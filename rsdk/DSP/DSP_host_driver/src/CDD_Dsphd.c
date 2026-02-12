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

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include <string.h>
#include "CDD_Dsphd.h"
#include "dsp_jobs.h"
#include "crc8.h"
#include "Dsphd_cmd_client.h"
#include "Dsphd_Cfg.h"
#include "rsdk_toolchain_helper.h"
#include "ipc-shm.h"
#include "CDD_Dsphd_Cbk.h"
#include "rsdk_version.h"




#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_DSPHD_C_VENDOR_ID                     43

#define CDD_DSPHD_C_AR_RELEASE_MAJOR_VERSION      RSDK_AR_MAJOR
#define CDD_DSPHD_C_AR_RELEASE_MINOR_VERSION      RSDK_AR_MINOR
#define CDD_DSPHD_C_AR_RELEASE_REVISION_VERSION   RSDK_AR_REV

#define CDD_DSPHD_C_SW_MAJOR_VERSION              RSDK_SW_MAJOR
#define CDD_DSPHD_C_SW_MINOR_VERSION              RSDK_SW_MINOR
#define CDD_DSPHD_C_SW_PATCH_VERSION              RSDK_SW_PATCH

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Verify vendor ID and version numbers for included header file: CDD_Dsphd.h */
#if (CDD_DSPHD_C_VENDOR_ID != CDD_DSPHD_VENDOR_ID)
    #error "CDD_Dsphd.c and CDD_Dsphd.h have different vendor ids"
#endif

#if ((CDD_DSPHD_C_AR_RELEASE_MAJOR_VERSION    != CDD_DSPHD_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_DSPHD_C_AR_RELEASE_MINOR_VERSION    != CDD_DSPHD_AR_RELEASE_MINOR_VERSION) || \
     (CDD_DSPHD_C_AR_RELEASE_REVISION_VERSION != CDD_DSPHD_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Dsphd.c and CDD_Dsphd.h are different"
#endif

#if ((CDD_DSPHD_C_SW_MAJOR_VERSION != CDD_DSPHD_SW_MAJOR_VERSION) || \
     (CDD_DSPHD_C_SW_MINOR_VERSION != CDD_DSPHD_SW_MINOR_VERSION) || \
     (CDD_DSPHD_C_SW_PATCH_VERSION != CDD_DSPHD_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of CDD_Dsphd.c and CDD_Dsphd.h are different"
#endif

/* Verify vendor ID and version numbers for included header file: Dsphd_cmd_client.h */
#if (CDD_DSPHD_C_VENDOR_ID != DSPHD_CMD_CLIENT_VENDOR_ID)
    #error "CDD_Dsphd.c and Dsphd_cmd_client.h have different vendor ids"
#endif

#if ((CDD_DSPHD_C_AR_RELEASE_MAJOR_VERSION    != DSPHD_CMD_CLIENT_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_DSPHD_C_AR_RELEASE_MINOR_VERSION    != DSPHD_CMD_CLIENT_AR_RELEASE_MINOR_VERSION) || \
     (CDD_DSPHD_C_AR_RELEASE_REVISION_VERSION != DSPHD_CMD_CLIENT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Dsphd.c and Dsphd_cmd_client.h are different"
#endif

#if ((CDD_DSPHD_C_SW_MAJOR_VERSION != DSPHD_CMD_CLIENT_SW_MAJOR_VERSION) || \
     (CDD_DSPHD_C_SW_MINOR_VERSION != DSPHD_CMD_CLIENT_SW_MINOR_VERSION) || \
     (CDD_DSPHD_C_SW_PATCH_VERSION != DSPHD_CMD_CLIENT_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of CDD_Dsphd.c and Dsphd_cmd_client.h are different"
#endif

/* Verify vendor ID and version numbers for included header file: dsp_jobs.h */
#if (CDD_DSPHD_C_VENDOR_ID != DSP_JOBS_VENDOR_ID)
    #error "CDD_Dsphd.c and dsp_jobs.h have different vendor ids"
#endif

#if ((CDD_DSPHD_C_AR_RELEASE_MAJOR_VERSION    != DSP_JOBS_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_DSPHD_C_AR_RELEASE_MINOR_VERSION    != DSP_JOBS_AR_RELEASE_MINOR_VERSION) || \
     (CDD_DSPHD_C_AR_RELEASE_REVISION_VERSION != DSP_JOBS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Dsphd.c and dsp_jobs.h are different"
#endif

#if ((CDD_DSPHD_C_SW_MAJOR_VERSION != DSP_JOBS_SW_MAJOR_VERSION) || \
     (CDD_DSPHD_C_SW_MINOR_VERSION != DSP_JOBS_SW_MINOR_VERSION) || \
     (CDD_DSPHD_C_SW_PATCH_VERSION != DSP_JOBS_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of CDD_Dsphd.c and dsp_jobs.h are different"
#endif

/* Verify vendor ID and version numbers for included header file: crc8.h */
#if (CDD_DSPHD_C_VENDOR_ID != CRC8_VENDOR_ID)
    #error "CDD_Dsphd.c and crc8.h have different vendor ids"
#endif

#if ((CDD_DSPHD_C_AR_RELEASE_MAJOR_VERSION    != CRC8_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_DSPHD_C_AR_RELEASE_MINOR_VERSION    != CRC8_AR_RELEASE_MINOR_VERSION) || \
     (CDD_DSPHD_C_AR_RELEASE_REVISION_VERSION != CRC8_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Dsphd.c and crc8.h are different"
#endif

#if ((CDD_DSPHD_C_SW_MAJOR_VERSION != CRC8_SW_MAJOR_VERSION) || \
     (CDD_DSPHD_C_SW_MINOR_VERSION != CRC8_SW_MINOR_VERSION) || \
     (CDD_DSPHD_C_SW_PATCH_VERSION != CRC8_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of CDD_Dsphd.c and crc8.h are different"
#endif

/* Verify vendor ID and version numbers for included header file: Dsphd_Cfg.h */
#if (CDD_DSPHD_C_VENDOR_ID != DSPHD_CFG_VENDOR_ID)
    #error "CDD_Dsphd.c and Dsphd_Cfg.h have different vendor ids"
#endif

#if ((CDD_DSPHD_C_AR_RELEASE_MAJOR_VERSION    != DSPHD_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_DSPHD_C_AR_RELEASE_MINOR_VERSION    != DSPHD_CFG_AR_RELEASE_MINOR_VERSION) || \
     (CDD_DSPHD_C_AR_RELEASE_REVISION_VERSION != DSPHD_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Dsphd.c and Dsphd_Cfg.h are different"
#endif

#if ((CDD_DSPHD_C_SW_MAJOR_VERSION != DSPHD_CFG_SW_MAJOR_VERSION) || \
     (CDD_DSPHD_C_SW_MINOR_VERSION != DSPHD_CFG_SW_MINOR_VERSION) || \
     (CDD_DSPHD_C_SW_PATCH_VERSION != DSPHD_CFG_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of CDD_Dsphd.c and Dsphd_Cfg.h are different"
#endif


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

#define DSPHD_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dsphd_MemMap.h"


static volatile Dsphd_AckStatusType bbe32AckStatus;
static uint32_t numberOfCommandsSent = 0;
static Dsphd_MsgTypeType lastMsgSent;





#define DSPHD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED



#include "Dsphd_MemMap.h"

/*==================================================================================================
*                                       FUNCTIONS
==================================================================================================*/

#define DSPHD_START_SEC_CODE
#include "Dsphd_MemMap.h"


static void WaitBbe32Ack(void)
{
    volatile uint32 ackTimeout;
    //wait ACK from BBE32 on each command
    ackTimeout = 10000u;
    while(ackTimeout > 0u)
    {
        if (bbe32AckStatus == DSPHD_ACK_RECEIVED)
        {
            break;
        }
        else if (bbe32AckStatus == DSPHD_ACK_OUT_OF_ORDER)
        {
            break;
        } else {
            ; // do nothing
        }
        ackTimeout--;
    }
    if(ackTimeout == 0u)
    {
        bbe32AckStatus = DSPHD_ACK_TIMEOUT;
    }
}

static Std_ReturnType CheckBbe32AckStatus(void)
{
    Std_ReturnType status = (Std_ReturnType)E_OK;

    WaitBbe32Ack();

    switch (bbe32AckStatus)
    {
    case DSPHD_ACK_OUT_OF_ORDER:
        status = DSPHD_REPORT_ERROR(RSDK_DSPHD_RET_ERR_ACK_OUT_OF_ORDER, DSPHD_SEND_MESSAGE, DSPHD_E_ACK_OUT_OF_ORDER);
        break;
    case DSPHD_ACK_TIMEOUT:
        status = DSPHD_REPORT_ERROR(RSDK_DSPHD_RET_ERR_ACK_TIMEOUT, DSPHD_SEND_MESSAGE, DSPHD_E_ACK_TIMEOUT);
        break;
    default:
        ; // do nothing
        break;
    }

    return status;
}

void Bbe32EvtIsr(void *argPtr, const uint8 instance, uint8 chan_id, void *bufPtr, uint32 size)

{
    UNUSED_ARG(argPtr);
    UNUSED_ARG(instance);
    UNUSED_ARG(chan_id);
    if (chan_id == CTRL_CHAN_ID)
    {
        if ( (((Dsphd_CommandAckType *)bufPtr)->commandNumber == numberOfCommandsSent) &&
            (((Dsphd_CommandAckType *)bufPtr)->commandType == lastMsgSent))
        {
            bbe32AckStatus = DSPHD_ACK_RECEIVED;
        }
        else
        {
            bbe32AckStatus = DSPHD_ACK_OUT_OF_ORDER;
        }
    }
    else if (chan_id == ASYNC_CHAN_ID)
    {
        if(*(uint32_t *)bufPtr == (uint32_t)DSPHD_SIG_ASYNC_DONE)
        {
            Dsphd_EventCb(DSPHD_SIG_ASYNC_DONE);
        }
        //clear buffer since we have no msg ID check
        (void)memset(bufPtr, 0x0, size);
    }
    else
    {
        DSPHD_HALT_ON_ERROR;
    }

    int err = ipc_shm_release_buf(instance, chan_id, bufPtr);
    if (err != 0)
    {
        DSPHD_HALT_ON_ERROR;
    }


}

static void DspHDAddJobToList(Dsphd_JobType* jobPtr, JobDescriptor_t* jobDescPtr, uint8_t isCrcEnabled)
{

    RSDK_COMPILER_ASSERT(sizeof(JobDescriptor_t) == SIZEOF_JOB_DESCRIPTOR);

    /* PAM=0 (direct parameter passing), CRC enabled */
    if (isCrcEnabled == 1u)
    {
        jobDescPtr->cmdFormat = DSP_CMD_FORMAT_CRCEN_BIT;
    }
    else
    {
        jobDescPtr->cmdFormat = DSP_CMD_FORMAT_CRCDIS_BIT;
    }
    jobDescPtr->funcId = jobPtr->id;
    (void)memcpy((uint8*)jobDescPtr->paramList, (uint8*)(&jobPtr->arg), sizeof(jobPtr->arg));

    /*compute 8-bit CRC on the DSP job "id" and "arg" fields, assuming they are contiguous in memory. */
    jobDescPtr->crc = GenCrc8(&jobDescPtr->funcId, (uint8)(sizeof(jobDescPtr->funcId)+sizeof(jobDescPtr->paramList)));
}

static char* GetShmBuffer(uint8 instance, uint8 channel, size_t size)
{
    char* bufPtr = NULL_PTR;
    uint32_t timeout = 10000;
    while(timeout > 0u)
    {
        bufPtr = (char *)ipc_shm_acquire_buf(instance, channel, size);
        if (bufPtr != NULL_PTR)
        {
            break;
        }

        timeout--;
    }

    return bufPtr;
}
















































Std_ReturnType Dsphd_CreateJobList(Dsphd_JobType* jobPtr, uint8* jobPtrListBuffer, uint16 numJobs, uint8_t isCrcEnabled)
{
    Std_ReturnType status = (Std_ReturnType)E_OK;
    JobList_t* jobPtrList = (JobList_t*)jobPtrListBuffer;

    RSDK_COMPILER_ASSERT(sizeof(JobList_t) == DSPHD_SIZEOF_JOB_LIST);

#if ((defined(RSDK_AUTOSAR) && (DSPHD_DEV_ERROR_DETECT == STD_ON)) || !defined(RSDK_AUTOSAR))
    if((jobPtr == NULL) || (jobPtrListBuffer == NULL))
    {
        status = (Std_ReturnType)DSPHD_REPORT_ERROR(RSDK_DSPHD_RET_ERR_INVALID_PARAMETER, DSPHD_CREATE_JOB_LIST, DSPHD_E_INVALID_PARAMETER);
    }

    if(status == (Std_ReturnType)E_OK)
    {
        if ((numJobs > RSDK_DSPHD_MAX_JOB_LIST_SIZE ) || (numJobs == 0u ))
        {
            status = (Std_ReturnType)DSPHD_REPORT_ERROR(RSDK_DSPHD_RET_ERR_INVALID_PARAMETER, DSPHD_CREATE_JOB_LIST, DSPHD_E_INVALID_PARAMETER);
        }
    }
#endif

    if(status == (Std_ReturnType)E_OK)
    {
        for (uint16 i = 0; i < numJobs; i++)
        {
            DspHDAddJobToList(&jobPtr[i], &jobPtrList->jobDescriptor[i], isCrcEnabled);
        }
        jobPtrList->numJobs = numJobs;
    }

    return status;
}

Std_ReturnType Dsphd_SendMsg(Dsphd_MsgTypeType msgType, uint32 msgPayload)
{
    Std_ReturnType status = (Std_ReturnType)E_OK;
    sint32 retVal;
    rsdkDspHDMsg_t DspHDMsg;

#if ((defined(RSDK_AUTOSAR) && (DSPHD_DEV_ERROR_DETECT == STD_ON)) || !defined(RSDK_AUTOSAR))
    if((msgType >= DSPHD_MSG_LAST) || (msgType < DSPHD_MSG_RUN_ASYNC_JOB))
    {
        status = (Std_ReturnType)DSPHD_REPORT_ERROR(RSDK_DSPHD_RET_ERR_INVALID_PARAMETER, DSPHD_SEND_MESSAGE, DSPHD_E_INVALID_PARAMETER);
    }
#endif

    if(status == (Std_ReturnType)E_OK)
    {

        RSDK_COMPILER_ASSERT(sizeof(Dsphd_RuntimeCfgType) == DSP_SIZEOF_RUNTIME_CFG_MSG);
        RSDK_COMPILER_ASSERT(offsetof(Dsphd_RuntimeCfgType, p1TaskConfig)  == DSP_RUNTIME_CFG_STRUCT_P1_TASK_CONFIG_OFFSET);
        RSDK_COMPILER_ASSERT(offsetof(Dsphd_RuntimeCfgType, fpuRoundConfig)  == DSP_RUNTIME_CFG_STRUCT_FPU_ROUND_CONFIG_OFFSET);
        RSDK_COMPILER_ASSERT(offsetof(Dsphd_RuntimeCfgType, pDispatcherState) == DSP_RUNTIME_CFG_STRUCT_DISP_STATE_CONFIG_OFFSET);
        RSDK_COMPILER_ASSERT(offsetof(Dsphd_RuntimeCfgType, reportFPUExceptions)  == DSP_RUNTIME_CFG_STRUCT_REPORT_FPU_EXC_OFFSET);
        RSDK_COMPILER_ASSERT(offsetof(Dsphd_RuntimeCfgType, crc)  == DSP_RUNTIME_CFG_STRUCT_CRC_OFFSET);

        // compute CRC for DSPHD_MSG_UPDATE_DISPATCHER_CONFIG
        if (msgType == DSPHD_MSG_UPDATE_DISPATCHER_CONFIG)
        {
            Dsphd_RuntimeCfgType* cfgPaylodPtr = (Dsphd_RuntimeCfgType*)((uintptr_t)msgPayload);
            cfgPaylodPtr->crc = GenCrc8((uint8*)(&cfgPaylodPtr->numberOfChirps), (uint8)(offsetof(Dsphd_RuntimeCfgType, crc)));
        }
        /*buffer size can be verified at compile time...*/
        RSDK_COMPILER_ASSERT(sizeof(rsdkDspHDMsg_t) == DSPHD_SIZEOF_MSG);
        RSDK_COMPILER_ASSERT(offsetof(rsdkDspHDMsg_t, payload)  == DSP_MSG_STRUCT_PAYLOAD_OFFSET);
        RSDK_COMPILER_ASSERT(offsetof(rsdkDspHDMsg_t, crc)  == DSP_MSG_STRUCT_CRC_OFFSET);
        lastMsgSent = msgType;
        DspHDMsg.type = msgType;
        DspHDMsg.payload = (uint32)msgPayload;
        DspHDMsg.crc = GenCrc8((uint8*)(&DspHDMsg.type), (uint8)(offsetof(rsdkDspHDMsg_t, crc)));

        char* txBufPtr = GetShmBuffer(IPCF_INSTANCE, CTRL_CHAN_ID, sizeof(DspHDMsg));

        if (txBufPtr != NULL_PTR)
        {
            (void)memcpy(txBufPtr, (char *)&DspHDMsg, sizeof(DspHDMsg));

            // Avoid race condition if ACK is coming before hitting WaitBbe32Ack();
            bbe32AckStatus = DSPHD_ACK_WAITING;

            retVal = ipc_shm_tx(IPCF_INSTANCE, CTRL_CHAN_ID, txBufPtr, sizeof(DspHDMsg));
            if (retVal != 0)
            {
                status = DSPHD_REPORT_ERROR(RSDK_DSPHD_RET_ERR_TX_FAILED, DSPHD_SEND_MESSAGE, DSPHD_E_TX_FAILED);
            }
            else
            {
                numberOfCommandsSent++;
                status = CheckBbe32AckStatus();
            }
        }
        else
        {
            status = DSPHD_REPORT_ERROR(RSDK_DSPHD_RET_ERR_INVALID_MSG_BUFF, DSPHD_SEND_MESSAGE, DSPHD_E_INVALID_MSG_BUFF);
        }

    }

    return status;
}






























































Std_ReturnType Dsphd_Init(void)
{
    Std_ReturnType status = (Std_ReturnType)E_OK;

    if (ipc_shm_init(&ipcf_shm_instances_cfg) != 0)
    {
        status = DSPHD_REPORT_ERROR(RSDK_DSPHD_RET_ERR_COMM_INIT_FAIL, DSPHD_INIT, DSPHD_E_COMM_INIT_FAIL);
    }

    return status;
}



#if (DSPHD_VERSION_INFO_API == STD_ON)
void Dsphd_GetVersionInfo(Std_VersionInfoType* versionInfoPtr)
{
#if (DSPHD_DEV_ERROR_DETECT == STD_ON)
    if (versionInfoPtr == NULL)
    {
        (void)DSPHD_REPORT_ERROR(RSDK_DSPHD_RET_ERR_INVALID_PARAMETER, DSPHD_GET_VERSION_INFO, DSPHD_E_INVALID_PARAMETER);
    }
    else
#endif
    {
        versionInfoPtr->moduleID           = (uint16)CDD_DSPHD_MODULE_ID;
        versionInfoPtr->vendorID           = (uint16)CDD_DSPHD_VENDOR_ID;
        versionInfoPtr->sw_major_version   = (uint8) CDD_DSPHD_SW_MAJOR_VERSION;
        versionInfoPtr->sw_minor_version   = (uint8) CDD_DSPHD_SW_MINOR_VERSION;
        versionInfoPtr->sw_patch_version   = (uint8) CDD_DSPHD_SW_PATCH_VERSION;
    }
}
#endif //#if (DSPHD_VERSION_INFO_API == STD_ON)



#define DSPHD_STOP_SEC_CODE
#include "Dsphd_MemMap.h"


/*===================================================================================================================*/

#ifdef __cplusplus
}
#endif

/*******************************************************************************
 * EOF
 ******************************************************************************/
