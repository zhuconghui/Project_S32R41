/**************************************************************************************************
* Copyright 2021-2023 NXP
**************************************************************************************************
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
**************************************************************************************************/
/*
 * rfeDspMath_fft.h
 *
 *  Created on: Apr 15, 2021
 *      Author: nlv13279   initial test
 *
 */

#ifndef RFE_DSP_MATH_FFT_H_
#define RFE_DSP_MATH_FFT_H_

#include "rfeDspMath.h"
#include "rfe_error.h"

/**
  \brief     rfeDspMath_fft.h: Header of using FFT and DFT functions in the rfeDsp unit. 
  \details   Including all FFT and DFT related definitions, constant and function prototype.
  \author  nlv13279
*/
#define RFE_DSP_SINE_MAXSTEPS_POWERBIT_COUNT     10U   // for max FFT size = 2^10 = 1024

/**
 * Sine tables for FFT
 */
extern const uint32_t rfeDspMat_sine1024Q1_f32[ 1024 / 4 + 1 ];

// Max index of the sine table 
#define RFE_DSP_SINE1Q_MAXIDX     ( ( ( uint16_t )1U ) << ( RFE_DSP_SINE_MAXSTEPS_POWERBIT_COUNT - 2U ) )  // Max sine table index


/*****************************************************************************************
 * Real input FFT functions using DSP & FPU
 * *****************************************************************************************/
/**
  \brief   rfeDspMath_fftI16F: General real input FFT of size ( 1<< nPower2 ) elements by floating-point calculation,
           output down-scaled FFT/fftSize.
  \details Do FFT and output a half of spectrum, as it is conjugate symmetric on frequency bin fftSize/2.
  \attention 1. The data in the input pIn buffer is reshuffled to improve butterfly speed. Please keep a copy of the 
             input before calling this function, if the input is needed later. 
             2. To save memory, result bin fftSize/2 is stored in the imaginary of bin 0 in pHalf. 
             Full FFT spectrum pFreq can be reconstructed by the following:
             pFreq[0].re           = pHalf[0].re;              pFreq[0].im           = 0;
             pFreq[1].re           = pHalf[1].re;              pFreq[1].im           = pHalf[1].im;
...
             pFreq[fftSize/2-1].re = pHalf[fftSize/2-1].re;    pFreq[fftSize/2-1].im = pHalf[fftSize/2-1].im;
             pFreq[fftSize/2].re   = pHalf[0].im;              pFreq[fftSize/2].im   = 0;
             pFreq[fftSize/2+1].re = pHalf[fftSize/2-1].re;    pFreq[fftSize/2+1].im = -pHalf[fftSize/2-1].im;
             pFreq[fftSize/2+2].re = pHalf[fftSize/2-2].re;    pFreq[fftSize/2+2].im = -pHalf[fftSize/2-2].im;

             pFreq[fftSize-1].re   = pHalf[1].re;              pFreq[fftSize-1].im   = -pHalf[1].im;

  \param [in]      pIn     Pointer to the input data in int16x2 array.
  \param [in]      nPower2 log2( FFT size ).
  \param [out]     pHalf   Pointer to the output cfloat32_t (complex single-precision floating point data type) array. 
  \result  1. Measured maximum real and imaginary relative error is < 5e-6
           2. FFT on shared memory is 2x slower than on M7 memory.
      arm-gcc cycles: 292/573/1155/2383/5084/11009/23889/51880    for FFT size 8/16/32/64/128/256/512/1024  
                      100098/219256/475161/1026220/2200186  for Shared Memory FFT size 1024/2048/4096/8192/16384 
    arm_clang cycles: 386/713/1293/2557/5359/11473/24377/55226    for FFT size 8/16/32/64/128/256/512/1024  
                      96797/212755/462717/998549/2139391  for Shared Memory FFT size 1024/2048/4096/8192/16384
  \author  nlv13279
 */
void rfeDspMath_fftI16F(
 int16x2_t* const   pIn, 
 const uint32_t     nPower2, 
 cfloat32_t* const  pHalf,
 rfe_error_t* rfe___error___pointer
);

#endif /*RFE_DSP_MATH_FFT_H_*/

