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
* @file           rsdk_dsp_lal_vec_prod.c
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

void Rsdk_LA_cross_Vo3f32p8Vi3f32p8Vi3f32p8(xb_vecN_2xf32 * pOutput,
		                                    xb_vecN_2xf32 * pInput1,
		                                    xb_vecN_2xf32 * pInput2)
{
	xb_vecN_2xf32 * pin1 = pInput1;
	xb_vecN_2xf32 * pin2 = pInput2;
	xb_vecN_2xf32 * pout = pOutput;
	
    xb_vecN_2xf32 op1_1, op1_2, op1_3;
    xb_vecN_2xf32 op2_1, op2_2, op2_3;
    xb_vecN_2xf32 res;


    op1_1 = *pin1;
    pin1++;
    op1_2 = *pin1;
    pin1++;
    op1_3 = *pin1;

    op2_1 = *pin2;
    pin2++;
    op2_2 = *pin2;
    pin2++;
    op2_3 = *pin2;

    res = (op1_2 * op2_3) - (op1_3 * op2_2);
    *pout = res;
    pout++;
    res = (op1_3 * op2_1) - (op1_1 * op2_3);
    *pout = res;
    pout++;
    res = (op1_1 * op2_2) - (op1_2 * op2_1);
    *pout = res;
}


void Rsdk_LA_cross_Vo3f32cp8Vi3f32cp8Vi3f32cp8(xb_vecN_2xcf32 * pOutput,
		                                       xb_vecN_2xcf32 * pInput1,
		                                       xb_vecN_2xcf32 * pInput2)
{
	xb_vecN_2xcf32 * pin1 = pInput1;
	xb_vecN_2xcf32 * pin2 = pInput2;
	xb_vecN_2xcf32 * pout = pOutput;
	
    xb_vecN_2xcf32 op1_1, op1_2, op1_3;
    xb_vecN_2xcf32 op2_1, op2_2, op2_3;
    xb_vecN_2xcf32 res;

    op1_1 = *pin1;
    pin1++;
    op1_2 = *pin1;
    pin1++;
    op1_3 = *pin1;

    op2_1 = *pin2;
    pin2++;
    op2_2 = *pin2;
    pin2++;
    op2_3 = *pin2;

    res = (op1_2 * op2_3) - (op1_3 * op2_2);
    *pout = res;
    pout++;
    res = (op1_3 * op2_1) - (op1_1 * op2_3);
    *pout = res;
    pout++;
    res = (op1_1 * op2_2) - (op1_2 * op2_1);
    *pout = res;
}


void Rsdk_LA_crossconj_Vo3f32cp8Vi3f32cp8Vi3f32cp8(xb_vecN_2xcf32 * pOutput,
		                                           xb_vecN_2xcf32 * pInput1,
		                                           xb_vecN_2xcf32 * pInput2)
{
	xb_vecN_2xcf32 * pin1 = pInput1;
	xb_vecN_2xcf32 * pin2 = pInput2;
	xb_vecN_2xcf32 * pout = pOutput;
	
    xb_vecN_2xcf32 op1_1, op1_2, op1_3;
    xb_vecN_2xcf32 op2_1, op2_2, op2_3;
    xb_vecN_2xcf32 res;

    op1_1 = *pin1;
    pin1++;
    op1_2 = *pin1;
    pin1++;
    op1_3 = *pin1;

    op2_1 = *pin2;
    pin2++;
    op2_2 = *pin2;
    pin2++;
    op2_3 = *pin2;

    res = (op1_2 * op2_3) - (op1_3 * op2_2);
    *pout = BBE_CONJN_2XCF32(res);
    pout++;
    res = (op1_3 * op2_1) - (op1_1 * op2_3);
    *pout = BBE_CONJN_2XCF32(res);
    pout++;
    res = (op1_1 * op2_2) - (op1_2 * op2_1);
    *pout = BBE_CONJN_2XCF32(res);
}


void Rsdk_LA_dot_Sof32p8Vif32p8Vif32p8(xb_vecN_2xf32 * pOutput,
		                               xb_vecN_2xf32 * pInput1,
		                               xb_vecN_2xf32 * pInput2,
		                                      uint32_t size)
{
    xb_vecN_2xf32 * pin1 = pInput1;
	xb_vecN_2xf32 * pin2 = pInput2;
	xb_vecN_2xf32 * pout = pOutput;
	
	uint32_t iElem;
    xb_vecN_2xf32 op1, op2, res;

    res = BBE_ZERON_2XF32();

    for (iElem = 0UL; iElem < size; iElem++)
    {
        op1 = *pin1;
        op2 = *pin2;
        BBE_MULAN_2XF32(res, op1, op2);
        pin1++;
        pin2++;
    }
    *pout = res;
}


void Rsdk_LA_dotFirstConj_Sof32cp8Vif32cp8Vif32cp8(xb_vecN_2xcf32 * pOutput,
                                                   xb_vecN_2xcf32 * pInput1,
                                                   xb_vecN_2xcf32 * pInput2,
                                                           uint32_t size)
{
	xb_vecN_2xcf32 * pin1 = pInput1;
	xb_vecN_2xcf32 * pin2 = pInput2;
	xb_vecN_2xcf32 * pout = pOutput;
	
    uint32_t iElem;
    xb_vecN_2xcf32 op1, op2, res;

    res = BBE_ZERON_2XCF32();

    for (iElem = 0UL; iElem < size; iElem++)
    {
        op1 = BBE_CONJN_2XCF32(*pin1);
        op2 = *pin2;
        res += (op1 * op2);
        pin1++;
        pin2++;
    }
    *pout = res;
}

void Rsdk_LA_dotSecondConj_Sof32cp8Vif32cp8Vif32cp8(xb_vecN_2xcf32 * pOutput,
                                                    xb_vecN_2xcf32 * pInput1,
                                                    xb_vecN_2xcf32 * pInput2,
                                                            uint32_t size)
{
	xb_vecN_2xcf32 * pin1 = pInput1;
	xb_vecN_2xcf32 * pin2 = pInput2;
	xb_vecN_2xcf32 * pout = pOutput;
	
    uint32_t iElem;
    xb_vecN_2xcf32 op1, op2, res;

    res = BBE_ZERON_2XCF32();

    for (iElem = 0UL; iElem < size; iElem++)
    {
        op1 = *pin1;
        op2 = BBE_CONJN_2XCF32(*pin2);
        res += (op1 * op2);
        pin1++;
        pin2++;
    }
    *pout = res;
}

#ifdef __cplusplus
}
#endif

/*******************************************************************************
* EOF
******************************************************************************/
