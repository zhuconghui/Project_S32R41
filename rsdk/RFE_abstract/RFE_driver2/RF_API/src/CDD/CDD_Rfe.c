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

/**
*   @file
*   @implements CDD_Rfe.c_Artifact
*
*   @addtogroup CDD_RFE
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*
* @page misra_violations MISRA-C:2012 violations
*
* @section Cdd_Rfe_c_REF_1
* Violates MISRA 2012 Advisory Rule 8.7
* #Functions and objects should not be defined with external linkage if they are referenced in only one translation unit
* The functions are API functions, to be called from the main application.
*
* @section Cdd_Rfe_c_REF_2
* Violates MISRA 2012 Advisory Rule 20.1
* #Include directives should only be preceded by preprocessor directives or comments.
* <MA>_MemMap.h is included after each section define in order to set the current memory section as defined by AUTOSAR.
*
* @section Cdd_Rfe_c_REF_3
* Violates MISRA 2012 Required Rule 5.1
* #External identifiers shall be distinct
* The function naming convention is followed here.
*
* @section Cdd_Rfe_c_REF_4
* Violates MISRA 2012 Advisory Rule 10.5
* #The value of an expression should not be cast to an inappropriate essential type.
* Necessary cast as the 32 bits value must be interpreted as an enumerated error.
*
*/


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_Rfe.h"
#include "SchM_CDD_Rfe.h"
#include "rsdk_version.h"
#include "rsdk_status.h"
#if(CDD_RFE_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
    #if defined(RSDK_AUTOSAR) && (CDD_RFE_DEV_ERROR_DETECT == STD_ON)
        #include "rsdk_status_helper.h"
    #endif
#endif

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_RFE_C_VENDOR_ID                     43
#define CDD_RFE_C_AR_RELEASE_MAJOR_VERSION      RSDK_AR_MAJOR
#define CDD_RFE_C_AR_RELEASE_MINOR_VERSION      RSDK_AR_MINOR
#define CDD_RFE_C_AR_RELEASE_REVISION_VERSION   RSDK_AR_REV
#define CDD_RFE_C_SW_MAJOR_VERSION              RSDK_SW_MAJOR
#define CDD_RFE_C_SW_MINOR_VERSION              RSDK_SW_MINOR
#define CDD_RFE_C_SW_PATCH_VERSION              RSDK_SW_PATCH


/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#if(CDD_RFE_VERSION_INFO_API == STD_ON)

/* Check if CDD_Rfe source file and CDD_Rfe header file are of the same vendor */
#if (CDD_RFE_C_VENDOR_ID != CDD_RFE_AR_VENDOR_ID)
    #error "CDD_Rfe.c and CDD_Rfe.h have different vendor ids"
#endif

/* Check if CDD_Rfe.c source file and CDD_Rfe.h header file are of the same Autosar version */
#if ((CDD_RFE_C_AR_RELEASE_MAJOR_VERSION    != CDD_RFE_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_RFE_C_AR_RELEASE_MINOR_VERSION    != CDD_RFE_AR_RELEASE_MINOR_VERSION) || \
     (CDD_RFE_C_AR_RELEASE_REVISION_VERSION != CDD_RFE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Rfe.c and CDD_Rfe.h are different"
#endif

/* Check if CDD_Rfe.c source file and CDD_Rfe.h header file are of the same Software version */
#if ((CDD_RFE_C_SW_MAJOR_VERSION != CDD_RFE_SW_MAJOR_VERSION) || \
     (CDD_RFE_C_SW_MINOR_VERSION != CDD_RFE_SW_MINOR_VERSION) || \
     (CDD_RFE_C_SW_PATCH_VERSION != CDD_RFE_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of CDD_Rfe.c and CDD_Rfe.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if(CDD_RFE_DEV_ERROR_DETECT == STD_ON)

    /* Check if CDD_Rfe.c source file and Det.h header file are of the same Autosar version */
    #if ((CDD_RFE_C_AR_RELEASE_MAJOR_VERSION    != DET_AR_RELEASE_MAJOR_VERSION) || \
         (CDD_RFE_C_AR_RELEASE_MINOR_VERSION    != DET_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of CDD_Rfe.c and Det.h are different"
    #endif
#endif
#endif
#endif  /* #if(CDD_RFE_VERSION_INFO_API == STD_ON)      */


/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
/* error report management      */
#if !defined(CDD_RFE_DET_REPORT)

        #if (CDD_RFE_DEV_ERROR_DETECT == STD_ON)
            #define CDD_RFE_DET_REPORT(a,b,c)    (void)RSDK_REPORT_ERROR(a, (uint16)CDD_RFE_AR_MODULE_ID, (uint8)CDD_RFE_AR_INSTANCE_ID, (b), (c));
        #else
            #define CDD_RFE_DET_REPORT(a,b,c)
        #endif



#endif

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/
/* Variable to store the current error.                                             */
static Cdd_RfeErrorType  Cdd_RfeError = rfe_error_none_e;

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

#if (CDD_RFE_CFG_HALT_ON_ERROR == STD_ON)
volatile bool gsCddRfeLoopExit = FALSE;
#endif

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                              GLOBAL FUNCTIONS
==================================================================================================*/
#define CDD_RFE_START_SEC_CODE
#include "CDD_Rfe_MemMap.h"


/*================================================================================================*/
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
 *  \return NIL
 *
 *  \post RFE-Fw will be in #rfe_state_initialized_e state after the correct initialization.
 *
 *  \ingroup NIL
 *
 */
/*
* @violates @ref Cdd_Rfe_c_REF_1 #Functions and objects should not be defined with external linkage
*                                   if they are referenced in only one translation unit
*/
void CDD_Rfe_Init(void)
{
    /* start exclusive area for this function       */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_00();
#endif

    /* Set the reported error to none                                                   */
    Cdd_RfeError = rfe_error_none_e;
    /* Call the low-level function to synchronize the rfeDriver with the RFE-Fw.        */
    rfe_sync(&Cdd_RfeError);
    /* as this function usually returns error, the error will not be reported to Det
     * and the execution will not be stopped                                            */

    /* exit exclusive area for this function        */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_00();
#endif

}
/* CDD_Rfe_Init *************************/


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
 *  \param [in]      pConfig - Pointer to Configuration Data Memory (see \ref blob)
 *  \param [in]      dynamicTableAddress - Address of the dynamic tables in system memory.
 *                   The dynamic tables created by the rfe configuration generator need
 *                   to be loaded or copied to this address in system memory before calling
 *                   this API function. Set to NULL when dynamic table is not used.
 *
 *  \return Std_ReturnType - E_OK / E_NOT_OK
 *
 *  \post RFE-Fw state becomes #rfe_state_busy_e and RFE-Fw performs configuration and calibrations asynchronously.
 *  When done, RFE-Fw state becomes #rfe_state_configured_e.
 *
 *  \ingroup NIL
 */

/*
* @violates @ref Cdd_Rfe_c_REF_1 #Functions and objects should not be defined with external linkage
*                                   if they are referenced in only one translation unit
*/
Std_ReturnType CDD_Rfe_Configure(uint8* configPtr, const Cdd_RfeSysMemAddressType dynamicTableAddress )
{
    Std_ReturnType ret = E_OK;      /* The error state to be reported, set to E_OK as default result            */

    /* start exclusive area for this function       */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_01();
#endif

    /* Set the reported error to none                                                   */
    Cdd_RfeError = rfe_error_none_e;
    /* Call the low-level function to configure the RFE-Fw. */
    rfe_configure(configPtr, dynamicTableAddress, &Cdd_RfeError);

    /* Check for error */
    if(Cdd_RfeError != rfe_error_none_e)
    {
       /* Report Error. */
       ret = E_NOT_OK;
       CDD_RFE_DET_REPORT(RSDK_RFE_NOT_INITIALIZED, CDD_RFE_CONFIGURE, CDD_RFE_E_SETUP_FAILED);
       CDD_RFE_HALT_ON_ERROR;
    }

    /* exit exclusive area for this function        */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_01();
#endif

    return ret;
}
/* CDD_Rfe_Configure *************************/


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
 *
 *  \return Std_ReturnType - E_OK / E_NOT_OK
 *
 *  \post When the API call is accepted and radar cycle is started, RFE-Fw state will become #rfe_state_busy_e
 *  during the the calibration, BIST and chirp sequences.
 *  During the radar cycle idle windows the state is #rfe_state_radarCycleIdle_e.
 *  RFE-Fw state returns to #rfe_state_configured_e, when all radar cycles are completed.
 *
 *  \ingroup NIL
 */

/*
* @violates @ref Cdd_Rfe_c_REF_1 #Functions and objects should not be defined with external linkage
*                                   if they are referenced in only one translation unit
*/
Std_ReturnType CDD_Rfe_RadarCycleStart( uint16 radarCycleCount, boolean isScheduled, uint32 startTime)
{
    Std_ReturnType ret = E_OK;      /* The error state to be reported, set to E_OK as default result            */

    /* start exclusive area for this function       */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_02();
#endif

    /* Set the reported error to none                                                   */
    Cdd_RfeError = rfe_error_none_e;
    /* Call the low-level function to start the configured radar cycles. */
    rfe_radarCycleStart( radarCycleCount, isScheduled, startTime, &Cdd_RfeError );

    /* Check for error */
    if(Cdd_RfeError != rfe_error_none_e)
    {
       /* Report Error. */
       ret = E_NOT_OK;
       CDD_RFE_DET_REPORT(RSDK_RFE_OPERATION_NOT_SUPPORTED_BY_DEVICE, CDD_RFE_START_EXECUTION,
                               CDD_RFE_E_RESPONSE_ERROR);
       CDD_RFE_HALT_ON_ERROR;
    }

    /* exit exclusive area for this function        */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_02();
#endif

    /* Return the count. */
    return ret;
}
/* CDD_Rfe_RadarCycleStart *************************/


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
 *  \return uint16  - Index of the active radar cycle at which radar cycle was stopped.
 *
 *  \post Radar cycle is stopped and RFE-Fw state returns to #rfe_state_configured_e.
 *
 *  \ingroup NIL
 */

/*
* @violates @ref Cdd_Rfe_c_REF_1 #Functions and objects should not be defined with external linkage
*                                   if they are referenced in only one translation unit
*/
uint16 CDD_Rfe_RadarCycleStop(void)
{
     /* State Variable. */
    uint16 radarCycleCount;

    /* start exclusive area for this function       */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_03();
#endif

    /* Set the reported error to none                                                   */
    Cdd_RfeError = rfe_error_none_e;
    /* Call the API to stop the active radar cycles and store the radar cycle count at which radar cycles stopped */
    radarCycleCount = rfe_radarCycleStop(&Cdd_RfeError);

    /* Check for error */
    if(Cdd_RfeError != rfe_error_none_e)
    {
        /* report the error */
        CDD_RFE_DET_REPORT(RSDK_RFE_OPERATION_NOT_SUPPORTED_BY_DEVICE, CDD_RFE_STOP_EXECUTION,
                                        CDD_RFE_E_RESPONSE_ERROR);
        CDD_RFE_HALT_ON_ERROR;
        /* clear the radar cycle count if error got*/
        radarCycleCount  = 0;
    }

    /* exit exclusive area for this function        */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_03();
#endif

    /* Return the count. */
    return radarCycleCount;
}
/* CDD_Rfe_RadarCycleStop *************************/


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
 *  \pre NIL
 *
 *  \return Cdd_RfeStateType - The RFE-Fw state
 *
 *  \post NIL
 *
 *  \ingroup NIL
 */

/*
* @violates @ref Cdd_Rfe_c_REF_1 #Functions and objects should not be defined with external linkage
*                                   if they are referenced in only one translation unit
*/
Cdd_RfeStateType CDD_Rfe_GetState(void)
{
    Cdd_RfeStateType state;     /* State Variable.      */

    /* start exclusive area for this function       */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_04();
#endif

    /* Set the reported error to none                                                   */
    Cdd_RfeError = rfe_error_none_e;
    state = rfe_getState(&Cdd_RfeError);        /* Get the RFE-Fw state        */

    /* Check for error */
    if(Cdd_RfeError != rfe_error_none_e)
    {
        CDD_RFE_DET_REPORT(RSDK_RFE_DRIVER_BUSY, CDD_RFE_GET_DATA, CDD_RFE_E_REDUNDANCY_CHECK_FAILED);
        CDD_RFE_HALT_ON_ERROR;
    }

    /* exit exclusive area for this function        */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_04();
#endif

    return state;               /* Return the State.    */
}
/* CDD_Rfe_GetState *************************/


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
 *  \return Cdd_RfeRadarCycleCountType - Structure that contains the radar cycle and chirp sequence count.
 *
 *  \post NIL
 *
 *  \ingroup NIL
 */

/*
* @violates @ref Cdd_Rfe_c_REF_1 #Functions and objects should not be defined with external linkage
*                                   if they are referenced in only one translation unit
*/
Cdd_RfeRadarCycleCountType CDD_Rfe_GetRadarCycleCount (void)
{
    Cdd_RfeRadarCycleCountType radarCycleCount;

    /* start exclusive area for this function     */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_05();
#endif

    /* Set the reported error to none                                                   */
    Cdd_RfeError = rfe_error_none_e;
    /* Call API to get the radar cycle and chirp sequence count since the radar cycles has been started . */
    radarCycleCount = rfe_getRadarCycleCount(&Cdd_RfeError);

    /* Check for error */
    if(Cdd_RfeError != rfe_error_none_e)
    {
        CDD_RFE_DET_REPORT(RSDK_RFE_DRIVER_BUSY, CDD_RFE_GET_DATA, CDD_RFE_E_REDUNDANCY_CHECK_FAILED);
        CDD_RFE_HALT_ON_ERROR;
    }


    /* exit exclusive area for this function     */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_05();
#endif

    /* Return the Radar Cycle Count.  */
    return radarCycleCount;
}
/* CDD_Rfe_GetradarCycleCount *************************/


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
 * \ingroup NIL
 */

/*
* @violates @ref Cdd_Rfe_c_REF_1 #Functions and objects should not be defined with external linkage
*                                   if they are referenced in only one translation unit
*/
Std_ReturnType CDD_Rfe_GetFuSaFaults(uint8  *fuSaR1R2FaultListPtr)
{
    /* The standard return type has set to zero*/
    Std_ReturnType ret = E_OK;

    /* start exclusive area for this function     */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_06();
#endif

    /* Set the reported error to none                                                   */
    Cdd_RfeError = rfe_error_none_e;
    /* Call the API to get the list of active FuSa Faults in RFE-Fw  */
    rfe_getFuSaFaults(fuSaR1R2FaultListPtr, &Cdd_RfeError);

    /* Check for error */
    if(Cdd_RfeError != rfe_error_none_e)
    {
        ret = E_NOT_OK;             /* Report Error.        */
        CDD_RFE_DET_REPORT(RSDK_RFE_DRIVER_BUSY, CDD_RFE_GET_DATA, CDD_RFE_E_RESPONSE_ERROR);
        CDD_RFE_HALT_ON_ERROR;
    }

    /* exit exclusive area for this function     */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_06();
#endif

    /* Return the fusa Error count. */
    return ret;
}
/* CDD_Rfe_GetFuSaFaults *************************/


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
 * not decrease even when R1 fault is promoted to R2 ( refer \ref thresholdValueToPromoteR1Faults ).
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
 *                  fault. The size of this array should be #RFE_FUSA_R1_FAULT_COUNT_MAX bytes.
 *                  The #rfe_fuSaFault_t up to index value #rfe_fuSaFault_R1_sm11_bist_tx4_sw_e bytes, must be used
 *                  to index the list to determine the fault occurrence count for the corresponding fault 
 *                  e.g., the value in \b pFuSaCountList[#rfe_fuSaFault_R1_sm11_bist_tx4_sw_e]
 *                  provides the fault occurrence count for #rfe_fuSaFault_R1_sm11_bist_tx4_sw_e.
 *
 *  \return Std_ReturnType - E_OK / E_NOT_OK
 *
 * \post This function does not result in change of RFE-Fw state.
 *
 * \remark
 * -# The functions CDD_Rfe_GetFuSaFaults(), CDD_Rfe_RadarCycleStart() and CDD_Rfe_RadarCycleStop() 
 *  do not affect the counter values. 
 * -# The \ref thresholdValueToPromoteR1Faults has no relation to the counter used in CDD_Rfe_GetFuSaFaultStatistics().
 *
 * \ingroup NIL
 */

/*
* @violates @ref Cdd_Rfe_c_REF_1 #Functions and objects should not be defined with external linkage
*                                   if they are referenced in only one translation unit
*/
Std_ReturnType CDD_Rfe_GetFuSaFaultStatistics( uint16 *r1FaultPromotedToR2Ptr,
                                               Cdd_RfeRadarCycleCountType *radarCycleCountPtr,
                                               uint8  *fuSaR1FaultCountListPtr )
{
    /* The standard return type has set to OK*/
    Std_ReturnType ret = E_OK;

    /* start exclusive area for this function     */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_07();
#endif

    /* Set the reported error to none                                                   */
    Cdd_RfeError = rfe_error_none_e;
    /* Call the API to get the list of active FuSa errors in RFE-Fw */
    rfe_getFuSaFaultStatistics(r1FaultPromotedToR2Ptr, radarCycleCountPtr,
                                    fuSaR1FaultCountListPtr, &Cdd_RfeError);

    /* Check for error */
    if(Cdd_RfeError != rfe_error_none_e)
    {
       ret = E_NOT_OK;
       CDD_RFE_DET_REPORT(RSDK_RFE_DRIVER_BUSY, CDD_RFE_GET_DATA, CDD_RFE_E_RESPONSE_ERROR);
       CDD_RFE_HALT_ON_ERROR;
    }

    /* exit exclusive area for this function     */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_07();
#endif

    /* Return the status. */
    return ret;
}
/* CDD_Rfe_GetFuSaFaultStatistics *************************/


/*================================================================================================*/
/**
 * \brief This function returns RX BIST measurement details to be used as zero hour reference data.
 *
 * \details The RFE-Fw performs the RX phase difference and RX gain difference
 * measurements upon this function call. The measured data is provided along with 
 * information on the frequency, power and RX test tone configuration ( refer \ref injectTestToneBeforeLna ) 
 * used for this measurement. This data must be stored by Application and be used as zero hour reference 
 * ( to be passed via RFE-Fw configuration BLOB, refer \ref monitorAndSafety ).
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
 * \param [out]     pRxReferenceData  - pointer to structure containing zero hour RX bist reference data.
 *
 *  \return Std_ReturnType - E_OK / E_NOT_OK
 *
 * \remark
 *  -# The configuration that changed due to  execution of CDD_Rfe_GetBistZeroHourReferenceData() will be restored to 
 *  configuration that existed before the function call.
 *  -# The threshold values ( \ref monitorAndSafety ) to be used along with zero hour data are determined after 
 * characterization.
 * \return NIL
 * \post This function does not result in change of RFE-Fw state.
 * 
 * \ingroup NIL
 */

/*
* @violates @ref Cdd_Rfe_c_REF_1 #Functions and objects should not be defined with external linkage
*                                   if they are referenced in only one translation unit
*/
Std_ReturnType CDD_Rfe_GetBistZeroHourReferenceData(Cdd_RfeRxBistZeroHourRefDataType *rxReferenceDataPtr)
{
    /* The standard return type has set to zero*/
    Std_ReturnType ret = E_OK;

    /* start exclusive area for this function     */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_08();
#endif

    /* Set the reported error to none                                                   */
    Cdd_RfeError = rfe_error_none_e;
    /* Call the API to get the list of active FuSa Faults in RFE-Fw */
    rfe_getBistZeroHourReferenceData(rxReferenceDataPtr, &Cdd_RfeError);

    /* Check for error */
    if(Cdd_RfeError != rfe_error_none_e)
    {
        ret = E_NOT_OK;
        /* TODO : simplify the code after the function implementation       */
        if(Cdd_RfeError == rfe_error_api_function_not_implemented_e)
        {
            /* Report temporary error */
            CDD_RFE_DET_REPORT(RSDK_INVALID_PARAMETER, CDD_RFE_GET_DATA, CDD_RFE_E_CMD_NOT_IMPLEMENTD);
            CDD_RFE_HALT_ON_ERROR;
        }
        else
        {
            /* Report Error. */
            CDD_RFE_DET_REPORT(RSDK_RFE_DRIVER_BUSY, CDD_RFE_SET_DATA, CDD_RFE_E_RESPONSE_ERROR);
            CDD_RFE_HALT_ON_ERROR;
        }
    }

    /* exit exclusive area for this function     */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_08();
#endif

    /* Return the fusa Error count. */
    return ret;
}
/* CDD_Rfe_GetBistZeroHourReferenceData *************************/


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
 *  \return uint32_t - Absolute RFE-Fw time since initialization in 25 [ns] resolution.
 *
 *  \post NIL
 *
 *  \ingroup NIL
 */

/*
* @violates @ref Cdd_Rfe_c_REF_1 #Functions and objects should not be defined with external linkage
*                                   if they are referenced in only one translation unit
*/
uint32 CDD_Rfe_GetTime(void)
{
    /* State Variable to store the reference time. */
    uint32  rfeTime = (uint8)CDD_RFE_ZERO;

    /* start exclusive area for this function     */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_09();
#endif

    /* Set the reported error to none                                                   */
    Cdd_RfeError = rfe_error_none_e;
    /* Call the API to get the absolute RFE-Fw time since the initialization in 25[ns] resolution. */
    rfeTime = rfe_getTime(&Cdd_RfeError);

    /* exit exclusive area for this function     */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_09();
#endif

    /* Return the reference time. */
    return rfeTime;
}
/* CDD_Rfe_GetTime *************************/


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
 *  \return Cdd_RfeVersionType - Structure containing RFE-Fw variant and version details.
 *
 *  \post NIL
 *
 *  \ingroup NIL
 */

/*
* @violates @ref Cdd_Rfe_c_REF_1 #Functions and objects should not be defined with external linkage
*                                   if they are referenced in only one translation unit
*/
Cdd_RfeVersionType CDD_Rfe_SwHwGetVersion(void)
{
     /* State Variable  */
    Cdd_RfeVersionType  version;

    /* start exclusive area for this function     */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_10();
#endif


    /* Set the reported error to none                                                   */
    Cdd_RfeError = rfe_error_none_e;
    /* Get the version and variant details of the RFE-Fw hardware and firmware */
    version = rfe_getVersion (&Cdd_RfeError);

    /* exit exclusive area for this function     */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_10();
#endif

    /* Return the version. */
    return version;
}
/* CDD_Rfe_SwHwGetVersion *************************/


/*================================================================================================*/
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
 *
 *  \return Cdd_RfeRadarCycleCountType - The radar cycle and chirp sequence count, when the monitors were read.
 *                                       Values of 0xffff for both values are reporting an error in the call.
 *
 *  \post NIL
 *
 *  \ingroup NIL
 */

/*
* @violates @ref Cdd_Rfe_c_REF_1 #Functions and objects should not be defined with external linkage
*                                   if they are referenced in only one translation unit
*/
Cdd_RfeRadarCycleCountType CDD_Rfe_MonitorRead( Cdd_RfeMonitorSelectType  monitorSelect,
                                                Cdd_RfeMonitorValuesType  *monitorValuesPtr)

{
     /* State Variable  */
    Cdd_RfeRadarCycleCountType  radarCycleCount = { (uint16)CDD_RFE_ZERO, (uint16)CDD_RFE_ZERO };

    /* start exclusive area for this function     */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_11();
#endif

    /* Set the reported error to none                                                   */
    Cdd_RfeError = rfe_error_none_e;
    /* Ask for the RFE-Fw monitors and values.
     * The radar cycle indicate when the monitors were read are stored into 'radarCycleCount'.*/
    radarCycleCount = rfe_monitorRead(monitorSelect, monitorValuesPtr, &Cdd_RfeError);

    /* checking for reported error      */
    if(Cdd_RfeError != rfe_error_none_e)
    {
        /* signalling the error by the returned value       */
        radarCycleCount.chirpSequenceCount = 0xffffu;
        radarCycleCount.radarCycleCount    = 0xffffu;
        /* TODO : simplify the code after the function implementation       */
        if(Cdd_RfeError == rfe_error_api_function_not_implemented_e)
        {
            /* Report temporary error */
            CDD_RFE_DET_REPORT(RSDK_INVALID_PARAMETER, CDD_RFE_GET_DATA, CDD_RFE_E_CMD_NOT_IMPLEMENTD);
            CDD_RFE_HALT_ON_ERROR;
        }
        else
        {
            /* Report temporary error */
            CDD_RFE_DET_REPORT(RSDK_RFE_DRIVER_BUSY, CDD_RFE_GET_DATA, CDD_RFE_E_RESPONSE_ERROR);
            CDD_RFE_HALT_ON_ERROR;
        }
    }

    /* exit exclusive area for this function     */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_11();
#endif

    /* Return the radar cycle count. */
    return radarCycleCount;
}
/* CDD_Rfe_MonitorRead *************************/


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
 *
 *  \return uint32   - Absolute start time of the next scheduled radar cycle in 25 [ns] resolution.
 *
 *  \post NIL
 *
 *  \ingroup NIL
 */

/*
* @violates @ref Cdd_Rfe_c_REF_1 #Functions and objects should not be defined with external linkage
*                                   if they are referenced in only one translation unit
*/
uint32 CDD_Rfe_GetNextRadarCycleStartTime( uint16  *radarCycleIndexPtr)
{
    uint32  startTime = (uint32)CDD_RFE_ZERO;

    /* start exclusive area for this function     */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_12();
#endif

    /* Set the reported error to none                                                   */
    Cdd_RfeError = rfe_error_none_e;
    /* Get the scheduled absolute start time of the next radar cycle */
    startTime = rfe_getNextRadarCycleStartTime(radarCycleIndexPtr, &Cdd_RfeError);

    /* exit exclusive area for this function     */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_12();
#endif

    /* Return start time. */
    return startTime;
}

/* CDD_Rfe_GetNextRadarCycleStartTime *************************/


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
 *
 *  \return uint16   - Index of the next radar cycle of which the start time is set.
 *
 *  \post Next radar cycle starts at the given start time.
 *
 *  \ingroup NIL
 */

/*
* @violates @ref Cdd_Rfe_c_REF_1 #Functions and objects should not be defined with external linkage
*                                   if they are referenced in only one translation unit
*/
uint16 CDD_Rfe_SetNextRadarCycleStartTime(uint32 startTime)
{
    uint16  radarCycleIndex = (uint16)CDD_RFE_ZERO;

    /* start exclusive area for this function     */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_13();
#endif

    /* Set the reported error to none                                                   */
    Cdd_RfeError = rfe_error_none_e;
    /* The API  updates the absolute start time of the next radar cycle according to the RFE time
    and store the index of the next radar cycle of which the start time is set to radarCycleIndex */
    radarCycleIndex = rfe_setNextRadarCycleStartTime(startTime, &Cdd_RfeError);

    /* exit exclusive area for this function     */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_13();
#endif

    /* Return the Index. */
    return radarCycleIndex;
}
/* CDD_Rfe_SetNextRadarCycleStartTime *************************/


/*================================================================================================*/
/**
 *  \brief This function begins a RFE-Fw configuration update operation.
 *
 *  \details When the RFE-Fw Configuration ( as set via Cdd_Rfe_configure()) is required to be done
 *  this is the first function to be called. This function will clear the existing/buffered configuration.
 *  This function does not interact with the RFE-Fw, instead it buffers data locally.
 *  This function does not return any error.
 *
 *  \pre NIL
 *
 *  \return void
 *
 *  \post The functions Cdd_Rfe_updateParam() and/or Cdd_Rfe_updateDynamicTable() must be called after, to prepare
 *  the configuration into the buffer. The new configuration is pusher into RFE-Fw via Cdd_Rfe_updatePush().
 *
 *  \ingroup NIL
 */

/*
* @violates @ref Cdd_Rfe_c_REF_1 #Functions and objects should not be defined with external linkage
*                                   if they are referenced in only one translation unit
*/
void CDD_Rfe_UpdateBegin(void)
{
    /* call the API to begin the update of RFE-Fw configuration */
    rfe_updateBegin();
}
/* CDD_Rfe_UpdateBegin *************************/


/*================================================================================================*/
/**
 *  \brief This functions buffers one of multiple configuration parameter set operations.
 *
 *  \details It buffers an update of the RFE-Fw configuration as was set before via Cdd_Rfe_configure().
 *  All parameters updated like this will be pushed to RFE-Fw when calling Cdd_Rfe_updatePush().
 *  A maximum number of #RFE_UPDATE_COUNT_MAX updates operations are supported for each push.
 *  This function does not interact with the RFE-Fw, instead it buffers data locally.
 *
 *  This function can return one of following errors:
 *  - #rfe_error_api_maxUpdateCountExceeded_e
 *
 *  \pre Call Cdd_Rfe_updateBegin() before any UpdateParam.
 *
 *  \param [in]      section - The configuration section to set
 *  \param [in]      param - The configuration parameter to set
 *  \param [in]      value - The value to set
 *
 *  \return Std_ReturnType - E_OK / E_NOT_OK
 *
 *  \post Push all buffered update operations to RFE-Fw by calling Cdd_Rfe_updatePush().
 *
 *  \ingroup NIL
 */

/*
* @violates @ref Cdd_Rfe_c_REF_1 #Functions and objects should not be defined with external linkage
*                                   if they are referenced in only one translation unit
*/
Std_ReturnType CDD_Rfe_UpdateParam(Cdd_RfeCfgSectionType section,
		Cdd_RfeParamUpdateType param, uint32 value)
{
    /* The standard return type has set to zero*/
    Std_ReturnType ret = E_OK;

    /* Set the reported error to none                                                   */
    Cdd_RfeError = rfe_error_none_e;
    /* Update the RFE-Fw configuration Parameter set operation. */
    rfe_updateParam(section, param, value, &Cdd_RfeError);

    /* Check for error */
    if(Cdd_RfeError != rfe_error_none_e)
    {
        /* Report Error. */
        ret = E_NOT_OK;
        if(Cdd_RfeError == rfe_error_api_function_not_implemented_e)
        {
            CDD_RFE_DET_REPORT(RSDK_INVALID_PARAMETER, CDD_RFE_SET_DATA, CDD_RFE_E_CMD_NOT_IMPLEMENTD);
            CDD_RFE_HALT_ON_ERROR;
        }
        else
        {
            CDD_RFE_DET_REPORT(RSDK_RFE_DRIVER_BUSY, CDD_RFE_SET_DATA, CDD_RFE_E_RESPONSE_ERROR);
            CDD_RFE_HALT_ON_ERROR;
        }
    }
    /* return the update count */
    return ret;
}
/* CDD_Rfe_UpdateParam *************************/


/*================================================================================================*/
/**
 *
 *  \brief This functions buffers a dynamic table update.
 *
 *  \details It buffers an update of the dynamic table currently configured on the RFE-Fw..
 *  It indicates to the RFE-Fw that a full dynamic table or part of it (i.e. selected dynamic parameters),
 *  located at the dynamicTableAddress in system memory (as configured via Cdd_Rfe_configure()), needs to be updated
 *  in the RFE-Fw. This updated parameters and other buffered updates will be pushed to RFE-Fw
 *  when calling Cdd_Rfe_updatePush().
 *  A maximum number of #RFE_UPDATE_COUNT_MAX updates operations are supported.
 *  This function does not interact with the RFE, instead it buffers data locally.
 *
 *  This function can return one of following errors:
 *  - #rfe_error_api_maxUpdateCountExceeded_e
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
 *  \ingroup NIL
*/

/*
* @violates @ref Cdd_Rfe_c_REF_1 #Functions and objects should not be defined with external linkage
*                                   if they are referenced in only one translation unit
*/
Std_ReturnType CDD_Rfe_UpdateDynamicTable(uint8 dynamicTableIndex,
                                        Cdd_RfeDynParamsSelectType paramsSelect)
{
    /* The standard return type has set to zero*/
    Std_ReturnType ret = E_OK;

    /* Set the reported error to none                                                   */
    Cdd_RfeError = rfe_error_none_e;
    /* Call the API to buffer the update of the dynamic Table for RFE-Fw */
    rfe_updateDynamicTable(dynamicTableIndex, paramsSelect, &Cdd_RfeError);

    /* Check for error */
    if(Cdd_RfeError != rfe_error_none_e)
    {
       /* Report Error. */
       ret = E_NOT_OK;
       if(Cdd_RfeError == rfe_error_api_function_not_implemented_e)
       {
           CDD_RFE_DET_REPORT(RSDK_INVALID_PARAMETER, CDD_RFE_SET_DATA, CDD_RFE_E_CMD_NOT_IMPLEMENTD);
           CDD_RFE_HALT_ON_ERROR;
       }
       else
       {
           CDD_RFE_DET_REPORT(RSDK_RFE_DRIVER_BUSY, CDD_RFE_SET_DATA, CDD_RFE_E_RESPONSE_ERROR);
           CDD_RFE_HALT_ON_ERROR;
       }
    }

   /* return the operation error status */
   return ret;
}
/* CDD_Rfe_UpdateDynamicTable *************************/


/*================================================================================================*/
/**
 *
 *  \brief This function pushes all the buffered update operations jointly to RFE-Fw.
 *
 *  \details Update-operations can be buffered by Cdd_Rfe_updateParam() or Cdd_Rfe_updateDynamicTable().
 *  It updates the RFE-Fw configuration as was set via Cdd_Rfe_configure(). The RFE-Fw will first check that
 *  the parameter values are within the supported range. If so, the parameters will be jointly applied for the
 *  next radar cycle. The next radar cycle index will be returned by this API function.
 *  Updates are not allowed when the last radar cycle is active. When there is no radar cycle active,
 *  the updates will be applied immediately within the API function.
 *  An error is returned if the parameters are not within the accepted range.
 *  This function returns after the RFE-Fw has accepted or rejected the call.
 *
 *  This function can return one of following errors:
 *  - #rfe_error_api_unsynchronized_e
 *  - #rfe_error_api_operationNotAllowed_e
 *  - #rfe_error_api_busy_e
 *  - #rfe_error_api_noUpdatesBuffered_e
 *  - #rfe_error_api_maxUpdateCountExceeded_e
 *  - #rfe_error_api_updateAlreadyPending_e
 *  - #rfe_error_api_invalidParameterForUpdate_e
 *  - #rfe_error_api_dynamicTablesNotConfigured_e
 *  - #rfe_error_api_cfgSectionMismatch_e
 *  - Any _cmdInterface_ error of #rfe_error_t.
 *  - #rfe_error_sharedData_redundancyCheckFailed_e
 *  - #rfe_error_rfeFuSaFault_e
 *
 *  \pre RFE-Fw must be in #rfe_state_configured_e or #rfe_state_radarCycleIdle_e state.
 *
 *  \return uint16   - The index of the next radar cycle at which the updates will be applied.
 *                     If radar cycle is not active, 0 will be returned.
 *
 *  \post NIL
 *
 *  \ingroup NIL
 */

/*
* @violates @ref Cdd_Rfe_c_REF_1 #Functions and objects should not be defined with external linkage
*                                   if they are referenced in only one translation unit
*/
uint16 CDD_Rfe_UpdatePush(void)
{
    /* State Variable  */
    uint16  radarCycleCount;

    /* enter exclusive area for this function     */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_14();
#endif

    /* Set the reported error to none                                                   */
    Cdd_RfeError = rfe_error_none_e;
    /* Call the API to push all the buffered  update operations and there is no active radar cycle */
    radarCycleCount = rfe_updatePush(&Cdd_RfeError);

    /* Check for error */
    if(Cdd_RfeError != rfe_error_none_e)
    {
        if(Cdd_RfeError == rfe_error_api_function_not_implemented_e)
        {
            CDD_RFE_DET_REPORT(RSDK_INVALID_PARAMETER, CDD_RFE_SET_DATA, CDD_RFE_E_CMD_NOT_IMPLEMENTD);
            CDD_RFE_HALT_ON_ERROR;
        }
        else
        {
            CDD_RFE_DET_REPORT(RSDK_RFE_DRIVER_BUSY, CDD_RFE_SET_DATA, CDD_RFE_E_RESPONSE_ERROR);
            CDD_RFE_HALT_ON_ERROR;
        }
        /* clear the radarCycleCount */
        radarCycleCount = (uint16)CDD_RFE_ZERO;
    }

    /* exit exclusive area for this function     */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_14();
#endif

    /* return the next Radar Cycle Count. */
    return radarCycleCount;
}
/* CDD_Rfe_UpdatePush *************************/


/*================================================================================================*/
/**
 *
 *  \brief This function start continuous wave transmission.
 *
 *  \details RFE-Fw use the profile configured via Cdd_Rfe_configure() as specified by \p profileIndex.
 *  The effective chirp bandwidth of this profile is neglected.
 *  The frequency is kept at the configured center frequency.
 *  This function  returns after RFE-Fw has accepted or rejected the call.
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
 *  \pre RFE-Fw must be in #rfe_state_configured_e state.
 *
 *  \param [in]      profileIndex - Index of the chirp profile to be used for continuous wave transmission.
 *
 *  \return Std_ReturnType - E_OK / E_NOT_OK
 *
 *  \post RFE-Fw goes to  #rfe_state_testContinuousWaveTransmission_e state.
 *
 *  \ingroup NIL
 */

/*
* @violates @ref Cdd_Rfe_c_REF_1 #Functions and objects should not be defined with external linkage
*                                   if they are referenced in only one translation unit
*/
Std_ReturnType CDD_Rfe_TestContinuousWaveTransmissionStart(Cdd_RfeChirpProfileIndexType profileIndex )
{
    /* The standard return type has set to zero*/
    Std_ReturnType ret = E_OK;

    /* enter exclusive area for this function     */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_15();
#endif

    /* Set the reported error to none                                                   */
    Cdd_RfeError = rfe_error_none_e;
    /* Call the API to start the continuous wave transmission */
    rfe_testContinuousWaveTransmissionStart(profileIndex, &Cdd_RfeError);

    /* Check for error */
    if(Cdd_RfeError != rfe_error_none_e)
    {
        /* Report Error. */
        ret = E_NOT_OK;
        if(Cdd_RfeError == rfe_error_api_function_not_implemented_e)
        {
            CDD_RFE_DET_REPORT(RSDK_INVALID_PARAMETER, CDD_RFE_START_EXECUTION, CDD_RFE_E_CMD_NOT_IMPLEMENTD);
            CDD_RFE_HALT_ON_ERROR;
        }
        else
        {
            CDD_RFE_DET_REPORT(RSDK_RFE_DRIVER_BUSY, CDD_RFE_START_EXECUTION, CDD_RFE_E_RESPONSE_ERROR);
            CDD_RFE_HALT_ON_ERROR;
        }
    }

    /* exit exclusive area for this function     */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_15();
#endif

    return ret;
}
/* CDD_Rfe_TestContinuousWaveTransmissionStart *************************/


/*================================================================================================*/
/**
 *
 *  \brief This function stops continuous wave transmission.
 *
 *  \details Continuous wave transmission can be started via Cdd_Rfe_testContinuousWaveTransmissionStart().
 *  This function returns after RFE-Fw has accepted or rejected the call.
 *
 *  This function can return one of following errors:
 *  - #rfe_error_api_unsynchronized_e
 *  - #rfe_error_api_operationNotAllowed_e
 *  - #rfe_error_api_busy_e
 *  - Any _cmdInterface_ error of #rfe_error_t.
 *  - #rfe_error_sharedData_redundancyCheckFailed_e
 *  - #rfe_error_rfeFuSaFault_e
 *
 *  \pre RFE-Fw must be in #rfe_state_testContinuousWaveTransmission_e state.
 *
 *  \return Std_ReturnType - E_OK / E_NOT_OK
 *
 *  \post RFE-Fw goes to  #rfe_state_configured_e state.
 *
 *  \ingroup NIL
 */
 
/*
* @violates @ref Cdd_Rfe_c_REF_1 #Functions and objects should not be defined with external linkage
*                                   if they are referenced in only one translation unit
*/
/*
* @violates @ref Cdd_Rfe_c_REF_3 #External identifiers shall be distinct
*/
Std_ReturnType CDD_Rfe_TestContinuousWaveTransmissionStop(void)
{
    /* The standard return type has set to zero*/
    Std_ReturnType ret = E_OK;

    /* enter exclusive area for this function       */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_16();
#endif

    /* Set the reported error to none                                                   */
    Cdd_RfeError = rfe_error_none_e;
    /* Stop the continuous wave transmission */
    rfe_testContinuousWaveTransmissionStop(&Cdd_RfeError);

    /* Check for error */
    if(Cdd_RfeError != rfe_error_none_e)
    {
        /* Report Error. */
        ret = E_NOT_OK;
        if(Cdd_RfeError == rfe_error_api_function_not_implemented_e)
        {
            CDD_RFE_DET_REPORT(RSDK_INVALID_PARAMETER, CDD_RFE_STOP_EXECUTION, CDD_RFE_E_CMD_NOT_IMPLEMENTD);
            CDD_RFE_HALT_ON_ERROR;
        }
        else
        {
            CDD_RFE_DET_REPORT(RSDK_RFE_DRIVER_BUSY, CDD_RFE_STOP_EXECUTION, CDD_RFE_E_RESPONSE_ERROR);
            CDD_RFE_HALT_ON_ERROR;
        }
    }

    /* exit exclusive area for RFE unit setup     */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_01();
#endif

    /* Return execution result */
    return ret;
}
/* CDD_Rfe_TestContinuousWaveTransmissionStop *************************/


/*================================================================================================*/
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
/*
* @violates @ref Cdd_Rfe_c_REF_1 #Functions and objects should not be defined with external linkage
*                                   if they are referenced in only one translation unit
*/
Std_ReturnType CDD_Rfe_TestSetParam(Cdd_RfeTestParamType testParam, uint32 value)
{
    /* The standard return type has set to zero*/
    Std_ReturnType ret = E_OK;

    /* enter exclusive area for this function     */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_17();
#endif

    /* Set the reported error to none                                                   */
    Cdd_RfeError = rfe_error_none_e;
    /* Set test parameter.*/
    rfe_testSetParam(testParam, value, &Cdd_RfeError);

    /* Check for error */
    if(Cdd_RfeError != rfe_error_none_e)
    {
        if(Cdd_RfeError == rfe_error_api_function_not_implemented_e)
        {
            CDD_RFE_DET_REPORT(RSDK_INVALID_PARAMETER, CDD_RFE_SET_DATA, CDD_RFE_E_CMD_NOT_IMPLEMENTD);
            CDD_RFE_HALT_ON_ERROR;
        }
        else
        {
            CDD_RFE_DET_REPORT(RSDK_RFE_DRIVER_BUSY, CDD_RFE_SET_DATA, CDD_RFE_E_RESPONSE_ERROR);
            CDD_RFE_HALT_ON_ERROR;
        }
        ret = E_NOT_OK;
    }

    /* exit exclusive area for this function     */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_17();
#endif

   return ret;
}
/* CDD_Rfe_TestSetParam *************************/


/*================================================================================================*/
/**
 *
 *  \brief This function provides the error occurred.
 *
 *  \details This function returns the registered error and clears the error register.
 *  This function return the currently registered error in the register.
 *
 * CDD_Rfe_GetError() can then return one of following errors:
 * - #rfe_error_api_unsynchronized_e
 * - #rfe_error_api_operationNotAllowed_e
 * - #rfe_error_api_busy_e
 * - #rfe_error_api_invalidArgumentValue_e
 * - Any _cmdInterface_ error of #rfe_error_t.
 * - #rfe_error_sharedData_redundancyCheckFailed_e
 * - #rfe_error_rfeFuSaFault_e
 *  \pre The RFE-Fw must be powered up and initialized.
 *
 *  \return Cdd_RfeErrorType
 *
 */
/*
* @violates @ref Cdd_Rfe_c_REF_1 #Functions and objects should not be defined with external linkage
*                                   if they are referenced in only one translation unit
*/
Cdd_RfeErrorType CDD_Rfe_GetError(void)
{
   /* Store the variable. */
   Cdd_RfeErrorType ret = Cdd_RfeError;

   /* Clear the error. */
    Cdd_RfeError = rfe_error_none_e;

   /* Return Error. */
   return ret;
}
/* CDD_Rfe_GetError *************************/


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
/*
* @violates @ref Cdd_Rfe_c_REF_1 #Functions and objects should not be defined with external linkage
*                                   if they are referenced in only one translation unit
*/
Std_ReturnType CDD_Rfe_TestGetInternalError(void)
{
    /* The standard return type has set to zero*/
    Std_ReturnType  ret = E_OK;
    uint32_t        crtError;

    /* start exclusive area for this function     */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_18();
#endif

    Cdd_RfeError = rfe_error_none_e;
    /* Call the API to get the Internal Error */
    crtError = rfe_testGetInternalError(&Cdd_RfeError);

    /* Check for error */
    if(Cdd_RfeError != rfe_error_none_e)
    {
        /* Report there was an execution error, the current error reported is that execution error              */
        ret = E_NOT_OK;
        if(Cdd_RfeError == rfe_error_api_function_not_implemented_e)
        {
            CDD_RFE_DET_REPORT(RSDK_INVALID_PARAMETER, CDD_RFE_GET_DATA, CDD_RFE_E_CMD_NOT_IMPLEMENTD);
            CDD_RFE_HALT_ON_ERROR;
        }
        else
        {
            CDD_RFE_DET_REPORT(RSDK_RFE_DRIVER_BUSY, CDD_RFE_GET_DATA, CDD_RFE_E_RESPONSE_ERROR);
            CDD_RFE_HALT_ON_ERROR;
        }
    }
    else
    {
        /* correct execution, so report E_OK and set the general error value to the InternalError reported.     */
        /*
        * @violates @ref Cdd_Rfe_c_REF_1 #The value of an expression should not be cast
        *                                   to an inappropriate essential type.
        */
        Cdd_RfeError = (Cdd_RfeErrorType)crtError;
    }

    /*  exit exclusive area for the function     */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_18();
#endif

    /* Return the general OK/NOT_OK result */
    return ret;
}
/* CDD_Rfe_TestGetInternalError *************************/


/*================================================================================================*/
/**
*
*   \brief      Function to get the specified value from the blob.
*
*   \details    The function identifies the value to be returned, according to the provided parameters.
*               An uint32 value will be returned, for any dimension of the required value.
*
*   @param[in]  pConfig - pointer to the blob array
*               section - blob section
*               param   - section parameter
*
*/
Std_ReturnType CDD_Rfe_GetBlobValue(uint8* configPtr, Cdd_RfeCfgSectionType section, Cdd_RfeCfgParamType param, uint32 *valuePtr)
{
    /* The standard return type has set to zero*/
    Std_ReturnType  ret = E_OK;

    /* start exclusive area for this function     */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_19();
#endif

    Cdd_RfeError = rfe_error_none_e;
    *valuePtr = rfeCfg_read(configPtr, section, param, (rfe_error_t*)&Cdd_RfeError);
    if(Cdd_RfeError != rfe_error_none_e)
    {
        ret = E_NOT_OK;
    }

    /* end exclusive area for this function     */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Exir_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_19();
#endif

    return ret;
}


/*================================================================================================*/
/**
*
*   \brief      Function to get the specified value from the blob.
*
*   \details    The function identifies the value to be set, according to the provided parameters.
*               The provided value is truncated to the real blob value dimension.
*
*   @param[in]  pConfig - pointer to the blob array
*               section - blob section
*               param   - section parameter
*               value   - the value to be set
*
*/
Std_ReturnType CDD_Rfe_SetBlobValue(uint8* configPtr, Cdd_RfeCfgSectionType section, Cdd_RfeCfgParamType param,
        uint32 value)
{
    /* The standard return type has set to zero*/
    Std_ReturnType  ret = E_OK;

    /* start exclusive area for this function     */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_20();
#endif

    Cdd_RfeError = rfe_error_none_e;
    rfeCfg_write(configPtr, section, param, value, (rfe_error_t*)&Cdd_RfeError);
    if(Cdd_RfeError != rfe_error_none_e)
    {
        ret = E_NOT_OK;
    }

    /* end exclusive area for this function     */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Exir_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_20();
#endif

    return ret;
}


/*================================================================================================*/
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
*   @param[in]  frontEndSelect  - front-end selection mask
*   @param[in]  moduleSelect    - module selection mask
*   @param[in]  dumpArrayPtr    - pointer to the returned values array of rfe_registerDumpValues_t type
*   @param[in]  dumpArrayPtrLen - pointer to the returned values array maximum length
*   @param[out] dumpArrayPtrLen - pointer to the exact number of returned values
*
*/
Std_ReturnType CDD_Rfe_GetRegisterDump(CDD_RfeFrontEndIdMaskType frontEndSelect, rfe_moduleDumpSelect_t moduleSelect, rfe_registerDumpValues_t *dumpArrayPtr,
        uint32_t *dumpArrayLenPtr)
{
    /* The standard return type has set to zero*/
    Std_ReturnType  ret = E_OK;

    /* start exclusive area for this function     */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_21();
#endif

    Cdd_RfeError = rfe_error_none_e;
    rfe_getRegisterDump((uint8_t)frontEndSelect, moduleSelect, dumpArrayPtr, dumpArrayLenPtr, (rfe_error_t*)&Cdd_RfeError);
    if(Cdd_RfeError != rfe_error_none_e)
    {
        ret = E_NOT_OK;
    }

    /* end exclusive area for this function     */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Exir_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_21();
#endif

    return ret;
}


/*================================================================================================*/
/**
*
*
*   \brief Service for passing the Information through a pointer *VersionInfo
*
*   \n<b>Description</b>:\n
*   Service for passing the Information through a pointer "*VersionInfo". \n
*
*   \n<b>Precondition</b>:\n
*   \n<b>used global variables</b>:\n
*
*   \n<b>Referenced Software-Requirements</b>:
*   "AUTOSAR_EXP_CDDDesignAndIntegrationGuideline.pdf"
*
*   @param[in]   - versioninfo --> pointer to an address where all the version
*                     information needs to be copied.
*    @param[out]  - none
*    @return      - none
*/

#if(CDD_RFE_VERSION_INFO_API == STD_ON)
/*
* @violates @ref Cdd_Rfe_c_REF_1 #Functions and objects should not be defined with external linkage
*                                   if they are referenced in only one translation unit
*/
void CDD_Rfe_GetVersionInfo (Std_VersionInfoType *versionInfoPtr)
{
#if (STD_ON == CDD_RFE_DEV_ERROR_DETECT)
    if (NULL_PTR == versionInfoPtr)
    {
      /* Call the DET.  */
      (void)Det_ReportError((uint16)CDD_RFE_AR_MODULE_ID, (uint8)CDD_RFE_AR_INSTANCE_ID,
                              (uint8)CDD_RFE_SID_GET_VERSION_INFO, (uint8)CDD_RFE_E_PARAM_POINTER);
    }
    else
#endif
    {
        versionInfoPtr->vendorID         = (uint16) CDD_RFE_AR_VENDOR_ID;
        versionInfoPtr->moduleID         = (uint16) CDD_RFE_AR_MODULE_ID;
        versionInfoPtr->sw_major_version = (uint8)  CDD_RFE_SW_MAJOR_VERSION;
        versionInfoPtr->sw_minor_version = (uint8)  CDD_RFE_SW_MINOR_VERSION;
        versionInfoPtr->sw_patch_version = (uint8)  CDD_RFE_SW_PATCH_VERSION;
    }
}
#endif
/* CDD_Rfe_GetVersionInfo *************************/


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
Std_ReturnType CDD_Rfe_SetFrontEnd(CDD_RfeFrontEndHierarchyType frontEndPos)
{
    /* The standard return type has set to zero*/
    Std_ReturnType  ret = E_OK;

    /* start exclusive area for this function     */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_19();
#endif

    Cdd_RfeError = rfe_error_none_e;
    rfe_setFrontEnd((uint8)frontEndPos, &Cdd_RfeError);
    if(Cdd_RfeError != rfe_error_none_e)
    {
        ret = E_NOT_OK;
    }

#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_19();
#endif
    return ret;
}
/* CDD_Rfe_SetFrontEnd *************************/


/*================================================================================================*/
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
Std_ReturnType CDD_Rfe_GetFrontEnd(CDD_RfeFrontEndHierarchyType *frontEndPosPtr)
{
    /* The standard return type has set to zero*/
    Std_ReturnType  ret;
    uint8           rez;

    /* start exclusive area for this function     */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_19();
#endif
    Cdd_RfeError = rfe_error_none_e;
    rez = rfe_getFrontEnd(&Cdd_RfeError);
    if(Cdd_RfeError != rfe_error_none_e)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *frontEndPosPtr = rez;
        ret = E_OK;
    }

#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_19();
#endif

    return ret;
}
/* CDD_Rfe_GetFrontEnd *************************/

/*================================================================================================*/
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
 */Std_ReturnType CDD_Rfe_ConfigureInterrupt(
                                Cdd_RfeCoreIdDataType coreId,
                                Cdd_RfeEventsIRQDataType events,
                                Cdd_RfeApiIRQDataType rfeAPIs,
                                Cdd_RfeApiWaitForInterruptDataType apiWaitForInterrupt )
{
    /* The standard return type has set to zero*/
    Std_ReturnType  ret = E_OK;

    /* start exclusive area for RFE unit setup     */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Enter_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_20();
#endif

    Cdd_RfeError = rfe_error_none_e;
    /* Call the API to configure RFE-FW IRQ */
    rfe_configureInterrupt( coreId, events, rfeAPIs, apiWaitForInterrupt, &Cdd_RfeError);
    /* Check for error */
    if(Cdd_RfeError != rfe_error_none_e)
    {
        /*set ret value */
        ret = E_NOT_OK;
    }

    /*  exit exclusive area for RFE unit setup     */
#if (CDD_RFE_SINGLE_MANAGEMENT_THREADS == STD_OFF)
    SchM_Exit_Cdd_Rfe_CDD_RFE_EXCLUSIVE_AREA_20();
#endif

    /* Return whether the API call has been accepted or rejected */
    return ret;
}
/* CDD_Rfe_ConfigureInterrupt *************************/

#define CDD_RFE_STOP_SEC_CODE
/*
* @violates @ref Cdd_Rfe_c_REF_2 #Include directives should only be preceded by preprocessor directives or comments.
*/
#include "CDD_Rfe_MemMap.h"

#ifdef __cplusplus
}
#endif
