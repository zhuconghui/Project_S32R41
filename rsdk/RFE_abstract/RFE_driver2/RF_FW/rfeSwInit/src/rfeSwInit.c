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
 *                                        INCLUDE FILES
 ==================================================================================================*/

// Tools
#include "typedefs.h"
#include "rfe_sw_cfg_to_tef82xx_map.h"
#include "rfe_debug.h"
#include "rfeSwDynamicTables.h"

#include "rfeSwInit.h"
#include "rfe_types.h"

#include "rfeApiFsm.h"
#include "rfeHwLink.h"
#include "rfe_sw_status_tef82xx.h"
#include "rfeSwUtils.h"

// BC LLD
#include "bc_cc.h"
#include "bc_sys.h"
#include "bc_otp.h"
#include "bc_spi.h"
#include "bc_adc.h"
#include "bc_alg.h"
#include "reg_es2_mclk.h"
#include "reg_es2_cc.h"
// FSM
#include "rfe_sw_driver_state.h"
#include "rfeSwCfgMngr.h"
#include "rfe_sw_cfg_tef82xx.h"

/*==================================================================================================
 *                                       LOCAL MACROS
 ==================================================================================================*/
// Magic value to discriminate between ES2 and ES2.1 for TEF82XX
#define RFE_TEF82XX_ES2_LIMIT           0x232U          // equivalent for 2*0x100 + 50

/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
 ==================================================================================================*/

/*==================================================================================================
 *                                      LOCAL VARIABLES
 ==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL VARIABLES
 ==================================================================================================*/


/*==================================================================================================
 *                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/**
 * \brief This function performs initialization of software only units that requires no hardware access.
 *
 * \details This function performs initialization of software only units that requires no hardware access.
 *
 * \pre NIL
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success rfeError_error_none_e is returned
 *
 * \return NIL
 *
 * \post NIL
 *
 * \ingroup NIL
 */
static void rfeSwInit_step_2_initSwOnlyUnits(rfe_error_t* rfe___error___pointer);

/**
 * \brief This function initializes hw units used by Tef82xx LLD.
 *
 * \details
 *
 * \pre All steps prior to this step in rfeSwInit_initialize should be completed successfully.
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success rfeError_error_none_e is returned
 *
 * \return NIL
 *
 * \post NIL
 *
 * \ingroup NIL
 */
static void rfeSwInit_step_3_initHwUnits(rfe_error_t* rfe___error___pointer);

/**
 * \brief This function initializes TEF82xx using the LLD API.
 *
 * \pre All steps prior to this step in rfeSwInit_initialize should be completed successfully.
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success rfeError_error_none_e is returned
 *
 * \return NIL
 *
 * \post NIL
 *
 * \ingroup NIL
 */
static void rfeSwInit_step_4_init82xxLld(rfe_error_t* rfe___error___pointer);
// Function used to get fe id in LLD format
static PLF_SPITarget_e rfeSwInit_getBcTarget(uint32_t frontEndId);
// Function used to do the TEH82xx initialization
static void te82xxFrontendInit(uint32_t rfeFrontEndId, rfe_error_t *rfe___error___pointer);
// Function used to enable TEH82xx IPs
static void setTef82xxDefaultIPs(SYS_IPList_t *tefAppConfig);
// Function used to verify chip version and read unique ID from OTP
static void rfeSwInit_storeTef82xxInfo(rfeDriverPersistentMem_t *pDrvState, rfe_error_t *rfe___error___pointer);
/*==================================================================================================
 *                                       LOCAL FUNCTIONS
==================================================================================================*/
static PLF_SPITarget_e rfeSwInit_getBcTarget(uint32_t frontEndId)
{
	PLF_SPITarget_e bcTargetDevice;

	switch (frontEndId)
	{
		case (uint32_t)rfeFrontEndId_0:
			bcTargetDevice = e_PLF_MASTER;
			break;
		case (uint32_t)rfeFrontEndId_1:
			bcTargetDevice = e_PLF_SLAVE1;
			break;
		case (uint32_t)rfeFrontEndId_2:
			bcTargetDevice = e_PLF_SLAVE2;
			break;
		case (uint32_t)rfeFrontEndId_3:
			bcTargetDevice = e_PLF_SLAVE3;
			break;
		default :
			bcTargetDevice = e_PLF_SPITARGET_INVALID;
			break;
	}

	return bcTargetDevice;
}
/*==================================================================================================*/
static BC_ERRCODE SetCorrectAdcLdoValue(void)
{
	BC_ERRCODE errCode = BC_ERR_NOERROR;
	R2M0C_XoPllLdoControlUnion_t xoPllLdoControl;
	R2M00_LdoControlUnion_t ldoControl;

	errCode = BC_SPI_Read(e_SYS_MCLK, R2M0C_XO_PLL_LDO_CONTROL_U16, &xoPllLdoControl.val_u32);
	if(errCode == BC_ERR_NOERROR)
	{
		errCode = BC_SPI_Read(e_SYS_CC, R2M00_LDO_CONTROL_U16, &ldoControl.val_u32);
	}
	if(errCode == BC_ERR_NOERROR)
	{
		ldoControl.bits_st.LdoSelVoutAdc = xoPllLdoControl.bits_st.XoLdoVout;
		errCode = BC_SPI_WriteCheck(e_SYS_CC, R2M00_LDO_CONTROL_U16, ldoControl.val_u32);
	}
	return errCode;
}
/*==================================================================================================*/
static void rfeSwInit_step_2_initSwOnlyUnits(rfe_error_t* rfe___error___pointer)
{
    rfeDriverPersistentMem_t *pDrvState;
    uint8_t	             	 feIdx;

    if (RfeDrvStateConfigurationGet() == rfeFrontEnd_Single_e)
    {
    	// single
    	rfeSwUtils_SelectFe((uint8_t)rfeFrontEndId_0);
        pDrvState = RfeDrvStateGet();
        RfeDrvStateDefaultInit(pDrvState);
        pDrvState->frontendMode = RFE_STANDALONE;
        pDrvState->frontendId = (uint32_t)rfeFrontEndId_0;
    }
    else
    {
    	for(feIdx = 0; feIdx < RfeDrvStateNoFrontendsGet(); feIdx++)
    	{
    		rfeSwUtils_SelectFe(feIdx);
			pDrvState = RfeDrvStateGet();
			RfeDrvStateDefaultInit(pDrvState);
			if (feIdx == ((uint8_t)rfeFrontEndId_0))
			{
				pDrvState->frontendMode = RFE_CASCADING_LEADER;
			}
			else
			{
				pDrvState->frontendMode = RFE_CASCADING_FOLLOWER;
			}
			pDrvState->frontendId = feIdx;
    	}
    }
    rfeSwCfgMngr_init( rfe___error___pointer);

}
/*==================================================================================================*/
static void rfeSwInit_step_3_initHwUnits(rfe_error_t* rfe___error___pointer)
{
	uint32_t	 feIdx;

	if(*rfe___error___pointer == rfe_error_none_e)
	{
		// GPIO
		RfeHwGpioInit();

#ifdef RFE_DEBUG
		RfeInitDebug(rfe___error___pointer);
		if (gRfeDebugLevel == e_rfe_debug_level_all)
		{
			RfeDbgPrintMsg("Start RFE FW on M7_1\n");
			RfeDbgPrintMsg("rfeSwMainFsm_mainState_initializing: func start\n");
		}
#endif
		// SPI
		if(*rfe___error___pointer == rfe_error_none_e)
		{
			for(feIdx = 0; feIdx < RfeDrvStateNoFrontendsGet(); feIdx++)
			{
				RfeHwSpiInitialize(feIdx, rfe___error___pointer);
			}
		}

		// Init timers
		RfeHwTimersInit(rfe___error___pointer);

		// TODO: Init BC error N interrupt if necessary
	}
}
/*==================================================================================================*/
static void setTef82xxDefaultIPs(SYS_IPList_t *tefAppConfig)
{
	// Enable all IPs
	tefAppConfig->CC = TRUE;
	tefAppConfig->LVDS = FALSE; // LVDS not supported in RFE abstract
	tefAppConfig->MIPI = TRUE;
	tefAppConfig->TE = TRUE;
	tefAppConfig->SC = TRUE;
	tefAppConfig->CAFC = TRUE;
	tefAppConfig->ADC12 = TRUE;
	tefAppConfig->ADC34 = TRUE;
	tefAppConfig->GBIAS = TRUE;
	/// RSNum:1004505  Enable LO Interface
	tefAppConfig->LOI = TRUE;
	tefAppConfig->MCLK = TRUE;
	tefAppConfig->RX1 = TRUE;
	tefAppConfig->RX2 = TRUE;
	tefAppConfig->RX3 = TRUE;
	tefAppConfig->RX4 = TRUE;
	tefAppConfig->TX1 = TRUE;
	tefAppConfig->TX2 = TRUE;
	tefAppConfig->TX3 = TRUE;
	tefAppConfig->GLDO = TRUE;
	tefAppConfig->ATB = FALSE;
	tefAppConfig->OTP = TRUE;
	tefAppConfig->ISM = TRUE;
	tefAppConfig->CHIRP5GMODE = TRUE;
	tefAppConfig->PR = TRUE;
	tefAppConfig->LOIN = TRUE;
	tefAppConfig->LOOUT = TRUE;
}
/*==================================================================================================*/
static void rfeSwInit_storeTef82xxInfo(rfeDriverPersistentMem_t *pDrvState, rfe_error_t *rfe___error___pointer)
{
	BC_ERRCODE     errCode = BC_ERR_NOERROR;
	OTP_ChipInfo_t chipInfo;
	uint32_t       wtNumber, ftNumber;

	if(*rfe___error___pointer == rfe_error_none_e)
	{
		// Get TEF82XX Chip info and compute unique id
		errCode = BC_OTP_GetChipInfo(&chipInfo);
		if (errCode == BC_ERR_NOERROR)
		{
			errCode = BC_ALG_CalculateCRC32((uint8_t *)&(chipInfo), sizeof(OTP_ChipInfo_t), 0xdeadc0deUL, &(pDrvState->uniqueId) );
		}
		if(errCode != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = rfeSwUtils_SetError(Tef82xxErrToRfeErrorMapper(errCode), (uint8_t)(pDrvState->frontendId));
		}
		if(*rfe___error___pointer == rfe_error_none_e)
		{
			// Check TEF82XX sample version is supported
			wtNumber = ((uint32_t)chipInfo.WT_TP_Version_Major * 0x100u) + (uint32_t)chipInfo.WT_TP_Version_Minor;
			ftNumber = ((uint32_t)chipInfo.FT_TP_Version_Major * 0x100u) + (uint32_t)chipInfo.FT_TP_Version_Minor;
			if(!((wtNumber >= RFE_TEF82XX_ES2_LIMIT) && (ftNumber >= RFE_TEF82XX_ES2_LIMIT)))
			{
				// Sample is ES2
				*rfe___error___pointer = rfeSwUtils_SetError(rfe_error_sys_FE_chip_es2_not_supported, (uint8_t)rfeFrontEndId_0);
#ifdef RFE_DEBUG
				RfeDbgPrintMsg("ES2.0 not supported!\n");
#endif
			}
		}
	}
}	
/*==================================================================================================*/
static void te82xxFrontendInit(uint32_t rfeFrontEndId, rfe_error_t *rfe___error___pointer)
{
	BC_ERRCODE      		errCode = BC_ERR_NOERROR;
	uint8_t 				retry = 0U;
	SYS_IPList_t    		tefAppConfig;
	PLF_SPITarget_e 		bcTargetDevice;
	BOOL					isFollower = FALSE;
	ADC_BackGroundCal_t 	bgCalParam;
	rfeDriverPersistentMem_t *pDrvState = NULL_PTR;

	if (*rfe___error___pointer == rfe_error_none_e)
	{
		// Enable all IPs
		setTef82xxDefaultIPs(&tefAppConfig);

		bgCalParam.AutoCalibrateAtPON = TRUE;
		bgCalParam.AutoSyncSequencer = TRUE;
		bgCalParam.EnCalibrateLSBWeights = TRUE;
		bgCalParam.EnContinuousBGCalibration = TRUE;
		bgCalParam.EnInterleavedCalibration = TRUE;
		bgCalParam.PowerSaveBGCalibrationWeights = 1U;

		// Follower initialization
		rfeSwUtils_SelectFe((uint8_t)rfeFrontEndId); // must be done for proper SPI selection
		pDrvState = RfeDrvStateGet();

		if (pDrvState->frontendMode == RFE_CASCADING_FOLLOWER)
		{
			tefAppConfig.CAFC = FALSE;
			tefAppConfig.SC = FALSE;
			isFollower = TRUE;
		}
		bcTargetDevice = rfeSwInit_getBcTarget(rfeFrontEndId);
		errCode = BC_CC_SetAppConfigMS(&tefAppConfig, bcTargetDevice);
		if (errCode == BC_ERR_NOERROR)
		{
			// Try to init TEF82xx
			// We do CALIBRATION_TIMEOUT_RETRIES because of the ADC calibration issue
			do
			{
				if (pDrvState->frontendMode == RFE_STANDALONE)
				{
					errCode = BC_SYS_Init();
				}
				else
				{
					errCode = BC_SYS_InitMasterSlaveMode(isFollower);
				}
				retry++;
			} 
			while ((errCode == BC_ERR_ADC_CALIBRATIONTIMEOUT) && (retry < (uint8_t) CALIBRATION_TIMEOUT_RETRIES));
		}
		if (errCode == BC_ERR_NOERROR)
		{
			errCode = SetCorrectAdcLdoValue();
		}
		if (errCode == BC_ERR_NOERROR)
		{
			errCode = BC_ADC_ConfigBackgroundCal(e_SYS_ADC12, FALSE, &bgCalParam);
		}
		if (errCode == BC_ERR_NOERROR)
		{
			errCode = BC_ADC_ConfigBackgroundCal(e_SYS_ADC34, FALSE, &bgCalParam);
		}
#ifdef RFE_DEBUG
		if (gRfeDebugLevel == e_rfe_debug_level_all)
		{
			if (errCode != BC_ERR_NOERROR)
			{
				RfeDbgPrintMsg("TEF82xx FrontEnd Id %d init error: 0x%x\n", rfeFrontEndId, errCode);
			}
			else
			{
				RfeDbgPrintMsg("TEF82xx FrontEnd Id %d init done!\n", rfeFrontEndId);
			}
		}
#endif
		if(errCode != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = rfeSwUtils_SetError(Tef82xxErrToRfeErrorMapper(errCode), (uint8_t)rfeFrontEndId);
		}
		rfeSwInit_storeTef82xxInfo(pDrvState, rfe___error___pointer);	
	}
}

static void rfeSwInit_step_4_init82xxLld(rfe_error_t* rfe___error___pointer)
{
	uint32_t		feIdx;

	if(*rfe___error___pointer == rfe_error_none_e)
	{
		for(feIdx = (uint32_t)rfeFrontEndId_0; feIdx < RfeDrvStateNoFrontendsGet(); feIdx++)
		{
			te82xxFrontendInit(feIdx, rfe___error___pointer);
		}
		if(*rfe___error___pointer == rfe_error_none_e)
		{
			rfeFusaFaultStatisticsResetTef82xx(rfe___error___pointer);
		}
	}
}

/*==================================================================================================
 *                                      GLOBAL FUNCTIONS
 ==================================================================================================*/
void rfeSwInit_initialize(rfe_error_t* rfe___error___pointer)
{
    if(*rfe___error___pointer == rfe_error_none_e)
    {
        //Step 1 init Core
        //initialization core is done by the startup software outside this function. Therefore no function is required.

        //This function performs initialization of software only units that requires no hardware access.
        rfeSwInit_step_2_initSwOnlyUnits( rfe___error___pointer);

        //This function initializes HW units SPI/GPIO/STM.
        rfeSwInit_step_3_initHwUnits( rfe___error___pointer);

        //This function initializes TEF82xx lowlevel driver.
        rfeSwInit_step_4_init82xxLld( rfe___error___pointer);
    }
}
