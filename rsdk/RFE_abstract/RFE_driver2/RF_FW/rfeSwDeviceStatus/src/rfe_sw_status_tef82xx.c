/**************************************************************************************************
* Copyright 2022 - 2023 NXP
**************************************************************************************************
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
**************************************************************************************************/

/******************************************************************************
 *   Project              : S32R41_RFE_FW
 *   Platform             : S32R41
 *****************************************************************************/

/*==================================================================================================
 *                                       INCLUDES
 ==================================================================================================*/
#include <stdio.h>
#include "rfeSwInit.h"
#include "rfe_sw_status_tef82xx.h"
#include "rfe_sw_cfg_to_tef82xx_map.h"
#include "rfe_tef82xx_voltage.h"
#include "rfe_sw_driver_state.h"
#include "rfe_register_dump.h"
#include "rfe_types.h"

#include "rfeHwLink.h"
#include "rfeSwUtils.h"
#include "rfeSwMainFsm.h"

#include "bc_err.h"
#include "bc_conf.h"
#include "bc_ism.h"
#include "bc_sys.h"
#include "bc_spi.h"
#include "bc_otp.h"
#include "reg_es2_ism.h"
#include "reg_es2_cc.h"
#include "reg_es2_ssb.h"
#include "bc_tx.h"
#include "bc_rx.h"
#include "bc_ssb.h"


/*==================================================================================================
 *                                        DEFINES
==================================================================================================*/

#define BIT_SET											1
#define BIT_CLEAR										0
#define FUSA_STATUS_SIZE 								32
#define TX_STATUS_RESPONSE_INDEX						2
#define RX_STATUS_RESPONSE_INDEX						3
#define CHIRP_STATUS_RESPONSE_INDEX						4
#define MCLOISMOTP_STATUS_RESPONSE_INDEX				5
#define SSBSERGBLDOATB_STATUS_RESPONSE_INDEX 			10
#define ADC_STATUS_RESPONSE_INDEX						6
#define ISM_STATUS_RESPONSE_INDEX						9
#define TX_STATUS_RESPONSE_USED_BITS_SIZE				18
#define RX_STATUS_RESPONSE_USED_BITS_SIZE				20
#define CHIRP_STATUS_RESPONSE_USED_BITS_SIZE			11
#define MCLOISMOTP_STATUS_RESPONSE_USED_BITS_SIZE		13
#define SSBSERGBLDOATB_STATUS_RESPONSE_USED_BITS_SIZE	9
#define ADC_STATUS_RESPONSE_USED_BITS_SIZE				6
#define SW_STATUS_RESPONSE_USED_BITS_SIZE               15
#define ISM_STATUS_RESPONSE_USED_BITS_SIZE				7
#define TX_CRC_MASKED_ERROR_STATUS_MASK                 0x07000000UL              
#define RX_CRC_MASKED_ERROR_STATUS_MASK                 0xF0000000UL
#define CHIRP_CRC_MASKED_ERROR_STATUS_MASK              0x10000000UL
#define MCLOISMOTP_CRC_MASKED_ERROR_STATUS_MASK         0x01F00000UL
#define SSBSERGBLDOATB_CRC_MASKED_ERROR_STATUS_MASK     0x001F0000UL
#define ADC_CRC_MASKED_ERROR_STATUS_MASK                0x00000C00UL
#define REG_CRC_FUSA_FAULT_REPORT_INDEX                 9U
#define REG_CRC_FUSA_FAULT_REPORT_BITPOS                4U
#define LAST_FUSA_BYTE_BIT_SIZE							5U
#define ATB1_EN_BIT										256U

#define BIT_ENABLE										1U
#define BIT_DISABLE										0u

/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
 *                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
 *                                      LOCAL VARIABLES
==================================================================================================*/
static uint8_t txStatusResponseUsedBits[TX_STATUS_RESPONSE_USED_BITS_SIZE] = {
		0U, 1U, 2U, 6U, 7U, 8U, 15U, 16U, 17U, 18U, 19U, 20U, 21U, 22U, 23U, 28U, 29U, 30U};

static uint8_t rxStatusResponseUsedBits[RX_STATUS_RESPONSE_USED_BITS_SIZE] = {
		0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 16U, 17U, 18U, 19U, 20U, 21U, 22U, 23U, 24U, 25U, 26U, 27U};

static uint8_t chirpStatusResponseUsedBits[CHIRP_STATUS_RESPONSE_USED_BITS_SIZE] = {
		0U, 1U, 8U, 11U, 12U, 13U, 16U, 17U, 18U, 20U, 21U};

static uint8_t mcLoIsmOtpStatusResponseUsedBits[MCLOISMOTP_STATUS_RESPONSE_USED_BITS_SIZE] = {
		2U, 3U, 4U, 5U, 6U, 8U, 9U, 10U, 13U, 14U, 16U, 19U, 1U};

static uint8_t ssbSerGbLdoAtbStatusResponseUsedBits[SSBSERGBLDOATB_STATUS_RESPONSE_USED_BITS_SIZE] = {
		0U, 4U, 8U, 9U, 10U, 12U, 13U, 14U, 15U};

static uint8_t adcStatusResponseUsedBits[ADC_STATUS_RESPONSE_USED_BITS_SIZE] = {
		0U, 1U, 2U, 3U, 8U, 9U};

static uint16_t TxFuSaStatusToFuSaErrorsMapper[TX_STATUS_RESPONSE_USED_BITS_SIZE] = {
		(uint16_t)rfe_fuSaFault_R2_sr27_bb_tx1_e,
		(uint16_t)rfe_fuSaFault_R2_sr27_bb_tx2_e,
		(uint16_t)rfe_fuSaFault_R2_sr27_bb_tx3_e,
		(uint16_t)rfe_fuSaFault_R2_sr69_rf_level_min_tx1_e,
		(uint16_t)rfe_fuSaFault_R2_sr69_rf_level_min_tx2_e,
		(uint16_t)rfe_fuSaFault_R2_sr69_rf_level_min_tx3_e,
		(uint16_t)rfe_fuSaFault_R2_sr69_rf_level_max_tx1_e,
		(uint16_t)rfe_fuSaFault_R2_sr69_rf_level_max_tx2_e,
		(uint16_t)rfe_fuSaFault_R2_sr69_rf_level_max_tx3_e,
		(uint16_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v8_tx1_e,
		(uint16_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v8_tx2_e,
		(uint16_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v8_tx3_e,
		(uint16_t)rfe_fuSaFault_R2_sr72_pr_tx1_e,
		(uint16_t)rfe_fuSaFault_R2_sr72_pr_tx2_e,
		(uint16_t)rfe_fuSaFault_R2_sr72_pr_tx3_e,
		(uint16_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v1_tx1_e,
		(uint16_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v1_tx2_e,
		(uint16_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v1_tx3_e
};

static uint16_t RxFuSaStatusToFuSaErrorsMapper[RX_STATUS_RESPONSE_USED_BITS_SIZE] = {
        (uint16_t)rfe_fuSaFault_R2_sr9_bb_rx1_e,
        (uint16_t)rfe_fuSaFault_R2_sr9_bb_rx2_e,
        (uint16_t)rfe_fuSaFault_R2_sr9_bb_rx3_e,
        (uint16_t)rfe_fuSaFault_R2_sr9_bb_rx4_e,
        (uint16_t)rfe_fuSaFault_R2_sr47_lo_level_min_rx1_e,
        (uint16_t)rfe_fuSaFault_R2_sr47_lo_level_min_rx2_e,
        (uint16_t)rfe_fuSaFault_R2_sr47_lo_level_min_rx3_e,
        (uint16_t)rfe_fuSaFault_R2_sr47_lo_level_min_rx4_e,
        (uint16_t)rfe_fuSaFault_R2_sr47_lo_level_max_rx1_e,
        (uint16_t)rfe_fuSaFault_R2_sr47_lo_level_max_rx2_e,
        (uint16_t)rfe_fuSaFault_R2_sr47_lo_level_max_rx3_e,
        (uint16_t)rfe_fuSaFault_R2_sr47_lo_level_max_rx4_e,
        (uint16_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v1_rx1_e,
        (uint16_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v1_rx2_e,
        (uint16_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v1_rx3_e,
        (uint16_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v1_rx4_e,
        (uint16_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v8_rx1_e,
        (uint16_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v8_rx2_e,
        (uint16_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v8_rx3_e,
        (uint16_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v8_rx4_e
};

static uint16_t ChripFuSaStatusToFuSaErrorsMapper[CHIRP_STATUS_RESPONSE_USED_BITS_SIZE] = {
        (uint16_t)rfe_fuSaFault_R2_sr7_lock_step_chirp_e,
        (uint16_t)rfe_fuSaFault_R2_sr43_unlock_chirp_e,
        (uint16_t)rfe_fuSaFault_R2_sr45_level_min_chirp_e,
        (uint16_t)rfe_fuSaFault_R2_sr45_level_max_chirp_e,
        (uint16_t)rfe_fuSaFault_R2_sr42_vco_freq_480_chirp_e,
        (uint16_t)rfe_fuSaFault_R2_sr7_interface_stuck_chirp_e,
        (uint16_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_pll_1v8_chirp_e,
        (uint16_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_vco_1v8_chirp_e,
        (uint16_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v1_chirp_e,
        (uint16_t)rfe_fuSaFault_R2_sr46_aafc_chirp_e,
        (uint16_t)rfe_fuSaFault_R2_sr46_aafc_cal_timeout_chirp_e
};

static uint16_t McLoIsmOtpFuSaStatusToFuSaErrorsMapper[MCLOISMOTP_STATUS_RESPONSE_USED_BITS_SIZE] = {
        (uint16_t)rfe_fuSaFault_R2_sr35_pll_lock_mclk_e,
        (uint16_t)rfe_fuSaFault_R2_sr39_dig_freq_mclk_e,
        (uint16_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v8_mclk_e,
        (uint16_t)rfe_fuSaFault_R2_sr36_mspc_mclk_e,
        (uint16_t)rfe_fuSaFault_R2_sr11_xo_no_clock_mclk_e,
        (uint16_t)rfe_fuSaFault_R2_sr18_bb_lo_out_loi_e,
        (uint16_t)rfe_fuSaFault_R2_sr17_bb_lo_in_loi_e,
        (uint16_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v1_loi_e,
        (uint16_t)rfe_fuSaFault_R2_sr19_wr_spi_crc_e,
        (uint16_t)rfe_fuSaFault_R2_sr19_rd_spi_crc_e,
        (uint16_t)rfe_fuSaFault_R2_sr48_level_min_loi_e,
        (uint16_t)rfe_fuSaFault_R2_sr48_level_max_loi_e,
		(uint16_t)rfe_fuSaFault_R2_sr37_pll_level_mclk_e
};

static uint16_t SsbSerGbLdoAtbFuSaStatusToFuSaErrorsMapper[SSBSERGBLDOATB_STATUS_RESPONSE_USED_BITS_SIZE] = {
        (uint16_t)rfe_fuSaFault_R2_sr65_67_supply_low_1v8_ssb_e,
        (uint16_t)rfe_fuSaFault_R2_sr65_67_supply_low_1v8_gbias_e,
        (uint16_t)rfe_fuSaFault_R2_sr65_67_supply_low_1v1_ser_e,
        (uint16_t)rfe_fuSaFault_R2_sr65_67_supply_low_1v1_csi2_e,
        (uint16_t)rfe_fuSaFault_R2_sr65_67_supply_low_1v8_ser_e,
        (uint16_t)rfe_fuSaFault_R2_sr63_supply_low_1v8_gldo_e,
        (uint16_t)rfe_fuSaFault_R2_sr61_supply_high_1v8_gldo_e,
        (uint16_t)rfe_fuSaFault_R2_sr59_supply_low_1v1_gldo_e,
        (uint16_t)rfe_fuSaFault_R2_sr57_supply_high_1v1_gldo_e
};

static uint16_t AdcFuSaStatusToFuSaErrorsMapper[ADC_STATUS_RESPONSE_USED_BITS_SIZE] = {
        (uint16_t)rfe_fuSaFault_R2_sr34_cal_adc1_e,
        (uint16_t)rfe_fuSaFault_R2_sr34_cal_adc2_e,
        (uint16_t)rfe_fuSaFault_R2_sr34_cal_adc3_e,
        (uint16_t)rfe_fuSaFault_R2_sr34_cal_adc4_e,
        (uint16_t)rfe_fuSaFault_R2_sr65_67_supply_low_1v8_adc12_e,
        (uint16_t)rfe_fuSaFault_R2_sr65_67_supply_low_1v8_adc34_e
};

static uint16_t swFuSaStatusToFuSaErrorsMapper[SW_STATUS_RESPONSE_USED_BITS_SIZE] = {
        (uint16_t)rfe_fuSaFault_R2_sr31_bist_lna_gaindiff_sw_e,
        (uint16_t)rfe_fuSaFault_R2_sr31_bist_lna_phasediff_sw_e,
        (uint16_t)rfe_fuSaFault_R2_sr31_bist_mixer_gaindiff_sw_e,
        (uint16_t)rfe_fuSaFault_R2_sr31_bist_mixer_phasediff_sw_e,
        (uint16_t)rfe_fuSaFault_R2_sr44_cafc_integrity_level_sw_e,
        (uint16_t)rfe_fuSaFault_R2_sr44_cafc_integrity_unlock_sw_e,
        (uint16_t)rfe_fuSaFault_R2_sr44_cafc_integrity_sw_e,
        (uint16_t)rfe_fuSaFault_R2_sr70_tx_integrity_sw_e,
        (uint16_t)rfe_fuSaFault_R2_sr72_tx_pr_cal_sw_e,
        (uint16_t)rfe_fuSaFault_R2_sr72_tx1_pr_cal_sw_e,
        (uint16_t)rfe_fuSaFault_R2_sr72_tx2_pr_cal_sw_e,
        (uint16_t)rfe_fuSaFault_R2_sr72_tx3_pr_cal_sw_e,
        (uint16_t)rfe_fuSaFault_R2_sr14_disable_lb_toggle_test_sw_e,
        (uint16_t)rfe_fuSaFault_R2_sr13_input_mode_toggle_test_sw_e,
        (uint16_t)rfe_generic_sw_e
};

// Array to store all sw errors from fusa fault list
static BOOL swErrorStatus[SW_ERROR_COUNT][RFE_MAX_SUPPORTED_DEVICES] = { (BOOL)FALSE };

/*==================================================================================================
 *                                      GLOBAL CONSTANTS
==================================================================================================*/
#if defined(TEF82XX_STATUS_DEBUG_HELPER) && defined(RFE_DEBUG)
//Tx FuSa error description

static const char txFuSaErr0[] = "tx1 bb err";
static const char txFuSaErr1[] = "tx2 bb err";
static const char txFuSaErr2[] = "tx3 bb err";
static const char txFuSaErr3[] = "tx1 temp err";
static const char txFuSaErr4[] = "tx2 temp err";
static const char txFuSaErr5[] = "tx3 temp err";
static const char txFuSaErr6[] = "tx1 rf level min err";
static const char txFuSaErr7[] = "tx2 rf level min err";
static const char txFuSaErr8[] = "tx3 rf level min err";
static const char txFuSaErr9[] = "tx1 rf level low err";
static const char txFuSaErr10[] = "tx2 rf level low err";
static const char txFuSaErr11[] = "tx3 rf level low err";
static const char txFuSaErr12[] = "tx1 rf level high err";
static const char txFuSaErr13[] = "tx2 rf level high err";
static const char txFuSaErr14[] = "tx3 rf level high err";
static const char txFuSaErr15[] = "tx1 rf level max err";
static const char txFuSaErr16[] = "tx2 rf level max err";
static const char txFuSaErr17[] = "tx3 rf level max err";
static const char txFuSaErr18[] = "tx1 1V8 low err";
static const char txFuSaErr19[] = "tx2 1V8 low err";
static const char txFuSaErr20[] = "tx3 1V8 low err";
static const char txFuSaErr21[] = "tx1 pr err";
static const char txFuSaErr22[] = "tx2 pr err";
static const char txFuSaErr23[] = "tx3 pr err";
static const char txFuSaErr24[] = "tx1 reg crc err";
static const char txFuSaErr25[] = "tx2 reg crc err";
static const char txFuSaErr26[] = "tx3 reg crc err";
static const char txFuSaErr28[] = "tx1 1V1 low err";
static const char txFuSaErr29[] = "tx2 1V1 low err";
static const char txFuSaErr30[] = "tx3 1V1 low err";

//Rx FuSa error description

static const char rxFuSaErr0[] = "rx1 bb err";
static const char rxFuSaErr1[] = "rx2 bb err";
static const char rxFuSaErr2[] = "rx3 bb err";
static const char rxFuSaErr3[] = "rx4 bb err";
static const char rxFuSaErr4[] = "rx1 rf level min err";
static const char rxFuSaErr5[] = "rx2 rf level min err";
static const char rxFuSaErr6[] = "rx3 rf level min err";
static const char rxFuSaErr7[] = "rx4 rf level min err";
static const char rxFuSaErr8[] = "rx1 rf level low err";
static const char rxFuSaErr9[] = "rx2 rf level low err";
static const char rxFuSaErr10[] = "rx3 rf level low err";
static const char rxFuSaErr11[] = "rx4 rf level low err";
static const char rxFuSaErr12[] = "rx1 rf level high err";
static const char rxFuSaErr13[] = "rx2 rf level high err";
static const char rxFuSaErr14[] = "rx3 rf level high err";
static const char rxFuSaErr15[] = "rx4 rf level high err";
static const char rxFuSaErr16[] = "rx2 rf level max err";
static const char rxFuSaErr17[] = "rx3 rf level max err";
static const char rxFuSaErr18[] = "rx3 rf level max err";
static const char rxFuSaErr19[] = "rx4 rf level max err";
static const char rxFuSaErr20[] = "rx1 1V1 low err";
static const char rxFuSaErr21[] = "rx2 1V1 low err";
static const char rxFuSaErr22[] = "rx3 1V1 low err";
static const char rxFuSaErr23[] = "rx4 1V1 low err";
static const char rxFuSaErr24[] = "rx1 1V8 low err";
static const char rxFuSaErr25[] = "rx2 1V8 low err";
static const char rxFuSaErr26[] = "rx4 1V8 low err";
static const char rxFuSaErr27[] = "rx1 1V8 low err";
static const char rxFuSaErr28[] = "rx1 reg crc err";
static const char rxFuSaErr29[] = "rx2 reg crc err";
static const char rxFuSaErr30[] = "rx2 reg crc err";
static const char rxFuSaErr31[] = "rx2 reg crc err";

//Chirp FuSa error description

static const char chirpFuSaErr0[] = "chirp lock step err";
static const char chirpFuSaErr1[] = "chirp unlock err";
static const char chirpFuSaErr2[] = "chirp temp err";
static const char chirpFuSaErr4[] = "chirp Vtune low err";
static const char chirpFuSaErr5[] = "chirp Vtune high err";
static const char chirpFuSaErr8[] = "chirp level min err";
static const char chirpFuSaErr9[] = "chirp level low err";
static const char chirpFuSaErr10[] = "chirp level high err";
static const char chirpFuSaErr11[] = "chirp level max err";
static const char chirpFuSaErr12[] = "chirp Vco Freq 480 err";
static const char chirpFuSaErr13[] = "chirp interface stuck err";
static const char chirpFuSaErr16[] = "chirp pll 1V8 low err";
static const char chirpFuSaErr17[] = "chirp Vco 1V8 low err";
static const char chirpFuSaErr18[] = "chirp Dig 1V1 low err";
static const char chirpFuSaErr20[] = "chirp Aafc err";
static const char chirpFuSaErr21[] = "chirp Aafc cal timeout err";

//MCOI FuSa error description

static const char mcoiFuSaErr0[] = "mclk pll freq cal err";
static const char mcoiFuSaErr1[] = "mclk pll level err";
static const char mcoiFuSaErr2[] = "mclk pll lock err";
static const char mcoiFuSaErr3[] = "mclk dig freq err";
static const char mcoiFuSaErr4[] = "mclk 1V8 low err";
static const char mcoiFuSaErr5[] = "mclk mscp err";
static const char mcoiFuSaErr6[] = "mclk Xo no clock err";
static const char mcoiFuSaErr8[] = "interface bb lo out err";
static const char mcoiFuSaErr9[] = "interface bb lo in err";
static const char mcoiFuSaErr10[] = "interface 1V8 low err";
static const char mcoiFuSaErr12[] = "jtag active set err";
static const char mcoiFuSaErr13[] = "wr spi crc err";
static const char mcoiFuSaErr14[] = "rd spi crc err";
static const char mcoiFuSaErr16[] = "interface loi level min err";
static const char mcoiFuSaErr17[] = "interface loi level low err";
static const char mcoiFuSaErr18[] = "interface loi level high err";
static const char mcoiFuSaErr19[] = "interface loi level max err";
static const char mcoiFuSaErr20[] = "mclk reg crc err";
static const char mcoiFuSaErr21[] = "interface reg crc err";
static const char mcoiFuSaErr22[] = "cc reg crc err";
static const char mcoiFuSaErr23[] = "ism reg crc err";
static const char mcoiFuSaErr24[] = "otp reg crc err";

//SSGA FuSa error description

static const char ssgaFuSaErr0[] = "ssb mod 1V8 low err";
static const char ssgaFuSaErr4[] = "global bias 1V8 low err";
static const char ssgaFuSaErr8[] = "ser 1V1 low err";
static const char ssgaFuSaErr9[] = "csi 1V1 low err";
static const char ssgaFuSaErr10[] = "ser 1V8 low err";
static const char ssgaFuSaErr12[] = "global ldo 1V8 low err";
static const char ssgaFuSaErr13[] = "global ldo 1V8 high err";
static const char ssgaFuSaErr14[] = "global ldo 1V1 low err";
static const char ssgaFuSaErr15[] = "global ldo 1V1 high err";
static const char ssgaFuSaErr16[] = "ssb mod reg crc err";
static const char ssgaFuSaErr17[] = "global bias reg crc err";
static const char ssgaFuSaErr18[] = "ser reg crc err";
static const char ssgaFuSaErr19[] = "global ldo reg crc err";
static const char ssgaFuSaErr20[] = "atb reg crc err";

//ADC FuSa error description

static const char adcFuSaErr0[] = "adc1 cal err";
static const char adcFuSaErr1[] = "adc2 cal err";
static const char adcFuSaErr2[] = "adc3 cal err";
static const char adcFuSaErr3[] = "adc4 cal err";
static const char adcFuSaErr4[] = "adc1 hard clipping err";
static const char adcFuSaErr5[] = "adc2 hard clipping err";
static const char adcFuSaErr6[] = "adc3 hard clipping err";
static const char adcFuSaErr7[] = "adc4 hard clipping err";
static const char adcFuSaErr8[] = "adc12 1V8 low err";
static const char adcFuSaErr9[] = "adc34 1V8 low err";
static const char adcFuSaErr10[] = "adc12 reg crc err";
static const char adcFuSaErr11[] = "adc34 reg crc err";

//ISM FuSa error description

static const char ismFuSaErr0[] = "ism rtm err";
static const char ismFuSaErr8[] = "ism ftti err";
static const char ismFuSaErr12[] = "ism digital 1V1 low err";
static const char ismFuSaErr16[] = "ism rtm err red";
static const char ismFuSaErr24[] = "ism ftti err red";
static const char ismFuSaErr28[] = "ism digital 1V1 low err red";
static const char ismFuSaErr31[] = "ism crc err";
#endif
/*==================================================================================================
 *                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
 *                                LOCAL FUNCTIONS PROTOTYPES
==================================================================================================*/

/*==================================================================================================
 *                                     INTERNAL FUNCTIONS
 ==================================================================================================*/
static uint16_t floatToUint16(float32_t value)
{
	uint16_t result;

	if (value <= (float32_t)0x0U)
	{
		result = 0U;
	}
	else if (value >= (float32_t)0xFFFFU)
	{
		result = 0xFFFFU;
	}
	else
	{
		result = (uint16_t)floor(value);
	}

	return result;
}

static BOOL getSwError( rfe_sw_fusaFault_index_t swErrorIndex, uint8_t fe )
{
	return swErrorStatus[swErrorIndex][fe];
}

static void reportSwErrorStatus( uint8_t *pFusaFaults  )
 {
	uint8_t statusReportOffset = 0;
	uint8_t statusReportBitwise = 0;
	BOOL 	swErrorActive = FALSE;
	uint8_t index;
	uint8_t fe = RfeDrvStateFrontendIdGet();

	for(index = (uint8_t)rfe_sw_fuSaFault_sr31_bist_lna_gaindiff_index_e; index < (uint8_t)SW_ERROR_COUNT; index++)
	{
		swErrorActive = getSwError((rfe_sw_fusaFault_index_t)index, fe);
		if (swErrorActive == TRUE )
		{
			statusReportOffset = (uint8_t)(swFuSaStatusToFuSaErrorsMapper[index] >> 8U);
			statusReportBitwise = (uint8_t)(swFuSaStatusToFuSaErrorsMapper[index] & 0x00ffU);
			pFusaFaults[statusReportOffset] |= ((uint8_t) (1U << statusReportBitwise));
		}
	}
 }

static BC_ERRCODE GetTemperature(rfeStatusReport_t* pDevStatus)
{
	BC_ERRCODE   errCode;
	// Enable temperature reading
	pDevStatus->fildsReported.statusResponse.txTemperature[0] = 1.0f;
	pDevStatus->fildsReported.statusResponse.txTemperature[1] = 1.0f;
	pDevStatus->fildsReported.statusResponse.txTemperature[2] = 1.0f;
	pDevStatus->fildsReported.statusResponse.chirpIpTemperature = 1.0f;

	errCode = BC_SYS_ReadTempSensor(&pDevStatus->fildsReported.statusResponse.txTemperature[0],
									&pDevStatus->fildsReported.statusResponse.txTemperature[1],
									&pDevStatus->fildsReported.statusResponse.txTemperature[2],
									&pDevStatus->fildsReported.statusResponse.chirpIpTemperature);
	return errCode;
}

#if defined(TEF82XX_STATUS_DEBUG_HELPER) && defined(RFE_DEBUG)
static void FuSaStatusDbgHelper(uint32_t fe, uint32_t fuSaStatus, const char ** fuSaErrName,
		rfe_error_t* rfe___error___pointer)
{
	uint8_t idx = 0;
	BOOL flag = FALSE;
	const char* msg = NULL;

	if(fuSaErrName != NULL)
	{
		for(idx = 0; idx < FUSA_STATUS_SIZE; ++idx)
		{
			flag = (fuSaStatus >> idx) & 0x00000001;
			if(flag == TRUE)
			{
				msg =  *(fuSaErrName + idx);
				if(msg != NULL)
				{
					RfeDbgPrintMsg("FuSa FE: %d, err: %s\n",fe, msg);
				}
				else
				{
					RfeDbgPrintMsg("FuSa FE: %d, err: unknow\n",fe);
				}
			}
		}
	}
	else
	{
		*rfe___error___pointer = rfe_error_nullPointer_e;
	}
}
#endif

static void SetFuSaReportBits(uint32_t fusaRegValue, uint8_t *pFusaFaults, uint16_t* arrayMapper,
		uint8_t* usedBits, uint8_t usedBitsSize)
{
	uint8_t i = 0U;
	uint8_t statusReportOffset = 0U;
	uint8_t statusReportBitwise = 0U;
	uint8_t bit = 0U;

	for(i = 0U; i < usedBitsSize; ++i)
	{
		bit = (uint8_t)((fusaRegValue >> usedBits[i]) & 0x01UL);
		if(bit == 1U)
		{
			statusReportOffset  = (uint8_t)(arrayMapper[i] >> 8U);
			statusReportBitwise = (uint8_t)(arrayMapper[i] & 0x00ffU);
			pFusaFaults[statusReportOffset] |= (uint8_t)(1U << statusReportBitwise);
		}
	}
}

static uint8_t GetModuleRegistersCount(uint8 module, uint16_t** regAddress)
{
	uint8_t count;

	switch(module)
	{
		case ((uint8_t)e_SYS_CC):
		{
			count = RFE_CC_REG_NUMBER;
			*regAddress = (uint16_t*)sw_CC_RegAddress;
			break;
		}
		case ((uint8_t)e_SYS_LVDS):
		{
			count = RFE_LDVS_REG_NUMBER;
			*regAddress = (uint16_t*)sw_LDVS_RegAddress;
			break;
		}
		case ((uint8_t)e_SYS_MIPI):
		{
			count = RFE_CSI2_REG_NUMBER;
			*regAddress = (uint16_t*)sw_CSI2_RegAddress;
			break;
		}
		case ((uint8_t)e_SYS_TE):
		{
			count = RFE_TE_REG_NUMBER;
			*regAddress = (uint16_t*)sw_TE_RegAddress;
			break;
		}
		case ((uint8_t)e_SYS_SC):
		{
			count = RFE_SC_REG_NUMBER;
			*regAddress = (uint16_t*)sw_SC_RegAddress;
			break;
		}
		case ((uint8_t)e_SYS_CAFC):
		{
			count = RFE_CAFC_REG_NUMBER;
			*regAddress = (uint16_t*)sw_CAFC_RegAddress;
			break;
		}
		case ((uint8_t)e_SYS_ADC12):
		{
			count = RFE_ADC_REG_NUMBER;
			*regAddress = (uint16_t*)sw_ADC_RegAddress;
			break;
		}
		case ((uint8_t)e_SYS_ADC34):
		{
			count = RFE_ADC_REG_NUMBER;
			*regAddress = (uint16_t*)sw_ADC_RegAddress;
			break;
		}
		case ((uint8_t)e_SYS_GBIAS):
		{
			count = RFE_GB_REG_NUMBER;
			*regAddress = (uint16_t*)sw_GB_RegAddress;
			break;
		}
		case ((uint8_t)e_SYS_LOI):
		{
			count = RFE_LOI_REG_NUMBER;
			*regAddress = (uint16_t*)sw_LOI_RegAddress;
			break;
		}
		case ((uint8_t)e_SYS_MCLK):
		{
			count = RFE_MCLK_REG_NUMBER;
			*regAddress = (uint16_t*)sw_MCLK_RegAddress;
			break;
		}
		case ((uint8_t)e_SYS_RX1):
		{
			count = RFE_RX_REG_NUMBER;
			*regAddress = (uint16_t*)sw_RX_RegAddress;
			break;
		}
		case ((uint8_t)e_SYS_RX2):
		{
			count = RFE_RX_REG_NUMBER;
			*regAddress = (uint16_t*)sw_RX_RegAddress;
			break;
		}
		case ((uint8_t)e_SYS_RX3):
		{
			count = RFE_RX_REG_NUMBER;
			*regAddress = (uint16_t*)sw_RX_RegAddress;
			break;
		}
		case ((uint8_t)e_SYS_RX4):
		{
			count = RFE_RX_REG_NUMBER;
			*regAddress = (uint16_t*)sw_RX_RegAddress;
			break;
		}
		case ((uint8_t)e_SYS_TX1):
		{
			count = RFE_TX_REG_NUMBER;
			*regAddress = (uint16_t*)sw_TX_RegAddress;
			break;
		}
		case ((uint8_t)e_SYS_TX2):
		{
			count = RFE_TX_REG_NUMBER;
			*regAddress = (uint16_t*)sw_TX_RegAddress;
			break;
		}
		case ((uint8_t)e_SYS_TX3):
		{
			count = RFE_TX_REG_NUMBER;
			*regAddress = (uint16_t*)sw_TX_RegAddress;
			break;
		}
		case ((uint8_t)e_SYS_SSB):
		{
			count = RFE_SSBMOD_REG_NUMBER;
			*regAddress = (uint16_t*)sw_SSBMOD_RegAddress;
			break;
		}
		case ((uint8_t)e_SYS_GLDO):
		{
			count = RFE_GLDO_REG_NUMBER;
			*regAddress = (uint16_t*)sw_GLDO_RegAddress;
			break;
		}
		case ((uint8_t)e_SYS_OTP):
		{
			count = RFE_OTP_REG_NUMBER;
			*regAddress = (uint16_t*)sw_OTP_RegAddress;
			break;
		}
		case ((uint8_t)e_SYS_ISM):
		{
			count = RFE_ISM_REG_NUMBER;
			*regAddress = (uint16_t*)sw_ISM_RegAddress;
			break;
		}
		default:
			count = 0U;
			break;
	}

	return count;
}

static void SetSwErrorStatus(uint8_t fe, rfe_sw_fusaFault_index_t index, rfe_error_t* rfe___error___pointer)
{
	uint8_t idx = (uint8_t)index;

	if( getSwFusaMask(idx) == FALSE )
	{
		swErrorStatus[idx][fe] = TRUE;
	}
	else
	{
		//error is masked, therefore it should not be reported.
		*rfe___error___pointer = rfe_error_none_e; // remove error
	}
}

/*
 *  Function to write an ATB module register and check the written data
 *  The execution is conditioned by the existing error code, which is overwritten after the check (if done)
 */
static void  AtbCtrl_WriteAndCheck(uint16_t regAdr, uint32_t dataVal, BC_ERRCODE *errorPtr)
{
    if(*errorPtr == BC_ERR_NOERROR)
    {
        *errorPtr = BC_SPI_WriteCheck(e_SYS_ATB, regAdr, dataVal);
    }
}
/*--------------- AtbCtrl_WriteAndCheck ----------------*/


static BC_ERRCODE ATB_ReadBISTADC(float32_t *voltageMilliVolt)
{
    BC_ERRCODE errCode = BC_ERR_NOERROR;
    // ATB_ReadBISTADC
    uint32_t AtbDataRegister = 0U;
    uint16_t ADCRaw = 0u;
    float32_t mVPerLSB = 0.0f;
    uint32_t OtpValue = 0UL;
    uint32_t CalBistADC = 0UL;
    int8_t BISTADC_gain_1;
    int8_t BISTADC_offset_1;
    BOOL BISTADCCalibrated = FALSE;
    int8_t LocalOffsetCode = 0;
    float32_t LocalmVPerLSB = mVPerLSB;
    uint32_t AtbConfigRegister1 = 0xC3080008UL;
    uint32_t WhileLoopCount = 0u;
    uint16_t ATBADCBufferAddress = 0U;
	*voltageMilliVolt = 9999.0f;
	int16_t temp;
	float32_t tempValue;

    errCode = BC_OTP_GetOTPRegValue(OTP_TRIM_VALID_0F8_INDEX, &OtpValue);
    BISTADCCalibrated = ((OtpValue & 0x01u) == 0x01u) ? TRUE : FALSE;

    if ((errCode == BC_ERR_NOERROR) && (BISTADCCalibrated == TRUE))
    {
    	errCode = BC_OTP_GetOTPRegValue(OTP_CAL_BISTADC1_INDEX, &CalBistADC);
    }
	if (errCode == BC_ERR_NOERROR)
	{
		BISTADC_gain_1 = (int8_t)((CalBistADC & 0x0000FF00UL) >> 8u);
		BISTADC_offset_1 = (int8_t)((CalBistADC & 0xFFu));
		LocalmVPerLSB = 1.8f;

		if(BISTADCCalibrated == TRUE)
		{
			LocalOffsetCode = BISTADC_offset_1;
			LocalmVPerLSB = (1.8f + ((float32_t)BISTADC_gain_1/ 1000.0f));
		}
		errCode = BC_SPI_WriteCheck(e_SYS_ATB, (uint16_t)0x0004, AtbConfigRegister1);
	}
    AtbCtrl_WriteAndCheck(0x0010U, 273UL, &errCode);
    //trigger ADC1 in clockless mode
	AtbCtrl_WriteAndCheck(0U, 1048576UL, &errCode);
    AtbCtrl_WriteAndCheck(0U, 0UL, &errCode);
    AtbCtrl_WriteAndCheck(0U, 1048576UL, &errCode);
	if (errCode == BC_ERR_NOERROR)
	{
		do
		{
			RfeHwDelayUs(ATB_ReadBISTADC_SLEEP);
			//Read ADC raw data
			errCode = BC_SPI_Read(e_SYS_ATB, (uint16_t)0x0100, &AtbDataRegister);
			if (errCode == BC_ERR_NOERROR)
			{
				ADCRaw = (uint16_t)(AtbDataRegister & 0x3FFUL);
				WhileLoopCount++;
				errCode = BC_ERR_ATB_BISTADCTIMEOUT;
			}
		} while ((((AtbDataRegister >> 12U)  & 1UL) == (uint32_t)FALSE) &&
				(errCode == BC_ERR_ATB_BISTADCTIMEOUT) &&
				(WhileLoopCount <= ATB_BISTADC_TIMEOUT));
	}
	if ((WhileLoopCount <= ATB_BISTADC_TIMEOUT) &&
		(errCode == BC_ERR_ATB_BISTADCTIMEOUT) &&
		(((AtbDataRegister >> 12U)  & 1UL) == (uint32_t)TRUE))
	{
		errCode = BC_ERR_NOERROR;
	}
    AtbCtrl_WriteAndCheck(0U, 0UL, &errCode);
    AtbCtrl_WriteAndCheck(ATBADCBufferAddress, 0UL, &errCode);
    AtbCtrl_WriteAndCheck(4U, 0UL, &errCode);
    if (errCode == BC_ERR_NOERROR)
    {
        temp = ((int16_t)ADCRaw - 512 - LocalOffsetCode);
        tempValue = (float32_t)temp;
        *voltageMilliVolt = tempValue * LocalmVPerLSB;
    }

    return errCode;
}

static BC_ERRCODE atb1Read(SYS_IPNum_e ConnectIP,uint16_t AtbControlAdress, uint32_t AtbControl, float32_t *voltageMilliVolt)
{
	BC_ERRCODE errCode = BC_ERR_NOERROR;
	uint16_t AtbControlAdressCC = 0x0504;
	uint8_t IPNum = 0x0u;
	uint32_t AtbEnableValue = 0u;

	/*  using switch case instead of if, since not all IPs are used here */
	switch (ConnectIP)
	{
	case e_SYS_LVDS:
	case e_SYS_MIPI:
		IPNum = 0x1u; // Special case for both  serializer value is 1
		break;
	case e_SYS_CAFC:
	case e_SYS_ADC12:
	case e_SYS_ADC34:
	case e_SYS_GBIAS:
	case e_SYS_LOI:
	case e_SYS_MCLK:
	case e_SYS_RX1:
	case e_SYS_RX2:
	case e_SYS_RX3:
	case e_SYS_RX4:
	case e_SYS_TX1:
	case e_SYS_TX2:
	case e_SYS_TX3:
	case e_SYS_SSB:
	case e_SYS_GLDO:
	case e_SYS_ATB:
	case e_SYS_TEMP_DIGITIZER:
		IPNum = (uint8_t)ConnectIP;
		break;
	default:
		errCode = BC_ERR_INPUTOUTOFRANGE;
		break;
	}

	// CC_ConfigDCATB Enable ATB1 and ATB connection in selected IP module
	AtbEnableValue = (uint32_t)IPNum + 256u;
	if (errCode == BC_ERR_NOERROR)
	{
		errCode = BC_SPI_WriteCheck(e_SYS_CC, AtbControlAdressCC, AtbEnableValue);
	}
    if (errCode == BC_ERR_NOERROR)
    {
        errCode = BC_SPI_WriteCheck(ConnectIP, AtbControlAdress, AtbControl);
    }

    // Wait 10ms for supply to settle.
    RfeHwDelayUs(10000U);

    if (errCode == BC_ERR_NOERROR)
    {
        errCode = ATB_ReadBISTADC(voltageMilliVolt);
    }
    if (errCode == BC_ERR_NOERROR)
    {
        errCode = BC_SPI_WriteCheck(ConnectIP, AtbControlAdress, 0);
    }
    return errCode;
}

static BC_ERRCODE adcAtbRead(SYS_IPNum_e IPNum, ADC_ATBNodes_e ADC_ATBNodes, float32_t *voltageMilliVolt)
// available supply nodes e_ADC_NODE_1V1_SUPPLY (divide by 11/3, internal LDO), e_ADC_NODE_1V1_SAFETY_SUPPLY (divide by 11/3, ball N3),
// e_ADC_NODE_1V8_SUPPLY (divide by 6, ball ADC12=C12, ADC34=N12)
{
    BC_ERRCODE errCode = BC_ERR_NOERROR;
    uint8_t selNode =(uint8_t)ADC_ATBNodes;
    uint16_t AtbControlAdress = 0x0500;

    // ADC_ConnectATBNode
    uint32_t AtbControl = (1UL<<selNode) << 16;
	errCode = atb1Read(IPNum,AtbControlAdress, AtbControl, voltageMilliVolt);

    return errCode;
}

static BC_ERRCODE adcVoltageRead(SYS_IPNum_e IPNum, ATB_ADCVoltages_t *pADCVoltages)
{
    BC_ERRCODE errCode = BC_ERR_NOERROR;
    float32_t voltageMilliVolt = 0.0f;

    errCode = adcAtbRead(IPNum,e_ADC_NODE_1V1_SAFETY_SUPPLY, &voltageMilliVolt);
    if (errCode == BC_ERR_NOERROR)
    {
    	pADCVoltages->ADC_NODE_1V1_SAFETY_SUPPLY = floatToUint16((11.0f/3.0f)*voltageMilliVolt);
        errCode = adcAtbRead(IPNum,e_ADC_NODE_1V1_SUPPLY, &voltageMilliVolt);
    }
    if (errCode == BC_ERR_NOERROR)
    {
    	pADCVoltages->ADC_NODE_1V1_SUPPLY = floatToUint16((11.0f/3.0f)*voltageMilliVolt);
        errCode = adcAtbRead(IPNum,e_ADC_NODE_1V8_SUPPLY, &voltageMilliVolt);
    }
    if (errCode == BC_ERR_NOERROR)
    {
    	pADCVoltages->ADC_NODE_1V8_SUPPLY = floatToUint16(6.0f*voltageMilliVolt);
    }
    return errCode;
}

static BC_ERRCODE allAdcVoltageRead(ATB_ADCVoltages_t *pADC12Voltages, ATB_ADCVoltages_t *pADC34Voltages)
{
    BC_ERRCODE errCode = BC_ERR_NOERROR;
    errCode =  adcVoltageRead(e_SYS_ADC12, pADC12Voltages);

    if (errCode == BC_ERR_NOERROR)
    {
       errCode =  adcVoltageRead(e_SYS_ADC34, pADC34Voltages);
    }

    return errCode;
}

static BC_ERRCODE atbAtbRead(ATB_ATBNodes_e ATB_ATBNodes, float32_t *voltageMilliVolt)
// available supply nodes e_ATB_NODE_VDDA_1V8 (divide by 6, ball C12), e_ATB_NODE_VDDA_1V1 (divide by 11/3, internal LDO),
// e_ATB_NODE_VDDD_SAFETY_1V1 (divide by 11/3, ball N3)
{
    BC_ERRCODE errCode = BC_ERR_NOERROR;
    uint8_t selNode =(uint8_t)ATB_ATBNodes;
    uint16_t AtbControlAdress = 0x0054;
    SYS_IPNum_e IPNum = e_SYS_ATB;

    // ATB_ConnectATBNode
    uint32_t AtbControl = (uint32_t)selNode + ATB1_EN_BIT;
	errCode = atb1Read(IPNum,AtbControlAdress, AtbControl, voltageMilliVolt);

    return errCode;
}

static BC_ERRCODE atbVoltageRead(ATB_ATBVoltages_t *pATBVoltages)
{
    BC_ERRCODE errCode = BC_ERR_NOERROR;
    float32_t voltageMilliVolt = 0.0f;

    errCode = atbAtbRead(e_ATB_NODE_VDDD_SAFETY_1V1, &voltageMilliVolt);
    if (errCode == BC_ERR_NOERROR)
    {
    	pATBVoltages->ATB_NODE_VDDD_SAFETY_1V1 = floatToUint16((11.0f/3.0f)*voltageMilliVolt);
        errCode = atbAtbRead(e_ATB_NODE_VDDA_1V1, &voltageMilliVolt);
    }
    if (errCode == BC_ERR_NOERROR)
    {
    	pATBVoltages->ATB_NODE_VDDA_1V1 = floatToUint16((11.0f/3.0f)*voltageMilliVolt);
        errCode = atbAtbRead(e_ATB_NODE_VDDA_1V8, &voltageMilliVolt);
    }
    if (errCode == BC_ERR_NOERROR)
    {
    	pATBVoltages->ATB_NODE_VDDA_1V8 = floatToUint16(6.0f*voltageMilliVolt);
    }

    return errCode;
}

static BC_ERRCODE cafcAtbRead(CAFC_ATBNodes_e CAFC_ATBNodes, float32_t *voltageMilliVolt)
// available supply nodes e_CAFC_NODE_VDD_VCO_1V8 (divide by 6, ball A7), e_CAFC_NODE_LDO_VCO_VDD (divide by 11/3, internal)
// e_CAFC_NODE_LDO_CPPFD_VDD (divide by 11/3, internal), e_CAFC_NODE_LDO_DIVIDER_VDD (divide by 11/3, internal),
// e_CAFC_NODE_VDD_PLL_1V8 (divide by 6, ball B8), e_CAFC_NODE_VDD_PLL_1V1 (filtered and divide by 11/3, ball N3)
{
    BC_ERRCODE errCode = BC_ERR_NOERROR;
    uint8_t selNode =(uint8_t)CAFC_ATBNodes;
    uint16_t AtbControlAdress = 0x0C04;
    SYS_IPNum_e IPNum = e_SYS_CAFC;

    // CAFC_ConnectATBNode
    uint32_t AtbControl = (uint32_t)selNode + ATB1_EN_BIT;
	errCode = atb1Read(IPNum,AtbControlAdress, AtbControl, voltageMilliVolt);

    return errCode;
}

static BC_ERRCODE cafcVoltageRead(ATB_CAFCVoltages_t *pCAFCVoltages)
{
    BC_ERRCODE errCode = BC_ERR_NOERROR;
    float32_t voltageMilliVolt = 0.0f;

    errCode = cafcAtbRead(e_CAFC_NODE_VDD_PLL_1V1, &voltageMilliVolt);
    if (errCode == BC_ERR_NOERROR)
    {
    	pCAFCVoltages->CAFC_NODE_VDD_PLL_1V1_FILTERED = floatToUint16((11.0f/3.0f)*voltageMilliVolt);
        errCode = cafcAtbRead(e_CAFC_NODE_LDO_CPPFD_VDD, &voltageMilliVolt);
    }
    if (errCode == BC_ERR_NOERROR)
    {
    	pCAFCVoltages->CAFC_NODE_LDO_CPPFD_VDD = floatToUint16((11.0f/3.0f)*voltageMilliVolt);
        errCode = cafcAtbRead(e_CAFC_NODE_LDO_VCO_VDD, &voltageMilliVolt);
    }
    if (errCode == BC_ERR_NOERROR)
    {
    	pCAFCVoltages->CAFC_NODE_LDO_VCO_VDD = floatToUint16((11.0f/3.0f)*voltageMilliVolt);
        errCode = cafcAtbRead(e_CAFC_NODE_LDO_DIVIDER_VDD, &voltageMilliVolt);
    }
    if (errCode == BC_ERR_NOERROR)
    {
    	pCAFCVoltages->CAFC_NODE_LDO_DIVIDER_VDD = floatToUint16((11.0f/3.0f)*voltageMilliVolt);
        errCode = cafcAtbRead(e_CAFC_NODE_VDD_VCO_1V8, &voltageMilliVolt);
    }
    if (errCode == BC_ERR_NOERROR)
    {
    	pCAFCVoltages->CAFC_NODE_VDD_VCO_1V8 = floatToUint16(6.0f*voltageMilliVolt);
        errCode = cafcAtbRead(e_CAFC_NODE_VDD_PLL_1V8, &voltageMilliVolt);
    }
    if (errCode == BC_ERR_NOERROR)
    {
    	pCAFCVoltages->CAFC_NODE_VDD_PLL_1V8 = floatToUint16(6.0f*voltageMilliVolt);
    }

    return errCode;
}

static BC_ERRCODE gbiasAtbRead(GBIAS_ATBNodes_e GBIAS_ATBNodes, float32_t *voltageMilliVolt)
// available supply node e_GBIAS_NODE_VDDA_GLOBAL_BIAS (divide by 6, ball C6&B6&B7),

{
    BC_ERRCODE errCode = BC_ERR_NOERROR;
    uint8_t selNode =(uint8_t)GBIAS_ATBNodes;
    uint16_t AtbControlAdress = 0x0C04;
    SYS_IPNum_e IPNum = e_SYS_GBIAS;

    // GBIAS_ConnectATBNode
    uint32_t AtbControl = (uint32_t)selNode + ATB1_EN_BIT;
	errCode=atb1Read(IPNum,AtbControlAdress, AtbControl, voltageMilliVolt);

    return errCode;
}

static BC_ERRCODE gbiasVoltageRead(ATB_GBIASVoltages_t *pGBIASVoltages)
{
    BC_ERRCODE errCode = BC_ERR_NOERROR;
    float32_t voltageMilliVolt = 0.0f;

    errCode = gbiasAtbRead(e_GBIAS_NODE_VDDA_GLOBAL_BIAS, &voltageMilliVolt);
    if (errCode == BC_ERR_NOERROR)
    {
    	pGBIASVoltages->GBIAS_NODE_VDDA_GLOBAL_BIAS_1V8 = floatToUint16(6.0f*voltageMilliVolt);
    }

    return errCode;
}

static BC_ERRCODE gldoAtbRead(GLDO_ATBNodes_e GLDO_ATBNodes, float32_t *voltageMilliVolt)
// available supply nodes e_GLDO_NODE_VDDD_SAFETY_1V1 (divide by 11/3, ball N3), e_GLDO_NODE_VDDA_LDO_1V8 (divide by 6, ball C6,B6,B7),
// e_GLDO_NODE_VDDA_LDO_1V1(divide by 11/3, ball B4), e_GLDO_NODE_VDDA_LDO_3V3 (divide by 11, ball A1,B2)
{
    BC_ERRCODE errCode = BC_ERR_NOERROR;
    uint8_t selNode =(uint8_t)GLDO_ATBNodes;
    uint16_t AtbControlAdress = 0x0074;
    SYS_IPNum_e IPNum = e_SYS_GLDO;

    // GLDO_ConnectATBNode
    uint32_t AtbControl = (uint32_t)selNode + ATB1_EN_BIT;
	errCode=atb1Read(IPNum,AtbControlAdress, AtbControl, voltageMilliVolt);

    return errCode;
}

static BC_ERRCODE gldoVoltageRead(ATB_GLDOVoltages_t *pGLDOVoltages)
{
    BC_ERRCODE errCode = BC_ERR_NOERROR;
    float32_t voltageMilliVolt = 0.0f;

    errCode = gldoAtbRead(e_GLDO_NODE_VDDD_SAFETY_1V1, &voltageMilliVolt);
    if (errCode == BC_ERR_NOERROR)
    {
    	pGLDOVoltages->GLDO_NODE_VDDD_SAFETY_1V1 = floatToUint16((11.0f/3.0f)*voltageMilliVolt);
    	errCode = gldoAtbRead(e_GLDO_NODE_VDDA_LDO_1V1, &voltageMilliVolt);
    }
    if (errCode == BC_ERR_NOERROR)
    {
    	pGLDOVoltages->GLDO_NODE_VDDA_LDO_1V1 = floatToUint16((11.0f/3.0f)*voltageMilliVolt);
		errCode = gldoAtbRead(e_GLDO_NODE_VDDA_LDO_1V8, &voltageMilliVolt);
    }
    if (errCode == BC_ERR_NOERROR)
    {
    	pGLDOVoltages->GLDO_NODE_VDDA_LDO_1V8 = floatToUint16(6.0f*voltageMilliVolt);
		errCode = gldoAtbRead(e_GLDO_NODE_VDDA_LDO_3V3, &voltageMilliVolt);
    }
    if (errCode == BC_ERR_NOERROR)
    {
    	pGLDOVoltages->GLDO_NODE_VDDA_LDO_3V3 = floatToUint16(11.0f*voltageMilliVolt);
    }

    return errCode;
}

static BC_ERRCODE loiAtvRead(LOI_ATBNodes_e LOI_ATBNodes, float32_t *voltageMilliVolt)
// available supply nodes e_LOI_NODE_VDDD_SAFETY (divide by 11/3, ball N3), e_LOI_NODE_VDDA_INTERFACE (divide by 11/3, ball H13),
// e_LOI_NODE_ATB1_VDDA1V8_ATB2_VREFB3, (divide by 6, ball C6,B6,B7)
{
    BC_ERRCODE errCode = BC_ERR_NOERROR;
    uint8_t selNode =(uint8_t)LOI_ATBNodes;
    uint16_t AtbControlAdress = 0x0C04;
    SYS_IPNum_e IPNum = e_SYS_LOI;

    // LOI_ConnectATBNode
    uint32_t AtbControl = (uint32_t)selNode + ATB1_EN_BIT;
	errCode=atb1Read(IPNum,AtbControlAdress, AtbControl, voltageMilliVolt);

    return errCode;
}

static BC_ERRCODE loiVoltageRead(ATB_LOIVoltages_t *pLOIVoltages)
{
    BC_ERRCODE errCode = BC_ERR_NOERROR;
    float32_t voltageMilliVolt = 0.0f;

    errCode = loiAtvRead(e_LOI_NODE_VDDD_SAFETY, &voltageMilliVolt);
    if (errCode == BC_ERR_NOERROR)
    {
    	pLOIVoltages->LOI_NODE_VDDD_SAFETY_1V1 = floatToUint16((11.0f/3.0f)*voltageMilliVolt);
		errCode = loiAtvRead(e_LOI_NODE_VDDA_INTERFACE, &voltageMilliVolt);
    }
    if (errCode == BC_ERR_NOERROR)
    {
    	pLOIVoltages->LOI_NODE_VDDA_INTERFACE_1V1 = floatToUint16((11.0f/3.0f)*voltageMilliVolt);
		errCode = loiAtvRead(e_LOI_NODE_ATB1_VDDA1V8_ATB2_VREFB3, &voltageMilliVolt);
    }
    if (errCode == BC_ERR_NOERROR)
    {
    	pLOIVoltages->LOI_NODE_VDDA_1V8 = floatToUint16(6.0f*voltageMilliVolt);
    }
    return errCode;
}

static BC_ERRCODE mclkAtbRead(MCLK_ATBNodes_e MLCK_ATBNodes, float32_t *voltageMilliVolt)
// available supply nodes e_MCLK_NODE_VDDD_SAFETY_1V1 (divide by 11/3, ball N3), e_MCLK_NODE_VDDA_1V1 (divide by 11/3, internal LDO),
// e_MCLK_NODE_VDDA_1V8, (divide by 6, ball B9),
{
    BC_ERRCODE errCode = BC_ERR_NOERROR;
    uint8_t selNode =(uint8_t)MLCK_ATBNodes;
	uint16_t AtbControlAdress = 0x0180;
    SYS_IPNum_e IPNum = e_SYS_MCLK;

    // MCLK_ConnectATBNode
    uint32_t AtbControl = ((uint32_t)selNode & 0x0Fu) + 256U;
	errCode = atb1Read(IPNum,AtbControlAdress, AtbControl, voltageMilliVolt);

    return errCode;
}

static BC_ERRCODE mclkVoltageRead(ATB_MCLKVoltages_t *pMCLKVoltages)
{
    BC_ERRCODE errCode = BC_ERR_NOERROR;
    float32_t voltageMilliVolt = 0.0f;

    errCode = mclkAtbRead(e_MCLK_NODE_VDDD_SAFETY_1V1, &voltageMilliVolt);
    if (errCode == BC_ERR_NOERROR)
    {
    	pMCLKVoltages->MCLK_NODE_VDDD_SAFETY_1V1 = floatToUint16((11.0f/3.0f)*voltageMilliVolt);
		errCode = mclkAtbRead(e_MCLK_NODE_VDDA_1V1, &voltageMilliVolt);
    }
    if (errCode == BC_ERR_NOERROR)
    {
    	pMCLKVoltages->MCLK_NODE_VDDA_1V1 = floatToUint16((11.0f/3.0f)*voltageMilliVolt);
		errCode = mclkAtbRead(e_MCLK_NODE_VDDA_1V8, &voltageMilliVolt);
    }
    if (errCode == BC_ERR_NOERROR)
    {
    	pMCLKVoltages->MCLK_NODE_VDDA_1V8 = floatToUint16(6.0f*voltageMilliVolt);
    }

    return errCode;
}

static BC_ERRCODE mipiAtbRead(MIPI_ATBNodes_e MIPI_ATBNodes, float32_t *voltageMilliVolt)
// available supply nodes e_MIPI_NODE_SUPPLY1V1_CSI2 (divide by 11/3, internal LDO ), e_MIPI_NODE_SUPPLY1V1_SER (divide by 11/3, internal LDO),
// e_MIPI_NODE_SUPPLY1V8, (divide by 6, ball N9), e_MIPI_NODE_SUPPLYIO_1v8_3v3 (divide by 11, ball N8),
// e_MIPI_NODE_SUPPLY_MIPI_3v3 (divide by 11, ball N7)
{
    BC_ERRCODE errCode = BC_ERR_NOERROR;
    uint8_t selNode =(uint8_t)MIPI_ATBNodes;
	uint16_t AtbControlAdress = 0x0504;
    SYS_IPNum_e IPNum = e_SYS_MIPI;

    // MIPI_ConnectATBNode
    uint32_t AtbControl = (uint32_t)selNode + ATB1_EN_BIT;
	errCode = atb1Read(IPNum,AtbControlAdress, AtbControl, voltageMilliVolt);

    return errCode;
}

static BC_ERRCODE mipiVoltageRead(ATB_MIPIVoltages_t *pMIPIVoltages)
{
    BC_ERRCODE errCode = BC_ERR_NOERROR;
    float32_t voltageMilliVolt = 0.0f;

    errCode = mipiAtbRead(e_MIPI_NODE_SUPPLY1V1_CSI2, &voltageMilliVolt);
    if (errCode == BC_ERR_NOERROR)
    {
    	pMIPIVoltages->MIPI_NODE_SUPPLY1V1_CSI2 = floatToUint16((11.0f/3.0f)*voltageMilliVolt);
		errCode = mipiAtbRead(e_MIPI_NODE_SUPPLY1V1_SER, &voltageMilliVolt);
    }
    if (errCode == BC_ERR_NOERROR)
    {
    	pMIPIVoltages->MIPI_NODE_SUPPLY1V1_SER = floatToUint16((11.0f/3.0f)*voltageMilliVolt);
		errCode = mipiAtbRead(e_MIPI_NODE_SUPPLY1V8, &voltageMilliVolt);
    }
    if (errCode == BC_ERR_NOERROR)
    {
    	pMIPIVoltages->MIPI_NODE_SUPPLY1V8 = floatToUint16(6.0f*voltageMilliVolt);
		errCode = mipiAtbRead(e_MIPI_NODE_SUPPLYIO_1v8_3v3, &voltageMilliVolt);
    }
    if (errCode == BC_ERR_NOERROR)
    {
    	// Ideal scaling factor based on internal resistor divider should be 11 but due to path resistance factor 12 is used
		pMIPIVoltages->MIPI_NODE_SUPPLYIO_1v8_3v3 = floatToUint16(12.0f*voltageMilliVolt);
		errCode = mipiAtbRead(e_MIPI_NODE_SUPPLY_MIPI_3v3, &voltageMilliVolt);
    }
    if (errCode == BC_ERR_NOERROR)
    {
    	// Ideal scaling factor based on internal resistor divider should be 11 but due to path resistance factor 13 is used
		pMIPIVoltages->MIPI_NODE_SUPPLY_MIPI_3v3 = floatToUint16(13.0f*voltageMilliVolt);
    }

    return errCode;
}

static BC_ERRCODE rxAtbRead(SYS_IPNum_e IPNum, RX_ATBNodes_e RX_ATBNodes, float32_t *voltageMilliVolt)
// available supply nodes e_RX_NODE_VDDA_1V1 (divide by 11/3, ball RX1=E13, RX2=F13, RX3=K13, RX4=L13), e_RX_NODE_VDDD_1V1 (divide by 11/3, ball N3),
// e_RX_NODE_VDDA_1V8 (divide by 6, ball RX1=C13, RX2=G13, RX3=J13, RX4=N13)
{
    BC_ERRCODE errCode = BC_ERR_NOERROR;
    uint8_t selNode = (uint8_t)RX_ATBNodes;
    uint16_t AtbControlAdress = 0x0204;

    // RX_ConnectATBNode
    uint32_t AtbControl = (uint32_t)selNode + ATB1_EN_BIT;
	errCode = atb1Read(IPNum,AtbControlAdress, AtbControl, voltageMilliVolt);

    return errCode;
}

static BC_ERRCODE rxVoltageRead(SYS_IPNum_e IPNum, ATB_RXVoltages_t *pRXVoltages)
{
    BC_ERRCODE errCode = BC_ERR_NOERROR;
    float32_t voltageMilliVolt = 0.0f;

    errCode = rxAtbRead(IPNum,e_RX_NODE_VDDD_1V1, &voltageMilliVolt);
    if (errCode == BC_ERR_NOERROR)
    {
    	pRXVoltages->RX_NODE_VDDD_1V1 = floatToUint16((11.0f/3.0f)*voltageMilliVolt);
		errCode = rxAtbRead(IPNum,e_RX_NODE_VDDA_1V1, &voltageMilliVolt);
    }
    if (errCode == BC_ERR_NOERROR)
    {
    	pRXVoltages->RX_NODE_VDDA_1V1 = floatToUint16((11.0f/3.0f)*voltageMilliVolt);
		errCode = rxAtbRead(IPNum,e_RX_NODE_VDDA_1V8, &voltageMilliVolt);
    }
    if (errCode == BC_ERR_NOERROR)
    {
    	pRXVoltages->RX_NODE_VDDA_1V8 = floatToUint16(6.0f*voltageMilliVolt);
    }

    return errCode;
}

static BC_ERRCODE allRxVoltageRead(ATB_RXVoltages_t *pRX1Voltages, ATB_RXVoltages_t *pRX2Voltages, ATB_RXVoltages_t *pRX3Voltages, ATB_RXVoltages_t *pRX4Voltages)
{
    BC_ERRCODE errCode = BC_ERR_NOERROR;
    // Enable RX and LNA locally
    errCode = BC_RX_ConfigLocalCtrl(e_SYS_RXMC, TRUE, TRUE);

    if (errCode == BC_ERR_NOERROR)
    {
       errCode =  rxVoltageRead(e_SYS_RX1, pRX1Voltages);
    }
    if (errCode == BC_ERR_NOERROR)
    {
       errCode =  rxVoltageRead(e_SYS_RX2, pRX2Voltages);
    }
    if (errCode == BC_ERR_NOERROR)
    {
       errCode =  rxVoltageRead(e_SYS_RX3, pRX3Voltages);
    }
    if (errCode == BC_ERR_NOERROR)
    {
       errCode =  rxVoltageRead(e_SYS_RX4, pRX4Voltages);
    }
    // Disable RX and LNA locally
    if (errCode == BC_ERR_NOERROR)
    {
        errCode = BC_RX_ConfigLocalCtrl(e_SYS_RXMC, FALSE, FALSE);
    }

    return errCode;
}

static BC_ERRCODE ssbAtbRead(SSB_ATBNodes_e SSB_ATBNodes, float32_t *voltageMilliVolt)
// available supply nodes e_SSB_NODE_VDDA_1V8 (divide by 6, ball N11), e_SSB_NODE_VDDA_1V1 (divide by 11/3, internal)
// e_SSB_NODE_VDDD_1V1 (divide by 11/3, ball N3)
{
    BC_ERRCODE errCode = BC_ERR_NOERROR;
    uint8_t selNode = (uint8_t)SSB_ATBNodes;
    uint16_t AtbControlAdress = 0x0204;
    SYS_IPNum_e IPNum = e_SYS_SSB;

    // SSB_ConnectATBNode
    uint32_t AtbControl = (uint32_t)selNode + ATB1_EN_BIT;
	errCode = atb1Read(IPNum,AtbControlAdress, AtbControl, voltageMilliVolt);

    return errCode;
}

static BC_ERRCODE ssbVoltageRead(ATB_SSBVoltages_t *pSSBVoltages)
{
    BC_ERRCODE errCode = BC_ERR_NOERROR;
    float32_t voltageMilliVolt = 0.0f;

    errCode = BC_SSB_ChangePowerState(TRUE);
    if (errCode == BC_ERR_NOERROR)
    {
    	errCode = ssbAtbRead(e_SSB_NODE_VDDD_1V1, &voltageMilliVolt);
    }
    if (errCode == BC_ERR_NOERROR)
    {
    	pSSBVoltages->SSB_NODE_VDDD_1V1 = floatToUint16((11.0f/3.0f)*voltageMilliVolt);
		errCode = ssbAtbRead(e_SSB_NODE_VDDA_1V1, &voltageMilliVolt);
    }
    if (errCode == BC_ERR_NOERROR)
    {
    	pSSBVoltages->SSB_NODE_VDDA_1V1 = floatToUint16((11.0f/3.0f)*voltageMilliVolt);
		errCode = ssbAtbRead(e_SSB_NODE_VDDA_1V8, &voltageMilliVolt);
    }
    if (errCode == BC_ERR_NOERROR)
    {
    	pSSBVoltages->SSB_NODE_VDDA_1V8 = floatToUint16(6.0f*voltageMilliVolt);
    }
    if (errCode == BC_ERR_NOERROR)
    {
        errCode = BC_SSB_ChangePowerState(FALSE);
    }
    return errCode;
}

static BC_ERRCODE txAtbRead(SYS_IPNum_e IPNum, TX_ATBNodes_e TX_ATBNodes, float32_t *voltageMilliVolt)
// available supply nodes e_TX_NODE_VDDA_1V1 (divide by 11/3, ball M3), e_TX_NODE_VDDD_1V1_FS (divide by 11/3, ball N3),
// e_TX_NODE_VDDA_1V8 (divide by 6, ball TX1=F3&D3, TX2=H3&G3, TX3=L3&J3)
{
    BC_ERRCODE errCode = BC_ERR_NOERROR;
    uint8_t selNode =(uint8_t)TX_ATBNodes;
    uint16_t AtbControlAdress = 0x0254;
    // TX_ConnectATBNode
    uint32_t AtbControl = (uint32_t)selNode + ATB1_EN_BIT;

	errCode = atb1Read(IPNum, AtbControlAdress, AtbControl, voltageMilliVolt);
    return errCode;
}

static BC_ERRCODE txVoltageRead(SYS_IPNum_e IPNum, ATB_TXVoltages_t *pTXVoltages)
{
    BC_ERRCODE errCode = BC_ERR_NOERROR;
    float32_t voltageMilliVolt = 0.0f;

    errCode = txAtbRead(IPNum,e_TX_NODE_VDDA_1V1, &voltageMilliVolt);
    if (errCode == BC_ERR_NOERROR)
    {
        pTXVoltages->TX_NODE_VDDA_1V1 = floatToUint16((11.0f/3.0f)*voltageMilliVolt);
        errCode = txAtbRead(IPNum,e_TX_NODE_VDDD_1V1_FS, &voltageMilliVolt);
    }
    if (errCode == BC_ERR_NOERROR)
    {
        pTXVoltages->TX_NODE_VDDD_1V1_FS = floatToUint16((11.0f/3.0f)*voltageMilliVolt);
        errCode = txAtbRead(IPNum,e_TX_NODE_VDDA_1V8, &voltageMilliVolt);
    }
    if (errCode == BC_ERR_NOERROR)
    {
    	pTXVoltages->TX_NODE_VDDA_1V8 = floatToUint16(6.0f*voltageMilliVolt);
    }

    return errCode;
}

static BC_ERRCODE allTxVoltageRead(ATB_TXVoltages_t *pTX1Voltages,ATB_TXVoltages_t *pTX2Voltages,ATB_TXVoltages_t *pTX3Voltages)
{
    BC_ERRCODE errCode = BC_ERR_NOERROR;
    // Enable TX and TX fast switch locally
    errCode =  BC_TX_ConfigLocalCtrl(e_SYS_TXMC, FALSE, FALSE, FALSE, 0.0f, TRUE, TRUE);

    if (errCode == BC_ERR_NOERROR)
    {
    	errCode =  txVoltageRead(e_SYS_TX1, pTX1Voltages);
    }
    if (errCode == BC_ERR_NOERROR)
    {
       errCode =  txVoltageRead(e_SYS_TX2, pTX2Voltages);
    }
    if (errCode == BC_ERR_NOERROR)
    {
       errCode =  txVoltageRead(e_SYS_TX3, pTX3Voltages);
    }
    // Disable TX and TX fast switch locally
    if (errCode == BC_ERR_NOERROR)
    {
    	errCode =  BC_TX_ConfigLocalCtrl(e_SYS_TXMC, FALSE, FALSE, FALSE, 0.0f, FALSE, FALSE);
    }
    return errCode;
}

static BC_ERRCODE disableAtbReading(
		R2M00_DynamicPowerControlEnableUnion_t DynamicPowerControlRestore,
		R2M14_SsbmodControlUnion_t SSBModControlRestore,
		R2M00_LdoEnableUnion_t EnableLDORestore,
		R2M00_IpLevelClockEnableUnion_t IpLevelClockEnableRestore,
		R2M00_IpResetControlUnion_t IpResetControlRestore,
		R2M00_IpLevelPonEnableUnion_t IpLevelPonEnableRestore,
		R2M00_IpFunctionalResetControlUnion_t IpFunctionalResetReleaseRestore)
{
	BC_ERRCODE errCode = BC_ERR_NOERROR;
	uint32_t LdoATBEn = 0u;
	uint32_t AtbACEnableValue = 0u;

	// Disable ATB local LDO
	errCode = BC_SPI_WriteCheck(e_SYS_ATB, (uint16_t) 0x001C, LdoATBEn);
	// Disconnect DC ATB bus from ATB1 BIST ADC and Connect to ground
	if (errCode == BC_ERR_NOERROR)
	{
		AtbACEnableValue = 17891328u;
		errCode = BC_SPI_WriteCheck(e_SYS_CC, (uint16_t) 0x0508, AtbACEnableValue);
	}
	// Restore Dynamic power down settings
	if (errCode == BC_ERR_NOERROR)
	{
		errCode = BC_SPI_Write(e_SYS_CC, R2M00_DYNAMIC_POWER_CONTROL_ENABLE_U16, DynamicPowerControlRestore.val_u32);
	}
	// Restore SSBMod control settings
	if (errCode == BC_ERR_NOERROR)
	{
		errCode = BC_SPI_WriteCheck(e_SYS_SSB, R2M14_SSBMOD_CONTROL_U16, SSBModControlRestore.val_u32);
	}
	// Restore LDO enable settings
	if (errCode == BC_ERR_NOERROR)
	{
		errCode = BC_SPI_WriteCheck(e_SYS_CC, R2M00_LDO_ENABLE_U16,	EnableLDORestore.val_u32);
	}
	// Restore IP CLK enable settings
	if (errCode == BC_ERR_NOERROR)
	{
		errCode = BC_SPI_WriteCheck(e_SYS_CC, R2M00_IP_LEVEL_CLOCK_ENABLE_U16, IpLevelClockEnableRestore.val_u32);
	}
	// Restore IP Reset settings
	if (errCode == BC_ERR_NOERROR)
	{
		errCode = BC_SPI_WriteCheck(e_SYS_CC, R2M00_IP_RESET_CONTROL_U16, IpResetControlRestore.val_u32);
	}
	// Restore IP Enable settings
	if (errCode == BC_ERR_NOERROR)
	{
		errCode = BC_SPI_WriteCheck(e_SYS_CC, R2M00_IP_LEVEL_PON_ENABLE_U16, IpLevelPonEnableRestore.val_u32);
	}
	// Restore IP Functional Reset settings
	if (errCode == BC_ERR_NOERROR)
	{
		errCode = BC_SPI_WriteCheck(e_SYS_CC, R2M00_IP_FUNCTIONAL_RESET_CONTROL_U16, IpFunctionalResetReleaseRestore.val_u32);
	}
	return errCode;
}

static BC_ERRCODE readATBVoltages(rfe_tef82xxVoltages_t *pVoltages)
{
	BC_ERRCODE errCode = BC_ERR_NOERROR;
	rfeDriverPersistentMem_t *pDrvState = RfeDrvStateGet();

	//Read ADC ATB Nodes

	errCode = allAdcVoltageRead(&pVoltages->ADC12Voltages,
			&pVoltages->ADC34Voltages);

	//Read ATB ATB Nodes
	if (errCode == BC_ERR_NOERROR) {
		errCode = atbVoltageRead(&pVoltages->ATBVoltages);
	}
	//Read CAFC ATB Nodes only for Leader Front End
	if ((errCode == BC_ERR_NOERROR) && (pDrvState->frontendMode != RFE_CASCADING_FOLLOWER)) {
		errCode = cafcVoltageRead(&pVoltages->CAFCVoltages);
	}
	//Read GBIAS ATB Nodes
	if (errCode == BC_ERR_NOERROR) {
		errCode = gbiasVoltageRead(&pVoltages->GBIASVoltages);
	}
	//Read GLDO ATB Nodes
	if (errCode == BC_ERR_NOERROR) {
		errCode = gldoVoltageRead(&pVoltages->GLDOVoltages);
	}
	//Read LOI ATB Nodes
	if (errCode == BC_ERR_NOERROR) {
		errCode = loiVoltageRead(&pVoltages->LOIVoltages);
	}
	//Read MCLK ATB Nodes
	if (errCode == BC_ERR_NOERROR) {
		errCode = mclkVoltageRead(&pVoltages->MCLKVoltages);
	}
	//Read MIPI ATB Nodes
	if (errCode == BC_ERR_NOERROR) {
		errCode = mipiVoltageRead(&pVoltages->MIPIVoltages);
	}
	//Read RX ATB Nodes
	if (errCode == BC_ERR_NOERROR) {
		errCode = allRxVoltageRead(&pVoltages->RX1Voltages,
				&pVoltages->RX2Voltages, &pVoltages->RX3Voltages,
				&pVoltages->RX4Voltages);
	}
	//Read SSB ATB Nodes
	if (errCode == BC_ERR_NOERROR) {
		errCode = ssbVoltageRead(&pVoltages->SSBVoltages);
	}
	//Read TX ATB Nodes
	if (errCode == BC_ERR_NOERROR) {
		errCode = allTxVoltageRead(&pVoltages->TX1Voltages,
				&pVoltages->TX2Voltages, &pVoltages->TX3Voltages);
	}
	return errCode;
}

static BC_ERRCODE enableAtbVoltageReading(
		R2M00_DynamicPowerControlEnableUnion_t *DynamicPowerControlRestore,
		R2M14_SsbmodControlUnion_t *SSBModControlRestore,
		R2M00_LdoEnableUnion_t *EnableLDORestore,
		R2M00_IpLevelClockEnableUnion_t *IpLevelClockEnableRestore,
		R2M00_IpResetControlUnion_t *IpResetControlRestore,
		R2M00_IpLevelPonEnableUnion_t *IpLevelPonEnableRestore,
		R2M00_IpFunctionalResetControlUnion_t *IpFunctionalResetReleaseRestore)
{
	BC_ERRCODE errCode = BC_ERR_NOERROR;

	R2M00_LdoEnableUnion_t EnableLDO;
	R2M00_IpLevelClockEnableUnion_t IpLevelClockEnable;
	R2M00_IpResetControlUnion_t IpResetControl;
	R2M14_SsbmodControlUnion_t SSBModControl;
	R2M00_IpLevelPonEnableUnion_t IpLevelPonEnable;
	R2M00_IpFunctionalResetControlUnion_t IpFunctionalResetRelease;
	R2M00_DynamicPowerControlEnableUnion_t EnableDynamicPow;

	// Enable the LDO of the SSB
	errCode = BC_SPI_Read(e_SYS_CC, R2M00_LDO_ENABLE_U16, &EnableLDO.val_u32);
	if (errCode == BC_ERR_NOERROR)
	{
		EnableLDORestore->val_u32 = EnableLDO.val_u32;
		EnableLDO.bits_st.LdoEnSsbmod = BIT_ENABLE;
		errCode = BC_SPI_WriteCheck(e_SYS_CC, R2M00_LDO_ENABLE_U16,	EnableLDO.val_u32);
	}
	if (errCode == BC_ERR_NOERROR)
	{
		//Add delay 20us
		RfeHwDelayUs(SSB_ENABLELDO_SLEEP);
	}
	// Enable the clocks of SSB and ATB
	if (errCode == BC_ERR_NOERROR)
	{
		errCode = BC_SPI_Read(e_SYS_CC, R2M00_IP_LEVEL_CLOCK_ENABLE_U16, &IpLevelClockEnable.val_u32);
	}
	if (errCode == BC_ERR_NOERROR)
	{
		IpLevelClockEnableRestore->val_u32 = IpLevelClockEnable.val_u32;
		IpLevelClockEnable.bits_st.Clk40Atb = BIT_ENABLE;
		IpLevelClockEnable.bits_st.Clk40Ssbmod = BIT_ENABLE;
		errCode = BC_SPI_WriteCheck(e_SYS_CC, R2M00_IP_LEVEL_CLOCK_ENABLE_U16, IpLevelClockEnable.val_u32);
	}
	// Release the reset of SSB and ATB
	if (errCode == BC_ERR_NOERROR)
	{
		errCode = BC_SPI_Read(e_SYS_CC, R2M00_IP_RESET_CONTROL_U16,	&IpResetControl.val_u32);
	}
	if (errCode == BC_ERR_NOERROR)
	{
		IpResetControlRestore->val_u32 = IpResetControl.val_u32;
		IpResetControl.bits_st.ResetAtb = BIT_ENABLE;
		IpResetControl.bits_st.ResetSsbmod = BIT_ENABLE;
		errCode = BC_SPI_WriteCheck(e_SYS_CC, R2M00_IP_RESET_CONTROL_U16, IpResetControl.val_u32);
	}
	// Distribute OTP data for the SSB (this is not reverted)
	if (errCode == BC_ERR_NOERROR)
	{
		errCode = BC_OTP_DistributeOTPData(e_OTP_SPARE_TRIM, (OTP_SPARE_TRIM_COUNT - 1u), OTP_SPARE_TRIM_COUNT);
	}
	// Enable the SSB locally
	if (errCode == BC_ERR_NOERROR)
	{
		errCode = BC_SPI_Read(e_SYS_SSB, R2M14_SSBMOD_CONTROL_U16, &SSBModControl.val_u32);
	}
	if (errCode == BC_ERR_NOERROR)
	{
		SSBModControlRestore->val_u32 = SSBModControl.val_u32;
		SSBModControl.bits_st.SsbmodEn = BIT_ENABLE;
		errCode = BC_SPI_WriteCheck(e_SYS_SSB, R2M14_SSBMOD_CONTROL_U16, SSBModControl.val_u32);
	}
	// Distribute OTP data for the ATB (this is not reverted)
	if (errCode == BC_ERR_NOERROR)
	{
		errCode = BC_OTP_DistributeOTPData(e_OTP_TRIM_LOCAL_LDO, 1u, 2u);
	}
	// Enable ATB module
	if (errCode == BC_ERR_NOERROR)
	{
		errCode = BC_SPI_Read(e_SYS_CC, R2M00_IP_LEVEL_PON_ENABLE_U16, &IpLevelPonEnable.val_u32);
	}
	if (errCode == BC_ERR_NOERROR)
	{
		IpLevelPonEnableRestore->val_u32 = IpLevelPonEnable.val_u32;
		IpLevelPonEnable.bits_st.PonAtbEn = BIT_ENABLE;
		errCode = BC_SPI_WriteCheck(e_SYS_CC, R2M00_IP_LEVEL_PON_ENABLE_U16, IpLevelPonEnable.val_u32);
	}
	// Release the functional reset of SSB and ATB
	if (errCode == BC_ERR_NOERROR)
	{
		errCode = BC_SPI_Read(e_SYS_CC, R2M00_IP_FUNCTIONAL_RESET_CONTROL_U16, &IpFunctionalResetRelease.val_u32);
	}
	if (errCode == BC_ERR_NOERROR)
	{
		IpFunctionalResetReleaseRestore->val_u32 = IpFunctionalResetRelease.val_u32;
		IpFunctionalResetRelease.bits_st.FnResetAtb = BIT_ENABLE;
		IpFunctionalResetRelease.bits_st.FnResetSsbmod = BIT_ENABLE;
		errCode = BC_SPI_WriteCheck(e_SYS_CC, R2M00_IP_FUNCTIONAL_RESET_CONTROL_U16, IpFunctionalResetRelease.val_u32);
	}
	// Get all IP out of dynamic power down
	if (errCode == BC_ERR_NOERROR)
	{
		errCode = BC_SPI_Read(e_SYS_CC, R2M00_DYNAMIC_POWER_CONTROL_ENABLE_U16,	&EnableDynamicPow.val_u32);
	}
	if (errCode == BC_ERR_NOERROR)
	{
		DynamicPowerControlRestore->val_u32 = EnableDynamicPow.val_u32;
		EnableDynamicPow.bits_st.AdcDyPowerControl = BIT_DISABLE;
		EnableDynamicPow.bits_st.ChirpDyPowerControl = BIT_DISABLE;
		EnableDynamicPow.bits_st.Rx1DyPowerControl = BIT_DISABLE;
		EnableDynamicPow.bits_st.Rx2DyPowerControl = BIT_DISABLE;
		EnableDynamicPow.bits_st.Rx3DyPowerControl = BIT_DISABLE;
		EnableDynamicPow.bits_st.Rx4DyPowerControl = BIT_DISABLE;
		EnableDynamicPow.bits_st.Tx1DyPowerControl = BIT_DISABLE;
		EnableDynamicPow.bits_st.Tx2DyPowerControl = BIT_DISABLE;
		EnableDynamicPow.bits_st.Tx3DyPowerControl = BIT_DISABLE;
		EnableDynamicPow.bits_st.LoInterfaceDyPowerControl = BIT_DISABLE;
		errCode = BC_SPI_Write(e_SYS_CC, R2M00_DYNAMIC_POWER_CONTROL_ENABLE_U16, EnableDynamicPow.val_u32);
	}
	// Enable ATB local LDO (this LDO supplies BISTADCs and their buffers)
	if (errCode == BC_ERR_NOERROR)
	{
		uint32_t LdoATBEn = 1u;
		errCode = BC_SPI_WriteCheck(e_SYS_ATB, (uint16_t) 0x001C, LdoATBEn);
	}
	// Connect DC ATB bus to ATB1 BIST ADC and Disconnect ground
	if (errCode == BC_ERR_NOERROR)
	{
		uint32_t AtbACEnableValue = 17891331UL;
		errCode = BC_SPI_WriteCheck(e_SYS_CC, (uint16_t) 0x0508,
				AtbACEnableValue);
	}
	return errCode;
}

static BC_ERRCODE atbMultiModuleVoltageRead(rfe_tef82xxVoltages_t *pVoltages)
{
	BC_ERRCODE errCode = BC_ERR_NOERROR;

	R2M00_IpLevelPonEnableUnion_t IpLevelPonEnableRestore;
	R2M00_IpFunctionalResetControlUnion_t IpFunctionalResetReleaseRestore;
	R2M00_DynamicPowerControlEnableUnion_t DynamicPowerControlEnable;
	R2M00_IpLevelClockEnableUnion_t IpLevelClockEnableRestore;
	R2M00_LdoEnableUnion_t EnableLDORestore;
	R2M00_IpResetControlUnion_t IpResetControlRestore;
	R2M14_SsbmodControlUnion_t SSBModControlRestore;

	IpLevelPonEnableRestore.val_u32 = 0UL;
	IpFunctionalResetReleaseRestore.val_u32 = 0UL;
	DynamicPowerControlEnable.val_u32 = 0UL;
	IpLevelClockEnableRestore.val_u32 = 0UL;
	EnableLDORestore.val_u32 = 0UL;
	IpResetControlRestore.val_u32 = 0UL;
	SSBModControlRestore.val_u32 = 0UL;

    errCode = enableAtbVoltageReading(&DynamicPowerControlEnable,
			&SSBModControlRestore, &EnableLDORestore,
			&IpLevelClockEnableRestore, &IpResetControlRestore,
			&IpLevelPonEnableRestore, &IpFunctionalResetReleaseRestore);

	if (errCode == BC_ERR_NOERROR)
	{
		RfeHwDelayUs(1000U);
	}
    //Read ADC ATB Nodes
    if (errCode == BC_ERR_NOERROR)
	{
    	errCode = readATBVoltages(pVoltages);
	}
    if (errCode == BC_ERR_NOERROR)
	{
		errCode = disableAtbReading(DynamicPowerControlEnable,
				SSBModControlRestore, EnableLDORestore,
				IpLevelClockEnableRestore, IpResetControlRestore,
				IpLevelPonEnableRestore, IpFunctionalResetReleaseRestore);
	}
	return errCode;
}

/*==================================================================================================
 *                                      PUBLIC FUNCTIONS
 ==================================================================================================*/

void rfeSwStatusTef82xxDeviceStatus(rfeStatusReport_t* pDevStatus, rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE errCode = BC_ERR_NOERROR;

	if (*rfe___error___pointer == rfe_error_none_e)
	{
		if (pDevStatus != NULL)
		{
			// get temperature
			errCode = GetTemperature(pDevStatus);
			if(errCode != BC_ERR_NOERROR)
			{
				*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
			}
		}
		else
		{
			*rfe___error___pointer = rfe_error_nullPointer_e;
		}
	}
}

void rfeFusaStatusTef82xxDeviceStatus(uint8_t *pFusaFaults, rfe_error_t* rfe___error___pointer)
{
	uint32_t maskedErrorStatus;
	BC_ERRCODE  errCode;
	bool crcError = false;

	//Initialize FUSA faults array
	for( uint8_t arrIndex = 0U; arrIndex < RFE_FUSA_R1_R2_MASK_UNMASK_FAULT_BYTE_COUNT; arrIndex ++ )
	{
		pFusaFaults[ arrIndex ] = 0U;
	}
	// Read out errors from TX
	errCode = BC_ISM_GetTxErrStatus(e_ISM_GET_MASKED_ERR, NULL, NULL, NULL, &maskedErrorStatus );
	if(errCode == BC_ERR_NOERROR)
	{
		//Check TX CRC bits
		if((maskedErrorStatus & TX_CRC_MASKED_ERROR_STATUS_MASK ) > 0UL)
		{
			crcError = true;
		}
		// Set TX FUSA bits in the report
		SetFuSaReportBits( maskedErrorStatus, pFusaFaults, TxFuSaStatusToFuSaErrorsMapper, txStatusResponseUsedBits, TX_STATUS_RESPONSE_USED_BITS_SIZE );
		errCode = BC_ISM_GetRxErrStatus( e_ISM_GET_MASKED_ERR, NULL, NULL, NULL, NULL, &maskedErrorStatus );
	}
	if( errCode == BC_ERR_NOERROR )
	{
		//Check RX CRC bits
		if ( ( maskedErrorStatus & RX_CRC_MASKED_ERROR_STATUS_MASK ) > 0UL )
		{
			crcError = true;
		}
		// Set RX FUSA bits in the report
		SetFuSaReportBits( maskedErrorStatus, pFusaFaults, RxFuSaStatusToFuSaErrorsMapper, rxStatusResponseUsedBits, RX_STATUS_RESPONSE_USED_BITS_SIZE );
		errCode = BC_ISM_GetChirpErrStatus( e_ISM_GET_MASKED_ERR, NULL, &maskedErrorStatus );
	}
	if( errCode == BC_ERR_NOERROR )
	{
		//Check chirp CRC bits
		if ( ( maskedErrorStatus & CHIRP_CRC_MASKED_ERROR_STATUS_MASK ) > 0UL )
		{
			crcError = true;
		}
		// Set chirp FUSA bits in the report
		SetFuSaReportBits( maskedErrorStatus, pFusaFaults, ChripFuSaStatusToFuSaErrorsMapper, chirpStatusResponseUsedBits, CHIRP_STATUS_RESPONSE_USED_BITS_SIZE );
		errCode  = BC_ISM_GetMClkLOISMOTPErrStatus( e_ISM_GET_MASKED_ERR, NULL, NULL, NULL, NULL, NULL, &maskedErrorStatus );
	}
	if( errCode == BC_ERR_NOERROR )
	{
		//Check MCLK/LOI/ISM/OTP CRC bits
		if ( ( maskedErrorStatus & MCLOISMOTP_CRC_MASKED_ERROR_STATUS_MASK ) > 0UL )
		{
			crcError = true;
		}
		// Set MCLK/LOI/ISM/OTP FUSA bits in the report
		SetFuSaReportBits( maskedErrorStatus, pFusaFaults, McLoIsmOtpFuSaStatusToFuSaErrorsMapper, mcLoIsmOtpStatusResponseUsedBits, MCLOISMOTP_STATUS_RESPONSE_USED_BITS_SIZE );
		errCode = BC_ISM_GetSSBSerGBGLDOATBErr(e_ISM_GET_MASKED_ERR, NULL, NULL, NULL, NULL, NULL, &maskedErrorStatus );
	}
	if( errCode == BC_ERR_NOERROR )
	{
		//Check SSB/SER/GBIAS/GLDO/ATB CRC bits
		if((maskedErrorStatus & SSBSERGBLDOATB_CRC_MASKED_ERROR_STATUS_MASK) > 0UL )
		{
			crcError = true;
		}
		// Set SSB/SER/GBIAS/GLDO/ATB FUSA bits in the report
		SetFuSaReportBits( maskedErrorStatus, pFusaFaults, SsbSerGbLdoAtbFuSaStatusToFuSaErrorsMapper, ssbSerGbLdoAtbStatusResponseUsedBits, SSBSERGBLDOATB_STATUS_RESPONSE_USED_BITS_SIZE );
		errCode = BC_ISM_GetADCErrStatus(e_ISM_GET_MASKED_ERR, NULL, NULL, &maskedErrorStatus);
	}
	if(errCode == BC_ERR_NOERROR)
	{
		//Check ADC CRC bits
		if((maskedErrorStatus & ADC_CRC_MASKED_ERROR_STATUS_MASK ) > 0UL )
		{
			crcError = true;
		}
		// Set ADC FUSA bits in the report
		SetFuSaReportBits( maskedErrorStatus, pFusaFaults, AdcFuSaStatusToFuSaErrorsMapper, adcStatusResponseUsedBits, ADC_STATUS_RESPONSE_USED_BITS_SIZE );
		if ( crcError == true )
		{
			// Set CRC bit in the report
			pFusaFaults[ REG_CRC_FUSA_FAULT_REPORT_INDEX ] |= (1U << REG_CRC_FUSA_FAULT_REPORT_BITPOS);
		}
		// set SW eror bits in the report
		reportSwErrorStatus(  pFusaFaults );
	}
	if(errCode != BC_ERR_NOERROR)
	{
		*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
	}
}

void setSwError( rfe_error_t* rfe___error___pointer )
{
	uint8_t     fe = 0U;
	rfe_error_t err = rfe_error_none_e;

	if(*rfe___error___pointer != rfe_error_none_e)
	{
		fe = (uint8_t)((uint32_t)*rfe___error___pointer >> 8U) & 0x0FU;
		err = (rfe_error_t)((uint32_t)*rfe___error___pointer & 0xFFFFF0FFUL);

		switch(err)
		{
			case rfe_error_rxbist_lna_gain_fail_e:
			{
				SetSwErrorStatus(fe, rfe_sw_fuSaFault_sr31_bist_lna_gaindiff_index_e, rfe___error___pointer);
				break;
			}
			case rfe_error_rxbist_lna_phase_fail_e:
			{
				SetSwErrorStatus(fe, rfe_sw_fuSaFault_sr31_bist_lna_phasediff_index_e, rfe___error___pointer);
				break;
			}
			case rfe_error_rxbist_mixer_gain_fail_e:
			{
				SetSwErrorStatus(fe, rfe_sw_fuSaFault_sr31_bist_mixer_gaindiff_index_e, rfe___error___pointer);
				break;
			}
			case rfe_error_rxbist_mixer_phase_fail_e:
			{
				SetSwErrorStatus(fe, rfe_sw_fuSaFault_sr31_bist_mixer_phasediff_index_e, rfe___error___pointer);
				break;
			}
			case rfe_error_bc_sys_cafcIntegrityCheckLevel:
			{
				SetSwErrorStatus(fe, rfe_sw_fuSaFault_sr44_cafc_integrity_level_index_e, rfe___error___pointer);
				break;
			}
			case rfe_error_bc_sys_cafcIntegrityCheckUnlock:
			{
				SetSwErrorStatus(fe, rfe_sw_fuSaFault_sr44_cafc_integrity_unlock_index_e, rfe___error___pointer);
				break;
			}
			case rfe_error_bc_sys_cafcIntegrityCheckFailed:
			{
				SetSwErrorStatus(fe, rfe_sw_fuSaFault_sr44_cafc_integrity_index_e, rfe___error___pointer);
				break;
			}
			case rfe_error_bc_txSensorFitFail:
			{
				SetSwErrorStatus(fe, rfe_sw_fuSaFault_sr70_tx_integrity_index_e, rfe___error___pointer);
				break;
			}
			case rfe_error_bc_txSafetyError:
			{
				SetSwErrorStatus(fe, rfe_sw_fuSaFault_sr72_tx_pr_cal_index_e, rfe___error___pointer);
				break;
			}
			case rfe_error_bc_tx1SafetyError:
			{
				SetSwErrorStatus(fe, rfe_sw_fuSaFault_sr72_tx1_pr_cal_index_e, rfe___error___pointer);
				break;
			}
			case rfe_error_bc_tx2SafetyError:
			{
				SetSwErrorStatus(fe, rfe_sw_fuSaFault_sr72_tx2_pr_cal_index_e, rfe___error___pointer);
				break;
			}
			case rfe_error_bc_tx3SafetyError:
			{
				SetSwErrorStatus(fe, rfe_sw_fuSaFault_sr72_tx3_pr_cal_index_e, rfe___error___pointer);
				break;
			}
			case rfe_error_bc_ismDisableLbToggleTestFailed:
			{
				SetSwErrorStatus(fe, rfe_sw_fuSaFault_sr14_disable_lb_toggle_test_index_e, rfe___error___pointer);
				break;
			}
			case rfe_error_bc_ismInputModeToggleTestFailed:
			{
				SetSwErrorStatus(fe, rfe_sw_fuSaFault_sr13_input_mode_toggle_test_index_e, rfe___error___pointer);
				break;
			}
			default: // non-fusa error is triggered, set sw generic bit to 1
			{
				swErrorStatus[rfe_sw_generic_index_e][fe] = TRUE;
				break;
			}
		}
	}
}

uint8_t GetBcdModuleRegistersDump(uint8_t fe, uint8_t moduleId, uint8_t regindex, uint32_t* regDump, rfe_error_t* rfe___error___pointer)
{
	uint8_t feActual = RfeDrvStateFrontendIdGet();
	BC_ERRCODE   errCode = BC_ERR_NOERROR;
	uint16_t* pRegAddress = NULL;
	uint8_t regCount = 0U;
	uint16_t regIdx = 0U, regArrayIdx = 0U;
	uint8_t regSize = 0U;
	uint16_t regAddress = 0U;

	if(*rfe___error___pointer == rfe_error_none_e)
	{
		rfeSwUtils_SelectFe(fe);
		if(moduleId == (uint8_t)rfe_bcd_otp_table_e)
		{
			regCount = RFE_OTP_TABLE_NUMBER;
		}
		else
		{
			regCount = GetModuleRegistersCount(moduleId, &pRegAddress);
		}
		regSize = regCount;
		if((regCount == 0U) || (regindex > regCount))
		{
			*rfe___error___pointer = rfe_error_parameterOutOfRange_e;
		}
	}
	if(*rfe___error___pointer == rfe_error_none_e)
	{
		if((regCount - regindex) > REG_MAX_COUNT_TO_SEND)
		{
			regSize = regindex + REG_MAX_COUNT_TO_SEND;
		}
		for(regIdx = regindex; regIdx < regSize; ++regIdx)
		{
			if(errCode != BC_ERR_NOERROR)
			{
				break;
			}

			if(moduleId != (uint8_t)rfe_bcd_otp_table_e)
			{
				regAddress = pRegAddress[regIdx];
				errCode = BC_SPI_Read((SYS_IPNum_e)moduleId, regAddress, &regDump[regArrayIdx]);
			}
			else
			{
				errCode = BC_OTP_GetOTPRegValue(regIdx, &regDump[regArrayIdx]);
			}
			regArrayIdx++;
		}
		if (errCode != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}
		rfeSwUtils_SelectFe(feActual);
	}
	return (uint8_t)(regSize - regindex);
}

uint32_t getAtbVoltageMeasurements(uint8_t feIdx, rfe_tef82xxVoltages_t* voltagesPtr, rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE   			errCode = BC_ERR_NOERROR;

	rfeSwUtils_SelectFe(feIdx);
	if(*rfe___error___pointer == rfe_error_none_e)
	{
        errCode = atbMultiModuleVoltageRead(voltagesPtr);
		if (errCode != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}
	}

	return(sizeof(rfe_tef82xxVoltages_t) / sizeof(uint16_t));
}
