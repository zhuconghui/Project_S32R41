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
@file bc_tx.c

@version

@brief Barracuda API code file

This is the code file for Barracuda APIs. All exported API code can be found in
this file.

*/


#include <stdint.h>

#include "bc_types.h"
#include "bc_err.h"

#include "bc_tx.h"

#ifdef TEF82XX_CFG_ES2
#include "hal_es2_tx.h"
#endif

#if defined(__cplusplus)
extern "C"
{
#endif

BC_ERRCODE BC_TX_SetProfileGain(SYS_ProfID_e ProfID, SYS_IPNum_e TXIP, uint8_t TXGain)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_TX_SetProfileGain(ProfID, TXIP, TXGain);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_TX_ConfigLocalCtrl(SYS_IPNum_e TXIP, BOOL UseEXTPSPin, BOOL BPS, BOOL ForcePhaseShift, float32_t PhaseShift, BOOL CloseTXSW, BOOL EnTX)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_TX_ConfigLocalCtrl(TXIP, UseEXTPSPin, BPS, ForcePhaseShift, PhaseShift, CloseTXSW, EnTX);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_TX_SetRFTargetPower(SYS_ProfID_e ProfID, SYS_IPNum_e TXIP, float32_t TargetPower)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_TX_SetRFTargetPower(ProfID, TXIP, TargetPower);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_TX_EnableRFLevelRMSDet(BOOL EnRMSDet, SYS_IPNum_e TXIP)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_TX_EnableRFLevelRMSDet(EnRMSDet, TXIP);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_TX_SetBinSearch(SYS_IPNum_e TXIP, TX_EnableBinarySearch_t *pEnableBinarySearch)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_TX_SetBinSearch(TXIP, pEnableBinarySearch);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_TX_SetRFCalMonLevel(SYS_IPNum_e TXIP, float32_t LevelHighDelta, float32_t LevelLowDelta)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_TX_SetRFCalMonLevel(TXIP, LevelHighDelta, LevelLowDelta);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_TX_CalibrateTXPPD(SYS_IPNum_e TXIP, BOOL ReadCalibStatus, uint32_t CalCheckTimeOutUs)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_TX_CalibrateTXPPD(TXIP, ReadCalibStatus, CalCheckTimeOutUs);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_TX_CalibrateTXRF(SYS_IPNum_e TXIP, SYS_EnableTxRfCalibration_t *pEnableTxRfCalibration, SYS_StoreInProfile_t *pStoreInProfile, BOOL ReadCalibStatus, uint32_t CalCheckTimeOutUs, SYS_ProfID_e CalibrateProfID, BOOL ReduceTransmisionForVGACalib)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_TX_CalibrateTXRF(TXIP, pEnableTxRfCalibration, pStoreInProfile, ReadCalibStatus, CalCheckTimeOutUs, CalibrateProfID, ReduceTransmisionForVGACalib);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_TX_StartTxPRSafetyCheck(SYS_IPNum_e TXIP, BOOL ReadCalibStatus, uint32_t SafetyCheckTimeOutUs)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_TX_StartTxPRSafetyCheck(TXIP, ReadCalibStatus, SafetyCheckTimeOutUs);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_TX_GetLocalCalibStatus(SYS_IPNum_e TXIP, BOOL SafetyCheck, TX_CalibrationStatus_t *pCalibStatus)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_TX_GetLocalCalibStatus(TXIP, SafetyCheck, pCalibStatus);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_TX_ConfigCalibTime(SYS_IPNum_e TXIP, TX_CalibrationTime_t *pCalibTime)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_TX_ConfigCalibTime(TXIP, pCalibTime);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_TX_SetLevelRfMin(SYS_IPNum_e TXIP, float32_t LevelRfMin)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_TX_SetLevelRfMin(TXIP, LevelRfMin);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_TX_SetMaxSafePOutTarget(SYS_ProfID_e ProfID, SYS_IPNum_e TXIP, uint8_t BackOffCode)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_TX_SetMaxSafePOutTarget(ProfID, TXIP, BackOffCode);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_TX_GetProfileCurrGain(SYS_IPNum_e TXIP, SYS_ProfID_e ProfID, uint8_t *pTxCurrGain)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_TX_GetProfileCurrGain(TXIP, ProfID, pTxCurrGain);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_TX_AdjustTXRFCurrentGain(SYS_IPNum_e TXIP, SYS_ProfID_e CalibrateProfID, SYS_TXErrors_t *pTxErr, uint8_t PercntCurGainAdj, uint8_t PercntgBiasCurGainAdj, SYS_StoreInProfile_t *pStoreInProfile, uint8_t *pTxCurrGain)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_TX_AdjustTXRFCurrentGain(TXIP, CalibrateProfID, pTxErr, PercntCurGainAdj, PercntgBiasCurGainAdj, pStoreInProfile, pTxCurrGain);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_TX_GetBPSKPhaseStatus(SYS_IPNum_e TXIP, TX_BPSKPhaseStatus_e *pTxBPSKPhaseStatus)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_TX_GetBPSKPhaseStatus(TXIP, pTxBPSKPhaseStatus);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_TX_ConfigBBD(SYS_IPNum_e TXIP, BOOL EnableBBDTX, BOOL NormalSensitivity, BOOL Grounded)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_TX_ConfigBBD(TXIP, EnableBBDTX, NormalSensitivity, Grounded);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}



#if defined(__cplusplus)
}
#endif
