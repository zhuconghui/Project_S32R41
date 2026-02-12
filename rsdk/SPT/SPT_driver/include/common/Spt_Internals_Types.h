
/*
 * Copyright 2021-2023 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */








#ifndef SPT_INTERNALS_TYPES_H
#define SPT_INTERNALS_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Spt_Types.h"
#include "Spt_Cfg.h"
#include "rsdk_version.h"







/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define SPT_INTERNALS_TYPES_VENDOR_ID                          43
#define SPT_INTERNALS_TYPES_AR_RELEASE_MAJOR_VERSION           RSDK_AR_MAJOR
#define SPT_INTERNALS_TYPES_AR_RELEASE_MINOR_VERSION           RSDK_AR_MINOR
#define SPT_INTERNALS_TYPES_AR_RELEASE_REVISION_VERSION        RSDK_AR_REV
#define SPT_INTERNALS_TYPES_SW_MAJOR_VERSION                   RSDK_SW_MAJOR
#define SPT_INTERNALS_TYPES_SW_MINOR_VERSION                   RSDK_SW_MINOR
#define SPT_INTERNALS_TYPES_SW_PATCH_VERSION                   RSDK_SW_PATCH


/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/


/* Check if Spt_Internals_Types header file and Spt_Types header file are of the same vendor */
#if (SPT_INTERNALS_TYPES_VENDOR_ID != SPT_TYPES_VENDOR_ID)
    #error "Spt_Internals_Types.c and Spt_Types.h have different vendor ids"
#endif

/* Check if Spt_Internals_Types header file and Spt_Types header file are of the same Autosar version */
#if ((SPT_INTERNALS_TYPES_AR_RELEASE_MAJOR_VERSION    != SPT_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (SPT_INTERNALS_TYPES_AR_RELEASE_MINOR_VERSION    != SPT_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (SPT_INTERNALS_TYPES_AR_RELEASE_REVISION_VERSION != SPT_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Spt_Internals_Types.c and Spt_Types.h are different"
#endif

/* Check if Spt_Internals_Types header file and Spt_Types header file are of the same Software version */
#if ((SPT_INTERNALS_TYPES_SW_MAJOR_VERSION != SPT_TYPES_SW_MAJOR_VERSION) || \
     (SPT_INTERNALS_TYPES_SW_MINOR_VERSION != SPT_TYPES_SW_MINOR_VERSION) || \
     (SPT_INTERNALS_TYPES_SW_PATCH_VERSION != SPT_TYPES_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Spt_Internals_Types.h and Spt_Types.h are different"
#endif

/* Check Spt_Cfg.h versions                                                                                */
#if (SPT_INTERNALS_TYPES_VENDOR_ID != SPT_CFG_VENDOR_ID)
    #error "Spt.h and Spt_Cfg.h have different vendor ids"
#endif

/* Check if Spt_Internals_Types header file and Spt_Cfg configuration header file are of the same Autosar version */
#if ((SPT_INTERNALS_TYPES_AR_RELEASE_MAJOR_VERSION    != SPT_CFG_AR_RELEASE_MAJOR_VERSION) ||   \
    (SPT_INTERNALS_TYPES_AR_RELEASE_MINOR_VERSION    != SPT_CFG_AR_RELEASE_MINOR_VERSION) ||   \
    (SPT_INTERNALS_TYPES_AR_RELEASE_REVISION_VERSION != SPT_CFG_AR_RELEASE_REVISION_VERSION)   \
    )
    #error "AutoSar Version Numbers of Spt_Internals_Types.h and Spt_Cfg.h are different"
#endif

/* Check if Spt_Internals_Types header file and Spt_Cfg configuration header file are of the same software version */
#if ((SPT_INTERNALS_TYPES_SW_MAJOR_VERSION    != SPT_CFG_SW_MAJOR_VERSION) ||     \
    (SPT_INTERNALS_TYPES_SW_MINOR_VERSION    != SPT_CFG_SW_MINOR_VERSION) ||     \
    (SPT_INTERNALS_TYPES_SW_PATCH_VERSION    != SPT_CFG_SW_PATCH_VERSION)        \
    )
    #error "Software Version Numbers of Spt_Internals_Types.h and Spt_Cfg.h are different"
#endif



/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
#define SPT_TIMEOUT_CNT_BLOCK_MODE      (100000u)   /* preload value for blocking mode wait loop */
#define SPT_TIMEOUT_CNT_START           (10000u)

#define SPT_TIMEOUT_CNT_DISABLE         (100u)      /* preload value for SPT disable wait loop
                                                     * (needs to be least 100 AHB clock cycles) */

#define SPT_SEQUENCER_STATE_RST         ((uint32)0)
#define SPT_SEQUENCER_STATE_START       ((uint32)1)

#define SPT_BITMASK_GBL_CTRL_PG_START   ((uint32)0x4)

#define SPT_MAX_MEM_OFFSET              (0x800000U)   /* SPT calling convention only supports memory offsets up to 23 bits */

#define SPT_NUM_WORK_REGISTERS          (48u)
#define SPT_REG_MEM_MAP_SIZE            (0x1000u)
#define SPT_STOP_OPCODE                 (0x04u)
#define SPT_SIZEOF_INSTRUCTION_WORD     (16u)

#if (SPT_MAX_N_PAR > SPT_NUM_WORK_REGISTERS)
#error 'Max number of SPT parameters exceeded!'
#endif

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/
typedef enum
{
    /* Initialize with non-zero complex bit pattern, to make state checks less prone to errors due to
     * random memory content before initalization.
     * This is useful for making sure the user cannot call Spt_Run or Spt_Stop before Spt_Setup */
    SPT_STATE_DISABLED = 0x13579BDFU,
    SPT_STATE_INITIALIZED,
    SPT_STATE_HW_BUSY,
    SPT_STATE_FAULT
} Spt_DrvStateType;

#ifdef TRACE_ENABLE
/* Enum used to add info about RSDK modules and functions in _FUNC_START and _FUNC_END events: */
typedef enum
{
    RSDK_TRACE_JOB_SPT_DRV_INIT = RSDK_TRACE_JOB_SPT_BASE,
    RSDK_TRACE_JOB_SPT_DRV_RUN,
    RSDK_TRACE_JOB_SPT_DRV_CMD,
    RSDK_TRACE_JOB_SPT_DRV_STOP,

    RSDK_TRACE_JOB_SPT_LAST
} Spt_TraceJobType;

typedef enum
{
    RSDK_TRACE_DBG_SPT_KERNEL_START = RSDK_TRACE_DBG_SPT_BASE,
    RSDK_TRACE_DBG_SPT_KERNEL_END,
    RSDK_TRACE_DBG_VAR_VALUE,
    RSDK_TRACE_DBG_SPT_KERNEL_TIMEOUT,
    RSDK_TRACE_DBG_SPT_KERNEL_ERROR,

    RSDK_TRACE_DBG_SPT_LAST
} Spt_TraceDbgType;
#endif

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef struct
{
    volatile Spt_DrvStateType   state;




    volatile sint32 *           kernelRetPar;
    uint32                      errInfo;     /* error information stored in case an error interrupt was caught */





    volatile SPT_Type *         pSptRegs;    /* points to the base address of the SPT memory map */
    boolean                     isSptMemMapped;

#if (SPT_SINGLE_THREAD == STD_OFF)
    boolean                     drvBusyFlag;
#endif




    Spt_DriverOpModeType        prevOpMode;  /* used in Spt_Run to detect changes of the operating mode (block/nonblock) */
} Spt_DrvMemPerType;

/* Generic datatype for all SPT WRs, to workaround the individual definitions provided in the platform headers: */
typedef union SPT_WrReUnionTag
{ /* Work Register Real */
    volatile uint32 R;
    struct
    {
        volatile uint32 SIGN_EXT : 8; /* Sign Extension */
        volatile uint32 REAL : 24;    /* Real part of Work Register R0 */
    } B;
} Spt_WrReTagType;

typedef union SPT_WrImUnionTag
{ /* Work Register Imaginary */
    volatile uint32 R;
    struct
    {
        volatile uint32 SIGN_EXT : 8; /* Sign Extension */
        volatile uint32 IM : 24;      /* Imaginary part of Work Register R0 */
    } B;
} Spt_WrImTagType;

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

#endif /* SPT_INTERNALS_TYPES_H */
