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
 * NXP_M7DSP_fft.c
 *
 *  Created on: Jan 19, 2021
 *      Author: Kai & strx-sw team, memory optimized version
 *
 */

#include "rfeDspMath_fft.h"
#include "rfeDspMath_internal.h"

void fft_bitreversal(int16x2_t* pData, uint32_t bits)
{
    uint32_t size  = 1UL << bits;
    uint32_t shift = 32UL - bits;
    uint32_t i;

    for(i = 1UL; i < (size - 1UL); i++)
    {
        uint32_t z = __RBIT(i) >> shift;
        if (z > i)
        {
            int16x2_t tmp = pData[i];
            pData[i] = pData[z];
            pData[z] = tmp;
        }
        else
        {
            // No swap if condition fails
        }
    }
}

void fft_forwardF32 (
    const int16x2_t* pData,
    uint32_t         fftBits,
    const uint32_t*  pSinQ1InIeee754Bits,
    uint32_t         sinQ1MaxIdx,
    cfloat32_t*      pOutCF
)
{
    uint32_t k;
    uint32_t phaStep = sinQ1MaxIdx;

    /* Calculate input data index bitlength to input element count */
    uint32_t fftsize = 1UL << fftBits;  // size of complex cFFT, but Half-size of real input rFFT
    float32_t nF = ( float32_t )fftsize;

    /**
      First FFT-4 simplified stage for stride=2 (only contains coefficients 0 and 1):
       For each FFT-4 block:
         - Input data contain even elemnets at low 16-bit and odd at high 16-bit, i.e. data[0].lo = x0, data[0].hi = x1
         - Put sum of even two input data in the first output position, and their subtraction in the second output persition
     */
    for ( k = 0UL; k < fftsize; k += 2U )
    {
        register int16x2_t data_k  = pData[k];
        register int16x2_t data_k1 = pData[k + 1U];

        /* Get real part FFT4 results */
        register int16_t i16a = rfeDspMath_unpackLowI16x2( data_k );
        register int16_t i16b = rfeDspMath_unpackLowI16x2( data_k1 );
        register float32_t f32a = ( float32_t )i16a;
        register float32_t f32b = ( float32_t )i16b;
        pOutCF[k + 1U].re = ( f32a - f32b ) / nF;
        pOutCF[  k  ].re = ( f32a + f32b ) / nF;

        /* Get imaginary part FFT4 results */
        i16a = rfeDspMath_unpackHighI16x2( data_k );
        i16b = rfeDspMath_unpackHighI16x2( data_k1 );
        f32a = ( float32_t )i16a;
        f32b = ( float32_t )i16b;
        pOutCF[k + 1U].im = ( f32a - f32b ) / nF;
        pOutCF[  k  ].im = ( f32a + f32b ) / nF;
    }

    /* process stride 4..fftbits */
    uint32_t n1 = 2UL;
    for ( uint32_t stride = 4UL; stride <= fftsize; stride <<= 1U )
    {
        /* 2nd trivial butterfly case on even data (for phi=0 and each stride):  */
        for ( k = 0UL; k < fftsize; k += stride )
        {
            register float32_t fr  = pOutCF[k].re;
            register float32_t fi  = pOutCF[k].im;
            register float32_t fr1 = pOutCF[k + n1].re;
            register float32_t fi1 = pOutCF[k + n1].im;

            pOutCF[ k ].re = fr + fr1;
            pOutCF[ k ].im = fi + fi1;
            pOutCF[k + n1].re = fr - fr1;
            pOutCF[k + n1].im = fi - fi1;
        }

        /*  2nd trivial butterfly case on odd data (for phi=0 and each stride): case where cos = 0 and sin=-FS */
        for ( k = n1 >> 1U; k < fftsize; k += stride )
        {
            register float32_t fr  = pOutCF[k].re;
            register float32_t fi  = pOutCF[k].im;
            register float32_t f2r = pOutCF[k + n1].re;
            register float32_t f2i = pOutCF[k + n1].im;

            pOutCF[ k ].re    = fr + f2i;  /* for x = x+y, y = y-x */
            pOutCF[ k ].im    = fi - f2r;
            pOutCF[k + n1].re = fr - f2i;  /* for x = x-y, y = y+x */
            pOutCF[k + n1].im = fi + f2r;
        }


        /* bruteforce symmetry of coefficients! This limits angle input       */
        /* range for sin/cos to 0..pi/2 which helps to half the sin/cos table size! */
        uint32_t sinIdx = phaStep;
        for ( uint32_t j = 1UL; j < ( n1 >> 1U ); j++ )
        {
            float32_t fCosCoef = rfeDspMath_loadSineFromIeee754Table( pSinQ1InIeee754Bits, sinQ1MaxIdx - sinIdx );
            float32_t fSinCoef = rfeDspMath_loadSineFromIeee754Table( pSinQ1InIeee754Bits, sinIdx );
            uint32_t k2 = n1 - j;

            for ( k = j; k < fftsize; k += stride )
            {
                /* full featured DFT2 butterfly */
                register float32_t fr  = pOutCF[k].re;
                register float32_t fi  = pOutCF[k].im;
                register float32_t f2r = pOutCF[k + n1].re;
                register float32_t f2i = pOutCF[k + n1].im;

                register float32_t f32r = (f2r * fSinCoef) - (f2i * fCosCoef);
                register float32_t f32i = (f2r * fCosCoef) + (f2i * fSinCoef);

                pOutCF[ k ].re    = fr + f32i;
                pOutCF[ k ].im    = fi - f32r;
                pOutCF[k + n1].re = fr - f32i;
                pOutCF[k + n1].im = fi + f32r;

                /* this is the other symmetric part */
                fr  = pOutCF[k2].re;
                fi  = pOutCF[k2].im;
                f2r = pOutCF[k2 + n1].re;
                f2i = pOutCF[k2 + n1].im;

                f32r = (f2r * fSinCoef)    - (f2i * (-fCosCoef));
                f32i = (f2r * (-fCosCoef)) + (f2i * fSinCoef);

                pOutCF[ k2 ].re    = fr + f32i;
                pOutCF[ k2 ].im    = fi - f32r;
                pOutCF[k2 + n1].re = fr - f32i;
                pOutCF[k2 + n1].im = fi + f32r;
                
                k2 += stride;
            }

            sinIdx += phaStep;
        }

        n1 <<= 1U;
        phaStep >>= 1U;
    }
}

void fft_rfftfinalstageF32(
    cfloat32_t*     pInOut,
    uint32_t        rfftbitsDiv2,
    const uint32_t* pSinQ1InIeee754Bits,
    uint32_t        sinQ1MaxIdx
)
{
    uint32_t phaStep = sinQ1MaxIdx >> ( rfftbitsDiv2 - 1U );
    uint32_t sinIdx = 0UL;
    uint32_t cosIdx = sinQ1MaxIdx;
    register float32_t nF = 2.0F; // extra downscale to reach full FFT size downscaling

    uint32_t framesize =  1UL << rfftbitsDiv2;
    uint32_t n = framesize >> 1U;

    register float32_t fr = pInOut[0].re;
    register float32_t fi = pInOut[0].im;
    pInOut[0].re = ( fr + fi ) / nF;
    pInOut[0].im = ( fr - fi ) / nF;

    pInOut[n].re = pInOut[n].re / nF;
    pInOut[n].im = -pInOut[n].im / nF;

    nF *= 2.0F;   // Required scaling to convert results to real FFT spectrum
    for ( n = 1UL; n < ( framesize >> 1U ); n++ )
    {
        cosIdx -= phaStep;
        sinIdx += phaStep;
        float32_t fCosCoef = rfeDspMath_loadSineFromIeee754Table( pSinQ1InIeee754Bits, cosIdx );
        float32_t fSinCoef = - rfeDspMath_loadSineFromIeee754Table( pSinQ1InIeee754Bits, sinIdx );

        uint32_t m = framesize - n;

        fr  = pInOut[n].re;
        fi  = pInOut[n].im;
        register float32_t f2r = pInOut[m].re;
        register float32_t f2i = -pInOut[m].im;

        register float32_t f32r = fr + f2r;
        register float32_t f32i = fi + f2i;

        fr = f2r - fr;
        fi = f2i - fi;

        f2r =  (fCosCoef * fi) + (fSinCoef * fr);  // calculate real
        f2i =  (fCosCoef * fr) - (fSinCoef * fi);  // calculate imag

        pInOut[n].re = ( f32r - f2r ) / nF;
        pInOut[n].im = ( f32i + f2i ) / nF;
        pInOut[m].re = ( f32r + f2r ) / nF;
        pInOut[m].im = ( f2i - f32i ) / nF;
    }
}

/**
  \brief   rfeDspMath_fftI16F: General real input FFT of fftSize = ( 1<< nPower2 ) elements by floating-point calculation,
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
               ...
             pFreq[fftSize-1].re   = pHalf[1].re;              pFreq[fftSize-1].im   = -pHalf[1].im;

  \param [in]      pIn     Pointer to the input data in int16x2 array. Note: value in pIn is reshuffled in FFT.
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
)
{
    const uint32_t* pSinQ1InIeee754Bits = rfeDspMat_sine1024Q1_f32;
    uint32_t sinQ1MaxIdx = RFE_DSP_SINE1Q_MAXIDX;

    if ( ( NULL == pIn ) || ( NULL == pHalf ) )
    {
        if ( ( rfe_error_t )rfe_error_none_e == *rfe___error___pointer )
        {
            *rfe___error___pointer = ( rfe_error_t ) ( rfe_error_nullPointer_e );
        }
    }
    else if ( ( ( uint32_t )1UL << ( nPower2 - 2U ) ) > sinQ1MaxIdx )
    {
        if ( ( rfe_error_t )rfe_error_none_e == *rfe___error___pointer )
        {
            *rfe___error___pointer = ( rfe_error_t )( rfe_error_invalidValue_e );
        }
    }
    else
    {
        /* No code required here */
    }

    if ( ( rfe_error_t )rfe_error_none_e == *rfe___error___pointer )
    {
        fft_bitreversal( pIn, nPower2 - 1U );
        fft_forwardF32( pIn, nPower2 - 1U, pSinQ1InIeee754Bits, sinQ1MaxIdx, pHalf);
        fft_rfftfinalstageF32( pHalf, nPower2 - 1U, pSinQ1InIeee754Bits, sinQ1MaxIdx );
    }
}



