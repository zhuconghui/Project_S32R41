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

/********************************************************************************************
 * rfeDspMath.c
 *  Math functions for ARM M7 DSP
 *
 *  Created on: March 15, 2021
 *      Author: nlv13279   initial test
 *
 */

#include "rfeDspMath.h"

const float32_t rfeDspMath_matan2SIN[10] = {
 1.0000000000F, 0.7071067812F, 0.3826834324F, 0.1950903220F, 0.0980171403F,
 0.0490676743F, 0.0245412285F, 0.0122715383F, 0.0061358846F, 0.0030679568F
};

const float32_t rfeDspMath_matan2COS[10] = {
 0.0000000000f, 0.7071067812f, 0.9238795325f, 0.9807852804f, 0.9951847267f,
 0.9987954562f, 0.9996988187f, 0.9999247018f, 0.9999811753f, 0.9999952938f
};

/**************************************************************************************************
 * DSP & FPU functions: log2, log10 and complex absolute decibel functions.  
 *                Note: integration test of fixed-point log2 and log10 functions are not done yet.
 **************************************************************************************************/
void rfeDspMath_absCF32dB(
 const cfloat32_t* pCF32,
 uint32_t nElements,
 float32_t* pAbsF32dB,
 rfe_error_t* rfe___error___pointer
)
{
    if ( ( NULL == pCF32 ) || ( NULL == pAbsF32dB ) )
    {
        if ( ( rfe_error_t )rfe_error_none_e == *rfe___error___pointer )
        {
            *rfe___error___pointer = ( rfe_error_t ) ( rfe_error_nullPointer_e );
        }
    }
    else
    {
        /* No code required here */
    }
    
    if ( ( rfe_error_t )rfe_error_none_e == *rfe___error___pointer )
    {
        register float32_t scaleF = LOG10_2 * 10.0F;
        for ( register uint32_t u32 = 0UL; u32 < nElements; u32++ )
        {
            register float32_t reF = pCF32[u32].re;
            register float32_t imF = pCF32[u32].im;
            register float32_t energyF = (reF * reF) + (imF * imF);
            pAbsF32dB[u32] = rfeDspMath_log2F( energyF ) * scaleF;
        }
    }
}
