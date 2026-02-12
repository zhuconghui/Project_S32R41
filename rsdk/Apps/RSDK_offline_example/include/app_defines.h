/**************************************************************************************************
 * 
 * NXP Confidential Proprietary
 *
 * Copyright 2017-2021 NXP 
 * All Rights Reserved
 *
 *****************************************************************************
 *
 * NXP Confidential. This software is owned or controlled by NXP and may only be used strictly in accordance with the
 * applicable license terms.  By expressly accepting such terms or by downloading, installing, activating and/or otherwise
 * using the software, you are agreeing that you have read, and that you agree to comply with and are bound by, such
 * license terms.  If you do not agree to be bound by the applicable license terms, then you may not retain, install,
 * activate or otherwise use the software.
 *
 **************************************************************************************************/
#ifndef APPD_H
#define APPD_H

/**
* @file           app_defines.h
*/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "typedefs.h"
#include "app_mem_mgr.h"

#ifdef __cplusplus
extern "C" {
#endif

extern rsdkBufHandle_t gPeakAntennaDataBufH;
extern uint16_t gNrDetects;
/*==================================================================================================
*                                      MACROS
==================================================================================================*/
#define RSDK_MAX_PEAK_ANT_DATA_SIZE (2048) /* 32 peaks, 16 antennas, 4 bytes per sample*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif  //APPD_H
