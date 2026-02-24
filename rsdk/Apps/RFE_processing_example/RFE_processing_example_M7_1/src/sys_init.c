/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 1.0.0
*   Build Version        : S32R41_RTD_1_0_0_D2305_ASR_REL_4_7_REV_0000_20230510
*
*   Copyright 2021 - 2023 NXP Semiconductors
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
*/
/*==================================================================================================
*   @file    sys_init.c
*   @version 1.0.0
*
*   @brief   AUTOSAR Platform - RTD auxiliary APIs used for RTD testing
*   @details RTD auxiliary APIs used for RTD testing
*            This file contains sample code only. It is not part of the production code deliverables
==================================================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "sys_init.h"
#include "Mcal.h"
#include "core.h"
#ifdef S32R41
#include "S32R41_FXOSC.h"
#include "S32R41_PLLDIG.h"
#include "S32R41_DFS.h"
#include "S32R41_MC_CGM.h"
#include "S32R41_MC_CGM_0.h"
#include "S32R41_MC_CGM_2.h"
#include "S32R41_MC_ME.h"
#else
#include "SAF85XX_FXOSC.h"
#include "SAF85XX_PLLDIG.h"
#include "SAF85XX_MC_CGM.h"
#include "SAF85XX_MC_CGM_0.h"
#include "SAF85XX_ATP.h"
#include "SAF85XX_SRC.h"
#include "SAF85XX_MC_ME.h"
#endif

/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/
#ifdef S32R41
#define SYS_USE_FXOSC   (STD_ON)
#define SYS_USE_FIRC    (STD_OFF)
#ifdef T32_TRACE_APP
/* Trace app reduce a half of PLL clock frequency for stable measurement */
#define CORE_PLLDIG_PLLDV_MFI_VAL (30U) /* FXOSC = 40MHz * 30 = 1200MHz VCO frequency */
#define PERIPH_PLLDIG_PLLDV_MFI_VAL (25U) /* FXOSC = 40MHz * 25 = 1000MHz VCO frequency */
#else
#define CORE_PLLDIG_PLLDV_MFI_VAL (60U) /* FXOSC = 40MHz * 60 = 2400MHz VCO frequency */
#define PERIPH_PLLDIG_PLLDV_MFI_VAL (50U) /* FXOSC = 40MHz * 50 = 2000MHz VCO frequency */
#endif
#else
#ifdef RFE_FW_ENABLED
#define SYS_USE_FIRC_MUXED    (STD_OFF)
#define SYS_USE_RFE_PLL       (STD_ON)
#else
#define SYS_USE_FIRC_MUXED    (STD_ON)
#define SYS_USE_RFE_PLL       (STD_OFF)
#endif
#define SYS_USE_AURORA_PLL    (STD_OFF)
#define FIRC_MUXED_USE_FIRC   (STD_ON)
#define FIRC_MUXED_USE_FXOSC  (STD_OFF)
#define FIRC_UNTRIMMED_30MHZ  (0)   /* The untrimmed FIRC is ~30 MHz as opposed to 48 MHz */
#define ATP_PLL_FREQ_625      (STD_OFF)
#define ATP_PLL_FREQ_125      (STD_OFF)
#define ATP_PLL_FREQ_640      (STD_ON)

#define ATP_ATB_CTRL     *(uint32_t *)0x51033084
#define ATP_FXOSC_CLK_REF    1
#define ATP_FIRC_CLK_REF     2
#define ATP_PLLO_0_DIV_OFFSET   17
#define ATP_PLLO_1_2_DIV_OFFSET 23
#endif

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/
/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"

#define SWITCH_CORE_FIRC_ERRNO         0x1
#define SWITCH_PERIPHERAL_FIRC_ERRNO   0x2
#define INIT_FXOSC_ERRNO               0x4
#define INIT_CORE_PLL_ERRNO            0x8
#define INIT_PERIPHERAL_PLL_ERRNO      0x10
#ifdef S32R41
#define INIT_PERIPHERAL_DFS_ERRNO      0x20
#endif
#define INIT_MC_CGM_0_ERRNO            0x40
#define INIT_MC_CGM_1_ERRNO            0x80
#ifdef S32R41
#define INIT_MC_CGM_2_ERRNO            0x100
#endif
#define INIT_MC_CGM_3_ERRNO            0x200
#ifdef SAF85
#define INIT_MC_CGM_FIRC_ERRNO         0x400
#define INIT_AURORA_PLL_ERRNO          0x800
#endif
#define INIT_COFB_ERRNO                0x1000

static int Switch_Core_FIRC(void);
static int Switch_Peripheral_FIRC(void);
static int Init_FXOSC(void);
static int Init_Core_PLL(void);
static int Init_Peripheral_PLL(void);
#ifdef S32R41
static int Init_Peripheral_DFS(void);
#endif
static int Init_MC_CGM(void);
static int Init_MC_CGM_0(void);
static int Init_MC_CGM_1(void);
#ifdef S32R41
static int Init_MC_CGM_2(void);
#endif
static int Init_MC_CGM_3(void);
#ifdef SAF85
static int Init_FIRC_MUXED(void);
#if (SYS_USE_AURORA_PLL == STD_ON)
static int Init_AURORA_PLL(void);
#endif
#endif
static int Init_COFB(void);

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief sys_enableAllInterrupts
* @details function used to enable all interrupts
*/
/*================================================================================================*/
void sys_enableAllInterrupts(void)
{
    OsIf_ResumeAllInterrupts();
}
/*================================================================================================*/
/**
* @brief sys_disableAllInterrupts
* @details function used to disable all interrupts
*/
/*================================================================================================*/
void sys_disableAllInterrupts(void)
{
    OsIf_SuspendAllInterrupts();
}
/*================================================================================================*/
/**
* @brief sys_disableIsrSource
* @details function used to disable the interrupt number id
*/
/*================================================================================================*/
void sys_disableIsrSource(uint16 id)
{
    Core_disableIsrSource(id);
}
/*================================================================================================*/
/**
* @brief sys_init
* @details function used to enable the interrupt number id and set up the priority
*/
/*================================================================================================*/
void sys_enableIsrSource(uint16 id, uint8 prio)
{
    Core_enableIsrSource(id, prio);
}
/*================================================================================================*/
/**
* @brief sys_init
* @details function used to register the interrupt handler in the interrupt vector
*/
/*================================================================================================*/
void sys_registerIsrHandler(uint16 irq_id, int_function_t isr_handler)
{
    OsIf_SuspendAllInterrupts();

    Core_registerIsrHandler(irq_id, isr_handler);

    OsIf_ResumeAllInterrupts();
}
/*================================================================================================*/
/**
* @brief sys_init
* @details function used to clear pending interrupt
*/
/*================================================================================================*/
void sys_clearIntPending(uint16 irq_id)
{
    Core_clearPendingIsrSource(irq_id);
}


/*================================================================================================*/
/*
 * system initialization : system clock, interrupt router ...
 */

/*-----------------------------------------------------------------------*/
/* Switch core clocks to FIRC_CLK                                        */
/*-----------------------------------------------------------------------*/
static int Switch_Core_FIRC(void)
{
    volatile int timeout = 0xFFFF;
    volatile int result  = 0;

    /* CGM_0_MUX_0_CSC -> M7 */
    /* Verify that we don't have switching in progress */
    while (((IP_MC_CGM_0->MUX_0_CSS & MC_CGM_0_MUX_0_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    /* Safe clock switch request to FIRC_CLK */
    IP_MC_CGM_0->MUX_0_CSC |= MC_CGM_0_MUX_0_CSC_SAFE_SW(1);

    /* Wait for acknowledge to be cleared */
    while (((IP_MC_CGM_0->MUX_0_CSS & MC_CGM_0_MUX_0_CSC_SAFE_SW_MASK) == 0) && (timeout > 0)) { --timeout; }

    /* Verify that clock switch completed */
    while (((IP_MC_CGM_0->MUX_0_CSS & MC_CGM_0_MUX_0_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }

    /* CGM_1_MUX_0_CSC -> A53 */
    /* Verify that we don't have switching in progress */
    while (((IP_MC_CGM_1->MUX_0_CSS & MC_CGM_MUX_0_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    /* Safe clock switch request to FIRC_CLK */
    IP_MC_CGM_1->MUX_0_CSC |= MC_CGM_MUX_0_CSC_SAFE_SW(1);

    /* Wait for acknowledge to be cleared */
    while (((IP_MC_CGM_1->MUX_0_CSS & MC_CGM_MUX_0_CSC_SAFE_SW_MASK) == 0) && (timeout > 0)) { --timeout; }

    /* Verify that clock switch completed */
    while (((IP_MC_CGM_1->MUX_0_CSS & MC_CGM_MUX_0_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }

    if (timeout <= 0)
    {
        result = SWITCH_CORE_FIRC_ERRNO; /* MC_CGM_CLK_SWITCH_TIMEOUT */
    }
    else
    {
        /* Do nothing */
    }

    return result;
}

/*-----------------------------------------------------------------------*/
/* Switch peripheral clocks to FIRC_CLK                                  */
/*-----------------------------------------------------------------------*/
static int Switch_Peripheral_FIRC(void)
{
    volatile int timeout = 0xFFFF;
    volatile int result  = 0;

    /* Verify that we don't have switching in progress */
    while (((IP_MC_CGM_0->MUX_0_CSS & MC_CGM_0_MUX_0_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_0->MUX_3_CSS & MC_CGM_0_MUX_3_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_0->MUX_4_CSS & MC_CGM_0_MUX_4_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_0->MUX_5_CSS & MC_CGM_0_MUX_5_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_0->MUX_6_CSS & MC_CGM_0_MUX_6_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_0->MUX_7_CSS & MC_CGM_0_MUX_7_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_0->MUX_8_CSS & MC_CGM_0_MUX_8_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }

    while (((IP_MC_CGM_1->MUX_0_CSS & MC_CGM_MUX_0_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_1->MUX_1_CSS & MC_CGM_MUX_1_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_1->MUX_2_CSS & MC_CGM_MUX_2_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_1->MUX_3_CSS & MC_CGM_MUX_3_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_1->MUX_4_CSS & MC_CGM_MUX_4_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_1->MUX_5_CSS & MC_CGM_MUX_5_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_1->MUX_6_CSS & MC_CGM_MUX_6_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }

#ifdef S32R41
    while (((IP_MC_CGM_2->MUX_1_CSS & MC_CGM_2_MUX_1_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_2->MUX_2_CSS & MC_CGM_2_MUX_2_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_2->MUX_3_CSS & MC_CGM_2_MUX_3_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_2->MUX_4_CSS & MC_CGM_2_MUX_4_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
#endif

    while (((IP_MC_CGM_3->MUX_0_CSS & MC_CGM_MUX_0_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_3->MUX_1_CSS & MC_CGM_MUX_1_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_3->MUX_2_CSS & MC_CGM_MUX_2_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_3->MUX_3_CSS & MC_CGM_MUX_3_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_3->MUX_4_CSS & MC_CGM_MUX_4_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }

    /* Safe clock switch request to FIRC_CLK */
    IP_MC_CGM_0->MUX_0_CSC |= MC_CGM_0_MUX_0_CSC_SAFE_SW(1);
    IP_MC_CGM_0->MUX_3_CSC |= MC_CGM_0_MUX_3_CSC_SAFE_SW(1);
    IP_MC_CGM_0->MUX_4_CSC |= MC_CGM_0_MUX_4_CSC_SAFE_SW(1);
    IP_MC_CGM_0->MUX_5_CSC |= MC_CGM_0_MUX_5_CSC_SAFE_SW(1);
    IP_MC_CGM_0->MUX_6_CSC |= MC_CGM_0_MUX_6_CSC_SAFE_SW(1);
    IP_MC_CGM_0->MUX_7_CSC |= MC_CGM_0_MUX_7_CSC_SAFE_SW(1);
    IP_MC_CGM_0->MUX_8_CSC |= MC_CGM_0_MUX_8_CSC_SAFE_SW(1);

    IP_MC_CGM_1->MUX_0_CSC |= MC_CGM_MUX_0_CSC_SAFE_SW(1);
    IP_MC_CGM_1->MUX_1_CSC |= MC_CGM_MUX_1_CSC_SAFE_SW(1);
    IP_MC_CGM_1->MUX_2_CSC |= MC_CGM_MUX_2_CSC_SAFE_SW(1);
    IP_MC_CGM_1->MUX_3_CSC |= MC_CGM_MUX_3_CSC_SAFE_SW(1);
    IP_MC_CGM_1->MUX_4_CSC |= MC_CGM_MUX_4_CSC_SAFE_SW(1);
    IP_MC_CGM_1->MUX_5_CSC |= MC_CGM_MUX_5_CSC_SAFE_SW(1);
    IP_MC_CGM_1->MUX_6_CSC |= MC_CGM_MUX_6_CSC_SAFE_SW(1);

#ifdef S32R41
    IP_MC_CGM_2->MUX_1_CSC |= MC_CGM_2_MUX_1_CSC_SAFE_SW(1);
    IP_MC_CGM_2->MUX_2_CSC |= MC_CGM_2_MUX_2_CSC_SAFE_SW(1);
    IP_MC_CGM_2->MUX_3_CSC |= MC_CGM_2_MUX_3_CSC_SAFE_SW(1);
    IP_MC_CGM_2->MUX_4_CSC |= MC_CGM_2_MUX_4_CSC_SAFE_SW(1);
#endif

    IP_MC_CGM_3->MUX_0_CSC |= MC_CGM_MUX_0_CSC_SAFE_SW(1);
    IP_MC_CGM_3->MUX_1_CSC |= MC_CGM_MUX_1_CSC_SAFE_SW(1);
    IP_MC_CGM_3->MUX_2_CSC |= MC_CGM_MUX_2_CSC_SAFE_SW(1);
    IP_MC_CGM_3->MUX_3_CSC |= MC_CGM_MUX_3_CSC_SAFE_SW(1);
    IP_MC_CGM_3->MUX_4_CSC |= MC_CGM_MUX_4_CSC_SAFE_SW(1);

    /* Wait for acknowledge to be cleared */
    while (((IP_MC_CGM_0->MUX_0_CSS & MC_CGM_0_MUX_0_CSC_SAFE_SW_MASK) == 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_0->MUX_3_CSS & MC_CGM_0_MUX_3_CSC_SAFE_SW_MASK) == 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_0->MUX_4_CSS & MC_CGM_0_MUX_4_CSC_SAFE_SW_MASK) == 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_0->MUX_5_CSS & MC_CGM_0_MUX_5_CSC_SAFE_SW_MASK) == 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_0->MUX_6_CSS & MC_CGM_0_MUX_6_CSC_SAFE_SW_MASK) == 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_0->MUX_7_CSS & MC_CGM_0_MUX_7_CSC_SAFE_SW_MASK) == 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_0->MUX_8_CSS & MC_CGM_0_MUX_8_CSC_SAFE_SW_MASK) == 0) && (timeout > 0)) { --timeout; }

    while (((IP_MC_CGM_1->MUX_0_CSS & MC_CGM_MUX_0_CSC_SAFE_SW_MASK) == 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_1->MUX_1_CSS & MC_CGM_MUX_1_CSC_SAFE_SW_MASK) == 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_1->MUX_2_CSS & MC_CGM_MUX_2_CSC_SAFE_SW_MASK) == 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_1->MUX_3_CSS & MC_CGM_MUX_3_CSC_SAFE_SW_MASK) == 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_1->MUX_4_CSS & MC_CGM_MUX_4_CSC_SAFE_SW_MASK) == 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_1->MUX_5_CSS & MC_CGM_MUX_5_CSC_SAFE_SW_MASK) == 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_1->MUX_6_CSS & MC_CGM_MUX_6_CSC_SAFE_SW_MASK) == 0) && (timeout > 0)) { --timeout; }

#ifdef S32R41
    while (((IP_MC_CGM_2->MUX_1_CSS & MC_CGM_2_MUX_1_CSC_SAFE_SW_MASK) == 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_2->MUX_2_CSS & MC_CGM_2_MUX_2_CSC_SAFE_SW_MASK) == 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_2->MUX_3_CSS & MC_CGM_2_MUX_3_CSC_SAFE_SW_MASK) == 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_2->MUX_4_CSS & MC_CGM_2_MUX_4_CSC_SAFE_SW_MASK) == 0) && (timeout > 0)) { --timeout; }
#endif

    while (((IP_MC_CGM_3->MUX_0_CSS & MC_CGM_MUX_0_CSC_SAFE_SW_MASK) == 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_3->MUX_1_CSS & MC_CGM_MUX_1_CSC_SAFE_SW_MASK) == 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_3->MUX_2_CSS & MC_CGM_MUX_2_CSC_SAFE_SW_MASK) == 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_3->MUX_3_CSS & MC_CGM_MUX_3_CSC_SAFE_SW_MASK) == 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_3->MUX_4_CSS & MC_CGM_MUX_4_CSC_SAFE_SW_MASK) == 0) && (timeout > 0)) { --timeout; }

    /* Verify that clock switch completed */
    while (((IP_MC_CGM_0->MUX_0_CSS & MC_CGM_0_MUX_0_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_0->MUX_3_CSS & MC_CGM_0_MUX_3_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_0->MUX_4_CSS & MC_CGM_0_MUX_4_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_0->MUX_5_CSS & MC_CGM_0_MUX_5_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_0->MUX_6_CSS & MC_CGM_0_MUX_6_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_0->MUX_7_CSS & MC_CGM_0_MUX_7_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_0->MUX_8_CSS & MC_CGM_0_MUX_8_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }

    while (((IP_MC_CGM_1->MUX_0_CSS & MC_CGM_MUX_0_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_1->MUX_1_CSS & MC_CGM_MUX_1_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_1->MUX_2_CSS & MC_CGM_MUX_2_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_1->MUX_3_CSS & MC_CGM_MUX_3_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_1->MUX_4_CSS & MC_CGM_MUX_4_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_1->MUX_5_CSS & MC_CGM_MUX_5_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_1->MUX_6_CSS & MC_CGM_MUX_6_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }

#ifdef S32R41
    while (((IP_MC_CGM_2->MUX_1_CSS & MC_CGM_2_MUX_1_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_2->MUX_2_CSS & MC_CGM_2_MUX_2_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_2->MUX_3_CSS & MC_CGM_2_MUX_3_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_2->MUX_4_CSS & MC_CGM_2_MUX_4_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
#endif

    while (((IP_MC_CGM_3->MUX_0_CSS & MC_CGM_MUX_0_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_3->MUX_1_CSS & MC_CGM_MUX_1_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_3->MUX_2_CSS & MC_CGM_MUX_2_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_3->MUX_3_CSS & MC_CGM_MUX_3_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_3->MUX_4_CSS & MC_CGM_MUX_4_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }

    if (timeout <= 0)
    {
        result = SWITCH_PERIPHERAL_FIRC_ERRNO; /* MC_CGM_CLK_SWITCH_TIMEOUT */
    }
    else
    {
        /* Do nothing */
    }

    return result;
}

/*-----------------------------------------------------------------------*/
/* Initialize & Start FXSOC = 40MHz (X-S32R41-EVB)                       */
/*-----------------------------------------------------------------------*/
static int Init_FXOSC(void)
{
    volatile int timeout = 0xFFFF;
    volatile int result  = 0;

    /* Set "Crystal Mode" */
#ifdef S32R41
    IP_FXOSC->CTRL = (IP_FXOSC->CTRL & ~FXOSC_CTRL_EOCV_MASK   ) | FXOSC_CTRL_EOCV(0x9D);
    IP_FXOSC->CTRL = (IP_FXOSC->CTRL & ~FXOSC_CTRL_GM_SEL_MASK ) | FXOSC_CTRL_GM_SEL(0xF);
    IP_FXOSC->CTRL = (IP_FXOSC->CTRL & ~FXOSC_CTRL_OSC_BYP_MASK) | FXOSC_CTRL_OSC_BYP(0);
#else
    /* SAF85xx: Internal stubbed oscillator bypassed hence clock available based on RFE_XOSC availability */
    IP_FXOSC->CTRL = (IP_FXOSC->CTRL & ~FXOSC_CTRL_OSC_BYP_MASK) | FXOSC_CTRL_OSC_BYP(1);
#endif
#ifdef S32R41
    IP_FXOSC->CTRL = (IP_FXOSC->CTRL & ~FXOSC_CTRL_COMP_EN_MASK) | FXOSC_CTRL_COMP_EN(1);
#endif
    IP_FXOSC->CTRL = (IP_FXOSC->CTRL & ~FXOSC_CTRL_OSCON_MASK  ) | FXOSC_CTRL_OSCON(1);

#ifdef S32R41
    while (((IP_FXOSC->STAT & FXOSC_STAT_OSC_STAT_MASK) == 0) && (timeout > 0)) { --timeout; }
#else
    while (((IP_FXOSC->STATUS & FXOSC_STATUS_OSC_STAT_MASK) == 0) && (timeout > 0)) { --timeout; }
#endif

    if (timeout <= 0)
    {
        result = INIT_FXOSC_ERRNO; /* FXOSC_TIMEOUT */
    }
    else
    {
        /* Do nothing */
    }

    return result;
}

/*-----------------------------------------------------------------------*/
/* Initialize Core_PLL                                                   */
/* - S32R41:                                                             */
/* FXOSC = 40MHz, FIRC = 48MHz, VCO = 2400MHz(?)                         */
/* Clocking.xlsx states Max(VCO)=2400MHz, but DS states Max(VCO)=1600MHz */
/* PHI0 = 800MHz, PHI1 = 600MHz, PHI2 = 400MHz, PHI3 = 80MHz,            */
/* (S32R416LB: PHI0 = 480MHz, PHI1 = 400MHz, PHI2 = 300MHz)              */
/* PHI4 =  80MHz, PHI5 = NC,     PHI6 = NC,     PHI7 = NC                */
/* PHI8 = 800MHz, PHI9 = 400MHz                                          */
/* - SAF85xx:                                                            */
/* FXOSC = 40MHz, FIRC = 48MHz, RFE_PLL = 640MHz                         */
/* PHI0 = 320MHz, PHI1 = 320MHz, PHI2 = 320MHz, PHI3 = 80MHz,            */
/* PHI4 = NC,     PHI5 = 320MHz, PHI6 = 320MHz, PHI7 = NC                */
/* PHI8 = 640MHz, PHI9 = 320MHz                                          */
/*-----------------------------------------------------------------------*/
static int Init_Core_PLL(void)
{
    volatile int timeout = 0xFFFF;
    volatile int result  = 0;

    IP_CORE_PLL->PLLODIV[0] = (IP_CORE_PLL->PLLODIV[0] & ~PLLDIG_PLLODIV_DE_MASK) | PLLDIG_PLLODIV_DE(0);       /* Disable PHI0 output */
    IP_CORE_PLL->PLLODIV[1] = (IP_CORE_PLL->PLLODIV[1] & ~PLLDIG_PLLODIV_DE_MASK) | PLLDIG_PLLODIV_DE(0);       /* Disable PHI1 output */
    IP_CORE_PLL->PLLODIV[2] = (IP_CORE_PLL->PLLODIV[2] & ~PLLDIG_PLLODIV_DE_MASK) | PLLDIG_PLLODIV_DE(0);       /* Disable PHI2 output */
    IP_CORE_PLL->PLLODIV[3] = (IP_CORE_PLL->PLLODIV[3] & ~PLLDIG_PLLODIV_DE_MASK) | PLLDIG_PLLODIV_DE(0);       /* Disable PHI3 output */
    IP_CORE_PLL->PLLODIV[4] = (IP_CORE_PLL->PLLODIV[4] & ~PLLDIG_PLLODIV_DE_MASK) | PLLDIG_PLLODIV_DE(0);       /* Disable PHI4 output */
    IP_CORE_PLL->PLLODIV[5] = (IP_CORE_PLL->PLLODIV[5] & ~PLLDIG_PLLODIV_DE_MASK) | PLLDIG_PLLODIV_DE(0);       /* Disable PHI5 output */
    IP_CORE_PLL->PLLODIV[6] = (IP_CORE_PLL->PLLODIV[6] & ~PLLDIG_PLLODIV_DE_MASK) | PLLDIG_PLLODIV_DE(0);       /* Disable PHI6 output */
    IP_CORE_PLL->PLLODIV[7] = (IP_CORE_PLL->PLLODIV[7] & ~PLLDIG_PLLODIV_DE_MASK) | PLLDIG_PLLODIV_DE(0);       /* Disable PHI7 output */
    IP_CORE_PLL->PLLODIV[8] = (IP_CORE_PLL->PLLODIV[8] & ~PLLDIG_PLLODIV_DE_MASK) | PLLDIG_PLLODIV_DE(0);       /* Disable PHI8 output */
    IP_CORE_PLL->PLLODIV[9] = (IP_CORE_PLL->PLLODIV[9] & ~PLLDIG_PLLODIV_DE_MASK) | PLLDIG_PLLODIV_DE(0);       /* Disable PHI9 output */

    IP_CORE_PLL->PLLCR = (IP_CORE_PLL->PLLCR & ~PLLDIG_PLLCR_PLLPD_MASK) | PLLDIG_PLLCR_PLLPD(1);          /* Disable Core_PLL */

#ifdef S32R41
#if ( SYS_USE_FXOSC == STD_ON )
    IP_CORE_PLL->PLLCLKMUX = (IP_CORE_PLL->PLLCLKMUX & ~PLLDIG_PLLCLKMUX_REFCLKSEL_MASK) | PLLDIG_PLLCLKMUX_REFCLKSEL(1);    /* Source FXOSC (40MHz) */
#endif
#if ( SYS_USE_FIRC == STD_ON )
    IP_CORE_PLL->PLLCLKMUX = (IP_CORE_PLL->PLLCLKMUX & ~PLLDIG_PLLCLKMUX_REFCLKSEL_MASK) | PLLDIG_PLLCLKMUX_REFCLKSEL(0);    /* Source FIRC (48MHz)  */
#endif

#if ( SYS_USE_FXOSC == STD_ON )
    IP_CORE_PLL->PLLDV = (IP_CORE_PLL->PLLDV & ~PLLDIG_PLLDV_RDIV_MASK) | PLLDIG_PLLDV_RDIV(1);  /* FXOSC = 40MHz / 1 = 40MHz input frequency  */
    IP_CORE_PLL->PLLDV = (IP_CORE_PLL->PLLDV & ~PLLDIG_PLLDV_MFI_MASK ) | PLLDIG_PLLDV_MFI(CORE_PLLDIG_PLLDV_MFI_VAL);  /* FXOSC = 40MHz * 60 = 2400MHz VCO frequency */
#endif
#if ( SYS_USE_FIRC == STD_ON )
    IP_CORE_PLL->PLLDV = (IP_CORE_PLL->PLLDV & ~PLLDIG_PLLDV_RDIV_MASK) | PLLDIG_PLLDV_RDIV(2);  /* FIRC = 48MHz / 2 = 24MHz input frequency   */
    IP_CORE_PLL->PLLDV = (IP_CORE_PLL->PLLDV & ~PLLDIG_PLLDV_MFI_MASK ) | PLLDIG_PLLDV_MFI(100); /* FIRC = 24MHz * 100 = 2400MHz VCO frequency */
#endif

    IP_CORE_PLL->PLLFD = (IP_CORE_PLL->PLLFD & ~PLLDIG_PLLFD_SDMEN_MASK) | PLLDIG_PLLFD_SDMEN(0);  /* Disable Frac-N mode */
    IP_CORE_PLL->PLLFD = (IP_CORE_PLL->PLLFD & ~PLLDIG_PLLFD_MFN_MASK  ) | PLLDIG_PLLFD_MFN(0);    /* No fractional divider */

    IP_CORE_PLL->PLLFM = (IP_CORE_PLL->PLLFM & ~PLLDIG_PLLFM_SSCGBYP_MASK  ) | PLLDIG_PLLFM_SSCGBYP(1);    /* Bypass modulation */
    IP_CORE_PLL->PLLFM = (IP_CORE_PLL->PLLFM & ~PLLDIG_PLLFM_STEPNO_MASK   ) | PLLDIG_PLLFM_STEPNO(0);
    IP_CORE_PLL->PLLFM = (IP_CORE_PLL->PLLFM & ~PLLDIG_PLLFM_SPREADCTL_MASK) | PLLDIG_PLLFM_SPREADCTL(0);  /* Only centered modulation supported */
    IP_CORE_PLL->PLLFM = (IP_CORE_PLL->PLLFM & ~PLLDIG_PLLFM_STEPSIZE_MASK ) | PLLDIG_PLLFM_STEPSIZE(0);
#else
#if ( SYS_USE_FIRC_MUXED == STD_ON )
    IP_CORE_PLL->CLKMUX = (IP_CORE_PLL->CLKMUX & ~PLLDIG_CLKMUX_RCLKSEL_MASK) | PLLDIG_CLKMUX_RCLKSEL(0);    /* Source FIRC (48MHz)  */
#endif
#if ( SYS_USE_RFE_PLL == STD_ON )
    IP_CORE_PLL->CLKMUX = (IP_CORE_PLL->CLKMUX & ~PLLDIG_CLKMUX_RCLKSEL_MASK) | PLLDIG_CLKMUX_RCLKSEL(2);    /* Source RFE_PLL */
#endif
#if ( SYS_USE_AURORA_PLL == STD_ON )
    IP_CORE_PLL->CLKMUX = (IP_CORE_PLL->CLKMUX & ~PLLDIG_CLKMUX_RCLKSEL_MASK) | PLLDIG_CLKMUX_RCLKSEL(3);    /* Source AURORA_PLL */
#endif
#endif

#ifdef S32R41
#ifdef S32R416LB
    IP_CORE_PLL->PLLODIV[0] = (IP_CORE_PLL->PLLODIV[0] & ~PLLDIG_PLLODIV_DIV_MASK) | PLLDIG_PLLODIV_DIV(5-1);   /* PHI0 = VCO / (ODIV_0 + 1) = 2400 / 5  = 480MHz */
    IP_CORE_PLL->PLLODIV[1] = (IP_CORE_PLL->PLLODIV[1] & ~PLLDIG_PLLODIV_DIV_MASK) | PLLDIG_PLLODIV_DIV(6-1);   /* PHI1 = VCO / (ODIV_1 + 1) = 2400 / 6  = 400MHz */
    IP_CORE_PLL->PLLODIV[2] = (IP_CORE_PLL->PLLODIV[2] & ~PLLDIG_PLLODIV_DIV_MASK) | PLLDIG_PLLODIV_DIV(8-1);   /* PHI2 = VCO / (ODIV_2 + 1) = 2400 / 8  = 300MHz */
#else
    IP_CORE_PLL->PLLODIV[0] = (IP_CORE_PLL->PLLODIV[0] & ~PLLDIG_PLLODIV_DIV_MASK) | PLLDIG_PLLODIV_DIV(3-1);   /* PHI0 = VCO / (ODIV_0 + 1) = 2400 / 3  = 800MHz */
    IP_CORE_PLL->PLLODIV[1] = (IP_CORE_PLL->PLLODIV[1] & ~PLLDIG_PLLODIV_DIV_MASK) | PLLDIG_PLLODIV_DIV(4-1);   /* PHI1 = VCO / (ODIV_1 + 1) = 2400 / 4  = 600MHz */
    IP_CORE_PLL->PLLODIV[2] = (IP_CORE_PLL->PLLODIV[2] & ~PLLDIG_PLLODIV_DIV_MASK) | PLLDIG_PLLODIV_DIV(6-1);   /* PHI2 = VCO / (ODIV_2 + 1) = 2400 / 6  = 400MHz */
#endif
    IP_CORE_PLL->PLLODIV[3] = (IP_CORE_PLL->PLLODIV[3] & ~PLLDIG_PLLODIV_DIV_MASK) | PLLDIG_PLLODIV_DIV(30-1);  /* PHI3 = VCO / (ODIV_3 + 1) = 2400 / 30 = 80MHz  */
    IP_CORE_PLL->PLLODIV[4] = (IP_CORE_PLL->PLLODIV[4] & ~PLLDIG_PLLODIV_DIV_MASK) | PLLDIG_PLLODIV_DIV(60-1);  /* PHI4 = VCO / (ODIV_4 + 1) = 2400 / 60 = 40MHz  */
    IP_CORE_PLL->PLLODIV[5] = (IP_CORE_PLL->PLLODIV[5] & ~PLLDIG_PLLODIV_DIV_MASK) | PLLDIG_PLLODIV_DIV(1-1);     /* PHI5 */
    IP_CORE_PLL->PLLODIV[6] = (IP_CORE_PLL->PLLODIV[6] & ~PLLDIG_PLLODIV_DIV_MASK) | PLLDIG_PLLODIV_DIV(1-1);     /* PHI6 */
    IP_CORE_PLL->PLLODIV[7] = (IP_CORE_PLL->PLLODIV[7] & ~PLLDIG_PLLODIV_DIV_MASK) | PLLDIG_PLLODIV_DIV(0);     /* PHI7 Not Connected */
    IP_CORE_PLL->PLLODIV[8] = (IP_CORE_PLL->PLLODIV[8] & ~PLLDIG_PLLODIV_DIV_MASK) | PLLDIG_PLLODIV_DIV(3-1);   /* PHI8 = VCO / (ODIV_8 + 1) = 2400 / 3  = 800MHz */
    IP_CORE_PLL->PLLODIV[9] = (IP_CORE_PLL->PLLODIV[9] & ~PLLDIG_PLLODIV_DIV_MASK) | PLLDIG_PLLODIV_DIV(6-1);   /* PHI9 = VCO / (ODIV_9 + 1) = 2400 / 6  = 400MHz */
#else
    IP_CORE_PLL->PLLODIV[0] = (IP_CORE_PLL->PLLODIV[0] & ~PLLDIG_PLLODIV_DIV_MASK) | PLLDIG_PLLODIV_DIV(2-1);   /* PHI0 = RFE_PLL / (ODIV_0 + 1) = 640 / 2  = 320MHz */
    IP_CORE_PLL->PLLODIV[1] = (IP_CORE_PLL->PLLODIV[1] & ~PLLDIG_PLLODIV_DIV_MASK) | PLLDIG_PLLODIV_DIV(2-1);   /* PHI1 = RFE_PLL / (ODIV_1 + 1) = 640 / 2  = 320MHz */
    IP_CORE_PLL->PLLODIV[2] = (IP_CORE_PLL->PLLODIV[2] & ~PLLDIG_PLLODIV_DIV_MASK) | PLLDIG_PLLODIV_DIV(2-1);   /* PHI2 = RFE_PLL / (ODIV_2 + 1) = 640 / 2  = 320MHz */
    IP_CORE_PLL->PLLODIV[3] = (IP_CORE_PLL->PLLODIV[3] & ~PLLDIG_PLLODIV_DIV_MASK) | PLLDIG_PLLODIV_DIV(8-1);   /* PHI3 = RFE_PLL / (ODIV_3 + 1) = 640 / 8  = 80MHz */
    IP_CORE_PLL->PLLODIV[4] = (IP_CORE_PLL->PLLODIV[4] & ~PLLDIG_PLLODIV_DIV_MASK) | PLLDIG_PLLODIV_DIV(0);     /* PHI4 Not Connected */
    IP_CORE_PLL->PLLODIV[5] = (IP_CORE_PLL->PLLODIV[5] & ~PLLDIG_PLLODIV_DIV_MASK) | PLLDIG_PLLODIV_DIV(2-1);   /* PHI5 = RFE_PLL / (ODIV_5 + 1) = 640 / 2  = 320MHz */
    IP_CORE_PLL->PLLODIV[6] = (IP_CORE_PLL->PLLODIV[6] & ~PLLDIG_PLLODIV_DIV_MASK) | PLLDIG_PLLODIV_DIV(2-1);   /* PHI6 = RFE_PLL / (ODIV_6 + 1) = 640 / 2  = 320MHz */
    IP_CORE_PLL->PLLODIV[7] = (IP_CORE_PLL->PLLODIV[7] & ~PLLDIG_PLLODIV_DIV_MASK) | PLLDIG_PLLODIV_DIV(0);     /* PHI7 Not Connected */
    IP_CORE_PLL->PLLODIV[8] = (IP_CORE_PLL->PLLODIV[8] & ~PLLDIG_PLLODIV_DIV_MASK) | PLLDIG_PLLODIV_DIV(1-1);   /* PHI8 = RFE_PLL / (ODIV_8 + 1) = 640 / 1  = 640MHz */
    IP_CORE_PLL->PLLODIV[9] = (IP_CORE_PLL->PLLODIV[9] & ~PLLDIG_PLLODIV_DIV_MASK) | PLLDIG_PLLODIV_DIV(2-1);   /* PHI9 = RFE_PLL / (ODIV_9 + 1) = 640 / 2  = 320Hz */
#endif

    IP_CORE_PLL->PLLCR = (IP_CORE_PLL->PLLCR & ~PLLDIG_PLLCR_PLLPD_MASK) | PLLDIG_PLLCR_PLLPD(0);          /* Enable Core_PLL */

    /* Wait for PLL lock */
    while (((IP_CORE_PLL->PLLSR & PLLDIG_PLLSR_LOCK_MASK) == 0) && (timeout > 0)) { --timeout; }
    if (timeout <= 0)
    {
        result = INIT_CORE_PLL_ERRNO; /* PLL_TIMEOUT */
    }
    else
    {
        /* Do nothing */
    }

    IP_CORE_PLL->PLLODIV[0] = (IP_CORE_PLL->PLLODIV[0] & ~PLLDIG_PLLODIV_DE_MASK) | PLLDIG_PLLODIV_DE(1);     /* Enable PHI0 output */
    IP_CORE_PLL->PLLODIV[1] = (IP_CORE_PLL->PLLODIV[1] & ~PLLDIG_PLLODIV_DE_MASK) | PLLDIG_PLLODIV_DE(1);     /* Enable PHI1 output */
    IP_CORE_PLL->PLLODIV[2] = (IP_CORE_PLL->PLLODIV[2] & ~PLLDIG_PLLODIV_DE_MASK) | PLLDIG_PLLODIV_DE(1);     /* Enable PHI2 output */
    IP_CORE_PLL->PLLODIV[3] = (IP_CORE_PLL->PLLODIV[3] & ~PLLDIG_PLLODIV_DE_MASK) | PLLDIG_PLLODIV_DE(1);     /* Enable PHI3 output */
#ifdef S32R41
    IP_CORE_PLL->PLLODIV[4] = (IP_CORE_PLL->PLLODIV[4] & ~PLLDIG_PLLODIV_DE_MASK) | PLLDIG_PLLODIV_DE(1);     /* Enable PHI4 output */
#else
    IP_CORE_PLL->PLLODIV[5] = (IP_CORE_PLL->PLLODIV[5] & ~PLLDIG_PLLODIV_DE_MASK) | PLLDIG_PLLODIV_DE(1);     /* Enable PHI5 output */
    IP_CORE_PLL->PLLODIV[6] = (IP_CORE_PLL->PLLODIV[6] & ~PLLDIG_PLLODIV_DE_MASK) | PLLDIG_PLLODIV_DE(1);     /* Enable PHI6 output */
#endif
    /* PHI7 Not Connected */
    IP_CORE_PLL->PLLODIV[8] = (IP_CORE_PLL->PLLODIV[8] & ~PLLDIG_PLLODIV_DE_MASK) | PLLDIG_PLLODIV_DE(1);     /* Enable PHI8 output */
    IP_CORE_PLL->PLLODIV[9] = (IP_CORE_PLL->PLLODIV[9] & ~PLLDIG_PLLODIV_DE_MASK) | PLLDIG_PLLODIV_DE(1);     /* Enable PHI9 output */

    return result;
}

/*-----------------------------------------------------------------------*/
/* Initialize Peripheral_PLL                                             */
/* - S32R41:                                                             */
/* FXOSC = 40MHz, FIRC = 48MHz, VCO = 2000MHz                            */
/* PHI0 = 400MHz, PHI1 =  80MHz, PHI2 =  80MHz, PHI3 = 100 MHz,          */
/* (S32R416LB:  PHI0 = 250MHz)                                           */
/* PHI4 = 200MHz, PHI5 = 500MHz, PHI6 =  50MHz, PHI7 = 100 MHz,          */
/* PHI8 = 400MHz, PHI9 = 62.5MHz                                         */
/* - SAF85xx:                                                            */
/* FXOSC = 40MHz, FIRC = 48MHz, RFE_PLL = 640MHz                         */
/* PHI0 = 320MHz, PHI1 =  80MHz, PHI2 =  80MHz, PHI3 =  80MHz,           */
/* PHI4 = 160MHz, PHI5 = 320MHz, PHI6 = 320MHz, PHI7 =  80MHz,           */
/* PHI8 =     NC, PHI9 = 213.3MHz                                        */
/*-----------------------------------------------------------------------*/
static int Init_Peripheral_PLL(void)
{
    volatile int timeout = 0xFFFF;
    volatile int result  = 0;

    IP_PERIPH_PLL->PLLODIV[0] = (IP_PERIPH_PLL->PLLODIV[0] & ~PLLDIG_PLLODIV_DE_MASK) | PLLDIG_PLLODIV_DE(0);     /* Disable PHI0 output */
    IP_PERIPH_PLL->PLLODIV[1] = (IP_PERIPH_PLL->PLLODIV[1] & ~PLLDIG_PLLODIV_DE_MASK) | PLLDIG_PLLODIV_DE(0);     /* Disable PHI1 output */
    IP_PERIPH_PLL->PLLODIV[2] = (IP_PERIPH_PLL->PLLODIV[2] & ~PLLDIG_PLLODIV_DE_MASK) | PLLDIG_PLLODIV_DE(0);     /* Disable PHI2 output */
    IP_PERIPH_PLL->PLLODIV[3] = (IP_PERIPH_PLL->PLLODIV[3] & ~PLLDIG_PLLODIV_DE_MASK) | PLLDIG_PLLODIV_DE(0);     /* Disable PHI3 output */
    IP_PERIPH_PLL->PLLODIV[4] = (IP_PERIPH_PLL->PLLODIV[4] & ~PLLDIG_PLLODIV_DE_MASK) | PLLDIG_PLLODIV_DE(0);     /* Disable PHI4 output */
    IP_PERIPH_PLL->PLLODIV[5] = (IP_PERIPH_PLL->PLLODIV[5] & ~PLLDIG_PLLODIV_DE_MASK) | PLLDIG_PLLODIV_DE(0);     /* Disable PHI5 output */
    IP_PERIPH_PLL->PLLODIV[6] = (IP_PERIPH_PLL->PLLODIV[6] & ~PLLDIG_PLLODIV_DE_MASK) | PLLDIG_PLLODIV_DE(0);     /* Disable PHI6 output */
    IP_PERIPH_PLL->PLLODIV[7] = (IP_PERIPH_PLL->PLLODIV[7] & ~PLLDIG_PLLODIV_DE_MASK) | PLLDIG_PLLODIV_DE(0);     /* Disable PHI7 output */
    IP_PERIPH_PLL->PLLODIV[8] = (IP_PERIPH_PLL->PLLODIV[8] & ~PLLDIG_PLLODIV_DE_MASK) | PLLDIG_PLLODIV_DE(0);     /* Disable PHI8 output */
    IP_PERIPH_PLL->PLLODIV[9] = (IP_PERIPH_PLL->PLLODIV[9] & ~PLLDIG_PLLODIV_DE_MASK) | PLLDIG_PLLODIV_DE(0);     /* Disable PHI9 output */

    IP_PERIPH_PLL->PLLCR = (IP_PERIPH_PLL->PLLCR & ~PLLDIG_PLLCR_PLLPD_MASK) | PLLDIG_PLLCR_PLLPD(1);        /* Disable Peripheral_PLL */

#ifdef S32R41
#if ( SYS_USE_FXOSC == STD_ON )
    IP_PERIPH_PLL->PLLCLKMUX = (IP_PERIPH_PLL->PLLCLKMUX & ~PLLDIG_PLLCLKMUX_REFCLKSEL_MASK) | PLLDIG_PLLCLKMUX_REFCLKSEL(1);  /* Source FXOSC (40MHz) */
#endif
#if ( SYS_USE_FIRC == STD_ON )
    IP_PERIPH_PLL->PLLCLKMUX = (IP_PERIPH_PLL->PLLCLKMUX & ~PLLDIG_PLLCLKMUX_REFCLKSEL_MASK) | PLLDIG_PLLCLKMUX_REFCLKSEL(0);  /* Source FIRC (48MHz)  */
#endif

#if ( SYS_USE_FXOSC == STD_ON )
    IP_PERIPH_PLL->PLLDV = (IP_PERIPH_PLL->PLLDV & ~PLLDIG_PLLDV_RDIV_MASK) | PLLDIG_PLLDV_RDIV(1);   /* FXOSC = 40MHz / 1 = 40MHz input frequency  */
    IP_PERIPH_PLL->PLLDV = (IP_PERIPH_PLL->PLLDV & ~PLLDIG_PLLDV_MFI_MASK ) | PLLDIG_PLLDV_MFI(PERIPH_PLLDIG_PLLDV_MFI_VAL);   /* FXOSC = 40MHz * 50 = 2000MHz VCO frequency */
#endif
#if ( SYS_USE_FIRC == STD_ON )
    IP_PERIPH_PLL->PLLDV = (IP_PERIPH_PLL->PLLDV & ~PLLDIG_PLLDV_RDIV_MASK) | PLLDIG_PLLDV_RDIV(3);   /* FIRC = 48MHz / 3 = 16MHz input frequency   */
    IP_PERIPH_PLL->PLLDV = (IP_PERIPH_PLL->PLLDV & ~PLLDIG_PLLDV_MFI_MASK ) | PLLDIG_PLLDV_MFI(125);  /* FIRC = 16MHz * 125 = 2000MHz VCO frequency */
#endif
#else
#if ( SYS_USE_FIRC_MUXED == STD_ON )
    IP_PERIPH_PLL->CLKMUX = (IP_PERIPH_PLL->CLKMUX & ~PLLDIG_CLKMUX_RCLKSEL_MASK) | PLLDIG_CLKMUX_RCLKSEL(0);    /* Source FIRC (48MHz)  */
#endif
#if ( SYS_USE_RFE_PLL == STD_ON )
    IP_PERIPH_PLL->CLKMUX = (IP_PERIPH_PLL->CLKMUX & ~PLLDIG_CLKMUX_RCLKSEL_MASK) | PLLDIG_CLKMUX_RCLKSEL(2);    /* Source RFE_PLL */
#endif
#if ( SYS_USE_AURORA_PLL == STD_ON )
    IP_PERIPH_PLL->CLKMUX = (IP_PERIPH_PLL->CLKMUX & ~PLLDIG_CLKMUX_RCLKSEL_MASK) | PLLDIG_CLKMUX_RCLKSEL(3);    /* Source AURORA_PLL */
#endif
#endif

    /* PLLFD Not Available */
    /* PLLFM Not Available */

#ifdef S32R41
#ifdef S32R416LB
    IP_PERIPH_PLL->PLLODIV[0] = (IP_PERIPH_PLL->PLLODIV[0] & ~PLLDIG_PLLODIV_DIV_MASK) | PLLDIG_PLLODIV_DIV(8-1);   /* PHI0 = VCO / (ODIV_0 + 1) = 2000 / 8  = 250MHz  */
#else
    IP_PERIPH_PLL->PLLODIV[0] = (IP_PERIPH_PLL->PLLODIV[0] & ~PLLDIG_PLLODIV_DIV_MASK) | PLLDIG_PLLODIV_DIV(5-1);   /* PHI0 = VCO / (ODIV_0 + 1) = 2000 / 5  = 400MHz  */
#endif
    IP_PERIPH_PLL->PLLODIV[1] = (IP_PERIPH_PLL->PLLODIV[1] & ~PLLDIG_PLLODIV_DIV_MASK) | PLLDIG_PLLODIV_DIV(25-1);  /* PHI1 = VCO / (ODIV_1 + 1) = 2000 / 25 =  80MHz  */
    IP_PERIPH_PLL->PLLODIV[2] = (IP_PERIPH_PLL->PLLODIV[2] & ~PLLDIG_PLLODIV_DIV_MASK) | PLLDIG_PLLODIV_DIV(25-1);  /* PHI2 = VCO / (ODIV_2 + 1) = 2000 / 25 =  80MHz  */
    IP_PERIPH_PLL->PLLODIV[3] = (IP_PERIPH_PLL->PLLODIV[3] & ~PLLDIG_PLLODIV_DIV_MASK) | PLLDIG_PLLODIV_DIV(20-1);  /* PHI3 = VCO / (ODIV_3 + 1) = 2000 / 20 = 100MHz  */
    IP_PERIPH_PLL->PLLODIV[4] = (IP_PERIPH_PLL->PLLODIV[4] & ~PLLDIG_PLLODIV_DIV_MASK) | PLLDIG_PLLODIV_DIV(10-1);  /* PHI4 = VCO / (ODIV_4 + 1) = 2000 / 10 = 200MHz  */
    IP_PERIPH_PLL->PLLODIV[5] = (IP_PERIPH_PLL->PLLODIV[5] & ~PLLDIG_PLLODIV_DIV_MASK) | PLLDIG_PLLODIV_DIV(4-1);   /* PHI5 = VCO / (ODIV_5 + 1) = 2000 / 4  = 500MHz  */
    IP_PERIPH_PLL->PLLODIV[6] = (IP_PERIPH_PLL->PLLODIV[6] & ~PLLDIG_PLLODIV_DIV_MASK) | PLLDIG_PLLODIV_DIV(40-1);  /* PHI6 = VCO / (ODIV_6 + 1) = 2000 / 40 =  50MHz  */
    IP_PERIPH_PLL->PLLODIV[7] = (IP_PERIPH_PLL->PLLODIV[7] & ~PLLDIG_PLLODIV_DIV_MASK) | PLLDIG_PLLODIV_DIV(20-1);  /* PHI7 = VCO / (ODIV_7 + 1) = 2000 / 20 = 100MHz  */
    IP_PERIPH_PLL->PLLODIV[8] = (IP_PERIPH_PLL->PLLODIV[8] & ~PLLDIG_PLLODIV_DIV_MASK) | PLLDIG_PLLODIV_DIV(5-1);   /* PHI8 = VCO / (ODIV_8 + 1) = 2000 / 5  = 400MHz  */
    IP_PERIPH_PLL->PLLODIV[9] = (IP_PERIPH_PLL->PLLODIV[9] & ~PLLDIG_PLLODIV_DIV_MASK) | PLLDIG_PLLODIV_DIV(32-1);  /* PHI9 = VCO / (ODIV_9 + 1) = 2000 / 32 = 62.5MHz */
#else
    IP_PERIPH_PLL->PLLODIV[0] = (IP_PERIPH_PLL->PLLODIV[0] & ~PLLDIG_PLLODIV_DIV_MASK) | PLLDIG_PLLODIV_DIV(2-1);   /* PHI0 = RFE_PLL / (ODIV_0 + 1) = 640 / 2 = 320MHz */
    IP_PERIPH_PLL->PLLODIV[1] = (IP_PERIPH_PLL->PLLODIV[1] & ~PLLDIG_PLLODIV_DIV_MASK) | PLLDIG_PLLODIV_DIV(8-1);   /* PHI1 = RFE_PLL / (ODIV_1 + 1) = 640 / 8 =  80MHz */
    IP_PERIPH_PLL->PLLODIV[2] = (IP_PERIPH_PLL->PLLODIV[2] & ~PLLDIG_PLLODIV_DIV_MASK) | PLLDIG_PLLODIV_DIV(8-1);   /* PHI2 = RFE_PLL / (ODIV_2 + 1) = 640 / 8 =  80MHz */
    IP_PERIPH_PLL->PLLODIV[3] = (IP_PERIPH_PLL->PLLODIV[3] & ~PLLDIG_PLLODIV_DIV_MASK) | PLLDIG_PLLODIV_DIV(8-1);   /* PHI3 = RFE_PLL / (ODIV_3 + 1) = 640 / 8 =  80MHz */
    IP_PERIPH_PLL->PLLODIV[4] = (IP_PERIPH_PLL->PLLODIV[4] & ~PLLDIG_PLLODIV_DIV_MASK) | PLLDIG_PLLODIV_DIV(4-1);   /* PHI4 = RFE_PLL / (ODIV_4 + 1) = 640 / 4 = 160MHz */
    IP_PERIPH_PLL->PLLODIV[5] = (IP_PERIPH_PLL->PLLODIV[5] & ~PLLDIG_PLLODIV_DIV_MASK) | PLLDIG_PLLODIV_DIV(2-1);   /* PHI5 = RFE_PLL / (ODIV_5 + 1) = 640 / 2 = 320MHz */
    IP_PERIPH_PLL->PLLODIV[6] = (IP_PERIPH_PLL->PLLODIV[6] & ~PLLDIG_PLLODIV_DIV_MASK) | PLLDIG_PLLODIV_DIV(2-1);   /* PHI6 = RFE_PLL / (ODIV_6 + 1) = 640 / 2 = 320MHz */
    IP_PERIPH_PLL->PLLODIV[7] = (IP_PERIPH_PLL->PLLODIV[7] & ~PLLDIG_PLLODIV_DIV_MASK) | PLLDIG_PLLODIV_DIV(8-1);   /* PHI7 = RFE_PLL / (ODIV_7 + 1) = 640 / 8 =  80MHz */
    IP_PERIPH_PLL->PLLODIV[8] = (IP_PERIPH_PLL->PLLODIV[8] & ~PLLDIG_PLLODIV_DIV_MASK) | PLLDIG_PLLODIV_DIV(0);     /* PHI8 Not Connected */
    IP_PERIPH_PLL->PLLODIV[9] = (IP_PERIPH_PLL->PLLODIV[9] & ~PLLDIG_PLLODIV_DIV_MASK) | PLLDIG_PLLODIV_DIV(3-1);   /* PHI9 = RFE_PLL / (ODIV_9 + 1) = 640 / 3 = 213.3MHz */
#endif

    IP_PERIPH_PLL->PLLCR = (IP_PERIPH_PLL->PLLCR & ~PLLDIG_PLLCR_PLLPD_MASK) | PLLDIG_PLLCR_PLLPD(0);          /* Enable Peripheral_PLL */

    /* Wait for PLL lock */
    while (((IP_PERIPH_PLL->PLLSR & PLLDIG_PLLSR_LOCK_MASK) == 0) && (timeout > 0)) { --timeout; }
    if (timeout <= 0)
    {
        result = INIT_PERIPHERAL_PLL_ERRNO; /* PLL_TIMEOUT */
    }
    else
    {
        /* Do nothing */
    }

    IP_PERIPH_PLL->PLLODIV[0] = (IP_PERIPH_PLL->PLLODIV[0] & ~PLLDIG_PLLODIV_DE_MASK) | PLLDIG_PLLODIV_DE(1);    /* Enable PHI0 output */
    IP_PERIPH_PLL->PLLODIV[1] = (IP_PERIPH_PLL->PLLODIV[1] & ~PLLDIG_PLLODIV_DE_MASK) | PLLDIG_PLLODIV_DE(1);    /* Enable PHI1 output */
    IP_PERIPH_PLL->PLLODIV[2] = (IP_PERIPH_PLL->PLLODIV[2] & ~PLLDIG_PLLODIV_DE_MASK) | PLLDIG_PLLODIV_DE(1);    /* Enable PHI2 output */
    IP_PERIPH_PLL->PLLODIV[3] = (IP_PERIPH_PLL->PLLODIV[3] & ~PLLDIG_PLLODIV_DE_MASK) | PLLDIG_PLLODIV_DE(1);    /* Enable PHI3 output */
    IP_PERIPH_PLL->PLLODIV[4] = (IP_PERIPH_PLL->PLLODIV[4] & ~PLLDIG_PLLODIV_DE_MASK) | PLLDIG_PLLODIV_DE(1);    /* Enable PHI4 output */
    IP_PERIPH_PLL->PLLODIV[5] = (IP_PERIPH_PLL->PLLODIV[5] & ~PLLDIG_PLLODIV_DE_MASK) | PLLDIG_PLLODIV_DE(1);    /* Enable PHI5 output */
    IP_PERIPH_PLL->PLLODIV[6] = (IP_PERIPH_PLL->PLLODIV[6] & ~PLLDIG_PLLODIV_DE_MASK) | PLLDIG_PLLODIV_DE(1);    /* Enable PHI6 output */
    IP_PERIPH_PLL->PLLODIV[7] = (IP_PERIPH_PLL->PLLODIV[7] & ~PLLDIG_PLLODIV_DE_MASK) | PLLDIG_PLLODIV_DE(1);    /* Enable PHI7 output */
    IP_PERIPH_PLL->PLLODIV[8] = (IP_PERIPH_PLL->PLLODIV[8] & ~PLLDIG_PLLODIV_DE_MASK) | PLLDIG_PLLODIV_DE(1);    /* Enable PHI8 output */
    IP_PERIPH_PLL->PLLODIV[9] = (IP_PERIPH_PLL->PLLODIV[9] & ~PLLDIG_PLLODIV_DE_MASK) | PLLDIG_PLLODIV_DE(1);    /* Enable PHI9 output */

    return result;
}

#ifdef S32R41
/*-----------------------------------------------------------------------*/
/* Initialize Peripheral_DFS                                             */
/* CLKIN = Periph(VCO) = 2000MHz                                         */
/* DFS1 = 318.58MHz (DDR80), DFS2 = 800MHz                               */
/*-----------------------------------------------------------------------*/
static int Init_Peripheral_DFS(void)
{
    volatile int timeout = 0xFFFF;
    volatile int result  = 0;

    IP_PERIPH_DFS->PORTRESET = (IP_PERIPH_DFS->PORTRESET & ~DFS_PORTRESET_RESET0_MASK) | DFS_PORTRESET_RESET0(1);      /* Disable DFS1 output */
    IP_PERIPH_DFS->PORTRESET = (IP_PERIPH_DFS->PORTRESET & ~DFS_PORTRESET_RESET1_MASK) | DFS_PORTRESET_RESET1(1);      /* Disable DFS2 output */

    while (((IP_PERIPH_DFS->PORTSR & DFS_PORTSR_PORTSTAT0_MASK) != 0) && (timeout > 0)) { --timeout; }  /* Wait for DFS1 to unlock */
    while (((IP_PERIPH_DFS->PORTSR & DFS_PORTSR_PORTSTAT1_MASK) != 0) && (timeout > 0)) { --timeout; }  /* Wait for DFS2 to unlock */

    IP_PERIPH_DFS->CTL = (IP_PERIPH_DFS->CTL & ~DFS_CTL_DFS_RESET_MASK) | DFS_CTL_DFS_RESET(1);                 /* Disable Peripheral_DFS */

    IP_PERIPH_DFS->DVPORT[0] = (IP_PERIPH_DFS->DVPORT[0] & ~DFS_DVPORT_MFI_MASK) | DFS_DVPORT_MFI(3);
    IP_PERIPH_DFS->DVPORT[0] = (IP_PERIPH_DFS->DVPORT[0] & ~DFS_DVPORT_MFN_MASK) | DFS_DVPORT_MFN(5);  /* DFS1 = CLKIN / 2 * (MFI + MFN / 36) = 2000 / 6.2(7) = 318.58MHz */

    IP_PERIPH_DFS->DVPORT[1] = (IP_PERIPH_DFS->DVPORT[1] & ~DFS_DVPORT_MFI_MASK) | DFS_DVPORT_MFI(1);
    IP_PERIPH_DFS->DVPORT[1] = (IP_PERIPH_DFS->DVPORT[1] & ~DFS_DVPORT_MFN_MASK) | DFS_DVPORT_MFN(9);  /* DFS2 = CLKIN / 2 * (MFI + MFN / 36) = 2000 / 2.50 = 800MHz */

    IP_PERIPH_DFS->CTL = (IP_PERIPH_DFS->CTL & ~DFS_CTL_DFS_RESET_MASK) | DFS_CTL_DFS_RESET(0);                 /* Enable Peripheral_DFS */

    IP_PERIPH_DFS->PORTRESET = (IP_PERIPH_DFS->PORTRESET & ~DFS_PORTRESET_RESET0_MASK) | DFS_PORTRESET_RESET0(0);     /* Enable DFS1 output */
    IP_PERIPH_DFS->PORTRESET = (IP_PERIPH_DFS->PORTRESET & ~DFS_PORTRESET_RESET1_MASK) | DFS_PORTRESET_RESET1(0);     /* Enable DFS2 output */

    while (((IP_PERIPH_DFS->PORTSR & DFS_PORTSR_PORTSTAT0_MASK) == 0) && (timeout > 0)) { --timeout; }  /* Wait for DFS1 to lock */
    while (((IP_PERIPH_DFS->PORTSR & DFS_PORTSR_PORTSTAT1_MASK) == 0) && (timeout > 0)) { --timeout; }  /* Wait for DFS2 to lock */

    if (timeout <= 0)
    {
        result = INIT_PERIPHERAL_DFS_ERRNO; /* PLL_TIMEOUT */
    }
    else
    {
        /* Do nothing */
    }

    return result;
}
#endif

/*-----------------------------------------------------------------------*/
/* Initialize MC_CGM                                                     */
/*-----------------------------------------------------------------------*/
/* S32R41_Clocking.xslx
*       Clock selector index    Clock source
*       0	                    FIRC_MUXED_CLK
*       2	                    FXOSC_CLK
*       3	                    REF_CLOCK_PLL_CLK
*       4	                    CORE_PLL_PHI0_CLK
*       5	                    CORE_PLL_PHI1_CLK
*       6	                    CORE_PLL_PHI2_CLK
*       7	                    CORE_PLL_PHI3_CLK
*       8	                    CORE_PLL_PHI4_CLK
*       9	                    CORE_PLL_PHI5_CLK
*       10	                    CORE_PLL_PHI6_CLK
*       11	                    CORE_PLL_PHI7_CLK
*       12	                    CORE_PLL_PHI8_CLK
*       13	                    CORE_PLL_PHI9_CLK
*       15	                    PERIPH_PLL_PHI8_CLK
*       16	                    PERIPH_PLL_PHI9_CLK
*       18	                    PERIPH_PLL_PHI0_CLK
*       19	                    PERIPH_PLL_PHI1_CLK
*       20	                    PERIPH_PLL_PHI2_CLK
*       21	                    PERIPH_PLL_PHI3_CLK
*       22	                    PERIPH_PLL_PHI4_CLK
*       23	                    PERIPH_PLL_PHI5_CLK
*       24	                    PERIPH_PLL_PHI6_CLK
*       25	                    PERIPH_PLL_PHI7_CLK
*       26	                    PERIPH_DFS1_CLK
*       27	                    PERIPH_DFS2_CLK
*       34	                    FTM_0_EXT_REF_CLK
*       37	                    GMAC_0_EXT_TX_CLK
*       38	                    GMAC_0_EXT_RX_CLK
*       39	                    GMAC_0_EXT_REF_CLK
*       44	                    GMAC_0_EXT_TS_CLK
*       45	                    GMAC_0_REF_DIV_CLK
*       46	                    TEST_CLK_MUX (for CLKOUT0)/reserved for customer
*       47	                    TEST_CLK_MUX (for CLKOUT1)/reserved for customer
*       50	                    AURORA_PLL_PHI2_CLK
*       53	                    GMAC_1_INT_REF_CLK
*       54	                    GMAC_1_REF_DIV_CLK
*       55	                    GMAC_1_EXT_TS_CLK
*       56	                    GMAC_1_EXT_TX_CLK
*       57	                    GMAC_1_EXT_RX_CLK
*       58	                    GMAC_1_EXT_REF_CLK
*       59	                    GMAC_0_SGMII_TX_CLK
*       60	                    GMAC_0_SGMII_RX_CLK
*       61	                    GMAC_0_SGMII_REF_CLK
*       63	                    REF_SPI_EXT_SCLK
*/
static int Init_MC_CGM(void)
{
    volatile int result = 0;

    result += Init_MC_CGM_0();
    result += Init_MC_CGM_1();
#ifdef S32R41
    result += Init_MC_CGM_2();
#endif
    result += Init_MC_CGM_3();

    return result;
}


/*-----------------------------------------------------------------------*/
/* Initialize MC_CGM_0                                                   */
/*-----------------------------------------------------------------------*/
/*                                 S32R41                                    /       SAF85xx
* MC_CGM_0_MUX_0_Source     = PERIPH_PLL_PHI0_CLK                            / PERIPH_PLL_PHI0_CLK
* MC_CGM_0_MUX_1_Source     = NC                                             / FIRC_MUXED_CLK
* MC_CGM_0_MUX_2_Source     = NC                                             / FIRC_MUXED_CLK
* MC_CGM_0_MUX_3_Source     = PERIPH_PLL_PHI1_CLK                            / PERIPH_PLL_PHI1_CLK
* MC_CGM_0_MUX_4_Source     = PERIPH_PLL_PHI7_CLK                            / PERIPH_PLL_PHI7_CLK
* MC_CGM_0_MUX_5_Source     = PERIPH_DFS1_CLK                                / PERIPH_PLL_PHI9_CLK
* MC_CGM_0_MUX_6_Source     = PERIPH_PLL_PHI5_CLK                            / PERIPH_PLL_PHI5_CLK
* MC_CGM_0_MUX_7_Source     = PERIPH_PLL_PHI2_CLK                            / PERIPH_PLL_PHI2_CLK
* MC_CGM_0_MUX_8_Source     = PERIPH_PLL_PHI3_CLK                            / PERIPH_PLL_PHI3_CLK
*
* SYS_CLK_Source            = MC_CGM_0_MUX_0          = 400MHz (S32R416LB: 250MHz)   / 320MHz
* SYS_DIV2_CLK_Source       = MC_CGM_0_MUX_0 / 2      = 200MHz (S32R416LB: 125MHz)   / 160MHz
* SYS_DIV4_CLK_Source       = MC_CGM_0_MUX_0 / 4      = 100MHz (S32R416LB: 62.5MHz)  / 80MHz
* SYS_DIV8_CLK_Source       = MC_CGM_0_MUX_0 / 8      = 50MHz  (S32R416LB: 31.25MHz) / 40MHz
* RT_DAPB_CLK_Source        = MC_CGM_0_MUX_0 / 8      = 50MHz  (S32R416LB: 31.25MHz) / 40MHz
* CLKOUT0_Source            = MC_CGM_0_MUX_1_DC_0     = Disabled             / 48MHz
* CLKOUT1_Source            = MC_CGM_0_MUX_2_DC_0     = Disabled             / 48MHz
* MC_CLK_Source             = MC_CGM_0_MUX_3          = 80Mhz                / 80MHz
* SPI_CLK_Source            = MC_CGM_0_MUX_4          = 100Mhz               / 160MHz
* QSPI_2X_CLK_Source        = MC_CGM_0_MUX_5_DC_0     = 159.29MHz (DDR80)    / 213.3MHz
* QSPI_1X_CLK_Source        = MC_CGM_0_MUX_5_DC_0 / 2 =  79.64MHz (DDR80)    / 106.6MHz
* GMAC_1_INT_REF_CLK_Source = MC_CGM_0_MUX_6 / 10     = 50MHz                / NC
* AURORA_TRACE_TEST_CLK_Source = MC_CGM_0_MUX_6       = NC                   / 320MHz
* CAN_TS_CLK_Source         = MC_CGM_0_MUX_6_DC_0     = 250MHz               / 320MHz
* TPIU_TRACE_CLK_Source     = MC_CGM_0_MUX_6_DC_0     = 250MHz               / 320MHz
* CAN_CHI_CLK_Source        = MC_CGM_0_MUX_6_DC_1     = 125MHz               / 40MHz
* FCCU_IPS_CLK_Source       = MC_CGM_0_MUX_6_DC_1     = 125MHz               / 40MHz
* CTU_IPS_CLK_Source        = MC_CGM_0_MUX_6_DC_1     = 125MHz               / 40MHz
* TMU_CLK_Source            = MC_CGM_0_MUX_6_DC_1     = 125MHz               / 40MHz (TMU issue running only 40-64MHz)
* TCLK_CLK_Source           = MC_CGM_0_MUX_6_DC_2     = 100MHz               / 80MHz
* DSPI_SCK_TST_CLK_Source   = MC_CGM_0_MUX_6_DC_3     = 62.5MHz              / 80MHz
* STCU_CLK_Source           = MC_CGM_0_MUX_6_DC_4     = 50MHz                / 80MHz
* DAPB_CLK_Source           = MC_CGM_0_MUX_6_DC_4     = 50MHz                / 80MHz
* CAN_PE_CLK_Source         = MC_CGM_0_MUX_7          = 80MHz                / 80MHz
* LIN_BAUD_CLK_Source       = MC_CGM_0_MUX_8          = 100MHz               / 80MHz
* LINFLEXD_CLK_Source       = MC_CGM_0_MUX_8 / 2      = 50MHz                / 40MHz
*/
static int Init_MC_CGM_0(void)
{
    volatile int timeout = 0xFFFF;
    volatile int result  = 0;

    /* Disable MC_CGM_0 dividers */
    IP_MC_CGM_0->MUX_1_DC_0 = (IP_MC_CGM_0->MUX_1_DC_0 & ~MC_CGM_0_MUX_1_DC_0_DE_MASK) | MC_CGM_0_MUX_1_DC_0_DE(0);
    IP_MC_CGM_0->MUX_2_DC_0 = (IP_MC_CGM_0->MUX_2_DC_0 & ~MC_CGM_0_MUX_2_DC_0_DE_MASK) | MC_CGM_0_MUX_2_DC_0_DE(0);
    IP_MC_CGM_0->MUX_5_DC_0 = (IP_MC_CGM_0->MUX_5_DC_0 & ~MC_CGM_0_MUX_5_DC_0_DE_MASK) | MC_CGM_0_MUX_5_DC_0_DE(0);
    IP_MC_CGM_0->MUX_6_DC_0 = (IP_MC_CGM_0->MUX_6_DC_0 & ~MC_CGM_0_MUX_6_DC_0_DE_MASK) | MC_CGM_0_MUX_6_DC_0_DE(0);
    IP_MC_CGM_0->MUX_6_DC_1 = (IP_MC_CGM_0->MUX_6_DC_1 & ~MC_CGM_0_MUX_6_DC_0_DE_MASK) | MC_CGM_0_MUX_6_DC_1_DE(0);
    IP_MC_CGM_0->MUX_6_DC_2 = (IP_MC_CGM_0->MUX_6_DC_2 & ~MC_CGM_0_MUX_6_DC_0_DE_MASK) | MC_CGM_0_MUX_6_DC_2_DE(0);
    IP_MC_CGM_0->MUX_6_DC_3 = (IP_MC_CGM_0->MUX_6_DC_3 & ~MC_CGM_0_MUX_6_DC_0_DE_MASK) | MC_CGM_0_MUX_6_DC_3_DE(0);
    IP_MC_CGM_0->MUX_6_DC_4 = (IP_MC_CGM_0->MUX_6_DC_4 & ~MC_CGM_0_MUX_6_DC_0_DE_MASK) | MC_CGM_0_MUX_6_DC_4_DE(0);

    /* Verify that we don't have switching in progress */
    while (((IP_MC_CGM_0->MUX_0_CSS & MC_CGM_0_MUX_0_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_0->MUX_3_CSS & MC_CGM_0_MUX_3_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_0->MUX_4_CSS & MC_CGM_0_MUX_4_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_0->MUX_5_CSS & MC_CGM_0_MUX_5_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_0->MUX_6_CSS & MC_CGM_0_MUX_6_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_0->MUX_7_CSS & MC_CGM_0_MUX_7_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_0->MUX_8_CSS & MC_CGM_0_MUX_8_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }

    /* Select MC_CGM_0 sources */
    IP_MC_CGM_0->MUX_0_CSC = (IP_MC_CGM_0->MUX_0_CSC & ~MC_CGM_0_MUX_0_CSC_SELCTL_MASK) | MC_CGM_0_MUX_0_CSC_SELCTL(18);
#ifdef SAF85
    /* CLKOUT */
    IP_MC_CGM_0->MUX_1_CSC |= MC_CGM_0_MUX_1_CSC_CG_MASK;
    IP_MC_CGM_0->MUX_2_CSC |= MC_CGM_0_MUX_2_CSC_CG_MASK;
    IP_MC_CGM_0->MUX_1_CSC = (IP_MC_CGM_0->MUX_1_CSC & ~MC_CGM_0_MUX_1_CSC_SELCTL_MASK) | MC_CGM_0_MUX_1_CSC_SELCTL(0);
    IP_MC_CGM_0->MUX_2_CSC = (IP_MC_CGM_0->MUX_2_CSC & ~MC_CGM_0_MUX_2_CSC_SELCTL_MASK) | MC_CGM_0_MUX_2_CSC_SELCTL(0);
    IP_MC_CGM_0->MUX_1_CSC &= ~MC_CGM_0_MUX_1_CSC_CG_MASK;
    IP_MC_CGM_0->MUX_2_CSC &= ~MC_CGM_0_MUX_2_CSC_CG_MASK;
    IP_MC_CGM_0->MUX_1_DC_0 = (IP_MC_CGM_0->MUX_1_DC_0 & ~MC_CGM_0_MUX_1_DC_0_DE_MASK) | MC_CGM_0_MUX_1_DC_0_DE(1);
    IP_MC_CGM_0->MUX_2_DC_0 = (IP_MC_CGM_0->MUX_2_DC_0 & ~MC_CGM_0_MUX_2_DC_0_DE_MASK) | MC_CGM_0_MUX_2_DC_0_DE(1);
#endif
    IP_MC_CGM_0->MUX_3_CSC = (IP_MC_CGM_0->MUX_3_CSC & ~MC_CGM_0_MUX_3_CSC_SELCTL_MASK) | MC_CGM_0_MUX_3_CSC_SELCTL(19);
    IP_MC_CGM_0->MUX_4_CSC = (IP_MC_CGM_0->MUX_4_CSC & ~MC_CGM_0_MUX_4_CSC_SELCTL_MASK) | MC_CGM_0_MUX_4_CSC_SELCTL(25);
#ifdef S32R41
    IP_MC_CGM_0->MUX_5_CSC = (IP_MC_CGM_0->MUX_5_CSC & ~MC_CGM_0_MUX_5_CSC_SELCTL_MASK) | MC_CGM_0_MUX_5_CSC_SELCTL(26);
#else
    IP_MC_CGM_0->MUX_5_CSC = (IP_MC_CGM_0->MUX_5_CSC & ~MC_CGM_0_MUX_5_CSC_SELCTL_MASK) | MC_CGM_0_MUX_5_CSC_SELCTL(16);
#endif
    IP_MC_CGM_0->MUX_6_CSC = (IP_MC_CGM_0->MUX_6_CSC & ~MC_CGM_0_MUX_6_CSC_SELCTL_MASK) | MC_CGM_0_MUX_6_CSC_SELCTL(23);
    IP_MC_CGM_0->MUX_7_CSC = (IP_MC_CGM_0->MUX_7_CSC & ~MC_CGM_0_MUX_7_CSC_SELCTL_MASK) | MC_CGM_0_MUX_7_CSC_SELCTL(20);
    IP_MC_CGM_0->MUX_8_CSC = (IP_MC_CGM_0->MUX_8_CSC & ~MC_CGM_0_MUX_8_CSC_SELCTL_MASK) | MC_CGM_0_MUX_8_CSC_SELCTL(21);

    /* Switch MC_CGM_0 sources */
    IP_MC_CGM_0->MUX_0_CSC = (IP_MC_CGM_0->MUX_0_CSC & ~MC_CGM_0_MUX_0_CSC_CLK_SW_MASK) | MC_CGM_0_MUX_0_CSC_CLK_SW(1);
    IP_MC_CGM_0->MUX_3_CSC = (IP_MC_CGM_0->MUX_3_CSC & ~MC_CGM_0_MUX_3_CSC_CLK_SW_MASK) | MC_CGM_0_MUX_3_CSC_CLK_SW(1);
    IP_MC_CGM_0->MUX_4_CSC = (IP_MC_CGM_0->MUX_4_CSC & ~MC_CGM_0_MUX_4_CSC_CLK_SW_MASK) | MC_CGM_0_MUX_4_CSC_CLK_SW(1);
    IP_MC_CGM_0->MUX_5_CSC = (IP_MC_CGM_0->MUX_5_CSC & ~MC_CGM_0_MUX_5_CSC_CLK_SW_MASK) | MC_CGM_0_MUX_5_CSC_CLK_SW(1);
    IP_MC_CGM_0->MUX_6_CSC = (IP_MC_CGM_0->MUX_6_CSC & ~MC_CGM_0_MUX_6_CSC_CLK_SW_MASK) | MC_CGM_0_MUX_6_CSC_CLK_SW(1);
    IP_MC_CGM_0->MUX_7_CSC = (IP_MC_CGM_0->MUX_7_CSC & ~MC_CGM_0_MUX_7_CSC_CLK_SW_MASK) | MC_CGM_0_MUX_7_CSC_CLK_SW(1);
    IP_MC_CGM_0->MUX_8_CSC = (IP_MC_CGM_0->MUX_8_CSC & ~MC_CGM_0_MUX_8_CSC_CLK_SW_MASK) | MC_CGM_0_MUX_8_CSC_CLK_SW(1);

    /* Wait for acknowledgement to be cleared */
    while (((IP_MC_CGM_0->MUX_0_CSS & MC_CGM_0_MUX_0_CSS_CLK_SW_MASK) == 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_0->MUX_3_CSS & MC_CGM_0_MUX_3_CSS_CLK_SW_MASK) == 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_0->MUX_4_CSS & MC_CGM_0_MUX_4_CSS_CLK_SW_MASK) == 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_0->MUX_5_CSS & MC_CGM_0_MUX_5_CSS_CLK_SW_MASK) == 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_0->MUX_6_CSS & MC_CGM_0_MUX_6_CSS_CLK_SW_MASK) == 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_0->MUX_7_CSS & MC_CGM_0_MUX_7_CSS_CLK_SW_MASK) == 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_0->MUX_8_CSS & MC_CGM_0_MUX_8_CSS_CLK_SW_MASK) == 0) && (timeout > 0)) { --timeout; }

    /* Verify that clock switch completed */
    while (((IP_MC_CGM_0->MUX_0_CSS & MC_CGM_0_MUX_0_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_0->MUX_3_CSS & MC_CGM_0_MUX_3_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_0->MUX_4_CSS & MC_CGM_0_MUX_4_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_0->MUX_5_CSS & MC_CGM_0_MUX_5_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_0->MUX_6_CSS & MC_CGM_0_MUX_6_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_0->MUX_7_CSS & MC_CGM_0_MUX_7_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_0->MUX_8_CSS & MC_CGM_0_MUX_8_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }

    /* Select MC_CGM_0 dividers */
#ifdef S32R41
    IP_MC_CGM_0->MUX_5_DC_0 = (IP_MC_CGM_0->MUX_5_DC_0 & ~MC_CGM_0_MUX_5_DC_0_DIV_MASK) | MC_CGM_0_MUX_5_DC_0_DIV(2-1);
    IP_MC_CGM_0->MUX_6_DC_0 = (IP_MC_CGM_0->MUX_6_DC_0 & ~MC_CGM_0_MUX_6_DC_0_DIV_MASK) | MC_CGM_0_MUX_6_DC_0_DIV(2-1);
    IP_MC_CGM_0->MUX_6_DC_1 = (IP_MC_CGM_0->MUX_6_DC_1 & ~MC_CGM_0_MUX_6_DC_1_DIV_MASK) | MC_CGM_0_MUX_6_DC_1_DIV(4-1);
    IP_MC_CGM_0->MUX_6_DC_2 = (IP_MC_CGM_0->MUX_6_DC_2 & ~MC_CGM_0_MUX_6_DC_2_DIV_MASK) | MC_CGM_0_MUX_6_DC_2_DIV(5-1);
    IP_MC_CGM_0->MUX_6_DC_3 = (IP_MC_CGM_0->MUX_6_DC_3 & ~MC_CGM_0_MUX_6_DC_3_DIV_MASK) | MC_CGM_0_MUX_6_DC_3_DIV(8-1);
    IP_MC_CGM_0->MUX_6_DC_4 = (IP_MC_CGM_0->MUX_6_DC_4 & ~MC_CGM_0_MUX_6_DC_4_DIV_MASK) | MC_CGM_0_MUX_6_DC_4_DIV(10-1);
#else
    IP_MC_CGM_0->MUX_5_DC_0 = (IP_MC_CGM_0->MUX_5_DC_0 & ~MC_CGM_0_MUX_5_DC_0_DIV_MASK) | MC_CGM_0_MUX_5_DC_0_DIV(1-1);
    IP_MC_CGM_0->MUX_6_DC_0 = (IP_MC_CGM_0->MUX_6_DC_0 & ~MC_CGM_0_MUX_6_DC_0_DIV_MASK) | MC_CGM_0_MUX_6_DC_0_DIV(1-1);
    IP_MC_CGM_0->MUX_6_DC_1 = (IP_MC_CGM_0->MUX_6_DC_1 & ~MC_CGM_0_MUX_6_DC_1_DIV_MASK) | MC_CGM_0_MUX_6_DC_1_DIV(8-1);
    IP_MC_CGM_0->MUX_6_DC_2 = (IP_MC_CGM_0->MUX_6_DC_2 & ~MC_CGM_0_MUX_6_DC_2_DIV_MASK) | MC_CGM_0_MUX_6_DC_2_DIV(4-1);
    IP_MC_CGM_0->MUX_6_DC_3 = (IP_MC_CGM_0->MUX_6_DC_3 & ~MC_CGM_0_MUX_6_DC_3_DIV_MASK) | MC_CGM_0_MUX_6_DC_3_DIV(4-1);
    IP_MC_CGM_0->MUX_6_DC_4 = (IP_MC_CGM_0->MUX_6_DC_4 & ~MC_CGM_0_MUX_6_DC_4_DIV_MASK) | MC_CGM_0_MUX_6_DC_4_DIV(4-1);
#endif

    /* Wait until divider configuration update has finished */
    while (((IP_MC_CGM_0->MUX_1_DIV_UPD_STAT & MC_CGM_0_MUX_1_DIV_UPD_STAT_DIV_STAT_MASK) != 0) && (timeout > 0))  { --timeout; }
    while (((IP_MC_CGM_0->MUX_2_DIV_UPD_STAT & MC_CGM_0_MUX_2_DIV_UPD_STAT_DIV_STAT_MASK) != 0) && (timeout > 0))  { --timeout; }
    while (((IP_MC_CGM_0->MUX_5_DIV_UPD_STAT & MC_CGM_0_MUX_5_DIV_UPD_STAT_DIV_STAT_MASK) != 0) && (timeout > 0))  { --timeout; }
    while (((IP_MC_CGM_0->MUX_6_DIV_UPD_STAT & MC_CGM_0_MUX_6_DIV_UPD_STAT_DIV_STAT_MASK) != 0) && (timeout > 0))  { --timeout; }

    /* Enable MC_CGM_0 dividers */
    IP_MC_CGM_0->MUX_5_DC_0 = (IP_MC_CGM_0->MUX_5_DC_0 & ~MC_CGM_0_MUX_5_DC_0_DE_MASK) | MC_CGM_0_MUX_5_DC_0_DE(1);
    IP_MC_CGM_0->MUX_6_DC_0 = (IP_MC_CGM_0->MUX_6_DC_0 & ~MC_CGM_0_MUX_6_DC_0_DE_MASK) | MC_CGM_0_MUX_6_DC_0_DE(1);
    IP_MC_CGM_0->MUX_6_DC_1 = (IP_MC_CGM_0->MUX_6_DC_1 & ~MC_CGM_0_MUX_6_DC_0_DE_MASK) | MC_CGM_0_MUX_6_DC_1_DE(1);
    IP_MC_CGM_0->MUX_6_DC_2 = (IP_MC_CGM_0->MUX_6_DC_2 & ~MC_CGM_0_MUX_6_DC_0_DE_MASK) | MC_CGM_0_MUX_6_DC_2_DE(1);
    IP_MC_CGM_0->MUX_6_DC_3 = (IP_MC_CGM_0->MUX_6_DC_3 & ~MC_CGM_0_MUX_6_DC_0_DE_MASK) | MC_CGM_0_MUX_6_DC_3_DE(1);
    IP_MC_CGM_0->MUX_6_DC_4 = (IP_MC_CGM_0->MUX_6_DC_4 & ~MC_CGM_0_MUX_6_DC_0_DE_MASK) | MC_CGM_0_MUX_6_DC_4_DE(1);

    if (timeout <= 0)
    {
        result = INIT_MC_CGM_0_ERRNO;
    }
    else
    {
        /* Do nothing */
    }

    return result;
}

/*-----------------------------------------------------------------------*/
/* Initialize MC_CGM_1                                                   */
/*-----------------------------------------------------------------------*/
/*                                 S32R41                                    /       SAF85xx
* MC_CGM_1_MUX_0_Source      = CORE_PLL_PHI0_CLK                             / CORE_PLL_PHI0_CLK
* MC_CGM_1_MUX_1_Source      = CORE_PLL_PHI1_CLK                             / CORE_PLL_PHI1_CLK
* MC_CGM_1_MUX_2_Source      = CORE_PLL_PHI2_CLK                             / CORE_PLL_PHI2_CLK
* MC_CGM_1_MUX_3_Source      = CORE_PLL_PHI3_CLK                             / CORE_PLL_PHI3_CLK
* MC_CGM_1_MUX_4_Source      = CORE_PLL_PHI4_CLK                             / CORE_PLL_PHI4_CLK
* MC_CGM_1_MUX_5_Source      = FIRC                                          / CORE_PLL_PHI8_CLK
* MC_CGM_1_MUX_6_Source      = FIRC                                          / CORE_PLL_PHI9_CLK
*
* CORE_CLK_Source            = MC_CGM_1_MUX_0          = 800MHz (S32R416LB: 480MHz)    / 320MHz
* A53_CORE_DIV2_CLK_Source   = MC_CGM_1_MUX_0 / 2      = 400MHz (S32R416LB: 240MHz)    / 160MHz
* A53_CORE_DIV4_CLK_Source   = MC_CGM_1_MUX_0 / 4      = NC                            / 80MHz
* A53_CORE_DIV10_CLK_Source  = MC_CGM_1_MUX_0 / 10     = 80MHz  (S32R416LB: 48MHz)     / NC
* ACCEL_CLK_Source           = MC_CGM_1_MUX_1          = 600MHz (S32R416LB: 400MHz)    / 320MHz
* ACCEL_DIV3_CLK_Source      = MC_CGM_1_MUX_1 / 3      = 200MHz (S32R416LB: 133.33MHz) / NC
* ACCEL_DIV4_CLK_Source      = MC_CGM_1_MUX_1 / 4      = NC                            / 80MHz
* ACCEL_XBAR_CLK_Source      = MC_CGM_1_MUX_2          = 400MHz (S32R416LB: 300MHz)    / 320MHz
* ACCEL_XBAR_DIV2_CLK_Source = MC_CGM_1_MUX_2 / 2      = 200MHz (S32R416LB: 150MHz)    / 160MHz
* ACCEL_XBAR_DIV4_CLK_Source = MC_CGM_1_MUX_2 / 4      = 100MHz (S32R416LB: 75MHz)     / 80MHz
* ACCEL_XBAR_DIV8_CLK_Source = MC_CGM_1_MUX_2 / 8      = 50MHz  (S32R416LB: 37.5MHz)   / 40MHz
* AP_DAPB_CLK_Source         = MC_CGM_1_MUX_2 / 8      = 50MHz  (S32R416LB: 37.5MHz)   / 40MHz
* CTE_CLK_Source             = MC_CGM_1_MUX_3          = 80MHz               / 80MHz
* CSI_IPS_CLK_Source         = MC_CGM_1_MUX_3          = 80MHz               / NC
* CSI_CFG_CLK_Source         = MC_CGM_1_MUX_4_DC_0     = 20MHz               / NC
* CSI_TXCLK_ESC_Source       = MC_CGM_1_MUX_4_DC_1     = 10MHz               / NC
* NOC_TRACE_CLK_Source       = MC_CGM_1_MUX_5          = 48MHz               / 640MHz
* LBIST_CLK_Source           = MC_CGM_1_MUX_6_DC_0     = 48MHz               / 160MHz
*/
static int Init_MC_CGM_1(void)
{
    volatile int timeout = 0xFFFF;
    volatile int result  = 0;

    /* Disable MC_CGM_1 dividers */
#ifdef S32R41
    IP_MC_CGM_1->MUX_4_DC_0 = (IP_MC_CGM_1->MUX_4_DC_0 & ~MC_CGM_MUX_4_DC_0_DE_MASK) | MC_CGM_MUX_4_DC_0_DE(0);
    IP_MC_CGM_1->MUX_4_DC_1 = (IP_MC_CGM_1->MUX_4_DC_1 & ~MC_CGM_MUX_4_DC_1_DE_MASK) | MC_CGM_MUX_4_DC_1_DE(0);
#endif
    IP_MC_CGM_1->MUX_6_DC_0 = (IP_MC_CGM_1->MUX_6_DC_0 & ~MC_CGM_MUX_6_DC_0_DE_MASK) | MC_CGM_MUX_6_DC_0_DE(0);

    /* Verify that we don't have switching in progress */
    while (((IP_MC_CGM_1->MUX_0_CSS & MC_CGM_MUX_0_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_1->MUX_1_CSS & MC_CGM_MUX_1_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_1->MUX_2_CSC & MC_CGM_MUX_2_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_1->MUX_3_CSS & MC_CGM_MUX_3_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
#ifdef S32R41
    while (((IP_MC_CGM_1->MUX_4_CSS & MC_CGM_MUX_4_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
#endif
    while (((IP_MC_CGM_1->MUX_5_CSS & MC_CGM_MUX_5_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_1->MUX_6_CSS & MC_CGM_MUX_6_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }

    /* Select MC_CGM_1 sources */
    IP_MC_CGM_1->MUX_0_CSC = (IP_MC_CGM_1->MUX_0_CSC & ~MC_CGM_MUX_0_CSC_SELCTL_MASK) | MC_CGM_MUX_0_CSC_SELCTL(4);
    IP_MC_CGM_1->MUX_1_CSC = (IP_MC_CGM_1->MUX_1_CSC & ~MC_CGM_MUX_1_CSC_SELCTL_MASK) | MC_CGM_MUX_1_CSC_SELCTL(5);
    IP_MC_CGM_1->MUX_2_CSC = (IP_MC_CGM_1->MUX_2_CSC & ~MC_CGM_MUX_2_CSC_SELCTL_MASK) | MC_CGM_MUX_2_CSC_SELCTL(6);
    IP_MC_CGM_1->MUX_3_CSC = (IP_MC_CGM_1->MUX_3_CSC & ~MC_CGM_MUX_3_CSC_SELCTL_MASK) | MC_CGM_MUX_3_CSC_SELCTL(7);
#ifdef S32R41
    IP_MC_CGM_1->MUX_4_CSC = (IP_MC_CGM_1->MUX_4_CSC & ~MC_CGM_MUX_4_CSC_SELCTL_MASK) | MC_CGM_MUX_4_CSC_SELCTL(8);
    IP_MC_CGM_1->MUX_5_CSC = (IP_MC_CGM_1->MUX_5_CSC & ~MC_CGM_MUX_5_CSC_SELCTL_MASK) | MC_CGM_MUX_5_CSC_SELCTL(0);
    IP_MC_CGM_1->MUX_6_CSC = (IP_MC_CGM_1->MUX_6_CSC & ~MC_CGM_MUX_6_CSC_SELCTL_MASK) | MC_CGM_MUX_6_CSC_SELCTL(0);
#else
    IP_MC_CGM_1->MUX_5_CSC = (IP_MC_CGM_1->MUX_5_CSC & ~MC_CGM_MUX_5_CSC_SELCTL_MASK) | MC_CGM_MUX_5_CSC_SELCTL(12);
    IP_MC_CGM_1->MUX_6_CSC = (IP_MC_CGM_1->MUX_6_CSC & ~MC_CGM_MUX_6_CSC_SELCTL_MASK) | MC_CGM_MUX_6_CSC_SELCTL(13);
#endif

    /* Switch MC_CGM_1 sources */
    IP_MC_CGM_1->MUX_0_CSC = (IP_MC_CGM_1->MUX_0_CSC & ~MC_CGM_MUX_0_CSC_CLK_SW_MASK) | MC_CGM_MUX_0_CSC_CLK_SW(1);
    IP_MC_CGM_1->MUX_1_CSC = (IP_MC_CGM_1->MUX_1_CSC & ~MC_CGM_MUX_1_CSC_CLK_SW_MASK) | MC_CGM_MUX_1_CSC_CLK_SW(1);
    IP_MC_CGM_1->MUX_2_CSC = (IP_MC_CGM_1->MUX_2_CSC & ~MC_CGM_MUX_2_CSC_CLK_SW_MASK) | MC_CGM_MUX_2_CSC_CLK_SW(1);
    IP_MC_CGM_1->MUX_3_CSC = (IP_MC_CGM_1->MUX_3_CSC & ~MC_CGM_MUX_3_CSC_CLK_SW_MASK) | MC_CGM_MUX_3_CSC_CLK_SW(1);
#ifdef S32R41
    IP_MC_CGM_1->MUX_4_CSC = (IP_MC_CGM_1->MUX_4_CSC & ~MC_CGM_MUX_4_CSC_CLK_SW_MASK) | MC_CGM_MUX_4_CSC_CLK_SW(1);
#endif
    IP_MC_CGM_1->MUX_5_CSC = (IP_MC_CGM_1->MUX_5_CSC & ~MC_CGM_MUX_5_CSC_CLK_SW_MASK) | MC_CGM_MUX_5_CSC_CLK_SW(1);
    IP_MC_CGM_1->MUX_6_CSC = (IP_MC_CGM_1->MUX_6_CSC & ~MC_CGM_MUX_6_CSC_CLK_SW_MASK) | MC_CGM_MUX_6_CSC_CLK_SW(1);

    /* Wait for acknowledgement to be cleared */
    while (((IP_MC_CGM_1->MUX_0_CSS & MC_CGM_MUX_0_CSS_CLK_SW_MASK) == 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_1->MUX_1_CSS & MC_CGM_MUX_1_CSS_CLK_SW_MASK) == 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_1->MUX_2_CSS & MC_CGM_MUX_2_CSS_CLK_SW_MASK) == 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_1->MUX_3_CSS & MC_CGM_MUX_3_CSS_CLK_SW_MASK) == 0) && (timeout > 0)) { --timeout; }
#ifdef S32R41
    while (((IP_MC_CGM_1->MUX_4_CSS & MC_CGM_MUX_4_CSS_CLK_SW_MASK) == 0) && (timeout > 0)) { --timeout; }
#endif
    while (((IP_MC_CGM_1->MUX_5_CSS & MC_CGM_MUX_5_CSS_CLK_SW_MASK) == 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_1->MUX_6_CSS & MC_CGM_MUX_6_CSS_CLK_SW_MASK) == 0) && (timeout > 0)) { --timeout; }

    /* Verify that clock switch completed */
    while (((IP_MC_CGM_1->MUX_0_CSS & MC_CGM_MUX_0_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_1->MUX_1_CSS & MC_CGM_MUX_1_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_1->MUX_2_CSS & MC_CGM_MUX_2_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_1->MUX_3_CSS & MC_CGM_MUX_3_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
#ifdef S32R41
    while (((IP_MC_CGM_1->MUX_4_CSS & MC_CGM_MUX_4_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
#endif
    while (((IP_MC_CGM_1->MUX_5_CSS & MC_CGM_MUX_5_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_1->MUX_6_CSS & MC_CGM_MUX_6_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }

    /* Select MC_CGM_1 dividers */
#ifdef S32R41
    IP_MC_CGM_1->MUX_4_DC_0 = (IP_MC_CGM_1->MUX_4_DC_0 & ~MC_CGM_MUX_4_DC_0_DIV_MASK) | MC_CGM_MUX_4_DC_0_DIV(2-1);
    IP_MC_CGM_1->MUX_4_DC_1 = (IP_MC_CGM_1->MUX_4_DC_1 & ~MC_CGM_MUX_4_DC_1_DIV_MASK) | MC_CGM_MUX_4_DC_1_DIV(4-1);
    IP_MC_CGM_1->MUX_6_DC_0 = (IP_MC_CGM_1->MUX_6_DC_0 & ~MC_CGM_MUX_6_DC_0_DIV_MASK) | MC_CGM_MUX_6_DC_0_DIV(1-1);
#else
    IP_MC_CGM_1->MUX_6_DC_0 = (IP_MC_CGM_1->MUX_6_DC_0 & ~MC_CGM_MUX_6_DC_0_DIV_MASK) | MC_CGM_MUX_6_DC_0_DIV(2-1);
#endif

    /* Wait until divider configuration update has finished */
#ifdef S32R41
    while (((IP_MC_CGM_1->MUX_4_DIV_UPD_STAT & MC_CGM_MUX_4_DIV_UPD_STAT_DIV_STAT_MASK) != 0) && (timeout > 0))  { --timeout; }
#endif
    while (((IP_MC_CGM_1->MUX_6_DIV_UPD_STAT & MC_CGM_MUX_6_DIV_UPD_STAT_DIV_STAT_MASK) != 0) && (timeout > 0))  { --timeout; }

    /* Enable MC_CGM_1 dividers */
#ifdef S32R41
    IP_MC_CGM_1->MUX_4_DC_0 = (IP_MC_CGM_1->MUX_4_DC_0 & ~MC_CGM_MUX_4_DC_0_DE_MASK) | MC_CGM_MUX_4_DC_0_DE(1);
    IP_MC_CGM_1->MUX_4_DC_1 = (IP_MC_CGM_1->MUX_4_DC_1 & ~MC_CGM_MUX_4_DC_1_DE_MASK) | MC_CGM_MUX_4_DC_1_DE(1);
#endif
    IP_MC_CGM_1->MUX_6_DC_0 = (IP_MC_CGM_1->MUX_6_DC_0 & ~MC_CGM_MUX_6_DC_0_DE_MASK) | MC_CGM_MUX_6_DC_0_DE(1);

    if (timeout <= 0)
    {
        result = INIT_MC_CGM_1_ERRNO;
    }
    else
    {
        /* Do nothing */
    }

    return result;
}

#ifdef S32R41
/*-----------------------------------------------------------------------*/
/* Initialize MC_CGM_2 (GMAC1 - RGMII - X-S32R41-EVB)                    */
/*-----------------------------------------------------------------------*/
/*
* MC_CGM_2_MUX_0_Source      = Reserved
* MC_CGM_2_MUX_1_Source      = PERIPH_PLL_PHI4_CLK
* MC_CGM_2_MUX_2_Source      = PERIPH_PLL_PHI5_CLK
* MC_CGM_2_MUX_3_Source      = GMAC_1_INT_REF_CLK  (Not used in RGMII)
* MC_CGM_2_MUX_4_Source      = GMAC_1_EXT_RX_CLK
*
* GMAC_1_TS_CLK_Source       = MC_CGM_2_MUX_1_DC_0     = 200MHz
* GMAC_1_TX_CLK_Source       = MC_CGM_2_MUX_2_DC_0     = 125MHz
* GMAC_1_REF_CLK_Source      = MC_CGM_2_MUX_3          = 50MHz
* GMAC_1_REF_DIV_CLK_Source  = MC_CGM_2_MUX_3_DC_0     = 25MHz
* GMAC_1_RX_CLK_Source       = MC_CGM_2_MUX_4          = 125MHz (Externally Provided)
*/
static int Init_MC_CGM_2(void)
{
    volatile int timeout = 0xFFFF;
    volatile int result  = 0;

    /* Disable MC_CGM_2 dividers */
    IP_MC_CGM_2->MUX_1_DC_0 = (IP_MC_CGM_2->MUX_1_DC_0 & ~MC_CGM_2_MUX_1_DC_0_DE_MASK) | MC_CGM_2_MUX_1_DC_0_DE(0);
    IP_MC_CGM_2->MUX_2_DC_0 = (IP_MC_CGM_2->MUX_2_DC_0 & ~MC_CGM_2_MUX_2_DC_0_DE_MASK) | MC_CGM_2_MUX_2_DC_0_DE(0);
    IP_MC_CGM_2->MUX_3_DC_0 = (IP_MC_CGM_2->MUX_3_DC_0 & ~MC_CGM_2_MUX_3_DC_0_DE_MASK) | MC_CGM_2_MUX_3_DC_0_DE(0);

    /* Verify that we don't have switching in progress */
    while (((IP_MC_CGM_2->MUX_1_CSS & MC_CGM_2_MUX_1_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_2->MUX_2_CSC & MC_CGM_2_MUX_2_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_2->MUX_3_CSS & MC_CGM_2_MUX_3_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_2->MUX_4_CSS & MC_CGM_2_MUX_4_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }

    /* Select MC_CGM_2 sources */
    IP_MC_CGM_2->MUX_1_CSC = (IP_MC_CGM_2->MUX_1_CSC & ~MC_CGM_2_MUX_1_CSC_SELCTL_MASK) | MC_CGM_2_MUX_1_CSC_SELCTL(22);
    IP_MC_CGM_2->MUX_2_CSC = (IP_MC_CGM_2->MUX_2_CSC & ~MC_CGM_2_MUX_2_CSC_SELCTL_MASK) | MC_CGM_2_MUX_2_CSC_SELCTL(23);
    IP_MC_CGM_2->MUX_3_CSC = (IP_MC_CGM_2->MUX_3_CSC & ~MC_CGM_2_MUX_3_CSC_SELCTL_MASK) | MC_CGM_2_MUX_3_CSC_SELCTL(53);
    IP_MC_CGM_2->MUX_4_CSC = (IP_MC_CGM_2->MUX_4_CSC & ~MC_CGM_2_MUX_4_CSC_SELCTL_MASK) | MC_CGM_2_MUX_4_CSC_SELCTL(57);

    /* Switch MC_CGM_2 sources */
    IP_MC_CGM_2->MUX_1_CSC = (IP_MC_CGM_2->MUX_1_CSC & ~MC_CGM_2_MUX_1_CSC_CLK_SW_MASK) | MC_CGM_2_MUX_1_CSC_CLK_SW(1);
    IP_MC_CGM_2->MUX_2_CSC = (IP_MC_CGM_2->MUX_2_CSC & ~MC_CGM_2_MUX_2_CSC_CLK_SW_MASK) | MC_CGM_2_MUX_2_CSC_CLK_SW(1);
    IP_MC_CGM_2->MUX_3_CSC = (IP_MC_CGM_2->MUX_3_CSC & ~MC_CGM_2_MUX_3_CSC_CLK_SW_MASK) | MC_CGM_2_MUX_3_CSC_CLK_SW(1);
    IP_MC_CGM_2->MUX_4_CSC = (IP_MC_CGM_2->MUX_4_CSC & ~MC_CGM_2_MUX_4_CSC_CLK_SW_MASK) | MC_CGM_2_MUX_4_CSC_CLK_SW(1);

    /* Wait for acknowledgement to be cleared */
    while (((IP_MC_CGM_2->MUX_1_CSS & MC_CGM_2_MUX_1_CSS_CLK_SW_MASK) == 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_2->MUX_2_CSS & MC_CGM_2_MUX_2_CSS_CLK_SW_MASK) == 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_2->MUX_3_CSS & MC_CGM_2_MUX_3_CSS_CLK_SW_MASK) == 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_2->MUX_4_CSS & MC_CGM_2_MUX_4_CSS_CLK_SW_MASK) == 0) && (timeout > 0)) { --timeout; }

    /* Verify that clock switch completed */
    while (((IP_MC_CGM_2->MUX_1_CSS & MC_CGM_2_MUX_1_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_2->MUX_2_CSS & MC_CGM_2_MUX_2_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_2->MUX_3_CSS & MC_CGM_2_MUX_3_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_2->MUX_4_CSS & MC_CGM_2_MUX_4_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }

    /* Select MC_CGM_2 dividers */
    IP_MC_CGM_2->MUX_1_DC_0 = (IP_MC_CGM_2->MUX_1_DC_0 & ~MC_CGM_2_MUX_1_DC_0_DIV_MASK) | MC_CGM_2_MUX_1_DC_0_DIV(1-1);
    IP_MC_CGM_2->MUX_2_DC_0 = (IP_MC_CGM_2->MUX_2_DC_0 & ~MC_CGM_2_MUX_2_DC_0_DIV_MASK) | MC_CGM_2_MUX_2_DC_0_DIV(4-1);
    IP_MC_CGM_2->MUX_3_DC_0 = (IP_MC_CGM_2->MUX_3_DC_0 & ~MC_CGM_2_MUX_3_DC_0_DIV_MASK) | MC_CGM_2_MUX_3_DC_0_DIV(2-1);

    /* Wait until divider configuration update has finished */
    while (((IP_MC_CGM_2->MUX_1_DIV_UPD_STAT & MC_CGM_2_MUX_1_DIV_UPD_STAT_DIV_STAT_MASK) != 0) && (timeout > 0))  { --timeout; }
    while (((IP_MC_CGM_2->MUX_2_DIV_UPD_STAT & MC_CGM_2_MUX_2_DIV_UPD_STAT_DIV_STAT_MASK) != 0) && (timeout > 0))  { --timeout; }
    while (((IP_MC_CGM_2->MUX_3_DIV_UPD_STAT & MC_CGM_2_MUX_3_DIV_UPD_STAT_DIV_STAT_MASK) != 0) && (timeout > 0))  { --timeout; }

    /* Enable MC_CGM_2 dividers */
    IP_MC_CGM_2->MUX_1_DC_0 = (IP_MC_CGM_2->MUX_1_DC_0 & ~MC_CGM_2_MUX_1_DC_0_DE_MASK) | MC_CGM_2_MUX_1_DC_0_DE(1);
    IP_MC_CGM_2->MUX_2_DC_0 = (IP_MC_CGM_2->MUX_2_DC_0 & ~MC_CGM_2_MUX_2_DC_0_DE_MASK) | MC_CGM_2_MUX_2_DC_0_DE(1);
    IP_MC_CGM_2->MUX_3_DC_0 = (IP_MC_CGM_2->MUX_3_DC_0 & ~MC_CGM_2_MUX_3_DC_0_DE_MASK) | MC_CGM_2_MUX_3_DC_0_DE(1);

    if (timeout <= 0)
    {
        result = INIT_MC_CGM_2_ERRNO;
    }
    else
    {
        /* Do nothing */
    }

    return result;
}
#endif

/*-----------------------------------------------------------------------*/
/* Initialize MC_CGM_3 (GMAC0 - RMII - X-S32R41-EVB)                     */
/*-----------------------------------------------------------------------*/
/*                                 S32R41                                       /       SAF85xx
* MC_CGM_3_MUX_0_Source      = PERIPH_PLL_PHI1_CLK                              / PERIPH_PLL_PHI1_CLK
* MC_CGM_3_MUX_1_Source      = PERIPH_PLL_PHI4_CLK                              / PERIPH_PLL_PHI4_CLK
* MC_CGM_3_MUX_2_Source      = GMAC_0_REF_DIV_CLK                               / FIRC_MUXED
* MC_CGM_3_MUX_3_Source      = PERIPH_PLL_PHI6_CLK                              / NC
* MC_CGM_3_MUX_4_Source      = GMAC_0_REF_DIV_CLK                               / FIRC_MUXED
*
* FTM0_EXT_CLK_Source        = MC_CGM_3_MUX_0_DC_0 = 80MHz                      / 80MHz
* GMAC_0_TS_CLK_Source       = MC_CGM_3_MUX_1_DC_0 = 200MHz                     / 160MHz
* GMAC_0_TX_CLK_Source       = MC_CGM_3_MUX_2      = 25MHz                      / 48MHz
* GMAC_0_REF_CLK_Source      = MC_CGM_3_MUX_3      = 50MHz (Internally Clocked) / NC
* GMAC_0_REF_DIV_CLK_Source  = MC_CGM_3_MUX_3_DC_0 = 25MHz                      / NC
* GMAC_0_RX_CLK_Source       = MC_CGM_3_MUX_4      = 25MHz                      / 48MHz
*/
static int Init_MC_CGM_3(void)
{
    volatile int timeout = 0xFFFF;
    volatile int result  = 0;

    /* Disable MC_CGM_3 dividers */
    IP_MC_CGM_3->MUX_0_DC_0 = (IP_MC_CGM_3->MUX_0_DC_0 & ~MC_CGM_MUX_0_DC_0_DE_MASK) | MC_CGM_MUX_0_DC_0_DE(0);
    IP_MC_CGM_3->MUX_1_DC_0 = (IP_MC_CGM_3->MUX_1_DC_0 & ~MC_CGM_MUX_1_DC_0_DE_MASK) | MC_CGM_MUX_1_DC_0_DE(0);
#ifdef S32R41
    IP_MC_CGM_3->MUX_3_DC_0 = (IP_MC_CGM_3->MUX_3_DC_0 & ~MC_CGM_MUX_3_DC_0_DE_MASK) | MC_CGM_MUX_3_DC_0_DE(0);
#endif

    /* Verify that we don't have switching in progress */
    while (((IP_MC_CGM_3->MUX_0_CSS & MC_CGM_MUX_0_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_3->MUX_1_CSS & MC_CGM_MUX_1_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
#ifdef S32R41
    while (((IP_MC_CGM_3->MUX_2_CSC & MC_CGM_MUX_2_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_3->MUX_3_CSS & MC_CGM_MUX_3_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_3->MUX_4_CSS & MC_CGM_MUX_4_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
#endif

    /* Select MC_CGM_3 sources */
    IP_MC_CGM_3->MUX_0_CSC = (IP_MC_CGM_3->MUX_0_CSC & ~MC_CGM_MUX_0_CSC_SELCTL_MASK) | MC_CGM_MUX_0_CSC_SELCTL(19);
    IP_MC_CGM_3->MUX_1_CSC = (IP_MC_CGM_3->MUX_1_CSC & ~MC_CGM_MUX_1_CSC_SELCTL_MASK) | MC_CGM_MUX_1_CSC_SELCTL(22);
#ifdef S32R41
    IP_MC_CGM_3->MUX_2_CSC = (IP_MC_CGM_3->MUX_2_CSC & ~MC_CGM_MUX_2_CSC_SELCTL_MASK) | MC_CGM_MUX_2_CSC_SELCTL(45);
    IP_MC_CGM_3->MUX_3_CSC = (IP_MC_CGM_3->MUX_3_CSC & ~MC_CGM_MUX_3_CSC_SELCTL_MASK) | MC_CGM_MUX_3_CSC_SELCTL(24);
    IP_MC_CGM_3->MUX_4_CSC = (IP_MC_CGM_3->MUX_4_CSC & ~MC_CGM_MUX_4_CSC_SELCTL_MASK) | MC_CGM_MUX_4_CSC_SELCTL(45);
#endif

    /* Switch MC_CGM_3 sources */
    IP_MC_CGM_3->MUX_0_CSC = (IP_MC_CGM_3->MUX_0_CSC & ~MC_CGM_MUX_0_CSC_CLK_SW_MASK) | MC_CGM_MUX_0_CSC_CLK_SW(1);
    IP_MC_CGM_3->MUX_1_CSC = (IP_MC_CGM_3->MUX_1_CSC & ~MC_CGM_MUX_1_CSC_CLK_SW_MASK) | MC_CGM_MUX_1_CSC_CLK_SW(1);
#ifdef S32R41
    IP_MC_CGM_3->MUX_3_CSC = (IP_MC_CGM_3->MUX_3_CSC & ~MC_CGM_MUX_3_CSC_CLK_SW_MASK) | MC_CGM_MUX_3_CSC_CLK_SW(1);
#endif

    /* Wait for acknowledgement to be cleared */
    while (((IP_MC_CGM_3->MUX_0_CSS & MC_CGM_MUX_0_CSS_CLK_SW_MASK) == 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_3->MUX_1_CSS & MC_CGM_MUX_1_CSS_CLK_SW_MASK) == 0) && (timeout > 0)) { --timeout; }
#ifdef S32R41
    while (((IP_MC_CGM_3->MUX_3_CSS & MC_CGM_MUX_3_CSS_CLK_SW_MASK) == 0) && (timeout > 0)) { --timeout; }
#endif

    /* Verify that clock switch completed */
    while (((IP_MC_CGM_3->MUX_0_CSS & MC_CGM_MUX_0_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_3->MUX_1_CSS & MC_CGM_MUX_1_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
#ifdef S32R41
    while (((IP_MC_CGM_3->MUX_3_CSS & MC_CGM_MUX_3_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
#endif

    /* Select MC_CGM_3 dividers */
    IP_MC_CGM_3->MUX_0_DC_0 = (IP_MC_CGM_3->MUX_0_DC_0 & ~MC_CGM_MUX_0_DC_0_DIV_MASK) | MC_CGM_MUX_0_DC_0_DIV(1-1);
    IP_MC_CGM_3->MUX_1_DC_0 = (IP_MC_CGM_3->MUX_1_DC_0 & ~MC_CGM_MUX_1_DC_0_DIV_MASK) | MC_CGM_MUX_1_DC_0_DIV(1-1);
#ifdef S32R41
    IP_MC_CGM_3->MUX_3_DC_0 = (IP_MC_CGM_3->MUX_3_DC_0 & ~MC_CGM_MUX_3_DC_0_DIV_MASK) | MC_CGM_MUX_3_DC_0_DIV(2-1);
#endif

    /* Wait until divider configuration update has finished */
    while (((IP_MC_CGM_3->MUX_0_DIV_UPD_STAT & MC_CGM_MUX_0_DIV_UPD_STAT_DIV_STAT_MASK) != 0) && (timeout > 0))  { --timeout; }
    while (((IP_MC_CGM_3->MUX_1_DIV_UPD_STAT & MC_CGM_MUX_1_DIV_UPD_STAT_DIV_STAT_MASK) != 0) && (timeout > 0))  { --timeout; }
#ifdef S32R41
    while (((IP_MC_CGM_3->MUX_3_DIV_UPD_STAT & MC_CGM_MUX_3_DIV_UPD_STAT_DIV_STAT_MASK) != 0) && (timeout > 0))  { --timeout; }
#endif

    /* Enable MC_CGM_3 dividers */
    IP_MC_CGM_3->MUX_0_DC_0 = (IP_MC_CGM_3->MUX_0_DC_0 & ~MC_CGM_MUX_0_DC_0_DE_MASK) | MC_CGM_MUX_0_DC_0_DE(1);
    IP_MC_CGM_3->MUX_1_DC_0 = (IP_MC_CGM_3->MUX_1_DC_0 & ~MC_CGM_MUX_1_DC_0_DE_MASK) | MC_CGM_MUX_1_DC_0_DE(1);
#ifdef S32R41
    IP_MC_CGM_3->MUX_3_DC_0 = (IP_MC_CGM_3->MUX_3_DC_0 & ~MC_CGM_MUX_3_DC_0_DE_MASK) | MC_CGM_MUX_3_DC_0_DE(1);

    /* Switch remaining MC_CGM_3 sources */
    IP_MC_CGM_3->MUX_2_CSC = (IP_MC_CGM_3->MUX_2_CSC & ~MC_CGM_MUX_2_CSC_CLK_SW_MASK) | MC_CGM_MUX_2_CSC_CLK_SW(1);
    IP_MC_CGM_3->MUX_4_CSC = (IP_MC_CGM_3->MUX_4_CSC & ~MC_CGM_MUX_4_CSC_CLK_SW_MASK) | MC_CGM_MUX_4_CSC_CLK_SW(1);

    /* Wait for acknowledgement to be cleared */
    while (((IP_MC_CGM_3->MUX_2_CSS & MC_CGM_MUX_2_CSS_CLK_SW_MASK) == 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_3->MUX_4_CSS & MC_CGM_MUX_4_CSS_CLK_SW_MASK) == 0) && (timeout > 0)) { --timeout; }

    /* Verify that clock switch completed */
    while (((IP_MC_CGM_3->MUX_2_CSS & MC_CGM_MUX_2_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
    while (((IP_MC_CGM_3->MUX_4_CSS & MC_CGM_MUX_4_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }
#endif

    if (timeout <= 0)
    {
        result = INIT_MC_CGM_3_ERRNO;
    }
    else
    {

    }

    return result;
}

#ifdef SAF85
/*-----------------------------------------------------------------------*/
/* Initialize FIRC_MUXED                                                 */
/*-----------------------------------------------------------------------*/
/*
* MC_CGM_FIRC_MUX_0_Source      = FIRC_CLK
*/
static int Init_FIRC_MUXED(void)
{
    volatile int timeout = 0xFFFF;
    volatile int result  = 0;

    /* Verify that we don't have switching in progress */
    while (((IP_MC_CGM_FIRC->MUX_0_CSS & MC_CGM_MUX_0_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }

#if (FIRC_MUXED_USE_FIRC == STD_ON)
    IP_MC_CGM_FIRC->MUX_0_CSC = (IP_MC_CGM_FIRC->MUX_0_CSC & ~MC_CGM_MUX_0_CSC_SELCTL_MASK) | MC_CGM_MUX_0_CSC_SELCTL(0);
#endif
#if (FIRC_MUXED_USE_FXOSC == STD_ON)
    IP_MC_CGM_FIRC->MUX_0_CSC = (IP_MC_CGM_FIRC->MUX_0_CSC & ~MC_CGM_MUX_0_CSC_SELCTL_MASK) | MC_CGM_MUX_0_CSC_SELCTL(2);
#endif
    /* Safe clock switch request to FIRC_CLK */
    IP_MC_CGM_FIRC->MUX_0_CSC |= MC_CGM_MUX_0_CSC_CLK_SW(1);

    /* Wait for acknowledgement to be cleared */
    while (((IP_MC_CGM_FIRC->MUX_0_CSS & MC_CGM_MUX_0_CSS_CLK_SW_MASK) == 0) && (timeout > 0)) { --timeout; }

    /* Verify that clock switch completed */
    while (((IP_MC_CGM_FIRC->MUX_0_CSS & MC_CGM_MUX_0_CSS_SWIP_MASK) != 0) && (timeout > 0)) { --timeout; }

    if (timeout <= 0)
    {
        result = INIT_MC_CGM_FIRC_ERRNO;
    }
    else
    {
        /* Do nothing */
    }

    return result;
}

#if (SYS_USE_AURORA_PLL == STD_ON)
/*-----------------------------------------------------------------------*/
/* Initialize AURORA_PLL                                                 */
/*-----------------------------------------------------------------------*/
static int Init_AURORA_PLL(void)
{
    uint32 timeout = 0xFFFFU;
    uint32 result = 0U;
    uint32 delay = 0U;

    /* Enable write access to ATP registers */
    IP_ATP->LAR = 0xC5ACCE55;

    /* Check lock status */
    while(((IP_ATP->LSR & ATP_LSR_SLK_MASK) != 0U) && timeout--);

    /* Power down aurora pll */
    IP_ATP->PLLCR = 0x80000000;

    /* Set DAC_TEST signals to 0 */
    ATP_ATB_CTRL = 0;

    /* Write Reset value of LDO=1, DCO=1 */
    IP_ATP->DCO_CTRL = 0x2B;   /*DCO_ENA = 1, CTR_B_PC = 0b0101, ENA_LDO_ANA_INT = 1.*/

    /* Disable clocks and switch input clock to FIRC */
    /* Write values to EN_CLKS(0x44). Deactivate the differential clock.*/
    IP_ATP->EN_CLKS = 0x44;    /*EN_CLKBUF = 1, BYPAS_B2 = 1*/
    /* Write reset value to ATP_CLKMUX to reset the clock source. */
    IP_ATP->CLKMUX =  ATP_CLKMUX_RCLKSEL(ATP_FIRC_CLK_REF); /* Select FIRC as clock source */

    /* Strobe to stop output clocks */
    IP_ATP->D_STROBE = 0x1;

    /* Wait 1us */
    for(delay=0; delay<100; delay++);

    IP_ATP->CLKMUX =  ATP_CLKMUX_RCLKSEL(ATP_FIRC_CLK_REF); /* Selects the PLL clock source as FXOSC */
    IP_ATP->DCO_CTRL = 0x00000021;            /* Program DCO_CTRL register enable DCO & enable LDO */
    IP_ATP->L_FILT_M = 0x00000030;            /* Program L_FILT_M for bang-bang adpll mode,integrator enabled,1st order filter */
    IP_ATP->D_G_CTR_ACQ = 0x00000030;         /* Select Gain Factor DCO ACQ */
    IP_ATP->D_G_CTR_TR = 0x00000300;          /* Select Gain factor DCO TR. */
    IP_ATP->LP_FLTR = 0x010198EA;

    IP_ATP->FNPDIV_C = (uint32) (ATP_FNPDIV_C_NDIV(0U)  |
                                 ATP_FNPDIV_C_PDIV(3U) |
                                 ATP_FNPDIV_C_FCW(37U));

    /* Enable diff clock again */
    /* BYPAS_B2 = 1, EN_CLKBF = 1, EN_D_CLK = 1, ENA_CLK = 1 */
    IP_ATP->EN_CLKS = (uint32) (ATP_EN_CLKS_BYPAS_B2_MASK |
                                ATP_EN_CLKS_EN_CLKBF_MASK |
                                ATP_EN_CLKS_EN_D_CLK_MASK |
                                ATP_EN_CLKS_ENA_CLK_MASK);

    /* Strobe EN_CLKS */
    IP_ATP->D_STROBE = 0x1;

    /* Add some delay before reading lock status */
    for (delay = 100000U; delay < 1U; delay--);

    /* Wait for lock status */
    while(((IP_ATP->PLLSR & ATP_PLLSR_LOCK_MASK) == 0U) && timeout--);

    if (timeout <= 0)
    {
        result = INIT_AURORA_PLL_ERRNO;
    }
    else
    {
        /* Clear the power down bit in ATP_PLLCR */
        IP_ATP->PLLCR = 0x00000000;

        /* Enable divider 640 MHz output */
        IP_ATP->PLLODIV_1 = 0x80000000;
    }

    return result;
}
#endif
#endif

/*-----------------------------------------------------------------------*/
/* Initialize COFB                                                       */
/*-----------------------------------------------------------------------*/
/*   S32R41                             /       SAF85xx
* BBE32EP DSP(ACCEL_CLK)                / BBE32EP DSP(ACCEL_CLK)
* SPT (ACCEL_CLK/ACCEL_DIV3_CLK)        / SPT (ACCEL_CLK/ACCEL_DIV4_CLK)
* MIPICSI2_0 and MIPICSI2_1             / MIPICSI2_0
*/
static int Init_COFB(void)
{
    volatile int timeout = 0xFFFF;
    volatile int result  = 0;

    /* Enable clock */
    IP_MC_ME->PRTN1_COFB0_CLKEN = MC_ME_PRTN1_COFB0_CLKEN_REQ0_MASK | MC_ME_PRTN1_COFB0_CLKEN_REQ1_MASK | MC_ME_PRTN1_COFB0_CLKEN_REQ2_MASK;

    /* Hardware trigger */
    IP_MC_ME->PRTN1_PUPD |= MC_ME_PRTN1_PUPD_PCUD_MASK;
    IP_MC_ME->CTL_KEY = 0x5AF0;
    IP_MC_ME->CTL_KEY = 0xA50F;

    /* Wait until clock is enabled */
    while(((IP_MC_ME->PRTN1_COFB0_STAT & MC_ME_PRTN1_COFB0_STAT_BLOCK0_MASK) == 0) && (timeout > 0)) { --timeout; }
    while(((IP_MC_ME->PRTN1_COFB0_STAT & MC_ME_PRTN1_COFB0_STAT_BLOCK1_MASK) == 0) && (timeout > 0)) { --timeout; }
    while(((IP_MC_ME->PRTN1_COFB0_STAT & MC_ME_PRTN1_COFB0_STAT_BLOCK2_MASK) == 0) && (timeout > 0)) { --timeout; }

    if (timeout <= 0)
    {
        result = INIT_COFB_ERRNO;
    }
    else
    {
        /* Do nothing */
    }

    return result;
}

/*================================================================================================*/
/**
* @brief sys_init
* @details Function used to initiatialize clocks
* @return E_NOT_OK/E_OK
*/
/*================================================================================================*/
Std_ReturnType sys_init_clock_full(void)
{
    volatile int status = 0;

    status += Switch_Core_FIRC();
    status += Switch_Peripheral_FIRC();

#ifdef SAF85
#if (SYS_USE_AURORA_PLL == STD_ON)
    status += Init_AURORA_PLL();
#endif
#endif

    status += Init_FXOSC();

    status += Init_Core_PLL();
    status += Init_Peripheral_PLL();

#ifdef S32R41
    status += Init_Peripheral_DFS();
#endif

    status += Init_MC_CGM();

#ifdef SAF85
    status += Init_FIRC_MUXED();
#endif

    status += Init_COFB();

    return (status == 0)? E_OK : E_NOT_OK;
}

/*================================================================================================*/
/**
* @brief sys_halt
* @details function used to enter halt mode
*/
/*================================================================================================*/
void sys_halt(void)
{
    EXECUTE_WAIT();
}

/*================================================================================================*/
/**
* @brief sys_stop
* @details function used to enter stop mode
*/
/*================================================================================================*/
void sys_stop(void)
{
    EXECUTE_WAIT();
}

uint8 EUnit_GetCoreID(void)
{
    return OsIf_GetCoreID();
}


#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

#ifdef __cplusplus
}
#endif
