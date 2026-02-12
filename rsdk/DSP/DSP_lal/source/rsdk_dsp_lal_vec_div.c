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
* @file           rsdk_dsp_lal_vec_div.c
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

void Rsdk_LA_div_Vof32p8Vif32p8Vif32p8(xb_vecN_2xf32 * pOutput,
		                               xb_vecN_2xf32 * pInput1,
		                               xb_vecN_2xf32 * pInput2,
		                                      uint32_t size)
{
	xb_vecN_2xf32 * pout = pOutput;
	xb_vecN_2xf32 * pin1 = pInput1;
	xb_vecN_2xf32 * pin2 = pInput2;
	
    uint32_t iElem;
    xb_vecN_2xf32 op1, op2, res;

    for (iElem = 0UL; iElem < size; iElem++)
    {
        op1 = *pin1;
        op2 = *pin2;
        res = BBE_DIVN_2XF32(op1, op2);
        *pout = res;
        pin1++;
        pin2++;
        pout++;
    }
}

void Rsdk_LA_div_Vof32p8Vif32p8Vif32p8_k2(xb_vecN_2xf32 * pOutput,
		                                  xb_vecN_2xf32 * pInput1,
		                                  xb_vecN_2xf32 * pInput2,
		                                         uint32_t size)
{
	xb_vecN_2xf32 * pout = pOutput;
	xb_vecN_2xf32 * pin1 = pInput1;
	xb_vecN_2xf32 * pin2 = pInput2;
		
    uint32_t iElem;
    xb_vecN_2xf32 op1, op2, res;

    for (iElem = 0UL; iElem < size; iElem++)
    {
        op1 = *pin1;
        op2 = *pin2;
        // TO DO investigation to replace BBE_RECIPN_2XF32 that is not IEEE-754 compliant
        res = op1 * BBE_RECIPN_2XF32(op2);
        *pout = res;
        pin1++;
        pin2++;
        pout++;
    }
}

void Rsdk_LA_div_Vof32cp8Vif32cp8Vif32cp8(xb_vecN_2xcf32 * pOutput,
		                                  xb_vecN_2xcf32 * pInput1,
		                                  xb_vecN_2xcf32 * pInput2,
		                                          uint32_t size)
{
	xb_vecN_2xcf32 * pout = pOutput;
	xb_vecN_2xcf32 * pin1 = pInput1;
	xb_vecN_2xcf32 * pin2 = pInput2;
	
    uint32_t iElem;
    xb_vecN_2xcf32 op1, op2, res;

    for (iElem = 0UL; iElem < size; iElem++)
    {
        op1 = *pin1;
        op2 = *pin2;
        res = op1 * BBE_RECIPN_2XCF32(op2);
        *pout = res;
        pin1++;
        pin2++;
        pout++;
    }
}

#ifdef __cplusplus
}
#endif

/*******************************************************************************
* EOF
******************************************************************************/
