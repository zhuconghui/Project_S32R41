/**************************************************************************************************
 * Copyright 2017-2022 NXP
 **************************************************************************************************
 * NXP Confidential. This software is owned or controlled by NXP and may only be used strictly in
 * accordance with the applicable license terms.  By expressly accepting such terms or by
 * downloading, installing, activating and/or otherwise using the software, you are agreeing that
 * you have read, and that you agree to comply with and are bound by, such license terms.
 * If you do not agree to be bound by the applicable license terms, then you may not retain,
 * install, activate or otherwise use the software.
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

#include "cache.h"
#include "app_mem_mgr.h"

#if defined(TRACE_ENABLE)
#include "trace.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern rsdkAppMemMgr_t pHeapMem;

/*==================================================================================================
*                                      MACROS
==================================================================================================*/
#define SAMPLES_PER_CHIRP 512    // number of samples per chirp -> has to be integer dividable by CHIRPS_PER_CTE_TT
#define CHIRPS_PER_FRAME 128     // number of chirps per frame
#define SDADC_ACTIVE_CHANNELS 4  // number of active SDADC channels

#define MAX_SPT_MODULE_CODE_SIZE 4000

#if defined(TRACE_ENABLE)
#define TRACE_LOG_NR_ENTRIES_HOST 300 /* Maximum number of events that can be saved in the trace buffer for the host CPU */
#define TRACE_BUF_SIZE_HOST (TRACE_LOG_NR_ENTRIES_HOST * RSDK_TRACE_LOG_ENTRY_SIZE)

#endif
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/



void ExampleInitSPTKernels(void);
void ExampleTestSPTMemErrInject(void);
void ExampleProcSPT(void);
rsdkStatus_t TransposeTagBmp(uint32_t *inBuff, uint32_t *outBuff, uint16_t nrRowsIn, uint16_t nrColsIn);

#ifdef __cplusplus
}
#endif

#endif  //RFC0_H
