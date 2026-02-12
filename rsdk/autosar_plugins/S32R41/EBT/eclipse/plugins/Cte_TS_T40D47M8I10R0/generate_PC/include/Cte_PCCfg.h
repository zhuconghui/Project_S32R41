/*==================================================================================================
 * Copyright 2022-2023 NXP Semiconductors
 *
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
==================================================================================================*/
[!VAR "CteCfgPath"!]/AUTOSAR/TOP-LEVEL-PACKAGES/Cte/ELEMENTS/Cte[!ENDVAR!]    [!// the CODE and ENCODE tag
#ifndef CTE_PCCFG_H
#define CTE_PCCFG_H

/**
*   @file
*
*   @internal
*   @addtogroup CTE
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
#include "StandardTypes.h"
#include "rsdk_version.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CTE_PCCFG_VENDOR_ID                        43
#define CTE_PCCFG_AR_RELEASE_MAJOR_VERSION         RSDK_AR_MAJOR
#define CTE_PCCFG_AR_RELEASE_MINOR_VERSION         RSDK_AR_MINOR
#define CTE_PCCFG_AR_RELEASE_REVISION_VERSION      RSDK_AR_REV
#define CTE_PCCFG_SW_MAJOR_VERSION                 RSDK_SW_MAJOR
#define CTE_PCCFG_SW_MINOR_VERSION                 RSDK_SW_MINOR
#define CTE_PCCFG_SW_PATCH_VERSION                 RSDK_SW_PATCH

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and StandardTypes header file are of the same AutoSar version */
    #if ((CTE_PCCFG_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (CTE_PCCFG_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of CTE_Cfg.h and StandardTypes.h are different"
    #endif
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/* Pre-processor switch to enable/disable development error detection for Cte API */
#define CTE_DEV_ERROR_DETECT                [!IF "node:value(concat($CteCfgPath,'/CteGeneral','/CteDevErrorDetect'))"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

/* Pre-processor switch to enable/disable stop execution after error detection for Cte API */
#define CTE_DEV_HALT_ON_ERROR               [!IF "node:value(concat($CteCfgPath,'/CteGeneral','/CteErrorHalt'))"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

/* Pre-processor switch to define single Cte management thread or multiple Cte management threads.
 * If single thread (which is the normal approach) - there are no necessary exclusive areas for the driver    */
#define CTE_SINGLE_MANAGEMENT_THREADS       [!IF "node:value(concat($CteCfgPath,'/CteGeneral','/CteSingleThread'))"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

/* Pre-processor switch to enable/disable version info report for Cte API                      */
#define CTE_VERSION_INFO_API                [!IF "node:value(concat($CteCfgPath,'/CteGeneral','/CteVersionInfo'))"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

/* Pre-processor switch to enable/disable Rx start/stop usage in CTE API                       */
#define CTE_START_STOP_USAGE                [!IF "node:value(concat($CteCfgPath,'/CteGeneral','/CteStartStop'))"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]



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

/** @} */

#endif /* CTE_PCCFG_H */
