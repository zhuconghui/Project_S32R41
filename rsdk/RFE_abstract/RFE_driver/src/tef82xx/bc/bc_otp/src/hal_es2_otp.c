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
#ifdef BUILD_FOR_VAL
#include "v_es2_otp.h"
#include "v_es2_loi.h"
#include "v_es2_cafc.h"
#include "v_es2_gldo.h"
#else
#include "reg_es2_otp.h"
#include "reg_es2_loi.h"
#include "reg_es2_cafc.h"
#include "reg_es2_gldo.h"
#endif
#include "hal_es2_otp.h"
#include "bc_spi.h"
#include "bc_conf.h"
#include "bc_alg.h"
#include <string.h>

#ifndef HOST_CPU_BIG_ENDIAN
typedef struct
{
    uint32_t TxPpdVgaLevel : 6;
    uint32_t TxPpdPrLevel : 6;
    uint32_t TxPpdLox3Level : 6;
    uint32_t TxPoutRefAnchorPoint : 6;
    uint32_t TxLevelRfMaxSpi : 6;
    uint32_t Reserved0 : 2;
} OTP_TrimTxThreshBits_t;
#else
typedef struct
{
    uint32_t Reserved0 : 2;
    uint32_t TxLevelRfMaxSpi : 6;
    uint32_t TxPoutRefAnchorPoint : 6;
    uint32_t TxPpdLox3Level : 6;
    uint32_t TxPpdPrLevel : 6;
    uint32_t TxPpdVgaLevel : 6;
} OTP_TrimTxThreshBits_t;
#endif
typedef union
{
    OTP_TrimTxThreshBits_t bits_st; /*## attribute bits_st */
    uint32_t val_u32;               /*## attribute val_u32 */
} OTP_TrimTxThreshBitsUnion_t;

// global array to store OTP data from burst read
static uint32_t gReadData[SYS_NUM_MAX_DEVICE][OTP_LUT_SIZE + 1u];

// Barracuda_Calibration_Trimming_Strategy_TO2_v13
#ifdef BUILD_FOR_VAL
uint32_t gDefaultOTPValues[65] = {
#else
static uint32_t gDefaultOTPValues[65] = {
#endif
    0x0u,
    0x0u,
    0x0u,
    0x0u,
    0x0u,
    0x0u,
    0x0u,
    0x0u,
    0x0u,
    0x1c252e3du,
    0x4a545d63u,
    0x1c252e3du,
    0x4a545d63u,
    0x26u,
    0x51525252u,
    0x2fcbf2fcu,
    0x2fau,
    0xc0ffc0ffu,
    0x120c6868u,
    0x2538c513u,
    0x3836241cu,
    0x3836241cu,
    0x3836241cu,
    0x3836241cu,
    0x88885u,
    0x88885u,
    0x88885u,
    0x88885u,
    0x4c4c4cu,
    0x1294a529u,
    0x32d7739du,
    0x2fcb739du,
    0x32d7739du,
    0x38362f2bu,
    0x57cf29e4u,
    0x3000u,
    0x1f000u,
    0x23230010u,
    0xc0704u,
    0x6700u,
    0x443e3cu,
    0x0u,
    0x0u,
    0x0u,
    0x0u,
    0x0u,
    0x1010101u,
    0x1010101u,
    0x1010101u,
    0x304da5u, // kvco_g4_ref_i = 48, kvco_g2_ref_i = 77
    0x1199c065u,
    0x18ce1946u,
    0x49a285cu, // a_g2 = 4, p_g2 = 9866, q_g2 = 92
    0x189a19a1u,
    0x29a6475u, // a_g4 = 2, p_g4 = 9881, q_g4 = 117
    0x185919feu,
    0x43e1300u, // dac_op_10=271; dac_op_01=265
    0x1e019a00u,
    0x28a20u,
    0x33u,
    0x0u,
    0x0u,
    0x0u,
    0x0u,
    0x0u}; // the last data of this bit array is added for enabling validation to use DC calibration data.

// a flag to check if the OTP data is correctly loaded.
static BOOL gOTPDataloaded[SYS_NUM_MAX_DEVICE] = {FALSE, FALSE, FALSE, FALSE};
static void Helper_FlipOTPDataBits(uint32_t num, uint32_t *FlipNum);
static BC_ERRCODE Helper_ES2_GetOTPTableBase(OTP_Table_e OTPTable, OTP_TableDescrip_t *pTableBase);
static void Helper_VtuneHighWarnCorrection(uint32_t *pReadData, uint32_t FTMajVer, uint32_t WTMajVer);
static void Helper_GLDOControlCodeCorrection(uint32_t *pReadData, uint32_t FTMajVer, uint32_t WTMajVer);
static void Helper_GLDOControlCodeCorrExt(uint32_t *pReadData, uint32_t FTMajVer, uint32_t WTMajVer);
static BC_ERRCODE Helper_CheckReadReady(uint32_t *pReadData);
static BC_ERRCODE Helper_OtpCrcValAdj(uint32_t *pReadData, uint32_t WTMajorVersion, uint32_t FTMajorVersion, uint32_t FTMinorVersion, BOOL *pOTPNotFusedWT);
static BC_ERRCODE Helper_ValidateCRC(uint32_t *pReadData, uint32_t FTMajorVersion, uint32_t FTMinorVersion);
static void Helper_ES2_LoiCorrection(uint32_t *pReadData, uint32_t FTMajorVersion, uint32_t FTMinorVersion, uint32_t WTMajorVersion, uint32_t WTMinorVersion);
static void Helper_ES2_AnchorCorrection(uint32_t *pReadData, uint32_t FTMajorVersion, uint32_t FTMinorVersion, uint32_t WTMajorVersion, uint32_t WTMinorVersion);
static void Helper_ES2_MatrixCorrection(uint32_t *pReadData, uint32_t FTMajorVersion, uint32_t FTMinorVersion, uint32_t WTMajorVersion, uint32_t WTMinorVersion);
static void Helper_CopySnsGldoTxTh(OTP_Table_e OTPTable, OTP_TableDescrip_t *pTableBase);
static void Helper_CopyRxThrFil(OTP_Table_e OTPTable, OTP_TableDescrip_t *pTableBase);
static void Helper_CopyTxBias(OTP_Table_e OTPTable, OTP_TableDescrip_t *pTableBase);
static void Helper_CopyTxLoiChirpThresSbCor(OTP_Table_e OTPTable, OTP_TableDescrip_t *pTableBase);
static void Helper_CopySpareTrimTxTs(OTP_Table_e OTPTable, OTP_TableDescrip_t *pTableBase);

const OTP_TableDescrip_t OtpTrimTx2Thresh[OTP_TRIM_TX2_THRESH_COUNT] = {
    {0x7Cu, 24u, 0x3f000000u, e_SYS_TX2, 0x48u, 8u, 0x3f00u},
    {0x7Cu, 18u, 0xfc0000u, e_SYS_TX2, 0x61cu, 0u, 0x3fu},
    {0x7Cu, 12u, 0x3f000u, e_SYS_TX2, 0x60cu, 0u, 0x3fu},
    {0x7Cu, 6u, 0xfc0u, e_SYS_TX2, 0x60cu, 8u, 0x3f00u},
    {0x7Cu, 0u, 0x3fu, e_SYS_TX2, 0x60cu, 16u, 0x3f0000u}};
static const OTP_TableDescrip_t OtpTrimFrGldo[OTP_TRIM_FR_GLDO_COUNT] = {
    {0xA0u, 20u, 0x700000u, e_SYS_GLDO, 0x24u, 4u, 0x70u},
    {0xA0u, 16u, 0x70000u, e_SYS_GLDO, 0x24u, 0u, 0x7u},
    {0xA0u, 8u, 0x7f00u, e_SYS_GLDO, 0x28u, 8u, 0x7f00u},
    {0xA0u, 0u, 0x7fu, e_SYS_GLDO, 0x28u, 0u, 0x7fu}};
const OTP_TableDescrip_t OtpTrimTx1Thresh[OTP_TRIM_TX1_THRESH_COUNT] = {
    {0x78u, 24u, 0x3f000000u, e_SYS_TX1, 0x48u, 8u, 0x3f00u},
    {0x78u, 18u, 0xfc0000u, e_SYS_TX1, 0x61cu, 0u, 0x3fu},
    {0x78u, 12u, 0x3f000u, e_SYS_TX1, 0x60cu, 0u, 0x3fu},
    {0x78u, 6u, 0xfc0u, e_SYS_TX1, 0x60cu, 8u, 0x3f00u},
    {0x78u, 0u, 0x3fu, e_SYS_TX1, 0x60cu, 16u, 0x3f0000u}};
const OTP_TableDescrip_t OtpTrimTxBiasSt3[OTP_TRIM_TX_BIAS_ST3_COUNT] = {
    {0x70u, 16u, 0x1f0000u, e_SYS_TX1, 0x200u, 10u, 0x7c00u},
    {0x70u, 8u, 0x1f00u, e_SYS_TX2, 0x200u, 10u, 0x7c00u},
    {0x70u, 0u, 0x1fu, e_SYS_TX3, 0x200u, 10u, 0x7c00u}};
const OTP_TableDescrip_t OtpTrimTxBiasSt12[OTP_TRIM_TX_BIAS_ST12_COUNT] = {
    {0x74u, 25u, 0x3e000000u, e_SYS_TX1, 0x200u, 5u, 0x3e0u},
    {0x74u, 20u, 0x1f00000u, e_SYS_TX1, 0x200u, 0u, 0x1fu},
    {0x74u, 15u, 0xf8000u, e_SYS_TX2, 0x200u, 5u, 0x3e0u},
    {0x74u, 10u, 0x7c00u, e_SYS_TX2, 0x200u, 0u, 0x1fu},
    {0x74u, 5u, 0x3e0u, e_SYS_TX3, 0x200u, 5u, 0x3e0u},
    {0x74u, 0u, 0x1fu, e_SYS_TX3, 0x200u, 0u, 0x1fu}};
const OTP_TableDescrip_t OtpTrimTx3Thresh[OTP_TRIM_TX3_THRESH_COUNT] = {
    {0x80u, 24u, 0x3f000000u, e_SYS_TX3, 0x48u, 8u, 0x3f00u},
    {0x80u, 18u, 0xfc0000u, e_SYS_TX3, 0x61cu, 0u, 0x3fu},
    {0x80u, 12u, 0x3f000u, e_SYS_TX3, 0x60cu, 0u, 0x3fu},
    {0x80u, 6u, 0xfc0u, e_SYS_TX3, 0x60cu, 8u, 0x3f00u},
    {0x80u, 0u, 0x3fu, e_SYS_TX3, 0x60cu, 16u, 0x3f0000u}};
const OTP_TableDescrip_t OtpTrimLoiThresh[OTP_TRIM_LOI_THRESH_COUNT] = {
    {0x84u, 30u, 0xc0000000u, e_SYS_LOI, 0x1cu, 0u, 0x3u},
    {0x84u, 24u, 0x3f000000u, e_SYS_LOI, 0xcu, 24u, 0x3f000000u},
    {0x84u, 16u, 0x3f0000u, e_SYS_LOI, 0xcu, 16u, 0x3f0000u},
    {0x84u, 8u, 0x3f00u, e_SYS_LOI, 0xcu, 8u, 0x3f00u},
    {0x84u, 0u, 0x3fu, e_SYS_LOI, 0xcu, 0u, 0x3fu}};
static const OTP_TableDescrip_t OtpTrimChirpThresh[OTP_TRIM_CHIRP_THRESH_COUNT] = {
    {0x88u, 28u, 0xf0000000u, e_SYS_CAFC, 0x24cu, 4u, 0xf0u},
    {0x88u, 24u, 0xf000000u, e_SYS_CAFC, 0x24cu, 0u, 0xfu},
    {0x88u, 18u, 0xfc0000u, e_SYS_CAFC, 0x254u, 24u, 0x3f000000u},
    {0x88u, 12u, 0x3f000u, e_SYS_CAFC, 0x254u, 16u, 0x3f0000u},
    {0x88u, 6u, 0xfc0u, e_SYS_CAFC, 0x254u, 8u, 0x3f00u},
    {0x88u, 0u, 0x3fu, e_SYS_CAFC, 0x254u, 0u, 0x3fu}};
const OTP_TableDescrip_t OtpTrimRx1Thresh[OTP_TRIM_RX1_THRESH_COUNT] = {
    {0x50u, 24u, 0x3f000000u, e_SYS_RX1, 0x104u, 24u, 0x3f000000u},
    {0x50u, 16u, 0x3f0000u, e_SYS_RX1, 0x104u, 16u, 0x3f0000u},
    {0x50u, 8u, 0x3f00u, e_SYS_RX1, 0x104u, 8u, 0x3f00u},
    {0x50u, 0u, 0x3fu, e_SYS_RX1, 0x104u, 0u, 0x3fu}};
const OTP_TableDescrip_t OtpTrimSubbandCorrection1g[OTP_TRIM_SUBBAND_CORRECTION_1G_COUNT] = {
    {0x8Cu, 28u, 0x70000000u, e_SYS_CAFC, 0x274u, 28u, 0x70000000u},
    {0x8Cu, 24u, 0x7000000u, e_SYS_CAFC, 0x274u, 24u, 0x7000000u},
    {0x8Cu, 20u, 0xf00000u, e_SYS_CAFC, 0x274u, 20u, 0xf00000u},
    {0x8Cu, 12u, 0x3f000u, e_SYS_CAFC, 0x274u, 12u, 0x3f000u},
    {0x8Cu, 8u, 0xf00u, e_SYS_CAFC, 0x274u, 8u, 0xf00u},
    {0x8Cu, 4u, 0x70u, e_SYS_CAFC, 0x274u, 4u, 0x70u},
    {0x8Cu, 0u, 0x7u, e_SYS_CAFC, 0x274u, 0u, 0x7u}};
const OTP_TableDescrip_t OtpTrimSubbandCorrection2g[OTP_TRIM_SUBBAND_CORRECTION_2G_COUNT] = {
    {0x90u, 28u, 0x70000000u, e_SYS_CAFC, 0x278u, 28u, 0x70000000u},
    {0x90u, 24u, 0x7000000u, e_SYS_CAFC, 0x278u, 24u, 0x7000000u},
    {0x90u, 20u, 0xf00000u, e_SYS_CAFC, 0x278u, 20u, 0xf00000u},
    {0x90u, 12u, 0x3f000u, e_SYS_CAFC, 0x278u, 12u, 0x3f000u},
    {0x90u, 8u, 0xf00u, e_SYS_CAFC, 0x278u, 8u, 0xf00u},
    {0x90u, 4u, 0x70u, e_SYS_CAFC, 0x278u, 4u, 0x70u},
    {0x90u, 0u, 0x7u, e_SYS_CAFC, 0x278u, 0u, 0x7u}};
const OTP_TableDescrip_t OtpTrimSubbandCorrection4g[OTP_TRIM_SUBBAND_CORRECTION_4G_COUNT] = {
    {0x94u, 8u, 0xf00u, e_SYS_CAFC, 0x27cu, 8u, 0xf00u},
    {0x94u, 4u, 0x70u, e_SYS_CAFC, 0x27cu, 4u, 0x70u},
    {0x94u, 0u, 0x7u, e_SYS_CAFC, 0x27cu, 0u, 0x7u}};

static void Helper_CopySpareTrimTxTs(OTP_Table_e OTPTable, OTP_TableDescrip_t *pTableBase)
{
    static const OTP_TableDescrip_t OtpSpareTrim[OTP_SPARE_TRIM_COUNT] = {
        {0x98u, 16u, 0x1f0000u, e_SYS_CAFC, 0x268u, 0u, 0x1fu},
        {0x98u, 8u, 0x1f00u, e_SYS_MCLK, 0x11cu, 0u, 0x1fu},
        {0x98u, 0u, 0x3fu, e_SYS_SSB, 0x4u, 0u, 0x3fu}};
    static const OTP_TableDescrip_t OtpTrimWrPtat[OTP_TRIM_WR_PTAT_COUNT] = {
        {0x9Cu, 14u, 0x4000u, e_SYS_GBIAS, 0x80u, 22u, 0x400000u},
        {0x9Cu, 8u, 0x3f00u, e_SYS_GBIAS, 0x80u, 16u, 0x3f0000u},
        {0x9Cu, 0u, 0x7fu, e_SYS_GBIAS, 0x5cu, 0u, 0x7fu}};
    static const OTP_TableDescrip_t OtpTrimTsThresh[OTP_TRIM_TS_THRESH_COUNT] = {
        {0x38u, 24u, 0x7f000000u, e_SYS_CAFC, 0x258u, 0u, 0x7fu},
        {0x38u, 16u, 0x7f0000u, e_SYS_TX3, 0x54u, 0u, 0x7fu},
        {0x38u, 8u, 0x7f00u, e_SYS_TX2, 0x54u, 0u, 0x7fu},
        {0x38u, 0u, 0x7fu, e_SYS_TX1, 0x54u, 0u, 0x7fu}};
    static const OTP_TableDescrip_t OtpTrimTxTsCoeff[OTP_TRIM_TX_TS_COEFF_COUNT] = {
        {0x3Cu, 20u, 0x3ff00000u, e_SYS_CC, 0x318u, 20u, 0x3ff00000u},
        {0x3Cu, 10u, 0xffc00u, e_SYS_CC, 0x318u, 10u, 0xffc00u},
        {0x3Cu, 0u, 0x3ffu, e_SYS_CC, 0x318u, 0u, 0x3ffu}};
    static const OTP_TableDescrip_t OtpTrimChirpTsCoeff[OTP_TRIM_CHIRP_TS_COEFF_COUNT] = {
        {0x40u, 0u, 0x3ffu, e_SYS_CC, 0x31cu, 0u, 0x3ffu}};

    if (OTPTable == e_OTP_SPARE_TRIM)
    {
        (void)memcpy(pTableBase, OtpSpareTrim, sizeof(OtpSpareTrim));
    }
    if (OTPTable == e_OTP_TRIM_WR_PTAT)
    {
        (void)memcpy(pTableBase, OtpTrimWrPtat, sizeof(OtpTrimWrPtat));
    }
    if (OTPTable == e_OTP_TRIM_TS_THRESH)
    {
        (void)memcpy(pTableBase, OtpTrimTsThresh, sizeof(OtpTrimTsThresh));
    }
    if (OTPTable == e_OTP_TRIM_TX_TS_COEFF)
    {
        (void)memcpy(pTableBase, OtpTrimTxTsCoeff, sizeof(OtpTrimTxTsCoeff));
    }
    if (OTPTable == e_OTP_TRIM_CHIRP_TS_COEFF)
    {
        (void)memcpy(pTableBase, OtpTrimChirpTsCoeff, sizeof(OtpTrimChirpTsCoeff));
    }
}
static void Helper_CopyTxLoiChirpThresSbCor(OTP_Table_e OTPTable, OTP_TableDescrip_t *pTableBase)
{

    if (OTPTable == e_OTP_TRIM_TX1_THRESH)
    {
        (void)memcpy(pTableBase, OtpTrimTx1Thresh, sizeof(OtpTrimTx1Thresh));
    }
    if (OTPTable == e_OTP_TRIM_TX2_THRESH)
    {
        (void)memcpy(pTableBase, OtpTrimTx2Thresh, sizeof(OtpTrimTx2Thresh));
    }
    if (OTPTable == e_OTP_TRIM_TX3_THRESH)
    {
        (void)memcpy(pTableBase, OtpTrimTx3Thresh, sizeof(OtpTrimTx3Thresh));
    }
    if (OTPTable == e_OTP_TRIM_LOI_THRESH)
    {
        (void)memcpy(pTableBase, OtpTrimLoiThresh, sizeof(OtpTrimLoiThresh));
    }
    if (OTPTable == e_OTP_TRIM_CHIRP_THRESH)
    {
        (void)memcpy(pTableBase, OtpTrimChirpThresh, sizeof(OtpTrimChirpThresh));
    }
    if (OTPTable == e_OTP_TRIM_SUBBAND_CORRECTION_1G)
    {
        (void)memcpy(pTableBase, OtpTrimSubbandCorrection1g, sizeof(OtpTrimSubbandCorrection1g));
    }
    if (OTPTable == e_OTP_TRIM_SUBBAND_CORRECTION_2G)
    {
        (void)memcpy(pTableBase, OtpTrimSubbandCorrection2g, sizeof(OtpTrimSubbandCorrection2g));
    }
    if (OTPTable == e_OTP_TRIM_SUBBAND_CORRECTION_4G)
    {
        (void)memcpy(pTableBase, OtpTrimSubbandCorrection4g, sizeof(OtpTrimSubbandCorrection4g));
    }
}

static void Helper_CopyRxThrFil(OTP_Table_e OTPTable, OTP_TableDescrip_t *pTableBase)
{
    static const OTP_TableDescrip_t OtpTrimRx4Thresh[OTP_TRIM_RX4_THRESH_COUNT] = {
        {0x5Cu, 24u, 0x3f000000u, e_SYS_RX4, 0x104u, 24u, 0x3f000000u},
        {0x5Cu, 16u, 0x3f0000u, e_SYS_RX4, 0x104u, 16u, 0x3f0000u},
        {0x5Cu, 8u, 0x3f00u, e_SYS_RX4, 0x104u, 8u, 0x3f00u},
        {0x5Cu, 0u, 0x3fu, e_SYS_RX4, 0x104u, 0u, 0x3fu}};
    static const OTP_TableDescrip_t OtpTrimRx1Filter[OTP_TRIM_RX1_FILTER_COUNT] = {
        {0x60u, 20u, 0xf00000u, e_SYS_RX1, 0x10cu, 20u, 0xf00000u},
        {0x60u, 16u, 0xf0000u, e_SYS_RX1, 0x10cu, 16u, 0xf0000u},
        {0x60u, 12u, 0xf000u, e_SYS_RX1, 0x10cu, 12u, 0xf000u},
        {0x60u, 8u, 0xf00u, e_SYS_RX1, 0x10cu, 8u, 0xf00u},
        {0x60u, 4u, 0xf0u, e_SYS_RX1, 0x10cu, 4u, 0xf0u},
        {0x60u, 0u, 0xfu, e_SYS_RX1, 0x10cu, 0u, 0xfu}};
    static const OTP_TableDescrip_t OtpTrimRx2Filter[OTP_TRIM_RX2_FILTER_COUNT] = {
        {0x64u, 20u, 0xf00000u, e_SYS_RX2, 0x10cu, 20u, 0xf00000u},
        {0x64u, 16u, 0xf0000u, e_SYS_RX2, 0x10cu, 16u, 0xf0000u},
        {0x64u, 12u, 0xf000u, e_SYS_RX2, 0x10cu, 12u, 0xf000u},
        {0x64u, 8u, 0xf00u, e_SYS_RX2, 0x10cu, 8u, 0xf00u},
        {0x64u, 4u, 0xf0u, e_SYS_RX2, 0x10cu, 4u, 0xf0u},
        {0x64u, 0u, 0xfu, e_SYS_RX2, 0x10cu, 0u, 0xfu}};
    static const OTP_TableDescrip_t OtpTrimRx3Filter[OTP_TRIM_RX3_FILTER_COUNT] = {
        {0x68u, 20u, 0xf00000u, e_SYS_RX3, 0x10cu, 20u, 0xf00000u},
        {0x68u, 16u, 0xf0000u, e_SYS_RX3, 0x10cu, 16u, 0xf0000u},
        {0x68u, 12u, 0xf000u, e_SYS_RX3, 0x10cu, 12u, 0xf000u},
        {0x68u, 8u, 0xf00u, e_SYS_RX3, 0x10cu, 8u, 0xf00u},
        {0x68u, 4u, 0xf0u, e_SYS_RX3, 0x10cu, 4u, 0xf0u},
        {0x68u, 0u, 0xfu, e_SYS_RX3, 0x10cu, 0u, 0xfu}};
    static const OTP_TableDescrip_t OtpTrimRx4Filter[OTP_TRIM_RX4_FILTER_COUNT] = {
        {0x6Cu, 20u, 0xf00000u, e_SYS_RX4, 0x10cu, 20u, 0xf00000u},
        {0x6Cu, 16u, 0xf0000u, e_SYS_RX4, 0x10cu, 16u, 0xf0000u},
        {0x6Cu, 12u, 0xf000u, e_SYS_RX4, 0x10cu, 12u, 0xf000u},
        {0x6Cu, 8u, 0xf00u, e_SYS_RX4, 0x10cu, 8u, 0xf00u},
        {0x6Cu, 4u, 0xf0u, e_SYS_RX4, 0x10cu, 4u, 0xf0u},
        {0x6Cu, 0u, 0xfu, e_SYS_RX4, 0x10cu, 0u, 0xfu}};

    if (OTPTable == e_OTP_TRIM_RX4_THRESH)
    {
        (void)memcpy(pTableBase, OtpTrimRx4Thresh, sizeof(OtpTrimRx4Thresh));
    }
    if (OTPTable == e_OTP_TRIM_RX1_FILTER)
    {
        (void)memcpy(pTableBase, OtpTrimRx1Filter, sizeof(OtpTrimRx1Filter));
    }
    if (OTPTable == e_OTP_TRIM_RX2_FILTER)
    {
        (void)memcpy(pTableBase, OtpTrimRx2Filter, sizeof(OtpTrimRx2Filter));
    }
    if (OTPTable == e_OTP_TRIM_RX3_FILTER)
    {
        (void)memcpy(pTableBase, OtpTrimRx3Filter, sizeof(OtpTrimRx3Filter));
    }
    if (OTPTable == e_OTP_TRIM_RX4_FILTER)
    {
        (void)memcpy(pTableBase, OtpTrimRx4Filter, sizeof(OtpTrimRx4Filter));
    }
}
static void Helper_CopyTxBias(OTP_Table_e OTPTable, OTP_TableDescrip_t *pTableBase)
{
    if ((OTPTable == e_OTP_TRIM_TX1_BIAS_ST3) || (OTPTable == e_OTP_TRIM_TX2_BIAS_ST3) || (OTPTable == e_OTP_TRIM_TX3_BIAS_ST3))
    {
        (void)memcpy(pTableBase, OtpTrimTxBiasSt3, sizeof(OtpTrimTxBiasSt3));
    }
    if ((OTPTable == e_OTP_TRIM_TX1_BIAS_ST12) || (OTPTable == e_OTP_TRIM_TX2_BIAS_ST12) || (OTPTable == e_OTP_TRIM_TX3_BIAS_ST12))
    {
        (void)memcpy(pTableBase, OtpTrimTxBiasSt12, sizeof(OtpTrimTxBiasSt12));
    }
}

static void Helper_CopySnsGldoTxTh(OTP_Table_e OTPTable, OTP_TableDescrip_t *pTableBase)
{
    static const OTP_TableDescrip_t OtpTrimSns[OTP_TRIM_SNS_COUNT] = {
        {0x44u, 30u, 0xc0000000u, e_SYS_GLDO, 0x2cu, 0u, 0x3u},
        {0x44u, 24u, 0x3f000000u, e_SYS_GLDO, 0x38u, 0u, 0x3fu},
        {0x44u, 22u, 0xc00000u, e_SYS_GLDO, 0x2cu, 4u, 0x30u},
        {0x44u, 16u, 0x3f0000u, e_SYS_GLDO, 0x3cu, 0u, 0x3fu},
        {0x44u, 14u, 0xc000u, e_SYS_GLDO, 0x2cu, 8u, 0x300u},
        {0x44u, 8u, 0x3f00u, e_SYS_GLDO, 0x30u, 0u, 0x3fu},
        {0x44u, 6u, 0xc0u, e_SYS_GLDO, 0x2cu, 12u, 0x3000u},
        {0x44u, 0u, 0x3fu, e_SYS_GLDO, 0x34u, 0u, 0x3fu}};
    static const OTP_TableDescrip_t OtpTrimGbias[OTP_TRIM_GBIAS_COUNT] = {
        {0x48u, 24u, 0x1f000000u, e_SYS_MCLK, 0xcu, 8u, 0x1f00u},
        {0x48u, 24u, 0x1f000000u, e_SYS_MCLK, 0xcu, 0u, 0x1fu},
        {0x48u, 24u, 0x1f000000u, e_SYS_CAFC, 0x264u, 0u, 0x1fu},
        {0x48u, 16u, 0x1f0000u, e_SYS_GBIAS, 0x48u, 0u, 0x1fu},
        {0x48u, 16u, 0x1f0000u, e_SYS_MCLK, 0x0u, 8u, 0x1f00u},
        {0x48u, 16u, 0x1f0000u, e_SYS_MCLK, 0x0u, 0u, 0x1fu},
        {0x48u, 14u, 0x4000u, e_SYS_GBIAS, 0x80u, 14u, 0x4000u},
        {0x48u, 8u, 0x3f00u, e_SYS_GBIAS, 0x80u, 8u, 0x3f00u},
        {0x48u, 6u, 0x40u, e_SYS_GBIAS, 0x80u, 6u, 0x40u},
        {0x48u, 0u, 0x3fu, e_SYS_GBIAS, 0x80u, 0u, 0x3fu}};
    static const OTP_TableDescrip_t OtpTrimLocalLdo[OTP_TRIM_LOCAL_LDO_COUNT] = {
        {0x4Cu, 24u, 0x3f000000u, e_SYS_LVDS, 0x108u, 0u, 0x3fu},
        {0x4Cu, 18u, 0x7c0000u, e_SYS_ATB, 0xcu, 0u, 0x1fu},
        {0x4Cu, 18u, 0x7c0000u, e_SYS_CAFC, 0x8u, 0u, 0x1fu},
        {0x4Cu, 18u, 0x7c0000u, e_SYS_CAFC, 0x10u, 0u, 0x1fu},
        {0x4Cu, 12u, 0x1f000u, e_SYS_CC, 0x4u, 24u, 0x1f000000u},
        {0x4Cu, 12u, 0x1f000u, e_SYS_CC, 0x4u, 8u, 0x1f00u},
        {0x4Cu, 12u, 0x1f000u, e_SYS_CC, 0x4u, 0u, 0x1fu},
        {0x4Cu, 12u, 0x1f000u, e_SYS_MCLK, 0x8u, 0u, 0x1fu},
        {0x4Cu, 6u, 0x7c0u, e_SYS_CC, 0x4u, 16u, 0x1f0000u},
        {0x4Cu, 0u, 0x1fu, e_SYS_CAFC, 0xcu, 0u, 0x1fu},
        {0x4Cu, 0u, 0x1fu, e_SYS_MCLK, 0x4u, 24u, 0x1f000000u},
        {0x4Cu, 0u, 0x1fu, e_SYS_MCLK, 0x4u, 16u, 0x1f0000u},
        {0x4Cu, 0u, 0x1fu, e_SYS_MCLK, 0x4u, 8u, 0x1f00u},
        {0x4Cu, 0u, 0x1fu, e_SYS_MCLK, 0x4u, 0u, 0x1fu}};
    static const OTP_TableDescrip_t OtpTrimRx2Thresh[OTP_TRIM_RX2_THRESH_COUNT] = {
        {0x54u, 24u, 0x3f000000u, e_SYS_RX2, 0x104u, 24u, 0x3f000000u},
        {0x54u, 16u, 0x3f0000u, e_SYS_RX2, 0x104u, 16u, 0x3f0000u},
        {0x54u, 8u, 0x3f00u, e_SYS_RX2, 0x104u, 8u, 0x3f00u},
        {0x54u, 0u, 0x3fu, e_SYS_RX2, 0x104u, 0u, 0x3fu}};
    static const OTP_TableDescrip_t OtpTrimRx3Thresh[OTP_TRIM_RX3_THRESH_COUNT] = {
        {0x58u, 24u, 0x3f000000u, e_SYS_RX3, 0x104u, 24u, 0x3f000000u},
        {0x58u, 16u, 0x3f0000u, e_SYS_RX3, 0x104u, 16u, 0x3f0000u},
        {0x58u, 8u, 0x3f00u, e_SYS_RX3, 0x104u, 8u, 0x3f00u},
        {0x58u, 0u, 0x3fu, e_SYS_RX3, 0x104u, 0u, 0x3fu}};

    if (OTPTable == e_OTP_TRIM_FR_GLDO)
    {
        (void)memcpy(pTableBase, OtpTrimFrGldo, sizeof(OtpTrimFrGldo));
    }
    if (OTPTable == e_OTP_TRIM_SNS)
    {
        (void)memcpy(pTableBase, OtpTrimSns, sizeof(OtpTrimSns));
    }
    if (OTPTable == e_OTP_TRIM_GBIAS)
    {
        (void)memcpy(pTableBase, OtpTrimGbias, sizeof(OtpTrimGbias));
    }
    if (OTPTable == e_OTP_TRIM_LOCAL_LDO)
    {
        (void)memcpy(pTableBase, OtpTrimLocalLdo, sizeof(OtpTrimLocalLdo));
    }
    if (OTPTable == e_OTP_TRIM_RX1_THRESH)
    {
        (void)memcpy(pTableBase, OtpTrimRx1Thresh, sizeof(OtpTrimRx1Thresh));
    }
    if (OTPTable == e_OTP_TRIM_RX2_THRESH)
    {
        (void)memcpy(pTableBase, OtpTrimRx2Thresh, sizeof(OtpTrimRx2Thresh));
    }
    if (OTPTable == e_OTP_TRIM_RX3_THRESH)
    {
        (void)memcpy(pTableBase, OtpTrimRx3Thresh, sizeof(OtpTrimRx3Thresh));
    }
}

static void Helper_ES2_MatrixCorrection(uint32_t *pReadData, uint32_t FTMajorVersion, uint32_t FTMinorVersion, uint32_t WTMajorVersion, uint32_t WTMinorVersion)
{
    if (((FTMajorVersion == OTP_TP_FT_MINI_MATRIX_MAJOR_VERSION) && (FTMinorVersion == OTP_TP_FT_MINI_MATRIX_MINOR_VERSION)) &&
        ((WTMajorVersion == OTP_TP_WT_MINI_MATRIX_MAJOR_VERSION) && (WTMinorVersion <= OTP_TP_WT_MINI_MATRIX_MINOR_VERSION)))
    {
        OTP_TrimTxThreshBitsUnion_t TrimTxThreshold;
        uint8_t AnchorPoint = 0u;
        uint8_t MaxAnchorPoint = 63u;
        uint8_t MaxLevel = 0u;
        TrimTxThreshold.val_u32 = pReadData[OTP_TRIM_TX1_THRESH_INDEX];
        MaxLevel = (uint8_t)(TrimTxThreshold.bits_st.TxLevelRfMaxSpi + 1u);
        TrimTxThreshold.bits_st.TxLevelRfMaxSpi = (MaxLevel > MaxAnchorPoint) ? MaxAnchorPoint : MaxLevel;
        AnchorPoint = (uint8_t)(TrimTxThreshold.bits_st.TxPoutRefAnchorPoint + 3u);
        TrimTxThreshold.bits_st.TxPoutRefAnchorPoint = (AnchorPoint > MaxAnchorPoint) ? MaxAnchorPoint : AnchorPoint;
        pReadData[OTP_TRIM_TX1_THRESH_INDEX] = TrimTxThreshold.val_u32;

        TrimTxThreshold.val_u32 = pReadData[OTP_TRIM_TX2_THRESH_INDEX];
        TrimTxThreshold.bits_st.TxLevelRfMaxSpi = (uint8_t)(TrimTxThreshold.bits_st.TxLevelRfMaxSpi - 2u);
        pReadData[OTP_TRIM_TX2_THRESH_INDEX] = TrimTxThreshold.val_u32;

        TrimTxThreshold.val_u32 = pReadData[OTP_TRIM_TX3_THRESH_INDEX];
        MaxLevel = (uint8_t)(TrimTxThreshold.bits_st.TxLevelRfMaxSpi + 1u);
        TrimTxThreshold.bits_st.TxLevelRfMaxSpi = (MaxLevel > MaxAnchorPoint) ? MaxAnchorPoint : MaxLevel;
        AnchorPoint = (uint8_t)(TrimTxThreshold.bits_st.TxPoutRefAnchorPoint + 3u);
        TrimTxThreshold.bits_st.TxPoutRefAnchorPoint = (AnchorPoint > MaxAnchorPoint) ? MaxAnchorPoint : AnchorPoint;
        pReadData[OTP_TRIM_TX3_THRESH_INDEX] = TrimTxThreshold.val_u32;
    }
}
static void Helper_ES2_AnchorCorrection(uint32_t *pReadData, uint32_t FTMajorVersion, uint32_t FTMinorVersion, uint32_t WTMajorVersion, uint32_t WTMinorVersion)
{

    /*
    This fix is needed for Es2, and only required for OTP enabled samples.
                                                                        Tx1 Max    Tx2 Max   Tx3 Max  Tx1 Anchor  Tx2 Anchor    Tx3 Anchor
    (WT <= 2.0  && FT <= 2.0)                                TP 2.0      -2         -5        -2        +2          -2             +2
    (WT => 2.0 & WT <= 2.11 ) && (FT ==2.11) TP 2.11 (mini matrix)        +1        -2        +1        +3           0             +3
    */

    if (((FTMajorVersion < OTP_TP_FT_TX_ANCHOR_MAJOR_VERSION) || ((FTMajorVersion == OTP_TP_FT_TX_ANCHOR_MAJOR_VERSION) && (FTMinorVersion == OTP_TP_FT_TX_ANCHOR_MINOR_VERSION))) &&
        ((WTMajorVersion < OTP_TP_WT_TX_ANCHOR_MAJOR_VERSION) || ((WTMajorVersion == OTP_TP_WT_TX_ANCHOR_MAJOR_VERSION) && (WTMinorVersion == OTP_TP_WT_TX_ANCHOR_MINOR_VERSION))))
    {
        OTP_TrimTxThreshBitsUnion_t TrimTxThreshold;
        uint8_t AnchorPoint = 0u;
        uint8_t MaxAnchorPoint = 63u;
        TrimTxThreshold.val_u32 = pReadData[OTP_TRIM_TX1_THRESH_INDEX];
        TrimTxThreshold.bits_st.TxLevelRfMaxSpi = (uint8_t)(TrimTxThreshold.bits_st.TxLevelRfMaxSpi - 2u);
        AnchorPoint = (uint8_t)(TrimTxThreshold.bits_st.TxPoutRefAnchorPoint + 2u);
        TrimTxThreshold.bits_st.TxPoutRefAnchorPoint = (AnchorPoint > MaxAnchorPoint) ? MaxAnchorPoint : AnchorPoint;
        pReadData[OTP_TRIM_TX1_THRESH_INDEX] = TrimTxThreshold.val_u32;

        TrimTxThreshold.val_u32 = pReadData[OTP_TRIM_TX2_THRESH_INDEX];
        TrimTxThreshold.bits_st.TxLevelRfMaxSpi = (uint8_t)(TrimTxThreshold.bits_st.TxLevelRfMaxSpi - 5u);
        TrimTxThreshold.bits_st.TxPoutRefAnchorPoint = (uint8_t)(TrimTxThreshold.bits_st.TxPoutRefAnchorPoint - 2u);
        pReadData[OTP_TRIM_TX2_THRESH_INDEX] = TrimTxThreshold.val_u32;

        TrimTxThreshold.val_u32 = pReadData[OTP_TRIM_TX3_THRESH_INDEX];
        TrimTxThreshold.bits_st.TxLevelRfMaxSpi = (uint8_t)(TrimTxThreshold.bits_st.TxLevelRfMaxSpi - 2u);
        AnchorPoint = (uint8_t)(TrimTxThreshold.bits_st.TxPoutRefAnchorPoint + 2u);
        TrimTxThreshold.bits_st.TxPoutRefAnchorPoint = (AnchorPoint > MaxAnchorPoint) ? MaxAnchorPoint : AnchorPoint;
        pReadData[OTP_TRIM_TX3_THRESH_INDEX] = TrimTxThreshold.val_u32;
    }
}

static void Helper_ES2_LoiCorrection(uint32_t *pReadData, uint32_t FTMajorVersion, uint32_t FTMinorVersion, uint32_t WTMajorVersion, uint32_t WTMinorVersion)
{
    /*
    This fix is needed for Es2, and only required for OTP enabled samples.
    Instead of taking the value from OTP, we adjust as follows, till these values fixed in test program:
    If WT TP is less than 2.50 and FT TP is less than 2.50
    LevelLoiLowSpi equals to LevelLoiLowSpi - 3
    LevelLoiHighSpi equals to LevelLoiHighSpi - 3
    LevelLoiMaxSpi equals to LevelLoiMaxSpi - 3
    LevelLoiMinSpi equals to LevelLoiMinSpi - 3
    This should give us enough margin to have it working for all temperatures and frequency ranges without warnings.
               */
    if (((FTMajorVersion < OTP_TP_FT_LOI_MAJOR_VERSION) || ((FTMajorVersion == OTP_TP_FT_LOI_MAJOR_VERSION) && (FTMinorVersion < OTP_TP_FT_LOI_MINOR_VERSION))) &&
        ((WTMajorVersion < OTP_TP_WT_LOI_MAJOR_VERSION) || ((WTMajorVersion == OTP_TP_WT_LOI_MAJOR_VERSION) && (WTMinorVersion < OTP_TP_WT_LOI_MINOR_VERSION))))
    {
        R2M0A_FuncsafeMonLevelSettingsUnion_t FuncsafeMonLevelSettings;
        uint8_t ReduceFactor = 3u;
        FuncsafeMonLevelSettings.val_u32 = pReadData[OTP_TRIM_LOI_THRESH_INDEX];
        FuncsafeMonLevelSettings.bits_st.LevelLoiHighSpi = (uint8_t)(FuncsafeMonLevelSettings.bits_st.LevelLoiHighSpi - ReduceFactor);
        FuncsafeMonLevelSettings.bits_st.LevelLoiLowSpi = (uint8_t)(FuncsafeMonLevelSettings.bits_st.LevelLoiLowSpi - ReduceFactor);
        FuncsafeMonLevelSettings.bits_st.LevelLoiMaxSpi = (uint8_t)(FuncsafeMonLevelSettings.bits_st.LevelLoiMaxSpi - ReduceFactor);
        FuncsafeMonLevelSettings.bits_st.LevelLoiMinSpi = (uint8_t)(FuncsafeMonLevelSettings.bits_st.LevelLoiMinSpi - ReduceFactor);
        pReadData[OTP_TRIM_LOI_THRESH_INDEX] = FuncsafeMonLevelSettings.val_u32;
    }
}
static BC_ERRCODE Helper_ValidateCRC(uint32_t *pReadData, uint32_t FTMajorVersion, uint32_t FTMinorVersion)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    BOOL CRCEnabled = FALSE;
    uint32_t StoreIndex60 = 0u;
    uint32_t CalculatedCRC = 0u;

    // OTP CRC is stored in index 63. In order to calculate the magic check, OTP CRC is temporarily moved to index 58, so that we can have a coninuous array from index 9 to index 59 to calculate magic check
    // CRC is enabled in FT >= 2.10
    if (((FTMajorVersion > OTP_TP_FT_CRC_EN_MAJOR_VERSION) || ((FTMajorVersion == OTP_TP_FT_CRC_EN_MAJOR_VERSION) && (FTMinorVersion >= OTP_TP_FT_CRC_EN_MINOR_VERSION))) &&
        (gDefaultOTPValues[64] != 0xa5u))
    {
        CRCEnabled = TRUE;
    }
    else
    {
        CRCEnabled = FALSE;
    }

    if (CRCEnabled == TRUE)
    {
        // move OTP crc to index 58
        StoreIndex60 = pReadData[OTP_CRC_LAST_INDEX];
        pReadData[OTP_CRC_LAST_INDEX] = pReadData[OTP_CRC_INDEX];
        ErrCode = BC_ALG_CalculateCRC32((uint8_t *)&pReadData[OTP_CRCDATA_START_INDEX], OTP_CRC_COMPUTE_SIZE * ((uint8_t)sizeof(uint32_t)), 0U, &CalculatedCRC);
        // revert index 60 to its previous data
        pReadData[OTP_CRC_LAST_INDEX] = StoreIndex60;
        if ((CalculatedCRC != OTP_MAGICCHECK) && (ErrCode == BC_ERR_NOERROR))
        {
            ErrCode = BC_ERR_OTP_CRCCHECKFAILURE;
        }
    }

    return ErrCode;
}
static BC_ERRCODE Helper_OtpCrcValAdj(uint32_t *pReadData, uint32_t WTMajorVersion, uint32_t FTMajorVersion, uint32_t FTMinorVersion, BOOL *pOTPNotFusedWT)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    uint8_t loop0 = 0u;

    if ((WTMajorVersion == 0u) && (FTMajorVersion == 0u))
    {
        *pOTPNotFusedWT = TRUE;
    }
    /* Validate CRC */
    ErrCode = Helper_ValidateCRC(pReadData, FTMajorVersion, FTMinorVersion);

    if (ErrCode == BC_ERR_NOERROR)
    {
        // check if this Sample has a valid OTP. if any of OTP_trim_valid, OTP_Cal_valid, OTP_CALIBRATED_valid is not equal to 1, this sample is not OTP enabled.
        if ((*pOTPNotFusedWT == TRUE) || (gDefaultOTPValues[64] == 0xa5u)) // if gDefaultOTPValues[64] is 0xa5, use validation dc calibration data
        {
            // this sample does not have a valid OTP, the default OTP values should be used
            for (loop0 = 0u; loop0 < 64u; loop0++)
            {
                pReadData[loop0] = gDefaultOTPValues[loop0];
            }
        }
    }
    return ErrCode;
}
static BC_ERRCODE Helper_CheckReadReady(uint32_t *pReadData)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    uint8_t loop0 = 0u;
    uint32_t FlipOTPData;
    R2M17_OtpStatusUnion_t OTPStatus;

    ErrCode = BC_SPI_Read(e_SYS_OTP, R2M17_OTP_STATUS_U16, &OTPStatus.val_u32);
    if (ErrCode == BC_ERR_NOERROR)
    {
        if (((OTPStatus.bits_st.ReadyForRead == 0u) || (OTPStatus.bits_st.Prreaddone == 0u)))
        {
            ErrCode = BC_ERR_OTP_FAILTOREAD;
        }
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_SPI_BurstRead(e_SYS_OTP, R2M17_OTP_DATA_RD_REG_U16, FALSE, (OTP_LUT_SIZE + 1u), pReadData);
        if (ErrCode == BC_ERR_NOERROR)
        {
            for (loop0 = 0u; loop0 < 64u; loop0++)
            {
                // throw away the first garbage data
                pReadData[loop0] = pReadData[loop0 + 1u];
                // revert the order of bits
                (void)Helper_FlipOTPDataBits(pReadData[loop0], &FlipOTPData);
                pReadData[loop0] = FlipOTPData;
            }
        }
    }
    return ErrCode;
}
static void Helper_VtuneHighWarnCorrection(uint32_t *pReadData, uint32_t FTMajVer, uint32_t WTMajVer)
{
    // This correctionis need for Test Program  2.0,2.5,3.0(WT2.5,FP3.0)
    if ((FTMajVer < OTP_TP_FT_VTUNE_MATRIX_MAJOR_VERSION) || (WTMajVer < OTP_TP_WT_VTUNE_MATRIX_MAJOR_VERSION))
    {
        uint32_t VtuneRegVal, VtuneHigh;
        VtuneRegVal = pReadData[OTP_TRIM_CHIRP_THRESH_INDEX];
        VtuneHigh = (VtuneRegVal & OtpTrimChirpThresh[0].SrcMsk) >> OtpTrimChirpThresh[0].SrcPos;
        if (VtuneHigh <= VTUNE_VCO_HIGH_MAX_MINUS_2)
        {
            VtuneHigh += 2u;
            pReadData[OTP_TRIM_CHIRP_THRESH_INDEX] &= ~(OtpTrimChirpThresh[0].SrcMsk);
            pReadData[OTP_TRIM_CHIRP_THRESH_INDEX] |= ((VtuneHigh << OtpTrimChirpThresh[0].SrcPos) & OtpTrimChirpThresh[0].SrcMsk);
        }
    }
}
static void Helper_GLDOControlCodeCorrExt(uint32_t *pReadData, uint32_t FTMajVer, uint32_t WTMajVer)
{
    if ((FTMajVer >= OTP_TP_FT_GLDO_MAJOR_VERSION) && (WTMajVer == OTP_TP_WT_GLDO_MAJOR_VERSION_EXT))
    {
        uint32_t GldoConfig2ExtRegVal, Gldo1v8SetDc, Gldo1v1SetDc;
        GldoConfig2ExtRegVal = pReadData[OTP_TRIM_FR_GLDO_INDEX];
        Gldo1v8SetDc = (GldoConfig2ExtRegVal & OtpTrimFrGldo[2u].SrcMsk) >> OtpTrimFrGldo[2u].SrcPos;
        Gldo1v1SetDc = (GldoConfig2ExtRegVal & OtpTrimFrGldo[3u].SrcMsk) >> OtpTrimFrGldo[3u].SrcPos;
        if (Gldo1v8SetDc != 0u)
        {
            Gldo1v8SetDc -= (uint8_t)1u;
        }
        /* If the control code crosses 63-64 transition because of the correction, subtract 1 code extra */
        if (Gldo1v8SetDc == 63u)
        {
            Gldo1v8SetDc = 62u;
        }
        if (Gldo1v1SetDc <= (GLDO_1V1_SET_DC_MAX_MINUS_2 + 1u))
        {
            Gldo1v1SetDc += (uint8_t)1u;
            /* If the control code crosses 63-64 transition because of the correction, add 1 code extra */
            if (Gldo1v1SetDc == 64u)
            {
                Gldo1v1SetDc = 65u;
            }
        }
        pReadData[OTP_TRIM_FR_GLDO_INDEX] &= ~(OtpTrimFrGldo[2u].SrcMsk);
        pReadData[OTP_TRIM_FR_GLDO_INDEX] &= ~(OtpTrimFrGldo[3u].SrcMsk);
        pReadData[OTP_TRIM_FR_GLDO_INDEX] |= ((Gldo1v8SetDc << OtpTrimFrGldo[2u].SrcPos) & OtpTrimFrGldo[2u].SrcMsk);
        pReadData[OTP_TRIM_FR_GLDO_INDEX] |= ((Gldo1v1SetDc << OtpTrimFrGldo[3u].SrcPos) & OtpTrimFrGldo[3u].SrcMsk);
    }
}
static void Helper_GLDOControlCodeCorrection(uint32_t *pReadData, uint32_t FTMajVer, uint32_t WTMajVer)
{
    if ((FTMajVer == OTP_TP_FT_GLDO_MAJOR_VERSION) && (WTMajVer == OTP_TP_WT_GLDO_MAJOR_VERSION))
    {
        uint32_t GldoConfig2ExtRegVal, Gldo1v8SetDc, Gldo1v1SetDc;
        GldoConfig2ExtRegVal = pReadData[OTP_TRIM_FR_GLDO_INDEX];
        Gldo1v8SetDc = (GldoConfig2ExtRegVal & OtpTrimFrGldo[2u].SrcMsk) >> OtpTrimFrGldo[2u].SrcPos;
        Gldo1v1SetDc = (GldoConfig2ExtRegVal & OtpTrimFrGldo[3u].SrcMsk) >> OtpTrimFrGldo[3u].SrcPos;
        Gldo1v8SetDc -= (uint8_t)1u;
        /* If the control code crosses 63-64 transition because of the correction, subtract 1 code extra */
        if (Gldo1v8SetDc == 63u)
        {
            Gldo1v8SetDc = 62u;
        }
        if (Gldo1v1SetDc <= GLDO_1V1_SET_DC_MAX_MINUS_2)
        {
            Gldo1v1SetDc += (uint8_t)2u;
            /* If we start with code 63 or 62 and have to add 2, we pass the 63-64 transition and therefore have to add 1 extra */
            if ((Gldo1v1SetDc == 65u) || (Gldo1v1SetDc == 64u))
            {
                Gldo1v1SetDc += 1u;
            }
        }
        pReadData[OTP_TRIM_FR_GLDO_INDEX] &= ~(OtpTrimFrGldo[2u].SrcMsk);
        pReadData[OTP_TRIM_FR_GLDO_INDEX] &= ~(OtpTrimFrGldo[3u].SrcMsk);
        pReadData[OTP_TRIM_FR_GLDO_INDEX] |= ((Gldo1v8SetDc << OtpTrimFrGldo[2u].SrcPos) & OtpTrimFrGldo[2u].SrcMsk);
        pReadData[OTP_TRIM_FR_GLDO_INDEX] |= ((Gldo1v1SetDc << OtpTrimFrGldo[3u].SrcPos) & OtpTrimFrGldo[3u].SrcMsk);
    }
    Helper_GLDOControlCodeCorrExt(pReadData, FTMajVer, WTMajVer);
}

static void Helper_FlipOTPDataBits(uint32_t num, uint32_t *FlipNum)
{
    uint32_t TempNum = 0u;
    TempNum = num;
    uint32_t count = ((uint32_t)sizeof(TempNum) * 8u) - 1u;
    uint32_t reverse_num = TempNum; // nrev will store the bit-reversed pattern

    TempNum >>= 1u;
    while (TempNum > 0u)
    {
        reverse_num <<= 1u;
        reverse_num |= TempNum & 1u;
        TempNum >>= 1u;
        count--;
    }
    reverse_num <<= count;
    *FlipNum = reverse_num;
}

BC_ERRCODE HAL_ES2_OTP_LoadOTP(void)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    uint32_t *pReadData = gReadData[gTargetDevice];
    gOTPDataloaded[gTargetDevice] = FALSE;
    uint32_t WTMinorVersion = 0u;
    uint32_t WTMajorVersion = 0u;
    uint32_t FTMajorVersion = 0u;
    uint32_t FTMinorVersion = 0u;
    uint32_t TPVersionWT;
    uint32_t TPVersionFT;
    BOOL OTPNotFusedWT = FALSE;

    ErrCode = Helper_CheckReadReady(pReadData);
    if (ErrCode == BC_ERR_NOERROR)
    {
        TPVersionWT = pReadData[OTP_TP_ID_WT_INDEX];
        TPVersionFT = pReadData[OTP_TP_ID_FT12_INDEX];
        WTMajorVersion = ((TPVersionWT & OTP_ID_WT_MAJOR_MASK) >> OTP_ID_WT_MAJOR_POS);
        WTMinorVersion = (TPVersionWT & OTP_ID_WT_MINOR_MASK);
        FTMajorVersion = ((TPVersionFT & OTP_ID_FT_MAJOR_MASK) >> OTP_ID_FT_MAJOR_POS);
        FTMinorVersion = (TPVersionFT & OTP_ID_FT_MINOR_MASK);

        ErrCode = Helper_OtpCrcValAdj(pReadData, WTMajorVersion, FTMajorVersion, FTMinorVersion, &OTPNotFusedWT);

        if ((ErrCode == BC_ERR_NOERROR) && (OTPNotFusedWT != TRUE) && (gDefaultOTPValues[64] != 0xa5u))
        {
            /*
            This fix is needed for Es2, and only required for OTP enabled samples.
            Instead of taking the value from OTP, we adjust */
            Helper_ES2_LoiCorrection(pReadData, FTMajorVersion, FTMinorVersion, WTMajorVersion, WTMinorVersion);

            /*
            This fix is needed for Es2, and only required for OTP enabled samples.
                                                                                Tx1 Max    Tx2 Max   Tx3 Max  Tx1 Anchor  Tx2 Anchor    Tx3 Anchor
            (WT <= 2.0  && FT <= 2.0)                                TP 2.0      -2         -5        -2        +2          -2             +2
            (WT => 2.0 & WT <= 2.11 ) && (FT ==2.11) TP 2.11 (mini matrix)        +1        -2        +1        +3           0             +3
            */
            Helper_ES2_AnchorCorrection(pReadData, FTMajorVersion, FTMinorVersion, WTMajorVersion, WTMinorVersion);

            Helper_ES2_MatrixCorrection(pReadData, FTMajorVersion, FTMinorVersion, WTMajorVersion, WTMinorVersion);
            /* Vtune High warning correction */
            Helper_VtuneHighWarnCorrection(pReadData, FTMajorVersion, WTMajorVersion);
            /* Gldo control code correction */
            Helper_GLDOControlCodeCorrection(pReadData, FTMajorVersion, WTMajorVersion);
        }
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        gOTPDataloaded[gTargetDevice] = TRUE;
    }
    // revert back the last entry of OTP to 0.
    gDefaultOTPValues[64] = 0u;
    return ErrCode;
}

BC_ERRCODE HAL_ES2_OTP_GetChipInfo(OTP_ChipInfo_t *pChipInfo)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    uint32_t localLOTID_MSB;
    uint32_t localLOTID_LSB;
    uint32_t localChar1, localChar2, localChar3, localChar4, localChar5, localChar6, localChar7, localChar8;
    uint32_t TempValue32;
    uint32_t *pReadData = gReadData[gTargetDevice];

    if (pChipInfo == NULL)
    {
        ErrCode = BC_ERR_INPUTOUTOFRANGE;
    }
    else
    {
        // the OTP data should be loaded successfully before calling this API.
        if (gOTPDataloaded[gTargetDevice] == TRUE)
        {
            TempValue32 = ((pReadData[OTP_TEST_CONTROL_INDEX] & (uint32_t)0x001F0000u) >> (uint32_t)16u) + (uint32_t)8210u;
            pChipInfo->Variant_Type = (uint16_t)TempValue32;
            localLOTID_MSB = pReadData[OTP_DIE_ID_1_INDEX];
            localLOTID_LSB = pReadData[OTP_DIE_ID_2_INDEX];

            localChar1 = (((localLOTID_MSB & (uint32_t)0x3F000000u) >> (uint32_t)24u) & (uint32_t)0x3Fu);
            localChar2 = (((localLOTID_MSB & (uint32_t)0x00FC0000u) >> (uint32_t)18u) & (uint32_t)0x3Fu);
            localChar3 = (((localLOTID_MSB & (uint32_t)0x0003F000u) >> (uint32_t)12u) & (uint32_t)0x3Fu);
            localChar4 = (((localLOTID_MSB & (uint32_t)0x00000FC0u) >> (uint32_t)6u) & (uint32_t)0x3Fu);
            localChar5 = ((localLOTID_MSB & (uint32_t)0x0000003Fu));
            localChar6 = (((localLOTID_LSB & (uint32_t)0xFC000000u) >> (uint32_t)26u) & (uint32_t)0x3Fu);
            localChar7 = (((localLOTID_LSB & (uint32_t)0x03F00000u) >> (uint32_t)20u) & (uint32_t)0x3Fu);
            localChar8 = (((localLOTID_LSB & (uint32_t)0x000FC000u) >> (uint32_t)14u) & (uint32_t)0x3Fu);
            /* Converting 6bit encoded data to 8 bit ASCII by adding 48u*/
            pChipInfo->LotID_MSB = (((localChar1 + (uint32_t)48u) << (uint32_t)24u) | ((localChar2 + (uint32_t)48u) << (uint32_t)16u) | ((localChar3 + (uint32_t)48u) << (uint32_t)8u) | (localChar4 + (uint32_t)48u));
            pChipInfo->LotID_LSB = (((localChar5 + (uint32_t)48u) << (uint32_t)24u) | ((localChar6 + (uint32_t)48u) << (uint32_t)16u) | ((localChar7 + (uint32_t)48u) << (uint32_t)8u) | (localChar8 + (uint32_t)48u));

            TempValue32 = (pReadData[OTP_DIE_ID_2_INDEX] & (uint32_t)0x00003F80u) >> (uint32_t)7u;
            pChipInfo->Wafer = (uint8_t)TempValue32;
            TempValue32 = (pReadData[OTP_DIE_ID_2_INDEX] & (uint32_t)0x0000007Fu);
            pChipInfo->Wafer_X_Position = (uint8_t)TempValue32;
            TempValue32 = (pReadData[OTP_DIE_ID_3_INDEX] & (uint32_t)0xFE000000u) >> (uint32_t)25u;

            pChipInfo->Wafer_Y_Position = (uint8_t)TempValue32;
            // Getting chip info MRA from OTP address 0x00C
            TempValue32 = (pReadData[OTP_DIE_ID_3_INDEX] & (uint32_t)0x01C00000u) >> (uint32_t)22u;
            pChipInfo->MaskVersion = (uint8_t)TempValue32;
            TempValue32 = (pReadData[OTP_DIE_ID_3_INDEX] & (uint32_t)0x003C0000u) >> (uint32_t)18u;
            /* WT_site info in OTP is shifted by 1: 0 is site 1 , 1 is site 2 and so on. To get correct value added 1 to OTP value.*/
            pChipInfo->WT_SITE = (uint8_t)TempValue32 + (uint8_t)1u;
            // Getting chip info of water test date from OTP address 0x00C
            TempValue32 = (pReadData[OTP_DIE_ID_3_INDEX] & (uint32_t)0x0003E000u) >> (uint32_t)13u;
            pChipInfo->WT_Day = (uint8_t)TempValue32;
            TempValue32 = (pReadData[OTP_DIE_ID_3_INDEX] & (uint32_t)0x00001E00u) >> (uint32_t)9u;
            pChipInfo->WT_Month = (uint8_t)TempValue32;
            TempValue32 = (pReadData[OTP_DIE_ID_3_INDEX] & (uint32_t)0x000001F0u) >> (uint32_t)4u;
            pChipInfo->WT_Year = (uint8_t)TempValue32;
            TempValue32 = (pReadData[OTP_DIE_ID_3_INDEX] & (uint32_t)0x0000000Fu);
            pChipInfo->MaskVersionMinor = (uint8_t)TempValue32;

            // Getting chip info of 1st Final Test from OTP adress 0x014
            TempValue32 = pReadData[OTP_TP_ID_FT12_INDEX] & (uint32_t)0x0000007Fu;
            pChipInfo->FT_TP_Version_Minor = (uint8_t)TempValue32;
            TempValue32 = (pReadData[OTP_TP_ID_FT12_INDEX] & (uint32_t)0x00007F00u) >> (uint32_t)8u;
            pChipInfo->FT_TP_Version_Major = (uint8_t)TempValue32;
            // Getting chip info of 1st wafer test from OTP address 0x10
            TempValue32 = pReadData[OTP_TP_ID_WT_INDEX] & (uint32_t)0x0000007Fu;
            pChipInfo->WT_TP_Version_Minor = (uint8_t)TempValue32;
            TempValue32 = (pReadData[OTP_TP_ID_WT_INDEX] & (uint32_t)0x00007F00u) >> (uint32_t)8u;
            pChipInfo->WT_TP_Version_Major = (uint8_t)TempValue32;
        }
        else
        {
            ErrCode = BC_ERR_OTP_OTPISNOTLOADED;
        }
    }
    return ErrCode;
}

static BC_ERRCODE Helper_ES2_GetOTPTableBase(OTP_Table_e OTPTable, OTP_TableDescrip_t *pTableBase)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    if (gOTPDataloaded[gTargetDevice] == TRUE)
    {
        switch (OTPTable)
        {
        case e_OTP_TRIM_FR_GLDO:
        case e_OTP_TRIM_SNS:
        case e_OTP_TRIM_GBIAS:
        case e_OTP_TRIM_LOCAL_LDO:
        case e_OTP_TRIM_RX1_THRESH:
        case e_OTP_TRIM_RX2_THRESH:
        case e_OTP_TRIM_RX3_THRESH:
            (void)Helper_CopySnsGldoTxTh(OTPTable, pTableBase);
            break;
        case e_OTP_TRIM_RX4_THRESH:
        case e_OTP_TRIM_RX1_FILTER:
        case e_OTP_TRIM_RX2_FILTER:
        case e_OTP_TRIM_RX3_FILTER:
        case e_OTP_TRIM_RX4_FILTER:
            (void)Helper_CopyRxThrFil(OTPTable, pTableBase);
            break;
        case e_OTP_TRIM_TX1_BIAS_ST3:
        case e_OTP_TRIM_TX2_BIAS_ST3:
        case e_OTP_TRIM_TX3_BIAS_ST3:
        case e_OTP_TRIM_TX1_BIAS_ST12:
        case e_OTP_TRIM_TX2_BIAS_ST12:
        case e_OTP_TRIM_TX3_BIAS_ST12:
            (void)Helper_CopyTxBias(OTPTable, pTableBase);
            break;
        case e_OTP_TRIM_TX1_THRESH:
        case e_OTP_TRIM_TX2_THRESH:
        case e_OTP_TRIM_TX3_THRESH:
        case e_OTP_TRIM_LOI_THRESH:
        case e_OTP_TRIM_CHIRP_THRESH:
        case e_OTP_TRIM_SUBBAND_CORRECTION_1G:
        case e_OTP_TRIM_SUBBAND_CORRECTION_2G:
        case e_OTP_TRIM_SUBBAND_CORRECTION_4G:
            (void)Helper_CopyTxLoiChirpThresSbCor(OTPTable, pTableBase);
            break;
        case e_OTP_SPARE_TRIM:
        case e_OTP_TRIM_WR_PTAT:
        case e_OTP_TRIM_TS_THRESH:
        case e_OTP_TRIM_TX_TS_COEFF:
        case e_OTP_TRIM_CHIRP_TS_COEFF:
            (void)Helper_CopySpareTrimTxTs(OTPTable, pTableBase);
            break;
        default:
            ErrCode = BC_ERR_INPUTOUTOFRANGE;
            break;
        }
    }
    else
    {
        ErrCode = BC_ERR_OTP_OTPISNOTLOADED;
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_OTP_DistributeOTPData(OTP_Table_e OTPTable, uint8_t StartIndex, uint8_t EndIndex)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    uint8_t ReadDataIndex = 0u;
    uint32_t OTPValue = 0u;
    uint8_t loopIndex = 0u;
    uint32_t RetVal = 0u;
    OTP_TableDescrip_t TableBase[MAX_OTP_DATA_TABLE_SIZE];
    (void)memset(TableBase, 0, sizeof(TableBase));
    uint32_t *pReadData = &gReadData[gTargetDevice][0];
    if ((StartIndex >= EndIndex) || (EndIndex > MAX_OTP_DATA_TABLE_SIZE))
    {
        ErrCode = BC_ERR_INPUTOUTOFRANGE;
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = Helper_ES2_GetOTPTableBase(OTPTable, TableBase);
        // calculate the index for gReadData given the address of the Source in the OTP table
        ReadDataIndex = TableBase[0u].SrcAddr / 4u;
    }
    // the OTP data should be loaded successfully before calling this API.
    for (loopIndex = StartIndex; loopIndex < EndIndex; loopIndex++)
    {
        if (ErrCode != BC_ERR_NOERROR)
        {
            break;
        }
        OTPValue = (pReadData[ReadDataIndex] & (TableBase[loopIndex].SrcMsk)) >> TableBase[loopIndex].SrcPos;
        ErrCode = BC_SPI_Read(TableBase[loopIndex].DstMod, TableBase[loopIndex].DstReg, &RetVal);
        if (ErrCode == BC_ERR_NOERROR)
        {
            RetVal = RetVal & (~(TableBase[loopIndex].DstMsk));
            RetVal = RetVal | (OTPValue << TableBase[loopIndex].DstPos);
            ErrCode = BC_SPI_WriteCheck(TableBase[loopIndex].DstMod, TableBase[loopIndex].DstReg, RetVal);
        }
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_OTP_CheckValidIP(OTP_ValidIP_e SelectedIP)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    uint8_t IPStatus = 0u;
    // If selectedIP is e_OTP_LOADED, this API only check if OTP is loaded.
    if (SelectedIP == e_OTP_LOADED)
    {
        if (gOTPDataloaded[gTargetDevice] == TRUE)
        {
            ErrCode = BC_ERR_NOERROR;
        }
        else
        {
            ErrCode = BC_ERR_OTP_OTPISNOTLOADED;
        }
    }
    else
    {
        if (gOTPDataloaded[gTargetDevice] == TRUE)
        {
            uint32_t OTPIndex0Value = gReadData[gTargetDevice][0];
            switch (SelectedIP)
            {
            case e_OTP_VALID_CHIRP_5G_MODE:
                IPStatus = (uint8_t)((OTPIndex0Value & 0x2000u) >> 13u);
                break;
            case e_OTP_VALID_PR:
                IPStatus = (uint8_t)((OTPIndex0Value & 0x1000u) >> 12u);
                break;
            case e_OTP_VALID_LO_IN:
                IPStatus = (uint8_t)((OTPIndex0Value & 0x800u) >> 11u);
                break;
            case e_OTP_VALID_LO_OUT:
                IPStatus = (uint8_t)((OTPIndex0Value & 0x400u) >> 10u);
                break;
            case e_OTP_VALID_RX4:
                IPStatus = (uint8_t)((OTPIndex0Value & 0x200u) >> 9u);
                break;
            case e_OTP_VALID_RX3:
                IPStatus = (uint8_t)((OTPIndex0Value & 0x100u) >> 8u);
                break;
            case e_OTP_VALID_RX2:
                IPStatus = (uint8_t)((OTPIndex0Value & 0x80u) >> 7u);
                break;
            case e_OTP_VALID_RX1:
                IPStatus = (uint8_t)((OTPIndex0Value & 0x40u) >> 6u);
                break;
            case e_OTP_VALID_TX3:
                IPStatus = (uint8_t)((OTPIndex0Value & 0x20u) >> 5u);
                break;
            case e_OTP_VALID_TX2:
                IPStatus = (uint8_t)((OTPIndex0Value & 0x10u) >> 4u);
                break;
            case e_OTP_VALID_TX1:
                IPStatus = (uint8_t)((OTPIndex0Value & 0x8u) >> 3u);
                break;
            case e_OTP_VALID_LVDS:
                IPStatus = (uint8_t)((OTPIndex0Value & 0x4u) >> 2u);
                break;
            case e_OTP_VALID_CSI2:
                IPStatus = (uint8_t)(OTPIndex0Value & 0x1u);
                break;

            default:
                ErrCode = BC_ERR_INPUTOUTOFRANGE;
                break;
            }

            if (ErrCode == BC_ERR_NOERROR)
            {
                if (IPStatus == 0u)
                {
                    ErrCode = BC_ERR_NOERROR;
                }
                else
                {
                    // If IP status is 1, then report that this IP is disabled.
                    ErrCode = BC_ERR_OTP_IPISDISABLED;
                }
            }
        }
        else
        {
            ErrCode = BC_ERR_OTP_OTPISNOTLOADED;
        }
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_OTP_GetOTPRegValue(uint16_t Offset, uint32_t *pRegData)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    if ((Offset <= 63u) && (pRegData != NULL))
    {
        if (gOTPDataloaded[gTargetDevice] == TRUE)
        {
            *pRegData = gReadData[gTargetDevice][Offset];
        }
        else
        {
            ErrCode = BC_ERR_OTP_OTPISNOTLOADED;
        }
    }
    else
    {
        ErrCode = BC_ERR_INPUTOUTOFRANGE;
    }
    return ErrCode;
}
#endif
