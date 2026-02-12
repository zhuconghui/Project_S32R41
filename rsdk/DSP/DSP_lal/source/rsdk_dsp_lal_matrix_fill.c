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
* @file           rsdk_dsp_lal_matrix_fill.c
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

void Rsdk_EF_fillZeros_Mof32p8(xb_vecN_2xf32 * pOutput,
                                      uint32_t rows,
                                      uint32_t cols)
{
	xb_vecN_2xf32 * pout  = pOutput;
	
    uint32_t iElem;

    for(iElem = 0UL; iElem < (rows * cols); iElem++)
    {
        *pout = BBE_ZERON_2XF32();
        pout++;
    }
}

void Rsdk_EF_fillZeros_Mof32cp8(xb_vecN_2xcf32 * pOutput,
                                        uint32_t rows,
                                        uint32_t cols)
{
	xb_vecN_2xcf32 * pout  = pOutput;
	
    uint32_t iElem;

    for(iElem = 0UL; iElem < (rows * cols); iElem++)
    {
        *pout = BBE_ZERON_2XCF32();
        pout++;
    }
}

void Rsdk_EF_identity_Mof32p8(xb_vecN_2xf32 * pOutput,
                                     uint32_t size)
{
    xb_vecN_2xf32 * pout = pOutput;
	
    uint32_t index = 0UL;
    uint32_t elem  = size*size;

    for(index = 0UL; index < elem; index++ )
    {
        *pout = BBE_ZERON_2XF32();
        pout++;
    }

    pout = pOutput;
    for(index = 0UL; index < size; index++)
    {
        *pout = (xb_vecN_2xf32)1L;
        pout += size + 1UL;
    }
}

void Rsdk_EF_identity_Mof32cp8(xb_vecN_2xcf32 * pOutput,
                                       uint32_t size)
{
    xb_vecN_2xcf32 * pout = pOutput;
	
    uint32_t index = 0UL;
    uint32_t elem  = size*size;

    for(index = 0UL; index < elem; index++)
    {
        *pout = BBE_ZERON_2XCF32();
        pout++;
    }

    pout = pOutput;
    for(index = 0UL; index < size; index++)
    {
        *pout = BBE_CMPLXN_2XF32((xb_vecN_2xf32)0L, (xb_vecN_2xf32)1L);
        pout += size + 1UL;
    }
}

void Rsdk_EF_fillZerosDg_Mof32p8Sif32p8(xb_vecN_2xf32 * pOutput,
                                  xb_vecN_2xf32 const * pInput,
                                               uint32_t size)
{
    xb_vecN_2xf32 * pout = pOutput;
	
    uint32_t index = 0UL;
    uint32_t elem  = size*size;

    for(index = 0UL; index < elem; index++ )
    {
        *pout = BBE_ZERON_2XF32();
        pout++;
    }

    pout = pOutput;
    for(index = 0UL; index < size; index++)
    {
        *pout = *pInput;
        pout += size + 1UL;
    }
}

void Rsdk_EF_fillZerosDg_Mof32cp8Sif32cp8(xb_vecN_2xcf32 * pOutput,
                                    xb_vecN_2xcf32 const * pInput,
                                                  uint32_t size)
{
    xb_vecN_2xcf32 * pout = pOutput;
	
    uint32_t index = 0UL;
    uint32_t elem  = size*size;

    for(index = 0UL; index < elem; index++)
    {
        *pout = BBE_ZERON_2XCF32();
        pout++;
    }

    pout = pOutput;
    for(index = 0UL; index < size; index++)
    {
        *pout = *pInput;
        pout += size + 1UL;
    }
}

void Rsdk_EF_fillZerosDg_Mof32p8Vif32p8(xb_vecN_2xf32 * pOutput,
                                  xb_vecN_2xf32 const * pInput,
                                               uint32_t size)
{
    xb_vecN_2xf32 const * pin  = pInput;
    xb_vecN_2xf32 * pout = pOutput;
	
    uint32_t index = 0UL;
    uint32_t elem  = size*size;

    for(index = 0UL; index < elem; index++ )
    {
        *pout = BBE_ZERON_2XF32();
        pout++;
    }

    pout = pOutput;
    for(index = 0UL; index < size; index++)
    {
        *pout = *pin;
        pout += size + 1UL;
        pin++;
    }
}

void Rsdk_EF_fillZerosDg_Mof32cp8Vif32cp8(xb_vecN_2xcf32 * pOutput,
                                    xb_vecN_2xcf32 const * pInput,
                                                  uint32_t size)
{
    xb_vecN_2xcf32 const * pin = pInput;
    xb_vecN_2xcf32 * pout = pOutput;
	
    uint32_t index = 0UL;
    uint32_t elem  = size*size;

    for(index = 0UL; index < elem; index++)
    {
        *pout = BBE_ZERON_2XCF32();
        pout++;
    }

    pout = pOutput;
    for(index = 0UL; index < size; index++)
    {
        *pout = *pin;
        pout += size + 1UL;
        pin++;
    }
}

#ifdef __cplusplus
}
#endif

/*******************************************************************************
* EOF
******************************************************************************/
