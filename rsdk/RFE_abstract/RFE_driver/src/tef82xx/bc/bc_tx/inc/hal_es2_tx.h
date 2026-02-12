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
@file hal_es2_tx.h

@version

@brief Barracuda API HAL(Hardware Abstraction Layer) header file

This is the header file for Barracuda APIs. All exported API can be found in
this file.

<TotalNumAPI>17
*/

#ifndef HAL_ES2_TX_H
#define HAL_ES2_TX_H


#include <stdint.h>

#include "bc_types.h"
#include "bc_err.h"

#if defined(__cplusplus)
extern "C"
{
#endif

/**
@brief This API sets the gain code of the selected TX in the selected profile
 
RSNum:1448230
 
# Description
 
An API will set TX gain in TX profile settings
 
## Note
1. Multicast for TX1/2/3 is not supported for ES2 samples.
 
@see SYS_IPNum_e
 
@param[in] ProfID The profile ID to be programmed.
@param[in] TXIP Which TX to be configured, multicasting is not supported for ES2 Samples.
@param[in] TXGain TX gain
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_TX_SetProfileGain(SYS_ProfID_e ProfID, SYS_IPNum_e TXIP, uint8_t TXGain);


/**
@brief This API controls various settings in local IP (can be used in idle time)
 
RSNum:1445693
 
# Description
 
An API will perform TX control locally from TX register space, without the control of other modules (e.g. TE).
 
## Note
1. Multicast for TX1/2/3 is supported.
 
@see SYS_IPNum_e
 
@param[in] TXIP Which TX to be configured, multicasting is supported
@param[in] UseEXTPSPin Use external phase shift pin or not
@param[in] BPS Control the bipolar phase shift TRUE: 180deg; FALSE: 0deg, only valid when UseEXTPSPin is set to FALSE.
@param[in] ForcePhaseShift Choose to force a phase shift using TX PR or not
@param[in] PhaseShift Phase shift value, only valid when ForcePhaseShift is set to TRUE.
@param[in] CloseTXSW Close TX RF transmission switch
@param[in] EnTX Enable or disable TX DC power
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_TX_ConfigLocalCtrl(SYS_IPNum_e TXIP, BOOL UseEXTPSPin, BOOL BPS, BOOL ForcePhaseShift, float32_t PhaseShift, BOOL CloseTXSW, BOOL EnTX);


/**
@brief This API sets target for output power calibration for the selected TX in the selected profile
RSNum:1448230
 
# Description
 
An API will set target power for output power calibration for the selected TX in the selected profile.
 
## Note
1. This API is only supported for ES2 samples.
2. Multicast for TX1/2/3 is supported.
 
@see SYS_IPNum_e
@see SYS_ProfID_e
 
@param[in] ProfID The profile ID to be programmed.
@param[in] TXIP Which TX to be configured, multicasting is supported
@param[in] TargetPower TargetPower to set target for output power calibration, max = 15 dBm, min = 1.5 dBm, 0.29 dBm per LSB
default target 14.13 dBm. Unit is dBm.
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_TX_SetRFTargetPower(SYS_ProfID_e ProfID, SYS_IPNum_e TXIP, float32_t TargetPower);


/**
@brief This API enable TX RF RMS power detector
 
RSNum:1456117, 510526, 510613, 510534, 673725, 673724
 
# Description
 
An API will enable/disable the RMS detector for TX RF level.
 
## Note
1. Multicast for TX1/2/3 is supported.
 
@param[in] EnRMSDet Enable or disable RMS detector
@param[in] TXIP Choose which TX's RMS detector to be configured, multicast is supported
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_TX_EnableRFLevelRMSDet(BOOL EnRMSDet, SYS_IPNum_e TXIP);


/**
@brief This API defines the way the binary search is performed
RSNum:2547535
 
# Description
An API will be used to define the way the binary search is performed, whether calibration results will be above/below the threshold

## Note
1. This API is only supported for ES2 samples.
2. Multicast is supported.
 
@see TX_EnableBinarySearch_t
 
@param[in] TXIP Choose which TX's to be configured, multicast is supported
@param[in] pEnableBinarySearch pointer to the structure which used to define a way the binary search is performed. If TRUE  the calibration results will be above the threshold.
@return BC_ERRCODE
*/
BC_ERRCODE HAL_ES2_TX_SetBinSearch(SYS_IPNum_e TXIP, TX_EnableBinarySearch_t *pEnableBinarySearch);


/**
@brief This API defines the level high or low delta for tx amplitude monitor high & low levels
RSNum:2547543
 
# Description
An API will be used to define the values to be added (substracted) to AMP_SETTINGS_PROFILEX/tx_power_target_mon_profile0 to get  AMP_SETTINGS_PROFILEX/level_rf_high_spi_profile0 (AMP_SETTINGS_PROFILEX/level_rf_low_spi_profile0)

## Note
1. This API is only supported for ES2 samples.
2. Multicast is supported.

@param[in] TXIP Choose which TX's to be configured, multicast is supported
@param[in] LevelHighDelta level high delta value in dBm
@param[in] LevelLowDelta level  low delta value in dBm
@return BC_ERRCODE
*/
BC_ERRCODE HAL_ES2_TX_SetRFCalMonLevel(SYS_IPNum_e TXIP, float32_t LevelHighDelta, float32_t LevelLowDelta);


/**
@brief This API contains the setting for TX PPD offsets calibration. 
RSNum:1448228, 1448229
 
# Description
An API will be used to start TX PPD offsets calibration and if ReadCalibStatus is TRUE, the API will wait for CalCheckTimeOut time after starting PPD offsets calibration and returns the global calibration status for TX.

## Note
1. This API is only supported for ES2 samples.
2. Multicast is supported.
3. Since this calibration is performed in CW calibration mode the Chirp and LO Interface modules should be out of Dynamic powering saving mode(Disable dynamic power down mode).
4. ReadCalibStatus recommended value is FALSE/0, based on the Application usage user can read the consolidate result of all the calibration, once entire calibration sequence is over, using the API BC_ISM_GetCalibrationStatus. This is optimize approached.   
 
@see BC_ISM_GetCalibrationStatus
@see SYS_IPNum_e

@param[in] TXIP Choose which TX's to be configured, multicast is supported
@param[in] ReadCalibStatus Whether to check GLOBAL CAL STATUS for tx calibration status or not. Recommended value FALSE.
@param[in] CalCheckTimeOutUs API wait for dedicate time after calibration is triggered, in case of  ReadCalibStatus = TRUE after this wait time, calibration status is checked. Typical value is 80us
@return BC_ERRCODE
*/
BC_ERRCODE HAL_ES2_TX_CalibrateTXPPD(SYS_IPNum_e TXIP, BOOL ReadCalibStatus, uint32_t CalCheckTimeOutUs);


/**
@brief This API contains the setting for Tx RF calibration. 
 
RSNum:1448228, 1448229, 1448230
 
# Description
An API will trigger selected calibration among Tx PPD offset, Tx Lox3, Tx Pout, Tx Pr current , Tx  PrPhase and Tx Vga. If ReadCalibStatus is TRUE, the api will wait for CalCheckTimeOut time after starting TX RF calibration and returns the global calibration status for TX.
An API will write the calibration output to profile registers based on the selected stored profile.
 
## Note
1. This API is only supported for ES2 samples.
2. Multicast is supported.
3. CalibrateProfID  is used only for VGA calibration VgaCalStart = TRUE.
4. In case VGA calibration (VgaCalStart = TRUE) is selected, before calibration start   (TX_CURR_GAIN_PROFILE0+ CalibrateProfID) register bitfields are updated, TX Current gain set to 255, and PR Current gain and Lox3 gain set to 0.
5. If VGA calibration is done the TX current gain, PR Current Gain and Lox3 gain is changed, and not restored, application might need to restore the values after the VGA calibration call based on the application needs.    
6. ReduceTransmisionForVGACalib parameter is used only when parameter VgaCalStart = TRUE. 
7. Since this calibration is performed in CW calibration mode the Chirp and LO Interface modules should be out of Dynamic powering saving mode(Disable dynamic power down mode).
8. Only during Pout calibration & VGA Calibration, since Tx FastSwich is closed, Barracuda will be transmitting a frequency for which calibration is getting performed.   
9. ReadCalibStatus recommended value is FALSE/0, based on the Application usage user can read the consolidate result of all the calibration, once entire calibration sequence is over, using the API BC_ISM_GetCalibrationStatus. This is optimize approached.   
10. VGA calibration with ReduceTransmisionForVGACalib = TRUE and POUT calibration at the same time is not supported.
 
@see BC_ISM_GetCalibrationStatus
@see SYS_IPNum_e
@see SYS_ProfID_e
@see SYS_EnableTxRfCalibration_t
@see SYS_StoreInProfile_t
 
@param[in] TXIP Choose which TX's to be configured, multicast is supported
@param[in] pEnableTxRfCalibration pointer to structure which contains which tx calibration to be enabled (PPD offset,Lox3, Pout. Pr, PrPhase, Vga).
@param[in] pStoreInProfile pointer to structure which contains calibration results to be stored in which profile.
@param[in] ReadCalibStatus Whether to check GLOBAL CAL STATUS for tx calibration status or not. Recommended value FALSE
@param[in] CalCheckTimeOutUs API wait for dedicate time after calibration is triggered, in case of  ReadCalibStatus = TRUE after this wait time, calibration status is checked.
@param[in] CalibrateProfID  ProfileID used for calibration valid input e_SYS_PROFILE_0 to e_SYS_PROFILE_8, only used if VgaCalStart is TRUE.
@param[in] ReduceTransmisionForVGACalib to reduce the transmission while VGA Calibration TRUE/1: PA stage 1 bias gain is reduced before VGA calibration, FALSE/0: no change in PA bias settings , only used if VgaCalStart is TRUE.
 
@return BC_ERRCODE
*/
BC_ERRCODE HAL_ES2_TX_CalibrateTXRF(SYS_IPNum_e TXIP, SYS_EnableTxRfCalibration_t *pEnableTxRfCalibration, SYS_StoreInProfile_t *pStoreInProfile, BOOL ReadCalibStatus, uint32_t CalCheckTimeOutUs, SYS_ProfID_e CalibrateProfID, BOOL ReduceTransmisionForVGACalib);


/**
@brief This API to start the TX PR safety check sequence
 
RSNum:2483564, 781146
 
# Description
An API will be used to start the safety check sequence when in forced mode

## Note
1. This API is only supported for ES2 samples.
2. Multicast is supported.
3. Since this safety check is performed in CW calibration mode the Chirp and LO Interface modules should be out of Dynamic powering saving mode(Disable dynamic power down mode).
 
@see BC_ISM_GetCalibrationStatus
@see SYS_IPNum_e

@param[in] TXIP Choose which TX's to be configured, multicast is supported
@param[in] ReadCalibStatus Whether to check GLOBAL CAL STATUS for tx calibration status or not.
@param[in] SafetyCheckTimeOutUs API wait for dedicate time after calibration is triggered, in case of  ReadCalibStatus = TRUE after this wait time, calibration status is checked. Recommended value is 405us.
 
@return BC_ERRCODE
*/
BC_ERRCODE HAL_ES2_TX_StartTxPRSafetyCheck(SYS_IPNum_e TXIP, BOOL ReadCalibStatus, uint32_t SafetyCheckTimeOutUs);


/**
@brief This API is used to get local tx calibration status and TxPrSafetyCheck
 
RSNum:2483563, 1448229, 781146
 
# Description
An API will be used to get local tx calibration status which returns tx calibration state and calibration status of PpdOffsetLox3Cal, PpdOffsetPrCal, PpdOffsetVgaCal, RfLox3Cal, RfPrCal, RfVgaCal, RfPrPhaseCal, PoutCal and status of TxPrSafetyCheck

## Note
1. This API is only supported for ES2 samples.
2. Multicast is not supported.
3. It is recommended to check calibration status only for the calibrations triggered before invoking this API.
4. If PR phase calibration is never triggered before invoking this API, the RfPrPhaseCal reported by this API will be e_ISM_CAL_ERROR.
 
@see SYS_IPNum_e
@see TX_CalibrationStatus_t

@param[in] TXIP Choose which TX's to be configured, multicast is not supported
@param[in] SafetyCheck whether to check tx pr safetycheck status
@see TX_CalibrationStatus_t
@param[out] pCalibStatus pointer to structure which contains tx calibration state and calibration status of PpdOffsetLox3Cal, PpdOffsetPrCal, PpdOffsetVgaCal, RfLox3Cal, RfPrCal, RfVgaCal, RfPrPhaseCal, PoutCal, TxPrSafetyCheck
 
@return BC_ERRCODE
*/
BC_ERRCODE HAL_ES2_TX_GetLocalCalibStatus(SYS_IPNum_e TXIP, BOOL SafetyCheck, TX_CalibrationStatus_t *pCalibStatus);


/**
@brief This API is used to set hardware calibration time.
 
RSNum:1448230
 
# Description
An API will be used to set hardware calibration time for Pout, RF, PPD and monitor in us.

## Note
1. This API is only supported for ES2 samples.
2. Multicast is supported
 
@see SYS_IPNum_e
@see TX_CalibrationTime_t
 
@param[in] TXIP Choose which TX's to be configured for Calibration time, multicast is supported
@param[in] pCalibTime pointer to structure which contains calibration time in us for Ppd, RF, PPD, and monitor. Maximum allowed time is 6.375us
 
@return BC_ERRCODE
*/
BC_ERRCODE HAL_ES2_TX_ConfigCalibTime(SYS_IPNum_e TXIP, TX_CalibrationTime_t *pCalibTime);


/**
@brief This API sets the TX RF level min trigger threshold level for Gain Control.
 
RSNum:2547543
 
# Description
 
An API will set TX RF level min trigger threshold level for Gain Control.
 
## Note
1. This API is only supported for ES2 samples.
2. Multicast for TX1/2/3 is supported.
 
@see SYS_IPNum_e
 
@param[in] TXIP Which TX to be configured, multicasting is supported
@param[in] LevelRfMin Min trigger level for Gain Control in dBm
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_TX_SetLevelRfMin(SYS_IPNum_e TXIP, float32_t LevelRfMin);


/**
@brief This API sets max safe target power for output power calibration for the selected TX in the selected profile
RSNum:1448230
 
# Description
 
An API will set max safe target power for output power calibration for the selected TX in the selected profile.
This API using the safe target output power based on the anchor point and max threshold values.
 
## Note
1. This API is only supported for ES2 samples.
2. Multicast for TX1/2/3 is supported.
3. BackOffCode value depends on chirp bandwidth and calibration frequency.
4. Insufficient BackOffCode might cause TX MAX error to flag during chirping.
5. Since this API tries to get maximum safe output power as possible, without reliability concern, variations in output power from die to die and over temperature is to be expected.
 
@see SYS_IPNum_e
@see SYS_ProfID_e
 
@param[in] ProfID the profile ID to be programmed.
@param[in] TXIP Which TX to be configured, multicasting is supported
@param[in] BackOffCode BackOffCode from MaxTarget. Unit 1 code equal to is 0.29 dBm. BackOffCode value depends on chirp bandwidth and calibration frequency. Recommended values 2 or 4.
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_TX_SetMaxSafePOutTarget(SYS_ProfID_e ProfID, SYS_IPNum_e TXIP, uint8_t BackOffCode);


/**
@brief This API gets the gain code of the selected TX in the selected profile
 
RSNum:1448229, 1448230
 
# Description
 
An API will read the TX current gain code in TX profile.
 
## Note
1. Multicast for TX1/2/3 is not supported.
 
@see SYS_IPNum_e
@see BC_TX_AdjustTXRFCurrentGain

@param[in] ProfID The profile ID to be programmed.
@param[in] TXIP Which TX to be read, multicasting is not supported .
@param[out] pTxCurrGain Output TX current gain value 
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_TX_GetProfileCurrGain(SYS_IPNum_e TXIP, SYS_ProfID_e ProfID, uint8_t *pTxCurrGain);


/**
@brief This API to adjust the Tx Current gain after the chirp sequence (TX POut calibration without transmission). 
 
RSNum:1448230
 
# Description
 
This API perform the TX POut calibration without the transmission. This API can be used as substitute for POut calibration BC_TX_CalibrateTXRF API. 
This API adjust the TX Current gain based on the Tx Error and/or warnings flags in the previous chirp sequence. 
This API can be called only after the chirp sequence is over and TX error flags are read using BC_ISM_GetTxErrStatus API.
Application need to provide the previous TX current gain value to adjust the gain.
This API will modified the TX Current Gain and copy it to required profiles.
 
## Note
1. Multicast for TX1/2/3 is not supported.
2. Application Needs to provide the previous Tx Current gain.
3. Application need to store the pTxCurrGain for the call of this API.
4. This API needs to be called only after BC_TX_CalibrateTXRF VGA calibration is done, since during  VGA calibration BC_TX_CalibrateTXRF  API will overwrite the Tx Current gain to 255. 

@see SYS_IPNum_e
@see BC_TX_GetProfileCurrGain
@see BC_ISM_GetTxErrStatus
 
@param[in] TXIP Which TX to be read, multicasting is not supported .
@param[in] CalibrateProfID The profile ID which will be used to copy the gain values.
@param[in] pTxErr structure of all the Tx-n errors, True : error occurred, False :  no error
@param[in] PercntCurGainAdj percentage increase/decrease of TX current gain. Typical value is 4 percent.
@param[in] PercntgBiasCurGainAdj percentage increase of TX current gain, in case no high and low errors are there. Typical value is 2 percent.
@param[in] pStoreInProfile pointer to structure which contains calibration results to be stored in which profile.
@param[inout] pTxCurrGain input value of TX current gain which will be updated in this function based on error values.
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_TX_AdjustTXRFCurrentGain(SYS_IPNum_e TXIP, SYS_ProfID_e CalibrateProfID, SYS_TXErrors_t *pTxErr, uint8_t PercntCurGainAdj, uint8_t PercntgBiasCurGainAdj, SYS_StoreInProfile_t *pStoreInProfile, uint8_t *pTxCurrGain);


/**
@brief This API gets the output phase from the BPSK hardware.

RSNum:1447756, 837411
 
# Description
 
An API will read the internal Phase of the BPSK modulator for the given Tx.
This API can be used to verify the status of BPSK hardware. 
 
## Note
1. Multicast for TX1/2/3 is not supported.
2. Since BPSK phase shift via GPIO is enabled only during chirp acquisition, to reflect the GPIO BPSK phase status, this API need to be called during chirp acquisition only, otherwise this API will return e_TX_BPSK_PHASE_STATUS_OFF status.
3. To check the BPSK phase status while CW mode or other than chirping, user need to Enable TX, Close Fast Swich and contol BPS via SPI using TX_CONTROL register. 
 
@see SYS_IPNum_e
@see TX_BPSKPhaseStatus_e
@see BC_TX_ConfigLocalCtrl
@see BC_TE_SetPhaseCtrls

@param[in] TXIP TX IP number to be read, Multicast(TXMC) is not supported.
@param[out] pTxBPSKPhaseStatus Output TX BPSK phase status 
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_TX_GetBPSKPhaseStatus(SYS_IPNum_e TXIP, TX_BPSKPhaseStatus_e *pTxBPSKPhaseStatus);


/**
@brief This API configure the ball break detector of TX.

RSNum:1456361, 2483080, 3602014
 
# Description
 
An API will enable or disable ball break detector. Also, configure the sensitivity and ground settings.
 
## Note
1. Multicast is supported.
2. For a grounded interface, both the positive and negative ball of the interface are the source of the BBD DC current, this current is sunk at the DC ground connection of theinterface. It requires TX BBD enabled, high sensitivity and grounded
3. For a not grounded interface, the positive ball of the interface is the source of this DC current, while the negative ball of the interface is the sink. This require TX BBD enabled, high sensitivity and not grounded. 
 
@see SYS_IPNum_e

@param[in] TXIP Choose which TX's to be configured, multicast is supported.
@param[in] EnableBBDTX Ball break detector enable.
@param[in] NormalSensitivity NormalSensitivity Ball break current detection limit. 1=50uA(Normal)   0=500uA(High) 
@param[in] Grounded Balun grounded control based on balun type. 0 = not grounded 1 = grounded.
 
@return BC_ERRCODE
*/
 
BC_ERRCODE HAL_ES2_TX_ConfigBBD(SYS_IPNum_e TXIP, BOOL EnableBBDTX, BOOL NormalSensitivity, BOOL Grounded);



#if defined(__cplusplus)
}
#endif
#endif
