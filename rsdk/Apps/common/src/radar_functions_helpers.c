/*************************************************************************************************
 *
 * NXP Confidential Proprietary
 *
 * Copyright 2023-2024 NXP
 * All Rights Reserved
 *
 ******************************************************************************
 *
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 *
 *************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/*=================================================================================================
 *                                        INCLUDE FILES
=================================================================================================*/
#include <stdio.h>
#if defined(STDIO)
#include <stdlib.h>
#endif
#include <string.h>

#include "debug_tools.h"
#include "cache.h"
#include "radar_functions_helpers.h"
#include "app_cond_flag.h"
#if defined(PROFILE_ENABLE)
#include "trace.h"
#endif


#include "CDD_Spt.h"
#include "Spt_Irq.h"
#include "Spt_PBcfg.h"


#include "interrupts_cm7.h"

#include "ipcf_Ip_Cfg.h"






#if ((defined(S32R45) || defined(S32R41) || defined(SAF85XX) || defined(SAF86XX)) && defined(DSP_ENABLE))

#include "CDD_Dsphd.h"
#include "dsp_jobs.h"

#if defined(BBE32_DEBUG)



#include "dsp_image_S32R41_debug.c"









#else



#include "dsp_image_S32R41_release.c"











#endif
#endif
#if defined(PROFILE_ENABLE)



#endif

/*=================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
=================================================================================================*/

/*=================================================================================================
 *                                       LOCAL MACROS
=================================================================================================*/

/*=================================================================================================
 *                                      LOCAL CONSTANTS
=================================================================================================*/

/*=================================================================================================
 *                                      LOCAL VARIABLES
=================================================================================================*/

/*=================================================================================================
 *                                      GLOBAL CONSTANTS
=================================================================================================*/

/*=================================================================================================
 *                                      GLOBAL VARIABLES
=================================================================================================*/
int				  			bufOvf = 0;
rsdkStatus_t      			isrStatusQueue[MAX_ERROR_COUNT];
uint32_t          			errInfoQueue[MAX_ERROR_COUNT];
uint8_t           			currentError = 0;

Dsphd_JobType               dspJobsList[RSDK_DSPHD_MAX_JOB_LIST_SIZE];//TODO: add RSDK_DSPHD_MAX_JOB_LIST_SIZE to DSPHD API
volatile Dsphd_DispatcherStateType dispatcherState __attribute__((section(".mcal_shared_bss"))); //place it in some non-cacheable section








/*=================================================================================================
 *                                   LOCAL FUNCTION PROTOTYPES
=================================================================================================*/

/*=================================================================================================
 *                                   LOCAL & GLOBAL FUNCTIONS
=================================================================================================*/
#if (defined(S32R41) || defined(SAF85XX) || defined(SAF86XX)) && defined(DSP_ENABLE)
void AppCheckDspResponsiveness()
{
	rsdkStatus_t status = RSDK_SUCCESS;
#if defined(PROFILE_ENABLE)
    RsdkTraceLogEvent(RSDK_TRACE_EVENT_FUNC_START, (uint16)RSDK_TRACE_JOB_APP_PROFILE_DSPHD_SENDMSG, 0u);
#endif
	status = Dsphd_SendMsg(DSPHD_MSG_CHECK_DISPATCHER_ALIVE, 0);
#if defined(PROFILE_ENABLE)
    RsdkTraceLogEvent(RSDK_TRACE_EVENT_FUNC_END, (uint16)RSDK_TRACE_JOB_APP_PROFILE_DSPHD_SENDMSG, 0u);
#endif
    statusCheck("RsdkDspHDSendMsg", status);
}

void AppChangeDspRuntimeConfig(uint16_t numberOfChirps, uint32_t p1TaskConfig, uint32_t fpuRoundConfig, uint8_t reportFPUExceptions)
{
	rsdkStatus_t status = RSDK_SUCCESS;

	dspRuntimeCfg.numberOfChirps = numberOfChirps;
	dspRuntimeCfg.p1TaskConfig = p1TaskConfig;
	dspRuntimeCfg.fpuRoundConfig = fpuRoundConfig;
	dspRuntimeCfg.reportFPUExceptions = reportFPUExceptions;

	dspRuntimeCfg.pDispatcherState = &dispatcherState;


    CacheFlush((const char *)&dspRuntimeCfg, sizeof(dspRuntimeCfg));
#if defined(PROFILE_ENABLE)
    RsdkTraceLogEvent(RSDK_TRACE_EVENT_FUNC_START, (uint16)RSDK_TRACE_JOB_APP_PROFILE_DSPHD_SENDMSG, 0u);
#endif
	status = Dsphd_SendMsg(DSPHD_MSG_UPDATE_DISPATCHER_CONFIG, (uintptr_t)&dspRuntimeCfg);
#if defined(PROFILE_ENABLE)
    RsdkTraceLogEvent(RSDK_TRACE_EVENT_FUNC_END, (uint16)RSDK_TRACE_JOB_APP_PROFILE_DSPHD_SENDMSG, 0u);
#endif

	statusCheck("RsdkDspHDSendMsg", status);
}

//==========================================================
// Running the DSP job list in async mode
// Input  : pointer to the job list
//==========================================================
void AppRunDspAsyncJob(uint8_t* pJobListBuf, uint32_t phyAddr, uint16_t kernelName)
{
    rsdkStatus_t        status = RSDK_SUCCESS;
	Dsphd_JobType job;

	job.id = kernelName;
	job.arg = phyAddr;
#if defined(PROFILE_ENABLE)
    RsdkTraceLogEvent(RSDK_TRACE_EVENT_FUNC_START, (uint16)RSDK_TRACE_JOB_APP_PROFILE_DSPHD_CREATEJOBLIST, 0u);
#endif
	status = Dsphd_CreateJobList(&job, pJobListBuf, 1u, DSPHD_JOB_LIST_CRC_EN);
#if defined(PROFILE_ENABLE)
    RsdkTraceLogEvent(RSDK_TRACE_EVENT_FUNC_END, (uint16)RSDK_TRACE_JOB_APP_PROFILE_DSPHD_CREATEJOBLIST, 0u);
#endif
	if(status == RSDK_SUCCESS)
	{
	    CacheFlush((const char *)pJobListBuf, DSPHD_SIZEOF_JOB_LIST);
	}
	statusCheck("RsdkDspHDCreateJobList", status);
	DbgPrintMsg("ARM->BBE32 sending msg: RSDK_DSPHD_MSG_RUN_ASYNC_JOB.\n");
	status = Dsphd_SendMsg(DSPHD_MSG_RUN_ASYNC_JOB, (uintptr_t)pJobListBuf);
    statusCheck("RsdkDspHDSendMsg", status);
	DbgPrintMsg("ARM->BBE32 msg sent: DSPHD_MSG_RUN_ASYNC_JOB.\n");

	// wait for DSP to finish
	AppCondFlagWait(&bbe32AsyncDone);
	DbgPrintMsg("BBE32->ARM : RSDK_DSPHD_MSG_RUN_ASYNC_JOB done.\n");

}


// For example interference mitigation
void AppUpdateDspJobList(uint8_t* pJobListBuf, Dsphd_JobType* pDspJobsList, uint16_t numJobs)
{
	rsdkStatus_t status = RSDK_SUCCESS;

#if defined(PROFILE_ENABLE)
    RsdkTraceLogEvent(RSDK_TRACE_EVENT_FUNC_START, (uint16)RSDK_TRACE_JOB_APP_PROFILE_DSPHD_CREATEJOBLIST, 0u);
#endif
	status = Dsphd_CreateJobList(pDspJobsList, pJobListBuf, numJobs, DSPHD_JOB_LIST_CRC_EN);
#if defined(PROFILE_ENABLE)
    RsdkTraceLogEvent(RSDK_TRACE_EVENT_FUNC_END, (uint16)RSDK_TRACE_JOB_APP_PROFILE_DSPHD_CREATEJOBLIST, 0u);
#endif
	if (status == RSDK_SUCCESS)
	{
	    CacheFlush((const char *)pJobListBuf, DSPHD_SIZEOF_JOB_LIST);
	}
	statusCheck("RsdkDspHDCreateJobList", status);
#if defined(PROFILE_ENABLE)
    RsdkTraceLogEvent(RSDK_TRACE_EVENT_FUNC_START, (uint16)RSDK_TRACE_JOB_APP_PROFILE_DSPHD_SENDMSG, 0u);
#endif
	status = Dsphd_SendMsg(DSPHD_MSG_UPDATE_CE_JOB_LIST, (uintptr_t)pJobListBuf);
#if defined(PROFILE_ENABLE)
    RsdkTraceLogEvent(RSDK_TRACE_EVENT_FUNC_END, (uint16)RSDK_TRACE_JOB_APP_PROFILE_DSPHD_SENDMSG, 0u);
#endif
    statusCheck("RsdkDspHDSendMsg", status);


}

//==========================================================
#if defined(TRACE_ENABLE)
void AppStartDspTrace()
{
    rsdkStatus_t        status = RSDK_SUCCESS;

    dspTraceCfg.bufAddr = (uint32_t)(uintptr_t)gTraceBufferDsp;
    dspTraceCfg.bufSize = sizeof(gTraceBufferDsp);

	CacheFlush(&dspTraceCfg, sizeof(dspTraceCfg));
#if defined(PROFILE_ENABLE)
    RsdkTraceLogEvent(RSDK_TRACE_EVENT_FUNC_START, (uint16)RSDK_TRACE_JOB_APP_PROFILE_DSPHD_SENDMSG, 0u);
#endif
	status = Dsphd_SendMsg(DSPHD_MSG_DSP_TRACE_START, (uintptr_t)&dspTraceCfg);
#if defined(PROFILE_ENABLE)
    RsdkTraceLogEvent(RSDK_TRACE_EVENT_FUNC_END, (uint16)RSDK_TRACE_JOB_APP_PROFILE_DSPHD_SENDMSG, 0u);
#endif
    statusCheck("RsdkDspHDSendMsg", status);

}

void AppStopDspTrace()
{
    uint8_t traceFileNameDsp[] = "RsdkTraceDumpDsp.hex";

    rsdkStatus_t        status = RSDK_SUCCESS;

#if defined(PROFILE_ENABLE)
    RsdkTraceLogEvent(RSDK_TRACE_EVENT_FUNC_START, (uint16)RSDK_TRACE_JOB_APP_PROFILE_DSPHD_SENDMSG, 0u);
#endif
	status = Dsphd_SendMsg(DSPHD_MSG_DSP_TRACE_END, 0U);
#if defined(PROFILE_ENABLE)
    RsdkTraceLogEvent(RSDK_TRACE_EVENT_FUNC_END, (uint16)RSDK_TRACE_JOB_APP_PROFILE_DSPHD_SENDMSG, 0u);
#endif
    statusCheck("RsdkDspHDSendMsg", status);

	CacheInvalidate(gTraceBufferDsp, sizeof(gTraceBufferDsp));
	DbgWriteFile(traceFileNameDsp, gTraceBufferDsp, sizeof(gTraceBufferDsp));
}
#endif //TRACE_ENABLE
#endif

//==========================================================
// DSP HD initialization and example commands
//==========================================================
#if ((defined(S32R41) || defined(SAF85XX) || defined(SAF86XX)) && defined(DSP_ENABLE))
void AppInitDsphd(void)
{
    rsdkStatus_t        status = RSDK_SUCCESS;








#if defined(PROFILE_ENABLE)
    RsdkTraceLogEvent(RSDK_TRACE_EVENT_FUNC_START, (uint16)RSDK_TRACE_JOB_APP_PROFILE_DSPHD_INIT, 0u);
#endif




#ifndef IPCF_INITIALIZED
    status = Dsphd_Init();
#endif

    #if defined(PROFILE_ENABLE)
    RsdkTraceLogEvent(RSDK_TRACE_EVENT_FUNC_END, (uint16)RSDK_TRACE_JOB_APP_PROFILE_DSPHD_INIT, 0u);
#endif
    statusCheck("Dsphd_Init", status);
    DbgPrintMsg("Dsphd_Init done.\n");

    AppCheckDspResponsiveness();
    DbgPrintMsg("ARM->BBE32 msg sent: DSPHD_MSG_CHECK_DISPATCHER_ALIVE.\n");
#if defined(TRACE_ENABLE)
    AppStartDspTrace();
#endif

    AppCondFlagInit(&bbe32AsyncDone);
}
#endif


//==========================================================
// SPT driver initialization
//==========================================================
void ExampleInitSPTDriver(void)
{
    rsdkStatus_t        status = RSDK_SUCCESS;



    //SPT initialization:


























    DbgPrintMsg("Initializing SPT Driver \n");
#if defined(PROFILE_ENABLE)
    RsdkTraceLogEvent(RSDK_TRACE_EVENT_FUNC_START, (uint16)RSDK_TRACE_JOB_APP_PROFILE_SPT_SETUP, 0u);
#endif

    status = Spt_Setup(&sptInitInfo);



#if defined(PROFILE_ENABLE)
    RsdkTraceLogEvent(RSDK_TRACE_EVENT_FUNC_END, (uint16)RSDK_TRACE_JOB_APP_PROFILE_SPT_SETUP, 0u);
#endif
    statusCheck("RsdkSptInit", status);
    DbgPrintMsg("RsdkSptInit done.\n");

    // Init sptDoneFlag
    AppCondFlagInit(&sptDoneFlag);
}

//==========================================================
// Execution launch for an SPT kernel
// Input  : pointer to the SPT context
//==========================================================

void ExampleLaunchSptKernel(Spt_DriverContextType const *const pSptContext)



{
    rsdkStatus_t sptStatus;

    currentError = 0;
    bufOvf = 0;

    // start SPT execution; all necessary setup was done before
#if defined(PROFILE_ENABLE)
    RsdkTraceLogEvent(RSDK_TRACE_EVENT_FUNC_START, (uint16)RSDK_TRACE_JOB_APP_PROFILE_SPT_RUN, 0u);
#endif

    sptStatus = Spt_Run(pSptContext);



#if defined(PROFILE_ENABLE)
    RsdkTraceLogEvent(RSDK_TRACE_EVENT_FUNC_END, (uint16)RSDK_TRACE_JOB_APP_PROFILE_SPT_RUN, 0u);
#endif
    if (sptStatus != RSDK_SUCCESS)
    {
        DbgPrintMsg("RsdkSptRun error!, status: %d\n", sptStatus);

        //an error was reported, so we need to reinitialize the Driver
        ExampleInitSPTDriver();
        DbgPrintMsg("Re-initialized SPT driver \n");
    }
    else
    {
        // SUCCESS reported for execution start
        WaitForSPT(pSptContext->opMode);                // wait for execution to finish

        // dump the reported errors, after the execution was finished

        for (int i = 0; i < currentError; i++)
        {
            DbgPrintMsg("SptEcsIsrCb error!, Status: 0x%X, Error info: 0x%X\n", isrStatusQueue[i],
                    (unsigned int)errInfoQueue[i]);
        }
        DbgPrintMsg("RsdkSptRun done. SPT processing done. Ready for next kernel.\n");
        if (pSptContext->kernelRetPar != NULL)
        {
            DbgPrintMsg("Kernel return param: 0x%X\n", (unsigned int)*pSptContext->kernelRetPar);
        }


    }
}


Std_ReturnType extractPeakData(uint16_t nrPeaksRDM, uint32_t *rdmPeakIndex, uint32_t *radarCube,
		uint32_t *peakAntennaData, uint16_t nrAnt)




{
    uint32_t   i;

    volatile   uint32_t *pGroup0;
    uint32_t   packSize, packSamples;
    uint32_t   rdPeakIndex, antDatIndex;

     if ((radarCube == NULL) || (peakAntennaData == NULL) || (rdmPeakIndex == NULL))
    {
        return RSDK_INVALID_PARAMETER;
    }
    else
    {
    	/* Antenna data is stored in a packed form ABCD... */
    	packSamples = nrAnt; /// gAppConfig.specific.cpRate;   -  hardcoded for no compression
    	packSize = packSamples * sizeof(radarCube[0]);

    	pGroup0 = &radarCube[0];

    	for (i = 0; i < nrPeaksRDM; i++)
    	{
    		/* Index of peak in radar cube*/
    		rdPeakIndex = rdmPeakIndex[i] * packSamples;
    		antDatIndex = packSamples * i;

    		memcpy((void *)&peakAntennaData[antDatIndex], (void *)&pGroup0[rdPeakIndex], packSize);
    	}
        return RSDK_SUCCESS;
    }
}

//==========================================================
// MergeDetects function - merge SPT peak search detects with CFAR detects; function is equivalent to a logical AND between the two detection(tag) bitmaps.
// Function is not optimized; it is also meant for better understanding of memory arrangement of SPT and DSP detection algos output.
// Memory layout example is shown for default RSDK use-case 512 chirps, 128 samples -> 256 Range bins, 128 Doppler bins
// Input:
//    - psBuff: PeakSearch output bitmap (from SPT) in a packed format - one bit per detect/tag. Array size = (nrRangeBins*nrDopplerBins/8) bytes
//			OBS - peak tag indexing is equivalent to transposed RDM
//              - in SPT internal memory, tag packing is done into 32 bit words in BIG ENDIAN (check SPT Peak search kernel API)
//              - SPT output to SRAM is word16 endianess reversed which results in following:
//
//                                Memory layout SRAM
//           Byte  |    N    | |   N+1   | |   N+2   | |   N+3   | __
//           0x00  R023...R016 R031...R024 R007...R000 R015...R008   |
//           0x04  R055...R048 R063...R056 R039...R032 R047...R040	 |
//                 |  ....   | |  ....   | |   ....  | |  ....   |   |  -> Doppler bin 0
//                 |  ....   | |  ....   | |   ....  | |  ....   |   |
//           0x1C  R247...R240 R255...R248 R231...R224 R239...R232 __|
//																   __
//           0x20  R023...R016 R031...R024 R007...R000 R015...R008   |
//           0x24  R055...R048 R063...R056 R039...R032 R047...R040   |
//                 |  ....   | |  ....   | |   ....  | |  ....   |   |  -> Doppler bin 1
//                 |  ....   | |  ....   | |   ....  | |  ....   |   |
//           0x3C  R247...R240 R255...R248 R231...R224 R239...R232 __|
//
//                 |  ....   | |  ....   | |   ....  | |  ....   |            ...
//                 |  ....   | |  ....   | |   ....  | |  ....   |            ...
//                 |  ....   | |  ....   | |   ....  | |  ....   |            ...
//                                                                 __
//          0xFE0  R023...R016 R031...R024 R007...R000 R015...R008   |
//          0xFE4  R055...R048 R063...R056 R039...R032 R047...R040   |
//                 |  ....   | |  ....   | |   ....  | |  ....   |   |  -> Doppler bin 127
//                 |  ....   | |  ....   | |   ....  | |  ....   |   |
//          0xFFC  R247...R240 R255...R248 R231...R224 R239...R232 __|
//
//    - cfarBuff:  CFAR output bitmap (from BBE) in a packed format - one bit per detect/tag. Array size = (nrRangeBins*nrDopplerBins/8) bytes
//          OBS - peak tag indexing is equivalent to RDM
//              - tag packing is done into 32 bit words
//
//                                Memory layout SRAM
//           Byte  |    N    | |   N+1   | |   N+2   | |   N+3   | __
//           0x00  D007...D000 D015...D008 D023...D016 D031...D024   |
//           0x04  D039...D032 D047...D040 D055...D048 D063...D056   |  -> Range bin 0
//                 |  ....   | |  ....   | |   ....  | |  ....   |   |
//           0x0C  D103...D096 D111...D104 D119...D112 D127...D120 __|
//                                                                 __
//           0x10  D007...D000 D015...D008 D023...D016 D031...D024   |
//           0x14  D039...D032 D047...D040 D055...D048 D063...D056   |  -> Range bin 1
//                 |  ....   | |  ....   | |   ....  | |  ....   |   |
//           0x1C  D103...D096 D111...D104 D119...D112 D127...D120 __|
//
//                 |  ....   | |  ....   | |   ....  | |  ....   |            ...
//                 |  ....   | |  ....   | |   ....  | |  ....   |            ...
//                 |  ....   | |  ....   | |   ....  | |  ....   |            ...
//                                                                 __
//          0xFF0  D007...D000 D015...D008 D023...D016 D031...D024   |
//          0xFF4  D039...D032 D047...D040 D055...D048 D063...D056   |  -> Range bin 255
//                 |  ....   | |  ....   | |   ....  | |  ....   |   |
//          0xFFC  D103...D096 D111...D104 D119...D112 D127...D120 __|
//    - nrRangeBins
//    - nrDopplerBins
//  Output:
//         detIndex - array of detects indexes in RDM
//==========================================================
void MergeDetects(uint32_t *psBuff, uint32_t *cfarBuff,  uint16_t nrRangeBins, uint16_t nrDopplerBins, uint32_t *detIndex)
{
    uint16_t rInd,dInd;
    uint32_t psInd,cfInd,psBitInd,cfBitInd,psIndPack, cfIndPack,psDet,cfDet;
    uint32_t sptPsPack;
    uint32_t nrBitsPack = 32;

    gNrDetects = 0;

    for(rInd = 0; rInd<nrRangeBins; rInd++)
    {
        for (dInd = 0; dInd<nrDopplerBins; dInd++)
        {
        	psInd     = dInd * nrRangeBins + rInd;      /* Get index in SPT bitmap */
        	psIndPack = psInd/nrBitsPack;               /*  Pack Number  */
        	psBitInd  = psInd - (psIndPack*nrBitsPack); /*  Bit number in pack*/
        	sptPsPack = psBuff[psIndPack];
        	sptPsPack = ((sptPsPack & 0xffff0000) >> 16 ) | ((sptPsPack & 0x0000ffff) << 16);   /* Rearrange pack to get tag bits in order*/
        	psDet     = (sptPsPack)& (1<<psBitInd);

            cfInd     = rInd * nrDopplerBins + dInd;         /* Get index in DSP bitmap*/
            cfIndPack = cfInd/nrBitsPack;                    /*  Pack Number  */
            cfBitInd  = cfInd - (cfIndPack*nrBitsPack);      /*  Bit number in pack*/
            cfDet     = cfarBuff[cfIndPack] & (1<<cfBitInd); /* No need for rearranging, */

            if (psDet && cfDet && (gNrDetects < RSDK_APP_MAX_NR_DETECTS))  /*  Guard number of detects to MAX to avoid buffer overflows*/
            {
            	detIndex[gNrDetects] = cfInd;  /* Save detect/tag index in RDM*/
                gNrDetects++;
            }
        }
    }
}

//==========================================================
// SPT execution callback
// Input  : interrupt status and errors
//==========================================================

void Spt_EcsIsrCb(rsdkStatus_t isrStatus, uint32_t errInfo)



{
    static uint32_t ecsIntNum = 0;

    ecsIntNum++;

    if (isrStatus == RSDK_SUCCESS)
    {
        // signal to the application the SPT execution finished
        AppCondFlagSignal(&sptDoneFlag);
    }
    else
    {
    	if( isrStatus == RSDK_SPT_RET_WARN_UNEXPECTED_STOP)
    	{
    		AppCondFlagSignal(&sptDoneFlag);
    	}

        // manage the received errors
    	if(currentError < MAX_ERROR_COUNT)
		{
			isrStatusQueue[currentError] = isrStatus;
			errInfoQueue[currentError] = (unsigned int)errInfo;
			currentError++;
		}
		else if (bufOvf == 0)
		{
			DbgPrintMsg("SPT Error queue overflow! Only the first %d errors are reported. Check last executed kernel!\n", MAX_ERROR_COUNT);
			bufOvf = 1;
		}
    }
}

//==========================================================
/** This is the SPT Event interrupt handler, used by the CPU to emulate signal acquisition on each chirp, when the application
 * runs on a hardware setup which has no actual Radar front-end connected.
 * It uses the SPT interrupt triggered by the 'evt' instrution to synchronize the CPU core with the SPT Range FFT kernel and update the
 * input buffer with samples read from data file on the PC.
 */
//==========================================================

__attribute__((weak)) void Spt_EvtIsrCb(rsdkStatus_t isr_status, uint32_t evtInfo)



{
    extern int             evtIntNum;
    int                    offsetADCData; //offset of the first chirp (of the two chirps) in the input file
    int                    offsetADCDataNextChirp; //offset in the input file for the second chirp
    int                    numBytesADCChirp; //bytes for one chirp in the ADC buffer
    int                    numBytesRangeInputChirp; //bytes for one chirp in the Range FFT input, including MIPI/CSI2 statistics

    Spt_DriverCmdResType   sptCmdResult;
    Spt_DriverCommandType  sptCmd = {SPT_CMD_TRIGGER_SW_EVENT, 0x0};




    rsdkStatus_t           sptStatus = RSDK_SUCCESS;

    //once every 2 chirps read next 'buffer' from input data file
    switch (evtInfo)
    {
        case SPT_EVT1_MSB:
            //we received an event from SPT on MSB line and we are using it to feed the next 2 chirps' worth of data
            //in the acquisition buffer
            if (evtIntNum % 2 == 0)
            {
              /* SPT Range FFT kernels have been adapted to consider MIPI/CSI2 statistics. The input file contains only ADC data and space needs to be
               * reserved for MIPI/CSI2 statistics after each chirp before running the range kernel.
               * RSDK_SPT_RANGE512_4CH_IN_BUF_SIZE includes the MIPI/CSI2 statistics size for 2 chirps. */
            	numBytesADCChirp = RSDK_SPT_RANGE512_4CH_IN_BUF_SIZE/2 * sizeof(int16_t) - RSDK_BYTES_CSI2_STATS;
            	offsetADCData = evtIntNum / 2 * (2*numBytesADCChirp);
            	offsetADCDataNextChirp = offsetADCData + numBytesADCChirp;
            	numBytesRangeInputChirp = RSDK_SPT_RANGE512_4CH_IN_BUF_SIZE/2 * sizeof(int16_t);

                DbgPrintMsg("SPT EVT interrupt number: %d. Sample buffer update from offset: %d\n", evtIntNum, offsetADCData);

                sprintf(fileName, "%s%s", FILE_IN_PATH, "rfft_in.dat");
                // make room for RSDK_BYTES_CSI2_STATS after each chirp in the gSdadcSampleBufferBufH
                DbgReadFileConvert(fileName, offsetADCData, (char *)gSdadcSampleBufferBufH.virtAddr, numBytesADCChirp, ENDIAN_CHANGE, DATA_BUFF_IS_CACHED);
                DbgReadFileConvert(fileName, offsetADCDataNextChirp, (char *)gSdadcSampleBufferBufH.virtAddr + numBytesRangeInputChirp, numBytesADCChirp, ENDIAN_CHANGE, DATA_BUFF_IS_CACHED);

            }
            evtIntNum++;

            //send back event to unblock the SPT from the 'WAIT' instruction:

            sptCmd.cmdId = SPT_CMD_TRIGGER_SW_EVENT;



            sptCmd.cmdParam = SPT_EVT1_MSB;


            sptStatus = Spt_Command(&sptCmd, &sptCmdResult);













            statusCheck("RsdkSptCommand", sptStatus);
            break;

        case SPT_EVT1_LSB:
            //workaround for errata ERR010997: in case the SPT kernel returns a value in WR0, the CPU is only allowed to read WR0 before the STOP instruction
            //and this can only be done using an EVT/WAIT handshake with the SPT kernel right before STOP. In this case the EVT interrupt in the Driver saves
            //WR0 in rsdkSptDriverContext_t.kernelRetPar, but the leaves it to the rsdkSptDriverContext_t.evtIsrCb function to unblock the kernel from its WAIT.
            //This gives the user freedom of choosing the event line to use for this handshake.

            //send back event to unblock the SPT from the 'WAIT' instruction:

        	sptCmd.cmdId = SPT_CMD_TRIGGER_SW_EVENT;




            sptCmd.cmdParam = SPT_EVT1_LSB;


            sptStatus = Spt_Command(&sptCmd, &sptCmdResult);













            statusCheck("RsdkSptCommand", sptStatus);
            break;

        default:
            break;
    }
}



//==========================================================
// Conditional wait for SPT execution finish
// Only for non-blocking operation.
// The function returns only if SPT signals execution end
// Input  : the SPT operation mode
//==========================================================

void WaitForSPT(Spt_DriverOpModeType opMode)
{
    if (opMode == SPT_OP_MODE_NONBLOCK)
    {






        AppCondFlagWait(&sptDoneFlag);

        if(isrStatusQueue[currentError]==RSDK_SPT_RET_WARN_UNEXPECTED_STOP)
        {
        	statusCheck("Wait for SPT ",isrStatusQueue[currentError]);
        }

    }

}

//==========================================================
// Relocate SPT code in memory
// Is not available for all platforms.
// Input  : pointer to the execution address, pointer to the address where the kernel is already loaded, kernel size
//==========================================================
void RelocSptCode(void* runAddr, void* loadAddr, size_t codeSize)
{
//This functions demonstrates that it is possbile to relocate SPT kernel code in memory. This operation is not mandatory.
//Assume that the buffer allocated at runAddr is non-cacheable
    memcpy(runAddr, (void *)loadAddr, codeSize);


    //TODO:make the SPT code buffer non-cacheable after MMU & linker file are configured properly to support
    //non-cacheable data sections. Then we can remove the flush
    CacheFlush(runAddr, codeSize);


}


#if ((defined(S32R45) || defined(S32R41) || defined(SAF85XX) || defined(SAF86XX)) && defined(DSP_ENABLE))
//==========================================================
// DSP callback from SPT interrupt
//==========================================================

__attribute__((weak)) void Csi2_IrqHandlerEvents0(void){}
__attribute__((weak)) void Csi2_IrqHandlerPathErr0(void){}
__attribute__((weak)) void Csi2_IrqHandlerRxErr0(void){}


void Spt_DspIsrCb(rsdkStatus_t isrStatus, uint32_t errInfo)





{
	// In a production app DO NOT use prints or any other operations that take a lot of time. For example here if 2 FP errors come before DbgPrintMsg is done interrupts will be missed.
	if (isrStatus == RSDK_DSP_RET_ERR_FP)
	{
		/* errInfo mapping for FP errors
		 *
		 * Byte1 - Byte 0 (uint16_t)
		 * Byte0 = Func Id
		 * Byte1 = InvalidFlag(bit4) - DivZeroFlag(bit3) - OverflowFlag(bit2) - UnderflowFlag(bit1) - InexactFlag(bit0)
		 */
		uint8_t fpErrType = (uint8_t)((errInfo >> 8) & 0x1f);
		uint8_t fpErrFunc = (uint8_t)errInfo & 0xff;
		uint8_t inexactFlagMask = (uint8_t)0x1;

		if (fpErrType == inexactFlagMask)
		{

			/* Commented out following debug print because it occurs often and it is not an actual error. Causes dual mode to loose real-time.
			 * Improvement: for better error monitoring, replace all prints in ISR with logging */
			//DbgPrintMsg("BBE32 FP Warning Inexact Flag Exception: 0x%X - Func Id: 0x%X\n",  fpErrType, fpErrFunc);
		}
		else
		{
			DbgPrintMsg("BBE32 FP Error! Exceptions: 0x%X - Func Id: 0x%X\n",  fpErrType, fpErrFunc);
		}

	}
	else if (isrStatus == RSDK_DSP_RET_ERR_EXCEPTION)
	{
		DbgPrintMsg("BBE32 Exception! exccause: 0x%X (found in corebits.h)\n", (uint32_t)errInfo);
	}
	else
	{
		DbgPrintMsg("BBE32 Error! Status: 0x%X\n",  isrStatus);
	}
}

#endif

//==========================================================
// Verify the returned status of a function
// If the status is not success, a message is sent to debug console and execution stuck
// Input  : function name to be shown, returned status
//==========================================================
void statusCheck(const char *funcName, int status)
{
    if (status != RSDK_SUCCESS)
    {
        DbgPrintMsg("%s error!, status: %d\n", funcName, status);
        HALT_HERE;
    }
}


#if ((defined(S32R45) || defined(S32R41) || defined(SAF85XX) || defined(SAF86XX)) && defined(DSP_ENABLE))


void Dsphd_EventCb(uint32_t status)
{
	if(status == DSPHD_SIG_ASYNC_DONE)
	{
		AppCondFlagSignal(&bbe32AsyncDone);
	}
	else
	{
		HALT_HERE;
	}
}

//==========================================================
// Bootloader for DSP
//==========================================================

void Spt_DspBootloaderCb(void)



{
#if !defined(BOOTLOADER_BOOT)
    uint32_t i, iSeg;
    uint32_t* pSrc, *pDest;

    //load the image:
    for (iSeg = 0; iSeg < RSDK_NUM_DSP_IMG_SEGMENTS; iSeg++)
    {

        pDest = (uint32_t*)dspImgSegmentRunaddr[iSeg];






        pSrc = (uint32_t*)dspImgSegmentLoadAddr[iSeg];

        DbgPrintMsg("Copying DSP image segment %d from 0x%lx to 0x%lx\n", iSeg, (uintptr_t)pSrc, (uintptr_t)pDest);

        //BBE32 IRAM allows 32 bit access only
        for (i = 0; i < dspImgSegmentSizes[iSeg]/4; i++)
        {
            pDest[i] = pSrc[i];
        }
    }
#endif
}
#endif

#ifdef __cplusplus
}
#endif

/******************************************************************************
 * EOF
 *****************************************************************************/
