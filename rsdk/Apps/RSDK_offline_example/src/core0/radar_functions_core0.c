/**************************************************************************************************
 * Copyright 2017-2024 NXP
 **************************************************************************************************
 * NXP Confidential. This software is owned or controlled by NXP and may only be used strictly in
 * accordance with the applicable license terms.  By expressly accepting such terms or by
 * downloading, installing, activating and/or otherwise using the software, you are agreeing that
 * you have read, and that you agree to comply with and are bound by, such license terms.
 * If you do not agree to be bound by the applicable license terms, then you may not retain,
 * install, activate or otherwise use the software.
 **************************************************************************************************/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include <stdio.h>
#include <string.h>

#include "compiler_api.h"



#include "debug_tools.h"
#include "radar_functions_core0.h"
#include "radar_functions_helpers.h"

#include "rsdk_spt_kernels.h"
#include "app_mem_mgr.h"
#include "app_cond_flag.h"
#include "app_defines.h"


#include "heap_size.h"
#include "rsdk_toolchain_helper.h"




#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
rsdkAppCondFlag_t sptDoneFlag;
int               evtIntNum;
int32_t           sptRetPar;


rsdk_heap_t     heapMem;
rsdkAppMemMgr_t pHeapMem = &heapMem;  //the rsdk heap memory manager is only used for bare-metal (SA); on OS the heap is handled by OAL




rsdkBufHandle_t gSptModuleCodeRelocBufH;  // Relocation buffer for the SPT Kernel code
rsdkBufHandle_t gSdadcSampleBufferBufH;   // SDADC sample buffer dimensioned for 2 chirps (double chirp buffer)

#if ((defined(S32R45) || defined(S32R41) || defined(SAF85XX))  && defined(DSP_ENABLE))







uint8_t gDspRcJobListBuf[DSPHD_SIZEOF_JOB_LIST] __attribute__((aligned(4)));
uint8_t gDspCeJobListBuf[DSPHD_SIZEOF_JOB_LIST] __attribute__((aligned(4)));
uint8_t gDspLongJobListBuf[DSPHD_SIZEOF_JOB_LIST] __attribute__((aligned(4)));
uint8_t gDspAsyncJobListBuf[DSPHD_SIZEOF_JOB_LIST] __attribute__((aligned(4)));
rsdkAppCondFlag_t bbe32AsyncDone;

#if defined(TRACE_ENABLE)
uint8_t gTraceBufferDsp[TRACE_BUF_SIZE_DSP] __attribute__((aligned(CACHE_LINE_SIZE))) __attribute__((section(".dsp_trace")));
Dsphd_TraceCfgType dspTraceCfg;
#endif
Dsphd_RuntimeCfgType dspRuntimeCfg;

#endif

char            fileName[75];

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

//==========================================================
// SPT kernel initialization
//==========================================================
void ExampleInitSPTKernels(void)
{


    Spt_DriverContextType sptContext;
    Spt_ParamType paramType;





    uint16_t               np = 0;


    // SPT twiddle, window and steering coefficient arrays.They can be freed once their content is copied into SPT internal memory
    rsdkBufHandle_t gFft512TwiddleFactorsBufH;
    rsdkBufHandle_t gFft128TwiddleFactorsBufH;
    rsdkBufHandle_t gFft512BlackmanWindowBufH;
    rsdkBufHandle_t gFft128BlackmanWindowBufH;
    rsdkBufHandle_t gFft16TwiddleFactorsBufH, gDbfSteeringVectorsBufH;

    //--- Init SPT runtime context for Range & Doppler Initialization Kernel -------------------------------------------------
    DbgPrintMsg("Running Range & Doppler Initialization Kernel...\n");


    AppMemAllocBuffer(pHeapMem, &gFft512TwiddleFactorsBufH, sizeof(uint32_t) * RSDK_SPT_FFT512_TWIDDLE_BUF_SIZE,
                      CACHE_LINE_SIZE, RSDK_OALMEM_CHUNK_ID_SPT_DATA);
    AppMemAllocBuffer(pHeapMem, &gFft128TwiddleFactorsBufH, sizeof(uint32_t) * RSDK_SPT_FFT128_TWIDDLE_BUF_SIZE,
                      CACHE_LINE_SIZE, RSDK_OALMEM_CHUNK_ID_SPT_DATA);
    AppMemAllocBuffer(pHeapMem, &gFft512BlackmanWindowBufH, sizeof(uint16_t) * RSDK_SPT_FFT512_WINDOW_BUF_SIZE,
                      CACHE_LINE_SIZE, RSDK_OALMEM_CHUNK_ID_SPT_DATA);
    AppMemAllocBuffer(pHeapMem, &gFft128BlackmanWindowBufH, sizeof(uint16_t) * RSDK_SPT_FFT128_WINDOW_BUF_SIZE,
                      CACHE_LINE_SIZE, RSDK_OALMEM_CHUNK_ID_SPT_DATA);
    AppMemAllocBuffer(pHeapMem, &gFft16TwiddleFactorsBufH, sizeof(uint32_t) * RSDK_SPT_FFT16_TWIDDLE_BUF_SIZE,
                      CACHE_LINE_SIZE, RSDK_OALMEM_CHUNK_ID_SPT_DATA);
    AppMemAllocBuffer(pHeapMem, &gDbfSteeringVectorsBufH, sizeof(uint32_t) * RSDK_SPT_DBF64_4CH_STEERVECT_BUF_SIZE,
                      CACHE_LINE_SIZE, RSDK_OALMEM_CHUNK_ID_SPT_DATA);


    memset(&sptContext, 0, sizeof(sptContext));

    sptContext.kernelCodeAddr = (uintptr_t)gSptModuleCodeRelocBufH.phyAddr;

    sptContext.opMode = SPT_OP_MODE;




    sptContext.kernelRetPar = NULL;  //this kernel has no return value
    sptContext.checkKernelWatermark = CHECK_KERNEL_WATERMARK;








    //first SPT Kernel to be run is the initialization of Range & Doppler FFTs for the 128chirps x 512 samples use case
    RelocSptCode(gSptModuleCodeRelocBufH.virtAddr, RsdkSptInit512smp128crp4ch, RSDK_SPT_GET_KERNEL_SIZE(RsdkSptInit512smp128crp4ch));

    //SPT parameter list:

    paramType = SPT_PARAM_TYPE_ADDR;




    sptContext.kernelParList[np].paramType = paramType;
    sptContext.kernelParList[np++].paramValue = (uintptr_t)(gFft512TwiddleFactorsBufH.phyAddr);
    sprintf(fileName, "%s%s", FILE_IN_PATH, "fft512_twiddle_factors.dat");
	/* RSDK data is stored in files big-endian format for compatibility reasons with PPC architectures
    	Endianess conversion is done ONLY for reading and writing data to/from files. No transformation is necessary in the processing flow.*/
    DbgReadFileConvert(fileName, 0, (char *)gFft512TwiddleFactorsBufH.virtAddr, gFft512TwiddleFactorsBufH.numBytes, ENDIAN_CHANGE, DATA_BUFF_IS_CACHED);

    sptContext.kernelParList[np].paramType = paramType;
    sptContext.kernelParList[np++].paramValue = (uintptr_t)gFft128TwiddleFactorsBufH.phyAddr;
    sprintf(fileName, "%s%s", FILE_IN_PATH, "fft128_twiddle_factors.dat");
    DbgReadFileConvert(fileName, 0, (char *)gFft128TwiddleFactorsBufH.virtAddr, gFft128TwiddleFactorsBufH.numBytes, ENDIAN_CHANGE, DATA_BUFF_IS_CACHED);

    sptContext.kernelParList[np].paramType = paramType;
    sptContext.kernelParList[np++].paramValue = (uintptr_t)gFft512BlackmanWindowBufH.phyAddr;
    sprintf(fileName, "%s%s", FILE_IN_PATH, "fft512_win_blackman.dat");
    DbgReadFileConvert(fileName, 0, (char *)gFft512BlackmanWindowBufH.virtAddr, gFft512BlackmanWindowBufH.numBytes, ENDIAN_CHANGE, DATA_BUFF_IS_CACHED);

    sptContext.kernelParList[np].paramType = paramType;
    sptContext.kernelParList[np++].paramValue = (uintptr_t)gFft128BlackmanWindowBufH.phyAddr;
    sprintf(fileName, "%s%s", FILE_IN_PATH, "fft128_win_blackman.dat");
    DbgReadFileConvert(fileName, 0, (char *)gFft128BlackmanWindowBufH.virtAddr, gFft128BlackmanWindowBufH.numBytes, ENDIAN_CHANGE, DATA_BUFF_IS_CACHED);

    sptContext.kernelParList[np].paramType = paramType;
    sptContext.kernelParList[np++].paramValue = (uintptr_t)gFft16TwiddleFactorsBufH.phyAddr;
    sprintf(fileName, "%s%s", FILE_IN_PATH, "fft16_twiddle_factors.dat");
    DbgReadFileConvert(fileName, 0, (char *)gFft16TwiddleFactorsBufH.virtAddr, gFft16TwiddleFactorsBufH.numBytes, ENDIAN_CHANGE, DATA_BUFF_IS_CACHED);

    // Allocate only for Initialization Kernel, no DFB DOA run in this case, no need for valid data in buffer
    sptContext.kernelParList[np].paramType = paramType;
    sptContext.kernelParList[np++].paramValue = (uintptr_t)gDbfSteeringVectorsBufH.phyAddr;



    paramType = SPT_PARAM_TYPE_LAST;




    sptContext.kernelParList[np].paramType = paramType;

    //--- Run Range & Doppler Initialization Kernel --------------------------------------------
    ExampleLaunchSptKernel(&sptContext);


    //free in reverse-allocation order, to be compatible with stand-alone RsdkHeap implementation
    AppMemFreeBuffer(pHeapMem, (&gDbfSteeringVectorsBufH));
    AppMemFreeBuffer(pHeapMem, (&gFft16TwiddleFactorsBufH));
    AppMemFreeBuffer(pHeapMem, (&gFft128BlackmanWindowBufH));
    AppMemFreeBuffer(pHeapMem, (&gFft512BlackmanWindowBufH));
    AppMemFreeBuffer(pHeapMem, (&gFft128TwiddleFactorsBufH));
    AppMemFreeBuffer(pHeapMem, (&gFft512TwiddleFactorsBufH));

    //after SPT_init_range512_doppler128 has finished, all the twiddle and windowing coefficients are placed in the
    //internal memory of the SPT. From now on, we can run the SPT_rangeFFT_512smp_128crp and SPT_dopplerFFT_128crp_512smp
    //multiple times without reinitialization, provided that no error occurs during execution.


}

//==========================================================
// Complete SPT flow
//==========================================================
void ExampleProcSPT(void)
{
    rsdkStatus_t            sptStatus = RSDK_SUCCESS;

    Spt_DriverContextType 	sptContext;
    Spt_ParamType 			paramType;





    rsdkBufHandle_t         gRadarCubeResultsBufH;
    uint16_t                np;


    rsdkBufHandle_t         gRdmBufferBufH;          //used for RDM memory
    rsdkBufHandle_t         gScratchBufH;            // used for scratch memory
    rsdkBufHandle_t         gPeakSearchResultsBufH;  // stores 2D/3D Peak Search results
    rsdkBufHandle_t         gThresholdBufH;          // stores the thresholds for 2D/3D Peak Search
    rsdkBufHandle_t         gHistResultsBufH;        // stores the Histogram output
    rsdkBufHandle_t         gCaCfarResultsBufH;      // stores output of cfar










#if ((defined(S32R45) || defined(S32R41) || defined(SAF85XX)) && defined(DSP_ENABLE))
    rsdkBbe32CaCfarParams_t *pCaCfarParams;  // stores the CFAR params for the BBE32
    rsdkBufHandle_t         caCfarParamsBufH;

    rsdkBufHandle_t         gLalVectorAddInput1BufH; // stores Input1 of LAL VectorAdd
    rsdkBufHandle_t         gLalVectorAddInput2BufH; // stores Input2 of LAL VectorAdd
    rsdkBufHandle_t         gLalVectorAddResultsBufH; // stores Output of LAL VectorAdd
    rsdkBufHandle_t         lalVectorAddBufH;
    rsdkBbe32LalVectorAddParams_t * pLalVectorAdd;  // stores the VectorAdd params for the BBE32

    uint32_t size_v;


    Spt_DspCmdType dspCmd;
    Spt_DriverCommandType sptCmd;
    Spt_DriverCmdResType sptCmdResult;






#endif
#if ((defined(S32R41) || defined(SAF85XX)) && defined(DSP_ENABLE))
    // Update chirp end job list
    dspJobsList[0].id =  (uint16_t)RSDK_DSP_GET_FUNC_ID(RsdkBbe32Func1);
    dspJobsList[0].arg = 0xABCD7777u;
    AppUpdateDspJobList(gDspCeJobListBuf, dspJobsList, 1u);
    DbgPrintMsg("ARM->BBE32 msg sent: DSPHD_MSG_UPDATE_CE_JOB_LIST.\n");

    // Preempt with polling for P1Task
    AppChangeDspRuntimeConfig(CHIRPS_PER_FRAME, DSPHD_CFG_P1_TASK_NON_PREEMPT, DSPHD_CFG_FPU_ROUND_TO_NEAREST, 1u);
    DbgPrintMsg("ARM->BBE32 msg sent: DSPHD_MSG_UPDATE_CONFIG.\n");
#endif

    //--- Re-init SPT runtime context for Range FFT Kernel -------------------------------------------------
    DbgPrintMsg("Running Range FFT Kernel...\n");

    evtIntNum = 0;





    AppMemAllocBuffer(pHeapMem, &gSdadcSampleBufferBufH, sizeof(uint16_t) * RSDK_SPT_RANGE512_4CH_IN_BUF_SIZE,
                      SPT_DATA_ADDR_ALIGN_BYTES, RSDK_OALMEM_CHUNK_ID_SPT_DATA);




    AppMemAllocBuffer(pHeapMem, &gRadarCubeResultsBufH, sizeof(uint32_t) * RSDK_SPT_DOPPLER_512x128_4CH_OUT_BUF_SIZE,
                      CACHE_LINE_SIZE, RSDK_OALMEM_CHUNK_ID_SPT_DATA);
    AppMemAllocBuffer(pHeapMem, &gRdmBufferBufH, sizeof(uint16_t) * RSDK_SPT_NCC_512x128_RDM_BUF_SIZE, CACHE_LINE_SIZE,
                      RSDK_OALMEM_CHUNK_ID_SPT_DATA);
    AppMemAllocBuffer(pHeapMem, &gScratchBufH, sizeof(uint32_t) * RSDK_SPT_PEAKSEARCH_512x128_SCRATCH_BUF_SIZE,
                      CACHE_LINE_SIZE, RSDK_OALMEM_CHUNK_ID_SPT_DATA);
    AppMemAllocBuffer(pHeapMem, &gPeakSearchResultsBufH, sizeof(uint8_t) * RSDK_SPT_PEAKSEARCH_512x128_OUT_BUF_SIZE,
                      CACHE_LINE_SIZE, RSDK_OALMEM_CHUNK_ID_SPT_DATA);
    AppMemAllocBuffer(pHeapMem, &gThresholdBufH, sizeof(uint16_t) * RSDK_SPT_THR_512x128_IN_BUF_SIZE, CACHE_LINE_SIZE,
                      RSDK_OALMEM_CHUNK_ID_SPT_DATA);
    AppMemAllocBuffer(pHeapMem, &gHistResultsBufH, sizeof(uint16_t) * RSDK_SPT_HIST_512x128_OUT_BUF_SIZE,
                      CACHE_LINE_SIZE, RSDK_OALMEM_CHUNK_ID_SPT_DATA);
    AppMemAllocBuffer(pHeapMem, &gCaCfarResultsBufH, sizeof(uint8_t) * RSDK_SPT_PEAKSEARCH_512x128_OUT_BUF_SIZE,
                          CACHE_LINE_SIZE, RSDK_OALMEM_CHUNK_ID_SPT_DATA);
















    sptContext.kernelCodeAddr = (uintptr_t)gSptModuleCodeRelocBufH.phyAddr;
    sptContext.opMode = SPT_OP_MODE;




    sptContext.kernelRetPar = NULL;  //this kernel has no return value
    sptContext.checkKernelWatermark = CHECK_KERNEL_WATERMARK;

    RelocSptCode(gSptModuleCodeRelocBufH.virtAddr, RsdkSptRange512smp128crp4ch, RSDK_SPT_GET_KERNEL_SIZE(RsdkSptRange512smp128crp4ch));

    np = 0;


    paramType = SPT_PARAM_TYPE_ADDR;




    sptContext.kernelParList[np].paramType = paramType;
    sptContext.kernelParList[np++].paramValue = (uintptr_t)gSdadcSampleBufferBufH.phyAddr;

    sptContext.kernelParList[np].paramType = paramType;
    sptContext.kernelParList[np++].paramValue = (uintptr_t)gRadarCubeResultsBufH.phyAddr;
















    paramType = SPT_PARAM_TYPE_VALUE;




    sptContext.kernelParList[np].paramType = paramType;
    sptContext.kernelParList[np++].paramValue = 3; /* no output shift */


    paramType = SPT_PARAM_TYPE_LAST;




    sptContext.kernelParList[np].paramType = paramType;

    //--- Run Range FFT Kernel --------------------------------------------
    ExampleLaunchSptKernel(&sptContext);

	DbgPrintMsg("RsdkSptRun done. SPT range processing done. Ready for next kernel.\n");

    sprintf(fileName, "%s%s", FILE_OUT_PATH, "rfft_out.dat");
	/* Output data to file is done in big-endian format. Endianess conversion is done ONLY for file-writing.*/
    DbgWriteFileConvert(fileName, (char *)gRadarCubeResultsBufH.virtAddr, gRadarCubeResultsBufH.numBytes, ENDIAN_CHANGE, DATA_BUFF_IS_CACHED);

    //--- Re-init SPT runtime context for Doppler FFT Kernel -------------------------------------------------
    DbgPrintMsg("Running Doppler FFT Kernel...\n");

    //rewrite only the fields that are changing..

    RelocSptCode(gSptModuleCodeRelocBufH.virtAddr, RsdkSptDoppler512smp128crp4ch, RSDK_SPT_GET_KERNEL_SIZE(RsdkSptDoppler512smp128crp4ch));

    np = 0;


    paramType = SPT_PARAM_TYPE_ADDR;




    //range output is doppler input
    sptContext.kernelParList[np].paramType = paramType;
    sptContext.kernelParList[np++].paramValue = (uintptr_t)gRadarCubeResultsBufH.phyAddr;

    sptContext.kernelParList[np].paramType = paramType;
    sptContext.kernelParList[np++].paramValue = (uintptr_t)gRadarCubeResultsBufH.phyAddr;
















    paramType = SPT_PARAM_TYPE_VALUE;




    sptContext.kernelParList[np].paramType = paramType;
    sptContext.kernelParList[np++].paramValue = 0; /* no output shift */


    paramType = SPT_PARAM_TYPE_LAST;



    sptContext.kernelParList[np].paramType = paramType;

    //--- Run Doppler FFT Kernel --------------------------------------------
    ExampleLaunchSptKernel(&sptContext);

    sprintf(fileName, "%s%s", FILE_OUT_PATH, "dfft_out.dat");
    DbgWriteFileConvert(fileName, (char *)gRadarCubeResultsBufH.virtAddr, gRadarCubeResultsBufH.numBytes, ENDIAN_CHANGE, DATA_BUFF_IS_CACHED);

    //--- Re-init SPT runtime context for Non Coherent Combining Kernel -------------------------------------------------
    DbgPrintMsg("Running Non Coherent Combining Kernel...\n");

    //rewrite only the fields that are changing..
    RelocSptCode(gSptModuleCodeRelocBufH.virtAddr, RsdkSptNcc512smp128crp4ch, RSDK_SPT_GET_KERNEL_SIZE(RsdkSptNcc512smp128crp4ch));


    paramType = SPT_PARAM_TYPE_ADDR;




    // doppler output is Non Coherent Combining input
    sptContext.kernelParList[0].paramType = paramType;
    sptContext.kernelParList[0].paramValue = (uintptr_t)gRadarCubeResultsBufH.phyAddr;

    // output buffer
    sptContext.kernelParList[1].paramType = paramType;
    sptContext.kernelParList[1].paramValue = (uintptr_t)gRdmBufferBufH.phyAddr;

    // histogram output buffer is set here
    sptContext.kernelParList[2].paramType = paramType;
    sptContext.kernelParList[2].paramValue = (uintptr_t)gHistResultsBufH.phyAddr;


    paramType = SPT_PARAM_TYPE_LAST;




    sptContext.kernelParList[3].paramType = paramType;

    //--- Run Non Coherent Combining Kernel --------------------------------------------
    ExampleLaunchSptKernel(&sptContext);

    sprintf(fileName, "%s%s", FILE_OUT_PATH, "ncc_out.dat");
    DbgWriteFileConvert(fileName, (char *)gRdmBufferBufH.virtAddr, gRdmBufferBufH.numBytes, ENDIAN_CHANGE, DATA_BUFF_IS_CACHED);

    sprintf(fileName, "%s%s", FILE_OUT_PATH, "ncc_hist_out.dat");
    DbgWriteFileConvert(fileName, (char *)gHistResultsBufH.virtAddr, gHistResultsBufH.numBytes, ENDIAN_CHANGE, DATA_BUFF_IS_CACHED);

    DbgPrintMsg("Running Peak Search Kernel...\n");

    //rewrite only the fields that are changing..

    RelocSptCode(gSptModuleCodeRelocBufH.virtAddr, RsdkSptPeakSearch512smp128crp, RSDK_SPT_GET_KERNEL_SIZE(RsdkSptPeakSearch512smp128crp));


    paramType = SPT_PARAM_TYPE_ADDR;




    // RDM output is Peak Search input
    sptContext.kernelParList[0].paramType = paramType;
    sptContext.kernelParList[0].paramValue = (uintptr_t)gRdmBufferBufH.phyAddr;

    // threshold data
    sptContext.kernelParList[1].paramType = paramType;
    sptContext.kernelParList[1].paramValue = (uintptr_t)gThresholdBufH.phyAddr;
    sprintf(fileName, "%s%s", FILE_IN_PATH, "ps_hthr_in.dat");
    DbgReadFileConvert(fileName, 0, (char *)gThresholdBufH.virtAddr, gThresholdBufH.numBytes, ENDIAN_CHANGE, DATA_BUFF_IS_CACHED);

    // scratch buffer
    sptContext.kernelParList[2].paramType = paramType;
    sptContext.kernelParList[2].paramValue = (uintptr_t)gScratchBufH.phyAddr;

    // peak output buffer is set here
    sptContext.kernelParList[3].paramType = paramType;
    sptContext.kernelParList[3].paramValue = (uintptr_t)gPeakSearchResultsBufH.phyAddr;


    paramType = SPT_PARAM_TYPE_LAST;




    sptContext.kernelParList[4].paramType = paramType;

    //--- Run Peak Search Kernel --------------------------------------------
    ExampleLaunchSptKernel(&sptContext);

    sprintf(fileName, "%s%s", FILE_OUT_PATH, "ps_out.dat");
    DbgWriteFileConvert(fileName, (char *)gPeakSearchResultsBufH.virtAddr, gPeakSearchResultsBufH.numBytes, ENDIAN_CHANGE, DATA_BUFF_IS_CACHED);

#if ((defined(S32R45) || defined(S32R41) || defined(SAF85XX)) && defined(DSP_ENABLE))
    //--- Re-init SPT runtime context for SPT DSP Kernel -------------------------------------------------
    DbgPrintMsg("Running DSP basic kernel...\n");

    //rewrite only the fields that are changing..

    sptRetPar = 0;

    sptContext.kernelRetPar = &sptRetPar;  //DSP function places its return param in SPT Work Reg 0

    RelocSptCode(gSptModuleCodeRelocBufH.virtAddr, RsdkSptDspExampleDirectBlocking, RSDK_SPT_GET_KERNEL_SIZE(RsdkSptDspExampleDirectBlocking));


    paramType = SPT_PARAM_TYPE_LAST;




    //No runtime parameters for this kernel. Everything is hardcoded inside the kernel
    sptContext.kernelParList[0].paramType = paramType;

    //--- Run DSP Kernel --------------------------------------------
    ExampleLaunchSptKernel(&sptContext);
    DbgPrintMsg("DSP finished\n");











    //--- Re-init SPT runtime context for SPT DSP CFAR Kernel -------------------------------------------------
    DbgPrintMsg("Running DSP CFAR kernel...\n");

    AppMemAllocBuffer(pHeapMem, &caCfarParamsBufH, sizeof(rsdkBbe32CaCfarParams_t), CACHE_LINE_SIZE,
                      RSDK_OALMEM_CHUNK_ID_SRAM);
    pCaCfarParams = (rsdkBbe32CaCfarParams_t *)caCfarParamsBufH.virtAddr;

    pCaCfarParams->rangeBins = SAMPLES_PER_CHIRP / 2;
    pCaCfarParams->dopplerBins = CHIRPS_PER_FRAME;

    pCaCfarParams->windowSize = 5;
    pCaCfarParams->guardInterval = 2;
    pCaCfarParams->thresholdFactor = 500; //SPT Mag2Log2 format






    pCaCfarParams->pRdm = (uint32_t)(uintptr_t)gRdmBufferBufH.phyAddr;  //intentional cast from 64-bit A53 pointer to 32-bit integer,
                                                           //because the BBE32 only supports 32-bit addresses.
    //User must make sure this address is accessible from BBE32 side.
    pCaCfarParams->pDetectBitmap = (uint32_t)(uintptr_t)gCaCfarResultsBufH.phyAddr;  //reuse the peak search buffers
    pCaCfarParams->pThr = (uint32_t)(uintptr_t)gScratchBufH.phyAddr;

    //rewrite only the fields that are changing in the sptContext:

    sptRetPar = 0;

    sptContext.kernelRetPar = &sptRetPar;

    RelocSptCode(gSptModuleCodeRelocBufH.virtAddr, RsdkSptDspExampleIndirectBlocking, RSDK_SPT_GET_KERNEL_SIZE(RsdkSptDspExampleIndirectBlocking));


    // The DSP reads data from SRAM
    CacheFlush((const char *)caCfarParamsBufH.virtAddr, sizeof(rsdkBbe32CaCfarParams_t));


    dspCmd.id = (uint16_t)RSDK_DSP_GET_FUNC_ID(RsdkBbe32CaCfar);
    dspCmd.arg = (uint32_t)(uintptr_t)caCfarParamsBufH.phyAddr;

	sptCmd.cmdId = SPT_CMD_GEN_DSP_CMD_CRC;
	sptCmd.cmdParam = (Spt_DriverCommandParamType)&dspCmd;
    sptStatus = Spt_Command(&sptCmd, &sptCmdResult); //Legacy code: sptCmdResult is not used in this command, but must not be NULL





    statusCheck("RsdkSptCommand", sptStatus);


    paramType = SPT_PARAM_TYPE_VALUE;




    //all parameters destined for the BBE32 are passed as "RSDK_SPT_PARAM_TYPE_VALUE" type,
    //even if they are pointers, to avoid the address translation done by SPT Driver on "RSDK_SPT_PARAM_TYPE_ADDR" params.
    sptContext.kernelParList[0].paramType = paramType;
    sptContext.kernelParList[0].paramValue = dspCmd.arg;

    sptContext.kernelParList[1].paramType = paramType;
    sptContext.kernelParList[1].paramValue = dspCmd.id;

    sptContext.kernelParList[2].paramType = paramType;
    sptContext.kernelParList[2].paramValue = dspCmd.crc;


    paramType = SPT_PARAM_TYPE_LAST;




    sptContext.kernelParList[3].paramType = paramType;

    //--- Run DSP Kernel --------------------------------------------
    ExampleLaunchSptKernel(&sptContext);
    DbgPrintMsg("DSP finished\n");

    sprintf(fileName, "%s%s", FILE_OUT_PATH, "caCfar_bmp_out.dat");
    DbgWriteFileConvert(fileName, (char *)gCaCfarResultsBufH.virtAddr, gCaCfarResultsBufH.numBytes, "word32", DATA_BUFF_IS_CACHED);




    //--- Running DSP LAL Kernel via Host Driver (add up 2 vectors) -------------------------------------------------
    AppMemAllocBuffer(pHeapMem, &lalVectorAddBufH, sizeof(rsdkBbe32LalVectorAddParams_t), CACHE_LINE_SIZE, RSDK_OALMEM_CHUNK_ID_SPT_DATA);

    pLalVectorAdd = (rsdkBbe32LalVectorAddParams_t *)lalVectorAddBufH.virtAddr;

    size_v 	   = SIZE_VEC * BBE_BATCH_WIDTH * sizeof(float32_t); //  in this demo: SIZE_VEC=6; BBE_BATCH_WIDTH=8
    AppMemAllocBuffer(pHeapMem, &gLalVectorAddInput1BufH, size_v, CACHE_LINE_SIZE, RSDK_OALMEM_CHUNK_ID_SPT_DATA);
    AppMemAllocBuffer(pHeapMem, &gLalVectorAddInput2BufH, size_v, CACHE_LINE_SIZE, RSDK_OALMEM_CHUNK_ID_SPT_DATA);
    AppMemAllocBuffer(pHeapMem, &gLalVectorAddResultsBufH, size_v, CACHE_LINE_SIZE, RSDK_OALMEM_CHUNK_ID_SPT_DATA);

    sprintf(fileName, "%s%s", FILE_IN_PATH, "lal_vector_add_in1.dat");
    DbgReadFileConvert(fileName, 0, (char *)gLalVectorAddInput1BufH.virtAddr, gLalVectorAddInput1BufH.numBytes, "none", DATA_BUFF_IS_CACHED);
    sprintf(fileName, "%s%s", FILE_IN_PATH, "lal_vector_add_in2.dat");
    DbgReadFileConvert(fileName, 0, (char *)gLalVectorAddInput2BufH.virtAddr, gLalVectorAddInput2BufH.numBytes, "none", DATA_BUFF_IS_CACHED);

    //User must make sure this address is accessible from BBE32 side.
    pLalVectorAdd->pInput1 = (uint32_t)(uintptr_t)gLalVectorAddInput1BufH.phyAddr;  //intentional cast from 64-bit A53 pointer to 32-bit integer,
    pLalVectorAdd->pInput2 = (uint32_t)(uintptr_t)gLalVectorAddInput2BufH.phyAddr;  //intentional cast from 64-bit A53 pointer to 32-bit integer,
    pLalVectorAdd->pOutput = (uint32_t)(uintptr_t)gLalVectorAddResultsBufH.phyAddr;  //intentional cast from 64-bit A53 pointer to 32-bit integer,
    //because the BBE32 only supports 32-bit addresses.
    pLalVectorAdd->size = SIZE_VEC;

    // The DSP reads data from SRAM
    CacheFlush((const char *)lalVectorAddBufH.virtAddr, sizeof(rsdkBbe32LalVectorAddParams_t));
    CacheFlush((const char *)gLalVectorAddInput1BufH.virtAddr,  gLalVectorAddInput1BufH.numBytes);
    CacheFlush((const char *)gLalVectorAddInput2BufH.virtAddr,  gLalVectorAddInput2BufH.numBytes);

    AppRunDspAsyncJob(gDspAsyncJobListBuf, (uint32_t)(uintptr_t)lalVectorAddBufH.phyAddr, (uint16_t)RSDK_DSP_GET_FUNC_ID(RsdkBbe32LalVectorAdd));
#if defined(TRACE_ENABLE)
	AppStopDspTrace();
#endif
    CacheInvalidate((char *)gLalVectorAddResultsBufH.virtAddr, gLalVectorAddResultsBufH.numBytes); // get rid of older values

    sprintf(fileName, "%s%s", FILE_OUT_PATH, "lal_vector_add_out.dat");
    DbgWriteFileConvert(fileName, (char *)gLalVectorAddResultsBufH.virtAddr, gLalVectorAddResultsBufH.numBytes, "none", DATA_BUFF_IS_CACHED);


#endif  //DSP_ENABLE




























    //free in reverse-allocation order, to be compatible with stand-alone RsdkHeap implementation
#if ((defined(S32R41) || defined(SAF85XX)) && defined(DSP_ENABLE))
    AppMemFreeBuffer(pHeapMem, (&gLalVectorAddResultsBufH));
    AppMemFreeBuffer(pHeapMem, (&gLalVectorAddInput2BufH));
    AppMemFreeBuffer(pHeapMem, (&gLalVectorAddInput1BufH));
    AppMemFreeBuffer(pHeapMem, (&lalVectorAddBufH));
#endif
#if ((defined(S32R45) || defined(S32R41) || defined(SAF85XX)) && defined(DSP_ENABLE))
    AppMemFreeBuffer(pHeapMem, (&caCfarParamsBufH));
#endif








    AppMemFreeBuffer(pHeapMem, (&gCaCfarResultsBufH));
    AppMemFreeBuffer(pHeapMem, (&gHistResultsBufH));
    AppMemFreeBuffer(pHeapMem, (&gThresholdBufH));
    AppMemFreeBuffer(pHeapMem, (&gPeakSearchResultsBufH));
    AppMemFreeBuffer(pHeapMem, (&gScratchBufH));
    AppMemFreeBuffer(pHeapMem, (&gRdmBufferBufH));
    AppMemFreeBuffer(pHeapMem, (&gRadarCubeResultsBufH));
    AppMemFreeBuffer(pHeapMem, (&gSdadcSampleBufferBufH));
    AppMemFreeBuffer(pHeapMem, (&gSptModuleCodeRelocBufH));


    //--- Stop the SPT hardware  --------------------------------------------

    sptStatus = Spt_Stop();



    statusCheck("RsdkSptStop", sptStatus);
    DbgPrintMsg("SPT stopped.\n");

    // destroy sptDoneFlag binary semaphore 
    AppCondFlagDestroy(&sptDoneFlag);

    AppCondFlagDestroy(&bbe32AsyncDone);




}

//==========================================================
// Test for SPT memory error injection
//==========================================================
void ExampleTestSPTMemErrInject(void)
{
	rsdkStatus_t           sptStatus = RSDK_SUCCESS;


	Spt_DriverCmdResType    sptCmdResult;
    Spt_DriverContextType   sptContext;
    Spt_DriverCommandType   sptCmd = {SPT_CMD_MEM_ERR_INJECT_EN, 0};
    Spt_ParamType 			paramType;






    //allocate a buffer to contain the code of the SPT kernels. This must be done before any kernel is called
    //TODO: move it out of this function, to the application init area

    AppMemAllocBuffer(pHeapMem, &gSptModuleCodeRelocBufH, MAX_SPT_MODULE_CODE_SIZE, SPT_CODE_ADDR_ALIGN_BYTES,
                      RSDK_OALMEM_CHUNK_ID_SRAM);





    DbgPrintMsg("Starting SPT memory error injection test \n");

    //enable memory error injection in SPT

    sptStatus = Spt_Command(&sptCmd, &sptCmdResult);



    statusCheck("RsdkSptCommand", sptStatus);
    DbgPrintMsg("SPT memory error injection enabled!\n");

    //call an SPT kernel which writes to OPRAM and TRAM to generate some parity errors in memory, then reads from the same memory.
    //This is expected to trigger a memory error interrupt on the SPT ECS interrupt line
    memset(&sptContext, 0, sizeof(sptContext));

    sptContext.opMode = SPT_OP_MODE;




    sptContext.kernelRetPar = NULL;  //this kernel has no return value
    sptContext.checkKernelWatermark = CHECK_KERNEL_WATERMARK;

    RelocSptCode(gSptModuleCodeRelocBufH.virtAddr, RsdkSptMemRwErrInject, RSDK_SPT_GET_KERNEL_SIZE(RsdkSptMemRwErrInject));

    sptContext.kernelCodeAddr = (uintptr_t)gSptModuleCodeRelocBufH.phyAddr;


    paramType = SPT_PARAM_TYPE_LAST;




    sptContext.kernelParList[0].paramType = paramType;

    //--- Run memory error injection kernel --------------------------------------------
    ExampleLaunchSptKernel(&sptContext);

    //disable memory error injection in SPT.


    sptCmd.cmdId = SPT_CMD_MEM_ERR_INJECT_DIS;



    sptCmd.cmdParam = 0;


    sptStatus = Spt_Command(&sptCmd, &sptCmdResult);



    statusCheck("RsdkSptCommand", sptStatus);
    DbgPrintMsg("SPT memory error injection disabled. SPT memory now needs to be re-initialized.\n");

    DbgPrintMsg("SPT memory error injection test done \n");
    //At this point, the memory still contains the altered parity bits, any read access would still generate
    //an error interrupt. The memory needs to be re-written, to refresh all affected parity bits.
    //In our example this will happen on the next call of ExampleInitSPTKernels()
}
























#ifdef __cplusplus
}
#endif

/*******************************************************************************
 * EOF
 ******************************************************************************/

/** @} */
