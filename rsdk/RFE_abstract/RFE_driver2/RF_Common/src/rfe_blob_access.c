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
 *   Project              : RF_Abstract_2.0
 *   Platform             : S32R41
 *****************************************************************************/

/******************************************************************************
 *                              INCLUDES
 *****************************************************************************/
#include "rfe_cfg_blob.h"
#include "rfe_blob_access.h"
#include "rfe_min_max_blob.h"


/******************************************************************************
 *                              DEFINITIONS
 *****************************************************************************/
/**
 * The accepted values for blob version
 */
#define RFE_CFG_BLOB_ID_MAJOR_MIN       0UL
#define RFE_CFG_BLOB_ID_MINOR_MIN       8UL
#define RFE_CFG_BLOB_ID_PATCH_MIN       10UL
#define RFE_CFG_BLOB_ID_HASH_MIN        0UL
#define RFE_CFG_BLOB_ID_32BITS_MIN      ((RFE_CFG_BLOB_ID_MAJOR_MIN << 24U) + (RFE_CFG_BLOB_ID_MINOR_MIN << 16U) + (RFE_CFG_BLOB_ID_PATCH_MIN << 8U) + RFE_CFG_BLOB_ID_HASH_MIN)

#define RFE_CFG_BLOB_ID_MAJOR_MAX       0UL
#define RFE_CFG_BLOB_ID_MINOR_MAX       8UL
#define RFE_CFG_BLOB_ID_PATCH_MAX       10UL
#define RFE_CFG_BLOB_ID_HASH_MAX        0UL
#define RFE_CFG_BLOB_ID_32BITS_MAX      ((RFE_CFG_BLOB_ID_MAJOR_MAX << 24U) + (RFE_CFG_BLOB_ID_MINOR_MAX << 16U) + (RFE_CFG_BLOB_ID_PATCH_MAX << 8U) + RFE_CFG_BLOB_ID_HASH_MAX)


/******************************************************************************
 *                                      LOCAL CONSTANTS
*****************************************************************************/
/**
 * Maps chirp sequence config index to the corresponding section.
 */
static const rfeCfg_section_t rfeCfg_util_sections_chirpSequence[RFE_CHIRP_SEQUENCE_CONFIGS_MAX] = {
    [0] = rfeCfg_section_chirpSequenceConfig_0_e,
    [1] = rfeCfg_section_chirpSequenceConfig_1_e,
    [2] = rfeCfg_section_chirpSequenceConfig_2_e,
    [3] = rfeCfg_section_chirpSequenceConfig_3_e,
    [4] = rfeCfg_section_chirpSequenceConfig_4_e,
    [5] = rfeCfg_section_chirpSequenceConfig_5_e,
    [6] = rfeCfg_section_chirpSequenceConfig_6_e,
    [7] = rfeCfg_section_chirpSequenceConfig_7_e
};

/**
 * Maps chirp profile sequence index to the corresponding param.
 */
static const rfeCfg_param_t rfeCfg_util_params_chirpSequence_chirpProfileSequence[RFE_CHIRP_PROFILE_SEQUENCE_LENGTH_MAX] = {
    [0] = rfeCfg_param_chirpSequence_chirpProfileSequence_0_e,
    [1] = rfeCfg_param_chirpSequence_chirpProfileSequence_1_e,
    [2] = rfeCfg_param_chirpSequence_chirpProfileSequence_2_e,
    [3] = rfeCfg_param_chirpSequence_chirpProfileSequence_3_e,
    [4] = rfeCfg_param_chirpSequence_chirpProfileSequence_4_e,
    [5] = rfeCfg_param_chirpSequence_chirpProfileSequence_5_e,
    [6] = rfeCfg_param_chirpSequence_chirpProfileSequence_6_e,
    [7] = rfeCfg_param_chirpSequence_chirpProfileSequence_7_e
};

/**
 * Maps chirp profile index to the corresponding section.
 */
static const rfeCfg_section_t rfeCfg_util_sections_chirpProfile[RFE_CHIRP_PROFILES_MAX] = {
    [0] = rfeCfg_section_chirpProfile_0_e,
    [1] = rfeCfg_section_chirpProfile_1_e,
    [2] = rfeCfg_section_chirpProfile_2_e,
    [3] = rfeCfg_section_chirpProfile_3_e,
    [4] = rfeCfg_section_chirpProfile_4_e,
    [5] = rfeCfg_section_chirpProfile_5_e,
    [6] = rfeCfg_section_chirpProfile_6_e,
    [7] = rfeCfg_section_chirpProfile_7_e
};

/**
 * Maps TX phase rotation index to the corresponding param.
 */
static const rfeCfg_param_t rfeCfg_util_params_radarCycle_chirpProfile_txPhaseRotation[RFE_TX_COUNT] = {
    [0] = rfeCfg_param_chirpProfile_txPhaseRotation_1_e,
    [1] = rfeCfg_param_chirpProfile_txPhaseRotation_2_e,
    [2] = rfeCfg_param_chirpProfile_txPhaseRotation_3_e,
};

/**
 * Maps TX ddma init phase index to the corresponding param.
 */
static const rfeCfg_param_t rfeCfg_util_params_radarCycle_chirpProfile_txDdmaInitPhase[RFE_TX_COUNT] = {
    [0] = rfeCfg_param_chirpSequence_txPhaseRotation_ddma_tx1_init_e,
    [1] = rfeCfg_param_chirpSequence_txPhaseRotation_ddma_tx2_init_e,
    [2] = rfeCfg_param_chirpSequence_txPhaseRotation_ddma_tx3_init_e,
};

/**
 * Maps TX ddma update phase index to the corresponding param.
 */
static const rfeCfg_param_t rfeCfg_util_params_radarCycle_chirpProfile_txDdmaUpdatePhase[RFE_TX_COUNT] = {
    [0] = rfeCfg_param_chirpSequence_txPhaseRotation_ddma_tx1_update_e,
    [1] = rfeCfg_param_chirpSequence_txPhaseRotation_ddma_tx2_update_e,
    [2] = rfeCfg_param_chirpSequence_txPhaseRotation_ddma_tx3_update_e,
};

/**
 * Maps TX final pc gen mode index to the corresponding param.
 */
static const rfeCfg_param_t rfeCfg_util_params_radarCycle_chirpProfile_txFinalPcGenMode[RFE_TX_COUNT] = {
    [0] = rfeCfg_param_chirpSequence_txPhaseRotation_ddma_tx1_mode_e,
    [1] = rfeCfg_param_chirpSequence_txPhaseRotation_ddma_tx2_mode_e,
    [2] = rfeCfg_param_chirpSequence_txPhaseRotation_ddma_tx3_mode_e
};

/**
 * Maps radar cycle chirp sequence index to the corresponding param.
 */
static const rfeCfg_param_t rfeCfg_util_params_radarCycle_chirpSequenceStartTimeOffset[RFE_CHIRP_SEQUENCES_PER_RADAR_CYCLE_MAX] = {
    [0] = rfeCfg_param_radarCycle_chirpSequenceStartTimeOffset_0_e,
    [1] = rfeCfg_param_radarCycle_chirpSequenceStartTimeOffset_1_e,
    [2] = rfeCfg_param_radarCycle_chirpSequenceStartTimeOffset_2_e,
    [3] = rfeCfg_param_radarCycle_chirpSequenceStartTimeOffset_3_e,
    [4] = rfeCfg_param_radarCycle_chirpSequenceStartTimeOffset_4_e,
    [5] = rfeCfg_param_radarCycle_chirpSequenceStartTimeOffset_5_e,
    [6] = rfeCfg_param_radarCycle_chirpSequenceStartTimeOffset_6_e,
    [7] = rfeCfg_param_radarCycle_chirpSequenceStartTimeOffset_7_e
};

/**
 * Maps radar cycle chirp sequence index to the corresponding param.
 */
static const rfeCfg_param_t rfeCfg_util_params_radarCycle_chirpSequence[RFE_CHIRP_SEQUENCES_PER_RADAR_CYCLE_MAX] = {
    [0] = rfeCfg_param_radarCycle_chirpSequence_0_e,
    [1] = rfeCfg_param_radarCycle_chirpSequence_1_e,
    [2] = rfeCfg_param_radarCycle_chirpSequence_2_e,
    [3] = rfeCfg_param_radarCycle_chirpSequence_3_e,
    [4] = rfeCfg_param_radarCycle_chirpSequence_4_e,
    [5] = rfeCfg_param_radarCycle_chirpSequence_5_e,
    [6] = rfeCfg_param_radarCycle_chirpSequence_6_e,
    [7] = rfeCfg_param_radarCycle_chirpSequence_7_e
};

/**
 * Maps FUSA mask index to corresponding param.
 */
static const rfeCfg_param_t rfeCfg_util_params_fuSaFaultMask[RFE_FUSA_FAULT_MASK_PARAM_COUNT] = {
    [0] = rfeCfg_param_monitorAndSafety_fuSaFaultMask_0_e,
    [1] = rfeCfg_param_monitorAndSafety_fuSaFaultMask_1_e,
    [2] = rfeCfg_param_monitorAndSafety_fuSaFaultMask_2_e,
    [3] = rfeCfg_param_monitorAndSafety_fuSaFaultMask_3_e,
    [4] = rfeCfg_param_monitorAndSafety_fuSaFaultMask_4_e,
    [5] = rfeCfg_param_monitorAndSafety_fuSaFaultMask_5_e,
    [6] = rfeCfg_param_monitorAndSafety_fuSaFaultMask_6_e,
    [7] = rfeCfg_param_monitorAndSafety_fuSaFaultMask_7_e,
    [8] = rfeCfg_param_monitorAndSafety_fuSaFaultMask_8_e,
    [9] = rfeCfg_param_monitorAndSafety_fuSaFaultMask_9_e,
    [10] = rfeCfg_param_monitorAndSafety_fuSaFaultMask_10_e,
    [11] = rfeCfg_param_monitorAndSafety_fuSaFaultMask_11_e
};

/**
 * Maps rx saturation threshold stage index to the corresponding section.
 */
static const rfeCfg_param_t rfeCfg_util_sections_rxSaturationThresholdStage[RFE_RX_STAGE][RFE_RX_COUNT] = {
	{
		rfeCfg_param_monitorAndSafety_rxSaturationThresholdStage1_rx1_e,
		rfeCfg_param_monitorAndSafety_rxSaturationThresholdStage1_rx2_e,
		rfeCfg_param_monitorAndSafety_rxSaturationThresholdStage1_rx3_e,
		rfeCfg_param_monitorAndSafety_rxSaturationThresholdStage1_rx4_e
	},
	{
		rfeCfg_param_monitorAndSafety_rxSaturationThresholdStage2_rx1_e,
		rfeCfg_param_monitorAndSafety_rxSaturationThresholdStage2_rx2_e,
		rfeCfg_param_monitorAndSafety_rxSaturationThresholdStage2_rx3_e,
		rfeCfg_param_monitorAndSafety_rxSaturationThresholdStage2_rx4_e
	}
};

/**
 * Maps rx saturation count limit stage  index to the corresponding section.
 */
static const rfeCfg_param_t rfeCfg_util_sections_rxSaturationCountLimitStage[RFE_RX_STAGE][RFE_RX_COUNT] = {
	[0] = {
		[0] = rfeCfg_param_monitorAndSafety_rxSaturationCountLimitStage1_rx1_e,
		[1] = rfeCfg_param_monitorAndSafety_rxSaturationCountLimitStage1_rx2_e,
		[2] = rfeCfg_param_monitorAndSafety_rxSaturationCountLimitStage1_rx3_e,
		[3] = rfeCfg_param_monitorAndSafety_rxSaturationCountLimitStage1_rx4_e
	},
	[1] = {
		[0] = rfeCfg_param_monitorAndSafety_rxSaturationCountLimitStage2_rx1_e,
		[1] = rfeCfg_param_monitorAndSafety_rxSaturationCountLimitStage2_rx2_e,
		[2] = rfeCfg_param_monitorAndSafety_rxSaturationCountLimitStage2_rx3_e,
		[3] = rfeCfg_param_monitorAndSafety_rxSaturationCountLimitStage2_rx4_e

	}
};

/******************************************************************************
 *                              TYPES
 *****************************************************************************/

/******************************************************************************
 *                              LOCAL FUNCTIONS
 *****************************************************************************/
void rfeCfg_general_setPowerMode(uint8_t* pConfig, rfe_powerMode_t powerMode, rfe_error_t* rfe___error___pointer)
{
   rfeCfg_write( pConfig, rfeCfg_section_general_e, rfeCfg_param_general_powerMode_e, (uint32_t)powerMode, rfe___error___pointer);
}

uint8_t rfeCfg_general_getPowerMode(const uint8_t* pConfig, rfe_error_t* rfe___error___pointer)
{
   return rfeCfg_readB(pConfig, rfeCfg_section_general_e, rfeCfg_param_general_powerMode_e, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Get the TX Calibration mode (with / without transmission)
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the Sequence index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  0 - without transmission
 *          1 - with transmission
 */
uint8_t rfeCfg_general_getTxCalibrationMode(const uint8_t* pConfig, rfe_error_t* rfe___error___pointer)
{
    return rfeCfg_readB(pConfig, rfeCfg_section_general_e, rfeCfg_param_general_txCalibration_mode_e, rfe___error___pointer);
}

/*
**
 * \brief  Maps FUSA mask config index to the corresponding param.
 *
 * \param [in]          fusaErrorMaskIndex              The FUSA mask index.
 * \param [in, out]     rfe___error___pointer           Error handling parameter:
 *
 * \return The corresponding param.
 *
 */
static inline rfeCfg_param_t rfeCfg_util_fuSaFaultMask(rfe_fuSaFaultMaskIndex_t fusaErrorMaskIndex, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_param_t parm = rfeCfg_param_monitorAndSafety_fuSaFaultMask_0_e;

    if(*rfe___error___pointer == rfe_error_none_e)
    {
        if((uint32_t)fusaErrorMaskIndex < RFE_FUSA_FAULT_MASK_PARAM_COUNT)
        {
            parm = rfeCfg_util_params_fuSaFaultMask[(uint8_t)fusaErrorMaskIndex];
        }
        else
        {
            *rfe___error___pointer = rfe_error_api_invalidArgumentValue_e ;
        }
    }
    return parm;
}

/*
**
 * \brief  Maps rxSaturationThresholdStage config index to the corresponding param.
 *
 * \param [in]          rxStage                The Rx stage.
 * \param [in]          rxIndex                The Rx index.
 * \param [in, out]     rfe___error___pointer  Error handling parameter:
 *
 * \return The corresponding param.
 *
 */
static inline rfeCfg_param_t rfeCfg_util_rxSaturationThresholdStage(uint8_t rxStage, uint8_t rxIndex, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_param_t parm = rfeCfg_param_monitorAndSafety_fuSaFaultMask_0_e;

    if(*rfe___error___pointer == rfe_error_none_e)
    {
        if ((rxIndex < (uint8_t)RFE_RX_COUNT) && (rxStage < (uint8_t)RFE_RX_STAGE))
        {
            parm = rfeCfg_util_sections_rxSaturationThresholdStage[rxStage][rxIndex];
        }
        else
        {
            *rfe___error___pointer = rfe_error_api_invalidArgumentValue_e ;
        }
    }
    return parm;
}

/*
**
 * \brief  Maps rxSaturationCountLimitStage config index to the corresponding param.
 *
 * \param [in]          rxStage                The Rx stage.
 * \param [in]          rxIndex                The Rx index.
 * \param [in, out]     rfe___error___pointer  Error handling parameter:
 *
 * \return The corresponding param.
 *
 */
static inline rfeCfg_param_t rfeCfg_util_rxSaturationCountLimitStage(uint8_t rxStage, uint8_t rxIndex, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_param_t parm = rfeCfg_param_monitorAndSafety_fuSaFaultMask_0_e;

    if(*rfe___error___pointer == rfe_error_none_e)
    {
        if ((rxIndex < (uint8_t)RFE_RX_COUNT) && (rxStage < (uint8_t)RFE_RX_STAGE))
        {
            parm = rfeCfg_util_sections_rxSaturationCountLimitStage[rxStage][rxIndex];
        }
        else
        {
            *rfe___error___pointer = rfe_error_api_invalidArgumentValue_e ;
        }
    }

    return parm;
}

/**
 * \brief  Maps chirp profile sequence start time offset index to the corresponding param.
 *
 * \param [in]          index                               The chirp profile sequence start time offset index.
 * \param [in, out]     rfe___error___pointer               Error handling parameter:
 *
 * \return The corresponding param.
 *
 */
static inline rfeCfg_param_t rfeCfg_util_chirpSequenceStartTimeOffset(uint8_t index, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_param_t param = rfeCfg_param_radarCycle_chirpSequenceStartTimeOffset_0_e;

    if(*rfe___error___pointer == rfe_error_none_e)
    {
        if(index < (uint8_t)RFE_CHIRP_SEQUENCES_PER_RADAR_CYCLE_MAX)
        {
            param = rfeCfg_util_params_radarCycle_chirpSequenceStartTimeOffset[(uint8_t)index];
        }
        else
        {
            *rfe___error___pointer = rfe_error_api_invalidArgumentValue_e;
        }
    }
    return param;
}

/**
 * \brief  Maps TX phase rotation index to the corresponding param.
 *
 * \pre    NIL
 *
 * \param [in]          tx                                          The TX phase rotation index.
 * \param [in, out]     RFE_ERROR_FUNCTION_PARAMETER                Error handling parameter:
 *
 * \return The corresponding param.
 *
 * \post   NIL
 */
static inline rfeCfg_param_t rfeCfg_util_txPhaseRotation(rfe_txIndex_t tx, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_param_t param = rfeCfg_param_chirpProfile_txPhaseRotation_1_e;

    if((uint32_t)tx < RFE_TX_COUNT)
    {
        param = rfeCfg_util_params_radarCycle_chirpProfile_txPhaseRotation[(uint8_t)tx];
    }
    else
    {
        *rfe___error___pointer = rfe_error_api_invalidArgumentValue_e;
    }
    return param;
}

/**
 * \brief  Maps TX ddma init phase index to the corresponding param.
 *
 * \pre    NIL
 *
 * \param [in]          tx                                          The TX phase rotation index.
 * \param [in, out]     RFE_ERROR_FUNCTION_PARAMETER                Error handling parameter:
 *
 * \return The corresponding param.
 *
 * \post   NIL
 */
static inline rfeCfg_param_t rfeCfg_util_txDdmaInitPhase(rfe_txIndex_t tx, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_param_t param = rfeCfg_param_chirpSequence_txPhaseRotation_ddma_tx1_init_e;

    if((uint32_t)tx < RFE_TX_COUNT)
    {
        param = rfeCfg_util_params_radarCycle_chirpProfile_txDdmaInitPhase[(uint8_t)tx];
    }
    else
    {
        *rfe___error___pointer = rfe_error_api_invalidArgumentValue_e;
    }
    return param;
}

/**
 * \brief  Maps TX ddma update phase index to the corresponding param.
 *
 * \pre    NIL
 *
 * \param [in]          tx                                          The TX phase rotation index.
 * \param [in, out]     RFE_ERROR_FUNCTION_PARAMETER                Error handling parameter:
 *
 * \return The corresponding param.
 *
 * \post   NIL
 */
static inline rfeCfg_param_t rfeCfg_util_txDdmaUpdatePhase(rfe_txIndex_t tx, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_param_t param = rfeCfg_param_chirpSequence_txPhaseRotation_ddma_tx1_update_e;

    if((uint32_t)tx < RFE_TX_COUNT)
    {
        param = rfeCfg_util_params_radarCycle_chirpProfile_txDdmaUpdatePhase[(uint8_t)tx];
    }
    else
    {
        *rfe___error___pointer = rfe_error_api_invalidArgumentValue_e;
    }
    return param;
}

/**
 * \brief  Maps TX final pc gem mode index to the corresponding param.
 *
 * \param [in]          tx                                          The TX phase rotation index.
 * \param [in, out]     RFE_ERROR_FUNCTION_PARAMETER                Error handling parameter:
 *
 * \return The corresponding param.
 *
 */
static inline rfeCfg_param_t rfeCfg_util_txFinalPcGenMode(rfe_txIndex_t tx, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_param_t param = rfeCfg_param_chirpSequence_txPhaseRotation_ddma_tx1_mode_e;

    if((uint32_t)tx < RFE_TX_COUNT)
    {
        param = rfeCfg_util_params_radarCycle_chirpProfile_txFinalPcGenMode[(uint8_t)tx];
    }
    else
    {
        *rfe___error___pointer = rfe_error_api_invalidArgumentValue_e;
    }
    return param;
}

/**
 * \brief  Function to compute the parameter offset inside the section.
 *
 * \param [in]          section                     the section of the parameter
 * \param [in]          parameter                   the parameter
 * \param [in, out]     rfe___error___pointer       error handling pointer
 *
 * \return The parameter offset.
 *
 */
static uint16_t rfeCfg_getParamOffset(rfeCfg_section_t section, rfeCfg_param_t param, rfe_error_t* rfe___error___pointer)
{
    uint16_t offset = 0U;

    if(*rfe___error___pointer == rfe_error_none_e)
    {
        if(((uint16_t)section & RFE_CFG_PARAM_SECTION_MSK) == ((uint16_t)param & RFE_CFG_PARAM_SECTION_MSK))
        {
            offset  = ((uint16_t)section & RFE_CFG_PARAM_OFFSET_MSK) >> RFE_CFG_PARAM_OFFSET_SHF;
            offset += ((uint16_t)param & RFE_CFG_PARAM_OFFSET_MSK) >> RFE_CFG_PARAM_OFFSET_SHF;
        }
        else
        {
            *rfe___error___pointer = rfe_error_api_cfgInvalidParameterSize_rfeDriverOnly_e;
        }
    }
    return offset;
}

/**
 * \brief  Function to return the parameter size.
 *
 * \param [in]          parameter                   the parameter
 * \param [in, out]     rfe___error___pointer       error handling pointer
 *
 * \return The parameter size.
 *
 */
static rfeCfg_size_t rfeCfg_getParamSize(rfeCfg_param_t param, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_size_t size = rfeCfg_size_invalid_e;

    if(*rfe___error___pointer == rfe_error_none_e)
    {
        switch ( (uint16_t)param & RFE_CFG_PARAM_SIZE_MSK )
        {
            case RFE_CFG_PARAM_SIZE_8_BIT:
                size = rfeCfg_size_8_bit_e;
                break;

            case RFE_CFG_PARAM_SIZE_16_BIT:
                size = rfeCfg_size_16_bit_e;
                break;

            case RFE_CFG_PARAM_SIZE_32_BIT:
                size = rfeCfg_size_32_bit_e;
                break;

            default:
                *rfe___error___pointer = rfe_error_api_cfgInvalidParameterSize_rfeDriverOnly_e;
                break;
        }
    }
    return size;
}

/**
 * \brief  Function to write a blob parameter value.
 *
 * \param [in]     pConfig      pointer to the blob configuration
 * \param [in]     value        the value to be written
 * \param [in]     size         the size of the parameter
 *
 */
static void rfeCfg_writeValue(uint8_t *pConfig, uint32_t value, rfeCfg_size_t size)
{
    *pConfig = (uint8_t)((value & 0x000000ffUL));
    if(size != rfeCfg_size_8_bit_e)
    {
        pConfig[1U] = (uint8_t)(((value & 0x0000ff00UL) >> 8u));
    }
    if(size == rfeCfg_size_32_bit_e)
    {
        pConfig[2U] = (uint8_t)(((value & 0x00ff0000UL) >> 16u));
        pConfig[3U] = (uint8_t)(((value & 0xff000000UL) >> 24u));
    }
}

/******************************************************************************
 *                              GLOBAL FUNCTIONS
 *****************************************************************************/
/*****************************************************************************
 * \brief  Maps chirp sequence config index to the corresponding section.
 *
 * \param [in]          chirpSequenceIndex                          The chirp sequence config index.
 * \param [in, out]     RFE_ERROR_FUNCTION_PARAMETER                Error handling parameter:
 *
 * \return The corresponding section.
 *
 * \post   NIL
 */
rfeCfg_section_t rfeCfg_util_chirpSequenceConfigIndex(rfe_chirpSequenceIndex_t chirpSequenceIndex, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_section_chirpSequenceConfig_0_e;

    if((uint32_t)chirpSequenceIndex < RFE_CHIRP_SEQUENCE_CONFIGS_MAX)
    {
        section = rfeCfg_util_sections_chirpSequence[(uint8_t)chirpSequenceIndex];
    }
    else
    {
        *rfe___error___pointer = rfe_error_api_invalidArgumentValue_e;
    }
    return section;
}

/*****************************************************************************
 * \brief  Maps chirp profile sequence index to the corresponding param.
 *
 * \param [in]          index                                The chirp profile sequence index.
 * \param [in, out]     rfe___error___pointer                Error handling parameter:
 *
 * \return The corresponding param.
 *
 */
rfeCfg_param_t rfeCfg_util_chirpProfileSequence(uint8_t index, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_param_t param = rfeCfg_param_chirpSequence_chirpProfileSequence_0_e;

    if(*rfe___error___pointer == rfe_error_none_e)
    {
        if(index < (uint8_t)RFE_CHIRP_PROFILE_SEQUENCE_LENGTH_MAX)
        {
            param = rfeCfg_util_params_chirpSequence_chirpProfileSequence[index];
        }
        else
        {
            *rfe___error___pointer = rfe_error_api_invalidArgumentValue_e;
        }
    }
    return param;
}


/*------------------------------------------------------------------------------*/
/**
 * \brief  Check the blob compatibility
 *
 * \param [in]          configPtr                   Pointer to the blob
 * \param [in, out]     rfe___error___pointer       Error handling parameter:
 *
 * \return void, but the wrong result is signaled as error in rfe___error___pointer
 *
 */
void rfeCfg_CheckBlobCompatibility(void* configPtr, volatile rfe_error_t* rfe___error___pointer)
{
    uint32_t    blobVersion;                    // blob Version
    uint8_t     *ptrConfig = (uint8_t*)configPtr;

    blobVersion =  ((uint32_t)(ptrConfig[rfeCfg_param_metadata_majorVersion_e])) << 24u;
    blobVersion += ((uint32_t)(ptrConfig[rfeCfg_param_metadata_minorVersion_e])) << 16u;
    blobVersion += ((uint32_t)(ptrConfig[rfeCfg_param_metadata_patchVersion_e])) << 8u;
    blobVersion +=  (uint32_t)(ptrConfig[rfeCfg_param_metadata_hashVersion_e]);
    if((blobVersion < (uint32_t)RFE_CFG_BLOB_ID_32BITS_MIN) || (blobVersion > (uint32_t)RFE_CFG_BLOB_ID_32BITS_MAX))
    {
        *rfe___error___pointer = rfe_error_api_invalidConfigurationVersion_e;
    }
}
/*---- rfeCfg_CheckBlobCompatibility ----------------*/

/*****************************************************************************
 * \brief This function write a value from the configuration, according to the provided parameters :
 *          section and parameter. The provided value must be a uint32_t value, but the written value is according
 *          to the Configuration parameter definition.
 *
 * \pre   NIL
 *
 * \param [in]      pConfig   - Pointer to the data buffer.
 *                  len       - the required length in bytes
 *
 */
void rfeCfg_calcAndWriteCrc(void* pConfig, uint32_t len)
{
    uint8_t     i;
    uint32_t    crcCalc;
    uint8_t     *crcPtr = &((uint8_t*)pConfig)[len];

    crcCalc = rfeCrc_calBuf((void*)pConfig, len);
    for(i = 0; i < sizeof(uint32_t); i++)
    {
        *crcPtr = (uint8_t)crcCalc;
        crcPtr++;
        crcCalc >>= 8U;
    }
}
/*---- rfeCfg_calcAndWriteCrc ----------------*/


/*****************************************************************************
 * \brief This function write a value from the configuration, according to the provided parameters :
 *          section and parameter. The provided value must be a uint32_t value, but the written value is according
 *          to the Configuration parameter definition.
 *
 * \pre   NIL
 *
 * \param [in]      pConfig   - Pointer to the Configuration Data Memory.
 *                  section   - the required section
 *                  parameter - the required parameter
 *                  value     - the value to be written, aligned to 32 bits
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * \return \ref     void
 *
 * \post   NIL
 *
 */
void rfeCfg_write(uint8_t *pConfig, rfeCfg_section_t section, rfeCfg_param_t param, uint32_t value, rfe_error_t* rfe___error___pointer)
{
    uint32_t        blobMin, blobMax;
    uint16_t        offset;
    rfeCfg_size_t   size;
    uint32_t        crcCalc, crcBlob;
    uint8_t         *crcPtr;

    // check first the compatibility for the min/max blobs
    rfeCfg_CheckBlobCompatibility(rfeConfigBlobMinValues, rfe___error___pointer);
    rfeCfg_CheckBlobCompatibility(rfeConfigBlobMaxValues, rfe___error___pointer);
    if(*rfe___error___pointer == rfe_error_none_e)
    {
        // check the blob CRC
        crcCalc = rfeCrc_calBuf((void*)pConfig, (uint32_t)RFE_CFG_OFFSET_SECTION_CRC);
        crcPtr = (uint8_t*)(void*)pConfig + RFE_CFG_OFFSET_SECTION_CRC;
        crcBlob = (((uint32_t)*(crcPtr + 3U)) << 24U) + (((uint32_t)*(crcPtr + 2U)) << 16U) + (((uint32_t)*(crcPtr + 1U)) << 8U) + (uint32_t)*(crcPtr);
        if(crcCalc != crcBlob)
        {
            *rfe___error___pointer = rfe_error_api_blob_crc_wrong_e;
        }
        else
        {
            // check the value compatibility, between min/max values
            blobMin = rfeCfg_read(rfeConfigBlobMinValues, section, param, rfe___error___pointer);
            blobMax = rfeCfg_read(rfeConfigBlobMaxValues, section, param, rfe___error___pointer);
            if(((blobMin < blobMax) && ((blobMax < value) || (blobMin > value))) ||
                    ((blobMin > blobMax) && ((blobMax < value) && (blobMin > value))))
            {
                *rfe___error___pointer = rfe_error_api_invalidArgumentValue_e;      // wrong value, not between [min...max]
            }
        }
        if ( *rfe___error___pointer == rfe_error_none_e )
        {
            // detect the location and the size of the parameter
            offset = rfeCfg_getParamOffset(section, param, rfe___error___pointer);
            size = rfeCfg_getParamSize(param, rfe___error___pointer);
            if(size >= rfeCfg_size_invalid_e)
            {
                *rfe___error___pointer = rfe_error_api_cfgInvalidParameterSize_rfeDriverOnly_e;
            }
            else
            {
                rfeCfg_writeValue(&pConfig[offset], value, size);
            }
            // update the blob CRC
            rfeCfg_calcAndWriteCrc((void*)pConfig, (uint32_t)RFE_CFG_OFFSET_SECTION_CRC);
        }
    }
}

/*****************************************************************************
 * \brief This function read an value from the configuration, according to the provided parameters : section and parameter
 *
 * \param [in]      pConfig   - Pointer to the Configuration Data Memory.
 *                  section   - the required section
 *                  parameter - the required parameter
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * \return \ref uint32_t value
 *
 */
uint32_t rfeCfg_read(const uint8_t *pConfig, rfeCfg_section_t section, rfeCfg_param_t param, rfe_error_t* rfe___error___pointer)
{
    uint32_t value = 0;

    if(*rfe___error___pointer == rfe_error_none_e)
    {
        uint16_t offset = rfeCfg_getParamOffset( section, param, rfe___error___pointer);
        rfeCfg_size_t size = rfeCfg_getParamSize( param, rfe___error___pointer);
        switch(size)
        {
        case rfeCfg_size_32_bit_e:
            value  =  (uint32_t)(pConfig[offset + 0U]);
            value |= ((uint32_t)(pConfig[offset + 1U]) << 8 );
            value |= ((uint32_t)(pConfig[offset + 2U]) << 16);
            value |= ((uint32_t)(pConfig[offset + 3U]) << 24);
            break;
        case rfeCfg_size_16_bit_e:
            value  =  (uint32_t)(pConfig[offset + 0U]);
            value |= ((uint32_t)(pConfig[offset + 1U]) << 8 );
            break;
        case rfeCfg_size_8_bit_e:
            value  =  (uint32_t)(pConfig[offset + 0U]);
            break;
        default:
            *rfe___error___pointer = rfe_error_api_cfgInvalidParameterSize_rfeDriverOnly_e;
            break;
        }
    }
    return value;
}


/*****************************************************************************
 * \brief This function read an uint32_t value from the configuration, according to the provided parameters :
 *          section and parameter
 *
 * \param [in]      pConfig   - Pointer to the Configuration Data Memory.
 *                  section   - the required section
 *                  parameter - the required parameter
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * \return \ref uint32_t value
 *
 */
uint32_t rfeCfg_readDW(const uint8_t *pConfig, rfeCfg_section_t section, rfeCfg_param_t param, rfe_error_t* rfe___error___pointer)
{
    uint32_t value = 0;

    if(*rfe___error___pointer == rfe_error_none_e)
    {
        uint16_t offset = rfeCfg_getParamOffset( section, param, rfe___error___pointer);
        if(rfeCfg_getParamSize( param, rfe___error___pointer) != rfeCfg_size_32_bit_e)
        {
            *rfe___error___pointer = rfe_error_api_cfgInvalidParameterSize_rfeDriverOnly_e;
        }
        else
        {
            value |=  (uint32_t)(pConfig[offset + 0U]);
            value |= ((uint32_t)(pConfig[offset + 1U]) << 8 );
            value |= ((uint32_t)(pConfig[offset + 2U]) << 16);
            value |= ((uint32_t)(pConfig[offset + 3U]) << 24);
        }
    }
    return value;
}


/*****************************************************************************
 * \brief This function read an uint16_t value from the configuration, according to the provided parameters :
 *          section and parameter
 *
 * \param [in]      pConfig   - Pointer to the Configuration Data Memory.
 *                  section   - the required section
 *                  parameter - the required parameter
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * \return \ref uint16_t value
 *
 */
uint16_t rfeCfg_readW(const uint8_t *pConfig, rfeCfg_section_t section, rfeCfg_param_t param, rfe_error_t* rfe___error___pointer)
{
    uint16_t value = 0;

    if(*rfe___error___pointer == rfe_error_none_e)
    {
        uint16_t offset = rfeCfg_getParamOffset( section, param, rfe___error___pointer);
        if(rfeCfg_getParamSize( param, rfe___error___pointer) != rfeCfg_size_16_bit_e)
        {
            *rfe___error___pointer = rfe_error_api_cfgInvalidParameterSize_rfeDriverOnly_e;
        }
        else
        {
            value =   (uint16_t)(pConfig[offset + 0U]);
            value |= ((uint16_t)(pConfig[offset + 1U]) << 8u);
        }
    }
    return value;
}


/*****************************************************************************
 * \brief This function read an uint8_t value from the configuration, according to the provided parameters :
 *          section and parameter
 *
 * \param [in]      pConfig   - Pointer to the Configuration Data Memory.
 *                  section   - the required section
 *                  parameter - the required parameter
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * \return \ref uint8_t value
 *
 */
uint8_t rfeCfg_readB(const uint8_t *pConfig, rfeCfg_section_t section, rfeCfg_param_t param, rfe_error_t* rfe___error___pointer)
{
    uint8_t value = 0;

    if(*rfe___error___pointer == rfe_error_none_e)
    {
        uint16_t offset = rfeCfg_getParamOffset( section, param, rfe___error___pointer);
        if(rfeCfg_getParamSize( param, rfe___error___pointer) != rfeCfg_size_8_bit_e)
        {
            *rfe___error___pointer = rfe_error_api_cfgInvalidParameterSize_rfeDriverOnly_e;
        }
        else
        {
            value = pConfig[offset + 0U];
        }
    }
    return value;
}


/*****************************************************************************
 * \brief  Writes a configuration item.
 *
 * \param [in]          chirpProfileIndex                   The chirp profile index.
 * \param [in, out]     rfe___error___pointer               Error handling parameter:
 *
 * \return The corresponding section.
 *
 */
rfeCfg_section_t rfeCfg_util_chirpProfileIndex(rfe_chirpProfileIndex_t chirpProfileIndex, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_section_chirpProfile_0_e;

    if(*rfe___error___pointer == rfe_error_none_e)
    {
        if((uint32_t)chirpProfileIndex < RFE_CHIRP_PROFILES_MAX)
        {
            section = rfeCfg_util_sections_chirpProfile[(uint8_t)chirpProfileIndex];
        }
        else
        {
            *rfe___error___pointer = rfe_error_api_invalidArgumentValue_e;
        }
    }
    return section;
}


/*****************************************************************************
 * \brief   Set a different chirp count to the blob
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the index of the sequence to be changed
 * \param   chirpCount                  = the new chir count
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpSequence_setChirpCount(uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, uint16_t chirpCount, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpSequenceConfigIndex(chirpSequenceConfigIndex, rfe___error___pointer);
    rfeCfg_write(pConfig, section, rfeCfg_param_chirpSequence_chirpCount_e, (uint32_t)chirpCount, rfe___error___pointer);
}

                                
/*****************************************************************************
 * \brief   Get the curent chirp count in the blob
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the index of the sequence to be checked
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing chirp count, as uint16_t
 */
uint16_t rfeCfg_chirpSequence_getChirpCount(const uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpSequenceConfigIndex(chirpSequenceConfigIndex, rfe___error___pointer);
    return rfeCfg_readW(pConfig, section, rfeCfg_param_chirpSequence_chirpCount_e, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Set a different sequence length
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the index of the sequence to be changed
 * \param   chirpProfileSequenceLength  = the new sequence length
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpSequence_setChirpProfileSequenceLength(uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, uint8_t chirpProfileSequenceLength,
        rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpSequenceConfigIndex(chirpSequenceConfigIndex, rfe___error___pointer);
    rfeCfg_write(pConfig, section, rfeCfg_param_chirpSequence_chirpProfileSequenceLength_e, (uint32_t)chirpProfileSequenceLength, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the index of the sequence to be checked
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing sequence length
 */
uint8_t rfeCfg_chirpSequence_getChirpProfileSequenceLength(const uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpSequenceConfigIndex(chirpSequenceConfigIndex, rfe___error___pointer);
    return rfeCfg_readB(pConfig, section, rfeCfg_param_chirpSequence_chirpProfileSequenceLength_e, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Set chirp Profile Repeat Count in sequence
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the index of the sequence to be changed
 * \param   chirpProfileRepeatCount  	= the new repeat count
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpSequence_setChirpProfileRepeatCount(uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, uint8_t chirpProfileRepeatCount,
        rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpSequenceConfigIndex(chirpSequenceConfigIndex, rfe___error___pointer);
    rfeCfg_write(pConfig, section, rfeCfg_param_chirpSequence_chirpProfileRepeatCount_e, (uint32_t)chirpProfileRepeatCount, rfe___error___pointer);
}

/*****************************************************************************
 * \brief
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the index of the sequence to be checked
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing sequence length
 */
uint8_t rfeCfg_chirpSequence_getChirpProfileRepeatCount(const uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpSequenceConfigIndex(chirpSequenceConfigIndex, rfe___error___pointer);
    return rfeCfg_readB(pConfig, section, rfeCfg_param_chirpSequence_chirpProfileRepeatCount_e, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Set a different dynamic update enablement
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the index of the sequence to be changed
 * \param   dynamicUpdatesEnabled       = the new dynamic update enablement
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpSequence_setDynamicUpdatesEnabled(uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, bool dynamicUpdatesEnabled,
        rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpSequenceConfigIndex(chirpSequenceConfigIndex, rfe___error___pointer);
    rfeCfg_write(pConfig, section, (rfeCfg_param_t)rfeCfg_param_chirpSequence_dynamicUpdatesEnabled_e, (uint32_t)dynamicUpdatesEnabled, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Get the existing setting for dynamic updates
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the index of the sequence to be checked
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The dynamic update current status
 */
bool rfeCfg_chirpSequence_getDynamicUpdatesEnabled(const uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpSequenceConfigIndex(chirpSequenceConfigIndex, rfe___error___pointer);
    return (bool) (rfeCfg_readB(pConfig, section, rfeCfg_param_chirpSequence_dynamicUpdatesEnabled_e, rfe___error___pointer));
}

/*****************************************************************************
 * \brief   Set a new dynamic table index
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the index of the sequence to be set
 * \param   dynamicTableIndex           = the new dynamic table index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpSequence_setDynamicTableIndex(uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, uint8_t dynamicTableIndex, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpSequenceConfigIndex(chirpSequenceConfigIndex, rfe___error___pointer);
    rfeCfg_write(pConfig, section, rfeCfg_param_chirpSequence_dynamicTableIndex_e, (uint32_t)dynamicTableIndex, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Get the current dynamic table index
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the index of the sequence to be checked
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing dynamic table index
 */
uint8_t rfeCfg_chirpSequence_getDynamicTableIndex(const uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpSequenceConfigIndex(chirpSequenceConfigIndex, rfe___error___pointer);
    return rfeCfg_readB(pConfig, section, rfeCfg_param_chirpSequence_dynamicTableIndex_e, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Set a new value for Rx Enablement
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the index of the sequence to be set
 * \param   rxEnable                    = the new value for Rx Enablement
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpSequence_setRxEnable(uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, rfe_rxSelect_t rxEnable, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpSequenceConfigIndex(chirpSequenceConfigIndex, rfe___error___pointer);
    rfeCfg_write(pConfig, section, rfeCfg_param_chirpSequence_rxEnable_e, (uint32_t)rxEnable, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Get the current Rx Enablement value
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the index of the sequence to be checked
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Rx Enablement
 */
uint8_t rfeCfg_chirpSequence_getRxEnable(const uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpSequenceConfigIndex(chirpSequenceConfigIndex, rfe___error___pointer);
    return rfeCfg_readB(pConfig, section, rfeCfg_param_chirpSequence_rxEnable_e, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Set a new value for Chirp Profile Sequence
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the index of the sequence to be set
 * \param   chirpProfileSequenceIndex   = the chirp sequence to update
 * \param   chirpProfile                = the new value for Chirp Profile Sequence
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpSequence_setChirpProfileSequence(uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, uint8_t chirpProfileSequenceIndex,
        rfe_chirpProfileIndex_t chirpProfile, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpSequenceConfigIndex(chirpSequenceConfigIndex, rfe___error___pointer);
    rfeCfg_param_t param = rfeCfg_util_chirpProfileSequence(chirpProfileSequenceIndex, rfe___error___pointer);
    rfeCfg_write(pConfig, section, param, (uint32_t)chirpProfile, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Get the current Chirp Profile Sequence value
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the index of the sequence to be checked
 * \param   chirpProfileSequenceIndex   = the chirp sequence to check
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Chirp Profile Sequence
 */
uint8_t rfeCfg_chirpSequence_getChirpProfileSequence(const uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, uint8_t chirpProfileSequenceIndex,
        rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpSequenceConfigIndex(chirpSequenceConfigIndex, rfe___error___pointer);
    rfeCfg_param_t param = rfeCfg_util_chirpProfileSequence(chirpProfileSequenceIndex, rfe___error___pointer);
    return rfeCfg_readB(pConfig, section, param, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Set a new value for Effective Sampling Frequency
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   effectiveSamplingFrequency  = the new value for Effective Sampling Frequency
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpProfile_setEffectiveSamplingFrequency(uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_effectiveSamplingFrequency_t effectiveSamplingFrequency,
        rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpProfileIndex(chirpProfileIndex, rfe___error___pointer);
    rfeCfg_write(pConfig, section, rfeCfg_param_chirpProfile_effectiveSamplingFrequency_e, (uint32_t)effectiveSamplingFrequency, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Get the current Effective Sampling Frequency value
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Effective Sampling Frequency
 */
uint8_t rfeCfg_chirpProfile_getEffectiveSamplingFrequency(const uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpProfileIndex(chirpProfileIndex, rfe___error___pointer);
    return rfeCfg_readB(pConfig, section, rfeCfg_param_chirpProfile_effectiveSamplingFrequency_e, rfe___error___pointer);
}
        
/*****************************************************************************
 * \brief   Set a new value for Chirp Interval Time Ticks
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   chirpIntervalTimeTicks      = the new value for Chirp Interval Time Ticks
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpProfile_setChirpIntervalTimeTicks(uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, uint32_t chirpIntervalTimeTicks,rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpProfileIndex(chirpProfileIndex, rfe___error___pointer);
    rfeCfg_write(pConfig, section, rfeCfg_param_chirpProfile_chirpIntervalTimeTicks_e, chirpIntervalTimeTicks, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Get the current Chirp Interval Time Ticks
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Chirp Interval Time Ticks
 */
uint32_t rfeCfg_chirpProfile_getChirpIntervalTimeTicks(const uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpProfileIndex(chirpProfileIndex, rfe___error___pointer);
    return rfeCfg_readDW(pConfig, section, rfeCfg_param_chirpProfile_chirpIntervalTimeTicks_e, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Set a new value for Dwell Time Ticks
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   dwellTimeTicks              = the new value for Dwell Time Ticks
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpProfile_setDwellTimeTicks(uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, uint16_t dwellTimeTicks, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpProfileIndex(chirpProfileIndex, rfe___error___pointer);
    rfeCfg_write(pConfig, section, rfeCfg_param_chirpProfile_dwellTimeTicks_e, (uint32_t)dwellTimeTicks, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Get the current Dwell Time Ticks
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Dwell Time Ticks
 */
uint16_t rfeCfg_chirpProfile_getDwellTimeTicks(const uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpProfileIndex(chirpProfileIndex, rfe___error___pointer);
    return rfeCfg_readW(pConfig, section, rfeCfg_param_chirpProfile_dwellTimeTicks_e, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Set a new value for Settle Time Ticks
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   settleTimeTicks             = the new value for Settle Time Ticks
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpProfile_setSettleTimeTicks(uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, uint16_t settleTimeTicks, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpProfileIndex(chirpProfileIndex, rfe___error___pointer);
    rfeCfg_write(pConfig, section, rfeCfg_param_chirpProfile_settleTimeTicks_e, (uint32_t)settleTimeTicks, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Get the current Settle Time Ticks
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Settle Time Ticks
 */
uint16_t rfeCfg_chirpProfile_getSettleTimeTicks(const uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpProfileIndex(chirpProfileIndex, rfe___error___pointer);
    return rfeCfg_readW(pConfig, section, rfeCfg_param_chirpProfile_settleTimeTicks_e, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Set a new value for Acquisition Time Ticks
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   acquisitionTimeTicks        = the new value for Acquisition Time Ticks
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpProfile_setAcquisitionTimeTicks(uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, uint16_t acquisitionTimeTicks, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpProfileIndex(chirpProfileIndex, rfe___error___pointer);
    rfeCfg_write(pConfig, section, rfeCfg_param_chirpProfile_acquisitionTimeTicks_e, (uint32_t)acquisitionTimeTicks, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Get the current Acquisition Time Ticks
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Acquisition Time Ticks
 */
uint16_t rfeCfg_chirpProfile_getAcquisitionTimeTicks(const uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpProfileIndex(chirpProfileIndex, rfe___error___pointer);
    return rfeCfg_readW(pConfig, section, rfeCfg_param_chirpProfile_acquisitionTimeTicks_e, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Set a new value for Reset Time Ticks
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   resetTimeTicks              = the new value for Reset Time Ticks
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpProfile_setResetTimeTicks(uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, uint16_t resetTimeTicks, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpProfileIndex(chirpProfileIndex, rfe___error___pointer);
    rfeCfg_write(pConfig, section, rfeCfg_param_chirpProfile_resetTimeTicks_e, (uint32_t)resetTimeTicks, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Get the current Reset Time Ticks
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Reset Time Ticks
 */
uint16_t rfeCfg_chirpProfile_getResetTimeTicks(const uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpProfileIndex(chirpProfileIndex, rfe___error___pointer);
    return rfeCfg_readW(pConfig, section, rfeCfg_param_chirpProfile_resetTimeTicks_e, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Set a new value for Center Frequency
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   centerFrequency             = the new value for Center Frequency
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpProfile_setCenterFrequency(uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, uint32_t centerFrequency, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpProfileIndex(chirpProfileIndex, rfe___error___pointer);
    rfeCfg_write(pConfig, section, rfeCfg_param_chirpProfile_centerFrequency_e, centerFrequency, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Get the current Center Frequency
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Center Frequency
 */
uint32_t rfeCfg_chirpProfile_getCenterFrequency(const uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpProfileIndex(chirpProfileIndex, rfe___error___pointer);
    return rfeCfg_readDW(pConfig, section, rfeCfg_param_chirpProfile_centerFrequency_e, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Set a new value for Effective Chirp Bandwidth
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   effectiveChirpBandwidth     = the new value for Effective Chirp Bandwidth
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpProfile_setEffectiveChirpBandwidth(uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, uint32_t effectiveChirpBandwidth,
        rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpProfileIndex(chirpProfileIndex, rfe___error___pointer);
    rfeCfg_write(pConfig, section, rfeCfg_param_chirpProfile_effectiveChirpBandwidth_e, effectiveChirpBandwidth, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Get the current Effective Chirp Bandwidth
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Effective Chirp Bandwidth
 */
uint32_t rfeCfg_chirpProfile_getEffectiveChirpBandwidth(const uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpProfileIndex(chirpProfileIndex, rfe___error___pointer);
    return rfeCfg_readDW(pConfig, section, rfeCfg_param_chirpProfile_effectiveChirpBandwidth_e, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Set a new value for Chirp Pll Vco
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   chirpPllVcoSelect           = the new value for Chirp Pll Vco
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpProfile_setChirpPllVco(uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_chirpPllVco_t chirpPllVcoSelect, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpProfileIndex(chirpProfileIndex, rfe___error___pointer);
    rfeCfg_write(pConfig, section, rfeCfg_param_chirpProfile_chirpPllVcoSelect_e, (uint32_t)chirpPllVcoSelect, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Get the current Chirp Pll Vco
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Chirp Pll Vco
 */
uint8_t rfeCfg_chirpProfile_getChirpPllVco(const uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpProfileIndex(chirpProfileIndex, rfe___error___pointer);
    return rfeCfg_readB(pConfig, section, rfeCfg_param_chirpProfile_chirpPllVcoSelect_e, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Set a new value for Chirp Slope Direction
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   chirpSlopeDirection         = the new value for Chirp Slope Direction
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpProfile_setChirpSlopeDirection(uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_chirpSlopeDirection_t chirpSlopeDirection,
        rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpProfileIndex(chirpProfileIndex, rfe___error___pointer);
    rfeCfg_write(pConfig, section, rfeCfg_param_chirpProfile_chirpSlopeDirection_e, (uint32_t)chirpSlopeDirection, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Get the current Chirp Slope Direction
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Chirp Slope Direction
 */
uint8_t rfeCfg_chirpProfile_getChirpSlopeDirection(const uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpProfileIndex(chirpProfileIndex, rfe___error___pointer);
    return rfeCfg_readB(pConfig, section, rfeCfg_param_chirpProfile_chirpSlopeDirection_e, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Set a new value for Chirp Pll Loop Filter Bandwidth
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   chirpPllLoopFilterBandwidth = the new value for Chirp Pll Loop Filter Bandwidth
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpProfile_setChirpPllLoopFilterBandwidth(uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_chirpPllLoopFilterBandwidth_t chirpPllLoopFilterBandwidth,
        rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpProfileIndex(chirpProfileIndex, rfe___error___pointer);
    rfeCfg_write(pConfig, section, rfeCfg_param_chirpProfile_chirpPllLoopFilterBandwidth_e, (uint32_t)chirpPllLoopFilterBandwidth, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Get the current Chirp Pll Loop Filter Bandwidth
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Chirp Pll Loop Filter Bandwidth
 */
uint8_t rfeCfg_chirpProfile_getChirpPllLoopFilterBandwidth(const uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex,
        rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpProfileIndex(chirpProfileIndex, rfe___error___pointer);
    return rfeCfg_readB(pConfig, section, rfeCfg_param_chirpProfile_chirpPllLoopFilterBandwidth_e, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Set a new value for Tx Transmission Enable
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   txTransmissionEnable        = the new value for Tx Transmission Enable
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpProfile_setTxTransmissionEnable(uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_txSelect_t txTransmissionEnable,
        rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpProfileIndex(chirpProfileIndex, rfe___error___pointer);
    rfeCfg_write(pConfig, section, rfeCfg_param_chirpProfile_txTransmissionEnable_e, (uint32_t)txTransmissionEnable, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Get the current Tx Transmission Enable
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Tx Transmission Enable
 */
uint8_t rfeCfg_chirpProfile_getTxTransmissionEnable(const uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpProfileIndex(chirpProfileIndex, rfe___error___pointer);
    return rfeCfg_readB(pConfig, section, rfeCfg_param_chirpProfile_txTransmissionEnable_e, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Set a new value for Tx Power
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   txPower                     = the new value for Tx Power
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpProfile_setTxPower(uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, int16_t txPower, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpProfileIndex(chirpProfileIndex, rfe___error___pointer);
    rfeCfg_write(pConfig, section, rfeCfg_param_chirpProfile_txPower_e, (uint32_t)txPower, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Get the current Tx Power
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Tx Power
 */
int16_t rfeCfg_chirpProfile_getTxPower(const uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpProfileIndex(chirpProfileIndex, rfe___error___pointer);
    return (int16_t)rfeCfg_readW(pConfig, section, rfeCfg_param_chirpProfile_txPower_e, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Set a new value for Tx Phase Rotation
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   txPhaseRotation             = the new value for Tx Phase Rotation
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpProfile_setTxPhaseRotation(uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_txIndex_t tx, rfe_phaseRotation_t txPhaseRotation,
        rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpProfileIndex(chirpProfileIndex, rfe___error___pointer);
    rfeCfg_param_t param = rfeCfg_util_txPhaseRotation(tx, rfe___error___pointer);
    rfeCfg_write(pConfig, section, param, (uint32_t)txPhaseRotation, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Get the current Tx Phase Rotation
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Tx Phase Rotation
 */
uint8_t rfeCfg_chirpProfile_getTxPhaseRotation(const uint8_t* pConfig,
        rfe_chirpProfileIndex_t chirpProfileIndex, rfe_txIndex_t tx, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpProfileIndex(chirpProfileIndex, rfe___error___pointer);
    rfeCfg_param_t param = rfeCfg_util_txPhaseRotation(tx, rfe___error___pointer);
    return rfeCfg_readB(pConfig, section, param, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Set a new value for Tx Transmission Reference Time
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   txTransmissionReferenceTime = the new value for Tx Transmission Reference Time
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpProfile_setTxTransmissionReferenceTime(uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_txTransmissionReferenceTime_t txTransmissionReferenceTime,
        rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpProfileIndex(chirpProfileIndex, rfe___error___pointer);
    rfeCfg_write(pConfig, section, rfeCfg_param_chirpProfile_txTransmissionReferenceTime_e, (uint32_t)txTransmissionReferenceTime, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Get the current Tx Transmission Reference Time
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Tx Transmission Reference Time
 */
uint8_t rfeCfg_chirpProfile_getTxTransmissionReferenceTime(const uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpProfileIndex(chirpProfileIndex, rfe___error___pointer);
    return rfeCfg_readB(pConfig, section, rfeCfg_param_chirpProfile_txTransmissionReferenceTime_e, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Set a new value for Tx Transmission Time Offset
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   txTransmissionTimeOffset    = the new value for Tx Transmission Time Offset
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpProfile_setTxTransmissionTimeOffset(uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, uint16_t txTransmissionTimeOffset, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpProfileIndex(chirpProfileIndex, rfe___error___pointer);
    rfeCfg_write(pConfig, section, rfeCfg_param_chirpProfile_txTransmissionTimeOffset_e, (uint32_t)txTransmissionTimeOffset, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Get the current Tx Transmission Time Offset
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Tx Transmission Time Offset
 */
uint16_t rfeCfg_chirpProfile_getTxTransmissionTimeOffset(const uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpProfileIndex(chirpProfileIndex, rfe___error___pointer);
    return rfeCfg_readW(pConfig, section, rfeCfg_param_chirpProfile_txTransmissionTimeOffset_e, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Set a new value for Rx Gain
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   rxGain                      = the new value for Rx Gain
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpProfile_setRxGain(uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_rxGain_t rxGain, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpProfileIndex(chirpProfileIndex, rfe___error___pointer);
    rfeCfg_write(pConfig, section, rfeCfg_param_chirpProfile_rxGain_e, (uint32_t)rxGain, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Get the current Rx Gain
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Rx Gain
 */
uint8_t rfeCfg_chirpProfile_getRxGain(const uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpProfileIndex(chirpProfileIndex, rfe___error___pointer);
    return rfeCfg_readB(pConfig, section, rfeCfg_param_chirpProfile_rxGain_e, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Set a new value for Rx Hpf CutOff Frequency
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   rxHpfCutOffFrequency        = the new value for Rx Hpf CutOff Frequency
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpProfile_setRxHpfCutOffFrequency(uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_rxHpfCutOffFrequency_t rxHpfCutOffFrequency,
        rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpProfileIndex(chirpProfileIndex, rfe___error___pointer);
    rfeCfg_write(pConfig, section, rfeCfg_param_chirpProfile_rxHpfCutOffFrequency_e, (uint32_t)rxHpfCutOffFrequency, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Get the current Rx Hpf CutOff Frequency
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Rx Hpf CutOff Frequency
 */
uint8_t rfeCfg_chirpProfile_getRxHpfCutOffFrequency(const uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpProfileIndex(chirpProfileIndex, rfe___error___pointer);
    return rfeCfg_readB(pConfig, section, rfeCfg_param_chirpProfile_rxHpfCutOffFrequency_e, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Set a new value for Rx Lpf CutOff Frequency
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   rxLpfCutOffFrequency        = the new value for Rx Lpf CutOff Frequency
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpProfile_setRxLpfCutOffFrequency(uint8_t* pConfig,rfe_chirpProfileIndex_t chirpProfileIndex, rfe_rxLpfCutOffFrequency_t rxLpfCutOffFrequency, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpProfileIndex(chirpProfileIndex, rfe___error___pointer);
    rfeCfg_write(pConfig, section, rfeCfg_param_chirpProfile_rxLpfCutOffFrequency_e, (uint32_t)rxLpfCutOffFrequency, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Get the current Rx Lpf CutOff Frequency
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Rx Lpf CutOff Frequency
 */
uint8_t rfeCfg_chirpProfile_getRxLpfCutOffFrequency(const uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpProfileIndex(chirpProfileIndex, rfe___error___pointer);
    return rfeCfg_readB(pConfig, section, rfeCfg_param_chirpProfile_rxLpfCutOffFrequency_e,  rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Set a new value for Virtual Channel
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   virtualChannel              = the new value for Virtual Channel
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_chirpProfile_setVirtualChannel(uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_virtualChannel_t virtualChannel, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpProfileIndex(chirpProfileIndex, rfe___error___pointer);
    rfeCfg_write(pConfig, section, rfeCfg_param_chirpProfile_virtualChannel_e, (uint32_t)virtualChannel, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Get the current Rx Virtual Channel
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpProfileIndex           = the chirp profile index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Virtual Channel
 */
uint8_t rfeCfg_chirpProfile_getVirtualChannel(const uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpProfileIndex(chirpProfileIndex, rfe___error___pointer);
    return rfeCfg_readB(pConfig, section, rfeCfg_param_chirpProfile_virtualChannel_e, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Set a new value for Radar Cycle Duration
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   radarCycleDuration          = the new value for Radar Cycle Duration
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_radarCycle_setRadarCycleDuration(uint8_t* pConfig, uint32_t radarCycleDuration, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_write(pConfig, rfeCfg_section_radarCycle_e, rfeCfg_param_radarCycle_radarCycleDuration_e, radarCycleDuration, rfe___error___pointer);
}


/*****************************************************************************
 * \brief  Maps radar cycle chirp sequence index to the corresponding param.
 *
 * \param [in]          index                                The radar cycle chirp sequence index.
 * \param [in, out]     rfe___error___pointer                Error handling parameter:
 *
 * \return The corresponding param.
 *
 */
rfeCfg_param_t rfeCfg_util_radarCycleChirpSequence(uint8_t index, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_param_t param = rfeCfg_param_radarCycle_chirpSequence_0_e;

    if(*rfe___error___pointer == rfe_error_none_e)
    {
        if(index < RFE_CHIRP_SEQUENCES_PER_RADAR_CYCLE_MAX)
        {
            param = rfeCfg_util_params_radarCycle_chirpSequence[index];
        }
        else
        {
            *rfe___error___pointer = rfe_error_api_invalidArgumentValue_e;
        }
    }
    return param;
}

/*****************************************************************************
 * \brief   Get the current Rx Radar Cycle Duration
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Radar Cycle Duration
 */
uint32_t rfeCfg_radarCycle_getRadarCycleDuration(const uint8_t* pConfig, rfe_error_t* rfe___error___pointer)
{
    return rfeCfg_readDW(pConfig, rfeCfg_section_radarCycle_e, rfeCfg_param_radarCycle_radarCycleDuration_e, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Get Chirp sequence
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceIndex          = sequence index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The chirp Sequence Config Index
 */
uint8_t rfeCfg_radarCycle_getChirpSequence(const uint8_t* pConfig, uint8_t chirpSequenceIndex, rfe_error_t* rfe___error___pointer)
{
   rfeCfg_param_t param = rfeCfg_util_radarCycleChirpSequence(chirpSequenceIndex, rfe___error___pointer);
   return rfeCfg_readB(pConfig, rfeCfg_section_radarCycle_e, param, rfe___error___pointer);
}


/*****************************************************************************
 * \brief   Set RxBist element value
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   param                       = bist parameter to be updated
 * \param   value                       = the new value
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The chirp Sequence Config Index
 */
void rfeCfg_monitorAndSafety_setBist(uint8_t* pConfig, rfeCfg_param_t param, int16_t value, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_write(pConfig, rfeCfg_section_monitorAndSafety_e, param, (uint32_t)value, rfe___error___pointer);
}


void rfeCfg_monitorAndSafety_setInjectTestTone(uint8_t* pConfig, rfeSwBist_InjectToneMode_t injectTestToneMode, rfe_error_t* rfe___error___pointer)
{
   rfeCfg_write( pConfig, rfeCfg_section_monitorAndSafety_e, rfeCfg_param_monitorAndSafety_injectTestTone_e, (uint32_t)injectTestToneMode, rfe___error___pointer );
}

uint8_t rfeCfg_monitorAndSafety_getInjectTestTone(const uint8_t* pConfig, rfe_error_t* rfe___error___pointer)
{
   return rfeCfg_readB(pConfig, rfeCfg_section_monitorAndSafety_e, rfeCfg_param_monitorAndSafety_injectTestTone_e, rfe___error___pointer);
}

int16_t rfeCfg_monitorAndSafety_getBist(const uint8_t* pConfig, rfeCfg_param_t param, rfe_error_t* rfe___error___pointer)
{
    return (int16_t)rfeCfg_readW(pConfig, rfeCfg_section_monitorAndSafety_e, param, rfe___error___pointer);
}

/**
 * \brief This function gets the Loi BBD parameters stored in the Configuration Data Memory.
 *
 * \param [in]      pConfig - Pointer to the Configuration Data Memory.
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *
 * \return Loi BBD parameters
 *
 */
uint8_t rfeCfg_monitorAndSafety_getLoiBBD(const uint8_t* pConfig, rfe_error_t* rfe___error___pointer)
{
    return rfeCfg_readB(pConfig, rfeCfg_section_monitorAndSafety_e, rfeCfg_param_monitorAndSafety_checkBbd_loi_e, rfe___error___pointer);
}

/**
 * \brief This function sets the Loi BBD parameters in the Configuration Data Memory.
 *
 * \param [in]      pConfig - Pointer to the Configuration Data Memory.
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *
 * \return Loi BBD parameters
 *
 */
void rfeCfg_monitorAndSafety_setLoiBBD(const uint8_t* pConfig, uint8_t val, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_write((uint8_t*)pConfig, rfeCfg_section_monitorAndSafety_e, rfeCfg_param_monitorAndSafety_checkBbd_loi_e, (uint32_t)val, rfe___error___pointer);
}

/**
 * \brief This function gets the Tx BBD parameters stored in the Configuration Data Memory.
 *
 * \param [in]      pConfig - Pointer to the Configuration Data Memory.
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *
 * \return Loi BBD parameters
 *
 */
uint8_t rfeCfg_monitorAndSafety_getTxBBD(const uint8_t* pConfig, rfe_error_t* rfe___error___pointer)
{
    return rfeCfg_readB(pConfig, rfeCfg_section_monitorAndSafety_e, rfeCfg_param_monitorAndSafety_checkBbd_tx_e, rfe___error___pointer);
}

/**
 * \brief This function gets the Rx BBD parameters stored in the Configuration Data Memory.
 *
 * \param [in]      pConfig - Pointer to the Configuration Data Memory.
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *
 * \return Loi BBD parameters
 *
 */
uint8_t rfeCfg_monitorAndSafety_getRxBBD(const uint8_t* pConfig, rfe_error_t* rfe___error___pointer)
{
    return rfeCfg_readB(pConfig, rfeCfg_section_monitorAndSafety_e, rfeCfg_param_monitorAndSafety_checkBbd_rx_e, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Set Ddma Phase Rotator enable/disable
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the Sequence index
 * \param   enable		                = enable/disable
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_sequence_setPhaseRotationDdmaMode(uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, uint8_t enable, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpSequenceConfigIndex(chirpSequenceConfigIndex, rfe___error___pointer);
    rfeCfg_write(pConfig, section, rfeCfg_param_chirpSequence_txPhaseRotation_ddma_e, (uint32_t)enable, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Get Ddma Phase Rotator enable/disable
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the Sequence index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  Ddma enable/disable
 */
uint8_t rfeCfg_sequence_getPhaseRotationDdmaMode(const uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpSequenceConfigIndex(chirpSequenceConfigIndex, rfe___error___pointer);
    return rfeCfg_readB(pConfig, section, rfeCfg_param_chirpSequence_txPhaseRotation_ddma_e, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Get Tx use ddma
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the Sequence index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  use_ddma
 */
uint8_t rfeCfg_sequence_getPhaseRotationTxUseDdma(const uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpSequenceConfigIndex(chirpSequenceConfigIndex, rfe___error___pointer);
    return rfeCfg_readB(pConfig, section, rfeCfg_param_chirpSequence_txPhaseRotation_ddma_tx_e, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Set a new value for Tx Ddma_init_phase
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the Sequence index
 * \param   txDdmaInitPhase             = the new value for Tx Ddma_init_phase
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_sequence_setTxDdmaInitPhase(uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, rfe_txIndex_t tx, rfe_phaseRotation_t txDdmaInitPhase,
        rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpSequenceConfigIndex(chirpSequenceConfigIndex, rfe___error___pointer);
    rfeCfg_param_t param = rfeCfg_util_txDdmaInitPhase(tx, rfe___error___pointer);
    rfeCfg_write(pConfig, section, param, (uint32_t)txDdmaInitPhase, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Get the current Tx Ddma_init_phase
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the Sequence index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Tx Ddma_init_phase
 */
uint8_t rfeCfg_sequence_getTxDdmaInitPhase(const uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, rfe_txIndex_t tx,
        rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpSequenceConfigIndex(chirpSequenceConfigIndex, rfe___error___pointer);
    rfeCfg_param_t param = rfeCfg_util_txDdmaInitPhase(tx, rfe___error___pointer);
    return rfeCfg_readB(pConfig, section, param, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Set a new value for Tx Ddma_update_phase
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the Sequence index
 * \param   txDdmaUpdatePhase             = the new value for Tx Ddma_update_phase
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_sequence_setTxDdmaUpdatePhase(uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, rfe_txIndex_t tx, rfe_phaseRotation_t txDdmaUpdatePhase,
        rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpSequenceConfigIndex(chirpSequenceConfigIndex, rfe___error___pointer);
    rfeCfg_param_t param = rfeCfg_util_txDdmaUpdatePhase(tx, rfe___error___pointer);
    rfeCfg_write(pConfig, section, param, (uint32_t)txDdmaUpdatePhase, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Get the current Tx Ddma_update_phase
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the Sequence index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Tx Ddma_update_phase
 */
uint8_t rfeCfg_sequence_getTxDdmaUpdatePhase(const uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, rfe_txIndex_t tx,
        rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpSequenceConfigIndex(chirpSequenceConfigIndex, rfe___error___pointer);
    rfeCfg_param_t param = rfeCfg_util_txDdmaUpdatePhase(tx, rfe___error___pointer);
    return rfeCfg_readB(pConfig, section, param, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Set a new value for Tx final pc gen mode
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the Sequence index
 * \param   txFinalPcGenMode            = the new value for Tx final pc gen mode
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 */
void rfeCfg_sequence_setTxFinalPcGenMode(uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, rfe_txIndex_t tx, rfe_PRPCGenMode_e txFinalPcGenMode,
        rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpSequenceConfigIndex(chirpSequenceConfigIndex, rfe___error___pointer);
    rfeCfg_param_t param = rfeCfg_util_txFinalPcGenMode(tx, rfe___error___pointer);
    rfeCfg_write(pConfig, section, param, (uint32_t)txFinalPcGenMode, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Get the TX Calibration - High Power Threshold
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the Sequence index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  range -> (0, 4] with 2 fractional digits
 */
uint16_t rfeCfg_sequence_getTxCalibrationThresholdHigh(const uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, rfe_error_t* rfe___error___pointer)
{
	rfeCfg_section_t section = rfeCfg_util_chirpSequenceConfigIndex(chirpSequenceConfigIndex, rfe___error___pointer);
	return rfeCfg_readW(pConfig, section, rfeCfg_param_chirpSequence_txCalibration_thresholdHigh_e, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Get the TX Calibration - Low Power Threshold
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the Sequence index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  range -> (0, 4] with 2 fractional digits
 */
uint16_t rfeCfg_sequence_getTxCalibrationThresholdLow(const uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpSequenceConfigIndex(chirpSequenceConfigIndex, rfe___error___pointer);
    return rfeCfg_readW(pConfig, section, rfeCfg_param_chirpSequence_txCalibration_thresholdLow_e, rfe___error___pointer);
}

/*****************************************************************************
 * \brief   Get the current Tx final pc gen mode
 *
 * \param   pConfig                     = pointer to the blob configuration
 * \param   chirpSequenceConfigIndex    = the Sequence index
 * \param   rfe___error___pointer       = pointer to the error variable
 *
 * \return  The existing Tx final pc gen mode
 */
uint8_t rfeCfg_sequence_getFinalPcGenMode(const uint8_t* pConfig, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, rfe_txIndex_t tx, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpSequenceConfigIndex(chirpSequenceConfigIndex, rfe___error___pointer);
    rfeCfg_param_t param = rfeCfg_util_txFinalPcGenMode(tx, rfe___error___pointer);
    return rfeCfg_readB(pConfig, section, param, rfe___error___pointer);
}

/**
 * \brief  This function gets the chirp frequency drift.
 *
 * \param [in]      	pConfig - Pointer to the Configuration Data Memory.
 * \param [in]          chirpProfileIndex - The chirp profile config index.
 * \param [in, out]     rfe___error___pointer - fault handling parameter:
 *                      On success *rfe___error___pointer == rfe_error_none_e is true,
 *                      On failure *rfe___error___pointer != rfe_error_none_e is true
 *
 * \return The Chirp Frequency Drift.
 *
 */
int32_t rfeCfg_chirpSequence_getChirpFrequencyDriftSteps(const uint8_t* pConfig, rfe_chirpProfileIndex_t chirpProfileIndex, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_section_t section = rfeCfg_util_chirpProfileIndex(chirpProfileIndex, rfe___error___pointer);
    return (int32_t)(rfeCfg_readDW(pConfig, section, rfeCfg_param_chirpProfile_chirpFrequencyDriftSteps_e, rfe___error___pointer));
}

/**
 * \brief This function gets the \ref chirpSequenceStartTimeOffset stored in the Configuration Data Memory.
 *
 * \param [in]      pConfig - Pointer to the Configuration Data Memory.
 * \param [in]      chirpSequenceIndex - The chirp sequence index
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success *rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure *rfe___error___pointer != rfe_error_none_e is true
 *
 * \return \ref chirpSequenceStartTimeOffset
 *
 */
uint32_t rfeCfg_radarCycle_getChirpSequenceStartTimeOffset(const uint8_t *pConfig, uint8_t chirpSequenceIndex, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_param_t param = rfeCfg_util_chirpSequenceStartTimeOffset( chirpSequenceIndex, rfe___error___pointer );
    return rfeCfg_readDW(pConfig, rfeCfg_section_radarCycle_e, param, rfe___error___pointer);
}

/**
 * \brief This function gets the \ref fuSaFaultMask stored in the Configuration Data Memory.
 *
 * \param [in]      pConfig - Pointer to the Configuration Data Memory.
 * \param [in]      fuSaFaultMaskIndex - The FuSa fault mask
 * \param [in,out]  rfe___error___pointer - fault handling parameter:
 *                  On success *rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure *rfe___error___pointer != rfe_error_none_e is true
 *
 * \return \ref fuSaFaultMask
 *
 */
uint8_t rfeCfg_monitorAndSafety_getFuSaFaultMask(const uint8_t *pConfig, rfe_fuSaFaultMaskIndex_t fuSaFaultMaskIndex, rfe_error_t* rfe___error___pointer)
{
   rfeCfg_param_t param = rfeCfg_util_fuSaFaultMask( fuSaFaultMaskIndex, rfe___error___pointer );
   return rfeCfg_readB( pConfig, rfeCfg_section_monitorAndSafety_e, param, rfe___error___pointer);
}

/**
 * \brief This function gets the \ref rxSaturationThresholdStage stored in the Configuration Data Memory.
 *
 * \param [in]      pConfig - Pointer to the Configuration Data Memory.
 * \param [in]      rxStage - The Rx stage.
 * \param [in]      rxIndex - The Rx index
 * \param [in,out]  rfe___error___pointer - fault handling parameter:
 *                  On success *rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure *rfe___error___pointer != rfe_error_none_e is true
 *
 * \return \ref rxSaturationThreshold
 *
 */
uint8_t rfeCfg_monitorAndSafety_getRxSaturationThresholdStage(const uint8_t *pConfig, uint8_t rxStage, uint8_t rxIndex, rfe_error_t* rfe___error___pointer)
{
   rfeCfg_param_t param = rfeCfg_util_rxSaturationThresholdStage( rxStage, rxIndex, rfe___error___pointer );
   return rfeCfg_readB( pConfig, rfeCfg_section_monitorAndSafety_e, param, rfe___error___pointer);
}

/**
 * \brief This function gets the \ref rxSaturationCountLimitStage stored in the Configuration Data Memory.
 *
 * \param [in]      pConfig - Pointer to the Configuration Data Memory.
 * \param [in]      rxStage - The Rx stage.
 * \param [in]      rxIndex - The Rx index
 * \param [in,out]  rfe___error___pointer - fault handling parameter:
 *                  On success *rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure *rfe___error___pointer != rfe_error_none_e is true
 *
 * \return \ref rxSaturationCountLimit
 *
 */
uint16_t rfeCfg_monitorAndSafety_getRxSaturationCountLimitStage(const uint8_t *pConfig, uint8_t rxStage, uint8_t rxIndex, rfe_error_t* rfe___error___pointer)
{
   rfeCfg_param_t param = rfeCfg_util_rxSaturationCountLimitStage( rxStage, rxIndex, rfe___error___pointer);
   return (uint16_t)rfeCfg_readDW( pConfig, rfeCfg_section_monitorAndSafety_e, param, rfe___error___pointer);
}

/**
 * \brief This function gets the \ref rxSatCountResetEveryChirpSequence stored
 * 			in the Configuration Data Memory.
 *
 * \param [in]      pConfig - Pointer to the Configuration Data Memory.
 * \param [in,out]  rfe___error___pointer - fault handling parameter:
 *                  On success *rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure *rfe___error___pointer != rfe_error_none_e is true
 *
 * \return \ref rxSaturationCountLimit
 *
 */
bool rfeCfg_monitorAndSafety_getRxSatCountResetEveryChirpSequence(const uint8_t* pConfig, rfe_error_t* rfe___error___pointer)
{
	bool flag = false;
	uint8_t val = rfeCfg_readB( pConfig, rfeCfg_section_monitorAndSafety_e, rfeCfg_param_monitorAndSafety_rxSatCountResetEveryChirpSequence_e, rfe___error___pointer);
	if(val != 0UL)
	{
		flag = true;
	}
	return flag;
}

/**
 * \brief This function gets the \ref adcClippingCountResetEveryChirpSequence stored
 * 			in the Configuration Data Memory.
 *
 * \param [in]      pConfig - Pointer to the Configuration Data Memory.
 * \param [in,out]  rfe___error___pointer - fault handling parameter:
 *                  On success *rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure *rfe___error___pointer != rfe_error_none_e is true
 *
 * \return \ref rxSaturationCountLimit
 *
 */

bool rfeCfg_monitorAndSafety_getAdcClippingCountResetEveryChirpSequence(const uint8_t* pConfig, rfe_error_t* rfe___error___pointer)
{
	bool flag = false;
	uint8_t val = rfeCfg_readB(pConfig, rfeCfg_section_monitorAndSafety_e, rfeCfg_param_monitorAndSafety_adcClippingCountResetEveryChirpSequence_e, rfe___error___pointer );
	if(val != 0UL)
	{
		flag = true;
	}
    return flag;
}

void rfeCfg_monitorAndSafety_setFrequencyForBist(uint8_t* pConfig, uint32_t frequencyForBist, rfe_error_t* rfe___error___pointer)
{
    rfeCfg_write(pConfig, (rfeCfg_section_t)rfeCfg_section_monitorAndSafety_e, (rfeCfg_param_t)rfeCfg_param_monitorAndSafety_frequencyForBist_e, frequencyForBist,
            rfe___error___pointer);
}

uint32_t rfeCfg_monitorAndSafety_getFrequencyForBist(const uint8_t* pConfig, rfe_error_t* rfe___error___pointer)
{
    return rfeCfg_readDW(pConfig, (rfeCfg_section_t)rfeCfg_section_monitorAndSafety_e, (rfeCfg_param_t)rfeCfg_param_monitorAndSafety_frequencyForBist_e, rfe___error___pointer);
}

bool rfeCfg_general_getPdcBitwidth(const uint8_t* pConfig, rfe_error_t* rfe___error___pointer)
{
    return (bool)(rfeCfg_readB(pConfig, rfeCfg_section_general_e, rfeCfg_param_general_pdcDecimationFilter_e, rfe___error___pointer));
}
