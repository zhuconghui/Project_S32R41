/*
    Copyright 2023 NXP
    NXP Confidential. This software is owned or controlled by NXP and may only be
    used strictly in accordance with the applicable license terms. By expressly
    accepting such terms or by downloading, installing, activating and/or otherwise
    using the software, you are agreeing that you have read, and that you agree to
    comply with and are bound by, such license terms.  If you do not agree to be
    bound by the applicable license terms, then you may not retain, install,
    activate or otherwise use the software.
 */

/*
 * rfeSwBist_rfeSwBist.c
 */

/*==================================================================================================
 *   Project              : RFE_SW
 *   Platform             : S32R41-TEF82xx
 ==================================================================================================*/

/*==================================================================================================
 *                                        INCLUDE FILES
 ==================================================================================================*/
#include <stddef.h>
#include <string.h>
#include "rfe_sw_cfg_tef82xx.h"
#include "rfe_sw_cfg_to_tef82xx_map.h"
#include "rfeSwBist.h"
#include "rfe_error.h"
#include "rfeSysTick.h"
#include "rfeApiFsm.h"
#include "rfeSwUtils.h"

#include "rfe_blob_access.h"
#include "rfeSwInit.h"
#include "rfeDspMath.h"
#include "rfeDspMath_fft.h"
#include "rfe_sw_calib_tef82xx.h"
#include "rfe_debug.h"
#include "rfe_sw_cfg_tef82xx_timing_req.h"

// BCD LLD
#include "bc_err.h"
#include "bc_types.h"
#include "bc_rx.h"
#include "bc_conf.h"
#include "bc_ssb.h"
#include "bc_sys.h"
#include "bc_cafc.h"
#include "bc_te.h"
#include "bc_loi.h"
#include "bc_mipi.h"
#include "bc_gbias.h"
#include "bc_sc.h"

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*====================================================================================================================
 *                                      TYPES
 ====================================================================================================================*/
/**
 * \struct rfeSwBist_PeakAndBin_t
 * \brief Structure store peak value(magnitude) and bin of a frequency.
 */
typedef struct {
    float32_t   value;
    uint16_t    bin;
} rfeSwBist_PeakAndBin_t;

typedef union ConvertSign
{
    uint16_t    uInt16Value; 
    int16_t     int16Value;
} rfe_convert16_t;

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief        Number of chirps in frame for RFBist testing
*/
#define RSDK_TEF82XX_RFBIST_CHIRPS_PER_FRAME    (1U)
/**
* @brief        Number of samples in chirp for RFBist testing
*/
#define RSDK_TEF82XX_RFBIST_SAMPLES_PER_CHIRP   (128U)
/**
* @brief        CSI2 Tile size
*/
#define RSDK_TEF82XX_RFBIST_TILE_SIZE           (8U)
/**
* @brief        Acquisition buffer size in samples for RFBist testing
*/
#define RSDK_TEF82XX_RFBIST_TOT_SAMP_ADC        (RSDK_TEF82XX_RFBIST_NO_ANTENNAS * RSDK_TEF82XX_RFBIST_CHIRPS_PER_FRAME * RSDK_TEF82XX_RFBIST_SAMPLES_PER_CHIRP)
/**
* @brief        Bytes per sample. One sample is 16bits
*/
#define BYTES_PER_SAMPLE                        (2U)
/**
* @brief        Acquisition buffer size in bytes for RFBist testing
*/
#define RSDK_TEF82XX_RFBIST_TOT_BYTES_ADC       (RSDK_TEF82XX_RFBIST_TOT_SAMP_ADC * BYTES_PER_SAMPLE)
/**
* @brief        Value for buffer reset
*/
#define DEFAULT_VAL                             (0U)
/**
* @brief        Number of bytes to check if the buffer received data
*/
#define NO_BYTES_TO_CHECK                       (10U)
/**
* @brief        Number of check buffer received data retries
*/
#define NO_BUF_CHECK_RETRY                      (3U)
/**
* @brief        RFBist Profile timing settings
*/
#define TEF82XX_RFBIST_SETTLE_TIME              (5.0f)
#define TEF82XX_RFBIST_JUMPBACK_TIME            (0.025f)
#define TEF82XX_RFBIST_DWELL_TIME               (5.0f)
#define TEF82XX_RFBIST_RESET_TIME               (2.0f)      // Suggested value(0.75f) but if < 2 the FE it will never stop chirping
#define TEF82XX_RFBIST_TXSWANDBPS_DELAY         (0.2f)

#define TEF82XX_RFBIST_DC_POWER_ON_DELAY_US             (50.0f)
#define TEF82XX_RFBIST_TX_DC_POWER_ON_GROUP_DELAY_US    (46.75f)
#define TEF82XX_RFBIST_RX_DC_POWER_ON_GROUP_DELAY_US    (46.25f)
#define TEF82XX_RFBIST_DELTA_POWER_ON_STAGGERING_US     (0.5f)

// Default norm frequency for RF BIST
// 9.38MHz sampled at 40Mhz for 128 samples => 9.38/40*128=30
#define TEF82XX_DEFAULT_TEST_FREQ_BIN           (30U)
// RF BIST test tone minimum magnitude treshold
#define TEF82XX_RFBIST_MIN_MAGNITUDE_TH	        (-30.0f)    // dBFS
// RF BIST test tone target level for calibration
#define TEF82XX_RFBIST_TARGET_LEVEL             (-15)       // dBFS
// 20 * log10(0x07FF) = 20 * log10(2047) = 66.2224 - 6 (6dBFS real sine-wave correction)
#define TEF82XX_RFBIST_MAX_MAG_POW              (60.2224f)  // 0dBFS -6dBFS real sine-wave correction
// PI number
#define TEF82XX_RFBIST_PI                       (3.1416f)
// Threshold for magnitude check 2[dB]-Mixer 4[dB]-LNA
#define TEF82XX_RFBIST_MAGNITUDE_LNA_TH         (4)         // dB
#define TEF82XX_RFBIST_MAGNITUDE_MIXER_TH       (2)         // dB
// Threshold for phase check
// 10 degrees in radians - Mixer , 30 degrees in radians - LNA
#define TEF82XX_RFBIST_PHASE_LNA_TH             (0.5235f)
#define TEF82XX_RFBIST_PHASE_MIXER_TH           (0.1745f)

/*====================================================================================================================
 *                                   LOCAL VARIABLES
======================================================================================================================*/
static uint8_t*                     rfeSwBist_Buffer = NULL;
static int16_t                      bistInputData[RSDK_TEF82XX_RFBIST_NO_ANTENNAS][RSDK_TEF82XX_RFBIST_SAMPLES_PER_CHIRP] __attribute__((section(".dtcm_bss"))) = {{ 0 }};
static cfloat32_t                   outFFT[RSDK_TEF82XX_RFBIST_NO_ANTENNAS][RSDK_TEF82XX_RFBIST_SAMPLES_PER_CHIRP / 2] __attribute__((section(".dtcm_bss"))) = {{{ 0.0f }}};
static float32_t                    magFFT[RSDK_TEF82XX_RFBIST_NO_ANTENNAS][RSDK_TEF82XX_RFBIST_SAMPLES_PER_CHIRP / 2] __attribute__((section(".dtcm_bss"))) = {{ 0.0f }};
static rfeSwBist_rxBistParam_t      bistParams[RFE_MAX_SUPPORTED_DEVICES];
static float32_t                    gfTChirpRFBIST = 0.0f;
/*====================================================================================================================
 *                                   LOCAL FUNCTION PROTOTYPES
======================================================================================================================*/
// Function used for selecting the Single Sideband Modulator injection point.
static BC_ERRCODE Tef82xxSSBConnect(RX_RFBIST_Input_e SelectInput);

// Function used for RX Bist setup. Part of radar cycle. See AN12816 Figure 96.
static BC_ERRCODE Tef82XXRfBistSetup(rfeDriverPersistentMem_t *pDrvState);

// Function used for reverting TEF82xx settings to curent sequence after RX Bist
static BC_ERRCODE Tef82XXRfBistRevertSettings(rfeDriverPersistentMem_t *pDrvState);

// Function used for RX Bist acquisition
static void Tef82xxRxBistAcquisition(rfe_error_t* rfe___error___pointer);

// Function used for bist data buffers reset 
static void Tef82xxRxBistClearBuf(uint8_t* dataBuf, uint32_t size, rfe_error_t* rfe___error___pointer);

// Function used for checking data on MIPI CSI2 buffers
static bool Tef82xxRxBistBufHasData(uint8_t* dataBuf);

static void Tef82xxRxBistFillInputBuffs(uint16_t* rfeSwBistInBuffer);

// Function used for processing RX Bist data FFT or DFT on bin 31
static float32_t Tef82xxRxBistPostProcessing(bool firstRun, uint8_t fe, rfe_error_t* rfe___error___pointer);

// Function used for Amplitude Check
static void Tef82xxRxBistAmplitudeCheck(uint8_t feIndex,
                                        bool zeroDayMeasurement,
                                        rfeTef82XXRfBistTest_t testType, 
                                        rfe_error_t* rfe___error___pointer);

// Function used for Phase Check
static void Tef82xxRxBistPhaseCheck(uint8_t feIndex,
                                    bool zeroDayMeasurement,
                                    rfeTef82XXRfBistTest_t testType, 
                                    rfe_error_t* rfe___error___pointer);

// Function used for performing the RX Bist on TEF82xx frontends setup
static void Tef82xxRxBist(bool zeroDayMeasurement,
                          rfe_error_t* rfe___error___pointer);
                                
// Helper function used to get max peak value and bin
rfeSwBist_PeakAndBin_t Tef82xxGetMaxBinAndValue(float32_t* magFftParam, uint16_t size);

// Function used for performing the RX Bist stages 2,3,4,5,6 on TEF82xx frontends 
// 2 - SSB connect
// 3 - Acquisition
// 4 - Post Processing
// 5 - Amplitude Check
// 6 - Phase Check
static void Tef82XXRfBistTest(bool zeroDayMeasurement, 
                              rfeTef82XXRfBistTest_t testType, 
                              rfe_error_t* rfe___error___pointer);

// Function used for performing all bist test (includes gain calibration and zero hour measurements)
static void Tef82xxBistTests(bool zeroDayMeasurement, rfe_error_t *rfe___error___pointer);

// Function used for frontends bist setup (profile select/dynamic power/SSB/calibrations)
static BC_ERRCODE Tef82xxPrepareBist(void);

// Function used to connect SSB and adjust gain
static void rfeSwBistPrepareTest(rfeTef82XXRfBistTest_t testType, bool firstRun[RFE_MAX_SUPPORTED_DEVICES][TEF82XX_RFBIST_TESTS], float32_t toneLevelDBFS[RFE_MAX_SUPPORTED_DEVICES][TEF82XX_RFBIST_TESTS], rfe_error_t *rfe___error___pointer);

// Function used to prepare data , process(fft, abs and max) and check amplitude and phase
static void rfeSwBistProcessAndCheck(rfeTef82XXRfBistTest_t testType, bool zeroDayMeasurement, bool firstRun[RFE_MAX_SUPPORTED_DEVICES][TEF82XX_RFBIST_TESTS], float32_t toneLevelDBFS[RFE_MAX_SUPPORTED_DEVICES][TEF82XX_RFBIST_TESTS], rfe_error_t *rfe___error___pointer);

// Function used to ENABLE/DISABLE Chirp Power Mode
static BC_ERRCODE Tef82xxCPMConfig(bool forceDisableCPM, rfeDriverPersistentMem_t *pDrvState);

// Function used to calibrate the rfbist
static BC_ERRCODE Tef82xxBistCalibration(rfeDriverPersistentMem_t *pDrvState);

// Function that return ADC decimation factor for the current chirp sequence
static uint8_t rfeSwBist_GetDecimationFactor(uint8_t *pRfeConfig, rfe_chirpSequenceIndex_t chirpSequence, rfe_error_t* rfe___error___pointer);
/*====================================================================================================================
 *                                       LOCAL FUNCTIONS
======================================================================================================================*/
static uint8_t rfeSwBist_GetDecimationFactor(uint8_t *pRfeConfig, rfe_chirpSequenceIndex_t chirpSequence, rfe_error_t* rfe___error___pointer)
{
    uint8_t                             decimation = TEF82XX_DECIMATION_ADC_40MSPS;
    rfe_chirpProfileIndex_t             profileIdx;
    rfe_effectiveSamplingFrequency_t    samplingFrequency;    

	if (*rfe___error___pointer == rfe_error_none_e)
	{
        // All profiles must have the same sampling frequency
        // Using first profile in sequence as reference
        profileIdx = rfeChirpProfileMapper(rfeCfg_chirpSequence_getChirpProfileSequence(pRfeConfig, chirpSequence, 0u, rfe___error___pointer));
        samplingFrequency = rfeSwUtils_SamplingFrequency(rfeCfg_chirpProfile_getEffectiveSamplingFrequency(pRfeConfig, profileIdx, rfe___error___pointer));
        if (*rfe___error___pointer == rfe_error_none_e)
        {
            switch((uint32_t)samplingFrequency)
            {
                case (uint32_t)RFE_ADC_5MSPS:
                    decimation = TEF82XX_DECIMATION_ADC_5MSPS;
                    break;
                case (uint32_t)RFE_ADC_10MSPS:
                    decimation = TEF82XX_DECIMATION_ADC_10MSPS;
                    break;
                case (uint32_t)RFE_ADC_20MSPS:
                    decimation = TEF82XX_DECIMATION_ADC_20MSPS;
                    break;
                case (uint32_t)RFE_ADC_40MSPS:
                    decimation = TEF82XX_DECIMATION_ADC_40MSPS;
                    break;
                default:
                    decimation = TEF82XX_DECIMATION_ADC_40MSPS;
                    break;
            }
        }
    }
    return decimation;
}
/*====================================================================================================================*/
static BC_ERRCODE Tef82xxSSBConnect(RX_RFBIST_Input_e SelectInput)
{
    BC_ERRCODE errCode = BC_ERR_NOERROR;

    errCode = BC_RX_ConnectRFBISTSignal(e_SYS_RXMC, SelectInput);
    return errCode;
}
/*====================================================================================================================*/
static BC_ERRCODE Tef82xxCPMConfig(bool forceDisableCPM, rfeDriverPersistentMem_t *pDrvState)
{
    BC_ERRCODE        errCode = BC_ERR_NOERROR;
    BOOL              EnHardFuncRstFrame;
    TE_ChirpTrgMode_t ChirpTrgMode;

    if (forceDisableCPM)
    {
        // Let the TEF82xx do the functional resets when CPM is disabled.
        EnHardFuncRstFrame = TRUE;
        ChirpTrgMode.ChirpPowerMode = FALSE;
    }
    else
    {
        // Disable automatic Hardware Functional reset, to be manually performed.
        // This is required to support the CPM flow for better TX switch isolation.
        EnHardFuncRstFrame = FALSE;
        ChirpTrgMode.ChirpPowerMode = TRUE;
    }   
    errCode = BC_SC_EnDivHardFuncReset(TRUE, FALSE, EnHardFuncRstFrame, FALSE);
    if (errCode == BC_ERR_NOERROR)
    {
        if (pDrvState->frontendMode == RFE_CASCADING_FOLLOWER)
        {
            ChirpTrgMode.ChirpTrigMode = e_TE_CH_TRG_EXT_SINGLE_TRG;
            ChirpTrgMode.ChirpStartDelay = TRUE;
        }
        else
        {
            // TODO: Update this for GPIO trigger when will be supported
            ChirpTrgMode.ChirpTrigMode = e_TE_CH_TRG_SPI_TRIGGER;
            ChirpTrgMode.ChirpStartDelay = FALSE;
        }
        errCode = BC_TE_SetChirpTrgMode(&ChirpTrgMode);
    }    
    return errCode;
}
/*====================================================================================================================*/
static BC_ERRCODE Tef82xxBistCalibration(rfeDriverPersistentMem_t *pDrvState)
{
    BC_ERRCODE  errCode = BC_ERR_NOERROR;

    errCode = rfeSwCfgSetDynPowMode(e_DPM_FOR_LO_CALIBRATION);
    // Work-around done for proper VCO selection when using multiple sequences with different VCO configured
    if ((errCode == BC_ERR_NOERROR) && (pDrvState->frontendMode != RFE_CASCADING_FOLLOWER))
    {
    	errCode = BC_CAFC_ConfigVCOProfile(e_SYS_PROFILE_8,
    			pDrvState->tef82xxDrvState.profChirpFreqRFBIST.VCOSel,
				pDrvState->tef82xxDrvState.profChirpFreqRFBIST.PLLLPFSel,
				TEF82XX_SKIP_CAFC_IVCO_FINE,
				TEF82XX_SKIP_CAFC_SUBBAND);
    }
    if ((errCode == BC_ERR_NOERROR) && (pDrvState->frontendMode != RFE_CASCADING_FOLLOWER))
    {
    	errCode = BC_CAFC_ConfigLoopFilter(
    			pDrvState->tef82xxDrvState.profChirpFreqRFBIST.PLLLPFSel,
				rfeCafcPllLPFLUTSelFromVCOMapper(pDrvState->tef82xxDrvState.profChirpFreqRFBIST.VCOSel),
				200000.0f,
				pDrvState->tef82xxDrvState.profChirpFreqRFBIST.InputFrequency,
				pDrvState->tef82xxDrvState.profChirpFreqRFBIST.DownChirp);
    }
    // Workaround end
    // Load RFBIST profile
    if (errCode == BC_ERR_NOERROR)
    {
        errCode = BC_CAFC_LoadProfile(e_SYS_PROFILE_8);
    }
    if (errCode == BC_ERR_NOERROR)
    {
        errCode = BC_CAFC_FastBiasChirpPll();
    }
    if (errCode == BC_ERR_NOERROR)
    {
        errCode = BC_LOI_StartLOGainCalib(TRUE, GR_LOI_B2_CALIBRATION_TIMEOUT);
    }
    if (errCode == BC_ERR_NOERROR)
    {
        errCode = BC_RX_CalibrateLOx3Gain(e_SYS_RXMC, TRUE, GR_RX_LOX3_CALIBRATION_TIMEOUT);
    }
    return errCode;
}
/*====================================================================================================================*/
static BC_ERRCODE Tef82XXRfBistSetup(rfeDriverPersistentMem_t *pDrvState)
{
    BC_ERRCODE           errCode = BC_ERR_NOERROR;
    rfe_error_t          rfeError = rfe_error_none_e;
    uint8_t        		 profList[8] = { 0, 0, 0, 0, 0, 0, 0, 0};
    TE_StaticConfig_t    staticConfigBist;
#ifdef MIPI_SETUP_SEQUENCE
	MIPI_VCNum_t         selectVCs = {0};
	MIPI_VCClearFrame_t  clearFrameVCs = {0};
#endif
    // Disable CPM if used
    // To meet timing requirements with the TE controlled powering ON TX/RX and specific other switches,
    // it is recommended to disabled CPM for RFBIST. By this more timing headroom becomes available in the DC_PowerOn_Delay phase. 
    if (pDrvState->tef82xxDrvState.chirpPowerSavingEnabled == (uint8_t)TRUE)
    {
        errCode = Tef82xxCPMConfig(true, pDrvState);
    }
    if (errCode == BC_ERR_NOERROR)
    {
        // HPFResetReleaseCtrl: True,      # True T2 (start TSettle).
        // RxActiveCtrl: True,             # True T2 (start TSettle).
        // HPFResetReleaseDelay_us: 0.15,  # Delay from the reference point for the HPF release de-assertion.
        // RxActiveDelay_us: 0.025         # Delay from the reference point for the RX filter activation.        
        errCode = BC_TE_SetRxFilterCtrls(TRUE, TRUE, 0.15f, 0.025f);
    }
    if (errCode == BC_ERR_NOERROR)
    {
        staticConfigBist = RfeSwCfgTimingReqGetStaticConfig(&rfeError);
        if (rfeError == rfe_error_none_e)
        {
            //  DC power on delay in us
            staticConfigBist.DCPowerOnDelay = TEF82XX_RFBIST_DC_POWER_ON_DELAY_US; 
            //  TX group delay in us
            staticConfigBist.TXGroupDelay = TEF82XX_RFBIST_TX_DC_POWER_ON_GROUP_DELAY_US;
            //  RX group delay in us
            staticConfigBist.RXGroupDelay = TEF82XX_RFBIST_RX_DC_POWER_ON_GROUP_DELAY_US;
            //  Jump back time in us
            staticConfigBist.JumpBackTime = TEF82XX_RFBIST_JUMPBACK_TIME;
            //  Number of chirps within a chirp sequence
            staticConfigBist.NumChirpInSeq = 1U;
            //  Number of chirp sequences in a burst with a chirp start trigger
            staticConfigBist.NumSeqInBurst = 1U;
            //  Group delay fine control for Tx1 and RX1 pair
            staticConfigBist.GDelayFineControl1 = 0.0f;
            //  Group delay fine control for Tx2 and RX2 pair        
            staticConfigBist.GDelayFineControl2 = TEF82XX_RFBIST_DELTA_POWER_ON_STAGGERING_US;
            //  Group delay fine control for Tx3 and RX3 pair
            staticConfigBist.GDelayFineControl3 = TEF82XX_RFBIST_DELTA_POWER_ON_STAGGERING_US * 2.0f;
            //  Group delay fine control for RX4
            staticConfigBist.GDelayFineControl4 = TEF82XX_RFBIST_DELTA_POWER_ON_STAGGERING_US * 3.0f;
            //  Duration of a chirp sequence in us. In case of burst mode, it also includes idle time between sequences.
            staticConfigBist.SeqInterval = gfTChirpRFBIST;
            errCode = BC_TE_ConfigStatic(&staticConfigBist);
        }
        else
        {
            errCode = BC_ERR_INPUTOUTOFRANGE;
        }
    }
    if (errCode == BC_ERR_NOERROR)
    {
        // Disable PR Safety check for RFBIST procedure.
        // EnPRSafetyCheck 0/FALSE: PR Safety check disabled; 1/TRUE: PR Safety check enabled.
        // PRSafetyStartDelay Delay in us, at the end of the chirp sequence to start the safety check.
        errCode = BC_TE_TXPRSafetyCheckDelay(FALSE, (float32_t)TEF82XX_DEFAULT_PR_SAFETY_START_DELAY);
    }

    if (errCode == BC_ERR_NOERROR)
    {
        errCode = BC_TE_ConfigProfileSequencing(e_SYS_PROFILE_8, profList, 1U, TRUE, TRUE, 0U);
    }
    if (errCode == BC_ERR_NOERROR)
    {
        errCode = Tef82xxBistCalibration(pDrvState);
    }
    if (pDrvState->frontendMode == RFE_CASCADING_FOLLOWER)
    {
        if (errCode == BC_ERR_NOERROR)
        {
            errCode = BC_TE_EnableChirp(TRUE);
        }
        if (errCode == BC_ERR_NOERROR)
        {
            // Activate DPM on leader only after follower calibration
            errCode = rfeSwCfgSetDynPowMode(e_DPM_ACTIVE);
        }
        // Power on SSB
        if ((errCode == BC_ERR_NOERROR) && (pDrvState->tef82xxDrvState.txPhaseErrorWa1Enabled == (uint8_t)TRUE))
        {
            errCode = BC_GBIAS_EnableSSBBias(TRUE);
        }   
        if (errCode == BC_ERR_NOERROR)
        {
            errCode = BC_SSB_ChangePowerState(TRUE);
        }
    }
#ifdef MIPI_SETUP_SEQUENCE            
    if (errCode == BC_ERR_NOERROR)
    {
        selectVCs.SelectVC3 = TRUE;
	    clearFrameVCs.ClearFrameVC3 = TRUE;
        errCode = BC_MIPI_ConfigVC(&selectVCs, &clearFrameVCs);
    }
#endif    
    return errCode;
}
/*====================================================================================================================*/
static BC_ERRCODE Tef82XXRfBistRevertSettings(rfeDriverPersistentMem_t *pDrvState)
{
    BC_ERRCODE  errCode  = BC_ERR_NOERROR;
    rfe_error_t rfeError = rfe_error_none_e; 
    rfeRxFilterCtrlParams_t rxFilterCtrlParam = { 0 };
    TE_StaticConfig_t staticConfigBist;

    errCode = BC_RX_ConnectRFBISTSignal(e_SYS_RXMC, e_RX_RFBIST_INPUT_DISABLED);
    // Power off SSB
	if (errCode == BC_ERR_NOERROR)
	{
		errCode = BC_SSB_ChangePowerState(FALSE);
	}
    if ((errCode == BC_ERR_NOERROR) && (pDrvState->tef82xxDrvState.txPhaseErrorWa1Enabled == (uint8_t)TRUE))
	{
		errCode = BC_GBIAS_EnableSSBBias(FALSE);
	}
    if ((errCode == BC_ERR_NOERROR) && (pDrvState->tef82xxDrvState.chirpPowerSavingEnabled == (uint8_t)TRUE))
    {
        errCode = Tef82xxCPMConfig(false, pDrvState);
    }
    if (errCode == BC_ERR_NOERROR)
    {
        staticConfigBist = RfeSwCfgTimingReqGetStaticConfig(&rfeError);
        if (rfeError != rfe_error_none_e)
        {
            errCode = BC_ERR_INPUTOUTOFRANGE;
        }
    }    
    if (errCode == BC_ERR_NOERROR)
    {
            // The number of chirp in sequence will be overwrote by chirp sequence init
            staticConfigBist.NumChirpInSeq = 1U;
            errCode = BC_TE_ConfigStatic(&staticConfigBist);
    }
    if ((errCode == BC_ERR_NOERROR) && (pDrvState->frontendMode == RFE_CASCADING_FOLLOWER))
    {
        errCode = BC_TE_EnableChirp(TRUE);
    }
    if (errCode == BC_ERR_NOERROR)
    {
        errCode = BC_TE_TXPRSafetyCheckDelay((bool)TEF82XX_DEFAULT_EN_PR_SAFETY_CHECK,
                                            (float32_t)TEF82XX_DEFAULT_PR_SAFETY_START_DELAY * NS_TO_US);
    }
    if (errCode == BC_ERR_NOERROR)
    {
        RfeSwCfgTimingReqGetRxFilterCtrlParams(&rxFilterCtrlParam, &rfeError);
        if (rfeError != rfe_error_none_e)
        {
            errCode = BC_ERR_INPUTOUTOFRANGE;
        }
    }
    if (errCode == BC_ERR_NOERROR)
    {
        errCode = BC_TE_SetRxFilterCtrls(rxFilterCtrlParam.hpfResetReleaseCtrl,
                                         rxFilterCtrlParam.rxActiveCtrl,
                                         rxFilterCtrlParam.hpfResetReleaseDelay_us,
                                         rxFilterCtrlParam.rxActiveDelay_us);
    } 
    return errCode;
}
/*====================================================================================================================*/
static void Tef82xxRxBistAcquisition(rfe_error_t* rfe___error___pointer)
{
    BC_ERRCODE errCode = BC_ERR_NOERROR;
    uint8_t feIndex;
    uint16_t retries;

    if (rfe_error_none_e == *rfe___error___pointer)
    {
		Tef82xxRxBistClearBuf(rfeSwBist_Buffer, RSDK_TEF82XX_RFBIST_TOT_BYTES_ADC, rfe___error___pointer);
		rfeSwUtils_SelectFe((uint8_t)rfeFrontEndId_0);
		// Chirp start
		errCode = BC_TE_StartChirp();
		if (errCode == BC_ERR_NOERROR)
		{
			errCode = BC_TE_WaitForReady();
		}
		for(feIndex = 0; feIndex < RfeDrvStateNoFrontendsGet(); feIndex++)
		{
			retries = NO_BUF_CHECK_RETRY;
			while (!Tef82xxRxBistBufHasData(rfeSwBist_Buffer + (RSDK_TEF82XX_RFBIST_TOT_BYTES_ADC * feIndex)) && (retries > 0U))
			{
				retries--;
				RfeHwDelayUs(100);
			}
			if (retries <= 0U)
			{
				errCode = BC_ERR_ATB_BISTADCTIMEOUT;
				break;
			}
		}
		if (errCode != BC_ERR_NOERROR)
		{
			*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
		}
	}
}
/*====================================================================================================================*/
static void Tef82xxRxBistFillInputBuffs(uint16_t* rfeSwBistInBuffer)
{
    uint8_t         rxAnt;
    uint32_t        sampleIndex, adcBufIndex;
    uint8_t         tileIndex;
    rfe_convert16_t adcData;

    /* Memory layout for input buffers
    * s0a0 s1a0    ...    s7a0 
    * s0a1 s1a1    ...    s7a1
    * s0a2 s1a2    ...    s7a2
    * s0a3 s1a3    ...    s7a3
    * s8a0 s9a0    ...    s15a0
    * s8a1 s9a1    ...    s15a1
    * s8a2 s9a2    ...    s15a2
    * s8a3 s9a3    ...    s15a3
    * ...
    * ...
    */
    for(sampleIndex = 0; sampleIndex < RSDK_TEF82XX_RFBIST_SAMPLES_PER_CHIRP; sampleIndex += RSDK_TEF82XX_RFBIST_TILE_SIZE)
    {
        for(rxAnt = 0; rxAnt < RSDK_TEF82XX_RFBIST_NO_ANTENNAS; rxAnt++)
        {
            for(tileIndex = 0; tileIndex < RSDK_TEF82XX_RFBIST_TILE_SIZE; tileIndex++)
            {
                adcBufIndex = (sampleIndex * RSDK_TEF82XX_RFBIST_NO_ANTENNAS)  + (rxAnt * RSDK_TEF82XX_RFBIST_TILE_SIZE) + tileIndex;
                // CSI2 Raw 12 samples. 3FF8 highest value - C000 lowest value
                // Shift by 3 for 07FF highest value -  F000 lowest value (12bit signed value)
                adcData.uInt16Value = rfeSwBistInBuffer[adcBufIndex]; // Get signed value bitwise
                bistInputData[rxAnt][sampleIndex + tileIndex] = adcData.int16Value / 8; 
            }
        }
    } 
}
/*====================================================================================================================*/
static void Tef82xxRxBistAmplitudeCheck(uint8_t feIndex, bool zeroDayMeasurement, rfeTef82XXRfBistTest_t testType, rfe_error_t* rfe___error___pointer)
{
    uint8_t     rxAnt;
    float32_t   magValRx0, difMag;
    bool		gainFail = false;

    if (rfe_error_none_e == *rfe___error___pointer)
    {
        magValRx0 = magFFT[0U][TEF82XX_DEFAULT_TEST_FREQ_BIN];
        for( rxAnt = 1; rxAnt < RSDK_TEF82XX_RFBIST_NO_ANTENNAS; rxAnt++)
        {
            difMag = magValRx0 - magFFT[rxAnt][TEF82XX_DEFAULT_TEST_FREQ_BIN];
            if (zeroDayMeasurement)
            {
                bistParams[feIndex].zeroDayMeasurementBuff.refMag[rxAnt - 1U][testType] = difMag;
            }
            else
            {
                difMag -= bistParams[feIndex].zeroDayMeasurementBuff.refMag[rxAnt - 1U][testType];
                if (difMag > bistParams[feIndex].rxBistGainThreshold[testType])
                {
                	gainFail = true;
                	break;
                }
            }
        }
        if (gainFail)
        {
			if (testType == TEF82XX_RFBIST_MIXER_TEST)
			{
                *rfe___error___pointer = rfeSwUtils_SetError(rfe_error_rxbist_mixer_gain_fail_e, feIndex);
			}
			else
			{
                *rfe___error___pointer = rfeSwUtils_SetError(rfe_error_rxbist_lna_gain_fail_e, feIndex);
			}
            setSwError(rfe___error___pointer);
        }
    }
}
/*====================================================================================================================*/
static void Tef82xxRxBistPhaseCheck(uint8_t feIndex, bool zeroDayMeasurement, rfeTef82XXRfBistTest_t testType, rfe_error_t* rfe___error___pointer)
{
    uint8_t     rxAnt;
    cfloat32_t  delta, rxAnt0, rxAntX;
    float32_t   phVal, cPhase;
    float32_t   minPh = 0.0f, maxPh = 0.0f, difPh;
    
    if (rfe_error_none_e == *rfe___error___pointer)
    {
        // Use first antenna as reference point for phase
        rxAnt0 = outFFT[0U][TEF82XX_DEFAULT_TEST_FREQ_BIN];
        for (rxAnt = 1U; rxAnt < RSDK_TEF82XX_RFBIST_NO_ANTENNAS; rxAnt++)
        {
            rxAntX = outFFT[rxAnt][TEF82XX_DEFAULT_TEST_FREQ_BIN];
            // Compute AntX * conj(Ant0)
            delta.im = (rxAnt0.re * rxAntX.im) - (rxAnt0.im * rxAntX.re);
            delta.re = (rxAnt0.re * rxAntX.re) + (rxAnt0.im * rxAntX.im);
            // Get phase - use atan2f to account for quadrant
            phVal = rfeDspMath_atan2F(delta.im, delta.re);
            if (zeroDayMeasurement)
            {
                bistParams[feIndex].zeroDayMeasurementBuff.refPh[rxAnt - 1U][testType]  = phVal;
            }
            else
            {
                // All BIST measurements are relative to reference(first measurement)
                cPhase = phVal - bistParams[feIndex].zeroDayMeasurementBuff.refPh[rxAnt - 1U][(uint8_t)testType];
                // Wrap-around to [-pi,pi]
                if (cPhase > 0.0f)
                {
                    cPhase = fmodf(cPhase + TEF82XX_RFBIST_PI, 2.0f * TEF82XX_RFBIST_PI) - TEF82XX_RFBIST_PI;
                }
                else
                {
                    cPhase = fmodf(cPhase - TEF82XX_RFBIST_PI, 2.0f * TEF82XX_RFBIST_PI) + TEF82XX_RFBIST_PI;
                }
                // Find Min and Max phase to check maximum phase diff
                if (minPh > cPhase)
                {
                    minPh = cPhase;
                }
                if (maxPh < cPhase)
                {
                    maxPh = cPhase;
                }
            }
        }
        if (!zeroDayMeasurement)
        {
            difPh = maxPh - minPh;
            if (difPh > bistParams[feIndex].rxBistPhaseThreshold[testType])
            {
                if (testType == TEF82XX_RFBIST_MIXER_TEST)
                {
                    *rfe___error___pointer = rfeSwUtils_SetError(rfe_error_rxbist_mixer_phase_fail_e, feIndex);
                }
                else
                {
                    *rfe___error___pointer = rfeSwUtils_SetError(rfe_error_rxbist_lna_phase_fail_e, feIndex);
                }
                setSwError(rfe___error___pointer);
            }
        }
    }
}
/*====================================================================================================================*/
static float32_t Tef82xxRxBistPostProcessing(bool firstRun, uint8_t fe, rfe_error_t* rfe___error___pointer)
{
    uint8_t                 rxAnt;
    rfeSwBist_PeakAndBin_t  peak = { .value = 0.0f, .bin = 0U};
    float32_t               toneLevelDBFS = 0.0f;
    float32_t               maxToneLevelDBFS = 0.0f - TEF82XX_RFBIST_MAX_MAG_POW;
    float32_t               nPower2 = (float32_t)log2((double)RSDK_TEF82XX_RFBIST_SAMPLES_PER_CHIRP);
    const uint32_t          fftSize = (uint32_t)nPower2;

    for( rxAnt = 0; rxAnt < RSDK_TEF82XX_RFBIST_NO_ANTENNAS; rxAnt++)
    {
        rfeDspMath_fftI16F((int16x2_t *)(void*)bistInputData[rxAnt], fftSize, outFFT[rxAnt], rfe___error___pointer);
        rfeDspMath_absCF32dB(outFFT[rxAnt], RSDK_TEF82XX_RFBIST_SAMPLES_PER_CHIRP / 2UL, magFFT[rxAnt], rfe___error___pointer);
    }
    if (rfe_error_none_e == *rfe___error___pointer)
    {
        for( rxAnt = 0; rxAnt < RSDK_TEF82XX_RFBIST_NO_ANTENNAS; rxAnt++)
        {
            peak = Tef82xxGetMaxBinAndValue(magFFT[rxAnt], RSDK_TEF82XX_RFBIST_SAMPLES_PER_CHIRP / 2U);
            // Check if the signal fundamental is at TEF82XX_DEFAULT_TEST_FREQ_BIN as expected
            if (peak.bin != TEF82XX_DEFAULT_TEST_FREQ_BIN)
            {
                *rfe___error___pointer = rfeSwUtils_SetError(rfe_error_rxbist_frequency_fail, fe);
                setSwError(rfe___error___pointer);
                break;
            }
            toneLevelDBFS = peak.value - TEF82XX_RFBIST_MAX_MAG_POW;
            if (toneLevelDBFS > maxToneLevelDBFS)
            {
                maxToneLevelDBFS = toneLevelDBFS;
            }
            // Check minimum tone level
            if (((peak.value - TEF82XX_RFBIST_MAX_MAG_POW) < TEF82XX_RFBIST_MIN_MAGNITUDE_TH) && !firstRun)
            {
                *rfe___error___pointer = rfeSwUtils_SetError(rfe_error_rxbist_missing_signal, fe);
                setSwError(rfe___error___pointer);
                break;
            }
        }
    }
    return maxToneLevelDBFS;
}
/*====================================================================================================================*/
rfeSwBist_PeakAndBin_t Tef82xxGetMaxBinAndValue(float32_t* magFftParam, uint16_t size)
{
    uint16_t idx;
    rfeSwBist_PeakAndBin_t max;
    // Init max val with first array val and index
    max.value = magFftParam[0];
    max.bin = 0;
    for ( idx = 1; idx < size; idx++)
    {
        if (max.value < magFftParam[idx])
        {
            max.value = magFftParam[idx];
            max.bin = idx;
        }
    }
    return max;
}
/*====================================================================================================================*/
static void Tef82xxRxBistClearBuf(uint8_t* dataBuf, uint32_t size, rfe_error_t* rfe___error___pointer)
{
    uint8_t     feIndex;
    uint32_t    buffIndex = 0UL;

    if (rfe_error_none_e == *rfe___error___pointer)
    {
        for( feIndex = 0; feIndex < RfeDrvStateNoFrontendsGet(); feIndex++)
        {
            // Fix CERT INT30-C	L2	Unsigned integer operation "size * (uint32_t)feIndex" may wrap.
            if ((buffIndex + size) > buffIndex)
            {
                buffIndex += size;
                (void)memset(dataBuf + buffIndex, (int32_t)DEFAULT_VAL, size);
            }
            else
            {
                // Mem Overflow         
                *rfe___error___pointer = rfe_error_invalidPointer_e;
            }            
        }
    }
}
/*====================================================================================================================*/
static bool Tef82xxRxBistBufHasData(uint8_t* dataBuf)
{
    uint32_t i;
    bool     ret = false;

    for(i = 0; i < NO_BYTES_TO_CHECK; i++)
    {
        // Check last NO_BYTES_TO_CHECK from buffer for data
        if(dataBuf[RSDK_TEF82XX_RFBIST_TOT_BYTES_ADC - i - 1UL] != DEFAULT_VAL)
        {
            ret = true;
            break;
        }
    }
    return ret;
}

static void rfeSwBistPrepareTest(rfeTef82XXRfBistTest_t testType, bool firstRun[RFE_MAX_SUPPORTED_DEVICES][TEF82XX_RFBIST_TESTS], float32_t toneLevelDBFS[RFE_MAX_SUPPORTED_DEVICES][TEF82XX_RFBIST_TESTS], rfe_error_t *rfe___error___pointer)
{
#if (RFE_MAX_SUPPORTED_DEVICES == 4UL)
	static uint8_t      previousIfLevelCode[RFE_MAX_SUPPORTED_DEVICES][TEF82XX_RFBIST_TESTS] = {{3U,3U},{3U,3U},{3U,3U},{3U,3U}};
#elif (RFE_MAX_SUPPORTED_DEVICES == 2UL)
	static uint8_t      previousIfLevelCode[RFE_MAX_SUPPORTED_DEVICES][TEF82XX_RFBIST_TESTS] = {{3U,3U},{3U,3U}};
#endif
	uint8_t     feIndex;
	BC_ERRCODE  errCode = BC_ERR_NOERROR;
	uint8_t     currentIfLevelCode = 0U;

	if (rfe_error_none_e == *rfe___error___pointer)
	{
		for (feIndex = 0; feIndex < RfeDrvStateNoFrontendsGet(); feIndex++)
		{
			rfeSwUtils_SelectFe(feIndex);
			/////////////////////////////////// 2. SSB connect
			switch (testType)
			{
				case TEF82XX_RFBIST_MIXER_TEST:
					errCode = Tef82xxSSBConnect(e_RX_RFBIST_INPUT_MIXER);
					break;
				case TEF82XX_RFBIST_LNA_TEST:
					errCode = Tef82xxSSBConnect(e_RX_RFBIST_INPUT_LNA);
					break;
				default:
					// do nothing for TEF82XX_RFBIST_TESTS or others
					;
					break;
			}
			// Adjust gain SSB level
			if ((!firstRun[feIndex][testType]) && (errCode == BC_ERR_NOERROR))
			{
				rfeSwUtils_SelectFe(feIndex);
				errCode = BC_SSB_CalibRFBISTGainStAl(TEF82XX_RFBIST_TARGET_LEVEL, (int32_t) toneLevelDBFS[feIndex][testType], previousIfLevelCode[feIndex][testType], &currentIfLevelCode);
				previousIfLevelCode[feIndex][testType] = currentIfLevelCode;
#ifdef RFE_DEBUG
				if (gRfeDebugLevel <= e_rfe_debug_level_bc)
				{
					RfeDbgPrintMsg("Tef82XXRfBistTest toneLevelDBFS[%d][%d] %d Code: %d\n", feIndex, testType,(int32_t)toneLevelDBFS[feIndex][testType],currentIfLevelCode);
				}
#endif
				if (errCode != BC_ERR_NOERROR)
				{
					*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
				}
			}
			if (errCode != BC_ERR_NOERROR)
			{
				*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
				break;
			}
		}
	}
}

static void rfeSwBistProcessAndCheck(rfeTef82XXRfBistTest_t testType, bool zeroDayMeasurement, bool firstRun[RFE_MAX_SUPPORTED_DEVICES][TEF82XX_RFBIST_TESTS], float32_t toneLevelDBFS[RFE_MAX_SUPPORTED_DEVICES][TEF82XX_RFBIST_TESTS], rfe_error_t *rfe___error___pointer)
{
	uint8_t feIndex;

	if (rfe_error_none_e == *rfe___error___pointer)
	{
		for (feIndex = 0; feIndex < RfeDrvStateNoFrontendsGet(); feIndex++)
		{
			if (bistParams[feIndex].bistActive)
			{
				Tef82xxRxBistFillInputBuffs((uint16_t*) (void*) (rfeSwBist_Buffer + (RSDK_TEF82XX_RFBIST_TOT_BYTES_ADC * (uint32_t) feIndex)));
				/////////////////////////////////// 4. Post Processing
				toneLevelDBFS[feIndex][testType] = Tef82xxRxBistPostProcessing(firstRun[feIndex][testType], feIndex, rfe___error___pointer);
				if (!firstRun[feIndex][testType])
				{
					/////////////////////////////////// 5. Amplitude Check
					Tef82xxRxBistAmplitudeCheck(feIndex, zeroDayMeasurement, testType, rfe___error___pointer);
					/////////////////////////////////// 6. Phase Check
					Tef82xxRxBistPhaseCheck(feIndex, zeroDayMeasurement, testType, rfe___error___pointer);
				}
				else
				{
					firstRun[feIndex][testType] = false;
				}
			}
		}
	}
}

/*====================================================================================================================*/
static void Tef82XXRfBistTest(bool zeroDayMeasurement, rfeTef82XXRfBistTest_t testType, rfe_error_t* rfe___error___pointer)
{
#if (RFE_MAX_SUPPORTED_DEVICES == 4UL)
	static bool         firstRun[RFE_MAX_SUPPORTED_DEVICES][TEF82XX_RFBIST_TESTS] = {{true, true},{true, true},{true, true},{true, true}};
	static float32_t    toneLevelDBFS[RFE_MAX_SUPPORTED_DEVICES][TEF82XX_RFBIST_TESTS] = {{ 0.0F }};
#elif (RFE_MAX_SUPPORTED_DEVICES == 2UL)
	static bool         firstRun[RFE_MAX_SUPPORTED_DEVICES][TEF82XX_RFBIST_TESTS] = {{true, true},{true, true}};
	static float32_t    toneLevelDBFS[RFE_MAX_SUPPORTED_DEVICES][TEF82XX_RFBIST_TESTS] = {{ 0.0F }};
#endif

	if (rfe_error_none_e == *rfe___error___pointer)
	{
		// Connect SSB and adjust gain
		rfeSwBistPrepareTest(testType, firstRun, toneLevelDBFS, rfe___error___pointer);
		/////////////////////////////////// 3. Acquisition
		Tef82xxRxBistAcquisition(rfe___error___pointer);
		// Prepare data, process(fft, abs and max) and check amplitude and phase
		rfeSwBistProcessAndCheck(testType, zeroDayMeasurement, firstRun, toneLevelDBFS, rfe___error___pointer);
	}
}
/*====================================================================================================================*/
static BC_ERRCODE Tef82xxPrepareBist(void)
{
	uint8_t feIndex;
	rfeDriverPersistentMem_t *pDrvState = NULL;
	BC_ERRCODE errCode = BC_ERR_NOERROR;

	for (feIndex = 0; feIndex < RfeDrvStateNoFrontendsGet(); feIndex++)
	{
		rfeSwUtils_SelectFe(feIndex);
		pDrvState = RfeDrvStateGet();
		errCode = Tef82XXRfBistSetup(pDrvState);
		if (errCode != BC_ERR_NOERROR)
		{
			break;
		}
	}
	// Select leader
	if ((errCode == BC_ERR_NOERROR) && (RfeDrvStateConfigurationGet() == rfeFrontEnd_Cascaded_e))
	{
		rfeSwUtils_SelectFe((uint8_t) rfeFrontEndId_0);
		pDrvState = RfeDrvStateGet();
	}
	// Activate DPM on leader/standalone
	if (errCode == BC_ERR_NOERROR)
	{
		errCode = rfeSwCfgSetDynPowMode(e_DPM_ACTIVE);
	}
	// Power on SSB
	if ((errCode == BC_ERR_NOERROR)
			&& (((pDrvState->tef82xxDrvState.txPhaseErrorWa1Enabled != 0U) ? TRUE : FALSE) == TRUE))
	{
		errCode = BC_GBIAS_EnableSSBBias(TRUE);
	}
	if (errCode == BC_ERR_NOERROR)
	{
		errCode = BC_SSB_ChangePowerState(TRUE);
	}
	return errCode;
}
/*====================================================================================================================*/
static void Tef82xxBistTests(bool zeroDayMeasurement, rfe_error_t *rfe___error___pointer)
{
	static bool testLNA = true;

	if (rfe_error_none_e == *rfe___error___pointer)
	{
		if (zeroDayMeasurement)
		{
			// Do mixer test twice in order to have SSB calibrated properly
			Tef82XXRfBistTest(zeroDayMeasurement, TEF82XX_RFBIST_MIXER_TEST, rfe___error___pointer);
			Tef82XXRfBistTest(zeroDayMeasurement, TEF82XX_RFBIST_LNA_TEST, rfe___error___pointer);
			Tef82XXRfBistTest(zeroDayMeasurement, TEF82XX_RFBIST_MIXER_TEST, rfe___error___pointer);
			Tef82XXRfBistTest(zeroDayMeasurement, TEF82XX_RFBIST_LNA_TEST, rfe___error___pointer);
		}
		else
		{
			switch (bistParams[rfeFrontEndId_0].rxBistInjectToneMode)
			{
				case TEF82XX_only_mixer:
					Tef82XXRfBistTest(zeroDayMeasurement, TEF82XX_RFBIST_MIXER_TEST, rfe___error___pointer);
					break;
				case TEF82XX_alternate_lna_mixer:
					if (testLNA)
					{
						Tef82XXRfBistTest(zeroDayMeasurement, TEF82XX_RFBIST_LNA_TEST, rfe___error___pointer);
						testLNA = false;
					}
					else
					{
						Tef82XXRfBistTest(zeroDayMeasurement, TEF82XX_RFBIST_MIXER_TEST, rfe___error___pointer);
						testLNA = true;
					}
					break;
				default:
					Tef82XXRfBistTest(zeroDayMeasurement, TEF82XX_RFBIST_MIXER_TEST, rfe___error___pointer);
					Tef82XXRfBistTest(zeroDayMeasurement, TEF82XX_RFBIST_LNA_TEST, rfe___error___pointer);
					break;
			}
		}
	}
}
/*====================================================================================================================*/
static void Tef82xxRxBist(bool zeroDayMeasurement, rfe_error_t* rfe___error___pointer)
{
    BC_ERRCODE                  errCode = BC_ERR_NOERROR;
    rfeDriverPersistentMem_t*   pDrvState = NULL;
    uint8_t                     feIndex;

 #ifdef RFE_DEBUG
	if (gRfeDebugLevel <= e_rfe_debug_level_bc)
	{
		RfeDbgPrintMsg("Tef82xxRxBist get ref %d\n", zeroDayMeasurement);
	}
#endif
    if (rfe_error_none_e == *rfe___error___pointer)
    {
        /////////////////////////////////// 1. Setup bist
    	errCode = Tef82xxPrepareBist();
        if (errCode != BC_ERR_NOERROR)
        {
        	*rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
        }
        /////////////////////////////////// 2,3,4,5,6 LNA/MIXER test
		Tef82xxBistTests(zeroDayMeasurement, rfe___error___pointer);

        /////////////////////////////////// 7. Revert settings
        if((errCode == BC_ERR_NOERROR) && (rfe_error_none_e == *rfe___error___pointer))
        {
            // Revert all fe settings
            for( feIndex = 0; feIndex < RfeDrvStateNoFrontendsGet(); feIndex++)
            {
                rfeSwUtils_SelectFe(feIndex);
                pDrvState = RfeDrvStateGet();  
                errCode = Tef82XXRfBistRevertSettings(pDrvState);
                if (errCode != BC_ERR_NOERROR)
                {
                    break;   
                }            
            }
        }
        if (errCode != BC_ERR_NOERROR)
        {
            *rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
        }        
    }
}

/*====================================================================================================================
 *                                       GLOBAL FUNCTIONS
====================================================================================================================*/
void rfeSwBist_initialConfiguration(rfeDriverPersistentMem_t *const pDrvState, 
                                    uint8_t *pRfeConfig,
		                            rfe_chirpSequenceIndex_t chirpSequence,
                                    rfe_error_t* rfe___error___pointer)
{
    BC_ERRCODE            errCode = BC_ERR_NOERROR;
    uint8_t               decimation;
    // RFBIST timing
    float32_t             TSampleTimeRFBIST;
    float32_t             TRampRFBIST;
    SYS_ProfChirpTiming_t ProfChirpTimingRFBIST;
    SYS_ProfChirpFreq_t   ProfChirpFreqRFBIST;
    SYS_ProfChirpSampleDeci_t ProfChirpSampleRFBIST;
    // Frequency settings
    CAFC_PLLLPFSel_e PLLLPFSel = e_CAFC_PLLLPF_CFG3;
    // TX settings for RFBIST
    BOOL      TXENRFBIST[RFE_MAX_TX_CHANNELS] = {FALSE, FALSE, FALSE};  //For RFBIST, TX should be off
    BOOL      TXSWRFBIST[RFE_MAX_TX_CHANNELS] = {FALSE, FALSE, FALSE};  //For RFBIST, TX should be off
    BOOL      TXBPSRFBIST[RFE_MAX_TX_CHANNELS] = {FALSE, FALSE, FALSE};
    float32_t TXPhaseRFBIST[RFE_MAX_TX_CHANNELS] = {0.0f, 0.0f, 0.0f};
    // RX settings for RFBIST
    BOOL                   RXENRFBIST[RFE_MAX_RX_CHANNELS] = {TRUE, TRUE, TRUE, TRUE};
    RX_Gain_Control_e      RXGainRFBIST[RFE_MAX_RX_CHANNELS] = {e_RX_GAIN_27DB, e_RX_GAIN_27DB, e_RX_GAIN_27DB, e_RX_GAIN_27DB};
    SYS_RXLPF_CornerFreq_e RXLPFRFBIST[RFE_MAX_RX_CHANNELS] = {e_SYS_RXLPF_25MHZ, e_SYS_RXLPF_25MHZ, e_SYS_RXLPF_25MHZ, e_SYS_RXLPF_25MHZ};
    SYS_RXHPF_CornerFreq_e RXHPFRFBIST[RFE_MAX_RX_CHANNELS] = {e_SYS_RXHPF_400KHZ, e_SYS_RXHPF_400KHZ, e_SYS_RXHPF_400KHZ, e_SYS_RXHPF_400KHZ};

    float32_t TempKelvinChirp = 0.0f;
    float32_t CAFCCalCheckTimeOutUs = SYS_WAIT_TO_TRIGGER_AAFC_200US;
    float32_t KvcoAverage = 0.0f;
    SYS_StoreInProfile_t storeInProfile = {0};

    if (*rfe___error___pointer == rfe_error_none_e)
    {    
        decimation = rfeSwBist_GetDecimationFactor(pRfeConfig, chirpSequence, rfe___error___pointer);
    }
    if (*rfe___error___pointer == rfe_error_none_e)
    {    
        TSampleTimeRFBIST = ((float32_t)(128U) * (float32_t)decimation * 12.5f) / 1000.0f;
        TRampRFBIST = TEF82XX_RFBIST_SETTLE_TIME + TSampleTimeRFBIST + TEF82XX_RFBIST_JUMPBACK_TIME;
        gfTChirpRFBIST = TEF82XX_RFBIST_DWELL_TIME + TRampRFBIST + TEF82XX_RFBIST_RESET_TIME;
        //--------------------------------------------------------------------------------
        // RFBIST STatic configuration
        //------------------------------------------------------------------------------
        errCode = BC_SSB_RFBISTStaticConfig(decimation);
        // ----------------------------------------------------------------------------
        // Functional configuration (profile based settings)
        // ----------------------------------------------------------------------------
        if (errCode == BC_ERR_NOERROR)
        {
            // The bist input frequency from the blob is stored in khz uint32
            ProfChirpFreqRFBIST.InputFrequency = (float32_t)rfeCfg_monitorAndSafety_getFrequencyForBist(pRfeConfig, rfe___error___pointer) * 1000.0f;
            if (*rfe___error___pointer != rfe_error_none_e)
            {
                // The value for input frequency cannot be readed
                errCode = BC_ERR_INPUTOUTOFRANGE;
            }
        }
        if (errCode == BC_ERR_NOERROR)
        {
            // Program RFBIST profile. Profile_8 is reserved for RFBIST
            ProfChirpTimingRFBIST.TChirp = gfTChirpRFBIST;
            ProfChirpTimingRFBIST.TDwell = TEF82XX_RFBIST_DWELL_TIME;
            ProfChirpTimingRFBIST.TSettle = TEF82XX_RFBIST_SETTLE_TIME;
            ProfChirpTimingRFBIST.TJumpback = TEF82XX_RFBIST_JUMPBACK_TIME;
            ProfChirpTimingRFBIST.TReset = TEF82XX_RFBIST_RESET_TIME;
            ProfChirpTimingRFBIST.TriggerTXSWAndBPSAtTSettle = TRUE;
            ProfChirpTimingRFBIST.TXSWAndBPSDelay = TEF82XX_RFBIST_TXSWANDBPS_DELAY;
            ProfChirpFreqRFBIST.DownChirp = FALSE;
            ProfChirpFreqRFBIST.InputBW = 0.0f; // Effective modulation bandwidth
            ProfChirpFreqRFBIST.InputBWType = e_SYS_BWACQ;
            ProfChirpFreqRFBIST.InputFreqType = e_SYS_CENTERFREQACQ;
            ProfChirpFreqRFBIST.PLLLPFSel = PLLLPFSel;
            ProfChirpFreqRFBIST.SBSearch = e_SYS_SBSEARCH_AAFC_SPI_TRIG;
            ProfChirpFreqRFBIST.VCOSel = e_CAFC_1GBAND;
            ProfChirpSampleRFBIST.ADCMode = e_SYS_ADC80MSPS_FUNCTIONAL;
            ProfChirpSampleRFBIST.Decimation = decimation;
            ProfChirpSampleRFBIST.PDCBWWide = FALSE;
            ProfChirpSampleRFBIST.RawNumSamples = (uint16_t)RSDK_TEF82XX_RFBIST_SAMPLES_PER_CHIRP * (uint16_t)decimation;
            ProfChirpSampleRFBIST.VirtualChNo = rfeVirtualChannelMapper((uint8_t)RFE_CSI2_VC_3);  // RFBIST is recommended to use virtual channel 3
            errCode = BC_SYS_ProgramChirp(e_SYS_PROFILE_8, &ProfChirpTimingRFBIST, &ProfChirpFreqRFBIST,
                                &ProfChirpSampleRFBIST, TXBPSRFBIST, TXPhaseRFBIST, TXSWRFBIST, TXENRFBIST,
                                RXENRFBIST, RXGainRFBIST, RXLPFRFBIST, RXHPFRFBIST);
        }
        //Sub-band for RFBIST
        if ((errCode == BC_ERR_NOERROR) && (pDrvState->frontendMode != RFE_CASCADING_FOLLOWER))
        {
            errCode = rfeSwCfgSetDynPowMode(e_DPM_FOR_CHIRP_CALIBRATION);
            pDrvState->tef82xxDrvState.profChirpFreqRFBIST = ProfChirpFreqRFBIST; // Save RFBIST Frequency Structure, to be used during RF Bist Setup
            // Work-around done for proper VCO selection when using multiple sequences with different VCO configured
            if (errCode == BC_ERR_NOERROR)
            {
                errCode = BC_CAFC_ConfigVCOProfile(e_SYS_PROFILE_8,
                        pDrvState->tef82xxDrvState.profChirpFreqRFBIST.VCOSel,
                        pDrvState->tef82xxDrvState.profChirpFreqRFBIST.PLLLPFSel,
						TEF82XX_SKIP_CAFC_IVCO_FINE,
						TEF82XX_SKIP_CAFC_SUBBAND);
            }
            if (errCode == BC_ERR_NOERROR)
            {
                errCode = BC_CAFC_ConfigLoopFilter(
                        pDrvState->tef82xxDrvState.profChirpFreqRFBIST.PLLLPFSel,
                        rfeCafcPllLPFLUTSelFromVCOMapper(pDrvState->tef82xxDrvState.profChirpFreqRFBIST.VCOSel),
                        200000.0f,
                        pDrvState->tef82xxDrvState.profChirpFreqRFBIST.InputFrequency,
                        pDrvState->tef82xxDrvState.profChirpFreqRFBIST.DownChirp);
            }
            // Workaround end
            if (errCode == BC_ERR_NOERROR)
            {
                storeInProfile.Profile8 = TRUE;
                errCode = BC_CAFC_CalibAAFCInjDAC(FALSE, FALSE, &ProfChirpFreqRFBIST, &ProfChirpTimingRFBIST, e_SYS_PROFILE_8, &storeInProfile, CAFCCalCheckTimeOutUs, TempKelvinChirp, &KvcoAverage);
            }
            if (errCode == BC_ERR_NOERROR)
            {
                errCode = rfeSwCfgSetDynPowMode(e_DPM_ACTIVE);
            }
        }
        if (errCode != BC_ERR_NOERROR)
        {
            *rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
        }
    }
}
/*====================================================================================================================*/
void rfeSwBist_getBistZeroHourReferenceData(rfeSwBist_rxBistReferenceData_t *zeroHourData, 
                                            rfe_error_t* rfe___error___pointer)
{
    uint8_t chirpSequence = 0;
    uint8_t feIndex;

    if (*rfe___error___pointer == rfe_error_none_e)
    {
        // TODO: Get current chirp sequence, we asume that we did not start any radar cycle and the first sequence is 0
    	rfeSwCalibTef82xxCalibration(chirpSequence, rfe___error___pointer);
        Tef82xxRxBist(true, rfe___error___pointer);
        if (*rfe___error___pointer == rfe_error_none_e)
        {
            for(feIndex = 0U; feIndex < RfeDrvStateNoFrontendsGet(); feIndex++)
            {
                // RX Bist Zero Hour measurement distribution
                // Mixer
                zeroHourData[feIndex].refMag[0][TEF82XX_RFBIST_MIXER_TEST] = bistParams[feIndex].zeroDayMeasurementBuff.refMag[0][TEF82XX_RFBIST_MIXER_TEST];
                zeroHourData[feIndex].refMag[1][TEF82XX_RFBIST_MIXER_TEST] = bistParams[feIndex].zeroDayMeasurementBuff.refMag[1][TEF82XX_RFBIST_MIXER_TEST];
                zeroHourData[feIndex].refMag[2][TEF82XX_RFBIST_MIXER_TEST] = bistParams[feIndex].zeroDayMeasurementBuff.refMag[2][TEF82XX_RFBIST_MIXER_TEST];
                zeroHourData[feIndex].refPh[0][TEF82XX_RFBIST_MIXER_TEST] = rfeSwUtils_radians2degrees(bistParams[feIndex].zeroDayMeasurementBuff.refPh[0][TEF82XX_RFBIST_MIXER_TEST]);
                zeroHourData[feIndex].refPh[1][TEF82XX_RFBIST_MIXER_TEST] = rfeSwUtils_radians2degrees(bistParams[feIndex].zeroDayMeasurementBuff.refPh[1][TEF82XX_RFBIST_MIXER_TEST]);
                zeroHourData[feIndex].refPh[2][TEF82XX_RFBIST_MIXER_TEST] = rfeSwUtils_radians2degrees(bistParams[feIndex].zeroDayMeasurementBuff.refPh[2][TEF82XX_RFBIST_MIXER_TEST]);
                // Lna
                zeroHourData[feIndex].refMag[0][TEF82XX_RFBIST_LNA_TEST] = bistParams[feIndex].zeroDayMeasurementBuff.refMag[0][TEF82XX_RFBIST_LNA_TEST];
                zeroHourData[feIndex].refMag[1][TEF82XX_RFBIST_LNA_TEST] = bistParams[feIndex].zeroDayMeasurementBuff.refMag[1][TEF82XX_RFBIST_LNA_TEST];
                zeroHourData[feIndex].refMag[2][TEF82XX_RFBIST_LNA_TEST] = bistParams[feIndex].zeroDayMeasurementBuff.refMag[2][TEF82XX_RFBIST_LNA_TEST];
                zeroHourData[feIndex].refPh[0][TEF82XX_RFBIST_LNA_TEST] = rfeSwUtils_radians2degrees(bistParams[feIndex].zeroDayMeasurementBuff.refPh[0][TEF82XX_RFBIST_LNA_TEST]);
                zeroHourData[feIndex].refPh[1][TEF82XX_RFBIST_LNA_TEST] = rfeSwUtils_radians2degrees(bistParams[feIndex].zeroDayMeasurementBuff.refPh[1][TEF82XX_RFBIST_LNA_TEST]);
                zeroHourData[feIndex].refPh[2][TEF82XX_RFBIST_LNA_TEST] = rfeSwUtils_radians2degrees(bistParams[feIndex].zeroDayMeasurementBuff.refPh[2][TEF82XX_RFBIST_LNA_TEST]);                 
            }
        }
    }
}
/*====================================================================================================================*/
void rfeSwBist_bist(rfe_error_t* rfe___error___pointer)
{
	Tef82xxRxBist(false, rfe___error___pointer);
}
/*====================================================================================================================*/
void rfeSwBist_readBistConfig(rfeDriverPersistentMem_t* pDrvState,
                              rfe_error_t* rfe___error___pointer)
{
    uint8_t feIndex = RfeDrvStateFrontendIdGet();
    rfe_bistInterval_t bistInterval;

    if (*rfe___error___pointer == rfe_error_none_e)
    {
        // Set initial RX Bist params
        bistParams[feIndex].rxBistGainThreshold[TEF82XX_RFBIST_MIXER_TEST]  = (float32_t)TEF82XX_RFBIST_MAGNITUDE_MIXER_TH;
        bistParams[feIndex].rxBistGainThreshold[TEF82XX_RFBIST_LNA_TEST]    = (float32_t)TEF82XX_RFBIST_MAGNITUDE_LNA_TH;
        bistParams[feIndex].rxBistPhaseThreshold[TEF82XX_RFBIST_MIXER_TEST] = (float32_t)TEF82XX_RFBIST_PHASE_MIXER_TH;
        bistParams[feIndex].rxBistPhaseThreshold[TEF82XX_RFBIST_LNA_TEST]   = (float32_t)TEF82XX_RFBIST_PHASE_LNA_TH;
        bistParams[feIndex].rxBistInjectToneMode = TEF82XX_both_lna_mixer;
        bistParams[feIndex].bistActive = true;

        // Active Bist on this frontend?
        bistInterval = rfeSwUtils_BistIntervalMapper(rfeCfg_radarCycle_getBistInterval(pDrvState->rfeConfig, rfe___error___pointer));
        if (bistInterval == rfe_bistInterval_none_e)
        {
            bistParams[feIndex].bistActive = false;
        }
        else
        {
            // RX Bist Zero Hour measurement distribution
            // Mixer
            bistParams[feIndex].zeroDayMeasurementBuff.refMag[0][TEF82XX_RFBIST_MIXER_TEST] = BIST_PHASE_GAIN_INT16_TO_FLOAT(rfeCfg_monitorAndSafety_getBist(pDrvState->rfeConfig, rfeCfg_param_monitorAndSafety_zeroHrRefForRxGainDiffMixer_rx1_rx2_e, rfe___error___pointer));
            bistParams[feIndex].zeroDayMeasurementBuff.refMag[1][TEF82XX_RFBIST_MIXER_TEST] = BIST_PHASE_GAIN_INT16_TO_FLOAT(rfeCfg_monitorAndSafety_getBist(pDrvState->rfeConfig, rfeCfg_param_monitorAndSafety_zeroHrRefForRxGainDiffMixer_rx1_rx3_e, rfe___error___pointer));
            bistParams[feIndex].zeroDayMeasurementBuff.refMag[2][TEF82XX_RFBIST_MIXER_TEST] = BIST_PHASE_GAIN_INT16_TO_FLOAT(rfeCfg_monitorAndSafety_getBist(pDrvState->rfeConfig, rfeCfg_param_monitorAndSafety_zeroHrRefForRxGainDiffMixer_rx1_rx4_e, rfe___error___pointer));
            bistParams[feIndex].zeroDayMeasurementBuff.refPh[0][TEF82XX_RFBIST_MIXER_TEST] = rfeSwUtils_degrees2radians(BIST_PHASE_GAIN_INT16_TO_FLOAT(rfeCfg_monitorAndSafety_getBist(pDrvState->rfeConfig, rfeCfg_param_monitorAndSafety_zeroHrRefForRxPhaseDiffMixer_rx1_rx2_e, rfe___error___pointer)));
            bistParams[feIndex].zeroDayMeasurementBuff.refPh[1][TEF82XX_RFBIST_MIXER_TEST] = rfeSwUtils_degrees2radians(BIST_PHASE_GAIN_INT16_TO_FLOAT(rfeCfg_monitorAndSafety_getBist(pDrvState->rfeConfig, rfeCfg_param_monitorAndSafety_zeroHrRefForRxPhaseDiffMixer_rx1_rx3_e, rfe___error___pointer)));
            bistParams[feIndex].zeroDayMeasurementBuff.refPh[2][TEF82XX_RFBIST_MIXER_TEST] = rfeSwUtils_degrees2radians(BIST_PHASE_GAIN_INT16_TO_FLOAT(rfeCfg_monitorAndSafety_getBist(pDrvState->rfeConfig, rfeCfg_param_monitorAndSafety_zeroHrRefForRxPhaseDiffMixer_rx1_rx4_e, rfe___error___pointer)));
            // Lna
            bistParams[feIndex].zeroDayMeasurementBuff.refMag[0][TEF82XX_RFBIST_LNA_TEST] = BIST_PHASE_GAIN_INT16_TO_FLOAT(rfeCfg_monitorAndSafety_getBist(pDrvState->rfeConfig, rfeCfg_param_monitorAndSafety_zeroHrRefForRxGainDiffLna_rx1_rx2_e, rfe___error___pointer));
            bistParams[feIndex].zeroDayMeasurementBuff.refMag[1][TEF82XX_RFBIST_LNA_TEST] = BIST_PHASE_GAIN_INT16_TO_FLOAT(rfeCfg_monitorAndSafety_getBist(pDrvState->rfeConfig, rfeCfg_param_monitorAndSafety_zeroHrRefForRxGainDiffLna_rx1_rx3_e, rfe___error___pointer));
            bistParams[feIndex].zeroDayMeasurementBuff.refMag[2][TEF82XX_RFBIST_LNA_TEST] = BIST_PHASE_GAIN_INT16_TO_FLOAT(rfeCfg_monitorAndSafety_getBist(pDrvState->rfeConfig, rfeCfg_param_monitorAndSafety_zeroHrRefForRxGainDiffLna_rx1_rx4_e, rfe___error___pointer));
            bistParams[feIndex].zeroDayMeasurementBuff.refPh[0][TEF82XX_RFBIST_LNA_TEST] = rfeSwUtils_degrees2radians(BIST_PHASE_GAIN_INT16_TO_FLOAT(rfeCfg_monitorAndSafety_getBist(pDrvState->rfeConfig, rfeCfg_param_monitorAndSafety_zeroHrRefForRxPhaseDiffLna_rx1_rx2_e, rfe___error___pointer)));
            bistParams[feIndex].zeroDayMeasurementBuff.refPh[1][TEF82XX_RFBIST_LNA_TEST] = rfeSwUtils_degrees2radians(BIST_PHASE_GAIN_INT16_TO_FLOAT(rfeCfg_monitorAndSafety_getBist(pDrvState->rfeConfig, rfeCfg_param_monitorAndSafety_zeroHrRefForRxPhaseDiffLna_rx1_rx3_e, rfe___error___pointer)));
            bistParams[feIndex].zeroDayMeasurementBuff.refPh[2][TEF82XX_RFBIST_LNA_TEST] = rfeSwUtils_degrees2radians(BIST_PHASE_GAIN_INT16_TO_FLOAT(rfeCfg_monitorAndSafety_getBist(pDrvState->rfeConfig, rfeCfg_param_monitorAndSafety_zeroHrRefForRxPhaseDiffLna_rx1_rx4_e, rfe___error___pointer)));
            // RX Bist Threshold distribution
            // Mixer
            bistParams[feIndex].rxBistGainThreshold[TEF82XX_RFBIST_MIXER_TEST] = BIST_PHASE_GAIN_INT16_TO_FLOAT(rfeCfg_monitorAndSafety_getBist(pDrvState->rfeConfig, rfeCfg_param_monitorAndSafety_rxGainDiffMixerThresholdTolerance_e, rfe___error___pointer));
            bistParams[feIndex].rxBistPhaseThreshold[TEF82XX_RFBIST_MIXER_TEST] = rfeSwUtils_degrees2radians(BIST_PHASE_GAIN_INT16_TO_FLOAT(rfeCfg_monitorAndSafety_getBist(pDrvState->rfeConfig, rfeCfg_param_monitorAndSafety_rxPhaseDiffMixerThresholdTolerance_e, rfe___error___pointer)));
            // Lna
            bistParams[feIndex].rxBistGainThreshold[TEF82XX_RFBIST_LNA_TEST] = BIST_PHASE_GAIN_INT16_TO_FLOAT(rfeCfg_monitorAndSafety_getBist(pDrvState->rfeConfig, rfeCfg_param_monitorAndSafety_rxGainDiffLnaThresholdTolerance_e, rfe___error___pointer));
            bistParams[feIndex].rxBistPhaseThreshold[TEF82XX_RFBIST_LNA_TEST] = rfeSwUtils_degrees2radians(BIST_PHASE_GAIN_INT16_TO_FLOAT(rfeCfg_monitorAndSafety_getBist(pDrvState->rfeConfig, rfeCfg_param_monitorAndSafety_rxPhaseDiffLnaThresholdTolerance_e, rfe___error___pointer)));
            // RX Bist Test mode type
            bistParams[feIndex].rxBistInjectToneMode = rfeSwUtils_BistInjectToneMode(rfeCfg_monitorAndSafety_getInjectTestTone(pDrvState->rfeConfig, rfe___error___pointer));
        }
    }    
}
/*====================================================================================================================*/
void rfeSwBist_setSharedAddresses(uint32_t rfeRfBistBufferAddress)
{
    rfeSwBist_Buffer = (uint8_t *)rfeRfBistBufferAddress;
}

rfeSwBist_rxBistParam_t* rfeSwBist_getBistParamsAddress(void)
{
	return &bistParams[0];
}
/*====================================================================================================================*/

#ifdef __cplusplus
}
#endif

/*====================================================================================================================
 * EOF
 *====================================================================================================================*/

/** @} */
