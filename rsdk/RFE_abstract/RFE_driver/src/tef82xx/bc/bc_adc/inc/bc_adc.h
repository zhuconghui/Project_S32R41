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
@file bc_adc.h

@version

@brief Barracuda API header file

This is the header file for Barracuda APIs. All exported API can be found in
this file.

<TotalNumAPI>4
*/

#ifndef BC_ADC_H
#define BC_ADC_H


#include <stdint.h>

#include "bc_types.h"
#include "bc_err.h"

#if defined(__cplusplus)
extern "C"
{
#endif

/**
@brief This API initializes ADC
 
RSNum:1456426
 
# Description
 
An will initialize the dual ADCs, do auto calibration and return the calibration status by calling BC_ADC_CheckCalResult 
 
@param[in] EnADC12 FALSE: ADC12 is not enabled; TRUE: ADC12 is enabled.
@param[in] EnADC34 FALSE: ADC34 is not enabled; TRUE: ADC34 is enabled.
 
## Note
1. ADC calibration does not work in case IP is in powered down (power saving) mode. 
 
@return BC_ERRCODE
*/
 
BC_ERRCODE BC_ADC_PowerOn(BOOL EnADC12, BOOL EnADC34);


/**
@brief this API configures ADC background calibration.
 
RSNum:1456426
 
# Description 
 
An API will enable and configure the background calibration 
 
@param[in] ADCNum to select ADC12 or ADC34
@param[in] EnBackgroundCal FALSE: disable background calibration; TRUE: enable background calibration
@param[in] pBackgroundCalControl  parameters to configure background calibration
 
@return BC_ERRCODE
*/
 
BC_ERRCODE BC_ADC_ConfigBackgroundCal(SYS_IPNum_e ADCNum, BOOL EnBackgroundCal, ADC_BackGroundCal_t *pBackgroundCalControl);


/**
@brief This API configures the clipping detector of ADC.
 
RSNum:2547546
 
# Description
 
An API will configure the clipping level and error count threshold for clipping detector.
 
@param[in] ADCNum to select ADC12 or ADC34
@param[in] pConfigClippingDet parameters to configure clipping detector
 
@return BC_ERRCODE
*/
 
BC_ERRCODE BC_ADC_ConfigClippingDet(SYS_IPNum_e ADCNum, ADC_ConfigClippingDet_t *pConfigClippingDet);


/**
@brief This API checks the calibration result.
 
RSNum:2483560, 771671
 
# Description
 
An API will wait ADC calibration until finish, then check calibration result. It will be called in HAL_EXs_ADC_PowerOn.
 
## Note
1. This function will be protected by proper timeout.
 
@param[in] ADCNum to select ADC12 or ADC34
 
@return BC_ERRCODE
*/
 
BC_ERRCODE BC_ADC_CheckCalResult(SYS_IPNum_e ADCNum);



#if defined(__cplusplus)
}
#endif
#endif
