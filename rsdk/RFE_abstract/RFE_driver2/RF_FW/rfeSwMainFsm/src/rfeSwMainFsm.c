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

#include <string.h>
#include <stddef.h>
#include <stdlib.h>

#include "rfeSwUtils.h"
#include "rfe_sw_status_tef82xx.h"

#include "rfe_types.h"
#include "rfeSwMainFsm.h"
#include "rfeSwMainFsm_internal.h"
#include "rfe_error.h"

#include "rfe_debug.h"

#include "rfeApiFsm.h"
#include "rfeHwLink.h"
#include "rfe_cmd_server.h"

#include "rfe_blob_access.h"
#include "rfeSwCfgMngr.h"
#include "rfeSwInit.h"
#include "rfeSwFuSaMngr.h"
#include "rfe_sw_driver_state.h"
#include "rfeSwBist.h"
#include "rfe_integrity_checks.h"
#include "rfeSwContinuousWave.h"
#include "rfeSwDynamicTables.h"

#include "rfe_sw_calib_tef82xx.h"
#include "rfe_sw_cfg_tef82xx.h"
#include "rfe_sw_mon_tef82xx.h"
#include "rfe_sw_cfg_to_tef82xx_map.h"

// TEF82XX LLD
#include "bc_sys.h"
#include "bc_te.h"
#include "bc_mipi.h"


/******************************************************************************
 *                              DEFINES
 *****************************************************************************/
#define DEFAULT_PIN_TOGGLE_TEST (rfe_ic_gpio_chirp_start_out_e | rfe_ic_gpio_error_n_e)

/******************************************************************************
 *                              TYPES
 *****************************************************************************/

/**
 * The main state table
 */
static const rfeSwMainFsm_stateTableEntry_t stateTable_main[RFE_SW_MAIN_FSM_MAIN_STATE_COUNT] =
{
    [(uint8_t)rfeSwMainFsm_mainState_initializing_e]                  = { &rfeSwMainFsm_mainState_initializing,         (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_DONT_CHECK_FOR_CMDS,   (uint8_t)rfe_state_busy_e },
    [(uint8_t)rfeSwMainFsm_mainState_waitingForSync_e]                = { &rfeSwMainFsm_mainState_waitingForSync,       (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_DONT_CHECK_FOR_CMDS,   (uint8_t)rfe_state_busy_e },
    [(uint8_t)rfeSwMainFsm_mainState_initialized_e]                   = { NULL_PTR,                                     (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_CONFIGURE |
                                                                                                                        (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_GET_TIME |
                                                                                                                        (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_GET_VERSION |
                                                                                                                        (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_TEST_SET_PARAM |
                                                                                                                        (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_MONITOR_READ |
                                                                                                                        (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_GET_FUSA_FAULTS |
                                                                                                                        (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_GET_FUSA_FAULTSTATISTICS |
                                                                                                                        (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_TEST_GET_INTERNAL_ERROR |
                                                                                                                        (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_SET_FE_ID |
                                                                                                                        (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_REG_DUMP |
                                                                                                                        (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_CONFIGURE_INTERRUPT |
                                                                                                                        (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_GET_FE_ID,             (uint8_t)rfe_state_initialized_e },
    [(uint8_t)rfeSwMainFsm_mainState_configuring_e]                   = { &rfeSwMainFsm_mainState_configuring,          (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_DONT_CHECK_FOR_CMDS,   (uint8_t)rfe_state_busy_e },
    [(uint8_t)rfeSwMainFsm_mainState_configured_e]                    = { NULL_PTR,                                     (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_CONFIGURE |
                                                                                                                        (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_RADAR_CYCLE_START |
                                                                                                                        (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_GET_TIME |
                                                                                                                        (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_GET_VERSION |
                                                                                                                        (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_MONITOR_READ |
                                                                                                                        (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_GET_BIST_ZEROHOUR_REFERENCEDATA |
                                                                                                                        (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_UPDATE_PUSH |
                                                                                                                        (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_TEST_CONTINUOUS_WAVE_TRANSMISSION_START |
                                                                                                                        (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_TEST_SET_PARAM |
                                                                                                                        (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_GET_FUSA_FAULTS |
                                                                                                                        (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_GET_FUSA_FAULTSTATISTICS |
                                                                                                                        (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_TEST_GET_INTERNAL_ERROR |
                                                                                                                        (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_REG_DUMP |
                                                                                                                        (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_CONFIGURE_INTERRUPT |
                                                                                                                        (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_SET_FE_ID |
                                                                                                                        (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_GET_FE_ID,             (uint8_t)rfe_state_configured_e },
    [(uint8_t)rfeSwMainFsm_mainState_startRadarCycles_e]              = { &rfeSwMainFsm_mainState_startRadarCycles,     (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_DONT_CHECK_FOR_CMDS,   (uint8_t)rfe_state_busy_e },
    [(uint8_t)rfeSwMainFsm_mainState_radarCycles_e]                   = { &rfeSwMainFsm_mainState_radarCycles,          (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_DONT_CHECK_FOR_CMDS,   (uint8_t)rfe_state_busy_e },
    [(uint8_t)rfeSwMainFsm_mainState_testContinuousWaveTransmission_e]= { NULL_PTR,                                     (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_TEST_CONTINUOUS_WAVE_TRANSMISSION_STOP |
                                                                                                                        (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_GET_TIME |
                                                                                                                        (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_MONITOR_READ,          (uint8_t)rfe_state_testContinuousWaveTransmission_e },
    [(uint8_t)rfeSwMainFsm_mainState_fuSaFault_e]                     = { &rfeSwMainFsm_mainState_fuSaFault,            (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_GET_FUSA_FAULTS |
                                                                                                                        (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_GET_FUSA_FAULTSTATISTICS |
                                                                                                                        (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_GET_VERSION |
                                                                                                                        (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_TEST_GET_INTERNAL_ERROR |
                                                                                                                        (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_REG_DUMP |
                                                                                                                        (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_SET_FE_ID |
                                                                                                                        (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_GET_FE_ID,             (uint8_t)rfe_state_fuSaFault_e }
};

/**
 * The radar cycle state table
 */
static const rfeSwMainFsm_stateTableEntry_t stateTable_radarCycle[RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_COUNT] =
{
    [(uint8_t)rfeSwMainFsm_radarCycleState_begin_e]               = { &rfeSwMainFsm_radarCyclesState_begin,                 (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_DONT_CHECK_FOR_CMDS,   (uint8_t)rfe_state_busy_e },
    [(uint8_t)rfeSwMainFsm_radarCycleState_startOffset_e]         = { NULL_PTR,                                             (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_DONT_CHECK_FOR_CMDS,   (uint8_t)rfe_state_busy_e },
    [(uint8_t)rfeSwMainFsm_radarCycleState_powerOn_e]             = { &rfeSwMainFsm_radarCyclesState_powerOn,               (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_DONT_CHECK_FOR_CMDS,   (uint8_t)rfe_state_busy_e },
    [(uint8_t)rfeSwMainFsm_radarCycleState_initChirpSequence_e]   = { &rfeSwMainFsm_radarCyclesState_initChirpSequence,     (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_DONT_CHECK_FOR_CMDS,   (uint8_t)rfe_state_busy_e },
    [(uint8_t)rfeSwMainFsm_radarCycleState_recalibration_e]       = { &rfeSwMainFsm_radarCyclesState_recalibration,         (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_DONT_CHECK_FOR_CMDS,   (uint8_t)rfe_state_busy_e },
    [(uint8_t)rfeSwMainFsm_radarCycleState_chirpSequence_e]       = { &rfeSwMainFsm_radarCyclesState_chirpSequence,         (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_DONT_CHECK_FOR_CMDS,   (uint8_t)rfe_state_busy_e },
    [(uint8_t)rfeSwMainFsm_radarCycleState_monitorsAndMetadata_e] = { &rfeSwMainFsm_radarCyclesState_monitorsAndMetadata,   (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_DONT_CHECK_FOR_CMDS,   (uint8_t)rfe_state_busy_e },
    [(uint8_t)rfeSwMainFsm_radarCycleState_bist_e]                = { &rfeSwMainFsm_radarCyclesState_bist,                  (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_DONT_CHECK_FOR_CMDS,   (uint8_t)rfe_state_busy_e },
    [(uint8_t)rfeSwMainFsm_radarCycleState_powerOff_e]            = { &rfeSwMainFsm_radarCyclesState_powerOff,              (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_DONT_CHECK_FOR_CMDS,   (uint8_t)rfe_state_busy_e },
    [(uint8_t)rfeSwMainFsm_radarCycleState_idle_e]                = { NULL_PTR,                                             (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_RADAR_CYCLE_STOP |
                                                                                                                            (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_GET_TIME |
                                                                                                                            (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_GET_NEXT_RADAR_CYCLE_START_TIME |
                                                                                                                            (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_SET_NEXT_RADAR_CYCLE_START_TIME |
                                                                                                                            (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_MONITOR_READ |
                                                                                                                            (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_UPDATE_PUSH |
                                                                                                                            (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_GET_FUSA_FAULTS |
                                                                                                                            (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_TEST_GET_INTERNAL_ERROR |
                                                                                                                            (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_SET_FE_ID |
                                                                                                                            (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_GET_FE_ID,             (uint8_t)rfe_state_radarCycleIdle_e },
    [(uint8_t)rfeSwMainFsm_radarCycleState_cmdExecutionBuffer_e]  = { NULL_PTR,                                             (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_DROP_ALL_CMDS,         (uint8_t)rfe_state_busy_e },
    [(uint8_t)rfeSwMainFsm_radarCycleState_configUpdate_e]        = { &rfeSwMainFsm_radarCyclesState_configUpdate,          (uint32_t)RFE_SW_MAIN_FSM_CMD_SELECT_DONT_CHECK_FOR_CMDS,   (uint8_t)rfe_state_busy_e }
};

/**
 * This macro defines the main state transition count
 */
#define RFE_SW_MAIN_FSM_MAIN_STATE_TRANSITION_COUNT               ( 15UL )

/**
 * The main state transition table
 */
static const rfeSwMainFsm_stateTransition_t stateTransitionTable_main[RFE_SW_MAIN_FSM_MAIN_STATE_TRANSITION_COUNT] =
{
    {(uint8_t)rfeSwMainFsm_event_stateTaskFinished_e,               (uint8_t)rfeSwMainFsm_mainState_initializing_e,                  (uint8_t)rfeSwMainFsm_mainState_waitingForSync_e },
    {(uint8_t)rfeSwMainFsm_event_stateTaskFinished_e,               (uint8_t)rfeSwMainFsm_mainState_waitingForSync_e,                (uint8_t)rfeSwMainFsm_mainState_initialized_e },
    {(uint8_t)rfeSwMainFsm_event_stateTaskFinished_e,               (uint8_t)rfeSwMainFsm_mainState_configuring_e,                   (uint8_t)rfeSwMainFsm_mainState_configured_e },
    {(uint8_t)rfeSwMainFsm_event_stateTaskFinished_e,               (uint8_t)rfeSwMainFsm_mainState_startRadarCycles_e,              (uint8_t)rfeSwMainFsm_mainState_radarCycles_e },
    {(uint8_t)rfeSwMainFsm_event_stateTaskFinished_e,               (uint8_t)rfeSwMainFsm_mainState_radarCycles_e,                   (uint8_t)rfeSwMainFsm_mainState_configured_e },
    {(uint8_t)rfeSwMainFsm_event_configurationPending_e,            (uint8_t)rfeSwMainFsm_mainState_initialized_e,                   (uint8_t)rfeSwMainFsm_mainState_configuring_e },
    {(uint8_t)rfeSwMainFsm_event_configurationPending_e,            (uint8_t)rfeSwMainFsm_mainState_configured_e,                    (uint8_t)rfeSwMainFsm_mainState_configuring_e },
    {(uint8_t)rfeSwMainFsm_event_startRadarCycles_e,                (uint8_t)rfeSwMainFsm_mainState_configured_e,                    (uint8_t)rfeSwMainFsm_mainState_startRadarCycles_e },
    {(uint8_t)rfeSwMainFsm_event_stopRadarCycles_e,                 (uint8_t)rfeSwMainFsm_mainState_radarCycles_e,                   (uint8_t)rfeSwMainFsm_mainState_configured_e },
    {(uint8_t)rfeSwMainFsm_event_startContinuousWaveTransmission_e, (uint8_t)rfeSwMainFsm_mainState_configured_e,                    (uint8_t)rfeSwMainFsm_mainState_testContinuousWaveTransmission_e },
    {(uint8_t)rfeSwMainFsm_event_stopContinuousWaveTransmission_e,  (uint8_t)rfeSwMainFsm_mainState_testContinuousWaveTransmission_e,(uint8_t)rfeSwMainFsm_mainState_configured_e },
    {(uint8_t)rfeSwMainFsm_event_configurationInvalid_e,            (uint8_t)rfeSwMainFsm_mainState_initialized_e,                   (uint8_t)rfeSwMainFsm_mainState_initialized_e },
    {(uint8_t)rfeSwMainFsm_event_configurationInvalid_e,            (uint8_t)rfeSwMainFsm_mainState_configured_e,                    (uint8_t)rfeSwMainFsm_mainState_initialized_e },
    {(uint8_t)rfeSwMainFsm_event_configurationInvalid_e,            (uint8_t)rfeSwMainFsm_mainState_radarCycles_e,                   (uint8_t)rfeSwMainFsm_mainState_initialized_e },
    {(uint8_t)rfeSwMainFsm_event_configurationIncomplete_e,         (uint8_t)rfeSwMainFsm_mainState_configuring_e,                   (uint8_t)rfeSwMainFsm_mainState_initialized_e } // Type
};

// Radar cycle start parameters
static uint16_t radarCycleStopCount = 0U;
static uint32_t radarCycleStartTime = 0UL;
static bool radarCycleIsScheduled = false;
// setNextRadarCycleStartTime parameters
static int32_t radarCycleStartTimeOffset = 0;

// FSM information
static uint8_t mainState;
static uint8_t nextMainState;
static uint8_t currentChirpSequenceIndex;
static bool cmdServerSynced = false;
static bool skipTimeCheck = false;
static bool lastSequenceInCycle = false;

// Counters
static uint16_t radarCycleCount;
static uint16_t chirpSequenceCount;

// Store the error for API report
static rfe_error_t storedSwError = rfe_error_none_e;

// Test controls
#ifdef RFE_DEBUG
static bool bypassWaits = true;
#else
static bool bypassWaits = false;
#endif
/******************************************************************************
 *                           STATIC INLINE FUNCTIONS
 *****************************************************************************/

static inline void rfeSwMainFsm_sharedDataWrite(rfeSwMainFsm_sharedParameter_t param, uint16_t value,
        rfe_error_t* rfe___error___pointer)
{
    if ( cmdServerSynced )
    {
        rfeCmdServer_sharedDataWrite((uint32_t)param, value, rfe___error___pointer);
    }
    else
    {
        // Cmd server not yet initialized
    }
}

static inline void rfeSwMainFsm_shareState(rfe_state_t state, rfe_error_t* rfe___error___pointer)
{
    static rfe_state_t previousSharedState = rfe_state_busy_e;

    if ( state != previousSharedState )
    {
        rfeSwMainFsm_sharedDataWrite(rfeSwMainFsm_sharedParameter_state_e, (uint16_t)state, rfe___error___pointer);
        previousSharedState = state;
    }
    else
    {
        // Cmd server not yet initialized
    }
}

/******************************************************************************
 *                           STATIC FUNCTIONS PROTOTIPES
 *****************************************************************************/

static void rfeSwMainFsm_CheckCmd( rfeSwMainFsm_radarCycleState_t stateW, rfe_error_t *rfe___error___pointer);

static void rfeSwMainFsm_CallStateFunc( rfeSwMainFsm_radarCycleState_t stateW, rfe_error_t *rfe___error___pointer);

static uint32_t rfeSwMainFsm_GetStateEndTime(rfeSwMainFsm_radarCycleState_t stateW);

static rfeSwMainFsm_radarCycleState_t rfeSwMainFsm_ChangeState( rfeSwMainFsm_radarCycleState_t stateW, uint32_t currentStateEndTime, rfe_error_t *rfe___error___pointer);

static _Bool rfeSwMainFsm_CheckStateTimeOut( uint32_t currentStateEndTime, rfeSwMainFsm_radarCycleState_t stateW, rfe_error_t *rfe___error___pointer);

static void rfeSwMainFsm_ErrorCheck(rfe_error_t *rfe___error___pointer);

static void rfeSwMain_PrepareChirping(rfe_error_t* rfe___error___pointer);

static void rfeSwMain_PostChirping(rfe_error_t *rfe___error___pointer);

static void rfeSwMain_StartChirpSeq(rfe_error_t* rfe___error___pointer);
/******************************************************************************
 *                           STATIC FUNCTIONS
 *****************************************************************************/

static uint8_t getErrorNStatus(void)
{
    // ErrorNS 0 indicates error state
    // ErrorN pin is active low
    uint32_t frontEndId;
    uint8_t errorN = 1;

    for(frontEndId = 0U; frontEndId < RfeDrvStateNoFrontendsGet(); frontEndId++)
    {
		RfeHwGpioGet(frontEndId, e_ERRORN, &errorN);
		if (errorN == 0U)
        {
            break;
        }
    }
	return errorN;
}

static void rfeSwMainFsm_ErrorCheck(rfe_error_t *rfe___error___pointer)
{
    uint8_t errorNValue;

    // Read ErrorN pin for Tef82xx ISM
    errorNValue = getErrorNStatus();
    // FUSA SW Errors ( if not masked) --> Always go to fusa error state
    // System sw errors -> Always go to fusa error state
    // ISM Errors --> Only go to fusa error state after rfe_configure() has been called, to allow masking of errors in initialized state.
    if (((*rfe___error___pointer != rfe_error_none_e) ||
            ((errorNValue == 0U) && (mainState > (uint8_t) rfeSwMainFsm_mainState_initialized_e)))
            && (mainState != (uint8_t) rfeSwMainFsm_mainState_fuSaFault_e))
    {
#ifdef RFE_DEBUG
        uint8_t fe = (uint8_t)(*rfe___error___pointer >> 8U) & 0x0FU;
        RfeDbgPrintMsg("\nfeId %u rfeError = 0x%X\nerrorNValue = %d\n\n", fe, ((*rfe___error___pointer) & ~RFE_ERROR_RFE_INTERNAL_ERROR_BIT) & ~(1UL<<8u), errorNValue);
#endif
        // Log the system error
        storedSwError = *rfe___error___pointer;
        // Prepare response for get fusa error cmd
        setSwError(rfe___error___pointer);
        // Clear the error
        *rfe___error___pointer = rfe_error_none_e;
        nextMainState = (uint8_t) rfeSwMainFsm_mainState_fuSaFault_e;
        rfeSwMainFsm_shareState((rfe_state_t) stateTable_main[nextMainState].sharedState, rfe___error___pointer);
    }
    else
    {
        // No error
    }
}

static void rfeSwMain_PrepareChirping(rfe_error_t* rfe___error___pointer)
{
    BC_ERRCODE   errCode = BC_ERR_NOERROR;
    uint8_t     feIdx;

    if (rfe_error_none_e == *rfe___error___pointer)
    {
    	rfeSwUtils_SelectFe((uint8_t) rfeFrontEndId_0);
        errCode = CpmWaDpmEnable(TRUE);
        if (errCode == BC_ERR_NOERROR)
        {
            errCode = CpmWaRxEnable(TRUE);
        }
        if (errCode == BC_ERR_NOERROR)
        {
            errCode = TxPhaseWa1SsbEnable(TRUE);
        }
        // Enable ADC Background calibration
        if ((errCode == BC_ERR_NOERROR) && (lastSequenceInCycle))
        {
            errCode = AdcBkgrdCalibEnable(TRUE);
        }
        if (RfeDrvStateConfigurationGet() == rfeFrontEnd_Cascaded_e)
        {
            for (feIdx = 1; feIdx < RfeDrvStateNoFrontendsGet(); feIdx++)
            {
                if (errCode == BC_ERR_NOERROR)
                {
                    rfeSwUtils_SelectFe(feIdx);
                    errCode = CpmWaDpmEnable(TRUE);
                }
                if (errCode == BC_ERR_NOERROR)
                {
                    errCode = CpmWaRxEnable(TRUE);
                }
                if (errCode == BC_ERR_NOERROR)
                {
                    errCode = TxPhaseWa1SsbEnable(TRUE);
                }
                // Enable ADC Background calibration
                if ((errCode == BC_ERR_NOERROR) && (lastSequenceInCycle))
                {
                    errCode = AdcBkgrdCalibEnable(TRUE);
                }
            }
        }
        if (errCode != BC_ERR_NOERROR)
        {
            *rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
        }
    }
}

static void rfeSwMain_PostChirping(rfe_error_t *rfe___error___pointer)
{
    BC_ERRCODE 	errCode;
    uint8_t 	feIdx;

    if (rfe_error_none_e == *rfe___error___pointer)
    {
        // Enable Dynamic Power Mode
        // Set ADC in dynamic power mode per sequence
        errCode = CpmWaDpmEnable(FALSE);
        if (RfeDrvStateConfigurationGet() == rfeFrontEnd_Cascaded_e)
        {
            for (feIdx = 1; feIdx < RfeDrvStateNoFrontendsGet(); feIdx++)
            {
                if (errCode == BC_ERR_NOERROR)
                {
                    rfeSwUtils_SelectFe(feIdx);
                    errCode = CpmWaDpmEnable(FALSE);
                }
            }
            if (errCode == BC_ERR_NOERROR)
            {
                rfeSwUtils_SelectFe((uint8_t) rfeFrontEndId_0);
            }
        }
        if (errCode == BC_ERR_NOERROR)
        {
            errCode = BC_TE_WaitForReady();
        }
#ifdef RFE_DEBUG
        if (errCode != BC_ERR_NOERROR)
        {
            RfeDbgPrintMsg("BC_TE_WaitForReady timeout. Errcode %d\n", errCode);
        }
#endif
        if (errCode == BC_ERR_NOERROR)
        {
            errCode = TxPhaseWa1SsbEnable(FALSE);
        }
        if (errCode == BC_ERR_NOERROR)
        {
            errCode = CpmWaRxEnable(FALSE);
        }
        if (RfeDrvStateConfigurationGet() == rfeFrontEnd_Cascaded_e)
        {
            for (feIdx = 1; feIdx < RfeDrvStateNoFrontendsGet(); feIdx++)
            {
                if (errCode == BC_ERR_NOERROR)
                {
                    rfeSwUtils_SelectFe(feIdx);
                    errCode = TxPhaseWa1SsbEnable(FALSE);
                }
                if (errCode == BC_ERR_NOERROR)
                {
                    errCode = TxPhaseWa1SsbEnable(FALSE);
                }
                if (errCode == BC_ERR_NOERROR)
                {
                    errCode = CpmWaRxEnable(FALSE);
                }
            }
        }
        if (errCode != BC_ERR_NOERROR)
        {
            *rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
        }
    }
}


static void rfeSwMain_ResetTxPrDDMA(rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE   errCode = BC_ERR_NOERROR;
	uint8_t      feIdx;
	TE_DDMAMod_e ddmaMode;

	rfeDriverPersistentMem_t *pDrvState;

	for(feIdx = (uint8_t)rfeFrontEndId_0; feIdx < RfeDrvStateNoFrontendsGet(); feIdx++)
	{
		if (rfe_error_none_e == *rfe___error___pointer)
		{
			rfeSwUtils_SelectFe(feIdx);
			pDrvState = RfeDrvStateGet();
			ddmaMode = (TE_DDMAMod_e)rfeCfg_sequence_getPhaseRotationDdmaMode(pDrvState->rfeConfig, (rfe_chirpSequenceIndex_t)currentChirpSequenceIndex, rfe___error___pointer);
		}
		if ((rfe_error_none_e == *rfe___error___pointer) && (ddmaMode == e_TE_DDMA_FUN_MODE))
		{
			errCode = BC_TE_ResetTxPRDDMA();
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}
	}
}

static void rfeSwMain_StartChirpSeq(rfe_error_t* rfe___error___pointer)
{
    BC_ERRCODE   errCode = BC_ERR_NOERROR;

    // DDMA phase reset before a new sequence is started
    rfeSwMain_ResetTxPrDDMA(rfe___error___pointer);

    if (rfe_error_none_e == *rfe___error___pointer)
    {
    	// Is mandatory to trigger chirping from Leader FE
        rfeSwUtils_SelectFe((uint8_t) rfeFrontEndId_0);
        errCode = rfeSwCfgSetFastSwitch();
        if (errCode == BC_ERR_NOERROR)
        {
        	// Start chirp sequence
        	errCode = BC_TE_StartChirp();
        }
        if (errCode != BC_ERR_NOERROR)
        {
            *rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
        }
    }
}

/******************************************************************************
 *                       PUBLIC FUNCTIONS (RFE INTERNAL)
 *****************************************************************************/

rfeSwMainFsm_mainState_t rfeSwMainFsm_mainFsm(rfeSwMainFsm_mainState_t startState, rfe_error_t* rfe___error___pointer)
{
    mainState = (uint8_t)startState;

    // Call state function
    if ( stateTable_main[mainState].function != NULL )
    {
        stateTable_main[mainState].function( rfe___error___pointer);
    }
    else
    {
        // This state has no function to be called
    }
    // Handle cmds
    if ( stateTable_main[mainState].allowedCmds != RFE_SW_MAIN_FSM_CMD_SELECT_DONT_CHECK_FOR_CMDS )
    {
        rfeSwMainFsm_handleCmds( stateTable_main[mainState].allowedCmds, rfe___error___pointer);
    }
    else
    {
        // We don't check for cmds in this state
    }
    // Error check
    rfeSwMainFsm_ErrorCheck(rfe___error___pointer);
    // Progress state
    mainState = nextMainState;
    return (rfeSwMainFsm_mainState_t)mainState;
}

rfe_radarCycleCount_t rfeSwMainFsm_getRadarCycleCount(bool* pIsRadarCycleActive)
{
#ifdef RFE_DEBUG
    if (gRfeDebugLevel == e_rfe_debug_level_all)
    {
        RfeDbgPrintMsg("rfeSwMainFsm_getRadarCycleCount: func start\n");
    }
#endif
    rfe_radarCycleCount_t radarCycleCountStruct;
    radarCycleCountStruct.radarCycleCount = radarCycleCount;
    radarCycleCountStruct.chirpSequenceCount = chirpSequenceCount;

    if ( pIsRadarCycleActive == NULL )
    {
        // We don't set pIsRadarCycleActive
    }
    else
    {
        *pIsRadarCycleActive = (mainState == (uint8_t)rfeSwMainFsm_mainState_radarCycles_e);
    }

    return radarCycleCountStruct;
}

void rfeSwMainFsm_triggerEvent(rfeSwMainFsm_event_t event, rfe_error_t* rfe___error___pointer)
{
    uint8_t transitionIndex;
    bool validTransition = false;

    if(*rfe___error___pointer == rfe_error_none_e)
    {
        for(transitionIndex = 0U; transitionIndex < RFE_SW_MAIN_FSM_MAIN_STATE_TRANSITION_COUNT; transitionIndex++)
        {
            if(((uint8_t)event == stateTransitionTable_main[transitionIndex].event) && (mainState == stateTransitionTable_main[transitionIndex].srcState))
            {
                nextMainState = stateTransitionTable_main[transitionIndex].dstState;
                validTransition = true;
            }
            else
            {
                // This transition was not been triggered
            }
        }

        if ( validTransition )
        {
            // We should update external state immediately, e.g. within the API, otherwise the
            // control core would see the state change only after some time, which will result
            // in unwanted behavior
            rfeSwMainFsm_shareState((rfe_state_t)stateTable_main[nextMainState].sharedState, rfe___error___pointer);
        }
        else
        {
            // No state transition has been triggered, which means event is not allowed at the current state
            *rfe___error___pointer = rfe_error_mainFsm_eventNotAllowed_e;
        }
    }
}


/******************************************************************************
 *                       PUBLIC FUNCTIONS (API FUNCTIONS)
 *****************************************************************************/

void rfeSwMainFsm_radarCycleStart(uint16_t radarCycleCountParam, bool isScheduled, uint32_t startTime, rfe_error_t* rfe___error___pointer)
{
    radarCycleIsScheduled = isScheduled;
    radarCycleStartTime = startTime;
    radarCycleStopCount = radarCycleCountParam;
    rfeSwMainFsm_triggerEvent ( rfeSwMainFsm_event_startRadarCycles_e, rfe___error___pointer);
}

uint16_t rfeSwMainFsm_radarCycleStop(rfe_error_t* rfe___error___pointer)
{
#ifdef RFE_DEBUG
    if (gRfeDebugLevel == e_rfe_debug_level_all)
    {
        RfeDbgPrintMsg("rfeSwMainFsm_radarCycleStop: func start\n");
    }
#endif
    rfeSwMainFsm_triggerEvent( rfeSwMainFsm_event_stopRadarCycles_e, rfe___error___pointer);
    return radarCycleCount;
}

uint32_t rfeSwMainFsm_getNextRadarCycleStartTime(uint16_t *pRadarCycleCount, rfe_error_t* rfe___error___pointer)
{
    (void)rfe___error___pointer;
    uint32_t radarCycleDuration;

#ifdef RFE_DEBUG
    if (gRfeDebugLevel == e_rfe_debug_level_all)
    {
        RfeDbgPrintMsg("rfeSwMainFsm_getNextRadarCycleStartTime: func start\n");
    }
#endif
    radarCycleDuration = radarCycleTimeSchedule.stateEndTimeTicks[(uint32_t)rfeSwMainFsm_radarCycleState_configUpdate_e -
                                                                           RFE_SW_MAIN_FSM_RADAR_CYCLE_CHIRP_SEQUENCE_LOOP_STATE_COUNT];

    *pRadarCycleCount = radarCycleCount;
    return ( radarCycleStartTime + radarCycleDuration );
}

uint16_t rfeSwMainFsm_setNextRadarCycleStartTime(uint32_t startTime, rfe_error_t* rfe___error___pointer)
{
    uint32_t radarCycleDuration;
    int32_t startTimeOffset;
    int32_t timeAfterLastIdleStartTime;
    int32_t timeRemaining;
    int32_t idleTime;
    int32_t cmdExecBuffTime;
    int32_t cfgUpdateTime;
    /* coverity[cert_int31_c_violation] Value for chirpSequencesPerRadarCycle is obtained from rfeConfig->cfg.radarCycle.chirpSequenceCount, Minimum value = 1, Maximum value = 8 and which is checked in rfeSwCfgMngr, this operations does not wrap */
    uint8_t chirpSeqPerRadarCycleCount = ( chirpSequencesPerRadarCycle - 1U ) ;

#ifdef RFE_DEBUG
    if (gRfeDebugLevel == e_rfe_debug_level_all)
    {
        RfeDbgPrintMsg("rfeSwMainFsm_setNextRadarCycleStartTime: func start\n");
    }
#endif
    if(*rfe___error___pointer == rfe_error_none_e)
    {
        radarCycleDuration = radarCycleTimeSchedule.stateEndTimeTicks[(uint32_t)rfeSwMainFsm_radarCycleState_configUpdate_e - RFE_SW_MAIN_FSM_RADAR_CYCLE_CHIRP_SEQUENCE_LOOP_STATE_COUNT];
        /* coverity[misra_c_2012_rule_10_8_violation] Wrapping calculation is needed for time difference calculation. Unsigned wrapping behavior is well defined and since processors uses 2's complement representation we can safely cast here.*/
        /* coverity[cert_int31_c_violation] Wrapping calculation is needed for time difference calculation. Unsigned wrapping behavior is well defined and since processors uses 2's complement representation we can safely cast here.*/
        /* coverity[cert_int30_c_violation] Wrapping calculation is needed for time difference calculation. Unsigned wrapping behavior is well defined and since processors uses 2's complement representation we can safely cast here.*/        
        startTimeOffset = (int32_t)(startTime - radarCycleStartTime - radarCycleDuration);
        /* coverity[misra_c_2012_rule_10_8_violation] Wrapping calculation is needed for time difference calculation. Unsigned wrapping behavior is well defined and since processors uses 2's complement representation we can safely cast here.*/
        /* coverity[cert_int31_c_violation] Wrapping calculation is needed for time difference calculation. Unsigned wrapping behavior is well defined and since processors uses 2's complement representation we can safely cast here.*/
        /* coverity[cert_int30_c_violation] Wrapping calculation is needed for time difference calculation. Unsigned wrapping behavior is well defined and since processors uses 2's complement representation we can safely cast here.*/        
        timeAfterLastIdleStartTime = (int32_t)(startTime - radarCycleStartTime - radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSeqPerRadarCycleCount][rfeSwMainFsm_radarCycleState_bist_e]);
        /* coverity[misra_c_2012_rule_10_8_violation] Wrapping calculation is needed for time difference calculation. Unsigned wrapping behavior is well defined and since processors uses 2's complement representation we can safely cast here.*/
        /* coverity[cert_int31_c_violation] Wrapping calculation is needed for time difference calculation. Unsigned wrapping behavior is well defined and since processors uses 2's complement representation we can safely cast here.*/
        /* coverity[cert_int30_c_violation] Wrapping calculation is needed for time difference calculation. Unsigned wrapping behavior is well defined and since processors uses 2's complement representation we can safely cast here.*/
        timeRemaining = (int32_t)(startTime - rfeSysTick_getTick( rfe___error___pointer));/* Implicit conversion of startTime - rfeSysTick_getTick() from essential type unsigned 32-bit int to different
                                                                              or narrower essential type signed 32-bit int.To fix this warning int32 typecasting is done*/
        /* coverity[misra_c_2012_rule_10_8_violation]
         * TypeCasting is required  startTimeOffset , timeAfterLastIdleStartTime , timeRemaining  can be -ve
         * TypeCasting is required to fix MISRA rule 10.3
         */
        if ((startTimeOffset > (int32_t)RFE_SW_MAIN_FSM_SET_NEXT_RADAR_CYCLE_START_TIME_OFFSET_MAX) ||
             (timeAfterLastIdleStartTime < (int32_t)RFE_SW_MAIN_FSM_SET_NEXT_RADAR_CYCLE_START_TIME_REMAINING_LAST_IDLE_TIME_MIN) ||
             (timeRemaining < (int32_t)RFE_SW_MAIN_FSM_SET_NEXT_RADAR_CYCLE_START_TIME_REMAINING_TIME_MIN)
        )
        {
            *rfe___error___pointer = rfe_error_api_invalidArgumentValue_e;
        }
        else
        {
            /*Essential type of the left hand operand radarCycleTimeSchedule.stateEndTimeTicks[0U] (unsigned) is not the same as that of the right operand startTimeOffset(signed), To fix typecasting is done  */
            /* coverity[cert_int31_c_violation] Wrapping calculation is needed for time difference calculation. Unsigned wrapping behavior is well defined and since processors uses 2's complement representation we can safely cast here.*/
            idleTime = ( int32_t ) radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[ chirpSeqPerRadarCycleCount ][rfeSwMainFsm_radarCycleState_idle_e] + startTimeOffset;
            /* coverity[cert_int31_c_violation] Wrapping calculation is needed for time difference calculation. Unsigned wrapping behavior is well defined and since processors uses 2's complement representation we can safely cast here.*/
            radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[ chirpSeqPerRadarCycleCount ][ rfeSwMainFsm_radarCycleState_idle_e ] =  ( uint32_t )idleTime;
            /* coverity[cert_int31_c_violation] Wrapping calculation is needed for time difference calculation. Unsigned wrapping behavior is well defined and since processors uses 2's complement representation we can safely cast here.*/
            cmdExecBuffTime = ( int32_t ) radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[ chirpSeqPerRadarCycleCount ][ rfeSwMainFsm_radarCycleState_cmdExecutionBuffer_e ] + startTimeOffset;
            /* coverity[cert_int31_c_violation] Wrapping calculation is needed for time difference calculation. Unsigned wrapping behavior is well defined and since processors uses 2's complement representation we can safely cast here.*/
            radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[ chirpSeqPerRadarCycleCount ][ rfeSwMainFsm_radarCycleState_cmdExecutionBuffer_e ] = ( uint32_t )cmdExecBuffTime;
            /* coverity[cert_int31_c_violation] Wrapping calculation is needed for time difference calculation. Unsigned wrapping behavior is well defined and since processors uses 2's complement representation we can safely cast here.*/
            cfgUpdateTime = ( int32_t ) radarCycleTimeSchedule.stateEndTimeTicks[ ( uint8_t ) rfeSwMainFsm_radarCycleState_configUpdate_e - ( uint8_t ) RFE_SW_MAIN_FSM_RADAR_CYCLE_CHIRP_SEQUENCE_LOOP_STATE_COUNT] + startTimeOffset;
            /* coverity[cert_int31_c_violation] Wrapping calculation is needed for time difference calculation. Unsigned wrapping behavior is well defined and since processors uses 2's complement representation we can safely cast here.*/
            radarCycleTimeSchedule.stateEndTimeTicks[ ( uint8_t ) rfeSwMainFsm_radarCycleState_configUpdate_e - ( uint8_t ) RFE_SW_MAIN_FSM_RADAR_CYCLE_CHIRP_SEQUENCE_LOOP_STATE_COUNT] = ( uint32_t ) cfgUpdateTime;

            // Buffer startTimeOffset to revert it for next radar cycle in #rfeSwMainFsm_radarCycleState_begin_e state
            radarCycleStartTimeOffset = startTimeOffset;
        }
    }

    return radarCycleCount;
}

void rfeMainFsm_continuousWaveTransmissionStart(rfe_chirpProfileIndex_t profileIndex,
        rfe_error_t* rfe___error___pointer)
{
	rfeDriverPersistentMem_t *pDrvState = RfeDrvStateGet();
	uint8_t profileCount = 0U;
#ifdef RFE_DEBUG
    if (gRfeDebugLevel == e_rfe_debug_level_all)
    {
        RfeDbgPrintMsg("rfeMainFsm_continuousWaveTransmissionStart: func start\n");
    }
#endif
    profileCount = rfeCfg_metadata_getChirpProfileCount(pDrvState->rfeConfig, rfe___error___pointer);
    if (((uint8_t)profileIndex) < profileCount)
    {
    	rfeSwContinuousWave_Start( profileIndex, rfe___error___pointer);
    	rfeSwMainFsm_triggerEvent ( rfeSwMainFsm_event_startContinuousWaveTransmission_e, rfe___error___pointer);
    }
    else
    {
    	// Selected profile is not configured
    	*rfe___error___pointer = rfe_error_api_invalidArgumentValue_e;
    }
}

void rfeMainFsm_continuousWaveTransmissionStop(rfe_error_t* rfe___error___pointer)
{
#ifdef RFE_DEBUG
    if (gRfeDebugLevel == e_rfe_debug_level_all)
    {
        RfeDbgPrintMsg("rfeMainFsm_continuousWaveTransmissionStop: func start\n");
    }
#endif
    rfeSwContinuousWave_Stop(rfe___error___pointer);
    rfeSwMainFsm_triggerEvent ( rfeSwMainFsm_event_stopContinuousWaveTransmission_e, rfe___error___pointer);
}

rfe_monitorValues_t* rfeSwMainFsm_monitorRead(rfe_monitorSelect_t monitorSelect,
        rfe_radarCycleCount_t *pRadarCycleCount, rfe_error_t* rfe___error___pointer)
{
    uint8_t frontendIndex = 0;
    rfe_monitorValues_t *monitorValues = rfeMon_getRfeMonitorValues();

#ifdef RFE_DEBUG
    if (gRfeDebugLevel == e_rfe_debug_level_all)
    {
        RfeDbgPrintMsg("rfeSwMainFsm_monitorRead: func start\n");
    }
#endif
    // Store the current front end id set since we are updating it to read temperature from multiple front ends 
    if(*rfe___error___pointer == rfe_error_none_e)
    {
        *pRadarCycleCount = rfeSwMainFsm_getRadarCycleCount( NULL );
    }
    if ((monitorSelect == 0U) ||
        (monitorSelect > RFE_MONITOR_SELECT_ALL) ||
        (((monitorSelect & RFE_MONITOR_SELECT_TEMP_IMMEDIATELY) != 0U) && (mainState == (uint8_t)rfeSwMainFsm_mainState_radarCycles_e)))
    {
        *rfe___error___pointer = rfe_error_api_invalidArgumentValue_e;
    }
    if((*rfe___error___pointer == rfe_error_none_e) && ((monitorSelect & RFE_MONITOR_SELECT_TEMP_IMMEDIATELY) != 0U))
    {

        for (frontendIndex = 0; frontendIndex < RfeDrvStateNoFrontendsGet(); frontendIndex++)
        {
			rfeSwUtils_SelectFe(frontendIndex);
            // Measure and store temperature after chirp
            if (*rfe___error___pointer != rfe_error_none_e)
            {
                break;
            }
            rfeSwMon_getTemperatureMeasurement(&(monitorValues->temperature_immediately[RFE_TEMPERATURE_SENSOR_COUNT * frontendIndex]), rfe___error___pointer);
        }
    }
    return monitorValues;
}

void rfeSwMainFsm_getFuSaFaults(uint8_t *pFuSaFaults, rfe_error_t* rfe___error___pointer)
{
#ifdef RFE_DEBUG
    if (gRfeDebugLevel == e_rfe_debug_level_all)
    {
        RfeDbgPrintMsg("rfeSwMainFsm_getFuSaFaults: func start\n");
    }
#endif
    if ( pFuSaFaults  == NULL )
    {
        *rfe___error___pointer = rfe_error_parameterOutOfRange_e;
}
    else
    {
        // All parameters within range
        rfeFusaStatusTef82xxDeviceStatus( pFuSaFaults, rfe___error___pointer );
    }
}

void rfeSwMainFsm_getFuSaFaultStatistics(rfeSwFuSaMngr_fuSaFault_t *pFuSaFaults, rfe_error_t* rfe___error___pointer)
{
#ifdef RFE_DEBUG
    if (gRfeDebugLevel == e_rfe_debug_level_all)
    {
        RfeDbgPrintMsg("rfeSwMainFsm_getFuSaFaultStatistics: func start\n");
    }
#endif
    if ( pFuSaFaults  == NULL )
    {
        *rfe___error___pointer = rfe_error_parameterOutOfRange_e;
    }
    else
    {
        // All parameters within range
    }
    if(*rfe___error___pointer == rfe_error_none_e)
    {
        pFuSaFaults->radaCycleCount.radarCycleCount = radarCycleCount;
        pFuSaFaults->radaCycleCount.chirpSequenceCount = chirpSequenceCount;
        rfeGetFusaFaultStatisticsTef82xx(pFuSaFaults);
    }
}

uint32_t rfeSwMainFsm_getTime(rfe_error_t* rfe___error___pointer)
{
#ifdef RFE_DEBUG
    if (gRfeDebugLevel == e_rfe_debug_level_all)
    {
        RfeDbgPrintMsg("rfeSwMainFsm_getTime: func start\n");
    }
#endif
    return rfeSysTick_getTick( rfe___error___pointer);
}

/******************************************************************************
 *                              INTERNAL FUNCTIONS
 *****************************************************************************/
static void rfeSwMainFsm_CheckCmd( rfeSwMainFsm_radarCycleState_t stateW, rfe_error_t *rfe___error___pointer)
{
    rfeSwMainFsm_cmdSelect_t allowedCmds;

	// Handle cmds
	if (stateTable_radarCycle[stateW].allowedCmds != RFE_SW_MAIN_FSM_CMD_SELECT_DONT_CHECK_FOR_CMDS)
	{
		if ((radarCycleStopCount != 0U)	&& (radarCycleCount == (radarCycleStopCount - 1U)))
		{
			// Don't allow specific commands in the last radar cycle
			allowedCmds = stateTable_radarCycle[stateW].allowedCmds	& ~(RFE_SW_MAIN_FSM_CMD_SELECT_GET_NEXT_RADAR_CYCLE_START_TIME
																		| RFE_SW_MAIN_FSM_CMD_SELECT_SET_NEXT_RADAR_CYCLE_START_TIME
																		| RFE_SW_MAIN_FSM_CMD_SELECT_UPDATE_PUSH);
		}
		else
		{
			allowedCmds = stateTable_radarCycle[stateW].allowedCmds;
		}
		rfeSwMainFsm_handleCmds(allowedCmds, rfe___error___pointer);
	}
	else
	{
		// We don't check for commands in this state
	}
}

static void rfeSwMainFsm_CallStateFunc( rfeSwMainFsm_radarCycleState_t stateW, rfe_error_t *rfe___error___pointer)
{
	// Call radar cycle sub-state function
	if (stateTable_radarCycle[stateW].function != NULL)
	{
		stateTable_radarCycle[stateW].function(rfe___error___pointer);
	}
	else
	{
		// This state has no function to be called
	}
}

static uint32_t rfeSwMainFsm_GetStateEndTime(rfeSwMainFsm_radarCycleState_t stateW)
{
	uint32_t stateEndTime;

	if ((uint32_t) stateW < RFE_SW_MAIN_FSM_RADAR_CYCLE_CHIRP_SEQUENCE_LOOP_STATE_COUNT)
	{
		stateEndTime = (uint32_t) radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[currentChirpSequenceIndex][(uint8_t) stateW];
	}
	else
	{
		stateEndTime = (uint32_t) radarCycleTimeSchedule.stateEndTimeTicks[(uint32_t) stateW	- RFE_SW_MAIN_FSM_RADAR_CYCLE_CHIRP_SEQUENCE_LOOP_STATE_COUNT];
	}
	return stateEndTime;
}

static rfeSwMainFsm_radarCycleState_t rfeSwMainFsm_ChangeState( rfeSwMainFsm_radarCycleState_t stateW, uint32_t currentStateEndTime, rfe_error_t *rfe___error___pointer)
{
	uint32_t nextStateEndTime;
	uint32_t rfeTime;

	do
	{
#ifdef GET_TIMINGS
#ifdef GPIO_STATES
    	// Use Folower TX3_I pin for state validation on logic probe
    	// use only for validation of profiler
	    RfeHwGpioSet(1U, e_TX3_I_PS, 1U);
	    RfeHwGpioSet(1U, e_TX3_I_PS, 0U);
#endif
        stateDurationEndTime = rfeSysTick_getTick( rfe___error___pointer);
        debugData.timingRecords[debugData.timeRecordsCount].stateTime = abs(stateDurationEndTime - stateDurationStartTime);
        debugData.timingRecords[debugData.timeRecordsCount].state = (uint8_t)stateW;
        debugData.timingRecords[debugData.timeRecordsCount].sequence = (uint8_t) currentChirpSequenceIndex;
        debugData.timingRecords[debugData.timeRecordsCount].radarCycle = (uint16_t) radarCycleCount;
        debugData.timeRecordsCount = (debugData.timeRecordsCount + 1) % MAX_TIME_RECORDS;
        stateDurationStartTime = rfeSysTick_getTick( rfe___error___pointer);
#ifdef GPIO_STATES
    	// Use Folower TX3_I pin for state validation on logic probe
    	// use only for validation of profiler
	    RfeHwGpioSet(1U, e_TX3_I_PS, 1U);
	    RfeHwGpioSet(1U, e_TX3_I_PS, 0U);
#endif
#endif
		// Goto next state
        /* coverity[misra_c_2012_rule_10_3_violation]
         * by type casting left hand state variable be constant and lvalue required as left operand of assignment  */
		stateW = ( ( uint32_t) stateW + 1UL) % RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_COUNT;
		// Update state for APi
		rfeSwMainFsm_shareState((rfe_state_t) stateTable_radarCycle[stateW].sharedState, rfe___error___pointer);
		if ((uint32_t) stateW == RFE_SW_MAIN_FSM_RADAR_CYCLE_CHIRP_SEQUENCE_LOOP_STATE_COUNT)
		{
			// We made an iteration through the chirp sequence loop
            /* coverity[cert_int31_c_violation] Value for chirpSequencesPerRadarCycle is obtained from rfeConfig->cfg.radarCycle.chirpSequenceCount, Minimum value = 1, Maximum value = 8 and which is checked in rfeSwCfgMngr, this operations does not wrap */
			currentChirpSequenceIndex = (currentChirpSequenceIndex + 1U) % chirpSequencesPerRadarCycle;
			if (currentChirpSequenceIndex != 0U)
			{
				// Loop through chirp sequence state-loop again
				stateW = rfeSwMainFsm_radarCycleState_powerOn_e;
			}
			else
			{
				// We go to rfeSwMainFsm_radarCycleState_configUpdate_e state (at the end of radar cycle)
			}
			if (skipTimeCheck)
			{
				// Do not skip timing for next radar sequence
				skipTimeCheck = false;
#ifdef RFE_DEBUG
				if (gRfeDebugLevel <= e_rfe_debug_level_radar_cycle)
				{
					RfeDbgPrintMsg("-->This sequence SKIPED timing check\n");
				}
#endif
				// Compensate for time used for other jobs
				rfeTime = rfeSysTick_getTick( rfe___error___pointer);
				radarCycleStartTime += ((rfeTime - radarCycleStartTime) - currentStateEndTime);
			}
			else
			{
#ifdef RFE_DEBUG
				if (gRfeDebugLevel <= e_rfe_debug_level_radar_cycle)
				{
					RfeDbgPrintMsg("-->Timing check ACTIVE for this sequence\n");
				}
#endif
			}
		}
		else
		{
			if (stateW == rfeSwMainFsm_radarCycleState_begin_e)
			{
				// In next state, we enter a new radar cycle
                /* coverity[cert_int30_c_violation] intended to be wrapping because this reflects the number of radarCycles being executed and it is defined as wrapping counter. Unsigned wrapping behavior is well defined */
				radarCycleCount++;
				rfeSwMainFsm_sharedDataWrite(rfeSwMainFsm_sharedParameter_radarCycleCount_e, radarCycleCount, rfe___error___pointer);
                /* coverity[cert_int30_c_violation] Wrapping calculation is intended. Unsigned wrapping behavior is well defined */
				radarCycleStartTime += currentStateEndTime;
			}
			else
			{
				// Not entering next chirp sequence of radar cycle, state just becomes previous state + 1
			}
		}
		nextStateEndTime = rfeSwMainFsm_GetStateEndTime(stateW);
	}
	// Skip next state if its endTime is the same as that of current state
	while (nextStateEndTime == currentStateEndTime);

	return stateW;
}

static _Bool rfeSwMainFsm_CheckStateTimeOut( uint32_t currentStateEndTime, rfeSwMainFsm_radarCycleState_t stateW, rfe_error_t *rfe___error___pointer)
{
	_Bool stateTimeExpired;
	uint32_t rfeTime;

	rfeTime = rfeSysTick_getTick(rfe___error___pointer);
	stateTimeExpired = (rfeTime - radarCycleStartTime) >= currentStateEndTime;
    // Check if end time of cmdExecutionBuffer is expired
    if ( (stateTimeExpired)
            && (stateW == rfeSwMainFsm_radarCycleState_cmdExecutionBuffer_e)
            && (!skipTimeCheck)
            && (!bypassWaits) )
	{
#ifdef RFE_DEBUG
		RfeDbgPrintMsg(" State %d\n stateTimeExpired  %d\n rfeTime  %d\n radarCycleStartTime  %d\n currentStateEndTime %d\n",
				stateW, stateTimeExpired, rfeTime, radarCycleStartTime,
				currentStateEndTime);
		RfeDbgPrintMsg("Dif %d\n", rfeTime - radarCycleStartTime);
		RfeDbgPrintMsg("Radar cycle %d Seq %d\n", radarCycleCount, chirpSequenceCount);
#endif
		if (*rfe___error___pointer == rfe_error_none_e)
		{
			*rfe___error___pointer = rfe_error_radarCycleFsm_stateEndTimeExceeded_e;
		}
	}
    return stateTimeExpired;
}

rfeSwMainFsm_radarCycleState_t rfeSwMainFsm_radarCycleFsm(rfeSwMainFsm_radarCycleState_t state, rfe_error_t* rfe___error___pointer)
{
    bool stateTimeExpired = false;
    uint32_t currentStateEndTime;
    uint8_t errorNStatus;
    rfeSwMainFsm_radarCycleState_t stateW = state;

#ifdef RFE_DEBUG
    if (gRfeDebugLevel <= e_rfe_debug_level_radar_cycle)
    {
        RfeDbgPrintMsg("rfeSwMainFsm_radarCycleFsm: START!!!\n");
    }
#endif
    if(*rfe___error___pointer == rfe_error_none_e)
    {        
#ifdef GET_TIMINGS
#ifdef GPIO_STATES
    	// Use Folower TX3_I pin for state validation on logic probe
    	// use only for validation of profiler
	    RfeHwGpioSet(1U, e_TX3_I_PS, 1U);
	    RfeHwGpioSet(1U, e_TX3_I_PS, 0U);
#endif
	    debugData.timeRecordsCount = 0;
        stateDurationStartTime = rfeSysTick_getTick( rfe___error___pointer);
#endif
        do
        {
            // Get current state end time
			currentStateEndTime = rfeSwMainFsm_GetStateEndTime(stateW);
            // Call radar cycle sub-state function
			rfeSwMainFsm_CallStateFunc(	stateW, rfe___error___pointer);
            // Handle cmds
			rfeSwMainFsm_CheckCmd( stateW, rfe___error___pointer);
			// Check state timeout
			stateTimeExpired = rfeSwMainFsm_CheckStateTimeOut(currentStateEndTime, stateW, rfe___error___pointer);
			if (*rfe___error___pointer != rfe_error_none_e)
			{
				// If end time of cmdExecutionBuffer is expired or other internal error
				break;
            }
            if (stateW != rfeSwMainFsm_radarCycleState_idle_e)
            {
                // Update state for APi
				stateTimeExpired = true;
			}
			if ((stateTimeExpired) || (bypassWaits))
			{
				stateW = rfeSwMainFsm_ChangeState(stateW, currentStateEndTime, rfe___error___pointer);
                    
				if ((radarCycleStopCount != 0U) &&
					 (radarCycleCount == (radarCycleStopCount - 1U)) &&
					 (currentChirpSequenceIndex == (chirpSequencesPerRadarCycle - 1U)) &&
					 (stateW >= rfeSwMainFsm_radarCycleState_idle_e) &&
					 (stateW < rfeSwMainFsm_radarCycleState_begin_e)
				)
				{
					// We go the last idle state of all radar cycles, we can exit the radar cycle FSM now, we don't want to run the idle state.
					radarCycleCount++;
					rfeSwMainFsm_sharedDataWrite( rfeSwMainFsm_sharedParameter_radarCycleCount_e, radarCycleCount, rfe___error___pointer);
					rfeSwMainFsm_triggerEvent( rfeSwMainFsm_event_stateTaskFinished_e, rfe___error___pointer);
				}
			}
			else
			{
				// State time is not expired, remain in current state (we can only get here in idle state )
			}
            // Check for ErrorN
			errorNStatus = getErrorNStatus();
        } while((*rfe___error___pointer == rfe_error_none_e) && (errorNStatus != 0U) && (nextMainState == (uint8_t)rfeSwMainFsm_mainState_radarCycles_e));

        rfeSwCfgMngr_clearParamUpdates( rfe___error___pointer);

#if (defined(GET_TIMINGS) && defined(RFE_DEBUG))
        for(int i = 0; i < debugData.timeRecordsCount; i++)
        {
            RfeDbgPrintMsg("RadarCycle %u Sequence %u State %u Duration %u\n", debugData.timingRecords[i].radarCycle, debugData.timingRecords[i].sequence, debugData.timingRecords[i].state, debugData.timingRecords[i].stateTime);
        }
#endif        
    }
    return stateW;
}

void rfeSwMainFsm_mainState_initializing(rfe_error_t* rfe___error___pointer)
{
    radarCycleCount             = 0U;
    chirpSequenceCount          = 0U;
    currentChirpSequenceIndex   = 0U;
    rfeSwInit_initialize( rfe___error___pointer);
    rfeSwMainFsm_triggerEvent( rfeSwMainFsm_event_stateTaskFinished_e, rfe___error___pointer);
}

void rfeSwMainFsm_mainState_waitingForSync(rfe_error_t* rfe___error___pointer)
{
#ifdef RFE_DEBUG
    if (gRfeDebugLevel == e_rfe_debug_level_all)
    {
        RfeDbgPrintMsg("rfeSwMainFsm_mainState_waitingForSync: func start\n");
    }
#endif

    cmdServerSynced = rfeCmdServer_sync( rfe___error___pointer);

    if ( cmdServerSynced )
    {
        rfeSwMainFsm_triggerEvent( rfeSwMainFsm_event_stateTaskFinished_e, rfe___error___pointer);
#ifdef RFE_DEBUG
        if (gRfeDebugLevel == e_rfe_debug_level_all)
        {
            RfeDbgPrintMsg("rfeSwMainFsm_mainState_waitingForSync: cmdServer synchronized with cmdClient\n");
        }
#endif
    }
#ifdef RFE_DEBUG
    else
    {
        if (gRfeDebugLevel == e_rfe_debug_level_all)
        {
            RfeDbgPrintMsg("rfeSwMainFsm_mainState_waitingForSync: cmdServer not yet synchronized with cmdClient\n");
        }
    }
#endif
}

void rfeSwMainFsm_mainState_configuring(rfe_error_t* rfe___error___pointer)
{
    uint8_t feId;
    uint8_t fullyConfigured = 1U;
    rfeDriverPersistentMem_t *pDrvState = RfeDrvStateGet();

#ifdef RFE_DEBUG
    if (gRfeDebugLevel == e_rfe_debug_level_all)
    {
        RfeDbgPrintMsg("rfeSwMainFsm_mainState_configuring: func start\n");
    }
#endif
    rfeSwCfgMngr_distributeConfiguration(rfe___error___pointer);
    if (RfeDrvStateConfigurationGet() == rfeFrontEnd_Cascaded_e)
    {
        // cascaded
        if ( *rfe___error___pointer == rfe_error_none_e)
        {
            pDrvState->configured = 1;
            for (feId = 0; feId < RfeDrvStateNoFrontendsGet(); feId++)
            {
                pDrvState = RfeDrvStateWithIdGet(feId);
                if (pDrvState->configured == 0U)
                {
                    fullyConfigured = 0;
                    break;
                }
            }
        }
    }
    if (fullyConfigured != 0U)
    {
        rfeSwMainFsm_triggerEvent( rfeSwMainFsm_event_stateTaskFinished_e, rfe___error___pointer);
    }
    else
    {
        rfeSwMainFsm_triggerEvent( rfeSwMainFsm_event_configurationIncomplete_e, rfe___error___pointer);
    }
}

void rfeSwMainFsm_mainState_startRadarCycles(rfe_error_t* rfe___error___pointer)
{
    uint32_t rfeTime;
    uint32_t waitRadarCycleStartUs = 0U;
#ifdef RFE_DEBUG
    if (gRfeDebugLevel == e_rfe_debug_level_all)
    {
        RfeDbgPrintMsg("rfeSwMainFsm_mainState_startRadarCycles: func start\n");
    }
#endif
    currentChirpSequenceIndex = 0U;
    radarCycleCount = 0U;
    chirpSequenceCount = 0U;

    rfeSwMainFsm_sharedDataWrite( rfeSwMainFsm_sharedParameter_radarCycleCount_e, radarCycleCount, rfe___error___pointer);
    rfeSwMainFsm_sharedDataWrite( rfeSwMainFsm_sharedParameter_chirpSequenceCount_e, chirpSequenceCount, rfe___error___pointer);

    if ( radarCycleIsScheduled )
    {
        rfeTime = rfeSysTick_getTick( rfe___error___pointer);
        waitRadarCycleStartUs = (uint32_t)abs(rfeTime - radarCycleStartTime) / (uint32_t)RFE_SYSTICK_TICKS_PER_USEC;
        RfeHwDelayUs(waitRadarCycleStartUs);
    }
    // We start radar cycles immediately
    radarCycleStartTime = rfeSysTick_getTick( rfe___error___pointer);

    rfeSwMainFsm_triggerEvent( rfeSwMainFsm_event_stateTaskFinished_e, rfe___error___pointer);
}

void rfeSwMainFsm_mainState_radarCycles(rfe_error_t* rfe___error___pointer)
{
#ifdef RFE_DEBUG
    if (gRfeDebugLevel == e_rfe_debug_level_all)
    {
        RfeDbgPrintMsg("rfeSwMainFsm_mainState_radarCycles: func start\n");
    }
#endif
    (void)rfeSwMainFsm_radarCycleFsm( rfeSwMainFsm_radarCycleState_begin_e, rfe___error___pointer);
}


void rfeSwMainFsm_mainState_fuSaFault(rfe_error_t* rfe___error___pointer)
{
    if ( !cmdServerSynced )
    {
        cmdServerSynced = rfeCmdServer_sync( rfe___error___pointer);
    }
    else
    {
        // cmdServer already synchronized with cmdClient
    }
}

void rfeSwMainFsm_radarCyclesState_begin(rfe_error_t* rfe___error___pointer)
{
    uint8_t bistInterval;
    rfeDriverPersistentMem_t* pDrvState;

#ifdef RFE_DEBUG
    if (gRfeDebugLevel <= e_rfe_debug_level_radar_cycle)
    {
        RfeDbgPrintMsg("0_rfeSwMainFsm_radarCyclesState_begin: func start\n");
    }
#endif
    pDrvState = RfeDrvStateGet();
    // Check whether we have to do bist in this radar cycle
    bistInterval = rfeCfg_radarCycle_getBistInterval(pDrvState->rfeConfig, rfe___error___pointer);

    if( rfeSwUtils_BistIntervalMapper(bistInterval) != rfe_bistInterval_none_e )
    {
        if ((radarCycleCount % (uint16_t)(1UL << (uint16_t)bistInterval)) == 0U)
        {
            // We do bist in this radar cycle
            radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequencesPerRadarCycle - 1U][rfeSwMainFsm_radarCycleState_bist_e] =
                    radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequencesPerRadarCycle - 1U][rfeSwMainFsm_radarCycleState_monitorsAndMetadata_e] +
                    (uint32_t)RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_BIST_DURATION;
        }
        else
        {
            // We skip bist in this radar cycle
            radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequencesPerRadarCycle - 1U][rfeSwMainFsm_radarCycleState_bist_e] =
                    radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequencesPerRadarCycle - 1U][rfeSwMainFsm_radarCycleState_monitorsAndMetadata_e];
        }
    }
    else
    {
            // We skip bist in this radar cycle
            radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequencesPerRadarCycle - 1U][rfeSwMainFsm_radarCycleState_bist_e] =
                    radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequencesPerRadarCycle - 1U][rfeSwMainFsm_radarCycleState_monitorsAndMetadata_e];
    }
    radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequencesPerRadarCycle - 1U][rfeSwMainFsm_radarCycleState_powerOff_e] =
            radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequencesPerRadarCycle - 1U][rfeSwMainFsm_radarCycleState_bist_e] +
            (uint32_t)RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_POWEROFF_DURATION;
    // Revert the modified radar cycle schedule timing, due to rfeSwMainFsm_setNextRadarCycleStartTime(), for this new radar cycle
    if (radarCycleStartTimeOffset != 0)
    {
        radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequencesPerRadarCycle - 1U][rfeSwMainFsm_radarCycleState_idle_e] -= (uint32_t)radarCycleStartTimeOffset;
        radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequencesPerRadarCycle - 1U][rfeSwMainFsm_radarCycleState_cmdExecutionBuffer_e] -= (uint32_t)radarCycleStartTimeOffset;
        radarCycleTimeSchedule.stateEndTimeTicks[( uint32_t )rfeSwMainFsm_radarCycleState_configUpdate_e - RFE_SW_MAIN_FSM_RADAR_CYCLE_CHIRP_SEQUENCE_LOOP_STATE_COUNT] -=
                (uint32_t)radarCycleStartTimeOffset;
        radarCycleStartTimeOffset = 0;
    }
    else
    {
        // rfeSwMainFsm_setNextRadarCycleStartTime() was not called in previous radar cycle
    }
}

void rfeSwMainFsm_radarCyclesState_powerOn(rfe_error_t* rfe___error___pointer)
{
    (void)rfe___error___pointer;
#ifdef RFE_DEBUG
    if (gRfeDebugLevel <= e_rfe_debug_level_radar_cycle)
    {
        RfeDbgPrintMsg("1_rfeSwMainFsm_radarCyclesState_powerOn: func start\n");
    }
#endif
    // We need to know if this is last sequence in cycle
    if (currentChirpSequenceIndex == (chirpSequencesPerRadarCycle - 1))
    {
        lastSequenceInCycle = true;
    }
    else
    {
        lastSequenceInCycle = false;
    }
}

void rfeSwMainFsm_radarCyclesState_initChirpSequence(rfe_error_t* rfe___error___pointer)
{
    BC_ERRCODE                  errCode = BC_ERR_NOERROR;
    rfeDriverPersistentMem_t    *pDrvState = NULL;
    rfe_chirpSequenceIndex_t    chirpSequenceConfigIndex = (rfe_chirpSequenceIndex_t)chirpSequences[currentChirpSequenceIndex];
    uint8_t                     frontendIndex = 0;

#ifdef RFE_DEBUG
    if (gRfeDebugLevel <= e_rfe_debug_level_radar_cycle)
    {
        RfeDbgPrintMsg("2_rfeSwMainFsm_radarCyclesState_initChirpSequence %d: func start\n", chirpSequenceConfigIndex);
    }
#endif
    for(; frontendIndex < RfeDrvStateNoFrontendsGet(); frontendIndex++)
    {
        rfeSwUtils_SelectFe(frontendIndex);
        // TODO: Reprogram params only if needed (e.g. if they changed)
        pDrvState = RfeDrvStateGet();
#ifdef MIPI_SETUP_SEQUENCE
        // Setup MIPI_CSI2 Virtual Channels for current sequence
        MIPI_Config(RFE_MIPI_CONFIG_VC, chirpSequenceConfigIndex, rfe___error___pointer);
#endif
        // Set TEF82XX CSI2 DPHY to Continuous Clock Mode in order to gracefully initialize CSI2 RX on host
        // This needs to be called only once, after MIPI_Config - RFE_MIPI_CONFIG_FULL
        if ((*rfe___error___pointer == rfe_error_none_e) && (pDrvState->csi2TxClkNonContinuousMode == 1U))
        {
            // Add a 1.5ms delay to allow CSI2 RX to initialize in stable CLK conditions
            RfeHwDelayUs(1500U);
            pDrvState->csi2TxClkNonContinuousMode = 0U;
            *rfe___error___pointer = Tef82xxErrToRfeErrorMapper(BC_MIPI_EnContinuousClock(TRUE));
        }

        if ( *rfe___error___pointer != rfe_error_none_e)
        {
            break;
        }
        // Configure the number of chirps in the sequence
        errCode = BC_TE_SetChirpSeqCtrl(TEF82XX_DEFAULT_NUM_SEQ_IN_BURST,
                                        pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[chirpSequenceConfigIndex].nrChirpsInFrame);
        if (errCode != BC_ERR_NOERROR)
        {
            *rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
        }
        if (*rfe___error___pointer == rfe_error_none_e)
        {
            // Configure the profile sequence
            TE_ConfigProfileSequencing((uint8_t)chirpSequenceConfigIndex, rfe___error___pointer);
            // Configure phase rotators for current sequence
            rfeSwCfg_PhaseRotatorPhaseControl(pDrvState->rfeConfig, chirpSequenceConfigIndex, rfe___error___pointer);
            // Configure the dynamic update based on dynamic tables
            rfeSwDynamicTables_TableSet(pDrvState, chirpSequenceConfigIndex, rfe___error___pointer);
        }
    }
    // Set initial QPSK phase
    rfeSwDynamicTables_IQUpdate();

    rfeSwMon_monitorDataBeforeChirping(lastSequenceInCycle, rfe___error___pointer);
}

void rfeSwMainFsm_radarCyclesState_recalibration(rfe_error_t* rfe___error___pointer)
{

    static BOOL firstCalibration = TRUE;
    uint8_t     feIndex;
    uint8_t     lastSeqInt;

#ifdef RFE_DEBUG
    if (gRfeDebugLevel <= e_rfe_debug_level_radar_cycle)
    {
        RfeDbgPrintMsg("3_rfeSwMainFsm_radarCyclesState_recalibration: func start\n");
    }
#endif

    rfeSwCalibTef82xxCalibration(currentChirpSequenceIndex, rfe___error___pointer);

    if(firstCalibration == TRUE)
    {
#ifdef RFE_DEBUG
        if (gRfeDebugLevel <= e_rfe_debug_level_radar_cycle)
        {
            RfeDbgPrintMsg("Integrity_check: tx sensor and cafc\n");
        }
#endif
        if (lastSequenceInCycle)
        {   // Added for MISRA Rule 10.5 compliance
            lastSeqInt = 1U;
        }
        else
        {
            lastSeqInt = 0U;
        }
        // DO CAFC and Tx checks only after the first calibration
        // define the Front-Ends(s) to be tested
        for(feIndex = 0; feIndex < RfeDrvStateNoFrontendsGet(); feIndex++)
        {
            rfeSwUtils_SelectFe(feIndex);
            rfeIcTest(feIndex, (rfe_icFaultInjectionTest_t)((uint8_t)rfe_ic_tx_sensor_test_e | (uint8_t)rfe_ic_cafc_test_e), rfe_ic_gpio_none_e, lastSeqInt, rfe___error___pointer);
        }
        // ask for IC tests
        firstCalibration = FALSE;
        skipTimeCheck = true;
    }
}

void rfeSwMainFsm_radarCyclesState_chirpSequence(rfe_error_t* rfe___error___pointer)
{
#ifdef RFE_DEBUG
    if (gRfeDebugLevel <= e_rfe_debug_level_radar_cycle)
    {
        RfeDbgPrintMsg("4_rfeSwMainFsm_radarCycles(%d)State_chirpSequence(%d): func start\n", radarCycleCount, chirpSequenceCount);
    }
#endif
    rfeSwMain_PrepareChirping(rfe___error___pointer);
    // Enable INT trigger updates on MCU INT
    rfeSwDynamicTables_IQUpdateEnabled(true);
    // Set initial QPSK phase
    rfeSwDynamicTables_IQUpdate();
    rfeSwMain_StartChirpSeq(rfe___error___pointer);
    rfeSwMain_PostChirping(rfe___error___pointer);
    // Disable INT trigger updates on MCU INT
    rfeSwDynamicTables_IQUpdateEnabled(false);
#ifdef LB_DATA_DUMP
	uint32_t ms = 1000;
	while(ms)
	{
		RfeHwDelayUs(1000);
		ms--;
	}
#endif
    chirpSequenceCount++;
    rfeCmdServer_sharedDataWrite((uint32_t)rfeSwMainFsm_sharedParameter_chirpSequenceCount_e, chirpSequenceCount, rfe___error___pointer);
}

void rfeSwMainFsm_radarCyclesState_monitorsAndMetadata(rfe_error_t* rfe___error___pointer)
{
    rfeDriverPersistentMem_t *pDrvState = RfeDrvStateGet();

#ifdef RFE_DEBUG
    if (gRfeDebugLevel <= e_rfe_debug_level_radar_cycle)
    {
        RfeDbgPrintMsg("5_rfeSwMainFsm_radarCyclesState_monitorsAndMetadata: func start\n");
    }
#endif

    rfeSwStatusTef82xxDeviceStatus(&pDrvState->devStatus, rfe___error___pointer);

    // Workaround for ADC calibration issue
    if (lastSequenceInCycle)
    {
        skipTimeCheck = CheckAdcCalibration(rfe___error___pointer);
    }

    // Measure and store temperature before last sequence in radar cycle
    rfeMon_performFEMonitoring(lastSequenceInCycle, currentChirpSequenceIndex, rfe___error___pointer);
}

void rfeSwMainFsm_radarCyclesState_bist(rfe_error_t* rfe___error___pointer)
{
    uint8_t                         frontendIndex;
    rfe_icFaultInjectionTest_t      testToDo = (rfe_icFaultInjectionTest_t)((uint8_t)rfe_ic_toggle_test_e | (uint8_t)rfe_ic_loi_bbd_test_e |
            (uint8_t)rfe_ic_tx_calib_status_e);
    rfeDriverPersistentMem_t        *pDrvState = NULL;
    // For the chirp Start In signal test please add rfe_ic_gpio_chirp_start_in_e in the gpioMask.
    rfe_icGpioSignal_t              gpioMask;
    uint8_t                         lastSeqInt;
#ifdef RFE_DEBUG
    if (gRfeDebugLevel <= e_rfe_debug_level_radar_cycle)
    {
        RfeDbgPrintMsg("6_rfeSwMainFsm_radarCyclesState_bist: func start\n");
        RfeDbgPrintMsg("Integrity check: pin toggle and loi bbd\n");
    }
#endif
    if (lastSequenceInCycle)
    {   // Added for MISRA Rule 10.5 compliance
        lastSeqInt = 1U;
    }
    else
    {
        lastSeqInt = 0U;
    }
    for(frontendIndex = 0; frontendIndex < RfeDrvStateNoFrontendsGet(); frontendIndex++)
    {
        rfeSwUtils_SelectFe(frontendIndex);
        pDrvState = RfeDrvStateGet();
        gpioMask = DEFAULT_PIN_TOGGLE_TEST;
        if (pDrvState->tef82xxDrvState.enableIQPinsTogleTest == TRUE)
        {
            // Update with I/Q pins togle test
            gpioMask |= (rfe_ic_gpio_tx1_i_e | rfe_ic_gpio_tx2_i_e | rfe_ic_gpio_tx3_i_e | rfe_ic_gpio_tx1_q_e | rfe_ic_gpio_tx2_q_e | rfe_ic_gpio_tx3_q_e);
        }
        rfeIcTest(frontendIndex, testToDo, gpioMask, lastSeqInt, rfe___error___pointer);
    }

#ifdef RFE_DEBUG
    if (gRfeDebugLevel <= e_rfe_debug_level_radar_cycle)
    {
        static uint8_t count = 0;
        RfeDbgPrintMsg("\nPerform RX bist %d radarCycle %d seq %d\n\n\n", ++count, radarCycleCount, chirpSequenceCount);
    }
#endif
    rfeSwBist_bist(rfe___error___pointer);
}

void rfeSwMainFsm_radarCyclesState_powerOff(rfe_error_t* rfe___error___pointer)
{
    (void)rfe___error___pointer;
#ifdef RFE_DEBUG
    if (gRfeDebugLevel <= e_rfe_debug_level_radar_cycle)
    {
        RfeDbgPrintMsg("7_rfeSwMainFsm_radarCyclesState_powerOff: func start\n");
    }
#endif
}

void rfeSwMainFsm_radarCyclesState_configUpdate(rfe_error_t* rfe___error___pointer)
{
#ifdef RFE_DEBUG
    if (gRfeDebugLevel <= e_rfe_debug_level_radar_cycle)
    {
        RfeDbgPrintMsg("rfeSwMainFsm_radarCyclesState_configUpdate: func start\n");
    }
#endif
    bool updatesApplied = rfeSwCfgMngr_applyParamUpdates(rfe___error___pointer);

    if(updatesApplied)
    {
        radarCycleStartTimeOffset = 0;
    }
    else
    {
        // No updates were applied.
    }
}

void rfeSwMainFsm_handleCmds(rfeSwMainFsm_cmdSelect_t allowedCmds, rfe_error_t* rfe___error___pointer)
{
#ifdef RFE_DEBUG
    const char* cmdNames[] = {"configure_e", "radarCycleStart_e", "radarCycleStop_e",
            "getFuSaFaults_e", "getTime_e", "getVersion_e", "monitorRead_e", "getNextRadarCycleStartTime_e",
            "setNextRadarCycleStartTime_e", "updatePush_e", "testContinuousWaveTransmissionStart_e",
            "testContinuousWaveTransmissionStop_e", "testSetParam_e", "getFuSaFaultStatistics_e",
            "getBistZeroHourReferenceData_e", "testGetInternalError_e", "setFrontEnd_e", "getFrontEnd_e"};
#endif
    uint8_t cmdId;
    if(rfeCmdServer_cmdAvailable(&cmdId))
    {
        if(((1UL << cmdId) & allowedCmds) != 0UL)
        {
#ifdef RFE_DEBUG
            if (gRfeDebugLevel <= e_rfe_debug_level_handle_cmd)
            {
                RfeDbgPrintMsg("rfeSwMainFsm_handleCmds: command \"%s\" good\n", cmdNames[cmdId]);
            }
#endif
            rfeCmdServer_handlecmd( rfe_error_none_e, rfe___error___pointer);
        }
        else
        {
#ifdef RFE_DEBUG
            if (gRfeDebugLevel <= e_rfe_debug_level_handle_cmd)
            {
                RfeDbgPrintMsg("rfeSwMainFsm_handleCmds: command \"%s\" not allowed\n", cmdNames[cmdId]);
            }
#endif
            rfeCmdServer_handlecmd( rfe_error_api_operationNotAllowed_e, rfe___error___pointer);
        }
    }
    else
    {
        // No command available
    }

}

rfeSwMainFsm_fwInternalErrorCode_t rfeSwMainFsm_testGetInternalErrors(rfe_error_t* rfe___error___pointer)
{
    (void)rfe___error___pointer;
#ifdef RFE_DEBUG
    if (gRfeDebugLevel == e_rfe_debug_level_all)
    {
        RfeDbgPrintMsg("rfeSwMainFsm_testGetInternalErrors: func start");
    }
#endif
    return (rfeSwMainFsm_fwInternalErrorCode_t)storedSwError;
}

void rfeSwMainFsm_getBistZeroHourReferenceData(rfeSwBist_rxBistReferenceData_t *zeroHourData, rfe_error_t* rfe___error___pointer)
{
    if ( zeroHourData == NULL )
    {
        *rfe___error___pointer = rfe_error_nullPointer_e;
    }
    else
    {
        // All parameters within range
    }
    if(*rfe___error___pointer == rfe_error_none_e)
    {
        rfeSwBist_getBistZeroHourReferenceData(zeroHourData, rfe___error___pointer);
    }
}
