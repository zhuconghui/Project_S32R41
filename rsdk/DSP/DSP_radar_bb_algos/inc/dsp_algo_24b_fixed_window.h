/**************************************************************************************************
 * Copyright 2024 NXP
 **************************************************************************************************
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
 * accordance with the applicable license terms.  By expressly accepting such terms or by
 * downloading, installing, activating and/or otherwise using the software, you are agreeing that
 * you have read, and that you agree to comply with and are bound by, such license terms.
 * If you do not agree to be bound by the applicable license terms, then you may not retain,
 * install, activate or otherwise use the software.
 **************************************************************************************************/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#ifndef DSP_ALGOS_WINDOW_H
#define DSP_ALGOS_WINDOW_H

#ifdef __cplusplus
extern "C"{
#endif

#include <stdint.h>



extern const int16_t RsdkBbe32FftWindow128[64];
extern const int16_t RsdkBbe32FftWindow256[128];
extern const int16_t RsdkBbe32FftWindow512[256];
extern const int16_t RsdkBbe32FftWindow1024[512];
extern const int16_t RsdkBbe32FftWindow2048[1024];


#ifdef __cplusplus
}
#endif

/*******************************************************************************
* EOF
******************************************************************************/


#endif // DSP_ALGOS_WINDOW_H_
