/**************************************************************************************************
 * Copyright 2021-2024 NXP
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
* @file           rsdk_dsp_lal_vec_xcorr.c
*/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "rsdk_dsp_lal.h"

#ifdef __cplusplus
extern "C"{
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define max(x,y) (((x)<(y))? (y):(x))
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

void Rsdk_LA_xcorr_Vof32p8Vif32p8Vif32p8(xb_vecN_2xf32 * restrict pOutput,
                                                  xb_vecN_2xf32 * pInput1,
                                                  xb_vecN_2xf32 * pInput2,
                                                         uint32_t size1,
                                                         uint32_t size2)
{
    xb_vecN_2xf32 * pin1 = pInput1;
    xb_vecN_2xf32 * pin2 = pInput2;
    xb_vecN_2xf32 * restrict pout = pOutput;
    xb_vecN_2xf32 tmp = (xb_vecN_2xf32)0.0F;

    uint32_t iElem;
    int32_t jElem;
    uint32_t k, startIdx, outSize;

    outSize = (2UL * max(size1, size2)) - 1UL;

    if (size1 > size2)
    {
        startIdx = size1 - size2;
    }
    else
    {
        startIdx = 0UL;
    }

    for (iElem = 0UL; iElem < outSize; iElem++)
    {
        pout[iElem] = (xb_vecN_2xf32)0.0F;
    }

    for (iElem = 0UL; iElem < size1; iElem++)
    {
        k = startIdx + iElem;
        BBE_LVN_2XF32_IP(tmp, pin1, 32UL);
        for (jElem = ((int32_t)size2 - 1L); jElem >= 0L; (jElem--))
        {
            BBE_MULAN_2XF32(pout[k], tmp, pin2[jElem]);
            k++;
        }
    }
}

void Rsdk_LA_xcorr_Vof32cp8Vif32cp8Vif32cp8(xb_vecN_2xcf32 * restrict pOutput,
                                                     xb_vecN_2xcf32 * pInput1,
                                                     xb_vecN_2xcf32 * pInput2,
                                                             uint32_t size1,
                                                             uint32_t size2)
{
    xb_vecN_2xcf32 * pin1 = pInput1;
    xb_vecN_2xcf32 * pin2 = pInput2;
    xb_vecN_2xcf32 * restrict pout = pOutput;
    xb_vecN_2xcf32 tmp = (xb_vecN_2xcf32)0.0F;

    uint32_t iElem;
    int32_t jElem;
    uint32_t k, startIdx, outSize;

    outSize = (2UL * max(size1, size2)) - 1UL;

    if (size1 > size2)
    {
        startIdx = size1 - size2;
    }
    else
    {
        startIdx = 0UL;
    }

    for (iElem = 0UL; iElem < outSize; iElem++)
    {
        pout[iElem] = (xb_vecN_2xcf32)0.0F;
    }

    for (iElem = 0UL; iElem < size1; iElem++)
    {
        k = startIdx + iElem;
        BBE_LVN_2XCF32_IP(tmp, pin1, 64UL);
        for (jElem = ((int32_t)size2 - 1L); jElem >= 0L; (jElem--))
        {
            BBE_MULJAN_2XCF32(pout[k], tmp, pin2[jElem]);
            k++;
        }
    }
}

#ifdef __cplusplus
}
#endif

/*******************************************************************************
* EOF
******************************************************************************/
