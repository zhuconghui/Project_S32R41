/**************************************************************************************************
 * Copyright 2017-2024 NXP
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
#include <stdio.h>
#include <string.h>

#include "compiler_api.h"
#include "rsdk_glue_irq_register_api.h" // to be removed for NXP RTOS
#include "debug_tools.h"
#include "app_mem_mgr.h"
#include "app_cond_flag.h"
#include "radar_functions_helpers.h"
#include "rfe_types.h"
#include "Rfe20_PCCfg.h"

#include "CDD_Spt.h"
#include "Spt_Irq.h"
#include "rsdk_spt_kernels.h"
#include "CDD_Csi2.h"
#include "CDD_Rfe.h"
#include "CDD_Rfe_Types.h"
#include "rfeConfig.h"
#include "rfeDynamicTables.h"
#if ((defined(S32R41)) && defined(DSP_ENABLE))

#include "CDD_Dsphd.h"
#include "rsdk_dsp_lal_vector_add.h"

#include "rsdk_dsp_radar_bb_algos.h"
#include "rsdk_dsp_dispatcher_func_list_host.h"
#endif

#include "app_defines.h"
#include "radar_functions_core0.h"

#include "Spt_PBcfg.h"
#include "ipcf_Ip_Cfg.h"


#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define MAX_NR_CSI2_ERRORS 10
#define PING_PONG_BUFFERING 2
#define NR_RX_ANT 4
#define ADC_SAMPLE_BUFF_SIZE (PING_PONG_BUFFERING * ((NUM_SAMPLES_PER_CHIRP_PROF_0 * NR_RX_ANT * BYTES_PER_SAMPLE) + CSI2_LINE_STAT_LENGTH))

#define CONFIG_LINE_SIZE 256         /* Length of config file line*/
#define MAX_PARAM_NAME_LENGTH 30     /* Length of parameter line's n*/
#define APP_DUMMY_RFE_ID      (0xC0FFEE41)
#define ADC_ACQ_TIMEOUT_CNT_START  2000000
#define RFE_DBG_REGDUMP_MASK (rfe_registerDump_CC  | rfe_registerDump_CSI2 | rfe_registerDump_TE     | \
				              rfe_registerDump_SC  | rfe_registerDump_CAFC | rfe_registerDump_ADC12  | rfe_registerDump_ADC34 | \
							  rfe_registerDump_GB  | rfe_registerDump_LOI  | rfe_registerDump_MCLK   | rfe_registerDump_RX1   | \
							  rfe_registerDump_RX2 | rfe_registerDump_RX3  | rfe_registerDump_RX4    | rfe_registerDump_TX1   | \
							  rfe_registerDump_TX2 | rfe_registerDump_TX3  | rfe_registerDump_SSBMOD | rfe_registerDump_GLDO  | \
							  rfe_registerDump_OTP | rfe_registerDump_ISM  | rfe_registerDump_OTP_TABLE | rfe_registerDump_ATB_VOLTAGE_READOUT)

#define RFE_DBG_REGDUMP_SIZE (RFE_CC_REG_NUMBER     + RFE_CSI2_REG_NUMBER  + RFE_TE_REG_NUMBER    + \
   	   	   	   	   	  	  	  RFE_SC_REG_NUMBER     + RFE_CAFC_REG_NUMBER  + 2*RFE_ADC_REG_NUMBER + RFE_GB_REG_NUMBER   + \
							  RFE_LOI_REG_NUMBER    + RFE_MCLK_REG_NUMBER  + 4*RFE_RX_REG_NUMBER  + 3*RFE_TX_REG_NUMBER + \
							  RFE_SSBMOD_REG_NUMBER + RFE_GLDO_REG_NUMBER  + RFE_OTP_REG_NUMBER   + RFE_ISM_REG_NUMBER  + \
							  RFE_OTP_TABLE_NUMBER  + RFE_ATB_VOLTAGE_TABLE_NUMBER)

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
typedef uint32_t appRfeHwId_t;  /* Just for example*/
typedef struct {
	appRfeHwId_t rfeHwId;
	Cdd_RfeRxBistZeroHourRefDataType bistZeroHour;
} rfeBistReferenceData_t;

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
extern 	Csi2_SetupParamsType 	Csi2SetupParamsList_0;
extern 	Csi2_SetupParamsType 	Csi2SetupParamsList_1;
extern Std_ReturnType gAppStatus;
#if APP_RUNTIME_CONFIG
extern Csi2_VCParamsType SetupParam_1_Params_VC_0;
extern Csi2_VCParamsType SetupParam_0_Params_VC_0;
extern Csi2_VCParamsType SetupParam_0_Params_VC_3;
extern Csi2_VCParamsType SetupParam_1_Params_VC_3;
#endif
uint8_t	gAdcDataBuff0[ADC_SAMPLE_BUFF_SIZE] 	__attribute__((aligned(16))) __attribute__((section(".radar")));
uint8_t	gAdcDataBuff1[ADC_SAMPLE_BUFF_SIZE] 	__attribute__((aligned(16))) __attribute__((section(".radar")));
uint8_t heapBuffer[HEAP_BUFF_SIZE] __attribute__((aligned(64))) __attribute__((section(".radar")));
uint8_t eof_session_cfg_file = 0;

/* Reserved memory for RFE communication and sync buffers. This section must be placed in linker file, making sure it covers
   the region defined by RFE_CMD_CLIENT_BASE_ADDRESS, RFE_CMD_IF_RFE_STATE_ADDRESS and RFE_CMD_IF_BASE_ADDRESS_PTR.
   It can also be split in smaller pieces, to optimize memory */
uint8_t gRfeCommBuffer[0x10000] __attribute__((section(".rfe_fw")));


rsdk_heap_t     heapMem;
rsdkAppMemMgr_t pHeapMem = &heapMem;  //the rsdk heap memory manager is only used for bare-metal (SA); on OS the heap is handled by OAL




#if ((defined(S32R41)) && defined(DSP_ENABLE))


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

char            fileName[150];
char    fileContent[20000]; /** allocate on app heap?? */

rsdkAppSettings_t gAppConfig;
rsdkBufferSize_t rsdkBufferSize;
sptKernelChainAddr_t gSptKernelAddr;

rsdkBufHandle_t gSptModuleCodeRelocBufH;  // Relocation buffer for the SPT Kernel code
rsdkBufHandle_t gRadarCubeResultsBufH;
rsdkBufHandle_t gFullAdcSampleBufferBufH;
rsdkBufHandle_t gSdadcSampleBufferBufH;
rsdkBufHandle_t gAdcSample0BufH;
rsdkBufHandle_t gAdcSample1BufH;

rsdkBufHandle_t gCascadedAdcSampleBufH[APP_MAX_NR_SEQUENCES];
rsdkBufHandle_t gAdcSampleBufH[RFE_NUM_USED_FRONT_ENDS][APP_MAX_NR_SEQUENCES];

bool gFrameEndReceivedCSI0; // make this appFlag
bool gFrameEndReceivedCSI1; // make this appFlag
bool gRfeInitialized = false;
uint16_t gLineCount;
volatile expCsi2ErrorInfo_t gCsi2ErrorLog[MAX_NR_CSI2_ERRORS];
volatile uint8_t  gCsi2ErrorCount=0;

int32_t  sptRetPar;

/* radar_functions_helpers.c dependencies*/
rsdkAppCondFlag_t sptDoneFlag;
int               evtIntNum;
uint16_t     gNrDetects = 0;

#ifdef APP_RUNTIME_CONFIG
Csi2_SetupParamsType customCsi2Params[RFE_NUM_USED_FRONT_ENDS];
Csi2_VCParamsType customCsi2VcParams[RFE_NUM_USED_FRONT_ENDS][APP_MAX_NR_SEQUENCES];
uint8_t customRfeConfigs[RFE_NUM_USED_FRONT_ENDS][RFE_CFG_SIZE_TOTAL];
#endif

Csi2_SetupParamsType *pCsi2Params0;
Csi2_SetupParamsType *pCsi2Params1;
Csi2_VCParamsType *pCsi2VcParams0;
Csi2_VCParamsType *pCsi2VcParams1;

uint8_t gUpdateBistZeroHourReferenceFlag = 0;
Std_VersionInfoType rsdkVersionInfo = {0};

rfeBistReferenceData_t  rfeBistReferenceData[RFE_NUM_USED_FRONT_ENDS] = { 0 };
Cdd_RfeVersionType 		rfeSwHwVersionInfo[RFE_NUM_USED_FRONT_ENDS] = { 0 };

#if (RFE_NUM_USED_FRONT_ENDS==1)
const CDD_RfeFrontEndHierarchyType rfeList[RFE_NUM_USED_FRONT_ENDS] = { CDD_RFE_FRONT_END_LEADER };
uint8_t *ppRfeConfigs[RFE_NUM_USED_FRONT_ENDS] = { rfeConfig0 };
#elif (RFE_NUM_USED_FRONT_ENDS==2)
CDD_RfeFrontEndHierarchyType rfeList[RFE_NUM_USED_FRONT_ENDS] = { CDD_RFE_FRONT_END_LEADER, CDD_RFE_FRONT_END_FOLLOWER_0 };
uint8_t *ppRfeConfigs[RFE_NUM_USED_FRONT_ENDS] = { rfeConfig0, rfeConfig1  };
uint8_t *ppDynTbls[RFE_NUM_USED_FRONT_ENDS] = { rfeDynamicTables0, rfeDynamicTables1  };
#else
#error RFE_NUM_USED_FRONT_ENDS should be set to either 1 or 2 for S32R41
#endif

const uint16_t RFE_SAMPLING_FREQUENCY[] = {40, 20, 10, 5}; // according to rfe_effectiveSamplingFrequency_t definition
const uint16_t RFE_SECTION_SEQUENCE_ID[APP_MAX_NR_SEQUENCES] = {
		rfeCfg_section_chirpSequenceConfig_0_e,
		rfeCfg_section_chirpSequenceConfig_1_e,
		rfeCfg_section_chirpSequenceConfig_2_e
};

const uint16_t RFE_SECTION_CHIRP_PROFILE_ID[APP_MAX_NR_PROFILES] = {
		rfeCfg_section_chirpProfile_0_e,
		rfeCfg_section_chirpProfile_1_e,
		rfeCfg_section_chirpProfile_2_e,
		rfeCfg_section_chirpProfile_3_e,
		rfeCfg_section_chirpProfile_4_e,
		rfeCfg_section_chirpProfile_5_e,
		rfeCfg_section_chirpProfile_6_e,
		rfeCfg_section_chirpProfile_7_e
};

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

void ReadConfigFile(char *fileName, char *fileContent, size_t fileContentLen, rsdkAppSettings_t *appConfig);
void ReadAppSessionConfigFile(char *fileName, char *fileContent, size_t fileContentLen, rsdkAppSettings_t *appConfig);
void ParseConfigFile(char *fileContent, size_t fileContentLen, rsdkAppSettings_t *appConfig);
void ScanStatusCheck(int sscanfRet, int refValue);

void PrintError(char* pText)
{
    sprintf(gDbgMsg, "Rfe - %s ERROR - %d\n", pText, CDD_Rfe_GetError());
    DbgPrintMsg(gDbgMsg);
}

// Callback definition for CSI2 interrupts result check
void Csi2_SingleIsrCallback(Csi2_ErrorReportType *pError)
{

    if ((pError->evtMaskVC[CSI2_VC_0] & CSI2_EVT_LINE_END) != 0)
    {
    	gLineCount++;
    }

    if ((pError->unitId == CSI2_UNIT_0 && (pError->evtMaskVC[CSI2_VC_0] & CSI2_EVT_FRAME_END) != 0))
    {
        gFrameEndReceivedCSI0 = true;
    }

    if ((pError->unitId == CSI2_UNIT_1 && (pError->evtMaskVC[CSI2_VC_0] & CSI2_EVT_FRAME_END) != 0))
    {
        gFrameEndReceivedCSI1 = true;
    }
    if ((pError->unitId == CSI2_UNIT_0 && (pError->evtMaskVC[CSI2_VC_1] & CSI2_EVT_FRAME_END) != 0))
    {
        gFrameEndReceivedCSI0 = true;
    }

    if ((pError->unitId == CSI2_UNIT_1 && (pError->evtMaskVC[CSI2_VC_1] & CSI2_EVT_FRAME_END) != 0))
    {
        gFrameEndReceivedCSI1 = true;
    }
    if (pError->errMaskU)
	{
    	if(gCsi2ErrorCount<MAX_NR_CSI2_ERRORS)
    	{
    		gCsi2ErrorLog[gCsi2ErrorCount].unitId = pError->unitId;
    		gCsi2ErrorLog[gCsi2ErrorCount++].errMaskU = pError->errMaskU;
    	}
	}
}

void ExampleCsi2ErrorCheck(void)
{
	if (gCsi2ErrorCount)
	{
		for (int i = 0; i<gCsi2ErrorCount; i++)
		{
			sprintf(gDbgMsg,"Error in CSI2 unit %d  mask 0x%X \n",gCsi2ErrorLog[i].unitId,gCsi2ErrorLog[i].errMaskU);
			DbgPrintMsg(gDbgMsg);
		}
		if (gCsi2ErrorCount >= MAX_NR_CSI2_ERRORS )
		{
			DbgPrintMsg("Error: Too many CSI2 errors!\n");
			HALT_HERE;
		}

		/* Reset error counter*/
		gCsi2ErrorCount=0;
	}
}

void ExampleWaitForAcq(uint16_t frame)
{
	uint32  timeout = ADC_ACQ_TIMEOUT_CNT_START;

	switch (gAppConfig.nrFrontends)
	{
	case 1:
		while(!gFrameEndReceivedCSI0 && timeout)
		{
			timeout--;
		}
		break;
	case 2:
		while(!gFrameEndReceivedCSI0 && !gFrameEndReceivedCSI1 && timeout)
		{
			timeout--;
		}
		break;
	}

	if (timeout)
	{
		ExampleCsi2ErrorCheck();

		/* Reset CSI2 counters and flags*/
		gFrameEndReceivedCSI1 = false;
		gFrameEndReceivedCSI0 = false;
		gLineCount = 0;
	}
	else
	{
		gAppStatus = E_NOT_OK;
	}
}

void ExampleRfeRegisterDump(void)
{
	uint16_t rfeId, status;
	rfe_registerDumpValues_t rfeRegs[RFE_DBG_REGDUMP_SIZE] = {{0}};
	static uint32_t nrRegDump = RFE_DBG_REGDUMP_SIZE;
	for (rfeId = 0; rfeId < gAppConfig.nrFrontends; rfeId++)
	{
		CDD_RfeFrontEndIdMaskType rfeIdMask = 1<<rfeId;
		status = CDD_Rfe_GetRegisterDump( rfeIdMask, RFE_DBG_REGDUMP_MASK, rfeRegs, &nrRegDump);

		if (status == E_OK)
		{
			sprintf (fileName, "%srfe_reg_dump_%d.bin", OUT_PATH, rfeId);
			DbgWriteFile((const char *)fileName, (const char *)rfeRegs, sizeof(rfeRegs));
		}
		else
		{
			HALT_HERE;
		}
	}
}

void ExampleRfeCheckFusa(void)
{
	uint8_t fusaBuf[RFE_FUSA_R1_R2_MASK_UNMASK_FAULT_BYTE_COUNT] = {0};
	rfe_error_t rfeFwError = rfe_error_none_e;
	uint8_t fusaOccured = 0;
	uint16_t rfeIdx;

	// TODO move this outside of fusa faults
	if (CDD_Rfe_TestGetInternalError() == E_OK)
	{
		rfeFwError = CDD_Rfe_GetError();
		DbgPrintMsg ("CDD_Rfe_GetError() = 0x%04x\n", rfeFwError);
	}
	else
	{
		DbgPrintMsg ("CDD_Rfe_TestGetInternalError() - E_NOT_OK\n");
	}

	/* Read FuSa faults for all front-ends*/
	for (rfeIdx = 0; rfeIdx < gAppConfig.nrFrontends; rfeIdx++)
	{
		if(CDD_Rfe_SetFrontEnd((CDD_RfeFrontEndHierarchyType)rfeIdx) != E_OK)
		{
			PrintError("CDD_Rfe_SetFrontEnd()\n");
		}
		else
		{
			DbgPrintMsg("Rfe - CDD_Rfe_SetFrontEnd(%d): ok\n", rfeIdx);
		}

		if ( CDD_Rfe_GetFuSaFaults(fusaBuf) == E_OK )
		{
			for(int i = 0; i < RFE_FUSA_R1_R2_MASK_UNMASK_FAULT_BYTE_COUNT; i++)
			{
				if (fusaBuf[i])
				{
					fusaOccured = 1;
					DbgPrintMsg("FUSA fault mask index %d - error mask 0x%02x\n", i, fusaBuf[i]);
				}
			}
		}
		else
		{
			DbgPrintMsg("CDD_Rfe_GetFuSaFaults() - E_NOT_OK\n");
		}
	}

	/* Output RFE registers to file in case FuSa fault occurred*/
	if (fusaOccured)
	{
		ExampleRfeRegisterDump();
	}

	DbgPrintMsg("ExampleRfeCheckFusa - exit()\n");
	DbgPrintMsg("Test failed!\n");
	DBG_POINT(DBG_ID_HALT_ERROR);
	HALT_HERE;
}

void ExampleRfeWaitForState(rfe_state_t rfeCondition)
{
	rfe_state_t currentState;
	do
	{
		currentState = CDD_Rfe_GetState();
		if (currentState == rfe_state_fuSaFault_e)
		{
			ExampleRfeCheckFusa();
		}
	} while(currentState != rfeCondition);
}

void ExampleSptTearDown(void)
{
	rsdkStatus_t status;

	/* Stop the SPT hardware */
	status = Spt_Stop();
	statusCheck("RsdkSptStop", status);
	DbgPrintMsg("SPT stopped.\n");

	AppCondFlagDestroy(&sptDoneFlag);
}


void ExampleCsi2Init(void)
{
#ifndef APP_RUNTIME_CONFIG
	/* Default Csi2 configuration - Tresos generated*/
	pCsi2Params0 = &Csi2SetupParamsList_0;
	pCsi2Params1 = &Csi2SetupParamsList_1;
#else
	uint8 csi2NumLanes;
	uint32 csi2RxClkFreq;

	/* Adjust CS2 number of lanes and clock depending on sampling frequency - see RFE abstract documentation*/
	/* Assumption is that ppRfeConfigs contains current RFE configuration. All chirp profiles MUST have the same sampling frequency*/
	switch (gAppConfig.rfeSettings.samplingFrequency)
	{
	case rfe_effectiveSamplingFrequency_5MHz_e:
	{
		csi2NumLanes = CSI2_LANE_0;
		csi2RxClkFreq = 240;
		break;
	}
	case rfe_effectiveSamplingFrequency_10MHz_e:
	{
		csi2NumLanes = CSI2_LANE_1;
		csi2RxClkFreq = 240;
		break;
	}
	case rfe_effectiveSamplingFrequency_20MHz_e:
	{
		csi2NumLanes = CSI2_LANE_3;
		csi2RxClkFreq = 240;
		break;
	}
	case rfe_effectiveSamplingFrequency_40MHz_e:
	{
		csi2NumLanes = CSI2_LANE_3;
		csi2RxClkFreq = 480;
		break;
	}
	default:
	{
		csi2NumLanes = CSI2_LANE_3;
		csi2RxClkFreq = 480;
		break;
	}
	}

	/* Adjust CSI2 config according to use-case*/
	for (uint16_t rfeId = 0; rfeId<gAppConfig.nrFrontends; rfeId++)
	{
		memcpy(&customCsi2Params[rfeId], &Csi2SetupParamsList_0, sizeof(Csi2_SetupParamsType)); // copy default CSI2 settings and adjust VC settings
#if	CSI2_STATISTIC_DATA_USAGE == STD_ON
		customCsi2Params[rfeId].statManagement = gAppConfig.csi2StatsEnable;   /* Disable statistics for acquisition only use-case*/
#endif

		customCsi2Params[rfeId].numLanesRx = csi2NumLanes;
		customCsi2Params[rfeId].rxClkFreq = csi2RxClkFreq;

		for (uint16_t seq = 0; seq<gAppConfig.rfeSettings.nrSequences; seq++)
		{
			memcpy(&customCsi2VcParams[rfeId][seq], &SetupParam_0_Params_VC_0, sizeof(Csi2_VCParamsType)); // copy default VC settings and adjust sizes

			customCsi2VcParams[rfeId][seq].expectedNumSamples = gAppConfig.rfeSettings.seqProfileSampleCount[seq];
			customCsi2VcParams[rfeId][seq].expectedNumLines   = gAppConfig.rfeSettings.seqChirpCount[seq];
			customCsi2VcParams[rfeId][seq].bufNumLines        = gAppConfig.rfeSettings.seqChirpCount[seq]; // Keep in memory all chirps
			customCsi2VcParams[rfeId][seq].bufLineLen         = sizeof(uint16_t) * gAppConfig.rfeSettings.seqProfileSampleCount[seq] * RSDK_NR_RX_PER_FRONTEND;
			customCsi2VcParams[rfeId][seq].bufDataPtr         = gAdcSampleBufH[rfeId][seq].phyAddr;

			customCsi2Params[rfeId].vcConfigPtr[seq] = &customCsi2VcParams[rfeId][seq];
		}
	}

	pCsi2Params0   = &customCsi2Params[0];
	pCsi2Params1   = &customCsi2Params[1];
	pCsi2Params0->vcConfigPtr[3] = &SetupParam_0_Params_VC_3;// Virtual channels for BIST - use default hardcoded
	pCsi2Params1->vcConfigPtr[3] = &SetupParam_1_Params_VC_3;
#endif

	// CSI2 initialization
	Std_ReturnType rez = Csi2_Setup(CSI2_UNIT_0, pCsi2Params0);
	if(rez == E_OK)
	{
		DbgPrintMsg("Csi2 Setup - successful \n");
	}

	if (gAppConfig.nrFrontends == 2)
	{
		Std_ReturnType rez = Csi2_Setup(CSI2_UNIT_1, pCsi2Params1);
		if(rez == E_OK)
		{
			DbgPrintMsg("Csi2 Setup - successful \n");
		}
	}
}

void ExampleCsi2Teardown(void)
{
	if (gAppConfig.nrFrontends == 2)
	{
		Std_ReturnType rez = Csi2_PowerOff(CSI2_UNIT_1);
		if(rez == E_OK)
		{
			DbgPrintMsg("Csi2 Power Off Unit 1- successful \n");
		}
	}

	// CSI2 initialization
	Std_ReturnType rez = Csi2_PowerOff(CSI2_UNIT_0);
	if(rez == E_OK)
	{
		DbgPrintMsg("Csi2 Power Off Unit 0- successful \n");
	}
}

void ExampleRfeInit(void)
{
	/* Synchronize with Rfe Drive with RFE FW running on M7-1 core*/
	DbgPrintMsg("Rfe - Initialize and sync with CmdServer \n");
	do
	{
		CDD_Rfe_Init();
	} while (CDD_Rfe_GetError() == rfe_error_api_unresponsive_e );
	DbgPrintMsg("Rfe - synchronized with CmdServer \n");

	ExampleRfeWaitForState(rfe_state_initialized_e);

	DbgPrintMsg("Rfe - Initialization done \n");


	gRfeInitialized = true;
}

void ExampleRfeHwSwVersionCheck(void)
{
	uint8_t rfeIdx=0;
	
	// Obtain AUTOSAR driver Version information
	CDD_Rfe_GetVersionInfo(&rsdkVersionInfo);
	DbgPrintMsg("Rfe - CDD_RFE_Version: v%d.%d.%d\n",
			rsdkVersionInfo.sw_major_version,
			rsdkVersionInfo.sw_minor_version,
			rsdkVersionInfo.sw_patch_version
			);

	// Iterate all Radar Frontends in the application
	for (rfeIdx = 0; rfeIdx < gAppConfig.nrFrontends; rfeIdx++)
	{
		// Select Frontend
		if(CDD_Rfe_SetFrontEnd((CDD_RfeFrontEndHierarchyType)rfeIdx) != E_OK)
		{
	        PrintError("CDD_Rfe_SetFrontEnd()\n");
		}
		else
		{
	        DbgPrintMsg("Rfe - CDD_Rfe_SetFrontEnd(%d): ok\n", rfeIdx);
		}

		// Obtain M7_1 Firmware and RFE hardware version info
		rfeSwHwVersionInfo[rfeIdx] =  CDD_Rfe_SwHwGetVersion();

		// Print and check M7_1 Firmware version only for Rfe0
		if (rfeIdx == 0)
		{
			DbgPrintMsg("Rfe - Firmware Version: v%d.%d.%d (%d)\n",
				rfeSwHwVersionInfo[rfeIdx].fwVersionMajor,
				rfeSwHwVersionInfo[rfeIdx].fwVersionMinor,
				rfeSwHwVersionInfo[rfeIdx].fwVersionPatch,
				rfeSwHwVersionInfo[rfeIdx].fwVersionReleased
			);

			// Check M7_1 Firmware version match to RSDK/M7_0 application
			if ((rsdkVersionInfo.sw_major_version != rfeSwHwVersionInfo[rfeIdx].fwVersionMajor) ||
				(rsdkVersionInfo.sw_minor_version != rfeSwHwVersionInfo[rfeIdx].fwVersionMinor) ||
				(rsdkVersionInfo.sw_patch_version != rfeSwHwVersionInfo[rfeIdx].fwVersionPatch))
			{
				DbgPrintMsg("Rfe - WARNING - M7_1 FW version does not match RSDK/M7_0 version!\n");
			}
		}

		DbgPrintMsg("Rfe%d - Hardware Version: Type: %d, Variant: %d, Version %d, UID 0x%08x\n",
			rfeIdx,
			rfeSwHwVersionInfo[rfeIdx].hwType,
			rfeSwHwVersionInfo[rfeIdx].hwVariant,
			rfeSwHwVersionInfo[rfeIdx].hwVersion,
			rfeSwHwVersionInfo[rfeIdx].hwUniqueId
		);
	}
}

// Write RF BIST T0 data to file
void ExampleRfeIdAndBistRefSetNvm(void)
{
	// Write bistReferenceData to file from host
	sprintf(fileName, "%s%s", AUX_IN_PATH, "rfbist.dat");

	// This call will HALT_HERE, if fileName cannot be opened on host
	(void)DbgWriteFile(fileName, (char *)rfeBistReferenceData, sizeof(rfeBistReferenceData) );

	DbgPrintMsg("RxBIST ZeroHour for RFE UID 0x%08x stored to %s\n", rfeBistReferenceData[0].rfeHwId, fileName);
}

void ExampleRfeIdAndBistRefGetNvm(void)
{
	int cnt=0;

	/* Function to read rfeBistReferenceData[RFE_MAX_SUPPORTED_DEVICES] from NVM
	 * For this demo (run with debugger), data is loaded from a file on the host platform
	 * The data in the file is bound to the Unique ID of the RFE
	 * If the read Id in does not match the RFE ID (see ExampleRfeCheckIdMatch), the Zero-Hour
	 * measurement will be triggered automatically.
	 *
	 * By default, a dummy file (with zeros) will be read, which triggers the Zero-Hour.
	 * On subsequent runs with the same hardware, this will not be done again.
	 */
	sprintf(fileName, "%s%s", AUX_IN_PATH, "rfbist.dat");

	// This call will HALT_HERE, if fileName cannot be found on host
	cnt = DbgReadFile(fileName, 0, (char *)rfeBistReferenceData, sizeof(rfeBistReferenceData) );

	// Check if we could at least read sufficient bytes from file to fill the structure.
	// Also do this, in case the unique Id of the first entry is zero
	if (cnt != sizeof(rfeBistReferenceData) || rfeBistReferenceData[0].rfeHwId==0) {
		/* unable to read data correctly, set update flag*/
		gUpdateBistZeroHourReferenceFlag = 1;
	}
}

void ExampleRfeCheckIdMatch()
{
	uint8_t rfeIdx;
	for (rfeIdx = 0; rfeIdx < gAppConfig.nrFrontends; rfeIdx++)
	{
		if ((rfeSwHwVersionInfo[rfeIdx].hwUniqueId == 0) || (rfeBistReferenceData[rfeIdx].rfeHwId==0 ) ||
  			      (rfeSwHwVersionInfo[rfeIdx].hwUniqueId != rfeBistReferenceData[rfeIdx].rfeHwId) )
		{
			gUpdateBistZeroHourReferenceFlag = 1;

			/* If there is a mismatch between HW ID and saved ID, application needs to deal with it
			 * In this example, the action is to update the measurement for zero hour BIST data*/
			DbgPrintMsg("RFE%d BIST ZeroHour UID mismatch - file: 0x%08x vs. rfe: 0x%08x\n",rfeIdx,
					rfeBistReferenceData[rfeIdx].rfeHwId, rfeSwHwVersionInfo[rfeIdx].hwUniqueId);
		}
	}
}

void ExampleRfeBlobSetBistReference(void)
{
	uint8_t rfeIdx;
	Cdd_RfeRxBistZeroHourRefDataType *pRefData = NULL_PTR;

	for (rfeIdx=0; rfeIdx < gAppConfig.nrFrontends; rfeIdx++)
	{
		pRefData = &(rfeBistReferenceData[rfeIdx].bistZeroHour);

		if (ppRfeConfigs[rfeIdx] != NULL_PTR && pRefData != NULL_PTR)
		{
			if(CDD_Rfe_SetBlobValue(ppRfeConfigs[rfeIdx], rfeCfg_section_monitorAndSafety_e, rfeCfg_param_monitorAndSafety_zeroHrRefForRxPhaseDiffLna_rx1_rx2_e, pRefData->refPh[0][TEF82XX_RFBIST_LNA_TEST]) != E_OK)
			{
				PrintError("CDD_Rfe_SetBlobValue()\n");
			}
			if(CDD_Rfe_SetBlobValue(ppRfeConfigs[rfeIdx], rfeCfg_section_monitorAndSafety_e, rfeCfg_param_monitorAndSafety_zeroHrRefForRxPhaseDiffLna_rx1_rx3_e, pRefData->refPh[1][TEF82XX_RFBIST_LNA_TEST])!= E_OK)
			{
				PrintError("CDD_Rfe_SetBlobValue()\n");
			}
			if(CDD_Rfe_SetBlobValue(ppRfeConfigs[rfeIdx], rfeCfg_section_monitorAndSafety_e, rfeCfg_param_monitorAndSafety_zeroHrRefForRxPhaseDiffLna_rx1_rx4_e, pRefData->refPh[2][TEF82XX_RFBIST_LNA_TEST])!= E_OK)
			{
				PrintError("CDD_Rfe_SetBlobValue()\n");
			}
			if(CDD_Rfe_SetBlobValue(ppRfeConfigs[rfeIdx], rfeCfg_section_monitorAndSafety_e, rfeCfg_param_monitorAndSafety_zeroHrRefForRxGainDiffLna_rx1_rx2_e, pRefData->refMag[0][TEF82XX_RFBIST_LNA_TEST])!= E_OK)
			{
				PrintError("CDD_Rfe_SetBlobValue()\n");
			}
			if(CDD_Rfe_SetBlobValue(ppRfeConfigs[rfeIdx], rfeCfg_section_monitorAndSafety_e, rfeCfg_param_monitorAndSafety_zeroHrRefForRxGainDiffLna_rx1_rx3_e, pRefData->refMag[1][TEF82XX_RFBIST_LNA_TEST])!= E_OK)
			{
				PrintError("CDD_Rfe_SetBlobValue()\n");
			}
			if(CDD_Rfe_SetBlobValue(ppRfeConfigs[rfeIdx], rfeCfg_section_monitorAndSafety_e, rfeCfg_param_monitorAndSafety_zeroHrRefForRxGainDiffLna_rx1_rx4_e, pRefData->refMag[2][TEF82XX_RFBIST_LNA_TEST])!= E_OK)
			{
				PrintError("CDD_Rfe_SetBlobValue()\n");
			}
			if(CDD_Rfe_SetBlobValue(ppRfeConfigs[rfeIdx], rfeCfg_section_monitorAndSafety_e, rfeCfg_param_monitorAndSafety_zeroHrRefForRxPhaseDiffMixer_rx1_rx2_e, pRefData->refPh[0][TEF82XX_RFBIST_MIXER_TEST])!= E_OK)
			{
				PrintError("CDD_Rfe_SetBlobValue()\n");
			}
			if(CDD_Rfe_SetBlobValue(ppRfeConfigs[rfeIdx], rfeCfg_section_monitorAndSafety_e, rfeCfg_param_monitorAndSafety_zeroHrRefForRxPhaseDiffMixer_rx1_rx3_e, pRefData->refPh[1][TEF82XX_RFBIST_MIXER_TEST])!= E_OK)
			{
				PrintError("CDD_Rfe_SetBlobValue()\n");
			}
			if(CDD_Rfe_SetBlobValue(ppRfeConfigs[rfeIdx], rfeCfg_section_monitorAndSafety_e, rfeCfg_param_monitorAndSafety_zeroHrRefForRxPhaseDiffMixer_rx1_rx4_e, pRefData->refPh[2][TEF82XX_RFBIST_MIXER_TEST])!= E_OK)
			{
				PrintError("CDD_Rfe_SetBlobValue()\n");
			}
			if(CDD_Rfe_SetBlobValue(ppRfeConfigs[rfeIdx], rfeCfg_section_monitorAndSafety_e, rfeCfg_param_monitorAndSafety_zeroHrRefForRxGainDiffMixer_rx1_rx2_e, pRefData->refMag[0][TEF82XX_RFBIST_MIXER_TEST])!= E_OK)
			{
				PrintError("CDD_Rfe_SetBlobValue()\n");
			}
			if(CDD_Rfe_SetBlobValue(ppRfeConfigs[rfeIdx], rfeCfg_section_monitorAndSafety_e, rfeCfg_param_monitorAndSafety_zeroHrRefForRxGainDiffMixer_rx1_rx3_e, pRefData->refMag[1][TEF82XX_RFBIST_MIXER_TEST])!= E_OK)
			{
				PrintError("CDD_Rfe_SetBlobValue()\n");
			}
			if(CDD_Rfe_SetBlobValue(ppRfeConfigs[rfeIdx], rfeCfg_section_monitorAndSafety_e, rfeCfg_param_monitorAndSafety_zeroHrRefForRxGainDiffMixer_rx1_rx4_e, pRefData->refMag[2][TEF82XX_RFBIST_MIXER_TEST])!= E_OK)
			{
				PrintError("CDD_Rfe_SetBlobValue()\n");
			}
		}
	}
}

void ExampleRfeConfigureWithBist(void)
{
	uint8 rfeIdx=0;
	Cdd_RfeRxBistZeroHourRefDataType bistRef[RFE_NUM_USED_FRONT_ENDS] = {0};
	gUpdateBistZeroHourReferenceFlag = 0;

	// Obtain SwHwVersionInfo (if not done yet) for Unique ID
	if (rfeSwHwVersionInfo[0].hwUniqueId == 0)
		ExampleRfeHwSwVersionCheck();

	// Get Zero-Hour Reference data for RFBIST from file or NVM storage
	ExampleRfeIdAndBistRefGetNvm();

	// Check RFE Hardware Unique IDs to match against Reference Data Ids
	ExampleRfeCheckIdMatch();

	/* Set zero hour BIST reference data in config blob prior to sending it to RFE core
	 * In case gUpdateBistZeroHourReferenceFlag is set, the operation is not necessary,
	 *  but for testing purposes this is done either way */
	ExampleRfeBlobSetBistReference();

	// Configure the RFEs
	ExampleRfeConfigure();

	// Configure CSI2 Receiver
	ExampleCsi2Init();

	if (gUpdateBistZeroHourReferenceFlag)
	{
		// Select Frontend
		if(CDD_Rfe_SetFrontEnd(CDD_RFE_FRONT_END_LEADER) != E_OK)
		{
			PrintError("CDD_Rfe_SetFrontEnd(Leader)\n");
		}

		// CDD_Rfe_GetBistZeroHourReferenceData() will return T0 data for all RFEs
		if (CDD_Rfe_GetBistZeroHourReferenceData(bistRef) != E_OK)
		{
			PrintError("CDD_Rfe_GetBistZeroHourReferenceData()\n");
		} else {
			// Copy data back to rfeBistReferenceData[] structure
			DbgPrintMsg("Rfe - CDD_Rfe_GetBistZeroHourReferenceData(): ok\n");
			for  (rfeIdx = 0; rfeIdx < gAppConfig.nrFrontends; rfeIdx++)
			{
				// Copy T0 data and Unique ID to each member of reBistReferenceData[]
				memcpy( &(rfeBistReferenceData[rfeIdx].bistZeroHour),  &bistRef[rfeIdx], sizeof(Cdd_RfeRxBistZeroHourRefDataType) );
				rfeBistReferenceData[rfeIdx].rfeHwId = rfeSwHwVersionInfo[rfeIdx].hwUniqueId;
			}
			DbgPrintMsg("Rfe - Copied BIST data Rfe: ok\n");
		}
		
		/* Update zero hour reference data for BIST in configuration blob*/
		ExampleRfeBlobSetBistReference();

		/* Reconfigure RFE with updated blob. Sending only BIST reference values to M7_1 via Cdd_RfeParamUpdateType() function is not yet available*/
		ExampleRfeConfigure();

		// Store Zero-hour RF BIST data back to NVM/File
		ExampleRfeIdAndBistRefSetNvm();

		// Reset flag 
		gUpdateBistZeroHourReferenceFlag = 0;
	}
}

void ExampleRfeConfigure(void)
{

	uint8_t rfeIdx = 0;
	rfe_state_t leaderReferenceState = CDD_Rfe_GetState();

	// Starting with Leader, send configuration to each RFE.
	// Note: will not change state between frontends, until all configs are sent
	for (rfeIdx=0; rfeIdx < gAppConfig.nrFrontends; rfeIdx++)
	{
		DbgPrintMsg("Rfe - Send configuration RFE %d:\n", rfeIdx);

		if(CDD_Rfe_SetFrontEnd((CDD_RfeFrontEndHierarchyType)rfeIdx) != E_OK)
		{
	        PrintError("SetFrontEnd()\n");
		}
		else
		{
	        DbgPrintMsg("CDD_Rfe_SetFrontEnd ok\n");
		}

		// Send Configuration to Rfe
		if (CDD_Rfe_Configure(ppRfeConfigs[rfeIdx], ppDynTbls[rfeIdx]) != E_OK )
		{
			PrintError("Configure\n");
		}

		// Cascaded quirk: If in cascaded state, the M7_1 stays in 'reference'state, until all
		//  two/four RFE are Configured. Only after the 2nd/4th RfeConfigure, will we go to 'configured'
		if (rfeIdx < (gAppConfig.nrFrontends-1))  {
			ExampleRfeWaitForState(leaderReferenceState);
		} else {
			// Wait for configuration to complete
			ExampleRfeWaitForState(rfe_state_configured_e);
		}

		ExampleCsi2ErrorCheck();
	}
	DbgPrintMsg("Rfe - Configuration done!\n");
}

void RsdkSptBufferSizeCalc(void)
{
	uint16_t nrStrVectCh = (gAppConfig.specific.nrVirtAnt == 4) ? 8 : gAppConfig.specific.nrVirtAnt; /* Steer vectors are padded up to 8 when using 4RX due to SPT DOA implementation*/
	uint32_t rdmSamples = gAppConfig.specific.nrRangeBins * gAppConfig.specific.nrDopplerBins;
	uint32_t cubeSamples = rdmSamples * gAppConfig.specific.nrVirtAnt;

	rsdkBufferSize.sptRangeTwd   = sizeof(uint32_t) * gAppConfig.specific.rFftSize;
	rsdkBufferSize.sptDopplerTwd = sizeof(uint32_t) * gAppConfig.specific.dFftSize;
	rsdkBufferSize.spt3dFftTwd   = sizeof(uint32_t) * 16;
	rsdkBufferSize.sptRangeWin   = sizeof(uint16_t) * gAppConfig.specific.rFftSize;
	rsdkBufferSize.sptDopplerWin = sizeof(uint16_t) * gAppConfig.specific.dFftSize;
	rsdkBufferSize.sptSteerVect  = sizeof(uint32_t) * RSDK_SPT_DBFDOA_BEAMS_NUM * nrStrVectCh;
	rsdkBufferSize.sptMimoDeRot  = sizeof(uint32_t) * gAppConfig.specific.nrDopplerBins * (gAppConfig.specific.nrTxMimo - 1);
	rsdkBufferSize.sptRangeIn    = sizeof(uint16_t) * gAppConfig.rfeSettings.nrSamplesPerChirp * RSDK_NR_RX_PER_FRONTEND * RSDK_SPT_DOUBLE_BUFFER;
	rsdkBufferSize.sptRadarCube  = sizeof(uint32_t) * cubeSamples / gAppConfig.specific.cpRate;
	rsdkBufferSize.sptRDM        = sizeof(uint16_t) * rdmSamples;
	rsdkBufferSize.sptHistOut    = sizeof(uint16_t) * gAppConfig.specific.nrRangeBins * RSDK_SPT_HIST_BINS;
	rsdkBufferSize.sptThreshold  = sizeof(uint16_t) * gAppConfig.specific.nrRangeBins;
	rsdkBufferSize.sptPeakDetScratch = sizeof(uint32_t) * rdmSamples;
	rsdkBufferSize.sptPeakDetOut = RSDK_SPT_PEAK_BITMAP_PACK_SIZE(rdmSamples);
	rsdkBufferSize.peakInd       = sizeof(uint16_t) * RSDK_SPT_DBFDOA_PEAKS_NUM;
	rsdkBufferSize.sptDbfDoaIn   = sizeof(uint32_t) * RSDK_SPT_DBFDOA_PEAKS_NUM * gAppConfig.specific.nrVirtAnt / gAppConfig.specific.cpRate;
	rsdkBufferSize.sptDbfDoaOut  = sizeof(uint32_t) * RSDK_SPT_DBFDOA_BEAMS_NUM * RSDK_SPT_DBFDOA_PEAKS_NUM;
}

//==========================================================
// SPT Memory Initialization
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
	AppMemAllocBuffer(pHeapMem, &gDbfSteeringVectorsBufH, sizeof(uint32_t) * RSDK_SPT_DBF64_8CH_STEERVECT_BUF_SIZE,
                  	  CACHE_LINE_SIZE, RSDK_OALMEM_CHUNK_ID_SPT_DATA);


	memset(&sptContext, 0, sizeof(sptContext));

    sptContext.kernelCodeAddr = (uintptr_t)gSptModuleCodeRelocBufH.phyAddr;

    sptContext.opMode = SPT_OP_MODE;




    sptContext.kernelRetPar = NULL;  //this kernel has no return value
    sptContext.checkKernelWatermark = CHECK_KERNEL_WATERMARK;

    //first SPT Kernel to be run is the initialization of Range & Doppler FFTs for the 128chirps x 512 samples use case
    RelocSptCode(gSptModuleCodeRelocBufH.virtAddr, RsdkSptInit512smp128crp8ch, RSDK_SPT_GET_KERNEL_SIZE(RsdkSptInit512smp128crp8ch));

    //SPT parameter list:

    paramType = SPT_PARAM_TYPE_ADDR;




    sptContext.kernelParList[np].paramType = paramType;
    sptContext.kernelParList[np++].paramValue = (uintptr_t)(gFft512TwiddleFactorsBufH.phyAddr);
    sprintf(fileName, "%s%s", AUX_IN_PATH, "fft512_twiddle_factors.dat");
    DbgReadFileConvert(fileName, 0, (char *)gFft512TwiddleFactorsBufH.virtAddr, gFft512TwiddleFactorsBufH.numBytes, ENDIAN_CHANGE, DATA_BUFF_IS_CACHED);

    sptContext.kernelParList[np].paramType = paramType;
    sptContext.kernelParList[np++].paramValue = (uintptr_t)gFft128TwiddleFactorsBufH.phyAddr;
    sprintf(fileName, "%s%s", AUX_IN_PATH, "fft128_twiddle_factors.dat");
    DbgReadFileConvert(fileName, 0, (char *)gFft128TwiddleFactorsBufH.virtAddr, gFft128TwiddleFactorsBufH.numBytes, ENDIAN_CHANGE, DATA_BUFF_IS_CACHED);

    sptContext.kernelParList[np].paramType = paramType;
    sptContext.kernelParList[np++].paramValue = (uintptr_t)gFft512BlackmanWindowBufH.phyAddr;
    sprintf(fileName, "%s%s", AUX_IN_PATH, "fft512_win_blackman.dat");
    DbgReadFileConvert(fileName, 0, (char *)gFft512BlackmanWindowBufH.virtAddr, gFft512BlackmanWindowBufH.numBytes, ENDIAN_CHANGE, DATA_BUFF_IS_CACHED);

    sptContext.kernelParList[np].paramType = paramType;
    sptContext.kernelParList[np++].paramValue = (uintptr_t)gFft128BlackmanWindowBufH.phyAddr;
    sprintf(fileName, "%s%s", AUX_IN_PATH, "fft128_win_blackman.dat");
    DbgReadFileConvert(fileName, 0, (char *)gFft128BlackmanWindowBufH.virtAddr, gFft128BlackmanWindowBufH.numBytes, ENDIAN_CHANGE, DATA_BUFF_IS_CACHED);

    sptContext.kernelParList[np].paramType = paramType;
    sptContext.kernelParList[np++].paramValue = (uintptr_t)gFft16TwiddleFactorsBufH.phyAddr;
    sprintf(fileName, "%s%s", AUX_IN_PATH, "fft16_twiddle_factors.dat");
    DbgReadFileConvert(fileName, 0, (char *)gFft16TwiddleFactorsBufH.virtAddr, gFft16TwiddleFactorsBufH.numBytes, ENDIAN_CHANGE, DATA_BUFF_IS_CACHED);

    /* Hardcoded for 8 channels */
    sptContext.kernelParList[np].paramType = paramType;
    sptContext.kernelParList[np++].paramValue = (uintptr_t)gDbfSteeringVectorsBufH.phyAddr;
    sprintf(fileName, "%s%s%d%s", AUX_IN_PATH, "dbf_8ch_64angles_",gAppConfig.spSettings.dbfFov ,"fov.dat");
    DbgReadFileConvert(fileName, 0, (char *)gDbfSteeringVectorsBufH.virtAddr, gDbfSteeringVectorsBufH.numBytes, ENDIAN_CHANGE, DATA_BUFF_IS_CACHED);


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
    //multiple times without re-initialization, provided that no error occurs during execution.

    DbgPrintMsg("Initialized SPT kernels\n");
}

void ExampleTriggerRangeProcessing(uint16_t frame)
{
	uint16_t     np;
	rsdkStatus_t rsdkStatus;
	Spt_DriverContextType sptContext;

	/* Init SPT runtime context for Range FFT Kernel */
	sptContext.kernelCodeAddr = gSptKernelAddr.rangeFft;
	sptContext.opMode = SPT_OP_MODE;
	sptContext.kernelRetPar = NULL;  /* This kernel has no return value */
	sptContext.checkKernelWatermark = CHECK_KERNEL_WATERMARK;

	np = 0;

	sptContext.kernelParList[np].paramType = SPT_PARAM_TYPE_ADDR;
	sptContext.kernelParList[np++].paramValue = (uintptr_t)gAdcSample0BufH.phyAddr;

    if (gAppConfig.nrFrontends == 2)
    {
    	sptContext.kernelParList[np].paramType = SPT_PARAM_TYPE_ADDR;
    	sptContext.kernelParList[np++].paramValue = (uintptr_t)gAdcSample1BufH.phyAddr;
    }

	sptContext.kernelParList[np].paramType = SPT_PARAM_TYPE_ADDR;
	sptContext.kernelParList[np++].paramValue = (uintptr_t)gRadarCubeResultsBufH.phyAddr;

	sptContext.kernelParList[np].paramType = SPT_PARAM_TYPE_VALUE;
	sptContext.kernelParList[np++].paramValue = 4;

	sptContext.kernelParList[np].paramType = SPT_PARAM_TYPE_LAST;

	currentError = 0; /* Reset SPT error counter*/
	evtIntNum = 0;    /* Reset SPT event counter*/

	/* Trigger Range FFT Kernel - SPT will wait for data*/
	rsdkStatus = Spt_Run(&sptContext);
	statusCheck("RsdkSptRun", rsdkStatus);

}

void ExampleWaitRangeProcess(uint16_t frame)
{

	/* Wait for range processing finish. Print SPT errors if any */
	WaitForSPT(SPT_OP_MODE_NONBLOCK);
	for (int i = 0; i < currentError; i++)
	{
		DbgPrintMsg("SptEcsIsrCb error!, Status: 0x%X, Error info: 0x%X\n", isrStatusQueue[i], (unsigned int)errInfoQueue[i]);
	}

	/* last frame */
	if (frame == gAppConfig.acqNrFrames - 1)
	{
		/* Output Range data */
		sprintf(fileName, "%s%s", OUT_PATH, "rfft_out.dat");
		DbgWriteFileConvert(fileName, (char *)gRadarCubeResultsBufH.virtAddr, gRadarCubeResultsBufH.numBytes, ENDIAN_CHANGE, DATA_BUFF_IS_CACHED);
	}
}

void ExampleAcqBuffInit(void)
{
    uint16_t csi2StatsBuffSize;

    /* Calculate acquisition buffer size for current configuration */
    if (gAppConfig.spSettings.enableRadarProcessing)
    {
    	gAppConfig.specific.acqBuffNrChirps = RSDK_SPT_DOUBLE_BUFFER;  /* Range processing on SPT uses double buffering on chirps */
    }
    else
    {
    	gAppConfig.specific.acqBuffNrChirps = gAppConfig.rfeSettings.nrChirpsInFrame; /* For acquisition only, save entire frame in memory */
    }

    if (gAppConfig.csi2StatsEnable)
    {
    	csi2StatsBuffSize = CSI2_LINE_STAT_LENGTH;
    }
    else
    {
    	csi2StatsBuffSize = 0;
    }

    rsdkBufferSize.singleChirpSize = sizeof(uint16_t) * gAppConfig.rfeSettings.nrSamplesPerChirp * RSDK_NR_RX_PER_FRONTEND + csi2StatsBuffSize;
    rsdkBufferSize.adcSampleBuff = rsdkBufferSize.singleChirpSize * gAppConfig.specific.acqBuffNrChirps;
    rsdkBufferSize.fullAdcSampleBuff = gAppConfig.nrFrontends * rsdkBufferSize.adcSampleBuff;

    if (gAppConfig.spSettings.enableRadarProcessing)
    {
    	/* Default buffer usage*/
    	gAdcSample0BufH.phyAddr = (int8_t *)gAdcDataBuff0;
    	gAdcSample0BufH.virtAddr = gAdcSample0BufH.phyAddr;
    	gAdcSample0BufH.numBytes = rsdkBufferSize.adcSampleBuff;

    	if (gAppConfig.nrFrontends == 2)
    	{
    		gAdcSample1BufH.phyAddr = (int8_t *)gAdcDataBuff1;
    		gAdcSample1BufH.virtAddr = gAdcSample1BufH.phyAddr;
    		gAdcSample1BufH.numBytes = rsdkBufferSize.adcSampleBuff;
    	}
    }
    else
    {
    	for(uint16_t seq = 0; seq<gAppConfig.rfeSettings.nrSequences; seq++)
    	{
    	   uint32_t chirpSize = sizeof(uint16_t) * gAppConfig.rfeSettings.seqProfileSampleCount[seq] * RSDK_NR_RX_PER_FRONTEND;
    	   uint32_t seqSize = gAppConfig.rfeSettings.seqChirpCount[seq]*chirpSize;

			AppMemAllocBuffer(pHeapMem, &gCascadedAdcSampleBufH[seq], gAppConfig.nrFrontends*seqSize, UNUSED_PARAM, UNUSED_PARAM);

    		for(uint16_t rfe = 0; rfe< gAppConfig.nrFrontends; rfe++)
    		{
    			gAdcSampleBufH[rfe][seq].phyAddr = &gCascadedAdcSampleBufH[seq].phyAddr[rfe*seqSize];
    			gAdcSampleBufH[rfe][seq].virtAddr = gAdcSampleBufH[rfe][seq].phyAddr;
    			gAdcSampleBufH[rfe][seq].numBytes = seqSize;
    		}
    	}
    }

}

void ExampleAcqBuffClear(void)
{
	if (gAppConfig.spSettings.enableRadarProcessing)
	{
		AppMemFreeBuffer(pHeapMem, &gFullAdcSampleBufferBufH);
	}
	else
	{
		for(uint16_t i = 1; i<=gAppConfig.rfeSettings.nrSequences; i++)
		{
			uint16_t seq = gAppConfig.rfeSettings.nrSequences-i;
			AppMemFreeBuffer(pHeapMem, &gCascadedAdcSampleBufH[seq]);
		}
	}
}

static rsdkStatus_t ThresholdCompute(uint16_t *histBuff, uint16_t *threshBuff, int16_t nrRangeBins, uint16_t thresholdScale, int16_t pointsAroundMax)
{

    rsdkStatus_t status;
    int16_t      i, j;
    int16_t      maxInd;
    uint16_t     maxVal;
	uint16_t 	 maxBinIndex;
    uint16_t	 histBinIndex;
	uint16_t 	 sptHistBinIndex;
    uint16_t *   cHist;
    float		 wAcc, wSum, wAvg;
    int16_t      histGuard = pointsAroundMax/2; // keeps the bins around max within histogram boundaries
    int16_t		 lowerBin, upperBin;

    if ((histBuff == NULL) || (threshBuff == NULL))
    {
        status = RSDK_INVALID_PARAMETER;
    }
    else
    {
        /* Compute separate threshold for each range bin*/
        for (i = 0; i < nrRangeBins; i++)
        {

        	cHist = &histBuff[i * RSDK_SPT_HIST_BINS];

            maxVal = cHist[histGuard];
            maxInd = histGuard;

            /* Find index of first max value in SPT histogram*/
            for (j = histGuard; j < RSDK_SPT_HIST_BINS - histGuard; j++)
            {
                if(cHist[j] > maxVal)
                {
                    maxVal = cHist[j];
                    maxInd = j;
                }
            }

        	/* Note that SPT histogram's even and odd bins are swapped*/
            maxBinIndex = maxInd ^ 0x0001; //Index of the max bin

            wAcc = 0;
            wSum = 0;

            lowerBin = maxBinIndex - histGuard;
            upperBin = maxBinIndex + (pointsAroundMax - histGuard);

            /* Weighted Average of histogram's max and a number of bins around it given by pointsAroundMax*/
            for(histBinIndex = lowerBin; histBinIndex <= upperBin; histBinIndex++)
            {
            	/* Swap to get SPT histogram index*/
            	sptHistBinIndex = histBinIndex ^ 0x0001;

				wSum += (float)cHist[sptHistBinIndex];
				wAcc += (float)(cHist[sptHistBinIndex] * histBinIndex);
            }

            wAvg = wAcc / wSum; // noise estimate's log2 value for current range bin

            threshBuff[i] = ((uint16_t)(wAvg * 256)) + thresholdScale; // Convert noise estimate from float to 7Q8 integer

        }

        status = RSDK_SUCCESS;
    }
    return status;
}

/*==========================================================
  Implements radar signal processing chain
  Input  : current frame number
==========================================================*/
void ExampleAcqPostProc(uint16_t frame)
{
	Spt_DriverContextType  sptContext;
    uint16_t                np;
    Spt_ParamType paramType;
    Spt_DspCmdType dspCmd;
    Spt_DriverCommandType sptCmd;
    Spt_DriverCmdResType sptCmdResult;
    rsdkStatus_t            sptStatus = RSDK_SUCCESS;
    rsdkStatus_t            appStatus;
    rsdkBufHandle_t         gRdmBufferBufH;          /* Used for Range-Doppler-Magnitude matrix */
    rsdkBufHandle_t         gScratchBufH;            /* Used for scratch memory */
    rsdkBufHandle_t         gPeakSearchResultsBufH;  /* Stores 2D/3D Peak Search results */
    rsdkBufHandle_t         gThresholdBufH;          /* Stores the thresholds for 2D/3D Peak Search */
    rsdkBufHandle_t         gHistResultsBufH;        /* Stores the Histogram output */
    rsdkBufHandle_t         gCaCfarResultsBufH;      /* Stores output of CFAR */
    rsdkBufHandle_t         caCfarParamsBufH;
    rsdkBufHandle_t 		gPeakAntennaDataBufH;    /* Stores the antenna data extracted from the radar cube based on RDM peaks*/
    rsdkBufHandle_t 		gBeamscans;    		     /* Stores Digital Beamform output */

    rsdkBbe32CaCfarParams_t *pCaCfarParams;

    int16_t pointsAroundMax;							 // number of histogram bins used for noise estimation

    uint16_t detAntDataSize;						 /* Buffer size of extracted antenna data*/
    uint16_t detBeamscansSize;						 /* Buffer size of beamscans */

    AppMemAllocBuffer(pHeapMem, &gRdmBufferBufH,         rsdkBufferSize.sptRDM,            CACHE_LINE_SIZE, RSDK_OALMEM_CHUNK_ID_SPT_DATA);
    AppMemAllocBuffer(pHeapMem, &gScratchBufH,           rsdkBufferSize.sptPeakDetScratch, CACHE_LINE_SIZE, RSDK_OALMEM_CHUNK_ID_SPT_DATA);
    AppMemAllocBuffer(pHeapMem, &gPeakSearchResultsBufH, rsdkBufferSize.sptPeakDetOut,     CACHE_LINE_SIZE, RSDK_OALMEM_CHUNK_ID_SPT_DATA);
    AppMemAllocBuffer(pHeapMem, &gThresholdBufH,         rsdkBufferSize.sptThreshold,      CACHE_LINE_SIZE, RSDK_OALMEM_CHUNK_ID_SPT_DATA);
    AppMemAllocBuffer(pHeapMem, &gHistResultsBufH,       rsdkBufferSize.sptHistOut,        CACHE_LINE_SIZE, RSDK_OALMEM_CHUNK_ID_SPT_DATA);
    AppMemAllocBuffer(pHeapMem, &gCaCfarResultsBufH,     rsdkBufferSize.sptPeakDetOut,     CACHE_LINE_SIZE, RSDK_OALMEM_CHUNK_ID_SPT_DATA);
    AppMemAllocBuffer(pHeapMem, &gPeakAntennaDataBufH,   rsdkBufferSize.sptDbfDoaIn,       CACHE_LINE_SIZE, RSDK_OALMEM_CHUNK_ID_SPT_DATA);
    AppMemAllocBuffer(pHeapMem, &gBeamscans,   			 rsdkBufferSize.sptDbfDoaOut,      CACHE_LINE_SIZE, RSDK_OALMEM_CHUNK_ID_SPT_DATA);

    /*--------------------------------------------------------------------------------------*/
    /* ------------------------ DOPPLER FFT SPT Kernel -------------------------------------*/
    /*--------------------------------------------------------------------------------------*/

    /* Init SPT runtime context*/
    sptContext.kernelCodeAddr = gSptKernelAddr.dopplerFft;
    sptContext.opMode         = SPT_OP_MODE;
    sptContext.kernelRetPar   = NULL;  /* This kernel has no return value */
    sptContext.checkKernelWatermark = CHECK_KERNEL_WATERMARK;
    np = 0;

    sptContext.kernelParList[np].paramType = SPT_PARAM_TYPE_ADDR;
    sptContext.kernelParList[np++].paramValue = (uintptr_t)gRadarCubeResultsBufH.phyAddr;

    sptContext.kernelParList[np].paramType = SPT_PARAM_TYPE_ADDR;
    sptContext.kernelParList[np++].paramValue = (uintptr_t)gRadarCubeResultsBufH.phyAddr;

    sptContext.kernelParList[np].paramType = SPT_PARAM_TYPE_VALUE;
    sptContext.kernelParList[np++].paramValue = gAppConfig.spSettings.scalingDoppler;

    sptContext.kernelParList[np].paramType = SPT_PARAM_TYPE_LAST;

    DbgPrintMsg("Running Doppler FFT Kernel...\n");
    ExampleLaunchSptKernel(&sptContext);

    /* Output Doppler data */
    sprintf(fileName, "%s%s", OUT_PATH, "dfft_out.dat");
    DbgWriteFileConvert(fileName, (char *)gRadarCubeResultsBufH.virtAddr, gRadarCubeResultsBufH.numBytes, ENDIAN_CHANGE, DATA_BUFF_IS_CACHED);

    /*--------------------------------------------------------------------------------------*/
    /* ------------------------ NON COHERENT COMBINING SPT Kernel --------------------------*/
    /*--------------------------------------------------------------------------------------*/

    /* Overwrite only fields that are changing in SPT runtime context - kernel address and kernel param list*/
    sptContext.kernelCodeAddr = gSptKernelAddr.antComb;

    sptContext.kernelParList[0].paramType = SPT_PARAM_TYPE_ADDR;
    sptContext.kernelParList[0].paramValue = (uintptr_t)gRadarCubeResultsBufH.phyAddr;

    sptContext.kernelParList[1].paramType = SPT_PARAM_TYPE_ADDR;
    sptContext.kernelParList[1].paramValue = (uintptr_t)gRdmBufferBufH.phyAddr;

    sptContext.kernelParList[2].paramType = SPT_PARAM_TYPE_ADDR;
    sptContext.kernelParList[2].paramValue = (uintptr_t)gHistResultsBufH.phyAddr;

    sptContext.kernelParList[3].paramType = SPT_PARAM_TYPE_LAST;

    DbgPrintMsg("Running Non Coherent Combining Kernel...\n");
    ExampleLaunchSptKernel(&sptContext);

    /* Output antenna combining data*/
    sprintf(fileName, "%s%s", OUT_PATH, "ncc_out.dat");
    DbgWriteFileConvert(fileName, (char *)gRdmBufferBufH.virtAddr, gRdmBufferBufH.numBytes, ENDIAN_CHANGE, DATA_BUFF_IS_CACHED);

    /*--------------------------------------------------------------------------------------*/
    /*--------------------------- PEAK SEARCH SPT Kernel -----------------------------------*/
    /*--------------------------------------------------------------------------------------*/

	// Hard coded weighted average of histogram's max and 4 bins around it
	pointsAroundMax = 4;
	appStatus = ThresholdCompute((uint16_t *) &gHistResultsBufH.virtAddr[0], (uint16_t *)&gThresholdBufH.virtAddr[0],gAppConfig.specific.nrRangeBins,
            					gAppConfig.spSettings.histThresholdFactor, pointsAroundMax);
	statusCheck("Compute threshold for peak search", appStatus);

    sptContext.kernelCodeAddr = gSptKernelAddr.peakSearch;

    /* Input to peak search is RD Magnitude Matrix*/
    sptContext.kernelParList[0].paramType = SPT_PARAM_TYPE_ADDR;
    sptContext.kernelParList[0].paramValue = (uintptr_t)gRdmBufferBufH.phyAddr;

    /* Threhsold factor; use thr = 0 to get only local peaks, without thresholding*/
    sptContext.kernelParList[1].paramType = SPT_PARAM_TYPE_ADDR;
    sptContext.kernelParList[1].paramValue = (uintptr_t)gThresholdBufH.phyAddr;

    /* Scratch buffer */
    sptContext.kernelParList[2].paramType = SPT_PARAM_TYPE_ADDR;
    sptContext.kernelParList[2].paramValue = (uintptr_t)gScratchBufH.phyAddr;

    /* Output buffer */
    sptContext.kernelParList[3].paramType = SPT_PARAM_TYPE_ADDR;
    sptContext.kernelParList[3].paramValue = (uintptr_t)gPeakSearchResultsBufH.phyAddr;

    sptContext.kernelParList[4].paramType = SPT_PARAM_TYPE_LAST;

    DbgPrintMsg("Running SPT Peak search  Kernel...\n");
    ExampleLaunchSptKernel(&sptContext);

    /* Output peak search bitmap */
    sprintf(fileName, "%s%s", OUT_PATH, "ps_out.dat");
    DbgWriteFileConvert(fileName, (char *)gPeakSearchResultsBufH.virtAddr, gPeakSearchResultsBufH.numBytes, ENDIAN_CHANGE, DATA_BUFF_IS_CACHED);

#if ((defined(S32R41)) && defined(DSP_ENABLE))
    /*--------------------------------------------------------------------------------------*/
    /*--------------------------- CA-CFAR DSP SPT Kernel -----------------------------------*/
    /*--------------------------------------------------------------------------------------*/

    AppMemAllocBuffer(pHeapMem, &caCfarParamsBufH, sizeof(rsdkBbe32CaCfarParams_t), CACHE_LINE_SIZE,
                      RSDK_OALMEM_CHUNK_ID_SRAM);
    pCaCfarParams = (rsdkBbe32CaCfarParams_t *)caCfarParamsBufH.virtAddr;

    pCaCfarParams->rangeBins = NUM_SAMPLES_PER_CHIRP_PROF_0 / 2;
    pCaCfarParams->dopplerBins = NUM_CHIRPS;

    pCaCfarParams->windowSize = 5;
    pCaCfarParams->guardInterval = 2;
    pCaCfarParams->thresholdFactor = 500; //SPT Mag2Log2 format






    //User must make sure these addresses are accessible from BBE32 side.
    pCaCfarParams->pRdm = (uint32_t)(uintptr_t)gRdmBufferBufH.phyAddr;  /* BBE32 only supports 32-bit addresses - cast is legacy from A53 implementation */
    pCaCfarParams->pDetectBitmap = (uint32_t)(uintptr_t)gCaCfarResultsBufH.phyAddr;  //reuse the peak search buffers
    pCaCfarParams->pThr = (uint32_t)(uintptr_t)gScratchBufH.phyAddr;


    CacheFlush((const char *)caCfarParamsBufH.virtAddr, sizeof(rsdkBbe32CaCfarParams_t)); // The DSP reads data from SRAM


    dspCmd.id = (uint16_t)RSDK_DSP_GET_FUNC_ID(RsdkBbe32CaCfar);
    dspCmd.arg = (uint32_t)(uintptr_t)caCfarParamsBufH.phyAddr;

	sptCmd.cmdId = SPT_CMD_GEN_DSP_CMD_CRC;
	sptCmd.cmdParam = (Spt_DriverCommandParamType)&dspCmd;
    sptStatus = Spt_Command(&sptCmd, &sptCmdResult); //Legacy code: sptCmdResult is not used in this command, but must not be NULL





    statusCheck("RsdkSptGenCrcCommand", sptStatus);

    //--- Re-init SPT runtime context for SPT DSP CFAR Kernel ---------------------
    sptRetPar = 0;
    sptContext.kernelRetPar = &sptRetPar;
    sptContext.kernelCodeAddr = (uintptr_t)gSptModuleCodeRelocBufH.phyAddr;
    RelocSptCode(gSptModuleCodeRelocBufH.virtAddr, RsdkSptDspExampleIndirectBlocking, RSDK_SPT_GET_KERNEL_SIZE(RsdkSptDspExampleIndirectBlocking));


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

    DbgPrintMsg("Running DSP CFAR kernel...\n");
    ExampleLaunchSptKernel(&sptContext);

    sprintf(fileName, "%s%s", OUT_PATH, "caCfar_bmp_out.dat");
    DbgWriteFileConvert(fileName, (char *)gCaCfarResultsBufH.virtAddr, gCaCfarResultsBufH.numBytes, "word32", DATA_BUFF_IS_CACHED);
#endif

    DbgPrintMsg("Merge detects \n");
    MergeDetects((uint32_t *)gPeakSearchResultsBufH.virtAddr, (uint32_t *)gCaCfarResultsBufH.virtAddr,  gAppConfig.specific.nrRangeBins,  gAppConfig.specific.nrDopplerBins, (uint32_t *)gScratchBufH.virtAddr);

    /*-----------------------------------------------------------------------------------------------------*/
    /*-------------------------- DBF pre-processing - extract peak data from cube -------------------------*/
    /*-----------------------------------------------------------------------------------------------------*/

	DbgPrintMsg("Extract peak data \n");
	appStatus =  extractPeakData( gNrDetects, (uint32_t *)gScratchBufH.virtAddr, (uint32_t *)gRadarCubeResultsBufH.virtAddr, (uint32_t *)gPeakAntennaDataBufH.virtAddr, gAppConfig.specific.nrVirtAnt);
	statusCheck("Extract peak data status ", appStatus);

	/* 16 bits for the imaginary part and 16 bits for the real part. Total of 32 bits*/
	detAntDataSize = sizeof(uint32_t) * gAppConfig.specific.nrVirtAnt * gNrDetects; // in Bytes

	sprintf(fileName, "%s%s", OUT_PATH, "peak_ant_data.dat");
	DbgWriteFileConvert(fileName, (char *)gPeakAntennaDataBufH.virtAddr, detAntDataSize, ENDIAN_CHANGE, DATA_BUFF_IS_CACHED);

    /*-----------------------------------------------------------------------------------------------------*/
    /*--------------------------------------------- DBF/DOA -----------------------------------------------*/
    /*-----------------------------------------------------------------------------------------------------*/

	sptContext.kernelCodeAddr = gSptKernelAddr.beamForming;
	sptContext.opMode         = SPT_OP_MODE;
	sptContext.kernelRetPar   = NULL;  /* This kernel has no return value */
	sptContext.checkKernelWatermark = CHECK_KERNEL_WATERMARK;

	np = 0;

	sptContext.kernelParList[np].paramType = SPT_PARAM_TYPE_ADDR;
	sptContext.kernelParList[np++].paramValue = (uintptr_t)gPeakAntennaDataBufH.phyAddr;

	sptContext.kernelParList[np].paramType = SPT_PARAM_TYPE_ADDR;
	sptContext.kernelParList[np++].paramValue = (uintptr_t)gBeamscans.phyAddr;

	/* No processing after DBF. Threshold factor hardcoded to 0*/
	sptContext.kernelParList[np].paramType = SPT_PARAM_TYPE_VALUE;
	sptContext.kernelParList[np++].paramValue = 0;

	sptContext.kernelParList[np].paramType = SPT_PARAM_TYPE_LAST;

	DbgPrintMsg("Running Digital Beamforming Kernel...\n");
	ExampleLaunchSptKernel(&sptContext);

	/* 16 bits for detection Tag and 16 bits for Mag2log2 of each Doa bin. Total of 32 bits */
	detBeamscansSize = sizeof(uint32_t) * RSDK_SPT_DBFDOA_BEAMS_NUM * gNrDetects; // in Bytes

	/* Output beamscans*/
	sprintf(fileName, "%s%s", OUT_PATH, "beamscans.dat");
	DbgWriteFileConvert(fileName, (char *)gBeamscans.virtAddr, detBeamscansSize, "word32", DATA_BUFF_IS_CACHED);

    /* Free in reverse-allocation order, to be compatible with stand-alone RsdkHeap implementation */
    AppMemFreeBuffer(pHeapMem, (&gBeamscans));
    AppMemFreeBuffer(pHeapMem, (&gPeakAntennaDataBufH));
	AppMemFreeBuffer(pHeapMem, (&gCaCfarResultsBufH));
    AppMemFreeBuffer(pHeapMem, (&gHistResultsBufH));
    AppMemFreeBuffer(pHeapMem, (&gThresholdBufH));
    AppMemFreeBuffer(pHeapMem, (&gPeakSearchResultsBufH));
    AppMemFreeBuffer(pHeapMem, (&gScratchBufH));
    AppMemFreeBuffer(pHeapMem, (&gRdmBufferBufH));
#if ((defined(S32R41)) && defined(DSP_ENABLE))
    AppMemFreeBuffer(pHeapMem, (&caCfarParamsBufH));
#endif
}

void ExampleGetConfig(void)
{

#ifdef RFE_MODE_CASCADED
	gAppConfig.nrFrontends = RFE_NUM_USED_FRONT_ENDS;
#else
	gAppConfig.nrFrontends = 1;
#endif

#if !defined(APP_RUNTIME_CONFIG)
	/* Default app settings*/
	gAppConfig.acqNrFrames = 1;
	gAppConfig.appRunMode = RSDK_FIXED_FRAMES_MODE;

	gAppConfig.sessionCfg.numOfRuns = 1;

	gAppConfig.rfeSettings.samplingFrequency = 40000;
	gAppConfig.rfeSettings.nrSamplesPerChirp = 512;
	gAppConfig.rfeSettings.nrChirpsInFrame   = 128;
	gAppConfig.rfeSettings.nrChirpShapes     = 1;

	gAppConfig.csi2StatsEnable = CSI2_AUTODC_EVERY_LINE;

	gAppConfig.spSettings.enableRadarProcessing   	= RSDK_PROCESSING_ENABLE;
	gAppConfig.spSettings.radarProcessingChain    	= RSDK_SAMPLES512_CHIRPS128_8CH;
	gAppConfig.spSettings.antennaCombining        	= RSDK_NON_COH_COMB;
	gAppConfig.spSettings.histThresholdFactor     	= 768; /* log2 value in 7Q8 fromat */
	gAppConfig.spSettings.doaThesholdFactor       	= 200;
	gAppConfig.spSettings.dbfFov            		= RSDK_DBF_60_DEG;
	gAppConfig.spSettings.scalingRange      		= 5;
	gAppConfig.spSettings.scalingDoppler    		= 3;
	gAppConfig.spSettings.cfarTreshold      		= 300;
	gAppConfig.spSettings.cfarGuardInterval 		= 10;
	gAppConfig.spSettings.cfarWindowSize    		= 15;

	gAppConfig.spSettings.sptRangeAdaptiveScaling 	= 0; /* Default = 0. Overwritten by ConfigSptKernelChain() in case of adaptive scaling */
	gAppConfig.spSettings.coherentCombSupport     	= 1; /* Default = 1. Overwritten by ConfigSptKernelChain() for use cases that don't support it */

	gAppConfig.dataOutChannel = NONE; /* Output via Lauterbach*/

	/* Use default pre-defined RFE config structures*/
	ppRfeConfigs[0] = rfeConfig0;
	ppRfeConfigs[1] = rfeConfig1;
#else
	/* RFE config - read pre-generated RFE config blobs from file*/
	ppRfeConfigs[0] = customRfeConfigs[0];
	sprintf(fileName, "%s%s/%s", IN_PATH, gAppConfig.sessionCfg.usecase, "rfeConfig0.bin");
	DbgPrintMsg("Reading rfeConfig%d from file %s\n", 0, fileName);
	DbgReadFile(fileName, (int)0, (char *)ppRfeConfigs[0], (int)RFE_CFG_SIZE_TOTAL);

	if (gAppConfig.nrFrontends >= 2)
	{
		ppRfeConfigs[1] = customRfeConfigs[1];
		sprintf(fileName, "%s%s/%s",IN_PATH,  gAppConfig.sessionCfg.usecase, "rfeConfig1.bin");
		DbgPrintMsg("Reading rfeConfig%d from file %s\n", 1, fileName);
		DbgReadFile(fileName, 0, (char *)ppRfeConfigs[1], RFE_CFG_SIZE_TOTAL);
	}

	gAppConfig.acqNrFrames = 1; // hardcode for the moment
	gAppConfig.appRunMode = RSDK_FIXED_FRAMES_MODE; //not used anyway
	gAppConfig.csi2StatsEnable = CSI2_AUTODC_NO; // for ADC acquisition CSI2 stats default disabled

	/* Extract number of samples and chirps for each sequence in blob - use only RFE0 as reference*/
	uint32_t tmpVal0,tmpVal1;
	CDD_Rfe_GetBlobValue(ppRfeConfigs[0], rfeCfg_section_radarCycle_e , rfeCfg_param_radarCycle_chirpSequenceCount_e, &tmpVal0);
	gAppConfig.rfeSettings.nrSequences = (uint16_t)tmpVal0;

	for (uint16_t seq = 0; seq<gAppConfig.rfeSettings.nrSequences; seq++)
	{
		uint16_t seqSectionId = RFE_SECTION_SEQUENCE_ID[seq];
		if(CDD_Rfe_GetBlobValue(ppRfeConfigs[0], seqSectionId , rfeCfg_param_chirpSequence_chirpCount_e, &tmpVal0) != E_OK)
		{
			PrintError("CDD_Rfe_SetBlobValue()\n");
		}
		gAppConfig.rfeSettings.seqChirpCount[seq] = (uint16_t)tmpVal0;

		/* Get index of first profile in sequence*/
		if(CDD_Rfe_GetBlobValue(ppRfeConfigs[0], seqSectionId , rfeCfg_param_chirpSequence_chirpProfileSequence_0_e, &tmpVal0)!= E_OK)
		{
			PrintError("CDD_Rfe_SetBlobValue()\n");
		}
		uint16_t profSectionId = RFE_SECTION_CHIRP_PROFILE_ID[tmpVal0];
		if(CDD_Rfe_GetBlobValue(ppRfeConfigs[0], profSectionId , rfeCfg_param_chirpProfile_effectiveSamplingFrequency_e, &tmpVal0)!= E_OK)
		{
			PrintError("CDD_Rfe_SetBlobValue()\n");
		} // Sampling freq index - see enum rfe_effectiveSamplingFrequency_t

		gAppConfig.rfeSettings.samplingFrequency = tmpVal0;
		tmpVal0 = RFE_SAMPLING_FREQUENCY[tmpVal0];
		if(CDD_Rfe_GetBlobValue(ppRfeConfigs[0], profSectionId , rfeCfg_param_chirpProfile_acquisitionTimeTicks_e, &tmpVal1)!= E_OK)
		{
			PrintError("CDD_Rfe_SetBlobValue()\n");
		} // Acquisition time in ticks (1 tick = 25 ns)
		gAppConfig.rfeSettings.seqProfileSampleCount[seq] = (uint16_t)(tmpVal1*tmpVal0/40);
	}
#endif
}

/*==========================================================
  Configure the SPT processing chain
  Return : 0 for success, error else
==========================================================*/
void ConfigSptKernelChain(void)
{
	uintptr_t tramInitAddr,	tramCheckAddr, rangeFftAddr, dopplerFftAddr;
	uintptr_t nonCohCombAddr, fftCohCombAddr, peakSearchAddr, beamFormingAddr;
	rsdkSptCompMode_t cpMode;
	rsdkMimoType_t	mimoType;

	/* Selecting the necessary procedures/kernels, according to the specified algorithm */
	switch(gAppConfig.spSettings.radarProcessingChain)
	{

	case RSDK_SAMPLES512_CHIRPS128_4CH:
		tramInitAddr    = (uintptr_t)(&RsdkSptInit512smp128crp4ch);
		tramCheckAddr   = (uintptr_t)(&RsdkSptCheckTram512smp128crp4ch);
		rangeFftAddr    = (uintptr_t)(&RsdkSptRange512smp128crp4ch);
		dopplerFftAddr  = (uintptr_t)(&RsdkSptDoppler512smp128crp4ch);
		nonCohCombAddr  = (uintptr_t)(&RsdkSptNcc512smp128crp4ch);
		fftCohCombAddr  = (uintptr_t)(&RsdkSpt3Dfft512smp128crp4ch);
		peakSearchAddr  = (uintptr_t)(&RsdkSptPeakSearch512smp128crp);
		beamFormingAddr = (uintptr_t)(&RsdkSptDbfDoa64Beams4Ch128Peaks);
		cpMode 			= RSDK_SPT_NO_COMP;
		mimoType		= RSDK_NO_MIMO;
		break;

	case RSDK_SAMPLES512_CHIRPS128_8CH:
		tramInitAddr    = (uintptr_t)(&RsdkSptInit512smp128crp8ch);
		tramCheckAddr   = (uintptr_t)(&RsdkSptCheckTram512smp128crp8ch);
		rangeFftAddr    = (uintptr_t)(&RsdkSptRange512smp128crp8ch);
		dopplerFftAddr  = (uintptr_t)(&RsdkSptDoppler512smp128crp8ch);
		nonCohCombAddr  = (uintptr_t)(&RsdkSptNcc512smp128crp8ch);
		fftCohCombAddr  = (uintptr_t)(&RsdkSpt3Dfft512smp128crp8ch);
		peakSearchAddr  = (uintptr_t)(&RsdkSptPeakSearch512smp128crp);
		beamFormingAddr = (uintptr_t)(&RsdkSptDbfDoa64Beams8Ch128Peaks);
		cpMode 			= RSDK_SPT_NO_COMP;
		mimoType		= RSDK_NO_MIMO;
		break;

	default:
		sprintf(gDbgMsg, "Invalid signal processing chain selected. Abort!\n");
		DbgPrintMsg(gDbgMsg);
		HALT_HERE;
		break;
	}

	/* SPT kernel addresses */
	gSptKernelAddr.tramInit    = tramInitAddr;
	gSptKernelAddr.tramCheck   = tramCheckAddr;
	gSptKernelAddr.rangeFft    = rangeFftAddr;
	gSptKernelAddr.dopplerFft  = dopplerFftAddr;
	gSptKernelAddr.antComb     = nonCohCombAddr;
	gSptKernelAddr.peakSearch  = peakSearchAddr;
	gSptKernelAddr.beamForming = beamFormingAddr;

	if (gAppConfig.spSettings.antennaCombining == RSDK_3DFFT)
	{
		/* Supplementary setting for specific request */
		if (gAppConfig.spSettings.coherentCombSupport)
		{
			gSptKernelAddr.antComb  = fftCohCombAddr;
		}
		else
		{
			DbgPrintMsg("Coherent antenna combining is not supported in the selected processing chain!\n");
			HALT_HERE;
		}
	}
	else
	{
		gSptKernelAddr.antComb  = nonCohCombAddr;
	}

	/* SPT data compression */
	gAppConfig.specific.cpMode = cpMode;
	switch (cpMode)
	{
	case RSDK_SPT_NO_COMP:
		gAppConfig.specific.cpRate = 1;
		break;
	case RSDK_SPT_CP4D:
		gAppConfig.specific.cpRate = 2;
		break;
	default:
		sprintf(gDbgMsg, "Invalid compress mode selected. Abort!\n");
		DbgPrintMsg(gDbgMsg);
		HALT_HERE;
		break;
	}

	/* MIMO related settings*/
	gAppConfig.specific.mimoType = mimoType;
	if (mimoType == RSDK_DD_MIMO)
	{
		gAppConfig.specific.nrTxMimo = 3;
		gAppConfig.specific.dFftSize = gAppConfig.rfeSettings.nrChirpsInFrame;
		gAppConfig.specific.nrDopplerBins = gAppConfig.rfeSettings.nrChirpsInFrame/4;
	}
	else
	{
		gAppConfig.specific.nrTxMimo = gAppConfig.rfeSettings.nrChirpShapes;
		gAppConfig.specific.dFftSize = gAppConfig.rfeSettings.nrChirpsInFrame/gAppConfig.specific.nrTxMimo;
		gAppConfig.specific.nrDopplerBins = gAppConfig.specific.dFftSize;
	}

	/* Other */
	gAppConfig.specific.rFftSize    = gAppConfig.rfeSettings.nrSamplesPerChirp;
	gAppConfig.specific.nrRangeBins = gAppConfig.specific.rFftSize / 2;
	gAppConfig.specific.rxActive    = gAppConfig.nrFrontends * RSDK_NR_RX_PER_FRONTEND;
	gAppConfig.specific.nrVirtAnt   = gAppConfig.specific.rxActive *gAppConfig.specific.nrTxMimo;
}

void ExampleRsdkAcqOnlyFlow(void)
{
	uint16_t frame,seq;
	Std_ReturnType status;

	for (int i = 0; i < gAppConfig.sessionCfg.numOfRuns; i++)
	{
		gAppConfig.sessionCfg.crtRunNum = i;
		sprintf(gDbgMsg, " ==== Run App for config %s, iteration# %d ====\n", gAppConfig.sessionCfg.usecase, gAppConfig.sessionCfg.crtRunNum);
		DbgPrintMsg(gDbgMsg);

		frame = 0;

		gFrameEndReceivedCSI0 = false;
		gFrameEndReceivedCSI1 = false;
		gLineCount = 0;

		DbgPrintMsg("Radar cycle start\n");
		status = CDD_Rfe_RadarCycleStart(gAppConfig.acqNrFrames, false, 0);
		statusCheck("RFE Radar cycle start", status);

		for (seq=0; seq<gAppConfig.rfeSettings.nrSequences; seq++)
		ExampleWaitForAcq(frame);

		for (frame = 1; frame < gAppConfig.acqNrFrames; frame++)
		{
			for (seq=0; seq<gAppConfig.rfeSettings.nrSequences; seq++)
			ExampleWaitForAcq(frame);
		}

		/* Output ADC data of last radar cycle */
		for (seq = 0; seq<gAppConfig.rfeSettings.nrSequences; seq++)
		{
			sprintf(fileName, "%s%s_run_%d_sequence_%d_%s", OUT_PATH, gAppConfig.sessionCfg.usecase, gAppConfig.sessionCfg.crtRunNum, seq, "adc_out.dat");
			DbgWriteFileConvert(fileName, (char *)gCascadedAdcSampleBufH[seq].virtAddr, gCascadedAdcSampleBufH[seq].numBytes, ENDIAN_CHANGE, DATA_BUFF_IS_CACHED);
		}

		/* Check RFE is in expected state at the end of execution*/
		ExampleRfeWaitForState(rfe_state_configured_e);
		DbgPrintMsg("Radar cycle DONE!\n");
	}
}

void ExampleRsdkAcqAndProcessingFlow(void)
{
	uint16_t frame = 0;
	Std_ReturnType status;

	ExampleInitSPTDriver();

	AppMemAllocBuffer(pHeapMem, &gSptModuleCodeRelocBufH, MAX_SPT_MODULE_CODE_SIZE, SPT_CODE_ADDR_ALIGN_BYTES,  RSDK_OALMEM_CHUNK_ID_SRAM);

	ConfigSptKernelChain();

    RsdkSptBufferSizeCalc();

    AppMemAllocBuffer(pHeapMem, &gRadarCubeResultsBufH, rsdkBufferSize.sptRadarCube, SPT_DATA_ADDR_ALIGN_BYTES,  RSDK_OALMEM_CHUNK_ID_SRAM);

    ExampleInitSPTKernels();

    AppInitDsphd();

    ExampleTriggerRangeProcessing(frame);

    gFrameEndReceivedCSI0 = false;
    gFrameEndReceivedCSI1 = false;
    gLineCount = 0;

    DbgPrintMsg("Radar cycle start\n");

    status = CDD_Rfe_RadarCycleStart(gAppConfig.acqNrFrames, false, 0);
    statusCheck("RFE Radar cycle start", status);

    ExampleWaitForAcq(frame);
    if (gAppStatus==E_OK)
    {
    	ExampleWaitRangeProcess(frame);
    }
	for(frame = 1; frame < gAppConfig.acqNrFrames; frame++)
	{
		ExampleTriggerRangeProcessing(frame);
		ExampleWaitForAcq(frame);
		if (gAppStatus==E_OK)
		{
			ExampleWaitRangeProcess(frame);
		}
	}

	/* Output ADC data for last radar cycle
	   Need to relocate ADC data into a single buffer */
	AppMemAllocBuffer(pHeapMem, &gFullAdcSampleBufferBufH, rsdkBufferSize.fullAdcSampleBuff, UNUSED_PARAM, UNUSED_PARAM);
	memcpy((void*) &gFullAdcSampleBufferBufH.virtAddr[0], gAdcSample0BufH.virtAddr, gAdcSample0BufH.numBytes);
	if (gAppConfig.nrFrontends == 2)
	{
		memcpy((void*) &gFullAdcSampleBufferBufH.virtAddr[gAdcSample0BufH.numBytes], gAdcSample1BufH.virtAddr, gAdcSample0BufH.numBytes);
	}
	sprintf(fileName, "%s%s", OUT_PATH, "adc_out.dat");
	DbgWriteFileConvert(fileName, (char *)gFullAdcSampleBufferBufH.virtAddr, gFullAdcSampleBufferBufH.numBytes, ENDIAN_CHANGE, DATA_BUFF_IS_CACHED);
	AppMemFreeBuffer(pHeapMem, &gFullAdcSampleBufferBufH);

    ExampleAcqPostProc(frame - 1);

    ExampleRfeWaitForState(rfe_state_configured_e);
    DbgPrintMsg("Radar cycle DONE!\n");

    ExampleSptTearDown();

    AppMemFreeBuffer(pHeapMem, &gRadarCubeResultsBufH);
    AppMemFreeBuffer(pHeapMem, &gSptModuleCodeRelocBufH);
}

//==========================================================
// Read app's initialization file and extract config parameters
// The execution stuck after the detected error.
// Input  : the file name to be read, pointer to the buffer to put the file content, the buffer length,
//          pointer to application configuration parameters
//==========================================================
void ReadConfigFile(char *fileName, char *fileContent, size_t fileContentLen, rsdkAppSettings_t *appConfig)
{
    char *pcontent = fileContent;


    if (fileName == NULL)
    {
        DbgPrintMsg("NULL file name provided\n");
        HALT_HERE;
    }
    // watermark the buffer for a correct file parsing
    memset(fileContent, '@',
           fileContentLen); /*(watermark memory to make sure read operation does not overflow from available memory*/
    DbgReadFile(fileName, 0, pcontent, fileContentLen);
    if (fileContent[0] == '@')
    {   // first char is watermark
        sprintf(gDbgMsg, "Config file %s was not read properly. Abort!\n", fileName);
        DbgPrintMsg(gDbgMsg);
        HALT_HERE;
    }
    if (fileContent[fileContentLen - 1] != '@')
    {   // last char is not watermark
        /*file is larger than allocated space, not all content could fit in. Abort.*/
        sprintf(gDbgMsg, "Config file: %s is larger than allocated space %lu. Abort!\n", fileName, (long unsigned int)fileContentLen);
        DbgPrintMsg(gDbgMsg);
        HALT_HERE;
    }

    ParseConfigFile(fileContent, fileContentLen, appConfig);
}

//==========================================================
// Read app's initialization file and extract config parameters
// The execution stuck after the detected error.
// Input  : the file name to be read, pointer to the buffer to put the file content, the buffer length,
//          pointer to application configuration parameters
//==========================================================
void ReadAppSessionConfigFile(char *fileName, char *fileContent, size_t fileContentLen, rsdkAppSettings_t *appConfig)
{
    char            current_line[INI_LINE_SIZE];
    static int      lastOffset = 0;
    char            *pcontent;

    pcontent = fileContent; //global pointer to fileContent; updated with every read line by line
    memset(fileContent, '@', fileContentLen); //init all fileContent with '@'
    DbgReadFile(fileName, lastOffset, pcontent, fileContentLen); //read fileName and place it into pcontent
    memset(&appConfig->sessionCfg, 0, sizeof(rsdkAppSessionCfg_t));

    //cannot read the file at all
    if (fileContent[0] == '@')
    {
        sprintf(gDbgMsg, "Initialization file %s was not read, abort!\n", fileName);
        DbgPrintMsg(gDbgMsg);
        HALT_HERE;
    }

    //INI file is too large to be read
    if (fileContent[fileContentLen - 1] != '@')
    {
        sprintf(gDbgMsg, "Initialization file %s too large, abort!\n", fileName);
        DbgPrintMsg(gDbgMsg);
        HALT_HERE;
    }

    pcontent = DbgGetIniline(pcontent, current_line);
    if (*current_line == '@')
    {
        eof_session_cfg_file = 1;
        goto end_of_tests;
    }

    sscanf(current_line, "%s%d", (*appConfig).sessionCfg.usecase, &((*appConfig).sessionCfg.numOfRuns));

    lastOffset += (int)(pcontent - fileContent);

end_of_tests:
    {/*do nothing*/}
}


//==========================================================
// Parsing the configuration file content
// The execution stuck after the detected error.
// Input  : pointer to the buffer containing the file content, the maximum content length,
//          pointer to application configuration parameters
//==========================================================
void ParseConfigFile(char *fileContent, size_t fileContentLen, rsdkAppSettings_t *appConfig)
{
    char *       pcontent = fileContent;
    char         paramName[MAX_PARAM_NAME_LENGTH];
    char         currentLine[CONFIG_LINE_SIZE];
    volatile int sscanfRet;
    unsigned int tmpSu1, tmpSu2, tmpSu3, tmpSu4, tmpSu5, tmpSu6, tmpSu7, tmpSu8, tmpSu9, tmpSu10;

    /* Get name of parameter line*/
    pcontent = DbgGetIniline(pcontent, currentLine);
    // parse file until the first char is a watermark
    while (*currentLine != '@')
    {
        sscanfRet = sscanf(currentLine, "%s", paramName);
        ScanStatusCheck(sscanfRet, 1);

        /* Get parameter line*/
        pcontent = DbgGetIniline(pcontent, currentLine);

        /* Get number of frames*/
        if (strcmp(paramName, "NR_FRAMES") == 0)
        {
            sscanfRet = sscanf(currentLine, "%hu", &((*appConfig).acqNrFrames));
            ScanStatusCheck(sscanfRet, 1);

            if ((*appConfig).acqNrFrames < 0)
            {
                sprintf(gDbgMsg, "%hu is not a valid number of frames. Abort!\n", (*appConfig).acqNrFrames);
                DbgPrintMsg(gDbgMsg);
                HALT_HERE;
            }
        }
        else if (strcmp(paramName, "OUTPUT_DATA_CHANNEL") == 0)
        {
            sscanf(currentLine, "%u", &tmpSu1);
            ScanStatusCheck(sscanfRet, 1);

            (*appConfig).dataOutChannel = (rsdkOutputChannel_t)tmpSu1;
            if ((*appConfig).dataOutChannel >= RSDK_LAST_SUPPORTED_OUTPUT_CHANNEL)
            {
                sprintf(gDbgMsg, "Output data channel is not supported. Abort!\n");
                DbgPrintMsg(gDbgMsg);
                HALT_HERE;
            }
        }
        /* Configure output*/
        else if (strcmp(paramName, "OUTPUT_DATA_ENABLE") == 0)
        {
            sscanfRet = sscanf(currentLine, "%u%u%u%u%u%u%u%u%u%u", &tmpSu1, &tmpSu2, &tmpSu3, &tmpSu4, &tmpSu5, &tmpSu6,
                               &tmpSu7, &tmpSu8, &tmpSu9, &tmpSu10);
            ScanStatusCheck(sscanfRet, 10);

            (*appConfig).dataOutEnable.adcData = tmpSu1;
            (*appConfig).dataOutEnable.rangeData = tmpSu2;
            (*appConfig).dataOutEnable.rdCube = tmpSu3;
            (*appConfig).dataOutEnable.rdMag = tmpSu4;
            (*appConfig).dataOutEnable.psDet = tmpSu5;
            (*appConfig).dataOutEnable.cfarDet = tmpSu6;
            (*appConfig).dataOutEnable.peakAntData = tmpSu7;
            (*appConfig).dataOutEnable.dbfDoa = tmpSu8;
            (*appConfig).dataOutEnable.peakList = tmpSu9;
            (*appConfig).dataOutEnable.bistData = tmpSu10;
            (*appConfig).dataOutEnable.profileInfo = 0;
        }

        /* RF configuration*/
        else if (strcmp(paramName, "RF_PARAMETERS") == 0)
        {
            sscanfRet = sscanf(currentLine, "%u%u%u%u%u", &tmpSu1, &tmpSu2, &tmpSu3, &tmpSu4, &tmpSu5);
            ScanStatusCheck(sscanfRet, 5);

            (*appConfig).nrFrontends = tmpSu1;
            (*appConfig).rfeSettings.samplingFrequency = tmpSu2;
            (*appConfig).rfeSettings.nrSamplesPerChirp = tmpSu3;
            (*appConfig).rfeSettings.nrChirpsInFrame = tmpSu4;
            (*appConfig).rfeSettings.nrChirpShapes = tmpSu5;

            (*appConfig).specific.rxActive = (*appConfig).nrFrontends * RSDK_NR_RX_PER_FRONTEND;

            (*appConfig).rfeSettings.txChannelsUsed = 0;

            for (int cS = 0; cS < (*appConfig).rfeSettings.nrChirpShapes; cS++)
            {
                pcontent = DbgGetIniline(pcontent, currentLine);

                sscanfRet = sscanf(currentLine, "%u%u%u%u%u%u%u%u%u%u", &tmpSu1, &tmpSu2, &tmpSu3, &tmpSu4, &tmpSu5,
                                   &tmpSu6, &tmpSu7, &tmpSu8, &tmpSu9, &tmpSu10);
                ScanStatusCheck(sscanfRet, 10);  /* RFE settings from .ini file are not used*/
            }
        }

        /* Radar processing enable*/
        else if (strcmp(paramName, "RADAR_SIG_PROC_ENABLE") == 0)
        {
            sscanfRet = sscanf(currentLine, "%u", &tmpSu1);
            ScanStatusCheck(sscanfRet, 1);
            (*appConfig).spSettings.enableRadarProcessing = tmpSu1;
        }

        /* Radar processing configuration*/
        else if (strcmp(paramName, "SIG_PROC_CHAIN") == 0)
        {
            sscanfRet = sscanf(currentLine, "%u%u%u%u", &tmpSu1, &tmpSu2, &tmpSu3, &tmpSu4);
            ScanStatusCheck(sscanfRet, 4);

            (*appConfig).spSettings.radarProcessingChain = (rsdkProcessingChains_t)tmpSu1;
            (*appConfig).spSettings.antennaCombining = (rsdkCombining_t)tmpSu2;
            (*appConfig).spSettings.scalingRange = tmpSu3;
            (*appConfig).spSettings.scalingDoppler = tmpSu4;
        }

        /* Get name of parameter line*/
        pcontent = DbgGetIniline(pcontent, currentLine);
    }
}

//==========================================================
// Text parse check, after a sscanf was called
// The execution stuck after the detected error.
// Input  : returned sscanf value and the reference value
//==========================================================
void ScanStatusCheck(int sscanfRet, int refValue)
{
    if (sscanfRet != refValue)
    {
        sprintf(gDbgMsg, "sscanf() could not parse. Abort!\n");
        DbgPrintMsg(gDbgMsg);
        HALT_HERE;
    }
}

#ifdef __cplusplus
}
#endif

/*******************************************************************************
 * EOF
 ******************************************************************************/

/** @} */

