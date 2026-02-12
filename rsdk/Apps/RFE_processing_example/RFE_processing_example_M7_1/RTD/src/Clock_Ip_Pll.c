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
/**
*   @file       Clock_Ip_Pll.c
*   @version    2.0.0
*
*   @brief   CLOCK driver implementations.
*   @details CLOCK driver implementations.
*
*   @addtogroup CLOCK_DRIVER Clock Ip Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Clock_Ip_Private.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CLOCK_IP_PLL_VENDOR_ID_C                      43
#define CLOCK_IP_PLL_AR_RELEASE_MAJOR_VERSION_C       4
#define CLOCK_IP_PLL_AR_RELEASE_MINOR_VERSION_C       7
#define CLOCK_IP_PLL_AR_RELEASE_REVISION_VERSION_C    0
#define CLOCK_IP_PLL_SW_MAJOR_VERSION_C               2
#define CLOCK_IP_PLL_SW_MINOR_VERSION_C               0
#define CLOCK_IP_PLL_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Clock_Ip_Pll.c file and Clock_Ip_Private.h file are of the same vendor */
#if (CLOCK_IP_PLL_VENDOR_ID_C != CLOCK_IP_PRIVATE_VENDOR_ID)
    #error "Clock_Ip_Pll.c and Clock_Ip_Private.h have different vendor ids"
#endif

/* Check if Clock_Ip_Pll.c file and Clock_Ip_Private.h file are of the same Autosar version */
#if ((CLOCK_IP_PLL_AR_RELEASE_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_PLL_AR_RELEASE_MINOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_PLL_AR_RELEASE_REVISION_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip_Pll.c and Clock_Ip_Private.h are different"
#endif

/* Check if Clock_Ip_Pll.c file and Clock_Ip_Private.h file are of the same Software version */
#if ((CLOCK_IP_PLL_SW_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MAJOR_VERSION) || \
     (CLOCK_IP_PLL_SW_MINOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MINOR_VERSION) || \
     (CLOCK_IP_PLL_SW_PATCH_VERSION_C != CLOCK_IP_PRIVATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Clock_Ip_Pll.c and Clock_Ip_Private.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/
/* Clock start section code */
#define MCU_START_SEC_CODE

#include "Mcu_MemMap.h"

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


static void Clock_Ip_CallbackPllEmpty(Clock_Ip_PllConfigType const* Config);
static Clock_Ip_PllStatusReturnType Clock_Ip_CallbackPllEmptyComplete(Clock_Ip_NameType PllName);
static void Clock_Ip_CallbackPllEmptyDisable(Clock_Ip_NameType PllName);

#ifdef CLOCK_IP_PLLDIG_SW_DIS_PLLPD_RCLKSEL_LOCK
static void Clock_Ip_ResetPlldigSwDisPllpdRclkselLock(Clock_Ip_PllConfigType const* Config);
static void Clock_Ip_SetPlldigSwDisPllpdRclkselLock(Clock_Ip_PllConfigType const* Config);
static Clock_Ip_PllStatusReturnType Clock_Ip_CompletePlldigSwDisPllpdRclkselLock(Clock_Ip_NameType PllName);
static void Clock_Ip_EnablePlldigSwDisPllpdRclkselLock(Clock_Ip_PllConfigType const* Config);
#endif
#ifdef CLOCK_IP_PLLDIG_RDIV_MFI_MFN_SDMEN_SSCGBYP_SPREADCTL_STEPNO_STEPSIZE
static void Clock_Ip_ResetPlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize(Clock_Ip_PllConfigType const* Config);
static void Clock_Ip_SetPlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize(Clock_Ip_PllConfigType const* Config);
static Clock_Ip_PllStatusReturnType Clock_Ip_CompletePlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize(Clock_Ip_NameType PllName);
static void Clock_Ip_EnablePlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize(Clock_Ip_PllConfigType const* Config);
#endif
#ifdef CLOCK_IP_PLLDIG_RDIV_MFI
static void Clock_Ip_ResetPlldigRdivMfi(Clock_Ip_PllConfigType const* Config);
static void Clock_Ip_SetPlldigRdivMfi(Clock_Ip_PllConfigType const* Config);
static Clock_Ip_PllStatusReturnType Clock_Ip_CompletePlldigRdivMfi(Clock_Ip_NameType PllName);
static void Clock_Ip_EnablePlldigRdivMfi(Clock_Ip_PllConfigType const* Config);
#endif
#ifdef CLOCK_IP_AURORA_PLL_ATP_FNPDIV_NDIV_PDIV_FCW
static void Clock_Ip_ResetAuroraPllAtpFnpdivNdivPdivFcw(Clock_Ip_PllConfigType const* Config);
static void Clock_Ip_SetAuroraPllAtpFnpdivNdivPdivFcw(Clock_Ip_PllConfigType const* Config);
static Clock_Ip_PllStatusReturnType Clock_Ip_CompleteAuroraPllAtpFnpdivNdivPdivFcw(Clock_Ip_NameType PllName);
static void Clock_Ip_EnableAuroraPllAtpFnpdivNdivPdivFcw(Clock_Ip_PllConfigType const* Config);
#endif

#ifdef CLOCK_IP_AURORA_PLL_ATP_PLL_FNPDIV_NDIV_PDIV_FCW
static void Clock_Ip_ResetAuroraPllAtpPllFnpdivNdivPdivFcw(Clock_Ip_PllConfigType const* Config);
static void Clock_Ip_SetAuroraPllAtpPllFnpdivNdivPdivFcw(Clock_Ip_PllConfigType const* Config);
static Clock_Ip_PllStatusReturnType Clock_Ip_CompleteAuroraPllAtpPllFnpdivNdivPdivFcw(Clock_Ip_NameType PllName);
static void Clock_Ip_EnableAuroraPllAtpPllFnpdivNdivPdivFcw(Clock_Ip_PllConfigType const* Config);
#endif


/* Clock stop section code */
#define MCU_STOP_SEC_CODE

#include "Mcu_MemMap.h"

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

#define MCU_START_SEC_CODE
/* Clock start section code */

#include "Mcu_MemMap.h"


static void Clock_Ip_CallbackPllEmpty(Clock_Ip_PllConfigType const* Config)
{
    (void)Config;
    /* No implementation */
}
static Clock_Ip_PllStatusReturnType Clock_Ip_CallbackPllEmptyComplete(Clock_Ip_NameType PllName)
{
    (void)PllName;
    /* No implementation */
    return STATUS_PLL_LOCKED;
}
static void Clock_Ip_CallbackPllEmptyDisable(Clock_Ip_NameType PllName)
{
    (void)PllName;
    /* No implementation */
}


#ifdef CLOCK_IP_PLLDIG_SW_DIS_PLLPD_RCLKSEL_LOCK
static void Clock_Ip_ResetPlldigSwDisPllpdRclkselLock(Clock_Ip_PllConfigType const* Config)
{
    uint32 Instance;
    uint8 DividerIndex;

    if (NULL_PTR != Config)
    {
        Instance = Clock_Ip_au8ClockFeatures[Config->Name][CLOCK_IP_MODULE_INSTANCE];

        /* Disable output dividers */
        for (DividerIndex = 0U; DividerIndex < Clock_Ip_apxPll[Instance].DivsNo; DividerIndex++)
        {
            Clock_Ip_apxPll[Instance].PllInstance->PLLODIV[DividerIndex] &= ~PLLDIG_PLLODIV_DE_MASK;
        }

        /* Power down PLL */
        Clock_Ip_apxPll[Instance].PllInstance->PLLCR |= PLLDIG_PLLCR_PLLPD_MASK;
    }
    else
    {
        (void)Instance;
        (void)DividerIndex;
    }
}
static void Clock_Ip_SetPlldigSwDisPllpdRclkselLock(Clock_Ip_PllConfigType const* Config)
{
    uint32 Instance;

    if (NULL_PTR != Config)
    {
        Instance = Clock_Ip_au8ClockFeatures[Config->Name][CLOCK_IP_MODULE_INSTANCE];

        if (Config->Enable != 0U)
        {
            /* Name of the input reference clock */
            switch (Config->InputReference)
            {
                case FIRC_MUXED_CLK:
                    /* Select input reference. */
                    Clock_Ip_apxPll[Instance].PllInstance->CLKMUX = PLLDIG_CLKMUX_RCLKSEL(0U);
                    break;
                case FXOSC_CLK:
                    /* Select input reference. */
                    Clock_Ip_apxPll[Instance].PllInstance->CLKMUX = PLLDIG_CLKMUX_RCLKSEL(1U);
                    break;
                case RFE_PLL_CLK:
                    /* Select input reference. */
                    Clock_Ip_apxPll[Instance].PllInstance->CLKMUX = PLLDIG_CLKMUX_RCLKSEL(2U);
                    break;
            #ifdef CLOCK_IP_HAS_AURORAPLL_PHI0_CLK
                case AURORAPLL_PHI0_CLK:
                    /* Select input reference. */
                    Clock_Ip_apxPll[Instance].PllInstance->CLKMUX = PLLDIG_CLKMUX_RCLKSEL(3U);
                    break;
            #endif
            #ifdef CLOCK_IP_HAS_AURORAPLL_PHI1_CLK
                case AURORAPLL_PHI1_CLK:
                    /* Select input reference. */
                    Clock_Ip_apxPll[Instance].PllInstance->CLKMUX = PLLDIG_CLKMUX_RCLKSEL(3U);
                    break;
            #endif
                default:
                    /* Command is not implemented on this platform */
                    break;
            }
            Clock_Ip_apxPll[Instance].PllInstance->PLLCR = PLLDIG_PLLCR_SW_DIS(Config->SoftwareDisable);
        }
    }
    else
    {
        (void)Instance;
    }
}
static Clock_Ip_PllStatusReturnType Clock_Ip_CompletePlldigSwDisPllpdRclkselLock(Clock_Ip_NameType PllName)
{
    Clock_Ip_PllStatusReturnType PllStatus = STATUS_PLL_LOCKED;
    boolean TimeoutOccurred = FALSE;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    uint32 PllLockStatus;
    uint32 Instance = Clock_Ip_au8ClockFeatures[PllName][CLOCK_IP_MODULE_INSTANCE];

    if (0U == (Clock_Ip_apxPll[Instance].PllInstance->PLLCR & PLLDIG_PLLCR_PLLPD_MASK))
    {
        Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
        /* Wait until this pll is locked */
        do
        {
            PllLockStatus = ((Clock_Ip_apxPll[Instance].PllInstance->PLLSR & PLLDIG_PLLSR_LOCK_MASK) >> PLLDIG_PLLSR_LOCK_SHIFT);
            TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
        }
        while ((0U == PllLockStatus) && (FALSE == TimeoutOccurred));

        if(TRUE == TimeoutOccurred)
        {
            PllStatus = STATUS_PLL_UNLOCKED;
            /* Report timeout error */
            Clock_Ip_ReportClockErrors(CLOCK_IP_REPORT_TIMEOUT_ERROR, PllName);
        }
    }
    else
    {
        PllStatus = STATUS_PLL_NOT_ENABLED;
    }
    return PllStatus;
}
static void Clock_Ip_EnablePlldigSwDisPllpdRclkselLock(Clock_Ip_PllConfigType const* Config)
{
    uint32 Instance;

    if (NULL_PTR != Config)
    {
        Instance = Clock_Ip_au8ClockFeatures[Config->Name][CLOCK_IP_MODULE_INSTANCE];

        /* Configure PLL. */
        if (1U == Config->Enable)
        {
            /* Send command to enable PLL device. */
            Clock_Ip_apxPll[Instance].PllInstance->PLLCR &= ~PLLDIG_PLLCR_PLLPD_MASK;
        }
    }
    else
    {
        (void)Instance;
    }
}
#endif
/* Pll with frequency modulation */
#ifdef CLOCK_IP_PLLDIG_RDIV_MFI_MFN_SDMEN_SSCGBYP_SPREADCTL_STEPNO_STEPSIZE
#ifndef CLOCK_IP_FIRC_PLL_REFERENCE
    #define CLOCK_IP_FIRC_PLL_REFERENCE 0U
#endif
#ifndef CLOCK_IP_FXOSC_PLL_REFERENCE
    #define CLOCK_IP_FXOSC_PLL_REFERENCE 1U
#endif
static void Clock_Ip_ResetPlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize(Clock_Ip_PllConfigType const* Config)
{
    uint32 Instance;
    uint8 DividerIndex;

    if (NULL_PTR != Config)
    {
        Instance = Clock_Ip_au8ClockFeatures[Config->Name][CLOCK_IP_MODULE_INSTANCE];

        /* Disable output dividers */
        for (DividerIndex = 0U; DividerIndex < Clock_Ip_apxPll[Instance].DivsNo; DividerIndex++)
        {
            Clock_Ip_apxPll[Instance].PllInstance->PLLODIV[DividerIndex] &= ~PLLDIG_PLLODIV_DE_MASK;
        }

        /* Power down PLL */
        Clock_Ip_apxPll[Instance].PllInstance->PLLCR |= PLLDIG_PLLCR_PLLPD_MASK;
    }
    else
    {
        (void)Instance;
        (void)DividerIndex;
    }
}
static void Clock_Ip_SetPlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize(Clock_Ip_PllConfigType const* Config)
{
    uint32 Instance;
    uint32 Value;

    if (NULL_PTR != Config)
    {
        Instance = Clock_Ip_au8ClockFeatures[Config->Name][CLOCK_IP_MODULE_INSTANCE];

        if (Config->Enable != 0U)
        {
            /* Name of the input reference clock */
            switch (Config->InputReference)
            {
                case FIRC_CLK:
                    /* Select input reference. */
                    Clock_Ip_apxPll[Instance].PllInstance->PLLCLKMUX = PLLDIG_PLLCLKMUX_REFCLKSEL(CLOCK_IP_FIRC_PLL_REFERENCE);
                    break;
                case FXOSC_CLK:
                    /* Select input reference. */
                    Clock_Ip_apxPll[Instance].PllInstance->PLLCLKMUX = PLLDIG_PLLCLKMUX_REFCLKSEL(CLOCK_IP_FXOSC_PLL_REFERENCE);
                    break;
                default:
                    /* Command is not implemented on this platform */
                    break;
            }

            /* Configure PLL: predivider and multiplier */
            Value = Clock_Ip_apxPll[Instance].PllInstance->PLLDV;
            Value &= ~(PLLDIG_PLLDV_RDIV_MASK | PLLDIG_PLLDV_MFI_MASK);
            Value |= (uint32) (PLLDIG_PLLDV_RDIV(Config->Predivider)   |
                                PLLDIG_PLLDV_MFI(Config->MulFactorDiv));
            Clock_Ip_apxPll[Instance].PllInstance->PLLDV = Value;
            /* Set numerator fractional loop divider and sigma delta modulation */
            Value = Clock_Ip_apxPll[Instance].PllInstance->PLLFD;
            Value &= ~(PLLDIG_PLLFD_MFN_MASK | PLLDIG_PLLFD_SDMEN_MASK);
            Value |=  PLLDIG_PLLFD_MFN(Config->NumeratorFracLoopDiv);
            Value |= PLLDIG_PLLFD_SDMEN(Config->SigmaDelta);
            Clock_Ip_apxPll[Instance].PllInstance->PLLFD = Value;
            /* Configure modulation */
            Value = (uint32) (PLLDIG_PLLFM_SSCGBYP(Config->FrequencyModulationBypass)               |
                              PLLDIG_PLLFM_SPREADCTL(Config->ModulationType)                        |
                              PLLDIG_PLLFM_STEPNO(Config->IncrementStep)                            |
                              PLLDIG_PLLFM_STEPSIZE(Config->ModulationPeriod));
            Clock_Ip_apxPll[Instance].PllInstance->PLLFM = Value;
        }
    }
    else
    {
        (void)Instance;
        (void)Value;
    }
}

static Clock_Ip_PllStatusReturnType Clock_Ip_CompletePlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize(Clock_Ip_NameType PllName)
{
    Clock_Ip_PllStatusReturnType PllStatus = STATUS_PLL_LOCKED;

    boolean TimeoutOccurred = FALSE;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    uint32 PllLockStatus;
    uint32 Instance = Clock_Ip_au8ClockFeatures[PllName][CLOCK_IP_MODULE_INSTANCE];

    if (0U == (Clock_Ip_apxPll[Instance].PllInstance->PLLCR & PLLDIG_PLLCR_PLLPD_MASK))
    {
        Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
        /* Wait until this pll is locked */
        do
        {
            PllLockStatus = ((Clock_Ip_apxPll[Instance].PllInstance->PLLSR & PLLDIG_PLLSR_LOCK_MASK) >> PLLDIG_PLLSR_LOCK_SHIFT);
            TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
        }
        while ((0U == PllLockStatus) && (FALSE == TimeoutOccurred));

        if (TRUE == TimeoutOccurred)
        {
            PllStatus = STATUS_PLL_UNLOCKED;
            /* Report timeout error */
            Clock_Ip_ReportClockErrors(CLOCK_IP_REPORT_TIMEOUT_ERROR, PllName);
        }
    }
    else
    {
        PllStatus = STATUS_PLL_NOT_ENABLED;
    }

    return PllStatus;
}
static void Clock_Ip_EnablePlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize(Clock_Ip_PllConfigType const* Config)
{
    uint32 Instance;

    if (NULL_PTR != Config)
    {
        Instance = Clock_Ip_au8ClockFeatures[Config->Name][CLOCK_IP_MODULE_INSTANCE];

        /* Configure PLL. */
        if (1U == Config->Enable)
        {
            /* Send command to enable PLL device. */
            Clock_Ip_apxPll[Instance].PllInstance->PLLCR &= ~PLLDIG_PLLCR_PLLPD_MASK;
        }
    }
    else
    {
        (void)Instance;
    }
}
#endif

#ifdef CLOCK_IP_PLLDIG_RDIV_MFI
#ifndef CLOCK_IP_FIRC_PLL_REFERENCE
    #define CLOCK_IP_FIRC_PLL_REFERENCE 0U
#endif
#ifndef CLOCK_IP_FXOSC_PLL_REFERENCE
    #define CLOCK_IP_FXOSC_PLL_REFERENCE 1U
#endif
static void Clock_Ip_ResetPlldigRdivMfi(Clock_Ip_PllConfigType const* Config)
{
    uint32 Instance;
    uint8 DividerIndex;

    if (NULL_PTR != Config)
    {
        Instance = Clock_Ip_au8ClockFeatures[Config->Name][CLOCK_IP_MODULE_INSTANCE];

        /* Disable output dividers */
        for (DividerIndex = 0U; DividerIndex < Clock_Ip_apxPll[Instance].DivsNo; DividerIndex++)
        {
            Clock_Ip_apxPll[Instance].PllInstance->PLLODIV[DividerIndex] &= ~PLLDIG_PLLODIV_DE_MASK;
        }
        /* Power down PLL */
        Clock_Ip_apxPll[Instance].PllInstance->PLLCR |= PLLDIG_PLLCR_PLLPD_MASK;
    }
    else
    {
        (void)Instance;
        (void)DividerIndex;
    }
}
static void Clock_Ip_SetPlldigRdivMfi(Clock_Ip_PllConfigType const* Config)
{
    uint32 Instance;
    uint32 Value;

    if (NULL_PTR != Config)
    {
        Instance = Clock_Ip_au8ClockFeatures[Config->Name][CLOCK_IP_MODULE_INSTANCE];

        if (Config->Enable != 0U)
        {
            /* Name of the input reference clock */
            switch (Config->InputReference)
            {
                case FIRC_CLK:
                    /* Select input reference. */
                    Clock_Ip_apxPll[Instance].PllInstance->PLLCLKMUX = PLLDIG_PLLCLKMUX_REFCLKSEL(CLOCK_IP_FIRC_PLL_REFERENCE);
                    break;
                case FXOSC_CLK:
                    /* Select input reference. */
                    Clock_Ip_apxPll[Instance].PllInstance->PLLCLKMUX = PLLDIG_PLLCLKMUX_REFCLKSEL(CLOCK_IP_FXOSC_PLL_REFERENCE);
                    break;
                default:
                    /* Command is not implemented on this platform */
                    break;
            }

            /* Configure PLL: predivider and multiplier */
            Value = Clock_Ip_apxPll[Instance].PllInstance->PLLDV;
            Value &= ~(PLLDIG_PLLDV_RDIV_MASK | PLLDIG_PLLDV_MFI_MASK);
            Value |= (uint32) (PLLDIG_PLLDV_RDIV(Config->Predivider)   |
                                PLLDIG_PLLDV_MFI(Config->MulFactorDiv));
            Clock_Ip_apxPll[Instance].PllInstance->PLLDV = Value;
        }
    }
    else
    {
        (void)Instance;
        (void)Value;
    }
}
static Clock_Ip_PllStatusReturnType Clock_Ip_CompletePlldigRdivMfi(Clock_Ip_NameType PllName)
{
    Clock_Ip_PllStatusReturnType PllStatus = STATUS_PLL_LOCKED;
    boolean TimeoutOccurred = FALSE;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    uint32 PllLockStatus;
    uint32 Instance = Clock_Ip_au8ClockFeatures[PllName][CLOCK_IP_MODULE_INSTANCE];

    if (0U == (Clock_Ip_apxPll[Instance].PllInstance->PLLCR & PLLDIG_PLLCR_PLLPD_MASK))
    {
        Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
        /* Wait until this pll is locked */
        do
        {
            PllLockStatus = ((Clock_Ip_apxPll[Instance].PllInstance->PLLSR & PLLDIG_PLLSR_LOCK_MASK) >> PLLDIG_PLLSR_LOCK_SHIFT);
            TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
        }
        while ((0U == PllLockStatus) && (FALSE == TimeoutOccurred));

        if(TRUE == TimeoutOccurred)
        {
            PllStatus = STATUS_PLL_UNLOCKED;
            /* Report timeout error */
            Clock_Ip_ReportClockErrors(CLOCK_IP_REPORT_TIMEOUT_ERROR, PllName);
        }
    }
    else
    {
        PllStatus = STATUS_PLL_NOT_ENABLED;
    }

    return PllStatus;
}
static void Clock_Ip_EnablePlldigRdivMfi(Clock_Ip_PllConfigType const* Config)
{
    uint32 Instance;

    if (NULL_PTR != Config)
    {
        Instance = Clock_Ip_au8ClockFeatures[Config->Name][CLOCK_IP_MODULE_INSTANCE];

        /* Configure PLL. */
        if (1U == Config->Enable)
        {
            /* Send command to enable PLL device. */
            Clock_Ip_apxPll[Instance].PllInstance->PLLCR &= ~PLLDIG_PLLCR_PLLPD_MASK;
        }
    }
    else
    {
        (void)Instance;
    }
}
#endif
/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/



#ifdef CLOCK_IP_AURORA_PLL_ATP_FNPDIV_NDIV_PDIV_FCW
#define CLOCK_IP_CTR_B_PC 5U
#define CLOCK_IP_FIRC_AURORA_REFERENCE 2U
#define CLOCK_IP_FXOSC_AURORA_REFERENCE 1U
#define CLOCK_IP_LVDS_AURORA_REFERENCE 0U
#define CLOCK_IP_AURORA_MIN_POSTDIVIDER 2U
#define CLOCK_IP_AURORA_MAX_POSTDIVIDER 255U
#define CLOCK_IP_AURORA_MIN_PREDIVIDER 1U
#define CLOCK_IP_AURORA_MAX_PREDIVIDER 128U
#define CLOCK_IP_AURORA_MIN_MULTIPLIER 12U
#define CLOCK_IP_AURORA_MAX_MULTIPLIER 2500U
#define CLOCK_IP_AURORA_KEY 0xC5ACCE55u
#define CLOCK_IP_D_G_CTR_ACQ 0x00000030U
#define CLOCK_IP_D_G_CTR_TR 0x000002EEU
#define CLOCK_IP_AURORA_PLL_UNLOCKED 0U
#define CLOCK_IP_AURORA_PLL_ANA_AND_DCO_CTRL      0x02ABB829U
#define CLOCK_IP_AURORA_PLL_LOOP_FILTER_MISC_FIRC 0x08001860U
#define CLOCK_IP_AURORA_PLL_LOOPFILTER_FIRC       0x0F0198F0U
#define CLOCK_IP_AURORA_PLL_DC_COEF_FIRC          0x0000FCD0U
#define CLOCK_IP_AURORA_PLL_LOOP_FILTER_MISC      0x08000C70U
#define CLOCK_IP_AURORA_PLL_LOOPFILTER            0x0EB198EBU
#define CLOCK_IP_AURORA_PLL_DC_COEF               0x0000FCEBU
#define CLOCK_IP_AURORA_PLL_TR_TIMER_VALUE        0x0000B7FFU
#define CLOCK_IP_AURORA_PLL_LOCK_DET_CONTROL_1    0x010007A0U
#define CLOCK_IP_AURORA_PLL_LOCK_DET_CONTROL_2    0x00A91A00U
#define CLOCK_IP_AURORA_PLL_DPLL_TEST_CONFIG      0x00059A68U


static void Clock_Ip_ResetAuroraPllAtpFnpdivNdivPdivFcw(Clock_Ip_PllConfigType const* Config)
{
    boolean TimeoutOccurred = FALSE;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;

    if (NULL_PTR != Config)
    {
        /* Enable write access to ATP registers */
        Clock_Ip_apxAurora->LAR = CLOCK_IP_AURORA_KEY;

        Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
        /* Wait for lock status to auto-clear */
        do
        {
            TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
        }                                                          /* No safe clock switch operation was requested. */
        while ((CLOCK_IP_AURORA_PLL_UNLOCKED != (Clock_Ip_apxAurora->LSR & ATP_LSR_SLK_MASK)) && (FALSE == TimeoutOccurred));

        /* Configure Clock output to TPIU */
        Clock_Ip_apxAurora->CIAC |= ATP_CIAC_TPIU_CLK_DISABLE_MASK;
        Clock_Ip_apxAurora->CIAC |= ATP_CIAC_TPIU_CLK_SEL_MASK;
        Clock_Ip_apxAurora->CIAC &= ~ATP_CIAC_TPIU_CLK_DISABLE_MASK;

        if (FALSE == TimeoutOccurred)
        {
            /******************************************************/
            /**********  Reset AURORA PLL - START *****************/
            /* Disable Input Buffer */
            Clock_Ip_apxAurora->LVDSRX |= ATP_LVDSRX_RXICE_MASK;

            /* RX Disable Power */
            Clock_Ip_apxAurora->LVDSRX &= ~ATP_LVDSRX_RX_EPWR_MASK;

            /* Power down aurora pll */
            Clock_Ip_apxAurora->PLLODIV_0 &= ~ATP_PLLODIV_0_DE_MASK;
            Clock_Ip_apxAurora->PLLODIV_1 &= ~ATP_PLLODIV_0_DE_MASK;
            Clock_Ip_apxAurora->PLLODIV_2 &= ~ATP_PLLODIV_0_DE_MASK;
            Clock_Ip_apxAurora->PLLCR = ATP_PLLCR_PLLPD(1U);

            /* Write Reset value for DCO_CTRL=0x02ABB829: SET_IREF=0x15; STARTUP_CNT=0x1770; ENA_LDO_ANA=0x1; CTRL_BIAS_PTAT_VS_CTAT=0x4; DCO_ENA = 1 */
            Clock_Ip_apxAurora->DCO_CTRL = CLOCK_IP_AURORA_PLL_ANA_AND_DCO_CTRL;

            /* Disable clocks and switch input clock to FIRC */
            /* Write values to EN_CLKS(0x44). Deactivate the differential clock.*/
            Clock_Ip_apxAurora->EN_CLKS = ATP_ENABLE_CLOCKS_ENA_CLKOUTBUFS(1U) | ATP_ENABLE_CLOCKS_BYPASS_BY2(1U);    /*EN_CLKBUF = 1, BYPAS_B2 = 1*/

            /* Write reset value to ATP_CLKMUX to reset the clock source. */
            Clock_Ip_apxAurora->CLKMUX =  ATP_CLKMUX_RCLKSEL(CLOCK_IP_FIRC_AURORA_REFERENCE); /* Select FIRC as clock source */

            /* Strobe to stop output clocks */
            Clock_Ip_apxAurora->D_STROBE = ATP_DATA_STROBE_STROBE(1U);

            /******************************************************/
            /**********  Reset AURORA PLL - END *******************/
        }
        else
        {
            /* Report timeout error */
            Clock_Ip_ReportClockErrors(CLOCK_IP_REPORT_TIMEOUT_ERROR, Config->Name);
        }
    }
    else
    {
        (void)TimeoutOccurred;
        (void)StartTime;
        (void)ElapsedTime;
        (void)TimeoutTicks;
    }
}

static void Clock_Ip_SetAuroraPllAtpFnpdivNdivPdivFcw(Clock_Ip_PllConfigType const* Config)
{
    boolean TimeoutOccurred = FALSE;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;

    if (NULL_PTR != Config)
    {
        /* Aurora pll is enabled */
        if (1U == Config->Enable)
        {
            /******************************************************/
            /**********  set Aurora pll - START *******************/

            /* When external LVDS 100 MHz is used */
            if (LVDS_CLK == Config->InputReference)
            {
                /* Enable Input Buffer */
                Clock_Ip_apxAurora->LVDSRX &= ~ATP_LVDSRX_RXICE_MASK;

                /* RX Enable Power */
                Clock_Ip_apxAurora->LVDSRX |= ATP_LVDSRX_RX_EPWR_MASK;
            }

            Clock_Ip_apxAurora->LVDSRX |= ATP_LVDSRX_RX_EPWR_MASK;

            /* Enables power to current reference module */
            Clock_Ip_apxAurora->LVDSTX |= ATP_LVDSTX_IREF_EPWR_MASK;

            /* TX0 Power Enable */
            Clock_Ip_apxAurora->LVDSTX |= ATP_LVDSTX_EPWRTX0_MASK;
            Clock_Ip_apxAurora->LVDSTX |= ATP_LVDSTX_EPWRTX1_MASK;
            Clock_Ip_apxAurora->LVDSTX |= ATP_LVDSTX_EPWRTX2_MASK;
            Clock_Ip_apxAurora->LVDSTX |= ATP_LVDSTX_EPWRTX3_MASK;

            /* LVDS TX OBE Configuration */
            /* TX-0 Aurora pad output buffer enable */
            Clock_Ip_apxAurora->LVDSTXOBE &= ~(ATP_LVDSTXOBE_OBETX0_MASK | ATP_LVDSTXOBE_OBETX1_MASK | ATP_LVDSTXOBE_OBETX2_MASK | ATP_LVDSTXOBE_OBETX3_MASK);

            /* Name of the input reference clock */
            switch (Config->InputReference)
            {
                case LVDS_CLK:
                    /* Selects the PLL clock source as LVDS */
                    Clock_Ip_apxAurora->CLKMUX =  ATP_CLKMUX_RCLKSEL(CLOCK_IP_LVDS_AURORA_REFERENCE);
                    break;
                case FXOSC_CLK:
                    /* Selects the PLL clock source as FXOSC */
                    Clock_Ip_apxAurora->CLKMUX =  ATP_CLKMUX_RCLKSEL(CLOCK_IP_FXOSC_AURORA_REFERENCE);
                    break;
                case FIRC_CLK:
                    /* Selects the PLL clock source as FIRC */
                    Clock_Ip_apxAurora->CLKMUX =  ATP_CLKMUX_RCLKSEL(CLOCK_IP_FIRC_AURORA_REFERENCE);
                    break;
                default:
                    /* Input reference is not supported on this platform. */
                    break;
            }

            /* LOOP_FILTER_MISC, LOOPFILTER, DC_COEF; the vaules are depended on InputReference */
            if (FIRC_CLK == Config->InputReference)
            {
                Clock_Ip_apxAurora->L_FILT_M = CLOCK_IP_AURORA_PLL_LOOP_FILTER_MISC_FIRC;
                Clock_Ip_apxAurora->LP_FLTR  = CLOCK_IP_AURORA_PLL_LOOPFILTER_FIRC;
                Clock_Ip_apxAurora->DC_COEF  = CLOCK_IP_AURORA_PLL_DC_COEF_FIRC;
            }
            else
            {
                Clock_Ip_apxAurora->L_FILT_M = CLOCK_IP_AURORA_PLL_LOOP_FILTER_MISC;
                Clock_Ip_apxAurora->LP_FLTR  = CLOCK_IP_AURORA_PLL_LOOPFILTER;
                Clock_Ip_apxAurora->DC_COEF  = CLOCK_IP_AURORA_PLL_DC_COEF;
            }

            Clock_Ip_apxAurora->D_G_CTR_ACQ = CLOCK_IP_D_G_CTR_ACQ;         /* Select Gain Factor DCO ACQ */
            Clock_Ip_apxAurora->D_G_CTR_TR = CLOCK_IP_D_G_CTR_TR;          /* Select Gain factor DCO TR. */

            /* Set TR_TIMER_VALUE = 0x0000B7FF; LOCK_DET_CONTROL_1 = 0x010007A0; LOCK_DET_CONTROL_2 = 0x00A91A00 */
            Clock_Ip_apxAurora->TR_T_VAL   = CLOCK_IP_AURORA_PLL_TR_TIMER_VALUE;
            Clock_Ip_apxAurora->L_D_CTR_1  = CLOCK_IP_AURORA_PLL_LOCK_DET_CONTROL_1;
            Clock_Ip_apxAurora->L_D_CT_2   = CLOCK_IP_AURORA_PLL_LOCK_DET_CONTROL_2;

            CLOCK_IP_DEV_ASSERT((Config->Postdivider >= CLOCK_IP_AURORA_MIN_POSTDIVIDER) &&
                                (Config->Postdivider <= CLOCK_IP_AURORA_MAX_POSTDIVIDER));
            CLOCK_IP_DEV_ASSERT((Config->Predivider >= CLOCK_IP_AURORA_MIN_PREDIVIDER) &&
                                (Config->Predivider <= CLOCK_IP_AURORA_MAX_PREDIVIDER));
            CLOCK_IP_DEV_ASSERT((Config->Multiplier >= CLOCK_IP_AURORA_MIN_MULTIPLIER) &&
                                (Config->Multiplier <= CLOCK_IP_AURORA_MAX_MULTIPLIER));

            Clock_Ip_apxAurora->FNPDIV_C = (uint32) (ATP_FCW_NDIV_PDIV_CONFIG_NDIV((uint32)(Config->Predivider) - 1U) |
                                                     ATP_FCW_NDIV_PDIV_CONFIG_PDIV(Config->Postdivider)               |
                                                     ATP_FCW_NDIV_PDIV_CONFIG_FCW(Config->Multiplier));


            /* Set DPLL_TEST_CONFIG = 0x00059A68; DATA_STROBE = 0x00000001 */
            Clock_Ip_apxAurora->DPLL_T_C  = CLOCK_IP_AURORA_PLL_DPLL_TEST_CONFIG;
            Clock_Ip_apxAurora->D_STROBE = ATP_DATA_STROBE_STROBE(1U);

            /* 9. Enable diff clock again */
            /* BYPAS_B2 = 1, ENA_CLKOUTBUFS = 1, ENA_DIFF_CLK = 1, ENA_CLK = 1 */
            Clock_Ip_apxAurora->EN_CLKS = (uint32) ((uint32)ATP_ENABLE_CLOCKS_BYPASS_BY2_MASK         |
                                                    (uint32)ATP_ENABLE_CLOCKS_DIRECTO(Config->Bypass) |
                                                    (uint32)ATP_ENABLE_CLOCKS_ENA_CLKOUTBUFS_MASK     |
                                                    (uint32)ATP_ENABLE_CLOCKS_ENA_DIFF_CLK_MASK       |
                                                    (uint32)ATP_ENABLE_CLOCKS_ENA_CLK_MASK);

            /* Strobe EN_CLKS */
            Clock_Ip_apxAurora->D_STROBE = ATP_DATA_STROBE_STROBE(1U);

            /* Add some delay before reading lock status, i.e. wait 200 us */
            Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, 200U);
            do
            {
                TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
            }
            while (FALSE == TimeoutOccurred);


            Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
            /* Wait for lock status to auto-clear */
            do
            {
                TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
            }                                                          /* No safe clock switch operation was requested. */
            while ((CLOCK_IP_AURORA_PLL_UNLOCKED == (Clock_Ip_apxAurora->PLLSR & ATP_PLLSR_LOCK_MASK)) && (FALSE == TimeoutOccurred));

            /******************************************************/
            /**********  set Aurora pll - END *******************/

            if (FALSE == TimeoutOccurred)
            {
                /* 12. Power up aurora pll */
                Clock_Ip_apxAurora->PLLCR &= ~ATP_PLLCR_PLLPD_MASK;
            }
            else
            {
                /* Report timeout error */
                Clock_Ip_ReportClockErrors(CLOCK_IP_REPORT_TIMEOUT_ERROR, Config->Name);
            }
        }
    }
    else
    {
        (void)TimeoutOccurred;
        (void)StartTime;
        (void)ElapsedTime;
        (void)TimeoutTicks;
    }
}
static Clock_Ip_PllStatusReturnType Clock_Ip_CompleteAuroraPllAtpFnpdivNdivPdivFcw(Clock_Ip_NameType PllName)
{
    Clock_Ip_PllStatusReturnType PllStatus = STATUS_PLL_LOCKED;
    boolean TimeoutOccurred = FALSE;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    uint32 PllLockStatus;

    (void)PllName;
    if (0U == (Clock_Ip_apxAurora->PLLCR & ATP_PLLCR_PLLPD_MASK))
    {
        Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
        /* Wait until this pll is locked */
        do
        {
            PllLockStatus = (Clock_Ip_apxAurora->PLLSR & ATP_PLLSR_LOCK_MASK);
            TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
        }
        while ((CLOCK_IP_AURORA_PLL_UNLOCKED == PllLockStatus) && (FALSE == TimeoutOccurred));

        if (TRUE == TimeoutOccurred)
        {
            PllStatus = STATUS_PLL_UNLOCKED;
            /* Report timeout error */
            Clock_Ip_ReportClockErrors(CLOCK_IP_REPORT_TIMEOUT_ERROR, PllName);
        }
    }
    else
    {
        PllStatus = STATUS_PLL_NOT_ENABLED;
    }

    return PllStatus;
}
static void Clock_Ip_EnableAuroraPllAtpFnpdivNdivPdivFcw(Clock_Ip_PllConfigType const* Config)
{
    if (NULL_PTR != Config)
    {
        /* Configure PLL. */
        if (1U == Config->Enable)
        {
            /* 12. Power up aurora pll */
            Clock_Ip_apxAurora->PLLCR &= ~ATP_PLLCR_PLLPD_MASK;
        }
    }
}
#endif


#ifdef CLOCK_IP_AURORA_PLL_ATP_PLL_FNPDIV_NDIV_PDIV_FCW
#define CLOCK_IP_CTR_B_PC 5U
#define CLOCK_IP_FIRC_AURORA_REFERENCE 2U
#define CLOCK_IP_FXOSC_AURORA_REFERENCE 1U
#define CLOCK_IP_LVDS_AURORA_REFERENCE 0U
#define CLOCK_IP_AURORA_MIN_POSTDIVIDER 2U
#define CLOCK_IP_AURORA_MAX_POSTDIVIDER 255U
#define CLOCK_IP_AURORA_MIN_PREDIVIDER 1U
#define CLOCK_IP_AURORA_MAX_PREDIVIDER 128U
#define CLOCK_IP_AURORA_MIN_MULTIPLIER 12U
#define CLOCK_IP_AURORA_MAX_MULTIPLIER 2500U
#define CLOCK_IP_AURORA_KEY 0xC5ACCE55u
#define CLOCK_IP_D_G_CTR_ACQ 0x00000030U
#define CLOCK_IP_D_G_CTR_TR 0x000002EEU
#define CLOCK_IP_AURORA_PLL_UNLOCKED 0U
#define CLOCK_IP_AURORA_PLL_ANA_AND_DCO_CTRL      0x02ABB829U
#define CLOCK_IP_AURORA_PLL_ANA_AND_DCO_CTRL_FIRC 0x02ABB833U
#define CLOCK_IP_AURORA_PLL_LOOP_FILTER_MISC_FIRC 0x08001860U
#define CLOCK_IP_AURORA_PLL_LOOPFILTER_FIRC       0x0F0198F0U
#define CLOCK_IP_AURORA_PLL_DC_COEF_FIRC          0x0000FCD0U
#define CLOCK_IP_AURORA_PLL_LOOP_FILTER_MISC      0x08000C70U
#define CLOCK_IP_AURORA_PLL_LOOPFILTER            0x0EB198EBU
#define CLOCK_IP_AURORA_PLL_DC_COEF               0x0000FCEBU
#define CLOCK_IP_AURORA_PLL_TR_TIMER_VALUE        0x0000B7FFU
#define CLOCK_IP_AURORA_PLL_LOCK_DET_CONTROL_1    0x010007A0U
#define CLOCK_IP_AURORA_PLL_LOCK_DET_CONTROL_2    0x00A91A00U
#define CLOCK_IP_AURORA_PLL_DPLL_TEST_CONFIG      0x00059A68U


static void Clock_Ip_ResetAuroraPllAtpPllFnpdivNdivPdivFcw(Clock_Ip_PllConfigType const* Config)
{
    if (NULL_PTR != Config)
    {

        /******************************************************/
        /**********  Reset AURORA PLL - START *****************/

        /* Power down aurora pll */
        Clock_Ip_apxAurora->PLLODIV_0 &= ~ATP_PLL_PLLODIV_0_DE_MASK;
        Clock_Ip_apxAurora->PLLODIV_2 &= ~ATP_PLL_PLLODIV_0_DE_MASK;
        Clock_Ip_apxAurora->PLLCR = ATP_PLL_PLLCR_PLLPD(1U);

        if (FIRC_CLK ==  Config->InputReference)
        {
            /* Write Reset value for DCO_CTRL=0x02ABB833 */
            Clock_Ip_apxAurora->DCO_CTRL = CLOCK_IP_AURORA_PLL_ANA_AND_DCO_CTRL_FIRC;
        }
        else
        {
            /* Write Reset value for DCO_CTRL=0x02ABB829 */
            Clock_Ip_apxAurora->DCO_CTRL = CLOCK_IP_AURORA_PLL_ANA_AND_DCO_CTRL;
        }

        /* Disable clocks and switch input clock to FIRC */
        /* Write values to EN_CLKS(0x44). Deactivate the differential clock.*/
        Clock_Ip_apxAurora->EN_CLKS = ATP_PLL_ENABLE_CLOCKS_ENA_CLKOUTBUFS(1U) | ATP_PLL_ENABLE_CLOCKS_BYPASS_BY2(1U);    /*EN_CLKBUF = 1, BYPAS_B2 = 1*/

        /* Write reset value to ATP_PLL_CLKMUX to reset the clock source. */
        Clock_Ip_apxAurora->CLKMUX =  ATP_PLL_CLKMUX_RCLKSEL(CLOCK_IP_FIRC_AURORA_REFERENCE); /* Select FIRC as clock source */

        /* Strobe to stop output clocks */
        Clock_Ip_apxAurora->D_STROBE = ATP_PLL_DATA_STROBE_STROBE(1U);

        /******************************************************/
        /**********  Reset AURORA PLL - END *******************/
       
    }
}

static void Clock_Ip_SetAuroraPllAtpPllFnpdivNdivPdivFcw(Clock_Ip_PllConfigType const* Config)
{
    boolean TimeoutOccurred = FALSE;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;

    if (NULL_PTR != Config)
    {
        /* Aurora pll is enabled */
        if (1U == Config->Enable)
        {
            /******************************************************/
            /**********  set Aurora pll - START *******************/

            /* Name of the input reference clock */
            switch (Config->InputReference)
            {
                case LVDS_CLK:
                    /* Selects the PLL clock source as LVDS */
                    Clock_Ip_apxAurora->CLKMUX =  ATP_PLL_CLKMUX_RCLKSEL(CLOCK_IP_LVDS_AURORA_REFERENCE);
                    break;
                case FXOSC_CLK:
                    /* Selects the PLL clock source as FXOSC */
                    Clock_Ip_apxAurora->CLKMUX =  ATP_PLL_CLKMUX_RCLKSEL(CLOCK_IP_FXOSC_AURORA_REFERENCE);
                    break;
                case FIRC_CLK:
                    /* Selects the PLL clock source as FIRC */
                    Clock_Ip_apxAurora->CLKMUX =  ATP_PLL_CLKMUX_RCLKSEL(CLOCK_IP_FIRC_AURORA_REFERENCE);
                    break;
                default:
                    /* Input reference is not supported on this platform. */
                    break;
            }

            /* LOOP_FILTER_MISC, LOOPFILTER, DC_COEF; the vaules are depended on InputReference */
            if (FIRC_CLK == Config->InputReference)
            {
                Clock_Ip_apxAurora->L_FILT_M = CLOCK_IP_AURORA_PLL_LOOP_FILTER_MISC_FIRC;
                Clock_Ip_apxAurora->LP_FLTR  = CLOCK_IP_AURORA_PLL_LOOPFILTER_FIRC;
                Clock_Ip_apxAurora->DC_COEF  = CLOCK_IP_AURORA_PLL_DC_COEF_FIRC;
            }
            else
            {
                Clock_Ip_apxAurora->L_FILT_M = CLOCK_IP_AURORA_PLL_LOOP_FILTER_MISC;
                Clock_Ip_apxAurora->LP_FLTR  = CLOCK_IP_AURORA_PLL_LOOPFILTER;
                Clock_Ip_apxAurora->DC_COEF  = CLOCK_IP_AURORA_PLL_DC_COEF;
            }

            Clock_Ip_apxAurora->D_G_CTR_ACQ = CLOCK_IP_D_G_CTR_ACQ;         /* Select Gain Factor DCO ACQ */
            Clock_Ip_apxAurora->D_G_CTR_TR = CLOCK_IP_D_G_CTR_TR;          /* Select Gain factor DCO TR. */

            /* Set TR_TIMER_VALUE = 0x0000B7FF; LOCK_DET_CONTROL_1 = 0x010007A0; LOCK_DET_CONTROL_2 = 0x00A91A00 */
            Clock_Ip_apxAurora->TR_T_VAL   = CLOCK_IP_AURORA_PLL_TR_TIMER_VALUE;
            Clock_Ip_apxAurora->L_D_CTR_1  = CLOCK_IP_AURORA_PLL_LOCK_DET_CONTROL_1;
            Clock_Ip_apxAurora->L_D_CT_2   = CLOCK_IP_AURORA_PLL_LOCK_DET_CONTROL_2;

            CLOCK_IP_DEV_ASSERT((Config->Postdivider >= CLOCK_IP_AURORA_MIN_POSTDIVIDER) &&
                                (Config->Postdivider <= CLOCK_IP_AURORA_MAX_POSTDIVIDER));
            CLOCK_IP_DEV_ASSERT((Config->Predivider >= CLOCK_IP_AURORA_MIN_PREDIVIDER) &&
                                (Config->Predivider <= CLOCK_IP_AURORA_MAX_PREDIVIDER));
            CLOCK_IP_DEV_ASSERT((Config->Multiplier >= CLOCK_IP_AURORA_MIN_MULTIPLIER) &&
                                (Config->Multiplier <= CLOCK_IP_AURORA_MAX_MULTIPLIER));

            Clock_Ip_apxAurora->FNPDIV_C = (uint32) (ATP_PLL_FCW_NDIV_PDIV_CONFIG_NDIV((uint32)(Config->Predivider) - 1U) |
                                                     ATP_PLL_FCW_NDIV_PDIV_CONFIG_PDIV(Config->Postdivider)               |
                                                     ATP_PLL_FCW_NDIV_PDIV_CONFIG_FCW(Config->Multiplier));


            /* Set DPLL_TEST_CONFIG = 0x00059A68; DATA_STROBE = 0x00000001 */
            Clock_Ip_apxAurora->DPLL_T_C  = CLOCK_IP_AURORA_PLL_DPLL_TEST_CONFIG;
            Clock_Ip_apxAurora->D_STROBE = ATP_PLL_DATA_STROBE_STROBE(1U);

            /* 9. Enable diff clock again */
            /* BYPAS_B2 = 1, ENA_CLKOUTBUFS = 1, ENA_DIFF_CLK = 1, ENA_CLK = 1 */
            Clock_Ip_apxAurora->EN_CLKS = (uint32) ((uint32)ATP_PLL_ENABLE_CLOCKS_BYPASS_BY2_MASK         |
                                                    (uint32)ATP_PLL_ENABLE_CLOCKS_DIRECTO(Config->Bypass) |
                                                    (uint32)ATP_PLL_ENABLE_CLOCKS_ENA_CLKOUTBUFS_MASK     |
                                                    (uint32)ATP_PLL_ENABLE_CLOCKS_ENA_DIFF_CLK_MASK       |
                                                    (uint32)ATP_PLL_ENABLE_CLOCKS_ENA_CLK_MASK);

            /* Strobe EN_CLKS */
            Clock_Ip_apxAurora->D_STROBE = ATP_PLL_DATA_STROBE_STROBE(1U);

            /* Add some delay before reading lock status, i.e. wait 200 us */
            Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, 200U);
            do
            {
                TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
            }
            while (FALSE == TimeoutOccurred);


            Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
            /* Wait for lock status to auto-clear */
            do
            {
                TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
            }                                                          /* No safe clock switch operation was requested. */
            while ((CLOCK_IP_AURORA_PLL_UNLOCKED == (Clock_Ip_apxAurora->PLLSR & ATP_PLL_PLLSR_LOCK_MASK)) && (FALSE == TimeoutOccurred));

            /******************************************************/
            /**********  set Aurora pll - END *******************/

            if (FALSE == TimeoutOccurred)
            {
                /* 12. Power up aurora pll */
                Clock_Ip_apxAurora->PLLCR &= ~ATP_PLL_PLLCR_PLLPD_MASK;
            }
            else
            {
                /* Report timeout error */
                Clock_Ip_ReportClockErrors(CLOCK_IP_REPORT_TIMEOUT_ERROR, Config->Name);
            }
        }
    }
    else
    {
        (void)TimeoutOccurred;
        (void)StartTime;
        (void)ElapsedTime;
        (void)TimeoutTicks;
    }
}
static Clock_Ip_PllStatusReturnType Clock_Ip_CompleteAuroraPllAtpPllFnpdivNdivPdivFcw(Clock_Ip_NameType PllName)
{
    Clock_Ip_PllStatusReturnType PllStatus = STATUS_PLL_LOCKED;
    boolean TimeoutOccurred = FALSE;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    uint32 PllLockStatus;

    (void)PllName;
    if (0U == (Clock_Ip_apxAurora->PLLCR & ATP_PLL_PLLCR_PLLPD_MASK))
    {
        Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
        /* Wait until this pll is locked */
        do
        {
            PllLockStatus = (Clock_Ip_apxAurora->PLLSR & ATP_PLL_PLLSR_LOCK_MASK);
            TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
        }
        while ((CLOCK_IP_AURORA_PLL_UNLOCKED == PllLockStatus) && (FALSE == TimeoutOccurred));

        if (TRUE == TimeoutOccurred)
        {
            PllStatus = STATUS_PLL_UNLOCKED;
            /* Report timeout error */
            Clock_Ip_ReportClockErrors(CLOCK_IP_REPORT_TIMEOUT_ERROR, PllName);
        }
    }
    else
    {
        PllStatus = STATUS_PLL_NOT_ENABLED;
    }

    return PllStatus;
}
static void Clock_Ip_EnableAuroraPllAtpPllFnpdivNdivPdivFcw(Clock_Ip_PllConfigType const* Config)
{
    if (NULL_PTR != Config)
    {
        /* Configure PLL. */
        if (1U == Config->Enable)
        {
            /* 12. Power up aurora pll */
            Clock_Ip_apxAurora->PLLCR &= ~ATP_PLL_PLLCR_PLLPD_MASK;
        }
    }
}
#endif





/* Clock stop section code */
#define MCU_STOP_SEC_CODE

#include "Mcu_MemMap.h"

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/
/* Clock start constant section data */
#define MCU_START_SEC_CONST_UNSPECIFIED

#include "Mcu_MemMap.h"
const Clock_Ip_PllCallbackType Clock_Ip_axPllCallbacks[CLOCK_IP_PLL_CALLBACKS_COUNT] =
{
    {
        &Clock_Ip_CallbackPllEmpty,            /* Reset */
        &Clock_Ip_CallbackPllEmpty,            /* Set */
        &Clock_Ip_CallbackPllEmptyComplete,    /* Complete */
        &Clock_Ip_CallbackPllEmpty,            /* Enable */
        &Clock_Ip_CallbackPllEmptyDisable,     /* Disable */
    },
#ifdef CLOCK_IP_PLLDIG_SW_DIS_PLLPD_RCLKSEL_LOCK
    {
        &Clock_Ip_ResetPlldigSwDisPllpdRclkselLock,          /* Reset */
        &Clock_Ip_SetPlldigSwDisPllpdRclkselLock,            /* Set */
        &Clock_Ip_CompletePlldigSwDisPllpdRclkselLock,       /* Complete */
        &Clock_Ip_EnablePlldigSwDisPllpdRclkselLock,         /* Enable */
        &Clock_Ip_CallbackPllEmptyDisable,                   /* Disable */
    },
#endif
    /* Pll with frequency modulation */
#ifdef CLOCK_IP_PLLDIG_RDIV_MFI_MFN_SDMEN_SSCGBYP_SPREADCTL_STEPNO_STEPSIZE
    {
        &Clock_Ip_ResetPlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize,              /* Reset */
        &Clock_Ip_SetPlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize,                /* Set */
        &Clock_Ip_CompletePlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize,           /* Complete */
        &Clock_Ip_EnablePlldigRdivMfiMfnSdmenSsscgbypSpreadctlStepnoStepsize,             /* Enable */
        &Clock_Ip_CallbackPllEmptyDisable,                                               /* Disable */
    },
#endif
    /* Pll without frequency modulation */
#ifdef CLOCK_IP_PLLDIG_RDIV_MFI
    {
        &Clock_Ip_ResetPlldigRdivMfi,          /* Reset */
        &Clock_Ip_SetPlldigRdivMfi,            /* Set */
        &Clock_Ip_CompletePlldigRdivMfi,       /* Complete */
        &Clock_Ip_EnablePlldigRdivMfi,         /* Enable */
        &Clock_Ip_CallbackPllEmptyDisable,            /* Disable */
    },
#endif
    /* Aurora Pll */
#ifdef CLOCK_IP_AURORA_PLL_ATP_FNPDIV_NDIV_PDIV_FCW
    {
        &Clock_Ip_ResetAuroraPllAtpFnpdivNdivPdivFcw,                                      /* Reset */
        &Clock_Ip_SetAuroraPllAtpFnpdivNdivPdivFcw,                                        /* Set */
        &Clock_Ip_CompleteAuroraPllAtpFnpdivNdivPdivFcw,                                   /* Complete */
        &Clock_Ip_EnableAuroraPllAtpFnpdivNdivPdivFcw,                                     /* Enable */
        &Clock_Ip_CallbackPllEmptyDisable,                                                 /* Disable */
    },
#endif
#ifdef CLOCK_IP_AURORA_PLL_ATP_PLL_FNPDIV_NDIV_PDIV_FCW
    {
        &Clock_Ip_ResetAuroraPllAtpPllFnpdivNdivPdivFcw,                                   /* Reset */
        &Clock_Ip_SetAuroraPllAtpPllFnpdivNdivPdivFcw,                                     /* Set */
        &Clock_Ip_CompleteAuroraPllAtpPllFnpdivNdivPdivFcw,                                /* Complete */
        &Clock_Ip_EnableAuroraPllAtpPllFnpdivNdivPdivFcw,                                  /* Enable */
        &Clock_Ip_CallbackPllEmptyDisable,                                                 /* Disable */
    },
#endif
};


/* Clock stop constant section data */
#define MCU_STOP_SEC_CONST_UNSPECIFIED

#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

