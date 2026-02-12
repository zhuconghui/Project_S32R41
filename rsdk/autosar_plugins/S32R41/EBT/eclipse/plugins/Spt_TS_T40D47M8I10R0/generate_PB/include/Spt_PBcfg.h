[!CODE!][!//
/*
 * Copyright 2021-2024 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
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
#include "CDD_Spt.h"

[!NOCODE!][!//
[!INCLUDE "Spt_RegOperations.m"!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPT_PBCFG_VENDOR_ID                          43
#define SPT_PBCFG_AR_RELEASE_MAJOR_VERSION           RSDK_AR_MAJOR
#define SPT_PBCFG_AR_RELEASE_MINOR_VERSION           RSDK_AR_MINOR
#define SPT_PBCFG_AR_RELEASE_REVISION_VERSION        RSDK_AR_REV
#define SPT_PBCFG_SW_MAJOR_VERSION                   RSDK_SW_MAJOR
#define SPT_PBCFG_SW_MINOR_VERSION                   RSDK_SW_MINOR
#define SPT_PBCFG_SW_PATCH_VERSION                   RSDK_SW_PATCH

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if Spt_PBcfg source file and CDD_Spt.h header file are of the same vendor */
#if (SPT_PBCFG_VENDOR_ID != CDD_SPT_VENDOR_ID)
    #error "Spt_PBcfg.c and CDD_Spt.h have different vendor ids"
#endif

/* Check if Spt_PBcfg source file and CDD_Spt.h header file are of the same Autosar version */
#if ((SPT_PBCFG_AR_RELEASE_MAJOR_VERSION    != CDD_SPT_AR_RELEASE_MAJOR_VERSION) || \
     (SPT_PBCFG_AR_RELEASE_MINOR_VERSION    != CDD_SPT_AR_RELEASE_MINOR_VERSION) || \
     (SPT_PBCFG_AR_RELEASE_REVISION_VERSION != CDD_SPT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Spt_PBcfg.c and CDD_Spt.h are different"
#endif

/* Check if Spt_PBcfg source file and CDD_Spt.h header file are of the same Software version */
#if ((SPT_PBCFG_SW_MAJOR_VERSION != CDD_SPT_SW_MAJOR_VERSION) || \
     (SPT_PBCFG_SW_MINOR_VERSION != CDD_SPT_SW_MINOR_VERSION) || \
     (SPT_PBCFG_SW_PATCH_VERSION != CDD_SPT_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Spt_PBcfg.c and CDD_Spt.h are different"
#endif

/*==================================================================================================
*                                   GLOBAL FUNCTION PROTOTYPES
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
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
[!CALL "SptConfigSetupMacroVar"!][!//

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
[!ENDCODE!]
