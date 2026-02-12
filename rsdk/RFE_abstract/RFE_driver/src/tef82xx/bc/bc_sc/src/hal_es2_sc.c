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
#include "bc_err.h"
#include "bc_types.h"
#include "bc_conf.h"
#ifdef BUILD_FOR_VAL
#include "v_es2_sc.h"
#include "v_es2_cc.h"
#include "v_es2_te.h"
#include "v_es2_cafc.h"
#else
#include "reg_es2_sc.h"
#include "reg_es2_cc.h"
#include "reg_es2_te.h"
#include "reg_es2_cafc.h"
#endif
#include "hal_es2_sc.h"
#include "bc_spi.h"
#include <math.h>
static BC_ERRCODE ValidateConfProfParams(BC_FLOAT StartFreq, BC_FLOAT usedBW, float32_t RampTime, float32_t ResetTime);
static BC_ERRCODE Helper_SC_ConfigSlowDriftChirp(SYS_ProfID_e ProfID, BC_FLOAT FreqDriftHz, float32_t TReset, BC_FLOAT InputBWFullRamp);

static BC_ERRCODE Helper_SC_ConfigSlowDriftChirp(SYS_ProfID_e ProfID, BC_FLOAT FreqDriftHz, float32_t TReset, BC_FLOAT InputBWFullRamp)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M05_DnResetRfProfile0Union_t DnResetRfProfileX;
    float32_t StepsInReset;
    BC_FLOAT ResetDriftStepSize;
    uint32_t DnReset = 0u;
    uint32_t DnResetDrift;
    uint32_t InputResetValue;
    uint16_t RegOffset;
    uint32_t StepsInResetRounded = 0u;
    RegOffset = (uint16_t)ProfID * 0x18u; /*This offset can be used wrt profile 0 registers*/
    ErrCode = BC_SPI_Read(e_SYS_SC, (R2M05_DN_RESET_RF_PROFILE0_U16 + RegOffset), &DnResetRfProfileX.val_u32);
    StepsInReset = TReset * SC_RAMPTIME_MULTIPLIER;
    StepsInResetRounded = (uint32_t)lroundf(StepsInReset);
    if ((InputBWFullRamp != 0.0) && (BC_ERR_NOERROR == ErrCode))
    {
        if ((InputBWFullRamp > FreqDriftHz))
        {
            BC_FLOAT ResetDIVStepSize;
            float32_t TempValue;
            ResetDIVStepSize = ((InputBWFullRamp - FreqDriftHz) * SC_FREQ2DIV);
            TempValue = (float32_t)ResetDIVStepSize;
            TempValue = TempValue / (float32_t)StepsInResetRounded;
            DnReset = (uint32_t)lroundf(TempValue);
        }
        else
        {
            ErrCode = BC_ERR_SC_INPUT_FREQ_DRIFT_INVALID;
        }
    }
    if ((InputBWFullRamp == 0.0) && (BC_ERR_NOERROR == ErrCode))
    {
        float32_t TempValue;
        ResetDriftStepSize = (FreqDriftHz * SC_FREQ2DIV);
        TempValue = (float32_t)ResetDriftStepSize;
        TempValue = TempValue / (float32_t)StepsInResetRounded;
        DnResetDrift = (uint32_t)lroundf(TempValue);
        // getting the DN reset value to for Full BW set in program Chirp
        InputResetValue = DnResetRfProfileX.bits_st.DnchirpresetRegProfile0 & 0x3FFFFFFu;
        if (InputResetValue > DnResetDrift)
        {
            DnReset = InputResetValue - DnResetDrift;
        }
        else
        {
            ErrCode = BC_ERR_SC_INPUT_FREQ_DRIFT_INVALID;
        }
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        // getting the ChirpType Only and resetting other bits
        DnResetRfProfileX.bits_st.DnchirpresetRegProfile0 = DnResetRfProfileX.bits_st.DnchirpresetRegProfile0 & 0x4000000u;
        /* With usedBW max = 6GHz, min RampTime = 1 and min ResetTime = 0.5, the max value of InputResetValue is 24 bits. So, range check is not required before this assignment  */
        // setting the Final DnReset value with drift
        DnResetRfProfileX.bits_st.DnchirpresetRegProfile0 |= DnReset;
        ErrCode = BC_SPI_WriteCheck(e_SYS_SC, (R2M05_DN_RESET_RF_PROFILE0_U16 + RegOffset), DnResetRfProfileX.val_u32);
    }
    return ErrCode;
}

static BC_ERRCODE ValidateConfProfParams(BC_FLOAT StartFreq, BC_FLOAT usedBW, float32_t RampTime, float32_t ResetTime)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    if ((StartFreq < SC_AUTO_RADAR_LOWER_END) || (StartFreq > SC_AUTO_RADAR_UPPER_END))
    {
        retVal = BC_ERR_SC_OPERATING_FREQ_OUTOFRANGE;
    }
    if (((usedBW < SC_AUTO_RADAR_USED_BW_LOW) || (usedBW > SC_AUTO_RADAR_USED_BW_HIGH)) && (BC_ERR_NOERROR == retVal))
    {
        retVal = BC_ERR_SC_USED_BW_OUTOFRANGE;
    }
    if (((RampTime < SC_AUTO_RADAR_RAMP_TIME_MIN) || (RampTime > SC_AUTO_RADAR_RAMP_TIME_MAX)) && (BC_ERR_NOERROR == retVal))
    {
        retVal = BC_ERR_SC_RAMP_TIME_OUTOFRANGE;
    }
    if (((ResetTime < SC_AUTO_RADAR_RESET_TIME_MIN) || (ResetTime > SC_AUTO_RADAR_RESET_TIME_MAX)) && (BC_ERR_NOERROR == retVal))
    {
        retVal = BC_ERR_SC_RESET_TIME_OUTOFRANGE;
    }
    return retVal;
}

BC_ERRCODE HAL_ES2_SC_SetZeroRamp(SYS_ProfID_e ProfileNum)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    uint16_t RegOffset;
    R2M05_DnChirpRfProfile0Union_t DnChirpRfProfileX;
    R2M05_DnResetRfProfile0Union_t DnResetRfProfileX;
    if (ProfileNum <= e_SYS_PROFILE_8)
    {
        RegOffset = 0x18u * (uint16_t)(ProfileNum);
        retVal = BC_SPI_Read(e_SYS_SC, (R2M05_DN_CHIRP_RF_PROFILE0_U16 + RegOffset), &DnChirpRfProfileX.val_u32);
        if (BC_ERR_NOERROR == retVal)
        {
            DnChirpRfProfileX.bits_st.DnchirpactiveRegProfile0 = 0u;
            retVal = BC_SPI_WriteCheck(e_SYS_SC, (R2M05_DN_CHIRP_RF_PROFILE0_U16 + RegOffset), DnChirpRfProfileX.val_u32);
        }
        if (BC_ERR_NOERROR == retVal)
        {
            retVal = BC_SPI_Read(e_SYS_SC, (R2M05_DN_RESET_RF_PROFILE0_U16 + RegOffset), &DnResetRfProfileX.val_u32);
        }
        if (BC_ERR_NOERROR == retVal)
        {
            DnResetRfProfileX.bits_st.DnchirpresetRegProfile0 = 0u;
            retVal = BC_SPI_WriteCheck(e_SYS_SC, (R2M05_DN_RESET_RF_PROFILE0_U16 + RegOffset), DnResetRfProfileX.val_u32);
        }
    }
    else
    {
        retVal = BC_ERR_SC_PROFILE;
    }
    return retVal;
}

BC_ERRCODE HAL_ES2_SC_ConfigProfile(SYS_ProfID_e ProfileNum, BC_FLOAT StartFreq, BC_FLOAT usedBW, float32_t RampTime, BOOL DownChirp, float32_t ResetTime)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    uint16_t RegOffset;
    R2M05_NStartRfProfile0Union_t NStartRfProfileX;
    R2M05_DnChirpRfProfile0Union_t DnChirpRfProfileX;
    R2M05_NStepChirpRfProfile0Union_t NStepChirpRfProfileX;
    R2M05_DnResetRfProfile0Union_t DnResetRfProfileX;
    R2M05_NStepResetRfProfile0Union_t NStepResetRfProfileX;

    float32_t StartDiv0 = 0.0f;
    float32_t NStart = 0.0f;
    float32_t NStartf = 0.0f;
    uint8_t NStart_int = 0u;
    uint32_t NStart_frac = 0u;

    float32_t StepsInChirp;
    uint32_t DnChirp;
    float32_t StepsInReset;
    uint32_t DnReset;
    BC_FLOAT TempDiv;
    retVal = ValidateConfProfParams(StartFreq, usedBW, RampTime, ResetTime);
    if (BC_ERR_NOERROR == retVal)
    {
        if (ProfileNum <= e_SYS_PROFILE_8)
        { /*Note: No expilict checks on other input parameters, which will be done at sys API level */

            RegOffset = (uint16_t)ProfileNum * 0x18u; /*This offset can be used wrt profile 0 registers*/

            /* NStart's integer and fractional parts computation */
            TempDiv = StartFreq / (BC_FLOAT)SC_FREQ_DIVIDER;
            StartDiv0 = (float32_t)TempDiv;
            NStartf = modff(StartDiv0, &NStart); /* modff breaks StartDiv0 into integral and fractional parts */
            NStart_int = (uint8_t)NStart;        /*Integer part, casting not harmful as fractional part is 0*/
            /*Converting fractional part into integer representation with Q26 format*/
            NStart_frac = (uint32_t)(roundf(NStartf * (float32_t)SC_ONE_LSH_26F));

            /*No read required as changing the entire register value*/
            NStartRfProfileX.bits_st.NstartintrfProfile0 = NStart_int;
            NStartRfProfileX.bits_st.NstartfracrfProfile0 = NStart_frac;
            retVal = BC_SPI_WriteCheck(e_SYS_SC, (R2M05_N_START_RF_PROFILE0_U16 + RegOffset), NStartRfProfileX.val_u32);

            if (BC_ERR_NOERROR == retVal)
            {
                /* N_step_chirp = acquisition_period in 40 MHz cycles * ((480MHz / divupdaterf_profile ) / Base clock in MHz)*/
                /* With base clock 40MHz N_step_chirp = (acquisition_period in us) * (480e6/divupdaterf_profile/1e6) */
                /* Note: No need to convert to 25ns base or 40MHz cycles */
                StepsInChirp = RampTime * SC_RAMPTIME_MULTIPLIER;

                NStepChirpRfProfileX.val_u32 = 0u; /*To avoid read of register*/
                NStepChirpRfProfileX.bits_st.NstepchirpactiveRegProfile0 = (uint32_t)lroundf(StepsInChirp) - 1u;
                retVal = BC_SPI_WriteCheck(e_SYS_SC, (R2M05_N_STEP_CHIRP_RF_PROFILE0_U16 + RegOffset), NStepChirpRfProfileX.val_u32);
            }

            if (BC_ERR_NOERROR == retVal)
            {
                StepsInReset = ResetTime * SC_RAMPTIME_MULTIPLIER;
                NStepResetRfProfileX.val_u32 = 0u; /*To avoid read of register*/
                NStepResetRfProfileX.bits_st.NstepchirpresetRegProfile0 = (uint32_t)lroundf(StepsInReset) - 1u;
                retVal = BC_SPI_WriteCheck(e_SYS_SC, (R2M05_N_STEP_RESET_RF_PROFILE0_U16 + RegOffset), NStepResetRfProfileX.val_u32);
            }

            if (BC_ERR_NOERROR == retVal)
            {
                BC_FLOAT ChirpFreqStepSize64;
                float32_t TempValue;
                uint32_t StepsInChirpRounded = (uint32_t)lroundf(StepsInChirp);
                ChirpFreqStepSize64 = (usedBW * SC_FREQ2DIV);
                TempValue = (float32_t)ChirpFreqStepSize64;
                TempValue = TempValue / (float32_t)StepsInChirpRounded;
                DnChirp = (uint32_t)lroundf(TempValue);
                DnChirpRfProfileX.val_u32 = 0u;
                DnChirpRfProfileX.bits_st.DnchirpactiveRegProfile0 = DnChirp;
                if (TRUE == DownChirp)
                {
                    DnChirpRfProfileX.bits_st.DnchirpactiveRegProfile0 |= ((uint32_t)1u << 26u);
                }
                retVal = BC_SPI_WriteCheck(e_SYS_SC, (R2M05_DN_CHIRP_RF_PROFILE0_U16 + RegOffset), DnChirpRfProfileX.val_u32);
            }
            if (BC_ERR_NOERROR == retVal)
            {
                float32_t ResetDIVStepSize;
                uint32_t StepsInResetRounded = (uint32_t)lroundf(StepsInReset);
                uint32_t StepsInChirpRounded = (uint32_t)lroundf(StepsInChirp);
                ResetDIVStepSize = ((float32_t)DnChirp * (float32_t)StepsInChirpRounded) / (float32_t)StepsInResetRounded;
                DnReset = (uint32_t)lroundf(ResetDIVStepSize);
                DnResetRfProfileX.val_u32 = 0u;
                /* With usedBW max = 6GHz, min RampTime = 1 and min ResetTime = 0.5, the max value of DnReset is 24 bits. So, range check is not required before this assignment  */
                DnResetRfProfileX.bits_st.DnchirpresetRegProfile0 = DnReset;
                if (FALSE == DownChirp)
                {
                    DnResetRfProfileX.bits_st.DnchirpresetRegProfile0 |= ((uint32_t)1u << 26u);
                }
                retVal = BC_SPI_WriteCheck(e_SYS_SC, (R2M05_DN_RESET_RF_PROFILE0_U16 + RegOffset), DnResetRfProfileX.val_u32);
            }
        }
        else
        {
            retVal = BC_ERR_SC_PROFILE;
        }
    }
    return retVal;
}
BC_ERRCODE HAL_ES2_SC_SetSweepCtrlMode(BOOL ChirpType, BOOL SweepRstCtrl)
{
    R2M05_ChirpModeUnion_t SCChirpMode;
    BC_ERRCODE retVal;

    retVal = BC_SPI_Read(e_SYS_SC, R2M05_CHIRP_MODE_U16, &SCChirpMode.val_u32);
    if (BC_ERR_NOERROR == retVal)
    {
        SCChirpMode.bits_st.DonotLoadAccumulatorBetweenChirp = (uint8_t)ChirpType; /* True: Progressive; FALSE:  Non-progressive */
        SCChirpMode.bits_st.SweepControlMode = (uint8_t)SweepRstCtrl;              /* False : Chirp reset follows TE ; True: chirp reset follows SC */
        retVal = BC_SPI_WriteCheck(e_SYS_SC, R2M05_CHIRP_MODE_U16, SCChirpMode.val_u32);
    }
    return retVal;
}

BC_ERRCODE HAL_ES2_SC_ConfigSlowDriftChirp(SYS_ProfID_e ProfID, BC_FLOAT FreqDriftHz, float32_t TReset, BC_FLOAT InputBWFullRamp)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    if (ProfID > e_SYS_PROFILE_8)
    {
        ErrCode = BC_ERR_SC_PROFILE;
    }
    if (((TReset < SC_AUTO_RADAR_RESET_TIME_MIN) || (TReset > SC_AUTO_RADAR_RESET_TIME_MAX)) && ((BC_ERR_NOERROR == ErrCode)))
    {
        ErrCode = BC_ERR_SC_RESET_TIME_OUTOFRANGE;
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = Helper_SC_ConfigSlowDriftChirp(ProfID, FreqDriftHz, TReset, InputBWFullRamp);
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_SC_ConfigAAFCFc(SYS_CAFCTXCalFreqMode_e CAFCTXCalMode, BC_FLOAT Fc)
{
    /*
    In SC, the following bits in N_START_RF_CAL_CENTER_FREQ_SEL are important for AAFC search

    A: cal_frequency_chirp_tx_sel: main frequency mode selection for AAFC/TX calibration
    B: cal_frequency_chirp_tx_calc_mode
    C: tx_cal_open_close_loop_sel: control CAFC PLL loop mode for TX PR calibration. 0:open loop, 1:close loop

    Note: AAFC is always done in open loop mode.
    Note: MDes is only used in AAFC calibration, this field is in CAFC.

    Recommended setting table

    |A   |B   |C   |Description|
    |--- |--- |--- |
    |00  |0   |1   |fstart for AAFC, fstart for TX; AAFC open, TX PR closed loop; fstart is specified by N_START_RF_PROFILEx, MDes must be programmed manually by user in CAFC |
    |01  |0   |1   |fcenter for AAFC, fcenter for TX; AAFC open, TX PR closed loop; fcenter is specified by N_START_RF_CAL_CENTER_FREQ (divider value), MDes must be programmed manually by user in CAFC. |
    |10  |0   |1   |fstart for AAFC, fcenter for TX; AAFC open, TX PR closed loop; fstart (for CAFC cal) is specified by N_START_RF_PROFILEx (divider value), MDes must be programmed manually by user in CAFC. fcenter(for TX cal use only) is specified by N_START_RF_CAL_CENTER_FREQ (divider value). |
    |00  |1   |1   |fstart for AAFC, fstart for TX; AAFC open, TX PR closed loop; fstart is specified by N_START_RF_PROFILEx (divdier value), MDes is calculated by HW automatically |
    |01  |1   |1   |fcenter for AAFC, fcenter for TX; AAFC open, TX PR closed loop; fcenter is specified by automatic HW calculation, using N_START_RF_PROFILEx, DN_CHIRP and N_STEP_CHIRP. MDes is also calculated by fcenter result. |
    |10  |1   |1   |fstart for AAFC, fcenter for TX; AAFC open, TXPR closed loop; fstart (for CAFC cal) is specified by N_START_RF_PROFILEx (divier value), MDes is calculated by HW. fcenter (for TX cal) is specified by automatic HW calculation, using N_START_RF_PROFILEx, DN_CHIRP and N_STEP_CHIRP.|

    */

    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    R2M05_NStartRfCalCenterFreqSelUnion_t NStartRFCalCenterFSel;
    R2M05_NStartRfCalCenterFreqUnion_t NStartRFCalCenterF;

    ErrCode = BC_SPI_Read(e_SYS_SC, R2M05_N_START_RF_CAL_CENTER_FREQ_SEL_U16, &NStartRFCalCenterFSel.val_u32);

    if (BC_ERR_NOERROR == ErrCode)
    {
        // judege on modes
        switch (CAFCTXCalMode)
        {
        case e_SYS_CAFCTX_FS_CLOSE_MAN:
            NStartRFCalCenterFSel.bits_st.CalFrequencyChirpTxSel = 0u;
            NStartRFCalCenterFSel.bits_st.CalFrequencyChirpTxCalcMode = 0u;
            NStartRFCalCenterFSel.bits_st.TxCalOpenCloseLoopSel = 1u;
            break;
        case e_SYS_CAFCTX_FC_CLOSE_MAN:
            NStartRFCalCenterFSel.bits_st.CalFrequencyChirpTxSel = 1u;
            NStartRFCalCenterFSel.bits_st.CalFrequencyChirpTxCalcMode = 0u;
            NStartRFCalCenterFSel.bits_st.TxCalOpenCloseLoopSel = 1u;
            break;
        case e_SYS_CAFCFS_TXFC_CLOSE_MAN:
            NStartRFCalCenterFSel.bits_st.CalFrequencyChirpTxSel = 2u;
            NStartRFCalCenterFSel.bits_st.CalFrequencyChirpTxCalcMode = 0u;
            NStartRFCalCenterFSel.bits_st.TxCalOpenCloseLoopSel = 1u;
            break;
        case e_SYS_CAFCTX_FS_CLOSE_AUTO:
            NStartRFCalCenterFSel.bits_st.CalFrequencyChirpTxSel = 0u;
            NStartRFCalCenterFSel.bits_st.CalFrequencyChirpTxCalcMode = 1u;
            NStartRFCalCenterFSel.bits_st.TxCalOpenCloseLoopSel = 1u;
            break;
        case e_SYS_CAFCTX_FC_CLOSE_AUTO:
            NStartRFCalCenterFSel.bits_st.CalFrequencyChirpTxSel = 1u;
            NStartRFCalCenterFSel.bits_st.CalFrequencyChirpTxCalcMode = 1u;
            NStartRFCalCenterFSel.bits_st.TxCalOpenCloseLoopSel = 1u;
            break;
        case e_SYS_CAFCFS_TXFC_CLOSE_AUTO:
            NStartRFCalCenterFSel.bits_st.CalFrequencyChirpTxSel = 2u;
            NStartRFCalCenterFSel.bits_st.CalFrequencyChirpTxCalcMode = 1u;
            NStartRFCalCenterFSel.bits_st.TxCalOpenCloseLoopSel = 1u;
            break;
        default:
            ErrCode = BC_ERR_INPUTOUTOFRANGE;
            break;
        }
        if (BC_ERR_NOERROR == ErrCode)
        { // write settings
            ErrCode = BC_SPI_WriteCheck(e_SYS_SC, R2M05_N_START_RF_CAL_CENTER_FREQ_SEL_U16, NStartRFCalCenterFSel.val_u32);
        }
    }

    if (BC_ERR_NOERROR == ErrCode)
    {
        // if use cetner freq (both or partially) and user wants to calculate center frequency by himself
        if ((CAFCTXCalMode == e_SYS_CAFCTX_FC_CLOSE_MAN) || (CAFCTXCalMode == e_SYS_CAFCFS_TXFC_CLOSE_MAN))
        {
            // Fc range is relaxed.
            if ((Fc > 70e9) && (Fc < 85e9))
            {
                /* NStart's integer and fractional parts computation */
                BC_FLOAT StartDiv64 = Fc / (BC_FLOAT)SC_FREQ_DIVIDER;
                float32_t StartDiv = (float32_t)StartDiv64;
                float32_t NStart = 0.0f;
                float32_t NStartf = modff(StartDiv, &NStart); /* modff breaks StartDiv0 into integral and fractional parts */
                uint8_t NStart_int = (uint8_t)NStart;         /*Integer part, casting not harmful as fractional part is 0*/
                /*Converting fractional part into integer representation with Q26 format*/
                uint32_t NStart_frac = (uint32_t)(roundf(NStartf * (float32_t)SC_ONE_LSH_26F));

                // write user wanted Fc to this special purpose register only for Fc usecase
                ErrCode = BC_SPI_Read(e_SYS_SC, R2M05_N_START_RF_CAL_CENTER_FREQ_U16, &NStartRFCalCenterF.val_u32);
                NStartRFCalCenterF.bits_st.NstartintrfCalCenterFrequency = NStart_int;
                NStartRFCalCenterF.bits_st.NstartfracrfCalCenterFrequency = NStart_frac;

                if (BC_ERR_NOERROR == ErrCode)
                {
                    ErrCode = BC_SPI_WriteCheck(e_SYS_SC, R2M05_N_START_RF_CAL_CENTER_FREQ_U16, NStartRFCalCenterF.val_u32);
                }
            }
            else
            {
                ErrCode = BC_ERR_INPUTOUTOFRANGE;
            }
        }
    }

    return ErrCode;
}

BC_ERRCODE HAL_ES2_SC_KeepMiddleFrequency(BOOL KeepMidFreq)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M05_NStartRfCalCenterFreqSelUnion_t NStartRfCalCenterFreqSel;
    // Keep middle frequency as CW mode for calibration
    ErrCode = BC_SPI_Read(e_SYS_SC, R2M05_N_START_RF_CAL_CENTER_FREQ_SEL_U16, &NStartRfCalCenterFreqSel.val_u32);
    if (ErrCode == BC_ERR_NOERROR)
    {
        NStartRfCalCenterFreqSel.bits_st.KeepMiddleFrequencyInCwMode = KeepMidFreq;
        ErrCode = BC_SPI_Write(e_SYS_SC, R2M05_N_START_RF_CAL_CENTER_FREQ_SEL_U16, NStartRfCalCenterFreqSel.val_u32);
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_SC_EnDivHardFuncReset(BOOL EnDivRstFrame, BOOL EnDivRstChirp, BOOL EnHardFuncRstFrame, BOOL EnHardFuncRstChirp)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M05_SweepDivRstControlUnion_t SweepDivRstControl;
    R2M06_AdditionalHwSettingsUnion_t HwSettings;

    ErrCode = BC_SPI_Read(e_SYS_SC, R2M05_SWEEP_DIV_RST_CONTROL_U16, &SweepDivRstControl.val_u32);
    if (ErrCode == BC_ERR_NOERROR)
    {
        SweepDivRstControl.bits_st.SweepDivRstEnableFrame = EnDivRstFrame;
        SweepDivRstControl.bits_st.SweepDivRstEnableChirp = EnDivRstChirp;
        ErrCode = BC_SPI_Write(e_SYS_SC, R2M05_SWEEP_DIV_RST_CONTROL_U16, SweepDivRstControl.val_u32);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_ADDITIONAL_HW_SETTINGS_U16, &HwSettings.val_u32);
        if (ErrCode == BC_ERR_NOERROR)
        {
            HwSettings.bits_st.EnableHardFuncResetPerFrame = EnHardFuncRstFrame;
            HwSettings.bits_st.EnableHardFuncResetPerChirp = EnHardFuncRstChirp;
            ErrCode = BC_SPI_Write(e_SYS_CAFC, R2M06_ADDITIONAL_HW_SETTINGS_U16, HwSettings.val_u32);
        }
    }

    return ErrCode;
}

BC_ERRCODE HAL_ES2_SC_ConfigDitherCtrl(SC_DitherControl_t *pDitherControl)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M05_DitherControlUnion_t DitherControl;
    if (pDitherControl != NULL)
    {
        if (!((pDitherControl->StepSizeStartFreqDither < 0x2000u) && (pDitherControl->StartFreqDitherAccuIncr < 0x20u)))
        {
            ErrCode = BC_ERR_INPUTOUTOFRANGE;
        }
    }
    else
    {
        ErrCode = BC_ERR_SC_PTR_ADDR_NULL;
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        DitherControl.val_u32 = 0u;
        DitherControl.bits_st.DwellDitherEnable = pDitherControl->EnDwellDither;
        DitherControl.bits_st.FractionalDelayEnable = pDitherControl->EnFractionalDelay;
        DitherControl.bits_st.NumberOfLevelsDwellDither = (uint8_t)pDitherControl->NumLevelsDwellDither;
        DitherControl.bits_st.NumberOfLevelsStartFreqDither = (uint8_t)pDitherControl->NumLevelsStartFreqDither;
        DitherControl.bits_st.StartFreqDitherAccuIncr = pDitherControl->StartFreqDitherAccuIncr;
        DitherControl.bits_st.StartFreqDitherEnable = pDitherControl->EnStartFreqDither;
        DitherControl.bits_st.StartFreqDitherMode = (uint8_t)pDitherControl->StartFreqDitherMode;
        DitherControl.bits_st.StepSizeForStartFreqDither = pDitherControl->StepSizeStartFreqDither;
        ErrCode = BC_SPI_WriteCheck(e_SYS_SC, R2M05_DITHER_CONTROL_U16, DitherControl.val_u32);
    }
    return ErrCode;
}

#endif
