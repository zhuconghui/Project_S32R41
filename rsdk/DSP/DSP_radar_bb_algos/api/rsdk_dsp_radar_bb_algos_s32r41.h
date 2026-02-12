/*
 * Copyright 2024 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

#ifndef DSP_ALGOS_S32R41_H
#define DSP_ALGOS_S32R41_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include <stdint.h>
#include "rsdk_status.h"


#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/** * @addtogroup dsp_algos_api_const
* @{
*/
#define BBE_SIMD_WIDTH (16u)

/** @} */
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
typedef enum rsdkBbe32FftShift
{
  RSDK_BBE32_FFT_SHIFT_0 = 0,       /**< Right shift by 0; /1*/
  RSDK_BBE32_FFT_SHIFT_1 = 5,       /**< Right shift by 1; /2*/
  RSDK_BBE32_FFT_SHIFT_2 = 10,      /**< Right shift by 2; /4*/
  RSDK_BBE32_FFT_SHIFT_3 = 15       /**< Right shift by 3; /8*/
} rsdkBbe32FftShift_t;	 		/**< @brief This structure is used to specify shift per stage to prevent saturation/overflow. */


typedef enum rsdkBbe32FftSize
{
  RSDK_BBE32_FFT_SIZE_128 = 128,
  RSDK_BBE32_FFT_SIZE_256 = 256,
  RSDK_BBE32_FFT_SIZE_512 = 512,
  RSDK_BBE32_FFT_SIZE_1024 = 1024,
  RSDK_BBE32_FFT_SIZE_2048 = 2048
} rsdkBbe32FftSize_t;	 		/**< @brief This structure is used to specify the size of the Fft. */
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/** * @addtogroup dsp_algos_api_data_type
* @{
*/

/**
 * @brief       The data types accepted by the BBE32 algos.
 * @details     Parameters for BBE32 radar signal processing algorithms.
 *
 */

typedef struct
{
    uint16_t rangeBins;        /**< <b>[in]</b> Number of range bins.*/
    uint16_t dopplerBins;      /**< <b>[in]</b>  Number of doppler bins. Must be multiple of 16 */
    uint8_t windowSize;        /**< <b>[in]</b>  Window size for CFAR algo. */
    uint8_t guardInterval;     /**< <b>[in]</b>  Guard interval of CFAR algo. */
    uint16_t  thresholdFactor; /**< <b>[in]</b>  Threshold factor. SPT Mag2Log2 format. User must prevent overflow/saturation.  */

    uint32_t pRdm; 			   /**< <b>[in]</b> Pointer to data buffer containing 2-D range-doppler magnitude matrix of size [N_CHIRPS*N_SAMPLES].
                                    It is represented as uint32_t to allow passing 32-bit addresses from A53 to BBE32.
                                    The buffer must be aligned at 32 bytes and size must be multiple of 32 bytes (16 16-bit magnitude values)*/
    uint32_t pThr;			   /**< <b>[in]</b> Pointer to scratch buffer used by RsdkBbe32Cfar() to store computed threshold values
                                    It is represented as uint32_t to allow passing 32-bit addresses from A53 to BBE32.
                                    The buffer must be aligned at 32 bytes and size must be multiple of 32 bytes*/
    uint32_t pDetectBitmap;    /**< <b>[out]</b> Pointer to data buffer which will store peak detection bitmap results, of size [(N_CHIRPS/16)*N_SAMPLES]
                                    It is represented as uint32_t to allow passing 32-bit addresses from A53 to BBE32*/
} rsdkBbe32CaCfarParams_t;     /**< @brief This structure is used to pass config parameters and in/out buffers to the CA-CFAR algorithm */

/**
 * @brief       The data types accepted by the BBE32 algos.
 * @details     Parameters for OS-CFAR algorithm.
 *
 */

typedef struct
{
    uint16_t dopplerBins;         /**< <b>[in]</b>  Number of doppler bins. Must be multiple of 16 */
} rsdkBbe32OsCfarParams_t;        /**< @brief This structure is used to pass config parameters to the OS-CFAR algorithm*/
/**
 * @brief       The data types accepted by the BBE32 algos.
 * @details     Parameters for complex DoA algorithms based on FFTs.
 *
 */
typedef struct
{
    uint32_t pOutMag;           /**< <b>[out]</b> Output. Magnitude values((a^2 + b ^ 2) / 2). Utile data size should be noPeaks * doaSize(128/256) * 4 bytes, but
                                      the allocated space must be noPeaks * doaSize(128/256) * 8 bytes.
                                      Each elements is represented on 24 bits, but stored on 32 bits.
                                      The output value should be scaled with (shift^4)^2 / 256.
                                      It is represented as uint32_t to allow passing 32-bit addresses from M7 to BBE32.
                                      */
    uint32_t pDetectBitmap;     /**< <b>[out]</b> Output. Local max Bitmap, size should be noPeaks * doaSize(128/256) * 2  / 16 bytes.
                                     Each elements of the bitmap is represented on 16 bits.
                                     It is represented as uint32_t to allow passing 32-bit addresses from M7 to BBE32.*/
    uint32_t pIn;			  	/**< <b>[in]</b> Input. Size should be noPeaks * noAntennas * 8 bytes.
                                     Both real and imaginary parts of each element is represented on 24 bits(q0.23 format), but stored on 32 bits.
                                     It is represented as uint32_t to allow passing 32-bit addresses from M7 to BBE32.*/
    uint32_t pScratch1Area;     /**< <b>[scratch] <\b> Scratch. Pointer to scratch area used in radix rounds of FFTs.
                                     Size should be 128 * 8 bytes for doa128.
                                     Size should be 256 * 8 bytes for doa256.
                                     Each element is represented on 24 bits, but stored on 32 bits.
                                     OPTIONAL: For best performance this should point to a DRAM area.
                                     It is represented as uint32_t to allow passing 32-bit addresses from M7 to BBE32.*/
    uint32_t pScratch2Area;     /**< <b>[scratch] <\b> Scratch. Pointer to scratch area used in radix rounds of FFTs.
                                     Each element is represented on 24 bits, but stored on 32 bits.
                                     Size should be 128 * 8 bytes for doa128.
                                     Size should be 256 * 8 bytes for doa256.
                                     OPTIONAL: For best performance this should point to a DRAM area(if possible in different memory from pScrach1Area).
                                     It is represented as uint32_t to allow passing 32-bit addresses from M7 to BBE32.*/
    uint32_t pTwiddlesArea;     /**< <b>[scratch] <\b> Scratch. Pointer to area where twiddles will be stored.
                                     Size should be 352 * 2 bytes for doa128.
                                     Size should be 832 * 2 bytes for doa256.
                                     Each element is stored on 16 bits, (q0.15) format.
                                     OPTIONAL: For the initialization of the twiddles values, RsdkBbe32FftInit() must be called before with the same addresses for twiddles and window areas.
                                     OPTIONAL: For best performance this should point to a DRAM area.
                                     It is represented as uint32_t to allow passing 32-bit addresses from M7 to BBE32.*/
    uint32_t pWindowArea;       /**< <b>[scratch] <\b> Scratch. Pointer to area where window coefficients will be stored. Size should be [doaSize(128/256) / 2 * 2] bytes for DOA128/256.
                                     Each element is stored on 16 bits, (q0.15) format.
                                     OPTIONAL: For the initialization of the window coefficients, RsdkBbe32FftInit() must be called before with the same addresses for twiddles and window areas.
                                     OPTIONAL: For best performance this should point to a DRAM area.
                                     It is represented as uint32_t to allow passing 32-bit addresses from M7 to BBE32.*/
    uint16_t noAntennas;		/**< <b>[in]</b> Input. Number of virtual antennas. */
    uint16_t noPeaks;           /**< <b>[in]</b> Input. Number of input peaks. */
    uint16_t shift;			    /**< <b>[in]</b> Shift amount for FFTs. RSDK_BBE32_FFT_SHIFT_2 should be used usually to prevent saturation.
                                     The available shift amounts are described in rsdkBbe32FftShift_t enum.
                                     User must prevent overflow/saturation.*/
    uint32_t thresholdFactor;   /**< <b>[in]</b> Input. The threshold factor is multiplied with the global maximum magnitude value for comparison with the local maximum values.
                                     The value represents a fixed-point value between [0,1] saved on 24 bits(q0.23).
                                     It is represented as uint32_t to allow passing from M7 to BBE32. */
} rsdkBbe32DoaParams_t;        	/**< @brief This structure is used to pass config parameters, in/out buffer to the DoA algorithm based on FFTs. */

/**
 * @brief       The data types accepted by the BBE32 algos.
 * @details     Parameters for FFT initlization for twdiddles and window coefficients
 *
 */
typedef struct
{
    uint32_t pTwiddlesArea;     /**< <b>[scratch] <\b> Scratch. Pointer to area where twiddles will be stored.
                                     Size should be 352 * 2 bytes for N = 128.
                                     Size should be 832 * 2 bytes for N = 256.
                                     Size should be 1536 * 2 bytes for N = 512.
                                     Size should be 3584 * 2 bytes for N = 1024.
                                     Size should be 6656 * 2 bytes for N = 2048.
                                     Each element is stored on 16 bits, (q0.15) format.
                                     OPTIONAL: For best performance this should point to a buffer in DRAM area, and should be called only once at the start of the application or when changing the used FFT size.
                                     IMPORTANT: Same buffer address must be used for both the initalization(RsdkBbe32FftInit()) and the actual FFT(RsdkBbe32Fft2Real()/RsdkBbe32Fft2Cplx()).
                                     IMPORTANT: Buffer must not be overwritten or have its address changed.
                                     It is represented as uint32_t to allow passing 32-bit addresses from M7 to BBE32.*/
    uint32_t pWindowArea;       /**< <b>[scratch] <\b> Scratch. Pointer to area where window coefficients will be stored. Size should be (N / 2) * 2 bytes.
                                     Each element is stored on 16 bits, (q0.15) format.
                                     OPTIONAL: For best performance this should point to a buffer in DRAM area, and should be called only once at the start of the application or when changing the used FFT size.
                                     IMPORTANT: Same buffer address must be used for both the initalization(RsdkBbe32FftInit()) and the actual FFT(RsdkBbe32Fft2Real()/RsdkBbe32Fft2Cplx()).
                                     IMPORTANT: Buffer must not be overwritten or have its address changed.
                                     It is represented as uint32_t to allow passing 32-bit addresses from M7 to BBE32.*/
	uint32_t size;              /** < <b>[in] <\b> Size of the desired FFT to be initialized(N).
	                                  The available sizes are described in rsdkBbe32FftSize_t enum. */
} rsdkBbe32FftInitParams_t; /** <@brief This struture is used to pass the window and twiddles area, for the RsdkBbe32FftInit() wrapper */

/**
 * @brief       The data types accepted by the BBE32 algos.
 * @details     Parameters for complex FFT algorithms.
 *
 */
typedef struct
{
    uint32_t pInOut;				  	/**< <b>[in/out]</b> Input/Output buffer pointer. The operation is done inplace, so buffer is used both for holding input signal and the corresponding output FFT. Size should be N * 8 bytes.
                                             Both real and imaginary parts of each element is represented on 24 bits(q0.23 format), but stored on 32 bits.
                                             It is represented as uint32_t to allow passing 32-bit addresses from M7 to BBE32.*/
    uint32_t pScratch1Area;             /**< <b>[scratch] <\b> Scratch. Pointer to scratch area used in radix rounds of FFTs. Size should be N * 8 bytes.
                                             Both real and imaginary parts of each element is represented on 24 bits(q0.23 format), but stored on 32 bits.
                                             OPTIONAL: For best performance this should point to a buffer in the DRAM area.
                                             IMPORTANT: Buffer can be overwritten/reused between multiple kernels or runs.
                                             It is represented as uint32_t to allow passing 32-bit addresses from M7 to BBE32.*/
    uint32_t pScratch2Area;             /**< <b>[scratch] <\b> Scratch. Pointer to scratch area used in radix rounds of FFTs.  Size should be N * 8 bytes.
                                             Both real and imaginary parts of each element is represented on 24 bits(q0.23 format), but stored on 32 bits.
                                             OPTIONAL: For best performance this should point to a buffer in the DRAM area(if possible in different memory from pScrach1Area).
                                             IMPORTANT: Buffer can be overwritten/reused between multiple kernels or runs.
                                             It is represented as uint32_t to allow passing 32-bit addresses from M7 to BBE32.*/
    uint32_t pTwiddlesArea;             /**< <b>[scratch] <\b> Scratch. Pointer to area where twiddles will be stored.
                                             Size should be 352 * 2 bytes for N = 128.
                                             Size should be 832 * 2 bytes for N = 256.
                                             Size should be 1536 * 2 bytes for N = 512.
                                             Size should be 3584 * 2 bytes for N = 1024.
                                             Size should be 6656 * 2 bytes for N = 2048.
                                             Each element is stored on 16 bits, (q0.15) format.
                                             OPTIONAL: For best performance this should point to a buffer in DRAM area, and should be kept at CONSTANT ADDRESS between multiple chirps processing.
                                             IMPORTANT: For the initialization of the twiddles values, RsdkBbe32FftInit() must be called before with the same addresses for twiddles and window areas.
                                             IMPORTANT: Buffer must not be overwritten or have its address changed.
                                             It is represented as uint32_t to allow passing 32-bit addresses from M7 to BBE32.*/
    uint32_t pWindowArea;               /**< <b>[scratch] <\b> Scratch. Pointer to area where window coefficients will be stored. Size should be (N / 2) * 2 bytes.
                                             Each element is stored on 16 bits, (q0.15) format.
                                             OPTIONAL: For best performance this should point to a buffer in DRAM area, and should be kept at CONSTANT ADDRESS between multiple chirps processing.
                                             IMPORTANT: For the initialization of the window values, RsdkBbe32FftInit() must be called before with the same addresses for twiddles and window areas.
                                             IMPORTANT: Buffer must not be overwritten or have its address changed.
                                             It is represented as uint32_t to allow passing 32-bit addresses from M7 to BBE32.*/
    uint16_t shift;			             /**< <b>[in]</b> Shift amount. RSDK_BBE32_FFT_SHIFT_2 should be used usually to prevent saturation between radix rounds. The available shift amounts are described in rsdkBbe32FftShift_t enum*/
    uint16_t size;			             /**< <b>[in]</b> Size of the FFTs/input signals(N).
                                              The available sizes are described in rsdkBbe32FftSize_t enum */
} rsdkBbe32FftCplxParams_t;        		/**< @brief This structure is used to pass config parameters, scratch buffers, in/out buffer to the FFT algorithm */

/**
 * @brief       The data types accepted by the BBE32 algos.
 * @details     Parameters for 2 real input FFT algorithm.
 *
 */
typedef struct
{
    uint32_t pOut1;				  	/**< <b>[out]</b> Output buffer, containing the complex output lower half of FFT corresponding to the first input signal. Size should be (N / 2) * 8 bytes.
                                             Each element is represented on 24 bits(q0.23 format), but stored on 32 bits.
                                             IMPORTANT: pOut1 and pIn1 can point to the same memory location!
                                             It is represented as uint32_t to allow passing 32-bit addresses from M7 to BBE32. */
    uint32_t pOut2;				  	/**< <b>[out]</b> Output buffer, containing the complex output lower half of FFT corresponding to the second input signal. Size should be (N / 2) * 8 bytes.
                                             Each element is represented on 24 bits(q0.23 format), but stored on 32 bits.
                                             IMPORTANT: pOut2 and pIn2 can point to the same memory location!
                                             It is represented as uint32_t to allow passing 32-bit addresses from M7 to BBE32. */
    uint32_t pIn1;				  	/**< <b>[in]</b> Input buffer containing the first real input signal. Size should be N * 2 bytes.
                                             Each element is represented on 16 bits(q0.15 format).
                                             IMPORTANT: pOut1 and pIn1 can point to the same memory location!
                                             It is represented as uint32_t to allow passing 32-bit addresses from M7 to BBE32. */
    uint32_t pIn2;				  	/**< <b>[in]</b> Input buffer containing the second real input signal. Size should be N * 2 bytes.
                                             Each element is represented on 16 bits(q0.15 format).
                                             IMPORTANT: pOut2 and pIn2 can point to the same memory location!
                                             It is represented as uint32_t to allow passing 32-bit addresses from M7 to BBE32. */
    uint32_t pScratch1Area;             /**< <b>[scratch] <\b> Scratch. Pointer to scratch area used in radix rounds of FFTs.  Size should be N * 8 bytes.
                                             Both real and imaginary parts of each element is represented on 24 bits(q0.23 format), but stored on 32 bits.
                                             OPTIONAL: For best performance this should point to a buffer in the DRAM area
                                             IMPORTANT: Buffer can be overwritten/reused between multiple kernels or runs.
                                             It is represented as uint32_t to allow passing 32-bit addresses from M7 to BBE32.*/
    uint32_t pScratch2Area;             /**< <b>[scratch] <\b> Scratch. Pointer to scratch area used in radix rounds of FFTs.  Size should be N * 8 bytes.
                                             Both real and imaginary parts of each element is represented on 24 bits(q0.23 format), but stored on 32 bits.
                                             OPTIONAL: For best performance this should point to a buffer in the DRAM area(if possible in different memory from pScratch1Area).
                                             IMPORTANT: Buffer can be overwritten/reused between multiple kernels or runs.
                                             It is represented as uint32_t to allow passing 32-bit addresses from M7 to BBE32.*/
    uint32_t pScratch3Area;             /**< <b>[scratch] <\b> Scratch. Pointer to scratch area used for combining the two input signals. Size should be ( N + 8) * 8 bytes.
                                             Both real and imaginary parts of each element is represented on 24 bits(q0.23 format), but stored on 32 bits.
                                             OPTIONAL: For best performance this should point to a buffer in the DRAM area
                                             IMPORTANT: Buffer can be overwritten/reused between multiple kernels or runs.
                                             It is represented as uint32_t to allow passing 32-bit addresses from M7 to BBE32.*/
    uint32_t pTwiddlesArea;             /**< <b>[scratch] <\b> Scratch. Pointer to area where twiddles will be stored.
                                             Size should be 352 * 2 bytes for N = 128.
                                             Size should be 832 * 2 bytes for N = 256.
                                             Size should be 1536 * 2 bytes for N = 512.
                                             Size should be 3584 * 2 bytes for N = 1024.
                                             Size should be 6656 * 2 bytes for N = 2048.
                                             Each element is stored on 16 bits, (q0.15) format.
                                             OPTIONAL: For best performance this should point to a buffer in DRAM area, and should be kept at CONSTANT ADDRESS between multiple chirps processing.
                                             IMPORTANT: For the initialization of the twiddles values, RsdkBbe32FftInit() must be called before with the same addresses for twiddles and window areas.
                                             IMPORTANT: Buffer must not be overwritten or have its address changed.
                                             It is represented as uint32_t to allow passing 32-bit addresses from M7 to BBE32.*/
    uint32_t pWindowArea;               /**< <b>[scratch] <\b> Scratch. Pointer to area where window coefficients will be stored. Size should be (N / 2) * 2 bytes.
                                             Each element is stored on 16 bits, (q0.15) format.
                                             OPTIONAL: For best performance this should point to a buffer in DRAM area, and should be kept at CONSTANT ADDRESS between multiple chirps processing.
                                             IMPORTANT: For the initialization of the window values, RsdkBbe32FftInit() must be called before with the same addresses for twiddles and window areas.
                                             IMPORTANT: Buffer must not be overwritten or have its address changed.
                                             It is represented as uint32_t to allow passing 32-bit addresses from M7 to BBE32.*/
    uint16_t shift;			            /**< <b>[in]</b> Shift amount. RSDK_BBE32_FFT_SHIFT_2 should be used usually to prevent saturation between radix rounds. The available shift amounts are described in rsdkBbe32FftShift_t enum*/
    uint16_t size;			             /**< <b>[in]</b> Size of the FFTs/input signals(N).
                                              The available sizes are described in rsdkBbe32FftSize_t enum */
} rsdkBbe32Fft2RealParams_t;         	/**< @brief This structure is used to pass config parameters, scratch buffers, in/out buffers to the 2 real FFT algorithm */

/**
 * @brief       The data types accepted by the BBE32 algos.
 * @details     Parameters for Histogram algorithm.
 *
 */
typedef struct
{
    uint32_t pOut;				  	/**< <b>[out]</b> Output buffer. Size should be sizeEdges * 4 bytes.*/
    uint32_t pIn;				  	/**< <b>[in]</b> Input buffer. Size should be size * 4 bytes.*/
    uint32_t pEdges;				/**< <b>[in]</b> Edges Input buffer. Size should be sizeEdges * 4 bytes.*/
    uint16_t size;					/**< <b>[in]</b> Size of input buffer. */
    uint16_t sizeEdges;				/**< <b>[in]</b> Size of the edges buffer. */
} rsdkBbe32HistParams_t;         	/**< @brief This structure is used to pass config parameters, edges buffer, in buffer and out buffer to the Histogram algorithm */

/**
 * @brief       The data types accepted by the BBE32 algos.
 * @details     Parameters for Reorder algorithm.
 *
 */

typedef struct
{
	uint32_t pOutDat;        /**< <b>[out]</b> Pointer to data buffer containing output data vector concatenated for all antennas, containing 16-bit elements.
                                   It is represented as uint32_t to allow passing 32-bit addresses from M7 to BBE32. */
	uint32_t pInDat;         /**< <b>[in]</b> Pointer to data buffer containing input data vector of 4 Channels tile 16(16 elem ch1, 16 elem ch2, 16 elem ch3, 16 elem ch4, 16 ch1, 16 ch2, 16 ch3, 16 ch4 ...) of size [noElements], containing elements on 16 bits.
                                   It is represented as uint32_t to allow passing 32-bit addresses from M7 to BBE32. */
	uint8_t doubleInBufEn;/**< <b>[in]</b> Control flag to specify whether RsdkBbe32ReordTile16to4Ch() should toggle the pInDat pointer in a ping-pong fashion, to match with the CSI2 double-buffer data aquisition pattern.
	                                Valid values: "0" = disable, "non-0" = enable.  */
	uint16_t noElements;    /** <b>[in]</b> Number of input elements must be multiple of 64 (16 samples * 4 channels) */
} rsdkBbe32ReordTile16to4ChParams_t; /**< @brief This structure is used to pass config parameters to the algorithm of RsdkBbe32ReordTile16to4Ch()*/


/** @} */
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/** * @addtogroup dsp_algos_api_func
* @{
*/
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
/**
* @brief	1D CA-CFAR implementation iso-doppler dimension
* Using sliding window approach to avoid redundant summations.
*
* @param [in] argList - pointer to a data structure of type rsdkBbe32CaCfarParams_t containing the CA-CFAR parameters and buffers.
*
* @pre This implementation assumes the following memory layout of the input RDM buffer passed by rsdkBbe32CfarParams_t::pRdm :
*
* INPUT Memory layout example for RangeBins = Nr, DopplerBins = Nd:
* Sample format: 16 bit real SPT "Log2 Mag2"
*
*  |offset bytes:| 0          | 2        | ...   | 2*(Nd-2)         | 2*(Nd-1)    |
*  |-------------|------------|----------|-------|------------------|-------------|
*  |           0 | R0_D0      | R0_D1    | ...   | R0_D<Nd-1>       | R0_D<Nd>    |
*  |        2*Nd | R1_D0      | R1_D1    | ...   | R1_D<Nd-1>       | R1_D<Nd>    |
*  |             | :          | :        |       | :                | :           |
*  |             | :          | :        |       | :                | :           |
*  | 2*(Nr-1)*Nd | R<Nr>_D0   | R1<Nr>_D1| ...   | R1<Nr>_D<Nd-1>   | R1<Nr>_D<Nd>|
*
*/
void RsdkBbe32CaCfar(uintptr_t argList);

/**
* @brief	1D OS-CFAR implementation across RDM 'range' dimension
* @param [in] argList - pointer to a data structure of type rsdkBbe32OsCfarParams_t containing the OS-CFAR parameters.
* @details This function reads the input samples (from ORAM) and the sliding window thresholds (from ORAM) computed in the RsdkSptOsCfar kernel and then
* computes a new threshold vector. \n
* The newly formed threshold vector is compared with the input samples element wise. If the sample is greater than the threshold the
* corresponding bit is set to 1 (1byte = 8 elements). Thre result is written back in ORAM.
* @pre
* !!! THIS FUNCTION SHOULD ONLY BE USED INSIDE THE RsdkSptOsCfar KERNEL \n
* The input is taken from ORAM and the output is written to ORAM. \n
* \if S32R45_DOCS
* The memory map is fixed. Input samples: OR_0_0_0 SW controller, Input thresholds for BBE32: OR_0_0_0 NE controller, Output: OR_0_0_0  NE controller \n
* If the memory layout is changed in the RsdkSptOsCfar kernel then RsdkBbe32OsCfar needs to be changed in the following way: \n
* op_br0 - controls the bank selection for RLU0 (Acces to OR_0_0_0 to OR_3_0_0 in NW(0-3) and SW(4-7)) \n
* op_br1 - controls the bank selection for RLU1 (Acces to OR_0_0_0 to OR_3_0_0 in SE(8-11) and ME(12-15)) \n
* op_bw0 - controls the bank selection for WLU (Acces to OR_0_0_0 to OR_3_0_0 in NW(0-3), SW(4-7), SE(8-11) and ME(12-15)) \n
* RESTRICTION: op_br0, op_br1 and op_bw0 SHOULD POINT TO DIFFERENT CONTROLLERS with op_br0 accesing only banks 0-7, op_br1 accesing only banks 8-15 and op_bw accesing banks 0-15 \n
* \endif
* \if (S32R41_DOCS || SAF85XX_DOCS)
* The memory map is fixed. Input samples: OR_0_0_0, Input thresholds for BBE32: OR_2_0_0, Output: OR_0_0_0 \n
* If the memory layout is changed in the RsdkSptOsCfar kernel then RsdkBbe32OsCfar needs to be changed in the following way: \n
* op_br0 - controls the bank selection for RLU0 \n
* op_br1 - controls the bank selection for RLU1 \n
* op_bw0 - controls the bank selection for WLU \n
* RESTRICTION: op_br0, op_br1 and op_bw0 SHOULD POINT TO DIFFERENT CONTROLLERS \n
* \endif
*/
void RsdkBbe32OsCfar(uintptr_t argList);

/**
* @brief	Initialization of FFT window and twiddle coefficients for one particular size.
* @details  Copies the window and twiddle coefficients(recommended in SRAM) to the two pointers provided(recommened in DRAM).
*
* @param [in] argList - pointer to a data structure of type rsdkBbe32FftInitParams_t containing the FFT size, twiddles and windows destination areas.
*
*/
void RsdkBbe32FftInit(uintptr_t argList);

/**
* @brief	 FFT 24bits complex
* @details  Performs FFT on 24bits complex operands.
*
* @param [in] argList - pointer to a data structure of type rsdkBbe32FftCplxParams_t containing the FFT parameters and buffers.
*
* @pre RsdkBbe32FftInit() must be called for initializing FFT window and twiddles coefficients before calling this function the same size parameter.
* The FFT is computed inplace, meaning that the pInOut serves both as an input complex signal, and as the output complex FFT and uses int32_t for real and imaginary parts.
* <br>Even though the operations are performed on 24bits (re, imag), the data is stored in memory on 32 bits. The output is sign extended to 32 bits.
* The shift value should be RSDK_BBE32_FFT_SHIFT_2 since a division by 4 is required before performing each radix4/radix2 round to prevent saturation.
* <br> The output signals should be scaled with shift_value^radix_stages.
* <br> The available sizes are described in rsdkBbe32FftSize_t enum.
* <br> OPTIONAL: For maintaining the accuracy of the result, the output FFT can be scaled with shift_value^radix_stages.
* The twiddles and window coefficients are converted from q0.15 to q0.23 fixed point. \n
*
*/
void RsdkBbe32FftCplx(uintptr_t argList);

/**
* @brief	 FFT 24bits 2 real inputs
* @details  Performs FFT on 24bits 2 real operands in 1 complex operand. Lower half of each Fft is returned.
*
* @param [in] argList - pointer to a data structure of type rsdkBbe32Fft2RealParams_t containing the FFT parameters and buffers.
*
* @pre RsdkBbe32FftInit() must be called for initializing FFT window and twiddles coefficients before calling this function the same size parameter.
*
* <br> The pOut1 an pOut2 are pointers that serve both as two output complex lower half FFTs(one for each signal) and uses int32_t.
* <br> Even though the operations are performed  on 24bits (re, imag), the data is stored in memory on 32 bits. The outputs are sign extended to 32 bits.
* <br> The shift value should be RSDK_BBE32_FFT_SHIFT_2 since a division by 4 is required before performing each radix4/radix2 round to prevent saturation.
* <br> The available sizes are described in rsdkBbe32FftSize_t enum.
* <br> OPTIONAL: For maintaining the accuracy of the results, the two output FFTs can be scaled with shift_value^radix_stages.
* <br> OPTIONAL: pIn1 and pOut1 can point to the same memory location, pIn2 and pOut2 can point to the same memory location.
* <br> There are 4 stages for 128 and 256 input size buffers; 5 stages for 512 and 1024 input size; 6 stages for 2048 input size.
* <br> The twiddles and window coefficients are converted inside the used complex FFT kernel from q0.15 to q0.23 fixed point. \n
*
*/
void RsdkBbe32Fft2Real(uintptr_t argList);


/**
* @brief	 Histogram 24bits real
* @details   Performs Histogram on 24 bits 2 real inputs (data and edges). \n
*            It sorts data into bins with bin edges specified in the edges vector.
*            The output values (expect the last two scalar values) represent how many input values respect the following inequation: edge(i) <= in < edge(i + 1); i=0...M-1. \n
*            The second last scalar value(int32_t) represents how many input values respect the following inequation: edge(M-2) <= in <= edge(M-1).
*            The last scalar value(int32_t) is not useful data.
*
* @param [in] argList - pointer to a data structure of type rsdkBbe32HistParams_t containing the Histogram parameters and buffers.
*
* @pre The pOut an pIn and pEdges are pointers to real output and input data which use int32_t.
* <br> The output are sign extended to 32 bits.
* <br> Values of the edges(threshold values) must be stored in ascending order.
* <br> The size(N) and sizeEdges(M) are restricted to being multiple of 16.
* <br> The useful output data has size equal to (sizeEdges - 1).
*
*/
void RsdkBbe32Hist(uintptr_t argList);
/**
* @brief	 DoA 128 24bits complex input
* @details   Performs DoA based on FFT128 on 24bits on complex operands.
*            The algorihm extends an input vector to 128 complex elements(fill with 0), applies the corresponding FFT and computes the mag2 => (real^2 + imag^2)/2. \n
*            Using these values, the maximum mag2 value is computed and multiplied with a threshold factor obtaining a threshold value. \n
*            This result is then compared with all the local maximum values(localMaxMag2 > threshold) of the mag2 for creating a bitmap. \n
*            A value mag2(i) is considered a local maximum value if (mag2(i) > mag2(i - 1) and mag2(i) >= mag2(i+1)). \n
*            The start and the end of the resulting mag2 vector are not considered.
*
*
* @param [in] argList - pointer to a data structure of type rsdkBbe32DoaParams_t containing the DoA parameters and buffers.
*
* @pre RsdkBbe32FftInit() must be called for initializing FFT window and twiddles coefficients before calling this function the same size parameter.
* @pre The pOutMag an pIn are pointers to the real mag2 output and complex input data respectively, which use int32_t.
* <br> Even though the operations are performed  on 24bits (re, imag), the data is stored in memory on 32 bits. The outputs are sign extended to 32 bits.
* <br> The pDetectBitmap contains the resulting bitmap and is represented using uint16_t.
* <br> The shift value should be RSDK_BBE32_FFT_SHIFT_2 since a division by 4 is required before performing each radix4/radix2 round to prevent saturation.
* <br> The available sizes are described in rsdkBbe32FftSize_t enum.
* <br> The output signals should be scaled with (shift_value^4)^2 / 256.
* <br> The twiddles and window coeffi are converted inside the used FFT kernel from q0.15 to q0.23 fixed point. \n
*
*/
void RsdkBbe32Doa128(uintptr_t argList);
/**
* @brief	 DoA 256 24bits complex input
* @details   Performs DoA based on FFT256 on 24bits on complex operands.
*            The algorihm extends an input vector to 256 complex elements(fill with 0), applies the corresponding FFT and computes the mag2 => (real^2 + imag^2)/2. \n
*            Using these values, the maximum mag2 value is computed and multiplied with a threshold factor obtaining a threshold value. \n
*            This result is then compared with all the local maximum values(localMaxMag2 > threshold) of the mag2 for creating a bitmap. \n
*            A value mag2(i) is considered a local maximum value if (mag2(i) > mag2(i - 1) and mag2(i) >= mag2(i+1)). \n
*            The start and the end of the resulting mag2 vector are not considered.
*
*
* @param [in] argList - pointer to a data structure of type rsdkBbe32DoaParams_t containing the DoA parameters and buffers.
*
* @pre RsdkBbe32FftInit() must be called for initializing FFT window and twiddles coefficients before calling this function the same size parameter.
* @pre The pOutMag an pIn are pointers to the real mag2 output and complex input data respectively, which use int32_t.
* <br> Even though the operations are performed  on 24bits (re, imag), the data is stored in memory on 32 bits. The outputs are sign extended to 32 bits.
* <br> The pDetectBitmap contains the resulting bitmap and is represented using uint16_t.
* <br> The shift value should be RSDK_BBE32_FFT_SHIFT_2 since a division by 4 is required before performing each radix4/radix2 round to prevent saturation.
* <br> The available sizes are described in rsdkBbe32FftSize_t enum.
* <br> The output signals should be scaled with (shift_value^4)^2 / 256.
* <br> The twiddles and window coefficients and are converted inside the used FFT kernel from q0.15 to q0.23 fixed point. \n
*
*/
void RsdkBbe32Doa256(uintptr_t argList);

/**
* @brief	 Reorder tile 16 data from 1 buffer of 16 bits elements to 4 data buffer of 16 bits elements
* @details   Performs a reorder from a buffer containing data from 4 channels tile 16 (16 elem ch1, 16 elem ch2, 16 elem ch3, 16 elem ch4, 16 elem ch1, 16 elem ch2, 16 elem ch3, 16 elem ch4, ....) to 4 buffers of 16 bits elements.
*
* @param [in] argList - pointer to a data structure of type rsdkBbe32ReordTile16to4ChParams_t containing the reorder parameters and buffers.
*
* @pre noElements, representing the number of input elements must be multiple of 64. \n
*
*/
void RsdkBbe32ReordTile16to4Ch(uintptr_t argList);

/** @} */

#ifdef __cplusplus
}
#endif

/*******************************************************************************
* EOF
******************************************************************************/


#endif /*DSP_ALGOS_S32R41_H*/
