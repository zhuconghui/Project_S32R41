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
@file hal_es2_rx.h

@version

@brief Barracuda API HAL(Hardware Abstraction Layer) header file

This is the header file for Barracuda APIs. All exported API can be found in
this file.

<TotalNumAPI>8
*/

#ifndef HAL_ES2_RX_H
#define HAL_ES2_RX_H


#include <stdint.h>

#include "bc_types.h"
#include "bc_err.h"

#if defined(__cplusplus)
extern "C"
{
#endif

/**
@brief This API configures RX channel profiles.
 
RSNum:1445690
 
# Description
 
An API will configure the RX channel profiles with selected RX gain, Low pass and high pass filter frequencies.  
 
## Note
1. Multicast is supported.
 
@see SYS_IPNum_e
@see SYS_ProfID_e
@see RX_ConfigProfile_t
 
@param[in] RXNum to select a RX. RX multicasting is supported.
@param[in] ProfileNum to select a profile
@param[in] pConfigProfile Parameters to configure RX profiles
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_RX_ConfigProfile(SYS_IPNum_e RXNum, SYS_ProfID_e ProfileNum, RX_ConfigProfile_t *pConfigProfile);


/**
@brief This API enables the RMS detector.
 
RSNum:1456117, 1456365, 510534
 
# Description
 
An API will configure the calibration control setting for the RMS detector. 
 
## Note
1. Multicast is supported.
 
@see SYS_IPNum_e
 
@param[in] EnRMSDet 0: disable RMS detector; 1: enable RMS detector
@param[in] RXNum to select a RX. RX multicasting is supported.
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_RX_EnableRMSDet(BOOL EnRMSDet, SYS_IPNum_e RXNum);


/**
@brief  This API controls RX locally.
 
RSNum:1447608, 510472
 
# Description
 
An API will perform RX control locally from RX register space, without the control of other modules (e.g. TE).
 
## Note
1. Multicast is supported.
 
@see SYS_IPNum_e
 
@param[in] RXNum to Select a RX. RX multicasting is supported.
@param[in] EnRX  0: disable RX; 1: Enable RX
@param[in] EnLNA 0: disable LNA; 1: Enable LNA
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_RX_ConfigLocalCtrl(SYS_IPNum_e RXNum, BOOL EnRX, BOOL EnLNA);


/**
@brief  This API selects RFBIST input signal.
 
RSNum:1447608, 514072
 
# Description
 
An API will select the RFBIST input signal ( Mixer or LNA)
 
## Note
1. Multicast is supported.
 
@see SYS_IPNum_e
@param[in] RXNum to select a RX. RX multicasting is supported.
@param[in] SelectInput to select if the input is connected to LNA or Mixer
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_RX_ConnectRFBISTSignal(SYS_IPNum_e RXNum, RX_RFBIST_Input_e SelectInput);


/**
@brief  This API configure the LOx3 Gain configuration based on the gain source 
 
RSNum:2547535, 1448227
 
# Description
An API will configure LOx3 gain controls based on the LOx3 RX gain source.
 
## Note
1. RX multicasting is supported.
2. This API is only supported for ES2 samples.
 
@see SYS_IPNum_e
@see RX_LOx3_GainSelect_e
 
@param[in] RXIP  To select a RX. RX multicasting is supported.
@param[in] GainSelect Select the source of RX LOx3 gain
@param[in] GainCode If GainSelect is from RX LOx3 CTRL register, thn sets the gaincode
@param[in] BinSearchFromAbove Set binary search from (TRUE)above and (FALSE)below if GainSelect is HW calibration
@param[in] CalTargetOffset Set Target offset value for RX LOx3 gain Calibration
 
@return BC_ERRCODE
*/
BC_ERRCODE HAL_ES2_RX_ConfigLOx3Gain(SYS_IPNum_e RXIP, RX_LOx3_GainSelect_e GainSelect, uint8_t GainCode, BOOL BinSearchFromAbove, uint8_t CalTargetOffset);


/**
@brief  This API triggers RX LOx3 gain calibration and check for calibration status.
 
RSNum:1448227
 
# Description
An API will triggers RX LOx3 gain HW calibration and if status check is enabled, it checks for calibration status after a fixed input timeout value in us. This API assumes correct RX RF Level Low and High thresholds are set in RX IP.
An API will change gain source set to local calibration result before calibration start and change back to common value for all Rx after calibration is done.

## Note
1. Since this calibration is performed in CW calibration mode the Chirp and LO Interface modules should be out of Dynamic powering saving mode(Disable dynamic power down mode).
2. RX multicasting is supported.
3. This API is only supported for ES2 samples.
4. ReadCalibStatus recommended value is FALSE/0, based on the Application usage user can read the consolidate result of all the calibration, once entire calibration sequence is over, using the API BC_ISM_GetCalibrationStatus. This is optimize approach.
 
 
@see BC_ISM_GetCalibrationStatus
@see SYS_IPNum_e
 
@param[in] RXIP  To select a RX. RX multicasting is supported.
@param[in] ReadCalibStatus Enable checking calibration status after RX LOx3 calibration is triggered. Recommended value FALSE
@param[in] CalCheckTimeOutUs API wait for dedicate time after calibration is triggered, in case of  ReadCalibStatus = TRUE after this wait time, calibration status is checked. Typical value is 17us.
 
@return BC_ERRCODE
*/
BC_ERRCODE HAL_ES2_RX_CalibrateLOx3Gain(SYS_IPNum_e RXIP, BOOL ReadCalibStatus, uint32_t CalCheckTimeOutUs);


/**
@brief  This API updates the value for low trigger level for LO level  monitor and set LOx3 calibration target based on input center frequency and VCO selected.
 
RSNum:1456117, 510526, 510613, 510534, 673725, 673724
 
# Description
An API will update the value for low trigger level for LO level  monitor and set LOx3 calibration target based on input center frequency and VCO selected.
 
## Note
1. RX multicasting is supported.
2. This API is only supported for ES2 samples.
 
@see SYS_IPNum_e
 
@param[in] RXNum To select a RX. RX multicasting is supported.
@param[in] VCOSel VCO selection, 5GHz VCO has two mode (4GHz, 2GHz), and 1GHz VCO
@param[in] InputFrequency Input center frequency which is used only for 1GHz VCO.
 
@return BC_ERRCODE
*/
BC_ERRCODE HAL_ES2_RX_UpdateLOLowLevelTh(SYS_IPNum_e RXNum, CAFC_VCOBWSel_e VCOSel, BC_FLOAT InputFrequency);


/**
@brief This API configure the Ball Break Detector of RX.

RSNum:1456361, 2483080, 3602014
 
# Description
 
An API will enable or disable ball break detector. Also, configure the sensitivity and ground settings.
 
## Note
1. Multicast is supported.
2. For a grounded interface, both the positive and negative ball of the interface are the source of the BBD DC current, this current is sunk at the DC ground connection of the interface. It requires RX BBD enabled, high sensitivity and grounded
3. For a not grounded interface, the positive ball of the interface is the source of this DC current, while the negative ball of the interface is the sink. This require RX BBD enabled, high sensitivity and not grounded. 
 
@see SYS_IPNum_e

@param[in] RXIP Choose which RX's to be configured, multicast is supported.
@param[in] EnableBBDRX Ball break detector enable.
@param[in] NormalSensitivity NormalSensitivity Ball break current detection limit. 1=50uA(Normal)   0=500uA(High) 
@param[in] Grounded Balun grounded control based on balun type. 0 = not grounded 1 = grounded.
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_RX_ConfigBBD(SYS_IPNum_e RXIP, BOOL EnableBBDRX, BOOL NormalSensitivity, BOOL Grounded);



#if defined(__cplusplus)
}
#endif
#endif
