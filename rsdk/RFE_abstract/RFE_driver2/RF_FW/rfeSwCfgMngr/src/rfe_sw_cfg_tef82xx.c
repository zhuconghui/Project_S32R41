/**************************************************************************************************
* Copyright 2022 - 2024 NXP
**************************************************************************************************
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
**************************************************************************************************/

/******************************************************************************
 *   Project              : S32R41_RFE_FW
 *   Platform             : S32R41
 *****************************************************************************/

/******************************************************************************
 *                              INCLUDES
 *****************************************************************************/
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include <string.h>

#include "rfe_types.h"
#include "rfe_sw_cfg_tef82xx.h"
#include "rfe_sw_cfg_tef82xx_timing_req.h"
#include "rfe_sw_driver_state.h"
#include "rfe_sw_cfg_to_tef82xx_map.h"
#include "rfeSwMainFsm_internal.h"
#include "rfe_error.h"
#include "rfe_blob_access.h"
#include "rfe_cfg_blob.h"
#include "rfeSwUtils.h"
#include "rfeHwLink.h"
#include "rfe_sw_cfg_tef82xx.h"
#include "rfe_sw_mon_tef82xx.h"

#include "bc_spi.h"
#include "bc_sys.h"
#include "bc_cc.h"
#include "bc_types.h"
#include "bc_te.h"
#include "bc_tx.h"
#include "bc_sc.h"
#include "bc_cafc.h"
#include "bc_mipi.h"
#include "bc_loi.h"
#include "bc_rx.h"
#include "bc_ssb.h"
#include "bc_conf.h"
#include "bc_ism.h"
#include "bc_err.h"
#include "bc_adc.h"
#include "bc_gbias.h"

#include "reg_es2_mipi.h"
#include "reg_es2_cc.h"

#include "rfeHwLink.h"
#include "rfeSwBist.h"

/*==================================================================================================
 *                                      DEFINES
==================================================================================================*/
#define TEF82XX_DEFAULT_RADAR_CYCLE_DURATION	1000000		// 1 second (dummy value)
#define TEF82XX_DEFAULT_RADAR_SEQUENCES			1	
#define TEF82XX_DEFAULT_SEQ_START_TIME			0	
#define PROFMODESEL_OFFSET						7
#define INIT_PROF_LIST							0x0F
#define ERROR_MASKED		1U
#define ERROR_NOT_MASKED	0U
/**
 * This macro defines the number of RX_SATURATION_THRASHOLD.
 */
#define RFE_RX_SATURATION_THRASHOLD_COUNT    (16UL)
/**
 * This macro defines the number of Rx in IP .
 */
#define IP_ADC_NUMBER	2U

/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
 *                                      LOCAL CONSTANTS
==================================================================================================*/
/**
 * This array defines the values for adc clip level threshold .
 * This values was calculated use these formulas:
 *    dB = 20*log(A1/A0)
 *    A0 = A1/exp(dB/20)
 *    A1 = 4095 - the max value for 12bits adc
 *    dB values is defined in blob
 */
static const uint16_t absolutRxSaturationThresholds[RFE_RX_SATURATION_THRASHOLD_COUNT] = {
		[rfe_rxSaturationThreshold_min13_05dB_e] = 912,
		[rfe_rxSaturationThreshold_min12_18dB_e] = 1008,
		[rfe_rxSaturationThreshold_min11_31dB_e] = 1114,
		[rfe_rxSaturationThreshold_min10_44dB_e] = 1231,
		[rfe_rxSaturationThreshold_min9_57dB_e] = 1361,
		[rfe_rxSaturationThreshold_min8_70dB_e] = 1504,
		[rfe_rxSaturationThreshold_min7_83dB_e] = 1662,
		[rfe_rxSaturationThreshold_min6_96dB_e] = 1838,
		[rfe_rxSaturationThreshold_min6_09dB_e] = 2031,
		[rfe_rxSaturationThreshold_min5_22dB_e] = 2245,
		[rfe_rxSaturationThreshold_min4_35dB_e] = 2482,
		[rfe_rxSaturationThreshold_min3_48dB_e] = 2743,
		[rfe_rxSaturationThreshold_min2_61dB_e] = 3032,
		[rfe_rxSaturationThreshold_min1_74dB_e] = 3352,
		[rfe_rxSaturationThreshold_min0_87dB_e] = 3705,
		[rfe_rxSaturationThreshold_0dB_e] = 4095
};
/*==================================================================================================
 *                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
 *                                      LOCAL VARIABLES
==================================================================================================*/
static uint32_t dpmReqDelay[] = {
    0u,    // e_NO_DPM_ACTIVE
    0u,    // e_DPM_FOR_CHIRP_CALIBRATION
    5u,    // e_DPM_FOR_LO_CALIBRATION
    0u     // e_DPM_ACTIVE
};

static CC_DynPowDnIPList_t Tef82xxDpmRecommendedPowerModes[] = {
    {    // DISABLE_POWER_SAVING_MODE
        .SetTx1=e_CC_DYN_POWMODE_NONE, 
        .SetTx2=e_CC_DYN_POWMODE_NONE, 
        .SetTx3=e_CC_DYN_POWMODE_NONE,
        .SetRx1=e_CC_DYN_POWMODE_NONE, 
        .SetRx2=e_CC_DYN_POWMODE_NONE, 
        .SetRx3=e_CC_DYN_POWMODE_NONE, 
        .SetRx4=e_CC_DYN_POWMODE_NONE,
        .SetADC=e_CC_DYN_POWMODE_NONE, 
        .SetChirp=e_CC_DYN_POWMODE_NONE, 
        .SetLoInterface=e_CC_DYN_POWMODE_NONE,
        .SetADCBGClib=e_CC_DYN_POWMODE_PERSEQUENCE
     },  //# SetADCBGClib = ADC background calibration triggered at the end of a sequence.

     {   // DPM_FOR_CHIRP_CALIBRATION
        .SetTx1=e_CC_DYN_POWMODE_NONE,
        .SetTx2=e_CC_DYN_POWMODE_NONE,
        .SetTx3=e_CC_DYN_POWMODE_NONE,
        .SetRx1=e_CC_DYN_POWMODE_NONE,
        .SetRx2=e_CC_DYN_POWMODE_NONE,
        .SetRx3=e_CC_DYN_POWMODE_NONE,
        .SetRx4=e_CC_DYN_POWMODE_NONE,
        .SetADC=e_CC_DYN_POWMODE_PERSEQUENCE,
        .SetChirp=e_CC_DYN_POWMODE_NONE,
        .SetLoInterface=e_CC_DYN_POWMODE_PERSEQUENCE,
        .SetADCBGClib=e_CC_DYN_POWMODE_PERSEQUENCE
     },

     {       //DPM_FOR_LO_CALIBRATION
        .SetTx1=e_CC_DYN_POWMODE_NONE,
        .SetTx2=e_CC_DYN_POWMODE_NONE,
        .SetTx3=e_CC_DYN_POWMODE_NONE,
        .SetRx1=e_CC_DYN_POWMODE_NONE,
        .SetRx2=e_CC_DYN_POWMODE_NONE,
        .SetRx3=e_CC_DYN_POWMODE_NONE,
        .SetRx4=e_CC_DYN_POWMODE_NONE,
        .SetADC=e_CC_DYN_POWMODE_PERSEQUENCE,
        .SetChirp=e_CC_DYN_POWMODE_NONE,
        .SetLoInterface=e_CC_DYN_POWMODE_NONE,
        .SetADCBGClib=e_CC_DYN_POWMODE_PERSEQUENCE
     },

     {                  // DPM_ACTIVE
        .SetTx1=e_CC_DYN_POWMODE_NONE,
        .SetTx2=e_CC_DYN_POWMODE_NONE,
        .SetTx3=e_CC_DYN_POWMODE_NONE,
        .SetRx1=e_CC_DYN_POWMODE_NONE,
        .SetRx2=e_CC_DYN_POWMODE_NONE,
        .SetRx3=e_CC_DYN_POWMODE_NONE,
        .SetRx4=e_CC_DYN_POWMODE_NONE,
        .SetADC=e_CC_DYN_POWMODE_PERSEQUENCE,
        .SetChirp=e_CC_DYN_POWMODE_PERSEQUENCE,
        .SetLoInterface=e_CC_DYN_POWMODE_PERSEQUENCE,
        .SetADCBGClib=e_CC_DYN_POWMODE_PERSEQUENCE
     }
};
static BOOL swFusaMask[SW_ERROR_COUNT] = { (BOOL)FALSE };

/*==================================================================================================
 *                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
 *                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
/*
 * @brief Function that determines if TEF82xx IQ Togle test must be done
 * @param pDrvState - pointer to the driver state structure
 * @param [in,out]  rfe___error___pointer - Error handling parameter:
 */
static void SetPersistentIQTogleTest(rfeDriverPersistentMem_t *const pDrvState, rfe_error_t* rfe___error___pointer);
/*
 * @brief Function to set the persistent radar parameters
 * @param pRfeConfig - pointer to the radar parameters structure
 * @param pDrvState - pointer to the driver state structure
 * @param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 */
static void SetPersistentRadarConfig(rfeDriverPersistentMem_t *const pDrvState, uint8_t* pRfeConfig,
		rfe_error_t* rfe___error___pointer);
/*
 * @brief Helper function to set QPSK pin configuration
 * @param speed - pin sampling speed, see Tef82xx LLD 
 * @param [out] - Tef82xx LLD BC_ERRCODE
 */
static BC_ERRCODE ConfigQPSKPinPads(CC_PINSpeed_e speed);		
/*
 * @brief Function to set IO pin configuration
 * @param pDrvState - pointer to the driver state structure
 * @param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 */
static void StaticConfigIO(rfeDriverPersistentMem_t *const pDrvState, rfe_error_t* rfe___error___pointer);
/*
 * @brief Function to set chirp trigger mode
 * @param pDrvState - pointer to the driver state structure
 * @param chirpSequence - sequence index
 * @param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 */
static void SetChirpTrgMode(rfeDriverPersistentMem_t *const pDrvState, uint8_t chirpSequence,
		rfe_error_t* rfe___error___pointer);
/*
 * @brief Function to set Rf min level
 * @param LevelRfMin - value to Rf min level
 */
static BC_ERRCODE TX_SetLevelRfMin(float32_t LevelRfMin);
/*
 * @brief Function update the LO low level threshold
 * @param pDrvState - pointer to the driver state structure
 * @param chirpSequence - sequence index
 *
 */
static BC_ERRCODE UpdateLOLowLevelTh(rfeDriverPersistentMem_t *const pDrvState, uint8_t chirpSequence);
/*
 * @brief Function configuration the static parameters to TEF82XX with ES2.1 samples
 * @param pDrvState - pointer to the driver state structure
 * @param pRfeConfig - pointer to the radar parameters structure
 * @param chirpSequence - sequence index
 * @param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 */
static void StaticConfig(rfeDriverPersistentMem_t *const pDrvState, uint8_t *pRfeConfig,
		uint8_t chirpSequence, rfe_error_t* rfe___error___pointer);
/*
 * @brief Function configuration the profile parameters to TEF82XX
 * @param pDrvState - pointer to the driver state structure
 * @param pRfeConfig - pointer to the radar parameters structure
 * @param chirpSequence - sequence index
 * @param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 */
static void ProfileConfig(rfeDriverPersistentMem_t *pDrvState, uint8_t *pRfeConfig,	uint8_t chirpSequence,
		rfe_error_t* rfe___error___pointer);

/*
 * @brief Function check if profiles use phase rotator
 * @param pRfeConfig - pointer to the radar parameters structure
 * @param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 */
static uint8_t GetPhaseRotatorEnable(const uint8_t * pRfeConfig, rfe_error_t* rfe___error___pointer);
/*==================================================================================================
 *                              		LOCAL FUNCTIONS
 ==================================================================================================*/
static void SetPersistentIQTogleTest(rfeDriverPersistentMem_t *const pDrvState, rfe_error_t* rfe___error___pointer)
{
	uint8_t chirpSequenceConfigIndex;
	uint8_t noChirpSeq = rfeCfg_metadata_getChirpSequenceConfigCount(pDrvState->rfeConfig, rfe___error___pointer);

	if (rfe_error_none_e == *rfe___error___pointer)
	{
		pDrvState->tef82xxDrvState.enableIQPinsTogleTest = FALSE;
		for(chirpSequenceConfigIndex = 0U; chirpSequenceConfigIndex < noChirpSeq; chirpSequenceConfigIndex++)
		{
			if (rfeCfg_chirpSequence_getDynamicUpdatesEnabled(pDrvState->rfeConfig, rfeChirpSequenceMapper(chirpSequenceConfigIndex), rfe___error___pointer))
			{
				pDrvState->tef82xxDrvState.enableIQPinsTogleTest = TRUE;
			}
		}
	}
}

static void GetChirpSeqParams(rfeDriverPersistentMem_t *const pDrvState, uint8_t index, uint8_t* pRfeConfig, rfe_error_t* rfe___error___pointer)
{
	uint8_t idx;
	uint8_t chirpProfileSequenceLength = 0;
	bool customPatern = false;

	if (*rfe___error___pointer == rfe_error_none_e)
	{
		// Get number of chirps in sequence/frame
		pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[index].nrChirpsInFrame =
				rfeCfg_chirpSequence_getChirpCount(pRfeConfig, rfeChirpSequenceMapper(index), rfe___error___pointer);
		if (*rfe___error___pointer == rfe_error_none_e)
		{
			// Get length of chirp profiles sequence
			chirpProfileSequenceLength = rfeCfg_chirpSequence_getChirpProfileSequenceLength(pRfeConfig, rfeChirpSequenceMapper(index), rfe___error___pointer);
			pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[index].nrSequenceChirpProfiles =
					chirpProfileSequenceLength;
		}
		for(idx = 0; idx < (uint8_t)RFE_MAX_CHIRP_PROFILES; ++idx)
		{
			pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[index].profList[idx] = INIT_PROF_LIST;
		}
		for(idx = 0; idx < chirpProfileSequenceLength; ++idx)
		{
			if(*rfe___error___pointer != rfe_error_none_e)
			{
					break;
			}
			pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[index].profList[idx] =
					(uint8_t)rfeCfg_chirpSequence_getChirpProfileSequence(pRfeConfig, rfeChirpSequenceMapper(index), idx, rfe___error___pointer);
		}
		if(*rfe___error___pointer == rfe_error_none_e)
		{
			// more then one chirp profile in sequence
			if(chirpProfileSequenceLength > 1U)
			{
				// fit chirp profile sequence in BC regs
				for(idx = 0; idx < chirpProfileSequenceLength; ++idx)
				{
					if(pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[index].profList[idx] != idx)
					{
						customPatern = true;
						break;
					}
				}
				if(customPatern)
				{
					pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[index].profModeSel = (uint8_t)USE_PROFILE_LIST;
				}
				else
				{
					pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[index].profModeSel = chirpProfileSequenceLength + PROFILE_GREAT_ONE_OFFSET;
				}
			}
			else
			{
				// single profile
				pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[index].profModeSel =
						pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[index].profList[0];
			}
			// Get RX channels
			// -----------------------------------------------------------------------------------------
			pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[index].rxChannelEnable =
								(uint8_t)rfeCfg_chirpSequence_getRxEnable(pRfeConfig, rfeChirpSequenceMapper(index), rfe___error___pointer);
			SetPersistentIQTogleTest(pDrvState, rfe___error___pointer);
		}
	}
}

static BOOL CheckSequencesUsesPhaseRotator(rfeDriverPersistentMem_t *const pDrvState, rfe_error_t* rfe___error___pointer)
{
	uint8_t seqIdx = 0U;
	uint8_t profileIdx = 0U;
	BOOL checkResult = FALSE;
	TE_DDMAMod_e ddma = e_TE_DDMA_DISABLED;
	bool useQPSK = false;
	uint8_t	noChirpProfiles = rfeCfg_metadata_getChirpProfileCount(pDrvState->rfeConfig, rfe___error___pointer);
	uint8_t txEneble = 0U;

	if(*rfe___error___pointer == rfe_error_none_e)
	{
		for(profileIdx = 0; profileIdx < noChirpProfiles ; ++profileIdx)
		{
			txEneble = rfeCfg_chirpProfile_getTxTransmissionEnable(pDrvState->rfeConfig, rfeChirpProfileMapper(profileIdx),
					rfe___error___pointer);
			if (*rfe___error___pointer != rfe_error_none_e)
			{
				break;
			}
			if(txEneble != 0U)
			{
				checkResult = TRUE;
				break;
			}
		}
	}
	if(checkResult != FALSE)
	{
		checkResult = FALSE;
		for(seqIdx = 0; seqIdx < pDrvState->tef82xxDrvState.radarCycleParams.noRadarSequences; ++seqIdx)
		{
			if (*rfe___error___pointer != rfe_error_none_e)
			{
				break;
			}
			ddma = rfeDdmaModeFromUint8Mapper( rfeCfg_sequence_getPhaseRotationDdmaMode(pDrvState->rfeConfig, rfeChirpSequenceMapper(seqIdx), rfe___error___pointer));
			if (*rfe___error___pointer != rfe_error_none_e)
			{
				break;
			}
			if(ddma != e_TE_DDMA_DISABLED)
			{
				checkResult = TRUE;
				break;
			}
			useQPSK = rfeCfg_chirpSequence_getDynamicUpdatesEnabled(pDrvState->rfeConfig, rfeChirpSequenceMapper(seqIdx), rfe___error___pointer);
			if(useQPSK == TRUE)
			{
				checkResult = TRUE;
				break;
			}
		}
		if (*rfe___error___pointer == rfe_error_none_e)
		{
			if(checkResult == FALSE)
			{
				checkResult = ConvertUint8ToBool(GetPhaseRotatorEnable(pDrvState->rfeConfig, rfe___error___pointer));
			}
		}
	}
	return checkResult;
}

static void SetChirpSequence(rfeDriverPersistentMem_t *const pDrvState, uint8_t* pRfeConfig, rfe_error_t* rfe___error___pointer)
{
	uint8_t index;
	uint8_t firstProfileUsedInSeq;

	for(index = 0; index < rfeCfg_metadata_getChirpSequenceConfigCount(pRfeConfig, rfe___error___pointer); ++index)
	{
		pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[index].firstCalib = TRUE;
		if (*rfe___error___pointer != rfe_error_none_e)
		{
			break;
		}
		GetChirpSeqParams(pDrvState, index, pRfeConfig, rfe___error___pointer);
		if (*rfe___error___pointer != rfe_error_none_e)
		{
			break;
		}
		// Get data for CAFC PLL FILTER settings
		firstProfileUsedInSeq = pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[index].profList[RFE_LIST_PROFILE_0];
		if (firstProfileUsedInSeq < (uint8_t)RFE_MAX_CHIRP_PROFILES)
		{
			// Only for valid chirp seq
			pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[index].cafcLoopBandwidth = GetPllLoopFilterBw(firstProfileUsedInSeq, pRfeConfig, rfe___error___pointer);
			if (*rfe___error___pointer != rfe_error_none_e)
			{
				break;
			}
			pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[index].effFc =
					(float32_t)rfeCfg_chirpProfile_getCenterFrequency(pRfeConfig, rfeChirpProfileMapper(firstProfileUsedInSeq),
							rfe___error___pointer) * KHZ_TO_HZ;
			if (*rfe___error___pointer != rfe_error_none_e)
			{
				break;
			}
			pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[index].vcoSel =
					ChirpPllVcoBandwidthMapper(rfeCfg_chirpProfile_getChirpPllVco(pRfeConfig, rfeChirpProfileMapper(firstProfileUsedInSeq), rfe___error___pointer));
			if (*rfe___error___pointer != rfe_error_none_e)
			{
				break;
			}
			pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[index].DownChirp =
					((uint8_t)rfeCfg_chirpProfile_getChirpSlopeDirection(pRfeConfig, rfeChirpProfileMapper(firstProfileUsedInSeq), rfe___error___pointer) == (uint8_t)RFE_RISING) ? FALSE: TRUE;
		}
	}
}

static void SetPersistentRadarConfig(rfeDriverPersistentMem_t *const pDrvState, uint8_t* pRfeConfig, rfe_error_t* rfe___error___pointer)
{
	uint8_t loiBbd = 0;

	pDrvState->tef82xxDrvState.firstCalib = TRUE;
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		pDrvState->tef82xxDrvState.radarGeneral.nrChirpProfiles = rfeCfg_metadata_getChirpProfileCount(pRfeConfig, rfe___error___pointer);
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		pDrvState->tef82xxDrvState.radarGeneral.tJumpbackTime = rfeCfg_general_getJumpbackTimeTicks(pRfeConfig, rfe___error___pointer);
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		// Needed by FSM
		pDrvState->tef82xxDrvState.radarCycleParams.noRadarSequences = rfeCfg_radarCycle_getChirpSequenceCount(pRfeConfig, rfe___error___pointer);
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		SetChirpSequence(pDrvState, pRfeConfig, rfe___error___pointer);
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		// dynamic power mode activation; lower power -> chirp power mode; active -> no power savings, no chirp power mode
		pDrvState->tef82xxDrvState.chirpPowerSavingEnabled = ((uint8_t)rfeCfg_general_getPowerMode(pRfeConfig, rfe___error___pointer) == 0U) ? 1U: 0U;

		// TX Phase workaround 1, required due to LOI load imbalance depended on the amount of TX enabled
		// Requires change in the BLOB to give the user the choice to enable the WA or not
#ifdef TX_PHASE_ERROR_WA1
		pDrvState->tef82xxDrvState.txPhaseErrorWa1Enabled = (uint8_t)TRUE;
#else
		pDrvState->tef82xxDrvState.txPhaseErrorWa1Enabled = (uint8_t)FALSE;
#endif
	}
	// get Loi BBD parameters
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		loiBbd = rfeCfg_monitorAndSafety_getLoiBBD(pRfeConfig, rfe___error___pointer);
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		pDrvState->tef82xxDrvState.loiBbdEn = (BOOL)((loiBbd >> 4U) & 0x01U);
		pDrvState->tef82xxDrvState.LoOutSensitivity = (BOOL)((loiBbd >> 3U) & 0x01U);
		pDrvState->tef82xxDrvState.LoOutGrounded = (BOOL)((loiBbd >> 2U) & 0x01U);
		pDrvState->tef82xxDrvState.LoISensitivity = (BOOL)((loiBbd >> 1U) & 0x01U);
		pDrvState->tef82xxDrvState.LoIGrounded = (BOOL)((loiBbd >> 0U) & 0x01U);
	}
	pDrvState->tef82xxDrvState.sequencesUsesPhaseRotator = CheckSequencesUsesPhaseRotator(pDrvState, rfe___error___pointer);
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		pDrvState->tef82xxDrvState.enableReduceTransmisionForVGACalib =
				!ConvertUint8ToBool( rfeCfg_general_getTxCalibrationMode(pDrvState->rfeConfig, rfe___error___pointer));
	}
}

static BC_ERRCODE ConfigQPSKPinPads(CC_PINSpeed_e speed)
{
	BC_ERRCODE   errCode = BC_ERR_NOERROR;

	// All input mode
	errCode = BC_CC_ConfigPad(FALSE, speed, e_SYS_TX1_I_PS);
	if (errCode == BC_ERR_NOERROR)
	{
		errCode = BC_CC_ConfigPad(FALSE, speed, e_SYS_TX1_Q_PS);
	}			
	if (errCode == BC_ERR_NOERROR)
	{
		errCode = BC_CC_ConfigPad(FALSE, speed, e_SYS_TX2_I_PS);
	}
	if (errCode == BC_ERR_NOERROR)
	{
		errCode = BC_CC_ConfigPad(FALSE, speed, e_SYS_TX2_Q_PS);
	}			
	if (errCode == BC_ERR_NOERROR)
	{
		errCode = BC_CC_ConfigPad(FALSE, speed, e_SYS_TX3_I_PS);
	}
	if (errCode == BC_ERR_NOERROR)
	{
		errCode = BC_CC_ConfigPad(FALSE, speed, e_SYS_TX3_Q_PS);
	}			
	return errCode;
} 

static BC_ERRCODE StaticConfigIO_Standalone(void)
{
	BC_ERRCODE   errCode = BC_ERR_NOERROR;
	TE_CSOutCfg_t csOutCfg = {0};

	errCode = BC_CC_ConfigMCUInt((BOOL)TEF82XX_DEFAULT_MCU_INT_POLARITY, (BOOL)TEF82XX_DEFAULT_MCU_INT_TRG_MODE,
												 TEF82XX_DEFAULT_MCU_INT_PERIOD);
	if (errCode == BC_ERR_NOERROR)
	{
		errCode = BC_CC_ConfigPad(TRUE, e_CC_PADSPEED_HIGH, e_SYS_MCUINT_CHIRPSTART_OUT_PAD);
	}
	if (errCode == BC_ERR_NOERROR)
	{
		errCode = ConfigQPSKPinPads(e_CC_PADSPEED_FAST);
	}
	if (errCode == BC_ERR_NOERROR)
	{
		// Enable Chirp start out for every chirp
		csOutCfg.CSINFunSel = e_TE_CSIN_INT_EVENT;
		csOutCfg.CSOUTFunSel = e_TE_CSOUT_BASEDON_CS_OUT;
		csOutCfg.CSI2FrameMode = e_TE_CSI2_DEACT_ENDOF_SEQ;
		csOutCfg.ChirpStartOutMode = e_TE_CSTOGGLE_EVERY_CHIRP;
		csOutCfg.ReadyIntMode = e_TE_READYINT_END_OF_SEQ;
		errCode = BC_SYS_SetCSOut(&csOutCfg);
	}
	if (errCode == BC_ERR_NOERROR)
	{
		// Configure MCU int pin as chirp start out
		errCode = BC_CC_SwitchMcuIntCSOut(TRUE);
	}

	return errCode;
}

static BC_ERRCODE StaticConfigIO_Leader(void)
{
	BC_ERRCODE   errCode = BC_ERR_NOERROR;
	TE_CSOutCfg_t csOutCfg = {0};

	rfeSwUtils_SelectFe(0U);
	errCode = BC_CC_ConfigPad(TRUE, e_CC_PADSPEED_HIGH, e_SYS_MCUINT_CHIRPSTART_OUT_PAD);
	if (errCode == BC_ERR_NOERROR)
	{
		errCode = ConfigQPSKPinPads(e_CC_PADSPEED_FAST);
	}
	if (errCode == BC_ERR_NOERROR)
	{
		// Enable Chirp start out for every chirp
		csOutCfg.CSINFunSel = e_TE_CSIN_INT_EVENT;
		csOutCfg.CSOUTFunSel = e_TE_CSOUT_BASEDON_CS_OUT;
		csOutCfg.CSI2FrameMode = e_TE_CSI2_DEACT_ENDOF_SEQ;
		csOutCfg.ChirpStartOutMode = e_TE_CSTOGGLE_FOLLOW_MASTER;
		csOutCfg.ReadyIntMode = e_TE_READYINT_END_OF_SEQ;
		errCode = BC_SYS_SetCSOut(&csOutCfg);
	}
	if (errCode == BC_ERR_NOERROR)
	{
		// Configure MCU int pin as chirp start out
		errCode = BC_CC_SwitchMcuIntCSOut(TRUE);
	}
	return errCode;
}

static BC_ERRCODE StaticConfigIO_Follower(rfeDriverPersistentMem_t *const pDrvState)
{
	BC_ERRCODE   errCode = BC_ERR_NOERROR;
	TE_CSOutCfg_t csOutCfg = {0};

	rfeSwUtils_SelectFe(pDrvState->frontendId);
	errCode = BC_CC_ConfigPad(FALSE, e_CC_PADSPEED_HIGH, e_SYS_CHIRPSTART_IN_PAD);
	if (errCode == BC_ERR_NOERROR)
	{
		errCode = BC_CC_ConfigPad(TRUE, e_CC_PADSPEED_HIGH, e_SYS_MCUINT_CHIRPSTART_OUT_PAD);
	}
	if (errCode == BC_ERR_NOERROR)
	{
		errCode = ConfigQPSKPinPads(e_CC_PADSPEED_FAST);
	}
	if (errCode == BC_ERR_NOERROR)
	{
		// Enable Chirp start out for every chirp
		csOutCfg.CSINFunSel = e_TE_CSIN_INT_EVENT;
		csOutCfg.CSOUTFunSel = e_TE_CSOUT_BASEDON_CS_OUT;
		csOutCfg.CSI2FrameMode = e_TE_CSI2_DEACT_ENDOF_SEQ;
		csOutCfg.ChirpStartOutMode = e_TE_CSTOGGLE_EVERY_CHIRP;
		csOutCfg.ReadyIntMode = e_TE_READYINT_END_OF_SEQ;
		errCode = BC_SYS_SetCSOut(&csOutCfg);
	}
	if (errCode == BC_ERR_NOERROR)
	{
		// Configure MCU int pin as chirp start out
		errCode = BC_CC_SwitchMcuIntCSOut(TRUE);
	}
	return errCode;
}

static void StaticConfigIO(rfeDriverPersistentMem_t *const pDrvState, rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE errCode = BC_ERR_NOERROR;
	CC_IntEvent_t intEvents = {0};
	intEvents.EndofDataTnfrInt = (BOOL)TEF82XX_DEFAULT_INT_EVENT_END_OF_DATA_TNFR;
	intEvents.ChirpIn = (BOOL)TEF82XX_DEFAULT_INT_EVENT_CHIRP_IN;

	// Config dynamic power mod
	errCode = rfeSwCfgSetDynPowMode(e_DPM_ACTIVE);

	if(errCode == BC_ERR_NOERROR)
	{
		// config IO pads ad needed
		if (RfeDrvStateConfigurationGet() == rfeFrontEnd_Single_e)
		{
			// single
			errCode = StaticConfigIO_Standalone();
		}
		else
		{
			// cascaded
			if (pDrvState->frontendMode == RFE_CASCADING_LEADER)
			{
				errCode = StaticConfigIO_Leader();
			}
			else
			{
				// For followers FE we can map the FE id to the follower index
				errCode = StaticConfigIO_Follower(pDrvState);
			}
		}
	}
	if (errCode == BC_ERR_NOERROR)
	{
		errCode = BC_CC_EnDisClrInt(e_CC_ENABLE_INT, &intEvents);
	}

	if(errCode != BC_ERR_NOERROR)
	{
		*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
	}
}

static void SetChirpTrgMode(rfeDriverPersistentMem_t *const pDrvState, uint8_t chirpSequence,
		rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE   errCode = BC_ERR_NOERROR;
	TE_ChirpTrgMode_t  teChirpTrgMode = {0};
	if (pDrvState->tef82xxDrvState.chirpPowerSavingEnabled != 0U)
	{
		teChirpTrgMode.ChirpPowerMode = TRUE;
	}
	if (RfeDrvStateConfigurationGet() == rfeFrontEnd_Single_e)
	{
		// single
		teChirpTrgMode.ChirpTrigMode = rfeUseExtTrigMapper(pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[chirpSequence].useExtTrig);
		teChirpTrgMode.ChirpStartDelay = FALSE;
	}
	else
	{
		if (pDrvState->frontendMode == RFE_CASCADING_FOLLOWER)
		{
			// Force external chirp triggering mode for Slave RFEs
			teChirpTrgMode.ChirpTrigMode = e_TE_CH_TRG_EXT_SINGLE_TRG;  // related to e_TE_CH_TRG_EXT_EVERY_CHRIP;
			teChirpTrgMode.ChirpStartDelay = TRUE;
		}
		else
		{
			teChirpTrgMode.ChirpTrigMode = rfeUseExtTrigMapper(
					pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[chirpSequence].useExtTrig);
			teChirpTrgMode.ChirpStartDelay = FALSE;
		}
	}
	// set to SPI chirp trigger mode
	errCode = BC_TE_SetChirpTrgMode(&teChirpTrgMode);

	if(errCode != BC_ERR_NOERROR)
	{
		*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
	}
}

void CAFC_ConfigLoopFilter(uint8_t chirpSequence, rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE                  errCode = BC_ERR_NOERROR;
	rfeDriverPersistentMem_t    *pDrvState = NULL;
	CAFC_PLLLPFSel_e            cafcPll;
	CAFC_LoopFilterLUTSel_e     cafcLoop;

	if (*rfe___error___pointer == rfe_error_none_e)
	{
		pDrvState = RfeDrvStateGet();
		cafcPll = rfeCafcPllLPFSelMapper(TEF82XX_DEFAULT_CAFC_PLL_PROF_SEL);
		cafcLoop = rfeCafcLoopFilterLUTSelMapper(TEF82XX_DEFAULT_CAFC_LOOP_FLT_LUT_SEL);
		errCode = BC_CAFC_ConfigLoopFilter(cafcPll, cafcLoop,
						pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[chirpSequence].cafcLoopBandwidth,
						(BC_FLOAT)pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[chirpSequence].effFc,
						pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[chirpSequence].DownChirp);
		if(errCode != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}
	}
}


static void SetMipiNumLaneAndDataRate(rfeDriverPersistentMem_t *pDrvState, uint8_t *mipiNumLanes,
		MIPI_DataRate_e *mipiDataRate, rfe_chirpSequenceIndex_t chirpSequence, rfe_error_t* rfe___error___pointer)
{
	uint8_t 							profileIdx;
	rfe_effectiveSamplingFrequency_t 	samplingFrequency = rfe_effectiveSamplingFrequency_40MHz_e;

	if ( *rfe___error___pointer == rfe_error_none_e)
	{
		// All profiles must have the same sampling frequency
		// Using first profile in sequence as reference
		profileIdx = (uint8_t)rfeCfg_chirpSequence_getChirpProfileSequence(pDrvState->rfeConfig, chirpSequence, 0u, rfe___error___pointer);
	}
	if ( *rfe___error___pointer == rfe_error_none_e)
	{
		samplingFrequency = EffectiveSamplingFrequencyMapper(rfeCfg_chirpProfile_getEffectiveSamplingFrequency(pDrvState->rfeConfig, rfeChirpProfileMapper(profileIdx), rfe___error___pointer));
	}
	if ( *rfe___error___pointer == rfe_error_none_e)
	{
		switch (samplingFrequency)
		{
			case rfe_effectiveSamplingFrequency_5MHz_e:
			{
				*mipiNumLanes = 1U;
				*mipiDataRate = e_MIPI_DATARATE_240;
				break;
			}
			case rfe_effectiveSamplingFrequency_10MHz_e:
			{
				*mipiNumLanes = 2U;
				*mipiDataRate = e_MIPI_DATARATE_240;
				break;
			}
			case rfe_effectiveSamplingFrequency_20MHz_e:
			{
				*mipiNumLanes = 4U;
				*mipiDataRate = e_MIPI_DATARATE_240;
				break;
			}							
			case rfe_effectiveSamplingFrequency_40MHz_e:
			{
				*mipiNumLanes = 4U;
				*mipiDataRate = e_MIPI_DATARATE_480;
				break;
			}
			default:
			{
				*mipiNumLanes = 4U;
				*mipiDataRate = e_MIPI_DATARATE_480;
				break;
			}
		}
	}

}

static void SetMipiVCs(rfeDriverPersistentMem_t *pDrvState, MIPI_VCNum_t *selectVCs,MIPI_VCClearFrame_t *clearFrameVCs,
		rfe_chirpSequenceIndex_t chirpSequence, rfe_error_t* rfe___error___pointer)
{
	uint8_t	numChirpProfilesInSeq = 0U;
	uint8_t idx = 0U;
	rfe_virtualChannel_t virtualChannel;
	uint8_t profileIdx = 0U;

	if ( *rfe___error___pointer == rfe_error_none_e)
	{	
#ifdef MIPI_SETUP_SEQUENCE
		numChirpProfilesInSeq = rfeCfg_chirpSequence_getChirpProfileSequenceLength(pDrvState->rfeConfig,
				(rfe_chirpSequenceIndex_t)chirpSequence, rfe___error___pointer);
#else
		// Get all VC used in all profiles
		numChirpProfilesInSeq = rfeCfg_metadata_getChirpProfileCount(pDrvState->rfeConfig, rfe___error___pointer);
#endif
		for(idx = 0 ; idx < numChirpProfilesInSeq; ++idx)
		{
			if ( *rfe___error___pointer != rfe_error_none_e)
			{
				break;
			}
#ifdef MIPI_SETUP_SEQUENCE
			profileIdx = rfeCfg_chirpSequence_getChirpProfileSequence(pDrvState->rfeConfig,
					chirpSequence, idx, rfe___error___pointer);
#else
			profileIdx = idx;
#endif
			if ( *rfe___error___pointer != rfe_error_none_e)
			{
				break;
			}
			virtualChannel = VirtualChannelMapper(rfeCfg_chirpProfile_getVirtualChannel(pDrvState->rfeConfig, rfeChirpProfileMapper(profileIdx),
					rfe___error___pointer));
			if ( *rfe___error___pointer != rfe_error_none_e)
			{
				break;
			}
			switch(virtualChannel)
			{
			case rfe_virtualChannel_0_e:
				selectVCs->SelectVC0 = TRUE;
				clearFrameVCs->ClearFrameVC0 = TRUE;
				break;
			case rfe_virtualChannel_1_e:
				selectVCs->SelectVC1 = TRUE;
				clearFrameVCs->ClearFrameVC1 = TRUE;
				break;
			case rfe_virtualChannel_2_e:
				selectVCs->SelectVC2 = TRUE;
				clearFrameVCs->ClearFrameVC2 = TRUE;
				break;
			default:
				*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(BC_ERR_TE_VIRTUALCHANNEL);
				break;
			}
		}
#ifndef MIPI_SETUP_SEQUENCE
		// Enable VC3. It is used for RX Bist.
		selectVCs->SelectVC3 = TRUE;
		clearFrameVCs->ClearFrameVC3 = TRUE;
#endif
	}
}

void MIPI_Config(rfeMipiCsiConfigLevel_t configLevel, rfe_chirpSequenceIndex_t chirpSequence, rfe_error_t* rfe___error___pointer)
{
/*	TEF82XX Reference Manual RM00227 page 64
 *
The PDC decimation factor is also set in the eight chirp profiles. However, dynamic
switching of the decimation factor, and therefore of the data rate at the digital output,
is not supported within a chirp sequence series. For example, correct operation of
sequential series 0-1-0-1 requires the PDC decimation factor to be the same in profiles
0 and 1. When switching decimation factor and therefore output data rate, a settling
transient may take place on the clocking network of the LVDS or if CSI2 the PLL clock
generator within the CSI2 interface relocks to a different output frequency, which takes a
settling time on the order of 60 μs.
*/
	BC_ERRCODE 							errCode = BC_ERR_NOERROR;
	rfeDriverPersistentMem_t            *pDrvState = NULL;
	MIPI_VCNum_t        				selectVCs = {0};
	MIPI_VCClearFrame_t 				clearFrameVCs = {0};
	uint8_t             				mipiNumLanes = 0U;
	MIPI_DataRate_e     				mipiDataRate = e_MIPI_DATARATE_INVALID;
	R2M02_PdcConfigRegUnion_t			PdcConfigReg;

	pDrvState = RfeDrvStateGet();

	SetMipiNumLaneAndDataRate(pDrvState, &mipiNumLanes, &mipiDataRate, chirpSequence, rfe___error___pointer);
	SetMipiVCs(pDrvState, &selectVCs, &clearFrameVCs, chirpSequence, rfe___error___pointer);

	if ( *rfe___error___pointer == rfe_error_none_e)
	{
		if (configLevel >= RFE_MIPI_CONFIG_PDC)
		{
			errCode = BC_MIPI_Config(mipiNumLanes, mipiDataRate);
		}
		if (errCode == BC_ERR_NOERROR)
		{
			errCode = BC_MIPI_ConfigVC(&selectVCs, &clearFrameVCs);
		}
		if (configLevel == RFE_MIPI_CONFIG_FULL)
		{
			if (errCode == BC_ERR_NOERROR)
			{
				errCode = BC_SPI_Read(e_SYS_MIPI, R2M02_PDC_CONFIG_REG_U16, &PdcConfigReg.val_u32);
				if (errCode == BC_ERR_NOERROR)
				{
					PdcConfigReg.bits_st.MakeOutputUnsigned = 0x0u;
					errCode = BC_SPI_WriteCheck(e_SYS_MIPI, R2M02_PDC_CONFIG_REG_U16, PdcConfigReg.val_u32);
				}
			}
			if (errCode == BC_ERR_NOERROR)
			{
				errCode = BC_MIPI_EnTransmission(TRUE);
			}
			// Set TEF82XX CSI2 DPHY to Non-Continuous Clock Mode in order to gracefully initialize CSI2 RX on host
			if (errCode == BC_ERR_NOERROR)
			{
				pDrvState->csi2TxClkNonContinuousMode = 1U;
				errCode = BC_MIPI_EnContinuousClock(FALSE);
			}
		}
		if (errCode != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}
	}
}

static BC_ERRCODE TX_SetLevelRfMin(float32_t LevelRfMin)
{
	BC_ERRCODE   errCode = BC_ERR_NOERROR;

	errCode = BC_TX_SetLevelRfMin(e_SYS_TX1, LevelRfMin);
	if(errCode == BC_ERR_NOERROR)
	{
		errCode = BC_TX_SetLevelRfMin(e_SYS_TX2, LevelRfMin);
	}
	if(errCode == BC_ERR_NOERROR)
	{
		errCode = BC_TX_SetLevelRfMin(e_SYS_TX3, LevelRfMin);
	}

	return errCode;
}

static BC_ERRCODE UpdateLOLowLevelTh(rfeDriverPersistentMem_t *const pDrvState, uint8_t chirpSequence)
{
	BC_ERRCODE   errCode = BC_ERR_NOERROR;
	CAFC_VCOBWSel_e VCOSel = rfeVCOSelMapper((uint8_t)pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[chirpSequence].vcoSel);

	if(VCOSel == e_CAFC_1GBAND)
	{
		errCode = BC_RX_UpdateLOLowLevelTh(e_SYS_RXMC, VCOSel,
				pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[chirpSequence].effFc);
	}

	return errCode;
}

static uint8_t GetPhaseRotatorEnable(const uint8_t * pRfeConfig, rfe_error_t* rfe___error___pointer)
{
	uint8_t idx = 0U;
	uint8_t txIdx = 0U;
	uint8_t prEnable = 0U;
	uint8_t phaseVal = 0U;

	for(idx = 0U; idx < rfeCfg_metadata_getChirpProfileCount(pRfeConfig, rfe___error___pointer); ++idx)
	{
		for(txIdx = 0U; txIdx < (uint8_t)RFE_MAX_TX_CHANNELS; ++txIdx)
		{
			if (*rfe___error___pointer != rfe_error_none_e)
			{
				break;
			}
			phaseVal = (uint8_t)rfeCfg_chirpProfile_getTxPhaseRotation(pRfeConfig, (rfe_chirpProfileIndex_t)idx, (rfe_txIndex_t)txIdx, rfe___error___pointer);
			if(phaseVal != 0U)
			{
				prEnable = 1U;
				break;
			}
		}
		if ((*rfe___error___pointer != rfe_error_none_e) || (prEnable != 0U))
		{
			break;
		}
	}

	return prEnable;
}

static void LoiConfigBbd(rfeDriverPersistentMem_t *const pDrvState, rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE	errCode = BC_ERR_NOERROR;

	if(RfeDrvStateConfigurationGet() == rfeFrontEnd_Cascaded_e)
	{
		if ((pDrvState->tef82xxDrvState.LoIGrounded == (BOOL)FALSE) &&
					(pDrvState->tef82xxDrvState.LoOutGrounded == (BOOL)FALSE))
		{
			errCode = BC_LOI_ConfigBBD((BOOL)FALSE, (BOOL)FALSE,
					pDrvState->tef82xxDrvState.LoISensitivity, pDrvState->tef82xxDrvState.LoIGrounded,
					pDrvState->tef82xxDrvState.LoOutSensitivity, pDrvState->tef82xxDrvState.LoOutGrounded);
			if (errCode == BC_ERR_NOERROR)
			{
				errCode = BC_ISM_ConfigLOIBBDMonitor((BOOL)TRUE);
			}
		}
		else
		{
			if(pDrvState->frontendId != (uint8_t)rfeFrontEndId_0)
			{
				errCode = BC_LOI_ConfigBBD(pDrvState->tef82xxDrvState.loiBbdEn, (BOOL)FALSE,
						pDrvState->tef82xxDrvState.LoISensitivity, pDrvState->tef82xxDrvState.LoIGrounded,
						pDrvState->tef82xxDrvState.LoOutSensitivity, pDrvState->tef82xxDrvState.LoOutGrounded);
			}
			else
			{
				errCode = BC_LOI_ConfigBBD(pDrvState->tef82xxDrvState.loiBbdEn, pDrvState->tef82xxDrvState.loiBbdEn,
						pDrvState->tef82xxDrvState.LoISensitivity, pDrvState->tef82xxDrvState.LoIGrounded,
						pDrvState->tef82xxDrvState.LoOutSensitivity, pDrvState->tef82xxDrvState.LoOutGrounded);
			}
		}
	}
	else
	{
		errCode = BC_LOI_ConfigBBD((BOOL)FALSE, (BOOL)FALSE,
				pDrvState->tef82xxDrvState.LoISensitivity, pDrvState->tef82xxDrvState.LoIGrounded,
				pDrvState->tef82xxDrvState.LoOutSensitivity, pDrvState->tef82xxDrvState.LoOutGrounded);
	}
	if (errCode != BC_ERR_NOERROR)
	{
		*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
	}
}

static void TxConfigBbd(rfeDriverPersistentMem_t *const pDrvState, rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE				errCode = BC_ERR_NOERROR;
	uint8_t bbd = 0;
	BOOL bbdTxEneble = (BOOL)FALSE;
	BOOL bbdTxSensitivity = (BOOL)FALSE;
	BOOL bbdTxGrounded = (BOOL)FALSE;

	if (*rfe___error___pointer == rfe_error_none_e)
	{
		bbd = rfeCfg_monitorAndSafety_getTxBBD(pDrvState->rfeConfig, rfe___error___pointer);
		bbdTxEneble = ConvertUint8ToBool((bbd >> 2U) & 0x01U);
		bbdTxSensitivity = ConvertUint8ToBool((bbd >> 1U) & 0x01U);
		bbdTxGrounded = ConvertUint8ToBool(bbd & 0x01U);
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		errCode = BC_TX_ConfigBBD(e_SYS_TXMC, bbdTxEneble, bbdTxSensitivity, bbdTxGrounded);
		if (errCode != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}
	}
}

static void RxConfigBbd(rfeDriverPersistentMem_t *const pDrvState, rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE				errCode = BC_ERR_NOERROR;
	uint8_t bbd = 0;
	BOOL bbdRxEneble = (BOOL)FALSE;
	BOOL bbdRxSensitivity = (BOOL)FALSE;
	BOOL bbdRxGrounded = (BOOL)FALSE;

	if (*rfe___error___pointer == rfe_error_none_e)
	{
		bbd = rfeCfg_monitorAndSafety_getRxBBD(pDrvState->rfeConfig, rfe___error___pointer);
		bbdRxEneble = ConvertUint8ToBool((bbd >> 2U) & 0x01U);
		bbdRxSensitivity = ConvertUint8ToBool((bbd >> 1U) & 0x01U);
		bbdRxGrounded = ConvertUint8ToBool(bbd & 0x01U);
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		errCode = BC_RX_ConfigBBD(e_SYS_RXMC, bbdRxEneble, bbdRxSensitivity, bbdRxGrounded);
		if (errCode != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}
	}
}

static void StandaloneOrLeaderConfig(uint8_t chirpSequence, rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE errCode = BC_ERR_NOERROR;

	if(*rfe___error___pointer == rfe_error_none_e)
	{
		CAFC_ConfigLoopFilter(chirpSequence, rfe___error___pointer);
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		//Configure fast reset
		errCode = BC_CAFC_ConfigFastReturn((BOOL)TEF82XX_DEFAULT_FAST_DISCHARGE_GS_ENABLE,
				(BOOL)TEF82XX_DEFAULT_FAST_DISCHARGE_CURR_INJ_ENABLE);
		if (errCode == BC_ERR_NOERROR)
		{
			errCode = BC_CAFC_ConfigStatic(
					(BOOL)TEF82XX_DEFAULT_CAFC_STATIC_ENABLE_CP, (BOOL)TEF82XX_DEFAULT_CAFC_STATIC_ENABLE_VCO_LDO,
					(BOOL)TEF82XX_DEFAULT_CAFC_STATIC_ENABLE_DIV_LDO, (BOOL)TEF82XX_DEFAULT_CAFC_STATIC_ENABLE_CPPFD_LDO,
					(BOOL)TEF82XX_DEFAULT_CAFC_STATIC_ENABLE_ALL_BIAS);	//CAFC static configuration
		}
		if (errCode == BC_ERR_NOERROR)
		{
			errCode = BC_CAFC_SetVtuneVoltage(TEF82XX_DEFAULT_FORCE_VTUNE_START_VOLTAGE,
					TEF82XX_DEFAULT_FORCE_VTUNE_CENTER_VOLTAGE);	//SetVtune voltage
		}
		if (errCode == BC_ERR_NOERROR)
		{
			errCode = BC_CAFC_EnableVCO(TRUE);	//Enable VCO
		}
		if(errCode != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}
	}
}

static void AllFE_Config(rfeDriverPersistentMem_t *const pDrvState, uint8_t chirpSequence,
		rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE errCode = BC_ERR_NOERROR;
	rfeRxFilterCtrlParams_t rxFilterCtrlParam = { 0 };

	errCode = TX_SetLevelRfMin((float32_t)4.0);	//Set TX RF level min threshold
	if (errCode == BC_ERR_NOERROR)
	{
		errCode = BC_TX_SetRFCalMonLevel(e_SYS_TXMC, TX_LEVEL_RF_HIGH_DELTA, TX_LEVEL_RF_LOW_DELTA);
	}
	if (errCode == BC_ERR_NOERROR)
	{
		MIPI_Config(RFE_MIPI_CONFIG_FULL, rfeChirpSequenceMapper(chirpSequence), rfe___error___pointer);
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		RfeSwCfgTimingReqGetRxFilterCtrlParams(&rxFilterCtrlParam, rfe___error___pointer);
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		errCode = BC_TE_SetRxFilterCtrls(rxFilterCtrlParam.hpfResetReleaseCtrl,
										 rxFilterCtrlParam.rxActiveCtrl,
										 rxFilterCtrlParam.hpfResetReleaseDelay_us,
										 rxFilterCtrlParam.rxActiveDelay_us);
		if (errCode == BC_ERR_NOERROR)
		{
			errCode = UpdateLOLowLevelTh(pDrvState, chirpSequence);	//Configure LOI level threshold
		}
		if ((errCode == BC_ERR_NOERROR) &&
				(pDrvState->tef82xxDrvState.txPhaseErrorWa1Enabled == (uint8_t)TRUE))
		{
			// Required for the TX phase WA to initialize the SSB, decimation factor is not important for the WA, therefore hard coded
			// If RFBIST is used, this function must be called again and configured with the RFBIST decimation factor
			errCode = BC_SSB_RFBISTStaticConfig(TEF82XX_DECIMATION_ADC_40MSPS);
		}
	}
	if(errCode != BC_ERR_NOERROR)
	{
		*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
	}
}
static void StaticConfig(rfeDriverPersistentMem_t *const pDrvState, uint8_t *pRfeConfig,
		uint8_t chirpSequence, rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE				errCode = BC_ERR_NOERROR;

	if (*rfe___error___pointer == rfe_error_none_e)
	{
		LoiConfigBbd(pDrvState, rfe___error___pointer);
	}

	TxConfigBbd(pDrvState, rfe___error___pointer);
	RxConfigBbd(pDrvState, rfe___error___pointer);

	// Required for the TX Phase imbalance workaround 1
	// Disable common biasing, such that bias of the SSB can be controlled to save power
	if ((*rfe___error___pointer == rfe_error_none_e) &&
			(pDrvState->tef82xxDrvState.txPhaseErrorWa1Enabled == (uint8_t)TRUE))
	{
		errCode = BC_GBIAS_SelectCommonBias(FALSE);

		if(errCode != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}
	}

	if (*rfe___error___pointer == rfe_error_none_e)
	{
		StaticConfigIO(pDrvState, rfe___error___pointer);	//Configure pad & Configure CS OUT
	}
	// power mode config
	if ((*rfe___error___pointer == rfe_error_none_e) &&
		(pDrvState->frontendMode != RFE_CASCADING_FOLLOWER) &&
		(pDrvState->tef82xxDrvState.chirpPowerSavingEnabled == (uint8_t)TRUE))   // Add here CPM TX Mode Enabled
	{
		errCode = BC_SC_EnDivHardFuncReset(TRUE, FALSE, FALSE, FALSE);
		if(errCode != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}		
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		TE_ConfigStatic(chirpSequence, pRfeConfig, rfe___error___pointer);
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		TE_ConfigProfileSequencing(chirpSequence, rfe___error___pointer);	//Configure profile sequence
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		SetChirpTrgMode(pDrvState, chirpSequence, rfe___error___pointer);	//Set chirp trigger mode
	}
	// Settings only for STANDALONE or LEADER frontends
	if (pDrvState->frontendMode != RFE_CASCADING_FOLLOWER)
	{
		StandaloneOrLeaderConfig(chirpSequence, rfe___error___pointer);
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		AllFE_Config(pDrvState, chirpSequence, rfe___error___pointer);
	}
}



static void SetTxChannelEnable(uint8_t *pRfeConfig, rfeDriverPersistentMem_t *pDrvState, rfe_error_t* rfe___error___pointer)
{
	uint8_t 	profileIdx = 0;
	uint8_t		noChirpProfiles = rfeCfg_metadata_getChirpProfileCount(pRfeConfig, rfe___error___pointer);

	if (*rfe___error___pointer == rfe_error_none_e)
	{
		for (profileIdx = 0; profileIdx < noChirpProfiles; profileIdx++)
		{
			pDrvState->tef82xxDrvState.txChannelEnable[profileIdx] = rfeCfg_chirpProfile_getTxTransmissionEnable(
					pRfeConfig, (rfe_chirpProfileIndex_t)profileIdx, rfe___error___pointer);
			if (*rfe___error___pointer != rfe_error_none_e)
			{
				pDrvState->tef82xxDrvState.txChannelEnable[profileIdx] = 0;
				break;
			}
		}
	}
}

static void GetIdxProfileClosestToMeanCenterFrequency(uint8_t *pRfeConfig, rfeDriverPersistentMem_t *pDrvState,
		rfe_error_t* rfe___error___pointer)
{
	uint8_t 	profileIdx = 0;
	uint8_t		noChirpProfiles = rfeCfg_metadata_getChirpProfileCount(pRfeConfig, rfe___error___pointer);
	uint32_t 	centerFrequency[RFE_MAX_CHIRP_PROFILES] = {0};
	uint32_t	meanCenterFreq = 0;
	int32_t  	freqDiff = 0;
	int32_t  	minCenterFreqDelta = (int32_t)(RFE_TEF82XX_MAX_CENTER_FREQUENCY) -
			(int32_t)(RFE_TEF82XX_MIN_CENTER_FREQUENCY);

	// Identify profile closest to the mean center frequency of all profiles configured
	// and save this in the persistent memory for calibration purposes
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		for (profileIdx = 0; profileIdx < noChirpProfiles; profileIdx++)
		{
			centerFrequency[profileIdx] = rfeCfg_chirpProfile_getCenterFrequency(pRfeConfig, (rfe_chirpProfileIndex_t)profileIdx, rfe___error___pointer);
			if (*rfe___error___pointer != rfe_error_none_e)
			{
				break;
			}
			meanCenterFreq += centerFrequency[profileIdx];
		}

		if (*rfe___error___pointer == rfe_error_none_e)
		{
			meanCenterFreq = meanCenterFreq / noChirpProfiles;

			for (profileIdx = 0; profileIdx < noChirpProfiles; profileIdx++)
			{
				freqDiff = (int32_t)centerFrequency[profileIdx] - (int32_t)meanCenterFreq;
				if (labs(freqDiff) < minCenterFreqDelta)
				{
					minCenterFreqDelta = (int32_t)labs(freqDiff);
							pDrvState->tef82xxDrvState.meanCenterFreqProf = profileIdx;
				}
			}
		}
	}
}

static void ConfigFrequencyDrift(rfeDriverPersistentMem_t *pDrvState, uint8_t profileIdx,
		rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE					errCode = BC_ERR_NOERROR;
	float32_t 					freqDriftHz = 0.0f;
	float32_t					tReset = 0.0f;

	if (*rfe___error___pointer == rfe_error_none_e)
	{
		tReset = (float32_t)rfeCfg_chirpProfile_getResetTimeTicks(pDrvState->rfeConfig, rfeChirpProfileMapper(profileIdx), rfe___error___pointer) * TICK_TO_US;
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		freqDriftHz = ((float32_t) rfeCfg_chirpSequence_getChirpFrequencyDriftSteps(pDrvState->rfeConfig, rfeChirpProfileMapper(profileIdx), rfe___error___pointer) * STEP_TO_HZ);
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		if((fabsf((freqDriftHz - TEF82XX_DISABLE_FREQ_AUTO_DRIFT))) > DELTA_FLOAT)
		{
			if((freqDriftHz > TEF82XX_MAX_FREQ_AUTO_DRIFT) || (freqDriftHz <= TEF82XX_MIN_FREQ_AUTO_DRIFT))
			{
				*rfe___error___pointer = rfe_error_bc_scInputFreqDriftInvalid;
			}
			else
			{
				errCode = BC_SC_ConfigSlowDriftChirp(rfeProfModeSelMapper(profileIdx), freqDriftHz, tReset, 0.0f);
				if (errCode == BC_ERR_NOERROR)
				{
					// Enable the Automatic sub band switching. This is required to implement the slow drift modulation.
					// SubbandSteps hardcoded to 1 as advised by TEF82XX team
					errCode = BC_SYS_AutoSubbandSwitching((BOOL)TRUE, 1);
				}
				if (errCode != BC_ERR_NOERROR)
				{
					*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
				}
			}
		}
	}
}

static void SetRFTargetPower(rfeDriverPersistentMem_t *pDrvState, uint8_t profileIdx,
		rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE					errCode = BC_ERR_NOERROR;
	float32_t 					txPower = 0.0f;
	uint8_t						txSW[RFE_MAX_TX_CHANNELS];

	if (*rfe___error___pointer == rfe_error_none_e)
	{
		txSW[0] = (pDrvState->tef82xxDrvState.txChannelEnable[profileIdx] >> RFE_TX_CHANNEL_0) & 0x01U;
		txSW[1] = (pDrvState->tef82xxDrvState.txChannelEnable[profileIdx] >> RFE_TX_CHANNEL_1) & 0x01U;
		txSW[2] = (pDrvState->tef82xxDrvState.txChannelEnable[profileIdx] >> RFE_TX_CHANNEL_2) & 0x01U;

		txPower = (float32_t)rfeCfg_chirpProfile_getTxPower(pDrvState->rfeConfig, rfeChirpProfileMapper(profileIdx), rfe___error___pointer) / TENTHS_OF_DB_TO_DB;
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		if(txSW[0] != 0U)
		{
			pDrvState->tef82xxDrvState.txChannelPower[profileIdx][RFE_TX_CHANNEL_0] = txPower;
		}
		else
		{
			pDrvState->tef82xxDrvState.txChannelPower[profileIdx][RFE_TX_CHANNEL_0] = TEF82XX_DISABLED_TX;
		}
		if(txSW[1] != 0U)
		{
			pDrvState->tef82xxDrvState.txChannelPower[profileIdx][RFE_TX_CHANNEL_1] = txPower;
		}
		else
		{
			pDrvState->tef82xxDrvState.txChannelPower[profileIdx][RFE_TX_CHANNEL_1] = TEF82XX_DISABLED_TX;
		}
		if(txSW[2] != 0U)
		{
			pDrvState->tef82xxDrvState.txChannelPower[profileIdx][RFE_TX_CHANNEL_2] = txPower;
		}
		else
		{
			pDrvState->tef82xxDrvState.txChannelPower[profileIdx][RFE_TX_CHANNEL_2] = TEF82XX_DISABLED_TX;
		}
		if ((fabsf((txPower - RFE_TEF82XX_SET_MAX_SAFE_TX_POWER))) <= DELTA_FLOAT)

		{
			errCode = BC_TX_SetMaxSafePOutTarget(rfeProfModeSelMapper(profileIdx), e_SYS_TXMC, 3U);
		}
		else
		{
			// broadcast set TX power for all channels
			// ES2.1 TEF82XX bug - on ES2.2 is not longer present
			if ((pDrvState->tef82xxDrvState.txChannelEnable[profileIdx]) != 0UL)
			{
				errCode = BC_TX_SetRFTargetPower(rfeProfModeSelMapper(profileIdx), e_SYS_TXMC, txPower);
			}
		}
		if (errCode != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}
	}
}

static void ProgramProfile(rfeDriverPersistentMem_t *pDrvState, uint8_t profileIdx,
		uint8_t	rxChannelEnable, rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE					errCode = BC_ERR_NOERROR;
	uint8_t						rxEn[RFE_MAX_RX_CHANNELS];
	uint8_t						txEn[RFE_MAX_TX_CHANNELS];
	uint8_t						txSW[RFE_MAX_TX_CHANNELS];
	uint8_t						txBPS[RFE_MAX_TX_CHANNELS];
	float32_t					txPhase[RFE_MAX_TX_CHANNELS];
	SYS_ProfChirpTiming_t		profChirpTiming;
	SYS_ProfChirpFreq_t			profChirpFreq;
	SYS_ProfChirpSampleDeci_t	profChirpSample;
	uint8_t						phaseIdx;
	rfe_rxGain_t 				rxCfgGain = rfe_rxGain_25dB_e;
	rfeRxLpfCutOff_t 			lpfCutOff = RFE_RX_LPF_CUTOFF_12_5MHZ;
	rfeRxHpfCutOff_t 			hpfCutOff = RFE_RX_HPF_CUTOFF_100KHZ;
	uint8_t						memIdx;
	RX_Gain_Control_e			rxGain[RFE_MAX_RX_CHANNELS];
	SYS_RXLPF_CornerFreq_e		rxLPF[RFE_MAX_RX_CHANNELS];
	SYS_RXHPF_CornerFreq_e		rxHPF[RFE_MAX_RX_CHANNELS];

	if (*rfe___error___pointer == rfe_error_none_e)
	{
		// RX is enabled the same for all profiles
		rxEn[0] = (rxChannelEnable >> RFE_RX_CHANNEL_0) & 0x01U;
		rxEn[1] = (rxChannelEnable >> RFE_RX_CHANNEL_1) & 0x01U;
		rxEn[2] = (rxChannelEnable >> RFE_RX_CHANNEL_2) & 0x01U;
		rxEn[3] = (rxChannelEnable >> RFE_RX_CHANNEL_3) & 0x01U;

		txEn[0] = ((uint8_t)pDrvState->tef82xxDrvState.txChannelEnable[profileIdx] >> RFE_TX_CHANNEL_0) & 0x01U;
		txEn[1] = ((uint8_t)pDrvState->tef82xxDrvState.txChannelEnable[profileIdx] >> RFE_TX_CHANNEL_1) & 0x01U;
		txEn[2] = ((uint8_t)pDrvState->tef82xxDrvState.txChannelEnable[profileIdx] >> RFE_TX_CHANNEL_2) & 0x01U;
		GetProfChirpTiming(&profChirpTiming, profileIdx, pDrvState->rfeConfig, rfe___error___pointer);
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		GetProfChirpFreq(&profChirpFreq, profileIdx, pDrvState->rfeConfig, rfe___error___pointer);
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		txSW[0] = ((uint8_t)pDrvState->tef82xxDrvState.txChannelEnable[profileIdx] >> RFE_TX_CHANNEL_0) & 0x01U;
		txSW[1] = ((uint8_t)pDrvState->tef82xxDrvState.txChannelEnable[profileIdx] >> RFE_TX_CHANNEL_1) & 0x01U;
		txSW[2] = ((uint8_t)pDrvState->tef82xxDrvState.txChannelEnable[profileIdx] >> RFE_TX_CHANNEL_2) & 0x01U;

		txBPS[0] = (uint8_t)TEF82XX_DEFAULT_TX_BPS;
		txBPS[1] = (uint8_t)TEF82XX_DEFAULT_TX_BPS;
		txBPS[2] = (uint8_t)TEF82XX_DEFAULT_TX_BPS;
		GetProfChirpSample(&profChirpSample, profileIdx, pDrvState->rfeConfig, rfe___error___pointer);
	}
	for(phaseIdx = 0; phaseIdx < (uint8_t)RFE_MAX_TX_CHANNELS; ++phaseIdx)
	{
		if (*rfe___error___pointer != rfe_error_none_e)
		{
			break;
		}
		txPhase[phaseIdx] = (float32_t) rfeCfg_chirpProfile_getTxPhaseRotation(pDrvState->rfeConfig, rfeChirpProfileMapper(profileIdx), rfeTxIndexMapper(phaseIdx),
				rfe___error___pointer) * BLOB_PHASE_TO_PHASE_DEGREE;
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		rxCfgGain = RxGainMapper(rfeCfg_chirpProfile_getRxGain(pDrvState->rfeConfig, rfeChirpProfileMapper(profileIdx), rfe___error___pointer));
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		lpfCutOff = rfeRxLpfCutOffMapper(rfeCfg_chirpProfile_getRxLpfCutOffFrequency(pDrvState->rfeConfig, rfeChirpProfileMapper(profileIdx), rfe___error___pointer));
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		hpfCutOff = rfeRxHpfCutOffMapper(rfeCfg_chirpProfile_getRxHpfCutOffFrequency(pDrvState->rfeConfig, rfeChirpProfileMapper(profileIdx), rfe___error___pointer));
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		// rsdk to bc enum mapping
		for(memIdx = 0; memIdx < (uint8_t)RFE_MAX_RX_CHANNELS; memIdx++)
		{
			rxGain[memIdx] = RxGainControlMapper(rxCfgGain);
			rxLPF[memIdx] = rfeRxLPFMapper(lpfCutOff);
			rxHPF[memIdx] = rfeRxHPFMapper(hpfCutOff);
		}
		if(pDrvState->tef82xxDrvState.meanCenterFreqProf == profileIdx)
		{
			pDrvState->tef82xxDrvState.meanCenterFreqProfTiming = profChirpTiming;
			pDrvState->tef82xxDrvState.meanCenterFreqProfFreq = profChirpFreq;
		}
		errCode = BC_SYS_ProgramChirp(rfeProfModeSelMapper(profileIdx), &profChirpTiming, &profChirpFreq, &profChirpSample,
								  txBPS, txPhase, txSW, txEn, rxEn, rxGain, rxLPF, rxHPF);
		if (errCode != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}
	}

	// check if chirp frequency drift is enabled, (freqDriftHz != 0)
	ConfigFrequencyDrift(pDrvState, profileIdx, rfe___error___pointer);
	SetRFTargetPower(pDrvState, profileIdx, rfe___error___pointer);
}

static void ProfileConfig(rfeDriverPersistentMem_t *pDrvState, uint8_t *pRfeConfig,	uint8_t chirpSequence,
		rfe_error_t* rfe___error___pointer)
{
	uint8_t						rxChannelEnable = 0;
	uint8_t						profileIdx;
	uint8_t						sequenceIdx;
	uint8_t						noChirpProfiles = rfeCfg_metadata_getChirpProfileCount(pRfeConfig, rfe___error___pointer);

	// Get enabled TX channels for profiles
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		SetTxChannelEnable(pRfeConfig, pDrvState, rfe___error___pointer);
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		rxChannelEnable = rfeCfg_chirpSequence_getRxEnable(pRfeConfig, (rfe_chirpSequenceIndex_t)chirpSequence, rfe___error___pointer);
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		// Identify profile closest to the mean center frequency of all profiles configured
		GetIdxProfileClosestToMeanCenterFrequency(pRfeConfig, pDrvState, rfe___error___pointer);
	}
	// Why this is configured for all sequences
	for(sequenceIdx = 0; sequenceIdx < rfeCfg_metadata_getChirpSequenceConfigCount(pRfeConfig, rfe___error___pointer); ++sequenceIdx)
	{
		if (*rfe___error___pointer != rfe_error_none_e)
		{
			break;
		}
		SetSequenceProfChirpParam( pRfeConfig, sequenceIdx, rfe___error___pointer);
	}

	for (profileIdx = 0; profileIdx < noChirpProfiles; profileIdx++)
	{
		// program chirp profiles
		if (*rfe___error___pointer != rfe_error_none_e)
		{
			break;
		}
		ProgramProfile(pDrvState, profileIdx, rxChannelEnable, rfe___error___pointer);
	}
}

static inline BOOL GetBitFromFuSaMask(uint8_t fuSaFaultMask, uint8_t bit)
{
	return (BOOL)((fuSaFaultMask >> bit) & 0x01U);
}

static void SetTxFuSaMask(uint8_t* pRfeConfig, rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE errCode;
	uint8_t fuSaFaultMask = 0;
	SYS_TXErrors_t Tx1Err = {FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE };
	SYS_TXErrors_t Tx2Err = {FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE };
	SYS_TXErrors_t Tx3Err = {FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE };

	fuSaFaultMask = rfeCfg_monitorAndSafety_getFuSaFaultMask(pRfeConfig, rfe_fuSaFaultMaskIndex_0_e,
			rfe___error___pointer);

	if(*rfe___error___pointer  == rfe_error_none_e)
	{
		Tx3Err.TxSupply1v1LowErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v1_tx3_e & 0x00ffu));
		Tx2Err.TxSupply1v1LowErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v1_tx2_e & 0x00ffu));
		Tx1Err.TxSupply1v1LowErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v1_tx1_e & 0x00ffu));
		Tx3Err.TxPRErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr72_pr_tx3_e & 0x00ffu));
		Tx2Err.TxPRErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr72_pr_tx2_e & 0x00ffu));
		Tx1Err.TxPRErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr72_pr_tx1_e & 0x00ffu));
		Tx3Err.TxSupply1v8LowErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v8_tx3_e & 0x00ffu));
		Tx2Err.TxSupply1v8LowErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v8_tx2_e & 0x00ffu));
	}
	if(*rfe___error___pointer  == rfe_error_none_e)
	{
		fuSaFaultMask = rfeCfg_monitorAndSafety_getFuSaFaultMask(pRfeConfig, rfe_fuSaFaultMaskIndex_1_e, rfe___error___pointer);

		if(*rfe___error___pointer  == rfe_error_none_e)
		{
			Tx1Err.TxSupply1v8LowErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v8_tx1_e & 0x00ffu));
			Tx3Err.TxRfLevelMaxErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr69_rf_level_max_tx3_e & 0x00ffu));
			Tx2Err.TxRfLevelMaxErr  = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr69_rf_level_max_tx2_e & 0x00ffu));
			Tx1Err.TxRfLevelMaxErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr69_rf_level_max_tx1_e & 0x00ffu));
			Tx3Err.TxRfLevelMinErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr69_rf_level_min_tx3_e & 0x00ffu));
			Tx2Err.TxRfLevelMinErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr69_rf_level_min_tx2_e & 0x00ffu));
			Tx1Err.TxRfLevelMinErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr69_rf_level_min_tx1_e & 0x00ffu));
			Tx3Err.TxRFConnectionErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr27_bb_tx3_e & 0x00ffu));
		}
	}
	if(*rfe___error___pointer  == rfe_error_none_e)
	{
		fuSaFaultMask = rfeCfg_monitorAndSafety_getFuSaFaultMask(pRfeConfig, rfe_fuSaFaultMaskIndex_2_e, rfe___error___pointer);

		if(*rfe___error___pointer  == rfe_error_none_e)
		{
			Tx2Err.TxRFConnectionErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr27_bb_tx2_e & 0x00ffu));
			Tx1Err.TxRFConnectionErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr27_bb_tx1_e & 0x00ffu));
		}
	}
	if(*rfe___error___pointer  == rfe_error_none_e)
	{
		fuSaFaultMask = rfeCfg_monitorAndSafety_getFuSaFaultMask(pRfeConfig, rfe_fuSaFaultMaskIndex_9_e,
					rfe___error___pointer);

		if(*rfe___error___pointer  == rfe_error_none_e)
		{
			Tx3Err.TxRegCRCErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr3_reg_crc_e & 0x00ffu));
			Tx2Err.TxRegCRCErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr3_reg_crc_e & 0x00ffu));
			Tx1Err.TxRegCRCErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr3_reg_crc_e & 0x00ffu));
		
			errCode = BC_ISM_MaskRTMSetClrTxErr(e_ISM_ERR_OP_MASK_ERR, &Tx1Err, &Tx2Err, &Tx3Err);

			if(errCode != BC_ERR_NOERROR)
			{
				*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
			}
		}
	}
}

static void SetRxFuSaMask(uint8_t* pRfeConfig, rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE errCode;
	uint8_t fuSaFaultMask = 0;
	SYS_RXErrors_t Rx1Err = {FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE};
	SYS_RXErrors_t Rx2Err = {FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE};
	SYS_RXErrors_t Rx3Err = {FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE};
	SYS_RXErrors_t Rx4Err = {FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE};

	fuSaFaultMask = rfeCfg_monitorAndSafety_getFuSaFaultMask(pRfeConfig, rfe_fuSaFaultMaskIndex_2_e,
			rfe___error___pointer);

	if(*rfe___error___pointer  == rfe_error_none_e)
	{
		Rx4Err.RxSupply1V8LowErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v8_rx4_e & 0x00ffu));
		Rx3Err.RxSupply1V8LowErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v8_rx3_e & 0x00ffu));
		Rx2Err.RxSupply1V8LowErr  = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v8_rx2_e & 0x00ffu));
		Rx1Err.RxSupply1V8LowErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v8_rx1_e & 0x00ffu));
		Rx4Err.RxSupply1V1LowErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v1_rx4_e & 0x00ffu));
		Rx3Err.RxSupply1V1LowErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v1_rx3_e & 0x00ffu));
	}
	if(*rfe___error___pointer  == rfe_error_none_e)
	{
		fuSaFaultMask = rfeCfg_monitorAndSafety_getFuSaFaultMask(pRfeConfig, rfe_fuSaFaultMaskIndex_3_e,
					rfe___error___pointer);

		if(*rfe___error___pointer  == rfe_error_none_e)
		{
			Rx2Err.RxSupply1V1LowErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v1_rx2_e & 0x00ffu));
			Rx1Err.RxSupply1V1LowErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v1_rx1_e & 0x00ffu));
			Rx4Err.RxLOLevelMaxErr  = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr47_lo_level_max_rx4_e & 0x00ffu));
			Rx3Err.RxLOLevelMaxErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr47_lo_level_max_rx3_e & 0x00ffu));
			Rx2Err.RxLOLevelMaxErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr47_lo_level_max_rx2_e & 0x00ffu));
			Rx1Err.RxLOLevelMaxErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr47_lo_level_max_rx1_e & 0x00ffu));
			Rx4Err.RxLOLevelMinErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr47_lo_level_min_rx4_e & 0x00ffu));
			Rx3Err.RxLOLevelMinErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr47_lo_level_min_rx3_e & 0x00ffu));
		}
	}
	if(*rfe___error___pointer  == rfe_error_none_e)
	{
		fuSaFaultMask = rfeCfg_monitorAndSafety_getFuSaFaultMask(pRfeConfig, rfe_fuSaFaultMaskIndex_4_e, rfe___error___pointer);

		if(*rfe___error___pointer  == rfe_error_none_e)
		{
			Rx2Err.RxLOLevelMinErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr47_lo_level_min_rx2_e & 0x00ffu));
			Rx1Err.RxLOLevelMinErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr47_lo_level_min_rx1_e & 0x00ffu));
			Rx4Err.RxRFConnectionErr  = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr9_bb_rx4_e & 0x00ffu));
			Rx3Err.RxRFConnectionErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr9_bb_rx3_e & 0x00ffu));
			Rx2Err.RxRFConnectionErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr9_bb_rx2_e & 0x00ffu));
			Rx1Err.RxRFConnectionErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr9_bb_rx1_e & 0x00ffu));
		}
	}
	if(*rfe___error___pointer  == rfe_error_none_e)
	{
		fuSaFaultMask = rfeCfg_monitorAndSafety_getFuSaFaultMask(pRfeConfig, rfe_fuSaFaultMaskIndex_9_e, rfe___error___pointer);

		if(*rfe___error___pointer  == rfe_error_none_e)
		{
			Rx4Err.RxRegCRCErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr3_reg_crc_e & 0x00ffu));
			Rx3Err.RxRegCRCErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr3_reg_crc_e & 0x00ffu));
			Rx2Err.RxRegCRCErr  = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr3_reg_crc_e & 0x00ffu));
			Rx1Err.RxRegCRCErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr3_reg_crc_e & 0x00ffu));
			errCode = BC_ISM_MaskRTMSetClrRxErr(e_ISM_ERR_OP_MASK_ERR, &Rx1Err, &Rx2Err, &Rx3Err, &Rx4Err);

			if(errCode != BC_ERR_NOERROR)
			{
				*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
			}
		}
	}
}

static void SetChirpFuSaMask(uint8_t* pRfeConfig, rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE errCode;
	uint8_t fuSaFaultMask = 0;
	SYS_CAFCErrors_t chirpErr = {FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE,
			FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE};

	fuSaFaultMask = rfeCfg_monitorAndSafety_getFuSaFaultMask(pRfeConfig, rfe_fuSaFaultMaskIndex_4_e, rfe___error___pointer);

	if(*rfe___error___pointer  == rfe_error_none_e)
	{
		chirpErr.AAFCCalTimeoutErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr46_aafc_cal_timeout_chirp_e & 0x00ffu));
		chirpErr.AAFCDigitalErr  = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr46_aafc_chirp_e & 0x00ffu));
	}
	if(*rfe___error___pointer  == rfe_error_none_e)
	{

		fuSaFaultMask = rfeCfg_monitorAndSafety_getFuSaFaultMask(pRfeConfig, rfe_fuSaFaultMaskIndex_5_e,
				rfe___error___pointer);

		if(*rfe___error___pointer  == rfe_error_none_e)
		{
			chirpErr.ChirpDigSupply1v1LowErrorErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v1_chirp_e & 0x00ffU));
			chirpErr.ChirpVCOSupply1v8vLowErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_vco_1v8_chirp_e & 0x00ffU));
			chirpErr.ChirpPLLSupply1v8vLowErr  = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_pll_1v8_chirp_e & 0x00ffU));
			chirpErr.InterfaceStuckatErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr7_interface_stuck_chirp_e & 0x00ffU));
			chirpErr.VCOFrequency480Err = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr42_vco_freq_480_chirp_e & 0x00ffU));
			chirpErr.VCOLevelMaxErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr45_level_max_chirp_e & 0x00ffU));
			chirpErr.VCOLevelMinErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr45_level_min_chirp_e & 0x00ffU));
			chirpErr.PLLUnlockErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr43_unlock_chirp_e & 0x00ffU));
		}
	}
	if(*rfe___error___pointer  == rfe_error_none_e)
	{

		fuSaFaultMask = rfeCfg_monitorAndSafety_getFuSaFaultMask(pRfeConfig, rfe_fuSaFaultMaskIndex_6_e, rfe___error___pointer);

		if(*rfe___error___pointer  == rfe_error_none_e)
		{
			chirpErr.ChirpDigitalLockStepErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr7_lock_step_chirp_e & 0x00ffu));
		}
	}
	if(*rfe___error___pointer  == rfe_error_none_e)
	{

		fuSaFaultMask = rfeCfg_monitorAndSafety_getFuSaFaultMask(pRfeConfig, rfe_fuSaFaultMaskIndex_9_e,
				rfe___error___pointer);

		if(*rfe___error___pointer  == rfe_error_none_e)
		{
			chirpErr.CAFCRegCRCErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr3_reg_crc_e & 0x00ffu));

			errCode = BC_ISM_MaskRTMSetClrChirpErr(e_ISM_ERR_OP_MASK_ERR, &chirpErr);

			if(errCode != BC_ERR_NOERROR)
			{
				*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
			}
		}
	}
}

static void SetMCOIFuSaMask(uint8_t* pRfeConfig, rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE errCode;
	uint8_t fuSaFaultMask = 0;
	BOOL OTPRegCRCErr = FALSE;
	BOOL ISMRegCRCErr = FALSE;
	SYS_MCLKErrors_t MClkErr = {FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE};
	SYS_LOIErrors_t LOIErr = {FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE};
	SYS_CCErrors_t CCErr = {FALSE, FALSE, FALSE};

	fuSaFaultMask = rfeCfg_monitorAndSafety_getFuSaFaultMask(pRfeConfig, rfe_fuSaFaultMaskIndex_6_e,
			rfe___error___pointer);

	if(*rfe___error___pointer  == rfe_error_none_e)
	{
		LOIErr.LOILevelMaxErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr48_level_max_loi_e & 0x00ffu));
		LOIErr.LOILeveMinErr  = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr48_level_min_loi_e & 0x00ffu));
		CCErr.SPIRdErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr19_rd_spi_crc_e & 0x00ffu));
		CCErr.SPIWrErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr19_wr_spi_crc_e & 0x00ffu));
		LOIErr.LOISupply1v1LowErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v1_loi_e & 0x00ffu));
		LOIErr.LOIInConnectionErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr17_bb_lo_in_loi_e & 0x00ffu));
		LOIErr.LOIOutConnectionErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr18_bb_lo_out_loi_e & 0x00ffu));
	}
	if(*rfe___error___pointer  == rfe_error_none_e)
	{

		fuSaFaultMask = rfeCfg_monitorAndSafety_getFuSaFaultMask(pRfeConfig, rfe_fuSaFaultMaskIndex_7_e, rfe___error___pointer);

		if(*rfe___error___pointer  == rfe_error_none_e)
		{
			MClkErr.MclkXoNoClkErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr11_xo_no_clock_mclk_e & 0x00ffu));
			MClkErr.MclkMSPCErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr36_mspc_mclk_e & 0x00ffu));
			MClkErr.MclkSupply1v8LowErr  = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr65_sr67_supply_low_1v8_mclk_e & 0x00ffu));
			MClkErr.MclkDigOutPutFreqErr= GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr39_dig_freq_mclk_e & 0x00ffu));
			MClkErr.MclkPllLockErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr35_pll_lock_mclk_e & 0x00ffu));
		}
	}
	if(*rfe___error___pointer  == rfe_error_none_e)
	{
		fuSaFaultMask = rfeCfg_monitorAndSafety_getFuSaFaultMask(pRfeConfig, rfe_fuSaFaultMaskIndex_11_e, rfe___error___pointer);
		if(*rfe___error___pointer  == rfe_error_none_e)
		{
			MClkErr.MclkPllLevelErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr37_pll_level_mclk_e & 0x00ffu));
		}
	}
	if(*rfe___error___pointer  == rfe_error_none_e)
	{

		fuSaFaultMask = rfeCfg_monitorAndSafety_getFuSaFaultMask(pRfeConfig, rfe_fuSaFaultMaskIndex_9_e, rfe___error___pointer);

		if(*rfe___error___pointer  == rfe_error_none_e)
		{
			CCErr.CCRegCRCErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr3_reg_crc_e & 0x00ffu));
			ISMRegCRCErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr3_reg_crc_e & 0x00ffu));
			OTPRegCRCErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr3_reg_crc_e & 0x00ffu));
			MClkErr.MclkRegCRCErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr3_reg_crc_e & 0x00ffu));
			LOIErr.LOIRegCRC_Err = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr3_reg_crc_e & 0x00ffu));

			errCode = BC_ISM_MaskRTMSetClrMCOIErr(e_ISM_ERR_OP_MASK_ERR, OTPRegCRCErr, ISMRegCRCErr, &MClkErr, &LOIErr, &CCErr);
			if(errCode != BC_ERR_NOERROR)
			{
				*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
			}
		}
	}
}

static void SetSSGAFuSaMask(uint8_t* pRfeConfig, rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE errCode;
	uint8_t fuSaFaultMask = 0U;
	BOOL ATBRegCRCErr = FALSE;
	SYS_SerialiserErrors_t SerErr = {FALSE, FALSE, FALSE, FALSE};
	SYS_SSBErrors_t SSBErr = {FALSE, FALSE};
	SYS_GBIASErrors_t GBErr = {FALSE, FALSE};
	SYS_GLDOErrors_t GLDOErr = {FALSE, FALSE, FALSE, FALSE, FALSE};

	fuSaFaultMask = rfeCfg_monitorAndSafety_getFuSaFaultMask(pRfeConfig, rfe_fuSaFaultMaskIndex_7_e, rfe___error___pointer);

	if(*rfe___error___pointer  == rfe_error_none_e)
	{
		GLDOErr.GlDOSupply1v1HighErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr57_supply_high_1v1_gldo_e & 0x00ffU));
		GLDOErr.GlDOSupply1v1LowErr= GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr59_supply_low_1v1_gldo_e & 0x00ffU));
		GLDOErr.GlDOSupply1v8HighErr  = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr61_supply_high_1v8_gldo_e & 0x00ffU));
	}
	if(*rfe___error___pointer  == rfe_error_none_e)
	{

		fuSaFaultMask = rfeCfg_monitorAndSafety_getFuSaFaultMask(pRfeConfig, rfe_fuSaFaultMaskIndex_8_e, rfe___error___pointer);

		if(*rfe___error___pointer  == rfe_error_none_e)
		{
			GLDOErr.GlDOSupply1v8LowErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr63_supply_low_1v8_gldo_e & 0x00ffu));
			SerErr.Supply1v8SerLowErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr65_67_supply_low_1v8_ser_e & 0x00ffu));
			SerErr.Supply1v1MIPILowErr  = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr65_67_supply_low_1v1_csi2_e & 0x00ffu));
			SerErr.Supply1v1LVDSLowErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr65_67_supply_low_1v1_ser_e & 0x00ffu));
			GBErr.GBIASSupply1v8LowErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr65_67_supply_low_1v8_gbias_e & 0x00ffu));
			SSBErr.SSBSupply1v8LowErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr65_67_supply_low_1v8_ssb_e & 0x00ffu));
		}
	}
	if(*rfe___error___pointer  == rfe_error_none_e)
	{

		fuSaFaultMask = rfeCfg_monitorAndSafety_getFuSaFaultMask(pRfeConfig, rfe_fuSaFaultMaskIndex_9_e, rfe___error___pointer);

		if(*rfe___error___pointer  == rfe_error_none_e)
		{
			
			ATBRegCRCErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr3_reg_crc_e & 0x00ffu));
			GLDOErr.GlDORegCRCErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr3_reg_crc_e & 0x00ffu));
			SSBErr.SSBRegCRCErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr3_reg_crc_e & 0x00ffu));
			GBErr.GBIASRegCRCErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr3_reg_crc_e & 0x00ffu));
			SerErr.SerRegCRCErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr3_reg_crc_e & 0x00ffu));

			errCode = BC_ISM_MaskRTMSetClrSSGAErr(e_ISM_ERR_OP_MASK_ERR, ATBRegCRCErr, &SerErr, &SSBErr, &GBErr, &GLDOErr);

			if(errCode != BC_ERR_NOERROR)
			{
				*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
			}
		}
	}
}

static void SetAdcFuSaMask(uint8_t* pRfeConfig, rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE errCode;
	uint8_t fuSaFaultMask = 0;
	SYS_ADCErrors_t ADC12Err = {FALSE, FALSE, FALSE, FALSE, FALSE, FALSE};
	SYS_ADCErrors_t ADC34Err = {FALSE, FALSE, FALSE, FALSE, FALSE, FALSE};

	fuSaFaultMask = rfeCfg_monitorAndSafety_getFuSaFaultMask(pRfeConfig, rfe_fuSaFaultMaskIndex_8_e,
			rfe___error___pointer);

	if(*rfe___error___pointer  == rfe_error_none_e)
	{
		ADC34Err.ADCSupply1v8LowErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr65_67_supply_low_1v8_adc34_e & 0x00ffu));
		ADC12Err.ADCSupply1v8LowErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr65_67_supply_low_1v8_adc12_e & 0x00ffu));
	}
	if(*rfe___error___pointer  == rfe_error_none_e)
	{

		fuSaFaultMask = rfeCfg_monitorAndSafety_getFuSaFaultMask(pRfeConfig, rfe_fuSaFaultMaskIndex_9_e,
				rfe___error___pointer);

		if(*rfe___error___pointer  == rfe_error_none_e)
		{
			ADC34Err.ADCn1CalErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr34_cal_adc4_e & 0x00ffu));
			ADC34Err.ADCn0CalErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr34_cal_adc3_e & 0x00ffu));
			ADC12Err.ADCn1CalErr  = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr34_cal_adc2_e & 0x00ffu));
			ADC12Err.ADCn0CalErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr34_cal_adc1_e & 0x00ffu));
			ADC34Err.ADCRegCrcErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr3_reg_crc_e & 0x00ffu));
			ADC12Err.ADCRegCrcErr = GetBitFromFuSaMask(fuSaFaultMask, (uint8_t)((uint16_t)rfe_fuSaFault_R2_sr3_reg_crc_e & 0x00ffu));

			errCode = BC_ISM_MaskRTMSetClrADCErr(e_ISM_ERR_OP_MASK_ERR, &ADC12Err, &ADC34Err);

			if(errCode != BC_ERR_NOERROR)
			{
				*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
			}
		}
	}
}

static void setSwFusaMask( uint8_t* pRfeConfig, rfe_error_t* rfe___error___pointer )
{
	uint8_t fuSaFaultMask = 0U, index;

	fuSaFaultMask = rfeCfg_monitorAndSafety_getFuSaFaultMask(pRfeConfig, rfe_fuSaFaultMaskIndex_9_e, rfe___error___pointer);
	if(*rfe___error___pointer  == rfe_error_none_e)
	{
		for(index = (uint8_t)rfe_sw_fuSaFault_sr31_bist_lna_gaindiff_index_e; index < (uint8_t)rfe_sw_fuSaFault_sr31_bist_mixer_phasediff_index_e; index++)
		{
			// Set  sr31-bist-lna-gaindiff-sw, sr31-bist-lna-phasediff-sw, sr31-bist-mixer-gaindiff-sw
			swFusaMask[index] = GetBitFromFuSaMask( fuSaFaultMask, (index + 5U));
		}
		fuSaFaultMask = rfeCfg_monitorAndSafety_getFuSaFaultMask(pRfeConfig, rfe_fuSaFaultMaskIndex_10_e, rfe___error___pointer);
	}
	if(*rfe___error___pointer  == rfe_error_none_e)
	{
		for(index = (uint8_t)rfe_sw_fuSaFault_sr31_bist_mixer_phasediff_index_e; index < (uint8_t)rfe_sw_fuSaFault_sr72_tx3_pr_cal_index_e; index++)
		{
			// Set sr72-tx2-pr-cal-sw, sr72-tx1-pr-cal-sw,  sr72-tx-pr-cal-sw, sr70-tx-integrity-sw, sr44-cafc-integrity-sw, sr44-cafc-intgerity-unlock-sw, sr44-cafc-intgerity-level-sw, sr31-bist-mixer-phasediff-sw
			swFusaMask[index] = GetBitFromFuSaMask( fuSaFaultMask, (index - 3U));
		}
		fuSaFaultMask = rfeCfg_monitorAndSafety_getFuSaFaultMask(pRfeConfig, rfe_fuSaFaultMaskIndex_11_e, rfe___error___pointer);
	}
	if(*rfe___error___pointer  == rfe_error_none_e)
	{
		for(index = (uint8_t)rfe_sw_fuSaFault_sr72_tx3_pr_cal_index_e; index < ((uint8_t)rfe_sw_generic_index_e + 1U); index++)
		{
			// Set rfe-generic-sw,  sr13-input-mode-toggle-test-sw, sr14-disable-lb-toggle-test-sw, sr72-tx3-pr-cal-sw
			swFusaMask[index] = GetBitFromFuSaMask( fuSaFaultMask, (index - 11U) );
		}
	}
}

BOOL getSwFusaMask( uint8_t swErrorIndex )
{
	return swFusaMask[swErrorIndex];
}

// Function get the FuSa Fault Mask from blob
static void FuSaFaultMaskConfig(uint8_t* pRfeConfig, rfe_error_t* rfe___error___pointer)
{

	SetTxFuSaMask(pRfeConfig, rfe___error___pointer);

	if(*rfe___error___pointer  == rfe_error_none_e)
	{
		SetRxFuSaMask(pRfeConfig, rfe___error___pointer);
	}
	if(*rfe___error___pointer  == rfe_error_none_e)
	{
		SetChirpFuSaMask(pRfeConfig, rfe___error___pointer);
	}
	if(*rfe___error___pointer  == rfe_error_none_e)
	{
		SetMCOIFuSaMask(pRfeConfig, rfe___error___pointer);
	}
	if(*rfe___error___pointer  == rfe_error_none_e)
	{
		SetSSGAFuSaMask(pRfeConfig, rfe___error___pointer);
	}
	if(*rfe___error___pointer  == rfe_error_none_e)
	{
		SetAdcFuSaMask(pRfeConfig, rfe___error___pointer);
	}
	if(*rfe___error___pointer  == rfe_error_none_e)
	{
		setSwFusaMask(pRfeConfig, rfe___error___pointer);
	}

}

void SetRxSaturationThresholdStage(uint8_t* rfeConfig, SYS_IPNum_e adcNum,
		rfe_error_t* rfe___error___pointer )
{
	BC_ERRCODE   errCode = BC_ERR_NOERROR;
	uint8_t rxSatThreshold = (uint8_t)rfe_rxSaturationThreshold_min13_05dB_e;
	uint16_t rxSatCountLimit = 0;
	uint8_t idx = 0;
	ADC_ConfigClippingDet_t adcClipping = {0};
	uint8_t rx[IP_ADC_NUMBER] = {(uint8_t) rfe_rxIndex_1_e, (uint8_t) rfe_rxIndex_2_e};

	if(adcNum == e_SYS_ADC34)
	{
		rx[0] = (uint8_t) rfe_rxIndex_3_e;
		rx[1] = (uint8_t) rfe_rxIndex_4_e;
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		for(idx = 0; idx < IP_ADC_NUMBER; ++idx)
		{
			rxSatThreshold = rfeCfg_monitorAndSafety_getRxSaturationThresholdStage(rfeConfig,
					(uint8_t)rfe_rxStage_1_e, rx[idx], rfe___error___pointer);
			if (*rfe___error___pointer != rfe_error_none_e)
			{
				break;
			}
			rxSatCountLimit = rfeCfg_monitorAndSafety_getRxSaturationCountLimitStage(rfeConfig,
					(uint8_t)rfe_rxStage_1_e, rx[idx], rfe___error___pointer);
			if (*rfe___error___pointer != rfe_error_none_e)
			{
				break;
			}
			if(idx == 0U)
			{
				adcClipping.ClipLevelADC0 = absolutRxSaturationThresholds[rxSatThreshold];
				adcClipping.ErrCntThresholdADC0 = rxSatCountLimit;
			}
			else
			{
				adcClipping.ClipLevelADC1 = absolutRxSaturationThresholds[rxSatThreshold];
				adcClipping.ErrCntThresholdADC1 = rxSatCountLimit;
			}
		}
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		errCode = BC_ADC_ConfigClippingDet(adcNum, &adcClipping);
		if (errCode != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}
	}
}

static void ConfigRxSaturationThresholdStage(rfeDriverPersistentMem_t *pDrvState, rfe_error_t* rfe___error___pointer )
{
	SetRxSaturationThresholdStage(pDrvState->rfeConfig, e_SYS_ADC12, rfe___error___pointer );
	SetRxSaturationThresholdStage(pDrvState->rfeConfig, e_SYS_ADC34, rfe___error___pointer );
}

static void setAdcHardClippingErrMask(BOOL adc1Mask, BOOL adc2Mask, BOOL adc3Mask, BOOL adc4Mask,
		rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE   errCode = BC_ERR_NOERROR;
	ISM_ErrCmd_e cmdReg = e_ISM_ERR_OP_MASK_ERR;
	SYS_ADCErrors_t adc12Err = {0};
	SYS_ADCErrors_t adc34Err = {0};

	if(adc1Mask == (BOOL)TRUE)
	{
		adc12Err.ADCn0HardClippingErr = (BOOL)ERROR_MASKED;
	}
	else
	{
		adc12Err.ADCn0HardClippingErr = (BOOL)ERROR_NOT_MASKED;
	}
	if(adc2Mask == (BOOL)TRUE)
	{
		adc12Err.ADCn1HardClippingErr = (BOOL)ERROR_MASKED;
	}
	else
	{
		adc12Err.ADCn1HardClippingErr = (BOOL)ERROR_NOT_MASKED;
	}
	if(adc3Mask == (BOOL)TRUE)
	{
		adc34Err.ADCn0HardClippingErr = (BOOL)ERROR_MASKED;
	}
	else
	{
		adc34Err.ADCn0HardClippingErr = (BOOL)ERROR_NOT_MASKED;
	}
	if(adc4Mask == (BOOL)TRUE)
	{
		adc34Err.ADCn1HardClippingErr = (BOOL)ERROR_MASKED;
	}
	else
	{
		adc34Err.ADCn1HardClippingErr = (BOOL)ERROR_NOT_MASKED;
	}

	errCode = BC_ISM_MaskRTMSetClrADCErr(cmdReg, &adc12Err, &adc34Err);
	if (errCode != BC_ERR_NOERROR)
	{
		*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
	}
}

/*==================================================================================================
 *                              PUBLIC FUNCTIONS
 ==================================================================================================*/

void GetProfChirpTiming(SYS_ProfChirpTiming_t* profChirpTiming, uint8_t	profileIdx, uint8_t *pRfeConfig,
		rfe_error_t* rfe___error___pointer)
{
	float32_t	tActive;
	float32_t	noIdleTChirp; // aux val used for compare

	if (*rfe___error___pointer == rfe_error_none_e)
	{
		profChirpTiming->TDwell = (float32_t)rfeCfg_chirpProfile_getDwellTimeTicks(pRfeConfig, (rfe_chirpProfileIndex_t)profileIdx, rfe___error___pointer) * TICK_TO_US;
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		profChirpTiming->TSettle = (float32_t)rfeCfg_chirpProfile_getSettleTimeTicks(pRfeConfig, (rfe_chirpProfileIndex_t)profileIdx, rfe___error___pointer) * TICK_TO_US;
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		profChirpTiming->TJumpback = (float32_t)rfeCfg_general_getJumpbackTimeTicks(pRfeConfig, rfe___error___pointer) * TICK_TO_US;
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		profChirpTiming->TReset = (float32_t)rfeCfg_chirpProfile_getResetTimeTicks(pRfeConfig, (rfe_chirpProfileIndex_t)profileIdx, rfe___error___pointer) * TICK_TO_US;
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		tActive = (float32_t)rfeCfg_chirpProfile_getAcquisitionTimeTicks(pRfeConfig, (rfe_chirpProfileIndex_t)profileIdx, rfe___error___pointer) * TICK_TO_US;
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		noIdleTChirp = profChirpTiming->TDwell + profChirpTiming->TSettle + tActive + profChirpTiming->TJumpback + profChirpTiming->TReset;
		profChirpTiming->TChirp = (float32_t)rfeCfg_chirpProfile_getChirpIntervalTimeTicks(pRfeConfig, (rfe_chirpProfileIndex_t)profileIdx, rfe___error___pointer) * TICK_TO_US;
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		if (profChirpTiming->TChirp < noIdleTChirp)
		{
			*rfe___error___pointer = rfe_error_api_configParamCrossCheck_chirpIntervalTimeTooShort_e;
		}
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		/* This profile chirp timing data is not coming from the BLOB, but determined in the function rfeSwCfgTef82xxConfig */
		profChirpTiming->TriggerTXSWAndBPSAtTSettle = RfeSwCfgTimingReqGetTriggerTXSWAndBPSAtTSettle(profileIdx, rfe___error___pointer) ? TRUE : FALSE;
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		/* This profile chirp timing data is not coming from the BLOB, but calculated in the function rfeSwCfgTef82xxConfig */
		profChirpTiming->TXSWAndBPSDelay = RfeSwCfgTimingReqGetTXSWAndBPSDelay_us(profileIdx, rfe___error___pointer);
	}
}

void GetProfChirpFreq(SYS_ProfChirpFreq_t* profChirpFreq, uint8_t	profileIdx, uint8_t *pRfeConfig, rfe_error_t* rfe___error___pointer)
{
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		profChirpFreq->DownChirp =
			((uint8_t)rfeCfg_chirpProfile_getChirpSlopeDirection(pRfeConfig, (rfe_chirpProfileIndex_t)profileIdx, rfe___error___pointer) == (uint8_t)RFE_RISING) ? FALSE: TRUE;
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		profChirpFreq->InputBW = (float32_t)rfeCfg_chirpProfile_getEffectiveChirpBandwidth(
				pRfeConfig, (rfe_chirpProfileIndex_t)profileIdx, rfe___error___pointer) * KHZ_TO_HZ;
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		profChirpFreq->InputBWType = e_SYS_BWACQ;
		profChirpFreq->InputFrequency = (BC_FLOAT)(
		        (float32_t)rfeCfg_chirpProfile_getCenterFrequency(pRfeConfig, (rfe_chirpProfileIndex_t)profileIdx, rfe___error___pointer) * KHZ_TO_HZ);
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		profChirpFreq->InputFreqType = e_SYS_CENTERFREQACQ;
		profChirpFreq->SBSearch = e_SYS_SBSEARCH_AAFC_SPI_TRIG;
		profChirpFreq->Subband = TEF82XX_SUBBAND;   // SBSearch input is Auto so it does not matter
		profChirpFreq->iVCOFine = TEF82XX_IVCOFINE;  // SBSearch input is Auto so it does not matter
		profChirpFreq->VCOSel = rfeVCOSelMapper((uint8_t)rfeCfg_chirpProfile_getChirpPllVco(pRfeConfig, (rfe_chirpProfileIndex_t)profileIdx, rfe___error___pointer));
		profChirpFreq->PLLLPFSel = rfeCafcPllLPFSelFromVCOMapper(profChirpFreq->VCOSel);
	}
}

void GetProfChirpSample(SYS_ProfChirpSampleDeci_t* profChirpSample, uint8_t	profileIdx, uint8_t *pRfeConfig,
		rfe_error_t* rfe___error___pointer)
{
	uint8_t						decimation = 0;
	uint32_t tAcqTimeTicks = 0;
	uint16_t nrSamplesPerChirp = 0;
	rfeSamplingFrequencies_t samplingFrequency =
				(rfeSamplingFrequencies_t)rfeCfg_chirpProfile_getEffectiveSamplingFrequency(pRfeConfig, (rfe_chirpProfileIndex_t)profileIdx, rfe___error___pointer);
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		switch (samplingFrequency)
		{
			case RFE_ADC_5MSPS:
				decimation = TEF82XX_DECIMATION_ADC_5MSPS;
				break;
			case RFE_ADC_10MSPS:
				decimation = TEF82XX_DECIMATION_ADC_10MSPS;
				break;
			case RFE_ADC_20MSPS:
				decimation = TEF82XX_DECIMATION_ADC_20MSPS;
				break;
			case RFE_ADC_40MSPS:		
				decimation = TEF82XX_DECIMATION_ADC_40MSPS;
				break;
			default:
				decimation = TEF82XX_DECIMATION_ADC_40MSPS;
				break;
		}
		profChirpSample->ADCMode = e_SYS_ADC80MSPS_FUNCTIONAL;
		profChirpSample->Decimation = decimation;
		profChirpSample->PDCBWWide = (BOOL)rfeCfg_general_getPdcBitwidth(pRfeConfig, rfe___error___pointer);
		tAcqTimeTicks =	rfeCfg_chirpProfile_getAcquisitionTimeTicks(pRfeConfig, (rfe_chirpProfileIndex_t)profileIdx, rfe___error___pointer);

	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		switch (samplingFrequency)
		{
			case RFE_ADC_40MSPS:
				nrSamplesPerChirp = (uint16_t)((float32_t)tAcqTimeTicks * (TICK_TO_US * 40.0f));
				break;
			case RFE_ADC_20MSPS:
				nrSamplesPerChirp = (uint16_t)((float32_t)tAcqTimeTicks * (TICK_TO_US * 20.0f));
				break;
			case RFE_ADC_10MSPS:
				nrSamplesPerChirp = (uint16_t)((float32_t)tAcqTimeTicks * (TICK_TO_US * 10.0f));
				break;
			case RFE_ADC_5MSPS:
				nrSamplesPerChirp = (uint16_t)((float32_t)tAcqTimeTicks * (TICK_TO_US * 5.0f));
				break;
			default:
				nrSamplesPerChirp = (uint16_t)((float32_t)tAcqTimeTicks * (TICK_TO_US * 40.0f));
				break;
		}
		profChirpSample->RawNumSamples = nrSamplesPerChirp * decimation;
		profChirpSample->VirtualChNo = rfeVirtualChannelMapper(
		        (uint8_t)rfeCfg_chirpProfile_getVirtualChannel(pRfeConfig, (rfe_chirpProfileIndex_t)profileIdx, rfe___error___pointer));
	}
}

float32_t GetPllLoopFilterBw(uint8_t chirpProfileIndex, uint8_t* pRfeConfig,
		rfe_error_t* rfe___error___pointer)
{
	float32_t pllLoopFilterBw = 0.0f;
	rfe_chirpPllLoopFilterBandwidth_t val = rfeCfg_chirpProfile_getChirpPllLoopFilterBandwidth(pRfeConfig, rfeChirpProfileMapper(chirpProfileIndex), rfe___error___pointer);

	pllLoopFilterBw = (((float32_t)val) * RFE_TEF82XX_PLL_LOOP_FILTER_BANDWIDTH_STEP) + RFE_TEF82XX_PLL_LOOP_FILTER_BANDWIDTH_MIN;
	if( (pllLoopFilterBw < RFE_TEF82XX_PLL_LOOP_FILTER_BANDWIDTH_MIN) || (pllLoopFilterBw > RFE_TEF82XX_PLL_LOOP_FILTER_BANDWIDTH_MAX) )
	{
		/* Set to a default value. */
		pllLoopFilterBw = TEF82XX_DEFAULT_PLL_LOOP_FILTER_BANDWIDTH;
	}
	return pllLoopFilterBw;
}

void rfeSwCfg_PhaseRotatorPhaseControl(const uint8_t * pRfeConfig, 
									  rfe_chirpSequenceIndex_t chirpSequenceConfigIndex,
		 							  rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE				errCode = BC_ERR_NOERROR;
	uint8_t   				useDDMA[RFE_MAX_TX_CHANNELS] = {0U};
	uint8_t					phaseRotatorFromProfileEnable = 0U;
	bool 					useQPSK = false;
	TE_DDMAMod_e        	ddmaMode = e_TE_DDMA_DISABLED;	
	uint8_t   				phaseShiftControlSource[RFE_MAX_TX_CHANNELS] = {0U};
	float32_t 				ddmaInitPhase[RFE_MAX_TX_CHANNELS] = {0.0f};
	float32_t 				ddmaPhaseUpdate[RFE_MAX_TX_CHANNELS] = {0.0f};
	uint8_t   				bpskSource[RFE_MAX_TX_CHANNELS] = {0U};
	TE_PRPCGenMode_e    	finalPCGenMode[RFE_MAX_TX_CHANNELS];
	uint8_t 				idx;

	if (*rfe___error___pointer == rfe_error_none_e)
	{
		phaseRotatorFromProfileEnable = GetPhaseRotatorEnable(pRfeConfig, rfe___error___pointer);
		ddmaMode = rfeDdmaModeFromUint8Mapper(rfeCfg_sequence_getPhaseRotationDdmaMode(pRfeConfig, chirpSequenceConfigIndex, rfe___error___pointer));
		useQPSK = rfeCfg_chirpSequence_getDynamicUpdatesEnabled(pRfeConfig, chirpSequenceConfigIndex, rfe___error___pointer);
		for(idx = 0U; idx < (uint8_t)RFE_MAX_TX_CHANNELS; ++idx)
		{
			// Source of the initial phase code. 0/FALSE: TE; 1/ TRUE: DDMA
			useDDMA[idx] = (rfeCfg_sequence_getPhaseRotationTxUseDdma(pRfeConfig, chirpSequenceConfigIndex, rfe___error___pointer) >> idx) & 0x01U;
			// Initial phase value in degrees for DDMA mode
			ddmaInitPhase[idx] = (float32_t)rfeCfg_sequence_getTxDdmaInitPhase(pRfeConfig, chirpSequenceConfigIndex, rfeTxIndexMapper(idx), rfe___error___pointer) *
			                            BLOB_PHASE_TO_PHASE_DEGREE;
			// Phase update size in degrees for DDMA mode
			ddmaPhaseUpdate[idx] = (float32_t)rfeCfg_sequence_getTxDdmaUpdatePhase(pRfeConfig, chirpSequenceConfigIndex, rfeTxIndexMapper(idx), rfe___error___pointer) *
			                            BLOB_PHASE_TO_PHASE_DEGREE;
			if (useQPSK)
			{
				bpskSource[idx] = TEF82XX_DEFAULT_PR_QPSK_SOURCE;
				phaseShiftControlSource[idx] = TEF82XX_DEFAULT_PR_QPSK_SOURCE;
			}
			else
			{
				bpskSource[idx] = TEF82XX_DEFAULT_PR_BPSK_SOURCE;
				phaseShiftControlSource[idx] = TEF82XX_DEFAULT_PR_BPSK_SOURCE;
			}
			finalPCGenMode[idx] = (TE_PRPCGenMode_e)rfeCfg_sequence_getFinalPcGenMode(pRfeConfig, chirpSequenceConfigIndex,
					rfeTxIndexMapper(idx), rfe___error___pointer);
		}

		if (*rfe___error___pointer == rfe_error_none_e)
		{
			if ((phaseRotatorFromProfileEnable != 0U) || (ddmaMode != e_TE_DDMA_DISABLED) || (useQPSK != false))
			{
				errCode = BC_TE_TXPRSafetyCheckDelay((bool)TEF82XX_DEFAULT_EN_PR_SAFETY_CHECK,
									(float32_t)TEF82XX_DEFAULT_PR_SAFETY_START_DELAY * NS_TO_US);
			}
			if (errCode == BC_ERR_NOERROR)
			{
				errCode = BC_SYS_ConfigTXPR(useDDMA, ddmaMode, ddmaInitPhase, ddmaPhaseUpdate, finalPCGenMode, bpskSource);
			}
			if (errCode == BC_ERR_NOERROR)
			{
				errCode = BC_TE_SetPhaseCtrls(phaseShiftControlSource, (BOOL)TEF82XX_DEFAULT_PR_BPSK_SAMPLING,
						(BOOL)TEF82XX_DEFAULT_PR_QPSK_SAMPLING, finalPCGenMode);
			}
			if(errCode != BC_ERR_NOERROR)
			{
				*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
			}
		}
	}
}

void TE_ConfigStatic(uint8_t chirpSeqIndex, uint8_t *pRfeConfig, rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE errCode = BC_ERR_NOERROR;
	TE_StaticConfig_t staticConfigLoc = { 0.0f };

	/* Get the calculated power ON timings and start reference points */
	staticConfigLoc = RfeSwCfgTimingReqGetStaticConfig(rfe___error___pointer);

	if(*rfe___error___pointer == rfe_error_none_e)
	{
	    staticConfigLoc.NumChirpInSeq = rfeCfg_chirpSequence_getChirpCount(pRfeConfig, (rfe_chirpSequenceIndex_t)chirpSeqIndex, rfe___error___pointer);
	}
	if(*rfe___error___pointer == rfe_error_none_e)
	{
		errCode = BC_TE_ConfigStatic(&staticConfigLoc);
		if (errCode != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}
	}
}

void TE_ConfigProfileSequencing(uint8_t chirpSequence, rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE   errCode = BC_ERR_NOERROR;
	rfeDriverPersistentMem_t *pDrvState = NULL;
	uint8_t profileRepeatCount = 0;
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		pDrvState = RfeDrvStateGet();
		profileRepeatCount = rfeCfg_chirpSequence_getChirpProfileRepeatCount(pDrvState->rfeConfig, (rfe_chirpSequenceIndex_t)chirpSequence, rfe___error___pointer);
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
	// choose profile sequencing mode
	// 0x478A is reset value of PR seed (just setting, not used in this example)
		errCode = BC_TE_ConfigProfileSequencing(
				rfeProfModeSelMapper(pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[chirpSequence].profModeSel),
				pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[chirpSequence].profList,
				profileRepeatCount,	(BOOL)TEF82XX_DEFAULT_PROF_RESET, TRUE,	0x468Au);
		if(errCode != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}
	}
}

void rfeSwCfgTef82xxConfig(uint8_t* rfeConfig, rfe_error_t* rfe___error___pointer)
{
	rfeDriverPersistentMem_t *pDrvState 		= NULL;
	uint8_t					 chirpSequence 		= 0;
	uint8_t					 txIndex 			= 0;
	uint8_t 				 chirpProfileIndex 	= 0;
	rfe_monitorValues_t*  	 monitorValues  	= NULL;
	
	// Get the first sequence in radar cycle
	chirpSequence = (uint8_t)rfeCfg_radarCycle_getChirpSequence(rfeConfig, 0U, rfe___error___pointer);
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		pDrvState = RfeDrvStateGet();
		SetPersistentRadarConfig(pDrvState, rfeConfig, rfe___error___pointer);
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		/* From the rfeConfig, scan all enabled profiles, check timing rquirements, calculate/determine 
		   the TE filter, RX HPF timing and TX fast switch and BPS control timing. All calculated and 
		   determined configuration items can be retrieved with the corresponding function call 
		   rfeSwCfgTimingGetxxx */
		RfeSwCfgTimingReqCalculateTiming(pDrvState, rfe___error___pointer);
	}
	// Configure Tef82xx radar parameters
	if(*rfe___error___pointer == rfe_error_none_e)
	{
		StaticConfig(pDrvState, rfeConfig, chirpSequence, rfe___error___pointer);
	}
	// Profile 8 config for RF BIST
	rfeSwBist_initialConfiguration(pDrvState, rfeConfig, (rfe_chirpSequenceIndex_t)chirpSequence, rfe___error___pointer);
	// Read RX bist config from file
	rfeSwBist_readBistConfig(pDrvState, rfe___error___pointer);
	if(*rfe___error___pointer == rfe_error_none_e)
	{
		ProfileConfig(pDrvState, rfeConfig, chirpSequence, rfe___error___pointer);
	}
	// FuSa configuration
	if(*rfe___error___pointer == rfe_error_none_e)
	{
		FuSaFaultMaskConfig(rfeConfig, rfe___error___pointer);
	}
	// Config rx saturation threshold
	if(*rfe___error___pointer == rfe_error_none_e)
	{
		ConfigRxSaturationThresholdStage(pDrvState, rfe___error___pointer);
	}
	// Not mask adc hard clipping error
	if(*rfe___error___pointer == rfe_error_none_e)
	{
		setAdcHardClippingErrMask((BOOL)ERROR_NOT_MASKED, (BOOL)ERROR_NOT_MASKED, (BOOL)ERROR_NOT_MASKED, (BOOL)ERROR_NOT_MASKED,
			rfe___error___pointer);
	}
	// Set tx profile threshold amplitude
	if(*rfe___error___pointer == rfe_error_none_e)
	{
		monitorValues = rfeMon_getRfeMonitorValues();
		for ( chirpProfileIndex = 0; chirpProfileIndex < RFE_CHIRP_PROFILES_MAX; chirpProfileIndex++ )
		{
			 for ( txIndex = 0; txIndex < (RFE_TX_COUNT * RFE_MAX_SUPPORTED_DEVICES); txIndex++ )
			 {
				 monitorValues->txPower[chirpProfileIndex][txIndex] = -128;
			 }
		}
	}
}

BC_ERRCODE rfeSwCfgSetDynPowMode(powerMode_t mode)
{
	BC_ERRCODE   errCode = BC_ERR_NOERROR;
	uint32_t	reqDelayUs = dpmReqDelay[mode];

	errCode = BC_CC_SetDynPowModeDown(&Tef82xxDpmRecommendedPowerModes[mode],
									  TEF82XX_DEFAULT_DYN_PDOWN_DLY_PER_CHIRP,
									  TEF82XX_DEFAULT_DYN_PDOWN_DLY_PER_SEQ);
	if (errCode == BC_ERR_NOERROR)
	{
		if (reqDelayUs > 0u)
		{
			RfeHwDelayUs(reqDelayUs);
		}
	}

	return errCode;
}

BC_ERRCODE rfeSwCfgSetFastSwitch(void)
{
	BC_ERRCODE   errCode = BC_ERR_NOERROR;
	R2M00_IpFunctionalResetControlUnion_t IpFunctionalResetRelease;
	rfeDriverPersistentMem_t *pDrvState;
	IpFunctionalResetRelease.val_u32 = 0xFFFFFFFFU;

	pDrvState = RfeDrvStateGet();

	if (pDrvState->tef82xxDrvState.chirpPowerSavingEnabled == (uint8_t)TRUE)
	{
		errCode = BC_CAFC_FastBiasChirpPll();
		if (errCode == BC_ERR_NOERROR)
		{
			errCode = BC_SPI_Read(e_SYS_CC, R2M00_IP_FUNCTIONAL_RESET_CONTROL_U16, &IpFunctionalResetRelease.val_u32);
		}

		if (errCode == BC_ERR_NOERROR)
		{
			IpFunctionalResetRelease.bits_st.FnResetChirp = 0U;
			errCode = BC_SPI_WriteCheck(e_SYS_CC, R2M00_IP_FUNCTIONAL_RESET_CONTROL_U16, IpFunctionalResetRelease.val_u32);
		}

		if (errCode  == BC_ERR_NOERROR )
		{
			IpFunctionalResetRelease.bits_st.FnResetChirp = 1U;
			errCode = BC_SPI_WriteCheck(e_SYS_CC, R2M00_IP_FUNCTIONAL_RESET_CONTROL_U16, IpFunctionalResetRelease.val_u32);
		}
		RfeHwDelayUs(TEF82XX_FNRESETCHIRP_DELAY);
	}
	return errCode;
}

BC_ERRCODE CpmWaRxEnable(BOOL flag)
{
	BC_ERRCODE   errCode = BC_ERR_NOERROR;

	rfeDriverPersistentMem_t *pDrvState;

	pDrvState = RfeDrvStateGet();

	if (pDrvState->tef82xxDrvState.chirpPowerSavingEnabled == (uint8_t)TRUE)
	{
		// CPM Workaround to manually enable/disable the RX and improve chirp linearity
		errCode = BC_RX_ConfigLocalCtrl(e_SYS_RXMC,  flag, flag);
	}

	return errCode;
}

BC_ERRCODE CpmWaDpmEnable(BOOL flag)
{
	BC_ERRCODE   errCode = BC_ERR_NOERROR;

	rfeDriverPersistentMem_t *pDrvState;

	// Enabling the workaround, should disable the power saving
	powerMode_t PowerMode = (flag == TRUE) ? e_NO_DPM_ACTIVE : e_DPM_ACTIVE;

	pDrvState = RfeDrvStateGet();

	if (pDrvState->tef82xxDrvState.chirpPowerSavingEnabled == (uint8_t)TRUE)
	{
		// CPM Workaround to manually enable/disable power saving and improve chirp linearity
        errCode = rfeSwCfgSetDynPowMode(PowerMode);
	}

	return errCode;
}

BC_ERRCODE TxPhaseWa1SsbEnable(BOOL flag)
{
	BC_ERRCODE   errCode = BC_ERR_NOERROR;

	rfeDriverPersistentMem_t *pDrvState;

	pDrvState = RfeDrvStateGet();

	if (pDrvState->tef82xxDrvState.txPhaseErrorWa1Enabled == (uint8_t)TRUE)
	{
		// CPM Workaround to manually enable/disable power saving and improve chirp linearity
	    errCode = BC_SSB_ChangePowerState(flag);
	}

	return errCode;
}

BOOL* GetSwFusaMaskAddress(void)
{
	return &swFusaMask[0];
}

void SetSequenceProfChirpParam(uint8_t *pRfeConfig,
		uint8_t sequenceIndex, rfe_error_t* rfe___error___pointer)
{
	rfeDriverPersistentMem_t *pDrvState = RfeDrvStateGet();
	uint8_t *profilesIndexInSequence = &pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[sequenceIndex].profList[0];
	uint32_t centerFrequency[RFE_MAX_CHIRP_PROFILES] = {0};
	uint32_t meanCenterFreq = 0;
	int32_t freqDiff = 0;
	int32_t minCenterFreqDelta = (int32_t)(RFE_TEF82XX_MAX_CENTER_FREQUENCY) - (int32_t)(RFE_TEF82XX_MIN_CENTER_FREQUENCY);
	uint8_t	noChirpProfiles = pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[sequenceIndex].nrSequenceChirpProfiles;
	uint8_t profileIdx = 0;
	SYS_ProfChirpTiming_t		profChirpTiming;
	SYS_ProfChirpFreq_t			profChirpFreq;

	//Get meanCenterFreqProf
	for (profileIdx = 0; profileIdx < noChirpProfiles; profileIdx++)
	{
		centerFrequency[profileIdx] = rfeCfg_chirpProfile_getCenterFrequency(pRfeConfig, rfeChirpProfileMapper(profilesIndexInSequence[profileIdx]), rfe___error___pointer);
		if (*rfe___error___pointer != rfe_error_none_e)
		{
			break;
		}
		meanCenterFreq += centerFrequency[profileIdx];
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		meanCenterFreq = meanCenterFreq / noChirpProfiles;

		for (profileIdx = 0; profileIdx < noChirpProfiles; profileIdx++)
		{
			freqDiff = (int32_t)centerFrequency[profileIdx] - (int32_t)meanCenterFreq;
			if (labs(freqDiff) < minCenterFreqDelta)
			{
				minCenterFreqDelta = (int32_t)labs(freqDiff);
				pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[sequenceIndex].meanCenterFreqProf =
						profilesIndexInSequence[profileIdx];
			}
		}

		profileIdx = pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[sequenceIndex].meanCenterFreqProf;
		GetProfChirpFreq(&profChirpFreq, profileIdx, pRfeConfig, rfe___error___pointer);
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		GetProfChirpTiming(&profChirpTiming, profileIdx, pRfeConfig, rfe___error___pointer);
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[sequenceIndex].meanCenterFreqProfTiming = profChirpTiming;
		pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[sequenceIndex].meanCenterFreqProfFreq = profChirpFreq;
	}
}
