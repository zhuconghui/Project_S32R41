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
 @file bc_conf.h
 @version
 @brief Barracuda API configuration file
 */
 #ifndef BC_CONF_H
 #define BC_CONF_H


#include <stdint.h>
#include <math.h>
 #if defined(__cplusplus)
 extern "C"
 {
 #endif
 // Following will be updated before release
#define BC_API_MAJOR_VERSION (9u)
#define BC_API_MINOR_VERSION (3u)
#define BC_API_PATCH_VERSION (0u)

 //CAFC frequency counting timeout
 #define CAFC_FREQ_CNT_TIMEOUT (100000u)
 #define CAFC_MEASUREDVDT_SLEEP (3u)
 #define CAFC_READFREQCOUNTER_SLEEP (3u)
 #define CAFC_DVDT_MAXIMUM_COUNT (1000u)
 #define BC_CAFC_FAST_BIAS_CHIRP_PLL_SLEEP (5u)
 // subband search value 1G  we should start search from lower sub band 
 #define BC_CAFC_AFC_FSEL_INIT_OVERRIDE_VALUE_1G_VCO 60u
 // subband search value 2G and 4G VCO, we should start search from lower sub band 
 #define BC_CAFC_AFC_FSEL_INIT_OVERRIDE_VALUE_2G_4G_VCO 30u
 #define BC_CAFC_AFC_MAX_SB_VALUE_1G_2G_VCO 127u
 #define BC_CAFC_AFC_MAX_SB_VALUE_4G_VCO 63u
 #define BC_CAFC_AFC_SKIPSB_CHECK_1G_2G_VCO 64u
 #define BC_CAFC_AFC_SKIPSB_CHECK_4G_VCO 32u



 #define ATB_BISTADC_TIMEOUT (100000u)
 #define ATB_ReadBISTADC_SLEEP (3u)
 #define SSB_ENABLELDO_SLEEP (20u)
 #define ADC_CALIBRATION_TIMEOUT (200u)
 #define ADC_CHECKCALRESULT_SLEEP (10u)
 #define ADC_WAIT_FOR_CALIBRATION_READY_US (3100u)
 #define ATB_RESISTOR_OHM (2000.0f)
 #define LPF_ATB_RES_RATIO (1.252f)
 #define VCO_MIN_SLICE_CURRENT (62.5f)
 
 #define ADC_RECALBRATION_COUNT (4u)
 
 #define MIPI_FREQ_COUNT_TIMEOUT    (100000u)
 #define MIPI_MEASUREFREQ_SLEEP (3u)
 #define MIPI_PLL_READY_TIMEOUT      (100000u)
 #define MIPI_CONFIG_SLEEP (3u)
 #define MIPI_IDEAL480_DEFAULT_VALUE (480.0f)
 #define MIPI_REFCOUNT_DEFAULT_VALUE (40u)
 #define LVDS_WAIT_FOR_READY_TIMEOUT (100000u)
 #define LVDS_MEASUREFREQ_SLEEP (3u)
 #define LVDS_IDEAL480_DEFAULT_VALUE (480.0f)
 #define LVDS_REFCOUNT_DEFAULT_VALUE (40u) 
 #define MIPI_LVDS_MAX_FREQ_COUNT_PERIOD  (136.53125f)
 #define SYS_CONVERT_TIMEUS_TO_40MHZCYCLE(timeus)        (uint32_t)(lroundf((timeus) * 1000.0f / 25.0f))
 #define SYS_RMS_IMPEDANCE (100u)// to be confimred.
 #define SYS_LDO_SETTLE_TIME 50u  /*TBD: To be confirmed, currently 50us*/

#define SYS_INIT_HRESET_TIME   (2u) 

//RawNumSample Divisibility check for various decimation factors
#define SYS_NUM_SAMP_DIV_ODD_MASK   (1u)
#define SYS_NUM_SAMP_DIV_BY_4_MASK  (3u)
#define SYS_NUM_SAMP_DIV_BY_8_MASK  (7u)
#define SYS_NUM_SAMP_DIV_BY_16_MASK (15u)
#define SYS_MAX_PROFILE_COUNT (9u)

 //Attenuation factors
 #define SYS_RMS_ATT_SSB (0.0f)
 #define SYS_RMS_ATT_RX (17.5f)
 #define SYS_RMS_ATT_TX   (12.0f)
 #define SYS_RMS_ATT_CAFC (15.0f)
 #define SYS_RMS_ATT_LOI (8.0f)
 #define SYS_TEMP_DIGITIZER_DELAY (0x2u)
 #define SYS_TEMP_MEASUREMENT_DELAY_24US (24u)

 #define TX_PRC_ADC_DATAOUT_TIMEOUT (100000u)
 #define TX_READPRCADC_SLEEP (3u)
 #define TX_ACTIVE_DELAY_DEFAULT (40u)
 
 #define TX_MAX_CURRENT_GAIN_CODE_FLOAT (255.0f)
 #define TX_MAX_CURRENT_GAIN_CODE_UINT8 ((uint8_t)255u)
 #define TX_CHECK_CAL_RESULT_SLEEP    (3u)
 /* Assuming 5us as avg SPI read time and 3us sleep every iteration, polling for TX calibration complete is done for ~900us in worst case before timeout */
 #define TX_CALIBRATION_TIMEOUT (120u)

#define SYS_NUM_MAX_DEVICE 4u
#define SYS_RECOVERY_TIME_TEMP_ERR (10000u) 
#define SYS_WAIT_TIMEOUT_10US (10u)
#define SYS_WAIT_TIMEOUT_100US (100u)
#define SYS_WAIT_TEMP_MEASUREMENT_TIMEOUT (200u)
#define SYS_WAIT_TO_READ_ISMFLAG (2u)
#define SYS_WAIT_TO_TRIGGER_AAFC_150US (150.0f)
#define SYS_WAIT_TO_TRIGGER_AAFC_200US (200.0f)
#define SYS_WAIT_CENTER_TO_MID_FREQ_30US (30u)

#define SYS_TE_PROFILE_REG_NUM (4u)
#define SYS_SC_PROFILE_REG_NUM (6u)
#define SYS_CAFC_PROFILE_REG_NUM (4u)
#define SYS_CAFC_PROFILE_ES2_REG_GAP (2u)
#define SYS_RX_PROFILE_REG_NUM (4u)
#define SYS_TX_PROFILE_REG_NUM (2u)
#define SYS_REGCRC_ERROR_INJECTION_RESET_VALUE 0x0u
#define SYS_REGCRC_ERROR_INJECTION_FORCE_VALUE 0x5u
#define SYS_SYS_REGCRC_TRGGER_WAIT  12u

#define MCLK_SERCLK_FREQ_COUNT_TIME (10.0f)
#define MCLK_SERCLK_FREQ_TOLERANCE_HZ (500000.0f)
#define MCLK_SERCLK_REF_FREQUENCY (480000000.0f)
#define MCLK_PLL_CALIBRATION_TIME_US (400u) // can be changed after validation results 
#define MCLK_PLL_RECALIBRATION_TIME_US (103u) // can be changed after validation results 
#define MCLK_PLL_INIT_STABILISE_TIME (550u)
#define MCLK_PLL_INIT_STABILISE_TIME_FIX (550u)
#define MCLK_MSPC_ADDITIONAL_WAIT_TIME_US   (5u)
#define MCLK_MSPC_ADDITIONAL_CHECK_TIME_US  (5u)
#define MCLK_MSPCTIMEOUT_TIMEOUT         (200u)
#define MCLK_STARTMSPC_SLEEP (3u)
#define MCLK_MSPC_MEASURE_WAIT_TIME     (8u)  //mspc_measure_wait_time
#define MCLK_MSPC_PLLSKEW_WAIT_TIME     (40u) // mspc_pll_skew_wait_time
#define MCLK_MSPC_CALIB_ONEROUND_WAIT_TIME  (MCLK_MSPC_PLLSKEW_WAIT_TIME+MCLK_MSPC_MEASURE_WAIT_TIME)
#define MCLK_MSPC_CHECK_TOTAL_WAIT_TIME  (2u*MCLK_MSPC_CALIB_ONEROUND_WAIT_TIME)
 //TE Wait for ready timeout (us)
 #define TE_WAITFORREADY_TIMEOUT (100000u)
 #define TE_WAITFORREADY_SLEEP (20u)
 #define TE_DCPOWERONDELAY_MIN (10.0f)
 #define TE_DCPOWERONDELAY_MAX (1638.35f) /* 16 bit max value - 1 divide by 40 */
 #define TE_DELAY_MIN          (0.025f) 
 #define TE_SAFETYMONDELAY_MAX (102.35f) /* 12 bit max value - 1 divide by 40 */
 #define TE_PRSAFETYSTARTDELAY_MAX (102.35f) /* 12 bit max value - 1 divide by 40 */
 #define TE_RXACTIVEDELAY_MAX  (6.35f) /* 8 bit max value - 1 divide by 40 */
 #define TE_HPFRESETDELAY_MAX  (6.35f) /* 8 bit max value - 1 divide by 40 */

 #define LO_GAIN_BIST_MAX_MILLIVOLT (1800.0f) //this value needs further confimration
 #define BISTADC_LSB_MILLIVOLT (3.5f)

 /* Sweep Control input reference clock */
#define SC_REF_FREQ              (480.0e6f)
 /* fixed freqeuncy divider in the feedback loop of PLL */
#define SC_FREQ_DIV_PRESCALER    (2.0f)
 /*frequency trippler after the output of LO */
#define SC_FREQ_MULTIPLIER       (3.0f)

/* SC_REF_FREQ * SC_FREQ_DIV_PRESCALER * SC_FREQ_MULTIPLIER */
#define SC_FREQ_DIVIDER (2880.0e6)
/* RampTimeMultiplier (480e6/SC_UPDATE_DIV/1e6)
   RampTimeMultiplier = 480e6/6/1e6 = 80. 
*/
#define SC_RAMPTIME_MULTIPLIER      (80.0f)  

/*Sweep Control divider for setting update rate of accumulator */
/*While updating the register, less than one to be done*/
#define SC_UPDATE_DIV           (6u)

/*67108864.0f corresponds to 1u << 26u */
#define SC_ONE_LSH_26F   (67108864.0)

///the ratio to convert RF freqeuncy to PLL divider value
/// SC_FREQ2DIV = SC_ONE_LSH_26F/ SC_REF_FREQ / SC_FREQ_DIV_PRESCALER / SC_FREQ_MULTIPLIER = 0.023301689
/// SC_FREQ2DIV is equal to (67108864.0)/480e6/2/3) = 0.023301689

#define SC_FREQ2DIV                         ((BC_FLOAT)0.0233016889)
//TODO: Change to correct range 74e9, 83e9
#define SC_AUTO_RADAR_LOWER_END             ((BC_FLOAT)70e9)
#define SC_AUTO_RADAR_UPPER_END             ((BC_FLOAT)87e9)
/* Max bandwidth for 1GHz VCO   */
#define SC_TOTAL_BW_1G_BAND_MAX             ((BC_FLOAT)1.4e9)
/* Max bandwidth for 5GHz VCO, working in 2GHz bandwidth mode */ 
#define SC_TOTAL_BW_5G_NARROW_MAX           ((BC_FLOAT)3.3e9)
/* Max bandwidth for 5GHz VCO, working in 4GHz bandwidth mode */
#define SC_TOTAL_BW_5G_WIDE_MAX             ((BC_FLOAT)5.2e9)

/* Lowest bandwidth in Hz for chirp profile */
#define SC_AUTO_RADAR_USED_BW_LOW            ((BC_FLOAT)0.0)
/* Highest bandwidth in Hz for chirp profile */
#define SC_AUTO_RADAR_USED_BW_HIGH           ((BC_FLOAT)6e9)
/* Minimum Ramp-up time in us, of the chirp profile */
#define SC_AUTO_RADAR_RAMP_TIME_MIN          (1.0f)
/* Minimum Reset time in us, of the chirp*/
#define SC_AUTO_RADAR_RESET_TIME_MIN         (0.5f)
/* Maximum Ramp-up time in us, of the chirp profile - Practical values need to be updated later */
#define SC_AUTO_RADAR_RAMP_TIME_MAX          (3276.0f)
/* Maximum Reset time in us, of the chirp - Practical values need to be updated later */
#define SC_AUTO_RADAR_RESET_TIME_MAX         (3276.0f)


//time needed for local LDO stablization
#define LOCAL_LDO_STABLIZATION_US (30u)

//the time needed for the GBIAS stabilization
#define GBIAS_WAIT_FOR_STABILIZATION_US   (5u)

// Error Recovery Funtion Default values 

#define RECOVERERR_TX_GAIN_DEFAULT_SETTING    (0x80u)
#define RECOVERERR_LO_GAIN_DEFAULT_SETTING    (0x0Fu)
#define RECOVERERR_MSPC_MSPC_WAITTIME     (e_MCLK_MSPC_WAITTIME_64US)
#define RECOVERERR_MSPC_SKEW_WAITTIME     (e_MCLK_MSPC_PLLSKEW_WAITTIME_5US)
#define RECOVERERR_MSPC_DELAY_WAITTIME    (e_MCLK_MSPC_DELAY_WAITTIME_200NS) 
#define RECOVERERR_DCPOWERONDELAY_DEFAULT     (250.0f)  
#define RECOVERERR_SAFETYMONTRDELAY_DEFAULT   (102.0f)
#define RECOVERERR_SAFETYMONTRACTCTRL_DEFAULT ((BOOL)FALSE)
#define RECOVERERR_ENPRSAFETYCHECK_DEFAULT    ((BOOL)TRUE)
#define RECOVERERR_ENPRCALIB_DEFAULT          ((BOOL)TRUE)
#define RECOVERERR_PRCALIBSTARTDELAY_DEFAULT   (150.0f) 
#define RECOVERERR_PRSAFETYSTARTDELAY_DEFAULT  (18.0f) 

#define RECOVERERR_CHIRP_AFC_KICTRL1_DEFAULT   0x06u
#define RECOVERERR_CHIRP_AFC_KICTRL2_DEFAULT   0x07u
#define RECOVERERR_CHIRP_AAC_KI_DEFAULT        0x04u

#define RECOVERERR_CHIRP_SUBBAND_DEFAULT        0x010u
#define RECOVERERR_CHIRP_CURRENT_DEFAULT        0x0Fu

#define HRESET_N_PIN_ID           0xFFu /*TBD*/

//ISM
#define MAX_ERROR_REPORT         5u
#define MAX_ERROR_REPORT_WITH_CAL (MAX_ERROR_REPORT + 12u)
//Module ID Macros
#define SSB_GB_SER_GLDO_ATB     0x5
#define MC_LO_CC_ISM_OTP        0x4
#define TX_MODULE_ID        	0x1
#define RX_MODULE_ID        	0x2
#define CHIRP_MODULE_ID        	0x3
#define ADC_MODULE_ID        	0x6

//Interface internal Pin ID for toggle test.
#define ERRORRESET_DIR_POS    19u
#define ERRORRESET_DATA_POS   3u
#define CHIRPSTART_DIR_POS    16u
#define CHIRPSTART_DATA_POS   0u
#define READYINT_DIR_POS      17u
#define READYINT_DATA_POS     1u
#define ERRORN_DIR_POS        18u
#define ERRORN_DATA_POS       2u
#define TX1_I_PS_DIR_POS      20u
#define TX1_I_PS_DATA_POS     4u
#define TX2_I_PS_DIR_POS      21u
#define TX2_I_PS_DATA_POS     5u
#define TX3_I_PS_DIR_POS      22u
#define TX3_I_PS_DATA_POS     6u
#define TX1_Q_PS_DIR_POS      24u
#define TX1_Q_PS_DATA_POS     8u
#define TX2_Q_PS_DIR_POS      25u
#define TX2_Q_PS_DATA_POS     9u
#define TX3_Q_PS_DIR_POS      26u
#define TX3_Q_PS_DATA_POS     10u

#define OTP_LUT_SIZE (64u) //OTP lookup table size
#define OTP_MAGICCHECK (0x2144DF1Cu)
#define OTP_ID_WT_MAJOR_POS  (8u)  
#define OTP_ID_WT_MAJOR_MASK  (0x00007F00u)  
#define OTP_ID_WT_MINOR_MASK  (0x0000007Fu)
#define OTP_ID_FT_MAJOR_POS  (8u)  
#define OTP_ID_FT_MAJOR_MASK  (0x00007F00u)  
#define OTP_ID_FT_MINOR_MASK  (0x0000007Fu)  

#ifdef TEF82XX_CFG_ES2
#define OTP_TP_WT_CRC_EN_MAJOR_VERSION       (2u)
#define OTP_TP_FT_CRC_EN_MAJOR_VERSION       (2u)
#define OTP_TP_FT_CRC_EN_MINOR_VERSION       (10u)
#define OTP_TP_FT_LOI_MAJOR_VERSION          (2u)
#define OTP_TP_FT_LOI_MINOR_VERSION          (50u)
#define OTP_TP_WT_LOI_MAJOR_VERSION          (2u)
#define OTP_TP_WT_LOI_MINOR_VERSION          (50u)
#define OTP_TP_FT_TX_ANCHOR_MAJOR_VERSION    (2u)
#define OTP_TP_FT_TX_ANCHOR_MINOR_VERSION    (0u)
#define OTP_TP_WT_TX_ANCHOR_MAJOR_VERSION    (2u)
#define OTP_TP_WT_TX_ANCHOR_MINOR_VERSION    (0u)
#define OTP_TP_WT_GLDO_MAJOR_VERSION         (0u)
#define OTP_TP_WT_GLDO_MAJOR_VERSION_EXT     (2u)
#define OTP_TP_FT_GLDO_MAJOR_VERSION         (2u)
#define OTP_TP_FT_MINI_MATRIX_MAJOR_VERSION  (2u)
#define OTP_TP_FT_VTUNE_MATRIX_MAJOR_VERSION (3u)
#define OTP_TP_FT_MINI_MATRIX_MINOR_VERSION  (11u)
#define OTP_TP_WT_MINI_MATRIX_MAJOR_VERSION  (2u)
#define OTP_TP_WT_VTUNE_MATRIX_MAJOR_VERSION (3u)
#define OTP_TP_WT_MINI_MATRIX_MINOR_VERSION  (11u)
#define OTP_TEST_CONTROL_INDEX               (0u)
#define OTP_DIE_ID_1_INDEX                   (1u)
#define OTP_DIE_ID_2_INDEX                   (2u)
#define OTP_DIE_ID_3_INDEX                   (3u)
#define OTP_TP_ID_WT_INDEX                   (4u)
#define OTP_TP_ID_FT12_INDEX                 (5u)
#define OTP_TP_ID_FT34_INDEX                 (6u)
#define OTP_TP_ID_MISC_INDEX                 (7u)
#define OTP_TP_ID_ACCU_INDEX                 (8u)
#define OTP_WH_GLDO_1V8_47_INDEX             (9u)
#define OTP_WH_GLDO_1V8_03_INDEX             (10u)
#define OTP_WH_GLDO_1V1_47_INDEX             (11u)
#define OTP_WH_GLDO_1V1_03_INDEX             (12u)
#define OTP_WH_MISC_INDEX                    (13u)
#define OTP_TRIM_TS_THRESH_INDEX             (14u)
#define OTP_TRIM_TX_TS_COEFF_INDEX           (15u)
#define OTP_TRIM_CHIRP_TS_COEFF_INDEX        (16u)
#define OTP_TRIM_SNS_INDEX                   (17u)
#define OTP_TRIM_GBIAS_INDEX                 (18u)
#define OTP_TRIM_LOCAL_LDO_INDEX             (19u)
#define OTP_TRIM_RX1_THRESH_INDEX            (20u)
#define OTP_TRIM_RX2_THRESH_INDEX            (21u)
#define OTP_TRIM_RX3_THRESH_INDEX            (22u)
#define OTP_TRIM_RX4_THRESH_INDEX            (23u)
#define OTP_TRIM_RX1_FILTER_INDEX            (24u)
#define OTP_TRIM_RX2_FILTER_INDEX            (25u)
#define OTP_TRIM_RX3_FILTER_INDEX            (26u)
#define OTP_TRIM_RX4_FILTER_INDEX            (27u)
#define OTP_TRIM_TX_BIAS_ST3_INDEX           (28u)
#define OTP_TRIM_TX_BIAS_ST12_INDEX          (29u)
#define OTP_TRIM_TX1_THRESH_INDEX            (30u)
#define OTP_TRIM_TX2_THRESH_INDEX            (31u)
#define OTP_TRIM_TX3_THRESH_INDEX            (32u)
#define OTP_TRIM_LOI_THRESH_INDEX            (33u)
#define OTP_TRIM_CHIRP_THRESH_INDEX          (34u)
#define OTP_TRIM_SUBBAND_CORRECTION_1G_INDEX (35u)
#define OTP_TRIM_SUBBAND_CORRECTION_2G_INDEX (36u)
#define OTP_TRIM_SUBBAND_CORRECTION_4G_INDEX (37u)
#define OTP_SPARE_TRIM_INDEX                 (38u)
#define OTP_TRIM_WR_PTAT_INDEX               (39u)
#define OTP_TRIM_FR_GLDO_INDEX               (40u)
#define OTP_CAL_BISTADC1_INDEX               (41u)
#define OTP_CAL_BISTADC2_INDEX               (42u)
#define OTP_CAL_RMS_OFFSET_TX_INDEX          (43u)
#define OTP_CAL_RMS_OFFSET_RX_INDEX          (44u)
#define OTP_CAL_RMS_OFFSET_CHIRP_SSB_INDEX   (45u)
#define OTP_CAL_RMS_GAIN_TX_INDEX            (46u)
#define OTP_CAL_RMS_GAIN_RX_INDEX            (47u)
#define OTP_CAL_RMS_GAIN_CHIRP_SSB_INDEX     (48u)
#define OTP_CAL_CHIRP_INJ_DAC_1_INDEX        (49u)
#define OTP_CAL_CHIRP_INJ_DAC_2_INDEX        (50u)
#define OTP_CAL_CHIRP_INJ_DAC_3_INDEX        (51u)
#define OTP_CAL_CHIRP_INJ_DAC_4_INDEX        (52u)
#define OTP_CAL_CHIRP_INJ_DAC_5_INDEX        (53u)
#define OTP_CAL_CHIRP_INJ_DAC_6_INDEX        (54u)
#define OTP_CAL_CHIRP_INJ_DAC_7_INDEX        (55u)
#define OTP_CAL_CHIRP_INJ_DAC_8_INDEX        (56u)
#define OTP_CAL_CHIRP_INJ_DAC_9_INDEX        (57u)
#define OTP_CAL_CHIRP_76G_INDEX              (58u)
#define OTP_SPARE_0EC_INDEX                  (59u)
#define OTP_TRIM_VALID_0F0_INDEX             (60u)
#define OTP_TRIM_VALID_0F4_INDEX             (61u)
#define OTP_TRIM_VALID_0F8_INDEX             (62u)
#define OTP_CRC_INDEX                        (63u)

#define OTP_CRCDATA_START_INDEX (9u)
#define OTP_CRCDATA_ES2_END_INDEX (59u)
#define OTP_CRC_LAST_INDEX (OTP_CRCDATA_ES2_END_INDEX + 1u)
#define OTP_CRC_INDEX (63u)
#define OTP_CRC_COMPUTE_SIZE (OTP_CRC_LAST_INDEX - OTP_CRCDATA_START_INDEX + 1u) // number of OTP entires (from index 9 to index 59) for caculating the CRC

#define OTP_TRIM_TS_THRESH_COUNT (4u)
#define OTP_TRIM_TX_TS_COEFF_COUNT (3u)
#define OTP_TRIM_CHIRP_TS_COEFF_COUNT (1u)
#define OTP_TRIM_SNS_COUNT (8u)
#define OTP_TRIM_GBIAS_COUNT (10u)
#define OTP_TRIM_LOCAL_LDO_COUNT (14u)
#define OTP_TRIM_RX1_THRESH_COUNT (4u)
#define OTP_TRIM_RX2_THRESH_COUNT (4u)
#define OTP_TRIM_RX3_THRESH_COUNT (4u)
#define OTP_TRIM_RX4_THRESH_COUNT (4u)
#define OTP_TRIM_RX1_FILTER_COUNT (6u)
#define OTP_TRIM_RX2_FILTER_COUNT (6u)
#define OTP_TRIM_RX3_FILTER_COUNT (6u)
#define OTP_TRIM_RX4_FILTER_COUNT (6u)
#define OTP_TRIM_TX_BIAS_ST3_COUNT (3u)
#define OTP_TRIM_TX_BIAS_ST12_COUNT (6u)
#define OTP_TRIM_TX1_THRESH_COUNT (5u)
#define OTP_TRIM_TX2_THRESH_COUNT (5u)
#define OTP_TRIM_TX3_THRESH_COUNT (5u)
#define OTP_TRIM_LOI_THRESH_COUNT (5u)
#define OTP_TRIM_CHIRP_THRESH_COUNT (6u)
#define OTP_TRIM_SUBBAND_CORRECTION_1G_COUNT (7u)
#define OTP_TRIM_SUBBAND_CORRECTION_2G_COUNT (7u)
#define OTP_TRIM_SUBBAND_CORRECTION_4G_COUNT (3u)
#define OTP_SPARE_TRIM_COUNT (3u)
#define OTP_TRIM_WR_PTAT_COUNT (3u)
#define OTP_TRIM_FR_GLDO_COUNT (4u)

#define OTP_TS_THRESHOLD_SEL_SPI_CAFC_INDEX (0u)
#define OTP_TS_THRESHOLD_SEL_SPI_TX3_INDEX (1u)
#define OTP_TS_THRESHOLD_SEL_SPI_TX2_INDEX (2u)
#define OTP_TS_THRESHOLD_SEL_SPI_TX1_INDEX (3u)
#define OTP_TX3_TEMP_COEFFICIENT_CC_INDEX (0u)
#define OTP_TX2_TEMP_COEFFICIENT_CC_INDEX (1u)
#define OTP_TX1_TEMP_COEFFICIENT_CC_INDEX (2u)
#define OTP_CHIRP_TEMP_COEFFICIENT_CC_INDEX (0u)
#define OTP_SNS_1V1_LOW_THRESH_SEL_GLDO_INDEX (0u)
#define OTP_GLDO1V1_SNS_LOW_CAL_GLDO_INDEX (1u)
#define OTP_SNS_1V1_HIGH_THRESH_SEL_GLDO_INDEX (2u)
#define OTP_GLDO1V1_SNS_HIGH_CAL_GLDO_INDEX (3u)
#define OTP_SNS_1V8_LOW_THRESH_SEL_GLDO_INDEX (4u)
#define OTP_GLDO1V8_SNS_LOW_CAL_GLDO_INDEX (5u)
#define OTP_SNS_1V8_HIGH_THRESH_SEL_GLDO_INDEX (6u)
#define OTP_GLDO1V8_SNS_HIGH_CAL_GLDO_INDEX (7u)
#define OTP_LPF_R2_MCLK_INDEX (0u)
#define OTP_VCO_RSET_MCLK_INDEX (1u)
#define OTP_CTL_LPF_R1_SPI_CAFC_INDEX (2u)
#define OTP_CTRL_IREF_LOCAL_LDO_GBIAS_INDEX (3u)
#define OTP_SEL_IREF_BIAS_MCLK_INDEX (4u)
#define OTP_XO_LDO_IREF_MCLK_INDEX (5u)
#define OTP_CTRL_IREF_ALL_IP_BGR_ENABLE_GBIAS_INDEX (6u)
#define OTP_CTRL_IREF_ALL_IP_BGR_GBIAS_INDEX (7u)
#define OTP_CTRL_IREF_ALL_IP_BG_ENABLE_GBIAS_INDEX (8u)
#define OTP_CTRL_IREF_ALL_IP_BG_GBIAS_INDEX (9u)
#define OTP_LVDS_VCM_SET_LVDS_INDEX (0u)
#define OTP_LDO_SEL_VOUT_ATB_ATB_INDEX (1u)
#define OTP_CTL_LDO_VCO_SEL_VOUT_SPI_CAFC_INDEX (2u)
#define OTP_CTL_LDO_DIVIDER_SEL_VOUT_SPI_CAFC_INDEX (3u)
#define OTP_LDO_SEL_VOUT_SSBMOD_CC_INDEX (4u)
#define OTP_LDO_SEL_VOUT_SERIALISER_SER_CC_INDEX (5u)
#define OTP_LDO_SEL_VOUT_ADC_CC_INDEX (6u)
#define OTP_LDO_SEL_VOUT_MCLK_INDEX (7u)
#define OTP_LDO_SEL_VOUT_SERIALISER_CSI2_CC_INDEX (8u)
#define OTP_CTL_LDO_CPPFD_SEL_VOUT_SPI_CAFC_INDEX (9u)
#define OTP_XO_LDO_VOUT_MCLK_INDEX (10u)
#define OTP_VOUT_LDO3_MCLK_INDEX (11u)
#define OTP_VOUT_LDO2_MCLK_INDEX (12u)
#define OTP_VOUT_LDO1_MCLK_INDEX (13u)
#define OTP_LEVEL_LO_MAX_SPI_RX1_INDEX (0u)
#define OTP_LEVEL_LO_HIGH_SPI_RX1_INDEX (1u)
#define OTP_LEVEL_LO_LOW_SPI_RX1_INDEX (2u)
#define OTP_LEVEL_LO_MIN_SPI_RX1_INDEX (3u)
#define OTP_LEVEL_LO_MAX_SPI_RX2_INDEX (0u)
#define OTP_LEVEL_LO_HIGH_SPI_RX2_INDEX (1u)
#define OTP_LEVEL_LO_LOW_SPI_RX2_INDEX (2u)
#define OTP_LEVEL_LO_MIN_SPI_RX2_INDEX (3u)
#define OTP_LEVEL_LO_MAX_SPI_RX3_INDEX (0u)
#define OTP_LEVEL_LO_HIGH_SPI_RX3_INDEX (1u)
#define OTP_LEVEL_LO_LOW_SPI_RX3_INDEX (2u)
#define OTP_LEVEL_LO_MIN_SPI_RX3_INDEX (3u)
#define OTP_LEVEL_LO_MAX_SPI_RX4_INDEX (0u)
#define OTP_LEVEL_LO_HIGH_SPI_RX4_INDEX (1u)
#define OTP_LEVEL_LO_LOW_SPI_RX4_INDEX (2u)
#define OTP_LEVEL_LO_MIN_SPI_RX4_INDEX (3u)
#define OTP_LPF_RX_FINE_SET_WB_RX1_INDEX (0u)
#define OTP_LPF_RX_FINE_SET_25MHZ_RX1_INDEX (1u)
#define OTP_LPF_RX_FINE_SET_20MHZ_RX1_INDEX (2u)
#define OTP_LPF_RX_FINE_SET_15MHZ_RX1_INDEX (3u)
#define OTP_LPF_RX_FINE_SET_12P5MHZ_RX1_INDEX (4u)
#define OTP_RC_RX_TRIM_SET_RX1_INDEX (5u)
#define OTP_LPF_RX_FINE_SET_WB_RX2_INDEX (0u)
#define OTP_LPF_RX_FINE_SET_25MHZ_RX2_INDEX (1u)
#define OTP_LPF_RX_FINE_SET_20MHZ_RX2_INDEX (2u)
#define OTP_LPF_RX_FINE_SET_15MHZ_RX2_INDEX (3u)
#define OTP_LPF_RX_FINE_SET_12P5MHZ_RX2_INDEX (4u)
#define OTP_RC_RX_TRIM_SET_RX2_INDEX (5u)
#define OTP_LPF_RX_FINE_SET_WB_RX3_INDEX (0u)
#define OTP_LPF_RX_FINE_SET_25MHZ_RX3_INDEX (1u)
#define OTP_LPF_RX_FINE_SET_20MHZ_RX3_INDEX (2u)
#define OTP_LPF_RX_FINE_SET_15MHZ_RX3_INDEX (3u)
#define OTP_LPF_RX_FINE_SET_12P5MHZ_RX3_INDEX (4u)
#define OTP_RC_RX_TRIM_SET_RX3_INDEX (5u)
#define OTP_LPF_RX_FINE_SET_WB_RX4_INDEX (0u)
#define OTP_LPF_RX_FINE_SET_25MHZ_RX4_INDEX (1u)
#define OTP_LPF_RX_FINE_SET_20MHZ_RX4_INDEX (2u)
#define OTP_LPF_RX_FINE_SET_15MHZ_RX4_INDEX (3u)
#define OTP_LPF_RX_FINE_SET_12P5MHZ_RX4_INDEX (4u)
#define OTP_RC_RX_TRIM_SET_RX4_INDEX (5u)
#define OTP_PA_ST3_BIAS_CTRL_TX1_INDEX (0u)
#define OTP_PA_ST3_BIAS_CTRL_TX2_INDEX (1u)
#define OTP_PA_ST3_BIAS_CTRL_TX3_INDEX (2u)
#define OTP_PA_ST2_BIAS_CTRL_TX1_INDEX (0u)
#define OTP_PA_ST1_BIAS_CTRL_TX1_INDEX (1u)
#define OTP_PA_ST2_BIAS_CTRL_TX2_INDEX (2u)
#define OTP_PA_ST1_BIAS_CTRL_TX2_INDEX (3u)
#define OTP_PA_ST2_BIAS_CTRL_TX3_INDEX (4u)
#define OTP_PA_ST1_BIAS_CTRL_TX3_INDEX (5u)
#define OTP_LEVEL_RF_MAX_SPI_TX1_INDEX (0u)
#define OTP_ANCHOR_POINT_TX1_INDEX (1u)
#define OTP_PPD_LEVEL_LOX3_TX1_INDEX (2u)
#define OTP_PPD_LEVEL_PR_TX1_INDEX (3u)
#define OTP_PPD_LEVEL_VGA_TX1_INDEX (4u)
#define OTP_LEVEL_RF_MAX_SPI_TX2_INDEX (0u)
#define OTP_ANCHOR_POINT_TX2_INDEX (1u)
#define OTP_PPD_LEVEL_LOX3_TX2_INDEX (2u)
#define OTP_PPD_LEVEL_PR_TX2_INDEX (3u)
#define OTP_PPD_LEVEL_VGA_TX2_INDEX (4u)
#define OTP_LEVEL_RF_MAX_SPI_TX3_INDEX (0u)
#define OTP_ANCHOR_POINT_TX3_INDEX (1u)
#define OTP_PPD_LEVEL_LOX3_TX3_INDEX (2u)
#define OTP_PPD_LEVEL_PR_TX3_INDEX (3u)
#define OTP_PPD_LEVEL_VGA_TX3_INDEX (4u)
#define OTP_LOI_LUT_SEL_CTRL_LOI_INDEX (0u)
#define OTP_LEVEL_LOI_MAX_SPI_LOI_INDEX (1u)
#define OTP_LEVEL_LOI_HIGH_SPI_LOI_INDEX (2u)
#define OTP_LEVEL_LOI_LOW_SPI_LOI_INDEX (3u)
#define OTP_LEVEL_LOI_MIN_SPI_LOI_INDEX (4u)
#define OTP_CTL_VTUNE_VCO_HIGH_SPI_CAFC_INDEX (0u)
#define OTP_CTL_VTUNE_VCO_LOW_SPI_CAFC_INDEX (1u)
#define OTP_CTL_LEVEL_VCO_MAX_SPI_CAFC_INDEX (2u)
#define OTP_CTL_LEVEL_VCO_HIGH_SPI_CAFC_INDEX (3u)
#define OTP_CTL_LEVEL_VCO_LOW_SPI_CAFC_INDEX (4u)
#define OTP_CTL_LEVEL_VCO_MIN_SPI_CAFC_INDEX (5u)
#define OTP_VCO_1G_SKIP_112_CAFC_INDEX (0u)
#define OTP_VCO_1G_SKIP_96_CAFC_INDEX (1u)
#define OTP_VCO_1G_SKIP_80_CAFC_INDEX (2u)
#define OTP_VCO_1G_SKIP_64_CAFC_INDEX (3u)
#define OTP_VCO_1G_SKIP_48_CAFC_INDEX (4u)
#define OTP_VCO_1G_SKIP_32_CAFC_INDEX (5u)
#define OTP_VCO_1G_SKIP_16_CAFC_INDEX (6u)
#define OTP_VCO_2G_SKIP_112_CAFC_INDEX (0u)
#define OTP_VCO_2G_SKIP_96_CAFC_INDEX (1u)
#define OTP_VCO_2G_SKIP_80_CAFC_INDEX (2u)
#define OTP_VCO_2G_SKIP_64_CAFC_INDEX (3u)
#define OTP_VCO_2G_SKIP_48_CAFC_INDEX (4u)
#define OTP_VCO_2G_SKIP_32_CAFC_INDEX (5u)
#define OTP_VCO_2G_SKIP_16_CAFC_INDEX (6u)
#define OTP_VCO_4G_SKIP_48_CAFC_INDEX (0u)
#define OTP_VCO_4G_SKIP_32_CAFC_INDEX (1u)
#define OTP_VCO_4G_SKIP_16_CAFC_INDEX (2u)
#define OTP_CTL_VCO_R_IBIAS_SET_SPI_CAFC_INDEX (0u)
#define OTP_MSPC_TRIM_CTRL_MCLK_INDEX (1u)
#define OTP_IF_LEVEL_SET_SSB_INDEX (2u)
#define OTP_CTRL_IREF_ALL_IP_PTAT_ENABLE_GBIAS_INDEX (0u)
#define OTP_CTRL_IREF_ALL_IP_PTAT_GBIAS_INDEX (1u)
#define OTP_PTAT_OFFSET_CALIB_CTRL_GBIAS_INDEX (2u)
#define OTP_REF_LDO1V8_SET_CURVE_GLDO_INDEX (0u)
#define OTP_REF_LDO1V1_SET_CURVE_GLDO_INDEX (1u)
#define OTP_REF_LDO1V8_SET_DC_GLDO_INDEX (2u)
#define OTP_REF_LDO1V1_SET_DC_GLDO_INDEX (3u)

#endif

#define ATBNODE_NUM_LVDS 11u
#define ATBNODE_NUM_MIPI 11u
#define ATBNODE_NUM_CAFC 22u
#define ATBNODE_NUM_ADC 16u
#define ATBNODE_NUM_GBIAS 6u
#define ATBNODE_NUM_LOI 17u
#define ATBNODE_NUM_MCLK 56u
#define ATBNODE_NUM_RX 19u
#ifdef TEF82XX_CFG_ES2 
#define ATBNODE_NUM_TX 62u
#endif
#define ATBNODE_NUM_SSB 15u
#define ATBNODE_NUM_GLDO 15u
#define ATBNODE_NUM_ATB 8u

// Max size of OTP data table
#define MAX_OTP_DATA_TABLE_SIZE   14u
// Max possible Vtune before correction
#define VTUNE_VCO_HIGH_MAX_MINUS_2 13u
// Max Possible Gldo1v1SetDc value before correction
#define GLDO_1V1_SET_DC_MAX_MINUS_2 125u

/// VCO output maximal voltage level
#define CAFC_VCO_MAXAMP (1100u)
/// CAFC current injection LSB value for aquisition
#define CAFC_INJ_LSB_ACQ (0.5970f)
 /// CAFC current injection LSB value for reset
#define CAFC_INJ_LSB_RST (3.7975f)

//Temperature sensor read time delay(TBD) in 1 ms
#define TEMP_SENSER_WAIT_FOR_READY_TIMEOUT_IN_US (0x1000u)
                                                
#define CAFC_VCO_OPTIMAL_AMP (520.0f)
#define CAFC_VCO_FORCE_DIVIDER_OPTIMAL (32u)
// Pmos inject current
#define CAFC_PMOS_INJECT_CURRENT  (0x1u)
#define CAFC_NMOS_INJECT_CURRENT  (0x0u)
// charge pump offset 10% offset
#define CAFC_CHARGE_PUMP_10_PERCENT_OFFSET  (0x2u)
#define CAFC_CHARGE_PUMP_15_PERCENT_OFFSET  (0x3u)

#define CAFC_CALIBRATION_TIMEOUT_IN_US_MIN  (80.0f)
#define CAFC_CALIBRATION_TIMEOUT_IN_US_MAX  (350.0f)

//Delay after enabling local tx for generating level min error
#define SYS_LOCALTX_ON_WAITIME_IN_US (0x2u)
//Delay for LOI and Chirp to come out of power saving mode
#define SYS_LOI_CHIRP_DYN_POWER_UP_WAITIME_IN_US (0x200u)

// Chirp timing and frequency parameters for Golden Run
#define GR_POWERDOWN_DELAY_PER_CHIRP 5.0f     // 10microsecond
#define GR_POWERDOWN_DELAY_PER_SEQUENCE 10.0f // 40microsecond
#define GR_SAFETY_MON_DELAY 40.0f             // 40 microsecond
#define GR_DC_POWERON_TIME (50.0f)
#define GR_DWELL_TIME (1.25f)
#define GR_SETTLE_TIME (2.0f)
#define GR_JUMPBACK_TIME (0.025f)
#define GR_RESET_TIME (0.75f)

#define REG_ALLTX_CALIB_DELAY (1u)
#define GR_TXSWANDBPS_DELAY (0.2f)
#define GR_EFFECTIVE_BW (1000.0e6f) // 1GHz
#define GR_LOOP_BW_1GVCO (250e3f) // 1GHz VCO, BW: 300kHz
#define GR_LOOP_BW_2G4GVCO (300e3f) // 1GHz VCO, BW: 300kHz
#define GR_NUM_RAW_SAMPLES (2048u)
#define GR_ADC_DECIMATION (2u)
#define GR_TXPRCAL_TIMEOUT (450u) //450 micro seconds, same as reset value in register map
#define GR_RAMPTIME (GR_SETTLE_TIME + ((float32_t)GR_NUM_RAW_SAMPLES * (12.50f / 1000.0f)) + GR_JUMPBACK_TIME)
#define GR_CHIRP_TIME (GR_DWELL_TIME + GR_RAMPTIME + GR_RESET_TIME)
// Es2 define fro GR
#define GR_TXRF_CALIBRATION_TIMEOUT (240u)
#define GR_TX_PPD_CALIBRATION_TIMEOUT (80u)
#ifdef S32R294
#define GR_TXRF_POUT_TARGET_POWER (10.5f)
#define GR_TXRF_POUT_TARGET_POWER_BACKOFFCODE (6u)
#else
#define GR_TXRF_POUT_TARGET_POWER (12.0f)
#define GR_TXRF_POUT_TARGET_POWER_BACKOFFCODE (4u)
#endif
#define GR_RX_LOX3_CALIBRATION_TIMEOUT (17u)
#define GR_CAFC_CALIBRATION_TIMEOUT (200u)
#define GR_LOI_B2_CALIBRATION_TIMEOUT (17u)

#define GR_TXRF_CALIBRATE_LOX3 (FALSE)
#define GR_TXRF_CALIBRATE_POUT (TRUE)
#define GR_TXRF_CALIBRATE_PR (TRUE)
#define GR_TXRF_CALIBRATE_PRPHASE (TRUE)
#define GR_TXRF_CALIBRATE_VGA (TRUE)

#define TX_PRC_ADC_TIMER_START_ADC_CONV (45u)
#define TX_PRC_ADC_TIMER_ADC_CYCLE (55u)
#define TX_LEVEL_RF_HIGH_DELTA (2.0f)
#define TX_LEVEL_RF_LOW_DELTA (3.0f)
#define TX_LEVEL_MIN_RF_MAX (15.0f)
#define TX_LEVEL_MIN_RF_MIN (-3.0f)
#define TX_LEVEL_MAXIMUM_TARGET_POWER (15.0f)
#define TX_PPD_CALIBRATION_TIME (92u)
#define TX_LOX3_CALIBRATION_TIME (80u)
#define TX_PRCURR_CALIBRATION_TIME (120u)
#define TX_VGA_CALIBRATION_TIME (120u)
#define TX_POUT_CALIBRATION_TIME (70u)
#define TX_PRPHASE_CALIBRATION_TIME (205u)
/* Range selected for target power is POut - 10. POut maximum is 11.5dBm */
#define TX_LEVEL_MINIMUM_TARGET_POWER (3.0f)
#define TX_LEVEL_RF_MAXIMUM_DELTA (4.0f)
#define CC_SCRATCH_REGISTER1_U16 (uint16_t)0x0080
#define CC_CRC_ERROR_INJECTION_U16 (uint16_t)0x0F20
#define CAFC_FILTER_PAR_TRIM_U16 (uint16_t)0x0264
#define CAFC_FILTER_PAR_TRIM_MASK  (0xFFFEFFFFu)  
#define GLDO_MASK_CC_FORCE_ERROR_U16 (uint16_t)0x0200
#define GLDO_MASK_CC_RESET_ERROR_U16 (uint16_t)0x0204
#define GLDO_TEST_FORCE_ERROR_U16 (uint16_t)0x0100
#define GLDO_TEST_RESET_ERROR_U16 (uint16_t)0x0104
#define RX_CENTER_FREQ_LIMIT  ((BC_FLOAT)79.5e9)
#define LOI_4G_INPUTBW_LIMIT  ((BC_FLOAT)3.5e9)
#define SSB_IFLEVEL_INDEX_RANGE  (12u)
#define SSB_MINIMUM_IFLEVEL  ((int32_t)0)
#define SSB_MAXIMUM_LASTIFLEVELREG  (16u)
#define SSB_MINIMUM_LASTIFLEVELREG  (0u)
#define SSB_INVALID_GAIN_CODE_SEARCH_INDEX (13u)
#define SSB_IF_FREQ_CAL_FIRST_DIVIDER (0xBu)
#define SSB_IF_FREQ_CAL_SECOND_DIVIDER (0x1u)
#define SSB_MOD_OUTPUT_LEVEL  (0x3Fu)
#define SSB_DEFAULT_IF_SIGNAL_LEVEL_CODE (0x3u)
#define CC_DYNAMIC_POWDWN_DELAY_MAX (1638.375f)
#define TX_LEVEL_CODE_MAX (64u)
#define RX_LOX3_CALIBRATION_TIMEOUT (17u)
#define RX_LOX3_CAL_TARGET_OFFSET_MAX (3u)
#define TX_SAFETY_PR_INL_GAIN_CODE (150u)

 #if defined(__cplusplus)
 }
 #endif
 #endif
