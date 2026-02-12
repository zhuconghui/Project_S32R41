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
* @file           rsdk_dsp_lal_matrix_mul.c
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

void Rsdk_LA_mul_Mof32p8Mif32p8Mif32p8(xb_vecN_2xf32 * __restrict pOutput,
		                                          xb_vecN_2xf32 * pInput1,
		                                          xb_vecN_2xf32 * pInput2,
		                                                 uint32_t in1h,
		                                                 uint32_t in1w,
		                                                 uint32_t in2w)
{
	xb_vecN_2xf32 * pout = pOutput;
	xb_vecN_2xf32 * pin1 = pInput1;
	xb_vecN_2xf32 * pin2 = pInput2;
	uint32_t iLin, iCol, iElem;

	Rsdk_EF_fillZeros_Mof32p8(pout, in1h, in2w);

	for(iElem = 0U; iElem < in1w; iElem++)
	{
		pout = pOutput;
		pin1 = &pInput1[iElem];
		for(iLin = 0U; iLin < in1h; iLin++)
		{
			pin2 = &pInput2[iElem * in2w];
			for(iCol = 0U; iCol < in2w; iCol++)
			{
				*pout += ((*pin1) * (*pin2));
				pout++;
				pin2++;
			}
			pin1 += in1w;
		}
	}
}

void Rsdk_LA_mul_Mof32cp8Mif32cp8Mif32cp8(xb_vecN_2xcf32 * __restrict pOutput,
		                                             xb_vecN_2xcf32 * pInput1,
		                                             xb_vecN_2xcf32 * pInput2,
		                                                     uint32_t in1h,
		                                                     uint32_t in1w,
		                                                     uint32_t in2w)
{
	/* matrix multiplication using the kij order */
	xb_vecN_2xcf32 * pout = pOutput;
	xb_vecN_2xcf32 * pin1 = pInput1;
	xb_vecN_2xcf32 * pin2 = pInput2;
	uint32_t iLin, iCol, iElem;

	Rsdk_EF_fillZeros_Mof32cp8(pout, in1h, in2w);

	for(iElem = 0U; iElem < in1w; iElem++)
	{
		pout = pOutput;
		pin1 = &pInput1[iElem];
		for(iLin = 0U; iLin < in1h; iLin++)
		{
			pin2 = &pInput2[iElem * in2w];
			for(iCol = 0U; iCol < in2w; iCol++)
			{
				*pout += ((*pin1) * (*pin2));
				pout++;
				pin2++;
			}
			pin1 += in1w;
		}
	}
}

void Rsdk_LA_mulSecondT_Mof32p8Mif32p8Mif32p8(xb_vecN_2xf32 * pOutput,
		                                      xb_vecN_2xf32 * pInput1,
		                                      xb_vecN_2xf32 * pInput2,
		                                             uint32_t in1h,
		                                             uint32_t in1w,
		                                             uint32_t in2w)
{
	xb_vecN_2xf32 (*pout)[in1h][in2w] = (xb_vecN_2xf32 (*)[in1h][in2w]) pOutput;
	xb_vecN_2xf32 (*pin1)[in1h][in1w] = (xb_vecN_2xf32 (*)[in1h][in1w]) pInput1;
	xb_vecN_2xf32 (*pin2)[in2w][in1w] = (xb_vecN_2xf32 (*)[in2w][in1w]) pInput2;
	uint32_t iLin, iCol, iElem;

	Rsdk_EF_fillZeros_Mof32p8((xb_vecN_2xf32 *)pout, in1h, in2w);

	for(iElem = 0U; iElem < in1w; iElem++)
	{
		for(iLin = 0U; iLin < in1h; iLin++)
		{
			for(iCol = 0U; iCol < in2w; iCol++)
			{
				(*pout)[iLin][iCol] += ((*pin1)[iLin][iElem] * (*pin2)[iCol][iElem]);
			}
		}
	}
}

void Rsdk_LA_mulSecondH_Mof32cp8Mif32cp8Mif32cp8(xb_vecN_2xcf32 * pOutput,
		                                         xb_vecN_2xcf32 * pInput1,
		                                         xb_vecN_2xcf32 * pInput2,
		                                                 uint32_t in1h,
		                                                 uint32_t in1w,
		                                                 uint32_t in2w)
{
	xb_vecN_2xcf32 (*pout)[in1h][in2w] = (xb_vecN_2xcf32 (*)[in1h][in2w]) pOutput;
	xb_vecN_2xcf32 (*pin1)[in1h][in1w] = (xb_vecN_2xcf32 (*)[in1h][in1w]) pInput1;
	xb_vecN_2xcf32 (*pin2)[in2w][in1w] = (xb_vecN_2xcf32 (*)[in2w][in1w]) pInput2;
	uint32_t iLin, iCol, iElem;

	Rsdk_EF_fillZeros_Mof32cp8((xb_vecN_2xcf32 *)pout, in1h, in2w);

	for(iElem = 0U; iElem < in1w; iElem++)
	{
		for(iLin = 0U; iLin < in1h; iLin++)
		{
			for(iCol = 0U; iCol < in2w; iCol++)
			{
				(*pout)[iLin][iCol] += ((*pin1)[iLin][iElem] * BBE_CONJN_2XCF32((*pin2)[iCol][iElem]));
			}
		}
	}
}
#ifdef __cplusplus
}
#endif

/*******************************************************************************
* EOF
******************************************************************************/
