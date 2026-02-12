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

#ifndef    CDD_RFE_TYPES_H
#define    CDD_RFE_TYPES_H


/**
*   @file
*   @implements CDD_Rfe_Types.h_Artifact
*
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "rfe_low_level.h"
#include "rsdk_version.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_RFE_TYPES_AR_MODULE_ID                     255
#define CDD_RFE_TYPES_AR_INSTANCE_ID                   0
#define CDD_RFE_TYPES_VENDOR_ID                        43
#define CDD_RFE_TYPES_AR_RELEASE_MAJOR_VERSION         RSDK_AR_MAJOR
#define CDD_RFE_TYPES_AR_RELEASE_MINOR_VERSION         RSDK_AR_MINOR
#define CDD_RFE_TYPES_AR_RELEASE_REVISION_VERSION      RSDK_AR_REV
#define CDD_RFE_TYPES_SW_MAJOR_VERSION                 RSDK_SW_MAJOR
#define CDD_RFE_TYPES_SW_MINOR_VERSION                 RSDK_SW_MINOR
#define CDD_RFE_TYPES_SW_PATCH_VERSION                 RSDK_SW_PATCH

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/**
*   @addtogroup rsdk_rfe_api_const
*   @{
*/

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/** Zero value                              */
#define CDD_RFE_ZERO                 (uint32)0U

/**
* @brief API IDs.
*/
#define CDD_RFE_SID_INIT                                       (0x00U)
#define CDD_RFE_SID_CONFIGURE                                  (0x01U)
#define CDD_RFE_SID_RADARCYCLESTART                            (0x02U)
#define CDD_RFE_SID_RADARCYCLESTOP                             (0x03U)
#define CDD_RFE_SID_GETSTATE                                   (0x04U)
#define CDD_RFE_SID_GETRADARCYCLECOUNT                         (0x05U)
#define CDD_RFE_SID_GETFUSAERRORS                              (0x06U)
#define CDD_RFE_SID_GETTIME                                    (0x07U)
#define CDD_RFE_SID_GETVERSION                                 (0x08U)
#define CDD_RFE_SID_MONITORREAD                                (0x09U)
#define CDD_RFE_SID_GETNEXTRADARCYCLESTARTTIME                 (0x0AU)
#define CDD_RFE_SID_SETNEXTRADARCYCLESTARTTIME                 (0x0BU)
#define CDD_RFE_SID_UPDATEBEGIN                                (0x0CU)
#define CDD_RFE_SID_UPDATEPARAM                                (0x0DU)
#define CDD_RFE_SID_UPDATEDYNAMICTABLE                         (0x0EU)
#define CDD_RFE_SID_UPDATEPUSH                                 (0x13U)
#define CDD_RFE_SID_TESTCONTINUOUSWAVETRANSMISSIONSTART        (0x14U)
#define CDD_RFE_SID_TESTCONTINUOUSWAVETRANSMISSIONSTOP         (0x0FU)
#define CDD_RFE_SID_TESTSETPARAM                               (0x10U)
#define CDD_RFE_SID_GET_VERSION_INFO                           (0x11U)
#define CDD_RFE_SID_GET_ERROR                                  (0x12U)
#define CDD_RFE_SID_INVALID                                    (0xFFU)


/**
* @brief API request called with an invalid parameter ( Nullpointer or invalid parameter).
* rfe_error_api_invalidArgumentValue_e,
* rfe_error_api_cfgInvalidParameterSize_rfeDriverOnly_e,
* */
#define CDD_RFE_E_PARAM_POINTER                ((uint8)0x01U)
#define CDD_RFE_E_PARAM_SIZE                   ((uint8)0x02U)


/**
* @brief API request called with invalid parameter (invalid value).
* rfe_error_api_invalidConfigurationSize_e,
* rfe_error_api_maxUpdateCountExceeded_e,
* rfe_error_api_noUpdatesBuffered_e,
* rfe_error_sharedData_invalidIndex_e,
* */
#define CDD_RFE_E_LIMIT_EXCEED                 ((uint8)0x03U)


/**
* @brief API request with Redundancy Check Error .
* rfe_error_sharedData_redundancyCheckFailed_e,
* */
#define CDD_RFE_E_REDUNDANCY_CHECK_FAILED      ((uint8)0x04U)


/**
* @brief API request with of RFE Driver Initialization failed.
* rfe_error_api_unsynchronized_e.
* */
#define CDD_RFE_E_SETUP_FAILED                 ((uint8)0x05U)

/**
* @brief API request with invalid response, CRC and response length.
* rfe_error_cmdInterface_invalidResponse_e,
* rfe_error_cmdInterface_invalidCrc_e,
* rfe_error_cmdInterface_invalidRspLength_e,
* */
#define CDD_RFE_E_RESPONSE_ERROR               ((uint8)0x06U)

/**
* @brief API request with Invalid Command Length.
* rfe_error_cmdInterface_invalidCmdLength_e,
* */
#define CDD_RFE_E_CMD_LENGTH                   ((uint8)0x07U)

/**
* @brief API request for a function not implemented in RFE-Fw side.
* rfe_error_api_function_not_implemented_e,
* */
#define CDD_RFE_E_CMD_NOT_IMPLEMENTD            ((uint8)0x08U)



/* Formal API id for some CDD_RFE driver functions groups, to be used at development time                       */
/*! Error at VersionInfo call                           */
#define CDD_RFE_VERSION_INFO_CHECK              0u
/*! Error at configuration time                         */
#define CDD_RFE_CONFIGURE                       1u
/*! Error when ask for execution start                  */
#define CDD_RFE_START_EXECUTION                 2u
/*! Error when ask for execution start                  */
#define CDD_RFE_STOP_EXECUTION                  3u
/*! Error when ask for data from RFE-Fw                 */
#define CDD_RFE_GET_DATA                        4u
/*! Error when ask for data set                         */
#define CDD_RFE_SET_DATA                        5u


/**
*   @}
*   @addtogroup rsdk_rfe_api_interface
*   @{
*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/


/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
 * This type defines an address to system memory.
 */
typedef  rfe_sysMemAddress_t           Cdd_RfeSysMemAddressType;

/**
 *  This enumeration data type is used for FuSa faults.
 *  - In RFE Configuration, the enumeration must be used as bitwise index to mask
 *  or unmask the corresponding fault bit.
 *  - In CDD_Rfe_GetFuSaFaults(), the enumeration must be used as bitwise index to get
 *  the fault status for the corresponding fault.
 *  - In CDD_Rfe_GetFuSaFaultStatistics(), the enumeration must be used as bytewise index
 *  to get the fault count for the corresponding R1 fault.
 *
 */
typedef  rfe_fuSaFault_t               Cdd_RfeFusaFaultType           ;

/**
 * API error codes.
 */
typedef  rfe_error_t                   Cdd_RfeErrorType               ;

/**
 * This types defines a selection of RFE monitors.
 */
typedef  rfe_monitorSelect_t           Cdd_RfeMonitorSelectType       ;

/**
 * This structure is a container for all RFE monitors to be read via rfe_monitorRead().
 */
typedef  rfe_monitorValues_t           Cdd_RfeMonitorValuesType       ;

/**
 * The defined sections.
 */
typedef  rfeCfg_section_t              Cdd_RfeCfgSectionType          ;

/**
 * The defined sections.
 */
typedef  rfeCfg_param_t                Cdd_RfeCfgParamType          ;

/**
 * This enumerated types defines the RFE parameters that can be updated.
 */
typedef  rfe_paramUpdate_t             Cdd_RfeParamUpdateType         ;

/**
 * This type defines a selection of dynamic parameters.
 */
typedef  rfe_dynParamsSelect_t         Cdd_RfeDynParamsSelectType     ;

/**
 * This enumerated type defines the chirp profile indices.
 */
typedef  rfe_chirpProfileIndex_t       Cdd_RfeChirpProfileIndexType   ;

/**
 * This enumerated type defines the RFE test parameters.
 * Used by rfe_testSetParam().
 */
typedef  rfe_testParam_t               Cdd_RfeTestParamType           ;

/**
 * This structure contains the radar cycle and chirp sequence count.
 * It can be retrieved via rfe_getRadarCycleCount().
 */
typedef  rfe_radarCycleCount_t         Cdd_RfeRadarCycleCountType     ;

/**
 * This type defines the RFE states.
 * RFE state can be retrieved via rfe_getState().
 */
typedef  rfe_state_t                   Cdd_RfeStateType               ;

/**
 * This structure contains the version and variant details of the rfe:
 * - Hardware and firmware variants
 */
typedef  rfe_version_t                 Cdd_RfeVersionType             ;


/**
 * This structure contains the zero hour reference data for
 * rxPhase difference, Gain difference
 * It can be retrieved via CDD_Rfe_GetBistZeroHourReferenceData().
 */
typedef  rfeCfg_rxBistReferenceData_t   Cdd_RfeRxBistZeroHourRefDataType             ;


/**
 * This enumerated type defines which core will receive IRQs from RFE firmware
 * \note Core Id 0: appM7 core
 *       Core Id 1: a53 core
 */
typedef  rfe_coreId_t                   Cdd_RfeCoreIdDataType                        ;

/**
 * This type defines which events shall trigger an IRQ from RFE firmware
 */
typedef  rfe_eventsIRQ_t                Cdd_RfeEventsIRQDataType                     ;

/**
 * This type defines which RFE APIs shall trigger an IRQ from RFE firmware upon completion
 */
typedef  rfe_apiIRQ_t                   Cdd_RfeApiIRQDataType                        ;

/**
 * This type defines RFE API wait for interrupt function pointer.
 */
typedef rfe_apiWaitForInterrupt_f       Cdd_RfeApiWaitForInterruptDataType           ;


/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

/** @} */

#ifdef __cplusplus
}
#endif

#endif    /* CDD_RFE_TYPES_H */
