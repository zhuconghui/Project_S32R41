/*
 * Copyright 2023-2024 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

#include <xtensa/tie/xt_FP.h>
#include <xtensa/tie/xt_bben.h>
#include <xtensa/tie/xt_misc.h>
#include <xtensa/tie/radar24.h>

#include "dsp_algo_24b_fixed_functions_s32r41.h"
#include "rsdk_dsp_radar_bb_algos_s32r41.h"






#ifdef __cplusplus
extern "C"{
#endif

// no left end
static const uint16_t maskLeft = 65534U;
// no right end
static const uint16_t maskRight = 32767U;

// shuffle vector one position to the left
static const int16_t shuffleVectorL[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 15};
// shuffle vector one position to the right
static const int16_t shuffleVectorR[16] = {0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

static void Rsdk_CopyFillZerosOffset(bbx_vecNx24 * __restrict pOutput,
                                     bbx_vecNx24 * __restrict pInput,
                                                     uint16_t offset,
                                                     uint16_t size)
{
    uint16_t i;
    bbx_vecNx24 * __restrict pIn, * __restrict pOut;
    bbx_vecNx24 elem;

    pOut = pOutput;
    pIn = pInput;
    for (i = 0; i < size; i++)
    {
        if (i >= offset)
        {
            elem = BBX_MOVI2L(0);
            BBX_SVNX24_IP(elem, pOut, 64U);
        } else
        {
            BBX_LVNX24_IP(elem, pIn, 64U);
            BBX_SVNX24_IP(elem, pOut, 64U);
        }
    }
}
// size must be multiple of 2
static void Rsdk_FftShiftEven(bbx_vecNx24 * __restrict pInOut,
                                  uint16_t size)
{
    uint16_t i;
    bbx_vecNx24 tmp;

    for (i = 0U; i < size / 2U; i++)
    {
        tmp = pInOut[i];
        pInOut[i] = pInOut[size / 2U + i];
        pInOut[size / 2U + i] = tmp;
    }
}

// size must be multiple of 2
static void Rsdk_Mag2(bbx_vecNx24 * __restrict pOutput,
                   bbx_vecN_2xc24 * __restrict pInput,
                          uint16_t size)
{

    bbx_vecNx24 * __restrict pIn = (bbx_vecNx24 * __restrict)(uintptr_t)pInput;
    bbx_vecNx24 * __restrict pOut = pOutput;
    bbx_vecNx24 elem, elem2;
    bbx_vecNx24 tmp_res, tmp_res2;
    bbx_vecNx56 tmp_add, tmp_add2;
    uint16_t i;

    for (i = 0U; i < size - 1U; i += 2U) {
        tmp_add = BBX_MOVA2WW(0);
        tmp_add2 = BBX_MOVA2WW(0);

        BBX_LVNX24_IP(elem, pIn, 64U);
        BBX_LVNX24_IP(elem2, pIn, 64U);
        // obtain (real^2, imag^2) for all elements
        BBX_MULANX24(tmp_add, elem, elem);
        // obtain (imag^2, real^2) for all elements
        elem = BBX_SWPNX24C((bbx_vecN_2xc24)elem);
        // add results to obtain (real^2 + imag^2), (imag^2, real^2)
        BBX_MULANX24(tmp_add, elem, elem);
        // save the result mag2 eq [(real^2 + imag^2)/2] for 8 scalar elements
        // the previous result must be divided with 2
        // and also be divided with 2^23 to keep the results on 24 bits
        // A multiplication with 2^8 is done to avoid underflow and increase precision
        // 2^16 eq 2^23 * 2 / 2^8
        tmp_res = BBX_PACKVNX56(tmp_add, (vsaN)16);
        // repeat procedure for next elements
        BBX_MULANX24(tmp_add2, elem2, elem2);
        elem2 = BBX_SWPNX24C((bbx_vecN_2xc24)elem2);
        BBX_MULANX24(tmp_add2, elem2, elem2);
        tmp_res2 = BBX_PACKVNX56(tmp_add2, (vsaN)16);
        // combine the two mag2 as the datatype used represents 16 scalar elements
        BBX_MOVI2S0(BBE_SELI_EXTRACT_1_OF_2_OFF_0);
        tmp_res =  BBX_SELNX24S0(tmp_res2, tmp_res);
        pOut[i / 2U] = tmp_res;
    }
}


// size must be > 1
static void Rsdk_GlbMaxThresh(int32_t *threshold,
              bbx_vecNx24 * __restrict pInput,
                              uint32_t thresholdFactor,
                              uint32_t size)
{

    bbx_vecNx24 *__restrict pIn = pInput;
    bbx_vecNx24 elem;
    bbx_vecNx24 tmp, tmpMax;
    uint32_t i;
    int32_t maxVal;
    int64_t tmpThresh;

    BBX_LVNX24_IP(elem, pIn, 64U);
    tmpMax = BBX_RMAXNX24(elem);

    for (i = 1U; i < size; i++)
    {
        BBX_LVNX24_IP(elem, pIn, 64U);
        tmp = BBX_RMAXNX24(elem);
        tmpMax = BBX_MAXNX24(tmpMax, tmp);
    }
    maxVal = ((int32_t *)(uintptr_t)&tmpMax)[0U];
    // multiply maxValue with threshold
    tmpThresh = (int64_t)maxVal * (int64_t)thresholdFactor;
    // rescale because thresholdfactor its fixed point on 24 bits(q0.24)
    *threshold = (int32_t)(tmpThresh >> 24);
}




// size > 1 as a requirement
static void Rsdk_LocalMaxThresh(uint16_t *maxBitmap,
                 bbx_vecNx24 * __restrict pInput,
                                  int32_t threshold,
                                 uint16_t size)
{
    bbx_vecNx24 *__restrict pIn = pInput;
    bbx_vecNx24 cmpElem;
    bbx_vecNx24 threshVal;
    xb_vecNx16 *pShuffleVectorL = (xb_vecNx16 *)(uintptr_t)&shuffleVectorL;
    xb_vecNx16 *pShuffleVectorR = (xb_vecNx16 *)(uintptr_t)&shuffleVectorR;
    vboolN* maskL = (vboolN*)(uintptr_t)&maskLeft;
    vboolN* maskR = (vboolN*)(uintptr_t)&maskRight;
    vboolN maskFirst;
    vboolN maskLast;
    vboolN tmpRes, tmpRes2;
    vsaN selectShuffleL = xb_vecNx16_rtor_vsaN(*pShuffleVectorL);
    vsaN selectShuffleR = xb_vecNx16_rtor_vsaN(*pShuffleVectorR);
    uint16_t i = 0U;

    threshVal = int32_rtor_bbx_vecNx24(threshold);
    maskFirst = BBE_NOTB(*maskL);
    maskLast  = BBE_NOTB(*maskR);

    // i = 0
    //  prev elem < elem
    cmpElem = BBX_SHFNX24(pIn[i], selectShuffleR);
    tmpRes = BBX_LTNX24(cmpElem, pIn[i]);
    tmpRes = BBE_ANDB(*maskL, tmpRes);
    // elem >= next_elem => next_elem <= elem
    cmpElem = BBX_SHFNX24(pIn[i], selectShuffleL);
    BBX_MOVA2LT(cmpElem, ((int32_t *)(uintptr_t)&pIn[i + 1U])[0U], maskLast);
    tmpRes2 = BBX_LTENX24(cmpElem, pIn[i]);
    tmpRes = BBE_ANDB(tmpRes2, tmpRes);
    // Compare Threshold (threshVal < pIn[i])
    tmpRes2 = BBX_LTNX24(threshVal, pIn[i]);
    tmpRes = BBE_ANDB(tmpRes2, tmpRes);
    maxBitmap[i] = *((uint16_t *)(uintptr_t)&tmpRes);

    for (i = 1U; i < size - 1U; i++)
    {
        //  prev elem < elem
        //  prev elem < elem
        cmpElem = BBX_SHFNX24(pIn[i], selectShuffleR);
        BBX_MOVA2LT(cmpElem, ((int32_t *)(uintptr_t)&pIn[i - 1U])[15U], maskFirst);
        tmpRes = BBX_LTNX24(cmpElem, pIn[i]);
        // elem >= next_elem => next_elem <= elem
        cmpElem = BBX_SHFNX24(pIn[i], selectShuffleL);
        BBX_MOVA2LT(cmpElem, ((int32_t *)(uintptr_t)&pIn[i + 1U])[0U], maskLast);
        tmpRes2 = BBX_LTENX24(cmpElem, pIn[i]);
        tmpRes = BBE_ANDB(tmpRes2, tmpRes);
        // Compare Threshold (threshVal < pIn[i])
        tmpRes2 = BBX_LTNX24(threshVal, pIn[i]);
        tmpRes = BBE_ANDB(tmpRes2, tmpRes);
        maxBitmap[i] = *((uint16_t *)(uintptr_t)&tmpRes);

    }
    // i  = size - 1
    // elem >= next_elem : next_elem <= elem
    cmpElem = BBX_SHFNX24(pIn[i], selectShuffleL);
    tmpRes = BBX_LTENX24(cmpElem, pIn[i]);
    tmpRes = BBE_ANDB(*maskR, tmpRes);
    //  prev elem < elem
    cmpElem = BBX_SHFNX24(pIn[i], selectShuffleR);
    BBX_MOVA2LT(cmpElem, ((int32_t *)(uintptr_t)&pIn[i - 1U])[15U], maskFirst);
    tmpRes2 = BBX_LTNX24(cmpElem, pIn[i]);
    tmpRes = BBE_ANDB(tmpRes2, tmpRes);
    // Compare Threshold (threshVal < pIn[i])
    tmpRes2 = BBX_LTNX24(threshVal, pIn[i]);
    tmpRes = BBE_ANDB(tmpRes2, tmpRes);
    maxBitmap[i] = *((uint16_t *)(uintptr_t)&tmpRes);
}

void Rsdk_Doa128(bbx_vecNx24 * __restrict pOutputMag,
                               uint16_t * pOutputBitmap,
                 bbx_vecNx24 * __restrict pInput,
              bbx_vecN_2xc24 * __restrict pScratch1,
              bbx_vecN_2xc24 * __restrict pScratch2,
		          xb_vecNx16 * __restrict pTwiddles,
				  xb_vecNx16 * __restrict pWindow,
                      uint32_t thresholdFactor,
                      uint16_t noAntennas,
                      uint16_t shift,
                      uint16_t noPeaks)
{
    bbx_vecNx24 * __restrict tmp;
    bbx_vecNx24 * __restrict pIn;
    bbx_vecNx24  * __restrict pOutMag;
    uint16_t    *pOutBmap;
    int32_t      threshold;
    uint16_t     i;

    for (i = 0U; i < noPeaks; i++)
    {
        pOutMag = &pOutputMag[i * 128U / 16U];
        pOutBmap = &pOutputBitmap[i * 128U / 16U];
        pIn = &pInput[i * 2U * noAntennas / 16U];
        tmp = (bbx_vecNx24 *)(uintptr_t)pOutMag;
        // copy and fill with 0 to complete to 128 complex elements
        Rsdk_CopyFillZerosOffset(tmp, pIn, 2U * noAntennas / 16U, 2U * 128U / 16);
        // fft on the new input
        Rsdk_FftCplx((bbx_vecN_2xc24 * __restrict)(uintptr_t)tmp, pScratch1, pScratch2, pTwiddles, pWindow, shift, 128U);
        // shift FFT spectre
        Rsdk_FftShiftEven(tmp, 2U * 128U/16U);
        // magnitude
        Rsdk_Mag2(pOutMag, tmp, 2U * 128U/16U);
        // Global max to obtain threshold
        Rsdk_GlbMaxThresh(&threshold, pOutMag, thresholdFactor, 128U/16U);
        // local maxBitmap with threshold(localmax > threshold)
        Rsdk_LocalMaxThresh(pOutBmap, pOutMag, threshold, 128U/16U);
    }
}

void Rsdk_Doa256(bbx_vecNx24 * __restrict pOutputMag,
                               uint16_t * pOutputBitmap,
                 bbx_vecNx24 * __restrict pInput,
              bbx_vecN_2xc24 * __restrict pScratch1,
              bbx_vecN_2xc24 * __restrict pScratch2,
		          xb_vecNx16 * __restrict pTwiddles,
				  xb_vecNx16 * __restrict pWindow,
                                 uint32_t thresholdFactor,
                                 uint16_t noAntennas,
                                 uint16_t shift,
                                 uint16_t noPeaks)
{
    bbx_vecNx24 * __restrict tmp;
    bbx_vecNx24 * __restrict pIn;
    bbx_vecNx24  * __restrict pOutMag;
    uint16_t    *pOutBmap;
    int32_t      threshold;
    uint16_t     i;

    for (i = 0U; i < noPeaks; i++)
    {
        pOutMag = &pOutputMag[i * 256U / 16U];
        pOutBmap = &pOutputBitmap[i * 256U / 16U];
        pIn = &pInput[i * 2U *noAntennas / 16U];
        tmp = (bbx_vecNx24 * __restrict)(uintptr_t)pOutMag;
        // copy and fill with 0 to complete to 256 complex elements
        Rsdk_CopyFillZerosOffset(tmp, pIn, 2 * noAntennas / 16, 2U * 256U / 16);
        // fft on the new input
        Rsdk_FftCplx((bbx_vecN_2xc24 * __restrict)(uintptr_t)tmp, pScratch1, pScratch2, pTwiddles, pWindow, shift, 256U);
        // shift FFT spectre
        Rsdk_FftShiftEven(tmp, 2U * 256U/16U);
        // magnitude
        Rsdk_Mag2(pOutMag, tmp, 2U * 256U/16U);
        // Global max to obtain threshold
        Rsdk_GlbMaxThresh(&threshold, pOutMag, thresholdFactor, 256U/16U);
        // local maxBitmap with threshold(localmax > threshold)
        Rsdk_LocalMaxThresh(pOutBmap, pOutMag, threshold, 256U/16U);
    }
}

#ifdef __cplusplus
}
#endif

/*******************************************************************************
* EOF
******************************************************************************/

