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
@file bc_te.c

@version

@brief Barracuda API code file

This is the code file for Barracuda APIs. All exported API code can be found in
this file.

*/


#include <stdint.h>

#include "bc_types.h"
#include "bc_err.h"

#include "bc_te.h"

#ifdef TEF82XX_CFG_ES2 
#include "hal_es2_te.h"
#endif

#if defined(__cplusplus)
extern "C"
{
#endif

BC_ERRCODE BC_TE_ConfigProfile(TE_ConfigProfile_t *pConfigProfile)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_TE_ConfigProfile(pConfigProfile);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_TE_SetChirpTrgMode(TE_ChirpTrgMode_t *pChirpTrgMode)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_TE_SetChirpTrgMode(pChirpTrgMode);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_TE_StartChirp(void)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_TE_StartChirp();
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_TE_EnableChirp(BOOL Enable)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_TE_EnableChirp(Enable);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_TE_WaitForReady(void)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_TE_WaitForReady();
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_TE_LoadProfile(SYS_ProfID_e ChirpProfSel)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_TE_LoadProfile(ChirpProfSel);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_TE_SetRxFilterCtrls(BOOL HPFResetReleaseCtrl, BOOL RxActiveCtrl, float32_t HPFResetReleaseDelay, float32_t RxActiveDelay)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_TE_SetRxFilterCtrls(HPFResetReleaseCtrl, RxActiveCtrl, HPFResetReleaseDelay, RxActiveDelay);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_TE_ConfigStatic(TE_StaticConfig_t *pStaticConfig)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_TE_ConfigStatic(pStaticConfig);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_TE_SetPhaseCtrls(BOOL pEnBPCtrlFromQPSKIO[3], BOOL EnAsyncBPSKSamp, BOOL EnAsyncQPSKSamp, TE_PRPCGenMode_e pFinalPCGenMode[3])
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_TE_SetPhaseCtrls(pEnBPCtrlFromQPSKIO, EnAsyncBPSKSamp, EnAsyncQPSKSamp, pFinalPCGenMode);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_TE_UpdateProfTiming(SYS_ProfID_e ProfileNum, float32_t DwellTime, float32_t TxOnDelayFromRefPoint, BOOL TrigPoint, BOOL pBPPhaseCtrlTx[3], BOOL pEnTx[3])
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_TE_UpdateProfTiming(ProfileNum, DwellTime, TxOnDelayFromRefPoint, TrigPoint, pBPPhaseCtrlTx, pEnTx);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_TE_UpdateProfADC(SYS_ProfID_e ProfileNum, BOOL PDCBWWide, uint16_t NumSamples, float32_t SettleTime, TE_OutputSampRate_e OutSampRate)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_TE_UpdateProfADC(ProfileNum, PDCBWWide, NumSamples, SettleTime, OutSampRate);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_TE_UpdateProfPRCtrl(SYS_ProfID_e ProfileNum, float32_t pPRPhaseCtrlTx[3], SYS_VCN_e VirtualChNo)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_TE_UpdateProfPRCtrl(ProfileNum, pPRPhaseCtrlTx, VirtualChNo);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_TE_SetDCPowOnDelay(float32_t DCPowerOnDelay, float32_t SafetyMontrDelay, BOOL SafetyMontrActCtrl)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_TE_SetDCPowOnDelay(DCPowerOnDelay, SafetyMontrDelay, SafetyMontrActCtrl);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_TE_ConfigTXRXDCGrpDelay(float32_t TXDCPowOnGrpDelay, float32_t RXDCPowOnGrpDelay, float32_t pFineControl[4])
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_TE_ConfigTXRXDCGrpDelay(TXDCPowOnGrpDelay, RXDCPowOnGrpDelay, pFineControl);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_TE_SetJumpBackTime(float32_t JumpBackTime)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_TE_SetJumpBackTime(JumpBackTime);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_TE_SetChirpSeqInterval(float32_t SeqInterval)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_TE_SetChirpSeqInterval(SeqInterval);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_TE_SetBiasSwitchCtrl(BOOL EnFastBiasSwitch, float32_t FastBiasSwitchDelay, BOOL EnReplicaBiasBypass, float32_t ReplicaBiasBypassDelay)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_TE_SetBiasSwitchCtrl(EnFastBiasSwitch, FastBiasSwitchDelay, EnReplicaBiasBypass, ReplicaBiasBypassDelay);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_TE_UpdateProfChirpPeriod(SYS_ProfID_e ProfileNum, float32_t ChirpPeriod, BOOL pActiveRx[4], BOOL pActiveTx[3])
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_TE_UpdateProfChirpPeriod(ProfileNum, ChirpPeriod, pActiveRx, pActiveTx);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_TE_ConfigProfileSequencing(SYS_ProfID_e ChirpProfSel, uint8_t pProfileList[8], uint8_t ProfileRepeatCount, BOOL EnProfileReset, BOOL EnChirp, uint16_t PRSeed)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_TE_ConfigProfileSequencing(ChirpProfSel, pProfileList, ProfileRepeatCount, EnProfileReset, EnChirp, PRSeed);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_TE_SetChirpSeqCtrl(uint32_t NumSeqInBurst, uint16_t NumChirpInSeq)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_TE_SetChirpSeqCtrl(NumSeqInBurst, NumChirpInSeq);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_TE_SetPRDDMACtrls(BOOL pUseDDMA[3], TE_DDMAMod_e DDMAMode, float32_t pDDMAInitPhase[3], float32_t pDDMAPhaseUpdate[3])
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_TE_SetPRDDMACtrls(pUseDDMA, DDMAMode, pDDMAInitPhase, pDDMAPhaseUpdate);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_TE_ResetTxPRDDMA(void)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_TE_ResetTxPRDDMA();
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_TE_TXPRSafetyCheckDelay(BOOL EnPRSafetyCheck, float32_t PRSafetyStartDelay)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_TE_TXPRSafetyCheckDelay(EnPRSafetyCheck, PRSafetyStartDelay);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}



#if defined(__cplusplus)
}
#endif
