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
@file bc_rx.c

@version

@brief Barracuda API code file

This is the code file for Barracuda APIs. All exported API code can be found in
this file.

*/


#include <stdint.h>

#include "bc_types.h"
#include "bc_err.h"

#include "bc_rx.h"

#ifdef TEF82XX_CFG_ES2 
#include "hal_es2_rx.h"
#endif

#if defined(__cplusplus)
extern "C"
{
#endif

BC_ERRCODE BC_RX_ConfigProfile(SYS_IPNum_e RXNum, SYS_ProfID_e ProfileNum, RX_ConfigProfile_t *pConfigProfile)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_RX_ConfigProfile(RXNum, ProfileNum, pConfigProfile);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_RX_EnableRMSDet(BOOL EnRMSDet, SYS_IPNum_e RXNum)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_RX_EnableRMSDet(EnRMSDet, RXNum);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_RX_ConfigLocalCtrl(SYS_IPNum_e RXNum, BOOL EnRX, BOOL EnLNA)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_RX_ConfigLocalCtrl(RXNum, EnRX, EnLNA);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_RX_ConnectRFBISTSignal(SYS_IPNum_e RXNum, RX_RFBIST_Input_e SelectInput)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_RX_ConnectRFBISTSignal(RXNum, SelectInput);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_RX_ConfigLOx3Gain(SYS_IPNum_e RXIP, RX_LOx3_GainSelect_e GainSelect, uint8_t GainCode, BOOL BinSearchFromAbove, uint8_t CalTargetOffset)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_RX_ConfigLOx3Gain(RXIP, GainSelect, GainCode, BinSearchFromAbove, CalTargetOffset);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_RX_CalibrateLOx3Gain(SYS_IPNum_e RXIP, BOOL ReadCalibStatus, uint32_t CalCheckTimeOutUs)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_RX_CalibrateLOx3Gain(RXIP, ReadCalibStatus, CalCheckTimeOutUs);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_RX_UpdateLOLowLevelTh(SYS_IPNum_e RXNum, CAFC_VCOBWSel_e VCOSel, BC_FLOAT InputFrequency)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_RX_UpdateLOLowLevelTh(RXNum, VCOSel, InputFrequency);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_RX_ConfigBBD(SYS_IPNum_e RXIP, BOOL EnableBBDRX, BOOL NormalSensitivity, BOOL Grounded)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_RX_ConfigBBD(RXIP, EnableBBDRX, NormalSensitivity, Grounded);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}



#if defined(__cplusplus)
}
#endif
