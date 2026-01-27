/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.0.0
*   Build Version        : SAF85xx_SAF86xx_S32R41_RTD_2_0_0_P03_D2404_ASR_REL_4_7_REV_0000_20240405
*
*   Copyright 2021 - 2024 NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef CLOCK_IP_SPECIFIC_H
#define CLOCK_IP_SPECIFIC_H

/**
*   @file    Clock_Ip_Specific.h
*   @version    2.0.0
*
*   @brief   CLOCK IP specific header file.
*   @details CLOCK IP specific header file.

*   @addtogroup CLOCK_DRIVER Clock Ip Driver
*   @{
*/

#if defined(__cplusplus)
extern "C"{
#endif
/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Clock_Ip_Cfg_Defines.h"
#include "Mcal.h"

#if defined(CLOCK_IP_DERIVATIVE_001)
    #include "Clock_Ip_Derivative_001.h"
#endif
#if defined(CLOCK_IP_DERIVATIVE_002)
    #include "Clock_Ip_Derivative_002.h"
#endif
#if defined(CLOCK_IP_DERIVATIVE_003)
    #include "Clock_Ip_Derivative_003.h"
#endif


/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CLOCK_IP_SPECIFIC_VENDOR_ID                       43
#define CLOCK_IP_SPECIFIC_AR_RELEASE_MAJOR_VERSION        4
#define CLOCK_IP_SPECIFIC_AR_RELEASE_MINOR_VERSION        7
#define CLOCK_IP_SPECIFIC_AR_RELEASE_REVISION_VERSION     0
#define CLOCK_IP_SPECIFIC_SW_MAJOR_VERSION                2
#define CLOCK_IP_SPECIFIC_SW_MINOR_VERSION                0
#define CLOCK_IP_SPECIFIC_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Clock_Ip_Specific.h file and Clock_Ip_Cfg_Defines.h file have same versions */
#if (CLOCK_IP_SPECIFIC_VENDOR_ID  != CLOCK_IP_CFG_DEFINES_VENDOR_ID)
    #error "Clock_Ip_Specific.h and Clock_Ip_Cfg_Defines.h have different vendor IDs"
#endif

/* Check if Clock_Ip_Specific.h file and Clock_Ip_Cfg_Defines.h file are of the same Autosar version */
#if ((CLOCK_IP_SPECIFIC_AR_RELEASE_MAJOR_VERSION    != CLOCK_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_SPECIFIC_AR_RELEASE_MINOR_VERSION    != CLOCK_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_SPECIFIC_AR_RELEASE_REVISION_VERSION != CLOCK_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Clock_Ip_Specific.h and Clock_Ip_Cfg_Defines.h are different"
#endif

/* Check if Clock_Ip_Specific.h file and Clock_Ip_Cfg_Defines.h file are of the same Software version */
#if ((CLOCK_IP_SPECIFIC_SW_MAJOR_VERSION != CLOCK_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (CLOCK_IP_SPECIFIC_SW_MINOR_VERSION != CLOCK_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (CLOCK_IP_SPECIFIC_SW_PATCH_VERSION != CLOCK_IP_CFG_DEFINES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Clock_Ip_Specific.h and Clock_Ip_Cfg_Defines.h are different"
#endif

#if defined(CLOCK_IP_DERIVATIVE_001)
    /* Check if Clock_Ip_Specific.h file and Clock_Ip_Derivative_001.h file have same versions */
    #if (CLOCK_IP_SPECIFIC_VENDOR_ID  != CLOCK_IP_DERIVATIVE_001_VENDOR_ID)
        #error "Clock_Ip_Specific.h and Clock_Ip_Derivative_001.h have different vendor IDs"
    #endif

    /* Check if Clock_Ip_Specific.h file and Clock_Ip_Derivative_001.h file are of the same Autosar version */
    #if ((CLOCK_IP_SPECIFIC_AR_RELEASE_MAJOR_VERSION    != CLOCK_IP_DERIVATIVE_001_AR_RELEASE_MAJOR_VERSION) || \
         (CLOCK_IP_SPECIFIC_AR_RELEASE_MINOR_VERSION    != CLOCK_IP_DERIVATIVE_001_AR_RELEASE_MINOR_VERSION) || \
         (CLOCK_IP_SPECIFIC_AR_RELEASE_REVISION_VERSION != CLOCK_IP_DERIVATIVE_001_AR_RELEASE_REVISION_VERSION))
        #error "AutoSar Version Numbers of Clock_Ip_Specific.h and Clock_Ip_Derivative_001.h are different"
    #endif

    /* Check if Clock_Ip_Specific.h file and Clock_Ip_Derivative_001.h file are of the same Software version */
    #if ((CLOCK_IP_SPECIFIC_SW_MAJOR_VERSION != CLOCK_IP_DERIVATIVE_001_SW_MAJOR_VERSION) || \
         (CLOCK_IP_SPECIFIC_SW_MINOR_VERSION != CLOCK_IP_DERIVATIVE_001_SW_MINOR_VERSION) || \
         (CLOCK_IP_SPECIFIC_SW_PATCH_VERSION != CLOCK_IP_DERIVATIVE_001_SW_PATCH_VERSION))
        #error "Software Version Numbers of Clock_Ip_Specific.h and Clock_Ip_Derivative_001.h are different"
    #endif
#endif

#if defined(CLOCK_IP_DERIVATIVE_002)
    /* Check if Clock_Ip_Specific.h file and Clock_Ip_Derivative_002.h file have same versions */
    #if (CLOCK_IP_SPECIFIC_VENDOR_ID  != CLOCK_IP_DERIVATIVE_002_VENDOR_ID)
        #error "Clock_Ip_Specific.h and Clock_Ip_Derivative_002.h have different vendor IDs"
    #endif

    /* Check if Clock_Ip_Specific.h file and Clock_Ip_Derivative_002.h file are of the same Autosar version */
    #if ((CLOCK_IP_SPECIFIC_AR_RELEASE_MAJOR_VERSION    != CLOCK_IP_DERIVATIVE_002_AR_RELEASE_MAJOR_VERSION) || \
         (CLOCK_IP_SPECIFIC_AR_RELEASE_MINOR_VERSION    != CLOCK_IP_DERIVATIVE_002_AR_RELEASE_MINOR_VERSION) || \
         (CLOCK_IP_SPECIFIC_AR_RELEASE_REVISION_VERSION != CLOCK_IP_DERIVATIVE_002_AR_RELEASE_REVISION_VERSION))
        #error "AutoSar Version Numbers of Clock_Ip_Specific.h and Clock_Ip_Derivative_002.h are different"
    #endif

    /* Check if Clock_Ip_Specific.h file and Clock_Ip_Derivative_002.h file are of the same Software version */
    #if ((CLOCK_IP_SPECIFIC_SW_MAJOR_VERSION != CLOCK_IP_DERIVATIVE_002_SW_MAJOR_VERSION) || \
         (CLOCK_IP_SPECIFIC_SW_MINOR_VERSION != CLOCK_IP_DERIVATIVE_002_SW_MINOR_VERSION) || \
         (CLOCK_IP_SPECIFIC_SW_PATCH_VERSION != CLOCK_IP_DERIVATIVE_002_SW_PATCH_VERSION))
        #error "Software Version Numbers of Clock_Ip_Specific.h and Clock_Ip_Derivative_002.h are different"
    #endif
#endif

#if defined(CLOCK_IP_DERIVATIVE_003)
    /* Check if Clock_Ip_Specific.h file and Clock_Ip_Derivative_003.h file have same versions */
    #if (CLOCK_IP_SPECIFIC_VENDOR_ID  != CLOCK_IP_DERIVATIVE_003_VENDOR_ID)
        #error "Clock_Ip_Specific.h and Clock_Ip_Derivative_003.h have different vendor IDs"
    #endif

    /* Check if Clock_Ip_Specific.h file and Clock_Ip_Derivative_003.h file are of the same Autosar version */
    #if ((CLOCK_IP_SPECIFIC_AR_RELEASE_MAJOR_VERSION    != CLOCK_IP_DERIVATIVE_003_AR_RELEASE_MAJOR_VERSION) || \
         (CLOCK_IP_SPECIFIC_AR_RELEASE_MINOR_VERSION    != CLOCK_IP_DERIVATIVE_003_AR_RELEASE_MINOR_VERSION) || \
         (CLOCK_IP_SPECIFIC_AR_RELEASE_REVISION_VERSION != CLOCK_IP_DERIVATIVE_003_AR_RELEASE_REVISION_VERSION))
        #error "AutoSar Version Numbers of Clock_Ip_Specific.h and Clock_Ip_Derivative_003.h are different"
    #endif

    /* Check if Clock_Ip_Specific.h file and Clock_Ip_Derivative_003.h file are of the same Software version */
    #if ((CLOCK_IP_SPECIFIC_SW_MAJOR_VERSION != CLOCK_IP_DERIVATIVE_003_SW_MAJOR_VERSION) || \
         (CLOCK_IP_SPECIFIC_SW_MINOR_VERSION != CLOCK_IP_DERIVATIVE_003_SW_MINOR_VERSION) || \
         (CLOCK_IP_SPECIFIC_SW_PATCH_VERSION != CLOCK_IP_DERIVATIVE_003_SW_PATCH_VERSION))
        #error "Software Version Numbers of Clock_Ip_Specific.h and Clock_Ip_Derivative_003.h are different"
    #endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Clock_Ip_Specific.h file and Mcal.h file are of the same Autosar version */
#if ((CLOCK_IP_SPECIFIC_AR_RELEASE_MAJOR_VERSION    != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_SPECIFIC_AR_RELEASE_MINOR_VERSION    != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Clock_Ip_Specific.h and Mcal.h are different"
#endif
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

#define CLOCK_IP_ALL_CALLBACKS_COUNT                                                   11U

#if defined(CLOCK_IP_HAS_AURORAPLL_CLK)
#define CLOCK_IP_NUMBER_OF_HARDWARE_PLL                                                3U
#define CLOCK_IP_NUMBER_OF_HARDWARE_DFS                                                0U
#define CLOCK_IP_PLL_INSTANCES_ARRAY_SIZE                                              2U
#define CLOCK_IP_DFS_INSTANCES_ARRAY_SIZE                                              1U
#else
#define CLOCK_IP_NUMBER_OF_HARDWARE_PLL                                                2U
#define CLOCK_IP_NUMBER_OF_HARDWARE_DFS                                                2U
#define CLOCK_IP_PLL_INSTANCES_ARRAY_SIZE                                              2U
#define CLOCK_IP_DFS_INSTANCES_ARRAY_SIZE                                              1U
#endif

#define CLOCK_IP_MC_CGM_INSTANCES_COUNT      4U
#define CLOCK_IP_MC_CGM_MUXS_COUNT           9U
#define CLOCK_IP_XOSC_INSTANCES_ARRAY_SIZE   1U
#define CLOCK_IP_CMU_INSTANCES_ARRAY_SIZE    26U
#define CLOCK_IP_MC_ME_PARTITIONS_COUNT      2U
#define CLOCK_IP_CMU_INFO_SIZE               32U
#define CLOCK_IP_GATE_INFO_SIZE              3U
#define CLOCK_IP_EXTENSIONS_SIZE             35U

#define CLOCK_IP_MC_CGM_MUX_MUX_DIV_COUNT    2u
#define CLOCK_IP_MC_CGM_PCFS_COUNT           64u
#define CLOCK_IP_PRTN_COFB_NO                4u

#define MC_CGM_MUX_DC_DE_MASK                MC_CGM_0_MUX_1_DC_0_DE_MASK
#define MC_CGM_MUX_DC_DE_SHIFT               MC_CGM_0_MUX_1_DC_0_DE_SHIFT
#define MC_CGM_MUX_CSC_SAFE_SW_MASK          MC_CGM_0_MUX_0_CSS_SAFE_SW_MASK
#define MC_CGM_MUX_CSC_CLK_SW_MASK           MC_CGM_0_MUX_0_CSC_CLK_SW_MASK
#define MC_CGM_MUX_CSC_RAMPUP_MASK           MC_CGM_MUX_1_CSC_RAMPUP_MASK
#define MC_CGM_MUX_CSC_RAMPDOWN_MASK         MC_CGM_MUX_1_CSC_RAMPDOWN_MASK
#define MC_CGM_MUX_CSS_SWIP_MASK             MC_CGM_MUX_1_CSS_SWIP_MASK
#define MC_CGM_MUX_CSS_SWIP_IN_PROGRESS      MC_CGM_MUX_1_CSS_SWIP_MASK
#define MC_CGM_MUX_CSS_SWTRG_MASK            MC_CGM_MUX_1_CSS_SWTRG_MASK
#define MC_CGM_MUX_CSS_SWTRG_SHIFT           MC_CGM_MUX_1_CSS_SWTRG_SHIFT
#define CLOCK_IP_MC_CGM_MUX_CSS_SWTRG_SUCCEEDED       1U
#define MC_CGM_MUX_CSS_CLK_SW_MASK           MC_CGM_0_MUX_0_CSS_CLK_SW_MASK
#define CLOCK_IP_MC_CGM_MUX_CSS_CLK_SW_NOT_REQUESTED  0U
#define MC_CGM_MUX_CSC_CG_MASK               MC_CGM_0_MUX_1_CSC_CG_MASK
#define MC_CGM_MUX_CSC_FCG_MASK              MC_CGM_0_MUX_1_CSC_FCG_MASK
#define MC_CGM_MUX_CSS_CS_MASK               MC_CGM_0_MUX_1_CSS_CS_MASK
#define MC_CGM_MUX_CSS_CS_TRANSPARENT        MC_CGM_0_MUX_1_CSS_CS_MASK
#define MC_CGM_MUX_DIV_UPD_STAT_DIV_STAT_MASK MC_CGM_MUX_0_DIV_UPD_STAT_DIV_STAT_MASK
#define MC_CGM_MUX_DIV_UPD_STAT_DIV_STAT_PENDING MC_CGM_MUX_0_DIV_UPD_STAT_DIV_STAT_MASK
#define MC_CGM_PCFS_DIVC_INIT(x)             MC_CGM_PCFS_DIVC4_INIT(x)
#define MC_CGM_PCFS_DIVC_RATE(x)             MC_CGM_PCFS_DIVC4_RATE(x)
#define MC_CGM_PCFS_DIVE_DIVE(x)             MC_CGM_PCFS_DIVE4_DIVE(x)
#define MC_CGM_PCFS_DIVS_DIVS(x)             MC_CGM_PCFS_DIVS4_DIVS(x)
#define DFS_PORTSR_PORTSTAT_MASK             (DFS_PORTSR_PORTSTAT1_MASK | DFS_PORTSR_PORTSTAT0_MASK)
#define DFS_PORTSR_PORTSTAT_SHIFT            (DFS_PORTSR_PORTSTAT0_SHIFT)
#define DFS_PORTSR_PORTSTAT(x)               (((uint32)(((uint32)(x)) << DFS_PORTSR_PORTSTAT_SHIFT)) & DFS_PORTSR_PORTSTAT_MASK)

#define CLOCK_IP_CMU_FREQUENCY_CHECK_ENABLED          CMU_FC_GCR_FCE_MASK
#define CLOCK_IP_CMU_FREQUENCY_CHECK_STOPPED          0U
#define CLOCK_IP_CMU_ISR_MASK                         3U

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


typedef struct {
  uint32 CSC;
  const  uint32 CSS;
  uint32 Divider[CLOCK_IP_MC_CGM_MUX_MUX_DIV_COUNT];
  uint8 RESERVED_0[36];
  uint32 MUX_DIV_TRIG_CTRL;               /**< Clock Mux 0 Divider trigger Control Register, offset: 0x334 */
  uint32 MUX_DIV_TRIG;                    /**< Clock Mux 0 Divider trigger Register, offset: 0x338 */
  const  uint32 MUX_DIV_UPD_STAT;

}volatile Clock_Ip_CgmMuxType;

typedef struct {

    uint32 PCFS_SDUR;                           /**< PCFS Step Duration, offset: 0x0 */
    struct {                                    /* offset: 0x4, array step: 0xC */
      uint32 DIVC;                              /**< PCFS Divider Change 12 Register, array offset: 0x4, array step: 0xC */
      uint32 DIVE;                              /**< PCFS Divider End 12 Register, array offset: 0x8, array step: 0xC */
      uint32 DIVS;                              /**< PCFS Divider Start 12 Register, array offset: 0xC, array step: 0xC */
    } PCFS[CLOCK_IP_MC_CGM_PCFS_COUNT];

}Clock_Ip_CgmPcfsType;

typedef struct {
    volatile uint32 PRTN_COFB_CLKEN[CLOCK_IP_PRTN_COFB_NO];
}Clock_Ip_McmePartitionSetType;

typedef struct {
    volatile const  uint32 PRTN_COFB_STAT[CLOCK_IP_PRTN_COFB_NO];
}Clock_Ip_McmePartitionGetType;

typedef struct {
    volatile uint32 PRTN_PCONF;
    volatile uint32 PRTN_PUPD;
    volatile const  uint32 PRTN_STAT;
}Clock_Ip_McmePartitionTriggerType;

/** XOSC - Register Layout Typedef */
typedef struct {
    uint32 CTRL;                        /**< XOSC Control Register, offset: 0x0 */
    const  uint32 STAT;                        /**< Oscillator Status Register, offset: 0x4 */
}volatile Clock_Ip_ExtOSCType;

/** CMU - Register Layout Typedef */
typedef struct {
    uint32 GCR;                               /**< Global Configuration Register, offset: 0x0 */
    uint32 RCCR;                              /**< Reference Count Configuration Register, offset: 0x4 */
    uint32 HTCR;                              /**< High Threshold Configuration Register, offset: 0x8 */
    uint32 LTCR;                              /**< Low Threshold Configuration Register, offset: 0xC */
    volatile uint32 SR;                                /**< Status Register, offset: 0x10 */
    uint32 IER;                               /**< Interrupt Enable Register, offset: 0x14 */

}Clock_Ip_ClockMonitorType;

#if (defined(IP_ATP) || defined(IP_ATP_PLL))
/** ATP - Register Layout Typedef */
typedef struct {
  volatile uint32 PLLCR;                             /**< PLL Control Register, offset: 0x0 */
  volatile const  uint32 PLLSR;                             /**< PLL Status Register, offset: 0x4 */
  uint8_t RESERVED_0[24];
  volatile uint32 CLKMUX;                            /**< PLL Clock Multiplexer, offset: 0x20 */
  volatile uint32 PLLODIV_0;                         /**< PLL Output Divider 0, offset: 0x24 */
  volatile uint32 PLLODIV_1;                         /**< PLL Output Divider 1, offset: 0x28 */
  volatile uint32 PLLODIV_2;                         /**< PLL Output Divider 2, offset: 0x2C */
  uint8_t RESERVED_1[12];
  volatile uint32 D_G_CTR_ACQ;                       /**< DCO_GAIN_CONTROL_ACQ, offset: 0x3C */
  volatile uint32 D_G_CTR_TR;                        /**< DCO_GAIN_CONTROL_TR, offset: 0x40 */
  uint8_t RESERVED_2[8];
  volatile uint32 TR_T_VAL;                          /**< TR_TIMER_VALUE Register, offset: 0x4C */
  volatile uint32 L_FILT_M;                          /**< LOOP_FILTER_MISC, offset: 0x50 */
  volatile uint32 LP_FLTR;                           /**< LOOPFILTER, offset: 0x54 */
  volatile uint32 DC_COEF;                           /**< DC_COEF Register, offset: 0x58 */
  volatile uint32 L_D_CTR_1;                         /**< LOCK_DET_CONTROL_1 Register, offset: 0x5C */
  volatile uint32 L_D_CT_2;                          /**< LOCK_DET_CONTROL_2 Register, offset: 0x60 */
  volatile uint32 F_D_CTRL;                          /**< ATP_F_D_CTRL, offset: 0x64 */
  volatile uint32 FNPDIV_C;                          /**< FCW_NDIV_PDIV_CONFIG, offset: 0x68 */
  volatile uint32 EN_CLKS;                           /**< ENABLE_CLOCKS, offset: 0x6C */
  volatile uint32 DCO_CTRL;                          /**< DCO_CTRL Register, offset: 0x70 */
  volatile uint32 DPLL_T_C;                          /**< DPLL_TEST_CONFIG Register, offset: 0x74 */
  uint8_t RESERVED_4[12];
  volatile uint32 ATB_CTRL;                          /**< ATB_CTRL Register, offset: 0x84 */
  volatile uint32 D_STROBE;                          /**< DATA STROBE, offset: 0x88 */
  uint8_t RESERVED_5[64];
  volatile const  uint32 LOCK;                       /**< LOCK Register, offset: 0xCC */
  uint8_t RESERVED_6[560];
  volatile const  uint32 ALS;                        /**< AL Status, offset: 0x300 */
  uint8_t RESERVED_7[4];
  volatile uint32 ALGC;                              /**< AL General Control, offset: 0x308 */
  volatile uint32 ALTC;                              /**< AL Training Control, offset: 0x30C */
  uint8_t RESERVED_8[304];
  volatile uint32 LVDSTX;                            /**< LVDS TX IO Configuration, offset: 0x440 */
  volatile uint32 LVDSRX;                            /**< LVDS RX IO Configuration, offset: 0x444 */
  volatile uint32 LVDSTXOBE;                         /**< LVDS TX OBE Configuration, offset: 0x448 */
  uint8_t RESERVED_9[52];
  volatile uint32 CIAC;                              /**< CIA Control, offset: 0x480 */
  uint8_t RESERVED_10[4];
  volatile uint32 ATPE;                              /**< Aurora Trace Port Enable, offset: 0x488 */
  uint8_t RESERVED_11[2676];
  volatile const  uint32 ITCTRL;                            /**< Integration Mode Control, offset: 0xF00 */
  uint8_t RESERVED_12[156];
  volatile const  uint32 CLAIMSET;                          /**< Claim Tag Set, offset: 0xFA0 */
  volatile const  uint32 CLAIMCLR;                          /**< Claim Tag Clear, offset: 0xFA4 */
  volatile const  uint32 DEVAFF0;                           /**< Device Affinity 0, offset: 0xFA8 */
  volatile const  uint32 DEVAFF1;                           /**< Device Affinity 1, offset: 0xFAC */
  volatile uint32 LAR;                               /**< Lock Access Register, offset: 0xFB0 */
  volatile const  uint32 LSR;                               /**< Lock Status Register, offset: 0xFB4 */
  volatile const  uint32 AUTHSTATUS;                        /**< Authentication Status, offset: 0xFB8 */
  volatile const  uint32 DEVARCH;                           /**< Device Architecture, offset: 0xFBC */
  volatile const  uint32 DEVID2;                            /**< Device Configuration 2, offset: 0xFC0 */
  volatile const  uint32 DEVID1;                            /**< Device Configuration 1, offset: 0xFC4 */
  volatile const  uint32 DEVID;                             /**< Device Configuration, offset: 0xFC8 */
  volatile const  uint32 DEVTYPE;                           /**< Device Type Identifier, offset: 0xFCC */
  volatile const  uint32 PIDR4;                             /**< Peripheral Identification Register 4, offset: 0xFD0 */
  uint8_t RESERVED_13[12];
  volatile const  uint32 PIDR0;                             /**< Peripheral Identification Register 0, offset: 0xFE0 */
  volatile const  uint32 PIDR1;                             /**< Peripheral Identification Register 1, offset: 0xFE4 */
  volatile const  uint32 PIDR2;                             /**< Peripheral Identification Register 2, offset: 0xFE8 */
  volatile const  uint32 PIDR3;                             /**< Peripheral Identification Register 3, offset: 0xFEC */
  volatile const  uint32 CIDR0;                             /**< Component Identification Register 0, offset: 0xFF0 */
  volatile const  uint32 CIDR1;                             /**< Component Identification Register 1, offset: 0xFF4 */
  volatile const  uint32 CIDR2;                             /**< Component Identification Register 2, offset: 0xFF8 */
  volatile const  uint32 CIDR3;                             /**< Component Identification Register 3, offset: 0xFFC */
}Clock_Ip_ATPType;
#endif

typedef struct{

    Clock_Ip_NameType Name;       /* Name of the clock that can be monitored/supports cmu (clock monitor) */
    Clock_Ip_NameType Reference;  /* Name of the reference clock */
    Clock_Ip_NameType Bus;        /* Name of the bus clock */

    Clock_Ip_ClockMonitorType* CmuInstance;

}Clock_Ip_CmuInfoType;
typedef struct
{
    uint8 PartitionValue;
    uint8 ColectionValue;
    uint8 RequestValueShift;
    uint32 RequestValueMask;

}Clock_Ip_GateInfoType;

typedef struct
{
    uint32 SelectorValueMask;
    uint32 SelectorValueShift;
    uint32 DividerValueMask;
    uint32 DividerValueShift;

}Clock_Ip_ClockExtensionType;

typedef struct
{
    PLLDIG_Type* PllInstance;
    uint8 DivsNo;

}Clock_Ip_PllType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/* Clock start constant section data */
#define MCU_START_SEC_CONST_UNSPECIFIED

#include "Mcu_MemMap.h"

extern Clock_Ip_CgmMuxType* const Clock_Ip_apxCgm[CLOCK_IP_MC_CGM_INSTANCES_COUNT][CLOCK_IP_MC_CGM_MUXS_COUNT];
extern volatile Clock_Ip_CgmPcfsType* const Clock_Ip_apxCgmPcfs[CLOCK_IP_MC_CGM_INSTANCES_COUNT];
extern Clock_Ip_ExtOSCType* const Clock_Ip_apxXosc[CLOCK_IP_XOSC_INSTANCES_ARRAY_SIZE];
extern Clock_Ip_PllType const Clock_Ip_apxPll[CLOCK_IP_PLL_INSTANCES_ARRAY_SIZE];
#if CLOCK_IP_NUMBER_OF_HARDWARE_DFS > 0
extern DFS_Type* const Clock_Ip_apxDfs[CLOCK_IP_DFS_INSTANCES_ARRAY_SIZE];
#endif
extern Clock_Ip_ClockMonitorType * const Clock_Ip_apxCmu[CLOCK_IP_CMU_INSTANCES_ARRAY_SIZE];
extern Clock_Ip_NameType const Clock_Ip_aeCmuNames[CLOCK_IP_CMU_INSTANCES_ARRAY_SIZE];

extern volatile Clock_Ip_McmePartitionSetType* const Clock_Ip_apxMcMeSetPartitions[CLOCK_IP_MC_ME_PARTITIONS_COUNT];
extern volatile const Clock_Ip_McmePartitionGetType* const Clock_Ip_apxMcMeGetPartitions[CLOCK_IP_MC_ME_PARTITIONS_COUNT];
extern volatile Clock_Ip_McmePartitionTriggerType* const Clock_Ip_apxMcMeTriggerPartitions[CLOCK_IP_MC_ME_PARTITIONS_COUNT];
#if (defined(IP_ATP) || defined(IP_ATP_PLL))
extern Clock_Ip_ATPType* const Clock_Ip_apxAurora; 
#endif
#if CLOCK_IP_NUMBER_OF_HARDWARE_DFS > 0
extern const Clock_Ip_NameType Clock_Ip_aeHwDfsName[CLOCK_IP_NUMBER_OF_HARDWARE_DFS];
#endif
extern const Clock_Ip_CmuInfoType Clock_Ip_axCmuInfo[CLOCK_IP_CMU_INFO_SIZE];

extern const Clock_Ip_GateInfoType Clock_Ip_axGateInfo[CLOCK_IP_GATE_INFO_SIZE];

extern const Clock_Ip_ClockExtensionType Clock_Ip_axFeatureExtensions[CLOCK_IP_EXTENSIONS_SIZE];

/* Clock stop constant section data */
#define MCU_STOP_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

/* Clock start constant section data */
#define MCU_START_SEC_CONST_8
#include "Mcu_MemMap.h"

extern const uint8 Clock_Ip_au8SoftwareMuxResetValue[CLOCK_IP_FEATURE_NAMES_NO];

/* Clock stop constant section data */
#define MCU_STOP_SEC_CONST_8
#include "Mcu_MemMap.h"

/* Clock start constant section data */
#define MCU_START_SEC_CONST_16
#include "Mcu_MemMap.h"

extern const uint16 Clock_Ip_au16SelectorEntryHardwareValue[CLOCK_IP_FEATURE_PRODUCERS_NO];

/* Clock stop constant section data */
#define MCU_STOP_SEC_CONST_16
#include "Mcu_MemMap.h"



/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

/* Clock start section code */
#define MCU_START_SEC_CODE

#include "Mcu_MemMap.h"

#if (defined(CLOCK_IP_ENABLE_USER_MODE_SUPPORT))
  #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
void Clock_Ip_SpecificSetUserAccessAllowed(void);
  #endif
#endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
void Clock_Ip_McMeEnterKey(void);

/* Clock stop section code */
#define MCU_STOP_SEC_CODE

#include "Mcu_MemMap.h"

#if defined(__cplusplus)
}
#endif

/** @} */

#endif /* CLOCK_IP_SPECIFIC_H */

