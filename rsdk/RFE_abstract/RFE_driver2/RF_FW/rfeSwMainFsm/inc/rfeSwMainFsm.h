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

#ifndef RFE_SW_MAIN_FSM_H
#define RFE_SW_MAIN_FSM_H


/******************************************************************************
 *                              INCLUDES
 *****************************************************************************/
#include "rfeApiFsm.h"
#include "rfeSwMainFsm_timings.h"
#include "rfeSwFuSaMngr.h"
#include "rfe_error.h"
#include "rfe_types.h"
#include "rfeSwBist.h"

/******************************************************************************
 *                              TYPES
 *****************************************************************************/
/**
 * This enumerated type defines events.
 */
typedef enum
{
    rfeSwMainFsm_event_none_e = 0U,
    rfeSwMainFsm_event_stateTaskFinished_e = 1U,
    rfeSwMainFsm_event_configurationPending_e = 2U,
    rfeSwMainFsm_event_startRadarCycles_e = 3U,
    rfeSwMainFsm_event_stopRadarCycles_e = 4U,
    rfeSwMainFsm_event_startContinuousWaveTransmission_e = 5U,
    rfeSwMainFsm_event_stopContinuousWaveTransmission_e = 6U,
    rfeSwMainFsm_event_configurationInvalid_e = 7U,
    rfeSwMainFsm_event_configurationIncomplete_e = 8U
} rfeSwMainFsm_event_t;

/**
 * This macro defines the number of radar cycle states.
 */
#define RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_COUNT ( 12UL )

/**
 * This enumerated type defines radar cycle states.
 */
typedef enum
{
    rfeSwMainFsm_radarCycleState_powerOn_e = 0U,
    rfeSwMainFsm_radarCycleState_initChirpSequence_e = 1U,
    rfeSwMainFsm_radarCycleState_recalibration_e = 2U,
    rfeSwMainFsm_radarCycleState_chirpSequence_e = 3U,
    rfeSwMainFsm_radarCycleState_monitorsAndMetadata_e = 4U,
    rfeSwMainFsm_radarCycleState_bist_e = 5U,
    rfeSwMainFsm_radarCycleState_powerOff_e = 6U,
    rfeSwMainFsm_radarCycleState_idle_e = 7U,
    rfeSwMainFsm_radarCycleState_cmdExecutionBuffer_e = 8U,
    rfeSwMainFsm_radarCycleState_configUpdate_e = 9U,        // Only once at end of radar cycle
    rfeSwMainFsm_radarCycleState_begin_e = 10U,               // Only once at beginning of radar cycle
    rfeSwMainFsm_radarCycleState_startOffset_e = 11U,         // Only once at the beginning of radar cycle
} rfeSwMainFsm_radarCycleState_t;

#ifdef NXP_INTERNAL_CALIBRATION_CALCULATION_MODE

/**
 * This enumerated type defines different types of calibration
 */
typedef enum
{
    rfeSwMainFsm_radarCycleCalibrationType_profileDependent_e,
    rfeSwMainFsm_radarCycleCalibrationType_profileIndependent_e,
} rfeSwMainFsm_radarCycleCalibrationType_t;
#endif /* NXP_INTERNAL_CALIBRATION_CALCULATION_MODE */

/**
 * This enumerated type defines the MainFsm parameters shared with the control core.
 */
typedef enum
{
    rfeSwMainFsm_sharedParameter_state_e = 0U,
    rfeSwMainFsm_sharedParameter_radarCycleCount_e = 1U,
    rfeSwMainFsm_sharedParameter_chirpSequenceCount_e = 2U,
    rfeSwMainFsm_sharedParameter_fw_ready_e = 3U,
    rfeSwMainFsm_sharedParameter_spare1_e,
    rfeSwMainFsm_sharedParameter_spare2_e,
    rfeSwMainFsm_sharedParameter_spare3_e,
    rfeSwMainFsm_sharedParameter_spare4_e,
} rfeSwMainFsm_sharedParameter_t;

/**
 * This types defines the fwInternalErrorCode returned by rfeSwMainFsm_testGetInternalErrors().
 */
typedef uint32_t rfeSwMainFsm_fwInternalErrorCode_t;
#define RFE_SW_MAIN_FSM_FW_INTERNAL_ERROR_CODE_FIRST_SW_ERROR_MSK           ( 0x0000FFFFUL )
#define RFE_SW_MAIN_FSM_FW_INTERNAL_ERROR_CODE_FIRST_SW_ERROR_SHF           ( 0UL )
#define RFE_SW_MAIN_FSM_FW_INTERNAL_ERROR_CODE_MAIN_FSM_STATE_MSK           ( 0x000F0000UL )
#define RFE_SW_MAIN_FSM_FW_INTERNAL_ERROR_CODE_MAIN_FSM_STATE_SHF           ( 16UL )
#define RFE_SW_MAIN_FSM_FW_INTERNAL_ERROR_CODE_RADAR_CYCLE_FSM_STATE_MSK    ( 0x00F00000UL )
#define RFE_SW_MAIN_FSM_FW_INTERNAL_ERROR_CODE_RADAR_CYCLE_FSM_STATE_SHF    ( 20UL )
#define RFE_SW_MAIN_FSM_FW_INTERNAL_ERROR_CODE_CHIRP_SEQUENCE_INDEX_MSK     ( 0x0F000000UL )
#define RFE_SW_MAIN_FSM_FW_INTERNAL_ERROR_CODE_CHIRP_SEQUENCE_INDEX_SHF     ( 24UL )

/**
 * This macro defines the number of radar cycle states within the chirp sequence state-loop.
 */
#define RFE_SW_MAIN_FSM_RADAR_CYCLE_CHIRP_SEQUENCE_LOOP_STATE_COUNT ( 9UL )

/**
 * This macro defines the number calibration types i.e. profile dependent and
 * profile independent calibrations.
 */

#define RFE_SW_MAIN_FSM_RADAR_CYCLE_CALIBRATION_TYPES_COUNT ( 2 )

/**
 * This struct contains the radar cycle timing schedule and calibration duration details
 */
typedef struct
{
    //holds the endtime Ticks for the chirpSequence Loop
    uint32_t stateEndTimeTicks_chirpSequenceLoop[RFE_CHIRP_SEQUENCES_PER_RADAR_CYCLE_MAX][RFE_SW_MAIN_FSM_RADAR_CYCLE_CHIRP_SEQUENCE_LOOP_STATE_COUNT];
    //holds the endtime Ticks for states which occur only once in a radar cycle and number of elements in array = 3
    uint32_t stateEndTimeTicks[RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_COUNT-RFE_SW_MAIN_FSM_RADAR_CYCLE_CHIRP_SEQUENCE_LOOP_STATE_COUNT];
#ifdef NXP_INTERNAL_CALIBRATION_CALCULATION_MODE
    //holds the individual timeTick Duration for calibration states
    uint32_t calibrationDurationTicks[RFE_CHIRP_SEQUENCES_PER_RADAR_CYCLE_MAX][RFE_SW_MAIN_FSM_RADAR_CYCLE_CALIBRATION_TYPES_COUNT];
#endif
} rfeSwMainFsm_radarCycleTimingSchedule_t;


/******************************************************************************
 *                       PUBLIC FUNCTIONS (RFE INTERNAL)
 *****************************************************************************/
/**
 * \brief This function executes the Finite State Machine (FSM) for the Radar frontend driver.
 *
 * \details This is the function that must be called by the RFE control application.
 *
 * \pre NIL
 *
 * \param [in]      startState - Start/curent state.
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #RFE_ERROR_IS_NO_ERROR is true,
 *                  On failure #RFE_ERROR_IS_ERROR is true
 *
 * \return rfeSwMainFsm_mainState_t - Curent state.
 *
 * \post NIL
 *
 * \ingroup NIL
 */
rfeSwMainFsm_mainState_t rfeSwMainFsm_mainFsm(rfeSwMainFsm_mainState_t startState, rfe_error_t* rfe___error___pointer);

/**
 * \brief This function returns the radar cycle and chirp sequence count.
 *
 * \details It returns the number radar cycles and chirp sequences
 * that have been completed since rfe_radarCycleStart().
 * This function is used by rfeSwMainFsm_monitorRead() and rfeSwCfgMngr_updatePush().
 *
 * \pre NIL
 *
 * \param [out]     pIsRadarCycleActive - Indicates whether radar cycle is active.
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #RFE_ERROR_IS_NO_ERROR is true,
 *                  On failure #RFE_ERROR_IS_ERROR is true
 *
 * \return rfe_radarCycleCount_t - Structure that contains the radar cycle and chirp sequence count.
 *
 * \post NIL
 *
 * \ingroup NIL
 */
rfe_radarCycleCount_t rfeSwMainFsm_getRadarCycleCount(bool* pIsRadarCycleActive);

/**
 * \brief This function triggers an event that will be handled by the main or radar cycle fsm.
 *
 * \details Only one event can be active at time for the main and radar cycle fsm. When an event
 * is still active, when calling this function, it will be overwritten.
 *
 * \pre NIL
 *
 * \param [in]      event - The event to trigger
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
void rfeSwMainFsm_triggerEvent(rfeSwMainFsm_event_t event, rfe_error_t* rfe___error___pointer);

/**
 * \brief This function calculates the radar cycle timing schedule.
 *
 * \details This function is called by rfeSwMainFsm_mainState_configuring()
 * and rfeSwMainFsm_radarCyclesState_begin().
 *
 * \pre NIL
 *
 * \param [in]      pRfeConfig_arg - The RFE Config.
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #RFE_ERROR_IS_NO_ERROR is true,
 *                  On failure #RFE_ERROR_IS_ERROR is true
 *
 * \return const rfeSwMainFsm_radarCycleTimingSchedule_t* - Pointer to the radar cycle timing schedule.
 *
 * \post NIL
 *
 * \ingroup NIL
 */
const rfeSwMainFsm_radarCycleTimingSchedule_t* rfeSwMainFsm_calcRadarCycleTimingSchedule(
    const uint8_t *pRfeConfig_arg, rfe_error_t* rfe___error___pointer);

/**
 * \brief This function calculates the chirp sequence duration.
 *
 * \details This function is called by rfeSwMainFsm_calcRadarCycleTimingSchedule().
 *
 * \pre NIL
 *
 * \param [in]      pRfeConfig_arg - The RFE Config.
 * \param [in]      chirpSequenceConfigIndex - The chirp sequence configuration index.
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #RFE_ERROR_IS_NO_ERROR is true,
 *                  On failure #RFE_ERROR_IS_ERROR is true
 *
 * \return uint32_t - The chirp sequence duration in ticks
 *
 * \post NIL
 *
 * \ingroup NIL
 */
uint32_t rfeSwMainFsm_calcChirpSequenceDuration(const uint8_t *pRfeConfig_arg,
        rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, rfe_error_t* rfe___error___pointer);


/******************************************************************************
 *                       PUBLIC FUNCTIONS (API FUNCTIONS)
 *****************************************************************************/

/**
 * \brief This function starts the configured radar cycle.
 *
 * \details The configured radar cycle is started at \p startTime or
 * as soon as possible depending on the \p isScheduled parameter.
 * This function is called by the rfeCmdServerDispatcher.
 *
 * \pre Main state must be #rfeSwMainFsm_mainState_configured_e.
 *
 * \param [in]      radarCycleCount - Number of radar cycles to start.
 *                  A value of 0 indicates an infinite number of radar cycles,
 *                  i.e. until stopped by rfe_radarCycleStop().
 * \param [in]      isScheduled - If true, radar cycle starts at \p startTime.
 *                  If false, radar cycle starts as soon as possible.
 * \param [in]      startTime - The absolute start time in 25 [ns] resolution of the chirp
 *                  sequence according to the RFE time.
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #RFE_ERROR_IS_NO_ERROR is true,
 *                  On failure #RFE_ERROR_IS_ERROR is true
 *
 * \return NIL
 *
 * \post Main state becomes #rfeSwMainFsm_mainState_startRadarCycles_e.
 *
 * \ingroup NIL
 */
void rfeSwMainFsm_radarCycleStart(uint16_t radarCycleCountParam, bool isScheduled, uint32_t startTime, rfe_error_t* rfe___error___pointer);

/**
 * \brief This function stops the active radar cycle.
 *
 * \details This function is called by the rfeCmdServerDispatcher.
 *
 * \pre Main state must be #rfeSwMainFsm_mainState_radarCycles_e.
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #RFE_ERROR_IS_NO_ERROR is true,
 *                  On failure #RFE_ERROR_IS_ERROR is true
 *
 * \return uint16_t - Index of the active radar cycle at which we stop.
 *
 * \post Main state becomes #rfeSwMainFsm_mainState_configured_e.
 *
 * \ingroup NIL
 */
uint16_t rfeSwMainFsm_radarCycleStop(rfe_error_t* rfe___error___pointer);

/**
 * \brief This function returns the active RFE FuSa faults.
 *
 * \details This function returns the active RFE FuSa faults. It is to be used
 * when a FuSa fault occured. This function is called by the rfeCmdServerDispatcher.
 *
 * \pre The RFE must be in the rfe_state_fuSaFault_e states
 *
 * \param [out]     pFuSaFaults  - pointer to structure containing fault status for R1 and R2 type fault,
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
void rfeSwMainFsm_getFuSaFaults(uint8_t *pFuSaFaults,rfe_error_t* rfe___error___pointer);
/**
 * \brief This function returns the active RFE FuSa faults.
 *
 * \details This function returns the active RFE FuSa faults. It is to be used
 * when a FuSa fault occured. This function is called by the rfeCmdServerDispatcher.
 *
 * \pre The RFE must be in the rfe_state_fuSaFault_e states
 *
 * \param [out]     pFuSaFaults  - pointer to structure containing fault status for R1 and R2 type fault,
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
void rfeSwMainFsm_getFuSaFaultStatistics(rfeSwFuSaMngr_fuSaFault_t *pFuSaFaults, rfe_error_t* rfe___error___pointer);

/**
 * \brief This function returns the scheduled absolute start time of the next radar cycle.
 *
 * \details The returned time is according to the RFE time.
 * This function is called by the rfeCmdServerDispatcher.
 *
 * \pre NIL
 *
 * \param [out]     pRadarCycleIndex - Pointer to index of the next radar cycle
 *                  of which the start time is returned.
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #RFE_ERROR_IS_NO_ERROR is true,
 *                  On failure #RFE_ERROR_IS_ERROR is true
 *
 * \return uint32_t - Absolute start time of the next scheduled radar cycle in 25 [ns] resolution.
 *
 * \post NIL
 *
 * \ingroup NIL
 */
uint32_t rfeSwMainFsm_getNextRadarCycleStartTime(uint16_t *pRadarCycleCount, rfe_error_t* rfe___error___pointer);

/**
 * \brief This function updates the start time of the next radar cycle.
 *
 * \details rfe_radarCycleStart() starts one or multiple radar cycles immediately or
 * at a schedule time, with a certain period ( \ref radarCycleDuration), as per the configuration.
 * This function updates the absolute start time of the next radar cycle according to the RFE time.
 * That radar cycle will thereby be delayed or pulled in. Subsequent radar cycles will shift in
 * time accordingly to maintain the configured \ref radarCycleDuration. This functionality
 * can be used to synchronize multiple radar sensors in time.
 * This function is called by the rfeCmdServerDispatcher.
 *
 * \pre NIL
 *
 * \param [in]      startTime - Absolute start time of the next radar cycle in 25 [ns] resolution.
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #RFE_ERROR_IS_NO_ERROR is true,
 *                  On failure #RFE_ERROR_IS_ERROR is true
 *
 * \return uint16_t - Index of the next radar cycle of which the start time is set.
 *
 * \post Next radar cycle starts at the given start time.
 *
 * \ingroup NIL
 */
uint16_t rfeSwMainFsm_setNextRadarCycleStartTime(uint32_t startTime, rfe_error_t* rfe___error___pointer);

/**
 * \brief This function will read-out one or more RFE monitors.
 *
 * \details Monitors to be read are selected by \p monitorSelect.
 * This function is called by the rfeCmdServerDispatcher.
 *
 * \pre NIL
 *
 * \param [in]      monitorSelect - Selection of the RFE monitors to read-out
 * \param [out]     pRadarCycleCount - The radar cycle and chirp sequence count,
 *                  indicating when the monitors were read.
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #RFE_ERROR_IS_NO_ERROR is true,
 *                  On failure #RFE_ERROR_IS_ERROR is true
 *
 * \return rfe_monitorValues_t* - A pointer to the monitor values.
 *
 * \post NIL
 *
 * \ingroup NIL
 */
rfe_monitorValues_t* rfeSwMainFsm_monitorRead(rfe_monitorSelect_t monitorSelect,
    rfe_radarCycleCount_t *pRadarCycleCount, rfe_error_t* rfe___error___pointer);

/**
 * \brief This function start continuous wave tranmission.
 *
 * \details It uses the RFE profile as configured via rfe_configure()
 * as specified by \p profileIndex. The effective chirp bandwidth of this
 * profile is neglected. The frequency is kept at the configured center
 * frequency. This function is called by the rfeCmdServerDispatcher.
 *
 * \pre Main state must be #rfeSwMainFsm_mainState_configured_e.
 *
 * \param [in]      profileIndex - Index of the chirp profile to be used for
 *                  the test mode.
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #RFE_ERROR_IS_NO_ERROR is true,
 *                  On failure #RFE_ERROR_IS_ERROR is true
 *
 * \return NIL
 *
 * \post Main state becomes #rfeSwMainFsm_mainState_testContinuousWaveTransmission_e.
 *
 * \ingroup NIL
 */
void rfeMainFsm_continuousWaveTransmissionStart(rfe_chirpProfileIndex_t profileIndex,
        rfe_error_t* rfe___error___pointer);

/**
 * \brief This function stops continuous wave tranmission.
 *
 * \details Continuous wave transmission can be started via rfe_testContinuousWaveTransmissionStart().
 * This function is called by the rfeCmdServerDispatcher.
 *
 * \pre Main state must be #rfeSwMainFsm_mainState_testContinuousWaveTransmission_e.
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #RFE_ERROR_IS_NO_ERROR is true,
 *                  On failure #RFE_ERROR_IS_ERROR is true
 *
 * \return NIL
 *
 * \post Test modes becomes inactive
 *
 * \ingroup NIL
 */
void rfeMainFsm_continuousWaveTransmissionStop(rfe_error_t* rfe___error___pointer);

/**
 * \brief This function returns the RFE time.
 *
 * \details It returns the absolute RFE time since RFE initialization
 * in 25[ns] resolution. The counter wrap around time is equal
 * to 2^32 * 25 ns, which is approximately 107 seconds.
 *  This function is called by the rfeCmdServerDispatcher.
 *
 * \pre NIL
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #RFE_ERROR_IS_NO_ERROR is true,
 *                  On failure #RFE_ERROR_IS_ERROR is true
 *
 * \return uint32_t - Absolute RFE time since initialization in 25 [ns] resolution.
 *
 * \post NIL
 *
 * \ingroup NIL
 */
uint32_t rfeSwMainFsm_getTime(rfe_error_t* rfe___error___pointer);

/**
 * \brief This function returns the internal error from mainFSM.
 *
 * \details It returns the internal error code.
 *  This function is called by the rfeCmdServerDispatcher.
 *
 * \pre NIL
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #RFE_ERROR_IS_NO_ERROR is true,
 *                  On failure #RFE_ERROR_IS_ERROR is true
 *
 * \return rfeSwMainFsm_fwInternalErrorCode_t - Internal error code
 *
 * \post NIL
 *
 * \ingroup NIL
 */
rfeSwMainFsm_fwInternalErrorCode_t rfeSwMainFsm_testGetInternalErrors(rfe_error_t* rfe___error___pointer);

/**
 * \brief This function gets zero hour reference data for RX bist.
 *
 * \details This function returns zero hour reference data for RX bist.
 * This function is called by the rfeCmdServerDispatcher.
 *
 * \pre NIL
 *
 * \param [out]     rfeSwBist_rxBistReferenceData_t  - pointer to structure containing zero hour RX bist reference data.
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #RFE_ERROR_IS_NO_ERROR is true,
 *                  On failure #RFE_ERROR_IS_ERROR is true*
 * \post NIL
 *
 * \ingroup NIL
 */
void rfeSwMainFsm_getBistZeroHourReferenceData(rfeSwBist_rxBistReferenceData_t *zeroHourData, rfe_error_t* rfe___error___pointer);

#endif // !RFE_SW_MAIN_FSM_H

