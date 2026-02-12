/**************************************************************************************************
 * Copyright 2021 - 2024 NXP
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

#ifndef RFE_CONFIG_H
#define RFE_CONFIG_H


/******************************************************************************
 *                              INCLUDES
 *****************************************************************************/

#include "rfe_cfg_blob.h"

#include <stdint.h>


/******************************************************************************
 *                              TYPES
 *****************************************************************************/

 /**
 * The RFE configuration blob
 */
extern uint8_t rfeConfig0[RFE_CFG_SIZE_TOTAL];
extern uint8_t rfeConfig1[RFE_CFG_SIZE_TOTAL];

#endif /* RFE_CONFIG_H */
