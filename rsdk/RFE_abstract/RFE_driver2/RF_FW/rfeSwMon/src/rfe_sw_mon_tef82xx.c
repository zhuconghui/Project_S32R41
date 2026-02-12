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

/******************************************************************************
 *                              INCLUDES
 *****************************************************************************/
#include "rfe_sw_mon_tef82xx.h"
#include "rfe_blob_access.h"
#include "rfe_sw_cfg_to_tef82xx_map.h"
#include "rfeSwMainFsm_internal.h"
#include "rfe_error.h"
#include "bc_sys.h"
#include "bc_spi.h"
#include "bc_ism.h"
#include "bc_cc.h"
#include "reg_es2_ism.h"
#include "rfeDspMath.h"
#include "rfeSwUtils.h"
/*==================================================================================================
 *                                      DEFINES
==================================================================================================*/
#define RESET_COUNTER 		1
#define ALWAYS_ACTIVE		1
#define SAFETY_ONLY_ACTIVE	0
#define CLEAR_FLAG			1
#define NO_ACTION			0
/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
 *                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
 *                                      LOCAL VARIABLES
==================================================================================================*/
static rfe_monitorValues_t rfeMonitorValues;
/*==================================================================================================
 *                                      LOCAL FUNCTIONS PROTOTYPES
==================================================================================================*/
/**
 * \brief This function get rx staturation clipping count in frame
 *
 * \pre NIL
 *
 * \param in		 -
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter.
 *
 * \param [out]     adcClipping - pointer to output adc cliping .
 *
 * \return NIL
 *
 * \post
 * -
 * -
 *
 * \ingroup NIL
 */
static void rfeSwMon_getRxSaturationClipping(uint16_t* adcClipping, rfe_error_t* rfe___error___pointer);

/**
 * \brief This function get rx staturation clipping count in frame
 *
 * \pre NIL
 *
 * \param in		rxReset - which rx adc clipping counter will be reset
 * 							  rfe_rx1234Reset_e - all adc clipping counters will be reset
 * \param in		activeSaftyPeriodOnly - TRUE - Counter is active during safety monitoring period only
 * 											FALSE - Counter always active (for debug)
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter.
 *
 * \return NIL
 *
 * \post
 * -
 * -
 *
 * \ingroup NIL
 */
static void rfeSwMon_enableResetAdc1234ClippingCounter(rfe_rxClippingReset_t rxReset, BOOL activeSaftyPeriodOnly,
		rfe_error_t* rfe___error___pointer);

/**
 * \brief This function clear adc hard clipping flag
 *
 * \pre NIL
 *
 * \param in		adc1ClearFlg - TRUE - clear hard clipping flag
 * 							   	   FALSE - no action
 * \param in		adc2ClearFlg - TRUE - clear hard clipping flag
 * 							       FALSE - no action
 * \param in		adc3ClearFlg - TRUE - clear hard clipping flag
 * 							       FALSE - no action
 * \param in		adc4ClearFlg - TRUE - clear hard clipping flag
 * 							       FALSE - no action
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter.
 *
 * \return NIL
 *
 * \post
 * -
 * -
 *
 * \ingroup NIL
 */
static void rfeSwMon_clearAdcHardClippingFlag(BOOL adc1ClearFlg, BOOL adc2ClearFlg, BOOL adc3ClearFlg,
		BOOL adc4ClearFlg, rfe_error_t* rfe___error___pointer);

/**
 * \brief This function get adc hard clipping masked err flag
 *
 * \pre NIL
 *
 * \param in		 -
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter.
 *
 * \param [out]     adcFlag - pointer to output adc err flag .
 *
 * \return NIL
 *
 * \post
 * -
 * -
 *
 * \ingroup NIL
 */
static void rfeSwMon_getAdcHardClippingMaskedFlag(uint8_t* adcFlag, rfe_error_t* rfe___error___pointer);
/*==================================================================================================
 *                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
 *                                      LOCAL FUNCTIONS
==================================================================================================*/
static void rfeSwMon_getRxSaturationClipping(uint16_t* adcClipping, rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE   errCode = BC_ERR_NOERROR;
	R2M18_Adc12ClippingEventsThresholdCounterUnion_t adc12Clipping;
	R2M18_Adc34ClippingEventsThresholdCounterUnion_t adc34Clipping;

	adc12Clipping.val_u32 = 0;
	adc34Clipping.val_u32 = 0;

	if (*rfe___error___pointer == rfe_error_none_e)
	{
		if(adcClipping == NULL)
		{
			*rfe___error___pointer = rfe_error_invalidPointer_e;
		}
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		errCode = BC_SPI_Read(e_SYS_ISM, R2M18_ADC12_CLIPPING_EVENTS_THRESHOLD_COUNTER_U16, &adc12Clipping.val_u32);
		if(errCode == BC_ERR_NOERROR)
		{
			errCode = BC_SPI_Read(e_SYS_ISM, R2M18_ADC34_CLIPPING_EVENTS_THRESHOLD_COUNTER_U16, &adc34Clipping.val_u32);
		}
		if (errCode != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		adcClipping[rfe_rxIndex_1_e] = (uint16_t)adc12Clipping.bits_st.Adc1ClippingEventsThresholdCounter;
		adcClipping[rfe_rxIndex_2_e] = (uint16_t)adc12Clipping.bits_st.Adc2ClippingEventsThresholdCounter;
		adcClipping[rfe_rxIndex_3_e] = (uint16_t)adc34Clipping.bits_st.Adc3ClippingEventsThresholdCounter;
		adcClipping[rfe_rxIndex_4_e] = (uint16_t)adc34Clipping.bits_st.Adc4ClippingEventsThresholdCounter;
	}
}
/*==================================================================================================*/
static void rfeSwMon_enableResetAdc1234ClippingCounter(rfe_rxClippingReset_t rxReset, BOOL activeSaftyPeriodOnly,
		rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE   errCode = BC_ERR_NOERROR;
	R2M18_Adc1234ClippingEventsThresholdCounterResetUnion_t adc1234ClippingReset;

	adc1234ClippingReset.val_u32 = 0;
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		if((uint8_t) rxReset >= RFE_RX_CLIPPING_RESET)
		{
			*rfe___error___pointer = rfe_error_parameterOutOfRange_e;
		}
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		errCode = BC_SPI_Read(e_SYS_ISM, R2M18_ADC1234_CLIPPING_EVENTS_THRESHOLD_COUNTER_RESET_U16, &adc1234ClippingReset.val_u32);
		if(errCode == BC_ERR_NOERROR)
		{
			switch(rxReset)
			{
				case rfe_rx1Reset_e:
				{
					adc1234ClippingReset.bits_st.Adc1ClippingEventsThresholdCounterReset = RESET_COUNTER;
					break;
				}
				case rfe_rx2Reset_e:
				{
					adc1234ClippingReset.bits_st.Adc2ClippingEventsThresholdCounterReset = RESET_COUNTER;
					break;
				}
				case rfe_rx3Reset_e:
				{
					adc1234ClippingReset.bits_st.Adc3ClippingEventsThresholdCounterReset = RESET_COUNTER;
					break;
				}
				case rfe_rx4Reset_e:
				{
					adc1234ClippingReset.bits_st.Adc4ClippingEventsThresholdCounterReset = RESET_COUNTER;
					break;
				}
				case rfe_rx1234Reset_e:
				{
					adc1234ClippingReset.bits_st.EnableResetErrorBasedAllAdcCounterReset = RESET_COUNTER;
					break;
				}
				default:
				{
					*rfe___error___pointer = rfe_error_parameterOutOfRange_e;
					break;
				}
			}
			if(activeSaftyPeriodOnly == TRUE)
			{
				adc1234ClippingReset.bits_st.ClippingEventsThresholdCounterActivePeriod = SAFETY_ONLY_ACTIVE;
			}
			else
			{
				adc1234ClippingReset.bits_st.ClippingEventsThresholdCounterActivePeriod = ALWAYS_ACTIVE;
			}
			errCode = BC_SPI_Write(e_SYS_ISM, R2M18_ADC1234_CLIPPING_EVENTS_THRESHOLD_COUNTER_RESET_U16, adc1234ClippingReset.val_u32);
		}
		if (errCode != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}
	}
}
/*==================================================================================================*/
static void rfeSwMon_clearAdcHardClippingFlag(BOOL adc1ClearFlg, BOOL adc2ClearFlg, BOOL adc3ClearFlg,
		BOOL adc4ClearFlg, rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE   errCode = BC_ERR_NOERROR;
	SYS_ADCErrors_t adc12Err = {0};
	SYS_ADCErrors_t adc34Err = {0};

	adc12Err.ADCn0HardClippingErr = adc1ClearFlg;
	adc12Err.ADCn1HardClippingErr = adc2ClearFlg;
	adc34Err.ADCn0HardClippingErr = adc3ClearFlg;
	adc34Err.ADCn1HardClippingErr = adc4ClearFlg;

	if (*rfe___error___pointer == rfe_error_none_e)
	{
		errCode = BC_ISM_MaskRTMSetClrADCErr(e_ISM_ERR_OP_CLEAR_ERR, &adc12Err, &adc34Err);

		if (errCode != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}
	}
}
/*==================================================================================================*/
static void rfeSwMon_getAdcHardClippingMaskedFlag(uint8_t* adcFlag, rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE   errCode = BC_ERR_NOERROR;
	SYS_ADCErrors_t adc12Err = {0};
	SYS_ADCErrors_t adc34Err = {0};
	uint32_t pModuleErr = 0;

	if (*rfe___error___pointer == rfe_error_none_e)
	{
		if(adcFlag == NULL)
		{
			*rfe___error___pointer = rfe_error_invalidPointer_e;
		}
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		errCode = BC_ISM_GetADCErrStatus(e_ISM_GET_MASKED_ERR, &adc12Err, &adc34Err, &pModuleErr);
		if (errCode != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}
	}
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		adcFlag[0] = (uint8_t)adc12Err.ADCn0HardClippingErr;
		adcFlag[1] = (uint8_t)adc12Err.ADCn1HardClippingErr;
		adcFlag[2] = (uint8_t)adc34Err.ADCn0HardClippingErr;
		adcFlag[3] = (uint8_t)adc34Err.ADCn1HardClippingErr;
	}
}
/*==================================================================================================
 *                                      GLOBAL FUNCTIONS
==================================================================================================*/
/**
 * \brief This function performs temperature measurement of TX1,2,3 and Chirp modules
 *
 * \pre NIL
 *
 * \param in		outputValues -
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter.
 *
 * \return NIL
 *
 * \post
 * -
 * -
 *
 * \ingroup NIL
 */
void rfeSwMon_getTemperatureMeasurement( rfe_temperature_t *outputValues,  rfe_error_t* rfe___error___pointer )
{
    BC_ERRCODE errCode = BC_ERR_NOERROR;
    bool satFlag = FALSE;
    SYS_IPList_t appConfig;
    uint8_t fe = RfeDrvStateFrontendIdGet();
    float32_t kelvinTx1 = RFE_ENABLE_TEMPERATURE_MEASUREMENT;
    float32_t kelvinTx2 = RFE_ENABLE_TEMPERATURE_MEASUREMENT;
    float32_t kelvinTx3 = RFE_ENABLE_TEMPERATURE_MEASUREMENT;
    float32_t kelvinChirp = RFE_ENABLE_TEMPERATURE_MEASUREMENT;

    errCode = BC_SYS_ReadTempSensor(&kelvinTx1, &kelvinTx2, &kelvinTx3, &kelvinChirp);
    if (errCode == BC_ERR_NOERROR)
    {
    	errCode = BC_CC_SetMSDevice((PLF_SPITarget_e) fe);
    }
    if (errCode == BC_ERR_NOERROR)
    {
    	errCode = BC_CC_GetAppConfiguration(&appConfig, NULL);
    }
    if (errCode == BC_ERR_NOERROR)
    {
    	if(appConfig.TX1 == FALSE)
    	{
    		kelvinTx1 = RFE_ENABLE_TEMPERATURE_MEASUREMENT;
    	}
    	if(appConfig.TX2 == FALSE)
		{
			kelvinTx2 = RFE_ENABLE_TEMPERATURE_MEASUREMENT;
		}
    	if(appConfig.TX3 == FALSE)
		{
			kelvinTx3 = RFE_ENABLE_TEMPERATURE_MEASUREMENT;
		}
    	if(appConfig.CAFC == FALSE)
		{
    		kelvinChirp = RFE_ENABLE_TEMPERATURE_MEASUREMENT;
		}
        // Above function returns value in kelvin. But rfe_temperature_t is in degrees celsius stored in fixed point
        // SQ6 format. So convert before storing.
        outputValues[(uint8_t)rfe_temperatureSensorIndex_tx1_e] = rfeDspMath_floatToQ15( RFE_KELVIN_TO_CELSIUS(kelvinTx1), 6U,  &satFlag );
        outputValues[(uint8_t)rfe_temperatureSensorIndex_tx2_e] = rfeDspMath_floatToQ15( RFE_KELVIN_TO_CELSIUS(kelvinTx2), 6U,  &satFlag );
        outputValues[(uint8_t)rfe_temperatureSensorIndex_tx3_e] = rfeDspMath_floatToQ15( RFE_KELVIN_TO_CELSIUS(kelvinTx3), 6U,  &satFlag );
        outputValues[(uint8_t)rfe_temperatureSensorIndex_chirp_e] = rfeDspMath_floatToQ15( RFE_KELVIN_TO_CELSIUS(kelvinChirp), 6U,  &satFlag );
        (void)satFlag;
    }
	if (errCode != BC_ERR_NOERROR)
	{
		*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
	}

}

void rfeMon_performFEMonitoring(bool measureTemperature, uint8_t currentChirpSequenceIndexParam, rfe_error_t* rfe___error___pointer)
{
	rfeDriverPersistentMem_t *pDrvState = NULL;
	BC_ERRCODE	errCode = BC_ERR_NOERROR;
    uint8_t		frontendIndex = 0;
    bool		resetSaturationCounter = false;
	bool		resetAdcClippingCounter = false;
	uint8_t 	rxIndex = 0;
	uint16_t 	adcSaturationClipping[RFE_RX_COUNT] = {0};
	uint8_t 	pdcClipping[RFE_RX_COUNT] = {0};

	if (*rfe___error___pointer == rfe_error_none_e)
	{
		// Store the current front end id set since we are updating it to read temperature from multiple front ends
		for(frontendIndex = 0; frontendIndex < RfeDrvStateNoFrontendsGet(); frontendIndex++)
		{
			rfeSwUtils_SelectFe(frontendIndex);
			pDrvState = RfeDrvStateGet();
			resetSaturationCounter = rfeCfg_monitorAndSafety_getRxSatCountResetEveryChirpSequence(pDrvState->rfeConfig, rfe___error___pointer);
			resetAdcClippingCounter = rfeCfg_monitorAndSafety_getAdcClippingCountResetEveryChirpSequence(pDrvState->rfeConfig, rfe___error___pointer);
			if(resetSaturationCounter)
			{
				for(rxIndex =  0; rxIndex < RFE_RX_COUNT; ++rxIndex)
				{
					rfeMonitorValues.rxSaturationClippingCount[(rxIndex + (RFE_RX_COUNT * frontendIndex))] = 0;
				}
			}
			if(resetAdcClippingCounter)
			{
				for(rxIndex =  0; rxIndex < RFE_RX_COUNT; ++rxIndex)
				{
					rfeMonitorValues.pdcClippingCount[(rxIndex + (RFE_RX_COUNT * frontendIndex))] = 0;
				}
			}
			rfeSwMon_getRxSaturationClipping(adcSaturationClipping, rfe___error___pointer);
			if (*rfe___error___pointer == rfe_error_none_e)
			{
				for(rxIndex =  0; rxIndex < RFE_RX_COUNT; ++rxIndex)
				{
					rfeMonitorValues.rxSaturationClippingCount[(rxIndex + (RFE_RX_COUNT * frontendIndex))] += adcSaturationClipping[rxIndex];
				}
			}
			if (*rfe___error___pointer == rfe_error_none_e)
			{
				rfeSwMon_getAdcHardClippingMaskedFlag(pdcClipping, rfe___error___pointer);
			}
			if (*rfe___error___pointer == rfe_error_none_e)
			{
				for(rxIndex =  0; rxIndex < RFE_RX_COUNT; ++rxIndex)
				{
					rfeMonitorValues.pdcClippingCount[(rxIndex + (RFE_RX_COUNT * frontendIndex))] += (uint32_t)pdcClipping[rxIndex];
				}
			}
			// Get Tx ISM error and warnings
			errCode = BC_ISM_GetTxErrStatus(e_ISM_GET_MASKED_ERR , &pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[currentChirpSequenceIndexParam].txErr[RFE_TX_CHANNEL_0],
					&pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[currentChirpSequenceIndexParam].txErr[RFE_TX_CHANNEL_1],
					&pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[currentChirpSequenceIndexParam].txErr[RFE_TX_CHANNEL_2], NULL);
			if(errCode != BC_ERR_NOERROR)
			{
				*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
			}
			if (measureTemperature)
			{
				if (*rfe___error___pointer == rfe_error_none_e)
				{
					rfeSwMon_getTemperatureMeasurement(&rfeMonitorValues.
						temperature_afterChirpSequence[(RFE_TEMPERATURE_SENSOR_COUNT * frontendIndex)], rfe___error___pointer);
				}
			}
			rfeFusaFaultStatisticsUpdateTef82xx(rfe___error___pointer);
		}
	}
}

void rfeSwMon_monitorDataBeforeChirping(bool measureTemperature, rfe_error_t* rfe___error___pointer)
{
    uint8_t		frontendIndex = 0;

	if (*rfe___error___pointer == rfe_error_none_e)
	{
		for(frontendIndex = 0; frontendIndex < RfeDrvStateNoFrontendsGet(); frontendIndex++)
		{
			rfeSwUtils_SelectFe(frontendIndex);
			// Measure and store temperature after last sequence in radar cycle
			if (measureTemperature == true)
			{
				rfeSwMon_getTemperatureMeasurement(&rfeMonitorValues.temperature_beforeChirpSequence[RFE_TEMPERATURE_SENSOR_COUNT * frontendIndex], rfe___error___pointer);
			}
			rfeSwMon_enableResetAdc1234ClippingCounter(rfe_rx1234Reset_e, (BOOL)TRUE, rfe___error___pointer);
			rfeSwMon_clearAdcHardClippingFlag((BOOL)TRUE, (BOOL)TRUE, (BOOL)TRUE, (BOOL)TRUE, rfe___error___pointer);
		}
	}
}


rfe_monitorValues_t* rfeMon_getRfeMonitorValues(void)
{
    return &rfeMonitorValues;
}
