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


#include "rsdk_dsp_radar_bb_algos_s32r41.h"
#include "dsp_algo_24b_fixed_functions_s32r41.h"




#include "dsp_algo_24b_fixed_helper.h"
#include "dsp_algo_24b_fixed_twiddles.h"
#include "dsp_algo_24b_fixed_window.h"
#include "hw_defs.h"
#include <xtensa/tie/xt_FP.h>
#include <xtensa/tie/xt_bben.h>
#include <xtensa/tie/xt_misc.h>
#include <xtensa/tie/radar24.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
void RsdkBbe32FftInit(uintptr_t argList)
{
	rsdkBbe32FftInitParams_t * fftInitParams = ((rsdkBbe32FftInitParams_t**)argList)[0];

	uint32_t fftSize = fftInitParams->size;
	xb_vecNx16 * pTwiddles = (xb_vecNx16 *)(uintptr_t)fftInitParams->pTwiddlesArea;
    xb_vecNx16U * pWindow = (xb_vecNx16 *)(uintptr_t)fftInitParams->pWindowArea;

    switch(fftSize)
    {
    	case RSDK_BBE32_FFT_SIZE_128:
			RsdkVMemCpy16(pTwiddles, (xb_vecNx16 *)(uintptr_t)RsdkBbe32Twiddle128, DSP_ALGO_FFT128_TWIDDLES_LEN / 16);
		    RsdkVMemCpy16(pWindow, (xb_vecNx16 *)(uintptr_t)RsdkBbe32FftWindow128, fftSize / (2 * 16));
    		break;
    	case RSDK_BBE32_FFT_SIZE_256:
			RsdkVMemCpy16(pTwiddles, (xb_vecNx16 *)(uintptr_t)RsdkBbe32Twiddle256, DSP_ALGO_FFT256_TWIDDLES_LEN / 16);
		    RsdkVMemCpy16(pWindow, (xb_vecNx16 *)(uintptr_t)RsdkBbe32FftWindow256, fftSize / (2 * 16));
    		break;
    	case RSDK_BBE32_FFT_SIZE_512:
			RsdkVMemCpy16(pTwiddles, (xb_vecNx16 *)(uintptr_t)RsdkBbe32Twiddle512, DSP_ALGO_FFT512_TWIDDLES_LEN / 16);
		    RsdkVMemCpy16(pWindow, (xb_vecNx16 *)(uintptr_t)RsdkBbe32FftWindow512, fftSize / (2 * 16));
			break;
    	case RSDK_BBE32_FFT_SIZE_1024:
			RsdkVMemCpy16(pTwiddles, (xb_vecNx16 *)(uintptr_t)RsdkBbe32Twiddle1024, DSP_ALGO_FFT1024_TWIDDLES_LEN / 16);
		    RsdkVMemCpy16(pWindow, (xb_vecNx16 *)(uintptr_t)RsdkBbe32FftWindow1024, fftSize / (2 * 16));
    		break;
    	case RSDK_BBE32_FFT_SIZE_2048:
			RsdkVMemCpy16(pTwiddles, (xb_vecNx16 *)(uintptr_t)RsdkBbe32Twiddle2048, DSP_ALGO_FFT2048_TWIDDLES_LEN / 16);
		    RsdkVMemCpy16(pWindow, (xb_vecNx16 *)(uintptr_t)RsdkBbe32FftWindow2048, fftSize / (2 * 16));
    		break;
    	default:
    		SetDspError(RSDK_DSP_RET_ERR_INVALID_PARAM);
    		break;
    }

}

void RsdkBbe32FftCplx(uintptr_t argList)
{
    rsdkBbe32FftCplxParams_t* fftParams = ((rsdkBbe32FftCplxParams_t**)argList)[0];
    // pointer for twiddles buffer in DRAM
    xb_vecNx16 * pTwiddles = (xb_vecNx16 *)(uintptr_t)fftParams->pTwiddlesArea;
    // pointer for InOut buffer in DRAM
    bbx_vecN_2xc24 * pInOut = (bbx_vecN_2xc24 * __restrict)(uintptr_t)fftParams->pInOut;
    // pointer for Scratch1 and Scratch2 buffers in DRAM
    bbx_vecN_2xc24 * pScratch1 =(bbx_vecN_2xc24 *)(uintptr_t)fftParams->pScratch1Area;
    bbx_vecN_2xc24 * pScratch2 =(bbx_vecN_2xc24 *)(uintptr_t)fftParams->pScratch2Area;
    // pointer for Window coefficients in DRAM
    xb_vecNx16U * pWindow = (xb_vecNx16 *)(uintptr_t)fftParams->pWindowArea;

    Rsdk_FftCplx(pInOut, pScratch1, pScratch2, pTwiddles, pWindow, fftParams->shift, fftParams->size);
}

void RsdkBbe32Fft2Real(uintptr_t argList)
{
    rsdkBbe32Fft2RealParams_t* fft2realParams = ((rsdkBbe32Fft2RealParams_t**)argList)[0];
    // pointer for twiddles buffer
    xb_vecNx16 * pTwiddles = (xb_vecNx16 *)(uintptr_t)fft2realParams->pTwiddlesArea;
    // pointer for InOut1 and InOut2 buffers
    bbx_vecN_2xc24 * pOut1 = (bbx_vecN_2xc24 * )(uintptr_t)fft2realParams->pOut1;
    bbx_vecN_2xc24 * pOut2 = (bbx_vecN_2xc24 * )(uintptr_t)fft2realParams->pOut2;
    xb_vecNx16 * pIn1 = (xb_vecNx16 * __restrict)(uintptr_t)fft2realParams->pIn1;
    xb_vecNx16 * pIn2 = (xb_vecNx16 * __restrict)(uintptr_t)fft2realParams->pIn2;
    // pointer for Scratch1 and Scratch2 and Scratch3 buffers
    bbx_vecN_2xc24 * pScratch1 =(bbx_vecN_2xc24 *)(uintptr_t)fft2realParams->pScratch1Area;
    bbx_vecN_2xc24 * pScratch2 =(bbx_vecN_2xc24 *)(uintptr_t)fft2realParams->pScratch2Area;
    bbx_vecN_2xc24 * pScratch3 =(bbx_vecN_2xc24 *)(uintptr_t)fft2realParams->pScratch3Area;
    // pointer for Window coefficients
    xb_vecNx16 * pWindow = (xb_vecNx16 *)(uintptr_t)fft2realParams->pWindowArea;

    Rsdk_Fft2Real(pOut1,
    		      pOut2,
				  pIn1,
				  pIn2,
				  pScratch1,
				  pScratch2,
                  pScratch3,
				  pTwiddles,
				  pWindow,
                  fft2realParams->size,
                  fft2realParams->shift);
}

void RsdkBbe32Hist(uintptr_t argList)
{
    rsdkBbe32HistParams_t* histParams = ((rsdkBbe32HistParams_t**)argList)[0];
    uint16_t size = histParams->size / 16;
    uint16_t sizeEdges = histParams->sizeEdges / 16;

    Rsdk_Hist((bbx_vecNx24 *)(uintptr_t)histParams->pOut,
              (bbx_vecNx24 *)(uintptr_t)histParams->pIn,
              (bbx_vecNx24 *)(uintptr_t)histParams->pEdges,
                                                    size,
                                                    sizeEdges);
}

void RsdkBbe32ReordTile16to4Ch(uintptr_t argList)
{
	rsdkBbe32ReordTile16to4ChParams_t* cmprParams = ((rsdkBbe32ReordTile16to4ChParams_t **)argList)[0];

	Rsdk_ReordTile16to4Ch((xb_vecNx16 *)(uintptr_t)cmprParams->pOutDat,
						   (xb_vecNx16 *)(uintptr_t)cmprParams->pInDat,
						   cmprParams->doubleInBufEn,
					       cmprParams->noElements / 16U);
}

void RsdkBbe32Doa128(uintptr_t argList)
{
    rsdkBbe32DoaParams_t* doaParams = ((rsdkBbe32DoaParams_t**)argList)[0];
    // pointer for twiddles buffer in DRAM
    xb_vecNx16 * pTwiddles = (xb_vecNx16 *)(uintptr_t)doaParams->pTwiddlesArea;
    // pointer for Scratch1 and Scratch2 buffers in DRAM
    bbx_vecN_2xc24 * pScratch1 =(bbx_vecN_2xc24 *)(uintptr_t)doaParams->pScratch1Area;
    bbx_vecN_2xc24 * pScratch2 =(bbx_vecN_2xc24 *)(uintptr_t)doaParams->pScratch2Area;
    xb_vecNx16 * pWindow = (xb_vecNx16 *)(uintptr_t)doaParams->pWindowArea;

    Rsdk_Doa128((bbx_vecNx24 *)(uintptr_t)doaParams->pOutMag,
                   (uint16_t *)(uintptr_t)doaParams->pDetectBitmap,
                (bbx_vecNx24 *)(uintptr_t)doaParams->pIn,
				                          pScratch1,
										  pScratch2,
			                              pTwiddles,
										  pWindow,
                                          doaParams->thresholdFactor,
                                          doaParams->noAntennas,
                                          doaParams->shift,
                                          doaParams->noPeaks);
}

void RsdkBbe32Doa256(uintptr_t argList)
{
    rsdkBbe32DoaParams_t* doaParams = ((rsdkBbe32DoaParams_t**)argList)[0];
    // pointer for twiddles buffer in DRAM
    xb_vecNx16 * pTwiddles = (xb_vecNx16 *)(uintptr_t)doaParams->pTwiddlesArea;
    // pointer for Scratch1 and Scratch2 buffers in DRAM
    bbx_vecN_2xc24 * pScratch1 =(bbx_vecN_2xc24 *)(uintptr_t)doaParams->pScratch1Area;
    bbx_vecN_2xc24 * pScratch2 =(bbx_vecN_2xc24 *)(uintptr_t)doaParams->pScratch2Area;
    xb_vecNx16 * pWindow = (xb_vecNx16 *)(uintptr_t)doaParams->pWindowArea;
    Rsdk_Doa256((bbx_vecNx24 *)(uintptr_t)doaParams->pOutMag,
                   (uint16_t *)(uintptr_t)doaParams->pDetectBitmap,
                (bbx_vecNx24 *)(uintptr_t)doaParams->pIn,
                                          pScratch1,
				                          pScratch2,
			                              pTwiddles,
										  pWindow,
                                          doaParams->thresholdFactor,
                                          doaParams->noAntennas,
                                          doaParams->shift,
                                          doaParams->noPeaks);
}
#ifdef __cplusplus
}
#endif


/*******************************************************************************
 * EOF
 ******************************************************************************/
