/**************************************************************************************************
* Copyright 2022 - 2023 NXP
**************************************************************************************************
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
**************************************************************************************************/

/******************************************************************************
 *   Project              : S32R41_RFE_FW
 *   Platform             : S32R41
 *****************************************************************************/

/*
 * main implementation: use this 'C' sample to create your own application
 *
 */


#include <stdio.h>
#if defined(STDIO)
#include <stdlib.h>
#endif
#include <string.h>

#include "rsdk_S32R41.h"

/* RSDK Platform setup */
#include "compiler_api.h"
#include "platform_setup_basic.h"
#include "rsdk_glue_timer_api.h"
#include "rsdk_glue_irq_register_api.h"

#include "Os.h"

/* Application headers*/
#include "app_mem_mgr.h"
#include "app_cond_flag.h"
#include "app_defines.h"
#include "debug_tools.h"
#include "radar_functions_core0.h"
#include "radar_functions_helpers.h"
#include "rfe_ipc_api_app.h"
#include "ipcf_ip_Cfg.h"

#if defined(STDIO)
extern void initialise_monitor_handles(void);
#endif

extern rsdkAppSettings_t gAppConfig;
extern uint8_t heapBuffer[];
extern uint8_t eof_session_cfg_file;
extern bool gRfeInitialized;

char cfgFileContent[20000];
Std_ReturnType gAppStatus = E_OK;

Std_ReturnType Det_ReportError(uint16 ModuleId,
        uint8 InstanceId,
        uint8 ApiId,
        uint8 ErrorId)
{
    sprintf(gDbgMsg, "Det_ReportError\n ModuleId: %d\n InstanceId: %d\n ApiId: %d\n ErrorId: %d\n", ModuleId, InstanceId, ApiId, ErrorId);
    DbgPrintMsg(gDbgMsg);
    return 0;
}

void    PostTaskHook( void )                     /* Routine to call after saving task context */
{

}

void    PreTaskHook( void )                     /* Routine to call before entering task context */
{

}

void StartupHook (void)
{

}

void    ErrorHook( StatusType Error )           /* Error handling routine */
{
    sprintf(gDbgMsg, "ErrorHook : %d\n", Error);
    DbgPrintMsg(gDbgMsg);
}

void ShutdownHook (StatusType error)
{
    sprintf(gDbgMsg, "ShutdownHook : %d\n", error);
    DbgPrintMsg(gDbgMsg);
}

/*--------------------------------------------------------------------------------*/
void __attribute__((optimize("O0"))) StartM7_1Debug(void)
{
	ASMNOP(dbg_point_label_platform_setup_done);
}
#ifdef IPCF_INITIALIZED
static void ipc_hardirq_dsp_instance(void)
{
    ipc_shm_hardirq_instance(IPCF_INSTANCE);
}
static void ipc_hardirq_rfe_fw_instance(void)
{
    ipc_shm_hardirq_instance(RFE_ABSTRACT_IPCF_INSTANCE);
}
#endif

int main(void)
{
	/* start the Operating System   */
	StartOS( OsAppMode_0 );

	return 0;
}

TASK(RsdkMain)
{
#if defined(STDIO)
	initialise_monitor_handles();
#endif

	//stand-alone, bare-metal application: basic platform setup
	// This will configure (at least) the PERHIPHERAL_PLL to 100Mhz, and select it for DSPI1 and 2.
	// As a result the DSPI Clock rate will boost by a factor 100/48, from 9.6MHz to 20MHz.
	// The DSPI clock of 20MHz has a 40% duty cycle, to address SPI MISO latencies on the SPF-48194 EVB
	if (RsdkPlatformSetup(PLAT_TYPE_S32R41_EVB) != 0)
	{
		HALT_HERE;  //if anything goes wrong, the execution will get stuck here
	}

	StartM7_1Debug();

	/* LTB semihosting starts here*/
	DBG_POINT(DBG_ID_SESSION_START);

	DbgPrintMsg("Platform setup done. M7_1 core started \n");

	AppMemInit(pHeapMem, heapBuffer, HEAP_BUFF_SIZE);

	// This should be outside the while loop TODO: check why
	if(rfeIpc_clientInit() != 0)
	{
		HALT_HERE;
	}

#ifdef APP_RUNTIME_CONFIG
	/* App configuration read at runtime from file
	  Main radar_functions loop (loop for all test cases in the ini file)
	 * eof_session_cfg_file is set to 1 in ReadAppSessionConfigFile(char *fileName, char* fileContent,
	 * size_t fileContentLen) when first '@' character is parsed in iniFileName
	 */
	while (1)
    {
    	sprintf(fileName, "%s%s", IN_PATH, "app_running_session_config.ini");
    	ReadAppSessionConfigFile(fileName, cfgFileContent, sizeof(cfgFileContent), &gAppConfig);
    	if(eof_session_cfg_file == 1)
    		break;
#endif  //APP_RUNTIME_CONFIG

#ifdef IPCF_INITIALIZED
        if((interrupts_cm7_install(MSCM_INT1_IRQn, 2, &ipc_hardirq_dsp_instance, 0) != RSDK_SUCCESS) ||
           (interrupts_cm7_install(MSCM_INT0_IRQn, 2, &ipc_hardirq_rfe_fw_instance, 0) != RSDK_SUCCESS))
        {
            while (1){};  //if anything goes wrong, the execution will get stuck here
        }
#endif

    	ExampleGetConfig();
    	ExampleAcqBuffInit();

    	/* For the scenario with multiple runs, the RFE needs to be initialized only once */
    	/* Limitation: switching b/w cascaded and standalone RFE modes is not supported with the current flow */
    	if (!gRfeInitialized)
    	{
    		ExampleRfeInit();
    	}

    	/* ExampleRfeConfigureWithBist configures the Radar Front-ends, CSI2 Receiver units and loads the
    	 * zero-hour BIST data (initial/reference measurement) for subsequent BIST tests*/
    	ExampleRfeConfigureWithBist();

    	if (gAppConfig.spSettings.enableRadarProcessing)
    	{
    		ExampleRsdkAcqAndProcessingFlow();
    	}
    	else
    	{
    		ExampleRsdkAcqOnlyFlow();
    	}

    	ExampleAcqBuffClear();

    	ExampleCsi2Teardown();

    	if (gAppStatus == E_OK)
    	{
    		DbgPrintMsg("Example finished successfully! \n");
    	}
    	else
    	{
    		DbgPrintMsg("Example failed! \n");
    	}
#ifdef APP_RUNTIME_CONFIG
    } /* end while(EOF_INI != 1) */
#endif
	DBG_POINT(DBG_ID_SESSION_END);

	HALT_HERE;
}
