/*
 * Copyright 2019-2022 NXP
 * NXP Confidential. This software is owned or controlled by NXP and may only
 * be used strictly in accordance with the applicable license terms. By
 * expressly accepting such terms or by downloading, installing, activating
 * and/or otherwise using the software, you are agreeing that you have read,
 * and that you agree to comply with and are bound by, such license terms. If
 * you do not agree to be bound by the applicable license terms, then you may
 * not retain, install, activate or otherwise use the software.
 */

#include "math.h"
#include "bc_sys.h"
#include "bc_spi.h"
#include "bc_cc.h"
#include "bc_conf.h"
#include "bc_sc.h"
#include "bc_te.h"
#include "plf.h"
#include "helper_bcsys.h"

BC_ERRCODE BC_SYS_GetAPISWVersion(SYS_ApiVersion_t *pVersion)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    if (pVersion == NULL)
    {
        ErrCode = BC_ERR_SYS_PTR_ADDR_NULL;
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        pVersion->Major = BC_API_MAJOR_VERSION;
        pVersion->Minor = BC_API_MINOR_VERSION;
        pVersion->Patch = BC_API_PATCH_VERSION;
    }
    return ErrCode;
}

BC_ERRCODE BC_SYS_Init(void)
{
    BC_ERRCODE ErrCode;
    ErrCode = Helper_Init();
    return ErrCode;
}

BC_ERRCODE BC_SYS_ProgramChirp(SYS_ProfID_e ProfID, SYS_ProfChirpTiming_t *pChirpTiming,
                               SYS_ProfChirpFreq_t *pChirpFreq, SYS_ProfChirpSampleDeci_t *pProfSampleDeci,
                               BOOL TXBPS[3], float32_t PhaseRotation[3], BOOL TXFastSW[3], BOOL TXEN[3], BOOL RXEN[4],
                               RX_Gain_Control_e RXGain[4], SYS_RXLPF_CornerFreq_e RXLPF[4], SYS_RXHPF_CornerFreq_e RXHPF[4])
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    SYS_IPList_t AppConfig;

    /* ********** Get APP Config *********** */
    ErrCode = BC_CC_GetAppConfiguration(&AppConfig, NULL);
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = Helper_ConfigTE(ProfID, pChirpTiming, pProfSampleDeci, TXBPS, PhaseRotation, TXFastSW, TXEN, RXEN);
    }
    /* ********** Prepare for RX_ConfigProfile *********** */
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = Helper_ConfigRX(ProfID, RXGain, RXLPF, RXHPF, &AppConfig);
    }
    /* ********** Prepare for SC_ConfigProfile *********** */
    if ((BC_ERR_NOERROR == ErrCode) && (AppConfig.CAFC == TRUE))
    {
        ErrCode = Helper_ConfigSC(ProfID, pChirpTiming, pChirpFreq, pProfSampleDeci);
    }
    /* ********** Prepare for SC_ConfigProfile *********** */
    if ((BC_ERR_NOERROR == ErrCode) && (AppConfig.CAFC == TRUE))
    {
        ErrCode = Helper_ConfigCAFC(ProfID, pChirpFreq);
    }
    return ErrCode;
}

BC_ERRCODE BC_SYS_ChangeFStart(SYS_ProfID_e ProfID, BC_FLOAT StartFreqHz, SYS_SBChangeMode_e Mode, uint8_t *pSubband)
{
    BC_ERRCODE ErrCode;
    ErrCode = Helper_ChangeFStart(ProfID, StartFreqHz, Mode, pSubband);
    return ErrCode;
}

BC_ERRCODE BC_SYS_CopyProfile(SYS_IPNum_e IPNum, SYS_ProfID_e SrcProfID, SYS_ProfID_e DestProfID)
{
    BC_ERRCODE ErrCode;
    ErrCode = Helper_CopyProfile(IPNum, SrcProfID, DestProfID);
    return ErrCode;
}

BC_ERRCODE BC_SYS_ConfigTXPR(BOOL pUseDDMA[3], TE_DDMAMod_e DDMAMode, float32_t pDDMAInitPhase[3], float32_t pDDMAPhaseUpdate[3], TE_PRPCGenMode_e pFinalPCGenMode[3], BOOL pBPSKSource[3])
{
    BC_ERRCODE ErrCode;
    ErrCode = Helper_ConfigTXPR(pUseDDMA, DDMAMode, pDDMAInitPhase, pDDMAPhaseUpdate, pFinalPCGenMode, pBPSKSource);
    return ErrCode;
}

BC_ERRCODE BC_SYS_CalibrationCWMode(SYS_ProfID_e ProfileID, BOOL KeepMiddleFreq)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    if (ProfileID < e_SYS_PROFILE_INVALID)
    {
        ErrCode = BC_SC_KeepMiddleFrequency(KeepMiddleFreq);
        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = BC_TE_LoadProfile(ProfileID);
        }
        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = PLF_TM_Sleep(SYS_WAIT_CENTER_TO_MID_FREQ_30US);
        }
    }
    else
    {
        ErrCode = BC_ERR_INPUTOUTOFRANGE;
    }
    return ErrCode;
}

BC_ERRCODE BC_SYS_MCLKIntegrityCheck(void)
{
    BC_ERRCODE ErrCode;
    ErrCode = Helper_MCLKIntegrityCheck();
    return ErrCode;
}

BC_ERRCODE BC_SYS_TXSensorIntegrityCheck(void)
{
    BC_ERRCODE ErrCode;
    ErrCode = Helper_TXSensorIntegrityCheck();
    return ErrCode;
}

BC_ERRCODE BC_SYS_CAFCSensorIntegrityCheck(SYS_ProfID_e ChirpProfSel, uint16_t NumChirp)
{
    BC_ERRCODE ErrCode;
    ErrCode = Helper_CAFCSensorIntegrityCheck(ChirpProfSel, NumChirp);
    return ErrCode;
}

BC_ERRCODE BC_SYS_SetCSOut(TE_CSOutCfg_t *pCSOutCfg)
{
    BC_ERRCODE ErrCode;
    ErrCode = Helper_SetCSOut(pCSOutCfg);
    return ErrCode;
}

BC_ERRCODE BC_SYS_ReadTempSensor(float32_t *pKelvinTX1, float32_t *pKelvinTX2, float32_t *pKelvinTX3, float32_t *pKelvinChirp)
{
    BC_ERRCODE ErrCode;
    ErrCode = Helper_ReadTempSensor(pKelvinTX1, pKelvinTX2, pKelvinTX3, pKelvinChirp);
    return ErrCode;
}

BC_ERRCODE BC_SYS_RegCRCCheckCtrl(SYS_CRC_Trigger_Event_e CRCTriggerEvent)
{
    BC_ERRCODE ErrCode;
    ErrCode = Helper_RegCRCCheckCtrl(CRCTriggerEvent);
    return ErrCode;
}

BC_ERRCODE BC_SYS_InitMasterSlaveMode(BOOL EnSlaveMode)
{
    BC_ERRCODE ErrCode;
    ErrCode = Helper_InitMasterSlaveMode(EnSlaveMode);
    return ErrCode;
}

BC_ERRCODE BC_SYS_AutoSubbandSwitching(BOOL Enable, uint8_t SubbandSteps)
{
    BC_ERRCODE ErrCode;
    ErrCode = Helper_AutoSubbandSwitching(Enable, SubbandSteps);
    return ErrCode;
}

BC_ERRCODE BC_SYS_SetDevice(PLF_SPITarget_e TargetDevice)
{
    BC_ERRCODE ErrCode;
    ErrCode = Helper_SetDevice(TargetDevice);
    return ErrCode;
}
BC_ERRCODE BC_SYS_RegCRCMCUTrigIntCheck(void)
{
    BC_ERRCODE ErrCode;
    ErrCode = Helper_RegCRCMCUTrigIntCheck();
    return ErrCode;
}

BC_ERRCODE BC_SYS_LoiBBDCheck(BOOL CheckLOIN, BOOL NormalSensitivityLOIN, BOOL GroundedLOIN, BOOL NormalSensitivityLOOUT, BOOL GroundedLOOUT)
{
     BC_ERRCODE ErrCode;
    ErrCode = Helper_LoiBBDCheck(CheckLOIN, NormalSensitivityLOIN, GroundedLOIN, NormalSensitivityLOOUT, GroundedLOOUT);
    return ErrCode;
}


