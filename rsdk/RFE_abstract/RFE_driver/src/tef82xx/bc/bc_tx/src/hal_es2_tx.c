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
#include "bc_err.h"
#include "bc_types.h"
#include "bc_spi.h"
#include "bc_conf.h"
#include "bc_ism.h"
#include "bc_cafc.h"
#include "bc_cc.h"
#ifdef BUILD_FOR_VAL
#include "v_es2_tx.h"
#else
#include "reg_es2_tx.h"
#endif
#include "hal_es2_tx.h"
#include "hal_es2_otp.h"
#include "plf.h"

static BC_ERRCODE Helper_ES2_SetEnRMSDetMC(BOOL EnRMSDet);
static BC_ERRCODE Helper_GetAdjustedCurGain(SYS_TXErrors_t *pTxErr, uint8_t PercntCurGainAdj, uint8_t PercntgBiasCurGainAdj, uint8_t *pTxCurrGain);
static BC_ERRCODE Helper_CopyTXRFCurrentGain(SYS_IPNum_e TXIP, SYS_ProfID_e CalibrateProfID, SYS_StoreInProfile_t *pStoreInProfile, uint8_t TxCurrGain);
static BC_ERRCODE Helper_ES2_TxPaBiasCurWriteCheck(uint32_t Tx1PaBiasCtrlVal, uint32_t Tx2PaBiasCtrlVal, uint32_t Tx3PaBiasCtrlVal);
static BC_ERRCODE Helper_ES2_TxSetSt1BiasCtrl(SYS_IPNum_e TXIP, uint32_t Tx1PaBiasCtrlVal32, uint32_t Tx2PaBiasCtrlVal32, uint32_t Tx3PaBiasCtrlVal32);
static BC_ERRCODE Helper_ES2_SetSt1BiasCtrl(SYS_IPNum_e TXIP, BOOL SetZeroSt1Bias);
static BC_ERRCODE Helper_ES2_ReadTxCalibStatus(SYS_IPNum_e TXIP);
static BC_ERRCODE Helper_ES2_SetTxCurrentGain(SYS_IPNum_e TXIP, SYS_ProfID_e CalibrateProfID);
static BC_ERRCODE Helper_ES2_GetSafeMaxTarget(SYS_IPNum_e TXIP, uint8_t *pTx1SafeTarget, uint8_t *pTx2SafeTarget, uint8_t *pTx3SafeTarget, uint8_t BackOffCode);
static BC_ERRCODE Helper_ES2_TXGetSafeMaxTarget(uint8_t *pTxSafeTarget, uint16_t Offset, const OTP_TableDescrip_t *pTableBase, uint8_t BackOffCode);
static void Helper_StoreInProfile(SYS_StoreInProfile_t *pStoreInProfile, BOOL pProfile[SYS_MAX_PROFILE_COUNT]);
static BC_ERRCODE Helper_ES2_CalTxCalibStatus(SYS_IPNum_e TXIP);
static BC_ERRCODE Helper_ES2_CalTxMCCalibStatus(uint8_t *pCalStatusBusy, uint32_t *pCalStatusError);
static ISM_Cal_Status_e Helper_ES2_GetISMCalStatus(uint8_t CalBusyFlag, uint8_t CalErrorFlag);
static BC_ERRCODE Helper_ES2_GetLocalCalStatus(SYS_IPNum_e TXIP, TX_CalibrationStatus_t *pCalibStatus, uint32_t *pTxCalStatus);
static BC_ERRCODE Helper_ES2_TxMCSafetyCheckStatus(uint8_t *pCalStatusBusy, uint32_t *pCalStatusError);
static BC_ERRCODE Helper_ES2_TxSafetyCheckStatus(SYS_IPNum_e TXIP);
static BC_ERRCODE Helper_ES2_ReadSafetyCheckStatus(SYS_IPNum_e TXIP);
static BC_ERRCODE Helper_ES2_CalibTimeRangeCheck(TX_CalibrationTime_t *pCalibTime);
static BC_ERRCODE Helper_ES2_GetFunSafeOTPRegVal(SYS_IPNum_e TXIP, float32_t LevelRfMin, uint32_t *pTx1FunSafeVal, uint32_t *pTx2FunSafeVal, uint32_t *pTx3FunSafeVal, uint32_t *pFunSafeVal);
static BC_ERRCODE Helper_ES2_LvlRFMinRangeCheck(SYS_IPNum_e TXIP, float32_t LevelRfMin);
static BOOL Helper_ES2_LvlRFMinValCheck(uint32_t Tx1Val, uint32_t Tx2Val, uint32_t Tx3Val);
static BC_ERRCODE Helper_ES2_GetTXFunSafeOTPRegVal(uint8_t LevelRfMinCode, uint16_t Offset, const OTP_TableDescrip_t *pTableBase, uint32_t *pTxFunSafeVal);
static BC_ERRCODE Helper_ES2_CalTXRFRangeCheck(SYS_IPNum_e TXIP, SYS_EnableTxRfCalibration_t *pEnableTxRfCalibration, SYS_StoreInProfile_t *pStoreInProfile, SYS_ProfID_e CalibrateProfID, BOOL ReduceTransmisionForVGACalib);
static BC_ERRCODE Helper_ES2_VgaCalibWA(SYS_IPNum_e TXIP, SYS_EnableTxRfCalibration_t *pEnableTxRfCalibration, SYS_ProfID_e CalibrateProfID, BOOL ReduceTransmisionForVGACalib, BOOL *pBiasSettingChanged);
static BC_ERRCODE Helper_ES2_CalTXRFNullPntrCheck(SYS_EnableTxRfCalibration_t *pEnableTxRfCalibration, SYS_StoreInProfile_t *pStoreInProfile);
static BC_ERRCODE Helper_CheckCalibStatus(SYS_IPNum_e TXIP);
static BC_ERRCODE Helper_RestoreBiasCurrent(SYS_IPNum_e TXIP, BOOL ReadCalibStatus, BC_ERRCODE ErrCode);
static BC_ERRCODE Helper_ES2_SetTxCurrentGain(SYS_IPNum_e TXIP, SYS_ProfID_e CalibrateProfID)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M11_TxCurrGainProfile0Union_t TxCurrGainProfile;
    if (TXIP == e_SYS_TXMC)
    {
        SYS_IPNum_e TXIPTmp = e_SYS_TX1;
        ErrCode = BC_SPI_Read(TXIPTmp, R2M11_TX_CURR_GAIN_PROFILE0_U16 + ((uint16_t)CalibrateProfID * 8u), &TxCurrGainProfile.val_u32);
        if (BC_ERR_NOERROR == ErrCode)
        {
            TxCurrGainProfile.bits_st.TxCurrGainCtrlProfile0 = 0xFFu;
            ErrCode = BC_SPI_Write(TXIPTmp, R2M11_TX_CURR_GAIN_PROFILE0_U16 + ((uint16_t)CalibrateProfID * 8u), TxCurrGainProfile.val_u32);
        }
        TXIPTmp = e_SYS_TX2;
        if (BC_ERR_NOERROR == ErrCode)
        {
            ErrCode = BC_SPI_Read(TXIPTmp, R2M11_TX_CURR_GAIN_PROFILE0_U16 + ((uint16_t)CalibrateProfID * 8u), &TxCurrGainProfile.val_u32);
            if (BC_ERR_NOERROR == ErrCode)
            {
                TxCurrGainProfile.bits_st.TxCurrGainCtrlProfile0 = 0xFFu;
                ErrCode = BC_SPI_Write(TXIPTmp, R2M11_TX_CURR_GAIN_PROFILE0_U16 + ((uint16_t)CalibrateProfID * 8u), TxCurrGainProfile.val_u32);
            }
        }
        TXIPTmp = e_SYS_TX3;
        if (BC_ERR_NOERROR == ErrCode)
        {
            ErrCode = BC_SPI_Read(TXIPTmp, R2M11_TX_CURR_GAIN_PROFILE0_U16 + ((uint16_t)CalibrateProfID * 8u), &TxCurrGainProfile.val_u32);
            if (BC_ERR_NOERROR == ErrCode)
            {
                TxCurrGainProfile.bits_st.TxCurrGainCtrlProfile0 = 0xFFu;
                ErrCode = BC_SPI_Write(TXIPTmp, R2M11_TX_CURR_GAIN_PROFILE0_U16 + ((uint16_t)CalibrateProfID * 8u), TxCurrGainProfile.val_u32);
            }
        }
    }
    else
    {
        ErrCode = BC_SPI_Read(TXIP, R2M11_TX_CURR_GAIN_PROFILE0_U16 + ((uint16_t)CalibrateProfID * 8u), &TxCurrGainProfile.val_u32);
        if (BC_ERR_NOERROR == ErrCode)
        {
            TxCurrGainProfile.bits_st.TxCurrGainCtrlProfile0 = 0xFFu;
            ErrCode = BC_SPI_Write(TXIP, R2M11_TX_CURR_GAIN_PROFILE0_U16 + ((uint16_t)CalibrateProfID * 8u), TxCurrGainProfile.val_u32);
        }
    }
    return ErrCode;
}

static BC_ERRCODE Helper_ES2_TxRfVgaCalibWA(SYS_IPNum_e TXIP, SYS_ProfID_e CalibrateProfID, BOOL ReadProfileReg)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M11_TxCurrGainProfile0Union_t TxCurrGainProfile;

    if (ReadProfileReg == TRUE)
    {
        ErrCode = Helper_ES2_SetTxCurrentGain(TXIP, CalibrateProfID);
    }
    else
    {
        TxCurrGainProfile.val_u32 = 0u;
        TxCurrGainProfile.bits_st.TxCurrGainCtrlProfile0 = 0xFFu;
        ErrCode = BC_SPI_Write(TXIP, R2M11_TX_CURR_GAIN_PROFILE0_U16 + ((uint16_t)CalibrateProfID * 8u), TxCurrGainProfile.val_u32);
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_CAFC_LoadProfile(CalibrateProfID);
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_TxPaBiasCurWriteCheck(uint32_t Tx1PaBiasCtrlVal, uint32_t Tx2PaBiasCtrlVal, uint32_t Tx3PaBiasCtrlVal)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    uint32_t TxPaBiasCtrl = 0u;
    SYS_IPList_t AppConfig = {FALSE};
    ErrCode = BC_CC_GetAppConfiguration(&AppConfig, NULL);

    if ((TRUE == AppConfig.TX1) && (BC_ERR_NOERROR == ErrCode))
    {
        ErrCode = BC_SPI_Read(e_SYS_TX1, R2M11_TX_PA_BIAS_CTRL_U16, &TxPaBiasCtrl);
        if (TxPaBiasCtrl != Tx1PaBiasCtrlVal)
        {
            ErrCode = BC_ERR_TX_CALIB_BIAS_CURR_WRITE_FAILED;
        }
    }
    if ((TRUE == AppConfig.TX2) && (BC_ERR_NOERROR == ErrCode))
    {
        ErrCode = BC_SPI_Read(e_SYS_TX2, R2M11_TX_PA_BIAS_CTRL_U16, &TxPaBiasCtrl);
        if (TxPaBiasCtrl != Tx2PaBiasCtrlVal)
        {
            ErrCode = BC_ERR_TX_CALIB_BIAS_CURR_WRITE_FAILED;
        }
    }
    if ((TRUE == AppConfig.TX3) && (BC_ERR_NOERROR == ErrCode))
    {
        ErrCode = BC_SPI_Read(e_SYS_TX3, R2M11_TX_PA_BIAS_CTRL_U16, &TxPaBiasCtrl);
        if (TxPaBiasCtrl != Tx3PaBiasCtrlVal)
        {
            ErrCode = BC_ERR_TX_CALIB_BIAS_CURR_WRITE_FAILED;
        }
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_TxSetSt1BiasCtrl(SYS_IPNum_e TXIP, uint32_t Tx1PaBiasCtrlVal32, uint32_t Tx2PaBiasCtrlVal32, uint32_t Tx3PaBiasCtrlVal32)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    uint32_t TxPaBiasCtrl = 0u;

    if (TXIP == e_SYS_TX1)
    {
        TxPaBiasCtrl = Tx1PaBiasCtrlVal32;
    }
    if (TXIP == e_SYS_TX2)
    {
        TxPaBiasCtrl = Tx2PaBiasCtrlVal32;
    }
    if (TXIP == e_SYS_TX3)
    {
        TxPaBiasCtrl = Tx3PaBiasCtrlVal32;
    }
    ErrCode = BC_SPI_WriteCheck(TXIP, R2M11_TX_PA_BIAS_CTRL_U16, TxPaBiasCtrl);
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_SetSt1BiasCtrl(SYS_IPNum_e TXIP, BOOL SetZeroSt1Bias)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M11_TxPaBiasCtrlUnion_t Tx1PaBiasCtrl;
    R2M11_TxPaBiasCtrlUnion_t Tx2PaBiasCtrl;
    R2M11_TxPaBiasCtrlUnion_t Tx3PaBiasCtrl;
    uint32_t TxBiasSt3CtrlOTP;
    uint32_t TxBiasSt12CtrlOTP;

    ErrCode = HAL_ES2_OTP_GetOTPRegValue(OTP_TRIM_TX_BIAS_ST3_INDEX, &TxBiasSt3CtrlOTP);
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = HAL_ES2_OTP_GetOTPRegValue(OTP_TRIM_TX_BIAS_ST12_INDEX, &TxBiasSt12CtrlOTP);
        if (BC_ERR_NOERROR == ErrCode)
        {
            uint32_t MaskTx1St3 = OtpTrimTxBiasSt3[OTP_PA_ST3_BIAS_CTRL_TX1_INDEX].SrcMsk;
            uint32_t MaskTx2St3 = OtpTrimTxBiasSt3[OTP_PA_ST3_BIAS_CTRL_TX2_INDEX].SrcMsk;
            uint32_t MaskTx3St3 = OtpTrimTxBiasSt3[OTP_PA_ST3_BIAS_CTRL_TX3_INDEX].SrcMsk;

            uint32_t MaskTx1St2 = OtpTrimTxBiasSt12[OTP_PA_ST2_BIAS_CTRL_TX1_INDEX].SrcMsk;
            uint32_t MaskTx1St1 = OtpTrimTxBiasSt12[OTP_PA_ST1_BIAS_CTRL_TX1_INDEX].SrcMsk;

            uint32_t MaskTx2St2 = OtpTrimTxBiasSt12[OTP_PA_ST2_BIAS_CTRL_TX2_INDEX].SrcMsk;
            uint32_t MaskTx2St1 = OtpTrimTxBiasSt12[OTP_PA_ST1_BIAS_CTRL_TX2_INDEX].SrcMsk;

            uint32_t MaskTx3St2 = OtpTrimTxBiasSt12[OTP_PA_ST2_BIAS_CTRL_TX3_INDEX].SrcMsk;
            uint32_t MaskTx3St1 = OtpTrimTxBiasSt12[OTP_PA_ST1_BIAS_CTRL_TX3_INDEX].SrcMsk;

            Tx1PaBiasCtrl.val_u32 = 0u;
            Tx1PaBiasCtrl.bits_st.PaSt3BiasCtrl = (uint8_t)((TxBiasSt3CtrlOTP & MaskTx1St3) >> OtpTrimTxBiasSt3[OTP_PA_ST3_BIAS_CTRL_TX1_INDEX].SrcPos);
            Tx1PaBiasCtrl.bits_st.PaSt2BiasCtrl = (uint8_t)((TxBiasSt12CtrlOTP & MaskTx1St2) >> OtpTrimTxBiasSt12[OTP_PA_ST2_BIAS_CTRL_TX1_INDEX].SrcPos);

            Tx2PaBiasCtrl.val_u32 = 0u;
            Tx2PaBiasCtrl.bits_st.PaSt3BiasCtrl = (uint8_t)((TxBiasSt3CtrlOTP & MaskTx2St3) >> OtpTrimTxBiasSt3[OTP_PA_ST3_BIAS_CTRL_TX2_INDEX].SrcPos);
            Tx2PaBiasCtrl.bits_st.PaSt2BiasCtrl = (uint8_t)((TxBiasSt12CtrlOTP & MaskTx2St2) >> OtpTrimTxBiasSt12[OTP_PA_ST2_BIAS_CTRL_TX2_INDEX].SrcPos);

            Tx3PaBiasCtrl.val_u32 = 0u;
            Tx3PaBiasCtrl.bits_st.PaSt3BiasCtrl = (uint8_t)(TxBiasSt3CtrlOTP & MaskTx3St3);
            Tx3PaBiasCtrl.bits_st.PaSt2BiasCtrl = (uint8_t)((TxBiasSt12CtrlOTP & MaskTx3St2) >> OtpTrimTxBiasSt12[OTP_PA_ST2_BIAS_CTRL_TX3_INDEX].SrcPos);

            if (SetZeroSt1Bias == TRUE)
            {
                Tx1PaBiasCtrl.bits_st.PaSt1BiasCtrl = 0x0u;
                Tx2PaBiasCtrl.bits_st.PaSt1BiasCtrl = 0x0u;
                Tx3PaBiasCtrl.bits_st.PaSt1BiasCtrl = 0x0u;
            }
            else
            {
                Tx1PaBiasCtrl.bits_st.PaSt1BiasCtrl = (uint8_t)((TxBiasSt12CtrlOTP & MaskTx1St1) >> OtpTrimTxBiasSt12[OTP_PA_ST1_BIAS_CTRL_TX1_INDEX].SrcPos);
                Tx2PaBiasCtrl.bits_st.PaSt1BiasCtrl = (uint8_t)((TxBiasSt12CtrlOTP & MaskTx2St1) >> OtpTrimTxBiasSt12[OTP_PA_ST1_BIAS_CTRL_TX2_INDEX].SrcPos);
                Tx3PaBiasCtrl.bits_st.PaSt1BiasCtrl = (uint8_t)(TxBiasSt12CtrlOTP & MaskTx3St1);
            }
        }
    }

    if (BC_ERR_NOERROR == ErrCode)
    {
        if (TXIP == e_SYS_TXMC)
        {
            if ((Tx1PaBiasCtrl.val_u32 == Tx2PaBiasCtrl.val_u32) && (Tx1PaBiasCtrl.val_u32 == Tx3PaBiasCtrl.val_u32))
            {
                ErrCode = BC_SPI_Write(e_SYS_TXMC, R2M11_TX_PA_BIAS_CTRL_U16, Tx1PaBiasCtrl.val_u32);
            }
            else
            {
                ErrCode = BC_SPI_Write(e_SYS_TX1, R2M11_TX_PA_BIAS_CTRL_U16, Tx1PaBiasCtrl.val_u32);
                if (BC_ERR_NOERROR == ErrCode)
                {
                    ErrCode = BC_SPI_Write(e_SYS_TX2, R2M11_TX_PA_BIAS_CTRL_U16, Tx2PaBiasCtrl.val_u32);
                }
                if (BC_ERR_NOERROR == ErrCode)
                {
                    ErrCode = BC_SPI_Write(e_SYS_TX3, R2M11_TX_PA_BIAS_CTRL_U16, Tx3PaBiasCtrl.val_u32);
                }
            }

            // Perform separate write check for multicast
            if (BC_ERR_NOERROR == ErrCode)
            {
                ErrCode = Helper_ES2_TxPaBiasCurWriteCheck(Tx1PaBiasCtrl.val_u32, Tx2PaBiasCtrl.val_u32, Tx3PaBiasCtrl.val_u32);
            }
        }
        else
        {
            ErrCode = Helper_ES2_TxSetSt1BiasCtrl(TXIP, Tx1PaBiasCtrl.val_u32, Tx2PaBiasCtrl.val_u32, Tx3PaBiasCtrl.val_u32);
        }
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_SetEnRMSDetMC(BOOL EnRMSDet)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M11_FuncsafeMonLevelSettingsEnableUnion_t FuncSafeCtrl;
    uint32_t FuncSafeCtrlTX1 = 0u;
    uint32_t FuncSafeCtrlTX2 = 0u;
    uint32_t FuncSafeCtrlTX3 = 0u;
    uint8_t Count = 0u;
    SYS_IPList_t AppConfig = {FALSE};
    ErrCode = BC_CC_GetAppConfiguration(&AppConfig, NULL);

    FuncSafeCtrl.val_u32 = 0u; /*To set unused bits to 0*/
    /*Enable the Func Safety Mon Level, LO detection */
    FuncSafeCtrl.bits_st.LevelRfEnableSpi = (uint8_t)EnRMSDet;
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SPI_Write(e_SYS_TXMC, R2M11_FUNCSAFE_MON_LEVEL_SETTINGS_ENABLE_U16, FuncSafeCtrl.val_u32);
    }
    if ((TRUE == AppConfig.TX1) && (BC_ERR_NOERROR == ErrCode))
    {
        ErrCode = BC_SPI_Read(e_SYS_TX1, R2M11_FUNCSAFE_MON_LEVEL_SETTINGS_ENABLE_U16, &FuncSafeCtrlTX1);
        if (FuncSafeCtrl.val_u32 != FuncSafeCtrlTX1)
        {
            Count = 1u;
        }
    }
    if ((TRUE == AppConfig.TX2) && (BC_ERR_NOERROR == ErrCode))
    {
        ErrCode = BC_SPI_Read(e_SYS_TX2, R2M11_FUNCSAFE_MON_LEVEL_SETTINGS_ENABLE_U16, &FuncSafeCtrlTX2);
        if (FuncSafeCtrl.val_u32 != FuncSafeCtrlTX2)
        {
            Count = Count + 2u;
        }
    }
    if ((TRUE == AppConfig.TX3) && (BC_ERR_NOERROR == ErrCode))
    {
        ErrCode = BC_SPI_Read(e_SYS_TX3, R2M11_FUNCSAFE_MON_LEVEL_SETTINGS_ENABLE_U16, &FuncSafeCtrlTX3);
        if (FuncSafeCtrl.val_u32 != FuncSafeCtrlTX3)
        {
            Count = Count + 4u;
        }
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        if (Count != 0u)
        {
            ErrCode = BC_ERR_TX_FUSA_ENABLE_WRITECHECK_BASE + Count;
        }
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_TX_SetRFTargetPower(SYS_ProfID_e ProfID, SYS_IPNum_e TXIP, float32_t TargetPower)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M11_AmpSettingsProfile0Union_t AmpSettings;
    uint8_t TXLevelMaxCode = 63u; // TX output max threshold is 15dbm
    uint8_t TargetPowerCode = 0u;

    if ((TargetPower >= TX_LEVEL_MINIMUM_TARGET_POWER) && (TargetPower <= TX_LEVEL_MAXIMUM_TARGET_POWER) && (ProfID <= e_SYS_PROFILE_8) && (((TXIP >= e_SYS_TX1) && (TXIP <= e_SYS_TX3)) || (TXIP == e_SYS_TXMC)))
    {
        // TX Output threshold code and rf level are linear, each code step is 0.29dBm in RF power
        TargetPowerCode = TXLevelMaxCode - (uint8_t)lroundf((15.0f - TargetPower) / 0.29f);

        AmpSettings.val_u32 = 0u; /*To set unused bits to 0*/
        AmpSettings.bits_st.TxPowerTargetProfile0 = TargetPowerCode;
        ErrCode = BC_SPI_Write(TXIP, (R2M11_AMP_SETTINGS_PROFILE0_U16 + ((uint16_t)ProfID * 8u)), AmpSettings.val_u32);
    }
    else
    {
        ErrCode = BC_ERR_TX_INPUTOUTOFRANGE;
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_TX_SetProfileGain(SYS_ProfID_e ProfID, SYS_IPNum_e TXIP, uint8_t TXGain)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M11_TxCurrGainProfile0Union_t TxCurrGainCtrl;
    uint16_t AddrTxCurrGainProfReg;

    if ((ProfID <= e_SYS_PROFILE_8) && ((TXIP >= e_SYS_TX1) && (TXIP <= e_SYS_TX3)))
    {
        /*Note: Based on profile, the register address changes.
        For all profiles the underlying structure is of same type; with different names"*/
        AddrTxCurrGainProfReg = R2M11_TX_CURR_GAIN_PROFILE0_U16 + ((uint16_t)ProfID * 8u);
        ErrCode = BC_SPI_Read(TXIP, AddrTxCurrGainProfReg, &TxCurrGainCtrl.val_u32);
        if (ErrCode == BC_ERR_NOERROR)
        {
            /*As TXGain is of uint8_t type; no need for check the range */
            TxCurrGainCtrl.bits_st.TxCurrGainCtrlProfile0 = TXGain;
            ErrCode = BC_SPI_Write(TXIP, AddrTxCurrGainProfReg, TxCurrGainCtrl.val_u32);
        }
    }
    else
    {
        ErrCode = BC_ERR_TX_INPUTOUTOFRANGE;
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_TX_EnableRFLevelRMSDet(BOOL EnRMSDet, SYS_IPNum_e TXIP)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M11_FuncsafeMonLevelSettingsEnableUnion_t FuncSafeCtrl;

    if ((TXIP >= e_SYS_TX1) && (TXIP <= e_SYS_TX3))
    {
        FuncSafeCtrl.val_u32 = 0u; /*To set unused bits to 0*/
        /*Enable the Func Safety Mon Level / LO detection */
        FuncSafeCtrl.bits_st.LevelRfEnableSpi = (uint8_t)EnRMSDet;
        ErrCode = BC_SPI_WriteCheck(TXIP, R2M11_FUNCSAFE_MON_LEVEL_SETTINGS_ENABLE_U16, FuncSafeCtrl.val_u32);
    }
    else if (e_SYS_TXMC == TXIP)
    {
        ErrCode = Helper_ES2_SetEnRMSDetMC(EnRMSDet);
    }
    else
    {
        ErrCode = BC_ERR_TX_INPUTOUTOFRANGE;
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_TX_ConfigLocalCtrl(SYS_IPNum_e TXIP, BOOL UseEXTPSPin, BOOL BPS, BOOL ForcePhaseShift, float32_t PhaseShift, BOOL CloseTXSW, BOOL EnTX)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M11_PrcTestTeInputUnion_t PrcTestTEInputCtrl;
    R2M11_TxControlUnion_t TXCtrl;
    uint8_t tmpPhaseShift;

    if (((((TXIP >= e_SYS_TX1) && (TXIP <= e_SYS_TX3))) || (e_SYS_TXMC == TXIP)))
    {

        TXCtrl.val_u32 = 0; /*Note: TXCtrl.bits_st.PonLsSpi retained to reset value 0 */
        TXCtrl.bits_st.EnPsExtSpi = (uint8_t)UseEXTPSPin;
        TXCtrl.bits_st.PsTxViaSpi = (uint8_t)BPS;
        TXCtrl.bits_st.EnTxViaSpi = (uint8_t)EnTX;
        TXCtrl.bits_st.SwTxViaSpi = (uint8_t)CloseTXSW;
        TXCtrl.bits_st.TxActiveDelayCtrl = 40u; // set it as default value in the register map
        TXCtrl.bits_st.TxActiveViaSpi = (uint8_t)TRUE;
        TXCtrl.bits_st.TxCascodeSelViaSpi = (uint8_t)FALSE;
        TXCtrl.bits_st.TxCascodeValueViaSpi = (uint8_t)FALSE;
        ErrCode = BC_SPI_Write(TXIP, R2M11_TX_CONTROL_U16, TXCtrl.val_u32);

        if (BC_ERR_NOERROR == ErrCode)
        {
            PrcTestTEInputCtrl.val_u32 = 0u; /*To set unused bits to 0s*/
            PrcTestTEInputCtrl.bits_st.DForceTePhaseSel = (uint8_t)ForcePhaseShift;

            /*Converting floating phase to phase code*/
            /*Input phase will be rounded to integer multiple of 5.625 degrees */
            tmpPhaseShift = (uint8_t)lroundf(PhaseShift / 5.625f);
            PrcTestTEInputCtrl.bits_st.DForceTePhase = (uint8_t)(tmpPhaseShift & 0x3Fu);
            ErrCode = BC_SPI_Write(TXIP, R2M11_PRC_TEST_TE_INPUT_U16, PrcTestTEInputCtrl.val_u32);
        }
    }
    else
    {
        ErrCode = BC_ERR_TX_INPUTOUTOFRANGE;
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_TX_SetBinSearch(SYS_IPNum_e TXIP, TX_EnableBinarySearch_t *pEnableBinarySearch)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M11_RfCalMonitorCtrlUnion_t RfCalMonitorCtrl;

    if ((((TXIP >= e_SYS_TX1) && (TXIP <= e_SYS_TX3)) || (e_SYS_TXMC == TXIP)) && (pEnableBinarySearch != NULL))
    {
        // rf_cal_mon_iptat_gain and rf_cal_mon_ibg_gain are not used.
        RfCalMonitorCtrl.val_u32 = 0u; /*To set unused bits to 0*/
        RfCalMonitorCtrl.bits_st.PpdLox3BinSearchFromAbove = (uint8_t)pEnableBinarySearch->PpdLox3BinSearch;
        RfCalMonitorCtrl.bits_st.PpdPrBinSearchFromAbove = (uint8_t)pEnableBinarySearch->PpdPrBinSearch;
        RfCalMonitorCtrl.bits_st.PpdVgaBinSearchFromAbove = (uint8_t)pEnableBinarySearch->PpdVgaBinSearch;
        RfCalMonitorCtrl.bits_st.RfLox3BinSearchFromAbove = (uint8_t)pEnableBinarySearch->RfLox3BinSearch;
        RfCalMonitorCtrl.bits_st.RfPrBinSearchFromAbove = (uint8_t)pEnableBinarySearch->RfPrBinSearch;
        RfCalMonitorCtrl.bits_st.RfVgaBinSearchFromAbove = (uint8_t)pEnableBinarySearch->RfVgaBinSearch;
        RfCalMonitorCtrl.bits_st.PoutBinSearchFromAbove = (uint8_t)pEnableBinarySearch->PoutBinSearch;
        ErrCode = BC_SPI_Write(TXIP, R2M11_RF_CAL_MONITOR_CTRL_U16, RfCalMonitorCtrl.val_u32);
    }
    else
    {
        ErrCode = BC_ERR_TX_INPUTOUTOFRANGE;
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_TX_SetRFCalMonLevel(SYS_IPNum_e TXIP, float32_t LevelHighDelta, float32_t LevelLowDelta)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M11_CalMonLevelUnion_t CalMonLevel;
    uint8_t LevelHighDeltaCode = 0u;
    uint8_t LevelLowDeltaCode = 0u;
    if (((LevelLowDelta > 0.0f) && (LevelLowDelta <= TX_LEVEL_RF_MAXIMUM_DELTA)) && ((LevelHighDelta > 0.0f) && (LevelHighDelta <= TX_LEVEL_RF_MAXIMUM_DELTA)) && (((TXIP >= e_SYS_TX1) && (TXIP <= e_SYS_TX3)) || (TXIP == e_SYS_TXMC)))
    {
        LevelHighDeltaCode = (uint8_t)lroundf((LevelHighDelta / 0.29f) + 0.49f);
        LevelLowDeltaCode = (uint8_t)lroundf((LevelLowDelta / 0.29f) + 0.49f);
        CalMonLevel.val_u32 = 0u; /*To set unused bits to 0*/
        CalMonLevel.bits_st.LevelRfHighDelta = LevelHighDeltaCode;
        CalMonLevel.bits_st.LevelRfLowDelta = LevelLowDeltaCode;
        ErrCode = BC_SPI_Write(TXIP, R2M11_CAL_MON_LEVEL_U16, CalMonLevel.val_u32);
    }
    else
    {
        ErrCode = BC_ERR_TX_INPUTOUTOFRANGE;
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_TX_CalibrateTXPPD(SYS_IPNum_e TXIP, BOOL ReadCalibStatus, uint32_t CalCheckTimeOutUs)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M11_RfCalCtrlUnion_t RfCalControl;
    if (!(((TXIP >= e_SYS_TX1) && (TXIP <= e_SYS_TX3)) || (TXIP == e_SYS_TXMC)))
    {
        ErrCode = BC_ERR_TX_INPUTOUTOFRANGE;
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        RfCalControl.val_u32 = 0u; /*To set unused bits to 0*/
        RfCalControl.bits_st.PpdOffsetsCalStart = 1u;
        ErrCode = BC_SPI_Write(TXIP, R2M11_RF_CAL_CTRL_U16, RfCalControl.val_u32);
    }
    if ((CalCheckTimeOutUs != 0u) && (ErrCode == BC_ERR_NOERROR))
    {
        ErrCode = PLF_TM_Sleep(CalCheckTimeOutUs);
    }
    if ((ReadCalibStatus == TRUE) && (ErrCode == BC_ERR_NOERROR))
    {
        ErrCode = Helper_ES2_ReadTxCalibStatus(TXIP);
    }
    return ErrCode;
}

static BC_ERRCODE Helper_ES2_CalTXRFNullPntrCheck(SYS_EnableTxRfCalibration_t *pEnableTxRfCalibration, SYS_StoreInProfile_t *pStoreInProfile)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    if ((pStoreInProfile == NULL) || (pEnableTxRfCalibration == NULL))
    {
        ErrCode = BC_ERR_TX_PTR_ADDR_NULL;
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_CalTXRFRangeCheck(SYS_IPNum_e TXIP, SYS_EnableTxRfCalibration_t *pEnableTxRfCalibration, SYS_StoreInProfile_t *pStoreInProfile, SYS_ProfID_e CalibrateProfID, BOOL ReduceTransmisionForVGACalib)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    BOOL CheckStoreInProfile;
    ErrCode = Helper_ES2_CalTXRFNullPntrCheck(pEnableTxRfCalibration, pStoreInProfile);
    if (ErrCode == BC_ERR_NOERROR)
    {
        CheckStoreInProfile = (BOOL)((pStoreInProfile->Profile0) | (pStoreInProfile->Profile1) | (pStoreInProfile->Profile2) | (pStoreInProfile->Profile3) | (pStoreInProfile->Profile4) | (pStoreInProfile->Profile5) | (pStoreInProfile->Profile6) | (pStoreInProfile->Profile7) | (pStoreInProfile->Profile8));
        if (CheckStoreInProfile == FALSE)
        {
            ErrCode = BC_ERR_TX_NOSTOREINPROFILESELECTED;
        }
        if ((ReduceTransmisionForVGACalib == TRUE) && (pEnableTxRfCalibration->VgaCalStart == TRUE) && (pEnableTxRfCalibration->PoutCalStart == TRUE))
        {
            ErrCode = BC_ERR_TX_POUT_VGA_REDUCETX_NOTSUPPORTED;
        }
        if ((((TXIP < e_SYS_TX1) || (TXIP > e_SYS_TX3)) && (TXIP != e_SYS_TXMC)) || (CalibrateProfID > e_SYS_PROFILE_8))
        {
            ErrCode = BC_ERR_TX_INPUTOUTOFRANGE;
        }
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_VgaCalibWA(SYS_IPNum_e TXIP, SYS_EnableTxRfCalibration_t *pEnableTxRfCalibration, SYS_ProfID_e CalibrateProfID, BOOL ReduceTransmisionForVGACalib, BOOL *pBiasSettingChanged)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    BOOL SetZeroSt1Bias = FALSE;
    if (pEnableTxRfCalibration->VgaCalStart == TRUE)
    {
        if (ReduceTransmisionForVGACalib == TRUE)
        {
            SetZeroSt1Bias = TRUE;
            *pBiasSettingChanged = TRUE;
            ErrCode = Helper_ES2_SetSt1BiasCtrl(TXIP, SetZeroSt1Bias);
        }

        if (BC_ERR_NOERROR == ErrCode)
        { // TX RF VGA workaround
            BOOL ReadProfileReg = (pEnableTxRfCalibration->PrCalStart == FALSE) ? TRUE : FALSE;
            ErrCode = Helper_ES2_TxRfVgaCalibWA(TXIP, CalibrateProfID, ReadProfileReg);
        }
    }
    else
    {
        if (pEnableTxRfCalibration->PrCalStart == TRUE)
        {
            BOOL ReadProfileReg = FALSE;
            ErrCode = Helper_ES2_TxRfVgaCalibWA(TXIP, CalibrateProfID, ReadProfileReg);
        }
    }
    return ErrCode;
}

static BC_ERRCODE Helper_CheckCalibStatus(SYS_IPNum_e TXIP)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    uint32_t WhileLoopCount = 0u;
    do
    {
        ErrCode = PLF_TM_Sleep(TX_CHECK_CAL_RESULT_SLEEP);
        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = Helper_ES2_ReadTxCalibStatus(TXIP);
            if (WhileLoopCount > TX_CALIBRATION_TIMEOUT)
            {
                ErrCode = BC_ERR_TX_CALIB_TIMEOUT;
            }
        }
        WhileLoopCount++;
    } while ((ErrCode == BC_ERR_TX_CAL_BUSY) || (ErrCode == BC_ERR_TX1_CAL_BUSY) || (ErrCode == BC_ERR_TX2_CAL_BUSY) || (ErrCode == BC_ERR_TX3_CAL_BUSY));

    return ErrCode;
}

static BC_ERRCODE Helper_RestoreBiasCurrent(SYS_IPNum_e TXIP, BOOL ReadCalibStatus, BC_ERRCODE ErrCode)
{
    BC_ERRCODE LocalErrCode = BC_ERR_NOERROR;

    BOOL SetZeroSt1Bias = FALSE;
    if ((ErrCode == BC_ERR_TX_CAL_BUSY) || (ErrCode == BC_ERR_TX1_CAL_BUSY) || (ErrCode == BC_ERR_TX2_CAL_BUSY) || (ErrCode == BC_ERR_TX3_CAL_BUSY) || (ReadCalibStatus == FALSE))
    {
        LocalErrCode = Helper_CheckCalibStatus(TXIP);
    }
    /* Clearing the error code returned by previous function in case TX calibration status is not requested in API */
    if ((ReadCalibStatus == FALSE) && ((LocalErrCode >= BC_ERR_TX_CAL_ERROR) && (LocalErrCode <= BC_ERR_TX1_TX2_TX3_CAL_ERROR)))
    {
        LocalErrCode = BC_ERR_NOERROR;
    }

    /* Restore bias current */
    if(LocalErrCode != BC_ERR_TX_CALIB_TIMEOUT)
    {
        LocalErrCode = Helper_ES2_SetSt1BiasCtrl(TXIP, SetZeroSt1Bias);
    }
    return LocalErrCode;
}
BC_ERRCODE HAL_ES2_TX_CalibrateTXRF(SYS_IPNum_e TXIP, SYS_EnableTxRfCalibration_t *pEnableTxRfCalibration, SYS_StoreInProfile_t *pStoreInProfile, BOOL ReadCalibStatus, uint32_t CalCheckTimeOutUs, SYS_ProfID_e CalibrateProfID, BOOL ReduceTransmisionForVGACalib)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    BC_ERRCODE TmpErrCode = BC_ERR_NOERROR;
    R2M11_RfCalCtrlUnion_t RfCalControl;
    BOOL BiasSettingChanged = FALSE;

    ErrCode = Helper_ES2_CalTXRFRangeCheck(TXIP, pEnableTxRfCalibration, pStoreInProfile, CalibrateProfID, ReduceTransmisionForVGACalib);
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = Helper_ES2_VgaCalibWA(TXIP, pEnableTxRfCalibration, CalibrateProfID, ReduceTransmisionForVGACalib, &BiasSettingChanged);
    }

    if ((ErrCode == BC_ERR_NOERROR))
    {
        RfCalControl.val_u32 = 0u; /*To set unused bits to 0*/
        RfCalControl.bits_st.Lox3CalStart = (uint8_t)pEnableTxRfCalibration->Lox3CalStart;
        RfCalControl.bits_st.PoutCalStart = (uint8_t)pEnableTxRfCalibration->PoutCalStart;
        RfCalControl.bits_st.PrCalStart = (uint8_t)pEnableTxRfCalibration->PrCalStart;
        RfCalControl.bits_st.PrPhaseCalStart = (uint8_t)pEnableTxRfCalibration->PrPhaseCalStart;
        RfCalControl.bits_st.VgaCalStart = (uint8_t)pEnableTxRfCalibration->VgaCalStart;
        RfCalControl.bits_st.PpdOffsetsCalStart = (uint8_t)pEnableTxRfCalibration->PPDOffsetCalStart;
        RfCalControl.bits_st.StoreInProfile0 = (uint8_t)pStoreInProfile->Profile0;
        RfCalControl.bits_st.StoreInProfile1 = (uint8_t)pStoreInProfile->Profile1;
        RfCalControl.bits_st.StoreInProfile2 = (uint8_t)pStoreInProfile->Profile2;
        RfCalControl.bits_st.StoreInProfile3 = (uint8_t)pStoreInProfile->Profile3;
        RfCalControl.bits_st.StoreInProfile4 = (uint8_t)pStoreInProfile->Profile4;
        RfCalControl.bits_st.StoreInProfile5 = (uint8_t)pStoreInProfile->Profile5;
        RfCalControl.bits_st.StoreInProfile6 = (uint8_t)pStoreInProfile->Profile6;
        RfCalControl.bits_st.StoreInProfile7 = (uint8_t)pStoreInProfile->Profile7;
        RfCalControl.bits_st.StoreInProfile8 = (uint8_t)pStoreInProfile->Profile8;

        ErrCode = BC_SPI_Write(TXIP, R2M11_RF_CAL_CTRL_U16, RfCalControl.val_u32);
    }

    if ((CalCheckTimeOutUs != 0u) && (ErrCode == BC_ERR_NOERROR))
    {
        ErrCode = PLF_TM_Sleep(CalCheckTimeOutUs);
    }

    if ((ReadCalibStatus == TRUE) && (ErrCode == BC_ERR_NOERROR))
    {
        ErrCode = Helper_ES2_ReadTxCalibStatus(TXIP);
    }
    /* Return  error code not checked since bias current need to be restored*/
    if (BiasSettingChanged == TRUE)
    {
        TmpErrCode = Helper_RestoreBiasCurrent(TXIP, ReadCalibStatus, ErrCode);
        ErrCode = (TmpErrCode == BC_ERR_NOERROR) ? ErrCode : TmpErrCode;
    }
    return ErrCode;
}

static BC_ERRCODE Helper_ES2_TxMCSafetyCheckStatus(uint8_t *pCalStatusBusy, uint32_t *pCalStatusError)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    SYS_CalibrationStatus_t CalibrationStatus;
    uint32_t tmpCalStatusError;

    ErrCode = BC_ISM_GetCalibrationStatus(&CalibrationStatus, NULL);
    if (ErrCode == BC_ERR_NOERROR)
    {
        *pCalStatusBusy = ((CalibrationStatus.Tx1SafetyCalStatus == e_ISM_CAL_BUSY) || (CalibrationStatus.Tx2SafetyCalStatus == e_ISM_CAL_BUSY) || (CalibrationStatus.Tx3SafetyCalStatus == e_ISM_CAL_BUSY)) ? 1u : 0u;
        tmpCalStatusError = (CalibrationStatus.Tx1SafetyCalStatus == e_ISM_CAL_ERROR) ? 1u : 0u;
        tmpCalStatusError = (CalibrationStatus.Tx2SafetyCalStatus == e_ISM_CAL_ERROR) ? (tmpCalStatusError + 2u) : tmpCalStatusError;
        tmpCalStatusError = (CalibrationStatus.Tx3SafetyCalStatus == e_ISM_CAL_ERROR) ? (tmpCalStatusError + 4u) : tmpCalStatusError;
        *pCalStatusError = tmpCalStatusError;
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_TxSafetyCheckStatus(SYS_IPNum_e TXIP)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    SYS_CalibrationStatus_t CalibrationStatus;
    ISM_Cal_Status_e CalStatus = e_ISM_CAL_INVALID;

    ErrCode = BC_ISM_GetCalibrationStatus(&CalibrationStatus, NULL);
    if (ErrCode == BC_ERR_NOERROR)
    {
        if (TXIP == e_SYS_TX1)
        {
            CalStatus = CalibrationStatus.Tx1SafetyCalStatus;
        }
        if (TXIP == e_SYS_TX2)
        {
            CalStatus = CalibrationStatus.Tx2SafetyCalStatus;
        }
        if (TXIP == e_SYS_TX3)
        {
            CalStatus = CalibrationStatus.Tx3SafetyCalStatus;
        }
        if (CalStatus == e_ISM_CAL_BUSY)
        {
            ErrCode = BC_ERR_TX1_SAFETY_BUSY + ((uint32_t)TXIP - (uint32_t)e_SYS_TX1);
        }
        if (CalStatus == e_ISM_CAL_ERROR)
        {
            ErrCode = BC_ERR_TX_SAFETY_ERROR + ((uint32_t)1u << ((uint32_t)TXIP - (uint32_t)e_SYS_TX1));
        }
    }

    return ErrCode;
}
static BC_ERRCODE Helper_ES2_ReadSafetyCheckStatus(SYS_IPNum_e TXIP)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    uint8_t SafetyCalStatusBusy;
    uint32_t SafetyCalStatusError;

    if (TXIP == e_SYS_TXMC)
    {
        ErrCode = Helper_ES2_TxMCSafetyCheckStatus(&SafetyCalStatusBusy, &SafetyCalStatusError);
        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = (SafetyCalStatusBusy == TRUE) ? BC_ERR_TX_SAFETY_BUSY : (SafetyCalStatusError > 0u) ? (BC_ERR_TX_SAFETY_ERROR + SafetyCalStatusError)
                                                                                                          : BC_ERR_NOERROR;
        }
    }
    else
    {
        ErrCode = Helper_ES2_TxSafetyCheckStatus(TXIP);
    }
    return ErrCode;
}
BC_ERRCODE HAL_ES2_TX_StartTxPRSafetyCheck(SYS_IPNum_e TXIP, BOOL ReadCalibStatus, uint32_t SafetyCheckTimeOutUs)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M11_PrcFsmStartCtrlUnion_t PrcFsmStartCtrl;

    if (!(((TXIP >= e_SYS_TX1) && (TXIP <= e_SYS_TX3)) || (TXIP == e_SYS_TXMC)))
    {
        ErrCode = BC_ERR_TX_INPUTOUTOFRANGE;
    }

    if (ErrCode == BC_ERR_NOERROR)
    {
        // Reset value for register is 0u.
        PrcFsmStartCtrl.val_u32 = 0u; /*To set unused bits to 0*/
        PrcFsmStartCtrl.bits_st.StartSafetyCheck = 1u;
        ErrCode = BC_SPI_Write(TXIP, R2M11_PRC_FSM_START_CTRL_U16, PrcFsmStartCtrl.val_u32);
    }
    if ((SafetyCheckTimeOutUs != 0u) && (ErrCode == BC_ERR_NOERROR))
    {
        ErrCode = PLF_TM_Sleep(SafetyCheckTimeOutUs);
    }
    if ((ReadCalibStatus == TRUE) && (ErrCode == BC_ERR_NOERROR))
    {
        ErrCode = Helper_ES2_ReadSafetyCheckStatus(TXIP);
    }

    return ErrCode;
}

static ISM_Cal_Status_e Helper_ES2_GetISMCalStatus(uint8_t CalBusyFlag, uint8_t CalErrorFlag)
{
    ISM_Cal_Status_e CalStatus;
    CalStatus = (CalBusyFlag == TRUE) ? e_ISM_CAL_BUSY : ((CalErrorFlag == TRUE) ? e_ISM_CAL_ERROR : e_ISM_CAL_SUCCESS);
    return CalStatus;
}
static BC_ERRCODE Helper_ES2_GetLocalCalStatus(SYS_IPNum_e TXIP, TX_CalibrationStatus_t *pCalibStatus, uint32_t *pTxCalStatus)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    if (pCalibStatus == NULL)
    {
        ErrCode = BC_ERR_TX_PTR_ADDR_NULL;
    }
    if (((TXIP < e_SYS_TX1) || (TXIP > e_SYS_TX3)) && (ErrCode == BC_ERR_NOERROR))
    {
        ErrCode = BC_ERR_TX_INPUTOUTOFRANGE;
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_SPI_Read(TXIP, R2M11_TX_CAL_STATUS_U16, pTxCalStatus);
    }
    return ErrCode;
}
BC_ERRCODE HAL_ES2_TX_GetLocalCalibStatus(SYS_IPNum_e TXIP, BOOL SafetyCheck, TX_CalibrationStatus_t *pCalibStatus)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M11_TxCalStatusUnion_t CalibrationStatus;
    R2M11_PrcSafetyStatusUnion_t PrcSafetyStatus;
    CalibrationStatus.val_u32 = 0u;
    ErrCode = Helper_ES2_GetLocalCalStatus(TXIP, pCalibStatus, &CalibrationStatus.val_u32);
    if (ErrCode == BC_ERR_NOERROR)
    {
        /* Initializing with SUCCESS, gets updated if SafetyCheck is true.*/
        pCalibStatus->TxPrSafetyCheck = e_ISM_CAL_SUCCESS;
        pCalibStatus->TXCalibState = (uint8_t)CalibrationStatus.bits_st.TxCalibrationState;
        pCalibStatus->TXCalibBusy = (uint8_t)CalibrationStatus.bits_st.TxCalibBusy;
        pCalibStatus->PpdOffsetPrCal = Helper_ES2_GetISMCalStatus(CalibrationStatus.bits_st.PpdOffsetPrCalBusy, CalibrationStatus.bits_st.PpdOffsetPrCalWarning);
        pCalibStatus->PpdOffsetVgaCal = Helper_ES2_GetISMCalStatus(CalibrationStatus.bits_st.PpdOffsetVgaCalBusy, CalibrationStatus.bits_st.PpdOffsetVgaCalWarning);
        pCalibStatus->PpdOffsetLox3Cal = Helper_ES2_GetISMCalStatus(CalibrationStatus.bits_st.PpdOffsetLox3CalBusy, CalibrationStatus.bits_st.PpdOffsetLox3CalWarning);
        pCalibStatus->RfLox3Cal = Helper_ES2_GetISMCalStatus(CalibrationStatus.bits_st.RfLox3CalBusy, CalibrationStatus.bits_st.RfLox3CalWarning);
        pCalibStatus->RfPrCal = Helper_ES2_GetISMCalStatus(CalibrationStatus.bits_st.RfPrCalBusy, CalibrationStatus.bits_st.RfPrCalWarning);
        pCalibStatus->RfVgaCal = Helper_ES2_GetISMCalStatus(CalibrationStatus.bits_st.RfVgaCalBusy, CalibrationStatus.bits_st.RfVgaCalWarning);
        /*There is no warning flag for PR Phase*/
        pCalibStatus->RfPrPhaseCal = (CalibrationStatus.bits_st.RfPrPhaseCalBusy == TRUE) ? e_ISM_CAL_BUSY : ((CalibrationStatus.bits_st.RfPrPhaseCalDone == TRUE) ? e_ISM_CAL_SUCCESS : e_ISM_CAL_ERROR);
        pCalibStatus->PoutCal = Helper_ES2_GetISMCalStatus(CalibrationStatus.bits_st.PoutCalBusy, CalibrationStatus.bits_st.PoutCalWarning);
        if (SafetyCheck == TRUE)
        {
            ErrCode = BC_SPI_Read(TXIP, R2M11_PRC_SAFETY_STATUS_U16, &PrcSafetyStatus.val_u32);
            if (ErrCode == BC_ERR_NOERROR)
            {
                pCalibStatus->TxPrSafetyCheck = (PrcSafetyStatus.bits_st.SafetyBusy == 1u) ? e_ISM_CAL_BUSY : ((PrcSafetyStatus.bits_st.SafeFlagPrc == 0u) ? e_ISM_CAL_SUCCESS : e_ISM_CAL_ERROR);
            }
        }
    }

    return ErrCode;
}
static BC_ERRCODE Helper_ES2_CalibTimeRangeCheck(TX_CalibrationTime_t *pCalibTime)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    if (((pCalibTime->PoutDetCountThreshold <= 0.0f) || (pCalibTime->PoutDetCountThreshold > 6.375f)) ||
        ((pCalibTime->PPDDetCountThreshold <= 0.0f) || (pCalibTime->PPDDetCountThreshold > 6.375f)) ||
        ((pCalibTime->RFDetCountThreshold <= 0.0f) || (pCalibTime->RFDetCountThreshold > 6.375f)) ||
        ((pCalibTime->MonDetCountThreshold <= 0.0f) || (pCalibTime->MonDetCountThreshold > 6.375f)))
    {
        ErrCode = BC_ERR_TX_INPUTOUTOFRANGE;
    }
    return ErrCode;
}
BC_ERRCODE HAL_ES2_TX_ConfigCalibTime(SYS_IPNum_e TXIP, TX_CalibrationTime_t *pCalibTime)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M11_TxThresholdControlUnion_t TxThresholdControl;
    if (pCalibTime == NULL)
    {
        ErrCode = BC_ERR_TX_PTR_ADDR_NULL;
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = Helper_ES2_CalibTimeRangeCheck(pCalibTime);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        if (((TXIP >= e_SYS_TX1) && (TXIP <= e_SYS_TX3)) || (TXIP == e_SYS_TXMC))
        {
            TxThresholdControl.bits_st.DetCntThresholdPout = (uint8_t)SYS_CONVERT_TIMEUS_TO_40MHZCYCLE(pCalibTime->PoutDetCountThreshold);
            TxThresholdControl.bits_st.DetCntThresholdPpd = (uint8_t)SYS_CONVERT_TIMEUS_TO_40MHZCYCLE(pCalibTime->PPDDetCountThreshold);
            TxThresholdControl.bits_st.DetCntThresholdRf = (uint8_t)SYS_CONVERT_TIMEUS_TO_40MHZCYCLE(pCalibTime->RFDetCountThreshold);
            TxThresholdControl.bits_st.MonCntThreshold = (uint8_t)SYS_CONVERT_TIMEUS_TO_40MHZCYCLE(pCalibTime->MonDetCountThreshold);
            ErrCode = BC_SPI_Write(TXIP, R2M11_TX_THRESHOLD_CONTROL_U16, TxThresholdControl.val_u32);
        }
        else
        {
            ErrCode = BC_ERR_TX_INPUTOUTOFRANGE;
        }
    }
    return ErrCode;
}

static BC_ERRCODE Helper_ES2_CalTxMCCalibStatus(uint8_t *pCalStatusBusy, uint32_t *pCalStatusError)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    SYS_CalibrationStatus_t CalibrationStatus;
    uint32_t tmpCalStatusError;

    ErrCode = BC_ISM_GetCalibrationStatus(&CalibrationStatus, NULL);
    if (ErrCode == BC_ERR_NOERROR)
    {
        *pCalStatusBusy = ((CalibrationStatus.Tx1CalStatus == e_ISM_CAL_BUSY) || (CalibrationStatus.Tx2CalStatus == e_ISM_CAL_BUSY) || (CalibrationStatus.Tx3CalStatus == e_ISM_CAL_BUSY)) ? 1u : 0u;
        tmpCalStatusError = (CalibrationStatus.Tx1CalStatus == e_ISM_CAL_ERROR) ? 1u : 0u;
        tmpCalStatusError = (CalibrationStatus.Tx2CalStatus == e_ISM_CAL_ERROR) ? (tmpCalStatusError + 2u) : tmpCalStatusError;
        tmpCalStatusError = (CalibrationStatus.Tx3CalStatus == e_ISM_CAL_ERROR) ? (tmpCalStatusError + 4u) : tmpCalStatusError;
        *pCalStatusError = tmpCalStatusError;
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_CalTxCalibStatus(SYS_IPNum_e TXIP)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    SYS_CalibrationStatus_t CalibrationStatus;
    ISM_Cal_Status_e CalStatus = e_ISM_CAL_INVALID;

    ErrCode = BC_ISM_GetCalibrationStatus(&CalibrationStatus, NULL);
    if (ErrCode == BC_ERR_NOERROR)
    {
        if (TXIP == e_SYS_TX1)
        {
            CalStatus = CalibrationStatus.Tx1CalStatus;
        }
        if (TXIP == e_SYS_TX2)
        {
            CalStatus = CalibrationStatus.Tx2CalStatus;
        }
        if (TXIP == e_SYS_TX3)
        {
            CalStatus = CalibrationStatus.Tx3CalStatus;
        }
        if (CalStatus == e_ISM_CAL_BUSY)
        {
            ErrCode = BC_ERR_TX1_CAL_BUSY + ((uint32_t)TXIP - (uint32_t)e_SYS_TX1);
        }
        if (CalStatus == e_ISM_CAL_ERROR)
        {
            ErrCode = BC_ERR_TX_CAL_ERROR + ((uint32_t)1u << ((uint32_t)TXIP - (uint32_t)e_SYS_TX1));
        }
    }

    return ErrCode;
}
static BC_ERRCODE Helper_ES2_ReadTxCalibStatus(SYS_IPNum_e TXIP)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    uint8_t CalStatusBusy;
    uint32_t CalStatusError;

    if (TXIP == e_SYS_TXMC)
    {
        ErrCode = Helper_ES2_CalTxMCCalibStatus(&CalStatusBusy, &CalStatusError);
        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = (uint32_t)((CalStatusBusy == TRUE) ? BC_ERR_TX_CAL_BUSY : ((CalStatusError > 0u) ? (BC_ERR_TX_CAL_ERROR + CalStatusError) : BC_ERR_NOERROR));
        }
    }
    else
    {
        ErrCode = Helper_ES2_CalTxCalibStatus(TXIP);
    }
    return ErrCode;
}

static BC_ERRCODE Helper_ES2_LvlRFMinRangeCheck(SYS_IPNum_e TXIP, float32_t LevelRfMin)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    if ((((TXIP < e_SYS_TX1) || (TXIP > e_SYS_TX3)) && (TXIP != e_SYS_TXMC)) || (LevelRfMin > TX_LEVEL_MAXIMUM_TARGET_POWER) || (LevelRfMin < TX_LEVEL_MINIMUM_TARGET_POWER))
    {
        ErrCode = BC_ERR_TX_INPUTOUTOFRANGE;
    }
    return ErrCode;
}
static BOOL Helper_ES2_LvlRFMinValCheck(uint32_t Tx1Val, uint32_t Tx2Val, uint32_t Tx3Val)
{
    BOOL SameFlag = FALSE;
    if ((Tx1Val == Tx2Val) && (Tx1Val == Tx3Val))
    {
        SameFlag = TRUE;
    }
    return SameFlag;
}

static BC_ERRCODE Helper_ES2_GetTXFunSafeOTPRegVal(uint8_t LevelRfMinCode, uint16_t Offset, const OTP_TableDescrip_t *pTableBase, uint32_t *pTxFunSafeVal)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    uint32_t TrimTxThreshOTP = 0u;
    uint32_t MaskTx = 0u;
    uint32_t MaskAnchorTx = 0u;
    uint32_t PosTx = 0u;
    uint32_t PosAnchorTx = 0u;
    uint8_t TxAnchor = 0u;
    uint8_t LevelRfMinCodeTemp = 0u;
    R2M11_FuncsafeMonLevelSettingsUnion_t FuncsafeMonLevelSettings;

    MaskTx = pTableBase[OTP_LEVEL_RF_MAX_SPI_TX1_INDEX].SrcMsk;
    PosTx = pTableBase[OTP_LEVEL_RF_MAX_SPI_TX1_INDEX].SrcPos;
    MaskAnchorTx = pTableBase[OTP_ANCHOR_POINT_TX1_INDEX].SrcMsk;
    PosAnchorTx = pTableBase[OTP_ANCHOR_POINT_TX1_INDEX].SrcPos;
    ErrCode = HAL_ES2_OTP_GetOTPRegValue(Offset, &TrimTxThreshOTP);
    if (ErrCode == BC_ERR_NOERROR)
    {
        TxAnchor = (uint8_t)((TrimTxThreshOTP & MaskAnchorTx) >> PosAnchorTx);
        if ((LevelRfMinCode + TxAnchor) >= TX_LEVEL_CODE_MAX)
        {
            LevelRfMinCodeTemp = (LevelRfMinCode + TxAnchor) % TX_LEVEL_CODE_MAX;
            FuncsafeMonLevelSettings.val_u32 = 0u;
            FuncsafeMonLevelSettings.bits_st.LevelRfMaxSpi = (uint8_t)((TrimTxThreshOTP & MaskTx) >> PosTx);
            FuncsafeMonLevelSettings.bits_st.LevelRfMinSpi = LevelRfMinCodeTemp;
            *pTxFunSafeVal = FuncsafeMonLevelSettings.val_u32;
        }
        else
        {
            ErrCode = BC_ERR_TX_RF_MIN_CODE_OUTOFRANGE;
        }
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_GetFunSafeOTPRegVal(SYS_IPNum_e TXIP, float32_t LevelRfMin, uint32_t *pTx1FunSafeVal, uint32_t *pTx2FunSafeVal, uint32_t *pTx3FunSafeVal, uint32_t *pFunSafeVal)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    uint8_t LevelRfMinCode = 0u;
    uint8_t LevelRfMinCodeMax = 63u;

    LevelRfMinCode = LevelRfMinCodeMax - (uint8_t)lroundf((15.0f - LevelRfMin) / 0.29f);

    if ((TXIP == e_SYS_TXMC) || (TXIP == e_SYS_TX1))
    {
        ErrCode = Helper_ES2_GetTXFunSafeOTPRegVal(LevelRfMinCode, OTP_TRIM_TX1_THRESH_INDEX, OtpTrimTx1Thresh, pTx1FunSafeVal);
        *pFunSafeVal = *pTx1FunSafeVal;
    }
    if ((BC_ERR_NOERROR == ErrCode) && ((TXIP == e_SYS_TXMC) || (TXIP == e_SYS_TX2)))
    {
        ErrCode = Helper_ES2_GetTXFunSafeOTPRegVal(LevelRfMinCode, OTP_TRIM_TX2_THRESH_INDEX, OtpTrimTx2Thresh, pTx2FunSafeVal);
        *pFunSafeVal = *pTx2FunSafeVal;
    }
    if ((BC_ERR_NOERROR == ErrCode) && ((TXIP == e_SYS_TXMC) || (TXIP == e_SYS_TX3)))
    {
        ErrCode = Helper_ES2_GetTXFunSafeOTPRegVal(LevelRfMinCode, OTP_TRIM_TX3_THRESH_INDEX, OtpTrimTx3Thresh, pTx3FunSafeVal);
        *pFunSafeVal = *pTx3FunSafeVal;
    }
    return ErrCode;
}
BC_ERRCODE HAL_ES2_TX_SetLevelRfMin(SYS_IPNum_e TXIP, float32_t LevelRfMin)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    uint32_t FuncsafeMonLevelSettings = 0u;
    uint32_t Tx1FunSafeVal32 = 0u;
    uint32_t Tx2FunSafeVal32 = 0u;
    uint32_t Tx3FunSafeVal32 = 0u;
    ErrCode = Helper_ES2_LvlRFMinRangeCheck(TXIP, LevelRfMin);
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = Helper_ES2_GetFunSafeOTPRegVal(TXIP, LevelRfMin, &Tx1FunSafeVal32, &Tx2FunSafeVal32, &Tx3FunSafeVal32, &FuncsafeMonLevelSettings);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        if (TXIP == e_SYS_TXMC)
        {
            if (Helper_ES2_LvlRFMinValCheck(Tx1FunSafeVal32, Tx2FunSafeVal32, Tx3FunSafeVal32) == TRUE)
            {
                ErrCode = BC_SPI_Write(e_SYS_TXMC, R2M11_FUNCSAFE_MON_LEVEL_SETTINGS_U16, Tx1FunSafeVal32);
            }
            else
            {
                ErrCode = BC_SPI_Write(e_SYS_TX1, R2M11_FUNCSAFE_MON_LEVEL_SETTINGS_U16, Tx1FunSafeVal32);
                if (BC_ERR_NOERROR == ErrCode)
                {
                    ErrCode = BC_SPI_Write(e_SYS_TX2, R2M11_FUNCSAFE_MON_LEVEL_SETTINGS_U16, Tx2FunSafeVal32);
                }
                if (BC_ERR_NOERROR == ErrCode)
                {
                    ErrCode = BC_SPI_Write(e_SYS_TX3, R2M11_FUNCSAFE_MON_LEVEL_SETTINGS_U16, Tx3FunSafeVal32);
                }
            }
        }
        else
        {
            ErrCode = BC_SPI_Write(TXIP, R2M11_FUNCSAFE_MON_LEVEL_SETTINGS_U16, FuncsafeMonLevelSettings);
        }
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_TXGetSafeMaxTarget(uint8_t *pTxSafeTarget, uint16_t Offset, const OTP_TableDescrip_t *pTableBase, uint8_t BackOffCode)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    uint8_t TxFuncsafeMonLevelMaxSpi;
    uint8_t TxAnchor;
    /* Maximum value for 6 bits*/
    uint8_t TxMaxTarget = TX_LEVEL_CODE_MAX - (uint8_t)1u;
    uint32_t TrimTxThreshOTP = 0u;
    uint32_t MaskTx = 0u;
    uint32_t PosTx = 0u;
    uint32_t MaskAnchorTx = 0u;
    uint32_t PosAnchorTx = 0u;

    MaskTx = pTableBase[OTP_LEVEL_RF_MAX_SPI_TX1_INDEX].SrcMsk;
    PosTx = pTableBase[OTP_LEVEL_RF_MAX_SPI_TX1_INDEX].SrcPos;
    MaskAnchorTx = pTableBase[OTP_ANCHOR_POINT_TX1_INDEX].SrcMsk;
    PosAnchorTx = pTableBase[OTP_ANCHOR_POINT_TX1_INDEX].SrcPos;
    ErrCode = HAL_ES2_OTP_GetOTPRegValue(Offset, &TrimTxThreshOTP);
    if (ErrCode == BC_ERR_NOERROR)
    {
        TxFuncsafeMonLevelMaxSpi = (uint8_t)((TrimTxThreshOTP & MaskTx) >> PosTx);
        TxAnchor = (uint8_t)((TrimTxThreshOTP & MaskAnchorTx) >> PosAnchorTx);
        /*  maxtarget is MIN(63, 64 - (anchor-max)) */
        if (TxAnchor > TxFuncsafeMonLevelMaxSpi)
        {
            TxMaxTarget = TX_LEVEL_CODE_MAX - (TxAnchor - TxFuncsafeMonLevelMaxSpi);
        }

        *pTxSafeTarget = TxMaxTarget - BackOffCode;
    }

    return ErrCode;
}
static BC_ERRCODE Helper_ES2_GetSafeMaxTarget(SYS_IPNum_e TXIP, uint8_t *pTx1SafeTarget, uint8_t *pTx2SafeTarget, uint8_t *pTx3SafeTarget, uint8_t BackOffCode)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    uint8_t TxSafeTarget = 0u;

    if ((TXIP == e_SYS_TXMC) || (TXIP == e_SYS_TX1))
    {
        ErrCode = Helper_ES2_TXGetSafeMaxTarget(&TxSafeTarget, OTP_TRIM_TX1_THRESH_INDEX, OtpTrimTx1Thresh, BackOffCode);
        *pTx1SafeTarget = TxSafeTarget;
    }
    if ((BC_ERR_NOERROR == ErrCode) && ((TXIP == e_SYS_TXMC) || (TXIP == e_SYS_TX2)))
    {
        ErrCode = Helper_ES2_TXGetSafeMaxTarget(&TxSafeTarget, OTP_TRIM_TX2_THRESH_INDEX, OtpTrimTx2Thresh, BackOffCode);
        *pTx2SafeTarget = TxSafeTarget;
    }
    if ((BC_ERR_NOERROR == ErrCode) && ((TXIP == e_SYS_TXMC) || (TXIP == e_SYS_TX3)))
    {
        ErrCode = Helper_ES2_TXGetSafeMaxTarget(&TxSafeTarget, OTP_TRIM_TX3_THRESH_INDEX, OtpTrimTx3Thresh, BackOffCode);
        *pTx3SafeTarget = TxSafeTarget;
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_TX_SetMaxSafePOutTarget(SYS_ProfID_e ProfID, SYS_IPNum_e TXIP, uint8_t BackOffCode)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M11_AmpSettingsProfile0Union_t AmpSettings;
    uint8_t Tx1SafeTarget = 0u;
    uint8_t Tx3SafeTarget = 0u;
    uint8_t Tx2SafeTarget = 0u;

    if ((((TXIP < e_SYS_TX1) || (TXIP > e_SYS_TX3)) && (TXIP != e_SYS_TXMC)) || (ProfID > e_SYS_PROFILE_8) || (BackOffCode >= 0x40u))
    {
        ErrCode = BC_ERR_TX_INPUTOUTOFRANGE;
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = Helper_ES2_GetSafeMaxTarget(TXIP, &Tx1SafeTarget, &Tx2SafeTarget, &Tx3SafeTarget, BackOffCode);
    }
    if ((TXIP == e_SYS_TXMC) && (BC_ERR_NOERROR == ErrCode))
    {
        if ((Tx1SafeTarget == Tx2SafeTarget) && (Tx1SafeTarget == Tx3SafeTarget))
        {
            AmpSettings.val_u32 = 0u; /*To set unused bits to 0*/
            AmpSettings.bits_st.TxPowerTargetProfile0 = Tx1SafeTarget;
            ErrCode = BC_SPI_Write(TXIP, (R2M11_AMP_SETTINGS_PROFILE0_U16 + ((uint16_t)ProfID * 8u)), AmpSettings.val_u32);
        }
        else
        {
            AmpSettings.val_u32 = 0u; /*To set unused bits to 0*/
            AmpSettings.bits_st.TxPowerTargetProfile0 = Tx1SafeTarget;
            ErrCode = BC_SPI_Write(e_SYS_TX1, (R2M11_AMP_SETTINGS_PROFILE0_U16 + ((uint16_t)ProfID * 8u)), AmpSettings.val_u32);
            if (BC_ERR_NOERROR == ErrCode)
            {
                AmpSettings.bits_st.TxPowerTargetProfile0 = Tx2SafeTarget;
                ErrCode = BC_SPI_Write(e_SYS_TX2, (R2M11_AMP_SETTINGS_PROFILE0_U16 + ((uint16_t)ProfID * 8u)), AmpSettings.val_u32);
            }
            if (BC_ERR_NOERROR == ErrCode)
            {
                AmpSettings.bits_st.TxPowerTargetProfile0 = Tx3SafeTarget;
                ErrCode = BC_SPI_Write(e_SYS_TX3, (R2M11_AMP_SETTINGS_PROFILE0_U16 + ((uint16_t)ProfID * 8u)), AmpSettings.val_u32);
            }
        }
    }
    else
    {
        if (BC_ERR_NOERROR == ErrCode)
        {
            if (TXIP == e_SYS_TX1)
            {
                AmpSettings.val_u32 = 0u; /*To set unused bits to 0*/
                AmpSettings.bits_st.TxPowerTargetProfile0 = Tx1SafeTarget;
            }
            if (TXIP == e_SYS_TX2)
            {
                AmpSettings.val_u32 = 0u; /*To set unused bits to 0*/
                AmpSettings.bits_st.TxPowerTargetProfile0 = Tx2SafeTarget;
            }
            if (TXIP == e_SYS_TX3)
            {
                AmpSettings.val_u32 = 0u; /*To set unused bits to 0*/
                AmpSettings.bits_st.TxPowerTargetProfile0 = Tx3SafeTarget;
            }
            ErrCode = BC_SPI_Write(TXIP, (R2M11_AMP_SETTINGS_PROFILE0_U16 + ((uint16_t)ProfID * 8u)), AmpSettings.val_u32);
        }
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_TX_GetProfileCurrGain(SYS_IPNum_e TXIP, SYS_ProfID_e ProfID, uint8_t *pTxCurrGain)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M11_TxCurrGainProfile0Union_t TxCurrGainCtrl;
    uint16_t AddrTxCurrGainProfReg;

    if ((ProfID <= e_SYS_PROFILE_8) && (TXIP >= e_SYS_TX1) && (TXIP <= e_SYS_TX3) && (pTxCurrGain != NULL))
    {
        /*Note: Based on profile, the register address changes.
        For all profiles the underlying structure is of same type; with different names"*/
        AddrTxCurrGainProfReg = R2M11_TX_CURR_GAIN_PROFILE0_U16 + ((uint16_t)ProfID * 8u);
        ErrCode = BC_SPI_Read(TXIP, AddrTxCurrGainProfReg, &TxCurrGainCtrl.val_u32);
        if (ErrCode == BC_ERR_NOERROR)
        {
            /*As TXGain is of uint8_t type; no need for check the range */
            *pTxCurrGain = TxCurrGainCtrl.bits_st.TxCurrGainCtrlProfile0;
        }
    }
    else
    {
        ErrCode = BC_ERR_TX_INPUTOUTOFRANGE;
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_TX_AdjustTXRFCurrentGain(SYS_IPNum_e TXIP, SYS_ProfID_e CalibrateProfID, SYS_TXErrors_t *pTxErr, uint8_t PercntCurGainAdj, uint8_t PercntgBiasCurGainAdj, SYS_StoreInProfile_t *pStoreInProfile, uint8_t *pTxCurrGain)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    if ((pTxCurrGain == NULL) || (pTxErr == NULL) || (PercntCurGainAdj >= 100u) || (PercntgBiasCurGainAdj >= 100u) ||
        (CalibrateProfID > e_SYS_PROFILE_8) || (TXIP < e_SYS_TX1) || (TXIP > e_SYS_TX3) || (pStoreInProfile == NULL))
    {
        ErrCode = BC_ERR_TX_INPUTOUTOFRANGE;
    }
    else
    {
        BOOL CheckStoreInProfile = (BOOL)((pStoreInProfile->Profile0) | (pStoreInProfile->Profile1) | (pStoreInProfile->Profile2) | (pStoreInProfile->Profile3) | (pStoreInProfile->Profile4) | (pStoreInProfile->Profile5) | (pStoreInProfile->Profile6) | (pStoreInProfile->Profile7) | (pStoreInProfile->Profile8));
        if (CheckStoreInProfile == FALSE)
        {
            ErrCode = BC_ERR_TX_NOSTOREINPROFILESELECTED;
        }
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = Helper_GetAdjustedCurGain(pTxErr, PercntCurGainAdj, PercntgBiasCurGainAdj, pTxCurrGain);
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = Helper_CopyTXRFCurrentGain(TXIP, CalibrateProfID, pStoreInProfile, *pTxCurrGain);
    }

    return ErrCode;
}

BC_ERRCODE HAL_ES2_TX_GetBPSKPhaseStatus(SYS_IPNum_e TXIP, TX_BPSKPhaseStatus_e *pTxBPSKPhaseStatus)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M11_PhaseshifterStatusUnion_t PhaseshifterStatus;
    if ((pTxBPSKPhaseStatus == NULL) || (TXIP < e_SYS_TX1) || (TXIP > e_SYS_TX3))
    {
        ErrCode = BC_ERR_TX_INPUTOUTOFRANGE;
    }
    else
    {
        *pTxBPSKPhaseStatus = e_TX_BPSK_PHASE_STATUS_INVALID;
        ErrCode = BC_SPI_Read(TXIP, R2M11_PHASESHIFTER_STATUS_U16, &PhaseshifterStatus.val_u32);
        if (BC_ERR_NOERROR == ErrCode)
        {            
            switch (PhaseshifterStatus.bits_st.PsB1B0Rb)
            {
            case 0x0u:
                *pTxBPSKPhaseStatus = e_TX_BPSK_PHASE_STATUS_OFF;
                break;
            case 0x1u:
                *pTxBPSKPhaseStatus = e_TX_BPSK_PHASE_STATUS_ONE_EIGHTY_DEGREE;
                break;
            case 0x2u:
                *pTxBPSKPhaseStatus = e_TX_BPSK_PHASE_STATUS_ZERO_DEGREE;
                break;
            default:
                *pTxBPSKPhaseStatus = e_TX_BPSK_PHASE_STATUS_RESERVED;
                break;
            }
        }
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_TX_ConfigBBD(SYS_IPNum_e TXIP, BOOL EnableBBDTX, BOOL NormalSensitivity, BOOL Grounded)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M11_BbdControlUnion_t txBbdCtl;
    uint32_t tx1BbdCtl = 0u;
    uint32_t tx2BbdCtl = 0u;
    uint32_t tx3BbdCtl = 0u;
    SYS_IPList_t AppConfig = {FALSE};
    uint8_t Count = 0u;

    ErrCode = BC_CC_GetAppConfiguration(&AppConfig, NULL);
    txBbdCtl.val_u32 = 0u;
    txBbdCtl.bits_st.BbEnSpi = EnableBBDTX;
    txBbdCtl.bits_st.BbIdetectSpi = NormalSensitivity;
    txBbdCtl.bits_st.BbGroundedSpi = Grounded;
    if ((TXIP >= e_SYS_TX1) && (TXIP <= e_SYS_TX3) && (BC_ERR_NOERROR == ErrCode))
    {
        ErrCode = BC_SPI_WriteCheck(TXIP, R2M11_BBD_CONTROL_U16, txBbdCtl.val_u32);
    }
    else if ((TXIP == e_SYS_TXMC) && (BC_ERR_NOERROR == ErrCode))
    {
        ErrCode = BC_SPI_Write(TXIP, R2M11_BBD_CONTROL_U16, txBbdCtl.val_u32);
        if ((TRUE == AppConfig.TX1) && (BC_ERR_NOERROR == ErrCode))
        {
            ErrCode = BC_SPI_Read(e_SYS_TX1, R2M11_BBD_CONTROL_U16, &tx1BbdCtl);
            if (txBbdCtl.val_u32 != tx1BbdCtl)
            {
                Count = 1u;
            }
        }
        if ((TRUE == AppConfig.TX2) && (BC_ERR_NOERROR == ErrCode))
        {
            ErrCode = BC_SPI_Read(e_SYS_TX2, R2M11_BBD_CONTROL_U16, &tx2BbdCtl);
            if (txBbdCtl.val_u32 != tx2BbdCtl)
            {
                Count = Count + 2u;
            }
        }
        if ((TRUE == AppConfig.TX3) && (BC_ERR_NOERROR == ErrCode))
        {
            ErrCode = BC_SPI_Read(e_SYS_TX3, R2M11_BBD_CONTROL_U16, &tx3BbdCtl);
            if (txBbdCtl.val_u32 != tx3BbdCtl)
            {
                Count = Count + 4u;
            }
        }

        if (BC_ERR_NOERROR == ErrCode)
        {
            if (Count != 0u)
            {
                ErrCode = BC_ERR_TX_BBD_ENABLE_WRITECHECK_BASE + Count;
            }
        }
    }
    else
    {
        ErrCode = BC_ERR_TX_INPUTOUTOFRANGE;
    }
    return ErrCode;
}

static BC_ERRCODE Helper_GetAdjustedCurGain(SYS_TXErrors_t *pTxErr, uint8_t PercntCurGainAdj, uint8_t PercntgBiasCurGainAdj, uint8_t *pTxCurrGain)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    float32_t TmpTxCurrGain;
    uint8_t LocalCurrGain = *pTxCurrGain;
    /* In case max and/or High error reduce the gain code */
    if ((pTxErr->TxRfLevelMaxErr == TRUE) || ((pTxErr->TxRfLevelHighErr == TRUE) && (pTxErr->TxRfLevelLowErr == FALSE)))
    {
        TmpTxCurrGain = (float32_t)((100.0f - (float32_t)PercntCurGainAdj) * 0.01f);
        *pTxCurrGain = (uint8_t)lroundf((float32_t)LocalCurrGain * TmpTxCurrGain);
    }
    else
    {
        /* In case Low warning increase the gain code */
        if ((pTxErr->TxRfLevelHighErr == FALSE) && (pTxErr->TxRfLevelLowErr == TRUE))
        {
            TmpTxCurrGain = (float32_t)((100.0f + (float32_t)PercntCurGainAdj) * 0.01f);
            TmpTxCurrGain = (float32_t)LocalCurrGain * TmpTxCurrGain;
            *pTxCurrGain = (TmpTxCurrGain > TX_MAX_CURRENT_GAIN_CODE_FLOAT) ? TX_MAX_CURRENT_GAIN_CODE_UINT8 : (uint8_t)TmpTxCurrGain;
        }
        /* In case of no error/warnings increase the gain code by small amount to get closer to max power */
        if ((pTxErr->TxRfLevelHighErr == FALSE) && (pTxErr->TxRfLevelLowErr == FALSE))
        {
            TmpTxCurrGain = (float32_t)((100.0f + (float32_t)PercntgBiasCurGainAdj) * 0.01f);
            TmpTxCurrGain = (float32_t)LocalCurrGain * TmpTxCurrGain;
            *pTxCurrGain = (TmpTxCurrGain > TX_MAX_CURRENT_GAIN_CODE_FLOAT) ? TX_MAX_CURRENT_GAIN_CODE_UINT8 : (uint8_t)TmpTxCurrGain;
        }
        // in case high and low both error true do nothing
    }
    return ErrCode;
}

static void Helper_StoreInProfile(SYS_StoreInProfile_t *pStoreInProfile, BOOL pProfile[SYS_MAX_PROFILE_COUNT])
{
    pProfile[0] = pStoreInProfile->Profile0;
    pProfile[1] = pStoreInProfile->Profile1;
    pProfile[2] = pStoreInProfile->Profile2;
    pProfile[3] = pStoreInProfile->Profile3;
    pProfile[4] = pStoreInProfile->Profile4;
    pProfile[5] = pStoreInProfile->Profile5;
    pProfile[6] = pStoreInProfile->Profile6;
    pProfile[7] = pStoreInProfile->Profile7;
    pProfile[8] = pStoreInProfile->Profile8;
}

static BC_ERRCODE Helper_CopyTXRFCurrentGain(SYS_IPNum_e TXIP, SYS_ProfID_e CalibrateProfID, SYS_StoreInProfile_t *pStoreInProfile, uint8_t TxCurrGain)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M11_TxCurrGainProfile0Union_t TxCurrGainCtrl;
    uint16_t AddrTxCurrGainProfReg;
    BOOL Profile[SYS_MAX_PROFILE_COUNT];
    uint8_t ProfileCount;

    (void)Helper_StoreInProfile(pStoreInProfile, &Profile[0]);

    /*Note: Based on profile, the register address changes.
    For all profiles the underlying structure is of same type; with different names"*/
    AddrTxCurrGainProfReg = R2M11_TX_CURR_GAIN_PROFILE0_U16 + ((uint16_t)CalibrateProfID * (R2M11_TX_CURR_GAIN_PROFILE1_U16 - R2M11_TX_CURR_GAIN_PROFILE0_U16));
    ErrCode = BC_SPI_Read(TXIP, AddrTxCurrGainProfReg, &TxCurrGainCtrl.val_u32);
    if (ErrCode == BC_ERR_NOERROR)
    {
        /*As TXGain is of uint8_t type; no need for check the range */
        TxCurrGainCtrl.bits_st.TxCurrGainCtrlProfile0 = TxCurrGain;
    }
    for (ProfileCount = 0u; ProfileCount < SYS_MAX_PROFILE_COUNT; ProfileCount++)
    {
        if ((Profile[ProfileCount] == TRUE) && (ErrCode == BC_ERR_NOERROR))
        {
            AddrTxCurrGainProfReg = R2M11_TX_CURR_GAIN_PROFILE0_U16 + ((uint16_t)ProfileCount * (R2M11_TX_CURR_GAIN_PROFILE1_U16 - R2M11_TX_CURR_GAIN_PROFILE0_U16));
            ErrCode = BC_SPI_Write(TXIP, AddrTxCurrGainProfReg, TxCurrGainCtrl.val_u32);
        }
    }
    return ErrCode;
}
#endif
