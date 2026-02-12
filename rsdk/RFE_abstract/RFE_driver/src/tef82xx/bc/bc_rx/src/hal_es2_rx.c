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
#include <stdint.h>
#include <math.h>

#include "bc_types.h"
#include "bc_err.h"
#include "bc_conf.h"
#include "bc_spi.h"
#include "plf.h"
#include "bc_ism.h"
#include "hal_es2_rx.h"
#include "hal_es2_otp.h"

// Register header
#ifdef BUILD_FOR_VAL
#include "v_es2_rx.h"
#else
#include "reg_es2_rx.h"
#endif

static uint8_t gLox3GainCalTargetOffset[4] = {0u, 0u, 0u, 0u};
static BC_ERRCODE Helper_ES2_RxSetEnRMSDetMC(BOOL EnRMSDet);
static BC_ERRCODE Helper_ES2_ReadRxCalibStatus(SYS_IPNum_e RXIP);
static BC_ERRCODE Helper_ES2_CheckInputRange(SYS_IPNum_e RXNum, SYS_ProfID_e ProfileNum, RX_ConfigProfile_t *pConfigProfile);
static BC_ERRCODE Helper_ES2_CalRxCalibStatus(SYS_IPNum_e RXIP);
static BC_ERRCODE Helper_ES2_CalRxMCCalibStatus(uint8_t *pCalStatusBusy, uint32_t *pCalStatusError);
static BC_ERRCODE Helper_ES2_LOLwLvlThRangeChck(SYS_IPNum_e RXNum, CAFC_VCOBWSel_e VCOSel);
static BC_ERRCODE Helper_ES2_RXGetFunSafeSettings(SYS_IPNum_e RXNum, uint32_t *pFuncSafeMonLvlSettings, uint32_t *pLox3GainControl);
static BC_ERRCODE Helper_ES2_GetFunSafeLox3GainCtl(SYS_IPNum_e RXNum, uint32_t *pRx1FuncSafeMonLvlSettings, uint32_t *pRx1Lox3GainControl, uint32_t *pRx2FuncSafeMonLvlSettings, uint32_t *pRx2Lox3GainControl, uint32_t *pRx3FuncSafeMonLvlSettings, uint32_t *pRx3Lox3GainControl, uint32_t *pRx4FuncSafeMonLvlSettings, uint32_t *pRx4Lox3GainControl);
static BC_ERRCODE Helper_ES2_SetLoLowLevel(SYS_IPNum_e RXNum, CAFC_VCOBWSel_e VCOSel, BC_FLOAT InputFrequency, uint32_t FuncSafeMonLvlSettingsVal32);
static BC_ERRCODE Helper_ES2_SetLox3GainTargetOffset(SYS_IPNum_e RXNum, CAFC_VCOBWSel_e VCOSel, BC_FLOAT InputFrequency, uint32_t Lox3GainControlVal32);
static BC_ERRCODE Helper_ES2_LOLwLvlThRangeChck(SYS_IPNum_e RXNum, CAFC_VCOBWSel_e VCOSel);
static BOOL Helper_ES2_ChecKAllRXVal(uint32_t Rx1Val, uint32_t Rx2Val, uint32_t Rx3Val, uint32_t Rx4Val);
static BC_ERRCODE Helper_ES2_SetRxLoLowLvl(CAFC_VCOBWSel_e VCOSel, BC_FLOAT InputFrequency, uint32_t Rx1Val, uint32_t Rx2Val, uint32_t Rx3Val, uint32_t Rx4Val);
static BC_ERRCODE Helper_ES2_SetRxLox3GainTrgtOfst(CAFC_VCOBWSel_e VCOSel, BC_FLOAT InputFrequency, uint32_t Rx1Val, uint32_t Rx2Val, uint32_t Rx3Val, uint32_t Rx4Val);
static BC_ERRCODE Helper_ES2_SetLOLowLevelTh(SYS_IPNum_e RXNum, CAFC_VCOBWSel_e VCOSel, BC_FLOAT InputFrequency, uint32_t Rx1FuncSafeMonLvlSettings, uint32_t Rx1Lox3GainControl, uint32_t Rx2FuncSafeMonLvlSettings, uint32_t Rx2Lox3GainControl, uint32_t Rx3FuncSafeMonLvlSettings, uint32_t Rx3Lox3GainControl, uint32_t Rx4FuncSafeMonLvlSettings, uint32_t Rx4Lox3GainControl);
static BC_ERRCODE Helper_SetRXLOx3CaliGainSource(SYS_IPNum_e RXIP, RX_LOx3_GainSelect_e Lox3GainSource);
static BC_ERRCODE Helper_RxCalibLOx3GainCheckRange(SYS_IPNum_e RXIP, uint32_t CalCheckTimeOutUs, uint32_t *pDefaultCalCheckTimeOutUs);

BC_ERRCODE HAL_ES2_RX_ConfigLOx3Gain(SYS_IPNum_e RXIP, RX_LOx3_GainSelect_e GainSelect, uint8_t GainCode, BOOL BinSearchFromAbove, uint8_t CalTargetOffset)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M0D_Lox3GainControlUnion_t Lox3GainControl;
    R2M0D_Lox3GainCalControlUnion_t Lox3GainCalControl;

    if ((((RXIP >= e_SYS_RX1) && (RXIP <= e_SYS_RX4)) || (RXIP == e_SYS_RXMC)) && (GainSelect < e_RX_LOx3_INVALID) && (GainCode < 0x20u) && (CalTargetOffset <= RX_LOX3_CAL_TARGET_OFFSET_MAX))
    {
        Lox3GainControl.val_u32 = 0u;
        Lox3GainControl.bits_st.Lox3GainCalRoundMode = 0u; // reset value
        Lox3GainControl.bits_st.Lox3GainSource = (uint8_t)GainSelect;
        if (GainSelect == e_RX_LOx3_CAL)
        {
            // storing the value for calibration API
            gLox3GainCalTargetOffset[gTargetDevice] = CalTargetOffset;
            Lox3GainControl.bits_st.Lox3GainCalTargetOffset = CalTargetOffset;
            // write BinSearchFromAbove considering the case of common LOx3 gain from LO
            Lox3GainCalControl.val_u32 = 0u;
            Lox3GainCalControl.bits_st.RxDetCntThreshold = 0x50u; // reset value
            Lox3GainCalControl.bits_st.RxMonCntThreshold = 0x4u;  // reset value
            Lox3GainCalControl.bits_st.BinSearchFromAbove = (uint8_t)BinSearchFromAbove;
            ErrCode = BC_SPI_Write(RXIP, R2M0D_LOX3_GAIN_CAL_CONTROL_U16, Lox3GainCalControl.val_u32);
        }

        if (GainSelect == e_RX_LOx3_CTRLREG)
        {
            Lox3GainControl.bits_st.Lox3GainCtrl = GainCode;
        }
        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = BC_SPI_Write(RXIP, R2M0D_LOX3_GAIN_CONTROL_U16, Lox3GainControl.val_u32);
        }
    }
    else
    {
        ErrCode = BC_ERR_RX_INPUTOUTOFRANGE;
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_RX_CalibrateLOx3Gain(SYS_IPNum_e RXIP, BOOL ReadCalibStatus, uint32_t CalCheckTimeOutUs)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M0D_Lox3GainCalTriggerUnion_t Lox3GainCalTrigger;
    uint32_t DefaultCalCheckTimeOutUs = RX_LOX3_CALIBRATION_TIMEOUT;
    BOOL GainSourceChanged = FALSE;

    ErrCode = Helper_RxCalibLOx3GainCheckRange(RXIP, CalCheckTimeOutUs, &DefaultCalCheckTimeOutUs);

    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = Helper_SetRXLOx3CaliGainSource(RXIP, e_RX_LOx3_CAL);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        GainSourceChanged = TRUE;
        Lox3GainCalTrigger.val_u32 = 0u; /*To set unused bits to 0*/
        Lox3GainCalTrigger.bits_st.Lox3GainCalStart = 1u;
        ErrCode = BC_SPI_Write(RXIP, R2M0D_LOX3_GAIN_CAL_TRIGGER_U16, Lox3GainCalTrigger.val_u32);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = PLF_TM_Sleep(DefaultCalCheckTimeOutUs);
    }
    if ((ReadCalibStatus == TRUE) && (ErrCode == BC_ERR_NOERROR))
    {
        ErrCode = Helper_ES2_ReadRxCalibStatus(RXIP);
    }
    if (GainSourceChanged == TRUE)
    {
        // even in case of error also we should change the gain source to common
        (void)Helper_SetRXLOx3CaliGainSource(RXIP, e_RX_LOx3_COMMON);
    }
    return ErrCode;
}

static BC_ERRCODE Helper_ES2_CheckInputRange(SYS_IPNum_e RXNum, SYS_ProfID_e ProfileNum, RX_ConfigProfile_t *pConfigProfile)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    if (pConfigProfile == NULL)
    {
        ErrCode = BC_ERR_RX_PTR_ADDR_NULL;
    }
    else
    {
        if ((((RXNum > e_SYS_RX4) || (RXNum < e_SYS_RX1)) && (RXNum != e_SYS_RXMC)) ||
            (pConfigProfile->RXGain >= e_RX_GAIN_INVALID) || (pConfigProfile->HPFCutoffFreq >= e_SYS_RXHPF_INVALID) ||
            (pConfigProfile->LPFCutoffFreq >= e_SYS_RXLPF_INVALID) || (ProfileNum > e_SYS_PROFILE_8))
        {
            ErrCode = BC_ERR_INPUTOUTOFRANGE;
        }
    }

    return ErrCode;
}
BC_ERRCODE HAL_ES2_RX_ConfigProfile(SYS_IPNum_e RXNum, SYS_ProfID_e ProfileNum, RX_ConfigProfile_t *pConfigProfile)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    uint16_t SetRXProfileGain;
    uint16_t SetRXHPFFreq;
    uint16_t SetRXLPFFreq;

    R2M0D_GainRxSetProfile0Union_t GainRxSetProfile;
    R2M0D_HpfRxSetProfile0Union_t HpfRxSetProfile;
    R2M0D_LpfRxSetProfile0Union_t LpfRxSetProfile;

    ErrCode = Helper_ES2_CheckInputRange(RXNum, ProfileNum, pConfigProfile);

    if (ErrCode == BC_ERR_NOERROR)
    {
        SetRXProfileGain = R2M0D_GAIN_RX_SET_PROFILE0_U16 + (((uint16_t)ProfileNum - (uint16_t)e_SYS_PROFILE_0) * (R2M0D_GAIN_RX_SET_PROFILE1_U16 - R2M0D_GAIN_RX_SET_PROFILE0_U16));
        SetRXHPFFreq = R2M0D_HPF_RX_SET_PROFILE0_U16 + (((uint16_t)ProfileNum - (uint16_t)e_SYS_PROFILE_0) * (R2M0D_HPF_RX_SET_PROFILE1_U16 - R2M0D_HPF_RX_SET_PROFILE0_U16));
        SetRXLPFFreq = R2M0D_LPF_RX_SET_PROFILE0_U16 + (((uint16_t)ProfileNum - (uint16_t)e_SYS_PROFILE_0) * (R2M0D_LPF_RX_SET_PROFILE1_U16 - R2M0D_LPF_RX_SET_PROFILE0_U16));
        // Rx gain setting
        GainRxSetProfile.val_u32 = 0u;
        GainRxSetProfile.bits_st.GainRxSetCtrlProfile0 = (uint8_t)pConfigProfile->RXGain;
        ErrCode = BC_SPI_Write(RXNum, SetRXProfileGain, GainRxSetProfile.val_u32);

        // LPF filter setting
        if (ErrCode == BC_ERR_NOERROR)
        {
            LpfRxSetProfile.val_u32 = 0u;
            LpfRxSetProfile.bits_st.LpfRxSetCtrlProfile0 = (uint8_t)pConfigProfile->EnLPFWideBandMode;

            if (pConfigProfile->LPFCutoffFreq != e_SYS_RXLPF_WIDE)
            {
                // if wideband is enabled, this value is ignored
                LpfRxSetProfile.bits_st.LpfRxCornerSetProfile0 = (uint8_t)pConfigProfile->LPFCutoffFreq;
            }
            ErrCode = BC_SPI_Write(RXNum, SetRXLPFFreq, LpfRxSetProfile.val_u32);
        }

        // Hpf Setting
        if (ErrCode == BC_ERR_NOERROR)
        {

            HpfRxSetProfile.val_u32 = 0u;
            HpfRxSetProfile.bits_st.HpfRxSetCtrlProfile0 = (uint8_t)pConfigProfile->HPFCutoffFreq;
            ErrCode = BC_SPI_Write(RXNum, SetRXHPFFreq, HpfRxSetProfile.val_u32);
        }
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_RX_EnableRMSDet(BOOL EnRMSDet, SYS_IPNum_e RXNum)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    R2M0D_FuncsafeMonLevelSettingsEnableUnion_t FuncsafeMonLevelSettingsEnable;

    // select a Rx, if it is not one of the Rxes, report error
    if (((RXNum >= e_SYS_RX1) && (RXNum <= e_SYS_RX4)))
    {
        // Enable or Disable RMS detector
        FuncsafeMonLevelSettingsEnable.val_u32 = 0u;
        FuncsafeMonLevelSettingsEnable.bits_st.LevelLoEnSpi = (uint8_t)EnRMSDet;
        ErrCode = BC_SPI_WriteCheck(RXNum, R2M0D_FUNCSAFE_MON_LEVEL_SETTINGS_ENABLE_U16, FuncsafeMonLevelSettingsEnable.val_u32);
    }
    else if (e_SYS_RXMC == RXNum)
    {
        ErrCode = Helper_ES2_RxSetEnRMSDetMC(EnRMSDet);
    }
    else
    {
        ErrCode = BC_ERR_INPUTOUTOFRANGE;
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_RX_ConfigLocalCtrl(SYS_IPNum_e RXNum, BOOL EnRX, BOOL EnLNA)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    R2M0D_RxControlUnion_t RxControl;

    // select a Rx, if it is not one of the 4 Rxes, report error
    if (((RXNum < e_SYS_RX1) || (RXNum > e_SYS_RX4)) && (RXNum != e_SYS_RXMC))
    {
        ErrCode = BC_ERR_INPUTOUTOFRANGE;
    }

    if (ErrCode == BC_ERR_NOERROR)
    {
        RxControl.val_u32 = 0u;
        // Enable or disable RX and LNA
        RxControl.bits_st.PonLsSpi = 0;
        RxControl.bits_st.EnRxViaSpi = (uint8_t)EnRX;
        RxControl.bits_st.EnLnaViaSpi = (uint8_t)EnLNA;

        ErrCode = BC_SPI_Write(RXNum, R2M0D_RX_CONTROL_U16, RxControl.val_u32);
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_RX_ConnectRFBISTSignal(SYS_IPNum_e RXNum, RX_RFBIST_Input_e SelectInput)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M0D_RfbistControlUnion_t RfbistControl;

    // Input parameters in range check
    if ((((RXNum < e_SYS_RX1) || (RXNum > e_SYS_RX4)) && (RXNum != e_SYS_RXMC)) || (SelectInput >= e_RX_RFBIST_INPUT_INVALID))
    {
        ErrCode = BC_ERR_INPUTOUTOFRANGE;
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        // select the RFBIST signal input
        RfbistControl.val_u32 = 0u;
        RfbistControl.bits_st.SelRxBistInSpi = (uint8_t)SelectInput;
        ErrCode = BC_SPI_WriteCheck(RXNum, R2M0D_RFBIST_CONTROL_U16, RfbistControl.val_u32);
    }
    return ErrCode;
}

static BC_ERRCODE Helper_ES2_CalRxMCCalibStatus(uint8_t *pCalStatusBusy, uint32_t *pCalStatusError)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    SYS_CalibrationStatus_t CalibrationStatus;
    uint32_t tmpCalStatusError;

    ErrCode = BC_ISM_GetCalibrationStatus(&CalibrationStatus, NULL);
    if (ErrCode == BC_ERR_NOERROR)
    {
        *pCalStatusBusy = ((CalibrationStatus.Rx1CalStatus == e_ISM_CAL_BUSY) || (CalibrationStatus.Rx2CalStatus == e_ISM_CAL_BUSY) || (CalibrationStatus.Rx3CalStatus == e_ISM_CAL_BUSY) || (CalibrationStatus.Rx4CalStatus == e_ISM_CAL_BUSY)) ? 1u : 0u;
        tmpCalStatusError = (CalibrationStatus.Rx1CalStatus == e_ISM_CAL_ERROR) ? 1u : 0u;
        tmpCalStatusError = (CalibrationStatus.Rx2CalStatus == e_ISM_CAL_ERROR) ? (tmpCalStatusError + 2u) : tmpCalStatusError;
        tmpCalStatusError = (CalibrationStatus.Rx3CalStatus == e_ISM_CAL_ERROR) ? (tmpCalStatusError + 4u) : tmpCalStatusError;
        tmpCalStatusError = (CalibrationStatus.Rx4CalStatus == e_ISM_CAL_ERROR) ? (tmpCalStatusError + 8u) : tmpCalStatusError;
        *pCalStatusError = tmpCalStatusError;
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_CalRxCalibStatus(SYS_IPNum_e RXIP)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    SYS_CalibrationStatus_t CalibrationStatus;
    ISM_Cal_Status_e CalStatus = e_ISM_CAL_INVALID;

    ErrCode = BC_ISM_GetCalibrationStatus(&CalibrationStatus, NULL);
    if (ErrCode == BC_ERR_NOERROR)
    {
        if (RXIP == e_SYS_RX1)
        {
            CalStatus = CalibrationStatus.Rx1CalStatus;
        }
        if (RXIP == e_SYS_RX2)
        {
            CalStatus = CalibrationStatus.Rx2CalStatus;
        }
        if (RXIP == e_SYS_RX3)
        {
            CalStatus = CalibrationStatus.Rx3CalStatus;
        }
        if (RXIP == e_SYS_RX4)
        {
            CalStatus = CalibrationStatus.Rx4CalStatus;
        }
        if (CalStatus == e_ISM_CAL_BUSY)
        {
            ErrCode = BC_ERR_RX1_CAL_BUSY + ((uint32_t)RXIP - (uint32_t)e_SYS_RX1);
        }
        if (CalStatus == e_ISM_CAL_ERROR)
        {
            ErrCode = BC_ERR_RX_CAL_ERROR + ((uint32_t)1u << ((uint32_t)RXIP - (uint32_t)e_SYS_RX1));
        }
    }

    return ErrCode;
}
static BC_ERRCODE Helper_ES2_RxSetEnRMSDetMC(BOOL EnRMSDet)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M0D_FuncsafeMonLevelSettingsEnableUnion_t FuncsafeMonLevelSettingsEnable;
    uint32_t FuncSafeCtrlRX1 = 0u;
    uint32_t FuncSafeCtrlRX2 = 0u;
    uint32_t FuncSafeCtrlRX3 = 0u;
    uint32_t FuncSafeCtrlRX4 = 0u;
    // Enable or Disable RMS detector
    FuncsafeMonLevelSettingsEnable.val_u32 = 0u;
    FuncsafeMonLevelSettingsEnable.bits_st.LevelLoEnSpi = (uint8_t)EnRMSDet;
    ErrCode = BC_SPI_Write(e_SYS_RXMC, R2M0D_FUNCSAFE_MON_LEVEL_SETTINGS_ENABLE_U16, FuncsafeMonLevelSettingsEnable.val_u32);
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SPI_Read(e_SYS_RX1, R2M0D_FUNCSAFE_MON_LEVEL_SETTINGS_ENABLE_U16, &FuncSafeCtrlRX1);
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SPI_Read(e_SYS_RX2, R2M0D_FUNCSAFE_MON_LEVEL_SETTINGS_ENABLE_U16, &FuncSafeCtrlRX2);
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SPI_Read(e_SYS_RX3, R2M0D_FUNCSAFE_MON_LEVEL_SETTINGS_ENABLE_U16, &FuncSafeCtrlRX3);
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SPI_Read(e_SYS_RX4, R2M0D_FUNCSAFE_MON_LEVEL_SETTINGS_ENABLE_U16, &FuncSafeCtrlRX4);
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        uint8_t Count = 0u;
        if (FuncsafeMonLevelSettingsEnable.val_u32 != FuncSafeCtrlRX1)
        {
            Count = 1u;
        }
        if (FuncsafeMonLevelSettingsEnable.val_u32 != FuncSafeCtrlRX2)
        {
            Count = Count + 2u;
        }
        if (FuncsafeMonLevelSettingsEnable.val_u32 != FuncSafeCtrlRX3)
        {
            Count = Count + 4u;
        }
        if (FuncsafeMonLevelSettingsEnable.val_u32 != FuncSafeCtrlRX4)
        {
            Count = Count + 8u;
        }
        if (Count != 0u)
        {
            ErrCode = BC_ERR_RX_FUSA_ENABLE_WRITECHECK_BASE + (uint32_t)Count;
        }
    }
    return ErrCode;
}

static BC_ERRCODE Helper_ES2_ReadRxCalibStatus(SYS_IPNum_e RXIP)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    uint8_t CalStatusBusy;
    uint32_t CalStatusError;

    if (RXIP == e_SYS_RXMC)
    {
        ErrCode = Helper_ES2_CalRxMCCalibStatus(&CalStatusBusy, &CalStatusError);
        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = (uint32_t)((CalStatusBusy == TRUE) ? BC_ERR_RX_CAL_BUSY : ((CalStatusError > 0u) ? (BC_ERR_RX_CAL_ERROR + CalStatusError) : BC_ERR_NOERROR));
        }
    }
    else
    {
        ErrCode = Helper_ES2_CalRxCalibStatus(RXIP);
    }
    return ErrCode;
}

static BC_ERRCODE Helper_ES2_RXGetFunSafeSettings(SYS_IPNum_e RXNum, uint32_t *pFuncSafeMonLvlSettings, uint32_t *pLox3GainControl)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M0D_FuncsafeMonLevelSettingsUnion_t FuncsafeMonLevelSettings;
    uint32_t TrimRxThreshOTP = 0u;
    uint16_t TrimRxThreshOTPIndex = OTP_TRIM_RX1_THRESH_INDEX;
    uint32_t RxMaskLOMax;
    uint32_t RxLOMaxIndex = OTP_LEVEL_LO_MAX_SPI_RX1_INDEX;
    uint32_t RxMaskLOHigh;
    uint32_t RxLOHighIndex = OTP_LEVEL_LO_HIGH_SPI_RX1_INDEX;
    uint32_t RxMaskLOLow;
    uint32_t RxLOLowIndex = OTP_LEVEL_LO_LOW_SPI_RX1_INDEX;
    uint32_t RxMaskLOMin;
    uint32_t RxLOMinIndex = OTP_LEVEL_LO_MIN_SPI_RX1_INDEX;
    uint32_t RxPosLOMax;
    uint32_t RxPosLOHigh;
    uint32_t RxPosLOLow;
    uint32_t RxPosLOMin;
    if (RXNum == e_SYS_RX1)
    {
        TrimRxThreshOTPIndex = OTP_TRIM_RX1_THRESH_INDEX;
        RxLOMaxIndex = OTP_LEVEL_LO_MAX_SPI_RX1_INDEX;
        RxLOHighIndex = OTP_LEVEL_LO_HIGH_SPI_RX1_INDEX;
        RxLOLowIndex = OTP_LEVEL_LO_LOW_SPI_RX1_INDEX;
        RxLOMinIndex = OTP_LEVEL_LO_MIN_SPI_RX1_INDEX;
    }
    if (RXNum == e_SYS_RX2)
    {
        TrimRxThreshOTPIndex = OTP_TRIM_RX2_THRESH_INDEX;
        RxLOMaxIndex = OTP_LEVEL_LO_MAX_SPI_RX2_INDEX;
        RxLOHighIndex = OTP_LEVEL_LO_HIGH_SPI_RX2_INDEX;
        RxLOLowIndex = OTP_LEVEL_LO_LOW_SPI_RX2_INDEX;
        RxLOMinIndex = OTP_LEVEL_LO_MIN_SPI_RX2_INDEX;
    }
    if (RXNum == e_SYS_RX3)
    {
        TrimRxThreshOTPIndex = OTP_TRIM_RX3_THRESH_INDEX;
        RxLOMaxIndex = OTP_LEVEL_LO_MAX_SPI_RX3_INDEX;
        RxLOHighIndex = OTP_LEVEL_LO_HIGH_SPI_RX3_INDEX;
        RxLOLowIndex = OTP_LEVEL_LO_LOW_SPI_RX3_INDEX;
        RxLOMinIndex = OTP_LEVEL_LO_MIN_SPI_RX3_INDEX;
    }
    if (RXNum == e_SYS_RX4)
    {
        TrimRxThreshOTPIndex = OTP_TRIM_RX4_THRESH_INDEX;
        RxLOMaxIndex = OTP_LEVEL_LO_MAX_SPI_RX4_INDEX;
        RxLOHighIndex = OTP_LEVEL_LO_HIGH_SPI_RX4_INDEX;
        RxLOLowIndex = OTP_LEVEL_LO_LOW_SPI_RX4_INDEX;
        RxLOMinIndex = OTP_LEVEL_LO_MIN_SPI_RX4_INDEX;
    }
    ErrCode = HAL_ES2_OTP_GetOTPRegValue(TrimRxThreshOTPIndex, &TrimRxThreshOTP);
    if (ErrCode == BC_ERR_NOERROR)
    {
        RxMaskLOMax = OtpTrimRx1Thresh[RxLOMaxIndex].SrcMsk;
        RxMaskLOHigh = OtpTrimRx1Thresh[RxLOHighIndex].SrcMsk;
        RxMaskLOLow = OtpTrimRx1Thresh[RxLOLowIndex].SrcMsk;
        RxMaskLOMin = OtpTrimRx1Thresh[RxLOMinIndex].SrcMsk;
        RxPosLOMax = OtpTrimRx1Thresh[RxLOMaxIndex].SrcPos;
        RxPosLOHigh = OtpTrimRx1Thresh[RxLOHighIndex].SrcPos;
        RxPosLOLow = OtpTrimRx1Thresh[RxLOLowIndex].SrcPos;
        RxPosLOMin = OtpTrimRx1Thresh[RxLOMinIndex].SrcPos;
        FuncsafeMonLevelSettings.val_u32 = 0u;
        FuncsafeMonLevelSettings.bits_st.LevelLoMaxSpi = (uint8_t)((TrimRxThreshOTP & RxMaskLOMax) >> RxPosLOMax);
        FuncsafeMonLevelSettings.bits_st.LevelLoHighSpi = (uint8_t)((TrimRxThreshOTP & RxMaskLOHigh) >> RxPosLOHigh);
        FuncsafeMonLevelSettings.bits_st.LevelLoLowSpi = (uint8_t)((TrimRxThreshOTP & RxMaskLOLow) >> RxPosLOLow);
        FuncsafeMonLevelSettings.bits_st.LevelLoMinSpi = (uint8_t)((TrimRxThreshOTP & RxMaskLOMin) >> RxPosLOMin);
        *pFuncSafeMonLvlSettings = FuncsafeMonLevelSettings.val_u32;
        ErrCode = BC_SPI_Read(RXNum, R2M0D_LOX3_GAIN_CONTROL_U16, pLox3GainControl);
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_SetLoLowLevel(SYS_IPNum_e RXNum, CAFC_VCOBWSel_e VCOSel, BC_FLOAT InputFrequency, uint32_t FuncSafeMonLvlSettingsVal32)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M0D_FuncsafeMonLevelSettingsUnion_t FuncsafeMonLevelSettings;
    uint8_t ReduceFactor = 0u;
    FuncsafeMonLevelSettings.val_u32 = FuncSafeMonLvlSettingsVal32;
    if ((VCOSel == e_CAFC_1GBAND) && (InputFrequency >= RX_CENTER_FREQ_LIMIT))
    {
        ReduceFactor = 2u;
    }
    if (VCOSel == e_CAFC_5GNARROW)
    {
        ReduceFactor = 4u;
    }
    if (VCOSel == e_CAFC_5GWIDE)
    {
        ReduceFactor = 6u;
    }
    if (FuncsafeMonLevelSettings.bits_st.LevelLoLowSpi >= ReduceFactor)
    {
        FuncsafeMonLevelSettings.bits_st.LevelLoLowSpi = (uint8_t)(FuncsafeMonLevelSettings.bits_st.LevelLoLowSpi - ReduceFactor);
    }
    else
    {
        FuncsafeMonLevelSettings.bits_st.LevelLoLowSpi = 0u;
    }

    ErrCode = BC_SPI_Write(RXNum, R2M0D_FUNCSAFE_MON_LEVEL_SETTINGS_U16, FuncsafeMonLevelSettings.val_u32);

    return ErrCode;
}
static BC_ERRCODE Helper_ES2_SetLox3GainTargetOffset(SYS_IPNum_e RXNum, CAFC_VCOBWSel_e VCOSel, BC_FLOAT InputFrequency, uint32_t Lox3GainControlVal32)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M0D_Lox3GainControlUnion_t Lox3GainControl;
    Lox3GainControl.val_u32 = Lox3GainControlVal32;
    Lox3GainControl.bits_st.Lox3GainCalTargetOffset = 0u;
    if ((VCOSel == e_CAFC_1GBAND) && (InputFrequency >= RX_CENTER_FREQ_LIMIT))
    {
        Lox3GainControl.bits_st.Lox3GainCalTargetOffset = 1u;
    }
    if (VCOSel == e_CAFC_5GNARROW)
    {
        Lox3GainControl.bits_st.Lox3GainCalTargetOffset = 2u;
    }
    if (VCOSel == e_CAFC_5GWIDE)
    {
        Lox3GainControl.bits_st.Lox3GainCalTargetOffset = 3u;
    }
    gLox3GainCalTargetOffset[gTargetDevice] = Lox3GainControl.bits_st.Lox3GainCalTargetOffset;
    ErrCode = BC_SPI_Write(RXNum, R2M0D_LOX3_GAIN_CONTROL_U16, Lox3GainControl.val_u32);

    return ErrCode;
}
static BC_ERRCODE Helper_ES2_LOLwLvlThRangeChck(SYS_IPNum_e RXNum, CAFC_VCOBWSel_e VCOSel)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    // select a Rx, if it is not one of the 4 Rxes, report error
    if ((((RXNum < e_SYS_RX1) || (RXNum > e_SYS_RX4)) && (RXNum != e_SYS_RXMC)) || (VCOSel >= e_CAFC_VCOBWSEL_INVALID))
    {
        ErrCode = BC_ERR_INPUTOUTOFRANGE;
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_GetFunSafeLox3GainCtl(SYS_IPNum_e RXNum, uint32_t *pRx1FuncSafeMonLvlSettings, uint32_t *pRx1Lox3GainControl, uint32_t *pRx2FuncSafeMonLvlSettings, uint32_t *pRx2Lox3GainControl, uint32_t *pRx3FuncSafeMonLvlSettings, uint32_t *pRx3Lox3GainControl, uint32_t *pRx4FuncSafeMonLvlSettings, uint32_t *pRx4Lox3GainControl)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    if (RXNum == e_SYS_RXMC)
    {
        ErrCode = Helper_ES2_RXGetFunSafeSettings(e_SYS_RX1, pRx1FuncSafeMonLvlSettings, pRx1Lox3GainControl);

        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = Helper_ES2_RXGetFunSafeSettings(e_SYS_RX2, pRx2FuncSafeMonLvlSettings, pRx2Lox3GainControl);
        }
        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = Helper_ES2_RXGetFunSafeSettings(e_SYS_RX3, pRx3FuncSafeMonLvlSettings, pRx3Lox3GainControl);
        }
        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = Helper_ES2_RXGetFunSafeSettings(e_SYS_RX4, pRx4FuncSafeMonLvlSettings, pRx4Lox3GainControl);
        }
    }
    else
    {
        if (RXNum == e_SYS_RX1)
        {
            ErrCode = Helper_ES2_RXGetFunSafeSettings(e_SYS_RX1, pRx1FuncSafeMonLvlSettings, pRx1Lox3GainControl);
        }
        if (RXNum == e_SYS_RX2)
        {
            ErrCode = Helper_ES2_RXGetFunSafeSettings(e_SYS_RX2, pRx2FuncSafeMonLvlSettings, pRx2Lox3GainControl);
        }
        if (RXNum == e_SYS_RX3)
        {
            ErrCode = Helper_ES2_RXGetFunSafeSettings(e_SYS_RX3, pRx3FuncSafeMonLvlSettings, pRx3Lox3GainControl);
        }
        if (RXNum == e_SYS_RX4)
        {
            ErrCode = Helper_ES2_RXGetFunSafeSettings(e_SYS_RX4, pRx4FuncSafeMonLvlSettings, pRx4Lox3GainControl);
        }
    }
    return ErrCode;
}
static BOOL Helper_ES2_ChecKAllRXVal(uint32_t Rx1Val, uint32_t Rx2Val, uint32_t Rx3Val, uint32_t Rx4Val)
{
    BOOL SameFlag = FALSE;
    if ((Rx1Val == Rx2Val) && (Rx1Val == Rx3Val) && (Rx1Val == Rx4Val))
    {
        SameFlag = TRUE;
    }
    return SameFlag;
}
static BC_ERRCODE Helper_ES2_SetRxLoLowLvl(CAFC_VCOBWSel_e VCOSel, BC_FLOAT InputFrequency, uint32_t Rx1Val, uint32_t Rx2Val, uint32_t Rx3Val, uint32_t Rx4Val)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    ErrCode = Helper_ES2_SetLoLowLevel(e_SYS_RX1, VCOSel, InputFrequency, Rx1Val);
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = Helper_ES2_SetLoLowLevel(e_SYS_RX2, VCOSel, InputFrequency, Rx2Val);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = Helper_ES2_SetLoLowLevel(e_SYS_RX3, VCOSel, InputFrequency, Rx3Val);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = Helper_ES2_SetLoLowLevel(e_SYS_RX4, VCOSel, InputFrequency, Rx4Val);
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_SetRxLox3GainTrgtOfst(CAFC_VCOBWSel_e VCOSel, BC_FLOAT InputFrequency, uint32_t Rx1Val, uint32_t Rx2Val, uint32_t Rx3Val, uint32_t Rx4Val)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    ErrCode = Helper_ES2_SetLox3GainTargetOffset(e_SYS_RX1, VCOSel, InputFrequency, Rx1Val);
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = Helper_ES2_SetLox3GainTargetOffset(e_SYS_RX2, VCOSel, InputFrequency, Rx2Val);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = Helper_ES2_SetLox3GainTargetOffset(e_SYS_RX3, VCOSel, InputFrequency, Rx3Val);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = Helper_ES2_SetLox3GainTargetOffset(e_SYS_RX4, VCOSel, InputFrequency, Rx4Val);
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_SetLOLowLevelTh(SYS_IPNum_e RXNum, CAFC_VCOBWSel_e VCOSel, BC_FLOAT InputFrequency, uint32_t Rx1FuncSafeMonLvlSettings, uint32_t Rx1Lox3GainControl, uint32_t Rx2FuncSafeMonLvlSettings, uint32_t Rx2Lox3GainControl, uint32_t Rx3FuncSafeMonLvlSettings, uint32_t Rx3Lox3GainControl, uint32_t Rx4FuncSafeMonLvlSettings, uint32_t Rx4Lox3GainControl)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    uint32_t FuncsafeMonLevelSettingsVal32 = 0u;
    uint32_t Lox3GainControlVal32 = 0u;
    if (RXNum == e_SYS_RX1)
    {
        FuncsafeMonLevelSettingsVal32 = Rx1FuncSafeMonLvlSettings;
        Lox3GainControlVal32 = Rx1Lox3GainControl;
    }
    if (RXNum == e_SYS_RX2)
    {
        FuncsafeMonLevelSettingsVal32 = Rx2FuncSafeMonLvlSettings;
        Lox3GainControlVal32 = Rx2Lox3GainControl;
    }
    if (RXNum == e_SYS_RX3)
    {
        FuncsafeMonLevelSettingsVal32 = Rx3FuncSafeMonLvlSettings;
        Lox3GainControlVal32 = Rx3Lox3GainControl;
    }
    if (RXNum == e_SYS_RX4)
    {
        FuncsafeMonLevelSettingsVal32 = Rx4FuncSafeMonLvlSettings;
        Lox3GainControlVal32 = Rx4Lox3GainControl;
    }
    ErrCode = Helper_ES2_SetLoLowLevel(RXNum, VCOSel, InputFrequency, FuncsafeMonLevelSettingsVal32);
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = Helper_ES2_SetLox3GainTargetOffset(RXNum, VCOSel, InputFrequency, Lox3GainControlVal32);
    }
    return ErrCode;
}
BC_ERRCODE HAL_ES2_RX_UpdateLOLowLevelTh(SYS_IPNum_e RXNum, CAFC_VCOBWSel_e VCOSel, BC_FLOAT InputFrequency)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    uint32_t Rx1Lox3GainControlVal32 = 0u;
    uint32_t Rx2Lox3GainControlVal32 = 0u;
    uint32_t Rx3Lox3GainControlVal32 = 0u;
    uint32_t Rx4Lox3GainControlVal32 = 0u;
    uint32_t Rx1FuncsafeMonLevelSettingsVal32 = 0u;
    uint32_t Rx2FuncsafeMonLevelSettingsVal32 = 0u;
    uint32_t Rx3FuncsafeMonLevelSettingsVal32 = 0u;
    uint32_t Rx4FuncsafeMonLevelSettingsVal32 = 0u;

    ErrCode = Helper_ES2_LOLwLvlThRangeChck(RXNum, VCOSel);

    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = Helper_ES2_GetFunSafeLox3GainCtl(RXNum, &Rx1FuncsafeMonLevelSettingsVal32, &Rx1Lox3GainControlVal32, &Rx2FuncsafeMonLevelSettingsVal32, &Rx2Lox3GainControlVal32, &Rx3FuncsafeMonLevelSettingsVal32, &Rx3Lox3GainControlVal32, &Rx4FuncsafeMonLevelSettingsVal32, &Rx4Lox3GainControlVal32);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {

        if (RXNum == e_SYS_RXMC)
        {
            if (Helper_ES2_ChecKAllRXVal(Rx1FuncsafeMonLevelSettingsVal32, Rx2FuncsafeMonLevelSettingsVal32, Rx3FuncsafeMonLevelSettingsVal32, Rx4FuncsafeMonLevelSettingsVal32) == TRUE)
            {
                ErrCode = Helper_ES2_SetLoLowLevel(e_SYS_RXMC, VCOSel, InputFrequency, Rx1FuncsafeMonLevelSettingsVal32);
            }
            else
            {
                ErrCode = Helper_ES2_SetRxLoLowLvl(VCOSel, InputFrequency, Rx1FuncsafeMonLevelSettingsVal32, Rx2FuncsafeMonLevelSettingsVal32, Rx3FuncsafeMonLevelSettingsVal32, Rx4FuncsafeMonLevelSettingsVal32);
            }
            if (ErrCode == BC_ERR_NOERROR)
            {
                if (Helper_ES2_ChecKAllRXVal(Rx1Lox3GainControlVal32, Rx2Lox3GainControlVal32, Rx3Lox3GainControlVal32, Rx4Lox3GainControlVal32) == TRUE)
                {
                    ErrCode = Helper_ES2_SetLox3GainTargetOffset(e_SYS_RXMC, VCOSel, InputFrequency, Rx1Lox3GainControlVal32);
                }
                else
                {
                    ErrCode = Helper_ES2_SetRxLox3GainTrgtOfst(VCOSel, InputFrequency, Rx1Lox3GainControlVal32, Rx2Lox3GainControlVal32, Rx3Lox3GainControlVal32, Rx4Lox3GainControlVal32);
                }
            }
        }
        else
        {
            ErrCode = Helper_ES2_SetLOLowLevelTh(RXNum, VCOSel, InputFrequency, Rx1FuncsafeMonLevelSettingsVal32, Rx1Lox3GainControlVal32, Rx2FuncsafeMonLevelSettingsVal32, Rx2Lox3GainControlVal32, Rx3FuncsafeMonLevelSettingsVal32, Rx3Lox3GainControlVal32, Rx4FuncsafeMonLevelSettingsVal32, Rx4Lox3GainControlVal32);
        }
    }

    return ErrCode;
}

BC_ERRCODE HAL_ES2_RX_ConfigBBD(SYS_IPNum_e RXIP, BOOL EnableBBDRX, BOOL NormalSensitivity, BOOL Grounded)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M0D_BbdControlUnion_t rxBbdCtl;
    uint32_t rx1BbdCtl = 0u;
    uint32_t rx2BbdCtl = 0u;
    uint32_t rx3BbdCtl = 0u;
    uint32_t rx4BbdCtl = 0u;

    rxBbdCtl.val_u32 = 0u;
    rxBbdCtl.bits_st.BbEnSpi = EnableBBDRX;
    rxBbdCtl.bits_st.BbIdetectSpi = NormalSensitivity;
    rxBbdCtl.bits_st.BbGroundedSpi = Grounded;
    if ((RXIP >= e_SYS_RX1) && (RXIP <= e_SYS_RX4))
    {
        ErrCode = BC_SPI_WriteCheck(RXIP, R2M0D_BBD_CONTROL_U16, rxBbdCtl.val_u32);
    }
    else if (RXIP == e_SYS_RXMC)
    {
        ErrCode = BC_SPI_Write(RXIP, R2M0D_BBD_CONTROL_U16, rxBbdCtl.val_u32);
        if (BC_ERR_NOERROR == ErrCode)
        {
            ErrCode = BC_SPI_Read(e_SYS_RX1, R2M0D_BBD_CONTROL_U16, &rx1BbdCtl);
        }
        if (BC_ERR_NOERROR == ErrCode)
        {
            ErrCode = BC_SPI_Read(e_SYS_RX2, R2M0D_BBD_CONTROL_U16, &rx2BbdCtl);
        }
        if (BC_ERR_NOERROR == ErrCode)
        {
            ErrCode = BC_SPI_Read(e_SYS_RX3, R2M0D_BBD_CONTROL_U16, &rx3BbdCtl);
        }
        if (BC_ERR_NOERROR == ErrCode)
        {
            ErrCode = BC_SPI_Read(e_SYS_RX4, R2M0D_BBD_CONTROL_U16, &rx4BbdCtl);
        }
        if (BC_ERR_NOERROR == ErrCode)
        {
            uint8_t Count = 0u;
            if (rxBbdCtl.val_u32 != rx1BbdCtl)
            {
                Count = 1u;
            }
            if (rxBbdCtl.val_u32 != rx2BbdCtl)
            {
                Count = Count + 2u;
            }
            if (rxBbdCtl.val_u32 != rx3BbdCtl)
            {
                Count = Count + 4u;
            }
            if (rxBbdCtl.val_u32 != rx4BbdCtl)
            {
                Count = Count + 8u;
            }
            if (Count != 0u)
            {
                ErrCode = BC_ERR_RX_BBD_ENABLE_WRITECHECK_BASE + (uint32_t)Count;
            }
        }
    }
    else
    {
        ErrCode = BC_ERR_RX_INPUTOUTOFRANGE;
    }
    return ErrCode;
}

static BC_ERRCODE Helper_SetRXLOx3CaliGainSource(SYS_IPNum_e RXIP, RX_LOx3_GainSelect_e Lox3GainSource)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M0D_Lox3GainControlUnion_t Lox3GainControl;

    if (gLox3GainCalTargetOffset[gTargetDevice] <= RX_LOX3_CAL_TARGET_OFFSET_MAX)
    {
        // not reading the LOX3_GAIN_CONTROL since the value of Lox3GainCalTargetOffset is already stored, all Rx will have same value of Lox3GainCalTargetOffset, so reading one Rx is fine
        Lox3GainControl.val_u32 = 0u;
        Lox3GainControl.bits_st.Lox3GainCalTargetOffset = gLox3GainCalTargetOffset[gTargetDevice];
        Lox3GainControl.bits_st.Lox3GainSource = (uint8_t)Lox3GainSource;
        ErrCode = BC_SPI_Write(RXIP, R2M0D_LOX3_GAIN_CONTROL_U16, Lox3GainControl.val_u32);
    }
    else
    {
        /* Lox3GainCalTargetOffset should be configured less than or equal to 3.
            0 for VCO 1G and freq less than 79.5 GHz
            1 for VCO 1G and freq greater than 79.5 GHz
            2 for VCO 5G Narrow and 3 for VCO 5G wide */
        ErrCode = BC_ERR_RX_WRNG_CAL_TARGET_OFFSET;
    }
    return ErrCode;
}

static BC_ERRCODE Helper_RxCalibLOx3GainCheckRange(SYS_IPNum_e RXIP, uint32_t CalCheckTimeOutUs, uint32_t *pDefaultCalCheckTimeOutUs)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    *pDefaultCalCheckTimeOutUs = (CalCheckTimeOutUs == 0u) ? RX_LOX3_CALIBRATION_TIMEOUT : CalCheckTimeOutUs;
    if (((RXIP < e_SYS_RX1) || (RXIP > e_SYS_RX4)) && (RXIP != e_SYS_RXMC))
    {
        ErrCode = BC_ERR_RX_INPUTOUTOFRANGE;
    }
    return ErrCode;
}
#endif
