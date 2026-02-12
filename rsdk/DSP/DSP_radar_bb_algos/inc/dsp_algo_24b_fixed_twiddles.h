/**************************************************************************************************
 * Copyright 2023-2024 NXP
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
#ifndef DSP_ALGOS_TWIDDLES_H
#define DSP_ALGOS_TWIDDLES_H

#ifdef __cplusplus
extern "C"{
#endif


#include <stdint.h>

#define DSP_ALGO_FFT128_TWIDDLES_LEN  352u
#define DSP_ALGO_FFT256_TWIDDLES_LEN  832u
#define DSP_ALGO_FFT512_TWIDDLES_LEN  1536u
#define DSP_ALGO_FFT1024_TWIDDLES_LEN 3584u
#define DSP_ALGO_FFT2048_TWIDDLES_LEN 6656u

extern const int16_t RsdkBbe32Twiddle128[DSP_ALGO_FFT128_TWIDDLES_LEN];
extern const int16_t RsdkBbe32Twiddle256[DSP_ALGO_FFT256_TWIDDLES_LEN];
extern const int16_t RsdkBbe32Twiddle512[DSP_ALGO_FFT512_TWIDDLES_LEN];
extern const int16_t RsdkBbe32Twiddle1024[DSP_ALGO_FFT1024_TWIDDLES_LEN];
extern const int16_t RsdkBbe32Twiddle2048[DSP_ALGO_FFT2048_TWIDDLES_LEN];


#ifdef __cplusplus
}
#endif

/*******************************************************************************
* EOF
******************************************************************************/


#endif // DSP_ALGOS_TWIDDLES_H_
