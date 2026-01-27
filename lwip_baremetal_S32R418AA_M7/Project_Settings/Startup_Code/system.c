/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 0.9.0
*   Build Version        : SAF85_S32R41_RTD_0_9_0_D2207_ASR_REL_4_4_REV_0000_20220729
*
*   (c) Copyright 2022 NXP Semiconductors
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
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
#include "Mcal.h"
#include "system.h"
#include "core.h"

#ifdef S32R41
#include "S32R41_MSCM.h"
#include "S32R41_MC_ME.h"
#include "S32R41_MC_RGM.h"
#include "S32R41_SECURITY.h"
#include "S32R41_SDA_AP.h"
#include "S32R41_MDM_AP.h"
#include "S32R41_RESET.h"
#else
#include "SAF85XX_MSCM.h"
#include "SAF85XX_MC_ME.h"
#include "SAF85XX_MC_RGM.h"
#include "SAF85XX_SECURITY.h"
#include "SAF85XX_SDA_AP.h"
#include "SAF85XX_MDM_AP.h"
#include "SAF85XX_RESET.h"
    #ifdef PMC_SUPPORT_LOAD_OTP_TRIM
    #include "SAF85XX_OCOTP.h"
    #include "SAF85XX_PMC.h"
    #include "SAF85XX_PMC_SUPPORT.h"
    #endif
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
*                                       LOCAL MACROS
==================================================================================================*/
#define CA53     (2UL)
#ifdef S32R41
#define CM7_1    (1UL)
#endif
#define CM7_0    (0UL)

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/
#define PLATFORM_START_SEC_VAR_CLEARED_32
#include "Platform_MemMap.h"

/* Allocate a global variable which will be overwritten by the debugger if attached(in CMM), to catch the core after reset. */
uint32 RESET_CATCH_CORE;

#define PLATFORM_STOP_SEC_VAR_CLEARED_32
#include "Platform_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"

/*================================================================================================*/
/**
* @brief    startup_go_to_user_mode
* @details  Function called from startup.s to switch to user mode if MCAL_ENABLE_USER_MODE_SUPPORT
*           is defined
*/
/*================================================================================================*/
void startup_go_to_user_mode(void);
void startup_go_to_user_mode(void)
{
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
    Core_GoToUser();
#endif
}

/*================================================================================================*/
/**
* @brief Sys_GoToSupervisor
* @details function used to enter to supervisor mode.
*           check if it's needed to switch to supervisor mode and make the switch.
*           Return 1 if switch was done
*/
/*================================================================================================*/
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
uint32 Sys_GoToSupervisor(void)
{
    return Core_GoToSupervisor();
}

/*================================================================================================*/
/**
* @brief Sys_GoToUser_Return
* @details function used to switch back to user mode for Thread mode, return a uint32 value passed as parameter
*/
/*================================================================================================*/
uint32 Sys_GoToUser_Return(uint32 u32SwitchToSupervisor, uint32 u32returnValue)
{
    return Core_GoToUser_Return(u32SwitchToSupervisor, u32returnValue);
}

uint32 Sys_GoToUser(void)
{
    return Core_GoToUser();
}

/*================================================================================================*/
/**
* @brief Sys_SuspendInterrupts
* @details Suspend Interrupts
*/
/*================================================================================================*/
void Sys_SuspendInterrupts(void)
{
    Core_SuspendInterrupts();
}
/*================================================================================================*/
/**
* @brief Sys_ResumeInterrupts
* @details Resume Interrupts
*/
/*================================================================================================*/
void Sys_ResumeInterrupts(void)
{
    Core_ResumeInterrupts();
}
#endif


/*================================================================================================*/
/**
* @brief Sys_GetCoreID
* @details Function used to get the ID of the currently executing thread
*/
/*================================================================================================*/
#if !defined(USING_OS_AUTOSAROS)
uint8 Sys_GetCoreID(void)
{
    return ((uint8)(IP_MSCM->CPXNUM & MSCM_CPXNUM_CPN_MASK));
}
#endif

/*================================================================================================*/
/**
* @brief Sys_EnablePartitions
* @details  Function used to enable partitions
*/
/*================================================================================================*/
static void Sys_EnablePartitions(void)
{
    /* Enable Partition 1 */
    if ((IP_MC_RGM->PSTAT1_0 & MC_RGM_PSTAT1_0_PERIPH_64_STAT_MASK) != 0U)
    {
        IP_MC_ME->PRTN1_PCONF |= 1;
        IP_MC_ME->PRTN1_PUPD = 1;
        IP_MC_ME->CTL_KEY = 0x5AF0;
        IP_MC_ME->CTL_KEY = 0xA50F;
        while (!(IP_MC_ME->PRTN1_STAT & MC_ME_PRTN1_STAT_PCS_MASK)) {};
        IP_RDC->RD1_CTRL_REG = RESET_RD1_CTRL_REG_RD1_CTRL_UNLOCK_MASK;
        IP_RDC->RD1_CTRL_REG &= ~RESET_RD1_CTRL_REG_RD1_INTERCONNECT_INTERFACE_DISABLE_MASK;
        while (IP_RDC->RD1_STAT_REG & RESET_RD1_STAT_REG_RD1_INTERCONNECT_INTERFACE_DISABLE_STAT_MASK) {};
        IP_MC_RGM->PRST1_0 &= ~MC_RGM_PRST1_0_PERIPH_64_RST(1);
        IP_MC_ME->PRTN1_PCONF &= ~MC_ME_PRTN1_PCONF_OSSE_MASK;
        IP_MC_ME->PRTN1_PUPD = MC_ME_PRTN1_PUPD_OSSUD_MASK;
        IP_MC_ME->CTL_KEY = 0x5AF0;
        IP_MC_ME->CTL_KEY = 0xA50F;
        while (IP_MC_ME->PRTN1_STAT & MC_ME_PRTN1_STAT_OSSS_MASK) {};
        while (IP_MC_RGM->PSTAT1_0 & MC_RGM_PSTAT1_0_PERIPH_64_STAT_MASK);
        IP_RDC->RD1_CTRL_REG &= ~RESET_RD1_CTRL_REG_RD1_CTRL_UNLOCK_MASK;
    }
}

/*================================================================================================*/
/**
* @brief Sys_StartSecondaryCores
* @details Function used to start the secondary cores
*/
/*================================================================================================*/
#if (defined(CORE0) && defined(MULTIPLE_IMAGE))

static void Sys_StartSecondaryCores(void)
{
#ifdef START_CM7_1
    extern const uint32 __CORE1_START_ADDRESS;

    IP_MC_ME->PRTN0_CORE1_ADDR = (uint32)&__CORE1_START_ADDRESS;
    IP_MC_ME->PRTN0_CORE1_PCONF = 1;
    IP_MC_ME->PRTN0_CORE1_PUPD = 1;
    IP_MC_ME->CTL_KEY = 0x5AF0;
    IP_MC_ME->CTL_KEY = 0xA50F;
    while (!(IP_MC_ME->PRTN0_CORE1_STAT & MC_ME_PRTN0_CORE1_STAT_CCS_MASK)) {};
    IP_MC_RGM->PRST0_0 &= ~MC_RGM_PRST0_0_PERIPH_1_RST(1);
    while(IP_MC_RGM->PSTAT0_0 & MC_RGM_PSTAT0_0_PERIPH_1_STAT_MASK);
#endif

#ifdef START_CA53_0
    extern const uint32 __CORE2_START_ADDRESS;

    /* Enable CA53_0 */
    IP_MC_ME->PRTN1_CORE0_ADDR = (uint32)&__CORE2_START_ADDRESS;
    IP_MC_ME->PRTN1_CORE0_PCONF = 1;
    IP_MC_ME->PRTN1_CORE0_PUPD = 1;
    IP_MC_ME->CTL_KEY = 0x5AF0;
    IP_MC_ME->CTL_KEY = 0xA50F;
    while (!(IP_MC_ME->PRTN1_CORE0_STAT & MC_ME_PRTN1_CORE0_STAT_CCS_MASK)) {};
    IP_MC_RGM->PRST1_0 &= ~MC_RGM_PRST1_0_PERIPH_65_RST(1);
    while(IP_MC_RGM->PSTAT1_0 & MC_RGM_PSTAT1_0_PERIPH_65_STAT_MASK);
#endif
}
#endif

/*================================================================================================*/
/*
 * SystemWfiConfig : Implement errata ERR051149
 */
/*================================================================================================*/
#ifdef ERR_CORTEX_M7_E051149 
#if (ERR_CORTEX_M7_E051149 == STD_ON)
void SystemWfiConfig(void)
{
    volatile uint32 u32EdbStatus = (uint32_t)(IP_SECURITY->MISCDAT0 & SECURITY_MISCDAT0_EDB_MASK);
    if (!u32EdbStatus)
    {
        IP_SDA_AP->DEBUG_ENABLE_CTRL &= ~SDA_AP_DEBUG_ENABLE_CTRL_CSPNIDEN_MASK;
        IP_SDA_AP->DEBUG_ENABLE_CTRL &= ~SDA_AP_DEBUG_ENABLE_CTRL_CSPIDEN_MASK;
        IP_SDA_AP->DEBUG_ENABLE_CTRL &= ~SDA_AP_DEBUG_ENABLE_CTRL_CNIDEN_MASK;  
        IP_SDA_AP->DEBUG_ENABLE_CTRL &= ~SDA_AP_DEBUG_ENABLE_CTRL_CDBGEN_MASK;  
        IP_MDM_AP->CTRL_0 |= MDM_AP_CTRL_0_CM7_0_EDBGREQ_MASK;

    }else{
    }
}
#endif
#endif

/*================================================================================================*/
/*
 * system initialization : system clock, interrupt router ...
*/
/*================================================================================================*/
#ifdef __ICCARM__ 
    #pragma default_function_attributes = @ ".systeminit"
#else
    __attribute__ ((section (".systeminit")))
#endif 
void SystemInit(void)
{
    uint32 i;
    uint32 coreMask;
#ifdef SAF8544
#ifdef PMC_SUPPORT_LOAD_OTP_TRIM
    uint32 dataTrim;
#endif
#endif
    uint32 coreId = OsIf_GetCoreID();

    switch(coreId)
    {
        case CA53:
            coreMask = (1UL << MSCM_IRSPRC_CA53_MASK);
            break;
        case CM7_0:
            coreMask = (1UL << MSCM_IRSPRC_M7_0_SHIFT);
            break;
#ifdef S32R41
        case CM7_1:
            coreMask = (1UL << MSCM_IRSPRC_M7_1_SHIFT);
            break;
#endif
        default:
            coreMask = 0UL;
            break;
    }

    /* Configure IP_MSCM to enable/disable interrupts routing to Core processor */
    for (i = 0; i < MSCM_IRSPRC_COUNT; i++) 
    {
        IP_MSCM->IRSPRC[i] |= coreMask;
    }

    Sys_EnablePartitions();

#if (defined(CORE0) && defined(MULTIPLE_IMAGE))
    Sys_StartSecondaryCores();
#endif

/**************************************************************************/
/* Interrupt Controller ENABLE*/
/**************************************************************************/
    Core_IC_Init();

/**************************************************************************/
/* FPU ENABLE*/
/**************************************************************************/
    Core_FPU_Init();

/**************************************************************************/
/* DEFAULT MEMORY ENABLE*/
/**************************************************************************/
    Core_MPU_Init();

/**************************************************************************/
/* ENABLE CACHE */
/**************************************************************************/
    Core_Cache_Init();
/*
 * SystemWfiConfig : Implement errata ERR051149
 */
 
#ifdef ERR_CORTEX_M7_E051149
#if (ERR_CORTEX_M7_E051149 == STD_ON)
    SystemWfiConfig();
#endif
#endif
#ifdef SAF8544
#ifdef PMC_SUPPORT_LOAD_OTP_TRIM
/**************************************************************************/
/* WORKAROUND TO LOAD TRIM VALUES AUTOMATICALLY FROM OTP */
/**************************************************************************/
    if (0U == (IP_PMC->NCSPD_STAT & PMC_NCSPD_STAT_NCSPD_STAT1_MASK))
    {
        dataTrim = IP_OCOTP->SHADOWS[84U];
        /* Make sure data are valid before using OTP data as trim data */
        /* Trim data is valid when all these fields are non-zero: 
        OVUV BG buffer[21:20], SOC BG OVUV[15:14], SOC BG HVLDO 1V8[13:12] */
        if ((dataTrim & 0x300000U) && (dataTrim & 0xC000U) && (dataTrim & 0x3000U))
        {
            /* Set BG_TRIM_EN to 1 to use OTP data as trim data */
            IP_PMC_SUPPORT->BG_HLD_CTL |= PMC_SUPPORT_BG_HLD_CTL_BG_TRIM_EN_MASK;
            /* Clear bit BG_RES_HLD1V8 */
            IP_PMC_SUPPORT->BG_HLD_CTL &= (~PMC_SUPPORT_BG_HLD_CTL_BG_RES_HLD1V8_MASK);
        }
    }
#endif /* PMC_SUPPORT_LOAD_OTP_TRIM */
#endif /* SAF8544 */
}


#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

#ifdef __cplusplus
}
#endif
