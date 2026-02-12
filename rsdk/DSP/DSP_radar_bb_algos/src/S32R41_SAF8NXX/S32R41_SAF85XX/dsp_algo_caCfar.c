/*
 * Copyright 2018,2021-2024 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

#include <assert.h>
#include <xtensa/tie/xt_FP.h>
#include <xtensa/tie/xt_bben.h>
#include <xtensa/tie/xt_misc.h>
#include <xtensa/tie/radar24.h>

#include "rsdk_dsp_radar_bb_algos_s32r41.h"



#include "hw_defs.h"

#ifdef __cplusplus
extern "C" {
#endif


#define ROUND_SCALE_FACTOR 32768

#define SHIFT_VAL (6u)    //>=2*log2(max(cfarParams.windowSize))

void RsdkBbe32CaCfar(uintptr_t argList)
{
    rsdkBbe32CaCfarParams_t* cfarParams = ((rsdkBbe32CaCfarParams_t**)argList)[0];

    xb_vecNx16U * pVecRdm =(xb_vecNx16U*)cfarParams->pRdm;
    xb_vecNx16U * pVecThr = (xb_vecNx16U*)cfarParams->pThr;
    uint16_t* pDetectBmp = (uint16_t*)cfarParams->pDetectBitmap;

    /* check restrictions */
    if ((uintptr_t)pVecRdm % (2 * BBE_SIMD_WIDTH) != 0)
    {
        SetDspError(RSDK_DSP_ALGO_WRONG_ALIGN);
        return;
    }
    if ((uintptr_t)pVecThr % (2 * BBE_SIMD_WIDTH) != 0)
    {
        SetDspError(RSDK_DSP_ALGO_WRONG_ALIGN);
        return;
    }

    if (cfarParams->dopplerBins % BBE_SIMD_WIDTH != 0)
    {
        SetDspError(RSDK_DSP_ALGO_WRONG_PARAM);
        return;
    }

    if (cfarParams->dopplerBins == 0)
    {
        SetDspError(RSDK_DSP_ALGO_WRONG_PARAM);
        return;
    }

    xb_vecNx40 thrAccum, temp40;
    xb_vecNx16U temp16U;
    vboolN detects;
    
    uint16_t scalingFactor = cfarParams->thresholdFactor;
    uint8_t g = cfarParams->guardInterval;
    uint8_t w = cfarParams->windowSize;
    uint8_t j, cfarLen = g+w;
    uint16_t nd = cfarParams->dopplerBins;
    uint16_t ir, nr = cfarParams->rangeBins;
    uint16_t id, rdmLineOffsetVec16 = nd/BBE_SIMD_WIDTH;
    float    tapValueFloat;
    uint16_t tapValueQ15_1, tapValueQ15_2, tapValueQ15_vec[30];

    //compute scaling factors for the CS-CFAR estimators
    tapValueFloat = 1 / (float)cfarParams->windowSize;

    // Check if value can be converted to fixed point Q15
    if (tapValueFloat >= 1)
    {
        SetDspError(RSDK_DSP_ALGO_CANNOT_CONVERT_TO_FIXED_POINT);
        return;
    }

    tapValueQ15_1 = (uint16_t)(XT_FIROUND_S(tapValueFloat * ROUND_SCALE_FACTOR));


    tapValueQ15_2 = tapValueQ15_1/2;
    for ( j=0; j<=w; j++ )
    {
        tapValueFloat = 1 / (float)(cfarParams->windowSize + j);
        tapValueQ15_vec[j] = (uint16_t)(XT_FIROUND_S(tapValueFloat * ROUND_SCALE_FACTOR));
    }

    //compute the CS-CFAR estimators:
    //outer loop splits the rdm 'range=const' lines into swaths of BBE_SIMD_WIDTH samples.
    for ( id=0; id<rdmLineOffsetVec16; id++ )
    {
        //inner loops compute the CA-CFAR thresholds from range cell 0 to Nr-1.

        //initialize the CFAR estimator for first 'range=const' line, by summing only one half of the estimation window
        //and dividing to windowSize samples
        thrAccum = (xb_vecNx40)0;
        ir=0;
        for ( j=g+1; j<=cfarLen; j++ )
        {
            //thrAccum += pVecRdm[rdmLineOffsetVec16 * j + id]; //TODO: replace with BBE_ADDWUA16U ? or BBE_MULANXQ15PR?
            BBE_MULUUANX16(thrAccum, pVecRdm[rdmLineOffsetVec16 * j + id], (xb_vecNx16U)1);
        }
        //pVecThr[0 + id] = thrAccum * (xb_vecNx16U)tapValueQ15_1;    //TODO: replace with int32_rtor_xb_vecNx16U?
        temp16U = (xb_vecNx16U)BBE_SRAINX40(thrAccum, SHIFT_VAL);    //shift right to keep accumulated result within 16 bits resolution
        temp40 = BBE_MULUUNX16(temp16U, (xb_vecNx16U)tapValueQ15_1);
        pVecThr[rdmLineOffsetVec16 * ir + id] = BBE_ADDNX16U((xb_vecNx16U)(temp40 >> (15-SHIFT_VAL)), (xb_vecNx16U)scalingFactor);

        detects = BBE_GTUNX16U(pVecRdm[rdmLineOffsetVec16 * ir + id], pVecThr[rdmLineOffsetVec16 * ir + id]);
        BBE_SBN_I(detects, (void*)&pDetectBmp[rdmLineOffsetVec16*ir + id], 0);

        //BBX_SCRLU(0x11000000 + id, 0xBC);


        //first batch:
        //CFAR estimator computed by sliding only the leading half of the estimation window - adding 1 lead cell and subtracting 1 trailing cell
        //from the accumulator, then dividing with windowSize
        for ( ir=1; ir<=g; ir++ )
        {
            //thrAccum += pVecRdm[rdmLineOffsetVec16 * (ir + cfarLen) + id] -
            //            pVecRdm[rdmLineOffsetVec16 * (ir + g) + id];

            //pVecThr[rdmLineOffsetVec16 * ir + id] = thrAccum * (xb_vecNx16U)tapValueQ15_1;

            BBE_MULUUANX16(thrAccum, pVecRdm[rdmLineOffsetVec16 * (ir + cfarLen) + id], (xb_vecNx16U)1);
            BBE_MULUSANX16(thrAccum, pVecRdm[rdmLineOffsetVec16 * (ir + g) + id], (xb_vecNx16)(-1));

            //pVecThr[rdmLineOffsetVec16 * ir + id] = (xb_vecNx16U)(thrAccum >> 15);
            temp16U = (xb_vecNx16U)BBE_SRAINX40(thrAccum, SHIFT_VAL);    //shift right to keep accumulated result within 16 bits resolution
            temp40 = BBE_MULUUNX16(temp16U, (xb_vecNx16U)tapValueQ15_1);
            temp40 = BBE_ADDNX40(temp40, (xb_vecNx40)scalingFactor);
            pVecThr[rdmLineOffsetVec16 * ir + id] = BBE_ADDNX16U((xb_vecNx16U)(temp40 >> (15-SHIFT_VAL)), (xb_vecNx16U)scalingFactor);

            detects = BBE_GTUNX16U(pVecRdm[rdmLineOffsetVec16 * ir + id], pVecThr[rdmLineOffsetVec16 * ir + id]);
            BBE_SBN_I(detects, (void*)&pDetectBmp[rdmLineOffsetVec16*ir + id], 0);
        }

        //batch 2:
        //CFAR estimator computed by adding 2 lead cells (ir+cfarLen and ir-g-1) and subtracting 1 trailing cell (ir+g)
        //from the accumulator, then dividing with variable factor [windowSize+1 .. 2*windowSize]
        for ( ir=g+1; ir<=cfarLen; ir++ )
        {
//            thrAccum += pVecRdm[rdmLineOffsetVec16 * (ir + cfarLen) + id] -
//                        pVecRdm[rdmLineOffsetVec16 * (ir + g) + id]       +
//                           pVecRdm[rdmLineOffsetVec16 * (ir - g - 1) + id];
//
//            pVecThr[rdmLineOffsetVec16 * ir + id] = thrAccum * (xb_vecNx16U)tapValueQ15_vec[ir - g - 1];

            BBE_MULUUANX16(thrAccum, pVecRdm[rdmLineOffsetVec16 * (ir + cfarLen) + id], (xb_vecNx16U)1);
            BBE_MULUSANX16(thrAccum, pVecRdm[rdmLineOffsetVec16 * (ir + g) + id], (xb_vecNx16)(-1));
            BBE_MULUUANX16(thrAccum, pVecRdm[rdmLineOffsetVec16 * (ir - g -1) + id], (xb_vecNx16U)1);

            //pVecThr[rdmLineOffsetVec16 * ir + id] = (xb_vecNx16U)(thrAccum >> 15);
            temp16U = (xb_vecNx16U)BBE_SRAINX40(thrAccum, SHIFT_VAL);
            temp40 = BBE_MULUUNX16(temp16U, (xb_vecNx16U)tapValueQ15_vec[ir - g]);
            temp40 = BBE_ADDNX40(temp40, (xb_vecNx40)scalingFactor);
            pVecThr[rdmLineOffsetVec16 * ir + id] = BBE_ADDNX16U((xb_vecNx16U)(temp40 >> (15-SHIFT_VAL)), (xb_vecNx16U)scalingFactor);

            detects = BBE_GTUNX16U(pVecRdm[rdmLineOffsetVec16 * ir + id], pVecThr[rdmLineOffsetVec16 * ir + id]);
            BBE_SBN_I(detects, (void*)&pDetectBmp[rdmLineOffsetVec16*ir + id], 0);
        }

        //batch 3:
        //CFAR estimator computed by slidinig the entire estimation window - adding 2 lead cells and subtracting 2 trailing cells
        //from the accumulator, then dividing with 2*windowSize
        for ( ir=cfarLen+1; ir <= (nr - 1 - cfarLen); ir++ )
        {
//            thrAccum += pVecRdm[rdmLineOffsetVec16 * (ir + cfarLen) + id]     -
//                        pVecRdm[rdmLineOffsetVec16 * (ir + g) + id]           +
//                           pVecRdm[rdmLineOffsetVec16 * (ir - g - 1) + id]             -
//                           pVecRdm[rdmLineOffsetVec16 * (ir - cfarLen - 1) + id];
//
//            pVecThr[rdmLineOffsetVec16 * ir + id] = thrAccum * (xb_vecNx16U)tapValueQ15_2;

            BBE_MULUUANX16(thrAccum, pVecRdm[rdmLineOffsetVec16 * (ir + cfarLen) + id], (xb_vecNx16U)1);
            BBE_MULUSANX16(thrAccum, pVecRdm[rdmLineOffsetVec16 * (ir + g) + id], (xb_vecNx16)(-1));
            BBE_MULUUANX16(thrAccum, pVecRdm[rdmLineOffsetVec16 * (ir - g -1) + id], (xb_vecNx16U)1);
            BBE_MULUSANX16(thrAccum, pVecRdm[rdmLineOffsetVec16 * (ir - cfarLen - 1) + id], (xb_vecNx16)(-1));

            //pVecThr[rdmLineOffsetVec16 * ir + id] = (xb_vecNx16U)(thrAccum >> 15);
            temp16U = (xb_vecNx16U)BBE_SRAINX40(thrAccum, SHIFT_VAL);
            temp40 = BBE_MULUUNX16(temp16U, (xb_vecNx16U)tapValueQ15_2);
            temp40 = BBE_ADDNX40(temp40, (xb_vecNx40)scalingFactor);
            pVecThr[rdmLineOffsetVec16 * ir + id] = BBE_ADDNX16U((xb_vecNx16U)(temp40 >> (15-SHIFT_VAL)), (xb_vecNx16U)scalingFactor);

            detects = BBE_GTUNX16U(pVecRdm[rdmLineOffsetVec16 * ir + id], pVecThr[rdmLineOffsetVec16 * ir + id]);
            BBE_SBN_I(detects, (void*)&pDetectBmp[rdmLineOffsetVec16*ir + id], 0);
        }

        //batch 4:
        //CFAR estimator computed by adding 1 lead cell and subtracting 2 trailing cells
        //from the accumulator, then dividing with variable factor [2*windowSize .. windowSize+1]
        for ( ir = nr - 1 - cfarLen + 1 ; ir <= nr - 1 - g; ir++ )
        {
//            thrAccum += (xb_vecNx16U)0 -
//                        pVecRdm[rdmLineOffsetVec16 * (ir + g) + id]           +
//                           pVecRdm[rdmLineOffsetVec16 * (ir - g - 1) + id]             -
//                           pVecRdm[rdmLineOffsetVec16 * (ir - cfarLen - 1) + id];
//
//            pVecThr[rdmLineOffsetVec16 * ir + id] = thrAccum * (xb_vecNx16U)tapValueQ15_vec[nr - 1 - g - ir];

            BBE_MULUSANX16(thrAccum, pVecRdm[rdmLineOffsetVec16 * (ir + g) + id], (xb_vecNx16)(-1));
            BBE_MULUUANX16(thrAccum, pVecRdm[rdmLineOffsetVec16 * (ir - g - 1) + id], (xb_vecNx16U)1);
            BBE_MULUSANX16(thrAccum, pVecRdm[rdmLineOffsetVec16 * (ir - cfarLen - 1) + id], (xb_vecNx16)(-1));

            //pVecThr[rdmLineOffsetVec16 * ir + id] = (xb_vecNx16U)(thrAccum >> 15);
            temp16U = (xb_vecNx16U)BBE_SRAINX40(thrAccum, SHIFT_VAL);
            temp40 = BBE_MULUUNX16(temp16U, (xb_vecNx16U)tapValueQ15_vec[nr - 1 - g - ir]);
            temp40 = BBE_ADDNX40(temp40, (xb_vecNx40)scalingFactor);
            pVecThr[rdmLineOffsetVec16 * ir + id] = BBE_ADDNX16U((xb_vecNx16U)(temp40 >> (15-SHIFT_VAL)), (xb_vecNx16U)scalingFactor);

            detects = BBE_GTUNX16U(pVecRdm[rdmLineOffsetVec16 * ir + id], pVecThr[rdmLineOffsetVec16 * ir + id]);
            BBE_SBN_I(detects, (void*)&pDetectBmp[rdmLineOffsetVec16*ir + id], 0);
        }

        //batch 5:
        //CFAR estimator computed by sliding only the trailing half of the estimation window - adding 1 lead cell and subtracting 1 trailing cell
        //from the accumulator, then dividing with windowSize
        for ( ir = nr - 1 - g + 1; ir <= nr-1; ir++ )
        {
//            thrAccum += pVecRdm[rdmLineOffsetVec16 * (ir - g - 1) + id]             -
//                           pVecRdm[rdmLineOffsetVec16 * (ir - cfarLen - 1) + id];
//
//            pVecThr[rdmLineOffsetVec16 * ir + id] = thrAccum * (xb_vecNx16U)tapValueQ15_1;

            BBE_MULUUANX16(thrAccum, pVecRdm[rdmLineOffsetVec16 * (ir - g - 1) + id], (xb_vecNx16U)1);
            BBE_MULUSANX16(thrAccum, pVecRdm[rdmLineOffsetVec16 * (ir - cfarLen - 1) + id], (xb_vecNx16)(-1));

            //pVecThr[rdmLineOffsetVec16 * ir + id] = (xb_vecNx16U)(thrAccum >> 15);
            temp16U = (xb_vecNx16U)BBE_SRAINX40(thrAccum, SHIFT_VAL);
            temp40 = BBE_MULUUNX16(temp16U, (xb_vecNx16U)tapValueQ15_1);
            temp40 = BBE_ADDNX40(temp40, (xb_vecNx40)scalingFactor);
            pVecThr[rdmLineOffsetVec16 * ir + id] = BBE_ADDNX16U((xb_vecNx16U)(temp40 >> (15-SHIFT_VAL)), (xb_vecNx16U)scalingFactor);

            detects = BBE_GTUNX16U(pVecRdm[rdmLineOffsetVec16 * ir + id], pVecThr[rdmLineOffsetVec16 * ir + id]);
            BBE_SBN_I(detects, (void*)&pDetectBmp[rdmLineOffsetVec16*ir + id], 0);
        }

    }

}

#ifdef __cplusplus
}
#endif

/*******************************************************************************
* EOF
******************************************************************************/
