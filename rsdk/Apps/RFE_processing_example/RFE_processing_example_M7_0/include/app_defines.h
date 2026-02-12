/**************************************************************************************************
 * Copyright 2016-2022 NXP
 **************************************************************************************************
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 **************************************************************************************************/
#ifndef APPD_H
#define APPD_H

/**
* @file           app_defines.h
*/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "typedefs.h"
//#include "rsdk_rfe_api.h"
#include "app_mem_mgr.h"
//#include "apprfe.h"

#ifdef __cplusplus
extern "C" {
#endif

extern rsdkBufHandle_t gPeakAntennaDataBufH;
extern uint16_t gNrDetects;

/*==================================================================================================
*                                      MACROS
==================================================================================================*/
#ifndef TRUE
#define TRUE ((uint8_t)1)
#endif
#ifndef FALSE
#define FALSE ((uint8_t)0)
#endif

#define RSDK_MAX_PEAK_ANT_DATA_SIZE (2048) /* 32 peaks, 16 antennas, 4 bytes per sample*/
#define RSDK_NR_RX_PER_FRONTEND 4

#define BYTES_PER_SAMPLE 	  2
#define NUM_CHIRPS 			  128
#define HEAP_BUFF_SIZE        (3*1024*1024)

#define NUM_SAMPLES_PER_CHIRP_PROF_0 	512
#define NUM_ANTENNA_PROF_0

#define UNUSED_PARAM          0
#define APP_MAX_NR_SEQUENCES  3
#define APP_MAX_NR_PROFILES   8
/*=================================================================================================
*                                             ENUMS
=================================================================================================*/
/**
* @brief    Radar processing enable
* @details  Enable or disable radar processing chain
*/
typedef enum
{
    RSDK_FIXED_FRAMES_MODE = 0U,
	RSDK_CONTINOUS_MODE
} rsdkAppRunMode_t;

typedef enum
{
    RSDK_PROCESSING_DISABLE = 0U,
    RSDK_PROCESSING_ENABLE,
} rsdkProcessingEnable_t;

/**
* @brief    List of the supported processing chains
* @details  This list is based on implemented SPT kernels
*/
typedef enum
{
	RSDK_SPT_PROCESSING_DISABLED = 0U,
    RSDK_SAMPLES512_CHIRPS128_4CH,
	RSDK_SAMPLES512_CHIRPS128_4CH_ADPTV,
    RSDK_SAMPLES256_CHIRPS256_4CH,
	RSDK_SAMPLES256_CHIRPS256_4CH_ADPTV,
    RSDK_SAMPLES1024_CHIRPS128_4CH_CP4D,
    RSDK_SAMPLES256_CHIRPS256_4CH_CP4D_2TXMIMO,
    RSDK_SAMPLES256_CHIRPS128_4CH_3TXMIMO,
	RSDK_SAMPLES256_CHIRPS128_4CH_3TXMIMO_ADPTV,
	RSDK_SAMPLES1024_CHIRPS256_4CH_CP4D_3TXDDMIMO,
	RSDK_SAMPLES512_CHIRPS128_8CH,
	RSDK_SAMPLES512_CHIRPS128_8CH_ADPTV,
    RSDK_SAMPLES256_CHIRPS256_8CH,
	RSDK_SAMPLES256_CHIRPS256_8CH_ADPTV,
	RSDK_SAMPLES1024_CHIRPS128_CP4D_8CH,
	RSDK_SAMPLES256_CHIRPS256_CP4D_8CH_2TXMIMO,
	RSDK_SAMPLES256_CHIRPS128_CP4D_8CH_6TXMIMO,
    RSDK_LAST_SUPPORTED_PROCESS_CHAIN
} rsdkProcessingChains_t;

/**
* @brief    List of the supported combining methods
* @details  This list is based on implemented SPT kernels
*/
typedef enum
{
    RSDK_NON_COH_COMB = 0U,
    RSDK_3DFFT,
    RSDK_LAST_SUPPORTED_ANT_COMB_TYPE,
} rsdkCombining_t;

/**
* @brief    List of the supported fields of view for beamscans - DBF FOV
* @details  This list is based on implemented SPT kernels
*/
typedef enum
{
    RSDK_DBF_30_DEG = 30U,
    RSDK_DBF_60_DEG = 60U,
    RSDK_DBF_90_DEG = 90U,
    RSDK_DBF_120_DEG = 120U,
    RSDK_LAST_SUPPORTED_DBF_FOV,
} rsdkDbfFov_t;

typedef enum
{
	RSDK_NO_MIMO = 0,
	RSDK_TD_MIMO,
	RSDK_DD_MIMO
}rsdkMimoType_t;

typedef enum
{
    NONE,  //LB
    RTP,
    TFTP,
    UART,
    RSDK_LAST_SUPPORTED_OUTPUT_CHANNEL
} rsdkOutputChannel_t;

typedef enum
{
    RSDK_SPT_NO_COMP = 0U,
    RSDK_SPT_CP4D
} rsdkSptCompMode_t;

/*=================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
=================================================================================================*/

typedef struct
{
    uint32_t *fftRangeTwiddle;   /* Twiddle buffers for FFT*/
    uint32_t *fftDopplerTwiddle; /* Twiddle buffers for FFT*/
    uint16_t *fftRangeWindow;    /* Window buffers for FFT*/
    uint16_t *fftDopplerWindow;  /* Window buffers for FFT*/
    uint32_t *fft16Twiddle;      /* Twiddle buffer for FFT16*/
    uint32_t *steeringVectors;   /* Steering vectors for DBF*/
    uint32_t *mimoDeRotVect;     /* TD-MIMO compensation vectors*/
} rsdkSptAuxVect_t;

typedef struct
{
	int32_t singleChirpSize;
	int32_t adcSampleBuff;
	int32_t fullAdcSampleBuff;
    int32_t
            sptRangeIn; /**< Size of ADC sample buffer used as input for RangeFFT. Takes into account the necessity of double buffering */
    int32_t sptRadarCube;      /**< Size of Radar 3D cube, same for output of RangeFFT and DopplerFFT in and out */
    int32_t sptRDM;            /**< Size of Range-Doppler magnitude matrix */
    int32_t sptThreshold;      /**< Size of Threshold list buffer - one threshold per Range bin */
    int32_t sptPeakDetScratch; /**< Size of Peak Search scratch buffer */
    int32_t sptPeakDetOut;     /**< Size of Peak Search output - detect list packed in a bitmap*/
    int32_t sptHistOut;        /**< Size of Histogram List - one histogram per Range bin*/
    int32_t sptRangeTwd;       /**< Size of Twiddle buffer for Range FFT*/
    int32_t sptDopplerTwd;     /**< Size of Twiddle buffer for Doppler FFT*/
    int32_t spt3dFftTwd;       /**< Size of Twiddle buffer for 3D FFT*/
    int32_t sptRangeWin;       /**< Size of Window buffer for Range FFT*/
    int32_t sptDopplerWin;     /**< Size of Window buffer for Doppler FFT*/
    int32_t sptSteerVect;      /**< Size of steering vectors for DBF*/
    int32_t sptDbfDoaIn;       /**< Size of DBF-DOA input buffer*/
    int32_t sptDbfDoaOut;      /**< Size of DBF-DOA output buffer*/
    int32_t peakInd;           /**< Size of Peak Indices buffer*/
    int32_t sptMimoDeRot;      /**< Size of TD-MIMO compensation vectors*/
} rsdkBufferSize_t;


typedef struct {
	uintptr_t tramInit;
	uintptr_t rangeFft;
	uintptr_t dopplerFft;
	uintptr_t antComb;
	uintptr_t peakSearch;
	uintptr_t beamForming;
	uintptr_t tramCheck;
}sptKernelChainAddr_t;


typedef struct
{
    uint8_t adcData;     /* Output full frame of ADC samples - no post processing*/
    uint8_t rangeData;   /* Output of Range FFT results*/
    uint8_t rdCube;      /* Output of Range-Doppler cube*/
    uint8_t rdMag;       /* Output of Range-Doppler magnitude matrix (in SPT log2 format)*/
    uint8_t psDet;       /* Output of peak detect bitmap*/
    uint8_t cfarDet;     /* Output of CFAR peak detect*/
    uint8_t peakAntData; /* Output of peaks' antenna data*/
    uint8_t dbfDoa;      /* Output of beamscans*/
    uint8_t peakList;    /* Output of detected peaks range, doppler, angle */
    uint8_t bistData;    /* Output of RFE BIST - adc samples, FFT and FFT magnitude */
    uint8_t profileInfo; /* Number of ticks for each radar processing step*/
} rsdkOutputEnable_t;


typedef struct
{
//	rsdkRfeFrontendMode_t rfeMode[RSDK_MAX_NR_FRONTENDS];
    rsdkMimoType_t    mimoType;
    rsdkSptCompMode_t cpMode;
    uint8_t           cpRate;
    uint8_t           rxActive;
    uint16_t          nrTxMimo;
    uint16_t          rFftSize;
    uint16_t          dFftSize;
    uint16_t          nrRangeBins;
    uint16_t          nrDopplerBins;
    uint16_t          nrVirtAnt;
    uint16_t 		  acqBuffNrChirps;
} rsdkAppOthers_t;

typedef struct
{
    /** [in] The ADC sampling frequency in kSps. See the enum rsdkRfe[device]SamplingFrequencies from the device
     * specific header for the list of supported values. */
    uint32_t samplingFrequency;
    /** [in] Number of chirps present in the frame. Refer to the RSDK_[device]_MAX_NR_OF_CHIRPS_PER_FRAME define
     * from the device specific header for the maximum value.*/
    uint16_t nrChirpsInFrame;
    /** [in] Number of sample that will be acquired during the acquisition window. See the define
     * RSDK_[device]_MAX_NR_OF_SAMPLES_PER_CHIRP for the maximum value supported. */
    uint16_t nrSamplesPerChirp;
    /** [in] The number of chirp shapes that will be configured for this frame. The application should allocate
     * an array of rsdkRfeChirpShape_t that will have nrChirpShapes elements. Refer to the
     * RSDK_[device]_MAX_NR_OF_CHIRPS_SHAPES from the device specific header for the maximum value.*/
    uint8_t nrChirpShapes;
//    /** [in] Array to the chirp shapes which will be generated in the current frame. */
//    rsdkRfeChirpShape_t chirpShapes[RSDK_MAX_NR_FRONTENDS][RSDK_RFE_MAX_CHIRP_SHAPES];
    /** [in] Bitfield indicating all enabled TX across programmed profiles. */
    uint8_t txChannelsUsed;
    uint16_t nrSequences;
    uint16_t seqChirpCount[APP_MAX_NR_SEQUENCES];
    uint16_t seqProfileSampleCount[APP_MAX_NR_SEQUENCES];
} rsdkRfeSettings_t;

typedef struct
{
    /** [in] Enable radar processing */
    rsdkProcessingEnable_t enableRadarProcessing;
    /** [in] Radar processing chain */
    rsdkProcessingChains_t radarProcessingChain;
	/** [in] Use adaptive scaling in Range processing */
	uint8_t sptRangeAdaptiveScaling;
	/** [in] Selected SPT processing chain supports cherent antenna combining */
	uint8_t coherentCombSupport;
    /** [in] Combining method */
    rsdkCombining_t antennaCombining;
    /** [in] Peak search histogram threshold value */
    uint16_t histThresholdFactor;
    /** [in] Threshold factor for DOA estimation. */
    uint16_t doaThesholdFactor;
    /** [in] DBF field of view. */
    rsdkDbfFov_t dbfFov;
    /** [in] This number is used for scaling up range FFT output data. Use with care in order to avoid saturation. */
    uint8_t scalingRange;
    /** [in] This number is used for scaling up doppler FFT output data. Use with care in order to avoid saturation. */
    uint8_t scalingDoppler;
    /** [in] Threshold factor of CFAR algo */
    float cfarTreshold;
    /** [in] Guard interval of CFAR algo value */
    uint8_t cfarGuardInterval;
    /** [in] Window size for CFAR algo */
    uint8_t cfarWindowSize;
} rsdkSigProcSettings_t;


typedef struct
{
    char usecase[50];
    int numOfRuns;
    int crtRunNum;
} rsdkAppSessionCfg_t;

typedef struct
{
	rsdkAppSessionCfg_t sessionCfg;
    uint8_t  appRunMode;  /* Continuous or fixed nr of frames*/
    uint16_t acqNrFrames; /* Number of frames to run the app*/

    uint8_t nrFrontends;

    /** [in] Radar front end chip settings */
    rsdkRfeSettings_t rfeSettings;
    /** [in] Radar SPT processing unit settings */
    rsdkSigProcSettings_t spSettings;
    /** [in] Output channel support */
    rsdkOutputChannel_t dataOutChannel;
    /** [in] Enable output for radar data*/
    rsdkOutputEnable_t dataOutEnable;
    /** CSI2 statistics */
    uint16_t csi2StatsEnable;
    /** Specific app settings */
    rsdkAppOthers_t specific;
} rsdkAppSettings_t;

typedef struct
{
    uint8       unitId;
    uint32      errMaskU;
} expCsi2ErrorInfo_t;

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif  //APPD_H
