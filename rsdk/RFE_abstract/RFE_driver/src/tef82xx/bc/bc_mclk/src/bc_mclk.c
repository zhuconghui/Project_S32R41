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
@file bc_mclk.c

@version

@brief Barracuda API code file

This is the code file for Barracuda APIs. All exported API code can be found in
this file.

*/


#include <stdint.h>

#include "bc_types.h"
#include "bc_err.h"

#include "bc_mclk.h"

#ifdef TEF82XX_CFG_ES2 
#include "hal_es2_mclk.h"
#endif

#if defined(__cplusplus)
extern "C"
{
#endif

BC_ERRCODE BC_MCLK_AutoCalib(BOOL ExtendedReCal)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_MCLK_AutoCalib(ExtendedReCal);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_MCLK_GetCalibrationStatus(BOOL *pLocked, MCLK_CalibrationStatus_t *pCalibStatus)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_MCLK_GetCalibrationStatus(pLocked, pCalibStatus);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_MCLK_SetClkBuffers(BOOL EnChirp480M, BOOL EnSer480600M, BOOL EnADC1200M, BOOL EnSSB600M, BOOL EnADC40M)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_MCLK_SetClkBuffers(EnChirp480M, EnSer480600M, EnADC1200M, EnSSB600M, EnADC40M);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_MCLK_ConfigMSPCTiming(MCLK_MSPCWaitTime_e MSPCTime, MCLK_MSPCSkewWaitTime_e SkewTime, MCLK_MSPCDelayWaitTime_e DelayTime)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_MCLK_ConfigMSPCTiming(MSPCTime, SkewTime, DelayTime);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_MCLK_StartMSPC(void)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_MCLK_StartMSPC();
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_MCLK_CheckMSPCStatus(BOOL *pNeedCalib)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_MCLK_CheckMSPCStatus(pNeedCalib);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_MCLK_ConfigManualMSPC(uint8_t OutPutClkSkewCode, uint8_t RefClkDelayCode)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_MCLK_ConfigManualMSPC(OutPutClkSkewCode, RefClkDelayCode);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}



#if defined(__cplusplus)
}
#endif
