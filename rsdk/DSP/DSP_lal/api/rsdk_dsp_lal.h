/**************************************************************************************************
 * Copyright 2021-2024 NXP
 **************************************************************************************************
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 **************************************************************************************************/

#ifndef RSDK_DSP_LAL_H_
#define RSDK_DSP_LAL_H_

/**
* @file           rsdk_dsp_lal.h
* @brief          BBE Library low level functions API
* @details        These functions are the basic building blocks for the the BBE graphs.
*/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <alloca.h>
#include <complex.h>
#include <stdbool.h>

#include <xtensa/config/defs.h>
#include <xtensa/tie/xt_bben.h>
#include <xtensa/tie/xt_bbe32.h>
#include <xtensa/tie/radar24.h>

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
/** @addtogroup dsp_lal_api_func_add_vec
* @{
*/

/**
 * @brief          Add vectors - real single precision.
 * @details        Function implements add operation for 2 real data vectors. \n
 *                 Input and output can be in-place memory vectors.
 *
 * @param[out]     pOutput     Result contains 8 parallel real vectors, size N.
 * @param[in]      pInput1     First operand contains 8 parallel real vectors, size N.
 * @param[in]      pInput2     First operand contains 8 parallel real vectors, size N.
 * @param[in]      size        Size of input and output vectors, N.
 *
 *
 * @note           add(vector1,vector2) = vector \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..2730]
 */
void Rsdk_LA_add_Vof32p8Vif32p8Vif32p8(xb_vecN_2xf32 * pOutput,
                                       xb_vecN_2xf32 * pInput1,
                                       xb_vecN_2xf32 * pInput2,
                                              uint32_t size);

/**
 * @brief          Add vectors - real single precision.
 * @details        Function implements add operation for 2 real data vectors. \n
 *                 Output must not be in-place memory vector.
 *
 * @param[out]     pOutput     Result contains 8 parallel real vectors, size N.
 * @param[in]      pInput1     First operand contains 8 parallel real vectors, size N.
 * @param[in]      pInput2     First operand contains 8 parallel real vectors, size N.
 * @param[in]      size        Size of input and output vectors, N.
 *
 * @note           add(vector1,vector2) = vector \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..2730]
 */
void Rsdk_LA_add_Vof32p8Vif32p8Vif32p8_k2(xb_vecN_2xf32 * __restrict pOutput,
                                                     xb_vecN_2xf32 * pInput1,
                                                     xb_vecN_2xf32 * pInput2,
                                                            uint32_t size);

/**
 * @brief          Add vectors - complex single precision.
 * @details        Function implements add operation for 2 complex data vectors. \n
 *
 * @param[out]     pOutput     Result contains 8 parallel complex vectors, size N.
 * @param[in]      pInput1     First operand contains 8 parallel complex vectors, size N.
 * @param[in]      pInput2     First operand contains 8 parallel complex vectors, size N.
 * @param[in]      size        Size of input and output vectors, N.
 *
 * @note           add(vector1,vector2) = vector \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..1365]
 * 
 */

void Rsdk_LA_add_Vof32cp8Vif32cp8Vif32cp8(xb_vecN_2xcf32  * pOutput,
                                          xb_vecN_2xcf32  * pInput1,
                                          xb_vecN_2xcf32  * pInput2,
                                                   uint32_t size);
/**
 * @brief          Add vectors - complex single precision.
 * @details        Function implements add operation for 2 complex data vectors. \n
 *                 Output must not be in-place memory vector.
 *
 * @param[out]     pOutput     Result contains 8 parallel complex vectors, size N.
 * @param[in]      pInput1     First operand contains 8 parallel complex vectors, size N.
 * @param[in]      pInput2     First operand contains 8 parallel complex vectors, size N.
 * @param[in]      size        Size of input and output vectors, N.
 *
 * @note           add(vector1,vector2) = vector \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..1365]
 */
void Rsdk_LA_add_Vof32cp8Vif32cp8Vif32cp8_k2(xb_vecN_2xcf32  * __restrict pOutput,
                                                        xb_vecN_2xcf32  * pInput1,
                                                        xb_vecN_2xcf32  * pInput2,
                                                                 uint32_t size);
/** @} */

/** @addtogroup dsp_lal_api_func_sub_vec
* @{
*/

/**
 * @brief          Vector subtraction - real single precision.
 * @details        Function performs subtraction of 2 real data vectors. \n
 *
 * @param[out]     pOutput     Result contains 8 parallel real vectors, size N.
 * @param[in]      pInput1     First operand contains 8 parallel real vectors, size N.
 * @param[in]      pInput2     Second operand contains 8 parallel real vectors, size N.
 * @param[in]      size        Size of input and output vectors, N.
 *
 * @note           vector = vector1 - vector2 \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..2730] 
 */
void Rsdk_LA_sub_Vof32p8Vif32p8Vif32p8(xb_vecN_2xf32 * pOutput,
                                       xb_vecN_2xf32 * pInput1,
                                       xb_vecN_2xf32 * pInput2,
                                              uint32_t size);

/**
 * @brief          Vector subtraction - real single precision.
 * @details        Function performs subtraction of 2 real data vectors. \n
 *                 Output must not be in-place memory vector.
 *
 * @param[out]     pOutput     Result contains 8 parallel real vectors, size N.
 * @param[in]      pInput1     First operand contains 8 parallel real vectors, size N.
 * @param[in]      pInput2     Second operand contains 8 parallel real vectors, size N.
 * @param[in]      size        Size of input and output vectors, N.
 *
 * @note           vector = vector1 - vector2 \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..2730] 
 */
void Rsdk_LA_sub_Vof32p8Vif32p8Vif32p8_k2(xb_vecN_2xf32 * __restrict pOutput,
                                                     xb_vecN_2xf32 * pInput1,
                                                     xb_vecN_2xf32 * pInput2,
                                                            uint32_t size);

/**
 * @brief          Vector substraction - complex single precision.
 * @details        Function performs subtraction of 2 complex data vectors. \n
 *
 * @param[out]     pOutput     Result contains 8 parallel complex vectors, size N.
 * @param[in]      pInput1     First operand contains 8 parallel complex vectors, size N.
 * @param[in]      pInput2     Second operand contains 8 parallel complex vectors, size N.
 * @param[in]      size        Size of input and output vectors, N.
 *
 * @note           vector = vector1 - vector2 \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..1365] 
 */
void Rsdk_LA_sub_Vof32cp8Vif32cp8Vif32cp8(xb_vecN_2xcf32 * pOutput,
                                          xb_vecN_2xcf32 * pInput1,
                                          xb_vecN_2xcf32 * pInput2,
                                                  uint32_t size);

/**
 * @brief          Vector substraction - complex single precision.
 * @details        Function performs subtraction of 2 complex data vectors. \n
 *                 Output must not be in-place memory vector.
 *
 * @param[out]     pOutput     Result contains 8 parallel complex vectors, size N.
 * @param[in]      pInput1     First operand contains 8 parallel complex vectors, size N.
 * @param[in]      pInput2     Second operand contains 8 parallel complex vectors, size N.
 * @param[in]      size        Size of input and output vectors, N.
 *
 * @note           vector = vector1 - vector2 \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..1365] 
 */
void Rsdk_LA_sub_Vof32cp8Vif32cp8Vif32cp8_k2(xb_vecN_2xcf32 * __restrict pOutput,
                                                        xb_vecN_2xcf32 * pInput1,
                                                        xb_vecN_2xcf32 * pInput2,
                                                                uint32_t size);
/** @} */


/** @addtogroup dsp_lal_api_func_mul_vec_mat
* @{
*/

/**
 * @brief          Multiply vectors - real single precision.
 * @details        Function implements multiply operation for 2 real data vectors.  \n
 *
 * @param[out]     pOutput     Result contains 8 parallel real vectors, size N.
 * @param[in]      pInput1     First operand contains 8 parallel real vectors, size N.
 * @param[in]      pInput2     First operand contains 8 parallel real vectors, size N.
 * @param[in]      size        Size of input and output vectors, N.
 * 
 * @note           mul(vector1,vector2) = vector \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..2730] 
 */
void Rsdk_LA_mul_Vof32p8Vif32p8Vif32p8(xb_vecN_2xf32 * pOutput,
                                       xb_vecN_2xf32 * pInput1,
                                       xb_vecN_2xf32 * pInput2,
                                              uint32_t size);

/**
 * @brief          Multiply vectors - real single precision.
 * @details        Function implements multiply operation for 2 real data vectors. \n
 *                 Function only works for N modulo 4 = 0. \n
 *                 The implementation uses loop unrolling.  \n
 *                 Output must not be in-place memory vector. \n
 *
 * @param[out]     pOutput     Result contains 8 parallel real vectors, size N.
 * @param[in]      pInput1     First operand contains 8 parallel real vectors, size N.
 * @param[in]      pInput2     First operand contains 8 parallel real vectors, size N.
 * @param[in]      size        Size of input and output vectors, N.
 *
 * @note           mul(vector1,vector2) = vector \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..2730] 
 */
void Rsdk_LA_mul_Vof32p8Vif32p8Vif32p8_k2(xb_vecN_2xf32 * __restrict pOutput,
                                                     xb_vecN_2xf32 * pInput1,
                                                     xb_vecN_2xf32 * pInput2,
                                                            uint32_t size);

/**
 * @brief          Multiply vectors - complex single precision.
 * @details        Function implements multiply operation for 2 complex data vectors.  \n
 *
 * @param[out]     pOutput     Result contains 8 parallel complex vectors, size N.
 * @param[in]      pInput1     First operand contains 8 parallel complex vectors, size N.
 * @param[in]      pInput2     First operand contains 8 parallel complex vectors, size N.
 * @param[in]      size        Size of input and output vectors, N.
 *
 * @note           mul(vector1,vector2) = vector \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..1365] 
 */
void Rsdk_LA_mul_Vof32cp8Vif32cp8Vif32cp8(xb_vecN_2xcf32 * pOutput,
                                         xb_vecN_2xcf32  * pInput1,
                                         xb_vecN_2xcf32  * pInput2,
                                                  uint32_t size);

/**
 * @brief          Multiply vectors - complex single precision.
 * @details        Function implements multiply operation for 2 complex data vectors. \n
 *                 Function only works for N modulo 4 = 0. \n
 *                 The implementation uses loop unrolling. \n
 *                 Output must not be in-place memory vector. \n
 *
 * @param[out]     pOutput     Result contains 8 parallel complex vectors, size N.
 * @param[in]      pInput1     First operand contains 8 parallel complex vectors, size N.
 * @param[in]      pInput2     First operand contains 8 parallel complex vectors, size N.
 * @param[in]      size        Size of input and output vectors, N.
 *
 * @note           mul(vector1,vector2) = vector \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..1365] 
 */
void Rsdk_LA_mul_Vof32cp8Vif32cp8Vif32cp8_k2(xb_vecN_2xcf32 * __restrict pOutput,
                                                       xb_vecN_2xcf32  * pInput1,
                                                       xb_vecN_2xcf32  * pInput2,
                                                                uint32_t size);

/**
 * @brief          Multiply matrices - real single precision.
 * @details        Function implements multiply operation for 2 real data matrices.  \n
 *                 Output must not be in-place memory. \n
 *
 * @param[out]     pOutput     Result contains 8 parallel real matrices, size NxQ.
 * @param[in]      pInput1     First operand contains 8 parallel real matrices, size NxM.
 * @param[in]      pInput2     First operand contains 8 parallel real matrices, size MxQ.
 * @param[in]      in1h        Rows of input matrix pInput1 and rows of output matrix pOutput, N.
 * @param[in]      in1w        Columns of input matrix pInput2 and rows of input matrix pInput2, M.
 * @param[in]      in2w        Columns of output matrix, Q.
 *
 * @note           mul(matrix1,matrix2) = matrix \n
 *                 The following sizes are estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 in1h        range is [2..N] \n
 *                 in1w        range is [2..M] \n
 *                 in2w        range is [2..Q] \n
 *                 (N * Q + N * M + M * Q) <= 8191
 */
void Rsdk_LA_mul_Mof32p8Mif32p8Mif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                                  xb_vecN_2xf32 * pInput1,
                                                  xb_vecN_2xf32 * pInput2,
                                                         uint32_t in1h,
                                                         uint32_t in1w,
                                                         uint32_t in2w);

/**
 * @brief          Multiply matrices - complex single precision.
 * @details        Function implements multiply operation for 2 complex data matrices.  \n
 *                 Output must not be in-place memory. \n
 *
 * @param[out]     pOutput     Result contains 8 parallel complex matrices, size NxQ.
 * @param[in]      pInput1     First operand contains 8 parallel complex matrices, size NxM.
 * @param[in]      pInput2     First operand contains 8 parallel complex matrices, size MxQ.
 * @param[in]      in1h        Rows of input matrix pInput1 and rows of output matrix pOutput, N.
 * @param[in]      in1w        Columns of input matrix pInput1 and rows of input matrix pInput2, M.
 * @param[in]      in2w        Columns of output matrix, Q.
 *
 * @note           mul(matrix1,matrix2) = matrix \n
 *                 The following sizes are estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 in1h        range is [2..N] \n
 *                 in1w        range is [2..M] \n
 *                 in2w        range is [2..Q] \n
 *                 (N * Q + N * M + M * Q) <= 4095
 */
void Rsdk_LA_mul_Mof32cp8Mif32cp8Mif32cp8(xb_vecN_2xcf32 * __restrict pOutput,
                                                    xb_vecN_2xcf32  * pInput1,
                                                    xb_vecN_2xcf32  * pInput2,
                                                             uint32_t in1h,
                                                             uint32_t in1w,
                                                             uint32_t in2w);

/**
 * @brief          Multiply 8 parallel streams of NxM matrices by transposed of 8 parallel streams
 *                 of NxQ matrices - real single precision.
 * @details        All matrices from second input parallel stream are transposed, then each matrix \n
 *                 from first input parallel stream is multiplied by corresponding matrix in second parallel stream. \n
 *                 Streams are independent. \n
 *                 Output can be in-place memory.                    \n
 *
 * @param[out]     pOutput     Result contains 8 parallel real matrices, size NxQ.
 * @param[in]      pInput1     First operand contains 8 parallel real matrices, size NxM.
 * @param[in]      pInput2     Second operand contains 8 parallel real matrices, size QxM.
 * @param[in]      in1h        Rows of the input matrix pInput1 and rows of the output matrix pOutput, N.
 * @param[in]      in1w        Columns of the input matrix pInput1 and columns of the transposed input matrix pInput2, M.
 * @param[in]      in2w        Columns of the output matrix and rows of the transposed input matrix pInput2, Q.
 *
 * @note           mul(matrix1,matrix2 ^ T) = matrix \n
 *                 The following sizes are estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 in1h        range is [2..N] \n
 *                 in1w        range is [2..M] \n
 *                 in2w        range is [2..Q] \n
 *                 (N * Q + N * M + M * Q) <= 8191 
 */
void Rsdk_LA_mulSecondT_Mof32p8Mif32p8Mif32p8(xb_vecN_2xf32 * pOutput,
                                              xb_vecN_2xf32 * pInput1,
                                              xb_vecN_2xf32 * pInput2,
                                                     uint32_t in1h,
                                                     uint32_t in1w,
                                                     uint32_t in2w);

/**
 * @brief          Multiply 8 parallel streams of NxM matrices by the transposed of the complex conjugate
 *                 of 8 parallel streams of NxQ matrices - complex single precision.
 * @details        All matrices from second input parallel stream are transposed and complex conjugate, \n
 *                 then each matrix from first input parallel stream is multiplied by corresponding matrix in second parallel stream. \n
 *                 Streams are independent. \n
 *                 Output can be in-place memory.                    \n
 *
 * @param[out]     pOutput     Result contains 8 parallel complex matrices, size NxQ.
 * @param[in]      pInput1     First operand contains 8 parallel complex matrices, size NxM.
 * @param[in]      pInput2     Second operand contains 8 parallel complex matrices, size QxM.
 * @param[in]      in1h        Rows of the input matrix pInput1 and rows of the output matrix pOutput, N.
 * @param[in]      in1w        Columns of the input matrix pInput1 and columns of the transposed input matrix pInput2, M.
 * @param[in]      in2w        Columns of the output matrix and rows of the transposed input matrix pInput2, Q.
 *
 * @note           mul(matrix1,conj(matrix2^T)) = matrix \n
 *                 The following sizes are estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 in1h        range is [2..N] \n
 *                 in1w        range is [2..M] \n
 *                 in2w        range is [2..Q] \n
 *                 (N * Q + N * M + M * Q) <= 4095 
 */
void Rsdk_LA_mulSecondH_Mof32cp8Mif32cp8Mif32cp8(xb_vecN_2xcf32 * pOutput,
                                                xb_vecN_2xcf32  * pInput1,
                                                xb_vecN_2xcf32  * pInput2,
                                                         uint32_t in1h,
                                                         uint32_t in1w,
                                                         uint32_t in2w);
/** @} */

/** @addtogroup dsp_lal_api_func_div_vec
* @{
*/

/**
 * @brief          Vector division - real single precision.
 * @details        Function performs division of 2 real data vectors. \n
 *
 * @param[out]     pOutput     Result contains 8 parallel real vectors, size N.
 * @param[in]      pInput1     First operand contains 8 parallel real vectors, size N.
 * @param[in]      pInput2     Second operand contains 8 parallel real vectors, size N.
 * @param[in]      size        Size of input and output vectors, N.
 *
 * @note           div(vector1, vector2) = vector1 ./ vector2 \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..2730] 
 */
void Rsdk_LA_div_Vof32p8Vif32p8Vif32p8(xb_vecN_2xf32 * pOutput,
                                       xb_vecN_2xf32 * pInput1,
                                       xb_vecN_2xf32 * pInput2,
                                              uint32_t size);

/**
 * @brief          Vector division - real single precision. The fastest version.
 * @details        Function performs division of 2 real data vectors. \n
 *
 * @param[out]     pOutput     Result contains 8 parallel real vectors, size N.
 * @param[in]      pInput1     First operand contains 8 parallel real vectors, size N.
 * @param[in]      pInput2     Second operand contains 8 parallel real vectors, size N.
 * @param[in]      size        Size of input and output vectors, N.
 *
 * @note           div(vector1, vector2) = vector1 * rcp(vector2) \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..2730] 
 */
void Rsdk_LA_div_Vof32p8Vif32p8Vif32p8_k2(xb_vecN_2xf32 * pOutput,
                                          xb_vecN_2xf32 * pInput1,
                                          xb_vecN_2xf32 * pInput2,
                                                 uint32_t size);

/**
 * @brief          Vector division - complex single precision.
 * @details        Function performs division of 2 complex data vectors. \n
 *
 * @param[out]     pOutput     Result contains 8 parallel complex vectors, size N.
 * @param[in]      pInput1     First operand contains 8 parallel complex vectors, size N.
 * @param[in]      pInput2     Second operand contains 8 parallel complex vectors, size N.
 * @param[in]      size        Size of input and output vectors, N.
 *
 * @note           div(vector1, vector2) = vector1 ./ vector2 \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..1365] 
 */
void Rsdk_LA_div_Vof32cp8Vif32cp8Vif32cp8(xb_vecN_2xcf32 * pOutput,
                                          xb_vecN_2xcf32 * pInput1,
                                          xb_vecN_2xcf32 * pInput2,
                                                  uint32_t size);
/** @} */

/** @addtogroup dsp_lal_api_func_xcorr_vec
* @{
*/

/**
 * @brief          Cross correlation on vectors - real single precision.
 * @details        Function implements cross correlation  operation for 2 real data vectors.  \n
 *
 * @param[out]     pOutput     Result contains 8 parallel real vectors, size 2*max(M,N)-1.
 * @param[in]      pInput1     First operand contains 8 parallel real vectors, size N.
 * @param[in]      pInput2     First operand contains 8 parallel real vectors, size M.
 * @param[in]      size1       Size of input and output vectors, N.
 * @param[in]      size2       Size of input and output vectors, M.
 *
 * @note           xcorr(vector1,vector2) = vector \n
 *                 The following sizes /are estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size1        range is [1..N] \n
 *                 size2        range is [1..M] \n
 *                 (N + M + 2 * max(M,N)) < 8192
 */
void Rsdk_LA_xcorr_Vof32p8Vif32p8Vif32p8(xb_vecN_2xf32 * restrict pOutput,
                                                  xb_vecN_2xf32 * pInput1,
                                                  xb_vecN_2xf32 * pInput2,
                                                         uint32_t size1,
                                                         uint32_t size2);

/**
 * @brief          Cross correlation on vectors - complex single precision.
 * @details        Function implements cross correlation  operation 2 complex data vectors.  \n
 *
 * @param[out]     pOutput     Result contains 8 parallel complex vectors, size 2*max(M,N)-1.
 * @param[in]      pInput1     First operand contains 8 parallel complex vectors, size N.
 * @param[in]      pInput2     First operand contains 8 parallel complex vectors, size M.
 * @param[in]      size1       Size of input and output vectors, N.
 * @param[in]      size2       Size of input and output vectors, M.
 *
 * @note           xcorr(vector1,vector2) = vector \n
 *                 The following sizes are estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size1        range is [1..N] \n
 *                 size2        range is [1..M] \n
 *                 (N + M + 2 * max(M,N)) < 4096 
 */
void Rsdk_LA_xcorr_Vof32cp8Vif32cp8Vif32cp8(xb_vecN_2xcf32  * restrict pOutput,
                                                     xb_vecN_2xcf32  * pInput1,
                                                     xb_vecN_2xcf32  * pInput2,
                                                              uint32_t size1,
                                                              uint32_t size2);

/** @} */

/** @addtogroup dsp_lal_api_func_op_vec_mat
* @{
*/

/**
 * @brief          Modulo - real single precision.
 * @details        Function implements the modulo operation between 2 real data vectors.  \n
 *                 Output must not be in-place memory vector.
 *
 * @param[out]     pOutput     Result contains 8 parallel real vectors, size N.
 * @param[in]      pInput1     First operand contains 8 parallel real vectors, size N.
 * @param[in]      pInput2     First operand contains 8 parallel real vectors, size N.
 * @param[in]      size        Size of input and output vectors, N.
 *
 *
 * @note           mod(vector1,vector2) = vector \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..2730] 
 */
void Rsdk_EF_mod_Vof32p8Vif32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                                  xb_vecN_2xf32 * pInput1,
                                                  xb_vecN_2xf32 * pInput2,
                                                         uint32_t size);

/**
 * @brief          Root square - real single precision.
 * @details        Function calculates the square root of a real data vectors.  \n
 *                 The square root of the absolute input value is computed. \n
 *                 Output must not be in-place memory vector.
 *
 * @param[out]     pOutput     Result contains 8 parallel real vectors, size N.
 * @param[in]      pInput      Operand contains 8 parallel real vectors, size N.
 * @param[in]      size        Size of input and output vectors, N.
 *
 * @note           sqrt(abs(vector)) = vector \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..4095]
 */
void Rsdk_EF_sqrtAbs_Vof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                               xb_vecN_2xf32 * pInput,
                                                      uint32_t size);

/**
 * @brief          Root square - real single precision.
 * @details        Function calculates the square root of a real data vectors. \n
 *                 Values must be real positives. \n
 *                 Output must not be in-place memory vector.
 *
 * @param[out]     pOutput     Result contains 8 parallel real vectors, size N.
 * @param[in]      pInput      Operand contains 8 parallel real vectors, size N.
 * @param[in]      size        Size of input and output vectors, N.
 *
 * @note           sqrt(vector) = vector \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..4095]
 */
void Rsdk_EF_sqrt_Vof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                            xb_vecN_2xf32 * pInput,
                                                   uint32_t size);

/**
 * @brief          Root square - complex single precision.
 * @details        Function calculates the square root of a complex data vectors.  \n
 *                 Output must not be in-place memory vector.
 *
 * @param[out]     pOutput     Result contains 8 parallel complex vectors, size N.
 * @param[in]      pInput      Operand contains 8 parallel complex vectors, size N.
 * @param[in]      size        Size of input and output vectors, N.
 *
 * @note           csqrt (vector) = vector \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..2047]
 */
void Rsdk_EF_sqrt_Vof32cp8Vif32cp8(xb_vecN_2xcf32 * __restrict pOutput,
                                              xb_vecN_2xcf32 * pInput,
                                                      uint32_t size);

/**
 * @brief          Hypotenuse - real single precision.
 * @details        Function implements the hypotenuse operation between 2 real data vectors. \n
 *                 Output must not be in-place memory vector.
 *
 * @param[out]     pOutput     Result contains 8 parallel real vectors, size N.
 * @param[in]      pInput1     First operand contains 8 parallel real vectors, size N.
 * @param[in]      pInput2     First operand contains 8 parallel real vectors, size N.
 * @param[in]      size        Size of input and output vectors, N.
 *
 *
 * @note           hypotenuse(vector1,vector2) = sqrt(a*a + b*b) = vector \n
 *                 If one of the input is +/-INF and the other one is NaN,
 *                 the output is +INF (IEEE-754 compliant)
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..2730]
 */
void Rsdk_LA_hypot_Vof32p8Vif32p8Vif32p8(xb_vecN_2xf32 * restrict pOutput,
                                                  xb_vecN_2xf32 * pInput1,
                                                  xb_vecN_2xf32 * pInput2,
                                                         uint32_t size);

/**
 * @brief          Reciprocal - real single precision.
 * @details        Function calculates the reciprocal of a real data vectors.  \n
 *                 Input and output must not be in-place memory vectors.
 *
 * @param[out]     pOutput     Result contains 8 parallel real vectors, size N.
 * @param[in]      pInput      Operand contains 8 parallel real vectors, size N.
 * @param[in]      size        Size of input and output vectors, N.
 *
 * @note           rcp(vector) = 1./vector \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..4095]
 */
void Rsdk_LA_rcp_Vof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                           xb_vecN_2xf32 * pInput,
                                                  uint32_t size);

/**
 * @brief          Recipcrocal - complex single precision.
 * @details        Function calculates the reciprocal of a complex data vectors.  \n
 *                 Output must not be in-place memory vector. \n
 *
 * @param[out]     pOutput     Result contains 8 parallel complex vectors, size N.
 * @param[in]      pInput      Operand contains 8 parallel complex vectors, size N.
 * @param[in]      size        Size of input and output vectors, N.
 *
 * @note           rcp (vector) = 1./vector \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..2047]
 */
void Rsdk_LA_rcp_Vof32cp8Vif32cp8(xb_vecN_2xcf32 * __restrict pOutput,
                                             xb_vecN_2xcf32 * pInput,
                                                     uint32_t size);
/**
 * @brief          Threshold using a real vector to a complex vector \n
 *                 absolute values - complex single precision.
 * @details        Function performs the threshold of the magnitude of the complex input vector \n
 *                 against the square of the threshold vector. \n
 *                 Each element of the output vector is either 0 (input element < threshold^2 ) \n
 *                 or 1 (input element >= threshold^2). \n
 *                 Output must not be in-place memory vector.
 *
 * @param[out]     pOutput     Result contains 8 parallel real vectors, size N.
 * @param[in]      pInput1     Operand contains 8 parallel complex vectors, size N.
 * @param[in]      pInput2     Operand contains 8 parallel threshold real vectors, size 1.
 * @param[in]      size        Size of the input and output vectors, N.
 *
 * @note           absThrsh(vector, vector) = vector \n
 *                 v1 = a1, a2, ... aN \n
 *                 v2 = b1, b2, ... bN \n
 *                 absThrsh(v1, v2) = (|a1|^2 >= b1^2), (|a2|^2 >= b2^2), ... (|aN|^2 >= bN^2), \n
 *                 where |aN| is the magnitude of the complex number aN, computed as \n
 *                 sqrt(real(aN)^2 + imag(aN)^2) \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..2730]
 */
void Rsdk_LA_threshAbs_Vof32p8Vif32cp8Vif32p8(xb_vecN_2xf32 * __restrict  pOutput,
                                                   xb_vecN_2xcf32 const * pInput1,
                                                    xb_vecN_2xf32 const * pInput2,
                                                                 uint32_t size);

/**
 * @brief          Threshold using a real scalar to a complex vector \n
 *                 absolute values - complex single precision.
 * @details        Function performs the threshold of the magnitude of the complex input vector \n
 *                 against the square of the scalar threshold. \n
 *                 Each element of the output vector is either 0 (input element < threshold^2 ) \n
 *                 or 1 (input element >= threshold^2). \n
 *                 One threshold is used for all 8 parallel streams. \n
 *                 Output must not be in-place memory vector.
 *
 * @param[out]     pOutput     Result contains 8 parallel real vectors, size N.
 * @param[in]      pInput1     Operand contains 8 parallel complex vectors, size N.
 * @param[in]      pInput2     Operand contains a pointer to the real scalar threshold.
 * @param[in]      size        Size of the input and output vectors, N.
 *
 * @note           absThrsh(vector, scalar) = vector \n
 *                 v = a1, a2, ... aN \n
 *                 s = thr \n
 *                 absThrsh(v, s) = (|a1|^2 >= thr^2), (|a2|^2 >= thr^2), ... (|aN|^2 >= thr^2),
 *                 where |aN| is the magnitude of the complex number aN, computed as \n
 *                 sqrt(real(aN)^2 + imag(aN)^2) \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..2730]
 */
void Rsdk_LA_threshAbs_Vof32p8Vif32cp8Sif32(xb_vecN_2xf32 * __restrict  pOutput,
                                                 xb_vecN_2xcf32 const * pInput1,
                                                      float32_t const * pInput2,
                                                               uint32_t size);

/**
 * @brief          Threshold using a real threshold vector to a real vector \n
 *                 values - real single precision.
 * @details        Function perform the threshold of the real input vector \n
 *                 against the real threshold vector. \n
 *                 Each element of the output vector is either 0 (input element < threshold ) \n
 *                 or 1 (input element >= threshold). \n
 *                 Output must not be in-place memory vector.
 *
 * @param[out]     pOutput     Result contains 8 parallel real vectors, size N.
 * @param[in]      pInput1     Operand contains 8 parallel real vectors, size N.
 * @param[in]      pInput2     Operand contains 8 parallel threshold real vectors, size 1.
 * @param[in]      size        Size of the input and output vectors, N.
 *
 * @note           thresh(vector, vector) = vector \n
 *                 v1 = a1, a2, ... aN \n
 *                 v2 = b1, b2, ... bN \n
 *                 thresh(v1, v2) = (a1 >= b1), (a2 >= b2), ... (an >= bN) \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..4095]
 */
void Rsdk_LA_thresh_Vof32p8Vif32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                               xb_vecN_2xf32 const * pInput1,
                                               xb_vecN_2xf32 const * pInput2,
                                                            uint32_t size);

/**
 * @brief          Threshold using a real scalar to a real vector \n
 *                 values - real single precision.
 * @details        Function perform the threshold of the real input vector \n
 *                 against the real scalar threshold. \n
 *                 Each element of the output vector is either 0 (input element < threshold ) \n
 *                 or 1 (input element >= threshold). \n
 *                 One threshold is used for all 8 parallel streams. \n
 *                 Output must not be in-place memory vector.
 *
 * @param[out]     pOutput     Result contains 8 parallel real vectors, size N.
 * @param[in]      pInput1     Operand contains 8 parallel real vectors, size N.
 * @param[in]      pInput2     Operand contains a pointer to the real scalar threshold.
 * @param[in]      size        Size of the input and output vectors, N.
 *
 * @note           thresh(vector, scalar) = vector \n
 *                 v = a1, a2, ... aN \n
 *                 s = thr \n
 *                 absThrsh(v, s) = (a1 >= thr), (a2 >= thr), ... (an >= thr) \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..4095]
 */
void Rsdk_LA_thresh_Vof32p8Vif32p8Sif32(xb_vecN_2xf32 * __restrict pOutput,
                                             xb_vecN_2xf32 const * pInput1,
                                                 float32_t const * pInput2,
                                                          uint32_t size);

/**
 * @brief          Exponential - real single precision.
 * @details        Function calculates the exponential of a real data vectors.  \n
 *                 The exponential values are computed based on the identity e^x = 2^y, where y = (x / ln(2)), \n
 *                 which can be expanded to e^x = 2^(int)y * 2^(fractional)y. \n
 *                 2^y will be aproximated using Taylor series, implemented using Horner's method to reduce the number of operations. \n
 *                 The Taylor series approximation is expanded around the value 0.5f. \n
 *                 For input values < 8.5f, the function produces an approximation error < 1e-3. \n
 *                 For input values > 8.5f, the approximation error increases constantly with the increasing of the input values. \n
 *                 Output must not be in-place memory vector. \n
 *
 * @param[out]     pOutput     Result contains 8 parallel real vectors, representing the exponential values, size N.
 * @param[in]      pInput      Operand contains 8 parallel real vectors, size N.
 * @param[in]      size        Size of input and output vectors, N.
 *
 * @note           exp (vector) = vector \n
 *                 v = (a1, a2, ..., an);  \n
 *                 exp (v) = (e^a1, e^a2, ..., e^an); \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..4095]
 */
void Rsdk_EF_exp_Vof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                           xb_vecN_2xf32 * pInput,
                                                  uint32_t size);

/** @} */

/** @addtogroup dsp_lal_api_func_fill
* @{
*/

/**
 * @brief          Fill with zero vectors - real single precision.
 * @details        Function fills vectors with zeros. \n
 *
 * @param[out]     pOutput     Result contains 8 parallel real vectors, size N.
 * @param[in]      size        Size of output vectors, N.
 *
 * @note           fillZeros() = vector \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..8191]
 */
void Rsdk_EF_fillZeros_Vof32p8(xb_vecN_2xf32 * pOutput,
                                      uint32_t size);

/**
 * @brief          Fill with zero vectors - complex single precision.
 * @details        Function fills vectors with zeros. \n
 *
 * @param[out]     pOutput     Result contains 8 parallel complex vectors, size N.
 * @param[in]      size        Size of output vectors, N.
 *
 * @note           fillZeros() = vector \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..4095]
 */
void Rsdk_EF_fillZeros_Vof32cp8(xb_vecN_2xcf32 * pOutput,
                                        uint32_t size);

/**
 * @brief          Fill 8 streams of vectors, size N, with one value - real single precision.
 * @details        Set all elements of vectors with a real scalar.
 *
 * @param[out]     pOutput     Result contains 8 parallel real vectors size N.
 * @param[in]      pInput      Operand is a real scalar.
 * @param[in]      size        Number of vector elements(N).
 *
 * @note           The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..8191]
 */
void Rsdk_EF_fill_Vof32p8Sif32(xb_vecN_2xf32 * pOutput,
                             float32_t const * pInput,
                                      uint32_t size);

/**
 * @brief          Fill 8 streams of vectors, size N, with one value - complex single precision.
 * @details        Set all elements of the vectors with a complex scalar.
 *
 * @param[out]     pOutput     Result contains 8 parallel complex vectors size N.
 * @param[in]      pInput      Operand is a complex scalar.
 * @param[in]      size        Number of vector elements(N).
 *
 * @note           The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..4095]
 */
void Rsdk_EF_fill_Vof32cp8Sif32c(xb_vecN_2xcf32 * pOutput,
                           xtcomplexfloat const * pInput,
                                         uint32_t size);

/**
 * @brief          Fill 8 streams of vectors, size N, with one value - real single precision.
 * @details        Set all elements of vectors with a real scalar.
 *
 * @param[out]     pOutput     Result contains 8 parallel real vectors size N.
 * @param[in]      pInput      Operand contains 8 real scalars.
 * @param[in]      size        Number of vector elements(N).
 *
 * @note           The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..8190]
 *
 */
void Rsdk_EF_fill_Vof32p8Sif32p8(xb_vecN_2xf32 * pOutput,
                           xb_vecN_2xf32 const * pInput,
                                        uint32_t size);

/**
 * @brief          Fill 8 streams of vectors, size N, with one value - complex single precision.
 * @details        Set all elements of the vectors with a complex scalar.
 *
 * @param[out]     pOutput     Result contains 8 parallel complex vectors size N.
 * @param[in]      pInput      Operand contains 8 complex scalars.
 * @param[in]      size        Number of vector elements(N).
 *
 * @note           The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..4094]
 */
void Rsdk_EF_fill_Vof32cp8Sif32cp8(xb_vecN_2xcf32 * pOutput,
                             xb_vecN_2xcf32 const * pInput,
                                           uint32_t size);

/**
 * @brief          Fill 8 parallel identical vectors with FFT radix 2 stage twiddle factors
 *                 - complex single precision.
 * @details        Result contains 8 parallel identical complex vectors, size 2 to power of S,
 *                 containing roots of unity often called FFT twiddle factors corresponding to
 *                 a particular stage. Implemented algorithm is from the book Approximations
 *                 for Digital Computers, Cecil Hastings, p140.
 *
 * @param[out]     pOutput     Result contains 8 parallel complex vectors size 2^S.
 * @param[in]      stage       Stage number (S).
 *
 * @note           fill twiddle = vector \n
 *                 N = 2^S \n
 *                 fill twiddle() = 8, cos(-2*pi*    0*1/N), sin(-2*pi*    0*1/N), ... ; \n
 *                                  8, cos(-2*pi*    1*1/N), sin(-2*pi*    1*1/N), ... ; \n
 *                                  8, .........................................., ... ; \n
 *                                  8, cos(-2*pi*(N-1)*1/N), sin(-2*pi*(N-1)*1/N), ... ; \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 stage       range is [2..11]
 */
void Rsdk_SP_fillStgRadix2_Vof32cp8(xb_vecN_2xcf32 * pOutput,
                                            uint32_t stage);

/**
 * @brief          Fill with zero matrices - real single precision.
 * @details        Function fills matrices with zeros. \n
 *
 * @param[out]     pOutput     Result contains 8 parallel real matrices, size NxM.
 * @param[in]      rows        Rows of output matrices, N.
 * @param[in]      cols        Columns of output matrices, M.
 *
 * @note           fillZeros() = matrix \n
 *                 The following sizes are estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 rows       range is [1..N] \n
 *                 cols       range is [1..M] \n
 *                 (N * M) < 8192
 */
void Rsdk_EF_fillZeros_Mof32p8(xb_vecN_2xf32 * pOutput,
                                      uint32_t rows,
                                      uint32_t cols);

/**
 * @brief          Fill with zero matrices - complex single precision.
 * @details        Function fills matrices with zeros. \n
 *
 * @param[out]     pOutput     Result contains 8 parallel complex matrices, size NxM.
 * @param[in]      rows        Rows of output matrices, N.
 * @param[in]      cols        Columns of output matrices, M.
 *
 * @note           fillZeros() = matrix \n
 *                 The following sizes are estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 rows       range is [1..N] \n
 *                 cols       range is [1..M] \n
 *                 (N * M) < 4096
 */
void Rsdk_EF_fillZeros_Mof32cp8(xb_vecN_2xcf32 * pOutput,
                                        uint32_t rows,
                                        uint32_t cols);

/**
 * @brief          Fill 8 streams of NxN matrix with 0 and the diagonal elements to a scalar
 *                 - real single precision.
 * @details        Set diagonals' elements to a scalar and the rest of the matrices' elements
 *                 to 0.\n
 *
 * @param[out]     pOutput     Result contains 8 parallel real square matrices, size NxN.
 * @param[in]      pInput      Operand contains 8 real scalars.
 * @param[in]      size        Size of output matrices(N, rows, cols).
 *
 * @note           fillZerosDg() = matrix \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [2..90]
 */
void Rsdk_EF_fillZerosDg_Mof32p8Sif32p8(xb_vecN_2xf32 * pOutput,
                                  xb_vecN_2xf32 const * pInput,
                                               uint32_t size);

/**
 * @brief          Fill 8 streams of NxN matrix with 0 and the diagonal with a vector of
 *                 values - real single precision.
 * @details        Set diagonals' elements to the vector and the rest of matrices' elements
 *                 to 0.\n
 *
 * @param[out]     pOutput     Result contains 8 parallel real square matrices, size NxN.
 * @param[in]      pInput      Operand contains 8 parallel real vectors, size N.
 * @param[in]      size        Size of output matrices(N, rows, cols).
 *
 * @note           fillZeros() = matrix \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [2..90]
 */
void Rsdk_EF_fillZerosDg_Mof32p8Vif32p8(xb_vecN_2xf32 * pOutput,
                                  xb_vecN_2xf32 const * pInput,
                                               uint32_t size);

/**
 * @brief          Fill 8 streams of NxN matrix with (0,0i) and the diagonal elements to a
 *                 scalar - complex single precision.
 * @details        Set diagonals' elements to a scalar and the rest of the matrices' elements
 *                 to (0,0i).\n
 *
 * @param[out]     pOutput     Result contains 8 parallel complex square matrices, size NxN.
 * @param[in]      pInput      Operand contains 8 complex scalars.
 * @param[in]      size        Size of output matrix(N, rows, cols).
 *
 * @note           fillZeros() = matrix \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [2..63]
 */
void Rsdk_EF_fillZerosDg_Mof32cp8Sif32cp8(xb_vecN_2xcf32 * pOutput,
                                    xb_vecN_2xcf32 const * pInput,
                                                  uint32_t size);

/**
 * @brief          Fill 8 streams of NxN matrix with (0,0i) and the diagonal with a vector
 *                 of values - complex single precision.
 * @details        Set diagonals' elements to the vector and the rest of matrices' elements
 *                 to (0,0i).\n
 *
 * @param[out]     pOutput     Result contains 8 parallel complex square matrices, size NxN.
 * @param[in]      pInput      Operand contains 8 parallel complex vectors, size N.
 * @param[in]      size        Size of output matrices(N, rows, cols).
 *
 * @note           fillZeros() = matrix \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [2..63]
 */
void Rsdk_EF_fillZerosDg_Mof32cp8Vif32cp8(xb_vecN_2xcf32 * pOutput,
                                    xb_vecN_2xcf32 const * pInput,
                                                  uint32_t size);

/**
 * @brief          Identity matrices - real single precision.
 * @details        Function creates identity matrices. \n
 *
 * @param[out]     pOutput     Result contains 8 parallel real matrices, size NxN.
 * @param[in]      size        Number of rows and columns in the output matrices, N.
 *
 * @note           identity() = matrix \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [2..90]
 */
void Rsdk_EF_identity_Mof32p8(xb_vecN_2xf32 * pOutput,
                                     uint32_t size);

/**
 * @brief          Identity matrices - complex single precision.
 * @details        Function creates identity matrices. \n
 *
 * @param[out]     pOutput     Result contains 8 parallel complex matrices, size NxN.
 * @param[in]      size        Number of rows and columns in the output matrices.
 *
 * @note           identity() = matrix \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [2..63]
 */
void Rsdk_EF_identity_Mof32cp8(xb_vecN_2xcf32 * pOutput,
                                       uint32_t size);

/** @} */


/** @addtogroup dsp_lal_api_func_trig_vec
* @{
*/

/**
 * @brief          Element-wise convert angle in radians to degrees
 * @details        Element-wise convert angle in radians degrees by multiplying
 *                 each element of a real single precision vector with pre-calculated
 *                 constant 180.0 / PI                                          \n
 *                 angleInRadians = (angleInDegrees) * 180.0 / PI
 *
 * @param[out]     pOutput     Result contains 8 parallel real vectors, size N.
 * @param[in]      pInput      Operand contains 8 parallel real vectors, size N.
 * @param[in]      size        Size of input and output vectors, N.
 *
 * @note           The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..4095]
 */
void Rsdk_LA_rad2deg_Vof32p8Vif32p8(xb_vecN_2xf32 * pOutput,
                                    xb_vecN_2xf32 * pInput,
                                           uint32_t size);

/**
 * @brief          Element-wise convert angle in degrees to radians
 * @details        Element-wise convert angle in degrees to radians by multiplying
 *                 each element of a real single precision vector with pre-calculated
 *                 constant PI / 180.0                                       \n
 *                 angleInRadians = (angleInDegrees) * PI / 180.0
 *
 * @param[out]     pOutput     Result contains 8 parallel real vectors, size N.
 * @param[in]      pInput      Operand contains 8 parallel real vectors, size N.
 * @param[in]      size        Size of input and output vectors, N.
 *
 * @note           The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..4095]
 */
void Rsdk_LA_deg2rad_Vof32p8Vif32p8(xb_vecN_2xf32 * pOutput,
                                    xb_vecN_2xf32 * pInput,
                                           uint32_t size);

/**
 * @brief          Arcsine - real single precision,  high accuracy.
 * @details        Function calculates the inverse sinus of a real data vectors. \n
 *                 It returns arcsin(x) in domain [-pi/2,pi/2] for x in domain [-1,1]. \n
 *                 Implemented algorithm from Approximations for Digital Computers, Cecil Hastings, p163.  \n
 *                 Output must not be in-place memory vector. \n
 *
 * @param[out]     pOutput     Result contains 8 parallel real vectors, size N.
 * @param[in]      pInput      Operand contains 8 parallel real vectors, size N.
 * @param[in]      size        Size of input and output vectors, N.
 *
 * @note           asin(vector) = vector \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..4095]
 */
void Rsdk_EF_asin_Vof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                            xb_vecN_2xf32 * pInput,
                                                   uint32_t size);

/**
 * @brief          Arccosine - real single precision,  high accuracy.
 * @details        Function calculates the inverse cosine of a real data vectors. \n
 *                 It returns arccos(x) in domain [0,pi] for x in domain [-1,1]. \n
 *                 Computed using formula acos(x) = pi/2 - asin(x).  \n
 *                 Output must not be in-place memory vector. \n
 *
 * @param[out]     pOutput     Result contains 8 parallel real vectors, size N.
 * @param[in]      pInput      Operand contains 8 parallel real vectors, size N.
 * @param[in]      size        Size of input and output vectors, N.
 *
 * @note           acos(vector) = vector \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..4095]
 */
void Rsdk_EF_acos_Vof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                            xb_vecN_2xf32 * pInput,
                                                   uint32_t size);

/**
 * @brief          Sine - real single precision,  high accuracy.
 * @details        Function calculates the sinus of a real data vector. \n
 *                 It returns sin(x) in domain [-1,1] for x in domain [-pi,pi]. \n
 *                 Implemented algorithm from Approximations for Digital Computers, Cecil Hastings, p140. \n
 *                 Output must not be in-place memory vector. \n
 *
 * @param[out]     pOutput     Result contains 8 parallel real vectors, size N.
 * @param[in]      pInput      Operand contains 8 parallel real vectors, size N.
 * @param[in]      size        Size of input and output vectors, N.
 *
 * @note           sin(vector) = vector \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..4095]
 */
void Rsdk_EF_sin_Vof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                           xb_vecN_2xf32 * pInput,
                                                  uint32_t size);

/**
 * @brief          Cosine - real single precision,  high accuracy.
 * @details        Function calculates the cosine of a real data vectors. \n
 *                 It returns cos(x) in domain [-1,1] for x in domain [-pi,pi]. \n
 *                 Computed using formula cos(x) = sin(x + pi/2). \n
 *                 Output must not be in-place memory vector. \n
 *
 * @param[out]     pOutput     Result contains 8 parallel real vectors, size N.
 * @param[in]      pInput      Operand contains 8 parallel real vectors, size N.
 * @param[in]      size        Size of input and output vectors, N.
 *
 * @note           cos(vector) = vector \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..4095]
 */
void Rsdk_EF_cos_Vof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                           xb_vecN_2xf32 * pInput,
                                                  uint32_t size);

/**
 * @brief          Arctangent - real single precision,  high accuracy.
 * @details        Function calculates the inverse tangent of a real data vectors. \n
 *                 It returns atan(x) in domain [-pi/2,pi/2] for x in domain (-INF,INF) using a Maclaurin expansion. \n
 *                 This avoids the expensive division needed in the Pade approximation alternative
 *                 and is slightly faster.  \n
 *                 Output must not be in-place memory vector. \n
 * @param[out]     pOutput     Result contains 8 parallel real vectors, size N.
 * @param[in]      pInput      Operand contains 8 parallel real vectors, size N.
 * @param[in]      size        Size of input and output vectors, N.
 *
 * @note           atan(vector) = vector \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..4095]
 */
void Rsdk_EF_atan_Vof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                            xb_vecN_2xf32 * pInput,
                                                   uint32_t size);

/**
 * @brief          Arctangent2 - real single precision.
 * @details        Function calculates 4 quadrant inverse tangent of 2 real data vectors. \n
 *                 It returns atan2(y/x) in domain [-pi,pi] for x and y in domain (-INF,INF). \n
 *                 Function uses atan() - high accuracy. \n
 *                 Output must not be in-place memory vectors.
 *
 * @param[out]     pOutput     Result contains 8 parallel real vectors, size N.
 * @param[in]      pInputY     First operand contains 8 parallel real vectors, size N.
 * @param[in]      pInputX     Second operand contains 8 parallel real vectors, size N.
 * @param[in]      size        Size of input and output vectors, N.
 *
 * @note           atan2(vector2,vector1) = vector \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..2730]
 */
void Rsdk_EF_atan2_Vof32p8Vif32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                                    xb_vecN_2xf32 * pInputY,
                                                    xb_vecN_2xf32 * pInputX,
                                                           uint32_t size);
/** @} */


/** @addtogroup dsp_lal_api_func_log_vec
* @{
*/

/**
 * @brief          Natural logarithm - real single precision,  high accuracy.
 * @details        Function calculates the natural logarithm of a real data vectors
 *                 using the Taylor series approximation, 4 coefficients. \n
 *                 Implemented algorithm from Approximations for Digital Computers, Cecil Hastings, p176. \n
 *                 Input and output must not be in-place memory vectors.
 *
 * @param[out]     pOutput     Result contains 8 parallel real vectors, size N.
 * @param[in]      pInput      Operand contains 8 parallel real vectors, size N.
 * @param[in]      size        Size of input and output vectors, N.
 *
 * @note           log(vector) = vector \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..4095]
 */
void Rsdk_EF_log_Vof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                           xb_vecN_2xf32 * pInput,
                                                  uint32_t size);

/**
 * @brief          Logarithm base 2 - real single precision,  high accuracy.
 * @details        Function calculates the base 2 logarithm of a real data vectors
 *                 using the formula log2(x)=log(x)/log(2). \n
 *                 log(x) is implemented from Approximations for Digital Computers, Cecil Hastings, p176. \n
 *                 Output must not be in-place memory vector. \n
 *
 * @param[out]     pOutput     Result contains 8 parallel real vectors, size N.
 * @param[in]      pInput      Operand contains 8 parallel real vectors, size N.
 * @param[in]      size        Size of input and output vectors, N.
 *
 * @note           log2(vector) = vector \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..4095]
 */
void Rsdk_EF_log2_Vof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                            xb_vecN_2xf32 * pInput,
                                                   uint32_t size);

/**
 * @brief          Logarithm base 10 - real single precision,  high accuracy.
 * @details        Function calculates the base 10 logarithm of a real data vectors
 *                 using the formula log10(x)=log(x)/log(10). \n
 *                 log(x) is implemented from Approximations for Digital Computers, Cecil Hastings, p176. \n
 *                 Output must not be in-place memory vector. \n
 *
 * @param[out]     pOutput     Result contains 8 parallel real vectors, size N.
 * @param[in]      pInput      Operand contains 8 parallel real vectors, size N.
 * @param[in]      size        Size of input and output vectors, N.
 *
 * @note           log10(vector) = vector \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..4095]
 */
void Rsdk_EF_log10_Vof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                             xb_vecN_2xf32 * pInput,
                                                    uint32_t size);

/** @} */


/** @addtogroup dsp_lal_api_func_prod_vec
* @{
*/

/**
 * @brief          Cross product of 2 vectors - real single precision.
 * @details        Function computes the cross(vectorial) product of 2 real data vectors of size 3. \n
 *
 * @param[out]     pOutput     Result contains 8 parallel real vectors, size 3.
 * @param[in]      pInput1     First operand contains 8 parallel real vectors, size 3.
 * @param[in]      pInput2     First operand contains 8 parallel real vectors, size 3.
 *
 * @note           cross(vector1,vector2) = vector1 x vector2 \n
 */
void Rsdk_LA_cross_Vo3f32p8Vi3f32p8Vi3f32p8(xb_vecN_2xf32 * pOutput,
                                            xb_vecN_2xf32 * pInput1,
                                            xb_vecN_2xf32 * pInput2);

/**
 * @brief          Cross product of 2 vectors - complex single precision.
 * @details        Function computes the cross(vectorial) product for 2 complex data vectors of size 3. \n
 *
 * @param[out]     pOutput     Result contains 8 parallel complex vectors, size 3.
 * @param[in]      pInput1     First operand contains 8 parallel complex vectors, size 3.
 * @param[in]      pInput2     First operand contains 8 parallel complex vectors, size 3.
 *
 * @note           cross(vector1,vector2) = vector1 x vector2 \n
 */
void Rsdk_LA_cross_Vo3f32cp8Vi3f32cp8Vi3f32cp8(xb_vecN_2xcf32 * pOutput,
                                               xb_vecN_2xcf32 * pInput1,
                                               xb_vecN_2xcf32 * pInput2);

/**
 * @brief          Complex conjugated cross product of 2 vectors - complex single precision.
 * @details        Function computes the conjugated cross(vectorial) product for 2 complex data vectors of size 3. \n
 *
 * @param[out]     pOutput     Result contains 8 parallel complex vectors, size 3.
 * @param[in]      pInput1     First operand contains 8 parallel complex vectors, size 3.
 * @param[in]      pInput2     First operand contains 8 parallel complex vectors, size 3.
 *
 * @note           crossconj(vector1,vector2) = conj(vector1 x vector2) \n
 */
void Rsdk_LA_crossconj_Vo3f32cp8Vi3f32cp8Vi3f32cp8(xb_vecN_2xcf32 * pOutput,
                                                   xb_vecN_2xcf32 * pInput1,
                                                   xb_vecN_2xcf32 * pInput2);

/**
 * @brief          Dot product of 2 vectors - real single precision.
 * @details        Function computes the dot(scalar) product of 2 real data vectors. \n
 *
 * @param[out]     pOutput     Result contains 8 real scalars, size 1.
 * @param[in]      pInput1     First operand contains 8 parallel real vectors, size N.
 * @param[in]      pInput2     First operand contains 8 parallel real vectors, size N.
 * @param[in]      size        Size of input and output vectors, N.
 *
 * @note           dot(vector1,vector2) = sum(vector1[i] * vector2[i]) \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..4095]
 */
void Rsdk_LA_dot_Sof32p8Vif32p8Vif32p8(xb_vecN_2xf32 * pOutput,
                                       xb_vecN_2xf32 * pInput1,
                                       xb_vecN_2xf32 * pInput2,
                                              uint32_t size);

/**
 * @brief          Dot product of 2 vectors - complex single precision.
 * @details        Function computes the dot(scalar) product for 2 complex data vectors. \n
 *
 * @param[out]     pOutput     Result contains 8 complex scalars, size 1.
 * @param[in]      pInput1     First operand contains 8 parallel complex vectors, size N.
 * @param[in]      pInput2     First operand contains 8 parallel complex vectors, size N.
 * @param[in]      size        Size of input and output vectors, N.
 *
 * @note           dot(vector1,vector2) = sum(conj(vector1[i]) * vector2[i]) \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..2047]
 */
void Rsdk_LA_dotFirstConj_Sof32cp8Vif32cp8Vif32cp8(xb_vecN_2xcf32 * pOutput,
                                                   xb_vecN_2xcf32 * pInput1,
                                                   xb_vecN_2xcf32 * pInput2,
                                                           uint32_t size);

/**
 * @brief          Dot product of 2 vectors - complex single precision.
 * @details        Function computes the dot(scalar) product for 2 complex data vectors. \n
 *
 * @param[out]     pOutput     Result contains 8 complex scalars, size 1.
 * @param[in]      pInput1     First operand contains 8 parallel complex vectors, size N.
 * @param[in]      pInput2     First operand contains 8 parallel complex vectors, size N.
 * @param[in]      size        Size of input and output vectors, N.
 *
 * @note           dot(vector1,vector2) = sum(vector1[i] * conj(vector2[i])) \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [1..2047]
 */
void Rsdk_LA_dotSecondConj_Sof32cp8Vif32cp8Vif32cp8(xb_vecN_2xcf32 * pOutput,
                                                    xb_vecN_2xcf32 * pInput1,
                                                    xb_vecN_2xcf32 * pInput2,
                                                            uint32_t size);

/** @} */


/** @addtogroup dsp_lal_api_func_det_mat
* @{
*/

/**
 * @brief          Determinant of a matrix - real single precision.
 * @details        Function computes the determinant of a real matrix
 *                 using the upper triangular matrix resulted after the QR decomposition
 *                 of the input matrix. \n
 *
 * @param[out]     pOutput     Result contains 8 real scalars.
 * @param[in]      pInput      First operand contains 8 parallel real matrices, size NxN.
 * @param[in,out]  pBuffer1    Scratch area contains 8 parallel real matrices, size NxN. \n
 *                             It may have the same address as the input buffer - inplace mode. \n
 *                             In this case the input buffer is overwritten. \n
 * @param[in,out]  pBuffer2    Scratch area contains 8 parallel real vectors, size N.
 * @param[in]      size        Number of rows and columns in the input matrix, N.
 * 
 * @note           det(matrix) = scalar \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 If used in inplace mode: \n
 *                 size        range is [2..90] \n
 *                 else: \n
 *                 size        range is [2..63]
 */
void Rsdk_LA_detSq_Sof32p8Mif32p8(xb_vecN_2xf32 * pOutput,
                                  xb_vecN_2xf32 * pInput,
                                  xb_vecN_2xf32 * pBuffer1,
                                  xb_vecN_2xf32 * pBuffer2,
                                         uint32_t size);

/**
 * @brief          Determinant of a matrix - complex single precision.
 * @details        Function computes the determinant of a complex matrix
 *                 using the upper triangular matrix resulted after the QR decomposition
 *                 of the input matrix. \n
 *
 * @param[out]     pOutput     Result contains 8 complex scalars.
 * @param[in]      pInput      First operand contains 8 parallel complex matrices, size NxN.
 * @param[in,out]  pBuffer1    Scratch area contains 8 parallel complex matrices, size NxN. \n
 *                             It may have the same address as the input buffer - inplace mode. \n
 *                             In this case the input buffer is overwritten.
 * @param[in,out]  pBuffer2    Scratch area contains 8 parallel complex vectors, size N.
 * @param[in]      size        Number of rows and columns in the input matrix, N.
 * 
 * @note           det(matrix) = scalar \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 If used in inplace mode: \n
 *                 size        range is [2..63] \n
 *                 else: \n
 *                 size        range is [2..44]
 */
void Rsdk_LA_detSq_Sof32cp8Mif32cp8(xb_vecN_2xcf32 * pOutput,
                                    xb_vecN_2xcf32 * pInput,
                                    xb_vecN_2xcf32 * pBuffer1,
                                    xb_vecN_2xcf32 * pBuffer2,
                                            uint32_t size);

/** @} */


/** @addtogroup dsp_lal_api_func_qr_dec_mat
* @{
*/

/**
 * @brief          QR decomposition of a matrix - real single precision.
 * @details        Function computes the QR decomposition in parallel for each real matrix
 *                 in batch using Householder transformations.                              \n
 *                 Function assumes that all matrices have linearly independent columns.    \n
 *                 Usual R, Q are not unique, but if input matrix is of full rank,
 *                 then there exists a single R that has all positive diagonal elements.    \n
 *                 If the input matrix is square non singular, the decomposition is unique. \n
 *                 Corresponding rows and columns in Q and R can flip their signs.          \n
 *                 pOutputR and pInput can point to the same address - inplace mode. In this
 *                 case the input buffer is overwritten.                                    \n
 *                 outputQ*outputR = input \n
 *                 Q*R = input \n
 *
 * @param[out]     pOutputR    First result contains 8 parallel real R matrices, size MxN. \n
 *                             The R-matrix is an upper triangular matrix \n
 * @param[out]     pOutputQ    Second result contains 8 parallel real Q matrices, size MxM. \n
 *                             The Q-matrix has orthonormal columns(QT*Q=I). If input is a square \n
 *                             matrix, Q is orthonormal(Q*QT=QT*Q=I).
 * @param[in,out]  pBuffer     Scratch area for a vector with the length equal with the number of \n
 *                             lines in the input matrix, size M.
 * @param[in]      pInput      Operand contains 8 parallel real matrices, size MxN. \n
 * @param[in]      rows        Row size of input matrix, Q matrix and R matrix and column size
 *                             for Q matrix - (M).
 * @param[in]      cols        Column size of input matrix and of R matrix - (N).
 * 
 * @note           qr(matrixM) = matrixQ, matrixR with M = Q*R \n
 *                 rows >= cols                                \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 If used in inplace mode: \n
 *                 rows        range is [2..M] \n
 *                 cols        range is [2..N] \n 
 *                 (M * (N + M + 1)) < 8192    \n
 *                 else: \n
 *                 rows        range is [2..M] \n
 *                 cols        range is [2..N] \n 
 *                 (M * (2 * N + M + 1)) < 8192    \n
 */
void Rsdk_LA_decQRHous_Mof32p8Mof32p8Mif32p8(xb_vecN_2xf32 * pOutputR,
                                             xb_vecN_2xf32 * pOutputQ,
                                             xb_vecN_2xf32 * pBuffer,
                                             xb_vecN_2xf32 * pInput,
                                                    uint32_t rows,
                                                    uint32_t cols);

/**
 * @brief          QR decomposition of a matrix - complex single precision.
 * @details        Function computes the QR decomposition in parallel for each complex matrix
 *                 in batch using Householder reflection.                                   \n
 *                 Function assumes that all matrices have linearly independent columns.    \n
 *                 Usual R, Q are not unique, but if input matrix is of full rank,
 *                 then there exists a single R that has all positive diagonal elements.    \n
 *                 If input matrix is square non singular, then the decomposition is unique.\n
 *                 Corresponding rows and columns in Q and R can flip their signs.          \n
 *                 pOutputR and pInput can point to the same address - inplace mode. In this
 *                 case the input buffer is overwritten.                                    \n
 *                 outputQ*outputR = input \n
 *                 Q*R = input \n
 *
 * @param[out]     pOutputR    First result contains 8 parallel complex R matrices, size MxN. \n
 *                             The R-matrix is an upper triangular matrix. \n
 * @param[out]     pOutputQ    Second result contains 8 parallel complex Q matrices, size MxM. \n
 *                             The Q-matrix has orthonormal columns(QH*Q=I). If input is a square \n
 *                             matrix Q is orthogonal(Q*QH=QH*Q=I).
 * @param[in,out]  pBuffer     Scratch area for a vector with the length equal with the number of \n
 *                             lines in the input matrix, size M.\n
 * @param[in]      pInput      Operand contains 8 parallel complex matrices, size MxN. \n
 * @param[in]      rows        Row size of input matrix, Q matrix and R matrix and column size
 *                             for Q matrix - (M).
 * @param[in]      cols        Column size of input matrix and of R matrix - (N).
 * 
 * @note           qr(matrixM) = matrixQ, matrixR with M = Q*R \n
 *                 rows >= cols                                \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 If used in inplace mode: \n
 *                 rows        range is [2..M] \n
 *                 cols        range is [2..N] \n 
 *                 (M * (N + M + 1)) < 4095    \n
 *                 else: \n
 *                 rows        range is [2..M] \n
 *                 cols        range is [2..N] \n 
 *                 (M * (2 * N + M + 1)) < 4095
 */
void Rsdk_LA_decQRHous_Mof32cp8Mof32cp8Mif32cp8(xb_vecN_2xcf32 * pOutputR,
                                                xb_vecN_2xcf32 * pOutputQ,
                                                xb_vecN_2xcf32 * pBuffer,
                                                xb_vecN_2xcf32 * pInput,
                                                        uint32_t rows,
                                                        uint32_t cols);

/** @} */

/** @addtogroup dsp_lal_api_func_cholesky_dec_mat
* @{
*/

/**
 * @brief          Cholesky decomposition of a matrix - LL - real single precision.
 * @details        The function applies Cholesky decomposition on real input matrix
 *                 and returns lower triangular matrix implementing the Cholesky-Crout
 *                 algorithm.                                                          \n
 *                 Function assumes the input matrix is square and symmetric.          \n
 *                 Function should not be used for input matrices that are not positive
 *                 definite or semi-definite.                                          \n
 *                 Decomposition is unique when the input matrix is positive definite
 *                 and the output matrix has real and positive diagonal entries.       \n
 *                 If the input matrix is positive semi-definite the decomposition is
 *                 not unique and the output diagonal entries can be zeros.            \n
 *                 input = L * L^T                                                     \n
 *
 * @param[out]     pOutput     Result contains 8 parallel low-triangular real matrices, size NxN. \n
 * @param[in]      pInput      Operand contains 8 parallel real matrices, size NxN. \n
 * @param[in]      size        Number of rows and columns in the input and output matrices.
 *
 * @note           Cholesky(inmatrix) = outmatrix with inmatrix = outmatrix*outmatrix^T \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [2..63]
 */
void Rsdk_LA_decLLCholPd_Mof32p8Mif32p8(xb_vecN_2xf32 * pOutput,
                                        xb_vecN_2xf32 * pInput,
                                               uint32_t size);

/**
 * @brief          Cholesky decomposition of a matrix - LL - complex single precision.
 * @details        The function applies Cholesky decomposition on complex input matrix
 *                 and returns lower triangular matrix implementing the Cholesky-Crout
 *                 algorithm.                                                          \n
 *                 Function assumes the input matrix is square and Hermitian.          \n
 *                 Function should not be used for input matrices that are not positive
 *                 definite or semi-definite.                                          \n
 *                 Decomposition is unique when the input matrix is positive definite,
 *                 then the output matrix has real and positive diagonal entries.      \n
 *                 If the input matrix is positive semi-definite the decomposition is
 *                 not unique and the output diagonal entries can be zeros.            \n
 *                 input = L * L^H                                                     \n
 *
 * @param[out]     pOutput     Result contains 8 parallel low-triangular real matrices, size NxN. \n
 * @param[in]      pInput      Operand contains 8 parallel real matrices, size NxN. \n
 * @param[in]      size        Number of rows and columns in the input and output matrices.
 *
 * @note           Cholesky(inmatrix) = outmatrix with inmatrix = outmatrix*outmatrix^H \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [2..45]
 */
void Rsdk_LA_decLLCholPd_Mof32cp8Mif32cp8(xb_vecN_2xcf32 * pOutput,
                                          xb_vecN_2xcf32 * pInput,
                                                  uint32_t size);

/** @} */

/** @addtogroup dsp_lal_api_func_conj_vec
* @{
*/

/**
 * @brief          Conjugate - complex single precision.
 * @details        Function implements the conjugate operation on a vector.            \n
 *                 Output must not be in-place memory vector.                          \n
 *
 * @param[out]     pOutput     Result contains 8 parallel complex vectors, size N.
 * @param[in]      pInput      Operand contains 8 parallel complex vectors, size N.
 * @param[in]      size        Size of input and output vectors, N.
 *
 * @note           conj(vector) = vector \n
 *                 The following size is estimated in the ideal condition that the function uses the whole memory of 256 KBytes. \n
 *                 size        range is [2..2047]
 */
void Rsdk_LA_conj_Vof32cp8Vif32cp8(xb_vecN_2xcf32 * __restrict pOutput,
                                              xb_vecN_2xcf32 * pInput,
                                                      uint32_t size);

/** @} */


/** @addtogroup dsp_lal_api_func_min_max_vec
* @{
*/

/**
 * @brief          Min - real single precision.
 * @details        Function implements minimum operation for real data vectors.        \n
 *                 The function returns the index of the minimum value.                \n
 *                 In case of multiple appearances of the minimum value,
 *                 the first position is returned. \n
 *                 Output must not be in-place memory.                                 \n
 *
 * @param[out]     pOutput     Result contains a pointer to 8 parallel scalar values, the positions of the minimum values.
 * @param[in]      pInput      First operand contains 8 parallel real vectors, size N.
 * @param[in]      size        Size of input vector, N.
 *
 * @note           min(vector) = scalar \n
 *                 The maximum vector size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N <= 8000. \n
 */
void Rsdk_LA_min_Sou32p8Vif32p8(xb_vecN_2x32Uv * __restrict pOutput,
                                            xb_vecN_2xf32 * pInput,
                                                   uint32_t size);

/**
 * @brief          Min - complex single precision.
 * @details        Function implements minimum operation for complex data vectors.        \n
 *                 The function returns the index of element with the smallest magnitude. \n
 *                 In case of multiple appearances of the minimum magnitude,
 *                 the index of the first apperance is returned.                          \n
 *                 Phase is not used.                                                     \n
 *                 Output must not be in-place memory.                                    \n
 *
 * @param[out]     pOutput     Result contains a pointer to 8 parallel scalar values, the positions of the minimum magnitude values.
 * @param[in]      pInput      First operand contains 8 parallel complex vectors, size N.
 * @param[in]      size        Size of input vector, N.
 *
 * @note           min(vector) = scalar \n
 *                 The maximum vector size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N <= 4000. \n
 */
void Rsdk_LA_minAbs_Sou32p8Vif32cp8(xb_vecN_2x32Uv * __restrict pOutput,
                                               xb_vecN_2xcf32 * pInput,
                                                       uint32_t size);

/**
 * @brief          Max - real single precision.
 * @details        Function implements maximum operation for real data vectors.        \n
 *                 The function returns the index of the maximum value.                \n
 *                 In case of multiple appearances of the maximum value,
 *                 the index of the first apperance is returned.
 *                 Output must not be in-place memory.                                 \n
 *
 * @param[out]     pOutput     Result contains a pointer to 8 parallel scalar values, the positions of the maximum values.
 * @param[in]      pInput      First operand contains 8 parallel real vectors, size N.
 * @param[in]      size        Size of input vector, N.
 *
 * @note           max(vector) = scalar \n
 *                 The maximum vector size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N <= 8000. \n
 */

void Rsdk_LA_max_Sou32p8Vif32p8(xb_vecN_2x32Uv * __restrict pOutput,
                                           xb_vecN_2xf32  * pInput,
                                                   uint32_t size);
/**
 * @brief          Max - complex single precision.
 * @details        Function implements maximum operation for complex data vectors.       \n
 *                 The function returns the index of element with the largest magnitude. \n
 *                 In case of multiple appearances of the maximum magnitude,
 *                 the index of the first apperance is returned.                         \n
 *                 Phase is not used.                                                    \n
 *                 Output must not be in-place memory.                                   \n
 *
 * @param[out]     pOutput     Result contains a pointer to 8 parallel scalar values, the positions of the maximum magnitude values.
 * @param[in]      pInput      First operand contains 8 parallel complex vectors, size N.
 * @param[in]      size        Size of input vector, N.
 *
 * @note           max(vector) = scalar \n
 *                 The maximum vector size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N <= 4000. \n
 */
void Rsdk_LA_maxAbs_Sou32p8Vif32cp8(xb_vecN_2x32Uv * __restrict pOutput,
                                              xb_vecN_2xcf32  * pInput,
                                                       uint32_t size);
/** @} */


/** @addtogroup dsp_lal_api_func_sum_vec
* @{
*/

/**
 * @brief          Sum - real single precision.
 * @details        Function implements sum operation for real data vectors.            \n
 *                 Output must not be in-place memory.                                 \n
 *
 * @param[out]     pOutput     Result contains a pointer to 8 parallel scalar real values.
 * @param[in]      pInput      First operand contains 8 parallel real vectors, size N.
 * @param[in]      size        Size of input vector, N.
 *
 * @note           sum(vector) = scalar \n
 *                 The maximum vector size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N <= 8000. \n
 */
void Rsdk_LA_sum_Sof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                           xb_vecN_2xf32 * pInput,
                                                  uint32_t size);

/**
 * @brief          Sum - complex single precision.
 * @details        Function implements sum operation for complex data vectors.        \n
 *                 Output must not be in-place memory.                                \n
 *
 * @param[out]     pOutput     Result contains a pointer to 8 parallel scalar complex values.
 * @param[in]      pInput      First operand contains 8 parallel complex vectors, size N.
 * @param[in]      size        Size of input vector, N.
 *
 * @note           sum(vector) = scalar \n
 *                 The maximum vector size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N <= 4000. \n
 */
void Rsdk_LA_sum_Sof32cp8Vif32cp8(xb_vecN_2xcf32 * __restrict pOutput,
                                             xb_vecN_2xcf32 * pInput,
                                                     uint32_t size);

/**
 * @brief          Sum of all squared vector elements - real single precision.
 * @details        Function implements sum of all squared elements operation for real data vectors. \n
 *                 Output must not be in-place memory.                                              \n
 *
 * @param[out]     pOutput     Result contains a pointer to 8 parallel scalar real values.
 * @param[in]      pInput      First operand contains 8 parallel real vectors, size N.
 * @param[in]      size        Size of input vector, N.
 *
 * @note           sum2(vector) = scalar \n
 *                 The maximum vector size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N <= 8000. \n
 */
void Rsdk_LA_sum2_Sof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                            xb_vecN_2xf32 * pInput,
                                                   uint32_t size);

/**
 * @brief          Sum of all squared vector elements - complex single precision.
 * @details        Function implements sum of all squared elements operation for complex data vectors. \n
 *                 Output must not be in-place memory.                                                 \n
 *
 * @param[out]     pOutput     Result contains a pointer to 8 parallel scalar complex values.
 * @param[in]      pInput      First operand contains 8 parallel complex vectors, size N.
 * @param[in]      size        Size of input vector, N.
 *
 * @note           sum2(vector) = scalar \n
 *                 The maximum vector size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N <= 4000. \n
 */
void Rsdk_LA_sum2_Sof32cp8Vif32cp8(xb_vecN_2xcf32 * __restrict pOutput,
                                              xb_vecN_2xcf32 * pInput,
                                                      uint32_t size);

/**
 * @brief          Sum of all cubes vector elements - real single precision.
 * @details        Function implements sum of all cubes elements operation for real data vectors. \n
 *                 Output must not be in-place memory.                                            \n
 *
 * @param[out]     pOutput     Result contains a pointer to 8 parallel scalar real values.
 * @param[in]      pInput      First operand contains 8 parallel real vectors, size N.
 * @param[in]      size        Size of input vector, N.
 *
 * @note           sum3(vector) = scalar \n
 *                 The maximum vector size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N <= 8000. \n
 */
void Rsdk_LA_sum3_Sof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                            xb_vecN_2xf32 * pInput,
                                                   uint32_t size);

/**
 * @brief          Sum of all cubes vector elements - complex single precision.
 * @details        Function implements sum of all cubes elements operation for complex data vectors. \n
 *                 Output must not be in-place memory.                                               \n
 *
 * @param[out]     pOutput     Result contains a pointer to 8 parallel scalar complex values.
 * @param[in]      pInput      First operand contains 8 parallel complex vectors, size N.
 * @param[in]      size        Size of input vector, N.
 *
 * @note           sum3(vector) = scalar \n
 *                 The maximum vector size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N <= 4000. \n
 */
void Rsdk_LA_sum3_Sof32cp8Vif32cp8(xb_vecN_2xcf32 * __restrict pOutput,
                                              xb_vecN_2xcf32 * pInput,
                                                      uint32_t size);

/**
 * @brief          Sum of all reciprocal vector elements - real single precision.
 * @details        Reciprocal summation is the addition of a sequence of each 1 divided by element in vector,
 *                 called addends or summands. The result is their reciprocal sum or reciprocal total.\n
 *                 The parallel stream result is NAN, if one input in that stream is zero. 
 *
 * @param[out]     pOutput     Result, contains a pointer to 8 parallel scalar real values.
 * @param[in]      pInput      Operand, contains 8 parallel real vectors, size N.
 * @param[in]      size        Number of vector elements(N).
 *
 * @note           element reciprocal sum (vector) = scalar \n
 *                 n = size \n
 *                 v = n, a1, a2..., an; \n
 *                 ersum(v) = 1/a1 + 1/a2 + ... + 1/an;
 *                 The maximum vector size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N <= 8000. \n
 */
void Rsdk_LA_sumRcp_Sof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                             xb_vecN_2xf32 const * pInput,
                                          uint32_t size);

/**
 * @brief          Sum of all reciprocal vector elements - complex single precision.
 * @details        Reciprocal summation is the addition of a sequence of each
 *                 1 divided by element in vector, called addends or summands.
 *                 The result is their reciprocal sum or reciprocal total.
 *
 * @param[out]     pOutput     Result, contains a pointer to 8 parallel scalar complex values.
 * @param[in]      pInput      Operand, contains 8 parallel complex vectors, size N.
 * @param[in]      size        Number of vector elements(N).
 *
 * @note           element reciprocal sum (vector) = scalar \n
 *                 n = size \n
 *                 v = n, a1, a2..., an; \n
 *                 a1 = x + iy; \n
 *                 ersum(v) = 1/a1 + 1/a2 + ... + 1/an; \n
 *                 1/a1 = x/(x^2 + y^2) - iy/(x^2 + y^2);
 *                 The maximum vector size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N <= 8000. \n
 */
void Rsdk_LA_sumRcp_Sof32cp8Vif32cp8(xb_vecN_2xcf32 * __restrict pOutput,
                               xb_vecN_2xcf32 const * pInput,
                                             uint32_t size);
/** @} */

/** @addtogroup dsp_lal_api_func_inv_up_triang_mat
* @{
*/

/**
 * @brief          Upper triangular matrix inverse - real single precision.
 * @details        Function implements matrix inverse for an upper triangular matrix.                     \n
 *                 Function assumes input matrix is an upper triangular, non-singular and has inverse.    \n
 *                 Output can be in-place memory.                                                         \n

 *
 * @param[out]     pOutput     Result contains 8 parallel real matrices, size NxN.
 * @param[in]      pInput      Operand contains 8 parallel real matrices, size NxN.
 * @param[in]      size        Number of rows and columns in the input and output matrices, N(>=2).
 *
 * @note           inv(matrix) = matrix \n
 *                 The maximum matrix size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N < 64. \n
 */
void Rsdk_LA_invUNs_Mof32p8Mif32p8(xb_vecN_2xf32 * pOutput,
                                   xb_vecN_2xf32 * pInput,
                                          uint32_t size);

/**
 * @brief          Upper triangular matrix inverse - complex single precision.
 * @details        Function implements matrix inverse for an upper triangular matrix.                     \n
 *                 Function assumes input matrix is an upper triangular, non-singular and has inverse.    \n
 *                 Output can be in-place memory.                                                         \n
 *
 * @param[out]     pOutput     Result contains 8 parallel complex matrices,size NxN
 * @param[in]      pInput      Operand contains 8 parallel complex matrices, size NxN.
 * @param[in]      size        Number of rows and columns in the input and output matrices, N(>=2).
 *
 * @note           inv(matrix) = matrix \n
 *                 The maximum matrix size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N < 45. \n
 */
void Rsdk_LA_invUNs_Mof32cp8Mif32cp8(xb_vecN_2xcf32 * pOutput,
                                     xb_vecN_2xcf32 * pInput,
                                             uint32_t size);


/**
 * @brief          Upper triangular rectangular matrix inverse - real single precision.
 * @details        Function implements matrix inverse for a rectangular upper triangular matrix.                  \n
 *                 Function assumes input matrix is rectangular, upper triangular, non-singular and has inverse.  \n
 *                 Function assumes output matrix is a NxM matrix filled with zeros.                              \n
 *                 Output cannot be in-place memory.                                                              \n
 *                 Number of rows of the input matrix should be >= number of columns                              \n

 *
 * @param[out]     pOutput     Result contains 8 parallel real matrices, size NxM.
 * @param[in]      pInput      Operand contains 8 parallel real matrices, size MxN.
 * @param[in]      rows        Number of rows in the input matrix and number of columns in the output matrix, M(>=2), M>=N.
 * @param[in]      cols        Number of columns in the input matrix and number of rows in the output matrix, N(>=2).
 *
 * @return         void
 *
 * @note           inv(matrix) = matrix \n
 *                 The maximum matrix size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: MxN < 64x64. \n
 */
 void Rsdk_LA_invRectUNs_Mof32p8Mif32p8(xb_vecN_2xf32 * __restrict pOutput,
		                                xb_vecN_2xf32 * pInput,
		                                       uint32_t rows,
										       uint32_t cols);
 
 
 /**
 * @brief          Upper triangular rectangular matrix inverse - complex single precision.
 * @details        Function implements matrix inverse for a rectangular upper triangular matrix.                  \n
 *                 Function assumes input matrix is rectangular upper triangular, non-singular and has inverse.   \n
 *                 Function assumes output matrix is a NxM matrix filled with zeros.                              \n
 *                 Output cannot be in-place memory.                                                              \n
 *                 Number of rows of the input matrix should be >= number of columns                              \n
 
 *
 * @param[out]     pOutput     Result contains 8 parallel complex matrices, size NxM.
 * @param[in]      pInput      Operand contains 8 parallel complex matrices, size MxN.
 * @param[in]      rows        Number of rows in the input matrix and number of columns in the output matrix, M(>=2), M>=N.
 * @param[in]      cols        Number of columns in the input matrix and number of rows in the output matrix, N(>=2).
 *
 * @return         void
 *
 * @note           inv(matrix) = matrix \n
 *                 The maximum matrix size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: MxN < 46x46. \n
 */
void Rsdk_LA_invRectUNs_Mof32cp8Mif32cp8(xb_vecN_2xcf32 * __restrict pOutput,
                                         xb_vecN_2xcf32 * pInput,
                                                 uint32_t rows,
												 uint32_t cols);
 /** @} */

/** @addtogroup dsp_lal_api_func_inv_low_triang_mat
* @{
*/

/**
 * @brief          Lower triangular matrix inverse - real single precision.
 * @details        Function implements matrix inverse for a lower triangular matrix.                     \n
 *                 Function assumes input matrix is a lower triangular, non-singular and has inverse.    \n
 *                 Output can be in-place memory.                                                         \n

 *
 * @param[out]     pOutput     Result contains 8 parallel real matrices, size NxN.
 * @param[in]      pInput      Operand contains 8 parallel real matrices, size NxN.
 * @param[in]      size        Number of rows and columns in the input and output matrices, N(>=2).
 *
 * @note           inv(matrix) = matrix \n
 *                 The maximum matrix size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N < 64. \n
 */
void Rsdk_LA_invLNs_Mof32p8Mif32p8(xb_vecN_2xf32 * pOutput,
                                   xb_vecN_2xf32 * pInput,
                                          uint32_t size);
	

/**
 * @brief          Lower triangular matrix inverse - complex single precision.
 * @details        Function implements matrix inverse for a lower triangular matrix.                     \n
 *                 Function assumes input matrix is a lower triangular, non-singular and has inverse.    \n
 *                 Output can be in-place memory.                                                         \n
 *
 * @param[out]     pOutput     Result contains 8 parallel complex matrices,size NxN
 * @param[in]      pInput      Operand contains 8 parallel complex matrices, size NxN.
 * @param[in]      size        Number of rows and columns in the input and output matrices, N(>=2).
 *
 * @note           inv(matrix) = matrix \n
 *                 The maximum matrix size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N < 45. \n
 */
void Rsdk_LA_invLNs_Mof32cp8Mif32cp8(xb_vecN_2xcf32 * pOutput,
                                     xb_vecN_2xcf32 * pInput,
                                             uint32_t size);
											 
/**
 * @brief          Lower triangular rectangular matrix inverse - real single precision.
 * @details        Function implements matrix inverse for a lower triangular rectangular matrix.                    \n
 *                 Function assumes input matrix is rectangular, lower triangular, non-singular and has inverse.    \n
 *                 Function assumes output matrix is a NxM matrix filled with zeros.                                \n
 *                 Output cannot be in-place memory.                                                                \n
 *                 Number of rows of the input matrix should be <= number of columns                                \n
 *
 * @param[out]     pOutput     Result contains 8 parallel real matrices, size NxM.
 * @param[in]      pInput      Operand contains 8 parallel real matrices, size MxN.
 * @param[in]      rows        Number of rows in the input matrix and number of columns in the output matrix, M(>=2), M<=N.
 * @param[in]      cols        Number of columns in the input matrix and number of rows in the output matrix, N(>=2).
 *
 * @return         void
 *
 * @note           inv(matrix) = matrix \n
 *                 The maximum matrix size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: MxN < 64x64. \n
 */
void Rsdk_LA_invRectLNs_Mof32p8Mif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                       xb_vecN_2xf32 * pInput,
                                              uint32_t rows,
										      uint32_t cols);
										  
										  
/**
 * @brief          Lower triangular rectangular matrix inverse - complex single precision.
 * @details        Function implements matrix inverse for a lower triangular rectangular matrix.                    \n
 *                 Function assumes input matrix is rectangular, lower triangular, non-singular and has inverse.    \n
 *                 Function assumes output matrix is a NxM matrix filled with zeros.                                \n
 *                 Output cannot be in-place memory.                                                                \n
 *                 Number of rows of the input matrix should be <= number of columns                                \n
 *
 * @param[out]     pOutput     Result contains 8 parallel complex matrices,size NxM
 * @param[in]      pInput      Operand contains 8 parallel complex matrices, size MxN.
 * @param[in]      rows        Number of rows in the input matrix and number of columns in the output matrix, M(>=2), M<=N.
 * @param[in]      cols        Number of columns in the input matrix and number of rows in the output matrix, N(>=2).
 *
 * @return         void
 *
 * @note           inv(matrix) = matrix \n
 *                 The maximum matrix size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: MxN < 46x46. \n
 */
void Rsdk_LA_invRectLNs_Mof32cp8Mif32cp8(xb_vecN_2xcf32 * __restrict pOutput,
                                         xb_vecN_2xcf32 * pInput,
                                                 uint32_t rows,
										         uint32_t cols);										 

 /** @} */

 /** @addtogroup dsp_lal_api_func_inv_qr_mat
* @{
*/

/**
 * @brief          Matrix inverse - real single precision.
 * @details        Function implements matrix inverse using QR decomposition with Householder reflection. \n
 *                 Function multiplies the inverse of R matrix with the inverse of the Q matrix. \n
 *                 Function assumes input matrix is non-singular and has inverse.                \n
 *                 Output can be in-place memory.                                              \n
 *
 * @param[out]     pOutput     Result contains 8 parallel real matrices, size NxN.
 * @param[in]      pInput      Operand contains 8 parallel real matrices, size NxN.
 * @param[in,out]  pBuffer1    Scratch area for 8 parallel real matrices used for Q matrices, size N*N.
 * @param[in,out]  pBuffer2    Scratch area for 8 parallel real matrices used for R matrices and
 *                             R inverse matrices, size N*N.
 * @param[in]      size        Number of rows and columns in the input and output matrices, N(>=2).
 *
 * @note           inv(matrix) = matrix \n
 *                 The maximum matrix size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N < 45. \n
 */
void Rsdk_LA_invHousQRNs_Mof32p8Mif32p8(xb_vecN_2xf32 * pOutput,
                                        xb_vecN_2xf32 * pInput,
                                        xb_vecN_2xf32 * pBuffer1,
                                        xb_vecN_2xf32 * pBuffer2,
                                               uint32_t size);

/**
 * @brief          Matrix inverse - complex single precision.
 * @details        Function implements matrix inverse using QR decomposition with Householder reflection. \n
 *                 Function multiplies the inverse of R matrix with the inverse of the Q matrix. \n
 *                 Function assumes input matrix is non-singular and has inverse.                \n
 *                 Output can be in-place memory.                                              \n
 *
 * @param[out]     pOutput     Result contains 8 parallel complex matrices,size NxN
 * @param[in]      pInput      Operand contains 8 parallel complex matrices, size NxN.
 * @param[in,out]  pBuffer1    Scratch area for 8 parallel complex matrices used for Q matrices, size N*N.
 * @param[in,out]  pBuffer2    Scratch area for 8 parallel complex matrices used for R matrices and
 *                             R inverse matrices, size N*N.
 * @param[in]      size        Number of rows and columns in the input and output matrices, N(>=2).
 *
 * @note           inv(matrix) = matrix \n
 *                 The maximum matrix size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N < 32. \n
 */
void Rsdk_LA_invHousQRNs_Mof32cp8Mif32cp8(xb_vecN_2xcf32 * pOutput,
                                          xb_vecN_2xcf32 * pInput,
                                          xb_vecN_2xcf32 * pBuffer1,
                                          xb_vecN_2xcf32 * pBuffer2,
                                                  uint32_t size);

/** @} */


/** @addtogroup dsp_lal_api_func_inv_gauss_mat
* @{
*/

/**
 * @brief          Matrix inverse - real single precision.
 * @details        Function implements matrix inverse using Gaussian Elimination with column pivoting. \n
 *                 Function assumes input matrix is non-singular and has inverse.                      \n
 *                 Output can be in-place memory.                                                      \n
 *
 * @param[out]     pOutput     Result contains 8 parallel real matrices, size NxN.
 * @param[in,out]  pInput      Operand contains 8 parallel real matrices, size NxN.
 * @param[in]      size        Number of rows and columns in the input and output matrices, N(>=2).
 *
 * @note           inv(matrix) = matrix \n
 *                 Function modifies input matrix. If one needs them for ulterior processing,
 *                 they  should copy the input to another buffer before calling this function.
 *                 The maximum matrix size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N <= 50. \n
 */
void Rsdk_LA_invGausCPNs_Mof32p8Miof32p8(xb_vecN_2xf32 * restrict pOutput,
                                         xb_vecN_2xf32 * pInput,
                                                uint32_t size);

/**
 * @brief          Matrix inverse - real single precision.
 * @details        Function implements matrix inverse using Gaussian Elimination with no pivoting. \n
 *                 Function assumes input matrix is non-singular and has inverse.                  \n
 *                 Output can be in-place memory.                                                  \n
 *
 * @param[out]     pOutput     Result contains 8 parallel real matrices, size NxN.
 * @param[in,out]  pInput      Operand contains 8 parallel real matrices, size NxN.
 * @param[in]      size        Number of rows and columns in the input and output matrices, N(>=2).
 *
 * @note           inv(matrix) = matrix \n
 *                 Function modifies input matrix. If one needs them for ulterior processing,
 *                 they  should copy the input to another buffer before calling this function.
 *                 The maximum matrix size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N <= 50. \n
 */
void Rsdk_LA_invNsGaus_Mof32p8Miof32p8(xb_vecN_2xf32 * restrict pOutput,
                                       xb_vecN_2xf32 * pInput,
                                              uint32_t size);

/**
 * @brief          Matrix inverse - complex single precision.
 * @details        Function implements matrix inverse using Gaussian Elimination with column pivoting. \n
 *                 Function assumes input matrix is non-singular and has inverse.                      \n
 *                 Output can be in-place memory.                                                      \n
 *
 * @param[out]     pOutput     Result contains 8 parallel complex matrices,size NxN
 * @param[in,out]  pInput      Operand contains 8 parallel complex matrices, size NxN.
 * @param[in]      size        Number of rows and columns in the input and output matrices, N(>=2).
 *
 * @note           inv(matrix) = matrix \n
 *                 Function modifies input matrix. If one needs them for ulterior processing,
 *                 they  should copy the input to another buffer before calling this function.
 *                 The maximum matrix size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N <= 35. \n
 */
void Rsdk_LA_invGausCPNs_Mof32cp8Miof32cp8(xb_vecN_2xcf32 * restrict pOutput,
                                           xb_vecN_2xcf32 * pInput,
                                                   uint32_t size);

/**
 * @brief          Matrix inverse - complex single precision.
 * @details        Function implements matrix inverse using Gaussian Elimination with no pivoting. \n
 *                 Function assumes input matrix is non-singular and has inverse.                  \n
 *                 Output can be in-place memory.                                                  \n
 *
 * @param[out]     pOutput     Result contains 8 parallel complex matrices,size NxN
 * @param[in,out]  pInput      Operand contains 8 parallel complex matrices, size NxN.
 * @param[in]      size        Number of rows and columns in the input and output matrices, N(>=2).
 *
 * @note           inv(matrix) = matrix \n
 *                 Function modifies input matrix. If one needs them for ulterior processing,
 *                 they  should copy the input to another buffer before calling this function.
 *                 The maximum matrix size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N <= 35. \n
 */
void Rsdk_LA_invNsGaus_Mof32cp8Miof32cp8(xb_vecN_2xcf32 * restrict pOutput,
                                         xb_vecN_2xcf32 * pInput,
                                                 uint32_t size);


/** @} */


/** @addtogroup dsp_lal_api_func_eig_jacobi_mat
* @{
*/

/**
 * @brief          Eigen solver for symmetric NxN matrices - real single precision.
 * @details        Functions computes the eigenvalues and eigenvectors for the input matrices. \n
 *                 The eigen-decomposition: A=V*D*Vt is done executing successive Jacobi rotations over
 *                 the input matrix. \n
 *                 The function assumes the the matrices are real symmetric.The algorithm will only use
 *                 the values on and above the leading diagonal of the input matrix. \n
 *                 The output D matrix contains on the diagonal the eigenvalues, as result of the
 *                 Jacobi rotations. \n
 *                 The output V matrix columns are the eigenvectors of the input matrix. \n
 *                 The eigenvectorin column k of the matrix V has the corresponding eigenvalue in the diagonal
 *                 element (k,k) of the matrix D. \n
 *                 Output can be in-place memory.                                                    \n
 *                 pOutputD and pInput can point to the same address.                                  \n
 *
 * @param[out]     pOutputD  Result contains the 8 parallel D real matrices - size NxN.
 * @param[out]     pOutputV  Result contains the 8 parallel V real matrices - size NxN.
 * @param[in]      pInput    Operand contains the 8 parallel real symmetric matrices - size NxN.
 * @param[in]      size      Number of rows and columns of input, D and V matrices: N(N>=2).
 * @param[in]      passes    Number of Jacobi iterations applied to the input matrix.
 *
 * @note           eig(matrix) = matrix matrix \n
 *                 The maximum matrix size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N <= 50. \n
 */
void Rsdk_LA_eigSy_Mof32p8Mof32p8Mif32p8(xb_vecN_2xf32 * pOutputD,
                                         xb_vecN_2xf32 * pOutputV,
                                         xb_vecN_2xf32 * pInput,
                                                uint32_t size,
                                                uint32_t passes);

/**
 * @brief          Eigen solver for complex hermitian NxN matrices - complex single precision.
 * @details        Functions computes the eigenvalues and eigenvectors for the input matrices. \n
 *                 The eigen-decomposition: A=V*D*Vt is done executing successive Jacobi rotations over
 *                 the input matrix. \n
 *                 The function assumes the the matrices are complex hermitian.The algorithm will only use
 *                 the values on and above the leading diagonal of the input matrix. \n
 *                 The output D matrix contains on the diagonal the eigenvalues, as result of the
 *                 Jacobi rotations. \n
 *                 The output V matrix columns are the eigenvectors of the input matrix. \n
 *                 The eigen vector in column k of the matrix V has the corresponding eigenvalue in the diagonal
 *                 element (k,k) of the matrix D. \n
 *                 Output can be in-place memory.                                                    \n
 *                 pOutputD and pInput can point to the same address.                                  \n
 *
 * @param[out]     pOutputD  Result contains the 8 parallel D complex matrices - size NxN.
 * @param[out]     pOutputV  Result contains the 8 parallel V complex matrices - size NxN.
 * @param[in]      pInput    Operand contains the 8 parallel complex symmetric matrices - size NxN.
 * @param[in]      size      Number of rows and columns of input, D and V matrices: N (N>=2).
 * @param[in]      passes    Number of Jacobi iterations applied to the input matrix.
 *
 * @note           eig(matrix) = matrix matrix \n
 *                 The maximum matrix size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N <= 35. \n
 */
void Rsdk_LA_eigHm_Mof32cp8Mof32cp8Mif32cp8(xb_vecN_2xcf32 * pOutputD,
                                            xb_vecN_2xcf32 * pOutputV,
                                            xb_vecN_2xcf32 * pInput,
                                                    uint32_t size,
                                                    uint32_t passes);
/** @} */

/** @addtogroup dsp_lal_api_func_eig_ql_mat
* @{
*/

/**
 * @brief              Eigen solver for real symmetric tri-diagonal NxN matrices using QL decomposition - real single precision.
 * @details            Functions computes the eigenvalues and eigenvectors for the input matrices. \n
 *                     The QL decomposition is done executing Givens rotations.                    \n
 *                     A QL iteration step is performed with implicit shifts.                      \n
 *                     The function assumes the the matrices are in symmetric tri-diagonal form.   \n
 *                     The eigen vector in column k of the matrix V has the corresponding eigenvalue in the
 *                     element k of the vector D.                                                  \n
 *                     The eigenvector matrix the eigenvectors of the symmetric tri-diagonal pInput.  \n
 *                     Typically only 2.5*N iterations are required but the cautious limit is 30*N.\n
 *                     Function is restricted to matrices with values < 1e+18 due to overflows.    \n
 *                     Output cannot be in-place memory.                                           \n
 *
 * @param[out]         pOutputD      Result contains the 8 parallel D real vectors, representing the eigenvalues - size 1xN.
 * @param[out]         pOutputV      Result contains the 8 parallel V real matrices, representing the eigenvectors - size NxN.
 * @param[in]          pInput        Operand contains the 8 parallel real matrices - size NxN.
 * @param[in]          iterations    Maximum number of iterations to be applied to the input matrix.
 * @param[in]          size          Number of rows and columns of input and V matrices and D vectors: N (N>=2).
 *
 * @note               eig(matrix) = vector(eigenvalues) matrix(eigenvectors) \n
 *                     The maximum size of N is estimated in the ideal condition that
 *                     the function use the whole memory of 256 kBytes: N < 64. \n
 */
void Rsdk_LA_eigTriDgSy_Mof32p8Mof32p8Mif32p8(xb_vecN_2xf32 * __restrict pOutputD,
                                              xb_vecN_2xf32 * __restrict pOutputV,
                                              xb_vecN_2xf32 * pInput,
											          int32_t iterations,
                                                      int32_t size);		

/**
 * @brief              Eigen solver for real symmetric tri-diagonal NxN matrices using QL decomposition - real single precision.
 * @details            Functions computes the eigenvalues and eigenvectors for the input matrices. \n
 *                     The QL decomposition is done executing Givens rotations.                    \n
 *                     A QL iteration step is performed with implicit shifts.                      \n
 *                     The function assumes the the matrices are in symmetric tri-diagonal form.   \n
 *                     The eigen vector in column k of the matrix V has the corresponding eigenvalue in the
 *                     element k of the vector D.                                                  \n
 *                     The eigenvector matrix pOutputV is passed to this function as the orthogonal Householder matrix
 *                     used to transform an initial symmetric matrix to symmetric tri-diagonal form. \n
 *                     Typically only 2.5*N iterations are required but the cautious limit is 30*N.\n
 *                     Function is restricted to matrices with values < 1e+18 due to overflows.    \n
 *                     Output cannot be in-place memory.                                           \n
 *
 * @param[out]         pOutputD      Result contains the 8 parallel D real vectors, representing the eigenvalues - size 1xN.
 * @param[in,out]      pOutputV      Operand contains the 8 parallel real Householder matrix transforms - size NxN. \n
 *                                   Result contains the 8 parallel V real matrices, representing the eigenvectors - size NxN.
 * @param[in]          pInput        Operand contains the 8 parallel real matrices - size NxN.
 * @param[in]          iterations    Maximum number of iterations to be applied to the input matrix.
 * @param[in]          size          Number of rows and columns of input and V matrices and D vectors: N (N>=2).
 *
 * @note               eig(matrix) = vector(eigenvalues) matrix(eigenvectors) \n
 *                     The maximum size of N is estimated in the ideal condition that
 *                     the function use the whole memory of 256 kBytes: N < 64. \n
 */
void Rsdk_LA_eigTriDgQHousSy_Mof32p8Mof32p8Mif32p8(xb_vecN_2xf32 * __restrict pOutputD,
                                                   xb_vecN_2xf32 * __restrict pOutputV,
                                                              xb_vecN_2xf32 * pInput,
											                          int32_t iterations,
                                                                      int32_t size);
													  
/**
 * @brief              Eigen solver for real symmetric tri-diagonal NxN matrices using QL decomposition - real single precision.
 * @details            Functions computes the eigenvalues for the input matrices. \n
 *                     The QL decomposition is done executing Givens rotations.                    \n
 *                     A QL iteration step is performed with implicit shifts.                      \n
 *                     The function assumes the the matrices are in symmetric tri-diagonal form.   \n
 *                     Typically only 2.5*N iterations are required but the cautious limit is 30*N.\n
 *                     Function is restricted to matrices with values < 1e+18 due to overflows.    \n
 *                     Output cannot be in-place memory.                                           \n
 *
 * @param[out]         pOutputD      Result contains the 8 parallel D real vectors, representing the eigenvalues - size 1xN.
 * @param[in]          pInput        Operand contains the 8 parallel real matrices - size NxN.
 * @param[in]          iterations    Maximum number of iterations to be applied to the input matrix.
 * @param[in]          size          Number of rows and columns of input and V matrices and D vectors: N (N>=2).
 *
 * @note               eigVal(matrix) = vector(eigenvalues) \n
 *                     The maximum size of N is estimated in the ideal condition that
 *                     the function use the whole memory of 256 kBytes: N < 64. \n
 */
void Rsdk_LA_eigValTriDgSy_Mof32p8Mof32p8Mif32p8(xb_vecN_2xf32 * __restrict pOutputD,
                                                 xb_vecN_2xf32 * pInput,
											    	     int32_t iterations,
                                                         int32_t size);
													 
/** @} */
					
/** @addtogroup dsp_lal_api_func_eig_QRfrancis_mat
* @{
*/
/**
 * @brief              Eigenvalues for complex upper Hessenberg form NxN matrices using Francis Algorithm - complex single precision.
 * @details            Functions computes the eigenvalues for the input matrices.                  \n
 *                     The computation is done executing Francis QR iterations.                    \n
 *                     A QR iteration step is performed with implicit shifts.                      \n
 *                     The function assumes the the matrices are in upper Hessenberg form.         \n
 *                     Typically only 3*N iterations are required but the cautious limit is 30*N.  \n
 *                     Function is restricted to matrices with values < 1e+18 due to overflows.    \n
 *                     Output cannot be in-place memory.                                           \n
 *
 * @param[out]         pOutputD      Result contains the 8 parallel D complex vectors, representing the eigenvalues - size 1xN.
 * @param[in]          pInput        Operand contains the 8 parallel complex matrices - size NxN.
 * @param[in,out]      iterations    Maximum number of iterations to be applied to the input matrix.                \n
 *                                   At the end of the algorithm it will contain the number of iterations remaining.
 * @param[in]          size          Number of rows and columns of input and D vectors: N (N>=2).
 *
 * @note               eigVal(matrix) = vector(eigenvalues) \n
 *                     The maximum size of N is estimated in the ideal condition that
 *                     the function use the whole memory of 256 kBytes: N < 64. \n
 */

void Rsdk_LA_eigValUpHess_Vof32cp8Mif32cp8(xb_vecN_2xcf32 * __restrict pOutputD,
                                                      xb_vecN_2xcf32 * pInput,
                                                            uint32_t * iterations,
                                                              uint32_t size);
/**
 * @brief              Eigen solver for complex upper Hessenberg form NxN matrices using Francis Algorithm - complex single precision.
 * @details            Functions computes the eigenvalues and eigenvectors for the input matrices. \n
 *                     The eigen-decomposition is done executing Francis QR iterations.            \n
 *                     A QR iteration step is performed with implicit shifts.                      \n
 *                     The function assumes the the matrices are in upper Hessenberg form.         \n
 *                     The eigen vector in column k of the matrix V has the corresponding eigenvalue in the
 *                     element k of the vector D.                                                  \n
 *                     Typically only 3*N iterations are required but the cautious limit is 30*N.  \n
 *                     Function is restricted to matrices with values < 1e+18 due to overflows.    \n
 *                     Output cannot be in-place memory.                                           \n
 *
 * @param[out]         pOutputD      Result contains the 8 parallel D complex vectors, representing the eigenvalues - size 1xN.
 * @param[out]         pOutputV      Result contains the 8 parallel V complex matrices, representing the eigenvectors - size NxN.
 * @param[in]          pInput        Operand contains the 8 parallel complex matrices - size NxN.
 * @param[in,out]      iterations    Maximum number of iterations to be applied to the input matrix.                \n
 *                                   At the end of the algorithm it will contain the number of iterations remaining.
 * @param[in]          size          Number of rows and columns of input and V matrices and D vectors: N (N>=2).
 *
 * @note               eig(matrix) = vector(eigenvalues) matrix(eigenvectors) \n
 *                     The maximum matrix size is estimated in the ideal condition that
 *                     the function use the whole memory of 256 kBytes: N < 45. \n
 */
void Rsdk_LA_eigUpHess_Vof32cp8Mof32cp8Mif32cp8(xb_vecN_2xcf32 * __restrict pOutputD,
                                                xb_vecN_2xcf32 * __restrict pOutputV,
                                                           xb_vecN_2xcf32 * pInput,
                                                                 uint32_t * iterations,
                                                                   uint32_t size);
/** @} */

/** @addtogroup dsp_lal_api_func_mean_vec
* @{
*/

/**
 * @brief          Arithmetic Mean - real single precision.
 * @details        Function implements arithmetic mean operation for real data vectors. \n
 *                 Output must not be in-place memory.                                 \n
 *
 * @param[out]     pOutput     Result contains a pointer to 8 parallel scalar real values.
 * @param[in]      pInput      First operand contains 8 parallel real vectors, size N.
 * @param[in]      size        Size of input vector, N.
 *
 * @note           Arithmetic mean(vector) = scalar \n
 *                 The maximum vector size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N <= 8000. \n
 */
void Rsdk_LA_avg_Sof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                           xb_vecN_2xf32 * pInput,
                                                  uint32_t size);

/**
 * @brief          Arithmetic Mean - complex single precision.
 * @details        Function implements arithmetic mean operation for complex data vectors. \n
 *                 Output must not be in-place memory.                                \n
 *
 * @param[out]     pOutput     Result contains a pointer to 8 parallel scalar complex values.
 * @param[in]      pInput      First operand contains 8 parallel complex vectors, size N.
 * @param[in]      size        Size of input vector, N.
 *
 * @note           Arithmetic mean(vector) = scalar \n
 *                 The maximum vector size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N <= 4000. \n
 */
void Rsdk_LA_avg_Sof32cp8Vif32cp8(xb_vecN_2xcf32 * __restrict pOutput,
                                            xb_vecN_2xcf32  * pInput,
                                                     uint32_t size);

/**
 * @brief          Weighted Arithmetic Mean - real single precision.
 * @details        Function implements weighted arithmetic mean operation for real data vectors. \n
 *                 Output must not be in-place memory.                                 \n
 *
 * @param[out]     pOutput      Result contains a pointer to 8 parallel scalar real values.
 * @param[in]      pInput1      First operand contains 8 parallel real vectors representing the values, size N.
 * @param[in]      pInput2      Second operand contains 8 parallel real vectors representing the weights, size N.
 * @param[in]      size         Size of input vector, N.
 *
 * @note           Weighted arithmetic mean(vector vector) = scalar \n
 *                 The maximum vector size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N <= 4000. \n
 */
void Rsdk_LA_wavg_Sof32p8Vif32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                                   xb_vecN_2xf32 * pInput1,
                                                   xb_vecN_2xf32 * pInput2,
                                                          uint32_t size);

/**
 * @brief          Weighted Arithmetic Mean - complex single precision.
 * @details        Function implements weighted arithmetic mean operation for complex data vectors. \n
 *                 Output must not be in-place memory.                                \n
 *
 * @param[out]     pOutput      Result contains a pointer to 8 parallel scalar complex values.
 * @param[in]      pInput1      First operand contains 8 parallel complex vectors representing the values, size N.
 * @param[in]      pInput2      Second operand contains 8 parallel complex vectors representing the weights, size N.
 * @param[in]      size         Size of input vector, N.
 *
 * @note           Weighted arithmetic mean(vector vector) = scalar \n
 *                 The maximum vector size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N <= 2000. \n
 */
void Rsdk_LA_wavg_Sof32cp8Vif32cp8Vif32cp8(xb_vecN_2xcf32 * __restrict pOutput,
                                                     xb_vecN_2xcf32  * pInput1,
                                                     xb_vecN_2xcf32  * pInput2,
                                                              uint32_t size);

/**
 * @brief          Harmonic Mean - real single precision.
 * @details        Function implements harmonic mean operation for real data vectors. \n
 *                 Output must not be in-place memory.                                 \n
 *
 * @param[out]     pOutput     Result contains a pointer to 8 parallel scalar real values.
 * @param[in]      pInput      First operand contains 8 parallel real vectors, size N.
 * @param[in]      size        Size of input vector, N.
 *
 * @note           Harmonic mean(vector) = scalar \n
 *                 The maximum vector size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N <= 8000. \n
 */
void Rsdk_LA_havg_Sof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                            xb_vecN_2xf32 * pInput,
                                                   uint32_t size);

/**
 * @brief          Harmonic Mean - complex single precision.
 * @details        Function implements harmonic mean operation for complex data vectors. \n
 *                 Output must not be in-place memory.                                \n
 *
 * @param[out]     pOutput     Result contains a pointer to 8 parallel scalar complex values.
 * @param[in]      pInput      First operand contains 8 parallel complex vectors, size N.
 * @param[in]      size        Size of input vector, N.
 *
 * @note           Harmonic mean(vector) = scalar \n
 *                 The maximum vector size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N <= 4000. \n
 */
void Rsdk_LA_havg_Sof32cp8Vif32cp8(xb_vecN_2xcf32 * __restrict pOutput,
                                             xb_vecN_2xcf32  * pInput,
                                                      uint32_t size);

/**
 * @brief          Root Mean Square or Quadratic Mean - real single precision.
 * @details        Function implements root mean square or quadratic mean operation for real data vectors. \n
 *                 Output must not be in-place memory.                                 \n
 *
 * @param[out]     pOutput     Result contains a pointer to 8 parallel scalar real values.
 * @param[in]      pInput      First operand contains 8 parallel real vectors, size N.
 * @param[in]      size        Size of input vector, N.
 *
 * @note           Root Mean Square(vector) = scalar \n
 *                 The maximum vector size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N <= 8000. \n
 */
void Rsdk_LA_rms_Sof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                           xb_vecN_2xf32 * pInput,
                                                  uint32_t size);

/**
 * @brief          Root Mean Square or Quadratic Mean - complex single precision.
 * @details        Function implements root mean square or quadratic mean operation for complex data vectors. \n
 *                 Output must not be in-place memory.                                \n
 *
 * @param[out]     pOutput     Result contains a pointer to 8 parallel scalar real values.
 * @param[in]      pInput      First operand contains 8 parallel complex vectors, size N.
 * @param[in]      size        Size of input vector, N.
 *
 * @note           Root Mean Square(vector) = scalar \n
 *                 The maximum vector size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N <= 8000. \n
 */
void Rsdk_LA_rms_Sof32p8Vif32cp8(xb_vecN_2xf32 * __restrict pOutput,
                                          xb_vecN_2xcf32  * pInput,
                                                   uint32_t size);
/** @} */


/** @addtogroup dsp_lal_api_func_conversions_vec_mat
* @{
*/

/**
 * @brief          Convert complex vectors into real vectors
 *                 by extracting the real part of each vector element - single precision.
 * @details        Extract and concatenate the real part of the inputs vectors.       \n
 *                 Output must not be in-place memory.                                \n
 *
 * @param[out]     pOutput     Result contains 8 parallel real vectors size N.
 * @param[in]      pInput      First operand contains 8 parallel complex vectors size N.
 * @param[in]      size        Size of input vector, N.
 *
 * @note           getRe (vector) = vector \n
 *                 The maximum vector size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N <= 2000. \n
 */
void Rsdk_DT_getRe_Vof32p8Vif32cp8(xb_vecN_2xf32 * __restrict pOutput,
                                             xb_vecN_2xcf32 * pInput,
                                                     uint32_t size);

/**
 * @brief          Convert complex vectors into real vectors
 *                 by extracting the imaginary part of each vector element - single precision.
 * @details        Extract and concatenate the imaginary part of the inputs vectors.       \n
 *                 Output must not be in-place memory.                                \n
 *
 * @param[out]     pOutput     Result contains 8 parallel real vectors size N.
 * @param[in]      pInput      First operand contains 8 parallel complex vectors size N.
 * @param[in]      size        Size of input vector, N.
 *
 * @note           getIm (vector) = vector \n
 *                 The maximum vector size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N <= 2000. \n
 */
void Rsdk_DT_getIm_Vof32p8Vif32cp8(xb_vecN_2xf32 * __restrict pOutput,
                                             xb_vecN_2xcf32 * pInput,
                                                     uint32_t size);

/**
 * @brief          Join two matrices with real elements into a matrix with complex elements - single precision.
 * @details        Interleave first matrix as real parts of the corresponding output complex
 *                 elements and second matrix as the imaginary parts, respectively. \n
 *                 First input matrix holds the real part of the complex output matrix. \n
 *                 Second input matrix holds the imaginary part of the complex output matrix. \n
 *                 This is the reverse function to Rsdk_DT_deinterl_Mof32p8Mof32p8Mif32cp8. \n
 *                 Output must not be in-place memory.                                \n
 *
 * @param[out]     pOutput     Result complex matrix size NxM.
 * @param[in]      pInput1     First operand real matrix size NxM.
 * @param[in]      pInput2     Second operand real matrix size NxM.
 * @param[in]      rows        Number of rows in input, output matrixes N.
 * @param[in]      cols        Number of columns in input, output matrixes M.
 *
 * @note           interl(real_matrix, real_matrix) = complex_matrix \n
 *                 The maximum matrix size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: NxM <= 2000. \n
 */
void Rsdk_DT_interl_Mof32cp8Mif32p8Mif32p8(xb_vecN_2xcf32 * __restrict pOutput,
                                                       xb_vecN_2xf32 * pInput1,
                                                       xb_vecN_2xf32 * pInput2,
                                                              uint32_t rows,
                                                              uint32_t cols);

/**
 * @brief          Split a complex matrix into two matrices first containing the real complex part
 *                 and second the imaginary complex part - single precision.
 * @details        Break input complex matrix in two output matrices containing real part and
 *                 imaginary part. \n
 *                 First output matrix holds the real part of the complex input matrix. \n
 *                 Second output matrix holds the imaginary part of the complex input matrix. \n
 *                 This is the reverse function to Rsdk_DT_interl_Mof32cp8Mif32p8Mif32p8. \n
 *                 Output must not be in-place memory.                                \n
 *
 * @param[out]     pOutput1    First result real matrix size NxM..
 * @param[out]     pOutput2    Second result real matrix size NxM.
 * @param[in]      pInput      Operand complex matrix size NxM.
 * @param[in]      rows        Number of rows in input, output matrixes N.
 * @param[in]      cols        Number of columns in input, output matrixes M.
 *
 * @note           deinterl(complex_matrix) = (real_matrix, real_matrix) \n
 *                 The maximum matrix size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: NxM <= 2000. \n
 */
void Rsdk_DT_deinterl_Mof32p8Mof32p8Mif32cp8(xb_vecN_2xf32 * __restrict pOutput1,
                                             xb_vecN_2xf32 * __restrict pOutput2,
                                                       xb_vecN_2xcf32 * pInput,
                                                               uint32_t rows,
                                                               uint32_t cols);

/** @} */

/** @addtogroup dsp_lal_api_func_sort_vec
* @{
*/

/**
 * @brief          Sort descending - real single precision.
 * @details        Function sorts descending real data vectors using Odd-Even transpostion or Odd-Even Sort. \n
 *                 Output must not be in-place memory vector.
 *
 * @param[out]     pOutput     Result contains 8 parallel sorted descending real vectors, size N.
 * @param[in]      pInput      Operand contains 8 parallel real vectors, size N.
 * @param[in]      size        Size of input and output vectors, N.
 *
 * @note           sortd (vector) = vector \n
 *                 The maximum vector size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N <= 4000. \n
 */
void Rsdk_AU_sortdOET_Vof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                                xb_vecN_2xf32 * pInput,
                                                       uint32_t size);

/**
 * @brief          Sort ascending - real single precision.
 * @details        Function sorts ascending real data vectors using Odd-Even transpostion or Odd-Even Sort. \n
 *                 Output must not be in-place memory vector.
 *
 * @param[out]     pOutput     Result contains 8 parallel sorted ascending real vectors, size N.
 * @param[in]      pInput      Operand contains 8 parallel real vectors, size N.
 * @param[in]      size        Size of input and output vectors, N.
 *
 * @note           sorta (vector) = vector \n
 *                 The maximum vector size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N <= 4000. \n
 */
void Rsdk_AU_sortOET_Vof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                               xb_vecN_2xf32 * pInput,
                                                      uint32_t size);

/**
 * @brief          Sort descending - real single precision.
 * @details        Function sorts descending real data vectors using Odd-Even transpostion or Odd-Even Sort. \n
 *
 * @param[in,out]  pInOut      Result/operand contains 8 parallel real vectors unsorted at the beginning of the function \n
 *                             and sorted descending at the end, size N.
 * @param[in]      size        Size of inout vectors, N.
 *
 * @note           sortd (vector) = vector \n
 *                 The maximum vector size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N <= 8000. \n
 */
void Rsdk_AU_sortdOET_Viof32p8_k2(xb_vecN_2xf32 * pInOut,
                                         uint32_t size);

/**
 * @brief          Sort ascending - real single precision.
 * @details        Function sorts ascending real data vectors using Odd-Even transpostion or Odd-Even Sort. \n
 *
 * @param[in,out]  pInOut      Result/operand contains 8 parallel real vectors unsorted at the beginning of the function \n
 *                             and sorted ascending at the end, size N.
 * @param[in]      size        Size of input and output vectors, N.
 *
 * @note           sorta (vector) = vector \n
 *                 The maximum vector size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N <= 8000. \n
 */
void Rsdk_AU_sortOET_Viof32p8_k2(xb_vecN_2xf32 * pInOut,
                                        uint32_t size);

/**
 * @brief          Element-wise compare and compute minimum and maximum values - real single precision.
 * @details        Compare each element from the first input vector with the element \n
 *                 at the same position from the second input vector, minimum result is copied in first output vector and \n
 *                 maximum is copied in second output vector. \n
 *                 Output must not be in-place memory vector. \n
 *
 * @param[out]     pOutput1     Result contains 8 parallel real vectors, representing the minimum values, size N.
 * @param[out]     pOutput2     Result contains 8 parallel real vectors, representing the maximum values, size N.
 * @param[in]      pInput1      Operand contains 8 parallel real vectors, size N.
 * @param[in]      pInput2      Operand contains 8 parallel real vectors, size N.
 * @param[in]      size         Size of input and output vectors, N.
 *
 * @note           minMax (vector, vector) = (vector, vector) \n
 *                 v1 = a1, a2..., an; \n
 *                 v2 = b1, b2..., bn; \n
 *                 minMax1 (v1,v2) =  (min (a1,b1), ..., min (an,bn); \n
 *                 minMax2 (v1,v2) =  (max (a1,b1), ..., max (an,bn); \n
 *                 minMax = (minMax1, minMax2)
 *                 The maximum vector size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N <= 2000. \n
 */
void Rsdk_DT_minMax_Vof32p8Vof32p8Vif32p8Vif32p8(xb_vecN_2xf32 * pOutput1,
                                                 xb_vecN_2xf32 * pOutput2,
                                                 xb_vecN_2xf32 * pInput1,
                                                 xb_vecN_2xf32 * pInput2,
                                                 uint32_t size);

/** @} */

/** @addtogroup dsp_lal_api_func_sp_smooth
* @{
*/

/**
 * @brief          2D Spatial smoothing correlation matrix construction for 8 parallel streams
 *                 of matrices size NxM - complex single precision.
 * @details        The function performs 2D Spatial smoothing required for ESPRIT algorithm
 *                 implementation and outputs the correlation matrix between smoothed vectors.\n
 *                 The output matrix is constructed by sliding the matrix window, size PxQ, over the
 *                 input antenna array. A vector is created for each position by concatenating the
 *                 window columns, and its outer product (v * vH) is computed. All outer products
 *                 are accumulated in the output correlation matrix.\n
 *
 * @param[out]     pOutput     Result contains 8 parallel square complex matrices, size (P*Q)x(P*Q).
 * @param[in]      pInput      First operand contains 8 parallel matrixes, size NxM.
 * @param[in]      rowsIn      Number of rows of the input matrix (N).
 * @param[in]      colsIn      Number of columns of the input matrix (M).
 * @param[in]      rowsWin     Number of rows of the smoothing window (P).
 * @param[in]      colsWin     Number of columns of the smoothing window (Q).
 *
 * @note           The maximum size for the output matrix is 35x35 defined in MAX_SP_SM_OUT_SZ.\n
 *                 The maximum input matrix size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: NxM <= 2800. \n
 *                 rowsIn      range is [2..N]\n
 *                 colsIn      range is [2..M]\n
 *                 rowsWin     range is [2..rowsIn]\n
 *                 colsWin     range is [2..colsIn]\n
 */
void Rsdk_ML_spatialSm_Mof32cp8Mif32cp8(xb_vecN_2xcf32 * pOutput,
                                  xb_vecN_2xcf32 const * pInput,
                                                uint32_t rowsIn,
                                                uint32_t colsIn,
                                                uint32_t rowsWin,
                                                uint32_t colsWin);

/** @} */

/** @addtogroup dsp_lal_func_api_dist
 * @{
 */

/**
 * @brief          Squared Normalized Euclidean distance between two vectors with 2 variables
 *                 - real single precision.
 * @details        Squared Normalized Euclidean distance between two vectors
 *                 of the same distribution with the inverse covariance matrix S pre-calculated
 *                 and diagonal. \n
 *                 Input1 vector contains 8 parallel observations for 2 variables. \n
 *                 Input2 vector contains 8 parallel references for 2 variables. \n
 *                 Input3 contains pre-calculated symmetric inverse diagonal covariance matrix S
 *                 stored as a vector c00, c11. \n
 *                 Output vector contains squared distances from first to second vector. \n
 *
 * @param[out]     pOutput     Result contains real vector size 8.
 * @param[in]      pInput1     First operand contains 8 parallel real vectors size 2.
 * @param[in]      pInput2     Second operand contains 8 parallel real vectors size 2.
 * @param[in]      pInput3     Third operand contains real vector size 2.
 *
 * @note           mahal (vector, vector) = (vector) \n
 *                       v1 = obs_x1, obs_x2, ..., obs_x8; \n
 *                            obs_y1, obs_y2, ..., obs_y8; \n
 *                       v2 = ref_x1, ref_x2, ..., ref_x8; \n
 *                            ref_y1, ref_y2, ..., ref_y8; \n
 *                       s  = c00, c11; covariance diagonal \n
 *                       di,j = (obs_xi-ref_xj)^2 * c00 + (obs_yi-ref_yj)^2 * c11; \n
 *                mahal (v1,v2) = d1,1, d2,2, ...., d8,8; \n
 *
 */
void Rsdk_LA_dist2MahalDg2_Sof32p8Vif32p8Vif32p8Vi2f32(xb_vecN_2xf32 * pOutput,
                                                 xb_vecN_2xf32 const * pInput1,
                                                 xb_vecN_2xf32 const * pInput2,
                                                     float32_t const * pInput3);

/**
 * @brief          Squared Normalized Euclidean distance between one observation with 2 variables
 *                 and multiple references - real single precision.
 * @details        Compute order 2 squared Normalized Euclidean distance between one observation
 *                 and multiple references of the same distribution with the inverse covariance
 *                 matrix S pre-calculated and diagonal. \n
 *                 First input containf one observation. \n
 *                 Second input 8 parallel streams of references. \n
 *                 Third input contains pre-calculated symmetric inverse diagonal covariance matrix S
 *                 stored as a vector c00, c11. \n
 *                 Output vector contains 8 scalar squared distances from the selected observation.
 *
 * @param[out]     pOutput     Result contains real vector size 8.
 * @param[in]      pInput1     First operand contains real vector size 2.
 * @param[in]      pInput2     Second operand contains 8 parallel real vectors size 2.
 * @param[in]      pInput3     Third operand contains real vector size 2.
 *
 * @note           mahal2 (vector, vector, vector) = vector \n
 *                 v1 = obs_x, obs_y; \n
 *                 size(v1) = 1 x 2; \n
 *                 v2 = ref_x0, ref_x1, ..., ref_x7; \n
 *                      ref_y0, ref_y1, ..., ref_y7; \n
 *                 size(v2) = 8 x 2; \n
 *                 v3 = c00, c11; covariance diagonal \n
 *                 size(v3) = 2; \n
 *                 d1j = d((obs_x, obs_y), (ref_xj, ref_yj))
 *                     = (obs_x1-ref_xj)^2 * c00 + (obs_y1-ref_yj)^2 * c11;
 *                 mahal2 (v1,v2,v3) = d11, d12, ..., d18;
 */
void Rsdk_LA_dist2MahalDg2_Sof32p8Vi2f32Vif32p8Vi2f32(xb_vecN_2xf32 * pOutput,
                                                    float32_t const * pInput1,
                                                xb_vecN_2xf32 const * pInput2,
                                                    float32_t const * pInput3);

/** @} */

/** @addtogroup dsp_lal_api_func_prod_tot
 * @{
 */

/**
 * @brief          Product of all vector elements for 8 parallel streams of vectors,
 *                 size N - real single precision.
 * @details        All elements in each vector are multiplied resulting a total product.
 *
 * @param[out]     pOutput     Result contains 8 real scalars(the product of vectors' elements).
 * @param[in]      pInput      Operand contains 8 parallel real vectors, size N.
 * @param[in]      size        Number of elements in vector (N).
 *
 * @note           element eprod (vector) = scalar \n
 *                 n = elem_cnt \n
 *                 v = n, a1, a2..., an; \n
 *                 eprod(v) = a1 * a2 * ... * an;
 *                 The maximum vector size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N <= 8000. \n
 */
void Rsdk_LA_prod_Sof32p8Vif32p8(xb_vecN_2xf32 * pOutput,
                           xb_vecN_2xf32 const * pInput,
                                        uint32_t size);

/**
 * @brief          Product of all vector elements for 8 parallel streams of vectors,
 *                 size N - complex single precision.
 * @details        All elements in each vector are multiplied resulting a total product.
 *
 * @param[out]     pOutput     Result contains 8 complex scalars(the product of vectors' elements).
 * @param[in]      pInput      Operand contains 8 parallel complex vectors, size N.
 * @param[in]      size        Number of elements in vector (N).
 *
 * @note           element eprod (vector) = scalar \n
 *                 n = elem_cnt \n
 *                 v = n, a1, a2..., an; \n
 *                 eprod(v) = a1 * a2 * ... * an;
 *                 The maximum vector size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N <= 4000. \n
 */
void Rsdk_LA_prod_Sof32cp8Vif32cp8(xb_vecN_2xcf32 * pOutput,
                             xb_vecN_2xcf32 const * pInput,
                                           uint32_t size);

/** @} */

/** @addtogroup dsp_lal_api_func_hessenberg_mat
* @{
*/

/**
 * @brief          Upper Hessenberg reduction for NxN matrices - real single precision.
 * @details        Function reduces a real general purpose matrix to the upper Hessenberg form using Householder \n
 *                 reflection or Householder transformations. \n
 *                 pOutputP * pOutputH * pOutputP ^T = pInput \n
 *                 pOutputH and pInput can point to the same address.
 *
 *
 * @param[out]     pOutputP    Result contains 8 parallel orthogonal real matrices, size N. \n
 *                             pOutputP is an orthogonal matrix.
 * @param[out]     pOutputH    Result contains 8 parallel upper Hessenberg real matrices, size N. \n
 *                             They have zero entries below the first subdiagonal.
 * @param[in]      pInput      Operand contains 8 parallel real matrices, size N.
 * @param[in,out]  pBuffer     Scratch area contains 8 parallel real vectors, size N.
 * @param[in]      size        Size of input and output vectors, N >= 3.
 *
 * @note           upHess (matrix) = (matrixP, matrixH) \n
 *                 The maximum matrix/vector size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N <= 50. \n
 */
void Rsdk_LA_decQUpHessQHousSq_Mof32p8Mof32p8Mif32p8(xb_vecN_2xf32 * pOutputP,
                                                     xb_vecN_2xf32 * pOutputH,
                                                     xb_vecN_2xf32 * pInput,
                                                     xb_vecN_2xf32 * pBuffer,
                                                     uint32_t size);

/**
 * @brief          Upper Hessenberg reduction for NxN matrices - complex single precision.
 * @details        Function reduces a complex general purpose matrix to the upper Hessenberg form using Householder \n
 *                 reflection or Householder transformations. \n
 *                 pOutputP * pOutputH * pOutputP ^T = pInput \n
 *                 pOutputH and pInput can point to the same address.
 *
 *
 * @param[out]     pOutputP    Result contains 8 parallel orthogonal complex matrices, size N. \n
 *                             pOutputP is an unitary matrix.
 * @param[out]     pOutputH    Result contains 8 parallel upper Hessenberg complex matrices, size N. \n
 *                             They have zero entries below the first subdiagonal.
 * @param[in]      pInput      Operand contains 8 parallel complex matrices, size N.
 * @param[in,out]  pBuffer     Scratch area contains 8 parallel complex vectors, size N.
 * @param[in]      size        Size of input and output vectors, N >= 3.
 *
 * @note           upHess (matrix) = (matrixP, matrixH) \n
 *                 The maximum matrix/vector size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N <= 35. \n
 */
void Rsdk_LA_decQUpHessQHousSq_Mof32cp8Mof32cp8Mif32cp8(xb_vecN_2xcf32 * pOutputP,
                                                        xb_vecN_2xcf32 * pOutputH,
                                                        xb_vecN_2xcf32 * pInput,
                                                        xb_vecN_2xcf32 * pBuffer,
                                                        uint32_t size);
/** @} */

/** @addtogroup dsp_lal_api_func_copy
 * @{
 */

/**
 * @brief          Copy 8 parallel streams of vectors - real single precision.
 * @details        Copies the vectors from an 8 parallel streams vectors buffer,
 *                 pInput, to another 8 parallel streams vectors buffer, pOutput.
 *                 Output and input must not be in-place memory. \n
 *
 * @param[out]     pOutput     Result contains 8 parallel real vectors, size N.
 * @param[in]      pInput      Operand contains 8 parallel real vectors, size N.
 * @param[in]      size        Number of elements in vector (N).
 *
 * @note           copy(vector) = vector \n
 *                 The maximum vector size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N <= 4000. \n
 */
void Rsdk_DT_copy_Vof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                 xb_vecN_2xf32 * __restrict pInput,
                                                   uint32_t size);

/**
 * @brief          Copy 8 parallel streams of vectors - complex single precision.
 * @details        Copies the vectors from an 8 parallel streams vectors buffer,
 *                 pInput, to another 8 parallel streams vectors buffer, pOutput.
 *                 Output and input must not be in-place memory. \n
 *
 * @param[out]     pOutput     Result contains 8 parallel complex vectors, size N.
 * @param[in]      pInput      Operand contains 8 parallel complex vectors, size N.
 * @param[in]      size        Number of elements in vector (N).
 *
 * @note           copy(vector) = vector \n
 *                 The maximum vector size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N <= 2000. \n
 */
void Rsdk_DT_copy_Vof32cp8Vif32cp8(xb_vecN_2xcf32 * __restrict pOutput,
                                   xb_vecN_2xcf32 * __restrict pInput,
                                                      uint32_t size);

/**
 * @brief          Copy matrices - real single precision.
 * @details        Function copy the values from input matrices into the output matrices. \n
 *                 Output and input must not be in-place memory. \n
 *
 * @param[out]     pOutput     Result contains 8 parallel real matrices, size NxM.
 * @param[in]      pInput      Operand contains 8 parallel real matrices, size NxM.
 * @param[in]      rows        Rows of input and output matrices, N.
 * @param[in]      cols        Columns of input and output matrices, M.
 *
 * @note           copy(matrix) = matrix \n
 *                 The maximum matrix size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: NxM <= 4000. \n
 */
void Rsdk_DT_copy_Mof32p8Mif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                 xb_vecN_2xf32 * __restrict pInput,
                                                   uint32_t rows,
                                                   uint32_t cols);

/**
 * @brief          Copy matrices - complex single precision.
 * @details        Function copy the values from input matrices into the output matrices. \n
 *                 Output and input must not be in-place memory. \n
 *
 * @param[out]     pOutput     Result contains 8 parallel complex matrices, size NxM.
 * @param[in]      pInput      Operand contains 8 parallel complex matrices, size NxM.
 * @param[in]      rows        Rows of input and output matrices, N.
 * @param[in]      cols        Columns of input and output matrices, M.
 *
 * @note           copy(matrix) = matrix \n
 *                 The maximum matrix size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: NxM <= 2000. \n
 */
void Rsdk_DT_copy_Mof32cp8Mif32cp8(xb_vecN_2xcf32 * __restrict pOutput,
                                   xb_vecN_2xcf32 * __restrict pInput,
                                                      uint32_t rows,
                                                      uint32_t cols);

/**
 * @brief          Copy a number of vector elements from an 8 parallel streams buffer to
 *                 the vectors in another 8 parallel streams buffer with/without offsets -
 *                 real single precision.
 * @details        Copies numElem elements from the vectors in pInput buffer, starting with inOffset
 *                 position, to the pOutput buffer vectors, starting with the outOffset position.
 *                 Output vectors' elements in range [outOffset, outOffset + numElem -1]
 *                 are overwritten by numElem elements from the corresponding input vector,
 *                 starting with inOffset index: [inOffset, inOffset + numElem - 1].\n
 *                 Both buffers are treated as linear infinite memory zones. This means that
 *                 if the payload to copy is numElem, the output's length is
 *                 P < numElem + outOffset and/or the input's length is N < numElem + inOffset,
 *                 the copying will continue until all numElem input elements are copied
 *                 regardless of buffers' sizes.\n
 *                 If inOffset is 0, copying will start from the first element of the vectors.\n
 *                 If outOffset is 0, writting will start at the first element of the vectors.\n
 *                 Output and input must not be in-place memory. \n
 *
 * @param[out]     pOutput     Result contains 8 parallel real vectors, size P.
 * @param[in]      pInput      Operand contains 8 parallel real vector size N.
 * @param[in]      numElem     Number of elements to copy from input vectors to output vectors.
 * @param[in]      outOffset   Output vectors' element index where the input vector elements will be written.
 * @param[in]      inOffset    Input vectors' element index from which the elements will be copied.
 *
 * @note           copy(input, output) = output which contains the numElem elements
 *                 from the input buffer, starting at inOffset, from outOffset onwards.\n
 *                 in  = a0, a1, ..., a(N-1); \n
 *                 out = b0, b1, ..., b(P-1); \n
 *                 copy(in,out) = b0, b1, b2, ........., b(outOffset-2), b(outOffset-1),
 *                                a(inOffset), a(inOffset+1) ..., a(inOffset+numElem-1),
 *                                b(outOffset-1+numElem), b(outOffset+numElem), ... \n\n
 *
 *                 A practical use-case is copying elements from a vector input to a matrix output.
 *                 For this example, note that:\n
 *                  - Dimensions for both matrix and vector are disregarded.\n
 *                  - If the matrix's dimensionality is m x n, it is indexed as a (m * n) size vector,
 *                    from 0 to (m * n - 1). \n
 *                 The maximum vectors' size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N+P <= 8000. \n
 *                 numElem     range is [1.. minimum(N,P)] \n
 *                 outOffset   range is [0..P] \n
 *                 inOffset    range is [0..N] \n
 */
void Rsdk_DT_copyOffset_Vof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                 xb_vecN_2xf32 const * __restrict pInput,
                                              uint32_t numElem,
                                              uint32_t outOffset,
                                              uint32_t inOffset);

/**
 * @brief          Copy a number of vector elements from an 8 parallel streams buffer to
 *                 the vectors in another 8 parallel streams buffer with/without offsets -
 *                 complex single precision.
 * @details        Copies numElem elements from the vectors in pInput buffer, starting with inOffset
 *                 position, to the pOutput buffer vectors, starting with the outOffset position.
 *                 Output vectors' elements in range [outOffset, outOffset + numElem - 1]
 *                 are overwritten by numElem elements from the corresponding input vector,
 *                 starting with inOffset index: [inOffset, inOffset + numElem - 1].\n
 *                 Both buffers are treated as linear infinite memory zones. This means that
 *                 if the payload to copy is numElem, the output's length is
 *                 P < numElem + outOffset and/or the input's length is N < numElem + inOffset,
 *                 the copying will continue until all numElem input elements are copied
 *                 regardless of buffers' sizes.\n
 *                 If inOffset is 0, copying will start from the first element of the vectors.\n
 *                 If outOffset is 0, writing will start at the first element of the vectors. \n
 *                 Output and input must not be in-place memory. \n
 *
 * @param[out]     pOutput     Result contains 8 parallel complex vector size P.
 * @param[in]      pInput      Operand contains 8 parallel complex vector size N.
 * @param[in]      numElem     Number of elements to copy from input vectors to output vectors.
 * @param[in]      outOffset   Output vectors' element index where the input vector elements will be written.
 * @param[in]      inOffset    Input vectors' element index from which the elements will be copied.
 *
 * @note           copy(input, output) = output which contains the numElem elements
 *                 from the input buffer, starting at inOffset, from outOffset onwards.\n
 *                 in  = a0, a1, ..., a(N-1); \n
 *                 out = b0, b1, ..., b(P-1); \n
 *                 copy(in,out) = b0, b1, b2, ........., b(outOffset-2), b(outOffset-1),
 *                                a(inOffset), a(inOffset+1) ..., a(inOffset+numElem-1),
 *                                b(outOffset-1+numElem), b(outOffset+numElem), ... \n\n
 *
 *                 A practical use-case is copying elements from a vector input to a matrix output.
 *                 For this example, note that:\n
 *                  - Dimensions for both matrix and vector are disregarded.\n
 *                  - If the matrix's dimensionality is m x n, it is indexed as a (m * n) size vector,
 *                    from 0 to (m * n - 1).
 *                 The maximum vectors' size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N+P <= 4000. \n
 *                 numElem     range is [1..minimum(N,P)] \n
 *                 outOffset   range is [0..P] \n
 *                 inOffset    range is [0..N] \n
 */
void Rsdk_DT_copyOffset_Vof32cp8Vif32cp8(xb_vecN_2xcf32 * __restrict pOutput,
                                   xb_vecN_2xcf32 const * __restrict pInput,
                                                 uint32_t numElem,
                                                 uint32_t outOffset,
                                                 uint32_t inOffset);

/**
 * @brief          Copy a number of vector elements from an 8 parallel streams buffer starting with
 *                 an offset at the beginning of the vectors in another 8 parallel streams buffer -
 *                 real single precision.
 * @details        Copies numElem elements from the vectors in pInput buffer, starting from inOffset
 *                 position, to pOutput buffer vectors, starting with the first element.
 *                 Output vectors' elements in range [0, numElem -1] are overwritten by
 *                 numElem elements from the corresponding input vector, starting with
 *                 inOffset index: [inOffset, inOffset + numElem - 1].\n
 *                 Both buffers are treated as linear infinite memory zones. This means that if the
 *                 payload to copy is numElem and the output's length is P < numElem and/or the
 *                 input's length is N < inOffset + numElem, the copying will continue until all
 *                 numElem elements are copied regardless of buffers' sizes.\n
 *                 If inOffset is 0, copying will start from the first element of the vectors.\n
 *                 Output and input must not be in-place memory. \n
 *
 * @param[out]     pOutput     Result contains 8 parallel real vectors, size P.
 * @param[in]      pInput      Operand contains 8 parallel real vector size N.
 * @param[in]      numElem     Number of elements to copy from input vectors to output vectors.
 * @param[in]      inOffset    Input vectors' element index from which the elements will be copied.
 *
 * @note           copy(input, output) = output which contains the numElem elements
 *                 from the input buffer, starting at inOffset, from outOffset onwards.\n
 *                 in  = a0, a1, ..., a(N-1); \n
 *                 out = b0, b1, ..., b(P-1); \n
 *                 copy(in,out) = a(inOffset), a(inOffset+1), ..., a(inOffset+numElem-1),
 *                                b(numElem),  b(numElem+1), ........ \n\n
 *
 *                 A practical use-case is copying elements from a vector input to a matrix output.
 *                 For this example, note that:\n
 *                  - Dimensions for both matrix and vector are disregarded.\n
 *                  - If the matrix's dimensionality is m x n, it is indexed as a (m * n) size
 *                    vector, from 0 to (m * n - 1). \n
 *                 The maximum vectors' size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N+P <= 8000. \n
 *                 numElem     range is [1..minimum(N,P)] \n
 *                 inOffset    range is [0..N] \n
 */
void Rsdk_DT_copyInOffset_Vof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                   xb_vecN_2xf32 const * __restrict pInput,
                                                uint32_t numElem,
                                                uint32_t inOffset);

/**
 * @brief          Copy a number of vector elements from an 8 parallel streams buffer starting with
 *                 an offset at the begining of the vectors in another 8 parallel streams buffer -
 *                 complex single precision.
 * @details        Copies numElem elements from the vectors in pInput buffer, starting from inOffset
 *                 position, to pOutput buffer vectors, starting with the first element.
 *                 Output vectors' elements in range [0, numElem -1] are overwritten by
 *                 numElem elements from the corresponding input vector, starting with
 *                 inOffset index: [inOffset, inOffset + numElem - 1].\n
 *                 Both buffers are treated as linear infinite memory zones. This means that if the
 *                 payload to copy is numElem and the output's length is P < numElem and/or the
 *                 input's length is N < inOffset + numElem, the copying will continue until all
 *                 numElem elements are copied regardless of buffers' sizes.\n
 *                 If inOffset is 0, copying will start from the first element of the vectors.\n
 *                 Output and input must not be in-place memory. \n
 *
 * @param[out]     pOutput     Result contains 8 parallel complex vector size P.
 * @param[in]      pInput      Operand contains 8 parallel complex vector size N.
 * @param[in]      numElem     Number of elements to copy from input vectors to output vectors.
 * @param[in]      inOffset    Input vectors' element index from which the elements will be copied.
 *
 * @note           copy(input, output) = output which contains the numElem elements
 *                 from the input buffer, starting at inOffset, from outOffset onwards.\n
 *                 in  = a0, a1, ..., a(N-1); \n
 *                 out = b0, b1, ..., b(P-1); \n
 *                 copy(in,out) = a(inOffset), a(inOffset+1), ..., a(inOffset+numElem-1),
 *                                b(numElem),  b(numElem+1), ........ \n\n
 *
 *                 A practical use-case is copying elements from a vector input to a matrix output.
 *                 For this example, note that:\n
 *                  - Dimensions for both matrix and vector are disregarded.\n
 *                  - If the matrix's dimensionality is m x n, it is indexed as a (m * n) size
 *                    vector, from 0 to (m * n - 1).
 *                 The maximum vectors' size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N+P <= 4000. \n
 *                 numElem     range is [1..minimum(N,P)] \n
 *                 inOffset    range is [0..N] \n
 */
void Rsdk_DT_copyInOffset_Vof32cp8Vif32cp8(xb_vecN_2xcf32 * __restrict pOutput,
                                     xb_vecN_2xcf32 const * __restrict pInput,
                                                   uint32_t numElem,
                                                   uint32_t inOffset);

/**
 * @brief          Copy a number of elements from the vectors in an 8 parallel streams buffer to the
 *                 vectors in another 8 parallel streams buffer starting with an offset -
 *                 real single precision.
 * @details        Copies numElem elements from the vectors in the pInput buffer, starting with the
 *                 first element, to the pOutput buffer vectors, starting with the outOffset position.
 *                 Output vectors' elements in range [outOffset, outOffset + numElem -1]
 *                 are overwritten by numElem elements from the corresponding input vector,
 *                 starting with inOffset index: [0, numElem - 1].\n
 *                 Both buffers are treated as linear infinite memory zones. This means that if the
 *                 payload to copy is numElem, the output's useful length is P < numElem +
 *                 outOffset and the input's useful length is N < numElem, the copying will continue
 *                 until all numElem input elements are copied regardless of buffers' sizes.\n
 *                 If outOffset is 0, writting will start at the first element of the vectors.\n
 *                 Output and input must not be in-place memory. \n
 *
 * @param[out]     pOutput     Result contains 8 parallel real vectors, size P.
 * @param[in]      pInput      Operand contains 8 parallel real vector size N.
 * @param[in]      numElem     Number of elements to copy from input vectors to output vectors.
 * @param[in]      outOffset   Output vectors' element index where the input vector elements will be written.
 *
 * @note           copy(input, output) = output which contains the numElem elements
 *                 from the input buffer, starting at inOffset, from outOffset onwards.\n
 *                 in  = a0, a1, ..., a(N-1); \n
 *                 out = b0, b1, ..., b(P-1); \n
 *                 copy(in,out) = b0, b1, ........, b(outOffset-1),
 *                                a(inOffset), ..., a(inOffset+numElem-1), .. \n\n
 *
 *                 A practical use-case is copying elements from a vector input to a matrix output.
 *                 For this example, note that:\n
 *                  - Dimensions for both matrix and vector are disregarded.\n
 *                  - If the matrix's (useful) dimensionality is m x n, it is indexed as a (m * n) size vector,
 *                    from 0 to (m * n - 1).
 *                 The maximum vectors' size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N+P <= 8000. \n
 *                 numElem     range is [1..minimum(N,P)] \n
 *                 outOffset   range is [0..P] \n
 */
void Rsdk_DT_copyOutOffset_Vof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                    xb_vecN_2xf32 const * __restrict pInput,
                                                 uint32_t numElem,
                                                 uint32_t outOffset);

/**
 * @brief          Copy a number of elements from the vectors in an 8 parallel streams buffer to the
 *                 vectors in another 8 parallel streams buffer starting with an offset -
 *                 complex single precision.
 * @details        Copies numElem elements from the vectors in the pInput buffer, starting with the
 *                 first element, to the pOutput buffer vectors, starting with the outOffset position.
 *                 Output vectors' elements in range [outOffset, outOffset + numElem -1]
 *                 are overwritten by numElem elements from the corresponding input vector,
 *                 starting with inOffset index: [0, numElem - 1].\n
 *                 Both buffers are treated as linear infinite memory zones. This means that if the
 *                 payload to copy is numElem and the output's useful length is P < numElem +
 *                 outOffset and the input's useful length is N < numElem, the copying will continue
 *                 until all numElem input elements are copied regardless of buffers' sizes.\n
 *                 If outOffset is 0, writting will start at the first element of the vectors.\n
 *                 Output and input must not be in-place memory.\n
 *
 * @param[out]     pOutput     Result contains 8 parallel complex vector size P.
 * @param[in]      pInput      Operand contains 8 parallel complex vector size N.
 * @param[in]      numElem     Number of elements to copy from input vectors to output vectors.
 * @param[in]      outOffset   Output vectors' element index where the input vector elements will be written.
 *
 * @note           copy(input, output) = output which contains the numElem elements
 *                 from the input buffer, starting at inOffset, from outOffset onwards.\n
 *                 in  = a0, a1, ..., a(N-1); \n
 *                 out = b0, b1, ..., b(P-1); \n
 *                 copy(in,out) = b0, b1, ........, b(outOffset-1),
 *                                a(inOffset), ..., a(inOffset+numElem-1), .. \n\n
 *
 *                 A practical use-case is copying elements from a vector input to a matrix output.
 *                 For this example, note that:\n
 *                  - Dimensions for both matrix and vector are disregarded.\n
 *                  - If the matrix's (useful) dimensionality is m x n, it is indexed as a (m * n) size vector,
 *                    from 0 to (m * n - 1).
 *                 The maximum vectors' size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N+P <= 4000. \n
 *                 numElem     range is [1..minimum(N,P)] \n
 *                 outOffset   range is [0..P] \n
 */
void Rsdk_DT_copyOutOffset_Vof32cp8Vif32cp8(xb_vecN_2xcf32 * __restrict pOutput,
                                      xb_vecN_2xcf32 const * __restrict pInput,
                                                    uint32_t numElem,
                                                    uint32_t outOffset);

/** @} */


/** @addtogroup dsp_lal_api_func_polinom
* @{
*/

/**
 * @brief          Polynoms evaluation(the 8 polynoms are defined by 8 parallel streams of real
 *                 coeficient vectors, size N+1) for 8 corresponding variable's values - real
 *                 single precision.
 * @details        The function evaluates the polynomial functions for a real value of the variable.\n
 *                 Each polynomial function is defined by the vector of the real values of the
 *                 coeficients arranged in descending order.\n
 *                 The polynoms have the same degree, N.\n
 *
 * @param[out]     pOutput     Result contains the 8 parallel evaluation results P(x), real scalars.
 * @param[in]      pInput1     First operand contains 8 parallel real coeficients' vectors, size N+1.
 * @param[in]      pInput2     Second operand contains 8 real scalar variables.
 * @param[in]      degree      The polinomyals' degree, N.
 *
 * @note           The maximum vector size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N <= 8000. \n
 */
void Rsdk_LA_polinomEval_Sof32p8Vif32p8Sif32p8(xb_vecN_2xf32 * pOutput,
                                         xb_vecN_2xf32 const * pInput1,
                                         xb_vecN_2xf32 const * pInput2,
                                                      uint32_t degree);

/** @} */

/** @addtogroup dsp_lal_api_func_snr
 * @{
 */

/**
 * @brief          Element-wise signal-to-noise ratio or SNR in dB - real single precision.
 * @details        Compute Signal to noise ratio of signal and noise real vectors. \n
 *                 output[k] = 10*log10( | input1[k]/input2[k] | )
 *
 * @param[out]     pOutput     Result real vector size N.
 * @param[in]      pInput1     First operand real vector size N.
 * @param[in]      pInput2     Second operand real vector size N.
 * @param[in]      size        Number of elements in vector (N).
 *
 * @note           signal-to-noise ratio (vector, vector) = vector \n
 *                 v1 = n, a1, a2, ..., an; \n
 *                 v2 = n, b1, b2, ..., bn; \n
 *                 SNR (v1,v2) = n, 10*log10(|a1/b1|),... ,10*log10(|an/bn|); \n
 *                 The maximum vectors' size is estimated in the ideal condition that
 *                 the function use the whole memory of 256 kBytes: N <= 2730. \n
 */
void Rsdk_SP_SNR_Vof32p8Vif32p8Vif32p8(xb_vecN_2xf32 * pOutput,
                                 xb_vecN_2xf32 const * pInput1,
                                 xb_vecN_2xf32 const * pInput2,
                                              uint32_t size);

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* RSDK_DSP_LAL_H_ */
