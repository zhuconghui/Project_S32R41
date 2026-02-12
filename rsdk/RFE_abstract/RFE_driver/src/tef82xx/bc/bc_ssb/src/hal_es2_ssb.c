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

#include <math.h>
#include <stdlib.h>
#ifdef TEF82XX_CFG_ES2
#include "bc_spi.h"
#include "bc_types.h"
#include "bc_conf.h"
#include "bc_err.h"
#include "bc_otp.h"
#include "plf.h"

#include "hal_es2_ssb.h"
#ifdef BUILD_FOR_VAL
#include "v_es2_ssb.h"
#include "v_es2_cc.h"
#else
#include "reg_es2_ssb.h"
#include "reg_es2_cc.h"
#endif

BC_ERRCODE HAL_ES2_SSB_ConfigRFBIST(SSB_ConfigRFBIST_t *pConfigRFBIST)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M14_SsbmodControlUnion_t SSBModControl;
    R2M14_IfControlUnion_t IFControl;
    R2M14_LevelSetUnion_t LevelSet;

    if ((pConfigRFBIST != NULL) && (pConfigRFBIST->Divider1 < 32u) && (pConfigRFBIST->Divider2 < 8u) && (pConfigRFBIST->IFLevel < 16u) && (pConfigRFBIST->OutputLevel < 64u))
    {
        ErrCode = BC_SPI_Read(e_SYS_SSB, R2M14_SSBMOD_CONTROL_U16, &SSBModControl.val_u32);
        if (ErrCode == BC_ERR_NOERROR)
        {
            SSBModControl.bits_st.SsbmodEn = (uint8_t)pConfigRFBIST->EnSSBMod;
            SSBModControl.bits_st.Div1Set = pConfigRFBIST->Divider1;
            SSBModControl.bits_st.Div2Set = pConfigRFBIST->Divider2;
            SSBModControl.bits_st.Clk600En = (uint8_t)pConfigRFBIST->EnCLK600;
            SSBModControl.bits_st.ModSel = (uint8_t)pConfigRFBIST->EnExtSignalGen;
            ErrCode = BC_SPI_WriteCheck(e_SYS_SSB, R2M14_SSBMOD_CONTROL_U16, SSBModControl.val_u32);
        }
        if (ErrCode == BC_ERR_NOERROR)
        {
            IFControl.val_u32 = 0u;
            IFControl.bits_st.IfLevelSet = pConfigRFBIST->IFLevel;
            ErrCode = BC_SPI_WriteCheck(e_SYS_SSB, R2M14_IF_CONTROL_U16, IFControl.val_u32);
        }
        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = BC_SPI_Read(e_SYS_SSB, R2M14_LEVEL_SET_U16, &LevelSet.val_u32);
            if (ErrCode == BC_ERR_NOERROR)
            {
                LevelSet.bits_st.LevelSetCtrl = pConfigRFBIST->OutputLevel;
                ErrCode = BC_SPI_WriteCheck(e_SYS_SSB, R2M14_LEVEL_SET_U16, LevelSet.val_u32);
            }
        }
    }
    else
    {
        ErrCode = BC_ERR_INPUTOUTOFRANGE;
    }

    return ErrCode;
}

BC_ERRCODE HAL_ES2_SSB_RFBISTStaticConfig(uint8_t Decimation)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    SSB_ConfigRFBIST_t ConfigRFBIST = {SSB_IF_FREQ_CAL_FIRST_DIVIDER, SSB_IF_FREQ_CAL_SECOND_DIVIDER, SSB_MOD_OUTPUT_LEVEL, SSB_DEFAULT_IF_SIGNAL_LEVEL_CODE, TRUE, TRUE, FALSE};
    switch (Decimation)
    {
    case 1u:
        ConfigRFBIST.Divider1 = 1u; //2 x Decimation - 1
        break;
    case 2u:
        ConfigRFBIST.Divider1 = 3u; //2 x Decimation - 1
        break;
    case 4u:
        ConfigRFBIST.Divider1 = 7u; //2 x Decimation - 1
        break;
    case 8u:
        ConfigRFBIST.Divider1 = 15u; //2 x Decimation - 1
        break;
    case 16u:
        ConfigRFBIST.Divider1 = 31u; //2 x Decimation - 1
        break;
    default:
        ErrCode = BC_ERR_INPUTOUTOFRANGE;
        break;
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = HAL_ES2_SSB_EnableSSB(TRUE);
    }
    //Distribute otp for SSB
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_OTP_DistributeOTPData(e_OTP_SPARE_TRIM, (OTP_SPARE_TRIM_COUNT - 1u), OTP_SPARE_TRIM_COUNT);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = HAL_ES2_SSB_ConfigRFBIST(&ConfigRFBIST);
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_SSB_EnableRMSDet(BOOL EnRMSDet)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M14_SsbmodControlUnion_t SsbmodControl;

    ErrCode = BC_SPI_Read(e_SYS_SSB, R2M14_SSBMOD_CONTROL_U16, &SsbmodControl.val_u32);
    if (ErrCode == BC_ERR_NOERROR)
    {
        SsbmodControl.bits_st.EnRfDet = (uint8_t)EnRMSDet;
        ErrCode = BC_SPI_WriteCheck(e_SYS_SSB, R2M14_SSBMOD_CONTROL_U16, SsbmodControl.val_u32);
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_SSB_EnableSSB(BOOL Enable)
{
    BC_ERRCODE ErrCode;
    R2M00_LdoEnableUnion_t EnableLDO;

    R2M00_IpFunctionalResetControlUnion_t IPFunctionalReset;
    R2M00_IpLevelClockEnableUnion_t EnableIPClock;
    R2M00_IpResetControlUnion_t ResetIP;

    if (TRUE == Enable)
    {
        ErrCode = BC_SPI_Read(e_SYS_CC, R2M00_LDO_ENABLE_U16, &EnableLDO.val_u32);
        if (ErrCode == BC_ERR_NOERROR)
        {
            EnableLDO.bits_st.LdoEnSsbmod = Enable;
            ErrCode = BC_SPI_WriteCheck(e_SYS_CC, R2M00_LDO_ENABLE_U16, EnableLDO.val_u32);
        }
        if (ErrCode == BC_ERR_NOERROR)
        {
            /*Add delay 20us*/
            ErrCode = PLF_TM_Sleep(SSB_ENABLELDO_SLEEP);
        }
        if (ErrCode == BC_ERR_NOERROR)
        {
            /*Enable SSB Clock SSB*/
            ErrCode = BC_SPI_Read(e_SYS_CC, R2M00_IP_LEVEL_CLOCK_ENABLE_U16, &EnableIPClock.val_u32);
            if (ErrCode == BC_ERR_NOERROR)
            {
                EnableIPClock.bits_st.Clk40Ssbmod = Enable;
                ErrCode = BC_SPI_WriteCheck(e_SYS_CC, R2M00_IP_LEVEL_CLOCK_ENABLE_U16, EnableIPClock.val_u32);
            }
        }
        if (ErrCode == BC_ERR_NOERROR)
        {
            /*Reset release after enabling the clock*/
            ErrCode = BC_SPI_Read(e_SYS_CC, R2M00_IP_RESET_CONTROL_U16, &ResetIP.val_u32);
            if (ErrCode == BC_ERR_NOERROR)
            {
                ResetIP.bits_st.ResetSsbmod = Enable;
                ErrCode = BC_SPI_WriteCheck(e_SYS_CC, R2M00_IP_RESET_CONTROL_U16, ResetIP.val_u32);
            }
        }
        if (ErrCode == BC_ERR_NOERROR)
        {
            /*Functional Reset SSB*/
            ErrCode = BC_SPI_Read(e_SYS_CC, R2M00_IP_FUNCTIONAL_RESET_CONTROL_U16, &IPFunctionalReset.val_u32);
            if (ErrCode == BC_ERR_NOERROR)
            {
                IPFunctionalReset.bits_st.FnResetSsbmod = Enable;
                ErrCode = BC_SPI_WriteCheck(e_SYS_CC, R2M00_IP_FUNCTIONAL_RESET_CONTROL_U16, IPFunctionalReset.val_u32);
            }
        }
    }
    else
    {
        /*Functional Reset SSB*/
        ErrCode = BC_SPI_Read(e_SYS_CC, R2M00_IP_FUNCTIONAL_RESET_CONTROL_U16, &IPFunctionalReset.val_u32);
        if (ErrCode == BC_ERR_NOERROR)
        {
            IPFunctionalReset.bits_st.FnResetSsbmod = Enable;
            ErrCode = BC_SPI_WriteCheck(e_SYS_CC, R2M00_IP_FUNCTIONAL_RESET_CONTROL_U16, IPFunctionalReset.val_u32);
        }
        if (ErrCode == BC_ERR_NOERROR)
        {
            /*Reset release after before disabling the clock*/
            ErrCode = BC_SPI_Read(e_SYS_CC, R2M00_IP_RESET_CONTROL_U16, &ResetIP.val_u32);
            if (ErrCode == BC_ERR_NOERROR)
            {
                ResetIP.bits_st.ResetSsbmod = Enable;
                ErrCode = BC_SPI_WriteCheck(e_SYS_CC, R2M00_IP_RESET_CONTROL_U16, ResetIP.val_u32);
            }
        }
        if (ErrCode == BC_ERR_NOERROR)
        {
            /*Disable SSB Clock */
            ErrCode = BC_SPI_Read(e_SYS_CC, R2M00_IP_LEVEL_CLOCK_ENABLE_U16, &EnableIPClock.val_u32);
            if (ErrCode == BC_ERR_NOERROR)
            {
                EnableIPClock.bits_st.Clk40Ssbmod = Enable;
                ErrCode = BC_SPI_WriteCheck(e_SYS_CC, R2M00_IP_LEVEL_CLOCK_ENABLE_U16, EnableIPClock.val_u32);
            }
        }
        if (ErrCode == BC_ERR_NOERROR)
        {
            /*Disable SSB Local LDO*/
            ErrCode = BC_SPI_Read(e_SYS_CC, R2M00_LDO_ENABLE_U16, &EnableLDO.val_u32);
            if (ErrCode == BC_ERR_NOERROR)
            {
                EnableLDO.bits_st.LdoEnSsbmod = Enable;
                ErrCode = BC_SPI_WriteCheck(e_SYS_CC, R2M00_LDO_ENABLE_U16, EnableLDO.val_u32);
            }
        }
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_SSB_ChangePowerState(BOOL PowerON)
{
    BC_ERRCODE ErrCode;
    R2M00_IpLevelPonEnableUnion_t LocalIPEnable;

    /*PON SSB*/
    ErrCode = BC_SPI_Read(e_SYS_CC, R2M00_IP_LEVEL_PON_ENABLE_U16, &LocalIPEnable.val_u32);
    if (ErrCode == BC_ERR_NOERROR)
    {
        LocalIPEnable.bits_st.PonSsbmodEn = PowerON;
        ErrCode = BC_SPI_WriteCheck(e_SYS_CC, R2M00_IP_LEVEL_PON_ENABLE_U16, LocalIPEnable.val_u32);
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_SSB_CalibrateRFBISTGain(int32_t TargetIFLevel, int32_t LastIFLevel)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M14_IfControlUnion_t IFControl;
    uint8_t IfLevelSetLUTCode[SSB_IFLEVEL_INDEX_RANGE] = {0u, 1u, 2u, 3u, 4u, 5u, 6u, 7u, 12u, 13u, 14u, 15u};
    int32_t IfLevelSetGaindB[SSB_IFLEVEL_INDEX_RANGE] = {0, 4, 8, 12, 16, 20, 24, 28, 33, 37, 41, 45};
    int32_t AvailableDeltas[SSB_IFLEVEL_INDEX_RANGE] = {0};
    int32_t MinimumDelta = 45;
    int32_t TempMinimumDelta;
    uint8_t PreviousIfLevelSet = 0u;
    uint8_t Index, SearchIndex = 0u, MinSearchIndex = 0u;
    /*Derive amount of gain delta from target*/
    int32_t GainShortage = LastIFLevel - TargetIFLevel;
    ErrCode = BC_SPI_Read(e_SYS_SSB, R2M14_IF_CONTROL_U16, &IFControl.val_u32);
    if (ErrCode == BC_ERR_NOERROR)
    {
        PreviousIfLevelSet = IFControl.bits_st.IfLevelSet;
    }
    if ((ErrCode == BC_ERR_NOERROR) && ((TargetIFLevel > SSB_MINIMUM_IFLEVEL) || (LastIFLevel > SSB_MINIMUM_IFLEVEL) || (PreviousIfLevelSet >= SSB_MAXIMUM_LASTIFLEVELREG)))
    {
        ErrCode = BC_ERR_SSB_INPUTOUTOFRANGE;
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        /*The gain code is searched based on PreviousIfLevelSet, and find the corresponding gain in IfLevelSetLUTCode.*/
        for (Index = 0u; Index < SSB_IFLEVEL_INDEX_RANGE; Index++)
        {
            if (IfLevelSetLUTCode[Index] == PreviousIfLevelSet)
            {
                SearchIndex = Index;
                break;
            }
        }
        for (Index = 0u; Index < SSB_IFLEVEL_INDEX_RANGE; Index++)
        {
            AvailableDeltas[Index] = IfLevelSetGaindB[Index] - IfLevelSetGaindB[SearchIndex] + GainShortage;
            TempMinimumDelta = abs(AvailableDeltas[Index]);
            if (TempMinimumDelta < MinimumDelta)
            {
                MinimumDelta = TempMinimumDelta;
                MinSearchIndex = Index;
            }
        }
        IFControl.val_u32 = 0u;
        IFControl.bits_st.IfLevelSet = IfLevelSetLUTCode[MinSearchIndex];
        ErrCode = BC_SPI_WriteCheck(e_SYS_SSB, R2M14_IF_CONTROL_U16, IFControl.val_u32);
    }

    return ErrCode;
}

BC_ERRCODE HAL_ES2_SSB_CalibRFBISTGainStAl(int32_t TargetIFLevel, int32_t LastIFLevel, uint8_t PreviousIfLevelCode, uint8_t *pCurrentIfLevelCode)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M14_IfControlUnion_t IFControl;
    uint8_t IfLevelSetLUTCode[SSB_IFLEVEL_INDEX_RANGE] = {0u, 1u, 2u, 3u, 4u, 5u, 6u, 7u, 12u, 13u, 14u, 15u};
    int32_t IfLevelSetGaindB[SSB_IFLEVEL_INDEX_RANGE] = {0, 4, 8, 12, 16, 20, 24, 28, 33, 37, 41, 45};
    int32_t AvailableDeltas[SSB_IFLEVEL_INDEX_RANGE] = {0};
    int32_t MinimumDelta = 45;
    int32_t TempMinimumDelta;
    uint8_t Index, SearchIndex = SSB_INVALID_GAIN_CODE_SEARCH_INDEX, MinSearchIndex = 0u;
    /*Derive amount of gain delta from target*/
    int32_t GainShortage = LastIFLevel - TargetIFLevel;

    if ((pCurrentIfLevelCode == NULL) || ((TargetIFLevel > SSB_MINIMUM_IFLEVEL) || (LastIFLevel > SSB_MINIMUM_IFLEVEL) || (PreviousIfLevelCode >= SSB_MAXIMUM_LASTIFLEVELREG)))
    {
        ErrCode = BC_ERR_SSB_INPUTOUTOFRANGE;
    }

    if (ErrCode == BC_ERR_NOERROR)
    {
        /*The gain code is searched based on PreviousIfLevelCode, and find the corresponding gain in IfLevelSetLUTCode.*/
        for (Index = 0u; Index < SSB_IFLEVEL_INDEX_RANGE; Index++)
        {
            if (IfLevelSetLUTCode[Index] == PreviousIfLevelCode)
            {
                SearchIndex = Index;
                break;
            }
        }
    }
    if (SearchIndex == SSB_INVALID_GAIN_CODE_SEARCH_INDEX)
    {
        ErrCode = BC_ERR_SSB_INPUTOUTOFRANGE;
    }

    if (ErrCode == BC_ERR_NOERROR)
    {
        for (Index = 0u; Index < SSB_IFLEVEL_INDEX_RANGE; Index++)
        {
            AvailableDeltas[Index] = IfLevelSetGaindB[Index] - IfLevelSetGaindB[SearchIndex] + GainShortage;
            TempMinimumDelta = abs(AvailableDeltas[Index]);
            if (TempMinimumDelta < MinimumDelta)
            {
                MinimumDelta = TempMinimumDelta;
                MinSearchIndex = Index;
            }
        }
        *pCurrentIfLevelCode = IfLevelSetLUTCode[MinSearchIndex];
        IFControl.val_u32 = 0u;
        IFControl.bits_st.IfLevelSet = IfLevelSetLUTCode[MinSearchIndex];
        ErrCode = BC_SPI_WriteCheck(e_SYS_SSB, R2M14_IF_CONTROL_U16, IFControl.val_u32);
    }

    return ErrCode;
}

#endif
