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

#ifndef DSP_JOBS_H
#define DSP_JOBS_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#ifdef RSDK_AUTOSAR
#include "Std_Types.h"
#include "rsdk_version.h"
#else
#include "typedefs.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef RSDK_AUTOSAR
/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DSP_JOBS_VENDOR_ID                     43

#define DSP_JOBS_AR_RELEASE_MAJOR_VERSION      RSDK_AR_MAJOR
#define DSP_JOBS_AR_RELEASE_MINOR_VERSION      RSDK_AR_MINOR
#define DSP_JOBS_AR_RELEASE_REVISION_VERSION   RSDK_AR_REV

#define DSP_JOBS_SW_MAJOR_VERSION              RSDK_SW_MAJOR
#define DSP_JOBS_SW_MINOR_VERSION              RSDK_SW_MINOR
#define DSP_JOBS_SW_PATCH_VERSION              RSDK_SW_PATCH

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Verify vendor ID and version numbers for included header file: Std_Types.h */
#if (DSP_JOBS_VENDOR_ID != STD_VENDOR_ID)
    #error "dsp_jobs.h and Std_Types.h have different vendor IDs"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((DSP_JOBS_AR_RELEASE_MAJOR_VERSION    != STD_AR_RELEASE_MAJOR_VERSION) || \
         (DSP_JOBS_AR_RELEASE_MINOR_VERSION    != STD_AR_RELEASE_MINOR_VERSION) || \
         (DSP_JOBS_AR_RELEASE_REVISION_VERSION != STD_AR_RELEASE_REVISION_VERSION) \
        )
        #error "AutoSar Version Numbers of dsp_jobs.h and Std_Types.h are different"
    #endif
#endif



#endif /* RSDK_AUTOSAR */
/*==================================================================================================
*                                      MACROS
==================================================================================================*/
#define SIZEOF_JOB_DESCRIPTOR 16U /* bytes */
#define RSDK_DSPHD_MAX_JOB_LIST_SIZE  10U	/**< Max number of jobs allowed in a DSP job list*/

#define DSP_CMD_FORMAT_PAM_BIT 0x2U		/**< Parameter Addressing Mode bit described in the DSP Calling Convention */
#define DSP_CMD_FORMAT_CRCEN_BIT 0x1U	/**< CRC Enable bit described in the DSP Calling Convention*/
#define DSP_CMD_FORMAT_CRCDIS_BIT 0x0U  /**< CRC Disable bit described in the DSP Calling Convention*/
#define DSP_CMD_FORMAT_PAM_DIRECT 0U

#define DSP_MSG_STRUCT_PAYLOAD_OFFSET 4
#define DSP_MSG_STRUCT_CRC_OFFSET 8

#define DSP_SIZEOF_RUNTIME_CFG_MSG 20
#define DSP_RUNTIME_CFG_STRUCT_P1_TASK_CONFIG_OFFSET 4
#define DSP_RUNTIME_CFG_STRUCT_FPU_ROUND_CONFIG_OFFSET 8
#define DSP_RUNTIME_CFG_STRUCT_DISP_STATE_CONFIG_OFFSET 12
#define DSP_RUNTIME_CFG_STRUCT_REPORT_FPU_EXC_OFFSET 16
#define DSP_RUNTIME_CFG_STRUCT_CRC_OFFSET 17

/*==================================================================================================
*                          TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
#ifdef RSDK_AUTOSAR
#define DSPHD_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dsphd_MemMap.h"
#endif

typedef struct {
	/* this structure mirrors the "DSP Calling Convention" described in the RSDK User Manual */
	uint8_t crc;
	uint8_t funcId;
	uint8_t paramList[12];
	uint8_t cmdFormat;
	uint8_t unused;		/*to keep struct length at 16 bytes.*/
} JobDescriptor_t;

typedef struct {
	uint16_t numJobs;
	JobDescriptor_t jobDescriptor[RSDK_DSPHD_MAX_JOB_LIST_SIZE];
} JobList_t;

#ifdef RSDK_AUTOSAR
#define DSPHD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dsphd_MemMap.h"
#endif

#ifdef __cplusplus
}
#endif

#endif  /*DSP_JOBS_H*/
