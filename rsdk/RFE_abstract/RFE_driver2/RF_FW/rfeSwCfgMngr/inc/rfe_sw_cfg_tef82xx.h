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

#ifndef RFE_SW_CFG_TEF82XX_H_
#define RFE_SW_CFG_TEF82XX_H_

/*==================================================================================================
 *                                          INCLUDES
 ==================================================================================================*/
#include <stdbool.h>

#include "rfe_types.h"
#include "rfeSwInit.h"
#include "rfe_error.h"
#include "rfe_cfg_blob.h"
#include "bc_types.h"

/*==================================================================================================
 *                          TYPEDEFS (UNIONS, ENUMS)
==================================================================================================*/
typedef enum {
    e_NO_DPM_ACTIVE=0,
    e_DPM_FOR_CHIRP_CALIBRATION,
    e_DPM_FOR_LO_CALIBRATION,
    e_DPM_ACTIVE
} powerMode_t;
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define NS_TO_US 					(1e-3f)
#define TICK_TO_US					(25.0f * (NS_TO_US))
#define MHZ_TO_HZ 					(1e6f)
#define KHZ_TO_HZ 					(1e3f)
#define STEP_TO_HZ                  (42.9153f)
#define BLOB_PHASE_TO_PHASE_DEGREE	5.625f
#define TENTHS_OF_DB_TO_DB 			10.0f
#define ENABLED 					1U
#define DISABLED 					0U

#define USE_PROFILE_LIST			0x1F
#define PROFILE_GREAT_ONE_OFFSET	7U
#define DELTA_FLOAT					0.0001f		//use in equal float compare
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
// TXISOLATION CONSTANTS

#define TEF82XX_P_ON_DELAY                          150000U // 150 [us]
#define TEF82XX_CAFC_VCO_SELECT                     0U		// 1GHZ VCO
#define TEF82XX_SUBBAND                             2u
#define TEF82XX_IVCOFINE                            4u
#define TEF82XX_PRSEED                              0x0u

// Default values

#define TEF82XX_DEFAULT_SEQ_INTERVAL				1000U   			// This value keeps the timer expired, won't time out???
#define TEF82XX_DEFAULT_P_ON_DELAY					TEF82XX_P_ON_DELAY
#define TEF82XX_DEFAULT_ISM_DELAY					50000U  			// 50 [us]
#define TEF82XX_DEFAULT_USE_EXT_TRIG				0U 					// SPI TRIGGER
#define TEF82XX_DEFAULT_PROF_RESET					1U 					// Reset the profile counter every new frame
#define TEF82XX_DEFAULT_PROF_MODE_SEL				0U 					// Profile 0
#define TEF82XX_DEFAULT_PROF_LIST					0U 	    			// No profile list
#define TEF82XX_DEFAULT_PROF_STAY_CNT				1U 					// No profile repeat in sequence
#define TEF82XX_DEFAULT_GRUP_FINE_DELAY_CTRL_1		0U   				// 0 [ns]
#define TEF82XX_DEFAULT_NUM_SEQ_IN_BURST			1U		// 1 chirp sequence in a burst with a chirp start trigger
#define TEF82XX_DEFAULT_SAFETY_MON_ACT_CTRL			0U 		// Disabled
#define TEF82XX_DEFAULT_PR_ENABLE					0U  	// Disabled
#define TEF82XX_DEFAULT_PR_DDMA_MODE				RFE_PR_DDMA_DISABLED
#define TEF82XX_DEFAULT_PR_BPSK_SOURCE				1U		// Profile setting, not QPSK pin
#define TEF82XX_DEFAULT_PR_QPSK_SOURCE				0U		// QPSK pin, not profile setting
#define TEF82XX_DEFAULT_PR_DDMA_INIT_PHASE			0.0f	// 0 deg
#define TEF82XX_DEFAULT_PR_DDMA_PHASE_UPDATE		0.0f	// 0 deg
#define TEF82XX_DEFAULT_PR_PC_GEN_MODE				RFE_PR_PCGEN_NO_CHANGE
#define TEF82XX_DEFAULT_PR_USE_DDMA					0U		// Don't use DDMA
#define TEF82XX_DEFAULT_PR_SAFETY_CHECK_TIMEOUT		405    // 405 [us]
#define TEF82XX_DEFAULT_EN_PR_SAFETY_CHECK			0U  	// Disabled
#define TEF82XX_DEFAULT_PR_SAFETY_START_DELAY		1000U	// 1000 [ns]
// BPSK/QPSK Sampling
#define TEF82XX_DEFAULT_PR_BPSK_ASYNC_SAMPLING		1U  	// Asynchronous Sampling
#define TEF82XX_DEFAULT_PR_QPSK_ASYNC_SAMPLING		1U  	// Asynchronous Sampling
#define TEF82XX_DEFAULT_PR_BPSK_SYNC_SAMPLING		0U  	// Synchronous Sampling
#define TEF82XX_DEFAULT_PR_QPSK_SYNC_SAMPLING		0U  	// Synchronous Sampling 
#define TEF82XX_DEFAULT_PR_BPSK_SAMPLING			TEF82XX_DEFAULT_PR_BPSK_SYNC_SAMPLING
#define TEF82XX_DEFAULT_PR_QPSK_SAMPLING			TEF82XX_DEFAULT_PR_QPSK_SYNC_SAMPLING

#define TEF82XX_DEFAULT_FAST_DISCHARGE_GS_ENABLE	1U		// Enabled
#define TEF82XX_DEFAULT_FAST_DISCHARGE_CURR_INJ_ENABLE	1U	// Enabled
#define TEF82XX_DEFAULT_CAFC_LOOP_FLT_LUT_IDX_SEL 	2U
#define TEF82XX_DEFAULT_CAFC_PLL_PROF_SEL 			0x00u   // e_CAFC_PLLLPF_CFG0
#define TEF82XX_DEFAULT_CAFC_LOOP_FLT_LUT_SEL 		0x00    // e_CAFC_LPF_LUT_1G
#define TEF82XX_DEFAULT_CAFC_LOOP_BANDWIDTH         300e3f  // max bandwidth for 1G PLL
#define TEF82XX_DEFAULT_RX_LPF  					RFE_RX_LPF_CUTOFF_20MHZ //e_SYS_RXLPF_20MHZ
#define TEF82XX_DEFAULT_RX_HPF  					RFE_RX_HPF_CUTOFF_300KHZ //e_SYS_RXHPF_300KHZ
#define TEF82XX_DEFAULT_RX_GAIN 					0x06u   //e_RX_GAIN_42DB
#define TEF82XX_DEFAULT_TX_PHASE					0.0f
#define TEF82XX_DEFAULT_TX_BPS						0U 		// Disabled
#define TEF82XX_DEFAULT_CAFC_STATIC_ENABLE_CP 		1U
#define TEF82XX_DEFAULT_CAFC_STATIC_ENABLE_VCO_LDO 	1U
#define TEF82XX_DEFAULT_CAFC_STATIC_ENABLE_DIV_LDO 	1U
#define TEF82XX_DEFAULT_CAFC_STATIC_ENABLE_CPPFD_LDO 1U
#define TEF82XX_DEFAULT_CAFC_STATIC_ENABLE_ALL_BIAS 1U
#define TEF82XX_DEFAULT_CAFC_VCO_SELECT				TEF82XX_CAFC_VCO_SELECT // 5GHz VCO, working in 4GHz bandwidth mode

/* iVcoFine and Subband default values are chosen such that BC_CAFC_ConfigVCOProfile
 * does not over-write these parameters. They are selected automatically (through calibration)
 * when calling BC_CAFC_CalibAAFCInjDAC */
#define TEF82XX_SKIP_CAFC_IVCO_FINE				65U
#define TEF82XX_SKIP_CAFC_SUBBAND				129U

#define	TEF82XX_DEFAULT_DYN_PDOWN_DLY_PER_CHIRP 	5.0f
#define	TEF82XX_DEFAULT_DYN_PDOWN_DLY_PER_SEQ   	10.0f
#define	TEF82XX_DEFAULT_MCU_INT_POLARITY 			1U
#define	TEF82XX_DEFAULT_MCU_INT_TRG_MODE 			1U
#define	TEF82XX_DEFAULT_MCU_INT_PERIOD   			144U
#define	TEF82XX_DEFAULT_INT_EVENT_END_OF_DATA_TNFR 	1U
#define	TEF82XX_DEFAULT_INT_EVENT_CHIRP_IN         	1U
#define	TEF82XX_DEFAULT_FORCE_VTUNE_START_VOLTAGE 	0x67U
#define	TEF82XX_DEFAULT_FORCE_VTUNE_CENTER_VOLTAGE 	0x40U
#define TEF82XX_DEFAULT_PDCBWWIDE					1U
#define TEF82XX_DEFAULT_TX_POWER_OUTPUT_CALIBRATION_DELTA 0.5f //dBm
#define TEF82XX_DEFAULT_VIRTUAL_CHANNEL_NO			0U // Virtual channel 0
#define TEF82XX_DISABLED_TX							-1.0f

#define TEF82XX_DEFAULT_OUTPUT_CLK_SKEW_CODE_MASTER 8U
#define TEF82XX_DEFAULT_REF_CLK_DELAY_CODE_MASTER   7U
#define TEF82XX_DEFAULT_OUTPUT_CLK_SKEW_CODE_SLAVE	6U
#define TEF82XX_DEFAULT_REF_CLK_DELAY_CODE_SLAVE	6U

#define TEF82XX_DEFAULT_AUTODRIFT_ENABLE			0U
#define TEF82XX_DEFAULT_AUTODRIFT_FREQ				(float32_t)3e6

// Dummy profile for ES2 Calibration workaround
#define TEF82XX_ES2_DUMMY_PROFILE					e_SYS_PROFILE_7

//Decimation
#define TEF82XX_DECIMATION_ADC_5MSPS				16U
#define TEF82XX_DECIMATION_ADC_10MSPS				8U
#define TEF82XX_DECIMATION_ADC_20MSPS				4U
#define TEF82XX_DECIMATION_ADC_40MSPS				2U

#define TEF82XX_DEFAULT_CHRIP_PROFILES				1
#define TEF82XX_DEFAULT_CHRIPS_IN_FRAME				128
#define TEF82XX_DEFAULT_SEMPLES_PER_CHRIP			512
#define TEF82XX_DEFAULT_CENTRE_FREQUENCY			79000000
#define TEF82XX_DEFAULT_ACQ_BAND_WIDTH				1000000
#define TEF82XX_DEFAULT_JUMPBACK_TIME				4
#define TEF82XX_DEFAULT_T_PRE_SAMPLING				40
#define TEF82XX_DEFAULT_T_RETURN					255
#define TEF82XX_DEFAULT_T_START						40
#define TEF82XX_DEFAULT_TX_CHANNEL_ENABLE			1
#define TEF82XX_DEFAULT_TX_CHANNEL_POWER			6.0
#define TEF82XX_FNRESETCHIRP_DELAY					10u
#define TEF82XX_DEFAULT_PLL_LOOP_FILTER_BANDWIDTH   300000.0f

/**
* @defgroup     RSDK_TEF82XX_CENTER_FREQUENCY Limit values for rsdkRfeChirpProfile_t::centerFrequency, values MHz
* @details      Limit values for rsdkRfeChirpProfile_t::centerFrequency, values MHz
* @{
*/
#define RFE_TEF82XX_MIN_CENTER_FREQUENCY        	76100U
#define RFE_TEF82XX_MAX_CENTER_FREQUENCY        	80900U
/** @} */
/**
* @brief        Enable auto maximum safe power output for rsdkRfeChirpProfile_t::txChannelPower
*/
#define RFE_TEF82XX_SET_MAX_SAFE_TX_POWER       	16.0f

#define RFE_SPI_TX_BUFF_SIZE	            		512U
#define RFE_SPI_RX_BUFF_SIZE	            		512U

/**
* @defgroup     RSDK_TEF82XX_FREQ_AUTO_DRIFT Limit values for rsdkTef82XXFrameOptionalParams_t::rsdkTef82XXAutoDriftParams_t::FreqDriftHz, values Hz
* @details      Limit values for rsdkTef82XXFrameOptionalParams_t::rsdkTef82XXAutoDriftParams_t::FreqDriftHz, values Hz
* @{
*/
#define TEF82XX_DISABLE_FREQ_AUTO_DRIFT   0.0f
#define TEF82XX_MIN_FREQ_AUTO_DRIFT   	0.0f
#define TEF82XX_MAX_FREQ_AUTO_DRIFT   	40e6f

#define RFE_TEF82XX_PLL_LOOP_FILTER_BANDWIDTH_MIN      200000.0f
#define RFE_TEF82XX_PLL_LOOP_FILTER_BANDWIDTH_MAX     1700000.0f
#define RFE_TEF82XX_PLL_LOOP_FILTER_BANDWIDTH_STEP      50000.0f

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/**
* @brief    List of chirp sequences indexes and the maximum number of sequences supported.
* @details  
*/
enum
{
    RFE_CHIRP_SEQUENCE_0 = 0U,
    RFE_CHIRP_SEQUENCE_1 = 1U,
    RFE_CHIRP_SEQUENCE_2 = 2U,
    RFE_CHIRP_SEQUENCE_3 = 3U,
    RFE_CHIRP_SEQUENCE_4 = 4U,
    RFE_CHIRP_SEQUENCE_5 = 5U,
    RFE_CHIRP_SEQUENCE_6 = 6U,
    RFE_CHIRP_SEQUENCE_7 = 7U,
    RFE_MAX_CHIRP_SEQUENCES
};

/**
 * @brief       CSI2 Virtual Channel enumeration.
 * @details     Adjusted to the specific platform.
 *
 */
typedef enum
{
	RFE_CSI2_VC_0 = 0,             /**< Virtual Channel 0                                                          */
	RFE_CSI2_VC_1,                 /**< Virtual Channel 1                                                          */
	RFE_CSI2_VC_2,                 /**< Virtual Channel 2                                                          */
	RFE_CSI2_VC_3,                 /**< Virtual Channel 3                                                          */
	RFE_CSI2_MAX_VC                /**< Virtual channels number limit for Csi2 unit, to not use in procedure call  */
}rfeFeCsi2VirtChnlId_t;

/**
* @brief    List of the supported front-end configuration modes
* @details  Tells the driver if the front-end is used alone or part of front-end cascade
*/
typedef enum
{
    RFE_STANDALONE = 0U,
	RFE_CASCADING_LEADER = 1U,
	RFE_CASCADING_FOLLOWER  = 2U,
} rfeFrontendMode_t;

/**
* @brief    List of the chirp slope directions
*/
typedef enum
{
    RFE_FALLING = 0U,
    RFE_RISING = 1U,
} rfeChirpSlopeDirection_t;

/**
* @brief    List of transmit channel indexes and the maximum number of channels supported by the library
* @details  Can be used with fields that depend on RSDK_RFE_MAX_TX_CHANNELS or RSDK_[device]_MAX_TX_CHANNELS
*/
enum
{
    RFE_TX_CHANNEL_0 = 0U,
    RFE_TX_CHANNEL_1 = 1U,
    RFE_TX_CHANNEL_2 = 2U,
    RFE_MAX_TX_CHANNELS
};

/**
* @brief    List of receive channel indexes and the maximum number of channels supported by the library
* @details  Can be used with fields that depend on RSDK_RFE_MAX_RX_CHANNELS or RSDK_[device]_MAX_RX_CHANNELS
*/
enum
{
    RFE_RX_CHANNEL_0 = 0U,
    RFE_RX_CHANNEL_1 = 1U,
    RFE_RX_CHANNEL_2 = 2U,
    RFE_RX_CHANNEL_3 = 3U,
    RFE_MAX_RX_CHANNELS
};

/**
* @brief    List of chirp profiles indexes and the maximum number of profiles supported by the library.
* @details  
*/
enum
{
    RFE_CHIRP_PROFILE_0 = 0U,
    RFE_CHIRP_PROFILE_1 = 1U,
    RFE_CHIRP_PROFILE_2 = 2U,
    RFE_CHIRP_PROFILE_3 = 3U,
    RFE_CHIRP_PROFILE_4 = 4U,
    RFE_CHIRP_PROFILE_5 = 5U,
    RFE_CHIRP_PROFILE_6 = 6U,
    RFE_CHIRP_PROFILE_7 = 7U,
    RFE_MAX_CHIRP_PROFILES
};

enum
{
    RFE_LIST_PROFILE_0 = 0U,
    RFE_LIST_PROFILE_1 = 1U,
    RFE_LIST_PROFILE_2 = 2U,
    RFE_LIST_PROFILE_3 = 3U,
    RFE_LIST_PROFILE_4 = 4U,
    RFE_LIST_PROFILE_5 = 5U,
    RFE_LIST_PROFILE_6 = 6U,
    RFE_LIST_PROFILE_7 = 7U,
    RFE_MAX_LIST_PROFILES
};
/**
* @brief        Profile indexes used to refer to a specific profile.
*/
enum rfeProfiles
{
	RFE_PROFILE_0 = 0U,
	RFE_PROFILE_1 = 1U,
	RFE_PROFILE_2 = 2U,
	RFE_PROFILE_3 = 3U,
	RFE_PROFILE_4 = 4U,
	RFE_PROFILE_5 = 5U,
	RFE_PROFILE_6 = 6U,
	RFE_PROFILE_7 = 7U,
	RFE_MAX_NR_OF_PROFILES
};

/**
* @brief        List of supported ADC sampling frequencies.
*/
typedef enum
{

	RFE_ADC_40MSPS = 0U,
	RFE_ADC_20MSPS = 1U,
	RFE_ADC_10MSPS = 2U,
	RFE_ADC_5MSPS = 3U
} rfeSamplingFrequencies_t;

/**
* @brief        List of supported Phase Rotator DDMA modes
* 				Should be used with rfeFrameParams_t::rfePhaseRotatorParams_t.
*/
typedef enum
{
	RFE_PR_DDMA_DISABLED = 0U,
	RFE_PR_DDMA_FUNCTIONAL_MODE,
	RFE_PR_DDMA_TEST_MODE,
	RFE_PR_DDMA_TEST_MODE_NOCHIRP,
} rfeDDMAModeSel_t;

/**
* @brief        List of supported Phase Rotator Phase Code generation modes
* 				Should be used with rfeFrameParams_t::rfePhaseRotatorParams_t.
*/
typedef enum
{
	RFE_PR_PCGEN_NO_CHANGE = 0U,
	RFE_PR_PCGEN_REPLACE_MSB_WITH_QPSK,
	RFE_PR_PCGEN_ADD_QPSK_TO_MSB
} rfePRPCGenMode_t;

/**
* @brief        List of supported RX gains, should be used with rsdkRfeChirpProfile_t::rxChannelGain.
*/
typedef enum
{
	RFE_RX_GAIN_27DB	= 1U,
	RFE_RX_GAIN_30DB,
	RFE_RX_GAIN_33DB,
	RFE_RX_GAIN_36DB,
	RFE_RX_GAIN_39DB,
	RFE_RX_GAIN_42DB,
	RFE_RX_GAIN_45DB
} rfeRxGain_t;

/**
 * @brief List of supported chirp PLL VCO bandwidths, should be used with rsdkRfeChirpProfile_t::chirpPllVcoBandwidth.
 * 
 */
typedef enum
{
	RFE_CHIRP_PLL_VCO_BANDWIDTH_1GHZ = 0U,
	RFE_CHIRP_PLL_VCO_BANDWIDTH_2GHZ = 1U,
	RFE_CHIRP_PLL_VCO_BANDWIDTH_4GHZ = 2U,
	RFE_CHIRP_PLL_VCO_BANDWIDTH_INVALID
} rfeChirpPllVcoBandwidth_t;

/**
* @brief        List of supported RX LPF Cutoff frequencies, should be used with rsdkTef82XXProfileOptionalParams_t::rsdkRfeTef82XXRxLpfCutOff_t.
*/
typedef enum
{
	RFE_RX_LPF_CUTOFF_12_5MHZ = 0U,
	RFE_RX_LPF_CUTOFF_15MHZ,
	RFE_RX_LPF_CUTOFF_20MHZ,
	RFE_RX_LPF_CUTOFF_25MHZ,
	RFE_RX_LPF_CUTOFF_WIDE,
	RFE_RX_LPF_CUTOFF_INVALID
} rfeRxLpfCutOff_t;

/**
* @brief        List of supported RX HPF Cutoff frequencies, should be used with rsdkTef82XXProfileOptionalParams_t::rsdkRfeTef82XXRxHpfCutOff_t.
*/
typedef enum
{
	RFE_RX_HPF_CUTOFF_100KHZ = 0U,
	RFE_RX_HPF_CUTOFF_200KHZ,
	RFE_RX_HPF_CUTOFF_300KHZ,
	RFE_RX_HPF_CUTOFF_400KHZ,
	RFE_RX_HPF_CUTOFF_800KHZ,
	RFE_RX_HPF_CUTOFF_1600KHZ,
	RFE_RX_HPF_CUTOFF_3200KHZ,
	RFE_RX_HPF_CUTOFF_INVALID
} rfeRxHpfCutOff_t;

typedef enum
{
    RFE_UNINITIALIZED            = 0,
    RFE_INITIALIZED              = 1,
    RFE_FRAME_CONFIGURED         = 2,
    RFE_DEVICE_RESET_FINISHED    = 3, // Signal a possible inconsistent state, device was reset but driver not
    RFE_FRAME_PARTIAL_CONFIGURED = 4, // Some of the registers that configure a frame have been changed
    RFE_FE_CALIBRATED            = 5,
} rfeState_t;

typedef enum
{
	RFE_TRIGGER_TYPE_SPI = 0,
	RFE_TRIGGER_TYPE_GPIO= 1
} rfeTriggerType_t;

/**
* @brief List of supported MIPI CSI2 configuration levels.
*/
typedef enum
{
	RFE_MIPI_CONFIG_VC,	  // only VC
	RFE_MIPI_CONFIG_PDC,  // PDC and VC 
	RFE_MIPI_CONFIG_FULL, // all settings (PDC, VC and others)
} rfeMipiCsiConfigLevel_t;

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief        Contains the parameters used to configure a radar chirp sequence (frame).
* @details      
*/
typedef struct
{
	/** [in] Number of chirps present in the chirp sequence/frame. 
	 * 
	*/
	uint16_t nrChirpsInFrame;
	/** [in] Bit field indicating which of the receive channels are enabled. Bit 0 -> Rx[0] ... Bit 7 -> Rx[7].
	 * 
	*/
	uint8_t rxChannelEnable;
	/** [in] Use external chirp start trigger:
	 *	- 0: Use SPI trigger (via RsdkRfeFrameStart)
	 *	- 1: Use external trigger mode with single trigger for the entire frame
	 *	- 2: Use external trigger mode with a trigger for every chirp in frame
	 *	The external trigger uses "chirp_start" pin as input. In case of external trigger use,
	 *	     "chirp_start" pin handling will be handled outside the RFE driver. RsdkRfeFrameStart will
	 *	     return a DOLPHINIC_EC_WRONG_CHIRP_TRIGGER_MODE error if called when external trigger is used.
	 *	- Default value: 0 (SPI trigger)
	 * */
	uint8_t useExtTrig;
	/** [in] This input parameter decides the sequence of using different profiles in a chirp frame.
	*	- 0x00: Selects Prof-0
	*	- 0x01: Selects Prof-1
	*	- 0x02: Selects Prof-2
	*	- 0x03: Selects Prof-3
	*	- 0x04: Selects Prof-4
	*	- 0x05: Selects Prof-5
	*	- 0x06: Selects Prof-6
	*	- 0x07: Selects Prof-7
	*	- 0x08: Selects Prof-8
	*	- 0x09: Selects Prof-0-1
	*	- 0x0A: Selects Prof-0-1-2
	*	- 0x0B: Selects Prof-0-1-2-3
	*	- 0x0C: Selects Prof-0-1-2-3-4
	*	- 0x0D: Selects Prof-0-1-2-3-4-5
	*	- 0x0E: Selects Prof-0-1-2-3-4-5-6
	*	- 0x0F: Selects Prof-0-1-2-3-4-5-6-7
	*	- 0x1E: Selects pseudo random profile
	*	- 0x1F: Selects profiles from the profile list
	*	- Default value: 0
	* */
	uint8_t profModeSel;
	/** [in] This is a custom list of maximum 8 profiles that can be used by the RFE in any order specified by
	 * the user: {3, 6, 2} for running Profile 4, 7, 3 in this exact sequence. Range for each element is [0, 7].
	 * To use this custom list, rsdkTef82XXFrameOptionalParams_t::profModeSel needs to be set to 0x1F.
	 * Default value: NULL (empty)
	* */
	uint8_t profList[RFE_MAX_CHIRP_PROFILES];
	/** [in] PLL Loop bandwidth in Hz
	 * PLL Loop bandwidth must be provided in multiples of 50kHz.
	 * For the values other than multiples of 50kHz will be rounded off to the nearest multiple of 50kHz BW.
	 * - For 1G VCO PLL Loop BW starts from 200kHz and ends at 2400kHz mode.
	 * - For 2G VCO starts from 250kHz  and ends at 2400kHz,
	 * - For 4G VCO PLL Loop BW starts from 300kHz  and ends at 2800kHz.
	 *  Default value: 1600kHz (for 1G VCO PLL)
	 * */
	float32_t cafcLoopBandwidth;
	/** [in] Effective center frequency of the chirp, this will be used to perform loop gain compensation.
	 */
	float32_t effFc;
	/** [in] Chirp PLL VCO Bandwidth options
	 * 	- 0 : 1GHz VCO
	 * 	- 1 : 5GHz VCO, working in 2GHz bandwidth mode
	 * 	- 2 : 5GHz VCO, working in 4GHz bandwidth mode
	 * 	Default value: 2 (5GHz VCO, working in 4GHz bandwidth mode)
	 */
	rfeChirpPllVcoBandwidth_t vcoSel;
	/** chirp slope direction
	 */
	BOOL DownChirp;
	// ------------------------------------
	/** Profile used for mean center frequency calculation. Init in Profile config.
	  * */
	uint8_t                     meanCenterFreqProf;
	/** Profile timing used for mean center frequency calculation. Init in Profile config.
	 * */
	SYS_ProfChirpTiming_t       meanCenterFreqProfTiming;
	/** Profile frequency used for mean center frequency calculation. Init in Profile config.
	 * */
	SYS_ProfChirpFreq_t         meanCenterFreqProfFreq;
	/** Number of chirp profiles used in sequence
	 * */
	uint8_t nrSequenceChirpProfiles;
	/** Parameter used for No TXPout emission Calibration feature
	 * */
	BOOL	firstCalib;
	SYS_TXErrors_t txErr[RFE_MAX_TX_CHANNELS];	// Tx channel ISM err. Update after each chirping. It is using in Tx calib without radiation

} rfeFrameParams_t;

/**
* @brief        Contains the generic parameters used to configure a radar cycle.
* @details      
*/
typedef struct 
{
	/** [in] Time duration of the entire radar cycle in 25ns steps.
	 */
	uint32_t tRadarCycleDuration;
	/** [in] Number of chirp sequences in the radar cycle.
	 */
	uint8_t noRadarSequences;
	// TODO: Add support for recalibration parameteres
	// - recalibrationProfileIndependent chirp-sequences="0"
	// - recalibrationProfileDependent chirp-sequence="0" chirp-profiles="0"
	/** [in] Array of chirp sequences. 
	 * */
	rfeFrameParams_t chirpSequences[RFE_MAX_CHIRP_SEQUENCES];	
} rfeRadarCycleParams_t;

/**
* @brief        Contains the general parameters used to configure radar.
* @details      
*/
typedef struct 
{
    /** [in] Time duration after the acquisition window has finished and the end of the chirp ramp in ns steps.
     * Must be the same for all chirps. */
    uint32_t tJumpbackTime;
	/** [in] The number of chirp profiles that will be configured for this frame. The application should allocate
	 * an array of rsdkRfeChirpProfile_t that will have nrChirpProfiles elements.
	 * */
	uint8_t nrChirpProfiles;
} rfeRadarGeneral_t;

/*==================================================================================================
 *                                         Functions
 ==================================================================================================*/
/*****************************************************************************
 * \brief   Set MIPI-CSI2 parameters for a specified chirp sequence
 *
 *
 * \param   chirpSequence    			= the index of the sequence
 * \param   rfe___error___pointer       = pointer to the error variable
 * \param   configLevel					= config level see rfeMipiCsiConfigLevel_t
 *
 * \details Please note the preprocessor define MIPI_SETUP_SEQUENCE.
 * - If this is NOT defined, driver will activate all virtual channels used in configuration, on all profiles. This is done at configuration stage only one time.
 * TEF82XX will send the events on all MIPI CSI2 virtual channels configured, not on the specific channel programed in the current profile from current sequence. 
 * - If this is DEFINED, driver will activate only virtual channels used in profiles from current sequence. This is done at every chirp sequence.			
 * 
 * \return  NIL
 */
void MIPI_Config(rfeMipiCsiConfigLevel_t configLevel, rfe_chirpSequenceIndex_t chirpSequence, rfe_error_t* rfe___error___pointer);

/**
 * \brief This function setups CAFC Loop Filter.
 *
 * \details
 * \pre NIL
 *
 * \param in
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * \return NIL
 *
 * \post
 * -
 * -
 *
 * \ingroup NIL
 */
void CAFC_ConfigLoopFilter(uint8_t chirpSequence, rfe_error_t* rfe___error___pointer);

/**
 * \brief This function start the configuration of the TEF82XX.
 *
 * \details This function configure the frontend with Id = frontendId and use
 * the pointer rfeConfig from blob configuration file
 *
 * \pre NIL
 *
 * \param in		rfeConfig - blob pointer
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * \return NIL
 *
 * \post
 * -
 * -
 *
 * \ingroup NIL
 */
void rfeSwCfgTef82xxConfig(uint8_t* rfeConfig, rfe_error_t* rfe___error___pointer);
/**
 * \brief This function perform static timing engine configuration of the TEF82XX.
 *
 * \details This function configure the front end with Id = frontendId and use
 * the pointer rfeConfig from blob configuration file
 *
 * \pre NIL
 *
 * \param in		chirpSeqIndex - current sequence
 * 					rfeConfig - blob pointer
 * 					TeStaticConf - Data to be passed to TE.
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * \return NIL
 *
 * \post
 * -
 * -
 *
 * \ingroup NIL
 */
void TE_ConfigStatic(uint8_t chirpSeqIndex, uint8_t *pRfeConfig, rfe_error_t* rfe___error___pointer);

/**
 * \brief This function performs phase rotators configuration for a specific chirp sequence.
 *
 * \pre NIL
 *
 * \param in		chirpSequenceConfigIndex - current sequence
 * 					pDrvState - frontend persistent memory configuration
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * \return NIL
 *
 * \post
 * -
 * -
 *
 * \ingroup NIL
 */
void rfeSwCfg_PhaseRotatorPhaseControl(const uint8_t * pRfeConfig, 
									  rfe_chirpSequenceIndex_t chirpSequenceConfigIndex,
		 							  rfe_error_t* rfe___error___pointer);

/**
 * \brief This function performs profile sequencing configuration of the TEF82XX.
 *
 * \details This function configure the frontend with Id = frontendId and use
 * the pointer rfeConfig from blob configuration file
 *
 * \pre NIL
 *
 * \param in		frontendId - frontend id
 * 					rfeConfig - blob pointer
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * \return NIL
 *
 * \post
 * -
 * -
 *
 * \ingroup NIL
 */
void TE_ConfigProfileSequencing(uint8_t chirpSequence, rfe_error_t* rfe___error___pointer);

/**
 * \brief 
 *
 * \details 
 * 
 *
 * \pre NIL
 *
 * \param in		the reccomended power mode (configuration identifier)
 * 					
 *

 * \param [in,out]
 *
 * \return NIL		BC_ERRCODE - Error return by function:
 *
 * \post
 * -
 * -
 *
 * \ingroup NIL
 */
BC_ERRCODE rfeSwCfgSetDynPowMode(powerMode_t mode);
/**
 * \brief 
 *
 * \details 	configure frontend for fast PLL switching
 * 
 *
 * \pre NIL
 *
 * \param in		NIL
 * 					
 *
 * \param out  		errCode
 *
 *
 * \return NIL
 *
 * \post
 * -
 * -
 *
 * \ingroup NIL
 */
BC_ERRCODE rfeSwCfgSetFastSwitch(void);

/**
 * \brief     This function gets sw error masking/unmasking configuration
 *
 * \details   This function gets sw error masking/unmasking configuration from array #swFusaMask. 
 *
 * \pre NIL
 *
 * \param[in]   swErrorIndex -sw error index
 * 					
 *
 * \param[out]  NIL
 *
 *
 * \return masking/unmasking status of a selected error
 *
 * \post
 * -
 * -
 *
 * \ingroup NIL
 */
BOOL getSwFusaMask( uint8_t swErrorIndex );

/**
 * \brief     This function performs switch between CPM and DMP
 *
 * \details   CPM - chirp power mode ; DPM - dynamic power mode
 *
 * \pre NIL
 *
 * \param[in]   swErrorIndex -sw error index
 *
 *
 * \param[out]  NIL
 *
 *
 * \return error code TEF82xx style
 *
 * \post
 * -
 * -
 *
 * \ingroup NIL
 */
BC_ERRCODE CpmWaDpmEnable(BOOL flag);

/**
 * \brief     This function performs CPM rx enable
 *
 *
 * \pre NIL
 *
 * \param[in]   swErrorIndex -sw error index
 *
 *
 * \param[out]  NIL
 *
 *
 * \return error code TEF82xx style
 *
 * \post
 * -
 * -
 *
 * \ingroup NIL
 */
BC_ERRCODE CpmWaRxEnable(BOOL flag);

/**
 * \brief     This function performs SSB phase fix
 *
 *
 * \pre NIL
 *
 *
 * \param[out]  NIL
 *
 *
 * \return error code TEF82xx style
 *
 * \post
 * -
 * -
 *
 * \ingroup NIL
 */
BC_ERRCODE TxPhaseWa1SsbEnable(BOOL flag);

/**
 * \brief This function return the pointer of swFusaMask array.
 *
 * \details
 * \pre NIL
 *
 * \param in
 *
 * \param [in,out]
 *
 * \return BOOL* - pointer of swFusaMask array
 *
 * \post
 * -
 * -
 *
 * \ingroup NIL
 */
BOOL* GetSwFusaMaskAddress(void);

/**
 * \brief This function get the profChirpSample.
 *
 * \details
 * \pre NIL
 *
 * \param in 		profileIdx - profile number
 * 					pRfeConfig - pointer of RfeConfig blob
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * \param out		 profChirpSample - pointer of  SYS_ProfChirpSampleDeci_t structure
 *
 * \return NIL
 *
 * \post
 * -
 * -
 *
 * \ingroup NIL
 */
void GetProfChirpSample(SYS_ProfChirpSampleDeci_t* profChirpSample, uint8_t	profileIdx, uint8_t *pRfeConfig,
		rfe_error_t* rfe___error___pointer);

/**
 * \brief This function get the ProfChirpFreq.
 *
 * \details
 * \pre NIL
 *
 * \param in		profileIdx - profile number
 * 					pRfeConfig - pointer of RfeConfig blob
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * \param out		 profChirpFreq - pointer of  SYS_ProfChirpFreq_t structure
 *
 * \return NIL
 *
 * \post
 * -
 * -
 *
 * \ingroup NIL
 */
void GetProfChirpFreq(SYS_ProfChirpFreq_t* profChirpFreq, uint8_t	profileIdx, uint8_t *pRfeConfig,
		rfe_error_t* rfe___error___pointer);

/**
 * \brief This function get the ProfChirpTiming.
 *
 * \details
 * \pre NIL
 *
 * \param in		profileIdx - profile number
 * 					pRfeConfig - pointer of RfeConfig blob
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * \param out		profChirpTiming - pointer of  SYS_ProfChirpTiming_t structure
 *
 * \return NIL
 *
 * \post
 * -
 * -
 *
 * \ingroup NIL
 */
void GetProfChirpTiming(SYS_ProfChirpTiming_t* profChirpTiming, uint8_t	profileIdx, uint8_t *pRfeConfig,
		rfe_error_t* rfe___error___pointer);

/**
 * \brief This function get the PllLoopFilterBw.
 *
 * \details
 * \pre NIL
 *
 * \param in		chirpProfileIndex - profile number
 * 					pRfeConfig - pointer of RfeConfig blob
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * \return float32_t - pll loop filter bandwidth
 *
 * \post
 * -
 * -
 *
 * \ingroup NIL
 */
float32_t GetPllLoopFilterBw(uint8_t chirpProfileIndex, uint8_t* pRfeConfig,
		rfe_error_t* rfe___error___pointer);

/**
 * \brief This function set the RX saturation threshold .
 *
 * \details
 * \pre NIL
 *
 * \param in		rfeConfig - pointer of RfeConfig blob
 * 					adcNum - IP number (e_SYS_ADC12 sau e_SYS_ADC34)
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * \return none
 *
 * \post
 * -
 * -
 *
 * \ingroup NIL
 */
void SetRxSaturationThresholdStage(uint8_t* rfeConfig, SYS_IPNum_e adcNum,
		rfe_error_t* rfe___error___pointer );

/**
 * \brief This function set the Sequence prof chirp param .
 *
 * \details
 * \pre NIL
 *
 * \param in		pRfeConfig - pointer to current DrvState array
 * 					sequenceIndex - sequence index
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * \return none
 *
 * \post
 * -
 * -
 *
 * \ingroup NIL
 */
void SetSequenceProfChirpParam(uint8_t *pRfeConfig,	uint8_t sequenceIndex,
		rfe_error_t* rfe___error___pointer);

#endif /* RFE_SW_CFG_TEF82XX_H_ */
