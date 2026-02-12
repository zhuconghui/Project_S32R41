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
 *                                         INCLUDES
 ==================================================================================================*/
#include <stddef.h>
#include <string.h>

#include <rfe_sw_cfg_tef82xx.h>
#include <rfe_sw_cfg_update.h>
#include "rfeSwCfgMngr.h"
#include "rfeSwInit.h"
#include "rfeSwMainFsm.h"
#include "rfeHwLink.h"

#include "rfe_debug.h"
#include "rfe_sw_driver_state.h"

/*==================================================================================================
 *                                      GLOBAL VARIABLES
==================================================================================================*/
static bool keepTxTransmissionEnabled;
static bool enableClockRetuning;
static bool configParamCrossCheckEnable;
static uint8_t pendingUpdateCount;

/*==================================================================================================
 *                                          TYPES
 ==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                      PUBLIC FUNCTIONS
 ==================================================================================================*/

uint8_t* rfeSwCfgMngr_configureBegin(rfe_error_t* rfe___error___pointer)
{    
    uint8_t* pConfig = NULL;
    rfeDriverPersistentMem_t *pDrvState = NULL;

    if(*rfe___error___pointer == rfe_error_none_e)
    {
    	pDrvState = RfeDrvStateGet();
        pConfig = pDrvState->rfeConfig;
        rfeSwMainFsm_triggerEvent( rfeSwMainFsm_event_configurationInvalid_e, rfe___error___pointer);
    }

    return pConfig;
}

void rfeSwCfgMngr_configureEnd(rfe_error_t* rfe___error___pointer)
{
	rfeDriverPersistentMem_t *pDrvState = NULL;
	pDrvState = RfeDrvStateGet();

    (void)rfeSwMainFsm_calcRadarCycleTimingSchedule( pDrvState->rfeConfig, rfe___error___pointer);

    if (*rfe___error___pointer == rfe_error_none_e)
    {
        rfeSwMainFsm_triggerEvent( rfeSwMainFsm_event_configurationPending_e, rfe___error___pointer);
    }
    else
    {
        rfeSwMainFsm_triggerEvent( rfeSwMainFsm_event_configurationInvalid_e, rfe___error___pointer);
#ifdef RFE_DEBUG
        RfeDbgPrintMsg("rfeSwMainFsm_event_configurationInvalid_e");
#endif
    }
}

void rfeSwCfgMngr_distributeConfiguration(rfe_error_t* rfe___error___pointer)
{
	rfeDriverPersistentMem_t *pDrvState = NULL;
	pDrvState = RfeDrvStateGet();
    if (*rfe___error___pointer == rfe_error_none_e)
    {
		rfeSwCfgTef82xxConfig(pDrvState->rfeConfig, rfe___error___pointer);
#ifdef RFE_DEBUG
		if (*rfe___error___pointer != rfe_error_none_e)
		{
			RfeDbgPrintMsg("Frontend Frame Config Error %d\n", *rfe___error___pointer);
		}
		else
		{
			if (gRfeDebugLevel <= e_rfe_debug_level_bc)
			{
				RfeDbgPrintMsg("Frontend Frame Config Done!\n");
			}
		}
#endif
    }
}

uint16_t rfeSwCfgMngr_updatePush(const rfeSwCfgMngr_update_t* pUpdates, uint8_t updateCount,
    rfe_error_t* rfe___error___pointer)
{
	uint16_t radarCC = 0U;

	if(*rfe___error___pointer == rfe_error_none_e)
	{
	    radarCC = rfeSwCfgUpdatePush(pUpdates, updateCount, rfe___error___pointer);
	}
	return radarCC;
}

bool rfeSwCfgMngr_applyParamUpdates(rfe_error_t* rfe___error___pointer)
{

	bool updatesApplied = false;

	if(*rfe___error___pointer == rfe_error_none_e)
	{
		updatesApplied = (rfeSwCfgApplyParamUpdates(rfe___error___pointer) == TRUE) ? true : false;
	}

	return updatesApplied;
}

void rfeSwCfgMngr_clearParamUpdates(rfe_error_t* rfe___error___pointer)
{
    if(*rfe___error___pointer == rfe_error_none_e)
    {
        pendingUpdateCount = 0U;
    }
}

void rfeSwCfgMngr_init(rfe_error_t* rfe___error___pointer)
{
    rfeSwCfgMngr_clearParamUpdates( rfe___error___pointer);
    if(*rfe___error___pointer == rfe_error_none_e)
    {
        keepTxTransmissionEnabled = false;
        configParamCrossCheckEnable = true;
        enableClockRetuning = false;
    }
}

bool rfeSwCfgMngr_getKeepTxTransmissionEnabled(void)
{
    return keepTxTransmissionEnabled;
}

bool rfeSwCfgMngr_isClockRetuningEnabled(void)
{
    return enableClockRetuning;
}

void rfeSwCfgMngr_testSetParam(rfe_testParam_t testParam, uint32_t value, rfe_error_t* rfe___error___pointer)
{
    (void)testParam;
    (void)value;
    (void)rfe___error___pointer;
}






















          










