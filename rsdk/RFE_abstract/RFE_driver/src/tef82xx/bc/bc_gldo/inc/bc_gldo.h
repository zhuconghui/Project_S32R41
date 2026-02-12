/*
 * Copyright 2016,2019-2022 NXP
 * NXP Confidential. This software is owned or controlled by NXP and may only
 * be used strictly in accordance with the applicable license terms. By
 * expressly accepting such terms or by downloading, installing, activating
 * and/or otherwise using the software, you are agreeing that you have read,
 * and that you agree to comply with and are bound by, such license terms. If
 * you do not agree to be bound by the applicable license terms, then you may
 * not retain, install, activate or otherwise use the software.
 */

/**
@file bc_gldo.h

@version

@brief Barracuda API header file

This is the header file for Barracuda APIs. All exported API can be found in
this file.

<TotalNumAPI>2
*/

#ifndef BC_GLDO_H
#define BC_GLDO_H


#include <stdint.h>

#include "bc_types.h"
#include "bc_err.h"

#if defined(__cplusplus)
extern "C"
{
#endif

/**
@brief This API selects the global LDO reference voltage.
 
RSNum:1456422
 
# Description
 
An API will set the analog switch to low noise reference or default 900mV reference voltage. 
 
@param[in] EnLowNoise 0/FALSE: use default 900mv ref voltage; 1/TRUE: use low noise ref voltage
 
@return BC_ERRCODE
*/
 
BC_ERRCODE BC_GLDO_SelectGLDOVRef(BOOL EnLowNoise);


/**
@brief This API set the 4 SNS monitor thresholds.
 
RSNum:1447610, 1616530, 1616526
 
# Description
 
An API will set the SNS high/low threshold with a coarse adjustment of 5% and a fine adjustment of 0.2% of Vnom. There are 4 SNS monitor thresholds in the GLDO : 1v1 low, 1v1 high. 1v8 low and 1v8 high.
 
## Note
1. CoarseAjustment refers to registers GLDO1V1_SNS_LOW_CONFIG, GLDO1V1_SNS_HIGH_CONFIG, GLDO1V8_SNS_LOW_CONFIG, GLDO1V8_SNS_HIGH_CONFIG.
2. FineAjustment refers to registers GLDO1V1_SNS_LOW_CAL_REG, GLDO1V1_SNS_HIGH_CAL_REG, GLDO1V8_SNS_LOW_CAL_REG, GLDO1V8_SNS_HIGH_CAL_REG
 
@param[in] SelectSNSThreshold  List of 4 SNS monitor thresholds 
@param[in] CoarseAdjustment  Coarse adjustment of the selected SNS threshold
@param[in] FineAdjustment Fine adjustment of the selected SNS threshold
 
@return BC_ERRCODE
*/
 
BC_ERRCODE BC_GLDO_SetSNSThreshold(GLDO_SNSThreshold_e SelectSNSThreshold, GLDO_SNS_CoarseAdjustment_e CoarseAdjustment, uint8_t FineAdjustment);



#if defined(__cplusplus)
}
#endif
#endif
