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
#include "bc_cafc.h"
#include "bc_conf.h"
#include "bc_te.h"
#include "bc_lvds.h"
#include "bc_mipi.h"
#include "bc_mclk.h"
#include "bc_rx.h"
#include "bc_gldo.h"
#include "bc_otp.h"
#include "bc_loi.h"
#include "bc_ism.h"
#include "plf.h"
#include "bc_sysinit.h"
#include "bc_types.h"
#include "helper_bcsys.h"
#include "helper_sysinit.h"

static BC_ERRCODE Helper_RegCRCIssue(void);
static BC_ERRCODE Helper_SYSINIT_ConfigRX(SYS_IPList_t *pAppConfig);
static BC_ERRCODE Helper_RX_EnableRMSDet(SYS_IPList_t *pAppConfig);
static BC_ERRCODE Helper_ChckChrpLOINLOOUTValidIP(SYS_IPList_t *pAppConfig);
static BC_ERRCODE Helper_CheckTXValidIP(SYS_IPList_t *pAppConfig);
static BC_ERRCODE Helper_CheckRXValidIP(SYS_IPList_t *pAppConfig);
static BC_ERRCODE Helper_CheckMIPILVDSPRValidIP(SYS_IPList_t *pAppConfig);

static BC_ERRCODE Helper_RX_EnableRMSDet(SYS_IPList_t *pAppConfig)
{
    BOOL EnRMSDet = TRUE;
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    if (TRUE == pAppConfig->RX1)
    {
        ErrCode = BC_RX_EnableRMSDet(EnRMSDet, e_SYS_RX1);
    }
    if ((BC_ERR_NOERROR == ErrCode) && (TRUE == pAppConfig->RX2))
    {
        ErrCode = BC_RX_EnableRMSDet(EnRMSDet, e_SYS_RX2);
    }
    if ((BC_ERR_NOERROR == ErrCode) && (TRUE == pAppConfig->RX3))
    {
        ErrCode = BC_RX_EnableRMSDet(EnRMSDet, e_SYS_RX3);
    }
    if ((BC_ERR_NOERROR == ErrCode) && (TRUE == pAppConfig->RX4))
    {
        ErrCode = BC_RX_EnableRMSDet(EnRMSDet, e_SYS_RX4);
    }
    return ErrCode;
}
static BC_ERRCODE Helper_SYSINIT_ConfigRX(SYS_IPList_t *pAppConfig)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    BOOL EnRMSDet = TRUE;
    if ((pAppConfig->RX1 == TRUE) && (pAppConfig->RX2 == TRUE) && (pAppConfig->RX3 == TRUE) && (pAppConfig->RX4 == TRUE))
    {
        ErrCode = BC_RX_EnableRMSDet(EnRMSDet, e_SYS_RXMC);
    }
    else
    {
        ErrCode = Helper_RX_EnableRMSDet(pAppConfig);
    }
    return ErrCode;
}
BC_ERRCODE BC_SYS_Init_ReleaseHRESET(void)
{
    BC_ERRCODE ErrCode;

    ErrCode = PLF_HIO_SetIO(e_SYS_HRESET, FALSE); /*Set the HRESET_N pin to Low*/

    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = PLF_TM_Sleep(SYS_INIT_HRESET_TIME);
    }

    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = PLF_HIO_SetIO(e_SYS_HRESET, TRUE); /*Set the HRESET_N pin to high*/
    }

    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = PLF_HIO_SetIO(e_SYS_ERRORRESET, FALSE); /*Set the error_reset pin to low*/
    }

    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = PLF_TM_Sleep(SYS_INIT_HRESET_TIME);
    }

    return ErrCode;
}

static BC_ERRCODE Helper_RegCRCIssue(void)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    uint32_t KnownValue = 0x0u;
    uint16_t IReg;

    for (IReg = 0x01u; IReg < 0x08u; IReg++)
    {
        ErrCode = BC_SPI_Write(e_SYS_CC, (CC_SCRATCH_REGISTER1_U16 + (uint16_t)(4u * IReg)), KnownValue);
        if (BC_ERR_NOERROR != ErrCode)
        {
            break;
        }
    }
    return ErrCode;
}

BC_ERRCODE BC_SYS_Init_SPIAccessCheck(void)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    uint32_t ReadValue = 0xA5A5A5A5u;
    uint32_t KnownValue = 0xA5A5A5A5u;

    ErrCode = BC_SPI_Write(e_SYS_CC, CC_SCRATCH_REGISTER1_U16, KnownValue);
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SPI_Read(e_SYS_CC, CC_SCRATCH_REGISTER1_U16, &ReadValue);
        if (ErrCode == BC_ERR_NOERROR)
        {
            if (ReadValue == KnownValue)
            {
                // SPI check is okay mark it as OK in ISM
                ErrCode = BC_ISM_SetStartupStatus(e_ISM_SPI_ACCESS_CHECK_OK);
            }
            else
            {
                ErrCode = BC_ERR_SYS_SPIACCESS_CHECKFAIL;
            }
        }
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = Helper_RegCRCIssue();
    }
    return ErrCode;
}

static BC_ERRCODE Helper_CheckTXValidIP(SYS_IPList_t *pAppConfig)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    // if OTP checkvalidip reports that this IP is otp disabled but in appconfig it is set as on, report error
    if (((BC_OTP_CheckValidIP(e_OTP_VALID_TX1) != BC_ERR_NOERROR) && (pAppConfig->TX1 == (BOOL)TRUE)) ||
        ((BC_OTP_CheckValidIP(e_OTP_VALID_TX2) != BC_ERR_NOERROR) && (pAppConfig->TX2 == (BOOL)TRUE)) ||
        ((BC_OTP_CheckValidIP(e_OTP_VALID_TX3) != BC_ERR_NOERROR) && (pAppConfig->TX3 == (BOOL)TRUE)))
    {
        ErrCode = BC_ERR_SYS_WRONG_APPCONFIG;
    }
    return ErrCode;
}

static BC_ERRCODE Helper_CheckRXValidIP(SYS_IPList_t *pAppConfig)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    // if OTP checkvalidip reports that this IP is otp disabled but in appconfig it is set as on, report error
    if (((BC_OTP_CheckValidIP(e_OTP_VALID_RX1) != BC_ERR_NOERROR) && (pAppConfig->RX1 == (BOOL)TRUE)) ||
        ((BC_OTP_CheckValidIP(e_OTP_VALID_RX2) != BC_ERR_NOERROR) && (pAppConfig->RX2 == (BOOL)TRUE)) ||
        ((BC_OTP_CheckValidIP(e_OTP_VALID_RX3) != BC_ERR_NOERROR) && (pAppConfig->RX3 == (BOOL)TRUE)) ||
        ((BC_OTP_CheckValidIP(e_OTP_VALID_RX4) != BC_ERR_NOERROR) && (pAppConfig->RX4 == (BOOL)TRUE)))
    {
        ErrCode = BC_ERR_SYS_WRONG_APPCONFIG;
    }
    return ErrCode;
}

static BC_ERRCODE Helper_CheckMIPILVDSPRValidIP(SYS_IPList_t *pAppConfig)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    // if OTP checkvalidip reports that this IP is otp disabled but in appconfig it is set as on, report error
    if (((BC_OTP_CheckValidIP(e_OTP_VALID_LVDS) != BC_ERR_NOERROR) && (pAppConfig->LVDS == (BOOL)TRUE)) ||
        ((BC_OTP_CheckValidIP(e_OTP_VALID_CSI2) != BC_ERR_NOERROR) && (pAppConfig->MIPI == (BOOL)TRUE)) ||
        ((BC_OTP_CheckValidIP(e_OTP_VALID_PR) != BC_ERR_NOERROR) && (pAppConfig->PR == (BOOL)TRUE)))
    {
        ErrCode = BC_ERR_SYS_WRONG_APPCONFIG;
    }
    return ErrCode;
}

static BC_ERRCODE Helper_ChckChrpLOINLOOUTValidIP(SYS_IPList_t *pAppConfig)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    // if OTP checkvalidip reports that this IP is otp disabled but in appconfig it is set as on, report error
    if (((BC_OTP_CheckValidIP(e_OTP_VALID_CHIRP_5G_MODE) != BC_ERR_NOERROR) && (pAppConfig->CHIRP5GMODE == (BOOL)TRUE)) ||
        ((BC_OTP_CheckValidIP(e_OTP_VALID_LO_IN) != BC_ERR_NOERROR) && (pAppConfig->LOIN == (BOOL)TRUE)) ||
        ((BC_OTP_CheckValidIP(e_OTP_VALID_LO_OUT) != BC_ERR_NOERROR) && (pAppConfig->LOOUT == (BOOL)TRUE)))
    {
        ErrCode = BC_ERR_SYS_WRONG_APPCONFIG;
    }
    return ErrCode;
}

BC_ERRCODE BC_SYS_Init_ReadOTPCheckCRC(void)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    SYS_IPList_t AppConfig;

    // load OTP
    ErrCode = BC_OTP_LoadOTP();
    if (ErrCode == BC_ERR_NOERROR)
    {
        // Get APP configuration
        ErrCode = BC_CC_GetAppConfiguration(&AppConfig, NULL);
    }
    // Check if app configuration is possible with OTP bits
    if (ErrCode == BC_ERR_NOERROR)
    {
        // Check Valid Ip for Chirp, LO_IN and LO_OUT
        ErrCode = Helper_ChckChrpLOINLOOUTValidIP(&AppConfig);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        // Check Valid Ip for TX
        ErrCode = Helper_CheckTXValidIP(&AppConfig);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        // Check Valid Ip for TX
        ErrCode = Helper_CheckRXValidIP(&AppConfig);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        // Check Valid Ip for TX
        ErrCode = Helper_CheckMIPILVDSPRValidIP(&AppConfig);
    }

    return ErrCode;
}

BC_ERRCODE BC_SYS_Init_ConfigGLDO(void)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    CC_ModList_t ModList = {FALSE};
    ModList.SetGLDO = TRUE;
    // Set low noise reference for 1v1 and 1v8
    ErrCode = BC_GLDO_SelectGLDOVRef(TRUE);
    // PON enable GLDO
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_CC_SetPonClkRst(e_CC_PON, &ModList);
    }
    // release functional reset
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_CC_SetPonClkRst(e_CC_FUNCRST, &ModList);
    }
    // mark it as OK in ISm
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_ISM_SetStartupStatus(e_ISM_MAIN_LDO_CONFIG_OK);
    }

    return ErrCode;
}

BC_ERRCODE BC_SYS_Init_ConfigGBIAS(void)
{

    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    CC_ModList_t ModList = {FALSE};
    ModList.SetGLDO = TRUE;
    ModList.SetGBIAS = TRUE;
    // PON enable GBIAS
    ErrCode = BC_CC_SetPonClkRst(e_CC_PON, &ModList);

    // release functional reset
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_CC_SetPonClkRst(e_CC_FUNCRST, &ModList);
    }

    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = Helper_InitConfigPonLdoGBIAS();
    }
    // wait for stablization
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = PLF_TM_Sleep(GBIAS_WAIT_FOR_STABILIZATION_US);
    }
    // mark it as OK in ISm
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_ISM_SetStartupStatus(e_ISM_GOBAL_BIAS_CONFIG_OK);
    }

    return ErrCode;
}

BC_ERRCODE BC_SYS_Init_EnClkRelRstIPs(void)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    CC_ModList_t CCAppConfig;
    SYS_IPList_t SysAppConfig;
    /* Get the list of 'desired' IPs */
    ErrCode = BC_CC_GetAppConfiguration(&SysAppConfig, NULL);
    if (ErrCode == BC_ERR_NOERROR)
    {
        /* Copying from Sys structure to CC structure */
        // ADC clock should not be enabled before its LDO is enabled.
        // Master reset of ADC should not be deasserted before its LDO is enabled.
        CCAppConfig.SetADC12 = FALSE;
        CCAppConfig.SetADC34 = FALSE;
        CCAppConfig.SetATB = SysAppConfig.ATB;
        /* As IPs: TE is always on, SC and CAFC needs to power on !*/
        CCAppConfig.SetChirp = SysAppConfig.TE;
        CCAppConfig.SetGBIAS = SysAppConfig.GBIAS;
        CCAppConfig.SetGLDO = SysAppConfig.GLDO;
        CCAppConfig.SetISM = SysAppConfig.ISM;
        CCAppConfig.SetLOInterface = SysAppConfig.LOI;
        CCAppConfig.SetMCLK = SysAppConfig.MCLK;
        CCAppConfig.SetOTP = SysAppConfig.OTP;
        CCAppConfig.SetRX1 = SysAppConfig.RX1;
        CCAppConfig.SetRX2 = SysAppConfig.RX2;
        CCAppConfig.SetRX3 = SysAppConfig.RX3;
        CCAppConfig.SetRX4 = SysAppConfig.RX4;
        // Serialiser clock should not be enabled before its LDO is enabled.
        // Master reset of Serialiser should not be deasserted before its LDO is enabled.
        CCAppConfig.SetSerialiser = FALSE;
        // SSB clock should not be enabled before its LDO is enabled.
        // Master reset of SSB should not be deasserted before its LDO is enabled.
        CCAppConfig.SetSSBMOD = FALSE;
        CCAppConfig.SetTX1 = SysAppConfig.TX1;
        CCAppConfig.SetTX2 = SysAppConfig.TX2;
        CCAppConfig.SetTX3 = SysAppConfig.TX3;

        /* Enable the clocks of IPs*/
        ErrCode = BC_CC_SetPonClkRst(e_CC_CLKEN, &CCAppConfig);
        if (ErrCode == BC_ERR_NOERROR)
        {
            /* Release the rest of IPs*/
            ErrCode = BC_CC_SetPonClkRst(e_CC_RST, &CCAppConfig);
        }
    }
    return ErrCode;
}

BC_ERRCODE BC_SYS_Init_DistributeOTPData(void)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    ErrCode = Helper_InitDistributeOTPData();
    return ErrCode;
}

BC_ERRCODE BC_SYS_Init_EnLocalLDO(void)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    SYS_IPList_t AppConfig;
    /* Get the list of IPs set by application */
    ErrCode = BC_CC_GetAppConfiguration(&AppConfig, NULL);
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = Helper_EnLocLDORelRSTADCSer(&AppConfig);
    }
    // distribute OTP data to LVDS moduel
    if (ErrCode == BC_ERR_NOERROR)
    {
        if (AppConfig.LVDS == TRUE)
        {
            // distribute LVDS common mode trimming, only if the data interface is LVDS
            ErrCode = BC_OTP_DistributeOTPData(e_OTP_TRIM_LOCAL_LDO, 0u, 1u);
        }
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        // Local LDO config is done; mark it as OK in ISM
        ErrCode = BC_ISM_SetStartupStatus(e_ISM_LOCAL_LDO_CONFIG_OK);
    }
    return ErrCode;
}

BC_ERRCODE BC_SYS_Init_ConfigMCLK(void)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    CC_ModList_t ModList = {FALSE};
    ModList.SetGLDO = TRUE;
    ModList.SetGBIAS = TRUE;
    ModList.SetMCLK = TRUE;
    // for master clock integrity check we need to pon the MIPI or LVDS
    ModList.SetSerialiser = TRUE;

    // power on the MCLK
    ErrCode = BC_CC_SetPonClkRst(e_CC_PON, &ModList);

    // release functional reset
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_CC_SetPonClkRst(e_CC_FUNCRST, &ModList);
    }

    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = Helper_InitConfigMCLK();
    }
    // if PON calibration, perform one more recalibration
    if (ErrCode == BC_ERR_NOERROR)
    {
        // ReCalibration
        // no need to do initial calibration hence FALSE
        ErrCode = BC_MCLK_AutoCalib(FALSE);
    }
    // set calibrated clock for CC
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = Helper_ConfigSetCCClk();
    }
    // enable the src buffers
    if (ErrCode == BC_ERR_NOERROR)
    {
        BOOL EnChirp480M = TRUE;
        BOOL EnSer480600M = TRUE;
        BOOL EnADC1200M = TRUE;
        BOOL EnSSB600M = TRUE;
        BOOL EnADC40M = TRUE;
        ErrCode = BC_MCLK_SetClkBuffers(EnChirp480M, EnSer480600M, EnADC1200M, EnSSB600M, EnADC40M);
    }

    // now check the integrity of the MCLK
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_SYS_MCLKIntegrityCheck();
    }

    if (ErrCode == BC_ERR_NOERROR)
    {
        // PLL calibration and MClk integrity is okay mark it as OK in ISM
        ErrCode = BC_ISM_SetStartupStatus(e_ISM_MCLK_CONFIG_OK);
    }

    return ErrCode;
}

BC_ERRCODE BC_SYS_Init_ConfigCAFC(void)
{
    BC_ERRCODE ErrCode;

    ErrCode = Helper_InitConfigCAFC();
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_ISM_SetStartupStatus(e_ISM_CAFC_CONFIG_OK);
    }
    return ErrCode;
}

BC_ERRCODE BC_SYS_Init_PowerOnModules(void)
{
    BC_ERRCODE ErrCode;
    ErrCode = Helper_InitPowerOnModules();
    return ErrCode;
}

BC_ERRCODE BC_SYS_Init_ConfigADC(void)
{
    BC_ERRCODE ErrCode;
    ErrCode = Helper_InitConfigADC();
    return ErrCode;
}

BC_ERRCODE BC_SYS_Init_ConfigSafetySensors(void)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    SYS_IPList_t SysAppConfig = {FALSE};

    ErrCode = BC_CC_GetAppConfiguration(&SysAppConfig, NULL);
    if ((ErrCode == BC_ERR_NOERROR) && (TRUE == SysAppConfig.CAFC))
    {
        ErrCode = Helper_InitConfigCAFCFuSa();
    }
    // Not updating Rx RMS_CONTROL register since RMS_CONTROL reset value already setting RMS detector as output
    // Enable LOI RMS detector
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_LOI_EnableRFLevelRMSDet(TRUE);
    }
    // Enable RMS detector for all Rx
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = Helper_SYSINIT_ConfigRX(&SysAppConfig);
    }
    // Not updating Tx FUNCSAFE_MON_LEVEL_SETTINGS_ENABLE register since FUNCSAFE_MON_LEVEL_SETTINGS_ENABLE-> level_rf_enable_spi reset value is 1
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = Helper_ConfigISM();
    }
    // Mark the successful sensor configuration in the ISM start-up status register
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_ISM_ResetISMErr(FALSE, TRUE, TRUE, TRUE);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_ISM_SetStartupStatus(e_ISM_SAFETY_SENSOR_CONFIG_OK);
    }
    return ErrCode;
}

BC_ERRCODE BC_SYS_Init_InitDataInterface(void)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    SYS_IPList_t AppConfig;
    ErrCode = BC_CC_GetAppConfiguration(&AppConfig, NULL);
    if (ErrCode == BC_ERR_NOERROR)
    {

        if ((AppConfig.LVDS == TRUE) && (AppConfig.MIPI == FALSE))
        {

            ErrCode = BC_LVDS_Init();
        }
        else if ((AppConfig.LVDS == FALSE) && (AppConfig.MIPI == TRUE))
        {
            ErrCode = BC_MIPI_Init();
        }
        else
        {
            ErrCode = BC_ERR_SYS_WRONG_DATAINTERFACE_CONFIG;
        }
    }

    return ErrCode;
}

BC_ERRCODE BC_SYS_Init_SNSIntegrityCheck(void)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    ErrCode = Helper_InitGLDOSelfTest();

    return ErrCode;
}
/* Endif of file */
