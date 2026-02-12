/*
 * Copyright 2020-2022 NXP
 * NXP Confidential. This software is owned or controlled by NXP and may only
 * be used strictly in accordance with the applicable license terms. By
 * expressly accepting such terms or by downloading, installing, activating
 * and/or otherwise using the software, you are agreeing that you have read,
 * and that you agree to comply with and are bound by, such license terms. If
 * you do not agree to be bound by the applicable license terms, then you may
 * not retain, install, activate or otherwise use the software.
 */

#include <stdint.h>
#include "bc_types.h"
#include "bc_err.h"
#include "bc_cc.h"
#include "bc_cafc.h"
#include "bc_conf.h"
#include "bc_te.h"
#include "bc_rx.h"
#include "bc_sc.h"
#include "bc_sys.h"

#include "helper_bcsys.h"
#ifdef TEF82XX_CFG_ES2
#include "helper_es2sys.h"
#endif

static BC_ERRCODE Helper_GetFStartAtTSettleBegin(SYS_ProfChirpFreq_t *pChirpFreq, SYS_ProfChirpTiming_t *pChirpTiming, float32_t SlopeSign, float32_t RampSlope, float32_t TACQ, BC_FLOAT TotalUsedBW, BC_FLOAT *pFStartAtTSettleBegin);
static BC_ERRCODE Helper_GetAcqTime(float32_t *pTACQ, SYS_ProfChirpTiming_t *pChirpTiming, SYS_ProfChirpFreq_t *pChirpFreq, SYS_ProfChirpSampleDeci_t *pProfSampleDeci);
static BC_ERRCODE ValidateConfigSCParams(SYS_ProfChirpTiming_t * pChirpTiming, SYS_ProfChirpFreq_t *pChirpFreq, float32_t TACQ, BC_FLOAT TotalUsedBW);

static BC_ERRCODE ValidateConfigSCParams(SYS_ProfChirpTiming_t *pChirpTiming, SYS_ProfChirpFreq_t *pChirpFreq, float32_t TACQ, BC_FLOAT TotalUsedBW)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    if (pChirpTiming->TReset > TACQ)
    {
        ErrCode = BC_ERR_SYS_INVALID_RESET_TIME;
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        switch (pChirpFreq->VCOSel)
        {
        case e_CAFC_1GBAND:
            if (TotalUsedBW > SC_TOTAL_BW_1G_BAND_MAX)
            {
                ErrCode = BC_ERR_SYS_TOTAL_BW_OUTOFRANGE;
            }
            break;
        case e_CAFC_5GNARROW:
            if (TotalUsedBW > SC_TOTAL_BW_5G_NARROW_MAX)
            {
                ErrCode = BC_ERR_SYS_TOTAL_BW_OUTOFRANGE;
            }
            break;
        case e_CAFC_5GWIDE:
            if (TotalUsedBW > SC_TOTAL_BW_5G_WIDE_MAX)
            {
                ErrCode = BC_ERR_SYS_TOTAL_BW_OUTOFRANGE;
            }
            break;
        default:
            ErrCode = BC_ERR_CAFC_BWOUTOFRANGE;
            break;
        }
    }
    return ErrCode;
}
BC_ERRCODE Helper_ConfigTE(SYS_ProfID_e ProfID, SYS_ProfChirpTiming_t *pChirpTiming, SYS_ProfChirpSampleDeci_t *pProfSampleDeci,
                           BOOL TXBPS[3], float32_t PhaseRotation[3], BOOL TXFastSW[3], BOOL TXEN[3], BOOL RXEN[4])
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    uint16_t DivCheckMask = 0x0u;
    TE_ConfigProfile_t TEProfile;

    if ((pChirpTiming == NULL) || (pProfSampleDeci == NULL) || (TXBPS == NULL) || (PhaseRotation == NULL) || (TXFastSW == NULL) || (TXEN == NULL) || (RXEN == NULL))
    {
        ErrCode = BC_ERR_SYS_PTR_ADDR_NULL;
    }
    /* ********** Prepare for TE_ConfigProfile *********** */
    if (BC_ERR_NOERROR == ErrCode)
    {
        // configure profile ID
        TEProfile.ProfileNum = ProfID;
        TEProfile.PDCBWWide = pProfSampleDeci->PDCBWWide;
        switch (pProfSampleDeci->Decimation)
        {
        case 1u:
            if (pProfSampleDeci->ADCMode == e_SYS_ADC80MSPS_DEBUG)
            {
                TEProfile.OutSampRate = e_TE_OSR_FUN80_NONF40;
                TEProfile.NumSamples = pProfSampleDeci->RawNumSamples;
            }
            else
            {
                ErrCode = BC_ERR_INPUTOUTOFRANGE;
            }
            break;
        case 2u:
            TEProfile.OutSampRate = e_TE_OSR_FUN40_NONF20;
            // divide by 2
            // NumSamples is basically the acq time, since the clock is of 40MHz, this is equal to the number of sample at ADC at 40MSPC
            TEProfile.NumSamples = pProfSampleDeci->RawNumSamples >> 1u;
            DivCheckMask = SYS_NUM_SAMP_DIV_ODD_MASK;
            break;
        case 4u:
            // divide by 4
            TEProfile.OutSampRate = e_TE_OSR_FUN20_NONF10;
            // NumSamples is basically the acq time, since the clock is of 40MHz, this is equal to the number of sample at ADC at 40MSPC
            TEProfile.NumSamples = pProfSampleDeci->RawNumSamples >> 1u;
            DivCheckMask = SYS_NUM_SAMP_DIV_BY_4_MASK;
            break;
        case 8u:
            // divide by 8
            TEProfile.OutSampRate = e_TE_OSR_FUN10_NONF5;
            // NumSamples is basically the acq time, since the clock is of 40MHz, this is equal to the number of sample at ADC at 40MSPC
            TEProfile.NumSamples = pProfSampleDeci->RawNumSamples >> 1u;
            DivCheckMask = SYS_NUM_SAMP_DIV_BY_8_MASK;
            break;
        case 16u:
            // divide by 16
            TEProfile.OutSampRate = e_TE_OSR_FUN5_NONF2P5;
            // NumSamples is basically the acq time, since the clock is of 40MHz, this is equal to the number of sample at ADC at 40MSPC
            TEProfile.NumSamples = pProfSampleDeci->RawNumSamples >> 1u;
            DivCheckMask = SYS_NUM_SAMP_DIV_BY_16_MASK;
            break;
        default:
            ErrCode = BC_ERR_INPUTOUTOFRANGE;
            break;
        }
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        if (((pProfSampleDeci->RawNumSamples & DivCheckMask) != 0x0u) || (pProfSampleDeci->RawNumSamples == 0x0u))
        {
            ErrCode = BC_ERR_SYS_RAW_NUM_SAMPLE_INVALID;
        }
    }

    if (BC_ERR_NOERROR == ErrCode)
    {
        // chirp timing
        TEProfile.DwellTime = pChirpTiming->TDwell;
        TEProfile.SettleTime = pChirpTiming->TSettle;
        // Tchirp should not be shorter than the total timing.
        TEProfile.ChirpPeriod = pChirpTiming->TChirp;

        // trigger point selection
        TEProfile.TrigPoint = pChirpTiming->TriggerTXSWAndBPSAtTSettle;
        // SW and BPS delay after trigger point
        TEProfile.TxOnDelayFromRefPoint = pChirpTiming->TXSWAndBPSDelay;

        // TRX settings
        TEProfile.EnTx1 = TXFastSW[0];
        TEProfile.EnTx2 = TXFastSW[1];
        TEProfile.EnTx3 = TXFastSW[2];
        TEProfile.ActiveTx1 = TXEN[0];
        TEProfile.ActiveTx2 = TXEN[1];
        TEProfile.ActiveTx3 = TXEN[2];
        TEProfile.BPPhaseCtrlTx1 = TXBPS[0];
        TEProfile.BPPhaseCtrlTx2 = TXBPS[1];
        TEProfile.BPPhaseCtrlTx3 = TXBPS[2];
        TEProfile.PRPhaseCtrlTx1 = PhaseRotation[0];
        TEProfile.PRPhaseCtrlTx2 = PhaseRotation[1];
        TEProfile.PRPhaseCtrlTx3 = PhaseRotation[2];
        TEProfile.ActiveRx1 = RXEN[0];
        TEProfile.ActiveRx2 = RXEN[1];
        TEProfile.ActiveRx3 = RXEN[2];
        TEProfile.ActiveRx4 = RXEN[3];
        TEProfile.VirtualChNo = pProfSampleDeci->VirtualChNo;
        // Config TE profiles

        ErrCode = BC_TE_ConfigProfile(&TEProfile);
    }
    return ErrCode;
}
BC_ERRCODE Helper_ConfigRX(SYS_ProfID_e ProfID, RX_Gain_Control_e RXGain[4], SYS_RXLPF_CornerFreq_e RXLPF[4], SYS_RXHPF_CornerFreq_e RXHPF[4], SYS_IPList_t *pAppConfig)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    RX_ConfigProfile_t RXProfile;
    if ((RXGain == NULL) || (RXLPF == NULL) || (RXHPF == NULL) || (pAppConfig == NULL))
    {
        ErrCode = BC_ERR_SYS_PTR_ADDR_NULL;
    }
    else
    {
        if ((TRUE == pAppConfig->RX1))
        {
            RXProfile.HPFCutoffFreq = RXHPF[0];
            RXProfile.LPFCutoffFreq = RXLPF[0];
            RXProfile.EnLPFWideBandMode = ((uint8_t)RXLPF[0] == (uint8_t)e_SYS_RXLPF_WIDE) ? TRUE : FALSE;
            RXProfile.RXGain = RXGain[0];
            ErrCode = BC_RX_ConfigProfile(e_SYS_RX1, ProfID, &RXProfile);
        }
        if ((TRUE == pAppConfig->RX2) && (ErrCode == BC_ERR_NOERROR))
        {
            RXProfile.HPFCutoffFreq = RXHPF[1];
            RXProfile.LPFCutoffFreq = RXLPF[1];
            RXProfile.EnLPFWideBandMode = ((uint8_t)RXLPF[1] == (uint8_t)e_SYS_RXLPF_WIDE) ? TRUE : FALSE;
            RXProfile.RXGain = RXGain[1];
            ErrCode = BC_RX_ConfigProfile(e_SYS_RX2, ProfID, &RXProfile);
        }
        if ((TRUE == pAppConfig->RX3) && (ErrCode == BC_ERR_NOERROR))
        {
            RXProfile.HPFCutoffFreq = RXHPF[2];
            RXProfile.LPFCutoffFreq = RXLPF[2];
            RXProfile.EnLPFWideBandMode = ((uint8_t)RXLPF[2] == (uint8_t)e_SYS_RXLPF_WIDE) ? TRUE : FALSE;
            RXProfile.RXGain = RXGain[2];
            ErrCode = BC_RX_ConfigProfile(e_SYS_RX3, ProfID, &RXProfile);
        }
        if ((TRUE == pAppConfig->RX4) && (ErrCode == BC_ERR_NOERROR))
        {
            RXProfile.HPFCutoffFreq = RXHPF[3];
            RXProfile.LPFCutoffFreq = RXLPF[3];
            RXProfile.EnLPFWideBandMode = ((uint8_t)RXLPF[3] == (uint8_t)e_SYS_RXLPF_WIDE) ? TRUE : FALSE;
            RXProfile.RXGain = RXGain[3];
            ErrCode = BC_RX_ConfigProfile(e_SYS_RX4, ProfID, &RXProfile);
        }
    }
    return ErrCode;
}

static BC_ERRCODE Helper_GetAcqTime(float32_t *pTACQ, SYS_ProfChirpTiming_t *pChirpTiming, SYS_ProfChirpFreq_t *pChirpFreq, SYS_ProfChirpSampleDeci_t *pProfSampleDeci)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    if ((pChirpTiming == NULL) || (pChirpFreq == NULL) || (pProfSampleDeci == NULL))
    {
        ErrCode = BC_ERR_SYS_PTR_ADDR_NULL;
    }
    else
    {
        if ((pProfSampleDeci->RawNumSamples == 0x0u))
        {
            ErrCode = BC_ERR_SYS_RAW_NUM_SAMPLE_INVALID;
        }
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        // ADC acquisition period according to sampling interval
        // ADC80debug and ADC40legacy not to use.
        if ((pProfSampleDeci->ADCMode == e_SYS_ADC80MSPS_DEBUG) || (pProfSampleDeci->ADCMode == e_SYS_ADC80MSPS_FUNCTIONAL))
        {
            // equivalent to * 12.5f / 1000.0f
            *pTACQ = (float32_t)pProfSampleDeci->RawNumSamples / 80.0f;
        }
        else if ((pProfSampleDeci->ADCMode == e_SYS_ADC40MSPS_LEGACY))
        {
            // equivalent to * 25.0f / 1000.0f
            *pTACQ = (float32_t)pProfSampleDeci->RawNumSamples / 40.0f;
        }
        else
        {
            ErrCode = BC_ERR_INPUTOUTOFRANGE;
        }
    }
    return ErrCode;
}
static BC_ERRCODE Helper_GetFStartAtTSettleBegin(SYS_ProfChirpFreq_t *pChirpFreq, SYS_ProfChirpTiming_t *pChirpTiming, float32_t SlopeSign, float32_t RampSlope, float32_t TACQ, BC_FLOAT TotalUsedBW, BC_FLOAT *pFStartAtTSettleBegin)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    float32_t TempValue;
    BC_FLOAT SlopeSign64;

    switch (pChirpFreq->InputFreqType)
    {
    case e_SYS_STARTFREQFULLRAMP:
        *pFStartAtTSettleBegin = pChirpFreq->InputFrequency;
        break;
    case e_SYS_STARTFREQACQ:
        TempValue = (SlopeSign * RampSlope * pChirpTiming->TSettle);
        *pFStartAtTSettleBegin = (pChirpFreq->InputFrequency - (BC_FLOAT)TempValue);
        break;
    case e_SYS_CENTERFREQFULLRAMP:
        SlopeSign64 = ((pChirpFreq->DownChirp) == TRUE) ? (BC_FLOAT)-0.5 : (BC_FLOAT)0.5;
        // center of full ramp - half of BW during full ramp
        *pFStartAtTSettleBegin = pChirpFreq->InputFrequency - (SlopeSign64 * TotalUsedBW);
        break;
    case e_SYS_CENTERFREQACQ:
        TempValue = (SlopeSign * RampSlope * ((TACQ * 0.5f) + pChirpTiming->TSettle));
        // center of ACQ - half of BW during ACQ - BW during tSettle
        *pFStartAtTSettleBegin = ((pChirpFreq->InputFrequency) - (BC_FLOAT)TempValue);
        break;
    default:
        ErrCode = BC_ERR_INPUTOUTOFRANGE;
        break;
    }
    return ErrCode;
}
BC_ERRCODE Helper_ConfigSC(SYS_ProfID_e ProfID, SYS_ProfChirpTiming_t *pChirpTiming, SYS_ProfChirpFreq_t *pChirpFreq, SYS_ProfChirpSampleDeci_t *pProfSampleDeci)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    // ADC acquisition time
    float32_t TACQ = 0.0f;
    // full frequency ramp time
    float32_t RampTime = 0.0f;
    float32_t RampSlope = 0.0f;
    BC_FLOAT RampSlope64;
    BC_FLOAT FStartAtTSettleBegin = 0.0f;
    BC_FLOAT TotalUsedBW = 0.0f;
    BC_FLOAT TempValue64;
    float32_t TempValue;
    float32_t SlopeSign;

    ErrCode = Helper_GetAcqTime(&TACQ, pChirpTiming, pChirpFreq, pProfSampleDeci);
   
    if (ErrCode == BC_ERR_NOERROR)
    {
        // the assumption is that InputBW can be negative for down chirp
        RampTime = TACQ + pChirpTiming->TSettle + pChirpTiming->TJumpback;
        // calculate chirp slope according to user input types
        switch (pChirpFreq->InputBWType)
        {
        case e_SYS_BWACQ:
            // chirp BW during ADC ACQ / ACQ time
            RampSlope64 = pChirpFreq->InputBW / (BC_FLOAT)TACQ;
            RampSlope = (float32_t)RampSlope64;
            TempValue = (pChirpTiming->TSettle + pChirpTiming->TJumpback) * RampSlope;
            TempValue64 = (BC_FLOAT)TempValue;
            TotalUsedBW = (pChirpFreq->InputBW + (TempValue64));
            break;
        case e_SYS_BWFULLRAMP:
            // full ramp BW / full ramp time
            RampSlope64 = pChirpFreq->InputBW / (BC_FLOAT)RampTime;
            RampSlope = (float32_t)RampSlope64;
            TotalUsedBW = pChirpFreq->InputBW;
            break;
        default:
            ErrCode = BC_ERR_INPUTOUTOFRANGE;
            break;
        }
        if (BC_ERR_NOERROR == ErrCode)
        {
            ErrCode = ValidateConfigSCParams(pChirpTiming, pChirpFreq, TACQ, TotalUsedBW);
        }
        if (BC_ERR_NOERROR == ErrCode)
        {
            SlopeSign = ((pChirpFreq->DownChirp) == TRUE) ? -1.0f : 1.0f;
            // calculate actual start frequency based on user input types
            ErrCode = Helper_GetFStartAtTSettleBegin(pChirpFreq, pChirpTiming, SlopeSign, RampSlope, TACQ, TotalUsedBW, &FStartAtTSettleBegin);
        }
        if (BC_ERR_NOERROR == ErrCode)
        {
            // finally configure SC profile
            ErrCode = BC_SC_ConfigProfile(ProfID, FStartAtTSettleBegin, TotalUsedBW, (float32_t)RampTime, pChirpFreq->DownChirp, pChirpTiming->TReset);
        }
        if ((BC_ERR_NOERROR == ErrCode) && (TotalUsedBW == 0.0f))
        {
            ErrCode = BC_SC_SetZeroRamp(ProfID);
        }
    }
    return ErrCode;
}

BC_ERRCODE Helper_ConfigCAFC(SYS_ProfID_e ProfID, SYS_ProfChirpFreq_t *pChirpFreq)
{
    BC_ERRCODE ErrCode;
#ifdef TEF82XX_CFG_ES2
    ErrCode = Helper_ES2_ConfigCAFC(ProfID, pChirpFreq);
#else
    ErrCode = BC_ERR_FUNCNOTEXIST;
#endif
    return ErrCode;
}

BC_ERRCODE Helper_ChangeFStart(SYS_ProfID_e ProfID, BC_FLOAT StartFreqHz, SYS_SBChangeMode_e Mode, uint8_t *pSubband)
{
    BC_ERRCODE ErrCode;
#ifdef TEF82XX_CFG_ES2
    ErrCode = Helper_ES2_ChangeFStart(ProfID, StartFreqHz, Mode, pSubband);
#else
    ErrCode = BC_ERR_FUNCNOTEXIST;
#endif
    return ErrCode;
}
BC_ERRCODE Helper_CopyProfile(SYS_IPNum_e IPNum, SYS_ProfID_e SrcProfID, SYS_ProfID_e DestProfID)
{
    BC_ERRCODE ErrCode;
#ifdef TEF82XX_CFG_ES2
    ErrCode = Helper_ES2_CopyProfile(IPNum, SrcProfID, DestProfID);
#else
    ErrCode = BC_ERR_FUNCNOTEXIST;
#endif
    return ErrCode;
}
BC_ERRCODE Helper_ConfigTXPR(BOOL pUseDDMA[3], TE_DDMAMod_e DDMAMode, float32_t pDDMAInitPhase[3], float32_t pDDMAPhaseUpdate[3], TE_PRPCGenMode_e pFinalPCGenMode[3], BOOL pBPSKSource[3])
{
    BC_ERRCODE ErrCode;
#ifdef TEF82XX_CFG_ES2
    ErrCode = Helper_ES2_ConfigTXPR(pUseDDMA, DDMAMode, pDDMAInitPhase, pDDMAPhaseUpdate, pFinalPCGenMode, pBPSKSource);
#else
    ErrCode = BC_ERR_FUNCNOTEXIST;
#endif
    return ErrCode;
}

BC_ERRCODE Helper_MCLKIntegrityCheck(void)
{
    BC_ERRCODE ErrCode;
#ifdef TEF82XX_CFG_ES2
    ErrCode = Helper_ES2_MCLKIntegrityCheck();
#else
    ErrCode = BC_ERR_FUNCNOTEXIST;
#endif
    return ErrCode;
}
BC_ERRCODE Helper_TXSensorIntegrityCheck(void)
{
    BC_ERRCODE ErrCode;
#ifdef TEF82XX_CFG_ES2
    ErrCode = Helper_ES2_TXSensorIntegrityCheck();
#else
    ErrCode = BC_ERR_FUNCNOTEXIST;
#endif
    return ErrCode;
}

BC_ERRCODE Helper_CAFCSensorIntegrityCheck(SYS_ProfID_e ChirpProfSel, uint16_t NumChirp)
{
    BC_ERRCODE ErrCode;
#ifdef TEF82XX_CFG_ES2
    ErrCode = Helper_ES2_CAFCSensorIntegrityCheck(ChirpProfSel, NumChirp);
#else
    ErrCode = BC_ERR_FUNCNOTEXIST;
#endif
    return ErrCode;
}

BC_ERRCODE Helper_SetCSOut(TE_CSOutCfg_t *pCSOutCfg)
{
    BC_ERRCODE ErrCode;
#ifdef TEF82XX_CFG_ES2
    ErrCode = Helper_ES2_SetCSOut(pCSOutCfg);
#else
    ErrCode = BC_ERR_FUNCNOTEXIST;
#endif
    return ErrCode;
}
BC_ERRCODE Helper_ReadTempSensor(float32_t *pKelvinTX1, float32_t *pKelvinTX2, float32_t *pKelvinTX3, float32_t *pKelvinChirp)
{
    BC_ERRCODE ErrCode;
#ifdef TEF82XX_CFG_ES2
    ErrCode = Helper_ES2_ReadTempSensor(pKelvinTX1, pKelvinTX2, pKelvinTX3, pKelvinChirp);
#else
    ErrCode = BC_ERR_FUNCNOTEXIST;
#endif
    return ErrCode;
}
BC_ERRCODE Helper_RegCRCCheckCtrl(SYS_CRC_Trigger_Event_e CRCTriggerEvent)
{
    BC_ERRCODE ErrCode;
#ifdef TEF82XX_CFG_ES2
    ErrCode = Helper_ES2_RegCRCCheckCtrl(CRCTriggerEvent);
#else
    ErrCode = BC_ERR_FUNCNOTEXIST;
#endif
    return ErrCode;
}
BC_ERRCODE Helper_InitMasterSlaveMode(BOOL EnSlaveMode)
{
    BC_ERRCODE ErrCode;
#ifdef TEF82XX_CFG_ES2
    ErrCode = Helper_ES2_InitMasterSlaveMode(EnSlaveMode);
#else
    ErrCode = BC_ERR_FUNCNOTEXIST;
#endif
    return ErrCode;
}
BC_ERRCODE Helper_AutoSubbandSwitching(BOOL Enable, uint8_t SubbandSteps)
{
    BC_ERRCODE ErrCode;
#ifdef TEF82XX_CFG_ES2
    ErrCode = Helper_ES2_AutoSubbandSwitching(Enable, SubbandSteps);
#else
    ErrCode = BC_ERR_FUNCNOTEXIST;
#endif
    return ErrCode;
}
BC_ERRCODE Helper_SetDevice(PLF_SPITarget_e TargetDevice)
{
    BC_ERRCODE ErrCode;
#ifdef TEF82XX_CFG_ES2
    ErrCode = Helper_ES2_SetDevice(TargetDevice);
#else
    ErrCode = BC_ERR_FUNCNOTEXIST;
#endif
    return ErrCode;
}

BC_ERRCODE Helper_InitConfigADC(void)
{
    BC_ERRCODE ErrCode;
#ifdef TEF82XX_CFG_ES2
    ErrCode = Helper_ES2_InitConfigADC();
#else
    ErrCode = BC_ERR_FUNCNOTEXIST;
#endif
    return ErrCode;
}

BC_ERRCODE Helper_Init(void)
{
    BC_ERRCODE ErrCode;
#ifdef TEF82XX_CFG_ES2
    ErrCode = Helper_ES2_Init();
#else
    ErrCode = BC_ERR_FUNCNOTEXIST;
#endif
    return ErrCode;
}

BC_ERRCODE Helper_RegCRCMCUTrigIntCheck(void)
{
    BC_ERRCODE ErrCode;
#ifdef TEF82XX_CFG_ES2
    ErrCode = Helper_ES2_RegCRCMCUTrigIntCheck();
#else
    ErrCode = BC_ERR_FUNCNOTEXIST;
#endif
    return ErrCode;
}

BC_ERRCODE Helper_LoiBBDCheck(BOOL CheckLOIN, BOOL NormalSensitivityLOIN, BOOL GroundedLOIN, BOOL NormalSensitivityLOOUT, BOOL GroundedLOOUT)
{
   BC_ERRCODE ErrCode;
#ifdef TEF82XX_CFG_ES2
    ErrCode = Helper_ES2_LoiBBDCheck(CheckLOIN, NormalSensitivityLOIN, GroundedLOIN, NormalSensitivityLOOUT, GroundedLOOUT);
#else
    ErrCode = BC_ERR_FUNCNOTEXIST;
#endif
    return ErrCode;  
}
