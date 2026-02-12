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
[!
/*  Variable defintions to be used for the code generation  */
var SptGeneral = (this[0]).getChildById("SptGeneralConfiguration");
!]

/* Pre-processor switch to enable/disable development error detection for Spt API */
#ifndef SPT_DEV_ERROR_DETECT
[!<code>#define SPT_DEV_ERROR_DETECT                $(SptGeneral.getChildById("SptDevErrorDetect").getValue()) ? "STD_ON":"STD_OFF"$</code>!]

#endif

/* Pre-processor switch to enable/disable haling on error for development errors for Spt API */
#ifndef SPT_DEV_HALT_ON_ERROR
[!<code>#define SPT_DEV_HALT_ON_ERROR               $(SptGeneral.getChildById("SptHaltOnError").getValue()) ? "STD_ON":"STD_OFF"$</code>!]

#endif

/* Pre-processor switch to enable/disable support for exclusive areas in the SPT driver
 * If all SPT driver calls are made from the same thread, there is no need for exclusive ares.    */
#ifndef SPT_SINGLE_THREAD
[!<code>#define SPT_SINGLE_THREAD                   $(SptGeneral.getChildById("SptSingleThread").getValue()) ? "STD_ON":"STD_OFF"$</code>!]

#endif

/* Pre-processor switch to enable/disable version info report for Spt API                         */
#ifndef SPT_VERSION_INFO_API
[!<code>#define SPT_VERSION_INFO_API                $(SptGeneral.getChildById("SptVersionInfoApi").getValue()) ? "STD_ON":"STD_OFF"$</code>!]

#endif

/* Pre-processor switch to enable/disable DSP support from the SPT driver                         */
#ifndef SPT_DSP_ENABLE
[!<code>#define SPT_DSP_ENABLE                      $(SptGeneral.getChildById("SptDspEnable").getValue()) ? "STD_ON":"STD_OFF"$</code>!]

#endif

/* Pre-processor switch to enable/disable polling support from the SPT driver                     */
#ifndef SPT_RUN_POLL
[!<code>#define SPT_RUN_POLL                        $(SptGeneral.getChildById("SptRunPoll").getValue()) ? "STD_ON":"STD_OFF"$</code>!]

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
