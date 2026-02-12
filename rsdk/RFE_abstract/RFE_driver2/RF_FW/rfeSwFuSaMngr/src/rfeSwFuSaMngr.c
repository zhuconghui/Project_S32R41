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

#include <stddef.h>
#include "rfeSwFuSaMngr.h"
#include "rfe_sw_driver_state.h"
#include "rfe_sw_cfg_to_tef82xx_map.h"
#include "rfeSwUtils.h"

// LLD
#include "bc_err.h"
#include "bc_ism.h"
#include "reg_es2_ism.h"

/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
 *                                     INTERNAL FUNCTIONS
 ==================================================================================================*/

static void SetTxFusaFaultR1(rfeDriverPersistentMem_t *pDrvState, rfe_error_t* rfe___error___pointer)
{
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		R2M18_TxErrorFlagMaskedStatusUnion_t TxErrorFlagMask;
		BC_ERRCODE  errCode;

		// Read out errors from TX
		errCode = BC_ISM_GetTxErrStatus(e_ISM_GET_MASKED_ERR, NULL, NULL, NULL,
				&TxErrorFlagMask.val_u32 );
		if(errCode == BC_ERR_NOERROR)
		{

			pDrvState->fusaStatistic.fuSaR1FaultCount[rfe_fuSaFault_R1_tempErrorFlagTx1_e] +=
					(uint8_t)(TxErrorFlagMask.bits_st.TempErrorFlagTx1MaskedStatus);
			pDrvState->fusaStatistic.fuSaR1FaultCount[rfe_fuSaFault_R1_tempErrorFlagTx2_e] +=
					(uint8_t)(TxErrorFlagMask.bits_st.TempErrorFlagTx2MaskedStatus);
			pDrvState->fusaStatistic.fuSaR1FaultCount[rfe_fuSaFault_R1_tempErrorFlagTx3_e] +=
					(uint8_t)(TxErrorFlagMask.bits_st.TempErrorFlagTx3MaskedStatus);
			pDrvState->fusaStatistic.fuSaR1FaultCount[rfe_fuSaFault_R1_rfLevelLowErrorFlagTx1_e] +=
					(uint8_t)(TxErrorFlagMask.bits_st.RfLevelLowErrorFlagTx1MaskedStatus);
			pDrvState->fusaStatistic.fuSaR1FaultCount[rfe_fuSaFault_R1_rfLevelLowErrorFlagTx2_e] +=
					(uint8_t)(TxErrorFlagMask.bits_st.RfLevelLowErrorFlagTx2MaskedStatus);
			pDrvState->fusaStatistic.fuSaR1FaultCount[rfe_fuSaFault_R1_rfLevelLowErrorFlagTx3_e] +=
					(uint8_t)(TxErrorFlagMask.bits_st.RfLevelLowErrorFlagTx3MaskedStatus);
			pDrvState->fusaStatistic.fuSaR1FaultCount[rfe_fuSaFault_R1_rfLevelHighErrorFlagTx1_e] +=
					(uint8_t)(TxErrorFlagMask.bits_st.RfLevelHighErrorFlagTx1MaskedStatus);
			pDrvState->fusaStatistic.fuSaR1FaultCount[rfe_fuSaFault_R1_rfLevelHighErrorFlagTx2_e] +=
					(uint8_t)(TxErrorFlagMask.bits_st.RfLevelHighErrorFlagTx2MaskedStatus);
			pDrvState->fusaStatistic.fuSaR1FaultCount[rfe_fuSaFault_R1_rfLevelHighErrorFlagTx3_e] +=
					(uint8_t)(TxErrorFlagMask.bits_st.RfLevelHighErrorFlagTx3MaskedStatus);
		}
		else
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}
	}
}

static void SetRxFusaFaultR1(rfeDriverPersistentMem_t *pDrvState, rfe_error_t* rfe___error___pointer)
{
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		R2M18_RxErrorFlagMaskedStatusUnion_t RxErrorFlagMask;
		BC_ERRCODE  errCode;

		// Read out errors from TX
		errCode = BC_ISM_GetRxErrStatus(e_ISM_GET_MASKED_ERR, NULL, NULL, NULL, NULL,
				&RxErrorFlagMask.val_u32 );
		if(errCode == BC_ERR_NOERROR)
		{
				pDrvState->fusaStatistic.fuSaR1FaultCount[rfe_fuSaFault_R1_loLevelLowErrorFlagRx1_e] +=
						(uint8_t)(RxErrorFlagMask.bits_st.LoLevelLowErrorFlagRx1MaskedStatus);
				pDrvState->fusaStatistic.fuSaR1FaultCount[rfe_fuSaFault_R1_loLevelLowErrorFlagRx2_e] +=
						(uint8_t)(RxErrorFlagMask.bits_st.LoLevelLowErrorFlagRx2MaskedStatus);
				pDrvState->fusaStatistic.fuSaR1FaultCount[rfe_fuSaFault_R1_loLevelLowErrorFlagRx3_e] +=
						(uint8_t)(RxErrorFlagMask.bits_st.LoLevelLowErrorFlagRx3MaskedStatus);
				pDrvState->fusaStatistic.fuSaR1FaultCount[rfe_fuSaFault_R1_loLevelLowErrorFlagRx4_e] +=
						(uint8_t)(RxErrorFlagMask.bits_st.LoLevelLowErrorFlagRx4MaskedStatus);
				pDrvState->fusaStatistic.fuSaR1FaultCount[rfe_fuSaFault_R1_loLevelHighErrorFlagRx1_e] +=
						(uint8_t)(RxErrorFlagMask.bits_st.LoLevelHighErrorFlagRx1MaskedStatus);
				pDrvState->fusaStatistic.fuSaR1FaultCount[rfe_fuSaFault_R1_loLevelHighErrorFlagRx2_e] +=
						(uint8_t)(RxErrorFlagMask.bits_st.LoLevelHighErrorFlagRx2MaskedStatus);
				pDrvState->fusaStatistic.fuSaR1FaultCount[rfe_fuSaFault_R1_loLevelHighErrorFlagRx3_e] +=
						(uint8_t)(RxErrorFlagMask.bits_st.LoLevelHighErrorFlagRx3MaskedStatus);
				pDrvState->fusaStatistic.fuSaR1FaultCount[rfe_fuSaFault_R1_loLevelHighErrorFlagRx4_e] +=
						(uint8_t)(RxErrorFlagMask.bits_st.LoLevelHighErrorFlagRx4MaskedStatus);
		}
		else
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}
	}
}

static void SetChirpFusaFaultR1(rfeDriverPersistentMem_t *pDrvState, rfe_error_t* rfe___error___pointer)
{
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		R2M18_ChirpErrorFlagMaskedStatusUnion_t ChirpErrorFlagMask;
		BC_ERRCODE  errCode;

		// Read out errors from TX
		errCode = BC_ISM_GetChirpErrStatus(e_ISM_GET_MASKED_ERR, NULL, &ChirpErrorFlagMask.val_u32 );
		if(errCode == BC_ERR_NOERROR)
		{
				pDrvState->fusaStatistic.fuSaR1FaultCount[rfe_fuSaFault_R1_tempErrorFlagChirp_e] +=
						(uint8_t)(ChirpErrorFlagMask.bits_st.TempErrorFlagChirpMaskedStatus);
				pDrvState->fusaStatistic.fuSaR1FaultCount[rfe_fuSaFault_R1_vtuneLowErrorFlagChirp_e] +=
						(uint8_t)(ChirpErrorFlagMask.bits_st.VtuneLowErrorFlagChirpMaskedStatus);
				pDrvState->fusaStatistic.fuSaR1FaultCount[rfe_fuSaFault_R1_vtuneHighErrorFlagChirp_e] +=
						(uint8_t)(ChirpErrorFlagMask.bits_st.VtuneHighErrorFlagChirpMaskedStatus);
				pDrvState->fusaStatistic.fuSaR1FaultCount[rfe_fuSaFault_R1_levelLowErrorFlagChirp_e] +=
						(uint8_t)(ChirpErrorFlagMask.bits_st.LevelLowErrorFlagChirpMaskedStatus);
				pDrvState->fusaStatistic.fuSaR1FaultCount[rfe_fuSaFault_R1_levelHighErrorFlagChirp_e] +=
						(uint8_t)(ChirpErrorFlagMask.bits_st.LevelHighErrorFlagChirpMaskedStatus);
		}
		else
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}
	}
}

static void SetMClkLOISMOTPFusaFaultR1(rfeDriverPersistentMem_t *pDrvState, rfe_error_t* rfe___error___pointer)
{
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		R2M18_McLoCcIsmOtpErrorFlagMaskedStatusUnion_t McLoCcIsmOtpErrorFlagMask;
		BC_ERRCODE  errCode;

		// Read out errors from TX
		errCode = BC_ISM_GetMClkLOISMOTPErrStatus(e_ISM_GET_MASKED_ERR, NULL, NULL, NULL, NULL, NULL,
				&McLoCcIsmOtpErrorFlagMask.val_u32 );
		if(errCode == BC_ERR_NOERROR)
		{
				pDrvState->fusaStatistic.fuSaR1FaultCount[rfe_fuSaFault_R1_pllFreqCalErrorFlagMc_e] +=
						(uint8_t)(McLoCcIsmOtpErrorFlagMask.bits_st.PllFreqCalErrorFlagMcMaskedStatus);
				pDrvState->fusaStatistic.fuSaR1FaultCount[rfe_fuSaFault_R1_loiLevelLowErrorFlagInterface_e] +=
						(uint8_t)(McLoCcIsmOtpErrorFlagMask.bits_st.LoiLevelLowErrorFlagInterfaceMaskedStatus);
				pDrvState->fusaStatistic.fuSaR1FaultCount[rfe_fuSaFault_R1_loiLevelHighErrorFlagInterface_e] +=
						(uint8_t)(McLoCcIsmOtpErrorFlagMask.bits_st.LoiLevelHighErrorFlagInterfaceMaskedStatus);
		}
		else
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}
	}
}

static void SetADCFusaFaultR1(rfeDriverPersistentMem_t *pDrvState, rfe_error_t* rfe___error___pointer)
{
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		R2M18_AdcErrorFlagMaskedStatusUnion_t adcErrorFlagMask;
		BC_ERRCODE  errCode;

		// Read out errors from TX
		errCode = BC_ISM_GetADCErrStatus(e_ISM_GET_MASKED_ERR, NULL, NULL,
				&adcErrorFlagMask.val_u32 );
		if(errCode == BC_ERR_NOERROR)
		{
				pDrvState->fusaStatistic.fuSaR1FaultCount[rfe_fuSaFault_R1_hardClippingFlagPersistentAdc1_e] +=
						(uint8_t)(adcErrorFlagMask.bits_st.HardClippingFlagPersistentAdc1MaskedStatus);
				pDrvState->fusaStatistic.fuSaR1FaultCount[rfe_fuSaFault_R1_hardClippingFlagPersistentAdc2_e] +=
						(uint8_t)(adcErrorFlagMask.bits_st.HardClippingFlagPersistentAdc2MaskedStatus);
				pDrvState->fusaStatistic.fuSaR1FaultCount[rfe_fuSaFault_R1_hardClippingFlagPersistentAdc3_e] +=
						(uint8_t)(adcErrorFlagMask.bits_st.HardClippingFlagPersistentAdc3MaskedStatus);
				pDrvState->fusaStatistic.fuSaR1FaultCount[rfe_fuSaFault_R1_hardClippingFlagPersistentAdc4_e] +=
						(uint8_t)(adcErrorFlagMask.bits_st.HardClippingFlagPersistentAdc4MaskedStatus);
		}
		else
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}
	}
}

/******************************************************************************
 *                              PUBLIC FUNCTIONS
 *****************************************************************************/

void rfeFusaFaultStatisticsUpdateTef82xx(rfe_error_t* rfe___error___pointer)
{

	rfeDriverPersistentMem_t *pDrvState = NULL;

	if (*rfe___error___pointer == rfe_error_none_e)
	{
		pDrvState = RfeDrvStateGet();

		SetTxFusaFaultR1(pDrvState, rfe___error___pointer);
		SetRxFusaFaultR1(pDrvState, rfe___error___pointer);
		SetChirpFusaFaultR1(pDrvState, rfe___error___pointer);
		SetMClkLOISMOTPFusaFaultR1(pDrvState, rfe___error___pointer);
		SetADCFusaFaultR1(pDrvState, rfe___error___pointer);


	}
}

void rfeFusaFaultStatisticsResetTef82xx(rfe_error_t* rfe___error___pointer)
{
	uint8_t frontEndId = 0U;
	rfeDriverPersistentMem_t *pDrvState = NULL;
	uint8_t feActual = RfeDrvStateFrontendIdGet();
	uint8_t idx = 0U;

	if(*rfe___error___pointer == rfe_error_none_e)
	{
		for(frontEndId = 0U; frontEndId < RfeDrvStateNoFrontendsGet(); frontEndId++)
		{
			rfeSwUtils_SelectFe(frontEndId);
			pDrvState = RfeDrvStateGet();
			for(idx = 0U; idx < (uint8_t)rfe_fusaFault_R1_size_e; ++idx)
			{
				pDrvState->fusaStatistic.fuSaR1FaultCount[idx] = 0U;
			}
			for(idx = 0U; idx < RFE_FUSA_R1_R2_MASK_UNMASK_FAULT_BYTE_COUNT; ++idx)
			{
				pDrvState->fusaStatistic.fuSaR1R2FaultStatus[idx] = 0U;
			}
			pDrvState->fusaStatistic.r1FaultPromotedToR2 = 0U;
			pDrvState->fusaStatistic.radaCycleCount.chirpSequenceCount = 0U;
			pDrvState->fusaStatistic.radaCycleCount.radarCycleCount = 0U;
		}
		rfeSwUtils_SelectFe(feActual);
	}
}

void rfeGetFusaFaultStatisticsTef82xx(rfeSwFuSaMngr_fuSaFault_t *pFuSaFaults)
{
	rfeDriverPersistentMem_t *pDrvState = NULL;
	uint8_t idx = 0U;

	pDrvState = RfeDrvStateGet();
	for(idx = 0U; idx < (uint8_t)rfe_fusaFault_R1_size_e; ++idx)
	{
		pFuSaFaults->fuSaR1FaultCount[idx] = pDrvState->fusaStatistic.fuSaR1FaultCount[idx];
	}
	pFuSaFaults->r1FaultPromotedToR2 = pDrvState->fusaStatistic.r1FaultPromotedToR2;
}

