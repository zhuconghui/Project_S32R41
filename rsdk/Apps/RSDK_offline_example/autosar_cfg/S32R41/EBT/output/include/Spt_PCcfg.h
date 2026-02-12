/*
 * Copyright 2021,2023 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

#ifndef SPT_PCCFG_H
#define SPT_PCCFG_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPT_PCCFG_VENDOR_ID                          43
#define SPT_PCCFG_AR_RELEASE_MAJOR_VERSION           RSDK_AR_MAJOR
#define SPT_PCCFG_AR_RELEASE_MINOR_VERSION           RSDK_AR_MINOR
#define SPT_PCCFG_AR_RELEASE_REVISION_VERSION        RSDK_AR_REV
#define SPT_PCCFG_SW_MAJOR_VERSION                   RSDK_SW_MAJOR
#define SPT_PCCFG_SW_MINOR_VERSION                   RSDK_SW_MINOR
#define SPT_PCCFG_SW_PATCH_VERSION                   RSDK_SW_PATCH

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/* Pre-processor switch to enable/disable development error detection for Spt API */
#ifndef SPT_DEV_ERROR_DETECT
#define SPT_DEV_ERROR_DETECT                    (STD_ON)
#endif

/* Pre-processor switch to enable/disable haling on error for development errors for Spt API */
#ifndef SPT_DEV_HALT_ON_ERROR
#define SPT_DEV_HALT_ON_ERROR                   (STD_OFF)
#endif

/* Pre-processor switch to enable/disable support for exclusive areas in the SPT driver
 * If all SPT driver calls are made from the same thread, there is no need for exclusive ares.    */
#ifndef SPT_SINGLE_THREAD
#define SPT_SINGLE_THREAD                       (STD_ON)
#endif

/* Pre-processor switch to enable/disable version info report for Spt API                         */
#ifndef SPT_VERSION_INFO_API
#define SPT_VERSION_INFO_API                    (STD_ON)
#endif

/* Pre-processor switch to enable/disable DSP support from the SPT driver                         */
#ifndef SPT_DSP_ENABLE
#define SPT_DSP_ENABLE                          (STD_ON)
#endif

/* Pre-processor switch to enable/disable polling support from the SPT driver                     */
#ifndef SPT_RUN_POLL
#define SPT_RUN_POLL                            (STD_ON)
#endif

/*================================================================================================*/

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

#endif /* SPT_PCCFG_H */

