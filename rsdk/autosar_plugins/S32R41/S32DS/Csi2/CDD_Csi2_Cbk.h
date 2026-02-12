/*
 * Copyright 2024 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

#ifndef CDD_CSI2_CBK_H
#define CDD_CSI2_CBK_H

#ifdef __cplusplus
extern "C"{
#endif

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
#if ((CSI2_CBK_AR_RELEASE_MAJOR_VERSION    != CSI2_TYPES_AR_RELEASE_MAJOR_VERSION) ||   \\\
     (CSI2_CBK_AR_RELEASE_MINOR_VERSION    != CSI2_TYPES_AR_RELEASE_MINOR_VERSION) ||   \\\
     (CSI2_CBK_AR_RELEASE_REVISION_VERSION != CSI2_TYPES_AR_RELEASE_REVISION_VERSION)   \\\
    )
    #error "AutoSar Version Numbers of Csi2_Cbk.h and Csi2_Types.h are different"
#endif

/* Check if Csi2_Ip header file and Csi2_Types configuration header file are of the same software version      */
#if ((CSI2_CBK_SW_MAJOR_VERSION    != CSI2_TYPES_SW_MAJOR_VERSION) ||     \\\
     (CSI2_CBK_SW_MINOR_VERSION    != CSI2_TYPES_SW_MINOR_VERSION) ||     \\\
     (CSI2_CBK_SW_PATCH_VERSION    != CSI2_TYPES_SW_PATCH_VERSION)        \\\
    )
    #error "Software Version Numbers of Csi2_Cbk.h and Csi2_Types.h are different"
#endif


/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

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
[!
var configSet   = this[0];
var Csi2General = configSet.getChildById("Csi2GeneralConfiguration");       // root node for general driver setup

    if (Csi2General.getChildById("Csi2SingleCallbackUsage").getValue())
    {       // single callback
<code>extern $Csi2General.getChildById("Csi2CallbackSetup.Csi2SingleCallbackName").getValue()$(Csi2_ErrorReportType *errorPtr);</code>
    }
    else
    {       // different callback for eack interrupt
<code>extern void $Csi2General.getChildById("Csi2CallbackSetup.Csi2PhyErrorCallbackName").getValue()$(Csi2_ErrorReportType *errorPtr);
extern void $Csi2General.getChildById("Csi2CallbackSetup.Csi2PcktErrorCallbackName").getValue()$(Csi2_ErrorReportType *errorPtr);
extern void $Csi2General.getChildById("Csi2CallbackSetup.Csi2EvtErrorCallbackName").getValue()$(Csi2_ErrorReportType *errorPtr);</code>
    }
!]



#ifdef __cplusplus
}
#endif

#endif /* CDD_CSI2_PBCBK_H */
