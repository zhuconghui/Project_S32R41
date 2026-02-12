/**************************************************************************************************
 * 
 * NXP Confidential Proprietary
 *
 * Copyright 2021 NXP 
 * All Rights Reserved
 *
 ******************************************************************************
 *
 * NXP Confidential. This software is owned or controlled by NXP and may only be used strictly in accordance with the
 * applicable license terms.  By expressly accepting such terms or by downloading, installing, activating and/or otherwise
 * using the software, you are agreeing that you have read, and that you agree to comply with and are bound by, such
 * license terms.  If you do not agree to be bound by the applicable license terms, then you may not retain, install,
 * activate or otherwise use the software.
 *
 *************************************************************************************************/

#ifndef RSDK_APPRFE_H
#define RSDK_APPRFE_H

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/
#include "rsdk_rfe_api.h"
#include "rsdk_rfe_tef82xx_api.h"
#include "app_mem_mgr.h"

#ifdef __cplusplus
/*do this after the #includes*/
extern "C" {
#endif

/*=================================================================================================
*                                      DEFINES AND MACROS
=================================================================================================*/
#define TESTER_CSI2_UNIT_TO_USE RSDK_CSI2_UNIT_0
#define N_CHIRP_SHAPES 1u
/*=================================================================================================
*                                          CONSTANTS
=================================================================================================*/

/*=================================================================================================
*                                             ENUMS
=================================================================================================*/

/*=================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
=================================================================================================*/

/*=================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
=================================================================================================*/
extern rsdkBufHandle_t gSdadcSampleBufferBufH[];

/*=================================================================================================
*                                    FUNCTION PROTOTYPES
=================================================================================================*/

void AppRfeInit(uint32_t rfeId, rsdkRfeFrontendMode_t rfeMode);
void AppRfeFrameConfig(uint32_t rfeId);
void AppRfeCheckRfeStatus(void);
void ExampleInitRfe(void);
void AppRfeCalibAndRun(void);

#ifdef __cplusplus
}
#endif

#endif /*RSDK_APPRFE_H*/
