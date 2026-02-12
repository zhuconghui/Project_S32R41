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

[!VAR "Csi2CfgPath"!]/AUTOSAR/TOP-LEVEL-PACKAGES/Csi2/ELEMENTS/Csi2[!ENDVAR!]    [!// the CODE and ENCODE tag
#ifndef CSI2_CBK_H
#define CSI2_CBK_H

/**
*   @file
*   @implements Csi2_PBCbk.h_Artifact
*
*   @addtogroup CSI2_ASR
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*
* @page misra_violations MISRA-C:2012 violations
*
* @section Csi2_Cbk_h_REF_1
* Violates MISRA 2012 Advisory Rule 20.1, #Include directives should only be preceded by preprocessor directives or comments.
* <MA>_MemMap.h is included after each section define in order to set the current memory section as defined by AUTOSAR.
*/

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Csi2_Types.h"
#include "rsdk_version.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CSI2_CBK_VENDOR_ID                          43
#define CSI2_CBK_AR_RELEASE_MAJOR_VERSION           RSDK_AR_MAJOR
#define CSI2_CBK_AR_RELEASE_MINOR_VERSION           RSDK_AR_MINOR
#define CSI2_CBK_AR_RELEASE_REVISION_VERSION        RSDK_AR_REV
#define CSI2_CBK_SW_MAJOR_VERSION                   RSDK_SW_MAJOR
#define CSI2_CBK_SW_MINOR_VERSION                   RSDK_SW_MINOR
#define CSI2_CBK_SW_PATCH_VERSION                   RSDK_SW_PATCH

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check Csi2_Types.h versions                                                                                */
#if (CSI2_CBK_VENDOR_ID != CSI2_TYPES_VENDOR_ID)
    #error "Csi2_Cbk.h and Csi2_Types.h have different vendor ids"
#endif

/* Check if Csi2_Cbk header file and Csi2_Types configuration header file are of the same Autosar version       */
#if ((CSI2_CBK_AR_RELEASE_MAJOR_VERSION    != CSI2_TYPES_AR_RELEASE_MAJOR_VERSION) ||   \
     (CSI2_CBK_AR_RELEASE_MINOR_VERSION    != CSI2_TYPES_AR_RELEASE_MINOR_VERSION) ||   \
     (CSI2_CBK_AR_RELEASE_REVISION_VERSION != CSI2_TYPES_AR_RELEASE_REVISION_VERSION)   \
    )
    #error "AutoSar Version Numbers of Csi2_Cbk.h and Csi2_Types.h are different"
#endif

/* Check if Csi2_Ip header file and Csi2_Types configuration header file are of the same software version      */
#if ((CSI2_CBK_SW_MAJOR_VERSION    != CSI2_TYPES_SW_MAJOR_VERSION) ||     \
     (CSI2_CBK_SW_MINOR_VERSION    != CSI2_TYPES_SW_MINOR_VERSION) ||     \
     (CSI2_CBK_SW_PATCH_VERSION    != CSI2_TYPES_SW_PATCH_VERSION)        \
    )
    #error "Software Version Numbers of Csi2_Cbk.h and Csi2_Types.h are different"
#endif


/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
[!IF "node:value(concat($Csi2CfgPath,'/Csi2General','/Csi2SingleCallbackUsage'))"!][!IF "node:value(concat($Csi2CfgPath,'/Csi2Callbacks','/Csi2SingleCallbackName')) != 'Csi2_SingleIsrCallback'"!]#define Csi2_SingleIsrCallback [!"node:value(concat($Csi2CfgPath,'/Csi2Callbacks','/Csi2SingleCallbackName'))"!][!ENDIF!][!ELSE!][!IF "node:value(concat($Csi2CfgPath,'/Csi2Callbacks','/Csi2PhyErrorCallbackName')) != 'Csi2_PhyIsrCallbackUnit'"!]#define Csi2_PhyIsrCallbackUnit [!"node:value(concat($Csi2CfgPath,'/Csi2Callbacks','/Csi2PhyErrorCallbackName'))"!][!ENDIF!]
[!IF "node:value(concat($Csi2CfgPath,'/Csi2Callbacks','/Csi2PcktErrorCallbackName')) != 'Csi2_PcktIsrCallbackUnit'"!]#define Csi2_PcktIsrCallbackUnit [!"node:value(concat($Csi2CfgPath,'/Csi2Callbacks','/Csi2PcktErrorCallbackName'))"!][!ENDIF!]
[!IF "node:value(concat($Csi2CfgPath,'/Csi2Callbacks','/Csi2EvtErrorCallbackName')) != 'Csi2_EvtIsrCallbackUnit'"!]#define Csi2_EvtIsrCallbackUnit [!"node:value(concat($Csi2CfgPath,'/Csi2Callbacks','/Csi2EvtErrorCallbackName'))"!][!ENDIF!][!ENDIF!]

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
[!IF "node:value(concat($Csi2CfgPath,'/Csi2General','/Csi2SingleCallbackUsage'))"!]extern void Csi2_SingleIsrCallback(Csi2_ErrorReportType *errorReportPtr);[!ELSE!]extern void Csi2_PhyIsrCallbackUnit(Csi2_ErrorReportType *errorReportPtr);
extern void Csi2_PcktIsrCallbackUnit(Csi2_ErrorReportType *errorReportPtr);
extern void Csi2_EvtIsrCallbackUnit(Csi2_ErrorReportType *errorReportPtr);[!ENDIF!]


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CSI2_PBCBK_H */
