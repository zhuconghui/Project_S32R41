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
#ifndef CTE_CBK_H
#define CTE_CBK_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Cte_Types.h"
#include "StandardTypes.h"
#include "rsdk_version.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CTE_CBK_VENDOR_ID                        43
#define CTE_CBK_AR_RELEASE_MAJOR_VERSION         RSDK_AR_MAJOR
#define CTE_CBK_AR_RELEASE_MINOR_VERSION         RSDK_AR_MINOR
#define CTE_CBK_AR_RELEASE_REVISION_VERSION      RSDK_AR_REV
#define CTE_CBK_SW_MAJOR_VERSION                 RSDK_SW_MAJOR
#define CTE_CBK_SW_MINOR_VERSION                 RSDK_SW_MINOR
#define CTE_CBK_SW_PATCH_VERSION                 RSDK_SW_PATCH

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and StandardTypes header file are of the same AutoSar version */
    #if ((CTE_CBK_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (CTE_CBK_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of CTE_Cbk.h and StandardTypes.h are different"
    #endif
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
[!IF "node:value(concat($CteCfgPath,'/CteGeneral','/CteCallbackName')) != 'Cte_IsrCallback'"!]#define Cte_IsrCallback [!"node:value(concat($CteCfgPath,'/CteGeneral','/CteCallbackName'))"!][!ENDIF!]

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
extern void Cte_IsrCallback(uint32 evtMask);


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CTE_PCCBK_H */




