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
@file bc_sc.c

@version

@brief Barracuda API code file

This is the code file for Barracuda APIs. All exported API code can be found in
this file.

*/


#include <stdint.h>

#include "bc_types.h"
#include "bc_err.h"

#include "bc_sc.h"

#ifdef TEF82XX_CFG_ES2 
#include "hal_es2_sc.h"
#endif

#if defined(__cplusplus)
extern "C"
{
#endif

BC_ERRCODE BC_SC_ConfigProfile(SYS_ProfID_e ProfileNum, BC_FLOAT StartFreq, BC_FLOAT usedBW, float32_t RampTime, BOOL DownChirp, float32_t ResetTime)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_SC_ConfigProfile(ProfileNum, StartFreq, usedBW, RampTime, DownChirp, ResetTime);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_SC_SetSweepCtrlMode(BOOL ChirpType, BOOL SweepRstCtrl)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_SC_SetSweepCtrlMode(ChirpType, SweepRstCtrl);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_SC_ConfigSlowDriftChirp(SYS_ProfID_e ProfID, BC_FLOAT FreqDriftHz, float32_t TReset, BC_FLOAT InputBWFullRamp)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_SC_ConfigSlowDriftChirp(ProfID, FreqDriftHz, TReset, InputBWFullRamp);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_SC_SetZeroRamp(SYS_ProfID_e ProfileNum)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_SC_SetZeroRamp(ProfileNum);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_SC_ConfigAAFCFc(SYS_CAFCTXCalFreqMode_e CAFCTXCalMode, BC_FLOAT Fc)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_SC_ConfigAAFCFc(CAFCTXCalMode, Fc);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_SC_KeepMiddleFrequency(BOOL KeepMidFreq)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_SC_KeepMiddleFrequency(KeepMidFreq);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_SC_EnDivHardFuncReset(BOOL EnDivRstFrame, BOOL EnDivRstChirp, BOOL EnHardFuncRstFrame, BOOL EnHardFuncRstChirp)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_SC_EnDivHardFuncReset(EnDivRstFrame, EnDivRstChirp, EnHardFuncRstFrame, EnHardFuncRstChirp);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_SC_ConfigDitherCtrl(SC_DitherControl_t *pDitherControl)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_SC_ConfigDitherCtrl(pDitherControl);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}



#if defined(__cplusplus)
}
#endif
