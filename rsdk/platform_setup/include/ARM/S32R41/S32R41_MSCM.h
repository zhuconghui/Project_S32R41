/*
** ###################################################################
**     Processor:           S32R41_A53
**     Compiler:            Keil ARM C/C++ Compiler
**     Reference manual:    S32R41 RM Rev.1
**     Version:             rev. 1.4, 2021-11-10
**     Build:               b211109
**
**     Abstract:
**         Peripheral Access Layer for S32R41_A53
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2021 NXP
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
 * @file S32R41_MSCM.h
 * @version 1.4
 * @date 2021-11-10
 * @brief Peripheral Access Layer for S32R41_MSCM
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
#if !defined(S32R41_MSCM_H_)  /* Check if memory map has not been already included */
#define S32R41_MSCM_H_

#include "S32R41_COMMON.h"

/* ----------------------------------------------------------------------------
   -- MSCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MSCM_Peripheral_Access_Layer MSCM Peripheral Access Layer
 * @{
 */

/** MSCM - Size of Registers Arrays */
#define MSCM_IRSPRC_COUNT                         240u

/** MSCM - Register Layout Typedef */
typedef struct {
  __I  uint32_t CPXTYPE;                           /**< Processor x Type, offset: 0x0 */
  __I  uint32_t CPXNUM;                            /**< Processor x Number, offset: 0x4 */
  __I  uint32_t CPXREV;                            /**< Processor x Revision, offset: 0x8 */
  __I  uint32_t CPXCFG0;                           /**< Processor x Configuration 0, offset: 0xC */
  __I  uint32_t CPXCFG1;                           /**< Processor x Configuration 1, offset: 0x10 */
  __I  uint32_t CPXCFG2;                           /**< Processor x Configuration 2, offset: 0x14 */
  __I  uint32_t CPXCFG3;                           /**< Processor x Configuration 3, offset: 0x18 */
  uint8_t RESERVED_0[4];
  __I  uint32_t CP0TYPE;                           /**< Processor 0 Type, offset: 0x20 */
  __I  uint32_t CP0NUM;                            /**< Processor 0 Number, offset: 0x24 */
  __I  uint32_t CP0REV;                            /**< Processor 0 Count, offset: 0x28 */
  __I  uint32_t CP0CFG0;                           /**< Processor 0 Configuration 0, offset: 0x2C */
  __I  uint32_t CP0CFG1;                           /**< Processor 0 Configuration 1, offset: 0x30 */
  __I  uint32_t CP0CFG2;                           /**< Processor 0 Configuration 2, offset: 0x34 */
  __I  uint32_t CP0CFG3;                           /**< Processor 0 Configuration 3, offset: 0x38 */
  uint8_t RESERVED_1[4];
  __I  uint32_t CP1TYPE;                           /**< Processor 1 Type, offset: 0x40 */
  __I  uint32_t CP1NUM;                            /**< Processor 1 Number, offset: 0x44 */
  __I  uint32_t CP1REV;                            /**< Processor 1 Count, offset: 0x48 */
  __I  uint32_t CP1CFG0;                           /**< Processor 1 Configuration 0, offset: 0x4C */
  __I  uint32_t CP1CFG1;                           /**< Processor 1 Configuration 1, offset: 0x50 */
  __I  uint32_t CP1CFG2;                           /**< Processor 1 Configuration 2, offset: 0x54 */
  __I  uint32_t CP1CFG3;                           /**< Processor 1 Configuration 3, offset: 0x58 */
  uint8_t RESERVED_2[4];
  __I  uint32_t CP2TYPE;                           /**< Processor 2 Type, offset: 0x60 */
  __I  uint32_t CP2NUM;                            /**< Processor 2 Number, offset: 0x64 */
  __I  uint32_t CP2REV;                            /**< Processor 2 Count, offset: 0x68 */
  __I  uint32_t CP2CFG0;                           /**< Processor 2 Configuration 0, offset: 0x6C */
  __I  uint32_t CP2CFG1;                           /**< Processor 2 Configuration 1, offset: 0x70 */
  __I  uint32_t CP2CFG2;                           /**< Processor 2 Configuration 2, offset: 0x74 */
  __I  uint32_t CP2CFG3;                           /**< Processor 2 Configuration 3, offset: 0x78 */
  uint8_t RESERVED_3[388];
  __IO uint32_t IRCP0ISR0;                         /**< Interrupt Router CP0 Interrupt Status, offset: 0x200 */
  __O  uint32_t IRCP0IGR0;                         /**< Interrupt Router CP0 Interrupt Generation, offset: 0x204 */
  __IO uint32_t IRCP0ISR1;                         /**< Interrupt Router CP0 Interrupt Status, offset: 0x208 */
  __O  uint32_t IRCP0IGR1;                         /**< Interrupt Router CP0 Interrupt Generation, offset: 0x20C */
  __IO uint32_t IRCP0ISR2;                         /**< Interrupt Router CP0 Interrupt Status, offset: 0x210 */
  __O  uint32_t IRCP0IGR2;                         /**< Interrupt Router CP0 Interrupt Generation, offset: 0x214 */
  __IO uint32_t IRCP0ISR3;                         /**< Interrupt Router CP0 Interrupt Status, offset: 0x218 */
  __O  uint32_t IRCP0IGR3;                         /**< Interrupt Router CP0 Interrupt Generation, offset: 0x21C */
  __IO uint32_t IRCP1ISR0;                         /**< Interrupt Router CP1 Interrupt Status, offset: 0x220 */
  __O  uint32_t IRCP1IGR0;                         /**< Interrupt Router CP1 Interrupt Generation, offset: 0x224 */
  __IO uint32_t IRCP1ISR1;                         /**< Interrupt Router CP1 Interrupt Status, offset: 0x228 */
  __O  uint32_t IRCP1IGR1;                         /**< Interrupt Router CP1 Interrupt Generation, offset: 0x22C */
  __IO uint32_t IRCP1ISR2;                         /**< Interrupt Router CP1 Interrupt Status, offset: 0x230 */
  __O  uint32_t IRCP1IGR2;                         /**< Interrupt Router CP1 Interrupt Generation, offset: 0x234 */
  __IO uint32_t IRCP1ISR3;                         /**< Interrupt Router CP1 Interrupt Status, offset: 0x238 */
  __O  uint32_t IRCP1IGR3;                         /**< Interrupt Router CP1 Interrupt Generation, offset: 0x23C */
  __IO uint32_t IRCP2ISR0;                         /**< Interrupt Router CP2 Interrupt Status, offset: 0x240 */
  __O  uint32_t IRCP2IGR0;                         /**< Interrupt Router CP2 Interrupt Generation, offset: 0x244 */
  __IO uint32_t IRCP2ISR1;                         /**< Interrupt Router CP2 Interrupt Status, offset: 0x248 */
  __O  uint32_t IRCP2IGR1;                         /**< Interrupt Router CP2 Interrupt Generation, offset: 0x24C */
  __IO uint32_t IRCP2ISR2;                         /**< Interrupt Router CP2 Interrupt Status, offset: 0x250 */
  __O  uint32_t IRCP2IGR2;                         /**< Interrupt Router CP2 Interrupt Generation, offset: 0x254 */
  __IO uint32_t IRCP2ISR3;                         /**< Interrupt Router CP2 Interrupt Status, offset: 0x258 */
  __O  uint32_t IRCP2IGR3;                         /**< Interrupt Router CP2 Interrupt Generation, offset: 0x25C */
  __IO uint32_t IRCP3ISR0;                         /**< Interrupt Router CP3 Interrupt Status, offset: 0x260 */
  __O  uint32_t IRCP3IGR0;                         /**< Interrupt Router CP3 Interrupt Generation, offset: 0x264 */
  __IO uint32_t IRCP3ISR1;                         /**< Interrupt Router CP3 Interrupt Status, offset: 0x268 */
  __O  uint32_t IRCP3IGR1;                         /**< Interrupt Router CP3 Interrupt Generation, offset: 0x26C */
  __IO uint32_t IRCP3ISR2;                         /**< Interrupt Router CP3 Interrupt Status, offset: 0x270 */
  __O  uint32_t IRCP3IGR2;                         /**< Interrupt Router CP3 Interrupt Generation, offset: 0x274 */
  __IO uint32_t IRCP3ISR3;                         /**< Interrupt Router CP3 Interrupt Status, offset: 0x278 */
  __O  uint32_t IRCP3IGR3;                         /**< Interrupt Router CP3 Interrupt Generation, offset: 0x27C */
  uint8_t RESERVED_4[384];
  __IO uint32_t IRCPCFG;                           /**< Interrupt Router Configuration, offset: 0x400 */
  uint8_t RESERVED_5[508];
  __IO uint32_t ENEDC0;                            /**< Read Data Check Enable, offset: 0x600 */
  __IO uint32_t ENEDC1;                            /**< Write Data Check Enable, offset: 0x604 */
  __IO uint32_t ENEDC2;                            /**< Address Check Enable, offset: 0x608 */
  uint8_t RESERVED_6[244];
  __IO uint32_t IAHBCFGREG0;                       /**< AHB Gasket Configuration 0, offset: 0x700 */
  __IO uint32_t IAHBCFGREG1;                       /**< AHB Gasket Configuration 1, offset: 0x704 */
  __IO uint32_t IAHBCFGREG2;                       /**< AHB Gasket Configuration 2, offset: 0x708 */
  uint8_t RESERVED_7[244];
  __IO uint32_t IRNMIC;                            /**< Interrupt Router Non-Maskable Interrupt Control Register, offset: 0x800 */
  uint8_t RESERVED_8[124];
  __IO uint16_t IRSPRC[MSCM_IRSPRC_COUNT];         /**< Interrupt Router Shared Peripheral Routing Control, array offset: 0x880, array step: 0x2 */
} MSCM_Type, *MSCM_MemMapPtr;

/** Number of instances of the MSCM module. */
#define MSCM_INSTANCE_COUNT                      (1u)

/* MSCM - Peripheral instance base addresses */
/** Peripheral MSCM base address */
#define IP_MSCM_BASE                             (0x40010000u)
/** Peripheral MSCM base pointer */
#define IP_MSCM                                  ((MSCM_Type *)IP_MSCM_BASE)
/** Array initializer of MSCM peripheral base addresses */
#define IP_MSCM_BASE_ADDRS                       { IP_MSCM_BASE }
/** Array initializer of MSCM peripheral base pointers */
#define IP_MSCM_BASE_PTRS                        { IP_MSCM }

/* ----------------------------------------------------------------------------
   -- MSCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MSCM_Register_Masks MSCM Register Masks
 * @{
 */

/*! @name CPXTYPE - Processor x Type */
/*! @{ */

#define MSCM_CPXTYPE_PERSONALITY_MASK            (0xFFFFFFFFU)
#define MSCM_CPXTYPE_PERSONALITY_SHIFT           (0U)
#define MSCM_CPXTYPE_PERSONALITY_WIDTH           (32U)
#define MSCM_CPXTYPE_PERSONALITY(x)              (((uint32_t)(((uint32_t)(x)) << MSCM_CPXTYPE_PERSONALITY_SHIFT)) & MSCM_CPXTYPE_PERSONALITY_MASK)
/*! @} */

/*! @name CPXNUM - Processor x Number */
/*! @{ */

#define MSCM_CPXNUM_CPN_MASK                     (0x3U)
#define MSCM_CPXNUM_CPN_SHIFT                    (0U)
#define MSCM_CPXNUM_CPN_WIDTH                    (2U)
#define MSCM_CPXNUM_CPN(x)                       (((uint32_t)(((uint32_t)(x)) << MSCM_CPXNUM_CPN_SHIFT)) & MSCM_CPXNUM_CPN_MASK)
/*! @} */

/*! @name CPXREV - Processor x Revision */
/*! @{ */

#define MSCM_CPXREV_RYPZ_MASK                    (0xFFU)
#define MSCM_CPXREV_RYPZ_SHIFT                   (0U)
#define MSCM_CPXREV_RYPZ_WIDTH                   (8U)
#define MSCM_CPXREV_RYPZ(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CPXREV_RYPZ_SHIFT)) & MSCM_CPXREV_RYPZ_MASK)
/*! @} */

/*! @name CPXCFG0 - Processor x Configuration 0 */
/*! @{ */

#define MSCM_CPXCFG0_DCWY_MASK                   (0xFFU)
#define MSCM_CPXCFG0_DCWY_SHIFT                  (0U)
#define MSCM_CPXCFG0_DCWY_WIDTH                  (8U)
#define MSCM_CPXCFG0_DCWY(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG0_DCWY_SHIFT)) & MSCM_CPXCFG0_DCWY_MASK)

#define MSCM_CPXCFG0_DCSZ_MASK                   (0xFF00U)
#define MSCM_CPXCFG0_DCSZ_SHIFT                  (8U)
#define MSCM_CPXCFG0_DCSZ_WIDTH                  (8U)
#define MSCM_CPXCFG0_DCSZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG0_DCSZ_SHIFT)) & MSCM_CPXCFG0_DCSZ_MASK)

#define MSCM_CPXCFG0_ICWY_MASK                   (0xFF0000U)
#define MSCM_CPXCFG0_ICWY_SHIFT                  (16U)
#define MSCM_CPXCFG0_ICWY_WIDTH                  (8U)
#define MSCM_CPXCFG0_ICWY(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG0_ICWY_SHIFT)) & MSCM_CPXCFG0_ICWY_MASK)

#define MSCM_CPXCFG0_ICSZ_MASK                   (0xFF000000U)
#define MSCM_CPXCFG0_ICSZ_SHIFT                  (24U)
#define MSCM_CPXCFG0_ICSZ_WIDTH                  (8U)
#define MSCM_CPXCFG0_ICSZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG0_ICSZ_SHIFT)) & MSCM_CPXCFG0_ICSZ_MASK)
/*! @} */

/*! @name CPXCFG1 - Processor x Configuration 1 */
/*! @{ */

#define MSCM_CPXCFG1_L2WY_MASK                   (0xFF0000U)
#define MSCM_CPXCFG1_L2WY_SHIFT                  (16U)
#define MSCM_CPXCFG1_L2WY_WIDTH                  (8U)
#define MSCM_CPXCFG1_L2WY(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG1_L2WY_SHIFT)) & MSCM_CPXCFG1_L2WY_MASK)

#define MSCM_CPXCFG1_L2SZ_MASK                   (0xFF000000U)
#define MSCM_CPXCFG1_L2SZ_SHIFT                  (24U)
#define MSCM_CPXCFG1_L2SZ_WIDTH                  (8U)
#define MSCM_CPXCFG1_L2SZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG1_L2SZ_SHIFT)) & MSCM_CPXCFG1_L2SZ_MASK)
/*! @} */

/*! @name CPXCFG2 - Processor x Configuration 2 */
/*! @{ */

#define MSCM_CPXCFG2_ITCMSZ_MASK                 (0xFF0000U)
#define MSCM_CPXCFG2_ITCMSZ_SHIFT                (16U)
#define MSCM_CPXCFG2_ITCMSZ_WIDTH                (8U)
#define MSCM_CPXCFG2_ITCMSZ(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG2_ITCMSZ_SHIFT)) & MSCM_CPXCFG2_ITCMSZ_MASK)

#define MSCM_CPXCFG2_DTCMSZ_MASK                 (0xFF000000U)
#define MSCM_CPXCFG2_DTCMSZ_SHIFT                (24U)
#define MSCM_CPXCFG2_DTCMSZ_WIDTH                (8U)
#define MSCM_CPXCFG2_DTCMSZ(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG2_DTCMSZ_SHIFT)) & MSCM_CPXCFG2_DTCMSZ_MASK)
/*! @} */

/*! @name CPXCFG3 - Processor x Configuration 3 */
/*! @{ */

#define MSCM_CPXCFG3_HW_FPU_MASK                 (0x1U)
#define MSCM_CPXCFG3_HW_FPU_SHIFT                (0U)
#define MSCM_CPXCFG3_HW_FPU_WIDTH                (1U)
#define MSCM_CPXCFG3_HW_FPU(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG3_HW_FPU_SHIFT)) & MSCM_CPXCFG3_HW_FPU_MASK)

#define MSCM_CPXCFG3_SIMD_MASK                   (0x2U)
#define MSCM_CPXCFG3_SIMD_SHIFT                  (1U)
#define MSCM_CPXCFG3_SIMD_WIDTH                  (1U)
#define MSCM_CPXCFG3_SIMD(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG3_SIMD_SHIFT)) & MSCM_CPXCFG3_SIMD_MASK)

#define MSCM_CPXCFG3_MMU_MASK                    (0x4U)
#define MSCM_CPXCFG3_MMU_SHIFT                   (2U)
#define MSCM_CPXCFG3_MMU_WIDTH                   (1U)
#define MSCM_CPXCFG3_MMU(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG3_MMU_SHIFT)) & MSCM_CPXCFG3_MMU_MASK)

#define MSCM_CPXCFG3_CMP_MASK                    (0x8U)
#define MSCM_CPXCFG3_CMP_SHIFT                   (3U)
#define MSCM_CPXCFG3_CMP_WIDTH                   (1U)
#define MSCM_CPXCFG3_CMP(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG3_CMP_SHIFT)) & MSCM_CPXCFG3_CMP_MASK)

#define MSCM_CPXCFG3_CPY_MASK                    (0x10U)
#define MSCM_CPXCFG3_CPY_SHIFT                   (4U)
#define MSCM_CPXCFG3_CPY_WIDTH                   (1U)
#define MSCM_CPXCFG3_CPY(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG3_CPY_SHIFT)) & MSCM_CPXCFG3_CPY_MASK)
/*! @} */

/*! @name CP0TYPE - Processor 0 Type */
/*! @{ */

#define MSCM_CP0TYPE_PERSONALITY_MASK            (0xFFFFFFFFU)
#define MSCM_CP0TYPE_PERSONALITY_SHIFT           (0U)
#define MSCM_CP0TYPE_PERSONALITY_WIDTH           (32U)
#define MSCM_CP0TYPE_PERSONALITY(x)              (((uint32_t)(((uint32_t)(x)) << MSCM_CP0TYPE_PERSONALITY_SHIFT)) & MSCM_CP0TYPE_PERSONALITY_MASK)
/*! @} */

/*! @name CP0NUM - Processor 0 Number */
/*! @{ */

#define MSCM_CP0NUM_CPN_MASK                     (0x3U)
#define MSCM_CP0NUM_CPN_SHIFT                    (0U)
#define MSCM_CP0NUM_CPN_WIDTH                    (2U)
#define MSCM_CP0NUM_CPN(x)                       (((uint32_t)(((uint32_t)(x)) << MSCM_CP0NUM_CPN_SHIFT)) & MSCM_CP0NUM_CPN_MASK)
/*! @} */

/*! @name CP0REV - Processor 0 Count */
/*! @{ */

#define MSCM_CP0REV_RYPZ_MASK                    (0xFFU)
#define MSCM_CP0REV_RYPZ_SHIFT                   (0U)
#define MSCM_CP0REV_RYPZ_WIDTH                   (8U)
#define MSCM_CP0REV_RYPZ(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CP0REV_RYPZ_SHIFT)) & MSCM_CP0REV_RYPZ_MASK)
/*! @} */

/*! @name CP0CFG0 - Processor 0 Configuration 0 */
/*! @{ */

#define MSCM_CP0CFG0_DCWY_MASK                   (0xFFU)
#define MSCM_CP0CFG0_DCWY_SHIFT                  (0U)
#define MSCM_CP0CFG0_DCWY_WIDTH                  (8U)
#define MSCM_CP0CFG0_DCWY(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP0CFG0_DCWY_SHIFT)) & MSCM_CP0CFG0_DCWY_MASK)

#define MSCM_CP0CFG0_DCSZ_MASK                   (0xFF00U)
#define MSCM_CP0CFG0_DCSZ_SHIFT                  (8U)
#define MSCM_CP0CFG0_DCSZ_WIDTH                  (8U)
#define MSCM_CP0CFG0_DCSZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP0CFG0_DCSZ_SHIFT)) & MSCM_CP0CFG0_DCSZ_MASK)

#define MSCM_CP0CFG0_ICWY_MASK                   (0xFF0000U)
#define MSCM_CP0CFG0_ICWY_SHIFT                  (16U)
#define MSCM_CP0CFG0_ICWY_WIDTH                  (8U)
#define MSCM_CP0CFG0_ICWY(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP0CFG0_ICWY_SHIFT)) & MSCM_CP0CFG0_ICWY_MASK)

#define MSCM_CP0CFG0_ICSZ_MASK                   (0xFF000000U)
#define MSCM_CP0CFG0_ICSZ_SHIFT                  (24U)
#define MSCM_CP0CFG0_ICSZ_WIDTH                  (8U)
#define MSCM_CP0CFG0_ICSZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP0CFG0_ICSZ_SHIFT)) & MSCM_CP0CFG0_ICSZ_MASK)
/*! @} */

/*! @name CP0CFG1 - Processor 0 Configuration 1 */
/*! @{ */

#define MSCM_CP0CFG1_L2WY_MASK                   (0xFF0000U)
#define MSCM_CP0CFG1_L2WY_SHIFT                  (16U)
#define MSCM_CP0CFG1_L2WY_WIDTH                  (8U)
#define MSCM_CP0CFG1_L2WY(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP0CFG1_L2WY_SHIFT)) & MSCM_CP0CFG1_L2WY_MASK)

#define MSCM_CP0CFG1_L2SZ_MASK                   (0xFF000000U)
#define MSCM_CP0CFG1_L2SZ_SHIFT                  (24U)
#define MSCM_CP0CFG1_L2SZ_WIDTH                  (8U)
#define MSCM_CP0CFG1_L2SZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP0CFG1_L2SZ_SHIFT)) & MSCM_CP0CFG1_L2SZ_MASK)
/*! @} */

/*! @name CP0CFG2 - Processor 0 Configuration 2 */
/*! @{ */

#define MSCM_CP0CFG2_ITCMSZ_MASK                 (0xFF0000U)
#define MSCM_CP0CFG2_ITCMSZ_SHIFT                (16U)
#define MSCM_CP0CFG2_ITCMSZ_WIDTH                (8U)
#define MSCM_CP0CFG2_ITCMSZ(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_CP0CFG2_ITCMSZ_SHIFT)) & MSCM_CP0CFG2_ITCMSZ_MASK)

#define MSCM_CP0CFG2_DTCMSZ_MASK                 (0xFF000000U)
#define MSCM_CP0CFG2_DTCMSZ_SHIFT                (24U)
#define MSCM_CP0CFG2_DTCMSZ_WIDTH                (8U)
#define MSCM_CP0CFG2_DTCMSZ(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_CP0CFG2_DTCMSZ_SHIFT)) & MSCM_CP0CFG2_DTCMSZ_MASK)
/*! @} */

/*! @name CP0CFG3 - Processor 0 Configuration 3 */
/*! @{ */

#define MSCM_CP0CFG3_HW_FPU_MASK                 (0x1U)
#define MSCM_CP0CFG3_HW_FPU_SHIFT                (0U)
#define MSCM_CP0CFG3_HW_FPU_WIDTH                (1U)
#define MSCM_CP0CFG3_HW_FPU(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_CP0CFG3_HW_FPU_SHIFT)) & MSCM_CP0CFG3_HW_FPU_MASK)

#define MSCM_CP0CFG3_SIMD_MASK                   (0x2U)
#define MSCM_CP0CFG3_SIMD_SHIFT                  (1U)
#define MSCM_CP0CFG3_SIMD_WIDTH                  (1U)
#define MSCM_CP0CFG3_SIMD(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP0CFG3_SIMD_SHIFT)) & MSCM_CP0CFG3_SIMD_MASK)

#define MSCM_CP0CFG3_MMU_MASK                    (0x4U)
#define MSCM_CP0CFG3_MMU_SHIFT                   (2U)
#define MSCM_CP0CFG3_MMU_WIDTH                   (1U)
#define MSCM_CP0CFG3_MMU(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CP0CFG3_MMU_SHIFT)) & MSCM_CP0CFG3_MMU_MASK)

#define MSCM_CP0CFG3_CMP_MASK                    (0x8U)
#define MSCM_CP0CFG3_CMP_SHIFT                   (3U)
#define MSCM_CP0CFG3_CMP_WIDTH                   (1U)
#define MSCM_CP0CFG3_CMP(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CP0CFG3_CMP_SHIFT)) & MSCM_CP0CFG3_CMP_MASK)

#define MSCM_CP0CFG3_CPY_MASK                    (0x10U)
#define MSCM_CP0CFG3_CPY_SHIFT                   (4U)
#define MSCM_CP0CFG3_CPY_WIDTH                   (1U)
#define MSCM_CP0CFG3_CPY(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CP0CFG3_CPY_SHIFT)) & MSCM_CP0CFG3_CPY_MASK)
/*! @} */

/*! @name CP1TYPE - Processor 1 Type */
/*! @{ */

#define MSCM_CP1TYPE_PERSONALITY_MASK            (0xFFFFFFFFU)
#define MSCM_CP1TYPE_PERSONALITY_SHIFT           (0U)
#define MSCM_CP1TYPE_PERSONALITY_WIDTH           (32U)
#define MSCM_CP1TYPE_PERSONALITY(x)              (((uint32_t)(((uint32_t)(x)) << MSCM_CP1TYPE_PERSONALITY_SHIFT)) & MSCM_CP1TYPE_PERSONALITY_MASK)
/*! @} */

/*! @name CP1NUM - Processor 1 Number */
/*! @{ */

#define MSCM_CP1NUM_CPN_MASK                     (0x3U)
#define MSCM_CP1NUM_CPN_SHIFT                    (0U)
#define MSCM_CP1NUM_CPN_WIDTH                    (2U)
#define MSCM_CP1NUM_CPN(x)                       (((uint32_t)(((uint32_t)(x)) << MSCM_CP1NUM_CPN_SHIFT)) & MSCM_CP1NUM_CPN_MASK)
/*! @} */

/*! @name CP1REV - Processor 1 Count */
/*! @{ */

#define MSCM_CP1REV_RYPZ_MASK                    (0xFFU)
#define MSCM_CP1REV_RYPZ_SHIFT                   (0U)
#define MSCM_CP1REV_RYPZ_WIDTH                   (8U)
#define MSCM_CP1REV_RYPZ(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CP1REV_RYPZ_SHIFT)) & MSCM_CP1REV_RYPZ_MASK)
/*! @} */

/*! @name CP1CFG0 - Processor 1 Configuration 0 */
/*! @{ */

#define MSCM_CP1CFG0_DCWY_MASK                   (0xFFU)
#define MSCM_CP1CFG0_DCWY_SHIFT                  (0U)
#define MSCM_CP1CFG0_DCWY_WIDTH                  (8U)
#define MSCM_CP1CFG0_DCWY(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP1CFG0_DCWY_SHIFT)) & MSCM_CP1CFG0_DCWY_MASK)

#define MSCM_CP1CFG0_DCSZ_MASK                   (0xFF00U)
#define MSCM_CP1CFG0_DCSZ_SHIFT                  (8U)
#define MSCM_CP1CFG0_DCSZ_WIDTH                  (8U)
#define MSCM_CP1CFG0_DCSZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP1CFG0_DCSZ_SHIFT)) & MSCM_CP1CFG0_DCSZ_MASK)

#define MSCM_CP1CFG0_ICWY_MASK                   (0xFF0000U)
#define MSCM_CP1CFG0_ICWY_SHIFT                  (16U)
#define MSCM_CP1CFG0_ICWY_WIDTH                  (8U)
#define MSCM_CP1CFG0_ICWY(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP1CFG0_ICWY_SHIFT)) & MSCM_CP1CFG0_ICWY_MASK)

#define MSCM_CP1CFG0_ICSZ_MASK                   (0xFF000000U)
#define MSCM_CP1CFG0_ICSZ_SHIFT                  (24U)
#define MSCM_CP1CFG0_ICSZ_WIDTH                  (8U)
#define MSCM_CP1CFG0_ICSZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP1CFG0_ICSZ_SHIFT)) & MSCM_CP1CFG0_ICSZ_MASK)
/*! @} */

/*! @name CP1CFG1 - Processor 1 Configuration 1 */
/*! @{ */

#define MSCM_CP1CFG1_L2WY_MASK                   (0xFF0000U)
#define MSCM_CP1CFG1_L2WY_SHIFT                  (16U)
#define MSCM_CP1CFG1_L2WY_WIDTH                  (8U)
#define MSCM_CP1CFG1_L2WY(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP1CFG1_L2WY_SHIFT)) & MSCM_CP1CFG1_L2WY_MASK)

#define MSCM_CP1CFG1_L2SZ_MASK                   (0xFF000000U)
#define MSCM_CP1CFG1_L2SZ_SHIFT                  (24U)
#define MSCM_CP1CFG1_L2SZ_WIDTH                  (8U)
#define MSCM_CP1CFG1_L2SZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP1CFG1_L2SZ_SHIFT)) & MSCM_CP1CFG1_L2SZ_MASK)
/*! @} */

/*! @name CP1CFG2 - Processor 1 Configuration 2 */
/*! @{ */

#define MSCM_CP1CFG2_ITCMSZ_MASK                 (0xFF0000U)
#define MSCM_CP1CFG2_ITCMSZ_SHIFT                (16U)
#define MSCM_CP1CFG2_ITCMSZ_WIDTH                (8U)
#define MSCM_CP1CFG2_ITCMSZ(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_CP1CFG2_ITCMSZ_SHIFT)) & MSCM_CP1CFG2_ITCMSZ_MASK)

#define MSCM_CP1CFG2_DTCMSZ_MASK                 (0xFF000000U)
#define MSCM_CP1CFG2_DTCMSZ_SHIFT                (24U)
#define MSCM_CP1CFG2_DTCMSZ_WIDTH                (8U)
#define MSCM_CP1CFG2_DTCMSZ(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_CP1CFG2_DTCMSZ_SHIFT)) & MSCM_CP1CFG2_DTCMSZ_MASK)
/*! @} */

/*! @name CP1CFG3 - Processor 1 Configuration 3 */
/*! @{ */

#define MSCM_CP1CFG3_HW_FPU_MASK                 (0x1U)
#define MSCM_CP1CFG3_HW_FPU_SHIFT                (0U)
#define MSCM_CP1CFG3_HW_FPU_WIDTH                (1U)
#define MSCM_CP1CFG3_HW_FPU(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_CP1CFG3_HW_FPU_SHIFT)) & MSCM_CP1CFG3_HW_FPU_MASK)

#define MSCM_CP1CFG3_SIMD_MASK                   (0x2U)
#define MSCM_CP1CFG3_SIMD_SHIFT                  (1U)
#define MSCM_CP1CFG3_SIMD_WIDTH                  (1U)
#define MSCM_CP1CFG3_SIMD(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP1CFG3_SIMD_SHIFT)) & MSCM_CP1CFG3_SIMD_MASK)

#define MSCM_CP1CFG3_MMU_MASK                    (0x4U)
#define MSCM_CP1CFG3_MMU_SHIFT                   (2U)
#define MSCM_CP1CFG3_MMU_WIDTH                   (1U)
#define MSCM_CP1CFG3_MMU(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CP1CFG3_MMU_SHIFT)) & MSCM_CP1CFG3_MMU_MASK)

#define MSCM_CP1CFG3_CMP_MASK                    (0x8U)
#define MSCM_CP1CFG3_CMP_SHIFT                   (3U)
#define MSCM_CP1CFG3_CMP_WIDTH                   (1U)
#define MSCM_CP1CFG3_CMP(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CP1CFG3_CMP_SHIFT)) & MSCM_CP1CFG3_CMP_MASK)

#define MSCM_CP1CFG3_CPY_MASK                    (0x10U)
#define MSCM_CP1CFG3_CPY_SHIFT                   (4U)
#define MSCM_CP1CFG3_CPY_WIDTH                   (1U)
#define MSCM_CP1CFG3_CPY(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CP1CFG3_CPY_SHIFT)) & MSCM_CP1CFG3_CPY_MASK)
/*! @} */

/*! @name CP2TYPE - Processor 2 Type */
/*! @{ */

#define MSCM_CP2TYPE_PERSONALITY_MASK            (0xFFFFFFFFU)
#define MSCM_CP2TYPE_PERSONALITY_SHIFT           (0U)
#define MSCM_CP2TYPE_PERSONALITY_WIDTH           (32U)
#define MSCM_CP2TYPE_PERSONALITY(x)              (((uint32_t)(((uint32_t)(x)) << MSCM_CP2TYPE_PERSONALITY_SHIFT)) & MSCM_CP2TYPE_PERSONALITY_MASK)
/*! @} */

/*! @name CP2NUM - Processor 2 Number */
/*! @{ */

#define MSCM_CP2NUM_CPN_MASK                     (0x3U)
#define MSCM_CP2NUM_CPN_SHIFT                    (0U)
#define MSCM_CP2NUM_CPN_WIDTH                    (2U)
#define MSCM_CP2NUM_CPN(x)                       (((uint32_t)(((uint32_t)(x)) << MSCM_CP2NUM_CPN_SHIFT)) & MSCM_CP2NUM_CPN_MASK)
/*! @} */

/*! @name CP2REV - Processor 2 Count */
/*! @{ */

#define MSCM_CP2REV_RYPZ_MASK                    (0xFFU)
#define MSCM_CP2REV_RYPZ_SHIFT                   (0U)
#define MSCM_CP2REV_RYPZ_WIDTH                   (8U)
#define MSCM_CP2REV_RYPZ(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CP2REV_RYPZ_SHIFT)) & MSCM_CP2REV_RYPZ_MASK)
/*! @} */

/*! @name CP2CFG0 - Processor 2 Configuration 0 */
/*! @{ */

#define MSCM_CP2CFG0_DCWY_MASK                   (0xFFU)
#define MSCM_CP2CFG0_DCWY_SHIFT                  (0U)
#define MSCM_CP2CFG0_DCWY_WIDTH                  (8U)
#define MSCM_CP2CFG0_DCWY(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP2CFG0_DCWY_SHIFT)) & MSCM_CP2CFG0_DCWY_MASK)

#define MSCM_CP2CFG0_DCSZ_MASK                   (0xFF00U)
#define MSCM_CP2CFG0_DCSZ_SHIFT                  (8U)
#define MSCM_CP2CFG0_DCSZ_WIDTH                  (8U)
#define MSCM_CP2CFG0_DCSZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP2CFG0_DCSZ_SHIFT)) & MSCM_CP2CFG0_DCSZ_MASK)

#define MSCM_CP2CFG0_ICWY_MASK                   (0xFF0000U)
#define MSCM_CP2CFG0_ICWY_SHIFT                  (16U)
#define MSCM_CP2CFG0_ICWY_WIDTH                  (8U)
#define MSCM_CP2CFG0_ICWY(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP2CFG0_ICWY_SHIFT)) & MSCM_CP2CFG0_ICWY_MASK)

#define MSCM_CP2CFG0_ICSZ_MASK                   (0xFF000000U)
#define MSCM_CP2CFG0_ICSZ_SHIFT                  (24U)
#define MSCM_CP2CFG0_ICSZ_WIDTH                  (8U)
#define MSCM_CP2CFG0_ICSZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP2CFG0_ICSZ_SHIFT)) & MSCM_CP2CFG0_ICSZ_MASK)
/*! @} */

/*! @name CP2CFG1 - Processor 2 Configuration 1 */
/*! @{ */

#define MSCM_CP2CFG1_L2WY_MASK                   (0xFF0000U)
#define MSCM_CP2CFG1_L2WY_SHIFT                  (16U)
#define MSCM_CP2CFG1_L2WY_WIDTH                  (8U)
#define MSCM_CP2CFG1_L2WY(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP2CFG1_L2WY_SHIFT)) & MSCM_CP2CFG1_L2WY_MASK)

#define MSCM_CP2CFG1_L2SZ_MASK                   (0xFF000000U)
#define MSCM_CP2CFG1_L2SZ_SHIFT                  (24U)
#define MSCM_CP2CFG1_L2SZ_WIDTH                  (8U)
#define MSCM_CP2CFG1_L2SZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP2CFG1_L2SZ_SHIFT)) & MSCM_CP2CFG1_L2SZ_MASK)
/*! @} */

/*! @name CP2CFG2 - Processor 2 Configuration 2 */
/*! @{ */

#define MSCM_CP2CFG2_ITCMSZ_MASK                 (0xFF0000U)
#define MSCM_CP2CFG2_ITCMSZ_SHIFT                (16U)
#define MSCM_CP2CFG2_ITCMSZ_WIDTH                (8U)
#define MSCM_CP2CFG2_ITCMSZ(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_CP2CFG2_ITCMSZ_SHIFT)) & MSCM_CP2CFG2_ITCMSZ_MASK)

#define MSCM_CP2CFG2_DTCMSZ_MASK                 (0xFF000000U)
#define MSCM_CP2CFG2_DTCMSZ_SHIFT                (24U)
#define MSCM_CP2CFG2_DTCMSZ_WIDTH                (8U)
#define MSCM_CP2CFG2_DTCMSZ(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_CP2CFG2_DTCMSZ_SHIFT)) & MSCM_CP2CFG2_DTCMSZ_MASK)
/*! @} */

/*! @name CP2CFG3 - Processor 2 Configuration 3 */
/*! @{ */

#define MSCM_CP2CFG3_HW_FPU_MASK                 (0x1U)
#define MSCM_CP2CFG3_HW_FPU_SHIFT                (0U)
#define MSCM_CP2CFG3_HW_FPU_WIDTH                (1U)
#define MSCM_CP2CFG3_HW_FPU(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_CP2CFG3_HW_FPU_SHIFT)) & MSCM_CP2CFG3_HW_FPU_MASK)

#define MSCM_CP2CFG3_SIMD_MASK                   (0x2U)
#define MSCM_CP2CFG3_SIMD_SHIFT                  (1U)
#define MSCM_CP2CFG3_SIMD_WIDTH                  (1U)
#define MSCM_CP2CFG3_SIMD(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP2CFG3_SIMD_SHIFT)) & MSCM_CP2CFG3_SIMD_MASK)

#define MSCM_CP2CFG3_MMU_MASK                    (0x4U)
#define MSCM_CP2CFG3_MMU_SHIFT                   (2U)
#define MSCM_CP2CFG3_MMU_WIDTH                   (1U)
#define MSCM_CP2CFG3_MMU(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CP2CFG3_MMU_SHIFT)) & MSCM_CP2CFG3_MMU_MASK)

#define MSCM_CP2CFG3_CMP_MASK                    (0x8U)
#define MSCM_CP2CFG3_CMP_SHIFT                   (3U)
#define MSCM_CP2CFG3_CMP_WIDTH                   (1U)
#define MSCM_CP2CFG3_CMP(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CP2CFG3_CMP_SHIFT)) & MSCM_CP2CFG3_CMP_MASK)

#define MSCM_CP2CFG3_CPY_MASK                    (0x10U)
#define MSCM_CP2CFG3_CPY_SHIFT                   (4U)
#define MSCM_CP2CFG3_CPY_WIDTH                   (1U)
#define MSCM_CP2CFG3_CPY(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CP2CFG3_CPY_SHIFT)) & MSCM_CP2CFG3_CPY_MASK)
/*! @} */

/*! @name IRCP0ISR0 - Interrupt Router CP0 Interrupt Status */
/*! @{ */

#define MSCM_IRCP0ISR0_CP0_INT_MASK              (0x1U)
#define MSCM_IRCP0ISR0_CP0_INT_SHIFT             (0U)
#define MSCM_IRCP0ISR0_CP0_INT_WIDTH             (1U)
#define MSCM_IRCP0ISR0_CP0_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP0ISR0_CP0_INT_SHIFT)) & MSCM_IRCP0ISR0_CP0_INT_MASK)

#define MSCM_IRCP0ISR0_CP1_INT_MASK              (0x2U)
#define MSCM_IRCP0ISR0_CP1_INT_SHIFT             (1U)
#define MSCM_IRCP0ISR0_CP1_INT_WIDTH             (1U)
#define MSCM_IRCP0ISR0_CP1_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP0ISR0_CP1_INT_SHIFT)) & MSCM_IRCP0ISR0_CP1_INT_MASK)

#define MSCM_IRCP0ISR0_CP2_INT_MASK              (0x4U)
#define MSCM_IRCP0ISR0_CP2_INT_SHIFT             (2U)
#define MSCM_IRCP0ISR0_CP2_INT_WIDTH             (1U)
#define MSCM_IRCP0ISR0_CP2_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP0ISR0_CP2_INT_SHIFT)) & MSCM_IRCP0ISR0_CP2_INT_MASK)

#define MSCM_IRCP0ISR0_CP3_INT_MASK              (0x8U)
#define MSCM_IRCP0ISR0_CP3_INT_SHIFT             (3U)
#define MSCM_IRCP0ISR0_CP3_INT_WIDTH             (1U)
#define MSCM_IRCP0ISR0_CP3_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP0ISR0_CP3_INT_SHIFT)) & MSCM_IRCP0ISR0_CP3_INT_MASK)
/*! @} */

/*! @name IRCP0IGR0 - Interrupt Router CP0 Interrupt Generation */
/*! @{ */

#define MSCM_IRCP0IGR0_INT_EN_MASK               (0x1U)
#define MSCM_IRCP0IGR0_INT_EN_SHIFT              (0U)
#define MSCM_IRCP0IGR0_INT_EN_WIDTH              (1U)
#define MSCM_IRCP0IGR0_INT_EN(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP0IGR0_INT_EN_SHIFT)) & MSCM_IRCP0IGR0_INT_EN_MASK)
/*! @} */

/*! @name IRCP0ISR1 - Interrupt Router CP0 Interrupt Status */
/*! @{ */

#define MSCM_IRCP0ISR1_CP0_INT_MASK              (0x1U)
#define MSCM_IRCP0ISR1_CP0_INT_SHIFT             (0U)
#define MSCM_IRCP0ISR1_CP0_INT_WIDTH             (1U)
#define MSCM_IRCP0ISR1_CP0_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP0ISR1_CP0_INT_SHIFT)) & MSCM_IRCP0ISR1_CP0_INT_MASK)

#define MSCM_IRCP0ISR1_CP1_INT_MASK              (0x2U)
#define MSCM_IRCP0ISR1_CP1_INT_SHIFT             (1U)
#define MSCM_IRCP0ISR1_CP1_INT_WIDTH             (1U)
#define MSCM_IRCP0ISR1_CP1_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP0ISR1_CP1_INT_SHIFT)) & MSCM_IRCP0ISR1_CP1_INT_MASK)

#define MSCM_IRCP0ISR1_CP2_INT_MASK              (0x4U)
#define MSCM_IRCP0ISR1_CP2_INT_SHIFT             (2U)
#define MSCM_IRCP0ISR1_CP2_INT_WIDTH             (1U)
#define MSCM_IRCP0ISR1_CP2_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP0ISR1_CP2_INT_SHIFT)) & MSCM_IRCP0ISR1_CP2_INT_MASK)

#define MSCM_IRCP0ISR1_CP3_INT_MASK              (0x8U)
#define MSCM_IRCP0ISR1_CP3_INT_SHIFT             (3U)
#define MSCM_IRCP0ISR1_CP3_INT_WIDTH             (1U)
#define MSCM_IRCP0ISR1_CP3_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP0ISR1_CP3_INT_SHIFT)) & MSCM_IRCP0ISR1_CP3_INT_MASK)
/*! @} */

/*! @name IRCP0IGR1 - Interrupt Router CP0 Interrupt Generation */
/*! @{ */

#define MSCM_IRCP0IGR1_INT_EN_MASK               (0x1U)
#define MSCM_IRCP0IGR1_INT_EN_SHIFT              (0U)
#define MSCM_IRCP0IGR1_INT_EN_WIDTH              (1U)
#define MSCM_IRCP0IGR1_INT_EN(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP0IGR1_INT_EN_SHIFT)) & MSCM_IRCP0IGR1_INT_EN_MASK)
/*! @} */

/*! @name IRCP0ISR2 - Interrupt Router CP0 Interrupt Status */
/*! @{ */

#define MSCM_IRCP0ISR2_CP0_INT_MASK              (0x1U)
#define MSCM_IRCP0ISR2_CP0_INT_SHIFT             (0U)
#define MSCM_IRCP0ISR2_CP0_INT_WIDTH             (1U)
#define MSCM_IRCP0ISR2_CP0_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP0ISR2_CP0_INT_SHIFT)) & MSCM_IRCP0ISR2_CP0_INT_MASK)

#define MSCM_IRCP0ISR2_CP1_INT_MASK              (0x2U)
#define MSCM_IRCP0ISR2_CP1_INT_SHIFT             (1U)
#define MSCM_IRCP0ISR2_CP1_INT_WIDTH             (1U)
#define MSCM_IRCP0ISR2_CP1_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP0ISR2_CP1_INT_SHIFT)) & MSCM_IRCP0ISR2_CP1_INT_MASK)

#define MSCM_IRCP0ISR2_CP2_INT_MASK              (0x4U)
#define MSCM_IRCP0ISR2_CP2_INT_SHIFT             (2U)
#define MSCM_IRCP0ISR2_CP2_INT_WIDTH             (1U)
#define MSCM_IRCP0ISR2_CP2_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP0ISR2_CP2_INT_SHIFT)) & MSCM_IRCP0ISR2_CP2_INT_MASK)

#define MSCM_IRCP0ISR2_CP3_INT_MASK              (0x8U)
#define MSCM_IRCP0ISR2_CP3_INT_SHIFT             (3U)
#define MSCM_IRCP0ISR2_CP3_INT_WIDTH             (1U)
#define MSCM_IRCP0ISR2_CP3_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP0ISR2_CP3_INT_SHIFT)) & MSCM_IRCP0ISR2_CP3_INT_MASK)
/*! @} */

/*! @name IRCP0IGR2 - Interrupt Router CP0 Interrupt Generation */
/*! @{ */

#define MSCM_IRCP0IGR2_INT_EN_MASK               (0x1U)
#define MSCM_IRCP0IGR2_INT_EN_SHIFT              (0U)
#define MSCM_IRCP0IGR2_INT_EN_WIDTH              (1U)
#define MSCM_IRCP0IGR2_INT_EN(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP0IGR2_INT_EN_SHIFT)) & MSCM_IRCP0IGR2_INT_EN_MASK)
/*! @} */

/*! @name IRCP0ISR3 - Interrupt Router CP0 Interrupt Status */
/*! @{ */

#define MSCM_IRCP0ISR3_CP0_INT_MASK              (0x1U)
#define MSCM_IRCP0ISR3_CP0_INT_SHIFT             (0U)
#define MSCM_IRCP0ISR3_CP0_INT_WIDTH             (1U)
#define MSCM_IRCP0ISR3_CP0_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP0ISR3_CP0_INT_SHIFT)) & MSCM_IRCP0ISR3_CP0_INT_MASK)

#define MSCM_IRCP0ISR3_CP1_INT_MASK              (0x2U)
#define MSCM_IRCP0ISR3_CP1_INT_SHIFT             (1U)
#define MSCM_IRCP0ISR3_CP1_INT_WIDTH             (1U)
#define MSCM_IRCP0ISR3_CP1_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP0ISR3_CP1_INT_SHIFT)) & MSCM_IRCP0ISR3_CP1_INT_MASK)

#define MSCM_IRCP0ISR3_CP2_INT_MASK              (0x4U)
#define MSCM_IRCP0ISR3_CP2_INT_SHIFT             (2U)
#define MSCM_IRCP0ISR3_CP2_INT_WIDTH             (1U)
#define MSCM_IRCP0ISR3_CP2_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP0ISR3_CP2_INT_SHIFT)) & MSCM_IRCP0ISR3_CP2_INT_MASK)

#define MSCM_IRCP0ISR3_CP3_INT_MASK              (0x8U)
#define MSCM_IRCP0ISR3_CP3_INT_SHIFT             (3U)
#define MSCM_IRCP0ISR3_CP3_INT_WIDTH             (1U)
#define MSCM_IRCP0ISR3_CP3_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP0ISR3_CP3_INT_SHIFT)) & MSCM_IRCP0ISR3_CP3_INT_MASK)
/*! @} */

/*! @name IRCP0IGR3 - Interrupt Router CP0 Interrupt Generation */
/*! @{ */

#define MSCM_IRCP0IGR3_INT_EN_MASK               (0x1U)
#define MSCM_IRCP0IGR3_INT_EN_SHIFT              (0U)
#define MSCM_IRCP0IGR3_INT_EN_WIDTH              (1U)
#define MSCM_IRCP0IGR3_INT_EN(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP0IGR3_INT_EN_SHIFT)) & MSCM_IRCP0IGR3_INT_EN_MASK)
/*! @} */

/*! @name IRCP1ISR0 - Interrupt Router CP1 Interrupt Status */
/*! @{ */

#define MSCM_IRCP1ISR0_CP0_INT_MASK              (0x1U)
#define MSCM_IRCP1ISR0_CP0_INT_SHIFT             (0U)
#define MSCM_IRCP1ISR0_CP0_INT_WIDTH             (1U)
#define MSCM_IRCP1ISR0_CP0_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP1ISR0_CP0_INT_SHIFT)) & MSCM_IRCP1ISR0_CP0_INT_MASK)

#define MSCM_IRCP1ISR0_CP1_INT_MASK              (0x2U)
#define MSCM_IRCP1ISR0_CP1_INT_SHIFT             (1U)
#define MSCM_IRCP1ISR0_CP1_INT_WIDTH             (1U)
#define MSCM_IRCP1ISR0_CP1_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP1ISR0_CP1_INT_SHIFT)) & MSCM_IRCP1ISR0_CP1_INT_MASK)

#define MSCM_IRCP1ISR0_CP2_INT_MASK              (0x4U)
#define MSCM_IRCP1ISR0_CP2_INT_SHIFT             (2U)
#define MSCM_IRCP1ISR0_CP2_INT_WIDTH             (1U)
#define MSCM_IRCP1ISR0_CP2_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP1ISR0_CP2_INT_SHIFT)) & MSCM_IRCP1ISR0_CP2_INT_MASK)

#define MSCM_IRCP1ISR0_CP3_INT_MASK              (0x8U)
#define MSCM_IRCP1ISR0_CP3_INT_SHIFT             (3U)
#define MSCM_IRCP1ISR0_CP3_INT_WIDTH             (1U)
#define MSCM_IRCP1ISR0_CP3_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP1ISR0_CP3_INT_SHIFT)) & MSCM_IRCP1ISR0_CP3_INT_MASK)
/*! @} */

/*! @name IRCP1IGR0 - Interrupt Router CP1 Interrupt Generation */
/*! @{ */

#define MSCM_IRCP1IGR0_INT_EN_MASK               (0x1U)
#define MSCM_IRCP1IGR0_INT_EN_SHIFT              (0U)
#define MSCM_IRCP1IGR0_INT_EN_WIDTH              (1U)
#define MSCM_IRCP1IGR0_INT_EN(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP1IGR0_INT_EN_SHIFT)) & MSCM_IRCP1IGR0_INT_EN_MASK)
/*! @} */

/*! @name IRCP1ISR1 - Interrupt Router CP1 Interrupt Status */
/*! @{ */

#define MSCM_IRCP1ISR1_CP0_INT_MASK              (0x1U)
#define MSCM_IRCP1ISR1_CP0_INT_SHIFT             (0U)
#define MSCM_IRCP1ISR1_CP0_INT_WIDTH             (1U)
#define MSCM_IRCP1ISR1_CP0_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP1ISR1_CP0_INT_SHIFT)) & MSCM_IRCP1ISR1_CP0_INT_MASK)

#define MSCM_IRCP1ISR1_CP1_INT_MASK              (0x2U)
#define MSCM_IRCP1ISR1_CP1_INT_SHIFT             (1U)
#define MSCM_IRCP1ISR1_CP1_INT_WIDTH             (1U)
#define MSCM_IRCP1ISR1_CP1_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP1ISR1_CP1_INT_SHIFT)) & MSCM_IRCP1ISR1_CP1_INT_MASK)

#define MSCM_IRCP1ISR1_CP2_INT_MASK              (0x4U)
#define MSCM_IRCP1ISR1_CP2_INT_SHIFT             (2U)
#define MSCM_IRCP1ISR1_CP2_INT_WIDTH             (1U)
#define MSCM_IRCP1ISR1_CP2_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP1ISR1_CP2_INT_SHIFT)) & MSCM_IRCP1ISR1_CP2_INT_MASK)

#define MSCM_IRCP1ISR1_CP3_INT_MASK              (0x8U)
#define MSCM_IRCP1ISR1_CP3_INT_SHIFT             (3U)
#define MSCM_IRCP1ISR1_CP3_INT_WIDTH             (1U)
#define MSCM_IRCP1ISR1_CP3_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP1ISR1_CP3_INT_SHIFT)) & MSCM_IRCP1ISR1_CP3_INT_MASK)
/*! @} */

/*! @name IRCP1IGR1 - Interrupt Router CP1 Interrupt Generation */
/*! @{ */

#define MSCM_IRCP1IGR1_INT_EN_MASK               (0x1U)
#define MSCM_IRCP1IGR1_INT_EN_SHIFT              (0U)
#define MSCM_IRCP1IGR1_INT_EN_WIDTH              (1U)
#define MSCM_IRCP1IGR1_INT_EN(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP1IGR1_INT_EN_SHIFT)) & MSCM_IRCP1IGR1_INT_EN_MASK)
/*! @} */

/*! @name IRCP1ISR2 - Interrupt Router CP1 Interrupt Status */
/*! @{ */

#define MSCM_IRCP1ISR2_CP0_INT_MASK              (0x1U)
#define MSCM_IRCP1ISR2_CP0_INT_SHIFT             (0U)
#define MSCM_IRCP1ISR2_CP0_INT_WIDTH             (1U)
#define MSCM_IRCP1ISR2_CP0_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP1ISR2_CP0_INT_SHIFT)) & MSCM_IRCP1ISR2_CP0_INT_MASK)

#define MSCM_IRCP1ISR2_CP1_INT_MASK              (0x2U)
#define MSCM_IRCP1ISR2_CP1_INT_SHIFT             (1U)
#define MSCM_IRCP1ISR2_CP1_INT_WIDTH             (1U)
#define MSCM_IRCP1ISR2_CP1_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP1ISR2_CP1_INT_SHIFT)) & MSCM_IRCP1ISR2_CP1_INT_MASK)

#define MSCM_IRCP1ISR2_CP2_INT_MASK              (0x4U)
#define MSCM_IRCP1ISR2_CP2_INT_SHIFT             (2U)
#define MSCM_IRCP1ISR2_CP2_INT_WIDTH             (1U)
#define MSCM_IRCP1ISR2_CP2_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP1ISR2_CP2_INT_SHIFT)) & MSCM_IRCP1ISR2_CP2_INT_MASK)

#define MSCM_IRCP1ISR2_CP3_INT_MASK              (0x8U)
#define MSCM_IRCP1ISR2_CP3_INT_SHIFT             (3U)
#define MSCM_IRCP1ISR2_CP3_INT_WIDTH             (1U)
#define MSCM_IRCP1ISR2_CP3_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP1ISR2_CP3_INT_SHIFT)) & MSCM_IRCP1ISR2_CP3_INT_MASK)
/*! @} */

/*! @name IRCP1IGR2 - Interrupt Router CP1 Interrupt Generation */
/*! @{ */

#define MSCM_IRCP1IGR2_INT_EN_MASK               (0x1U)
#define MSCM_IRCP1IGR2_INT_EN_SHIFT              (0U)
#define MSCM_IRCP1IGR2_INT_EN_WIDTH              (1U)
#define MSCM_IRCP1IGR2_INT_EN(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP1IGR2_INT_EN_SHIFT)) & MSCM_IRCP1IGR2_INT_EN_MASK)
/*! @} */

/*! @name IRCP1ISR3 - Interrupt Router CP1 Interrupt Status */
/*! @{ */

#define MSCM_IRCP1ISR3_CP0_INT_MASK              (0x1U)
#define MSCM_IRCP1ISR3_CP0_INT_SHIFT             (0U)
#define MSCM_IRCP1ISR3_CP0_INT_WIDTH             (1U)
#define MSCM_IRCP1ISR3_CP0_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP1ISR3_CP0_INT_SHIFT)) & MSCM_IRCP1ISR3_CP0_INT_MASK)

#define MSCM_IRCP1ISR3_CP1_INT_MASK              (0x2U)
#define MSCM_IRCP1ISR3_CP1_INT_SHIFT             (1U)
#define MSCM_IRCP1ISR3_CP1_INT_WIDTH             (1U)
#define MSCM_IRCP1ISR3_CP1_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP1ISR3_CP1_INT_SHIFT)) & MSCM_IRCP1ISR3_CP1_INT_MASK)

#define MSCM_IRCP1ISR3_CP2_INT_MASK              (0x4U)
#define MSCM_IRCP1ISR3_CP2_INT_SHIFT             (2U)
#define MSCM_IRCP1ISR3_CP2_INT_WIDTH             (1U)
#define MSCM_IRCP1ISR3_CP2_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP1ISR3_CP2_INT_SHIFT)) & MSCM_IRCP1ISR3_CP2_INT_MASK)

#define MSCM_IRCP1ISR3_CP3_INT_MASK              (0x8U)
#define MSCM_IRCP1ISR3_CP3_INT_SHIFT             (3U)
#define MSCM_IRCP1ISR3_CP3_INT_WIDTH             (1U)
#define MSCM_IRCP1ISR3_CP3_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP1ISR3_CP3_INT_SHIFT)) & MSCM_IRCP1ISR3_CP3_INT_MASK)
/*! @} */

/*! @name IRCP1IGR3 - Interrupt Router CP1 Interrupt Generation */
/*! @{ */

#define MSCM_IRCP1IGR3_INT_EN_MASK               (0x1U)
#define MSCM_IRCP1IGR3_INT_EN_SHIFT              (0U)
#define MSCM_IRCP1IGR3_INT_EN_WIDTH              (1U)
#define MSCM_IRCP1IGR3_INT_EN(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP1IGR3_INT_EN_SHIFT)) & MSCM_IRCP1IGR3_INT_EN_MASK)
/*! @} */

/*! @name IRCP2ISR0 - Interrupt Router CP2 Interrupt Status */
/*! @{ */

#define MSCM_IRCP2ISR0_CP0_INT_MASK              (0x1U)
#define MSCM_IRCP2ISR0_CP0_INT_SHIFT             (0U)
#define MSCM_IRCP2ISR0_CP0_INT_WIDTH             (1U)
#define MSCM_IRCP2ISR0_CP0_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP2ISR0_CP0_INT_SHIFT)) & MSCM_IRCP2ISR0_CP0_INT_MASK)

#define MSCM_IRCP2ISR0_CP1_INT_MASK              (0x2U)
#define MSCM_IRCP2ISR0_CP1_INT_SHIFT             (1U)
#define MSCM_IRCP2ISR0_CP1_INT_WIDTH             (1U)
#define MSCM_IRCP2ISR0_CP1_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP2ISR0_CP1_INT_SHIFT)) & MSCM_IRCP2ISR0_CP1_INT_MASK)

#define MSCM_IRCP2ISR0_CP2_INT_MASK              (0x4U)
#define MSCM_IRCP2ISR0_CP2_INT_SHIFT             (2U)
#define MSCM_IRCP2ISR0_CP2_INT_WIDTH             (1U)
#define MSCM_IRCP2ISR0_CP2_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP2ISR0_CP2_INT_SHIFT)) & MSCM_IRCP2ISR0_CP2_INT_MASK)

#define MSCM_IRCP2ISR0_CP3_INT_MASK              (0x8U)
#define MSCM_IRCP2ISR0_CP3_INT_SHIFT             (3U)
#define MSCM_IRCP2ISR0_CP3_INT_WIDTH             (1U)
#define MSCM_IRCP2ISR0_CP3_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP2ISR0_CP3_INT_SHIFT)) & MSCM_IRCP2ISR0_CP3_INT_MASK)
/*! @} */

/*! @name IRCP2IGR0 - Interrupt Router CP2 Interrupt Generation */
/*! @{ */

#define MSCM_IRCP2IGR0_INT_EN_MASK               (0x1U)
#define MSCM_IRCP2IGR0_INT_EN_SHIFT              (0U)
#define MSCM_IRCP2IGR0_INT_EN_WIDTH              (1U)
#define MSCM_IRCP2IGR0_INT_EN(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP2IGR0_INT_EN_SHIFT)) & MSCM_IRCP2IGR0_INT_EN_MASK)
/*! @} */

/*! @name IRCP2ISR1 - Interrupt Router CP2 Interrupt Status */
/*! @{ */

#define MSCM_IRCP2ISR1_CP0_INT_MASK              (0x1U)
#define MSCM_IRCP2ISR1_CP0_INT_SHIFT             (0U)
#define MSCM_IRCP2ISR1_CP0_INT_WIDTH             (1U)
#define MSCM_IRCP2ISR1_CP0_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP2ISR1_CP0_INT_SHIFT)) & MSCM_IRCP2ISR1_CP0_INT_MASK)

#define MSCM_IRCP2ISR1_CP1_INT_MASK              (0x2U)
#define MSCM_IRCP2ISR1_CP1_INT_SHIFT             (1U)
#define MSCM_IRCP2ISR1_CP1_INT_WIDTH             (1U)
#define MSCM_IRCP2ISR1_CP1_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP2ISR1_CP1_INT_SHIFT)) & MSCM_IRCP2ISR1_CP1_INT_MASK)

#define MSCM_IRCP2ISR1_CP2_INT_MASK              (0x4U)
#define MSCM_IRCP2ISR1_CP2_INT_SHIFT             (2U)
#define MSCM_IRCP2ISR1_CP2_INT_WIDTH             (1U)
#define MSCM_IRCP2ISR1_CP2_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP2ISR1_CP2_INT_SHIFT)) & MSCM_IRCP2ISR1_CP2_INT_MASK)

#define MSCM_IRCP2ISR1_CP3_INT_MASK              (0x8U)
#define MSCM_IRCP2ISR1_CP3_INT_SHIFT             (3U)
#define MSCM_IRCP2ISR1_CP3_INT_WIDTH             (1U)
#define MSCM_IRCP2ISR1_CP3_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP2ISR1_CP3_INT_SHIFT)) & MSCM_IRCP2ISR1_CP3_INT_MASK)
/*! @} */

/*! @name IRCP2IGR1 - Interrupt Router CP2 Interrupt Generation */
/*! @{ */

#define MSCM_IRCP2IGR1_INT_EN_MASK               (0x1U)
#define MSCM_IRCP2IGR1_INT_EN_SHIFT              (0U)
#define MSCM_IRCP2IGR1_INT_EN_WIDTH              (1U)
#define MSCM_IRCP2IGR1_INT_EN(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP2IGR1_INT_EN_SHIFT)) & MSCM_IRCP2IGR1_INT_EN_MASK)
/*! @} */

/*! @name IRCP2ISR2 - Interrupt Router CP2 Interrupt Status */
/*! @{ */

#define MSCM_IRCP2ISR2_CP0_INT_MASK              (0x1U)
#define MSCM_IRCP2ISR2_CP0_INT_SHIFT             (0U)
#define MSCM_IRCP2ISR2_CP0_INT_WIDTH             (1U)
#define MSCM_IRCP2ISR2_CP0_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP2ISR2_CP0_INT_SHIFT)) & MSCM_IRCP2ISR2_CP0_INT_MASK)

#define MSCM_IRCP2ISR2_CP1_INT_MASK              (0x2U)
#define MSCM_IRCP2ISR2_CP1_INT_SHIFT             (1U)
#define MSCM_IRCP2ISR2_CP1_INT_WIDTH             (1U)
#define MSCM_IRCP2ISR2_CP1_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP2ISR2_CP1_INT_SHIFT)) & MSCM_IRCP2ISR2_CP1_INT_MASK)

#define MSCM_IRCP2ISR2_CP2_INT_MASK              (0x4U)
#define MSCM_IRCP2ISR2_CP2_INT_SHIFT             (2U)
#define MSCM_IRCP2ISR2_CP2_INT_WIDTH             (1U)
#define MSCM_IRCP2ISR2_CP2_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP2ISR2_CP2_INT_SHIFT)) & MSCM_IRCP2ISR2_CP2_INT_MASK)

#define MSCM_IRCP2ISR2_CP3_INT_MASK              (0x8U)
#define MSCM_IRCP2ISR2_CP3_INT_SHIFT             (3U)
#define MSCM_IRCP2ISR2_CP3_INT_WIDTH             (1U)
#define MSCM_IRCP2ISR2_CP3_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP2ISR2_CP3_INT_SHIFT)) & MSCM_IRCP2ISR2_CP3_INT_MASK)
/*! @} */

/*! @name IRCP2IGR2 - Interrupt Router CP2 Interrupt Generation */
/*! @{ */

#define MSCM_IRCP2IGR2_INT_EN_MASK               (0x1U)
#define MSCM_IRCP2IGR2_INT_EN_SHIFT              (0U)
#define MSCM_IRCP2IGR2_INT_EN_WIDTH              (1U)
#define MSCM_IRCP2IGR2_INT_EN(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP2IGR2_INT_EN_SHIFT)) & MSCM_IRCP2IGR2_INT_EN_MASK)
/*! @} */

/*! @name IRCP2ISR3 - Interrupt Router CP2 Interrupt Status */
/*! @{ */

#define MSCM_IRCP2ISR3_CP0_INT_MASK              (0x1U)
#define MSCM_IRCP2ISR3_CP0_INT_SHIFT             (0U)
#define MSCM_IRCP2ISR3_CP0_INT_WIDTH             (1U)
#define MSCM_IRCP2ISR3_CP0_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP2ISR3_CP0_INT_SHIFT)) & MSCM_IRCP2ISR3_CP0_INT_MASK)

#define MSCM_IRCP2ISR3_CP1_INT_MASK              (0x2U)
#define MSCM_IRCP2ISR3_CP1_INT_SHIFT             (1U)
#define MSCM_IRCP2ISR3_CP1_INT_WIDTH             (1U)
#define MSCM_IRCP2ISR3_CP1_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP2ISR3_CP1_INT_SHIFT)) & MSCM_IRCP2ISR3_CP1_INT_MASK)

#define MSCM_IRCP2ISR3_CP2_INT_MASK              (0x4U)
#define MSCM_IRCP2ISR3_CP2_INT_SHIFT             (2U)
#define MSCM_IRCP2ISR3_CP2_INT_WIDTH             (1U)
#define MSCM_IRCP2ISR3_CP2_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP2ISR3_CP2_INT_SHIFT)) & MSCM_IRCP2ISR3_CP2_INT_MASK)

#define MSCM_IRCP2ISR3_CP3_INT_MASK              (0x8U)
#define MSCM_IRCP2ISR3_CP3_INT_SHIFT             (3U)
#define MSCM_IRCP2ISR3_CP3_INT_WIDTH             (1U)
#define MSCM_IRCP2ISR3_CP3_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP2ISR3_CP3_INT_SHIFT)) & MSCM_IRCP2ISR3_CP3_INT_MASK)
/*! @} */

/*! @name IRCP2IGR3 - Interrupt Router CP2 Interrupt Generation */
/*! @{ */

#define MSCM_IRCP2IGR3_INT_EN_MASK               (0x1U)
#define MSCM_IRCP2IGR3_INT_EN_SHIFT              (0U)
#define MSCM_IRCP2IGR3_INT_EN_WIDTH              (1U)
#define MSCM_IRCP2IGR3_INT_EN(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP2IGR3_INT_EN_SHIFT)) & MSCM_IRCP2IGR3_INT_EN_MASK)
/*! @} */

/*! @name IRCP3ISR0 - Interrupt Router CP3 Interrupt Status */
/*! @{ */

#define MSCM_IRCP3ISR0_CP0_INT_MASK              (0x1U)
#define MSCM_IRCP3ISR0_CP0_INT_SHIFT             (0U)
#define MSCM_IRCP3ISR0_CP0_INT_WIDTH             (1U)
#define MSCM_IRCP3ISR0_CP0_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP3ISR0_CP0_INT_SHIFT)) & MSCM_IRCP3ISR0_CP0_INT_MASK)

#define MSCM_IRCP3ISR0_CP1_INT_MASK              (0x2U)
#define MSCM_IRCP3ISR0_CP1_INT_SHIFT             (1U)
#define MSCM_IRCP3ISR0_CP1_INT_WIDTH             (1U)
#define MSCM_IRCP3ISR0_CP1_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP3ISR0_CP1_INT_SHIFT)) & MSCM_IRCP3ISR0_CP1_INT_MASK)

#define MSCM_IRCP3ISR0_CP2_INT_MASK              (0x4U)
#define MSCM_IRCP3ISR0_CP2_INT_SHIFT             (2U)
#define MSCM_IRCP3ISR0_CP2_INT_WIDTH             (1U)
#define MSCM_IRCP3ISR0_CP2_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP3ISR0_CP2_INT_SHIFT)) & MSCM_IRCP3ISR0_CP2_INT_MASK)

#define MSCM_IRCP3ISR0_CP3_INT_MASK              (0x8U)
#define MSCM_IRCP3ISR0_CP3_INT_SHIFT             (3U)
#define MSCM_IRCP3ISR0_CP3_INT_WIDTH             (1U)
#define MSCM_IRCP3ISR0_CP3_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP3ISR0_CP3_INT_SHIFT)) & MSCM_IRCP3ISR0_CP3_INT_MASK)
/*! @} */

/*! @name IRCP3IGR0 - Interrupt Router CP3 Interrupt Generation */
/*! @{ */

#define MSCM_IRCP3IGR0_INT_EN_MASK               (0x1U)
#define MSCM_IRCP3IGR0_INT_EN_SHIFT              (0U)
#define MSCM_IRCP3IGR0_INT_EN_WIDTH              (1U)
#define MSCM_IRCP3IGR0_INT_EN(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP3IGR0_INT_EN_SHIFT)) & MSCM_IRCP3IGR0_INT_EN_MASK)
/*! @} */

/*! @name IRCP3ISR1 - Interrupt Router CP3 Interrupt Status */
/*! @{ */

#define MSCM_IRCP3ISR1_CP0_INT_MASK              (0x1U)
#define MSCM_IRCP3ISR1_CP0_INT_SHIFT             (0U)
#define MSCM_IRCP3ISR1_CP0_INT_WIDTH             (1U)
#define MSCM_IRCP3ISR1_CP0_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP3ISR1_CP0_INT_SHIFT)) & MSCM_IRCP3ISR1_CP0_INT_MASK)

#define MSCM_IRCP3ISR1_CP1_INT_MASK              (0x2U)
#define MSCM_IRCP3ISR1_CP1_INT_SHIFT             (1U)
#define MSCM_IRCP3ISR1_CP1_INT_WIDTH             (1U)
#define MSCM_IRCP3ISR1_CP1_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP3ISR1_CP1_INT_SHIFT)) & MSCM_IRCP3ISR1_CP1_INT_MASK)

#define MSCM_IRCP3ISR1_CP2_INT_MASK              (0x4U)
#define MSCM_IRCP3ISR1_CP2_INT_SHIFT             (2U)
#define MSCM_IRCP3ISR1_CP2_INT_WIDTH             (1U)
#define MSCM_IRCP3ISR1_CP2_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP3ISR1_CP2_INT_SHIFT)) & MSCM_IRCP3ISR1_CP2_INT_MASK)

#define MSCM_IRCP3ISR1_CP3_INT_MASK              (0x8U)
#define MSCM_IRCP3ISR1_CP3_INT_SHIFT             (3U)
#define MSCM_IRCP3ISR1_CP3_INT_WIDTH             (1U)
#define MSCM_IRCP3ISR1_CP3_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP3ISR1_CP3_INT_SHIFT)) & MSCM_IRCP3ISR1_CP3_INT_MASK)
/*! @} */

/*! @name IRCP3IGR1 - Interrupt Router CP3 Interrupt Generation */
/*! @{ */

#define MSCM_IRCP3IGR1_INT_EN_MASK               (0x1U)
#define MSCM_IRCP3IGR1_INT_EN_SHIFT              (0U)
#define MSCM_IRCP3IGR1_INT_EN_WIDTH              (1U)
#define MSCM_IRCP3IGR1_INT_EN(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP3IGR1_INT_EN_SHIFT)) & MSCM_IRCP3IGR1_INT_EN_MASK)
/*! @} */

/*! @name IRCP3ISR2 - Interrupt Router CP3 Interrupt Status */
/*! @{ */

#define MSCM_IRCP3ISR2_CP0_INT_MASK              (0x1U)
#define MSCM_IRCP3ISR2_CP0_INT_SHIFT             (0U)
#define MSCM_IRCP3ISR2_CP0_INT_WIDTH             (1U)
#define MSCM_IRCP3ISR2_CP0_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP3ISR2_CP0_INT_SHIFT)) & MSCM_IRCP3ISR2_CP0_INT_MASK)

#define MSCM_IRCP3ISR2_CP1_INT_MASK              (0x2U)
#define MSCM_IRCP3ISR2_CP1_INT_SHIFT             (1U)
#define MSCM_IRCP3ISR2_CP1_INT_WIDTH             (1U)
#define MSCM_IRCP3ISR2_CP1_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP3ISR2_CP1_INT_SHIFT)) & MSCM_IRCP3ISR2_CP1_INT_MASK)

#define MSCM_IRCP3ISR2_CP2_INT_MASK              (0x4U)
#define MSCM_IRCP3ISR2_CP2_INT_SHIFT             (2U)
#define MSCM_IRCP3ISR2_CP2_INT_WIDTH             (1U)
#define MSCM_IRCP3ISR2_CP2_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP3ISR2_CP2_INT_SHIFT)) & MSCM_IRCP3ISR2_CP2_INT_MASK)

#define MSCM_IRCP3ISR2_CP3_INT_MASK              (0x8U)
#define MSCM_IRCP3ISR2_CP3_INT_SHIFT             (3U)
#define MSCM_IRCP3ISR2_CP3_INT_WIDTH             (1U)
#define MSCM_IRCP3ISR2_CP3_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP3ISR2_CP3_INT_SHIFT)) & MSCM_IRCP3ISR2_CP3_INT_MASK)
/*! @} */

/*! @name IRCP3IGR2 - Interrupt Router CP3 Interrupt Generation */
/*! @{ */

#define MSCM_IRCP3IGR2_INT_EN_MASK               (0x1U)
#define MSCM_IRCP3IGR2_INT_EN_SHIFT              (0U)
#define MSCM_IRCP3IGR2_INT_EN_WIDTH              (1U)
#define MSCM_IRCP3IGR2_INT_EN(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP3IGR2_INT_EN_SHIFT)) & MSCM_IRCP3IGR2_INT_EN_MASK)
/*! @} */

/*! @name IRCP3ISR3 - Interrupt Router CP3 Interrupt Status */
/*! @{ */

#define MSCM_IRCP3ISR3_CP0_INT_MASK              (0x1U)
#define MSCM_IRCP3ISR3_CP0_INT_SHIFT             (0U)
#define MSCM_IRCP3ISR3_CP0_INT_WIDTH             (1U)
#define MSCM_IRCP3ISR3_CP0_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP3ISR3_CP0_INT_SHIFT)) & MSCM_IRCP3ISR3_CP0_INT_MASK)

#define MSCM_IRCP3ISR3_CP1_INT_MASK              (0x2U)
#define MSCM_IRCP3ISR3_CP1_INT_SHIFT             (1U)
#define MSCM_IRCP3ISR3_CP1_INT_WIDTH             (1U)
#define MSCM_IRCP3ISR3_CP1_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP3ISR3_CP1_INT_SHIFT)) & MSCM_IRCP3ISR3_CP1_INT_MASK)

#define MSCM_IRCP3ISR3_CP2_INT_MASK              (0x4U)
#define MSCM_IRCP3ISR3_CP2_INT_SHIFT             (2U)
#define MSCM_IRCP3ISR3_CP2_INT_WIDTH             (1U)
#define MSCM_IRCP3ISR3_CP2_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP3ISR3_CP2_INT_SHIFT)) & MSCM_IRCP3ISR3_CP2_INT_MASK)

#define MSCM_IRCP3ISR3_CP3_INT_MASK              (0x8U)
#define MSCM_IRCP3ISR3_CP3_INT_SHIFT             (3U)
#define MSCM_IRCP3ISR3_CP3_INT_WIDTH             (1U)
#define MSCM_IRCP3ISR3_CP3_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP3ISR3_CP3_INT_SHIFT)) & MSCM_IRCP3ISR3_CP3_INT_MASK)
/*! @} */

/*! @name IRCP3IGR3 - Interrupt Router CP3 Interrupt Generation */
/*! @{ */

#define MSCM_IRCP3IGR3_INT_EN_MASK               (0x1U)
#define MSCM_IRCP3IGR3_INT_EN_SHIFT              (0U)
#define MSCM_IRCP3IGR3_INT_EN_WIDTH              (1U)
#define MSCM_IRCP3IGR3_INT_EN(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP3IGR3_INT_EN_SHIFT)) & MSCM_IRCP3IGR3_INT_EN_MASK)
/*! @} */

/*! @name IRCPCFG - Interrupt Router Configuration */
/*! @{ */

#define MSCM_IRCPCFG_CP0_TR_MASK                 (0x1U)
#define MSCM_IRCPCFG_CP0_TR_SHIFT                (0U)
#define MSCM_IRCPCFG_CP0_TR_WIDTH                (1U)
#define MSCM_IRCPCFG_CP0_TR(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_IRCPCFG_CP0_TR_SHIFT)) & MSCM_IRCPCFG_CP0_TR_MASK)

#define MSCM_IRCPCFG_CP1_TR_MASK                 (0x2U)
#define MSCM_IRCPCFG_CP1_TR_SHIFT                (1U)
#define MSCM_IRCPCFG_CP1_TR_WIDTH                (1U)
#define MSCM_IRCPCFG_CP1_TR(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_IRCPCFG_CP1_TR_SHIFT)) & MSCM_IRCPCFG_CP1_TR_MASK)

#define MSCM_IRCPCFG_CP2_TR_MASK                 (0x4U)
#define MSCM_IRCPCFG_CP2_TR_SHIFT                (2U)
#define MSCM_IRCPCFG_CP2_TR_WIDTH                (1U)
#define MSCM_IRCPCFG_CP2_TR(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_IRCPCFG_CP2_TR_SHIFT)) & MSCM_IRCPCFG_CP2_TR_MASK)

#define MSCM_IRCPCFG_CP3_TR_MASK                 (0x8U)
#define MSCM_IRCPCFG_CP3_TR_SHIFT                (3U)
#define MSCM_IRCPCFG_CP3_TR_WIDTH                (1U)
#define MSCM_IRCPCFG_CP3_TR(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_IRCPCFG_CP3_TR_SHIFT)) & MSCM_IRCPCFG_CP3_TR_MASK)

#define MSCM_IRCPCFG_LOCK_MASK                   (0x80000000U)
#define MSCM_IRCPCFG_LOCK_SHIFT                  (31U)
#define MSCM_IRCPCFG_LOCK_WIDTH                  (1U)
#define MSCM_IRCPCFG_LOCK(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_IRCPCFG_LOCK_SHIFT)) & MSCM_IRCPCFG_LOCK_MASK)
/*! @} */

/*! @name ENEDC0 - Read Data Check Enable */
/*! @{ */

#define MSCM_ENEDC0_CM7_0_AHBM_MASK              (0x1U)
#define MSCM_ENEDC0_CM7_0_AHBM_SHIFT             (0U)
#define MSCM_ENEDC0_CM7_0_AHBM_WIDTH             (1U)
#define MSCM_ENEDC0_CM7_0_AHBM(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC0_CM7_0_AHBM_SHIFT)) & MSCM_ENEDC0_CM7_0_AHBM_MASK)

#define MSCM_ENEDC0_CM7_0_AHBP_MASK              (0x2U)
#define MSCM_ENEDC0_CM7_0_AHBP_SHIFT             (1U)
#define MSCM_ENEDC0_CM7_0_AHBP_WIDTH             (1U)
#define MSCM_ENEDC0_CM7_0_AHBP(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC0_CM7_0_AHBP_SHIFT)) & MSCM_ENEDC0_CM7_0_AHBP_MASK)

#define MSCM_ENEDC0_eDMA_MASK                    (0x4U)
#define MSCM_ENEDC0_eDMA_SHIFT                   (2U)
#define MSCM_ENEDC0_eDMA_WIDTH                   (1U)
#define MSCM_ENEDC0_eDMA(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC0_eDMA_SHIFT)) & MSCM_ENEDC0_eDMA_MASK)

#define MSCM_ENEDC0_APP2RT_MASK                  (0x8U)
#define MSCM_ENEDC0_APP2RT_SHIFT                 (3U)
#define MSCM_ENEDC0_APP2RT_WIDTH                 (1U)
#define MSCM_ENEDC0_APP2RT(x)                    (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC0_APP2RT_SHIFT)) & MSCM_ENEDC0_APP2RT_MASK)

#define MSCM_ENEDC0_HSE_MASK                     (0x10U)
#define MSCM_ENEDC0_HSE_SHIFT                    (4U)
#define MSCM_ENEDC0_HSE_WIDTH                    (1U)
#define MSCM_ENEDC0_HSE(x)                       (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC0_HSE_SHIFT)) & MSCM_ENEDC0_HSE_MASK)

#define MSCM_ENEDC0_ENET_MASK                    (0x20U)
#define MSCM_ENEDC0_ENET_SHIFT                   (5U)
#define MSCM_ENEDC0_ENET_WIDTH                   (1U)
#define MSCM_ENEDC0_ENET(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC0_ENET_SHIFT)) & MSCM_ENEDC0_ENET_MASK)

#define MSCM_ENEDC0_CM7_1_AHBM_MASK              (0x40U)
#define MSCM_ENEDC0_CM7_1_AHBM_SHIFT             (6U)
#define MSCM_ENEDC0_CM7_1_AHBM_WIDTH             (1U)
#define MSCM_ENEDC0_CM7_1_AHBM(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC0_CM7_1_AHBM_SHIFT)) & MSCM_ENEDC0_CM7_1_AHBM_MASK)

#define MSCM_ENEDC0_CM7_1_AHBP_MASK              (0x80U)
#define MSCM_ENEDC0_CM7_1_AHBP_SHIFT             (7U)
#define MSCM_ENEDC0_CM7_1_AHBP_WIDTH             (1U)
#define MSCM_ENEDC0_CM7_1_AHBP(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC0_CM7_1_AHBP_SHIFT)) & MSCM_ENEDC0_CM7_1_AHBP_MASK)

#define MSCM_ENEDC0_TCM_MASK                     (0x100U)
#define MSCM_ENEDC0_TCM_SHIFT                    (8U)
#define MSCM_ENEDC0_TCM_WIDTH                    (1U)
#define MSCM_ENEDC0_TCM(x)                       (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC0_TCM_SHIFT)) & MSCM_ENEDC0_TCM_MASK)

#define MSCM_ENEDC0_STAM_MASK                    (0x200U)
#define MSCM_ENEDC0_STAM_SHIFT                   (9U)
#define MSCM_ENEDC0_STAM_WIDTH                   (1U)
#define MSCM_ENEDC0_STAM(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC0_STAM_SHIFT)) & MSCM_ENEDC0_STAM_MASK)

#define MSCM_ENEDC0_DEBUG_MASK                   (0x400U)
#define MSCM_ENEDC0_DEBUG_SHIFT                  (10U)
#define MSCM_ENEDC0_DEBUG_WIDTH                  (1U)
#define MSCM_ENEDC0_DEBUG(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC0_DEBUG_SHIFT)) & MSCM_ENEDC0_DEBUG_MASK)

#define MSCM_ENEDC0_APP2RTPERIPH_MASK            (0x800U)
#define MSCM_ENEDC0_APP2RTPERIPH_SHIFT           (11U)
#define MSCM_ENEDC0_APP2RTPERIPH_WIDTH           (1U)
#define MSCM_ENEDC0_APP2RTPERIPH(x)              (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC0_APP2RTPERIPH_SHIFT)) & MSCM_ENEDC0_APP2RTPERIPH_MASK)

#define MSCM_ENEDC0_APP2RTPRAM_MASK              (0x1000U)
#define MSCM_ENEDC0_APP2RTPRAM_SHIFT             (12U)
#define MSCM_ENEDC0_APP2RTPRAM_WIDTH             (1U)
#define MSCM_ENEDC0_APP2RTPRAM(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC0_APP2RTPRAM_SHIFT)) & MSCM_ENEDC0_APP2RTPRAM_MASK)
/*! @} */

/*! @name ENEDC1 - Write Data Check Enable */
/*! @{ */

#define MSCM_ENEDC1_PRAM0_MASK                   (0x1U)
#define MSCM_ENEDC1_PRAM0_SHIFT                  (0U)
#define MSCM_ENEDC1_PRAM0_WIDTH                  (1U)
#define MSCM_ENEDC1_PRAM0(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC1_PRAM0_SHIFT)) & MSCM_ENEDC1_PRAM0_MASK)

#define MSCM_ENEDC1_PRAM1_MASK                   (0x2U)
#define MSCM_ENEDC1_PRAM1_SHIFT                  (1U)
#define MSCM_ENEDC1_PRAM1_WIDTH                  (1U)
#define MSCM_ENEDC1_PRAM1(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC1_PRAM1_SHIFT)) & MSCM_ENEDC1_PRAM1_MASK)

#define MSCM_ENEDC1_PRAM2_MASK                   (0x4U)
#define MSCM_ENEDC1_PRAM2_SHIFT                  (2U)
#define MSCM_ENEDC1_PRAM2_WIDTH                  (1U)
#define MSCM_ENEDC1_PRAM2(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC1_PRAM2_SHIFT)) & MSCM_ENEDC1_PRAM2_MASK)

#define MSCM_ENEDC1_PRAM3_MASK                   (0x8U)
#define MSCM_ENEDC1_PRAM3_SHIFT                  (3U)
#define MSCM_ENEDC1_PRAM3_WIDTH                  (1U)
#define MSCM_ENEDC1_PRAM3(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC1_PRAM3_SHIFT)) & MSCM_ENEDC1_PRAM3_MASK)

#define MSCM_ENEDC1_PRAM4_MASK                   (0x10U)
#define MSCM_ENEDC1_PRAM4_SHIFT                  (4U)
#define MSCM_ENEDC1_PRAM4_WIDTH                  (1U)
#define MSCM_ENEDC1_PRAM4(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC1_PRAM4_SHIFT)) & MSCM_ENEDC1_PRAM4_MASK)

#define MSCM_ENEDC1_PRAM5_MASK                   (0x20U)
#define MSCM_ENEDC1_PRAM5_SHIFT                  (5U)
#define MSCM_ENEDC1_PRAM5_WIDTH                  (1U)
#define MSCM_ENEDC1_PRAM5(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC1_PRAM5_SHIFT)) & MSCM_ENEDC1_PRAM5_MASK)

#define MSCM_ENEDC1_PRAM6_MASK                   (0x40U)
#define MSCM_ENEDC1_PRAM6_SHIFT                  (6U)
#define MSCM_ENEDC1_PRAM6_WIDTH                  (1U)
#define MSCM_ENEDC1_PRAM6(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC1_PRAM6_SHIFT)) & MSCM_ENEDC1_PRAM6_MASK)

#define MSCM_ENEDC1_PRAM7_MASK                   (0x80U)
#define MSCM_ENEDC1_PRAM7_SHIFT                  (7U)
#define MSCM_ENEDC1_PRAM7_WIDTH                  (1U)
#define MSCM_ENEDC1_PRAM7(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC1_PRAM7_SHIFT)) & MSCM_ENEDC1_PRAM7_MASK)

#define MSCM_ENEDC1_PRAM8_MASK                   (0x100U)
#define MSCM_ENEDC1_PRAM8_SHIFT                  (8U)
#define MSCM_ENEDC1_PRAM8_WIDTH                  (1U)
#define MSCM_ENEDC1_PRAM8(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC1_PRAM8_SHIFT)) & MSCM_ENEDC1_PRAM8_MASK)

#define MSCM_ENEDC1_TCM_MASK                     (0x200U)
#define MSCM_ENEDC1_TCM_SHIFT                    (9U)
#define MSCM_ENEDC1_TCM_WIDTH                    (1U)
#define MSCM_ENEDC1_TCM(x)                       (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC1_TCM_SHIFT)) & MSCM_ENEDC1_TCM_MASK)

#define MSCM_ENEDC1_QSPI_MASK                    (0x400U)
#define MSCM_ENEDC1_QSPI_SHIFT                   (10U)
#define MSCM_ENEDC1_QSPI_WIDTH                   (1U)
#define MSCM_ENEDC1_QSPI(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC1_QSPI_SHIFT)) & MSCM_ENEDC1_QSPI_MASK)

#define MSCM_ENEDC1_RT2APP_MASK                  (0x800U)
#define MSCM_ENEDC1_RT2APP_SHIFT                 (11U)
#define MSCM_ENEDC1_RT2APP_WIDTH                 (1U)
#define MSCM_ENEDC1_RT2APP(x)                    (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC1_RT2APP_SHIFT)) & MSCM_ENEDC1_RT2APP_MASK)

#define MSCM_ENEDC1_AIPS0_MASK                   (0x1000U)
#define MSCM_ENEDC1_AIPS0_SHIFT                  (12U)
#define MSCM_ENEDC1_AIPS0_WIDTH                  (1U)
#define MSCM_ENEDC1_AIPS0(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC1_AIPS0_SHIFT)) & MSCM_ENEDC1_AIPS0_MASK)

#define MSCM_ENEDC1_AIPS1_MASK                   (0x2000U)
#define MSCM_ENEDC1_AIPS1_SHIFT                  (13U)
#define MSCM_ENEDC1_AIPS1_WIDTH                  (1U)
#define MSCM_ENEDC1_AIPS1(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC1_AIPS1_SHIFT)) & MSCM_ENEDC1_AIPS1_MASK)

#define MSCM_ENEDC1_AIPS2_MASK                   (0x4000U)
#define MSCM_ENEDC1_AIPS2_SHIFT                  (14U)
#define MSCM_ENEDC1_AIPS2_WIDTH                  (1U)
#define MSCM_ENEDC1_AIPS2(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC1_AIPS2_SHIFT)) & MSCM_ENEDC1_AIPS2_MASK)

#define MSCM_ENEDC1_CM7_0_TCM_MASK               (0x8000U)
#define MSCM_ENEDC1_CM7_0_TCM_SHIFT              (15U)
#define MSCM_ENEDC1_CM7_0_TCM_WIDTH              (1U)
#define MSCM_ENEDC1_CM7_0_TCM(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC1_CM7_0_TCM_SHIFT)) & MSCM_ENEDC1_CM7_0_TCM_MASK)

#define MSCM_ENEDC1_CM7_1_TCM_MASK               (0x10000U)
#define MSCM_ENEDC1_CM7_1_TCM_SHIFT              (16U)
#define MSCM_ENEDC1_CM7_1_TCM_WIDTH              (1U)
#define MSCM_ENEDC1_CM7_1_TCM(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC1_CM7_1_TCM_SHIFT)) & MSCM_ENEDC1_CM7_1_TCM_MASK)

#define MSCM_ENEDC1_DEBUG_MASK                   (0x20000U)
#define MSCM_ENEDC1_DEBUG_SHIFT                  (17U)
#define MSCM_ENEDC1_DEBUG_WIDTH                  (1U)
#define MSCM_ENEDC1_DEBUG(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC1_DEBUG_SHIFT)) & MSCM_ENEDC1_DEBUG_MASK)
/*! @} */

/*! @name ENEDC2 - Address Check Enable */
/*! @{ */

#define MSCM_ENEDC2_PRAM0_MASK                   (0x1U)
#define MSCM_ENEDC2_PRAM0_SHIFT                  (0U)
#define MSCM_ENEDC2_PRAM0_WIDTH                  (1U)
#define MSCM_ENEDC2_PRAM0(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC2_PRAM0_SHIFT)) & MSCM_ENEDC2_PRAM0_MASK)

#define MSCM_ENEDC2_PRAM1_MASK                   (0x2U)
#define MSCM_ENEDC2_PRAM1_SHIFT                  (1U)
#define MSCM_ENEDC2_PRAM1_WIDTH                  (1U)
#define MSCM_ENEDC2_PRAM1(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC2_PRAM1_SHIFT)) & MSCM_ENEDC2_PRAM1_MASK)

#define MSCM_ENEDC2_PRAM2_MASK                   (0x4U)
#define MSCM_ENEDC2_PRAM2_SHIFT                  (2U)
#define MSCM_ENEDC2_PRAM2_WIDTH                  (1U)
#define MSCM_ENEDC2_PRAM2(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC2_PRAM2_SHIFT)) & MSCM_ENEDC2_PRAM2_MASK)

#define MSCM_ENEDC2_PRAM3_MASK                   (0x8U)
#define MSCM_ENEDC2_PRAM3_SHIFT                  (3U)
#define MSCM_ENEDC2_PRAM3_WIDTH                  (1U)
#define MSCM_ENEDC2_PRAM3(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC2_PRAM3_SHIFT)) & MSCM_ENEDC2_PRAM3_MASK)

#define MSCM_ENEDC2_PRAM4_MASK                   (0x10U)
#define MSCM_ENEDC2_PRAM4_SHIFT                  (4U)
#define MSCM_ENEDC2_PRAM4_WIDTH                  (1U)
#define MSCM_ENEDC2_PRAM4(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC2_PRAM4_SHIFT)) & MSCM_ENEDC2_PRAM4_MASK)

#define MSCM_ENEDC2_PRAM5_MASK                   (0x20U)
#define MSCM_ENEDC2_PRAM5_SHIFT                  (5U)
#define MSCM_ENEDC2_PRAM5_WIDTH                  (1U)
#define MSCM_ENEDC2_PRAM5(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC2_PRAM5_SHIFT)) & MSCM_ENEDC2_PRAM5_MASK)

#define MSCM_ENEDC2_PRAM6_MASK                   (0x40U)
#define MSCM_ENEDC2_PRAM6_SHIFT                  (6U)
#define MSCM_ENEDC2_PRAM6_WIDTH                  (1U)
#define MSCM_ENEDC2_PRAM6(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC2_PRAM6_SHIFT)) & MSCM_ENEDC2_PRAM6_MASK)

#define MSCM_ENEDC2_PRAM7_MASK                   (0x80U)
#define MSCM_ENEDC2_PRAM7_SHIFT                  (7U)
#define MSCM_ENEDC2_PRAM7_WIDTH                  (1U)
#define MSCM_ENEDC2_PRAM7(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC2_PRAM7_SHIFT)) & MSCM_ENEDC2_PRAM7_MASK)

#define MSCM_ENEDC2_PRAM8_MASK                   (0x100U)
#define MSCM_ENEDC2_PRAM8_SHIFT                  (8U)
#define MSCM_ENEDC2_PRAM8_WIDTH                  (1U)
#define MSCM_ENEDC2_PRAM8(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC2_PRAM8_SHIFT)) & MSCM_ENEDC2_PRAM8_MASK)

#define MSCM_ENEDC2_TCM_MASK                     (0x200U)
#define MSCM_ENEDC2_TCM_SHIFT                    (9U)
#define MSCM_ENEDC2_TCM_WIDTH                    (1U)
#define MSCM_ENEDC2_TCM(x)                       (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC2_TCM_SHIFT)) & MSCM_ENEDC2_TCM_MASK)

#define MSCM_ENEDC2_QSPI_MASK                    (0x400U)
#define MSCM_ENEDC2_QSPI_SHIFT                   (10U)
#define MSCM_ENEDC2_QSPI_WIDTH                   (1U)
#define MSCM_ENEDC2_QSPI(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC2_QSPI_SHIFT)) & MSCM_ENEDC2_QSPI_MASK)

#define MSCM_ENEDC2_RT2APP_MASK                  (0x800U)
#define MSCM_ENEDC2_RT2APP_SHIFT                 (11U)
#define MSCM_ENEDC2_RT2APP_WIDTH                 (1U)
#define MSCM_ENEDC2_RT2APP(x)                    (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC2_RT2APP_SHIFT)) & MSCM_ENEDC2_RT2APP_MASK)

#define MSCM_ENEDC2_AIPS0_MASK                   (0x1000U)
#define MSCM_ENEDC2_AIPS0_SHIFT                  (12U)
#define MSCM_ENEDC2_AIPS0_WIDTH                  (1U)
#define MSCM_ENEDC2_AIPS0(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC2_AIPS0_SHIFT)) & MSCM_ENEDC2_AIPS0_MASK)

#define MSCM_ENEDC2_AIPS1_MASK                   (0x2000U)
#define MSCM_ENEDC2_AIPS1_SHIFT                  (13U)
#define MSCM_ENEDC2_AIPS1_WIDTH                  (1U)
#define MSCM_ENEDC2_AIPS1(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC2_AIPS1_SHIFT)) & MSCM_ENEDC2_AIPS1_MASK)

#define MSCM_ENEDC2_AIPS2_MASK                   (0x4000U)
#define MSCM_ENEDC2_AIPS2_SHIFT                  (14U)
#define MSCM_ENEDC2_AIPS2_WIDTH                  (1U)
#define MSCM_ENEDC2_AIPS2(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC2_AIPS2_SHIFT)) & MSCM_ENEDC2_AIPS2_MASK)

#define MSCM_ENEDC2_CM7_0_TCM_MASK               (0x8000U)
#define MSCM_ENEDC2_CM7_0_TCM_SHIFT              (15U)
#define MSCM_ENEDC2_CM7_0_TCM_WIDTH              (1U)
#define MSCM_ENEDC2_CM7_0_TCM(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC2_CM7_0_TCM_SHIFT)) & MSCM_ENEDC2_CM7_0_TCM_MASK)

#define MSCM_ENEDC2_CM7_1_TCM_MASK               (0x10000U)
#define MSCM_ENEDC2_CM7_1_TCM_SHIFT              (16U)
#define MSCM_ENEDC2_CM7_1_TCM_WIDTH              (1U)
#define MSCM_ENEDC2_CM7_1_TCM(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC2_CM7_1_TCM_SHIFT)) & MSCM_ENEDC2_CM7_1_TCM_MASK)

#define MSCM_ENEDC2_DEBUG_MASK                   (0x20000U)
#define MSCM_ENEDC2_DEBUG_SHIFT                  (17U)
#define MSCM_ENEDC2_DEBUG_WIDTH                  (1U)
#define MSCM_ENEDC2_DEBUG(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC2_DEBUG_SHIFT)) & MSCM_ENEDC2_DEBUG_MASK)

#define MSCM_ENEDC2_PRAM_P0_MASK                 (0x40000U)
#define MSCM_ENEDC2_PRAM_P0_SHIFT                (18U)
#define MSCM_ENEDC2_PRAM_P0_WIDTH                (1U)
#define MSCM_ENEDC2_PRAM_P0(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC2_PRAM_P0_SHIFT)) & MSCM_ENEDC2_PRAM_P0_MASK)

#define MSCM_ENEDC2_PRAM_P1_MASK                 (0x80000U)
#define MSCM_ENEDC2_PRAM_P1_SHIFT                (19U)
#define MSCM_ENEDC2_PRAM_P1_WIDTH                (1U)
#define MSCM_ENEDC2_PRAM_P1(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC2_PRAM_P1_SHIFT)) & MSCM_ENEDC2_PRAM_P1_MASK)

#define MSCM_ENEDC2_PRAM_P2_MASK                 (0x100000U)
#define MSCM_ENEDC2_PRAM_P2_SHIFT                (20U)
#define MSCM_ENEDC2_PRAM_P2_WIDTH                (1U)
#define MSCM_ENEDC2_PRAM_P2(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC2_PRAM_P2_SHIFT)) & MSCM_ENEDC2_PRAM_P2_MASK)

#define MSCM_ENEDC2_PRAM_P3_MASK                 (0x200000U)
#define MSCM_ENEDC2_PRAM_P3_SHIFT                (21U)
#define MSCM_ENEDC2_PRAM_P3_WIDTH                (1U)
#define MSCM_ENEDC2_PRAM_P3(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC2_PRAM_P3_SHIFT)) & MSCM_ENEDC2_PRAM_P3_MASK)

#define MSCM_ENEDC2_DMA_S0_MASK                  (0x400000U)
#define MSCM_ENEDC2_DMA_S0_SHIFT                 (22U)
#define MSCM_ENEDC2_DMA_S0_WIDTH                 (1U)
#define MSCM_ENEDC2_DMA_S0(x)                    (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC2_DMA_S0_SHIFT)) & MSCM_ENEDC2_DMA_S0_MASK)

#define MSCM_ENEDC2_DMA_S1_MASK                  (0x800000U)
#define MSCM_ENEDC2_DMA_S1_SHIFT                 (23U)
#define MSCM_ENEDC2_DMA_S1_WIDTH                 (1U)
#define MSCM_ENEDC2_DMA_S1(x)                    (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC2_DMA_S1_SHIFT)) & MSCM_ENEDC2_DMA_S1_MASK)

#define MSCM_ENEDC2_MAIN_2_PERIPH_MASK           (0x1000000U)
#define MSCM_ENEDC2_MAIN_2_PERIPH_SHIFT          (24U)
#define MSCM_ENEDC2_MAIN_2_PERIPH_WIDTH          (1U)
#define MSCM_ENEDC2_MAIN_2_PERIPH(x)             (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC2_MAIN_2_PERIPH_SHIFT)) & MSCM_ENEDC2_MAIN_2_PERIPH_MASK)

#define MSCM_ENEDC2_PERIPH_2_MAIN_MASK           (0x2000000U)
#define MSCM_ENEDC2_PERIPH_2_MAIN_SHIFT          (25U)
#define MSCM_ENEDC2_PERIPH_2_MAIN_WIDTH          (1U)
#define MSCM_ENEDC2_PERIPH_2_MAIN(x)             (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC2_PERIPH_2_MAIN_SHIFT)) & MSCM_ENEDC2_PERIPH_2_MAIN_MASK)
/*! @} */

/*! @name IAHBCFGREG0 - AHB Gasket Configuration 0 */
/*! @{ */

#define MSCM_IAHBCFGREG0_ENET_DIS_WR_OPT_MASK    (0x1U)
#define MSCM_IAHBCFGREG0_ENET_DIS_WR_OPT_SHIFT   (0U)
#define MSCM_IAHBCFGREG0_ENET_DIS_WR_OPT_WIDTH   (1U)
#define MSCM_IAHBCFGREG0_ENET_DIS_WR_OPT(x)      (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG0_ENET_DIS_WR_OPT_SHIFT)) & MSCM_IAHBCFGREG0_ENET_DIS_WR_OPT_MASK)

#define MSCM_IAHBCFGREG0_DMA_AXBS_S0_DIS_WR_OPT_MASK (0x10U)
#define MSCM_IAHBCFGREG0_DMA_AXBS_S0_DIS_WR_OPT_SHIFT (4U)
#define MSCM_IAHBCFGREG0_DMA_AXBS_S0_DIS_WR_OPT_WIDTH (1U)
#define MSCM_IAHBCFGREG0_DMA_AXBS_S0_DIS_WR_OPT(x) (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG0_DMA_AXBS_S0_DIS_WR_OPT_SHIFT)) & MSCM_IAHBCFGREG0_DMA_AXBS_S0_DIS_WR_OPT_MASK)

#define MSCM_IAHBCFGREG0_DMA_AXBS_S1_DIS_WR_OPT_MASK (0x100U)
#define MSCM_IAHBCFGREG0_DMA_AXBS_S1_DIS_WR_OPT_SHIFT (8U)
#define MSCM_IAHBCFGREG0_DMA_AXBS_S1_DIS_WR_OPT_WIDTH (1U)
#define MSCM_IAHBCFGREG0_DMA_AXBS_S1_DIS_WR_OPT(x) (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG0_DMA_AXBS_S1_DIS_WR_OPT_SHIFT)) & MSCM_IAHBCFGREG0_DMA_AXBS_S1_DIS_WR_OPT_MASK)

#define MSCM_IAHBCFGREG0_HSE_DIS_WR_OPT_MASK     (0x1000U)
#define MSCM_IAHBCFGREG0_HSE_DIS_WR_OPT_SHIFT    (12U)
#define MSCM_IAHBCFGREG0_HSE_DIS_WR_OPT_WIDTH    (1U)
#define MSCM_IAHBCFGREG0_HSE_DIS_WR_OPT(x)       (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG0_HSE_DIS_WR_OPT_SHIFT)) & MSCM_IAHBCFGREG0_HSE_DIS_WR_OPT_MASK)

#define MSCM_IAHBCFGREG0_STAM_DIS_WR_OPT_MASK    (0x10000U)
#define MSCM_IAHBCFGREG0_STAM_DIS_WR_OPT_SHIFT   (16U)
#define MSCM_IAHBCFGREG0_STAM_DIS_WR_OPT_WIDTH   (1U)
#define MSCM_IAHBCFGREG0_STAM_DIS_WR_OPT(x)      (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG0_STAM_DIS_WR_OPT_SHIFT)) & MSCM_IAHBCFGREG0_STAM_DIS_WR_OPT_MASK)

#define MSCM_IAHBCFGREG0_DBG_MSTR_DIS_WR_OPT_MASK (0x100000U)
#define MSCM_IAHBCFGREG0_DBG_MSTR_DIS_WR_OPT_SHIFT (20U)
#define MSCM_IAHBCFGREG0_DBG_MSTR_DIS_WR_OPT_WIDTH (1U)
#define MSCM_IAHBCFGREG0_DBG_MSTR_DIS_WR_OPT(x)  (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG0_DBG_MSTR_DIS_WR_OPT_SHIFT)) & MSCM_IAHBCFGREG0_DBG_MSTR_DIS_WR_OPT_MASK)

#define MSCM_IAHBCFGREG0_TCM_DIS_WR_OPT_MASK     (0x1000000U)
#define MSCM_IAHBCFGREG0_TCM_DIS_WR_OPT_SHIFT    (24U)
#define MSCM_IAHBCFGREG0_TCM_DIS_WR_OPT_WIDTH    (1U)
#define MSCM_IAHBCFGREG0_TCM_DIS_WR_OPT(x)       (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG0_TCM_DIS_WR_OPT_SHIFT)) & MSCM_IAHBCFGREG0_TCM_DIS_WR_OPT_MASK)

#define MSCM_IAHBCFGREG0_PRAM0_DIS_WR_OPT_MASK   (0x10000000U)
#define MSCM_IAHBCFGREG0_PRAM0_DIS_WR_OPT_SHIFT  (28U)
#define MSCM_IAHBCFGREG0_PRAM0_DIS_WR_OPT_WIDTH  (1U)
#define MSCM_IAHBCFGREG0_PRAM0_DIS_WR_OPT(x)     (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG0_PRAM0_DIS_WR_OPT_SHIFT)) & MSCM_IAHBCFGREG0_PRAM0_DIS_WR_OPT_MASK)
/*! @} */

/*! @name IAHBCFGREG1 - AHB Gasket Configuration 1 */
/*! @{ */

#define MSCM_IAHBCFGREG1_PRAM1_DIS_WR_OPT_MASK   (0x1U)
#define MSCM_IAHBCFGREG1_PRAM1_DIS_WR_OPT_SHIFT  (0U)
#define MSCM_IAHBCFGREG1_PRAM1_DIS_WR_OPT_WIDTH  (1U)
#define MSCM_IAHBCFGREG1_PRAM1_DIS_WR_OPT(x)     (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG1_PRAM1_DIS_WR_OPT_SHIFT)) & MSCM_IAHBCFGREG1_PRAM1_DIS_WR_OPT_MASK)

#define MSCM_IAHBCFGREG1_PRAM2_DIS_WR_OPT_MASK   (0x10U)
#define MSCM_IAHBCFGREG1_PRAM2_DIS_WR_OPT_SHIFT  (4U)
#define MSCM_IAHBCFGREG1_PRAM2_DIS_WR_OPT_WIDTH  (1U)
#define MSCM_IAHBCFGREG1_PRAM2_DIS_WR_OPT(x)     (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG1_PRAM2_DIS_WR_OPT_SHIFT)) & MSCM_IAHBCFGREG1_PRAM2_DIS_WR_OPT_MASK)

#define MSCM_IAHBCFGREG1_PRAM3_DIS_WR_OPT_MASK   (0x100U)
#define MSCM_IAHBCFGREG1_PRAM3_DIS_WR_OPT_SHIFT  (8U)
#define MSCM_IAHBCFGREG1_PRAM3_DIS_WR_OPT_WIDTH  (1U)
#define MSCM_IAHBCFGREG1_PRAM3_DIS_WR_OPT(x)     (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG1_PRAM3_DIS_WR_OPT_SHIFT)) & MSCM_IAHBCFGREG1_PRAM3_DIS_WR_OPT_MASK)

#define MSCM_IAHBCFGREG1_DBG_SLV_DIS_WR_OPT_MASK (0x1000U)
#define MSCM_IAHBCFGREG1_DBG_SLV_DIS_WR_OPT_SHIFT (12U)
#define MSCM_IAHBCFGREG1_DBG_SLV_DIS_WR_OPT_WIDTH (1U)
#define MSCM_IAHBCFGREG1_DBG_SLV_DIS_WR_OPT(x)   (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG1_DBG_SLV_DIS_WR_OPT_SHIFT)) & MSCM_IAHBCFGREG1_DBG_SLV_DIS_WR_OPT_MASK)

#define MSCM_IAHBCFGREG1_QSPI_DIS_WR_OPT_MASK    (0x10000U)
#define MSCM_IAHBCFGREG1_QSPI_DIS_WR_OPT_SHIFT   (16U)
#define MSCM_IAHBCFGREG1_QSPI_DIS_WR_OPT_WIDTH   (1U)
#define MSCM_IAHBCFGREG1_QSPI_DIS_WR_OPT(x)      (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG1_QSPI_DIS_WR_OPT_SHIFT)) & MSCM_IAHBCFGREG1_QSPI_DIS_WR_OPT_MASK)

#define MSCM_IAHBCFGREG1_AIPS0_DIS_WR_OPT_MASK   (0x100000U)
#define MSCM_IAHBCFGREG1_AIPS0_DIS_WR_OPT_SHIFT  (20U)
#define MSCM_IAHBCFGREG1_AIPS0_DIS_WR_OPT_WIDTH  (1U)
#define MSCM_IAHBCFGREG1_AIPS0_DIS_WR_OPT(x)     (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG1_AIPS0_DIS_WR_OPT_SHIFT)) & MSCM_IAHBCFGREG1_AIPS0_DIS_WR_OPT_MASK)

#define MSCM_IAHBCFGREG1_AIPS1_DIS_WR_OPT_MASK   (0x1000000U)
#define MSCM_IAHBCFGREG1_AIPS1_DIS_WR_OPT_SHIFT  (24U)
#define MSCM_IAHBCFGREG1_AIPS1_DIS_WR_OPT_WIDTH  (1U)
#define MSCM_IAHBCFGREG1_AIPS1_DIS_WR_OPT(x)     (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG1_AIPS1_DIS_WR_OPT_SHIFT)) & MSCM_IAHBCFGREG1_AIPS1_DIS_WR_OPT_MASK)

#define MSCM_IAHBCFGREG1_AIPS2_DIS_WR_OPT_MASK   (0x10000000U)
#define MSCM_IAHBCFGREG1_AIPS2_DIS_WR_OPT_SHIFT  (28U)
#define MSCM_IAHBCFGREG1_AIPS2_DIS_WR_OPT_WIDTH  (1U)
#define MSCM_IAHBCFGREG1_AIPS2_DIS_WR_OPT(x)     (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG1_AIPS2_DIS_WR_OPT_SHIFT)) & MSCM_IAHBCFGREG1_AIPS2_DIS_WR_OPT_MASK)
/*! @} */

/*! @name IAHBCFGREG2 - AHB Gasket Configuration 2 */
/*! @{ */

#define MSCM_IAHBCFGREG2_M2P_AXBS_DIS_WR_OPT_MASK (0x1U)
#define MSCM_IAHBCFGREG2_M2P_AXBS_DIS_WR_OPT_SHIFT (0U)
#define MSCM_IAHBCFGREG2_M2P_AXBS_DIS_WR_OPT_WIDTH (1U)
#define MSCM_IAHBCFGREG2_M2P_AXBS_DIS_WR_OPT(x)  (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG2_M2P_AXBS_DIS_WR_OPT_SHIFT)) & MSCM_IAHBCFGREG2_M2P_AXBS_DIS_WR_OPT_MASK)

#define MSCM_IAHBCFGREG2_P2M_AXBS_DIS_WR_OPT_MASK (0x10U)
#define MSCM_IAHBCFGREG2_P2M_AXBS_DIS_WR_OPT_SHIFT (4U)
#define MSCM_IAHBCFGREG2_P2M_AXBS_DIS_WR_OPT_WIDTH (1U)
#define MSCM_IAHBCFGREG2_P2M_AXBS_DIS_WR_OPT(x)  (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG2_P2M_AXBS_DIS_WR_OPT_SHIFT)) & MSCM_IAHBCFGREG2_P2M_AXBS_DIS_WR_OPT_MASK)

#define MSCM_IAHBCFGREG2_CM7_0_AHBP_WR_DIS_OPT_MASK (0x100U)
#define MSCM_IAHBCFGREG2_CM7_0_AHBP_WR_DIS_OPT_SHIFT (8U)
#define MSCM_IAHBCFGREG2_CM7_0_AHBP_WR_DIS_OPT_WIDTH (1U)
#define MSCM_IAHBCFGREG2_CM7_0_AHBP_WR_DIS_OPT(x) (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG2_CM7_0_AHBP_WR_DIS_OPT_SHIFT)) & MSCM_IAHBCFGREG2_CM7_0_AHBP_WR_DIS_OPT_MASK)

#define MSCM_IAHBCFGREG2_CM7_1_AHBP_WR_DIS_OPT_MASK (0x1000U)
#define MSCM_IAHBCFGREG2_CM7_1_AHBP_WR_DIS_OPT_SHIFT (12U)
#define MSCM_IAHBCFGREG2_CM7_1_AHBP_WR_DIS_OPT_WIDTH (1U)
#define MSCM_IAHBCFGREG2_CM7_1_AHBP_WR_DIS_OPT(x) (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG2_CM7_1_AHBP_WR_DIS_OPT_SHIFT)) & MSCM_IAHBCFGREG2_CM7_1_AHBP_WR_DIS_OPT_MASK)
/*! @} */

/*! @name IRNMIC - Interrupt Router Non-Maskable Interrupt Control Register */
/*! @{ */

#define MSCM_IRNMIC_CP0_NMI_EN_MASK              (0x1U)
#define MSCM_IRNMIC_CP0_NMI_EN_SHIFT             (0U)
#define MSCM_IRNMIC_CP0_NMI_EN_WIDTH             (1U)
#define MSCM_IRNMIC_CP0_NMI_EN(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRNMIC_CP0_NMI_EN_SHIFT)) & MSCM_IRNMIC_CP0_NMI_EN_MASK)

#define MSCM_IRNMIC_CP1_NMI_EN_MASK              (0x2U)
#define MSCM_IRNMIC_CP1_NMI_EN_SHIFT             (1U)
#define MSCM_IRNMIC_CP1_NMI_EN_WIDTH             (1U)
#define MSCM_IRNMIC_CP1_NMI_EN(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRNMIC_CP1_NMI_EN_SHIFT)) & MSCM_IRNMIC_CP1_NMI_EN_MASK)

#define MSCM_IRNMIC_CP2_NMI0_EN_MASK             (0x4U)
#define MSCM_IRNMIC_CP2_NMI0_EN_SHIFT            (2U)
#define MSCM_IRNMIC_CP2_NMI0_EN_WIDTH            (1U)
#define MSCM_IRNMIC_CP2_NMI0_EN(x)               (((uint32_t)(((uint32_t)(x)) << MSCM_IRNMIC_CP2_NMI0_EN_SHIFT)) & MSCM_IRNMIC_CP2_NMI0_EN_MASK)
/*! @} */

/*! @name IRSPRC - Interrupt Router Shared Peripheral Routing Control */
/*! @{ */

#define MSCM_IRSPRC_M7_0_MASK                    (0x1U)
#define MSCM_IRSPRC_M7_0_SHIFT                   (0U)
#define MSCM_IRSPRC_M7_0_WIDTH                   (1U)
#define MSCM_IRSPRC_M7_0(x)                      (((uint16_t)(((uint16_t)(x)) << MSCM_IRSPRC_M7_0_SHIFT)) & MSCM_IRSPRC_M7_0_MASK)

#define MSCM_IRSPRC_M7_1_MASK                    (0x2U)
#define MSCM_IRSPRC_M7_1_SHIFT                   (1U)
#define MSCM_IRSPRC_M7_1_WIDTH                   (1U)
#define MSCM_IRSPRC_M7_1(x)                      (((uint16_t)(((uint16_t)(x)) << MSCM_IRSPRC_M7_1_SHIFT)) & MSCM_IRSPRC_M7_1_MASK)

#define MSCM_IRSPRC_CA53_MASK                    (0x4U)
#define MSCM_IRSPRC_CA53_SHIFT                   (2U)
#define MSCM_IRSPRC_CA53_WIDTH                   (1U)
#define MSCM_IRSPRC_CA53(x)                      (((uint16_t)(((uint16_t)(x)) << MSCM_IRSPRC_CA53_SHIFT)) & MSCM_IRSPRC_CA53_MASK)

#define MSCM_IRSPRC_BBE32_SPT_MASK               (0x8U)
#define MSCM_IRSPRC_BBE32_SPT_SHIFT              (3U)
#define MSCM_IRSPRC_BBE32_SPT_WIDTH              (1U)
#define MSCM_IRSPRC_BBE32_SPT(x)                 (((uint16_t)(((uint16_t)(x)) << MSCM_IRSPRC_BBE32_SPT_SHIFT)) & MSCM_IRSPRC_BBE32_SPT_MASK)

#define MSCM_IRSPRC_LOCK_MASK                    (0x8000U)
#define MSCM_IRSPRC_LOCK_SHIFT                   (15U)
#define MSCM_IRSPRC_LOCK_WIDTH                   (1U)
#define MSCM_IRSPRC_LOCK(x)                      (((uint16_t)(((uint16_t)(x)) << MSCM_IRSPRC_LOCK_SHIFT)) & MSCM_IRSPRC_LOCK_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group MSCM_Register_Masks */

/*!
 * @}
 */ /* end of group MSCM_Peripheral_Access_Layer */

#endif  /* #if !defined(S32R41_MSCM_H_) */
