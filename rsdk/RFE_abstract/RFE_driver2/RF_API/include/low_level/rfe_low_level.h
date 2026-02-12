/*
* Copyright 2022-2023 NXP
*
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and
* may only be used strictly in accordance with the applicable license terms.  By
* expressly accepting such terms or by downloading, installing, activating and/or
* otherwise using the software, you are agreeing that you have read, and that you
* agree to comply with and are bound by, such license terms.  If you do not agree to
* be bound by the applicable license terms, then you may not retain, install, activate or
* otherwise use the software.
*/


/******************************************************************************
 *   Project              : RF_Abstract_2.0
 *   Platform             : S32R41
 *****************************************************************************/

#ifndef RFE_ABSTRACT_API_H
#define RFE_ABSTRACT_API_H


/******************************************************************************
 *                              INCLUDES
 *****************************************************************************/
#include "rfe_cfg_blob.h"
#include "rfe_blob_access.h"
#include "rfe_error.h"
#include "rfe_types.h"
#include "rfe_register_dump.h"

/**
*   @addtogroup rsdk_rfe_interface
*   @{
*
*/

/******************************************************************************
 *                              FUNCTIONS
 *****************************************************************************/
/**
 *
 *  \brief This function synchronizes the rfeDriver on M7-0 core with the RFE-Fw running on M7-1 core.
 *
 *  \details This is the first RFE Driver function to be called. The first call to this
 *  function initiates the control core <-> RFE-Fw synchronization protocol and always fails.
 *  This function shall be called until the #rfe_error_api_unresponsive_e error is not set anymore,
 *  which indicates that the synchronization protocol was executed successfully.
 *  The error is get using CDD_Rfe_GetError() funtion.
 *
 *  This function can set one of following errors:
 *  - #rfe_error_api_unresponsive_e
 *  - #rfe_error_sharedData_redundancyCheckFailed_e
 *
 *  \pre The RFE-Fw (M7-1 core) must be started.
 *
 *  \param [in,out] rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 *  \post RFE-Fw will be in #rfe_state_initialized_e state after the correct initialization.
 *
 */
void rfe_sync(volatile rfe_error_t* rfe___error___pointer);


/*================================================================================================*/
/**
 *  \brief This function fully configures the RFE-Fw.
 *
 *  \details This function copies the provided configuration and dynamic tables to the RFE-Fw and verifies the response.
 *  This function returns only after RFE-Fw has processed the command and responded.
 *  Asynchronously, after this command is processed, the RFE-Fw performs the configuration and calibrations.
 *
 *  If error occur, CDD_Rfe_GetError must retur one of :
 *  - #rfe_error_api_unsynchronized_e
 *  - #rfe_error_api_operationNotAllowed_e
 *  - #rfe_error_api_busy_e
 *  - #rfe_error_api_invalidArgumentValue_e
 *  - #rfe_error_api_invalidConfigurationSize_e
 *  - #rfe_error_api_invalidConfigurationParameterValue_e
 *  - #rfe_error_api_invalidDynamicTableSize_e
 *  - #rfe_error_api_invalidDynamicTableValue_e
 *  - #rfe_error_api_invalidRadarCycleTimeSchedule_e
 *  - Any rfe_error_api_configParamCrossCheck_... error of #rfe_error_t.
 *  - Any rfe_error_cmdInterface_... error of #rfe_error_t.
 *  - #rfe_error_sharedData_redundancyCheckFailed_e
 *  - #rfe_error_rfeFuSaFault_e
 *
 *  \pre The RFE-Fw must be in #rfe_state_initialized_e state, or in #rfe_state_configured_e state.
 *
 *  \param [in]      pConfig - Pointer to Configuration Data Memory (see \ref rsdk_rfe_blob)
 *  \param [in]      dynamicTableAddress - Address of the dynamic tables in system memory.
 *                   The dynamic tables created by the rfe configuration generator need
 *                   to be loaded or copied to this address in system memory before calling
 *                   this API function. Set to NULL when dynamic table is not used.
 *  \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                   On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                   On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 *  \post RFE-Fw state becomes #rfe_state_busy_e and RFE-Fw performs configuration and calibrations asynchronously.
 *  When done, RFE-Fw state becomes #rfe_state_configured_e.
 *
 */
void rfe_configure(uint8_t *pConfig, rfe_sysMemAddress_t dynamicTableAddress,
                    volatile rfe_error_t* rfe___error___pointer);


/*================================================================================================*/
/**
 *
 *  \brief This function starts the configured radar cycles.
 *
 *  \details The configured radar cycles are started at \p startTime or as soon as possible depending on the
 *  \p isScheduled parameter. The radar cycle start can be scheduled from 10 us up to 1000 ms in the future
 *  (time interval started after the reception of the API call by the RFE-Fw).
 *  This function returns only after RFE-Fw has processed the command and responded.
 *
 *  This function can return one of following errors:
 *  - #rfe_error_api_unsynchronized_e
 *  - #rfe_error_api_operationNotAllowed_e
 *  - #rfe_error_api_busy_e
 *  - #rfe_error_api_invalidArgumentValue_e
 *  - Any _cmdInterface_ error of #rfe_error_t.
 *  - #rfe_error_sharedData_redundancyCheckFailed_e
 *  - #rfe_error_rfeFuSaFault_e
 *
 *  \pre The RFE-Fw must be in #rfe_state_configured_e state.
 *
 *  \param [in]      radarCycleCount - Number of radar cycles to start.
 *                      0 indicates an infinite number of radar cycles, until stopped by Cdd_Rfe_radarCycleStop().
 *  \param [in]      isScheduled - If true, radar cycle starts at \p startTime. If false, radar cycle starts asap.
 *  \param [in]      startTime - The absolute start time delay in 25 [ns] resolution, according to the RFE-Fw time.
 *  \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                   On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                   On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 *  \post When the API call is accepted and radar cycle is started, RFE-Fw state will become #rfe_state_busy_e
 *  during the the calibration, BIST and chirp sequences.
 *  During the radar cycle idle windows the state is #rfe_state_radarCycleIdle_e.
 *  RFE-Fw state returns to #rfe_state_configured_e, when all radar cycles are completed.
 *
 */
void rfe_radarCycleStart(uint16_t radarCycleCount, bool isScheduled, uint32_t startTime,
        volatile rfe_error_t* rfe___error___pointer);


/*================================================================================================*/
/**
 *
 *  \brief This function stops the active radar cycles.
 *
 *  \details The active radar cycle will not be finished, but it is stopped as soon as the command has been received.
 *  Pending parameters update will be cancelled.
 *  It can be called, for example, when the  application needs  to do a full
 *  reconfiguration or needs to go to a lower power mode or for any external event
 *  where active radar cycle needs to be stopped. It returns after RFE-Fw has accepted or rejected the call.
 *
 *  This function can return one of following errors:
 *  - #rfe_error_api_unsynchronized_e
 *  - #rfe_error_api_operationNotAllowed_e
 *  - #rfe_error_api_busy_e
 *  - Any _cmdInterface_ error of #rfe_error_t.
 *  - #rfe_error_sharedData_redundancyCheckFailed_e
 *  - #rfe_error_rfeFuSaFault_e
 *
 *  \pre The RFE-Fw state must be #rfe_state_radarCycleIdle_e.
 *
 *  \param [in,out] rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 *  \return uint16  - Index of the active radar cycle at which radar cycle was stopped.
 *
 *  \post Radar cycle is stopped and RFE-Fw state returns to #rfe_state_configured_e.
 *
 */
uint16_t rfe_radarCycleStop(volatile rfe_error_t* rfe___error___pointer);


/*================================================================================================*/
/**
 *
 *  \brief This function returns the RFE-Fw state.
 *
 *  \details This function does not interact with the RFE-Fw, returning the state information from the shared memory.
 *
 *  This function can return one of following errors:
 *  - #rfe_error_api_unsynchronized_e
 *  - #rfe_error_sharedData_redundancyCheckFailed_e
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 *  \return Cdd_RfeStateType - The RFE-Fw state
 *
 */
rfe_state_t rfe_getState(volatile rfe_error_t* rfe___error___pointer);


/*================================================================================================*/
/**
 *
 *  \brief This function returns the radar cycle and chirp sequence count.
 *
 *  \details It returns the number radar cycles and chirp sequences completed since Cdd_Rfe_radarCycleStart().
 *  It can be used to keep track of the radar cycle or chirp sequence execution.
 *  This function does not interact with the RFE-Fw, instead it returns information from a shared memory location.
 *
 *  This function can return one of following errors:
 *  - #rfe_error_api_unsynchronized_e
 *  - #rfe_error_sharedData_redundancyCheckFailed_e
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 *  \return Cdd_RfeRadarCycleCountType - Structure that contains the radar cycle and chirp sequence count.
 *
 */
rfe_radarCycleCount_t rfe_getRadarCycleCount(volatile rfe_error_t* rfe___error___pointer);


/*================================================================================================*/
/**
 * \brief This function provides the RFE-Fw FuSa faults which are set in RFE-Fw FCCU.
 * \details This function has to be used when a FuSa fault occurs, which is indicated by the ERROR_N signal
 * and can also be observed by CDD_Rfe_GetState() returning #rfe_state_fuSaFault_e.
 *
 * This function can return one of following errors:
 * - #rfe_error_api_unsynchronized_e
 * - #rfe_error_api_operationNotAllowed_e
 * - #rfe_error_api_busy_e
 * - #rfe_error_api_invalidArgumentValue_e
 * - Any _cmdInterface_ error of #rfe_error_t.
 * - #rfe_error_rfeFuSaFault_e
 *
 * \pre The RFE-Fw must be in one of the following states:
 * - #rfe_state_initialized_e
 * - #rfe_state_configured_e
 * - #rfe_state_radarCycleIdle_e
 * - #rfe_error_rfeFuSaFault_e
 *
 * \param [out]     pFuSaR1R2FaultList - Pointer to an array, where this function will store the list of
 *                  fusa faults. The size of this array must be \b RFE_FUSA_R1_R2_MASK_UNMASK_FAULT_BYTE_COUNT bytes.
 *                  The enumeration \b rfe_fuSaFault_t must be used as bit index to determine the fault from
 *                  the \b pFuSaR1R2FaultList e.g., if byte index 3 of \b pFuSaR1R2FaultList has the value
 *                  b0010000, it means bit position 5 of fuSaFaultMask3 is set, i.e rfe_fuSaFault_sr47_lo_level_max_rx1_e fault is set.
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * \post This function does not result in change of RFE-Fw state.
 *
 */
void rfe_getFuSaFaults(uint8_t *pFuSaR1R2FaultList, volatile rfe_error_t* rfe___error___pointer);


/*================================================================================================*/
/**
 * \brief This function provides the fault statistics for R1 faults.
 * \details This function provides list of fault occurrence count for each R1 fault.
 * Whenever a R1 fault is detected, the corresponding counter is incremented.
 * Each counter can reach up to a maximum value of 0xFF and stays at this level until reset.
 * The counter is reset as part of RFE-Fw initialization upon
 *  - Functional reset.
 *  - Destructive reset.
 *  - Power on reset.
 *
 * The \b pFuSaR1FaultCountList is of fixed size #RFE_FUSA_R1_FAULT_COUNT_MAX and does
 * not decrease even when R1 fault is promoted to R2 ( refer \ref rfeCfg_param_monitorAndSafety_thresholdValueToPromoteR1Faults_e ).
 * The \b pR1FaultPromotedToR2Since will indicate which R1 fault was promoted to R2.
 *
 * This function returns after RFE-Fw has accepted or rejected the call.
 *
 * This function can return one of following errors:
 * - #rfe_error_api_unsynchronized_e
 * - #rfe_error_api_operationNotAllowed_e
 * - #rfe_error_api_busy_e
 * - #rfe_error_api_invalidArgumentValue_e
 * - Any _cmdInterface_ error of #rfe_error_t.
 * - #rfe_error_rfeFuSaFault_e
 *
 * \pre The RFE-Fw must be in one of the following states:
 * - #rfe_state_initialized_e
 * - #rfe_state_configured_e
 * - #rfe_state_radarCycleIdle_e
 * - #rfe_error_rfeFuSaFault_e
 *
 * \param [out]     pR1FaultPromotedToR2 - Indicates the R1 fault which is promoted to R2.
 * \param [out]     pRadarCycleCount - Pointer to structure which provides Radar cycle count and Chirp sequence
 *                  count. The count in \b pRadarCycleCount is updated whenever the fault occurrence count is
 *                  updated. If there is no active radar cycle, the radar cycle count and chirp sequence count
 *                  value will be 0x00 each.
 * \param [out]     pFuSaR1FaultCountList - Pointer to an array containing fault occurrence count for each R1
 *                  fault. The size of this array should be RFE_FUSA_R1_FAULT_COUNT_MAX bytes.
 *                  The rfe_fuSaFault_t up to index value rfe_fuSaFault_R1_sm11_bist_tx4_sw_e bytes, must be used
 *                  to index the list to determine the fault occurrence count for the corresponding fault
 *                  e.g., the value in \b pFuSaCountList[rfe_fuSaFault_R1_sm11_bist_tx4_sw_e]
 *                  provides the fault occurrence count for rfe_fuSaFault_R1_sm11_bist_tx4_sw_e.
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * \post This function does not result in change of RFE-Fw state.
 *
 * \remark
 * -# The functions CDD_Rfe_GetFuSaFaults(), CDD_Rfe_RadarCycleStart() and CDD_Rfe_RadarCycleStop()
 *  do not affect the counter values.
 * -# The \ref rfeCfg_param_monitorAndSafety_thresholdValueToPromoteR1Faults_e has no relation to the counter used in CDD_Rfe_GetFuSaFaultStatistics().
 *
 */
void rfe_getFuSaFaultStatistics(uint16_t *pR1FaultPromotedToR2, rfe_radarCycleCount_t *pRadarCycleCount,
                                uint8_t *pFuSaR1FaultCountList, volatile rfe_error_t* rfe___error___pointer);


/*================================================================================================*/
/**
 * \brief This function returns RX BIST measurement details to be used as zero hour reference data.
 *
 * \details The RFE-Fw performs the RX phase difference and RX gain difference
 * measurements upon this function call. 
 *
 * This function can return one of following errors:
 * - #rfe_error_api_unsynchronized_e
 * - #rfe_error_api_operationNotAllowed_e
 * - #rfe_error_api_busy_e
 * - Any _cmdInterface_ error of #rfe_error_t.
 * - #rfe_error_rfeFuSaFault_e
 *
 * \pre The RFE-Fw must be in #rfe_state_configured_e.
 *
 * \param [out]      pRxReferenceData  - pointer to structure containing zero hour RX bist reference data.
 * \param [in,out]   rfe___error___pointer - Error handling parameter:
 *                   On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                   On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * \remark
 *  -# The configuration that changed due to  execution of CDD_Rfe_GetBistZeroHourReferenceData() will be restored to
 *  configuration that existed before the function call.
 *  -# The threshold values (\ref monitorAndSafety ) to be used along with zero hour data are determined after
 * characterization.
 * \post This function does not result in change of RFE-Fw state.
 *
 * \ingroup NIL
 */
void rfe_getBistZeroHourReferenceData(rfeCfg_rxBistReferenceData_t *pRxReferenceData, volatile rfe_error_t* rfe___error___pointer);


/*================================================================================================*/
/**
 *
 *  \brief This function returns the RFE-Fw time.
 *
 *  \details It returns the absolute RFE-Fw time since the initialization in 25[ns] resolution.
 *  The counter wrap around time is equal to 2^32 * 25 ns, which is approximately 107 seconds.
 *  This function returns after RFE-Fw has accepted or rejected the call.
 *
* T his function can return one of following errors:
 *  - #rfe_error_api_unsynchronized_e
 *  - #rfe_error_api_operationNotAllowed_e
 *  - #rfe_error_api_busy_e
 *  - Any _cmdInterface_ error of #rfe_error_t.
 *  - #rfe_error_sharedData_redundancyCheckFailed_e
 *  - #rfe_error_rfeFuSaFault_e
 *
 *  \pre The RFE-Fw must be in one of the following states:
 *  - #rfe_state_initialized_e
 *  - #rfe_state_configured_e
 *  - #rfe_state_radarCycleIdle_e
 *
 *  \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                   On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                   On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 *  \return uint32_t - Absolute RFE-Fw time since initialization in 25 [ns] resolution.
 *
 */
uint32_t rfe_getTime(volatile rfe_error_t* rfe___error___pointer );


/*================================================================================================*/
/**
 *
 *  \brief This function returns version and variant details of the RFE-Fw hardware and firmware.
 *
 *  \details This function returns after RFE-Fw has accepted or rejected the call.
 *
 *  This function can return one of following errors:
 *  - #rfe_error_api_unsynchronized_e
 *  - #rfe_error_api_operationNotAllowed_e
 *  - #rfe_error_api_busy_e
 *  - Any _cmdInterface_ error of #rfe_error_t.
 *  - #rfe_error_sharedData_redundancyCheckFailed_e
 *  - #rfe_error_rfeFuSaFault_e
 *
 *  \pre The RFE-Fw must be in one of the following states:
 *  - #rfe_state_initialized_e
 *  - #rfe_state_configured_e
 *  - #rfe_state_radarCycleIdle_e
 *
 *  \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                   On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                   On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 *  \return Cdd_RfeVersionType - Structure containing RFE-Fw variant and version details.
 *
 */
rfe_version_t rfe_getVersion(volatile rfe_error_t* rfe___error___pointer);


/*================================================================================================*/
/**
 *
 *  \brief This function will read-out one or more RFE-Fw monitors.
 *
 *  \details Monitors to be read are selected by \p monitorSelect.
 *
 *  This function returns after RFE-Fw has accepted or rejected the API call.
 *
 *  This function can return one of following errors:
 *  - #rfe_error_api_unsynchronized_e
 *  - #rfe_error_api_operationNotAllowed_e
 *  - #rfe_error_api_busy_e
 *  - #rfe_error_api_invalidArgumentValue_e
 *  - Any _cmdInterface_ error of #rfe_error_t.
 *  - #rfe_error_sharedData_redundancyCheckFailed_e
 *  - #rfe_error_rfeFuSaFault_e
 *
 *  \pre The RFE-Fw must be in one of the following states:
 *  - #rfe_state_initialized_e
 *  - #rfe_state_configured_e
 *  - #rfe_state_radarCycleIdle_e (#RFE_MONITOR_SELECT_TEMP_IMMEDIATELY bit of \p monitorSelect must be '0')
 *  - #rfe_state_testContinuousWaveTransmission_e
 *
 *  \param [in]      monitorSelect - Selection of the RFE-Fw monitors to read-out
 *  \param [out]     *pMonitorValues - The monitor values will be written to this pointer
 *  \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                   On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                   On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 *  \return Cdd_RfeRadarCycleCountType - The radar cycle and chirp sequence count,
 *  indicating when the monitors were read.
 *
 */
rfe_radarCycleCount_t rfe_monitorRead(rfe_monitorSelect_t monitorSelect, rfe_monitorValues_t *pMonitorValues,
                                volatile rfe_error_t* rfe___error___pointer);


/*================================================================================================*/
/**
 *
 *  \brief This function returns the scheduled absolute start time of the next radar cycle
 *
 *  \details The returned time is according to the RFE-Fw time.
 *  This function returns after RFE-Fw has accepted or rejected the call.
 *
 *  This function can return one of following errors:
 *  - #rfe_error_api_unsynchronized_e
 *  - #rfe_error_api_operationNotAllowed_e
 *  - #rfe_error_api_busy_e
 *  - #rfe_error_api_invalidArgumentValue_e
 *  - Any _cmdInterface_ error of #rfe_error_t.
 *  - #rfe_error_sharedData_redundancyCheckFailed_e
 *  - #rfe_error_rfeFuSaFault_e
 *
 *  \pre The RFE-Fw must be in #rfe_state_radarCycleIdle_e state.
 *
 *  \param [out]     *pRadarCycleIndex - Pointer to index of the next radar cycle of which the start time is returned.
 *  \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                   On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                   On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 *  \return uint32   - Absolute start time of the next scheduled radar cycle in 25 [ns] resolution.
 *
 */
uint32_t rfe_getNextRadarCycleStartTime(uint16_t *pRadarCycleIndex, volatile rfe_error_t* rfe___error___pointer);


/*================================================================================================*/
/**
 *
 *  \brief This function updates the start time of the next radar cycle
 *
 *  \details Cdd_Rfe_radarCycleStart() starts one or multiple radar cycles immediately or at a schedule time,
 *  with a certain period ( \ref radarCycleDuration), as per the configuration.
 *  This function updates the absolute start time of the next radar cycle according to the RFE-Fw time.
 *  That radar cycle will thereby be delayed or pulled in. Subsequent radar cycles will shift in
 *  time accordingly to maintain the configured \ref radarCycleDuration.
 *  This functionality can be used to synchronize multiple radar sensors in time.
 *  The next radar cycle start time can be delayed up to 100 ms and should not conflict with
 *  the current radar cycle time schedule (in case of pull in).
 *  This function returns after RFE-Fw has accepted or rejected the API call.
 *
 *  This function can return one of following errors:
 *  - #rfe_error_api_unsynchronized_e
 *  - #rfe_error_api_operationNotAllowed_e
 *  - #rfe_error_api_busy_e
 *  - #rfe_error_api_invalidArgumentValue_e
 *  - Any _cmdInterface_ error of #rfe_error_t.
 *  - #rfe_error_sharedData_redundancyCheckFailed_e
 *  - #rfe_error_rfeFuSaFault_e
 *
 *  \pre The RFE-Fw must be in #rfe_state_radarCycleIdle_e state.
 *
 *  \param [in]      startTime - Absolute start time of the next radar cycle in 25 [ns] resolution.
 *  \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                   On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                   On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 *  \return uint16   - Index of the next radar cycle of which the start time is set.
 *
 *  \post Next radar cycle starts at the given start time.
 *
 */
uint16_t rfe_setNextRadarCycleStartTime(uint32_t startTime, volatile rfe_error_t* rfe___error___pointer);


/*================================================================================================*/
/**
 *  \brief This function begins a RFE configuration update operation.
 *
 *  \details When the RFE Configuration ( as set via Cdd_Rfe_configure()) is required to
     be updated then this is the first function
 *  to be called. This function will clear the buffered RFE configuration.
 *  This function does not interact with the RFE, instead it buffers data locally.
 *  This function does not return any error.
 *
 *  \post The functions Cdd_Rfe_updateParam() and/or Cdd_Rfe_updateDynamicTable()
 *  must be called after this function
 *  to buffer the configuration and then push the configuration
 *  into RFE FW via the configuration update via Cdd_Rfe_updatePush().
 *
 */
void rfe_updateBegin(void);


/*================================================================================================*/
/**
 *
 *  \brief This function start continuous wave tranmission.
 *
 *  \details It uses the RFE-Fw profile as configured via rfe_configure() as specified by \p profileIndex.
 *  The effective chirp bandwidth of this profile is neglected.
 *  The frequency is kept at the configured center frequency.
 *  This function  returns after RFE-Fw has accepted or rejected the call.
 *
 *   This function can sets one of following errors:
 *  - #rfe_error_api_unsynchronized_e
 *  - #rfe_error_api_operationNotAllowed_e
 *  - #rfe_error_api_busy_e
 *  - #rfe_error_api_invalidArgumentValue_e
 *  - Any _cmdInterface_ error of #rfe_error_t.
 *  - #rfe_error_sharedData_redundancyCheckFailed_e
 *  - #rfe_error_rfeFuSaFault_e
 *
 *  \pre RFE-Fw must be in #rfe_state_configured_e state.
 *
 *  \param [in]      section - the section mask, as in rfeCfg_section_tenum
 *  \param [in]      param - index of the parameter to be updated, as in rfe_paramUpdate_t
 *  \param [in]      value - the new value of the parameter
 *  \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                   On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                   On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 *  \post RFE goes to  #rfe_state_testContinuousWaveTransmission_e state.
 *
 */
void rfe_updateParam(rfeCfg_section_t section, rfe_paramUpdate_t param, uint32_t value,
                            volatile rfe_error_t* rfe___error___pointer);


/*================================================================================================*/
/**
 *
 *  \brief This function stops continuous wave tranmission.
 *
 *  \details Continuous wave transmission can be started via rfe_testContinuousWaveTransmissionStart().
 *  This function returns whether RFE-Fw has accepted or rejected the call.
 *
 *   This function can sets one of following errors:
 *  - #rfe_error_api_unsynchronized_e
 *  - #rfe_error_api_operationNotAllowed_e
 *  - #rfe_error_api_busy_e
 *  - Any _cmdInterface_ error of #rfe_error_t.
 *  - #rfe_error_sharedData_redundancyCheckFailed_e
 *  - #rfe_error_rfeFuSaFault_e
 *
 *  \param [in]     dynamicTableIndex - the index of the dynamic table to be updated
 *  \param [in]     paramsSelect      - the parameters selection
 *  \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                   On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                   On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 *  \pre RFE must be in #rfe_state_testContinuousWaveTransmission_e state.
 *
 *  \post RFE goes to  #rfe_state_configured_e state.
 *
 */
void rfe_updateDynamicTable(uint8_t dynamicTableIndex, rfe_dynParamsSelect_t paramsSelect,
                                volatile rfe_error_t* rfe___error___pointer);


/*================================================================================================*/
/**
 *
 *  \brief This function sets a test parameter.
 *
 *  \details This function returns whether RFE-Fw has accepted or rejected the call.
 *
 *   This function can sets one of following errors:
 *  - #rfe_error_api_unsynchronized_e
 *  - #rfe_error_api_operationNotAllowed_e
 *  - #rfe_error_api_busy_e
 *  - #rfe_error_api_invalidArgumentValue_e
 *  - Any _cmdInterface_ error of #rfe_error_t.
 *  - #rfe_error_sharedData_redundancyCheckFailed_e
 *  - #rfe_error_rfeFuSaFault_e
 *
 *  \pre The RFE-Fw must be in one of the following states:
 *  - #rfe_state_initialized_e
 *  - #rfe_state_configured_e
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 *  \return the radarCycleCount reported by the firmware
 *
 */
uint16_t rfe_updatePush(volatile rfe_error_t* rfe___error___pointer);


/*================================================================================================*/
/**
 * \brief This function start continuous wave transmission.
 *
 * \details It uses the RFE-Fw profile as configured via rfe_configure() as specified by \p profileIndex.
 * The effective chirp bandwidth of this profile is neglected.
 * The frequency is kept at the configured center frequency.
 * This function  returns after RFE-Fw has accepted or rejected the call.
 *
 * This function can return one of following errors:
 * - #rfe_error_api_unsynchronized_e
 * - #rfe_error_api_operationNotAllowed_e
 * - #rfe_error_api_busy_e
 * - #rfe_error_api_invalidArgumentValue_e
 * - Any _cmdInterface_ error of #rfe_error_t.
 * - #rfe_error_sharedData_redundancyCheckFailed_e
 * - #rfe_error_rfeFuSaFault_e
 *
 * \pre RFE must be in #rfe_state_configured_e state.
 *
 * \param [in]      profileIndex - Index of the chirp profile to be used for
 *                  continuous wave transmission.
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * \post RFE-Fw goes to  #rfe_state_testContinuousWaveTransmission_e state.
 *
 */
void rfe_testContinuousWaveTransmissionStart(rfe_chirpProfileIndex_t profileIndex,
                                volatile rfe_error_t* rfe___error___pointer);


/*================================================================================================*/
/**
 * \brief This function stops continuous wave transmission.
 *
 * \details Continuous wave transmission can be started via rfe_testContinuousWaveTransmissionStart().
 * This function returns after RFE-Fw has accepted or rejected the API call.
 *
 * This function can return one of following errors:
 * - #rfe_error_api_unsynchronized_e
 * - #rfe_error_api_operationNotAllowed_e
 * - #rfe_error_api_busy_e
 * - Any _cmdInterface_ error of #rfe_error_t.
 * - #rfe_error_sharedData_redundancyCheckFailed_e
 * - #rfe_error_rfeFuSaFault_e
 *
 * \pre RFE-Fw must be in #rfe_state_testContinuousWaveTransmission_e state.
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * \post RFE-Fw goes to  #rfe_state_configured_e state.
 *
 */
void rfe_testContinuousWaveTransmissionStop(volatile rfe_error_t* rfe___error___pointer );


/*================================================================================================*/
/**
 * \brief This function sets a test parameter.
 *
 * \details This function returns whether RFE-Fw has accepted or rejected the API call.
 *
 * This function can return one of following errors:
 * - #rfe_error_api_unsynchronized_e
 * - #rfe_error_api_operationNotAllowed_e
 * - #rfe_error_api_busy_e
 * - #rfe_error_api_invalidArgumentValue_e
 * - Any _cmdInterface_ error of #rfe_error_t.
 * - #rfe_error_sharedData_redundancyCheckFailed_e
 * - #rfe_error_rfeFuSaFault_e
 *
 * \pre The RFE-Fw must be in one of the following states:
 * - #rfe_state_initialized_e
 * - #rfe_state_configured_e
 *
 * \param [in]      testParam - The test parameter to set
 * \param [in]      value - The value to set
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 */
void rfe_testSetParam(rfe_testParam_t testParam, uint32_t value, volatile rfe_error_t* rfe___error___pointer);


/*================================================================================================*/
 /**
 *
 *  \brief This function provides the Internal error occured.
 *
 *  \details This function returns internal error code.
 * This function returns whether RFE has accepted or rejected the API call.
 *
 * This function can return one of following errors:
 * - #rfe_error_api_unsynchronized_e
 * - #rfe_error_api_operationNotAllowed_e
 * - #rfe_error_api_busy_e
 * - #rfe_error_api_invalidArgumentValue_e
 * - Any _cmdInterface_ error of #rfe_error_t.
 * - #rfe_error_sharedData_redundancyCheckFailed_e
 * - #rfe_error_rfeFuSaFault_e
 *
 *  \return     the error
 *
 */
uint32_t rfe_testGetInternalError(volatile rfe_error_t* rfe___error___pointer);


/*================================================================================================*/
/**
*
*   \brief      Function to get the complete registry status on one or many front-end(s)
*
*   \details    The function must be used only when the radar cycle is stopped else an error will be reported.
*               The returned values will be dumped in the result array pointed by dumpArrayPtr.
*               For the moment this function doesn't have a CDD equivalent.
*               It is the user duty to have enough space for the received data, please be aware of the :
*                   - rfe_registerDumpValues_t structure length
*                   - the expected number of registers to be dump for the requested module(s) found in rfe_register_dump.h as RFE_..._REG_NUMBER
*
* \param[in]        frontEndPos     - the Front-End to be used for registry dump
* \param[in]        moduleSelection - one or more modules to get the registry values
* \param[in]        dumpArrayPtr    - pointer to the data area to save the received data
* \param[in,out]    dumpArrayPtrLen - input - pointer to data array maximum length; output - the pointer receive the exact number of values returned
* \param [in,out]   rfe___error___pointer - Error handling parameter:
*                   On success #*rfe___error___pointer == rfe_error_none_e is true,
*                   On failure #*rfe___error___pointer != rfe_error_none_e is true
*
*/
void rfe_getRegisterDump(uint8_t frontEndPos, rfe_moduleDumpSelect_t moduleSelection, rfe_registerDumpValues_t *dumpArrayPtr,
                        uint32_t *dumpArrayPtrLen, volatile rfe_error_t* rfe___error___pointer);


/*================================================================================================*/
/**
*
*   \brief      Function to change the associated Front-End "subject" in a cascaded setup.
*
*   \details    The function must be used only in a cascaded setup, else an error will be returned.
*               The possible errors are :
*               - unresponsive
*               - not synchronized
*               - busy
*               - operation not allowed - only this is a specific error for this operation request, returned from RFE-Fw
*               - invalid argument
*
* \param[in]        frontEndPos - the Front-End to be used as conversation subject between the two cores
* \param [in,out]   rfe___error___pointer - Error handling parameter:
*                   On success #*rfe___error___pointer == rfe_error_none_e is true,
*                   On failure #*rfe___error___pointer != rfe_error_none_e is true
*
*/
void rfe_setFrontEnd(uint8_t frontEndPos, volatile rfe_error_t* rfe___error___pointer);


/*================================================================================================*/
/**
*
*   \brief      Function to get the associated Front-End "subject" in a cascaded setup.
*
*   \details    The function must be used only in a cascaded setup, else an error will be returned.
*               The possible errors are :
*               - unresponsive
*               - not synchronized
*               - busy
*               - operation not allowed - only this is a specific error for this operation request, returned from RFE-Fw
*
* \param [in,out]   rfe___error___pointer - Error handling parameter:
*                   On success #*rfe___error___pointer == rfe_error_none_e is true,
*                   On failure #*rfe___error___pointer != rfe_error_none_e is true
*
*/
uint8_t rfe_getFrontEnd(volatile rfe_error_t* rfe___error___pointer);

/**
 * \brief This function configure the RFE firmware interrupt.
 *
 * \details rfe_configureInterrupt() configures which conditions will raise
 *          an IRQ to \p coreId, these conditions are:
 *            - RFE state changes
 *            - Radar Cycle count changes
 *            - Chirp Sequence count changes
 *            - Specific RFE API responses from the firmware
 *
 *          The \p apiWaitForInterrupt function will be called while the driver is
 *          waiting for an RFE API response, this function shall return whenever a RFE
 *          firmware interrupt is received.
 *
 *          This is a user registered call back function where wait for interrupt or
 *          functionality to give control to Operating System can be implemented as per
 *          customer need.
 *
 *          This function may be called multiple times on a single RFE API call.
 *          During this call only APIs that do not interact with the firmware are allowed.
 *
 *          This function can return one of following errors:
 *          - #rfe_error_api_unsynchronized_e
 *          - #rfe_error_api_operationNotAllowed_e
 *          - #rfe_error_api_busy_e
 *          - #rfe_error_api_invalidArgumentValue_e
 *          - Any _cmdInterface_ error of #rfe_error_t.
 *          - #rfe_error_rfeFuSaFault_e
 *
 * \note \p apiWaitForInterrupt IS NOT an interrupt handler, the application code
 *       is responsible for setting up and handle incoming RFE interrupts.
 *
 * \pre The RFE must be in one of the following states:
 * - #rfe_state_initialized_e
 * - #rfe_state_configured_e
 * - #rfe_state_radarCycleIdle_e
 * - #rfe_error_rfeFuSaFault_e
 *
 * \param [in]      coreId - Which core should the RFE interrupt be sent.
 * \param [in]      events - Bitmask of events that will trigger an interrupt.
 * \param [in]      rfeAPIs - Bitmask of RFE-APIs responses that will trigger an interrupt.
 * \param [in]      apiWaitForInterrupt - API wait for interrupt function pointer.
 *                                        This is a user registered call back function where wait for interrupt or
 *                                        functionality to give control to Operating System can be implemented as per customer need.
 * \param [in,out]  rfe___error___pointer - Error handling parameter
 *
 * \ingroup NIL
 */
void rfe_configureInterrupt(
    rfe_coreId_t coreId,
    rfe_eventsIRQ_t events,
    rfe_apiIRQ_t rfeAPIs,
    rfe_apiWaitForInterrupt_f apiWaitForInterrupt,
    volatile rfe_error_t* rfe___error___pointer
);

/** @} */

#endif /* !RFE_ABSTRACT_API_H   */

