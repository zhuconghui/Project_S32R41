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

/**************************************************************************************************
 *   Project              : S32R41_RFE_FW
 *   Platform             : S32R41
 **************************************************************************************************/


/**************************************************************************************************
 *                              INCLUDES
 **************************************************************************************************/
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

#include "rfe_sw_cfg_tef82xx.h"
#include "rfe_sw_cfg_tef82xx_timing_req.h"
#include "rfe_blob_access.h"
#include "rfe_cfg_blob.h"
#include "rfeHwLink.h"
#if defined(RFE_DEBUG)
#include "math.h"
#endif

/*==================================================================================================
 *                                      LOCAL CONSTANTS
==================================================================================================*/

/**
* @brief    Recommended delta delays for staggering power ON of individual RX and TX channels.
* @details  Delta delays are used to calculate individual GDelayFineControl1, 2, 3, etc for the TE.
*           Delta delays power ON steps of the following sequence: RX1, TX1, RX2, TX2, RX3, TX3, RX4.
*
*           Purpose of staggered power ON is to reduce the in-rush current. See also RM00227 TEF82xx
*           reference manual and AN13777 TEF82xx Timing Requirement.
*
*           Two recommendations, CPM enabled and CPM disabled.
*/
const static float32_t rfeRecommendedDeltaPowerOnStaggeringCpmEnabled_us   = 0.05f;
const static float32_t rfeRecommendedDeltaPowerOnStaggeringCpmDisabled_us  = 0.5f;

/**
* @details  TX Pout calibration happens at the end of the TX calibration sequence, where the TX is
*           warmed up. Due to power saving mechanisms, the temperature of the TX is lower for the
*           first few chirps. This may result in a higher output power than expected, which can
*           lead to TX High ISM warnings or TX Max ISM errors. To prevent these errors from occurring,
*           the TX is powered ON rfeRecommendedGroupDelayCpmDisabled_us after the chirp start signal.
*           The 'warm up' time is: DC Power On Delay - rfeRecommendedGroupDelayCpmDisabled_us.
*           This is only applicable when Power Mode = Active (No CPM) */
const static float32_t rfeRecommendedGroupDelayCpmDisabled_us       = 10.0f;

/* Limits hard defined by TEF82xx registers. See also RM00228 TEF82xx Register Map */
const static float32_t minimumDcPowerOnDelay_us     = 15.0f;
const static float32_t minimumTDwell_us             = 1.0f;
const static float32_t minimumTSettle_us            = 2.0f;
const static float32_t minimumTJumpback_us          = 0.025f;
const static float32_t minimumTReset_us             = 0.75f;
const static float32_t minimumTReturn_us            = 4.0f;
const static float32_t mimumumSafetyMontrDelay_us   = 0.1f;

const static float32_t minimumDelay_us              = 0.025f;
const static float32_t minimumTxGroupDelay_us       = 0.025f;
const static float32_t minimumTxSwAndBpsDelay_us    = 0.05f;
const static float32_t minimumRxGroupDelay_us       = 0.025f;
const static float32_t maximumDelay_us              = 6.35f;

/* These RX HPF settle timings are tuned on the corresponding corner frequency. More details can be found
   in the RM00227 TEF82xx Reference manual and AN13777 TEF82xx Timing Requirement */
const static float32_t rxHpf100kHzSettleTime_us     = 7.975f;
const static float32_t rxHpf200kHzSettleTime_us     = 4.000f;
const static float32_t rxHpf300kHzSettleTime_us     = 3.675f;
const static float32_t rxHpf400kHzSettleTime_us     = 2.000f;
const static float32_t rxHpf800kHzSettleTime_us     = 1.000f;
const static float32_t rxHpf1600kHzSettleTime_us    = 0.500f;
const static float32_t rxHpf3200kHzSettleTime_us    = 0.275f;

/* Minimum timing constrains, required by TEF82xx. .
   Constant number below map on the AN13777 Detail Timing Constraints slides */
const static float32_t constrain_1_us               = 1.5f;
const static float32_t constrain_2_us               = 0.5f;
const static float32_t constrain_3_us               = 2.0f;
const static float32_t constrain_4_us               = 0.15f;

// Longest dwell + settle time in all profiles
// used for dynamic tables update I Q pins 
static float32_t dwellPhaseLongestFound_us          = 0.0f;

#ifdef RFE_DEBUG
/* TEMPORARY solution.
   Because RfeDbgPrintMsg does not support proper formatting, 'snprintf' is temporary replace
   RfeDbgPrintMsg. Allocate buffer to check output while debugging */
static char temporary_buf[200];
#endif

/*=================================================================================================
 *                                      TYPES
 =================================================================================================*/

/**
* @brief        Local calculated/determined chirp timing data.
*/
typedef struct
{
	bool 	   triggerTXSWAndBPSAtTSettle;
	float32_t  txSWAndBPSDelay_us;
} chirpTimingDataLocal_t;


/*=================================================================================================
 *                                      DEFINES AND MACROS
 =================================================================================================*/

/* Temporary solution to get float formatting in debug prints */
#define FORMAT_FLOAT_3P3  "%d.%03d"
#define SPLIT_FLOAT_3P3(FLOAT)  (int16_t)(float32_t)(FLOAT), ((int16_t)((float32_t)((FLOAT)*1000.0f))%1000)


/*=================================================================================================
 *                                   LOCAL VARIABLES
=================================================================================================*/

/**
* @brief Local calculated TE data. Structure is specifically used with API BC_TE_ConfigStatic.
*/
static TE_StaticConfig_t 		staticConfig;       // TODO : see if the removed initialization (MISRA doesn't allow single param init "= {0}" ) affects the usage

/**
* @brief Local calculated/determined RX HPF filter data and includes all values 
         that are required by API BC_TE_SetRxFilterCtrls.
*/
static rfeRxFilterCtrlParams_t 	rxFilterCtrlParams = {0};

/**
* @brief Local calculated/determined data of the profile chirp timing data. These 
         elements are required by API BC_SYS_ProgramChirp.
*/
static chirpTimingDataLocal_t   profileChirpTimingDataLocal[RFE_CHIRP_PROFILES_MAX] = {
        { .triggerTXSWAndBPSAtTSettle = false, .txSWAndBPSDelay_us = 0.0f }
};


/*=================================================================================================
 *                                   LOCAL FUNCTION PROTOTYPES
=================================================================================================*/

/*
 * @brief  Static timing initialization. Checking is according RM00227 TEF82xx Reference manual
 *         and AN13777 TEF82xx Timing Requirement.
 * @param [in]      pRfeConfig - Pointer to the radar configuration data (blob).
 * @param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 * \return  NIL
 */
static void rfeStaticConfigInitialize(uint8_t *pRfeConfig,
		                              rfe_error_t *rfe___error___pointer);

/*
 * @brief  Determine which of the enabled profiles have the lowest RX HPF corner frequency and
           hereby the longest settle time. Return the settle time. Exclude the RFBIST profile 
           from the scan.
 * @param [in]      pRfeConfig - Pointer to the radar configuration data (blob).
 * @param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 * \return Settle time of RX HPF filter in us.
 */
static float32_t DetermineLongestRxHpfSettleTime_us(uint8_t *pRfeConfig,
                                                        rfe_error_t *rfe___error___pointer);

/*=================================================================================================
 *                                       LOCAL FUNCTIONS
=================================================================================================*/
static void rfeStaticConfigInitialize(uint8_t *pRfeConfig,
								      rfe_error_t *rfe___error___pointer)
{
	float32_t tDwell_us = 0.0f;
	float32_t tSettle_us = 0.0f;
	float32_t tJumpback_us = 0.0f;
	float32_t tReset_us = 0.0f;
	float32_t tReturn_us = 0.0f;
	uint8_t   profileIdx = 0u;
    uint8_t	noChirpProfiles = 0u;

    if (*rfe___error___pointer == rfe_error_none_e)
    {
    	noChirpProfiles = rfeCfg_metadata_getChirpProfileCount(pRfeConfig, rfe___error___pointer);
    }
    /* Initialize static configuration structure */
    if (*rfe___error___pointer == rfe_error_none_e)
	{
		staticConfig.NumSeqInBurst = TEF82XX_DEFAULT_NUM_SEQ_IN_BURST;
		staticConfig.SeqInterval   = (float32_t) TEF82XX_DEFAULT_SEQ_INTERVAL * TICK_TO_US;
#if (TEF82XX_DEFAULT_EN_PR_SAFETY_CHECK == 1U)
		staticConfig.SeqInterval = staticConfig.SeqInterval + ((float32_t) TEF82XX_DEFAULT_PR_SAFETY_START_DELAY * NS_TO_US);
#endif
		staticConfig.DCPowerOnDelay     = (float32_t) TEF82XX_DEFAULT_P_ON_DELAY * NS_TO_US;
		staticConfig.SafetyMontrActCtrl = (BOOL)TEF82XX_DEFAULT_SAFETY_MON_ACT_CTRL;
		staticConfig.SafetyMontrDelay   = (float32_t) TEF82XX_DEFAULT_ISM_DELAY * NS_TO_US;
		staticConfig.JumpBackTime       = (float32_t)rfeCfg_general_getJumpbackTimeTicks(pRfeConfig, rfe___error___pointer) * TICK_TO_US;
	}
    if ((*rfe___error___pointer == rfe_error_none_e) && (staticConfig.DCPowerOnDelay < minimumDcPowerOnDelay_us))
    {
		*rfe___error___pointer = rfe_error_bc_teDcPowOnDelay;
#ifdef RFE_DEBUG
			RfeDbgPrintMsg("rfe_error_bc_teDcPowOnDelay");
#endif
	}
    /* Check if minimum condition is met when safety monitor control is enabled */
    if ((*rfe___error___pointer == rfe_error_none_e) && (staticConfig.SafetyMontrActCtrl == TRUE) && (staticConfig.SafetyMontrDelay < mimumumSafetyMontrDelay_us))
    {
		*rfe___error___pointer = rfe_error_bc_teDcSafetyDelay;
#ifdef RFE_DEBUG
			RfeDbgPrintMsg("rfe_error_bc_teDcSafetyDelay");
#endif
    }
    /* Iterate through all enabled profiles to find the shortest hpfResetReleaseDelay_us.
       For all calculations T1 (start at TDwell) is the default reference point */
	for (profileIdx = 0; profileIdx < noChirpProfiles; profileIdx++)
	{
		tDwell_us = (float32_t)rfeCfg_chirpProfile_getDwellTimeTicks(pRfeConfig, (rfe_chirpProfileIndex_t)profileIdx, rfe___error___pointer) * TICK_TO_US;
		tSettle_us = (float32_t)rfeCfg_chirpProfile_getSettleTimeTicks(pRfeConfig, (rfe_chirpProfileIndex_t)profileIdx, rfe___error___pointer) * TICK_TO_US;
		tJumpback_us = (float32_t)rfeCfg_general_getJumpbackTimeTicks(pRfeConfig, rfe___error___pointer) * TICK_TO_US;
		tReset_us = (float32_t)rfeCfg_chirpProfile_getResetTimeTicks(pRfeConfig, (rfe_chirpProfileIndex_t)profileIdx, rfe___error___pointer) * TICK_TO_US;
		if (*rfe___error___pointer != rfe_error_none_e)
        {
            break;
        }
        if (tDwell_us < minimumTDwell_us)
        {
        	*rfe___error___pointer = rfe_error_api_configParamCrossCheck_dwellSettleTimeTooShort_e;
#ifdef RFE_DEBUG
			RfeDbgPrintMsg("rfe_error_api_configParamCrossCheck_dwellSettleTimeTooShort_e");
#endif
        	break;
        }
        if (tSettle_us < minimumTSettle_us)
        {
        	*rfe___error___pointer = rfe_error_api_configParamCrossCheck_dwellSettleTimeTooShort_e;
#ifdef RFE_DEBUG
			RfeDbgPrintMsg("rfe_error_api_configParamCrossCheck_dwellSettleTimeTooShort_e");
#endif
        	break;
	    }
        if (tJumpback_us < minimumTJumpback_us)
        {
        	*rfe___error___pointer = rfe_error_api_configParamCrossCheck_acqJumpbackResetTimeTooShort_e;
#ifdef RFE_DEBUG
			RfeDbgPrintMsg("rfe_error_api_configParamCrossCheck_acqJumpbackResetTimeTooShort_e");
#endif
        	break;
        }
        if (tReset_us < minimumTReset_us)
        {
        	*rfe___error___pointer = rfe_error_api_configParamCrossCheck_acqJumpbackResetTimeTooShort_e;
#ifdef RFE_DEBUG
			RfeDbgPrintMsg("rfe_error_api_configParamCrossCheck_acqJumpbackResetTimeTooShort_e");
#endif
        	break;
        }

        /* Check to guarantees optimal PLL performance */
        tReturn_us = tDwell_us + tSettle_us + tReset_us;
        if (tReturn_us < minimumTReturn_us)
        {
        	*rfe___error___pointer = rfe_error_bc_inputOutOfRange;
#ifdef RFE_DEBUG
			RfeDbgPrintMsg("rfe_error_bc_inputOutOfRange");
#endif
        	break;
        }
    }
}

static float32_t DetermineLongestRxHpfSettleTime_us(uint8_t *pRfeConfig, rfe_error_t *rfe___error___pointer)
{
	uint8_t profileIdx = 0u;
	float32_t filterSettleTime_us = 0.0f;
	float32_t longestFilterSettleTime_us = 0.0f;
    SYS_RXHPF_CornerFreq_e rxHpfCornerFeqEnum = e_SYS_RXHPF_100KHZ;
	uint8_t	noChirpProfiles = 0u;
	rfeRxHpfCutOff_t hpfCutOff = RFE_RX_HPF_CUTOFF_100KHZ;

    if (*rfe___error___pointer == rfe_error_none_e)
    {
    	noChirpProfiles = rfeCfg_metadata_getChirpProfileCount(pRfeConfig, rfe___error___pointer);
    }

	for (profileIdx = 0; profileIdx < noChirpProfiles; profileIdx++)
	{
		if (*rfe___error___pointer != rfe_error_none_e)
		{
			break;
		}
		hpfCutOff = rfeRxHpfCutOffMapper(rfeCfg_chirpProfile_getRxHpfCutOffFrequency(pRfeConfig, rfeChirpProfileMapper(profileIdx), rfe___error___pointer));
		if (*rfe___error___pointer != rfe_error_none_e)
		{
			break;
		}
		/* All RX channels share one HPF filter setting */
		rxHpfCornerFeqEnum = rfeRxHPFMapper(hpfCutOff);

		/* Lookup the timing of the selected corner frequency setting */
		switch(rxHpfCornerFeqEnum)
		{
			case e_SYS_RXHPF_100KHZ:
			{
				filterSettleTime_us = rxHpf100kHzSettleTime_us;
				break;
			}
			case e_SYS_RXHPF_200KHZ:
			{
				filterSettleTime_us = rxHpf200kHzSettleTime_us;
				break;
			}
			case e_SYS_RXHPF_300KHZ:
			{
				filterSettleTime_us = rxHpf300kHzSettleTime_us;
				break;
			}
			case e_SYS_RXHPF_400KHZ:
			{
				filterSettleTime_us = rxHpf400kHzSettleTime_us;
				break;
			}
			case e_SYS_RXHPF_800KHZ:
			{
				filterSettleTime_us = rxHpf800kHzSettleTime_us;
				break;
			}
			case e_SYS_RXHPF_1600KHZ:
			{
				filterSettleTime_us = rxHpf1600kHzSettleTime_us;
				break;
			}
			case e_SYS_RXHPF_3200KHZ:
			{
				filterSettleTime_us = rxHpf3200kHzSettleTime_us;
				break;
			}
			default:
			{
				filterSettleTime_us = 0.0f;
				break;
			}
		}
		if(filterSettleTime_us <= 0.0f)
		{
#ifdef RFE_DEBUG
			RfeDbgPrintMsg("Profile %d - rfe_error_api_invalidConfigurationParameterValue_e", profileIdx);
#endif
		}
		if (filterSettleTime_us > longestFilterSettleTime_us)
		{
			longestFilterSettleTime_us = filterSettleTime_us;
		}
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		if (longestFilterSettleTime_us <= 0.0f)
		{
			*rfe___error___pointer = rfe_error_api_invalidConfigurationParameterValue_e;
#ifdef RFE_DEBUG
			RfeDbgPrintMsg("rfe_error_api_invalidConfigurationParameterValue_e");
#endif
		}
	}

    return longestFilterSettleTime_us;
}

/*=================================================================================================
 *                                       GLOBAL FUNCTIONS
=================================================================================================*/

void RfeSwCfgTimingReqCalculateTiming(rfeDriverPersistentMem_t *pDrvState,
		                              rfe_error_t *rfe___error___pointer)
{    
    float32_t tDwell_us = 0.0f;
    float32_t tSettle_us = 0.0f;
    float32_t txGroupDelay_us = 0.0f;
    float32_t txSwAndBpsDelayT1_us = 0.0f;
    float32_t hpfResetReleaseDelayT2_us = 0.0f;
    float32_t rxLongestDelayFineControlPowerOn_us = 0.0f;
    float32_t txLongestDelayFineControlPowerOn_us = 0.0f;
    float32_t rxActiveDelayT1_us = 0.0f;

    /* Initialization of timing variables to find the shortest delay over all enabled profiles, start initially high */
    float32_t dwellPhaseShortestFound_us = 999999.0f;
    float32_t settlePhaseShortestFound_us = 999999.0f;
    float32_t dwellSettlePhasesShortestFound_us = 999999.0f;
    float32_t txGroupDelayShortestFound_us = 999999.0f;
    float32_t longestFilterSettleTime_us = 0.0f;
    float32_t rfeDefaultDeltaPowerOnStaggering_us = 0.0f;
	float32_t settlePhases;
	uint8_t   profileIdx;

	/* Because the CPM state will determine the existence of the DcPowerOnDelay phase,
	   the recommended delta timing of the staggered powering ON of the TX and RX modules
	   is fine tuned */
	if (pDrvState->tef82xxDrvState.chirpPowerSavingEnabled != 0U)
	{
		/* DcPowerOnDelay phase is NOT available, timing of staggering must fit in settle phase.
		   Use a shorter delta timing */
		rfeDefaultDeltaPowerOnStaggering_us = rfeRecommendedDeltaPowerOnStaggeringCpmEnabled_us;
	}
	else
	{
		/* DcPowerOnDelay phase is available to have timing wise a more relaxed staggering */
		rfeDefaultDeltaPowerOnStaggering_us = rfeRecommendedDeltaPowerOnStaggeringCpmDisabled_us;
	}

    uint8_t	  noChirpProfiles = 0u;

#ifdef RFE_DEBUG
    float32_t recommendedChange_us = 0.0f;
    uint8_t   dwellSettlePhasesShortestFoundInProfileId = 0u;
#endif

    /* Initialize the static timings and check requirements */
    rfeStaticConfigInitialize(pDrvState->rfeConfig, rfe___error___pointer);
	if (*rfe___error___pointer == rfe_error_none_e)
    {
		noChirpProfiles = rfeCfg_metadata_getChirpProfileCount(pDrvState->rfeConfig, rfe___error___pointer);
    }

    /* Iterate through all enabled profiles to find the shortest hpfResetReleaseDelay_us.
       For all calculations T1 (start at TDwell) is the default reference point */
	for(profileIdx = 0; profileIdx < noChirpProfiles; profileIdx++)
	{
        /* Get the timing data of this specific profile */
		if (*rfe___error___pointer != rfe_error_none_e)
		{
			break;
		}
			tDwell_us = (float32_t)rfeCfg_chirpProfile_getDwellTimeTicks(pDrvState->rfeConfig, (rfe_chirpProfileIndex_t)profileIdx, rfe___error___pointer) * TICK_TO_US;
		if (*rfe___error___pointer != rfe_error_none_e)
		{
			break;
		}
			tSettle_us = (float32_t)rfeCfg_chirpProfile_getSettleTimeTicks(pDrvState->rfeConfig, (rfe_chirpProfileIndex_t)profileIdx, rfe___error___pointer) * TICK_TO_US;
		if (*rfe___error___pointer != rfe_error_none_e)
		{
			break;
		}
		/* Find the shortest dwell and settle times, but also the shortest of both combined */
		if (tDwell_us < dwellPhaseShortestFound_us)
		{
			dwellPhaseShortestFound_us = tDwell_us;
		}
		if (tSettle_us < settlePhaseShortestFound_us)
		{
			settlePhaseShortestFound_us = tSettle_us;
		}
		settlePhases = tDwell_us + tSettle_us;
		if (settlePhases < dwellSettlePhasesShortestFound_us)
		{
			dwellSettlePhasesShortestFound_us = settlePhases;
#ifdef RFE_DEBUG
			dwellSettlePhasesShortestFoundInProfileId = profileIdx;
#endif
		}
		if (settlePhases > dwellPhaseLongestFound_us)
		{
			dwellPhaseLongestFound_us = settlePhases;
		}
    }
    if (*rfe___error___pointer == rfe_error_none_e)
    {
		/* Determine the best possible reference points where to start the delays to be compliant with the AN13777
		   constrains, but also with the minimum and maximum values of the TEF82xx register requirements */

		/* The lowest RX HPF corner frequency requires the longest time to settle the RX signal. Find over all enabled
		   profiles, the longest settling time to calculate the RX hpfResetReleaseDelay_us and start reference point (dwell or settle phase) */
        longestFilterSettleTime_us = DetermineLongestRxHpfSettleTime_us(pDrvState->rfeConfig, rfe___error___pointer);
    }
    if (*rfe___error___pointer == rfe_error_none_e)
    {
        if (longestFilterSettleTime_us < settlePhaseShortestFound_us)
        {
            /* From all enabled profiles, the shortest found TSettle is long enough to fit the longest found RX HPF
               settling time. Use start reference point to T2 (settle phase) */
        	hpfResetReleaseDelayT2_us = settlePhaseShortestFound_us - longestFilterSettleTime_us;
            rxFilterCtrlParams.hpfResetReleaseCtrl = TRUE;
            rxFilterCtrlParams.hpfResetReleaseDelay_us = hpfResetReleaseDelayT2_us;
        }
        else
        {
            /* The RX hpfResetReleaseDelay_us can be maintained at reference start point T1 (dwell phase) */
            rxFilterCtrlParams.hpfResetReleaseCtrl = FALSE;
            rxFilterCtrlParams.hpfResetReleaseDelay_us = dwellSettlePhasesShortestFound_us - longestFilterSettleTime_us;
        }

    /* Check if the RX hpfResetReleaseDelay_us value fits with the required TEF82xx register range */
		if (rxFilterCtrlParams.hpfResetReleaseDelay_us > maximumDelay_us)
		{
#ifdef RFE_DEBUG
			recommendedChange_us = rxFilterCtrlParams.hpfResetReleaseDelay_us - maximumDelay_us;
#endif
			rxFilterCtrlParams.hpfResetReleaseDelay_us = maximumDelay_us;

#ifdef RFE_DEBUG
			(void)snprintf(temporary_buf, sizeof(temporary_buf), "HPFResetReleaseDelay must be clipped on"FORMAT_FLOAT_3P3" us to meet requirement. HPF filter will settle earlier than start of acquisition. Reduce phase %s with"FORMAT_FLOAT_3P3" us.\n",
        		SPLIT_FLOAT_3P3(maximumDelay_us), (rxFilterCtrlParams.hpfResetReleaseCtrl == TRUE) ? "T2 (settle)" : "T1 (dwell)", SPLIT_FLOAT_3P3(recommendedChange_us));
			RfeDbgPrintMsg(temporary_buf);
#endif
		}
		else if (rxFilterCtrlParams.hpfResetReleaseDelay_us < minimumDelay_us)
		{
#ifdef RFE_DEBUG
			recommendedChange_us = (float32_t)fabs((float64_t)minimumDelay_us - (float64_t)rxFilterCtrlParams.hpfResetReleaseDelay_us);

			(void)snprintf(temporary_buf, sizeof(temporary_buf), "Set HPFResetReleaseDelay does not fit in shortest dwell + settle. Increase time value(s) of Profile ID %d with"FORMAT_FLOAT_3P3" us.\n",
					 dwellSettlePhasesShortestFoundInProfileId, SPLIT_FLOAT_3P3(recommendedChange_us));
			RfeDbgPrintMsg(temporary_buf);

			*rfe___error___pointer = rfe_error_bc_teHpfResetWrongTriggerPoint;
			RfeDbgPrintMsg("rfe_error_bc_teHpfResetWrongTriggerPoint");
#endif
		}
		else
		{
#ifdef RFE_DEBUG
		    (void)snprintf(temporary_buf, sizeof(temporary_buf), "Set HPFResetReleaseDelay ="FORMAT_FLOAT_3P3" us starting at %s.\n",
					SPLIT_FLOAT_3P3(rxFilterCtrlParams.hpfResetReleaseDelay_us), (rxFilterCtrlParams.hpfResetReleaseCtrl == TRUE) ? "T2 (settle)" : "T1 (dwell)");
			RfeDbgPrintMsg(temporary_buf);
#endif
		}
    }
    if (*rfe___error___pointer == rfe_error_none_e)
    {
		/*  Determine rxActiveDelay_us and start reference point (dwell or settle phase).
			Check if the still fits in the same phase where also RX hpfResetReleaseDelay_us is positioned.
			Apply the timing constrain 4 from AN13777, the rxActiveDelay_us must expire >=0.15 us earlier
			before RX HPF reset is released */

		if (rxFilterCtrlParams.hpfResetReleaseDelay_us > (constrain_4_us + minimumDelay_us))
		{
			/* Use the same start reference point from the RX HPF reset release delay also for RX activate */
			rxFilterCtrlParams.rxActiveCtrl = rxFilterCtrlParams.hpfResetReleaseCtrl;
			rxFilterCtrlParams.rxActiveDelay_us = rxFilterCtrlParams.hpfResetReleaseDelay_us - constrain_4_us;
		}
		else
		{
			/* The remaining part of the rxActiveDelay_us must be moved to T1 (dwell phase) */
			rxFilterCtrlParams.rxActiveCtrl = FALSE;
			rxFilterCtrlParams.rxActiveDelay_us = dwellPhaseShortestFound_us - constrain_4_us + rxFilterCtrlParams.hpfResetReleaseDelay_us;

			/* Check if the rxActiveDelay_us value fits with the required TEF82xx register range.
			   The maximum value will be clipped, but the minimum will result in an error */
			if (rxFilterCtrlParams.rxActiveDelay_us > maximumDelay_us)
			{
#ifdef RFE_DEBUG
				recommendedChange_us = rxFilterCtrlParams.rxActiveDelay_us - maximumDelay_us;
#endif
				rxFilterCtrlParams.rxActiveDelay_us = maximumDelay_us;

#ifdef RFE_DEBUG
				(void)snprintf(temporary_buf, sizeof(temporary_buf), "RxActiveDelay must be clipped on"FORMAT_FLOAT_3P3" us to meet requirement. RX will be activated before dwell phase end. This can be optimized by reducing TSettle with"FORMAT_FLOAT_3P3" us.\n",
						SPLIT_FLOAT_3P3(maximumDelay_us), SPLIT_FLOAT_3P3(recommendedChange_us));
				RfeDbgPrintMsg(temporary_buf);
#endif
			}
			else
			{
#ifdef RFE_DEBUG
			    (void)snprintf(temporary_buf, sizeof(temporary_buf), "Set RxActiveDelay ="FORMAT_FLOAT_3P3" us starting at %s.\n",
						 SPLIT_FLOAT_3P3(rxFilterCtrlParams.rxActiveDelay_us),
						 (rxFilterCtrlParams.hpfResetReleaseCtrl == TRUE) ? "T2 (settle)" : "T1 (dwell)");
				RfeDbgPrintMsg(temporary_buf);
#endif
				if (rxFilterCtrlParams.rxActiveDelay_us < minimumDelay_us)
				{
					*rfe___error___pointer = rfe_error_parameterOutOfRange_e;
#ifdef RFE_DEBUG
					RfeDbgPrintMsg("rfe_error_parameterOutOfRange_e");
#endif
				}
			}
			if (*rfe___error___pointer == rfe_error_none_e)
			{
				if (rxFilterCtrlParams.hpfResetReleaseCtrl == FALSE)
				{
					/* If HPFResetReleaseDelay is already T1 (dwell phase) and could not meet the constrain_4_us.
					   The above mode of RxActiveDelay to T1 (dwell phase) won't fix this */
#ifdef RFE_DEBUG
					recommendedChange_us = constrain_4_us + minimumDelay_us - rxFilterCtrlParams.hpfResetReleaseDelay_us;
					(void)snprintf(temporary_buf, sizeof(temporary_buf), "RxActiveDelay does NOT fit in settle phase. Increase TDwell and/or TSettle of Profile ID %d with"FORMAT_FLOAT_3P3" us.\n",
							 dwellSettlePhasesShortestFoundInProfileId, SPLIT_FLOAT_3P3(recommendedChange_us));
					RfeDbgPrintMsg(temporary_buf);

					*rfe___error___pointer = rfe_error_parameterOutOfRange_e;
					RfeDbgPrintMsg("rfe_error_parameterOutOfRange_e");
#endif
				}
			}
		}
    }
    if (*rfe___error___pointer == rfe_error_none_e)
    {
#ifdef RFE_DEBUG
        (void)snprintf(temporary_buf, sizeof(temporary_buf), "Set RxActiveDelay ="FORMAT_FLOAT_3P3" us starting at %s must be >="FORMAT_FLOAT_3P3".\n",
				 SPLIT_FLOAT_3P3(rxFilterCtrlParams.rxActiveDelay_us),
				 (rxFilterCtrlParams.hpfResetReleaseCtrl == TRUE) ? "T2 (settle)" : "T1 (dwell)",
				 SPLIT_FLOAT_3P3(minimumDelay_us));
		RfeDbgPrintMsg(temporary_buf);
#endif
		if (rxFilterCtrlParams.rxActiveDelay_us < minimumDelay_us)
		{
			*rfe___error___pointer = rfe_error_parameterOutOfRange_e;
#ifdef RFE_DEBUG
			RfeDbgPrintMsg("rfe_error_parameterOutOfRange_e");
#endif
		}
    }
    /* Determine TXSWAndBPSDelay_us and start reference point (dwell or settle phase) for every enabled profile.
       Iterate again through all enabled profiles. Timing constrain 2 from AN13777. The TXSWAndBPSDelay_us must 
       expire >= 0.5 us earlier before the rxActiveDelay_us does */
 
	for (profileIdx = 0; profileIdx < noChirpProfiles; profileIdx++)
	{
        /* Get the timing data of this specific profile */
		if (*rfe___error___pointer != rfe_error_none_e)
		{
			break;
		}
        tDwell_us = (float32_t)rfeCfg_chirpProfile_getDwellTimeTicks(pDrvState->rfeConfig, (rfe_chirpProfileIndex_t)profileIdx, rfe___error___pointer) * TICK_TO_US;
		if (*rfe___error___pointer != rfe_error_none_e)
		{
			break;
		}
		/* Base timing calculations require T1 as base reference point before timing constrain 2 is applied.
		   Check which reference start point is used */
		if (rxFilterCtrlParams.rxActiveCtrl == TRUE)
		{
			/* Convert to T1 start reference point */
			txSwAndBpsDelayT1_us = rxFilterCtrlParams.rxActiveDelay_us + tDwell_us - constrain_2_us;
		}
		else
		{
			txSwAndBpsDelayT1_us = rxFilterCtrlParams.rxActiveDelay_us - constrain_2_us;
		}

		/* Check if TXSWAndBPSDelay_us fits within dwell phase */
		if (txSwAndBpsDelayT1_us > tDwell_us)
		{
			/* Does not fit. Move start point to T2. Calculate the remaining delay, performed in the settle phase */
			profileChirpTimingDataLocal[profileIdx].triggerTXSWAndBPSAtTSettle = true;
			profileChirpTimingDataLocal[profileIdx].txSWAndBPSDelay_us = txSwAndBpsDelayT1_us - tDwell_us;
		}
		else
		{
			/* Timing fits in dwell phase. Keep T1 as start reference point like previous calculations have done */
			profileChirpTimingDataLocal[profileIdx].triggerTXSWAndBPSAtTSettle = false;
			profileChirpTimingDataLocal[profileIdx].txSWAndBPSDelay_us = txSwAndBpsDelayT1_us;
		}

		if (profileChirpTimingDataLocal[profileIdx].txSWAndBPSDelay_us < minimumTxSwAndBpsDelay_us)
		{
#ifdef RFE_DEBUG
			recommendedChange_us = (float32_t)fabs((float64_t)minimumTxSwAndBpsDelay_us - (float64_t)profileChirpTimingDataLocal[profileIdx].txSWAndBPSDelay_us);

			(void)snprintf(temporary_buf, sizeof(temporary_buf), "TXSWAndBPSDelay is too short. Increase TDwell and/or TSettle of Profile ID %d with"FORMAT_FLOAT_3P3" us.\n",
					 dwellSettlePhasesShortestFoundInProfileId, SPLIT_FLOAT_3P3(recommendedChange_us));
			RfeDbgPrintMsg(temporary_buf);
			RfeDbgPrintMsg("rfe_error_parameterOutOfRange_e");
#endif
			*rfe___error___pointer = rfe_error_parameterOutOfRange_e;
			break;
		}

#ifdef RFE_DEBUG
		(void)snprintf(temporary_buf, sizeof(temporary_buf), "Set TXSWAndBPSDelay ="FORMAT_FLOAT_3P3" us starting at %s for profile ID %d.\n",
				 SPLIT_FLOAT_3P3(profileChirpTimingDataLocal[profileIdx].txSWAndBPSDelay_us),
				 profileChirpTimingDataLocal[profileIdx].triggerTXSWAndBPSAtTSettle ? "T2 (settle)" : "T1 (dwell)",
				 profileIdx);
		RfeDbgPrintMsg(temporary_buf);
#endif
		if (profileChirpTimingDataLocal[profileIdx].txSWAndBPSDelay_us < minimumTxSwAndBpsDelay_us)
		{
			*rfe___error___pointer = rfe_error_parameterOutOfRange_e;
#ifdef RFE_DEBUG
			RfeDbgPrintMsg("rfe_error_parameterOutOfRange_e");
#endif
			break;
		}

		/* Calculate the individual GDelayFineControl values. First fine control can start at zero because the offset can
		   be added with TXGroupDelay_us and RXGroupDelay_us. The fine control values are shared by RX and TX, so these
		   represent RX1, RX2, RX3, RX4 but also on TX1, TX2, TX3. Because rfeDefaultDeltaPowerOnStaggering_us represents
		   the delta steps between RX1, TX1, RX2, TX2, RX3, etc. it is required to multiply 2 */
		staticConfig.GDelayFineControl1 = 0.0f;
		staticConfig.GDelayFineControl2 = staticConfig.GDelayFineControl1 + (rfeDefaultDeltaPowerOnStaggering_us * 2.0f);
		staticConfig.GDelayFineControl3 = staticConfig.GDelayFineControl2 + (rfeDefaultDeltaPowerOnStaggering_us * 2.0f);
		staticConfig.GDelayFineControl4 = staticConfig.GDelayFineControl3 + (rfeDefaultDeltaPowerOnStaggering_us * 2.0f);

		/* Time constrain 1 from AN13777, the TX power ON must be completed >=1.5us earlier than the
		   TriggerTXSWAndBPSAtTSettle expires to close the TX fast switch and BPS control.
		   Take the longest delay stored in GDelayFineControl3 (TX3) */
		txLongestDelayFineControlPowerOn_us = staticConfig.GDelayFineControl3;

		if (pDrvState->tef82xxDrvState.chirpPowerSavingEnabled != 0U)
		{
			/* The staggered TX1, TX2 and TX3 power ON must fit in remaining part of phase.
			   Reference start points: T1 when CPM is enabled */
			if ((txSwAndBpsDelayT1_us - constrain_1_us) >=
				(txLongestDelayFineControlPowerOn_us + minimumTxGroupDelay_us))
			{
				/* Fits. Calculate the group delay to meet constrain_1 */
				txGroupDelay_us = txSwAndBpsDelayT1_us - txLongestDelayFineControlPowerOn_us - constrain_1_us;
			}
			else
			{
#ifdef RFE_DEBUG
				recommendedChange_us = txLongestDelayFineControlPowerOn_us + minimumTxGroupDelay_us
									 - txSwAndBpsDelayT1_us + constrain_1_us;

				(void)snprintf(temporary_buf, sizeof(temporary_buf), "Delay between TX power ON and TX fast switch and BPS control must be >="FORMAT_FLOAT_3P3" us. Increase the shortest Dwell + Settle times to fit in the power ON delays. Increase with"FORMAT_FLOAT_3P3" us.\n",
						 SPLIT_FLOAT_3P3(constrain_1_us), SPLIT_FLOAT_3P3(recommendedChange_us));
				RfeDbgPrintMsg(temporary_buf);
				RfeDbgPrintMsg("rfe_error_parameterOutOfRange_e");
#endif
				*rfe___error___pointer = rfe_error_parameterOutOfRange_e;
				break;
			}
		}

		/* Calculate the TE TX groups delay (static configuration item and hereby not profile based) and
		   scan all enabled profiles to determine the shortest TX group delay. This one is finally used
		   to calculate the RX group delay */
		if (txGroupDelay_us < txGroupDelayShortestFound_us)
		{
			txGroupDelayShortestFound_us = txGroupDelay_us;
		}
    } /* Iteration profileIdx */

	if (*rfe___error___pointer == rfe_error_none_e)
	{
        staticConfig.TXGroupDelay = txGroupDelayShortestFound_us;

        /* Time constrain 3 from AN13777, the RX power ON must expire >=2.0us earlier than the RX activation.
           Power ON timing constrain checks require reference start point T1 for rxActiveDelay_us. */
        rxActiveDelayT1_us = rxFilterCtrlParams.rxActiveDelay_us;
        if (rxFilterCtrlParams.rxActiveCtrl == TRUE)
        {
            /* Start point of the RX active delay is at T2 (settle phase). Convert to T1 by using from all
            enabled profiles the shortest found dwell time */
            rxActiveDelayT1_us += dwellPhaseShortestFound_us;
        }

        /* Take the longest delay stored in GDelayFineControl4 (RX4) of the staggered RX1, RX2, RX3 and RX4 power ON */
        rxLongestDelayFineControlPowerOn_us = staticConfig.GDelayFineControl4;

        if (pDrvState->tef82xxDrvState.chirpPowerSavingEnabled != 0U)
		{
			/* The staggered RX1, RX2, RX3 and RX4 power ON must fit in remaining part of phase.
			   Reference start points: T1 when CPM is enabled */
			if ((rxActiveDelayT1_us - constrain_3_us) >=
				(rxLongestDelayFineControlPowerOn_us + minimumRxGroupDelay_us))
			{
				/* Fits. Calculate the group delay to meet constrain_3 */
				staticConfig.RXGroupDelay = rxActiveDelayT1_us - rxLongestDelayFineControlPowerOn_us - constrain_3_us;
			}
			else
			{
#ifdef RFE_DEBUG
				recommendedChange_us = rxLongestDelayFineControlPowerOn_us + minimumRxGroupDelay_us
									 - rxActiveDelayT1_us + constrain_3_us;

				(void)snprintf(temporary_buf, sizeof(temporary_buf), "Delay between RX power ON and RX activate must be >= "FORMAT_FLOAT_3P3" us. Dwell + Settle time for power ON delays is too short. Increase with"FORMAT_FLOAT_3P3" us.\n",
						 SPLIT_FLOAT_3P3(constrain_3_us), SPLIT_FLOAT_3P3(recommendedChange_us));
				RfeDbgPrintMsg(temporary_buf);
				RfeDbgPrintMsg("rfe_error_parameterOutOfRange_e");
#endif
				*rfe___error___pointer = rfe_error_parameterOutOfRange_e;
			}
		}
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		if (pDrvState->tef82xxDrvState.chirpPowerSavingEnabled == 0U)
		{
			/* CPM is disabled. The group delays will be executed in the DcPowerOnDelay phase and start at T0. Use the
			   recommended fixed group delay to prevent ISM TX high warnings. More details can be found where the constant
			   rfeRecommendedGroupDelayCpmDisabled_us is declared. Delta between RX and TX is calculated in next code block */
			staticConfig.RXGroupDelay = rfeRecommendedGroupDelayCpmDisabled_us;
			staticConfig.TXGroupDelay = rfeRecommendedGroupDelayCpmDisabled_us;
		}
		/* Else CPM is enabled. There is no DcPowerOnDelay phase and the group delays will be executed in the dwell phase
		   (start point T1) */

		/* Use the shortest RX or TX group delay to align the other delay. Add delta staggering time to power ON
		   the RX and TX modules in order of RX1, TX1, RX2, TX2, RX3, TX3, RX4 */
		if (staticConfig.TXGroupDelay >= staticConfig.RXGroupDelay)
		{
			staticConfig.TXGroupDelay = staticConfig.RXGroupDelay + rfeDefaultDeltaPowerOnStaggering_us;
		}
		else
		{
			staticConfig.RXGroupDelay = staticConfig.TXGroupDelay + rfeDefaultDeltaPowerOnStaggering_us;
		}

#ifdef RFE_DEBUG
		/* Output debug timing information about TX RX power ON staggering */
		(void)snprintf(temporary_buf, sizeof(temporary_buf), "DC power ON delays in %s phase:\n", (pDrvState->tef82xxDrvState.chirpPowerSavingEnabled != 0U) ? "Dwell (T1)" : "DC Power ON (T0)");
		RfeDbgPrintMsg(temporary_buf);
		(void)snprintf(temporary_buf, sizeof(temporary_buf), "   Staggering RX1 = "FORMAT_FLOAT_3P3"       RX2 = "FORMAT_FLOAT_3P3"       RX3 = "FORMAT_FLOAT_3P3"       RX4 = "FORMAT_FLOAT_3P3" us.\n",
				 SPLIT_FLOAT_3P3(staticConfig.RXGroupDelay + staticConfig.GDelayFineControl1),
				 SPLIT_FLOAT_3P3(staticConfig.RXGroupDelay + staticConfig.GDelayFineControl2),
				 SPLIT_FLOAT_3P3(staticConfig.RXGroupDelay + staticConfig.GDelayFineControl3),
				 SPLIT_FLOAT_3P3(staticConfig.RXGroupDelay + staticConfig.GDelayFineControl4));
		RfeDbgPrintMsg(temporary_buf);
		(void)snprintf(temporary_buf, sizeof(temporary_buf), "                    TX1 = "FORMAT_FLOAT_3P3"       TX2 = "FORMAT_FLOAT_3P3"       TX3 = "FORMAT_FLOAT_3P3" us.\n",
				 SPLIT_FLOAT_3P3(staticConfig.TXGroupDelay + staticConfig.GDelayFineControl1),
				 SPLIT_FLOAT_3P3(staticConfig.TXGroupDelay + staticConfig.GDelayFineControl2),
				 SPLIT_FLOAT_3P3(staticConfig.TXGroupDelay + staticConfig.GDelayFineControl3));
		RfeDbgPrintMsg(temporary_buf);
#endif
	}
}

bool RfeSwCfgTimingReqGetTriggerTXSWAndBPSAtTSettle(uint8_t profileIdx, rfe_error_t* rfe___error___pointer)
{
	bool triggerTXSWAndBPSAtTSettle = false;

	/* Check also if the local data is generated */
    if ((profileIdx < RFE_CHIRP_PROFILES_MAX) && (profileChirpTimingDataLocal[profileIdx].txSWAndBPSDelay_us > 0.0f))
    {
    	triggerTXSWAndBPSAtTSettle = profileChirpTimingDataLocal[profileIdx].triggerTXSWAndBPSAtTSettle;
    }
    else
    {
        *rfe___error___pointer = rfe_error_api_invalidArgumentValue_e;
#ifdef RFE_DEBUG
        RfeDbgPrintMsg("rfe_error_api_invalidArgumentValue_e");
#endif
    }

	return triggerTXSWAndBPSAtTSettle;
}

float32_t RfeSwCfgTimingReqGetTXSWAndBPSDelay_us(uint8_t profileIdx, rfe_error_t* rfe___error___pointer)
{
	float32_t TXSWAndBPSDelay_us = 0.0f;

	/* Check also if the local data is generated */
    if ((profileIdx < RFE_CHIRP_PROFILES_MAX) && (profileChirpTimingDataLocal[profileIdx].txSWAndBPSDelay_us > 0.0f))
    {
    	TXSWAndBPSDelay_us = profileChirpTimingDataLocal[profileIdx].txSWAndBPSDelay_us;
    }
    else
    {
        *rfe___error___pointer = rfe_error_api_invalidArgumentValue_e;
#ifdef RFE_DEBUG
        RfeDbgPrintMsg("rfe_error_api_invalidArgumentValue_e");
#endif
    }

	return TXSWAndBPSDelay_us;
}

TE_StaticConfig_t RfeSwCfgTimingReqGetStaticConfig(rfe_error_t* rfe___error___pointer)
{
	/* Check also if the local data is generated */
	if ((staticConfig.TXGroupDelay <= 0.0f) || (staticConfig.RXGroupDelay <= 0.0f))
    {
        *rfe___error___pointer = rfe_error_api_invalidArgumentValue_e;
#ifdef RFE_DEBUG
        RfeDbgPrintMsg("rfe_error_api_invalidArgumentValue_e");
#endif
    }

	return staticConfig;
}

void RfeSwCfgTimingReqGetRxFilterCtrlParams(rfeRxFilterCtrlParams_t *pRxFilterCtrlParams, rfe_error_t* rfe___error___pointer)
{
	/* Check also if the local data is generated */
	if ((rxFilterCtrlParams.hpfResetReleaseDelay_us <= 0.0f) || (rxFilterCtrlParams.rxActiveDelay_us <= 0.0f))
    {
        *rfe___error___pointer = rfe_error_api_invalidArgumentValue_e;
#ifdef RFE_DEBUG
        RfeDbgPrintMsg("rfe_error_api_invalidArgumentValue_e");
#endif
    }

	*pRxFilterCtrlParams = rxFilterCtrlParams;
}

void RfeSwCfgTimingReq_GetDynIQUpdatesTiming(float32_t * dwellSettleTimeP, float32_t * dcGroupDelayP)
{
	*dwellSettleTimeP = dwellPhaseLongestFound_us;
	*dcGroupDelayP = staticConfig.DCPowerOnDelay;
}
