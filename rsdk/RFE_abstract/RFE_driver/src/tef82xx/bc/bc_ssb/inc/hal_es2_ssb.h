/*
 * Copyright 2020-2022 NXP
 * NXP Confidential. This software is owned or controlled by NXP and may only
 * be used strictly in accordance with the applicable license terms. By
 * expressly accepting such terms or by downloading, installing, activating
 * and/or otherwise using the software, you are agreeing that you have read,
 * and that you agree to comply with and are bound by, such license terms. If
 * you do not agree to be bound by the applicable license terms, then you may
 * not retain, install, activate or otherwise use the software.
 */

/**
@file hal_es2_ssb.h

@version

@brief Barracuda API HAL(Hardware Abstraction Layer) header file

This is the header file for Barracuda APIs. All exported API can be found in
this file.

<TotalNumAPI>7
*/

#ifndef HAL_ES2_SSB_H
#define HAL_ES2_SSB_H


#include <stdint.h>

#include "bc_types.h"
#include "bc_err.h"

#if defined(__cplusplus)
extern "C"
{
#endif

/**
@brief This API configures RFBIST to generate an IF.
 
RSNum:1447609, 514072 
 
# Description
 
An API will enable the SSB module to generate a IF with selected frequency and target output level. This API will also select if the IF signal source is internal or external.
 
## Note
1. Enable the SSB module before calling this API. To enable SSB use BC_SSB_EnableSSB.
 
@see BC_SSB_EnableSSB
 
@param[in] pConfigRFBIST parameters to configure RFBIST
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_SSB_ConfigRFBIST(SSB_ConfigRFBIST_t *pConfigRFBIST);


/** 
@brief This API performs static configuration for RFBIST.
 
RSNum:1447609, 514072 
 
# Description
 
An API will perform the static configuration for RFBIST. Within this API, the IF frequency is set to 3.125 MHz, output level is set to 0x3f,  if_level_set is set to 0x3.
 
## Note
1. For ES1, Decimation parameter is not used by the API.
 
@param[in] Decimation ADC decimation factor value for divider1 in configuration for RFBIST
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_SSB_RFBISTStaticConfig(uint8_t Decimation);


/**
@brief This API Enable the RMS detector.
 
RSNum:1447609, 514072 
 
# Description
 
An API will enable the RMS detector, required for the calibration . 
 
## Note
1. Enable the SSB module before calling this API. To enable SSB use BC_SSB_EnableSSB.
 
@see BC_SSB_EnableSSB
 
@param[in] EnRMSDet FALSE: Disable RMS detector; TRUE: enable RMS detector
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_SSB_EnableRMSDet(BOOL EnRMSDet);


/**
@brief This API Enable and disable SSB Module.
 
RSNum:1447609, 514072 
 
# Description
 
An API will enable/disable SSB LDO, enable/disable clock to SSB, release or enable functional reset to SSB and release or eanale reset to SSB.
 
## Note
This API does not power on SSB module. For SSB power on, please call BC_SSB_ChangePowerState
 
@see BC_SSB_ChangePowerState
 
@param[in]  Enable 0/FALSE: Disable SSB local LDO, disable Clock to SSB module, put SSB into reset, put SSB into functional reset ; 1/TRUE: Enable SSB local LDO, enable Clock to SSB module, release reset of SSB, release functional reset of SSB. 
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_SSB_EnableSSB(BOOL Enable);


/**
@brief This API power on/off SSB module.
 
RSNum:1447609, 514072 
 
# Description
 
An API will power on/off the SSB module. 
 
@param[in] PowerON 0/FALSE: power off SSB module; 1/TRUE: power on SSB module
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_SSB_ChangePowerState(BOOL PowerON);


/**
@brief This API calibrate the Gain code of RFBIST based on look-up table.
 
RSNum:1447609, 514072 
 
# Description
 
An API will calibrate the Gain code of RFBIST based on the input target if level(in dBFs) and last if level(in dBFs).
if_level_set_lut_code = [0, 1, 2, 3, 4, 5, 6, 7, 12, 13, 14, 15];
if_level_set_gain_dBm = [0, 4, 8, 12, 16, 20, 24, 28, 33, 37, 41, 45];
The gain code is searched based on if_level_set_gain_dBm, and find the corresponding gain in if_level_set_lut_code.
 
## Note
1. Enable the SSB module before calling this API. To enable SSB use BC_SSB_EnableSSB.
2. For input target if_level and last if_level should be less than or equal to 0.
3. This API is only supported for ES2 samples.
4. API depends on the previous if level set.
 
@see BC_SSB_EnableSSB
 
@param[in] TargetIFLevel the target IF level in dBFs.
@param[in] LastIFLevel the last IF signal level in dBFs.
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_SSB_CalibrateRFBISTGain(int32_t TargetIFLevel, int32_t LastIFLevel);


/**
@brief This API calibrate the Gain code of RFBIST based on look-up table and previous gain code. 
 
RSNum:1447609, 514072 
 
# Description
 
An API will calibrate the Gain code of RFBIST based on the input and last target if level(in dBFs) and last gain code passed from the application.
if_level_set_lut_code = [0, 1, 2, 3, 4, 5, 6, 7, 12, 13, 14, 15];
if_level_set_gain_dBm = [0, 4, 8, 12, 16, 20, 24, 28, 33, 37, 41, 45];
The gain code is searched based on if_level_set_gain_dBm, and find the corresponding gain in if_level_set_lut_code.

## Note
1. Enable the SSB module before calling this API. To enable SSB use BC_SSB_EnableSSB.
2. For input target if_level and last if_level should be less than or equal to 0.
3. This API is only supported for ES2 samples.
4. API depends on the previous if level. While invoking this API for first time, set the IF level code to default value (3) as mentioned in application note

@see BC_SSB_EnableSSB

@param[in] TargetIFLevel the target IF level in dBFs.
@param[in] LastIFLevel the last IF signal level in dBFs.
@param[in] PreviousIfLevelCode the last set gain code.
@param[out] pCurrentIfLevelCode the updated current gain code.


@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_SSB_CalibRFBISTGainStAl(int32_t TargetIFLevel, int32_t LastIFLevel, uint8_t PreviousIfLevelCode, uint8_t *pCurrentIfLevelCode );



#if defined(__cplusplus)
}
#endif
#endif
