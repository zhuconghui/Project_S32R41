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
* @file           rsdk_dsp_lal_vec_log.c
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

void Rsdk_EF_log_Vof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
		                                   xb_vecN_2xf32 * pInput,
		                                          uint32_t size)
{
    xb_vecN_2xf32 * pin  = pInput;
	xb_vecN_2xf32 * pout = pOutput;
    xb_vecN_2xf32 x;
    xb_vecNx16 ix;
    xb_vecN_2xf32 delta;
    xb_vecN_2xf32 ln;
    xb_vecN_2xf32 exponent;
    const xb_vecNx16 expMask = EXP_MASK;
    const xb_vecNx16 mantissaMask = MANTISSA_MASK;
    const xb_vecN_2xf32 a1 = 0.99744420F;
    const xb_vecN_2xf32 a2 = -0.47128390F;
    const xb_vecN_2xf32 a3 = 0.22566850F;
    const xb_vecN_2xf32 a4 = -0.05875270F;
    const xb_vecN_2xf32 log2tologe = 0.69314718F;
    const xb_vecN_2xf32 exponentBias = 127.0F;
    vboolN_2 flags;
    uint32_t iElem;

    for (iElem = 0UL; iElem < size; iElem++)
    {
        x = *pin;
        ix = BBE_MOVNX16_FROMN_2XF32(x);
        exponent = BBE_FLOATN_2X32(BBE_MOVN_2X32_FROMNX16(ix & expMask), 23);
        delta = BBE_FLOATN_2X32(BBE_MOVN_2X32_FROMNX16(ix & mantissaMask), 23);
        ln = delta * (a1 + (delta * (a2 + (delta * (a3 + (delta * a4))))));
        ln += (exponent - exponentBias) * log2tologe;
        flags = (vboolN_2)( exponent == (xb_vecN_2xf32)0.0F );
        BBE_NEGN_2XF32T(ln, INFINITY_SP, flags);
        flags = (vboolN_2)( x < (xb_vecN_2xf32)0.0F );
        BBE_NEGN_2XF32T(ln, NAN_SP, flags);

        *pout = ln;
        pin++;
        pout++;
    }
}

void Rsdk_EF_log2_Vof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
		                                    xb_vecN_2xf32 * pInput,
		                                           uint32_t size)
{
	xb_vecN_2xf32 * pin  = pInput;
	xb_vecN_2xf32 * pout = pOutput;
    const xb_vecN_2xf32 logtolog2 = 1.4426950F;
    uint32_t iElem;

    Rsdk_EF_log_Vof32p8Vif32p8(pout, pin, size);

    for (iElem = 0UL; iElem < size; iElem++)
    {
        *pout = (*pout) * logtolog2;
        pout++;
    }
}

void Rsdk_EF_log10_Vof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
		                                     xb_vecN_2xf32 * pInput,
		                                            uint32_t size)
{
    xb_vecN_2xf32 * pin  = pInput;
	xb_vecN_2xf32 * pout = pOutput;
    const xb_vecN_2xf32 logtolog10 = 0.43429448F;
    uint32_t iElem;

    Rsdk_EF_log_Vof32p8Vif32p8(pout, pin, size);

    for (iElem = 0UL; iElem < size; iElem++)
    {
        *pout = (*pout) * logtolog10;
        pout++;
    }
}

#ifdef __cplusplus
}
#endif

/*******************************************************************************
* EOF
******************************************************************************/

