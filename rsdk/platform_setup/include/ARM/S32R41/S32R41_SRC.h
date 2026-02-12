/*
** ###################################################################
**     Processor:           S32R41_A53
**     Compiler:            Keil ARM C/C++ Compiler
**     Reference manual:    S32R41 RM Rev.2 Draft A
**     Version:             rev. 1.5, 2022-07-11
**     Build:               b220711
**
**     Abstract:
**         Peripheral Access Layer for S32R41_A53
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2022 NXP
**
**     NXP Confidential. This software is owned or controlled by NXP and may only be
**     used strictly in accordance with the applicable license terms. By expressly
**     accepting such terms or by downloading, installing, activating and/or otherwise
**     using the software, you are agreeing that you have read, and that you agree to
**     comply with and are bound by, such license terms. If you do not agree to be
**     bound by the applicable license terms, then you may not retain, install,
**     activate or otherwise use the software. The production use license in
**     Section 2.3 is expressly granted for this software.
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
** ###################################################################
*/

/*!
 * @file S32R41_SRC.h
 * @version 1.5
 * @date 2022-07-11
 * @brief Peripheral Access Layer for S32R41_SRC
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.3, local typedef not referenced
* The SoC header defines typedef for all modules.
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.5, local macro not referenced
* The SoC header defines macros for all modules and registers.
*
* @section [global]
* Violates MISRA 2012 Advisory Directive 4.9, Function-like macro
* These are generated macros used for accessing the bit-fields from registers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.1, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.2, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.4, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.5, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 21.1, defined macro '__I' is reserved to the compiler
* This type qualifier is needed to ensure correct I/O access and addressing.
*/

/* Prevention from multiple including the same memory map */
#if !defined(S32R41_SRC_H_)  /* Check if memory map has not been already included */
#define S32R41_SRC_H_

#include "S32R41_COMMON.h"

/* ----------------------------------------------------------------------------
   -- SRC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SRC_Peripheral_Access_Layer SRC Peripheral Access Layer
 * @{
 */

/** SRC - Register Layout Typedef */
typedef struct {
  __IO uint32_t SW_NCF;                            /**< Software Triggered Faults, offset: 0x0 */
  __IO uint32_t GMAC_0_CTRL_STS;                   /**< GMAC_0 Control, offset: 0x4 */
  __IO uint32_t GMAC_1_CTRL_REG;                   /**< GMAC_1 Control, offset: 0x8 */
  uint8_t RESERVED_0[4];
  __IO uint32_t CTE_CTRL_REG;                      /**< CTE Control, offset: 0x10 */
  __IO uint32_t CMU_FLL_STATUS_REG;                /**< CMU FLL Status, offset: 0x14 */
  __I  uint32_t TRANSACTION_STAT_REG;              /**< Transaction Status, offset: 0x18 */
  __I  uint32_t TRANSACTION_STAT_2_REG;            /**< Transaction Status 2, offset: 0x1C */
  __IO uint32_t FCCU_EOUT_OVERRIDE_CLEAR_REG;      /**< FCCU EOUT Override Clear, offset: 0x20 */
  __IO uint32_t MIPI_CSI2_REG;                     /**< MIPI CSI2 Control, offset: 0x24 */
  __I  uint32_t TIMEOUT_FAULT_STATUS_REG;          /**< Timeout Fault Status, offset: 0x28 */
  uint8_t RESERVED_1[16];
  __IO uint32_t PERIPHERAL_REGISTER;               /**< Peripheral Control, offset: 0x3C */
  __I  uint32_t PERIPHERAL_ACK_SIGNAL;             /**< Peripheral Acknowledge, offset: 0x40 */
  __IO uint32_t ENET_RT_AHB_GASKET;                /**< GMAC_0 AHB Gasket, offset: 0x44 */
  __IO uint32_t PFAULT_READ_NCF_FAULT_MASKING;     /**< PFAULT Read NCF Fault Masking, offset: 0x48 */
  __IO uint32_t CMU_FHH_STATUS_REG;                /**< CMU_FHH Status, offset: 0x4C */
  __IO uint32_t GMAC_2_CTRL_REG;                   /**< GMAC_2 Control, offset: 0x50 */
  __IO uint32_t DSP_PFAULT_SEL;                    /**< DSP PFAULT Select, offset: 0x54 */
  __IO uint32_t PRAM_AHB_ALARM;                    /**< PRAM AHB Alarm, offset: 0x58 */
  __IO uint32_t EDC_ERR_OUT;                       /**< EDC Error Out, offset: 0x5C */
  __IO uint32_t FCCU_ALARM;                        /**< FCCU Alarm 1, offset: 0x60 */
  __IO uint32_t FCCU_ALARM_REG;                    /**< FCCU Alarm 2, offset: 0x64 */
  __IO uint32_t MAIN_MISSION_INT_REG;              /**< Main Mission Interrupt Status, offset: 0x68 */
  uint8_t RESERVED_2[4];
  __IO uint32_t BUS_DISABLE_OVERRIDE;              /**< Bus Disable Override, offset: 0x70 */
  __IO uint32_t RESET_REQUEST_REG;                 /**< Reset Request, offset: 0x74 */
  __IO uint32_t PIPE_PARITY_MODE_DATA_CTRL1_REG;   /**< Pipe Parity Control 1, offset: 0x78 */
  uint8_t RESERVED_3[4];
  __IO uint32_t DSP_IP_REGISTER;                   /**< DSP IP Status, offset: 0x80 */
  __IO uint32_t ATP_REG;                           /**< ATP Status, offset: 0x84 */
  uint8_t RESERVED_4[52];
  __IO uint32_t DEBUG_CONTROL;                     /**< Debug Control, offset: 0xBC */
  uint8_t RESERVED_5[32];
  __IO uint32_t TIMESTAMP_CONTROL_REGISTER;        /**< Timestamp Control, offset: 0xE0 */
} SRC_Type, *SRC_MemMapPtr;

/** Number of instances of the SRC module. */
#define SRC_INSTANCE_COUNT                       (1u)

/* SRC - Peripheral instance base addresses */
/** Peripheral SRC base address */
#define IP_SRC_BASE                              (0x400D8300u)
/** Peripheral SRC base pointer */
#define IP_SRC                                   ((SRC_Type *)IP_SRC_BASE)
/** Array initializer of SRC peripheral base addresses */
#define IP_SRC_BASE_ADDRS                        { IP_SRC_BASE }
/** Array initializer of SRC peripheral base pointers */
#define IP_SRC_BASE_PTRS                         { IP_SRC }

/* ----------------------------------------------------------------------------
   -- SRC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SRC_Register_Masks SRC Register Masks
 * @{
 */

/*! @name SW_NCF - Software Triggered Faults */
/*! @{ */

#define SRC_SW_NCF_SW_NCF1_MASK                  (0x1U)
#define SRC_SW_NCF_SW_NCF1_SHIFT                 (0U)
#define SRC_SW_NCF_SW_NCF1_WIDTH                 (1U)
#define SRC_SW_NCF_SW_NCF1(x)                    (((uint32_t)(((uint32_t)(x)) << SRC_SW_NCF_SW_NCF1_SHIFT)) & SRC_SW_NCF_SW_NCF1_MASK)

#define SRC_SW_NCF_SW_NCF2_MASK                  (0x2U)
#define SRC_SW_NCF_SW_NCF2_SHIFT                 (1U)
#define SRC_SW_NCF_SW_NCF2_WIDTH                 (1U)
#define SRC_SW_NCF_SW_NCF2(x)                    (((uint32_t)(((uint32_t)(x)) << SRC_SW_NCF_SW_NCF2_SHIFT)) & SRC_SW_NCF_SW_NCF2_MASK)

#define SRC_SW_NCF_SW_NCF3_MASK                  (0x4U)
#define SRC_SW_NCF_SW_NCF3_SHIFT                 (2U)
#define SRC_SW_NCF_SW_NCF3_WIDTH                 (1U)
#define SRC_SW_NCF_SW_NCF3(x)                    (((uint32_t)(((uint32_t)(x)) << SRC_SW_NCF_SW_NCF3_SHIFT)) & SRC_SW_NCF_SW_NCF3_MASK)

#define SRC_SW_NCF_SW_NCF4_MASK                  (0x8U)
#define SRC_SW_NCF_SW_NCF4_SHIFT                 (3U)
#define SRC_SW_NCF_SW_NCF4_WIDTH                 (1U)
#define SRC_SW_NCF_SW_NCF4(x)                    (((uint32_t)(((uint32_t)(x)) << SRC_SW_NCF_SW_NCF4_SHIFT)) & SRC_SW_NCF_SW_NCF4_MASK)
/*! @} */

/*! @name GMAC_0_CTRL_STS - GMAC_0 Control */
/*! @{ */

#define SRC_GMAC_0_CTRL_STS_PHY_INTF_SEL_MASK    (0x7U)
#define SRC_GMAC_0_CTRL_STS_PHY_INTF_SEL_SHIFT   (0U)
#define SRC_GMAC_0_CTRL_STS_PHY_INTF_SEL_WIDTH   (3U)
#define SRC_GMAC_0_CTRL_STS_PHY_INTF_SEL(x)      (((uint32_t)(((uint32_t)(x)) << SRC_GMAC_0_CTRL_STS_PHY_INTF_SEL_SHIFT)) & SRC_GMAC_0_CTRL_STS_PHY_INTF_SEL_MASK)

#define SRC_GMAC_0_CTRL_STS_FTM0_SEL_MASK        (0x8U)
#define SRC_GMAC_0_CTRL_STS_FTM0_SEL_SHIFT       (3U)
#define SRC_GMAC_0_CTRL_STS_FTM0_SEL_WIDTH       (1U)
#define SRC_GMAC_0_CTRL_STS_FTM0_SEL(x)          (((uint32_t)(((uint32_t)(x)) << SRC_GMAC_0_CTRL_STS_FTM0_SEL_SHIFT)) & SRC_GMAC_0_CTRL_STS_FTM0_SEL_MASK)
/*! @} */

/*! @name GMAC_1_CTRL_REG - GMAC_1 Control */
/*! @{ */

#define SRC_GMAC_1_CTRL_REG_PHY_INTF_SEL_MASK    (0x7U)
#define SRC_GMAC_1_CTRL_REG_PHY_INTF_SEL_SHIFT   (0U)
#define SRC_GMAC_1_CTRL_REG_PHY_INTF_SEL_WIDTH   (3U)
#define SRC_GMAC_1_CTRL_REG_PHY_INTF_SEL(x)      (((uint32_t)(((uint32_t)(x)) << SRC_GMAC_1_CTRL_REG_PHY_INTF_SEL_SHIFT)) & SRC_GMAC_1_CTRL_REG_PHY_INTF_SEL_MASK)

#define SRC_GMAC_1_CTRL_REG_GMAC0_VC_ID_MASK     (0x18U)
#define SRC_GMAC_1_CTRL_REG_GMAC0_VC_ID_SHIFT    (3U)
#define SRC_GMAC_1_CTRL_REG_GMAC0_VC_ID_WIDTH    (2U)
#define SRC_GMAC_1_CTRL_REG_GMAC0_VC_ID(x)       (((uint32_t)(((uint32_t)(x)) << SRC_GMAC_1_CTRL_REG_GMAC0_VC_ID_SHIFT)) & SRC_GMAC_1_CTRL_REG_GMAC0_VC_ID_MASK)

#define SRC_GMAC_1_CTRL_REG_GMAC1_VC_ID_MASK     (0x60U)
#define SRC_GMAC_1_CTRL_REG_GMAC1_VC_ID_SHIFT    (5U)
#define SRC_GMAC_1_CTRL_REG_GMAC1_VC_ID_WIDTH    (2U)
#define SRC_GMAC_1_CTRL_REG_GMAC1_VC_ID(x)       (((uint32_t)(((uint32_t)(x)) << SRC_GMAC_1_CTRL_REG_GMAC1_VC_ID_SHIFT)) & SRC_GMAC_1_CTRL_REG_GMAC1_VC_ID_MASK)

#define SRC_GMAC_1_CTRL_REG_GMAC0_MIPICSI2_ID_MASK (0x180U)
#define SRC_GMAC_1_CTRL_REG_GMAC0_MIPICSI2_ID_SHIFT (7U)
#define SRC_GMAC_1_CTRL_REG_GMAC0_MIPICSI2_ID_WIDTH (2U)
#define SRC_GMAC_1_CTRL_REG_GMAC0_MIPICSI2_ID(x) (((uint32_t)(((uint32_t)(x)) << SRC_GMAC_1_CTRL_REG_GMAC0_MIPICSI2_ID_SHIFT)) & SRC_GMAC_1_CTRL_REG_GMAC0_MIPICSI2_ID_MASK)
/*! @} */

/*! @name CTE_CTRL_REG - CTE Control */
/*! @{ */

#define SRC_CTE_CTRL_REG_IN_CTE_MASK             (0x1U)
#define SRC_CTE_CTRL_REG_IN_CTE_SHIFT            (0U)
#define SRC_CTE_CTRL_REG_IN_CTE_WIDTH            (1U)
#define SRC_CTE_CTRL_REG_IN_CTE(x)               (((uint32_t)(((uint32_t)(x)) << SRC_CTE_CTRL_REG_IN_CTE_SHIFT)) & SRC_CTE_CTRL_REG_IN_CTE_MASK)

#define SRC_CTE_CTRL_REG_VC_ID_MASK              (0x6U)
#define SRC_CTE_CTRL_REG_VC_ID_SHIFT             (1U)
#define SRC_CTE_CTRL_REG_VC_ID_WIDTH             (2U)
#define SRC_CTE_CTRL_REG_VC_ID(x)                (((uint32_t)(((uint32_t)(x)) << SRC_CTE_CTRL_REG_VC_ID_SHIFT)) & SRC_CTE_CTRL_REG_VC_ID_MASK)

#define SRC_CTE_CTRL_REG_MIPICSI2_ID_MASK        (0x18U)
#define SRC_CTE_CTRL_REG_MIPICSI2_ID_SHIFT       (3U)
#define SRC_CTE_CTRL_REG_MIPICSI2_ID_WIDTH       (2U)
#define SRC_CTE_CTRL_REG_MIPICSI2_ID(x)          (((uint32_t)(((uint32_t)(x)) << SRC_CTE_CTRL_REG_MIPICSI2_ID_SHIFT)) & SRC_CTE_CTRL_REG_MIPICSI2_ID_MASK)
/*! @} */

/*! @name CMU_FLL_STATUS_REG - CMU FLL Status */
/*! @{ */

#define SRC_CMU_FLL_STATUS_REG_CMU_3_FLL_STATUS_MASK (0x1U)
#define SRC_CMU_FLL_STATUS_REG_CMU_3_FLL_STATUS_SHIFT (0U)
#define SRC_CMU_FLL_STATUS_REG_CMU_3_FLL_STATUS_WIDTH (1U)
#define SRC_CMU_FLL_STATUS_REG_CMU_3_FLL_STATUS(x) (((uint32_t)(((uint32_t)(x)) << SRC_CMU_FLL_STATUS_REG_CMU_3_FLL_STATUS_SHIFT)) & SRC_CMU_FLL_STATUS_REG_CMU_3_FLL_STATUS_MASK)

#define SRC_CMU_FLL_STATUS_REG_CMU_1_FLL_STATUS_MASK (0x2U)
#define SRC_CMU_FLL_STATUS_REG_CMU_1_FLL_STATUS_SHIFT (1U)
#define SRC_CMU_FLL_STATUS_REG_CMU_1_FLL_STATUS_WIDTH (1U)
#define SRC_CMU_FLL_STATUS_REG_CMU_1_FLL_STATUS(x) (((uint32_t)(((uint32_t)(x)) << SRC_CMU_FLL_STATUS_REG_CMU_1_FLL_STATUS_SHIFT)) & SRC_CMU_FLL_STATUS_REG_CMU_1_FLL_STATUS_MASK)

#define SRC_CMU_FLL_STATUS_REG_CMU_10_FLL_STATUS_MASK (0x4U)
#define SRC_CMU_FLL_STATUS_REG_CMU_10_FLL_STATUS_SHIFT (2U)
#define SRC_CMU_FLL_STATUS_REG_CMU_10_FLL_STATUS_WIDTH (1U)
#define SRC_CMU_FLL_STATUS_REG_CMU_10_FLL_STATUS(x) (((uint32_t)(((uint32_t)(x)) << SRC_CMU_FLL_STATUS_REG_CMU_10_FLL_STATUS_SHIFT)) & SRC_CMU_FLL_STATUS_REG_CMU_10_FLL_STATUS_MASK)

#define SRC_CMU_FLL_STATUS_REG_CMU_11_FLL_STATUS_MASK (0x8U)
#define SRC_CMU_FLL_STATUS_REG_CMU_11_FLL_STATUS_SHIFT (3U)
#define SRC_CMU_FLL_STATUS_REG_CMU_11_FLL_STATUS_WIDTH (1U)
#define SRC_CMU_FLL_STATUS_REG_CMU_11_FLL_STATUS(x) (((uint32_t)(((uint32_t)(x)) << SRC_CMU_FLL_STATUS_REG_CMU_11_FLL_STATUS_SHIFT)) & SRC_CMU_FLL_STATUS_REG_CMU_11_FLL_STATUS_MASK)

#define SRC_CMU_FLL_STATUS_REG_CMU_12_FLL_STATUS_MASK (0x10U)
#define SRC_CMU_FLL_STATUS_REG_CMU_12_FLL_STATUS_SHIFT (4U)
#define SRC_CMU_FLL_STATUS_REG_CMU_12_FLL_STATUS_WIDTH (1U)
#define SRC_CMU_FLL_STATUS_REG_CMU_12_FLL_STATUS(x) (((uint32_t)(((uint32_t)(x)) << SRC_CMU_FLL_STATUS_REG_CMU_12_FLL_STATUS_SHIFT)) & SRC_CMU_FLL_STATUS_REG_CMU_12_FLL_STATUS_MASK)

#define SRC_CMU_FLL_STATUS_REG_CMU_13_FLL_STATUS_MASK (0x20U)
#define SRC_CMU_FLL_STATUS_REG_CMU_13_FLL_STATUS_SHIFT (5U)
#define SRC_CMU_FLL_STATUS_REG_CMU_13_FLL_STATUS_WIDTH (1U)
#define SRC_CMU_FLL_STATUS_REG_CMU_13_FLL_STATUS(x) (((uint32_t)(((uint32_t)(x)) << SRC_CMU_FLL_STATUS_REG_CMU_13_FLL_STATUS_SHIFT)) & SRC_CMU_FLL_STATUS_REG_CMU_13_FLL_STATUS_MASK)

#define SRC_CMU_FLL_STATUS_REG_CMU_14_FLL_STATUS_MASK (0x40U)
#define SRC_CMU_FLL_STATUS_REG_CMU_14_FLL_STATUS_SHIFT (6U)
#define SRC_CMU_FLL_STATUS_REG_CMU_14_FLL_STATUS_WIDTH (1U)
#define SRC_CMU_FLL_STATUS_REG_CMU_14_FLL_STATUS(x) (((uint32_t)(((uint32_t)(x)) << SRC_CMU_FLL_STATUS_REG_CMU_14_FLL_STATUS_SHIFT)) & SRC_CMU_FLL_STATUS_REG_CMU_14_FLL_STATUS_MASK)

#define SRC_CMU_FLL_STATUS_REG_CMU_15_FLL_STATUS_MASK (0x80U)
#define SRC_CMU_FLL_STATUS_REG_CMU_15_FLL_STATUS_SHIFT (7U)
#define SRC_CMU_FLL_STATUS_REG_CMU_15_FLL_STATUS_WIDTH (1U)
#define SRC_CMU_FLL_STATUS_REG_CMU_15_FLL_STATUS(x) (((uint32_t)(((uint32_t)(x)) << SRC_CMU_FLL_STATUS_REG_CMU_15_FLL_STATUS_SHIFT)) & SRC_CMU_FLL_STATUS_REG_CMU_15_FLL_STATUS_MASK)

#define SRC_CMU_FLL_STATUS_REG_CMU_16_FLL_STATUS_MASK (0x100U)
#define SRC_CMU_FLL_STATUS_REG_CMU_16_FLL_STATUS_SHIFT (8U)
#define SRC_CMU_FLL_STATUS_REG_CMU_16_FLL_STATUS_WIDTH (1U)
#define SRC_CMU_FLL_STATUS_REG_CMU_16_FLL_STATUS(x) (((uint32_t)(((uint32_t)(x)) << SRC_CMU_FLL_STATUS_REG_CMU_16_FLL_STATUS_SHIFT)) & SRC_CMU_FLL_STATUS_REG_CMU_16_FLL_STATUS_MASK)

#define SRC_CMU_FLL_STATUS_REG_CMU_17_FLL_STATUS_MASK (0x200U)
#define SRC_CMU_FLL_STATUS_REG_CMU_17_FLL_STATUS_SHIFT (9U)
#define SRC_CMU_FLL_STATUS_REG_CMU_17_FLL_STATUS_WIDTH (1U)
#define SRC_CMU_FLL_STATUS_REG_CMU_17_FLL_STATUS(x) (((uint32_t)(((uint32_t)(x)) << SRC_CMU_FLL_STATUS_REG_CMU_17_FLL_STATUS_SHIFT)) & SRC_CMU_FLL_STATUS_REG_CMU_17_FLL_STATUS_MASK)

#define SRC_CMU_FLL_STATUS_REG_CMU_21_FLL_STATUS_MASK (0x400U)
#define SRC_CMU_FLL_STATUS_REG_CMU_21_FLL_STATUS_SHIFT (10U)
#define SRC_CMU_FLL_STATUS_REG_CMU_21_FLL_STATUS_WIDTH (1U)
#define SRC_CMU_FLL_STATUS_REG_CMU_21_FLL_STATUS(x) (((uint32_t)(((uint32_t)(x)) << SRC_CMU_FLL_STATUS_REG_CMU_21_FLL_STATUS_SHIFT)) & SRC_CMU_FLL_STATUS_REG_CMU_21_FLL_STATUS_MASK)

#define SRC_CMU_FLL_STATUS_REG_CMU_22_FLL_STATUS_MASK (0x800U)
#define SRC_CMU_FLL_STATUS_REG_CMU_22_FLL_STATUS_SHIFT (11U)
#define SRC_CMU_FLL_STATUS_REG_CMU_22_FLL_STATUS_WIDTH (1U)
#define SRC_CMU_FLL_STATUS_REG_CMU_22_FLL_STATUS(x) (((uint32_t)(((uint32_t)(x)) << SRC_CMU_FLL_STATUS_REG_CMU_22_FLL_STATUS_SHIFT)) & SRC_CMU_FLL_STATUS_REG_CMU_22_FLL_STATUS_MASK)

#define SRC_CMU_FLL_STATUS_REG_CMU_ACCEL_DIV3_CLK_FLL_STATUS_MASK (0x1000U)
#define SRC_CMU_FLL_STATUS_REG_CMU_ACCEL_DIV3_CLK_FLL_STATUS_SHIFT (12U)
#define SRC_CMU_FLL_STATUS_REG_CMU_ACCEL_DIV3_CLK_FLL_STATUS_WIDTH (1U)
#define SRC_CMU_FLL_STATUS_REG_CMU_ACCEL_DIV3_CLK_FLL_STATUS(x) (((uint32_t)(((uint32_t)(x)) << SRC_CMU_FLL_STATUS_REG_CMU_ACCEL_DIV3_CLK_FLL_STATUS_SHIFT)) & SRC_CMU_FLL_STATUS_REG_CMU_ACCEL_DIV3_CLK_FLL_STATUS_MASK)

#define SRC_CMU_FLL_STATUS_REG_CMU_CTE_CLK_FLL_STATUS_MASK (0x2000U)
#define SRC_CMU_FLL_STATUS_REG_CMU_CTE_CLK_FLL_STATUS_SHIFT (13U)
#define SRC_CMU_FLL_STATUS_REG_CMU_CTE_CLK_FLL_STATUS_WIDTH (1U)
#define SRC_CMU_FLL_STATUS_REG_CMU_CTE_CLK_FLL_STATUS(x) (((uint32_t)(((uint32_t)(x)) << SRC_CMU_FLL_STATUS_REG_CMU_CTE_CLK_FLL_STATUS_SHIFT)) & SRC_CMU_FLL_STATUS_REG_CMU_CTE_CLK_FLL_STATUS_MASK)

#define SRC_CMU_FLL_STATUS_REG_CMU_GMAC1_RX_CLK_FLL_STATUS_MASK (0x4000U)
#define SRC_CMU_FLL_STATUS_REG_CMU_GMAC1_RX_CLK_FLL_STATUS_SHIFT (14U)
#define SRC_CMU_FLL_STATUS_REG_CMU_GMAC1_RX_CLK_FLL_STATUS_WIDTH (1U)
#define SRC_CMU_FLL_STATUS_REG_CMU_GMAC1_RX_CLK_FLL_STATUS(x) (((uint32_t)(((uint32_t)(x)) << SRC_CMU_FLL_STATUS_REG_CMU_GMAC1_RX_CLK_FLL_STATUS_SHIFT)) & SRC_CMU_FLL_STATUS_REG_CMU_GMAC1_RX_CLK_FLL_STATUS_MASK)

#define SRC_CMU_FLL_STATUS_REG_CMU_GMAC1_TX_CLK_FLL_STATUS_MASK (0x8000U)
#define SRC_CMU_FLL_STATUS_REG_CMU_GMAC1_TX_CLK_FLL_STATUS_SHIFT (15U)
#define SRC_CMU_FLL_STATUS_REG_CMU_GMAC1_TX_CLK_FLL_STATUS_WIDTH (1U)
#define SRC_CMU_FLL_STATUS_REG_CMU_GMAC1_TX_CLK_FLL_STATUS(x) (((uint32_t)(((uint32_t)(x)) << SRC_CMU_FLL_STATUS_REG_CMU_GMAC1_TX_CLK_FLL_STATUS_SHIFT)) & SRC_CMU_FLL_STATUS_REG_CMU_GMAC1_TX_CLK_FLL_STATUS_MASK)

#define SRC_CMU_FLL_STATUS_REG_CMU_GMAC1_TS_CLK_FLL_STATUS_MASK (0x10000U)
#define SRC_CMU_FLL_STATUS_REG_CMU_GMAC1_TS_CLK_FLL_STATUS_SHIFT (16U)
#define SRC_CMU_FLL_STATUS_REG_CMU_GMAC1_TS_CLK_FLL_STATUS_WIDTH (1U)
#define SRC_CMU_FLL_STATUS_REG_CMU_GMAC1_TS_CLK_FLL_STATUS(x) (((uint32_t)(((uint32_t)(x)) << SRC_CMU_FLL_STATUS_REG_CMU_GMAC1_TS_CLK_FLL_STATUS_SHIFT)) & SRC_CMU_FLL_STATUS_REG_CMU_GMAC1_TS_CLK_FLL_STATUS_MASK)

#define SRC_CMU_FLL_STATUS_REG_a53_cluster_FLL_STATUS_MASK (0x20000U)
#define SRC_CMU_FLL_STATUS_REG_a53_cluster_FLL_STATUS_SHIFT (17U)
#define SRC_CMU_FLL_STATUS_REG_a53_cluster_FLL_STATUS_WIDTH (1U)
#define SRC_CMU_FLL_STATUS_REG_a53_cluster_FLL_STATUS(x) (((uint32_t)(((uint32_t)(x)) << SRC_CMU_FLL_STATUS_REG_a53_cluster_FLL_STATUS_SHIFT)) & SRC_CMU_FLL_STATUS_REG_a53_cluster_FLL_STATUS_MASK)

#define SRC_CMU_FLL_STATUS_REG_CMU_CSI_CFG_CLK_FLL_STATUS_MASK (0x40000U)
#define SRC_CMU_FLL_STATUS_REG_CMU_CSI_CFG_CLK_FLL_STATUS_SHIFT (18U)
#define SRC_CMU_FLL_STATUS_REG_CMU_CSI_CFG_CLK_FLL_STATUS_WIDTH (1U)
#define SRC_CMU_FLL_STATUS_REG_CMU_CSI_CFG_CLK_FLL_STATUS(x) (((uint32_t)(((uint32_t)(x)) << SRC_CMU_FLL_STATUS_REG_CMU_CSI_CFG_CLK_FLL_STATUS_SHIFT)) & SRC_CMU_FLL_STATUS_REG_CMU_CSI_CFG_CLK_FLL_STATUS_MASK)
/*! @} */

/*! @name TRANSACTION_STAT_REG - Transaction Status */
/*! @{ */

#define SRC_TRANSACTION_STAT_REG_m_apb_debug_AP_I_mainNoPendingTrans_MASK (0x1U)
#define SRC_TRANSACTION_STAT_REG_m_apb_debug_AP_I_mainNoPendingTrans_SHIFT (0U)
#define SRC_TRANSACTION_STAT_REG_m_apb_debug_AP_I_mainNoPendingTrans_WIDTH (1U)
#define SRC_TRANSACTION_STAT_REG_m_apb_debug_AP_I_mainNoPendingTrans(x) (((uint32_t)(((uint32_t)(x)) << SRC_TRANSACTION_STAT_REG_m_apb_debug_AP_I_mainNoPendingTrans_SHIFT)) & SRC_TRANSACTION_STAT_REG_m_apb_debug_AP_I_mainNoPendingTrans_MASK)

#define SRC_TRANSACTION_STAT_REG_m_axi_ENET_A_I_mainNoPendingTrans_MASK (0x2U)
#define SRC_TRANSACTION_STAT_REG_m_axi_ENET_A_I_mainNoPendingTrans_SHIFT (1U)
#define SRC_TRANSACTION_STAT_REG_m_axi_ENET_A_I_mainNoPendingTrans_WIDTH (1U)
#define SRC_TRANSACTION_STAT_REG_m_axi_ENET_A_I_mainNoPendingTrans(x) (((uint32_t)(((uint32_t)(x)) << SRC_TRANSACTION_STAT_REG_m_axi_ENET_A_I_mainNoPendingTrans_SHIFT)) & SRC_TRANSACTION_STAT_REG_m_axi_ENET_A_I_mainNoPendingTrans_MASK)

#define SRC_TRANSACTION_STAT_REG_m_axi_MIPI_0_WO_I_mainNoPendingTrans_MASK (0x4U)
#define SRC_TRANSACTION_STAT_REG_m_axi_MIPI_0_WO_I_mainNoPendingTrans_SHIFT (2U)
#define SRC_TRANSACTION_STAT_REG_m_axi_MIPI_0_WO_I_mainNoPendingTrans_WIDTH (1U)
#define SRC_TRANSACTION_STAT_REG_m_axi_MIPI_0_WO_I_mainNoPendingTrans(x) (((uint32_t)(((uint32_t)(x)) << SRC_TRANSACTION_STAT_REG_m_axi_MIPI_0_WO_I_mainNoPendingTrans_SHIFT)) & SRC_TRANSACTION_STAT_REG_m_axi_MIPI_0_WO_I_mainNoPendingTrans_MASK)

#define SRC_TRANSACTION_STAT_REG_s_axi_to_STM500_T_mainNoPendingTrans_MASK (0x8U)
#define SRC_TRANSACTION_STAT_REG_s_axi_to_STM500_T_mainNoPendingTrans_SHIFT (3U)
#define SRC_TRANSACTION_STAT_REG_s_axi_to_STM500_T_mainNoPendingTrans_WIDTH (1U)
#define SRC_TRANSACTION_STAT_REG_s_axi_to_STM500_T_mainNoPendingTrans(x) (((uint32_t)(((uint32_t)(x)) << SRC_TRANSACTION_STAT_REG_s_axi_to_STM500_T_mainNoPendingTrans_SHIFT)) & SRC_TRANSACTION_STAT_REG_s_axi_to_STM500_T_mainNoPendingTrans_MASK)

#define SRC_TRANSACTION_STAT_REG_s_service_Debug_T_mainNoPendingTrans_MASK (0x10U)
#define SRC_TRANSACTION_STAT_REG_s_service_Debug_T_mainNoPendingTrans_SHIFT (4U)
#define SRC_TRANSACTION_STAT_REG_s_service_Debug_T_mainNoPendingTrans_WIDTH (1U)
#define SRC_TRANSACTION_STAT_REG_s_service_Debug_T_mainNoPendingTrans(x) (((uint32_t)(((uint32_t)(x)) << SRC_TRANSACTION_STAT_REG_s_service_Debug_T_mainNoPendingTrans_SHIFT)) & SRC_TRANSACTION_STAT_REG_s_service_Debug_T_mainNoPendingTrans_MASK)

#define SRC_TRANSACTION_STAT_REG_s_service_Debug_mainNoPendingTrans_MASK (0x20U)
#define SRC_TRANSACTION_STAT_REG_s_service_Debug_mainNoPendingTrans_SHIFT (5U)
#define SRC_TRANSACTION_STAT_REG_s_service_Debug_mainNoPendingTrans_WIDTH (1U)
#define SRC_TRANSACTION_STAT_REG_s_service_Debug_mainNoPendingTrans(x) (((uint32_t)(((uint32_t)(x)) << SRC_TRANSACTION_STAT_REG_s_service_Debug_mainNoPendingTrans_SHIFT)) & SRC_TRANSACTION_STAT_REG_s_service_Debug_mainNoPendingTrans_MASK)

#define SRC_TRANSACTION_STAT_REG_m_axi_a53_I_mainNoPendingTrans_MASK (0x40U)
#define SRC_TRANSACTION_STAT_REG_m_axi_a53_I_mainNoPendingTrans_SHIFT (6U)
#define SRC_TRANSACTION_STAT_REG_m_axi_a53_I_mainNoPendingTrans_WIDTH (1U)
#define SRC_TRANSACTION_STAT_REG_m_axi_a53_I_mainNoPendingTrans(x) (((uint32_t)(((uint32_t)(x)) << SRC_TRANSACTION_STAT_REG_m_axi_a53_I_mainNoPendingTrans_SHIFT)) & SRC_TRANSACTION_STAT_REG_m_axi_a53_I_mainNoPendingTrans_MASK)

#define SRC_TRANSACTION_STAT_REG_BBE32_DSP_PWaitMode_MASK (0x80U)
#define SRC_TRANSACTION_STAT_REG_BBE32_DSP_PWaitMode_SHIFT (7U)
#define SRC_TRANSACTION_STAT_REG_BBE32_DSP_PWaitMode_WIDTH (1U)
#define SRC_TRANSACTION_STAT_REG_BBE32_DSP_PWaitMode(x) (((uint32_t)(((uint32_t)(x)) << SRC_TRANSACTION_STAT_REG_BBE32_DSP_PWaitMode_SHIFT)) & SRC_TRANSACTION_STAT_REG_BBE32_DSP_PWaitMode_MASK)

#define SRC_TRANSACTION_STAT_REG_m_from_m7_axbs_I_mainNoPendingTrans_MASK (0x100U)
#define SRC_TRANSACTION_STAT_REG_m_from_m7_axbs_I_mainNoPendingTrans_SHIFT (8U)
#define SRC_TRANSACTION_STAT_REG_m_from_m7_axbs_I_mainNoPendingTrans_WIDTH (1U)
#define SRC_TRANSACTION_STAT_REG_m_from_m7_axbs_I_mainNoPendingTrans(x) (((uint32_t)(((uint32_t)(x)) << SRC_TRANSACTION_STAT_REG_m_from_m7_axbs_I_mainNoPendingTrans_SHIFT)) & SRC_TRANSACTION_STAT_REG_m_from_m7_axbs_I_mainNoPendingTrans_MASK)

#define SRC_TRANSACTION_STAT_REG_m_mipi_1_I_mainNoPendingTrans_MASK (0x200U)
#define SRC_TRANSACTION_STAT_REG_m_mipi_1_I_mainNoPendingTrans_SHIFT (9U)
#define SRC_TRANSACTION_STAT_REG_m_mipi_1_I_mainNoPendingTrans_WIDTH (1U)
#define SRC_TRANSACTION_STAT_REG_m_mipi_1_I_mainNoPendingTrans(x) (((uint32_t)(((uint32_t)(x)) << SRC_TRANSACTION_STAT_REG_m_mipi_1_I_mainNoPendingTrans_SHIFT)) & SRC_TRANSACTION_STAT_REG_m_mipi_1_I_mainNoPendingTrans_MASK)

#define SRC_TRANSACTION_STAT_REG_s_AIPS3_T_mainNoPendingTrans_MASK (0x400U)
#define SRC_TRANSACTION_STAT_REG_s_AIPS3_T_mainNoPendingTrans_SHIFT (10U)
#define SRC_TRANSACTION_STAT_REG_s_AIPS3_T_mainNoPendingTrans_WIDTH (1U)
#define SRC_TRANSACTION_STAT_REG_s_AIPS3_T_mainNoPendingTrans(x) (((uint32_t)(((uint32_t)(x)) << SRC_TRANSACTION_STAT_REG_s_AIPS3_T_mainNoPendingTrans_SHIFT)) & SRC_TRANSACTION_STAT_REG_s_AIPS3_T_mainNoPendingTrans_MASK)

#define SRC_TRANSACTION_STAT_REG_s_to_m7_axbs_ram_T_mainNoPendingTrans_MASK (0x800U)
#define SRC_TRANSACTION_STAT_REG_s_to_m7_axbs_ram_T_mainNoPendingTrans_SHIFT (11U)
#define SRC_TRANSACTION_STAT_REG_s_to_m7_axbs_ram_T_mainNoPendingTrans_WIDTH (1U)
#define SRC_TRANSACTION_STAT_REG_s_to_m7_axbs_ram_T_mainNoPendingTrans(x) (((uint32_t)(((uint32_t)(x)) << SRC_TRANSACTION_STAT_REG_s_to_m7_axbs_ram_T_mainNoPendingTrans_SHIFT)) & SRC_TRANSACTION_STAT_REG_s_to_m7_axbs_ram_T_mainNoPendingTrans_MASK)

#define SRC_TRANSACTION_STAT_REG_spt_bbe32_mainNoPendingTrans_MASK (0x1000U)
#define SRC_TRANSACTION_STAT_REG_spt_bbe32_mainNoPendingTrans_SHIFT (12U)
#define SRC_TRANSACTION_STAT_REG_spt_bbe32_mainNoPendingTrans_WIDTH (1U)
#define SRC_TRANSACTION_STAT_REG_spt_bbe32_mainNoPendingTrans(x) (((uint32_t)(((uint32_t)(x)) << SRC_TRANSACTION_STAT_REG_spt_bbe32_mainNoPendingTrans_SHIFT)) & SRC_TRANSACTION_STAT_REG_spt_bbe32_mainNoPendingTrans_MASK)

#define SRC_TRANSACTION_STAT_REG_spt_bbe32_tcm_T_mainNoPendingTrans_MASK (0x2000U)
#define SRC_TRANSACTION_STAT_REG_spt_bbe32_tcm_T_mainNoPendingTrans_SHIFT (13U)
#define SRC_TRANSACTION_STAT_REG_spt_bbe32_tcm_T_mainNoPendingTrans_WIDTH (1U)
#define SRC_TRANSACTION_STAT_REG_spt_bbe32_tcm_T_mainNoPendingTrans(x) (((uint32_t)(((uint32_t)(x)) << SRC_TRANSACTION_STAT_REG_spt_bbe32_tcm_T_mainNoPendingTrans_SHIFT)) & SRC_TRANSACTION_STAT_REG_spt_bbe32_tcm_T_mainNoPendingTrans_MASK)

#define SRC_TRANSACTION_STAT_REG_spt_rd_I_mainNoPendingTrans_MASK (0x4000U)
#define SRC_TRANSACTION_STAT_REG_spt_rd_I_mainNoPendingTrans_SHIFT (14U)
#define SRC_TRANSACTION_STAT_REG_spt_rd_I_mainNoPendingTrans_WIDTH (1U)
#define SRC_TRANSACTION_STAT_REG_spt_rd_I_mainNoPendingTrans(x) (((uint32_t)(((uint32_t)(x)) << SRC_TRANSACTION_STAT_REG_spt_rd_I_mainNoPendingTrans_SHIFT)) & SRC_TRANSACTION_STAT_REG_spt_rd_I_mainNoPendingTrans_MASK)

#define SRC_TRANSACTION_STAT_REG_spt_wr_I_mainNoPendingTrans_MASK (0x8000U)
#define SRC_TRANSACTION_STAT_REG_spt_wr_I_mainNoPendingTrans_SHIFT (15U)
#define SRC_TRANSACTION_STAT_REG_spt_wr_I_mainNoPendingTrans_WIDTH (1U)
#define SRC_TRANSACTION_STAT_REG_spt_wr_I_mainNoPendingTrans(x) (((uint32_t)(((uint32_t)(x)) << SRC_TRANSACTION_STAT_REG_spt_wr_I_mainNoPendingTrans_SHIFT)) & SRC_TRANSACTION_STAT_REG_spt_wr_I_mainNoPendingTrans_MASK)

#define SRC_TRANSACTION_STAT_REG_gic500_T_mainNoPendingTrans_MASK (0x10000U)
#define SRC_TRANSACTION_STAT_REG_gic500_T_mainNoPendingTrans_SHIFT (16U)
#define SRC_TRANSACTION_STAT_REG_gic500_T_mainNoPendingTrans_WIDTH (1U)
#define SRC_TRANSACTION_STAT_REG_gic500_T_mainNoPendingTrans(x) (((uint32_t)(((uint32_t)(x)) << SRC_TRANSACTION_STAT_REG_gic500_T_mainNoPendingTrans_SHIFT)) & SRC_TRANSACTION_STAT_REG_gic500_T_mainNoPendingTrans_MASK)

#define SRC_TRANSACTION_STAT_REG_s_sram_2_T_mainNoPendingTrans_MASK (0x20000U)
#define SRC_TRANSACTION_STAT_REG_s_sram_2_T_mainNoPendingTrans_SHIFT (17U)
#define SRC_TRANSACTION_STAT_REG_s_sram_2_T_mainNoPendingTrans_WIDTH (1U)
#define SRC_TRANSACTION_STAT_REG_s_sram_2_T_mainNoPendingTrans(x) (((uint32_t)(((uint32_t)(x)) << SRC_TRANSACTION_STAT_REG_s_sram_2_T_mainNoPendingTrans_SHIFT)) & SRC_TRANSACTION_STAT_REG_s_sram_2_T_mainNoPendingTrans_MASK)

#define SRC_TRANSACTION_STAT_REG_s_sram_3_T_mainNoPendingTrans_MASK (0x40000U)
#define SRC_TRANSACTION_STAT_REG_s_sram_3_T_mainNoPendingTrans_SHIFT (18U)
#define SRC_TRANSACTION_STAT_REG_s_sram_3_T_mainNoPendingTrans_WIDTH (1U)
#define SRC_TRANSACTION_STAT_REG_s_sram_3_T_mainNoPendingTrans(x) (((uint32_t)(((uint32_t)(x)) << SRC_TRANSACTION_STAT_REG_s_sram_3_T_mainNoPendingTrans_SHIFT)) & SRC_TRANSACTION_STAT_REG_s_sram_3_T_mainNoPendingTrans_MASK)

#define SRC_TRANSACTION_STAT_REG_s_to_periph_axbs_T_mainNoPendingTrans_MASK (0x80000U)
#define SRC_TRANSACTION_STAT_REG_s_to_periph_axbs_T_mainNoPendingTrans_SHIFT (19U)
#define SRC_TRANSACTION_STAT_REG_s_to_periph_axbs_T_mainNoPendingTrans_WIDTH (1U)
#define SRC_TRANSACTION_STAT_REG_s_to_periph_axbs_T_mainNoPendingTrans(x) (((uint32_t)(((uint32_t)(x)) << SRC_TRANSACTION_STAT_REG_s_to_periph_axbs_T_mainNoPendingTrans_SHIFT)) & SRC_TRANSACTION_STAT_REG_s_to_periph_axbs_T_mainNoPendingTrans_MASK)
/*! @} */

/*! @name TRANSACTION_STAT_2_REG - Transaction Status 2 */
/*! @{ */

#define SRC_TRANSACTION_STAT_2_REG_m_debug_I_etr_mainNoPendingTrans_MASK (0x1U)
#define SRC_TRANSACTION_STAT_2_REG_m_debug_I_etr_mainNoPendingTrans_SHIFT (0U)
#define SRC_TRANSACTION_STAT_2_REG_m_debug_I_etr_mainNoPendingTrans_WIDTH (1U)
#define SRC_TRANSACTION_STAT_2_REG_m_debug_I_etr_mainNoPendingTrans(x) (((uint32_t)(((uint32_t)(x)) << SRC_TRANSACTION_STAT_2_REG_m_debug_I_etr_mainNoPendingTrans_SHIFT)) & SRC_TRANSACTION_STAT_2_REG_m_debug_I_etr_mainNoPendingTrans_MASK)

#define SRC_TRANSACTION_STAT_2_REG_m_nsp_sf_host_access_I_mainNoPendingTrans_MASK (0x2U)
#define SRC_TRANSACTION_STAT_2_REG_m_nsp_sf_host_access_I_mainNoPendingTrans_SHIFT (1U)
#define SRC_TRANSACTION_STAT_2_REG_m_nsp_sf_host_access_I_mainNoPendingTrans_WIDTH (1U)
#define SRC_TRANSACTION_STAT_2_REG_m_nsp_sf_host_access_I_mainNoPendingTrans(x) (((uint32_t)(((uint32_t)(x)) << SRC_TRANSACTION_STAT_2_REG_m_nsp_sf_host_access_I_mainNoPendingTrans_SHIFT)) & SRC_TRANSACTION_STAT_2_REG_m_nsp_sf_host_access_I_mainNoPendingTrans_MASK)

#define SRC_TRANSACTION_STAT_2_REG_s_local_sram_0_T_mainNoPendingTrans_MASK (0x4U)
#define SRC_TRANSACTION_STAT_2_REG_s_local_sram_0_T_mainNoPendingTrans_SHIFT (2U)
#define SRC_TRANSACTION_STAT_2_REG_s_local_sram_0_T_mainNoPendingTrans_WIDTH (1U)
#define SRC_TRANSACTION_STAT_2_REG_s_local_sram_0_T_mainNoPendingTrans(x) (((uint32_t)(((uint32_t)(x)) << SRC_TRANSACTION_STAT_2_REG_s_local_sram_0_T_mainNoPendingTrans_SHIFT)) & SRC_TRANSACTION_STAT_2_REG_s_local_sram_0_T_mainNoPendingTrans_MASK)

#define SRC_TRANSACTION_STAT_2_REG_s_local_sram_1_T_mainNoPendingTrans_MASK (0x8U)
#define SRC_TRANSACTION_STAT_2_REG_s_local_sram_1_T_mainNoPendingTrans_SHIFT (3U)
#define SRC_TRANSACTION_STAT_2_REG_s_local_sram_1_T_mainNoPendingTrans_WIDTH (1U)
#define SRC_TRANSACTION_STAT_2_REG_s_local_sram_1_T_mainNoPendingTrans(x) (((uint32_t)(((uint32_t)(x)) << SRC_TRANSACTION_STAT_2_REG_s_local_sram_1_T_mainNoPendingTrans_SHIFT)) & SRC_TRANSACTION_STAT_2_REG_s_local_sram_1_T_mainNoPendingTrans_MASK)

#define SRC_TRANSACTION_STAT_2_REG_s_service_ss_user_T_mainNoPendingTrans_MASK (0x10U)
#define SRC_TRANSACTION_STAT_2_REG_s_service_ss_user_T_mainNoPendingTrans_SHIFT (4U)
#define SRC_TRANSACTION_STAT_2_REG_s_service_ss_user_T_mainNoPendingTrans_WIDTH (1U)
#define SRC_TRANSACTION_STAT_2_REG_s_service_ss_user_T_mainNoPendingTrans(x) (((uint32_t)(((uint32_t)(x)) << SRC_TRANSACTION_STAT_2_REG_s_service_ss_user_T_mainNoPendingTrans_SHIFT)) & SRC_TRANSACTION_STAT_2_REG_s_service_ss_user_T_mainNoPendingTrans_MASK)

#define SRC_TRANSACTION_STAT_2_REG_s_service_ss_user_mainNoPendingTrans_MASK (0x20U)
#define SRC_TRANSACTION_STAT_2_REG_s_service_ss_user_mainNoPendingTrans_SHIFT (5U)
#define SRC_TRANSACTION_STAT_2_REG_s_service_ss_user_mainNoPendingTrans_WIDTH (1U)
#define SRC_TRANSACTION_STAT_2_REG_s_service_ss_user_mainNoPendingTrans(x) (((uint32_t)(((uint32_t)(x)) << SRC_TRANSACTION_STAT_2_REG_s_service_ss_user_mainNoPendingTrans_SHIFT)) & SRC_TRANSACTION_STAT_2_REG_s_service_ss_user_mainNoPendingTrans_MASK)

#define SRC_TRANSACTION_STAT_2_REG_m_nsp_from_cc_mipiro_to_cbram_internal_I_mainNoPendingTrans_MASK (0x40U)
#define SRC_TRANSACTION_STAT_2_REG_m_nsp_from_cc_mipiro_to_cbram_internal_I_mainNoPendingTrans_SHIFT (6U)
#define SRC_TRANSACTION_STAT_2_REG_m_nsp_from_cc_mipiro_to_cbram_internal_I_mainNoPendingTrans_WIDTH (1U)
#define SRC_TRANSACTION_STAT_2_REG_m_nsp_from_cc_mipiro_to_cbram_internal_I_mainNoPendingTrans(x) (((uint32_t)(((uint32_t)(x)) << SRC_TRANSACTION_STAT_2_REG_m_nsp_from_cc_mipiro_to_cbram_internal_I_mainNoPendingTrans_SHIFT)) & SRC_TRANSACTION_STAT_2_REG_m_nsp_from_cc_mipiro_to_cbram_internal_I_mainNoPendingTrans_MASK)
/*! @} */

/*! @name FCCU_EOUT_OVERRIDE_CLEAR_REG - FCCU EOUT Override Clear */
/*! @{ */

#define SRC_FCCU_EOUT_OVERRIDE_CLEAR_REG_EOUT_OVERRIDE_CLEAR_MASK (0x1U)
#define SRC_FCCU_EOUT_OVERRIDE_CLEAR_REG_EOUT_OVERRIDE_CLEAR_SHIFT (0U)
#define SRC_FCCU_EOUT_OVERRIDE_CLEAR_REG_EOUT_OVERRIDE_CLEAR_WIDTH (1U)
#define SRC_FCCU_EOUT_OVERRIDE_CLEAR_REG_EOUT_OVERRIDE_CLEAR(x) (((uint32_t)(((uint32_t)(x)) << SRC_FCCU_EOUT_OVERRIDE_CLEAR_REG_EOUT_OVERRIDE_CLEAR_SHIFT)) & SRC_FCCU_EOUT_OVERRIDE_CLEAR_REG_EOUT_OVERRIDE_CLEAR_MASK)

#define SRC_FCCU_EOUT_OVERRIDE_CLEAR_REG_EOUT_OVERRIDE_DISABLE_DURING_SELFTEST_MASK (0x2U)
#define SRC_FCCU_EOUT_OVERRIDE_CLEAR_REG_EOUT_OVERRIDE_DISABLE_DURING_SELFTEST_SHIFT (1U)
#define SRC_FCCU_EOUT_OVERRIDE_CLEAR_REG_EOUT_OVERRIDE_DISABLE_DURING_SELFTEST_WIDTH (1U)
#define SRC_FCCU_EOUT_OVERRIDE_CLEAR_REG_EOUT_OVERRIDE_DISABLE_DURING_SELFTEST(x) (((uint32_t)(((uint32_t)(x)) << SRC_FCCU_EOUT_OVERRIDE_CLEAR_REG_EOUT_OVERRIDE_DISABLE_DURING_SELFTEST_SHIFT)) & SRC_FCCU_EOUT_OVERRIDE_CLEAR_REG_EOUT_OVERRIDE_DISABLE_DURING_SELFTEST_MASK)
/*! @} */

/*! @name MIPI_CSI2_REG - MIPI CSI2 Control */
/*! @{ */

#define SRC_MIPI_CSI2_REG_MIPI_CSI2_0_LINE_DONE_sel_0_MASK (0x1U)
#define SRC_MIPI_CSI2_REG_MIPI_CSI2_0_LINE_DONE_sel_0_SHIFT (0U)
#define SRC_MIPI_CSI2_REG_MIPI_CSI2_0_LINE_DONE_sel_0_WIDTH (1U)
#define SRC_MIPI_CSI2_REG_MIPI_CSI2_0_LINE_DONE_sel_0(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIPI_CSI2_REG_MIPI_CSI2_0_LINE_DONE_sel_0_SHIFT)) & SRC_MIPI_CSI2_REG_MIPI_CSI2_0_LINE_DONE_sel_0_MASK)

#define SRC_MIPI_CSI2_REG_MIPI_CSI2_0_LINE_DONE_sel_1_MASK (0x2U)
#define SRC_MIPI_CSI2_REG_MIPI_CSI2_0_LINE_DONE_sel_1_SHIFT (1U)
#define SRC_MIPI_CSI2_REG_MIPI_CSI2_0_LINE_DONE_sel_1_WIDTH (1U)
#define SRC_MIPI_CSI2_REG_MIPI_CSI2_0_LINE_DONE_sel_1(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIPI_CSI2_REG_MIPI_CSI2_0_LINE_DONE_sel_1_SHIFT)) & SRC_MIPI_CSI2_REG_MIPI_CSI2_0_LINE_DONE_sel_1_MASK)

#define SRC_MIPI_CSI2_REG_MIPI_CSI2_0_LINE_DONE_sel_2_MASK (0x4U)
#define SRC_MIPI_CSI2_REG_MIPI_CSI2_0_LINE_DONE_sel_2_SHIFT (2U)
#define SRC_MIPI_CSI2_REG_MIPI_CSI2_0_LINE_DONE_sel_2_WIDTH (1U)
#define SRC_MIPI_CSI2_REG_MIPI_CSI2_0_LINE_DONE_sel_2(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIPI_CSI2_REG_MIPI_CSI2_0_LINE_DONE_sel_2_SHIFT)) & SRC_MIPI_CSI2_REG_MIPI_CSI2_0_LINE_DONE_sel_2_MASK)

#define SRC_MIPI_CSI2_REG_MIPI_CSI2_0_LINE_DONE_sel_3_MASK (0x8U)
#define SRC_MIPI_CSI2_REG_MIPI_CSI2_0_LINE_DONE_sel_3_SHIFT (3U)
#define SRC_MIPI_CSI2_REG_MIPI_CSI2_0_LINE_DONE_sel_3_WIDTH (1U)
#define SRC_MIPI_CSI2_REG_MIPI_CSI2_0_LINE_DONE_sel_3(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIPI_CSI2_REG_MIPI_CSI2_0_LINE_DONE_sel_3_SHIFT)) & SRC_MIPI_CSI2_REG_MIPI_CSI2_0_LINE_DONE_sel_3_MASK)

#define SRC_MIPI_CSI2_REG_MIPI_CSI2_0_VSYNC_sel_0_MASK (0x10U)
#define SRC_MIPI_CSI2_REG_MIPI_CSI2_0_VSYNC_sel_0_SHIFT (4U)
#define SRC_MIPI_CSI2_REG_MIPI_CSI2_0_VSYNC_sel_0_WIDTH (1U)
#define SRC_MIPI_CSI2_REG_MIPI_CSI2_0_VSYNC_sel_0(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIPI_CSI2_REG_MIPI_CSI2_0_VSYNC_sel_0_SHIFT)) & SRC_MIPI_CSI2_REG_MIPI_CSI2_0_VSYNC_sel_0_MASK)

#define SRC_MIPI_CSI2_REG_MIPI_CSI2_0_VSYNC_sel_1_MASK (0x20U)
#define SRC_MIPI_CSI2_REG_MIPI_CSI2_0_VSYNC_sel_1_SHIFT (5U)
#define SRC_MIPI_CSI2_REG_MIPI_CSI2_0_VSYNC_sel_1_WIDTH (1U)
#define SRC_MIPI_CSI2_REG_MIPI_CSI2_0_VSYNC_sel_1(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIPI_CSI2_REG_MIPI_CSI2_0_VSYNC_sel_1_SHIFT)) & SRC_MIPI_CSI2_REG_MIPI_CSI2_0_VSYNC_sel_1_MASK)

#define SRC_MIPI_CSI2_REG_MIPI_CSI2_1_LINE_DONE_sel_0_MASK (0x40U)
#define SRC_MIPI_CSI2_REG_MIPI_CSI2_1_LINE_DONE_sel_0_SHIFT (6U)
#define SRC_MIPI_CSI2_REG_MIPI_CSI2_1_LINE_DONE_sel_0_WIDTH (1U)
#define SRC_MIPI_CSI2_REG_MIPI_CSI2_1_LINE_DONE_sel_0(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIPI_CSI2_REG_MIPI_CSI2_1_LINE_DONE_sel_0_SHIFT)) & SRC_MIPI_CSI2_REG_MIPI_CSI2_1_LINE_DONE_sel_0_MASK)

#define SRC_MIPI_CSI2_REG_MIPI_CSI2_1_LINE_DONE_sel_1_MASK (0x80U)
#define SRC_MIPI_CSI2_REG_MIPI_CSI2_1_LINE_DONE_sel_1_SHIFT (7U)
#define SRC_MIPI_CSI2_REG_MIPI_CSI2_1_LINE_DONE_sel_1_WIDTH (1U)
#define SRC_MIPI_CSI2_REG_MIPI_CSI2_1_LINE_DONE_sel_1(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIPI_CSI2_REG_MIPI_CSI2_1_LINE_DONE_sel_1_SHIFT)) & SRC_MIPI_CSI2_REG_MIPI_CSI2_1_LINE_DONE_sel_1_MASK)

#define SRC_MIPI_CSI2_REG_MIPI_CSI2_1_LINE_DONE_sel_2_MASK (0x100U)
#define SRC_MIPI_CSI2_REG_MIPI_CSI2_1_LINE_DONE_sel_2_SHIFT (8U)
#define SRC_MIPI_CSI2_REG_MIPI_CSI2_1_LINE_DONE_sel_2_WIDTH (1U)
#define SRC_MIPI_CSI2_REG_MIPI_CSI2_1_LINE_DONE_sel_2(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIPI_CSI2_REG_MIPI_CSI2_1_LINE_DONE_sel_2_SHIFT)) & SRC_MIPI_CSI2_REG_MIPI_CSI2_1_LINE_DONE_sel_2_MASK)

#define SRC_MIPI_CSI2_REG_MIPI_CSI2_1_LINE_DONE_sel_3_MASK (0x200U)
#define SRC_MIPI_CSI2_REG_MIPI_CSI2_1_LINE_DONE_sel_3_SHIFT (9U)
#define SRC_MIPI_CSI2_REG_MIPI_CSI2_1_LINE_DONE_sel_3_WIDTH (1U)
#define SRC_MIPI_CSI2_REG_MIPI_CSI2_1_LINE_DONE_sel_3(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIPI_CSI2_REG_MIPI_CSI2_1_LINE_DONE_sel_3_SHIFT)) & SRC_MIPI_CSI2_REG_MIPI_CSI2_1_LINE_DONE_sel_3_MASK)

#define SRC_MIPI_CSI2_REG_MIPI_CSI2_1_VSYNC_sel_0_MASK (0x400U)
#define SRC_MIPI_CSI2_REG_MIPI_CSI2_1_VSYNC_sel_0_SHIFT (10U)
#define SRC_MIPI_CSI2_REG_MIPI_CSI2_1_VSYNC_sel_0_WIDTH (1U)
#define SRC_MIPI_CSI2_REG_MIPI_CSI2_1_VSYNC_sel_0(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIPI_CSI2_REG_MIPI_CSI2_1_VSYNC_sel_0_SHIFT)) & SRC_MIPI_CSI2_REG_MIPI_CSI2_1_VSYNC_sel_0_MASK)

#define SRC_MIPI_CSI2_REG_MIPI_CSI2_1_VSYNC_sel_1_MASK (0x800U)
#define SRC_MIPI_CSI2_REG_MIPI_CSI2_1_VSYNC_sel_1_SHIFT (11U)
#define SRC_MIPI_CSI2_REG_MIPI_CSI2_1_VSYNC_sel_1_WIDTH (1U)
#define SRC_MIPI_CSI2_REG_MIPI_CSI2_1_VSYNC_sel_1(x) (((uint32_t)(((uint32_t)(x)) << SRC_MIPI_CSI2_REG_MIPI_CSI2_1_VSYNC_sel_1_SHIFT)) & SRC_MIPI_CSI2_REG_MIPI_CSI2_1_VSYNC_sel_1_MASK)
/*! @} */

/*! @name TIMEOUT_FAULT_STATUS_REG - Timeout Fault Status */
/*! @{ */

#define SRC_TIMEOUT_FAULT_STATUS_REG_m_apb_debug_AP_I_mainInitiator_Timeout_Fault_MASK (0x1U)
#define SRC_TIMEOUT_FAULT_STATUS_REG_m_apb_debug_AP_I_mainInitiator_Timeout_Fault_SHIFT (0U)
#define SRC_TIMEOUT_FAULT_STATUS_REG_m_apb_debug_AP_I_mainInitiator_Timeout_Fault_WIDTH (1U)
#define SRC_TIMEOUT_FAULT_STATUS_REG_m_apb_debug_AP_I_mainInitiator_Timeout_Fault(x) (((uint32_t)(((uint32_t)(x)) << SRC_TIMEOUT_FAULT_STATUS_REG_m_apb_debug_AP_I_mainInitiator_Timeout_Fault_SHIFT)) & SRC_TIMEOUT_FAULT_STATUS_REG_m_apb_debug_AP_I_mainInitiator_Timeout_Fault_MASK)

#define SRC_TIMEOUT_FAULT_STATUS_REG_m_axi_MIPI_0_I_mainInitiator_Timeout_Fault_MASK (0x2U)
#define SRC_TIMEOUT_FAULT_STATUS_REG_m_axi_MIPI_0_I_mainInitiator_Timeout_Fault_SHIFT (1U)
#define SRC_TIMEOUT_FAULT_STATUS_REG_m_axi_MIPI_0_I_mainInitiator_Timeout_Fault_WIDTH (1U)
#define SRC_TIMEOUT_FAULT_STATUS_REG_m_axi_MIPI_0_I_mainInitiator_Timeout_Fault(x) (((uint32_t)(((uint32_t)(x)) << SRC_TIMEOUT_FAULT_STATUS_REG_m_axi_MIPI_0_I_mainInitiator_Timeout_Fault_SHIFT)) & SRC_TIMEOUT_FAULT_STATUS_REG_m_axi_MIPI_0_I_mainInitiator_Timeout_Fault_MASK)

#define SRC_TIMEOUT_FAULT_STATUS_REG_m_axi_a53_I_mainInitiator_Timeout_Fault_MASK (0x4U)
#define SRC_TIMEOUT_FAULT_STATUS_REG_m_axi_a53_I_mainInitiator_Timeout_Fault_SHIFT (2U)
#define SRC_TIMEOUT_FAULT_STATUS_REG_m_axi_a53_I_mainInitiator_Timeout_Fault_WIDTH (1U)
#define SRC_TIMEOUT_FAULT_STATUS_REG_m_axi_a53_I_mainInitiator_Timeout_Fault(x) (((uint32_t)(((uint32_t)(x)) << SRC_TIMEOUT_FAULT_STATUS_REG_m_axi_a53_I_mainInitiator_Timeout_Fault_SHIFT)) & SRC_TIMEOUT_FAULT_STATUS_REG_m_axi_a53_I_mainInitiator_Timeout_Fault_MASK)

#define SRC_TIMEOUT_FAULT_STATUS_REG_m_axi_enet_I_mainInitiator_Timeout_Fault_MASK (0x8U)
#define SRC_TIMEOUT_FAULT_STATUS_REG_m_axi_enet_I_mainInitiator_Timeout_Fault_SHIFT (3U)
#define SRC_TIMEOUT_FAULT_STATUS_REG_m_axi_enet_I_mainInitiator_Timeout_Fault_WIDTH (1U)
#define SRC_TIMEOUT_FAULT_STATUS_REG_m_axi_enet_I_mainInitiator_Timeout_Fault(x) (((uint32_t)(((uint32_t)(x)) << SRC_TIMEOUT_FAULT_STATUS_REG_m_axi_enet_I_mainInitiator_Timeout_Fault_SHIFT)) & SRC_TIMEOUT_FAULT_STATUS_REG_m_axi_enet_I_mainInitiator_Timeout_Fault_MASK)

#define SRC_TIMEOUT_FAULT_STATUS_REG_m_debug_etr_I_mainInitiator_Timeout_Fault_MASK (0x10U)
#define SRC_TIMEOUT_FAULT_STATUS_REG_m_debug_etr_I_mainInitiator_Timeout_Fault_SHIFT (4U)
#define SRC_TIMEOUT_FAULT_STATUS_REG_m_debug_etr_I_mainInitiator_Timeout_Fault_WIDTH (1U)
#define SRC_TIMEOUT_FAULT_STATUS_REG_m_debug_etr_I_mainInitiator_Timeout_Fault(x) (((uint32_t)(((uint32_t)(x)) << SRC_TIMEOUT_FAULT_STATUS_REG_m_debug_etr_I_mainInitiator_Timeout_Fault_SHIFT)) & SRC_TIMEOUT_FAULT_STATUS_REG_m_debug_etr_I_mainInitiator_Timeout_Fault_MASK)

#define SRC_TIMEOUT_FAULT_STATUS_REG_m_from_m7_axbs_I_mainInitiator_Timeout_Fault_MASK (0x20U)
#define SRC_TIMEOUT_FAULT_STATUS_REG_m_from_m7_axbs_I_mainInitiator_Timeout_Fault_SHIFT (5U)
#define SRC_TIMEOUT_FAULT_STATUS_REG_m_from_m7_axbs_I_mainInitiator_Timeout_Fault_WIDTH (1U)
#define SRC_TIMEOUT_FAULT_STATUS_REG_m_from_m7_axbs_I_mainInitiator_Timeout_Fault(x) (((uint32_t)(((uint32_t)(x)) << SRC_TIMEOUT_FAULT_STATUS_REG_m_from_m7_axbs_I_mainInitiator_Timeout_Fault_SHIFT)) & SRC_TIMEOUT_FAULT_STATUS_REG_m_from_m7_axbs_I_mainInitiator_Timeout_Fault_MASK)

#define SRC_TIMEOUT_FAULT_STATUS_REG_m_mipi_1_I_mainInitiator_Timeout_Fault_MASK (0x40U)
#define SRC_TIMEOUT_FAULT_STATUS_REG_m_mipi_1_I_mainInitiator_Timeout_Fault_SHIFT (6U)
#define SRC_TIMEOUT_FAULT_STATUS_REG_m_mipi_1_I_mainInitiator_Timeout_Fault_WIDTH (1U)
#define SRC_TIMEOUT_FAULT_STATUS_REG_m_mipi_1_I_mainInitiator_Timeout_Fault(x) (((uint32_t)(((uint32_t)(x)) << SRC_TIMEOUT_FAULT_STATUS_REG_m_mipi_1_I_mainInitiator_Timeout_Fault_SHIFT)) & SRC_TIMEOUT_FAULT_STATUS_REG_m_mipi_1_I_mainInitiator_Timeout_Fault_MASK)

#define SRC_TIMEOUT_FAULT_STATUS_REG_spt_bbe32_I_mainInitiator_Timeout_Fault_MASK (0x100U)
#define SRC_TIMEOUT_FAULT_STATUS_REG_spt_bbe32_I_mainInitiator_Timeout_Fault_SHIFT (8U)
#define SRC_TIMEOUT_FAULT_STATUS_REG_spt_bbe32_I_mainInitiator_Timeout_Fault_WIDTH (1U)
#define SRC_TIMEOUT_FAULT_STATUS_REG_spt_bbe32_I_mainInitiator_Timeout_Fault(x) (((uint32_t)(((uint32_t)(x)) << SRC_TIMEOUT_FAULT_STATUS_REG_spt_bbe32_I_mainInitiator_Timeout_Fault_SHIFT)) & SRC_TIMEOUT_FAULT_STATUS_REG_spt_bbe32_I_mainInitiator_Timeout_Fault_MASK)

#define SRC_TIMEOUT_FAULT_STATUS_REG_spt_rd_I_mainInitiator_Timeout_Fault_MASK (0x200U)
#define SRC_TIMEOUT_FAULT_STATUS_REG_spt_rd_I_mainInitiator_Timeout_Fault_SHIFT (9U)
#define SRC_TIMEOUT_FAULT_STATUS_REG_spt_rd_I_mainInitiator_Timeout_Fault_WIDTH (1U)
#define SRC_TIMEOUT_FAULT_STATUS_REG_spt_rd_I_mainInitiator_Timeout_Fault(x) (((uint32_t)(((uint32_t)(x)) << SRC_TIMEOUT_FAULT_STATUS_REG_spt_rd_I_mainInitiator_Timeout_Fault_SHIFT)) & SRC_TIMEOUT_FAULT_STATUS_REG_spt_rd_I_mainInitiator_Timeout_Fault_MASK)

#define SRC_TIMEOUT_FAULT_STATUS_REG_spt_wr_I_mainInitiator_Timeout_Fault_MASK (0x400U)
#define SRC_TIMEOUT_FAULT_STATUS_REG_spt_wr_I_mainInitiator_Timeout_Fault_SHIFT (10U)
#define SRC_TIMEOUT_FAULT_STATUS_REG_spt_wr_I_mainInitiator_Timeout_Fault_WIDTH (1U)
#define SRC_TIMEOUT_FAULT_STATUS_REG_spt_wr_I_mainInitiator_Timeout_Fault(x) (((uint32_t)(((uint32_t)(x)) << SRC_TIMEOUT_FAULT_STATUS_REG_spt_wr_I_mainInitiator_Timeout_Fault_SHIFT)) & SRC_TIMEOUT_FAULT_STATUS_REG_spt_wr_I_mainInitiator_Timeout_Fault_MASK)
/*! @} */

/*! @name PERIPHERAL_REGISTER - Peripheral Control */
/*! @{ */

#define SRC_PERIPHERAL_REGISTER_flexcan0_ipg_stop_MASK (0x1U)
#define SRC_PERIPHERAL_REGISTER_flexcan0_ipg_stop_SHIFT (0U)
#define SRC_PERIPHERAL_REGISTER_flexcan0_ipg_stop_WIDTH (1U)
#define SRC_PERIPHERAL_REGISTER_flexcan0_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << SRC_PERIPHERAL_REGISTER_flexcan0_ipg_stop_SHIFT)) & SRC_PERIPHERAL_REGISTER_flexcan0_ipg_stop_MASK)

#define SRC_PERIPHERAL_REGISTER_flexcan1_ipg_stop_MASK (0x2U)
#define SRC_PERIPHERAL_REGISTER_flexcan1_ipg_stop_SHIFT (1U)
#define SRC_PERIPHERAL_REGISTER_flexcan1_ipg_stop_WIDTH (1U)
#define SRC_PERIPHERAL_REGISTER_flexcan1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << SRC_PERIPHERAL_REGISTER_flexcan1_ipg_stop_SHIFT)) & SRC_PERIPHERAL_REGISTER_flexcan1_ipg_stop_MASK)

#define SRC_PERIPHERAL_REGISTER_dspi0_ipg_stop_MASK (0x4U)
#define SRC_PERIPHERAL_REGISTER_dspi0_ipg_stop_SHIFT (2U)
#define SRC_PERIPHERAL_REGISTER_dspi0_ipg_stop_WIDTH (1U)
#define SRC_PERIPHERAL_REGISTER_dspi0_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << SRC_PERIPHERAL_REGISTER_dspi0_ipg_stop_SHIFT)) & SRC_PERIPHERAL_REGISTER_dspi0_ipg_stop_MASK)

#define SRC_PERIPHERAL_REGISTER_dspi1_ipg_stop_MASK (0x8U)
#define SRC_PERIPHERAL_REGISTER_dspi1_ipg_stop_SHIFT (3U)
#define SRC_PERIPHERAL_REGISTER_dspi1_ipg_stop_WIDTH (1U)
#define SRC_PERIPHERAL_REGISTER_dspi1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << SRC_PERIPHERAL_REGISTER_dspi1_ipg_stop_SHIFT)) & SRC_PERIPHERAL_REGISTER_dspi1_ipg_stop_MASK)

#define SRC_PERIPHERAL_REGISTER_dspi2_ipg_stop_MASK (0x10U)
#define SRC_PERIPHERAL_REGISTER_dspi2_ipg_stop_SHIFT (4U)
#define SRC_PERIPHERAL_REGISTER_dspi2_ipg_stop_WIDTH (1U)
#define SRC_PERIPHERAL_REGISTER_dspi2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << SRC_PERIPHERAL_REGISTER_dspi2_ipg_stop_SHIFT)) & SRC_PERIPHERAL_REGISTER_dspi2_ipg_stop_MASK)

#define SRC_PERIPHERAL_REGISTER_dspi3_ipg_stop_MASK (0x20U)
#define SRC_PERIPHERAL_REGISTER_dspi3_ipg_stop_SHIFT (5U)
#define SRC_PERIPHERAL_REGISTER_dspi3_ipg_stop_WIDTH (1U)
#define SRC_PERIPHERAL_REGISTER_dspi3_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << SRC_PERIPHERAL_REGISTER_dspi3_ipg_stop_SHIFT)) & SRC_PERIPHERAL_REGISTER_dspi3_ipg_stop_MASK)

#define SRC_PERIPHERAL_REGISTER_i2c0_ipg_stop_MASK (0x40U)
#define SRC_PERIPHERAL_REGISTER_i2c0_ipg_stop_SHIFT (6U)
#define SRC_PERIPHERAL_REGISTER_i2c0_ipg_stop_WIDTH (1U)
#define SRC_PERIPHERAL_REGISTER_i2c0_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << SRC_PERIPHERAL_REGISTER_i2c0_ipg_stop_SHIFT)) & SRC_PERIPHERAL_REGISTER_i2c0_ipg_stop_MASK)

#define SRC_PERIPHERAL_REGISTER_i2c1_ipg_stop_MASK (0x80U)
#define SRC_PERIPHERAL_REGISTER_i2c1_ipg_stop_SHIFT (7U)
#define SRC_PERIPHERAL_REGISTER_i2c1_ipg_stop_WIDTH (1U)
#define SRC_PERIPHERAL_REGISTER_i2c1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << SRC_PERIPHERAL_REGISTER_i2c1_ipg_stop_SHIFT)) & SRC_PERIPHERAL_REGISTER_i2c1_ipg_stop_MASK)

#define SRC_PERIPHERAL_REGISTER_linflex_ipg_stop_MASK (0x100U)
#define SRC_PERIPHERAL_REGISTER_linflex_ipg_stop_SHIFT (8U)
#define SRC_PERIPHERAL_REGISTER_linflex_ipg_stop_WIDTH (1U)
#define SRC_PERIPHERAL_REGISTER_linflex_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << SRC_PERIPHERAL_REGISTER_linflex_ipg_stop_SHIFT)) & SRC_PERIPHERAL_REGISTER_linflex_ipg_stop_MASK)

#define SRC_PERIPHERAL_REGISTER_pit0_ipg_stop_MASK (0x200U)
#define SRC_PERIPHERAL_REGISTER_pit0_ipg_stop_SHIFT (9U)
#define SRC_PERIPHERAL_REGISTER_pit0_ipg_stop_WIDTH (1U)
#define SRC_PERIPHERAL_REGISTER_pit0_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << SRC_PERIPHERAL_REGISTER_pit0_ipg_stop_SHIFT)) & SRC_PERIPHERAL_REGISTER_pit0_ipg_stop_MASK)

#define SRC_PERIPHERAL_REGISTER_pit2_ipg_stop_MASK (0x400U)
#define SRC_PERIPHERAL_REGISTER_pit2_ipg_stop_SHIFT (10U)
#define SRC_PERIPHERAL_REGISTER_pit2_ipg_stop_WIDTH (1U)
#define SRC_PERIPHERAL_REGISTER_pit2_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << SRC_PERIPHERAL_REGISTER_pit2_ipg_stop_SHIFT)) & SRC_PERIPHERAL_REGISTER_pit2_ipg_stop_MASK)

#define SRC_PERIPHERAL_REGISTER_ctu_ipg_stop_MASK (0x800U)
#define SRC_PERIPHERAL_REGISTER_ctu_ipg_stop_SHIFT (11U)
#define SRC_PERIPHERAL_REGISTER_ctu_ipg_stop_WIDTH (1U)
#define SRC_PERIPHERAL_REGISTER_ctu_ipg_stop(x)  (((uint32_t)(((uint32_t)(x)) << SRC_PERIPHERAL_REGISTER_ctu_ipg_stop_SHIFT)) & SRC_PERIPHERAL_REGISTER_ctu_ipg_stop_MASK)

#define SRC_PERIPHERAL_REGISTER_ocotp_inst_ipg_stop_MASK (0x1000U)
#define SRC_PERIPHERAL_REGISTER_ocotp_inst_ipg_stop_SHIFT (12U)
#define SRC_PERIPHERAL_REGISTER_ocotp_inst_ipg_stop_WIDTH (1U)
#define SRC_PERIPHERAL_REGISTER_ocotp_inst_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << SRC_PERIPHERAL_REGISTER_ocotp_inst_ipg_stop_SHIFT)) & SRC_PERIPHERAL_REGISTER_ocotp_inst_ipg_stop_MASK)

#define SRC_PERIPHERAL_REGISTER_ocotp_inst1_ipg_stop_MASK (0x2000U)
#define SRC_PERIPHERAL_REGISTER_ocotp_inst1_ipg_stop_SHIFT (13U)
#define SRC_PERIPHERAL_REGISTER_ocotp_inst1_ipg_stop_WIDTH (1U)
#define SRC_PERIPHERAL_REGISTER_ocotp_inst1_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << SRC_PERIPHERAL_REGISTER_ocotp_inst1_ipg_stop_SHIFT)) & SRC_PERIPHERAL_REGISTER_ocotp_inst1_ipg_stop_MASK)

#define SRC_PERIPHERAL_REGISTER_quadspi_ipg_stop_MASK (0x4000U)
#define SRC_PERIPHERAL_REGISTER_quadspi_ipg_stop_SHIFT (14U)
#define SRC_PERIPHERAL_REGISTER_quadspi_ipg_stop_WIDTH (1U)
#define SRC_PERIPHERAL_REGISTER_quadspi_ipg_stop(x) (((uint32_t)(((uint32_t)(x)) << SRC_PERIPHERAL_REGISTER_quadspi_ipg_stop_SHIFT)) & SRC_PERIPHERAL_REGISTER_quadspi_ipg_stop_MASK)
/*! @} */

/*! @name PERIPHERAL_ACK_SIGNAL - Peripheral Acknowledge */
/*! @{ */

#define SRC_PERIPHERAL_ACK_SIGNAL_flexcan0_stop_ack_MASK (0x1U)
#define SRC_PERIPHERAL_ACK_SIGNAL_flexcan0_stop_ack_SHIFT (0U)
#define SRC_PERIPHERAL_ACK_SIGNAL_flexcan0_stop_ack_WIDTH (1U)
#define SRC_PERIPHERAL_ACK_SIGNAL_flexcan0_stop_ack(x) (((uint32_t)(((uint32_t)(x)) << SRC_PERIPHERAL_ACK_SIGNAL_flexcan0_stop_ack_SHIFT)) & SRC_PERIPHERAL_ACK_SIGNAL_flexcan0_stop_ack_MASK)

#define SRC_PERIPHERAL_ACK_SIGNAL_flexcan1_stop_ack_MASK (0x2U)
#define SRC_PERIPHERAL_ACK_SIGNAL_flexcan1_stop_ack_SHIFT (1U)
#define SRC_PERIPHERAL_ACK_SIGNAL_flexcan1_stop_ack_WIDTH (1U)
#define SRC_PERIPHERAL_ACK_SIGNAL_flexcan1_stop_ack(x) (((uint32_t)(((uint32_t)(x)) << SRC_PERIPHERAL_ACK_SIGNAL_flexcan1_stop_ack_SHIFT)) & SRC_PERIPHERAL_ACK_SIGNAL_flexcan1_stop_ack_MASK)

#define SRC_PERIPHERAL_ACK_SIGNAL_dspi0_stop_ack_MASK (0x4U)
#define SRC_PERIPHERAL_ACK_SIGNAL_dspi0_stop_ack_SHIFT (2U)
#define SRC_PERIPHERAL_ACK_SIGNAL_dspi0_stop_ack_WIDTH (1U)
#define SRC_PERIPHERAL_ACK_SIGNAL_dspi0_stop_ack(x) (((uint32_t)(((uint32_t)(x)) << SRC_PERIPHERAL_ACK_SIGNAL_dspi0_stop_ack_SHIFT)) & SRC_PERIPHERAL_ACK_SIGNAL_dspi0_stop_ack_MASK)

#define SRC_PERIPHERAL_ACK_SIGNAL_dspi1_stop_ack_MASK (0x8U)
#define SRC_PERIPHERAL_ACK_SIGNAL_dspi1_stop_ack_SHIFT (3U)
#define SRC_PERIPHERAL_ACK_SIGNAL_dspi1_stop_ack_WIDTH (1U)
#define SRC_PERIPHERAL_ACK_SIGNAL_dspi1_stop_ack(x) (((uint32_t)(((uint32_t)(x)) << SRC_PERIPHERAL_ACK_SIGNAL_dspi1_stop_ack_SHIFT)) & SRC_PERIPHERAL_ACK_SIGNAL_dspi1_stop_ack_MASK)

#define SRC_PERIPHERAL_ACK_SIGNAL_dspi2_stop_ack_MASK (0x10U)
#define SRC_PERIPHERAL_ACK_SIGNAL_dspi2_stop_ack_SHIFT (4U)
#define SRC_PERIPHERAL_ACK_SIGNAL_dspi2_stop_ack_WIDTH (1U)
#define SRC_PERIPHERAL_ACK_SIGNAL_dspi2_stop_ack(x) (((uint32_t)(((uint32_t)(x)) << SRC_PERIPHERAL_ACK_SIGNAL_dspi2_stop_ack_SHIFT)) & SRC_PERIPHERAL_ACK_SIGNAL_dspi2_stop_ack_MASK)

#define SRC_PERIPHERAL_ACK_SIGNAL_dspi3_stop_ack_MASK (0x20U)
#define SRC_PERIPHERAL_ACK_SIGNAL_dspi3_stop_ack_SHIFT (5U)
#define SRC_PERIPHERAL_ACK_SIGNAL_dspi3_stop_ack_WIDTH (1U)
#define SRC_PERIPHERAL_ACK_SIGNAL_dspi3_stop_ack(x) (((uint32_t)(((uint32_t)(x)) << SRC_PERIPHERAL_ACK_SIGNAL_dspi3_stop_ack_SHIFT)) & SRC_PERIPHERAL_ACK_SIGNAL_dspi3_stop_ack_MASK)

#define SRC_PERIPHERAL_ACK_SIGNAL_i2c0_stop_ack_MASK (0x40U)
#define SRC_PERIPHERAL_ACK_SIGNAL_i2c0_stop_ack_SHIFT (6U)
#define SRC_PERIPHERAL_ACK_SIGNAL_i2c0_stop_ack_WIDTH (1U)
#define SRC_PERIPHERAL_ACK_SIGNAL_i2c0_stop_ack(x) (((uint32_t)(((uint32_t)(x)) << SRC_PERIPHERAL_ACK_SIGNAL_i2c0_stop_ack_SHIFT)) & SRC_PERIPHERAL_ACK_SIGNAL_i2c0_stop_ack_MASK)

#define SRC_PERIPHERAL_ACK_SIGNAL_i2c1_stop_ack_MASK (0x80U)
#define SRC_PERIPHERAL_ACK_SIGNAL_i2c1_stop_ack_SHIFT (7U)
#define SRC_PERIPHERAL_ACK_SIGNAL_i2c1_stop_ack_WIDTH (1U)
#define SRC_PERIPHERAL_ACK_SIGNAL_i2c1_stop_ack(x) (((uint32_t)(((uint32_t)(x)) << SRC_PERIPHERAL_ACK_SIGNAL_i2c1_stop_ack_SHIFT)) & SRC_PERIPHERAL_ACK_SIGNAL_i2c1_stop_ack_MASK)

#define SRC_PERIPHERAL_ACK_SIGNAL_linflex_stop_ack_MASK (0x100U)
#define SRC_PERIPHERAL_ACK_SIGNAL_linflex_stop_ack_SHIFT (8U)
#define SRC_PERIPHERAL_ACK_SIGNAL_linflex_stop_ack_WIDTH (1U)
#define SRC_PERIPHERAL_ACK_SIGNAL_linflex_stop_ack(x) (((uint32_t)(((uint32_t)(x)) << SRC_PERIPHERAL_ACK_SIGNAL_linflex_stop_ack_SHIFT)) & SRC_PERIPHERAL_ACK_SIGNAL_linflex_stop_ack_MASK)

#define SRC_PERIPHERAL_ACK_SIGNAL_pit0_stop_ack_MASK (0x200U)
#define SRC_PERIPHERAL_ACK_SIGNAL_pit0_stop_ack_SHIFT (9U)
#define SRC_PERIPHERAL_ACK_SIGNAL_pit0_stop_ack_WIDTH (1U)
#define SRC_PERIPHERAL_ACK_SIGNAL_pit0_stop_ack(x) (((uint32_t)(((uint32_t)(x)) << SRC_PERIPHERAL_ACK_SIGNAL_pit0_stop_ack_SHIFT)) & SRC_PERIPHERAL_ACK_SIGNAL_pit0_stop_ack_MASK)

#define SRC_PERIPHERAL_ACK_SIGNAL_pit2_stop_ack_MASK (0x400U)
#define SRC_PERIPHERAL_ACK_SIGNAL_pit2_stop_ack_SHIFT (10U)
#define SRC_PERIPHERAL_ACK_SIGNAL_pit2_stop_ack_WIDTH (1U)
#define SRC_PERIPHERAL_ACK_SIGNAL_pit2_stop_ack(x) (((uint32_t)(((uint32_t)(x)) << SRC_PERIPHERAL_ACK_SIGNAL_pit2_stop_ack_SHIFT)) & SRC_PERIPHERAL_ACK_SIGNAL_pit2_stop_ack_MASK)

#define SRC_PERIPHERAL_ACK_SIGNAL_ctu_stop_ack_MASK (0x800U)
#define SRC_PERIPHERAL_ACK_SIGNAL_ctu_stop_ack_SHIFT (11U)
#define SRC_PERIPHERAL_ACK_SIGNAL_ctu_stop_ack_WIDTH (1U)
#define SRC_PERIPHERAL_ACK_SIGNAL_ctu_stop_ack(x) (((uint32_t)(((uint32_t)(x)) << SRC_PERIPHERAL_ACK_SIGNAL_ctu_stop_ack_SHIFT)) & SRC_PERIPHERAL_ACK_SIGNAL_ctu_stop_ack_MASK)

#define SRC_PERIPHERAL_ACK_SIGNAL_ocotp_inst_stop_ack_MASK (0x1000U)
#define SRC_PERIPHERAL_ACK_SIGNAL_ocotp_inst_stop_ack_SHIFT (12U)
#define SRC_PERIPHERAL_ACK_SIGNAL_ocotp_inst_stop_ack_WIDTH (1U)
#define SRC_PERIPHERAL_ACK_SIGNAL_ocotp_inst_stop_ack(x) (((uint32_t)(((uint32_t)(x)) << SRC_PERIPHERAL_ACK_SIGNAL_ocotp_inst_stop_ack_SHIFT)) & SRC_PERIPHERAL_ACK_SIGNAL_ocotp_inst_stop_ack_MASK)

#define SRC_PERIPHERAL_ACK_SIGNAL_ocotop_inst1_stop_ack_MASK (0x2000U)
#define SRC_PERIPHERAL_ACK_SIGNAL_ocotop_inst1_stop_ack_SHIFT (13U)
#define SRC_PERIPHERAL_ACK_SIGNAL_ocotop_inst1_stop_ack_WIDTH (1U)
#define SRC_PERIPHERAL_ACK_SIGNAL_ocotop_inst1_stop_ack(x) (((uint32_t)(((uint32_t)(x)) << SRC_PERIPHERAL_ACK_SIGNAL_ocotop_inst1_stop_ack_SHIFT)) & SRC_PERIPHERAL_ACK_SIGNAL_ocotop_inst1_stop_ack_MASK)

#define SRC_PERIPHERAL_ACK_SIGNAL_quadspi_stop_ack_MASK (0x4000U)
#define SRC_PERIPHERAL_ACK_SIGNAL_quadspi_stop_ack_SHIFT (14U)
#define SRC_PERIPHERAL_ACK_SIGNAL_quadspi_stop_ack_WIDTH (1U)
#define SRC_PERIPHERAL_ACK_SIGNAL_quadspi_stop_ack(x) (((uint32_t)(((uint32_t)(x)) << SRC_PERIPHERAL_ACK_SIGNAL_quadspi_stop_ack_SHIFT)) & SRC_PERIPHERAL_ACK_SIGNAL_quadspi_stop_ack_MASK)

#define SRC_PERIPHERAL_ACK_SIGNAL_ctu_ipg_MT_ack_MASK (0x8000U)
#define SRC_PERIPHERAL_ACK_SIGNAL_ctu_ipg_MT_ack_SHIFT (15U)
#define SRC_PERIPHERAL_ACK_SIGNAL_ctu_ipg_MT_ack_WIDTH (1U)
#define SRC_PERIPHERAL_ACK_SIGNAL_ctu_ipg_MT_ack(x) (((uint32_t)(((uint32_t)(x)) << SRC_PERIPHERAL_ACK_SIGNAL_ctu_ipg_MT_ack_SHIFT)) & SRC_PERIPHERAL_ACK_SIGNAL_ctu_ipg_MT_ack_MASK)
/*! @} */

/*! @name ENET_RT_AHB_GASKET - GMAC_0 AHB Gasket */
/*! @{ */

#define SRC_ENET_RT_AHB_GASKET_enet_rt_ahb_gasket_disable_opt_wr_MASK (0x1U)
#define SRC_ENET_RT_AHB_GASKET_enet_rt_ahb_gasket_disable_opt_wr_SHIFT (0U)
#define SRC_ENET_RT_AHB_GASKET_enet_rt_ahb_gasket_disable_opt_wr_WIDTH (1U)
#define SRC_ENET_RT_AHB_GASKET_enet_rt_ahb_gasket_disable_opt_wr(x) (((uint32_t)(((uint32_t)(x)) << SRC_ENET_RT_AHB_GASKET_enet_rt_ahb_gasket_disable_opt_wr_SHIFT)) & SRC_ENET_RT_AHB_GASKET_enet_rt_ahb_gasket_disable_opt_wr_MASK)
/*! @} */

/*! @name PFAULT_READ_NCF_FAULT_MASKING - PFAULT Read NCF Fault Masking */
/*! @{ */

#define SRC_PFAULT_READ_NCF_FAULT_MASKING_src_pfault_speculative_read_ncf_masking_MASK (0x1U)
#define SRC_PFAULT_READ_NCF_FAULT_MASKING_src_pfault_speculative_read_ncf_masking_SHIFT (0U)
#define SRC_PFAULT_READ_NCF_FAULT_MASKING_src_pfault_speculative_read_ncf_masking_WIDTH (1U)
#define SRC_PFAULT_READ_NCF_FAULT_MASKING_src_pfault_speculative_read_ncf_masking(x) (((uint32_t)(((uint32_t)(x)) << SRC_PFAULT_READ_NCF_FAULT_MASKING_src_pfault_speculative_read_ncf_masking_SHIFT)) & SRC_PFAULT_READ_NCF_FAULT_MASKING_src_pfault_speculative_read_ncf_masking_MASK)
/*! @} */

/*! @name CMU_FHH_STATUS_REG - CMU_FHH Status */
/*! @{ */

#define SRC_CMU_FHH_STATUS_REG_CMU_3_FHH_STATUS_MASK (0x1U)
#define SRC_CMU_FHH_STATUS_REG_CMU_3_FHH_STATUS_SHIFT (0U)
#define SRC_CMU_FHH_STATUS_REG_CMU_3_FHH_STATUS_WIDTH (1U)
#define SRC_CMU_FHH_STATUS_REG_CMU_3_FHH_STATUS(x) (((uint32_t)(((uint32_t)(x)) << SRC_CMU_FHH_STATUS_REG_CMU_3_FHH_STATUS_SHIFT)) & SRC_CMU_FHH_STATUS_REG_CMU_3_FHH_STATUS_MASK)

#define SRC_CMU_FHH_STATUS_REG_CMU_1_FHH_STATUS_MASK (0x2U)
#define SRC_CMU_FHH_STATUS_REG_CMU_1_FHH_STATUS_SHIFT (1U)
#define SRC_CMU_FHH_STATUS_REG_CMU_1_FHH_STATUS_WIDTH (1U)
#define SRC_CMU_FHH_STATUS_REG_CMU_1_FHH_STATUS(x) (((uint32_t)(((uint32_t)(x)) << SRC_CMU_FHH_STATUS_REG_CMU_1_FHH_STATUS_SHIFT)) & SRC_CMU_FHH_STATUS_REG_CMU_1_FHH_STATUS_MASK)

#define SRC_CMU_FHH_STATUS_REG_CMU_10_FHH_STATUS_MASK (0x4U)
#define SRC_CMU_FHH_STATUS_REG_CMU_10_FHH_STATUS_SHIFT (2U)
#define SRC_CMU_FHH_STATUS_REG_CMU_10_FHH_STATUS_WIDTH (1U)
#define SRC_CMU_FHH_STATUS_REG_CMU_10_FHH_STATUS(x) (((uint32_t)(((uint32_t)(x)) << SRC_CMU_FHH_STATUS_REG_CMU_10_FHH_STATUS_SHIFT)) & SRC_CMU_FHH_STATUS_REG_CMU_10_FHH_STATUS_MASK)

#define SRC_CMU_FHH_STATUS_REG_CMU_11_FHH_STATUS_MASK (0x8U)
#define SRC_CMU_FHH_STATUS_REG_CMU_11_FHH_STATUS_SHIFT (3U)
#define SRC_CMU_FHH_STATUS_REG_CMU_11_FHH_STATUS_WIDTH (1U)
#define SRC_CMU_FHH_STATUS_REG_CMU_11_FHH_STATUS(x) (((uint32_t)(((uint32_t)(x)) << SRC_CMU_FHH_STATUS_REG_CMU_11_FHH_STATUS_SHIFT)) & SRC_CMU_FHH_STATUS_REG_CMU_11_FHH_STATUS_MASK)

#define SRC_CMU_FHH_STATUS_REG_CMU_12_FHH_STATUS_MASK (0x10U)
#define SRC_CMU_FHH_STATUS_REG_CMU_12_FHH_STATUS_SHIFT (4U)
#define SRC_CMU_FHH_STATUS_REG_CMU_12_FHH_STATUS_WIDTH (1U)
#define SRC_CMU_FHH_STATUS_REG_CMU_12_FHH_STATUS(x) (((uint32_t)(((uint32_t)(x)) << SRC_CMU_FHH_STATUS_REG_CMU_12_FHH_STATUS_SHIFT)) & SRC_CMU_FHH_STATUS_REG_CMU_12_FHH_STATUS_MASK)

#define SRC_CMU_FHH_STATUS_REG_CMU_13_FHH_STATUS_MASK (0x20U)
#define SRC_CMU_FHH_STATUS_REG_CMU_13_FHH_STATUS_SHIFT (5U)
#define SRC_CMU_FHH_STATUS_REG_CMU_13_FHH_STATUS_WIDTH (1U)
#define SRC_CMU_FHH_STATUS_REG_CMU_13_FHH_STATUS(x) (((uint32_t)(((uint32_t)(x)) << SRC_CMU_FHH_STATUS_REG_CMU_13_FHH_STATUS_SHIFT)) & SRC_CMU_FHH_STATUS_REG_CMU_13_FHH_STATUS_MASK)

#define SRC_CMU_FHH_STATUS_REG_CMU_14_FHH_STATUS_MASK (0x40U)
#define SRC_CMU_FHH_STATUS_REG_CMU_14_FHH_STATUS_SHIFT (6U)
#define SRC_CMU_FHH_STATUS_REG_CMU_14_FHH_STATUS_WIDTH (1U)
#define SRC_CMU_FHH_STATUS_REG_CMU_14_FHH_STATUS(x) (((uint32_t)(((uint32_t)(x)) << SRC_CMU_FHH_STATUS_REG_CMU_14_FHH_STATUS_SHIFT)) & SRC_CMU_FHH_STATUS_REG_CMU_14_FHH_STATUS_MASK)

#define SRC_CMU_FHH_STATUS_REG_CMU_15_FHH_STATUS_MASK (0x80U)
#define SRC_CMU_FHH_STATUS_REG_CMU_15_FHH_STATUS_SHIFT (7U)
#define SRC_CMU_FHH_STATUS_REG_CMU_15_FHH_STATUS_WIDTH (1U)
#define SRC_CMU_FHH_STATUS_REG_CMU_15_FHH_STATUS(x) (((uint32_t)(((uint32_t)(x)) << SRC_CMU_FHH_STATUS_REG_CMU_15_FHH_STATUS_SHIFT)) & SRC_CMU_FHH_STATUS_REG_CMU_15_FHH_STATUS_MASK)

#define SRC_CMU_FHH_STATUS_REG_CMU_16_FHH_STATUS_MASK (0x100U)
#define SRC_CMU_FHH_STATUS_REG_CMU_16_FHH_STATUS_SHIFT (8U)
#define SRC_CMU_FHH_STATUS_REG_CMU_16_FHH_STATUS_WIDTH (1U)
#define SRC_CMU_FHH_STATUS_REG_CMU_16_FHH_STATUS(x) (((uint32_t)(((uint32_t)(x)) << SRC_CMU_FHH_STATUS_REG_CMU_16_FHH_STATUS_SHIFT)) & SRC_CMU_FHH_STATUS_REG_CMU_16_FHH_STATUS_MASK)

#define SRC_CMU_FHH_STATUS_REG_CMU_17_FHH_STATUS_MASK (0x200U)
#define SRC_CMU_FHH_STATUS_REG_CMU_17_FHH_STATUS_SHIFT (9U)
#define SRC_CMU_FHH_STATUS_REG_CMU_17_FHH_STATUS_WIDTH (1U)
#define SRC_CMU_FHH_STATUS_REG_CMU_17_FHH_STATUS(x) (((uint32_t)(((uint32_t)(x)) << SRC_CMU_FHH_STATUS_REG_CMU_17_FHH_STATUS_SHIFT)) & SRC_CMU_FHH_STATUS_REG_CMU_17_FHH_STATUS_MASK)

#define SRC_CMU_FHH_STATUS_REG_CMU_21_FHH_STATUS_MASK (0x400U)
#define SRC_CMU_FHH_STATUS_REG_CMU_21_FHH_STATUS_SHIFT (10U)
#define SRC_CMU_FHH_STATUS_REG_CMU_21_FHH_STATUS_WIDTH (1U)
#define SRC_CMU_FHH_STATUS_REG_CMU_21_FHH_STATUS(x) (((uint32_t)(((uint32_t)(x)) << SRC_CMU_FHH_STATUS_REG_CMU_21_FHH_STATUS_SHIFT)) & SRC_CMU_FHH_STATUS_REG_CMU_21_FHH_STATUS_MASK)

#define SRC_CMU_FHH_STATUS_REG_CMU_22_FHH_STATUS_MASK (0x800U)
#define SRC_CMU_FHH_STATUS_REG_CMU_22_FHH_STATUS_SHIFT (11U)
#define SRC_CMU_FHH_STATUS_REG_CMU_22_FHH_STATUS_WIDTH (1U)
#define SRC_CMU_FHH_STATUS_REG_CMU_22_FHH_STATUS(x) (((uint32_t)(((uint32_t)(x)) << SRC_CMU_FHH_STATUS_REG_CMU_22_FHH_STATUS_SHIFT)) & SRC_CMU_FHH_STATUS_REG_CMU_22_FHH_STATUS_MASK)

#define SRC_CMU_FHH_STATUS_REG_CMU_ACCEL_DIV3_CLK_FHH_STATUS_MASK (0x1000U)
#define SRC_CMU_FHH_STATUS_REG_CMU_ACCEL_DIV3_CLK_FHH_STATUS_SHIFT (12U)
#define SRC_CMU_FHH_STATUS_REG_CMU_ACCEL_DIV3_CLK_FHH_STATUS_WIDTH (1U)
#define SRC_CMU_FHH_STATUS_REG_CMU_ACCEL_DIV3_CLK_FHH_STATUS(x) (((uint32_t)(((uint32_t)(x)) << SRC_CMU_FHH_STATUS_REG_CMU_ACCEL_DIV3_CLK_FHH_STATUS_SHIFT)) & SRC_CMU_FHH_STATUS_REG_CMU_ACCEL_DIV3_CLK_FHH_STATUS_MASK)

#define SRC_CMU_FHH_STATUS_REG_CMU_CSI_CFG_CLK_FHH_STATUS_MASK (0x2000U)
#define SRC_CMU_FHH_STATUS_REG_CMU_CSI_CFG_CLK_FHH_STATUS_SHIFT (13U)
#define SRC_CMU_FHH_STATUS_REG_CMU_CSI_CFG_CLK_FHH_STATUS_WIDTH (1U)
#define SRC_CMU_FHH_STATUS_REG_CMU_CSI_CFG_CLK_FHH_STATUS(x) (((uint32_t)(((uint32_t)(x)) << SRC_CMU_FHH_STATUS_REG_CMU_CSI_CFG_CLK_FHH_STATUS_SHIFT)) & SRC_CMU_FHH_STATUS_REG_CMU_CSI_CFG_CLK_FHH_STATUS_MASK)

#define SRC_CMU_FHH_STATUS_REG_CMU_CTE_CLK_FHH_STATUS_MASK (0x4000U)
#define SRC_CMU_FHH_STATUS_REG_CMU_CTE_CLK_FHH_STATUS_SHIFT (14U)
#define SRC_CMU_FHH_STATUS_REG_CMU_CTE_CLK_FHH_STATUS_WIDTH (1U)
#define SRC_CMU_FHH_STATUS_REG_CMU_CTE_CLK_FHH_STATUS(x) (((uint32_t)(((uint32_t)(x)) << SRC_CMU_FHH_STATUS_REG_CMU_CTE_CLK_FHH_STATUS_SHIFT)) & SRC_CMU_FHH_STATUS_REG_CMU_CTE_CLK_FHH_STATUS_MASK)

#define SRC_CMU_FHH_STATUS_REG_CMU_GMAC1_RX_CLK_FHH_STATUS_MASK (0x8000U)
#define SRC_CMU_FHH_STATUS_REG_CMU_GMAC1_RX_CLK_FHH_STATUS_SHIFT (15U)
#define SRC_CMU_FHH_STATUS_REG_CMU_GMAC1_RX_CLK_FHH_STATUS_WIDTH (1U)
#define SRC_CMU_FHH_STATUS_REG_CMU_GMAC1_RX_CLK_FHH_STATUS(x) (((uint32_t)(((uint32_t)(x)) << SRC_CMU_FHH_STATUS_REG_CMU_GMAC1_RX_CLK_FHH_STATUS_SHIFT)) & SRC_CMU_FHH_STATUS_REG_CMU_GMAC1_RX_CLK_FHH_STATUS_MASK)

#define SRC_CMU_FHH_STATUS_REG_CMU_GMAC1_TX_CLK_FHH_STATUS_MASK (0x10000U)
#define SRC_CMU_FHH_STATUS_REG_CMU_GMAC1_TX_CLK_FHH_STATUS_SHIFT (16U)
#define SRC_CMU_FHH_STATUS_REG_CMU_GMAC1_TX_CLK_FHH_STATUS_WIDTH (1U)
#define SRC_CMU_FHH_STATUS_REG_CMU_GMAC1_TX_CLK_FHH_STATUS(x) (((uint32_t)(((uint32_t)(x)) << SRC_CMU_FHH_STATUS_REG_CMU_GMAC1_TX_CLK_FHH_STATUS_SHIFT)) & SRC_CMU_FHH_STATUS_REG_CMU_GMAC1_TX_CLK_FHH_STATUS_MASK)

#define SRC_CMU_FHH_STATUS_REG_CMU_GMAC1_TS_CLK_FHH_STATUS_MASK (0x20000U)
#define SRC_CMU_FHH_STATUS_REG_CMU_GMAC1_TS_CLK_FHH_STATUS_SHIFT (17U)
#define SRC_CMU_FHH_STATUS_REG_CMU_GMAC1_TS_CLK_FHH_STATUS_WIDTH (1U)
#define SRC_CMU_FHH_STATUS_REG_CMU_GMAC1_TS_CLK_FHH_STATUS(x) (((uint32_t)(((uint32_t)(x)) << SRC_CMU_FHH_STATUS_REG_CMU_GMAC1_TS_CLK_FHH_STATUS_SHIFT)) & SRC_CMU_FHH_STATUS_REG_CMU_GMAC1_TS_CLK_FHH_STATUS_MASK)

#define SRC_CMU_FHH_STATUS_REG_a53_cluster_FHH_STATUS_MASK (0x40000U)
#define SRC_CMU_FHH_STATUS_REG_a53_cluster_FHH_STATUS_SHIFT (18U)
#define SRC_CMU_FHH_STATUS_REG_a53_cluster_FHH_STATUS_WIDTH (1U)
#define SRC_CMU_FHH_STATUS_REG_a53_cluster_FHH_STATUS(x) (((uint32_t)(((uint32_t)(x)) << SRC_CMU_FHH_STATUS_REG_a53_cluster_FHH_STATUS_SHIFT)) & SRC_CMU_FHH_STATUS_REG_a53_cluster_FHH_STATUS_MASK)
/*! @} */

/*! @name GMAC_2_CTRL_REG - GMAC_2 Control */
/*! @{ */

#define SRC_GMAC_2_CTRL_REG_GMAC0_MIPICSI2_ID_MASK (0x3U)
#define SRC_GMAC_2_CTRL_REG_GMAC0_MIPICSI2_ID_SHIFT (0U)
#define SRC_GMAC_2_CTRL_REG_GMAC0_MIPICSI2_ID_WIDTH (2U)
#define SRC_GMAC_2_CTRL_REG_GMAC0_MIPICSI2_ID(x) (((uint32_t)(((uint32_t)(x)) << SRC_GMAC_2_CTRL_REG_GMAC0_MIPICSI2_ID_SHIFT)) & SRC_GMAC_2_CTRL_REG_GMAC0_MIPICSI2_ID_MASK)

#define SRC_GMAC_2_CTRL_REG_GMAC_0_VC_ID_MASK    (0xCU)
#define SRC_GMAC_2_CTRL_REG_GMAC_0_VC_ID_SHIFT   (2U)
#define SRC_GMAC_2_CTRL_REG_GMAC_0_VC_ID_WIDTH   (2U)
#define SRC_GMAC_2_CTRL_REG_GMAC_0_VC_ID(x)      (((uint32_t)(((uint32_t)(x)) << SRC_GMAC_2_CTRL_REG_GMAC_0_VC_ID_SHIFT)) & SRC_GMAC_2_CTRL_REG_GMAC_0_VC_ID_MASK)

#define SRC_GMAC_2_CTRL_REG_GMAC_1_VC_ID_MASK    (0x30U)
#define SRC_GMAC_2_CTRL_REG_GMAC_1_VC_ID_SHIFT   (4U)
#define SRC_GMAC_2_CTRL_REG_GMAC_1_VC_ID_WIDTH   (2U)
#define SRC_GMAC_2_CTRL_REG_GMAC_1_VC_ID(x)      (((uint32_t)(((uint32_t)(x)) << SRC_GMAC_2_CTRL_REG_GMAC_1_VC_ID_SHIFT)) & SRC_GMAC_2_CTRL_REG_GMAC_1_VC_ID_MASK)
/*! @} */

/*! @name DSP_PFAULT_SEL - DSP PFAULT Select */
/*! @{ */

#define SRC_DSP_PFAULT_SEL_dsp_pfault_sel_MASK   (0x1U)
#define SRC_DSP_PFAULT_SEL_dsp_pfault_sel_SHIFT  (0U)
#define SRC_DSP_PFAULT_SEL_dsp_pfault_sel_WIDTH  (1U)
#define SRC_DSP_PFAULT_SEL_dsp_pfault_sel(x)     (((uint32_t)(((uint32_t)(x)) << SRC_DSP_PFAULT_SEL_dsp_pfault_sel_SHIFT)) & SRC_DSP_PFAULT_SEL_dsp_pfault_sel_MASK)
/*! @} */

/*! @name PRAM_AHB_ALARM - PRAM AHB Alarm */
/*! @{ */

#define SRC_PRAM_AHB_ALARM_pram0_fccu_ahb_alarm_MASK (0x1U)
#define SRC_PRAM_AHB_ALARM_pram0_fccu_ahb_alarm_SHIFT (0U)
#define SRC_PRAM_AHB_ALARM_pram0_fccu_ahb_alarm_WIDTH (1U)
#define SRC_PRAM_AHB_ALARM_pram0_fccu_ahb_alarm(x) (((uint32_t)(((uint32_t)(x)) << SRC_PRAM_AHB_ALARM_pram0_fccu_ahb_alarm_SHIFT)) & SRC_PRAM_AHB_ALARM_pram0_fccu_ahb_alarm_MASK)

#define SRC_PRAM_AHB_ALARM_pram1_fccu_ahb_alarm_MASK (0x2U)
#define SRC_PRAM_AHB_ALARM_pram1_fccu_ahb_alarm_SHIFT (1U)
#define SRC_PRAM_AHB_ALARM_pram1_fccu_ahb_alarm_WIDTH (1U)
#define SRC_PRAM_AHB_ALARM_pram1_fccu_ahb_alarm(x) (((uint32_t)(((uint32_t)(x)) << SRC_PRAM_AHB_ALARM_pram1_fccu_ahb_alarm_SHIFT)) & SRC_PRAM_AHB_ALARM_pram1_fccu_ahb_alarm_MASK)

#define SRC_PRAM_AHB_ALARM_pram2_fccu_ahb_alarm_MASK (0x4U)
#define SRC_PRAM_AHB_ALARM_pram2_fccu_ahb_alarm_SHIFT (2U)
#define SRC_PRAM_AHB_ALARM_pram2_fccu_ahb_alarm_WIDTH (1U)
#define SRC_PRAM_AHB_ALARM_pram2_fccu_ahb_alarm(x) (((uint32_t)(((uint32_t)(x)) << SRC_PRAM_AHB_ALARM_pram2_fccu_ahb_alarm_SHIFT)) & SRC_PRAM_AHB_ALARM_pram2_fccu_ahb_alarm_MASK)

#define SRC_PRAM_AHB_ALARM_pram3_fccu_ahb_alarm_MASK (0x8U)
#define SRC_PRAM_AHB_ALARM_pram3_fccu_ahb_alarm_SHIFT (3U)
#define SRC_PRAM_AHB_ALARM_pram3_fccu_ahb_alarm_WIDTH (1U)
#define SRC_PRAM_AHB_ALARM_pram3_fccu_ahb_alarm(x) (((uint32_t)(((uint32_t)(x)) << SRC_PRAM_AHB_ALARM_pram3_fccu_ahb_alarm_SHIFT)) & SRC_PRAM_AHB_ALARM_pram3_fccu_ahb_alarm_MASK)

#define SRC_PRAM_AHB_ALARM_pram4_fccu_ahb_alarm_MASK (0x10U)
#define SRC_PRAM_AHB_ALARM_pram4_fccu_ahb_alarm_SHIFT (4U)
#define SRC_PRAM_AHB_ALARM_pram4_fccu_ahb_alarm_WIDTH (1U)
#define SRC_PRAM_AHB_ALARM_pram4_fccu_ahb_alarm(x) (((uint32_t)(((uint32_t)(x)) << SRC_PRAM_AHB_ALARM_pram4_fccu_ahb_alarm_SHIFT)) & SRC_PRAM_AHB_ALARM_pram4_fccu_ahb_alarm_MASK)

#define SRC_PRAM_AHB_ALARM_pram5_fccu_ahb_alarm_MASK (0x20U)
#define SRC_PRAM_AHB_ALARM_pram5_fccu_ahb_alarm_SHIFT (5U)
#define SRC_PRAM_AHB_ALARM_pram5_fccu_ahb_alarm_WIDTH (1U)
#define SRC_PRAM_AHB_ALARM_pram5_fccu_ahb_alarm(x) (((uint32_t)(((uint32_t)(x)) << SRC_PRAM_AHB_ALARM_pram5_fccu_ahb_alarm_SHIFT)) & SRC_PRAM_AHB_ALARM_pram5_fccu_ahb_alarm_MASK)

#define SRC_PRAM_AHB_ALARM_pram6_fccu_ahb_alarm_MASK (0x40U)
#define SRC_PRAM_AHB_ALARM_pram6_fccu_ahb_alarm_SHIFT (6U)
#define SRC_PRAM_AHB_ALARM_pram6_fccu_ahb_alarm_WIDTH (1U)
#define SRC_PRAM_AHB_ALARM_pram6_fccu_ahb_alarm(x) (((uint32_t)(((uint32_t)(x)) << SRC_PRAM_AHB_ALARM_pram6_fccu_ahb_alarm_SHIFT)) & SRC_PRAM_AHB_ALARM_pram6_fccu_ahb_alarm_MASK)

#define SRC_PRAM_AHB_ALARM_pram7_fccu_ahb_alarm_MASK (0x80U)
#define SRC_PRAM_AHB_ALARM_pram7_fccu_ahb_alarm_SHIFT (7U)
#define SRC_PRAM_AHB_ALARM_pram7_fccu_ahb_alarm_WIDTH (1U)
#define SRC_PRAM_AHB_ALARM_pram7_fccu_ahb_alarm(x) (((uint32_t)(((uint32_t)(x)) << SRC_PRAM_AHB_ALARM_pram7_fccu_ahb_alarm_SHIFT)) & SRC_PRAM_AHB_ALARM_pram7_fccu_ahb_alarm_MASK)

#define SRC_PRAM_AHB_ALARM_pram8_fccu_ahb_alarm_MASK (0x100U)
#define SRC_PRAM_AHB_ALARM_pram8_fccu_ahb_alarm_SHIFT (8U)
#define SRC_PRAM_AHB_ALARM_pram8_fccu_ahb_alarm_WIDTH (1U)
#define SRC_PRAM_AHB_ALARM_pram8_fccu_ahb_alarm(x) (((uint32_t)(((uint32_t)(x)) << SRC_PRAM_AHB_ALARM_pram8_fccu_ahb_alarm_SHIFT)) & SRC_PRAM_AHB_ALARM_pram8_fccu_ahb_alarm_MASK)
/*! @} */

/*! @name EDC_ERR_OUT - EDC Error Out */
/*! @{ */

#define SRC_EDC_ERR_OUT_rd_app_edc_err_out_MASK  (0x1U)
#define SRC_EDC_ERR_OUT_rd_app_edc_err_out_SHIFT (0U)
#define SRC_EDC_ERR_OUT_rd_app_edc_err_out_WIDTH (1U)
#define SRC_EDC_ERR_OUT_rd_app_edc_err_out(x)    (((uint32_t)(((uint32_t)(x)) << SRC_EDC_ERR_OUT_rd_app_edc_err_out_SHIFT)) & SRC_EDC_ERR_OUT_rd_app_edc_err_out_MASK)

#define SRC_EDC_ERR_OUT_rd_cm7_0_ahbm_edc_err_out_MASK (0x2U)
#define SRC_EDC_ERR_OUT_rd_cm7_0_ahbm_edc_err_out_SHIFT (1U)
#define SRC_EDC_ERR_OUT_rd_cm7_0_ahbm_edc_err_out_WIDTH (1U)
#define SRC_EDC_ERR_OUT_rd_cm7_0_ahbm_edc_err_out(x) (((uint32_t)(((uint32_t)(x)) << SRC_EDC_ERR_OUT_rd_cm7_0_ahbm_edc_err_out_SHIFT)) & SRC_EDC_ERR_OUT_rd_cm7_0_ahbm_edc_err_out_MASK)

#define SRC_EDC_ERR_OUT_rd_cm7_0_ahbp_edc_err_out_MASK (0x4U)
#define SRC_EDC_ERR_OUT_rd_cm7_0_ahbp_edc_err_out_SHIFT (2U)
#define SRC_EDC_ERR_OUT_rd_cm7_0_ahbp_edc_err_out_WIDTH (1U)
#define SRC_EDC_ERR_OUT_rd_cm7_0_ahbp_edc_err_out(x) (((uint32_t)(((uint32_t)(x)) << SRC_EDC_ERR_OUT_rd_cm7_0_ahbp_edc_err_out_SHIFT)) & SRC_EDC_ERR_OUT_rd_cm7_0_ahbp_edc_err_out_MASK)

#define SRC_EDC_ERR_OUT_rd_cm7_1_ahbm_edc_err_out_MASK (0x8U)
#define SRC_EDC_ERR_OUT_rd_cm7_1_ahbm_edc_err_out_SHIFT (3U)
#define SRC_EDC_ERR_OUT_rd_cm7_1_ahbm_edc_err_out_WIDTH (1U)
#define SRC_EDC_ERR_OUT_rd_cm7_1_ahbm_edc_err_out(x) (((uint32_t)(((uint32_t)(x)) << SRC_EDC_ERR_OUT_rd_cm7_1_ahbm_edc_err_out_SHIFT)) & SRC_EDC_ERR_OUT_rd_cm7_1_ahbm_edc_err_out_MASK)

#define SRC_EDC_ERR_OUT_rd_cm7_1_ahbp_edc_err_out_MASK (0x10U)
#define SRC_EDC_ERR_OUT_rd_cm7_1_ahbp_edc_err_out_SHIFT (4U)
#define SRC_EDC_ERR_OUT_rd_cm7_1_ahbp_edc_err_out_WIDTH (1U)
#define SRC_EDC_ERR_OUT_rd_cm7_1_ahbp_edc_err_out(x) (((uint32_t)(((uint32_t)(x)) << SRC_EDC_ERR_OUT_rd_cm7_1_ahbp_edc_err_out_SHIFT)) & SRC_EDC_ERR_OUT_rd_cm7_1_ahbp_edc_err_out_MASK)

#define SRC_EDC_ERR_OUT_rd_dbg_edc_err_out_MASK  (0x20U)
#define SRC_EDC_ERR_OUT_rd_dbg_edc_err_out_SHIFT (5U)
#define SRC_EDC_ERR_OUT_rd_dbg_edc_err_out_WIDTH (1U)
#define SRC_EDC_ERR_OUT_rd_dbg_edc_err_out(x)    (((uint32_t)(((uint32_t)(x)) << SRC_EDC_ERR_OUT_rd_dbg_edc_err_out_SHIFT)) & SRC_EDC_ERR_OUT_rd_dbg_edc_err_out_MASK)

#define SRC_EDC_ERR_OUT_rd_edma_edc_err_out_MASK (0x40U)
#define SRC_EDC_ERR_OUT_rd_edma_edc_err_out_SHIFT (6U)
#define SRC_EDC_ERR_OUT_rd_edma_edc_err_out_WIDTH (1U)
#define SRC_EDC_ERR_OUT_rd_edma_edc_err_out(x)   (((uint32_t)(((uint32_t)(x)) << SRC_EDC_ERR_OUT_rd_edma_edc_err_out_SHIFT)) & SRC_EDC_ERR_OUT_rd_edma_edc_err_out_MASK)

#define SRC_EDC_ERR_OUT_rd_enet_edc_err_out_MASK (0x80U)
#define SRC_EDC_ERR_OUT_rd_enet_edc_err_out_SHIFT (7U)
#define SRC_EDC_ERR_OUT_rd_enet_edc_err_out_WIDTH (1U)
#define SRC_EDC_ERR_OUT_rd_enet_edc_err_out(x)   (((uint32_t)(((uint32_t)(x)) << SRC_EDC_ERR_OUT_rd_enet_edc_err_out_SHIFT)) & SRC_EDC_ERR_OUT_rd_enet_edc_err_out_MASK)

#define SRC_EDC_ERR_OUT_rd_hse_edc_err_out_MASK  (0x100U)
#define SRC_EDC_ERR_OUT_rd_hse_edc_err_out_SHIFT (8U)
#define SRC_EDC_ERR_OUT_rd_hse_edc_err_out_WIDTH (1U)
#define SRC_EDC_ERR_OUT_rd_hse_edc_err_out(x)    (((uint32_t)(((uint32_t)(x)) << SRC_EDC_ERR_OUT_rd_hse_edc_err_out_SHIFT)) & SRC_EDC_ERR_OUT_rd_hse_edc_err_out_MASK)

#define SRC_EDC_ERR_OUT_rd_tcm_edc_err_out_MASK  (0x400U)
#define SRC_EDC_ERR_OUT_rd_tcm_edc_err_out_SHIFT (10U)
#define SRC_EDC_ERR_OUT_rd_tcm_edc_err_out_WIDTH (1U)
#define SRC_EDC_ERR_OUT_rd_tcm_edc_err_out(x)    (((uint32_t)(((uint32_t)(x)) << SRC_EDC_ERR_OUT_rd_tcm_edc_err_out_SHIFT)) & SRC_EDC_ERR_OUT_rd_tcm_edc_err_out_MASK)

#define SRC_EDC_ERR_OUT_rd_app_periph_edc_err_out_MASK (0x800U)
#define SRC_EDC_ERR_OUT_rd_app_periph_edc_err_out_SHIFT (11U)
#define SRC_EDC_ERR_OUT_rd_app_periph_edc_err_out_WIDTH (1U)
#define SRC_EDC_ERR_OUT_rd_app_periph_edc_err_out(x) (((uint32_t)(((uint32_t)(x)) << SRC_EDC_ERR_OUT_rd_app_periph_edc_err_out_SHIFT)) & SRC_EDC_ERR_OUT_rd_app_periph_edc_err_out_MASK)

#define SRC_EDC_ERR_OUT_rd_app_pram_edc_err_out_MASK (0x1000U)
#define SRC_EDC_ERR_OUT_rd_app_pram_edc_err_out_SHIFT (12U)
#define SRC_EDC_ERR_OUT_rd_app_pram_edc_err_out_WIDTH (1U)
#define SRC_EDC_ERR_OUT_rd_app_pram_edc_err_out(x) (((uint32_t)(((uint32_t)(x)) << SRC_EDC_ERR_OUT_rd_app_pram_edc_err_out_SHIFT)) & SRC_EDC_ERR_OUT_rd_app_pram_edc_err_out_MASK)
/*! @} */

/*! @name FCCU_ALARM - FCCU Alarm 1 */
/*! @{ */

#define SRC_FCCU_ALARM_axbs_fccu_alarm_MASK      (0x1U)
#define SRC_FCCU_ALARM_axbs_fccu_alarm_SHIFT     (0U)
#define SRC_FCCU_ALARM_axbs_fccu_alarm_WIDTH     (1U)
#define SRC_FCCU_ALARM_axbs_fccu_alarm(x)        (((uint32_t)(((uint32_t)(x)) << SRC_FCCU_ALARM_axbs_fccu_alarm_SHIFT)) & SRC_FCCU_ALARM_axbs_fccu_alarm_MASK)

#define SRC_FCCU_ALARM_dma_axbs_fccu_error_MASK  (0x2U)
#define SRC_FCCU_ALARM_dma_axbs_fccu_error_SHIFT (1U)
#define SRC_FCCU_ALARM_dma_axbs_fccu_error_WIDTH (1U)
#define SRC_FCCU_ALARM_dma_axbs_fccu_error(x)    (((uint32_t)(((uint32_t)(x)) << SRC_FCCU_ALARM_dma_axbs_fccu_error_SHIFT)) & SRC_FCCU_ALARM_dma_axbs_fccu_error_MASK)

#define SRC_FCCU_ALARM_periph_axbs_fccu_alarm_MASK (0x4U)
#define SRC_FCCU_ALARM_periph_axbs_fccu_alarm_SHIFT (2U)
#define SRC_FCCU_ALARM_periph_axbs_fccu_alarm_WIDTH (1U)
#define SRC_FCCU_ALARM_periph_axbs_fccu_alarm(x) (((uint32_t)(((uint32_t)(x)) << SRC_FCCU_ALARM_periph_axbs_fccu_alarm_SHIFT)) & SRC_FCCU_ALARM_periph_axbs_fccu_alarm_MASK)

#define SRC_FCCU_ALARM_pram_axbs_fccu_error_MASK (0x8U)
#define SRC_FCCU_ALARM_pram_axbs_fccu_error_SHIFT (3U)
#define SRC_FCCU_ALARM_pram_axbs_fccu_error_WIDTH (1U)
#define SRC_FCCU_ALARM_pram_axbs_fccu_error(x)   (((uint32_t)(((uint32_t)(x)) << SRC_FCCU_ALARM_pram_axbs_fccu_error_SHIFT)) & SRC_FCCU_ALARM_pram_axbs_fccu_error_MASK)

#define SRC_FCCU_ALARM_pram_splt_fccu_error_MASK (0x10U)
#define SRC_FCCU_ALARM_pram_splt_fccu_error_SHIFT (4U)
#define SRC_FCCU_ALARM_pram_splt_fccu_error_WIDTH (1U)
#define SRC_FCCU_ALARM_pram_splt_fccu_error(x)   (((uint32_t)(((uint32_t)(x)) << SRC_FCCU_ALARM_pram_splt_fccu_error_SHIFT)) & SRC_FCCU_ALARM_pram_splt_fccu_error_MASK)

#define SRC_FCCU_ALARM_tcm_axbs_fccu_error_MASK  (0x20U)
#define SRC_FCCU_ALARM_tcm_axbs_fccu_error_SHIFT (5U)
#define SRC_FCCU_ALARM_tcm_axbs_fccu_error_WIDTH (1U)
#define SRC_FCCU_ALARM_tcm_axbs_fccu_error(x)    (((uint32_t)(((uint32_t)(x)) << SRC_FCCU_ALARM_tcm_axbs_fccu_error_SHIFT)) & SRC_FCCU_ALARM_tcm_axbs_fccu_error_MASK)

#define SRC_FCCU_ALARM_cm7_0_lockstep_debug_masked_fault_MASK (0x40U)
#define SRC_FCCU_ALARM_cm7_0_lockstep_debug_masked_fault_SHIFT (6U)
#define SRC_FCCU_ALARM_cm7_0_lockstep_debug_masked_fault_WIDTH (1U)
#define SRC_FCCU_ALARM_cm7_0_lockstep_debug_masked_fault(x) (((uint32_t)(((uint32_t)(x)) << SRC_FCCU_ALARM_cm7_0_lockstep_debug_masked_fault_SHIFT)) & SRC_FCCU_ALARM_cm7_0_lockstep_debug_masked_fault_MASK)

#define SRC_FCCU_ALARM_cm7_1_lockstep_debug_masked_fault_MASK (0x80U)
#define SRC_FCCU_ALARM_cm7_1_lockstep_debug_masked_fault_SHIFT (7U)
#define SRC_FCCU_ALARM_cm7_1_lockstep_debug_masked_fault_WIDTH (1U)
#define SRC_FCCU_ALARM_cm7_1_lockstep_debug_masked_fault(x) (((uint32_t)(((uint32_t)(x)) << SRC_FCCU_ALARM_cm7_1_lockstep_debug_masked_fault_SHIFT)) & SRC_FCCU_ALARM_cm7_1_lockstep_debug_masked_fault_MASK)

#define SRC_FCCU_ALARM_rccu_dma_1_alarm_MASK     (0x100U)
#define SRC_FCCU_ALARM_rccu_dma_1_alarm_SHIFT    (8U)
#define SRC_FCCU_ALARM_rccu_dma_1_alarm_WIDTH    (1U)
#define SRC_FCCU_ALARM_rccu_dma_1_alarm(x)       (((uint32_t)(((uint32_t)(x)) << SRC_FCCU_ALARM_rccu_dma_1_alarm_SHIFT)) & SRC_FCCU_ALARM_rccu_dma_1_alarm_MASK)

#define SRC_FCCU_ALARM_enet_mon_error_MASK       (0x200U)
#define SRC_FCCU_ALARM_enet_mon_error_SHIFT      (9U)
#define SRC_FCCU_ALARM_enet_mon_error_WIDTH      (1U)
#define SRC_FCCU_ALARM_enet_mon_error(x)         (((uint32_t)(((uint32_t)(x)) << SRC_FCCU_ALARM_enet_mon_error_SHIFT)) & SRC_FCCU_ALARM_enet_mon_error_MASK)
/*! @} */

/*! @name FCCU_ALARM_REG - FCCU Alarm 2 */
/*! @{ */

#define SRC_FCCU_ALARM_REG_aips0_gskt_mon_alarm_MASK (0x1U)
#define SRC_FCCU_ALARM_REG_aips0_gskt_mon_alarm_SHIFT (0U)
#define SRC_FCCU_ALARM_REG_aips0_gskt_mon_alarm_WIDTH (1U)
#define SRC_FCCU_ALARM_REG_aips0_gskt_mon_alarm(x) (((uint32_t)(((uint32_t)(x)) << SRC_FCCU_ALARM_REG_aips0_gskt_mon_alarm_SHIFT)) & SRC_FCCU_ALARM_REG_aips0_gskt_mon_alarm_MASK)

#define SRC_FCCU_ALARM_REG_aips1_gskt_mon_alarm_MASK (0x2U)
#define SRC_FCCU_ALARM_REG_aips1_gskt_mon_alarm_SHIFT (1U)
#define SRC_FCCU_ALARM_REG_aips1_gskt_mon_alarm_WIDTH (1U)
#define SRC_FCCU_ALARM_REG_aips1_gskt_mon_alarm(x) (((uint32_t)(((uint32_t)(x)) << SRC_FCCU_ALARM_REG_aips1_gskt_mon_alarm_SHIFT)) & SRC_FCCU_ALARM_REG_aips1_gskt_mon_alarm_MASK)

#define SRC_FCCU_ALARM_REG_aips2_gskt_mon_alarm_MASK (0x4U)
#define SRC_FCCU_ALARM_REG_aips2_gskt_mon_alarm_SHIFT (2U)
#define SRC_FCCU_ALARM_REG_aips2_gskt_mon_alarm_WIDTH (1U)
#define SRC_FCCU_ALARM_REG_aips2_gskt_mon_alarm(x) (((uint32_t)(((uint32_t)(x)) << SRC_FCCU_ALARM_REG_aips2_gskt_mon_alarm_SHIFT)) & SRC_FCCU_ALARM_REG_aips2_gskt_mon_alarm_MASK)

#define SRC_FCCU_ALARM_REG_dbg_gskt_mon_alarm_MASK (0x8U)
#define SRC_FCCU_ALARM_REG_dbg_gskt_mon_alarm_SHIFT (3U)
#define SRC_FCCU_ALARM_REG_dbg_gskt_mon_alarm_WIDTH (1U)
#define SRC_FCCU_ALARM_REG_dbg_gskt_mon_alarm(x) (((uint32_t)(((uint32_t)(x)) << SRC_FCCU_ALARM_REG_dbg_gskt_mon_alarm_SHIFT)) & SRC_FCCU_ALARM_REG_dbg_gskt_mon_alarm_MASK)

#define SRC_FCCU_ALARM_REG_dbg_slv_gskt_fccu_alarm_MASK (0x10U)
#define SRC_FCCU_ALARM_REG_dbg_slv_gskt_fccu_alarm_SHIFT (4U)
#define SRC_FCCU_ALARM_REG_dbg_slv_gskt_fccu_alarm_WIDTH (1U)
#define SRC_FCCU_ALARM_REG_dbg_slv_gskt_fccu_alarm(x) (((uint32_t)(((uint32_t)(x)) << SRC_FCCU_ALARM_REG_dbg_slv_gskt_fccu_alarm_SHIFT)) & SRC_FCCU_ALARM_REG_dbg_slv_gskt_fccu_alarm_MASK)

#define SRC_FCCU_ALARM_REG_dma_axbs_s0_gskt_mon_alarm_MASK (0x20U)
#define SRC_FCCU_ALARM_REG_dma_axbs_s0_gskt_mon_alarm_SHIFT (5U)
#define SRC_FCCU_ALARM_REG_dma_axbs_s0_gskt_mon_alarm_WIDTH (1U)
#define SRC_FCCU_ALARM_REG_dma_axbs_s0_gskt_mon_alarm(x) (((uint32_t)(((uint32_t)(x)) << SRC_FCCU_ALARM_REG_dma_axbs_s0_gskt_mon_alarm_SHIFT)) & SRC_FCCU_ALARM_REG_dma_axbs_s0_gskt_mon_alarm_MASK)

#define SRC_FCCU_ALARM_REG_dma_axbs_s1_gskt_mon_alarm_MASK (0x40U)
#define SRC_FCCU_ALARM_REG_dma_axbs_s1_gskt_mon_alarm_SHIFT (6U)
#define SRC_FCCU_ALARM_REG_dma_axbs_s1_gskt_mon_alarm_WIDTH (1U)
#define SRC_FCCU_ALARM_REG_dma_axbs_s1_gskt_mon_alarm(x) (((uint32_t)(((uint32_t)(x)) << SRC_FCCU_ALARM_REG_dma_axbs_s1_gskt_mon_alarm_SHIFT)) & SRC_FCCU_ALARM_REG_dma_axbs_s1_gskt_mon_alarm_MASK)

#define SRC_FCCU_ALARM_REG_enet_gskt_fccu_alarm_MASK (0x80U)
#define SRC_FCCU_ALARM_REG_enet_gskt_fccu_alarm_SHIFT (7U)
#define SRC_FCCU_ALARM_REG_enet_gskt_fccu_alarm_WIDTH (1U)
#define SRC_FCCU_ALARM_REG_enet_gskt_fccu_alarm(x) (((uint32_t)(((uint32_t)(x)) << SRC_FCCU_ALARM_REG_enet_gskt_fccu_alarm_SHIFT)) & SRC_FCCU_ALARM_REG_enet_gskt_fccu_alarm_MASK)

#define SRC_FCCU_ALARM_REG_hse_gskt_mon_alarm_MASK (0x100U)
#define SRC_FCCU_ALARM_REG_hse_gskt_mon_alarm_SHIFT (8U)
#define SRC_FCCU_ALARM_REG_hse_gskt_mon_alarm_WIDTH (1U)
#define SRC_FCCU_ALARM_REG_hse_gskt_mon_alarm(x) (((uint32_t)(((uint32_t)(x)) << SRC_FCCU_ALARM_REG_hse_gskt_mon_alarm_SHIFT)) & SRC_FCCU_ALARM_REG_hse_gskt_mon_alarm_MASK)

#define SRC_FCCU_ALARM_REG_pram_p0_gskt_fccu_alarm_MASK (0x200U)
#define SRC_FCCU_ALARM_REG_pram_p0_gskt_fccu_alarm_SHIFT (9U)
#define SRC_FCCU_ALARM_REG_pram_p0_gskt_fccu_alarm_WIDTH (1U)
#define SRC_FCCU_ALARM_REG_pram_p0_gskt_fccu_alarm(x) (((uint32_t)(((uint32_t)(x)) << SRC_FCCU_ALARM_REG_pram_p0_gskt_fccu_alarm_SHIFT)) & SRC_FCCU_ALARM_REG_pram_p0_gskt_fccu_alarm_MASK)

#define SRC_FCCU_ALARM_REG_pram_p1_gskt_fccu_alarm_MASK (0x400U)
#define SRC_FCCU_ALARM_REG_pram_p1_gskt_fccu_alarm_SHIFT (10U)
#define SRC_FCCU_ALARM_REG_pram_p1_gskt_fccu_alarm_WIDTH (1U)
#define SRC_FCCU_ALARM_REG_pram_p1_gskt_fccu_alarm(x) (((uint32_t)(((uint32_t)(x)) << SRC_FCCU_ALARM_REG_pram_p1_gskt_fccu_alarm_SHIFT)) & SRC_FCCU_ALARM_REG_pram_p1_gskt_fccu_alarm_MASK)

#define SRC_FCCU_ALARM_REG_pram_p2_gskt_fccu_alarm_MASK (0x800U)
#define SRC_FCCU_ALARM_REG_pram_p2_gskt_fccu_alarm_SHIFT (11U)
#define SRC_FCCU_ALARM_REG_pram_p2_gskt_fccu_alarm_WIDTH (1U)
#define SRC_FCCU_ALARM_REG_pram_p2_gskt_fccu_alarm(x) (((uint32_t)(((uint32_t)(x)) << SRC_FCCU_ALARM_REG_pram_p2_gskt_fccu_alarm_SHIFT)) & SRC_FCCU_ALARM_REG_pram_p2_gskt_fccu_alarm_MASK)

#define SRC_FCCU_ALARM_REG_pram_p3_gskt_fccu_alarm_MASK (0x1000U)
#define SRC_FCCU_ALARM_REG_pram_p3_gskt_fccu_alarm_SHIFT (12U)
#define SRC_FCCU_ALARM_REG_pram_p3_gskt_fccu_alarm_WIDTH (1U)
#define SRC_FCCU_ALARM_REG_pram_p3_gskt_fccu_alarm(x) (((uint32_t)(((uint32_t)(x)) << SRC_FCCU_ALARM_REG_pram_p3_gskt_fccu_alarm_SHIFT)) & SRC_FCCU_ALARM_REG_pram_p3_gskt_fccu_alarm_MASK)

#define SRC_FCCU_ALARM_REG_qspi_gskt_mon_alarm_MASK (0x2000U)
#define SRC_FCCU_ALARM_REG_qspi_gskt_mon_alarm_SHIFT (13U)
#define SRC_FCCU_ALARM_REG_qspi_gskt_mon_alarm_WIDTH (1U)
#define SRC_FCCU_ALARM_REG_qspi_gskt_mon_alarm(x) (((uint32_t)(((uint32_t)(x)) << SRC_FCCU_ALARM_REG_qspi_gskt_mon_alarm_SHIFT)) & SRC_FCCU_ALARM_REG_qspi_gskt_mon_alarm_MASK)

#define SRC_FCCU_ALARM_REG_s0_to_main_gskt_mon_alarm_MASK (0x4000U)
#define SRC_FCCU_ALARM_REG_s0_to_main_gskt_mon_alarm_SHIFT (14U)
#define SRC_FCCU_ALARM_REG_s0_to_main_gskt_mon_alarm_WIDTH (1U)
#define SRC_FCCU_ALARM_REG_s0_to_main_gskt_mon_alarm(x) (((uint32_t)(((uint32_t)(x)) << SRC_FCCU_ALARM_REG_s0_to_main_gskt_mon_alarm_SHIFT)) & SRC_FCCU_ALARM_REG_s0_to_main_gskt_mon_alarm_MASK)

#define SRC_FCCU_ALARM_REG_s_to_periph_gskt_mon_alarm_MASK (0x8000U)
#define SRC_FCCU_ALARM_REG_s_to_periph_gskt_mon_alarm_SHIFT (15U)
#define SRC_FCCU_ALARM_REG_s_to_periph_gskt_mon_alarm_WIDTH (1U)
#define SRC_FCCU_ALARM_REG_s_to_periph_gskt_mon_alarm(x) (((uint32_t)(((uint32_t)(x)) << SRC_FCCU_ALARM_REG_s_to_periph_gskt_mon_alarm_SHIFT)) & SRC_FCCU_ALARM_REG_s_to_periph_gskt_mon_alarm_MASK)

#define SRC_FCCU_ALARM_REG_tcm_gskt_fccu_alarm_MASK (0x20000U)
#define SRC_FCCU_ALARM_REG_tcm_gskt_fccu_alarm_SHIFT (17U)
#define SRC_FCCU_ALARM_REG_tcm_gskt_fccu_alarm_WIDTH (1U)
#define SRC_FCCU_ALARM_REG_tcm_gskt_fccu_alarm(x) (((uint32_t)(((uint32_t)(x)) << SRC_FCCU_ALARM_REG_tcm_gskt_fccu_alarm_SHIFT)) & SRC_FCCU_ALARM_REG_tcm_gskt_fccu_alarm_MASK)

#define SRC_FCCU_ALARM_REG_cm7_0_ahbp_gskt_fccu_alarm_MASK (0x40000U)
#define SRC_FCCU_ALARM_REG_cm7_0_ahbp_gskt_fccu_alarm_SHIFT (18U)
#define SRC_FCCU_ALARM_REG_cm7_0_ahbp_gskt_fccu_alarm_WIDTH (1U)
#define SRC_FCCU_ALARM_REG_cm7_0_ahbp_gskt_fccu_alarm(x) (((uint32_t)(((uint32_t)(x)) << SRC_FCCU_ALARM_REG_cm7_0_ahbp_gskt_fccu_alarm_SHIFT)) & SRC_FCCU_ALARM_REG_cm7_0_ahbp_gskt_fccu_alarm_MASK)

#define SRC_FCCU_ALARM_REG_cm7_1_ahbp_gskt_fccu_alarm_MASK (0x80000U)
#define SRC_FCCU_ALARM_REG_cm7_1_ahbp_gskt_fccu_alarm_SHIFT (19U)
#define SRC_FCCU_ALARM_REG_cm7_1_ahbp_gskt_fccu_alarm_WIDTH (1U)
#define SRC_FCCU_ALARM_REG_cm7_1_ahbp_gskt_fccu_alarm(x) (((uint32_t)(((uint32_t)(x)) << SRC_FCCU_ALARM_REG_cm7_1_ahbp_gskt_fccu_alarm_SHIFT)) & SRC_FCCU_ALARM_REG_cm7_1_ahbp_gskt_fccu_alarm_MASK)
/*! @} */

/*! @name MAIN_MISSION_INT_REG - Main Mission Interrupt Status */
/*! @{ */

#define SRC_MAIN_MISSION_INT_REG_MAIN_RESET_DOMAIN_mainMissionInt_MASK (0x1U)
#define SRC_MAIN_MISSION_INT_REG_MAIN_RESET_DOMAIN_mainMissionInt_SHIFT (0U)
#define SRC_MAIN_MISSION_INT_REG_MAIN_RESET_DOMAIN_mainMissionInt_WIDTH (1U)
#define SRC_MAIN_MISSION_INT_REG_MAIN_RESET_DOMAIN_mainMissionInt(x) (((uint32_t)(((uint32_t)(x)) << SRC_MAIN_MISSION_INT_REG_MAIN_RESET_DOMAIN_mainMissionInt_SHIFT)) & SRC_MAIN_MISSION_INT_REG_MAIN_RESET_DOMAIN_mainMissionInt_MASK)

#define SRC_MAIN_MISSION_INT_REG_PBridge_RESET_DOMAIN_mainMissionInt_MASK (0x2U)
#define SRC_MAIN_MISSION_INT_REG_PBridge_RESET_DOMAIN_mainMissionInt_SHIFT (1U)
#define SRC_MAIN_MISSION_INT_REG_PBridge_RESET_DOMAIN_mainMissionInt_WIDTH (1U)
#define SRC_MAIN_MISSION_INT_REG_PBridge_RESET_DOMAIN_mainMissionInt(x) (((uint32_t)(((uint32_t)(x)) << SRC_MAIN_MISSION_INT_REG_PBridge_RESET_DOMAIN_mainMissionInt_SHIFT)) & SRC_MAIN_MISSION_INT_REG_PBridge_RESET_DOMAIN_mainMissionInt_MASK)

#define SRC_MAIN_MISSION_INT_REG_SW_RESET_DOMAIN_mainMissionInt_MASK (0x4U)
#define SRC_MAIN_MISSION_INT_REG_SW_RESET_DOMAIN_mainMissionInt_SHIFT (2U)
#define SRC_MAIN_MISSION_INT_REG_SW_RESET_DOMAIN_mainMissionInt_WIDTH (1U)
#define SRC_MAIN_MISSION_INT_REG_SW_RESET_DOMAIN_mainMissionInt(x) (((uint32_t)(((uint32_t)(x)) << SRC_MAIN_MISSION_INT_REG_SW_RESET_DOMAIN_mainMissionInt_SHIFT)) & SRC_MAIN_MISSION_INT_REG_SW_RESET_DOMAIN_mainMissionInt_MASK)
/*! @} */

/*! @name BUS_DISABLE_OVERRIDE - Bus Disable Override */
/*! @{ */

#define SRC_BUS_DISABLE_OVERRIDE_bus_disable_override_MASK (0x1U)
#define SRC_BUS_DISABLE_OVERRIDE_bus_disable_override_SHIFT (0U)
#define SRC_BUS_DISABLE_OVERRIDE_bus_disable_override_WIDTH (1U)
#define SRC_BUS_DISABLE_OVERRIDE_bus_disable_override(x) (((uint32_t)(((uint32_t)(x)) << SRC_BUS_DISABLE_OVERRIDE_bus_disable_override_SHIFT)) & SRC_BUS_DISABLE_OVERRIDE_bus_disable_override_MASK)
/*! @} */

/*! @name RESET_REQUEST_REG - Reset Request */
/*! @{ */

#define SRC_RESET_REQUEST_REG_hse_disrgmrst_MASK (0x1U)
#define SRC_RESET_REQUEST_REG_hse_disrgmrst_SHIFT (0U)
#define SRC_RESET_REQUEST_REG_hse_disrgmrst_WIDTH (1U)
#define SRC_RESET_REQUEST_REG_hse_disrgmrst(x)   (((uint32_t)(((uint32_t)(x)) << SRC_RESET_REQUEST_REG_hse_disrgmrst_SHIFT)) & SRC_RESET_REQUEST_REG_hse_disrgmrst_MASK)
/*! @} */

/*! @name PIPE_PARITY_MODE_DATA_CTRL1_REG - Pipe Parity Control 1 */
/*! @{ */

#define SRC_PIPE_PARITY_MODE_DATA_CTRL1_REG_PARITY_SEL_MASK (0x7FFFU)
#define SRC_PIPE_PARITY_MODE_DATA_CTRL1_REG_PARITY_SEL_SHIFT (0U)
#define SRC_PIPE_PARITY_MODE_DATA_CTRL1_REG_PARITY_SEL_WIDTH (15U)
#define SRC_PIPE_PARITY_MODE_DATA_CTRL1_REG_PARITY_SEL(x) (((uint32_t)(((uint32_t)(x)) << SRC_PIPE_PARITY_MODE_DATA_CTRL1_REG_PARITY_SEL_SHIFT)) & SRC_PIPE_PARITY_MODE_DATA_CTRL1_REG_PARITY_SEL_MASK)
/*! @} */

/*! @name DSP_IP_REGISTER - DSP IP Status */
/*! @{ */

#define SRC_DSP_IP_REGISTER_DSP_IP_bit_MASK      (0x1U)
#define SRC_DSP_IP_REGISTER_DSP_IP_bit_SHIFT     (0U)
#define SRC_DSP_IP_REGISTER_DSP_IP_bit_WIDTH     (1U)
#define SRC_DSP_IP_REGISTER_DSP_IP_bit(x)        (((uint32_t)(((uint32_t)(x)) << SRC_DSP_IP_REGISTER_DSP_IP_bit_SHIFT)) & SRC_DSP_IP_REGISTER_DSP_IP_bit_MASK)
/*! @} */

/*! @name ATP_REG - ATP Status */
/*! @{ */

#define SRC_ATP_REG_ATP_ipp_pad_MASK             (0x1U)
#define SRC_ATP_REG_ATP_ipp_pad_SHIFT            (0U)
#define SRC_ATP_REG_ATP_ipp_pad_WIDTH            (1U)
#define SRC_ATP_REG_ATP_ipp_pad(x)               (((uint32_t)(((uint32_t)(x)) << SRC_ATP_REG_ATP_ipp_pad_SHIFT)) & SRC_ATP_REG_ATP_ipp_pad_MASK)
/*! @} */

/*! @name DEBUG_CONTROL - Debug Control */
/*! @{ */

#define SRC_DEBUG_CONTROL_CA53_0_DBGL1RSTDISABLE_MASK (0x2U)
#define SRC_DEBUG_CONTROL_CA53_0_DBGL1RSTDISABLE_SHIFT (1U)
#define SRC_DEBUG_CONTROL_CA53_0_DBGL1RSTDISABLE_WIDTH (1U)
#define SRC_DEBUG_CONTROL_CA53_0_DBGL1RSTDISABLE(x) (((uint32_t)(((uint32_t)(x)) << SRC_DEBUG_CONTROL_CA53_0_DBGL1RSTDISABLE_SHIFT)) & SRC_DEBUG_CONTROL_CA53_0_DBGL1RSTDISABLE_MASK)

#define SRC_DEBUG_CONTROL_DBG_SETUP_DONE_MASK    (0x4U)
#define SRC_DEBUG_CONTROL_DBG_SETUP_DONE_SHIFT   (2U)
#define SRC_DEBUG_CONTROL_DBG_SETUP_DONE_WIDTH   (1U)
#define SRC_DEBUG_CONTROL_DBG_SETUP_DONE(x)      (((uint32_t)(((uint32_t)(x)) << SRC_DEBUG_CONTROL_DBG_SETUP_DONE_SHIFT)) & SRC_DEBUG_CONTROL_DBG_SETUP_DONE_MASK)

#define SRC_DEBUG_CONTROL_JTAG_ACTIVE_MASK       (0x8U)
#define SRC_DEBUG_CONTROL_JTAG_ACTIVE_SHIFT      (3U)
#define SRC_DEBUG_CONTROL_JTAG_ACTIVE_WIDTH      (1U)
#define SRC_DEBUG_CONTROL_JTAG_ACTIVE(x)         (((uint32_t)(((uint32_t)(x)) << SRC_DEBUG_CONTROL_JTAG_ACTIVE_SHIFT)) & SRC_DEBUG_CONTROL_JTAG_ACTIVE_MASK)

#define SRC_DEBUG_CONTROL_CA53_0_L2RSTDISABLE_MASK (0x10U)
#define SRC_DEBUG_CONTROL_CA53_0_L2RSTDISABLE_SHIFT (4U)
#define SRC_DEBUG_CONTROL_CA53_0_L2RSTDISABLE_WIDTH (1U)
#define SRC_DEBUG_CONTROL_CA53_0_L2RSTDISABLE(x) (((uint32_t)(((uint32_t)(x)) << SRC_DEBUG_CONTROL_CA53_0_L2RSTDISABLE_SHIFT)) & SRC_DEBUG_CONTROL_CA53_0_L2RSTDISABLE_MASK)

#define SRC_DEBUG_CONTROL_DBG_RST_MSK_0a_MASK    (0x20U)
#define SRC_DEBUG_CONTROL_DBG_RST_MSK_0a_SHIFT   (5U)
#define SRC_DEBUG_CONTROL_DBG_RST_MSK_0a_WIDTH   (1U)
#define SRC_DEBUG_CONTROL_DBG_RST_MSK_0a(x)      (((uint32_t)(((uint32_t)(x)) << SRC_DEBUG_CONTROL_DBG_RST_MSK_0a_SHIFT)) & SRC_DEBUG_CONTROL_DBG_RST_MSK_0a_MASK)

#define SRC_DEBUG_CONTROL_READY_FOR_DEBUG_MASK   (0x40U)
#define SRC_DEBUG_CONTROL_READY_FOR_DEBUG_SHIFT  (6U)
#define SRC_DEBUG_CONTROL_READY_FOR_DEBUG_WIDTH  (1U)
#define SRC_DEBUG_CONTROL_READY_FOR_DEBUG(x)     (((uint32_t)(((uint32_t)(x)) << SRC_DEBUG_CONTROL_READY_FOR_DEBUG_SHIFT)) & SRC_DEBUG_CONTROL_READY_FOR_DEBUG_MASK)

#define SRC_DEBUG_CONTROL_DBG_RST_MSK_1a_MASK    (0x80U)
#define SRC_DEBUG_CONTROL_DBG_RST_MSK_1a_SHIFT   (7U)
#define SRC_DEBUG_CONTROL_DBG_RST_MSK_1a_WIDTH   (1U)
#define SRC_DEBUG_CONTROL_DBG_RST_MSK_1a(x)      (((uint32_t)(((uint32_t)(x)) << SRC_DEBUG_CONTROL_DBG_RST_MSK_1a_SHIFT)) & SRC_DEBUG_CONTROL_DBG_RST_MSK_1a_MASK)
/*! @} */

/*! @name TIMESTAMP_CONTROL_REGISTER - Timestamp Control */
/*! @{ */

#define SRC_TIMESTAMP_CONTROL_REGISTER_CAN_TS_CNT_SEL_MASK (0x3U)
#define SRC_TIMESTAMP_CONTROL_REGISTER_CAN_TS_CNT_SEL_SHIFT (0U)
#define SRC_TIMESTAMP_CONTROL_REGISTER_CAN_TS_CNT_SEL_WIDTH (2U)
#define SRC_TIMESTAMP_CONTROL_REGISTER_CAN_TS_CNT_SEL(x) (((uint32_t)(((uint32_t)(x)) << SRC_TIMESTAMP_CONTROL_REGISTER_CAN_TS_CNT_SEL_SHIFT)) & SRC_TIMESTAMP_CONTROL_REGISTER_CAN_TS_CNT_SEL_MASK)

#define SRC_TIMESTAMP_CONTROL_REGISTER_TS_ENABLE_MASK (0x4U)
#define SRC_TIMESTAMP_CONTROL_REGISTER_TS_ENABLE_SHIFT (2U)
#define SRC_TIMESTAMP_CONTROL_REGISTER_TS_ENABLE_WIDTH (1U)
#define SRC_TIMESTAMP_CONTROL_REGISTER_TS_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << SRC_TIMESTAMP_CONTROL_REGISTER_TS_ENABLE_SHIFT)) & SRC_TIMESTAMP_CONTROL_REGISTER_TS_ENABLE_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group SRC_Register_Masks */

/*!
 * @}
 */ /* end of group SRC_Peripheral_Access_Layer */

#endif  /* #if !defined(S32R41_SRC_H_) */
