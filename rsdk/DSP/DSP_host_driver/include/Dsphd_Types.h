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

#ifndef DSPHD_TYPES_H
#define DSPHD_TYPES_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "rsdk_toolchain_helper.h"

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
#define DSPHD_TYPES_VENDOR_ID                     43

#define DSPHD_TYPES_AR_RELEASE_MAJOR_VERSION      RSDK_AR_MAJOR
#define DSPHD_TYPES_AR_RELEASE_MINOR_VERSION      RSDK_AR_MINOR
#define DSPHD_TYPES_AR_RELEASE_REVISION_VERSION   RSDK_AR_REV

#define DSPHD_TYPES_SW_MAJOR_VERSION              RSDK_SW_MAJOR
#define DSPHD_TYPES_SW_MINOR_VERSION              RSDK_SW_MINOR
#define DSPHD_TYPES_SW_PATCH_VERSION              RSDK_SW_PATCH

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Verify vendor ID and version numbers for included header file: Std_Types.h */
#if (DSPHD_TYPES_VENDOR_ID != STD_VENDOR_ID)
    #error "Dsphd_types.h and Std_Types.h have different vendor IDs"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((DSPHD_TYPES_AR_RELEASE_MAJOR_VERSION    != STD_AR_RELEASE_MAJOR_VERSION) || \
         (DSPHD_TYPES_AR_RELEASE_MINOR_VERSION    != STD_AR_RELEASE_MINOR_VERSION) || \
         (DSPHD_TYPES_AR_RELEASE_REVISION_VERSION != STD_AR_RELEASE_REVISION_VERSION) \
        )
        #error "AutoSar Version Numbers of Dsphd_types.h and Std_Types.h are different"
    #endif
#endif

/* Verify vendor ID and version numbers for included header file: rsdk_toolchain_helper.h */
#if (DSPHD_TYPES_VENDOR_ID != RSDK_TOOLCHAIN_HELPER_VENDOR_ID)
    #error "Dsphd_types.h and rsdk_toolchain_helper.h have different vendor IDs"
#endif

#if ((DSPHD_TYPES_AR_RELEASE_MAJOR_VERSION    != RSDK_TOOLCHAIN_HELPER_AR_RELEASE_MAJOR_VERSION) || \
     (DSPHD_TYPES_AR_RELEASE_MINOR_VERSION    != RSDK_TOOLCHAIN_HELPER_AR_RELEASE_MINOR_VERSION) || \
     (DSPHD_TYPES_AR_RELEASE_REVISION_VERSION != RSDK_TOOLCHAIN_HELPER_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Dsphd_types.h and rsdk_toolchain_helper.h are different"
#endif

#if ((DSPHD_TYPES_SW_MAJOR_VERSION != RSDK_TOOLCHAIN_HELPER_SW_MAJOR_VERSION) || \
     (DSPHD_TYPES_SW_MINOR_VERSION != RSDK_TOOLCHAIN_HELPER_SW_MINOR_VERSION) || \
     (DSPHD_TYPES_SW_PATCH_VERSION != RSDK_TOOLCHAIN_HELPER_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Dsphd_types.h and rsdk_toolchain_helper.h are different"
#endif


#endif /* RSDK_AUTOSAR */
/*==================================================================================================
*                                      Constants
==================================================================================================*/

/**
  * @anchor   Anchor_RSDK_DSPHD_MSG_BASE_ADDR
  * @brief    Base address used for referencing the DSP Host Driver's message buffer.
  * @details  This symbol should be defined identically in the linker files of both applications running on the DSP and host CPU.
  */
RSDK_DECL_LNK_SYM(RSDK_DSPHD_MSG_BASE_ADDR);

/*==================================================================================================
*                                      MACROS
==================================================================================================*/
/** @addtogroup dsp_hd_api_const
* @{
*/
#define DSPHD_SIZEOF_MSG          12                /**< Size of the DSP message buffer that must be allocated by the user. */
#define DSPHD_SIZEOF_JOB_LIST   ((16u * 10u) + 2u)    /**< Size of the job list buffer(s) that must be allocated by the user. */
/** @}*/
/*==================================================================================================
*                          TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
#ifdef RSDK_AUTOSAR
#define DSPHD_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dsphd_MemMap.h"
#endif

/** @addtogroup dsp_hd_api_data_type
* @{
*/

/**
* @brief          This structure packs the information needed to call a function remotely on the BBE32 DSP, 
                  through the DSP Dispatcher .
*/
typedef struct {
    uint8 id;     /**< Job ID returned from RSDK_DSP_GET_FUNC_ID(function_name)*/
    uint32 arg;   /**< Job argument. Can be either an immediate value or a 32-bit pointer to a data structure. */
} Dsphd_JobType;

#ifdef SAF86XX

typedef void (*Dsp_IsrCbType)(rsdkStatus_t isrStatus, uint32 errInfo);
typedef void (*Dsp_BootloaderCbType)(void);

/**
* @brief          DSP Host Driver init parameters.
* @details 	      They provide an option to boot the BBE32 from the DSP Host Driver and to configure the DSP error interrupt.
*                 Intended to be passed to Dsphd_Init().
*/
typedef struct
{
    uint8                   dspBootEn;  /**< Enable the BBE32 DSP to boot-up and start running the "DSP Dispatcher":
                                             0=disable, "non-0"=enable. */
    Dsp_IsrCbType           dspIsrCb;   /**< <b>[in]</b> Callback function to be called from the DSP interrupt handler.
                                             Used to pass BBE32 status & error information to the user application.
                                             If no callback is required then it can be initialized to NULL. */
    Dsp_BootloaderCbType    dspBootloaderCb; /**< <b>[in]</b> External function called for loading the DSP boot image into memory.
                                          This functions is called by the driver in the middle of the boot procedure,
                                          because the DSP internal memory (IRAM, DRAM) can only be accessed after releasing
                                          the DSP from reset. This callback is required when dspBootEn != 0. */
} Dsphd_InitType;


#endif //SAF86XX

/**
* @brief          This structure packs the information needed for ACK status from DSP Dispatcher
*/
typedef enum {
    DSPHD_ACK_WAITING, /**< Waiting for ACK*/
    DSPHD_ACK_RECEIVED, /**< ACK has been received from the DSP Dispatcher before timeout*/
    DSPHD_ACK_OUT_OF_ORDER, /**< ACK is not for the command we sent. This should never happen.
                                   If it does something is seriously wrong.*/
    DSPHD_ACK_TIMEOUT, /**< ACK has not been received in the expected time from DSP Dispatcher*/
} Dsphd_AckStatusType;

/**
* @brief     Defines the internal state of the DSP Dispatcher
* @details   Can be used to detect Dispatcher "idle" or "error" states
*/
typedef enum {
    DSPHD_DISP_STATE_INIT = 424242u, /**< Dispatcher initialized*/
    DSPHD_DISP_STATE_RUNNING, /**< Dispatcher running*/
    DSPHD_DISP_STATE_ERROR, /**< Dispatcher has reported unrecoverable error and halted*/
    DSPHD_DISP_STATE_IDLE, /**< Dispatcher idle. DSP is in low power wait state.*/
} Dsphd_DispatcherStateType;

/**
* @brief          This structure packs the information needed to configure and start application trace logging
                  in the DSP Dispatcher .
*/
typedef struct {
    uint8* bufAddr;     /**< Address of the trace log buffer*/
    uint16 bufSize;   /**<  Size of the trace log buffer in bytes*/
} Dsphd_TraceCfgType;

/**
* @brief          Defines the types of messages that P1 Task can be configured to.
*/

typedef enum {
    DSPHD_CFG_P1_TASK_PREEMPT, /**< Preempt P1 Task behavior and dispatcher operation. All interrupts enabled P1Task Preemptive with highest priority.
                                    P1 Task sleeps after every chirp and other tasks can run in the meantime.*/
    DSPHD_CFG_P1_TASK_NON_PREEMPT, /**< Non-Preempt P1 Task behavior and dispatcher operation. All interrupts related to other tasks 
                                        are disabled except RFS until numberOfChirps are processed.
                                        Chirp End interrupt waited via polling. Dispatcher never leaves P1 Task for the duration of expected chirps*/
    DSPHD_CFG_P1_TASK_EXTEND_ENUM_TO_32_BITS = 0x7FFFFFFFu
} Dsphd_p1TaskConfigType;

/**
* @brief          Defines the types of messages that correspond to FPU Rounding
*/

typedef enum {
    DSPHD_CFG_FPU_ROUND_TO_NEAREST, /**< FPU Round to nearest*/
    DSPHD_CFG_FPU_ROUND_TRUNC, /**< FPU Round towards 0*/
    DSPHD_CFG_FPU_ROUND_CEIL, /**< FPU Round towards +Infinity*/
    DSPHD_CFG_FPU_ROUND_FLOOR, /**< FPU Round towards -Infinity*/
    DSPHD_CFG_FPU_EXTEND_ENUM_TO_32_BITS = 0x7FFFFFFFu
} Dsphd_fpuRoundConfigType;

/**
* @brief          This structure packs the information needed to configure the runtime configuration of the DSP Dispatcher .
* @details        It must be used as payload to the #DSPHD_MSG_UPDATE_DISPATCHER_CONFIG message type
*/

typedef struct {
    uint16 numberOfChirps;                         /**< Number of chirps expected from LINE_DONE interrupt after which all interrupts are re-enabled and Dispatcher exists P1*/
    Dsphd_p1TaskConfigType p1TaskConfig;           /**< Specifies P1 task operation via Dsphd_p1TaskConfigType enum*/
    Dsphd_fpuRoundConfigType fpuRoundConfig;       /**< Configure the behavior of the DSP via FCR register for rounding*/
    volatile Dsphd_DispatcherStateType* pDispatcherState;   /** Global shared location where the DSP Dispatcher can report information about the DSP Dispatcher state */
    uint8 reportFPUExceptions;                     /**< Poll and throw FPU errors to the core after each BBE32 kernel; 0 means disabled; 1 means enabled*/
    uint8 crc;                                     /**< CRC on this struct*/
} Dsphd_RuntimeCfgType;

/**
* @brief          Defines the types of messages that can be sent from the host CPU application to the DSP Dispatcher
* @details        Enum values are starting from a large random number instead of 0, to avoid false interpretation of uninitialized memory
* */
typedef enum {
    DSPHD_MSG_RUN_ASYNC_JOB = 424242u,    /**< Command to execute an asynchronous job (function) immediately as the message is received */
    DSPHD_MSG_UPDATE_CE_JOB_LIST,        /**< Command to update the list of jobs that are executed periodically on each chirp end
                                                 (jobs that are triggered by the CSI2 LINE_DONE interrupt)*/
    DSPHD_MSG_UPDATE_RC_JOB_LIST,        /**< Command to update the list of jobs that are executed periodically on each radar cycle
                                                 (jobs that are triggered by the CSI2 VSYNC interrupt)*/
    DSPHD_MSG_UPDATE_LONG_JOB_LIST,    /**< Command to update the list of jobs that are executed periodically with lower priority
                                                 than the ones defined by #DSPHD_MSG_UPDATE_RC_JOB_LIST (e.g. self test, measuring core load etc) */
    DSPHD_MSG_CLEAR_CE_JOB_LIST,        /**< Command to clear the list of jobs that are executed periodically on each chirp end
                                                 (jobs that are triggered by the CSI2 LINE_DONE interrupt)*/
    DSPHD_MSG_CLEAR_RC_JOB_LIST,        /**< Command to clear the list of jobs that are executed periodically on each radar cycle
                                                 (jobs that are triggered by the CSI2 VSYNC interrupt)*/
    DSPHD_MSG_CLEAR_LONG_JOB_LIST,    /**< Command to clear the list of jobs that are executed periodically with lower priority
                                                 than the ones defined by #DSPHD_MSG_UPDATE_RC_JOB_LIST (e.g. self test, measuring core load etc) */
    DSPHD_MSG_UPDATE_DISPATCHER_CONFIG, /**< Command that configures the dsp dispatcher parameters at runtime. */
    DSPHD_MSG_CHECK_DISPATCHER_ALIVE, /**< Command that "pings" the Dispatcher and waits for an ACK to verify the Dispatcher is not stuck. */
    DSPHD_MSG_DSP_TRACE_START,    /**< Command to start logging events to the DSP Dispatcher trace log. */
    DSPHD_MSG_DSP_TRACE_END,    /**< Command to stop logging events to the DSP Dispatcher trace log. */
    DSPHD_MSG_LAST,
    DSPHD_MSG_EXTEND_ENUM_TO_32_BITS = 0x7FFFFFFFu
} Dsphd_MsgTypeType;

/**
* @brief          Defines the signals that can be used for the 2nd IPCF channel for different events (ASYNC_DONE as an example)
* */
typedef enum {
    DSPHD_SIG_ASYNC_DONE = 0x7C0DE001, /**< Signal ASYNC (P3) task kernel done */
    DSPHD_SIG_ASYNC_DONE_EXTEND_ENUM_TO_32_BITS = 0x7FFFFFFFu
} Dsphd_SignalsType;

/**
* @brief          This structure packs the information needed to send an ACK from the DSP Dispatcher to the core .
*/
typedef struct {
    uint32 commandNumber; /**< Number of the command that receives ACK*/
    Dsphd_MsgTypeType commandType; /**< Specifies the command type that has been ACKed*/
} Dsphd_CommandAckType;

/** @}*/

#ifdef RSDK_AUTOSAR
#define DSPHD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dsphd_MemMap.h"
#endif

#ifdef __cplusplus
}
#endif

#endif  /*RSDK_DSP_HD_API_H*/
