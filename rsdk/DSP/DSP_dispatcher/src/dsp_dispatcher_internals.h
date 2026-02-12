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

#ifndef DSP_DISPATCHER_INTERNALS_H
#define DSP_DISPATCHER_INTERNALS_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "rsdk_dsp_dispatcher.h"

#include "CDD_Dsphd.h"
#include "Dsphd_Types.h"

#include "dsp_jobs.h"
#include <xtensa/xos.h>

#if ((defined TRACE_ENABLE) && !defined(S32R45))
#include "dsp_trace.h"
#endif

#include "ipc-shm.h"

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define HALT_BBE32 while (blockBBE32Execution != 0U){}

//TODO: task stack size values should be compile-time configurable in the Dispatcher API

#define P1_THR_PRIO 9



#define P1_STACK_SIZE (XOS_STACK_MIN_SIZE + 0x1000u)




#define P2_THR_PRIO 7
#define P2_STACK_SIZE (XOS_STACK_MIN_SIZE + 0x1000u)



#define P3_THR_PRIO 5



#define P3_STACK_SIZE (XOS_STACK_MIN_SIZE + 0x1000u)


#define P4_THR_PRIO 3
#define P4_STACK_SIZE (XOS_STACK_MIN_SIZE + 0x1000u)
#define P5_THR_PRIO 1
#define P5_STACK_SIZE (XOS_STACK_MIN_SIZE + 0x1000u)



#define P6_THR_PRIO 0
#define P6_STACK_SIZE (XOS_STACK_MIN_SIZE_NO_CP)


#define BBE32_CLOCK_MHZ (XOS_CLOCK_FREQ*600u)







#define DSP_FPU_ROUNDING_MASK         0x3u
#define DSP_FPU_EXC_MASK            0x1Fu
#define DSP_FPU_EXC_SHIFT_VAL        0x7u

#define IPCF_REMOTE_INIT_WATERMARK  0x46435049u


#define PREFCTL_HW_DATA_SHIFT       0x0U
#define PREFCTL_HW_INSTR_SHIFT      0x4U
#define PREFCTL_SW_PREF_SHIFT       0x8U
#define PREFCTL_DL_1_SHIFT          0xCU
#define PREFCTL_IL_1_SHIFT          0xDU

#define PREFCTL_HW_DATA_MASK        0xFU
#define PREFCTL_HW_INSTR_MASK       0xFU
#define PREFCTL_SW_PREF_MASK        0xFU
#define PREFCTL_DL_1_MASK           0x1U
#define PREFCTL_IL_1_MASK           0x1U

#define BITMASK_EXCCAUSES 0x3717FFEFu //mask that gives the exccause override for exception handlers
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

typedef struct {
    Dsphd_MsgTypeType type;
    uint32_t payload;
    uint8_t crc;
} rsdkDspHDMsg_t;


typedef struct
{

    volatile Dsphd_RuntimeCfgType runtimeConfig;
    dspDispCommParams_t commParams;

    volatile uint32_t numChirpsElapsed;

    volatile uint8_t p2PendingSptCmds;
    volatile uint16_t sptEvtIntEnBitmap;
    volatile uint32_t numSptCmdsReceived;

    volatile uint32_t numArmCmdsReceived;
    volatile uint32_t numRadarCycles;
    rsdkDspFuncPtr_t *pFuncTable;
    uint32_t funcTableSize;

} dispatcherMemPer_t;



typedef struct
{
    volatile uint32_t exccause;
    volatile uint32_t excvaddr;
    volatile uint32_t ps;
    volatile uint32_t epc1;
} dispatcherErrContext_t;
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
extern volatile uint8_t blockBBE32Execution;
extern dispatcherMemPer_t gRsdkDspDispatcherMemPer;

extern XosThread P1ThreadTcb;

extern XosThread P2ThreadTcb;

extern XosThread P3ThreadTcb;
extern XosThread P4ThreadTcb;
extern XosThread P5ThreadTcb;

extern XosThread P6ThreadTcb;



extern volatile JobList_t* pP1RawJobList;
extern volatile JobList_t* pP3RawJobList;
extern volatile JobList_t* pP4RawJobList;
extern volatile JobList_t* pP5RawJobList;



extern volatile rsdkDspHDMsg_t gRsdkDspHDMsg;
extern volatile bool gP1JobListUpdateFlag;
extern volatile bool gP4JobListUpdateFlag;
extern volatile bool gP5JobListUpdateFlag;
extern volatile Dsphd_DispatcherStateType dispatcherStateDefaultLoc;



#ifdef TRACE_ENABLE
extern volatile uint32_t dispEvtLog[];
extern volatile uint32_t dispEvtLogIdx;
extern uint32_t dispatcherRunTrace;
extern uint32_t dispatcherInitTrace;
#endif

extern volatile dispatcherErrContext_t dspErrorContext;

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

extern char* GetShmBuffer(uint8 instance, uint8_t channel, size_t size);



#ifdef __cplusplus
}
#endif

#endif /*DSP_DISPATCHER_INTERNALS_H*/
