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
* @file           rsdk_dsp_lal_vec_add.c
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

void Rsdk_LA_add_Vof32p8Vif32p8Vif32p8(xb_vecN_2xf32 * pOutput,
		                               xb_vecN_2xf32 * pInput1,
		                               xb_vecN_2xf32 * pInput2,
		                                      uint32_t size)
{
	xb_vecN_2xf32 * pout = pOutput;
	xb_vecN_2xf32 * pin1 = pInput1;
	xb_vecN_2xf32 * pin2 = pInput2;
	
    uint32_t iElem;

    for (iElem = 0UL; iElem < size; iElem++)
    {
        *pout = *pin1 + *pin2;
        pin1++;
        pin2++;
        pout++;
    }
}

/*
 * TODO to reflect on:
 * using the __restrict qualifier is effective when calling functions from static libraries.
 * Reason: one assumption is that the compiler doesn't inline the functions as it sees overlapping memories
 * -OPT:alias=restrict doesn't change anything
 * However, using __restrict presumably forces the compiler to inline the functions (it is ony a supposition)
 */
void Rsdk_LA_add_Vof32p8Vif32p8Vif32p8_k2(xb_vecN_2xf32 * __restrict pOutput,
		                                             xb_vecN_2xf32 * pInput1,
		                                             xb_vecN_2xf32 * pInput2,
		                                                    uint32_t size)
{
	xb_vecN_2xf32 * pout = pOutput;
	xb_vecN_2xf32 * pin1 = pInput1;
	xb_vecN_2xf32 * pin2 = pInput2;
	
    uint32_t iElem;

    for (iElem = 0UL; iElem < size; iElem++)
    {
        *pout = *pin1 + *pin2;
        pin1++;
        pin2++;
        pout++;
    }
}

void Rsdk_LA_add_Vof32cp8Vif32cp8Vif32cp8(xb_vecN_2xcf32  * pOutput,
		                                  xb_vecN_2xcf32  * pInput1,
		                                  xb_vecN_2xcf32  * pInput2,
		                                           uint32_t size)
{
	xb_vecN_2xcf32 * pout = pOutput;
	xb_vecN_2xcf32 * pin1 = pInput1;
	xb_vecN_2xcf32 * pin2 = pInput2;
	
    uint32_t iElem;

    for (iElem = 0UL; iElem < size; iElem++)
    {
        *pout = *pin1 + *pin2;
        pin1++;
        pin2++;
        pout++;
    }
}

void Rsdk_LA_add_Vof32cp8Vif32cp8Vif32cp8_k2(xb_vecN_2xcf32  * __restrict pOutput,
		                                                xb_vecN_2xcf32  * pInput1,
		                                                xb_vecN_2xcf32  * pInput2,
		                                                         uint32_t size)
{
	xb_vecN_2xcf32 * pout = pOutput;
	xb_vecN_2xcf32 * pin1 = pInput1;
	xb_vecN_2xcf32 * pin2 = pInput2;
	
    uint32_t iElem;

    for (iElem = 0UL; iElem < size; iElem++)
    {
        *pout = *pin1 + *pin2;
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
