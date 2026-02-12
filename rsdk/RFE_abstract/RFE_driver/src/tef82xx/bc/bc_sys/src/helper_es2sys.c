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
#include "bc_conf.h"
#include "bc_err.h"
#include "bc_spi.h"
#include "bc_conf.h"
#include "bc_te.h"
#include "bc_tx.h"
#include "bc_rx.h"
#include "bc_ism.h"
#include "bc_cc.h"
#include "bc_sc.h"
#include "bc_loi.h"
#include "bc_mipi.h"
#include "bc_mclk.h"
#include "bc_lvds.h"
#include "bc_cafc.h"
#include "bc_otp.h"
#include "bc_adc.h"
#include "bc_sysinit.h"
#include "plf.h"
#ifdef BUILD_FOR_VAL
// register headers
#include "v_es2_cc.h"
#include "v_es2_cafc.h"
#include "v_es2_loi.h"
#include "v_es2_rx.h"
#include "v_es2_tx.h"
#include "v_es2_ism.h"
#include "v_es2_sc.h"
#include "v_es2_te.h"
#include "v_es2_mclk.h"
#include "v_es2_adc.h"
#else
#include "reg_es2_cc.h"
#include "reg_es2_cafc.h"
#include "reg_es2_loi.h"
#include "reg_es2_rx.h"
#include "reg_es2_tx.h"
#include "reg_es2_ism.h"
#include "reg_es2_sc.h"
#include "reg_es2_te.h"
#include "reg_es2_mipi.h"
#include "reg_es2_mclk.h"
#include "reg_es2_adc.h"
#endif
#include "bc_sys.h"
#include "helper_es2sys.h"
static BC_ERRCODE Helper_ES2_ConfigureSerialInterface(SYS_IPList_t *pAppConfig);
static BC_ERRCODE Helper_ES2_CheckErrorN(void);
static BC_ERRCODE Helper_ES2_EnableTxCtrl(SYS_IPList_t *pAppConfig, BOOL EnableTX, BOOL SwitchTX);
static BC_ERRCODE Helper_ES2_Monitor_RTMWriteTxErr(uint32_t TxErrorMonU32);
static BC_ERRCODE Helper_ES2_Monitor_TxRfMinErr(void);
static BC_ERRCODE Helper_ES2_Monitor_RTMReadTxErr(uint32_t *TxErrorMonU32);
static BC_ERRCODE Helper_ES2_ReadCAFCTemperature(float32_t *pKelvinChirp);
static BC_ERRCODE Helper_ES2_ReadTxTemperature(float32_t *pKelvinTX1, float32_t *pKelvinTX2, float32_t *pKelvinTX3);
static BC_ERRCODE Helper_ES2_ConfigMCLKClkDetector(MCLK_CLKDetMode_e CLKDetMode);
static BC_ERRCODE Helper_ES2_EnableMSPCPFDSupply(void);
static BC_ERRCODE Helper_ES2_RestoreTERegs(uint32_t RestoreChirpSequenceCtrl, BOOL UseStoredChirpTrigger, uint32_t StoredChirpTriggerMode, uint32_t StoreTxPrDelayControl, uint32_t RestoreCSeqInterval, uint32_t StoredChirpGlblReg, BC_ERRCODE InputErrCode);
static BC_ERRCODE Helper_ES2_ReduceSeqIntervalTime(SYS_ProfID_e ChirpProfSel, uint16_t NumChirp, uint32_t *pStoreTxPrDelayControl, uint32_t *pRestoreCSeqInterval, uint32_t *pStoredChirpGlblReg);
static BC_ERRCODE Helper_ES2_DisableTxRxLo(uint32_t *pStoredIpLevelPonEnable);
static BC_ERRCODE Helper_ES2_RestoreTxRxLo(uint32_t StoredIpLevelPonEnable);
static BC_ERRCODE Helper_ES2_CheckVcoLevelMinErr(void);
static BC_ERRCODE Helper_ES2_CheckPLLUnlockErr(void);
static BC_ERRCODE Helper_ES2_TrigChirpCheckErr(void);
static BC_ERRCODE Helper_ES2_RestoreDynPwrCntrl(BOOL DynPowModeRegUpdated, uint32_t DynamicPowerControlU32);
static BC_ERRCODE Helper_ES2_DisbleDynPwrCntrl(SYS_IPList_t *pAppConfig, BOOL *pDynPowModeRegUpdated, uint32_t *DynamicPowerControlU32);
static BC_ERRCODE Helper_ES2_SetCalMonMaxOffsetErr(BOOL EnADC12, BOOL EnADC34);
static BC_ERRCODE Helper_TXPRSafetyCheckDefaults(void);
static BC_ERRCODE Helper_ES2_CheckTxIntegrity(SYS_IPList_t *pAppConfig, BOOL *pTxSenIntegrityOK);
static BC_ERRCODE Helper_ES2_RevertIntegChkChange(SYS_IPList_t *pAppConfig, uint32_t TxErrorMonU32, BOOL DynPowModeRegUpdated, uint32_t DynamicPowerControlU32, BOOL TxSenIntegrityOK);
static BC_ERRCODE Helper_ES2_CheckTxErr(SYS_IPList_t *pAppConfig, BOOL CheckFlag, BOOL *pTxSenIntegrityOK);
static BC_ERRCODE Helper_CalcTempDelay(float32_t *pKelvinTX1, float32_t *pKelvinTX2, float32_t *pKelvinTX3, float32_t *pKelvinChirp, uint8_t *pTempModuleSelect, uint8_t *pTempModuleSelectCafc, uint8_t *pTempModuleSelectTX1, uint8_t *pTempModuleSelectTX2, uint8_t *pTempModuleSelectTX3, uint32_t *pTemperatureDelay);
static uint8_t Helper_TempModSel(float32_t *pKelvinTX, uint32_t *pTemperatureDelay);
static BC_ERRCODE Helper_ES2_SetStableSampling(void);
static BC_ERRCODE Helper_ES2_InitSPIChkLoadOTPSer(SYS_IPList_t *AppConfig);
static BC_ERRCODE Helper_ES2_InitConfigLOI(void);
static BC_ERRCODE Helper_ES2_InitConfigTXRX(void);
static BC_ERRCODE Helper_ES2_InitClkOTPGldoGbiaLdo(void);
static BC_ERRCODE Helper_ES2_InitPOnLOITxRxADCSaft(void);
static BC_ERRCODE Helper_ES2_InitFITCheckSNS(void);
static BC_ERRCODE Helper_ES2_InitCAFCConfMClkMSPC(BOOL EnSlaveMode);
static BC_ERRCODE Helper_ES2_InitMCModErNSerLOBuf(BOOL EnSlaveMode);
static BC_ERRCODE Helper_ES2_RestoreChirpGlobal(uint32_t StoredChirpGlblReg);
static BC_ERRCODE Helper_ES2_InjectCRCError(BOOL *pRestoreCRCInjectReg, BOOL *pRestoreCRCCheck, uint32_t *pStoreCRCCheckValue);
static BC_ERRCODE Helper_ES2_RestoreCRCRegs(BOOL RestoreCRCInjectReg, BOOL RestoreCRCCheck, uint32_t StoreCRCCheckValue);

static BC_ERRCODE Helper_ES2_InjectCRCError(BOOL *pRestoreCRCInjectReg, BOOL *pRestoreCRCCheck, uint32_t *pStoreCRCCheckValue)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    uint32_t CrcErrorInjectionVal = SYS_REGCRC_ERROR_INJECTION_FORCE_VALUE;
    SYS_RegCRCErrors_t RegCRCErr;
    R2M18_RegCrcCheckCtrlUnion_t RegCrcCheckCtrl;
    // Inject CRC error in CC module
    ErrCode = BC_SPI_WriteCheck(e_SYS_ISM, CC_CRC_ERROR_INJECTION_U16, CrcErrorInjectionVal);
    // Trigger CRC Check
    if (BC_ERR_NOERROR == ErrCode)
    {
        *pRestoreCRCInjectReg = TRUE;
        ErrCode = BC_SPI_Read(e_SYS_ISM, R2M18_REG_CRC_CHECK_CTRL_U16, &RegCrcCheckCtrl.val_u32);
        if (BC_ERR_NOERROR == ErrCode)
        {
            *pStoreCRCCheckValue = RegCrcCheckCtrl.val_u32;
            RegCrcCheckCtrl.bits_st.CrcCheckTriggerEvent = (uint8_t)e_SYS_CRC_TRIGGER_EVENT_MCU_TRIGGER;
            RegCrcCheckCtrl.bits_st.CrcCheckTriggerMcu = 1u;
            ErrCode = BC_SPI_Write(e_SYS_ISM, R2M18_REG_CRC_CHECK_CTRL_U16, RegCrcCheckCtrl.val_u32);
            *pRestoreCRCCheck = TRUE;
        }
        if (BC_ERR_NOERROR == ErrCode)
        {
            ErrCode = PLF_TM_Sleep(SYS_SYS_REGCRC_TRGGER_WAIT);
        }
        if (BC_ERR_NOERROR == ErrCode)
        {
            RegCRCErr.ISMRegCRCErr = FALSE;
            ErrCode = BC_ISM_GetRegCRCErrStatus(FALSE, &RegCRCErr, NULL);
            if ((BC_ERR_NOERROR == ErrCode) && (RegCRCErr.ISMRegCRCErr == FALSE))
            {
                ErrCode = BC_ERR_SYS_REGCRC_TRIGGER_FAILED;
            }
        }
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_RestoreCRCRegs(BOOL RestoreCRCInjectReg, BOOL RestoreCRCCheck, uint32_t StoreCRCCheckValue)
{
    uint32_t CrcErrorInjectionResetVal = SYS_REGCRC_ERROR_INJECTION_RESET_VALUE;
    BC_ERRCODE ErrCodeInjec = BC_ERR_NOERROR;
    BC_ERRCODE ErrCodeCRC = BC_ERR_NOERROR;
    if (TRUE == RestoreCRCInjectReg)
    {
        ErrCodeInjec = BC_SPI_WriteCheck(e_SYS_ISM, CC_CRC_ERROR_INJECTION_U16, CrcErrorInjectionResetVal);
    }
    if (TRUE == RestoreCRCCheck)
    {
        ErrCodeCRC = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_REG_CRC_CHECK_CTRL_U16, StoreCRCCheckValue);
    }
    if (ErrCodeInjec == BC_ERR_NOERROR)
    {
        ErrCodeInjec = ErrCodeCRC;
    }
    return ErrCodeInjec;
}

static BC_ERRCODE Helper_ES2_RestoreChirpGlobal(uint32_t StoredChirpGlblReg)
{
    R2M04_ChirpGlobalControlUnion_t ChirpGlblCtrl;
    R2M04_ChirpGlobalControlUnion_t ChirpGlblCtrlStored;
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    // restore chirp profile setting
    ChirpGlblCtrlStored.val_u32 = StoredChirpGlblReg;
    ErrCode = BC_SPI_Write(e_SYS_TE, R2M04_CHIRP_GLOBAL_CONTROL_U16, StoredChirpGlblReg);
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SPI_Read(e_SYS_TE, R2M04_CHIRP_GLOBAL_CONTROL_U16, &ChirpGlblCtrl.val_u32);
        if ((BC_ERR_NOERROR == ErrCode) &&
            ((ChirpGlblCtrl.bits_st.ChirpProfileSelect != ChirpGlblCtrlStored.bits_st.ChirpProfileSelect) ||
             (ChirpGlblCtrl.bits_st.ChirpEnable != ChirpGlblCtrlStored.bits_st.ChirpEnable) ||
             (ChirpGlblCtrl.bits_st.EnableProfileReset != ChirpGlblCtrlStored.bits_st.EnableProfileReset) ||
             (ChirpGlblCtrl.bits_st.ProfileRepeatCountVal != ChirpGlblCtrlStored.bits_st.ProfileRepeatCountVal)))
        {
            ErrCode = BC_ERR_SYS_RESTORE_CHIRP_GLOBAL_FAILED;
        }
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_TrigChirpCheckErr(void)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    SYS_CAFCErrors_t ChirpErr;

    ErrCode = BC_ISM_ResetISMErr(FALSE, FALSE, FALSE, TRUE);
    if (ErrCode == BC_ERR_NOERROR)
    {
        // trigger chirp
        ErrCode = BC_TE_StartChirp();
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        // wait using polling method
        ErrCode = BC_TE_WaitForReady();
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        // check the Chirp error
        ErrCode = BC_ISM_GetChirpErrStatus(e_ISM_GET_MASKED_ERR, &ChirpErr, NULL);
        if ((ErrCode == BC_ERR_NOERROR) && ((ChirpErr.PLLUnlockErr == TRUE) || (ChirpErr.VCOLevelMinErr == TRUE)))
        {
            ErrCode = BC_ERR_SYS_CAFCINTEGRITY_CHECK_FAILED;
        }
    }
    return ErrCode;
}

static BC_ERRCODE Helper_ES2_InitMCModErNSerLOBuf(BOOL EnSlaveMode)
{
    BOOL EnableBuffer13;
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    MCLK_CLKDetMode_e CLKDetMode = (TRUE == EnSlaveMode) ? e_MCLK_CLKDET_FOLLOWER_MODE : e_MCLK_CLKDET_LEADER_MODE;
    ErrCode = Helper_ES2_ConfigMCLKClkDetector(CLKDetMode);
    /*Checking for ERROR_N*/
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = Helper_ES2_CheckErrorN();
    }

    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SYS_Init_InitDataInterface();
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        EnableBuffer13 = (TRUE == EnSlaveMode) ? FALSE : TRUE; // if EnslaveMode is TRUE: Slave Enable  B2, B3 , if EnslaveMode is FALSE: Master Enable B1, B2, B3 ,B4,
        ErrCode = BC_LOI_ConfigBufferMode(EnableBuffer13, TRUE, TRUE, EnableBuffer13, TRUE, FALSE);
    }
    return ErrCode;
}

static BC_ERRCODE Helper_ES2_InitCAFCConfMClkMSPC(BOOL EnSlaveMode)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    if (FALSE == EnSlaveMode)
    {
        ErrCode = BC_SYS_Init_ConfigCAFC();
    }
    else
    {
        ErrCode = BC_ISM_SetStartupStatus(e_ISM_CAFC_CONFIG_OK);
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SYS_Init_ConfigMCLK();
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = Helper_ES2_EnableMSPCPFDSupply();
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_MCLK_StartMSPC();
    }
    return ErrCode;
}

static BC_ERRCODE Helper_ES2_InitFITCheckSNS(void)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    ErrCode = BC_ISM_FIT();
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SYS_Init_SNSIntegrityCheck();
    }
    return ErrCode;
}

static BC_ERRCODE Helper_ES2_InitPOnLOITxRxADCSaft(void)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    ErrCode = BC_SYS_Init_PowerOnModules();
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = Helper_ES2_InitConfigLOI();
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        /*Transmitter phase rotator calibration : ADC timing default values are updated for ES2 samples.*/
        ErrCode = Helper_ES2_InitConfigTXRX();
    }

    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SYS_Init_ConfigADC();
    }

    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SYS_Init_ConfigSafetySensors();
    }
    return ErrCode;
}

static BC_ERRCODE Helper_ES2_InitClkOTPGldoGbiaLdo(void)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    ErrCode = BC_SYS_Init_EnClkRelRstIPs();
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SYS_Init_DistributeOTPData();
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SYS_Init_ConfigGLDO();
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SYS_Init_ConfigGBIAS();
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SYS_Init_EnLocalLDO();
    }
    return ErrCode;
}

static BC_ERRCODE Helper_ES2_InitSPIChkLoadOTPSer(SYS_IPList_t *AppConfig)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    ErrCode = BC_SYS_Init_ReleaseHRESET();

    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SYS_Init_SPIAccessCheck();
    }

    if (BC_ERR_NOERROR == ErrCode)
    {
        CC_ModList_t ModList = {0};
        ModList.SetISM = TRUE;
        /* Assert the reset of IPs*/
        ErrCode = BC_CC_SetPonClkRst(e_CC_RST, &ModList);
    }

    if (BC_ERR_NOERROR == ErrCode)
    {
        // enable ErrorN pin to output mode
        ErrCode = BC_CC_ConfigPad(TRUE, e_CC_PADSPEED_HIGH, e_SYS_ERRORN);
    }

    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SYS_Init_ReadOTPCheckCRC();
    }

    // need to set serializer mode in CC to enabled access to LVDS or MIPI module
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_CC_GetAppConfiguration(AppConfig, NULL);
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = Helper_ES2_ConfigureSerialInterface(AppConfig);
    }
    return ErrCode;
}
static BC_ERRCODE Helper_TXConfigCalibDefaults(void)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M11_TxBiasSettingsUnion_t TxBiasSettings;
    R2M11_SpareSettingsUnion_t SpareSettings;
    R2M11_TxMmwEnableUnion_t TxMmwEnable;
    R2M11_PrcCalibrationCtrlUnion_t PrcCalibrationCtrl;
    uint8_t CurrTx;
    // Default value changed for TX_BIAS_SETTINGS
    TxBiasSettings.val_u32 = 0u;
    TxBiasSettings.bits_st.PaIbgGain = 0x0u;
    TxBiasSettings.bits_st.PaIptatGain = 0x8u;
    TxBiasSettings.bits_st.PrIbgGain = 0x7u;
    TxBiasSettings.bits_st.PrIptatGain = 0xDu;
    TxBiasSettings.bits_st.VgaIbgGain = 0x6u;
    TxBiasSettings.bits_st.VgaIptatGain = 0xBu;
    ErrCode = BC_SPI_Write(e_SYS_TXMC, R2M11_TX_BIAS_SETTINGS_U16, TxBiasSettings.val_u32);
    if (ErrCode == BC_ERR_NOERROR)
    {
        // Default value changed for SPARE_SETTING
        SpareSettings.val_u32 = 0u; // TxSpareBits = 0x0u; (Reset value)
        SpareSettings.bits_st.TempCompOffset = 0x5u;
        SpareSettings.bits_st.TempCompSlope = 0x4u;
        ErrCode = BC_SPI_Write(e_SYS_TXMC, R2M11_SPARE_SETTINGS_U16, SpareSettings.val_u32);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        for (CurrTx = 0; CurrTx < 3u; CurrTx++)
        {
            if (ErrCode == BC_ERR_NOERROR)
            {
                // Default value changed for TX_MMW_ENABLE
                SYS_IPNum_e TempTxIP;
                TempTxIP = (CurrTx == 0u) ? e_SYS_TX1 : ((CurrTx == 1u) ? e_SYS_TX2 : e_SYS_TX3);
                ErrCode = BC_SPI_Read((TempTxIP), R2M11_TX_MMW_ENABLE_U16, &TxMmwEnable.val_u32);
                if (ErrCode == BC_ERR_NOERROR)
                {
                    TxMmwEnable.bits_st.EnTcComp = 0x5Fu;
                    ErrCode = BC_SPI_Write((TempTxIP), R2M11_TX_MMW_ENABLE_U16, TxMmwEnable.val_u32);
                }
            }
        }
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        // Default value changed for PRC_CALIBRATION_CTRL
        PrcCalibrationCtrl.val_u32 = 0u;
        PrcCalibrationCtrl.bits_st.DPhaseCalBranchSel = 0x1u;
        PrcCalibrationCtrl.bits_st.PhaseSignComp = 0x0u; // reset value
        ErrCode = BC_SPI_Write(e_SYS_TXMC, R2M11_PRC_CALIBRATION_CTRL_U16, PrcCalibrationCtrl.val_u32);
    }
    return ErrCode;
}

static BC_ERRCODE Helper_TXPRSafetyCheckDefaults(void)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M11_PrcCtrl1SafetyUnion_t PrcCtrl1Safety;
    // Default value changed for PRC_CTRL1_SAFETY
    PrcCtrl1Safety.val_u32 = 0u;
    PrcCtrl1Safety.bits_st.PrInlPhiStep = 0x1u; // reset value
    PrcCtrl1Safety.bits_st.RfRampLimit = 0x8u;
    PrcCtrl1Safety.bits_st.RfRampStep = 0xAu;
    PrcCtrl1Safety.bits_st.RfRangeVariation = 0x40u;
    ErrCode = BC_SPI_Write(e_SYS_TXMC, R2M11_PRC_CTRL1_SAFETY_U16, PrcCtrl1Safety.val_u32);

    if (ErrCode == BC_ERR_NOERROR)
    {
        R2M11_PrcCtrl2SafetyUnion_t PrcCtrl2Safety;
        PrcCtrl2Safety.val_u32 = 0u;
        /* Eventhough SafetyPrInlGainCode is 16 bits wide, only lowest 8 bits are getting used */
        PrcCtrl2Safety.bits_st.SafetyPrInlGainCode = TX_SAFETY_PR_INL_GAIN_CODE;
        ErrCode = BC_SPI_Write(e_SYS_TXMC, R2M11_PRC_CTRL2_SAFETY_U16, PrcCtrl2Safety.val_u32);
    }

    return ErrCode;
}

static BC_ERRCODE Helper_TXLOx3GainSource(void)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M11_Lox3GainControlUnion_t Lox3GainCtrl;
    // Default value changed for Lox3GainSource to  Value from LOI module,  LOX3_GAIN_CONTROL  -> tx_lox3_gain_ctrl
    Lox3GainCtrl.val_u32 = 0u; /*To set unused bits to 0*/
    Lox3GainCtrl.bits_st.Lox3GainSource = 0u;
    ErrCode = BC_SPI_Write(e_SYS_TXMC, R2M11_LOX3_GAIN_CONTROL_U16, Lox3GainCtrl.val_u32);

    return ErrCode;
}

static BC_ERRCODE Helper_CopyProfileLocal(SYS_IPNum_e IPNum, SYS_ProfID_e SrcProfID, SYS_ProfID_e DestProfID, uint8_t ProfSetLen, uint16_t ProfSetBaseAddress)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    // fixed size array to store profile reg read results
    uint8_t loop0 = 0u;
    uint8_t loop1 = 0u;
    uint32_t ProfRegValArr[10] = {0u};
    // number of destination profiles
    uint8_t NumDestProf;
    // source profile offset, from profile 0
    uint8_t SrcProfOffset = 0u;
    // destination profile start offset, from profile 0
    uint8_t DestProfStartOffset = 0u;

    SrcProfOffset = (uint8_t)SrcProfID;

    // decide how many destination profiles need to be overwritten
    NumDestProf = (DestProfID <= e_SYS_PROFILE_8) ? 1u : ((uint8_t)DestProfID - (uint8_t)e_SYS_PROFILE_8 + 1u);
    DestProfStartOffset = (DestProfID <= e_SYS_PROFILE_8) ? ((uint8_t)DestProfID - (uint8_t)e_SYS_PROFILE_0) : 0u;

    // read from src profiles
    for (loop0 = 0; loop0 < ProfSetLen; loop0++)
    {
        // deal with CAFC reg gap
        if ((IPNum == e_SYS_CAFC) && (loop0 >= (ProfSetLen - SYS_CAFC_PROFILE_ES2_REG_GAP)))
        {
            continue;
        }

        if (BC_ERR_NOERROR == ErrCode)
        {
            // address composition: base + srcProfOffset + regInCurrentProf
            ErrCode = BC_SPI_Read(IPNum, ProfSetBaseAddress + (uint16_t)((((uint16_t)SrcProfOffset * ProfSetLen) + loop0) * 4u), &ProfRegValArr[loop0]);
        }
    }

    // write to dest profiles, iterate through all dest profiles and all register in a profile set.
    for (loop0 = 0; loop0 < NumDestProf; loop0++)
    {
        for (loop1 = 0; loop1 < ProfSetLen; loop1++)
        {
            // deal with CAFC reg gap
            if ((IPNum == e_SYS_CAFC) && (loop1 >= (ProfSetLen - SYS_CAFC_PROFILE_ES2_REG_GAP)))
            {
                continue;
            }

            if (BC_ERR_NOERROR == ErrCode)
            {
                // address composition: base + destProfOffset + regInCurrentProf
                ErrCode = BC_SPI_WriteCheck(IPNum, ProfSetBaseAddress + (uint16_t)(((((uint16_t)DestProfStartOffset + loop0) * ProfSetLen) + loop1) * 4u), ProfRegValArr[loop1]);
            }
        }
    }
    return ErrCode;
}

static BC_ERRCODE Helper_ES2_InitConfigLOI(void)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M0A_LoInterfaceControlUnion_t LoInterfaceControl;
    R2M0A_Lox3GainControlUnion_t Lox3GainCtrl;

    ErrCode = BC_SPI_Read(e_SYS_LOI, R2M0A_LO_INTERFACE_CONTROL_U16, &LoInterfaceControl.val_u32);
    if (BC_ERR_NOERROR == ErrCode)
    {
        LoInterfaceControl.bits_st.EnLo = TRUE;
        ErrCode = BC_SPI_WriteCheck(e_SYS_LOI, R2M0A_LO_INTERFACE_CONTROL_U16, LoInterfaceControl.val_u32);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        /* TX, RX gain selection from RX avrg roundup.*/
        Lox3GainCtrl.val_u32 = 0u;
        Lox3GainCtrl.bits_st.RxLox3GainSel = (uint8_t)e_LOI_RXGAIN_RX_LOX3_MINMAXAVG;
        Lox3GainCtrl.bits_st.TxLox3GainSel = (uint8_t)e_LOI_TXGAIN_RX_LOX3_MINMAXAVG;
        Lox3GainCtrl.bits_st.TxLox3GainCtrl = 0u;
        Lox3GainCtrl.bits_st.Lox3GainCtrl = 0u;
        Lox3GainCtrl.bits_st.RxLox3MinMaxAvgSel = (uint8_t)e_LOI_LOX3_AVG;
        Lox3GainCtrl.bits_st.TxLox3MinMaxAvgSel = (uint8_t)e_LOI_LOX3_AVG;
        Lox3GainCtrl.bits_st.TxLox3GainAvgRoundUp = TRUE;
        Lox3GainCtrl.bits_st.RxLox3GainAvgRoundUp = TRUE;
        ErrCode = BC_SPI_WriteCheck(e_SYS_LOI, R2M0A_LOX3_GAIN_CONTROL_U16, Lox3GainCtrl.val_u32);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        uint32_t TPVersionFT = 0u;
        uint32_t FTMajorVersion = 0u;
        uint32_t FTMinorVersion = 0u;
        ErrCode = BC_OTP_GetOTPRegValue(OTP_TP_ID_FT12_INDEX, &TPVersionFT);
        FTMajorVersion = ((TPVersionFT & OTP_ID_FT_MAJOR_MASK) >> OTP_ID_FT_MAJOR_POS);
        FTMinorVersion = (TPVersionFT & OTP_ID_FT_MINOR_MASK);
        // only for FT 2.0 default values 8 & 8 are good
        if ((ErrCode == BC_ERR_NOERROR) && ((FTMajorVersion != 0x2u) || (FTMinorVersion != 0u)))
        {
            R2M0A_RmsMonPtatBgrControlUnion_t RmsMonPtatBgrControl;
            ErrCode = BC_SPI_Read(e_SYS_LOI, R2M0A_RMS_MON_PTAT_BGR_CONTROL_U16, &RmsMonPtatBgrControl.val_u32);
            if (ErrCode == BC_ERR_NOERROR)
            {
                RmsMonPtatBgrControl.bits_st.CtrlIrefRmsMonBgrCtrl = 7u;
                RmsMonPtatBgrControl.bits_st.CtrlIrefRmsMonPtatCtrl = 5u;
                ErrCode = BC_SPI_WriteCheck(e_SYS_LOI, R2M0A_RMS_MON_PTAT_BGR_CONTROL_U16, RmsMonPtatBgrControl.val_u32);
            }
        }
    }
    return ErrCode;
}

static BC_ERRCODE Helper_ES2_ReadTxTemperature(float32_t *pKelvinTX1, float32_t *pKelvinTX2, float32_t *pKelvinTX3)
{
    BC_ERRCODE ErrCode;
    R2M00_TempDigitizerDataTxUnion_t TempDataTx;
    uint32_t count = 0u;

    // Temp digitizer data for chirp
    //  NULL Pointer check is not added since this function will not be called incase of NULL pointer input.
    count = 0u;
    do
    {
        TempDataTx.val_u32 = 0u;
        ErrCode = BC_SPI_Read(e_SYS_CC, R2M00_TEMP_DIGITIZER_DATA_TX_U16, &TempDataTx.val_u32);
        count++;
    } while ((TempDataTx.bits_st.TempDigitizerReadyTx == 0x0u) && (count < SYS_WAIT_TEMP_MEASUREMENT_TIMEOUT) && (ErrCode == BC_ERR_NOERROR));

    if (ErrCode == BC_ERR_NOERROR)
    {
        if (TempDataTx.bits_st.TempDigitizerReadyTx == 0x1u)
        {
            if (pKelvinTX1 != NULL)
            {
                *pKelvinTX1 = (*pKelvinTX1 == 1.0f) ? (float32_t)TempDataTx.bits_st.TempDataTx1 : 0.0f;
            }
            if (pKelvinTX2 != NULL)
            {
                *pKelvinTX2 = (*pKelvinTX2 == 1.0f) ? (float32_t)TempDataTx.bits_st.TempDataTx2 : 0.0f;
            }
            if (pKelvinTX3 != NULL)
            {
                *pKelvinTX3 = (*pKelvinTX3 == 1.0f) ? (float32_t)TempDataTx.bits_st.TempDataTx3 : 0.0f;
            }
        }
        else
        {
            ErrCode = BC_ERR_SYS_TX_TEMP_READ_TIMEOUT;
        }
    }

    return ErrCode;
}

static BC_ERRCODE Helper_ES2_ReadCAFCTemperature(float32_t *pKelvinChirp)
{
    BC_ERRCODE ErrCode;
    uint32_t count = 0u;
    R2M00_TempDigitizerDataChirpUnion_t TemperatureDataChirp;

    // NULL Pointer check is not added since this function will not be called incase of NULL pointer input.
    count = 0;
    do
    {
        TemperatureDataChirp.val_u32 = 0u;
        ErrCode = BC_SPI_Read(e_SYS_CC, R2M00_TEMP_DIGITIZER_DATA_CHIRP_U16, &TemperatureDataChirp.val_u32);
        count++;
    } while ((TemperatureDataChirp.bits_st.TempDigitizerReadyChirp == 0x0u) && (count < SYS_WAIT_TEMP_MEASUREMENT_TIMEOUT) && (ErrCode == BC_ERR_NOERROR));

    if (ErrCode == BC_ERR_NOERROR)
    {
        if (TemperatureDataChirp.bits_st.TempDigitizerReadyChirp == 0x1u)
        {
            *pKelvinChirp = (float32_t)TemperatureDataChirp.bits_st.TempDataChirp;
        }
        else
        {
            ErrCode = BC_ERR_SYS_CAFC_TEMP_READ_TIMEOUT;
        }
    }

    return ErrCode;
}

static BC_ERRCODE Helper_ES2_Monitor_RTMReadTxErr(uint32_t *TxErrorMonU32)
{
    BC_ERRCODE ErrCode;

    ErrCode = BC_SPI_Read(e_SYS_ISM, R2M18_TX_ERROR_MON_REG_U16, TxErrorMonU32);
    return ErrCode;
}

/*
 * This function is a simplified version of Helper_Monitor_RTMSetClrTxErr for explicitly and solely setting
 * the RF level Min Error Monitoring bit for the requested transceiver.
 * It is the caller's responsibility to prior read and store the original value from the register, and afterwards
 * restore it if required.
 */
static BC_ERRCODE Helper_ES2_Monitor_TxRfMinErr(void)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M18_TxErrorMonRegUnion_t TxErrorMon;

    // Completely clear current Tx Error Monitor Register value
    TxErrorMon.val_u32 = 0;
    TxErrorMon.bits_st.RfLevelMinErrorFlagTx1Mon = (uint8_t)TRUE;
    TxErrorMon.bits_st.RfLevelMinErrorFlagTx2Mon = (uint8_t)TRUE;
    TxErrorMon.bits_st.RfLevelMinErrorFlagTx3Mon = (uint8_t)TRUE;
    ErrCode = BC_SPI_Write(e_SYS_ISM, R2M18_TX_ERROR_MON_REG_U16, TxErrorMon.val_u32);

    return ErrCode;
}

static BC_ERRCODE Helper_ES2_Monitor_RTMWriteTxErr(uint32_t TxErrorMonU32)
{
    BC_ERRCODE ErrCode;

    ErrCode = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_TX_ERROR_MON_REG_U16, TxErrorMonU32);

    return ErrCode;
}

/*
 * This function is a simplified version of HAL_ES2_TX_ConfigLocalCtrl for explicitly and solely enabling the requested transceiver using Tx Control register.
 * The original function HAL_ES2_TX_ConfigLocalCtrl changes all bits as requested, whereas
 * this functions sets bits EnTxViaSpi & SwTxViaSpi. All other other bits are cleared.
 * It is the caller's responsibility to prior read and store the original value from the register, and afterwards
 * restore it if required.
 */
static BC_ERRCODE Helper_ES2_EnableTxCtrl(SYS_IPList_t *pAppConfig, BOOL EnableTX, BOOL SwitchTX)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M11_TxControlUnion_t TXCtrl;
    uint32_t TxCtrlEnableVal32 = 0u;
    uint8_t Count = 0u;

    TXCtrl.val_u32 = 0;
    TXCtrl.bits_st.EnPsExtSpi = (uint8_t)FALSE;
    TXCtrl.bits_st.PonLsSpi = (uint8_t)FALSE;
    TXCtrl.bits_st.PsTxViaSpi = (uint8_t)FALSE;
    TXCtrl.bits_st.TxActiveDelayCtrl = TX_ACTIVE_DELAY_DEFAULT;
    TXCtrl.bits_st.EnTxViaSpi = (uint8_t)EnableTX;
    TXCtrl.bits_st.SwTxViaSpi = (uint8_t)SwitchTX;
    TXCtrl.bits_st.TxCascodeSelViaSpi = (uint8_t)FALSE;
    TXCtrl.bits_st.TxCascodeValueViaSpi = (uint8_t)FALSE;
    if ((EnableTX == FALSE) && (SwitchTX == FALSE))
    {
        /* Restore to reset value at the end the BC_SYS_TxSensorIntegritCheck API. TxActiveViaSpi is 0 for faster response.*/
        TXCtrl.bits_st.TxActiveViaSpi = (uint8_t)TRUE;
        ErrCode = BC_SPI_Write(e_SYS_TXMC, R2M11_TX_CONTROL_U16, TXCtrl.val_u32);
        if ((pAppConfig->TX1 == TRUE) && (ErrCode == BC_ERR_NOERROR))
        {
            ErrCode = BC_SPI_Read(e_SYS_TX1, R2M11_TX_CONTROL_U16, &TxCtrlEnableVal32);
            if (TXCtrl.val_u32 != TxCtrlEnableVal32)
            {
                Count = 1u;
            }
            TxCtrlEnableVal32 = 0u;
        }
        if ((pAppConfig->TX2 == TRUE) && (ErrCode == BC_ERR_NOERROR))
        {
            ErrCode = BC_SPI_Read(e_SYS_TX2, R2M11_TX_CONTROL_U16, &TxCtrlEnableVal32);
            if (TXCtrl.val_u32 != TxCtrlEnableVal32)
            {
                Count = Count + 2u;
            }
            TxCtrlEnableVal32 = 0u;
        }
        if ((pAppConfig->TX3 == TRUE) && (ErrCode == BC_ERR_NOERROR))
        {
            ErrCode = BC_SPI_Read(e_SYS_TX3, R2M11_TX_CONTROL_U16, &TxCtrlEnableVal32);
            if (TXCtrl.val_u32 != TxCtrlEnableVal32)
            {
                Count = Count + 4u;
            }
            TxCtrlEnableVal32 = 0u;
        }
        if (BC_ERR_NOERROR == ErrCode)
        {
            if (Count != 0u)
            {
                ErrCode = BC_ERR_SYS_TX_CTRL_ENABLE_WRITECHECK_BASE + (uint32_t)Count;
            }
        }
    }
    else
    {
        ErrCode = BC_SPI_Write(e_SYS_TXMC, R2M11_TX_CONTROL_U16, TXCtrl.val_u32);
    }
    return ErrCode;
}

static BC_ERRCODE Helper_ES2_InitConfigTXRX(void)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M11_PrcTimerAdcFuncUnion_t TimerADC;
    TimerADC.val_u32 = 0;
    TimerADC.bits_st.TimerStartAdcConv = TX_PRC_ADC_TIMER_START_ADC_CONV;
    TimerADC.bits_st.TimerAdcCycle = TX_PRC_ADC_TIMER_ADC_CYCLE;
    ErrCode = BC_SPI_Write(e_SYS_TXMC, R2M11_PRC_TIMER_ADC_FUNC_U16, TimerADC.val_u32);
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = Helper_TXConfigCalibDefaults();
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = Helper_TXPRSafetyCheckDefaults();
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = Helper_TXLOx3GainSource();
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_TX_SetRFCalMonLevel(e_SYS_TXMC, TX_LEVEL_RF_HIGH_DELTA, TX_LEVEL_RF_LOW_DELTA);
    }
    // Calibration time updated after validation closure.
    if (ErrCode == BC_ERR_NOERROR)
    {
        /*
            Following was default/reset values of the bitfields.
            TX_THRESHOLD_CONTROL-> det_cnt_threshold_rf is 2us.
            TX_THRESHOLD_CONTROL-> mon_cnt_threshold is 100ns (default)
            TX_THRESHOLD_CONTROL-> det_cnt_threshold_ppd is 1us (default)
            TX_THRESHOLD_CONTROL-> det_cnt_threshold_pout is 1us (default)
        */
        TX_CalibrationTime_t CalibTime;
        CalibTime.MonDetCountThreshold = 6.375f;
        CalibTime.PoutDetCountThreshold = 1.0f;
        CalibTime.PPDDetCountThreshold = 6.375f;
        CalibTime.RFDetCountThreshold = 6.375f;
        ErrCode = BC_TX_ConfigCalibTime(e_SYS_TXMC, &CalibTime);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        // Calling the API to reset global variable. All bitfields are set to reset values.
        ErrCode = BC_RX_ConfigLOx3Gain(e_SYS_RXMC, e_RX_LOx3_CAL, 0u, TRUE, 0u);
    }
    return ErrCode;
}

BC_ERRCODE Helper_ES2_ChangeFStart(SYS_ProfID_e ProfID, BC_FLOAT StartFreqHz, SYS_SBChangeMode_e Mode, uint8_t *pSubband)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    uint16_t regOffset;
    float32_t startDiv0 = 0.0f;
    float32_t NStart = 0.0f;
    float32_t NStartf = 0.0f;
    uint8_t NStart_int = 0u;
    uint32_t NStart_frac = 0u;

    R2M06_VcoControlUnion_t VcoControl;
    R2M05_NStartRfProfile0Union_t NStartRfProfileX;
    R2M06_VcoRegProfile0Union_t VcoRegProfile0;

    // Assumed that program the chirp already and it does not matter the chirp mode or CW mode.
    // Compute the start frequency of chirp for all profiles
    if ((StartFreqHz < SC_AUTO_RADAR_LOWER_END) || (StartFreqHz > SC_AUTO_RADAR_UPPER_END))
    {
        ErrCode = BC_ERR_INPUTOUTOFRANGE;
    }
    if ((ProfID > e_SYS_PROFILE_8) && (ErrCode == BC_ERR_NOERROR))
    {
        ErrCode = BC_ERR_SYS_INVALID_PROFILE; // e_SYS_PROFILE_INVALID
    }
    // Supported the only 8 profile IDs.
    if (ErrCode == BC_ERR_NOERROR)
    {
        regOffset = (uint16_t)ProfID * 0x18u; /*This offset can be used wrt profile 0 registers*/

        /* NStart's integer and fractional parts computation */
        startDiv0 = (float32_t)(StartFreqHz / (BC_FLOAT)SC_FREQ_DIVIDER);
        NStartf = modff(startDiv0, &NStart); /* modff breaks startDiv0 into integral and fractional parts */
        NStart_int = (uint8_t)NStart;        /*Integer part, casting not harmful as fractional part is 0*/
        /*Converting fractional part into integer representation with Q26 format*/
        NStart_frac = (uint32_t)(roundf(NStartf * 67108864.0f)); // left shift 26

        /*No read required as changing the entire register value*/
        NStartRfProfileX.bits_st.NstartintrfProfile0 = NStart_int;
        NStartRfProfileX.bits_st.NstartfracrfProfile0 = NStart_frac;
        ErrCode = BC_SPI_WriteCheck(e_SYS_SC, (R2M05_N_START_RF_PROFILE0_U16 + regOffset), NStartRfProfileX.val_u32);
    }
    // Get the Sub-Band type which selected for start-frequency.
    if (ErrCode == BC_ERR_NOERROR)
    {
        // select the sub-band
        switch (Mode)
        { // keep current subband in register
        case e_SYS_SBCHG_KEEPSB:
            // Read the current start freq from all 8 profiles
            regOffset = (uint16_t)ProfID * 0x10u; /*This offset can be used w.r.t profile 0 registers*/
            ErrCode = BC_SPI_Read(e_SYS_CAFC, (R2M06_VCO_REG_PROFILE0_U16 + regOffset), &VcoRegProfile0.val_u32);
            if ((ErrCode == BC_ERR_NOERROR) && (pSubband != NULL))
            {
                /*Read the Sub-Band from CtlVcoCoarseTuning9GSpiProfile field for all profile using reg offset*/
                *pSubband = (uint8_t)(VcoRegProfile0.bits_st.CtlVcoCoarseTuning9GSpiProfile0);
            }
            break;
            // manually force a subband
        case e_SYS_SBCHG_FORCESB:
            // Read the current start freq from all 8 profiles
            ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_VCO_CONTROL_U16, &VcoControl.val_u32);
            if (ErrCode == BC_ERR_NOERROR)
            {
                regOffset = (uint16_t)ProfID * 0x10u; /*This offset can be used w.r.t profile 0 registers*/
                ErrCode = BC_SPI_Read(e_SYS_CAFC, (R2M06_VCO_REG_PROFILE0_U16 + regOffset), &VcoRegProfile0.val_u32);
            }
            // Selection of VCO
            // 5GHz VCO selected
            if ((pSubband != NULL) && (VcoControl.bits_st.CtlSelVco1G5GSpi == 0x1u) && (ErrCode == BC_ERR_NOERROR))
            { // Configure the Sub-Band and then reading sub-band.
                if (*pSubband <= 0x3fu)
                {
                    VcoRegProfile0.bits_st.CtlVcoCoarseTuning9GSpiProfile0 = (uint8_t)*pSubband;
                    ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, (R2M06_VCO_REG_PROFILE0_U16 + regOffset), VcoRegProfile0.val_u32);
                }
                else
                {
                    ErrCode = BC_ERR_INPUTOUTOFRANGE;
                }
            }
            if ((pSubband != NULL) && (VcoControl.bits_st.CtlSelVco1G5GSpi != 0x1u) && (ErrCode == BC_ERR_NOERROR)) // 1GHz VCO selected
            {                                                                                                       /*Read the Sub-Band from CtlVcoCoarseTuning9GSpiProfile field*/
                if (*pSubband <= 0x7fu)
                {
                    VcoRegProfile0.bits_st.CtlVcoCoarseTuning9GSpiProfile0 = (uint8_t)*pSubband;
                    ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, (R2M06_VCO_REG_PROFILE0_U16 + regOffset), VcoRegProfile0.val_u32);
                }
                else
                {
                    ErrCode = BC_ERR_INPUTOUTOFRANGE;
                }
            }
            break;
        default:
            ErrCode = BC_ERR_INPUTOUTOFRANGE; // e_SYS_SBCHG_INVALID
            break;
        }
    }

    return ErrCode;
}

BC_ERRCODE Helper_ES2_CopyProfile(SYS_IPNum_e IPNum, SYS_ProfID_e SrcProfID, SYS_ProfID_e DestProfID)
{
    BC_ERRCODE ErrCode;
    // number of profile registers in a full profile set, e.g. TE has CONTROL_1 to 4, 4 registers in one full profile.
    uint8_t ProfSetLen = 1u;
    // base address of profiles: the address of profile0
    uint16_t ProfSetBaseAddress = 0u;

    // input param check
    // note: Src must be single profile, Dest can be single profile or e.g. Prof_0_TO_7 (multiple desitnations)
    if (((e_SYS_TE == IPNum) || (e_SYS_SC == IPNum) || (e_SYS_CAFC == IPNum) ||
         ((IPNum >= e_SYS_RX1) && (IPNum <= e_SYS_RX4)) || ((IPNum >= e_SYS_TX1) && (IPNum <= e_SYS_TX3))) &&
        (SrcProfID <= e_SYS_PROFILE_8) && (DestProfID <= e_SYS_PROFILES_0_TO_7))
    {

        // Important note: assumption is profile regs are always in consecutive addresses with each other.
        if (IPNum == e_SYS_TE)
        {
            ProfSetLen = SYS_TE_PROFILE_REG_NUM;
            ProfSetBaseAddress = R2M04_TIMING_CONTROL_1_PROFILE0_U16;
        }
        if (IPNum == e_SYS_SC)
        {
            ProfSetLen = SYS_SC_PROFILE_REG_NUM;
            ProfSetBaseAddress = R2M05_N_START_RF_PROFILE0_U16;
        }
        if (IPNum == e_SYS_CAFC)
        {
            // acutal number is 2, but there is two reg gap in reg map in CAFC profiles.
            ProfSetLen = SYS_CAFC_PROFILE_REG_NUM;
            ProfSetBaseAddress = R2M06_VCO_REG_PROFILE0_U16;
        }
        if ((IPNum == e_SYS_RX1) || (IPNum == e_SYS_RX2) || (IPNum == e_SYS_RX3) || (IPNum == e_SYS_RX4))
        {
            ProfSetLen = SYS_RX_PROFILE_REG_NUM;
            ProfSetBaseAddress = R2M0D_GAIN_RX_SET_PROFILE0_U16;
        }
        if ((IPNum == e_SYS_TX1) || (IPNum == e_SYS_TX2) || (IPNum == e_SYS_TX3))
        {
            ProfSetLen = SYS_TX_PROFILE_REG_NUM;
            ProfSetBaseAddress = R2M11_TX_CURR_GAIN_PROFILE0_U16;
        }
        ErrCode = Helper_CopyProfileLocal(IPNum, SrcProfID, DestProfID, ProfSetLen, ProfSetBaseAddress);
    }
    else
    {
        ErrCode = BC_ERR_INPUTOUTOFRANGE;
    }
    return ErrCode;
}

BC_ERRCODE Helper_ES2_ConfigTXPR(BOOL pUseDDMA[3], TE_DDMAMod_e DDMAMode, float32_t pDDMAInitPhase[3], float32_t pDDMAPhaseUpdate[3], TE_PRPCGenMode_e pFinalPCGenMode[3], BOOL pBPSKSource[3])
{
    BC_ERRCODE ErrCode;

    R2M04_TxPrChirpControlModesUnion_t PrChirpCtrlModes;

    ErrCode = BC_SPI_Read(e_SYS_TE, R2M04_TX_PR_CHIRP_CONTROL_MODES_U16, &PrChirpCtrlModes.val_u32);
    if (((pUseDDMA != NULL) && (pBPSKSource != NULL) && (pFinalPCGenMode != NULL)) && (BC_ERR_NOERROR == ErrCode))
    {

        PrChirpCtrlModes.bits_st.Tx1PrPhaseBpskControl = (uint8_t)pBPSKSource[0];
        PrChirpCtrlModes.bits_st.Tx2PrPhaseBpskControl = (uint8_t)pBPSKSource[1];
        PrChirpCtrlModes.bits_st.Tx3PrPhaseBpskControl = (uint8_t)pBPSKSource[2];

        switch (pFinalPCGenMode[0])
        {
        case e_TE_PR_NO_CHANGE:
            PrChirpCtrlModes.bits_st.Tx1PrPhaseAddQpskControl = 0u;
            PrChirpCtrlModes.bits_st.Tx1PrPhaseMsbReplaceWithQpskControl = 0u;
            break;

        case e_TE_PR_REPLACE_MSB_WITH_QPSK:
            PrChirpCtrlModes.bits_st.Tx1PrPhaseAddQpskControl = 0u;
            PrChirpCtrlModes.bits_st.Tx1PrPhaseMsbReplaceWithQpskControl = 1u;
            break;

        case e_TE_PR_ADD_QPSK_TO_MSB:
            PrChirpCtrlModes.bits_st.Tx1PrPhaseAddQpskControl = 1u;
            PrChirpCtrlModes.bits_st.Tx1PrPhaseMsbReplaceWithQpskControl = 0u;
            break;

        default:
            ErrCode = BC_ERR_TE_DDMASETTING;
            break;
        }

        if (BC_ERR_NOERROR == ErrCode)
        {
            /*Final phase code generation related settings - for TX2*/
            switch (pFinalPCGenMode[1])
            {
            case e_TE_PR_NO_CHANGE:
                PrChirpCtrlModes.bits_st.Tx2PrPhaseAddQpskControl = 0u;
                PrChirpCtrlModes.bits_st.Tx2PrPhaseMsbReplaceWithQpskControl = 0u;
                break;

            case e_TE_PR_REPLACE_MSB_WITH_QPSK:
                PrChirpCtrlModes.bits_st.Tx2PrPhaseAddQpskControl = 0u;
                PrChirpCtrlModes.bits_st.Tx2PrPhaseMsbReplaceWithQpskControl = 1u;
                break;

            case e_TE_PR_ADD_QPSK_TO_MSB:
                PrChirpCtrlModes.bits_st.Tx2PrPhaseAddQpskControl = 1u;
                PrChirpCtrlModes.bits_st.Tx2PrPhaseMsbReplaceWithQpskControl = 0u;
                break;

            default:
                ErrCode = BC_ERR_TE_DDMASETTING;
                break;
            }

            if (BC_ERR_NOERROR == ErrCode)
            {
                /*Final phase code generation related settings - for TX3 */
                switch (pFinalPCGenMode[2])
                {
                case e_TE_PR_NO_CHANGE:
                    PrChirpCtrlModes.bits_st.Tx3PrPhaseAddQpskControl = 0u;
                    PrChirpCtrlModes.bits_st.Tx3PrPhaseMsbReplaceWithQpskControl = 0u;
                    break;

                case e_TE_PR_REPLACE_MSB_WITH_QPSK:
                    PrChirpCtrlModes.bits_st.Tx3PrPhaseAddQpskControl = 0u;
                    PrChirpCtrlModes.bits_st.Tx3PrPhaseMsbReplaceWithQpskControl = 1u;
                    break;

                case e_TE_PR_ADD_QPSK_TO_MSB:
                    PrChirpCtrlModes.bits_st.Tx3PrPhaseAddQpskControl = 1u;
                    PrChirpCtrlModes.bits_st.Tx3PrPhaseMsbReplaceWithQpskControl = 0u;
                    break;

                default:
                    ErrCode = BC_ERR_TE_DDMASETTING;
                    break;
                }
            }
        }

        if (BC_ERR_NOERROR == ErrCode)
        {
            ErrCode = BC_SPI_WriteCheck(e_SYS_TE, R2M04_TX_PR_CHIRP_CONTROL_MODES_U16, PrChirpCtrlModes.val_u32);
        }

        if (BC_ERR_NOERROR == ErrCode)
        {
            ErrCode = BC_TE_SetPRDDMACtrls(pUseDDMA, DDMAMode, pDDMAInitPhase, pDDMAPhaseUpdate);
        }
    }
    else
    {
        ErrCode = BC_ERR_SYS_PTR_ADDR_NULL;
    }
    return ErrCode;
}

BC_ERRCODE Helper_ES2_MCLKIntegrityCheck(void)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    float32_t CountPeriod = MCLK_SERCLK_FREQ_COUNT_TIME;
    float32_t Frequency;
    SYS_IPList_t SysAppConfig = {FALSE};

    ErrCode = BC_CC_GetAppConfiguration(&SysAppConfig, NULL);
    if (ErrCode == BC_ERR_NOERROR)
    {
        if (SysAppConfig.MIPI == TRUE)
        {
            ErrCode = BC_MIPI_MeasureFreq(e_MIPI_IGNORE_ZEROTH_BIT, CountPeriod, &Frequency);
        }
        else
        {
            if (SysAppConfig.LVDS == TRUE)
            {
                ErrCode = BC_LVDS_MeasureFreq(e_LVDS_IGNORE_0_BIT, CountPeriod, &Frequency);
            }
            else
            {
                ErrCode = BC_ERR_SYS_WRONG_APPCONFIG;
            }
        }
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        // will change this based on the validation results
        if ((Frequency < (MCLK_SERCLK_REF_FREQUENCY - MCLK_SERCLK_FREQ_TOLERANCE_HZ)) || (Frequency > (MCLK_SERCLK_REF_FREQUENCY + MCLK_SERCLK_FREQ_TOLERANCE_HZ)))
        {
            ErrCode = BC_ERR_SYS_MCLK_INTEGRITY_FAILED;
        }
    }
    return ErrCode;
}

BC_ERRCODE Helper_ES2_TXSensorIntegrityCheck(void)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    uint32_t TxErrorMonU32 = 0u;
    uint32_t DynamicPowerControlU32 = 0u;
    SYS_IPList_t AppConfig = {FALSE};
    BOOL DynPowModeRegUpdated = FALSE;
    BOOL TxSenIntegrityOK = FALSE;

    ErrCode = BC_CC_GetAppConfiguration(&AppConfig, NULL);
    // //Tx, LOI and Chirp is out of power saving mode
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = Helper_ES2_DisbleDynPwrCntrl(&AppConfig, &DynPowModeRegUpdated, &DynamicPowerControlU32);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = Helper_ES2_Monitor_RTMReadTxErr(&TxErrorMonU32);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = Helper_ES2_Monitor_TxRfMinErr();
    }
    // Enable Local TX
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = Helper_ES2_EnableTxCtrl(&AppConfig, TRUE, FALSE);
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = PLF_TM_Sleep(SYS_LOCALTX_ON_WAITIME_IN_US);
    }
    /*Reset ISM errors*/
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_ISM_ResetISMErr(FALSE, FALSE, FALSE, TRUE); /*Reset counter and SPI errors */
    }
    /* Perform integrity checks */
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = Helper_ES2_CheckTxIntegrity(&AppConfig, &TxSenIntegrityOK);
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = Helper_ES2_RevertIntegChkChange(&AppConfig, TxErrorMonU32, DynPowModeRegUpdated, DynamicPowerControlU32, TxSenIntegrityOK);
    }
    return ErrCode;
}
BC_ERRCODE Helper_ES2_CAFCSensorIntegrityCheck(SYS_ProfID_e ChirpProfSel, uint16_t NumChirp)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    uint32_t RestoreChirpSequenceCtrl = 0u;
    R2M04_ChirpSequenceControlUnion_t ChirpSeqCtrl;
    R2M04_ChirpTriggerModeControlUnion_t ChirpTriggerModeCtrl;
    uint32_t StoredChirpGlblReg = 0x0u;
    uint32_t StoredChirpTriggerMode = 0x0u;
    uint32_t StoredIpLevelPonEnable = 0x0u;
    BOOL UseStoredChirpTrigger = FALSE;
    uint32_t RestoreCSeqInterval = 0u;
    uint32_t StoreTxPrDelayControl = 0u;
    if ((ChirpProfSel <= e_SYS_PROFILE_8) && (NumChirp > 0u) && (NumChirp < 0xFFFFu))
    {
        // first reset the ISM errors
        ErrCode = BC_ISM_ResetISMErr(FALSE, FALSE, FALSE, TRUE);
        /* Basically we are checking the level and frequency error path integrity*/
        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = BC_SPI_Read(e_SYS_TE, R2M04_CHIRP_SEQUENCE_CONTROL_U16, &ChirpSeqCtrl.val_u32);
            if (ErrCode == BC_ERR_NOERROR)
            {
                RestoreChirpSequenceCtrl = ChirpSeqCtrl.val_u32;
                ChirpSeqCtrl.bits_st.NoOfChirpInASequence = NumChirp;
                ErrCode = BC_SPI_Write(e_SYS_TE, R2M04_CHIRP_SEQUENCE_CONTROL_U16, ChirpSeqCtrl.val_u32);
            }
        }
        if (BC_ERR_NOERROR == ErrCode)
        {
            ErrCode = BC_SPI_Read(e_SYS_TE, R2M04_CHIRP_TRIGGER_MODE_CONTROL_U16, &ChirpTriggerModeCtrl.val_u32);
            if (BC_ERR_NOERROR == ErrCode)
            {
                // Change external chirp trigger to SPI trigger mode
                if (ChirpTriggerModeCtrl.bits_st.ChirpTriggerMode > (uint8_t)e_TE_CH_TRG_SPI_TRIGGER)
                {
                    // preserve current trigger mode setting
                    StoredChirpTriggerMode = ChirpTriggerModeCtrl.val_u32;
                    UseStoredChirpTrigger = TRUE;
                    ChirpTriggerModeCtrl.bits_st.ChirpTriggerMode = (uint8_t)e_TE_CH_TRG_SPI_TRIGGER;
                    ErrCode = BC_SPI_Write(e_SYS_TE, R2M04_CHIRP_TRIGGER_MODE_CONTROL_U16, ChirpTriggerModeCtrl.val_u32);
                }
            }
        }
        if (BC_ERR_NOERROR == ErrCode)
        {
            ErrCode = Helper_ES2_ReduceSeqIntervalTime(ChirpProfSel, NumChirp, &StoreTxPrDelayControl, &RestoreCSeqInterval, &StoredChirpGlblReg);
        }
        if (BC_ERR_NOERROR == ErrCode)
        {
            ErrCode = Helper_ES2_DisableTxRxLo(&StoredIpLevelPonEnable);
        }
        if (BC_ERR_NOERROR == ErrCode)
        {
            ErrCode = Helper_ES2_CheckVcoLevelMinErr();
        }
        if (BC_ERR_NOERROR == ErrCode)
        {
            ErrCode = Helper_ES2_CheckPLLUnlockErr();
        }
        if (BC_ERR_NOERROR == ErrCode)
        {
            ErrCode = Helper_ES2_TrigChirpCheckErr();
        }
        if (BC_ERR_NOERROR == ErrCode)
        {
            ErrCode = Helper_ES2_RestoreTxRxLo(StoredIpLevelPonEnable);
        }
        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = BC_ISM_ResetISMErr(FALSE, FALSE, FALSE, TRUE);
        }
        if ((ErrCode == BC_ERR_NOERROR) || (ErrCode == BC_ERR_SYS_CAFCINTEGRITY_CHECK_UNLOCK) || (ErrCode == BC_ERR_SYS_CAFCINTEGRITY_CHECK_LEVEL) || (ErrCode == BC_ERR_SYS_CAFCINTEGRITY_CHECK_FAILED))
        {
            ErrCode = Helper_ES2_RestoreTERegs(RestoreChirpSequenceCtrl, UseStoredChirpTrigger, StoredChirpTriggerMode, StoreTxPrDelayControl, RestoreCSeqInterval, StoredChirpGlblReg, ErrCode);
        }
    }
    else
    {
        ErrCode = BC_ERR_INPUTOUTOFRANGE;
    }
    return ErrCode;
}

BC_ERRCODE Helper_ES2_SetCSOut(TE_CSOutCfg_t *pCSOutCfg)
{

    R2M04_ChirpTriggerModeControlUnion_t TEChirpTriggerModeCtrl;
    // R2M00_PinMuxUnion_t PinMuxSel;
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    if (pCSOutCfg != NULL)
    {
        ErrCode = BC_SPI_Read(e_SYS_TE, R2M04_CHIRP_TRIGGER_MODE_CONTROL_U16, &TEChirpTriggerModeCtrl.val_u32);
        if (BC_ERR_NOERROR == ErrCode)
        {
            if (pCSOutCfg->CSOUTFunSel < e_TE_CSOUT_INVALID)
            {
                TEChirpTriggerModeCtrl.bits_st.McuintChirpstartPadOutFuncSel = (uint8_t)(pCSOutCfg->CSOUTFunSel);
            }
            if (pCSOutCfg->CSINFunSel < e_TE_CSIN_INVALID)
            {
                TEChirpTriggerModeCtrl.bits_st.ChirpstartInPadFuncSel = (uint8_t)(pCSOutCfg->CSINFunSel);
            }

            if ((pCSOutCfg->CSOUTFunSel == e_TE_CSOUT_INT_EVENT) || (pCSOutCfg->CSINFunSel == e_TE_CSIN_INT_EVENT))
            { /*If pad_out or in_pad  is based on interrupts event*/
                if (pCSOutCfg->ReadyIntMode < e_TE_READYINT_INVALID)
                {
                    TEChirpTriggerModeCtrl.bits_st.ReadyIntModeSel = (uint8_t)(pCSOutCfg->ReadyIntMode);
                }
            }

            if ((pCSOutCfg->CSOUTFunSel == e_TE_CSOUT_BASEDON_CS_OUT) || (pCSOutCfg->CSINFunSel == e_TE_CSIN_BASEDON_CS_OUT))
            { /*If pad out or in_pad is based on sel mode for chirpt start out filed*/
                TEChirpTriggerModeCtrl.bits_st.SelModeForChirpStartOut = (uint8_t)(pCSOutCfg->ChirpStartOutMode);
            }
            ErrCode = BC_SPI_WriteCheck(e_SYS_TE, R2M04_CHIRP_TRIGGER_MODE_CONTROL_U16, TEChirpTriggerModeCtrl.val_u32);
        }
    }
    else
    {
        ErrCode = BC_ERR_SYS_PTR_ADDR_NULL;
    }
    return ErrCode;
}

BC_ERRCODE Helper_ES2_ReadTempSensor(float32_t *pKelvinTX1, float32_t *pKelvinTX2, float32_t *pKelvinTX3, float32_t *pKelvinChirp)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    uint8_t TempModuleSelect = 0x0u;
    uint8_t TempModuleSelectCafc = 0x0u;
    uint8_t TempModuleSelectTX1 = 0x0u;
    uint8_t TempModuleSelectTX2 = 0x0u;
    uint8_t TempModuleSelectTX3 = 0x0u;
    uint32_t TemperatureDelay = 0u;

    /* Calculate temperature measure delay and enable TEMP DIGITIZER */
    ErrCode = Helper_CalcTempDelay(pKelvinTX1, pKelvinTX2, pKelvinTX3, pKelvinChirp, &TempModuleSelect, &TempModuleSelectCafc, &TempModuleSelectTX1, &TempModuleSelectTX2, &TempModuleSelectTX3, &TemperatureDelay);

    /*Each module temperature measurement takes 10us(Init time)+2*16(No. of samples)*400ns(2.5MHz clock)+50*25ns = 24us at ADC clock 2.5MHz*/
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = PLF_TM_Sleep(TemperatureDelay);
    }

    if (((TempModuleSelectTX1 == 0x01u) || (TempModuleSelectTX2 == 0x01u) || (TempModuleSelectTX3 == 0x01u)) && (ErrCode == BC_ERR_NOERROR))
    {
        ErrCode = Helper_ES2_ReadTxTemperature(pKelvinTX1, pKelvinTX2, pKelvinTX3);
    }
    if ((TempModuleSelectCafc == 0x1u) && (ErrCode == BC_ERR_NOERROR))
    {
        ErrCode = Helper_ES2_ReadCAFCTemperature(pKelvinChirp);
    }

    return ErrCode;
}

BC_ERRCODE Helper_ES2_RegCRCCheckCtrl(SYS_CRC_Trigger_Event_e CRCTriggerEvent)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    R2M18_RegCrcCheckCtrlUnion_t RegCrcCheckCtrl;
    ErrCode = BC_SPI_Read(e_SYS_ISM, R2M18_REG_CRC_CHECK_CTRL_U16, &RegCrcCheckCtrl.val_u32);
    if (BC_ERR_NOERROR == ErrCode)
    {
        switch (CRCTriggerEvent)
        {
        case e_SYS_CRC_TRIGGER_EVENT_NO_CRC_TRIGGER:
        case e_SYS_CRC_TRIGGER_EVENT_AT_END_OF_CHIRP:
        case e_SYS_CRC_TRIGGER_EVENT_AT_START_OF_CHIRP:
        {
            RegCrcCheckCtrl.bits_st.CrcCheckTriggerEvent = (uint8_t)CRCTriggerEvent;
            ErrCode = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_REG_CRC_CHECK_CTRL_U16, RegCrcCheckCtrl.val_u32);
        }
        break;
        case e_SYS_CRC_TRIGGER_EVENT_MCU_TRIGGER:
        {
            RegCrcCheckCtrl.bits_st.CrcCheckTriggerEvent = (uint8_t)CRCTriggerEvent;
            ErrCode = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_REG_CRC_CHECK_CTRL_U16, RegCrcCheckCtrl.val_u32);
            if (BC_ERR_NOERROR == ErrCode)
            {
                RegCrcCheckCtrl.bits_st.CrcCheckTriggerMcu = 0x01u;
                ErrCode = BC_SPI_Write(e_SYS_ISM, R2M18_REG_CRC_CHECK_CTRL_U16, RegCrcCheckCtrl.val_u32);
            }
        }
        break;
        default:
            ErrCode = BC_ERR_SYS_INVALID_INPUT;
            break;
        }
    }
    return ErrCode;
}
BC_ERRCODE Helper_ES2_RegCRCMCUTrigIntCheck(void)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    BC_ERRCODE ErrCodeTmp = BC_ERR_NOERROR;
    SYS_RegCRCErrors_t RegCRCErr;
    BOOL RestoreCRCInjectReg = FALSE;
    BOOL RestoreCRCCheck = FALSE;
    uint32_t StoreCRCCheckValue = 0u;

    // Clear all the ISM errors
    ErrCode = BC_ISM_ResetISMErr(FALSE, FALSE, FALSE, TRUE);
    // check there should not be any ISM register CRC errors
    if (BC_ERR_NOERROR == ErrCode)
    {
        RegCRCErr.ISMRegCRCErr = FALSE;
        ErrCode = BC_ISM_GetRegCRCErrStatus(FALSE, &RegCRCErr, NULL);
        if ((BC_ERR_NOERROR == ErrCode) && (RegCRCErr.ISMRegCRCErr == TRUE))
        {
            ErrCode = BC_ERR_SYS_REGCRC_ISMMODULE_ERROR_SET;
        }
    }
    // Inject the ISM register CRC errors, do manual trigger and check error is  ISM registered CRC generated
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = Helper_ES2_InjectCRCError(&RestoreCRCInjectReg, &RestoreCRCCheck, &StoreCRCCheckValue);
        if (BC_ERR_NOERROR == ErrCode)
        {
            ErrCode = BC_ISM_ResetISMErr(FALSE, FALSE, FALSE, TRUE);
        }
    }
    // restore the CC_CRC_ERROR_INJECTION and REG_CRC_CHECK_CTRL always, if changed
    ErrCodeTmp = Helper_ES2_RestoreCRCRegs(RestoreCRCInjectReg, RestoreCRCCheck, StoreCRCCheckValue);
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = ErrCodeTmp;
    }

    return ErrCode;
}

BC_ERRCODE Helper_ES2_LoiBBDCheck(BOOL CheckLOIN, BOOL NormalSensitivityLOIN, BOOL GroundedLOIN, BOOL NormalSensitivityLOOUT, BOOL GroundedLOOUT)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M18_McLoCcIsmOtpErrorFlagMaskedStatusUnion_t McLoCcIsmOtpErrorFlagMask;
    McLoCcIsmOtpErrorFlagMask.val_u32 = 0u;
    BOOL CheckLOOUT;

    CheckLOOUT = (CheckLOIN == TRUE) ? FALSE : TRUE;

    // Reset active ISM Flags
    ErrCode = BC_ISM_ResetISMErr(FALSE, FALSE, FALSE, TRUE);

    // Enable BBD for the given setting
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_LOI_ConfigBBD(CheckLOIN, CheckLOOUT, NormalSensitivityLOIN, GroundedLOIN, NormalSensitivityLOOUT, GroundedLOOUT);
    }

    // Disable BBD
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_LOI_ConfigBBD(FALSE, FALSE, FALSE, FALSE, FALSE, FALSE);
    }

    // Read ISM Flags
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SPI_Read(e_SYS_ISM, R2M18_MC_LO_CC_ISM_OTP_ERROR_FLAG_MASKED_STATUS_U16, &McLoCcIsmOtpErrorFlagMask.val_u32);
    }

    if (BC_ERR_NOERROR == ErrCode)
    {
        // Only LO IN or LO OUT will be enabled for a device at a time
        if ((CheckLOIN == TRUE) && (McLoCcIsmOtpErrorFlagMask.bits_st.BbLoinErrorFlagInterfaceMaskedStatus == 1u))
        {
            ErrCode = BC_ERR_SYS_LOI_IN_BALL_BREAK_DETECTED;
        }
        else
        {
            if ((CheckLOOUT == TRUE) && (McLoCcIsmOtpErrorFlagMask.bits_st.BbLooutErrorFlagInterfaceMaskedStatus == 1u))
            {
                ErrCode = BC_ERR_SYS_LOI_OUT_BALL_BREAK_DETECTED;
            }
        }
    }

    return ErrCode;
}

static BC_ERRCODE Helper_ES2_CheckErrorN(void)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    BOOL ErrorNHigh = FALSE;
    ErrCode = BC_ISM_ResetISMErr(FALSE, TRUE, TRUE, TRUE);
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = PLF_HIO_GetIO(e_SYS_ERRORN, &ErrorNHigh);
        if (ErrorNHigh != TRUE)
        {
            ErrCode = BC_ERR_SYS_ERROR_N;
        }
    }
    return ErrCode;
}

BC_ERRCODE Helper_ES2_InitMasterSlaveMode(BOOL EnSlaveMode)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    SYS_IPList_t AppConfig = {FALSE};

    ErrCode = Helper_ES2_InitSPIChkLoadOTPSer(&AppConfig);
    if ((TRUE == EnSlaveMode) && (TRUE == AppConfig.CAFC))
    {
        ErrCode = BC_ERR_SYS_SLAVE_WRONG_APPCONFIG;
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = Helper_ES2_InitClkOTPGldoGbiaLdo();
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = Helper_ES2_InitCAFCConfMClkMSPC(EnSlaveMode);
    }

    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = Helper_ES2_InitPOnLOITxRxADCSaft();
    }

    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = Helper_ES2_InitMCModErNSerLOBuf(EnSlaveMode);
    }

    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = Helper_ES2_InitFITCheckSNS();
    }
    return ErrCode;
}

BC_ERRCODE Helper_ES2_AutoSubbandSwitching(BOOL Enable, uint8_t SubbandSteps)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M06_SubbandAmpCorrectionModeSelUnion_t SubbandAmpCorrectionModeSel;

    if (SubbandSteps > 0xFu)
    {
        ErrCode = BC_ERR_SYS_SUBBANDINC_OUTOFRANGE;
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_SUBBAND_AMP_CORRECTION_MODE_SEL_U16, &SubbandAmpCorrectionModeSel.val_u32);
        if (BC_ERR_NOERROR == ErrCode)
        {
            // same value of subband increment and decrement is used as described in user manual
            SubbandAmpCorrectionModeSel.bits_st.SubbandDecrement = SubbandSteps;
            SubbandAmpCorrectionModeSel.bits_st.SubbandIncrement = SubbandSteps;
            SubbandAmpCorrectionModeSel.bits_st.SubbandCorrectionEnable = Enable;
            ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, R2M06_SUBBAND_AMP_CORRECTION_MODE_SEL_U16, SubbandAmpCorrectionModeSel.val_u32);
        }
        // Chirp type is set to Progressive (do not load accumulator)
        if (BC_ERR_NOERROR == ErrCode)
        {
            ErrCode = BC_SC_SetSweepCtrlMode(Enable, FALSE);
        }
    }
    return ErrCode;
}

BC_ERRCODE Helper_ES2_SetDevice(PLF_SPITarget_e TargetDevice)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    ErrCode = BC_CC_SetMSDevice(TargetDevice);
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = PLF_SYS_SetTarget(TargetDevice);
    }
    return ErrCode;
}

static BC_ERRCODE Helper_ES2_CheckVcoLevelMinErr(void)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    SYS_CAFCErrors_t ChirpErr;
    R2M06_VcoEnableSettingsUnion_t VcoEnableSettings;
    ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_VCO_ENABLE_SETTINGS_U16, &VcoEnableSettings.val_u32);
    if (BC_ERR_NOERROR == ErrCode)
    { // Disabling VCO;
        VcoEnableSettings.bits_st.CtlVcoEnSpi = (uint8_t)FALSE;
        ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, R2M06_VCO_ENABLE_SETTINGS_U16, VcoEnableSettings.val_u32);
    }

    if (ErrCode == BC_ERR_NOERROR)
    {
        // trigger chirp
        ErrCode = BC_TE_StartChirp();
    }

    if (ErrCode == BC_ERR_NOERROR)
    {
        // wait using polling method
        ErrCode = BC_TE_WaitForReady();
    }

    // Reconfig Enabling VCO;
    if (BC_ERR_NOERROR == ErrCode)
    {
        VcoEnableSettings.bits_st.CtlVcoEnSpi = (uint8_t)TRUE;
        ErrCode = BC_SPI_Write(e_SYS_CAFC, R2M06_VCO_ENABLE_SETTINGS_U16, VcoEnableSettings.val_u32);
    }

    if (ErrCode == BC_ERR_NOERROR)
    {
        // check the Chirp error
        ErrCode = BC_ISM_GetChirpErrStatus(e_ISM_GET_MASKED_ERR, &ChirpErr, NULL);
        if (ErrCode == BC_ERR_NOERROR)
        {
            if ((ChirpErr.VCOLevelMinErr == FALSE))
            {
                ErrCode = BC_ERR_SYS_CAFCINTEGRITY_CHECK_LEVEL;
            }
            else
            {
                ErrCode = BC_ISM_ResetISMErr(FALSE, FALSE, FALSE, TRUE);
            }
        }
    }

    return ErrCode;
}
static BC_ERRCODE Helper_ES2_CheckPLLUnlockErr(void)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M06_LpfEnableSettingsUnion_t LpfEnableSettings;
    SYS_CAFCErrors_t ChirpErr;

    ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_LPF_ENABLE_SETTINGS_U16, &LpfEnableSettings.val_u32);
    if (BC_ERR_NOERROR == ErrCode)
    {
        // disable loop filter
        LpfEnableSettings.bits_st.CtlLpfIntEnSpi = 0u;
        ErrCode = BC_SPI_Write(e_SYS_CAFC, R2M06_LPF_ENABLE_SETTINGS_U16, LpfEnableSettings.val_u32);
    }

    if (ErrCode == BC_ERR_NOERROR)
    {
        // trigger chirp
        ErrCode = BC_TE_StartChirp();
    }

    if (ErrCode == BC_ERR_NOERROR)
    {
        // wait using polling method
        ErrCode = BC_TE_WaitForReady();
    }

    if (BC_ERR_NOERROR == ErrCode)
    {
        // enable loop filter
        LpfEnableSettings.bits_st.CtlLpfIntEnSpi = 1u;
        ErrCode = BC_SPI_Write(e_SYS_CAFC, R2M06_LPF_ENABLE_SETTINGS_U16, LpfEnableSettings.val_u32);
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        // check the Chirp error
        ErrCode = BC_ISM_GetChirpErrStatus(e_ISM_GET_MASKED_ERR, &ChirpErr, NULL);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        if (ChirpErr.PLLUnlockErr == FALSE)
        {
            ErrCode = BC_ERR_SYS_CAFCINTEGRITY_CHECK_UNLOCK;
        }
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_ReduceSeqIntervalTime(SYS_ProfID_e ChirpProfSel, uint16_t NumChirp, uint32_t *pStoreTxPrDelayControl, uint32_t *pRestoreCSeqInterval, uint32_t *pStoredChirpGlblReg)
{
    BC_ERRCODE ErrCode;
    R2M04_ChirpSequenceIntervalControlUnion_t CSeqInterval;
    R2M04_TxPrDelayControlUnion_t TxPrDelayControl;
    R2M04_ChirpGlobalControlUnion_t ChirpGlblCtrl;

    ErrCode = BC_SPI_Read(e_SYS_TE, R2M04_CHIRP_GLOBAL_CONTROL_U16, &ChirpGlblCtrl.val_u32);
    if (BC_ERR_NOERROR == ErrCode)
    {
        // preserve current profile setting
        *pStoredChirpGlblReg = ChirpGlblCtrl.val_u32;
        // change it to using profile
        ChirpGlblCtrl.bits_st.ChirpProfileSelect = (uint8_t)ChirpProfSel;
        ErrCode = BC_SPI_Write(e_SYS_TE, R2M04_CHIRP_GLOBAL_CONTROL_U16, ChirpGlblCtrl.val_u32);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        // disabling safety check for the CAFC integrity check if enabled
        ErrCode = BC_SPI_Read(e_SYS_TE, R2M04_TX_PR_DELAY_CONTROL_U16, &TxPrDelayControl.val_u32);
        if (BC_ERR_NOERROR == ErrCode)
        {
            *pStoreTxPrDelayControl = TxPrDelayControl.val_u32;
            if (TxPrDelayControl.bits_st.PrSafetyEnable == 1u)
            {
                TxPrDelayControl.bits_st.PrSafetyEnable = (uint8_t)0u;
                /*Writing back the values*/
                ErrCode = BC_SPI_Write(e_SYS_TE, R2M04_TX_PR_DELAY_CONTROL_U16, TxPrDelayControl.val_u32);
            }
        }
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        R2M04_TimingControl3Profile0Union_t Ctr3ProfX;
        R2M04_DcPowerOnDelayControlUnion_t DCPowOnDelyCtrl;
        uint16_t TimingControl3RegAddr;
        TimingControl3RegAddr = R2M04_TIMING_CONTROL_3_PROFILE0_U16 + ((uint16_t)ChirpProfSel * 0x10u);
        ErrCode = BC_SPI_Read(e_SYS_TE, TimingControl3RegAddr, &Ctr3ProfX.val_u32);
        // Reducing the sequence interval time according to number of chirp.
        if (BC_ERR_NOERROR == ErrCode)
        {
            ErrCode = BC_SPI_Read(e_SYS_TE, R2M04_DC_POWER_ON_DELAY_CONTROL_U16, &DCPowOnDelyCtrl.val_u32);
        }
        if (BC_ERR_NOERROR == ErrCode)
        {
            uint32_t SeqInterval = DCPowOnDelyCtrl.bits_st.DcPoweronDelay + (Ctr3ProfX.bits_st.ChirpIntervalTimerProfile0 * NumChirp);
            /*Allowed values : 0x00000001 to 0xFFFFFFFEu, change the value only, if it is with-in range*/
            if ((SeqInterval >= 1u) && (SeqInterval < 0xFFFFFFFFu))
            {
                ErrCode = BC_SPI_Read(e_SYS_TE, R2M04_CHIRP_SEQUENCE_INTERVAL_CONTROL_U16, &CSeqInterval.val_u32);
                if (BC_ERR_NOERROR == ErrCode)
                {
                    *pRestoreCSeqInterval = CSeqInterval.val_u32;
                    CSeqInterval.bits_st.ChirpSequenceInterval = (uint32_t)SeqInterval;
                    ErrCode = BC_SPI_Write(e_SYS_TE, R2M04_CHIRP_SEQUENCE_INTERVAL_CONTROL_U16, CSeqInterval.val_u32);
                }
            }
        }
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_DisableTxRxLo(uint32_t *pStoredIpLevelPonEnable)
{
    BC_ERRCODE ErrCode;
    R2M00_IpLevelPonEnableUnion_t IpLevelPonEnable;

    ErrCode = BC_SPI_Read(e_SYS_CC, R2M00_IP_LEVEL_PON_ENABLE_U16, &IpLevelPonEnable.val_u32);
    if (BC_ERR_NOERROR == ErrCode)
    {
        // preserve current power setting
        *pStoredIpLevelPonEnable = IpLevelPonEnable.val_u32;

        // Power off RX,TX and LO
        IpLevelPonEnable.bits_st.PonLoInterfaceEn = FALSE;
        IpLevelPonEnable.bits_st.PonRx1En = FALSE;
        IpLevelPonEnable.bits_st.PonRx2En = FALSE;
        IpLevelPonEnable.bits_st.PonRx3En = FALSE;
        IpLevelPonEnable.bits_st.PonRx4En = FALSE;
        IpLevelPonEnable.bits_st.PonTx1En = FALSE;
        IpLevelPonEnable.bits_st.PonTx2En = FALSE;
        IpLevelPonEnable.bits_st.PonTx3En = FALSE;
        ErrCode = BC_SPI_WriteCheck(e_SYS_CC, R2M00_IP_LEVEL_PON_ENABLE_U16, IpLevelPonEnable.val_u32);
    }
    return ErrCode;
}

static BC_ERRCODE Helper_ES2_RestoreTxRxLo(uint32_t StoredIpLevelPonEnable)
{
    BC_ERRCODE ErrCode;

    ErrCode =  BC_SPI_WriteCheck(e_SYS_CC, R2M00_IP_LEVEL_PON_ENABLE_U16, StoredIpLevelPonEnable);
    return ErrCode;

}

static BC_ERRCODE Helper_ES2_RestoreTERegs(uint32_t RestoreChirpSequenceCtrl, BOOL UseStoredChirpTrigger, uint32_t StoredChirpTriggerMode, uint32_t StoreTxPrDelayControl, uint32_t RestoreCSeqInterval, uint32_t StoredChirpGlblReg, BC_ERRCODE InputErrCode)
{
    R2M04_TxPrDelayControlUnion_t TxPrDelayControl;
    TxPrDelayControl.val_u32 = StoreTxPrDelayControl;
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    // restore number of chirp
    ErrCode = BC_SPI_WriteCheck(e_SYS_TE, R2M04_CHIRP_SEQUENCE_CONTROL_U16, RestoreChirpSequenceCtrl);
    if (BC_ERR_NOERROR == ErrCode)
    {
        // restore chirp profile setting
        ErrCode = Helper_ES2_RestoreChirpGlobal(StoredChirpGlblReg);
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        // restore sequence interval setting
        ErrCode = BC_SPI_WriteCheck(e_SYS_TE, R2M04_CHIRP_SEQUENCE_INTERVAL_CONTROL_U16, RestoreCSeqInterval);
    }
    if ((UseStoredChirpTrigger == TRUE) && (BC_ERR_NOERROR == ErrCode))
    {
        // restore trigger mode setting
        ErrCode = BC_SPI_WriteCheck(e_SYS_TE, R2M04_CHIRP_TRIGGER_MODE_CONTROL_U16, StoredChirpTriggerMode);
    }
    // Only in case of SafetyCheck was enable previously we restore it otherwise not needed
    if ((TxPrDelayControl.bits_st.PrSafetyEnable == 1u) && (BC_ERR_NOERROR == ErrCode))
    {
        // restore safety check setting
        TxPrDelayControl.bits_st.PrSafetyEnable = (uint8_t)1u;
        /*Writing back the values*/
        ErrCode = BC_SPI_WriteCheck(e_SYS_TE, R2M04_TX_PR_DELAY_CONTROL_U16, TxPrDelayControl.val_u32);
    }
    ErrCode = (ErrCode == BC_ERR_NOERROR) ? InputErrCode : ErrCode;

    return ErrCode;
}

static BC_ERRCODE Helper_ES2_EnableMSPCPFDSupply(void)
{
    BC_ERRCODE ErrCode;
    R2M0C_MspcControl1Union_t MspcControl1;
    // Not needed the Workaround for ES1, cascaded phase issue: automatic calibration solution, since reset value of MSPC_TRIM_SETTINGS.bits_st.MspcTrimCtrl already equals to 7u;
    ErrCode = BC_SPI_Read(e_SYS_MCLK, R2M0C_MSPC_CONTROL1_U16, &MspcControl1.val_u32);
    if (BC_ERR_NOERROR == ErrCode)
    {
        // Es2 reset value is already MspcControl1.bits_st.MspcClkmuxCtrl equals 3u;
        MspcControl1.bits_st.MspcPfd1V1Ena = 1u;
        MspcControl1.bits_st.MspcPfd1V8Ena = 1u;
        ErrCode = BC_SPI_WriteCheck(e_SYS_MCLK, R2M0C_MSPC_CONTROL1_U16, MspcControl1.val_u32);
    }
    /* before first MSPC measurement 60us wait is required 50us wait is added since startMSPC API  has one read call */
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = PLF_TM_Sleep(50u);
    }
    return ErrCode;
}

static BC_ERRCODE Helper_ES2_SetTempDigitizer(void)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M00_TempDigitizerAdcControlUnion_t TempDigitizerAdcControl;
    ErrCode = BC_SPI_Read(e_SYS_CC, R2M00_TEMP_DIGITIZER_ADC_CONTROL_U16, &TempDigitizerAdcControl.val_u32);
    if (ErrCode == BC_ERR_NOERROR)
    {
        TempDigitizerAdcControl.bits_st.TempDigitizerAdcClockFreq = 2u; // 2.5 MHz
        TempDigitizerAdcControl.bits_st.TempDigitizerAdcSamples = 4u;   // 16 samples
        ErrCode = BC_SPI_WriteCheck(e_SYS_CC, R2M00_TEMP_DIGITIZER_ADC_CONTROL_U16, TempDigitizerAdcControl.val_u32);
    }
    return ErrCode;
}

static BC_ERRCODE Helper_ES2_SetCalMonMaxOffsetErr(BOOL EnADC12, BOOL EnADC34)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M07_CalMonitorMaxErrorUnion_t CalMonitorMaxError;

    if (EnADC12 == TRUE)
    {
        ErrCode = BC_SPI_Read(e_SYS_ADC12, R2M07_CAL_MONITOR_MAX_ERROR_U16, &CalMonitorMaxError.val_u32);
        if (ErrCode == BC_ERR_NOERROR)
        {
            CalMonitorMaxError.bits_st.CalMonitorMaxOffsetError = 192u;
            ErrCode = BC_SPI_WriteCheck(e_SYS_ADC12, R2M07_CAL_MONITOR_MAX_ERROR_U16, CalMonitorMaxError.val_u32);
        }
    }

    if ((EnADC34 == TRUE) && (ErrCode == BC_ERR_NOERROR))
    {
        ErrCode = BC_SPI_Read(e_SYS_ADC34, R2M07_CAL_MONITOR_MAX_ERROR_U16, &CalMonitorMaxError.val_u32);
        if (ErrCode == BC_ERR_NOERROR)
        {
            CalMonitorMaxError.bits_st.CalMonitorMaxOffsetError = 192u;
            ErrCode = BC_SPI_WriteCheck(e_SYS_ADC34, R2M07_CAL_MONITOR_MAX_ERROR_U16, CalMonitorMaxError.val_u32);
        }
    }

    return ErrCode;
}

static BC_ERRCODE Helper_ES2_SetStableSampling(void)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M0C_ClkselUnion_t Clksel;
    ErrCode = BC_SPI_Read(e_SYS_MCLK, R2M0C_CLKSEL_U16, &Clksel.val_u32);
    if (ErrCode == BC_ERR_NOERROR)
    {
        Clksel.bits_st.ClkselAdc40Negedge = 0u;
        ErrCode = BC_SPI_WriteCheck(e_SYS_MCLK, R2M0C_CLKSEL_U16, Clksel.val_u32);
    }
    return ErrCode;
}

BC_ERRCODE Helper_ES2_InitConfigADC(void)
{
    BC_ERRCODE ErrCode;
    BOOL EnADC12 = FALSE;
    BOOL EnADC34 = FALSE;
    SYS_IPList_t AppConfig = {FALSE};

    ErrCode = Helper_ES2_SetStableSampling();

    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_CC_GetAppConfiguration(&AppConfig, NULL);
    }

    if (BC_ERR_NOERROR == ErrCode)
    {
        EnADC12 = AppConfig.ADC12;
        EnADC34 = AppConfig.ADC34;
        ErrCode = BC_ADC_PowerOn(EnADC12, EnADC34);
    }
    if (BC_ERR_NOERROR == ErrCode)
    { /*Set ADC in dynamic power mode per sequence */
        CC_DynPowDnIPList_t PowDnIPList;
        PowDnIPList.SetADC = e_CC_DYN_POWMODE_PERSEQUENCE;
        PowDnIPList.SetChirp = e_CC_DYN_POWMODE_NONE;
        PowDnIPList.SetRx1 = e_CC_DYN_POWMODE_NONE;
        PowDnIPList.SetRx2 = e_CC_DYN_POWMODE_NONE;
        PowDnIPList.SetRx3 = e_CC_DYN_POWMODE_NONE;
        PowDnIPList.SetRx4 = e_CC_DYN_POWMODE_NONE;
        PowDnIPList.SetTx1 = e_CC_DYN_POWMODE_NONE;
        PowDnIPList.SetTx2 = e_CC_DYN_POWMODE_NONE;
        PowDnIPList.SetTx3 = e_CC_DYN_POWMODE_NONE;
        PowDnIPList.SetLoInterface = e_CC_DYN_POWMODE_NONE;
        PowDnIPList.SetADCBGClib = e_CC_DYN_POWMODE_NONE;
        ErrCode = BC_CC_SetDynPowModeDown(&PowDnIPList, 1.0f, 1.0f);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = Helper_ES2_SetTempDigitizer();
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = Helper_ES2_SetCalMonMaxOffsetErr(EnADC12, EnADC34);
    }
    return ErrCode;
}

static BC_ERRCODE Helper_ES2_ConfigureSerialInterface(SYS_IPList_t *pAppConfig)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    if ((pAppConfig->LVDS == TRUE) && (pAppConfig->MIPI == FALSE))
    {
        ErrCode = BC_CC_SetInterface(e_CC_LVDS);
    }
    else if ((pAppConfig->LVDS == FALSE) && (pAppConfig->MIPI == TRUE))
    {
        ErrCode = BC_CC_SetInterface(e_CC_MIPI);
    }
    else
    {
        ErrCode = BC_ERR_SYS_WRONG_APPCONFIG;
    }
    return ErrCode;
}

BC_ERRCODE Helper_ES2_Init(void)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    SYS_IPList_t AppConfig = {FALSE};

    ErrCode = Helper_ES2_InitSPIChkLoadOTPSer(&AppConfig);

    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = Helper_ES2_InitClkOTPGldoGbiaLdo();
    }

    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SYS_Init_ConfigCAFC();
    }

    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SYS_Init_ConfigMCLK();
    }

    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = Helper_ES2_InitPOnLOITxRxADCSaft();
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = Helper_ES2_ConfigMCLKClkDetector(e_MCLK_CLKDET_STANDALONE_MODE);
    }
    /*Checking for ERROR_N*/
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = Helper_ES2_CheckErrorN();
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SYS_Init_InitDataInterface();
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = Helper_ES2_InitFITCheckSNS();
    }

    return ErrCode;
}
static BC_ERRCODE Helper_ES2_ConfigMCLKClkDetector(MCLK_CLKDetMode_e CLKDetMode)
{
    BC_ERRCODE ErrCode;
    R2M0C_ClkDetEnConfigUnion_t ClkDetEnConfig;

    ErrCode = BC_SPI_Read(e_SYS_MCLK, R2M0C_CLK_DET_EN_CONFIG_U16, &ClkDetEnConfig.val_u32);
    if (BC_ERR_NOERROR == ErrCode)
    {
        ClkDetEnConfig.bits_st.ClkDetMode = (uint8_t)CLKDetMode;
        ErrCode = BC_SPI_Write(e_SYS_MCLK, R2M0C_CLK_DET_EN_CONFIG_U16, ClkDetEnConfig.val_u32);
    }
    return ErrCode;
}

BC_ERRCODE Helper_ES2_ConfigCAFC(SYS_ProfID_e ProfID, SYS_ProfChirpFreq_t *pChirpFreq)
{
    BC_ERRCODE ErrCode;

    if (pChirpFreq == NULL)
    {
        ErrCode = BC_ERR_SYS_PTR_ADDR_NULL;
    }
    else
    {
        switch (pChirpFreq->SBSearch)
        {
        case e_SYS_SBSEARCH_KEEP_CURRENT:
            // keep iVCO and subband untouched.
            ErrCode = BC_CAFC_ConfigVCOProfile(ProfID, pChirpFreq->VCOSel, pChirpFreq->PLLLPFSel, 64u, 128u);
            break;
        case e_SYS_SBSEARCH_FORCE:
            // force iVCO and subband
            ErrCode = BC_CAFC_ConfigVCOProfile(ProfID, pChirpFreq->VCOSel, pChirpFreq->PLLLPFSel, pChirpFreq->iVCOFine, pChirpFreq->Subband);
            break;
        case e_SYS_SBSEARCH_AAFC_AUTO:
            ErrCode = BC_ERR_SYS_AAFC_AUTO_NOT_SUPPORTED;
            break;
        case e_SYS_SBSEARCH_AAFC_SPI_TRIG:
            // keep iVCO and subband untouched.
            ErrCode = BC_CAFC_ConfigVCOProfile(ProfID, pChirpFreq->VCOSel, pChirpFreq->PLLLPFSel, 64u, 128u);
            break;
        case e_SYS_SBSEARCH_SW_ASSIST:
            // feature not implemented.
            ErrCode = BC_ERR_INPUTOUTOFRANGE;
            break;
        default:
            ErrCode = BC_ERR_INPUTOUTOFRANGE;
            break;
        }
    }

    return ErrCode;
}

static BC_ERRCODE Helper_ES2_RestoreDynPwrCntrl(BOOL DynPowModeRegUpdated, uint32_t DynamicPowerControlU32)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    if (DynPowModeRegUpdated == TRUE)
    {
        ErrCode = BC_SPI_WriteCheck(e_SYS_CC, R2M00_DYNAMIC_POWER_CONTROL_ENABLE_U16, DynamicPowerControlU32);
    }

    return ErrCode;
}

static BC_ERRCODE Helper_ES2_DisbleDynPwrCntrl(SYS_IPList_t *pAppConfig, BOOL *pDynPowModeRegUpdated, uint32_t *DynamicPowerControlU32)
{
    BC_ERRCODE ErrCode;
    BOOL ChirpDynPowEnable = FALSE;
    R2M00_DynamicPowerControlEnableUnion_t DynamicPowerControlEnable;

    *pDynPowModeRegUpdated = FALSE;
    ErrCode = BC_SPI_Read(e_SYS_CC, R2M00_DYNAMIC_POWER_CONTROL_ENABLE_U16, &DynamicPowerControlEnable.val_u32);
    if (ErrCode == BC_ERR_NOERROR)
    {
        *DynamicPowerControlU32 = DynamicPowerControlEnable.val_u32;
        if (DynamicPowerControlEnable.bits_st.LoInterfaceDyPowerControl == TRUE)
        {
            DynamicPowerControlEnable.bits_st.LoInterfaceDyPowerControl = FALSE;
        }
        if (DynamicPowerControlEnable.bits_st.ChirpDyPowerControl == TRUE)
        {
            ChirpDynPowEnable = TRUE;
            DynamicPowerControlEnable.bits_st.ChirpDyPowerControl = FALSE;
        }
        if ((DynamicPowerControlEnable.bits_st.Tx1DyPowerControl == TRUE) && (pAppConfig->TX1 == TRUE))
        {
            DynamicPowerControlEnable.bits_st.Tx1DyPowerControl = FALSE;
        }
        if ((DynamicPowerControlEnable.bits_st.Tx2DyPowerControl == TRUE) && (pAppConfig->TX2 == TRUE))
        {
            DynamicPowerControlEnable.bits_st.Tx2DyPowerControl = FALSE;
        }
        if ((DynamicPowerControlEnable.bits_st.Tx3DyPowerControl == TRUE) && (pAppConfig->TX3 == TRUE))
        {
            DynamicPowerControlEnable.bits_st.Tx3DyPowerControl = FALSE;
        }
        if (*DynamicPowerControlU32 != DynamicPowerControlEnable.val_u32)
        {
            *pDynPowModeRegUpdated = TRUE;
            ErrCode = BC_SPI_Write(e_SYS_CC, R2M00_DYNAMIC_POWER_CONTROL_ENABLE_U16, DynamicPowerControlEnable.val_u32);
            // This is done to fast biasing the PLL
            if ((BC_ERR_NOERROR == ErrCode) && (ChirpDynPowEnable == TRUE))
            {
                ErrCode = BC_CAFC_FastBiasChirpPll();
            }
        }
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_CheckTxIntegrity(SYS_IPList_t *pAppConfig, BOOL *pTxSenIntegrityOK)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    BOOL CheckFlag = TRUE;

    /*Read errros Tx min error should be TRUE */
    ErrCode = Helper_ES2_CheckTxErr(pAppConfig, CheckFlag, pTxSenIntegrityOK);
    if ((ErrCode == BC_ERR_NOERROR) && (*pTxSenIntegrityOK == TRUE))
    {
        ErrCode = Helper_ES2_EnableTxCtrl(pAppConfig, TRUE, TRUE);
        if (BC_ERR_NOERROR == ErrCode)
        {
            ErrCode = PLF_TM_Sleep(SYS_LOCALTX_ON_WAITIME_IN_US);
        }
        /*Reset ISM errors*/
        if (PLF_NOERROR == ErrCode)
        {
            ErrCode = BC_ISM_ResetISMErr(FALSE, FALSE, FALSE, TRUE); /*Reset counter and SPI errors */
        }
        if (BC_ERR_NOERROR == ErrCode)
        { /*Read errros again this time Tx min error should be FALSE */
            CheckFlag = FALSE;
            ErrCode = Helper_ES2_CheckTxErr(pAppConfig, CheckFlag, pTxSenIntegrityOK);
        }
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_RevertIntegChkChange(SYS_IPList_t *pAppConfig, uint32_t TxErrorMonU32, BOOL DynPowModeRegUpdated, uint32_t DynamicPowerControlU32, BOOL TxSenIntegrityOK)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    // disable TX
    ErrCode = Helper_ES2_EnableTxCtrl(pAppConfig, FALSE, FALSE);
    if (ErrCode == BC_ERR_NOERROR)
    { // Revert always monitoring by restoring the original value of Tx Error Monitor Reg
        ErrCode = Helper_ES2_Monitor_RTMWriteTxErr(TxErrorMonU32);
    }
    if (ErrCode == BC_ERR_NOERROR)
    { // Revert Dynamic Power Control Enable
        ErrCode = Helper_ES2_RestoreDynPwrCntrl(DynPowModeRegUpdated, DynamicPowerControlU32);
    }
    /*Reset ISM errors*/
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_ISM_ResetISMErr(FALSE, FALSE, FALSE, TRUE); /*Reset counter and SPI errors */
    }
    if ((BC_ERR_NOERROR == ErrCode) && (TxSenIntegrityOK == FALSE))
    {
        ErrCode = BC_ERR_TX_SENSORFITFAIL;
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_CheckTxErr(SYS_IPList_t *pAppConfig, BOOL CheckFlag, BOOL *pTxSenIntegrityOK)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    SYS_TXErrors_t Tx1 = {FALSE};
    SYS_TXErrors_t Tx2 = {FALSE};
    SYS_TXErrors_t Tx3 = {FALSE};
    BOOL Tx1Error;
    BOOL Tx2Error;
    BOOL Tx3Error;

    /*Read errros again*/
    ErrCode = BC_ISM_GetTxErrStatus(e_ISM_GET_MASKED_ERR, &Tx1, &Tx2, &Tx3, NULL);
    if (BC_ERR_NOERROR == ErrCode)
    {
        // if TX is not enabled error will not be generated so making it equal to CheckFlag (TRUE/FALSE)
        Tx1Error = (pAppConfig->TX1 == TRUE) ? Tx1.TxRfLevelMinErr : CheckFlag;
        Tx2Error = (pAppConfig->TX2 == TRUE) ? Tx2.TxRfLevelMinErr : CheckFlag;
        Tx3Error = (pAppConfig->TX3 == TRUE) ? Tx3.TxRfLevelMinErr : CheckFlag;
        if ((Tx1Error == CheckFlag) && (Tx2Error == CheckFlag) && (Tx3Error == CheckFlag))
        {
            *pTxSenIntegrityOK = TRUE;
        }
        else
        {
            *pTxSenIntegrityOK = FALSE;
        }
    }
    return ErrCode;
}
static uint8_t Helper_TempModSel(float32_t *pKelvinTX, uint32_t *pTemperatureDelay)
{
    uint8_t RetModSel = 0x0u;
    if (pKelvinTX != NULL)
    {
        RetModSel = (*pKelvinTX > 0.0f) ? 0x01u : 0x00u;
        *pTemperatureDelay += SYS_TEMP_MEASUREMENT_DELAY_24US;
    }

    return RetModSel;
}

static BC_ERRCODE Helper_CalcTempDelay(float32_t *pKelvinTX1, float32_t *pKelvinTX2, float32_t *pKelvinTX3, float32_t *pKelvinChirp, uint8_t *pTempModuleSelect, uint8_t *pTempModuleSelectCafc, uint8_t *pTempModuleSelectTX1, uint8_t *pTempModuleSelectTX2, uint8_t *pTempModuleSelectTX3, uint32_t *pTemperatureDelay)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M00_TempDigitizerFuncControlUnion_t TempDigFuncControl;

    if ((pKelvinTX1 == NULL) && (pKelvinTX2 == NULL) && (pKelvinTX3 == NULL) && (pKelvinChirp == NULL))
    {
        ErrCode = BC_ERR_SYS_PTR_ADDR_NULL;
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        *pTempModuleSelectTX1 = Helper_TempModSel(pKelvinTX1, pTemperatureDelay);
        *pTempModuleSelectTX2 = Helper_TempModSel(pKelvinTX2, pTemperatureDelay);
        *pTempModuleSelectTX3 = Helper_TempModSel(pKelvinTX3, pTemperatureDelay);
        if (pKelvinChirp != NULL)
        {
            *pTempModuleSelectCafc = (*pKelvinChirp > 0.0f) ? 0x01u : 0x00u;
            *pTemperatureDelay = (*pTemperatureDelay == 0u) ? SYS_TEMP_MEASUREMENT_DELAY_24US : *pTemperatureDelay;
        }
        *pTempModuleSelect = ((*pTempModuleSelectTX1 << 0x00U) | (*pTempModuleSelectTX2 << 0x01U) | (*pTempModuleSelectTX3 << 0x02U) | (*pTempModuleSelectCafc << 0x03U)) & 0x0Fu;

        /*Enable the TEMP DIGITIZER*/
        TempDigFuncControl.val_u32 = 0u;
        TempDigFuncControl.bits_st.EnableTempDigitizer = 0x1u;
        TempDigFuncControl.bits_st.TempDigitizerTsModuleSelect = *pTempModuleSelect;
        /*Trigger temp digitizer statemachine and it should be called after module select*/
        TempDigFuncControl.bits_st.TriggerTempDigitizer = 0x1u;
        ErrCode = BC_SPI_Write(e_SYS_CC, R2M00_TEMP_DIGITIZER_FUNC_CONTROL_U16, TempDigFuncControl.val_u32);
    }
    return ErrCode;
}
#endif
/* End of  file*/
