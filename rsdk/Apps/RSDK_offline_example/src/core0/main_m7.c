/**************************************************************************************************
 * Copyright 2016-2024 NXP
 **************************************************************************************************
 * NXP Confidential. This software is owned or controlled by NXP and may only be used strictly in
 * accordance with the applicable license terms.  By expressly accepting such terms or by
 * downloading, installing, activating and/or otherwise using the software, you are agreeing that
 * you have read, and that you agree to comply with and are bound by, such license terms.
 * If you do not agree to be bound by the applicable license terms, then you may not retain,
 * install, activate or otherwise use the software.
 **************************************************************************************************/

/**
* @file           main.c
* Description:    SPT Example Application, integrating SPT Driver and Kernels
*/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include <stdio.h>
#if defined(STDIO)
#include <stdlib.h>
#endif
#include <string.h>
#include "compiler_api.h"




#include "radar_functions_helpers.h"
#include "radar_functions_core0.h"
#include "debug_tools.h"
#include "app_mem_mgr.h"

#include "platform_setup_basic.h"
#include "heap_size.h"


#include "Os.h"


#if defined(TRACE_ENABLE)
#include "trace.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                          TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       MACROS
==================================================================================================*/




/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
uint32_t errorCount;
rsdkBufHandle_t gPeakAntennaDataBufH;
uint16_t gNrDetects;

/*==================================================================================================
*                                   FUNCTION PROTOTYPES
==================================================================================================*/
int main(void);
#if defined(STDIO)
void initialise_monitor_handles(void);
#endif
/*==================================================================================================
*                                       FUNCTIONS
==================================================================================================*/

void    ErrorHook( StatusType Error )           /* Error handling routine */
{
    sprintf(gDbgMsg, "ErrorHook : %d", Error);
    DbgPrintMsg(gDbgMsg);
}

int main(void)
{
	/* start the Operating System   */
	StartOS( OsAppMode_0 );

	return 0;
}

TASK(RSDK_Main)



{
#if defined(TRACE_ENABLE)
    char traceFileNameHost[] = "RsdkTraceDump.hex";
    char traceBufferHost[TRACE_BUF_SIZE_HOST];
#endif
#if defined(STDIO)
    initialise_monitor_handles();
#else
	DBG_POINT(DBG_ID_SESSION_START);
#endif
	//stand-alone, bare-metal application: we do our own basic hw platform setup

	if (RsdkPlatformSetup(PLAT_TYPE_S32R41_EVB) != 0)
	{
		HALT_HERE;  //if anything goes wrong, the execution will get stuck here
	}






	DbgPrintMsg("Platform setup done \n");
	DbgPrintMsg("Starting SPT Example application \n");



    AppMemInit(pHeapMem, heapBuffer, HEAP_BUFF_SIZE);


#if defined(TRACE_ENABLE)
    RsdkTraceInit(traceBufferHost, TRACE_BUF_SIZE_HOST);
#endif

    ExampleInitSPTDriver();
    DbgPrintMsg("Initialized SPT driver\n");

    AppInitDsphd();
    DbgPrintMsg("Initialized DSP Host Driver\n");

    ExampleTestSPTMemErrInject();

    ExampleInitSPTKernels();
    DbgPrintMsg("Initialized SPT kernels\n");

    ExampleProcSPT();
    DbgPrintMsg("Finished SPT processing\n");







    DbgPrintMsg("Finished offline example\n");

#if defined(TRACE_ENABLE)
    RsdkTraceDump(traceFileNameHost, &DbgWriteFile);
#endif

    DBG_POINT(DBG_ID_SESSION_END);


    {
        HALT_HERE;
    }





}

#ifdef __cplusplus
}
#endif

/*******************************************************************************
 * EOF
 ******************************************************************************/

/** @} */
