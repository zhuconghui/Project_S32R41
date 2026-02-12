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
#include <stdbool.h>
#include <xtensa/tie/xt_misc.h>
#include <xtensa/tie/radar24.h>

#include "dsp_dispatcher_internals.h"
#include <xtensa/xos.h>
#include "interrupts.h"
#include "cmd_handlers.h"
#include "hw_defs.h"
#include <string.h>

#include "ipc-shm.h"

#include <xtensa/tie/xt_bben_scalarfp.h>



#include <stddef.h>
#include "crc8.h"

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

extern void ipc_shm_hardirq(void *arg);
extern void CpuEvtIsr(void *arg, const uint8 instance, uint8 chan_id, void *buf, uint32 size);

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

static dspEvtIsrArg_t evtIsrArgList[NUM_EVT_INTS];


static Dsphd_CommandAckType ackPacket;

volatile uint8_t blockBBE32Execution = 1;
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

static void SptCmdQIsr(void *arg)
{
    UNUSED_ARG(arg);

    int32_t xosStatus;

    //not allowed to pop the cmd queue inside the interrupt due to risk of consecutive interrupts
    //triggering HW_ACC_ERR_STATUS[CS_DSP_IF_MISSING_RESP_ERR]
    //So cannot call SptCmdQPop here.












    //no need to clear the interrupt.
    //xos_rm: "Edge-triggered and software interrupts are automatically cleared by the OS interrupt dispatcher (see xos_handlers.S)"

    *(gRsdkDspDispatcherMemPer.runtimeConfig.pDispatcherState) = DSPHD_DISP_STATE_RUNNING;

    RsdkTraceLogEvent(RSDK_TRACE_EVENT_DBG_INFO, RSDK_TRACE_DBG_DSP_SPT_ISR, 0u);

    gRsdkDspDispatcherMemPer.p2PendingSptCmds ++; //mark new command received
    gRsdkDspDispatcherMemPer.numSptCmdsReceived++;

    xosStatus = xos_thread_resume(&P2ThreadTcb);

    if(xosStatus != XOS_OK)
    {
        SetDspError(RSDK_DSP_RET_ERR_THR_RESUME);
    }

    BBX_SCRLU(0x10000001 + (int32_t)gRsdkDspDispatcherMemPer.p2PendingSptCmds, ADDR_DSP_DEBUG2_REG);
}

static void SptEvtIsr(void *arg)
{
    dspEvtIsrArg_t* pEvtIsrArg = (dspEvtIsrArg_t*)arg;
    uint32_t evtID = pEvtIsrArg->evtIntID;
    rsdkDspIsrCb_t evtIsrCallback = pEvtIsrArg->cb;

    //We get the evt number as argument, directly from the interrupt registration.

    BBX_SCRLU((int32_t)evtID, ADDR_DSP_DEBUG1_REG);//report EVT numbers {0..12}

    if(evtID > NUM_EVT_INTS)
    {
        //this handler was called with invalid EVT ID
        SetDspError(RSDK_DSP_RET_ERR_UNKNOWN);
        HALT_BBE32;
    }
    else
    {
        //no need to clear the interrupt, it's already done in the LevelOneInterrupt

        //user callback
        if (evtIsrCallback != NULL)
        {
            evtIsrCallback(evtID);
        }
    }

}


void DspExceptionHandler(XosExcFrame * frame)
{
	
	dspErrorContext.exccause = frame->exccause;
	dspErrorContext.excvaddr = frame->excvaddr;
	dspErrorContext.ps = frame->ps;
	dspErrorContext.epc1 = frame->pc;


    BBX_SCRLU((int32_t)dspErrorContext.exccause, ADDR_DSP_DEBUG1_REG);




    SetDspError((rsdkStatus_t)RSDK_DSP_RET_ERR_EXCEPTION);


    *(gRsdkDspDispatcherMemPer.runtimeConfig.pDispatcherState) = DSPHD_DISP_STATE_ERROR;


    //if we get here BBE32 needs a reboot
    HALT_BBE32;
}

static void WriteErrIsr(void *arg)
{
    UNUSED_ARG(arg);
    //do not halt the core following an AXI error, just report it to the host and continue execution
    SetDspError((rsdkStatus_t)RSDK_DSP_RET_ERR_AXI_WRITE);
}


void EnableAllInterruptsAfterChirpsDone(void)
{
    int32_t xosStatus;

    // Re-enable ARM core interrupt
    xosStatus = xos_interrupt_enable(XCHAL_EXTINT_ARM);
    if(xosStatus != XOS_OK)
    {
        SetDspError(RSDK_DSP_RET_ERR_INT_ENABLE);
    }

    // Re-enable chirp sync interrupt
    xosStatus = xos_interrupt_enable(XCHAL_EXTINT_CSI2_LINE_DONE);
    if(xosStatus != XOS_OK)
    {
        SetDspError(RSDK_DSP_RET_ERR_INT_ENABLE);
    }


    // Re-enable SPT Queue interrupt
    xosStatus = xos_interrupt_enable(XCHAL_EXTINT0_NUM);
    if(xosStatus != XOS_OK)
    {
        SetDspError(RSDK_DSP_RET_ERR_INT_ENABLE);
    }

    // Re-enable SPT interrupts
    for (uint32_t i = (uint32_t)XCHAL_EXTINT1_NUM; i <= (uint32_t)XCHAL_EXTINT13_NUM; i++)
    {
        uint32_t evtID = i-(uint32_t)XCHAL_EXTINT1_NUM;
        if( (gRsdkDspDispatcherMemPer.sptEvtIntEnBitmap & (uint16_t)((uint16_t)0x0001u << (evtID)) ) != 0u)
        {
            xosStatus = xos_interrupt_enable(i);
            if(xosStatus != XOS_OK)
            {
                SetDspError(RSDK_DSP_RET_ERR_INT_ENABLE);
            }
        }
    }

}

static void DisableAllInterruptsForP1NonPreempt(void)
{
    int32_t xosStatus;

    // Disable chirp sync interrupt
    xosStatus = xos_interrupt_disable(XCHAL_EXTINT_CSI2_LINE_DONE);
    if(xosStatus != XOS_OK)
    {
        SetDspError(RSDK_DSP_RET_ERR_INT_DISABLE);
    }

    // Disable ARM core interrupt
    xosStatus = xos_interrupt_disable(XCHAL_EXTINT_ARM);
    if(xosStatus != XOS_OK)
    {
        SetDspError(RSDK_DSP_RET_ERR_INT_DISABLE);
    }


    // Disable SPT Queue interrupt
    xosStatus = xos_interrupt_disable(XCHAL_EXTINT0_NUM);
    if(xosStatus != XOS_OK)
    {
        SetDspError(RSDK_DSP_RET_ERR_INT_DISABLE);
    }

    // Disable SPT interrupts
    for (uint32_t i = (uint32_t)XCHAL_EXTINT1_NUM; i <= (uint32_t)XCHAL_EXTINT13_NUM; i++)
    {
        uint32_t evtID = i-(uint32_t)XCHAL_EXTINT1_NUM;
        if( (gRsdkDspDispatcherMemPer.sptEvtIntEnBitmap & (uint16_t)((uint16_t)0x0001u << (evtID)) ) != 0u)
        {
            xosStatus = xos_interrupt_disable(i);
            if(xosStatus != XOS_OK)
            {
                SetDspError(RSDK_DSP_RET_ERR_INT_DISABLE);
            }
        }
    }


}
void CpuEvtIsr(void *arg, const uint8 instance, uint8 chan_id, void *buf, uint32 size)
{
    /*buffer size can be verified at compile time...*/
    RSDK_COMPILER_ASSERT(sizeof(rsdkDspHDMsg_t) == DSPHD_SIZEOF_MSG);
    RSDK_COMPILER_ASSERT(((int32_t)offsetof(rsdkDspHDMsg_t, payload))  == DSP_MSG_STRUCT_PAYLOAD_OFFSET);
    RSDK_COMPILER_ASSERT((int32_t)(offsetof(rsdkDspHDMsg_t, crc))  == DSP_MSG_STRUCT_CRC_OFFSET);

    UNUSED_ARG(arg);
    UNUSED_ARG(size);
    UNUSED_ARG(instance);
    UNUSED_ARG(chan_id);

    int32_t xosStatus;

    *(gRsdkDspDispatcherMemPer.runtimeConfig.pDispatcherState) = DSPHD_DISP_STATE_RUNNING;

    // Check if CRC is correct, if not throw error to core
    uint8_t crcRead = ((rsdkDspHDMsg_t *)buf)->crc;
    uint8_t crcComputed = GenCrc8((uint8_t*)&((rsdkDspHDMsg_t *)buf)->type, (uint8)(offsetof(rsdkDspHDMsg_t, crc)));
    if (crcRead != crcComputed)
    {
        SetDspError(RSDK_DSP_RET_ERR_CRC_INVALID);
    }
    gRsdkDspHDMsg.type = ((rsdkDspHDMsg_t *)buf)->type;
    gRsdkDspHDMsg.payload = ((rsdkDspHDMsg_t *)buf)->payload;

    RsdkTraceLogEvent(RSDK_TRACE_EVENT_DBG_INFO, RSDK_TRACE_DBG_DSP_CPU_ISR, gRsdkDspHDMsg.type);
    gRsdkDspDispatcherMemPer.numArmCmdsReceived++;

    BBX_SCRLU((int32_t)0xF0000000U, ADDR_DSP_DEBUG2_REG);



    switch (gRsdkDspHDMsg.type)
    {
        case DSPHD_MSG_UPDATE_DISPATCHER_CONFIG:
        {
        	//check that the Dsphd_RuntimeCfgType structure fields are found at the same offsets on DSP and host CPU side
            RSDK_COMPILER_ASSERT(sizeof(Dsphd_RuntimeCfgType) == DSP_SIZEOF_RUNTIME_CFG_MSG);
            RSDK_COMPILER_ASSERT(offsetof(Dsphd_RuntimeCfgType, p1TaskConfig)  == DSP_RUNTIME_CFG_STRUCT_P1_TASK_CONFIG_OFFSET);
            RSDK_COMPILER_ASSERT(offsetof(Dsphd_RuntimeCfgType, fpuRoundConfig)  == DSP_RUNTIME_CFG_STRUCT_FPU_ROUND_CONFIG_OFFSET);
            RSDK_COMPILER_ASSERT(offsetof(Dsphd_RuntimeCfgType, pDispatcherState) == DSP_RUNTIME_CFG_STRUCT_DISP_STATE_CONFIG_OFFSET);
            RSDK_COMPILER_ASSERT(offsetof(Dsphd_RuntimeCfgType, reportFPUExceptions)  == DSP_RUNTIME_CFG_STRUCT_REPORT_FPU_EXC_OFFSET);
            RSDK_COMPILER_ASSERT(offsetof(Dsphd_RuntimeCfgType, crc)  == DSP_RUNTIME_CFG_STRUCT_CRC_OFFSET);

            crcRead = ((Dsphd_RuntimeCfgType*)gRsdkDspHDMsg.payload)->crc;
            crcComputed = GenCrc8((uint8_t*)&((Dsphd_RuntimeCfgType *)gRsdkDspHDMsg.payload)->numberOfChirps, (uint8)(offsetof(Dsphd_RuntimeCfgType, crc)));
            if (crcRead != crcComputed)
            {
                SetDspError(RSDK_DSP_RET_ERR_CRC_INVALID);
            }

            gRsdkDspDispatcherMemPer.numChirpsElapsed = 0; // start fresh
            Dsphd_RuntimeCfgType* pDspRuntimeCfg = (Dsphd_RuntimeCfgType*)gRsdkDspHDMsg.payload;
            gRsdkDspDispatcherMemPer.runtimeConfig.numberOfChirps = pDspRuntimeCfg->numberOfChirps;

            if (pDspRuntimeCfg->pDispatcherState == NULL)
            {
                SetDspError(RSDK_DSP_RET_ERR_INVALID_PARAM);
            }
            else
            {
                gRsdkDspDispatcherMemPer.runtimeConfig.pDispatcherState = pDspRuntimeCfg->pDispatcherState;
                *(gRsdkDspDispatcherMemPer.runtimeConfig.pDispatcherState) = dispatcherStateDefaultLoc;
            }

            if ((pDspRuntimeCfg->p1TaskConfig != DSPHD_CFG_P1_TASK_NON_PREEMPT) && (pDspRuntimeCfg->p1TaskConfig != DSPHD_CFG_P1_TASK_PREEMPT))
            {
                pDspRuntimeCfg->p1TaskConfig = DSPHD_CFG_P1_TASK_PREEMPT;
                SetDspError(RSDK_DSP_RET_ERR_INVALID_PARAM);
            }
            if ((pDspRuntimeCfg->fpuRoundConfig < DSPHD_CFG_FPU_ROUND_TO_NEAREST) || (pDspRuntimeCfg->fpuRoundConfig > DSPHD_CFG_FPU_ROUND_FLOOR))
            {
                pDspRuntimeCfg->fpuRoundConfig = DSPHD_CFG_FPU_ROUND_TO_NEAREST;
                SetDspError(RSDK_DSP_RET_ERR_INVALID_PARAM);
            }
            gRsdkDspDispatcherMemPer.runtimeConfig.fpuRoundConfig = pDspRuntimeCfg->fpuRoundConfig;
            gRsdkDspDispatcherMemPer.runtimeConfig.reportFPUExceptions = pDspRuntimeCfg->reportFPUExceptions;
            gRsdkDspDispatcherMemPer.runtimeConfig.p1TaskConfig = pDspRuntimeCfg->p1TaskConfig;
            XT_WUR_FCR((uint32_t)(gRsdkDspDispatcherMemPer.runtimeConfig.fpuRoundConfig) & DSP_FPU_ROUNDING_MASK);
            break;
        }
        case DSPHD_MSG_UPDATE_CE_JOB_LIST:
            if(gP1JobListUpdateFlag == false)
            {
                gP1JobListUpdateFlag = true;
                pP1RawJobList = (JobList_t*)gRsdkDspHDMsg.payload;
            }
            else
            {
                SetDspError(RSDK_DSP_RET_ERR_CE_JOBS_NOT_UPDATED);
            }
            break;

        case DSPHD_MSG_UPDATE_RC_JOB_LIST:
            if(gP4JobListUpdateFlag == false)
            {
                gP4JobListUpdateFlag = true;
                pP4RawJobList = (JobList_t*)gRsdkDspHDMsg.payload;
            }
            else
            {
                SetDspError(RSDK_DSP_RET_ERR_RC_JOBS_NOT_UPDATED);
            }
            break;
        case DSPHD_MSG_UPDATE_LONG_JOB_LIST:
            if(gP5JobListUpdateFlag == false)
            {
                gP5JobListUpdateFlag = true;
                pP5RawJobList = (JobList_t*)gRsdkDspHDMsg.payload;
            }
            else
            {
                SetDspError(RSDK_DSP_RET_ERR_LONG_JOBS_NOT_UPDATED);
            }
            break;

        case DSPHD_MSG_CLEAR_CE_JOB_LIST:
        {
            gP1ParsedJobList.numJobs = 0;
            memset(gP1ParsedJobList.job, 0, sizeof(gP1ParsedJobList.job));
            break;
        }


        case DSPHD_MSG_CLEAR_RC_JOB_LIST:
        {
            gP4ParsedJobList.numJobs = 0;
            memset(gP4ParsedJobList.job, 0, sizeof(gP4ParsedJobList.job));
            break;
        }
        case DSPHD_MSG_CLEAR_LONG_JOB_LIST:
        {
            gP5ParsedJobList.numJobs = 0;
            memset(gP5ParsedJobList.job, 0, sizeof(gP5ParsedJobList.job));
            break;
        }

        case DSPHD_MSG_RUN_ASYNC_JOB:
            {
                pP3RawJobList = (JobList_t*)gRsdkDspHDMsg.payload;

                xosStatus = xos_thread_resume(&P3ThreadTcb);

                if(xosStatus != XOS_OK)
                {
                    SetDspError(RSDK_DSP_RET_ERR_THR_RESUME);
                }
            }
            break;

        // this command forces an ACK to check the Dispatcher is still running
        case DSPHD_MSG_CHECK_DISPATCHER_ALIVE:
            break;

        case DSPHD_MSG_DSP_TRACE_START:
#ifdef TRACE_ENABLE
        {
            //Decided to use RSDK Trace instead of the (very similar) XOS built-in event logging, for few reasons:
            //- to keep compatibility with the rest of RSDK components and demos and allow re-use of the same trace parser for all
            //- to allow allocating the trace buffer from the host application side and passing the pointer + size to the BBE32 at runtime.
            rsdkStatus_t status = RSDK_SUCCESS;
            Dsphd_TraceCfgType* pDspTraceCfg = (Dsphd_TraceCfgType*)gRsdkDspHDMsg.payload;
            status = RsdkTraceInit((char*)pDspTraceCfg->bufAddr , pDspTraceCfg->bufSize);
            if(status != RSDK_SUCCESS)
            {
                SetDspError(RSDK_DSP_RET_ERR_TRACE_START);
            }
            RsdkTraceLogEvent(RSDK_TRACE_EVENT_DBG_INFO, RSDK_TRACE_DBG_DISPATCHER_INIT, dispatcherInitTrace);
            RsdkTraceLogEvent(RSDK_TRACE_EVENT_DBG_INFO, RSDK_TRACE_DBG_DISPATCHER_RUN, dispatcherRunTrace);

        }
#else
            SetDspError(RSDK_DSP_RET_ERR_TRACE_DISABLED);
#endif
            break;
        case DSPHD_MSG_DSP_TRACE_END:
#ifdef TRACE_ENABLE
        {
            extern traceRecord_t gTraceRecord;
            gTraceRecord.enable = false;
        }
#else
            SetDspError(RSDK_DSP_RET_ERR_TRACE_DISABLED);
#endif
            break;
        default:
            SetDspError(RSDK_DSP_RET_ERR_INVALID_PARAM);
            break;
    }

    int32_t retVal = ipc_shm_release_buf(instance, chan_id, buf);
    if (retVal != 0)
    {
        SetDspError(RSDK_DSP_RET_ERR_RELEASE_MSG_BUFF);
        HALT_BBE32;
    }

    //Send ACK to host driver
    ackPacket.commandNumber = gRsdkDspDispatcherMemPer.numArmCmdsReceived;
    ackPacket.commandType = gRsdkDspHDMsg.type;

    char* txBuf = GetShmBuffer(gRsdkDspDispatcherMemPer.commParams.ipcfInstance, gRsdkDspDispatcherMemPer.commParams.ctrlChanId, sizeof(ackPacket));

    if (txBuf != NULL)
    {
        memcpy((void*)txBuf, (void*)&ackPacket, sizeof(ackPacket));

        retVal = ipc_shm_tx(gRsdkDspDispatcherMemPer.commParams.ipcfInstance, gRsdkDspDispatcherMemPer.commParams.ctrlChanId, txBuf, sizeof(ackPacket));
        if (retVal != 0)
        {
            SetDspError(RSDK_DSP_RET_ERR_TX_FAILED);
        }
    }
    else
    {
        SetDspError(RSDK_DSP_RET_ERR_INVALID_MSG_BUFF);
    }
}
static void RcsIsr(void *arg)
{
    UNUSED_ARG(arg);

    int32_t xosStatus;

    RsdkTraceLogEvent(RSDK_TRACE_EVENT_DBG_INFO, RSDK_TRACE_DBG_DSP_RCS_ISR, 0u);

    *(gRsdkDspDispatcherMemPer.runtimeConfig.pDispatcherState) = DSPHD_DISP_STATE_RUNNING;

    if(gRsdkDspDispatcherMemPer.runtimeConfig.p1TaskConfig == DSPHD_CFG_P1_TASK_PREEMPT)
    {
        xosStatus = xos_thread_resume(&P1ThreadTcb);
        if(xosStatus != XOS_OK)
        {
            SetDspError(RSDK_DSP_RET_ERR_THR_RESUME);
        }
    }
}

static void RfsIsr(void *arg)
{
    UNUSED_ARG(arg);

    int32_t xosStatus;

    BBX_SCRLU((int32_t)0xE0000000U, ADDR_DSP_DEBUG2_REG);



    RsdkTraceLogEvent(RSDK_TRACE_EVENT_DBG_INFO, RSDK_TRACE_DBG_DSP_RFS_ISR, 0u);

    *(gRsdkDspDispatcherMemPer.runtimeConfig.pDispatcherState) = DSPHD_DISP_STATE_RUNNING;
    gRsdkDspDispatcherMemPer.numRadarCycles++;

    if(gRsdkDspDispatcherMemPer.runtimeConfig.p1TaskConfig == DSPHD_CFG_P1_TASK_NON_PREEMPT)
    {
        DisableAllInterruptsForP1NonPreempt();
        xosStatus = xos_thread_resume(&P1ThreadTcb);

        if(xosStatus != XOS_OK)
        {
            SetDspError(RSDK_DSP_RET_ERR_THR_RESUME);
        }
    }

    xosStatus = xos_thread_resume(&P4ThreadTcb);
    if(xosStatus != XOS_OK)
    {
        SetDspError(RSDK_DSP_RET_ERR_THR_RESUME);
    }

}


rsdkStatus_t ConfigureInterrupts(uint16_t sptEvtIntEnBitmap, rsdkDspIsrCb_t sptEvtIsrCb)
{

    uint32_t i, evtID;

    int32_t xosStatus;
    rsdkStatus_t ret = RSDK_SUCCESS;


    BBX_SCRLU((int32_t)0x1001, ADDR_DSP_DEBUG2_REG);  //debug write to a SPT control register (DSP_DEBUG2_REG - offset 0xA8):

    //SPT command queue:
    xosStatus = xos_register_interrupt_handler(XCHAL_EXTINT0_NUM, &SptCmdQIsr, NULL);
    if(xosStatus != XOS_OK)
    {
        ret = RSDK_DSP_RET_ERR_INT_CONFIG;
    }
    else
    {
        xosStatus = xos_interrupt_enable(XCHAL_EXTINT0_NUM);
        if(xosStatus != XOS_OK)
        {
            ret = RSDK_DSP_RET_ERR_INT_ENABLE;
        }
    }

    if(ret == RSDK_SUCCESS)
    {
        //SPT events
        for (i = (uint32_t)XCHAL_EXTINT1_NUM; i <= (uint32_t)XCHAL_EXTINT13_NUM; i++)
        {
            evtID = i-(uint32_t)XCHAL_EXTINT1_NUM;
            if( (sptEvtIntEnBitmap & (uint16_t)((uint16_t)0x0001u << (evtID)) ) != 0u)
            {
                //re-use the same handler for all EVT interrupts, by passing a different parameter for each one, including here the EVT index:
                evtIsrArgList[evtID].cb = sptEvtIsrCb;
                evtIsrArgList[evtID].evtIntID = evtID;

                xosStatus = xos_register_interrupt_handler(i, &SptEvtIsr, &evtIsrArgList[evtID]);
                if(xosStatus != XOS_OK)
                {
                    ret = RSDK_DSP_RET_ERR_INT_CONFIG;
                    break;
                }
                xosStatus = xos_interrupt_enable(i);
                if(xosStatus != XOS_OK)
                {
                    ret = RSDK_DSP_RET_ERR_INT_ENABLE;
                }
            }
            else
            {
                xosStatus = xos_interrupt_disable(i);
                if(xosStatus != XOS_OK)
                {
                    ret = RSDK_DSP_RET_ERR_INT_DISABLE;
                }
            }
        }
    }






    if(ret == RSDK_SUCCESS)
    {
        //ARM core
        xosStatus = xos_register_interrupt_handler(XCHAL_EXTINT_ARM, &ipc_shm_hardirq, NULL);
        if(xosStatus != XOS_OK)
        {
            ret = RSDK_DSP_RET_ERR_INT_CONFIG;
        }
        else
        {
            xosStatus = xos_interrupt_enable(XCHAL_EXTINT_ARM);
            if(xosStatus != XOS_OK)
            {
                ret = RSDK_DSP_RET_ERR_INT_ENABLE;
            }
        }
    }

    if(ret == RSDK_SUCCESS)
    {
        //CSI2 unit 1 VSYNC (frame start)
        xosStatus = xos_register_interrupt_handler(XCHAL_EXTINT_CSI2_VSYNC, &RfsIsr, NULL);
        if(xosStatus != XOS_OK)
        {
            ret = RSDK_DSP_RET_ERR_INT_CONFIG;
        }
        else
        {
            xosStatus = xos_interrupt_enable(XCHAL_EXTINT_CSI2_VSYNC);
            if(xosStatus != XOS_OK)
            {
                ret = RSDK_DSP_RET_ERR_INT_ENABLE;
            }
        }
    }

    if(ret == RSDK_SUCCESS)
    {
        //CSI2 unit 1 LINEDone(chirp end)
        xosStatus = xos_register_interrupt_handler(XCHAL_EXTINT_CSI2_LINE_DONE, &RcsIsr, NULL);
        if(xosStatus != XOS_OK)
        {
            ret = RSDK_DSP_RET_ERR_INT_CONFIG;
        }
        else
        {
            xosStatus = xos_interrupt_enable(XCHAL_EXTINT_CSI2_LINE_DONE);
            if(xosStatus != XOS_OK)
            {
                ret = RSDK_DSP_RET_ERR_INT_ENABLE;
            }
        }
    }


    if(ret == RSDK_SUCCESS)
    {
        //AXI write err:
        xosStatus = xos_register_interrupt_handler(XCHAL_WRITE_ERROR_INTERRUPT, &WriteErrIsr, NULL);
        if(xosStatus != XOS_OK)
        {
            ret = RSDK_DSP_RET_ERR_INT_CONFIG;
        }
        else
        {
            xosStatus = xos_interrupt_enable(XCHAL_WRITE_ERROR_INTERRUPT);
            if(xosStatus != XOS_OK)
            {
                ret = RSDK_DSP_RET_ERR_INT_ENABLE;
            }
        }
    }

    BBX_SCRLU((int32_t)0x1002, ADDR_DSP_DEBUG2_REG);



    return ret;
}

/*================================================================================================*/

#ifdef __cplusplus
}
#endif

/*******************************************************************************
 * EOF
 ******************************************************************************/
