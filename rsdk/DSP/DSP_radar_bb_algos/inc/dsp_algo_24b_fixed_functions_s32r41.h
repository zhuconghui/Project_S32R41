/*
 * Copyright 2023-2024 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

#ifndef DSP_ALGO_FIXED_FUNCTIONS_S32R41_H
#define DSP_ALGO_FIXED_FUNCTIONS_S32R41_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/


#include <xtensa/tie/xt_FP.h>
#include <xtensa/tie/xt_bben.h>
#include <xtensa/tie/xt_misc.h>
#include <xtensa/tie/radar24.h>
#include <stdint.h>
#include "hw_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
/**
* @brief	 FFT 24bits complex
* @details   Performs FFT 128/256/512/1024/2048 on 24bits complex operands.
*            The twiddles are converted inside the FFT to q0.23.
*
* @param[in,out]  pInOut    - Result/operand contains 1 scalar complex vector(fft/input signal), size N / 16. \n
* @param[in,out]  pScratch1 - Scratch area for 1 scalar complex vector, size N / 16. \n
* @param[in,out]  pScratch2 - Scratch area for 1 scalar complex vector, size N / 16. \n
* @param[in]      pTwiddles - Operand contains twiddles, (q0.15) format, size 22/52/96/224/416 for fft size 128/256/512/1024/2048. \n
* @param[in]      pWindow   - Operand contains window coefficients, (q0.15) format, size 8/16/32/64/128 for fft size 128/256/512/1024/2048. \n
* @param[in]      shift     - Shift value. \n
* @param[in       size      - Size of the input signal(N), can be 128/256/512/1024/2048.
*
* @note The pInOut is a pointer to the output/input data which uses 2 int32_t for real and imaginary parts.
* <br> Even though the operations are performed on 24bits (re, imag) 32bits are used. The output is sign extended to 32 bits.
* <br> The shift value should be RSDK_BBE32_FFT_SHIFT_2 since a division by 4 is required before performing radix4 to prevent saturation.
* <br> The output signal should be scaled with shift_value^radix_stages (radix_stage is 4 for size 128/256, 5 for size 512/1024 and 6 for size 2048).
* <br> The window coefficients represent only half of the window, as the other half is mirrored.
* <br> For organizing the window coefficients to the right order, the following matlab code has been used:
* <br> N_factor = N / 128;
* <br> for  i = 1 : N_factor
* <br> 		index = (i - 1)  * 16 + 1;
* <br>  	WindowFinal = [WindowFinal; WindowCoeff(index:(index+7)); WindowCoeff((2 * N_factor * 16 + index):(2 * N_factor * 16 + index+7)); WindowCoeff((4 * N_factor * 16 + index):(4 * 16 * N_factor +index+7)); WindowCoeff((6 * 16 * N_factor + index):(6 * 16 * N_factor + index + 7))];
* <br>  	WindowFinal = [WindowFinal; WindowCoeff((index + 8):(index+15)); WindowCoeff((2 * N_factor * 16 + index + 8):(2 * N_factor * 16 + index+15)); WindowCoeff((4 * N_factor * 16 + index + 8):(4 * 16 * N_factor +index+15)); WindowCoeff((6 * 16 * N_factor + index + 8):(6 * 16 * N_factor + index + 15))];
* <br> end
* <br> N is the size of FFT(128/256/512/1024/2048) and WindowCoeff are the the coefficients resulted from a fft window function and WindowFinal is the re-organized window.
*/
void Rsdk_FftCplx(bbx_vecN_2xc24 * __restrict pInOut,
                  bbx_vecN_2xc24 * __restrict pScratch1,
                  bbx_vecN_2xc24 * __restrict pScratch2,
                      xb_vecNx16 * __restrict pTwiddles,
					   xb_vecNx16 *__restrict pWindow,
                                     uint16_t shift,
						             uint16_t size);
/**
* @brief	 Reorder 2 real signal on 16 bits into 1 complex signal on 24bits
* @details   Performs a reordering of 2 real signals on 16 bits with into 1 complex signal on 24 bits
*            The conversion from 16 bits to 24 bits is done by left shifting to the left with 8 (conversion from q0.15 to q0.23)
*
* @param[out]  pOut - Result/operand contains 1 scalar complex vector, size 2 * N / 16. \n
* @param[in]   pIn1 - Input containing 1 real vector, size N / 16. \n
* @param[in]   pIn2 - Input containing 1 real vector, size N / 16. \n
* @param[in    size - Size of the input signal(N), can be 128/256/512/1024/2048.
*
* @note Even though the operations are performed on 24bits (re, imag) 32bits are used. The output is sign extended to 32 bits.
*/
void Rsdk_Reord2RealToCplx(bbx_vecN_2xc24 * __restrict pOut,
		                       xb_vecNx16 * __restrict pIn1,
							   xb_vecNx16 * __restrict pIn2,
						                      uint16_t size);
/**
* @brief	 Split 1 complex combined fft  into 2 complex ffts on 24bits
* @details   Performs a splitting of an complex combined fft into 2 complex ffts on 24 bits
*
* @param[out]  pOut1 - Result/operand contains 1 complex vector, lower half of the fft of first signal, size  N / 16. \n
* @param[out]  pOut2 - Result/operand contains 1 complex vector, lower half of the fft of second signal, size  N / 16. \n
* @param[in]   pIn   - Input containing 1 complex vector, size 2 * N / 16. \n
* @param[in    size  - Size of the two real signal used for fft(N), can be 128/256/512/1024/2048.
*
* @note Even though the operations are performed on 24bits (re, imag) 32bits are used. The output is sign extended to 32 bits.
*/
void Rsdk_SplitFftCplxto2Cplx(bbx_vecN_2xc24 * __restrict pOut1,
		                      bbx_vecN_2xc24 * __restrict pOut2,
		                         bbx_vecNx24 * __restrict pIn,
							                     uint16_t size);
/**
* @brief	FFT 24bits 2 real inputs
* @details  Performs FFT on 24bits 2 real operands in 1 complex operand.
*           Returns the lower half of each Fft.
*           The twiddles are converted inside the FFT to q0.23.
*
* @param[out]  pOut1    - Result/operand contains 1 scalar complex vector(lower half of fft1), size N. \n
* @param[out]  pOut2    - Result/operand contains 1 scalar complex vector(lower half of fft2), size N. \n
* @param[in]   pIn1     - Result/operand contains 1 scalar real vector(input signal1), size N. \n
* @param[in]   pIn2     - Result/operand contains 1 scalar real vector(input signal2), size N. \n
* @param[in,out]  pScratch1  - Scratch area for 1 scalar complex vector, size N / 16. \n
* @param[in,out]  pScratch2  - Scratch area for 1 scalar complex vector, size N / 16. \n
* @param[in,out]  pScratch3  - Scratch area for 1 scalar complex vector, size (N + 16) / 16. \n
* @param[in]      pTwiddles  - Operand contains twiddles for the complex FFT operation, (q0.15) format. \n
*                              For FFT on 128 elements size is 22. \n
*                              For FFT on 256 elements size is 52. \n
*                              For FFT on 512 elements size is 96. \n
*                              For FFT on 1024 elements size is 224. \n
*                              For FFT on 2048 elements size is 416. \n
* @param[in]      pWindow    - Operand contains window coefficients, (q0.15) format, size 8/16/32/64/128 for fft size 128/256/512/1024/2048. \n
* @param[in]      size       - Size of the FFTs/input signals(N) . \n
* @param[in]      shift      - Shift value
*
* @pre The pOut1 an pOut2 are pointers to the two complex output that use int32_t. <br>Even though the operations are performed
* on 24bits (re, imag) 32bits are used. The outputs are complex data, sign extended to 32 bits.
* <br> The shift value should be RSDK_BBE32_FFT_SHIFT_2 since a division by 4 is required before performing radix4 to prevent saturation.
* <br> The available sizes are described in rsdkBbe32FftSize_t enum.
* <br>The output signals should be scaled with shift_value^radix_stages.
* <br> There are 4 stages for 128 and 256 input size buffers; 5 stages for 512 and 1024 input size; 6 stages for 2048 input size.
* <br> The window coefficients represent only half of the window, as the other half is mirrored.
* <br> For organizing the window coefficients to the right order, the following matlab code has been used:
* <br> N_factor = N / 128;
* <br> for  i = 1 : N_factor
* <br> 		index = (i - 1)  * 16 + 1;
* <br>  	WindowFinal = [WindowFinal; WindowCoeff(index:(index+7)); WindowCoeff((2 * N_factor * 16 + index):(2 * N_factor * 16 + index+7)); WindowCoeff((4 * N_factor * 16 + index):(4 * 16 * N_factor +index+7)); WindowCoeff((6 * 16 * N_factor + index):(6 * 16 * N_factor + index + 7))];
* <br>  	WindowFinal = [WindowFinal; WindowCoeff((index + 8):(index+15)); WindowCoeff((2 * N_factor * 16 + index + 8):(2 * N_factor * 16 + index+15)); WindowCoeff((4 * N_factor * 16 + index + 8):(4 * 16 * N_factor +index+15)); WindowCoeff((6 * 16 * N_factor + index + 8):(6 * 16 * N_factor + index + 15))];
* <br> end
* <br> N is the size of FFT(128/256/512/1024/2048) and WindowCoeff are the the coefficients resulted from a fft window function and WindowFinal is the re-organized window.
*/
void Rsdk_Fft2Real(bbx_vecNx24 * __restrict pOut1,
		           bbx_vecNx24 * __restrict pOut2,
		            xb_vecNx16 * __restrict pIn1,
	                xb_vecNx16 * __restrict pIn2,
                bbx_vecN_2xc24 * __restrict pScratch1,
                bbx_vecN_2xc24 * __restrict pScratch2,
                bbx_vecN_2xc24 * __restrict pScratch3,
                    xb_vecNx16 * __restrict pTwiddles,
                    xb_vecNx16 * __restrict pWindow,
                                   uint16_t size,
                                   uint16_t shift);


/**
* @brief	 Histogram 24 bits
* @details   Performs Histogram on 24 bits 2 real inputs (data and edges). \n
*            It sorts data into bins with bin edges specified in the edges vector.
*            The output values (expect the last two scalar values - int32_t) represent how many input values respect the following inequation: edge(i) <= in < edge(i + 1); i=0...M-1. \n
*            The second last scalar value(int32_t) represents how many input values respect the following inequation: edge(M-2) <= in <= edge(M-1).
*            The last scalar value(int32_t) is not useful data.
*
* @param[out]     pOut       - Result contains 1 scalar real vector, size M. \n
* @param[in]      pIn        - Operand contains 1 scalar real vector, size N. \n
* @param[in]      pEdges     - Operand contains 1 scalar real vector, size M. \n
* @param[in]      size       - Size of the input data(N). \n
* @param[in]      sizeEdges  - Size of the output data/edges (M).
*
* @pre Values of the edges(threshold values) must be stored in ascending order.
*/
void Rsdk_Hist(bbx_vecNx24 * pOut,
               bbx_vecNx24 * pIn,
               bbx_vecNx24 * pEdges,
                    uint16_t size,
                    uint16_t sizeEdges);
/**
* @brief	 Reorder input tile 16 data buffer on 16bits elements to an output buffer of 16bits real elements.
* @details   Reorder input tile 16 data buffer on 16bits elements(16 scalar elements from channel 1, 16 elem from ch2, 16 elem from ch3, 16 elem from ch4, 16 elem from ch1, 16 elem from ch2, 16 elem from ch3, 16 elem from ch4, ...)
*            to an output buffer containing concatenated data of each channel separated on 16bits real elements.
*
* @param[out]  pOut       - Buffer containing output data vector concatenated for all antennas
* @param[in]   pIn        - Input operand containg data from all 4 channels, real vector size N.
* @param[in]   size       - Size of input vector (N)
*
*/
void Rsdk_ReordTile16to4Ch(xb_vecNx16 * pOut,
	    	               xb_vecNx16 * pIn,
							    uint8_t doubleInBufEn,
		                       uint16_t size);
/**
* @brief	 DoA 128 24bits complex input
* @details   Performs DoA based on FFT128 on 24bits on complex operands.
*            The algorihm extends an input vector to 128 complex elements(fill with 0), applies the corresponding FFT and computes the mag2 => (real^2 + imag^2)/2. \n
*            Using these values, the maximum mag2 value is computed and multiplied with a threshold factor obtaining a threshold value. \n
*            This result is then compared with all the local maximum values(localMaxMag2 > threshold) of the mag2 for creating a bitmap. \n
*            A value mag2(i) is considered a local maximum value if (mag2(i) > mag2(i - 1) and mag2(i) >= mag2(i+1)). \n
*            The start and the end of the resulting mag2 vector are not considered.
*            The twiddles are converted inside the FFT used to q0.23 and compensated with 255 and -255 for values > 0 and < 0 respectively.
*            The output mag2 should be scaled with (shift value ^ 4 ) ^ 2 / 256.
*
*
* @param[out]     pOutputMag      - Result contains 1 scalar real vector. Size of useful data: 128 * M, size of the required allocated space: 128 * M * 2. \n
* @param[out]     pOutputBitmap   - Result contains 1 scalar real vector, size 128 * M / 16. \n
* @param[in]      pIn             - Operand contains 1 scalar complex vector, size N * M / 16. \n
* @param[in]      pTwiddles       - Operand contains twiddles, size 22, (q0.15) format. \n
* @param[in]      pWindow         - Operand contains window coefficients, (q0.15) format, size 8. \n
* @param[in]      thresholdFactor - Threshold factort that is multiplied with the global maximum magnitude value for comparison with the local maximum values.\n
*                                   The value represents a fixed-point value between [0,1] saved on 24 bits(q0.23).
* @param[in]      shift           - Shift value
* @param[in]      noAntennas      - Number of virtual antennas(N). \n
* @param[in]      noPeaks         - Number of input peaks (M).
*
*
* @pre The pOutMag an pIn are pointers to the real mag2 output and complex input data respectively, which use int32_t.
* <br> Even though the operations are performed on 24bits, 32bits are used for load/store. The outputs are sign extended to 32 bits.
* <br> The pDetectBitmap contains the resulting bitmap and is represented using uint16_t.
* <br> The shift value should be RSDK_BBE32_FFT_SHIFT_2 since a division by 4 is required before performing radix4 to prevent saturation.
* <br> The available sizes are described in rsdkBbe32FftSize_t enum.
* <br> The window coefficients represent only half of the window, as the other half is mirrored.
* <br> For organizing the window coefficients to the right order, the following matlab code has been used:
* <br> N_factor = N / 128;
* <br> for  i = 1 : N_factor
* <br> 		index = (i - 1)  * 16 + 1;
* <br>  	WindowFinal = [WindowFinal; WindowCoeff(index:(index+7)); WindowCoeff((2 * N_factor * 16 + index):(2 * N_factor * 16 + index+7)); WindowCoeff((4 * N_factor * 16 + index):(4 * 16 * N_factor +index+7)); WindowCoeff((6 * 16 * N_factor + index):(6 * 16 * N_factor + index + 7))];
* <br>  	WindowFinal = [WindowFinal; WindowCoeff((index + 8):(index+15)); WindowCoeff((2 * N_factor * 16 + index + 8):(2 * N_factor * 16 + index+15)); WindowCoeff((4 * N_factor * 16 + index + 8):(4 * 16 * N_factor +index+15)); WindowCoeff((6 * 16 * N_factor + index + 8):(6 * 16 * N_factor + index + 15))];
* <br> end
* <br> N is the size of FFT(128) and WindowCoeff are the the coefficients resulted from a fft window function and WindowFinal is the re-organized window.
*/
void Rsdk_Doa128(bbx_vecNx24 * __restrict pOutputMag,
                               uint16_t * pOutputBitmap,
                 bbx_vecNx24 * __restrict pInput,
              bbx_vecN_2xc24 * __restrict pScratch1,
              bbx_vecN_2xc24 * __restrict pScratch2,
		          xb_vecNx16 * __restrict pTwiddles,
		          xb_vecNx16 * __restrict pWindow,
                                 uint32_t thresholdFactor,
                                 uint16_t noAntennas,
                                 uint16_t shift,
                                 uint16_t noPeaks);

/**
* @brief	 DoA 256 24bits complex input
* @details   Performs DoA based on FFT256 on 24bits on complex operands.
*            The algorihm extends an input vector to 256 complex elements(fill with 0), applies the corresponding FFT and computes the mag2 => (real^2 + imag^2)/2. \n
*            Using these values, the maximum mag2 value is computed and multiplied with a threshold factor obtaining a threshold value. \n
*            This result is then compared with all the local maximum values of the mag2(localMaxMag2 > threshold) for creating a bitmap. \n
*            A value mag2(i) is considered a local maximum value if (mag2(i) > mag2(i - 1) and mag2(i) >= mag2(i+1)). \n
*            The start and the end of the resulting mag2 vector are not considered.
*            The twiddles are converted inside the FFT used to q0.23 and compensated with 255 and -255 for values > 0 and < 0 respectively.
*            The output mag2 should be scaled with (shift value ^ 4 ) ^ 2 / 256
*
* @param[out]     pOutputMag      - Result contains 1 scalar real vector. Size of useful data: 256 * M, size of the required allocated space: 256 * M * 2. \n
* @param[out]     pOutputBitmap   - Result contains 1 scalar real vector, size 256 * M / 16. \n
* @param[in]      pIn             - Operand contains 1 scalar complex vector, size N * M / 16. \n
* @param[in]      pTwiddles       - Operand contains twiddles, size 52, (q0.15) format. \n
* @param[in]      pWindow         - Operand contains window coefficients, (q0.15) format, size 16. \n
* @param[in]      thresholdFactor - Threshold factor that is multiplied with the global maximum magnitude value for comparison with the local maximum values.\n
*                                   The value represents a fixed-point value between [0,1] saved on 24 bits(q0.23).
* @param[in]      shift           - Shift value
* @param[in]      noAntennas      - Number of virtual antennas(N). \n
* @param[in]      noPeaks         - Number of input peaks (M).
*
*
* @pre The pOutMag an pIn are pointers to the real mag2 output and complex input data respectively, which use int32_t.
* <br> Even though the operations are performed on 24bits, 32bits are used for load/store. The outputs are sign extended to 32 bits.
* <br> The pDetectBitmap contains the resulting bitmap and is represented using uint16_t.
* <br> The shift value should be RSDK_BBE32_FFT_SHIFT_2 since a division by 4 is required before performing radix4 to prevent saturation.
* <br> The available sizes are described in rsdkBbe32FftSize_t enum.
* <br> The window coefficients represent only half of the window, as the other half is mirrored.
* <br> For organizing the window coefficients to the right order, the following matlab code has been used:
* <br> N_factor = N / 128;
* <br> for  i = 1 : N_factor
* <br> 		index = (i - 1)  * 16 + 1;
* <br>  	WindowFinal = [WindowFinal; WindowCoeff(index:(index+7)); WindowCoeff((2 * N_factor * 16 + index):(2 * N_factor * 16 + index+7)); WindowCoeff((4 * N_factor * 16 + index):(4 * 16 * N_factor +index+7)); WindowCoeff((6 * 16 * N_factor + index):(6 * 16 * N_factor + index + 7))];
* <br>  	WindowFinal = [WindowFinal; WindowCoeff((index + 8):(index+15)); WindowCoeff((2 * N_factor * 16 + index + 8):(2 * N_factor * 16 + index+15)); WindowCoeff((4 * N_factor * 16 + index + 8):(4 * 16 * N_factor +index+15)); WindowCoeff((6 * 16 * N_factor + index + 8):(6 * 16 * N_factor + index + 15))];
* <br> end
* <br> N is the size of FFT(256) and WindowCoeff are the the coefficients resulted from a fft window function and WindowFinal is the re-organized window.
*/
void Rsdk_Doa256(bbx_vecNx24 * __restrict pOutputMag,
                               uint16_t * pOutputBitmap,
                 bbx_vecNx24 * __restrict pInput,
              bbx_vecN_2xc24 * __restrict pScratch1,
              bbx_vecN_2xc24 * __restrict pScratch2,
	              xb_vecNx16 * __restrict pTwiddles,
	              xb_vecNx16 * __restrict pWindow,
                                 uint32_t thresholdFactor,
                                 uint16_t noAntennas,
                                 uint16_t shift,
                                 uint16_t noPeaks);

#ifdef __cplusplus
}
#endif

/*******************************************************************************
* EOF
******************************************************************************/


#endif /*DSP_ALGO_FIXED_FUNCTIONS_S32R41_H*/

