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

#ifndef RFE_SW_CFG_MNGR_H
#define RFE_SW_CFG_MNGR_H


/******************************************************************************
 *                              INCLUDES
 *****************************************************************************/

#include "rfe_error.h"
#include "rfe_types.h"


/******************************************************************************
 *                              TYPES
 *****************************************************************************/

/** This macro defines the minimum dynamic table address (start of system memory) */
#define RFE_SW_CFG_MNGR_DYNAMIC_TABLE_ADDRESS_MIN                                   ( 0x33E00000 )
/** This macro defines the maximum dynamic table address (end of system memory) */
#define RFE_SW_CFG_MNGR_DYNAMIC_TABLE_ADDRESS_MAX                                   ( 0x33FFFFFF )

/** This macro defines the size of the global dynamic tables header */
#define RFE_SW_CFG_MNGR_DYN_TABLES_GLOBAL_HEADER_SIZE                               ( 4UL )

/** This macro defines the size of the per-dynamic-table header size */
#define RFE_SW_CFG_MNGR_DYN_TABLES_PER_TABLE_HEADER_SIZE                            ( 28UL )

/** This macro defines the size of the dynamic table header */
#define RFE_SW_CFG_MNGR_DYN_TABLES_MAX_OVERHEAD                                     ( RFE_SW_CFG_MNGR_DYN_TABLES_GLOBAL_HEADER_SIZE + RFE_SW_CFG_MNGR_DYNAMIC_TABLE_COUNT_MAX * RFE_SW_CFG_MNGR_DYN_TABLES_PER_TABLE_HEADER_SIZE )

/** This macro defines the maximum supported size of the dynamic tables in bytes */
#define RFE_SW_CFG_MNGR_DYN_TABLES_TOTAL_SIZE_MAX                                   ( 8192UL + RFE_SW_CFG_MNGR_DYN_TABLES_MAX_OVERHEAD )

/**
 * This macro defines the value for the section of the param update, when updating
 * the dynamic table.
 */
#define RFE_SW_CFG_MNGR_UPDATE_SECTION_DYNAMIC_TABLE                                ( 0xFFFFUL )

/**
 * These macros define the min and max value for configuration parameters that are
 * supported by the dynamic table. The macros are used in #paramMetadataTable and in
 * rfeSwCfgMngr_validateDynamicTable()
 */
#define RFE_SW_CFG_MNGR_DYNAMIC_TABLE_COUNT_MIN                                     ( 1UL )
#define RFE_SW_CFG_MNGR_DYNAMIC_TABLE_COUNT_MAX                                     ( 8UL )
#define RFE_SW_CFG_MNGR_DYNAMIC_SEQUENCE_LENGTH_MIN                                 ( 1UL )
#define RFE_SW_CFG_MNGR_DYNAMIC_SEQUENCE_LENGTH_MAX                                 ( 4096UL )
#define RFE_SW_CFG_MNGR_CHIRP_PROFILE_MIN                                           ( 0UL )
#define RFE_SW_CFG_MNGR_CHIRP_PROFILE_MAX                                           ( 7UL )
#define RFE_SW_CFG_MNGR_PHASE_ROTATION_MIN                                          ( 0x00UL )
#define RFE_SW_CFG_MNGR_PHASE_ROTATION_MAX                                          ( 0x7FUL )
#define RFE_SW_CFG_MNGR_TX_TRANSMISSION_ENABLE_MIN                                  ( 0x0UL )
#define RFE_SW_CFG_MNGR_TX_TRANSMISSION_ENABLE_MAX                                  ( 0xFUL )
#define RFE_SW_CFG_MNGR_DWELL_TIME_TICKS_MIN                                        ( 0x002UL )
#define RFE_SW_CFG_MNGR_DWELL_TIME_TICKS_MAX                                        ( 0xFFEUL )
#define RFE_SW_CFG_MNGR_CIT_TICKS_MIN                                               ( 0x000002UL )
#define RFE_SW_CFG_MNGR_CIT_TICKS_MAX                                               ( 0x3FFFFFUL )
#define RFE_SW_CFG_MNGR_CHIRP_FREQUENCY_DRIFT_STEPS_MIN                             ( 0x80000000UL )
#define RFE_SW_CFG_MNGR_CHIRP_FREQUENCY_DRIFT_STEPS_MAX                             ( 0x7fffffffUL )

/**
 * This macro defines the total number of configuration parameters.
 */
#define RFE_SW_CFG_MNGR_PARAMS                                                      ( 164UL )

/**
 * This macro defines size of the rfeConfig blobs with the min and max values: #rfeConfig_min and #rfeConfig_max
 */
#define RFE_SW_CFG_MNGR_MIN_MAX_BLOB_SIZE                                           ( RFE_CFG_SIZE_SECTION_METADATA + \
                                                                                      RFE_CFG_SIZE_SECTION_GENERAL + \
                                                                                      RFE_CFG_SIZE_SECTION_MONITOR_AND_SAFETY + \
                                                                                      RFE_CFG_SIZE_SECTION_RADAR_CYCLE + \
                                                                                      RFE_CFG_SIZE_SECTION_CHIRP_SEQUENCE + \
                                                                                      RFE_CFG_SIZE_SECTION_CHIRP_PROFILE )
/**
 * This struct contains all information for a single-parameter update.
 */
typedef struct 
{
    uint16_t section;
    uint16_t paramIndex;
    uint32_t value;
} rfeSwCfgMngr_update_t;

/**
 * This structure contains the configuration pointers
 */
typedef struct
{
    const uint8_t *pRfeConfig;
    const uint32_t *pDynamicTables;
} rfeSwCfgMngr_configurationPointers_t;


/**
 * This macro defines a debug test parameter (not defined in rfeDriver) to enable data output via packet processor
 */
#define RFE_SW_CFG_MNGR_DEBUG_TEST_PARAMETER_PACKET_PROCESSOR_DATA_OUT_ADDRESS      ( 100UL )

/**
 * This macro defines a debug test parameter (not defined in rfeDriver) to enable vtune out
 */
#define RFE_SW_CFG_MNGR_DEBUG_TEST_PARAMETER_ENABLE_VTUNE_OUT                       ( 101UL )

/**
 * This macro defines a debug test parameter (not defined in rfeDriver) to bypass a main state
 */
#define RFE_SW_CFG_MNGR_DEBUG_TEST_PARAMETER_BYPASS_MAIN_STATE                      ( 65534UL )

/**
 * This macro defines a debug test parameter (not defined in rfeDriver) to bypass a radar cycle state
 */
#define RFE_SW_CFG_MNGR_DEBUG_TEST_PARAMETER_BYPASS_RADAR_CYCLE_STATE               ( 65535UL )


/******************************************************************************
 *                              FUNCTIONS
 *****************************************************************************/

/**
 * \brief This function start the configuration of the RFE.
 * 
 * \details This function returns the pointer to the memory location where 
 * the RFE Configuration BLOB is stored. The cmd server dispatcher will 
 * call this function, when it receives the first cmd of the rfe_configure() 
 * API function. The dispatcher will copy the configuration blob from the shared 
 * memory to the configuration memory in DTCM. This function will set the 
 * configuration state to #rfeSwCfgMngr_state_unconfigured_e, since configuration is getting 
 * overwritten from this point. Only after validating the new configuration
 * in rfeSwCfgMngr_configureEnd() the state will become #rfeSwCfgMngr_state_configured_e.
 *
 * \pre NIL
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * \return NIL
 *
 * \post 
 * - State becomes #rfeSwCfgMngr_state_unconfigured_e.
 * - Call rfeSwCfgMngr_configureEnd() when configuration memory is filled.
 *
 * \ingroup NIL
 */
uint8_t* rfeSwCfgMngr_configureBegin(rfe_error_t* rfe___error___pointer);

/**
 * \brief This function ends the configuration of the RFE.
 * 
 * \details This function will validate the RFE configuration, copy the dynamic table
 * from system memory to DTCM and validate the dynamic table. When all this succeeds, the
 * state will become #rfeSwCfgMngr_state_configurationPending_e, otherwise an error is returned.
 * The command server dispatcher will call this function after the last cmd of the API
 * rfe_configure() is received, and the configuration is fully copied to the configuration
 * memory in DTCM.
 *
 * \pre 
 * - rfeSwCfgMngr_configureBegin() must be called to retrieve the pointer to configuration memory.
 * - Configuration memory must be filled.
 * 
 * \param [in]      _dynamicTableAddress - Address of the dynamic tables in system memory.
 *                  Set to 0 when dynamic table is not used.
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * \return NIL
 *
 * \post 
 * - State becomes #rfeSwCfgMngr_state_configurationPending_e.
 * - rfeSwCfgMngr_distributeConfiguration() shall be called by MainFSM to distribute the configuration to the units.
 *
 * \ingroup NIL
 */
void rfeSwCfgMngr_configureEnd(rfe_error_t* rfe___error___pointer);

/**
 * \brief This function distributes the configuration to the units.
 * 
 * \details This function is called by MainFSM after rfe_configure() API
 * call was successfull, i.e. state is #rfeSwCfgMngr_state_configurationPending_e.
 *
 * \pre 
 * - State must be #rfeSwCfgMngr_state_configurationPending_e, by calling 
 * rfeSwCfgMngr_configureBegin() and rfeSwCfgMngr_configureEnd() before.
 * 
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * \return rfeSwCfgMngr_configurationPointers_t - Pointers to the RFE configuration
 *
 * \post State becomes #rfeSwCfgMngr_state_configured_e.
 *
 * \ingroup NIL
 */
void rfeSwCfgMngr_distributeConfiguration(rfe_error_t* rfe___error___pointer);

/**
 * \brief This function updates a set of parameters
 *  
 * \details This function will validate a set of parameters to update and. If radar cycle is inactive,
 * it will also applies them (via rfeSwCfgMngr_applyParamUpdates()). This function is called by the cmd server 
 * dispatcher to handle the rfe_updatePush() API function. The RFE has to be configured before.
 * If not successfull an error is returned.
 *
 * \pre 
 * - State must be #rfeSwCfgMngr_state_configured_e
 * 
 * \param [in]      pUpdates - Pointer to an array with the updates.
 * \param [in]      updateCount - Number of parameter updates
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * \return uint16_t - The radar cycle index at which the configuration gets updated.
 *
 * \post NIL
 *
 * \ingroup NIL
 */
uint16_t rfeSwCfgMngr_updatePush(const rfeSwCfgMngr_update_t *pUpdates, uint8_t updateCount,
    rfe_error_t* rfe___error___pointer);

/**
 * \brief This function applies the configuration updates if any updates are pending.
 * 
 * \details This function is called by Main FSM.
 *
 * \pre NIL
 * 
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * \return bool - Returns if any updates were applied.
 *
 * \post NIL
 *
 * \ingroup NIL
 */
bool rfeSwCfgMngr_applyParamUpdates(rfe_error_t* rfe___error___pointer);

/**
 * \brief This function sets a test parameter.
 *
 * \details This function is called by the cmd server 
 * dispatcher to handle the rfe_testSetParam() API function.
 * 
 * \pre NIL
 *
 * \param [in]      testParam - The test parameter to set
 * \param [in]      value - The value to set
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * \return NIL
 *
 * \post NIL
 *
 * \ingroup NIL
 */
void rfeSwCfgMngr_testSetParam(rfe_testParam_t testParam, uint32_t value, rfe_error_t* rfe___error___pointer);

/**
 * \brief This function clears any pending param updates
 *
 * \details This function is called by MainFSM when user radar cycle stop command is given
 * to ensure pending updates are cleared.
 * 
 * 
 * \pre NIL
 *
 * \param [in]      testParam - The test parameter to set
 * \param [in]      value - The value to set
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * \return NIL
 *
 * \post NIL
 *
 * \ingroup NIL
 */
void rfeSwCfgMngr_clearParamUpdates(rfe_error_t* rfe___error___pointer);

/**
 * \brief This function initializes the CfgMngr
 *
 * \details This function is called by rfeSwInit to initialize the CfgMngr
 * 
 * 
 * \pre NIL
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * \return NIL
 *
 * \post NIL
 *
 * \ingroup NIL
 */
void rfeSwCfgMngr_init(rfe_error_t* rfe___error___pointer);

/**
 * \brief This function gets the keepTxTransmissionEnabled test setting
 *
 * \details This function is called by rfeSwMainFsm to enable/disable transmission before/after chirp sequence
 * 
 * 
 * \pre NIL
 *
 * \return bool - Indicates whether keepTxTransmissionEnabled is enabled (true) or disabled (false)
 *
 * \post NIL
 *
 * \ingroup NIL
 */
bool rfeSwCfgMngr_getKeepTxTransmissionEnabled(void);

/**
 * \brief This function returns whether clock retuning is enabled.
 *
 * \details This function is called by rfeSwMainFsm to check whether it should retune the clock periodically.
 * 
 * 
 * \pre NIL
 *
 * \return bool - Indicates whether enableClockRetuning is enabled (true) or disabled (false)
 *
 * \post NIL
 *
 * \ingroup NIL
 */
bool rfeSwCfgMngr_isClockRetuningEnabled(void);

#endif // !RFE_SW_CFG_MNGR_H

