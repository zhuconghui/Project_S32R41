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
* @file           rsdk_dsp_lal_matrix_lower_triangular_inv.c
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

void Rsdk_LA_invLNs_Mof32p8Mif32p8(xb_vecN_2xf32 * pOutput,
		                           xb_vecN_2xf32 * pInput,
		                                  uint32_t size)
{
	xb_vecN_2xf32 (*inv)[size][size] = (xb_vecN_2xf32 (*)[size][size]) pOutput;
	xb_vecN_2xf32 (*in)[size][size] = (xb_vecN_2xf32 (*)[size][size]) pInput;
	xb_vecN_2xf32 sum;
	int32_t i, j, k;
	int32_t size_s = (int32_t)size;

	for (i = 0L; i < size_s; i++)
	{
		/* reciprocal of the diagonal terms */
		(*inv)[i][i] = BBE_RECIPN_2XF32((*in)[i][i]);
		for (j = i - 1L; j >= 0L; j--)
		{
			sum = BBE_ZERON_2XF32();
			for (k = j + 1L; k <= i; k++)
			{
				sum = sum - ((*inv)[i][k] * (*in)[k][j]);
			}
			(*inv)[i][j] = sum * (*inv)[j][j];
		}
	}
};



void Rsdk_LA_invLNs_Mof32cp8Mif32cp8(xb_vecN_2xcf32 * pOutput,
		                             xb_vecN_2xcf32 * pInput,
		                                     uint32_t size)
{
	xb_vecN_2xcf32 (*inv)[size][size] = (xb_vecN_2xcf32 (*)[size][size]) pOutput;
	xb_vecN_2xcf32 (*in)[size][size] = (xb_vecN_2xcf32 (*)[size][size]) pInput;
	xb_vecN_2xcf32 sum;
	int32_t i, j, k;
	int32_t size_s = (int32_t)size;

	for (i = 0L; i < size_s; i++)
	{
		/* reciprocal of the diagonal terms */
		(*inv)[i][i] = BBE_RECIPN_2XCF32((*in)[i][i]);
		for (j = i - 1L; j >= 0L; j--)
		{
			sum = BBE_ZERON_2XCF32();
			for (k = j + 1L; k <= i; k++)
			{
				sum = sum - ((*inv)[i][k] * (*in)[k][j]);
			}
			(*inv)[i][j] = sum * (*inv)[j][j];
		}
	}
};


void Rsdk_LA_invRectLNs_Mof32p8Mif32p8(xb_vecN_2xf32 * __restrict pOutput,
		                               xb_vecN_2xf32 * pInput,
		                                      uint32_t rows,
											  uint32_t cols)
{
	xb_vecN_2xf32 (*inv)[cols][rows] = (xb_vecN_2xf32 (*)[cols][rows]) pOutput;
	xb_vecN_2xf32 (*in)[rows][cols] = (xb_vecN_2xf32 (*)[rows][cols]) pInput;
	xb_vecN_2xf32 * pin1;
	xb_vecN_2xf32 * pin2;
	xb_vecN_2xf32 sum, op1, op2;
	int32_t i, j, k;
	int32_t size_s = (int32_t)rows;

    #pragma loop_count min = 2, max = 63
	for (i = 0L; i < size_s; i++)
	{
		/* reciprocal of the diagonal terms */
		(*inv)[i][i] = BBE_RECIPN_2XF32((*in)[i][i]);
		for (j = i - 1L; j >= 0L; j--)
		{
			sum = BBE_ZERON_2XF32();
			for (k = j + 1L; k <= i; k++)
			{
			    pin1 = &((*inv)[i][k]);
				pin2 = &((*in)[k][j]);
				op1 = BBE_LVN_2XF32_I(pin1, 0);
				op2 = BBE_LVN_2XF32_I(pin2, 0);
				BBE_MULAN_2XF32(sum, op1, op2);
			}
			sum = BBE_NEGN_2XF32(sum);
			(*inv)[i][j] = sum * (*inv)[j][j];
		}
	}
};


void Rsdk_LA_invRectLNs_Mof32cp8Mif32cp8(xb_vecN_2xcf32 * __restrict pOutput,
		                                 xb_vecN_2xcf32 * pInput,
		                                        uint32_t rows,
											    uint32_t cols)
{
	xb_vecN_2xcf32 (*inv)[cols][rows] = (xb_vecN_2xcf32 (*)[cols][rows]) pOutput;
	xb_vecN_2xcf32 (*in)[rows][cols] = (xb_vecN_2xcf32 (*)[rows][cols]) pInput;
	xb_vecN_2xcf32 * pin1;
	xb_vecN_2xcf32 * pin2;
	xb_vecN_2xcf32 sum, op1, op2;
	int32_t i, j, k;
	int32_t size_s = (int32_t)rows;

	#pragma loop_count min = 2, max = 45
	for (i = 0L; i < size_s; i++)
	{
		/* reciprocal of the diagonal terms */
		(*inv)[i][i] = BBE_RECIPN_2XCF32((*in)[i][i]);
		for (j = i - 1L; j >= 0L; j--)
		{
			sum = BBE_ZERON_2XCF32();
			for (k = j + 1L; k <= i; k++)
			{
				pin1 = &((*inv)[i][k]);
				pin2 = &((*in)[k][j]);
				op1 = BBE_LVN_2XCF32_I(pin1, 0);
				op2 = BBE_LVN_2XCF32_I(pin2, 0);
				BBE_MULAN_2XCF32(sum, op1, op2);
			}
			sum = BBE_NEGN_2XCF32(sum);
			(*inv)[i][j] = sum * (*inv)[j][j];
		}
	}
};

#ifdef __cplusplus
}
#endif

/*******************************************************************************
* EOF
******************************************************************************/
