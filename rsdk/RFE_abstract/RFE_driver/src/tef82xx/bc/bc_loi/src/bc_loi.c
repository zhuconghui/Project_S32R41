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
@file bc_loi.c

@version

@brief Barracuda API code file

This is the code file for Barracuda APIs. All exported API code can be found in
this file.

*/


#include <stdint.h>

#include "bc_types.h"
#include "bc_err.h"

#include "bc_loi.h"

#ifdef TEF82XX_CFG_ES2 
#include "hal_es2_loi.h"
#endif

#if defined(__cplusplus)
extern "C"
{
#endif

BC_ERRCODE BC_LOI_ConfigBufferMode(BOOL EnBuffer1, BOOL EnBuffer2, BOOL EnBuffer3, BOOL EnBuffer4, BOOL MuxCtrl, BOOL EnCtrlSwitch)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_LOI_ConfigBufferMode(EnBuffer1, EnBuffer2, EnBuffer3, EnBuffer4, MuxCtrl, EnCtrlSwitch);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_LOI_EnableRFLevelRMSDet(BOOL EnRMSDet)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_LOI_EnableRFLevelRMSDet(EnRMSDet);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_LOI_ConfigLOGainCtrl(LOI_GainSel_e GainSelect, uint8_t GainCode, BOOL BinSearchFromAbove)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_LOI_ConfigLOGainCtrl(GainSelect, GainCode, BinSearchFromAbove);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_LOI_StartLOGainCalib(BOOL ReadCalibStatus, uint32_t CalCheckTimeOutUs)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_LOI_StartLOGainCalib(ReadCalibStatus, CalCheckTimeOutUs);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_LOI_ConfigLOx3Gain(LOI_LOx3GainConfig_t *pLOx3GainConfig, BOOL LOx3TxChannels[3], BOOL LOx3RxChannels[4])
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_LOI_ConfigLOx3Gain(pLOx3GainConfig, LOx3TxChannels, LOx3RxChannels);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_LOI_UpdateLOILevelTh(BC_FLOAT InputBW)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_LOI_UpdateLOILevelTh(InputBW);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_LOI_ConfigBBD(BOOL EnableBBDLOIN, BOOL EnableBBDLOOUT, BOOL NormalSensitivityLOIN, BOOL GroundedLOIN, BOOL NormalSensitivityLOOUT, BOOL GroundedLOOUT)
{
     BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_LOI_ConfigBBD(EnableBBDLOIN, EnableBBDLOOUT, NormalSensitivityLOIN, GroundedLOIN, NormalSensitivityLOOUT, GroundedLOOUT);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}

#if defined(__cplusplus)
}
#endif
