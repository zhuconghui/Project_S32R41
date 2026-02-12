/*
    Copyright 2021-2022 NXP
    NXP Confidential. This software is owned or controlled by NXP and may only be 
    used strictly in accordance with the applicable license terms. By expressly 
    accepting such terms or by downloading, installing, activating and/or otherwise
    using the software, you are agreeing that you have read, and that you agree to
    comply with and are bound by, such license terms.  If you do not agree to be 
    bound by the applicable license terms, then you may not retain, install, 
    activate or otherwise use the software.
 */


/******************************************************************************
 *   Project              : S32R41_RFE_FW
 *   Platform             : S32R41
 *****************************************************************************/

#ifndef RFE_SW_MAIN_FSM_INTERNAL_H
#define RFE_SW_MAIN_FSM_INTERNAL_H


/******************************************************************************
 *                              INCLUDES
 *****************************************************************************/

#include "rfe_cmd_interface.h"
#include "rfeSysTick.h"
#include "rfe_error.h"
#include "rfeSwMainFsm.h"

/******************************************************************************
 *                              TYPES
 *****************************************************************************/

/**
 * These macros define MainFsm timing constants
 */
#define RFE_SW_MAIN_FSM_SET_NEXT_RADAR_CYCLE_START_TIME_OFFSET_MAX                      ( 100000UL * RFE_SYSTICK_TICKS_PER_USEC )
#define RFE_SW_MAIN_FSM_SET_NEXT_RADAR_CYCLE_START_TIME_REMAINING_LAST_IDLE_TIME_MIN    ( RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_IDLE_DURATION_MIN + RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_CMD_EXECUTION_BUFFER_DURATION + RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_CONFIG_UPDATE_DURATION )
#define RFE_SW_MAIN_FSM_SET_NEXT_RADAR_CYCLE_START_TIME_REMAINING_TIME_MIN              ( RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_CMD_EXECUTION_BUFFER_DURATION + RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_CONFIG_UPDATE_DURATION )

/**
 * This type defines a selection of rfe cmds
 */
typedef uint32_t rfeSwMainFsm_cmdSelect_t;
#define RFE_SW_MAIN_FSM_CMD_SELECT_DONT_CHECK_FOR_CMDS                      ( ( rfeSwMainFsm_cmdSelect_t ) 0UL )
#define RFE_SW_MAIN_FSM_CMD_SELECT_CONFIGURE                                ( ( rfeSwMainFsm_cmdSelect_t ) ( 1UL<<rfeCmdServer_cmdId_configure_e ) )
#define RFE_SW_MAIN_FSM_CMD_SELECT_RADAR_CYCLE_START                        ( ( rfeSwMainFsm_cmdSelect_t ) ( 1UL<<rfeCmdServer_cmdId_radarCycleStart_e ) )
#define RFE_SW_MAIN_FSM_CMD_SELECT_RADAR_CYCLE_STOP                         ( ( rfeSwMainFsm_cmdSelect_t ) ( 1UL<<rfeCmdServer_cmdId_radarCycleStop_e ) )
#define RFE_SW_MAIN_FSM_CMD_SELECT_GET_FUSA_FAULTS                          ( ( rfeSwMainFsm_cmdSelect_t ) ( 1UL<<rfeCmdServer_cmdId_getFuSaFaults_e ) )
#define RFE_SW_MAIN_FSM_CMD_SELECT_GET_TIME                                 ( ( rfeSwMainFsm_cmdSelect_t ) ( 1UL<<rfeCmdServer_cmdId_getTime_e ) )
#define RFE_SW_MAIN_FSM_CMD_SELECT_GET_VERSION                              ( ( rfeSwMainFsm_cmdSelect_t ) ( 1UL<<rfeCmdServer_cmdId_getVersion_e ) )
#define RFE_SW_MAIN_FSM_CMD_SELECT_MONITOR_READ                             ( ( rfeSwMainFsm_cmdSelect_t ) ( 1UL<<rfeCmdServer_cmdId_monitorRead_e ) )
#define RFE_SW_MAIN_FSM_CMD_SELECT_GET_NEXT_RADAR_CYCLE_START_TIME          ( ( rfeSwMainFsm_cmdSelect_t ) ( 1UL<<rfeCmdServer_cmdId_getNextRadarCycleStartTime_e ) )
#define RFE_SW_MAIN_FSM_CMD_SELECT_SET_NEXT_RADAR_CYCLE_START_TIME          ( ( rfeSwMainFsm_cmdSelect_t ) ( 1UL<<rfeCmdServer_cmdId_setNextRadarCycleStartTime_e ) )
#define RFE_SW_MAIN_FSM_CMD_SELECT_UPDATE_PUSH                              ( ( rfeSwMainFsm_cmdSelect_t ) ( 1UL<<rfeCmdServer_cmdId_updatePush_e ) )
#define RFE_SW_MAIN_FSM_CMD_SELECT_TEST_CONTINUOUS_WAVE_TRANSMISSION_START  ( ( rfeSwMainFsm_cmdSelect_t ) ( 1UL<<rfeCmdServer_cmdId_testContinuousWaveTransmissionStart_e ) )
#define RFE_SW_MAIN_FSM_CMD_SELECT_TEST_CONTINUOUS_WAVE_TRANSMISSION_STOP   ( ( rfeSwMainFsm_cmdSelect_t ) ( 1UL<<rfeCmdServer_cmdId_testContinuousWaveTransmissionStop_e ) )
#define RFE_SW_MAIN_FSM_CMD_SELECT_TEST_SET_PARAM                           ( ( rfeSwMainFsm_cmdSelect_t ) ( 1UL<<rfeCmdServer_cmdId_testSetParam_e ) )
#define RFE_SW_MAIN_FSM_CMD_SELECT_GET_FUSA_FAULTSTATISTICS                 ( ( rfeSwMainFsm_cmdSelect_t ) ( 1UL<<rfeCmdServer_cmdId_getFuSaFaultStatistics_e ) )
#define RFE_SW_MAIN_FSM_CMD_SELECT_GET_BIST_ZEROHOUR_REFERENCEDATA          ( ( rfeSwMainFsm_cmdSelect_t ) ( 1UL<<rfeCmdServer_cmdId_getBistZeroHourReferenceData_e ) )
#define RFE_SW_MAIN_FSM_CMD_SELECT_TEST_GET_INTERNAL_ERROR                  ( ( rfeSwMainFsm_cmdSelect_t ) ( 1UL<<rfeCmdServer_cmdId_testGetInternalError_e ) )
#define RFE_SW_MAIN_FSM_CMD_SELECT_SET_FE_ID                  				( ( rfeSwMainFsm_cmdSelect_t ) ( 1UL<<rfeCmdServer_cmdId_setFrontEnd_e ) )
#define RFE_SW_MAIN_FSM_CMD_SELECT_GET_FE_ID                  				( ( rfeSwMainFsm_cmdSelect_t ) ( 1UL<<rfeCmdServer_cmdId_getFrontEnd_e ) )
#define RFE_SW_MAIN_FSM_CMD_SELECT_REG_DUMP                                 ( ( rfeSwMainFsm_cmdSelect_t ) ( 1UL<<rfeCmdServer_cmdId_registerDump_e ) )
#define RFE_SW_MAIN_FSM_CMD_SELECT_CONFIGURE_INTERRUPT                      ( ( rfeSwMainFsm_cmdSelect_t ) ( 1UL<<rfeCmdServer_cmdId_configureInterrupt_e ) )
#define RFE_SW_MAIN_FSM_CMD_SELECT_DROP_ALL_CMDS                            ( ( rfeSwMainFsm_cmdSelect_t ) ( 1UL<< RFE_CMD_IF_CMD_COUNT ) )



/**
 * This struct defines a state.
 */
typedef struct
{
    /** Pointer to state function. */
    void (*function)(rfe_error_t*);
    /** Selections of rfe cmds that are allowed during the state. */
    rfeSwMainFsm_cmdSelect_t allowedCmds;
    /** The state that will be shared to the control core in this state */
    uint8_t sharedState;
} rfeSwMainFsm_stateTableEntry_t;

/**
 * This struct defines a state transition.
 */
typedef struct
{
    /** Defines the event that triggers the transition */
    uint8_t event;
    /** Defines the source state */
    uint8_t srcState;
    /** Defines the destination state */
    uint8_t dstState;
}
rfeSwMainFsm_stateTransition_t;

extern rfeSwMainFsm_radarCycleTimingSchedule_t radarCycleTimeSchedule;
extern uint8_t chirpSequences[RFE_CHIRP_SEQUENCES_PER_RADAR_CYCLE_MAX];
extern uint8_t chirpSequencesPerRadarCycle;


/******************************************************************************
 *                              FUNCTIONS
 *****************************************************************************/

/**
 * \brief This function performs the radar cycle finite-state-machine.
 * 
 * \details This function is called by rfeSwMainFsm_mainFsm(). This function 
 * shall loop until a main event is triggered or an error occurs.
 *
 * \pre NIL
 *
 * \param [in]      state - Start state or, in case \p loop is set to false, the state
 *                  at which to continue.
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #RFE_ERROR_IS_NO_ERROR is true, 
 *                  On failure #RFE_ERROR_IS_ERROR is true
 *
 * \return rfeSwMainFsm_radarCycleState_t - The next state, when \p loop is set to false.
 * This return value can be used as argument to the next invocation of this function. In this
 * way we can step through the state machine, state by state, which is used for unit testing.
 *
 * \post NIL
 *
 * \ingroup NIL
 */
rfeSwMainFsm_radarCycleState_t rfeSwMainFsm_radarCycleFsm(rfeSwMainFsm_radarCycleState_t state,
    rfe_error_t* rfe___error___pointer);

/**
 * \brief This function performs the #rfeSwMainFsm_mainState_initializing_e state.
 * 
 * \details This function is called by rfeSwMainFsm_mainFsm().
 * 
 * \pre NIL
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #RFE_ERROR_IS_NO_ERROR is true, 
 *                  On failure #RFE_ERROR_IS_ERROR is true
 *
 * \return NIL
 *
 * \post NIL
 *
 * \ingroup NIL
 */
void rfeSwMainFsm_mainState_initializing(rfe_error_t* rfe___error___pointer);

/**
 * \brief This function performs the #rfeSwMainFsm_mainState_waitingForSync_e state.
 * 
 * \details This function is called by rfeSwMainFsm_mainFsm().
 * 
 * \pre NIL
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #RFE_ERROR_IS_NO_ERROR is true, 
 *                  On failure #RFE_ERROR_IS_ERROR is true
 *
 * \return NIL
 *
 * \post NIL
 *
 * \ingroup NIL
 */
void rfeSwMainFsm_mainState_waitingForSync(rfe_error_t* rfe___error___pointer);

/**
 * \brief This function performs the #rfeSwMainFsm_mainState_configuring_e state.
 * 
 * \details This function is called by rfeSwMainFsm_mainFsm().
 * 
 * \pre NIL
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #RFE_ERROR_IS_NO_ERROR is true, 
 *                  On failure #RFE_ERROR_IS_ERROR is true
 *
 * \return NIL
 *
 * \post NIL
 *
 * \ingroup NIL
 */
void rfeSwMainFsm_mainState_configuring(rfe_error_t* rfe___error___pointer);

/**
 * \brief This function performs the #rfeSwMainFsm_mainState_startRadarCycles_e state.
 * 
 * \details This function is called by rfeSwMainFsm_mainFsm().
 * 
 * \pre NIL
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #RFE_ERROR_IS_NO_ERROR is true, 
 *                  On failure #RFE_ERROR_IS_ERROR is true
 *
 * \return NIL
 *
 * \post NIL
 *
 * \ingroup NIL
 */
void rfeSwMainFsm_mainState_startRadarCycles(rfe_error_t* rfe___error___pointer);

/**
 * \brief This function performs the #rfeSwMainFsm_mainState_radarCycles_e state.
 * 
 * \details This function is called by rfeSwMainFsm_mainFsm().
 * 
 * \pre NIL
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #RFE_ERROR_IS_NO_ERROR is true, 
 *                  On failure #RFE_ERROR_IS_ERROR is true
 *
 * \return NIL
 *
 * \post NIL
 *
 * \ingroup NIL
 */
void rfeSwMainFsm_mainState_radarCycles(rfe_error_t* rfe___error___pointer);

/**
 * \brief This function performs the #rfeSwMainFsm_mainState_fuSaFault_e state.
 * 
 * \details This function is called by rfeSwMainFsm_mainFsm().
 * 
 * \pre NIL
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #RFE_ERROR_IS_NO_ERROR is true, 
 *                  On failure #RFE_ERROR_IS_ERROR is true
 *
 * \return NIL
 *
 * \post NIL
 *
 * \ingroup NIL
 */
void rfeSwMainFsm_mainState_fuSaFault(rfe_error_t* rfe___error___pointer);

/**
 * \brief This function performs the #rfeSwMainFsm_mainState_begin_e state.
 * 
 * \details This function is called by rfeSwMainFsm_radarCycleFsm().
 * 
 * \pre NIL
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #RFE_ERROR_IS_NO_ERROR is true, 
 *                  On failure #RFE_ERROR_IS_ERROR is true
 *
 * \return NIL
 *
 * \post NIL
 *
 * \ingroup NIL
 */
void rfeSwMainFsm_radarCyclesState_begin(rfe_error_t* rfe___error___pointer);

/**
 * \brief This function performs the #rfeSwMainFsm_radarCycleState_powerOn_e state.
 * 
 * \details This function is called by rfeSwMainFsm_radarCycleFsm().
 *  
 * \pre NIL
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #RFE_ERROR_IS_NO_ERROR is true, 
 *                  On failure #RFE_ERROR_IS_ERROR is true
 *
 * \return NIL
 *
 * \post NIL
 *
 * \ingroup NIL
 */   
void rfeSwMainFsm_radarCyclesState_powerOn(rfe_error_t* rfe___error___pointer);

/**
 * \brief This function performs the #rfeSwMainFsm_radarCycleState_initChirpSequence_e state.
 * 
 * \details This function is called by rfeSwMainFsm_radarCycleFsm().
 *  
 * \pre NIL
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #RFE_ERROR_IS_NO_ERROR is true, 
 *                  On failure #RFE_ERROR_IS_ERROR is true
 *
 * \return NIL
 *
 * \post NIL
 *
 * \ingroup NIL
 */   
void rfeSwMainFsm_radarCyclesState_initChirpSequence(rfe_error_t* rfe___error___pointer);

/**
 * \brief This function performs the #rfeSwMainFsm_radarCycleState_recalibration_e state.
 * 
 * \details This function is called by rfeSwMainFsm_radarCycleFsm().
 * 
 * \pre NIL
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #RFE_ERROR_IS_NO_ERROR is true, 
 *                  On failure #RFE_ERROR_IS_ERROR is true
 *
 * \return NIL
 *
 * \post NIL
 *
 * \ingroup NIL
 */
void rfeSwMainFsm_radarCyclesState_recalibration(rfe_error_t* rfe___error___pointer);

/**
 * \brief This function performs the #rfeSwMainFsm_radarCycleState_chirpSequence_e state.
 * 
 * \details This function is called by rfeSwMainFsm_radarCycleFsm().
 * 
 * \pre NIL
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #RFE_ERROR_IS_NO_ERROR is true, 
 *                  On failure #RFE_ERROR_IS_ERROR is true
 *
 * \return NIL
 *
 * \post NIL
 *
 * \ingroup NIL
 */
void rfeSwMainFsm_radarCyclesState_chirpSequence(rfe_error_t* rfe___error___pointer);

/**
 * \brief This function performs the #rfeSwMainFsm_radarCycleState_monitorsAndMetadata_e state.
 * 
 * \details This function is called by rfeSwMainFsm_radarCycleFsm().
 * 
 * \pre NIL
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #RFE_ERROR_IS_NO_ERROR is true, 
 *                  On failure #RFE_ERROR_IS_ERROR is true
 *
 * \return NIL
 *
 * \post NIL
 *
 * \ingroup NIL
 */
void rfeSwMainFsm_radarCyclesState_monitorsAndMetadata(rfe_error_t* rfe___error___pointer);

/**
 * \brief This function performs the #rfeSwMainFsm_radarCycleState_bist_e state.
 * 
 * \details This function is called by rfeSwMainFsm_radarCycleFsm().
 * 
 * \pre NIL
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #RFE_ERROR_IS_NO_ERROR is true, 
 *                  On failure #RFE_ERROR_IS_ERROR is true
 *
 * \return NIL
 *
 * \post NIL
 *
 * \ingroup NIL
 */
void rfeSwMainFsm_radarCyclesState_bist(rfe_error_t* rfe___error___pointer);

/**
 * \brief This function performs the #rfeSwMainFsm_radarCycleState_powerOff_e state.
 * 
 * \details This function is called by rfeSwMainFsm_radarCycleFsm().
 *  
 * \pre NIL
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #RFE_ERROR_IS_NO_ERROR is true, 
 *                  On failure #RFE_ERROR_IS_ERROR is true
 *
 * \return NIL
 *
 * \post NIL
 *
 * \ingroup NIL
 */   
void rfeSwMainFsm_radarCyclesState_powerOff(rfe_error_t* rfe___error___pointer);

/**
 * \brief This function performs the #rfeSwMainFsm_radarCycleState_configUpdate_e state.
 * 
 * \details This function is called by rfeSwMainFsm_radarCycleFsm().
 * 
 * \pre NIL
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #RFE_ERROR_IS_NO_ERROR is true, 
 *                  On failure #RFE_ERROR_IS_ERROR is true
 *
 * \return NIL
 *
 * \post NIL
 *
 * \ingroup NIL
 */
void rfeSwMainFsm_radarCyclesState_configUpdate(rfe_error_t* rfe___error___pointer);

/**
 * \brief This function checks and handles available cmd server commands.
 * 
 * \details This function is called by rfeSwMainFsm_mainFsm() and rfeSwMainFsm_radarCycleFsm().
 * 
 * \pre NIL
 * 
 * \param [in]      allowedCmds - Selection of rfe cmds that are allowed
 *                  and should be accepted, other cmds will be dropped.
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #RFE_ERROR_IS_NO_ERROR is true, 
 *                  On failure #RFE_ERROR_IS_ERROR is true
 *
 * \return NIL
 *
 * \post NIL
 *
 * \ingroup NIL
 */
void rfeSwMainFsm_handleCmds(rfeSwMainFsm_cmdSelect_t allowedCmds, rfe_error_t* rfe___error___pointer);

#endif // !RFE_SW_MAIN_FSM_INTERNAL_H

