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

#include "bc_types.h"
#include "bc_err.h"
#include "bc_conf.h"
#include "bc_spi.h"
#include "bc_ism.h"
#include "bc_cc.h"
#include "plf.h"
#include "hal_es2_loi.h"
#include "hal_es2_otp.h"

// Register header
#ifdef BUILD_FOR_VAL
#include "v_es2_loi.h"
#else
#include "reg_es2_loi.h"
#endif
static BC_ERRCODE Helper_ES2_GetFuncSafeMonLvlSettings(uint32_t *pFuncSafeMonLvlSettings);
static BC_ERRCODE Helper_ES2_LOx3GainRangeCheck(LOI_LOx3GainConfig_t *pLOx3GainConfig);
static BC_ERRCODE Helper_ES2_DisableLOx3Channels(BOOL LOx3TxChannels[3], BOOL LOx3RxChannels[4]);
static uint8_t Helper_ES2_GetDisableFlag(BOOL IP, BOOL LOx3Channel);
BC_ERRCODE HAL_ES2_LOI_ConfigBufferMode(BOOL EnBuffer1, BOOL EnBuffer2, BOOL EnBuffer3, BOOL EnBuffer4, BOOL MuxCtrl, BOOL EnCtrlSwitch)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M0A_LoInterfaceControlUnion_t LoInterfaceControl;

    ErrCode = BC_SPI_Read(e_SYS_LOI, R2M0A_LO_INTERFACE_CONTROL_U16, &LoInterfaceControl.val_u32);
    if (ErrCode == BC_ERR_NOERROR)
    {
        // Enable LO_26GHz_in to MUX
        LoInterfaceControl.bits_st.EnB1 = (uint8_t)EnBuffer1;
        // Enable MUX output to TX/LOI (must have for Slave, and Master/Slave config
        LoInterfaceControl.bits_st.EnB2 = (uint8_t)EnBuffer2;
        // Enable LOin to MUX
        LoInterfaceControl.bits_st.EnB3 = (uint8_t)EnBuffer3;
        // Enable LO_26GHz to LOout
        LoInterfaceControl.bits_st.EnB4 = (uint8_t)EnBuffer4;
        LoInterfaceControl.bits_st.CntrMuxLoSpi = (uint8_t)MuxCtrl;
        LoInterfaceControl.bits_st.CtrlSwitch = (uint8_t)EnCtrlSwitch;

        ErrCode = BC_SPI_WriteCheck(e_SYS_LOI, R2M0A_LO_INTERFACE_CONTROL_U16, LoInterfaceControl.val_u32);
    }

    return ErrCode;
}

BC_ERRCODE HAL_ES2_LOI_ConfigLOGainCtrl(LOI_GainSel_e GainSelect, uint8_t GainCode, BOOL BinSearchFromAbove)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M0A_LoInterfaceB2GainCalControlUnion_t LoB2GainCalControl;
    R2M0A_LoInterfaceGainControlUnion_t LoGainControl;
    R2M0A_LoInterfaceControlUnion_t LoControl;

    if (GainSelect < e_LOI_GAIN_INVALID)
    {
        ErrCode = BC_SPI_Read(e_SYS_LOI, R2M0A_LO_INTERFACE_GAIN_CONTROL_U16, &LoGainControl.val_u32);

        LoGainControl.bits_st.GainControlSel = (uint8_t)GainSelect;

        if ((GainSelect == e_LOI_GAIN_DIRECT) && (ErrCode == BC_ERR_NOERROR))
        {
            ErrCode = BC_SPI_Read(e_SYS_LOI, R2M0A_LO_INTERFACE_CONTROL_U16, &LoControl.val_u32);
            // Direct 8 bit control for the gain_code
            LoControl.bits_st.GainCodeDirect = GainCode;
            if (ErrCode == BC_ERR_NOERROR)
            {
                ErrCode = BC_SPI_WriteCheck(e_SYS_LOI, R2M0A_LO_INTERFACE_CONTROL_U16, LoControl.val_u32);
            }
        }

        if ((GainSelect == e_LOI_GAIN_LUT) && (ErrCode == BC_ERR_NOERROR))
        {
            // GainCodeLut bit field is 5bit
            ErrCode = (GainCode <= 31u) ? BC_ERR_NOERROR : BC_ERR_LOI_LUTGAINCODE_OUTOFRANGE;
            if (ErrCode == BC_ERR_NOERROR)
            {
                LoGainControl.bits_st.GainCodeLut = GainCode;
            }
        }

        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = BC_SPI_WriteCheck(e_SYS_LOI, R2M0A_LO_INTERFACE_GAIN_CONTROL_U16, LoGainControl.val_u32);
        }

        if (GainSelect == e_LOI_GAIN_CAL)
        {
            if (ErrCode == BC_ERR_NOERROR)
            {
                ErrCode = BC_SPI_Read(e_SYS_LOI, R2M0A_LO_INTERFACE_B2_GAIN_CAL_CONTROL_U16, &LoB2GainCalControl.val_u32);
                LoB2GainCalControl.bits_st.BinSearchFromAbove = (uint8_t)BinSearchFromAbove;
                if (ErrCode == BC_ERR_NOERROR)
                {
                    ErrCode = BC_SPI_WriteCheck(e_SYS_LOI, R2M0A_LO_INTERFACE_B2_GAIN_CAL_CONTROL_U16, LoB2GainCalControl.val_u32);
                }
            }
        }
    }
    else
    {
        ErrCode = BC_ERR_INPUTOUTOFRANGE;
    }

    return ErrCode;
}

BC_ERRCODE HAL_ES2_LOI_StartLOGainCalib(BOOL ReadCalibStatus, uint32_t CalCheckTimeOutUs)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    SYS_CalibrationStatus_t CalibrationStatus;
    ISM_Cal_Status_e CalStatus;
    R2M0A_LoInterfaceB2GainCalStartUnion_t LoB2GainCalStart;

    LoB2GainCalStart.val_u32 = 0x0u;
    LoB2GainCalStart.bits_st.LoiStartCal = 1u;
    ErrCode = BC_SPI_Write(e_SYS_LOI, R2M0A_LO_INTERFACE_B2_GAIN_CAL_START_U16, LoB2GainCalStart.val_u32);

    if ((CalCheckTimeOutUs != 0u) && (ErrCode == BC_ERR_NOERROR))
    {
        ErrCode = PLF_TM_Sleep(CalCheckTimeOutUs);
    }

    if ((ReadCalibStatus == TRUE) && (ErrCode == BC_ERR_NOERROR))
    {
        ErrCode = BC_ISM_GetCalibrationStatus(&CalibrationStatus, NULL);
        if (ErrCode == BC_ERR_NOERROR)
        {
            CalStatus = CalibrationStatus.LOICalStatus;
            ErrCode = (CalibrationStatus.LOICalStatus == e_ISM_CAL_BUSY) ? BC_ERR_LOI_CAL_BUSY : ((CalStatus == e_ISM_CAL_ERROR) ? BC_ERR_LOI_CAL_ERROR : BC_ERR_NOERROR);
        }
    }

    return ErrCode;
}

BC_ERRCODE HAL_ES2_LOI_EnableRFLevelRMSDet(BOOL EnRMSDet)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M0A_FuncsafeMonLevelSettingsEnableUnion_t FuncsafeMonLevelSettingsEnable;

    // Enable level detector
    FuncsafeMonLevelSettingsEnable.val_u32 = 0u;
    FuncsafeMonLevelSettingsEnable.bits_st.EnRmsdetLoi = (uint8_t)(EnRMSDet);
    ErrCode = BC_SPI_WriteCheck(e_SYS_LOI, R2M0A_FUNCSAFE_MON_LEVEL_SETTINGS_ENABLE_U16, FuncsafeMonLevelSettingsEnable.val_u32);

    return ErrCode;
}

static BC_ERRCODE Helper_ES2_LOx3GainRangeCheck(LOI_LOx3GainConfig_t *pLOx3GainConfig)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    if (pLOx3GainConfig != NULL)
    {
        if (!((pLOx3GainConfig->TxLOx3GainSelect < e_LOI_TXGAIN_LOX3_INVALID) && (pLOx3GainConfig->RxLOx3GainSelect < e_LOI_RXGAIN_LOX3_INVALID) && (pLOx3GainConfig->TXMinMaxAvg < e_LOI_LOX3_INVALID) && (pLOx3GainConfig->RXMinMaxAvg < e_LOI_LOX3_INVALID)))
        {
            ErrCode = BC_ERR_INPUTOUTOFRANGE;
        }
        if ((ErrCode == BC_ERR_NOERROR) && ((pLOx3GainConfig->RxLOx3Gain > 0x20u) || (pLOx3GainConfig->TxLOx3Gain > 0x20u)))
        {
            ErrCode = BC_ERR_INPUTOUTOFRANGE;
        }
    }
    else
    {
        ErrCode = BC_ERR_LOI_PTR_ADDR_NULL;
    }
    return ErrCode;
}

static uint8_t Helper_ES2_GetDisableFlag(BOOL IP, BOOL LOx3Channel)
{
    uint8_t DisableFlag = 1u;
    if ((IP == TRUE) && (LOx3Channel == TRUE))
    {
        DisableFlag = 0u;
    }
    return DisableFlag;
}

static BC_ERRCODE Helper_ES2_DisableLOx3Channels(BOOL LOx3TxChannels[3], BOOL LOx3RxChannels[4])
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M0A_Lox3ChannelDisableUnion_t Lox3ChannelDisable;
    SYS_IPList_t AppConfig = {FALSE};

    if ((LOx3TxChannels == NULL) || (LOx3RxChannels == NULL))
    {
        ErrCode = BC_ERR_LOI_PTR_ADDR_NULL;
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_CC_GetAppConfiguration(&AppConfig, NULL);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        Lox3ChannelDisable.val_u32 = 0u;
        Lox3ChannelDisable.bits_st.Tx1Disabled = Helper_ES2_GetDisableFlag(AppConfig.TX1, LOx3TxChannels[0u]);
        Lox3ChannelDisable.bits_st.Tx2Disabled = Helper_ES2_GetDisableFlag(AppConfig.TX2, LOx3TxChannels[1u]);
        Lox3ChannelDisable.bits_st.Tx3Disabled = Helper_ES2_GetDisableFlag(AppConfig.TX3, LOx3TxChannels[2u]);
        Lox3ChannelDisable.bits_st.Rx1Disabled = Helper_ES2_GetDisableFlag(AppConfig.RX1, LOx3RxChannels[0u]);
        Lox3ChannelDisable.bits_st.Rx2Disabled = Helper_ES2_GetDisableFlag(AppConfig.RX2, LOx3RxChannels[1u]);
        Lox3ChannelDisable.bits_st.Rx3Disabled = Helper_ES2_GetDisableFlag(AppConfig.RX3, LOx3RxChannels[2u]);
        Lox3ChannelDisable.bits_st.Rx4Disabled = Helper_ES2_GetDisableFlag(AppConfig.RX4, LOx3RxChannels[3u]);
        ErrCode = BC_SPI_WriteCheck(e_SYS_LOI, R2M0A_LOX3_CHANNEL_DISABLE_U16, Lox3ChannelDisable.val_u32);
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_LOI_ConfigLOx3Gain(LOI_LOx3GainConfig_t *pLOx3GainConfig, BOOL LOx3TxChannels[3], BOOL LOx3RxChannels[4])
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M0A_Lox3GainControlUnion_t Lox3GainCtrl;

    ErrCode = Helper_ES2_LOx3GainRangeCheck(pLOx3GainConfig);

    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = Helper_ES2_DisableLOx3Channels(LOx3TxChannels, LOx3RxChannels);

        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = BC_SPI_Read(e_SYS_LOI, R2M0A_LOX3_GAIN_CONTROL_U16, &Lox3GainCtrl.val_u32);
        }
        if (ErrCode == BC_ERR_NOERROR)
        {
            Lox3GainCtrl.bits_st.RxLox3GainSel = (uint8_t)pLOx3GainConfig->RxLOx3GainSelect;
            Lox3GainCtrl.bits_st.TxLox3GainSel = (uint8_t)pLOx3GainConfig->TxLOx3GainSelect;
            Lox3GainCtrl.bits_st.TxLox3GainCtrl = (uint8_t)pLOx3GainConfig->TxLOx3Gain;
            Lox3GainCtrl.bits_st.Lox3GainCtrl = (uint8_t)pLOx3GainConfig->RxLOx3Gain;
            Lox3GainCtrl.bits_st.RxLox3MinMaxAvgSel = (uint8_t)pLOx3GainConfig->RXMinMaxAvg;
            Lox3GainCtrl.bits_st.TxLox3MinMaxAvgSel = (uint8_t)pLOx3GainConfig->TXMinMaxAvg;
            Lox3GainCtrl.bits_st.TxLox3GainAvgRoundUp = (uint8_t)pLOx3GainConfig->TxGainAvgRoundUp;
            Lox3GainCtrl.bits_st.RxLox3GainAvgRoundUp = (uint8_t)pLOx3GainConfig->RxGainAvgRoundUp;
            ErrCode = BC_SPI_WriteCheck(e_SYS_LOI, R2M0A_LOX3_GAIN_CONTROL_U16, Lox3GainCtrl.val_u32);
        }
    }
    return ErrCode;
}

static BC_ERRCODE Helper_ES2_GetFuncSafeMonLvlSettings(uint32_t *pFuncSafeMonLvlSettings)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M0A_FuncsafeMonLevelSettingsUnion_t FuncsafeMonLevelSettings;
    uint32_t TrimLOIThreshOTP = 0u;
    uint16_t TrimLOIThreshOTPIndex = OTP_TRIM_LOI_THRESH_INDEX;
    uint32_t LOIMaskLOMax;
    uint32_t LOILOMaxIndex = OTP_LEVEL_LOI_MAX_SPI_LOI_INDEX;
    uint32_t LOIMaskLOHigh;
    uint32_t LOILOHighIndex = OTP_LEVEL_LOI_HIGH_SPI_LOI_INDEX;
    uint32_t LOIMaskLOLow;
    uint32_t LOILOLowIndex = OTP_LEVEL_LOI_LOW_SPI_LOI_INDEX;
    uint32_t LOIMaskLOMin;
    uint32_t LOILOMinIndex = OTP_LEVEL_LOI_MIN_SPI_LOI_INDEX;
    uint32_t LOIPosLOMax;
    uint32_t LOIPosLOHigh;
    uint32_t LOIPosLOLow;
    uint32_t LOIPosLOMin;

    ErrCode = HAL_ES2_OTP_GetOTPRegValue(TrimLOIThreshOTPIndex, &TrimLOIThreshOTP);
    if (ErrCode == BC_ERR_NOERROR)
    {
        LOIMaskLOMax = OtpTrimLoiThresh[LOILOMaxIndex].SrcMsk;
        LOIMaskLOHigh = OtpTrimLoiThresh[LOILOHighIndex].SrcMsk;
        LOIMaskLOLow = OtpTrimLoiThresh[LOILOLowIndex].SrcMsk;
        LOIMaskLOMin = OtpTrimLoiThresh[LOILOMinIndex].SrcMsk;
        LOIPosLOMax = OtpTrimLoiThresh[LOILOMaxIndex].SrcPos;
        LOIPosLOHigh = OtpTrimLoiThresh[LOILOHighIndex].SrcPos;
        LOIPosLOLow = OtpTrimLoiThresh[LOILOLowIndex].SrcPos;
        LOIPosLOMin = OtpTrimLoiThresh[LOILOMinIndex].SrcPos;
        FuncsafeMonLevelSettings.val_u32 = 0u;
        FuncsafeMonLevelSettings.bits_st.LevelLoiMaxSpi = (uint8_t)((TrimLOIThreshOTP & LOIMaskLOMax) >> LOIPosLOMax);
        FuncsafeMonLevelSettings.bits_st.LevelLoiHighSpi = (uint8_t)((TrimLOIThreshOTP & LOIMaskLOHigh) >> LOIPosLOHigh);
        FuncsafeMonLevelSettings.bits_st.LevelLoiLowSpi = (uint8_t)((TrimLOIThreshOTP & LOIMaskLOLow) >> LOIPosLOLow);
        FuncsafeMonLevelSettings.bits_st.LevelLoiMinSpi = (uint8_t)((TrimLOIThreshOTP & LOIMaskLOMin) >> LOIPosLOMin);
        *pFuncSafeMonLvlSettings = FuncsafeMonLevelSettings.val_u32;
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_LOI_UpdateLOILevelTh(BC_FLOAT InputBW)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M0A_FuncsafeMonLevelSettingsUnion_t FuncsafeMonLevelSettings;
    uint8_t ReduceFactor = 0u;
    FuncsafeMonLevelSettings.val_u32 = 0u;
    ErrCode = Helper_ES2_GetFuncSafeMonLvlSettings(&FuncsafeMonLevelSettings.val_u32);
    if (ErrCode == BC_ERR_NOERROR)
    {
        if (InputBW > LOI_4G_INPUTBW_LIMIT)
        {
            ReduceFactor = 1u;
        }
        FuncsafeMonLevelSettings.bits_st.LevelLoiLowSpi = (uint8_t)(FuncsafeMonLevelSettings.bits_st.LevelLoiLowSpi - ReduceFactor);
        FuncsafeMonLevelSettings.bits_st.LevelLoiMinSpi = (uint8_t)(FuncsafeMonLevelSettings.bits_st.LevelLoiMinSpi - ReduceFactor);
        FuncsafeMonLevelSettings.bits_st.LevelLoiHighSpi = (uint8_t)(FuncsafeMonLevelSettings.bits_st.LevelLoiHighSpi + ReduceFactor);
        FuncsafeMonLevelSettings.bits_st.LevelLoiMaxSpi = (uint8_t)(FuncsafeMonLevelSettings.bits_st.LevelLoiMaxSpi + ReduceFactor);
        ErrCode = BC_SPI_Write(e_SYS_LOI, R2M0A_FUNCSAFE_MON_LEVEL_SETTINGS_U16, FuncsafeMonLevelSettings.val_u32);
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_LOI_ConfigBBD(BOOL EnableBBDLOIN, BOOL EnableBBDLOOUT, BOOL NormalSensitivityLOIN, BOOL GroundedLOIN, BOOL NormalSensitivityLOOUT, BOOL GroundedLOOUT)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M0A_BbdControlUnion_t LoiBbdControl;
    LoiBbdControl.val_u32 = 0u;

    if ( TRUE == EnableBBDLOIN)
    {
        LoiBbdControl.bits_st.BbLoinEnSpi = (uint8_t)EnableBBDLOIN;
        LoiBbdControl.bits_st.BbLoinIdetectSpi = (uint8_t)NormalSensitivityLOIN;
        LoiBbdControl.bits_st.BbLoinGroundedSpi = (uint8_t)GroundedLOIN;
    }

    if ( TRUE == EnableBBDLOOUT)
    {
        LoiBbdControl.bits_st.BbLooutEnSpi = (uint8_t)EnableBBDLOOUT;
        LoiBbdControl.bits_st.BbLooutIdetectSpi = (uint8_t)NormalSensitivityLOOUT;
        LoiBbdControl.bits_st.BbLooutGroundedSpi = (uint8_t)GroundedLOOUT;
    }

    ErrCode = BC_SPI_WriteCheck(e_SYS_LOI, R2M0A_BBD_CONTROL_U16, LoiBbdControl.val_u32);

    return ErrCode;
}

#endif
