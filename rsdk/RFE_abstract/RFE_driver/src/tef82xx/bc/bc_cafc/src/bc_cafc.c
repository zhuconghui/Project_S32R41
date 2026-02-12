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
@file bc_cafc.c

@version

@brief Barracuda API code file

This is the code file for Barracuda APIs. All exported API code can be found in
this file.

*/


#include <stdint.h>

#include "bc_types.h"
#include "bc_err.h"

#include "bc_cafc.h"

#ifdef TEF82XX_CFG_ES2 
#include "hal_es2_cafc.h"
#endif

#if defined(__cplusplus)
extern "C"
{
#endif

BC_ERRCODE BC_CAFC_ReadFreqCounter(float32_t CntDurationMicroSec, float32_t *pRawFreqResultHz, float32_t *pRFFreqResultHz, SYS_ProfID_e ProfID)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_CAFC_ReadFreqCounter(CntDurationMicroSec, pRawFreqResultHz, pRFFreqResultHz, ProfID);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_CAFC_ForceLoopConditions(BOOL EnableLoopFilter, uint8_t ForcedDACCode, SYS_ProfID_e ProfID, CAFC_VCOBWSel_e VCOBWSel, uint8_t Subband, float32_t ForcedDividerValue)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_CAFC_ForceLoopConditions(EnableLoopFilter, ForcedDACCode, ProfID, VCOBWSel, Subband, ForcedDividerValue);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_CAFC_GenSBTable(CAFC_VCOBWSel_e VCOBWSel, uint8_t HighDACCode, uint8_t LowDACCode, uint8_t StartSB, uint8_t NumItems)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_CAFC_GenSBTable(VCOBWSel, HighDACCode, LowDACCode, StartSB, NumItems);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_CAFC_GetSBTable(CAFC_VCOBWSel_e VCOBWSel, BC_FLOAT pFBegin[128], BC_FLOAT pFEnd[128], BC_FLOAT pBW[128])
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_CAFC_GetSBTable(VCOBWSel, pFBegin, pFEnd, pBW);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_CAFC_EnableVCO(BOOL Enable)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_CAFC_EnableVCO(Enable);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_CAFC_ConfigLoopFilter(CAFC_PLLLPFSel_e PLLLPFSel, CAFC_LoopFilterLUTSel_e LPFLUTSel, float32_t PLLLoopBW, BC_FLOAT EffFc, BOOL DownChirp)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_CAFC_ConfigLoopFilter(PLLLPFSel, LPFLUTSel, PLLLoopBW, EffFc, DownChirp);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_CAFC_UpdateLoopFilterCP(CAFC_PLLLPFSel_e PLLLPFSel, CAFC_LoopFilterLUTSel_e LPFLUTSel, float32_t PLLLoopBW, float32_t KvcoAverage, BOOL DownChirp)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_CAFC_UpdateLoopFilterCP(PLLLPFSel, LPFLUTSel, PLLLoopBW, KvcoAverage, DownChirp);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_CAFC_GetLoopFilterEntry(CAFC_LoopFilterLUTSel_e LPFLUTSel, float32_t PLLLoopBW, CAFC_LPFLUTEntry_t *pTableEntry)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_CAFC_GetLoopFilterEntry(LPFLUTSel, PLLLoopBW, pTableEntry);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_CAFC_ConfigVCOProfile(SYS_ProfID_e ProfID, CAFC_VCOBWSel_e VCOSel, CAFC_PLLLPFSel_e PLLLPFSel, uint8_t iVCOFine, uint8_t Subband)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_CAFC_ConfigVCOProfile(ProfID, VCOSel, PLLLPFSel, iVCOFine, Subband);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_CAFC_ConfigFastReturn(BOOL EnableGS, BOOL EnableINJ)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_CAFC_ConfigFastReturn(EnableGS, EnableINJ);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_CAFC_ConfigStatic(BOOL EnableCP, BOOL EnableVCOLDO, BOOL EnableDividerLDO, BOOL EnableCPPFDLDO, BOOL EnableAllBias)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_CAFC_ConfigStatic(EnableCP, EnableVCOLDO, EnableDividerLDO, EnableCPPFDLDO, EnableAllBias);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_CAFC_ConfigMonitor(BOOL EnableAmpMon, BOOL EnableLockDet, CAFC_LockDetSettings *pLockDetSettings)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_CAFC_ConfigMonitor(EnableAmpMon, EnableLockDet, pLockDetSettings);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_CAFC_ConfigAAFC(BOOL EnableAAFC, CAFC_AACSettings_t *pAACSettings, CAFC_AFCSettings_t *pAFCSettings)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_CAFC_ConfigAAFC(EnableAAFC, pAACSettings, pAFCSettings);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_CAFC_GetAAFCStatus(BOOL *pAACLocked, BOOL *pAFCLocked, BOOL *pAACError, BOOL *pAFCError, uint8_t *pAFCSubbandChoice, uint8_t *pAACiVCOChoice)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_CAFC_GetAAFCStatus(pAACLocked, pAFCLocked, pAACError, pAFCError, pAFCSubbandChoice, pAACiVCOChoice);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_CAFC_EnableRFLevelRMSDet(BOOL EnRMSDet, CAFC_VCOBWSel_e VCOSel)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_CAFC_EnableRFLevelRMSDet(EnRMSDet, VCOSel);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_CAFC_SetVtuneVoltage(uint8_t ForceVtuneStartVolt, uint8_t ForceVtuneCenterVolt)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_CAFC_SetVtuneVoltage(ForceVtuneStartVolt, ForceVtuneCenterVolt);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_CAFC_GetVCOCalibStatus(CAFC_AAFCStatus_t *pAAFCStatus, CAFC_KVCOStatus_t *pKVCOStatus, CAFC_DVDTStatus_t *pDVDTStatus)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_CAFC_GetVCOCalibStatus(pAAFCStatus, pKVCOStatus, pDVDTStatus);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_CAFC_CalibAAFCInjDAC(BOOL PerformKVCO, BOOL PerformDVDT, SYS_ProfChirpFreq_t *pChirpFreq, SYS_ProfChirpTiming_t *pChirpTiming, SYS_ProfID_e CalibrateProfID, SYS_StoreInProfile_t *pStoreInProfiles, float32_t CalibTimeOutUs, float32_t TempKelvinChirp, float32_t *pKvcoAverage)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_CAFC_CalibAAFCInjDAC(PerformKVCO, PerformDVDT, pChirpFreq, pChirpTiming, CalibrateProfID, pStoreInProfiles, CalibTimeOutUs, TempKelvinChirp, pKvcoAverage);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_CAFC_SetVCOCalibTimeOut(float32_t CalibTimeOutUs)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_CAFC_SetVCOCalibTimeOut(CalibTimeOutUs);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_CAFC_LoadProfile(SYS_ProfID_e ChirpProfSel)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_CAFC_LoadProfile(ChirpProfSel);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_CAFC_FastBiasChirpPll(void)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_CAFC_FastBiasChirpPll();
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}



#if defined(__cplusplus)
}
#endif
