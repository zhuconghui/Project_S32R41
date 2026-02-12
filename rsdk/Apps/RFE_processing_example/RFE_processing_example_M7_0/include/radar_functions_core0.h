/**************************************************************************************************
 * Copyright 2017-2022 NXP
 **************************************************************************************************
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 **************************************************************************************************/
#ifndef RFC0_H
#define RFC0_H

/**
* @file           radar_functions_core0.h
*/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "typedefs.h"
#include "rfe_types.h"
#if defined(TRACE_ENABLE)
#include "trace.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

//extern rsdkAppMemMgr_t pHeapMem;

/*==================================================================================================
*                                      MACROS
==================================================================================================*/

#if defined(STDIO)
#define IN_PATH "./data/in/S32R41/"
#define AUX_IN_PATH "./data/in/S32R41/auxiliary/"
#define OUT_PATH "./data/out/S32R41/"
#else
#define IN_PATH "../data/in/S32R41/"
#define AUX_IN_PATH "../data/in/S32R41/auxiliary/"
#define OUT_PATH "../data/out/S32R41/"
#endif
#define SPT_OP_MODE SPT_OP_MODE_NONBLOCK /* TODO:defined in spt Tresos config file*/
//#define DSPHD_JOB_LIST_CRC_EN  0x1u
//#define DSPHD_JOB_LIST_CRC_DIS 0x0u

#define CHECK_KERNEL_WATERMARK 1U  /* TODO - should this be defined in SPT Tresos config*/
#define DATA_BUFF_IS_CACHED (true)













#define ENDIAN_CHANGE "word16"




#define MAX_SPT_MODULE_CODE_SIZE 4000

#if defined(TRACE_ENABLE)
#define TRACE_LOG_NR_ENTRIES_HOST 300 /* Maximum number of events that can be saved in the trace buffer for the host CPU */
#define TRACE_BUF_SIZE_HOST (TRACE_LOG_NR_ENTRIES_HOST * RSDK_TRACE_LOG_ENTRY_SIZE)

#if (defined(S32R41) && defined(DSP_ENABLE))
#define TRACE_LOG_NR_ENTRIES_DSP 200 /* Maximum number of events that can be saved in the trace buffer for the DSP */
#define TRACE_BUF_SIZE_DSP (TRACE_LOG_NR_ENTRIES_DSP * RSDK_TRACE_LOG_ENTRY_SIZE)
#endif

#endif

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
void ExampleRsdkAcqAndProcessingFlow(void);
void ExampleRsdkAcqOnlyFlow(void);
void ExampleGetConfig(void);
void ConfigSptKernelChain(void);
void RsdkSptBufferSizeCalc(void);
void ExampleAcqBuffInit(void);
void ExampleAcqBuffClear(void);
void ExampleInitSPTKernels(void);
void ExampleSptTearDown(void);
void ExampleCsi2Init(void);
void ExampleCsi2Teardown(void);
void ExampleRfeInit(void);
void ExampleRfeHwSwVersionCheck(void);
void ExampleRfeConfigure(void);
void ExampleRfeConfigureWithBist(void);
void ExampleRfeWaitForState(rfe_state_t rfeCondition);
void ExampleRfeCheckFusa(void);
void ExampleWaitForAcq(uint16_t frame);
void ExampleCsi2ErrorCheck(void);
void ExampleTriggerRangeProcessing(uint16_t frame);
void ExampleWaitRangeProcess(uint16_t frame);
void ExampleAcqPostProc(uint16_t frame);
void ReadAppSessionConfigFile(char *fileName, char *fileContent, size_t fileContentLen, rsdkAppSettings_t *appConfig);

#ifdef __cplusplus
}
#endif

#endif  //RFC0_H
