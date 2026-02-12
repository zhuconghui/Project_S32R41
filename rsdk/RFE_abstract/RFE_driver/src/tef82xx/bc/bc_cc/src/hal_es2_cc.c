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
#include "hal_es2_cc.h"
#ifdef BUILD_FOR_VAL
#include "v_es2_cc.h"
#else
#include "reg_es2_cc.h"
#endif
#include "bc_spi.h"
#include <math.h>
#include "bc_conf.h"
#include "hal_es2_otp.h"

#define LOCAL_LDO_VOLTAGE_MASK 0x1Fu

uint8_t gTargetDevice = 0u;
/// Global application configuration, see HAL_ES2_CC_SetAppConfiguration
static SYS_IPList_t gAppConfiguration[SYS_NUM_MAX_DEVICE] = {{(BOOL)0u, (BOOL)0u, (BOOL)0u, (BOOL)0u,
                                                              (BOOL)0u, (BOOL)0u, (BOOL)0u, (BOOL)0u,
                                                              (BOOL)0u, (BOOL)0u, (BOOL)0u, (BOOL)0u,
                                                              (BOOL)0u, (BOOL)0u, (BOOL)0u, (BOOL)0u,
                                                              (BOOL)0u, (BOOL)0u, (BOOL)0u, (BOOL)0u,
                                                              (BOOL)0u, (BOOL)0u, (BOOL)0u, (BOOL)0u, (BOOL)0u, (BOOL)0u},
                                                             {(BOOL)0u, (BOOL)0u, (BOOL)0u, (BOOL)0u,
                                                              (BOOL)0u, (BOOL)0u, (BOOL)0u, (BOOL)0u,
                                                              (BOOL)0u, (BOOL)0u, (BOOL)0u, (BOOL)0u,
                                                              (BOOL)0u, (BOOL)0u, (BOOL)0u, (BOOL)0u,
                                                              (BOOL)0u, (BOOL)0u, (BOOL)0u, (BOOL)0u,
                                                              (BOOL)0u, (BOOL)0u, (BOOL)0u, (BOOL)0u, (BOOL)0u, (BOOL)0u},
                                                             {(BOOL)0u, (BOOL)0u, (BOOL)0u, (BOOL)0u,
                                                              (BOOL)0u, (BOOL)0u, (BOOL)0u, (BOOL)0u,
                                                              (BOOL)0u, (BOOL)0u, (BOOL)0u, (BOOL)0u,
                                                              (BOOL)0u, (BOOL)0u, (BOOL)0u, (BOOL)0u,
                                                              (BOOL)0u, (BOOL)0u, (BOOL)0u, (BOOL)0u,
                                                              (BOOL)0u, (BOOL)0u, (BOOL)0u, (BOOL)0u, (BOOL)0u, (BOOL)0u},
                                                             {(BOOL)0u, (BOOL)0u, (BOOL)0u, (BOOL)0u,
                                                              (BOOL)0u, (BOOL)0u, (BOOL)0u, (BOOL)0u,
                                                              (BOOL)0u, (BOOL)0u, (BOOL)0u, (BOOL)0u,
                                                              (BOOL)0u, (BOOL)0u, (BOOL)0u, (BOOL)0u,
                                                              (BOOL)0u, (BOOL)0u, (BOOL)0u, (BOOL)0u,
                                                              (BOOL)0u, (BOOL)0u, (BOOL)0u, (BOOL)0u, (BOOL)0u, (BOOL)0u}};

static BC_ERRCODE Helper_SetDynPowModeDown(CC_DynPowDnIPList_t *pPowDnIPList);
static BC_ERRCODE Helper_ES2_EnDisInt(uint8_t Enable, CC_IntEvent_t *pIntEvents);
static BC_ERRCODE Helper_ES2_ClearInt(CC_IntEvent_t *pIntEvents);
static BC_ERRCODE Helper_ES2_DynPowDwnRangeCheck(CC_DynPowDnIPList_t *pPowDnIPList, float32_t PowDownDelayPerChirp, float32_t PowDownDelayPerSequence);
static BC_ERRCODE Helper_ES2_PowDwIPRangeCheck(CC_DynPowDnIPList_t *pPowDnIPList);
static BC_ERRCODE Helper_ES2_PowDwTxRxIPRangeChck(CC_DynPowDnIPList_t *pPowDnIPList);
static BC_ERRCODE Helper_ES2_ChirpStartCnfgPad(SYS_ExtPinID_e PadName, BOOL SetOutPort, uint8_t BitEhs0, uint8_t BitEhs1);
static BC_ERRCODE Helper_ES2_ErrorCnfgPad(SYS_ExtPinID_e PadName, BOOL SetOutPort, uint8_t BitEhs0, uint8_t BitEhs1);
static BC_ERRCODE Helper_ES2_TXIPSCnfgPad(SYS_ExtPinID_e PadName, BOOL SetOutPort, uint8_t BitEhs0, uint8_t BitEhs1);
static BC_ERRCODE Helper_ES2_TXQPSCnfgPad(SYS_ExtPinID_e PadName, BOOL SetOutPort, uint8_t BitEhs0, uint8_t BitEhs1);
static uint8_t Helper_ES2_GetModeSel(CC_DynPowMode_e DyPowSetting);
static uint8_t Helper_ES2_GetPowerControl(CC_DynPowMode_e DyPowSetting);

BC_ERRCODE HAL_ES2_CC_SetAppConfiguration(SYS_IPList_t *pAppConfig)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    if (NULL != pAppConfig)
    {
        // copy input to gloabl configuration
        gAppConfiguration[gTargetDevice].CC = pAppConfig->CC;
        gAppConfiguration[gTargetDevice].LVDS = pAppConfig->LVDS;
        gAppConfiguration[gTargetDevice].MIPI = pAppConfig->MIPI;
        gAppConfiguration[gTargetDevice].TE = pAppConfig->TE;
        gAppConfiguration[gTargetDevice].SC = pAppConfig->SC;
        gAppConfiguration[gTargetDevice].CAFC = pAppConfig->CAFC;
        gAppConfiguration[gTargetDevice].ADC12 = pAppConfig->ADC12;
        gAppConfiguration[gTargetDevice].ADC34 = pAppConfig->ADC34;
        gAppConfiguration[gTargetDevice].GBIAS = pAppConfig->GBIAS;
        gAppConfiguration[gTargetDevice].LOI = pAppConfig->LOI;
        gAppConfiguration[gTargetDevice].MCLK = pAppConfig->MCLK;
        gAppConfiguration[gTargetDevice].RX1 = pAppConfig->RX1;
        gAppConfiguration[gTargetDevice].RX2 = pAppConfig->RX2;
        gAppConfiguration[gTargetDevice].RX3 = pAppConfig->RX3;
        gAppConfiguration[gTargetDevice].RX4 = pAppConfig->RX4;
        gAppConfiguration[gTargetDevice].TX1 = pAppConfig->TX1;
        gAppConfiguration[gTargetDevice].TX2 = pAppConfig->TX2;
        gAppConfiguration[gTargetDevice].TX3 = pAppConfig->TX3;
        gAppConfiguration[gTargetDevice].GLDO = pAppConfig->GLDO;
        gAppConfiguration[gTargetDevice].ATB = pAppConfig->ATB;
        gAppConfiguration[gTargetDevice].OTP = pAppConfig->OTP;
        gAppConfiguration[gTargetDevice].ISM = pAppConfig->ISM;
        gAppConfiguration[gTargetDevice].CHIRP5GMODE = pAppConfig->CHIRP5GMODE;
        gAppConfiguration[gTargetDevice].PR = pAppConfig->PR;
        gAppConfiguration[gTargetDevice].LOIN = pAppConfig->LOIN;
        gAppConfiguration[gTargetDevice].LOOUT = pAppConfig->LOOUT;
    }
    else
    {
        ErrCode = BC_ERR_INPUTOUTOFRANGE;
    }

    return ErrCode;
}

BC_ERRCODE HAL_ES2_CC_SetAppConfigMS(SYS_IPList_t *pAppConfig, PLF_SPITarget_e TargetDevice)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    switch (TargetDevice)
    {
    case e_PLF_MASTER:
        gTargetDevice = 0u;
        break;
    case e_PLF_SLAVE1:
        gTargetDevice = 1u;
        break;
    case e_PLF_SLAVE2:
        gTargetDevice = 2u;
        break;
    case e_PLF_SLAVE3:
        gTargetDevice = 3u;
        break;
    default:
        ErrCode = BC_ERR_INPUTOUTOFRANGE;
        break;
    }

    if ((NULL != pAppConfig) && (BC_ERR_NOERROR == ErrCode))
    {
        // copy input to gloabl configuration
        gAppConfiguration[gTargetDevice].CC = pAppConfig->CC;
        gAppConfiguration[gTargetDevice].LVDS = pAppConfig->LVDS;
        gAppConfiguration[gTargetDevice].MIPI = pAppConfig->MIPI;
        gAppConfiguration[gTargetDevice].TE = pAppConfig->TE;
        gAppConfiguration[gTargetDevice].SC = pAppConfig->SC;
        gAppConfiguration[gTargetDevice].CAFC = pAppConfig->CAFC;
        gAppConfiguration[gTargetDevice].ADC12 = pAppConfig->ADC12;
        gAppConfiguration[gTargetDevice].ADC34 = pAppConfig->ADC34;
        gAppConfiguration[gTargetDevice].GBIAS = pAppConfig->GBIAS;
        gAppConfiguration[gTargetDevice].LOI = pAppConfig->LOI;
        gAppConfiguration[gTargetDevice].MCLK = pAppConfig->MCLK;
        gAppConfiguration[gTargetDevice].RX1 = pAppConfig->RX1;
        gAppConfiguration[gTargetDevice].RX2 = pAppConfig->RX2;
        gAppConfiguration[gTargetDevice].RX3 = pAppConfig->RX3;
        gAppConfiguration[gTargetDevice].RX4 = pAppConfig->RX4;
        gAppConfiguration[gTargetDevice].TX1 = pAppConfig->TX1;
        gAppConfiguration[gTargetDevice].TX2 = pAppConfig->TX2;
        gAppConfiguration[gTargetDevice].TX3 = pAppConfig->TX3;
        gAppConfiguration[gTargetDevice].GLDO = pAppConfig->GLDO;
        gAppConfiguration[gTargetDevice].ATB = pAppConfig->ATB;
        gAppConfiguration[gTargetDevice].OTP = pAppConfig->OTP;
        gAppConfiguration[gTargetDevice].ISM = pAppConfig->ISM;
        gAppConfiguration[gTargetDevice].CHIRP5GMODE = pAppConfig->CHIRP5GMODE;
        gAppConfiguration[gTargetDevice].PR = pAppConfig->PR;
        gAppConfiguration[gTargetDevice].LOIN = pAppConfig->LOIN;
        gAppConfiguration[gTargetDevice].LOOUT = pAppConfig->LOOUT;
    }
    else
    {
        ErrCode = BC_ERR_INPUTOUTOFRANGE;
    }

    return ErrCode;
}

BC_ERRCODE HAL_ES2_CC_SetMSDevice(PLF_SPITarget_e TargetDevice)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    switch (TargetDevice)
    {
    case e_PLF_MASTER:
        gTargetDevice = 0u;
        break;
    case e_PLF_SLAVE1:
        gTargetDevice = 1u;
        break;
    case e_PLF_SLAVE2:
        gTargetDevice = 2u;
        break;
    case e_PLF_SLAVE3:
        gTargetDevice = 3u;
        break;
    default:
        ErrCode = BC_ERR_INPUTOUTOFRANGE;
        break;
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_CC_GetAppConfiguration(SYS_IPList_t *pAppConfig, uint32_t *pPONMask)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    // note: this register should be the same across ES variants, but still using MACRO to be safe
#ifdef TEF82XX_CFG_ES2
    R2M00_IpLevelPonEnableUnion_t IpLevelPonEnable;
    // ensure not used bits are zeros
    IpLevelPonEnable.val_u32 = 0x0u;

    IpLevelPonEnable.bits_st.PonAdc12En = (uint8_t)(gAppConfiguration[gTargetDevice].ADC12);
    IpLevelPonEnable.bits_st.PonAdc34En = (uint8_t)(gAppConfiguration[gTargetDevice].ADC34);
    IpLevelPonEnable.bits_st.PonAtbEn = (uint8_t)(gAppConfiguration[gTargetDevice].ATB);
    IpLevelPonEnable.bits_st.PonChirpEn = (uint8_t)(gAppConfiguration[gTargetDevice].CAFC);
    IpLevelPonEnable.bits_st.PonGlobalBiasEn = (uint8_t)(gAppConfiguration[gTargetDevice].GBIAS);
    IpLevelPonEnable.bits_st.PonGlobalLdoEn = (uint8_t)(gAppConfiguration[gTargetDevice].GLDO);
    IpLevelPonEnable.bits_st.PonLoInterfaceEn = (uint8_t)(gAppConfiguration[gTargetDevice].LOI);
    IpLevelPonEnable.bits_st.PonMasterClkEn = (uint8_t)(gAppConfiguration[gTargetDevice].MCLK);
    IpLevelPonEnable.bits_st.PonOtpEn = (uint8_t)(gAppConfiguration[gTargetDevice].OTP);
    IpLevelPonEnable.bits_st.PonRx1En = (uint8_t)(gAppConfiguration[gTargetDevice].RX1);
    IpLevelPonEnable.bits_st.PonRx2En = (uint8_t)(gAppConfiguration[gTargetDevice].RX2);
    IpLevelPonEnable.bits_st.PonRx3En = (uint8_t)(gAppConfiguration[gTargetDevice].RX3);
    IpLevelPonEnable.bits_st.PonRx4En = (uint8_t)(gAppConfiguration[gTargetDevice].RX4);
    // This is because of MISRA 10.5 Since MISRA does not allow type casting Boolean to any other data types
    if ((gAppConfiguration[gTargetDevice].LVDS == TRUE) || (gAppConfiguration[gTargetDevice].MIPI == TRUE))
    {
        IpLevelPonEnable.bits_st.PonSerEn = (uint8_t)0x1u;
    }
    IpLevelPonEnable.bits_st.PonTx1En = (uint8_t)(gAppConfiguration[gTargetDevice].TX1);
    IpLevelPonEnable.bits_st.PonTx2En = (uint8_t)(gAppConfiguration[gTargetDevice].TX2);
    IpLevelPonEnable.bits_st.PonTx3En = (uint8_t)(gAppConfiguration[gTargetDevice].TX3);
#endif

    // treat all 0 as appConf not set, since no one will use the chip without all IPs.
    if (IpLevelPonEnable.val_u32 != 0x0u)
    {
        if ((NULL == pAppConfig) && (NULL == pPONMask))
        {
            // both are NULL
            ErrCode = BC_ERR_INPUTOUTOFRANGE;
        }
        else
        {
            // allowing at most one NULL
            if (NULL != pAppConfig)
            {
                pAppConfig->CC = gAppConfiguration[gTargetDevice].CC;
                pAppConfig->LVDS = gAppConfiguration[gTargetDevice].LVDS;
                pAppConfig->MIPI = gAppConfiguration[gTargetDevice].MIPI;
                pAppConfig->TE = gAppConfiguration[gTargetDevice].TE;
                pAppConfig->SC = gAppConfiguration[gTargetDevice].SC;
                pAppConfig->CAFC = gAppConfiguration[gTargetDevice].CAFC;
                pAppConfig->ADC12 = gAppConfiguration[gTargetDevice].ADC12;
                pAppConfig->ADC34 = gAppConfiguration[gTargetDevice].ADC34;
                pAppConfig->GBIAS = gAppConfiguration[gTargetDevice].GBIAS;
                pAppConfig->LOI = gAppConfiguration[gTargetDevice].LOI;
                pAppConfig->MCLK = gAppConfiguration[gTargetDevice].MCLK;
                pAppConfig->RX1 = gAppConfiguration[gTargetDevice].RX1;
                pAppConfig->RX2 = gAppConfiguration[gTargetDevice].RX2;
                pAppConfig->RX3 = gAppConfiguration[gTargetDevice].RX3;
                pAppConfig->RX4 = gAppConfiguration[gTargetDevice].RX4;
                pAppConfig->TX1 = gAppConfiguration[gTargetDevice].TX1;
                pAppConfig->TX2 = gAppConfiguration[gTargetDevice].TX2;
                pAppConfig->TX3 = gAppConfiguration[gTargetDevice].TX3;
                pAppConfig->GLDO = gAppConfiguration[gTargetDevice].GLDO;
                pAppConfig->ATB = gAppConfiguration[gTargetDevice].ATB;
                pAppConfig->OTP = gAppConfiguration[gTargetDevice].OTP;
                pAppConfig->ISM = gAppConfiguration[gTargetDevice].ISM;
                pAppConfig->CHIRP5GMODE = gAppConfiguration[gTargetDevice].CHIRP5GMODE;
                pAppConfig->PR = gAppConfiguration[gTargetDevice].PR;
                pAppConfig->LOIN = gAppConfiguration[gTargetDevice].LOIN;
                pAppConfig->LOOUT = gAppConfiguration[gTargetDevice].LOOUT;
            }

            if (NULL != pPONMask)
            {
                // assign output PONMask
                *pPONMask = IpLevelPonEnable.val_u32;
            }
        }
    }
    else
    {
        ErrCode = BC_ERR_CC_SYSCONFNOTSET;
    }

    return ErrCode;
}

BC_ERRCODE HAL_ES2_CC_SetInterface(CC_InterfaceType_e SerialiserMode)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    CC_InterfaceType_e GetSerialiserMode = e_CC_INTERFACE_INVALID;
    R2M00_SerialiserModeSelUnion_t SerialiserModeSet;

    /* Get the status of package variant */
    ErrCode = HAL_ES2_CC_GetInterface(&GetSerialiserMode);

    /* match the selected interface with the package interface */
    if ((SerialiserMode == GetSerialiserMode) && (ErrCode == BC_ERR_NOERROR))
    {
        /* since first 30 bits of this register is reserved register read is not required before updating*/
        SerialiserModeSet.val_u32 = 0x0u;

        SerialiserModeSet.bits_st.SwCtrlSerModeSel = (uint8_t)SerialiserMode;

        ErrCode = BC_SPI_WriteCheck(e_SYS_CC, R2M00_SERIALISER_MODE_SEL_U16, SerialiserModeSet.val_u32);
    }
    else
    {
        ErrCode = BC_ERR_WRONGINTERFACE;
    }

    return ErrCode;
}

BC_ERRCODE HAL_ES2_CC_GetInterface(CC_InterfaceType_e *pSerialiserMode)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    SYS_IPList_t SysAppConfig;

    if (pSerialiserMode != NULL)
    {
        if ((HAL_ES2_OTP_CheckValidIP(e_OTP_VALID_LVDS) == BC_ERR_NOERROR) && (HAL_ES2_OTP_CheckValidIP(e_OTP_VALID_CSI2) != BC_ERR_NOERROR))
        {
            *pSerialiserMode = e_CC_LVDS;
        }
        if ((HAL_ES2_OTP_CheckValidIP(e_OTP_VALID_LVDS) != BC_ERR_NOERROR) && (HAL_ES2_OTP_CheckValidIP(e_OTP_VALID_CSI2) == BC_ERR_NOERROR))
        {
            *pSerialiserMode = e_CC_MIPI;
        }
        // if both are valid (when OTP is not available)
        if ((HAL_ES2_OTP_CheckValidIP(e_OTP_VALID_LVDS) == BC_ERR_NOERROR) && (HAL_ES2_OTP_CheckValidIP(e_OTP_VALID_CSI2) == BC_ERR_NOERROR))
        {
            ErrCode = HAL_ES2_CC_GetAppConfiguration(&SysAppConfig, NULL);
            if (ErrCode == BC_ERR_NOERROR)
            {
                if (SysAppConfig.LVDS == TRUE)
                {
                    *pSerialiserMode = e_CC_LVDS;
                }
                else
                {
                    *pSerialiserMode = e_CC_MIPI;
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

BC_ERRCODE HAL_ES2_CC_SetPonClkRst(CC_PonClkRst_e Reg, CC_ModList_t *pModList)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    uint16_t RegAddr;
    uint32_t LocalRegister = 0;
    if (pModList != NULL)
    {
        switch (Reg)
        {
        case e_CC_PON:
        {
            R2M00_IpLevelPonEnableUnion_t LocalIPEnable;
            RegAddr = R2M00_IP_LEVEL_PON_ENABLE_U16;
            ErrCode = BC_SPI_Read(e_SYS_CC, RegAddr, &LocalIPEnable.val_u32);
            if (ErrCode == BC_ERR_NOERROR)
            {
                LocalIPEnable.bits_st.PonAdc12En = (uint8_t)pModList->SetADC12;
                LocalIPEnable.bits_st.PonAdc34En = (uint8_t)pModList->SetADC34;
                LocalIPEnable.bits_st.PonAtbEn = (uint8_t)pModList->SetATB;
                LocalIPEnable.bits_st.PonChirpEn = (uint8_t)pModList->SetChirp;
                LocalIPEnable.bits_st.PonGlobalBiasEn = (uint8_t)pModList->SetGBIAS;
                LocalIPEnable.bits_st.PonGlobalLdoEn = (uint8_t)pModList->SetGLDO;
                LocalIPEnable.bits_st.PonLoInterfaceEn = (uint8_t)pModList->SetLOInterface;
                /*ISM power can not be controlled*/
                LocalIPEnable.bits_st.PonMasterClkEn = (uint8_t)pModList->SetMCLK;
                LocalIPEnable.bits_st.PonOtpEn = (uint8_t)pModList->SetOTP;
                LocalIPEnable.bits_st.PonRx1En = (uint8_t)pModList->SetRX1;
                LocalIPEnable.bits_st.PonRx2En = (uint8_t)pModList->SetRX2;
                LocalIPEnable.bits_st.PonRx3En = (uint8_t)pModList->SetRX3;
                LocalIPEnable.bits_st.PonRx4En = (uint8_t)pModList->SetRX4;
                LocalIPEnable.bits_st.PonSerEn = (uint8_t)pModList->SetSerialiser;
                LocalIPEnable.bits_st.PonSsbmodEn = (uint8_t)pModList->SetSSBMOD;
                LocalIPEnable.bits_st.PonTx1En = (uint8_t)pModList->SetTX1;
                LocalIPEnable.bits_st.PonTx2En = (uint8_t)pModList->SetTX2;
                LocalIPEnable.bits_st.PonTx3En = (uint8_t)pModList->SetTX3;
                LocalRegister = LocalIPEnable.val_u32;
            }
            break;
        }
        case e_CC_CLKEN:
        {
            R2M00_IpLevelClockEnableUnion_t LocalIPEnable;
            RegAddr = R2M00_IP_LEVEL_CLOCK_ENABLE_U16;
            ErrCode = BC_SPI_Read(e_SYS_CC, RegAddr, &LocalIPEnable.val_u32);
            if (ErrCode == BC_ERR_NOERROR)
            {
                LocalIPEnable.bits_st.Clk40Adc12 = (uint8_t)pModList->SetADC12;
                LocalIPEnable.bits_st.Clk40Adc34 = (uint8_t)pModList->SetADC34;
                LocalIPEnable.bits_st.Clk40Atb = (uint8_t)pModList->SetATB;
                LocalIPEnable.bits_st.Clk40Chirp = (uint8_t)pModList->SetChirp;
                LocalIPEnable.bits_st.Clk40GlobalBias = (uint8_t)pModList->SetGBIAS;
                LocalIPEnable.bits_st.Clk40GlobalLdo = (uint8_t)pModList->SetGLDO;
                LocalIPEnable.bits_st.Clk40Ism = (uint8_t)pModList->SetISM;
                LocalIPEnable.bits_st.Clk40LoInterface = (uint8_t)pModList->SetLOInterface;
                LocalIPEnable.bits_st.Clk40MasterClk = (uint8_t)pModList->SetMCLK;
                LocalIPEnable.bits_st.Clk40Otp = (uint8_t)pModList->SetOTP;
                LocalIPEnable.bits_st.Clk40Rx1 = (uint8_t)pModList->SetRX1;
                LocalIPEnable.bits_st.Clk40Rx2 = (uint8_t)pModList->SetRX2;
                LocalIPEnable.bits_st.Clk40Rx3 = (uint8_t)pModList->SetRX3;
                LocalIPEnable.bits_st.Clk40Rx4 = (uint8_t)pModList->SetRX4;
                LocalIPEnable.bits_st.Clk40Ser = (uint8_t)pModList->SetSerialiser;
                LocalIPEnable.bits_st.Clk40Ssbmod = (uint8_t)pModList->SetSSBMOD;
                LocalIPEnable.bits_st.Clk40Tx1 = (uint8_t)pModList->SetTX1;
                LocalIPEnable.bits_st.Clk40Tx2 = (uint8_t)pModList->SetTX2;
                LocalIPEnable.bits_st.Clk40Tx3 = (uint8_t)pModList->SetTX3;
                LocalRegister = LocalIPEnable.val_u32;
            }
            break;
        }
        case e_CC_RST:
        {
            R2M00_IpResetControlUnion_t LocalIPEnable;
            RegAddr = R2M00_IP_RESET_CONTROL_U16;
            ErrCode = BC_SPI_Read(e_SYS_CC, RegAddr, &LocalIPEnable.val_u32);
            if (ErrCode == BC_ERR_NOERROR)
            {
                LocalIPEnable.bits_st.ResetAdc12 = (uint8_t)pModList->SetADC12;
                LocalIPEnable.bits_st.ResetAdc34 = (uint8_t)pModList->SetADC34;
                LocalIPEnable.bits_st.ResetAtb = (uint8_t)pModList->SetATB;
                LocalIPEnable.bits_st.ResetChirp = (uint8_t)pModList->SetChirp;
                LocalIPEnable.bits_st.ResetGlobalBias = (uint8_t)pModList->SetGBIAS;
                LocalIPEnable.bits_st.ResetGlobalLdo = (uint8_t)pModList->SetGLDO;
                LocalIPEnable.bits_st.ResetIsm = (uint8_t)pModList->SetISM;
                LocalIPEnable.bits_st.ResetLoInterface = (uint8_t)pModList->SetLOInterface;
                LocalIPEnable.bits_st.ResetMasterClk = (uint8_t)pModList->SetMCLK;
                /* otp can not be reset*/
                LocalIPEnable.bits_st.ResetRx1 = (uint8_t)pModList->SetRX1;
                LocalIPEnable.bits_st.ResetRx2 = (uint8_t)pModList->SetRX2;
                LocalIPEnable.bits_st.ResetRx3 = (uint8_t)pModList->SetRX3;
                LocalIPEnable.bits_st.ResetRx4 = (uint8_t)pModList->SetRX4;
                LocalIPEnable.bits_st.ResetSer = (uint8_t)pModList->SetSerialiser;
                LocalIPEnable.bits_st.ResetSsbmod = (uint8_t)pModList->SetSSBMOD;
                LocalIPEnable.bits_st.ResetTx1 = (uint8_t)pModList->SetTX1;
                LocalIPEnable.bits_st.ResetTx2 = (uint8_t)pModList->SetTX2;
                LocalIPEnable.bits_st.ResetTx3 = (uint8_t)pModList->SetTX3;
                LocalRegister = LocalIPEnable.val_u32;
            }
            break;
        }
        case e_CC_FUNCRST:
        {
            R2M00_IpFunctionalResetControlUnion_t LocalIPEnable;
            RegAddr = R2M00_IP_FUNCTIONAL_RESET_CONTROL_U16;
            ErrCode = BC_SPI_Read(e_SYS_CC, RegAddr, &LocalIPEnable.val_u32);
            if (ErrCode == BC_ERR_NOERROR)
            {
                LocalIPEnable.bits_st.FnResetAdc12 = (uint8_t)pModList->SetADC12;
                LocalIPEnable.bits_st.FnResetAdc34 = (uint8_t)pModList->SetADC34;
                LocalIPEnable.bits_st.FnResetAtb = (uint8_t)pModList->SetATB;
                LocalIPEnable.bits_st.FnResetChirp = (uint8_t)pModList->SetChirp;
                LocalIPEnable.bits_st.FnResetGlobalBias = (uint8_t)pModList->SetGBIAS;
                LocalIPEnable.bits_st.FnResetGlobalLdo = (uint8_t)pModList->SetGLDO;
                LocalIPEnable.bits_st.FnResetLoInterface = (uint8_t)pModList->SetLOInterface;
                LocalIPEnable.bits_st.FnResetMasterClk = (uint8_t)pModList->SetMCLK;
                /* otp can not be reset*/
                LocalIPEnable.bits_st.FnResetRx1 = (uint8_t)pModList->SetRX1;
                LocalIPEnable.bits_st.FnResetRx2 = (uint8_t)pModList->SetRX2;
                LocalIPEnable.bits_st.FnResetRx3 = (uint8_t)pModList->SetRX3;
                LocalIPEnable.bits_st.FnResetRx4 = (uint8_t)pModList->SetRX4;
                LocalIPEnable.bits_st.FnResetSer = (uint8_t)pModList->SetSerialiser;
                LocalIPEnable.bits_st.FnResetSsbmod = (uint8_t)pModList->SetSSBMOD;
                LocalIPEnable.bits_st.FnResetTx1 = (uint8_t)pModList->SetTX1;
                LocalIPEnable.bits_st.FnResetTx2 = (uint8_t)pModList->SetTX2;
                LocalIPEnable.bits_st.FnResetTx3 = (uint8_t)pModList->SetTX3;
                LocalRegister = LocalIPEnable.val_u32;
            }
            break;
        }
        default:
            ErrCode = BC_ERR_INPUTOUTOFRANGE;
            break;
        }
        if (ErrCode == BC_ERR_NOERROR)
        {
            /* for read modified write*/
            ErrCode = BC_SPI_WriteCheck(e_SYS_CC, RegAddr, LocalRegister);
        }
    }
    else
    {
        ErrCode = BC_ERR_INPUTOUTOFRANGE;
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_CC_GetIntStatus(BOOL UseRawInt, CC_IntEvent_t *pIntStatus)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M00_IntRawStatusUnion_t IntRawStatus;
    R2M00_IntMaskedStatusUnion_t IntMaskedStatus;

    if (pIntStatus != NULL)
    {
        if (UseRawInt == TRUE)
        {
            ErrCode = BC_SPI_Read(e_SYS_CC, R2M00_INT_RAW_STATUS_U16, &IntRawStatus.val_u32);
            if (ErrCode == BC_ERR_NOERROR)
            {
                pIntStatus->StatusFlagInt = (BOOL)IntRawStatus.bits_st.StatusFlagIntStatusRaw;
                pIntStatus->CRCErrInt = (BOOL)IntRawStatus.bits_st.CrcErrorIntStatusRaw;
                pIntStatus->RFPowerDownInt = (BOOL)IntRawStatus.bits_st.RfPowerdownIntStatusRaw;
                pIntStatus->RTMInt = (BOOL)IntRawStatus.bits_st.RtmIntStatusRaw;
                pIntStatus->EndofDataTnfrInt = (BOOL)IntRawStatus.bits_st.EndOfDataTnfrIntStatusRaw;
                pIntStatus->StatusWDTInt = (BOOL)IntRawStatus.bits_st.StatusWdtIntStatusRaw;
                pIntStatus->ChirpIn = (BOOL)IntRawStatus.bits_st.ChirpIntStatusRaw;
            }
        }
        else
        {
            ErrCode = BC_SPI_Read(e_SYS_CC, R2M00_INT_MASKED_STATUS_U16, &IntMaskedStatus.val_u32);
            if (ErrCode == BC_ERR_NOERROR)
            {
                pIntStatus->StatusFlagInt = (BOOL)IntMaskedStatus.bits_st.StatusFlagIntStatusMasked;
                pIntStatus->CRCErrInt = (BOOL)IntMaskedStatus.bits_st.CrcErrorIntStatusMasked;
                pIntStatus->RFPowerDownInt = (BOOL)IntMaskedStatus.bits_st.RfPowerdownIntStatusMasked;
                pIntStatus->RTMInt = (BOOL)IntMaskedStatus.bits_st.RtmIntStatusMasked;
                pIntStatus->EndofDataTnfrInt = (BOOL)IntMaskedStatus.bits_st.EndOfDataTnfrIntStatusMasked;
                pIntStatus->StatusWDTInt = (BOOL)IntMaskedStatus.bits_st.StatusWdtIntStatusMasked;
                pIntStatus->ChirpIn = (BOOL)IntMaskedStatus.bits_st.ChirpIntStatusMasked;
            }
        }
    }
    else
    {
        ErrCode = BC_ERR_INPUTOUTOFRANGE;
    }
    return ErrCode;
}

static BC_ERRCODE Helper_ES2_EnDisInt(uint8_t Enable, CC_IntEvent_t *pIntEvents)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M00_IntEnableUnion_t IntEnable;
    ErrCode = BC_SPI_Read(e_SYS_CC, R2M00_INT_ENABLE_U16, &IntEnable.val_u32);
    if (ErrCode == BC_ERR_NOERROR)
    {
        /*If Enable is 1u, Logic OR with the current status so that it only 'enables' interrupts but does not disable*/
        /* IF Enable is 0u, Extra logic to prevent enabling bits, this portion only 'disables' but does not enable*/
        IntEnable.bits_st.CrcErrorIntEn = (pIntEvents->CRCErrInt == TRUE) ? Enable : IntEnable.bits_st.CrcErrorIntEn;
        IntEnable.bits_st.StatusFlagIntEn = (pIntEvents->StatusFlagInt == TRUE) ? Enable : IntEnable.bits_st.StatusFlagIntEn;
        IntEnable.bits_st.RfPowerdownIntEn = (pIntEvents->RFPowerDownInt == TRUE) ? Enable : IntEnable.bits_st.RfPowerdownIntEn;
        IntEnable.bits_st.RtmIntEn = (pIntEvents->RTMInt == TRUE) ? Enable : IntEnable.bits_st.RtmIntEn;
        IntEnable.bits_st.StatusWdtIntEn = (pIntEvents->StatusWDTInt == TRUE) ? Enable : IntEnable.bits_st.StatusWdtIntEn;
        IntEnable.bits_st.EndOfDataTnfrIntEn = (pIntEvents->EndofDataTnfrInt == TRUE) ? Enable : IntEnable.bits_st.EndOfDataTnfrIntEn;
        IntEnable.bits_st.ChirpIntEn = (pIntEvents->ChirpIn == TRUE) ? Enable : IntEnable.bits_st.ChirpIntEn;

        ErrCode = BC_SPI_WriteCheck(e_SYS_CC, R2M00_INT_ENABLE_U16, IntEnable.val_u32);
    }
    return ErrCode;
}

static BC_ERRCODE Helper_ES2_ClearInt(CC_IntEvent_t *pIntEvents)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M00_IntClrUnion_t IntClr;
    IntClr.val_u32 = 0u;
    IntClr.bits_st.CrcErrorIntClr = (uint8_t)pIntEvents->CRCErrInt;
    IntClr.bits_st.StatusFlagIntClr = (uint8_t)pIntEvents->StatusFlagInt;
    IntClr.bits_st.RfPowerdownIntClr = (uint8_t)pIntEvents->RFPowerDownInt;
    IntClr.bits_st.RtmIntClr = (uint8_t)pIntEvents->RTMInt;
    IntClr.bits_st.StatusWdtIntClr = (uint8_t)pIntEvents->StatusWDTInt;
    IntClr.bits_st.EndOfDataTnfrIntClr = (uint8_t)pIntEvents->EndofDataTnfrInt;
    IntClr.bits_st.ChirpIntClr = (uint8_t)pIntEvents->ChirpIn;

    /*Write only register*/
    ErrCode = BC_SPI_Write(e_SYS_CC, R2M00_INT_CLR_U16, IntClr.val_u32);
    return ErrCode;
}

BC_ERRCODE HAL_ES2_CC_EnDisClrInt(CC_CmdEnClrInt_e CommandReg, CC_IntEvent_t *pIntEvents)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    uint8_t Enable = 0u;

    if (pIntEvents == NULL)
    {
        ErrCode = BC_ERR_INPUTOUTOFRANGE;
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        switch (CommandReg)
        {
        case e_CC_ENABLE_INT:

            Enable = 1u;
            ErrCode = Helper_ES2_EnDisInt(Enable, pIntEvents);
            break;

        case e_CC_DISABLE_INT:

            Enable = 0u;
            ErrCode = Helper_ES2_EnDisInt(Enable, pIntEvents);
            break;

        case e_CC_CLEAR_INT:

            ErrCode = Helper_ES2_ClearInt(pIntEvents);
            break;
        default:
            ErrCode = BC_ERR_INPUTOUTOFRANGE;
            break;
        }
    }

    return ErrCode;
}

static uint8_t Helper_ES2_GetPowerControl(CC_DynPowMode_e DyPowSetting)
{
    uint8_t CntrlModeSelFlag = 1u;
    if (DyPowSetting == e_CC_DYN_POWMODE_NONE)
    {
        CntrlModeSelFlag = 0u;
    }
    return CntrlModeSelFlag;
}
static uint8_t Helper_ES2_GetModeSel(CC_DynPowMode_e DyPowSetting)
{
    uint8_t CntrlModeSelFlag = 1u;
    if (DyPowSetting <= e_CC_DYN_POWMODE_PERSEQUENCE)
    {
        CntrlModeSelFlag = 0u;
    }
    return CntrlModeSelFlag;
}
static BC_ERRCODE Helper_SetDynPowModeDown(CC_DynPowDnIPList_t *pPowDnIPList)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    CC_DynPowMode_e DyPowSetting;
    R2M00_DynamicPowerControlEnableUnion_t EnableDynamicPow;
    uint8_t TmpVal;

    EnableDynamicPow.val_u32 = 0u;

    DyPowSetting = pPowDnIPList->SetADC;
    EnableDynamicPow.bits_st.AdcDyPowerControl = Helper_ES2_GetPowerControl(DyPowSetting);
    EnableDynamicPow.bits_st.AdcDyPowerModeSel = Helper_ES2_GetModeSel(DyPowSetting);

    DyPowSetting = pPowDnIPList->SetChirp;
    EnableDynamicPow.bits_st.ChirpDyPowerControl = Helper_ES2_GetPowerControl(DyPowSetting);
    EnableDynamicPow.bits_st.ChirpDyPowerModeSel = Helper_ES2_GetModeSel(DyPowSetting);

    DyPowSetting = pPowDnIPList->SetRx1;
    EnableDynamicPow.bits_st.Rx1DyPowerControl = Helper_ES2_GetPowerControl(DyPowSetting);
    EnableDynamicPow.bits_st.Rx1DyPowerModeSel = Helper_ES2_GetModeSel(DyPowSetting);

    DyPowSetting = pPowDnIPList->SetRx2;
    EnableDynamicPow.bits_st.Rx2DyPowerControl = Helper_ES2_GetPowerControl(DyPowSetting);
    EnableDynamicPow.bits_st.Rx2DyPowerModeSel = Helper_ES2_GetModeSel(DyPowSetting);

    DyPowSetting = pPowDnIPList->SetRx3;
    EnableDynamicPow.bits_st.Rx3DyPowerControl = Helper_ES2_GetPowerControl(DyPowSetting);
    EnableDynamicPow.bits_st.Rx3DyPowerModeSel = Helper_ES2_GetModeSel(DyPowSetting);

    DyPowSetting = pPowDnIPList->SetRx4;
    EnableDynamicPow.bits_st.Rx4DyPowerControl = Helper_ES2_GetPowerControl(DyPowSetting);
    EnableDynamicPow.bits_st.Rx4DyPowerModeSel = Helper_ES2_GetModeSel(DyPowSetting);

    DyPowSetting = pPowDnIPList->SetTx1;
    EnableDynamicPow.bits_st.Tx1DyPowerControl = Helper_ES2_GetPowerControl(DyPowSetting);
    EnableDynamicPow.bits_st.Tx1DyPowerModeSel = Helper_ES2_GetModeSel(DyPowSetting);

    DyPowSetting = pPowDnIPList->SetTx2;
    EnableDynamicPow.bits_st.Tx2DyPowerControl = Helper_ES2_GetPowerControl(DyPowSetting);
    EnableDynamicPow.bits_st.Tx2DyPowerModeSel = Helper_ES2_GetModeSel(DyPowSetting);

    DyPowSetting = pPowDnIPList->SetTx3;
    EnableDynamicPow.bits_st.Tx3DyPowerControl = Helper_ES2_GetPowerControl(DyPowSetting);
    EnableDynamicPow.bits_st.Tx3DyPowerModeSel = Helper_ES2_GetModeSel(DyPowSetting);

    DyPowSetting = pPowDnIPList->SetLoInterface;
    EnableDynamicPow.bits_st.LoInterfaceDyPowerControl = Helper_ES2_GetPowerControl(DyPowSetting);
    EnableDynamicPow.bits_st.LoInterfaceDyPowerModeSel = (DyPowSetting <= e_CC_DYN_POWMODE_PERSEQUENCE) ? 0u : 1u;

    TmpVal = (pPowDnIPList->SetADCBGClib == e_CC_DYN_POWMODE_NONE) ? (uint8_t)4u : (uint8_t)pPowDnIPList->SetADCBGClib;
    EnableDynamicPow.bits_st.AdcBgCalibModeSel = (uint8_t)(TmpVal - (uint8_t)1u);

    ErrCode = BC_SPI_Write(e_SYS_CC, R2M00_DYNAMIC_POWER_CONTROL_ENABLE_U16, EnableDynamicPow.val_u32);

    return ErrCode;
}
static BC_ERRCODE Helper_ES2_PowDwTxRxIPRangeChck(CC_DynPowDnIPList_t *pPowDnIPList)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    if ((pPowDnIPList->SetRx1 >= e_CC_DYN_POWMODE_INVALID) ||
        (pPowDnIPList->SetRx2 >= e_CC_DYN_POWMODE_INVALID) ||
        (pPowDnIPList->SetRx3 >= e_CC_DYN_POWMODE_INVALID) ||
        (pPowDnIPList->SetRx4 >= e_CC_DYN_POWMODE_INVALID) ||
        (pPowDnIPList->SetTx1 >= e_CC_DYN_POWMODE_INVALID) ||
        (pPowDnIPList->SetTx2 >= e_CC_DYN_POWMODE_INVALID) ||
        (pPowDnIPList->SetTx3 >= e_CC_DYN_POWMODE_INVALID))
    {
        ErrCode = BC_ERR_INPUTOUTOFRANGE;
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_PowDwIPRangeCheck(CC_DynPowDnIPList_t *pPowDnIPList)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    if ((pPowDnIPList->SetADC >= e_CC_DYN_POWMODE_INVALID) ||
        (pPowDnIPList->SetChirp >= e_CC_DYN_POWMODE_INVALID) ||
        (pPowDnIPList->SetADCBGClib >= e_CC_DYN_POWMODE_INVALID) ||
        (pPowDnIPList->SetLoInterface >= e_CC_DYN_POWMODE_INVALID))
    {
        ErrCode = BC_ERR_INPUTOUTOFRANGE;
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = Helper_ES2_PowDwTxRxIPRangeChck(pPowDnIPList);
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_DynPowDwnRangeCheck(CC_DynPowDnIPList_t *pPowDnIPList, float32_t PowDownDelayPerChirp, float32_t PowDownDelayPerSequence)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    if (pPowDnIPList == NULL)
    {
        ErrCode = BC_ERR_CC_PTR_ADDR_NULL;
    }
    else
    {
        ErrCode = Helper_ES2_PowDwIPRangeCheck(pPowDnIPList);
    }
    if ((ErrCode == BC_ERR_NOERROR) && ((PowDownDelayPerChirp > CC_DYNAMIC_POWDWN_DELAY_MAX) || (PowDownDelayPerSequence > CC_DYNAMIC_POWDWN_DELAY_MAX) || (PowDownDelayPerChirp < 0.0f) || (PowDownDelayPerSequence < 0.0f)))
    {
        ErrCode = BC_ERR_INPUTOUTOFRANGE;
    }
    return ErrCode;
}
BC_ERRCODE HAL_ES2_CC_SetDynPowModeDown(CC_DynPowDnIPList_t *pPowDnIPList, float32_t PowDownDelayPerChirp, float32_t PowDownDelayPerSequence)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M00_DynamicPowerControlDelayUnion_t DelayDynamicPow;
    uint16_t TmpDelayVal;

    ErrCode = Helper_ES2_DynPowDwnRangeCheck(pPowDnIPList, PowDownDelayPerChirp, PowDownDelayPerSequence);

    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = Helper_SetDynPowModeDown(pPowDnIPList);
        if ((BC_ERR_NOERROR == ErrCode) && ((PowDownDelayPerChirp != 0.0f) || (PowDownDelayPerSequence != 0.0f)))
        {
            ErrCode = BC_SPI_Read(e_SYS_CC, R2M00_DYNAMIC_POWER_CONTROL_DELAY_U16, &DelayDynamicPow.val_u32);
            if ((BC_ERR_NOERROR == ErrCode) && (PowDownDelayPerChirp != 0.0))
            {
                TmpDelayVal = (uint16_t)(roundf(PowDownDelayPerChirp * 1000.0f / 25.0f));
                DelayDynamicPow.bits_st.DyPdDelayValChirp = TmpDelayVal;
            }
            if ((BC_ERR_NOERROR == ErrCode) && (PowDownDelayPerSequence != 0.0))
            {
                TmpDelayVal = (uint16_t)(roundf(PowDownDelayPerSequence * 1000.0f / 25.0f));
                DelayDynamicPow.bits_st.DyPdDelayValSeq = TmpDelayVal;
            }
            if (BC_ERR_NOERROR == ErrCode)
            {
                ErrCode = BC_SPI_WriteCheck(e_SYS_CC, R2M00_DYNAMIC_POWER_CONTROL_DELAY_U16, DelayDynamicPow.val_u32);
            }
        }
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_CC_EnLDOControl(uint8_t VoltOutSSBMOD, uint8_t VoltOutLVDS, uint8_t VoltOutMIPI, uint8_t VoltOutADC)
{
    R2M00_LdoControlUnion_t SetLdoControl;
    R2M00_LdoEnableUnion_t EnableLDO;
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    /* Max LDO volaage bits are 5 bits*/
    ErrCode = BC_SPI_Read(e_SYS_CC, R2M00_LDO_CONTROL_U16, &SetLdoControl.val_u32);
    ErrCode = (ErrCode | BC_SPI_Read(e_SYS_CC, R2M00_LDO_ENABLE_U16, &EnableLDO.val_u32));
    if (BC_ERR_NOERROR == ErrCode)
    {
        if (VoltOutSSBMOD != 0u)
        {
            EnableLDO.bits_st.LdoEnSsbmod = 1u;
            if ((VoltOutSSBMOD <= LOCAL_LDO_VOLTAGE_MASK))
            {
                SetLdoControl.bits_st.LdoSelVoutSsbmod = VoltOutSSBMOD;
            }
        }
        else
        {
            EnableLDO.bits_st.LdoEnSsbmod = 0u;
        }
        if (VoltOutLVDS != 0u)
        {
            EnableLDO.bits_st.LdoEnSerialiserSer = 1u;
            if ((VoltOutLVDS <= LOCAL_LDO_VOLTAGE_MASK))
            {
                SetLdoControl.bits_st.LdoSelVoutSerialiserSer = VoltOutLVDS;
            }
        }
        else
        {
            EnableLDO.bits_st.LdoEnSerialiserSer = 0u;
        }
        if (VoltOutMIPI != 0u)
        {
            EnableLDO.bits_st.LdoEnSerialiserCsi2 = 1u;
            if ((VoltOutMIPI <= LOCAL_LDO_VOLTAGE_MASK))
            {
                SetLdoControl.bits_st.LdoSelVoutSerialiserCsi2 = VoltOutMIPI;
            }
        }
        else
        {
            EnableLDO.bits_st.LdoEnSerialiserCsi2 = 0u;
        }
        if (VoltOutADC != 0u)
        {
            EnableLDO.bits_st.LdoEnAdc = 1u;
            if (VoltOutADC <= LOCAL_LDO_VOLTAGE_MASK)
            {
                SetLdoControl.bits_st.LdoSelVoutAdc = VoltOutADC;
            }
        }
        else
        {
            EnableLDO.bits_st.LdoEnAdc = 0u;
        }
        ErrCode = BC_SPI_WriteCheck(e_SYS_CC, R2M00_LDO_CONTROL_U16, SetLdoControl.val_u32);
        if (BC_ERR_NOERROR == ErrCode)
        {
            ErrCode = BC_SPI_WriteCheck(e_SYS_CC, R2M00_LDO_ENABLE_U16, EnableLDO.val_u32);
        }
    }
    return ErrCode;
}

static BC_ERRCODE Helper_ES2_ChirpStartCnfgPad(SYS_ExtPinID_e PadName, BOOL SetOutPort, uint8_t BitEhs0, uint8_t BitEhs1)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    uint16_t RegAddr = 0u;
    uint32_t LocalRegister = 0u;
    uint32_t tempValue = 0u;
    if (PadName == e_SYS_CHIRPSTART_IN_PAD)
    {
        R2M00_ChirpstartInPadControlUnion_t PadControl;
        RegAddr = R2M00_CHIRPSTART_IN_PAD_CONTROL_U16;
        ErrCode = BC_SPI_Read(e_SYS_CC, RegAddr, &PadControl.val_u32);
        if (ErrCode == BC_ERR_NOERROR)
        {
            PadControl.bits_st.ChirpstartMfioEhs0 = BitEhs0;
            PadControl.bits_st.ChirpstartMfioEhs1 = BitEhs1;
            if (TRUE == SetOutPort)
            {
                PadControl.bits_st.ChirpstartOutRouteEn = 0x1u; // enabling Out routing
                PadControl.bits_st.ChirpstartInRouteEn = 0x0u;
                PadControl.bits_st.ChirpstartMfioEn = 0x0u;
            }
            else
            {
                PadControl.bits_st.ChirpstartOutRouteEn = 0x0u;
                PadControl.bits_st.ChirpstartInRouteEn = 0x1u; // enabling In routing
                PadControl.bits_st.ChirpstartMfioEn = 0x1u;
            }
            LocalRegister = PadControl.val_u32;
        }
    }
    if (PadName == e_SYS_MCUINT_CHIRPSTART_OUT_PAD)
    {
        R2M00_McuintChirpstartOutPadControlUnion_t PadControl;
        RegAddr = R2M00_MCUINT_CHIRPSTART_OUT_PAD_CONTROL_U16;
        ErrCode = BC_SPI_Read(e_SYS_CC, RegAddr, &PadControl.val_u32);
        if (ErrCode == BC_ERR_NOERROR)
        {
            PadControl.bits_st.McuintChirpstartMfioEhs0 = BitEhs0;
            PadControl.bits_st.McuintChirpstartMfioEhs1 = BitEhs1;
            tempValue = (uint32_t)SetOutPort;
            PadControl.bits_st.McuintChirpstartMfioEn = (uint8_t)(~tempValue & 0x01u);
            LocalRegister = PadControl.val_u32;
        }
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        /* for read modified write*/
        ErrCode = BC_SPI_WriteCheck(e_SYS_CC, RegAddr, LocalRegister);
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_ErrorCnfgPad(SYS_ExtPinID_e PadName, BOOL SetOutPort, uint8_t BitEhs0, uint8_t BitEhs1)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    uint32_t tempValue = 0u;
    uint16_t RegAddr = 0u;
    uint32_t LocalRegister = 0u;

    if (PadName == e_SYS_ERRORN)
    {
        R2M00_ErrorNPadControlUnion_t PadControl;
        RegAddr = R2M00_ERROR_N_PAD_CONTROL_U16;
        ErrCode = BC_SPI_Read(e_SYS_CC, RegAddr, &PadControl.val_u32);
        if (ErrCode == BC_ERR_NOERROR)
        {
            PadControl.bits_st.ErrorNMfioEhs0 = BitEhs0;
            PadControl.bits_st.ErrorNMfioEhs1 = BitEhs1;
            tempValue = (uint32_t)SetOutPort;
            PadControl.bits_st.ErrorNMfioEn = (uint8_t)(~tempValue & 0x01u);
            LocalRegister = PadControl.val_u32;
        }
    }
    if (PadName == e_SYS_ERRORRESET)
    {
        R2M00_ErrorResetPadControlUnion_t PadControl;
        RegAddr = R2M00_ERROR_RESET_PAD_CONTROL_U16;
        ErrCode = BC_SPI_Read(e_SYS_CC, RegAddr, &PadControl.val_u32);
        if (ErrCode == BC_ERR_NOERROR)
        {
            if (SetOutPort == FALSE)
            {
                PadControl.bits_st.ErrorResetMfioEhs0 = BitEhs0;
                PadControl.bits_st.ErrorResetMfioEhs1 = BitEhs1;
                tempValue = (uint32_t)SetOutPort;
                PadControl.bits_st.ErrorResetMfioEn = (uint8_t)(~tempValue & 0x01u);
                LocalRegister = PadControl.val_u32;
            }
            else
            {
                ErrCode = BC_ERR_INPUTOUTOFRANGE;
            }
        }
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        /* for read modified write*/
        ErrCode = BC_SPI_WriteCheck(e_SYS_CC, RegAddr, LocalRegister);
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_TXIPSCnfgPad(SYS_ExtPinID_e PadName, BOOL SetOutPort, uint8_t BitEhs0, uint8_t BitEhs1)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    uint32_t tempValue = 0u;
    uint16_t RegAddr = 0u;
    uint32_t LocalRegister = 0u;
    if (PadName == e_SYS_TX1_I_PS)
    {
        R2M00_Tx1PsIPadControlUnion_t PadControl;
        RegAddr = R2M00_TX1_PS_I_PAD_CONTROL_U16;
        ErrCode = BC_SPI_Read(e_SYS_CC, RegAddr, &PadControl.val_u32);
        if (ErrCode == BC_ERR_NOERROR)
        {
            PadControl.bits_st.Tx1PsIMfioEhs0 = BitEhs0;
            PadControl.bits_st.Tx1PsIMfioEhs1 = BitEhs1;
            tempValue = (uint32_t)SetOutPort;
            PadControl.bits_st.Tx1PsIMfioEn = (uint8_t)(~tempValue & 0x01u);
            LocalRegister = PadControl.val_u32;
        }
    }
    if (PadName == e_SYS_TX2_I_PS)
    {
        R2M00_Tx2PsIPadControlUnion_t PadControl;
        RegAddr = R2M00_TX2_PS_I_PAD_CONTROL_U16;
        ErrCode = BC_SPI_Read(e_SYS_CC, RegAddr, &PadControl.val_u32);
        if (ErrCode == BC_ERR_NOERROR)
        {
            PadControl.bits_st.Tx2PsIMfioEhs0 = BitEhs0;
            PadControl.bits_st.Tx2PsIMfioEhs1 = BitEhs1;
            tempValue = (uint32_t)SetOutPort;
            PadControl.bits_st.Tx2PsIMfioEn = (uint8_t)(~tempValue & 0x01u);
            LocalRegister = PadControl.val_u32;
        }
    }
    if (PadName == e_SYS_TX3_I_PS)
    {
        R2M00_Tx3PsIPadControlUnion_t PadControl;
        RegAddr = R2M00_TX3_PS_I_PAD_CONTROL_U16;
        ErrCode = BC_SPI_Read(e_SYS_CC, RegAddr, &PadControl.val_u32);
        if (ErrCode == BC_ERR_NOERROR)
        {
            PadControl.bits_st.Tx3PsIMfioEhs0 = BitEhs0;
            PadControl.bits_st.Tx3PsIMfioEhs1 = BitEhs1;
            tempValue = (uint32_t)SetOutPort;
            PadControl.bits_st.Tx3PsIMfioEn = (uint8_t)(~tempValue & 0x01u);
            LocalRegister = PadControl.val_u32;
        }
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        /* for read modified write*/
        ErrCode = BC_SPI_WriteCheck(e_SYS_CC, RegAddr, LocalRegister);
    }
    return ErrCode;
}
static BC_ERRCODE Helper_ES2_TXQPSCnfgPad(SYS_ExtPinID_e PadName, BOOL SetOutPort, uint8_t BitEhs0, uint8_t BitEhs1)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    uint32_t tempValue = 0u;
    uint16_t RegAddr = 0u;
    uint32_t LocalRegister = 0u;
    if (PadName == e_SYS_TX1_Q_PS)
    {
        R2M00_Tx1PsQPadControlUnion_t PadControl;
        RegAddr = R2M00_TX1_PS_Q_PAD_CONTROL_U16;
        ErrCode = BC_SPI_Read(e_SYS_CC, RegAddr, &PadControl.val_u32);
        if (ErrCode == BC_ERR_NOERROR)
        {
            PadControl.bits_st.Tx1PsQMfioEhs0 = BitEhs0;
            PadControl.bits_st.Tx1PsQMfioEhs1 = BitEhs1;
            tempValue = (uint32_t)SetOutPort;
            PadControl.bits_st.Tx1PsQMfioEn = (uint8_t)(~tempValue & 0x01u);
            LocalRegister = PadControl.val_u32;
        }
    }
    if (PadName == e_SYS_TX2_Q_PS)
    {
        R2M00_Tx2PsQPadControlUnion_t PadControl;
        RegAddr = R2M00_TX2_PS_Q_PAD_CONTROL_U16;
        ErrCode = BC_SPI_Read(e_SYS_CC, RegAddr, &PadControl.val_u32);
        if (ErrCode == BC_ERR_NOERROR)
        {
            PadControl.bits_st.Tx2PsQMfioEhs0 = BitEhs0;
            PadControl.bits_st.Tx2PsQMfioEhs1 = BitEhs1;
            tempValue = (uint32_t)SetOutPort;
            PadControl.bits_st.Tx2PsQMfioEn = (uint8_t)(~tempValue & 0x01u);
            LocalRegister = PadControl.val_u32;
        }
    }
    if (PadName == e_SYS_TX3_Q_PS)
    {
        R2M00_Tx3PsQPadControlUnion_t PadControl;
        RegAddr = R2M00_TX3_PS_Q_PAD_CONTROL_U16;
        ErrCode = BC_SPI_Read(e_SYS_CC, RegAddr, &PadControl.val_u32);
        if (ErrCode == BC_ERR_NOERROR)
        {
            PadControl.bits_st.Tx3PsQMfioEhs0 = BitEhs0;
            PadControl.bits_st.Tx3PsQMfioEhs1 = BitEhs1;
            tempValue = (uint32_t)SetOutPort;
            PadControl.bits_st.Tx3PsQMfioEn = (uint8_t)(~tempValue & 0x01u);
            LocalRegister = PadControl.val_u32;
        }
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        /* for read modified write*/
        ErrCode = BC_SPI_WriteCheck(e_SYS_CC, RegAddr, LocalRegister);
    }
    return ErrCode;
}
BC_ERRCODE HAL_ES2_CC_ConfigPad(BOOL SetOutPort, CC_PINSpeed_e Speed, SYS_ExtPinID_e PadName)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    uint8_t BitEhs0 = 0u;
    uint8_t BitEhs1 = 0u;

    if (Speed < e_CC_PADSPEED_INVALID)
    {
        BitEhs0 = (uint8_t)Speed & 0x01u;
        BitEhs1 = (((uint8_t)Speed & 0x02u) >> 1u);
        switch (PadName)
        {
        case e_SYS_CHIRPSTART_IN_PAD:
        case e_SYS_MCUINT_CHIRPSTART_OUT_PAD:
        {
            ErrCode = Helper_ES2_ChirpStartCnfgPad(PadName, SetOutPort, BitEhs0, BitEhs1);
            break;
        }
        case e_SYS_ERRORN:
        case e_SYS_ERRORRESET:
        {
            ErrCode = Helper_ES2_ErrorCnfgPad(PadName, SetOutPort, BitEhs0, BitEhs1);
            break;
        }
        case e_SYS_TX1_I_PS:
        case e_SYS_TX2_I_PS:
        case e_SYS_TX3_I_PS:
        {
            ErrCode = Helper_ES2_TXIPSCnfgPad(PadName, SetOutPort, BitEhs0, BitEhs1);
            break;
        }
        case e_SYS_TX1_Q_PS:
        case e_SYS_TX2_Q_PS:
        case e_SYS_TX3_Q_PS:
        {
            ErrCode = Helper_ES2_TXQPSCnfgPad(PadName, SetOutPort, BitEhs0, BitEhs1);
            break;
        }
        default:
        {
            ErrCode = BC_ERR_INPUTOUTOFRANGE;
            break;
        }
        }
    }
    else
    {
        ErrCode = BC_ERR_INPUTOUTOFRANGE;
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_CC_ConfigMCUInt(BOOL Polarity, BOOL TriggerMode, uint8_t IntPeriod)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M00_McuIntControlUnion_t ReadIntConfig;

    ErrCode = BC_SPI_Read(e_SYS_CC, R2M00_MCU_INT_CONTROL_U16, &ReadIntConfig.val_u32);
    if (ErrCode == BC_ERR_NOERROR)
    {
        ReadIntConfig.bits_st.InterruptPolarity = (uint8_t)Polarity;
        ReadIntConfig.bits_st.InterruptLevelOrPulse = (uint8_t)TriggerMode;
        ReadIntConfig.bits_st.InterruptPeriod = (uint8_t)IntPeriod;
        ErrCode = BC_SPI_WriteCheck(e_SYS_CC, R2M00_MCU_INT_CONTROL_U16, ReadIntConfig.val_u32);
    }
    return ErrCode;
}
BC_ERRCODE HAL_ES2_CC_SwitchMcuIntCSOut(BOOL CsOutEn)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M00_PinMuxUnion_t PinMux;

    ErrCode = BC_SPI_Read(e_SYS_CC, R2M00_PIN_MUX_U16, &PinMux.val_u32);
    if (ErrCode == BC_ERR_NOERROR)
    {
        PinMux.bits_st.PinmuxSel = (CsOutEn == TRUE) ? 0x01u : 0x00u;
        ErrCode = BC_SPI_WriteCheck(e_SYS_CC, R2M00_PIN_MUX_U16, PinMux.val_u32);
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_CC_TriggerADCBGCalib(void)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M00_DynamicPowerControlEnableUnion_t DynamicPow;

    ErrCode = BC_SPI_Read(e_SYS_CC, R2M00_DYNAMIC_POWER_CONTROL_ENABLE_U16, &DynamicPow.val_u32);

    if (ErrCode == BC_ERR_NOERROR)
    {
        DynamicPow.bits_st.AdcBgCalibModeSel = 2u;
        DynamicPow.bits_st.TriggerBgCalManual = 1u;
        ErrCode = BC_SPI_Write(e_SYS_CC, R2M00_DYNAMIC_POWER_CONTROL_ENABLE_U16, DynamicPow.val_u32);
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_CC_GetMaskVersion(uint8_t *pMaskVersion)
{
    BC_ERRCODE ErrCode;
    R2M00_ModuleIdUnion_t ModuleId;

    if (pMaskVersion != NULL)
    {
        ErrCode = BC_SPI_Read(e_SYS_CC, R2M00_MODULE_ID_U16, &ModuleId.val_u32);
        if (ErrCode == BC_ERR_NOERROR)
        {
            *pMaskVersion = (((uint8_t)ModuleId.bits_st.Idcode & 0xCu) >> 2u) + 1u;
        }
    }
    else
    {
        ErrCode = BC_ERR_CC_PTR_ADDR_NULL;
    }
    return ErrCode;
}
#endif
/* End of File */
