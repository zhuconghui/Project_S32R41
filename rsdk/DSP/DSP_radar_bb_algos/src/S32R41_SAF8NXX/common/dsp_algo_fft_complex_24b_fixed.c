/*
 * Copyright 2024 NXP
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







#include <stdint.h>
#include <xtensa/tie/xt_FP.h>
#include <xtensa/tie/xt_bben.h>
#include <xtensa/tie/xt_misc.h>
#include <xtensa/tie/radar24.h>

#ifdef __cplusplus
extern "C"{
#endif

void Rsdk_FftCplx(bbx_vecN_2xc24 * __restrict pInOut,
                  bbx_vecN_2xc24 * __restrict pScratch1,
                  bbx_vecN_2xc24 * __restrict pScratch2,
                      xb_vecNx16 * __restrict pTwiddles,
                      xb_vecNx16 * __restrict pWindow,
                          uint16_t shift,
                          uint16_t size)
{
    bbx_vecNx24  a0, a1, a2, a3, a4, a5, a6, a7;           //Butterfly inputs
    bbx_vecNx24  b0, b1, b2, b3, b4, b5, b6, b7;           //Butterfly outputs
    bbx_vecNx24  tw0, tw1, tw2, tw3, tw5, tw6, tw7;        //Twiddles for multiplication
    bbx_vecNx24  ww0, ww1, ww2, ww3, ww4, ww5, ww6, ww7;        //Window for multiplication
    bbx_vecNx24  tmp_a0, tmp_a1, tmp_a2, tmp_a3, tmp_a4, tmp_a5, tmp_a6, tmp_a7;       //Auxiliary variables for permutations
    // Input/output and scratch memory pointers
    bbx_vecNx24 *__restrict p_vout = (bbx_vecNx24 * __restrict) ((uintptr_t)&pScratch1[0]);
    bbx_vecNx24 *__restrict p_vin = (bbx_vecNx24 * __restrict) ((uintptr_t)&pInOut[0]);
    bbx_vecNx24 *p_a0, *p_a1, *p_a2, *p_a3;
    bbx_vecNx24 *p_b0, *p_b1, *p_b2, *p_b3;
    bbx_vecNx24 windowCoef;
    bbx_vecNx24 zeroVal = (bbx_vecNx24)0;
    //Twiddle pointer
    xb_vecNx16 *__restrict p_vtw0 = pTwiddles;
    // Window pointer
    xb_vecNx16 *__restrict p_wiow = pWindow;
    xb_vecNx16 tmpTwiddle;
    xb_vecNx16 tmpWindow;


    vsaN shift_24b = BBE_MOVVSA32(8);

    //Loop counters
    uint32_t i, j;
    uint32_t sizeFactor = size / 128U;

    //Load state vector
    WUR_bbx_ur_fft_states(shift << 8);
    // Stage 1, common to all ffts
    // Initialize input pointers
    p_a0    = &p_vin[0U * sizeFactor];
    p_a1    = &p_vin[4U * sizeFactor];
    p_a2    = &p_vin[8U * sizeFactor];
    p_a3    = &p_vin[12U * sizeFactor];
    // Initialize output pointers
    p_b0    = &p_vout[0U * sizeFactor];
    p_b1    = &p_vout[4U * sizeFactor];
    p_b2    = &p_vout[8U * sizeFactor];
    p_b3    = &p_vout[12U * sizeFactor];
    BBX_MOVI2S0(BBE_DSELI_INTERLEAVE_1);
    BBX_MOVI2S1(BBE_DSELI_INTERLEAVE_1);
    #pragma loop_count min = 1
    for (i = 0U ; i < 1 * sizeFactor; i++)
    {
        // Load vectors
        BBX_LVNX24_IP(a0, p_a0, 64);
        BBX_LVNX24_IP(a1, p_a1, 64);
        BBX_LVNX24_IP(a2, p_a2, 64);
        BBX_LVNX24_IP(a3, p_a3, 64);
        // Load window coefficients and move from q0.16 to q0.24
        BBE_LVNX16_IP(tmpWindow, p_wiow, 32);

        windowCoef = BBX_MOVN2L(tmpWindow);
        windowCoef = BBX_SLLSNX24(windowCoef, shift_24b);



        BBX_DSELNX24S0(ww1, ww0, zeroVal, windowCoef);
        BBE_LVNX16_IP(tmpWindow, p_wiow, 32);

        windowCoef = BBX_MOVN2L(tmpWindow);
        windowCoef = BBX_SLLSNX24(windowCoef, shift_24b);



        BBX_DSELNX24S0(ww3, ww2, zeroVal, windowCoef);
        // Multiply with window
        a0 = BBX_FFTMULNX24CPACKQ(a0, ww0);
        a1 = BBX_FFTMULNX24CPACKQ(a1, ww1);
        a2 = BBX_FFTMULNX24CPACKQ(a2, ww2);
        a3 = BBX_FFTMULNX24CPACKQ(a3, ww3);
        BBX_MOVL2SA(a2);
        BBX_MOVL2SB(a3);
        // Operator
        b0 = BBX_FFTADD4SABNX24(a0, a1, 0, 0);
        b1 = BBX_FFTADD4SABNX24(a0, a1, 3, 0);
        b2 = BBX_FFTADD4SABNX24(a0, a1, 2, 0);
        b3 = BBX_FFTADD4SABNX24(a0, a1, 1, 0);
        //Store vectors
        BBX_SVNX24_IP(b0, p_b0, 64);
        BBX_SVNX24_IP(b1, p_b1, 64);
        BBX_SVNX24_IP(b2, p_b2, 64);
        BBX_SVNX24_IP(b3, p_b3, 64);

        // Load vectors
        BBX_LVNX24_IP(a4, p_a0, 64);
        BBX_LVNX24_IP(a5, p_a1, 64);
        BBX_LVNX24_IP(a6, p_a2, 64);
        BBX_LVNX24_IP(a7, p_a3, 64);

        // Load window coefficients and move from q0.16 to q0.24
        BBE_LVNX16_IP(tmpWindow, p_wiow, 32);

        windowCoef = BBX_MOVN2L(tmpWindow);
        windowCoef = BBX_SLLSNX24(windowCoef, shift_24b);



        BBX_DSELNX24S1(ww5, ww4, zeroVal, windowCoef);

        BBE_LVNX16_IP(tmpWindow, p_wiow, 32);

        windowCoef = BBX_MOVN2L(tmpWindow);
        windowCoef = BBX_SLLSNX24(windowCoef, shift_24b);



        BBX_DSELNX24S1(ww7, ww6, zeroVal, windowCoef);
        // Multiply wind window
        a4 = BBX_FFTMULNX24CPACKQ(a4, ww4);
        a5 = BBX_FFTMULNX24CPACKQ(a5, ww5);
        a6 = BBX_FFTMULNX24CPACKQ(a6, ww6);
        a7 = BBX_FFTMULNX24CPACKQ(a7, ww7);
        BBX_MOVL2SC(a6);
        BBX_MOVL2SD(a7);
        // Operator
        b4 = BBX_FFTADD4SCDNX24(a4, a5, 0, 0);
        b5 = BBX_FFTADD4SCDNX24(a4, a5, 3, 0);
        b6 = BBX_FFTADD4SCDNX24(a4, a5, 2, 0);
        b7 = BBX_FFTADD4SCDNX24(a4, a5, 1, 0);
        // Store vectors
        BBX_SVNX24_IP(b4, p_b0, 64);
        BBX_SVNX24_IP(b5, p_b1, 64);
        BBX_SVNX24_IP(b6, p_b2, 64);
        BBX_SVNX24_IP(b7, p_b3, 64);
    }
BBE_LVNX16_IP(tmpWindow, p_wiow, -32);
#pragma loop_count min = 1
for (i = 0U ; i < 1 * sizeFactor; i++)
{
    // Load vectors
    BBX_LVNX24_IP(a0, p_a0, 64);
    BBX_LVNX24_IP(a1, p_a1, 64);
    BBX_LVNX24_IP(a2, p_a2, 64);
    BBX_LVNX24_IP(a3, p_a3, 64);
    // Load window coefficients and move from q0.16 to q0.24
    BBE_LVNX16_IP(tmpWindow, p_wiow, -32);
    tmpWindow = BBE_SHFLNX16I(tmpWindow, BBE_SHFLI_REVERSE_1);

    windowCoef = BBX_MOVN2L(tmpWindow);
    windowCoef = BBX_SLLSNX24(windowCoef, shift_24b);



    BBX_DSELNX24S0(ww1, ww0, zeroVal, windowCoef);
    BBE_LVNX16_IP(tmpWindow, p_wiow, -32);
    tmpWindow = BBE_SHFLNX16I(tmpWindow, BBE_SHFLI_REVERSE_1);

    windowCoef = BBX_MOVN2L(tmpWindow);
    windowCoef = BBX_SLLSNX24(windowCoef, shift_24b);



    BBX_DSELNX24S0(ww3, ww2, zeroVal, windowCoef);
    // Multiply with window
    a0 = BBX_FFTMULNX24CPACKQ(a0, ww0);
    a1 = BBX_FFTMULNX24CPACKQ(a1, ww1);
    a2 = BBX_FFTMULNX24CPACKQ(a2, ww2);
    a3 = BBX_FFTMULNX24CPACKQ(a3, ww3);
    BBX_MOVL2SA(a2);
    BBX_MOVL2SB(a3);
    // Operator
    b0 = BBX_FFTADD4SABNX24(a0, a1, 0, 0);
    b1 = BBX_FFTADD4SABNX24(a0, a1, 3, 0);
    b2 = BBX_FFTADD4SABNX24(a0, a1, 2, 0);
    b3 = BBX_FFTADD4SABNX24(a0, a1, 1, 0);
    //Store vectors
    BBX_SVNX24_IP(b0, p_b0, 64);
    BBX_SVNX24_IP(b1, p_b1, 64);
    BBX_SVNX24_IP(b2, p_b2, 64);
    BBX_SVNX24_IP(b3, p_b3, 64);

    // Load vectors
    BBX_LVNX24_IP(a4, p_a0, 64);
    BBX_LVNX24_IP(a5, p_a1, 64);
    BBX_LVNX24_IP(a6, p_a2, 64);
    BBX_LVNX24_IP(a7, p_a3, 64);

    // Load window coefficients and move from q0.16 to q0.24
    BBE_LVNX16_IP(tmpWindow, p_wiow, -32);
    tmpWindow = BBE_SHFLNX16I(tmpWindow, BBE_SHFLI_REVERSE_1);

    windowCoef = BBX_MOVN2L(tmpWindow);
    windowCoef = BBX_SLLSNX24(windowCoef, shift_24b);



    BBX_DSELNX24S1(ww5, ww4, zeroVal, windowCoef);

    BBE_LVNX16_IP(tmpWindow, p_wiow, -32);
    tmpWindow = BBE_SHFLNX16I(tmpWindow, BBE_SHFLI_REVERSE_1);

    windowCoef = BBX_MOVN2L(tmpWindow);
    windowCoef = BBX_SLLSNX24(windowCoef, shift_24b);



    BBX_DSELNX24S1(ww7, ww6, zeroVal, windowCoef);
    // Multiply wind window
    a4 = BBX_FFTMULNX24CPACKQ(a4, ww4);
    a5 = BBX_FFTMULNX24CPACKQ(a5, ww5);
    a6 = BBX_FFTMULNX24CPACKQ(a6, ww6);
    a7 = BBX_FFTMULNX24CPACKQ(a7, ww7);
    BBX_MOVL2SC(a6);
    BBX_MOVL2SD(a7);
    // Operator
    b4 = BBX_FFTADD4SCDNX24(a4, a5, 0, 0);
    b5 = BBX_FFTADD4SCDNX24(a4, a5, 3, 0);
    b6 = BBX_FFTADD4SCDNX24(a4, a5, 2, 0);
    b7 = BBX_FFTADD4SCDNX24(a4, a5, 1, 0);
    // Store vectors
    BBX_SVNX24_IP(b4, p_b0, 64);
    BBX_SVNX24_IP(b5, p_b1, 64);
    BBX_SVNX24_IP(b6, p_b2, 64);
    BBX_SVNX24_IP(b7, p_b3, 64);
}
    // fft 128
    if (size == RSDK_BBE32_FFT_SIZE_128)
    {
        // Stage 2
        p_vout = (bbx_vecNx24 * __restrict) ((uintptr_t)&pScratch2[0]);
        p_vin  = (bbx_vecNx24 * __restrict) ((uintptr_t)&pScratch1[0]);
        //Initialize input pointers
        p_a0    = &p_vin[0];
        p_a1    = &p_vin[1];
        p_a2    = &p_vin[2];
        p_a3    = &p_vin[3];
        //Initialize output pointers
        p_b0    = &p_vout[0];
        p_b1    = &p_vout[4];
        p_b2    = &p_vout[8];
        p_b3    = &p_vout[12];
        //Load fixed select register
#  pragma no_reorder
{
        for (i=0 ; i <2 ; i++)
        {
            //Load vectors
            BBX_LVNX24_IP(a0, p_a0, 64*4);
            BBX_LVNX24_IP(a1, p_a1, 64*4);
            BBX_LVNX24_IP(a2, p_a2, 64*4);
            BBX_LVNX24_IP(a3, p_a3, 64*4);
            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw0 = BBX_MOVN2L(tmpTwiddle);
            tw0 = BBX_SLLSNX24(tw0, shift_24b);



            tw1  = BBX_REPNX24C(tw0, 0);
            tw2  = BBX_REPNX24C(tw0, 1);
            tw3  = BBX_REPNX24C(tw0, 2);
            a1 = BBX_FFTMULNX24CPACKQ(a1, tw1);
            a2 = BBX_FFTMULNX24CPACKQ(a2, tw2);
            a3 = BBX_FFTMULNX24CPACKQ(a3, tw3);
            //Operator
            BBX_MOVL2SA(a2);
            BBX_MOVL2SB(a3);
            b0 = BBX_FFTADD4SABNX24(a0, a1, 0, 0);
            b1 = BBX_FFTADD4SABNX24(a0, a1, 3, 0);
            b2 = BBX_FFTADD4SABNX24(a0, a1, 2, 0);
            b3 = BBX_FFTADD4SABNX24(a0, a1, 1, 0);
            //Store vectors
            BBX_SVNX24_IP(b0, p_b0, 64);
            BBX_SVNX24_IP(b1, p_b1, 64);
            BBX_SVNX24_IP(b2, p_b2, 64);
            BBX_SVNX24_IP(b3, p_b3, 64);

            //Load vectors
            BBX_LVNX24_IP(a4, p_a0, 64*4);
            BBX_LVNX24_IP(a5, p_a1, 64*4);
            BBX_LVNX24_IP(a6, p_a2, 64*4);
            BBX_LVNX24_IP(a7, p_a3, 64*4);
            //Twiddles
            tw5  = BBX_REPNX24C(tw0, 3);
            tw6  = BBX_REPNX24C(tw0, 4);
            tw7  = BBX_REPNX24C(tw0, 5);
            a5 = BBX_FFTMULNX24CPACKQ(a5, tw5);
            a6 = BBX_FFTMULNX24CPACKQ(a6, tw6);
            a7 = BBX_FFTMULNX24CPACKQ(a7, tw7);
            //Operator
            BBX_MOVL2SC(a6);
            BBX_MOVL2SD(a7);
            b4 = BBX_FFTADD4SCDNX24(a4, a5, 0, 0);
            b5 = BBX_FFTADD4SCDNX24(a4, a5, 3, 0);
            b6 = BBX_FFTADD4SCDNX24(a4, a5, 2, 0);
            b7 = BBX_FFTADD4SCDNX24(a4, a5, 1, 0);
            //Store vectors
            BBX_SVNX24_IP(b4, p_b0, 64);
            BBX_SVNX24_IP(b5, p_b1, 64);
            BBX_SVNX24_IP(b6, p_b2, 64);
            BBX_SVNX24_IP(b7, p_b3, 64);

        }
}
#  pragma no_reorder
{
        // Stage 3
        p_vout = (bbx_vecNx24 * __restrict) ((uintptr_t)&pScratch1[0]);
        p_vin  = (bbx_vecNx24 * __restrict) ((uintptr_t)&pScratch2[0]);
        //Initialize input pointers
        p_a0    = &p_vin[0];
        p_a1    = &p_vin[1];
        p_a2    = &p_vin[2];
        p_a3    = &p_vin[3];
        //Initialize output pointers
        p_b0    = &p_vout[0];
        p_b1    = &p_vout[4];
        p_b2    = &p_vout[8];
        p_b3    = &p_vout[12];
        //Load fixed select register
        BBX_MOVI2S0(BBE_DSELI_INTERLEAVE_4);
        for (i=0 ; i <2 ; i++)
        {
            //Load vectors
            BBX_LVNX24_IP(a0, p_a0, 64*4);
            BBX_LVNX24_IP(a1, p_a1, 64*4);
            BBX_LVNX24_IP(a2, p_a2, 64*4);
            BBX_LVNX24_IP(a3, p_a3, 64*4);
            //Local permutations
            BBX_DSELNX24S0(a1, a0, a1, a0);
            BBX_DSELNX24S0(a3, a2, a3, a2);
            BBX_MOVI2S1(BBE_SELI_EXTRACT_LO_HALVES);
            tmp_a0 = BBX_SELNX24S1(a2, a0);
            tmp_a2 = BBX_SELNX24S1(a3, a1);
            BBX_MOVI2S1(BBE_SELI_EXTRACT_HI_HALVES);
            tmp_a1 = BBX_SELNX24S1(a2, a0);
            tmp_a3 = BBX_SELNX24S1(a3, a1);
            a0 = tmp_a0;
            a1 = tmp_a1;
            a2 = tmp_a2;
            a3 = tmp_a3;
            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw1 = BBX_MOVN2L(tmpTwiddle);
            tw1 = BBX_SLLSNX24(tw1, shift_24b);



            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw2 = BBX_MOVN2L(tmpTwiddle);
            tw2 = BBX_SLLSNX24(tw2, shift_24b);




            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw3 = BBX_MOVN2L(tmpTwiddle);
            tw3 = BBX_SLLSNX24(tw3, shift_24b);



            a1 = BBX_FFTMULNX24CPACKQ(a1, tw1);
            a2 = BBX_FFTMULNX24CPACKQ(a2, tw2);
            a3 = BBX_FFTMULNX24CPACKQ(a3, tw3);
            //Operator
            BBX_MOVL2SA(a2);
            BBX_MOVL2SB(a3);
            b0 = BBX_FFTADD4SABNX24(a0, a1, 0, 0);
            b1 = BBX_FFTADD4SABNX24(a0, a1, 3, 0);
            b2 = BBX_FFTADD4SABNX24(a0, a1, 2, 0);
            b3 = BBX_FFTADD4SABNX24(a0, a1, 1, 0);
            //Store vectors
            BBX_SVNX24_IP(b0, p_b0, 64);
            BBX_SVNX24_IP(b1, p_b1, 64);
            BBX_SVNX24_IP(b2, p_b2, 64);
            BBX_SVNX24_IP(b3, p_b3, 64);

            //Load vectors
            BBX_LVNX24_IP(a4, p_a0, 64*4);
            BBX_LVNX24_IP(a5, p_a1, 64*4);
            BBX_LVNX24_IP(a6, p_a2, 64*4);
            BBX_LVNX24_IP(a7, p_a3, 64*4);
            //Local permutations
            BBX_DSELNX24S0(a5, a4, a5, a4);
            BBX_DSELNX24S0(a7, a6, a7, a6);
            BBX_MOVI2S1(BBE_SELI_EXTRACT_LO_HALVES);
            tmp_a4 = BBX_SELNX24S1(a6, a4);
            tmp_a6 = BBX_SELNX24S1(a7, a5);
            BBX_MOVI2S1(BBE_SELI_EXTRACT_HI_HALVES);
            tmp_a5 = BBX_SELNX24S1(a6, a4);
            tmp_a7 = BBX_SELNX24S1(a7, a5);
            a4 = tmp_a4;
            a5 = tmp_a5;
            a6 = tmp_a6;
            a7 = tmp_a7;
            //Twiddles
            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw5 = BBX_MOVN2L(tmpTwiddle);
            tw5 = BBX_SLLSNX24(tw5, shift_24b);



            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw6 = BBX_MOVN2L(tmpTwiddle);
            tw6 = BBX_SLLSNX24(tw6, shift_24b);



            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw7 = BBX_MOVN2L(tmpTwiddle);
            tw7 = BBX_SLLSNX24(tw7, shift_24b);



            a5 = BBX_FFTMULNX24CPACKQ(a5, tw5);
            a6 = BBX_FFTMULNX24CPACKQ(a6, tw6);
            a7 = BBX_FFTMULNX24CPACKQ(a7, tw7);
            //Operator
            BBX_MOVL2SC(a6);
            BBX_MOVL2SD(a7);
            b4 = BBX_FFTADD4SCDNX24(a4, a5, 0, 0);
            b5 = BBX_FFTADD4SCDNX24(a4, a5, 3, 0);
            b6 = BBX_FFTADD4SCDNX24(a4, a5, 2, 0);
            b7 = BBX_FFTADD4SCDNX24(a4, a5, 1, 0);
            //Store vectors
            BBX_SVNX24_IP(b4, p_b0, 64);
            BBX_SVNX24_IP(b5, p_b1, 64);
            BBX_SVNX24_IP(b6, p_b2, 64);
            BBX_SVNX24_IP(b7, p_b3, 64);

        }
}
        // Stage 4
        p_vout = (bbx_vecNx24 * __restrict) ((uintptr_t)&pInOut[0]);
        p_vin  = (bbx_vecNx24 * __restrict) ((uintptr_t)&pScratch1[0]);
        // Reset A,B,C,D registers for last radix-2 stage
        BBX_MOVL2SA(0);
        BBX_MOVL2SB(0);
        BBX_MOVL2SC(0);
        BBX_MOVL2SD(0);
        //Initialize input pointers
        p_a0    = &p_vin[0];
        p_a1    = &p_vin[1];
        //Initialize output pointers
        p_b0    = &p_vout[0];
        p_b1    = &p_vout[8];
        //Load fixed select registers
        BBX_MOVI2S0(BBE_DSELI_DEINTERLEAVE_2);
        BBX_MOVI2S1(BBE_DSELI_DEINTERLEAVE_2);
#  pragma no_reorder
{
        for (i=0 ; i <4 ; i++)
        {
            //Load vectors
            BBX_LVNX24_IP(a0, p_a0, 64*2);
            BBX_LVNX24_IP(a1, p_a1, 64*2);
            //Local permutations
            BBX_DSELNX24S0(a1, a0, a1, a0);
            //Twiddles
            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw1 = BBX_MOVN2L(tmpTwiddle);
            tw1 = BBX_SLLSNX24(tw1, shift_24b);



            a1 = BBX_FFTMULNX24CPACKQ(a1, tw1);
            //Operator
            b0 = BBX_FFTADD4SABNX24(a0, a1, 0, 0);
            b1 = BBX_FFTADD4SABNX24(a0, a1, 2, 0);
            //Store vectors
            BBX_SVNX24_IP(b0, p_b0, 64);
            BBX_SVNX24_IP(b1, p_b1, 64);

            //Load vectors
            BBX_LVNX24_IP(a4, p_a0, 64*2);
            BBX_LVNX24_IP(a5, p_a1, 64*2);
            //Local permutations
            BBX_DSELNX24S1(a5, a4, a5, a4);
            //Twiddles
            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw5 = BBX_MOVN2L(tmpTwiddle);
            tw5 = BBX_SLLSNX24(tw5, shift_24b);



            a5 = BBX_FFTMULNX24CPACKQ(a5, tw5);
            //Operator
            b4 = BBX_FFTADD4SCDNX24(a4, a5, 0, 0);
            b5 = BBX_FFTADD4SCDNX24(a4, a5, 2, 0);
            //Store vectors
            BBX_SVNX24_IP(b4, p_b0, 64);
            BBX_SVNX24_IP(b5, p_b1, 64);
        }
}
    // fft 256
    } else if (size == RSDK_BBE32_FFT_SIZE_256)
    {
        // Stage 2
        p_vout =  (bbx_vecNx24 * __restrict) ((uintptr_t)&pScratch2[0]);
        p_vin  = (bbx_vecNx24 * __restrict) ((uintptr_t)&pScratch1[0]);
        // Initialize output pointers
        p_b0    = &p_vout[0];
        p_b1    = &p_vout[8];
        p_b2    = &p_vout[16];
        p_b3    = &p_vout[24];
        for (j = 0 ; j < 4 ; j++)
        {
            // Initialize input pointers
            p_a0    = &p_vin[j*8];
            p_a1    = &p_vin[j*8 + 1*2];
            p_a2    = &p_vin[j*8 + 2*2];
            p_a3    = &p_vin[j*8 + 3*2];
            for (i = 0 ; i < 1 ; i++)
            {
                // Load vectors
                BBX_LVNX24_IP(a0, p_a0, 64);
                BBX_LVNX24_IP(a1, p_a1, 64);
                BBX_LVNX24_IP(a2, p_a2, 64);
                BBX_LVNX24_IP(a3, p_a3, 64);
                // Twiddles
                BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

                tw0 = BBX_MOVN2L(tmpTwiddle);
                tw0 = BBX_SLLSNX24(tw0, shift_24b);



                tw1  = BBX_REPNX24C(tw0, 0);
                tw2  = BBX_REPNX24C(tw0, 1);
                tw3  = BBX_REPNX24C(tw0, 2);
                a1 = BBX_FFTMULNX24CPACKQ(a1, tw1);
                a2 = BBX_FFTMULNX24CPACKQ(a2, tw2);
                a3 = BBX_FFTMULNX24CPACKQ(a3, tw3);
                // Operator
                BBX_MOVL2SA(a2);
                BBX_MOVL2SB(a3);
                b0 = BBX_FFTADD4SABNX24(a0, a1, 0, 0);
                b1 = BBX_FFTADD4SABNX24(a0, a1, 3, 0);
                b2 = BBX_FFTADD4SABNX24(a0, a1, 2, 0);
                b3 = BBX_FFTADD4SABNX24(a0, a1, 1, 0);
                // Store vectors
                BBX_SVNX24_IP(b0, p_b0, 64);
                BBX_SVNX24_IP(b1, p_b1, 64);
                BBX_SVNX24_IP(b2, p_b2, 64);
                BBX_SVNX24_IP(b3, p_b3, 64);

                // Load vectors
                BBX_LVNX24_IP(a4, p_a0, 64);
                BBX_LVNX24_IP(a5, p_a1, 64);
                BBX_LVNX24_IP(a6, p_a2, 64);
                BBX_LVNX24_IP(a7, p_a3, 64);
                // Twiddles
                tw5  = BBX_REPNX24C(tw0, 3);
                tw6  = BBX_REPNX24C(tw0, 4);
                tw7  = BBX_REPNX24C(tw0, 5);
                a5 = BBX_FFTMULNX24CPACKQ(a5, tw5);
                a6 = BBX_FFTMULNX24CPACKQ(a6, tw6);
                a7 = BBX_FFTMULNX24CPACKQ(a7, tw7);
                // Operator
                BBX_MOVL2SC(a6);
                BBX_MOVL2SD(a7);
                b4 = BBX_FFTADD4SCDNX24(a4, a5, 0, 0);
                b5 = BBX_FFTADD4SCDNX24(a4, a5, 3, 0);
                b6 = BBX_FFTADD4SCDNX24(a4, a5, 2, 0);
                b7 = BBX_FFTADD4SCDNX24(a4, a5, 1, 0);
                // Store vectors
                BBX_SVNX24_IP(b4, p_b0, 64);
                BBX_SVNX24_IP(b5, p_b1, 64);
                BBX_SVNX24_IP(b6, p_b2, 64);
                BBX_SVNX24_IP(b7, p_b3, 64);
            }
        }

        // Stage 3
        p_vout =  (bbx_vecNx24 * __restrict) ((uintptr_t)&pScratch1[0]);
        p_vin  = (bbx_vecNx24 * __restrict) ((uintptr_t)&pScratch2[0]);
        // Initialize input pointers
        p_a0    = &p_vin[0];
        p_a1    = &p_vin[1];
        p_a2    = &p_vin[2];
        p_a3    = &p_vin[3];
        // Initialize output pointers
        p_b0    = &p_vout[0];
        p_b1    = &p_vout[8];
        p_b2    = &p_vout[16];
        p_b3    = &p_vout[24];
        // Load fixed select register
        BBX_MOVI2S0(BBE_SELI_EXTRACT_LO_HALVES);
        BBX_MOVI2S1(BBE_SELI_EXTRACT_HI_HALVES);
        for (i = 0 ; i < 4 ; i++)
        {
            // Load vectors
            BBX_LVNX24_IP(a0, p_a0, 64*4);
            BBX_LVNX24_IP(a1, p_a1, 64*4);
            BBX_LVNX24_IP(a2, p_a2, 64*4);
            BBX_LVNX24_IP(a3, p_a3, 64*4);
            // Local permutations
            tmp_a0 = BBX_SELNX24S0(a2, a0);
            tmp_a1 = BBX_SELNX24S1(a2, a0);
            tmp_a2 = BBX_SELNX24S0(a3, a1);
            tmp_a3 = BBX_SELNX24S1(a3, a1);
            a0 = tmp_a0;
            a1 = tmp_a1;
            a2 = tmp_a2;
            a3 = tmp_a3;
            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw1 = BBX_MOVN2L(tmpTwiddle);
            tw1 = BBX_SLLSNX24(tw1, shift_24b);



            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw2 = BBX_MOVN2L(tmpTwiddle);
            tw2 = BBX_SLLSNX24(tw2, shift_24b);



            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw3 = BBX_MOVN2L(tmpTwiddle);
            tw3 = BBX_SLLSNX24(tw3, shift_24b);



            a1 = BBX_FFTMULNX24CPACKQ(a1, tw1);
            a2 = BBX_FFTMULNX24CPACKQ(a2, tw2);
            a3 = BBX_FFTMULNX24CPACKQ(a3, tw3);
            // Operator
            BBX_MOVL2SA(a2);
            BBX_MOVL2SB(a3);
            b0 = BBX_FFTADD4SABNX24(a0, a1, 0, 0);
            b1 = BBX_FFTADD4SABNX24(a0, a1, 3, 0);
            b2 = BBX_FFTADD4SABNX24(a0, a1, 2, 0);
            b3 = BBX_FFTADD4SABNX24(a0, a1, 1, 0);
            // Store vectors
            BBX_SVNX24_IP(b0, p_b0, 64);
            BBX_SVNX24_IP(b1, p_b1, 64);
            BBX_SVNX24_IP(b2, p_b2, 64);
            BBX_SVNX24_IP(b3, p_b3, 64);

            // Load vectors
            BBX_LVNX24_IP(a4, p_a0, 64*4);
            BBX_LVNX24_IP(a5, p_a1, 64*4);
            BBX_LVNX24_IP(a6, p_a2, 64*4);
            BBX_LVNX24_IP(a7, p_a3, 64*4);
            // Local permutations
            tmp_a4 = BBX_SELNX24S0(a6, a4);
            tmp_a5 = BBX_SELNX24S1(a6, a4);
            tmp_a6 = BBX_SELNX24S0(a7, a5);
            tmp_a7 = BBX_SELNX24S1(a7, a5);
            a4 = tmp_a4;
            a5 = tmp_a5;
            a6 = tmp_a6;
            a7 = tmp_a7;
            // Twiddles
            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw5 = BBX_MOVN2L(tmpTwiddle);
            tw5 = BBX_SLLSNX24(tw5, shift_24b);



            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw6 = BBX_MOVN2L(tmpTwiddle);
            tw6 = BBX_SLLSNX24(tw6, shift_24b);



            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw7 = BBX_MOVN2L(tmpTwiddle);
            tw7 = BBX_SLLSNX24(tw7, shift_24b);



            a5 = BBX_FFTMULNX24CPACKQ(a5, tw5);
            a6 = BBX_FFTMULNX24CPACKQ(a6, tw6);
            a7 = BBX_FFTMULNX24CPACKQ(a7, tw7);
            // Operator
            BBX_MOVL2SC(a6);
            BBX_MOVL2SD(a7);
            b4 = BBX_FFTADD4SCDNX24(a4, a5, 0, 0);
            b5 = BBX_FFTADD4SCDNX24(a4, a5, 3, 0);
            b6 = BBX_FFTADD4SCDNX24(a4, a5, 2, 0);
            b7 = BBX_FFTADD4SCDNX24(a4, a5, 1, 0);
            // Store vectors
            BBX_SVNX24_IP(b4, p_b0, 64);
            BBX_SVNX24_IP(b5, p_b1, 64);
            BBX_SVNX24_IP(b6, p_b2, 64);
            BBX_SVNX24_IP(b7, p_b3, 64);
        }
        // Stage 4
        p_vout =  (bbx_vecNx24 * __restrict) ((uintptr_t)&pInOut[0]);
        p_vin  = (bbx_vecNx24 * __restrict) ((uintptr_t)&pScratch1[0]);
        // Initialize input pointers
        p_a0    = &p_vin[0];
        p_a1    = &p_vin[1];
        p_a2    = &p_vin[2];
        p_a3    = &p_vin[3];
        // Initialize output pointers
        p_b0    = &p_vout[0];
        p_b1    = &p_vout[8];
        p_b2    = &p_vout[16];
        p_b3    = &p_vout[24];
        // Load fixed select register
        BBX_MOVI2S1(BBE_DSELI_DEINTERLEAVE_2);
        for (i = 0 ; i < 4 ; i++)
        {
            // Load vectors
            BBX_LVNX24_IP(a0, p_a0, 64*4);
            BBX_LVNX24_IP(a1, p_a1, 64*4);
            BBX_LVNX24_IP(a2, p_a2, 64*4);
            BBX_LVNX24_IP(a3, p_a3, 64*4);
            // Local permutations
            BBX_MOVI2S0(BBE_SELI_16B_EXTRACT_4_OF_8_OFF_0);
            tmp_a0 = BBX_SELNX24S0(a1, a0);
            tmp_a2 = BBX_SELNX24S0(a3, a2);
            BBX_MOVI2S0(BBE_SELI_16B_EXTRACT_4_OF_8_OFF_4);
            tmp_a1 = BBX_SELNX24S0(a1, a0);
            tmp_a3 = BBX_SELNX24S0(a3, a2);
            BBX_DSELNX24S1(a1, a0, tmp_a2, tmp_a0);
            BBX_DSELNX24S1(a3, a2, tmp_a3, tmp_a1);
            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw1 = BBX_MOVN2L(tmpTwiddle);
            tw1 = BBX_SLLSNX24(tw1, shift_24b);



            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw2 = BBX_MOVN2L(tmpTwiddle);
            tw2 = BBX_SLLSNX24(tw2, shift_24b);



            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw3 = BBX_MOVN2L(tmpTwiddle);
            tw3 = BBX_SLLSNX24(tw3, shift_24b);



            a1 = BBX_FFTMULNX24CPACKQ(a1, tw1);
            a2 = BBX_FFTMULNX24CPACKQ(a2, tw2);
            a3 = BBX_FFTMULNX24CPACKQ(a3, tw3);
            // Operator
            BBX_MOVL2SA(a2);
            BBX_MOVL2SB(a3);
            b0 = BBX_FFTADD4SABNX24(a0, a1, 0, 0);
            b1 = BBX_FFTADD4SABNX24(a0, a1, 3, 0);
            b2 = BBX_FFTADD4SABNX24(a0, a1, 2, 0);
            b3 = BBX_FFTADD4SABNX24(a0, a1, 1, 0);
            // Store vectors
            BBX_SVNX24_IP(b0, p_b0, 64);
            BBX_SVNX24_IP(b1, p_b1, 64);
            BBX_SVNX24_IP(b2, p_b2, 64);
            BBX_SVNX24_IP(b3, p_b3, 64);

            // Load vectors
            BBX_LVNX24_IP(a4, p_a0, 64*4);
            BBX_LVNX24_IP(a5, p_a1, 64*4);
            BBX_LVNX24_IP(a6, p_a2, 64*4);
            BBX_LVNX24_IP(a7, p_a3, 64*4);
            // Local permutations
            BBX_MOVI2S0(BBE_SELI_16B_EXTRACT_4_OF_8_OFF_0);
            tmp_a4 = BBX_SELNX24S0(a5, a4);
            tmp_a6 = BBX_SELNX24S0(a7, a6);
            BBX_MOVI2S0(BBE_SELI_16B_EXTRACT_4_OF_8_OFF_4);
            tmp_a5 = BBX_SELNX24S0(a5, a4);
            tmp_a7 = BBX_SELNX24S0(a7, a6);
            BBX_DSELNX24S1(a5, a4, tmp_a6, tmp_a4);
            BBX_DSELNX24S1(a7, a6, tmp_a7, tmp_a5);
            // Twiddles
            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw5 = BBX_MOVN2L(tmpTwiddle);
            tw5 = BBX_SLLSNX24(tw5, shift_24b);



            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw6 = BBX_MOVN2L(tmpTwiddle);
            tw6 = BBX_SLLSNX24(tw6, shift_24b);



            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw7 = BBX_MOVN2L(tmpTwiddle);
            tw7 = BBX_SLLSNX24(tw7, shift_24b);



            a5 = BBX_FFTMULNX24CPACKQ(a5, tw5);
            a6 = BBX_FFTMULNX24CPACKQ(a6, tw6);
            a7 = BBX_FFTMULNX24CPACKQ(a7, tw7);
            // Operator
            BBX_MOVL2SC(a6);
            BBX_MOVL2SD(a7);
            b4 = BBX_FFTADD4SCDNX24(a4, a5, 0, 0);
            b5 = BBX_FFTADD4SCDNX24(a4, a5, 3, 0);
            b6 = BBX_FFTADD4SCDNX24(a4, a5, 2, 0);
            b7 = BBX_FFTADD4SCDNX24(a4, a5, 1, 0);
            // Store vectors
            BBX_SVNX24_IP(b4, p_b0, 64);
            BBX_SVNX24_IP(b5, p_b1, 64);
            BBX_SVNX24_IP(b6, p_b2, 64);
            BBX_SVNX24_IP(b7, p_b3, 64);
        }
    // fft 512
    } else if (size == RSDK_BBE32_FFT_SIZE_512)
    {
        // Stage 2
        p_vout =  (bbx_vecNx24 * __restrict) ((uintptr_t)&pScratch2[0]);
        p_vin  = (bbx_vecNx24 * __restrict) ((uintptr_t)&pScratch1[0]);
        //Initialize output pointers
        p_b0    = &p_vout[0];
        p_b1    = &p_vout[16];
        p_b2    = &p_vout[32];
        p_b3    = &p_vout[48];
        for (j = 0 ; j < 4 ; j++)
        {
            // Initialize input pointers
            p_a0    = &p_vin[j*16];
            p_a1    = &p_vin[j*16 + 1*4];
            p_a2    = &p_vin[j*16 + 2*4];
            p_a3    = &p_vin[j*16 + 3*4];
            for (i = 0 ; i < 2 ; i++)
            {
                // Load vectors
                BBX_LVNX24_IP(a0, p_a0, 64);
                BBX_LVNX24_IP(a1, p_a1, 64);
                BBX_LVNX24_IP(a2, p_a2, 64);
                BBX_LVNX24_IP(a3, p_a3, 64);
                // Twiddles
                BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

                tw0 = BBX_MOVN2L(tmpTwiddle);
                tw0 = BBX_SLLSNX24(tw0, shift_24b);



                tw1  = BBX_REPNX24C(tw0, 0);
                tw2  = BBX_REPNX24C(tw0, 1);
                tw3  = BBX_REPNX24C(tw0, 2);
                a1 = BBX_FFTMULNX24CPACKQ(a1, tw1);
                a2 = BBX_FFTMULNX24CPACKQ(a2, tw2);
                a3 = BBX_FFTMULNX24CPACKQ(a3, tw3);
                // Operator
                BBX_MOVL2SA(a2);
                BBX_MOVL2SB(a3);
                b0 = BBX_FFTADD4SABNX24(a0, a1, 0, 0);
                b1 = BBX_FFTADD4SABNX24(a0, a1, 3, 0);
                b2 = BBX_FFTADD4SABNX24(a0, a1, 2, 0);
                b3 = BBX_FFTADD4SABNX24(a0, a1, 1, 0);
                // Store vectors
                BBX_SVNX24_IP(b0, p_b0, 64);
                BBX_SVNX24_IP(b1, p_b1, 64);
                BBX_SVNX24_IP(b2, p_b2, 64);
                BBX_SVNX24_IP(b3, p_b3, 64);

                // Load vectors
                BBX_LVNX24_IP(a4, p_a0, 64);
                BBX_LVNX24_IP(a5, p_a1, 64);
                BBX_LVNX24_IP(a6, p_a2, 64);
                BBX_LVNX24_IP(a7, p_a3, 64);
                //Twiddles
                tw5  = BBX_REPNX24C(tw0, 3);
                tw6  = BBX_REPNX24C(tw0, 4);
                tw7  = BBX_REPNX24C(tw0, 5);
                a5 = BBX_FFTMULNX24CPACKQ(a5, tw5);
                a6 = BBX_FFTMULNX24CPACKQ(a6, tw6);
                a7 = BBX_FFTMULNX24CPACKQ(a7, tw7);
                // Operator
                BBX_MOVL2SC(a6);
                BBX_MOVL2SD(a7);
                b4 = BBX_FFTADD4SCDNX24(a4, a5, 0, 0);
                b5 = BBX_FFTADD4SCDNX24(a4, a5, 3, 0);
                b6 = BBX_FFTADD4SCDNX24(a4, a5, 2, 0);
                b7 = BBX_FFTADD4SCDNX24(a4, a5, 1, 0);
                // Store vectors
                BBX_SVNX24_IP(b4, p_b0, 64);
                BBX_SVNX24_IP(b5, p_b1, 64);
                BBX_SVNX24_IP(b6, p_b2, 64);
                BBX_SVNX24_IP(b7, p_b3, 64);
            }
        }
        // Stage 3
        p_vout =  (bbx_vecNx24 * __restrict) ((uintptr_t)&pScratch1[0]);
        p_vin  = (bbx_vecNx24 * __restrict) ((uintptr_t)&pScratch2[0]);
        // Initialize input pointers
        p_a0    = &p_vin[0];
        p_a1    = &p_vin[1];
        p_a2    = &p_vin[2];
        p_a3    = &p_vin[3];
        // Initialize output pointers
        p_b0    = &p_vout[0];
        p_b1    = &p_vout[16];
        p_b2    = &p_vout[32];
        p_b3    = &p_vout[48];
        // Load fixed select register
        for (i = 0 ; i < 8 ; i++)
        {
            // Load vectors
            BBX_LVNX24_IP(a0, p_a0, 64*4);
            BBX_LVNX24_IP(a1, p_a1, 64*4);
            BBX_LVNX24_IP(a2, p_a2, 64*4);
            BBX_LVNX24_IP(a3, p_a3, 64*4);
            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw0 = BBX_MOVN2L(tmpTwiddle);
            tw0 = BBX_SLLSNX24(tw0, shift_24b);



            tw1  = BBX_REPNX24C(tw0, 0);
            tw2  = BBX_REPNX24C(tw0, 1);
            tw3  = BBX_REPNX24C(tw0, 2);
            a1 = BBX_FFTMULNX24CPACKQ(a1, tw1);
            a2 = BBX_FFTMULNX24CPACKQ(a2, tw2);
            a3 = BBX_FFTMULNX24CPACKQ(a3, tw3);
            // Operator
            BBX_MOVL2SA(a2);
            BBX_MOVL2SB(a3);
            b0 = BBX_FFTADD4SABNX24(a0, a1, 0, 0);
            b1 = BBX_FFTADD4SABNX24(a0, a1, 3, 0);
            b2 = BBX_FFTADD4SABNX24(a0, a1, 2, 0);
            b3 = BBX_FFTADD4SABNX24(a0, a1, 1, 0);
            // Store vectors
            BBX_SVNX24_IP(b0, p_b0, 64);
            BBX_SVNX24_IP(b1, p_b1, 64);
            BBX_SVNX24_IP(b2, p_b2, 64);
            BBX_SVNX24_IP(b3, p_b3, 64);

            // Load vectors
            BBX_LVNX24_IP(a4, p_a0, 64*4);
            BBX_LVNX24_IP(a5, p_a1, 64*4);
            BBX_LVNX24_IP(a6, p_a2, 64*4);
            BBX_LVNX24_IP(a7, p_a3, 64*4);
            // Twiddles
            tw5  = BBX_REPNX24C(tw0, 3);
            tw6  = BBX_REPNX24C(tw0, 4);
            tw7  = BBX_REPNX24C(tw0, 5);
            a5 = BBX_FFTMULNX24CPACKQ(a5, tw5);
            a6 = BBX_FFTMULNX24CPACKQ(a6, tw6);
            a7 = BBX_FFTMULNX24CPACKQ(a7, tw7);
            // Operator
            BBX_MOVL2SC(a6);
            BBX_MOVL2SD(a7);
            b4 = BBX_FFTADD4SCDNX24(a4, a5, 0, 0);
            b5 = BBX_FFTADD4SCDNX24(a4, a5, 3, 0);
            b6 = BBX_FFTADD4SCDNX24(a4, a5, 2, 0);
            b7 = BBX_FFTADD4SCDNX24(a4, a5, 1, 0);
            // Store vectors
            BBX_SVNX24_IP(b4, p_b0, 64);
            BBX_SVNX24_IP(b5, p_b1, 64);
            BBX_SVNX24_IP(b6, p_b2, 64);
            BBX_SVNX24_IP(b7, p_b3, 64);

        }

        // Stage 4
        p_vout =  (bbx_vecNx24 * __restrict) ((uintptr_t)&pScratch2[0]);
        p_vin  = (bbx_vecNx24 * __restrict) ((uintptr_t)&pScratch1[0]);
        // Initialize input pointers
        p_a0    = &p_vin[0];
        p_a1    = &p_vin[1];
        p_a2    = &p_vin[2];
        p_a3    = &p_vin[3];
        // Initialize output pointers
        p_b0    = &p_vout[0];
        p_b1    = &p_vout[16];
        p_b2    = &p_vout[32];
        p_b3    = &p_vout[48];
        // Load fixed select register
        BBX_MOVI2S0(BBE_DSELI_INTERLEAVE_4);
        for (i = 0 ; i < 8 ; i++)
        {
            // Load vectors
            BBX_LVNX24_IP(a0, p_a0, 64*4);
            BBX_LVNX24_IP(a1, p_a1, 64*4);
            BBX_LVNX24_IP(a2, p_a2, 64*4);
            BBX_LVNX24_IP(a3, p_a3, 64*4);
            // Local permutations
            BBX_DSELNX24S0(a1, a0, a1, a0);
            BBX_DSELNX24S0(a3, a2, a3, a2);
            BBX_MOVI2S1(BBE_SELI_EXTRACT_LO_HALVES);
            tmp_a0 = BBX_SELNX24S1(a2, a0);
            tmp_a2 = BBX_SELNX24S1(a3, a1);
            BBX_MOVI2S1(BBE_SELI_EXTRACT_HI_HALVES);
            tmp_a1 = BBX_SELNX24S1(a2, a0);
            tmp_a3 = BBX_SELNX24S1(a3, a1);
            a0 = tmp_a0;
            a1 = tmp_a1;
            a2 = tmp_a2;
            a3 = tmp_a3;
            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw1 = BBX_MOVN2L(tmpTwiddle);
            tw1 = BBX_SLLSNX24(tw1, shift_24b);



            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw2 = BBX_MOVN2L(tmpTwiddle);
            tw2 = BBX_SLLSNX24(tw2, shift_24b);



            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw3 = BBX_MOVN2L(tmpTwiddle);
            tw3 = BBX_SLLSNX24(tw3, shift_24b);



            a1 = BBX_FFTMULNX24CPACKQ(a1, tw1);
            a2 = BBX_FFTMULNX24CPACKQ(a2, tw2);
            a3 = BBX_FFTMULNX24CPACKQ(a3, tw3);
            // Operator
            BBX_MOVL2SA(a2);
            BBX_MOVL2SB(a3);
            b0 = BBX_FFTADD4SABNX24(a0, a1, 0, 0);
            b1 = BBX_FFTADD4SABNX24(a0, a1, 3, 0);
            b2 = BBX_FFTADD4SABNX24(a0, a1, 2, 0);
            b3 = BBX_FFTADD4SABNX24(a0, a1, 1, 0);
            // Store vectors
            BBX_SVNX24_IP(b0, p_b0, 64);
            BBX_SVNX24_IP(b1, p_b1, 64);
            BBX_SVNX24_IP(b2, p_b2, 64);
            BBX_SVNX24_IP(b3, p_b3, 64);

            // Load vectors
            BBX_LVNX24_IP(a4, p_a0, 64*4);
            BBX_LVNX24_IP(a5, p_a1, 64*4);
            BBX_LVNX24_IP(a6, p_a2, 64*4);
            BBX_LVNX24_IP(a7, p_a3, 64*4);
            // Local permutations
            BBX_DSELNX24S0(a5, a4, a5, a4);
            BBX_DSELNX24S0(a7, a6, a7, a6);
            BBX_MOVI2S1(BBE_SELI_EXTRACT_LO_HALVES);
            tmp_a4 = BBX_SELNX24S1(a6, a4);
            tmp_a6 = BBX_SELNX24S1(a7, a5);
            BBX_MOVI2S1(BBE_SELI_EXTRACT_HI_HALVES);
            tmp_a5 = BBX_SELNX24S1(a6, a4);
            tmp_a7 = BBX_SELNX24S1(a7, a5);
            a4 = tmp_a4;
            a5 = tmp_a5;
            a6 = tmp_a6;
            a7 = tmp_a7;
            // Twiddles
            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw5 = BBX_MOVN2L(tmpTwiddle);
            tw5 = BBX_SLLSNX24(tw5, shift_24b);



            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw6 = BBX_MOVN2L(tmpTwiddle);
            tw6 = BBX_SLLSNX24(tw6, shift_24b);



            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw7 = BBX_MOVN2L(tmpTwiddle);
            tw7 = BBX_SLLSNX24(tw7, shift_24b);



            a5 = BBX_FFTMULNX24CPACKQ(a5, tw5);
            a6 = BBX_FFTMULNX24CPACKQ(a6, tw6);
            a7 = BBX_FFTMULNX24CPACKQ(a7, tw7);
            // Operator
            BBX_MOVL2SC(a6);
            BBX_MOVL2SD(a7);
            b4 = BBX_FFTADD4SCDNX24(a4, a5, 0, 0);
            b5 = BBX_FFTADD4SCDNX24(a4, a5, 3, 0);
            b6 = BBX_FFTADD4SCDNX24(a4, a5, 2, 0);
            b7 = BBX_FFTADD4SCDNX24(a4, a5, 1, 0);
            // Store vectors
            BBX_SVNX24_IP(b4, p_b0, 64);
            BBX_SVNX24_IP(b5, p_b1, 64);
            BBX_SVNX24_IP(b6, p_b2, 64);
            BBX_SVNX24_IP(b7, p_b3, 64);

        }

        // Stage 5
        p_vout =  (bbx_vecNx24 * __restrict) ((uintptr_t)&pInOut[0]);
        p_vin  = (bbx_vecNx24 * __restrict) ((uintptr_t)&pScratch2[0]);
        // Reset A,B,C,D registers for last radix-2 stage
        BBX_MOVL2SA(0);
        BBX_MOVL2SB(0);
        BBX_MOVL2SC(0);
        BBX_MOVL2SD(0);
        // Initialize input pointers
        p_a0    = &p_vin[0];
        p_a1    = &p_vin[1];
        // Initialize output pointers
        p_b0    = &p_vout[0];
        p_b1    = &p_vout[32];
        //Load fixed select registers
        BBX_MOVI2S0(BBE_DSELI_DEINTERLEAVE_2);
        BBX_MOVI2S1(BBE_DSELI_DEINTERLEAVE_2);
        for (i=0 ; i <16 ; i++)
        {
            // Load vectors
            BBX_LVNX24_IP(a0, p_a0, 64*2);
            BBX_LVNX24_IP(a1, p_a1, 64*2);
            // Local permutations
            BBX_DSELNX24S0(a1, a0, a1, a0);
            // Twiddles
            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw1 = BBX_MOVN2L(tmpTwiddle);
            tw1 = BBX_SLLSNX24(tw1, shift_24b);



            a1 = BBX_FFTMULNX24CPACKQ(a1, tw1);
            // Operator
            b0 = BBX_FFTADD4SABNX24(a0, a1, 0, 0);
            b1 = BBX_FFTADD4SABNX24(a0, a1, 2, 0);
            // Store vectors
            BBX_SVNX24_IP(b0, p_b0, 64);
            BBX_SVNX24_IP(b1, p_b1, 64);

            // Load vectors
            BBX_LVNX24_IP(a4, p_a0, 64*2);
            BBX_LVNX24_IP(a5, p_a1, 64*2);
            //Local permutations
            BBX_DSELNX24S1(a5, a4, a5, a4);
            // Twiddles
            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw5 = BBX_MOVN2L(tmpTwiddle);
            tw5 = BBX_SLLSNX24(tw5, shift_24b);



            a5 = BBX_FFTMULNX24CPACKQ(a5, tw5);
            // Operator
            b4 = BBX_FFTADD4SCDNX24(a4, a5, 0, 0);
            b5 = BBX_FFTADD4SCDNX24(a4, a5, 2, 0);
            // Store vectors
            BBX_SVNX24_IP(b4, p_b0, 64);
            BBX_SVNX24_IP(b5, p_b1, 64);
        }
    // fft 1024
    } else if (size == RSDK_BBE32_FFT_SIZE_1024) {
        // Stage 2
        p_vout =  (bbx_vecNx24 * __restrict) ((uintptr_t)&pScratch2[0]);
        p_vin  = (bbx_vecNx24 * __restrict) ((uintptr_t)&pScratch1[0]);
        // Initialize output pointers
        p_b0    = &p_vout[0];
        p_b1    = &p_vout[32];
        p_b2    = &p_vout[64];
        p_b3    = &p_vout[96];
        for (j = 0 ; j < 4 ; j++)
        {
            // Initialize input pointers
            p_a0    = &p_vin[j*32];
            p_a1    = &p_vin[j*32 + 1*8];
            p_a2    = &p_vin[j*32 + 2*8];
            p_a3    = &p_vin[j*32 + 3*8];
            for (i = 0 ; i < 4 ; i++)
            {
                // Load vectors
                BBX_LVNX24_IP(a0, p_a0, 64);
                BBX_LVNX24_IP(a1, p_a1, 64);
                BBX_LVNX24_IP(a2, p_a2, 64);
                BBX_LVNX24_IP(a3, p_a3, 64);
                // Twiddles
                BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

                tw0 = BBX_MOVN2L(tmpTwiddle);
                tw0 = BBX_SLLSNX24(tw0, shift_24b);



                tw1  = BBX_REPNX24C(tw0, 0);
                tw2  = BBX_REPNX24C(tw0, 1);
                tw3  = BBX_REPNX24C(tw0, 2);
                a1 = BBX_FFTMULNX24CPACKQ(a1, tw1);
                a2 = BBX_FFTMULNX24CPACKQ(a2, tw2);
                a3 = BBX_FFTMULNX24CPACKQ(a3, tw3);
                // Operator
                BBX_MOVL2SA(a2);
                BBX_MOVL2SB(a3);
                b0 = BBX_FFTADD4SABNX24(a0, a1, 0, 0);
                b1 = BBX_FFTADD4SABNX24(a0, a1, 3, 0);
                b2 = BBX_FFTADD4SABNX24(a0, a1, 2, 0);
                b3 = BBX_FFTADD4SABNX24(a0, a1, 1, 0);
                // Store vectors
                BBX_SVNX24_IP(b0, p_b0, 64);
                BBX_SVNX24_IP(b1, p_b1, 64);
                BBX_SVNX24_IP(b2, p_b2, 64);
                BBX_SVNX24_IP(b3, p_b3, 64);

                //Load vectors
                BBX_LVNX24_IP(a4, p_a0, 64);
                BBX_LVNX24_IP(a5, p_a1, 64);
                BBX_LVNX24_IP(a6, p_a2, 64);
                BBX_LVNX24_IP(a7, p_a3, 64);
                // Twiddles
                tw5  = BBX_REPNX24C(tw0, 3);
                tw6  = BBX_REPNX24C(tw0, 4);
                tw7  = BBX_REPNX24C(tw0, 5);
                a5 = BBX_FFTMULNX24CPACKQ(a5, tw5);
                a6 = BBX_FFTMULNX24CPACKQ(a6, tw6);
                a7 = BBX_FFTMULNX24CPACKQ(a7, tw7);
                // Operator
                BBX_MOVL2SC(a6);
                BBX_MOVL2SD(a7);
                b4 = BBX_FFTADD4SCDNX24(a4, a5, 0, 0);
                b5 = BBX_FFTADD4SCDNX24(a4, a5, 3, 0);
                b6 = BBX_FFTADD4SCDNX24(a4, a5, 2, 0);
                b7 = BBX_FFTADD4SCDNX24(a4, a5, 1, 0);
                // Store vectors
                BBX_SVNX24_IP(b4, p_b0, 64);
                BBX_SVNX24_IP(b5, p_b1, 64);
                BBX_SVNX24_IP(b6, p_b2, 64);
                BBX_SVNX24_IP(b7, p_b3, 64);
            }
        }
        // Stage 3
        p_vout =  (bbx_vecNx24 * __restrict) ((uintptr_t)&pScratch1[0]);
        p_vin  = (bbx_vecNx24 * __restrict) ((uintptr_t)&pScratch2[0]);
        // Initialize output pointers
        p_b0    = &p_vout[0];
        p_b1    = &p_vout[32];
        p_b2    = &p_vout[64];
        p_b3    = &p_vout[96];
        for (j = 0 ; j < 16 ; j++)
        {
            // Initialize input pointers
            p_a0    = &p_vin[j*8];
            p_a1    = &p_vin[j*8 + 1*2];
            p_a2    = &p_vin[j*8 + 2*2];
            p_a3    = &p_vin[j*8 + 3*2];
            for (i = 0 ; i < 1 ; i++)
            {
                // Load vectors
                BBX_LVNX24_IP(a0, p_a0, 64);
                BBX_LVNX24_IP(a1, p_a1, 64);
                BBX_LVNX24_IP(a2, p_a2, 64);
                BBX_LVNX24_IP(a3, p_a3, 64);
                // Twiddles
                BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

                tw0 = BBX_MOVN2L(tmpTwiddle);
                tw0 = BBX_SLLSNX24(tw0, shift_24b);



                tw1  = BBX_REPNX24C(tw0, 0);
                tw2  = BBX_REPNX24C(tw0, 1);
                tw3  = BBX_REPNX24C(tw0, 2);
                a1 = BBX_FFTMULNX24CPACKQ(a1, tw1);
                a2 = BBX_FFTMULNX24CPACKQ(a2, tw2);
                a3 = BBX_FFTMULNX24CPACKQ(a3, tw3);
                // Operator
                BBX_MOVL2SA(a2);
                BBX_MOVL2SB(a3);
                b0 = BBX_FFTADD4SABNX24(a0, a1, 0, 0);
                b1 = BBX_FFTADD4SABNX24(a0, a1, 3, 0);
                b2 = BBX_FFTADD4SABNX24(a0, a1, 2, 0);
                b3 = BBX_FFTADD4SABNX24(a0, a1, 1, 0);
                // Store vectors
                BBX_SVNX24_IP(b0, p_b0, 64);
                BBX_SVNX24_IP(b1, p_b1, 64);
                BBX_SVNX24_IP(b2, p_b2, 64);
                BBX_SVNX24_IP(b3, p_b3, 64);

                // Load vectors
                BBX_LVNX24_IP(a4, p_a0, 64);
                BBX_LVNX24_IP(a5, p_a1, 64);
                BBX_LVNX24_IP(a6, p_a2, 64);
                BBX_LVNX24_IP(a7, p_a3, 64);
                // Twiddles
                tw5  = BBX_REPNX24C(tw0, 3);
                tw6  = BBX_REPNX24C(tw0, 4);
                tw7  = BBX_REPNX24C(tw0, 5);
                a5 = BBX_FFTMULNX24CPACKQ(a5, tw5);
                a6 = BBX_FFTMULNX24CPACKQ(a6, tw6);
                a7 = BBX_FFTMULNX24CPACKQ(a7, tw7);
                // Operator
                BBX_MOVL2SC(a6);
                BBX_MOVL2SD(a7);
                b4 = BBX_FFTADD4SCDNX24(a4, a5, 0, 0);
                b5 = BBX_FFTADD4SCDNX24(a4, a5, 3, 0);
                b6 = BBX_FFTADD4SCDNX24(a4, a5, 2, 0);
                b7 = BBX_FFTADD4SCDNX24(a4, a5, 1, 0);
                // Store vectors
                BBX_SVNX24_IP(b4, p_b0, 64);
                BBX_SVNX24_IP(b5, p_b1, 64);
                BBX_SVNX24_IP(b6, p_b2, 64);
                BBX_SVNX24_IP(b7, p_b3, 64);
            }
        }
        // Stage 4
        p_vout =  (bbx_vecNx24 * __restrict) ((uintptr_t)&pScratch2[0]);
        p_vin  = (bbx_vecNx24 * __restrict) ((uintptr_t)&pScratch1[0]);
        // Initialize input pointers
        p_a0    = &p_vin[0];
        p_a1    = &p_vin[1];
        p_a2    = &p_vin[2];
        p_a3    = &p_vin[3];
        // Initialize output pointers
        p_b0    = &p_vout[0];
        p_b1    = &p_vout[32];
        p_b2    = &p_vout[64];
        p_b3    = &p_vout[96];
        // Load fixed select register
        BBX_MOVI2S0(BBE_SELI_EXTRACT_LO_HALVES);
        BBX_MOVI2S1(BBE_SELI_EXTRACT_HI_HALVES);
        for (i = 0 ; i < 16 ; i++)
        {
            // Load vectors
            BBX_LVNX24_IP(a0, p_a0, 64*4);
            BBX_LVNX24_IP(a1, p_a1, 64*4);
            BBX_LVNX24_IP(a2, p_a2, 64*4);
            BBX_LVNX24_IP(a3, p_a3, 64*4);
            // Local permutations
            tmp_a0 = BBX_SELNX24S0(a2, a0);
            tmp_a1 = BBX_SELNX24S1(a2, a0);
            tmp_a2 = BBX_SELNX24S0(a3, a1);
            tmp_a3 = BBX_SELNX24S1(a3, a1);
            a0 = tmp_a0;
            a1 = tmp_a1;
            a2 = tmp_a2;
            a3 = tmp_a3;
            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw1 = BBX_MOVN2L(tmpTwiddle);
            tw1 = BBX_SLLSNX24(tw1, shift_24b);



            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw2 = BBX_MOVN2L(tmpTwiddle);
            tw2 = BBX_SLLSNX24(tw2, shift_24b);



            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw3 = BBX_MOVN2L(tmpTwiddle);
            tw3 = BBX_SLLSNX24(tw3, shift_24b);



            a1 = BBX_FFTMULNX24CPACKQ(a1, tw1);
            a2 = BBX_FFTMULNX24CPACKQ(a2, tw2);
            a3 = BBX_FFTMULNX24CPACKQ(a3, tw3);
            // Operator
            BBX_MOVL2SA(a2);
            BBX_MOVL2SB(a3);
            b0 = BBX_FFTADD4SABNX24(a0, a1, 0, 0);
            b1 = BBX_FFTADD4SABNX24(a0, a1, 3, 0);
            b2 = BBX_FFTADD4SABNX24(a0, a1, 2, 0);
            b3 = BBX_FFTADD4SABNX24(a0, a1, 1, 0);
            // Store vectors
            BBX_SVNX24_IP(b0, p_b0, 64);
            BBX_SVNX24_IP(b1, p_b1, 64);
            BBX_SVNX24_IP(b2, p_b2, 64);
            BBX_SVNX24_IP(b3, p_b3, 64);

            // Load vectors
            BBX_LVNX24_IP(a4, p_a0, 64*4);
            BBX_LVNX24_IP(a5, p_a1, 64*4);
            BBX_LVNX24_IP(a6, p_a2, 64*4);
            BBX_LVNX24_IP(a7, p_a3, 64*4);
            // Local permutations
            tmp_a4 = BBX_SELNX24S0(a6, a4);
            tmp_a5 = BBX_SELNX24S1(a6, a4);
            tmp_a6 = BBX_SELNX24S0(a7, a5);
            tmp_a7 = BBX_SELNX24S1(a7, a5);
            a4 = tmp_a4;
            a5 = tmp_a5;
            a6 = tmp_a6;
            a7 = tmp_a7;
            // Twiddles
            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw5 = BBX_MOVN2L(tmpTwiddle);
            tw5 = BBX_SLLSNX24(tw5, shift_24b);



            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw6 = BBX_MOVN2L(tmpTwiddle);
            tw6 = BBX_SLLSNX24(tw6, shift_24b);



            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw7 = BBX_MOVN2L(tmpTwiddle);
            tw7 = BBX_SLLSNX24(tw7, shift_24b);



            a5 = BBX_FFTMULNX24CPACKQ(a5, tw5);
            a6 = BBX_FFTMULNX24CPACKQ(a6, tw6);
            a7 = BBX_FFTMULNX24CPACKQ(a7, tw7);
            // Operator
            BBX_MOVL2SC(a6);
            BBX_MOVL2SD(a7);
            b4 = BBX_FFTADD4SCDNX24(a4, a5, 0, 0);
            b5 = BBX_FFTADD4SCDNX24(a4, a5, 3, 0);
            b6 = BBX_FFTADD4SCDNX24(a4, a5, 2, 0);
            b7 = BBX_FFTADD4SCDNX24(a4, a5, 1, 0);
            // Store vectors
            BBX_SVNX24_IP(b4, p_b0, 64);
            BBX_SVNX24_IP(b5, p_b1, 64);
            BBX_SVNX24_IP(b6, p_b2, 64);
            BBX_SVNX24_IP(b7, p_b3, 64);
        }
        // Stage 5
        p_vout =  (bbx_vecNx24 * __restrict) ((uintptr_t)&pInOut[0]);
        p_vin  = (bbx_vecNx24 * __restrict) ((uintptr_t)&pScratch2[0]);
        // Initialize input pointers
        p_a0    = &p_vin[0];
        p_a1    = &p_vin[1];
        p_a2    = &p_vin[2];
        p_a3    = &p_vin[3];
        // Initialize output pointers
        p_b0    = &p_vout[0];
        p_b1    = &p_vout[32];
        p_b2    = &p_vout[64];
        p_b3    = &p_vout[96];
        // Load fixed select register
        BBX_MOVI2S1(BBE_DSELI_DEINTERLEAVE_2);
        for (i = 0 ; i < 16 ; i++)
        {
            // Load vectors
            BBX_LVNX24_IP(a0, p_a0, 64*4);
            BBX_LVNX24_IP(a1, p_a1, 64*4);
            BBX_LVNX24_IP(a2, p_a2, 64*4);
            BBX_LVNX24_IP(a3, p_a3, 64*4);
            // Local permutations
            BBX_MOVI2S0(BBE_SELI_16B_EXTRACT_4_OF_8_OFF_0);
            tmp_a0 = BBX_SELNX24S0(a1, a0);
            tmp_a2 = BBX_SELNX24S0(a3, a2);
            BBX_MOVI2S0(BBE_SELI_16B_EXTRACT_4_OF_8_OFF_4);
            tmp_a1 = BBX_SELNX24S0(a1, a0);
            tmp_a3 = BBX_SELNX24S0(a3, a2);
            BBX_DSELNX24S1(a1, a0, tmp_a2, tmp_a0);
            BBX_DSELNX24S1(a3, a2, tmp_a3, tmp_a1);
            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw1 = BBX_MOVN2L(tmpTwiddle);
            tw1 = BBX_SLLSNX24(tw1, shift_24b);



            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw2 = BBX_MOVN2L(tmpTwiddle);
            tw2 = BBX_SLLSNX24(tw2, shift_24b);



            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw3 = BBX_MOVN2L(tmpTwiddle);
            tw3 = BBX_SLLSNX24(tw3, shift_24b);



            a1 = BBX_FFTMULNX24CPACKQ(a1, tw1);
            a2 = BBX_FFTMULNX24CPACKQ(a2, tw2);
            a3 = BBX_FFTMULNX24CPACKQ(a3, tw3);
            // Operator
            BBX_MOVL2SA(a2);
            BBX_MOVL2SB(a3);
            b0 = BBX_FFTADD4SABNX24(a0, a1, 0, 0);
            b1 = BBX_FFTADD4SABNX24(a0, a1, 3, 0);
            b2 = BBX_FFTADD4SABNX24(a0, a1, 2, 0);
            b3 = BBX_FFTADD4SABNX24(a0, a1, 1, 0);
            // Store vectors
            BBX_SVNX24_IP(b0, p_b0, 64);
            BBX_SVNX24_IP(b1, p_b1, 64);
            BBX_SVNX24_IP(b2, p_b2, 64);
            BBX_SVNX24_IP(b3, p_b3, 64);

            // Load vectors
            BBX_LVNX24_IP(a4, p_a0, 64*4);
            BBX_LVNX24_IP(a5, p_a1, 64*4);
            BBX_LVNX24_IP(a6, p_a2, 64*4);
            BBX_LVNX24_IP(a7, p_a3, 64*4);
            // Local permutations
            BBX_MOVI2S0(BBE_SELI_16B_EXTRACT_4_OF_8_OFF_0);
            tmp_a4 = BBX_SELNX24S0(a5, a4);
            tmp_a6 = BBX_SELNX24S0(a7, a6);
            BBX_MOVI2S0(BBE_SELI_16B_EXTRACT_4_OF_8_OFF_4);
            tmp_a5 = BBX_SELNX24S0(a5, a4);
            tmp_a7 = BBX_SELNX24S0(a7, a6);
            BBX_DSELNX24S1(a5, a4, tmp_a6, tmp_a4);
            BBX_DSELNX24S1(a7, a6, tmp_a7, tmp_a5);
            // Twiddles
            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw5 = BBX_MOVN2L(tmpTwiddle);
            tw5 = BBX_SLLSNX24(tw5, shift_24b);



            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw6 = BBX_MOVN2L(tmpTwiddle);
            tw6 = BBX_SLLSNX24(tw6, shift_24b);



            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw7 = BBX_MOVN2L(tmpTwiddle);
            tw7 = BBX_SLLSNX24(tw7, shift_24b);



            a5 = BBX_FFTMULNX24CPACKQ(a5, tw5);
            a6 = BBX_FFTMULNX24CPACKQ(a6, tw6);
            a7 = BBX_FFTMULNX24CPACKQ(a7, tw7);
            // Operator
            BBX_MOVL2SC(a6);
            BBX_MOVL2SD(a7);
            b4 = BBX_FFTADD4SCDNX24(a4, a5, 0, 0);
            b5 = BBX_FFTADD4SCDNX24(a4, a5, 3, 0);
            b6 = BBX_FFTADD4SCDNX24(a4, a5, 2, 0);
            b7 = BBX_FFTADD4SCDNX24(a4, a5, 1, 0);
            // Store vectors
            BBX_SVNX24_IP(b4, p_b0, 64);
            BBX_SVNX24_IP(b5, p_b1, 64);
            BBX_SVNX24_IP(b6, p_b2, 64);
            BBX_SVNX24_IP(b7, p_b3, 64);
        }
    // fft 2048
    } else if (size == RSDK_BBE32_FFT_SIZE_2048) {
        // Stage 2
        p_vout =  (bbx_vecNx24 * __restrict) ((uintptr_t)&pScratch2[0]);
        p_vin  = (bbx_vecNx24 * __restrict) ((uintptr_t)&pScratch1[0]);
        // Initialize output pointers
        p_b0    = &p_vout[0];
        p_b1    = &p_vout[64];
        p_b2    = &p_vout[128];
        p_b3    = &p_vout[192];
        for (j = 0; j < 4; j++)
        {
            // Initialize input pointers
            p_a0    = &p_vin[j*64];
            p_a1    = &p_vin[j*64 + 1*16];
            p_a2    = &p_vin[j*64 + 2*16];
            p_a3    = &p_vin[j*64 + 3*16];
            for (i = 0; i < 8; i++)
            {
                // Load vectors
                BBX_LVNX24_IP(a0, p_a0, 64);
                BBX_LVNX24_IP(a1, p_a1, 64);
                BBX_LVNX24_IP(a2, p_a2, 64);
                BBX_LVNX24_IP(a3, p_a3, 64);
                // Twiddles
                BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

                tw0 = BBX_MOVN2L(tmpTwiddle);
                tw0 = BBX_SLLSNX24(tw0, shift_24b);



                tw1  = BBX_REPNX24C(tw0, 0);
                tw2  = BBX_REPNX24C(tw0, 1);
                tw3  = BBX_REPNX24C(tw0, 2);
                a1 = BBX_FFTMULNX24CPACKQ(a1, tw1);
                a2 = BBX_FFTMULNX24CPACKQ(a2, tw2);
                a3 = BBX_FFTMULNX24CPACKQ(a3, tw3);
                //Operator
                BBX_MOVL2SA(a2);
                BBX_MOVL2SB(a3);
                b0 = BBX_FFTADD4SABNX24(a0, a1, 0, 0);
                b1 = BBX_FFTADD4SABNX24(a0, a1, 3, 0);
                b2 = BBX_FFTADD4SABNX24(a0, a1, 2, 0);
                b3 = BBX_FFTADD4SABNX24(a0, a1, 1, 0);
                // Store vectors
                BBX_SVNX24_IP(b0, p_b0, 64);
                BBX_SVNX24_IP(b1, p_b1, 64);
                BBX_SVNX24_IP(b2, p_b2, 64);
                BBX_SVNX24_IP(b3, p_b3, 64);

                // Load vectors
                BBX_LVNX24_IP(a4, p_a0, 64);
                BBX_LVNX24_IP(a5, p_a1, 64);
                BBX_LVNX24_IP(a6, p_a2, 64);
                BBX_LVNX24_IP(a7, p_a3, 64);
                // Twiddles
                tw5  = BBX_REPNX24C(tw0, 3);
                tw6  = BBX_REPNX24C(tw0, 4);
                tw7  = BBX_REPNX24C(tw0, 5);
                a5 = BBX_FFTMULNX24CPACKQ(a5, tw5);
                a6 = BBX_FFTMULNX24CPACKQ(a6, tw6);
                a7 = BBX_FFTMULNX24CPACKQ(a7, tw7);
                // Operator
                BBX_MOVL2SC(a6);
                BBX_MOVL2SD(a7);
                b4 = BBX_FFTADD4SCDNX24(a4, a5, 0, 0);
                b5 = BBX_FFTADD4SCDNX24(a4, a5, 3, 0);
                b6 = BBX_FFTADD4SCDNX24(a4, a5, 2, 0);
                b7 = BBX_FFTADD4SCDNX24(a4, a5, 1, 0);
                // Store vectors
                BBX_SVNX24_IP(b4, p_b0, 64);
                BBX_SVNX24_IP(b5, p_b1, 64);
                BBX_SVNX24_IP(b6, p_b2, 64);
                BBX_SVNX24_IP(b7, p_b3, 64);
            }
        }
        // Stage 3
        p_vout =  (bbx_vecNx24 * __restrict) ((uintptr_t)&pScratch1[0]);
        p_vin  = (bbx_vecNx24 * __restrict) ((uintptr_t)&pScratch2[0]);
        // Initialize output pointers
        p_b0    = &p_vout[0];
        p_b1    = &p_vout[64];
        p_b2    = &p_vout[128];
        p_b3    = &p_vout[192];
        for (j = 0; j < 16; j++)
        {
            // Initialize input pointers
            p_a0    = &p_vin[j*16];
            p_a1    = &p_vin[j*16 + 1*4];
            p_a2    = &p_vin[j*16 + 2*4];
            p_a3    = &p_vin[j*16 + 3*4];
            for (i = 0; i < 2; i++)
            {
                // Load vectors
                BBX_LVNX24_IP(a0, p_a0, 64);
                BBX_LVNX24_IP(a1, p_a1, 64);
                BBX_LVNX24_IP(a2, p_a2, 64);
                BBX_LVNX24_IP(a3, p_a3, 64);
                // Twiddles
                BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

                tw0 = BBX_MOVN2L(tmpTwiddle);
                tw0 = BBX_SLLSNX24(tw0, shift_24b);



                tw1  = BBX_REPNX24C(tw0, 0);
                tw2  = BBX_REPNX24C(tw0, 1);
                tw3  = BBX_REPNX24C(tw0, 2);
                a1 = BBX_FFTMULNX24CPACKQ(a1, tw1);
                a2 = BBX_FFTMULNX24CPACKQ(a2, tw2);
                a3 = BBX_FFTMULNX24CPACKQ(a3, tw3);
                // Operator
                BBX_MOVL2SA(a2);
                BBX_MOVL2SB(a3);
                b0 = BBX_FFTADD4SABNX24(a0, a1, 0, 0);
                b1 = BBX_FFTADD4SABNX24(a0, a1, 3, 0);
                b2 = BBX_FFTADD4SABNX24(a0, a1, 2, 0);
                b3 = BBX_FFTADD4SABNX24(a0, a1, 1, 0);
                // Store vectors
                BBX_SVNX24_IP(b0, p_b0, 64);
                BBX_SVNX24_IP(b1, p_b1, 64);
                BBX_SVNX24_IP(b2, p_b2, 64);
                BBX_SVNX24_IP(b3, p_b3, 64);

                // Load vectors
                BBX_LVNX24_IP(a4, p_a0, 64);
                BBX_LVNX24_IP(a5, p_a1, 64);
                BBX_LVNX24_IP(a6, p_a2, 64);
                BBX_LVNX24_IP(a7, p_a3, 64);
                // Twiddles
                tw5  = BBX_REPNX24C(tw0, 3);
                tw6  = BBX_REPNX24C(tw0, 4);
                tw7  = BBX_REPNX24C(tw0, 5);
                a5 = BBX_FFTMULNX24CPACKQ(a5, tw5);
                a6 = BBX_FFTMULNX24CPACKQ(a6, tw6);
                a7 = BBX_FFTMULNX24CPACKQ(a7, tw7);
                // Operator
                BBX_MOVL2SC(a6);
                BBX_MOVL2SD(a7);
                b4 = BBX_FFTADD4SCDNX24(a4, a5, 0, 0);
                b5 = BBX_FFTADD4SCDNX24(a4, a5, 3, 0);
                b6 = BBX_FFTADD4SCDNX24(a4, a5, 2, 0);
                b7 = BBX_FFTADD4SCDNX24(a4, a5, 1, 0);
                // Store vectors
                BBX_SVNX24_IP(b4, p_b0, 64);
                BBX_SVNX24_IP(b5, p_b1, 64);
                BBX_SVNX24_IP(b6, p_b2, 64);
                BBX_SVNX24_IP(b7, p_b3, 64);
            }
        }
        // Stage 4
        p_vout =  (bbx_vecNx24 * __restrict) ((uintptr_t)&pScratch2[0]);
        p_vin  = (bbx_vecNx24 * __restrict) ((uintptr_t)&pScratch1[0]);
        // Initialize input pointers
        p_a0    = &p_vin[0];
        p_a1    = &p_vin[1];
        p_a2    = &p_vin[2];
        p_a3    = &p_vin[3];
        // Initialize output pointers
        p_b0    = &p_vout[0];
        p_b1    = &p_vout[64];
        p_b2    = &p_vout[128];
        p_b3    = &p_vout[192];
        // Load fixed select register
        for (i = 0; i < 32; i++)
        {
            //Load vectors
            BBX_LVNX24_IP(a0, p_a0, 64*4);
            BBX_LVNX24_IP(a1, p_a1, 64*4);
            BBX_LVNX24_IP(a2, p_a2, 64*4);
            BBX_LVNX24_IP(a3, p_a3, 64*4);
            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw0 = BBX_MOVN2L(tmpTwiddle);
            tw0 = BBX_SLLSNX24(tw0, shift_24b);



            tw1  = BBX_REPNX24C(tw0, 0);
            tw2  = BBX_REPNX24C(tw0, 1);
            tw3  = BBX_REPNX24C(tw0, 2);
            a1 = BBX_FFTMULNX24CPACKQ(a1, tw1);
            a2 = BBX_FFTMULNX24CPACKQ(a2, tw2);
            a3 = BBX_FFTMULNX24CPACKQ(a3, tw3);
            // Operator
            BBX_MOVL2SA(a2);
            BBX_MOVL2SB(a3);
            b0 = BBX_FFTADD4SABNX24(a0, a1, 0, 0);
            b1 = BBX_FFTADD4SABNX24(a0, a1, 3, 0);
            b2 = BBX_FFTADD4SABNX24(a0, a1, 2, 0);
            b3 = BBX_FFTADD4SABNX24(a0, a1, 1, 0);
            // Store vectors
            BBX_SVNX24_IP(b0, p_b0, 64);
            BBX_SVNX24_IP(b1, p_b1, 64);
            BBX_SVNX24_IP(b2, p_b2, 64);
            BBX_SVNX24_IP(b3, p_b3, 64);

            // Load vectors
            BBX_LVNX24_IP(a4, p_a0, 64*4);
            BBX_LVNX24_IP(a5, p_a1, 64*4);
            BBX_LVNX24_IP(a6, p_a2, 64*4);
            BBX_LVNX24_IP(a7, p_a3, 64*4);
            // Twiddles
            tw5  = BBX_REPNX24C(tw0, 3);
            tw6  = BBX_REPNX24C(tw0, 4);
            tw7  = BBX_REPNX24C(tw0, 5);
            a5 = BBX_FFTMULNX24CPACKQ(a5, tw5);
            a6 = BBX_FFTMULNX24CPACKQ(a6, tw6);
            a7 = BBX_FFTMULNX24CPACKQ(a7, tw7);
            // Operator
            BBX_MOVL2SC(a6);
            BBX_MOVL2SD(a7);
            b4 = BBX_FFTADD4SCDNX24(a4, a5, 0, 0);
            b5 = BBX_FFTADD4SCDNX24(a4, a5, 3, 0);
            b6 = BBX_FFTADD4SCDNX24(a4, a5, 2, 0);
            b7 = BBX_FFTADD4SCDNX24(a4, a5, 1, 0);
            // Store vectors
            BBX_SVNX24_IP(b4, p_b0, 64);
            BBX_SVNX24_IP(b5, p_b1, 64);
            BBX_SVNX24_IP(b6, p_b2, 64);
            BBX_SVNX24_IP(b7, p_b3, 64);
        }
        // Stage 5
        p_vout =  (bbx_vecNx24 * __restrict) ((uintptr_t)&pScratch1[0]);
        p_vin  = (bbx_vecNx24 * __restrict) ((uintptr_t)&pScratch2[0]);
        // Initialize input pointers
        p_a0    = &p_vin[0];
        p_a1    = &p_vin[1];
        p_a2    = &p_vin[2];
        p_a3    = &p_vin[3];
        // Initialize output pointers
        p_b0    = &p_vout[0];
        p_b1    = &p_vout[64];
        p_b2    = &p_vout[128];
        p_b3    = &p_vout[192];
        // Load fixed select register
        BBX_MOVI2S0(BBE_DSELI_INTERLEAVE_4);
        for (i = 0; i < 32; i++)
        {
            // Load vectors
            BBX_LVNX24_IP(a0, p_a0, 64*4);
            BBX_LVNX24_IP(a1, p_a1, 64*4);
            BBX_LVNX24_IP(a2, p_a2, 64*4);
            BBX_LVNX24_IP(a3, p_a3, 64*4);
            // Local permutations
            BBX_DSELNX24S0(a1, a0, a1, a0);
            BBX_DSELNX24S0(a3, a2, a3, a2);
            BBX_MOVI2S1(BBE_SELI_EXTRACT_LO_HALVES);
            tmp_a0 = BBX_SELNX24S1(a2, a0);
            tmp_a2 = BBX_SELNX24S1(a3, a1);
            BBX_MOVI2S1(BBE_SELI_EXTRACT_HI_HALVES);
            tmp_a1 = BBX_SELNX24S1(a2, a0);
            tmp_a3 = BBX_SELNX24S1(a3, a1);
            a0 = tmp_a0;
            a1 = tmp_a1;
            a2 = tmp_a2;
            a3 = tmp_a3;
            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw1 = BBX_MOVN2L(tmpTwiddle);
            tw1 = BBX_SLLSNX24(tw1, shift_24b);



            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw2 = BBX_MOVN2L(tmpTwiddle);
            tw2 = BBX_SLLSNX24(tw2, shift_24b);



            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw3 = BBX_MOVN2L(tmpTwiddle);
            tw3 = BBX_SLLSNX24(tw3, shift_24b);



            a1 = BBX_FFTMULNX24CPACKQ(a1, tw1);
            a2 = BBX_FFTMULNX24CPACKQ(a2, tw2);
            a3 = BBX_FFTMULNX24CPACKQ(a3, tw3);
            // Operator
            BBX_MOVL2SA(a2);
            BBX_MOVL2SB(a3);
            b0 = BBX_FFTADD4SABNX24(a0, a1, 0, 0);
            b1 = BBX_FFTADD4SABNX24(a0, a1, 3, 0);
            b2 = BBX_FFTADD4SABNX24(a0, a1, 2, 0);
            b3 = BBX_FFTADD4SABNX24(a0, a1, 1, 0);
            // Store vectors
            BBX_SVNX24_IP(b0, p_b0, 64);
            BBX_SVNX24_IP(b1, p_b1, 64);
            BBX_SVNX24_IP(b2, p_b2, 64);
            BBX_SVNX24_IP(b3, p_b3, 64);

            // Load vectors
            BBX_LVNX24_IP(a4, p_a0, 64*4);
            BBX_LVNX24_IP(a5, p_a1, 64*4);
            BBX_LVNX24_IP(a6, p_a2, 64*4);
            BBX_LVNX24_IP(a7, p_a3, 64*4);
            // Local permutations
            BBX_DSELNX24S0(a5, a4, a5, a4);
            BBX_DSELNX24S0(a7, a6, a7, a6);
            BBX_MOVI2S1(BBE_SELI_EXTRACT_LO_HALVES);
            tmp_a4 = BBX_SELNX24S1(a6, a4);
            tmp_a6 = BBX_SELNX24S1(a7, a5);
            BBX_MOVI2S1(BBE_SELI_EXTRACT_HI_HALVES);
            tmp_a5 = BBX_SELNX24S1(a6, a4);
            tmp_a7 = BBX_SELNX24S1(a7, a5);
            a4 = tmp_a4;
            a5 = tmp_a5;
            a6 = tmp_a6;
            a7 = tmp_a7;
            // Twiddles
            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw5 = BBX_MOVN2L(tmpTwiddle);
            tw5 = BBX_SLLSNX24(tw5, shift_24b);



            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw6 = BBX_MOVN2L(tmpTwiddle);
            tw6 = BBX_SLLSNX24(tw6, shift_24b);



            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw7 = BBX_MOVN2L(tmpTwiddle);
            tw7 = BBX_SLLSNX24(tw7, shift_24b);



            a5 = BBX_FFTMULNX24CPACKQ(a5, tw5);
            a6 = BBX_FFTMULNX24CPACKQ(a6, tw6);
            a7 = BBX_FFTMULNX24CPACKQ(a7, tw7);
            // Operator
            BBX_MOVL2SC(a6);
            BBX_MOVL2SD(a7);
            b4 = BBX_FFTADD4SCDNX24(a4, a5, 0, 0);
            b5 = BBX_FFTADD4SCDNX24(a4, a5, 3, 0);
            b6 = BBX_FFTADD4SCDNX24(a4, a5, 2, 0);
            b7 = BBX_FFTADD4SCDNX24(a4, a5, 1, 0);
            // Store vectors
            BBX_SVNX24_IP(b4, p_b0, 64);
            BBX_SVNX24_IP(b5, p_b1, 64);
            BBX_SVNX24_IP(b6, p_b2, 64);
            BBX_SVNX24_IP(b7, p_b3, 64);
        }
        // Stage 6
        p_vout =  (bbx_vecNx24 * __restrict) ((uintptr_t)&pInOut[0]);
        p_vin  = (bbx_vecNx24 * __restrict) ((uintptr_t)&pScratch1[0]);
        // Reset A,B,C,D registers for last radix-2 stage
        BBX_MOVL2SA(0);
        BBX_MOVL2SB(0);
        BBX_MOVL2SC(0);
        BBX_MOVL2SD(0);
        // Initialize input pointers
        p_a0    = &p_vin[0];
        p_a1    = &p_vin[1];
        // Initialize output pointers
        p_b0    = &p_vout[0];
        p_b1    = &p_vout[128];
        //Load fixed select registers
        BBX_MOVI2S0(BBE_DSELI_DEINTERLEAVE_2);
        BBX_MOVI2S1(BBE_DSELI_DEINTERLEAVE_2);
        for (i = 0; i < 64; i++)
        {
            // Load vectors
            BBX_LVNX24_IP(a0, p_a0, 64*2);
            BBX_LVNX24_IP(a1, p_a1, 64*2);
            // Local permutations
            BBX_DSELNX24S0(a1, a0, a1, a0);
            // Twiddles
            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw1 = BBX_MOVN2L(tmpTwiddle);
            tw1 = BBX_SLLSNX24(tw1, shift_24b);



            a1 = BBX_FFTMULNX24CPACKQ(a1, tw1);
            // Operator
            b0 = BBX_FFTADD4SABNX24(a0, a1, 0, 0);
            b1 = BBX_FFTADD4SABNX24(a0, a1, 2, 0);
            //Store vectors
            BBX_SVNX24_IP(b0, p_b0, 64);
            BBX_SVNX24_IP(b1, p_b1, 64);

            // Load vectors
            BBX_LVNX24_IP(a4, p_a0, 64*2);
            BBX_LVNX24_IP(a5, p_a1, 64*2);
            // Local permutations
            BBX_DSELNX24S1(a5, a4, a5, a4);
            // Twiddles
            BBE_LVNX16_IP(tmpTwiddle, p_vtw0, 32);

            tw5 = BBX_MOVN2L(tmpTwiddle);
            tw5 = BBX_SLLSNX24(tw5, shift_24b);



            a5 = BBX_FFTMULNX24CPACKQ(a5, tw5);
            // Operator
            b4 = BBX_FFTADD4SCDNX24(a4, a5, 0, 0);
            b5 = BBX_FFTADD4SCDNX24(a4, a5, 2, 0);
            // Store vectors
            BBX_SVNX24_IP(b4, p_b0, 64);
            BBX_SVNX24_IP(b5, p_b1, 64);
        }
    } else {
        SetDspError(RSDK_DSP_ALGO_WRONG_PARAM);
        return;
    }
}
#ifdef __cplusplus
}
#endif

/*******************************************************************************
* EOF
******************************************************************************/
