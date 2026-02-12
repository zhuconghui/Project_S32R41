/**************************************************************************************************
 * Copyright 2022-2023 NXP
 **************************************************************************************************
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 **************************************************************************************************/


/**
* @file           rsdk_dsp_lal_vec_mean.c
*/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "rsdk_dsp_lal.h"
#include "rsdk_dsp_lal_utils.h"

#ifdef __cplusplus
extern "C"{
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
void Rsdk_LA_avg_Sof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                           xb_vecN_2xf32 * pInput,
                                                  uint32_t size)
{
    xb_vecN_2xf32 * pin  = pInput;
    xb_vecN_2xf32 * pout = pOutput;

    xb_vecN_2xf32 acc = BBE_ZERON_2XF32();
    uint32_t      iElem;

    for (iElem = 0UL; iElem < size; iElem++)
    {
        acc += (*pin);
        pin++;
    }
    acc   = acc * BBE_RECIPN_2XF32((xb_vecN_2xf32)size);
    *pout = acc;
}

void Rsdk_LA_avg_Sof32cp8Vif32cp8(xb_vecN_2xcf32 * __restrict pOutput,
                                            xb_vecN_2xcf32  * pInput,
                                                     uint32_t size)
{
    xb_vecN_2xcf32 * pin  = pInput;
    xb_vecN_2xcf32 * pout = pOutput;

    xb_vecN_2xcf32 acc = BBE_ZERON_2XCF32();
    uint32_t       iElem;

    for (iElem = 0UL; iElem < size; iElem++)
    {
        acc += (*pin);
        pin++;
    }
    acc   = acc * BBE_RECIPN_2XCF32(BBE_CMPLXN_2XF32(0.0F, size));
    *pout = acc;
}

void Rsdk_LA_wavg_Sof32p8Vif32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                                   xb_vecN_2xf32 * pInput1,
                                                   xb_vecN_2xf32 * pInput2,
                                                          uint32_t size)
{
    xb_vecN_2xf32 * pin1 = pInput1;
    xb_vecN_2xf32 * pin2 = pInput2;
    xb_vecN_2xf32 * pout = pOutput;

    xb_vecN_2xf32 acc = BBE_ZERON_2XF32();
    xb_vecN_2xf32 sum = BBE_ZERON_2XF32();
    uint32_t      iElem;

    for (iElem = 0UL; iElem < size; iElem++)
    {
        acc += ((*pin1) * (*pin2));
        sum += (*pin2);
        pin1++;
        pin2++;
    }
    acc   = acc * BBE_RECIPN_2XF32(sum);
    *pout = acc;
}

void Rsdk_LA_wavg_Sof32cp8Vif32cp8Vif32cp8(xb_vecN_2xcf32 * __restrict pOutput,
                                                     xb_vecN_2xcf32  * pInput1,
                                                     xb_vecN_2xcf32  * pInput2,
                                                              uint32_t size)
{
    xb_vecN_2xcf32 * pin1 = pInput1;
    xb_vecN_2xcf32 * pin2 = pInput2;
    xb_vecN_2xcf32 * pout = pOutput;

    xb_vecN_2xcf32 acc = BBE_ZERON_2XCF32();
    xb_vecN_2xcf32 sum = BBE_ZERON_2XCF32();
    uint32_t       iElem;

    for (iElem = 0UL; iElem < size; iElem++)
    {
        acc += ((*pin1) * (*pin2));
        sum += (*pin2);
        pin1++;
        pin2++;
    }
    acc   = acc * BBE_RECIPN_2XCF32(sum);
    *pout = acc;
}

void Rsdk_LA_havg_Sof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                            xb_vecN_2xf32 * pInput,
                                                   uint32_t size)
{
    xb_vecN_2xf32 * pin  = pInput;
    xb_vecN_2xf32 * pout = pOutput;

    xb_vecN_2xf32 acc = BBE_ZERON_2XF32();
    uint32_t      iElem;

    for (iElem = 0UL; iElem < size; iElem++)
    {
        acc += BBE_RECIPN_2XF32(*pin);
        pin++;
    }
    acc   = (xb_vecN_2xf32)size * BBE_RECIPN_2XF32(acc);
    *pout = acc;
}

void Rsdk_LA_havg_Sof32cp8Vif32cp8(xb_vecN_2xcf32 * __restrict pOutput,
                                             xb_vecN_2xcf32  * pInput,
                                                      uint32_t size)
{
    xb_vecN_2xcf32 * pin  = pInput;
    xb_vecN_2xcf32 * pout = pOutput;

    xb_vecN_2xcf32 acc = BBE_ZERON_2XCF32();
    uint32_t       iElem;

    for (iElem = 0UL; iElem < size; iElem++)
    {
        acc += BBE_RECIPN_2XCF32(*pin);;
        pin++;
    }
    acc   = BBE_CMPLXN_2XF32(0.0F, size) * BBE_RECIPN_2XCF32(acc);
    *pout = acc;
}

void Rsdk_LA_rms_Sof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                           xb_vecN_2xf32 * pInput,
                                                  uint32_t size)
{
    xb_vecN_2xf32 * pin  = pInput;
    xb_vecN_2xf32 * pout = pOutput;

    xb_vecN_2xf32 acc = BBE_ZERON_2XF32();
    uint32_t      iElem;

    for (iElem = 0UL; iElem < size; iElem++)
    {
        acc += ((*pin) * (*pin));
        pin++;
    }
    acc   = acc * BBE_RECIPN_2XF32((xb_vecN_2xf32)size);
    acc   = BBE_SQRTN_2XF32(acc);
    *pout = acc;
}

void Rsdk_LA_rms_Sof32p8Vif32cp8(xb_vecN_2xf32 * __restrict pOutput,
                                          xb_vecN_2xcf32  * pInput,
                                                   uint32_t size)
{
    xb_vecN_2xf32 const * pin = (xb_vecN_2xf32 *)(uintptr_t)&pInput[0];
    xb_vecN_2xf32 * pout  = pOutput;

    xb_vecN_2xf32 scratch1, scratch2, pin1, pin2, tempMagn;

    xb_vecN_2xf32 acc = BBE_ZERON_2XF32();
    uint32_t      iElem;

    for (iElem = 0UL; iElem < size; iElem++)
    {
        BBE_LVN_2XF32_IP(pin1, pin, 2*XCHAL_BBEN_SIMD_WIDTH);
        BBE_LVN_2XF32_IP(pin2, pin, 2*XCHAL_BBEN_SIMD_WIDTH);
        RSDK_MAG2N_2XF32_V1(tempMagn, pin1, pin2, scratch1, scratch2);

        acc += tempMagn;
    }
    acc   = acc * BBE_RECIPN_2XF32((xb_vecN_2xf32)size);
    acc   = BBE_SQRTN_2XF32(acc);
    *pout = acc;
}
#ifdef __cplusplus
}
#endif

/*******************************************************************************
* EOF
******************************************************************************/
