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

#ifndef RFE_TYPES_COMMON_H
#define RFE_TYPES_COMMON_H


/*
* @page misra_violations MISRA-C:2012 violations
*
* @section rfe_types_c_REF_1
* Violates MISRA 2012 Required Rule 5.2
* #Identifiers declared in the same scope and name space shall be distinct.
* Function naming template used.
*
*/


/******************************************************************************
 *                              INCLUDES
 *****************************************************************************/

#include <stdbool.h>
#include <stdint.h>
#include "typedefs.h"
#include "rfe_cfg_blob.h"

#ifdef __cplusplus
extern "C"
{
#endif

/**
*   @addtogroup rsdk_rfe_const
*   @{
*/

/******************************************************************************
 *                              DEFINES
 *****************************************************************************/
/**
 * This macro defines the number of updates that can be buffered
 * by rfe_updateParam() and rfe_updateDynamicTable() and pushed
 * jointly via rfe_updatePush().
 */
#define RFE_UPDATE_COUNT_MAX                            (16UL)

/**
 * This macro defines the number of temperature sensors.
 * #rfe_temperatureSensorIndex_t defines the temperature sensors.
 */
#define RFE_TEMPERATURE_SENSOR_COUNT                    (4UL)

/**
 * This macro defines the TX BIST combinations: TX1-TX2, TX2-TX3 and TX3-TX4
 */
#define RFE_TX_BIST_COMBINATIONS                        (3UL)

/**
 * Monitor select - complete definitions
 */
/** This bit selects the rx stage1 in-phase saturation count of all enabled rx for monitor read-out. */
#define RFE_MONITOR_SELECT_RX_SAT_COUNT_STAGE_1I        ( ( rfe_monitorSelect_t ) 1UL << 0U )
/** This bit selects the pdc clipping count off all enabled pdc for monitor read-out. */
#define RFE_MONITOR_SELECT_PDC_CLIPPING_COUNT           ((rfe_monitorSelect_t)(1UL<<4U))
/** This bit selects the temperature before the chirp sequence of all temp sensors for monitor read-out.            */
#define RFE_MONITOR_SELECT_TEMP_BEFORE_CHIRP_SEQ        ((rfe_monitorSelect_t)(1UL<<5U))
/** This bit selects the temperature after the chirp sequence of all temp sensors for monitor read-out.             */
#define RFE_MONITOR_SELECT_TEMP_AFTER_CHIRP_SEQ         ((rfe_monitorSelect_t)(1UL<<6U))
/** This bit selects the current temperature of all temp sensors for monitor read-out.                              */
#define RFE_MONITOR_SELECT_TEMP_IMMEDIATELY             ((rfe_monitorSelect_t)(1UL<<7U))
/** This bit selects the transmitter power for monitor read-out.                                                    */
#define RFE_MONITOR_SELECT_TX_POWER                     ((rfe_monitorSelect_t)(1UL<<8U))
/** This value selects all monitors.                                                                                */
#define RFE_MONITOR_SELECT_ALL                          ((rfe_monitorSelect_t)0x1FFU)

/** Selects chirp profile as dynamic parameter, will overwrite \ref chirpProfileSequence of the configuration blob. */
#define RFE_DYN_PARAMS_SELECT_CHIRP_PROFILE                 ((rfe_dynParamsSelect_t) (1UL<<0U))
/** Selects Tx1 phase rotation as dynamic parameter, will overwrite \ref txPhaseRotation of the configuration blob. */
#define RFE_DYN_PARAMS_SELECT_TX1_PHASE_ROTATION            ((rfe_dynParamsSelect_t) (1UL<<1U))
/** Selects Tx2 phase rotation as dynamic parameter, will overwrite \ref txPhaseRotation of the configuration blob. */
#define RFE_DYN_PARAMS_SELECT_TX2_PHASE_ROTATION            ((rfe_dynParamsSelect_t) (1UL<<2U))
/** Selects Tx3 phase rotation as dynamic parameter, will overwrite \ref txPhaseRotation of the configuration blob. */
#define RFE_DYN_PARAMS_SELECT_TX3_PHASE_ROTATION            ((rfe_dynParamsSelect_t) (1UL<<3U))
/** Selects Tx4 phase rotation as dynamic parameter, will overwrite \ref txPhaseRotation of the configuration blob. */
#define RFE_DYN_PARAMS_SELECT_TX4_PHASE_ROTATION            ((rfe_dynParamsSelect_t) (1UL<<4U))
/** Selects Tx transmission enable as dynamic parameter, will overwrite \ref txTransmissionEnable of the config blob.*/
#define RFE_DYN_PARAMS_SELECT_TX_TRANSMISSION_ENABLE        ((rfe_dynParamsSelect_t) (1UL<<5U))
/** Selects chirp dwell time as dynamic parameter, will over-write \ref dwellTimeTicks of the configuration blob.   */
#define RFE_DYN_PARAMS_SELECT_DWELL_TIME_TICKS              ((rfe_dynParamsSelect_t) (1UL<<6U))
/** Selects chirp interval time as dynamic parameter, will overwrite \ref chirpIntervalTimeTicks of the config blob.*/
#define RFE_DYN_PARAMS_SELECT_CIT_TICKS                     ((rfe_dynParamsSelect_t) (1UL<<7U))
/** Selects chirp frequency drift as dynamic parameter */
#define RFE_DYN_PARAMS_SELECT_CHIRP_FREQUENCY_DRIFT_STEPS   ((rfe_dynParamsSelect_t) (1UL<<8U))
/** Selects all the above dynamic parameters */
#define RFE_DYN_PARAMS_SELECT_ALL                           ((rfe_dynParamsSelect_t) (0x1FFUL))

/**
 * This macro defines the number of receivers.
 * #rfe_rxIndex_t defines the receiver indices.
 */
#define RFE_RX_COUNT                                    (4UL)

/**
 * This macro defines the rx stages.
 * #rfe_rxStage_t defines the stage indices.
 */
#define RFE_RX_STAGE                                    (2UL)

/**
 * This macro defines the rx cliping reset counter.
 * #rfe_rxClippingReset_t defines the stage indices.
 */
#define RFE_RX_CLIPPING_RESET                           (5UL)

/**
 * This macro defines the tx power error.
 * #rfe_txPowerErrorFlag_t defines the stage indices.
 */
#define RFE_TX_POWER_ERR								(4UL)

/**
 * This macro defines the RX BIST combinations: RX1-RX2, RX1-RX3 and RX1-RX4
 */
#define RFE_RX_BIST_COMBINATIONS                        (3UL)

/**
 * This macro defines the number of nanoseconds that corresponds to a single time tick.
 */
#define RFE_NS_PER_TIME_TICK                            ( 25UL )

/**
 * This macro defines the number of ticks per microsecond.
 */
#define RFE_TIME_TICKS_PER_US                           ( 40UL )
/**
 * This macro defines the maximum number of frontends supported by SOC.
 */



#define RFE_MAX_SUPPORTED_DEVICES		                ( 2U )




/**
 * This type defines a selection of receivers.
 *   @}
 *   @addtogroup rsdk_rfe_interface
 *   @{
*/
typedef uint8_t rfe_rxSelect_t;
/**
 *   @}
*   @addtogroup rsdk_rfe_const
*   @{
*/
/** This value selects no receivers. */
#define RFE_RX_SELECT_NONE                              ( ( rfe_rxSelect_t ) 0x0UL )
/** This bit selects receiver 1. */
#define RFE_RX_SELECT_1                                 ( ( rfe_rxSelect_t ) ( 1UL<<0U ) )
/** This bit selects receiver 2. */
#define RFE_RX_SELECT_2                                 ( ( rfe_rxSelect_t ) ( 1UL<<1U ) )
/** This bit selects receiver 3. */
#define RFE_RX_SELECT_3                                 ( ( rfe_rxSelect_t ) ( 1UL<<2U ) )
/** This bit selects receiver 4. */
#define RFE_RX_SELECT_4                                 ( ( rfe_rxSelect_t ) ( 1UL<<3U ) )
/** This value selects all 4 receivers. */
#define RFE_RX_SELECT_ALL                               ( ( rfe_rxSelect_t ) 0xFUL )
/** This value selects no transmitters. */
#define RFE_TX_SELECT_NONE                              ( ( rfe_txSelect_t ) 0x0UL )
/** This bit selects transmitter 1. */
#define RFE_TX_SELECT_1                                 ( ( rfe_txSelect_t ) ( 1UL<<0 ) )
/** This bit selects transmitter 2. */
#define RFE_TX_SELECT_2                                 ( ( rfe_txSelect_t ) ( 1UL<<1 ) )
/** This bit selects transmitter 3. */
#define RFE_TX_SELECT_3                                 ( ( rfe_txSelect_t ) ( 1UL<<2 ) )
/** This bit selects transmitter 4. */
#define RFE_TX_SELECT_4                                 ( ( rfe_txSelect_t ) ( 1UL<<3 ) )
/** This value selects all 4 transmitters. */
#define RFE_TX_SELECT_ALL                               ( ( rfe_txSelect_t ) 0xFUL )
/** This bit enables data output to packet processor. */
#define RFE_DATA_OUT_DEST_PACKET_PROCESSOR              ((rfe_dataOutDest_t)(1UL<<0u))
/** This bit enables data output over CSI2. */
#define RFE_DATA_OUT_DEST_CSI2                          ((rfe_dataOutDest_t)(1UL<<1u))
/** Thus value define the maximum number of API interrupt requests  */
#define RFE_API_IRQ_MAX_NUM                             (19UL)

/**
*   @}
*   @addtogroup rsdk_rfe_interface
*   @{
*/

/**
 * These defines cover a selection of dynamic parameters.
 */
typedef uint16_t rfe_dynParamsSelect_t;

/**
 * This type defines a selection of transmitters.
 */
typedef uint8_t rfe_txSelect_t;

/**
 * This type defines the data out destinations of the packer.
 */
typedef uint8_t rfe_dataOutDest_t;

/******************************************************************************
 *                              TYPES
 *****************************************************************************/
/**
 * This enumerated type defines the RFE power modes.
 */
typedef enum
{
    /** Disable RFE chirp power mode. */
    rfe_powerMode_inactive_e,
    /** Puts RFE in active chirp power mode. */
    rfe_powerMode_active_e
} rfe_powerMode_t;

/**
 * This enumerated type defines the BIST interval.
 */
typedef enum
{
    /** Perform BIST after the last chirp sequence in every radar cycle. */
    rfe_bistInterval_everyRadarCycle_e = 0U,
    /** Perform BIST after the last chirp sequence once in two radar cycles. */
    rfe_bistInterval_onceIn2RadarCycles_e = 1U,
    /** Perform BIST after the last chirp sequence once in four radar cycles. */
    rfe_bistInterval_onceIn4RadarCycles_e = 2U,
    /** Do not perform BIST in radar Cycle. */
    rfe_bistInterval_none_e = 3U
} rfe_bistInterval_t;

/**
 * \brief Structure to hold the RX BIST test modes.
 */
typedef enum 
{
    TEF82XX_both_lna_mixer = 0,  // Lna and mixer for each frame.
    TEF82XX_only_mixer,          // only mixer 
    TEF82XX_alternate_lna_mixer,  // Use alternate lna and mixer. Lna for current frame and Mixer for subsequent frame
	InjectToneMode_Invalid
} rfeSwBist_InjectToneMode_t;

/**
 * This enumerated type defines the temperature sensors.
 */
typedef enum
{
    /** The temperature sensor located near transmitter 1.                                                    */
    rfe_temperatureSensorIndex_tx1_e,
    /** The temperature sensor located near transmitter 2.                                                    */
    rfe_temperatureSensorIndex_tx2_e,
    /** The temperature sensor located near transmitter 3.                                                    */
    rfe_temperatureSensorIndex_tx3_e,
    /** The temperature sensor located near the chirp module.                                                 */
    rfe_temperatureSensorIndex_chirp_e
} rfe_temperatureSensorIndex_t;

/**
 * This type defines temperature as SQ6 in degrees Celsius.
 * SQ6 is a signed (2's complement) fixed point number format
 * with 6 fractional bits. E.g. 1 degrees Celsius = 0x0040.
 */
typedef int16_t rfe_temperature_t;


/**
 * This enumerated type defines the chirp profile indices.
 */
typedef enum
{
    rfe_chirpProfileIndex_0_e,
    rfe_chirpProfileIndex_1_e,
    rfe_chirpProfileIndex_2_e,
    rfe_chirpProfileIndex_3_e,
    rfe_chirpProfileIndex_4_e,
    rfe_chirpProfileIndex_5_e,
    rfe_chirpProfileIndex_6_e,
    rfe_chirpProfileIndex_7_e,
	rfe_chirpProfileIndex_invalid_e
} rfe_chirpProfileIndex_t;

/**
 * This enumerated type defines indices for the FuSa fault mask configuration array.
 */
typedef enum
{
    rfe_fuSaFaultMaskIndex_0_e,
    rfe_fuSaFaultMaskIndex_1_e,
    rfe_fuSaFaultMaskIndex_2_e,
    rfe_fuSaFaultMaskIndex_3_e,
    rfe_fuSaFaultMaskIndex_4_e,
    rfe_fuSaFaultMaskIndex_5_e,
    rfe_fuSaFaultMaskIndex_6_e,
    rfe_fuSaFaultMaskIndex_7_e,
    rfe_fuSaFaultMaskIndex_8_e,
    rfe_fuSaFaultMaskIndex_9_e,
    rfe_fuSaFaultMaskIndex_10_e,
    rfe_fuSaFaultMaskIndex_11_e
} rfe_fuSaFaultMaskIndex_t;

/**
 * This enumerated type defines the indices of the transmitters.
 */
typedef enum
{
    rfe_txIndex_1_e,
    rfe_txIndex_2_e,
    rfe_txIndex_3_e,
    rfe_txIndex_4_e,
	rfe_txIndex_invalid_e
} rfe_txIndex_t;

/**
 * This enumerated type defines the phase rotator final pc gen mode.
 */
typedef enum
{
    ///  No change to initial phase code
    rfe_PR_NO_CHANGE_e = 0x00u,
    ///  Replace two MSB bits of initial phase code with the QPSK[1:0] bits
	rfe_PR_REPLACE_MSB_WITH_QPSK = 0x01u,
    ///  Add the QPSK[1:0] bits to two MSB bits of initial phase code
	rfe_PR_ADD_QPSK_TO_MSB = 0x02u,
	rfe_PR_INVALID
} rfe_PRPCGenMode_e;

/**
 * This enumerated type defines the indices of the receivers.
 */
typedef enum
{
    rfe_rxIndex_1_e,
    rfe_rxIndex_2_e,
    rfe_rxIndex_3_e,
    rfe_rxIndex_4_e
} rfe_rxIndex_t;

/**
 * This enumerated type defines the rx stages.
 */
typedef enum
{
    rfe_rxStage_1_e,
    rfe_rxStage_2_e
} rfe_rxStage_t;

/**
 * This enumerated type defines the rx saturation threshold.
 */
typedef enum
{
     rfe_rxSaturationThreshold_min13_05dB_e,
     rfe_rxSaturationThreshold_min12_18dB_e,
     rfe_rxSaturationThreshold_min11_31dB_e,
     rfe_rxSaturationThreshold_min10_44dB_e,
     rfe_rxSaturationThreshold_min9_57dB_e,
     rfe_rxSaturationThreshold_min8_70dB_e,
     rfe_rxSaturationThreshold_min7_83dB_e,
     rfe_rxSaturationThreshold_min6_96dB_e,
     rfe_rxSaturationThreshold_min6_09dB_e,
     rfe_rxSaturationThreshold_min5_22dB_e,
     rfe_rxSaturationThreshold_min4_35dB_e,
     rfe_rxSaturationThreshold_min3_48dB_e,
     rfe_rxSaturationThreshold_min2_61dB_e,
     rfe_rxSaturationThreshold_min1_74dB_e,
     rfe_rxSaturationThreshold_min0_87dB_e,
     rfe_rxSaturationThreshold_0dB_e
 } rfe_rxSaturationThreshold_t;

/**
* This enumerated type defines the rx cliping reset counter.
*/
 typedef enum
 {
	rfe_rx1Reset_e,
	rfe_rx2Reset_e,
	rfe_rx3Reset_e,
	rfe_rx4Reset_e,
	rfe_rx1234Reset_e
 }rfe_rxClippingReset_t;

 typedef enum
 {
	 rfe_txPowerMinErrorFlag,
	 rfe_txPowerLowErrorFlag,
	 rfe_txPowerHighErrorFlag,
	 rfe_txPowerMaxErrorFlag,
 }rfe_txPowerErrorFlag_t;

/**
 * This enumerated type defines the receiver gains.
 */
typedef enum
{
    rfe_rxGain_25dB_e,
    rfe_rxGain_28dB_e,
    rfe_rxGain_31dB_e,
    rfe_rxGain_34dB_e,
    rfe_rxGain_37dB_e,
    rfe_rxGain_40dB_e,
    rfe_rxGain_43dB_e,
    rfe_rxGain_46dB_e,
	rfe_rxGain_invalid_e
} rfe_rxGain_t;

/**
 * This enumerated type defines the receiver high-pass filter cut-off frequencies.
 */
typedef enum
{
    rfe_rxHpfCutOffFrequency_200kHz_e,
    rfe_rxHpfCutOffFrequency_300kHz_e,
    rfe_rxHpfCutOffFrequency_400kHz_e,
    rfe_rxHpfCutOffFrequency_800kHz_e,
    rfe_rxHpfCutOffFrequency_1600kHz_e,
    rfe_rxHpfCutOffFrequency_3200kHz_e,
    rfe_rxHpfCutOffFrequency_6400kHz_e,
	rfe_rxHpfCutOffFrequency_invalid_e
} rfe_rxHpfCutOffFrequency_t;

/**
 * This enumerated type defines the receiver low-pass filter cut-off frequencies.
 */
typedef enum
{
    rfe_rxLpfCutOffFrequency_12P5MHz_e,
    rfe_rxLpfCutOffFrequency_15MHz_e,
    rfe_rxLpfCutOffFrequency_20MHz_e,
    rfe_rxLpfCutOffFrequency_25MHz_e,
    rfe_rxLpfCutOffFrequency_40MHz_e,
	rfe_rxLpfCutOffFrequency_invalid_e
} rfe_rxLpfCutOffFrequency_t;

/**
 * This enumerated type defines slope directions of a chirp.
 */
typedef enum
{
    rfe_chirpSlopeDirection_falling_e,
    rfe_chirpSlopeDirection_rising_e
} rfe_chirpSlopeDirection_t;

/**
 * This enumerated type defines chirp PLL voltage-controlled oscillators.
 */
typedef enum
{
    rfe_chirpPllVco_1GHz_e,
	rfe_chirpPllVco_2GHz_e,
    rfe_chirpPllVco_4GHz_e
} rfe_chirpPllVco_t;

/**
 * This enumerated type defines the virtual channels.
 */
typedef enum
{
    rfe_virtualChannel_0_e,
    rfe_virtualChannel_1_e,
    rfe_virtualChannel_2_e,
    rfe_virtualChannel_3_e,
	rfe_virtualChannel_invalid_e
} rfe_virtualChannel_t;


/**
 * This type defines an address to system memory.
 */
typedef uint8_t *rfe_sysMemAddress_t;

/**
 * This structure contains the radar cycle and chirp sequence count.
 * It can be retrieved via rfe_getRadarCycleCount().
 */
typedef struct
{
    /** Number of radar cycles that have been completed since rfe_radarCycleStart().                                */
    uint16_t radarCycleCount;
    /** Number of chirp sequences that have been completed since rfe_radarCycleStart().                             */
    uint16_t chirpSequenceCount;
} rfe_radarCycleCount_t;

/**
* @brief        RF BIST Test Type
* @details      Select TEF82XX_RFBIST_MIXER_TEST to inject the RFBIST signal at the mixer input. Alternatively, use
* 				TEF82XX_RFBIST_LNA_TEST to inject the RFBIST signal at the LNA input.
*/
typedef enum 
{
	TEF82XX_RFBIST_MIXER_TEST = 0U,
	TEF82XX_RFBIST_LNA_TEST,
	TEF82XX_RFBIST_TESTS
} rfeTef82XXRfBistTest_t;

/**
 * This type defines the RFE-Fw states.
 * RFE-Fw state can be retrieved via rfe_getState().
 */
typedef enum
{
    /** RFE-Fw is busy and not accepting any commands.                                                                 */
    rfe_state_busy_e,
    /** RFE-Fw is initialized and ready to be configured via rfe_configure().                                          */
    rfe_state_initialized_e,
    /** RFE-Fw is configured and ready to take any command, such as rfe_radarCycleStart().                             */
    rfe_state_configured_e,
    /** 
     * RFE-Fw is in the idle period of the radar cycle and accepting limited commands, such as:
     * * rfe_updatePush()
     * * rfe_radarCycleStop()
     * * rfe_getNextRadarCycleStartTime()
     * * rfe_setNextRadarCycleStartTime()
     * * rfe_getTime()
     * * rfe_monitorRead()
     */
    rfe_state_radarCycleIdle_e,
    /** 
     * RFE-Fw is transmitting a continuous wave signal. and accepting limited commands, such as:
     * * rfe_testContinuousWaveTransmissionStop()
     * * rfe_getTime()
     * * rfe_monitorRead()
     */
    rfe_state_testContinuousWaveTransmission_e,
    /** A FuSa fault has occurred in the RFE-Fw, RFE-Fw is busy.
     * RFE-Fw parses the fault and attempts fault recovery for R1 faults. */
    rfe_state_fuSaFaultRecovery_e,
    /** A FuSa fault has occurred in the RFE, call rfe_getFuSaFaults() to retrieve the FuSa fault.                  */
    rfe_state_fuSaFault_e
} rfe_state_t;

/**
 * This structure is a container for all RFE-Fw monitors to be read via rfe_monitorRead().
 */
typedef struct
{
	/** The clipping count of each rx saturation.                                                   */
	uint32_t rxSaturationClippingCount[RFE_RX_COUNT * RFE_MAX_SUPPORTED_DEVICES];
    /** The clipping count of each programmable decimation chain.                                                   */
	uint32_t pdcClippingCount[RFE_RX_COUNT * RFE_MAX_SUPPORTED_DEVICES];
    /** The temperature measured before the chirp sequence for each temperature sensor in SQ6 format.                             */
    rfe_temperature_t temperature_beforeChirpSequence[RFE_TEMPERATURE_SENSOR_COUNT * RFE_MAX_SUPPORTED_DEVICES];
    /** The temperature measured after the chirp sequence for each temperature sensor in SQ6 format.                              */
    rfe_temperature_t temperature_afterChirpSequence[RFE_TEMPERATURE_SENSOR_COUNT * RFE_MAX_SUPPORTED_DEVICES];
    /** The temperature measured at the time rfe_monitorRead() is executed in SQ6 format.                                         */
    rfe_temperature_t temperature_immediately[RFE_TEMPERATURE_SENSOR_COUNT * RFE_MAX_SUPPORTED_DEVICES];
    /** The measured output power in 0.1 [dBm] for each transmitter and profile.
     * -100 means given profile for given TX is not calibrated.
     * -128 means that the front end cannot measure the output power                                                    */
    int16_t txPower[RFE_CHIRP_PROFILES_MAX][RFE_TX_COUNT * RFE_MAX_SUPPORTED_DEVICES];

} rfe_monitorValues_t;

/**
 * This types defines a selection of RFE-Fw monitors.
 */
typedef uint16_t rfe_monitorSelect_t;

/**
 * This enumerated type defines the RFE-Fw test parameters.
 * Used by rfe_testSetParam().
 */
typedef enum
{
    /**
     * This test is not implemented yet.
     */
    rfe_testParam_outputDataTestPattern_e,
    /**
     * This test is not implemented yet.
     */
    rfe_testParam_keepTxTransmissionEnabled_e,
    /** 
     * This test is not implemented yet.
     */
    rfe_testParam_chirpPllTestPinEnable_e,
    /** 
     * This test is not implemented yet.
     */
    rfe_testParam_enableClockRetuning_e
} rfe_testParam_t;

/**
 * This structure contains the version and variant details of the RFE-Fw:
 * - Hardware and firmware variants
 * - Hardware and firmware versions
 */
typedef struct
{
     /** 
     * Defines the IC type
     *     SAF85xx: 100
     *     S32R41:  200 
     */
    uint32_t hwType;
    /** 
     * Defines the commercial IC variant
     *     xx : 0 (no variant defined, evaluation sample)
     */
    uint32_t hwVariant;
    /** 
    * Defines the IC version
    *     ES1          : 1 
    *     ES1.1 (A1MF) : 2 
    */
    uint32_t hwVersion;
    /** 
    * Defines 32-bit Unique ID of RFE device connected
    * effectively CRC32 of BC OTP ChipInfo structure of Leader Device
    */
    uint32_t hwUniqueId;

    /**
     * Defines the firmware variant
     *     1: E2 T0  trim, evaluation sample
     *     2: E2 OTP trim, evaluation sample
     *     3: E2, E5 OTP trim, evaluation sample
     *     4: A1-E5-T2MF
     */
    uint32_t fwVariant;
    /**
     * Defines whether the firmware has been officially released.
     * In case of an un official release, major, minor and patch indicate the latest
     * officially released version which is the basis for the firmware. The firmware hash
     * can be used to identify the firmware in that case. 
     */
    bool fwVersionReleased;
    /** Defines the major firmware version.                                                                         */
    uint8_t fwVersionMajor;
    /** Defines the minor firmware version.                                                                         */
    uint8_t fwVersionMinor;
    /** Defines the patch firmware version.                                                                         */
    uint8_t fwVersionPatch;
    /** Defines the firmware hash for identifying unreleased versions.                                              */
    uint32_t fwHash;
} rfe_version_t;


/**
 * This enumerated type defines which core will receive IRQs from RFE firmware
 * \note Core Id 0: appM7 core
 *       Core Id 1: a53 core
 */
typedef enum rfe_coreId_et
{
    rfe_coreId_none_e = 0U,
    rfe_coreId_appM7_e,
    rfe_coreId_a53_e,
    rfe_coreId_max
}rfe_coreId_t;


/**
 * This type defines which events shall trigger an IRQ from RFE firmware
 */
typedef enum{
    RFE_EVENTS_IRQ_NONE                     = 0U,           /** Using only this bitmask, all events IRQs are disabled   */
    RFE_EVENTS_IRQ_STATE_CHANGE             = (1U << 0U),   /** This bit enables IRQ on state change                    */
    RFE_EVENTS_IRQ_RADAR_CYCLE_CHANGE       = (1U << 1U),   /** This bit enables IRQ on radar cycle change              */
    RFE_EVENTS_IRQ_CHIRP_SEQUENCE_CHANGE    = (1U << 2U),   /** This bit enables IRQ on chirp sequence change           */
    RFE_EVENTS_IRQ_MAX                      = (1U << 3U)    /** This bitmask define the IRQ events limit                */
}rfe_eventsIRQ_t;


/**
 * This type defines which RFE APIs shall trigger an IRQ from RFE firmware upon completion
 */
typedef enum {
    RFE_API_IRQ_NONE                                = 0UL,              /** This bitmask disables all commands completion IRQs                      */
    RFE_API_IRQ_CONFIGURE                           = (1UL << 0UL),     /** This bit enables IRQ on rfe_configure completion                        */
    RFE_API_IRQ_RADAR_CYCLE_START                   = (1UL << 1UL),     /** This bit enables IRQ on rfe_radarCycleStart completion                  */
    RFE_API_IRQ_RADAR_CYCLE_STOP                    = (1UL << 2UL),     /** This bit enables IRQ on rfe_radarCycleStop completion                   */
    RFE_API_IRQ_GET_FUSA_FAULTS                     = (1UL << 3UL),     /** This bit enables IRQ on rfe_getFuSaFaults completion                    */
    RFE_API_IRQ_GET_TIME                            = (1UL << 4UL),     /** This bit enables IRQ on rfe_getTime completion                          */
    RFE_API_IRQ_GET_VERSION                         = (1UL << 5UL),     /** This bit enables IRQ on rfe_getVersion completion                       */
    RFE_API_IRQ_MONITOR_READ                        = (1UL << 6UL),     /** This bit enables IRQ on rfe_monitorRead completion                      */
    RFE_API_IRQ_GET_NEXT_RADAR_CYCLE_START_TIME     = (1UL << 7UL),     /** This bit enables IRQ on rfe_getNextRadarCycleStartTime completion       */
    RFE_API_IRQ_SET_NEXT_RADAR_CYCLE_START_TIME     = (1UL << 8UL),     /** This bit enables IRQ on rfe_setNextRadarCycleStartTime completion       */
    RFE_API_IRQ_UPDATE_PUSH                         = (1UL << 9UL),     /** This bit enables IRQ on rfe_updatePush completion                       */
    RFE_API_IRQ_CONTINUOUS_WAVE_TRANSMISSION_START  = (1UL << 10UL),    /** This bit enables IRQ on rfe_continuousWaveTransmissionStart completion  */
    RFE_API_IRQ_CONTINUOUS_WAVE_TRANSMISSION_STOP   = (1UL << 11UL),    /** This bit enables IRQ on rfe_continuousWaveTransmissionStop completion   */
    RFE_API_IRQ_TEST_SET_PARAM                      = (1UL << 12UL),    /** This bit enables IRQ on rfe_testSetParam completion                     */
    RFE_API_IRQ_GET_FUSA_FAULT_STATISTICS           = (1UL << 13UL),    /** This bit enables IRQ on rfe_getFuSaFaultStatistics completion           */
    RFE_API_IRQ_GET_BIST_ZERO_HOUR_REFERENCE_DATA   = (1UL << 14UL),    /** This bit enables IRQ on rfe_getBistZeroHourReferenceData completion     */
    RFE_API_IRQ_TEST_GET_INTERNAL_ERROR             = (1UL << 15UL),    /** This bit enables IRQ on rfe_testGetInternalError completion             */
    RFE_API_IRQ_SET_FE_ID                           = (1UL << 16UL),    /** This bit enables IRQ on rfe_setFrontEnd completion                      */
    RFE_API_IRQ_GET_FE_ID                           = (1UL << 17UL),    /** This bit enables IRQ on rfe_getFrontEnd completion                      */
    RFE_API_IRQ_REG_DUMP                            = (1UL << 18UL),    /** This bit enables IRQ on rfe_registerDump completion                     */
    RFE_API_IRQ_MAX                                 = (1UL << RFE_API_IRQ_MAX_NUM)     /** This bit defines the IRQ mask limit                                     */
}rfe_apiIRQ_t;


/**
*   @}
*   @addtogroup rsdk_rfe_const
*   @{
*/
/** This macro defines 1 degree celsius. */
#define RFE_TEMPERATURE_1_DEG_CELSIUS                   ((rfe_temperature_t)(1UL<<6U))

/** This macro converts kelvin to celsius */
#define RFE_KELVIN_TO_CELSIUS(celsius)                    ((celsius) - 273.0f)

/** This bitmask enable all events IRQs */
#define RFE_EVENTS_IRQ_ALL  ((uint8_t)RFE_EVENTS_IRQ_STATE_CHANGE | (uint8_t)RFE_EVENTS_IRQ_RADAR_CYCLE_CHANGE | (uint8_t)RFE_EVENTS_IRQ_CHIRP_SEQUENCE_CHANGE)


/** This bit enables IRQ on all Rfe APIs completion */
#define RFE_API_IRQ_ALL \
        ( (uint32_t)RFE_API_IRQ_CONFIGURE | (uint32_t)RFE_API_IRQ_RADAR_CYCLE_START | (uint32_t)RFE_API_IRQ_RADAR_CYCLE_STOP | \
          (uint32_t)RFE_API_IRQ_GET_FUSA_FAULTS | (uint32_t)RFE_API_IRQ_GET_TIME | (uint32_t)RFE_API_IRQ_GET_VERSION | (uint32_t)RFE_API_IRQ_MONITOR_READ | \
          (uint32_t)RFE_API_IRQ_GET_NEXT_RADAR_CYCLE_START_TIME | (uint32_t)RFE_API_IRQ_SET_NEXT_RADAR_CYCLE_START_TIME | (uint32_t)RFE_API_IRQ_UPDATE_PUSH | \
          (uint32_t)RFE_API_IRQ_CONTINUOUS_WAVE_TRANSMISSION_START | (uint32_t)RFE_API_IRQ_CONTINUOUS_WAVE_TRANSMISSION_STOP | (uint32_t)RFE_API_IRQ_TEST_SET_PARAM | \
          (uint32_t)RFE_API_IRQ_GET_FUSA_FAULT_STATISTICS | (uint32_t)RFE_API_IRQ_GET_BIST_ZERO_HOUR_REFERENCE_DATA | (uint32_t)RFE_API_IRQ_TEST_GET_INTERNAL_ERROR | \
          (uint32_t)RFE_API_IRQ_SET_FE_ID | (uint32_t)RFE_API_IRQ_GET_FE_ID | (uint32_t)RFE_API_IRQ_REG_DUMP )

/**
*   @}
*   @addtogroup rsdk_rfe_api_interface
*   @{
*/
/**
 * This enumeration must be used to define the Front-End usage.
 * It must be used only for 'cascaded' setup, for 'stand-alone' Front-End it is meaningless.
 */
typedef enum {
    CDD_RFE_FRONT_END_LEADER,
    CDD_RFE_FRONT_END_FOLLOWER_0,
    CDD_RFE_FRONT_END_FOLLOWER_1,
    CDD_RFE_FRONT_END_FOLLOWER_2,
    CDD_RFE_FRONT_END_FOLLOWER_MAX,
}CDD_RfeFrontEndHierarchyType;


/**
 * This enumeration must be used to define the Front-End usage if the Front-End is defined as mask and not as enum.
 * It must be used only for 'cascaded' setup, for 'stand-alone' Front-End it is meaningless.
 * This approach is allowing to define more than one Front-End using a single value (as a sum of masks).
 */
typedef enum {
    CDD_RFE_FRONT_END_MASK_LEADER       = 0x01,
    CDD_RFE_FRONT_END_MASK_FOLLOWER_0   = 0x02,
    CDD_RFE_FRONT_END_MASK_FOLLOWER_1   = 0x04,
    CDD_RFE_FRONT_END_MASK_FOLLOWER_2   = 0x08,
}CDD_RfeFrontEndIdMaskType;


/**
*   @}
*   @addtogroup rsdk_rfe_interface
*   @{
*/
/**
 * This type defines RFE API wait for interrupt function pointer.
 */
typedef void (*rfe_apiWaitForInterrupt_f)(void);


/** @} */

#ifdef __cplusplus
}
#endif


#endif // !RFE_TYPES_H

