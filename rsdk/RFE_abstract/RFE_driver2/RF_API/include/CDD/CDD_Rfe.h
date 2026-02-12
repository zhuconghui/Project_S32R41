/*==================================================================================================
* Copyright 2022-2023 NXP
*
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and
* may only be used strictly in accordance with the applicable license terms.  By
* expressly accepting such terms or by downloading, installing, activating and/or
* otherwise using the software, you are agreeing that you have read, and that you
* agree to comply with and are bound by, such license terms.  If you do not agree to
* be bound by the applicable license terms, then you may not retain, install, activate or
* otherwise use the software.
==================================================================================================*/

#ifndef    CDD_RFE_H
#define    CDD_RFE_H


/**
*   @file
*   @implements CDD_Rfe.h_Artifact
*
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*
* @page misra_violations MISRA-C:2012 violations
*
* @section Cdd_Rfe_h_REF_1
* Violates MISRA 2012 Advisory Rule 20.1, ##Include directives should only be preceded by preprocessor directives or comments.
* <MA>_MemMap.h is included after each section define in order to set the current memory section as defined by AUTOSAR.
*
*/

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_Rfe_Cfg.h"
#include "CDD_Rfe_Types.h"
#include "CDD_Rfe_Irq.h"
#include "rsdk_version.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_RFE_AR_MODULE_ID                     2552
#define CDD_RFE_AR_INSTANCE_ID                   0
#define CDD_RFE_AR_VENDOR_ID                     43
#define CDD_RFE_AR_RELEASE_MAJOR_VERSION         RSDK_AR_MAJOR
#define CDD_RFE_AR_RELEASE_MINOR_VERSION         RSDK_AR_MINOR
#define CDD_RFE_AR_RELEASE_REVISION_VERSION      RSDK_AR_REV
#define CDD_RFE_SW_MAJOR_VERSION                 RSDK_SW_MAJOR
#define CDD_RFE_SW_MINOR_VERSION                 RSDK_SW_MINOR
#define CDD_RFE_SW_PATCH_VERSION                 RSDK_SW_PATCH

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if CDD_Rfe header file and CDD_Rfe_Types header file are of the same vendor */
#if (CDD_RFE_TYPES_VENDOR_ID != CDD_RFE_AR_VENDOR_ID)
    #error "CDD_Rfe.h and CDD_Rfe_Types.h have different vendor ids"
#endif

/* Check if CDD_Rfe header file and CDD_Rfe_Types header file are of the same Autosar version */
#if ((CDD_RFE_TYPES_AR_RELEASE_MAJOR_VERSION    != CDD_RFE_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_RFE_TYPES_AR_RELEASE_MINOR_VERSION    != CDD_RFE_AR_RELEASE_MINOR_VERSION) || \
     (CDD_RFE_TYPES_AR_RELEASE_REVISION_VERSION != CDD_RFE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Rfe_Types.h and CDD_Rfe.h are different"
#endif

/* Check if CDD_Rfe header file and CDD_Rfe_Types header file are of the same Software version */
#if ((CDD_RFE_TYPES_SW_MAJOR_VERSION != CDD_RFE_SW_MAJOR_VERSION) || \
     (CDD_RFE_TYPES_SW_MINOR_VERSION != CDD_RFE_SW_MINOR_VERSION) || \
     (CDD_RFE_TYPES_SW_PATCH_VERSION != CDD_RFE_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of CDD_Rfe_Types.h and CDD_Rfe.h are different"
#endif


/* Check if CDD_Rfe header file and CDD_Rfe_Cfg header file are of the same vendor */
#if (CDD_RFE_CFG_VENDOR_ID != CDD_RFE_AR_VENDOR_ID)
    #error "CDD_Rfe.h and CDD_Rfe_Types.h have different vendor ids"
#endif

/* Check if CDD_Rfe header file and CDD_Rfe_Cfg header file are of the same Autosar version */
#if ((CDD_RFE_CFG_AR_RELEASE_MAJOR_VERSION    != CDD_RFE_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_RFE_CFG_AR_RELEASE_MINOR_VERSION    != CDD_RFE_AR_RELEASE_MINOR_VERSION) || \
     (CDD_RFE_CFG_AR_RELEASE_REVISION_VERSION != CDD_RFE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Rfe_Types.h and CDD_Rfe.h are different"
#endif

/* Check if CDD_Rfe header file and CDD_Rfe_Cfg header file are of the same Software version */
#if ((CDD_RFE_CFG_SW_MAJOR_VERSION != CDD_RFE_SW_MAJOR_VERSION) || \
     (CDD_RFE_CFG_SW_MINOR_VERSION != CDD_RFE_SW_MINOR_VERSION) || \
     (CDD_RFE_CFG_SW_PATCH_VERSION != CDD_RFE_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of CDD_Rfe_Types.h and CDD_Rfe.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#define CDD_RFE_START_SEC_CODE
/*
* @violates @ref Cdd_Rfe_h_RFE_1  #Include directives should only be preceded by preprocessor directives or comments.
*/
#include "CDD_Rfe_MemMap.h"

/**
*   @addtogroup rsdk_rfe_api_interface
*   @{
*
* \note  The RFE API interface provides three kinds of functions, with different Front-End usage:
            - <b>Functions which apply globally to the RFE-Firmware software.</b>
            - <b>Functions which apply to a single, selected Radar Front-End only.</b> For a Cascaded solution, these functions need to be preceded by a call to apply to the Radar Front-End previously selected by the call to CDD_Rfe_SetFrontEnd.
              Normally, they need to be repeated for each Radar Front-End.
            - <b>Functions which can be applied to multiple Front-Ends  simultaneously.</b> These functions have a first argument CDD_RfeFrontEndIdMaskType < frontendSelect >,
              which defines a mask to select one or more Radar Front-Ends.

        - Functions which apply globally to the RFE-Firmware software.
            - CDD_Rfe_ConfigureInterrupt
            - CDD_Rfe_RadarCycleStart
            - CDD_Rfe_RadarCycleStop
            - CDD_Rfe_SwHwGetVersion
            - CDD_Rfe_GetVersionInfo
            - CDD_Rfe_GetError
            - CDD_Rfe_GetState
            - CDD_Rfe_GetTime
            - CDD_Rfe_GetRadarCycleCount
            - CDD_Rfe_GetNextRadarCycleStartTime
            - CDD_Rfe_TestContinuousWaveTransmissionStart
            - CDD_Rfe_TestContinuousWaveTransmissionStop
            - CDD_Rfe_TestGetInternalError
        - Functions which apply to a single, selected Radar Front-End only.
            - CDD_Rfe_Configure
            - CDD_Rfe_GetFuSaFaults
            - CDD_Rfe_GetBistZeroHourReferenceData
            - CDD_Rfe_MonitorRead
            - CDD_Rfe_UpdateBegin
            - CDD_Rfe_UpdateParam
            - CDD_Rfe_UpdateDynamicTable
            - CDD_Rfe_UpdatePush
        - Functions applicable to multiple Front-Ends simultaneously:
            - CDD_Rfe_GetRegisterDump
*
*/

/**
 *
 *  \brief This function synchronizes the Rfe_Driver with the RFE-Fw.
 *
 *  \details This is the first RFE Abstract 2.0 function to be called. The first call to this
 *  function initiates the control core <-> RFE-Fw synchronization protocol and always fails.
 *  This function shall be called until it does not sets \ref rfe_error_api_unresponsive_e
 *  error anymore, which indicates that the synchronization protocol was executed successfully.
 *
 *  This function can sets one of following errors:
 *  - \ref rfe_error_api_unresponsive_e
 *  - \ref rfe_error_sharedData_redundancyCheckFailed_e
 *
 *  \pre The RFE-Fw must be powered up and intialized.
 *
 *  \post RFE-Fw in \ref rfe_state_initialized_e state
 *
 *
 */
void CDD_Rfe_Init(void);


/**
 *  \brief This function fully configures the RFE-Fw.
 *
 *  \details This function copies the provided configuration and dynamic tables to the RFE-Fw and verifies them, after which the API function returns.
 *  Asynchronously, the RFE-Fw configures the Radar Front End (TEF82XX for now) and performs the configuration calibrations.
 *  This function returns after RFE-Fw processed the API call and configuration.
 *  This function must be called for each Front-End having as parameters the appropriate blob and dynamic table(s).
 *
 *   This function can sets one of following errors:
 *  - \ref rfe_error_api_unsynchronized_e
 *  - \ref rfe_error_api_operationNotAllowed_e
 *  - \ref rfe_error_api_busy_e
 *  - \ref rfe_error_api_invalidArgumentValue_e
 *  - \ref rfe_error_api_invalidConfigurationSize_e
 *  - \ref rfe_error_api_invalidConfigurationParameterValue_e
 *  - \ref rfe_error_api_invalidDynamicTableSize_e
 *  - \ref rfe_error_api_invalidDynamicTableValue_e
 *  - \ref rfe_error_api_invalidRadarCycleTimeSchedule_e
 *  - Any \ref rfe_error_api_configParamCrossCheck_dwellSettleTimeTooShort_e ... \ref rfe_error_api_configParamCrossCheck_unconfiguredDynamicTable_e.
 *  - Any \ref rfe_error_cmdInterface_invalidCmdId_e ... \ref rfe_error_cmdInterface_invalidConfigCmdSequencing_e.
 *  - \ref rfe_error_sharedData_redundancyCheckFailed_e
 *  - \ref rfe_error_rfeFuSaFault_e
 *
 *  \pre The RFE-Fw must be in \ref rfe_state_initialized_e state,
 *       or in \ref rfe_state_configured_e state in case of full reconfiguration.
 *
 *  \param [in]      configPtr - Pointer to Configuration Data Memory (see \ref rsdk_rfe_blob)
 *  \param [in]      dynamicTableAddress - Address of the dynamic tables in system memory.
 *                   The dynamic tables created by the RFE configuration generator need
 *                   to be loaded or copied to this address in system memory before calling
 *                   this API function. Set to 0 when dynamic table is not used.
 *
 *  \return Std_ReturnType - E_OK / E_NOT_OK
 *
 *  \post   RFE-Fw state becomes \ref rfe_state_busy_e and RFE-Fw performs configuration and configuration calibration asynchronously. 
*           RFE-Fw state becomes \ref rfe_state_configured_e only after all Front-End(s) are configurated.
 *
 */
Std_ReturnType CDD_Rfe_Configure(uint8* configPtr, const Cdd_RfeSysMemAddressType dynamicTableAddress);


/**
 *
 *  \brief This function starts the configured radar cycles.
 *
 *  \details The configured radar cycles are started at \b startTime or as soon as possible depending on the
 *  \b isScheduled parameter. The radar cycle start can be scheduled from 10 us up to 1000 ms in the future
 *  (on reception of the API call by the RFE-Fw).
 *  This function returns after RFE-Fw processed the API call.
 *
 *   This function can sets one of following errors:
 *  - \ref rfe_error_api_unsynchronized_e
 *  - \ref rfe_error_api_operationNotAllowed_e
 *  - \ref rfe_error_api_busy_e
 *  - \ref rfe_error_api_invalidArgumentValue_e
 *  - Any _cmdInterface_ error of \ref rfe_error_t.
 *  - \ref rfe_error_sharedData_redundancyCheckFailed_e
 *  - \ref rfe_error_rfeFuSaFault_e
 *
 *  \pre The RFE-Fw must be in \ref rfe_state_configured_e state.
 *
 *  \param [in]      radarCycleCount - Number of radar cycles to start.
 *                   A value of 0 indicates an infinite number of radar cycles,
 *                   i.e. until stopped by Cdd_Rfe_radarCycleStop().
 *  \param [in]      isScheduled - If \b true, radar cycle starts at \b startTime.
 *                   If false, radar cycle starts as soon as possible.
 *  \param [in]      startTime - The absolute start time in 25 [ns] resolution of the chirp
 *                   sequence according to the RFE-Fw time.
 *
 *  \return Std_ReturnType - E_OK / E_NOT_OK
 *
 *  \post When the API call is accepted and radar cycle is started, RFE-Fw state will become
 *  \ref rfe_state_busy_e during the the calibration, BIST and chirp sequences.
 *  During the radar cycle idle windows the state is \ref rfe_state_radarCycleIdle_e.
 *  RFE-Fw state returns to \ref rfe_state_configured_e, when all radar cycles are completed.
 *
 */
Std_ReturnType CDD_Rfe_RadarCycleStart(uint16 radarCycleCount, boolean isScheduled, uint32 startTime) ;


/**
 *
 *  \brief This function stops the active radar cycles.
 *
 *  \details The active radar cycle will not be finished, but it is stopped as soon as the command has been received.
 *  Pending parameters update will be cancelled. It can be called, for example, when the  application needs
 *  to do a full reconfiguration or needs to go to a lower power mode or for any external event
 *  where active radar cycle needs to be stopped.
 *  This function returns after RFE-Fw processed the API call.
 *
 *   This function can sets one of following errors:
 *  - \ref rfe_error_api_unsynchronized_e
 *  - \ref rfe_error_api_operationNotAllowed_e
 *  - \ref rfe_error_api_busy_e
 *  - Any _cmdInterface_ error of \ref rfe_error_t.
 *  - \ref rfe_error_sharedData_redundancyCheckFailed_e
 *  - \ref rfe_error_rfeFuSaFault_e
 *
 *  \pre The RFE-Fw state must be \ref rfe_state_radarCycleIdle_e.
 *
 *  \return uint16  - Index of the active radar cycle at which radar cycle was stopped.
 *
 *  \post Radar cycle is stopped and RFE-Fw state returns to \ref rfe_state_configured_e.
 *
 */
uint16 CDD_Rfe_RadarCycleStop(void);


/**
 *
 *  \brief This function returns the RFE-Fw state.
 *
 *  \details This function does not interact with RFE-Fw, it returns state information from a shared memory location.
 *
 *   This function can sets one of following errors:
 *  - \ref rfe_error_api_unsynchronized_e
 *  - \ref rfe_error_sharedData_redundancyCheckFailed_e
 *
 *  \return Cdd_RfeStateType - The RFE-Fw state
 *
 */
Cdd_RfeStateType CDD_Rfe_GetState(void) ;


/**
 *
 *  \brief This function returns the radar cycle and chirp sequence count.
 *
 *  \details It returns the number radar cycles and chirp sequences that have been completed since
 *  Cdd_Rfe_radarCycleStart(). It can be used to keep track of the radar cycle or chirp sequence execution.
 *  This function does not interact with RFE-Fw, it returns information from a shared memory location.
 *
 *   This function can sets one of following errors:
 *  - \ref rfe_error_api_unsynchronized_e
 *  - \ref rfe_error_sharedData_redundancyCheckFailed_e
 *
 *  \pre The RFE-Fw must be in \ref rfe_state_radarCycleIdle_e state.
 *
 *  \return Cdd_RfeRadarCycleCountType - Structure that contains the radar cycle and chirp sequence count.
 *
 */
Cdd_RfeRadarCycleCountType CDD_Rfe_GetRadarCycleCount(void);


/*================================================================================================*/
/**
 * \brief This function provides the RFE-Fw FuSa faults which are set in Front End FCCU.
 * \details This function has to be used when a FuSa fault occurs, which is indicated by the ERROR_N signal
 * and can also be observed by CDD_Rfe_GetState() returning \ref rfe_state_fuSaFault_e.
 * 
 * This function can return one of following errors:
 * - \ref rfe_error_api_unsynchronized_e
 * - \ref rfe_error_api_operationNotAllowed_e
 * - \ref rfe_error_api_busy_e
 * - \ref rfe_error_api_invalidArgumentValue_e
 * - Any _cmdInterface_ error of \ref rfe_error_t.
 * - \ref rfe_error_rfeFuSaFault_e
 *
 * \pre The RFE-Fw must be in one of the following states:
 * - \ref rfe_state_initialized_e
 * - \ref rfe_state_configured_e
 * - \ref rfe_state_radarCycleIdle_e
 * - \ref rfe_error_rfeFuSaFault_e
 *
 * \param [out]     fuSaR1R2FaultListPtr - Pointer to an array, where this function will store the list of
 *                  fusa faults. The size of this array must be \b RFE_FUSA_R1_R2_MASK_UNMASK_FAULT_BYTE_COUNT bytes.
 *                  The enumeration \b rfe_fuSaFault_t must be used as bit index to determine the fault from
 *                  the \b pFuSaR1R2FaultList e.g., if byte index 3 of \b pFuSaR1R2FaultList has the value
 *                  b0010000, it means bit position 5 of fuSaFaultMask3 is set, i.e rfe_fuSaFault_sr47_lo_level_max_rx1_e fault is set.
 *
 *  \return Std_ReturnType - E_OK / E_NOT_OK
 *
 * \post This function does not result in change of RFE-Fw state.
 * 
 */
Std_ReturnType CDD_Rfe_GetFuSaFaults(uint8  *fuSaR1R2FaultListPtr);


/*================================================================================================*/
/**
 * \brief This function provides the fault statistics for R1 faults. 
 * \details This function provides list of fault occurrence count 
 * for each R1 fault. Whenever a R1 fault is detected, the corresponding counter is 
 * incremented. Each counter can reach up to a maximum value of 0xFF and stays at this level
 * until reset. The counter is reset as part of RFE initialization upon:
 *  - Functional reset.
 *  - Destructive reset.
 *  - Power on reset.
 * 
 * The \b pFuSaR1FaultCountList is of fixed size \ref RFE_FUSA_R1_FAULT_COUNT_MAX and does
 * not decrease even when R1 fault is promoted to R2 (refer \ref rfeCfg_param_monitorAndSafety_thresholdValueToPromoteR1Faults_e ).
 * The \b pR1FaultPromotedToR2Since will indicate which R1 fault was promoted to R2.
 * 
 *  This function returns after RFE-Fw processed the API call.
 *
 * This function can return one of following errors:
 * - \ref rfe_error_api_unsynchronized_e
 * - \ref rfe_error_api_operationNotAllowed_e
 * - \ref rfe_error_api_busy_e
 * - \ref rfe_error_api_invalidArgumentValue_e
 * - Any _cmdInterface_ error of \ref rfe_error_t.
 * - \ref rfe_error_rfeFuSaFault_e
 *
 * \pre The RFE-Fw must be in one of the following states:
 * - \ref rfe_state_initialized_e
 * - \ref rfe_state_configured_e
 * - \ref rfe_state_radarCycleIdle_e
 * - \ref rfe_error_rfeFuSaFault_e
 *
 * \param [out]     r1FaultPromotedToR2Ptr - Indicates the R1 fault which is promoted to R2.                
 * \param [out]     radarCycleCountPtr - Pointer to structure which provides Radar cycle count and Chirp sequence
 *                  count. The count in \b pRadarCycleCount is updated whenever the fault occurrence count is 
 *                  updated. If there is no active radar cycle, the radar cycle count and chirp sequence count 
 *                  value will be 0x00 each.
 * \param [out]     fuSaR1FaultCountListPtr - Pointer to an array containing fault occurrence count for each R1
 *                  fault. The size of this array should be RFE_FUSA_R1_FAULT_COUNT_MAX bytes.
 *                  The rfe_fuSaFault_t up to index value rfe_fuSaFault_R1_sm11_bist_tx4_sw_e bytes, must be used
 *                  to index the list to determine the fault occurrence count for the corresponding fault 
 *                  e.g., the value in \b pFuSaCountList[rfe_fuSaFault_R1_sm11_bist_tx4_sw_e]
 *                  provides the fault occurrence count for rfe_fuSaFault_R1_sm11_bist_tx4_sw_e.
 *
 * \return Std_ReturnType - E_OK / E_NOT_OK
 *
 * \post This function does not result in change of RFE-Fw state.
 *
 * \remark
 * -# The functions CDD_Rfe_GetFuSaFaults(), CDD_Rfe_RadarCycleStart() and CDD_Rfe_RadarCycleStop() 
 *  do not affect the counter values. 
 * -# The \ref rfeCfg_param_monitorAndSafety_thresholdValueToPromoteR1Faults_e has no relation to
 *  the counter used in CDD_Rfe_GetFuSaFaultStatistics().
 */
Std_ReturnType CDD_Rfe_GetFuSaFaultStatistics(uint16 *r1FaultPromotedToR2Ptr,
                                              Cdd_RfeRadarCycleCountType *radarCycleCountPtr,
                                              uint8  *fuSaR1FaultCountListPtr);


/*================================================================================================*/
/**
 * \brief This function returns RX BIST measurement details to be used as
 *  zero hour reference data.
 *
 * \details The RFE-Fw performs the RX phase difference and RX gain difference
 * measurements upon this function call. The measured data is provided along with 
 * information on the frequency, power and RX test tone configuration ( refer \ref rfeCfg_param_monitorAndSafety_injectTestTone_e ) 
 * used for this measurement. This data must be stored by Application and be used as zero hour reference 
 * ( to be passed via RFE-Fw configuration BLOB, refer \ref rfeCfg_section_monitorAndSafety_e ).
 *
 * This function can return one of following errors:
 * - \ref rfe_error_api_unsynchronized_e
 * - \ref rfe_error_api_operationNotAllowed_e
 * - \ref rfe_error_api_busy_e
 * - Any _cmdInterface_ error of \ref rfe_error_t.
 * - \ref rfe_error_rfeFuSaFault_e
 *
 * \pre The RFE-Fw must be in \ref rfe_state_configured_e.
 *
 * \param [out]     rxReferenceDataPtr  - pointer to structure containing zero hour RX bist reference data.
 *
 *  \return Std_ReturnType - E_OK / E_NOT_OK
 *
 * \remark
 *  - The configuration that changed due to  execution of CDD_Rfe_GetBistZeroHourReferenceData() will be restored to
 *  configuration that existed before the function call.
 *  - The threshold values ( \ref rfeCfg_section_monitorAndSafety_e ) to be used along with zero hour data are determined after
 * characterization.
 *
 * \post This function does not result in change of RFE-Fw state.
 * 
 */
Std_ReturnType CDD_Rfe_GetBistZeroHourReferenceData(Cdd_RfeRxBistZeroHourRefDataType *rxReferenceDataPtr);


/**
 *
 *  \brief      This function returns the RFE-Fw time.
 *
 *  \details    It returns the absolute RFE-Fw time since RFE-Fw initialization in 25[ns] resolution.
 *  The counter wrap around time is equal to 2^32 * 25 ns, which is approximately 107 seconds.
 *  This function returns after RFE-Fw processed the API call.
 *
 *  This function can return one of following errors:
 *  - \ref rfe_error_api_unsynchronized_e
 *  - \ref rfe_error_api_operationNotAllowed_e
 *  - \ref rfe_error_api_busy_e
 *  - Any _cmdInterface_ error of \ref rfe_error_t.
 *  - \ref rfe_error_sharedData_redundancyCheckFailed_e
 *  - \ref rfe_error_rfeFuSaFault_e
 *
 *  \pre The RFE-Fw must be in one of the following states:
 *  - \ref rfe_state_initialized_e
 *  - \ref rfe_state_configured_e
 *  - \ref rfe_state_radarCycleIdle_e
 *
 *  \return uint32_t - Absolute RFE-Fw time since initialization in 25 [ns] resolution.
 *
 */
uint32 CDD_Rfe_GetTime(void);


/**
 *
 *  \brief      This function returns version and variant details of the RFE-Fw.
 *
 *  \details    This function returns after RFE-Fw processed the API call.
 *
 *   This function can sets one of following errors:
 *  - \ref rfe_error_api_unsynchronized_e
 *  - \ref rfe_error_api_operationNotAllowed_e
 *  - \ref rfe_error_api_busy_e
 *  - Any _cmdInterface_ error of \ref rfe_error_t.
 *  - \ref rfe_error_sharedData_redundancyCheckFailed_e
 *  - \ref rfe_error_rfeFuSaFault_e
 *
 *  \pre The RFE must be in one of the following states:
 *  - \ref rfe_state_initialized_e
 *  - \ref rfe_state_configured_e
 *  - \ref rfe_state_radarCycleIdle_e
 *
 *  \return Cdd_RfeVersionType - Structure containing RFE-Fw variant and version details.
 *
 */
Cdd_RfeVersionType CDD_Rfe_SwHwGetVersion(void);


/**
 *
 *  \brief This function will read-out one or more RFE monitors.
 *
 *  \details  Monitors to be read are selected by \p monitorSelect.
 *  
 *  Current implementation supports reading of temperature sensors. #RFE_MONITOR_SELECT_TX_POWER and 
 *  #RFE_MONITOR_SELECT_PDC_CLIPPING_COUNT  of \p monitorSelect are not implemented. API user will receive
 *  \ref rfe_error_api_operationNotAllowed_e, if these options are passed.
 *  
 *  #RFE_MONITOR_SELECT_ALL bits of \p monitorSelect, is to read values from all monitors supported by API.
 *  Since current implementation supports only temperature sensors, other sensor values of the passed structure
 *  should be discarded.
 *  
 *  This function returns after RFE-Fw processed the API call.
 *
 *   This function can sets one of following errors:
 *  - \ref rfe_error_api_unsynchronized_e
 *  - \ref rfe_error_api_operationNotAllowed_e
 *  - \ref rfe_error_api_busy_e
 *  - \ref rfe_error_api_invalidArgumentValue_e
 *  - Any _cmdInterface_ error of \ref rfe_error_t.
 *  - \ref rfe_error_sharedData_redundancyCheckFailed_e
 *  - \ref rfe_error_rfeFuSaFault_e
 *
 *  \pre The RFE-Fw must be in one of the following states:
 *  - \ref rfe_state_initialized_e
 *  - \ref rfe_state_configured_e
 *  - \ref rfe_state_radarCycleIdle_e ( \ref RFE_MONITOR_SELECT_TEMP_IMMEDIATELY bit of \b monitorSelect must be '0')
 *  - \ref rfe_state_testContinuousWaveTransmission_e
 *
 *  \param [in]      monitorSelect      - Selection of the RFE-Fw monitors to read-out
 *  \param [out]     *monitorValuesPtr  - The monitor values will be written to this pointer
 *
 *  \return Cdd_RfeRadarCycleCountType  - The radar cycle and chirp sequence count,
 *  indicating when the monitors were read.
 *
 */
Cdd_RfeRadarCycleCountType CDD_Rfe_MonitorRead( Cdd_RfeMonitorSelectType  monitorSelect,
                                                Cdd_RfeMonitorValuesType  *monitorValuesPtr);


/**
 *
 *  \brief This function returns the scheduled absolute start time of the next radar cycle
 *
 *  \details The returned time is according to the RFE-Fw time.
 *  This function returns after RFE-Fw processed the API call.
 *
 *   This function can sets one of following errors:
 *  - \ref rfe_error_api_unsynchronized_e
 *  - \ref rfe_error_api_operationNotAllowed_e
 *  - \ref rfe_error_api_busy_e
 *  - \ref rfe_error_api_invalidArgumentValue_e
 *  - Any _cmdInterface_ error of \ref rfe_error_t.
 *  - \ref rfe_error_sharedData_redundancyCheckFailed_e
 *  - \ref rfe_error_rfeFuSaFault_e
 *
 *  \pre The RFE-Fw must be in \ref rfe_state_radarCycleIdle_e state.
 *
 *  \param [out]     *radarCycleIndexPtr - Pointer to index of the next radar cycle
 *                   of which the start time is returned.
 *
 *  \return uint32   - Absolute start time of the next scheduled radar cycle in 25 [ns] resolution.
 *
 */
uint32 CDD_Rfe_GetNextRadarCycleStartTime(uint16 *radarCycleIndexPtr);


/**
 *
 *  \brief This function updates the start time of the next radar cycle.
 *
 *  \details Cdd_Rfe_radarCycleStart() starts one or multiple radar cycles immediately or
 *  at a schedule time, with a certain period ( \ref rfeCfg_param_radarCycle_radarCycleDuration_e), as per the configuration.
 *  This function updates the absolute start time of the next radar cycle according to the RFE time.
 *  That radar cycle will thereby be delayed or pulled in. Subsequent radar cycles will shift in
 *  time accordingly to maintain the configured \ref rfeCfg_param_radarCycle_radarCycleDuration_e. This functionality
 *  can be used to synchronize multiple radar sensors in time.
 *  The next radar cycle start time can be delayed up to 100 ms and should not conflict with
 *  the current radar cycle time schedule (in case of pull in).
 *  This function returns after RFE-Fw processed the API call.
 *
 *   This function can sets one of following errors:
 *  - \ref rfe_error_api_unsynchronized_e
 *  - \ref rfe_error_api_operationNotAllowed_e
 *  - \ref rfe_error_api_busy_e
 *  - \ref rfe_error_api_invalidArgumentValue_e
 *  - Any _cmdInterface_ error of \ref rfe_error_t.
 *  - \ref rfe_error_sharedData_redundancyCheckFailed_e
 *  - \ref rfe_error_rfeFuSaFault_e
 *
 *  \pre The RFE-Fw must be in \ref rfe_state_radarCycleIdle_e state.
 *
 *  \param [in]      startTime - Absolute start time of the next radar cycle in 25 [ns] resolution.
 *
 *  \return uint16   - Index of the next radar cycle of which the start time is set.
 *
 *  \post Next radar cycle starts at the given start time.
 *
 */
uint16 CDD_Rfe_SetNextRadarCycleStartTime(uint32 startTime);


/**
 *  \brief This function begins a RFE-Fw configuration update operation.
 *
 *  \details When the RFE-Fw Configuration (as set via \ref CDD_Rfe_Configure()) is required to
 *  be updated then this is the first function to be called. This function will clear the buffered RFE-Fw configuration.
 *  This function does not interact with RFE-Fw, it buffers data locally.
 *  This function does not return any error.
 *
 *  \post The functions \ref CDD_Rfe_UpdateParam() and/or \ref CDD_Rfe_UpdateDynamicTable() must be called after this function
 *  to buffer the configuration and then push the configuration into RFE-Fw via the configuration update via
 *  \ref CDD_Rfe_UpdatePush().
 *
 */
void CDD_Rfe_UpdateBegin(void);


/**
 *  \brief This functions buffers one of multiple configuration parameter set operations.
 *
 *  \details It buffers an update of the RFE-Fw configuration as was set via Cdd_Rfe_configure().
 *  This  parameter set operation will be jointly pushed with other buffered
 *  update operations when calling Cdd_Rfe_UpdatePush(). A maximum number of
 *  \ref RFE_UPDATE_COUNT_MAX updates operations are supported for each push.
 *  This function does not interact with RFE-Fw, it buffers data locally.
 *
 *   This function can sets one of following errors:
 *  - \ref rfe_error_api_maxUpdateCountExceeded_e
 *
 *  \pre Call Cdd_Rfe_updateBegin().
 *
 *  \param [in]      section - The configuration section to set
 *  \param [in]      param   - The configuration parameter to set
 *  \param [in]      value   - The value to set
 *
 *  \return Std_ReturnType - E_OK / E_NOT_OK
 *
 *  \post Push all buffered update operations to RFE-Fw by calling Cdd_Rfe_updatePush().
 *
 */
Std_ReturnType CDD_Rfe_UpdateParam(Cdd_RfeCfgSectionType section, Cdd_RfeParamUpdateType param, uint32 value);


/**
 *
 *  \brief This functions buffers a dynamic table update.
 *
 *  \details It buffers an update of the dynamic table in the RFE-Fw after the initial configuration.
 *  It indicates to the RFE-Fw that a full dynamic table or part of it (i.e. selected dynamic parameters),
 *  located at the dynamicTableAddress in system memory (as configured via Cdd_Rfe_configure()),
 *  has been modified and needs to be updated in the RFE-Fw. This update operation will be jointly pushed,
 *  with other buffered update operations, when calling Cdd_Rfe_updatePush().
 *  A maximum number of \ref RFE_UPDATE_COUNT_MAX updates operations are supported.
 *  This function does not interact with RFE-Fw, it buffers data locally.
 *
 *   This function can sets one of following errors:
 *  - \ref rfe_error_api_maxUpdateCountExceeded_e
 *
 *  \pre Call Cdd_Rfe_updateBegin().
 *
 *  \param [in]      dynamicTableIndex - The index of the dynamic table to update.
 *  \param [in]      paramsSelect - The selection of dynamic parameters to update.
 *                   Use #RFE_DYN_PARAMS_SELECT_ALL to update the full table.
 *
 *  \return Std_ReturnType - E_OK / E_NOT_OK
 *
 *  \post Push all buffered update operations to RFE-Fw by calling Cdd_Rfe_updatePush().
 *
*/
Std_ReturnType CDD_Rfe_UpdateDynamicTable(uint8 dynamicTableIndex, Cdd_RfeDynParamsSelectType paramsSelect);


/**
 *
 *  \brief This function pushes all the buffered update operations jointly to RFE-Fw.
 *
 *  \pre In a \b Cascaded configuration, before calling this function set (using \ref CDD_Rfe_SetFrontEnd or be sure it is the correct one) the Front-End to receive the update.
 *  Only one Front-End will receive the update at a time. If necessary to proceed to the same update on many Front-Ends, after calling CDD_Rfe_UpdatePush,
 *  set the new Front-End to receive the same update using \ref CDD_Rfe_SetFrontEnd and call again CDD_Rfe_UpdatePush.
 *  \details Update-operations can be buffered by CDD_Rfe_UpdateParam() or
 *  \ref CDD_Rfe_UpdateDynamicTable(). It updates the RFE-Fw configuration as was set via
 *  \ref CDD_Rfe_Configure(). The RFE-Fw will first check that the parameter values are within
 *  the supported range. If so, the parameters will be jointly applied for the
 *  next radar cycle. The next radar cycle index will be returned by this API function.
 *  Updates are not allowed when the last radar cycle is active. When there is no radar
 *  cycle active, the updates will be applied immediately within the API function.
 *  An error is returned if the parameters are not within the accepted range.
 *  This function returns after RFE-Fw processed the API call.
 *
 *   This function can sets one of following errors:
 *  - \ref rfe_error_api_unsynchronized_e
 *  - \ref rfe_error_api_operationNotAllowed_e
 *  - \ref rfe_error_api_busy_e
 *  - \ref rfe_error_api_noUpdatesBuffered_e
 *  - \ref rfe_error_api_maxUpdateCountExceeded_e
 *  - \ref rfe_error_api_updateAlreadyPending_e
 *  - \ref rfe_error_api_invalidParameterForUpdate_e
 *  - \ref rfe_error_api_dynamicTablesNotConfigured_e
 *  - \ref rfe_error_api_cfgSectionMismatch_e
 *  - Any _cmdInterface_ error of \ref rfe_error_t.
 *  - \ref rfe_error_sharedData_redundancyCheckFailed_e
 *  - \ref rfe_error_rfeFuSaFault_e
 *
 *  \pre RFE-Fw must be in \ref rfe_state_configured_e or \ref rfe_state_radarCycleIdle_e state.
 *
 *  \return uint16   - The index of the next radar cycle at which the updates will be applied.
 *                     If radar cycle is not active, 0 will be returned.
 *
 */
uint16 CDD_Rfe_UpdatePush(void);


/**
 *
 *  \brief This function start continuous wave transmission.
 *
 *  \details It uses the RFE-Fw profile as configured via Cdd_Rfe_configure() as specified by \p profileIndex.
 *  The frequency is kept at the configured center frequency.
 *  This function returns after RFE-Fw processed the API call.
 *
 *   This function can sets one of following errors:
 *  - \ref rfe_error_api_unsynchronized_e
 *  - \ref rfe_error_api_operationNotAllowed_e
 *  - \ref rfe_error_api_busy_e
 *  - \ref rfe_error_api_invalidArgumentValue_e
 *  - Any _cmdInterface_ error of \ref rfe_error_t.
 *  - \ref rfe_error_sharedData_redundancyCheckFailed_e
 *  - \ref rfe_error_rfeFuSaFault_e
 *
 *  \pre RFE-Fw must be in \ref rfe_state_configured_e state.
 *
 *  \param [in]      profileIndex - Index of the chirp profile to be used for continuous wave transmission.
 *
 *  \return Std_ReturnType - E_OK / E_NOT_OK
 *
 *  \post RFE-Fw goes to  \ref rfe_state_testContinuousWaveTransmission_e state.
 *
 */
Std_ReturnType CDD_Rfe_TestContinuousWaveTransmissionStart(Cdd_RfeChirpProfileIndexType profileIndex);


/**
 *
 *  \brief This function stops continuous wave transmission.
 *
 *  \details Continuous wave transmission can be started via CDD_Rfe_TestContinuousWaveTransmissionStart().
 *  This function returns after RFE-Fw processed the API call.
 *
 *   This function can sets one of following errors:
 *  - \ref rfe_error_api_unsynchronized_e
 *  - \ref rfe_error_api_operationNotAllowed_e
 *  - \ref rfe_error_api_busy_e
 *  - Any _cmdInterface_ error of \ref rfe_error_t.
 *  - \ref rfe_error_sharedData_redundancyCheckFailed_e
 *  - \ref rfe_error_rfeFuSaFault_e
 *
 *  \pre RFE-Fw must be in \ref rfe_state_testContinuousWaveTransmission_e state.
 *
 *  \return Std_ReturnType - E_OK / E_NOT_OK
 *
 *  \post RFE-Fw goes to  \ref rfe_state_configured_e state.
 *
 */
Std_ReturnType CDD_Rfe_TestContinuousWaveTransmissionStop(void);


/**
 *
 *  \brief This function sets a test parameter.
 *
 *  \details This function returns after RFE-Fw processed the API call.
 *
 *   This function can sets one of following errors:
 *  - \ref rfe_error_api_unsynchronized_e
 *  - \ref rfe_error_api_operationNotAllowed_e
 *  - \ref rfe_error_api_busy_e
 *  - \ref rfe_error_api_invalidArgumentValue_e
 *  - Any _cmdInterface_ error of \ref rfe_error_t.
 *  - \ref rfe_error_sharedData_redundancyCheckFailed_e
 *  - \ref rfe_error_rfeFuSaFault_e
 *
 *  \pre The RFE-Fw must be in one of the following states:
 *  - \ref rfe_state_initialized_e
 *  - \ref rfe_state_configured_e
 *
 *  \param [in]      testParam - The test parameter to set
 *  \param [in]      value - The value to set
 *
 *  \return Std_ReturnType - E_OK / E_NOT_OK
 *
 */
Std_ReturnType CDD_Rfe_TestSetParam(Cdd_RfeTestParamType testParam, uint32 value);


/**
 *
 *  \brief This function provides the error occurred.
 *
 *  \details This is the first RFE-Fw function to be called. The first call to this function initiates the
 *  control core <-> RFE-Fw synchronization protocol and always fails. This function shall be called until it
 *  does not return \ref rfe_error_api_unresponsive_e error anymore,
 *  which indicates that the synchronization protocol was executed successfully.
 *
 *  CDD_Rfe_GetError() can then return one of following errors:
 * - #rfe_error_api_unsynchronized_e
 * - #rfe_error_api_operationNotAllowed_e
 * - #rfe_error_api_busy_e
 * - #rfe_error_api_invalidArgumentValue_e
 * - Any _cmdInterface_ error of #rfe_error_t.
 * - #rfe_error_sharedData_redundancyCheckFailed_e
 * - #rfe_error_rfeFuSaFault_e
 *
 *  \pre The RFE-Fw must be powered up and intialized.
 *
 *  \return Cdd_RfeErrorType
 *
 */
Cdd_RfeErrorType CDD_Rfe_GetError(void);

/**
 *
 *  \brief This function fetches the internal software error code from M7_1 and stores it.
 *
 *  \details This function fetches the internal software error code from M7_1 and stores it.
 *  This function returns whether RFE has accepted or rejected the API call.
 *  API user should invoke CDD_Rfe_GetError() to get the internal software error stored by this API for further usage.
 *  
 *  \pre The RFE must be in one of the following states:
 *  - #rfe_state_initialized_e
 *  - #rfe_state_configured_e
 *  - #rfe_state_radarCycleIdle_e
 *  - #rfe_state_fuSaFault_e
 *
 *  \return Std_ReturnType - E_OK / E_NOT_OK
 *
 */
Std_ReturnType CDD_Rfe_TestGetInternalError(void);


/*================================================================================================*/
/**
*
*   \brief      Function to get the specified value from the blob.
*
*   \details    The function identifies the value to be returned, according to the provided parameters.
*               An uint32 value will be returned, for any dimension of the required value.
*
*   @param[in]  configPtr - pointer to the blob array
*   @param[in]  section   - blob section
*   @param[in]  param     - section parameter
*   @param[in]  valuePtr  - pointer to the receiving address
*
*/
Std_ReturnType CDD_Rfe_GetBlobValue(uint8* configPtr, Cdd_RfeCfgSectionType section, Cdd_RfeCfgParamType param, uint32 *valuePtr);


/*================================================================================================*/
/**
*
*   \brief      Function to get the specified value from the blob.
*
*   \details    The function identifies the value to be set, according to the provided parameters.
*               The provided value is truncated to the real blob value dimension.
*
*   @param[in]  configPtr - pointer to the blob array
*   @param[in]  section   - blob section
*   @param[in]  param     - section parameter
*   @param[in]  value     - the value to be set
*
*/
Std_ReturnType CDD_Rfe_SetBlobValue(uint8* configPtr, Cdd_RfeCfgSectionType section, Cdd_RfeCfgParamType param, uint32 value);


/**
*
*   \brief Service for passing the version information through a pointer *versionInfoPtr
*
*   \details  Service for passing the Information through a pointer "*versionInfoPtr".
*
*   @param[in]   *versionInfoPtr --> pointer to an address where all the version information needs to be copied.
*
*/
#if(CDD_RFE_VERSION_INFO_API == STD_ON)
void CDD_Rfe_GetVersionInfo(Std_VersionInfoType *versionInfoPtr);
#endif


/**
*
*   \brief      Function to change the associated Front-End "subject" in a cascaded setup.
*
*   \details    The function must be used only in a cascaded setup.
*               If used in a non-cascaded mode the result will be : SUCCESS for LEADER request and error for FOLLOWER request.
*               The reported error will be detailed using Det mechanism.
*               The possible errors are :
*               - unresponsive
*               - not synchronized
*               - busy
*               - invalid argument - only this is a specific error for this operation request, returned from RFE-Fw
*
*   @param[in]  frontEndPos - the Front-End to be used as conversation subject between the two cores
*
*/
Std_ReturnType CDD_Rfe_SetFrontEnd(CDD_RfeFrontEndHierarchyType frontEndPos);


/**
*
*   \brief      Function to get the current associated Front-End "subject" in the RFE-Fw, in a cascaded setup.
*
*   \details    The function must be used only in a cascaded setup.
*               If used in a non-cascaded setup, the result will be LEADER for each request.
*               The possible errors are :
*               - unresponsive
*               - not synchronized
*               - busy
*
*   @param[in]  *frontEndPosPtr - pointer to a CDD_RfeFrontEndHierarchyType variable to receive the used Front-End
*
*/
Std_ReturnType CDD_Rfe_GetFrontEnd(CDD_RfeFrontEndHierarchyType *frontEndPosPtr);

/**
*
*   \brief      Debug function to get specific Front-End register values.
*
*   \details    The primary usage of this function is to return the current values of the Front-End registers.
*               The read-out is performed on demand (when called), when the radar cycle is stopped.
*               The order of processing is :
*                   - loop over Front-Ends, in following order : Leader, Follower_0 [, Follower_1,...]
*                   - loop over modules (order described here: \ref rfe_bcdModuleId_t)
*
*               Front-end modules supply voltages can be also acquired with this function by adding
*               \ref rfe_registerDump_ATB_VOLTAGE_READOUT to the moduleSelect mask.
*
*               The order of returned module supply voltages (measured with the ATB) is identical to the order
*               of modules and voltages described in the \ref rfe_tef82xxVoltages_t structure.
*               Possible errors that can be obtained calling the CDD_Rfe_GetError function and are :
*               - unresponsive
*               - not synchronized
*               - busy
*
*   @param[in]      frontEndSelect  - front-end selection mask
*   @param[in]      moduleSelect    - module selection mask
*   @param[in]      dumpArrayPtr    - pointer to the returned values array of rfe_registerDumpValues_t type
*   @param[in,out]  dumpArrayLenPtr - in : pointer to the returned values array maximum length
*                                   - out : pointer to the exact number of returned values
*
*/
Std_ReturnType CDD_Rfe_GetRegisterDump(CDD_RfeFrontEndIdMaskType frontEndSelect, rfe_moduleDumpSelect_t moduleSelect, rfe_registerDumpValues_t *dumpArrayPtr,
                                        uint32_t *dumpArrayLenPtr);

 /**
  *
  * \brief This function configure the RFE firmware interrupt.
  *
  * \details rfe_configureInterrupt() configures which conditions will raise
  *          an IRQ to \p coreId, these conditions are:
  *            - RFE state changes
  *            - Radar Cycle count changes
  *            - Chirp Sequence count changes
  *            - Specific RFE API responses from the rfe firmware
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
  * \note \p apiWaitForInterrupt IS NOT an interrupt handler, the application code
  *       is responsible for setting up and handle incoming RFE interrupts.
  *
  * \param [in]      coreId - Which core should the RFE interrupt be sent.
  * \param [in]      events - Bitmask of events that will trigger an interrupt.
  * \param [in]      rfeAPIs - Bitmask of RFE-APIs responses that will trigger an interrupt.
  * \param [in]      apiWaitForInterrupt - API wait for interrupt function pointer.
  *                                        This is a user registered call back function where wait for interrupt or
  *                                        functionality to give control to Operating System can be implemented as per customer need.
  *
  *  \return Std_ReturnType
  */
Std_ReturnType CDD_Rfe_ConfigureInterrupt(
                                Cdd_RfeCoreIdDataType coreId,
                                Cdd_RfeEventsIRQDataType events,
                                Cdd_RfeApiIRQDataType rfeAPIs,
                                Cdd_RfeApiWaitForInterruptDataType apiWaitForInterrupt);


/** @} */

#define CDD_RFE_STOP_SEC_CODE

/*
* @violates @ref Cdd_Rfe_h_RFE_1  #Include directives should only be preceded by preprocessor directives or comments.
*/
#include "CDD_Rfe_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif    /* CDD_RFE_H */
