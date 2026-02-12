/*
 * Copyright 2016-2022 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

#ifndef DEBUG_TOOLS_H
#define DEBUG_TOOLS_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "rsdk_status.h"




#ifdef __cplusplus
extern "C" {
#endif
/*==================================================================================================
*                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define REVERSE_WORD16(n) ((uint16_t)(((n & 0x00FF) << 8) | ((n & 0xFF00) >> 8)))

#define REVERSE_WORD32(n)                                                                      \
    ((uint32_t)(((n & 0x000000FF) << 24) | ((n & 0x0000FF00) << 8) | ((n & 0x00FF0000) >> 8) | \
                ((n & 0xFF000000) >> 24)))

#define REVERSE_WORD64(n)                                                                                              \
    ((uint64_t)(((n & 0x00000000000000FF) << 56) | ((n & 0x000000000000FF00) << 40) |                                  \
                ((n & 0x0000000000FF0000) << 24) | ((n & 0x00000000FF000000) << 8) | ((n & 0x000000FF00000000) >> 8) | \
                ((n & 0x0000FF0000000000) >> 24) | ((n & 0x00FF000000000000) >> 40) |                                  \
                ((n & 0xFF00000000000000) >> 56)))


#define INI_LINE_SIZE 512
#define MAX_PATH_LENGTH 96
#define MAX_NAME_LENGTH 48
#define MAX_FILE_NAME_LENGTH (MAX_PATH_LENGTH + MAX_NAME_LENGTH)
#define MAX_MSG_LENGTH 700
#define MAX_INI_FILE_SIZE 524288 // 512KiB
#if defined(UART_ENABLED) && defined(USING_PLATFORM_SDK)
#define UART_TIMEOUT 5000
#endif

#define DEBUG_ASSERT(ex) (void)((ex) || (DbgAssert(#ex, __FILE__, __LINE__), 0))

#define HALT_HERE while (1){}





/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/** @addtogroup debug_tools_api
* @{
*/

/**
* @brief        Encodes the debug point IDs used in the RSDK.
* @details  	Intended to be passed as arguments to DBG_POINT(), to integrate debugger support
*  				for file I/O and multicore debug control operations.
*/
typedef enum
{
    DBG_ID_FREAD = 0xA,  /**< signals to the debugger that a system file read is expected */
    DBG_ID_FWRITE = 0xB, /**< signals to the debugger that a system file write is expected */
    DBG_ID_FCOMP = 0xC,  /**< tells the debugger to compare content in platform memory with a file on the PC */
    DBG_ID_PRINT = 0xD,  /**< for printing a message on the debug console */
    DBG_ID_TESTCASE_END =
        0xE, /**< signals the end of a test case. Useful for test automation actions (e.g. saving console output) */
    DBG_ID_SESSION_END =
        0xF, /**< signals the end of a test session. Useful for test automation actions (e.g. saving console output) */
    DBG_ID_HALT_ERROR = 0x12, /**< signals an execution error condition */
    DBG_ID_SESSION_START =
        0x13, /**< signals the start of a test session. Useful for test automation actions (e.g. detecting if test has been launched
                                      successfully based on console output) */
    DBG_ID_LB_PROFILING_REINIT = 0x14, /**< signals Lauterbach trace reinitialization (flushes already collected data)*/
    DBG_ID_LB_PROFILING_RESUME = 0x15, /**< signals Lauterbach trace start*/
    DBG_ID_LB_PROFILING_PAUSE = 0x16,  /**< signals Lauterbach trace stop*/
    DBG_ID_LB_PROFILING_PRINT = 0x17,  /**< signals Lauterbach trace output to file*/
    DBG_ID_LB_BRKPT = 0x18,            /**< signals Lauterbach breakpoint*/
    DBG_ID_OTHER,
} dbgId_t;

/** @}*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/
extern char gDbgMsg[MAX_MSG_LENGTH];
extern char gDebugLogEn;

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
char *DbgGetIniline(char *mystr, char *newline);
int   DbgCompareWithFile(const char *fileName, const char *srcAddr, int numBytes);

/** @addtogroup debug_tools_api
* @{
*/

/**
* @brief    Allows interaction with Lauterbach debug scripts (.cmm) that are included in RSDK package.
* @details  This function simply defines an elf symbol onto which a breakpoint can be attached. It does
*           not do any processing.
*           Once the breakpoint is hit, the debugger can take different actions, based on the debug point ID.
*
* @param[in] ID - debug point ID chosen from dbgId_t enumeration
*/
dbgId_t DBG_POINT(dbgId_t);

/**
* @brief       Perform debug related initialization operations
* @details     Must be invoked on all cores where file I/O operations would be then performed.
*              The file I/O method is selected at compile time by a set of preprocessor macros. See \ref dt_ug_macros for details.

* @pre            In case TFTP support is needed on the Z7 core, then both the Z4 and Z7 ELFs must include proxy_intercom.c
* 				  source file from rsdk/Tools/Debug_tools and a rsdkProxy_t typed variable must be defined by the application
*                 in a memory area that is shared between the server and client sides of this proxy (eg .data_shared for Z4 and Z7 cores) <br>
*                 Accesses to this variable are guarded by PROXY_BUSY_SEMA, defined at compile time, in proxy_intercom.c
*                 See /Apps/1RF_4Antennas_demo and proxy_intercom.h for more details <br>
*
*
* @param[in] iniFile -  String pointing to TFTP configuration file. Can be left NULL if TFTP is not used and for PROXY_CLIENT_FILEIO mode.
*                       Configuration of TFTP client/server is done via this file, containing, eg:       <br>
*                            \# TFTP CLIENT MAC and IP (ie. this RRU board)                              <br>
*                            00:11:33:55:77:AA                                                           <br>
*                            192.168.1.112                                                               <br>
*                            \# alternatively, IP address can be written as 0xC0A80170                   <br>
*                                                                                                        <br>
*                            \# TFTP SERVER MAC and IP (could be any TFTP server, eg. OpenTFTPServer)    <br>
*                            00:50:56:AF:7E:D2 (set to FF:FF:FF:FF:FF:FF) to have ARP take care of this  <br>
*                            192.168.1.110                                                               <br>
*                            \# alternatively, IP address can be written as 0xC0A8016E                   <br>
*                                                                                                        <br>
*                            \# TFTP SERVER PORT                                                         <br>
*                            69                                                                          <br>
*                                                                                                        <br>
*                            \# (optional) PREPENDED PATH                                                <br>
*                            \# if present, this represents a file path that is prepended to all         <br>
*                            \# filename requested via TFTP services. It can be used to adapt the        <br>
*                            \# root folder of the TFTP server running on the host PC to the proper      <br>
*                            \# folder in the application being executed.                                <br>
*                            dir/subdir/                                                                 <br>
*
* @return      Operation result
*/
rsdkStatus_t DbgInit(const char *iniFile);

/**
* @brief       Perform file i/o read operation
* @pre         DbgInit() must be called before using this function. The code must be built with a valid combination of preprocessor macros (see DbgInit() description)
*
* @param[in] fileName -     String containing file to be read
* @param[in] offsetBytes -  Number of bytes to skip at the beginning of the file (to mimic fseek() in SEEK_SET mode). Can be 0 or a positive integer
* @param[in] destAddr -     Pointer to SRAM where read bytes are to be stored. Mind to have a server-client shared memory zone when using PROXY_CLIENT_FILEIO mode
* @param[in] maxBytes -     Max number of bytes to read
*
* @return      Number of bytes read (for TFTP modes) or 0 for Lauterbach mode
*/
int DbgReadFile(const char *fileName, int offsetBytes, char *destAddr, int maxBytes);

/**
* @brief       Performs DbgReadFile followed by DbgPerformMemTransformOper
* @pre         DbgInit() must be called before using this function. The code must be built with a valid combination of preprocessor macros (see DbgInit() description)
*
* @param[in] fileName -     String containing file to be read
* @param[in] offsetBytes -  Number of bytes to skip at the beginning of the file (to mimic fseek() in SEEK_SET mode). Can be 0 or a positive integer
* @param[in] destAddr -     Pointer to SRAM where read bytes are to be stored. Mind to have a server-client shared memory zone when using PROXY_CLIENT_FILEIO mode
* @param[in] maxBytes -     Max number of bytes to read
* @param[in] memTransformOper - Data format (can be "none", "word16", "word32", "word64")
* @param[in] isDestCacheable -  If the destination buffer is cacheable, then the function will ensure coherency
* 								in system memory by performing flush/invalidate operations.
*
*/
void DbgReadFileConvert(const char *fileName, int offsetBytes, char *destAddr, int maxBytes, const char *memTransformOper, bool isDestCacheable);

/**
* @brief       Perform file i/o write operation, overwriting existing file.
* @pre         DbgInit() must be called before using this function. The code must be built with a valid combination of preprocessor macros (see DbgInit() description)
*
* @param[in] fileName -  String containing file to be written
* @param[in] srcAddr -   Pointer to SRAM from where bytes are written to file. Mind to have a server-client shared memory zone when using PROXY_CLIENT_FILEIO mode
* @param[in] numBytes -  Number of bytes to write 
*
*/
void DbgWriteFile(const char *fileName, const char *srcAddr, int numBytes);

/**
* @brief       Performs DbgPerformMemTransformOper followed by DbgWriteFile followed by DbgPerformMemTransformOper
* @pre         DbgInit() must be called before using this function. The code must be built with a valid combination of preprocessor macros (see DbgInit() description)
*
* @param[in] fileName -  String containing file to be written
* @param[in] srcAddr -   Pointer to SRAM from where bytes are written to file. Mind to have a server-client shared memory zone when using PROXY_CLIENT_FILEIO mode
* @param[in] numBytes -  Number of bytes to write 
* @param[in] memTransformOper - Data format (can be "none", "word16", "word32", "word64")
* @param[in] isSrcCacheable -  If the source buffer is cacheable, then the function will ensure coherency
* 								in system memory by performing flush/invalidate operations.
*
*/
void DbgWriteFileConvert(const char *fileName, const char *srcAddr, int numBytes, const char *memTransformOper, bool isSrcCacheable);

/**
* @brief       Send a RTP/UDP stream using source port 7777 and destination 7778. Sequence number starts from 55193 and is automatically incremented with each sent packet.
* @pre         DbgInit() must be called before using this function with Ethernet properly configured.
*
* @param[in] srcAddr      -  Pointer to SRAM from where bytes are sent. Mind to have a server-client shared memory zone when using PROXY_CLIENT_FILEIO mode
* @param[in] numBytes     -  Number of bytes to send (0 is a valid value) 
* @param[in] timestamp    -  As defined by RTP protocol
* @param[in] payload_type -  As defined by RTP protocol
* @param[in] ssrc         -  As defined by RTP protocol
*
* @note This is a blocking operation, ie. control is returned only after whole stream is sent.
*
*/
void DbgSendRtp(const char *srcAddr, int numBytes, uint32_t timestamp, uint8_t payload_type, uint32_t ssrc);

/**
* @brief       Perform simple printf()-like functionality
* @details     If no define is enabled, then operations are done for a Lauterbach debug probe. Other supported debuggers are P&E and UART.
* @pre         DbgInit() must be called before using this function. The code must be built with a valid combination of preprocessor macros (see DbgInit() description)
*
* @param[in] fmt -  String to be output
*
*/
void DbgPrintMsg(const char *fmt, ...);












/**
* @brief       Perform cross-endian transformation on a buffer in memory
* @note        Halts execution is called with wrong input parameters
*
* @param[in] bufAddr -         Starting address of memory buffer
* @param[in] bufSize -         Size of memory buffer
* @param[in] memTransformOper - Operation to be performed on the memory buffer                       <BR>
*                                "none" for no transformation, i.e. byte-to-byte I/O                 <BR>
*                                "word16" for swapping bytes of int16, i.e. cross-endian on int16_t  <BR>
*                                         (byte0-byte1 -> byte1-byte0)                               <BR>
*                                "word32" for swapping bytes of int32, i.e. cross-endian on int32_t  <BR>
*                                         (byte0-byte1-byte2-byte3 -> byte3-byte2-byte1-byte0)       <BR>
*                                "word64" for swapping bytes of int64, i.e. cross-endian on int64_t  <BR>
*                                         (byte 0-1-2-3-4-5-6-7 -> byte 7-6-5-4-3-2-1-0)
* @param[in] isCacheable -  If the buffer is cacheable, then the function will ensure coherency
* 							in system memory by performing flush/invalidate operations.
*
* @return      status of performed operation
*/
rsdkStatus_t DbgPerformMemTransformOper(char *bufAddr, int32_t bufSize, const char *memTransformOper, bool isCacheable);

/** @}*/

/* Function used by the DEBUG_ASSERT macro to replicate assert like functionality with lauterbach */
void DbgAssert(char const *msg, char const *file, uint32_t line);

void DBG_WaitFocus(void);

#ifdef __cplusplus
}
#endif

#endif  /* DEBUG_TOOLS_H */
