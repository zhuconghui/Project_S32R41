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
*   Build Version        : SAF85xx_SAF86xx_S32R41_RTD_2_0_0_D2402_ASR_REL_4_7_REV_0000_20240221
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
*   @file Xrdc_Ip_PBcfg.c
*
*   @addtogroup XRDC_IP XRDC IPV Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Xrdc_Ip_Types.h"
#include "Xrdc_Ip_Cfg.h"
#include "Xrdc_Ip_Device_Registers.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_XRDC_IP_PBCFG_VENDOR_ID_C                     43
#define RM_XRDC_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define RM_XRDC_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C      7
#define RM_XRDC_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C   0
#define RM_XRDC_IP_PBCFG_SW_MAJOR_VERSION_C              2
#define RM_XRDC_IP_PBCFG_SW_MINOR_VERSION_C              0
#define RM_XRDC_IP_PBCFG_SW_PATCH_VERSION_C              0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Xrdc_Ip_Types.h */
#if (RM_XRDC_IP_PBCFG_VENDOR_ID_C != RM_XRDC_IP_TYPES_VENDOR_ID)
    #error "Xrdc_Ip_PBcfg.c and Xrdc_Ip_Types.h have different vendor ids"
#endif
#if ((RM_XRDC_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != RM_XRDC_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (RM_XRDC_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C    != RM_XRDC_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (RM_XRDC_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C != RM_XRDC_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Xrdc_Ip_PBcfg.c and Xrdc_Ip_Types.h are different"
#endif
#if ((RM_XRDC_IP_PBCFG_SW_MAJOR_VERSION_C != RM_XRDC_IP_TYPES_SW_MAJOR_VERSION) || \
     (RM_XRDC_IP_PBCFG_SW_MINOR_VERSION_C != RM_XRDC_IP_TYPES_SW_MINOR_VERSION) || \
     (RM_XRDC_IP_PBCFG_SW_PATCH_VERSION_C != RM_XRDC_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Xrdc_Ip_PBcfg.c and Xrdc_Ip_Types.h are different"
#endif

/* Checks against Xrdc_Ip_Cfg.h */
#if (RM_XRDC_IP_PBCFG_VENDOR_ID_C != RM_XRDC_IP_CFG_VENDOR_ID)
    #error "Xrdc_Ip_PBcfg.c and Xrdc_Ip_Cfg.h have different vendor ids"
#endif
#if ((RM_XRDC_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != RM_XRDC_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (RM_XRDC_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C    != RM_XRDC_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (RM_XRDC_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C != RM_XRDC_IP_CFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Xrdc_Ip_PBcfg.c and Xrdc_Ip_Cfg.h are different"
#endif
#if ((RM_XRDC_IP_PBCFG_SW_MAJOR_VERSION_C != RM_XRDC_IP_CFG_SW_MAJOR_VERSION) || \
     (RM_XRDC_IP_PBCFG_SW_MINOR_VERSION_C != RM_XRDC_IP_CFG_SW_MINOR_VERSION) || \
     (RM_XRDC_IP_PBCFG_SW_PATCH_VERSION_C != RM_XRDC_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Xrdc_Ip_PBcfg.c and Xrdc_Ip_Cfg.h are different"
#endif

/* Checks against Xrdc_Ip_Device_Registers.h */
#if (RM_XRDC_IP_PBCFG_VENDOR_ID_C != RM_XRDC_IP_DEVICE_REGISTERS_VENDOR_ID)
    #error "Xrdc_Ip_PBcfg.c and Xrdc_Ip_Device_Registers.h have different vendor ids"
#endif
#if ((RM_XRDC_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != RM_XRDC_IP_DEVICE_REGISTERS_AR_RELEASE_MAJOR_VERSION) || \
     (RM_XRDC_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C    != RM_XRDC_IP_DEVICE_REGISTERS_AR_RELEASE_MINOR_VERSION) || \
     (RM_XRDC_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C != RM_XRDC_IP_DEVICE_REGISTERS_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Xrdc_Ip_PBcfg.c and Xrdc_Ip_Device_Registers.h are different"
#endif
#if ((RM_XRDC_IP_PBCFG_SW_MAJOR_VERSION_C != RM_XRDC_IP_DEVICE_REGISTERS_SW_MAJOR_VERSION) || \
     (RM_XRDC_IP_PBCFG_SW_MINOR_VERSION_C != RM_XRDC_IP_DEVICE_REGISTERS_SW_MINOR_VERSION) || \
     (RM_XRDC_IP_PBCFG_SW_PATCH_VERSION_C != RM_XRDC_IP_DEVICE_REGISTERS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Xrdc_Ip_PBcfg.c and Xrdc_Ip_Device_Registers.h are different"
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/








/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                      BUFFER DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                   STATE STRUCTURE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

#define RM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rm_MemMap.h"


static const uint32 Xrdc_Instances_InUsed[2] =
{
    XRDC_INSTANCE0, XRDC_INSTANCE1
};
/* XRDC instance: XRDC_INSTANCE0 */
static const Xrdc_Ip_MemConfigType Xrdc_Memory_Config_XRDC_INSTANCE0[13] =
{
    {
        /*Select Memory region controller Xrdc_0_PRAM0 will be used to control the address range below */
        XRDC_MRC0,
        /*Each memory region controller include 16 descriptors to write configuration. If multiple descriptors are configured the policy will be ORed by all the descriptors */
        (uint32)0UL,
        /*Start address for Xrdc_0_PRAM0 controller and descriptor 0 */
        (uint32)0x0UL,
        /*End address for Xrdc_0_PRAM0 controller and descriptor 0 */
        (uint32)0xffffffffUL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this memory range */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Xrdc MRGD bit lock*/
        XRDC_MRGD_W3_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Select Memory region controller Xrdc_0_PRAM1 will be used to control the address range below */
        XRDC_MRC0,
        /*Each memory region controller include 16 descriptors to write configuration. If multiple descriptors are configured the policy will be ORed by all the descriptors */
        (uint32)1UL,
        /*Start address for Xrdc_0_PRAM1 controller and descriptor 1 */
        (uint32)0x0UL,
        /*End address for Xrdc_0_PRAM1 controller and descriptor 1 */
        (uint32)0xffffffffUL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this memory range */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Xrdc MRGD bit lock*/
        XRDC_MRGD_W3_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Select Memory region controller Xrdc_0_PRAM2 will be used to control the address range below */
        XRDC_MRC0,
        /*Each memory region controller include 16 descriptors to write configuration. If multiple descriptors are configured the policy will be ORed by all the descriptors */
        (uint32)2UL,
        /*Start address for Xrdc_0_PRAM2 controller and descriptor 2 */
        (uint32)0x0UL,
        /*End address for Xrdc_0_PRAM2 controller and descriptor 2 */
        (uint32)0xffffffffUL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this memory range */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Xrdc MRGD bit lock*/
        XRDC_MRGD_W3_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Select Memory region controller Xrdc_0_PRAM3 will be used to control the address range below */
        XRDC_MRC0,
        /*Each memory region controller include 16 descriptors to write configuration. If multiple descriptors are configured the policy will be ORed by all the descriptors */
        (uint32)3UL,
        /*Start address for Xrdc_0_PRAM3 controller and descriptor 3 */
        (uint32)0x0UL,
        /*End address for Xrdc_0_PRAM3 controller and descriptor 3 */
        (uint32)0xffffffffUL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this memory range */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Xrdc MRGD bit lock*/
        XRDC_MRGD_W3_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Select Memory region controller Xrdc_0_QuadSPI will be used to control the address range below */
        XRDC_MRC1,
        /*Each memory region controller include 16 descriptors to write configuration. If multiple descriptors are configured the policy will be ORed by all the descriptors */
        (uint32)0UL,
        /*Start address for Xrdc_0_QuadSPI controller and descriptor 0 */
        (uint32)0x0UL,
        /*End address for Xrdc_0_QuadSPI controller and descriptor 0 */
        (uint32)0xffffffffUL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this memory range */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Xrdc MRGD bit lock*/
        XRDC_MRGD_W3_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Select Memory region controller Xrdc_0_M7_TCM0 will be used to control the address range below */
        XRDC_MRC2,
        /*Each memory region controller include 16 descriptors to write configuration. If multiple descriptors are configured the policy will be ORed by all the descriptors */
        (uint32)0UL,
        /*Start address for Xrdc_0_M7_TCM0 controller and descriptor 0 */
        (uint32)0x0UL,
        /*End address for Xrdc_0_M7_TCM0 controller and descriptor 0 */
        (uint32)0xffffffffUL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this memory range */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Xrdc MRGD bit lock*/
        XRDC_MRGD_W3_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Select Memory region controller Xrdc_0_M7_TCM1 will be used to control the address range below */
        XRDC_MRC2,
        /*Each memory region controller include 16 descriptors to write configuration. If multiple descriptors are configured the policy will be ORed by all the descriptors */
        (uint32)1UL,
        /*Start address for Xrdc_0_M7_TCM1 controller and descriptor 1 */
        (uint32)0x0UL,
        /*End address for Xrdc_0_M7_TCM1 controller and descriptor 1 */
        (uint32)0xffffffffUL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this memory range */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Xrdc MRGD bit lock*/
        XRDC_MRGD_W3_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Select Memory region controller Xrdc_0_S_DBG_APB will be used to control the address range below */
        XRDC_MRC3,
        /*Each memory region controller include 16 descriptors to write configuration. If multiple descriptors are configured the policy will be ORed by all the descriptors */
        (uint32)0UL,
        /*Start address for Xrdc_0_S_DBG_APB controller and descriptor 0 */
        (uint32)0x0UL,
        /*End address for Xrdc_0_S_DBG_APB controller and descriptor 0 */
        (uint32)0xffffffffUL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this memory range */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Xrdc MRGD bit lock*/
        XRDC_MRGD_W3_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Select Memory region controller Xrdc_0_PRAM4 will be used to control the address range below */
        XRDC_MRC4,
        /*Each memory region controller include 16 descriptors to write configuration. If multiple descriptors are configured the policy will be ORed by all the descriptors */
        (uint32)0UL,
        /*Start address for Xrdc_0_PRAM4 controller and descriptor 0 */
        (uint32)0x0UL,
        /*End address for Xrdc_0_PRAM4 controller and descriptor 0 */
        (uint32)0xffffffffUL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this memory range */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Xrdc MRGD bit lock*/
        XRDC_MRGD_W3_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Select Memory region controller Xrdc_0_PRAM5 will be used to control the address range below */
        XRDC_MRC4,
        /*Each memory region controller include 16 descriptors to write configuration. If multiple descriptors are configured the policy will be ORed by all the descriptors */
        (uint32)1UL,
        /*Start address for Xrdc_0_PRAM5 controller and descriptor 1 */
        (uint32)0x0UL,
        /*End address for Xrdc_0_PRAM5 controller and descriptor 1 */
        (uint32)0xffffffffUL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this memory range */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Xrdc MRGD bit lock*/
        XRDC_MRGD_W3_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Select Memory region controller Xrdc_0_PRAM6 will be used to control the address range below */
        XRDC_MRC4,
        /*Each memory region controller include 16 descriptors to write configuration. If multiple descriptors are configured the policy will be ORed by all the descriptors */
        (uint32)2UL,
        /*Start address for Xrdc_0_PRAM6 controller and descriptor 2 */
        (uint32)0x0UL,
        /*End address for Xrdc_0_PRAM6 controller and descriptor 2 */
        (uint32)0xffffffffUL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this memory range */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Xrdc MRGD bit lock*/
        XRDC_MRGD_W3_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Select Memory region controller Xrdc_0_PRAM7 will be used to control the address range below */
        XRDC_MRC4,
        /*Each memory region controller include 16 descriptors to write configuration. If multiple descriptors are configured the policy will be ORed by all the descriptors */
        (uint32)3UL,
        /*Start address for Xrdc_0_PRAM7 controller and descriptor 3 */
        (uint32)0x0UL,
        /*End address for Xrdc_0_PRAM7 controller and descriptor 3 */
        (uint32)0xffffffffUL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this memory range */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Xrdc MRGD bit lock*/
        XRDC_MRGD_W3_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Select Memory region controller Xrdc_0_Retention_RAM will be used to control the address range below */
        XRDC_MRC4,
        /*Each memory region controller include 16 descriptors to write configuration. If multiple descriptors are configured the policy will be ORed by all the descriptors */
        (uint32)4UL,
        /*Start address for Xrdc_0_Retention_RAM controller and descriptor 4 */
        (uint32)0x0UL,
        /*End address for Xrdc_0_Retention_RAM controller and descriptor 4 */
        (uint32)0xffffffffUL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this memory range */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Xrdc MRGD bit lock*/
        XRDC_MRGD_W3_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    }
};

static const Xrdc_Ip_PeripheralConfigType Xrdc_Peripheral_Config_XRDC_INSTANCE0[95] =
{
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)0UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)1UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)4UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)5UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)6UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)12UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)13UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)14UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)15UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)16UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)17UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)33UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)35UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)36UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)42UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)45UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)47UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)48UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)50UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)51UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)52UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)53UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)54UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)56UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)57UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)59UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)61UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)63UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)64UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)65UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)67UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)69UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)70UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)74UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)77UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)78UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)84UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)85UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)128UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)129UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)130UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)131UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)132UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)133UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)134UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)135UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)136UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)137UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)138UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)139UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)140UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)141UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)142UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)143UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)144UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)145UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)159UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)160UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)161UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)162UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)164UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)165UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)166UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)168UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)169UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)176UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)178UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)179UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)180UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)258UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)259UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)260UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)261UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)262UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)263UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)264UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)265UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)266UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)267UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)268UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)269UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)270UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)271UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)272UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)273UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)275UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)287UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)288UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)289UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)290UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)291UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)292UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)294UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)296UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)304UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    }
};

static const Xrdc_Ip_DomainConfigType Xrdc_Domain_Config_XRDC_INSTANCE0[5] =
{
    {
        /*Valid DomainID*/
        XRDC_DOMAIN0,
        /*Select the MDA register respect the Master instance */
        XRDC_MDAC5,
        /*Attribute to specfiy the type of current master which is core or non core master*/
        XRDC_CORE_MASTER,
        /*PID field only has meaning if the core is core master type and PID mode enable*/
        0,
        /*PID mask*/
        0,
        /*PID mode enable - only valid if the master instance is core type*/
        XRDC_MDA_PID_DISABLE,
        /*Three State Model to be done later if architecture support*/
        0UL,
        /*Selection of descriptor for current master core. If master is non-core master this field should be omitted*/
        XRDC_WORD0,
        /*Domain ID bypass. If master is core master this field should be omitted*/
        XRDC_MDA_DID_BYPASS_USED,
        /*Xrdc MDA DFMT bit lock*/
        XRDC_MDA_LK1_UNLOCK,
        /*Domain Secure Mode*/
        XRDC_SECURE,
        /*Domain Priviledged Mode*/
        XRDC_INPUT_PRIVILEDGE_FROM_BUS_MASTER
    },
    {
        /*Valid DomainID*/
        XRDC_DOMAIN0,
        /*Select the MDA register respect the Master instance */
        XRDC_MDAC1,
        /*Attribute to specfiy the type of current master which is core or non core master*/
        XRDC_CORE_MASTER,
        /*PID field only has meaning if the core is core master type and PID mode enable*/
        0,
        /*PID mask*/
        0,
        /*PID mode enable - only valid if the master instance is core type*/
        XRDC_MDA_PID_DISABLE,
        /*Three State Model to be done later if architecture support*/
        0UL,
        /*Selection of descriptor for current master core. If master is non-core master this field should be omitted*/
        XRDC_WORD0,
        /*Domain ID bypass. If master is core master this field should be omitted*/
        XRDC_MDA_DID_BYPASS_USED,
        /*Xrdc MDA DFMT bit lock*/
        XRDC_MDA_LK1_UNLOCK,
        /*Domain Secure Mode*/
        XRDC_SECURE,
        /*Domain Priviledged Mode*/
        XRDC_INPUT_PRIVILEDGE_FROM_BUS_MASTER
    },
    {
        /*Valid DomainID*/
        XRDC_DOMAIN0,
        /*Select the MDA register respect the Master instance */
        XRDC_MDAC3,
        /*Attribute to specfiy the type of current master which is core or non core master*/
        XRDC_NONCORE_MASTER,
        /*PID field only has meaning if the core is core master type and PID mode enable*/
        0,
        /*PID mask*/
        0,
        /*PID mode enable - only valid if the master instance is core type*/
        XRDC_MDA_PID_DISABLE,
        /*Three State Model to be done later if architecture support*/
        0UL,
        /*Selection of descriptor for current master core. If master is non-core master this field should be omitted*/
        XRDC_WORD0,
        /*Domain ID bypass. If master is core master this field should be omitted*/
        XRDC_MDA_DID_BYPASS_USED,
        /*Xrdc MDA DFMT bit lock*/
        XRDC_MDA_LK1_UNLOCK,
        /*Domain Secure Mode*/
        XRDC_SECURE,
        /*Domain Priviledged Mode*/
        XRDC_INPUT_PRIVILEDGE_FROM_BUS_MASTER
    },
    {
        /*Valid DomainID*/
        XRDC_DOMAIN0,
        /*Select the MDA register respect the Master instance */
        XRDC_MDAC4,
        /*Attribute to specfiy the type of current master which is core or non core master*/
        XRDC_NONCORE_MASTER,
        /*PID field only has meaning if the core is core master type and PID mode enable*/
        0,
        /*PID mask*/
        0,
        /*PID mode enable - only valid if the master instance is core type*/
        XRDC_MDA_PID_DISABLE,
        /*Three State Model to be done later if architecture support*/
        0UL,
        /*Selection of descriptor for current master core. If master is non-core master this field should be omitted*/
        XRDC_WORD0,
        /*Domain ID bypass. If master is core master this field should be omitted*/
        XRDC_MDA_DID_BYPASS_USED,
        /*Xrdc MDA DFMT bit lock*/
        XRDC_MDA_LK1_UNLOCK,
        /*Domain Secure Mode*/
        XRDC_SECURE,
        /*Domain Priviledged Mode*/
        XRDC_INPUT_PRIVILEDGE_FROM_BUS_MASTER
    },
    {
        /*Valid DomainID*/
        XRDC_DOMAIN0,
        /*Select the MDA register respect the Master instance */
        XRDC_MDAC7,
        /*Attribute to specfiy the type of current master which is core or non core master*/
        XRDC_NONCORE_MASTER,
        /*PID field only has meaning if the core is core master type and PID mode enable*/
        0,
        /*PID mask*/
        0,
        /*PID mode enable - only valid if the master instance is core type*/
        XRDC_MDA_PID_DISABLE,
        /*Three State Model to be done later if architecture support*/
        0UL,
        /*Selection of descriptor for current master core. If master is non-core master this field should be omitted*/
        XRDC_WORD0,
        /*Domain ID bypass. If master is core master this field should be omitted*/
        XRDC_MDA_DID_BYPASS_USED,
        /*Xrdc MDA DFMT bit lock*/
        XRDC_MDA_LK1_UNLOCK,
        /*Domain Secure Mode*/
        XRDC_SECURE,
        /*Domain Priviledged Mode*/
        XRDC_INPUT_PRIVILEDGE_FROM_BUS_MASTER
    }
};

static const Xrdc_Ip_InstanceConfigType Xrdc_Config_XRDC_INSTANCE0 =
{
    XRDC_INSTANCE0,
    Xrdc_Domain_Config_XRDC_INSTANCE0,
    (uint32)5UL,
    Xrdc_Memory_Config_XRDC_INSTANCE0,
    (uint32)13UL,
    Xrdc_Peripheral_Config_XRDC_INSTANCE0,
    (uint32)95UL,
    /*Xrdc CR bit lock*/
    XRDC_CR_UNLOCK,
    XRDC_PID_UNLOCKED
};

/* XRDC instance: XRDC_INSTANCE1 */
static const Xrdc_Ip_MemConfigType Xrdc_Memory_Config_XRDC_INSTANCE1[7] =
{
    {
        /*Select Memory region controller Xrdc_1_SRAM0 will be used to control the address range below */
        XRDC_MRC0,
        /*Each memory region controller include 16 descriptors to write configuration. If multiple descriptors are configured the policy will be ORed by all the descriptors */
        (uint32)0UL,
        /*Start address for Xrdc_1_SRAM0 controller and descriptor 0 */
        (uint32)0x0UL,
        /*End address for Xrdc_1_SRAM0 controller and descriptor 0 */
        (uint32)0xffffffffUL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this memory range */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Xrdc MRGD bit lock*/
        XRDC_MRGD_W3_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Select Memory region controller Xrdc_1_SRAM1 will be used to control the address range below */
        XRDC_MRC0,
        /*Each memory region controller include 16 descriptors to write configuration. If multiple descriptors are configured the policy will be ORed by all the descriptors */
        (uint32)1UL,
        /*Start address for Xrdc_1_SRAM1 controller and descriptor 1 */
        (uint32)0x0UL,
        /*End address for Xrdc_1_SRAM1 controller and descriptor 1 */
        (uint32)0xffffffffUL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this memory range */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Xrdc MRGD bit lock*/
        XRDC_MRGD_W3_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Select Memory region controller Xrdc_1_SRAM2 will be used to control the address range below */
        XRDC_MRC0,
        /*Each memory region controller include 16 descriptors to write configuration. If multiple descriptors are configured the policy will be ORed by all the descriptors */
        (uint32)2UL,
        /*Start address for Xrdc_1_SRAM2 controller and descriptor 2 */
        (uint32)0x0UL,
        /*End address for Xrdc_1_SRAM2 controller and descriptor 2 */
        (uint32)0xffffffffUL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this memory range */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Xrdc MRGD bit lock*/
        XRDC_MRGD_W3_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Select Memory region controller Xrdc_1_SRAM3 will be used to control the address range below */
        XRDC_MRC0,
        /*Each memory region controller include 16 descriptors to write configuration. If multiple descriptors are configured the policy will be ORed by all the descriptors */
        (uint32)3UL,
        /*Start address for Xrdc_1_SRAM3 controller and descriptor 3 */
        (uint32)0x0UL,
        /*End address for Xrdc_1_SRAM3 controller and descriptor 3 */
        (uint32)0xffffffffUL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this memory range */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Xrdc MRGD bit lock*/
        XRDC_MRGD_W3_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Select Memory region controller Xrdc_1_BBE32EP_DSP will be used to control the address range below */
        XRDC_MRC1,
        /*Each memory region controller include 16 descriptors to write configuration. If multiple descriptors are configured the policy will be ORed by all the descriptors */
        (uint32)0UL,
        /*Start address for Xrdc_1_BBE32EP_DSP controller and descriptor 0 */
        (uint32)0x0UL,
        /*End address for Xrdc_1_BBE32EP_DSP controller and descriptor 0 */
        (uint32)0xffffffffUL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this memory range */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Xrdc MRGD bit lock*/
        XRDC_MRGD_W3_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Select Memory region controller Xrdc_1_GIC_500 will be used to control the address range below */
        XRDC_MRC2,
        /*Each memory region controller include 16 descriptors to write configuration. If multiple descriptors are configured the policy will be ORed by all the descriptors */
        (uint32)0UL,
        /*Start address for Xrdc_1_GIC_500 controller and descriptor 0 */
        (uint32)0x0UL,
        /*End address for Xrdc_1_GIC_500 controller and descriptor 0 */
        (uint32)0xffffffffUL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this memory range */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Xrdc MRGD bit lock*/
        XRDC_MRGD_W3_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Select Memory region controller Xrdc_1_NoC will be used to control the address range below */
        XRDC_MRC3,
        /*Each memory region controller include 16 descriptors to write configuration. If multiple descriptors are configured the policy will be ORed by all the descriptors */
        (uint32)0UL,
        /*Start address for Xrdc_1_NoC controller and descriptor 0 */
        (uint32)0x0UL,
        /*End address for Xrdc_1_NoC controller and descriptor 0 */
        (uint32)0xffffffffUL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this memory range */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Xrdc MRGD bit lock*/
        XRDC_MRGD_W3_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    }
};

static const Xrdc_Ip_PeripheralConfigType Xrdc_Peripheral_Config_XRDC_INSTANCE1[21] =
{
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)0UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)1UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)2UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)3UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)4UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)32UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)33UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)36UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)37UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)39UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)40UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)41UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)43UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)48UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)50UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)51UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)52UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)53UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)54UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)57UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    },
    {
        /*Peripheral slot number of a block of peripherals. Checking Reference manual for chip specific*/
        (uint32)58UL,
        /*Enable Semaphore would require the domain must own the gate to have access right for this peripheral slot */
        (uint32)XRDC_SEMA4_DISABLE,
        /*Number of the gate of sema4 for granting access*/
        (uint32)0UL,
        /*Enable or disable PDAC lock bit. */
        (uint32)XRDC_PDAC_W1_UNLOCK,
        /*Access policy for Domains 0-7 is calculated automatically*/
        (uint32)0x7UL,
        /*Access policy for Domains 8-15 is calculated automatically*/
        (uint32)0x0UL
    }
};

static const Xrdc_Ip_DomainConfigType Xrdc_Domain_Config_XRDC_INSTANCE1[7] =
{
    {
        /*Valid DomainID*/
        XRDC_DOMAIN0,
        /*Select the MDA register respect the Master instance */
        XRDC_MDAC0,
        /*Attribute to specfiy the type of current master which is core or non core master*/
        XRDC_CORE_MASTER,
        /*PID field only has meaning if the core is core master type and PID mode enable*/
        0,
        /*PID mask*/
        0,
        /*PID mode enable - only valid if the master instance is core type*/
        XRDC_MDA_PID_DISABLE,
        /*Three State Model to be done later if architecture support*/
        0UL,
        /*Selection of descriptor for current master core. If master is non-core master this field should be omitted*/
        XRDC_WORD0,
        /*Domain ID bypass. If master is core master this field should be omitted*/
        XRDC_MDA_DID_BYPASS_USED,
        /*Xrdc MDA DFMT bit lock*/
        XRDC_MDA_LK1_UNLOCK,
        /*Domain Secure Mode*/
        XRDC_SECURE,
        /*Domain Priviledged Mode*/
        XRDC_INPUT_PRIVILEDGE_FROM_BUS_MASTER
    },
    {
        /*Valid DomainID*/
        XRDC_DOMAIN0,
        /*Select the MDA register respect the Master instance */
        XRDC_MDAC1,
        /*Attribute to specfiy the type of current master which is core or non core master*/
        XRDC_NONCORE_MASTER,
        /*PID field only has meaning if the core is core master type and PID mode enable*/
        0,
        /*PID mask*/
        0,
        /*PID mode enable - only valid if the master instance is core type*/
        XRDC_MDA_PID_DISABLE,
        /*Three State Model to be done later if architecture support*/
        0UL,
        /*Selection of descriptor for current master core. If master is non-core master this field should be omitted*/
        XRDC_WORD0,
        /*Domain ID bypass. If master is core master this field should be omitted*/
        XRDC_MDA_DID_BYPASS_USED,
        /*Xrdc MDA DFMT bit lock*/
        XRDC_MDA_LK1_UNLOCK,
        /*Domain Secure Mode*/
        XRDC_SECURE,
        /*Domain Priviledged Mode*/
        XRDC_INPUT_PRIVILEDGE_FROM_BUS_MASTER
    },
    {
        /*Valid DomainID*/
        XRDC_DOMAIN0,
        /*Select the MDA register respect the Master instance */
        XRDC_MDAC2,
        /*Attribute to specfiy the type of current master which is core or non core master*/
        XRDC_NONCORE_MASTER,
        /*PID field only has meaning if the core is core master type and PID mode enable*/
        0,
        /*PID mask*/
        0,
        /*PID mode enable - only valid if the master instance is core type*/
        XRDC_MDA_PID_DISABLE,
        /*Three State Model to be done later if architecture support*/
        0UL,
        /*Selection of descriptor for current master core. If master is non-core master this field should be omitted*/
        XRDC_WORD0,
        /*Domain ID bypass. If master is core master this field should be omitted*/
        XRDC_MDA_DID_BYPASS_USED,
        /*Xrdc MDA DFMT bit lock*/
        XRDC_MDA_LK1_UNLOCK,
        /*Domain Secure Mode*/
        XRDC_SECURE,
        /*Domain Priviledged Mode*/
        XRDC_PRIVILEDGE_MODE
    },
    {
        /*Valid DomainID*/
        XRDC_DOMAIN0,
        /*Select the MDA register respect the Master instance */
        XRDC_MDAC3,
        /*Attribute to specfiy the type of current master which is core or non core master*/
        XRDC_NONCORE_MASTER,
        /*PID field only has meaning if the core is core master type and PID mode enable*/
        0,
        /*PID mask*/
        0,
        /*PID mode enable - only valid if the master instance is core type*/
        XRDC_MDA_PID_DISABLE,
        /*Three State Model to be done later if architecture support*/
        0UL,
        /*Selection of descriptor for current master core. If master is non-core master this field should be omitted*/
        XRDC_WORD0,
        /*Domain ID bypass. If master is core master this field should be omitted*/
        XRDC_MDA_DID_BYPASS_USED,
        /*Xrdc MDA DFMT bit lock*/
        XRDC_MDA_LK1_UNLOCK,
        /*Domain Secure Mode*/
        XRDC_SECURE,
        /*Domain Priviledged Mode*/
        XRDC_PRIVILEDGE_MODE
    },
    {
        /*Valid DomainID*/
        XRDC_DOMAIN0,
        /*Select the MDA register respect the Master instance */
        XRDC_MDAC4,
        /*Attribute to specfiy the type of current master which is core or non core master*/
        XRDC_NONCORE_MASTER,
        /*PID field only has meaning if the core is core master type and PID mode enable*/
        0,
        /*PID mask*/
        0,
        /*PID mode enable - only valid if the master instance is core type*/
        XRDC_MDA_PID_DISABLE,
        /*Three State Model to be done later if architecture support*/
        0UL,
        /*Selection of descriptor for current master core. If master is non-core master this field should be omitted*/
        XRDC_WORD0,
        /*Domain ID bypass. If master is core master this field should be omitted*/
        XRDC_MDA_DID_BYPASS_USED,
        /*Xrdc MDA DFMT bit lock*/
        XRDC_MDA_LK1_UNLOCK,
        /*Domain Secure Mode*/
        XRDC_SECURE,
        /*Domain Priviledged Mode*/
        XRDC_INPUT_PRIVILEDGE_FROM_BUS_MASTER
    },
    {
        /*Valid DomainID*/
        XRDC_DOMAIN0,
        /*Select the MDA register respect the Master instance */
        XRDC_MDAC5,
        /*Attribute to specfiy the type of current master which is core or non core master*/
        XRDC_NONCORE_MASTER,
        /*PID field only has meaning if the core is core master type and PID mode enable*/
        0,
        /*PID mask*/
        0,
        /*PID mode enable - only valid if the master instance is core type*/
        XRDC_MDA_PID_DISABLE,
        /*Three State Model to be done later if architecture support*/
        0UL,
        /*Selection of descriptor for current master core. If master is non-core master this field should be omitted*/
        XRDC_WORD0,
        /*Domain ID bypass. If master is core master this field should be omitted*/
        XRDC_MDA_DID_BYPASS_USED,
        /*Xrdc MDA DFMT bit lock*/
        XRDC_MDA_LK1_UNLOCK,
        /*Domain Secure Mode*/
        XRDC_SECURE,
        /*Domain Priviledged Mode*/
        XRDC_INPUT_PRIVILEDGE_FROM_BUS_MASTER
    },
    {
        /*Valid DomainID*/
        XRDC_DOMAIN0,
        /*Select the MDA register respect the Master instance */
        XRDC_MDAC6,
        /*Attribute to specfiy the type of current master which is core or non core master*/
        XRDC_NONCORE_MASTER,
        /*PID field only has meaning if the core is core master type and PID mode enable*/
        0,
        /*PID mask*/
        0,
        /*PID mode enable - only valid if the master instance is core type*/
        XRDC_MDA_PID_DISABLE,
        /*Three State Model to be done later if architecture support*/
        0UL,
        /*Selection of descriptor for current master core. If master is non-core master this field should be omitted*/
        XRDC_WORD0,
        /*Domain ID bypass. If master is core master this field should be omitted*/
        XRDC_MDA_DID_BYPASS_USED,
        /*Xrdc MDA DFMT bit lock*/
        XRDC_MDA_LK1_UNLOCK,
        /*Domain Secure Mode*/
        XRDC_SECURE,
        /*Domain Priviledged Mode*/
        XRDC_INPUT_PRIVILEDGE_FROM_BUS_MASTER
    }
};

static const Xrdc_Ip_InstanceConfigType Xrdc_Config_XRDC_INSTANCE1 =
{
    XRDC_INSTANCE1,
    Xrdc_Domain_Config_XRDC_INSTANCE1,
    (uint32)7UL,
    Xrdc_Memory_Config_XRDC_INSTANCE1,
    (uint32)7UL,
    Xrdc_Peripheral_Config_XRDC_INSTANCE1,
    (uint32)21UL,
    /*Xrdc CR bit lock*/
    XRDC_CR_UNLOCK,
    XRDC_PID_UNLOCKED
};

static const Xrdc_Ip_InstanceConfigType * const aXrdc_Config_Array[2] = {&Xrdc_Config_XRDC_INSTANCE0,&Xrdc_Config_XRDC_INSTANCE1};

const Xrdc_Ip_ConfigType Xrdc_Config =
{
    aXrdc_Config_Array,
    (uint32)2UL,
    Xrdc_Instances_InUsed,
    (uint32)2UL
};

#define RM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rm_MemMap.h"


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

