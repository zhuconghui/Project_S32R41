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
* @file           rsdk_dsp_lal_vec_copy.c
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

void Rsdk_DT_copy_Vof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
		                         xb_vecN_2xf32 * __restrict pInput,
		                                           uint32_t size)
{
	xb_vecN_2xf32 * pout = pOutput;
	xb_vecN_2xf32 * pin  = pInput;
	
    uint32_t iElem;

    for (iElem = 0UL; iElem < size; iElem++)
    {
        *pout = *pin;
        pin++;
        pout++;
    }
}

void Rsdk_DT_copy_Vof32cp8Vif32cp8(xb_vecN_2xcf32 * __restrict pOutput,
		                           xb_vecN_2xcf32 * __restrict pInput,
		                                              uint32_t size)
{
	xb_vecN_2xcf32 * pout = pOutput;
	xb_vecN_2xcf32 * pin  = pInput;
	
    uint32_t iElem;

    for (iElem = 0UL; iElem < size; iElem++)
    {
        *pout = *pin;
        pin++;
        pout++;
    }
}


void Rsdk_DT_copyOffset_Vof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                 xb_vecN_2xf32 const * __restrict pInput,
                                               uint32_t numElem,
                                               uint32_t outOffset,
                                               uint32_t inOffset)
{
  xb_vecN_2xf32 const * pin  = &pInput[inOffset];
  xb_vecN_2xf32 * pout = &pOutput[outOffset];
  uint32_t i = 0UL;
  
  for(i = 0UL; i< numElem; i++)
  {
    *pout = *pin;
    pin++;
    pout++;
  }
}

void Rsdk_DT_copyOffset_Vof32cp8Vif32cp8(xb_vecN_2xcf32 * __restrict pOutput,
                                   xb_vecN_2xcf32 const * __restrict pInput,
                                                 uint32_t numElem,
                                                 uint32_t outOffset,
                                                 uint32_t inOffset)
{
  xb_vecN_2xcf32 const * pin  = &pInput[inOffset];
  xb_vecN_2xcf32 * pout = &pOutput[outOffset];
  uint32_t i = 0UL;
  
  for(i = 0UL; i< numElem; i++)
  {
    *pout = *pin;
    pin++;
    pout++;
  }
}

void Rsdk_DT_copyInOffset_Vof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                   xb_vecN_2xf32 const * __restrict pInput,
                                                uint32_t numElem,
                                                uint32_t inOffset)
{

  Rsdk_DT_copyOffset_Vof32p8Vif32p8(pOutput, pInput, numElem, 0UL, inOffset);

}

void Rsdk_DT_copyInOffset_Vof32cp8Vif32cp8(xb_vecN_2xcf32 * __restrict pOutput,
                                     xb_vecN_2xcf32 const * __restrict pInput,
                                                   uint32_t numElem,
                                                   uint32_t inOffset)
{

  Rsdk_DT_copyOffset_Vof32cp8Vif32cp8(pOutput, pInput, numElem, 0UL, inOffset);

}

void Rsdk_DT_copyOutOffset_Vof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                    xb_vecN_2xf32 const * __restrict pInput,
                                                 uint32_t numElem,
                                                 uint32_t outOffset)
{

  Rsdk_DT_copyOffset_Vof32p8Vif32p8(pOutput, pInput, numElem, outOffset, 0UL);

}

void Rsdk_DT_copyOutOffset_Vof32cp8Vif32cp8(xb_vecN_2xcf32 * __restrict pOutput,
                                      xb_vecN_2xcf32 const * __restrict pInput,
                                                    uint32_t numElem,
                                                    uint32_t outOffset)
{

  Rsdk_DT_copyOffset_Vof32cp8Vif32cp8(pOutput, pInput, numElem, outOffset, 0UL);

}

#ifdef __cplusplus
}
#endif

/*******************************************************************************
* EOF
******************************************************************************/
