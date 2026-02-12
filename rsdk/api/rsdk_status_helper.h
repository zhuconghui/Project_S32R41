/*
* Copyright 2019-2022 NXP
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef RSDK_STATUS_HELPER_H
#define RSDK_STATUS_HELPER_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#ifdef RSDK_AUTOSAR
#include "Det.h"
#include "rsdk_version.h"
#endif

#include "rsdk_toolchain_helper.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef RSDK_AUTOSAR
/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RSDK_STATUS_HELPER_VENDOR_ID                     43

#define RSDK_STATUS_HELPER_AR_RELEASE_MAJOR_VERSION      RSDK_AR_MAJOR
#define RSDK_STATUS_HELPER_AR_RELEASE_MINOR_VERSION      RSDK_AR_MINOR
#define RSDK_STATUS_HELPER_AR_RELEASE_REVISION_VERSION   RSDK_AR_REV

#define RSDK_STATUS_HELPER_SW_MAJOR_VERSION              RSDK_SW_MAJOR
#define RSDK_STATUS_HELPER_SW_MINOR_VERSION              RSDK_SW_MINOR
#define RSDK_STATUS_HELPER_SW_PATCH_VERSION              RSDK_SW_PATCH

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Verify vendor ID and version numbers for included header file: rsdk_toolchain_helper.h */
#if (RSDK_STATUS_HELPER_VENDOR_ID != RSDK_TOOLCHAIN_HELPER_VENDOR_ID)
    #error "rsdk_status_helper.h and rsdk_toolchain_helper.h have different vendor IDs"
#endif

#if ((RSDK_STATUS_HELPER_AR_RELEASE_MAJOR_VERSION    != RSDK_TOOLCHAIN_HELPER_AR_RELEASE_MAJOR_VERSION) || \
     (RSDK_STATUS_HELPER_AR_RELEASE_MINOR_VERSION    != RSDK_TOOLCHAIN_HELPER_AR_RELEASE_MINOR_VERSION) || \
     (RSDK_STATUS_HELPER_AR_RELEASE_REVISION_VERSION != RSDK_TOOLCHAIN_HELPER_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of rsdk_status_helper.h and rsdk_toolchain_helper.h are different"
#endif

#if ((RSDK_STATUS_HELPER_SW_MAJOR_VERSION != RSDK_TOOLCHAIN_HELPER_SW_MAJOR_VERSION) || \
     (RSDK_STATUS_HELPER_SW_MINOR_VERSION != RSDK_TOOLCHAIN_HELPER_SW_MINOR_VERSION) || \
     (RSDK_STATUS_HELPER_SW_PATCH_VERSION != RSDK_TOOLCHAIN_HELPER_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of rsdk_status_helper.h and rsdk_toolchain_helper.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if current file and Det header file are of the same AutoSar version */
#if ((RSDK_STATUS_HELPER_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION) || \
     (RSDK_STATUS_HELPER_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of rsdk_status_helper.h and Det.h are different"
#endif
#endif

#endif /* RSDK_AUTOSAR */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#ifdef RSDK_AUTOSAR

#define RSDK_MODULE_ERRCODE_MASK    0xFFUL

#define RSDK_REPORT_ERROR(rsdkErrCode, moduleId, instanceId, apiId, errCode)    RsdkReportError(rsdkErrCode, moduleId, instanceId, apiId, errCode)

#else

#define E_OK        RSDK_SUCCESS
#define E_NOT_OK    RSDK_ERROR

#define RSDK_REPORT_ERROR(rsdkErrCode, moduleId, instanceId, apiId, errCode)    rsdkErrCode

#endif /* RSDK_AUTOSAR */

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#ifndef RSDK_AUTOSAR
typedef rsdkStatus_t Std_ReturnType;
#endif

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef RSDK_AUTOSAR
static __inline Std_ReturnType RsdkReportError(rsdkStatus_t rsdkErrCode, uint16 moduleId, uint8 instanceId, uint8 apiId, uint8 errCode)
{
    RSDK_COMPILER_ASSERT(((uint32_t)rsdkErrCode & RSDK_MODULE_ERRCODE_MASK) == (uint32_t)errCode);

#ifndef BYPASS_DET_ERROR_REPORTING //used for building the RSDK CDDs without having RTD Det support
	(void)Det_ReportError((uint16)moduleId, (uint8)instanceId, (uint8)apiId, (uint8)errCode);
#endif

	return (Std_ReturnType)E_NOT_OK;
}
#endif

#ifdef __cplusplus
}
#endif

#endif /* RSDK_STATUS_HELPER_H */
