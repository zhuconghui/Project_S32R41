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
* @file           rsdk_dsp_lal_vec_fill.c
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

void Rsdk_EF_fillZeros_Vof32p8(xb_vecN_2xf32 * pOutput,
                                      uint32_t size)
{
	xb_vecN_2xf32 * pout = pOutput;
	
    uint32_t iElem;

    for (iElem = 0UL; iElem < size; iElem++)
    {
        *pout = BBE_ZERON_2XF32();
        pout++;
    }
}

void Rsdk_EF_fillZeros_Vof32cp8(xb_vecN_2xcf32 * pOutput,
                                        uint32_t size)
{
	xb_vecN_2xcf32 * pout = pOutput;
	
    uint32_t iElem;

    for (iElem = 0UL; iElem < size; iElem++)
    {
        *pout = BBE_ZERON_2XCF32();
        pout++;
    }
}

void Rsdk_EF_fill_Vof32p8Sif32(xb_vecN_2xf32 * pOutput,
                             float32_t const * pInput,
                                      uint32_t size)
{
    xb_vecN_2xf32 * pout = pOutput;
    float32_t const pin = *pInput;

    uint32_t index;

    for(index = 0UL; index < size; index++ )
    {
        *pout = (xb_vecN_2xf32)pin;
        pout++;
    }
}

void Rsdk_EF_fill_Vof32cp8Sif32c(xb_vecN_2xcf32 * pOutput,
                           xtcomplexfloat const * pInput,
                                         uint32_t size)
{
    xb_vecN_2xcf32 * pout = pOutput;
    uint32_t index;

    for(index = 0UL; index < size; index++)
    {
        *pout = BBE_CMPLXN_2XF32(BBE_CIMAGN_2XCF32((xb_vecN_2xcf32)*pInput), BBE_CREALN_2XCF32((xb_vecN_2xcf32)*pInput));
        pout++;
    }
}

void Rsdk_EF_fill_Vof32p8Sif32p8(xb_vecN_2xf32 * pOutput,
                           xb_vecN_2xf32 const * pInput,
                                        uint32_t size)
{
    xb_vecN_2xf32 * pout = pOutput;
    uint32_t index;

    for(index = 0UL; index < size; index++ )
    {
        *pout = *pInput;
        pout++;
    }
}

void Rsdk_EF_fill_Vof32cp8Sif32cp8(xb_vecN_2xcf32 * pOutput,
                             xb_vecN_2xcf32 const * pInput,
                                           uint32_t size)
{
    xb_vecN_2xcf32 * pout = pOutput;
    uint32_t index;

    for(index = 0UL; index < size; index++)
    {
        *pout = *pInput;
        pout++;
    }
}

void Rsdk_SP_fillStgRadix2_Vof32cp8(xb_vecN_2xcf32 * pOutput, uint32_t stage)
{
    uint32_t k;
    uint32_t elem_num = 1UL << stage; // 2^stage
    xb_vecN_2xcf32 * pout = pOutput;
    xb_vecN_2xf32 sine_a, cosine_a;
    xb_vecN_2xf32 angle, angle2;
    vboolN_2 xltmpiover2, xgtpiover2;
    const xb_vecN_2xf32 a1 = 9.999999947E-01F;
    const xb_vecN_2xf32 a3 = -1.666665670E-01F;
    const xb_vecN_2xf32 a5 = 8.333025174E-03F;
    const xb_vecN_2xf32 a7 = -1.980741431E-04F;
    const xb_vecN_2xf32 a9 = 2.601886907E-06F;

    for(k = 0UL ; k < elem_num ; k++)
    {
    // COMPUTING SINE
        // computing sin(angle) as -sin(angle+pi)
        // range -2pi <= angle <= 0 -> -pi <= angle+pi <= pi
        angle = (xb_vecN_2xf32)(((-2.0F*(SP_pi*(float32_t)k))/(float32_t)elem_num) + SP_pi);

        // set flags
        xltmpiover2 = (vboolN_2)(angle < (xb_vecN_2xf32)(-SP_pi_over_2));
        xgtpiover2 = (vboolN_2)(angle > (xb_vecN_2xf32)SP_pi_over_2);

        // mapping angle from range -pi <= angle <= pi to range -pi/2 <= x <= pi/2
        BBE_ADDN_2XF32T(angle, angle, (xb_vecN_2xf32)SP_pi, xltmpiover2);
        BBE_SUBN_2XF32T(angle, angle, (xb_vecN_2xf32)SP_pi, xgtpiover2);

        // compute sin(angle) for angle in range -pi/2 <= angle <= pi/2
        angle2 = BBE_MULN_2XF32(angle, angle);
        sine_a = angle * (a1 + (angle2 * (a3 + (angle2 * (a5 + (angle2 * (a7 + (angle2 * a9))))))));

        // correct sign for angle in range -3*pi/2 <= angle <= -pi/2
        BBE_NEGN_2XF32T(sine_a, sine_a, xltmpiover2);
        BBE_NEGN_2XF32T(sine_a, sine_a, xgtpiover2);

    // COMPUTING COSINE
        // computing cos(angle) as sin(angle + pi/2)
        // range -2pi <= angle <= 0 -> -3*pi/2 < angle+pi/2 < pi/2
        angle = (xb_vecN_2xf32)(((-2.0F*(SP_pi*(float32_t)k))/(float32_t)elem_num) + SP_pi_over_2);

        // set flags
        xltmpiover2 = (vboolN_2)(angle < (xb_vecN_2xf32)(-SP_pi_over_2));

        // mapping angle from range -3*pi/2 <= angle <= -pi/2 to range -pi/2 <= x <= pi/2
        BBE_ADDN_2XF32T(angle, angle, (xb_vecN_2xf32)SP_pi, xltmpiover2);

        // compute sin(angle) for angle in range -pi/2 <= x <= pi/2
        angle2 = BBE_MULN_2XF32(angle, angle);
        cosine_a = angle * (a1 + (angle2 * (a3 + (angle2 * (a5 + (angle2 * (a7 + (angle2 * a9))))))));

        // correct sign for angle in range -3*pi/2 <= angle <= -pi/2
        BBE_NEGN_2XF32T(cosine_a, cosine_a, xltmpiover2);

        *pout = BBE_CMPLXN_2XF32(-sine_a, cosine_a);
        pout++;
    }
}

#ifdef __cplusplus
}
#endif

/*******************************************************************************
* EOF
******************************************************************************/
