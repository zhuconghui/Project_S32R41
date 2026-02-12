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
@file bc_cc.c

@version

@brief Barracuda API code file

This is the code file for Barracuda APIs. All exported API code can be found in
this file.

*/


#include <stdint.h>

#include "bc_types.h"
#include "bc_err.h"

#include "bc_cc.h"

#ifdef TEF82XX_CFG_ES2
#include "hal_es2_cc.h"
#endif

#if defined(__cplusplus)
extern "C"
{
#endif

BC_ERRCODE BC_CC_SetAppConfiguration(SYS_IPList_t *pAppConfig)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_CC_SetAppConfiguration(pAppConfig);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_CC_SetAppConfigMS(SYS_IPList_t *pAppConfig, PLF_SPITarget_e TargetDevice)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_CC_SetAppConfigMS(pAppConfig, TargetDevice);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_CC_SetMSDevice(PLF_SPITarget_e TargetDevice)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_CC_SetMSDevice(TargetDevice);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_CC_GetAppConfiguration(SYS_IPList_t *pAppConfig, uint32_t *pPONMask)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_CC_GetAppConfiguration(pAppConfig, pPONMask);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_CC_SetInterface(CC_InterfaceType_e SerialiserMode)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_CC_SetInterface(SerialiserMode);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_CC_GetInterface(CC_InterfaceType_e *pSerialiserMode)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_CC_GetInterface(pSerialiserMode);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_CC_SetPonClkRst(CC_PonClkRst_e Reg, CC_ModList_t *pModList)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_CC_SetPonClkRst(Reg, pModList);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_CC_SetDynPowModeDown(CC_DynPowDnIPList_t *pPowDnIPList, float32_t PowDownDelayPerChirp, float32_t PowDownDelayPerSequence)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_CC_SetDynPowModeDown(pPowDnIPList, PowDownDelayPerChirp, PowDownDelayPerSequence);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_CC_EnLDOControl(uint8_t VoltOutSSBMOD, uint8_t VoltOutLVDS, uint8_t VoltOutMIPI, uint8_t VoltOutADC)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_CC_EnLDOControl(VoltOutSSBMOD, VoltOutLVDS, VoltOutMIPI, VoltOutADC);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_CC_ConfigPad(BOOL SetOutPort, CC_PINSpeed_e Speed, SYS_ExtPinID_e PadName)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_CC_ConfigPad(SetOutPort, Speed, PadName);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_CC_ConfigMCUInt(BOOL Polarity, BOOL TriggerMode, uint8_t IntPeriod)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_CC_ConfigMCUInt(Polarity, TriggerMode, IntPeriod);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_CC_EnDisClrInt(CC_CmdEnClrInt_e CommandReg, CC_IntEvent_t *pIntEvents)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_CC_EnDisClrInt(CommandReg, pIntEvents);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_CC_GetIntStatus(BOOL UseRawInt, CC_IntEvent_t *pIntStatus)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_CC_GetIntStatus(UseRawInt, pIntStatus);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_CC_SwitchMcuIntCSOut(BOOL CsOutEn)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_CC_SwitchMcuIntCSOut(CsOutEn);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_CC_GetMaskVersion(uint8_t *pMaskVersion)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_CC_GetMaskVersion(pMaskVersion);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_CC_TriggerADCBGCalib(void)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_CC_TriggerADCBGCalib();
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}



#if defined(__cplusplus)
}
#endif
