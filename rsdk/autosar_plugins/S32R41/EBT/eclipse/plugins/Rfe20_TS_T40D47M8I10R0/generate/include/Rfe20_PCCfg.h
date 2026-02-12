/*==================================================================================================
 *
 * Copyright 2022-2023 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 *
==================================================================================================*/
[!VAR "Rfe20CfgPath"!]/AUTOSAR/TOP-LEVEL-PACKAGES/Rfe20/ELEMENTS/Rfe20[!ENDVAR!]    [!// the CODE and ENCODE tag
#ifndef RFE20_PCCFG_H
#define RFE20_PCCFG_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#if defined(RSDK_AUTOSAR)
    #include "StandardTypes.h"
    #include "rsdk_version.h"
#endif

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#if defined(RSDK_AUTOSAR)
    #define RFE20_PCCFG_VENDOR_ID                        43
    #define RFE20_PCCFG_AR_RELEASE_MAJOR_VERSION         RSDK_AR_MAJOR
    #define RFE20_PCCFG_AR_RELEASE_MINOR_VERSION         RSDK_AR_MINOR
    #define RFE20_PCCFG_AR_RELEASE_REVISION_VERSION      RSDK_AR_REV
    #define RFE20_PCCFG_SW_MAJOR_VERSION                 RSDK_SW_MAJOR
    #define RFE20_PCCFG_SW_MINOR_VERSION                 RSDK_SW_MINOR
    #define RFE22_PCCFG_SW_PATCH_VERSION                 RSDK_SW_PATCH
#endif

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#if defined(RSDK_AUTOSAR)
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
        /* Check if header file and StandardTypes header file are of the same AutoSar version */
        #if ((RFE20_PCCFG_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
             (RFE20_PCCFG_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)    \
            )
            #error "AutoSar Version Numbers of RFE20_PCCfg.h and StandardTypes.h are different"
        #endif
    #endif
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/* Pre-processor switch to enable/disable development error detection for RFE API               */
#define CDD_RFE_DEV_ERROR_DETECT            [!IF "node:value(concat($Rfe20CfgPath,'/Rfe20_General','/Rfe20DevErrorDetect'))"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

/* Pre-processor switch to enable/disable stop execution after error detection for RFE API      */
#define CDD_RFE_CFG_HALT_ON_ERROR           [!IF "node:value(concat($Rfe20CfgPath,'/Rfe20_General','/Rfe20StopAfterErrorReport'))"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

/* Pre-processor switch to define single RFE management thread or multiple Csi2 management threads.
 * If single thread (which is the normal approach) - there are no necessary exclusive areas for the driver    */
#define CDD_RFE_SINGLE_MANAGEMENT_THREADS   [!IF "node:value(concat($Rfe20CfgPath,'/Rfe20_General','/Rfe20SingleThreadUsed'))"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

/* Pre-processor switch to enable/disable version info report for Rfe20 API                     */
#define CDD_RFE_VERSION_INFO_API            [!IF "node:value(concat($Rfe20CfgPath,'/Rfe20_General','/Rfe20VersionInfo'))"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

/* Working mode for the Firmware side                                                           */[!IF "node:value(concat($Rfe20CfgPath,'/Rfe20_General','/Rfe20_RfeMode')) = 'CASCADED'"!]
#define                                     RFE_MODE_CASCADED

/* The number of used Front-Ends                                                                */
#define RFE_NUM_USED_FRONT_ENDS             [!"node:value(concat($Rfe20CfgPath,'/Rfe20_General','/Rfe20FeNumber'))"!][!ELSE!]
#define                                     RFE_MODE_STANDALONE[!ENDIF!]

/* The memory location to receive the State reported by the Firmware                            */
#define RFE_CMD_IF_RFE_STATE_ADDRESS        [!"node:value(concat($Rfe20CfgPath,'/Rfe20_General','/Rfe20FeStateAddress'))"!]

/* The memory location to receive the pointer to Memory Shared Address                          */
#define RFE_CMD_IF_BASE_ADDRESS_PTR        [!"node:value(concat($Rfe20CfgPath,'/Rfe20_General','/Rfe20FePointerAddress'))"!]

/* The memory buffer start, to be used for API <-> Firmware data transfer                       */
#define RFE_CMD_CLIENT_BASE_ADDRESS        [!"node:value(concat($Rfe20CfgPath,'/Rfe20_General','/Rfe20DataTransferBuffer'))"!]

/* The memory buffer start, for BIST procedure, used only on Firmware side.
   For more details, please check the detailes provided for "BIST Buffer Address" parameter 
   in the Tresos plugin at configuration time.                                                  */
#define RFE_RFBIST_BUFFERS_ADDRESS         [!"node:value(concat($Rfe20CfgPath,'/Rfe20_General','/Rfe20BistBuffer'))"!]


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

#endif /* RFE20_PCCFG_H */
