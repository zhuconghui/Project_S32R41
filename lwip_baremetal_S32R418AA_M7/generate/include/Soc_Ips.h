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

#ifndef SOC_IPS_H
#define SOC_IPS_H

/**
*   @file Soc_Ips.h
*
*   @addtogroup BASENXP_COMPONENT
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Platform_Types.h"
#include "IpVersionMacros.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SOC_IPS_VENDOR_ID                    43
#define SOC_IPS_MODULE_ID                    0
#define SOC_IPS_AR_RELEASE_MAJOR_VERSION     4
#define SOC_IPS_AR_RELEASE_MINOR_VERSION     7
#define SOC_IPS_AR_RELEASE_REVISION_VERSION  0
#define SOC_IPS_SW_MAJOR_VERSION             2
#define SOC_IPS_SW_MINOR_VERSION             0
#define SOC_IPS_SW_PATCH_VERSION             0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Platform_Types.h header file are of the same Autosar version */
    #if ((SOC_IPS_AR_RELEASE_MAJOR_VERSION != PLATFORM_AR_RELEASE_MAJOR_VERSION) || \
         (SOC_IPS_AR_RELEASE_MINOR_VERSION != PLATFORM_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Soc_Ips.h and Platform_Types.h are different"
    #endif

    /* Check if source file and IpVersionMacros.h header file are of the same Autosar version */
    #if ((SOC_IPS_AR_RELEASE_MAJOR_VERSION != IPVERSIONMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (SOC_IPS_AR_RELEASE_MINOR_VERSION != IPVERSIONMACROS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Soc_Ips.h and IpVersionMacros.h are different"
    #endif
#endif

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/
/* 40 = 0x28 = CORTEXM_PLATFORM
 * 47 = 0x2F = S32R41 DERIVATIVE ID
 * 01 = 0x01 = Rev. 1
 * 00 = 0x00 = RC      (A-B-C-D-E-F-G-H-I-J-K-L-M-N-O-P-Q-R-S-T-U-V-W-X-Y-Z)
*/

/**
* @brief PMC IP Version: PMC v03.00.01.00
* @details  IP Versions
*/
#define IPV_PMC                  (0x282F0100UL)


/**
* @brief PIT_RTI IP Version: PIT_RTI v05.00.06.11
* @details  IP Versions
*/
#define IPV_PIT              (0x282F0100UL)


/**
* @brief RTC IP Version: RTC 00.00.03.06
* @details  IP Versions
*/
#define IPV_RTC                (0x282F0100UL)


/**
* @brief ADCDIG IP Version: v00.00.18.00
* @details  IP Versions
*/
#define IPV_ADCDIG               (0x282F0100UL)


/**
* @brief SIUL2 IP Version: v00.00.00.10
* @details  IP Versions
*/
#define IPV_SIULV2               (0x282F0100UL)

/**
* @brief MC IP Version: D_IP_magic_carpet_SYN_302 [v07.00.02.03]
* @details  IP Versions
*/
#define IPV_MC                (0x282F0100UL)

/**
* @brief PLLDIG IP Version: DA_IP_PLL_SYS_C40ESF3_008 [v00.00.03.04]
* @details  IP Versions
*/
#define IPV_PLLDIG               (0x282F0100UL)

/**
* @brief FXOSC IP Version: DA_IP_FXOSC_C [v40.00.00.02.05]
* @details  IP Versions
*/
#define IPV_FXOSC               (0x282F0100UL)

/**
* @brief FIRC IP Version: D_IP_FIRC_SYN_SPEC [v00.00.00.21]
* @details  IP Versions
*/
#define IPV_FIRC                (0x282F0100UL)

/**
* @brief GMAC IP Version: D_IP_3P_ENET_MAC_SYN_017 [v02.00.00.08]
* @details  IP Versions
*/
#define IPV_GMAC                (0x282F0100UL)  

/**
* @brief C40ASF IP Version: M_IP_c40asf_spec [v00.00.00.04]
* @details  IP Versions
*/
#define IPV_C40ASF              (0x282F0100UL) 

/**
* @brief PFLASH IP Version: pflash_c40asf_s32k_spec [v00.00.00.11]
* @details  IP Versions
*/
#define IPV_PFLASH              (0x282F0100UL)

/**
* @brief C40ASF IP Version: M_IP_c40asf_spec [v00.00.00.04]
* @details  IP Versions
*/
#define IPV_FLASH_ARRAY         (0x282F0100UL) 

/**
* @brief PFLASH IP Version: pflash_c40asf_s32k_spec [v00.00.00.11]
* @details  IP Versions
*/
#define IPV_FLASH_CONTROLLER    (0x282F0100UL)  

/**
* @brief QSPI IP Version: QSPI d_ip_quadspi_v2_sync_spec.025
* @details  IP Versions
*/
#define IPV_QSPI                (0x282F0100UL)          

/**
* @brief Clock Monitoring Unit Frequency Check (CMU_FC) IP Version
* @details  IP Versions
*/
#define IPV_CMU_FC              (0x282F0100UL) 

/*==================================================================================================
*                              REGISTER PROTECTION (REG_PROT)
==================================================================================================*/
/**
* @brief Register Protection IP Version
* @details  IP Versions
*/
#define IPV_REG_PROT                  (0x282F0100UL)
 
/*==================================================================================================
*                              Software Erratas for Hardware Erratas
==================================================================================================*/
/**
* @brief Hardware errata for CORE: (e051357)
* @details e051357 Cortex-M7: A Cortex-M7 application core can enter a hung state if an interrupt is received shortly after execution of a wait instruction.
*/
#define ERR_CORTEX_M7_E051357      (STD_ON)

/**
* @brief Hardware errata for MC_RGM: (e051310)
* @details e051310 Reset: Escalation not available on destructive reset source 22
*/
#define ERR_IPV_MC_RGM_E051310     (STD_ON)

/**
* @brief Hardware errata for XBIC: (e051299)
* @details e051299 XBIC: Logical Master ID not getting detected properly
*/
#define ERR_IPV_XBIC_E051299       (STD_ON)

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/**
* @brief Enable CACHE management feature
* @details Global define to enable CACHE management at runtime
*/
#define MCAL_CACHE_RUNTIME_MNGMNT (STD_ON)

/**
* @brief number of EMIOS channels per each interrupt
* @details  Platform specific Defines/Configurations for EMIOS.
* Can be 1U, 2U, 4U, etc.. depending on the platform
*/
#define EMIOS_CHANNELS_PER_INTERRUPT (4U)
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
/**
* @brief User Mode feature is enabled
* @details User Mode feature - MCAL is configured to run in supervisor mode, by default.
*/

#ifdef MCAL_ENABLE_SUPERVISOR_MODE
    #undef MCAL_ENABLE_USER_MODE_SUPPORT
#endif
/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif


/** @} */

#endif /* SOC_IPS_H */

