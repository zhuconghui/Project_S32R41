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

#ifdef TEF82XX_CFG_ES2
#include <math.h>
#include <stdlib.h>

#include "bc_types.h"
#include "bc_err.h"
#include "bc_conf.h"
#include "bc_spi.h"

#include "plf.h"
#include "hal_es2_cafc.h"
#include "hal_es2_otp.h"

#include "hal_es2_te.h"

// Register header
#ifdef BUILD_FOR_VAL
#include "v_es2_cafc.h"
#include "v_es2_sc.h"
#include "v_es2_te.h"
#else
#include "reg_es2_cafc.h"
#include "reg_es2_sc.h"
#include "reg_es2_te.h"
#endif

#define NUM_ENTRY_LOOPFILTER_1G_TABLE 45u
#define NUM_ENTRY_LOOPFILTER_2G_TABLE 44u
#define NUM_ENTRY_LOOPFILTER_4G_TABLE 51u

// local storage of 3 subband tables
// row 0 is 1G, row 1 is 5GNarrow, row2 is 5GWide
static BC_FLOAT gFStart[3][128] = {{0.0f}};
static BC_FLOAT gFStop[3][128] = {{0.0f}};
static BC_FLOAT gBW[3][128] = {{0.0f}};
static BC_ERRCODE Helper_ES2_ReadFrequency(float32_t CntDurationMicroSec, float32_t *pRawFreqResultHz, float32_t *pRFFreqResultHz, SYS_ProfID_e ProfID);
static BC_ERRCODE Helper_ES2_ConfigEnableSettings(BOOL EnableLoopFilter, uint8_t ForcedDACCode);
static BC_ERRCODE Helper_ES2_ConfigVCOControl(SYS_ProfID_e ProfID, CAFC_VCOBWSel_e VCOBWSel, uint8_t Subband);
static BC_ERRCODE Helper_ES2_DivideForceControl(SYS_ProfID_e ProfID, float32_t ForcedDividerValue);
static BC_ERRCODE Helper_ES2_CalculateDacInjection(SYS_ProfChirpFreq_t *pChirpFreq, SYS_ProfChirpTiming_t *pChirpTiming, float32_t Acquisitiontime, uint8_t AcqC1, uint8_t AcqC2, uint32_t DvDtCntC1, uint32_t CntHighKvcoAvg, uint32_t CntLowKvcoAvg);
static BC_ERRCODE Helper_ES2_CalculateSlope(SYS_ProfChirpFreq_t *pChirpFreq, SYS_ProfChirpTiming_t *pChirpTiming, float32_t Acquisitiontime, float32_t *pACQSlope, float32_t *pRSTSlope, float32_t *pFStartCount);
static BC_ERRCODE Helper_ES2_GetAcqCurr(BOOL PerformDVDT, SYS_ProfChirpFreq_t *pChirpFreq, SYS_ProfChirpTiming_t *pChirpTiming, SYS_ProfID_e CalibrateProfID, float32_t *pAcquisitiontime, uint8_t *pAcqC1, uint8_t *pAcqC2);
static BC_ERRCODE Helper_ES2_ConfigHighPllBW(CAFC_LoopFilterLUTSel_e LPFLUTSel, float32_t LPFUnitRes, float32_t GainCorrOTP, float32_t VCOGainCorr);
static BC_ERRCODE Helper_ES2_GetGainCorrRstBW(CAFC_LoopFilterLUTSel_e LPFLUTSel, float32_t *pGainCorrOTP, float32_t *pPLLLoopBWReset);
static BC_ERRCODE Helper_ES2_SetLDPolarity(CAFC_LoopFilterLUTSel_e LPFLUTSel, BOOL DownChirp);
static void Helper_ES2_GetKvcoRef(CAFC_LoopFilterLUTSel_e LPFLUTSel, float32_t *pKvcoRef);
static BC_ERRCODE Helper_ES2_UpdateLoopFilter(CAFC_PLLLPFSel_e PLLLPFSel, CAFC_LoopFilterLUTSel_e LPFLUTSel, float32_t PLLLoopBW, float32_t KvcoAverageLocal, BOOL DownChirp);
static BC_ERRCODE Helper_ES2_AACSettingRangeChck(CAFC_AACSettings_t *pAACSettings);
static BC_ERRCODE Helper_ES2_ConfigAACSettings(CAFC_AACSettings_t *pAACSettings);
static BC_ERRCODE Helper_ES2_AFCSettingRangeChck(CAFC_AFCSettings_t *pAFCSettings);
static BC_ERRCODE Helper_ES2_AFCLockRangeChck(CAFC_AFCSettings_t *pAFCSettings);
static BC_ERRCODE Helper_ES2_ConfigAFCSettings(CAFC_AFCSettings_t *pAFCSettings);
static BC_ERRCODE Helper_ES2_SelSBTable(CAFC_VCOBWSel_e VCOBWSel, uint8_t StartSB, uint8_t NumItems, uint8_t *pIndex);
static BC_ERRCODE Helper_ES2_EnAmpMonLd(uint8_t EnableFlag);
static BC_ERRCODE Helper_ES2_GetCAFCFreq(CAFC_VCOBWSel_e VCOBWSel, uint8_t DACCode, uint8_t loop0, float32_t *pCAFCFreqHz);
static void Helper_ES2_FlushSB(uint8_t StartSB, uint8_t NumItems, BC_FLOAT *pFStart, BC_FLOAT *pFStop, BC_FLOAT *pBW);
static BC_ERRCODE Helper_ES2_ConfigPllBW(CAFC_PLLLPFSel_e PLLLPFSel, BC_FLOAT EffFc, BC_FLOAT LPFRefFreq, float32_t GainCorrOTP, CAFC_LPFLUTEntry_t *pTableEntry, float32_t *pVCOGainCorr, BOOL DownChirp);
static BC_ERRCODE Helper_ES2_CfgPllLpfC1C2C3(CAFC_PLLLPFSel_e PLLLPFSel, CAFC_LPFLUTEntry_t *pTableEntry, CAFC_LPFLUTEntry_t *pTableEntryReset, float32_t *pLPFUnitRes);
static BC_ERRCODE Helper_ES2_CfgLoopFilterRangeChk(CAFC_PLLLPFSel_e PLLLPFSel, CAFC_LoopFilterLUTSel_e LPFLUTSel, BC_FLOAT EffFc);
static BC_ERRCODE Helper_ES2_CalDacInjRangeCheck(SYS_ProfChirpFreq_t *pChirpFreq);
static BC_ERRCODE Helper_ES2_GetChirpInjDac(SYS_ProfChirpFreq_t *pChirpFreq, float32_t *pRefFreqSlope, uint32_t *pMinKvcoRefI, uint32_t *pMinusP, uint32_t *pAG, uint32_t *pQG, uint32_t *pF0RefI, uint32_t *pF1RefI);
static BC_ERRCODE Helper_ES2_CalibRangeCheck(SYS_ProfID_e CalibrateProfID, SYS_StoreInProfile_t *pStoreInProfiles);
static BC_ERRCODE Helper_ES2_CheckDvdtError(BOOL PerformDVDT, uint8_t KvcoDvdtEnable, uint32_t AafcLockDvdtCountStatusVal32);
static BC_ERRCODE Helper_ES2_CalibStatus(BOOL PerformDVDT, uint8_t KvcoDvdtEnable, float32_t CalibTimeOutUs, uint32_t *pDvdtCntC1Onfly, SYS_ProfChirpFreq_t *pChirpFreq, SYS_StoreInProfile_t *pStoreInProfiles);
static BC_ERRCODE Helper_ES2_CalCulateKvcoAvg(uint8_t KvcoDvdtEnable, float32_t *pKvcoAverage, uint32_t *pCntLowKvcoAvg, uint32_t *pCntHighKvcoAvg);
static BC_ERRCODE Helper_ES2_SetForceDivider(BOOL PerformKVCO, uint32_t *pDivideForceControlVal32);
static BC_ERRCODE Helper_ES2_SetInitOverrideSB(CAFC_LoopFilterLUTSel_e LPFLUTSel);
static BC_ERRCODE Helper_ES2_SetForceDivider(BOOL PerformKVCO, uint32_t *pDivideForceControlVal32);
static BC_ERRCODE Helper_ES2_GetSubbandSkip(CAFC_VCOBWSel_e VCOSel, uint8_t *pSubbandSkip, uint8_t *pSubBandCheckNum, uint8_t *pMaxSB);
static BC_ERRCODE Helper_ES2_CopyCorrectSBSet(uint8_t CorrectedSubBand, SYS_StoreInProfile_t *pStoreInProfiles);
static BC_ERRCODE Helper_ES2_CalibCorrection(CAFC_VCOBWSel_e VCOSel, SYS_StoreInProfile_t *pStoreInProfiles);
static void Helper_CAFCStoreInProfile(SYS_StoreInProfile_t *pStoreInProfiles, BOOL pProfile[SYS_MAX_PROFILE_COUNT]);
static void Helper_CAFCStoreInProfile(SYS_StoreInProfile_t *pStoreInProfiles, BOOL pProfile[SYS_MAX_PROFILE_COUNT])
{
    pProfile[0] = pStoreInProfiles->Profile0;
    pProfile[1] = pStoreInProfiles->Profile1;
    pProfile[2] = pStoreInProfiles->Profile2;
    pProfile[3] = pStoreInProfiles->Profile3;
    pProfile[4] = pStoreInProfiles->Profile4;
    pProfile[5] = pStoreInProfiles->Profile5;
    pProfile[6] = pStoreInProfiles->Profile6;
    pProfile[7] = pStoreInProfiles->Profile7;
    pProfile[8] = pStoreInProfiles->Profile8;
}
static BC_ERRCODE Helper_ES2_ReadFrequency(float32_t CntDurationMicroSec, float32_t *pRawFreqResultHz, float32_t *pRFFreqResultHz, SYS_ProfID_e ProfID)
{
    BC_ERRCODE ErrCode;
    float32_t PLLDivVal = 0.0f;
    uint16_t NStartAddr;
    R2M06_FreqCounterReadValueUnion_t FreqCounterReadValue;
    R2M06_DivideForceControlUnion_t DivideForceControl;
    R2M05_NStartRfProfile0Union_t NStartRfProfile;

    // 2^26
    uint32_t tempDiv = 67108864u;

    // freq counting is done in time.
    // read out final counter value
    ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_FREQ_COUNTER_READ_VALUE_U16, &FreqCounterReadValue.val_u32);

    // return according to user supplied pointers
    if ((NULL != pRawFreqResultHz) && (BC_ERR_NOERROR == ErrCode))
    {
        // raw frequency reading.
        *pRawFreqResultHz = (float32_t)FreqCounterReadValue.bits_st.FreqCountValue / CntDurationMicroSec * 1e6f;
    }

    if ((BC_ERR_NOERROR == ErrCode) && (NULL != pRFFreqResultHz))
    {
        ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_DIVIDE_FORCE_CONTROL_U16, &DivideForceControl.val_u32);
    }
    if ((BC_ERR_NOERROR == ErrCode) && (NULL != pRFFreqResultHz))
    {
        if ((1u == DivideForceControl.bits_st.CtlForceDivider))
        {
            // divider is forced, use the forced value.
            PLLDivVal = (float32_t)DivideForceControl.bits_st.CtlDivForce;
            // return the PLL output RF freqeuncy in Hz.
            *pRFFreqResultHz = ((float32_t)FreqCounterReadValue.bits_st.FreqCountValue / CntDurationMicroSec) * 1e6f * PLLDivVal * 2.0f;
        }
        else if (ProfID <= e_SYS_PROFILE_8) // only single profile
        {
            // divider is not forced, read out the divider frequency from selected profile
            NStartAddr = R2M05_N_START_RF_PROFILE0_U16 + (((uint16_t)ProfID - (uint16_t)e_SYS_PROFILE_0) * (R2M05_N_START_RF_PROFILE1_U16 - R2M05_N_START_RF_PROFILE0_U16));
            ErrCode = BC_SPI_Read(e_SYS_SC, NStartAddr, &NStartRfProfile.val_u32);
            if (BC_ERR_NOERROR == ErrCode)
            {
                PLLDivVal = (float32_t)NStartRfProfile.bits_st.NstartintrfProfile0 + ((float32_t)NStartRfProfile.bits_st.NstartfracrfProfile0 / (float32_t)tempDiv);
                *pRFFreqResultHz = ((float32_t)FreqCounterReadValue.bits_st.FreqCountValue / CntDurationMicroSec) * 1e6f * PLLDivVal * 2.0f;
            }
        }
        else
        {
            ErrCode = BC_ERR_CAFC_INPUTOUTOFRANGE;
        }
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_CAFC_ReadFreqCounter(float32_t CntDurationMicroSec, float32_t *pRawFreqResultHz, float32_t *pRFFreqResultHz, SYS_ProfID_e ProfID)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M06_RefCntrInitUnion_t RefCntrInit;
    R2M06_FreqCounterReadValueUnion_t FreqCounterReadValue;
    R2M06_FreqCounterStartUnion_t FreqCounterStart;
    uint32_t WhileLoopCount = 0u;
    uint32_t StoreFreqCounterStart = 0u;
    uint32_t StoreRefCntrInit = 0u;

    // param validation
    // testing if counting period is smaller than 0.05us(50ns), to avoid testing equivalence with floating point number
    if (((pRawFreqResultHz == NULL) && (pRFFreqResultHz == NULL)) || (CntDurationMicroSec < 0.05f) || (CntDurationMicroSec > 1638.0f))
    {
        ErrCode = BC_ERR_CAFC_INPUTOUTOFRANGE;
    }

    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_REF_CNTR_INIT_U16, &RefCntrInit.val_u32);
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        // store current register value
        StoreRefCntrInit = RefCntrInit.val_u32;
        // convert us to 25ns based value
        RefCntrInit.bits_st.RefCountValue = (uint16_t)(lroundf(CntDurationMicroSec * 40.0f));
        // write frequency counting duration
        ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, R2M06_REF_CNTR_INIT_U16, RefCntrInit.val_u32);
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_FREQ_COUNTER_START_U16, &FreqCounterStart.val_u32);
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        // store the current register value
        StoreFreqCounterStart = FreqCounterStart.val_u32;
        // config the freq counter
        FreqCounterStart.bits_st.EnableFuncSafetyFreqMea = 0u;
        FreqCounterStart.bits_st.NumLsbbitsIgnored = 0u;
        FreqCounterStart.bits_st.FreqStart = 0u;
        ErrCode = BC_SPI_Write(e_SYS_CAFC, R2M06_FREQ_COUNTER_START_U16, FreqCounterStart.val_u32);
        if (BC_ERR_NOERROR == ErrCode)
        {
            // trigger the freq counter to start counting.
            FreqCounterStart.bits_st.FreqStart = 1u;
            ErrCode = BC_SPI_Write(e_SYS_CAFC, R2M06_FREQ_COUNTER_START_U16, FreqCounterStart.val_u32);
        }
    }

    // take timestamp
    // initialze Doneflag to false
    FreqCounterReadValue.bits_st.DoneFlag = FALSE;
    do
    {
        if (BC_ERR_NOERROR == ErrCode)
        {
            ErrCode = PLF_TM_Sleep(CAFC_READFREQCOUNTER_SLEEP);
        }
        if (ErrCode == BC_ERR_NOERROR)
        {
            // read out done
            ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_FREQ_COUNTER_READ_VALUE_U16, &FreqCounterReadValue.val_u32);
        }
        if ((WhileLoopCount >= CAFC_FREQ_CNT_TIMEOUT) && (BC_ERR_NOERROR == ErrCode))
        {
            ErrCode = BC_ERR_CAFC_FREQCNTTIMEOUT;
        }
        WhileLoopCount++;
    } while ((FreqCounterReadValue.bits_st.DoneFlag == FALSE) && (BC_ERR_NOERROR == ErrCode));

    if ((ErrCode == BC_ERR_NOERROR) && (FreqCounterReadValue.bits_st.DoneFlag == TRUE))
    {
        ErrCode = Helper_ES2_ReadFrequency(CntDurationMicroSec, pRawFreqResultHz, pRFFreqResultHz, ProfID);
    }

    if (ErrCode == BC_ERR_NOERROR)
    {
        // config the freq counter to preivious setting
        ErrCode = BC_SPI_Write(e_SYS_CAFC, R2M06_FREQ_COUNTER_START_U16, StoreFreqCounterStart);
    }

    if (ErrCode == BC_ERR_NOERROR)
    {
        // config ref_count_init to previous setting;
        ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, R2M06_REF_CNTR_INIT_U16, StoreRefCntrInit);
    }

    return ErrCode;
}

static BC_ERRCODE Helper_ES2_ConfigEnableSettings(BOOL EnableLoopFilter, uint8_t ForcedDACCode)
{
    BC_ERRCODE ErrCode;
    R2M06_LpfEnableSettingsUnion_t LpfEnableSettings;

    ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_LPF_ENABLE_SETTINGS_U16, &LpfEnableSettings.val_u32);

    if (BC_ERR_NOERROR == ErrCode)
    {
        LpfEnableSettings.bits_st.CtlLpfIntEnSpi = (uint8_t)EnableLoopFilter;

        if (ForcedDACCode <= 127u)
        {
            // legal force DAC code, then force DAC output voltage.
            LpfEnableSettings.bits_st.CtlLpfForceVtuneEnSpi = 1u;
            LpfEnableSettings.bits_st.CtlLpfProgForceVoltageSpi = ForcedDACCode;
        }
        else
        {
            // disable DAC code force
            LpfEnableSettings.bits_st.CtlLpfForceVtuneEnSpi = 0u;
        }
        ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, R2M06_LPF_ENABLE_SETTINGS_U16, LpfEnableSettings.val_u32);
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_ConfigVCOControl(SYS_ProfID_e ProfID, CAFC_VCOBWSel_e VCOBWSel, uint8_t Subband)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M06_VcoRegProfile0Union_t VcoRegProfile;
    R2M06_VcoControlUnion_t VcoControl;
    uint16_t VCOReg;

    VCOReg = R2M06_VCO_REG_PROFILE0_U16 + (((uint16_t)ProfID - (uint16_t)e_SYS_PROFILE_0) * (R2M06_VCO_REG_PROFILE1_U16 - R2M06_VCO_REG_PROFILE0_U16));

    ErrCode = BC_SPI_Read(e_SYS_CAFC, VCOReg, &VcoRegProfile.val_u32);
    // select one VCO according to user's input
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_VCO_CONTROL_U16, &VcoControl.val_u32);
    }

    if (ErrCode == BC_ERR_NOERROR)
    {
        if (VCOBWSel == e_CAFC_1GBAND)
        {
            // select 1G BW VCO
            VcoControl.bits_st.CtlSelVco1G5GSpi = 0u;
            ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, R2M06_VCO_CONTROL_U16, VcoControl.val_u32);
        }
        else
        {
            // select 5G BW VCO
            VcoControl.bits_st.CtlSelVco1G5GSpi = 1u;
            ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, R2M06_VCO_CONTROL_U16, VcoControl.val_u32);
            if (ErrCode == BC_ERR_NOERROR)
            {
                // select 2G or 4G BW using 5GVCO, accroding to user's input
                VcoRegProfile.bits_st.CtlVcoBandwidthSpiProfile0 = (VCOBWSel == e_CAFC_5GWIDE) ? 1u : 0u;
            }
        }

        // force subband or not according to user's input
        if (Subband <= 127u)
        {
            VcoRegProfile.bits_st.CtlVcoCoarseTuning9GSpiProfile0 = Subband;
        }
        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = BC_SPI_Write(e_SYS_CAFC, VCOReg, VcoRegProfile.val_u32);
        }
    }
    return ErrCode;
}

static BC_ERRCODE Helper_ES2_DivideForceControl(SYS_ProfID_e ProfID, float32_t ForcedDividerValue)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M06_DivideForceControlUnion_t DivideForceControl;
    R2M05_NStartRfProfile0Union_t NStartRfProfile;

    uint16_t NStartReg = R2M05_N_START_RF_PROFILE0_U16;
    float32_t NStartInt = 0.0f;
    float32_t NStartFrac = 0.0f;

    NStartReg = R2M05_N_START_RF_PROFILE0_U16 + (((uint16_t)ProfID - (uint16_t)e_SYS_PROFILE_0) * (R2M05_N_START_RF_PROFILE1_U16 - R2M05_N_START_RF_PROFILE0_U16));

    ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_DIVIDE_FORCE_CONTROL_U16, &DivideForceControl.val_u32);

    if ((ForcedDividerValue == 0.0f) && (BC_ERR_NOERROR == ErrCode)) // user wants to force divider
    {
        // simply cancel CAFC local divider force
        DivideForceControl.bits_st.CtlForceDivider = 0u;
    }
    if ((ForcedDividerValue == 1.0f) && (BC_ERR_NOERROR == ErrCode))
    {
        // do nothing, keep current divider force settings untouched.
    }
    if ((BC_ERR_NOERROR == ErrCode) && (ForcedDividerValue != 1.0f) && (ForcedDividerValue != 0.0f)) // user does not want to force divider
    {
        if (ceil(ForcedDividerValue) == ForcedDividerValue) // divider value is an integer
        {
            // divider is integer
            DivideForceControl.bits_st.CtlDivForce = (uint8_t)ForcedDividerValue;
            DivideForceControl.bits_st.CtlForceDivider = 1u;
        }
        else // divider is decimal
        {
            // cancel local divider force in CAFC. (will use SC force instead, in the following)
            DivideForceControl.bits_st.CtlForceDivider = 0u;

            ErrCode = BC_SPI_Read(e_SYS_SC, NStartReg, &NStartRfProfile.val_u32);
            if (BC_ERR_NOERROR == ErrCode)
            {
                // calculate integer and fractional part
                NStartFrac = modff(ForcedDividerValue, &NStartInt);
                NStartRfProfile.bits_st.NstartintrfProfile0 = (uint8_t)NStartInt;
                // 67108864u is 2^26, not using left shift to avoid MISRA errors
                NStartRfProfile.bits_st.NstartfracrfProfile0 = (uint32_t)(roundf(NStartFrac * (float32_t)(67108864u)));
                ErrCode = BC_SPI_WriteCheck(e_SYS_SC, NStartReg, NStartRfProfile.val_u32);
            }
        }
    }

    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, R2M06_DIVIDE_FORCE_CONTROL_U16, DivideForceControl.val_u32);
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_CalculateSlope(SYS_ProfChirpFreq_t *pChirpFreq, SYS_ProfChirpTiming_t *pChirpTiming, float32_t Acquisitiontime, float32_t *pACQSlope, float32_t *pRSTSlope, float32_t *pFStartCount)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    BC_FLOAT TotalUsedBW;
    BC_FLOAT FStart;
    float32_t RampTime; // unit: seconds
    float32_t ACQSlopeTmp;
    BC_FLOAT ACQSlope64;
    float32_t RSTSlopeTmp;
    float32_t TempValue;
    BC_FLOAT TempValue64;

    // calculate acquisition slope
    RampTime = Acquisitiontime + ((pChirpTiming->TSettle) * 1e-6f) + ((pChirpTiming->TJumpback) * 1e-6f);
    // calculate chirp slope according to user input types
    switch (pChirpFreq->InputBWType)
    {
    case e_SYS_BWACQ:
        // chirp BW during ADC ACQ / ACQ time
        ACQSlope64 = pChirpFreq->InputBW / (BC_FLOAT)Acquisitiontime;
        ACQSlopeTmp = (float32_t)ACQSlope64;
        TempValue = (ACQSlopeTmp * (((pChirpTiming->TSettle) * 1e-6f) + ((pChirpTiming->TJumpback) * 1e-6f)));
        TempValue64 = (BC_FLOAT)TempValue;
        TotalUsedBW = (pChirpFreq->InputBW + (TempValue64));
        break;
    case e_SYS_BWFULLRAMP:
        // full ramp BW / full ramp time
        ACQSlope64 = pChirpFreq->InputBW / (BC_FLOAT)RampTime;
        ACQSlopeTmp = (float32_t)ACQSlope64;
        TotalUsedBW = pChirpFreq->InputBW;
        break;
    default:
        ErrCode = BC_ERR_INPUTOUTOFRANGE;
        break;
    }
    // calculate FStart
    if (BC_ERR_NOERROR == ErrCode)
    {
        // calculate actual start frequency based on user input types
        float32_t SlopeSign = ((pChirpFreq->DownChirp) == TRUE) ? -1.0f : 1.0f;
        switch (pChirpFreq->InputFreqType)
        {
        case e_SYS_STARTFREQFULLRAMP:
            FStart = (pChirpFreq->InputFrequency);
            break;
        case e_SYS_STARTFREQACQ:
            TempValue = (SlopeSign * (ACQSlopeTmp * (pChirpTiming->TSettle) * 1e-6f));
            FStart = pChirpFreq->InputFrequency - (BC_FLOAT)TempValue;
            break;
        case e_SYS_CENTERFREQFULLRAMP:
            // center of full ramp - half of BW during full ramp
            TempValue = (SlopeSign * 0.5f);
            FStart = pChirpFreq->InputFrequency - ((BC_FLOAT)TempValue * TotalUsedBW);
            break;
        case e_SYS_CENTERFREQACQ:
            TempValue = (SlopeSign * ACQSlopeTmp) * ((Acquisitiontime * 0.5f) + (pChirpTiming->TSettle * 1e-6f));
            // center of ACQ - half of BW during ACQ - BW during tSettle
            FStart = (pChirpFreq->InputFrequency) - (BC_FLOAT)TempValue;
            break;
        default:
            ErrCode = BC_ERR_INPUTOUTOFRANGE;
            break;
        }
        if (ErrCode == BC_ERR_NOERROR)
        {
            float32_t Fstart32;
            FStart = FStart * (BC_FLOAT)100e-6;
            Fstart32 = (float32_t)FStart;
            Fstart32 = Fstart32 / 1200.0f;
            // f_cnt_start=fstart/Ndiv*t_integ/8; Ndiv = 50, t_integ = 100e-6s
            *pFStartCount = roundf(Fstart32);
            *pACQSlope = ACQSlopeTmp / 3.0f;
        }
    }
    // calculate RSTSlope
    if (ErrCode == BC_ERR_NOERROR)
    {
        BC_FLOAT RSTSLope64;
        RSTSlopeTmp = ((pChirpTiming->TReset) * 1e-6f) * 3.0f;
        RSTSLope64 = (TotalUsedBW / (BC_FLOAT)RSTSlopeTmp);
        *pRSTSlope = (float32_t)RSTSLope64;
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_GetChirpInjDac(SYS_ProfChirpFreq_t *pChirpFreq, float32_t *pRefFreqSlope, uint32_t *pMinKvcoRefI, uint32_t *pMinusP, uint32_t *pAG, uint32_t *pQG, uint32_t *pF0RefI, uint32_t *pF1RefI)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    uint32_t OTPCALChirpInjDAC1 = 0u;
    uint32_t OTPCALChirpInjDAC2 = 0u;
    uint32_t OTPCALChirpInjDAC3 = 0u;
    uint32_t OTPCALChirpInjDAC4 = 0u;
    uint32_t OTPCALChirpInjDAC5 = 0u;
    uint32_t OTPCALChirpInjDAC6 = 0u;
    uint32_t OTPCALChirpInjDAC7 = 0u;

    // read out OTP values for DAC code calibration
    ErrCode = HAL_ES2_OTP_GetOTPRegValue(OTP_CAL_CHIRP_INJ_DAC_1_INDEX, &OTPCALChirpInjDAC1);
    if ((ErrCode == BC_ERR_NOERROR) && (pChirpFreq->VCOSel == e_CAFC_1GBAND))
    {
        ErrCode = HAL_ES2_OTP_GetOTPRegValue(OTP_CAL_CHIRP_INJ_DAC_2_INDEX, &OTPCALChirpInjDAC2);
        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = HAL_ES2_OTP_GetOTPRegValue(OTP_CAL_CHIRP_INJ_DAC_3_INDEX, &OTPCALChirpInjDAC3);
        }
        *pRefFreqSlope = 17.1e12f;
        *pMinKvcoRefI = OTPCALChirpInjDAC1 & 0xFFu;           // to get kvco_g1_ref_i from OTP
        *pMinusP = (OTPCALChirpInjDAC2 & 0x00FFFC00u) >> 10u; // to get p_g1 from OTP
        *pAG = (OTPCALChirpInjDAC2 & 0x7F000000u) >> 24u;     // to get a_g1 from OTP
        *pQG = (OTPCALChirpInjDAC2 & 0x3FFu);                 // to get q_g1 from OTP
        *pF0RefI = (OTPCALChirpInjDAC3 & 0x1FFF0000u) >> 16u; // to get f0_g1_ref_i from OTP
        *pF1RefI = OTPCALChirpInjDAC3 & 0x1FFFu;              // to get f1_g1_ref_i from OTP
    }
    if ((ErrCode == BC_ERR_NOERROR) && (pChirpFreq->VCOSel == e_CAFC_5GNARROW))
    {
        ErrCode = HAL_ES2_OTP_GetOTPRegValue(OTP_CAL_CHIRP_INJ_DAC_4_INDEX, &OTPCALChirpInjDAC4);
        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = HAL_ES2_OTP_GetOTPRegValue(OTP_CAL_CHIRP_INJ_DAC_5_INDEX, &OTPCALChirpInjDAC5);
        }
        *pRefFreqSlope = 34.2e12f;
        *pMinKvcoRefI = (OTPCALChirpInjDAC1 & 0xFF00u) >> 8u; // to get kvco_g2_ref_i from OTP
        *pMinusP = (OTPCALChirpInjDAC4 & 0x00FFFC00u) >> 10u; // to get p_g2 from OTP
        *pAG = (OTPCALChirpInjDAC4 & 0x7F000000u) >> 24u;     // to get a_g2 from OTP
        *pQG = (OTPCALChirpInjDAC4 & 0x3FFu);                 // to get q_g2 from OTP
        *pF0RefI = (OTPCALChirpInjDAC5 & 0x1FFF0000u) >> 16u; // to get f0_g2_ref_i from OTP
        *pF1RefI = OTPCALChirpInjDAC5 & 0x1FFFu;              // to get f1_g2_ref_i from OTP
    }
    if ((ErrCode == BC_ERR_NOERROR) && (pChirpFreq->VCOSel == e_CAFC_5GWIDE))
    {
        ErrCode = HAL_ES2_OTP_GetOTPRegValue(OTP_CAL_CHIRP_INJ_DAC_6_INDEX, &OTPCALChirpInjDAC6);
        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = HAL_ES2_OTP_GetOTPRegValue(OTP_CAL_CHIRP_INJ_DAC_7_INDEX, &OTPCALChirpInjDAC7);
        }
        *pRefFreqSlope = 68.4e12f;
        *pMinKvcoRefI = (OTPCALChirpInjDAC1 & 0xFF0000u) >> 16u; // to get kvco_g4_ref_i from OTP
        *pMinusP = (OTPCALChirpInjDAC6 & 0x00FFFC00u) >> 10u;    // to get p_g4 from OTP
        *pAG = (OTPCALChirpInjDAC6 & 0x7F000000u) >> 24u;        // to get a_g4 from OTP
        *pQG = (OTPCALChirpInjDAC6 & 0x3FFu);                    // to get q_g4 from OTP
        *pF0RefI = (OTPCALChirpInjDAC7 & 0x1FFF0000u) >> 16u;    // to get f0_g4_ref_i from OTP
        *pF1RefI = OTPCALChirpInjDAC7 & 0x1FFFu;                 // to get f1_g4_ref_i from OTP
    }

    return ErrCode;
}
static BC_ERRCODE Helper_ES2_CalDacInjRangeCheck(SYS_ProfChirpFreq_t *pChirpFreq)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    
    if (pChirpFreq->VCOSel >= e_CAFC_VCOBWSEL_INVALID)
    {
        ErrCode = BC_ERR_CAFC_BWOUTOFRANGE;
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_CalculateDacInjection(SYS_ProfChirpFreq_t *pChirpFreq, SYS_ProfChirpTiming_t *pChirpTiming, float32_t Acquisitiontime, uint8_t AcqC1, uint8_t AcqC2, uint32_t DvDtCntC1, uint32_t CntHighKvcoAvg, uint32_t CntLowKvcoAvg)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    float32_t FStartCount = 0.0f;
    float32_t FStartCountRef;
    float32_t FreqCorr1;
    float32_t ACQSlope = 0.0f;
    float32_t RSTSlope = 0.0f;
    float32_t RefFreqSlope = 0.0f;
    float32_t DACC1AcqCorr0;
    float32_t DACC2AcqCorr0;
    float32_t DACC1RstCorr0;
    float32_t DACC2RstCorr0;
    float32_t DACCorr3;
    float32_t DACCorr4;
    uint32_t DACOP01;
    uint32_t DACOP10;
    uint32_t DACOP11;
    uint32_t DVDTC2;
    uint32_t DVDTRefI;
    uint32_t MinusP = 0u;
    uint32_t MinKvcoRefI = 0u;
    uint8_t DACC1Acq;
    uint8_t DACC2Acq;
    uint8_t DACC3Acq;
    uint8_t DACC1RST;
    uint8_t DACC2RST;
    uint8_t DACC3RST;
    uint32_t AG = 0u;
    uint32_t QG = 0u;
    uint32_t F0RefI = 0u;
    uint32_t F1RefI = 0u;

    uint32_t OTPCALChirpInjDAC8;
    uint32_t OTPCALChirpInjDAC9;
    R2M06_LpfInjAcqRstCommonUnion_t LpfInjAcqRstCommon;

    ErrCode = Helper_ES2_CalDacInjRangeCheck(pChirpFreq);
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = HAL_ES2_OTP_GetOTPRegValue(OTP_CAL_CHIRP_INJ_DAC_8_INDEX, &OTPCALChirpInjDAC8);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = HAL_ES2_OTP_GetOTPRegValue(OTP_CAL_CHIRP_INJ_DAC_9_INDEX, &OTPCALChirpInjDAC9);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        DACOP10 = (OTPCALChirpInjDAC8 & 0x7FC0000u) >> 18u;
        DACOP01 = (OTPCALChirpInjDAC8 & 0x0003FE00u) >> 9u;
        DACOP11 = OTPCALChirpInjDAC8 & 0x000001FFu;
        DVDTC2 = (OTPCALChirpInjDAC9 & 0X1FF80000u) >> 20u;  // script391
        DVDTRefI = (OTPCALChirpInjDAC9 & 0x0001FF80u) >> 8u; // script 337
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = Helper_ES2_CalculateSlope(pChirpFreq, pChirpTiming, Acquisitiontime, &ACQSlope, &RSTSlope, &FStartCount);
    }
    // Slope reference depending on 1G, 2G or 4G case
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = Helper_ES2_GetChirpInjDac(pChirpFreq, &RefFreqSlope, &MinKvcoRefI, &MinusP, &AG, &QG, &F0RefI, &F1RefI);

        if (ErrCode == BC_ERR_NOERROR)
        {
            // if polarity is 0 is down Chirp
            if (pChirpFreq->DownChirp == TRUE)
            {
                // dac_c1_a_corr0 equals abs(fslope_acq/A*(16+C1_dac_a)/(16+2^8-1)) * 1
                DACC1AcqCorr0 = ACQSlope / RefFreqSlope * (16.0f + (float32_t)AcqC1) / (16.0f + 256.0f - 1.0f);
                // dac_c1_r_corr0 equals abs(fslope_rst/A*(16+C1_dac_a)/(16+2^8-1))/8*(dac_op_01/2^8)/(6+1/3);
                DACC1RstCorr0 = RSTSlope / RefFreqSlope * (16.0f + (float32_t)AcqC1) / (16.0f + 256.0f - 1.0f) / 8.0f * ((float32_t)DACOP01 / 256.0f) / (6.0f + (1.0f / 3.0f));
                // dac_c2_a_corr0 equals abs(fslope_acq/A*(8+C2_dac_a)/(8+2^8-1))*dvdt_c2/2^10;
                DACC2AcqCorr0 = ACQSlope / RefFreqSlope * (8.0f + (float32_t)AcqC2) / (8.0f + 256.0f - 1.0f) * (float32_t)DVDTC2 / 1024.0f;
                // dac_c2_r_corr0 equals abs(fslope_rst/A*(8+C2_dac_a)/(8+2^8-1))/8*(dac_op_01/2^8)/(6+1/3)*dvdt_c2/2^10;
                DACC2RstCorr0 = RSTSlope / RefFreqSlope * (8.0f + (float32_t)AcqC2) / (8.0f + 256.0f - 1.0f) / 8.0f * ((float32_t)DACOP01 / 256.0f) / (6.0f + (1.0f / 3.0f)) * (float32_t)DVDTC2 / 1024.0f;
            }
            // if polarity is 1
            else
            {
                // dac_c1_a_corr0 equals abs(fslope_acq/A*(16+C1_dac_a)/(16+2^8-1)) * dac_op_10/2^8;
                DACC1AcqCorr0 = ACQSlope / RefFreqSlope * (16.0f + (float32_t)AcqC1) / (16.0f + 256.0f - 1.0f) * (float32_t)DACOP10 / 256.0f;
                // dac_c1_r_corr0 equals abs(fslope_rst/A*(16+C1_dac_a)/(16+2^8-1))/8*(dac_op_11/2^8)/(6+1/3);
                DACC1RstCorr0 = RSTSlope / RefFreqSlope * (16.0f + (float32_t)AcqC1) / (16.0f + 256.0f - 1.0f) / 8.0f * ((float32_t)DACOP11 / 256.0f) / (6.0f + (1.0f / 3.0f));
                // dac_c2_a_corr0 equals abs(fslope_acq/A*(8+C2_dac_a)/(8+2^8-1))*dvdt_c2/2^10*dac_op_10/2^8;
                DACC2AcqCorr0 = ACQSlope / RefFreqSlope * (8.0f + (float32_t)AcqC2) / (8.0f + 256.0f - 1.0f) * (float32_t)DVDTC2 / 1024.0f * (float32_t)DACOP10 / 256.0f;
                // dac_c2_r_corr0 equals abs(fslope_rst/A*(8+C2_dac_a)/(8+2^8-1))/8*(dac_op_11/2^8)/(6+1/3)*dvdt_c2/2^10;
                DACC2RstCorr0 = RSTSlope / RefFreqSlope * (8.0f + (float32_t)AcqC2) / (8.0f + 256.0f - 1.0f) / 8.0f * ((float32_t)DACOP11 / 256.0f) / (6.0f + (1.0f / 3.0f)) * (float32_t)DVDTC2 / 1024.0f;
            }
        }
    }

    if (ErrCode == BC_ERR_NOERROR)
    {
        // dac_corr1 is skipped here as it is 1;
        // dac_corr3 equals 1/(-(cnt_low_kvco_avg_onfly-cnt_high_kvco_avg_onfly)*min_kvco_ref_i/2^15);
        DACCorr3 = 1.0f / (fabsf((float32_t)CntHighKvcoAvg - (float32_t)CntLowKvcoAvg) * (float32_t)MinKvcoRefI / 32768.0f);

        // dac_corr4 equals dvdt_cnt_c1_onfly/10*dvdt_ref_i/2^17;
        // dac_corr4 equals dvdt_cnt_c1_onfly*dvdt_ref_i/2^17; // divided by 10 is not needed since it is 40MHZ clk
        DACCorr4 = (float32_t)DvDtCntC1 * (float32_t)DVDTRefI / 131072.0f;

        // freq_corr1 equals to 2/(cnt_low_kvco_avg_onfly*f0_ref_i/2^26+cnt_low_kvco_avg_onfly*f1_ref_i/2^26)
        FreqCorr1 = 2.0f / (((float32_t)CntLowKvcoAvg * (float32_t)F0RefI / 67108864.0f) + ((float32_t)CntHighKvcoAvg * (float32_t)F1RefI / 67108864.0f));

        // f_cnt_a_ref equals to round(freq_corr1*fcnt_a)
        FStartCountRef = roundf(FStartCount * FreqCorr1);

        // DAC_c1_a equals round(dac_c1_a_corr0*(a/2^13*(f_cnt_a_ref+(minus_p-2^14))^2+q/2^1)*(dac_corr1*band_corr+dac_corr3*(1-band_corr))*dac_corr4); band_corr equals to 0
        DACC1Acq = (uint8_t)roundf(DACC1AcqCorr0 * ((((float32_t)AG / 8192.0f) * (FStartCountRef + ((float32_t)MinusP - 16384.0f)) * (FStartCountRef + ((float32_t)MinusP - 16384.0f))) + ((float32_t)QG / 2.0f)) * DACCorr3 * DACCorr4);
        DACC1RST = (uint8_t)roundf(DACC1RstCorr0 * ((((float32_t)AG / 8192.0f) * (FStartCountRef + ((float32_t)MinusP - 16384.0f)) * (FStartCountRef + ((float32_t)MinusP - 16384.0f))) + ((float32_t)QG / 2.0f)) * DACCorr3 * DACCorr4);
        DACC2Acq = (uint8_t)roundf(DACC2AcqCorr0 * ((((float32_t)AG / 8192.0f) * (FStartCountRef + ((float32_t)MinusP - 16384.0f)) * (FStartCountRef + ((float32_t)MinusP - 16384.0f))) + ((float32_t)QG / 2.0f)) * DACCorr3 * DACCorr4);
        DACC2RST = (uint8_t)roundf(DACC2RstCorr0 * ((((float32_t)AG / 8192.0f) * (FStartCountRef + ((float32_t)MinusP - 16384.0f)) * (FStartCountRef + ((float32_t)MinusP - 16384.0f))) + ((float32_t)QG / 2.0f)) * DACCorr3 * DACCorr4);
        DACC3Acq = (uint8_t)roundf((float32_t)DACC2Acq / 4.371f);
        DACC3RST = (uint8_t)roundf((float32_t)DACC2RST / 4.371f);

        LpfInjAcqRstCommon.val_u32 = 0u;
        LpfInjAcqRstCommon.bits_st.TriggerToCopyInjDacVal = 1u;
        LpfInjAcqRstCommon.bits_st.CtlIdacInjAcqC1SpiCommon = DACC1Acq;
        LpfInjAcqRstCommon.bits_st.CtlIdacInjAcqC2SpiCommon = DACC2Acq;
        LpfInjAcqRstCommon.bits_st.CtlIdacInjAcqC3SpiCommon = DACC3Acq;
        LpfInjAcqRstCommon.bits_st.CtlIdacInjRstC1SpiCommon = DACC1RST;
        LpfInjAcqRstCommon.bits_st.CtlIdacInjRstC2SpiCommon = DACC2RST;
        LpfInjAcqRstCommon.bits_st.CtlIdacInjRstC3SpiCommon = DACC3RST;
        ErrCode = BC_SPI_Write(e_SYS_CAFC, R2M06_LPF_INJ_ACQ_RST_COMMON_U16, LpfInjAcqRstCommon.val_u32);
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_CAFC_ForceLoopConditions(BOOL EnableLoopFilter, uint8_t ForcedDACCode, SYS_ProfID_e ProfID, CAFC_VCOBWSel_e VCOBWSel, uint8_t Subband, float32_t ForcedDividerValue)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    if (ProfID > e_SYS_PROFILE_8)
    {
        ErrCode = BC_ERR_CAFC_INPUTOUTOFRANGE;
    }

    // check other input params
    if (((ForcedDACCode > 128u) || (VCOBWSel >= e_CAFC_VCOBWSEL_INVALID) || (Subband > 128u) || (ForcedDividerValue > 63.0f)) && (ErrCode == BC_ERR_NOERROR))
    {
        ErrCode = BC_ERR_CAFC_INPUTOUTOFRANGE;
    }

    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = Helper_ES2_ConfigEnableSettings(EnableLoopFilter, ForcedDACCode);
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = Helper_ES2_ConfigVCOControl(ProfID, VCOBWSel, Subband);
    }
    // set forced divider settings
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = Helper_ES2_DivideForceControl(ProfID, ForcedDividerValue);
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        // load selected profile to make above SC settings effective
        ErrCode = HAL_ES2_TE_LoadProfile(ProfID);
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_CAFC_ConfigStatic(BOOL EnableCP, BOOL EnableVCOLDO, BOOL EnableDividerLDO, BOOL EnableCPPFDLDO, BOOL EnableAllBias)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    // The 3 LDO settings resgisters only hold vout now. Enables are all in LDOEnControl.
    R2M06_LdoEnControlUnion_t LDOEnControl;
    R2M06_BiasBlockControlUnion_t BiasBlockControl;
    R2M06_CpControlUnion_t CpControl;

    // TS bias is in this reg
    R2M06_AdditionalHwSettingsUnion_t AdditionalHWSettings;
    uint8_t LocalEnBit = (uint8_t)EnableAllBias;

    // configure LDO enables according to user inputs
    ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_LDO_EN_CONTROL_U16, &LDOEnControl.val_u32);
    if (BC_ERR_NOERROR == ErrCode)
    {
        LDOEnControl.bits_st.CtlLdoCppfdEnSpi = (uint8_t)EnableCPPFDLDO;
        LDOEnControl.bits_st.CtlLdoDividerEnSpi = (uint8_t)EnableDividerLDO;
        LDOEnControl.bits_st.CtlLdoVcoEnSpi = (uint8_t)EnableVCOLDO;

        ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, R2M06_LDO_EN_CONTROL_U16, LDOEnControl.val_u32);
    }

    // configure bias block according to user inputs
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_BIAS_BLOCK_CONTROL_U16, &BiasBlockControl.val_u32);
        if (BC_ERR_NOERROR == ErrCode)
        {
            BiasBlockControl.bits_st.CtlIbiasBistDac200UEnSpi = LocalEnBit;
            BiasBlockControl.bits_st.CtlIbiasCpOpamp100UEnSpi = LocalEnBit;
            BiasBlockControl.bits_st.CtlIbiasDiv350UEnSpi = LocalEnBit;
            BiasBlockControl.bits_st.CtlIbiasEnSpi = LocalEnBit;
            BiasBlockControl.bits_st.CtlIbiasIdacInjndacEnSpi = LocalEnBit;
            BiasBlockControl.bits_st.CtlIbiasIdacInjpdacEnSpi = LocalEnBit;
            BiasBlockControl.bits_st.CtlIbiasIdacOpampEnSpi = LocalEnBit;
            BiasBlockControl.bits_st.CtlIbiasLd10UEnSpi = LocalEnBit;
            BiasBlockControl.bits_st.CtlIbiasRstBufferEnSpi = LocalEnBit;
            BiasBlockControl.bits_st.CtlIbiasTvn20UEnSpi = LocalEnBit;
            BiasBlockControl.bits_st.CtlIbiasVam100UEnSpi = LocalEnBit;

            ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, R2M06_BIAS_BLOCK_CONTROL_U16, BiasBlockControl.val_u32);
        }
    }

    // TS bias is also considered as part of all biases in CAFC.
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_ADDITIONAL_HW_SETTINGS_U16, &AdditionalHWSettings.val_u32);
        if (BC_ERR_NOERROR == ErrCode)
        {
            AdditionalHWSettings.bits_st.CtlIbiasTs100UEn = (uint8_t)EnableAllBias;
            ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, R2M06_ADDITIONAL_HW_SETTINGS_U16, AdditionalHWSettings.val_u32);
        }
    }

    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_CP_CONTROL_U16, &CpControl.val_u32);
        if (BC_ERR_NOERROR == ErrCode)
        {
            CpControl.bits_st.CtlCpEnSpi = (uint8_t)EnableCP;

            ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, R2M06_CP_CONTROL_U16, CpControl.val_u32);
        }
    }

    return ErrCode;
}

static BC_ERRCODE Helper_ES2_SelSBTable(CAFC_VCOBWSel_e VCOBWSel, uint8_t StartSB, uint8_t NumItems, uint8_t *pIndex)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    // choose correct SB table.
    switch (VCOBWSel)
    {
    case e_CAFC_1GBAND:
        *pIndex = 0u;
        // validate only SB range, rely on subsequent HAL API call to check other inputs
        if (((StartSB + (NumItems - 1u)) > 127u))
        {
            ErrCode = BC_ERR_CAFC_SBOUTOFRANGE;
        }
        break;
    case e_CAFC_5GNARROW:
        *pIndex = 1u;
        // validate only SB range, rely on subsequent HAL API call to check other inputs
        if (((StartSB + (NumItems - 1u)) > 127u))
        {
            ErrCode = BC_ERR_CAFC_SBOUTOFRANGE;
        }
        break;
    case e_CAFC_5GWIDE:
        *pIndex = 2u;
        // validate only SB range, rely on subsequent HAL API call to check other inputs
        if (((StartSB + (NumItems - 1u)) > 63u))
        {
            ErrCode = BC_ERR_CAFC_SBOUTOFRANGE;
        }
        break;
    default:
        ErrCode = BC_ERR_CAFC_INPUTOUTOFRANGE;
        break;
    }

    return ErrCode;
}
static BC_ERRCODE Helper_ES2_EnAmpMonLd(uint8_t EnableFlag)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M06_FuncsafeMonUnlockControlUnion_t FuncsafeMonUnlockControl;
    R2M06_FuncsafeMonLevelSettingsEnUnion_t FuncsafeMonLevelSettingsEn;
    ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_FUNCSAFE_MON_LEVEL_SETTINGS_EN_U16, &FuncsafeMonLevelSettingsEn.val_u32);
    if (BC_ERR_NOERROR == ErrCode)
    {
        FuncsafeMonLevelSettingsEn.bits_st.CtlLevelVcoAmpMonitorEnSpi = EnableFlag;
        ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, R2M06_FUNCSAFE_MON_LEVEL_SETTINGS_EN_U16, FuncsafeMonLevelSettingsEn.val_u32);
    }

    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_FUNCSAFE_MON_UNLOCK_CONTROL_U16, &FuncsafeMonUnlockControl.val_u32);
        if (BC_ERR_NOERROR == ErrCode)
        {
            FuncsafeMonUnlockControl.bits_st.CtlLdEnSpi = EnableFlag;
            ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, R2M06_FUNCSAFE_MON_UNLOCK_CONTROL_U16, FuncsafeMonUnlockControl.val_u32);
        }
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_GetCAFCFreq(CAFC_VCOBWSel_e VCOBWSel, uint8_t DACCode, uint8_t loop0, float32_t *pCAFCFreqHz)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    // This API uses always profile 0 to measure SB freqeucies.
    SYS_ProfID_e ProfID = e_SYS_PROFILE_0;
    float32_t ForceDiv = 27.0f;
    ErrCode = HAL_ES2_CAFC_ForceLoopConditions(FALSE, DACCode, ProfID, VCOBWSel, loop0, ForceDiv);
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = HAL_ES2_CAFC_ReadFreqCounter(10.0f, NULL, pCAFCFreqHz, ProfID);
    }
    return ErrCode;
}
static void Helper_ES2_FlushSB(uint8_t StartSB, uint8_t NumItems, BC_FLOAT *pFStart, BC_FLOAT *pFStop, BC_FLOAT *pBW)
{
    uint8_t loop = 0u;
    for (loop = 0u; loop < StartSB; loop++)
    {
        pFStart[loop] = 0.0f;
        pFStop[loop] = 0.0f;
        pBW[loop] = 0.0f;
    }

    for (loop = StartSB + NumItems; loop < 128u; loop++)
    {
        pFStart[loop] = 0.0f;
        pFStop[loop] = 0.0f;
        pBW[loop] = 0.0f;
    }
}
BC_ERRCODE HAL_ES2_CAFC_GenSBTable(CAFC_VCOBWSel_e VCOBWSel, uint8_t HighDACCode, uint8_t LowDACCode, uint8_t StartSB, uint8_t NumItems)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    float32_t CAFCFreqHz = 0.0f;
    // pointer to global SB table
    BC_FLOAT *pFStart = NULL;
    BC_FLOAT *pFStop = NULL;
    BC_FLOAT *pBW = NULL;
    // loop variable
    uint8_t loop0 = 0u;
    uint8_t index = 0u;

    ErrCode = Helper_ES2_SelSBTable(VCOBWSel, StartSB, NumItems, &index);

    if (BC_ERR_NOERROR == ErrCode)
    {
        pFStart = gFStart[index];
        pFStop = gFStop[index];
        pBW = gBW[index];
        // disable amplitude monitor and lock det temporarily to aovid issues during VCO table calibration.
        ErrCode = Helper_ES2_EnAmpMonLd(0u);
    }

    for (loop0 = StartSB; loop0 < (StartSB + NumItems); loop0++)
    {
        // first measure lower frequency boundary: FStart
        if (BC_ERR_NOERROR != ErrCode)
        {
            break;
        }
        else
        {
            ErrCode = Helper_ES2_GetCAFCFreq(VCOBWSel, HighDACCode, loop0, &CAFCFreqHz);
        }
        if (BC_ERR_NOERROR == ErrCode)
        {
            BC_FLOAT Temp64 = (BC_FLOAT)CAFCFreqHz;
            // assign start freqeuncy of current SB.
            pFStart[loop0] = Temp64 * (BC_FLOAT)3.0;
        }

        // then measure higher frequency boundary: FStop
        if (BC_ERR_NOERROR == ErrCode)
        {
            ErrCode = Helper_ES2_GetCAFCFreq(VCOBWSel, LowDACCode, loop0, &CAFCFreqHz);
        }
        if (BC_ERR_NOERROR == ErrCode)
        {
            BC_FLOAT Temp64 = (BC_FLOAT)CAFCFreqHz;
            // assign start freqeuncy of current SB.
            pFStop[loop0] = Temp64 * (BC_FLOAT)3.0;
            // assign also BW of current SB.
            pBW[loop0] = pFStop[loop0] - pFStart[loop0];
        }
    }

    if (BC_ERR_NOERROR == ErrCode)
    {
        // cancel any force to loop filter (VCOBWSel and SB choice cannot be reverted)
        ErrCode = HAL_ES2_CAFC_ForceLoopConditions(TRUE, 128u, e_SYS_PROFILE_0, VCOBWSel, 128u, 0.0f);
    }

    if (BC_ERR_NOERROR == ErrCode)
    {
        // re-enable amplitude monitor and lock det
        ErrCode = Helper_ES2_EnAmpMonLd(1u);
    }

    if (BC_ERR_NOERROR == ErrCode)
    {
        // flush unmeasure SB to all 0. (in case it's not the first time to run this API)
        (void)Helper_ES2_FlushSB(StartSB, NumItems, pFStart, pFStop, pBW);
    }

    return ErrCode;
}

BC_ERRCODE HAL_ES2_CAFC_GetSBTable(CAFC_VCOBWSel_e VCOBWSel, BC_FLOAT pFBegin[128], BC_FLOAT pFEnd[128], BC_FLOAT pBW[128])
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    // local pointers for VCO tables
    BC_FLOAT *pLocalStart = NULL;
    BC_FLOAT *pLocalStop = NULL;
    BC_FLOAT *pLocalBW = NULL;

    // if any output pointer is not NULL, it's valid case.
    if ((NULL != pFBegin) || (NULL != pFEnd) || (NULL != pBW))
    {
        switch (VCOBWSel)
        {
        case e_CAFC_1GBAND:
            pLocalStart = gFStart[0];
            pLocalStop = gFStop[0];
            pLocalBW = gBW[0];
            break;
        case e_CAFC_5GNARROW:
            pLocalStart = gFStart[1];
            pLocalStop = gFStop[1];
            pLocalBW = gBW[1];
            break;
        case e_CAFC_5GWIDE:
            pLocalStart = gFStart[2];
            pLocalStop = gFStop[2];
            pLocalBW = gBW[2];
            break;
        default:
            // input validation
            ErrCode = BC_ERR_CAFC_INPUTOUTOFRANGE;
            break;
        }
    }
    else
    {
        ErrCode = BC_ERR_CAFC_INPUTOUTOFRANGE;
    }

    if (BC_ERR_NOERROR == ErrCode)
    {
        // copy values to outputs
        uint32_t loop0 = 0u;
        for (loop0 = 0u; loop0 < 128u; loop0++)
        {
            // assign output according to user's choice
            if (NULL != pFBegin)
            {
                pFBegin[loop0] = pLocalStart[loop0];
            }

            if (NULL != pFEnd)
            {
                pFEnd[loop0] = pLocalStop[loop0];
            }

            if (NULL != pBW)
            {
                pBW[loop0] = pLocalBW[loop0];
            }
        }
    }

    return ErrCode;
}

BC_ERRCODE HAL_ES2_CAFC_EnableVCO(BOOL Enable)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    R2M06_VcoEnableSettingsUnion_t VcoEnableSettings;

    ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_VCO_ENABLE_SETTINGS_U16, &VcoEnableSettings.val_u32);
    if (BC_ERR_NOERROR == ErrCode)
    {
        VcoEnableSettings.bits_st.CtlVcoEnSpi = (uint8_t)Enable;

        ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, R2M06_VCO_ENABLE_SETTINGS_U16, VcoEnableSettings.val_u32);
    }

    // write forced divider value
    if (BC_ERR_NOERROR == ErrCode)
    {
        R2M06_DivideForceControlUnion_t DivideForceControl;
        ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_DIVIDE_FORCE_CONTROL_U16, &DivideForceControl.val_u32);
        if (BC_ERR_NOERROR == ErrCode)
        {
            DivideForceControl.bits_st.CtlDivForce = CAFC_VCO_FORCE_DIVIDER_OPTIMAL; // same is use by HW calculation of Mdes
            // since this is not required for the functional mode, Fro CAAFC 1/M value is internally taken care  by HW logic
            DivideForceControl.bits_st.CtlForceDivider = 0u;
            ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, R2M06_DIVIDE_FORCE_CONTROL_U16, DivideForceControl.val_u32);
        }
    }

    return ErrCode;
}

static BC_ERRCODE Helper_ES2_ConfigPllBW(CAFC_PLLLPFSel_e PLLLPFSel, BC_FLOAT EffFc, BC_FLOAT LPFRefFreq, float32_t GainCorrOTP, CAFC_LPFLUTEntry_t *pTableEntry, float32_t *pVCOGainCorr, BOOL DownChirp)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M06_CpPllbwCfg0Union_t CpPllbw;
    uint8_t SliceNum = 0u;
    uint8_t CompensatedSliceNum = 0u;
    uint8_t CompensatedSliceNumThermal = 0u;
    uint8_t IbiasCp150U = 0u;
    uint8_t CompensatedIbiasCp150U = 0u;
    float32_t IcpCompensated;
    float32_t CorrectedIcp150U;
    float32_t tempVCOGainCorr;
    uint16_t CP_PLLBW_CFG;
    CP_PLLBW_CFG = R2M06_CP_PLLBW_CFG0_U16 + (((uint16_t)PLLLPFSel - (uint16_t)e_CAFC_PLLLPF_CFG0) * (R2M06_CP_PLLBW_CFG1_U16 - R2M06_CP_PLLBW_CFG0_U16));

    // VCO gain compensatiomn (as the value stored in the table is only valid for efffc 76G Hz)
    BC_FLOAT tempFreq64 = (EffFc - LPFRefFreq);
    float32_t tempFreq = (float32_t)tempFreq64;
    tempVCOGainCorr = 1.0f - (tempFreq * 20.7f / 5e9f / 100.0f);
    *pVCOGainCorr = tempVCOGainCorr;
    SliceNum = pTableEntry->CP_SLICE_EN;
    IbiasCp150U = pTableEntry->IBIAS_CP_150U;

    // compensated Icp     = comp factor *  programmable bias level  *3.125uA/level  *  num of slices
    CorrectedIcp150U = GainCorrOTP * tempVCOGainCorr * (float32_t)IbiasCp150U * 3.125f;
    IcpCompensated = CorrectedIcp150U * (float32_t)SliceNum; // total current

    // if correctedIcp150U>=45 uA, keep the number of slice as the same from the LUT
    // if  correctedIcp150U < 45 and SlicenNum >1 compensation is needed for number of Slice (Decrease the unumber of slice to make CorrectedIcp150u >45.0f)
    if ((CorrectedIcp150U < 45.0f) && (SliceNum > 1u))
    {
        CompensatedSliceNum = (uint8_t)roundf(IcpCompensated / 85.0f); // new number of slices
        SliceNum = CompensatedSliceNum;
        if (SliceNum == 0u)
        {
            ErrCode = BC_ERR_CAFC_CONFIGLOOPFILTERFAIL;
        }
        else
        {
            CorrectedIcp150U = IcpCompensated / (float32_t)SliceNum;
        }
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        CompensatedIbiasCp150U = (uint8_t)roundf(CorrectedIcp150U / 3.125f);
        // convert binary to thermalmeter code
        CompensatedSliceNumThermal = 0xffu >> (8u - SliceNum);

        CpPllbw.val_u32 = 0u;
        CpPllbw.bits_st.CtlCpIoffsetUpdnSpiPllbwCfg0 = (DownChirp == TRUE) ? CAFC_NMOS_INJECT_CURRENT : CAFC_PMOS_INJECT_CURRENT;
        CpPllbw.bits_st.CtlCpIoffsetSetSpiPllbwCfg0 = CAFC_CHARGE_PUMP_10_PERCENT_OFFSET;
        CpPllbw.bits_st.CtlCpSliceEn0PllbwCfg0 = CompensatedSliceNumThermal;
        CpPllbw.bits_st.CtlIbiasCp150USpiPllbwCfg0 = CompensatedIbiasCp150U;
        ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, CP_PLLBW_CFG, CpPllbw.val_u32);
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_CfgPllLpfC1C2C3(CAFC_PLLLPFSel_e PLLLPFSel, CAFC_LPFLUTEntry_t *pTableEntry, CAFC_LPFLUTEntry_t *pTableEntryReset, float32_t *pLPFUnitRes)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M06_PllLpfC1PllbwCfg0Union_t PllLpfC1;
    R2M06_PllLpfC2PllbwCfg0Union_t PllLpfC2;
    R2M06_PllLpfC3PllbwCfg0Union_t PllLpfC3;
    R2M06_PllLpfResPllbwCfg0Union_t PllLpfRes;
    R2M06_AtbTrimUnion_t AtbTrim;
    uint32_t FilterParTrim;
    uint8_t ATBTrimCode = 0u;
    float32_t R1Ohm = 0.0f;
    uint8_t ResR1 = 0u;
    float32_t ATBUnitRes = 0.0f;
    float32_t tempLPFUnitRes = 0.0f;
    uint16_t PLL_LPF_C1_CFG;
    uint16_t PLL_LPF_C2_CFG;
    uint16_t PLL_LPF_C3_CFG;
    uint16_t PLL_LPF_RES_CFG;

    PLL_LPF_C1_CFG = R2M06_PLL_LPF_C1_PLLBW_CFG0_U16 + (((uint16_t)PLLLPFSel - (uint16_t)e_CAFC_PLLLPF_CFG0) * (R2M06_PLL_LPF_C1_PLLBW_CFG1_U16 - R2M06_PLL_LPF_C1_PLLBW_CFG0_U16));
    PLL_LPF_C2_CFG = R2M06_PLL_LPF_C2_PLLBW_CFG0_U16 + (((uint16_t)PLLLPFSel - (uint16_t)e_CAFC_PLLLPF_CFG0) * (R2M06_PLL_LPF_C2_PLLBW_CFG1_U16 - R2M06_PLL_LPF_C2_PLLBW_CFG0_U16));
    PLL_LPF_C3_CFG = R2M06_PLL_LPF_C3_PLLBW_CFG0_U16 + (((uint16_t)PLLLPFSel - (uint16_t)e_CAFC_PLLLPF_CFG0) * (R2M06_PLL_LPF_C3_PLLBW_CFG1_U16 - R2M06_PLL_LPF_C3_PLLBW_CFG0_U16));
    PLL_LPF_RES_CFG = R2M06_PLL_LPF_RES_PLLBW_CFG0_U16 + (((uint16_t)PLLLPFSel - (uint16_t)e_CAFC_PLLLPF_CFG0) * (R2M06_PLL_LPF_RES_PLLBW_CFG1_U16 - R2M06_PLL_LPF_RES_PLLBW_CFG0_U16));

    PllLpfC1.val_u32 = 0u;
    // Configure C1 setting during acquisition
    PllLpfC1.bits_st.PllLpfC1AcqCtrlPllbwCfg0 = pTableEntry->LPF_C1;
    // Configure C1 setting during reset
    PllLpfC1.bits_st.PllLpfC1RstCtrlPllbwCfg0 = pTableEntryReset->LPF_C1;
    ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, PLL_LPF_C1_CFG, PllLpfC1.val_u32);

    if (BC_ERR_NOERROR == ErrCode)
    {
        PllLpfC2.val_u32 = 0u;
        // Configure C2 setting during acquisition
        PllLpfC2.bits_st.PllLpfC2AcqCtrlPllbwCfg0 = pTableEntry->LPF_C2;
        // Configure C2 setting during reset
        PllLpfC2.bits_st.PllLpfC2RstCtrlPllbwCfg0 = pTableEntryReset->LPF_C2;
        ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, PLL_LPF_C2_CFG, PllLpfC2.val_u32);
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        PllLpfC3.val_u32 = 0u;
        // Configure C3 setting during acquisition
        PllLpfC3.bits_st.PllLpfC3AcqCtrlPllbwCfg0 = pTableEntry->LPF_C3;
        // Configure C3 setting during reset
        PllLpfC3.bits_st.PllLpfC3RstCtrlPllbwCfg0 = pTableEntryReset->LPF_C3;
        ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, PLL_LPF_C3_CFG, PllLpfC3.val_u32);
    }

    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SPI_Read(e_SYS_CAFC, CAFC_FILTER_PAR_TRIM_U16, &FilterParTrim);
        // Disable "copy the R1 and R2 setting from this register to all profile registers"
        if (BC_ERR_NOERROR == ErrCode)
        {
            FilterParTrim = FilterParTrim & CAFC_FILTER_PAR_TRIM_MASK;
            ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, CAFC_FILTER_PAR_TRIM_U16, FilterParTrim);
        }
    }

    if (BC_ERR_NOERROR == ErrCode)
    {
        // calibrate R1 using ATB_Trim
        ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_ATB_TRIM_U16, &AtbTrim.val_u32);
        if (ErrCode == BC_ERR_NOERROR)
        {
            ATBTrimCode = AtbTrim.bits_st.SetTrimRNSpi & 0x1Fu; // only 5 bits are used
            ATBUnitRes = (ATB_RESISTOR_OHM) / ((4.0f + (31.0f / 8.0f)) - ((float32_t)ATBTrimCode / 8.0f));
            tempLPFUnitRes = LPF_ATB_RES_RATIO * ATBUnitRes;
            *pLPFUnitRes = tempLPFUnitRes;
            R1Ohm = (float32_t)pTableEntry->R1;

            ResR1 = (uint8_t)lroundf(8.0f * ((tempLPFUnitRes + (tempLPFUnitRes / 2.0f) + (31.0f * tempLPFUnitRes / 8.0f)) - R1Ohm) / tempLPFUnitRes);
            ErrCode = BC_SPI_Read(e_SYS_CAFC, PLL_LPF_RES_CFG, &PllLpfRes.val_u32);
        }
        if (BC_ERR_NOERROR == ErrCode)
        {
            PllLpfRes.bits_st.CtlLpfR1SpiPllbwCfg0 = (ResR1 < 0x20u) ? ResR1 : 0x1Fu;
            ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, PLL_LPF_RES_CFG, PllLpfRes.val_u32);
        }
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_CfgLoopFilterRangeChk(CAFC_PLLLPFSel_e PLLLPFSel, CAFC_LoopFilterLUTSel_e LPFLUTSel, BC_FLOAT EffFc)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    if ((PLLLPFSel >= e_CAFC_PLLLPF_INVALID) || (LPFLUTSel >= e_CAFC_LPF_LUT_USER1) ||
        (EffFc < SC_AUTO_RADAR_LOWER_END) || (EffFc > SC_AUTO_RADAR_UPPER_END))
    {
        ErrCode = BC_ERR_CAFC_INPUTOUTOFRANGE;
    }
    return ErrCode;
}
BC_ERRCODE HAL_ES2_CAFC_ConfigLoopFilter(CAFC_PLLLPFSel_e PLLLPFSel, CAFC_LoopFilterLUTSel_e LPFLUTSel, float32_t PLLLoopBW, BC_FLOAT EffFc, BOOL DownChirp)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M06_CpControlUnion_t CpControl;
    BC_FLOAT LPFRefFreq = (BC_FLOAT)76e9;
    float32_t PLLLoopBWReset = 2400e3f;
    float32_t LPFUnitRes = 0.0f;
    float32_t VCOGainCorr = 0.0f;
    float32_t GainCorrOTP;
    CAFC_LPFLUTEntry_t LPFTableEnrty = {
        0.0f,
        0u,
        0u,
        0u,
        0u,
        0u,
        0u};
    CAFC_LPFLUTEntry_t LPFTableEnrtyReset = {
        0.0f,
        0u,
        0u,
        0u,
        0u,
        0u,
        0u};

    ErrCode = Helper_ES2_CfgLoopFilterRangeChk(PLLLPFSel, LPFLUTSel, EffFc);
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = Helper_ES2_GetGainCorrRstBW(LPFLUTSel, &GainCorrOTP, &PLLLoopBWReset);
        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_CP_CONTROL_U16, &CpControl.val_u32);
            if (ErrCode == BC_ERR_NOERROR)
            {
                CpControl.bits_st.CtlCpReplicaBiasEnSpi = 1u;
                ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, R2M06_CP_CONTROL_U16, CpControl.val_u32);
            }
        }
        if (ErrCode == BC_ERR_NOERROR)
        {
            // get the acquisition loop filter entry which needs to be configured
            ErrCode = HAL_ES2_CAFC_GetLoopFilterEntry(LPFLUTSel, PLLLoopBW, &LPFTableEnrty);
        }
        if (BC_ERR_NOERROR == ErrCode)
        {
            // get the reset loop filter entry which needs to be configured
            ErrCode = HAL_ES2_CAFC_GetLoopFilterEntry(LPFLUTSel, PLLLoopBWReset, &LPFTableEnrtyReset);
        }
        if (BC_ERR_NOERROR == ErrCode)
        {
            // Configure PLLBW
            ErrCode = Helper_ES2_ConfigPllBW(PLLLPFSel, EffFc, LPFRefFreq, GainCorrOTP, &LPFTableEnrty, &VCOGainCorr, DownChirp);
        }
        if (BC_ERR_NOERROR == ErrCode)
        {
            ErrCode = Helper_ES2_CfgPllLpfC1C2C3(PLLLPFSel, &LPFTableEnrty, &LPFTableEnrtyReset, &LPFUnitRes);
        }

        /* Configure high bandwidth settings */
        if (BC_ERR_NOERROR == ErrCode)
        {
            ErrCode = Helper_ES2_ConfigHighPllBW(LPFLUTSel, LPFUnitRes, GainCorrOTP, VCOGainCorr);
        }
        /*LD  polarity is controlled based on Chirp polarity */
        if (BC_ERR_NOERROR == ErrCode)
        {
            ErrCode = Helper_ES2_SetLDPolarity(LPFLUTSel, DownChirp);
        }
        if (BC_ERR_NOERROR == ErrCode)
        {
            ErrCode = Helper_ES2_SetInitOverrideSB(LPFLUTSel);
        }
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_SetInitOverrideSB(CAFC_LoopFilterLUTSel_e LPFLUTSel)
{
    BC_ERRCODE ErrCode;
    R2M06_ChirpCalibrationAfcControl1Union_t AFCControl1;

    ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_CHIRP_CALIBRATION_AFC_CONTROL1_U16, &AFCControl1.val_u32);
    if (ErrCode == BC_ERR_NOERROR)
    {
        AFCControl1.bits_st.AfcFselInitOverride = 1u;
        if (LPFLUTSel == e_CAFC_LPF_LUT_1G)
        {
            AFCControl1.bits_st.AfcFselInitOverrideValue = BC_CAFC_AFC_FSEL_INIT_OVERRIDE_VALUE_1G_VCO;
        }
        else
        {
            AFCControl1.bits_st.AfcFselInitOverrideValue = BC_CAFC_AFC_FSEL_INIT_OVERRIDE_VALUE_2G_4G_VCO;
        }
        ErrCode = BC_SPI_Write(e_SYS_CAFC, R2M06_CHIRP_CALIBRATION_AFC_CONTROL1_U16, AFCControl1.val_u32);
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_SetLDPolarity(CAFC_LoopFilterLUTSel_e LPFLUTSel, BOOL DownChirp)
{
    BC_ERRCODE ErrCode;
    R2M06_FuncsafeMonUnlockControlUnion_t FuncsafeMonUnlockControl;
    uint8_t LDWindowOffset = 6u; // Window offset for 1GHZ
    // Down chirp related settings

    if (LPFLUTSel == e_CAFC_LPF_LUT_5GNARROW)
    {
        LDWindowOffset = 4u;
    }
    if (LPFLUTSel == e_CAFC_LPF_LUT_5GWIDE)
    {
        if (DownChirp == TRUE)
        {
            LDWindowOffset = 3u;
        }
        else
        {
            LDWindowOffset = 1u;
        }
    }
    ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_FUNCSAFE_MON_UNLOCK_CONTROL_U16, &FuncsafeMonUnlockControl.val_u32);
    if (ErrCode == BC_ERR_NOERROR)
    {
        FuncsafeMonUnlockControl.bits_st.CtlLdPolSpi = (DownChirp == TRUE) ? 0u : 1u;
        FuncsafeMonUnlockControl.bits_st.CtlLdWindowOffsetSpi = LDWindowOffset;
        ErrCode = BC_SPI_Write(e_SYS_CAFC, R2M06_FUNCSAFE_MON_UNLOCK_CONTROL_U16, FuncsafeMonUnlockControl.val_u32);
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_CfgR1HighBWSetting(CAFC_LoopFilterLUTSel_e LPFLUTSel, float32_t LPFUnitRes, float32_t PLLLoopBW, CAFC_LPFLUTEntry_t *pLPFTableEnrtyMax, uint8_t *pCtlLpfR1SpiPllbwCfgH)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    float32_t R1Ohm = 0.0f;
    uint8_t ResR1 = 0u;

    ErrCode = HAL_ES2_CAFC_GetLoopFilterEntry(LPFLUTSel, PLLLoopBW, pLPFTableEnrtyMax);
    if (ErrCode == BC_ERR_NOERROR)
    {
        R1Ohm = (float32_t)pLPFTableEnrtyMax->R1;
        ResR1 = (uint8_t)lroundf(8.0f * ((LPFUnitRes + (LPFUnitRes / 2.0f) + (31.0f * LPFUnitRes / 8.0f)) - R1Ohm) / LPFUnitRes);
        *pCtlLpfR1SpiPllbwCfgH = (ResR1 < 0x20u) ? ResR1 : 0x1Fu;
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_ConfigPLLBWCfgHigh(CAFC_LoopFilterLUTSel_e LPFLUTSel, float32_t LPFUnitRes, uint16_t *pCpPllBwCfgHighRegAdd, uint16_t *pPllLpfCapPllBwCfgHighRegAdd, CAFC_LPFLUTEntry_t *pLPFTableEnrtyMax)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M06_PllLpfResPllbwCfgHighUnion_t PllLpfResPllbwCfgHigh;
    uint8_t CtlLpfR1SpiPllbwCfgH = 0u;
    ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_PLL_LPF_RES_PLLBW_CFG_HIGH_U16, &PllLpfResPllbwCfgHigh.val_u32);
    if (ErrCode == BC_ERR_NOERROR)
    {
        if (LPFLUTSel == e_CAFC_LPF_LUT_1G)
        {
            *pCpPllBwCfgHighRegAdd = R2M06_CP_PLLBW_CFG_HIGH_1G_U16;
            *pPllLpfCapPllBwCfgHighRegAdd = R2M06_PLL_LPF_CAP_PLLBW_CFG_HIGH_1G_U16;
            ErrCode = Helper_ES2_CfgR1HighBWSetting(LPFLUTSel, LPFUnitRes, 2400e3f, pLPFTableEnrtyMax, &CtlLpfR1SpiPllbwCfgH);
            if (ErrCode == BC_ERR_NOERROR)
            {
                PllLpfResPllbwCfgHigh.bits_st.CtlLpfR1SpiPllbwCfgH1G = CtlLpfR1SpiPllbwCfgH;
            }
        }
        if (LPFLUTSel == e_CAFC_LPF_LUT_5GNARROW)
        {
            *pCpPllBwCfgHighRegAdd = R2M06_CP_PLLBW_CFG_HIGH_2G_U16;
            *pPllLpfCapPllBwCfgHighRegAdd = R2M06_PLL_LPF_CAP_PLLBW_CFG_HIGH_2G_U16;
            ErrCode = Helper_ES2_CfgR1HighBWSetting(LPFLUTSel, LPFUnitRes, 2400e3f, pLPFTableEnrtyMax, &CtlLpfR1SpiPllbwCfgH);
            if (ErrCode == BC_ERR_NOERROR)
            {
                PllLpfResPllbwCfgHigh.bits_st.CtlLpfR1SpiPllbwCfgH2G = CtlLpfR1SpiPllbwCfgH;
            }
        }
        if (LPFLUTSel == e_CAFC_LPF_LUT_5GWIDE)
        {
            *pCpPllBwCfgHighRegAdd = R2M06_CP_PLLBW_CFG_HIGH_4G_U16;
            *pPllLpfCapPllBwCfgHighRegAdd = R2M06_PLL_LPF_CAP_PLLBW_CFG_HIGH_4G_U16;
            ErrCode = Helper_ES2_CfgR1HighBWSetting(LPFLUTSel, LPFUnitRes, 2800e3f, pLPFTableEnrtyMax, &CtlLpfR1SpiPllbwCfgH);
            if (ErrCode == BC_ERR_NOERROR)
            {
                PllLpfResPllbwCfgHigh.bits_st.CtlLpfR1SpiPllbwCfgH4G = CtlLpfR1SpiPllbwCfgH;
            }
        }
        if (ErrCode == BC_ERR_NOERROR)
        {
            // Configure R1 wiht high bandwidth setting
            ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, R2M06_PLL_LPF_RES_PLLBW_CFG_HIGH_U16, PllLpfResPllbwCfgHigh.val_u32);
        }
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_ConfigHighPllBW(CAFC_LoopFilterLUTSel_e LPFLUTSel, float32_t LPFUnitRes, float32_t GainCorrOTP, float32_t VCOGainCorr)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M06_CpPllbwCfgHigh1GUnion_t CpPllbwCfgHigh;
    R2M06_PllLpfCapPllbwCfgHigh1GUnion_t PllLpfCapPllbwCfgHigh;
    uint8_t SliceNum = 0u;
    uint8_t CompensatedSliceNum = 0u;
    uint8_t CompensatedSliceNumThermal = 0u;
    uint8_t IbiasCp150U = 0u;
    uint8_t CompensatedIbiasCp150U = 0u;
    float32_t CorrectedIcp150U;
    float32_t IcpCompensated;
    CAFC_LPFLUTEntry_t LPFTableEnrtyMax = {
        0.0f,
        0u,
        0u,
        0u,
        0u,
        0u,
        0u};
    uint16_t CpPllBwCfgHighRegAdd = R2M06_CP_PLLBW_CFG_HIGH_1G_U16;
    uint16_t PllLpfCapPllBwCfgHighRegAdd = R2M06_PLL_LPF_CAP_PLLBW_CFG_HIGH_1G_U16;

    ErrCode = Helper_ES2_ConfigPLLBWCfgHigh(LPFLUTSel, LPFUnitRes, &CpPllBwCfgHighRegAdd, &PllLpfCapPllBwCfgHighRegAdd, &LPFTableEnrtyMax);

    if (ErrCode == BC_ERR_NOERROR)
    {
        SliceNum = LPFTableEnrtyMax.CP_SLICE_EN;
        IbiasCp150U = LPFTableEnrtyMax.IBIAS_CP_150U;
        // compensated Icp     = comp factor *  programmable bias level  *3.125uA/level  *  num of slices
        CorrectedIcp150U = GainCorrOTP * VCOGainCorr * (float32_t)IbiasCp150U * 3.125f;
        IcpCompensated = CorrectedIcp150U * (float32_t)SliceNum; // total current

        // if correctedIcp150U>=45 uA, keep the number of slice as the same from the LUT
        // if  correctedIcp150U < 45 and SlicenNum >1 compensation is needed for number of Slice (Decrease the unumber of slice to make CorrectedIcp150u >45.0f)
        if ((CorrectedIcp150U < 45.0f) && (SliceNum > 1u))
        {
            CompensatedSliceNum = (uint8_t)roundf(IcpCompensated / 85.0f); // new number of slices
            SliceNum = CompensatedSliceNum;
            if (SliceNum == 0u)
            {
                ErrCode = BC_ERR_CAFC_CONFIGLOOPFILTERFAIL;
            }
            else
            {
                CorrectedIcp150U = IcpCompensated / (float32_t)SliceNum;
            }
        }

        if (BC_ERR_NOERROR == ErrCode)
        {

            CompensatedIbiasCp150U = (uint8_t)roundf(CorrectedIcp150U / 3.125f);
            // convert binary to thermalmeter code
            CompensatedSliceNumThermal = 0xffu >> (8u - SliceNum);

            ErrCode = BC_SPI_Read(e_SYS_CAFC, CpPllBwCfgHighRegAdd, &CpPllbwCfgHigh.val_u32);
        }
        if (BC_ERR_NOERROR == ErrCode)
        {
            // Configure charge pump with high bandwidth settings
            CpPllbwCfgHigh.bits_st.CtlCpIoffsetSetSpiPllbwCfgH1G = 2u; // 10% offset
            CpPllbwCfgHigh.bits_st.CtlIbiasCp150USpiPllbwCfgH1G = CompensatedIbiasCp150U;
            CpPllbwCfgHigh.bits_st.CtlCpSliceEn0PllbwCfgH1G = CompensatedSliceNumThermal;
            ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, CpPllBwCfgHighRegAdd, CpPllbwCfgHigh.val_u32);
        }
        if (BC_ERR_NOERROR == ErrCode)
        {
            // Configure LPF bank with high bandwidth settings
            PllLpfCapPllbwCfgHigh.val_u32 = 0u;
            PllLpfCapPllbwCfgHigh.bits_st.PllLpfC1HighPllbwCfg1G = LPFTableEnrtyMax.LPF_C1;
            PllLpfCapPllbwCfgHigh.bits_st.PllLpfC2HighPllbwCfg1G = LPFTableEnrtyMax.LPF_C2;
            PllLpfCapPllbwCfgHigh.bits_st.PllLpfC3HighPllbwCfg1G = LPFTableEnrtyMax.LPF_C3;
            ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, PllLpfCapPllBwCfgHighRegAdd, PllLpfCapPllbwCfgHigh.val_u32);
        }
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_GetGainCorrRstBW(CAFC_LoopFilterLUTSel_e LPFLUTSel, float32_t *pGainCorrOTP, float32_t *pPLLLoopBWReset)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    float32_t KvcoRef;
    float32_t KvcoOTP;
    uint32_t FreqCountLowVtune;
    uint32_t FreqCountHighVtune;
    uint32_t OTPCALChirpInjDAC3;
    uint32_t OTPCALChirpInjDAC5;
    uint32_t OTPCALChirpInjDAC7;

    if (LPFLUTSel == e_CAFC_LPF_LUT_1G)
    {
        KvcoRef = 575.0e6f;
        // Reset PLL loop bandwidth is set to 2400e3f, Since for Rst we will use C1, C2 and C3 value only,
        // for 200, 250 and 300K C1Acq,C2 Acq and C3 Acq are same so we can go to use max frequency values
        *pPLLLoopBWReset = 2400e3f;
        ErrCode = HAL_ES2_OTP_GetOTPRegValue(OTP_CAL_CHIRP_INJ_DAC_3_INDEX, &OTPCALChirpInjDAC3);
        if (ErrCode == BC_ERR_NOERROR)
        {
            FreqCountLowVtune = (OTPCALChirpInjDAC3 & 0x1FFF0000u) >> 16u;
            FreqCountHighVtune = OTPCALChirpInjDAC3 & 0x1FFFu;
        }
    }
    else if (LPFLUTSel == e_CAFC_LPF_LUT_5GNARROW)
    {
        KvcoRef = 1380.0e6f;
        // Reset PLL loop bandwidth is set to 2400e3f, Since for Rst we will use C1, C2 and C3 value only,
        // for 250 and 300K C1Acq,C2 Acq and C3 Acq are same so we can go to use max frequency values
        *pPLLLoopBWReset = 2400e3f;
        ErrCode = HAL_ES2_OTP_GetOTPRegValue(OTP_CAL_CHIRP_INJ_DAC_5_INDEX, &OTPCALChirpInjDAC5);
        if (ErrCode == BC_ERR_NOERROR)
        {
            FreqCountLowVtune = (OTPCALChirpInjDAC5 & 0x1FFF0000u) >> 16u;
            FreqCountHighVtune = OTPCALChirpInjDAC5 & 0x1FFFu;
        }
    }
    else
    {
        /* its  e_CAFC_LPF_LUT_5GWIDE */
        KvcoRef = 2220.0e6f;
        // Reset PLL loop bandwidth is set to 2800e3f, Since for Rst we will use C1, C2 and C3 value only,
        // we can go to use max frequency values
        *pPLLLoopBWReset = 2800e3f;
        ErrCode = HAL_ES2_OTP_GetOTPRegValue(OTP_CAL_CHIRP_INJ_DAC_7_INDEX, &OTPCALChirpInjDAC7);
        if (ErrCode == BC_ERR_NOERROR)
        {
            FreqCountLowVtune = (OTPCALChirpInjDAC7 & 0x1FFF0000u) >> 16u;
            FreqCountHighVtune = OTPCALChirpInjDAC7 & 0x1FFFu;
        }
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        KvcoOTP = 2.0f * 25.0f * 67108864.0f / (20.0e-6f * 0.8142f) * ((1.0f / (float32_t)FreqCountLowVtune) - (1.0f / (float32_t)FreqCountHighVtune));
        // Calculate the gain correction coefficient as the ratio of KvcoRef and KvcoOTP
        // KvcoOTP is caluculated at 78.5 GHZ, but KvcoRef is at 76 Ghz, so a correction of 1.1 is multiplied here
        *pGainCorrOTP = (1.1f * KvcoRef) / KvcoOTP;
    }
    return ErrCode;
}
static void Helper_ES2_GetKvcoRef(CAFC_LoopFilterLUTSel_e LPFLUTSel, float32_t *pKvcoRef)
{
    if (LPFLUTSel == e_CAFC_LPF_LUT_1G)
    {
        *pKvcoRef = 575.0e6f;
    }
    if (LPFLUTSel == e_CAFC_LPF_LUT_5GNARROW)
    {
        *pKvcoRef = 1380.0e6f;
    }
    if (LPFLUTSel == e_CAFC_LPF_LUT_5GWIDE)
    {
        *pKvcoRef = 2220.0e6f;
    }
}
static BC_ERRCODE Helper_ES2_UpdateLoopFilter(CAFC_PLLLPFSel_e PLLLPFSel, CAFC_LoopFilterLUTSel_e LPFLUTSel, float32_t PLLLoopBW, float32_t KvcoAverageLocal, BOOL DownChirp)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M06_CpPllbwCfg0Union_t CpPllbw;
    uint16_t CP_PLLBW_CFG;
    uint8_t SliceNum = 0u;
    uint8_t CompensatedSliceNum = 0u;
    uint8_t CompensatedSliceNumThermal = 0u;
    uint8_t IbiasCp150U = 0u;
    float32_t KvcoRef = 575.0e6f;
    uint8_t CompensatedIbiasCp150U = 0u;
    float32_t CorrectedIcp150U;
    float32_t KvcoAverageCorr;
    float32_t IcpCompensated;
    CAFC_LPFLUTEntry_t LPFTableEnrty = {
        0.0f,
        0u,
        0u,
        0u,
        0u,
        0u,
        0u};

    (void)Helper_ES2_GetKvcoRef(LPFLUTSel, &KvcoRef);
    // Calculate the Kvco average correction coefficient as the ratio of KvcoRef and KvcoAverage
    // This correction includes frequency variation, therefore no addtional frequency correction needs to be done
    KvcoAverageCorr = KvcoRef / KvcoAverageLocal;
    // get the loop filter entry which needs to be configured
    ErrCode = HAL_ES2_CAFC_GetLoopFilterEntry(LPFLUTSel, PLLLoopBW, &LPFTableEnrty);
    if (BC_ERR_NOERROR == ErrCode)
    {
        SliceNum = LPFTableEnrty.CP_SLICE_EN;
        IbiasCp150U = LPFTableEnrty.IBIAS_CP_150U;

        // compensated Icp     = comp factor *  programmable bias level  *3.125uA/level  *  num of slices
        CorrectedIcp150U = KvcoAverageCorr * (float32_t)IbiasCp150U * 3.125f;
        IcpCompensated = CorrectedIcp150U * (float32_t)SliceNum; // total current

        // if correctedIcp150U>=45 uA, keep the number of slice as the same from the LUT
        // if  correctedIcp150U < 45 and SlicenNum >1 compensation is needed for number of Slice (Decrease the unumber of slice to make CorrectedIcp150u >45.0f)
        if ((CorrectedIcp150U < 45.0f) && (SliceNum > 1u))
        {
            CompensatedSliceNum = (uint8_t)roundf(IcpCompensated / 85.0f); // new number of slices
            SliceNum = CompensatedSliceNum;
            if (SliceNum == 0u)
            {
                ErrCode = BC_ERR_CAFC_CONFIGLOOPFILTERFAIL;
            }
            else
            {
                CorrectedIcp150U = IcpCompensated / (float32_t)SliceNum;
            }
        }
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        CompensatedIbiasCp150U = (uint8_t)roundf(CorrectedIcp150U / 3.125f);
        // convert binary to thermalmeter code
        CompensatedSliceNumThermal = 0xffu >> (8u - SliceNum);
        CP_PLLBW_CFG = R2M06_CP_PLLBW_CFG0_U16 + (((uint16_t)PLLLPFSel - (uint16_t)e_CAFC_PLLLPF_CFG0) * (R2M06_CP_PLLBW_CFG1_U16 - R2M06_CP_PLLBW_CFG0_U16));
        CpPllbw.val_u32 = 0u;
        CpPllbw.bits_st.CtlCpIoffsetUpdnSpiPllbwCfg0 = (DownChirp == TRUE) ? CAFC_NMOS_INJECT_CURRENT : CAFC_PMOS_INJECT_CURRENT;
        CpPllbw.bits_st.CtlCpIoffsetSetSpiPllbwCfg0 = CAFC_CHARGE_PUMP_10_PERCENT_OFFSET;
        CpPllbw.bits_st.CtlCpSliceEn0PllbwCfg0 = CompensatedSliceNumThermal;
        CpPllbw.bits_st.CtlIbiasCp150USpiPllbwCfg0 = CompensatedIbiasCp150U;
        ErrCode = BC_SPI_Write(e_SYS_CAFC, CP_PLLBW_CFG, CpPllbw.val_u32);
    }
    return ErrCode;
}
BC_ERRCODE HAL_ES2_CAFC_UpdateLoopFilterCP(CAFC_PLLLPFSel_e PLLLPFSel, CAFC_LoopFilterLUTSel_e LPFLUTSel, float32_t PLLLoopBW, float32_t KvcoAverage, BOOL DownChirp)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    uint32_t CntLowKvcoAvg = 0u; // counter value of Kvco average measurement
    float32_t CntLowKvcoAvgTemp;
    uint32_t CntHighKvcoAvg = 0u; // counter value of Kvco average measurement
    float32_t CntHighKvcoAvgTemp;
    R2M06_KvcoCountStatusUnion_t KvcoCountStatus;
    float32_t KvcoAverageLocal = 0.0f;

    if ((PLLLPFSel < e_CAFC_PLLLPF_INVALID) && (LPFLUTSel < e_CAFC_LPF_LUT_USER1))
    {

        // if KvcoAverage is input as 0, then it will be calculated here using register values
        if (KvcoAverage == 0.0f)
        {
            // Read KVCO average measurement
            ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_KVCO_COUNT_STATUS_U16, &KvcoCountStatus.val_u32);
            if (ErrCode == BC_ERR_NOERROR)
            {
                CntHighKvcoAvg = KvcoCountStatus.bits_st.CntHighKvcoAvgOnfly;
                CntLowKvcoAvg = KvcoCountStatus.bits_st.CntLowKvcoAvgOnfly;
                if ((CntHighKvcoAvg != 0u) && (CntLowKvcoAvg != 0u))
                {
                    CntHighKvcoAvgTemp = 67108864.0f / (float32_t)CntHighKvcoAvg;
                    CntLowKvcoAvgTemp = 67108864.0f / (float32_t)CntLowKvcoAvg;
                    KvcoAverageLocal = 2.0f * 25.0f * 67108864.0f / (20.0e-6f * 0.8142f) * ((1.0f / (float32_t)CntLowKvcoAvgTemp) - (1.0f / (float32_t)CntHighKvcoAvgTemp));
                }
                else
                {
                    ErrCode = BC_ERR_CAFC_KVCO_COUNT_STATUS_ERR;
                }
            }
        }
        else
        {
            KvcoAverageLocal = KvcoAverage;
        }

        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = Helper_ES2_UpdateLoopFilter(PLLLPFSel, LPFLUTSel, PLLLoopBW, KvcoAverageLocal, DownChirp);
        }
    }
    else
    {
        ErrCode = BC_ERR_CAFC_INPUTOUTOFRANGE;
    }
    return ErrCode;
}

static BC_ERRCODE Helper_ES2_Get1GLoopFilterSettng(float32_t PLLLoopBW, CAFC_LPFLUTEntry_t *pTableEntry)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    float32_t TempBw;
    uint8_t Index = 0u;
    // local storage of CAFC loop filter settings
    // A configruation table is used instead of a calculation API for every case, this decision might change later.
    // unlike Dolphin, Barracuda needs just 1 or 2 PLL LPF BW settings per VCO
    static const CAFC_LPFLUTEntry_t LoopFilterSettingsTable1G[NUM_ENTRY_LOOPFILTER_1G_TABLE] =
        {{200e3f, 255u, 118u, 64u, 1u, 23u, 1787u},
         {250e3f, 255u, 118u, 64u, 1u, 36u, 1425u},
         {300e3f, 255u, 118u, 64u, 1u, 53u, 1190u},
         {350e3f, 216u, 101u, 55u, 2u, 30u, 1190u},
         {400e3f, 187u, 88u, 48u, 2u, 35u, 1190u},
         {450e3f, 164u, 78u, 42u, 2u, 39u, 1190u},
         {500e3f, 146u, 70u, 38u, 2u, 44u, 1190u},
         {550e3f, 131u, 64u, 34u, 2u, 48u, 1190u},
         {600e3f, 119u, 58u, 31u, 2u, 53u, 1190u},
         {650e3f, 109u, 54u, 29u, 3u, 38u, 1190u},
         {700e3f, 100u, 50u, 27u, 3u, 41u, 1190u},
         {750e3f, 92u, 47u, 25u, 3u, 44u, 1190u},
         {800e3f, 85u, 44u, 23u, 3u, 47u, 1190u},
         {850e3f, 79u, 41u, 22u, 3u, 50u, 1190u},
         {900e3f, 74u, 39u, 21u, 3u, 53u, 1190u},
         {950e3f, 69u, 37u, 19u, 4u, 41u, 1190u},
         {1000e3f, 65u, 35u, 18u, 4u, 44u, 1190u},
         {1050e3f, 61u, 33u, 17u, 4u, 46u, 1190u},
         {1100e3f, 57u, 32u, 17u, 4u, 48u, 1190u},
         {1150e3f, 54u, 30u, 16u, 4u, 50u, 1190u},
         {1200e3f, 51u, 29u, 15u, 4u, 53u, 1190u},
         {1250e3f, 48u, 28u, 14u, 5u, 44u, 1190u},
         {1300e3f, 46u, 27u, 14u, 5u, 45u, 1190u},
         {1350e3f, 44u, 26u, 13u, 5u, 47u, 1190u},
         {1400e3f, 41u, 25u, 13u, 5u, 49u, 1190u},
         {1450e3f, 39u, 24u, 12u, 5u, 51u, 1190u},
         {1500e3f, 38u, 23u, 12u, 5u, 53u, 1190u},
         {1550e3f, 36u, 22u, 11u, 6u, 45u, 1190u},
         {1600e3f, 34u, 21u, 11u, 6u, 47u, 1190u},
         {1650e3f, 33u, 21u, 11u, 6u, 48u, 1190u},
         {1700e3f, 31u, 20u, 10u, 6u, 50u, 1190u},
         {1750e3f, 30u, 20u, 10u, 6u, 51u, 1190u},
         {1800e3f, 29u, 19u, 10u, 6u, 53u, 1190u},
         {1850e3f, 27u, 18u, 9u, 7u, 46u, 1190u},
         {1900e3f, 26u, 18u, 9u, 7u, 47u, 1190u},
         {1950e3f, 25u, 17u, 9u, 7u, 49u, 1190u},
         {2000e3f, 24u, 17u, 9u, 7u, 50u, 1190u},
         {2050e3f, 23u, 17u, 8u, 7u, 51u, 1190u},
         {2100e3f, 22u, 16u, 8u, 7u, 53u, 1190u},
         {2150e3f, 21u, 16u, 8u, 8u, 47u, 1190u},
         {2200e3f, 20u, 15u, 8u, 8u, 48u, 1190u},
         {2250e3f, 19u, 15u, 8u, 8u, 49u, 1190u},
         {2300e3f, 19u, 15u, 7u, 8u, 50u, 1190u},
         {2350e3f, 18u, 14u, 7u, 8u, 51u, 1190u},
         {2400e3f, 17u, 14u, 7u, 8u, 53u, 1190u}};

    if ((PLLLoopBW >= 200e3f) && (PLLLoopBW <= 2400e3f))
    {
        // Index equal to ((BW / 50) minus 4) since BW filter setting change in the table is multiple of 50kHz
        TempBw = PLLLoopBW * 2.0f * 1e-5f;
        Index = (uint8_t)lroundf((TempBw - 4.0f));
    }
    else
    {
        ErrCode = BC_ERR_CAFC_LOOPBWOUTOFRANGE;
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        // assign output value
        *pTableEntry = LoopFilterSettingsTable1G[Index];
    }
    return ErrCode;
}

static BC_ERRCODE Helper_ES2_Get5GNwLpFilterSettng(float32_t PLLLoopBW, CAFC_LPFLUTEntry_t *pTableEntry)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    float32_t TempBw;
    uint8_t Index = 0u;
    // local storage of CAFC loop filter settings
    // A configruation table is used instead of a calculation API for every case, this decision might change later.
    // unlike Dolphin, Barracuda needs just 1 or 2 PLL LPF BW settings per VCO
    static const CAFC_LPFLUTEntry_t LoopFilterSettingsTable2G[NUM_ENTRY_LOOPFILTER_2G_TABLE] =
        {{250e3f, 255u, 118u, 64u, 1u, 15u, 1425u},
         {300e3f, 255u, 118u, 64u, 1u, 22u, 1191u},
         {350e3f, 216u, 101u, 55u, 1u, 25u, 1191u},
         {400e3f, 187u, 88u, 48u, 1u, 29u, 1191u},
         {450e3f, 164u, 78u, 42u, 1u, 33u, 1191u},
         {500e3f, 146u, 70u, 38u, 1u, 36u, 1191u},
         {550e3f, 131u, 64u, 34u, 1u, 40u, 1191u},
         {600e3f, 119u, 58u, 31u, 2u, 22u, 1191u},
         {650e3f, 108u, 54u, 29u, 2u, 23u, 1191u},
         {700e3f, 100u, 50u, 27u, 2u, 25u, 1191u},
         {750e3f, 92u, 47u, 25u, 2u, 27u, 1191u},
         {800e3f, 85u, 44u, 23u, 2u, 29u, 1191u},
         {850e3f, 79u, 41u, 22u, 2u, 31u, 1191u},
         {900e3f, 74u, 39u, 21u, 2u, 33u, 1191u},
         {950e3f, 69u, 37u, 19u, 3u, 23u, 1191u},
         {1000e3f, 65u, 35u, 18u, 3u, 24u, 1191u},
         {1050e3f, 61u, 33u, 17u, 3u, 25u, 1191u},
         {1100e3f, 57u, 32u, 17u, 3u, 26u, 1191u},
         {1150e3f, 54u, 30u, 16u, 3u, 28u, 1191u},
         {1200e3f, 51u, 29u, 15u, 4u, 22u, 1191u},
         {1250e3f, 48u, 28u, 14u, 4u, 22u, 1191u},
         {1300e3f, 46u, 27u, 14u, 4u, 23u, 1191u},
         {1350e3f, 44u, 26u, 13u, 4u, 24u, 1191u},
         {1400e3f, 41u, 25u, 13u, 4u, 25u, 1191u},
         {1450e3f, 39u, 24u, 12u, 4u, 26u, 1191u},
         {1500e3f, 38u, 23u, 12u, 4u, 27u, 1191u},
         {1550e3f, 36u, 22u, 11u, 5u, 22u, 1191u},
         {1600e3f, 34u, 21u, 11u, 5u, 23u, 1191u},
         {1650e3f, 33u, 21u, 11u, 5u, 24u, 1191u},
         {1700e3f, 31u, 20u, 10u, 5u, 25u, 1191u},
         {1750e3f, 30u, 20u, 10u, 5u, 25u, 1191u},
         {1800e3f, 28u, 19u, 10u, 5u, 26u, 1191u},
         {1850e3f, 27u, 18u, 9u, 6u, 22u, 1191u},
         {1900e3f, 26u, 18u, 9u, 6u, 23u, 1191u},
         {1950e3f, 25u, 17u, 9u, 6u, 23u, 1191u},
         {2000e3f, 24u, 17u, 9u, 6u, 24u, 1191u},
         {2050e3f, 23u, 17u, 8u, 6u, 25u, 1191u},
         {2100e3f, 22u, 16u, 8u, 6u, 25u, 1191u},
         {2150e3f, 21u, 16u, 8u, 7u, 22u, 1191u},
         {2200e3f, 20u, 15u, 8u, 7u, 23u, 1191u},
         {2250e3f, 19u, 15u, 8u, 7u, 23u, 1191u},
         {2300e3f, 19u, 15u, 7u, 7u, 24u, 1191u},
         {2350e3f, 18u, 14u, 7u, 7u, 24u, 1191u},
         {2400e3f, 17u, 14u, 7u, 8u, 22u, 1191u}};

    if ((PLLLoopBW >= 250e3f) && (PLLLoopBW <= 2400e3f))
    {
        // Index equal to ((BW / 50) minus 5) since BW filter setting change in the table is multiple of 50kHz
        TempBw = PLLLoopBW * 2.0f * 1e-5f;
        Index = (uint8_t)lroundf((TempBw - 5.0f));
    }
    else
    {
        ErrCode = BC_ERR_CAFC_LOOPBWOUTOFRANGE;
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        // assign output value
        *pTableEntry = LoopFilterSettingsTable2G[Index];
    }
    return ErrCode;
}

static BC_ERRCODE Helper_ES2_Get5GWdLpFilterSettng(float32_t PLLLoopBW, CAFC_LPFLUTEntry_t *pTableEntry)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    float32_t TempBw;
    uint8_t Index = 0u;
    // local storage of CAFC loop filter settings
    // A configruation table is used instead of a calculation API for every case, this decision might change later.
    // unlike Dolphin, Barracuda needs just 1 or 2 PLL LPF BW settings per VCO
    static const CAFC_LPFLUTEntry_t LoopFilterSettingsTable4G[NUM_ENTRY_LOOPFILTER_4G_TABLE] =
        {{300e3f, 255u, 118u, 64u, 1u, 13u, 1190u},
         {350e3f, 254u, 117u, 64u, 1u, 18u, 1022u},
         {400e3f, 220u, 103u, 56u, 1u, 21u, 1022u},
         {450e3f, 194u, 91u, 49u, 1u, 23u, 1022u},
         {500e3f, 173u, 82u, 44u, 1u, 26u, 1022u},
         {550e3f, 156u, 74u, 40u, 1u, 29u, 1022u},
         {600e3f, 141u, 68u, 37u, 1u, 31u, 1022u},
         {650e3f, 129u, 63u, 34u, 1u, 34u, 1022u},
         {700e3f, 119u, 58u, 31u, 2u, 18u, 1022u},
         {750e3f, 110u, 54u, 29u, 2u, 19u, 1022u},
         {800e3f, 102u, 51u, 27u, 2u, 21u, 1022u},
         {850e3f, 95u, 48u, 26u, 2u, 22u, 1022u},
         {900e3f, 89u, 45u, 24u, 2u, 23u, 1022u},
         {950e3f, 83u, 43u, 23u, 2u, 25u, 1022u},
         {1000e3f, 78u, 41u, 22u, 2u, 26u, 1022u},
         {1050e3f, 74u, 39u, 21u, 3u, 18u, 1022u},
         {1100e3f, 69u, 37u, 20u, 3u, 19u, 1022u},
         {1150e3f, 66u, 35u, 19u, 3u, 20u, 1022u},
         {1200e3f, 62u, 34u, 18u, 3u, 21u, 1022u},
         {1250e3f, 59u, 32u, 17u, 3u, 22u, 1022u},
         {1300e3f, 56u, 31u, 16u, 3u, 23u, 1022u},
         {1350e3f, 54u, 30u, 16u, 3u, 23u, 1022u},
         {1400e3f, 51u, 29u, 15u, 4u, 18u, 1022u},
         {1450e3f, 49u, 28u, 15u, 4u, 19u, 1022u},
         {1500e3f, 46u, 27u, 14u, 4u, 19u, 1022u},
         {1550e3f, 44u, 26u, 14u, 4u, 20u, 1022u},
         {1600e3f, 43u, 25u, 13u, 4u, 21u, 1022u},
         {1650e3f, 41u, 24u, 13u, 4u, 21u, 1022u},
         {1700e3f, 39u, 24u, 12u, 4u, 22u, 1022u},
         {1750e3f, 37u, 23u, 12u, 5u, 18u, 1022u},
         {1800e3f, 36u, 22u, 11u, 5u, 19u, 1022u},
         {1850e3f, 35u, 22u, 11u, 5u, 19u, 1022u},
         {1900e3f, 33u, 21u, 11u, 5u, 20u, 1022u},
         {1950e3f, 32u, 20u, 10u, 5u, 20u, 1022u},
         {2000e3f, 31u, 20u, 10u, 5u, 21u, 1022u},
         {2050e3f, 30u, 19u, 10u, 5u, 21u, 1022u},
         {2100e3f, 28u, 19u, 10u, 6u, 18u, 1022u},
         {2150e3f, 27u, 18u, 9u, 6u, 19u, 1022u},
         {2200e3f, 26u, 18u, 9u, 6u, 19u, 1022u},
         {2250e3f, 25u, 18u, 9u, 6u, 19u, 1022u},
         {2300e3f, 24u, 17u, 9u, 6u, 20u, 1022u},
         {2350e3f, 24u, 17u, 9u, 6u, 20u, 1022u},
         {2400e3f, 23u, 16u, 8u, 6u, 21u, 1022u},
         {2450e3f, 22u, 16u, 8u, 7u, 18u, 1022u},
         {2500e3f, 21u, 16u, 8u, 7u, 19u, 1022u},
         {2550e3f, 20u, 15u, 8u, 7u, 19u, 1022u},
         {2600e3f, 20u, 15u, 8u, 7u, 19u, 1022u},
         {2650e3f, 19u, 15u, 7u, 7u, 20u, 1022u},
         {2700e3f, 18u, 15u, 7u, 7u, 20u, 1022u},
         {2750e3f, 18u, 14u, 7u, 7u, 20u, 1022u},
         {2800e3f, 17u, 14u, 7u, 8u, 18u, 1022u}};

    if ((PLLLoopBW >= 300e3f) && (PLLLoopBW <= 2800e3f))
    {
        // Index equal to ((BW / 50) minus 6) since BW filter setting change in the table is multiple of 50kHz
        TempBw = PLLLoopBW * 2.0f * 1e-5f;
        Index = (uint8_t)lroundf((TempBw - 6.0f));
    }
    else
    {
        ErrCode = BC_ERR_CAFC_LOOPBWOUTOFRANGE;
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        // assign output value
        *pTableEntry = LoopFilterSettingsTable4G[Index];
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_CAFC_GetLoopFilterEntry(CAFC_LoopFilterLUTSel_e LPFLUTSel, float32_t PLLLoopBW, CAFC_LPFLUTEntry_t *pTableEntry)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    // validate user input
    if (NULL != pTableEntry)
    {
        switch (LPFLUTSel)
        {
        case e_CAFC_LPF_LUT_1G:
        {
            ErrCode = Helper_ES2_Get1GLoopFilterSettng(PLLLoopBW, pTableEntry);
        }
        break;
        case e_CAFC_LPF_LUT_5GNARROW:
        {
            ErrCode = Helper_ES2_Get5GNwLpFilterSettng(PLLLoopBW, pTableEntry);
        }
        break;
        case e_CAFC_LPF_LUT_5GWIDE:
        {
            ErrCode = Helper_ES2_Get5GWdLpFilterSettng(PLLLoopBW, pTableEntry);
        }
        break;
        default:
            ErrCode = BC_ERR_CAFC_INPUTOUTOFRANGE;
            break;
        }
    }
    else
    {
        ErrCode = BC_ERR_CAFC_INPUTOUTOFRANGE;
    }

    return ErrCode;
}

BC_ERRCODE HAL_ES2_CAFC_ConfigMonitor(BOOL EnableAmpMon, BOOL EnableLockDet, CAFC_LockDetSettings *pLockDetSettings)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M06_FuncsafeMonUnlockControlUnion_t FuncsafeMonUnlockControl;
    R2M06_FuncsafeMonLevelSettingsEnUnion_t FuncsafeMonLevelSettingsEn;

    ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_FUNCSAFE_MON_UNLOCK_CONTROL_U16, &FuncsafeMonUnlockControl.val_u32);
    if (BC_ERR_NOERROR == ErrCode)
    {
        // allow NULL as detailed settings, since these settings are not often changed
        if (NULL != pLockDetSettings)
        {
            // lock detector configuration
            FuncsafeMonUnlockControl.bits_st.CtlLdPolSpi = (uint8_t)(pLockDetSettings->NegPolLockDet);
            if ((pLockDetSettings->LockDetWinSize <= 0x3Fu) && (pLockDetSettings->LockDetWinOffset <= 0x3Fu))
            {
                // TODO: ES2 Changes. FuncsafeMonUnlockControl.bits_st.CtlLdWindowDeltaSpi = pLockDetSettings->LockDetWinSize;
                FuncsafeMonUnlockControl.bits_st.CtlLdWindowOffsetSpi = pLockDetSettings->LockDetWinOffset;
            }
            else
            {
                ErrCode = BC_ERR_CAFC_INPUTOUTOFRANGE;
            }
        }
        FuncsafeMonUnlockControl.bits_st.CtlLdEnSpi = (uint8_t)EnableLockDet;

        if (BC_ERR_NOERROR == ErrCode)
        {
            ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, R2M06_FUNCSAFE_MON_UNLOCK_CONTROL_U16, FuncsafeMonUnlockControl.val_u32);
        }
    }

    // enable/disable VCO amplitude monitor
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_FUNCSAFE_MON_LEVEL_SETTINGS_EN_U16, &FuncsafeMonLevelSettingsEn.val_u32);
        if (BC_ERR_NOERROR == ErrCode)
        {
            FuncsafeMonLevelSettingsEn.bits_st.CtlLevelVcoAmpMonitorEnSpi = (uint8_t)EnableAmpMon;
            ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, R2M06_FUNCSAFE_MON_LEVEL_SETTINGS_EN_U16, FuncsafeMonLevelSettingsEn.val_u32);
        }
    }

    return ErrCode;
}

BC_ERRCODE HAL_ES2_CAFC_GetAAFCStatus(BOOL *pAACLocked, BOOL *pAFCLocked, BOOL *pAACError, BOOL *pAFCError, uint8_t *pAFCSubbandChoice, uint8_t *pAACiVCOChoice)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M06_AafcLockDvdtCountStatusUnion_t AafcLockDvdtCountStatus;
    R2M06_ChirpCalibrationStatusUnion_t ChirpCalibrationStatus;

    if ((NULL != pAACLocked) || (NULL != pAFCLocked) || (NULL != pAACError) || (NULL != pAFCError))
    {
        ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_AAFC_LOCK_DVDT_COUNT_STATUS_U16, &AafcLockDvdtCountStatus.val_u32);
        if (BC_ERR_NOERROR == ErrCode)
        {
            if (NULL != pAACLocked)
            {
                *pAACLocked = (AafcLockDvdtCountStatus.bits_st.AacLock == 1u) ? TRUE : FALSE;
            }
            if (NULL != pAFCLocked)
            {
                *pAFCLocked = (AafcLockDvdtCountStatus.bits_st.AfcLock == 1u) ? TRUE : FALSE;
            }
            if (NULL != pAACError)
            {
                *pAACError = (AafcLockDvdtCountStatus.bits_st.AacError == 1u) ? TRUE : FALSE;
            }
            if (NULL != pAFCError)
            {
                *pAFCError = (AafcLockDvdtCountStatus.bits_st.AfcError == 1u) ? TRUE : FALSE;
            }
        }
    }

    if ((BC_ERR_NOERROR == ErrCode) && ((NULL != pAFCSubbandChoice) || (NULL != pAACiVCOChoice)))
    {
        ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_CHIRP_CALIBRATION_STATUS_U16, &ChirpCalibrationStatus.val_u32);
        if (BC_ERR_NOERROR == ErrCode)
        {
            if (NULL != pAFCSubbandChoice)
            {
                *pAFCSubbandChoice = ChirpCalibrationStatus.bits_st.AfcFselOut;
            }
            if (NULL != pAACiVCOChoice)
            {
                *pAACiVCOChoice = ChirpCalibrationStatus.bits_st.AacIregCtrl;
            }
        }
    }

    return ErrCode;
}

BC_ERRCODE HAL_ES2_CAFC_EnableRFLevelRMSDet(BOOL EnRMSDet, CAFC_VCOBWSel_e VCOSel)
{
    BC_ERRCODE ErrCode;
    R2M06_RmsControlUnion_t RMSControl;
    if (VCOSel < e_CAFC_VCOBWSEL_INVALID)
    {
        ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_RMS_CONTROL_U16, &RMSControl.val_u32);
        if (BC_ERR_NOERROR == ErrCode)
        {
            RMSControl.bits_st.ChirpRmsEnSpi = (uint8_t)EnRMSDet;
            if (VCOSel == e_CAFC_1GBAND)
            {
                RMSControl.bits_st.ChirpSelRmsSpi = 0x1u;
            }
            else
            {
                RMSControl.bits_st.ChirpSelRmsSpi = 0x2u;
            }
            ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, R2M06_RMS_CONTROL_U16, RMSControl.val_u32);
        }
    }
    else
    {
        ErrCode = BC_ERR_CAFC_INPUTOUTOFRANGE;
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_CAFC_ConfigVCOProfile(SYS_ProfID_e ProfID, CAFC_VCOBWSel_e VCOSel, CAFC_PLLLPFSel_e PLLLPFSel, uint8_t iVCOFine, uint8_t Subband)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    uint16_t VCORegProfileAddr;
    R2M06_VcoRegProfile0Union_t VCORegProfile;
    R2M06_VcoControlUnion_t VcoControl;
    R2M06_RmsControlUnion_t RmsControl;

    if ((ProfID <= e_SYS_PROFILE_8) && (VCOSel < e_CAFC_VCOBWSEL_INVALID) && (PLLLPFSel < e_CAFC_PLLLPF_INVALID))
    {
        // calculate selected VCO profile register address
        ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_VCO_CONTROL_U16, &VcoControl.val_u32);
        if (BC_ERR_NOERROR == ErrCode)
        {
            VCORegProfileAddr = R2M06_VCO_REG_PROFILE0_U16 + (((uint16_t)ProfID - (uint16_t)e_SYS_PROFILE_0) * (R2M06_VCO_REG_PROFILE1_U16 - R2M06_VCO_REG_PROFILE0_U16));
            ErrCode = BC_SPI_Read(e_SYS_CAFC, VCORegProfileAddr, &VCORegProfile.val_u32);
        }
        if (BC_ERR_NOERROR == ErrCode)
        {
            if (VCOSel == e_CAFC_5GNARROW)
            {
                // select 5G BW VCO
                VcoControl.bits_st.CtlSelVco1G5GSpi = 1u;
                VCORegProfile.bits_st.CtlVcoBandwidthSpiProfile0 = 0u;
            }
            else if (VCOSel == e_CAFC_5GWIDE)
            {
                // select 5G BW VCO
                VcoControl.bits_st.CtlSelVco1G5GSpi = 1u;
                VCORegProfile.bits_st.CtlVcoBandwidthSpiProfile0 = 1u;
            }
            else
            {
                // select 1G BW VCO
                VcoControl.bits_st.CtlSelVco1G5GSpi = 0u;
                VCORegProfile.bits_st.CtlVcoBandwidthSpiProfile0 = 0u;
            }
            VCORegProfile.bits_st.PllbwCfgSelectionProfile0 = (uint8_t)PLLLPFSel;

            // modify or keep iVCO/Subband untouched
            if (iVCOFine < 64u)
            {
                VCORegProfile.bits_st.CtlVcoIvcoFineSpiProfile0 = iVCOFine;
            }

            // two sub conditions for 1GVCO and 5GVCO
            if (((VCOSel != e_CAFC_5GWIDE) && (Subband < 128u)) || ((VCOSel == e_CAFC_5GWIDE) && (Subband < 64u)))
            {
                VCORegProfile.bits_st.CtlVcoCoarseTuning9GSpiProfile0 = Subband;
            }

            ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, VCORegProfileAddr, VCORegProfile.val_u32);
            if (BC_ERR_NOERROR == ErrCode)
            {
                ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, R2M06_VCO_CONTROL_U16, VcoControl.val_u32);
            }
        }
        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_RMS_CONTROL_U16, &RmsControl.val_u32);
            if (ErrCode == BC_ERR_NOERROR)
            {
                RmsControl.bits_st.ChirpSelRmsSpi = (VCOSel == e_CAFC_1GBAND) ? 1u : 2u;
                ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, R2M06_RMS_CONTROL_U16, RmsControl.val_u32);
            }
        }
    }
    else
    {
        ErrCode = BC_ERR_CAFC_INPUTOUTOFRANGE;
    }

    return ErrCode;
}

BC_ERRCODE HAL_ES2_CAFC_ConfigFastReturn(BOOL EnableGS, BOOL EnableINJ)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    R2M06_PllFastResetInjEnControlUnion_t PllFastResetInjEnControl;
    R2M06_PllFastResetTimingControlUnion_t PllFastResetTimingControl;
    R2M06_CpFastResetSliceControlUnion_t CpFastResetSliceControl;
    R2M06_PllLpfCapGsSelControlUnion_t PllLpfCapGsSelControl;
    R2M06_PllDacInjAcqControlUnion_t PllDacInjAcqControl;
    R2M06_PllDacInjRstControlUnion_t PllDacInjRstControl;
    R2M06_LpfEnableSettingsUnion_t LpfEnableSettings;

    // first configure enable/disable
    ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_PLL_FAST_RESET_INJ_EN_CONTROL_U16, &PllFastResetInjEnControl.val_u32);
    if (BC_ERR_NOERROR == ErrCode)
    {
        // inverted logic
        PllFastResetInjEnControl.bits_st.PllGsDis = (TRUE == EnableGS) ? FALSE : TRUE;
        PllFastResetInjEnControl.bits_st.PllInjDis = (TRUE == EnableINJ) ? FALSE : TRUE;

        ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, R2M06_PLL_FAST_RESET_INJ_EN_CONTROL_U16, PllFastResetInjEnControl.val_u32);
    }

    // enable fast reset buffer
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_LPF_ENABLE_SETTINGS_U16, &LpfEnableSettings.val_u32);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        LpfEnableSettings.bits_st.CtlLpfFrBufferEnSpi = 1u;
        ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, R2M06_LPF_ENABLE_SETTINGS_U16, LpfEnableSettings.val_u32);
    }
    // Fast reset timing control settings
    if (BC_ERR_NOERROR == ErrCode)
    {

        PllFastResetTimingControl.val_u32 = 0xA000051Eu;
        ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, R2M06_PLL_FAST_RESET_TIMING_CONTROL_U16, PllFastResetTimingControl.val_u32);

        if (BC_ERR_NOERROR == ErrCode)
        {
            ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_CP_FAST_RESET_SLICE_CONTROL_U16, &CpFastResetSliceControl.val_u32);
            if (BC_ERR_NOERROR == ErrCode)
            {
                CpFastResetSliceControl.bits_st.PllCpSliceCtrl = (uint8_t)(e_CAFC_GSFROMTE); // timing engine used
                ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, R2M06_CP_FAST_RESET_SLICE_CONTROL_U16, CpFastResetSliceControl.val_u32);
            }
        }

        if (BC_ERR_NOERROR == ErrCode)
        {
            ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_PLL_LPF_CAP_GS_SEL_CONTROL_U16, &PllLpfCapGsSelControl.val_u32);
            if (BC_ERR_NOERROR == ErrCode)
            {
                PllLpfCapGsSelControl.bits_st.PllLpfCapGsSelCtrl = (uint8_t)(e_CAFC_GSFROMTE); // Timing engine used
                ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, R2M06_PLL_LPF_CAP_GS_SEL_CONTROL_U16, PllLpfCapGsSelControl.val_u32);
            }
        }
    }

    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_PLL_DAC_INJ_ACQ_CONTROL_U16, &PllDacInjAcqControl.val_u32);
        if (BC_ERR_NOERROR == ErrCode)
        {
            PllDacInjAcqControl.bits_st.PllDacInjAcqCtrl = (uint8_t)(e_CAFC_NORMALINJ); // pass the geneated dac_inj_acq signal from timing engine
            PllDacInjAcqControl.bits_st.PllDacInjAcqDelay = 0u;                         // no delay
            ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, R2M06_PLL_DAC_INJ_ACQ_CONTROL_U16, PllDacInjAcqControl.val_u32);
        }
    }

    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_PLL_DAC_INJ_RST_CONTROL_U16, &PllDacInjRstControl.val_u32);
        if (BC_ERR_NOERROR == ErrCode)
        {
            PllDacInjRstControl.bits_st.PllDacInjRstStartCtrl = 1u;
            PllDacInjRstControl.bits_st.PllDacInjRstOutputCtrl = (uint8_t)e_CAFC_GSFROMTE;
            PllDacInjRstControl.bits_st.PllDacInjRstCtrl = (uint8_t)(e_CAFC_NORMALINJ); // pass the generated dac_inj_rst signal from timing engine
            PllDacInjRstControl.bits_st.PllDacInjRstSyncDownCtrl = 0u;
            PllDacInjRstControl.bits_st.PllDacInjRstSyncUpCtrl = 0u;
            PllDacInjRstControl.bits_st.PllDacInjRstDelay = 5u;
            ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, R2M06_PLL_DAC_INJ_RST_CONTROL_U16, PllDacInjRstControl.val_u32);
        }
    }

    return ErrCode;
}

static BC_ERRCODE Helper_ES2_AACSettingRangeChck(CAFC_AACSettings_t *pAACSettings)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    if ((pAACSettings->AACKi > 7u) ||
        (pAACSettings->AACLockCriteria < 4u) ||
        (pAACSettings->AACLockCriteria > 18u) ||
        (((pAACSettings->AACLockCriteria) & 0x01u) != 0u) ||
        (pAACSettings->AACRefTime >= e_CAFC_AACTREF_INVALID) ||
        (pAACSettings->MinVCOCurrent >= 0x40u) ||
        (pAACSettings->VCOOverrideCurrent >= 0x40u))
    {
        ErrCode = BC_ERR_CAFC_INPUTOUTOFRANGE;
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_ConfigAACSettings(CAFC_AACSettings_t *pAACSettings)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M06_ChirpCalibrationAacControl1Union_t AACControl1;
    R2M06_ChirpCalibrationAacControl2Union_t AACControl2;
    ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_CHIRP_CALIBRATION_AAC_CONTROL1_U16, &AACControl1.val_u32);
    if (BC_ERR_NOERROR == ErrCode)
    {
        AACControl1.bits_st.AacIctrlInitOverride = (uint8_t)(pAACSettings->OverrideInitialVCOCurrent);
        AACControl1.bits_st.AacIctrlInitOverrideValue = pAACSettings->VCOOverrideCurrent;
        AACControl1.bits_st.AacIctrlMin = pAACSettings->MinVCOCurrent;
        ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, R2M06_CHIRP_CALIBRATION_AAC_CONTROL1_U16, AACControl1.val_u32);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_CHIRP_CALIBRATION_AAC_CONTROL2_U16, &AACControl2.val_u32);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        AACControl2.bits_st.AacFrefSel = (uint8_t)pAACSettings->AACRefTime;
        AACControl2.bits_st.AacLockCtrl = (uint8_t)((pAACSettings->AACLockCriteria - 4u) / 2u); // reg setting of 0 means 4 iterations
        AACControl2.bits_st.AacKi = pAACSettings->AACKi;
        ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, R2M06_CHIRP_CALIBRATION_AAC_CONTROL2_U16, AACControl2.val_u32);
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_AFCLockRangeChck(CAFC_AFCSettings_t *pAFCSettings)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    if ((pAFCSettings->AFCLockCriteria1 < 2u) ||
        (pAFCSettings->AFCLockCriteria2 < 2u) ||
        (pAFCSettings->AFCLockCriteria1 > 9u) ||
        (pAFCSettings->AFCLockCriteria2 > 9u))
    {
        ErrCode = BC_ERR_CAFC_INPUTOUTOFRANGE;
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_AFCSettingRangeChck(CAFC_AFCSettings_t *pAFCSettings)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    if ((pAFCSettings->AFCKi > 7u) ||
        (pAFCSettings->AFCKi2 > 7u) ||
        (pAFCSettings->AFCRefTime >= e_CAFC_AFCTREF_INVALID) ||
        (pAFCSettings->AFCStepLimit >= e_CAFC_AFCSTEP_INVALID) ||
        (pAFCSettings->MinSB > 127u) ||
        (pAFCSettings->SBOverrideValue > 127u))
    {
        ErrCode = BC_ERR_CAFC_INPUTOUTOFRANGE;
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = Helper_ES2_AFCLockRangeChck(pAFCSettings);
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_ConfigAFCSettings(CAFC_AFCSettings_t *pAFCSettings)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M06_ChirpCalibrationAfcControl1Union_t AFCControl1;
    R2M06_ChirpCalibrationAfcControl2Union_t AFCControl2;
    ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_CHIRP_CALIBRATION_AFC_CONTROL1_U16, &AFCControl1.val_u32);
    if (BC_ERR_NOERROR == ErrCode)
    {
        AFCControl1.bits_st.AfcFselInitOverride = (uint8_t)(pAFCSettings->OverrideInitialSB);
        AFCControl1.bits_st.AfcFselInitOverrideValue = pAFCSettings->SBOverrideValue;
        AFCControl1.bits_st.AfcFselMin = pAFCSettings->MinSB;

        AFCControl2.bits_st.AfcFrefSel = (uint8_t)(pAFCSettings->AFCRefTime);
        AFCControl2.bits_st.AfcKiCtrl1 = pAFCSettings->AFCKi;
        AFCControl2.bits_st.AfcKiCtrl2 = pAFCSettings->AFCKi2;
        AFCControl2.bits_st.AfcLockCtrl1 = (uint8_t)(pAFCSettings->AFCLockCriteria1 - 2u); // reg setting of 0 means 2 iterations
        AFCControl2.bits_st.AfcLockCtrl2 = (uint8_t)(pAFCSettings->AFCLockCriteria2 - 2u);
        AFCControl2.bits_st.AfcStepLimit = (uint8_t)(pAFCSettings->AFCStepLimit);
        ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, R2M06_CHIRP_CALIBRATION_AFC_CONTROL1_U16, AFCControl1.val_u32);
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_CHIRP_CALIBRATION_AFC_CONTROL2_U16, &AFCControl2.val_u32);
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        AFCControl2.bits_st.AfcFrefSel = (uint8_t)(pAFCSettings->AFCRefTime);
        AFCControl2.bits_st.AfcKiCtrl1 = pAFCSettings->AFCKi;
        AFCControl2.bits_st.AfcKiCtrl2 = pAFCSettings->AFCKi2;
        AFCControl2.bits_st.AfcLockCtrl1 = (uint8_t)(pAFCSettings->AFCLockCriteria1 - 2u); // reg setting of 0 means 2 iterations
        AFCControl2.bits_st.AfcLockCtrl2 = (uint8_t)(pAFCSettings->AFCLockCriteria2 - 2u);
        AFCControl2.bits_st.AfcStepLimit = (uint8_t)(pAFCSettings->AFCStepLimit);
        ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, R2M06_CHIRP_CALIBRATION_AFC_CONTROL2_U16, AFCControl2.val_u32);
    }
    return ErrCode;
}
BC_ERRCODE HAL_ES2_CAFC_ConfigAAFC(BOOL EnableAAFC, CAFC_AACSettings_t *pAACSettings, CAFC_AFCSettings_t *pAFCSettings)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    BARRACUDA_IGNORE_PARAM(EnableAAFC);

    if ((NULL == pAACSettings) && (NULL == pAFCSettings))
    {
        ErrCode = BC_ERR_CAFC_PTR_ADDR_NULL;
    }
    if ((BC_ERR_NOERROR == ErrCode) && (NULL != pAACSettings))
    {
        // allow null, since this is not a frequent setting
        ErrCode = Helper_ES2_AACSettingRangeChck(pAACSettings);
        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = Helper_ES2_ConfigAACSettings(pAACSettings);
        }
    }

    if ((BC_ERR_NOERROR == ErrCode) && (NULL != pAFCSettings))
    {
        // allow null, since this is not a frequent setting
        ErrCode = Helper_ES2_AFCSettingRangeChck(pAFCSettings);
        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = Helper_ES2_ConfigAFCSettings(pAFCSettings);
        }
    }

    return ErrCode;
}

BC_ERRCODE HAL_ES2_CAFC_SetVtuneVoltage(uint8_t ForceVtuneStartVolt, uint8_t ForceVtuneCenterVolt)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M06_LpfEnableSettingsUnion_t LpfEnableSettings;

    if ((ForceVtuneStartVolt < 0x80u) && (ForceVtuneCenterVolt < 0x80u))
    {
        ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_LPF_ENABLE_SETTINGS_U16, &LpfEnableSettings.val_u32);
        if (BC_ERR_NOERROR == ErrCode)
        {
            LpfEnableSettings.bits_st.CtlLpfProgForceVoltageSpi = ForceVtuneStartVolt;
            LpfEnableSettings.bits_st.CtlLpfProgForceVoltageCfSpi = ForceVtuneCenterVolt;
            ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, R2M06_LPF_ENABLE_SETTINGS_U16, LpfEnableSettings.val_u32);
        }
    }
    else
    {
        ErrCode = BC_ERR_CAFC_INPUTOUTOFRANGE;
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_CAFC_GetVCOCalibStatus(CAFC_AAFCStatus_t *pAAFCStatus, CAFC_KVCOStatus_t *pKVCOStatus, CAFC_DVDTStatus_t *pDVDTStatus)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M06_KvcoCountStatusUnion_t KvcoCountStatus;
    R2M06_AafcLockDvdtCountStatusUnion_t AafcLockDvdtCountStatus;
    R2M06_ChirpCalibrationStatusUnion_t ChirpCalibrationStatus;

    if ((pAAFCStatus == NULL) && (pKVCOStatus == NULL) && (pDVDTStatus == NULL))
    {
        ErrCode = BC_ERR_CAFC_PTR_ADDR_NULL;
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_AAFC_LOCK_DVDT_COUNT_STATUS_U16, &AafcLockDvdtCountStatus.val_u32);
        if ((BC_ERR_NOERROR == ErrCode) && (pDVDTStatus != NULL))
        {
            pDVDTStatus->DVDTDone = (BOOL)AafcLockDvdtCountStatus.bits_st.DoneFlagDvdt;
            pDVDTStatus->DVDTCntC1 = (uint16_t)AafcLockDvdtCountStatus.bits_st.DvdtCntC1Onfly;
        }
        if ((BC_ERR_NOERROR == ErrCode) && (pKVCOStatus != NULL))
        {
            pKVCOStatus->KVCODone = (BOOL)AafcLockDvdtCountStatus.bits_st.DoneFlagKvco;
            ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_KVCO_COUNT_STATUS_U16, &KvcoCountStatus.val_u32);
            if (BC_ERR_NOERROR == ErrCode)
            {
                pKVCOStatus->HighKvcoAvg = (uint16_t)KvcoCountStatus.bits_st.CntHighKvcoAvgOnfly;
                pKVCOStatus->LowKvcoAvg = (uint16_t)KvcoCountStatus.bits_st.CntLowKvcoAvgOnfly;
            }
        }
        if ((BC_ERR_NOERROR == ErrCode) && (pAAFCStatus != NULL))
        {
            pAAFCStatus->AACLocked = (BOOL)AafcLockDvdtCountStatus.bits_st.AacLock;
            pAAFCStatus->AFCLocked = (BOOL)AafcLockDvdtCountStatus.bits_st.AafcLock;
            ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_CHIRP_CALIBRATION_STATUS_U16, &ChirpCalibrationStatus.val_u32);
            if (BC_ERR_NOERROR == ErrCode)
            {
                pAAFCStatus->AACiVCOChoice = (uint8_t)ChirpCalibrationStatus.bits_st.AacIregCtrl;
                pAAFCStatus->AFCSubbandChoice = (uint8_t)ChirpCalibrationStatus.bits_st.AfcFselOut;
            }
        }
    }
    return ErrCode;
}

static BC_ERRCODE Helper_ES2_CalibRangeCheck(SYS_ProfID_e CalibrateProfID, SYS_StoreInProfile_t *pStoreInProfiles)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    if (pStoreInProfiles == NULL)
    {
        ErrCode = BC_ERR_CAFC_PTR_ADDR_NULL;
    }
    else
    {
        BOOL CheckStoreInProfile;
        CheckStoreInProfile = (BOOL)((pStoreInProfiles->Profile0) | (pStoreInProfiles->Profile1) | (pStoreInProfiles->Profile2) | (pStoreInProfiles->Profile3) | (pStoreInProfiles->Profile4) | (pStoreInProfiles->Profile5) | (pStoreInProfiles->Profile6) | (pStoreInProfiles->Profile7) | (pStoreInProfiles->Profile8));
        if (CheckStoreInProfile == FALSE)
        {
            ErrCode = BC_ERR_CAFC_NOSTOREINPROFILESELECTED;
        }
    }
    if ((BC_ERR_NOERROR == ErrCode) && (CalibrateProfID >= e_SYS_PROFILES_0_TO_1))
    {
        ErrCode = BC_ERR_CAFC_WRONGPROFILEID;
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_CheckDvdtError(BOOL PerformDVDT, uint8_t KvcoDvdtEnable, uint32_t AafcLockDvdtCountStatusVal32)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M06_AafcLockDvdtCountStatusUnion_t AafcLockDvdtCountStatus;
    AafcLockDvdtCountStatus.val_u32 = AafcLockDvdtCountStatusVal32;
    if ((KvcoDvdtEnable > 0u) && (AafcLockDvdtCountStatus.bits_st.KvcoDvdtError == TRUE))
    {
        ErrCode = BC_ERR_CAFC_VCOCALIB_KVCODVDTFAIL;
    }
    if ((BC_ERR_NOERROR == ErrCode) && (PerformDVDT == TRUE) && (AafcLockDvdtCountStatus.bits_st.DvdtCntC1Onfly > CAFC_DVDT_MAXIMUM_COUNT))
    {
        ErrCode = BC_ERR_CAFC_DVDT_COUNT_WRONG;
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_CalibStatus(BOOL PerformDVDT, uint8_t KvcoDvdtEnable, float32_t CalibTimeOutUs, uint32_t *pDvdtCntC1Onfly, SYS_ProfChirpFreq_t *pChirpFreq, SYS_StoreInProfile_t *pStoreInProfiles)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M06_AafcLockDvdtCountStatusUnion_t AafcLockDvdtCountStatus;
    ErrCode = PLF_TM_Sleep((uint32_t)CalibTimeOutUs);
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_AAFC_LOCK_DVDT_COUNT_STATUS_U16, &AafcLockDvdtCountStatus.val_u32);
        if (BC_ERR_NOERROR == ErrCode)
        {
            *pDvdtCntC1Onfly = AafcLockDvdtCountStatus.bits_st.DvdtCntC1Onfly;
            ErrCode = (AafcLockDvdtCountStatus.bits_st.AafcKvcoDvdtBusy == TRUE) ? BC_ERR_CAFC_AAFCKVCODVDT_TIMEOUT : BC_ERR_NOERROR;
            if ((BC_ERR_NOERROR == ErrCode) && ((AafcLockDvdtCountStatus.bits_st.AafcLock == FALSE) || (AafcLockDvdtCountStatus.bits_st.AafcError == TRUE)))
            {
                ErrCode = BC_ERR_CAFC_VCOCALIB_AAFCFAIL;
            }
            if (ErrCode == BC_ERR_NOERROR)
            {
                ErrCode = Helper_ES2_CheckDvdtError(PerformDVDT, KvcoDvdtEnable, AafcLockDvdtCountStatus.val_u32);
            }
        }
    }
    /* Check for sub band jump issue and correct it */
    if ((BC_ERR_NOERROR == ErrCode) && (pChirpFreq != NULL))
    {
        ErrCode = Helper_ES2_CalibCorrection(pChirpFreq->VCOSel, pStoreInProfiles);
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_CalCulateKvcoAvg(uint8_t KvcoDvdtEnable, float32_t *pKvcoAverage, uint32_t *pCntLowKvcoAvg, uint32_t *pCntHighKvcoAvg)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    uint32_t tempCntLowKvcoAvg = 0u;  // counter value of Kvco average measurement
    uint32_t tempCntHighKvcoAvg = 0u; // counter value of Kvco average measurement
    R2M06_KvcoCountStatusUnion_t KvcoCountStatus;

    if (KvcoDvdtEnable > 0u)
    {
        // Read KVCO average measurement
        ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_KVCO_COUNT_STATUS_U16, &KvcoCountStatus.val_u32);
        if (ErrCode == BC_ERR_NOERROR)
        {
            float32_t CntLowKvcoAvgTemp;
            float32_t CntHighKvcoAvgTemp;
            tempCntLowKvcoAvg = KvcoCountStatus.bits_st.CntHighKvcoAvgOnfly;
            tempCntHighKvcoAvg = KvcoCountStatus.bits_st.CntLowKvcoAvgOnfly;
            if ((tempCntLowKvcoAvg != 0u) && (tempCntHighKvcoAvg != 0u) && (tempCntLowKvcoAvg != tempCntHighKvcoAvg))
            {
                *pCntLowKvcoAvg = tempCntLowKvcoAvg;
                *pCntHighKvcoAvg = tempCntHighKvcoAvg;
                if (pKvcoAverage != NULL)
                {
                    CntHighKvcoAvgTemp = 67108864.0f / (float32_t)tempCntLowKvcoAvg;
                    CntLowKvcoAvgTemp = 67108864.0f / (float32_t)tempCntHighKvcoAvg;
                    *pKvcoAverage = 2.0f * 25.0f * 67108864.0f / (20.0e-6f * 0.8142f) * ((1.0f / (float32_t)CntLowKvcoAvgTemp) - (1.0f / (float32_t)CntHighKvcoAvgTemp));
                }
            }
            else
            {
                ErrCode = BC_ERR_CAFC_WRONG_KVCO;
            }
        }
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_SetForceDivider(BOOL PerformKVCO, uint32_t *pDivideForceControlVal32)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M06_DivideForceControlUnion_t DivideForceControl;
    if (PerformKVCO == TRUE)
    {
        ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_DIVIDE_FORCE_CONTROL_U16, &DivideForceControl.val_u32);
        if (ErrCode == BC_ERR_NOERROR)
        {
            *pDivideForceControlVal32 = DivideForceControl.val_u32;
            DivideForceControl.bits_st.CtlForceDivider = 1u;
            ErrCode = BC_SPI_Write(e_SYS_CAFC, R2M06_DIVIDE_FORCE_CONTROL_U16, DivideForceControl.val_u32);
        }
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_GetSubbandSkip(CAFC_VCOBWSel_e VCOSel, uint8_t *pSubbandSkip, uint8_t *pSubBandCheckNum, uint8_t *pMaxSB)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    uint32_t SubbandCorrection = 0u;
    uint32_t MaskTx = 0u;
    uint32_t PosTx = 0u;

    if (e_CAFC_1GBAND == VCOSel)
    {
        *pSubBandCheckNum = BC_CAFC_AFC_SKIPSB_CHECK_1G_2G_VCO;
        *pMaxSB = BC_CAFC_AFC_MAX_SB_VALUE_1G_2G_VCO;
        MaskTx = OtpTrimSubbandCorrection1g[OTP_VCO_1G_SKIP_64_CAFC_INDEX].SrcMsk;
        PosTx = OtpTrimSubbandCorrection1g[OTP_VCO_1G_SKIP_64_CAFC_INDEX].SrcPos;
        ErrCode = HAL_ES2_OTP_GetOTPRegValue(OTP_TRIM_SUBBAND_CORRECTION_1G_INDEX, &SubbandCorrection);
    }
    if (e_CAFC_5GNARROW == VCOSel)
    {
        *pSubBandCheckNum = BC_CAFC_AFC_SKIPSB_CHECK_1G_2G_VCO;
        *pMaxSB = BC_CAFC_AFC_MAX_SB_VALUE_1G_2G_VCO;
        MaskTx = OtpTrimSubbandCorrection2g[OTP_VCO_2G_SKIP_64_CAFC_INDEX].SrcMsk;
        PosTx = OtpTrimSubbandCorrection2g[OTP_VCO_2G_SKIP_64_CAFC_INDEX].SrcPos;
        ErrCode = HAL_ES2_OTP_GetOTPRegValue(OTP_TRIM_SUBBAND_CORRECTION_2G_INDEX, &SubbandCorrection);
    }
    if (e_CAFC_5GWIDE == VCOSel)
    {
        *pSubBandCheckNum = BC_CAFC_AFC_SKIPSB_CHECK_4G_VCO;
        *pMaxSB = BC_CAFC_AFC_MAX_SB_VALUE_4G_VCO;
        MaskTx = OtpTrimSubbandCorrection4g[OTP_VCO_4G_SKIP_32_CAFC_INDEX].SrcMsk;
        PosTx = OtpTrimSubbandCorrection4g[OTP_VCO_4G_SKIP_32_CAFC_INDEX].SrcPos;
        ErrCode = HAL_ES2_OTP_GetOTPRegValue(OTP_TRIM_SUBBAND_CORRECTION_4G_INDEX, &SubbandCorrection);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        *pSubbandSkip = (uint8_t)((SubbandCorrection & MaskTx) >> PosTx);
    }
    return ErrCode;
}

static BC_ERRCODE Helper_ES2_CopyCorrectSBSet(uint8_t CorrectedSubBand, SYS_StoreInProfile_t *pStoreInProfiles)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M06_VcoRegProfile0Union_t VcoRegProfile;
    uint16_t VCOReg;
    BOOL Profile[SYS_MAX_PROFILE_COUNT];
    uint16_t ProfileCount;

    (void)Helper_CAFCStoreInProfile(pStoreInProfiles, &Profile[0]);

    for (ProfileCount = 0u; ProfileCount < SYS_MAX_PROFILE_COUNT; ProfileCount++)
    {
        if ((Profile[ProfileCount] == TRUE) && (ErrCode == BC_ERR_NOERROR))
        {
            VCOReg = R2M06_VCO_REG_PROFILE0_U16 + (ProfileCount * (R2M06_VCO_REG_PROFILE1_U16 - R2M06_VCO_REG_PROFILE0_U16));
            ErrCode = BC_SPI_Read(e_SYS_CAFC, VCOReg, &VcoRegProfile.val_u32);
            if (ErrCode == BC_ERR_NOERROR)
            {
                VcoRegProfile.bits_st.CtlVcoCoarseTuning9GSpiProfile0 = CorrectedSubBand;
                ErrCode = BC_SPI_Write(e_SYS_CAFC, VCOReg, VcoRegProfile.val_u32);
            }
        }
    }
    return ErrCode;
}

static BC_ERRCODE Helper_ES2_CalibCorrection(CAFC_VCOBWSel_e VCOSel, SYS_StoreInProfile_t *pStoreInProfiles)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M06_ChirpCalibrationStatusUnion_t ChirpCalibrationStatus;
    uint8_t SubbandSkip = 0u;
    uint8_t CorrectedSubBand = 0u;
    uint8_t SubBandCheckNum = 0u;
    uint8_t MaxSB = 0u;

    ErrCode = Helper_ES2_GetSubbandSkip(VCOSel, &SubbandSkip, &SubBandCheckNum, &MaxSB);
    if ((ErrCode == BC_ERR_NOERROR) && (SubbandSkip != 0u))
    {
        ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_CHIRP_CALIBRATION_STATUS_U16, &ChirpCalibrationStatus.val_u32);
        if (ErrCode == BC_ERR_NOERROR)
        {
            if ((ChirpCalibrationStatus.bits_st.AfcFselOut == SubBandCheckNum))
            {
                CorrectedSubBand = SubBandCheckNum + SubbandSkip;
                ErrCode = Helper_ES2_CopyCorrectSBSet(CorrectedSubBand, pStoreInProfiles);
            }
        }
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_CAFC_CalibAAFCInjDAC(BOOL PerformKVCO, BOOL PerformDVDT, SYS_ProfChirpFreq_t *pChirpFreq, SYS_ProfChirpTiming_t *pChirpTiming, SYS_ProfID_e CalibrateProfID, SYS_StoreInProfile_t *pStoreInProfiles, float32_t CalibTimeOutUs, float32_t TempKelvinChirp, float32_t *pKvcoAverage)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M06_ChirpCalibrationSwControlUnion_t ChirpCalibrationSWControl;
    R2M06_DivideForceControlUnion_t DivideForceControl;
    uint32_t RestoreDivideForceControl = 0u;
    uint8_t AcqC1 = 0u;
    uint8_t AcqC2 = 0u;
    float32_t Acquisitiontime = 0.0f; // unit: seconds
    uint32_t CntLowKvcoAvg = 0u;      // counter value of Kvco average measurement
    uint32_t CntHighKvcoAvg = 0u;     // counter value of Kvco average measurement
    uint8_t KvcoDvdtEnable = 0x0u;
    uint32_t DvDtCntC1; // counter value of dvdt measurement

    BARRACUDA_IGNORE_PARAM(TempKelvinChirp);

    ErrCode = Helper_ES2_CalibRangeCheck(CalibrateProfID, pStoreInProfiles);
    if (BC_ERR_NOERROR == ErrCode)
    {
        // store previous settings
        ErrCode = Helper_ES2_SetForceDivider(PerformKVCO, &RestoreDivideForceControl);
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        ChirpCalibrationSWControl.val_u32 = 0u;
        ChirpCalibrationSWControl.bits_st.EnProfileForCalibration = (uint8_t)TRUE;
        ChirpCalibrationSWControl.bits_st.UseProfileForCalibration = (uint8_t)CalibrateProfID;

        ChirpCalibrationSWControl.bits_st.StoreInProfile0 = (uint8_t)pStoreInProfiles->Profile0;
        ChirpCalibrationSWControl.bits_st.StoreInProfile1 = (uint8_t)pStoreInProfiles->Profile1;
        ChirpCalibrationSWControl.bits_st.StoreInProfile2 = (uint8_t)pStoreInProfiles->Profile2;
        ChirpCalibrationSWControl.bits_st.StoreInProfile3 = (uint8_t)pStoreInProfiles->Profile3;
        ChirpCalibrationSWControl.bits_st.StoreInProfile4 = (uint8_t)pStoreInProfiles->Profile4;
        ChirpCalibrationSWControl.bits_st.StoreInProfile5 = (uint8_t)pStoreInProfiles->Profile5;
        ChirpCalibrationSWControl.bits_st.StoreInProfile6 = (uint8_t)pStoreInProfiles->Profile6;
        ChirpCalibrationSWControl.bits_st.StoreInProfile7 = (uint8_t)pStoreInProfiles->Profile7;
        ChirpCalibrationSWControl.bits_st.StoreInProfile8 = (uint8_t)pStoreInProfiles->Profile8;

        KvcoDvdtEnable = (((uint8_t)PerformDVDT << 1u) | (uint8_t)PerformKVCO);
        ChirpCalibrationSWControl.bits_st.KvcoDvdtEnable = KvcoDvdtEnable;

        ChirpCalibrationSWControl.bits_st.ProfileLoadForCalibration = (uint8_t)TRUE;
        ChirpCalibrationSWControl.bits_st.StartChirpCalibration = (uint8_t)TRUE;

        ErrCode = BC_SPI_Write(e_SYS_CAFC, R2M06_CHIRP_CALIBRATION_SW_CONTROL_U16, ChirpCalibrationSWControl.val_u32);
    }
    // If Dac injection is enabled
    // Read acquisition time, C1 and C2 valud for Injection DAC code calculation
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = Helper_ES2_GetAcqCurr(PerformDVDT, pChirpFreq, pChirpTiming, CalibrateProfID, &Acquisitiontime, &AcqC1, &AcqC2);
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = Helper_ES2_CalibStatus(PerformDVDT, KvcoDvdtEnable, CalibTimeOutUs, &DvDtCntC1, pChirpFreq, pStoreInProfiles);
    }

    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = Helper_ES2_CalCulateKvcoAvg(KvcoDvdtEnable, pKvcoAverage, &CntLowKvcoAvg, &CntHighKvcoAvg);
    }

    // If Dac injection is enabled
    if ((BC_ERR_NOERROR == ErrCode) && (PerformDVDT == TRUE))
    {
        // calculate and program DAC injection code
        ErrCode = Helper_ES2_CalculateDacInjection(pChirpFreq, pChirpTiming, Acquisitiontime, AcqC1, AcqC2, DvDtCntC1, CntHighKvcoAvg, CntLowKvcoAvg);
    }
    // RestoreDivideForceControl
    if ((ErrCode == BC_ERR_NOERROR) && (PerformKVCO == TRUE))
    {
        DivideForceControl.val_u32 = RestoreDivideForceControl;
        DivideForceControl.bits_st.CtlForceDivider = 0u;
        (void)BC_SPI_Write(e_SYS_CAFC, R2M06_DIVIDE_FORCE_CONTROL_U16, DivideForceControl.val_u32);
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_CAFC_SetVCOCalibTimeOut(float32_t CalibTimeOutUs)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M06_ChirpCalibrationTimeoutDelayUnion_t ChirpCalibrationTimeoutDelay;
    if ((CalibTimeOutUs >= CAFC_CALIBRATION_TIMEOUT_IN_US_MIN) && (CalibTimeOutUs <= CAFC_CALIBRATION_TIMEOUT_IN_US_MAX))
    {
        ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_CHIRP_CALIBRATION_TIMEOUT_DELAY_U16, &ChirpCalibrationTimeoutDelay.val_u32);
        if (BC_ERR_NOERROR == ErrCode)
        {
            ChirpCalibrationTimeoutDelay.bits_st.ChirpAafcCalibrationTimeoutCounter = (uint16_t)SYS_CONVERT_TIMEUS_TO_40MHZCYCLE(CalibTimeOutUs);
            ErrCode = BC_SPI_Write(e_SYS_CAFC, R2M06_CHIRP_CALIBRATION_TIMEOUT_DELAY_U16, ChirpCalibrationTimeoutDelay.val_u32);
        }
    }
    else
    {
        ErrCode = BC_ERR_CAFC_INPUTOUTOFRANGE;
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_CAFC_LoadProfile(SYS_ProfID_e ChirpProfSel)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M06_ChirpCalibrationSwControlUnion_t ChirpCalibrationSWControl;

    if (ChirpProfSel < e_SYS_PROFILES_0_TO_1)
    {
        ChirpCalibrationSWControl.val_u32 = 0u;
        ChirpCalibrationSWControl.bits_st.EnProfileForCalibration = (uint8_t)TRUE;
        ChirpCalibrationSWControl.bits_st.UseProfileForCalibration = (uint8_t)ChirpProfSel;
        ChirpCalibrationSWControl.bits_st.ProfileLoadForCalibration = (uint8_t)TRUE;
        ErrCode = BC_SPI_Write(e_SYS_CAFC, R2M06_CHIRP_CALIBRATION_SW_CONTROL_U16, ChirpCalibrationSWControl.val_u32);
    }
    else
    {
        ErrCode = BC_ERR_CAFC_WRONGPROFILEID;
    }
    return ErrCode;
}

static BC_ERRCODE Helper_ES2_GetAcqCurr(BOOL PerformDVDT, SYS_ProfChirpFreq_t *pChirpFreq, SYS_ProfChirpTiming_t *pChirpTiming, SYS_ProfID_e CalibrateProfID, float32_t *pAcquisitiontime, uint8_t *pAcqC1, uint8_t *pAcqC2)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M04_TimingControl2Profile0Union_t TimingControl2Profile;
    uint16_t TimingControl2RegAddr;
    TimingControl2RegAddr = R2M04_TIMING_CONTROL_2_PROFILE0_U16 + ((uint16_t)CalibrateProfID * 0x10u);

    R2M06_PllLpfC1PllbwCfg0Union_t PllLpfC1PllbwCfg;
    R2M06_PllLpfC2PllbwCfg0Union_t PllLpfC2PllbwCfg;
    CAFC_PLLLPFSel_e PLLCFGSel;
    uint16_t PLL_LPF_C1_CFG = R2M06_PLL_LPF_C1_PLLBW_CFG0_U16;
    uint16_t PLL_LPF_C2_CFG = R2M06_PLL_LPF_C2_PLLBW_CFG0_U16;
    if (PerformDVDT == TRUE)
    {
        // If DAC injection is enabled, chirp frequency and timing configurations cannnot be NULL
        if ((pChirpFreq != NULL) && (pChirpTiming != NULL) && (pChirpFreq->PLLLPFSel <= e_CAFC_PLLLPF_CFG3))
        {
            ErrCode = BC_SPI_Read(e_SYS_TE, TimingControl2RegAddr, &TimingControl2Profile.val_u32);
            if (ErrCode == BC_ERR_NOERROR)
            {
                // Read out aquisition time
                *pAcquisitiontime = (float32_t)(TimingControl2Profile.bits_st.AcquisitionDurationProfile0) * 25.0f * 1e-9f; // unit:s
                if (TimingControl2Profile.bits_st.AcquisitionDurationProfile0 != 0u)
                {
                    PLLCFGSel = pChirpFreq->PLLLPFSel;
                    PLL_LPF_C1_CFG = R2M06_PLL_LPF_C1_PLLBW_CFG0_U16 + (((uint16_t)PLLCFGSel - (uint16_t)e_CAFC_PLLLPF_CFG0) * (R2M06_PLL_LPF_C1_PLLBW_CFG1_U16 - R2M06_PLL_LPF_C1_PLLBW_CFG0_U16));
                    PLL_LPF_C2_CFG = R2M06_PLL_LPF_C2_PLLBW_CFG0_U16 + (((uint16_t)PLLCFGSel - (uint16_t)e_CAFC_PLLLPF_CFG0) * (R2M06_PLL_LPF_C2_PLLBW_CFG1_U16 - R2M06_PLL_LPF_C2_PLLBW_CFG0_U16));
                }
                else
                {
                    ErrCode = BC_ERR_CAFC_WRONG_ACQUISITION_DURATION;
                }
            }
            if (ErrCode == BC_ERR_NOERROR)
            {
                // Read out the previously configured C1 and C2 value
                ErrCode = BC_SPI_Read(e_SYS_CAFC, PLL_LPF_C1_CFG, &PllLpfC1PllbwCfg.val_u32);
            }
            if (ErrCode == BC_ERR_NOERROR)
            {
                *pAcqC1 = PllLpfC1PllbwCfg.bits_st.PllLpfC1AcqCtrlPllbwCfg0;
                ErrCode = BC_SPI_Read(e_SYS_CAFC, PLL_LPF_C2_CFG, &PllLpfC2PllbwCfg.val_u32);
                if (ErrCode == BC_ERR_NOERROR)
                {
                    *pAcqC2 = PllLpfC2PllbwCfg.bits_st.PllLpfC2AcqCtrlPllbwCfg0;
                }
            }
        }
        else
        {
            ErrCode = BC_ERR_INPUTOUTOFRANGE;
        }
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_CAFC_FastBiasChirpPll(void)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M06_AdditionalHwSettingsUnion_t AdditionalHWSettings;
    ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_ADDITIONAL_HW_SETTINGS_U16, &AdditionalHWSettings.val_u32);
    if (BC_ERR_NOERROR == ErrCode)
    {
        AdditionalHWSettings.bits_st.CtlIbiasSpeedUpMuxCtrl = 1u;
        AdditionalHWSettings.bits_st.CtlIbiasSpeedUp = 1u;
        ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, R2M06_ADDITIONAL_HW_SETTINGS_U16, AdditionalHWSettings.val_u32);
    }
    /* 5us sleep required after toggling of CtlIbiasSpeedUp */
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = PLF_TM_Sleep(BC_CAFC_FAST_BIAS_CHIRP_PLL_SLEEP);
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        AdditionalHWSettings.bits_st.CtlIbiasSpeedUpMuxCtrl = 0u;
        AdditionalHWSettings.bits_st.CtlIbiasSpeedUp = 0u;
        ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, R2M06_ADDITIONAL_HW_SETTINGS_U16, AdditionalHWSettings.val_u32);
    }
    return ErrCode;
}
#endif
/* end of file*/
