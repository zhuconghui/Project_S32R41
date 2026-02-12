/*
 * Copyright 2022-2024 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

#ifndef DSPHD_PCCFG_H
#define DSPHD_PCCFG_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DSPHD_PCCFG_VENDOR_ID                          43

#define DSPHD_PCCFG_AR_RELEASE_MAJOR_VERSION           RSDK_AR_MAJOR
#define DSPHD_PCCFG_AR_RELEASE_MINOR_VERSION           RSDK_AR_MINOR
#define DSPHD_PCCFG_AR_RELEASE_REVISION_VERSION        RSDK_AR_REV

#define DSPHD_PCCFG_SW_MAJOR_VERSION                   RSDK_SW_MAJOR
#define DSPHD_PCCFG_SW_MINOR_VERSION                   RSDK_SW_MINOR
#define DSPHD_PCCFG_SW_PATCH_VERSION                   RSDK_SW_PATCH

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and StandardTypes header file are of the same AutoSar version */
#if ((DSPHD_PCCFG_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
     (DSPHD_PCCFG_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of Dsphd_PCcfg.h and StandardTypes.h are different"
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/* Pre-processor switch to enable/disable error detection during development phase*/
#ifndef DSPHD_DEV_ERROR_DETECT
#define DSPHD_DEV_ERROR_DETECT                    (STD_ON)
#endif

#ifndef DSPHD_DEV_HALT_ON_ERROR
#define DSPHD_DEV_HALT_ON_ERROR                   (STD_OFF)
#endif

/* Pre-processor switch to enable/disable version info report */
#ifndef DSPHD_VERSION_INFO_API
#define DSPHD_VERSION_INFO_API                    (STD_ON)
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

#endif /* DSPHD_PCCFG_H */
