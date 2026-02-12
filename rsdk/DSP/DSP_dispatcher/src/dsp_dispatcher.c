/**************************************************************************************************
 * Copyright 2018-2024 NXP
 **************************************************************************************************
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 **************************************************************************************************/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include <xtensa/tie/radar24.h>
#include <stdbool.h>
#include "dsp_dispatcher_internals.h"

#include "spt_q_handlers.h"

#include "cmd_handlers.h"
#include "interrupts.h"
#include "hw_defs.h"
#include <string.h>

#include "ipc-shm.h"

#include <xtensa/tie/xt_prefetch.h>
#include <xtensa/tie/xt_bben_scalarfp.h>






#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

extern const struct ipc_shm_instances_cfg ipcf_shm_instances_cfg;

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
dispatcherMemPer_t gRsdkDspDispatcherMemPer;


XosThread P1ThreadTcb;
uint8_t p1ThreadStack[P1_STACK_SIZE];

volatile bool gP1JobListUpdateFlag;
rsdkDspParsedJobList_t gP1ParsedJobList;



volatile JobList_t* pP1RawJobList;
volatile JobList_t* pP3RawJobList;

volatile JobList_t* pP4RawJobList;
volatile JobList_t* pP5RawJobList;




XosThread P2ThreadTcb;
uint8_t p2ThreadStack[P2_STACK_SIZE];



volatile rsdkDspHDMsg_t gRsdkDspHDMsg;
XosThread P3ThreadTcb;
uint8_t p3ThreadStack[P3_STACK_SIZE];

volatile Dsphd_DispatcherStateType dispatcherStateDefaultLoc;


volatile bool gP4JobListUpdateFlag;
rsdkDspParsedJobList_t gP4ParsedJobList;

XosThread P4ThreadTcb;
uint8_t p4ThreadStack[P4_STACK_SIZE];

volatile bool gP5JobListUpdateFlag;
rsdkDspParsedJobList_t gP5ParsedJobList;

XosThread P5ThreadTcb;
uint8_t p5ThreadStack[P5_STACK_SIZE];




XosThread P6ThreadTcb;
uint8_t p6ThreadStack[P6_STACK_SIZE];

volatile dispatcherErrContext_t dspErrorContext;

#ifdef TRACE_ENABLE
uint32_t dispatcherInitTrace, dispatcherRunTrace;
#endif


static uint32_t p1Iter = 0;
static uint32_t p3Iter = 0;

static uint32_t p4Iter = 0;
static uint32_t p5Iter = 0;



static uint32_t p2Iter = 0;

static uint32_t p6Iter = 0;




/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
static void OverrideDefaultExceptions(void)
{
    for (int32_t i = 0; i < XCHAL_EXCCAUSE_NUM; i++)
    {
        if ((((uint64_t)BITMASK_EXCCAUSES >> (uint32_t)i) & 0x1u) == 1u)
        {
            (void)xos_register_exception_handler((uint32_t)i, &DspExceptionHandler);
        }
    }
}

static rsdkStatus_t ParamCheckDispInit(dspDispInit_t const *const pDispInitInfo)
{
    rsdkStatus_t retStatus = RSDK_SUCCESS;

    //---parameter and state check:
    if ((pDispInitInfo == NULL) ||
       ((pDispInitInfo->funcTableSize != 0U) && (pDispInitInfo->pFuncTable == NULL)))
    {
        retStatus = RSDK_DSP_RET_ERR_INVALID_PARAM;
    }

    if ((retStatus == RSDK_SUCCESS) && ((pDispInitInfo->prefAggrParams.prefetchAggressionData > 0xFu) || (pDispInitInfo->prefAggrParams.prefetchAggressionInstr > 0xFu) || (pDispInitInfo->prefAggrParams.prefetchAggressionSW > 0xFu)))	{
		retStatus = RSDK_DSP_RET_ERR_INVALID_PARAM;
	}


    return retStatus;
}


char* GetShmBuffer(uint8 instance, uint8_t channel, size_t size)
{
    char* buf = NULL;
    uint32_t timeout = 10000;
    while(timeout > 0u)
    {
        buf = ipc_shm_acquire_buf(instance, channel, size);
        if (buf != NULL)
        {
            break;
        }

        timeout--;
    }

    return buf;
}

static rsdkStatus_t CommInit(dspDispCommParams_t const * const commParams)
{
    rsdkStatus_t retStatus = RSDK_SUCCESS;

    gRsdkDspDispatcherMemPer.commParams.ipcfInstance = commParams->ipcfInstance;
    gRsdkDspDispatcherMemPer.commParams.ctrlChanId = commParams->ctrlChanId;
    gRsdkDspDispatcherMemPer.commParams.asyncChanId = commParams->asyncChanId;

    if (ipc_shm_init(&ipcf_shm_instances_cfg) != 0)
    {
        retStatus = RSDK_DSP_RET_ERR_COMM_INIT_FAIL;
    }

    return retStatus;
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
rsdkStatus_t RsdkDspDispatcherInit(dspDispInit_t const *const pDispInitInfo)
{
#ifdef TRACE_ENABLE
    dispatcherInitTrace = xos_get_ccount();
#endif

    rsdkStatus_t dspStatus;

    uint32_t il1 = 0x0u; //IL1 off
    uint32_t dl1 = 0x0u; //DL1 off


    //TODO: param check
    dspStatus = ParamCheckDispInit(pDispInitInfo);

    BBX_SCRLU(0x9990, ADDR_DSP_DEBUG3_REG);




    if(dspStatus == RSDK_SUCCESS)
    {

        BBX_SCRLU(0x9991, ADDR_DSP_DEBUG3_REG);
        gRsdkDspDispatcherMemPer.sptEvtIntEnBitmap = pDispInitInfo->sptEvtIntEnBitmap;
        dspStatus = ConfigureInterrupts(pDispInitInfo->sptEvtIntEnBitmap, pDispInitInfo->sptEvtIsrCb);




    }



    // Set PREFCTL Register; IL1 disabled; DL1 disabled; Most aggressive prefetch (HW Data, Hw Instr, Sw)
    // Mitigate Erratum 616 (Xtensa LX Prefetch to L1 Data Cache may deadlock)
    if(dspStatus == RSDK_SUCCESS)
    {
    	XT_WSR_PREFCTL(((il1 & PREFCTL_IL_1_MASK) << PREFCTL_IL_1_SHIFT) |
            ((dl1 & PREFCTL_DL_1_MASK) << PREFCTL_DL_1_SHIFT) |
            ((((uint32_t)pDispInitInfo->prefAggrParams.prefetchAggressionSW) & PREFCTL_SW_PREF_MASK) << PREFCTL_SW_PREF_SHIFT) |
            ((((uint32_t)pDispInitInfo->prefAggrParams.prefetchAggressionInstr) & PREFCTL_HW_INSTR_MASK) << PREFCTL_HW_INSTR_SHIFT) |
            ((((uint32_t)pDispInitInfo->prefAggrParams.prefetchAggressionData) & PREFCTL_HW_DATA_MASK) << PREFCTL_HW_DATA_SHIFT));
    }

    // initialize IPCF communication
    if(dspStatus == RSDK_SUCCESS)
    {
        dspStatus = CommInit(&(pDispInitInfo->commParams));
    }
    if(dspStatus == RSDK_SUCCESS)
    {
        gP1JobListUpdateFlag = false;

        gP4JobListUpdateFlag = false;
        gP5JobListUpdateFlag = false;

    }


    if(dspStatus == RSDK_SUCCESS)
    {

        BBX_SCRLU(0x9992, ADDR_DSP_DEBUG3_REG);



        //initialize Dispatcher's persistent memory:
        gRsdkDspDispatcherMemPer.numArmCmdsReceived = 0;
        gRsdkDspDispatcherMemPer.numRadarCycles = 0;
        gRsdkDspDispatcherMemPer.numChirpsElapsed = 0;

        gRsdkDspDispatcherMemPer.numSptCmdsReceived = 0;
        gRsdkDspDispatcherMemPer.p2PendingSptCmds = 0;

        gRsdkDspDispatcherMemPer.pFuncTable = pDispInitInfo->pFuncTable;
        gRsdkDspDispatcherMemPer.funcTableSize = pDispInitInfo->funcTableSize;

        gRsdkDspDispatcherMemPer.runtimeConfig.numberOfChirps = 0;
        gRsdkDspDispatcherMemPer.runtimeConfig.p1TaskConfig = DSPHD_CFG_P1_TASK_PREEMPT;
        gRsdkDspDispatcherMemPer.runtimeConfig.fpuRoundConfig = DSPHD_CFG_FPU_ROUND_TO_NEAREST;
        gRsdkDspDispatcherMemPer.runtimeConfig.reportFPUExceptions = 0;

        //this is the default location for reporting the Dispatcher state. It can get re-initialized to a host-defined address
        //received through the DSPHD_MSG_UPDATE_DISPATCHER_CONFIG message
        gRsdkDspDispatcherMemPer.runtimeConfig.pDispatcherState = &dispatcherStateDefaultLoc;
        *(gRsdkDspDispatcherMemPer.runtimeConfig.pDispatcherState) = DSPHD_DISP_STATE_INIT;
        // Write default FCR config
        XT_WUR_FCR((uint32_t)gRsdkDspDispatcherMemPer.runtimeConfig.fpuRoundConfig & DSP_FPU_ROUNDING_MASK);


        // Set clock frequency before calling xos_start().
        xos_set_clock_freq(BBE32_CLOCK_MHZ);

        BBX_SCRLU(0x9999, ADDR_DSP_DEBUG3_REG);



    }
    else
    {
        SetDspError(dspStatus);
    }

    //configure overrides for default exception handlers
    OverrideDefaultExceptions();

#ifdef TRACE_ENABLE
    dispatcherInitTrace = xos_get_ccount() - dispatcherInitTrace;
#endif

    return dspStatus;
}



static void RunJobs(rsdkDspParsedJobList_t parsedJobList)
{
    for (uint16_t j = 0; j < parsedJobList.numJobs ; j++ )
    {
        RunDspCmd(&parsedJobList.job[j]);
    }
}

static rsdkStatus_t ParseJobList(volatile JobList_t* rawJobList, rsdkDspParsedJobList_t* parsedJobList, rsdkDspFuncPtr_t *dispatcherFuncTable, uint32_t funcTableSize)
{
    rsdkStatus_t    status;
    parsedJobList->numJobs = rawJobList->numJobs;

    for (uint16_t j = 0; j < parsedJobList->numJobs; j++ )
    {
        status = DispatcherCmdParse((uint8_t*)&(rawJobList->jobDescriptor[j]), &(parsedJobList->job[j]), dispatcherFuncTable, funcTableSize, DSP_CMD_SRC_CPU);
        if ((status != RSDK_SUCCESS) && (status != RSDK_DSP_RET_WARN_CMD_CRC_DISABLED))
        {
            break;
        }
    }

    return status;
}

static int32_t P1Task (void * arg, int32_t unused)
{
    UNUSED_ARG(arg);
    UNUSED_ARG(unused);
    rsdkStatus_t    status = RSDK_SUCCESS;
    while(true)
    {
        RsdkTraceLogEvent(RSDK_TRACE_EVENT_DBG_INFO, RSDK_TRACE_DBG_DSP_P1_ITER, p1Iter);

        if(gP1JobListUpdateFlag == true)
        {
            //A race condition is possible here, if RcsIsr() triggers again, so we use the Update flag to be sure.
            //The update is done here even though there is a time penalty to make sure we don't run in a race condition
            //by updating this Job List in another task (for example P3) because this thread has higher priority than all other tasks.
            gP1JobListUpdateFlag = false;

            //Received A53 interrupt with RSDK_DSPC_MSG_UPDATE_RC_JOB_LIST message, so we update the job list before running the P1 task for next chirp
            status = ParseJobList(pP1RawJobList, &gP1ParsedJobList, gRsdkDspDispatcherMemPer.pFuncTable, gRsdkDspDispatcherMemPer.funcTableSize);
            RsdkTraceLogEvent(RSDK_TRACE_EVENT_DBG_INFO, RSDK_TRACE_DBG_DSP_P1_JOB_LIST_UPDATE, p1Iter);
            if(status != RSDK_SUCCESS)
            {
                SetDspError(status);
            }
        }

        switch (gRsdkDspDispatcherMemPer.runtimeConfig.p1TaskConfig)
        {
            case DSPHD_CFG_P1_TASK_PREEMPT:
            {
                if ((status == RSDK_SUCCESS) || (status == RSDK_DSP_RET_WARN_CMD_CRC_DISABLED))
                {
                    RunJobs(gP1ParsedJobList);
                }
                gRsdkDspDispatcherMemPer.numChirpsElapsed++;
                p1Iter++;
                (void)xos_thread_suspend(XOS_THREAD_SELF); //this operation is expected to be always successful
                break;
            }

            case DSPHD_CFG_P1_TASK_NON_PREEMPT:
            {
                if (gRsdkDspDispatcherMemPer.numChirpsElapsed != gRsdkDspDispatcherMemPer.runtimeConfig.numberOfChirps)
                {
                    // poll interrupt
                    while(!xos_interrupt_pending(XCHAL_EXTINT_CSI2_LINE_DONE)) {

                    }
                    // clear interrupt
                    xthal_interrupt_clear(XCHAL_EXTINT_CSI2_LINE_DONE);
                    if ((status == RSDK_SUCCESS) || (status == RSDK_DSP_RET_WARN_CMD_CRC_DISABLED))
                    {
                        RunJobs(gP1ParsedJobList);
                    }
                    gRsdkDspDispatcherMemPer.numChirpsElapsed++;
                    p1Iter++;
                }
                else
                {
                    gRsdkDspDispatcherMemPer.numChirpsElapsed = 0;
                    EnableAllInterruptsAfterChirpsDone();
                    (void)xos_thread_suspend(XOS_THREAD_SELF); //this operation is expected to be always successful
                }
                break;
            }

            default:
                (void)xos_thread_suspend(XOS_THREAD_SELF); //this operation is expected to be always successful
                break;
        }

    }

    return 0;
}



static void P2DispatchPendingSptCmd(rsdkDspFuncPtr_t *dispatcherFuncTable, uint32_t funcTableSize)
{
    int32_t         rawCmd[4] __attribute__((aligned(16)));  //128 bits storage for the SPT command
    dspCmdContext_t parsedCmd;
    rsdkStatus_t    status;
    int32_t isDataAvailable = 0;



    //pop SPT "DSP" command from queue.
    //NOTE: This cannot be done in SptCmdQIsr(), because there is a risk of popping multiple commands
    //without sending back ordered "ACK"s in the report queue.
    //If the SPT issues more than 1 'dsp' instruction until the Dispatcher sends back "ACK",
    //then it will result in error: HW_ACC_ERR_STATUS[CS_DSP_IF_MISSING_RESP_ERR]
    isDataAvailable = SptCmdQPop(rawCmd);
    gRsdkDspDispatcherMemPer.p2PendingSptCmds--; //mark command as processed










    if (isDataAvailable != 0)
    {

        status = DispatcherCmdParse((uint8_t*)rawCmd, &parsedCmd, dispatcherFuncTable, funcTableSize, DSP_CMD_SRC_SPT);
        if (status == RSDK_SUCCESS)
        {
            RunDspCmd(&parsedCmd);
        }
        else if (status == RSDK_DSP_RET_WARN_CMD_CRC_DISABLED)
        {
            //report the warning but still run the command
            SetDspError(status);
            RunDspCmd(&parsedCmd);
        }
        else
        {
            SetDspError(status);
        }

        //send async "ACK" event in the SPT report queue when the command is done.
        //this is mandatory for all SPT 'dsp' commands (blocking or not), otherwise the SPT will be blocked
        SptRespQPush(parsedCmd.funcID);
        BBX_SCRLU((int32_t)(0x10000000 + (int32_t)parsedCmd.funcID), ADDR_DSP_DEBUG4_REG);

    }
    else
    {
        BBX_SCRLU(0x10000000-1, ADDR_DSP_DEBUG4_REG);
        SetDspError(RSDK_DSP_RET_ERR_CMD_NO_DATA);
    }

}

static int32_t P2Task (void * arg, int32_t unused)
{
    UNUSED_ARG(arg);
    UNUSED_ARG(unused);

    // NOTE: this thread is woken by the SPT Command Queue interrupt

    while(true)
    {
        RsdkTraceLogEvent(RSDK_TRACE_EVENT_DBG_INFO, RSDK_TRACE_DBG_DSP_P2_ITER, p2Iter);

        if(gRsdkDspDispatcherMemPer.p2PendingSptCmds == 0u )
        {
            //TODO: race condition possible here: if SptCmdQIsr() increments p2PendingSptCmds, P2 thread goes to sleep without processing the SPT command
            (void)xos_thread_suspend(XOS_THREAD_SELF); //this operation is expected to be always successful
        }
        else
        {
            P2DispatchPendingSptCmd(gRsdkDspDispatcherMemPer.pFuncTable, gRsdkDspDispatcherMemPer.funcTableSize);
            p2Iter++;
        }

        BBX_SCRLU((int32_t)(0x20000000 + (int32_t)p2Iter), ADDR_DSP_DEBUG3_REG);

    }

    return 0;
}




static int32_t P3Task (void * arg, int32_t unused)
{
    UNUSED_ARG(arg);
    UNUSED_ARG(unused);
    dspCmdContext_t parsedJob;
    volatile JobDescriptor_t* pJobDescriptor;
    rsdkStatus_t    status = RSDK_SUCCESS;
    int8_t ipcfRetVal;

    while(true)
    {
        RsdkTraceLogEvent(RSDK_TRACE_EVENT_DBG_INFO, RSDK_TRACE_DBG_DSP_P3_ITER, p3Iter);

        //Read and parse job descriptor, execute the job directly in the interrupt handler
        pJobDescriptor = (volatile JobDescriptor_t *)&(pP3RawJobList->jobDescriptor[0]);
        status = DispatcherCmdParse((uint8_t*)pJobDescriptor, &parsedJob, gRsdkDspDispatcherMemPer.pFuncTable, gRsdkDspDispatcherMemPer.funcTableSize, DSP_CMD_SRC_CPU);
        if (status != RSDK_SUCCESS)
        {
            SetDspError(status);

        }
        if ((status == RSDK_DSP_RET_WARN_CMD_CRC_DISABLED) || (status == RSDK_SUCCESS))
        {
            RunDspCmd(&parsedJob);
            uint32_t asyncSig = (uint32_t)DSPHD_SIG_ASYNC_DONE;
            char* txBuf = GetShmBuffer(gRsdkDspDispatcherMemPer.commParams.ipcfInstance, gRsdkDspDispatcherMemPer.commParams.asyncChanId, sizeof(asyncSig));
            if (txBuf != NULL)
            {
                (void)memcpy((void*)txBuf, (void *)&asyncSig, sizeof(asyncSig));
                ipcfRetVal = ipc_shm_tx(gRsdkDspDispatcherMemPer.commParams.ipcfInstance, gRsdkDspDispatcherMemPer.commParams.asyncChanId, (void *)txBuf, sizeof(asyncSig));
                if (ipcfRetVal != 0)
                {
                    SetDspError(RSDK_DSP_RET_ERR_TX_FAILED);
                }
            }
            else
            {
                SetDspError(RSDK_DSP_RET_ERR_INVALID_MSG_BUFF);
            }
        }


        p3Iter++;
        (void)xos_thread_suspend(XOS_THREAD_SELF); //this operation is expected to be always successful
    }

    return 0;
}


static int32_t P4Task (void * arg, int32_t unused)
{
    UNUSED_ARG(arg);
    UNUSED_ARG(unused);
    rsdkStatus_t    status = RSDK_SUCCESS;
    int32_t xosStatus = 0;

    while(true)
    {
        RsdkTraceLogEvent(RSDK_TRACE_EVENT_DBG_INFO, RSDK_TRACE_DBG_DSP_P4_ITER, p4Iter);

        if(gP4JobListUpdateFlag == true)
        {
            //A race condition is possible here, if HostEvtIsr() sets the flag to "true" again,
            //but we consider it very unlikely, since such job list changes should not happen more frequently than 1/radar cycle.
            //So don't consider this as a critical section, unless testing shows otherwise...
            gP4JobListUpdateFlag = false;

            //Received A53 interrupt with RSDK_DSPCC_MSG_UPDATE_RC_JOB_LIST message, so we update the job list before running the P4 task for next radar cycle
            status = ParseJobList(pP4RawJobList, &gP4ParsedJobList, gRsdkDspDispatcherMemPer.pFuncTable, gRsdkDspDispatcherMemPer.funcTableSize);
            RsdkTraceLogEvent(RSDK_TRACE_EVENT_DBG_INFO, RSDK_TRACE_DBG_DSP_P4_JOB_LIST_UPDATE, p4Iter);
            if(status != RSDK_SUCCESS)
            {
                SetDspError(status);
            }
        }


        if ((status == RSDK_SUCCESS) || (status == RSDK_DSP_RET_WARN_CMD_CRC_DISABLED))
        {
            RunJobs(gP4ParsedJobList);
        }

        p4Iter++;

        xosStatus = xos_thread_resume(&P5ThreadTcb);
        if(xosStatus != XOS_OK)
        {
            SetDspError(RSDK_DSP_RET_ERR_THR_RESUME);
        }

        (void)xos_thread_suspend(XOS_THREAD_SELF); //this operation is expected to be always successful

    }

    return 0;
}

static int32_t P5Task (void * arg, int32_t unused)
{
    UNUSED_ARG(arg);
    UNUSED_ARG(unused);
    rsdkStatus_t    status = RSDK_SUCCESS;

    while(true)
    {
        RsdkTraceLogEvent(RSDK_TRACE_EVENT_DBG_INFO, RSDK_TRACE_DBG_DSP_P5_ITER, p5Iter);

        if(gP5JobListUpdateFlag == true)
        {
            //A race condition is possible here, if HostEvtIsr() sets the flag to "true" again,
            //but we consider it very unlikely, since such job list changes should not happen more frequently than 1/radar cycle.
            //So don't consider this as a critical section, unless testing shows otherwise...
            gP5JobListUpdateFlag = false;

            //Received A53 interrupt with RSDK_DSPCC_MSG_UPDATE_RC_JOB_LIST message, so we update the job list before running the P4 task for next radar cycle
            status = ParseJobList(pP5RawJobList, &gP5ParsedJobList, gRsdkDspDispatcherMemPer.pFuncTable, gRsdkDspDispatcherMemPer.funcTableSize);
            RsdkTraceLogEvent(RSDK_TRACE_EVENT_DBG_INFO, RSDK_TRACE_DBG_DSP_P5_JOB_LIST_UPDATE, p5Iter);
            if(status != RSDK_SUCCESS)
            {
                SetDspError(status);
            }
        }

        if ((status == RSDK_SUCCESS) || (status == RSDK_DSP_RET_WARN_CMD_CRC_DISABLED))
        {
            RunJobs(gP5ParsedJobList);
        }

        p5Iter++;
        (void)xos_thread_suspend(XOS_THREAD_SELF); //this operation is expected to be always successful

    }

    return 0;
}



static int32_t P6Task (void * arg, int32_t unused)
{
    UNUSED_ARG(arg);
    UNUSED_ARG(unused);

    // NOTE: this thread might not be necessary, since XOS already runs its own "xos_idle_thread"
    //       when it doesn't find any other thread in "ready" state.
    //       But we keep it for better user control of the application e.g. maybe adding a background task in the future.

    while(true)
    {

        // Go to idle state, wait for an interrupt to resume the other threads.
        BBX_SCRLU((int32_t)(0x50000000 + (int32_t)p6Iter), ADDR_DSP_DEBUG5_REG);




        *(gRsdkDspDispatcherMemPer.runtimeConfig.pDispatcherState) = DSPHD_DISP_STATE_IDLE;

        XT_WAITI(0);
        //when any interrupt is triggered, this thread is expected to break out of the WAITI instruction and yield to a higher-prio thread.

        RsdkTraceLogEvent(RSDK_TRACE_EVENT_DBG_INFO, RSDK_TRACE_DBG_DSP_P6_ITER, p6Iter);
        p6Iter++;
    }

    return 0;
}

void RsdkDspDispatcherRun(void)
{
    int32_t xosStatus;

#ifdef TRACE_ENABLE
    dispatcherRunTrace = xos_get_ccount();
#endif

    //TODO: param check

    BBX_SCRLU(0xaaa0, ADDR_DSP_DEBUG3_REG);



    // Select and start system timer.
    xosStatus = xos_start_system_timer(-1, 0);

    if(xosStatus != XOS_OK)
    {
        SetDspError(RSDK_DSP_RET_ERR_TIMER_START);
    }

    if(xosStatus == XOS_OK)
    {
        // "P6" idle thread:
        xosStatus = xos_thread_create(&P6ThreadTcb,            //thread descriptor
                                XOS_NULL,                    //ptr to container thread
                                &P6Task,                        //Thread entry function
                                XOS_NULL,                    //"void*" arg to the thread function
                                "P6Task",                    //thread name
                                p6ThreadStack,                //stack pointer
                                P6_STACK_SIZE,                //stack size
                                P6_THR_PRIO,                //priority: [0.. XOS_MAX_PRIORITY-1].
                                XOS_NULL,                    //ptr to extra params
                                XOS_THREAD_NO_CP);            //thread flags. Options: {XOS_THREAD_SUSPEND, XOS_THREAD_RTC, XOS_THREAD_NO_CP}
    }


    if(xosStatus == XOS_OK)
    {
        //"P2" thread for handling SPT commands:
        xosStatus = xos_thread_create(&P2ThreadTcb,            //thread descriptor
                                XOS_NULL,                    //ptr to container thread
                                &P2Task,                        //Thread entry function
                                XOS_NULL,                    //"void*" arg to the thread function
                                "P2Task",                    //thread name
                                p2ThreadStack,                //stack pointer
                                P2_STACK_SIZE,                //stack size
                                P2_THR_PRIO,                //priority: [0.. XOS_MAX_PRIORITY-1].
                                XOS_NULL,                    //ptr to extra params
                                XOS_THREAD_SUSPEND);        //thread flags. Options: {XOS_THREAD_SUSPEND, XOS_THREAD_RTC, XOS_THREAD_NO_CP}
    }



    if(xosStatus == XOS_OK)
    {
        //"P1" thread for handling chirp done processing (interference detection, interference mitigation):
        xosStatus = xos_thread_create(&P1ThreadTcb,            //thread descriptor
                                XOS_NULL,                    //ptr to container thread
                                &P1Task,                        //Thread entry function
                                XOS_NULL,                    //"void*" arg to the thread function
                                "P1Task",                    //thread name
                                p1ThreadStack,                //stack pointer
                                P1_STACK_SIZE,                //stack size
                                P1_THR_PRIO,                //priority: [0.. XOS_MAX_PRIORITY-1].
                                XOS_NULL,                    //ptr to extra params
                                XOS_THREAD_SUSPEND);        //thread flags. Options: {XOS_THREAD_SUSPEND, XOS_THREAD_RTC, XOS_THREAD_NO_CP}
    }

    if(xosStatus == XOS_OK)
    {
        //"P3" thread for running async application core jobs
        xosStatus = xos_thread_create(&P3ThreadTcb,            //thread descriptor
                                XOS_NULL,                    //ptr to container thread
                                &P3Task,                        //Thread entry function
                                XOS_NULL,                    //"void*" arg to the thread function
                                "P3Task",                    //thread name
                                p3ThreadStack,                //stack pointer
                                P3_STACK_SIZE,                //stack size
                                P3_THR_PRIO,                //priority: [0.. XOS_MAX_PRIORITY-1].
                                XOS_NULL,                    //ptr to extra params
                                XOS_THREAD_SUSPEND);        //thread flags. Options: {XOS_THREAD_SUSPEND, XOS_THREAD_RTC, XOS_THREAD_NO_CP}
    }


    if(xosStatus == XOS_OK)
    {
        //"P4" thread for running periodic radar detection algos + LAL algos, scheduled by CSI2 interrupt (per radar cycle)
        xosStatus = xos_thread_create(&P4ThreadTcb,            //thread descriptor
                                XOS_NULL,                    //ptr to container thread
                                &P4Task,                        //Thread entry function
                                XOS_NULL,                    //"void*" arg to the thread function
                                "P4Task",                    //thread name
                                p4ThreadStack,                //stack pointer
                                P4_STACK_SIZE,                //stack size
                                P4_THR_PRIO,                //priority: [0.. XOS_MAX_PRIORITY-1].
                                XOS_NULL,                    //ptr to extra params
                                XOS_THREAD_SUSPEND);        //thread flags. Options: {XOS_THREAD_SUSPEND, XOS_THREAD_RTC, XOS_THREAD_NO_CP}
    }
    if(xosStatus == XOS_OK)
    {
        //"P5" thread for running periodic long jobs triggered by P4
        xosStatus = xos_thread_create(&P5ThreadTcb,            //thread descriptor
                                XOS_NULL,                    //ptr to container thread
                                &P5Task,                        //Thread entry function
                                XOS_NULL,                    //"void*" arg to the thread function
                                "P5Task",                    //thread name
                                p5ThreadStack,                //stack pointer
                                P5_STACK_SIZE,                //stack size
                                P5_THR_PRIO,                //priority: [0.. XOS_MAX_PRIORITY-1].
                                XOS_NULL,                    //ptr to extra params
                                XOS_THREAD_SUSPEND);        //thread flags. Options: {XOS_THREAD_SUSPEND, XOS_THREAD_RTC, XOS_THREAD_NO_CP}
    }



    if(xosStatus != XOS_OK)
    {
        SetDspError(RSDK_DSP_RET_ERR_DISP_CONFIG);
    }
    else
    {
#ifdef TRACE_ENABLE
        dispatcherRunTrace = xos_get_ccount() - dispatcherRunTrace;
#endif


        *(gRsdkDspDispatcherMemPer.runtimeConfig.pDispatcherState) = DSPHD_DISP_STATE_RUNNING;

        // Start multitasking.
        xos_start(0);

        // Should never get here.

        *(gRsdkDspDispatcherMemPer.runtimeConfig.pDispatcherState) = DSPHD_DISP_STATE_ERROR;

        HALT_BBE32;

    }

}

/*================================================================================================*/

#ifdef __cplusplus
}
#endif

/*******************************************************************************
 * EOF
 ******************************************************************************/
