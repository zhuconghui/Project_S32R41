/*
 * Copyright 2020-2022 NXP
 * NXP Confidential. This software is owned or controlled by NXP and may only
 * be used strictly in accordance with the applicable license terms. By
 * expressly accepting such terms or by downloading, installing, activating
 * and/or otherwise using the software, you are agreeing that you have read,
 * and that you agree to comply with and are bound by, such license terms. If
 * you do not agree to be bound by the applicable license terms, then you may
 * not retain, install, activate or otherwise use the software.
 */

/**
@file hal_es2_gbias.h

@version

@brief Barracuda API HAL(Hardware Abstraction Layer) header file

This is the header file for Barracuda APIs. All exported API can be found in
this file.

<TotalNumAPI>2
*/

#ifndef HAL_ES2_GBIAS_H
#define HAL_ES2_GBIAS_H


#include <stdint.h>

#include "bc_types.h"
#include "bc_err.h"

#if defined(__cplusplus)
extern "C"
{
#endif

/**
@brief This API configures global control bgr and ptat for RFBIST/SSBMOD bias current settings.
 
RSNum:0
 
# Description
 
This API configures global control bgr and ptat for RFBIST/SSBMOD bias current settings.
 
@param[in] 1/TRUE: set control bias current for ptat and bgr to trimmed value ; 0/FALSE set control bias current to 0 for ptat and bgr
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_GBIAS_EnableSSBBias(BOOL Enable);


/**
@brief This API configures global control for bg, bgr and ptat for all Ips.
 
RSNum:0
 
# Description
 
An API will configures global control for bg, bgr and ptat for all Ips.
 
@param[in] 1/TRUE: enable common for all ips e; 0/FALSE disable common for all ips
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_GBIAS_SelectCommonBias(BOOL Enable);



#if defined(__cplusplus)
}
#endif
#endif
