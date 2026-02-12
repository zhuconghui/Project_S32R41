
/*
 * Copyright 2022-2023 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */









#ifndef CSI2_CFG_H
#define CSI2_CFG_H


#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

    #include "StandardTypes.h"
    #include "CDD_Csi2_PCCfg.h"
	#include "rsdk_version.h"




/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/

    #define CSI2_CFG_VENDOR_ID                        43
    #define CSI2_CFG_AR_RELEASE_MAJOR_VERSION         RSDK_AR_MAJOR
    #define CSI2_CFG_AR_RELEASE_MINOR_VERSION         RSDK_AR_MINOR
    #define CSI2_CFG_AR_RELEASE_REVISION_VERSION      RSDK_AR_REV
    #define CSI2_CFG_SW_MAJOR_VERSION                 RSDK_SW_MAJOR
    #define CSI2_CFG_SW_MINOR_VERSION                 RSDK_SW_MINOR
    #define CSI2_CFG_SW_PATCH_VERSION     			  RSDK_SW_PATCH


/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
        /* Check if header file and StandardTypes header file are of the same AutoSar version */
        #if ((CSI2_CFG_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
             (CSI2_CFG_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)    \
            )
            #error "AutoSar Version Numbers of CSI2_Cfg.h and StandardTypes.h are different"
        #endif
    #endif

    /* Check Csi2_PCCfg.h versions                                                                                      */
    #if (CSI2_CFG_VENDOR_ID != CSI2_PCCFG_VENDOR_ID)
        #error "Csi2_Cfg.h and Csi2_PCCfg.h have different vendor ids"
    #endif

    /* Check if Csi2_Cfg header file and Csi2_PCCfg configuration header file are of the same Autosar version       */
    #if ((CSI2_CFG_AR_RELEASE_MAJOR_VERSION    != CSI2_PCCFG_AR_RELEASE_MAJOR_VERSION) ||   \
         (CSI2_CFG_AR_RELEASE_MINOR_VERSION    != CSI2_PCCFG_AR_RELEASE_MINOR_VERSION) ||   \
         (CSI2_CFG_AR_RELEASE_REVISION_VERSION != CSI2_PCCFG_AR_RELEASE_REVISION_VERSION)   \
        )
        #error "AutoSar Version Numbers of Csi2_Cfg.h and Csi2_PCCfg.h are different"
    #endif

    /* Check if Csi2_Cfg header file and Csi2_PCCfg configuration header file are of the same software version      */
    #if ((CSI2_CFG_SW_MAJOR_VERSION    != CSI2_PCCFG_SW_MAJOR_VERSION) ||     \
         (CSI2_CFG_SW_MINOR_VERSION    != CSI2_PCCFG_SW_MINOR_VERSION) ||     \
         (CSI2_CFG_SW_PATCH_VERSION    != CSI2_PCCFG_SW_PATCH_VERSION)        \
        )
        #error "Software Version Numbers of Csi2_Cfg.h and Csi2_PCCfg.h are different"
    #endif


/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/





















/**
*   @addtogroup csi2_asr_api_const
*   @{
*/
/* Pre-processor switch to enable/disable development error detection for Csi2 API */
    #ifndef CSI2_DEV_ERROR_DETECT
        #define CSI2_DEV_ERROR_DETECT               STD_ON
    #endif
/* Pre-processor switch to enable/disable stop execution after error detection for Csi2 API */
    #ifndef CSI2_DEV_HALT_ON_ERROR
        #define CSI2_DEV_HALT_ON_ERROR              STD_OFF
    #endif
/** @} */




/** @{ */

    /**
    * @brief    Pre-processor switch to define single Csi2 management thread or multiple Csi2 management threads.
    * @details  If single thread (the normal approach) - there are no necessary exclusive areas for the driver.
    *           This value is predefined in CDD_Csi2_PCCfg.h at configuration time.                                 */
    #ifndef CSI2_SINGLE_MANAGEMENT_THREADS
        #define CSI2_SINGLE_MANAGEMENT_THREADS      STD_ON
    #endif


    /** @brief  Pre-processor switch to enable/disable version info report for Csi2 API 
    * @details  This value is predefined in CDD_Csi2_PCCfg.h at configuration time.                                 */
    #ifndef CSI2_VERSION_INFO_API
        #define CSI2_VERSION_INFO_API               STD_ON
    #endif

    /** @brief  Pre-processor switch to enable/disable statistics usage for received data for Csi2 API 
    * @details  This value is predefined in CDD_Csi2_PCCfg.h at configuration time.                                 */
    #ifndef CSI2_STATISTIC_DATA_USAGE
        #define CSI2_STATISTIC_DATA_USAGE           STD_ON
    #endif

    /** @brief  Pre-processor switch to enable/disable DC auto compensation for received data on CSI2 API 
    * @details  This value is predefined in CDD_Csi2_PCCfg.h at configuration time.                                 */
    #if (CSI2_STATISTIC_DATA_USAGE == STD_ON)
        #ifndef CSI2_AUTO_DC_COMPENSATION
            #define CSI2_AUTO_DC_COMPENSATION       STD_ON
        #endif
    #else
        #define CSI2_AUTO_DC_COMPENSATION       STD_OFF

    #endif

    /** @brief  Pre-processor switch to enable/disable auxiliary data usage for received data on CSI2 API 
    * @details  This value is predefined in CDD_Csi2_PCCfg.h at configuration time.                                 */
    #ifndef CSI2_AUXILIARY_DATA_USAGE
        #define CSI2_AUXILIARY_DATA_USAGE           STD_ON
    #endif

    /** @brief  Pre-processor switch to enable/disable metadata usage for received data on CSI2 API 
    * @details  This value is predefined in CDD_Csi2_PCCfg.h at configuration time.                                 */
    #ifndef CSI2_METADATA_DATA_USAGE
        #define CSI2_METADATA_DATA_USAGE            STD_ON
    #endif

    /** @brief  Pre-processor switch to enable/disable single ISR callback for CSI2 API 
    * @details  This value is predefined in CDD_Csi2_PCCfg.h at configuration time.                                 */
    #ifndef CSI2_SINGLE_CALLBACK_USAGE
        #define CSI2_SINGLE_CALLBACK_USAGE          STD_ON
    #endif

    /** @brief  Pre-processor switch to enable/disable Rx start/stop usage in CSI2 API 
    * @details  This value is predefined in CDD_Csi2_PCCfg.h at configuration time.                                 */
    #ifndef CSI2_RX_START_STOP_USAGE
        #define CSI2_RX_START_STOP_USAGE            STD_ON
    #endif

    /** @brief  Pre-processor switch to enable/disable power on/off usage in CSI2 API 
    * @details  This value is predefined in CDD_Csi2_PCCfg.h at configuration time.                                 */
    #ifndef CSI2_POWER_ON_OFF_USAGE
        #define CSI2_POWER_ON_OFF_USAGE             STD_ON
    #endif

    /** @brief  Pre-processor switch to enable/disable secondary functions usage in CSI2 API 
    * @details  This value is predefined in CDD_Csi2_PCCfg.h at configuration time.                                 */
    #ifndef CSI2_SECONDARY_FUNCTIONS_USAGE
        #define CSI2_SECONDARY_FUNCTIONS_USAGE      STD_ON
    #endif

    /** @brief  Pre-processor switch to enable/disable internal frames counter usage in CSI2 API 
    * @details  This value is predefined in CDD_Csi2_PCCfg.h at configuration time.                                 */
    #ifndef CSI2_FRAMES_COUNTER_USED
        #define CSI2_FRAMES_COUNTER_USED            STD_ON
    #endif

    /** @brief  Pre-processor switch to enable/disable usage of GPIO in CSI2 API 
    * @details  This value is predefined in CDD_Csi2_PCCfg.h at configuration time.                                 */
    #ifndef CSI2_GPIO_USED
        #define CSI2_GPIO_USED                      STD_ON
    #endif

    /** @brief  Pre-processor switch to enable/disable usage of SDMA in CSI2 API 
    * @details  This value is predefined in CDD_Csi2_PCCfg.h at configuration time.                                 */
    #ifndef CSI2_SDMA_USED
        #define CSI2_SDMA_USED                      STD_ON
    #endif

    /** @brief  Pre-processor switch to enable/disable usage of CSI2-PHY, Rx only for SAF85XX/SAF86XX
    * @details  This value is predefined in CDD_Csi2_PCCfg.h at configuration time.                                 */











    /* Formal instance id for CSI2 driver, to be used at development time                                           */
    #define CSI2_INSTANCE_ID                        0u

    /* The type of timer to be used for necessary execution delays 
    * @details  This value is predefined in CDD_Csi2_PCCfg.h at configuration time.                                 */
    #if !defined(CSI2_TIMER_TYPE)
        #define CSI2_TIMER_TYPE                     CSI2_USING_COUNTER_DUMMY
    #endif
    #if (CSI2_TIMER_TYPE == CSI2_USING_COUNTER_DUMMY)
        #if defined(__OPTIMIZE_SIZE__)
            #define CSI2_US_DELAY   1110u
        #else
            #define CSI2_US_DELAY   1000u
        #endif
    #endif
    
/** @} */
    

















#if !defined(CSI2_DEV_HALT_ON_ERROR)
    #if (CSI2_DEV_HALT_ON_ERROR == STD_ON)
    /* Infinite loop if error detected and the option is to detect development errors */
        #define CSI2_HALT_ON_ERROR          while(gsCsi2LoopExit != TRUE)   \
                                            {                               \
                                                ;   /* empty loop */        \
                                            }
    #else
        #define CSI2_HALT_ON_ERROR
    #endif
#endif

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/



#ifdef __cplusplus
}
#endif

#endif /* CSI2_CFG_H */
