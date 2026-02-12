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
* @file           rsdk_dsp_lal_vec_sort.c
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

void Rsdk_AU_sortdOET_Vof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                                xb_vecN_2xf32 * pInput,
                                                       uint32_t size)
{
	uint32_t      stage, i;
	xb_vecN_2xf32 tmp;
	xb_vecN_2xf32 *out_ptr;
	/* copy input to output area */
	Rsdk_DT_copy_Vof32p8Vif32p8(pOutput, pInput, size);
    for(stage = 0UL; stage <= (size >> 1UL); stage++)
    {
    	out_ptr = pOutput;
    	out_ptr++;
        /* sort odd indexed elements */
    	for (i = 1UL; i <= (size - 2UL); i = i + 2UL)
    	{
    		/* out_ptr[i]     <- maximum(out_ptr[i], out_ptr[i + 1])
    		 * out_ptr[i + 1] <- minimum(out_ptr[i], out_ptr[i + 1])
    		 * */
    		tmp              = *out_ptr;
    		*out_ptr         = BBE_MAXN_2XF32((*out_ptr), *(out_ptr + 1UL));
    		*(out_ptr + 1UL) = BBE_MINN_2XF32(tmp, *(out_ptr + 1UL));
    		out_ptr += 2UL;
    	}
    	out_ptr = pOutput;
    	/* sort even indexed elements */
    	for (i = 0UL; i <= (size - 2UL); i = i + 2UL)
    	{
    		/* out_ptr[i]     <- maximum(out_ptr[i], out_ptr[i + 1])
    		 * out_ptr[i + 1] <- minimum(out_ptr[i], out_ptr[i + 1])
    		 * */
    		tmp              = *out_ptr;
    		*out_ptr         = BBE_MAXN_2XF32((*out_ptr), *(out_ptr + 1UL));
    		*(out_ptr + 1UL) = BBE_MINN_2XF32(tmp, *(out_ptr + 1UL));
    		out_ptr += 2UL;
    	}
    }
}

void Rsdk_AU_sortOET_Vof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                               xb_vecN_2xf32 * pInput,
                                                      uint32_t size)
{
	uint32_t      stage, i;
	xb_vecN_2xf32 tmp;
	xb_vecN_2xf32 * out_ptr = (xb_vecN_2xf32 *)pOutput;
	/* copy input to output area */
	Rsdk_DT_copy_Vof32p8Vif32p8(pOutput, pInput, size);
    for (stage = 0UL; stage <= (size >> 1UL); stage++)
    {
    	out_ptr = pOutput;
    	out_ptr++;
    	/* sort odd indexed elements */
    	for (i = 1UL; i <= (size - 2UL); i = i + 2UL)
    	{
    		/* out_ptr[i]     <- minimum(out_ptr[i], out_ptr[i + 1])
    		 * out_ptr[i + 1] <- maximum(out_ptr[i], out_ptr[i + 1])
    		 * */
    		tmp              = *out_ptr;
    		*out_ptr         = BBE_MINN_2XF32((*out_ptr), *(out_ptr + 1UL));
    		*(out_ptr + 1UL) = BBE_MAXN_2XF32(tmp, *(out_ptr + 1UL));
    		out_ptr += 2UL;
    	}
    	out_ptr = pOutput;
    	/* sort even indexed elements */
    	for (i = 0UL; i <= (size - 2UL); i = i + 2UL)
    	{
    		/* out_ptr[i]     <- minimum(out_ptr[i], out_ptr[i + 1])
    		 * out_ptr[i + 1] <- maximum(out_ptr[i], out_ptr[i + 1])
    		 * */
    		tmp              = *out_ptr;
    		*out_ptr         = BBE_MINN_2XF32((*out_ptr), *(out_ptr + 1UL));
    		*(out_ptr + 1UL) = BBE_MAXN_2XF32(tmp, *(out_ptr + 1UL));
    		out_ptr += 2UL;
    	}
    }
}

void Rsdk_AU_sortdOET_Viof32p8_k2(xb_vecN_2xf32 * pInOut,
                                         uint32_t size)
{
	uint32_t      stage, i;
	xb_vecN_2xf32 tmp;
	xb_vecN_2xf32 * sol_ptr = (xb_vecN_2xf32 * )pInOut;

    for(stage = 0UL; stage <= (size >> 1UL); stage++)
    {
    	sol_ptr = pInOut;
    	sol_ptr++;
        /* sort odd indexed elements */
    	for (i = 1UL; i <= (size - 2UL); i = i + 2UL)
    	{
    		/* sol_ptr[i]     <- maximum(sol_ptr[i], sol_ptr[i + 1])
    		 * sol_ptr[i + 1] <- minimum(sol_ptr[i], sol_ptr[i + 1])
    		 * */
    		tmp              = *sol_ptr;
    		*sol_ptr         = BBE_MAXN_2XF32((*sol_ptr), *(sol_ptr + 1UL));
    		*(sol_ptr + 1UL) = BBE_MINN_2XF32(tmp, *(sol_ptr + 1UL));
    		sol_ptr += 2UL;
    	}
    	sol_ptr = pInOut;
    	/* sort even indexed elements */
    	for (i = 0UL; i <= (size - 2UL); i = i + 2UL)
    	{
    		/* sol_ptr[i]     <- maximum(sol_ptr[i], sol_ptr[i + 1])
    		 * sol_ptr[i + 1] <- minimum(sol_ptr[i], sol_ptr[i + 1])
    		 * */
    		tmp              = *sol_ptr;
    		*sol_ptr         = BBE_MAXN_2XF32((*sol_ptr), *(sol_ptr + 1UL));
    		*(sol_ptr + 1UL) = BBE_MINN_2XF32(tmp, *(sol_ptr + 1UL));
    		sol_ptr += 2UL;
    	}
    }
}

void Rsdk_AU_sortOET_Viof32p8_k2(xb_vecN_2xf32 * pInOut,
		                                uint32_t size)
{
	uint32_t      stage, i;
	xb_vecN_2xf32 tmp;
	xb_vecN_2xf32 *sol_ptr;

    for (stage = 0UL; stage <= (size >> 1UL); stage++)
    {
    	sol_ptr = pInOut;
    	sol_ptr++;
    	/* sort odd indexed elements */
    	for (i = 1UL; i <= (size - 2UL); i = i + 2UL)
    	{
    		/* sol_ptr[i]     <- minimum(sol_ptr[i], sol_ptr[i + 1])
    		 * sol_ptr[i + 1] <- maximum(sol_ptr[i], sol_ptr[i + 1])
    		 * */
    		tmp              = *sol_ptr;
    		*sol_ptr         = BBE_MINN_2XF32((*sol_ptr), *(sol_ptr + 1UL));
    		*(sol_ptr + 1UL) = BBE_MAXN_2XF32(tmp, *(sol_ptr + 1UL));
    		sol_ptr += 2UL;
    	}
    	sol_ptr = pInOut;
    	/* sort even indexed elements */
    	for (i = 0UL; i <= (size - 2UL); i = i + 2UL)
    	{
    		/* sol_ptr[i]     <- minimum(sol_ptr[i], sol_ptr[i + 1])
    		 * sol_ptr[i + 1] <- maximum(sol_ptr[i], sol_ptr[i + 1])
    		 * */
    		tmp              = *sol_ptr;
    		*sol_ptr         = BBE_MINN_2XF32((*sol_ptr), *(sol_ptr + 1UL));
    		*(sol_ptr + 1UL) = BBE_MAXN_2XF32(tmp, *(sol_ptr + 1UL));
    		sol_ptr += 2UL;
    	}
    }
}

void Rsdk_DT_minMax_Vof32p8Vof32p8Vif32p8Vif32p8(xb_vecN_2xf32 * pOutput1,
                                                 xb_vecN_2xf32 * pOutput2,
                                                 xb_vecN_2xf32 * pInput1,
                                                 xb_vecN_2xf32 * pInput2,
                                                 uint32_t size)
{
	xb_vecN_2xf32 * pin1  = pInput1;
	xb_vecN_2xf32 * pin2  = pInput2;
	xb_vecN_2xf32 * pout1 = pOutput1;
	xb_vecN_2xf32 * pout2 = pOutput2;
	
	uint32_t iElem;
	for (iElem = 0UL; iElem < size; iElem++)
	{
		*pout1 = BBE_MINN_2XF32(*pin1, *pin2);
		*pout2 = BBE_MAXN_2XF32(*pin1, *pin2);
		pout1++;
		pout2++;
		pin1++;
		pin2++;
	}
}

#ifdef __cplusplus
}
#endif

/*******************************************************************************
* EOF
******************************************************************************/

