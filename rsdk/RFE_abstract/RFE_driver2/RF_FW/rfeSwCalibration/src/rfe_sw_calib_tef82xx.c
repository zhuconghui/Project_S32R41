/**************************************************************************************************
 * Copyright 2022 - 2023 NXP
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

/*==================================================================================================
 *                                       INCLUDES
 ==================================================================================================*/

#include <math.h>
#include <string.h>

#include <rfe_sw_cfg_to_tef82xx_map.h>
#include "rfe_sw_calib_tef82xx.h"
#include "rfe_sw_cfg_tef82xx.h"
#include "rfe_sw_driver_state.h"
#include "rfeSwMainFsm.h"
#include "rfe_blob_access.h"
#include "rfe_types.h"
#include "rfeSwInit.h"
#include "rfe_debug.h"
#include "rfeHwLink.h"
#include "rfeSwUtils.h"

#include "bc_err.h"
#include "bc_conf.h"
#include "bc_types.h"
#include "bc_mclk.h"
#include "bc_sc.h"
#include "bc_cafc.h"
#include "bc_tx.h"
#include "bc_loi.h"
#include "bc_rx.h"
#include "bc_ism.h"
#include "bc_spi.h"
#include "bc_adc.h"
#include "bc_types.h"

#include "reg_es2_loi.h"
#include "reg_es2_ism.h"
#include "reg_es2_cc.h"
#include "reg_es2_adc.h"
/*==================================================================================================
 *                                      DEFINES
==================================================================================================*/

#define TEF82XX_DISABLED_TX         -1.0f
#define PERCNT_CUR_GAIN_ADJ			4U	// in according with LLD
#define PERCNT_BIAS_CUR_GAIN_ADJ	2U	// in according with LLD
#define TX_CALIB_THRESHOLD_ADJ		0.01f //use to convert dB from blob value to float

/* PLL Loop BW limitations per VCO are defined according to where the respective VCO's support
 * the "fast return" features. For more information please refer to the Reference Manual RM00227 */
#define VCO_1G_MIN_PLL_LOOP_BW		200000.0f
#define VCO_1G_MAX_PLL_LOOP_BW		300000.0f
#define VCO_2G_MIN_PLL_LOOP_BW		250000.0f
#define VCO_2G_MAX_PLL_LOOP_BW		300000.0f
#define VCO_4G_MIN_PLL_LOOP_BW		300000.0f
#define VCO_4G_MAX_PLL_LOOP_BW		350000.0f

/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
typedef enum
{
    e_NR_PROFILES_0_TO_1 = 2,
    e_NR_PROFILES_0_TO_2,
    e_NR_PROFILES_0_TO_3,
    e_NR_PROFILES_0_TO_4,
    e_NR_PROFILES_0_TO_5,
    e_NR_PROFILES_0_TO_6,
    e_NR_PROFILES_0_TO_7,
}NR_PROFILES_e;

/*==================================================================================================
 *                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                       LOCAL MACROS
==================================================================================================*/
// ADC Calibration
#define DPCE_BITS_OFF 					0xfffffff7UL
#define RESET_DIGITAL_CAL_LOGIC			0x3fU
#define RELEASE_RESET_DIGITAL_CAL_LOGIC	0x1fU
#define START_FULL_ADC_CAL				0x01U

/*==================================================================================================
 *                                      LOCAL VARIABLES
==================================================================================================*/

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
 * @brief Function set used profiles in SYS_StoreInProfile_t structure
 * @param nrChirpProfiles - profiles used (profiles are consecutive)
 */
static SYS_StoreInProfile_t SetStoreInProfile(uint8_t nrChirpProfiles);
/*
 * @brief Function set SYS_StoreInProfile_t structure in accordance with list profiles
 * @param list - pointer to list profiles
 * @param nrSequenceProfiles - nr of profiles in list profiles
 */
static SYS_StoreInProfile_t ConfigListStoreInProfile(uint8_t* list, uint8_t nrSequenceProfiles);
/*
 * @brief Function set SYS_StoreInProfile_t structure in accordance with SYS_ProfID_e structure
 * @param profId - profiles used in sequence
 * @param list - pointer to list profiles
 * @param nrSequenceProfiles - nr of profiles in list profiles
 */
static SYS_StoreInProfile_t ConfigStoreInProfile(SYS_ProfID_e profId, uint8_t* profList, uint8_t nrSequenceProfiles);
/*
 * @brief Check and recovery ADC calibration when busy error
 *
 * @param  calibrationTimeout - true ; false - in/out param
 * @return TEF82xx error code
 */
static BC_ERRCODE AdcCalibrationBusyCheckAndRecovery(bool *calibrationTimeout);
/*==================================================================================================
 *                                      INTERNAL FUNCTIONS
 ==================================================================================================*/


static SYS_StoreInProfile_t SetStoreInProfile(uint8_t nrChirpProfiles)
{
    SYS_StoreInProfile_t storeInProfile = {0};

    if(nrChirpProfiles >= 1U)
    {
    	storeInProfile.Profile0 = TRUE;
    }
    if(nrChirpProfiles >= 2U)
	{
		storeInProfile.Profile1 = TRUE;
	}
    if(nrChirpProfiles >= 3U)
	{
		storeInProfile.Profile2 = TRUE;
	}
    if(nrChirpProfiles >= 4U)
	{
		storeInProfile.Profile3 = TRUE;
	}
    if(nrChirpProfiles >= 5U)
	{
		storeInProfile.Profile4 = TRUE;
	}
    if(nrChirpProfiles >= 6U)
	{
		storeInProfile.Profile5 = TRUE;
	}
    if(nrChirpProfiles >= 7U)
	{
		storeInProfile.Profile6 = TRUE;
	}
    if(nrChirpProfiles == 8U)
	{
		storeInProfile.Profile7 = TRUE;
	}

    return storeInProfile;
}

static SYS_StoreInProfile_t ConfigListStoreInProfile(uint8_t* list, uint8_t nrSequenceProfiles)
{
    SYS_StoreInProfile_t storeInProfile = {0};
    uint8_t i = 0;
    for(i = 0; i < nrSequenceProfiles; ++i)
    {
        switch(list[i])
        {
            case 0U:
            {
                storeInProfile.Profile0 = TRUE;
                break;
            }
            case 1U:
            {
                storeInProfile.Profile1 = TRUE;
                break;
            }
            case 2U:
            {
                storeInProfile.Profile2 = TRUE;
                break;
            }
            case 3U:
            {
                storeInProfile.Profile3 = TRUE;
                break;
            }
            case 4U:
            {
                storeInProfile.Profile4 = TRUE;
                break;
            }
            case 5U:
            {
                storeInProfile.Profile5 = TRUE;
                break;
            }
            case 6U:
            {
                storeInProfile.Profile6 = TRUE;
                break;
            }
            case 7U:
            {
                storeInProfile.Profile7 = TRUE;
                break;
            }
            default:
            {
                storeInProfile.Profile8 = TRUE;
                break;
            }
        }
    }
    return storeInProfile;
}

static void ConfigStoreInOneProfile(SYS_ProfID_e profId, SYS_StoreInProfile_t *storeInProfile)
{
	switch (profId)
	{
	case e_SYS_PROFILE_0:
		storeInProfile->Profile0 = (BOOL)TRUE;
		break;
	case e_SYS_PROFILE_1:
		storeInProfile->Profile1 = (BOOL)TRUE;
		break;
	case e_SYS_PROFILE_2:
		storeInProfile->Profile2 = (BOOL)TRUE;
		break;
	case e_SYS_PROFILE_3:
		storeInProfile->Profile3 = (BOOL)TRUE;
		break;
	case e_SYS_PROFILE_4:
		storeInProfile->Profile4 = (BOOL)TRUE;
		break;
	case e_SYS_PROFILE_5:
		storeInProfile->Profile5 = (BOOL)TRUE;
		break;
	case e_SYS_PROFILE_6:
		storeInProfile->Profile6 = (BOOL)TRUE;
		break;
	case e_SYS_PROFILE_7:
		storeInProfile->Profile7 = (BOOL)TRUE;
		break;
	case e_SYS_PROFILE_8:
		storeInProfile->Profile8 = (BOOL)TRUE;
		break;
	default:
		// MISRA
		break;
	}
}

static void ConfigStoreInMultiProfile(SYS_ProfID_e profId, SYS_StoreInProfile_t *storeInProfile,
		uint8_t* profList, uint8_t nrSequenceProfiles)
{
	switch (profId)
	{
	case e_SYS_PROFILES_0_TO_1:
		*storeInProfile = SetStoreInProfile((uint8_t)e_NR_PROFILES_0_TO_1);
		break;
	case e_SYS_PROFILES_0_TO_2:
		*storeInProfile = SetStoreInProfile((uint8_t)e_NR_PROFILES_0_TO_2);
		break;
	case e_SYS_PROFILES_0_TO_3:
		*storeInProfile = SetStoreInProfile((uint8_t)e_NR_PROFILES_0_TO_3);
		break;
	case e_SYS_PROFILES_0_TO_4:
		*storeInProfile = SetStoreInProfile((uint8_t)e_NR_PROFILES_0_TO_4);
		break;
	case e_SYS_PROFILES_0_TO_5:
		*storeInProfile = SetStoreInProfile((uint8_t)e_NR_PROFILES_0_TO_5);
		break;
	case e_SYS_PROFILES_0_TO_6:
		*storeInProfile = SetStoreInProfile((uint8_t)e_NR_PROFILES_0_TO_6);
		break;
	case e_SYS_PROFILES_0_TO_7:
		*storeInProfile = SetStoreInProfile((uint8_t)e_NR_PROFILES_0_TO_7);
		break;
	case e_SYS_PROFILE_LIST :
		*storeInProfile = ConfigListStoreInProfile(profList, nrSequenceProfiles);
		break;
	default:
		// MISRA
		break;
	}
}

static SYS_StoreInProfile_t ConfigStoreInProfile(SYS_ProfID_e profId, uint8_t* profList, uint8_t nrSequenceProfiles)
{
    SYS_StoreInProfile_t storeInProfile = {0};

    if(profId <= e_SYS_PROFILE_8)
    {
    	ConfigStoreInOneProfile(profId, &storeInProfile);
    }
    else
    {
    	ConfigStoreInMultiProfile(profId, &storeInProfile, profList, nrSequenceProfiles);
    }
    return storeInProfile;
}

static BC_ERRCODE TxCalibrationCheck(SYS_IPNum_e txIp, BC_ERRCODE receivedErrCode)
{
    TX_CalibrationStatus_t txCalibrationStatus = {0};
    BC_ERRCODE   errCode = BC_ERR_NOERROR;

    errCode = BC_TX_GetLocalCalibStatus(txIp, (BOOL)FALSE, &txCalibrationStatus);
    if (errCode == BC_ERR_NOERROR)
    {
        if ((txCalibrationStatus.PoutCal == e_ISM_CAL_SUCCESS) ||
                (txCalibrationStatus.PpdOffsetLox3Cal != e_ISM_CAL_SUCCESS) ||
                (txCalibrationStatus.PpdOffsetPrCal != e_ISM_CAL_SUCCESS) ||
                (txCalibrationStatus.PpdOffsetVgaCal != e_ISM_CAL_SUCCESS) ||
                (txCalibrationStatus.RfLox3Cal != e_ISM_CAL_SUCCESS) ||
                (txCalibrationStatus.RfPrCal != e_ISM_CAL_SUCCESS) ||
                (txCalibrationStatus.RfVgaCal != e_ISM_CAL_SUCCESS) ||
                (txCalibrationStatus.RfPrPhaseCal != e_ISM_CAL_SUCCESS) ||
                (txCalibrationStatus.TXCalibBusy != (BOOL)FALSE))
        {
            errCode = receivedErrCode;
        }
    }
    return errCode;
}

static void TxPowerBasedStoreInProfile(SYS_StoreInProfile_t *storeInProfile, float32_t *profilePowerLevels,
		float32_t currentPowerLevel, uint8_t nrChirpShapes, uint8_t* profList)
{
    uint8_t innerProfileId;

    for (innerProfileId = 0; innerProfileId < nrChirpShapes; innerProfileId++)
    {
        if ((fabsf((profilePowerLevels[profList[innerProfileId]] - currentPowerLevel))) <= DELTA_FLOAT)
        {
            // Enable this profile for calibration
            switch (profList[innerProfileId])
            {
            case (uint8_t)e_SYS_PROFILE_0:
                storeInProfile->Profile0 = TRUE;
                break;
            case (uint8_t)e_SYS_PROFILE_1:
                storeInProfile->Profile1 = TRUE;
                break;
            case (uint8_t)e_SYS_PROFILE_2:
                storeInProfile->Profile2 = TRUE;
                break;
            case (uint8_t)e_SYS_PROFILE_3:
                storeInProfile->Profile3 = TRUE;
                break;
            case (uint8_t)e_SYS_PROFILE_4:
                storeInProfile->Profile4 = TRUE;
                break;
            case (uint8_t)e_SYS_PROFILE_5:
                storeInProfile->Profile5 = TRUE;
                break;
            case (uint8_t)e_SYS_PROFILE_6:
                storeInProfile->Profile6 = TRUE;
                break;
            case (uint8_t)e_SYS_PROFILE_7:
                storeInProfile->Profile7 = TRUE;
                break;
            case (uint8_t)e_SYS_PROFILE_8:
                storeInProfile->Profile8 = TRUE;
                break;
            default:
                // MISRA
                break;
            }
            // Set profilePowerLevel to -1.0 to indicate profile set to be calibrated
            profilePowerLevels[profList[innerProfileId]] = -1.0f;
        }
    }
}

static BC_ERRCODE TxCalibration(SYS_StoreInProfile_t *pStoreInProfile,
        SYS_ProfID_e profId,
        BOOL performFullCal, BOOL reduceTransmisionForVGACalib)
{
    BC_ERRCODE   errCode = BC_ERR_NOERROR;
    BC_ERRCODE   errCodeTx1 = BC_ERR_NOERROR;
    BC_ERRCODE   errCodeTx2 = BC_ERR_NOERROR;
    BC_ERRCODE   errCodeTx3 = BC_ERR_NOERROR;

    BOOL readCalibStatus = FALSE;

    uint32_t txRfCalCheckTimeOutUs = 0U;
    SYS_EnableTxRfCalibration_t enableTxRfCalibration = {0};

    if(performFullCal == TRUE)
    {
        enableTxRfCalibration.PrCalStart = TRUE;
        enableTxRfCalibration.VgaCalStart = TRUE;
        enableTxRfCalibration.PPDOffsetCalStart = TRUE;
        enableTxRfCalibration.PrPhaseCalStart = TRUE;
        if(reduceTransmisionForVGACalib == FALSE)
        {
        	enableTxRfCalibration.PoutCalStart = TRUE;
        	txRfCalCheckTimeOutUs = RSDK_TEF82XX_TXCAL_POUT_TIMEOUT;
        }

        //Total TX calibrations execution time is approx 600uS
		txRfCalCheckTimeOutUs = RSDK_TEF82XX_TXCAL_PR_TIMEOUT +
								RSDK_TEF82XX_TXCAL_VGA_TIMEOUT +
								RSDK_TEF82XX_TXCAL_PPD_OFFSET_TIMEOUT +
								RSDK_TEF82XX_TXCAL_PR_PHASE_TIMEOUT +
								txRfCalCheckTimeOutUs;
    }
    else
    {
        enableTxRfCalibration.PoutCalStart = TRUE;
        txRfCalCheckTimeOutUs = RSDK_TEF82XX_TXCAL_POUT_TIMEOUT;
    }

    errCode = BC_TX_CalibrateTXRF(e_SYS_TXMC, &enableTxRfCalibration, pStoreInProfile, readCalibStatus,
            txRfCalCheckTimeOutUs, profId, reduceTransmisionForVGACalib);

    if (errCode == BC_ERR_NOERROR)
    {
        errCodeTx1 = TxCalibrationCheck(e_SYS_TX1, errCode);
        errCodeTx2 = TxCalibrationCheck(e_SYS_TX2, errCode);
        errCodeTx3 = TxCalibrationCheck(e_SYS_TX3, errCode);
        if (errCodeTx1 != BC_ERR_NOERROR)
        {
            errCode = errCodeTx1;
        }
        else if (errCodeTx2 != BC_ERR_NOERROR)
        {
            errCode = errCodeTx2;
        }
        else if (errCodeTx3 != BC_ERR_NOERROR)
        {
            errCode = errCodeTx3;
        }
        else
        {
            /* MISRA 15.7 */
        }
    }
    return errCode;
}

static BC_ERRCODE PerformTxCalibWithoutRadiation(uint8_t currentChirpSequenceIndexParam, rfeDriverPersistentMem_t * pDrvState,
		float32_t levelHighDelta, float32_t levelLowDelta, SYS_StoreInProfile_t* storeInProfile, uint8_t profileId, uint8_t* profList)
{
	BC_ERRCODE   errCode = BC_ERR_NOERROR;

	if(pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[currentChirpSequenceIndexParam].firstCalib != FALSE)
	{
		errCode = BC_TX_SetRFCalMonLevel(e_SYS_TXMC, levelHighDelta, levelLowDelta);
		// First time calibration for TX Calibration without transmission requires seperated TX Pout calibration
		if (errCode == BC_ERR_NOERROR)
		{
			errCode = TxCalibration(storeInProfile, rfeProfModeSelMapper(profList[profileId]), FALSE, FALSE);
		}
		if (errCode == BC_ERR_NOERROR)
		{
			errCode = BC_TX_GetProfileCurrGain(e_SYS_TX1, rfeProfModeSelMapper(profList[profileId]),
					&pDrvState->tef82xxDrvState.txCurrGain[rfeProfModeSelMapper(profList[profileId])][RFE_TX_CHANNEL_0]);
		}
		if (errCode == BC_ERR_NOERROR)
		{
			errCode = BC_TX_GetProfileCurrGain(e_SYS_TX2, rfeProfModeSelMapper(profList[profileId]),
					&pDrvState->tef82xxDrvState.txCurrGain[rfeProfModeSelMapper(profList[profileId])][RFE_TX_CHANNEL_1]);
		}
		if (errCode == BC_ERR_NOERROR)
		{
			errCode = BC_TX_GetProfileCurrGain(e_SYS_TX3, rfeProfModeSelMapper(profList[profileId]),
					&pDrvState->tef82xxDrvState.txCurrGain[rfeProfModeSelMapper(profList[profileId])][RFE_TX_CHANNEL_2]);
		}
		pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[currentChirpSequenceIndexParam].firstCalib = FALSE;
	}
	else
	{
		errCode = BC_TX_AdjustTXRFCurrentGain(e_SYS_TX1, rfeProfModeSelMapper(profList[profileId]),
			&pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[currentChirpSequenceIndexParam].txErr[RFE_TX_CHANNEL_0],
			PERCNT_CUR_GAIN_ADJ, PERCNT_BIAS_CUR_GAIN_ADJ, storeInProfile,
			&pDrvState->tef82xxDrvState.txCurrGain[profList[profileId]][RFE_TX_CHANNEL_0]);
		if (errCode == BC_ERR_NOERROR)
		{
			errCode = BC_TX_AdjustTXRFCurrentGain(e_SYS_TX2, rfeProfModeSelMapper(profList[profileId]),
				&pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[currentChirpSequenceIndexParam].txErr[RFE_TX_CHANNEL_1],
				PERCNT_CUR_GAIN_ADJ, PERCNT_BIAS_CUR_GAIN_ADJ, storeInProfile,
				&pDrvState->tef82xxDrvState.txCurrGain[profList[profileId]][RFE_TX_CHANNEL_1]);
		}
		if (errCode == BC_ERR_NOERROR)
		{
			errCode = BC_TX_AdjustTXRFCurrentGain(e_SYS_TX3, rfeProfModeSelMapper(profList[profileId]),
				&pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[currentChirpSequenceIndexParam].txErr[RFE_TX_CHANNEL_2],
				PERCNT_CUR_GAIN_ADJ, PERCNT_BIAS_CUR_GAIN_ADJ, storeInProfile,
				&pDrvState->tef82xxDrvState.txCurrGain[profList[profileId]][RFE_TX_CHANNEL_2]);
		}
	}
	return errCode;
}

static void MultiProfileTxCalibration(uint8_t currentChirpSequenceIndexParam, rfeDriverPersistentMem_t * pDrvState, rfe_error_t* rfe___error___pointer)
{
    BC_ERRCODE   errCode = BC_ERR_NOERROR;
    float32_t profilePowerLevels[RFE_MAX_CHIRP_PROFILES] = { TEF82XX_DISABLED_TX, TEF82XX_DISABLED_TX, TEF82XX_DISABLED_TX, TEF82XX_DISABLED_TX,
                                                            TEF82XX_DISABLED_TX, TEF82XX_DISABLED_TX, TEF82XX_DISABLED_TX, TEF82XX_DISABLED_TX};
    uint8_t nrChirpProfiles = 0U;
    uint8_t profileId, txId;
    float32_t maxPower;
    float32_t currentPowerLevel;
    SYS_StoreInProfile_t storeInProfile;
    BOOL performFullCal = (BOOL)TRUE;
    float32_t levelHighDelta = 0.0f;
    float32_t levelLowDelta = 0.0f;
    uint8_t* profList = NULL;

    profList = &pDrvState->tef82xxDrvState.radarCycleParams.
            chirpSequences[currentChirpSequenceIndexParam].profList[RFE_LIST_PROFILE_0];
    nrChirpProfiles = pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[currentChirpSequenceIndexParam].nrSequenceChirpProfiles;

    storeInProfile = ConfigStoreInProfile((SYS_ProfID_e)pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[currentChirpSequenceIndexParam].profModeSel,
				profList, nrChirpProfiles);

    if (*rfe___error___pointer == rfe_error_none_e)
    {
		levelHighDelta = ((float32_t) rfeCfg_sequence_getTxCalibrationThresholdHigh(pDrvState->rfeConfig,
			(rfe_chirpSequenceIndex_t) currentChirpSequenceIndexParam, rfe___error___pointer)) * TX_CALIB_THRESHOLD_ADJ;
    }
    if (*rfe___error___pointer == rfe_error_none_e)
    {
		levelLowDelta = ((float32_t) rfeCfg_sequence_getTxCalibrationThresholdLow(pDrvState->rfeConfig,
			(rfe_chirpSequenceIndex_t) currentChirpSequenceIndexParam, rfe___error___pointer)) * TX_CALIB_THRESHOLD_ADJ;
    }
    if (*rfe___error___pointer == rfe_error_none_e)
    {
		// Load into profilePowerLevels TX power level for each profile
		for (profileId = 0U; profileId < nrChirpProfiles; profileId++)
		{
			maxPower = -10.0f;

			for(txId = 0; txId < (uint8_t)RFE_MAX_TX_CHANNELS; txId++)
			{
				if (pDrvState->tef82xxDrvState.txChannelPower[profList[profileId]][txId] > maxPower)
				{
					maxPower = pDrvState->tef82xxDrvState.txChannelPower[profList[profileId]][txId];
				}
			}
			profilePowerLevels[profList[profileId]] = maxPower;
		}

		for (profileId = 0U; profileId < nrChirpProfiles; profileId++)
		{
			if (profilePowerLevels[profList[profileId]] >= 0.0f) // Check if the profileId has already been calibrated
			{
				currentPowerLevel = profilePowerLevels[profList[profileId]];

				if ((errCode == BC_ERR_NOERROR) && ((uint8_t)pDrvState->frontendMode >= (uint8_t)RFE_CASCADING_FOLLOWER))
				{
					errCode = BC_CAFC_LoadProfile(rfeProfModeSelMapper(profList[profileId]));
				}
				if (errCode == BC_ERR_NOERROR)
				{
					if(performFullCal == TRUE)
					{
						// Full TX calibration is performed just for the 1st iteration, with calibration values stored in all profiles
						errCode = TxCalibration(&storeInProfile, rfeProfModeSelMapper(profList[profileId]),
								performFullCal, pDrvState->tef82xxDrvState.enableReduceTransmisionForVGACalib);

						if (errCode == BC_ERR_NOERROR)
						{
							if (pDrvState->tef82xxDrvState.enableReduceTransmisionForVGACalib != FALSE)
							{
								errCode = PerformTxCalibWithoutRadiation(currentChirpSequenceIndexParam, pDrvState,
										levelHighDelta, levelLowDelta, &storeInProfile, profileId, profList);
							}
							else
							{
								performFullCal = FALSE;
							}

							// Clear all profiles calibrated with same TX Power as 1st profile
							TxPowerBasedStoreInProfile(&storeInProfile, profilePowerLevels, currentPowerLevel, nrChirpProfiles, profList);
						}
					}
					else
					{
						// Reset the storeInProfile structure to all zeros
						(void)memset(&storeInProfile, 0, sizeof(storeInProfile));
						// Configure profiles for calibration
						TxPowerBasedStoreInProfile(&storeInProfile, profilePowerLevels, currentPowerLevel, nrChirpProfiles, profList);

						errCode = TxCalibration(&storeInProfile, rfeProfModeSelMapper(profList[profileId]),
								performFullCal, pDrvState->tef82xxDrvState.enableReduceTransmisionForVGACalib);
					}
				}
			}
		}

		if (performFullCal == TRUE)
		{
			/* performFullCal TRUE at the end of calibration indicates no TX has been calibrated
			 * thus we can skip for TX Integrity Check for this frontend
			 */
			pDrvState->tef82xxDrvState.enableTxIntegrityCheck = FALSE;
		}
		else
		{
			pDrvState->tef82xxDrvState.enableTxIntegrityCheck = TRUE;
		}
		if(errCode != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}
    }
}

static void SetConfigFastReturn(uint8_t currentChirpSequenceIndexParam, rfeDriverPersistentMem_t * pDrvState, rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE   errCode = BC_ERR_NOERROR;
	BOOL fastReturnEnable = (BOOL)FALSE;

	if (*rfe___error___pointer == rfe_error_none_e)
	{
		switch(pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[currentChirpSequenceIndexParam].vcoSel)
		{
			case RFE_CHIRP_PLL_VCO_BANDWIDTH_1GHZ:
			{
				if((pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[currentChirpSequenceIndexParam].cafcLoopBandwidth >= VCO_1G_MIN_PLL_LOOP_BW) &&
						(pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[currentChirpSequenceIndexParam].cafcLoopBandwidth <= VCO_1G_MAX_PLL_LOOP_BW))
				{
					fastReturnEnable = (BOOL)TRUE;
				}
				break;
			}
			case RFE_CHIRP_PLL_VCO_BANDWIDTH_2GHZ:
			{
				if((pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[currentChirpSequenceIndexParam].cafcLoopBandwidth >= VCO_2G_MIN_PLL_LOOP_BW) &&
						(pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[currentChirpSequenceIndexParam].cafcLoopBandwidth <= VCO_2G_MAX_PLL_LOOP_BW))
				{
					fastReturnEnable = (BOOL)TRUE;
				}
				break;
			}
			case RFE_CHIRP_PLL_VCO_BANDWIDTH_4GHZ:
			{
				if((pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[currentChirpSequenceIndexParam].cafcLoopBandwidth >= VCO_4G_MIN_PLL_LOOP_BW) &&
						(pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[currentChirpSequenceIndexParam].cafcLoopBandwidth <= VCO_4G_MAX_PLL_LOOP_BW))
				{
					fastReturnEnable = (BOOL)TRUE;
				}
				break;
			}
			default:
			{
				errCode = BC_ERR_INPUTOUTOFRANGE;
				break;
			}
		}
		if(errCode == BC_ERR_NOERROR)
		{
			errCode = BC_CAFC_ConfigFastReturn(fastReturnEnable,
							fastReturnEnable);
		}
		if(errCode != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}
	}
}

static void CalibrationStandaloneStage1(uint8_t chirpSequenceIndex, rfeDriverPersistentMem_t * pDrvState, rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE   errCode = BC_ERR_NOERROR;
	float32_t tempKelvinChirp = 0.0f;
	float32_t kvcoAverage = 0.0f;
	float32_t cafcCalCheckTimeOutUs = (float32_t)GR_CAFC_CALIBRATION_TIMEOUT;
	uint32_t rxCalCheckTimeOutUs = GR_RX_LOX3_CALIBRATION_TIMEOUT;
	uint8_t nrChirpProfiles = 0;
	SYS_StoreInProfile_t storeInProfile = {0};
	uint8_t profModeSel = 0;
	uint8_t* profList = NULL;

	if (*rfe___error___pointer == rfe_error_none_e)
	{
		nrChirpProfiles = pDrvState->tef82xxDrvState.radarCycleParams.
				chirpSequences[chirpSequenceIndex].nrSequenceChirpProfiles;
		profModeSel = pDrvState->tef82xxDrvState.radarCycleParams.
				chirpSequences[chirpSequenceIndex].profModeSel;
		profList = &pDrvState->tef82xxDrvState.radarCycleParams.
				chirpSequences[chirpSequenceIndex].profList[RFE_LIST_PROFILE_0];

		storeInProfile = ConfigStoreInProfile(rfeProfModeSelMapper(profModeSel), profList, nrChirpProfiles);

		errCode = BC_MCLK_AutoCalib((BOOL)FALSE);
		if(errCode == BC_ERR_NOERROR)
		{
			errCode = rfeSwCfgSetDynPowMode(e_DPM_FOR_CHIRP_CALIBRATION);
		}
		if (errCode == BC_ERR_NOERROR)
		{
			errCode = BC_SC_KeepMiddleFrequency((BOOL)TRUE);
		}
		// Work-around done for proper VCO selection when using multiple sequences with different VCO configured
		if (errCode == BC_ERR_NOERROR)
		{
			errCode = BC_CAFC_ConfigVCOProfile(
					rfeProfModeSelMapper(pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[chirpSequenceIndex].meanCenterFreqProf),
					pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[chirpSequenceIndex].meanCenterFreqProfFreq.VCOSel,
					pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[chirpSequenceIndex].meanCenterFreqProfFreq.PLLLPFSel,
					TEF82XX_SKIP_CAFC_IVCO_FINE,
					TEF82XX_SKIP_CAFC_SUBBAND);
		}
		if (errCode == BC_ERR_NOERROR)
		{
			errCode = BC_CAFC_ConfigLoopFilter(
					pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[chirpSequenceIndex].meanCenterFreqProfFreq.PLLLPFSel,
					rfeCafcPllLPFLUTSelFromVCOMapper(pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[chirpSequenceIndex].meanCenterFreqProfFreq.VCOSel),
					pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[chirpSequenceIndex].cafcLoopBandwidth,
					pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[chirpSequenceIndex].effFc,
					pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[chirpSequenceIndex].DownChirp);
		}
		// Work-around end
		if (errCode == BC_ERR_NOERROR)
		{
			errCode = BC_CAFC_CalibAAFCInjDAC((BOOL)TRUE, (BOOL)TRUE,
					&pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[chirpSequenceIndex].meanCenterFreqProfFreq,
					&pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[chirpSequenceIndex].meanCenterFreqProfTiming,
					rfeProfModeSelMapper(pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[chirpSequenceIndex].meanCenterFreqProf),
					&storeInProfile,
					cafcCalCheckTimeOutUs, tempKelvinChirp, &kvcoAverage);
		}
		if (errCode == BC_ERR_NOERROR)
		{
			errCode = BC_CAFC_UpdateLoopFilterCP(
					pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[chirpSequenceIndex].meanCenterFreqProfFreq.PLLLPFSel,
					rfeCafcPllLPFLUTSelMApper((uint8_t)pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[chirpSequenceIndex].meanCenterFreqProfFreq.VCOSel),
					pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[chirpSequenceIndex].cafcLoopBandwidth,
					kvcoAverage, pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[chirpSequenceIndex].meanCenterFreqProfFreq.DownChirp);
		}
		if (errCode == BC_ERR_NOERROR)
		{
			errCode = rfeSwCfgSetDynPowMode(e_DPM_FOR_LO_CALIBRATION);
		}
		if (errCode == BC_ERR_NOERROR)
		{
			errCode = BC_LOI_StartLOGainCalib((BOOL)TRUE, GR_LOI_B2_CALIBRATION_TIMEOUT);
		}
		if (errCode == BC_ERR_NOERROR)
		{
			errCode = BC_RX_CalibrateLOx3Gain(e_SYS_RXMC, (BOOL)TRUE, rxCalCheckTimeOutUs);
		}
		if(errCode != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}
	}
}

static void CalibrationStandaloneStage2(rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE   errCode = BC_ERR_NOERROR;

	if (*rfe___error___pointer == rfe_error_none_e)
	{
		errCode = BC_SC_KeepMiddleFrequency((BOOL)FALSE);
		if (errCode == BC_ERR_NOERROR)
		{
			errCode = BC_ISM_ResetISMErr((BOOL)FALSE, (BOOL)FALSE, (BOOL)FALSE, (BOOL)TRUE);
		}
		if (errCode == BC_ERR_NOERROR)
		{
			errCode = rfeSwCfgSetDynPowMode(e_DPM_ACTIVE);
		}
		if(errCode != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}
	}
}

static void CalibrationStandalone(uint8_t currentChirpSequenceIndexParam, rfe_error_t* rfe___error___pointer)
{
	uint8_t chirpSequenceIndex = 0;
	rfeDriverPersistentMem_t * pDrvState = RfeDrvStateGet();

	chirpSequenceIndex = (uint8_t)rfeCfg_radarCycle_getChirpSequence(pDrvState->rfeConfig,
			currentChirpSequenceIndexParam, rfe___error___pointer);

	SetConfigFastReturn(chirpSequenceIndex, pDrvState, rfe___error___pointer);
	CalibrationStandaloneStage1(chirpSequenceIndex, pDrvState, rfe___error___pointer);
	MultiProfileTxCalibration(chirpSequenceIndex, pDrvState, rfe___error___pointer);
	CalibrationStandaloneStage2(rfe___error___pointer);
}

/******************************************************************************
 *                              PUBLIC FUNCTIONS
 *****************************************************************************/



static void LeaderCalibrationStart(uint8_t currentChirpSequenceIndexParam, rfeDriverPersistentMem_t * pDrvState, rfe_error_t* rfe___error___pointer)
{
    BC_ERRCODE   errCode = BC_ERR_NOERROR;
    float32_t tempKelvinChirp = 0.0f;
    float32_t kvcoAverage = 0.0f;
    float32_t cafcCalCheckTimeOutUs = (float32_t)GR_CAFC_CALIBRATION_TIMEOUT;
    uint32_t rxCalCheckTimeOutUs = GR_RX_LOX3_CALIBRATION_TIMEOUT;
    uint8_t nrChirpProfiles = 0U;
    SYS_StoreInProfile_t storeInProfile = {0};
    uint8_t profModeSel = 0;
    uint8_t* profList = NULL;

	nrChirpProfiles = pDrvState->tef82xxDrvState.radarCycleParams.
			chirpSequences[currentChirpSequenceIndexParam].nrSequenceChirpProfiles;
	profModeSel = pDrvState->tef82xxDrvState.radarCycleParams.
			chirpSequences[currentChirpSequenceIndexParam].profModeSel;
	profList = &pDrvState->tef82xxDrvState.radarCycleParams.
			chirpSequences[currentChirpSequenceIndexParam].profList[RFE_LIST_PROFILE_0];

	storeInProfile = ConfigStoreInProfile((SYS_ProfID_e)profModeSel, profList, nrChirpProfiles);

	rfeSwUtils_SelectFe((uint8_t)rfeFrontEndId_0);

	errCode = BC_MCLK_AutoCalib((BOOL)FALSE);

	if(errCode == BC_ERR_NOERROR)
	{
		errCode = rfeSwCfgSetDynPowMode(e_DPM_FOR_CHIRP_CALIBRATION);
	}
	if (errCode == BC_ERR_NOERROR)
	{
		errCode = BC_SC_KeepMiddleFrequency((BOOL)TRUE);
	}

	// Work-around done for proper VCO selection when using multiple sequences with different VCO configured
	if (errCode == BC_ERR_NOERROR)
	{
		errCode = BC_CAFC_ConfigVCOProfile(
				rfeProfModeSelMapper(pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[currentChirpSequenceIndexParam].meanCenterFreqProf),
				pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[currentChirpSequenceIndexParam].meanCenterFreqProfFreq.VCOSel,
				pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[currentChirpSequenceIndexParam].meanCenterFreqProfFreq.PLLLPFSel,
				TEF82XX_SKIP_CAFC_IVCO_FINE,
				TEF82XX_SKIP_CAFC_SUBBAND);
	}
	if (errCode == BC_ERR_NOERROR)
	{
		errCode = BC_CAFC_ConfigLoopFilter(
				pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[currentChirpSequenceIndexParam].meanCenterFreqProfFreq.PLLLPFSel,
				rfeCafcPllLPFLUTSelFromVCOMapper(pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[currentChirpSequenceIndexParam].meanCenterFreqProfFreq.VCOSel),
				pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[currentChirpSequenceIndexParam].cafcLoopBandwidth,
				pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[currentChirpSequenceIndexParam].effFc,
				pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[currentChirpSequenceIndexParam].DownChirp);
	}
	// Work-around end
	if (errCode == BC_ERR_NOERROR)
	{
		errCode = BC_CAFC_CalibAAFCInjDAC((BOOL)TRUE, (BOOL)TRUE,
				&pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[currentChirpSequenceIndexParam].meanCenterFreqProfFreq,
				&pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[currentChirpSequenceIndexParam].meanCenterFreqProfTiming,
				rfeProfModeSelMapper(pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[currentChirpSequenceIndexParam].meanCenterFreqProf),
				&storeInProfile,
				cafcCalCheckTimeOutUs, tempKelvinChirp, &kvcoAverage);
	}
	if (errCode == BC_ERR_NOERROR)
	{
		errCode = BC_CAFC_UpdateLoopFilterCP(
				pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[currentChirpSequenceIndexParam].meanCenterFreqProfFreq.PLLLPFSel,
				rfeCafcPllLPFLUTSelMApper((uint8_t)pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[currentChirpSequenceIndexParam].meanCenterFreqProfFreq.VCOSel),
				pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[currentChirpSequenceIndexParam].cafcLoopBandwidth,
				kvcoAverage, pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[currentChirpSequenceIndexParam].meanCenterFreqProfFreq.DownChirp);
	}
	if (errCode == BC_ERR_NOERROR)
	{
		errCode = rfeSwCfgSetDynPowMode(e_DPM_FOR_LO_CALIBRATION);
	}
	if (errCode == BC_ERR_NOERROR)
	{
		errCode = BC_LOI_StartLOGainCalib((BOOL)TRUE, GR_LOI_B2_CALIBRATION_TIMEOUT);
	}
	if (errCode == BC_ERR_NOERROR)
	{
		errCode = BC_RX_CalibrateLOx3Gain(e_SYS_RXMC, (BOOL)TRUE, rxCalCheckTimeOutUs);
	}
	if(errCode != BC_ERR_NOERROR)
	{
		*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
	}
}

static void FollowerCalibrationStartStage1(rfeDriverPersistentMem_t * pDrvState,
		rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE   errCode = BC_ERR_NOERROR;
	uint32_t rxCalCheckTimeOutUs = GR_RX_LOX3_CALIBRATION_TIMEOUT;

	if (*rfe___error___pointer == rfe_error_none_e)
	{
		rfeSwUtils_SelectFe(pDrvState->frontendId);

		errCode = BC_MCLK_AutoCalib((BOOL)FALSE);
		if (errCode == BC_ERR_NOERROR)
		{
			errCode = rfeSwCfgSetDynPowMode(e_DPM_FOR_LO_CALIBRATION);
		}
		if (errCode == BC_ERR_NOERROR)
		{
			errCode = BC_LOI_StartLOGainCalib((BOOL)TRUE, GR_LOI_B2_CALIBRATION_TIMEOUT);
		}
		if (errCode == BC_ERR_NOERROR)
		{
			errCode = BC_RX_CalibrateLOx3Gain(e_SYS_RXMC, (BOOL)TRUE, rxCalCheckTimeOutUs);
		}
		if(errCode != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}
	}
}

static void FollowerCalibrationStartStage2(rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE   errCode = BC_ERR_NOERROR;

	if (*rfe___error___pointer == rfe_error_none_e)
	{
		errCode = BC_ISM_ResetISMErr((BOOL)FALSE, (BOOL)FALSE, (BOOL)FALSE, (BOOL)TRUE);
		if (errCode == BC_ERR_NOERROR)
		{
			errCode = rfeSwCfgSetDynPowMode(e_DPM_ACTIVE);
		}
		if(errCode != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}
	}
}

static void FollowerCalibrationStart(uint8_t currentChirpSequenceIndexParam, rfeDriverPersistentMem_t * pDrvState,
		rfe_error_t* rfe___error___pointer)
{
    	FollowerCalibrationStartStage1(pDrvState, rfe___error___pointer);
		MultiProfileTxCalibration(currentChirpSequenceIndexParam, pDrvState, rfe___error___pointer);
		FollowerCalibrationStartStage2(rfe___error___pointer);
}

static void LeaderCalibrationEndStage1(rfe_error_t* rfe___error___pointer)
{
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		rfeSwUtils_SelectFe((uint8_t)rfeFrontEndId_0);
	}
}

static void LeaderCalibrationEndStage2(rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE   errCode = BC_ERR_NOERROR;

	if (*rfe___error___pointer == rfe_error_none_e)
	{
		errCode = BC_SC_KeepMiddleFrequency((BOOL)FALSE);
		if (errCode == BC_ERR_NOERROR)
		{
			errCode = BC_ISM_ResetISMErr((BOOL)FALSE, (BOOL)FALSE, (BOOL)FALSE, (BOOL)TRUE);
		}
		if (errCode == BC_ERR_NOERROR)
		{
			errCode = rfeSwCfgSetDynPowMode(e_DPM_ACTIVE);
		}
		if(errCode != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}
	}
}

static void LeaderCalibrationEnd(uint8_t currentChirpSequenceIndexParam, rfeDriverPersistentMem_t * pDrvState,
		rfe_error_t* rfe___error___pointer)
{
    LeaderCalibrationEndStage1(rfe___error___pointer);
    MultiProfileTxCalibration(currentChirpSequenceIndexParam, pDrvState, rfe___error___pointer);
    LeaderCalibrationEndStage2(rfe___error___pointer);
}

static void CalibrationCascaded(uint8_t currentChirpSequenceIndexParam, rfe_error_t* rfe___error___pointer)
{
    rfeDriverPersistentMem_t * pDrvState = NULL;
    uint8_t fe_idx = 0;
    uint8_t chirpSequenceIndex = 0;

    if (*rfe___error___pointer == rfe_error_none_e)
    {
        // Start Leader calibration
        // Set Leader device
    	rfeSwUtils_SelectFe((uint8_t)rfeFrontEndId_0);
        pDrvState = RfeDrvStateGet();
        chirpSequenceIndex = (uint8_t)rfeCfg_radarCycle_getChirpSequence(pDrvState->rfeConfig, currentChirpSequenceIndexParam, rfe___error___pointer);
    }
    if (*rfe___error___pointer == rfe_error_none_e)
	{
    	SetConfigFastReturn(chirpSequenceIndex, pDrvState, rfe___error___pointer);
	}
    if (*rfe___error___pointer == rfe_error_none_e)
	{
    	LeaderCalibrationStart(chirpSequenceIndex, pDrvState, rfe___error___pointer);
	}
    if (*rfe___error___pointer == rfe_error_none_e)
    {
        // Start Follower calibration
        for(fe_idx = (uint8_t)rfeFrontEndId_1; fe_idx < RfeDrvStateNoFrontendsGet(); ++fe_idx)
        {
            // Set Follower device
        	rfeSwUtils_SelectFe(fe_idx);
            pDrvState = RfeDrvStateGet();
            chirpSequenceIndex = (uint8_t)rfeCfg_radarCycle_getChirpSequence(pDrvState->rfeConfig, currentChirpSequenceIndexParam, rfe___error___pointer);
            if (*rfe___error___pointer != rfe_error_none_e)
            {
            	break;
            }
            SetConfigFastReturn(chirpSequenceIndex, pDrvState, rfe___error___pointer);
            FollowerCalibrationStart(chirpSequenceIndex, pDrvState, rfe___error___pointer);
            if (*rfe___error___pointer != rfe_error_none_e)
            {
                break;
            }
        }
    }
    if (*rfe___error___pointer == rfe_error_none_e)
    {
        // End Leader calibration
        // Set Leader device
    	rfeSwUtils_SelectFe((uint8_t)rfeFrontEndId_0);
        pDrvState = RfeDrvStateGet();
        chirpSequenceIndex = (uint8_t)rfeCfg_radarCycle_getChirpSequence(pDrvState->rfeConfig, currentChirpSequenceIndexParam,
                            		rfe___error___pointer);
    }
    if (*rfe___error___pointer == rfe_error_none_e)
	{
    	LeaderCalibrationEnd(chirpSequenceIndex, pDrvState, rfe___error___pointer);
	}
}

static BC_ERRCODE DisableDynamicPowerControl(uint8_t calibration_attempts, R2M00_DynamicPowerControlEnableUnion_t *dynPowContrEnable)
{
	BC_ERRCODE errCode = BC_ERR_NOERROR;
	uint16_t ADC_RESET_CONTROL = 0x4c;
	uint32_t dpce_disable_adcbg_pd = 0;

	if(calibration_attempts == 0U)
	{
		errCode = BC_SPI_Read(e_SYS_CC, R2M00_DYNAMIC_POWER_CONTROL_ENABLE_U16,	&dynPowContrEnable->val_u32);
		dpce_disable_adcbg_pd &= DPCE_BITS_OFF;
	}
	if(errCode == BC_ERR_NOERROR)
	{
		errCode = BC_SPI_Read(e_SYS_CC, R2M00_DYNAMIC_POWER_CONTROL_ENABLE_U16,	&dynPowContrEnable->val_u32);
	}
	// Disable dynamic power control of ADC and ADC BG Calibration
	if(errCode == BC_ERR_NOERROR)
	{
		errCode = BC_SPI_Write(e_SYS_CC, R2M00_DYNAMIC_POWER_CONTROL_ENABLE_U16, dpce_disable_adcbg_pd);
	}
	// Reset the digital calibration logic
	if(errCode != BC_ERR_NOERROR)
	{
		errCode = BC_SPI_Write(e_SYS_ADCMC, ADC_RESET_CONTROL, RESET_DIGITAL_CAL_LOGIC);
	}
	if(errCode != BC_ERR_NOERROR)
	{
		errCode = BC_SPI_Write(e_SYS_ADCMC, ADC_RESET_CONTROL, RELEASE_RESET_DIGITAL_CAL_LOGIC);
	}
	return errCode;
}

static BC_ERRCODE AdcRestartCalibration(BC_ERRCODE *errCodeAdc12, BC_ERRCODE *errCodeAdc34, uint8_t calibration_attempts,
		R2M00_DynamicPowerControlEnableUnion_t *dynPowContrEnable)
{
	BC_ERRCODE errCode;
	errCode = DisableDynamicPowerControl(calibration_attempts, dynPowContrEnable);
	if(errCode == BC_ERR_NOERROR)
	{
		// Manually restart the calibration
		errCode = BC_SPI_Write(e_SYS_ADCMC, R2M07_CALIBRATION_START_U16, START_FULL_ADC_CAL);
	}

	if(errCode == BC_ERR_NOERROR)
	{
		// Make sure at least 3.4ms is between the calibration start and the check for busy.
		RfeHwDelayUs(3400);
		// Check the calibration results of both ADC modules.
		*errCodeAdc12 = BC_ADC_CheckCalResult(e_SYS_ADC12);
		*errCodeAdc34 = BC_ADC_CheckCalResult(e_SYS_ADC34);
		if(!((*errCodeAdc12 == BC_ERR_ADC_CALIBRATIONTIMEOUT) || (*errCodeAdc34 == BC_ERR_ADC_CALIBRATIONTIMEOUT)))
		{
			errCode = BC_SPI_Write(e_SYS_CC, R2M00_DYNAMIC_POWER_CONTROL_ENABLE_U16, dynPowContrEnable->val_u32);
		}
	}
	return errCode;
}

static BC_ERRCODE AdcCalibrationBusyCheckAndRecovery(bool *calibrationTimeout)
{
	// Make sure to wait at least 600us after the chirp sequence ends to perform this check.
	BC_ERRCODE errCode;
	BC_ERRCODE errCodeAdc12 = BC_ERR_NOERROR;
	BC_ERRCODE errCodeAdc34 = BC_ERR_NOERROR;
	R2M00_DynamicPowerControlEnableUnion_t dynPowContrEnable;
	uint8_t calibration_attempts = 0;

	// Check the calibration results of both ADC modules.
	errCodeAdc12 = BC_ADC_CheckCalResult(e_SYS_ADC12);
	errCodeAdc34 = BC_ADC_CheckCalResult(e_SYS_ADC34);

	// Disable ADC Background calibration
	errCode = AdcBkgrdCalibEnable((BOOL)FALSE);
    if((errCodeAdc12 == BC_ERR_ADC_CALIBRATIONTIMEOUT) || (errCodeAdc34 == BC_ERR_ADC_CALIBRATIONTIMEOUT))
    {
        *calibrationTimeout = true;
        // In case of a time-out, start the recovery method.
		while(((errCodeAdc12 == BC_ERR_ADC_CALIBRATIONTIMEOUT) || (errCodeAdc34 == BC_ERR_ADC_CALIBRATIONTIMEOUT)) &&
				(calibration_attempts < (uint8_t)CALIBRATION_TIMEOUT_RETRIES) )
		{
			if(errCode != BC_ERR_NOERROR)
			{
				break;
			}
			errCode = AdcRestartCalibration(&errCodeAdc12, &errCodeAdc34, calibration_attempts,	&dynPowContrEnable);
			calibration_attempts++;
		}
#ifdef RFE_DEBUG
		if((errCodeAdc12 == BC_ERR_ADC_CALIBRATIONTIMEOUT) || (errCodeAdc34 == BC_ERR_ADC_CALIBRATIONTIMEOUT) ||
				(calibration_attempts == (uint8_t)CALIBRATION_TIMEOUT_RETRIES))
		{
			RfeDbgPrintMsg("FE %d - Recovery calibration error \n", RfeDrvStateFrontendIdGet());
		}
#endif
		if((errCode == BC_ERR_NOERROR) && ((errCodeAdc12 == BC_ERR_ADC_CALIBRATIONTIMEOUT) || (errCodeAdc34 == (uint8_t)BC_ERR_ADC_CALIBRATIONTIMEOUT)))
		{
			errCode = BC_ERR_ADC_CALIBRATIONTIMEOUT;
		}
    }
	return errCode;
}
/******************************************************************************
 *                              PUBLIC FUNCTIONS
 *****************************************************************************/

void rfeSwCalibTef82xxCalibration(uint8_t currentChirpSequenceIndexPar, rfe_error_t* rfe___error___pointer)
{
    if (*rfe___error___pointer == rfe_error_none_e)
    {
    	if (RfeDrvStateConfigurationGet() == rfeFrontEnd_Single_e)
    	{
    		// single
    		CalibrationStandalone(currentChirpSequenceIndexPar, rfe___error___pointer);
    	}
    	else
    	{
    		// cascaded
    		CalibrationCascaded(currentChirpSequenceIndexPar, rfe___error___pointer);
    	}
    }
}

BC_ERRCODE AdcBkgrdCalibEnable(BOOL flag)
{
	BC_ERRCODE   errCode = BC_ERR_NOERROR;
	ADC_BackGroundCal_t bgCalParam;

	bgCalParam.AutoCalibrateAtPON = (BOOL)TRUE;
	bgCalParam.AutoSyncSequencer = (BOOL)TRUE;
	bgCalParam.EnCalibrateLSBWeights = (BOOL)TRUE;
	bgCalParam.EnContinuousBGCalibration = (BOOL)TRUE;
	bgCalParam.EnInterleavedCalibration = (BOOL)TRUE;
	bgCalParam.PowerSaveBGCalibrationWeights = 1U;

#ifdef RFE_DEBUG
	if (gRfeDebugLevel <= e_rfe_debug_level_radar_cycle)
	{
		RfeDbgPrintMsg("---->AdcBkgrdCalibEnable(%d)\n", flag);
	}
#endif
	errCode = BC_ADC_ConfigBackgroundCal(e_SYS_ADC12, flag, &bgCalParam);
	if(errCode == BC_ERR_NOERROR)
	{
		errCode = BC_ADC_ConfigBackgroundCal(e_SYS_ADC34, flag, &bgCalParam);
	}

	return errCode;
}

bool CheckAdcCalibration(rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE errCode = BC_ERR_NOERROR;
    bool recovery = false;
	uint8_t feIdx;

#ifdef RFE_DEBUG
	if (gRfeDebugLevel <= e_rfe_debug_level_radar_cycle)
	{
		RfeDbgPrintMsg("---->CheckAdcCalibration: func start\n");
	}
#endif
	rfeSwUtils_SelectFe((uint8_t)rfeFrontEndId_0);
	errCode = AdcCalibrationBusyCheckAndRecovery(&recovery);
	if (RfeDrvStateConfigurationGet() == rfeFrontEnd_Cascaded_e)
	{
		for(feIdx = 1; feIdx < RfeDrvStateNoFrontendsGet(); feIdx++)
		{
			if (errCode == BC_ERR_NOERROR)
			{
				rfeSwUtils_SelectFe(feIdx);
				errCode = AdcCalibrationBusyCheckAndRecovery(&recovery);
			}
		}
	}
	if (errCode  != BC_ERR_NOERROR)
	{

		*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
	}
    return recovery;
}
