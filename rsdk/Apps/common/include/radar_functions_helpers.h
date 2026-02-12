/**************************************************************************************************
*
* NXP Confidential Proprietary
*
* Copyright 2023-2024 NXP
* All Rights Reserved
*
*****************************************************************************
*
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
*
**************************************************************************************************/

#ifndef RADAR_FUNCTIONS_HELPERS_H
#define RADAR_FUNCTIONS_HELPERS_H

/**
* @file           LAX_trigger_common.h
* @implements     Common definitions for all modules (main_app, LAX, CTE) for demo application.
*/


#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "app_mem_mgr.h"
#include "app_cond_flag.h"
#if defined(TRACE_ENABLE)
#include "trace.h"
#endif

#include "rsdk_spt_kernels.h"

#include "rsdk_status.h"

#include "CDD_Spt.h"

#include "interrupts_cm7.h"

#include "Spt_Irq.h"
#include "Spt_PBcfg.h"
#if (SPT_DSP_ENABLE == STD_ON)
#define DSP_ENABLE
#endif






#if ((defined(S32R45) || defined(S32R41) || defined(SAF85XX) || defined(SAF86XX)) && defined(DSP_ENABLE))

#include "CDD_Dsphd.h"


#include "rsdk_dsp_lal_vector_add.h"



#include "rsdk_dsp_radar_bb_algos.h"
#include "rsdk_dsp_dispatcher_func_list_host.h"
#endif




/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define MAX_ERROR_COUNT 10U // max isr errors
#define RSDK_APP_MAX_NR_DETECTS       (32)


#define SPT_EVT1_MSB (0x8000u)
#define ENDIAN_CHANGE "word16"

#define SPT_EVT1_LSB (0x1u)

#if ((defined(S32R41) || defined(SAF85XX) || defined(SAF86XX)) && defined(DSP_ENABLE))
#define TRACE_LOG_NR_ENTRIES_DSP 2100 /* Maximum number of events that can be saved in the trace buffer for the DSP */
#define TRACE_BUF_SIZE_DSP (TRACE_LOG_NR_ENTRIES_DSP * RSDK_TRACE_LOG_ENTRY_SIZE)
#endif


















#define FILE_IN_PATH "../../data/in/S32R41/"
#define FILE_OUT_PATH "../../data/out/S32R41/"









#define SPT_OP_MODE SPT_OP_MODE_NONBLOCK
#define DSPHD_JOB_LIST_CRC_EN  0x1u
#define DSPHD_JOB_LIST_CRC_DIS 0x0u

#define CHECK_KERNEL_WATERMARK 1U
#define DATA_BUFF_IS_CACHED (true)










#ifndef TRUE
#define TRUE ((uint8_t)1)
#endif
#ifndef FALSE
#define FALSE ((uint8_t)0)
#endif

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
extern int				  	bufOvf;
extern rsdkStatus_t      	isrStatusQueue[MAX_ERROR_COUNT];
extern uint32_t          	errInfoQueue[MAX_ERROR_COUNT];
extern uint8_t           	currentError;

extern Dsphd_JobType 		dspJobsList[];
extern volatile Dsphd_DispatcherStateType dispatcherState;


extern rsdkAppCondFlag_t 	sptDoneFlag;
extern rsdkAppCondFlag_t 	bbe32AsyncDone;
extern rsdkBufHandle_t 		gSdadcSampleBufferBufH;
extern char            		fileName[];
extern rsdkAppMemMgr_t 		pHeapMem;
extern uint16_t 			gNrDetects;

#if (defined(S32R41) || defined(SAF85XX) || defined(SAF86XX)) && defined(DSP_ENABLE)
extern uint8_t				gDspRcJobListBuf[];
extern Dsphd_RuntimeCfgType dspRuntimeCfg;
#if defined(TRACE_ENABLE)
extern uint8_t				gTraceBufferDsp[TRACE_BUF_SIZE_DSP];
extern Dsphd_TraceCfgType 	dspTraceCfg;
#endif
#endif






/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

__attribute__((weak)) void Csi2_IrqHandlerEvents0(void);
__attribute__((weak)) void Csi2_IrqHandlerPathErr0(void);
__attribute__((weak)) void Csi2_IrqHandlerRxErr0(void);

void ExampleLaunchSptKernel(Spt_DriverContextType const *const pSptContext);
void Spt_EcsIsrCb(rsdkStatus_t isrStatus, uint32_t errInfo);
__attribute__((weak)) void Spt_EvtIsrCb(rsdkStatus_t isr_status, uint32_t evtInfo);
void WaitForSPT(Spt_DriverOpModeType opMode);
void Spt_DspBootloaderCb(void);

#if defined(DSP_ENABLE)
void AppChangeDspRuntimeConfig(uint16_t numberOfChirps, uint32_t p1TaskConfig, uint32_t fpuRoundConfig, uint8_t reportFPUExceptions);
void AppCheckDspResponsiveness(void);
void AppRunDspAsyncJob(uint8_t* pJobListBuf, uint32_t phyAddr, uint16_t kernelName);
void AppUpdateDspJobList(uint8_t* pJobListBuf,  Dsphd_JobType* pDspJobsList, uint16_t numJobs);
#if defined(TRACE_ENABLE)
void AppStartDspTrace(void);
void AppStopDspTrace(void);
#endif
#endif








#if defined(DSP_ENABLE)
void DspBootloader(void);





void Spt_DspIsrCb(rsdkStatus_t isrStatus, uint32_t errInfo);

#endif
void statusCheck(const char *funcName, int status);
void AppInitDsphd(void);

void RelocSptCode(void* runAddr, void* loadAddr, size_t codeSize);
void ExampleInitSPTDriver(void);
void MergeDetects(uint32_t *psBuff, uint32_t *cfarBuff,  uint16_t nrRangeBins, uint16_t nrDopplerBins, uint32_t *peakIndex);

Std_ReturnType extractPeakData(uint16_t nrPeaksRDM, uint32_t *rdmPeakIndex, uint32_t *radarCube, uint32_t *peakAntennaData, uint16_t nrAnt);





#ifdef __cplusplus
}
#endif

#endif /* RADAR_FUNCTIONS_HELPERS_H */
