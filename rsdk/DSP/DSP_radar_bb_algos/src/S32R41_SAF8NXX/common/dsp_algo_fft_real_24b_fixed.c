/*
 * Copyright 2022-2024 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */


#include "dsp_algo_24b_fixed_functions_s32r41.h"
#include "rsdk_dsp_radar_bb_algos_s32r41.h"








#include <xtensa/tie/xt_FP.h>
#include <xtensa/tie/xt_bben.h>
#include <xtensa/tie/xt_misc.h>
#include <xtensa/tie/radar24.h>

#ifdef __cplusplus
extern "C"{
#endif

// shuffle vector used for reversing
static const int16_t shuffleVector[BBE_SIMD_WIDTH] = {0,1,14,15,12,13,10,11,8,9,6,7,4,5,2,3};

void Rsdk_Reord2RealToCplx(bbx_vecN_2xc24 * __restrict pOut,
		                       xb_vecNx16 * __restrict pIn1,
							   xb_vecNx16 * __restrict pIn2,
                                              uint16_t size)
{
	xb_vecNx16 * __restrict pVx1 = (xb_vecNx16 * __restrict)(uintptr_t)pIn1;
	xb_vecNx16 * __restrict pVx2 = (xb_vecNx16 * __restrict)(uintptr_t)pIn2;
    bbx_vecNx24 * __restrict pVz = (bbx_vecNx24 * __restrict)(uintptr_t)pOut;
    xb_vecNx16 Vz0, Vz1, Vz2, Vz3;
    bbx_vecNx24 Vx2, Vx3;

    vsaN shift_24b = BBE_MOVVSA32(8);


    uint32_t i;

    // combine the 2 real input data in 1 complex data: (X1, X2) -> (real, imag)
    for (i = 0U; i < size / BBE_SIMD_WIDTH; i++)
    {
        BBE_LVNX16_IP(Vz0, pVx1, 32);
        BBE_LVNX16_IP(Vz1, pVx2, 32);
        BBE_DSELNX16I(Vz3, Vz2, Vz1, Vz0, BBE_DSELI_INTERLEAVE_1);




        Vx2 = BBX_MOVN2L(Vz2);
        Vx2 = BBX_SLLSNX24(Vx2, shift_24b);
        Vx3 = BBX_MOVN2L(Vz3);
        Vx3 = BBX_SLLSNX24(Vx3, shift_24b);

        BBX_SVNX24_IP(Vx2, pVz, 64);
        BBX_SVNX24_IP(Vx3, pVz, 64);
    }
}
void Rsdk_SplitFftCplxto2Cplx(bbx_vecN_2xc24 * __restrict pOut1,
                              bbx_vecN_2xc24 * __restrict pOut2,
                                 bbx_vecNx24 * __restrict pIn,
                                                 uint16_t size)
{
    bbx_vecN_2xc24 * __restrict pVcX1 = pOut1;
    bbx_vecN_2xc24 * __restrict pVcX2 = pOut2;
    // position first pointer to Z(0)
    bbx_vecN_2xc24 * __restrict pVcZ = pIn;
    bbx_vecN_2xc24 VcTmp1, VcTmp2;
    bbx_vecNx24 * __restrict pVz = (bbx_vecNx24 * __restrict)(uintptr_t)pIn;
    bbx_vecNx24 Vz0, Vz1, Vz2;
    xb_vecNx16 * __restrict pShuffleVector = (xb_vecNx16 * __restrict)(uintptr_t)&shuffleVector;
    vsaN selectShuffle = BBE_MOVVSV(*pShuffleVector, 0);
    uint32_t i;
    /* mask is for selecting the first complex number(1100000000000000)
       mask2 is to select only imaginary elements(1010101010101010)
    */
    uint16_t mask = 3, mask2 = 43690;
    vboolN * maskBool, *maskBool2;
    //Load for shift right with 1 (divide by 2)
    WUR_bbx_ur_fft_states(5 << 8);
    // move 0 to SA register as is it not required
    BBX_MOVL2SA((bbx_vecNx24)0);

    // 2^23 - 1
    maskBool = (vboolN *)&mask;
    maskBool2 = (vboolN *)&mask2;

    // load the Z(N + 1) which is the same as Z(0) then position to Z(N) for the first operation
    BBX_LVNX24_XP(Vz0, pVz, 64 * ((2 * size / BBE_SIMD_WIDTH) - 1));
    // obtain the FFTs for the 2 input real data by separating the obtained combined FFT
    // formula used: X1 eq (Z(i) + Z*(N-i)) / 2 and X2 eq j * (Z*(N-i) - Z(i)) / 2
    // where Z*(i) represents the complex conjugate of Z(i)
    for (i = 0U; i < size / BBE_SIMD_WIDTH; i++)
    {
        // reverse the obtained combined FFT Z(n) to obtain Z(N-i)
        Vz1 = BBX_MOVL2L(Vz0);
        BBX_LVNX24_XP(Vz0, pVz, -64);
        Vz2 = BBX_SHFNX24(Vz0, selectShuffle);
        BBX_MOVL2LCT(Vz2, Vz1, *maskBool);
        BBX_LVNX24_IP((bbx_vecN_2xc24)Vz1, pVcZ, 64);
        // move element in SB register for future operation
        BBX_MOVL2SB(Vz1);
        // conjugate Z(N-i) to obtain Z*(N-i)
        BBX_NEGNX24T(Vz2, Vz2, *maskBool2);
        // separate the FFT
        // X1 eq (Z(i) + Z*(N-i)) / 2
        VcTmp1 = BBX_FFTADD4SABNX24(Vz2, (bbx_vecNx24)0, 0, 0);
        BBX_SVNX24_IP(VcTmp1, pVcX1, 64);
        // X2 eq j * (Z*(N-i) - Z(i)) / 2
        VcTmp2 = BBX_FFTADD4SABNX24((bbx_vecNx24)0, Vz2, 1, 0);
        BBX_SVNX24_IP(VcTmp2, pVcX2, 64);
    }
}

void Rsdk_Fft2Real(bbx_vecNx24 * __restrict pOut1,
		           bbx_vecNx24 * __restrict pOut2,
		            xb_vecNx16 * __restrict pIn1,
		            xb_vecNx16 * __restrict pIn2,
	            bbx_vecN_2xc24 * __restrict pScratch1,
                bbx_vecN_2xc24 * __restrict pScratch2,
                bbx_vecN_2xc24 * __restrict pScratch3,
                    xb_vecNx16 * __restrict pTwiddles,
                    xb_vecNx16 * __restrict pWindow,
                                   uint16_t size,
                                   uint16_t shift)
{
    // reorder 2 real signal into 1 complex signal
    Rsdk_Reord2RealToCplx(pScratch3, pIn1, pIn2, size);
    // call the complex FFT kernel based on size
    Rsdk_FftCplx(pScratch3, pScratch1, pScratch2, pTwiddles, pWindow, shift, size);
    // separatet the combined complex fft into 2 complex ffts
    Rsdk_SplitFftCplxto2Cplx(pOut1, pOut2, pScratch3, size);
}

#ifdef __cplusplus
}
#endif

/*******************************************************************************
* EOF
******************************************************************************/

