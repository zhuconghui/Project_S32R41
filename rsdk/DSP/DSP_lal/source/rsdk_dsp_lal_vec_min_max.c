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


/**
* @file           rsdk_dsp_lal_vec_min_max.c
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
void Rsdk_LA_min_Sou32p8Vif32p8(xb_vecN_2x32Uv * __restrict pOutput,
                                            xb_vecN_2xf32 * pInput,
                                                   uint32_t size)
{
    xb_vecN_2x32Uv * pout = pOutput;
    xb_vecN_2xf32 * pin   = pInput;

    xb_vecN_2xf32 min_id = BBE_ZERON_2XF32();
    xb_vecN_2xf32 prev_min_val, min_val = *pin;
    vboolN_2 detect_min;
    uint32_t iElem;

    pin++;
    for (iElem = 1UL; iElem < size; iElem++)
    {
        prev_min_val = min_val;
        min_val = BBE_MINN_2XF32(min_val, *pin);
        detect_min = (vboolN_2)(prev_min_val == min_val);
        min_id = BBE_MOVN_2XF32T(min_id, (xb_vecN_2xf32)(iElem), detect_min);
        pin++;
    }
    *pout = xb_vecN_2xf32_rtor_xb_vecN_2x32Uv(min_id);
}

void Rsdk_LA_minAbs_Sou32p8Vif32cp8(xb_vecN_2x32Uv * __restrict pOutput,
                                               xb_vecN_2xcf32 * pInput,
                                                       uint32_t size)
{
    xb_vecN_2x32Uv * pout = pOutput;
    xb_vecN_2xf32 const * pin = (xb_vecN_2xf32 *)(uintptr_t)&pInput[0];


    xb_vecN_2xf32 min_id = BBE_ZERON_2XF32();
    xb_vecN_2xf32 prev_min_magn, min_magn, tempMagn;
    xb_vecN_2xf32 scratch1, scratch2, pin1, pin2;
    vboolN_2 detect_min;
    uint32_t iElem;

    BBE_LVN_2XF32_IP(pin1, pin, 2*XCHAL_BBEN_SIMD_WIDTH);
    BBE_LVN_2XF32_IP(pin2, pin, 2*XCHAL_BBEN_SIMD_WIDTH);

    RSDK_MAG2N_2XF32_V1(min_magn, pin1, pin2, scratch1, scratch2);

    for (iElem = 1UL; iElem < size; iElem++)
    {
        prev_min_magn = min_magn;
        BBE_LVN_2XF32_IP(pin1, pin, 2*XCHAL_BBEN_SIMD_WIDTH);
        BBE_LVN_2XF32_IP(pin2, pin, 2*XCHAL_BBEN_SIMD_WIDTH);

        RSDK_MAG2N_2XF32_V1(tempMagn, pin1, pin2, scratch1, scratch2);

        min_magn = BBE_MINN_2XF32(min_magn, tempMagn);
        detect_min = (vboolN_2)(prev_min_magn == min_magn);
        min_id = BBE_MOVN_2XF32T(min_id, (xb_vecN_2xf32)(iElem), detect_min);
    }
    *pout = xb_vecN_2xf32_rtor_xb_vecN_2x32Uv(min_id);
}

void Rsdk_LA_max_Sou32p8Vif32p8(xb_vecN_2x32Uv * __restrict pOutput,
                                           xb_vecN_2xf32  * pInput,
                                                   uint32_t size)
{
    xb_vecN_2x32Uv * pout = pOutput;
    xb_vecN_2xf32 * pin   = pInput;

    xb_vecN_2xf32 max_id = BBE_ZERON_2XF32();
    xb_vecN_2xf32 prev_max_val, max_val = *pin;
    vboolN_2 detect_max;
    uint32_t iElem;

    pin++;
    for (iElem = 1UL; iElem < size; iElem++)
    {
        prev_max_val = max_val;
        max_val = BBE_MAXN_2XF32(max_val, *pin);
        detect_max = (vboolN_2)(prev_max_val == max_val);
        max_id = BBE_MOVN_2XF32T(max_id, (xb_vecN_2xf32)(iElem), detect_max);
        pin++;
    }
    *pout = xb_vecN_2xf32_rtor_xb_vecN_2x32Uv(max_id);
}

void Rsdk_LA_maxAbs_Sou32p8Vif32cp8(xb_vecN_2x32Uv * __restrict pOutput,
                                              xb_vecN_2xcf32  * pInput,
                                                       uint32_t size)
{
    xb_vecN_2x32Uv * pout = pOutput;
    xb_vecN_2xf32 const * pin = (xb_vecN_2xf32 const *)(uintptr_t)&pInput[0];

    xb_vecN_2xf32 max_id = BBE_ZERON_2XF32();
    xb_vecN_2xf32 prev_max_magn, max_magn, tempMagn;
    xb_vecN_2xf32 scratch1, scratch2, pin1, pin2;
    vboolN_2 detect_max;
    uint32_t iElem;

    BBE_LVN_2XF32_IP(pin1, pin, 2*XCHAL_BBEN_SIMD_WIDTH);
    BBE_LVN_2XF32_IP(pin2, pin, 2*XCHAL_BBEN_SIMD_WIDTH);

    RSDK_MAG2N_2XF32_V1(max_magn, pin1, pin2, scratch1, scratch2);

    for (iElem = 1UL; iElem < size; iElem++)
    {
        prev_max_magn = max_magn;
        BBE_LVN_2XF32_IP(pin1, pin, 2*XCHAL_BBEN_SIMD_WIDTH);
        BBE_LVN_2XF32_IP(pin2, pin, 2*XCHAL_BBEN_SIMD_WIDTH);

        RSDK_MAG2N_2XF32_V1(tempMagn, pin1, pin2, scratch1, scratch2);

        max_magn = BBE_MAXN_2XF32(max_magn, tempMagn);
        detect_max = (vboolN_2)(prev_max_magn == max_magn);
        max_id = BBE_MOVN_2XF32T(max_id, (xb_vecN_2xf32)(iElem), detect_max);
    }
    *pout = xb_vecN_2xf32_rtor_xb_vecN_2x32Uv(max_id);
}

#ifdef __cplusplus
}
#endif

/*******************************************************************************
* EOF
******************************************************************************/


