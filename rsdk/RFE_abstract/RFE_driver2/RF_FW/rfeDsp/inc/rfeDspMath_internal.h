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

/******************************************************************************
 *   Project              : RFE_SW
 *   Platform             : SAF85xx/SAF86xx/TEF83xx
 *****************************************************************************/

/*
 * rfeDspMath_internal.h
 *
 *  Created on: July 28, 2023
 *      Author: nlv13279   initial test
 *
 */

#ifndef RFE_DSP_MATH_INTERNAL_H
#define RFE_DSP_MATH_INTERNAL_H

/******************************************************************************
 *                              INCLUDES
 *****************************************************************************/

#include "rfe_types.h"
#include "rfe_error.h"

#include "rfeDspMath.h"

/******************************************************************************
 *                              TYPES
 *****************************************************************************/

/******************************************************************************
 *                              PRIVATE FUNCTIONS
 *****************************************************************************/

/*****************************************************************************************
 * FFT internal functions for test
 ******************************************************************************************/

/**
 * \brief   fft_bitreversal: Reshuffle input values for fast FFT Butter-fly process
 * \details In-place reshuffle input data according to the FFT size and output in the same input buffer
 * \attention       After the function call, the data in the input buffer is not in the sequence as original.
 * 
 * \pre     NIL 
 *
 * \param [in][out] pData  Pointer to the input data in int16x2 array.
 * \param [in]      bits   Element size in power of 2, i.e. number of int16x2_t elements is ( 1 << bits ).
 *
 * \return  NIL
 *
 * \post    NIL
 *
 * \ingroup NIL
 */
void fft_bitreversal(
    int16x2_t* pData,
    uint32_t bits
);

/**
 * \brief   rfeDspMath_loadSineFromIeee754Table returns float value of a Sine coefficient in the Sine table.
 * 
 * \pre     NIL 
 *
 * \param [in]   pSinQ1InIeee754Bits  Float Sine table of [0, pi/2] in IEEE754 bit format.
 * \param [in]   index                Position of the coefficient in the Sine table.
 *
 * \return       float value of the Sine coefficient 
 *
 * \post    NIL
 *
 * \ingroup NIL
 */
static inline float32_t rfeDspMath_loadSineFromIeee754Table (const uint32_t* pSinQ1InIeee754Bits, uint32_t index)
{
    rfeDsp_floatIeeeU32BitsUnion_t unionU32ToF;
    unionU32ToF.val_u32 = pSinQ1InIeee754Bits[index];
    return (float32_t)unionU32ToF.val_float;
}

/**
 * \brief   fft_forwardF32: Do FFT Butter-fly process on int16x2_t data using single-precision floating-point FPU
 * \details First do Butter-fly for all FFT4, than do butter-fly loops of the following strides before the last stage
 * \attention       This function is in-place process, i.e. output in the input buffer.
 * 
 * \pre     NIL 
 *
 * \param [in]   pData                Pointer to the input data in int16x2_t array, with (1<<fftbits) int16x2_t elements.
 * \param [in]   fftbits              log2(number of int16x2_t elements). Note: for real input fftI16, fftSize
 *                                    is 1 << (fftbits + 1); while for complex cfftI16, fftSize is 1<<fftbits.
 * \param [in]   pSinQ1InIeee754Bits  Float Sine table of [0, pi/2] in IEEE754 bit format.
 * \param [in]   sinQ1MaxIdx          Sine table size - 1.
 * \param [out]  pOutCF               Pointer to cfloat32_t array to output full cFFT spectrum or half rFFT spectrum.
 *
 * \return  NIL
 *
 * \post    NIL
 *
 * \ingroup NIL
 */
void fft_forwardF32 (
    const int16x2_t* pData,
    uint32_t         fftBits,
    const uint32_t*  pSinQ1InIeee754Bits,
    uint32_t         sinQ1MaxIdx,
    cfloat32_t*      pOutCF
);

/**
 * \brief   fft_rfftfinalstageF32: Final stage of real input rFFT to reconstruct rFFT results on FPU
 * \details Generate FFT results by final radix-2 butter-fly and scale down results by fftSize
 * \attention       This function supports in-place process.
 * 
 * \pre     NIL 
 *
 * \param [in][out] pInOut                Pointer to the input and output float array.
 * \param [in]      rfftbitsDiv2          Half of rFFT size in power of 2, i.e. rFFT size is 1 << ( rfftbitsDiv2 + 1 ).
 * \param [in]      pSinQ1InIeee754Bits   float Sine table of [0, pi/2] in IEEE754 bit format.
 * \param [in]      sinQ1MaxIdx           Sine table size - 1.
 *
 * \return  NIL
 *
 * \post    NIL
 *
 * \ingroup NIL
 */
void fft_rfftfinalstageF32(
    cfloat32_t*     pInOut,
    uint32_t        rfftbitsDiv2,
    const uint32_t* pSinQ1InIeee754Bits,
    uint32_t        sinQ1MaxIdx
);

#endif  // !RFE_DSP_MATH_INTERNAL_H
