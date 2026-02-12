/*
 * Copyright 2016-2023 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include <stdio.h> 
#include <string.h>
#include <stdarg.h>

#include "compiler_api.h"



#include "debug_tools.h"
#include "cache.h"
#include "rsdk_toolchain_helper.h"


#if !defined(USING_PLATFORM_SDK)
#include "platform_setup_basic.h"
#if defined(ARMCA53)
#include "interrupts.h"
#endif
#else
#ifndef PROXY_CLIENT_FILEIO
#include "rsdk_rtp.h"
#endif
#endif


#ifdef R41_UART_CONSOLE
#include "lin.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif
/*==================================================================================================
*                                       LOCAL DEFINES
==================================================================================================*/




typedef enum
{
    dbg_InFocus_uninit = 0,
    dbg_InFocus_init = 1,
    dbg_InFocus_monitored = 2,
    dbg_InFocus_dont_care = 3
} dbg_InFocus_t;

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/
char gDbgMsg[MAX_MSG_LENGTH];
char gDebugLogEn = 0;

/* variables for Lauterbach */
volatile dbgId_t     DBG_ID;
volatile char        DBG_FileName[MAX_FILE_NAME_LENGTH];
volatile char *      DBG_DestAddr;
volatile int         DBG_MaxBytes;
volatile int         DBG_OffsetBytes;
volatile const char *DBG_SrcAddr;
volatile int         DBG_NumBytes;
volatile int         DBG_CompareOffset;

/* set to value 1 by DbgInit and by Lauterbach script when when no longer listening to this core
 * set to value 2 by Lauterbach script when listening to this core (bp set to DBG_POINT on this core)
 * set by default to value 3 (ie. don't care) and then set to 1 by semihosting.cmm Lauterbach script
 * see also DBG_WaitFocus() */
#ifdef USING_LAUTERBACH
volatile dbg_InFocus_t DBG_InFocus = dbg_InFocus_uninit;
#else
volatile dbg_InFocus_t DBG_InFocus = dbg_InFocus_dont_care;
#endif

#if defined(__GNUC__) && !defined(__DCC__)
#define ATTR_OPT_DISABLE __attribute__((optimize("O0"))) 
#else
/*attribute is not supported, if defined(__ghs__) || defined(__DCC__)*/
#define ATTR_OPT_DISABLE 
#endif

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
char *get_newline(char *mystr, char *newline);

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/* Debug label to be used by the debug script running on host
   to interact with the application on the board */
void DBG_WaitFocus(void)
{
    /* in a stand-alone, bare-metal application, we wait for the DBG_InFocus flag to be set by the debugger
       otherwise, when running under OS control, DBG_POINT() must not have any effect */
    while (DBG_InFocus < dbg_InFocus_monitored)  /* Lauterbach script listens to this core */
        ;
}

dbgId_t ATTR_OPT_DISABLE DBG_POINT(dbgId_t ID)
{
    DBG_WaitFocus();  /* wait for Lauterbach to have its focus switched to this core */

    DBG_ID = ID;

    if ((ID >= DBG_ID_LB_PROFILING_REINIT) && (ID <= DBG_ID_LB_PROFILING_PRINT))
    {
        ASMNOP(dbg_point_label_class_profiling);
    }
    else
    {
        ASMNOP(dbg_point_label_class_regular);
    }

    return DBG_ID;
}

#if (!defined(STDIO))
/* functions that are using directly the DBG_POINT 'syscall'
   pass args to global variables to make them visible to debugger script: */
static int ATTR_OPT_DISABLE LauterbachReadFile(const char *fileName, int offsetBytes, char *destAddr, int maxBytes)
{
    /* pass params to global variables to have them visible to Lauterbach script */
    sscanf(fileName, "%s", DBG_FileName);
    DBG_DestAddr = destAddr;
    DBG_MaxBytes = maxBytes;
    DBG_OffsetBytes = offsetBytes;

    /* dbg point for file read.. now LB script reads the file and copies the content at destAddr as-is.*/
    DBG_POINT( DBG_ID_FREAD);

    /* Invalidate cache after receiving data.
       This is needed to make sure that data is read from SRAM. */
    CacheInvalidate(destAddr, maxBytes);

    /*LB does not implement this feature - data.load.binary does NOT return a result*/
    return maxBytes;
}

static void ATTR_OPT_DISABLE LauterbachWriteFile(const char *fileName, const char *srcAddr, int numBytes)
{
    /* pass args to global variables to make them visible to debugger script: */
    sscanf(fileName, "%s", DBG_FileName);
    DBG_SrcAddr = srcAddr;
    DBG_NumBytes = numBytes;

    DBG_POINT(DBG_ID_FWRITE);
}

#else

static int StdioReadFile(const char *fileName, int offsetBytes, char *destAddr, int maxBytes)
{
    FILE *   pFile;
    uint32_t numBytesRead = 0;

    pFile = fopen(fileName, "rb");
    if (pFile != NULL)
    {
        fseek(pFile, offsetBytes, SEEK_SET);
        numBytesRead = fread(destAddr, 1, maxBytes, pFile);
        fclose(pFile);
    }
    else
    {
        printf("Error: Could not open file for reading %s \n", fileName);
        HALT_HERE;
    }

    return numBytesRead;
}

static void StdioWriteFile(const char *fileName, const char *srcAddr, int numBytes)
{
    FILE *   pFile;

    pFile = fopen(fileName, "wb");
    if (pFile != NULL)
    {
        (void)fwrite(srcAddr, 1, numBytes, pFile);
        fclose(pFile);
    }
    else
    {
        printf("Error: Could not open file for writing %s \n", fileName);
        HALT_HERE;
    }
}
#endif  /* !STDIO */

#ifndef PROXY_CLIENT_FILEIO
static int DbgReadFileBackend(const char *fileName, int offsetBytes, char *destAddr, int maxBytes)
{
    int readBytes = 0;

#if defined(STDIO)
    readBytes = StdioReadFile(fileName, offsetBytes, destAddr, maxBytes);
#else
    readBytes = LauterbachReadFile(fileName, offsetBytes, destAddr, maxBytes);
#endif
    return readBytes;
}
#endif

#ifndef PROXY_CLIENT_FILEIO
static void DbgWriteFileBackend(const char *fileName, const char *srcAddr, int numBytes)
{
    /* Flush cache before transferring data.
       This is needed to make sure that cached data is ok in SRAM and not only in local cache. */
    CacheFlush(srcAddr, numBytes);
#if defined(STDIO)
    StdioWriteFile(fileName, srcAddr, numBytes);
#else
    LauterbachWriteFile(fileName, srcAddr, numBytes);
#endif
}
#endif

#ifndef PROXY_CLIENT_FILEIO
static void DbgRtpSendBackend(const char *srcAddr, int numBytes, uint32_t timestamp, uint8_t payload_type,
                              uint32_t ssrc)
{
#if (defined(USING_PLATFORM_SDK) && defined(USING_OS_FREERTOS))
    SendRtpData(srcAddr, numBytes, timestamp, payload_type, ssrc);
#endif
}
#endif


/* basic print, strings only... */
static void ATTR_OPT_DISABLE dbg_print_t32(const char *msg)
{
    DBG_ID = DBG_POINT(DBG_ID_PRINT);
}


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/* function to initialize file i/o and print communication */
rsdkStatus_t DbgInit(const char *iniFile)
{
    if (DBG_InFocus == dbg_InFocus_uninit)
        DBG_InFocus = dbg_InFocus_init;  /* mark (to Lauterbach script) that DbgInit has been executed */
    return RSDK_SUCCESS;
}

rsdkStatus_t DbgPerformMemTransformOper(char *bufAddr, int32_t bufSize, const char *memTransformOper, bool isCacheable)
{
    int32_t i;

    if (strcmp(memTransformOper, "none") == 0)
    {
    }
    else
    {
    	if(isCacheable == true)
    	{
			 CacheInvalidate(bufAddr, bufSize);
    	}

    	if (strcmp(memTransformOper, "word16") == 0)
		{
			uint16_t *tmp;

			if ((bufSize < 0) || ((bufSize % 2) != 0))
				return RSDK_ERROR;
			for (i = 0; i < bufSize; i += 2)
			{
				tmp = (uint16_t *)&bufAddr[i];
				*tmp = REVERSE_WORD16(*tmp);
			}
		}
		else if (strcmp(memTransformOper, "word32") == 0)
		{
			uint32_t *tmp;

			if ((bufSize < 0) || ((bufSize % 4) != 0))
				return RSDK_ERROR;
			for (i = 0; i < bufSize; i += 4)
			{
				tmp = (uint32_t *)&bufAddr[i];
				*tmp = REVERSE_WORD32(*tmp);
			}
		}
		else if (strcmp(memTransformOper, "word64") == 0)
		{
			uint64_t *tmp;

			if ((bufSize < 0) || ((bufSize % 8) != 0))
				return RSDK_ERROR;
			for (i = 0; i < bufSize; i += 8)
			{
				tmp = (uint64_t *)&bufAddr[i];
				*tmp = REVERSE_WORD64(*tmp);
			}
		}
		else
		{
			return RSDK_ERROR;
		}

    	if(isCacheable == true)
    	{
    		CacheFlush(bufAddr, bufSize);
    	}
    }

    return RSDK_SUCCESS;
}

int DbgReadFile(const char *fileName, int offsetBytes, char *destAddr, int maxBytes)
{
    return DbgReadFileBackend(fileName, offsetBytes, destAddr, maxBytes);
}

void DbgReadFileConvert(const char *fileName, int offsetBytes, char *destAddr, int maxBytes,
                        const char *memTransformOper, bool isDestCacheable)
{
    DbgReadFile(fileName, offsetBytes, destAddr, maxBytes);
    DbgPerformMemTransformOper(destAddr, maxBytes, memTransformOper, isDestCacheable);
}

void DbgWriteFile(const char *fileName, const char *srcAddr, int numBytes)
{
    DbgWriteFileBackend(fileName, srcAddr, numBytes);
}

void DbgWriteFileConvert(const char *fileName, const char *srcAddr, int numBytes, const char *memTransformOper, bool isSrcCacheable)
{
    DbgPerformMemTransformOper((char *)srcAddr, numBytes, memTransformOper, isSrcCacheable);
    DbgWriteFile(fileName, srcAddr, numBytes);
    DbgPerformMemTransformOper((char *)srcAddr, numBytes, memTransformOper, isSrcCacheable);
}

void DbgSendRtp(const char *srcAddr, int numBytes, uint32_t timestamp, uint8_t payload_type, uint32_t ssrc)
{
    DbgRtpSendBackend(srcAddr, numBytes, timestamp, payload_type, ssrc);
}

void DbgPrintMsg(const char *fmt, ...)
{
#if !defined(DBG_PRINT_DISABLED)
	va_list args;
    va_start(args, fmt);
#if defined(linux) || defined(STDIO)
    vprintf(fmt, args);
    fflush(stdout);
#elif defined(R41_UART_CONSOLE)
    vsprintf(gDbgMsg, fmt, args);
    uart_printf(gDbgMsg);
#else
    /* fallback to Lauterbach T32 */
    vsprintf(gDbgMsg, fmt, args);
    dbg_print_t32(gDbgMsg);
#endif
    va_end(args);
#endif
}













/*--------------------------------------------------------------------------------*/
/*functions involved in setup and execution of the test session:*/
int DbgCompareWithFile(const char *fileName, const char *srcAddr, int numBytes)
{
    /*pass args to global variables to make them visible to debugger script:*/
    sscanf(fileName, "%s", DBG_FileName);
    DBG_SrcAddr = srcAddr;
    DBG_NumBytes = numBytes;
    DBG_CompareOffset = numBytes + 1;

    DBG_POINT(DBG_ID_FCOMP);

    return DBG_CompareOffset;
}

char *get_newline(char *mystr, char *newline)
{
    char *       nextline;
    unsigned int len = 0;

    newline[0] = '\0';

    if (mystr == NULL)
        return NULL;

    nextline = strchr(mystr, '\n') + 1;

    if (nextline != NULL)
    {
        if (nextline == (void *)1)
        {
            DbgPrintMsg("End of file reached (no more end of lines)");
            return NULL;
        }

        len = (nextline - mystr);
        if (len >= INI_LINE_SIZE)
        {
            DbgPrintMsg("Line too long");
            HALT_HERE;
        }
        else
        {
            strncpy(newline, mystr, len);
            memset(&newline[len], 0, 1);  /* add 'NULL' character at the end.*/

            return nextline;
        }
    }
    else
    {
        strcpy(newline, mystr);
        return NULL;
    }
}

char *DbgGetIniline(char *mystr, char *newline)
{
    char  line_start[2];
    char *nextline;

    do
    {
        nextline = get_newline(mystr, newline);  /* get a new line as a NULL-terminated string */
        mystr = nextline;

        /* read first non-whitespace character in line (if any) */
        memset(line_start, 0, sizeof(line_start));
        sscanf(newline, "%1s", line_start);
    } while ((*line_start == '#' || *line_start == 0) && nextline != NULL);  /* ignore comments and empty lines */

    return mystr;
}

/* TODO this could be a macro to make use of __LINE__ and __FILE__ */
void DbgAssert(char const *msg, char const *file, uint32_t line)
{
    sprintf(gDbgMsg, "Assertion failed: %s at %s, line  %d\n", msg, file, (int)line);
    DbgPrintMsg(gDbgMsg);
}

#ifdef __cplusplus
}
#endif

/*******************************************************************************
 * EOF
 ******************************************************************************/
