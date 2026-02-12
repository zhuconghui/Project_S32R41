/*
 * Copyright 2016,2019-2022 NXP
 * NXP Confidential. This software is owned or controlled by NXP and may only
 * be used strictly in accordance with the applicable license terms. By
 * expressly accepting such terms or by downloading, installing, activating
 * and/or otherwise using the software, you are agreeing that you have read,
 * and that you agree to comply with and are bound by, such license terms. If
 * you do not agree to be bound by the applicable license terms, then you may
 * not retain, install, activate or otherwise use the software.
 */

/**
@file bc_types.h

@version

@brief Barracuda API header file

This is the header file for Barracuda APIs. All exported API can be found in
this file.

<TotalNumAPI>
*/

#ifndef BC_TYPES_H
#define BC_TYPES_H


#include <stdint.h>

#include "bc_err.h"

#if defined(__cplusplus)
extern "C"
{
#endif

///  typedefs to fix MISRA DIR4.6
typedef uint8_t BOOL;
typedef float float32_t;

#ifdef ENABLE_DOUBLE_PRECISION
typedef double float64_t;
#define BC_FLOAT float64_t
#else
#define BC_FLOAT float32_t ///  this is default setting  
#endif
#ifndef TRUE
#define TRUE ((uint8_t)1u)
#endif
#ifndef FALSE
#define FALSE ((uint8_t)0u)
#endif
#ifndef BARRACUDA_IGNORE_PARAM
#define BARRACUDA_IGNORE_PARAM(p)  (void) (p)
#endif

///  Platform layer SPI communication target
typedef enum
{
    e_PLF_MASTER = 0x00u,
    e_PLF_SLAVE1 = 0x01u,
    e_PLF_SLAVE2 = 0x02u,
    e_PLF_SLAVE3 = 0x03u,
    e_PLF_SPITARGET_INVALID
} PLF_SPITarget_e;

/**
SYS IP number enum, using SPI module address as enum number.
This enum is used widely in all APIs, where user is expected to select an IP to be operated on.
When user is expected to choose among from a sub list of IPs (e.g. from RX1-RX4), this type is also used. In this case the API will do parameter validation internally, input that is out of range will be rejected and reported as error code.
## Note
0x03, 0x0B, 0x19-0x29 are not used.
*/
typedef enum
{
    e_SYS_CC = 0x00u,
    e_SYS_LVDS = 0x01u,
    e_SYS_MIPI = 0x02u,
    // 0x3 is not existent
    e_SYS_TE = 0x04u,
    e_SYS_SC = 0x05u,
    e_SYS_CAFC = 0x06u,
    e_SYS_ADC12 = 0x07u,
    e_SYS_ADC34 = 0x08u,
    e_SYS_GBIAS = 0x09u,
    e_SYS_LOI = 0x0Au,
    // 0xB is not existent
    e_SYS_MCLK = 0x0Cu,
    e_SYS_RX1 = 0x0Du,
    e_SYS_RX2 = 0x0Eu,
    e_SYS_RX3 = 0x0Fu,
    e_SYS_RX4 = 0x10u,
    e_SYS_TX1 = 0x11u,
    e_SYS_TX2 = 0x12u,
    e_SYS_TX3 = 0x13u,
    e_SYS_SSB = 0x14u,
    e_SYS_GLDO = 0x15u,
    e_SYS_ATB = 0x16u,
    e_SYS_OTP = 0x17u,
    e_SYS_ISM = 0x18u,
    e_SYS_TEMP_DIGITIZER = 0x19u,
    // 0x20-0x29 is not existent
    e_SYS_ADCMC = 0x30u,
    e_SYS_TXMC = 0x31u,
    e_SYS_RXMC = 0x32u,
    e_SYS_INVALID
} SYS_IPNum_e;

///  ATB path, user may choose ATB1 or ATB2 to be used.
typedef enum
{
    e_SYS_ATBNUM1 = 0x00u,
    e_SYS_ATBNUM2 = 0x01u,
    e_SYS_ATBNUM_INVALID
} SYS_ATBNum_e;

///  CRC check trigger event selection, to choose at what event CRC check should be triggered.
typedef enum
{
    ///  No CRC check triggered.
    e_SYS_CRC_TRIGGER_EVENT_NO_CRC_TRIGGER = 0x00u,
    ///  CRC check is triggered at the start of the chirp sequence (Hardware based) for all modules
    e_SYS_CRC_TRIGGER_EVENT_AT_START_OF_CHIRP = 0x01u,
    ///  CRC check is triggered at the end of the chirp sequence  (Hardware based) for all modules
    e_SYS_CRC_TRIGGER_EVENT_AT_END_OF_CHIRP = 0x02u,
    ///  CRC check is triggered by the MCU.
    e_SYS_CRC_TRIGGER_EVENT_MCU_TRIGGER = 0x03u,
    e_SYS_CRC_TRIGGER_EVENT_INVALID
} SYS_CRC_Trigger_Event_e;

///  TX output power calibration mode
typedef enum
{
    ///  calibrate to center gain
    e_SYS_TXCAL_CENTERGAIN = 0x00u,
    /// calibrate to the lowest gain that does not trigger the rf_level_low_error
    e_SYS_TXCAL_LOWESTGAIN = 0x01u,
    ///  calibrate to the highest gain that does not trigger the rf_level_high_error
    e_SYS_TXCAL_HIGHESTGAIN = 0x02u,
    e_SYS_TXCAL_INVALID
} SYS_TXCal_e;

///  External Pin Id of the Barracuda
typedef enum
{
    /// The CHIRP_START pin provides precise timing of the actual chirp. The precise timing information is available in two output waveforms, which is chosen by sel_mode_for_chirp_start_out bitfield
    e_SYS_CHIRPSTART_IN_PAD = 0x01u,
    /// This pin can be configued as output pad with different functionalities like MCU_INT, Chirp start trigger or Chirp signal indicating busy/silent period of the chirp based on the configuration
    e_SYS_MCUINT_CHIRPSTART_OUT_PAD = 0x02u,
    /// ERROR_N pin is a generic error interrupt which indicates the MCU that there has a safety-related error has occurred.
    e_SYS_ERRORN = 0x03u,
    /// When a safety sensor is enabled and configured, then any error reported is latched within the module. The latched error is also propagated to inner safety monitor. The latched error is only reset by asserting the ERROR_RESET or via SPI
    e_SYS_ERRORRESET = 0x04,
    /// When the QPSK I/Os controls is set to “synchronous” mode, the value of the TXn_PS_I and TXn_PS_Q I/Os for each TX is sampled at a moment in time defined
    e_SYS_TX1_I_PS = 0x05u,
    e_SYS_TX2_I_PS = 0x06u,
    e_SYS_TX3_I_PS = 0x07u,
    e_SYS_TX1_Q_PS = 0x08u,
    e_SYS_TX2_Q_PS = 0x09u,
    e_SYS_TX3_Q_PS = 0x0Au,
    /// HRSET_N resets all modules to their default state and register values, except the OTP module. The OTP module is insensitive to HRESET_N. Application need to set this pin high 
    e_SYS_HRESET = 0x0Fu,
    /// Option to select all external pins of Barracuda
    e_SYS_ALL_BC_PINS = 0x10u,
    e_SYS_PINID_INVALID
} SYS_ExtPinID_e;

///  Profile IDs
typedef enum
{
    ///  Select profile 0
    e_SYS_PROFILE_0 = 0x00u,

    ///  Select profile 1
    e_SYS_PROFILE_1 = 0x01u,

    ///  Select profile 2
    e_SYS_PROFILE_2 = 0x02u,

    ///  Select profile 3
    e_SYS_PROFILE_3 = 0x03u,

    ///  Select profile 4
    e_SYS_PROFILE_4 = 0x04u,

    ///  Select profile 5
    e_SYS_PROFILE_5 = 0x05u,

    ///  Select profile 6
    e_SYS_PROFILE_6 = 0x06u,

    ///  Select profile 7
    e_SYS_PROFILE_7 = 0x07u,

    ///  Select profile 8
    e_SYS_PROFILE_8 = 0x08u,

    ///  Select profiles 0-1-0-1
    e_SYS_PROFILES_0_TO_1 = 0x09u,

    ///  Select profiles 0-1-2-0-1-2
    e_SYS_PROFILES_0_TO_2 = 0x0Au,

    ///  Select profiles 0-1-2-3-0-1-2-3
    e_SYS_PROFILES_0_TO_3 = 0x0Bu,

    ///  Select profiles 0-1-2-3-4-0-1-2-3-4
    e_SYS_PROFILES_0_TO_4 = 0x0Cu,

    ///  Select profiles 0-1-2-3-4-5-0-1-2-3-4-5
    e_SYS_PROFILES_0_TO_5 = 0x0Du,

    ///  Select profiles 0-1-2-3-4-5-6-0-1-2-3-4-5-6
    e_SYS_PROFILES_0_TO_6 = 0x0Eu,

    ///  Select profiles 0-1-2-3-4-5-6-7-0-1-2-3-4-5-6-7
    e_SYS_PROFILES_0_TO_7 = 0x0Fu,

    ///  Select pseudo random profile
    e_SYS_PROFILE_PSRB = 0x1Eu,

    ///  Select profiles from the profile list
    e_SYS_PROFILE_LIST = 0x1Fu,

    e_SYS_PROFILE_INVALID
} SYS_ProfID_e;

///  Virtual channel numbers
typedef enum
{
    e_SYS_VCN_0 = 0x00u,
    e_SYS_VCN_1 = 0x01u,
    e_SYS_VCN_2 = 0x02u,
    e_SYS_VCN_3 = 0x03u,
    e_SYS_VCN_INVALID
} SYS_VCN_e;

/// Modes for forcing new subband, keeping current subband
typedef enum
{
    ///  keep current subband in register
    e_SYS_SBCHG_KEEPSB = 0x00u,
    ///  manually force a subband
    e_SYS_SBCHG_FORCESB = 0x01u,
    e_SYS_SBCHG_INVALID = 0x02u
} SYS_SBChangeMode_e;

/// setting, masking, resetting ADC errors cmd selection
typedef enum
{
    ///  sets the errors
    e_SYS_TEST_FORCE_ERR = 0x01u,
    ///  sets the reset errors

    e_SYS_TEST_RESET_ERR = 0x02u,
    ///  mask  the force errors generated by CC toward the sensor

    e_SYS_MASK_CC_FORCE_ERR = 0x03u,
    ///  mask  the reset errors generated by CC toward the sensor
    e_SYS_MASK_CC_RESET_ERR = 0x04u,
    ///  mask  the force errors from sensor toward CC
    e_SYS_MASK_CC_ERR = 0x05u,
    e_SYS_TESTERRCMD_INVALID

} SYS_TestLocalErrCmd_e;

///  Options for the chirp frequency input parameter for API BC_SYS_ProgramChirp
typedef enum
{

    ///  input frequency param is the start frequency of the full ramp (at the beginning of tSettle)

    e_SYS_STARTFREQFULLRAMP = 0x00u,

    ///  input frequency param is the start frequency of the acquisition time (at the end of tSettle)

    e_SYS_STARTFREQACQ = 0x01u,

    ///  input frequency param is the center frequency of the full frequency ramp (middle of frequency between beginning of tSettle and end of tJumpback)

    e_SYS_CENTERFREQFULLRAMP = 0x02u,

    ///  input frequency param is the center frequency of the acquisition time (middle of frequency between end of tSettle and beginning of tJumpback

    e_SYS_CENTERFREQACQ = 0x03u,

    e_SYS_FREQTYPE_INVALID

} SYS_ChirpAPIFreqType_e;

///  Options for the chirp bandwidth input parameter for API BC_SYS_ProgramChirp
typedef enum
{
    ///  input BW param is the frequency bandwidth during acquisition (from end of tSettle to beginning of tJumpback)
    e_SYS_BWACQ = 0x00u,
    ///  input BW param is the frequency bandwidth during the full ramp (from beginning of tSettle to end of tJumpback
    e_SYS_BWFULLRAMP = 0x01u,
    e_SYS_BWTYPE_INVALID
} SYS_ChirpAPIBWType_e;

///  Choices of different golden run cases,
typedef enum
{
    e_SYS_GOLDENRUN_SINGLEPROFILE = 0x00u,
    e_SYS_GOLDENRUN_TDMA_MIMO = 0x01u,
    e_SYS_GOLDENRUN_CW = 0x02u,
    e_SYS_GOLDENRUN_MS_TDMA_MIMO = 0x03u,
    e_SYS_GOLDRUNTYPE_INVALID
} SYS_GoldenRunType_e;

///  ADC sample mode options
typedef enum
{
    e_SYS_ADC80MSPS_FUNCTIONAL = 0x00u,
    e_SYS_ADC80MSPS_DEBUG = 0x01u,
    e_SYS_ADC40MSPS_LEGACY = 0x02u,
    e_SYS_ADCSAMPLEMODE_INVALID
} SYS_ADCSamplingMode_e;

///  Analog Test Bus(ATB)  available sources
typedef enum
{
    e_SYS_ATBAC_MCLK2G4OUT = 0x00u,
    e_SYS_ATBAC_MCLK4G8IN = 0x01u,
    e_SYS_ATBAC_ADC12IN = 0x02u,
    e_SYS_ATBAC_ADC34IN = 0x03u,
    e_SYS_ATBAC_RX1IF = 0x04u,
    e_SYS_ATBAC_RX2IF = 0x05u,
    e_SYS_ATBAC_RX3IF = 0x06u,
    e_SYS_ATBAC_RX4IF = 0x07u,
    e_SYS_ATBAC_SSBIN = 0x08u,
    e_SYS_ATBAC_VTUNE = 0x09u,
    e_SYS_ATBACSRC_INVALID
} SYS_ATBACSrc_e;

///  These errors can be introduced in system by setting max and min values in corresponding module registers and verified by checking corresponding error status in ISM
typedef enum
{
    e_SYS_TX1_RF_LEVEL_MAX_ERR = 0x00u,
    e_SYS_TX2_RF_LEVEL_MAX_ERR = 0x01u,
    e_SYS_TX3_RF_LEVEL_MAX_ERR = 0x02u,
    e_SYS_TX1_RF_LEVEL_MIN_ERR = 0x03u,
    e_SYS_TX2_RF_LEVEL_MIN_ERR = 0x04u,
    e_SYS_TX3_RF_LEVEL_MIN_ERR = 0x05u,
    e_SYS_TX1_PR_ERR = 0x06u,
    e_SYS_TX2_PR_ERR = 0x07u,
    e_SYS_TX3_PR_ERR = 0x08u,
    e_SYS_RX1_LO_LEVEL_MAX_ERR = 0x09u,
    e_SYS_RX2_LO_LEVEL_MAX_ERR = 0x0Au,
    e_SYS_RX3_LO_LEVEL_MAX_ERR = 0x0Bu,
    e_SYS_RX4_LO_LEVEL_MAX_ERR = 0x0Cu,
    e_SYS_RX1_LO_LEVEL_MIN_ERR = 0x0Du,
    e_SYS_RX2_LO_LEVEL_MIN_ERR = 0x0Eu,
    e_SYS_RX3_LO_LEVEL_MIN_ERR = 0x0Fu,
    e_SYS_RX4_LO_LEVEL_MIN_ERR = 0x10u,
    e_SYS_LOI_LEVEL_MAX_ERR = 0x11u,
    e_SYS_LOI_LEVEL_MIN_ERR = 0x12u,
    e_SYS_MCLK_PLL_LOCK_ERR = 0x13u,
    e_SYS_MCLK_PLL_LEVEL_ERR = 0x14u,
    e_SYS_MCLK_DIG_OUTPUT_FREQ_ERR = 0x15u,
    e_SYS_MCLK_MSPC_ERR = 0x16u,
    e_SYS_PR_CALIB_TIMEOUT_ERR = 0x17u,
    e_SYS_AAFC_CALIB_TIMEOUT_ERR = 0x18u,
    e_SYS_AAFC_DIGITAL_ERR = 0x19u,
    e_SYS_CHIRP_INTERFACE_STUCKAT_ERR = 0x1Au,
    e_SYS_VCO_FREQ480_ERR = 0x1Bu,
    e_SYS_VCO_LEVEL_MAX_ERR = 0x1Cu,
    e_SYS_VCO_LEVEL_MIN_ERR = 0x1Du,
    e_SYS_CHIRP_PLL_LOCK_ERR = 0x1Eu,
    e_SYS_CHIRP_DIGITAL_LOCKSTEP_ERR = 0x1Fu,
    e_SYS_ADC1_CALIBRATION_ERR = 0x20u,
    e_SYS_ADC2_CALIBRATION_ERR = 0x21u,
    e_SYS_ADC3_CALIBRATION_ERR = 0x22u,
    e_SYS_ADC4_CALIBRATION_ERR = 0x23u,
    e_SYS_INJECT_ERR_INVAILD
} SYS_InjectErrors_e;

/// Options to keep current subband, forcing a subband and searching of subbands using different methods
typedef enum
{
    ///  keep current subband selection in registers
    e_SYS_SBSEARCH_KEEP_CURRENT = 0x00,
    ///  manually force a subband
    e_SYS_SBSEARCH_FORCE = 0x01,
    ///  AAFC Full Autonomous calibration: use AAFC hardware to perform full automatic search for a subband.
    e_SYS_SBSEARCH_AAFC_AUTO = 0x02,
    ///  AAFC SPI triggered subband calibration: use AAFC hardware, but need SPI command to trigger subband search. This is suitable for using multiple profiles with different subband (indicating different chirp frequency settings)
    e_SYS_SBSEARCH_AAFC_SPI_TRIG = 0x03,
    ///  use Dolphin legacy method, to use software to search from the full VCO subband table for a suitable subband. This requires a valid VCO subband table. @see BC_CAFC_GenSBTable
    e_SYS_SBSEARCH_SW_ASSIST = 0x04,
    e_SYS_SBSEARCH_INVALID
} SYS_SBSearchMethod_e;

///  2 ADC combination for 80MSPS debug mode
typedef enum
{
    e_SYS_ADC1_ADC2 = 0x00u,
    e_SYS_ADC3_ADC4 = 0x01u,
    e_SYS_ADC1_ADC3 = 0x02u,
    e_SYS_ADC1_ADC4 = 0x03u,
    e_SYS_ADC2_ADC3 = 0x04u,
    e_SYS_ADC2_ADC4 = 0x05u,
    e_SYS_ADCCOMBI_INVALID
} SYS_80MSPSADCCombi_e;

///  ADC enable control for 40MSPS
typedef enum
{
    e_SYS_ADCx0 = 0x01u,
    e_SYS_ADCx1 = 0x02u,
    e_SYS_ADC_INVALID
} SYS_40MSPSADCCtrl_e;

/**  AAFC and TX PR calibration frequency modes
In SC, the following bits in N_START_RF_CAL_CENTER_FREQ_SEL are important for AAFC search

A: cal_frequency_chirp_tx_sel: main frequency mode selection for AAFC/TX calibration
B: cal_frequency_chirp_tx_calc_mode
C: tx_cal_open_close_loop_sel: control CAFC PLL loop mode for TX PR calibration. 0:open loop, 1:close loop

Note: AAFC is always done in open loop mode.
Note: MDes is only used in AAFC calibration, this field is in CAFC.

Recommended setting table

|A   |B   |C   |Description|
|--- |--- |--- |
|00  |0   |1   |fstart for AAFC, fstart for TX; AAFC open, TX PR closed loop; fstart is specified by N_START_RF_PROFILEx, MDes must be programmed manually by user in CAFC |
|01  |0   |1   |fcenter for AAFC, fcenter for TX; AAFC open, TX PR closed loop; fcenter is specified by N_START_RF_CAL_CENTER_FREQ (divider value), MDes must be programmed manually by user in CAFC. |
|10  |0   |1   |fstart for AAFC, fcenter for TX; AAFC open, TX PR closed loop; fstart (for CAFC cal) is specified by N_START_RF_PROFILEx (divider value), MDes must be programmed manually by user in CAFC. fcenter(for TX cal use only) is specified by N_START_RF_CAL_CENTER_FREQ (divider value). |
|00  |1   |1   |fstart for AAFC, fstart for TX; AAFC open, TX PR closed loop; fstart is specified by N_START_RF_PROFILEx (divdier value), MDes is calculated by HW automatically |
|01  |1   |1   |fcenter for AAFC, fcenter for TX; AAFC open, TX PR closed loop; fcenter is specified by automatic HW calculation, using N_START_RF_PROFILEx, DN_CHIRP and N_STEP_CHIRP. MDes is also calculated by fcenter result. |
|10  |1   |1   |fstart for AAFC, fcenter for TX; AAFC open, TXPR closed loop; fstart (for CAFC cal) is specified by N_START_RF_PROFILEx (divier value), MDes is calculated by HW. fcenter (for TX cal) is specified by automatic HW calculation, using N_START_RF_PROFILEx, DN_CHIRP and N_STEP_CHIRP.|

*/

typedef enum
{
    e_SYS_CAFCTX_FS_CLOSE_MAN = 0x00u,
    e_SYS_CAFCTX_FC_CLOSE_MAN = 0x01u,
    e_SYS_CAFCFS_TXFC_CLOSE_MAN = 0x02u,
    e_SYS_CAFCTX_FS_CLOSE_AUTO = 0x03u,
    e_SYS_CAFCTX_FC_CLOSE_AUTO = 0x04u,
    e_SYS_CAFCFS_TXFC_CLOSE_AUTO = 0x05u,
    e_SYS_CAFCTX_CALMODE_INVALID
} SYS_CAFCTXCalFreqMode_e;

///  Rx LPF frequency coarse setting
typedef enum
{
    e_SYS_RXLPF_12P5MHZ = 0x00u,
    e_SYS_RXLPF_15MHZ = 0x01u,
    e_SYS_RXLPF_20MHZ = 0x02u,
    e_SYS_RXLPF_25MHZ = 0x03u,
    e_SYS_RXLPF_WIDE = 0x04u,
    e_SYS_RXLPF_INVALID
} SYS_RXLPF_CornerFreq_e;

///  Rx HPF frequency setting
typedef enum
{
    e_SYS_RXHPF_100KHZ = 0x00u,
    e_SYS_RXHPF_200KHZ = 0x01u,
    e_SYS_RXHPF_300KHZ = 0x02u,
    e_SYS_RXHPF_400KHZ = 0x03u,
    e_SYS_RXHPF_800KHZ = 0x04u,
    e_SYS_RXHPF_1600KHZ = 0x05u,
    e_SYS_RXHPF_3200KHZ = 0x06u,
    e_SYS_RXHPF_INVALID
} SYS_RXHPF_CornerFreq_e;

/// To choose from Central Control: PON, Clock Enable, Reset and Functional Reset.
typedef enum
{
    e_CC_PON = 0x00u,
    e_CC_CLKEN = 0x01u,
    e_CC_RST = 0x02u,
    e_CC_FUNCRST = 0x03u,
    e_CC_CMD_INVALID
} CC_PonClkRst_e;

///  External Pin speed control
typedef enum
{
    // 12.5MHz
    e_CC_PADSPEED_LOW = 0x00u,
    // 25MHz
    e_CC_PADSPEED_NORMAL = 0x01u,
    // 50MHz
    e_CC_PADSPEED_FAST = 0x02u,
    // 80MHz
    e_CC_PADSPEED_HIGH = 0x03u,
    e_CC_PADSPEED_INVALID
} CC_PINSpeed_e;

///  Enable, disable or clear interrupt
typedef enum
{
    e_CC_ENABLE_INT = 0x00u,
    e_CC_DISABLE_INT = 0x01u,
    e_CC_CLEAR_INT = 0x02u,
    e_CC_CMDEN_INVALID
} CC_CmdEnClrInt_e;

///  Dynamic power mode options
typedef enum
{
    e_CC_DYN_POWMODE_NONE = 0x00u,
    ///  Dynamic powerdown of IP's between chirp sequence controlled by central control
    e_CC_DYN_POWMODE_PERSEQUENCE = 0x01u,
    /// Dynamic powerdown of IP's between individual chirps controlled by central control
    e_CC_DYN_POWMODE_PERCHIRP = 0x02u,
    e_CC_DYN_POWMODE_INVALID = 0x03u
} CC_DynPowMode_e;

///  Serialiser Interface type
typedef enum
{
    e_CC_MIPI = 0x01,
    e_CC_LVDS = 0x02,
    e_CC_INTERFACE_INVALID
} CC_InterfaceType_e;

///  To choose from Central Control RMS cal ATB options.
typedef enum
{
    e_CC_VDDA_1v1 = 0x01u,
    e_CC_VDDA_1v8 = 0x02u,
    e_CC_VDDD = 0x03u,
    e_CC_CLK_AMP = 0x04u,
    e_CC_RMS_OUT = 0x05u,
    e_CC_VG_SENSE = 0x06u,
    e_CC_ATBRMSCAL_INVALID
} CC_ATBRMSCal_e;

///  Validation signal group for PIN MUX
typedef enum
{
    e_CC_TX_VALIDATION_SIGNAL = 0x01,
    e_CC_RX_VALIDATION_SIGNAL = 0x02,
    e_CC_TE_VALIDATION_SIGNAL = 0x03,
    e_CC_MASTERFLAG_VALIDATION_SIGNAL = 0x04,
    e_CC_RF_POWDOWN_VALIDATION_SIGNAL = 0x05,
    e_CC_MC_VALIDATION_SIGNAL = 0x06,
    e_CC_STATUS_FLAG_VALIDATION_SIGNAL = 0x07
    // This does not have the invalid since any other value 1 to 5 is considered  as Status Flag Val Signal
} CC_ValGroup_e;

/**
LVDS digital data interface test data pattern modes.
When e_LVDS_TESTMODE_FIXEDDATA is chosen, user can set a desired 12-bit data pattern.
When e_LVDS_TESTMODE_PRBS is chosen,   PRBS initial value is required to set,
*/
typedef enum
{
    e_LVDS_TESTMODE_FIXEDDATA = 0x00u,
    e_LVDS_TESTMODE_SINEWAVE = 0x01u,
    e_LVDS_TESTMODE_SAWTOOTH = 0x02u,
    e_LVDS_TESTMODE_PRBS = 0x03u,
    e_LVDS_TESTMODE_INVALID
} LVDS_TestMode_e;

///  Frequency counter deviation
typedef enum
{
    ///  Zeroth bit is ignored from comparison
    e_LVDS_IGNORE_0_BIT = 0x01u,

    ///  Zeroth and first bits are ignored from comparison
    e_LVDS_IGNORE_0_TO_1_BITS = 0x03u,

    ///  Zeroth to second bits are ignored from comparison
    e_LVDS_IGNORE_0_TO_2_BITS = 0x07u,

    ///  Zeroth to third bits are ignored from comparison
    e_LVDS_IGNORE_0_TO_3_BITS = 0x0Fu,
    e_LVDS_IGNORE_INVALID
} LVDS_Feq_Dev_e;

///  Sampling pulse shift control
typedef enum
{
    ///  Sampling pulse is right shifted by two 480/600 clocks
    e_LVDS_SAMPPULSE_SHIFT_BY_2 = 0x00u,
    ///  Sampling pulse is right shifted by three 480/600 clocks
    e_LVDS_SAMPPULSE_SHIFT_BY_3 = 0x01u,
    ///  Sampling pulse is right shifted by four 480/600 clocks
    e_LVDS_SAMPPULSE_SHIFT_BY_4 = 0x02u,
    ///  Sampling pulse is right shifted by five 480/600 clocks
    e_LVDS_SAMPPULSE_SHIFT_BY_5 = 0x03u,
    ///  Sampling pulse is right shifted by six 480/600 clocks
    e_LVDS_SAMPPULSE_SHIFT_BY_6 = 0x04u,
    ///  Sampling pulse is right shifted by seven 480/600 clocks
    e_LVDS_SAMPPULSE_SHIFT_BY_7 = 0x05u,
    ///  Sampling pulse is right shifted by eight 480/600 clocks
    e_LVDS_SAMPPULSE_SHIFT_BY_8 = 0x06u,
    ///  Sampling pulse is right shifted by nine 480/600 clocks
    e_LVDS_SAMPPULSE_SHIFT_BY_9 = 0x07u,
    e_LVDS_SAMPPULSE_SHIFT_INVALID
} LVDS_SamPulseShift_e;

///  LVDS data valid delay control
typedef enum
{
    e_LVDS_DVALID_NODELAY = 0x00u,
    e_LVDS_DVALID_1CLKDELAY = 0x01u,
    e_LVDS_DVALID_2CLKDELAY = 0x02u,
    e_LVDS_DVALID_3CLKDELAY = 0x03u,
    e_LVDS_DVALID_INVALID
} LVDS_DValidDelayCtrl_e;

///  LVDS internal nodes for ATB
typedef enum
{
    e_LVDS_NODE_RESET = 0x00u,
    e_LVDS_NODE_SUPPLY1V1_CSI2 = 0x01u,
    e_LVDS_NODE_SUPPLY1V1_SER = 0x02u,
    e_LVDS_NODE_SUPPLY1V8 = 0x03u,
    e_LVDS_NODE_LVDSVAR = 0x04u,
    e_LVDS_NODE_CSI2LDO = 0x05u,
    e_LVDS_NODE_SERLDO = 0x06u,
    e_LVDS_NODE_SUPPLYIO_1v8_3v3 = 0x07u,
    e_LVDS_NODE_SUPPLY_LVDS_3v3 = 0x08u,
    e_LVDS_NODE_SPARE2 = 0x09u,
    e_LVDS_NODE_SPARE3 = 0x0Au,
    e_LVDS_NODE_INVALID
} LVDS_ATBNodes_e;

///  LVDS MFIO speed selection
typedef enum
{
    e_LVDS_MFIO_20MHZ = 0x00u,
    e_LVDS_MFIO_40MHZ = 0x01u,
    e_LVDS_MFIO_85MHZ = 0x02u,
    e_LVDS_MFIO_125MHZ = 0x03u,
    e_LVDS_MFIO_INVALID
} LVDS_MFIOSpeed_e;

///  LVDS Decimation modes
typedef enum
{
    /// No decimation
    e_LVDS_DECIMATION_BYPASS = 0x00,
    /// Decimation by 2
    e_LVDS_DECIMATION_MODE1 = 0x01,
    /// Decimation by 4
    e_LVDS_DECIMATION_MODE2 = 0x02,
    /// Decimation by 8
    e_LVDS_DECIMATION_MODE3 = 0x03,
    /// Decimation by 16
    e_LVDS_DECIMATION_MODE4 = 0x04,
    e_LVDS_DECIMATION_INVALID
} LVDS_DecimationModes_e;

///  LVDS clock edge selection
typedef enum
{
    e_LVDS_CLK_EDGE_BOTH = 0x00u,
    e_LVDS_CLK_EDGE_POS = 0x01u,
    e_LVDS_CLK_EDGE_NEG = 0x02u,
    e_LVDS_CLK_EDGE_INVALID
} LVDS_ClkEdgeSel_e;

///  LVDS ADC clock selection
typedef enum
{
    /// All the ADC clocks are OR-ed together
    e_LVDS_ADCCLK_FROM_ALL = 0x00u,
    /// Select adc1 clock
    e_LVDS_ADCCLK_FROM_ADC_1 = 0x01u,
    /// Select adc2 clock
    e_LVDS_ADCCLK_FROM_ADC_2 = 0x02u,
    /// Select adc3 clock
    e_LVDS_ADCCLK_FROM_ADC_3 = 0x03u,
    /// Select adc4 clock
    e_LVDS_ADCCLK_FROM_ADC_4 = 0x04u,
    /// OR adc1 & adc3 clocks
    e_LVDS_ADCCLK_FROM_ADC_1_3 = 0x05u,
    /// OR adc2 & adc4 clocks
    e_LVDS_ADCCLK_FROM_ADC_2_4 = 0x06u,
    /// OR adc1 & adc4 clocks
    e_LVDS_ADCCLK_FROM_ADC_1_4 = 0x07u,
    e_LVDS_ADCCLK_FROM_INVALID
} LVDS_ADCClockSel_e;

///  MIPI interface data rate
typedef enum
{
    e_MIPI_DATARATE_480 = 0x00u,
    e_MIPI_DATARATE_240 = 0x01u,
    e_MIPI_DATARATE_120 = 0x02u,
    e_MIPI_DATARATE_INVALID
} MIPI_DataRate_e;

/**
MIPI digital data interface test data pattern modes.
When e_MIPI_TESTMODE_FIXEDDATA is chosen, user can set a desired 12-bit data pattern.
When e_MIPI_TESTMODE_PRBS is chosen,  PRBS initial value is required to set,
*/
typedef enum
{
    e_MIPI_TESTMODE_FIXEDDATA = 0x00u,
    e_MIPI_TESTMODE_SINEWAVE = 0x01u,
    e_MIPI_TESTMODE_SAWTOOTH = 0x02u,
    e_MIPI_TESTMODE_PRBS = 0x03u,
    e_MIPI_TESTMODE_INVALID
} MIPI_TestMode_e;

/**  Frequency counter deviation
  while comparing the final freq counter read value number of lsb bits to be ignored.
*/

typedef enum
{
    // Zeroth bit is ignored from comparison
    e_MIPI_IGNORE_ZEROTH_BIT = 0x01u,
    // Zeroth & first bits are ignored from comparison
    e_MIPI_IGNOR_ZERO_ONE_BITS = 0x03u,
    // Zeroth & first & second bits are ignored from comparison
    e_MIPI_IGNOR_ZERO_ONE_TWO_BITS = 0x07u,
    // Zeroth & first & second & third bits are ignored from
    e_MIPI_IGNOR_ZERO_ONE_TWO_THREE_BITS = 0x0Fu,
    e_MIPI_IGNORE_BITS_INVALID
} MIPI_FreqCountDeviation_e;

///  Clear Chirp Number option for MIPI packets
typedef enum
{
    e_MIPI_CHIRPNUM_CLEAR_EVERY_SEQUENCE = 0x00u,
    e_MIPI_CHIRPNUM_CLEAR_NOW = 0x01u,
    e_MIPI_NO_CLEAR = 0x02u,
    e_MIPI_CHIRPNUM_CLEAR_INVALID
} MIPI_ClearChirpNum_e;

///  MIPI internal nodes for ATB
typedef enum
{
    e_MIPI_NODE_RESET = 0x00u,
    e_MIPI_NODE_SUPPLY1V1_CSI2 = 0x01u,
    e_MIPI_NODE_SUPPLY1V1_SER = 0x02u,
    e_MIPI_NODE_SUPPLY1V8 = 0x03u,
    e_MIPI_NODE_LVDSVAR = 0x04u,
    e_MIPI_NODE_CSI2LDO = 0x05u,
    e_MIPI_NODE_SERLDO = 0x06u,
    e_MIPI_NODE_SUPPLYIO_1v8_3v3 = 0x07u,
    e_MIPI_NODE_SUPPLY_MIPI_3v3 = 0x08u,
    e_MIPI_NODE_SPARE2 = 0x09u,
    e_MIPI_NODE_SPARE3 = 0x0Au,
    e_MIPI_NODE_INVALID
} MIPI_ATBNodes_e;

///  Phase Code generation modes
typedef enum
{
    ///  No change to initial phase code
    e_TE_PR_NO_CHANGE = 0x00u,
    ///  Replace two MSB bits of initial phase code with the QPSK[1:0] bits
    e_TE_PR_REPLACE_MSB_WITH_QPSK = 0x01u,
    ///  Add the QPSK[1:0] bits to two MSB bits of initial phase code
    e_TE_PR_ADD_QPSK_TO_MSB = 0x02u,
    e_TE_PR_INVALID
} TE_PRPCGenMode_e;

///  DDMA mode selection
typedef enum
{
    ///  DDMA is disabled
    e_TE_DDMA_DISABLED = 0x00u,
    ///  DDMA functional mode i.e., phase code step is incremented every chirp basis
    e_TE_DDMA_FUN_MODE = 0x01u,
    ///  DDMA test mode i.e., phase code is incremented at every clock cycle of 40MHz
    e_TE_DDMA_TEST_MODE = 0x02u,

    ///  DDMA test mode with non-chirp mode (CW)
    e_TE_DDMA_TEST_NOCHIRP = 0x03u,
    e_TE_DDMA_INVALID
} TE_DDMAMod_e;

/// Ready Interrupt Mode
typedef enum
{
    /// Ready interrupt at end of a  sequence
    e_TE_READYINT_END_OF_SEQ = 0x00u,
    /**Interrupt at end of expiry of the chirp_sequence_interval_timer.
   # Note
  If the chirp sequence interval is less than data acquisition time, then do not use this option*/
    e_TE_READYINT_SYS_CYCLE = 0x01u,

    ///  Interrupt at end of every chirp
    e_TE_READYINT_EVERY_CHIRP = 0x02u,
    e_TE_READYINT_INVALID
} TE_ReadyIntMode_e;

///  Chirp start out behavior (master slave mode)
typedef enum
{
    ///  Chirp start toggles once per chirp sequence
    e_TE_CSTOGGLE_ONCE_CHIRP_SEQ = 0x00u,
    ///  Chirp start toggles for every chirp
    e_TE_CSTOGGLE_EVERY_CHIRP = 0x01u,
    ///   Chirp start follows master's internal chirp start
    e_TE_CSTOGGLE_FOLLOW_MASTER = 0x02u,
    e_TE_CSTOGGLE_INVALID
} TE_CSToggleMode_e;

///  Chirp trigger mode
typedef enum
{
    ///  SPI trigger mode
    e_TE_CH_TRG_SPI_TRIGGER = 0x00u,
    /// Ext. trigger mode with single trigger
    e_TE_CH_TRG_EXT_SINGLE_TRG = 0x01u,
    /// Ext. trigger mode with trigger for every chirp
    e_TE_CH_TRG_EXT_EVERY_CHRIP = 0x03u,
    e_TE_CH_TRG_INVALID
} TE_ChirpTrigMode_e;

///  Chirp start in functionality selection
typedef enum
{
    ///  Interrupt events based on the ready_int_mode_sel field
    e_TE_CSIN_INT_EVENT = 0x00u,
    ///  Chirp start trigger based on the sel_mode_for_chirp_start_out field
    e_TE_CSIN_BASEDON_CS_OUT = 0x01u,
    ///  Chirpt signal indicating busy/silent period of the chirp
    e_TE_CSIN_STATUS_BUSY_SILENT = 0x02u,
    e_TE_CSIN_INVALID
} TE_CSINFunSel_e;

///  Chirp start out functionality selection
typedef enum
{
    ///  Interrupt events based on the ready_int_mode_sel field
    e_TE_CSOUT_INT_EVENT = 0x00u,
    ///  Chirp start trigger based on the sel_mode_for_chirp_start_out field
    e_TE_CSOUT_BASEDON_CS_OUT = 0x01u,
    ///  Chirpt signal indicating busy/silent period of the chirp
    e_TE_CSOUT_STATUS_BUSY_SILENT = 0x02u,
    e_TE_CSOUT_INVALID
} TE_CSOUTFunSel_e;

///  CSI2 Frame mode selection
typedef enum
{
    ///  CSI2 frame deactivation at end of a sequence
    e_TE_CSI2_DEACT_ENDOF_SEQ = 0x00u,
    ///  CSI2 frame deactivation at the end of burst (multiple sequence end)
    e_TE_CSI2_DEACT_ENDOF_BURST = 0x01u,
    ///  CSI2 frame deactivation at end of every chirp
    e_TE_CSI2_DEACT_ENDOF_EVERYCHIRP = 0x02u,
    e_TE_CSI2_INVALID
} TE_CSI2FrameMode_e;

///  TE Output sample rate
typedef enum
{
    ///  Functional mode 80MSPS, non-fun mode 40MSPS
    e_TE_OSR_FUN80_NONF40 = 0x00u,
    ///  Functional mode 40MSPS, non-fun mode 20MSPS
    e_TE_OSR_FUN40_NONF20 = 0x01u,
    ///  Functional mode 20MSPS, non-fun mode 10MSPS
    e_TE_OSR_FUN20_NONF10 = 0x02u,
    ///  Functional mode 10MSPS, non-fun mode 5MSPS
    e_TE_OSR_FUN10_NONF5 = 0x03u,
    ///  Functional mode 5MSPS, non-fun mode 2.5MSPS
    e_TE_OSR_FUN5_NONF2P5 = 0x04u,
    e_TE_OSR_INVALID
} TE_OutputSampRate_e;

///  Control signal to select the operation mode
typedef enum
{
    e_SC_DITHER_MODE = 0x00u,
    e_SC_DRIFT_MODE = 0x01u,
    e_SC_COMBINED_MODE = 0x02u,
    e_SC_INACTIVE_MODE = 0x03u
} SC_StartFreqDitherMode_e;

///  Control signal to set the number of dither levels.
typedef enum
{
    e_SC_TWO_LEVLES = 0x00u,
    e_SC_FOUR_LEVLES = 0x01u,
    e_SC_EIGHT_LEVLES = 0x02u,
    e_SC_SIXTEEN_LEVLES = 0x03u
} SC_DitherLevels_e;

///  Chirp PLL VCO Bandwidth options, there are physically two VCOs in Dolphin plus CAFC.
typedef enum
{
    ///  1GHz VCO
    e_CAFC_1GBAND = 0x00,
    ///  5GHz VCO, working in 2GHz bandwidth mode
    e_CAFC_5GNARROW = 0x01,
    ///  5GHz VCO, working in 4GHz bandwidth mode
    e_CAFC_5GWIDE = 0x02,
    e_CAFC_VCOBWSEL_INVALID
} CAFC_VCOBWSel_e;

///  CAFC PLL loop filter LUT type options
typedef enum
{
    e_CAFC_LPF_LUT_1G = 0x00,
    e_CAFC_LPF_LUT_5GNARROW = 0x01,
    e_CAFC_LPF_LUT_5GWIDE = 0x02,
    e_CAFC_LPF_LUT_USER1 = 0x03,
    e_CAFC_LPF_LUT_USER2 = 0x04,
    e_CAFC_LPF_LUT_INVALID
} CAFC_LoopFilterLUTSel_e;

///  CAFC ATB internal nodes
typedef enum
{
    e_CAFC_NODE_RESET = 0x00u,
    e_CAFC_NODE_LEVEL_VCO_MIN = 0x01u,
    e_CAFC_NODE_LEVEL_VCO_LOW = 0x02u,
    e_CAFC_NODE_LEVEL_VCO_HIG = 0x03u,
    e_CAFC_NODE_LEVEL_VCO_MA = 0x04u,
    e_CAFC_NODE_RMS_DET_RE = 0x05u,
    e_CAFC_NODE_RMS_DET = 0x06u,
    e_CAFC_NODE_TEMP_SNS_BUFFE = 0x07u,
    e_CAFC_NODE_TEMP_SNS_COM = 0x08u,
    e_CAFC_NODE_VCO_IBIAS = 0x09u,
    e_CAFC_NODE_VCO_IND_CNT_TAP_1G = 0x0Au,
    e_CAFC_NODE_VCO_IND_CNT_TAP_5G = 0x0Bu,
    e_CAFC_NODE_VTUNE_LEVEL_HIGH = 0x0Cu,
    e_CAFC_NODE_VTUNE_LEVEL_LOW = 0x0Du,
    e_CAFC_NODE_LDO_DIVIDER_VDD = 0x0Eu,
    e_CAFC_NODE_LDO_CPPFD_VDD = 0x0Fu,
    e_CAFC_NODE_LDO_VCO_VDD = 0x10u,
    e_CAFC_NODE_VDD_PLL_1V8 = 0x11u,
    e_CAFC_NODE_VDD_VCO_1V8 = 0x12u,
    e_CAFC_NODE_IBIAS_CP_150U = 0x13u,
    e_CAFC_NODE_IBIAS_REF_100U = 0x14u,
    e_CAFC_NODE_VDD_PLL_1V1 = 0x15u,
    e_CAFC_NODE_INVALID
} CAFC_ATBNodes_e;

///  GS signal options for pll_gs_ctrl
typedef enum
{
    ///  GS driven Low - GS disabled, PLL bandwidth low
    e_CAFC_GSFIXEDLOW = 0x00u,
    ///  GS driven High - GS enabled, PLL bandwidth high
    e_CAFC_GSFIXEDHIGH = 0x01u,
    ///  pass the generated GS
    e_CAFC_NORMALGS = 0x02u,
    ///  inverted generated GS
    e_CAFC_NORMALGSINV = 0x03u,
    e_CAFC_GSOPTION_INVALID
} CAFC_GSManualCtrl_e;

///  GS and CPSlice switching signal selection options for pll_lpf_cap_gs_sel_ctrl and pll_cp_slice_ctrl
typedef enum
{
    ///  GS from TE
    e_CAFC_GSFROMTE = 0x00u,
    ///  GS synchronized with PLL UP pulse
    e_CAFC_GSFROMPLLUP = 0x01u,
    ///  // GS synchronized with PLL DN pulse
    e_CAFC_GSFROMPLLDN = 0x02u,
    e_CAFC_FRSEL_INVALID
} CAFC_FastResetSigSel_e;

///  Current injection signal options, used for pll_dac_inj_acq_ctrl and pll_dac_inj_rst_ctrl
typedef enum
{
    ///   dac_inj_acq/rst driven Low - timing engine not used (static case)
    e_CAFC_INJFIXEDLOW = 0x00u,
    ///   dac_inj_acq/rst driven High- timing engine not used (static case)
    e_CAFC_INJFIXEDHIGH = 0x01u,
    ///  pass the generated INJ signal from TE
    e_CAFC_NORMALINJ = 0x02u,
    ///  inverted generated INJ signal from TE
    e_CAFC_NORMALINJINV = 0x03u,
    e_CAFC_INJOPTION_INVALID
} CAFC_INJManualCtrl_e;

///  CAFC AAC cycle time of amplitude increment/decrement. Options > 1000ns is recommended.
typedef enum
{
    e_CAFC_AACTREF_200NS = 0x00,
    e_CAFC_AACTREF_400NS = 0x01,
    e_CAFC_AACTREF_800NS = 0x02,
    e_CAFC_AACTREF_1600NS = 0x03,
    e_CAFC_AACTREF_3200NS = 0x04,
    e_CAFC_AACTREF_6400NS = 0x05,
    e_CAFC_AACTREF_INVALID
} CAFC_AACTRef_e;

///  AFC frequency counting period for divider VCO frequency
typedef enum
{
    e_CAFC_AFCTREF_50NS = 0x00,
    e_CAFC_AFCTREF_100NS = 0x01,
    e_CAFC_AFCTREF_200NS = 0x02,
    e_CAFC_AFCTREF_400NS = 0x03,
    e_CAFC_AFCTREF_800NS = 0x04,
    e_CAFC_AFCTREF_1600NS = 0x05,
    e_CAFC_AFCTREF_3200NS = 0x06,
    e_CAFC_AFCTREF_6400NS = 0x07,
    e_CAFC_AFCTREF_INVALID
} CAFC_AFCTRef_e;

/// AFC loop integrator  step limiter options, it will determine subband increment/decrement step. Default is e_CAFC_AFCSTEP_16
typedef enum
{
    e_CAFC_AFCSTEP_2 = 0x00,
    e_CAFC_AFCSTEP_4 = 0x01,
    e_CAFC_AFCSTEP_8 = 0x02,
    e_CAFC_AFCSTEP_16 = 0x03,
    e_CAFC_AFCSTEP_32 = 0x04,
    e_CAFC_AFCSTEP_64 = 0x05,
    e_CAFC_AFCSTEP_INVALID
} CAFC_AFCStepLim_e;

///  PLL LPF BW configuration selection for a profile
typedef enum
{
    e_CAFC_PLLLPF_CFG0 = 0x00u,
    e_CAFC_PLLLPF_CFG1 = 0x01u,
    e_CAFC_PLLLPF_CFG2 = 0x02u,
    e_CAFC_PLLLPF_CFG3 = 0x03u,
    e_CAFC_PLLLPF_INVALID
} CAFC_PLLLPFSel_e;

/// ADC background calibration mode
typedef enum
{
    /// Background calibration in between chirps
    e_ADC_BACKGROUNDCAL_BETWEENCHIRP = 0x01u,
    /// Background calibration in between chirp sequences
    e_ADC_BACKGROUNDCAL_BETWEENCHIRPSEQ = 0x02u,
    e_ADC_BACKGROUNDCAL_INVALID
} ADC_BackgroundCalMode_e;

/// ADC input MUX control
typedef enum
{
    /// Input MUX controlled by calibration engine
    e_ADC_INPUTMUX_CALIBRATION_ENGINE = 0x00u,
    /// Input MUX to fixed internal input
    e_ADC_INPUTMUX_INTERNAL = 0x01u,
    /// Input MUX to fixed external input
    e_ADC_INPUTMUX_EXTERNAL = 0x02u,
    /// Input MUX to reference input
    e_ADC_INPUTMUX_REFERENCE = 0x03u,
    e_ADC_INPUTMUX_INVALID
} ADC_InputMUX_Control_e;

/// ADC internal nodes for ATB
typedef enum
{
    e_ADC_NODE_1V8_SUPPLY = 0x00u,
    e_ADC_NODE_1V1_SUPPLY = 0x01u,
    e_ADC_NODE_1V1_SAFETY_SUPPLY = 0x02u,
    /// 0x3u is not used
    e_ADC_NODE_VREF_P = 0x04u,
    e_ADC_NODE_VREF_N = 0x05u,
    e_ADC_NODE_BOOTSTRAP_INPUT = 0x06u,
    e_ADC_NODE_PREAMP_A_OUTPUT = 0x07u,
    /// 0x8u, 0x9u is not used
    e_ADC_NODE_VSSA = 0x0Au,
    e_ADC_NODE_PREAMPS_BIAS_CURRENT = 0x0Bu,
    e_ADC_NODE_MAIN_DAC_BIAS_CURRENT = 0x0Cu,
    e_ADC_NODE_LOCAL_LDO_REF_CURRENT = 0x0Du,
    e_ADC_NODE_BGR_REF_CURRENT = 0x0Eu,
    e_ADC_NODE_RESET = 0x0Fu,
    e_ADC_NODE_INVALID
} ADC_ATBNodes_e;

///  ADC output down sampling mode
typedef enum
{
    e_ADC_OUTPUT_NODOWNSAMPLE = 0x00u,
    e_ADC_OUTPUT_DOWNSAMPLEBY2 = 0x01u,
    e_ADC_OUTPUT_DOWNSAMPLEBY4 = 0x02u,
    e_ADC_OUTPUT_DOWNSAMPLEBY8 = 0x03u,
    e_ADC_OUTPUT_DOWNSAMPLEBY216 = 0x04u,
    e_ADC_OUTPUT_DOWNSAMPLE_INVALID
} ADC_OutputDownSampleModes_e;

///  ADC output mux operation mode
typedef enum
{
    e_ADC_OUTPUTMUX_NORMAL = 0x00u,
    e_ADC_OUTPUTMUX_CONSTANT = 0x01u,
    e_ADC_OUTPUTMUX_COUNTER = 0x02u,
    e_ADC_OUTPUTMUX_COUNTERPLUSOFF = 0x03u,
    e_ADC_OUTPUTMUX_INVALID
} ADC_OutputMuxModes_e;

/// Global Bias internal nodes for ATB
typedef enum
{
    e_GBIAS_NODE_RESET = 0x00u,
    e_GBIAS_NODE_IREF_BGR_TEST = 0x01u,
    e_GBIAS_NODE_IREF_PTAT_TEST = 0x02u,
    e_GBIAS_NODE_IREF_LOCAL_LDO = 0x03u,
    e_GBIAS_NODE_VBANDGAP = 0x04u,
    e_GBIAS_NODE_VDDA_GLOBAL_BIAS = 0x05u,
    e_GBIAS_NODE_INVALID
} GBIAS_ATBNodes_e;

///  LOI internal nodes for ATB
typedef enum
{
    e_LOI_NODE_RESET = 0x00u,
    e_LOI_NODE_VREFB2_STG1 = 0x01u,
    e_LOI_NODE_VREFB2_STG2 = 0x02u,
    e_LOI_NODE_VDDD_SAFETY = 0x03u,
    e_LOI_NODE_VDDA_INTERFACE = 0x04u,
    e_LOI_NODE_IREFBG = 0x05u,
    e_LOI_NODE_PTAT = 0x06u,
    e_LOI_NODE_VREFB1 = 0x07u,
    ///  this signal is VREFB3 if ATB1 is selected. this signal is VREFLOIMAX if ATB2 is selected.
    e_LOI_NODE_ATB1_VREFB3_ATB2_VREFLOIMAX = 0x08u,
    ///  this signal is VREFB4 if ATB1 is selected. this signal is VREFLOIHIGH if ATB2 is selected.
    e_LOI_NODE_ATB1_VREFB4_ATB2_VREFLOIHIGH = 0x09u,
    ///  this signal is VREFMUX if ATB1 is selected. this signal is VREFLOILOW if ATB2 is selected.
    e_LOI_NODE_ATB1_VREFMUX_ATB2_VREFLOILOW = 0x0Au,
    ///  this signal is LEVELLOI if ATB1 is selected. this signal is VREFLOIMIN if ATB2 is selected.
    e_LOI_NODE_ATB1_LEVELLOI_ATB2_VREFLOIMIN = 0x0Bu,
    ///  this signal is VDDA1V8 if ATB1 is selected. this signal is VREFB3 if ATB2 is selected.
    e_LOI_NODE_ATB1_VDDA1V8_ATB2_VREFB3 = 0x0Cu,
    ///  this signal can only be selected if ATB2 is enabled.
    e_LOI_NODE_ATB2_VREFB4 = 0x0Du,
    ///  this signal can only be selected if ATB2 is enabled.
    e_LOI_NODE_ATB2_VREFMUX = 0x0Eu,
    ///  this signal can only be selected if ATB2 is enabled.
    e_LOI_NODE_ATB2_LEVELLOI = 0x0Fu,
    ///  this signal can only be selected if ATB2 is enabled.
    e_LOI_NODE_ATB2_VDDA1V8 = 0x10u,
    e_LOI_NODE_INVALID
} LOI_ATBNodes_e;

///  LOI B2 Gain select - Option to select whether HW LO calibration or gaincode based
typedef enum
{
    /// LOI B2 level setting if LUT mode is used
    e_LOI_GAIN_LUT = 0x00u,
    /// Direct 8 bit control for the gain_code
    e_LOI_GAIN_DIRECT = 0x01u,
    /// Calibration based gain code direct which is updated after every stage ofthe binary search.
    e_LOI_GAIN_CAL = 0x02u,
    e_LOI_GAIN_INVALID
} LOI_GainSel_e;

/// LOx3  gain code option to be used as common gain code for all TX
typedef enum
{
    /// TX calbration results min, max_or avg value
    e_LOI_TXGAIN_TX_LOX3_MINMAXAVG = 0x00u,
    /// Use TX code in bitfield tx_lox3_gain_ctrl
    e_LOI_TXGAIN_TX_LOX3_GAINCTRLREG = 0x01u,
    /// Use RX code in bitfield lox3_gain_ctrl
    e_LOI_TXGAIN_RX_LOX3_GAINCTRLREG = 0x02u,
    /// RX calbration results min, max_or avg value based on rx_lox3_min_max_avg_sel
    e_LOI_TXGAIN_RX_LOX3_MINMAXAVG = 0x03u,
    e_LOI_TXGAIN_LOX3_INVALID
} LOI_LOx3TXGainSel_e;

/// LOx3 RX Gain code option to to be used as common gain code for all RX
typedef enum
{
    /// RX calbration results min, max_or avg value
    e_LOI_RXGAIN_RX_LOX3_MINMAXAVG = 0x00u,
    /// Use RX code in bitfield lox3_gain_ctrl
    e_LOI_RXGAIN_RX_LOX3_GAINCTRLREG = 0x01u,
    /// Use TX code in bitfield tx_lox3_gain_ctrl
    e_LOI_RXGAIN_TX_LOX3_GAINCTRLREG = 0x02u,
    /// TX calbration results min, max_or avg value based on tx_lox3_min_max_avg_sel
    e_LOI_RXGAIN_TX_LOX3_MINMAXAVG = 0x03u,
    e_LOI_RXGAIN_LOX3_INVALID
} LOI_LOx3RXGainSel_e;

///  LOI LOx3 Gain Min Max Avg selection
typedef enum
{
    e_LOI_LOX3_MIN = 0x00u,
    e_LOI_LOX3_MAX = 0x01u,
    e_LOI_LOX3_AVG = 0x02u,
    e_LOI_LOX3_INVALID
} LOI_LOx3MinMaxAvg_e;

///  MCLK 40MHz clk input source selection
typedef enum
{
    e_MCLK_CLK40SRC_XTAL = 0x00u,
    e_MCLK_CLK40SRC_CLKINPIN = 0x01u,
    e_MCLK_CLK40SRC_AUTODETECT = 0x02u,
    e_MCLK_CLK40SRC_INVALID
} MCLK_Clk40Src_e;

///  MCLK 40MHz output (clk_out) internal source selection
typedef enum
{
    e_MCLK_CLK40OUTSRC_XTAL = 0x00u,
    e_MCLK_CLK40OUTSRC_CLKIN = 0x01u,
    e_MCLK_CLK40OUTSRC_MCLK40M = 0x02u,
    e_MCLK_CLK40OUTSRC_INVALID
} MCLK_Clk40OutSrc_e;

///  MCLK Master Slave Phase Calibration wait time in microsecond
typedef enum
{
    ///  1 microsecond wait time after Calibration is triggered
    e_MCLK_MSPC_WAITTIME_1US = 0x00u,
    ///  2 microsecond wait time after Calibration is triggered
    e_MCLK_MSPC_WAITTIME_2US = 0x01u,
    ///  4 microsecond wait time after Calibration is triggered
    e_MCLK_MSPC_WAITTIME_4US = 0x02u,
    ///  8 microsecond wait time after Calibration is triggered
    e_MCLK_MSPC_WAITTIME_8US = 0x03u,
    ///  16 microsecond wait time after Calibration is triggered
    e_MCLK_MSPC_WAITTIME_16US = 0x04u,
    ///  32 microsecond wait time after Calibration is triggered
    e_MCLK_MSPC_WAITTIME_32US = 0x05u,
    ///  64 microsecond wait time after Calibration is triggered
    e_MCLK_MSPC_WAITTIME_64US = 0x06u,
    ///  128 microsecond wait time after Calibration is triggered
    e_MCLK_MSPC_WAITTIME_128US = 0x07u,
    ///  Do not change the wait time
    e_MCLK_MSPC_WAITTIME_KEEP_CURRENT = 0x08u,
    e_MCLK_MSPC_WAITTIME_INVALID
} MCLK_MSPCWaitTime_e;

///  MCLK MSPC wait time for PLL skew step in microsecond
typedef enum
{
    ///  2.5 microsecond wait time after pll skew is programed
    e_MCLK_MSPC_PLLSKEW_WAITTIME_2p5US = 0x00u,
    ///  5 microsecond wait time after pll skew is programed
    e_MCLK_MSPC_PLLSKEW_WAITTIME_5US = 0x01u,
    ///  10 microsecond wait time after pll skew is programed
    e_MCLK_MSPC_PLLSKEW_WAITTIME_10US = 0x02u,
    ///  20 microsecond wait time after pll skew is programed
    e_MCLK_MSPC_PLLSKEW_WAITTIME_20US = 0x03u,
    ///  40 microsecond wait time after pll skew is programed
    e_MCLK_MSPC_PLLSKEW_WAITTIME_40US = 0x04u,
    ///  80 microsecond wait time after pll skew is programed
    e_MCLK_MSPC_PLLSKEW_WAITTIME_80US = 0x05u,
    ///  160 microsecond wait time after pll skew is programed
    e_MCLK_MSPC_PLLSKEW_WAITTIME_160US = 0x06u,
    ///  320 microsecond wait time after pll skew is programed
    e_MCLK_MSPC_PLLSKEW_WAITTIME_320US = 0x07u,
    ///   Do not change wait time for pll skew step
    e_MCLK_MSPC_PLLSKEW_WAITTIME_KEEP_CURRENT = 0x08u,
    e_MCLK_MSPC_PLLSKEW_WAITTIME_INVALID
} MCLK_MSPCSkewWaitTime_e;

///  MCLK MSPC wait time for set_delay step in nanosecond
typedef enum
{
    ///  100 nanosecond wait time after set_delay programed
    e_MCLK_MSPC_DELAY_WAITTIME_100NS = 0x00u,
    ///  200 nanosecond wait time after set_delay programed
    e_MCLK_MSPC_DELAY_WAITTIME_200NS = 0x01u,
    ///  400 nanosecond wait time after set_delay programed
    e_MCLK_MSPC_DELAY_WAITTIME_400NS = 0x02u,
    ///  800 nanosecond wait time after set_delay programed
    e_MCLK_MSPC_DELAY_WAITTIME_800NS = 0x03u,
    ///  do not change wait time
    e_MCLK_MSPC_DELAY_WAITTIME_KEEP_CURRENT = 0x04u,
    e_MCLK_MSPC_DELAY_WAITTIME_INVALID
} MCLK_MSPCDelayWaitTime_e;

///  MCLK Clk detector configuration
typedef enum
{
    ///
    e_MCLK_CLKDET_STARTUP_MODE = 0x00u,
    e_MCLK_CLKDET_STANDALONE_MODE = 0x01u,
    e_MCLK_CLKDET_LEADER_MODE = 0x02u,
    e_MCLK_CLKDET_FOLLOWER_MODE = 0x03,
    e_MCLK_CLKDET_INVALID_MODE
} MCLK_CLKDetMode_e;

/// MCLK internal nodes for ATB
typedef enum
{
    ///  XO NODES for only ATB1
    e_MCLK_XO_NODE_LDOREF_CURR = 0x0u,            ///  3'b000: 20uA LDO ref current  (atb1_0 = 0.33V, atb1_180 = 0V)
    e_MCLK_XO_NODE_LEVEL_DETC_VS_CMV = 0x1u,      ///  3'b001: level detector output signal vs common mode voltage (atb1_0 = 0.7V, atb1_180 = 0.44V)
    e_MCLK_XO_NODE_LDO_SM_TH_VS_CMV = 0x2u,       ///  3'b010: LDO supply safety monitor threshold vs common mode voltage (atb1_0 = 0.7V, atb1_180 = 0.53V)
    e_MCLK_XO_NODE_LEVEL_DETC_SMTH_VS_CMV = 0x3u, ///  3'b011: level detector safety monitor threshold vs common mode voltage (atb1_0 = 0.7V, atb1_180 = 0.26V)
    e_MCLK_XO_NODE_1V1_TRX_SUP_VS_CMV = 0x4u,     ///  3'b100: 1.1V TRX supply vs common mode voltage (atb1_0 = 0.7V, atb1_180 = 0.26V)
    e_MCLK_XO_NODE_1V1_TRX_SUP_VS_CMV_RED = 0x5u, ///  3'b101: 1.1V TRX supply vs common mode voltage (atb1_0 = 0.7V, atb1_180 = 0.26V)
    e_MCLK_XO_NODE_1V1_CORE_SUP_VS_CMV = 0x6u,    ///  3'b110: 1.1V core supply vs common mode voltage (atb1_0 = 0.7V, atb1_180 = 0.26V)
    e_MCLK_XO_NODE_1V8_SUP_VS_CMV = 0x7u,         ///  3'b111: 1.8V supply vs common mode voltage (atb1_0 = 0.71V, atb1_180 = 0.29V)
    ///  PLL NODES for only ATB2
    e_MCLK_PLL_NODE_VTUNE_REF_H = 0x10u,    ///  0x10: vtune_ref_h (0.9V), atb2_180 = 0V
    e_MCLK_PLL_NODE_VTUNE_REF_I = 0x11u,    ///  0x11: vtune_ref_l (0.2V), atb2_180 = 0V
    e_MCLK_PLL_NODE_SETPOINT = 0x12u,       ///  0x12: vco_setpoint (0.73V), atb2_180 is vref_peak_det (0.48V)
    e_MCLK_PLL_NODE_VCO_CAL_MAX = 0x13u,    ///  0x13: vco_cal_max (0.77V), atb2_180 is vco_setpoint (0.73V)
    e_MCLK_PLL_NODE_VCO_CAL_MIN = 0x14u,    ///  0x14: vco_cal_min (0.67V), atb2_180 is vco_setpoint (0.73V)
    e_MCLK_PLL_NODE_VCO_ERROR_MAX = 0x15u,  ///  0x15: vco_error_max (0.80V), atb2_180 is vco_setpoint (0.73V)
    e_MCLK_PLL_NODE_VCO_ERROR_MIN = 0x16u,  ///  0x16: vco_error_min (0.66V), atb2_180 is vco_setpoint (0.73V)
    e_MCLK_PLL_NODE_VCO_PEAK_DET = 0x17u,   ///  0x17: vco_peak_det (0.73V), atb2_180 is vref_peak_det (0.48V)
    e_MCLK_PLL_NODE_VCO_IBIAS_TEST = 0x18u, ///  0x18: vco_ibias_test (vco bias current): atb2_0 is 0.4V and atb2_180 is 0.4V when ctl_ana_test_bus_cur=1
    e_MCLK_PLL_NODE_VCO_CENTER_TAP = 0x19u, ///  0x19: vco_center_tap (0.62V), atb2_180 is 0V
    e_MCLK_PLL_NODE_VDD1V8 = 0x1Au,         ///  0x1A: vdd1v8/6 (0.3V), atb2_180 is 0V
    e_MCLK_PLL_NODE_OPEN = 0x1Bu,           ///  0x1B: open
    e_MCLK_PLL_NODE_DCBUS2 = 0x1Cu,         ///  0x1C: dcbus20u (current or voltage): atb2_0 is 0.33V and atb2_180 is 0V when ctl_ana_test_bus_cur=1
    e_MCLK_PLL_NODE_LDO1 = 0x1Du,           ///  0x1D: LDO1 (1v1_div) (atb2_0 is 0.3V and atb2_180 is 0V)
    e_MCLK_PLL_NODE_LDO2 = 0x1Eu,           ///  0x1E: LDO2 (1v1_cppfd) (atb2_0 is 0.3V and atb2_180 is 0V)
    e_MCLK_PLL_NODE_LDO3 = 0x1Fu,           ///  0x1F: LDO3 (1v1_vco) (atb2_0 is 0.3V and atb2_180 is 0V)
    ///  ATB1 and ATB2 common nodes
    e_MCLK_NODE_IREF_BG = 0x21u,         ///  8'h01: atb1_iref_bg
    e_MCLK_NODE_IREF_BGR = 0x22u,        ///  8'h02: atb1_iref_bgr
    e_MCLK_NODE_IREF_LOCAL_LDO = 0x23u,  ///  8'h03: atb1_iref_local_ldo
    e_MCLK_NODE_VDDA_1V8 = 0x24u,        ///  8'h04: atb1_vdda_1v8
    e_MCLK_NODE_VDDD_SAFETY_1V1 = 0x25u, ///  8'h05: atb1_vddd_safety_1v1
    e_MCLK_NODE_ATBNOTUSED = 0x26u,      ///  8'h06: not used
    e_MCLK_NODE_VDDA_1V1 = 0x27u,        ///  8'h07: atb1_vdda_1v1
    ///  MSPS ATB1 and ATB2 nodes
    e_MCLK_MSPC_NODE_DCBUS1_PFD_UP = 0x31u,   ///  8'h01: mspc_sel_dcbus1_pfd_up (selects change up signal to  ATB1/2)
    e_MCLK_MSPC_NODE_DCBUS1_PFD_DOWN = 0x32u, ///  8'h02: mspc_sel_dcbus1_pfd_down (selects charge down signal to ATB1/2)
    e_MCLK_MSPC_NODE_DCBUS1_CP_FORCE = 0x33u, ///  8'h03: mspc_sel_dcbus1_cp_force (selects charge pump force signal to ATB1/2)
    e_MCLK_MSPC_NODE_DCBUS1_COMP_OUT = 0x34u, ///  8'h04: mspc_sel_dcbus1_comp_out (selects comparator output to ATB1/2)
    e_MCLK_MSPC_NODE_DCBUS1_COMP_VTH = 0x35u, ///  8'h05: mspc_sel_dcbus1_comp_vth (selects comparator  threshold  to ATB1/2)
    e_MCLK_MSPC_NODE_DCBUS1_ICP_OUT = 0x36u,  ///  8'h06: mspc_sel_dcbus1_icp_out (selects charge pump output voltage to ATB1/2)
    e_MCLK_NODE_RESET = 0x37u,
    e_MCLK_NODE_INVALID
} MCLK_ATBNodes_e;

///  RX internal nodes for ATB
typedef enum
{
    e_RX_NODE_RESET = 0x00u,
    e_RX_NODE_VDDA_1V8 = 0x1u,
    e_RX_NODE_VDDA_1V1 = 0x2u,
    e_RX_NODE_VDDD_1V1 = 0x3u,
    e_RX_NODE_LEVEL_LO = 0x4u,
    ///  0x5u,0x6u,0x7u,0x8u can only be selected if ATB1 is enabled.
    e_RX_NODE_LEVEL_LO_HIGH = 0x5u,
    e_RX_NODE_LEVEL_LO_LOW = 0x6u,
    e_RX_NODE_LEVEL_LO_MIN = 0x7u,
    e_RX_NODE_LEVEL_LO_MAX = 0x8u,
    e_RX_NODE_IBIAS_BG = 0x9u,
    e_RX_NODE_IBIAS_PTAT = 0xAu,
    e_RX_NODE_IBIAS_PTAT_LNA = 0xBu,
    e_RX_NODE_IBIAS_PTAT_MIXER = 0xCu,
    e_RX_NODE_IBIAS_PTAT_LO = 0xDu,
    e_RX_NODE_IBIAS_BG_BB1 = 0xEu,
    e_RX_NODE_IBIAS_BG_LO = 0xFu,
    e_RX_NODE_IBIAS_BG_BUF = 0x10u,
    e_RX_NODE_VSSA = 0x11u,
    e_RX_NODE_IBIAS_BG_BB2 = 0x12u,
    e_RX_NODE_INVALID
} RX_ATBNodes_e;

/// RX gain control
typedef enum
{
    e_RX_GAIN_27DB = 0x01u,
    e_RX_GAIN_30DB = 0x02u,
    e_RX_GAIN_33DB = 0x03u,
    e_RX_GAIN_36DB = 0x04u,
    e_RX_GAIN_39DB = 0x05u,
    e_RX_GAIN_42DB = 0x06u,
    e_RX_GAIN_45DB = 0x07u,
    e_RX_GAIN_INVALID
} RX_Gain_Control_e;

/// RX  RFBIST input signal
typedef enum
{
    e_RX_RFBIST_INPUT_DISABLED = 0x00u,
    /// Select RFBIST input as LNA
    e_RX_RFBIST_INPUT_LNA = 0x01u,
    /// Select RFBIST input as mixer
    e_RX_RFBIST_INPUT_MIXER = 0x02u,
    e_RX_RFBIST_INPUT_INVALID
} RX_RFBIST_Input_e;

///  RX LOx3 Gain source selection
typedef enum
{
    /// Common value for all LOI followers
    e_RX_LOx3_COMMON = 0x00u,
    /// Local control from lox3_gain_ctrl register
    e_RX_LOx3_CTRLREG = 0x01u,
    /// Local calibration result - default
    e_RX_LOx3_CAL = 0x02u,
    e_RX_LOx3_INVALID
} RX_LOx3_GainSelect_e;

///  TX BPSK internal phase status
typedef enum
{
    e_TX_BPSK_PHASE_STATUS_OFF = 0x00u,
    e_TX_BPSK_PHASE_STATUS_ONE_EIGHTY_DEGREE = 0x01u,
    e_TX_BPSK_PHASE_STATUS_ZERO_DEGREE = 0x02u,
    e_TX_BPSK_PHASE_STATUS_RESERVED = 0x03u,
    e_TX_BPSK_PHASE_STATUS_INVALID
} TX_BPSKPhaseStatus_e;

///  TX internal nodes for ATB
typedef enum
{
    e_TX_NODE_RESET = 0x00u,
    e_TX_NODE_VDDA_1V8 = 0x01u,
    e_TX_NODE_VDDA_1V1 = 0x02u,
    e_TX_NODE_VDDD_1V1_FS = 0x03u,
    e_TX_NODE_VREF_PA_MIN = 0x04u,
    e_TX_NODE_VREF_PA_LOW = 0x05u,
    e_TX_NODE_VREF_PA_HIGH = 0x06u,
    e_TX_NODE_VREF_PA_MAX = 0x07u,
    e_TX_NODE_LEVEL_PA = 0x08u,
    e_TX_NODE_LEVEL_TEMP = 0x09u,
    e_TX_NODE_VREF_TEMP = 0x0Au,
    e_TX_NODE_VCAS_LOX3_1V8 = 0x0Bu,
    e_TX_NODE_VCAS_PATOP_1 = 0x0Cu,
    e_TX_NODE_VCAS_PATOP_2 = 0x0Du,
    e_TX_NODE_VCAS_PATOP_3 = 0x0Eu,
    e_TX_NODE_IBIAS_LOX3 = 0x0Fu,
    e_TX_NODE_VCAS_PABOT_1 = 0x10u,
    e_TX_NODE_VCAS_PABOT_2 = 0x11u,
    e_TX_NODE_VCAS_PABOT_3 = 0x12u,
    e_TX_NODE_VCAS_PABOT_VREF = 0x13u,
    e_TX_NODE_VGG_VGA = 0x14u,
    e_TX_NODE_VGG_PS = 0x15u,
    e_TX_NODE_VGG_PA1 = 0x16u,
    e_TX_NODE_VGG_PA2 = 0x17u,
    e_TX_NODE_VGG_PA3 = 0x18u,
    e_TX_NODE_IBIAS_BGR = 0x19u,
    e_TX_NODE_IBIAS_PTAT = 0x1Au,
    e_TX_NODE_IBIAS_BG = 0x1Bu,
    e_TX_NODE_VGG_PR = 0x1Cu,
    e_TX_NODE_VGG_PRBUF0 = 0x1Du,
    e_TX_NODE_VGG_PRBUF1 = 0x1Eu,
    e_TX_NODE_VGG_PRBUF2 = 0x1Fu,
    e_TX_NODE_VGG_PRBUF3 = 0x20u,
    e_TX_NODE_VGG_PRPPD = 0x21u,
    e_TX_NODE_VOUT_PPD_VGA_OFFSETDAC = 0x22u,
    e_TX_NODE_VNGATE_PS_DAC = 0x23u,
    e_TX_NODE_VOUT_CAL_MUX = 0x24u,
    e_TX_NODE_SPARE1 = 0x25u,
    e_TX_NODE_SPARE2 = 0x26u,
    e_TX_NODE_VBX01_LOX3 = 0x27u,
    e_TX_NODE_VBX23_LOX3 = 0x28u,
    e_TX_NODE_VGG_CAS_PSDAC = 0x29u,
    e_TX_NODE_TC_COMP = 0x2Au,
    e_TX_NODE_PA_PPD_TOP = 0x2Bu,
    e_TX_NODE_PA_PPD_BOTTOM = 0x2Cu,
    e_TX_NODE_LOX3_PPD = 0x2Du,
    e_TX_NODE_PR_PPD = 0x2Eu,
    e_TX_NODE_PPD_REF_LOX3 = 0x2Fu,
    e_TX_NODE_PPD_REF_PR = 0x30u,
    e_TX_NODE_PPD_REF_PATOP = 0x31u,
    e_TX_NODE_PPD_REF_PABOT = 0x32u,
    e_TX_NODE_VREF_PPD_MON = 0x33u,
    e_TX_NODE_PA_PPD_DIFF_TOP = 0x34u,
    e_TX_NODE_PA_PPD_DIFF_BOTTOM = 0x35u,
    e_TX_NODE_LOX3_PPD_DIFF = 0x36u,
    e_TX_NODE_PR_PPD_DIFF = 0x37u,
    e_TX_NODE_PPD_VREF_LOX3 = 0x38u,
    e_TX_NODE_PPD_VREF_PR = 0x39u,
    e_TX_NODE_PPD_VREF_PATOP = 0x3Au,
    e_TX_NODE_PPD_VREF_PABOT = 0x3Bu,
    e_TX_NODE_INVALID
} TX_ATBNodes_e;

///  PRC MUX connection modes
typedef enum
{
    e_TX_PRCMUX_IDAC = 0x00u,
    e_TX_PRCMUX_QDAC = 0x01u,
    e_TX_PRCMUX_PPD = 0x02u,
    e_TX_PRCMUX_PPD_VIA_VGA = 0x03u,
    e_TX_PRCMUX_DISCONNECT = 0x04u,
    e_TX_PRCMUXMode_INVALID
} TX_PRCMUXModes_e;

/// SSB internal nodes for ATB
typedef enum
{
    e_SSB_NODE_RESET = 0x00u,
    e_SSB_NODE_VDDA_1V8 = 0x01u,
    e_SSB_NODE_VDDA_1V1 = 0x02u,
    e_SSB_NODE_VDDD_1V1 = 0x03u,
    e_SSB_NODE_LEVEL_RF = 0x04u,
    e_SSB_NODE_VGA_BIAS = 0x05u,
    e_SSB_NODE_VCASC = 0x06u,
    // 0x7, 0x8 is not used
    e_SSB_NODE_LO_BUFFER_BIAS = 0x09u,
    e_SSB_NODE_MIXER_BIAS = 0x0Au,
    e_SSB_NODE_RF_BUFFER_BIAS = 0x0Bu,
    // 0xCu and 0xDu is not used if ATB2 is selected.
    e_SSB_NODE_IREF_BGR = 0x0Cu,
    e_SSB_NODE_IREF_BG = 0x0Du,
    /// 0xEu is not used if ATB1 is selected.
    e_SSB_NODE_IREF_PTAT = 0x0Eu,
    e_SSB_NODE_INVALID
} SSB_ATBNodes_e;

///  Global LDO SNS thresholds
typedef enum
{
    e_GLDO_SNS_1v1HIGH = 0x00u,
    e_GLDO_SNS_1v1LOW = 0x01u,
    e_GLDO_SNS_1v8HIGH = 0x02u,
    e_GLDO_SNS_1v8LOW = 0x03u,
    e_GLDO_SNS_INVALID
} GLDO_SNSThreshold_e;

/// GLDO SNS threshold coarse adjustment
typedef enum
{
    /// if 1v8 high or 1v1 high is selected, 0x0u set that +5% of Vmon will trigger peak detect signal. if 1v8 low or 1v1 low is selected, 0x0u set that +10% of Vmon will trigger peak detect signal.
    e_GLDO_COARSESNS_PLUS5PERCENT_PLUS10PERCENT = 0x00u,
    /// if 1v8 high or 1v1 high is selected, 0x1u set that +10% of Vmon will trigger peak detect signal. if 1v8 low or 1v1 low is selected, 0x1u set that +5% of Vmon will trigger peak detect signal.
    e_GLDO_COARSESNS_PLUS10PERCENT_PLUS5PERCENT = 0x01u,
    /// if 1v8 high or 1v1 high is selected, 0x2u set that +15% of Vmon will trigger peak detect signal. if 1v8 low or 1v1 low is selected, 0x2u set that +0% of Vmon will trigger peak detect signal.
    e_GLDO_COARSESNS_PLUS15PERCENT_PLUS0PERCENT = 0x02u,
    /// if 1v8 high or 1v1 high is selected, 0x3u set that +20% of Vmon will trigger peak detect signal. if 1v8 low or 1v1 low is selected, 0x3u set that -5% of Vmon will trigger peak detect signal.
    e_GLDO_COARSESNS_PLUS20PERCENT_MINUS5PERCENT = 0x03u,
    e_GLDO_COARSESNS_INVALID
} GLDO_SNS_CoarseAdjustment_e;

/// Global LDO internal nodes for ATB
typedef enum
{
    e_GLDO_NODE_RESET = 0x00u,
    e_GLDO_NODE_VSSA_LDO = 0x01u,
    e_GLDO_NODE_SNS_VREF_0V7 = 0x02u,
    e_GLDO_NODE_BG_VREF_0V4 = 0x03u,
    e_GLDO_NODE_REF_VREF_LDO1V1_0V9 = 0x04u,
    e_GLDO_NODE_REF_VREF_LDO1V8_0V9 = 0x05u,
    e_GLDO_NODE_VDDD_SAFETY_1V1 = 0x06u,
    e_GLDO_NODE_VDDA_LDO_1V8 = 0x07u,
    e_GLDO_NODE_VDDA_LDO_1V1 = 0x08u,
    e_GLDO_NODE_VSS = 0x09u,
    e_GLDO_NODE_SNS_1V1_LOW_VREF = 0x0Au,
    e_GLDO_NODE_SNS_1V1_HIGH_VREF = 0x0Bu,
    e_GLDO_NODE_SNS_1V8_LOW_VREF = 0x0Cu,
    e_GLDO_NODE_SNS_1V8_HIGH_REF = 0x0Du,
    e_GLDO_NODE_VDDA_LDO_3V3 = 0x0Eu,
    e_GLDO_NODE_INVALID
} GLDO_ATBNodes_e;

///  ATB internal nodes for ATB
typedef enum
{
    e_ATB_NODE_RESET = 0x00u,
    e_ATB_NODE_VDDA_1V8 = 0x01u,
    e_ATB_NODE_VDDA_1V1 = 0x02u,
    e_ATB_NODE_VDDD_SAFETY_1V1 = 0x03u,
    e_ATB_NODE_IREF_BG = 0x04u,
    e_ATB_NODE_IREF_BGR_1 = 0x05u,
    e_ATB_NODE_IREF_BGR_2 = 0x06u,
    e_ATB_NODE_IREF_LOCAL_LDO = 0x07u,
    e_ATB_NODE_INVALID
} ATB_ATBNodes_e;

///  List of IP's and features inside Barracuda
typedef enum
{
    e_OTP_VALID_CHIRP_5G_MODE = 0x01u,
    e_OTP_VALID_PR = 0x02u,
    e_OTP_VALID_LO_IN = 0x03u,
    e_OTP_VALID_LO_OUT = 0x04u,
    e_OTP_VALID_RX1 = 0x05u,
    e_OTP_VALID_RX2 = 0x06u,
    e_OTP_VALID_RX3 = 0x07u,
    e_OTP_VALID_RX4 = 0x08u,
    e_OTP_VALID_TX1 = 0x09u,
    e_OTP_VALID_TX2 = 0x0Au,
    e_OTP_VALID_TX3 = 0x0Bu,
    e_OTP_VALID_LVDS = 0x0Cu,
    e_OTP_VALID_CSI2 = 0x0Du,
    e_OTP_LOADED = 0X0Eu,
    e_OTP_VALID_INVALID
} OTP_ValidIP_e;

///  OTP table identifier
typedef enum
{
    e_OTP_TRIM_TS_THRESH = 0x01u,
    e_OTP_TRIM_TX_TS_COEFF = 0x02u,
    e_OTP_TRIM_CHIRP_TS_COEFF = 0x03u,
    e_OTP_TRIM_SNS = 0x04u,
    e_OTP_TRIM_GBIAS = 0x05u,
    e_OTP_TRIM_LOCAL_LDO = 0x06u,
    e_OTP_TRIM_RX1_THRESH = 0x07u,
    e_OTP_TRIM_RX2_THRESH = 0x08u,
    e_OTP_TRIM_RX3_THRESH = 0x09u,
    e_OTP_TRIM_RX4_THRESH = 0x0Au,
    e_OTP_TRIM_RX1_FILTER = 0x0Bu,
    e_OTP_TRIM_RX2_FILTER = 0x0Cu,
    e_OTP_TRIM_RX3_FILTER = 0x0Du,
    e_OTP_TRIM_RX4_FILTER = 0x0Eu,
    e_OTP_TRIM_TX1_BIAS_ST3 = 0x0Fu,
    e_OTP_TRIM_TX2_BIAS_ST3 = 0x10u,
    e_OTP_TRIM_TX3_BIAS_ST3 = 0x11u,
    e_OTP_TRIM_TX1_BIAS_ST12 = 0x12u,
    e_OTP_TRIM_TX2_BIAS_ST12 = 0x13u,
    e_OTP_TRIM_TX3_BIAS_ST12 = 0x14u,
    e_OTP_TRIM_TX1_THRESH = 0x15u,
    e_OTP_TRIM_TX2_THRESH = 0x16u,
    e_OTP_TRIM_TX3_THRESH = 0x17u,
    e_OTP_TRIM_LOI_THRESH = 0x18u,
    e_OTP_TRIM_CHIRP_THRESH = 0x19u,
    e_OTP_TRIM_SUBBAND_CORRECTION_1G = 0x1Au,
    e_OTP_TRIM_SUBBAND_CORRECTION_2G = 0x1Bu,
    e_OTP_TRIM_SUBBAND_CORRECTION_4G = 0x1Cu,
    e_OTP_SPARE_TRIM = 0x1Du,
    e_OTP_TRIM_WR_PTAT = 0x1Eu,
    e_OTP_TRIM_FR_GLDO = 0x1Fu,
    e_OTP_TRIM_INVALID
} OTP_Table_e;

///  ISM error flag groups
typedef enum
{
    e_ISM_ERR_GROUP_TX = 0x00u,
    e_ISM_ERR_GROUP_RX = 0x01u,
    e_ISM_ERR_GROUP_CHIRP = 0x02u,
    e_ISM_ERR_GROUP_MC_LO_CC_ISM_OTP = 0x03u,
    e_ISM_ERR_GROUP_SSB_GB_SER_GLDO_ATB = 0x04u,
    e_ISM_ERR_GROUP_ADC = 0x05u,
    e_ISM_ERR_GROUP_INVALID
} ISM_ErrIPNum_e;

///  List of operations on ISM error flags
typedef enum
{
    e_ISM_ERR_OP_MASK_ERR = 0x00u,
    e_ISM_ERR_OP_UNMASK_ERR = 0x01u,
    e_ISM_ERR_OP_MONITOR_ERR = 0x02u,
    e_ISM_ERR_OP_CLEAR_ERR = 0x03u,
    e_ISM_ERR_OP_SET_ERR = 0x04u,
    e_ISM_ERR_OP_INVALID
} ISM_ErrCmd_e;

///  List of types of errors that API can get from ISM
typedef enum
{
    e_ISM_GET_MASKED_ERR = 0x00u,
    e_ISM_GET_RAW_ERR = 0x01u,
    e_ISM_GET_FIT_STATUS = 0x02u,
    e_ISM_GET_INVALID
} ISM_GetErrCmd_e;

///  List of types of first errors that API can get from ISM
typedef enum
{
    e_ISM_GET_FIRST_MASKED_ERR = 0x00u,
    e_ISM_GET_FIRST_MASKED_WAR = 0x01u,
    e_ISM_ERR_FIRST_INVALID
} ISM_GetFirstErrCmd_e;

///  Barracuda startup sequence  status
typedef enum
{
    e_ISM_SPI_ACCESS_CHECK_OK = 0x00u,
    e_ISM_IC_OTP_CALIBRATION_DATA_OK = 0x01u,
    e_ISM_MAIN_LDO_CONFIG_OK = 0x02u,
    e_ISM_GOBAL_BIAS_CONFIG_OK = 0x03u,
    e_ISM_LOCAL_LDO_CONFIG_OK = 0x04u,
    e_ISM_CAFC_CONFIG_OK = 0x05u,
    e_ISM_MCLK_CONFIG_OK = 0x06u,
    e_ISM_SAFETY_SENSOR_CONFIG_OK = 0x07u,
    e_ISM_STARTUP_SEQ_INVALID
} ISM_StartupSeq_e;

///  Hardware FIT test states
typedef enum
{
    e_ISM_FIT_IDLE = 0x0u,
    e_ISM_FIT_FORCE_STATE = 0x01u,
    e_ISM_FIT_RESET_STATE = 0x02u,
    e_ISM_FIT_COMPLETE = 0x03u,
    e_ISM_FIT_STATE_INVALID
} ISM_FITTestState_e;

///  ISM masked get report errors for all IPs
typedef enum
{
    e_ISM_NO_ERR = 0x00u,
    /// ISM Error status
    e_ISM_STARTUP_CHECK_ERR = 0x01u,
    e_ISM_SPI_CRC_ERR = 0x02u,
    e_ISM_FTTI_ERR = 0x03u,
    /// GLDO mask errors
    e_ISM_MASK_GLDO_HIGH1V1_ERR = 0x04u,
    e_ISM_MASK_GLDO_LOW1V1_ERR = 0x05u,
    e_ISM_MASK_GLDO_HIGH1V8_ERR = 0x06u,
    e_ISM_MASK_GLDO_LOW1V8_ERR = 0x07u,
    e_ISM_MASK_GLDO_REG_CRC_ERR = 0x08u,
    /// GBIAS
    e_ISM_MASK_GBIAS_REG_CRC_ERR = 0x09u,
    e_ISM_MASK_GBIAS_SUPPLY1V8LOW_ERR = 0x0Au,
    /// SER
    e_ISM_MASK_SER_REG_CRC_ERR = 0x0Bu,
    e_ISM_MASK_SER_SUPPLY1V8LOW_ERR = 0x0Cu,
    e_ISM_MASK_SER_SUPPLY1V1MIPILOW_ERR = 0x0Du,
    e_ISM_MASK_SER_SUPPLY1V1LVDSLOW_ERR = 0x0Eu,
    /// SSB
    e_ISM_MASK_SSB_REG_CRC_ERR = 0x0Fu,
    e_ISM_MASK_SSB_SUPPLY1V8LOW_ERR = 0x10u,
    /// ATB
    e_ISM_MASK_ATB_REG_CRC_ERR = 0x11u,
    // Chirp and VCO MASKED ERRORS
    e_ISM_MASK_CHIRP_CAFC_REG_CRC_ERR = 0x12u,
    e_ISM_MASK_CHIRP_PRCALTIMEOUT_ERR = 0x13u,
    e_ISM_MASK_CHIRP_AAFCCALTIMEOUT_ERR = 0x14u,
    e_ISM_MASK_CHIRP_AAFCDIGITAL_ERR = 0x15u,
    e_ISM_MASK_CHIRP_DIGSUPPLY1V1LOWERROR_ERR = 0x16u,
    e_ISM_MASK_CHIRP_VCOSUPPLY1V8VLOW_ERR = 0x17u,
    e_ISM_MASK_CHIRP_PLLSUPPLY1V8VLOW_ERR = 0x18u,
    e_ISM_MASK_CHIRP_INTERFACESTUCKAT_ERR = 0x19u,
    e_ISM_MASK_CHIRP_VCOFREQUENCY480_ERR = 0x1Au,
    e_ISM_MASK_CHIRP_VCOLEVELMAX_ERR = 0x1Bu,
    e_ISM_MASK_CHIRP_VCOLEVELHIGH_ERR = 0x1Cu,
    e_ISM_MASK_CHIRP_VCOLEVELLOW_ERR = 0x1Du,
    e_ISM_MASK_CHIRP_VCOLEVELMIN_ERR = 0x1Eu,
    e_ISM_MASK_CHIRP_VTUNEHIGH_ERR = 0x1Fu,
    e_ISM_MASK_CHIRP_VTUNELOW_ERR = 0x20u,
    e_ISM_MASK_CHIRP_TEMP_ERR = 0x21u,
    e_ISM_MASK_CHIRP_PLLUNLOCK_ERR = 0x22u,
    e_ISM_MASK_CHIRP_DIGITALLOCKSTEP_ERR = 0x23u,
    /// Master clock
    e_ISM_MASK_MCLK_REG_CRC_ERR = 0x24u,
    e_ISM_MASK_MCLK_PLLCAL_ERR = 0x25u,
    e_ISM_MASK_MCLK_PLLLEVEL_ERR = 0x26u,
    e_ISM_MASK_MCLK_PLLLOCK_ERR = 0x27u,
    e_ISM_MASK_MCLK_DIGOUTPUTFREQ_ERR = 0x28u,
    e_ISM_MASK_MCLK_SUPPLY1V8LOW_ERR = 0x29u,
    e_ISM_MASK_MCLK_MSPC_ERR = 0x2Au,
    /// LO Masked module
    e_ISM_MASK_LOI_REG_CRC_ERR = 0x2Bu,
    e_ISM_MASK_LOI_LEVELMAX_ERR = 0x2Cu,
    e_ISM_MASK_LOI_LEVELHIGH_ERR = 0x2Du,
    e_ISM_MASK_LOI_LEVELLOW_ERR = 0x2Eu,
    e_ISM_MASK_LOI_LEVELMIN_ERR = 0x2Fu,
    e_ISM_MASK_LOIIN_CONNECTION_ERR = 0x30u,
    e_ISM_MASK_LOIOUT_CONNECTION_ERR = 0x31u,
    e_ISM_MASK_LOI_SUPPLY1V1LOW_ERR = 0x32u,
    e_ISM_MASK_CC_REG_CRC_ERR = 0x33u,
    e_ISM_MASK_SPI_RD_ERR = 0x34u,
    e_ISM_MASK_SPI_WR_ERR = 0x35u,
    e_ISM_MASK_ISM_REG_CRC_ERR = 0x36u,
    e_ISM_MASK_OTP_REG_CRC_ERR = 0x37u,
    /// Tx1
    e_ISM_MASK_TX1_REG_CRC_ERR = 0x38u,
    e_ISM_MASK_TX1_PR_ERR = 0x39u,
    e_ISM_MASK_TX1_SUPPLY1V8LOW_ERR = 0x3Au,
    e_ISM_MASK_TX1_RFLEVELMAX_ERR = 0x3Bu,
    e_ISM_MASK_TX1_RFLEVELHIGH_ERR = 0x3Cu,
    e_ISM_MASK_TX1_RFLEVELLOW_ERR = 0x3Du,
    e_ISM_MASK_TX1_RFLEVELMIN_ERR = 0x3Eu,
    e_ISM_MASK_TX1_TEMPHIGH_ERR = 0x3Fu,
    e_ISM_MASK_TX1_RFCONNECTION_ERR = 0x40u,
    /// Tx2
    e_ISM_MASK_TX2_REG_CRC_ERR = 0x41u,
    e_ISM_MASK_TX2_PR_ERR = 0x42u,
    e_ISM_MASK_TX2_SUPPLY1V8LOW_ERR = 0x43u,
    e_ISM_MASK_TX2_RFLEVELMAX_ERR = 0x44u,
    e_ISM_MASK_TX2_RFLEVELHIGH_ERR = 0x45u,
    e_ISM_MASK_TX2_RFLEVELLOW_ERR = 0x46U,
    e_ISM_MASK_TX2_RFLEVELMIN_ERR = 0x47u,
    e_ISM_MASK_TX2_TEMPHIGH_ERR = 0x48u,
    e_ISM_MASK_TX2_RFCONNECTION_ERR = 0x49u,
    /// Tx3
    e_ISM_MASK_TX3_REG_CRC_ERR = 0x4Au,
    e_ISM_MASK_TX3_PR_ERR = 0x4Bu,
    e_ISM_MASK_TX3_SUPPLY1V8LOW_ERR = 0x4Cu,
    e_ISM_MASK_TX3_RFLEVELMAX_ERR = 0x4Du,
    e_ISM_MASK_TX3_RFLEVELHIGH_ERR = 0x4Eu,
    e_ISM_MASK_TX3_RFLEVELLOW_ERR = 0x4Fu,
    e_ISM_MASK_TX3_RFLEVELMIN_ERR = 0x50u,
    e_ISM_MASK_TX3_TEMPHIGH_ERR = 0x51u,
    e_ISM_MASK_TX3_RFCONNECTION_ERR = 0x52u,
    /// Rx Masked Errors
    e_ISM_MASK_RX1_REG_CRC_ERR = 0x53u,
    e_ISM_MASK_RX1_RFCONNECTION_ERR = 0x54u,
    e_ISM_MASK_RX1_SUPPLY1V1LOW_ERR = 0x55u,
    e_ISM_MASK_RX1_SUPPLY1V8LOW_ERR = 0x56u,
    e_ISM_MASK_RX1_LOLEVELMAX_ERR = 0x57u,
    e_ISM_MASK_RX1_LOLEVELHIGH_ERR = 0x58u,
    e_ISM_MASK_RX1_LOLEVELLOW_ERR = 0x59u,
    e_ISM_MASK_RX1_LOLEVELMIN_ERR = 0x5Au,
    e_ISM_MASK_RX2_REG_CRC_ERR = 0x5Bu,
    e_ISM_MASK_RX2_RFCONNECTION_ERR = 0x5Cu,
    e_ISM_MASK_RX2_SUPPLY1V1LOW_ERR = 0x5Du,
    e_ISM_MASK_RX2_SUPPLY1V8LOW_ERR = 0x5Eu,
    e_ISM_MASK_RX2_LOLEVELMAX_ERR = 0x5Fu,
    e_ISM_MASK_RX2_LOLEVELHIGH_ERR = 0x60u,
    e_ISM_MASK_RX2_LOLEVELLOW_ERR = 0x61u,
    e_ISM_MASK_RX2_LOLEVELMIN_ERR = 0x62u,
    e_ISM_MASK_RX3_REG_CRC_ERR = 0x63u,
    e_ISM_MASK_RX3_RFCONNECTION_ERR = 0x64u,
    e_ISM_MASK_RX3_SUPPLY1V1LOW_ERR = 0x65u,
    e_ISM_MASK_RX3_SUPPLY1V8LOW_ERR = 0x66u,
    e_ISM_MASK_RX3_LOLEVELMAX_ERR = 0x67u,
    e_ISM_MASK_RX3_LOLEVELHIGH_ERR = 0x68u,
    e_ISM_MASK_RX3_LOLEVELLOW_ERR = 0x69u,
    e_ISM_MASK_RX3_LOLEVELMIN_ERR = 0x6Au,
    e_ISM_MASK_RX4_REG_CRC_ERR = 0x6Bu,
    e_ISM_MASK_RX4_RFCONNECTION_ERR = 0x6Cu,
    e_ISM_MASK_RX4_SUPPLY1V1LOW_ERR = 0x6Du,
    e_ISM_MASK_RX4_SUPPLY1V8LOW_ERR = 0x6Eu,
    e_ISM_MASK_RX4_LOLEVELMAX_ERR = 0x6Fu,
    e_ISM_MASK_RX4_LOLEVELHIGH_ERR = 0x70u,
    e_ISM_MASK_RX4_LOLEVELLOW_ERR = 0x71u,
    e_ISM_MASK_RX4_LOLEVELMIN_ERR = 0x72u,
    /// ADC masked Errors
    e_ISM_MASK_ADC12_REG_CRC_ERR = 0x73u,
    e_ISM_MASK_ADC12_SUPPLY1V8LOW_ERR = 0x74u,
    e_ISM_MASK_ADC2_HARDCLIPPING_ERR = 0x75u,
    e_ISM_MASK_ADC1_HARDCLIPPING_ERR = 0x76u,
    e_ISM_MASK_ADC2_CAL_ERR = 0x77u,
    e_ISM_MASK_ADC1_CAL_ERR = 0x78u,
    e_ISM_MASK_ADC34_REG_CRC_ERR = 0x79u,
    e_ISM_MASK_ADC34_SUPPLY1V8LOW_ERR = 0x7Au,
    e_ISM_MASK_ADC4_HARDCLIPPING_ERR = 0x7Bu,
    e_ISM_MASK_ADC3_HARDCLIPPING_ERR = 0x7Cu,
    e_ISM_MASK_ADC4_CAL_ERR = 0x7Du,
    e_ISM_MASK_ADC3_CAL_ERR = 0x7Eu,
    e_ISM_MASK_CHIRP_LEVELMAX_ERR = 0X7Fu,
    e_ISM_MASK_MCLK_XONOCLK_ERR = 0x80u,
    e_ISM_MASK_TX1_SUPPLY1V1LOW_ERR = 0x82u,
    e_ISM_MASK_TX2_SUPPLY1V1LOW_ERR = 0x83u,
    e_ISM_MASK_TX3_SUPPLY1V1LOW_ERR = 0x84u,

    e_ISM_MASK_RFLEVEL_MAX_TX_Err = 0x85u,
    e_ISM_MASK_LOLEVEL_MAX_RX_Err = 0x86u,
    e_ISM_MASK_CAL_CHIRP_Err = 0x87u,
    e_ISM_MASK_CAL_LOI_Err = 0x88u,
    e_ISM_MASK_CAL_RX1_Err = 0x89u,
    e_ISM_MASK_CAL_RX2_Err = 0x8Au,
    e_ISM_MASK_CAL_RX3_Err = 0x8Bu,
    e_ISM_MASK_CAL_RX4_Err = 0x8Cu,
    e_ISM_MASK_CAL_TX1_Err = 0x8Du,
    e_ISM_MASK_CAL_TX2_Err = 0x8Eu,
    e_ISM_MASK_CAL_TX3_Err = 0x8Fu,
    e_ISM_MASK_CAL_TX1_SAFETY_Err = 0x90u,
    e_ISM_MASK_CAL_TX2_SAFETY_Err = 0x91u,
    e_ISM_MASK_CAL_TX3_SAFETY_Err = 0x92u,

    e_ISM_MASK_ERR_INVALID
} ISM_Mask_Error_e;

///  ISM Calibration Status
typedef enum
{
    e_ISM_CAL_SUCCESS = 0x00u,
    e_ISM_CAL_BUSY = 0x01u,
    e_ISM_CAL_ERROR = 0x02u,
    e_ISM_CAL_INVALID
} ISM_Cal_Status_e;

///  ISM Chirp and Sequence counter reset options
typedef enum
{
    /// No reset of the counter
    e_ISM_CHIRPSEQ_COUNTER_NORESET = 0x00u,
    /// Reset based on the chirp sequence start signal (hardware based)
    e_ISM_CHIRPSEQ_COUNTER_CHIRPSEQ_START = 0x01u,
    /// Reset based on the error_reset coming from pin or register
    e_ISM_CHIRPSEQ_COUNTER_ERROR_RESET = 0x02u,
    /// Reset based on the MCU write into register
    e_ISM_CHIRPSEQ_COUNTER_MCU_WRITE = 0x03u,
    e_ISM_CHIRPSEQ_COUNTER_INVALID
} ISM_CHIRPSEQ_COUNTER_e;

///  Extra data from host data capture
typedef struct
{
    ///  CRC raw values of channel 0
    uint32_t CRCRawVChann0;
    uint32_t CRCRawVChann1;
    uint32_t CRCRawVChann2;
    uint32_t CRCRawVChann3;
    ///  CRC verification result from host, TRUE is OK
    BOOL CRCVerifyOK0;
    BOOL CRCVerifyOK1;
    BOOL CRCVerifyOK2;
    BOOL CRCVerifyOK3;
} PLF_FrameExtraData_t;

///  DC calibration file content
typedef struct
{ // BISTADC
    float32_t B1lsb05;
    float32_t B2lsb05;
    float32_t B1lsb1;
    float32_t B2lsb1;
    // RMS_DET
    float32_t DCchirpG;
    float32_t DCtx1G;
    float32_t DCtx2G;
    float32_t DCtx3G;
    float32_t DCrx1G;
    float32_t DCrx2G;
    float32_t DCrx3G;
    float32_t DCrx4G;
    float32_t DCssbG;
    float32_t DCloiG;
    float32_t DCchirpO;
    float32_t DCtx1O;
    float32_t DCtx2O;
    float32_t DCtx3O;
    float32_t DCrx1O;
    float32_t DCrx2O;
    float32_t DCrx3O;
    float32_t DCrx4O;
    float32_t DCssbO;
    float32_t DCloiO;
    float32_t BA1chirpG;
    float32_t BA1tx1G;
    float32_t BA1tx2G;
    float32_t BA1tx3G;
    float32_t BA1rx1G;
    float32_t BA1rx2G;
    float32_t BA1rx3G;
    float32_t BA1rx4G;
    float32_t BA1ssbG;
    float32_t BA1loiG;
    float32_t BA1chirpO;
    float32_t BA1tx1O;
    float32_t BA1tx2O;
    float32_t BA1tx3O;
    float32_t BA1rx1O;
    float32_t BA1rx2O;
    float32_t BA1rx3O;
    float32_t BA1rx4O;
    float32_t BA1ssbO;
    float32_t BA1loiO;
    float32_t BA2chirpG;
    float32_t BA2tx1G;
    float32_t BA2tx2G;
    float32_t BA2tx3G;
    float32_t BA2rx1G;
    float32_t BA2rx2G;
    float32_t BA2rx3G;
    float32_t BA2rx4G;
    float32_t BA2ssbG;
    float32_t BA2loiG;
    float32_t BA2chirpO;
    float32_t BA2tx1O;
    float32_t BA2tx2O;
    float32_t BA2tx3O;
    float32_t BA2rx1O;
    float32_t BA2rx2O;
    float32_t BA2rx3O;
    float32_t BA2rx4O;
    float32_t BA2ssbO;
    float32_t BA2loiO;
    // BISTADC
    int16_t B1off05;
    int16_t B2off05;
    int16_t B1off1;
    int16_t B2off1;
    // fileheader
    uint8_t ESVersion;
    // Global LDO
    uint8_t v1idx;
    uint8_t v8idx;
    uint8_t v1cur;
    uint8_t v8cur;
    // RTRIM
    uint8_t rtrim;
    // GBIAS_Trimming
    uint8_t loc;
    uint8_t ptat;
    uint8_t bgr;
    uint8_t bg;
    uint8_t ptatoff;
    // LOCAL_LDO_Trimming
    uint8_t atb;
    uint8_t chirp;
    uint8_t lvds;
    uint8_t csi2;
    // FUSA
    uint8_t tx1max;
    uint8_t tx1min;
    uint8_t tx2max;
    uint8_t tx2min;
    uint8_t tx3max;
    uint8_t tx3min;
    uint8_t rx1max;
    uint8_t rx1high;
    uint8_t rx1low;
    uint8_t rx1min;
    uint8_t rx2max;
    uint8_t rx2high;
    uint8_t rx2low;
    uint8_t rx2min;
    uint8_t rx3max;
    uint8_t rx3high;
    uint8_t rx3low;
    uint8_t rx3min;
    uint8_t rx4max;
    uint8_t rx4high;
    uint8_t rx4low;
    uint8_t rx4min;
    uint8_t loimax;
    uint8_t loihigh;
    uint8_t loilow;
    uint8_t loimin;
    uint8_t chirpmax;
    uint8_t chirphigh;
    uint8_t chirplow;
    uint8_t chirpmin;
    uint8_t vtunehigh;
    uint8_t vtunelow;
} SYS_DCCal_t;

///  API Version information
typedef struct
{
    uint8_t Major;
    uint8_t Minor;
    uint8_t Patch;
} SYS_ApiVersion_t;

///  user options for golden run
typedef struct
{
    SYS_ProfID_e ProfID;
    ///  BC_FLOAT default build for single precision floating point, to enable double precision floating point, compile time diversity _doubleprecision_ or define ENABLE_DOUBLE_PRECISION can be used.
    BC_FLOAT CenterFreqHz;
    float32_t PhaseRotationTx1;
    float32_t PhaseRotationTx2;
    float32_t PhaseRotationTx3;
    uint16_t NumChirps; // number of Chirp in Sequence
    BOOL EnTx1;
    BOOL EnTx2;
    BOOL EnTx3;
} SYS_GoldenRunConfig_t;

///  user options for stand alone golden run
typedef struct
{
    SYS_ProfID_e ProfID;
    ///  BC_FLOAT default build for single precision floating point, to enable double precision floating point, compile time diversity _doubleprecision_ or define ENABLE_DOUBLE_PRECISION can be used.
    BC_FLOAT CenterFreqHz;
    BC_FLOAT SelectAcqBW;
    BOOL EnTx1;
    BOOL EnTx2;
    BOOL EnTx3;
} SYS_GoldenRunStandaloneConfig_t;

///  user options for cascade golden run
typedef struct
{
    SYS_ProfID_e ProfID;
    ///  BC_FLOAT default build for single precision floating point, to enable double precision floating point, compile time diversity _doubleprecision_ or define ENABLE_DOUBLE_PRECISION can be used.
    BC_FLOAT CenterFreqHz;
    BC_FLOAT SelectAcqBW;
    BOOL EnLeaderTx1;
    BOOL EnLeaderTx2;
    BOOL EnLeaderTx3;
    BOOL EnFollower1Tx1;
    BOOL EnFollower1Tx2;
    BOOL EnFollower1Tx3;
    BOOL EnFollower2Tx1;
    BOOL EnFollower2Tx2;
    BOOL EnFollower2Tx3;
    BOOL EnFollower3Tx1;
    BOOL EnFollower3Tx2;
    BOOL EnFollower3Tx3;
} SYS_GoldenRunCascadeConfig_t;

///  RMS detector config struct
typedef struct
{
    ///  Select calibration current for RMS detector, valid only when EnCalOffset is set to TRUE
    uint8_t CalCurLevel;
    ///  (only for calibration) FALSE:Disable calibration offset; TRUE: Enable calibration offset
    BOOL EnCalOffset;
    ///  (only for calibration) FALSE: Disable calibration current; TRUE: Enable calibration current
    BOOL EnCalCur;
    ///  FALSE: Measure input of power detector; TRUE: Measure output of power detector
    BOOL MeasDetOutput;
    ///  FALSE: Select positive calibration voltage; TRUE: Select negative calibration voltage
    BOOL SelNegativeCalVolt;
} SYS_ConfigRMSDet_t;

///  All available IPs in a list
typedef struct
{
    BOOL CC;
    BOOL LVDS;
    BOOL MIPI;
    BOOL TE;
    BOOL SC;
    BOOL CAFC;
    BOOL ADC12;
    BOOL ADC34;
    BOOL GBIAS;
    ///  Enable LO Interface
    BOOL LOI;
    BOOL MCLK;
    BOOL RX1;
    BOOL RX2;
    BOOL RX3;
    BOOL RX4;
    BOOL TX1;
    BOOL TX2;
    BOOL TX3;
    BOOL GLDO;
    BOOL ATB;
    BOOL OTP;
    BOOL ISM;
    BOOL CHIRP5GMODE;
    BOOL PR;
    ///  Enable LO_in
    BOOL LOIN;
    /// Enable LO_out
    BOOL LOOUT;

} SYS_IPList_t;

///  Chirp timing parameters in a profile
typedef struct
{
    float32_t TDwell;
    float32_t TSettle;
    float32_t TJumpback;
    float32_t TReset;
    float32_t TChirp;
    /// Transmission on delay from timing reference point in us. This can be either the start of TDWELL or start of TSETTLE
    float32_t TXSWAndBPSDelay;
    /// Controls the trigger point for start of the BPSK/PR/TX switch: TDWELL or TSETTLE. '0' : Trigger  point is start of Tdwell(T1). Position bps/tx phase rotator control and tx fast switch within Tdwell time. '1' :  Trigger  point is start of Tsettle(T2). Position bps/tx phase rotator control and tx fast switch within Tsettle time
    BOOL TriggerTXSWAndBPSAtTSettle;
} SYS_ProfChirpTiming_t;

///  Chirp frequency parameters in a profile, frequency unit is Hz
typedef struct
{
    ///  InputFreqType will decide the meaning of next input param: InputFreqeuncy, @see SYS_ChirpAPIFreqType_e
    SYS_ChirpAPIFreqType_e InputFreqType;
    ///  BC_FLOAT default build for single precision floating point, to enable double precision floating point, compile time diversity _doubleprecision_ or define ENABLE_DOUBLE_PRECISION can be used.
    BC_FLOAT InputFrequency;
    ///  InputBWType will decide the meaning of next input param: InputBW, @see SYS_ChirpAPIBWType_e
    SYS_ChirpAPIBWType_e InputBWType;
    ///  BC_FLOAT default build for single precision floating point, to enable double precision floating point, compile time diversity _doubleprecision_ or define ENABLE_DOUBLE_PRECISION can be used.
    BC_FLOAT InputBW;
    CAFC_VCOBWSel_e VCOSel;
    ///  Subband search method, @see SYS_SBSearchMethod. When options other than e_SYS_SBSEARCH_USEAFC is selected, AFC will be disabled in CAFC IP.
    SYS_SBSearchMethod_e SBSearch;
    ///  Selection of PLL LPF configuration (1 out of 4 configurations, need to pre-configure)
    CAFC_PLLLPFSel_e PLLLPFSel;
    ///  subband setting of the profile, whether this setting will be used depends on the setting of SBSearch input  subband, 0-127 are valid subbands, 128 means search failed
    uint8_t Subband;
    ///  VCO current setting (determines VCO output amplitude) of the profile, whether this setting will be used depends on the setting of SBSearch input,  of VCO current (which controls VCO amplitude), 0-63 are valid current settings, 64 means search failed
    uint8_t iVCOFine;
    BOOL DownChirp;
} SYS_ProfChirpFreq_t;

///  Number of samples and decimation settings for chirp profiles
typedef struct
{
    ///  Choose ADC sampling mode from 80MHZ functional, 80MHz debug or 40MHz legacy
    SYS_ADCSamplingMode_e ADCMode;

    uint16_t RawNumSamples;
    uint8_t Decimation;
    BOOL PDCBWWide;
    ///  Virtual channel number. Applicable only for CSI2 interface.
    SYS_VCN_e VirtualChNo;
} SYS_ProfChirpSampleDeci_t;

/**  Serialiser errors: catering to MIPI and LVDS
The same structure is used with APIs of LVDS and MIPI related to:
(  i)  Mask Reset Error
( ii)  Mask Force Error
(iii)  Mask Error
(iv)  Force Error
( v)  Reset Error
*/
typedef struct
{
    BOOL SerRegCRCErr;
    BOOL Supply1v8SerLowErr;
    BOOL Supply1v1MIPILowErr;
    BOOL Supply1v1LVDSLowErr;
} SYS_SerialiserErrors_t;

///  Errors of ADC
typedef struct
{
    ///  Register CRC error of ADC12 or ADC34
    BOOL ADCRegCrcErr;
    ///  Supply error of ADC12 or ADC34
    BOOL ADCSupply1v8LowErr;
    ///  Hard Clipping Error of ADC2 or ADC4
    BOOL ADCn1HardClippingErr;
    ///  Hard Clipping Error of ADC1 or ADC3
    BOOL ADCn0HardClippingErr;
    ///  calibration error of ADC2 or ADC4
    BOOL ADCn1CalErr;
    ///  calibration error of ADC1 or ADC3
    BOOL ADCn0CalErr;
} SYS_ADCErrors_t;

///  SSB modulator errors
typedef struct
{
    BOOL SSBRegCRCErr;
    BOOL SSBSupply1v8LowErr;
} SYS_SSBErrors_t;

///  Global BIAS error
typedef struct
{
    BOOL GBIASRegCRCErr;
    BOOL GBIASSupply1v8LowErr;
} SYS_GBIASErrors_t;

///  GLDO mask force errors struct
typedef struct
{
    BOOL GlDORegCRCErr;
    BOOL GlDOSupply1v8HighErr;
    BOOL GlDOSupply1v8LowErr;
    BOOL GlDOSupply1v1HighErr;
    BOOL GlDOSupply1v1LowErr;
} SYS_GLDOErrors_t;

///  MCLK errors
typedef struct
{
    BOOL MclkRegCRCErr;
    BOOL MclkPllCalErr;
    ///  The main 4.8GHz PLL O/P level not OK ( PLL /VCO level is too low or too high)
    BOOL MclkPllLevelErr;
    ///  The main 4.8GHz PLL in unlock situation
    BOOL MclkPllLockErr;
    ///  MC digital ootput frequency for 4.8GHz PLL(600/480 MHz) not in range
    BOOL MclkDigOutPutFreqErr;
    BOOL MclkSupply1v8LowErr;
    ///  MC  Master salve phase calibration error
    BOOL MclkMSPCErr;
    ///  xo_det clkin error status
    BOOL ClkinError;
    ///  xo_det pllclk error status
    BOOL PllClkError;
    ///  MC  XO no clock error
    BOOL MclkXoNoClkErr;
} SYS_MCLKErrors_t;

/// LOI errors
typedef struct
{
    BOOL LOIRegCRC_Err;
    ///  LOI level reached beyond reliability limits  If the value is above this limit, a LO power down  is initiated by the hardware if configured.
    BOOL LOILevelMaxErr;
    ///  LOI level is high, need to be addressed otherwise it will cause functional safety error .
    BOOL LOILeveHighErr;
    ///  LOI level is low, need to be addressed otherwise it will cause functional safety error .
    BOOL LOILeveLowErr;
    ///  LOI level too low. Functional safety error results in error_n assertion.
    BOOL LOILeveMinErr;
    ///  RF Ball break detected  at LO-in interface
    BOOL LOIInConnectionErr;
    ///  RF Ball break detected  at LO-out interface
    BOOL LOIOutConnectionErr;

    BOOL LOISupply1v1LowErr;
} SYS_LOIErrors_t;

///  Central Control errors
typedef struct
{
    /// CRC error flag for CC
    BOOL CCRegCRCErr;
    /// SPI CRC Read error flag
    BOOL SPIRdErr;
    /// SPI CRC Write error flag
    BOOL SPIWrErr;
} SYS_CCErrors_t;

///  RX errors
typedef struct
{
    BOOL RxRegCRCErr;
    ///  RX(RF Ball break error)RF connectivity to external antenna port is not working.
    BOOL RxRFConnectionErr;
    BOOL RxSupply1V1LowErr;
    BOOL RxSupply1V8LowErr;
    ///  Rx RF level reached beyond reliability limits, a Rx power down is initiated by the hardware.
    BOOL RxLOLevelMaxErr;
    ///  Rx rf level is high, need to be addressed otherwise it will cause functional safety error .
    BOOL RxLOLevelHighErr;
    ///  Rx PA level is low need to be addressed otherwise it will cause functional safety error .
    BOOL RxLOLevelLowErr;
    ///   RX LO level too low, Functional safety error results in error_n assertion
    BOOL RxLOLevelMinErr;
} SYS_RXErrors_t;

/// RX Local Enable structure to enable the RX IP during validation.
typedef struct
{
    ///  Power on Level Shifter from SPI
    BOOL PonLSSPI;
    ///  Enable RX from SPI
    BOOL EnRX;
    ///  Power on LNA from SPI
    BOOL EnLNA;
    ///  Selection of the rx_active value towards analog IF filter
    BOOL IfSel;
    ///  This bit will be driven towards to the analog IF filter
    BOOL IfRegValue;
    ///  Selection of the source of en_rx_cascode active value (TO2)
    BOOL CascodeSel;

    ///  This bit will be driven towards to the en_rx_cascode_active input of Ana
    BOOL CascodeReg;
    ///  This bit will be driven towards to the bias filters.
    ///  This bit will be driven towards to the bias filters.
    BOOL LORegValue;
    ///  Selection of the rx_active value towards bias filters
    BOOL LORegSel;
    ///  If HPF Rg Value is set hpf_rx_corner_reset_value[6:0] is driven to the IF filter
    BOOL HpfRegValue;
    ///  Selection of the reset_rx_hpf control signal
    BOOL HpfRegSel;
    ///  This value is applied when the reset_rx_hpf_reg_value = 1, 0x01 = 100kHz, 0x02 = 200kHz, 0x04 = 300kHz, 0x08 = 400kHz, 0x10 = 800kHz, 0x20 = 1600kHz, 0x40 = 3200kHz, 0x7F = 6400kHz, Default value is 0x7F
    uint8_t HpfRxCCornerResetValue;
} SYS_RXLocalEnable_t;

///  TX local test errors
typedef struct
{
    BOOL TxRegCRCErr;
    ///  phase rotator error for TX
    BOOL TxPRErr;
    ///  Tx RF level reached beyond reliability limits, a  Tx power down is initiated by the hardware.
    BOOL TxRfLevelMaxErr;
    ///  Tx PA level is high, need to be addressed otherwise it will cause functional safety error .
    BOOL TxRfLevelHighErr;
    ///  Tx PA level is low need to be addressed otherwise it will cause functional safety error .
    BOOL TxRfLevelLowErr;
    ///  Tx PA level is too low. Functional safety error results in error_n assertion
    BOOL TxRfLevelMinErr;

    ///   TxTemperature is high (error_n not asserted), if operation continue, then this may result in  reliability issue.
    BOOL TxTempHighErr;
    ///  Tx (RF Ball break error) RF connectivity to external antenna port is not working.
    BOOL TxRFConnectionErr;
    ///  TX  supply low error (1V8).  Functional safety error results in error_n assertion
    BOOL TxSupply1v8LowErr;
    ///  TX  supply low error (1V1).  Functional safety error results in error_n assertion
    BOOL TxSupply1v1LowErr;

} SYS_TXErrors_t;

///  CAFC errors
typedef struct
{
    BOOL CAFCRegCRCErr;

    BOOL AAFCCalTimeoutErr;
    ///  aafc error  for chirp digital
    BOOL AAFCDigitalErr;

    BOOL ChirpDigSupply1v1LowErrorErr;
    BOOL ChirpVCOSupply1v8vLowErr;
    BOOL ChirpPLLSupply1v8vLowErr;
    ///  Stuck on chirp_seq_active, safety_monitoring, window_active detected.
    BOOL InterfaceStuckatErr;

    ///  VCO O/P frequency to the chirp digital logic is beyond programmable limits.
    BOOL VCOFrequency480Err;
    ///   Chirp VCO O/P level reached beyond reliability limits, a chirp power down is initiated by the hardware
    BOOL VCOLevelMaxErr;
    ///   VCO output level is high need to be addressed otherwise it will cause functional safety error .
    BOOL VCOLevelHighErr;
    ///   VCO output level is low need to be addressed otherwise it will cause functional safety error .
    BOOL VCOLevelLowErr;
    ///   Chirp VCO level is too low. Functional safety error results in error_n assertion
    BOOL VCOLevelMinErr;
    //  Vtune level is high need to be addressed otherwise it will cause functional safety error .
    BOOL VtuneHighErr;
    //  Vtune level is low need to be addressed otherwise it will cause functional safety error .
    BOOL VtuneLowErr;
    ///  Temperature is high (error_n not asserted), if operation continue, then this may result in  reliability issue.
    BOOL ChirpTempErr;
    ///  Chirp PLL in un lock condition.
    BOOL PLLUnlockErr;
    ///  lock_step_error_flag_chirp_status. Chirp digital logic stuck at or transient logic failure.
    BOOL ChirpDigitalLockStepErr;

} SYS_CAFCErrors_t;

///   structure for ISM master errors register
typedef struct
{
    /// This is the combined reg crc error.reg crc error is detected in one or more modules.
    BOOL RegCRCError;
    /// Stuck on chirp_seq_active, safety_monitoring, window_active detected.
    BOOL InterfaceStuckatErr;
    ///  (RF Ball break error)one of the Rx RF connectivity to external antenna port is not working.
    BOOL RxRFConnectionErr;

    ///  One of the RX LO level too low
    BOOL RxLOLevelMinErr;
    /// phase rotator error for TX
    BOOL TxPRErr;
    ///  (RF Ball break error) one of the Tx RF connectivity to external antenna port is not working.
    BOOL TxRFConnectionErr;
    ///  TX PA level is too low. Functional safety error results in error_n assertion
    BOOL TxRfLevelMinErr;
    ///  LOI leve too low. Functional safety error results in error_n assertion.
    BOOL LOILeveMinErr;
    ///  RF Ball break detected  in one of the  LO interface
    BOOL LOIConnectionErr;
    ///  MC digital ootput frequency for 4.8GHz PLL(600/480 MHz) not in range
    BOOL MclkDigOutPutFreqErr;
    ///  The main 4.8GHz PLL in unlock situation
    BOOL MclkPllLockErr;

    ///  The main 4.8GHz PLL O/P level not OK ( PLL /VCO level is too low or too high)
    BOOL MclkPllLevelErr;
    ///  Main ADC calibration out of Sync (calibration issue in ADC)
    BOOL ADCCalErr;

    ///  /// aafc error  for chirp digital
    BOOL AAFCDigitalErr;
    ///  VCO O/P frequency to the chirp digital logic is beyond programmable limits.
    BOOL VCOFreq480Err;

    ///  Chirp PLL in un lock condition.
    BOOL ChirpPLLUnlockErr;
    ///  lock_step_error_flag_chirp_status. Chirp digital logic stuck at or transient logic failure.
    BOOL ChirpDigitalLockStepErr;

    BOOL GlDOSupply1v8HighErr;
    BOOL GlDOSupply1v8LowErr;
    BOOL GlDOSupply1v1HighErr;
    BOOL GlDOSupply1v1LowErr;
    ///  Combined supply low error from all local supply monitoring, for the individual supply failure check
    BOOL SupplyLowError;
    ///  MC  Master salve phase calibration error
    BOOL MclkMSPCErr;
    /// MC XO No clock error
    BOOL MclkXoNoClockErr;
    /// Chirp level max  error
    BOOL ChirpLevelMaxErr;
    /// LOI level max error
    BOOL LOILevelMaxErr;
    /// RF Level max error
    BOOL RFLevelMaxTxErr;
    /// LO Level max error
    BOOL LOLevelMaxRxErr;
} SYS_MasterErrors_t;

///  structure for all IP's supply errors
typedef struct
{
    BOOL GlDOSupply1v8HighErr;
    BOOL GlDOSupply1v8LowErr;
    BOOL GlDOSupply1v1HighErr;
    BOOL GlDOSupply1v1LowErr;
    BOOL ChirpDigSupply1v1LowErrorErr;
    BOOL ChirpVCOSupply1v8vLowErr;
    BOOL ChirpPLLSupply1v8vLowErr;
    BOOL Supply1v8SerLowErr;
    BOOL Supply1v1MIPILowErr;
    BOOL Supply1v1LVDSLowErr;
    BOOL GBIASSupply1v8LowErr;

    BOOL SSBSupply1v8LowErr;
    BOOL LOISupply1v1LowErr;

    BOOL ADC34Supply1v8LowErr;
    BOOL ADC12Supply1v8LowErr;
    BOOL MclkSupply1v8LowErr;
    BOOL Rx4Supply1V1LowErr;
    BOOL Rx3Supply1V1LowErr;
    BOOL Rx2Supply1V1LowErr;
    BOOL Rx1Supply1V1LowErr;

    BOOL Rx4Supply1V8LowErr;
    BOOL Rx3Supply1V8LowErr;
    BOOL Rx2Supply1V8LowErr;
    BOOL Rx1Supply1V8LowErr;

    BOOL Tx3Supply1v8LowErr;
    BOOL Tx2Supply1v8LowErr;
    BOOL Tx1Supply1v8LowErr;
    BOOL Tx3Supply1v1LowErr;
    BOOL Tx2Supply1v1LowErr;
    BOOL Tx1Supply1v1LowErr;
} SYS_SupplyErrors_t;

///  structure for all IP's register CRC errors
typedef struct
{
    BOOL ADC34RegCrcErr;
    BOOL ADC12RegCrcErr;
    BOOL ATBRegCRCErr;
    BOOL GlDORegCRCErr;
    BOOL SerRegCRCErr;
    BOOL GBIASRegCRCErr;
    BOOL SSBRegCRCErr;
    BOOL OTPRegCRCErr;
    BOOL ISMRegCRCErr;

    BOOL CCRegCRCErr;
    BOOL LOIRegCRC_Err;
    BOOL MclkRegCRCErr;
    BOOL CAFCRegCRCErr;
    BOOL Rx4RegCRCErr;
    BOOL Rx3RegCRCErr;
    BOOL Rx2RegCRCErr;
    BOOL Rx1RegCRCErr;
    BOOL Tx3RegCRCErr;
    BOOL Tx2RegCRCErr;
    BOOL Tx1RegCRCErr;
} SYS_RegCRCErrors_t;

///  structure for all the reliability errors
typedef struct
{
    ///  LOI level reached beyond reliability limits  If the value is above this limit, a LO power down  is initiated by the hardware if configured.
    BOOL LOILevelMaxErr;

    ///   Chirp VCO O/P level reached beyond reliability limits, a chirp power down is initiated by the hardware
    BOOL VCOLevelMaxErr;

    ///  Tx3 RF level reached beyond reliability limits, a Tx3 power down is initiated by the hardware.
    BOOL Tx3RfLevelMaxErr;
    ///  Tx2 RF level reached beyond reliability limits, a Tx2 power down is initiated by the hardware.
    BOOL Tx2RfLevelMaxErr;
    ///  Tx1 RF level reached beyond reliability limits, a Tx1 power down is initiated by the hardware.
    BOOL Tx1RfLevelMaxErr;

    ///  Rx4 RF level reached beyond reliability limits, a Rx4 power down is initiated by the hardware.
    BOOL Rx4LOLevelMaxErr;
    ///  Rx3 RF level reached beyond reliability limits, a Rx3 power down is initiated by the hardware.
    BOOL Rx3LOLevelMaxErr;
    ///  Rx2 RF level reached beyond reliability limits, a Rx2 power down is initiated by the hardware.
    BOOL Rx2LOLevelMaxErr;
    ///  Rx1 RF level reached beyond reliability limits, a Rx1 power down is initiated by the hardware.
    BOOL Rx1LOLevelMaxErr;
} SYS_RFPowerDownErrors_t;

///  structure for power down mask for level max error
typedef struct
{
    ///  LOI power down mask for level max error
    BOOL LOIPowerDownMask;

    ///   Chirp VCO power down mask for level max error
    BOOL VCOPowerDownMask;

    ///  Tx3 RF power down mask for level max error
    BOOL Tx3RfPowerDownMask;
    ///  Tx2 RF power down mask for level max error
    BOOL Tx2RfPowerDownMask;
    ///  Tx1 RF power down mask for level max error
    BOOL Tx1RfPowerDownMask;

    ///  Rx4 RF power down mask for level max error
    BOOL Rx4LOPowerDownMask;
    ///  Rx3 RF power down mask for level max error
    BOOL Rx3LOPowerDownMask;
    ///  Rx2 RF power down mask for level max error
    BOOL Rx2LOPowerDownMask;
    ///  Rx1 RF power down mask for level max error
    BOOL Rx1LOPowerDownMask;
} SYS_RFPowerDownMask_t;

///  structure for all the warning (Status errors)
typedef struct
{
    ///  LOI level is high, need to be addressed otherwise it will cause functional safety error .
    BOOL LOILeveHighErr;
    ///  LOI level is low, need to be addressed otherwise it will cause functional safety error .
    BOOL LOILeveLowErr;
    ///  Temperature is high (error_n not asserted), if operation continue, then this may result in reliability issue.
    BOOL ChirpTempErr;
    ///   Tx3 Temperature is high (error_n not asserted), if operation continue, then this may result in reliability issue.
    BOOL Tx3TempHighErr;
    ///   Tx2 Temperature is high (error_n not asserted), if operation continue, then this may result in reliability issue.
    BOOL Tx2TempHighErr;
    ///   Tx1 Temperature is high (error_n not asserted), if operation continue, then this may result in reliability issue.
    BOOL Tx1TempHighErr;
    ///  Main PLL need re-calibration(pll_freq_cal_error_flag_mc_warning_masked_status)
    BOOL MclkPllCalErr;

    ///  Tx3 PA level is high, need to be addressed otherwise it will cause functional safety error .
    BOOL Tx3RfLevelHighErr;
    ///  Tx2 PA level is high, need to be addressed otherwise it will cause functional safety error .
    BOOL Tx2RfLevelHighErr;
    ///  Tx1 PA level is high, need to be addressed otherwise it will cause functional safety error .
    BOOL Tx1RfLevelHighErr;
    ///  Tx3 PA level is low need to be addressed otherwise it will cause functional safety error .
    BOOL Tx3RfLevelLowErr;
    ///  Tx2 PA level is low need to be addressed otherwise it will cause functional safety error .
    BOOL Tx2RfLevelLowErr;
    ///  Tx1 PA level is low need to be addressed otherwise it will cause functional safety error .
    BOOL Tx1RfLevelLowErr;

    ///  Rx4 rf level is high, need to be addressed otherwise it will cause functional safety error .
    BOOL Rx4LOLevelHighErr;
    ///  Rx3 rf level is high, need to be addressed otherwise it will cause functional safety error .
    BOOL Rx3LOLevelHighErr;
    ///  Rx2 rf level is high, need to be addressed otherwise it will cause functional safety error .
    BOOL Rx2LOLevelHighErr;
    ///  Rx1 rf level is high, need to be addressed otherwise it will cause functional safety error .
    BOOL Rx1LOLevelHighErr;
    ///  Rx4 PA level is low need to be addressed otherwise it will cause functional safety error .
    BOOL Rx4LOLevelLowErr;
    ///  Rx3 PA level is low need to be addressed otherwise it will cause functional safety error .
    BOOL Rx3LOLevelLowErr;
    ///  Rx2 PA level is low need to be addressed otherwise it will cause functional safety error .
    BOOL Rx2LOLevelLowErr;
    ///  Rx1 PA level is low need to be addressed otherwise it will cause functional safety error .
    BOOL Rx1LOLevelLowErr;

    //  Vtune level is high need to be addressed otherwise it will cause functional safety error .
    BOOL VtuneHighErr;
    //  Vtune level is low need to be addressed otherwise it will cause functional safety error .
    BOOL VtuneLowErr;
    ///   VCO output level is high need to be addressed otherwise it will cause functional safety error .
    BOOL VCOLevelHighErr;
    ///   VCO output level is low need to be addressed otherwise it will cause functional safety error .
    BOOL VCOLevelLowErr;
} SYS_StatusErrors_t;

/// Error status in ISM space
typedef struct
{
    ///  MOSI CRC error
    BOOL SPICRCErr;

    ///  1v1Digital supply error
    BOOL Digital1v1SupplyRedErr;

    BOOL FTTIRedErr;

    ///  real time error
    BOOL RTMRedErr;
    ///  Startup error (Redundant module for startup check. )
    BOOL Digital1v1SupplyErr;
    BOOL FTTIErr;
    ///  real time error
    BOOL RTMErr;
} SYS_ISMErrorStatus_t;

/// Hardware Calibration status for individual IP
typedef struct
{
    ///  report calibration status of Chirp
    ISM_Cal_Status_e ChirpCalStatus;
    ///  report calibration status of LO
    ISM_Cal_Status_e LOICalStatus;
    ///  report calibration status of Rx4
    ISM_Cal_Status_e Rx4CalStatus;
    ///  report calibration status of Rx3
    ISM_Cal_Status_e Rx3CalStatus;
    ///  report calibration status of Rx2
    ISM_Cal_Status_e Rx2CalStatus;
    ///  report calibration status of Rx1
    ISM_Cal_Status_e Rx1CalStatus;
    ///  report calibration status of Tx3. If e_ISM_CAL_ERROR is returned, this can be treated as warning and ignored
    ISM_Cal_Status_e Tx3CalStatus;
    ///  report calibration status of Tx2. If e_ISM_CAL_ERROR is returned, this can be treated as warning and ignored
    ISM_Cal_Status_e Tx2CalStatus;
    ///  report calibration status of Tx1. If e_ISM_CAL_ERROR is returned, this can be treated as warning and ignored
    ISM_Cal_Status_e Tx1CalStatus;
    ///  report calibration status of Tx3 Safety Calibration
    ISM_Cal_Status_e Tx3SafetyCalStatus;
    ///  report calibration status of Tx2 Safety Calibration
    ISM_Cal_Status_e Tx2SafetyCalStatus;
    ///  report calibration status of Tx1 Safety Calibration
    ISM_Cal_Status_e Tx1SafetyCalStatus;
} SYS_CalibrationStatus_t;

///  Structure that contain the list and profiles and for which the profile data has to be stored. TRUE profile register will updated  with calibrated values, FALSE no update on particular profile
typedef struct
{
    BOOL Profile0;
    BOOL Profile1;
    BOOL Profile2;
    BOOL Profile3;
    BOOL Profile4;
    BOOL Profile5;
    BOOL Profile6;
    BOOL Profile7;
    BOOL Profile8;
} SYS_StoreInProfile_t;

///  Events and errors based Interrupts
///  Use the macros starting with CC_INTEVENT_ for the values
typedef struct
{
    ///  Interrupt is raised when a warning status flag is set
    BOOL StatusFlagInt;
    ///   Interrupt is raised  when a CRC checksum error is reported on the MISO lane
    BOOL CRCErrInt;
    ///   Interrupt is raised, when a RF power down event is triggered within Dolphin
    BOOL RFPowerDownInt;
    ///   Interrupt from real time safety monitoring.  This bit is a redundant bit . In case of safety error the error_n pin is also asserted.
    BOOL RTMInt;
    ///   Periodic  timer interrupt from status monitoring timer.  On occurrence of this interrupt, a set of status monitoring actions need to be performed by MCU before start of next Radar acquisition cycle
    BOOL StatusWDTInt;
    ///   Indicate an end of data transfer  from the serializer at the end of a current  data acquisition cycle.
    BOOL EndofDataTnfrInt;
    ///   Indicates one of the following chirp events from timing engine
    /// a. Routes the interrupt events from chip towards external world
    /// b. Routes the chirp_start signal towards the other chips. eg: slave chip chirp_start trigger
    /// c. Routes the chirp busy/silent timing towards external world eg: dynamic programming of the chip
    BOOL ChirpIn;
} CC_IntEvent_t;

/// IP Module list structure for Central Control. This structure is used for the Reset release, Clock enable,  functional reset and Power on of the selected module lists(IPs)
typedef struct
{
    BOOL SetATB;
    BOOL SetGLDO;
    BOOL SetSSBMOD;
    BOOL SetTX3;
    BOOL SetTX2;
    BOOL SetTX1;
    BOOL SetRX4;
    BOOL SetRX3;
    BOOL SetRX2;
    BOOL SetRX1;
    BOOL SetMCLK;
    BOOL SetLOInterface;
    BOOL SetGBIAS;
    BOOL SetADC34;
    BOOL SetADC12;
    BOOL SetChirp;
    BOOL SetSerialiser;
    BOOL SetISM;
    BOOL SetOTP;
} CC_ModList_t;

/// Central controlled  dynamic Power down IP list struct,
/// There are three modes used for all IPs.
/// - No dynamic power down
/// - Dynamic power down per Sequence
/// - Dynamic power down per Chirp
typedef struct
{
    CC_DynPowMode_e SetTx1;
    CC_DynPowMode_e SetTx2;
    CC_DynPowMode_e SetTx3;
    CC_DynPowMode_e SetRx1;
    CC_DynPowMode_e SetRx2;
    CC_DynPowMode_e SetRx3;
    CC_DynPowMode_e SetRx4;
    CC_DynPowMode_e SetADC;
    CC_DynPowMode_e SetChirp;
    CC_DynPowMode_e SetLoInterface;
    ///  SetADCBGClib will decide, when the ADC background calibration to be triggered during the dynamic powerdown mode, recommended value is at the end of sequence
    CC_DynPowMode_e SetADCBGClib;
} CC_DynPowDnIPList_t;

///  ATB DC branch master switches in CC IP
typedef struct
{
    BOOL CloseDCToInt0;
    BOOL CloseDCToInt180;
    BOOL GroundDC0;
    BOOL GroundDC180;
    BOOL CloseIntToPin0;
    BOOL CloseIntToPin180;
    BOOL GroundInt0;
    BOOL GroundInt180;
} CC_DCATBMasterSwitches_t;

///  ATB AC branch master switches
typedef struct
{
    ///  Valid only for Chirp and SSB
    BOOL CloseExtInEnable;
    BOOL CloseAC0n180;
    BOOL GroundAC0n180;

} CC_ACATBMasterSwitches_t;

///  LVDSTest mode config struct
typedef struct
{
    /** @brief Choose which test mode
        - 00 : Fixed Mode (TestPattern data as test data)
        - 01: Sinewave as test data (78.125 KHz)
        - 10:  Sawtooth wave Incremental Pattern  ( 0x001 ->FFF)
        - 11: PRBS pattern
*/
    LVDS_TestMode_e TestMode;
    ///  PRBS initial value in case TestMode is PRBS, default value is 0x0FFF
    uint16_t PRBSInitialVal;
    ///  12-bit test pattern when TestMode is Fixed (00)
    uint16_t TestData;
    ///  Test data injection point, TRUE: at the output of PDC, FALSE: at the input of PDC
    BOOL SkipPDC;
    ///  Enable Delay data
    BOOL EnDelayTestPattern;
    ///  Enable inverted PRBS pattern
    BOOL EnInvertPRBSPattern;
} LVDS_ConfigTestParms_t;

///  LVDS configuration structure
typedef struct
{
    /**
    Transmission enable for LVDS ChX. 0/FALSE: Not enabled; 1/TRUE: enabled.
    */
    BOOL EnCh1;
    BOOL EnCh2;
    BOOL EnCh3;
    BOOL EnCh4;

    ///  First serial bit start w.r.t bit clock. 0/FALSE: Fall edge. 1/TRUE: Rise edge.
    BOOL BitClkRiseEdge;

    /**
 Frame clock phase control within a frame boundary. 0/FALSE: serial bit starts from rise edge of frame clock; 1/TRUE: fall edge.
*/
    BOOL FrameClkFallEdge;

    /**
Parallel word bit control during serial to  parallel conversion. 0/FALSE: LSB first; 1/TRUE: MSB first
*/
    BOOL MSBFirst;

    ///  Packet (header and footer) endianness: 0/FALSE: MS first; 1/TRUE: LS first.
    BOOL PktHdrLSBFirst;
    /**
Frame clock gating behaviour. 0/FALSE: Frame clock is always free running . 1/TRUE: Frame clock is gated outside data valid.
*/
    BOOL FrameClkGated;

    ///  Packet header presence. 0/FALSE: No header; 1/TRUE: With header
    BOOL EnPktHdr;

    /**
CRC control. 0/FALSE: No footer; 1/TRUE: ADC data CRC protected and CRC appended to packet footer.
*/
    BOOL EnCRCFooter;

} LVDS_Config_t;

///   LVDS Optional configuration structure
typedef struct
{
    LVDS_DValidDelayCtrl_e DValidDelayCtrl;
    ///  Packet header format 0/FALSE: CN->WC->WC->CN; 1/TRUE: CN->CN->WC->WC
    BOOL PktHdrFormat;
    ///  Frame clock pattern to be sent on LVDS clock channel in RAW mode
    uint32_t FrameClkPattern;
    ///  Idle pattern to be sent in RAW mode
    uint32_t IdlePattern;
    ///  Streaming mode control: 0/FALSE: IDLE pattern; 1/TRUE: ADC data
    BOOL EnADCStreamingMode;

} LVDS_OptConfig_t;

///  LVDS Output lines polarity control
typedef struct
{
    ///  Bit clock: 0/FALSE: No invert; 1/TRUE: invert
    BOOL InvertBitClk;
    ///  Frame clock: 0/FALSE: No invert; 1/TRUE: invert
    BOOL InvertFrmClk;
    ///  Lane 3: 0/FALSE: No invert; 1/TRUE: invert
    BOOL InvertSer3;
    ///  Lane 2: 0/FALSE: No invert; 1/TRUE: invert
    BOOL InvertSer2;
    ///  Lane 1: 0/FALSE: No invert; 1/TRUE: invert
    BOOL InvertSer1;
    ///  Lane 0: 0/FALSE: No invert; 1/TRUE: invert
    BOOL InvertSer0;
    ///  Data Valid: 0/FALSE: No invert; 1/TRUE: invert
    BOOL InvertDataValid;
} LVDS_OpLaneCtrl_t;

///  MIPI Test mode config struct
typedef struct
{
    /** @brief Choose which test mode
        - 00 : Fixed Mode (TestPattern data as test data)
        - 01: Sinewave as test data (78.125 KHz)
        - 10:  Sawtooth wave Incremental Pattern  ( 0x001 ->FFF)
        - 11: PRBS pattern
*/
    MIPI_TestMode_e TestMode;
    ///  12-bit test pattern when TestMode is Fixed (00)
    uint16_t testModeTestData;
    ///  Enable Delay data
    BOOL EnDelayTestPattern;
    ///  Test data injection point, TRUE: at the output of PDC, FALSE: at the input of PDC
    BOOL SkipPDC;
    ///  Enable inverted PRBS pattern
    BOOL EnInvertPRBSPattern;
} MIPI_ConfigTestParms_t;

///  Virtual channel number structure for MIPI
typedef struct
{
    ///  True to select the Virtual channel 0
    BOOL SelectVC0;
    ///  True to select the Virtual channel 1
    BOOL SelectVC1;
    ///  True to select the Virtual channel 2
    BOOL SelectVC2;
    ///  True to select the Virtual channel 3
    BOOL SelectVC3;
} MIPI_VCNum_t;

///  Frame clear enable structure for each MIPI Virtual channel
typedef struct
{
    /// True: Frame Counter is cleared at the end of frame for VC0
    BOOL ClearFrameVC0;
    /// True: Frame Counter is cleared at the end of frame for VC1
    BOOL ClearFrameVC1;
    /// True: Frame Counter is cleared at the end of frame for VC2
    BOOL ClearFrameVC2;
    /// True: Frame Counter is cleared at the end of frame for VC3
    BOOL ClearFrameVC3;

} MIPI_VCClearFrame_t;

///  to disable individual ADC channel structure for MIPI
typedef struct
{
    ///  True to disable  adc channel 1
    BOOL DisableADCChannel1;
    ///  True to disable  adc channel 2
    BOOL DisableADCChannel2;
    ///  True to disable  adc channel 3
    BOOL DisableADCChannel3;
    ///  True to disable  adc channel 4
    BOOL DisableADCChannel4;

} MIPI_DisableADCChannels_t;

///  Long packet Meta data configuration structure
typedef struct
{
    ///  Meta data User info
    uint32_t MetaData_LP_UserInfo;
    ///  Long packet length when user field is enabled
    uint16_t MetaData_LP_Length;
    ///  Long packet data type
    uint8_t MetaData_LP_DataType;
    ///  Long packet virtual channel selection
    uint8_t MetaData_LP_VC;
    ///  Delay between end of final chrp and start of meta data
    uint8_t MetaData_LP_StartDelay;
    ///  Long packet Enable
    BOOL MetaData_LP_En;
    ///  LOng packet user field enable
    BOOL MetaData_LP_UserFieldEn;
} MIPI_ConfigMetaData_t;

///  TE config profile information structure
typedef struct
{
    ///  Profile number
    SYS_ProfID_e ProfileNum;
    ///  Output sample rate
    TE_OutputSampRate_e OutSampRate;
    ///  Virtual channel number. Applicable only for CSI2 interface.
    SYS_VCN_e VirtualChNo;
    ///  Dwell time in us
    float32_t DwellTime;
    ///  Settle time in us
    float32_t SettleTime;
    ///  Transmission on delay from timing reference point
    float32_t TxOnDelayFromRefPoint;
    ///  Chirp period in us
    float32_t ChirpPeriod;
    ///  Phase control value for TX
    float32_t PRPhaseCtrlTx1;
    float32_t PRPhaseCtrlTx2;
    float32_t PRPhaseCtrlTx3;
    ///  Number of samples
    uint16_t NumSamples;
    ///  Trigger point for start of TX BPS and transmission enable time. 0/FALSE : Trigger point is start of Dwell time, 1/TRUE: Trigger point is start of Settle time
    BOOL TrigPoint;

    ///  Bandwidth of decimation filter in serialiser. 0/FALSE : Narrow bandwidth, 1/TRUE : Large bandwidth
    BOOL PDCBWWide;

    ///  Binary phase control for TxX. 0/FALSE : in phase, 1/TRUE: out of phase (180 deg)
    BOOL BPPhaseCtrlTx1;
    BOOL BPPhaseCtrlTx2;
    BOOL BPPhaseCtrlTx3;
    ///  Enable TX Transmission. 0/FALSE : Transmission disabled, 1/TRUE: Transmission enabled
    BOOL EnTx1;
    BOOL EnTx2;
    BOOL EnTx3;
    ///  Enable or disable TX module in an active chirp. 0/FALSE : TX disabled for current chirp, 1/TRUE: TX enabled for current chirp
    BOOL ActiveTx1;
    BOOL ActiveTx2;
    BOOL ActiveTx3;

    ///  Enable or disable RX module in an active chirp. 0/FALSE : RX disabled for current chirp, 1/TRUE: RX enabled for current chirp
    BOOL ActiveRx1;
    BOOL ActiveRx2;
    BOOL ActiveRx3;
    BOOL ActiveRx4;

} TE_ConfigProfile_t;

///  TE chirp trigger mode config struct
typedef struct
{
    TE_ChirpTrigMode_e ChirpTrigMode;

    ///  Dynamic power mode. 0/FALSE: No dynamic control, 1/TRUE: Dynamic control active at chirp level
    BOOL ChirpPowerMode;

    ///  Chirp start delay wrt 40MHz clock. 0/FALSE: One clock cycle of 40MHz, 1/TRUE: No delay
    BOOL ChirpStartDelay;

} TE_ChirpTrgMode_t;

///  TE CS Out config struct
typedef struct
{
    ///  CS In functionality selection
    TE_CSINFunSel_e CSINFunSel;
    ///  CS out functionality selection
    TE_CSOUTFunSel_e CSOUTFunSel;
    ///  CS out toggle mode
    TE_CSToggleMode_e ChirpStartOutMode;
    ///  Ready Interrupt mode (to be used with LVDS)
    TE_ReadyIntMode_e ReadyIntMode;
    /// CSI2 frame mode selection (equivalent of Ready Interrupt mode with LVDS). This parameter is ignored by API implementation
    TE_CSI2FrameMode_e CSI2FrameMode;
} TE_CSOutCfg_t;

///  Static configuration structure of Timing Engine
typedef struct
{
    ///  DC power on delay in us
    float32_t DCPowerOnDelay;

    ///  The time delay in us, for starting the safety monitoring from the reference point
    float32_t SafetyMontrDelay;
    ///  TX group delay in us
    float32_t TXGroupDelay;
    ///  RX group delay in us
    float32_t RXGroupDelay;

    ///  Group delay fine control for Tx1 and RX1 pair
    float32_t GDelayFineControl1;
    ///  Group delay fine control for Tx2 and RX2 pair
    float32_t GDelayFineControl2;
    ///  Group delay fine control for Tx3 and RX3 pair
    float32_t GDelayFineControl3;
    ///  Group delay fine control for RX4
    float32_t GDelayFineControl4;
    ///  Jump back time in us
    float32_t JumpBackTime;
    ///  Duration of a chirp sequence in us. In case of burst mode, it also includes idle time between sequences.
    float32_t SeqInterval;
    ///  Number of chirps within a chirp sequence
    uint16_t NumChirpInSeq;
    ///  Number of chirp sequences in a burst with a chirp start trigger
    uint32_t NumSeqInBurst;

    /**  Safety monitoring activation control. 0/FALSE: Monitoring starts at the expiry of safety monitor delay timer; 1/TRUE: Monitoring starts at (settle time - safety monitor delay */
    BOOL SafetyMontrActCtrl;
} TE_StaticConfig_t;

///  Dither Control structure information
typedef struct
{
    SC_DitherLevels_e NumLevelsDwellDither;
    SC_StartFreqDitherMode_e StartFreqDitherMode;
    SC_DitherLevels_e NumLevelsStartFreqDither;
    uint16_t StepSizeStartFreqDither;
    uint8_t StartFreqDitherAccuIncr;
    BOOL EnFractionalDelay;
    BOOL EnDwellDither;
    BOOL EnStartFreqDither;

} SC_DitherControl_t;

///  CAFC PLL loop filter setting LUT entry for ES2
typedef struct
{
    ///  PLL LPF bandwidth that the below settings will achieve.
    float32_t loopBW;
    uint8_t LPF_C1;
    uint8_t LPF_C2;
    uint8_t LPF_C3;
    uint8_t CP_SLICE_EN;
    uint8_t IBIAS_CP_150U;
    ///  Res value to compute Select loop filter res
    uint16_t R1;
} CAFC_LPFLUTEntry_t;

///  CAFC fast reset detail settings
typedef struct
{
    ///  GS signal is generated in chirp reset state. This field defines the delay of the GS signal generation from the chirp reset start point. Internally, he delay is represented in cycles of 480MHz clock. Supported values from 0 to 1 us
    float32_t GSDelayUs;
    ///  The field defines the pulse width of GearSwitch signal. Internally, the width is represented in cycles of 40MHz clock.Supported values from 0.5 to 5.5 us
    float32_t GSPulseWidthUs;
    CAFC_GSManualCtrl_e GSSignalOverride;
    CAFC_FastResetSigSel_e CPSliceGSControl;
    CAFC_FastResetSigSel_e CapGSControl;
} CAFC_GearSwitchtingSettings_t;

///  CAFC current injection setting for ACQ time
typedef struct
{
    CAFC_INJManualCtrl_e INJACQSignalOverride;
    ///  The dac_inj_acq signal is generated during the acquisition period and stays high during the tsettle + tacq. This field defines the delay of the dac_inj_acq signal from the start point tsettle. Internally, the delay is represented in cycles of 480MHz clock. Supported values from 0 to 1 us
    float32_t INJACQDelayUs;
    ///  TRUE: Negative polarity - idac sinking in acq, sourcing in rst (vtune falling in acq, rising in rst, downchirp), FALSE: Positive polarity - idac sourcing in acq, sinking in rst (vtune rising in acq, falling in rst, upchirp)
    BOOL IDACSinkACQ;
} CAFC_INJ_ACQ_t;

///  CAFC current injection settings for RST time
typedef struct
{
    CAFC_INJManualCtrl_e INJRSTSignalOverride;
    CAFC_FastResetSigSel_e INJRSTControl;
    ///  The dac_inj_rst signal is generated during the reset period and stays high during the treset. This field defines the delay of the dac_inj_rst signal from the start point treset. Internally, the delay is represented in cycles of 480MHz clock. Supported values from 0 to 1 us

    float32_t INJRSTDelayUs;
} CAFC_INJ_RST_t;

///  CAFC AAC detailed settings
typedef struct
{
    ///  AAC cycle time for current setting increment/decrement, recommended to use >1000NS options.
    CAFC_AACTRef_e AACRefTime;
    ///  When TRUE, use can override initial search value of VCO current, if FALSE, then default value is maximum value. So the VCO amplitude search will start from highest value, to ensure VCO will startup and stable.
    BOOL OverrideInitialVCOCurrent;
    ///  Override value when OverrideInitialVCOCurrent is set to TRUE
    uint8_t VCOOverrideCurrent;
    ///  Minimal allowed VCO current initial value
    uint8_t MinVCOCurrent;
    ///  Gain of the proportional control block (in a PI control loop), smaller gain will make calibration time longer. Default is maximal (7)
    uint8_t AACKi;
    ///  The criteria to determine the search is done. This control decides the number of stable amplitude iterations to generate the final aac_lock which finishes the calibration. Default is maximal (18 iterations). Possible settings are: 4,6,8,10,12,14,16,18 iterations. Note: the final register setting is (AACLockCriteria-4)/2.
    uint8_t AACLockCriteria;
} CAFC_AACSettings_t;

///  CAFC AFC detailed settings
typedef struct
{
    ///  AFC frequency counting period for divider VCO frequency
    CAFC_AFCTRef_e AFCRefTime;
    ///  AFC loop subband increment/decrement step, default is  e_CAFC_AFCSTEP_16
    CAFC_AFCStepLim_e AFCStepLimit;
    ///  When set to TRUE, override the initial subband in the loop
    BOOL OverrideInitialSB;
    ///  When OverrideInitialSB set to TRUE, use this to set the desired initial subband in the search
    uint8_t SBOverrideValue;
    ///  Minimal subband
    uint8_t MinSB;
    ///  Frequency control loop gain for first AFC loop, default is 7
    uint8_t AFCKi;
    ///  Frequency control loop gain for second AFC loop, default is 6
    uint8_t AFCKi2;
    ///  This is first frequency loop. This control decides the number of stable sub-band iterations to generate the final afc_lock. Default is 4 iterations. Range is 2-9
    uint8_t AFCLockCriteria1;
    ///  This is final frequency loop after amplitude calibration. This control decides the number of stable sub-band iterations to generate the final afc_lock. Default is 9 iterations. Range is 2-9
    uint8_t AFCLockCriteria2;
} CAFC_AFCSettings_t;

///  CAFC local errors
typedef struct
{
    ///  sweep control divide freq error
    BOOL SCDivideFreqErr;
    ///  in ISM VCOFrequency480Err is (SCDivideFreqErr||VCOFreq480Err)
    BOOL VCOFreq480Err;
    ///  digital chirp_afc stuckat / transient error
    BOOL AFCStuckatTransientErr;
    ///  digital sweep control stuckat/transient
    BOOL SCStuckatTransientErr;
    ///  digital timing engine stuckat/transient error
    BOOL TEStuckatTransientErr;
    /// digital combined stuckat/transient error
    BOOL CombinedStuckatTransientErr;
    ///  ACF register CRC error alone, in ISM  CAFCRegCRCErr is (AFC||TE||SC)
    BOOL AFCRegCRCErr;
    ///  digital sweep control reg crc error
    BOOL SCRegCRCErr;
    ///  digital timing engine control reg crc error
    BOOL TERegCRCErr;

} CAFC_LocalTestErrors_t;

///  CAFC lock detector detailed settings
typedef struct
{
    ///   Choose the polarity of the lock detector, For ES2 TRUE: negative polarity, used in upchirp; FALSE: positive polarity, used in downchirp
    BOOL NegPolLockDet;
    ///   Lock detector windows size, only used by ES1 sample
    uint8_t LockDetWinSize;
    ///   Lock detector window offset,
    uint8_t LockDetWinOffset;
} CAFC_LockDetSettings;

///  AAFC status
typedef struct
{
    /// Amplitude Calibration loop locked status
    BOOL AACLocked;
    /// Frequency Calibration loop locked status
    BOOL AFCLocked;
    /// VCO coarse frequency tuning (subband number)
    uint8_t AFCSubbandChoice;
    /// VCO current value (ivco_fine)
    uint8_t AACiVCOChoice;
} CAFC_AAFCStatus_t;

///  KVCO status
typedef struct
{
    uint16_t LowKvcoAvg;
    uint16_t HighKvcoAvg;
    BOOL KVCODone;
} CAFC_KVCOStatus_t;

///  DVDT status
typedef struct
{
    /// Frequency count value to calculate the chirp slope (dvdt) when the ctl_lpf_prog_force_voltage_ldvdt_spi is set
    uint16_t DVDTCntC1;
    /// Error status for dvdt 1 -  count done, 0 - count error
    BOOL DVDTDone;
} CAFC_DVDTStatus_t;

/// ADC clipping detector config struct
typedef struct
{
    /// Output level that triggers clipping detector for ADC_0
    uint16_t ClipLevelADC0;
    /// Output level that triggers clipping detector for ADC_1
    uint16_t ClipLevelADC1;
    /// Error count threshold that triggers the clipping counter exceeding error for ADC_0
    uint16_t ErrCntThresholdADC0;
    /// Error count threshold that triggers the clipping counter exceeding error for ADC_1
    uint16_t ErrCntThresholdADC1;
} ADC_ConfigClippingDet_t;

///  ADC background calibration control
typedef struct
{
    /// Number of weights to calibrate per power-save background calibration cycle
    uint8_t PowerSaveBGCalibrationWeights;
    ///  FALSE: no continuation of weight calibration after BG abort; TRUE: continuation of weight calibration after BG abort enabled
    BOOL EnContinuousBGCalibration;
    /// FALSE: simultaneous calibration; TRUE: interleaved operation during calibration
    BOOL EnInterleavedCalibration;
    /// FALSE: disable calibration of LSBs that are not part of the DEM array; TRUE: enable calibration of LSBs that are not part of the DEM array
    BOOL EnCalibrateLSBWeights;
    /// FALSE: no action; TRUE: automatically synchronize sequencer with other dual ADC after calibration
    BOOL AutoSyncSequencer;
    /// FALSE: no action; TRUE:  automatically calibrate the ADC after power-on
    BOOL AutoCalibrateAtPON;
} ADC_BackGroundCal_t;

/// ADC output mux setting
typedef struct
{
    /// DownSample mode on output data
    ADC_OutputDownSampleModes_e DownSampleMode;
    /// 0/FALSE: Output clock is not enabled; 1/True: Output clock is enabled;
    BOOL EnOutputClk;
    /// Inversion of the output clocks; 00: ADC_0 and ADC_1 are not inverted; 01: ADC_0 is inverted but ADC_1 is not; 10: ADC_1 is inverted but ADC_0 is not; 11: ADC_0 and ADC_1 are both inverted;
    uint8_t OutputClkInversion;
    ///  Operation mode for the ADC_1 output mux
    ADC_OutputMuxModes_e OutputMuxModeADC1;
    ///  Operation mode for the ADC_0 output mux
    ADC_OutputMuxModes_e OutputMuxModeADC0;
    ///  Constant debug value for the ADC_1 output mux
    uint16_t ConstantADC1;
    ///  4-bit offset value for the debug counter for the ADC_1 output mux
    uint8_t OffSetADC1;
    ///  Constant debug value for the ADC_0 output mux
    uint16_t ConstantADC0;
    ///  4-bit offset value for the debug counter for the ADC_0 output mux
    uint8_t OffSetADC0;
} ADC_OutputMuxSet_t;

///  Additional ADC local error,  these error are not present in ISM
typedef struct
{
    BOOL ADCBGCalAbortErr;
    BOOL ADCn1ClipThClipCountErr;
    BOOL ADCn0ClipThClipCountErr;
    BOOL ADCAnalogSupplyErr;
} ADC_LocalTestErrors_t;

/// LOx3 Gain config parameters - Control the lox3 gain of TX and RX from LO. There are also local lox3_gain settings in TX and RX to override this value
typedef struct
{
    /// Select which gain code to be used as common gain code for all TX
    LOI_LOx3TXGainSel_e TxLOx3GainSelect;
    /// Select which gain code to be used as common gain code for all RX
    LOI_LOx3RXGainSel_e RxLOx3GainSelect;
    /// Controls how the combined TX LOx3 gain code is calculated from the individual TX LOx3 calibration results
    LOI_LOx3MinMaxAvg_e TXMinMaxAvg;
    /// Controls how the combined RX LOx3 gain code is calculated from the individual RX LOx3 calibration results
    LOI_LOx3MinMaxAvg_e RXMinMaxAvg;
    /// LOx3 gain of TX
    uint8_t TxLOx3Gain;
    /// LOx3 gain of RX
    uint8_t RxLOx3Gain;
    /// Select rounding method when averaging mode is selected for TX
    BOOL TxGainAvgRoundUp;
    /// Select rounding method when averaging mode is selected for RX
    BOOL RxGainAvgRoundUp;
} LOI_LOx3GainConfig_t;

/// Detailed PLL calibration status
typedef struct
{
    /// Calibration active status
    BOOL PllCalibrationActive;
    /// Lock error after pll_calibration_active is deasserted
    BOOL PLLLockError;
    /// VCO level detect output (before FuSa latch)
    BOOL VcoLevelError;
    /// VCO recalibration indicator flag
    BOOL VcoLevelRecalib;
    /// Tuning voltage recalibration comparator output
    BOOL VcoFreqRecalib;
    /// VCO level recalibration comparator output
    BOOL VcoRecalibrate;
} MCLK_CalibrationStatus_t;

///  RX configure profiles struct
typedef struct
{
    ///  low-pass filter cutoff frequency
    SYS_RXLPF_CornerFreq_e LPFCutoffFreq;
    /// high-pass filter cutoff frequency
    SYS_RXHPF_CornerFreq_e HPFCutoffFreq;
    ///  RX gain control in dB
    RX_Gain_Control_e RXGain;
    /// FALSE: disable LPF wideband mode; TRUE: Enable LPF wideband mode
    BOOL EnLPFWideBandMode;
} RX_ConfigProfile_t;

///  TX safety state machine stop states, When certain element in the struct is set to TRUE, the transition from that state to other states is not possible.
typedef struct
{
    BOOL FSM_Stop_Safety_PR_RF;
    BOOL FSM_Stop_Safety_PR_INL;
    BOOL FSM_Stop_Safety_Cordic;
    BOOL FSM_Stop_End_Safety;
    BOOL FSM_Stop_Start_Safety;
} TX_SafetyFSMStopStates_t;

///  TX PR calibration state machine stop states, When certain element in the struct is set to TRUE, the transition from that state to other states is not possible.
typedef struct
{
    BOOL FSM_Stop_Cdic_Sel2;
    BOOL FSM_Stop_Idle;
    BOOL FSM_Stop_Start_Cal;
    BOOL FSM_Stop_PPD_Averaging;
    BOOL FSM_Stop_Cdic_Sel;
    BOOL FSM_Stop_VGA_Offset_Cal;
    BOOL FSM_Stop_VGA_Gain_Cal;
    BOOL FSM_Stop_PPD_Offset_Cal;
    BOOL FSM_Stop_PPD_Gain_Cal;
    BOOL FSM_Stop_PPD_Phase_Cal;
    BOOL FSM_Stop_End_Cal;
} TX_CalFSMStopStates_t;

///  TX local test errors
typedef struct
{
    BOOL TxPRRfErr;
    BOOL TxPRInlErr;
    BOOL TxPRCordicErr;
} TX_LocalTestErrors_t;

///  TX RF Calibration components
typedef struct
{
    /// LOx3 gain calibration start, This feature is not working, in application context this should be set as FALSE
    BOOL Lox3CalStart;
    /// Output power calibration start
    BOOL PoutCalStart;
    /// PR gain calibration start
    BOOL PrCalStart;
    /// PR phase calibration start
    BOOL PrPhaseCalStart;
    /// VGA gain calibration start
    BOOL VgaCalStart;
    /// PPDs offsets calibration start
    BOOL PPDOffsetCalStart;
} SYS_EnableTxRfCalibration_t;

/// Define the way the binary search is performed to decide calibration values
typedef struct
{
    /// Set whether PPDLOX3 calibration result should be above(1) or below(0) the threshold
    BOOL PpdLox3BinSearch;
    /// Set whether PPD PR calibration result should be above(1) or below(0) the threshold
    BOOL PpdPrBinSearch;
    /// Set whether PPD VGA calibration result should be above(1) or below(0) the threshold
    BOOL PpdVgaBinSearch;
    /// Set whether RFLOX3 calibration result should be above(1) or below(0) the threshold
    BOOL RfLox3BinSearch;
    /// Set whether RF PR calibration result should be above(1) or below(0) the threshold
    BOOL RfPrBinSearch;
    /// Set whether RF VGA calibration result should be above(1) or below(0) the threshold
    BOOL RfVgaBinSearch;
    /// Set whether POUT calibration result should be above(1) or below(0) the threshold
    BOOL PoutBinSearch;
} TX_EnableBinarySearch_t;

///  TX local calibration status.
typedef struct
{
    /// PPD Offset LOX3 calibration status
    ISM_Cal_Status_e PpdOffsetLox3Cal;
    /// PR PPD offset calibration status
    ISM_Cal_Status_e PpdOffsetPrCal;
    /// VGA PPD offset calibration status
    ISM_Cal_Status_e PpdOffsetVgaCal;
    /// LOx3 calibration status
    ISM_Cal_Status_e RfLox3Cal;
    /// PR calibration status
    ISM_Cal_Status_e RfPrCal;
    /// VGA calibration status
    ISM_Cal_Status_e RfVgaCal;
    /// RF_PR Phase Calibration status
    ISM_Cal_Status_e RfPrPhaseCal;
    /// Pout calibration status
    ISM_Cal_Status_e PoutCal;
    /// TX PR safety check status
    ISM_Cal_Status_e TxPrSafetyCheck;
    /// Indicates the calibration state of the Calibration state machine for rf_pr_phase_cal, pout_cal, rf_vga, rf_pr, rf_lox3, ppd_offset, ppd_comp, ppd_vga
    uint8_t TXCalibState;
    /// Overall TX Calibration Status 1: Calibration in-progress 0: Calibration not active
    BOOL TXCalibBusy;
} TX_CalibrationStatus_t;

///  TX Calibration Time configuration structure.
typedef struct
{
    ///  maximum allowed time is 6.375us
    float32_t PoutDetCountThreshold;
    ///  maximum allowed time is 6.375us
    float32_t RFDetCountThreshold;
    ///  maximum allowed time is 6.375us
    float32_t PPDDetCountThreshold;
    ///  maximum allowed time is 6.375us
    float32_t MonDetCountThreshold;
} TX_CalibrationTime_t;

///  SSB configure RFBIST struct
typedef struct
{
    /// First divider to calculate the IF frequency
    uint8_t Divider1;
    /// Second divider to calculate the IF frequency
    uint8_t Divider2;
    /// SSB modulator output level
    uint8_t OutputLevel;
    /// IF signal level
    uint8_t IFLevel;
    /// Enable SSB modulator
    BOOL EnSSBMod;
    /// Enable 600 Mhz clock from master clock
    BOOL EnCLK600;
    ///  To select if the IF signal source is internal or external. Default is internal.
    BOOL EnExtSignalGen;
} SSB_ConfigRFBIST_t;

/// GLDO mask force errors struct
typedef struct
{
    BOOL MaskForceCRCRegErr;
    BOOL MaskForceSupply1v8HighErr;
    BOOL MaskForceSupply1v8LowErr;
    BOOL MaskForceSupply1v1HighErr;
    BOOL MaskForceSupply1v1LowErr;
} GLDO_MaskForceErr_t;

/// GLDO mask reset errors struct
typedef struct
{
    BOOL MaskResetCRCRegErr;
    BOOL MaskResetSupply1v8HighErr;
    BOOL MaskResetSupply1v8LowErr;
    BOOL MaskResetSupply1v1HighErr;
    BOOL MaskResetSupply1v1LowErr;
} GLDO_MaskResetErr_t;

/// GLDO force errors struct
typedef struct
{
    BOOL ForceCRCRegErr;
    BOOL ForceSupply1v8HighErr;
    BOOL ForceSupply1v8LowErr;
    BOOL ForceSupply1v1HighErr;
    BOOL ForceSupply1v1LowErr;
} GLDO_ForceErr_t;

/// GLDO mask errors struct
typedef struct
{
    BOOL MaskCRCRegErr;
    BOOL MaskSupply1v8HighErr;
    BOOL MaskSupply1v8LowErr;
    BOOL MaskSupply1v1HighErr;
    BOOL MaskSupply1v1LowErr;
} GLDO_MaskErr_t;

/// GLDO OVUV deglitch width
typedef struct
{
    uint8_t Supply1V8HighDeglitchThreshold;
    uint8_t Supply1V8LowDeglitchThreshold;
    uint8_t Supply1V1HighDeglitchThreshold;
    uint8_t Supply1V1LowDeglitchThreshold;
} GLDO_OVUVThreshold_t;

///  ATB local switches inside ATB IP, name is similar to design name
typedef struct
{
    BOOL ADCSwpSwitch;
    BOOL ATBReadRTrimSwitch;
    BOOL BISTADCGndSwitch;
    BOOL EnRTrimSwitch;
    BOOL RTrimGndSwitch;
} ATB_LocalSwitches_t;

/// OTP load chip information struct
typedef struct
{
    ///  LOTID ASCII 8 chars are located at  LotID_MSB[31:0] & LotID_LSB[31:0] Ex: Lot ID=S63823.5 here 'S' is first character is located at LotID_MSB[31:24] & '5' is an eighth character located at LotID_LSB[7:0]
    uint32_t LotID_MSB;
    uint32_t LotID_LSB;
    ///  Variant Type 8233 from the product type TEF8223
    uint16_t Variant_Type;
    uint8_t Wafer;
    uint8_t Wafer_X_Position;
    uint8_t Wafer_Y_Position;
    uint8_t MaskVersion;
    uint8_t WT_SITE;
    uint8_t WT_TP_Version_Major;
    uint8_t WT_TP_Version_Minor;
    uint8_t FT_TP_Version_Major;
    uint8_t FT_TP_Version_Minor;
    ///  DD/MM/YY
    uint8_t WT_Day;
    uint8_t WT_Month;
    uint8_t WT_Year;
    ///  B3 Silicon identifier
    uint8_t MaskVersionMinor;
} OTP_ChipInfo_t;

/// OTP mask force errors struct
typedef struct
{
    BOOL MaskForceCRCRegErr;
    BOOL MaskForceSupply1v8HighErr;
    BOOL MaskForceSupply1v8LowErr;
    BOOL MaskForceSupply1v1HighErr;
    BOOL MaskForceSupply1v1LowErr;
} OTP_MaskForceErr_t;

/// OTP backdoor access struct
typedef struct
{
    BOOL DisableChirp5GMode;
    BOOL DisablePR;
    BOOL DisableLOIn;
    BOOL DisableLOOut;
    BOOL DisableRX1;
    BOOL DisableRX2;
    BOOL DisableRX3;
    BOOL DisableRX4;
    BOOL DisableTX1;
    BOOL DisableTX2;
    BOOL DisableTX3;
    BOOL DisableLVDS;
    BOOL DisableCSI2;
} OTP_BackdoorAccess_t;

/// OTP table description struct
typedef struct
{
    ///  the SrcAddr is the relative address in the OTP table (starting from 0, step of 4)
    uint8_t SrcAddr;
    /// Bit field start position in source table
    uint32_t SrcPos;
    ///  Bit field mask in source table
    uint32_t SrcMsk;
    /// Destination module SPI address
    SYS_IPNum_e DstMod;
    /// Destination register address
    uint16_t DstReg;
    /// Bit field start position in destination register
    uint32_t DstPos;
    /// Bit field mask in destination register
    uint32_t DstMsk;
} OTP_TableDescrip_t;

/// OTP mask reset errors struct
typedef struct
{
    BOOL MaskResetCRCRegErr;
    BOOL MaskResetSupply1v8HighErr;
    BOOL MaskResetSupply1v8LowErr;
    BOOL MaskResetSupply1v1HighErr;
    BOOL MaskResetSupply1v1LowErr;
} OTP_MaskResetErr_t;

/// OTP force errors struct
typedef struct
{
    BOOL ForceCRCRegErr;
    BOOL ForceSupply1v8HighErr;
    BOOL ForceSupply1v8LowErr;
    BOOL ForceSupply1v1HighErr;
    BOOL ForceSupply1v1LowErr;
} OTP_ForceErr_t;

/// OTP mask errors struct
typedef struct
{
    BOOL MaskCRCRegErr;
    BOOL MaskSupply1v8HighErr;
    BOOL MaskSupply1v8LowErr;
    BOOL MaskSupply1v1HighErr;
    BOOL MaskSupply1v1LowErr;
} OTP_MaskErr_t;

/// OTP reset errors struct
typedef struct
{
    BOOL ResetCRCRegErr;
    BOOL ResetSupply1v8HighErr;
    BOOL ResetSupply1v8LowErr;
    BOOL ResetSupply1v1HighErr;
    BOOL ResetSupply1v1LowErr;
} OTP_ResetErr_t;

///  ISM FTTI Watch Dog Timer config struct
typedef struct
{
    ///  Watchdog Time Period
    float32_t WDTTimePeriod;
    /**  @brief WDT modes
  - 0: Moonshot Mode( once only)
  - 1: Continuous Mode (for each Chirp Sequence)
 */
    BOOL WDTMode;
    ///  True: enable the WDT
    BOOL EnWDT;
} ISM_ConfigWDT_t;

/// ISM RTM Safety Error Count Threshold struct
typedef struct
{ /// RT Error Poll Count Value
    uint8_t PollCount;
    /// RTM Error Safety Count Max Threshold  Value
    uint8_t MaxThresholdVal;
} RTMSafetyErrCnttThreshold_t;

/// ISM RF Power Down Error Count Threshold struct
typedef struct
{ /// RT Error Poll Count Value
    uint8_t PollCount;
    /// RTM Error Safety Count Max Threshold  Value
    uint8_t MaxThresholdVal;
} RFPowrDwnErrCntThreshold_t;

/// ISM First Error warning structure
typedef struct
{
    /** @brief Module id of the module in error
    Id The module ID of the warning
    3'000 : No Error
    3'b001 :  TX
    3'b010 :  RX
    3'b011 :  CHIRP
    3'b100 :  MC_LO_CC_ISM_OTP
    3'b101 :  SSB_GB_SER_GLDO_ATB
    3'b110 :  ADC
    3'b111 :  Supply
    */
    uint8_t ErrorModuleID;
    ///  Sequence number at which the warning occurred
    uint8_t SequenceNum;
    ///  Chirp number at which the warning occurred
    uint16_t ChirpNum;
    ///  Profile number at which the warning occurred
    uint8_t ProfileNum;
    /** Warning occurred instance
      - 0 : Warning occurred Outside Acquisition
      - 1 : Warning occurred Inside Acquisition
    */
    BOOL ErrInsideAcquisition;
    /** FirstErrorStatusDump for both first masked error status and warning status
     */
    uint32_t FirstErrorStatusDump;
} ISM_FirstErrWarning_t;

///  ISM FIT test Status
typedef struct
{
    ISM_FITTestState_e ISMFITCurrentstate;
    BOOL ISMOSMResetErr;
    BOOL ISMOSMForceErr;

    ///  True: FIT test successful
    BOOL FITRFPowerDownErr1;
    BOOL FITRFPowerDownErr0;
    BOOL FITRtmErr1;
    BOOL FITRtmErr0;
} ISM_FITStatus_t;

#if defined(__cplusplus)
}
#endif
#endif
