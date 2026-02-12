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
#include "helper_es2sysinit.h"
#include "bc_types.h"
#include "bc_err.h"
#include "bc_spi.h"
#include "bc_conf.h"
#include "bc_te.h"
#include "bc_ism.h"
#include "bc_cc.h"
#include "bc_loi.h"
#include "bc_cafc.h"
#include "bc_otp.h"
#include "plf.h"
// register headers
#ifdef BUILD_FOR_VAL
#include "v_es2_cc.h"
#include "v_es2_cafc.h"
#include "v_es2_gbias.h"
#include "v_es2_loi.h"
#include "v_es2_mclk.h"
#include "v_es2_gldo.h"
#include "v_es2_ism.h"
#else
#include "reg_es2_cc.h"
#include "reg_es2_cafc.h"
#include "reg_es2_gbias.h"
#include "reg_es2_loi.h"
#include "reg_es2_mclk.h"
#include "reg_es2_gldo.h"
#include "reg_es2_ism.h"
#endif

static BC_ERRCODE Helper_ES2_Clear1v1LowError(void)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    /* CLear GLDO 1v1 low/high and GLDO 1v8 low/high*/
    ErrCode = BC_SPI_WriteCheck(e_SYS_GLDO, GLDO_MASK_CC_FORCE_ERROR_U16, 0x0u);
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_SPI_WriteCheck(e_SYS_GLDO, GLDO_MASK_CC_RESET_ERROR_U16, 0x0u);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        /*SnsIntegritySupply1VxForceError and SnsIntegritySupply1VxResetError set to 0*/
        ErrCode = BC_SPI_WriteCheck(e_SYS_GLDO, R2M15_SNS_INTEGRITY_TEST_REG_U16, 0x0u);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_SPI_WriteCheck(e_SYS_GLDO, GLDO_TEST_FORCE_ERROR_U16, 0x0u);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_SPI_WriteCheck(e_SYS_GLDO, GLDO_TEST_RESET_ERROR_U16, 0x0u);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_ISM_ResetISMErr(FALSE, TRUE, TRUE, TRUE);
    }
    /* Clear ISM 1v1 low dig error*/
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_MCU_STARTUP_STATUS_CONTROL_U16, 0x0u);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_MCU_STARTUP_STATUS_CONTROL_U16, 0x1u);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_MCU_STARTUP_STATUS_CONTROL_U16, 0x3u);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_MCU_STARTUP_STATUS_CONTROL_U16, 0x7u);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_MCU_STARTUP_STATUS_CONTROL_U16, 0xFu);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_MCU_STARTUP_STATUS_CONTROL_U16, 0x1Fu);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_MCU_STARTUP_STATUS_CONTROL_U16, 0x3Fu);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_MCU_STARTUP_STATUS_CONTROL_U16, 0x7Fu);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_MCU_STARTUP_STATUS_CONTROL_U16, 0xFFu);
    }
    return ErrCode;
}
static BC_ERRCODE Helper_DistributeSupplyData(SYS_IPList_t *pSysAppConfig)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    ErrCode = BC_OTP_DistributeOTPData(e_OTP_TRIM_FR_GLDO, 0u, OTP_TRIM_FR_GLDO_COUNT);
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_OTP_DistributeOTPData(e_OTP_TRIM_SNS, 0u, OTP_TRIM_SNS_COUNT);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_OTP_DistributeOTPData(e_OTP_TRIM_GBIAS, 0u, 2u);
    }
    if ((ErrCode == BC_ERR_NOERROR) && (pSysAppConfig->CAFC == TRUE))
    {
        ErrCode = BC_OTP_DistributeOTPData(e_OTP_TRIM_GBIAS, 2u, 3u);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_OTP_DistributeOTPData(e_OTP_TRIM_GBIAS, 3u, OTP_TRIM_GBIAS_COUNT);
    }
    if ((ErrCode == BC_ERR_NOERROR) && (pSysAppConfig->ATB == TRUE))
    {
        ErrCode = BC_OTP_DistributeOTPData(e_OTP_TRIM_LOCAL_LDO, 1u, 2u);
    }
    if ((ErrCode == BC_ERR_NOERROR) && (pSysAppConfig->CAFC == TRUE))
    {
        ErrCode = BC_OTP_DistributeOTPData(e_OTP_TRIM_LOCAL_LDO, 2u, 4u);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_OTP_DistributeOTPData(e_OTP_TRIM_LOCAL_LDO, 4u, 9u);
    }
    if ((ErrCode == BC_ERR_NOERROR) && (pSysAppConfig->CAFC == TRUE))
    {
        ErrCode = BC_OTP_DistributeOTPData(e_OTP_TRIM_LOCAL_LDO, 9u, 10u);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_OTP_DistributeOTPData(e_OTP_TRIM_LOCAL_LDO, 10u, OTP_TRIM_LOCAL_LDO_COUNT);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {

        ErrCode = BC_OTP_DistributeOTPData(e_OTP_TRIM_WR_PTAT, 0u, OTP_TRIM_WR_PTAT_COUNT);
    }
    return ErrCode;
}

static BC_ERRCODE Helper_DistributeRXData(SYS_IPList_t *pSysAppConfig)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    if (pSysAppConfig->RX1 == TRUE)
    {
        //if rx1 is enbaled
        ErrCode = BC_OTP_DistributeOTPData(e_OTP_TRIM_RX1_THRESH, 0u, OTP_TRIM_RX1_THRESH_COUNT);
        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = BC_OTP_DistributeOTPData(e_OTP_TRIM_RX1_FILTER, 0u, OTP_TRIM_RX1_FILTER_COUNT);
        }
    }
    if ((ErrCode == BC_ERR_NOERROR) && (pSysAppConfig->RX2 == TRUE))
    {
        //if rx2 is enabled
        ErrCode = BC_OTP_DistributeOTPData(e_OTP_TRIM_RX2_THRESH, 0u, OTP_TRIM_RX2_THRESH_COUNT);
        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = BC_OTP_DistributeOTPData(e_OTP_TRIM_RX2_FILTER, 0u, OTP_TRIM_RX2_FILTER_COUNT);
        }
    }
    if ((ErrCode == BC_ERR_NOERROR) && (pSysAppConfig->RX3 == TRUE))
    {
        //if rx3 is enabled
        ErrCode = BC_OTP_DistributeOTPData(e_OTP_TRIM_RX3_THRESH, 0u, OTP_TRIM_RX3_THRESH_COUNT);
        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = BC_OTP_DistributeOTPData(e_OTP_TRIM_RX3_FILTER, 0u, OTP_TRIM_RX3_FILTER_COUNT);
        }
    }
    if ((ErrCode == BC_ERR_NOERROR) && (pSysAppConfig->RX4 == TRUE))
    {
        //if rx4 is enabled
        ErrCode = BC_OTP_DistributeOTPData(e_OTP_TRIM_RX4_THRESH, 0u, OTP_TRIM_RX4_THRESH_COUNT);
        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = BC_OTP_DistributeOTPData(e_OTP_TRIM_RX4_FILTER, 0u, OTP_TRIM_RX4_FILTER_COUNT);
        }
    }
    return ErrCode;
}

static BC_ERRCODE Helper_DistributeTXData(SYS_IPList_t *pSysAppConfig)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    if (pSysAppConfig->TX1 == TRUE)
    {
        //if tx1 is enabled
        ErrCode = BC_OTP_DistributeOTPData(e_OTP_TRIM_TX1_BIAS_ST3, 0u, 1u);
        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = BC_OTP_DistributeOTPData(e_OTP_TRIM_TX1_BIAS_ST12, 0u, 2u);
        }
        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = BC_OTP_DistributeOTPData(e_OTP_TRIM_TX1_THRESH, 0u, OTP_TRIM_TX1_THRESH_COUNT);
        }
    }
    if ((ErrCode == BC_ERR_NOERROR) && (pSysAppConfig->TX2 == TRUE))
    {
        //if tx2 is enabled
        ErrCode = BC_OTP_DistributeOTPData(e_OTP_TRIM_TX2_BIAS_ST3, 1u, 2u);
        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = BC_OTP_DistributeOTPData(e_OTP_TRIM_TX2_BIAS_ST12, 2u, 4u);
        }
        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = BC_OTP_DistributeOTPData(e_OTP_TRIM_TX2_THRESH, 0u, OTP_TRIM_TX2_THRESH_COUNT);
        }
    }
    if ((ErrCode == BC_ERR_NOERROR) && (pSysAppConfig->TX3 == TRUE))
    {
        //if tx3 is enabled
        ErrCode = BC_OTP_DistributeOTPData(e_OTP_TRIM_TX3_BIAS_ST3, 2u, 3u);
        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = BC_OTP_DistributeOTPData(e_OTP_TRIM_TX3_BIAS_ST12, 4u, 6u);
        }
        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = BC_OTP_DistributeOTPData(e_OTP_TRIM_TX3_THRESH, 0u, OTP_TRIM_TX3_THRESH_COUNT);
        }
    }
    return ErrCode;
}

static BC_ERRCODE Helper_DistributeCAFCData(SYS_IPList_t *pSysAppConfig)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    if (pSysAppConfig->CAFC == TRUE)
    {
        ErrCode = BC_OTP_DistributeOTPData(e_OTP_TRIM_CHIRP_THRESH, 0u, OTP_TRIM_CHIRP_THRESH_COUNT);
        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = BC_OTP_DistributeOTPData(e_OTP_TRIM_SUBBAND_CORRECTION_1G, 0u, OTP_TRIM_SUBBAND_CORRECTION_1G_COUNT);
        }
        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = BC_OTP_DistributeOTPData(e_OTP_TRIM_SUBBAND_CORRECTION_2G, 0u, OTP_TRIM_SUBBAND_CORRECTION_2G_COUNT);
        }
        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = BC_OTP_DistributeOTPData(e_OTP_TRIM_SUBBAND_CORRECTION_4G, 0u, OTP_TRIM_SUBBAND_CORRECTION_4G_COUNT);
        }
    }
    return ErrCode;
}

static BC_ERRCODE Helper_DistributeMISCData(SYS_IPList_t *pSysAppConfig)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    if (pSysAppConfig->CAFC == TRUE)
    {
        ErrCode = BC_OTP_DistributeOTPData(e_OTP_SPARE_TRIM, 0u, 1u);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        // For SSBMOD distribute otp is done after enabling SSB.
        ErrCode = BC_OTP_DistributeOTPData(e_OTP_SPARE_TRIM, 1u, OTP_SPARE_TRIM_COUNT - 1u);
    }
    if ((ErrCode == BC_ERR_NOERROR) && (pSysAppConfig->CAFC == TRUE))
    {
        ErrCode = BC_OTP_DistributeOTPData(e_OTP_TRIM_TS_THRESH, 0u, 1u);
    }
    if ((ErrCode == BC_ERR_NOERROR) && (pSysAppConfig->TX3 == TRUE))
    {
        ErrCode = BC_OTP_DistributeOTPData(e_OTP_TRIM_TS_THRESH, 1u, 2u);
    }
    if ((ErrCode == BC_ERR_NOERROR) && (pSysAppConfig->TX2 == TRUE))
    {
        ErrCode = BC_OTP_DistributeOTPData(e_OTP_TRIM_TS_THRESH, 2u, 3u);
    }
    if ((ErrCode == BC_ERR_NOERROR) && (pSysAppConfig->TX1 == TRUE))
    {
        ErrCode = BC_OTP_DistributeOTPData(e_OTP_TRIM_TS_THRESH, 3u, OTP_TRIM_TS_THRESH_COUNT);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_OTP_DistributeOTPData(e_OTP_TRIM_TX_TS_COEFF, 0u, OTP_TRIM_TX_TS_COEFF_COUNT);
    }
    if ((ErrCode == BC_ERR_NOERROR) && (pSysAppConfig->CAFC == TRUE))
    {
        ErrCode = BC_OTP_DistributeOTPData(e_OTP_TRIM_CHIRP_TS_COEFF, 0u, OTP_TRIM_CHIRP_TS_COEFF_COUNT);
    }
    return ErrCode;
}

BC_ERRCODE Helper_ES2_InitDistributeOTPData(void)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    SYS_IPList_t SysAppConfig;
    ErrCode = BC_CC_GetAppConfiguration(&SysAppConfig, NULL);

    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = Helper_DistributeSupplyData(&SysAppConfig);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = Helper_DistributeRXData(&SysAppConfig);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = Helper_DistributeTXData(&SysAppConfig);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = Helper_DistributeCAFCData(&SysAppConfig);
    }
    if ((ErrCode == BC_ERR_NOERROR) && (SysAppConfig.LOI == TRUE))
    {
        //if LOI is enabled
        ErrCode = BC_OTP_DistributeOTPData(e_OTP_TRIM_LOI_THRESH, 0u, OTP_TRIM_LOI_THRESH_COUNT);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = Helper_DistributeMISCData(&SysAppConfig);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_ISM_SetStartupStatus(e_ISM_IC_OTP_CALIBRATION_DATA_OK);
    }
    return ErrCode;
}

BC_ERRCODE Helper_ES2_InitConfigPonLdoGBIAS(void)
{
    BC_ERRCODE ErrCode;
    R2M09_GlobbiasPonIrefLocalLdoUnion_t PonIrefLocalLDO;
    uint32_t TPVersionFT = 0u;
    uint32_t FTMajorVersion = 0u;
    uint32_t FTMinorVersion = 0u;
    uint32_t GlobbiasSpare = 0x1E; // reduced from 0x24
    R2M09_GlobbiasAmpmonUnion_t GlobbiasAmpmon;

    // Rx Level MaxCode Fix
    ErrCode = BC_SPI_WriteCheck(e_SYS_GBIAS, R2M09_GLOBBIAS_SPARE_U16, GlobbiasSpare);
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_OTP_GetOTPRegValue(OTP_TP_ID_FT12_INDEX, &TPVersionFT);
        FTMajorVersion = ((TPVersionFT & OTP_ID_FT_MAJOR_MASK) >> OTP_ID_FT_MAJOR_POS);
        FTMinorVersion = (TPVersionFT & OTP_ID_FT_MINOR_MASK);
        // only for FT 2.0 default values 0x28 & 0x28 are good
        if ((ErrCode == BC_ERR_NOERROR) && ((FTMajorVersion != 0x2u) || (FTMinorVersion != 0u)))
        {
            GlobbiasAmpmon.val_u32 = 0u;
            GlobbiasAmpmon.bits_st.CtrlIrefAmpmonBgr = (uint8_t)0x2C;
            GlobbiasAmpmon.bits_st.CtrlIrefAmpmonPtatr = (uint8_t)0x2C;
            ErrCode = BC_SPI_WriteCheck(e_SYS_GBIAS, R2M09_GLOBBIAS_AMPMON_U16, GlobbiasAmpmon.val_u32);
        }
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_SPI_Read(e_SYS_GBIAS, R2M09_GLOBBIAS_PON_IREF_LOCAL_LDO_U16, &PonIrefLocalLDO.val_u32);
        if (BC_ERR_NOERROR == ErrCode)
        {
            PonIrefLocalLDO.bits_st.PonIrefLocalLdo = 1u;
            ErrCode = BC_SPI_WriteCheck(e_SYS_GBIAS, R2M09_GLOBBIAS_PON_IREF_LOCAL_LDO_U16, PonIrefLocalLDO.val_u32);
        }
    }

    return ErrCode;
}

BC_ERRCODE Helper_ES2_EnLocLDORelRSTADCSer(SYS_IPList_t *pAppConfig)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    R2M00_LdoEnableUnion_t EnableLDO;
    R2M00_IpLevelClockEnableUnion_t IpLevelClockEnable;
    R2M00_IpResetControlUnion_t IpResetControl;
#if 0    
    R2M07_CalMonitorMaxErrorUnion_t CalMonitorMaxError;
#endif
    //R1M06_LdoEnControlUnion_t LDOEnControl;
    //R1M0C_XoPllMcLdoEnableUnion_t  MCLDOEnCtrol;
    /* Get the list of IPs set by application */

    ErrCode = BC_SPI_Read(e_SYS_CC, R2M00_LDO_ENABLE_U16, &EnableLDO.val_u32);
    if (ErrCode == BC_ERR_NOERROR)
    {
        /* Even if only one of the ADC pairs is used/set by the application */
        if ((pAppConfig->ADC12 == TRUE) || (pAppConfig->ADC34 == TRUE))
        {
            EnableLDO.bits_st.LdoEnAdc = 1u;
        }
        if (pAppConfig->MIPI == TRUE)
        {
            EnableLDO.bits_st.LdoEnSerialiserCsi2 = 1u;
            EnableLDO.bits_st.LdoEnSerialiserSer = 1u;
        }
        else if (pAppConfig->LVDS == TRUE)
        {
            EnableLDO.bits_st.LdoEnSerialiserSer = 1u;
        }
        else
        {
            ErrCode = BC_ERR_SYS_WRONG_APPCONFIG;
        }
        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = BC_SPI_WriteCheck(e_SYS_CC, R2M00_LDO_ENABLE_U16, EnableLDO.val_u32);
        }
    }
    //wait for 30 micro second for local LDO to stablize
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = PLF_TM_Sleep(LOCAL_LDO_STABLIZATION_US);
    }
    //Deassert master reset and enable clock for ADC and serializer
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_SPI_Read(e_SYS_CC, R2M00_IP_LEVEL_CLOCK_ENABLE_U16, &IpLevelClockEnable.val_u32);
        if (ErrCode == BC_ERR_NOERROR)
        {
            IpLevelClockEnable.bits_st.Clk40Adc12 = pAppConfig->ADC12;
            IpLevelClockEnable.bits_st.Clk40Adc34 = pAppConfig->ADC34;
            IpLevelClockEnable.bits_st.Clk40Ser = 1u;
            ErrCode = BC_SPI_WriteCheck(e_SYS_CC, R2M00_IP_LEVEL_CLOCK_ENABLE_U16, IpLevelClockEnable.val_u32);
        }
        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = BC_SPI_Read(e_SYS_CC, R2M00_IP_RESET_CONTROL_U16, &IpResetControl.val_u32);
            if (BC_ERR_NOERROR == ErrCode)
            {
                IpResetControl.bits_st.ResetAdc12 = pAppConfig->ADC12;
                IpResetControl.bits_st.ResetAdc34 = pAppConfig->ADC34;
                IpResetControl.bits_st.ResetSer = 1u;
                ErrCode = BC_SPI_WriteCheck(e_SYS_CC, R2M00_IP_RESET_CONTROL_U16, IpResetControl.val_u32);
            }
        }
    }
    return ErrCode;
}

BC_ERRCODE Helper_ES2_ConfigSetCCClk(void)
{
    BC_ERRCODE ErrCode;
    /* since calibration is done use the calibrated clock for CC */
    R2M0C_ClkselUnion_t AdcClksel;
    R2M0C_ClkDetEnConfigUnion_t ClkDetEnConfig;
    ErrCode = BC_SPI_Read(e_SYS_MCLK, R2M0C_CLKSEL_U16, &AdcClksel.val_u32);
    if (BC_ERR_NOERROR == ErrCode)
    {
        AdcClksel.bits_st.ClkselCc40Calclk = 0x1u;
        ErrCode = BC_SPI_WriteCheck(e_SYS_MCLK, R2M0C_CLKSEL_U16, AdcClksel.val_u32);
    }
    /* glitches seen at the start of chirp, solution is to keep the 40MHz clock always on, instead of on-demand */
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_SPI_Read(e_SYS_MCLK, R2M0C_CLK_DET_EN_CONFIG_U16, &ClkDetEnConfig.val_u32);
        if (ErrCode == BC_ERR_NOERROR)
        {
            ClkDetEnConfig.bits_st.AlwaysEnableChirpSerXoClk = TRUE;
            ErrCode = BC_SPI_WriteCheck(e_SYS_MCLK, R2M0C_CLK_DET_EN_CONFIG_U16, ClkDetEnConfig.val_u32);
        }
    }
    return ErrCode;
}

BC_ERRCODE Helper_ES2_InitConfigMCLK(void)
{
    BC_ERRCODE ErrCode;
    R2M0C_ResetCalibrationUnion_t ResetCalibration;

    ErrCode = BC_SPI_Read(e_SYS_MCLK, R2M0C_RESET_CALIBRATION_U16, &ResetCalibration.val_u32);
    if (ErrCode == BC_ERR_NOERROR)
    {
        ResetCalibration.bits_st.RstAn = 1u;
        ErrCode = BC_SPI_WriteCheck(e_SYS_MCLK, R2M0C_RESET_CALIBRATION_U16, ResetCalibration.val_u32);
    }
    // once the RST pin is high the Mckl PLL automatically perform two calibration long calibration (initial calibration)
    // and short calibration (re calibration) it takes around 550 microseconds but because of es2 issue 5000 microseconds is required
    // Update: Updated wait to 550 ms since this issue is resolved in ES2 samples
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = PLF_TM_Sleep(MCLK_PLL_INIT_STABILISE_TIME_FIX);
    }
    return ErrCode;
}

BC_ERRCODE Helper_ES2_InitConfigCAFC(void)
{
    BC_ERRCODE ErrCode;
    R2M06_ChirpCalibrationAacControl1Union_t AACControl1;
    R2M06_AdditionalHwSettingsUnion_t AdditionalHWSettings;
    R2M06_ControlSpareUnion_t ControlSpare;
    R2M06_LoopFilterCounterInitUnion_t LoopFilterCounterInit;
    R2M06_KvcoDvdtConfigControlUnion_t KvcoDvdtConfigControl;
    uint8_t ReduceFactor = 3u;
    //leave chargepump disabled, enable LDO and all biases
    ErrCode = BC_CAFC_ConfigStatic(FALSE, TRUE, TRUE, TRUE, TRUE);
    if (BC_ERR_NOERROR == ErrCode)
    {
        R2M06_FuncsafeMonLevelSettingsUnion_t FuncsafeMonLevelSettings;
        ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_FUNCSAFE_MON_LEVEL_SETTINGS_U16, &FuncsafeMonLevelSettings.val_u32);
        if (BC_ERR_NOERROR == ErrCode)
        {
            // Adec in equal to (low+high)/2
            uint8_t TempAdesIn = FuncsafeMonLevelSettings.bits_st.CtlLevelVcoLowSpi + FuncsafeMonLevelSettings.bits_st.CtlLevelVcoHighSpi;
            TempAdesIn = TempAdesIn >> 1u;
            ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_CHIRP_CALIBRATION_AAC_CONTROL1_U16, &AACControl1.val_u32);
            if (BC_ERR_NOERROR == ErrCode)
            {
                AACControl1.bits_st.AacAdesIn = (uint8_t)TempAdesIn;
                ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, R2M06_CHIRP_CALIBRATION_AAC_CONTROL1_U16, AACControl1.val_u32);
            }
        }
    }
    /* For ES2 e_SYS_CAFCTX_FC_CLOSE_AUTO is default/reset setting of N_START_RF_CAL_CENTER_FREQ_SEL */
    /*Down chirp polarity is now controlled form Sweep control for IDAC  */
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_ADDITIONAL_HW_SETTINGS_U16, &AdditionalHWSettings.val_u32);
        if (BC_ERR_NOERROR == ErrCode)
        {
            AdditionalHWSettings.bits_st.IdacPolarityFromSweepControl = (uint8_t)1u;
            // it is not required to change LD polarity
            AdditionalHWSettings.bits_st.LdPolarityFromSweepControl = (uint8_t)0u;
            ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, R2M06_ADDITIONAL_HW_SETTINGS_U16, AdditionalHWSettings.val_u32);
        }
    }
    // enabling Chirp module temperature read out in dynamic power mode
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_CONTROL_SPARE_U16, &ControlSpare.val_u32);
        if (BC_ERR_NOERROR == ErrCode)
        {
            ControlSpare.bits_st.CtlTsInPdEn = (uint8_t)1u;
            ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, R2M06_CONTROL_SPARE_U16, ControlSpare.val_u32);
        }
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_LOOP_FILTER_COUNTER_INIT_U16, &LoopFilterCounterInit.val_u32);
        if (ErrCode == BC_ERR_NOERROR)
        { //override reset counter by auto clear needed for HW based DVDT measurement
            LoopFilterCounterInit.bits_st.OverrideResetCounter = 1u;
            ErrCode = BC_SPI_Write(e_SYS_CAFC, R2M06_LOOP_FILTER_COUNTER_INIT_U16, LoopFilterCounterInit.val_u32);
        }
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_KVCO_DVDT_CONFIG_CONTROL_U16, &KvcoDvdtConfigControl.val_u32);
        if (ErrCode == BC_ERR_NOERROR)
        {
            KvcoDvdtConfigControl.bits_st.CtlLpfProgForceVoltageLowSpi = (uint8_t)(KvcoDvdtConfigControl.bits_st.CtlLpfProgForceVoltageLowSpi - ReduceFactor);
            KvcoDvdtConfigControl.bits_st.CtlLpfProgForceVoltageHighSpi = (uint8_t)(KvcoDvdtConfigControl.bits_st.CtlLpfProgForceVoltageHighSpi - ReduceFactor);
            ErrCode = BC_SPI_Write(e_SYS_CAFC, R2M06_KVCO_DVDT_CONFIG_CONTROL_U16, KvcoDvdtConfigControl.val_u32);
        }
    }
    return ErrCode;
}

BC_ERRCODE Helper_ES2_InitConfigCAFCFuSa(void)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    R2M06_RmsControlUnion_t RMSControl;
    R2M06_FuncsafeMonLevelSettingsEnUnion_t CafcFuncsafeMonLevelSettingsEn;
    R2M06_LpfEnableSettingsUnion_t LpfEnableSettings;

    //Enable rms detector and select output of power detector
    ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_RMS_CONTROL_U16, &RMSControl.val_u32);
    if (BC_ERR_NOERROR == ErrCode)
    {
        RMSControl.bits_st.ChirpRmsEnSpi = 1u;
        RMSControl.bits_st.ChirpMeasInOutSpi = 1u;
        ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, R2M06_RMS_CONTROL_U16, RMSControl.val_u32);
    }

    // Enable level monitor
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_FUNCSAFE_MON_LEVEL_SETTINGS_EN_U16, &CafcFuncsafeMonLevelSettingsEn.val_u32);
        if (BC_ERR_NOERROR == ErrCode)
        {
            CafcFuncsafeMonLevelSettingsEn.bits_st.CtlLevelVcoAmpMonitorEnSpi = 1u;
            ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, R2M06_FUNCSAFE_MON_LEVEL_SETTINGS_EN_U16, CafcFuncsafeMonLevelSettingsEn.val_u32);
        }
    }
    // Vtune Monitor ( Threshold values are coming from OTP)
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SPI_Read(e_SYS_CAFC, R2M06_LPF_ENABLE_SETTINGS_U16, &LpfEnableSettings.val_u32);
        if (BC_ERR_NOERROR == ErrCode)
        {
            LpfEnableSettings.bits_st.CtlLpfVtuneMonitorEnSpi = 1u;
            ErrCode = BC_SPI_WriteCheck(e_SYS_CAFC, R2M06_LPF_ENABLE_SETTINGS_U16, LpfEnableSettings.val_u32);
        }
    }
    // Unlock Monitor Enable
    // ES2 Reset value of lock detector is 1 enabled, so no need of SPI write

    return ErrCode;
}

BC_ERRCODE Helper_ES2_InitGLDOSelfTest(void)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M18_SupplyErrorFlagMaskedStatusUnion_t SupplyErrorFlagMaskedStatus;
    R2M18_SsbGbSerGldoAtbErrorMonRegUnion_t SupplyErrorMonReg;
    R2M15_SnsIntegrityTestRegUnion_t SnsIntegrityTestReg;
    /*To back-up and restore flag states*/
    uint32_t SupplyErrorMonRegBackup;
    /*Error check of low threshold (1v1/1v8)*/
    BOOL LowErrorCheck = FALSE;
    /*Error check of high threshold (1v1/1v8)*/
    BOOL HighErrorCheck = FALSE;
    BOOL ReadSuccess = FALSE;

    ErrCode = BC_SPI_Read(e_SYS_ISM, R2M18_SSB_GB_SER_GLDO_ATB_ERROR_MON_REG_U16, &SupplyErrorMonReg.val_u32);
    if (BC_ERR_NOERROR == ErrCode)
    {
        ReadSuccess = TRUE;
        /*Storing the supply error flag (defualt)status*/
        SupplyErrorMonRegBackup = SupplyErrorMonReg.val_u32;
        /*Setting error monitoring to be "through out"*/
        SupplyErrorMonReg.bits_st.SupplyLowErrorFlag1V1GlobalLdoMon = 1u;
        SupplyErrorMonReg.bits_st.SupplyHighErrorFlag1V1GlobalLdoMon = 1u;
        SupplyErrorMonReg.bits_st.SupplyLowErrorFlag1V8GlobalLdoMon = 1u;
        SupplyErrorMonReg.bits_st.SupplyHighErrorFlag1V8GlobalLdoMon = 1u;
        ErrCode = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_SSB_GB_SER_GLDO_ATB_ERROR_MON_REG_U16, SupplyErrorMonReg.val_u32);
    }

    // Force Low and High error
    if (BC_ERR_NOERROR == ErrCode)
    {
        SnsIntegrityTestReg.val_u32 = 0u;
        SnsIntegrityTestReg.bits_st.SnsIntegritySupply1VxForceError = 1u;
        ErrCode = BC_SPI_WriteCheck(e_SYS_GLDO, R2M15_SNS_INTEGRITY_TEST_REG_U16, SnsIntegrityTestReg.val_u32);
    }
    /*Reset ISM errors*/
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_ISM_ResetISMErr(FALSE, FALSE, FALSE, TRUE); /*Reset counter and SPI errors */
    }
    /*Read the Low and High error status*/
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SPI_Read(e_SYS_ISM, R2M18_SUPPLY_ERROR_FLAG_MASKED_STATUS_U16, &SupplyErrorFlagMaskedStatus.val_u32);
        LowErrorCheck = SupplyErrorFlagMaskedStatus.bits_st.SupplyLowErrorFlag1V1GlobalLdoSupplyMaskedStatus &
                        SupplyErrorFlagMaskedStatus.bits_st.SupplyLowErrorFlag1V8GlobalLdoSupplyMaskedStatus;
        HighErrorCheck = SupplyErrorFlagMaskedStatus.bits_st.SupplyHighErrorFlag1V1GlobalLdoSupplyMaskedStatus &
                         SupplyErrorFlagMaskedStatus.bits_st.SupplyHighErrorFlag1V8GlobalLdoSupplyMaskedStatus;
    }
    /*If any of the four error did not occur; then there is some error*/
    if ((LowErrorCheck == FALSE) || (HighErrorCheck == FALSE))
    {
        ErrCode = BC_ERR_GLDO_SNS_FORCEERROR;
    }
    //Reset Low & high Error
    if (BC_ERR_NOERROR == ErrCode)
    {
        SnsIntegrityTestReg.bits_st.SnsIntegritySupply1VxForceError = 0u;
        SnsIntegrityTestReg.bits_st.SnsIntegritySupply1VxResetError = 1u;
        ErrCode = BC_SPI_WriteCheck(e_SYS_GLDO, R2M15_SNS_INTEGRITY_TEST_REG_U16, SnsIntegrityTestReg.val_u32);
    }
    /*Reset ISM errors*/
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_ISM_ResetISMErr(FALSE, FALSE, FALSE, TRUE); /*Reset counter and SPI errors */
    }
    /*Read the high and low error status*/
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SPI_Read(e_SYS_ISM, R2M18_SUPPLY_ERROR_FLAG_MASKED_STATUS_U16, &SupplyErrorFlagMaskedStatus.val_u32);
        LowErrorCheck = SupplyErrorFlagMaskedStatus.bits_st.SupplyLowErrorFlag1V1GlobalLdoSupplyMaskedStatus &
                        SupplyErrorFlagMaskedStatus.bits_st.SupplyLowErrorFlag1V8GlobalLdoSupplyMaskedStatus;
        HighErrorCheck = SupplyErrorFlagMaskedStatus.bits_st.SupplyHighErrorFlag1V1GlobalLdoSupplyMaskedStatus &
                         SupplyErrorFlagMaskedStatus.bits_st.SupplyHighErrorFlag1V8GlobalLdoSupplyMaskedStatus;
    }

    if (BC_ERR_NOERROR == ErrCode)
    {
        SnsIntegrityTestReg.bits_st.SnsIntegritySupply1VxResetError = 0u;
        ErrCode = BC_SPI_WriteCheck(e_SYS_GLDO, R2M15_SNS_INTEGRITY_TEST_REG_U16, SnsIntegrityTestReg.val_u32);
    }
    /*If any of the four error not cleared, then there is some error*/
    if ((LowErrorCheck != FALSE) || (HighErrorCheck != FALSE))
    {
        ErrCode = BC_ERR_GLDO_SNS_RESETERROR;
    }
    if (ReadSuccess == TRUE)
    {
        /*Restoring supply error flag*/
        (void)BC_SPI_WriteCheck(e_SYS_ISM, R2M18_SSB_GB_SER_GLDO_ATB_ERROR_MON_REG_U16, SupplyErrorMonRegBackup);
    }
    if (BC_ERR_NOERROR != ErrCode)
    {
        /*workaround for FTS if SnsIntegrityCheck fails */
        ErrCode = Helper_ES2_Clear1v1LowError();
    }
    return ErrCode;
}
BC_ERRCODE Helper_ES2_InitPowerOnModules(void)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    SYS_IPList_t SysAppConfig;
    R2M00_IpLevelPonEnableUnion_t IpLevelPonEnable;
    R2M00_IpFunctionalResetControlUnion_t IpFunctionalResetRelease;

    /* Get the list of 'desired' IPs */
    ErrCode = BC_CC_GetAppConfiguration(&SysAppConfig, NULL);
    if (ErrCode == BC_ERR_NOERROR)
    {
        IpLevelPonEnable.val_u32 = 0x0u;
        IpLevelPonEnable.bits_st.PonAdc12En = (uint8_t)SysAppConfig.ADC12;
        IpLevelPonEnable.bits_st.PonAdc34En = (uint8_t)SysAppConfig.ADC34;
        IpLevelPonEnable.bits_st.PonAtbEn = (uint8_t)SysAppConfig.ATB;
        IpLevelPonEnable.bits_st.PonChirpEn = ((SysAppConfig.CAFC == TRUE) && (SysAppConfig.SC == TRUE)) ? (uint8_t)TRUE : (uint8_t)FALSE;
        IpLevelPonEnable.bits_st.PonGlobalBiasEn = (uint8_t)SysAppConfig.GBIAS;
        IpLevelPonEnable.bits_st.PonGlobalLdoEn = (uint8_t)SysAppConfig.GLDO;
        IpLevelPonEnable.bits_st.PonLoInterfaceEn = (uint8_t)SysAppConfig.LOI;
        /*ISM power can not be controlled*/
        IpLevelPonEnable.bits_st.PonMasterClkEn = (uint8_t)SysAppConfig.MCLK;
        IpLevelPonEnable.bits_st.PonOtpEn = (uint8_t)SysAppConfig.OTP;
        IpLevelPonEnable.bits_st.PonRx1En = (uint8_t)SysAppConfig.RX1;
        IpLevelPonEnable.bits_st.PonRx2En = (uint8_t)SysAppConfig.RX2;
        IpLevelPonEnable.bits_st.PonRx3En = (uint8_t)SysAppConfig.RX3;
        IpLevelPonEnable.bits_st.PonRx4En = (uint8_t)SysAppConfig.RX4;
        IpLevelPonEnable.bits_st.PonSerEn = ((SysAppConfig.LVDS == TRUE) || (SysAppConfig.MIPI == TRUE)) ? (uint8_t)TRUE : (uint8_t)FALSE;
        /*SSBMOD is not to be powered on at this stage*/
        IpLevelPonEnable.bits_st.PonSsbmodEn = (uint8_t)FALSE;
        IpLevelPonEnable.bits_st.PonTx1En = (uint8_t)SysAppConfig.TX1;
        IpLevelPonEnable.bits_st.PonTx2En = (uint8_t)SysAppConfig.TX2;
        IpLevelPonEnable.bits_st.PonTx3En = (uint8_t)SysAppConfig.TX3;
        /* Temperature digitizer is PON*/
        IpLevelPonEnable.bits_st.PonTempDigitizerEn = (uint8_t)TRUE;
        /* Power on the IPs - except SSBMOD */
        ErrCode = BC_SPI_WriteCheck(e_SYS_CC, R2M00_IP_LEVEL_PON_ENABLE_U16, IpLevelPonEnable.val_u32);
        if (ErrCode == BC_ERR_NOERROR)
        {
            IpFunctionalResetRelease.val_u32 = 0x0u;
            IpFunctionalResetRelease.bits_st.FnResetAdc12 = (uint8_t)SysAppConfig.ADC12;
            IpFunctionalResetRelease.bits_st.FnResetAdc34 = (uint8_t)SysAppConfig.ADC34;
            IpFunctionalResetRelease.bits_st.FnResetAtb = (uint8_t)SysAppConfig.ATB;
            IpFunctionalResetRelease.bits_st.FnResetChirp = (uint8_t)SysAppConfig.TE;
            IpFunctionalResetRelease.bits_st.FnResetGlobalBias = (uint8_t)SysAppConfig.GBIAS;
            IpFunctionalResetRelease.bits_st.FnResetGlobalLdo = (uint8_t)SysAppConfig.GLDO;
            IpFunctionalResetRelease.bits_st.FnResetLoInterface = (uint8_t)SysAppConfig.LOI;
            /* ISM is out of reset after a POR  to support start up */
            IpFunctionalResetRelease.bits_st.FnResetIsm = (uint8_t)TRUE;
            IpFunctionalResetRelease.bits_st.FnResetMasterClk = (uint8_t)SysAppConfig.MCLK;
            /* otp can not be reset*/
            IpFunctionalResetRelease.bits_st.FnResetRx1 = (uint8_t)SysAppConfig.RX1;
            IpFunctionalResetRelease.bits_st.FnResetRx2 = (uint8_t)SysAppConfig.RX2;
            IpFunctionalResetRelease.bits_st.FnResetRx3 = (uint8_t)SysAppConfig.RX3;
            IpFunctionalResetRelease.bits_st.FnResetRx4 = (uint8_t)SysAppConfig.RX4;
            IpFunctionalResetRelease.bits_st.FnResetSer = ((SysAppConfig.LVDS == TRUE) || (SysAppConfig.MIPI == TRUE)) ? (uint8_t)TRUE : (uint8_t)FALSE;
            /*SSBMOD is not to be powered on at this stage*/
            IpFunctionalResetRelease.bits_st.FnResetSsbmod = (uint8_t)FALSE;
            IpFunctionalResetRelease.bits_st.FnResetTx1 = (uint8_t)SysAppConfig.TX1;
            IpFunctionalResetRelease.bits_st.FnResetTx2 = (uint8_t)SysAppConfig.TX2;
            IpFunctionalResetRelease.bits_st.FnResetTx3 = (uint8_t)SysAppConfig.TX3;
            ErrCode = BC_SPI_WriteCheck(e_SYS_CC, R2M00_IP_FUNCTIONAL_RESET_CONTROL_U16, IpFunctionalResetRelease.val_u32);
        }
    }
    /*The Local LDO settling time*/
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = PLF_TM_Sleep(SYS_LDO_SETTLE_TIME); /*50 usec*/
    }
    return ErrCode;
}
BC_ERRCODE Helper_ES2_ConfigISM(void)
{
    SYS_ADCErrors_t ADCEr = {FALSE}; /*Note: Same is used for ADC12 & ADC34 */
    SYS_MCLKErrors_t MClkErr = {FALSE};
    SYS_LOIErrors_t LOIErr = {FALSE};
    SYS_CCErrors_t CCEr = {FALSE};

    SYS_SerialiserErrors_t SerErr = {FALSE};
    SYS_SSBErrors_t SSBErr = {FALSE};
    SYS_GBIASErrors_t GBErr = {FALSE};
    SYS_GLDOErrors_t GLDOErr = {FALSE};
    SYS_CAFCErrors_t ChirpErr = {FALSE};
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    SYS_RXErrors_t RXErr = {FALSE}; /*Note: same is used for RX1,2,3 & 4*/
    SYS_TXErrors_t TxErr = {FALSE}; /*Note: same is used for TX1,2 & 3*/

    //ConfigFirstError
    ErrCode = BC_ISM_CfgFirstErrWar(e_ISM_CHIRPSEQ_COUNTER_CHIRPSEQ_START, e_ISM_CHIRPSEQ_COUNTER_CHIRPSEQ_START);

    //Monitoring mode(always/real time) and masking of safety sensors
    if (BC_ERR_NOERROR == ErrCode)
    {
        /*Note that the following will be applicable for both ADC12 & ADC34*/
        ADCEr.ADCn0CalErr = TRUE;
        ADCEr.ADCn1CalErr = TRUE;
        ADCEr.ADCSupply1v8LowErr = TRUE;

        ErrCode = BC_ISM_MaskRTMSetClrADCErr(e_ISM_ERR_OP_MONITOR_ERR, &ADCEr, &ADCEr);
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        MClkErr.MclkPllCalErr = TRUE;
        MClkErr.MclkPllLevelErr = TRUE;
        MClkErr.MclkPllLockErr = TRUE;
        MClkErr.MclkSupply1v8LowErr = TRUE;
        LOIErr.LOISupply1v1LowErr = TRUE;

        ErrCode = BC_ISM_MaskRTMSetClrMCOIErr(e_ISM_ERR_OP_MONITOR_ERR, FALSE, FALSE, &MClkErr, &LOIErr, &CCEr);
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        GLDOErr.GlDOSupply1v1HighErr = TRUE;
        GLDOErr.GlDOSupply1v1LowErr = TRUE;

        SSBErr.SSBSupply1v8LowErr = TRUE;

        SerErr.Supply1v1LVDSLowErr = TRUE;
        SerErr.Supply1v1MIPILowErr = TRUE;
        SerErr.Supply1v8SerLowErr = TRUE;

        GBErr.GBIASSupply1v8LowErr = TRUE;

        ErrCode = BC_ISM_MaskRTMSetClrSSGAErr(e_ISM_ERR_OP_MONITOR_ERR, FALSE, &SerErr, &SSBErr, &GBErr, &GLDOErr);
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        ChirpErr.ChirpTempErr = TRUE;
        ChirpErr.ChirpPLLSupply1v8vLowErr = TRUE;
        ChirpErr.ChirpVCOSupply1v8vLowErr = TRUE;
        ChirpErr.ChirpDigSupply1v1LowErrorErr = TRUE;
        ChirpErr.InterfaceStuckatErr = TRUE;
        ErrCode = BC_ISM_MaskRTMSetClrChirpErr(e_ISM_ERR_OP_MONITOR_ERR, &ChirpErr);
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        RXErr.RxSupply1V1LowErr = TRUE;
        RXErr.RxSupply1V8LowErr = TRUE;
        ErrCode = BC_ISM_MaskRTMSetClrRxErr(e_ISM_ERR_OP_MONITOR_ERR, &RXErr, &RXErr, &RXErr, &RXErr);
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        TxErr.TxTempHighErr = TRUE;
        TxErr.TxPRErr = TRUE;
        TxErr.TxSupply1v8LowErr = TRUE;
        TxErr.TxSupply1v1LowErr = TRUE;
        ErrCode = BC_ISM_MaskRTMSetClrTxErr(e_ISM_ERR_OP_MONITOR_ERR, &TxErr, &TxErr, &TxErr);
    }
    return ErrCode;
}
#endif
/* Endif of file */
