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

#ifndef CDD_DSPHD_H
#define CDD_DSPHD_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "rsdk_status.h"
#include "rsdk_status_helper.h"
#include "Dsphd_Types.h"
#if defined(SAF86XX) && !defined(USING_OS_XOS)
#include "SAF86xx.h"
#endif
#ifdef RSDK_AUTOSAR
#include "Dsphd_Cfg.h"
#include "rsdk_version.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef RSDK_AUTOSAR
/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_DSPHD_VENDOR_ID                     43
#define CDD_DSPHD_MODULE_ID                     2549

#define CDD_DSPHD_AR_RELEASE_MAJOR_VERSION      RSDK_AR_MAJOR
#define CDD_DSPHD_AR_RELEASE_MINOR_VERSION      RSDK_AR_MINOR
#define CDD_DSPHD_AR_RELEASE_REVISION_VERSION   RSDK_AR_REV

#define CDD_DSPHD_SW_MAJOR_VERSION              RSDK_SW_MAJOR
#define CDD_DSPHD_SW_MINOR_VERSION              RSDK_SW_MINOR
#define CDD_DSPHD_SW_PATCH_VERSION              RSDK_SW_PATCH

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Verify vendor ID and version numbers for included header file: rsdk_status.h */
#if (CDD_DSPHD_VENDOR_ID != RSDK_STATUS_VENDOR_ID)
    #error "CDD_Dsphd.h and rsdk_status.h have different vendor IDs"
#endif

#if ((CDD_DSPHD_AR_RELEASE_MAJOR_VERSION    != RSDK_STATUS_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_DSPHD_AR_RELEASE_MINOR_VERSION    != RSDK_STATUS_AR_RELEASE_MINOR_VERSION) || \
     (CDD_DSPHD_AR_RELEASE_REVISION_VERSION != RSDK_STATUS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Dsphd.h and rsdk_status.h are different"
#endif

#if ((CDD_DSPHD_SW_MAJOR_VERSION != RSDK_STATUS_SW_MAJOR_VERSION) || \
     (CDD_DSPHD_SW_MINOR_VERSION != RSDK_STATUS_SW_MINOR_VERSION) || \
     (CDD_DSPHD_SW_PATCH_VERSION != RSDK_STATUS_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of CDD_Dsphd.h and rsdk_status.h are different"
#endif

/* Verify vendor ID and version numbers for included header file: Dsphd_Types.h */
#if (CDD_DSPHD_VENDOR_ID != DSPHD_TYPES_VENDOR_ID)
    #error "CDD_Dsphd.h and Dsphd_Types.h have different vendor IDs"
#endif

#if ((CDD_DSPHD_AR_RELEASE_MAJOR_VERSION    != DSPHD_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_DSPHD_AR_RELEASE_MINOR_VERSION    != DSPHD_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (CDD_DSPHD_AR_RELEASE_REVISION_VERSION != DSPHD_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Dsphd.h and Dsphd_Types.h are different"
#endif

#if ((CDD_DSPHD_SW_MAJOR_VERSION != DSPHD_TYPES_SW_MAJOR_VERSION) || \
     (CDD_DSPHD_SW_MINOR_VERSION != DSPHD_TYPES_SW_MINOR_VERSION) || \
     (CDD_DSPHD_SW_PATCH_VERSION != DSPHD_TYPES_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of CDD_Dsphd.h and Dsphd_Types.h are different"
#endif

#endif /* RSDK_AUTOSAR */

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/* Formal instance id for DSP host driver, to be used at development time                              */
#define DSPHD_INSTANCE_ID           0u

#if !defined(DSPHD_REPORT_ERROR)
#define DSPHD_REPORT_ERROR(a, b, c) RSDK_REPORT_ERROR((rsdkStatus_t)a, (uint16)CDD_DSPHD_MODULE_ID,     \
                                    (uint8)DSPHD_INSTANCE_ID, (uint8)b, (uint8)c);                      \
                                    DSPHD_HALT_ON_ERROR;
#endif

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/
/* Formal API id for some DSP host driver functions groups, to be used at development time             */
typedef enum
{
    DSPHD_INIT = 0u,                    /* error reported by Dsphd_Init() */
    DSPHD_CREATE_JOB_LIST,              /* error reported by Dsphd_CreateJobList() */
    DSPHD_SEND_MESSAGE,                 /* error reported by Dsphd_SendMsg() */
    DSPHD_GET_VERSION_INFO             /* error reported by Dsphd_GetVersionInfo()  */
} Dsphd_ApiIdType;

/*================================================================================================*/

/*
* @brief Autosar-compatible development error codes.
*/

/**
* @brief          Return datatype for DSPHD API calls.
* @details        API functions either return a Dsphd_ErrStatusType value or void. These error codes are derived from rsdkStatus_t.
*/
typedef enum
{
    DSPHD_E_INVALID_PARAMETER = RSDK_DSPHD_RET_ERR_INVALID_PARAMETER - RSDK_DSPHD_RET_ERR_INVALID_PARAMETER,   /**< DSP Host Driver error:
                                                                                                Parameter value or combination of values not supported. */
    DSPHD_E_IRQ_REG,            /**< DSP dispatcher has encountered an error in the initialization of IPCF, the irq handler was not registered */
    DSPHD_E_INVALID_MSG_BUFF,   /**< DSP Host Driver error: Message buffer not allocated properly. */
    DSPHD_E_RELEASE_MSG_BUFF,   /**< DSP Host Driver error: Failed to release message buff. */
    DSPHD_E_TX_FAILED,          /**< DSP Host Driver error: Message sent from DSP Host Driver to DSP Dispatcher failed. */
    DSPHD_E_COMM_INIT_FAIL,     /**< DSP Host Driver error: The initialization of Inter-Platform Communication Framework(IPCF) has encountered an error. */
    DSPHD_E_ACK_OUT_OF_ORDER,   /**< DSP Host Driver error: ACK received for another message than the one sent (should not happen). */
    DSPHD_E_ACK_TIMEOUT,        /**< DSP Host Driver error: ACK not received fast enough. */
#ifdef SAF86XX
    DSPHD_E_WARN_BBE32_BOOT     /**< DSP Host Driver warning: could not boot the BBE32, core is already out of reset */
#endif
} Dsphd_ErrStatusType;

/**
* @brief API request called with an invalid parameter (Nullpointer).
* */
#define DSPHD_E_PARAM_POINTER    RSDK_INVALID_PARAMETER

/**
* @brief API request called with invalid parameter (invalid value).
* */
#define DSPHD_E_PARAM_VALUE     RSDK_INVALID_PARAMETER

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef RSDK_AUTOSAR
#define DSPHD_START_SEC_CODE
#include "Dsphd_MemMap.h"
#endif

/** @addtogroup dsp_hd_api_func
* @{
*/
/**
* @brief    Creates a list of jobs formatted for the DSP Dispatcher.
* @details  It reads the job information from a user-defined list,
            copies it to a shared buffer and computes CRC for each entry.
*
* @param[in] jobPtr: List of jobs to be sent to the Dispatcher
* @param[in] jobPtrListBuffer: Pointer to a buffer of size #DSPHD_SIZEOF_JOB_LIST that must be allocated
             by the user in a shared memory area, which is accessible to the BBE32 DSP.
* @param[in] numJob: Number of jobs in the user-defined list
* @param[in] isCrcEnabled: CRC check on/off for the jobs (0/other values but 1 = OFF, 1 = ON)
*
* @return #RSDK_SUCCESS or a specific error code.
*
* @pre   It should be called whenever the user wishes to change the list of periodic jobs running on the DSP.
         Calling this function alone does not change the DSP function schedule, it must be followed by another
         call to Dsphd_SendMsg(), using either the #DSPHD_MSG_UPDATE_RC_JOB_LIST or #DSPHD_MSG_UPDATE_LONG_JOB_LIST message types.
*/
Std_ReturnType Dsphd_CreateJobList(Dsphd_JobType* jobPtr, uint8* jobPtrListBuffer, uint16 numJobs, uint8_t isCrcEnabled);

/**
* @brief    Sends a message to the BBE32 DSP Dispatcher .
* @details  The message follows a simple "type+payload" protocol
*
* @param[in]  msgType: type of message
* @param[in]  msgPayload: 32-bit information field which can contain a scalar or 32-bit pointer usable by the BBE32 DSP
*
* @return     #RSDK_SUCCESS or a specific error code.
*
* @pre       For #DSPHD_MSG_UPDATE_RC_JOB_LIST or #DSPHD_MSG_UPDATE_LONG_JOB_LIST message types, the msgPayload
            must be a pointer to the pJobListBuffer initialized by Dsphd_CreateJobList()
*
*/
Std_ReturnType  Dsphd_SendMsg(Dsphd_MsgTypeType msgType, uint32 msgPayload);

/**
* @brief    Initializes the DSP Host driver .
* @details  Initializes the IPCF communication with the BBE32 DSP Dispatcher.
*           \if SAF86XX_DOCS Configures the DSP error interrupt. Optionally it can boot the BBE32 from the DSP Host Driver. \endif
* @return   #RSDK_SUCCESS or a specific error code.
*
*/
#ifdef SAF86XX
Std_ReturnType  Dsphd_Init(Dsphd_InitType* dsphdInitParams);
#else
Std_ReturnType  Dsphd_Init(void);
#endif

#if defined(SAF86XX)
void DspErrIsr(void);
#endif

#ifdef RSDK_AUTOSAR
#if (DSPHD_VERSION_INFO_API == STD_ON)
/**
 * @brief       Returns the version info for this software module.
 *
 * @param[in]   versionInfoPtr - pointer to a structure to receive the data
 */
void Dsphd_GetVersionInfo(Std_VersionInfoType* versionInfoPtr);
#endif
#endif

/** @}*/

#ifdef RSDK_AUTOSAR
#define DSPHD_STOP_SEC_CODE
#include "Dsphd_MemMap.h"
#endif

#ifdef __cplusplus
}
#endif

#endif  /* CDD_DSPHD_H */
