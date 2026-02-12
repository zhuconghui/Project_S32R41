/*
 * Copyright 2016,2019-2022 NXP
 * NXP Confidential. This software is owned or controlled by NXP and may only
 * be used strictly in accordance with the applicable license terms. By
 * expressly accepting such terms or by downloading, installing, activating
 * and/or otherwise using the software, you are agreeing that you have read,
 * and that you agree to comply with and are bound by, such license terms. If
 * you do not agree to be bound by the applicable license terms, then you may
 * not retain, install, activate or otherwise use the software.
 */

/**
@file bc_adc.c

@version

@brief Barracuda API code file

This is the code file for Barracuda APIs. All exported API code can be found in
this file.

*/


#include <stdint.h>

#include "bc_types.h"
#include "bc_err.h"

#include "bc_adc.h"

#ifdef TEF82XX_CFG_ES2 
#include "hal_es2_adc.h"
#endif

#if defined(__cplusplus)
extern "C"
{
#endif

BC_ERRCODE BC_ADC_PowerOn(BOOL EnADC12, BOOL EnADC34)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_ADC_PowerOn(EnADC12, EnADC34);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_ADC_ConfigBackgroundCal(SYS_IPNum_e ADCNum, BOOL EnBackgroundCal, ADC_BackGroundCal_t *pBackgroundCalControl)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_ADC_ConfigBackgroundCal(ADCNum, EnBackgroundCal, pBackgroundCalControl);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_ADC_ConfigClippingDet(SYS_IPNum_e ADCNum, ADC_ConfigClippingDet_t *pConfigClippingDet)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_ADC_ConfigClippingDet(ADCNum, pConfigClippingDet);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_ADC_CheckCalResult(SYS_IPNum_e ADCNum)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_ADC_CheckCalResult(ADCNum);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}



#if defined(__cplusplus)
}
#endif
