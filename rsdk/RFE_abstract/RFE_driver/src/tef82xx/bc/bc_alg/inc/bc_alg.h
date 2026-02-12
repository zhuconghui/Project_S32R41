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
@file bc_alg.h

@version

@brief Barracuda API header file

This is the header file for Barracuda APIs. All exported API can be found in
this file.

<TotalNumAPI>1
*/

#ifndef BC_ALG_H
#define BC_ALG_H


#include <stdint.h>

#include "bc_types.h"
#include "bc_err.h"

#if defined(__cplusplus)
extern "C"
{
#endif

/**
@brief this API calculates the CRC


RSNum:1456417, 1447535

 
# Description

An API will compute the CRC32 for a given data block using the IEEE-802.3 CRC32 Ethernet Standard algorithm.

@param[in] pData Pointer to start address of data block to be calculated.
@param[in] Length Length of data block to be calculated in bytes.
@param[in] PreviousCRC Start value when the algorithm starts.
@param[out] pCRC calculated CRC

 
@return BC_ERRCODE
*/

BC_ERRCODE BC_ALG_CalculateCRC32(uint8_t *pData, uint32_t Length, uint32_t PreviousCRC, uint32_t *pCRC);



#if defined(__cplusplus)
}
#endif
#endif
