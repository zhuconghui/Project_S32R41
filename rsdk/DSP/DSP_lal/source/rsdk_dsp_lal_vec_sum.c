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
* @file           rsdk_dsp_lal_vec_sum.c
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

void Rsdk_LA_sum_Sof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
								xb_vecN_2xf32 * pInput,
								       uint32_t size)
{
	xb_vecN_2xf32 * pout = pOutput;
	xb_vecN_2xf32 * pin  = pInput;
		
    uint32_t      iElem;
    xb_vecN_2xf32 acc = 0.0F;

    for (iElem = 0UL; iElem < size; iElem++)
    {
        acc += *pin;
        pin++;
    }
    *pout = acc;
}

void Rsdk_LA_sum_Sof32cp8Vif32cp8(xb_vecN_2xcf32 * __restrict pOutput,
		                         xb_vecN_2xcf32  * pInput,
		                                  uint32_t size)
{
	xb_vecN_2xcf32 * pout = pOutput;
	xb_vecN_2xcf32 * pin  = pInput;
		
	uint32_t       iElem;
    xb_vecN_2xcf32 acc = 0.0F;

    for (iElem = 0UL; iElem < size; iElem++)
    {
        acc += *pin;
        pin++;
    }
    *pout = acc;
}

void Rsdk_LA_sum2_Sof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
							     xb_vecN_2xf32 * pInput,
							            uint32_t size)
{
	xb_vecN_2xf32 * pout = pOutput;
	xb_vecN_2xf32 * pin  = pInput;
	
    xb_vecN_2xf32 acc = BBE_ZERON_2XF32();
    uint32_t      iElem;

    for (iElem = 0UL; iElem < size; iElem++)
    {
        acc += ((*pin) * (*pin));
        pin++;
    }
    *pout = acc;
}

void Rsdk_LA_sum2_Sof32cp8Vif32cp8(xb_vecN_2xcf32 * __restrict pOutput,
		                          xb_vecN_2xcf32  * pInput,
		                                   uint32_t size)
{
	xb_vecN_2xcf32 * pout = pOutput;
	xb_vecN_2xcf32 * pin  = pInput;
	
    xb_vecN_2xcf32 acc = BBE_ZERON_2XCF32();
    uint32_t       iElem;

    for (iElem = 0UL; iElem < size; iElem++)
    {
        acc += ((*pin) * (*pin));
        pin++;
    }
    *pout = acc;
}

void Rsdk_LA_sum3_Sof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
							     xb_vecN_2xf32 * pInput,
							            uint32_t size)
{
	xb_vecN_2xf32 * pout = pOutput;
	xb_vecN_2xf32 * pin  = pInput;
	
    xb_vecN_2xf32 acc = BBE_ZERON_2XF32();
    uint32_t      iElem;

    for (iElem = 0UL; iElem < size; iElem++)
    {
        acc += (*pin) * (*pin) * (*pin);
        pin++;
    }
    *pout = acc;
}

void Rsdk_LA_sum3_Sof32cp8Vif32cp8(xb_vecN_2xcf32 * __restrict pOutput,
		                          xb_vecN_2xcf32  * pInput,
		                                   uint32_t size)
{
	xb_vecN_2xcf32 * pout = pOutput;
	xb_vecN_2xcf32 * pin  = pInput;
	
    xb_vecN_2xcf32 acc = BBE_ZERON_2XCF32();
    uint32_t       iElem;

    for (iElem = 0UL; iElem < size; iElem++)
    {
        acc += (*pin) * (*pin) * (*pin);
        pin++;
    }
    *pout = acc;
}

void Rsdk_LA_sumRcp_Sof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                             xb_vecN_2xf32 const * pInput,
                                          uint32_t size)
{
	xb_vecN_2xf32 * pout       = pOutput;
	xb_vecN_2xf32 const * pin  = pInput;
	
    uint32_t count;
    xb_vecN_2xf32 vinv;
    xb_vecN_2xf32 acc = BBE_ZERON_2XF32();

    for (count = 0UL; count < size; count++)
    {
        vinv = BBE_RECIPN_2XF32(*pin);
        acc += vinv;
        pin++;
    }
    *pout = acc;
}

void Rsdk_LA_sumRcp_Sof32cp8Vif32cp8(xb_vecN_2xcf32 * __restrict pOutput,
                               xb_vecN_2xcf32 const * pInput,
                                             uint32_t size)
{
	xb_vecN_2xcf32 * pout       = pOutput;
	xb_vecN_2xcf32 const * pin  = pInput;
	
    uint32_t count;
    xb_vecN_2xcf32 vinv;
    xb_vecN_2xcf32 acc = BBE_ZERON_2XCF32();

    for (count = 0UL; count < size; count++)
    {
        vinv = BBE_RECIPN_2XCF32(*pin);
        acc += vinv;
        pin++;
    }
    *pout = acc;
}

#ifdef __cplusplus
}
#endif

/*******************************************************************************
* EOF
******************************************************************************/
