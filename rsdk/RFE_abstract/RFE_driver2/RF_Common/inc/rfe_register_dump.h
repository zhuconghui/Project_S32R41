/*
* Copyright 2024 NXP
*
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and
* may only be used strictly in accordance with the applicable license terms.  By
* expressly accepting such terms or by downloading, installing, activating and/or
* otherwise using the software, you are agreeing that you have read, and that you
* agree to comply with and are bound by, such license terms.  If you do not agree to
* be bound by the applicable license terms, then you may not retain, install, activate or
* otherwise use the software.
*/


/******************************************************************************
 *   Project              : RF_Abstract_2.0
 *   Platform             : S32R41
 *****************************************************************************/

#ifndef RFE_REGISTER_DUMP_H
#define RFE_REGISTER_DUMP_H

/******************************************************************************
 *                              INCLUDES
 *****************************************************************************/

#include "rfe_types.h"

#ifdef __cplusplus
extern "C"
{
#endif

/**
*   @addtogroup rsdk_rfe_api_const
*   @{
*/

/******************************************************************************
 *                              DEFINES AND TYPES
 *****************************************************************************/
#define REG_MAX_COUNT_TO_SEND                               58U

/** Number Central Control (0x00) registers. */
#define RFE_CC_REG_NUMBER                                   68U
/** Number LVDS Module (0x01) registers. */
#define RFE_LDVS_REG_NUMBER                                 46U
/** Number CSI2 Module (0x02) registers. */
#define RFE_CSI2_REG_NUMBER                                 71U
/** Number Timing Engine (0x04) registers. */
#define RFE_TE_REG_NUMBER                                   71U
/** Number Sweep Control (0x05) registers. */
#define RFE_SC_REG_NUMBER                                   70U
/** Number Chirp AFC (0x06) registers. */
#define RFE_CAFC_REG_NUMBER                                 137U
/** Number ADC12 (0x07) / ADC34 (0x08) registers. */
#define RFE_ADC_REG_NUMBER                                  118U
/** Number Global Bias (0x09) registers. */
#define RFE_GB_REG_NUMBER                                   46U
/** Number LO Interface (0x0A) registers. */
#define RFE_LOI_REG_NUMBER                                  32U
/** Number Master Clock (0x0C) registers. */
#define RFE_MCLK_REG_NUMBER                                 68U
/** Number RX1 (0x0D) / RX2 (0x0E) / RX3 (0x0F) / RX4 (0x10) registers. */
#define RFE_RX_REG_NUMBER                                   72U
/** Number TX1 (0x11) / TX2 (0x12) / TX3 (0x13) registers. */
#define RFE_TX_REG_NUMBER                                   124U
/** Number SSBMOD (0x14) registers. */
#define RFE_SSBMOD_REG_NUMBER                               24U
/** Number Global LDO (0x15) registers. */
#define RFE_GLDO_REG_NUMBER                                 38U
/** Number OTP (0x17) registers. */
#define RFE_OTP_REG_NUMBER                                  19U
/** Number ISM Module (0x18) registers. */
#define RFE_ISM_REG_NUMBER                                  89U
/** Number ISM Table  */
#define RFE_OTP_TABLE_NUMBER                                64U
/** Number ATB voltage Table   */
#define RFE_ATB_VOLTAGE_TABLE_NUMBER                        55U


/**
*   @}
*   @addtogroup rsdk_rfe_api_interface
*   @{
*/


/**
 * This types defines a selection of BBC register dump.
 */
typedef enum
{
    rfe_registerDump_CC                     = 0x00000001UL,
    rfe_registerDump_LDVS                   = 0x00000002UL,
    rfe_registerDump_CSI2                   = 0x00000004UL,
    rfe_registerDump_TE                     = 0x00000010UL,
    rfe_registerDump_SC                     = 0x00000020UL,
    rfe_registerDump_CAFC                   = 0x00000040UL,
    rfe_registerDump_ADC12                  = 0x00000080UL,
    rfe_registerDump_ADC34                  = 0x00000100UL,
    rfe_registerDump_GB                     = 0x00000200UL,
    rfe_registerDump_LOI                    = 0x00000400UL,
    rfe_registerDump_MCLK                   = 0x00001000UL,
    rfe_registerDump_RX1                    = 0x00002000UL,
    rfe_registerDump_RX2                    = 0x00004000UL,
    rfe_registerDump_RX3                    = 0x00008000UL,
    rfe_registerDump_RX4                    = 0x00010000UL,
    rfe_registerDump_TX1                    = 0x00020000UL,
    rfe_registerDump_TX2                    = 0x00040000UL,
    rfe_registerDump_TX3                    = 0x00080000UL,
    rfe_registerDump_SSBMOD                 = 0x00100000UL,
    rfe_registerDump_GLDO                   = 0x00200000UL,
    rfe_registerDump_OTP                    = 0x00800000UL,
    rfe_registerDump_ISM                    = 0x01000000UL,
    rfe_registerDump_OTP_TABLE              = 0x02000000UL,
    rfe_registerDump_ATB_VOLTAGE_READOUT    = 0x04000000UL
}rfe_moduleDumpSelect_t;

/**
 * This type defines the BCD module Id.
 */
typedef enum
{
    rfe_bcd_cc_e            = 0x00U,
    rfe_bcd_lvds_e          = 0x01U,
    rfe_bcd_csi2_e          = 0x02U,
    rfe_bcd_te_e            = 0x04U,
    rfe_bcd_sc_e            = 0x05U,
    rfe_bcd_cafc_e          = 0x06U,
    rfe_bcd_adc12_e         = 0x07U,
    rfe_bcd_adc34_e         = 0x08U,
    rfe_bcd_gb_e            = 0x09U,
    rfe_bcd_loi_e           = 0x0aU,
    rfe_bcd_mclk_e          = 0x0cU,
    rfe_bcd_rx1_e           = 0x0dU,
    rfe_bcd_rx2_e           = 0x0eU,
    rfe_bcd_rx3_e           = 0x0fU,
    rfe_bcd_rx4_e           = 0x10U,
    rfe_bcd_tx1_e           = 0x11U,
    rfe_bcd_tx2_e           = 0x12U,
    rfe_bcd_tx3_e           = 0x13U,
    rfe_bcd_ssbmod_e        = 0x14U,
    rfe_bcd_gldo_e          = 0x15U,
    rfe_bcd_otp_e           = 0x17U,
    rfe_bcd_ism_e           = 0x18U,
    rfe_bcd_otp_table_e     = 0x19U,
    rfe_bcd_atb_voltage_e   = 0x1aU
}rfe_bcdModuleId_t;


/**
 * This structure is a container for BCD register dump to be read via rfe_registerDumpRead().
 */
typedef struct
{
    uint8_t     frontEndId;                 // the frontEndId, numbered from 0, 1, ...
    uint8_t     moduleId;                   // the module Id, as in rfe_bcdModuleId_t
    uint16_t    registerAddress;            // the module registry offset
    uint32_t    value;                      // the reported value in the hw registry
}rfe_registerDumpValues_t;

/**
*   @}
*/

extern uint16_t sw_CC_RegAddress[RFE_CC_REG_NUMBER];
extern uint16_t sw_LDVS_RegAddress[RFE_LDVS_REG_NUMBER];
extern uint16_t sw_CSI2_RegAddress[RFE_CSI2_REG_NUMBER];
extern uint16_t sw_TE_RegAddress[RFE_TE_REG_NUMBER];
extern uint16_t sw_SC_RegAddress[RFE_SC_REG_NUMBER];
extern uint16_t sw_CAFC_RegAddress[RFE_CAFC_REG_NUMBER];
extern uint16_t sw_ADC_RegAddress[RFE_ADC_REG_NUMBER];
extern uint16_t sw_GB_RegAddress[RFE_GB_REG_NUMBER];
extern uint16_t sw_LOI_RegAddress[RFE_LOI_REG_NUMBER];
extern uint16_t sw_MCLK_RegAddress[RFE_MCLK_REG_NUMBER];
extern uint16_t sw_RX_RegAddress[RFE_RX_REG_NUMBER];
extern uint16_t sw_TX_RegAddress[RFE_TX_REG_NUMBER];
extern uint16_t sw_SSBMOD_RegAddress[RFE_SSBMOD_REG_NUMBER];
extern uint16_t sw_GLDO_RegAddress[RFE_GLDO_REG_NUMBER];
extern uint16_t sw_OTP_RegAddress[RFE_OTP_REG_NUMBER];
extern uint16_t sw_ISM_RegAddress[RFE_ISM_REG_NUMBER];

extern uint16_t *registryOffsetArrayPtr[];
extern uint8_t  rfe_regDumpModuleRegLimit[];

/******************************************************************************
 *                              FUNCTIONS
 *****************************************************************************/


#ifdef __cplusplus
}
#endif

#endif /* RFE_REGISTER_DUMP_H */
