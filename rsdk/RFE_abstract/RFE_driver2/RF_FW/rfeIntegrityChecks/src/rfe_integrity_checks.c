/*
* Copyright 2023 NXP
*
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and
* may only be used strictly in accordance with the applicable license terms.  By
* expressly accepting such terms or by downloading, installing, activating and/or
* otherwise using the software, you are agreeing that you have read, and that you
* agree to comply with and are bound by, such license terms.  If you do not agree to
* be bound by the applicable license terms, then you may not retain, install, activate or
* otherwise use the software.
*/


/**********************************************************************************************************************
 *   Project              : S32R41_RFE_FW
 *   Platform             : S32R41
 *********************************************************************************************************************/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include <stdint.h>
#include <stddef.h>
#include "rfe_integrity_checks.h"
#include "rfeHwLink.h"
#include "rfeSwUtils.h"

// LLD
#include "bc_cc.h"
#include "bc_conf.h"
#include "bc_ism.h"
#include "bc_mipi.h"
#include "bc_spi.h"
#include "bc_sys.h"
#include "bc_tx.h"
#include "bc_cafc.h"
#include "reg_es2_te.h"
#include "reg_es2_loi.h"
#include "reg_es2_ism.h"
#include "rfe_sw_driver_state.h"
#include "rfe_sw_cfg_to_tef82xx_map.h"


/*==================================================================================================
*                                    DEFINES AND MACROS
==================================================================================================*/
#define RFE_FIT_DEFAULT_SAFETY_CHECK_TIMEOUT    405U    // 405us is the recommended time-out for tx safety check

/*==================================================================================================
*                                    EXTERNAL SYMBOLS
==================================================================================================*/
// the location of the current communication Front-End if the TEF82XX_CFG_ES2 driver is used
extern uint8_t gTargetDevice;

/*==================================================================================================
*                                    INTERNAL FUNCTION PROTOTYPES
==================================================================================================*/
static rfe_error_t rfeIcCafcTest(uint8_t frontEndId);
static rfe_error_t rfeIcTxSensorTest(uint8_t frontEndID);
static rfe_error_t rfeIcTxCalibStatus(uint8_t frontEndID);
static rfe_error_t rfeIcToggleTest(uint8_t frontEndID, rfe_icGpioSignal_t gpioMask);
static BC_ERRCODE rfeIcChirpStartToggleTestLeader(void);
static BC_ERRCODE rfeIcChirpStartInToggleTest(uint8_t frontEndID);
static BC_ERRCODE rfeIcDisableChirpStartOnFollowers(R2M18_LoopBackTestRegUnion_t *loopBackTest, R2M04_ChirpGlobalControlUnion_t *globalCtrlBackup);
/*==================================================================================================
*                                    EXTERNAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                    LOCAL FUNCTIONS
==================================================================================================*/

/**********************************************************
 * Function to test CAFC
 * This function is really performed only for Leader or Standalone Front-End.
 * For any Follower the return will be rfe_error_none_e and nothing to be performed.
 * AFter this test, the Leader configuration must be reverted to the normal one.
 *
 * Input : frontEndMask         = the ID of the front-end to be tested, as rfe_fitFrontEnd_t value
 *
 * Return :     the result of the execution
 *
 */
static rfe_error_t rfeIcCafcTest(uint8_t frontEndId)
{
    BC_ERRCODE                      errCode = BC_ERR_NOERROR;         // the returned TEF82XX code

    R2M04_ChirpGlobalControlUnion_t ChirpGlblCtrl;

    if(frontEndId == (uint8_t)e_PLF_MASTER)
    {
        errCode = BC_MIPI_EnTransmission(FALSE);    // disable CSI2 data transmission
        if (errCode == BC_ERR_NOERROR)
        {
            // disable the TEF82XX pins
            errCode = BC_CC_ConfigPad(FALSE, e_CC_PADSPEED_HIGH, e_SYS_MCUINT_CHIRPSTART_OUT_PAD);
            if (errCode == BC_ERR_NOERROR)
            {
                // read the current chirp sequence used, to keep the settings
                errCode = BC_SPI_Read(e_SYS_TE, R2M04_CHIRP_GLOBAL_CONTROL_U16, &ChirpGlblCtrl.val_u32);
                if (errCode == BC_ERR_NOERROR)
                {
                    // perform internal TEF82XX CAFC sensor check
                    errCode = BC_SYS_CAFCSensorIntegrityCheck((SYS_ProfID_e)ChirpGlblCtrl.bits_st.Reserved3, 1U);
                }
                // re-enable the TEF82XX pins if no error reported
                if (errCode == BC_ERR_NOERROR)
                {
                    errCode = BC_CC_ConfigPad(TRUE, e_CC_PADSPEED_HIGH, e_SYS_MCUINT_CHIRPSTART_OUT_PAD);
                }
            }
            // re-enable CSI2 data transmission if no error
            if (errCode == BC_ERR_NOERROR)
            {
                errCode = BC_MIPI_EnTransmission(TRUE);
            }
        }
    }

    return Tef82xxErrToRfeErrorMapper(errCode);
}


/**********************************************************
 * Function to test Tx Sensor test
 *
 * Input : frontEndMask         = the ID of the front-end to be tested, as rfe_fitFrontEnd_t value
 *
 * Return :     the result of the execution
 *
 */
static rfe_error_t rfeIcTxSensorTest(uint8_t frontEndID)
{
    BC_ERRCODE errCode = BC_ERR_NOERROR;            // the returned TEF82XX code
    rfeDriverPersistentMem_t *pDrvState = RfeDrvStateWithIdGet(frontEndID);

    if (pDrvState->tef82xxDrvState.enableTxIntegrityCheck == (uint8_t)TRUE)
    {
    	errCode = BC_SYS_TXSensorIntegrityCheck();
    }
    return Tef82xxErrToRfeErrorMapper(errCode);
}


/**********************************************************
 * Function to test Calibration Status
 *
 * Input : frontEndMask         = the ID of the front-end to be tested, as rfe_fitFrontEnd_t value
 *
 * Return :     the result of the execution
 *
 */
static rfe_error_t rfeIcTxCalibStatus(uint8_t frontEndID)
{
    (void)frontEndID;
    BC_ERRCODE errCode = BC_ERR_NOERROR;            // the returned TEF82XX code
    rfeDriverPersistentMem_t *pDrvState = RfeDrvStateWithIdGet(frontEndID);

    if(pDrvState->tef82xxDrvState.sequencesUsesPhaseRotator == (BOOL)TRUE)
    {
		if(frontEndID == (uint8_t)e_PLF_MASTER)
		{
			errCode = BC_CAFC_FastBiasChirpPll();
		}
		if(errCode == BC_ERR_NOERROR)
		{
			// start checking the tx antennas
			errCode = BC_TX_StartTxPRSafetyCheck(e_SYS_TXMC, (BOOL)TRUE, RFE_FIT_DEFAULT_SAFETY_CHECK_TIMEOUT);
		}
    }
    return Tef82xxErrToRfeErrorMapper(errCode);
}


static BC_ERRCODE rfeIcHelperMSToggleTest(R2M18_LoopBackTestRegUnion_t LoopBackTest[RFE_MAX_SUPPORTED_DEVICES], uint32_t testValue)
{
	BC_ERRCODE  errCode = BC_ERR_NOERROR;
	R2M18_LoopBackTestRegUnion_t LoopBackTestReg;
	uint32_t TmpData = 1u;
	uint8_t feIdx;

	rfeSwUtils_SelectFe((uint8_t)rfeFrontEndId_0);
	// set the Direction of data and enable loop back test mode
	LoopBackTestReg.val_u32 = LoopBackTest[(uint32_t)rfeFrontEndId_0].val_u32;
	LoopBackTestReg.bits_st.ReadyIntData = testValue; /* set pin state to test Value */
	errCode = BC_SPI_Write(e_SYS_ISM, R2M18_LOOP_BACK_TEST_REG_U16, LoopBackTestReg.val_u32);

	if (errCode == BC_ERR_NOERROR)
	{
		errCode = BC_SPI_Read(e_SYS_ISM, R2M18_LOOP_BACK_TEST_REG_U16, &TmpData);
		if (((TmpData & 0xFFFFF800u) != (LoopBackTestReg.val_u32 & 0xFFFFF800u)) &&
				(errCode != BC_ERR_NOERROR))
		{
			errCode = BC_ERR_SPI_WRTCHECKFAIL;
		}
	}

	// Test follower chirp start in pin to be equal to testValue
	for(feIdx = (uint8_t)rfeFrontEndId_1; feIdx < RfeDrvStateNoFrontendsGet(); feIdx++)
	{
		if (errCode == BC_ERR_NOERROR)
		{
			rfeSwUtils_SelectFe(feIdx);
			// set the Direction of data and enable loop back test mode
			LoopBackTestReg.val_u32 = LoopBackTest[feIdx].val_u32;
			errCode = BC_SPI_Write(e_SYS_ISM, R2M18_LOOP_BACK_TEST_REG_U16, LoopBackTestReg.val_u32);
		}
		if (errCode == BC_ERR_NOERROR)
		{
			errCode = BC_SPI_Read(e_SYS_ISM, R2M18_LOOP_BACK_TEST_REG_U16, &TmpData);
			if (((TmpData & 0xFFFFF800u) != (LoopBackTestReg.val_u32 & 0xFFFFF800u)) &&
					(errCode != BC_ERR_NOERROR))
			{
				errCode = BC_ERR_SPI_WRTCHECKFAIL;
			}
		}
		if (errCode == BC_ERR_NOERROR)
		{
			errCode = BC_SPI_Read(e_SYS_ISM, R2M18_LOOP_BACK_TEST_REG_U16, &LoopBackTestReg.val_u32);
		}
		// Compare the both result of GPIO input value and ISM register value and it should be same otherwise test failed
		if ((errCode == BC_ERR_NOERROR) && (LoopBackTestReg.bits_st.ChirpStartData != testValue))
		{
			errCode = BC_ERR_ISM_INPUTMODE_TOGGLE_TEST_FAILED;
		}
	}

	return errCode;
}

/**********************************************************
 * Function for chirp start toggle test 
 *
 * Input :
 *
 * Return : the BC_ERRCODE result of the execution 
 *
 */
static BC_ERRCODE rfeIcChirpStartOutToggleTest(uint8_t frontEndID)
{
	BC_ERRCODE  errCode;

	if(frontEndID == 0U)
	{
		errCode = rfeIcChirpStartToggleTestLeader();
	}
	else
	{
		errCode = BC_ISM_InterfaceToggleTest(e_SYS_MCUINT_CHIRPSTART_OUT_PAD , FALSE);
	}
	return errCode;
}

/**********************************************************
 * Function to test digital input/output signals
 *
 * This function is not called in default release. 
 * The function may be usefull for some fusa checks needed by clients. 
 * 
 * Input : frontEndMask         = the ID of the front-end to be tested, as rfe_fitFrontEnd_t value
 *
 * Return :     the result of the execution
 *
 */
static BC_ERRCODE rfeIcChirpStartInToggleTest(uint8_t frontEndID)
{
	BC_ERRCODE  errCode;
    R2M04_ChirpGlobalControlUnion_t globalCtrl, globalCtrlBackup[RFE_MAX_SUPPORTED_DEVICES];

	errCode = BC_SPI_Read(e_SYS_TE, R2M04_CHIRP_GLOBAL_CONTROL_U16, &globalCtrlBackup[frontEndID].val_u32);
	if (errCode == BC_ERR_NOERROR)
	{
		globalCtrl.val_u32 = globalCtrlBackup[frontEndID].val_u32;
		if(globalCtrlBackup[frontEndID].bits_st.ChirpEnable != 0U)
		{
			/* Disable chirp */
			globalCtrl.bits_st.ChirpEnable = 0U;
			errCode = BC_SPI_Write(e_SYS_TE, R2M04_CHIRP_GLOBAL_CONTROL_U16, globalCtrl.val_u32);
		}
		if (errCode == BC_ERR_NOERROR)
		{
			errCode = BC_ISM_InterfaceToggleTest(e_SYS_CHIRPSTART_IN_PAD , TRUE);
		}
		if ((globalCtrlBackup[frontEndID].val_u32 != globalCtrl.val_u32) && (errCode == BC_ERR_NOERROR))
		{
			/* Revert to previously saved global Control register value only if necessary*/
			errCode = BC_SPI_Write(e_SYS_TE, R2M04_CHIRP_GLOBAL_CONTROL_U16, globalCtrlBackup[frontEndID].val_u32);
		}
	}
	return errCode;
}
/**********************************************************
 * Function to test digital input/output signals
 *
 * Input : frontEndMask         = the ID of the front-end to be tested, as rfe_fitFrontEnd_t value
 *
 * Return :     the result of the execution
 *
 */
static rfe_error_t rfeIcToggleTest(uint8_t frontEndID,  rfe_icGpioSignal_t gpioMask)
{
    rfe_error_t rez = rfe_error_ic_wrg_input_params_e;
    BC_ERRCODE  errCode = BC_ERR_NOERROR;      // error code received from the Front-End LLD

    if(((uint16_t)gpioMask > (uint16_t)rfe_ic_gpio_none_e) && ((uint16_t)gpioMask < (uint16_t)rfe_ic_gpio_max_e))
    {
        // first signal tested : CHIRP_START
        if(((uint16_t)gpioMask & (uint16_t)rfe_ic_gpio_chirp_start_in_e) != 0u)
        {
			errCode = rfeIcChirpStartInToggleTest(frontEndID);
        }
        // second test - CHIRP_START_OUT performed only for Leader Front-end
        if((errCode == BC_ERR_NOERROR) && (((uint16_t)gpioMask & (uint16_t)rfe_ic_gpio_chirp_start_out_e) != 0u))
        {
        	errCode = rfeIcChirpStartOutToggleTest(frontEndID);
        }
        // third test - ERROR_N, to be done on all FE
        if ((errCode == BC_ERR_NOERROR) && (((uint16_t)gpioMask & (uint16_t)rfe_ic_gpio_error_n_e) != 0u))
        {
            errCode = BC_ISM_InterfaceToggleTest(e_SYS_ERRORN , FALSE);
        }
        // fourth test - ERROR_RESET, to be done on all FE
        if ((errCode == BC_ERR_NOERROR) && (((uint16_t)gpioMask & (uint16_t)rfe_ic_gpio_error_reset_e) != 0u))
        {
            errCode = BC_ISM_InterfaceToggleTest(e_SYS_ERRORRESET , TRUE);
        }
        // fifth test - TX1IPS
        if ((errCode == BC_ERR_NOERROR) && (((uint16_t)gpioMask & (uint16_t)rfe_ic_gpio_tx1_i_e) != 0u))
        {
            errCode = BC_ISM_InterfaceToggleTest(e_SYS_TX1_I_PS , TRUE);
        }
        // sixth test - TX2IPS
        if ((errCode == BC_ERR_NOERROR) && (((uint16_t)gpioMask & (uint16_t)rfe_ic_gpio_tx2_i_e) != 0u))
        {
            errCode = BC_ISM_InterfaceToggleTest(e_SYS_TX2_I_PS , TRUE);
        }
        // seventh test - TX3IPS
        if ((errCode == BC_ERR_NOERROR) && (((uint16_t)gpioMask & (uint16_t)rfe_ic_gpio_tx3_i_e) != 0u))
        {
            errCode = BC_ISM_InterfaceToggleTest(e_SYS_TX3_I_PS , TRUE);
        }
        // eighth test - TX1QPS
        if ((errCode == BC_ERR_NOERROR) && (((uint16_t)gpioMask & (uint16_t)rfe_ic_gpio_tx1_q_e) != 0u))
        {
            errCode = BC_ISM_InterfaceToggleTest(e_SYS_TX1_Q_PS , TRUE);
        }
        // ninth test - TX2QPS
        if ((errCode == BC_ERR_NOERROR) && (((uint16_t)gpioMask & (uint16_t)rfe_ic_gpio_tx2_q_e) != 0u))
        {
            errCode = BC_ISM_InterfaceToggleTest(e_SYS_TX2_Q_PS , TRUE);
        }
        // tenth test - TX3QPS
        if ((errCode == BC_ERR_NOERROR) && (((uint16_t)gpioMask & (uint16_t)rfe_ic_gpio_tx3_q_e) != 0u))
        {
            errCode = BC_ISM_InterfaceToggleTest(e_SYS_TX3_Q_PS , TRUE);
        }
        rez = Tef82xxErrToRfeErrorMapper(errCode);
    }
    return rez;
}

/**********************************************************
 * Function to test Loi BBD
 *
 * Input :      frontEndID = the ID of the front-end to be tested, as PLF_SPITarget_e value
 *
 * Return :     the result of the execution, adapted to rfe_error_t value
 *
 */
static rfe_error_t rfeIcLoiBBDCheck(uint8_t frontEndID)
{
    rfeDriverPersistentMem_t    *pDrvState = NULL;
    BC_ERRCODE                   errCode = BC_ERR_NOERROR;

    pDrvState = RfeDrvStateGet();
    if (RfeDrvStateConfigurationGet() == rfeFrontEnd_Cascaded_e)
    {
		if(frontEndID == (uint8_t)e_PLF_MASTER)
		{
			// Start Leader check
			if((pDrvState->tef82xxDrvState.loiBbdEn == (BOOL)TRUE) &&
					(pDrvState->tef82xxDrvState.LoIGrounded == (BOOL)FALSE) &&
					(pDrvState->tef82xxDrvState.LoOutGrounded == (BOOL)FALSE))
			{
                // Check LoOutBBD
				errCode = BC_SYS_LoiBBDCheck((BOOL)FALSE, pDrvState->tef82xxDrvState.LoISensitivity, pDrvState->tef82xxDrvState.LoIGrounded,
						pDrvState->tef82xxDrvState.LoOutSensitivity, pDrvState->tef82xxDrvState.LoOutGrounded);
				if(errCode == BC_ERR_NOERROR)
				{
					// Check LoInBBD
					errCode = BC_SYS_LoiBBDCheck((BOOL)TRUE, pDrvState->tef82xxDrvState.LoISensitivity, pDrvState->tef82xxDrvState.LoIGrounded,
							pDrvState->tef82xxDrvState.LoOutSensitivity, pDrvState->tef82xxDrvState.LoOutGrounded);
				}
			}
		}
		else
		{
			// Start Follower check
			// Check only LoInBBD
			if((pDrvState->tef82xxDrvState.loiBbdEn == (BOOL)TRUE) &&
								(pDrvState->tef82xxDrvState.LoIGrounded == (BOOL)FALSE) &&
								(pDrvState->tef82xxDrvState.LoOutGrounded == (BOOL)FALSE))
			{
				errCode = BC_SYS_LoiBBDCheck((BOOL)TRUE, pDrvState->tef82xxDrvState.LoISensitivity, pDrvState->tef82xxDrvState.LoIGrounded,
						pDrvState->tef82xxDrvState.LoOutSensitivity, pDrvState->tef82xxDrvState.LoOutGrounded);
			}
		}
    }
    return Tef82xxErrToRfeErrorMapper(errCode);
}

/**********************************************************
 * Function to test Loi BBD
 *
 * Input :      frontEndID = the ID of the front-end to be tested, as PLF_SPITarget_e value
 *
 * Return :     the result of the execution, adapted to rfe_error_t value
 *
 */
static void rfeIcSetDpmActiveAfterChecks(rfe_error_t *err)
{
	BC_ERRCODE  errCode = BC_ERR_NOERROR;
	uint8_t feIdx;

	if((*err == rfe_error_none_e) && (RfeDrvStateConfigurationGet() == rfeFrontEnd_Cascaded_e))
	{
		for(feIdx = 1; feIdx < RfeDrvStateNoFrontendsGet(); feIdx++)
		{
			if (errCode == BC_ERR_NOERROR)
			{
				rfeSwUtils_SelectFe(feIdx);
				errCode = rfeSwCfgSetDynPowMode(e_DPM_ACTIVE);
			}
		}
		if (errCode == BC_ERR_NOERROR)
		{
			rfeSwUtils_SelectFe((uint8_t)rfeFrontEndId_0);
			errCode = rfeSwCfgSetDynPowMode(e_DPM_ACTIVE);
		}
		if (errCode != BC_ERR_NOERROR)
		{
			*err = Tef82xxErrToRfeErrorMapper(errCode);
		}
	}
}

/**********************************************************
 * Function for toggle test on Leader
 *
 * Input :      
 *
 * Return :     the result BC_ERRCODE value
 *
 */
static BC_ERRCODE rfeIcChirpStartToggleTestLeader(void)
{		
	BC_ERRCODE  					errCode = BC_ERR_NOERROR;
	uint8_t 						feIdx;
	R2M18_LoopBackTestRegUnion_t 	LoopBackTest[RFE_MAX_SUPPORTED_DEVICES] = {0};
	R2M04_ChirpGlobalControlUnion_t globalCtrlBackup[RFE_MAX_SUPPORTED_DEVICES] = {0};

	errCode = rfeIcDisableChirpStartOnFollowers(LoopBackTest, globalCtrlBackup);

	// Set Leader Chirp Start out pin High
	if (errCode == BC_ERR_NOERROR)
	{
		errCode = rfeIcHelperMSToggleTest(LoopBackTest, 1U);
	}
	// Set Leader Chirp Start out pin Low
	if (errCode == BC_ERR_NOERROR)
	{
		errCode = rfeIcHelperMSToggleTest(LoopBackTest, 0U);
	}

	for(feIdx = (uint8_t)rfeFrontEndId_0; feIdx < RfeDrvStateNoFrontendsGet(); feIdx++)
	{
		if (errCode == BC_ERR_NOERROR)
		{
			rfeSwUtils_SelectFe(feIdx);

			/* Disable Loopback test, also in error case. No need to readback the existing register value before clearing LoopBackTestEn since all other bits are don't care once loopback test is disabled */
			LoopBackTest[feIdx].bits_st.LoopBackTestEn = 0U;
			errCode = BC_SPI_Write(e_SYS_ISM, R2M18_LOOP_BACK_TEST_REG_U16, LoopBackTest[feIdx].val_u32);
		}
		if (errCode == BC_ERR_NOERROR)
		{
			errCode = BC_SPI_Read(e_SYS_ISM, R2M18_LOOP_BACK_TEST_REG_U16, &LoopBackTest[feIdx].val_u32);
		}
		if ((errCode == BC_ERR_NOERROR) && (LoopBackTest[feIdx].bits_st.LoopBackTestEn != 0U))
		{
			errCode = BC_ERR_ISM_DISABLE_LB_TOGGLE_TEST_FAILED;

		}
		if (errCode == BC_ERR_NOERROR)
		{
			/* Revert to previously saved global Control register value only if necessary*/
			errCode = BC_SPI_Write(e_SYS_TE, R2M04_CHIRP_GLOBAL_CONTROL_U16, globalCtrlBackup[feIdx].val_u32);
		}
	}
	// Select back the Leader FE for the next pins toggle tests that may be active for the leader
	rfeSwUtils_SelectFe((uint8_t)rfeFrontEndId_0);
	return errCode;
}		

static BC_ERRCODE rfeIcDisableChirpStartOnFollowers(R2M18_LoopBackTestRegUnion_t *loopBackTest, R2M04_ChirpGlobalControlUnion_t *globalCtrlBackup)
{
	BC_ERRCODE 						errCode = BC_ERR_NOERROR;
	uint8_t    						feIdx;
	R2M04_ChirpGlobalControlUnion_t globalCtrl;

	for(feIdx = 0U; feIdx < RfeDrvStateNoFrontendsGet(); feIdx++)
	{
		if (errCode == BC_ERR_NOERROR)
		{
			// This function should inhibit the Slave device to chirp when toggling MCU INT / CHIRP START OUT
			rfeSwUtils_SelectFe(feIdx);
			globalCtrlBackup[feIdx].val_u32 = 0UL;
			errCode = BC_SPI_Read(e_SYS_TE, R2M04_CHIRP_GLOBAL_CONTROL_U16, &globalCtrlBackup[feIdx].val_u32);
			globalCtrl.val_u32 = globalCtrlBackup[feIdx].val_u32;
			if((globalCtrlBackup[feIdx].bits_st.ChirpEnable != 0U) && (errCode == BC_ERR_NOERROR))
			{
				/* Disable chirp */
				globalCtrl.bits_st.ChirpEnable = 0U;
				errCode = BC_SPI_Write(e_SYS_TE, R2M04_CHIRP_GLOBAL_CONTROL_U16, globalCtrl.val_u32);
			}
			if (errCode == BC_ERR_NOERROR)
			{
				errCode = BC_SPI_Read(e_SYS_ISM, R2M18_LOOP_BACK_TEST_REG_U16, &loopBackTest[feIdx].val_u32);
			}
			if (errCode == BC_ERR_NOERROR)
			{
				loopBackTest[feIdx].bits_st.ErrorResetDir = 1U;
				loopBackTest[feIdx].bits_st.ErrorNDir = 0U;
				loopBackTest[feIdx].bits_st.ReadyIntDir = 0U;
				loopBackTest[feIdx].bits_st.ChirpStartDir = 1U;
				loopBackTest[feIdx].bits_st.Tx1IPsDir = 1U;
				loopBackTest[feIdx].bits_st.Tx1QPsDir = 1U;
				loopBackTest[feIdx].bits_st.Tx2IPsDir = 1U;
				loopBackTest[feIdx].bits_st.Tx2QPsDir = 1U;
				loopBackTest[feIdx].bits_st.Tx3IPsDir = 1U;
				loopBackTest[feIdx].bits_st.Tx3QPsDir = 1U;

				/* enable Loopback test, this applies also above set IO directions to Baracuda */
				loopBackTest[feIdx].bits_st.LoopBackTestEn = 1U;
			}
		}
	}
	return errCode;
}
/*==================================================================================================
*                                    GLOBAL FUNCTIONS
==================================================================================================*/
/*****************************************************************************
 * @brief   Call for a Fault Injection Tests sequence
 * @detail  The function performs the requested set of tests for the requested number of Front-Ends
 *          in the quickest possible succession.
 *
 * @param[in]   frontEnd                = the requested front-end to be tested
 * @param[in]   integrityCheckMask      = tests to be performed, as a single mask
 * @param[in]   gpioMask                = GPIO mask to be checked, used only if toggle test is required to be performed
 * @param[in]   rfe___error___pointer   = pointer to the error location to be returned
 *                                        if all functions succeed, pointed value will be rfe_error_none_e
 *                                        else a specific error will be set :
 *                                         rfe_error_fit_wrg_input_params_e = at least one of frontEndMask,
 *                                              integrityCheckMask or gpioMask parameters are incorrect
 *                                         the error reported by the Front-End LLD, mapped to the RFE 2.0 errors
 */
void rfeIcTest(uint8_t frontEndId, rfe_icFaultInjectionTest_t integrityCheckMask,
                rfe_icGpioSignal_t gpioMask, uint8_t lastCycleSequence, rfe_error_t *rfe___error___pointer)
{
    uint32_t    testID;                     	// the test mask
    BC_ERRCODE  bcErrCode = BC_ERR_NOERROR; 	// TEF82xx LLD error returned 

    if((*rfe___error___pointer == rfe_error_none_e) && (integrityCheckMask == rfe_ic_test_none_e))
    {
        *rfe___error___pointer = rfe_error_ic_wrg_input_params_e;
    }
    if(*rfe___error___pointer == rfe_error_none_e)
    {
        // disable first the GPIO interrupts if necessary
        bcErrCode = rfeSwCfgSetDynPowMode(e_NO_DPM_ACTIVE);
        if(bcErrCode != BC_ERR_NOERROR)
        {
            *rfe___error___pointer = Tef82xxErrToRfeErrorMapper(bcErrCode);
        }
        for(testID = (uint8_t)rfe_ic_cafc_test_e; testID < (uint8_t)rfe_ic_max_test_e; testID = testID << 1u)
        {
            if(*rfe___error___pointer != rfe_error_none_e)
            {
                break;                                  // stop the loop execution if error received
            }
            if(((uint32_t)integrityCheckMask & testID) == (uint8_t)rfe_ic_test_none_e)
            {
                continue;                               // the current test in the loop is not required to be tested
            }
            switch(testID)
            {
                case (uint8_t)rfe_ic_cafc_test_e:
                    *rfe___error___pointer = rfeIcCafcTest(frontEndId);
                    break;
                case (uint8_t)rfe_ic_tx_sensor_test_e:
                    *rfe___error___pointer = rfeIcTxSensorTest(frontEndId);
                    break;
                case (uint8_t)rfe_ic_tx_calib_status_e:
                    if(lastCycleSequence == (uint8_t)TRUE)
                    {
                        *rfe___error___pointer = rfeIcTxCalibStatus(frontEndId);
                    }
                    break;
                case (uint8_t)rfe_ic_loi_bbd_test_e:
                    *rfe___error___pointer = rfeIcLoiBBDCheck(frontEndId);
                    break;
                default:                                // normally rfe_ic_toggle_test_e
                    *rfe___error___pointer = rfeIcToggleTest(frontEndId, gpioMask);
                    break;
            }
        }
        // On last frontend tested reactivate dynamic power mode
        if (frontEndId == (RfeDrvStateNoFrontendsGet() - 1U))
        {
            rfeIcSetDpmActiveAfterChecks(rfe___error___pointer);
        }
    }
    setSwError(rfe___error___pointer);
}
