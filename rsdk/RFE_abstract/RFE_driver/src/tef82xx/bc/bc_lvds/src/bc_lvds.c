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
@file bc_lvds.c

@version

@brief Barracuda API code file

This is the code file for Barracuda APIs. All exported API code can be found in
this file.

*/


#include <stdint.h>

#include "bc_types.h"
#include "bc_err.h"

#include "bc_lvds.h"

#ifdef TEF82XX_CFG_ES2 
#include "hal_es2_lvds.h"
#endif

#if defined(__cplusplus)
extern "C"
{
#endif

BC_ERRCODE BC_LVDS_Init(void)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_LVDS_Init();
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_LVDS_Config(LVDS_Config_t *pLVDSConfig, LVDS_OptConfig_t *pLVDSOptConfig)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_LVDS_Config(pLVDSConfig, pLVDSOptConfig);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_LVDS_ConfigPDC(BOOL DisPDCFilter, BOOL EnPDCSync, BOOL EnWAProcess, BOOL EnUnsignedOut, uint8_t pDecModeDelays[4])
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_LVDS_ConfigPDC(DisPDCFilter, EnPDCSync, EnWAProcess, EnUnsignedOut, pDecModeDelays);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_LVDS_MeasureFreq(LVDS_Feq_Dev_e FreqDevVal, float32_t CountPeriod, float32_t *pFrequency)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_LVDS_MeasureFreq(FreqDevVal, CountPeriod, pFrequency);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_LVDS_EnTransmission(BOOL pTxChannels[4])
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_LVDS_EnTransmission(pTxChannels);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_LVDS_ConfigTestMode(BOOL EnTest, LVDS_ConfigTestParms_t *pTestConfig)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_LVDS_ConfigTestMode(EnTest, pTestConfig);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_LVDS_ChooseWinActiveSel(BOOL SelFromRegField, BOOL EnWA)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_LVDS_ChooseWinActiveSel(SelFromRegField, EnWA);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_LVDS_SwitchMode(BOOL SwitchToCalMode, uint16_t ClockChTxData12x1, uint16_t IdlePattern)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_LVDS_SwitchMode(SwitchToCalMode, ClockChTxData12x1, IdlePattern);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}



#if defined(__cplusplus)
}
#endif
