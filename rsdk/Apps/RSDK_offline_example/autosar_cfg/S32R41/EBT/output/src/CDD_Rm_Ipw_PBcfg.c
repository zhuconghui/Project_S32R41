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
*   @file CDD_Rm_Ipw_PBcfg.c
*
*   @addtogroup RM_MODULE RM Driver
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
#include "Mcal.h"
#include "Xrdc_Ip.h"
#include "Xbic_Ip.h"
#include "Dma_Mux_Ip.h"
#include "Mscm_Ip.h"
#include "CDD_Rm_Ipw_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_IPW_PBCFG_VENDOR_ID_C                     43
#define RM_IPW_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define RM_IPW_PBCFG_AR_RELEASE_MINOR_VERSION_C      7
#define RM_IPW_PBCFG_AR_RELEASE_REVISION_VERSION_C   0
#define RM_IPW_PBCFG_SW_MAJOR_VERSION_C              2
#define RM_IPW_PBCFG_SW_MINOR_VERSION_C              0
#define RM_IPW_PBCFG_SW_PATCH_VERSION_C              0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Mcal.h */
    #if ((RM_IPW_PBCFG_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (RM_IPW_PBCFG_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of CDD_Rm_Ipw_PBcfg.c and Mcal.h are different"
    #endif
#endif
/* Checks against CDD_Rm_Ipw_Cfg.h */
#if (RM_IPW_PBCFG_VENDOR_ID_C != RM_IPW_CFG_VENDOR_ID)
    #error "CDD_Rm_Ipw_PBcfg.c and CDD_Rm_Ipw_Cfg.h have different vendor ids"
#endif
#if ((RM_IPW_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != RM_IPW_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (RM_IPW_PBCFG_AR_RELEASE_MINOR_VERSION_C    != RM_IPW_CFG_AR_RELEASE_MINOR_VERSION) || \
     (RM_IPW_PBCFG_AR_RELEASE_REVISION_VERSION_C != RM_IPW_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of CDD_Rm_Ipw_PBcfg.c and CDD_Rm_Ipw_Cfg.h are different"
#endif
#if ((RM_IPW_PBCFG_SW_MAJOR_VERSION_C != RM_IPW_CFG_SW_MAJOR_VERSION) || \
     (RM_IPW_PBCFG_SW_MINOR_VERSION_C != RM_IPW_CFG_SW_MINOR_VERSION) || \
     (RM_IPW_PBCFG_SW_PATCH_VERSION_C != RM_IPW_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm_Ipw_PBcfg.c and CDD_Rm_Ipw_Cfg.h are different"
#endif

/* Checks against Xrdc_Ip.h */
#if (RM_IPW_PBCFG_VENDOR_ID_C != RM_XRDC_IP_VENDOR_ID)
    #error "CDD_Rm_Ipw_PBcfg.c and Xrdc_Ip.h have different vendor ids"
#endif
#if ((RM_IPW_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != RM_XRDC_IP_AR_RELEASE_MAJOR_VERSION) || \
     (RM_IPW_PBCFG_AR_RELEASE_MINOR_VERSION_C    != RM_XRDC_IP_AR_RELEASE_MINOR_VERSION) || \
     (RM_IPW_PBCFG_AR_RELEASE_REVISION_VERSION_C != RM_XRDC_IP_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of CDD_Rm_Ipw_PBcfg.c and Xrdc_Ip.h are different"
#endif
#if ((RM_IPW_PBCFG_SW_MAJOR_VERSION_C != RM_XRDC_IP_SW_MAJOR_VERSION) || \
     (RM_IPW_PBCFG_SW_MINOR_VERSION_C != RM_XRDC_IP_SW_MINOR_VERSION) || \
     (RM_IPW_PBCFG_SW_PATCH_VERSION_C != RM_XRDC_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm_Ipw_PBcfg.c and Xrdc_Ip.h are different"
#endif

/* Checks against Xbic_Ip.h */
#if ((RM_IPW_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != RM_XBIC_IP_AR_RELEASE_MAJOR_VERSION) || \
     (RM_IPW_PBCFG_AR_RELEASE_MINOR_VERSION_C    != RM_XBIC_IP_AR_RELEASE_MINOR_VERSION) || \
     (RM_IPW_PBCFG_AR_RELEASE_REVISION_VERSION_C != RM_XBIC_IP_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of CDD_Rm_Ipw_PBcfg.c and Xbic_Ip.h are different"
#endif
#if (RM_IPW_PBCFG_VENDOR_ID_C != RM_XBIC_IP_VENDOR_ID)
    #error "CDD_Rm_Ipw_PBcfg.c and Xbic_Ip.h have different vendor ids"
#endif
#if ((RM_IPW_PBCFG_SW_MAJOR_VERSION_C != RM_XBIC_IP_SW_MAJOR_VERSION) || \
     (RM_IPW_PBCFG_SW_MINOR_VERSION_C != RM_XBIC_IP_SW_MINOR_VERSION) || \
     (RM_IPW_PBCFG_SW_PATCH_VERSION_C != RM_XBIC_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm_Ipw_PBcfg.c and Xbic_Ip.h are different"
#endif

/* Checks against Dma_Mux_Ip.h */
#if (RM_IPW_PBCFG_VENDOR_ID_C != RM_DMA_MUX_IP_VENDOR_ID)
    #error "CDD_Rm_Ipw_PBcfg.c and Dma_Mux_Ip.h have different vendor ids"
#endif
#if ((RM_IPW_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != RM_DMA_MUX_IP_AR_RELEASE_MAJOR_VERSION) || \
     (RM_IPW_PBCFG_AR_RELEASE_MINOR_VERSION_C    != RM_DMA_MUX_IP_AR_RELEASE_MINOR_VERSION) || \
     (RM_IPW_PBCFG_AR_RELEASE_REVISION_VERSION_C != RM_DMA_MUX_IP_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of CDD_Rm_Ipw_PBcfg.c and Dma_Mux_Ip.h are different"
#endif
#if ((RM_IPW_PBCFG_SW_MAJOR_VERSION_C != RM_DMA_MUX_IP_SW_MAJOR_VERSION) || \
     (RM_IPW_PBCFG_SW_MINOR_VERSION_C != RM_DMA_MUX_IP_SW_MINOR_VERSION) || \
     (RM_IPW_PBCFG_SW_PATCH_VERSION_C != RM_DMA_MUX_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm_Ipw_PBcfg.c and Dma_Mux_Ip.h are different"
#endif

/* Checks against Mscm_Ip.h */
#if (RM_IPW_PBCFG_VENDOR_ID_C != RM_MSCM_IP_VENDOR_ID)
    #error "CDD_Rm_Ipw_PBcfg.c and Mscm_Ip.h have different vendor ids"
#endif
#if ((RM_IPW_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != RM_MSCM_IP_AR_RELEASE_MAJOR_VERSION) || \
     (RM_IPW_PBCFG_AR_RELEASE_MINOR_VERSION_C    != RM_MSCM_IP_AR_RELEASE_MINOR_VERSION) || \
     (RM_IPW_PBCFG_AR_RELEASE_REVISION_VERSION_C != RM_MSCM_IP_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of CDD_Rm_Ipw_PBcfg.c and Mscm_Ip.h are different"
#endif
#if ((RM_IPW_PBCFG_SW_MAJOR_VERSION_C != RM_MSCM_IP_SW_MAJOR_VERSION) || \
     (RM_IPW_PBCFG_SW_MINOR_VERSION_C != RM_MSCM_IP_SW_MINOR_VERSION) || \
     (RM_IPW_PBCFG_SW_PATCH_VERSION_C != RM_MSCM_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm_Ipw_PBcfg.c and Mscm_Ip.h are different"
#endif

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
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



const Rm_Ipw_ConfigType Rm_Ipw_Config =
{
    &Xrdc_Config,
    &Mscm_Config
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

