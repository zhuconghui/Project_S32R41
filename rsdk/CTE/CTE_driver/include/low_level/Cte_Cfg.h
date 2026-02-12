
/*==================================================================================================
 * Copyright 2022-2024 NXP Semiconductors
 *
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
==================================================================================================*/








#ifndef CTE_CFG_H
#define CTE_CFG_H

/**
*   @file
*
*   @internal
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

    #include "StandardTypes.h"
    #include "Cte_PCCfg.h"
    #include "rsdk_version.h"
    #include "rsdk_status.h"
    #include "rsdk_status_helper.h"




/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/

    #define CTE_CFG_VENDOR_ID                        43
    #define CTE_CFG_AR_RELEASE_MAJOR_VERSION         RSDK_AR_MAJOR
    #define CTE_CFG_AR_RELEASE_MINOR_VERSION         RSDK_AR_MINOR
    #define CTE_CFG_AR_RELEASE_REVISION_VERSION      RSDK_AR_REV
    #define CTE_CFG_SW_MAJOR_VERSION                 RSDK_SW_MAJOR
    #define CTE_CFG_SW_MINOR_VERSION                 RSDK_SW_MINOR
    #define CTE_CFG_SW_PATCH_VERSION                 RSDK_SW_PATCH


/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
        /* Check if header file and StandardTypes header file are of the same AutoSar version */
        #if ((CTE_CFG_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
             (CTE_CFG_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)    \
            )
            #error "AutoSar Version Numbers of CTE_Cfg.h and StandardTypes.h are different"
        #endif
    #endif

    /* Check if Cte header file and Cte_Types configuration header file are of the same Autosar version       */
    #if ((CTE_CFG_AR_RELEASE_MAJOR_VERSION    != CTE_PCCFG_AR_RELEASE_MAJOR_VERSION) ||   \
         (CTE_CFG_AR_RELEASE_MINOR_VERSION    != CTE_PCCFG_AR_RELEASE_MINOR_VERSION) ||   \
         (CTE_CFG_AR_RELEASE_REVISION_VERSION != CTE_PCCFG_AR_RELEASE_REVISION_VERSION)   \
        )
        #error "AutoSar Version Numbers of Cte_cfg.h and Cte_PCCfg.h are different"
    #endif

    /* Check if Cte header file and Cte_Types configuration header file are of the same software version      */
    #if ((CTE_CFG_SW_MAJOR_VERSION    != CTE_PCCFG_SW_MAJOR_VERSION) ||   \
         (CTE_CFG_SW_MINOR_VERSION    != CTE_PCCFG_SW_MINOR_VERSION) ||   \
         (CTE_CFG_SW_PATCH_VERSION    != CTE_PCCFG_SW_PATCH_VERSION)      \
        )
        #error "Software Version Numbers of CDD_CDD_Cte.h and Cte_Types.h are different"
    #endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/




/* Pre-processor switch to enable/disable development error detection for Cte API */
    #ifndef CTE_DEV_ERROR_DETECT
        #define CTE_DEV_ERROR_DETECT                   STD_ON
    #endif
/* Pre-processor switch to enable/disable stop execution after error detection for Cte API */
    #ifndef CTE_DEV_HALT_ON_ERROR
        #define CTE_DEV_HALT_ON_ERROR                   STD_OFF
    #endif


/* Pre-processor switch to define single Cte management thread or multiple Cte management threads.
 * If single thread (which is the normal approach) - there are no necessary exclusive areas for the driver    */
#ifndef CTE_SINGLE_MANAGEMENT_THREADS
#define CTE_SINGLE_MANAGEMENT_THREADS          STD_ON
#endif

/* Pre-processor switch to enable/disable version info report for Cte API                      */
#ifndef CTE_VERSION_INFO_API
#define CTE_VERSION_INFO_API                   STD_ON
#endif

/* Pre-processor switch to enable/disable Rx start/stop usage in CTE API                       */
#ifndef CTE_START_STOP_USAGE
#define CTE_START_STOP_USAGE                STD_ON
#endif



/* Formal instance id for CTE driver, to be used at development time                           */
#define CTE_INSTANCE_ID                        0u





/* Formal API id for some CTE driver functions groups, to be used at development time          */
#define CTE_VERSION_INFO_CHECK                 0u      /* error at VersionInfo call                        */
#define CTE_SETUP_PARAM_CHECK                  2u      /* error at setup, VC parameters check              */
#define CTE_SETUP_AUX_PARAM_CHECK              3u      /* error at setup, auxiliary data parameters check  */
#define CTE_SETUP_MD_PARAM_CHECK               4u      /* error at setup, metadata parameters check        */
#define CTE_SETUP_MODULE_INIT                  5u      /* error at setup, during real setup                */
#define CTE_RX_STOP                            6u      /* error when calling RxStop                        */
#define CTE_RX_START                           7u      /* error when calling RxStart                       */
#define CTE_POWER_OFF                          8u      /* error when calling PowerOff                      */
#define CTE_POWER_ON                           9u      /* error when calling PowerOn                       */
#define CTE_GET_VALUE                          10u     /* error when calling a get function                */

/* error report management      */

    #define CTE_REPORT_ERROR(a,b,c)    RSDK_REPORT_ERROR(a, (uint16)CTE_MODULE_ID, (uint8)CTE_INSTANCE_ID, (b), (c));





#if (CTE_DEV_HALT_ON_ERROR == STD_ON)
/* Infinite loop if error detected and the option is to detect development errors */
    #define CTE_HALT_ON_ERROR          while(gsCteLoopExit != TRUE)   \
                                        {                               \
                                            ;   /* empty loop */        \
                                        }
#else
    #define CTE_HALT_ON_ERROR
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


#endif /* CTE_CFG_H */
