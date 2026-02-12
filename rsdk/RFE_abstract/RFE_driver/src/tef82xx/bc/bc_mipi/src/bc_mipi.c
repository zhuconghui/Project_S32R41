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
@file bc_mipi.c

@version

@brief Barracuda API code file

This is the code file for Barracuda APIs. All exported API code can be found in
this file.

*/


#include <stdint.h>

#include "bc_types.h"
#include "bc_err.h"

#include "bc_mipi.h"

#ifdef TEF82XX_CFG_ES2 
#include "hal_es2_mipi.h"
#endif

#if defined(__cplusplus)
extern "C"
{
#endif

BC_ERRCODE BC_MIPI_Init(void)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_MIPI_Init();
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_MIPI_Config(uint8_t NLanes, MIPI_DataRate_e DataRate)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_MIPI_Config(NLanes, DataRate);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_MIPI_ConfigPDC(BOOL DisPDCFilter, BOOL EnPDCSync, BOOL EnWAProcess, BOOL EnUnsignedOut, uint8_t pDecModeDelays[4])
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_MIPI_ConfigPDC(DisPDCFilter, EnPDCSync, EnWAProcess, EnUnsignedOut, pDecModeDelays);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_MIPI_ConfigVC(MIPI_VCNum_t *pSelectVCs, MIPI_VCClearFrame_t *pClearFrameVCs)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_MIPI_ConfigVC(pSelectVCs, pClearFrameVCs);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_MIPI_MeasureFreq(MIPI_FreqCountDeviation_e FreqDeviationValue, float32_t CountPeriod, float32_t *pFrequency)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_MIPI_MeasureFreq(FreqDeviationValue, CountPeriod, pFrequency);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_MIPI_ConfigADAPT(MIPI_DisableADCChannels_t *pDisADCChannels, BOOL DisADCChanDataSelect, MIPI_ClearChirpNum_e EnChirpNumClearReg, BOOL EnPacketCRCFooter, BOOL EnPacketHeader)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_MIPI_ConfigADAPT(pDisADCChannels, DisADCChanDataSelect, EnChirpNumClearReg, EnPacketCRCFooter, EnPacketHeader);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_MIPI_EnTransmission(BOOL EnableDataTx)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_MIPI_EnTransmission(EnableDataTx);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}

BC_ERRCODE BC_MIPI_EnContinuousClock(BOOL EnableContClock)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_MIPI_EnContinuousClock(EnableContClock);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}

BC_ERRCODE BC_MIPI_ConfigTestMode(BOOL EnTest, MIPI_ConfigTestParms_t *pTestParameters)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_MIPI_ConfigTestMode(EnTest, pTestParameters);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_MIPI_ConfigMetaData(MIPI_ConfigMetaData_t *pConfigMetaData)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_MIPI_ConfigMetaData(pConfigMetaData);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}



#if defined(__cplusplus)
}
#endif
