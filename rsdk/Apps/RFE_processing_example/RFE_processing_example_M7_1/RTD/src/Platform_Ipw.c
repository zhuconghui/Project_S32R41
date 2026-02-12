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
*   (c) Copyright 2021 - 2024 NXP
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

/**
*   @file
*
*   @internal
*   @addtogroup Platform_Ipw
*   @{
*/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/

#include "Platform_TypesDef.h"
#include "Platform_Ipw.h"
#include "Mcal.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_PLATFORM_IPW_VENDOR_ID_C                         43
#define CDD_PLATFORM_IPW_AR_RELEASE_MAJOR_VERSION_C          4
#define CDD_PLATFORM_IPW_AR_RELEASE_MINOR_VERSION_C          7
#define CDD_PLATFORM_IPW_AR_RELEASE_REVISION_VERSION_C       0
#define CDD_PLATFORM_IPW_SW_MAJOR_VERSION_C                  2
#define CDD_PLATFORM_IPW_SW_MINOR_VERSION_C                  0
#define CDD_PLATFORM_IPW_SW_PATCH_VERSION_C                  0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Platform_TypesDef header file are of the same vendor */
#if (CDD_PLATFORM_IPW_VENDOR_ID_C != CDD_PLATFORM_TYPESDEF_VENDOR_ID)
    #error "Platform_Ipw.c and Platform_TypesDef.h have different vendor ids"
#endif
/* Check if current file and Platform_TypesDef header file are of the same Autosar version */
#if ((CDD_PLATFORM_IPW_AR_RELEASE_MAJOR_VERSION_C    != CDD_PLATFORM_TYPESDEF_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_PLATFORM_IPW_AR_RELEASE_MINOR_VERSION_C    != CDD_PLATFORM_TYPESDEF_AR_RELEASE_MINOR_VERSION) || \
     (CDD_PLATFORM_IPW_AR_RELEASE_REVISION_VERSION_C != CDD_PLATFORM_TYPESDEF_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Platform_Ipw.c and Platform_TypesDef.h are different"
#endif
/* Check if current file and Platform_Ipw_Cfg header file are of the same Software version */
#if ((CDD_PLATFORM_IPW_SW_MAJOR_VERSION_C != CDD_PLATFORM_TYPESDEF_SW_MAJOR_VERSION) || \
     (CDD_PLATFORM_IPW_SW_MINOR_VERSION_C != CDD_PLATFORM_TYPESDEF_SW_MINOR_VERSION) || \
     (CDD_PLATFORM_IPW_SW_PATCH_VERSION_C != CDD_PLATFORM_TYPESDEF_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Platform_Ipw.c and Platform_TypesDef.h are different"
#endif

/* Check if current file and Platform_Ipw header file are of the same vendor */
#if (CDD_PLATFORM_IPW_VENDOR_ID_C != CDD_PLATFORM_IPW_VENDOR_ID)
    #error "Platform_Ipw.c and Platform_Ipw.h have different vendor ids"
#endif
/* Check if current file and Platform_Ipw header file are of the same Autosar version */
#if ((CDD_PLATFORM_IPW_AR_RELEASE_MAJOR_VERSION_C    != CDD_PLATFORM_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_PLATFORM_IPW_AR_RELEASE_MINOR_VERSION_C    != CDD_PLATFORM_IPW_AR_RELEASE_MINOR_VERSION) || \
     (CDD_PLATFORM_IPW_AR_RELEASE_REVISION_VERSION_C != CDD_PLATFORM_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Platform_Ipw.c and Platform_Ipw.h are different"
#endif
/* Check if current file and Platform_Ipw header file are of the same Software version */
#if ((CDD_PLATFORM_IPW_SW_MAJOR_VERSION_C != CDD_PLATFORM_IPW_SW_MAJOR_VERSION) || \
     (CDD_PLATFORM_IPW_SW_MINOR_VERSION_C != CDD_PLATFORM_IPW_SW_MINOR_VERSION) || \
     (CDD_PLATFORM_IPW_SW_PATCH_VERSION_C != CDD_PLATFORM_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Platform_Ipw.c and Platform_Ipw.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal.h header file are of the same Autosar version */
    #if ((CDD_PLATFORM_IPW_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (CDD_PLATFORM_IPW_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Platform_Ipw.c and Mcal.h are different"
    #endif
#endif

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"

#if ((STD_ON == PLATFORM_ENABLE_USER_MODE_SUPPORT) && (defined (MCAL_ENABLE_USER_MODE_SUPPORT)))
    #define Call_System_Ip_ConfigIrq(eIrq,bEnable)          OsIf_Trusted_Call2params(System_Ip_ConfigIrq,(eIrq),(bEnable))
    #define Call_System_Ip_SetAhbSlavePriority(bPriority)   OsIf_Trusted_Call1param(System_Ip_SetAhbSlavePriority,(bPriority))
#else
    #define Call_System_Ip_ConfigIrq(eIrq,bEnable)          System_Ip_ConfigIrq((eIrq),(bEnable))
    #define Call_System_Ip_SetAhbSlavePriority(bPriority)   System_Ip_SetAhbSlavePriority((bPriority))
#endif

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
 * @brief         Initializes the platform settings based on user configuration.
 */
void Platform_Ipw_Init(const Platform_Ipw_ConfigType *pConfig)
{
#if (PLATFORM_SYS_CFG == STD_ON)
    uint8 irqIdx;
#endif

    /* Initialize interrupts at interrupt controller level */
    if (NULL_PTR != pConfig->pIntCtrlConfig)
    {
        (void)IntCtrl_Ip_Init(pConfig->pIntCtrlConfig);
    }

#if (PLATFORM_SYS_CFG == STD_ON)
    /* Configure core-related interrupt requests */
    if (pConfig->aSystemConfig != NULL_PTR)
    {
        for (irqIdx = 0u; irqIdx < (pConfig->aSystemConfig)->u8SysIrqsCount; irqIdx++)
        {
            Call_System_Ip_ConfigIrq((pConfig->aSystemConfig)->aSystemIrqs[irqIdx].eIrq, (pConfig->aSystemConfig)->aSystemIrqs[irqIdx].bEnable);
        }
        Call_System_Ip_SetAhbSlavePriority((pConfig->aSystemConfig)->bAhbSlavePriority);
    }
#endif
}


#if (PLATFORM_ENABLE_MPU_M7 == STD_ON)
/**
* @brief        Platform_Ipw_Mpu_M7_Init
* @details
*
* @param[in]
*
* @param[out]
*
* @return
*
* @api
*
*/
void Platform_Ipw_Mpu_M7_Init(const Platform_Ipw_ConfigType * pIpwConfig)
{
    Mpu_M7_Ip_Init(pIpwConfig->Platform_Ipw_pMpuConfig);
}


/**
* @brief        Platform_Ipw_Mpu_M7_SetRegionConfig
* @details
*
* @param[in]
*
* @param[out]
*
* @return
*
* @api
*
*/
void Platform_Ipw_Mpu_M7_SetRegionConfig(uint8 u8RegionNum, const Platform_Mpu_M7_RegionConfigType * const pUserConfigPtr)
{
    Mpu_M7_Ip_SetRegionConfig(u8RegionNum, pUserConfigPtr);
}



/**
* @brief        Platform_Ipw_Mpu_M7_EnableRegion
* @details
*
* @param[in]
*
* @param[out]
*
* @return
*
* @api
*
*/
void Platform_Ipw_Mpu_M7_EnableRegion(uint8 u8RegionNum, boolean bEnable)
{
    Mpu_M7_Ip_EnableRegion(u8RegionNum, bEnable);
}

/**
* @brief        Platform_Ipw_Mpu_M7_SetAccessRight
* @details
*
* @param[in]
*
* @param[out]
*
* @return
*
* @api
*
*/
void Platform_Ipw_Mpu_M7_SetAccessRight(uint8 u8RegionNum, Platform_Mpu_M7_AccessRightsType eRights)
{
    Mpu_M7_Ip_SetAccessRight(u8RegionNum, eRights);
}

/**
* @brief        Platform_Ipw_Mpu_M7_GetErrorDetails
* @details
*
* @param[in]
*
* @param[out]
*
* @return
*
* @api
*
*/
boolean Platform_Ipw_Mpu_M7_GetErrorDetails(Platform_Mpu_M7_ErrorDetailsType * pErrorDetails)
{
    return Mpu_M7_Ip_GetErrorDetails(pErrorDetails);
}

#endif /* #if (STD_ON == PLATFORM_ENABLE_MPU_M7)  */

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"
