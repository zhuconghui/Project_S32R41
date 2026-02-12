/**************************************************************************************************
 * Copyright 2024 - 2025 NXP
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
 *   Project              : S32R41_RFE20_FW
 *   Platform             : S32R41
 *****************************************************************************/


#ifndef RFE_MIN_MAX_BLOB_H
#define RFE_MIN_MAX_BLOB_H


/******************************************************************************
 *                              INCLUDES
 *****************************************************************************/

#include "rfe_cfg_blob.h"

#include <stdint.h>


/******************************************************************************
 *                              TYPES
 *****************************************************************************/

 /**
 * The arrays containing the RFE configuration blob MIN and MAX values
 */
extern uint8_t rfeConfigBlobMinValues[RFE_CFG_SIZE_TOTAL];
extern uint8_t rfeConfigBlobMaxValues[RFE_CFG_SIZE_TOTAL];

#endif /* RFE_MIN_MAX_BLOB_H */
