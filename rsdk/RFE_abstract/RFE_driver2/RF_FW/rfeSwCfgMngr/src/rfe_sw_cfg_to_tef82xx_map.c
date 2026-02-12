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
 *                              INCLUDES
 ==================================================================================================*/
#include "rfe_sw_cfg_to_tef82xx_map.h"
#include "rfe_sw_driver_state.h"

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

#define ERR_GROUP_OFFSET 0x060000UL
#define GROUP_FIVE 5U

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

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*=====================================================================================================================*/

RX_Gain_Control_e rfeRxGainMapper(uint8_t rxGain)
{
    RX_Gain_Control_e result = e_RX_GAIN_INVALID;

    switch (rxGain)
    {
        case (0x01u):
        {
            result = e_RX_GAIN_27DB;
            break;
        }
        case (0x02u):
        {
            result = e_RX_GAIN_30DB;
            break;
        }
        case (0x03u):
        {
            result = e_RX_GAIN_33DB;
            break;
        }
        case (0x04u):
        {
            result = e_RX_GAIN_36DB;
            break;
        }
        case (0x05u):
        {
            result = e_RX_GAIN_39DB;
            break;
        }
        case (0x06u):
        {
            result = e_RX_GAIN_42DB;
            break;
        }
        case (0x07u):
        {
            result = e_RX_GAIN_45DB;
            break;
        }
        default:
        {
            result = e_RX_GAIN_INVALID;
            break;
        }
    }

    return result;
}

/*=====================================================================================================================*/

SYS_RXLPF_CornerFreq_e rfeRxLPFMapper(rfeRxLpfCutOff_t rxLPF)
{
    SYS_RXLPF_CornerFreq_e result = e_SYS_RXLPF_INVALID;

    switch (rxLPF)
    {
        case (RFE_RX_LPF_CUTOFF_12_5MHZ):
        {
            result = e_SYS_RXLPF_12P5MHZ;
            break;
        }
        case (RFE_RX_LPF_CUTOFF_15MHZ):
        {
            result = e_SYS_RXLPF_15MHZ;
            break;
        }
        case (RFE_RX_LPF_CUTOFF_20MHZ):
        {
            result = e_SYS_RXLPF_20MHZ;
            break;
        }
        case (RFE_RX_LPF_CUTOFF_25MHZ):
        {
            result = e_SYS_RXLPF_25MHZ;
            break;
        }
        case (RFE_RX_LPF_CUTOFF_WIDE):
        {
            result = e_SYS_RXLPF_WIDE;
            break;
        }
        default:
        {
            result = e_SYS_RXLPF_INVALID;
            break;
        }
    }

    return result;
}

/*=====================================================================================================================*/

SYS_RXHPF_CornerFreq_e rfeRxHPFMapper(rfeRxHpfCutOff_t rxHPF)
{
    SYS_RXHPF_CornerFreq_e result = e_SYS_RXHPF_INVALID;

    switch (rxHPF)
    {
        case (RFE_RX_HPF_CUTOFF_100KHZ):
        {
            result = e_SYS_RXHPF_100KHZ;
            break;
        }
        case (RFE_RX_HPF_CUTOFF_200KHZ):
        {
            result = e_SYS_RXHPF_200KHZ;
            break;
        }
        case (RFE_RX_HPF_CUTOFF_300KHZ):
        {
            result = e_SYS_RXHPF_300KHZ;
            break;
        }
        case (RFE_RX_HPF_CUTOFF_400KHZ):
        {
            result = e_SYS_RXHPF_400KHZ;
            break;
        }
        case (RFE_RX_HPF_CUTOFF_800KHZ):
        {
            result = e_SYS_RXHPF_800KHZ;
            break;
        }
        case (RFE_RX_HPF_CUTOFF_1600KHZ):
        {
            result = e_SYS_RXHPF_1600KHZ;
            break;
        }
        case (RFE_RX_HPF_CUTOFF_3200KHZ):
        {
            result = e_SYS_RXHPF_3200KHZ;
            break;
        }
        default:
        {
            result = e_SYS_RXHPF_INVALID;
            break;
        }
    }

    return result;
}

/*=====================================================================================================================*/

CAFC_LoopFilterLUTSel_e rfeCafcPllLPFLUTSelMApper(uint8_t LPFLUTSel)
{
    CAFC_LoopFilterLUTSel_e result = e_CAFC_LPF_LUT_INVALID;

    switch (LPFLUTSel)
    {
        case (0x00):
        {
            result = e_CAFC_LPF_LUT_1G;
            break;
        }
        case (0x01):
        {
            result = e_CAFC_LPF_LUT_5GNARROW;
            break;
        }
        case (0x02):
        {
            result = e_CAFC_LPF_LUT_5GWIDE;
            break;
        }
        case (0x03):
        {
            result = e_CAFC_LPF_LUT_USER1;
            break;
        }
        case (0x04):
        {
            result = e_CAFC_LPF_LUT_USER2;
            break;
        }
        default:
        {
            result = e_CAFC_LPF_LUT_INVALID;
            break;
        }
    }

    return result;
}

/*=====================================================================================================================*/

CAFC_LoopFilterLUTSel_e rfeCafcPllLPFLUTSelFromVCOMapper(CAFC_VCOBWSel_e vcoSel)
{
    CAFC_LoopFilterLUTSel_e result = e_CAFC_LPF_LUT_INVALID;

    switch (vcoSel)
    {
        case (e_CAFC_1GBAND):
        {
            result = e_CAFC_LPF_LUT_1G;
            break;
        }
        case (e_CAFC_5GNARROW):
        {
            result = e_CAFC_LPF_LUT_5GNARROW;
            break;
        }
        case (e_CAFC_5GWIDE):
        {
            result = e_CAFC_LPF_LUT_5GWIDE;
            break;
        }
        default:
        {
            result = e_CAFC_LPF_LUT_INVALID;
            break;
        }
    }

    return result;
}

/*=====================================================================================================================*/

CAFC_PLLLPFSel_e rfeCafcPllLPFSelFromVCOMapper(CAFC_VCOBWSel_e vcoSel)
{
    CAFC_PLLLPFSel_e result = e_CAFC_PLLLPF_INVALID;

    switch (vcoSel)
    {
        case (e_CAFC_1GBAND):
        {
            result = e_CAFC_PLLLPF_CFG0;
            break;
        }
        case (e_CAFC_5GNARROW):
        {
            result = e_CAFC_PLLLPF_CFG1;
            break;
        }
        case (e_CAFC_5GWIDE):
        {
            result = e_CAFC_PLLLPF_CFG2;
            break;
        }
        default:
        {
            result = e_CAFC_PLLLPF_INVALID;
            break;
        }
    }

    return result;
}

/*=====================================================================================================================*/

SYS_ProfID_e rfeProfModeSelMapper(uint8_t profModeSel)
{
    SYS_ProfID_e result = e_SYS_PROFILE_INVALID;

    switch (profModeSel)
    {
        case (0x00u):
        {
            result = e_SYS_PROFILE_0;
            break;
        }
        case (0x01u):
        {
            result = e_SYS_PROFILE_1;
            break;
        }
        case (0x02u):
        {
            result = e_SYS_PROFILE_2;
            break;
        }
        case (0x03u):
        {
            result = e_SYS_PROFILE_3;
            break;
        }
        case (0x04u):
        {
            result = e_SYS_PROFILE_4;
            break;
        }
        case (0x05u):
        {
            result = e_SYS_PROFILE_5;
            break;
        }
        case (0x06u):
        {
            result = e_SYS_PROFILE_6;
            break;
        }
        case (0x07u):
        {
            result = e_SYS_PROFILE_7;
            break;
        }
        case (0x08u):
        {
            result = e_SYS_PROFILE_8;
            break;
        }
        case (0x09u):
        {
            result = e_SYS_PROFILES_0_TO_1;
            break;
        }
        case (0x0Au):
        {
            result = e_SYS_PROFILES_0_TO_2;
            break;
        }
        case (0x0Bu):
        {
            result = e_SYS_PROFILES_0_TO_3;
            break;
        }
        case (0x0Cu):
        {
            result = e_SYS_PROFILES_0_TO_4;
            break;
        }
        case (0x0Du):
        {
            result = e_SYS_PROFILES_0_TO_5;
            break;
        }
        case (0x0Eu):
        {
            result = e_SYS_PROFILES_0_TO_6;
            break;
        }
        case (0x0Fu):
        {
            result = e_SYS_PROFILES_0_TO_7;
            break;
        }
        case (0x1Eu):
        {
            result = e_SYS_PROFILE_PSRB;
            break;
        }
        case (0x1Fu):
        {
            result = e_SYS_PROFILE_LIST;
            break;
        }
        default:
        {
            result = e_SYS_PROFILE_INVALID;
            break;
        }
    }

    return result;
}

/*=====================================================================================================================*/

TE_ChirpTrigMode_e rfeUseExtTrigMapper(uint8_t useExtTrig)
{
    TE_ChirpTrigMode_e result = e_TE_CH_TRG_INVALID;

    switch (useExtTrig)
    {
        case (0x00):
        {
            result = e_TE_CH_TRG_SPI_TRIGGER;
            break;
        }
        case (0x01):
        {
            result = e_TE_CH_TRG_EXT_SINGLE_TRG;
            break;
        }
        case (0x03):
        {
            result = e_TE_CH_TRG_EXT_EVERY_CHRIP;
            break;
        }
        default:
        {
            result = e_TE_CH_TRG_INVALID;
            break;
        }
    }

    return result;
}

/*=====================================================================================================================*/

CAFC_PLLLPFSel_e rfeCafcPllLPFSelMapper(uint8_t cafcPllLPFSel)
{
    CAFC_PLLLPFSel_e result = e_CAFC_PLLLPF_INVALID;

    switch (cafcPllLPFSel)
    {
        case (0x00u):
        {
            result = e_CAFC_PLLLPF_CFG0;
            break;
        }
        case (0x01u):
        {
            result = e_CAFC_PLLLPF_CFG1;
            break;
        }
        case (0x02u):
        {
            result = e_CAFC_PLLLPF_CFG2;
            break;
        }
        case (0x03u):
        {
            result = e_CAFC_PLLLPF_CFG3;
            break;
        }
        default:
        {
            result = e_CAFC_PLLLPF_INVALID;
            break;
        }
    }

    return result;
}

/*=====================================================================================================================*/

CAFC_LoopFilterLUTSel_e rfeCafcLoopFilterLUTSelMapper(uint8_t cafcLoopFilterLUTSel)
{
	CAFC_LoopFilterLUTSel_e result = e_CAFC_LPF_LUT_INVALID;

    switch (cafcLoopFilterLUTSel)
    {
        case (0x00u):
        {
            result = e_CAFC_LPF_LUT_1G;
            break;
        }
        case (0x01u):
        {
            result = e_CAFC_LPF_LUT_5GNARROW;
            break;
        }
        case (0x02u):
        {
            result = e_CAFC_LPF_LUT_5GWIDE;
            break;
        }
        case (0x03u):
        {
            result = e_CAFC_LPF_LUT_USER1;
            break;
        }
        case (0x04u):
		{
			result = e_CAFC_LPF_LUT_USER2;
			break;
		}
        default:
        {
            result = e_CAFC_LPF_LUT_INVALID;
            break;
        }
    }

    return result;
}

/*=====================================================================================================================*/

CAFC_VCOBWSel_e rfeVCOSelMapper(uint8_t cafcPllLPFSel)
{
    CAFC_VCOBWSel_e result = e_CAFC_VCOBWSEL_INVALID;

    switch (cafcPllLPFSel)
    {
        case (0x00):
        {
            result = e_CAFC_1GBAND;
            break;
        }
        case (0x01):
        {
            result = e_CAFC_5GNARROW;
            break;
        }
        case (0x02):
        {
            result = e_CAFC_5GWIDE;
            break;
        }
        default:
        {
            result = e_CAFC_VCOBWSEL_INVALID;
            break;
        }
    }

    return result;
}

/*=====================================================================================================================*/

SYS_VCN_e rfeVirtualChannelMapper(uint8_t virtualChannelNo)
{
    SYS_VCN_e result = e_SYS_VCN_INVALID;

    switch (virtualChannelNo)
    {
        case (0x00u):
        {
            result = e_SYS_VCN_0;
            break;
        }
        case (0x01u):
        {
            result = e_SYS_VCN_1;
            break;
        }
        case (0x02u):
        {
            result = e_SYS_VCN_2;
            break;
        }
        case (0x03u):
        {
            result = e_SYS_VCN_3;
            break;
        }
        default:
        {
            result = e_SYS_VCN_INVALID;
            break;
        }
    }

    return result;
}

/*=====================================================================================================================*/

TE_DDMAMod_e rfeDdmaModeMapper(rfeDDMAModeSel_t ddmaMode)
{
    TE_DDMAMod_e result = e_TE_DDMA_INVALID;

    switch (ddmaMode)
    {
        case (RFE_PR_DDMA_DISABLED):
        {
            result = e_TE_DDMA_DISABLED;
            break;
        }
        case (RFE_PR_DDMA_FUNCTIONAL_MODE):
        {
            result = e_TE_DDMA_FUN_MODE;
            break;
        }
        case (RFE_PR_DDMA_TEST_MODE):
        {
            result = e_TE_DDMA_TEST_MODE;
            break;
        }
        case (RFE_PR_DDMA_TEST_MODE_NOCHIRP):
        {
            result = e_TE_DDMA_TEST_NOCHIRP;
            break;
        }
        default:
        {
            result = e_TE_DDMA_INVALID;
            break;
        }
    }

    return result;
}

/*=====================================================================================================================*/

TE_DDMAMod_e rfeDdmaModeFromUint8Mapper(uint8_t ddmaMode)
{
    TE_DDMAMod_e result = e_TE_DDMA_INVALID;

    switch (ddmaMode)
    {
        case (0U):
        {
            result = e_TE_DDMA_DISABLED;
            break;
        }
        case (1U):
        {
            result = e_TE_DDMA_FUN_MODE;
            break;
        }
        case (2U):
        {
            result = e_TE_DDMA_TEST_MODE;
            break;
        }
        case (3U):
        {
            result = e_TE_DDMA_TEST_NOCHIRP;
            break;
        }
        default:
        {
            result = e_TE_DDMA_INVALID;
            break;
        }
    }

    return result;
}

/*=====================================================================================================================*/

TE_PRPCGenMode_e rfeFinalPCGenModeMapper(rfePRPCGenMode_t finalPCGenMode)
{
    TE_PRPCGenMode_e result = e_TE_PR_INVALID;

    switch (finalPCGenMode)
    {
        case (RFE_PR_PCGEN_NO_CHANGE):
        {
            result = e_TE_PR_NO_CHANGE;
            break;
        }
        case (RFE_PR_PCGEN_REPLACE_MSB_WITH_QPSK):
        {
            result = e_TE_PR_REPLACE_MSB_WITH_QPSK;
            break;
        }
        case (RFE_PR_PCGEN_ADD_QPSK_TO_MSB):
        {
            result = e_TE_PR_ADD_QPSK_TO_MSB;
            break;
        }
        default:
        {
            result = e_TE_PR_INVALID;
            break;
        }
    }

    return result;
}

/*=====================================================================================================================*/

rfe_error_t Tef82xxErrToRfeErrorMapper(BC_ERRCODE errCode)
{
	uint32_t fe = (uint32_t)RfeDrvStateFrontendIdGet();
	rfe_error_t error;
	uint32_t errorGroup = errCode >> 16U;

	if(errCode == BC_ERR_NOERROR)
	{
		error = rfe_error_none_e;
	}
	else if(errorGroup == (uint32_t)GROUP_FIVE)
	{
		error = (rfe_error_t)(((uint32_t)errCode | RFE_ERROR_RFE_INTERNAL_ERROR_BIT) | (fe << 8U));
	}
	else
	{
		error =  (rfe_error_t)((((uint32_t)errCode + ERR_GROUP_OFFSET ) | RFE_ERROR_RFE_INTERNAL_ERROR_BIT) | (fe << 8U));
	}

	return error;
}

/*=====================================================================================================================*/

rfe_chirpSequenceIndex_t rfeChirpSequenceMapper(uint8_t chirpSequence)
{
	rfe_chirpSequenceIndex_t chirpSequenceIndex = rfe_chirpSequenceIndex_invalid_e;

	switch (chirpSequence)
	{
		case 0U:
		{
			chirpSequenceIndex = rfe_chirpSequenceIndex_0_e;
			break;
		}
		case 1U:
		{
			chirpSequenceIndex = rfe_chirpSequenceIndex_1_e;
			break;
		}
		case 2U:
		{
			chirpSequenceIndex = rfe_chirpSequenceIndex_2_e;
			break;
		}
		case 3U:
		{
			chirpSequenceIndex = rfe_chirpSequenceIndex_3_e;
			break;
		}
		case 4U:
		{
			chirpSequenceIndex = rfe_chirpSequenceIndex_4_e;
			break;
		}
		case 5U:
		{
			chirpSequenceIndex = rfe_chirpSequenceIndex_5_e;
			break;
		}
		case 6U:
		{
			chirpSequenceIndex = rfe_chirpSequenceIndex_6_e;
			break;
		}
		case 7U:
		{
			chirpSequenceIndex = rfe_chirpSequenceIndex_7_e;
			break;
		}
		default:
		{
			chirpSequenceIndex = rfe_chirpSequenceIndex_invalid_e;
			break;
		}
	}
	return chirpSequenceIndex;
}

/*=====================================================================================================================*/

rfe_chirpProfileIndex_t rfeChirpProfileMapper(uint8_t chirpProfile)
{
	rfe_chirpProfileIndex_t chirpProfileIndex = rfe_chirpProfileIndex_invalid_e;

	switch (chirpProfile)
	{
		case 0U:
		{
			chirpProfileIndex = rfe_chirpProfileIndex_0_e;
			break;
		}
		case 1U:
		{
			chirpProfileIndex = rfe_chirpProfileIndex_1_e;
			break;
		}
		case 2U:
		{
			chirpProfileIndex = rfe_chirpProfileIndex_2_e;
			break;
		}
		case 3U:
		{
			chirpProfileIndex = rfe_chirpProfileIndex_3_e;
			break;
		}
		case 4U:
		{
			chirpProfileIndex = rfe_chirpProfileIndex_4_e;
			break;
		}
		case 5U:
		{
			chirpProfileIndex = rfe_chirpProfileIndex_5_e;
			break;
		}
		case 6U:
		{
			chirpProfileIndex = rfe_chirpProfileIndex_6_e;
			break;
		}
		case 7U:
		{
			chirpProfileIndex = rfe_chirpProfileIndex_7_e;
			break;
		}
		default:
		{
			chirpProfileIndex = rfe_chirpProfileIndex_invalid_e;
			break;
		}
	}
	return chirpProfileIndex;
}

/*=====================================================================================================================*/

rfe_txIndex_t rfeTxIndexMapper(uint8_t tx)
{
	rfe_txIndex_t txIndex = rfe_txIndex_invalid_e;

	switch (tx)
	{
		case 0U:
		{
			txIndex = rfe_txIndex_1_e;
			break;
		}
		case 1U:
		{
			txIndex = rfe_txIndex_2_e;
			break;
		}
		case 2U:
		{
			txIndex = rfe_txIndex_3_e;
			break;
		}
		case 3U:
		{
			txIndex = rfe_txIndex_4_e;
			break;
		}
		default:
		{
			txIndex = rfe_txIndex_invalid_e;
			break;
		}
	}
	return txIndex;
}

/*=====================================================================================================================*/

rfeRxLpfCutOff_t rfeRxLpfCutOffMapper(uint8_t rxLpfCutOffFrequency)
{
	rfeRxLpfCutOff_t rxLpfCutOff = RFE_RX_LPF_CUTOFF_INVALID;

	switch (rxLpfCutOffFrequency)
	{
		case 0U:
		{
			rxLpfCutOff = RFE_RX_LPF_CUTOFF_12_5MHZ;
			break;
		}
		case 1U:
		{
			rxLpfCutOff = RFE_RX_LPF_CUTOFF_15MHZ;
			break;
		}
		case 2U:
		{
			rxLpfCutOff = RFE_RX_LPF_CUTOFF_20MHZ;
			break;
		}
		case 3U:
		{
			rxLpfCutOff = RFE_RX_LPF_CUTOFF_25MHZ;
			break;
		}
		case 4U:
		{
			rxLpfCutOff = RFE_RX_LPF_CUTOFF_WIDE;
			break;
		}
		default:
		{
			rxLpfCutOff = RFE_RX_LPF_CUTOFF_INVALID;
			break;
		}
	}
	return rxLpfCutOff;
}

/*=====================================================================================================================*/

rfeRxHpfCutOff_t rfeRxHpfCutOffMapper(uint8_t rxHpfCutOffFrequency)
{
	rfeRxHpfCutOff_t rxHpfCutOff = RFE_RX_HPF_CUTOFF_INVALID;

	switch (rxHpfCutOffFrequency)
	{
		case 0U:
		{
			rxHpfCutOff = RFE_RX_HPF_CUTOFF_100KHZ;
			break;
		}
		case 1U:
		{
			rxHpfCutOff = RFE_RX_HPF_CUTOFF_200KHZ;
			break;
		}
		case 2U:
		{
			rxHpfCutOff = RFE_RX_HPF_CUTOFF_300KHZ;
			break;
		}
		case 3U:
		{
			rxHpfCutOff = RFE_RX_HPF_CUTOFF_400KHZ;
			break;
		}
		case 4U:
		{
			rxHpfCutOff = RFE_RX_HPF_CUTOFF_800KHZ;
			break;
		}
		case 5U:
		{
			rxHpfCutOff = RFE_RX_HPF_CUTOFF_1600KHZ;
			break;
		}
		case 6U:
		{
			rxHpfCutOff = RFE_RX_HPF_CUTOFF_3200KHZ;
			break;
		}
		default:
		{
			rxHpfCutOff = RFE_RX_HPF_CUTOFF_INVALID;
			break;
		}
	}
	return rxHpfCutOff;
}

BOOL ConvertUint8ToBool(uint8_t val)
{
	BOOL result = FALSE;
	if(val != 0U)
	{
		result = TRUE;
	}
	return result;
}

rfeSwBist_InjectToneMode_t InjectToneModeMapper(uint8_t val)
{
	rfeSwBist_InjectToneMode_t injectToneMode = InjectToneMode_Invalid;

	switch(val)
	{
		case 0U:
		{
			injectToneMode = TEF82XX_both_lna_mixer;
			break;
		}
		case 1U:
		{
			injectToneMode = TEF82XX_only_mixer;
			break;
		}
		case 2U:
		{
			injectToneMode = TEF82XX_alternate_lna_mixer;
			break;
		}
		default:
		{
			injectToneMode = InjectToneMode_Invalid;
			break;
		}
	}
	return injectToneMode;
}

rfe_effectiveSamplingFrequency_t EffectiveSamplingFrequencyMapper(uint8_t val)
{
	rfe_effectiveSamplingFrequency_t effectiveSamplingFrequency = rfe_effectiveSamplingFrequency_invalid_e;

	switch(val)
	{
		case 0U:
		{
			effectiveSamplingFrequency = rfe_effectiveSamplingFrequency_40MHz_e;
			break;
		}
		case 1U:
		{
			effectiveSamplingFrequency = rfe_effectiveSamplingFrequency_20MHz_e;
			break;
		}
		case 2U:
		{
			effectiveSamplingFrequency = rfe_effectiveSamplingFrequency_10MHz_e;
			break;
		}
		case 3U:
		{
			effectiveSamplingFrequency = rfe_effectiveSamplingFrequency_5MHz_e;
			break;
		}
		default:
		{
			effectiveSamplingFrequency = rfe_effectiveSamplingFrequency_invalid_e;
			break;
		}
	}
	return effectiveSamplingFrequency;
}

rfe_rxGain_t RxGainMapper(uint8_t val)
{
	rfe_rxGain_t rxGain = rfe_rxGain_invalid_e;

	switch(val)
	{
		case 0U:
		{
			rxGain = rfe_rxGain_25dB_e;
			break;
		}
		case 1U:
		{
			rxGain = rfe_rxGain_28dB_e;
			break;
		}
		case 2U:
		{
			rxGain = rfe_rxGain_31dB_e;
			break;
		}
		case 3U:
		{
			rxGain = rfe_rxGain_34dB_e;
			break;
		}
		case 4U:
		{
			rxGain = rfe_rxGain_37dB_e;
			break;
		}
		case 5U:
		{
			rxGain = rfe_rxGain_40dB_e;
			break;
		}
		case 6U:
		{
			rxGain = rfe_rxGain_43dB_e;
			break;
		}
		case 7U:
		{
			rxGain = rfe_rxGain_46dB_e;
			break;
		}
		default:
		{
			rxGain = rfe_rxGain_invalid_e;
			break;
		}
	}
	return rxGain;
}

rfe_virtualChannel_t VirtualChannelMapper(uint8_t val)
{
	rfe_virtualChannel_t virtualChannel = rfe_virtualChannel_invalid_e;

	switch(val)
	{
		case 0U:
		{
			virtualChannel = rfe_virtualChannel_0_e;
			break;
		}
		case 1U:
		{
			virtualChannel = rfe_virtualChannel_1_e;
			break;
		}
		case 2U:
		{
			virtualChannel = rfe_virtualChannel_2_e;
			break;
		}
		case 3U:
		{
			virtualChannel = rfe_virtualChannel_3_e;
			break;
		}
		default:
		{
			virtualChannel = rfe_virtualChannel_invalid_e;
			break;
		}
	}
	return virtualChannel;
}

SYS_IPNum_e SYS_IPNumMapper(uint8_t val)
{
	SYS_IPNum_e iPNum = e_SYS_INVALID;

	switch(val)
	{
		case 0U:
		{
			iPNum = e_SYS_CC;
			break;
		}
		case 1U:
		{
			iPNum = e_SYS_LVDS;
			break;
		}
		case 2U:
		{
			iPNum = e_SYS_MIPI;
			break;
		}
		case 3U:
		{
			iPNum = e_SYS_INVALID;
			break;
		}
		case 4U:
		{
			iPNum = e_SYS_TE;
			break;
		}
		case 5U:
		{
			iPNum = e_SYS_SC;
			break;
		}
		case 6U:
		{
			iPNum = e_SYS_CAFC;
			break;
		}
		case 7U:
		{
			iPNum = e_SYS_ADC12;
			break;
		}
		case 8U:
		{
			iPNum = e_SYS_ADC34;
			break;
		}
		case 9U:
		{
			iPNum = e_SYS_GBIAS;
			break;
		}
		case 10U:
		{
			iPNum = e_SYS_LOI;
			break;
		}
		case 11U:
		{
			iPNum = e_SYS_INVALID;
			break;
		}
		case 12U:
		{
			iPNum = e_SYS_MCLK;
			break;
		}
		case 13U:
		{
			iPNum = e_SYS_RX1;
			break;
		}
		case 14U:
		{
			iPNum = e_SYS_RX2;
			break;
		}
		case 15U:
		{
			iPNum = e_SYS_RX3;
			break;
		}
		case 16U:
		{
			iPNum = e_SYS_RX4;
			break;
		}
		case 17U:
		{
			iPNum = e_SYS_TX1;
			break;
		}
		case 18U:
		{
			iPNum = e_SYS_TX2;
			break;
		}
		case 19U:
		{
			iPNum = e_SYS_TX3;
			break;
		}
		case 20U:
		{
			iPNum = e_SYS_SSB;
			break;
		}
		case 21U:
		{
			iPNum = e_SYS_GLDO;
			break;
		}
		case 22U:
		{
			iPNum = e_SYS_ATB;
			break;
		}
		case 23U:
		{
			iPNum = e_SYS_OTP;
			break;
		}
		case 24U:
		{
			iPNum = e_SYS_ISM;
			break;
		}
		case 25U:
		{
			iPNum = e_SYS_TEMP_DIGITIZER;
			break;
		}
		case 26U:
		case 27U:
		case 28U:
		case 29U:
		case 30U:
		case 31U:
		case 32U:
		case 33U:
		case 34U:
		case 35U:
		{
			iPNum = e_SYS_INVALID;
			break;
		}
		case 36U:
		{
			iPNum = e_SYS_ADCMC;
			break;
		}
		case 37U:
		{
			iPNum = e_SYS_TXMC;
			break;
		}
		case 38U:
		{
			iPNum = e_SYS_RXMC;
			break;
		}
		default:
		{
			iPNum = e_SYS_INVALID;
			break;
		}
	}
			return iPNum;
}

RX_Gain_Control_e RxGainControlMapper(rfe_rxGain_t val)
{
	RX_Gain_Control_e gainControl = e_RX_GAIN_INVALID;

	switch(val)
	{
		case rfe_rxGain_28dB_e:
		{
			gainControl = e_RX_GAIN_27DB;
			break;
		}
		case rfe_rxGain_31dB_e:
		{
			gainControl = e_RX_GAIN_30DB;
			break;
		}
		case rfe_rxGain_34dB_e:
		{
			gainControl = e_RX_GAIN_33DB;
			break;
		}
		case rfe_rxGain_37dB_e:
		{
			gainControl = e_RX_GAIN_36DB;
			break;
		}
		case rfe_rxGain_40dB_e:
		{
			gainControl = e_RX_GAIN_39DB;
			break;
		}
		case rfe_rxGain_43dB_e:
		{
			gainControl = e_RX_GAIN_42DB;
			break;
		}
		case rfe_rxGain_46dB_e:
		{
			gainControl = e_RX_GAIN_45DB;
			break;
		}
		default:
		{
			gainControl = e_RX_GAIN_INVALID;
			break;
		}
	}
	return gainControl;
}

rfeChirpPllVcoBandwidth_t ChirpPllVcoBandwidthMapper(uint8_t val)
{
	rfeChirpPllVcoBandwidth_t chirpPllVcoBandwidth = RFE_CHIRP_PLL_VCO_BANDWIDTH_INVALID;

	switch(val)
	{
		case 0U:
		{
			chirpPllVcoBandwidth = RFE_CHIRP_PLL_VCO_BANDWIDTH_1GHZ;
			break;
		}
		case 1U:
		{
			chirpPllVcoBandwidth = RFE_CHIRP_PLL_VCO_BANDWIDTH_2GHZ;
			break;
		}
		case 2U:
		{
			chirpPllVcoBandwidth = RFE_CHIRP_PLL_VCO_BANDWIDTH_4GHZ;
			break;
		}
		default:
		{
			chirpPllVcoBandwidth = RFE_CHIRP_PLL_VCO_BANDWIDTH_INVALID;
			break;
		}
	}
	return chirpPllVcoBandwidth;
}

/*******************************************************************************
 * EOF
 ******************************************************************************/





