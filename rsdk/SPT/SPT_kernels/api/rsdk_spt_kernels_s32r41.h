/**************************************************************************************************
 * 
 * NXP Confidential Proprietary
 *
 * Copyright 2021, 2023 NXP
 * All Rights Reserved
 *
 *****************************************************************************
 *
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 *
 **************************************************************************************************/

#ifndef RSDK_SPT_KERNELS_S32R41_API_H
#define RSDK_SPT_KERNELS_S32R41_API_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
/* NA */

/**
* \addtogroup spt_kernels_api_const
* 
*/
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
// clang-format off
/**
* @brief          <br><br> <b>Number of input data streams to be processed:</b>
* @details        The SPT modules can be used only when The number of ADC channels used
*                 in the radar application is equal to this values.
*/
//@{
#define RSDK_SPT_NUM_4CHANNELS              (4)
#define RSDK_SPT_NUM_8CHANNELS              (8)
#define RSDK_SPT_NUM_2TXTDMIMO_SLOTS        (2)
#define RSDK_SPT_NUM_3TXTDMIMO_SLOTS        (3)
#define RSDK_SPT_NUM_4TXTDMIMO_SLOTS        (4)
#define RSDK_SPT_NUM_6TXTDMIMO_SLOTS        (6)
#define RSDK_SPT_NUM_2TXTDMIMO_4CHANNELS    (RSDK_SPT_NUM_4CHANNELS * RSDK_SPT_NUM_2TXTDMIMO_SLOTS)
#define RSDK_SPT_NUM_3TXTDMIMO_4CHANNELS    (RSDK_SPT_NUM_4CHANNELS * RSDK_SPT_NUM_3TXTDMIMO_SLOTS)
#define RSDK_SPT_NUM_4TXTDMIMO_4CHANNELS    (RSDK_SPT_NUM_4CHANNELS * RSDK_SPT_NUM_4TXTDMIMO_SLOTS)
#define RSDK_SPT_NUM_2TXTDMIMO_8CHANNELS    (RSDK_SPT_NUM_8CHANNELS * RSDK_SPT_NUM_2TXTDMIMO_SLOTS)
#define RSDK_SPT_NUM_6TXTDMIMO_8CHANNELS    (RSDK_SPT_NUM_8CHANNELS * RSDK_SPT_NUM_6TXTDMIMO_SLOTS)
#define RSDK_SPT_NUM_3TXDDMIMO_4CHANNELS    (RSDK_SPT_NUM_4CHANNELS * 3)
//@}

/**
* @brief          <br><br> <b>Size of Twiddle factors buffer in uint32 values:</b> 
* @details        Can be used by the upper layers at application level to allocate memory space for 
*                 twiddle factors buffer.
*/
//@{
#define RSDK_SPT_FFT2048_TWIDDLE_BUF_SIZE  (2048)
#define RSDK_SPT_FFT1024_TWIDDLE_BUF_SIZE  (1024)
#define RSDK_SPT_FFT512_TWIDDLE_BUF_SIZE    (512)
#define RSDK_SPT_FFT256_TWIDDLE_BUF_SIZE    (256)
#define RSDK_SPT_FFT128_TWIDDLE_BUF_SIZE    (128)
#define RSDK_SPT_FFT64_TWIDDLE_BUF_SIZE      (64)
#define RSDK_SPT_FFT32_TWIDDLE_BUF_SIZE      (32)
#define RSDK_SPT_FFT16_TWIDDLE_BUF_SIZE      (16)
//@}

/**
* @brief          <br><br> <b>Size of window buffer in int16 values:</b>
* @details        Can be used by the upper layers at application level to allocate memory space for 
*                 window coefficients buffer.
*/
//@{
#define RSDK_SPT_FFT2048_WINDOW_BUF_SIZE   (2048)
#define RSDK_SPT_FFT1024_WINDOW_BUF_SIZE   (1024)
#define RSDK_SPT_FFT512_WINDOW_BUF_SIZE     (512)
#define RSDK_SPT_FFT256_WINDOW_BUF_SIZE     (256)
#define RSDK_SPT_FFT128_WINDOW_BUF_SIZE     (128)
#define RSDK_SPT_FFT64_WINDOW_BUF_SIZE       (64)
//@}

/**
* @brief          <br><br> <b>Size of input buffer for range FFT in int16 values:</b>
* @details        Can be used by the upper layers at application level to allocate memory space for SDADC samples.
*/
//@{
#define RSDK_SPT_RANGE512_4CH_IN_BUF_SIZE                           (RSDK_SPT_NP_RANGE512 * RSDK_SPT_NUM_4CHANNELS * RSDK_SPT_DOUBLE_BUFFER + RSDK_CSI2_STATS_DOUBLE_BUFFER)
#define RSDK_SPT_RANGE256_4CH_IN_BUF_SIZE                           (RSDK_SPT_NP_RANGE256 * RSDK_SPT_NUM_4CHANNELS * RSDK_SPT_DOUBLE_BUFFER + RSDK_CSI2_STATS_DOUBLE_BUFFER)
#define RSDK_SPT_RANGE1024_4CH_IN_BUF_SIZE                          (RSDK_SPT_NP_RANGE1024 * RSDK_SPT_NUM_4CHANNELS * RSDK_SPT_DOUBLE_BUFFER + RSDK_CSI2_STATS_DOUBLE_BUFFER)
#define RSDK_SPT_RANGE2048_4CH_IN_BUF_SIZE                          (RSDK_SPT_NP_RANGE2048 * RSDK_SPT_NUM_4CHANNELS * RSDK_SPT_DOUBLE_BUFFER + RSDK_CSI2_STATS_DOUBLE_BUFFER)

//@}

/**
* @brief          <br><br> <b>Size of Range FFT results buffer in uint32 values:</b>
* @details        Can be used by the upper layers at application level to allocate memory space for range fft result.
*                 Syntax include: < M>x<N>, M=number of samples and N=chirps.
*/
//@{
#define RSDK_SPT_RANGE_512x128_4CH_OUT_BUF_SIZE                      (RSDK_SPT_NUM_4CHANNELS * (RSDK_SPT_NP_RANGE512 >> 1) * RSDK_SPT_NP_DOPPLER128)
#define RSDK_SPT_RANGE_256x256_4CH_OUT_BUF_SIZE                      (RSDK_SPT_NUM_4CHANNELS * (RSDK_SPT_NP_RANGE256 >> 1) * RSDK_SPT_NP_DOPPLER256)
#define RSDK_SPT_RANGE_1024x64_4CH_CP4D_OUT_BUF_SIZE                ((RSDK_SPT_NUM_4CHANNELS * (RSDK_SPT_NP_RANGE1024 >> 1) * RSDK_SPT_NP_DOPPLER64) >> 1)
#define RSDK_SPT_RANGE_1024x128_4CH_CP4D_OUT_BUF_SIZE               ((RSDK_SPT_NUM_4CHANNELS * (RSDK_SPT_NP_RANGE1024 >> 1) * RSDK_SPT_NP_DOPPLER128) >> 1)
#define RSDK_SPT_RANGE_2048x256_4CH_CP4D_OUT_BUF_SIZE               ((RSDK_SPT_NUM_4CHANNELS * (RSDK_SPT_NP_RANGE2048 >> 1) * RSDK_SPT_NP_DOPPLER256) >> 1)
#define RSDK_SPT_RANGE_256x256_4CH_2TXTDMIMO_CP4D_OUT_BUF_SIZE      ((RSDK_SPT_NUM_2TXTDMIMO_4CHANNELS * (RSDK_SPT_NP_RANGE256 >> 1) * RSDK_SPT_NP_DOPPLER256) >> 1)
#define RSDK_SPT_RANGE_256x128_4CH_3TXTDMIMO_OUT_BUF_SIZE            (RSDK_SPT_NUM_3TXTDMIMO_4CHANNELS * (RSDK_SPT_NP_RANGE256 >> 1) * RSDK_SPT_NP_DOPPLER128)
#define RSDK_SPT_RANGE_1024x64_4CH_4TXTDMIMO_CP4D_OUT_BUF_SIZE      ((RSDK_SPT_NUM_4TXTDMIMO_4CHANNELS * (RSDK_SPT_NP_RANGE1024 >> 1) * RSDK_SPT_NP_DOPPLER64)>>1)
#define RSDK_SPT_RANGE_1024x256_4CH_3TXDDMIMO_CP4D_OUT_BUF_SIZE     ((RSDK_SPT_NUM_4CHANNELS * (RSDK_SPT_NP_RANGE1024 >> 1) * RSDK_SPT_NP_DOPPLER256) >> 1)
#define RSDK_SPT_RANGE_512x128_8CH_OUT_BUF_SIZE                      (RSDK_SPT_NUM_8CHANNELS * (RSDK_SPT_NP_RANGE512 >> 1) * RSDK_SPT_NP_DOPPLER128)
#define RSDK_SPT_RANGE_256x256_8CH_OUT_BUF_SIZE                      (RSDK_SPT_NUM_8CHANNELS * (RSDK_SPT_NP_RANGE256 >> 1) * RSDK_SPT_NP_DOPPLER256)
#define RSDK_SPT_RANGE_1024x128_8CH_CP4D_OUT_BUF_SIZE               ((RSDK_SPT_NUM_8CHANNELS * (RSDK_SPT_NP_RANGE1024 >> 1) * RSDK_SPT_NP_DOPPLER128) >> 1)
#define RSDK_SPT_RANGE_256x256_8CH_2TXTDMIMO_CP4D_OUT_BUF_SIZE      ((RSDK_SPT_NUM_2TXTDMIMO_8CHANNELS * (RSDK_SPT_NP_RANGE256 >> 1) * RSDK_SPT_NP_DOPPLER256) >> 1)
#define RSDK_SPT_RANGE_256x128_8CH_6TXTDMIMO_CP4D_OUT_BUF_SIZE      ((RSDK_SPT_NUM_6TXTDMIMO_8CHANNELS * (RSDK_SPT_NP_RANGE256 >> 1) * RSDK_SPT_NP_DOPPLER128) >> 1)


//@}

/**
* @brief          <br><br> <b>Size of Doppler FFT results buffer in uint32 values:</b>
* @details        Can be used by the upper layers at application level to allocate memory space for doppler fft result.
*                 Syntax include: < M>x<N>, M=number of samples and N=chirps.
*/
//@{
#define RSDK_SPT_DOPPLER_512x128_4CH_OUT_BUF_SIZE                    (RSDK_SPT_NUM_4CHANNELS * (RSDK_SPT_NP_RANGE512 >> 1) * RSDK_SPT_NP_DOPPLER128)
#define RSDK_SPT_DOPPLER_256x256_4CH_OUT_BUF_SIZE                    (RSDK_SPT_NUM_4CHANNELS * (RSDK_SPT_NP_RANGE256 >> 1) * RSDK_SPT_NP_DOPPLER256)
#define RSDK_SPT_DOPPLER_1024x64_4CH_CP4D_OUT_BUF_SIZE              ((RSDK_SPT_NUM_4CHANNELS * (RSDK_SPT_NP_RANGE1024 >> 1) * RSDK_SPT_NP_DOPPLER64) >> 1)
#define RSDK_SPT_DOPPLER_1024x128_4CH_CP4D_OUT_BUF_SIZE             ((RSDK_SPT_NUM_4CHANNELS * (RSDK_SPT_NP_RANGE1024 >> 1) * RSDK_SPT_NP_DOPPLER128) >> 1)
#define RSDK_SPT_DOPPLER_2048x256_4CH_CP4D_OUT_BUF_SIZE             ((RSDK_SPT_NUM_4CHANNELS * (RSDK_SPT_NP_RANGE2048 >> 1) * RSDK_SPT_NP_DOPPLER256) >> 1)
#define RSDK_SPT_DOPPLER_256x256_4CH_2TXTDMIMO_CP4D_OUT_BUF_SIZE    ((RSDK_SPT_NUM_2TXTDMIMO_4CHANNELS * (RSDK_SPT_NP_RANGE256 >> 1) * RSDK_SPT_NP_DOPPLER256) >> 1)
#define RSDK_SPT_DOPPLER_256x128_4CH_3TXTDMIMO_OUT_BUF_SIZE          (RSDK_SPT_NUM_3TXTDMIMO_4CHANNELS * (RSDK_SPT_NP_RANGE256 >> 1) * RSDK_SPT_NP_DOPPLER128)
#define RSDK_SPT_DOPPLER_1024x64_4CH_4TXTDMIMO_CP4D_OUT_BUF_SIZE    ((RSDK_SPT_NUM_4TXTDMIMO_4CHANNELS * (RSDK_SPT_NP_RANGE1024 >> 1) * RSDK_SPT_NP_DOPPLER64)>>1)
#define RSDK_SPT_DOPPLER_1024x256_4CH_3TXDDMIMO_CP4D_OUT_BUF_SIZE   ((RSDK_SPT_NUM_3TXDDMIMO_4CHANNELS * (RSDK_SPT_NP_RANGE1024 >> 1) * (RSDK_SPT_NP_DOPPLER256 >> 2)) >> 1)
#define RSDK_SPT_DOPPLER_512x128_8CH_OUT_BUF_SIZE                    (RSDK_SPT_NUM_8CHANNELS * (RSDK_SPT_NP_RANGE512 >> 1) * RSDK_SPT_NP_DOPPLER128)
#define RSDK_SPT_DOPPLER_256x256_8CH_OUT_BUF_SIZE                    (RSDK_SPT_NUM_8CHANNELS * (RSDK_SPT_NP_RANGE256 >> 1) * RSDK_SPT_NP_DOPPLER256)
#define RSDK_SPT_DOPPLER_1024x128_8CH_CP4D_OUT_BUF_SIZE             ((RSDK_SPT_NUM_8CHANNELS * (RSDK_SPT_NP_RANGE1024 >> 1) * RSDK_SPT_NP_DOPPLER128) >> 1)
#define RSDK_SPT_DOPPLER_256x256_8CH_2TXTDMIMO_CP4D_OUT_BUF_SIZE    ((RSDK_SPT_NUM_2TXTDMIMO_8CHANNELS * (RSDK_SPT_NP_RANGE256 >> 1) * RSDK_SPT_NP_DOPPLER256) >> 1)
#define RSDK_SPT_DOPPLER_256x128_8CH_6TXTDMIMO_CP4D_OUT_BUF_SIZE    ((RSDK_SPT_NUM_6TXTDMIMO_8CHANNELS * (RSDK_SPT_NP_RANGE256 >> 1) * RSDK_SPT_NP_DOPPLER128) >> 1)

//@}

/**
* @brief          <br><br> <b>Size of Compensation factors buffer in uint16 values:</b>
* @details        Can be used by the upper layers at application level to allocate memory space for compensation factors list for Range adaptive scaling.
*                 Syntax include: < M>x<N>, M=number of samples and N=chirps.
*/
//@{
#define RSDK_SPT_CF_512x128_4CH_BUF_SIZE                            ((RSDK_SPT_NUM_4CHANNELS >> 1) * RSDK_SPT_NP_DOPPLER128)
#define RSDK_SPT_CF_256x256_4CH_BUF_SIZE                            ((RSDK_SPT_NUM_4CHANNELS >> 1) * RSDK_SPT_NP_DOPPLER256)
#define RSDK_SPT_CF_512x128_8CH_BUF_SIZE                            ((RSDK_SPT_NUM_8CHANNELS >> 1) * RSDK_SPT_NP_DOPPLER128)
#define RSDK_SPT_CF_256x256_8CH_BUF_SIZE                            ((RSDK_SPT_NUM_8CHANNELS >> 1) * RSDK_SPT_NP_DOPPLER256)
#define RSDK_SPT_CF_256x128_4CH_3TXTDMIMO_BUF_SIZE                  ((RSDK_SPT_NUM_4CHANNELS >> 1) * RSDK_SPT_NP_DOPPLER128 * RSDK_SPT_NUM_3TXTDMIMO_SLOTS)
//@}

/**
* @brief          <br><br> <b>Size of 3D FFT RDM buffer in uint16 values:</b>
* @details        Can be used by the upper layers at application level to allocate memory space for doppler fft result.
*                 Syntax include: < M>x<N>, M=number of samples and N=chirps.
*/
//@{
#define RSDK_SPT_3DFFT_512x128_RDM_BUF_SIZE                         (RSDK_SPT_NP_RANGE512 * RSDK_SPT_NP_DOPPLER128 >> 1)
#define RSDK_SPT_3DFFT_256x256_RDM_BUF_SIZE                         (RSDK_SPT_NP_RANGE256 * RSDK_SPT_NP_DOPPLER256 >> 1)
#define RSDK_SPT_3DFFT_256x128_RDM_BUF_SIZE                         (RSDK_SPT_NP_RANGE256 * RSDK_SPT_NP_DOPPLER128 >> 1)
#define RSDK_SPT_3DFFT_1024x128_RDM_BUF_SIZE                        (RSDK_SPT_NP_RANGE1024 * RSDK_SPT_NP_DOPPLER128 >> 1)
#define RSDK_SPT_3DFFT_1024x64_RDM_BUF_SIZE                         (RSDK_SPT_NP_RANGE1024 * RSDK_SPT_NP_DOPPLER64 >> 1)
#define RSDK_SPT_3DFFT_2048x256_RDM_BUF_SIZE                        (RSDK_SPT_NP_RANGE2048 * RSDK_SPT_NP_DOPPLER256 >> 1)

//@}

/**
* @brief          <br><br> <b>Size of Non Coherent Combining RDM buffer in uint16 values:</b>
* @details        Can be used by the upper layers at application level to allocate memory space for doppler fft result.
*                 Syntax include: < M>x<N>, M=number of samples and N=chirps.
*/
//@{
#define RSDK_SPT_NCC_512x128_RDM_BUF_SIZE                           (RSDK_SPT_NP_RANGE512 * RSDK_SPT_NP_DOPPLER128 >> 1)
#define RSDK_SPT_NCC_256x256_RDM_BUF_SIZE                           (RSDK_SPT_NP_RANGE256 * RSDK_SPT_NP_DOPPLER256 >> 1)
#define RSDK_SPT_NCC_256x128_RDM_BUF_SIZE                           (RSDK_SPT_NP_RANGE256 * RSDK_SPT_NP_DOPPLER128 >> 1)
#define RSDK_SPT_NCC_1024x64_RDM_BUF_SIZE                           (RSDK_SPT_NP_RANGE1024 * RSDK_SPT_NP_DOPPLER64 >> 1)
#define RSDK_SPT_NCC_1024x128_RDM_BUF_SIZE                          (RSDK_SPT_NP_RANGE1024 * RSDK_SPT_NP_DOPPLER128 >> 1)
#define RSDK_SPT_NCC_2048x256_RDM_BUF_SIZE                          (RSDK_SPT_NP_RANGE2048 * RSDK_SPT_NP_DOPPLER256 >> 1)

//@}

/**
* @brief          <br><br> <b>Size of Histogram output buffer in uint16 values:</b>
* @details        Can be used by the upper layers at application level to allocate memory space for histogram result.
*                 Syntax include: < M>x<N>, M=number of samples and N=chirps.
*/
//@{
#define RSDK_SPT_HIST_512x128_OUT_BUF_SIZE                          ((RSDK_SPT_NP_RANGE512 >> 1) * RSDK_SPT_HIST_BINS)
#define RSDK_SPT_HIST_256x256_OUT_BUF_SIZE                          ((RSDK_SPT_NP_RANGE256 >> 1) * RSDK_SPT_HIST_BINS)
#define RSDK_SPT_HIST_256x128_OUT_BUF_SIZE                          ((RSDK_SPT_NP_RANGE256 >> 1) * RSDK_SPT_HIST_BINS)
#define RSDK_SPT_HIST_1024x64_OUT_BUF_SIZE                          ((RSDK_SPT_NP_RANGE1024 >> 1) * RSDK_SPT_HIST_BINS)
#define RSDK_SPT_HIST_1024x128_OUT_BUF_SIZE                         ((RSDK_SPT_NP_RANGE1024 >> 1) * RSDK_SPT_HIST_BINS)
#define RSDK_SPT_HIST_2048x256_OUT_BUF_SIZE                         ((RSDK_SPT_NP_RANGE2048 >> 1) * RSDK_SPT_HIST_BINS)

//@}

/**
* @brief          <br><br> <b>Size of Threshold input buffer in uint16 values (16b log2 SPT type of values):</b>
* @details        Can be used by the upper layers at application level to allocate memory space for peak search thresholds fft result.
*                 Syntax include: < M>x<N>, M=number of samples and N=chirps.
*/
//@{
#define RSDK_SPT_THR_512x128_IN_BUF_SIZE                            (RSDK_SPT_NP_RANGE512 >> 1)
#define RSDK_SPT_THR_256x256_IN_BUF_SIZE                            (RSDK_SPT_NP_RANGE256 >> 1)
#define RSDK_SPT_THR_256x128_IN_BUF_SIZE                            (RSDK_SPT_NP_RANGE256 >> 1)
#define RSDK_SPT_THR_1024x128_IN_BUF_SIZE                           (RSDK_SPT_NP_RANGE1024 >> 1)
#define RSDK_SPT_THR_1024x64_IN_BUF_SIZE                            (RSDK_SPT_NP_RANGE1024 >> 1)
#define RSDK_SPT_THR_2048x256_IN_BUF_SIZE                           (RSDK_SPT_NP_RANGE2048 >> 1)

//@}

/**
* @brief          <br><br> <b>Size of PEAK SEARCH scratch buffer in uint32 values:</b>
* @details        Can be used by the upper layers at application level to allocate memory space for doppler fft result.
*                 Syntax include: < M>x<N>, M=number of samples and N=chirps.
*/
//@{
#define RSDK_SPT_PEAKSEARCH_512x128_SCRATCH_BUF_SIZE                ((RSDK_SPT_NP_RANGE512 >> 1) * RSDK_SPT_NP_DOPPLER128)
#define RSDK_SPT_PEAKSEARCH_256x256_SCRATCH_BUF_SIZE                ((RSDK_SPT_NP_RANGE256 >> 1) * RSDK_SPT_NP_DOPPLER256)
#define RSDK_SPT_PEAKSEARCH_256x128_SCRATCH_BUF_SIZE                ((RSDK_SPT_NP_RANGE256 >> 1) * RSDK_SPT_NP_DOPPLER128)
#define RSDK_SPT_PEAKSEARCH_1024x64_SCRATCH_BUF_SIZE                ((RSDK_SPT_NP_RANGE1024 >> 1) * RSDK_SPT_NP_DOPPLER64)
#define RSDK_SPT_PEAKSEARCH_1024x128_SCRATCH_BUF_SIZE               ((RSDK_SPT_NP_RANGE1024 >> 1) * RSDK_SPT_NP_DOPPLER128)
#define RSDK_SPT_PEAKSEARCH_2048x256_SCRATCH_BUF_SIZE               ((RSDK_SPT_NP_RANGE2048 >> 1) * RSDK_SPT_NP_DOPPLER256)

//@}

/**
* @brief          <br><br> <b>Size of PEAK SEARCH output buffer in uint8 values (packed bitfield):</b>
* @details        Can be used by the upper layers at application level to allocate memory space for doppler fft result.
*                 Syntax include: < M>x<N>, M=number of samples and N=chirps.
*/
//@{
#define RSDK_SPT_PEAKSEARCH_512x128_OUT_BUF_SIZE                    (((RSDK_SPT_NP_RANGE512 >> 1) * RSDK_SPT_NP_DOPPLER128) >> 3)
#define RSDK_SPT_PEAKSEARCH_256x256_OUT_BUF_SIZE                    (((RSDK_SPT_NP_RANGE256 >> 1) * RSDK_SPT_NP_DOPPLER256) >> 3)
#define RSDK_SPT_PEAKSEARCH_256x128_OUT_BUF_SIZE                    (((RSDK_SPT_NP_RANGE256 >> 1) * RSDK_SPT_NP_DOPPLER128) >> 3)
#define RSDK_SPT_PEAKSEARCH_1024x64_OUT_BUF_SIZE                    (((RSDK_SPT_NP_RANGE1024 >> 1) * RSDK_SPT_NP_DOPPLER64) >> 3)
#define RSDK_SPT_PEAKSEARCH_1024x128_OUT_BUF_SIZE                   (((RSDK_SPT_NP_RANGE1024 >> 1) * RSDK_SPT_NP_DOPPLER128) >> 3)
#define RSDK_SPT_PEAKSEARCH_2048x256_OUT_BUF_SIZE                   (((RSDK_SPT_NP_RANGE2048 >> 1) * RSDK_SPT_NP_DOPPLER256) >> 3)

//@}

/**
* @brief          <br><br> <b>Size of input buffer for DBF/DOA in uint32 values:</b>
* @details        Can be used by the upper layers, at application level, to allocate memory space.
*/
//@{
#define RSDK_SPT_DBFDOA64BEAMS4CH128PEAKS_IN_BUF_SIZE                (RSDK_SPT_DBFDOA_PEAKS_NUM * RSDK_SPT_NUM_4CHANNELS)
#define RSDK_SPT_DBFDOA64BEAMS4CH128PEAKS_CP4D_IN_BUF_SIZE          ((RSDK_SPT_DBFDOA_PEAKS_NUM * RSDK_SPT_NUM_4CHANNELS) >> 1)
#define RSDK_SPT_DBFDOA64BEAMS8CH128PEAKS_IN_BUF_SIZE                (RSDK_SPT_DBFDOA_PEAKS_NUM * RSDK_SPT_NUM_8CHANNELS)
#define RSDK_SPT_DBFDOA64BEAMS8CH128PEAKS_CP4D_IN_BUF_SIZE          ((RSDK_SPT_DBFDOA_PEAKS_NUM * RSDK_SPT_NUM_8CHANNELS) >> 1)
#define RSDK_SPT_DBFDOA64BEAMS12CH128PEAKS_IN_BUF_SIZE               (RSDK_SPT_DBFDOA_PEAKS_NUM * RSDK_SPT_NUM_3TXTDMIMO_4CHANNELS)
#define RSDK_SPT_DBFDOA64BEAMS12CH128PEAKS_CP4D_IN_BUF_SIZE         ((RSDK_SPT_DBFDOA_PEAKS_NUM * RSDK_SPT_NUM_3TXDDMIMO_4CHANNELS) >> 1)
#define RSDK_SPT_DBFDOA64BEAMS16CH128PEAKS_CP4D_IN_BUF_SIZE         ((RSDK_SPT_DBFDOA_PEAKS_NUM * RSDK_SPT_NUM_2TXTDMIMO_8CHANNELS) >> 1)
#define RSDK_SPT_DBFFFT128BINS12CH128PEAKS_CP4D_IN_BUF_SIZE         ((RSDK_SPT_DBFFFT_PEAKS_NUM * RSDK_SPT_NUM_3TXDDMIMO_4CHANNELS) >> 1)
#define RSDK_SPT_DBFFFT128BINS48CH128PEAKS_CP4D_IN_BUF_SIZE         ((RSDK_SPT_DBFFFT_PEAKS_NUM * RSDK_SPT_NUM_6TXTDMIMO_8CHANNELS) >> 1)
//@}

/**
* @brief          <br><br> <b>Size of ouput buffer for DBF/DOA in uint32 values (16b reserved for tagging and 16b log2 Magnitudes):</b>
* @details        Can be used by the upper layers, at application level, to allocate memory space.
*/
//@{
#define RSDK_SPT_DBFDOA64BEAMS4CH128PEAKS_OUT_BUF_SIZE              (RSDK_SPT_DBFDOA_PEAKS_NUM * RSDK_SPT_DBFDOA_BEAMS_NUM)
#define RSDK_SPT_DBFDOA64BEAMS4CH128PEAKS_CP4D_OUT_BUF_SIZE         (RSDK_SPT_DBFDOA_PEAKS_NUM * RSDK_SPT_DBFDOA_BEAMS_NUM)
#define RSDK_SPT_DBFDOA64BEAMS8CH128PEAKS_OUT_BUF_SIZE              (RSDK_SPT_DBFDOA_PEAKS_NUM * RSDK_SPT_DBFDOA_BEAMS_NUM)
#define RSDK_SPT_DBFDOA64BEAMS8CH128PEAKS_CP4D_OUT_BUF_SIZE         (RSDK_SPT_DBFDOA_PEAKS_NUM * RSDK_SPT_DBFDOA_BEAMS_NUM)
#define RSDK_SPT_DBFDOA64BEAMS12CH128PEAKS_OUT_BUF_SIZE             (RSDK_SPT_DBFDOA_PEAKS_NUM * RSDK_SPT_DBFDOA_BEAMS_NUM)
#define RSDK_SPT_DBFDOA64BEAMS12CH128PEAKS_CP4D_OUT_BUF_SIZE        (RSDK_SPT_DBFDOA_PEAKS_NUM * RSDK_SPT_DBFDOA_BEAMS_NUM)
#define RSDK_SPT_DBFDOA64BEAMS16CH128PEAKS_CP4D_OUT_BUF_SIZE        (RSDK_SPT_DBFDOA_PEAKS_NUM * RSDK_SPT_DBFDOA_BEAMS_NUM)
//@}

/**
* @brief          <br><br> <b>Size of ouput buffer for DBF with FFT in uint32 values :</b>
* @details        Can be used by the upper layers at application level to allocate memory space for DBF fft result.
*/
//@{
#define RSDK_SPT_DBFFFT128BINS12CH128PEAKS_OUT_BUF_SIZE             (RSDK_SPT_DBFFFT_PEAKS_NUM * RSDK_SPT_NP_DBF128)
#define RSDK_SPT_DBFFFT128BINS48CH128PEAKS_OUT_BUF_SIZE             (RSDK_SPT_DBFFFT_PEAKS_NUM * RSDK_SPT_NP_DBF128)
//@}

/**
* @brief          <br><br> <b>Size of derotation phase vector buffer in uint32 values:</b>
* @details        Can be used by the upper layers at application level to allocate memory space for 
*                 derotation phase vectors buffer.
*/
//@{
#define RSDK_SPT_2TXTDMIMO_DEROTPH_BUF_SIZE     ((RSDK_SPT_NUM_2TXTDMIMO_SLOTS - 1) * RSDK_SPT_NP_DOPPLER256)
#define RSDK_SPT_3TXTDMIMO_DEROTPH_BUF_SIZE     ((RSDK_SPT_NUM_3TXTDMIMO_SLOTS - 1) * RSDK_SPT_NP_DOPPLER128)
#define RSDK_SPT_4TXTDMIMO_DEROTPH_BUF_SIZE     ((RSDK_SPT_NUM_4TXTDMIMO_SLOTS - 1) * RSDK_SPT_NP_DOPPLER64)
#define RSDK_SPT_6TXTDMIMO_DEROTPH_BUF_SIZE     ((RSDK_SPT_NUM_6TXTDMIMO_SLOTS - 1) * RSDK_SPT_NP_DOPPLER256)
//@}

/**
* @brief          <br><br> <b>Size of steering vector buffer in uint32 values:</b>
* @details        Can be used by the upper layers at application level to allocate memory space for 
*                 steering vectors buffer.
*/
//@{
#define RSDK_SPT_DBF64_4CH_STEERVECT_BUF_SIZE   (RSDK_SPT_DBFDOA_BEAMS_NUM * RSDK_SPT_NUM_4CHANNELS)
#define RSDK_SPT_DBF64_8CH_STEERVECT_BUF_SIZE   (RSDK_SPT_DBFDOA_BEAMS_NUM * RSDK_SPT_NUM_8CHANNELS)
#define RSDK_SPT_DBF64_12CH_STEERVECT_BUF_SIZE  (RSDK_SPT_DBFDOA_BEAMS_NUM * RSDK_SPT_NUM_3TXTDMIMO_4CHANNELS)
#define RSDK_SPT_DBF64_16CH_STEERVECT_BUF_SIZE  (RSDK_SPT_DBFDOA_BEAMS_NUM * RSDK_SPT_NUM_2TXTDMIMO_8CHANNELS)
//@}

/**
* @brief          <br><br> <b>Size of data buffers reguired for RF-Bist:</b>
* @details        Can be used by the upper layers at application level to allocate memory space for 
*                 steering vectors buffer.
*/
//@{
#define RSDK_SPT_RFBIST_128x1_4CH_ADC_BUF_SIZE  (RSDK_SPT_NP_RFBIST128 * RSDK_SPT_NUM_4CHANNELS)         /**< @brief int16 value */
#define RSDK_SPT_RFBIST_128x1_4CH_FFT_BUF_SIZE  ((RSDK_SPT_NP_RFBIST128 >> 1) * RSDK_SPT_NUM_4CHANNELS)  /**< @brief uint32 value */
#define RSDK_SPT_RFBIST_128x1_4CH_MAG_BUF_SIZE  ((RSDK_SPT_NP_RFBIST128 >> 1) * RSDK_SPT_NUM_4CHANNELS)  /**< @brief uint16 value */
#define RSDK_SPT_RFBIST_2048x1_4CH_ADC_BUF_SIZE (RSDK_SPT_NP_RFBIST2048 * RSDK_SPT_NUM_4CHANNELS)        /**< @brief int16 value */
#define RSDK_SPT_RFBIST_2048x1_4CH_FFT_BUF_SIZE ((RSDK_SPT_NP_RFBIST2048 >> 1) * RSDK_SPT_NUM_4CHANNELS) /**< @brief uint32 value */
#define RSDK_SPT_RFBIST_2048x1_4CH_MAG_BUF_SIZE ((RSDK_SPT_NP_RFBIST2048 >> 1) * RSDK_SPT_NUM_4CHANNELS) /**< @brief uint16 value */
//@}

/**
* \addtogroup spt_kernels_api_data_type
* @{
*/
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

extern char RsdkSptInit512smp128crp4ch_size;                    /**< @brief Kernel size */
extern char RsdkSptInit256smp256crp4ch_size;                    /**< @brief Kernel size */
extern char RsdkSptInit1024smp64crp4ch_size;                    /**< @brief Kernel size */
extern char RsdkSptInit1024smp128crp4ch_size;                   /**< @brief Kernel size */
extern char RsdkSptInit2048smp256crp4ch_size;                   /**< @brief Kernel size */
extern char RsdkSptInit256smp256crp4ch2TxTdMimo_size;           /**< @brief Kernel size */
extern char RsdkSptInit256smp128crp4ch3TxTdMimo_size;           /**< @brief Kernel size */
extern char RsdkSptInit1024smp64crp4ch4TxTdMimo_size;           /**< @brief Kernel size */
extern char RsdkSptInit1024smp256crp4ch3TxDdMimo_size;          /**< @brief Kernel size */
extern char RsdkSptInit512smp128crp8ch_size;                    /**< @brief Kernel size */
extern char RsdkSptInit256smp256crp8ch_size;                    /**< @brief Kernel size */
extern char RsdkSptInit1024smp128crp8ch_size;                   /**< @brief Kernel size */
extern char RsdkSptInit256smp256crp8ch2TxTdMimo_size;           /**< @brief Kernel size */
extern char RsdkSptInit256smp128crp8ch6TxTdMimo_size;           /**< @brief Kernel size */

extern char RsdkSptRange512smp128crp4ch_size;                   /**< @brief Kernel size */
extern char RsdkSptRange512smp128crp4chAdptv_size;              /**< @brief Kernel size */
extern char RsdkSptRange256smp256crp4ch_size;                   /**< @brief Kernel size */
extern char RsdkSptRange256smp256crp4chAdptv_size;              /**< @brief Kernel size */
extern char RsdkSptRange1024smp64crp4chCp4d_size;               /**< @brief Kernel size */
extern char RsdkSptRange1024smp128crp4chCp4d_size;              /**< @brief Kernel size */
extern char RsdkSptRange2048smp256crp4chCp4d_size;              /**< @brief Kernel size */
extern char RsdkSptRange256smp256crp4ch2TxTdMimoCp4d_size;      /**< @brief Kernel size */
extern char RsdkSptRange256smp128crp4ch3TxTdMimo_size;          /**< @brief Kernel size */
extern char RsdkSptRange256smp128crp4ch3TxTdMimoAdptv_size;     /**< @brief Kernel size */
extern char RsdkSptRange1024smp64crp4ch4TxTdMimoCp4d_size;      /**< @brief Kernel size */
extern char RsdkSptRange1024smp256crp4ch3TxDdMimoCp4d_size;     /**< @brief Kernel size */
extern char RsdkSptRange512smp128crp8ch_size;                   /**< @brief Kernel size */
extern char RsdkSptRange512smp128crp8chAdptv_size;              /**< @brief Kernel size */
extern char RsdkSptRange256smp256crp8ch_size;                   /**< @brief Kernel size */
extern char RsdkSptRange256smp256crp8chAdptv_size;              /**< @brief Kernel size */
extern char RsdkSptRange1024smp128crp8chCp4d_size;              /**< @brief Kernel size */
extern char RsdkSptRange256smp256crp8ch2TxTdMimoCp4d_size;      /**< @brief Kernel size */
extern char RsdkSptRange256smp128crp8ch6TxTdMimoCp4d_size;      /**< @brief Kernel size */

extern char RsdkSptDoppler512smp128crp4ch_size;                 /**< @brief Kernel size */
extern char RsdkSptDoppler512smp128crp4chRcomp_size;            /**< @brief Kernel size */
extern char RsdkSptDoppler256smp256crp4ch_size;                 /**< @brief Kernel size */
extern char RsdkSptDoppler256smp256crp4chRcomp_size;            /**< @brief Kernel size */
extern char RsdkSptDoppler1024smp64crp4chCp4d_size;            /**< @brief Kernel size */
extern char RsdkSptDoppler1024smp128crp4chCp4d_size;            /**< @brief Kernel size */
extern char RsdkSptDoppler2048smp256crp4chCp4d_size;            /**< @brief Kernel size */
extern char RsdkSptDoppler256smp256crp4ch2TxTdMimoCp4d_size;    /**< @brief Kernel size */
extern char RsdkSptDoppler256smp128crp4ch3TxTdMimo_size;        /**< @brief Kernel size */
extern char RsdkSptDoppler256smp128crp4ch3TxTdMimoRcomp_size;   /**< @brief Kernel size */
extern char RsdkSptDoppler1024smp256crp4ch3TxDdMimoCp4d_size;   /**< @brief Kernel size */
extern char RsdkSptDoppler1024smp64crp4ch4TxTdMimoCp4d_size;	/**< @brief Kernel size */
extern char RsdkSptDoppler512smp128crp8ch_size;                 /**< @brief Kernel size */
extern char RsdkSptDoppler512smp128crp8chRcomp_size;            /**< @brief Kernel size */
extern char RsdkSptDoppler256smp256crp8ch_size;                 /**< @brief Kernel size */
extern char RsdkSptDoppler256smp256crp8chRcomp_size;            /**< @brief Kernel size */
extern char RsdkSptDoppler1024smp128crp8chCp4d_size;            /**< @brief Kernel size */
extern char RsdkSptDoppler256smp256crp8ch2TxTdMimoCp4d_size;    /**< @brief Kernel size */
extern char RsdkSptDoppler256smp128crp8ch6TxTdMimoCp4d_size;    /**< @brief Kernel size */

extern char RsdkSptNcc512smp128crp4ch_size;                     /**< @brief Kernel size */
extern char RsdkSptNcc256smp256crp4ch_size;                     /**< @brief Kernel size */
extern char RsdkSptNcc1024smp64crp4chCp4d_size;                 /**< @brief Kernel size */
extern char RsdkSptNcc1024smp128crp4chCp4d_size;                /**< @brief Kernel size */
extern char RsdkSptNcc2048smp256crp4chCp4d_size;                /**< @brief Kernel size */
extern char RsdkSptNcc256smp256crp4ch2TxTdMimoCp4d_size;        /**< @brief Kernel size */
extern char RsdkSptNcc256smp128crp4ch3TxTdMimo_size;            /**< @brief Kernel size */
extern char RsdkSptNcc1024smp64crp4ch4TxTdMimoCp4d_size;        /**< @brief Kernel size */
extern char RsdkSptNcc1024smp64crp4ch3TxDdMimoCp4d_size;        /**< @brief Kernel size */
extern char RsdkSptNcc512smp128crp8ch_size;                     /**< @brief Kernel size */
extern char RsdkSptNcc256smp256crp8ch_size;                     /**< @brief Kernel size */
extern char RsdkSptNcc1024smp128crp8chCp4d_size;                /**< @brief Kernel size */
extern char RsdkSptNcc256smp256crp8ch2TxTdMimoCp4d_size;        /**< @brief Kernel size */
extern char RsdkSptNcc256smp128crp8ch6TxTdMimoCp4d_size;        /**< @brief Kernel size */

extern char RsdkSpt3Dfft512smp128crp4ch_size;                   /**< @brief Kernel size */
extern char RsdkSpt3Dfft256smp256crp4ch_size;                   /**< @brief Kernel size */
extern char RsdkSpt3Dfft1024smp128crp4chCp4d_size;              /**< @brief Kernel size */
extern char RsdkSpt3Dfft1024smp64crp4chCp4d_size;               /**< @brief Kernel size */
extern char RsdkSpt3Dfft2048smp256crp4chCp4d_size;              /**< @brief Kernel size */
extern char RsdkSpt3Dfft256smp256crp4ch2TxTdMimoCp4d_size;      /**< @brief Kernel size */
extern char RsdkSpt3Dfft256smp128crp4ch3TxTdMimo_size;          /**< @brief Kernel size */
extern char RsdkSpt3Dfft1024smp64crp4ch4TxTdMimoCp4d_size;      /**< @brief Kernel size */
extern char RsdkSpt3Dfft512smp128crp8ch_size;                   /**< @brief Kernel size */
extern char RsdkSpt3Dfft256smp256crp8ch_size;                   /**< @brief Kernel size */
extern char RsdkSpt3Dfft1024smp128crp8chCp4d_size;              /**< @brief Kernel size */
extern char RsdkSpt3Dfft256smp256crp8ch2TxTdMimoCp4d_size;      /**< @brief Kernel size */
extern char RsdkSpt3Dfft256smp128crp8ch6TxTdMimoCp4d_size;      /**< @brief Kernel size */

extern char RsdkSptPeakSearch512smp128crp_size;                 /**< @brief Kernel size */
extern char RsdkSptPeakSearch256smp256crp_size;                 /**< @brief Kernel size */
extern char RsdkSptPeakSearch1024smp128crp_size;                /**< @brief Kernel size */
extern char RsdkSptPeakSearch256smp128crp_size;                 /**< @brief Kernel size */
extern char RsdkSptPeakSearch1024smp64crp_size;                 /**< @brief Kernel size */
extern char RsdkSptPeakSearch1024smp64crp1D_size;               /**< @brief Kernel size */
extern char RsdkSptPeakSearch2048smp256crp_size;                /**< @brief Kernel size */
extern char RsdkSptPeakSearch2048smp256crp1D_size;              /**< @brief Kernel size */


extern char RsdkSptDbfDoa64Beams4Ch128Peaks_size;               /**< @brief Kernel size */
extern char RsdkSptDbfDoa64Beams4Ch128PeaksCp4d_size;           /**< @brief Kernel size */
extern char RsdkSptDbfDoa64Beams8Ch128Peaks_size;               /**< @brief Kernel size */
extern char RsdkSptDbfDoa64Beams8Ch128PeaksCp4d_size;           /**< @brief Kernel size */
extern char RsdkSptDbfDoa64Beams12Ch128Peaks_size;              /**< @brief Kernel size */
extern char RsdkSptDbfDoa64Beams12Ch128PeaksCp4d_size;          /**< @brief Kernel size */
extern char RsdkSptDbfDoa64Beams16Ch128PeaksCp4d_size;          /**< @brief Kernel size */
extern char RsdkSptDbfFFT128Bins12Ch128PeaksCp4d_size;          /**< @brief Kernel size */
extern char RsdkSptDbfFFT128Bins48Ch128PeaksCp4d_size;          /**< @brief Kernel size */

extern char RsdkSptCheckTram512smp128crp4ch_size;               /**< @brief Kernel size */
extern char RsdkSptCheckTram256smp256crp4ch_size;               /**< @brief Kernel size */
extern char RsdkSptCheckTram1024smp128crp4ch_size;              /**< @brief Kernel size */
extern char RsdkSptCheckTram1024smp64crp4ch_size;               /**< @brief Kernel size */
extern char RsdkSptCheckTram2048smp256crp4ch_size;              /**< @brief Kernel size */
extern char RsdkSptCheckTram256smp256crp4ch2TxTdMimo_size;      /**< @brief Kernel size */
extern char RsdkSptCheckTram256smp128crp4ch3TxTdMimo_size;      /**< @brief Kernel size */
extern char RsdkSptCheckTram1024smp64crp4ch4TxTdMimo_size;      /**< @brief Kernel size */
extern char RsdkSptCheckTram1024smp256crp4ch3TxDdMimo_size;     /**< @brief Kernel size */
extern char RsdkSptCheckTram512smp128crp8ch_size;               /**< @brief Kernel size */
extern char RsdkSptCheckTram256smp256crp8ch_size;               /**< @brief Kernel size */
extern char RsdkSptCheckTram1024smp128crp8ch_size;              /**< @brief Kernel size */
extern char RsdkSptCheckTram256smp256crp8ch2TxTdMimo_size;      /**< @brief Kernel size */
extern char RsdkSptCheckTram256smp128crp8ch6TxTdMimo_size;      /**< @brief Kernel size */
extern char RsdkSptRfBist128smp1crp4ch_size;                    /**< @brief Kernel size */
extern char RsdkSptRfBist2048smp1crp4ch_size;                   /**< @brief Kernel size */

extern char RsdkSptMemRwErrInject_size;                         /**< @brief Kernel size */
extern char RsdkSptDspExampleDirectBlocking_size;               /**< @brief Kernel size */
extern char RsdkSptDspExampleIndirectBlocking_size;             /**< @brief Kernel size */
extern char RsdkSptOsCfar_size;            						/**< @brief Kernel size */

/** @} */

/**
* \addtogroup spt_kernels_api_func
* @{
*/
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

extern void *RsdkSptInit512smp128crp4ch(void);                  /* 512 samples, 128 chirps, 4 phy channels initialization function */
extern void *RsdkSptInit256smp256crp4ch(void);                  /* 256 samples, 256 chirps, 4 phy channels initialization function */
extern void *RsdkSptInit1024smp64crp4ch(void);                 /* 1024 samples, 64 chirps, 4 phy channels initialization function */
extern void *RsdkSptInit1024smp128crp4ch(void);                 /* 1024 samples, 128 chirps, 4 phy channels initialization function */
extern void *RsdkSptInit2048smp256crp4ch(void);                 /* 2048 samples, 256 chirps, 4 phy channels initialization function */
extern void *RsdkSptInit256smp256crp4ch2TxTdMimo(void);         /* 256 samples, 256 chirps, 2TX TD-MIMO, 4 phy channels initialization function */
extern void *RsdkSptInit256smp128crp4ch3TxTdMimo(void);         /* 256 samples, 128 chirps, 3TX TD-MIMO, 4 phy channels initialization function */
extern void *RsdkSptInit1024smp256crp4ch3TxDdMimo(void);        /* 1024 samples, 256 chirps, 3TX DD-Mimo, 4 phy channels, initialization function */
extern void *RsdkSptInit1024smp64crp4ch4TxTdMimo(void);         /* 1024 samples, 64 chirps, 4TX TD-MIMO, 4 phy channels initialization function */
extern void *RsdkSptInit512smp128crp8ch(void);                  /* 512 samples, 128 chirps, 8 phy channels initialization function */
extern void *RsdkSptInit256smp256crp8ch(void);                  /* 256 samples, 256 chirps, 8 phy channels initialization function */
extern void *RsdkSptInit1024smp128crp8ch(void);                 /* 1024 samples, 128 chirps, 8 phy channels initialization function */
extern void *RsdkSptInit256smp256crp8ch2TxTdMimo(void);         /* 256 samples, 256 chirps, 2TX TD-MIMO, 8 phy channels initialization function */
extern void *RsdkSptInit256smp128crp8ch6TxTdMimo(void);         /* 256 samples, 128 chirps, 6TX TD-MIMO, 8 phy channels initialization function */

extern void *RsdkSptRange512smp128crp4ch(void);                 /* Range FFT512, 4 phy channels, run-time function */
extern void *RsdkSptRange512smp128crp4chAdptv(void);            /* Range FFT512, 4 phy channels, Adaptive scaling, run-time function */
extern void *RsdkSptRange256smp256crp4ch(void);                 /* Range FFT256, 4 phy channels, run-time function */
extern void *RsdkSptRange256smp256crp4chAdptv(void);            /* Range FFT256, 4 phy channels, Adaptive scaling, run-time function */
extern void *RsdkSptRange1024smp64crp4chCp4d(void);             /* Range FFT1024, 4 phy channels, run-time function */
extern void *RsdkSptRange1024smp128crp4chCp4d(void);            /* Range FFT1024, 4 phy channels, run-time function */
extern void *RsdkSptRange2048smp256crp4chCp4d(void);            /* Range FFT2048, 4 phy channels, run-time function */
extern void *RsdkSptRange256smp256crp4ch2TxTdMimoCp4d(void);    /* Range FFT256, 2TX TD-MIMO, 4 phy channels, run-time function */
extern void *RsdkSptRange256smp128crp4ch3TxTdMimo(void);        /* Range FFT256, 3TX TD-MIMO, 4 phy channels, run-time function */
extern void *RsdkSptRange256smp128crp4ch3TxTdMimoAdptv(void);   /* Range FFT256, 3TX TD-MIMO, 4 phy channels, Adaptive scaling, run-time function */
extern void *RsdkSptRange1024smp256crp4ch3TxDdMimoCp4d(void);   /* Range FFT1024, 4 phy channels, 3TX DD-Mimo, run-time function */
extern void *RsdkSptRange1024smp64crp4ch4TxTdMimoCp4d(void);    /* Range FFT1024, 4 phy channels, 4TX TD-Mimo, run-time function */
extern void *RsdkSptRange512smp128crp8ch(void);                 /* Range FFT512, 8 phy channels, run-time function */
extern void *RsdkSptRange512smp128crp8chAdptv(void);            /* Range FFT512, 8 phy channels, Adaptive scaling, run-time function */
extern void *RsdkSptRange256smp256crp8ch(void);                 /* Range FFT256, 8 phy channels, run-time function */
extern void *RsdkSptRange256smp256crp8chAdptv(void);            /* Range FFT256, 8 phy channels, Adaptive scaling, run-time function */
extern void *RsdkSptRange1024smp128crp8chCp4d(void);            /* Range FFT1024, 8 phy channels, run-time function */
extern void *RsdkSptRange256smp256crp8ch2TxTdMimoCp4d(void);    /* Range FFT256, 2TX TD-MIMO, 8 phy channels, run-time function */
extern void *RsdkSptRange256smp128crp8ch6TxTdMimoCp4d(void);    /* Range FFT256, 6TX TD-MIMO, 8 phy channels, run-time function */

extern void *RsdkSptDoppler512smp128crp4ch(void);               /* Doppler FFT128, 4 phy channels, run-time function */
extern void *RsdkSptDoppler512smp128crp4chRcomp(void);          /* Doppler FFT128, 4 phy channels, incl Compensation for Range Adptv, run-time function */
extern void *RsdkSptDoppler256smp256crp4ch(void);               /* Doppler FFT256, 4 phy channels, run-time function */
extern void *RsdkSptDoppler256smp256crp4chRcomp(void);          /* Doppler FFT256, 4 phy channels, incl Compensation for Range Adptv, run-time function */
extern void *RsdkSptDoppler1024smp64crp4chCp4d(void);           /* Doppler FFT64, 4 phy channels, run-time function */
extern void *RsdkSptDoppler1024smp128crp4chCp4d(void);          /* Doppler FFT128, 4 phy channels, run-time function */
extern void *RsdkSptDoppler2048smp256crp4chCp4d(void);          /* Doppler FFT256, 4 phy channels, run-time function */
extern void *RsdkSptDoppler256smp256crp4ch2TxTdMimoCp4d(void);  /* Doppler FFT256, 2TX TD-MIMO, 4 phy channels, run-time function */
extern void *RsdkSptDoppler256smp128crp4ch3TxTdMimo(void);      /* Doppler FFT128, 3TX TD-MIMO, 4 phy channels, run-time function */
extern void *RsdkSptDoppler256smp128crp4ch3TxTdMimoRcomp(void); /* Doppler FFT128, 3TX TD-MIMO, incl Compensation for Range Adptv, run-time function */
extern void *RsdkSptDoppler1024smp256crp4ch3TxDdMimoCp4d(void); /* Doppler FFT256, 4 phy channels, 3TX DD-Mimo, run-time function */
extern void *RsdkSptDoppler1024smp64crp4ch4TxTdMimoCp4d(void);	/* Doppler FFT64,  4 phy channels, 4TX TD-Mimo, run-time function */
extern void *RsdkSptDoppler512smp128crp8ch(void);               /* Doppler FFT128, 8 phy channels, run-time function */
extern void *RsdkSptDoppler512smp128crp8chRcomp(void);          /* Doppler FFT128, 8 phy channels, incl Compensation for Range Adptv, run-time function */
extern void *RsdkSptDoppler256smp256crp8ch(void);               /* Doppler FFT256, 8 phy channels, run-time function */
extern void *RsdkSptDoppler256smp256crp8chRcomp(void);          /* Doppler FFT256, 8 phy channels, incl Compensation for Range Adptv, run-time function */
extern void *RsdkSptDoppler1024smp128crp8chCp4d(void);          /* Doppler FFT128, 8 phy channels, run-time function */
extern void *RsdkSptDoppler256smp256crp8ch2TxTdMimoCp4d(void);  /* Doppler FFT256, 2TX TD-MIMO, 8 phy channels, run-time function */
extern void *RsdkSptDoppler256smp128crp8ch6TxTdMimoCp4d(void);  /* Doppler FFT128, 6TX TD-MIMO, 8 phy channels, run-time function */

extern void *RsdkSptNcc512smp128crp4ch(void);                   /* Non Coherent Combining for Range 512 & Doppler 128, 4 phy channels */
extern void *RsdkSptNcc256smp256crp4ch(void);                   /* Non Coherent Combining for Range 256 & Doppler 256, 4 phy channels */
extern void *RsdkSptNcc1024smp64crp4chCp4d(void);               /* Non Coherent Combining for Range 1024 & Doppler 64, 4 phy channels */
extern void *RsdkSptNcc1024smp128crp4chCp4d(void);              /* Non Coherent Combining for Range 1024 & Doppler 128, 4 phy channels */
extern void *RsdkSptNcc2048smp256crp4chCp4d(void);              /* Non Coherent Combining for Range 2048 & Doppler 256, 4 phy channels */
extern void *RsdkSptNcc256smp256crp4ch2TxTdMimoCp4d(void);      /* Non Coherent Combining for 2TX TD-MIMO Range FFT256 & Doppler FFT256, 4 phy channels */
extern void *RsdkSptNcc256smp128crp4ch3TxTdMimo(void);          /* Non Coherent Combining for 3TX TD-MIMO Range FFT256 & Doppler FFT128, 4 phy channels */
extern void *RsdkSptNcc1024smp64crp4ch4TxTdMimoCp4d(void);      /* Non Coherent Combining for Range 1024 & Doppler  64, 4 phy channels, 4TX TD-Mimo */
extern void *RsdkSptNcc1024smp64crp4ch3TxDdMimoCp4d(void);      /* Non Coherent Combining for Range 1024 & Doppler 256, 4 phy channels, 3TX DD-Mimo */
extern void *RsdkSptNcc512smp128crp8ch(void);                   /* Non Coherent Combining for Range 512 & Doppler 128, 8 phy channels */
extern void *RsdkSptNcc256smp256crp8ch(void);                   /* Non Coherent Combining for Range 256 & Doppler 256, 8 phy channels */
extern void *RsdkSptNcc1024smp128crp8chCp4d(void);              /* Non Coherent Combining for Range 1024 & Doppler 128, 8 phy channels */
extern void *RsdkSptNcc256smp256crp8ch2TxTdMimoCp4d(void);      /* Non Coherent Combining for 2TX TD-MIMO Range FFT256 & Doppler FFT256, 8 phy channels */
extern void *RsdkSptNcc256smp128crp8ch6TxTdMimoCp4d(void);      /* Non Coherent Combining for 6TX TD-MIMO Range FFT256 & Doppler FFT128, 8 phy channels */

extern void *RsdkSpt3Dfft512smp128crp4ch(void);                 /* 3D FFT for Range 512 & Doppler 128, 4 phy channels */
extern void *RsdkSpt3Dfft256smp256crp4ch(void);                 /* 3D FFT for Range 256 & Doppler 256, 4 phy channels */
extern void *RsdkSpt3Dfft1024smp128crp4chCp4d(void);            /* 3D FFT for Range 1024 & Doppler 128, 4 phy channels */
extern void *RsdkSpt3Dfft1024smp64crp4chCp4d(void);             /* 3D FFT for Range 1024 & Doppler 64, 4 phy channels */
extern void *RsdkSpt3Dfft2048smp256crp4chCp4d(void);            /* 3D FFT for Range 2048 & Doppler 256, 4 phy channels */
extern void *RsdkSpt3Dfft256smp256crp4ch2TxTdMimoCp4d(void);    /* 3D FFT for 2TX TD-MIMO Range FFT256 & Doppler FFT256, 4 phy channels */
extern void *RsdkSpt3Dfft256smp128crp4ch3TxTdMimo(void);        /* 3D FFT for 3TX TD-MIMO Range FFT256 & Doppler FFT128, 4 phy channels */
extern void *RsdkSpt3Dfft1024smp64crp4ch4TxTdMimoCp4d(void);    /* 3D FFT for 4TX TD-MIMO Range FFT1024 & Doppler FFT64, 4 phy channels */
extern void *RsdkSpt3Dfft512smp128crp8ch(void);                 /* 3D FFT for Range 512 & Doppler 128, 8 phy channels */
extern void *RsdkSpt3Dfft256smp256crp8ch(void);                 /* 3D FFT for Range 256 & Doppler 256, 8 phy channels */
extern void *RsdkSpt3Dfft1024smp128crp8chCp4d(void);            /* 3D FFT for Range 1024 & Doppler 128, 8 phy channels */
extern void *RsdkSpt3Dfft256smp256crp8ch2TxTdMimoCp4d(void);    /* 3D FFT for 2TX TD-MIMO Range FFT256 & Doppler FFT256, 8 phy channels */
extern void *RsdkSpt3Dfft256smp128crp8ch6TxTdMimoCp4d(void);    /* 3D FFT for 6TX TD-MIMO Range FFT256 & Doppler FFT128, 8 phy channels */

extern void *RsdkSptPeakSearch512smp128crp(void);               /* Peak Search for Range 512 & Doppler 128 */
extern void *RsdkSptPeakSearch256smp256crp(void);               /* Peak Search for Range 256 & Doppler 256 */
extern void *RsdkSptPeakSearch1024smp128crp(void);              /* Peak Search for Range 1024 & Doppler 128 */
extern void *RsdkSptPeakSearch256smp128crp(void);               /* Peak Search for Range 256 & Doppler 128 */
extern void *RsdkSptPeakSearch1024smp64crp(void);               /* Peak Search for Range 1024 & Doppler 256 (64) DD-Mimo */
extern void *RsdkSptPeakSearch2048smp256crp(void);              /* Peak Search for Range 2048 & Doppler 256 */
extern void *RsdkSptPeakSearch2048smp256crp1D(void);            /* Peak Search 1D for Range 2048 & Doppler 256 */
extern void *RsdkSptPeakSearch1024smp64crp1D(void);             /* Peak Search 1D for Range 1024 & Doppler 64 */

extern void *RsdkSptDbfDoa64Beams4Ch128Peaks(void);             /* Digital Beamforming and Direction of Arrival, 64 beams, 128 peaks, 4 channels */
extern void *RsdkSptDbfDoa64Beams4Ch128PeaksCp4d(void);         /* Digital Beamforming and Direction of Arrival, 64 beams, 128 peaks, 4 channels, CP4D */
extern void *RsdkSptDbfDoa64Beams8Ch128Peaks(void);             /* Digital Beamforming and Direction of Arrival, 64 beams, 128 peaks, 8 channels */
extern void *RsdkSptDbfDoa64Beams8Ch128PeaksCp4d(void);         /* Digital Beamforming and Direction of Arrival, 64 beams, 128 peaks, 8 channels, CP4D */
extern void *RsdkSptDbfDoa64Beams12Ch128Peaks(void);            /* Digital Beamforming and Direction of Arrival, 64 beams, 128 peaks, 12 channels */
extern void *RsdkSptDbfDoa64Beams12Ch128PeaksCp4d(void);        /* Digital Beamforming and Direction of Arrival, 64 beams, 128 peaks, 12 channels, CP4D */
extern void *RsdkSptDbfDoa64Beams16Ch128PeaksCp4d(void);        /* Digital Beamforming and Direction of Arrival, 64 beams, 128 peaks, 16 channels, CP4D */
extern void *RsdkSptDbfFFT128Bins12Ch128PeaksCp4d(void);        /* Digital Beamforming, FFT128, 128 peaks, 12 channels, CP4D */
extern void *RsdkSptDbfFFT128Bins48Ch128PeaksCp4d(void);        /* Digital Beamforming, FFT128, 128 peaks, 48 channels, CP4D */

extern void *RsdkSptCheckTram512smp128crp4ch(void);             /* 512 samples, 128 chirps, 4 phy channels check persistent TRAM function */
extern void *RsdkSptCheckTram256smp256crp4ch(void);             /* 256 samples, 256 chirps, 4 phy channels check persistent TRAM function */
extern void *RsdkSptCheckTram1024smp128crp4ch(void);            /* 1024 samples, 128 chirps, 4 phy channels check persistent TRAM function */
extern void *RsdkSptCheckTram1024smp64crp4ch(void);             /* 1024 samples, 64 chirps, 4 phy channels check persistent TRAM function */
extern void *RsdkSptCheckTram2048smp256crp4ch(void);            /* 2048 samples, 256 chirps, 4 phy channels check persistent TRAM function */
extern void *RsdkSptCheckTram256smp256crp4ch2TxTdMimo(void);    /* 256 samples, 256 chirps, 2TX TD-MIMO, 4 phy channels check persistent TRAM function */
extern void *RsdkSptCheckTram256smp128crp4ch3TxTdMimo(void);    /* 256 samples, 128 chirps, 3TX TD-MIMO, 4 phy channels check persistent TRAM function */
extern void *RsdkSptCheckTram1024smp64crp4ch4TxTdMimo(void);    /* 1024 samples, 64 chirps, 4TX TD-MIMO, 4 phy channels check persistent TRAM function*/
extern void *RsdkSptCheckTram1024smp256crp4ch3TxDdMimo(void);   /* 1024 samples, 256 chirps, 2TX DD-MIMO, 4 phy channels, check persistent TRAM function */
extern void *RsdkSptCheckTram512smp128crp8ch(void);             /* 512 samples, 128 chirps, 8 phy channels check persistent TRAM function */
extern void *RsdkSptCheckTram256smp256crp8ch(void);             /* 256 samples, 256 chirps, 8 phy channels check persistent TRAM function */
extern void *RsdkSptCheckTram1024smp128crp8ch(void);            /* 1024 samples, 128 chirps, 8 phy channels check persistent TRAM function */
extern void *RsdkSptCheckTram256smp256crp8ch2TxTdMimo(void);    /* 256 samples, 256 chirps, 2TX TD-MIMO, 8 phy channels check persistent TRAM function */
extern void *RsdkSptCheckTram256smp128crp8ch6TxTdMimo(void);    /* 256 samples, 128 chirps, 6TX TD-MIMO, 8 phy channels check persistent TRAM function */

extern void *RsdkSptRfBist128smp1crp4ch(void);                  /* RF Bist  128 samples, 1 chirp, 4 phy channels. Offline version only */
extern void *RsdkSptRfBist2048smp1crp4ch(void);                 /* RF Bist 2048 samples, 1 chirp, 4 phy channels. Offline version only */

extern void *RsdkSptMemRwErrInject(void);                       /* Read-after-write on one OPRAM bank, to generate parity errors */
extern void *RsdkSptDspExampleDirectBlocking(void);             /* SPT kernel for calling a DSP function */
extern void *RsdkSptDspExampleIndirectBlocking(void);           /* SPT kernel for calling a DSP function */
extern void *RsdkSptOsCfar(void);             					/* SPT kernel for calling a DSP functione */

// clang-format on
/** @} */

#ifdef __cplusplus
}
#endif

#endif /* RSDK_SPT_KERNELS_S32R41_API_H */
