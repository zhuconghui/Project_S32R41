/*
 * Copyright 2020-2023 NXP
 * NXP Confidential. This software is owned or controlled by NXP and may only
 * be used strictly in accordance with the applicable license terms. By
 * expressly accepting such terms or by downloading, installing, activating
 * and/or otherwise using the software, you are agreeing that you have read,
 * and that you agree to comply with and are bound by, such license terms. If
 * you do not agree to be bound by the applicable license terms, then you may
 * not retain, install, activate or otherwise use the software.
 */

#ifdef TEF82XX_CFG_ES2
#include "bc_types.h"
#include "bc_err.h"
#include "bc_spi.h"
#include "hal_es2_gbias.h"
// Register header
#include "reg_es2_gbias.h"
static BC_ERRCODE Helper_GBIAS_SetCtrlBgr(uint8_t BgrBiasCurrent);
static BC_ERRCODE Helper_GBIAS_SetCtrlPtat(uint8_t PtatBiasCurrent);
static BC_ERRCODE Helper_GBIAS_SetCtrlPtatBg(uint8_t PtatBiasCurrent, uint8_t BgBiasCurrent);

BC_ERRCODE HAL_ES2_GBIAS_EnableSSBBias(BOOL Enable)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M09_GlobbiasSsbmodUnion_t GlobbiasSsbmod;
    ErrCode = BC_SPI_Read(e_SYS_GBIAS, R2M09_GLOBBIAS_SSBMOD_U16, &GlobbiasSsbmod.val_u32);
    if (ErrCode == BC_ERR_NOERROR)
    {
        if (Enable == TRUE)
        {
            R2M09_GlobbiasIrefAllIpUnion_t GlobbiasIrefAllIp;
            ErrCode = BC_SPI_Read(e_SYS_GBIAS, R2M09_GLOBBIAS_IREF_ALL_IP_U16, &GlobbiasIrefAllIp.val_u32);
            if (ErrCode == BC_ERR_NOERROR)
            {
                GlobbiasSsbmod.bits_st.CtrlIrefSsbmodPtat = (uint8_t)GlobbiasIrefAllIp.bits_st.CtrlIrefAllIpPtat;
                GlobbiasSsbmod.bits_st.CtrlIrefSsbmodBgr = (uint8_t)GlobbiasIrefAllIp.bits_st.CtrlIrefAllIpBgr;
                ErrCode = BC_SPI_WriteCheck(e_SYS_GBIAS, R2M09_GLOBBIAS_SSBMOD_U16, GlobbiasSsbmod.val_u32);
            }
        }
        else
        {

            GlobbiasSsbmod.bits_st.CtrlIrefSsbmodPtat = 0u;
            GlobbiasSsbmod.bits_st.CtrlIrefSsbmodBgr = 0u;
            ErrCode = BC_SPI_WriteCheck(e_SYS_GBIAS, R2M09_GLOBBIAS_SSBMOD_U16, GlobbiasSsbmod.val_u32);
        }
    }

    return ErrCode;
}

static BC_ERRCODE Helper_GBIAS_SetCtrlBgr(uint8_t BgrBiasCurrent)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    // Same register value for MCLK and ADC12, ADC34, ATB and SNS as they have same bitfield structure.
    R2M09_GlobbiasMasterclkUnion_t GlobbiasMasterclk;
    GlobbiasMasterclk.val_u32 = 0u;
    GlobbiasMasterclk.bits_st.CtrlIrefMasterclkBgr = BgrBiasCurrent;
    ErrCode = BC_SPI_WriteCheck(e_SYS_GBIAS, R2M09_GLOBBIAS_MASTERCLK_U16, GlobbiasMasterclk.val_u32);
    if (ErrCode == BC_ERR_NOERROR)
    {
        // Same register value for MCLK and ADC12 as they have same bitfield structure.
        ErrCode = BC_SPI_WriteCheck(e_SYS_GBIAS, R2M09_GLOBBIAS_ADC12_U16, GlobbiasMasterclk.val_u32);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        // Same register value for MCLK and ADC34 as they have same bitfield structure.
        ErrCode = BC_SPI_WriteCheck(e_SYS_GBIAS, R2M09_GLOBBIAS_ADC34_U16, GlobbiasMasterclk.val_u32);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        // Same register value for MCLK and ATB as they have same bitfield structure.
        ErrCode = BC_SPI_WriteCheck(e_SYS_GBIAS, R2M09_GLOBBIAS_ATBIP_U16, GlobbiasMasterclk.val_u32);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        // Same register value for MCLK and SNS as they have same bitfield structure.
        ErrCode = BC_SPI_WriteCheck(e_SYS_GBIAS, R2M09_GLOBBIAS_SNS_U16, GlobbiasMasterclk.val_u32);
    }
    return ErrCode;
}

static BC_ERRCODE Helper_GBIAS_SetCtrlPtat(uint8_t PtatBiasCurrent)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    // Same register value for all RXs as they have same bitfield structure.
    R2M09_GlobbiasRx1Union_t GlobbiasRx1;
    GlobbiasRx1.val_u32 = 0u;
    GlobbiasRx1.bits_st.CtrlIrefRx1Ptat = PtatBiasCurrent;
    ErrCode = BC_SPI_WriteCheck(e_SYS_GBIAS, R2M09_GLOBBIAS_RX1_U16, GlobbiasRx1.val_u32);
    if (ErrCode == BC_ERR_NOERROR)
    {
        // Same register value for all RX as they have same bitfield structure.
        ErrCode = BC_SPI_WriteCheck(e_SYS_GBIAS, R2M09_GLOBBIAS_RX2_U16, GlobbiasRx1.val_u32);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        // Same register value for all RX as they have same bitfield structure.
        ErrCode = BC_SPI_WriteCheck(e_SYS_GBIAS, R2M09_GLOBBIAS_RX3_U16, GlobbiasRx1.val_u32);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        // Same register value for all RX as they have same bitfield structure.
        ErrCode = BC_SPI_WriteCheck(e_SYS_GBIAS, R2M09_GLOBBIAS_RX4_U16, GlobbiasRx1.val_u32);
    }
    return ErrCode;
}

static BC_ERRCODE Helper_GBIAS_SetCtrlPtatBg(uint8_t PtatBiasCurrent, uint8_t BgBiasCurrent)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    // Same register value for all TXs and LOI as they have same bitfield structure.
    R2M09_GlobbiasTx1Union_t GlobbiasTx1;
    GlobbiasTx1.val_u32 = 0u;
    GlobbiasTx1.bits_st.CtrlIrefTx1Bg = BgBiasCurrent;
    GlobbiasTx1.bits_st.CtrlIrefTx1Ptat = PtatBiasCurrent;
    ErrCode = BC_SPI_WriteCheck(e_SYS_GBIAS, R2M09_GLOBBIAS_TX1_U16, GlobbiasTx1.val_u32);
    if (ErrCode == BC_ERR_NOERROR)
    {
        // Same register value for all TX as they have same bitfield structure.
        ErrCode = BC_SPI_WriteCheck(e_SYS_GBIAS, R2M09_GLOBBIAS_TX2_U16, GlobbiasTx1.val_u32);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        // Same register value for all TX as they have same bitfield structure.
        ErrCode = BC_SPI_WriteCheck(e_SYS_GBIAS, R2M09_GLOBBIAS_TX3_U16, GlobbiasTx1.val_u32);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        // Same register value for TX and LOI as they have same bitfield structure.
        ErrCode = BC_SPI_WriteCheck(e_SYS_GBIAS, R2M09_GLOBBIAS_LO_INTERFACE_U16, GlobbiasTx1.val_u32);
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_GBIAS_SelectCommonBias(BOOL Enable)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M09_GlobbiasIrefAllIpUnion_t GlobbiasIrefAllIp;
    ErrCode = BC_SPI_Read(e_SYS_GBIAS, R2M09_GLOBBIAS_IREF_ALL_IP_U16, &GlobbiasIrefAllIp.val_u32);
    if (ErrCode == BC_ERR_NOERROR)
    {
        if (Enable == TRUE)
        {
            GlobbiasIrefAllIp.bits_st.CtrlIrefAllIpPtatEnable = (uint8_t)TRUE;
            GlobbiasIrefAllIp.bits_st.CtrlIrefAllIpBgrEnable = (uint8_t)TRUE;
            ErrCode = BC_SPI_WriteCheck(e_SYS_GBIAS, R2M09_GLOBBIAS_IREF_ALL_IP_U16, GlobbiasIrefAllIp.val_u32);
        }
        else
        {

            ErrCode = Helper_GBIAS_SetCtrlBgr(GlobbiasIrefAllIp.bits_st.CtrlIrefAllIpBgr);
            if (ErrCode == BC_ERR_NOERROR)
            {
                ErrCode = Helper_GBIAS_SetCtrlPtat(GlobbiasIrefAllIp.bits_st.CtrlIrefAllIpPtat);
            }
            if (ErrCode == BC_ERR_NOERROR)
            {
                ErrCode = Helper_GBIAS_SetCtrlPtatBg(GlobbiasIrefAllIp.bits_st.CtrlIrefAllIpPtat, GlobbiasIrefAllIp.bits_st.CtrlIrefAllIpBg);
            }
            if (ErrCode == BC_ERR_NOERROR)
            {
                R2M09_GlobbiasChirpgenUnion_t GlobbiasChirpgen;
                ErrCode = BC_SPI_Read(e_SYS_GBIAS, R2M09_GLOBBIAS_CHIRPGEN_U16, &GlobbiasChirpgen.val_u32);
                if (ErrCode == BC_ERR_NOERROR)
                {
                    GlobbiasChirpgen.bits_st.CtrlIrefChirpgenBg = GlobbiasIrefAllIp.bits_st.CtrlIrefAllIpBg;
                    GlobbiasChirpgen.bits_st.CtrlIrefChirpgenBgr = GlobbiasIrefAllIp.bits_st.CtrlIrefAllIpBgr;
                    GlobbiasChirpgen.bits_st.CtrlIrefChirpgenPtat = GlobbiasIrefAllIp.bits_st.CtrlIrefAllIpPtat;
                    ErrCode = BC_SPI_WriteCheck(e_SYS_GBIAS, R2M09_GLOBBIAS_CHIRPGEN_U16, GlobbiasChirpgen.val_u32);
                }
            }
            if (ErrCode == BC_ERR_NOERROR)
            {
                R2M09_GlobbiasSsbmodUnion_t GlobbiasSsbmod;
                ErrCode = BC_SPI_Read(e_SYS_GBIAS, R2M09_GLOBBIAS_SSBMOD_U16, &GlobbiasSsbmod.val_u32);
                if (ErrCode == BC_ERR_NOERROR)
                {
                    GlobbiasSsbmod.bits_st.CtrlIrefSsbmodPtat = 0u;
                    GlobbiasSsbmod.bits_st.CtrlIrefSsbmodBgr = 0u;
                    GlobbiasSsbmod.bits_st.CtrlIrefSsbmodBg = GlobbiasIrefAllIp.bits_st.CtrlIrefAllIpBg;
                    ErrCode = BC_SPI_WriteCheck(e_SYS_GBIAS, R2M09_GLOBBIAS_SSBMOD_U16, GlobbiasSsbmod.val_u32);
                }
            }

            if (ErrCode == BC_ERR_NOERROR)
            {
                GlobbiasIrefAllIp.bits_st.CtrlIrefAllIpPtatEnable = (uint8_t)FALSE;
                GlobbiasIrefAllIp.bits_st.CtrlIrefAllIpBgrEnable = (uint8_t)FALSE;
                ErrCode = BC_SPI_WriteCheck(e_SYS_GBIAS, R2M09_GLOBBIAS_IREF_ALL_IP_U16, GlobbiasIrefAllIp.val_u32);
            }
        }
    }
    return ErrCode;
}
#endif
/* End of File */
