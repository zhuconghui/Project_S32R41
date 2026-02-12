/**************************************************************************************************
 * Copyright 2017 - 2024 NXP
 **************************************************************************************************
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be
 * used strictly in accordance with the applicable license terms.  By expressly accepting such
 * terms or by downloading, installing, activating and/or otherwise using the software, you are
 * agreeing that you have read, and that you agree to comply with and are bound by, such license
 * terms. If you do not agree to be bound by the applicable license terms, then you may not retain,
 * install, activate or otherwise use the software.
 **************************************************************************************************/

#ifndef RSDK_CMODEL_LIB_FUNCTIONS_H_
#define RSDK_CMODEL_LIB_FUNCTIONS_H_


/**
 * @file           rsdk_cmodel_lib_functions.h
 * @brief          C Library model for low level functions API
 */

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "rsdk_c_types.h"

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#ifdef C_MODEL_DLL
/* macro used to build the dll*/
#define C_MODEL_DLL __declspec(dllexport)
#elif C_MODEL_STATIC_LIB
/* for building and using the C model static library */
#define C_MODEL_DLL
#else
/* for using the the C model dll*/
#define C_MODEL_DLL __declspec(dllimport)
#endif

#define VECTOR_SIZE_4 (4U)
#define VECTOR_SIZE_8 (8U)
#define VECTOR_SIZE_16 (16U)
#define VECTOR_SIZE_32 (32U)
#define VECTOR_SIZE_64 (64U)

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


/* VCPU kernel start here*/
/*==================================================================================================
 * FILL, SET
 ==================================================================================================*/

/* TO DO group c_functions_model_fill */
/* TO DO Rsdk_EF_fillZeros_Vof32c */
/* TO DO Rsdk_EF_fillZeros_Vof32 */
/* TO DO Rsdk_EF_fill_Vof32cSif32c  */
/* TO DO Rsdk_EF_fill_Vof32Sif32  */



/*==================================================================================================
 * Complex conjugate
 ==================================================================================================*/
/** @addtogroup c_functions_model_conj
* @{
*/

/**
* @brief          Compute the complex conjugate of each element in a
*                   complex single precision vector
* @details        output[k] = input[k].real - input[k].imag
*
* @param[out]     output      Output memory area.
* @param[in]      input       Input vector.
* @param[in]      size        Number of elements in vector.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_conj_Vof32cVif32c(rsdk_complex_float32_t * output,
                                               rsdk_complex_float32_t const * input,
                                                                     uint32_t size);

/**
* @brief          Conjugate NxM matrix - real single precision
* @details        N, M can take any value
*                 inputs and outputs are stored row-major order.
*
* @param[out]     output      Output memory area.
* @param[in]      input       Input matrix to be conjugated.
* @param[in]      rows        Number of rows. (>0)
* @param[in]      cols        Number of columns. (>0)
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_conj_Mof32cMif32c(rsdk_complex_float32_t * output,
                                               rsdk_complex_float32_t const * input,
                                                                     uint32_t rows,
                                                                     uint32_t cols);

/** @}*/

/*==================================================================================================
 * ABS
 ==================================================================================================*/
/** @addtogroup c_functions_model_absolute_value
* @{
*/

/**
* @brief          Element-wise vector absolute value of a real vector - single precision.
* @details        Calculate the absolute value of all elements in input vector.  \n
*                 Input vector is assumed padded to the nearest memory line.     \n
*                 All output elements are positive (sign ignored).               \n
*                 output[k] = |input[k]|                                         \n
*
*
* @param[out]     pOutput     Output real vector ptr.
* @param[in]      pInput      Input real vector ptr.
* @param[in]      size        Number of elements in vector, interval [0..65535].
*
*
* @return         void
*
* @note           abs (vector) = vector \n
*                 v = n, a1, a2, ..., an; \n
*                 abs (v) = n, |a1|, |a2|, ..., |an|; \n
*
*/
void __stdcall C_MODEL_DLL Rsdk_LA_abs_Vof32Vif32(float * pOutput,
                                            float const * pInput,
                                                 uint32_t size);

/**
* @brief          Element-wise absolute squared value of a complex vector - single precision.
* @details        Calculate the absolute value also known as complex norm,      \n
*                 modulus, or magnitude of all input elements.                  \n
*                 Input vector is assumed padded to the nearest memory line.    \n
*                 Output vector is real, with positive values (sign ignored).   \n
*                 output[k] = input.re[k]*input.re[k] + input.im[k]*input.im[k] \n
*
* @param[out]     pOutput     Output real vector ptr.
* @param[in]      pInput      Input complex vector ptr.
* @param[in]      size        Length of pInput (useful length).
*
* @return         void
*
* @note           abs2 (vector) = vector \n
*                 v = n, a1.re, a1.im, ..., an.re, an.im; \n
*                 abs2 (v) = n, ((a1.re^2)+(a1.im^2)), ..., ((an.re^2)+(an.im^2)); ; \n
*
*/
void __stdcall C_MODEL_DLL Rsdk_LA_abs2_Vof32Vif32c(float * pOutput,
                             rsdk_complex_float32_t const * pInput,
                                                   uint32_t size);

/**
 * @brief          Absolute squares of a complex matrix - single precision
 *
 * @param[out]     pOutput     Output real matrix ptr.
 * @param[in]      pInput      Input complex matrix ptr.
 * @param[in]      numRows     Number of rows of input and output matrices.
 * @param[in]      numCols     Number of columns of input and output matrices.
 *
 * @return         void
 *
 * @note           matrix element absolute square (matrix) = matrix \n
 *                 M = [a_11 a_12 ... a_1n; ... a_m1 a_m2 ... a_mn]; \n
 *                 dim(abs_square(M)) = dim(M) = m * n; \n
 *                 abs_square(M) = [(abs(a_11))^2 (abs(a_12))^2 ... (abs(a_1n))^2; ...
 *                                  (abs(a_m1))^2 (abs(a_m2))^2 ... (abs(a_mn))^2];
 *
 */
void __stdcall C_MODEL_DLL Rsdk_LA_abs2_Mof32Mif32c(float * pOutput,
                             rsdk_complex_float32_t const * pInput,
                                                   uint32_t numRows,
                                                   uint32_t numCols);
/** @}*/

/*==================================================================================================
 * ADD
 ==================================================================================================*/
/** @addtogroup c_functions_model_add
* @{
*/

/**
* @brief          Add the elements of a complex single precision vector by a complex scalar
* @details        output[k] = input1[k] .+ input2
*
* @param[out]     output      Output memory area.
* @param[in]      input1      Input vector.
* @param[in]      input2      Input scalar.
* @param[in]      size        Number of elements in vector.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_add_Vof32cVif32cSif32c(rsdk_complex_float32_t * output,
                                                    rsdk_complex_float32_t const * input1,
                                                    rsdk_complex_float32_t const * input2,
                                                                          uint32_t size);
/* TO DO Rsdk_LA_add_Vof32cVif32cSif32c_k2 */
/* TO DO Rsdk_LA_addCells_Vof32cVif32cVif32cViu32 */
/**
* @brief          Add the elements of a real single precision vector by a real scalar
* @details        output[k] = input1[k] .+ input2
*
* @param[out]     output      Output memory area.
* @param[in]      input1      Input vector.
* @param[in]      input2      Input scalar.
* @param[in]      size        Number of elements in vector.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_add_Vof32Vif32Sif32(float * output,
                                                 float const * input1,
                                                 float const * input2,
                                                      uint32_t size);

/* TO DO Rsdk_LA_add_Vof32Vif32Sif32_k2 */
/**
* @brief          Add elements of two complex single precision vectors
* @details        output[k] = input1[k] + input2[k]
*
* @param[out]     output      Output memory area.
* @param[in]      input1      Input vector 1.
* @param[in]      input2      Input vector 2.
* @param[in]      size        Number of elements in vector.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_add_Vof32cVif32cVif32c(rsdk_complex_float32_t * output,
                                                    rsdk_complex_float32_t const * input1,
                                                    rsdk_complex_float32_t const * input2,
                                                                          uint32_t size);

/* TO DO Rsdk_LA_add_Vof32cVif32cVif32c_k2 */
/**
* @brief          Add elements of two real single precision vectors
* @details        output[k] = input1[k] + input2[k]
*
* @param[out]     output      Output memory area.
* @param[in]      input1      Input vector 1.
* @param[in]      input2      Input vector 2.
* @param[in]      size        Number of elements in vector.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_add_Vof32Vif32Vif32(float * output,
                                                 float const * input1,
                                                 float const * input2,
                                                     uint32_t size);
/* TO DO Rsdk_LA_add_Vof32Vif32Vif32_k2 */
/* TO DO Rsdk_LA_add_Mof32cMif32cMif32c */
/* TO DO Rsdk_LA_add_Mof32Mif32Mif32 */
/* TO DO Rsdk_LA_add_Mof32Mif32Sif32 */
/* TO DO Rsdk_LA_add_Mof32cMif32cSif32c */

/** @}*/

/*==================================================================================================
 * SUB
 ==================================================================================================*/
/** @addtogroup c_functions_model_sub
* @{
*/

/**
* @brief          Subtract elements of two complex single precision vectors
* @details        output[k] = input1[k] - input2[k]
*
* @param[out]     output      Output memory area.
* @param[in]      input1      Input vector 1.
* @param[in]      input2      Input vector 2.
* @param[in]      size        Number of elements in vector.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_sub_Vof32cVif32cVif32c(rsdk_complex_float32_t * output,
                                                    rsdk_complex_float32_t const * input1,
                                                    rsdk_complex_float32_t const * input2,
                                                           uint32_t size);

/**
* @brief          Subtract elements of two real single precision vectors
* @details        output[k] = input1[k] - input2[k]
*
* @param[out]     output      Output memory area.
* @param[in]      input1      Input vector 1.
* @param[in]      input2      Input vector 2.
* @param[in]      size        Number of elements in vector.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_sub_Vof32Vif32Vif32(float * output,
                                                 float const * input1,
                                                 float const * input2,
                                                      uint32_t size);
/* TO DO Rsdk_LA_sub_Mof32cMif32cMif32c */
/* TO DO Rsdk_LA_sub_Mof32Mif32Mif32 */
/** @}*/

/*==================================================================================================
 * DOT, CROSS
 ==================================================================================================*/
/** @addtogroup c_functions_model_dot
* @{
*/

/**
* @brief          Compute the dot product of two complex single precision vectors
* @details        output = sum(conj(input1[k]) .* input2[k])
*
* @param[out]     output      Output memory area.
* @param[in]      input1      Input vector 1.
* @param[in]      input2      Input vector 2.
* @param[in]      size        Number of elements in vector.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_dot_Sof32cVif32cVif32c(rsdk_complex_float32_t * output,
                                                    rsdk_complex_float32_t const * input1,
                                                    rsdk_complex_float32_t const * input2,
                                                                          uint32_t size);
/* TO DO Rsdk_LA_dotFirstConj_Sof32cVif32cVif32c */
/**
* @brief          Compute the dot product of two complex single precision vectors
* @details        output = sum(conj(input1[k]) .* input2[k])
*
* @param[out]     output      Output memory area.
* @param[in]      input1      Input vector 1.
* @param[in]      input2      Input vector 2.
* @param[in]      size        Number of elements in vector.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_dot_Sof32Vif32Vif32(float * output,
                                                 float const * input1,
                                                 float const * input2,
                                                      uint32_t size);
/** @}*/

/** @addtogroup c_functions_model_cross_prod
* @{
*/

/**
* @brief          Compute the cross product of two complex single precision vectors
* @details        output = input1 x input2
*
* @param[out]     output      Output memory area.
* @param[in]      input1      Input vector 1.
* @param[in]      input2      Input vector 2.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_cross_Vo3f32cVi3f32cVi3f32c(rsdk_complex_float32_t * output,
                                                         rsdk_complex_float32_t const * input1,
                                                         rsdk_complex_float32_t const * input2);

/**
* @brief          Compute the cross product of two real single precision vectors
* @details        output = input1 x input2
*
* @param[out]     output      Output memory area.
* @param[in]      input1      Input vector 1.
* @param[in]      input2      Input vector 2.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_cross_Vo3f32Vi3f32Vi3f32(float * output,
                                                      float const * input1,
                                                      float const * input2);
/** @}*/

/*==================================================================================================
 * Correlation, cross correlation or sliding dot product or sliding inner-product.
 ==================================================================================================*/
/** @addtogroup c_functions_model_xcorr
* @{
*/

/**
* @brief          Compute the cross correlation between two complex single precision vectors
* @details        output = xcorr(input1, input2)
*
* @param[out]     output      Output memory area.
* @param[in]      input1      Input vector 1.
* @param[in]      input2      Input vector 2.
* @param[in]      size1       Number of elements in vector 1.
* @param[in]      size2       Number of elements in vector 2.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_xcorr_Vof32cVif32cVif32c(rsdk_complex_float32_t * output,
                                                      rsdk_complex_float32_t const * input1,
                                                      rsdk_complex_float32_t const * input2,
                                                                      uint32_t const size1,
                                                                      uint32_t const size2);

/**
* @brief          Compute the cross correlation between two real single precision vectors
* @details        output = xcorr(input1, input2)
*
* @param[out]     output      Output memory area.
* @param[in]      input1      Input vector 1.
* @param[in]      input2      Input vector 2.
* @param[in]      size1       Number of elements in vector 1.
* @param[in]      size2       Number of elements in vector 2.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_xcorr_Vof32Vif32Vif32(float * output,
                                                   float const * input1,
                                                   float const * input2,
                                                  uint32_t const size1,
                                                  uint32_t const size2);
/** @}*/

/*==================================================================================================
 * MUL
 ==================================================================================================*/
/** @addtogroup c_functions_model_mpy
* @{
*/

/**
* @brief          Multiply elements of a complex single precision vector with a complex scalar
* @details        output[k] = input1[k] .* input2
*
* @param[out]     output      Output memory area.
* @param[in]      input1      Input vector.
* @param[in]      input2      Input scalar.
* @param[in]      size        Number of elements in vector.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_mul_Vof32cVif32cSif32c(rsdk_complex_float32_t * output,
                                                    rsdk_complex_float32_t const * input1,
                                                    rsdk_complex_float32_t const * input2,
                                                                          uint32_t size);
/* TO DO Rsdk_LA_mulFirstConj_Vof32cVif32cSif32c */
/**
* @brief          Multiply elements of a real single precision vector with a real scalar
* @details        output[k] = input1[k] .* input2
*
* @param[out]     output      Output memory area.
* @param[in]      input1      Input vector.
* @param[in]      input2      Input scalar.
* @param[in]      size        Number of elements in vector.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_mul_Vof32Vif32Sif32(float * output,
                                                 float const * input1,
                                                 float const * input2,
                                                      uint32_t size);
/**
* @brief          Element-wise multiplication of two complex single precision vectors
* @details        output[k] = input1[k] .* innput2[k]
*
* @param[out]     output      Output memory area.
* @param[in]      input1      Input vector 1.
* @param[in]      input2      Input vector 2.
* @param[in]      size        Number of elements in vector.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_mul_Vof32cVif32cVif32c(rsdk_complex_float32_t * output,
                                                    rsdk_complex_float32_t const * input1,
                                                    rsdk_complex_float32_t const * input2,
                                                                          uint32_t size);

/**
* @brief          Element-wise multiplication of two real single precision vectors
* @details        output[k] = input1[k] .* innput2[k]
*
* @param[out]     output      Output memory area.
* @param[in]      input1      Input vector 1.
* @param[in]      input2      Input vector 2.
* @param[in]      size        Number of elements in vector.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_mul_Vof32Vif32Vif32(float * output,
                                                 float const * input1,
                                                 float const * input2,
                                                      uint32_t size);
/**
* @brief          Multiply NxM matrix by MxQ matrix - complex single precision
* @details        N, M, Q can take any value
*                 inputs and outputs are stored row-major order.
*
* @param[out]     output      Output memory area.
* @param[in]      input1      Input matrix first operand.
* @param[in]      input2      Input matrix second operand.
* @param[in]      in1h        Number of rows of first matrix. (>0)
* @param[in]      in1w        Number of columns of first matrix and rows of second matrix. (>0)
* @param[in]      in2w        Number of columns of second matrix. (>0)
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_mul_Mof32cMif32cMif32c(rsdk_complex_float32_t * output,
                                                    rsdk_complex_float32_t const * input1,
                                                    rsdk_complex_float32_t const * input2,
                                                                          uint32_t in1h,
                                                                          uint32_t in1w,
                                                                          uint32_t in2w);

/**
* @brief          Multiply NxM matrix by Mx1 vector - complex single precision
* @details        N and M can take any value.
*
* @param[out]     output      Output memory area.
* @param[in]      input1      Input matrix first operand stored row-major order.
* @param[in]      input2      Input matrix second operand.
* @param[in]      in1h        Number of rows of matrix.
* @param[in]      in1w        Number of columns matrix and elements in vector.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_mul_Vof32cMif32cVif32c(rsdk_complex_float32_t * output,
                                                    rsdk_complex_float32_t const * input1,
                                                    rsdk_complex_float32_t const * input2,
                                                                          uint32_t in1h,
                                                                          uint32_t in1w);
/**
* @brief          Multiply NxM matrix by MxQ matrix - real single precision
* @details        N, M, Q can take any value
*                 inputs and outputs are stored row-major order.
*
* @param[out]     output      Output memory area.
* @param[in]      input1      Input matrix first operand.
* @param[in]      input2      Input matrix second operand.
* @param[in]      in1h        Number of rows of first matrix. (>0)
* @param[in]      in1w        Number of columns of first matrix and rows of second matrix. (>0)
* @param[in]      in2w        Number of columns of second matrix. (>0)
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_mul_Mof32Mif32Mif32(float * output,
                                                 float const * input1,
                                                 float const * input2,
                                                      uint32_t in1h,
                                                      uint32_t in1w,
                                                      uint32_t in2w);

/**
* @brief          Multiply NxM matrix by Mx1 vector - real single precision
* @details        N and M can take any value.
*
* @param[out]     output      Output memory area.
* @param[in]      input1      Input matrix first operand stored row-major order.
* @param[in]      input2      Input matrix second operand.
* @param[in]      in1h        Number of rows of matrix.
* @param[in]      in1w        Number of columns matrix and elements in vector.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_mul_Vof32Mif32Vif32(float * output,
                                                 float const * input1,
                                                 float const * input2,
                                                      uint32_t in1h,
                                                      uint32_t in1w);

/**
 * @brief          Outer product - real single precision.
 * @details        Each vector is multiplied by corresponding vector to output the outer product.
 *                 First element is multiplied by all of the second vector's elements and so on.
 *                 The results is a real matrices. \n
 *                 a cross b = C[i,j] = a[i] * b[j] = a^T * b
 *
 * @param[out]     pOutput     Result contains a real matrixes size MxN.
 * @param[in]      pInput1     First operand contains a real vectors size M.
 * @param[in]      pInput2     Second operand contains a real vectors size N.
 * @param[in]      size1       Number of elements of first input vector (M).
 * @param[in]      size2       Number of elements of second input vector (N).
 *
 * @return         void
 */
void __stdcall C_MODEL_DLL Rsdk_LA_outerProd_Mof32Vif32Vif32(float * pOutput,
                                                       float const * pInput1,
                                                       float const * pInput2,
                                                            uint32_t size1,
                                                            uint32_t size2);

/**
 * @brief          Outer product - complex single precision.
 * @details        Each vector is multiplied by corresponding vector to output the outer product.
 *                 First element is multiplied by all of the second vector's elements and so on.
 *                 The results is a complex matrices. \n
 *                 a cross b = C[i,j] = a[i] * b[j] = a^T * b
 *
 * @param[out]     pOutput     Result contains a complex matrixes size MxN.
 * @param[in]      pInput1     First operand contains a complex vectors size M.
 * @param[in]      pInput2     Second operand contains a complex vectors size N.
 * @param[in]      size1       Number of elements of first input vector (M).
 * @param[in]      size2       Number of elements of second input vector (N).
 *
 * @return         void
 */
void __stdcall C_MODEL_DLL Rsdk_LA_outerProd_Mof32cVif32cVif32c(rsdk_complex_float32_t * pOutput,
                                                          rsdk_complex_float32_t const * pInput1,
                                                          rsdk_complex_float32_t const * pInput2,
                                                                                uint32_t size1,
                                                                                uint32_t size2);

/**
* @brief          Multiply conjugate NxM matrix by Mx1 vector - complex single precision
* @details        N and M can take any value.
*
* @param[out]     output      Output memory area.
* @param[in]      input1      Input matrix first operand stored row-major order.
* @param[in]      input2      Input matrix second operand.
* @param[in]      in1h        Number of rows of matrix.
* @param[in]      in1w        Number of columns matrix and elements in vector.
*
* @return         void
*/
void __stdcall C_MODEL_DLL  Rsdk_LA_mulFirstConj_Vof32cMif32cVif32c(rsdk_complex_float32_t * output,
                                                              rsdk_complex_float32_t const * input1,
                                                              rsdk_complex_float32_t const * input2,
                                                                                    uint32_t in1h,
                                                                                    uint32_t in1w);
/* TO DO Rsdk_LA_mulSecondConj_Vof32cMif32cVif32c */
/**
* @brief          Multiply conjugate NxM matrix by conjugate MxQ matrix - complex single precision
* @details        N, M, Q can take any value
*                 inputs and outputs are stored row-major order.
*
* @param[out]     output      Output memory area.
* @param[in]      input1      Input matrix first operand.
* @param[in]      input2      Input matrix second operand.
* @param[in]      in1h        Number of rows of first matrix. (>0)
* @param[in]      in1w        Number of columns of first matrix and rows of second matrix. (>0)
* @param[in]      in2w        Number of columns of second matrix. (>0)
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_mulConjConj_Mof32cMif32cMif32c(rsdk_complex_float32_t * output,
                                                            rsdk_complex_float32_t const * input1,
                                                            rsdk_complex_float32_t const * input2,
                                                                                  uint32_t in1h,
                                                                                  uint32_t in1w,
                                                                                  uint32_t in2w);

/**
* @brief          Multiply conjugate NxM matrix by MxQ matrix - complex single precision
* @details        N, M, Q can take any value
*                 inputs and outputs are stored row-major order.
*
* @param[out]     output      Output memory area.
* @param[in]      input1      Input matrix first operand.
* @param[in]      input2      Input matrix second operand.
* @param[in]      in1h        Number of rows of first matrix. (>0)
* @param[in]      in1w        Number of columns of first matrix and rows of second matrix. (>0)
* @param[in]      in2w        Number of columns of second matrix. (>0)
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_mulFirstConj_Mof32cMif32cMif32c(rsdk_complex_float32_t * output,
                                                             rsdk_complex_float32_t const * input1,
                                                             rsdk_complex_float32_t const * input2,
                                                                                   uint32_t in1h,
                                                                                   uint32_t in1w,
                                                                                   uint32_t in2w);
/* TO DO Rsdk_LA_mulSecondConj_Mof32cMif32cMif32c */
/** @}*/

/*==================================================================================================
 * MAC
 ==================================================================================================*/

/** @addtogroup c_functions_model_mac
 * @{
 */

/**
* @brief          Multiply elements of a complex single precision vectors with a complex scalar
*                   and add the elements of another complex single precision vector
* @details        output[k] = input1[k] * input2 + input3[i]
*
* @param[out]     output      Output memory area.
* @param[in]      input1      Input vector 1.
* @param[in]      input2      Input scalar.
* @param[in]      input3      Input vector 3.
* @param[in]      size        Number of elements in vector.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_mac_Vof32cVif32cSif32cVif32c(rsdk_complex_float32_t * output,
                                                          rsdk_complex_float32_t const * input1,
                                                          rsdk_complex_float32_t const * input2,
                                                          rsdk_complex_float32_t const * input3,
                                                                                uint32_t size);

/**
* @brief          Multiply elements of a real single precision vectors with a real scalar
*                   and add the elements of another real single precision vector
* @details        output[k] = input1[k] * input2 + input3[i]
*
* @param[out]     output      Output memory area.
* @param[in]      input1      Input vector 1.
* @param[in]      input2      Input scalar.
* @param[in]      input3      Input vector 3.
* @param[in]      size        Number of elements in vector.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_mac_Vof32Vif32Sif32Vif32(float * output,
                                                      float const * input1,
                                                      float const * input2,
                                                      float const * input3,
                                                           uint32_t size);

/**
* @brief          Multiply elements of a complex single precision vectors with a complex scalar
*                   and add the elements of another complex single precision vector
* @details        output[k] = input1[k] * input2[i] + input3[i]
*
* @param[out]     output      Output memory area.
* @param[in]      input1      Input vector 1.
* @param[in]      input2      Input vector 2.
* @param[in]      input3      Input vector 3.
* @param[in]      size        Number of elements in vector.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_mac_Vof32cVif32cVif32cVif32c(rsdk_complex_float32_t * output,
                                                          rsdk_complex_float32_t const * input1,
                                                          rsdk_complex_float32_t const * input2,
                                                          rsdk_complex_float32_t const * input3,
                                                                                uint32_t size);

/**
* @brief          Multiply elements of a real single precision vectors with a real scalar
*                   and add the elements of another real single precision vector
* @details        output[k] = input1[k] * input2[i] + input3[i]
*
* @param[out]     output      Output memory area.
* @param[in]      input1      Input vector 1.
* @param[in]      input2      Input vector 2.
* @param[in]      input3      Input vector 3.
* @param[in]      size        Number of elements in vector.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_mac_Vof32Vif32Vif32Vif32(float * output,
                                                      float const * input1,
                                                      float const * input2,
                                                      float const * input3,
                                                           uint32_t size);
/* TO DO Rsdk_LA_mac_Mof32Mif32Mif32Mif32 */
/* TO DO Rsdk_LA_mac_Mof32cMif32cMif32cMif32c */
/** @}*/

/*==================================================================================================
 * DIV
 ==================================================================================================*/
/** @addtogroup c_functions_model_div
* @{
*/

/**
* @brief          Divide the elements of two complex single precision vectors
* @details        output[k] = input1[k] ./ input2[k]
*
* @param[out]     output      Output memory area.
* @param[in]      input1      Input vector 1.
* @param[in]      input2      Input vector 2.
* @param[in]      size        Number of elements in vector.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_div_Vof32cVif32cVif32c(rsdk_complex_float32_t * output,
                                                    rsdk_complex_float32_t const * input1,
                                                    rsdk_complex_float32_t const * input2,
                                                                          uint32_t size);
/**
* @brief          Divide the elements of two real single precision vectors
* @details        output[k] = input1[k] ./ input2[k]
*
* @param[out]     output      Output memory area.
* @param[in]      input1      Input vector 1.
* @param[in]      input2      Input vector 2.
* @param[in]      size        Number of elements in vector.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_div_Vof32Vif32Vif32(float * output,
                                                 float const * input1,
                                                 float const * input2,
                                                      uint32_t size);

/**
* @brief          Divide the elements of a complex single precision vector by a complex scalar
* @details        output[k] = input1[k] ./ input2
*
* @param[out]     output      Output memory area.
* @param[in]      input1      Input vector.
* @param[in]      input2      Input scalar.
* @param[in]      size        Number of elements in vector.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_div_Vof32cVif32cSif32c(rsdk_complex_float32_t * output,
                                                    rsdk_complex_float32_t const * input1,
                                                    rsdk_complex_float32_t const * input2,
                                                                          uint32_t size);

/**
* @brief          Divide the elements of a real single precision vector by a real scalar
* @details        output[k] = input1[k] ./ input2
*
* @param[out]     output      Output memory area.
* @param[in]      input1      Input vector.
* @param[in]      input2      Input scalar.
* @param[in]      size        Number of elements in vector.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_div_Vof32Vif32Sif32(float * output,
                                                 float const * input1,
                                                 float const * input2,
                                                      uint32_t size);
/** @}*/

/** @addtogroup c_functions_model_rcp
* @{
*/

/**
* @brief          Element-wise vector reciprocal, rcp.
* @details        Compute Reciprocal, rcp of each vector real elements. \n
*                 output[k] = 1 / input[k]  \n
*
*
* @param[out]     pOutput     Output vector ptr.
* @param[in]      pInput      Input vector ptr.
* @param[in]      size        Number of elements in vector, interval [1..65535].
*
* @return         void
*/

void __stdcall C_MODEL_DLL Rsdk_EF_rcp_Vof32Vif32(float * pOutput,
                                            float const * pInput,
                                                 uint32_t size);
/* TO DO  Rsdk_EF_rcp_Vof32Vif32_k2 */
/** @}*/

/*==================================================================================================
 * Matrix inverse
 ==================================================================================================*/

/** @addtogroup c_functions_model_inv
* @{
*/

/**
* @brief          Inverse of NxN matrix - complex single precision
* @details        Function uses Gaussian elimination with partial pivoting.
*
* @param[out]     output      Output memory area.
* @param[in]      input1      Input matrix.
* @param[in]      scratch     Scratch area. Same size as input buffer.
* @param[in]      size        Size of input matrix (number of rows/columns).
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_invGausCPNs_Mof32cMif32c(rsdk_complex_float32_t * output,
                                                      rsdk_complex_float32_t const * input1,
                                                            rsdk_complex_float32_t * scratch,
                                                                            uint32_t size);

/**
* @brief          Inverse of NxN matrix - complex single precision - high accuracy
* @details        Function uses Gaussian elimination with partial pivoting.
*                 Same C model implementation as Rsdk_LA_invGausCPNs_Mof32cMif32c(),
*
* @param[out]     output      Output memory area.
* @param[in]      input1      Input matrix.
* @param[in]      scratch     Scratch area. Same size as input buffer.
* @param[in]      size        Size of input matrix (number of rows/columns).
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_invGausCPNs_Mof32cMif32c_k2(rsdk_complex_float32_t * output,
                                                         rsdk_complex_float32_t const * input1,
                                                               rsdk_complex_float32_t * scratch,
                                                                               uint32_t size);

/**
* @brief          Inverse of NxN matrix - real single precision
* @details        Function uses Gaussian elimination with partial pivoting.
*
* @param[out]     output      Output memory area.
* @param[in]      input1      Input matrix.
* @param[in]      scratch     Scratch area. Same size as input buffer.
* @param[in]      size        Size of input matrix.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_invGausCPNs_Mof32Mif32(float * output,
                                                    float const * input1,
                                                          float * scratch,
                                                         uint32_t size);

/**
* @brief          Inverse of NxN matrix - real single precision - high accuracy
* @details        Function uses Gaussian elimination with partial pivoting.
*                 Same C model implementation as Rsdk_LA_invGausCPNs_Mof32Mif32(),
*
* @param[out]     output      Output memory area.
* @param[in]      input1      Input matrix.
* @param[in]      scratch     Scratch area. Same size as input buffer.
* @param[in]      size        Size of input matrix.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_invGausCPNs_Mof32Mif32_k2(float * output,
                                                       float const * input1,
                                                             float * scratch,
                                                            uint32_t size);

/**
* @brief          Inverse of NxN upper triangular matrices - complex single precision
* @details        Function uses backward substitution.\n
*
* @param[out]     output      Output memory area.
* @param[in]      input1      Input matrix.
* @param[in]      size        Size of input matrix.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_invUNs_Mof32cMif32c(rsdk_complex_float32_t * output,
                                                 rsdk_complex_float32_t const * input1,
                                                                       uint32_t size);

/**
* @brief          Inverse of NxN upper triangular matrices - real single precision
* @details        Function uses backward substitution.\n
*
* @param[out]     output      Output memory area.
* @param[in]      input1      Input matrix.
* @param[in]      size        Size of input matrix.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_invUNs_Mof32Mif32(float * output,
                                               float const * input1,
                                                    uint32_t size);

/**
* @brief          Inverse of NxN lower triangular matrices - complex single precision
* @details        Function uses backward substitution.\n
*
* @param[out]     output      Output memory area.
* @param[in]      input1      Input matrix.
* @param[in]      size        Size of input matrix.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_invLNs_Mof32cMif32c(rsdk_complex_float32_t * output,
                                                 rsdk_complex_float32_t const * input1,
                                                                       uint32_t size);

/**
* @brief          Inverse of NxN lower triangular matrices - complex single precision
* @details        Function uses backward substitution.\n
*
* @param[out]     output      Output memory area.
* @param[in]      input1      Input matrix.
* @param[in]      size        Size of input matrix.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_invLNs_Mof32Mif32(float * output,
                                               float const * input1,
                                                    uint32_t size);

/** @} */

/*==================================================================================================
 * Matrix determinant
 ==================================================================================================*/

/** @addtogroup c_functions_model_det
* @{
*/

/**
* @brief          Determinant of NxN matrix - complex single precision
* @details        Function uses Gaussian elimination starting from last column
*
* @param[out]     output      Output memory area.
* @param[in]      input1      Input matrix.
* @param[in]      scratch     Scratch area. Same size as input buffer.
* @param[in]      size        Size of input matrix (number of rows/columns).
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_detSq_Sof32cMif32c(rsdk_complex_float32_t * output,
                                                rsdk_complex_float32_t const * input1,
                                                      rsdk_complex_float32_t * scratch,
                                                                      uint32_t size);

/**
* @brief          Determinant of NxN matrix - real single precision
* @details        Function uses Gaussian elimination starting from last column
*
* @param[out]     output      Output memory area.
* @param[in]      input1      Input matrix.
* @param[in]      scratch     Scratch area. Same size as input buffer.
* @param[in]      size        Size of input matrix (number of rows/columns).
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_detSq_Sof32Mif32(float * output,
                                              float const * input1,
                                                    float * scratch,
                                                   uint32_t size);
/** @}*/

/*==================================================================================================
 * Matrix Solvers
 ==================================================================================================*/

/** @addtogroup c_functions_model_triang_solver
* @{
*/

/**
* @brief          Solve Lx=b for b - real single precision
* @details        Matrix L is lower triangular. Function works column wise.
*
* @param[out]     pOutx       Output solved vector.
* @param[in]      pInLLT      Input symetric real matrix.
* @param[in]      pInb        Input vector.
* @param[in]      size        Size of input matrix (number of rows/columns, elem in vector x, b).
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_solveSyL_Vof32Mif32Vif32(float * pOutx,
                                                      float const * pInLLT,
                                                      float const * pInb,
                                                           uint32_t size);

/**
* @brief          Solve Lx=b for b - real single precision, accuracy mode
* @details        Matrix L is lower triangular. Function works column wise.
*
* @param[out]     pOutx       Output solved vector.
* @param[in]      pInLLT      Input symetric real matrix.
* @param[in]      pInb        Input vector.
* @param[in]      size        Size of input matrix (number of rows/columns, elem in vector x, b).
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_solveSyL_Vof32Mif32Vif32_k2(float * pOutx,
                                                         float const * pInLLT,
                                                         float const * pInb,
                                                              uint32_t size);

/**
* @brief          Solve Ux=b for b - real single precision
* @details        Matrix U is upper triangular. Function works column wise.
*
* @param[out]     pOutx       Output solved vector.
* @param[in]      pInLLT      Input symetric real matrix.
* @param[in]      pInb        Input vector.
* @param[in]      size        Size of input matrix (number of rows/columns, elem in vector x, b).
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_solveSyU_Vof32Mif32Vif32(float * pOutx,
                                                      float const * pInLLT,
                                                      float const * pInb,
                                                           uint32_t size);

/**
* @brief          Solve Ux=b for b - real single precision, accuracy mode
* @details        Matrix U is upper triangular. Function works column wise.
*
* @param[out]     pOutx       Output solved vector.
* @param[in]      pInLLT      Input symetric real matrix.
* @param[in]      pInb        Input vector.
* @param[in]      size        Size of input matrix (number of rows/columns, elem in vector x, b).
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_solveSyU_Vof32Mif32Vif32_k2(float * pOutx,
                                                         float const * pInLLT,
                                                         float const * pInb,
                                                              uint32_t size);
/** @}*/

/*==================================================================================================
 * Eigen solvers
 ==================================================================================================*/

/** @addtogroup c_functions_model_eigen
* @{
*/

/**
* @brief          Eigen solver for symmetric NxN matrix - real single precision.
* @details        The eigen-decomposition: A=V*D*Vt is done executing successive Jacobi rotations over
*                 the input matrix.
*                 The function assumes the the matrices are real symmetric. The algorithm will only use
*                 the values on and above the leading diagonal of the input matrix. \n
*                 The input matrix must be real symmetric. However, the algorithm will only use the
*                 values on and above the leading diagonal. \n
*                 The output D matrix contains on the diagonal the eigenvalues, as result of the
*                 Jacobi rotations. \n
*                 The output V matrix columns are the eigenvectors of the input matrix. The eigenvector
*                 in column k of the matrix V has the corresponding eigenvalue in the diagonal
*                 element (k,k) of the matrix D. \n
*                 In order to reduce memory usage, pInput and pOutputD may point to the same address-inplace. \n
*                 V*D*Vt = input \n
*
* @param[out]     pOutputD  Pointer to the output buffer containing the D matrix - size NxN.
* @param[out]     pOutputV  Pointer to the output buffer containing th V matrix - size NxN.
* @param[in]      pInput    Pointer to the input buffer containing the symmetric matrix - size NxN..
* @param[in]      size      Number of rows/columns in input, D and V matrices: N.
* @param[in]      passes    Number of Jacobi iterations applied to the input matrix.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_eigSy_Mof32Mof32Mif32(float * pOutputD,
                                                         float * pOutputV,
                                                         float * pInput,
                                                        uint32_t size,
                                                        uint32_t passes);
/**
* @brief          Eigensolver for NxN matrix - complex hermitian single precision - 2<=N
* @details        The function will perform successive passes over the matrix, doing Jacobi rotations.
*                 The eigenvalues of the matrix can be found on the diagonal of the output D matrix,
*                 which is the result of the Jacobi rotations. The eigenvectors are the columns of the
*                 output V matrix. The eigenvector in column k of the matrix V has the corresponding
*                 eigenvalue in element k,k of the matrix D.
*                 input1, outptutD and outputV should point to size by size complex matrices. Either
*                 outputV or outputD pointers may point to the same memory area as input1.  \n
*                 The input matrix must be complex hermitian. However, the algorithm will only use the
*                 values on and above the leading diagonal.
*
* @param[out]     outputD     Output memory area for D matrix.
* @param[out]     outputV     Output memory area for V matrix.
* @param[in]      input1      Input matrix.
* @param[in]      size        Size of matrices (>=2)
* @param[in]      passes      Number of passes of Jacobi rotations over whole matrix.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_eigHm_Mof32cMof32cMif32c(rsdk_complex_float32_t * outputD,
                                                            rsdk_complex_float32_t * outputV,
                                                      rsdk_complex_float32_t const * input1,
                                                                            uint32_t size,
                                                                            uint32_t passes);

/**
* @brief          Eigensolver for NxN matrix - complex normal (including unitary) single precision - 2<=N
* @details        The function will perform successive passes over the matrix, doing Jacobi rotations.
*                 The eigenvalues of the matrix can be found on the diagonal of the output D matrix,
*                 which is the result of the Jacobi rotations. The eigenvectors are the columns of the
*                 output V matrix. The eigenvector in column k of the matrix V has the corresponding
*                 eigenvalue in element k,k of the matrix D. \n
*                 input1, outptutD and outputV should point to size by size complex matrices. Either
*                 outputV or outputD pointers may point to the same memory area as input1.
*
* @param[out]     outputD     Output memory area for D matrix.
* @param[out]     outputV     Output memory area for V matrix.
* @param[in]      input1      Input matrix.
* @param[in]      size        Size of matrices (>=2)
* @param[in]      passes      Number of passes of Jacobi rotations over whole matrix.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_eigNm_Mof32cMof32cMif32c(rsdk_complex_float32_t * outputD,
                                                            rsdk_complex_float32_t * outputV,
                                                      rsdk_complex_float32_t const * input1,
                                                                            uint32_t size,
                                                                            uint32_t passes);

/**
* @brief          Eigenvalues solver for NxN matrix - complex single precision - 2<=N
* @details        The function uses Francis QR iteration algorithm to determine the eigenvalues
*                 of a complex upper Hessenberg matrix M.
*                 The eigenvalues of the matrix will be found in the output vector.
*
* @param[out]     pOutput    Output memory area for output vector with complex eigenvalues, size 1xN. \n
* @param[in,out]  pInput     Input matrix, complex data, size NxN. \n
*                            The matrix content is destroyed during processing.
* @param[in,out]  iterations As an input parameter, this is the  maximum number of iterations ,
*                            where the recommended value is 30*size, a cautious limit to allow convergence,
*                            though, typically only 3*size iterations are necessary.
*                            As an output parameter, it contains the number of remaining iterations.
* @param[in]      size       Number of rows and columns of input matrix and output vector: N (N>=2)
*
* @return         void
*
* @note           eigVal(matrix) = vector(eigenvalues)
*/
void __stdcall C_MODEL_DLL Rsdk_LA_eigValUpHess_Vof32cMif32c(rsdk_complex_float32_t *  pOutput,
                                                              rsdk_complex_float32_t * pInput,
                                                                            uint32_t * iterations,
                                                                              uint32_t size);

/**
* @brief          Eigenvalues and eigenvectors solver for NxN matrix - complex single precision - 2<=N
* @details        The function uses Francis QR iteration algorithm to determine the eigenvalues
*                 of a complex upper Hessenberg matrix M.
*                 The eigenvalues of the matrix will be found in the output vector.
*
* @param[out]     pOutputD   Output memory area for output vector with complex eigenvalues, size 1xN. \n
* @param[out]     pOutputV   Output memory area for output matrix with complex eigenvectors,size NxN. \n
* @param[in,out]  pInput     Input matrix, complex data, size NxN. \n
*                            The matrix content is destroyed during processing.
* @param[in,out]  iterations As an input parameter, this is the  maximum number of iterations ,
*                            where the recommended value is 30*size, a cautious limit to allow convergence,
*                            though, typically only 3*size iterations are necessary.
*                            As an output parameter, it contains the number of remaining iterations.
* @param[in]      size       Number of rows and columns of input matrix and output vector: N (N>=2)
*
* @return         void
*
* @note           eigVal(matrix) = vector(eigenvalues) matrix(eigenvectors)
*/
void __stdcall C_MODEL_DLL Rsdk_LA_eigUpHess_Vof32cMof32cMif32c(rsdk_complex_float32_t *  pOutputD,
                                                  rsdk_complex_float32_t *  pOutputV,
                                                  rsdk_complex_float32_t * pInput,
                                                                uint32_t * iterations,
                                                                  uint32_t size);
/** @} */

/*==================================================================================================
 * Cholesky decomposition
 ==================================================================================================*/

/** @addtogroup c_functions_model_cholesky
 * @{
 */

/**
* @brief          Cholesky decomposition for NxN matrix - complex hermitian single precision.
* @details        Applies Cholesky decomposition on positive definite hermitian input matrix
*                 and returns upper triangular matrix with positive real values on the leading
*                 diagonal. Both the input and output matrices are assumed to be square. Size must
*                 not be smaller than 2.
*
* @param[out]     pOutput     Output complex matrix ptr.
* @param[in]      pInput      Input complex matrix ptr.
* @param[in]      size    Size of matrices (>= 2).
*
* @return         void
*
*/
void __stdcall C_MODEL_DLL Rsdk_LA_decUUCholPd_Mof32cMif32c(rsdk_complex_float32_t * pOutput,
                                                      rsdk_complex_float32_t const * pInput,
                                                                            uint32_t size);

/**
* @brief          Cholesky decomposition for NxN matrix - complex hermitian single precision.
*                 Accuracy kernel version
* @details        Applies Cholesky decomposition on positive definite hermitian input matrix
*                 and returns upper triangular matrix with positive real values on the leading
*                 diagonal. Both the input and output matrices are assumed to be square. Size must
*                 not be smaller than 2.
*
* @param[out]     pOutput     Output complex matrix ptr.
* @param[in]      pInput      Input complex matrix ptr.
* @param[in]      size    Size of matrices (>= 2).
*
* @return         void
*
*/
void __stdcall C_MODEL_DLL Rsdk_LA_decUUCholPd_Mof32cMif32c_k2(rsdk_complex_float32_t * pOutput,
                                                         rsdk_complex_float32_t const * pInput,
                                                                               uint32_t size);

/**
* @brief          Cholesky decomposition for NxN matrix - real symmetric single precision.
* @details        Applies Cholesky decomposition on real symmetric input matrix and returns upper
*                 triangular matrix with positive values on the leading diagonal. Both the input
*                 and output matrices are assumed to be square. Size must not be smaller than 2.
*
* @param[out]     pOutput     Output real matrix ptr.
* @param[in]      pInput      Input real matrix ptr.
* @param[in]      size    Size of matrices (>= 2).
*
* @return         void
*
*/
void __stdcall C_MODEL_DLL Rsdk_LA_decUUCholPd_Mof32Mif32(float * pOutput,
                                                    float const * pInput,
                                                         uint32_t size);

/**
* @brief          Cholesky decomposition for NxN matrix - real symmetric single precision.
*                 Accuracy kernel version
* @details        Applies Cholesky decomposition on real symmetric input matrix and returns upper
*                 triangular matrix with positive values on the leading diagonal. Both the input
*                 and output matrices are assumed to be square. Size must not be smaller than 2.
*
* @param[out]     pOutput     Output real matrix ptr.
* @param[in]      pInput      Input real matrix ptr.
* @param[in]      size    Size of matrices (>= 2).
*
* @return         void
*
*/
void __stdcall C_MODEL_DLL Rsdk_LA_decUUCholPd_Mof32Mif32_k2(float * pOutput,
                                                       float const * pInput,
                                                            uint32_t size);
/** @}*/

/*==================================================================================================
 * QR decomposition
 ==================================================================================================*/
/** @addtogroup c_functions_model_qrdec
* @{
*/
/**
* @brief          QR decomposition of a matrix.
*
* @details        Calculate the Q and R matrix whith M=Q*R using the Householder algorithm.\n
*                 Input is a matrix M[m][n].                                               \n
*                 Output R[m][n] is an upper triangular matrix.                            \n
*                 Output Q[m][m] is a quadratic matrix.                                    \n
*                 M[m][n] = Q[m][m]* R[m][n]                                               \n
*                 m and n shall respect the following conditions:                          \n
*                   - m,n >= 2                                                             \n
*                   - m <= 40                                                              \n
*                   - n <= m                                                               \n
*                   - for m <= 24:  n <= (m-1)                                             \n
*                   - for 24 < m < 40:  m*(2*n + m + 1) <= 1800, for example m=32 & n <= 11\n
*                   - for m = 40 -> n = 2                                                  \n
*
* @param[out]     outputR     Output R matrix ptr.
* @param[out]     outputQ     Output Q matrix ptr.
* @param[in]      input       Input M matrix ptr.
* @param[in]      scratch     Scratch area  ptr. v[m].
* @param[in]      nrows       Number of rows of the input matrix(m).
* @param[in]      ncols       Number of columns of the input matrix(n).
*
* @return         void
*
*/
void __stdcall C_MODEL_DLL Rsdk_LA_decQUHous_Mof32Mof32Mif32(float * outputR,
                                                             float * outputQ,
                                                             float * input,
                                                             float * scratch,
                                                            uint32_t nrows,
                                                            uint32_t ncols);

/** @} */

/*==================================================================================================
 * Upper Hessenberg reduction
 ==================================================================================================*/

/** @addtogroup c_functions_model_hessenberg
* @{
*/

/**
* @brief          Hessenberg reduction for NxN matrix - real single precision.
* @details        Hessenberg reduction for real matrix using Householder
*                 reflection or Householder transformations. P is an orthogonal matrix.\n
*                 pOutputH and pInput can point to same address.\n
*                 P*H*P^t = input \n
*
* @param[out]     pOutputH    First result contains a real H matrix, size NxN.
* @param[out]     pOutputP    Second result contains a real P matrix, size NxN.
* @param[in]      pInput      Operand contains a real matrix, size NxN.
* @param[in]      pBuffer     Scratch area contains a real vector, size N.
* @param[in]      size        Number of rows/columns of input, H and P matrix (N).
*
* \note           size        range is [3...TBD] \n
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_decQUpHessQHousSq_Mof32Mof32Mif32(float * pOutputH,
                                                                     float * pOutputP,
                                                                     float * pInput,
                                                                     float * pBuffer,
                                                                     int32_t size);
/**
* @brief          Hessenberg reduction for a NxN matrix - complex single precision.
* @details        Hessenberg reduction in parallel for each complex matrix using Householder
*                 reflection or Householder transformations. P is an orthogonal matrix.\n
*                 pOutputH and pInput can point to same address.\n
*                 P*H*P^t = input \n
*
* @param[out]     pOutputH    First result contains a complex H matrix, size NxN.
* @param[out]     pOutputP    Second result contains a complex P matrix, size NxN.
* @param[in]      pInput      Operand contains a complex matrixe, size NxN.
* @param[in]      pBuffer     Scratch area contains a complex vector, size (N+1)x1.
* @param[in]      size        Number of rows/columns of input, H and P matrices (N).
*
* \note           size        range is [3...TBD] \n
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_decQUpHessQHousSq_Mof32cMof32cMif32c(rsdk_complex_float32_t * pOutputH,
                                                                        rsdk_complex_float32_t * pOutputP,
                                                                        rsdk_complex_float32_t * pInput,
                                                                        rsdk_complex_float32_t * pBuffer,
                                                                                        uint32_t size);
/** @} */

/** @addtogroup c_functions_model_tridiag
* @{
*/

/**
* @brief          Conversion of NxN tridiagonal Hermitian matrix to NxN tridiagonal symmetric matrix
*                 - single precision.
* @details        Conversion of NxN tridiagonal Hermitian matrix to NxN tridiagonal symmetric matrix
*                 applying a diagonal unitary similarity transformation.\n
*                 pOutputH and pOutputP are overwritten during the process.\n
*                 P*Hs = Hh*P \n
*
* @param[in,out]  pOutputH    First operand contains a tridiagonal Hermitian(complex) matrix, Hh, size NxN.
*                             First result al tridiagonal symmetric(real, but in complex layout) matrix, Hs, size NxN.
* @param[in,out]  pOutputP    Second operand contains an unitary complex matrices as input, size NxN.
*                             Second result contains an unitary similarity transformation
*                             complex matrix as output, P, size NxN.
*                             The buffer is overwritten.
* @param[in]      size        Number of rows/columns of input and output matrices (N).
*
* \note           size        range is [3...TBD] \n
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_simTriDgHm2Sy_Miof32cMiof32c(rsdk_complex_float32_t * pOutputH,
                                                                rsdk_complex_float32_t * pOutputP,
                                                                                uint32_t size);
/** @}*/

/*==================================================================================================
 * SQRT, 1/SQRT or RCPSQRT
 ==================================================================================================*/

/** @addtogroup c_functions_model_sqrt
* @{
*/

/**
* @brief          Element-wise vector square root, srt or sqrt.
* @details        Compute Square Root, srt or sqrt of each vector complex elements. \n
*                 output[k] = sqrt( |input[k]| )  \n
*                 Sign for elements in input vector is ignored.
*
*
* @param[out]     pOutput     Output vector ptr.
* @param[in]      pInput      Input vector ptr.
* @param[in]      size        Number of elements in vector, interval [1..65535].
*
* @return         void
*
*
*/
void __stdcall C_MODEL_DLL Rsdk_EF_sqrtAbs_Vof32Vif32(float * pOutput,
                                                float const * pInput,
                                                     uint32_t size);
/* TO DO Rsdk_EF_sqrtAbs_Vof32Vif32_k2 */
/** @}*/

/** @addtogroup c_functions_model_rsqrt
* @{
*/

/**
* @brief          Element-wise vector reciprocal square root, rrt or rsqrt.
* @details        Compute Reciprocal Square Root, rrt or rsqrt of each vector complex elements. \n
*                 output[k] = 1 / sqrt( |input[k]| )  \n
*                 Sign for elements in input vector is ignored.
*
*
* @param[out]     pOutput     Output vector ptr.
* @param[in]      pInput      Input vector ptr.
* @param[in]      size        Number of elements in vector, interval [1..65535].
*
* @return         void
*
*
*/
void __stdcall C_MODEL_DLL Rsdk_EF_rcpSqrtAbs_Vof32Vif32(float * pOutput,
                                                   float const * pInput,
                                                        uint32_t size);
/* TO DO Rsdk_EF_rcpSqrtAbs_Vof32Vif32_k2 */
/** @}*/

/*==================================================================================================
 * LOG, LOG2, LOG10
 ==================================================================================================*/

/** @addtogroup c_functions_model_log
 * @{
 */

/**
* @brief          Element-wise vector ln or natural logarithm (base e).
* @details        Calculate the ln of the modulus of the input.                    \n
*                 ln takes a real number and returns a real number. The sign of the input
*                 is ignored.                                                        \n
*                 output[k] = ln(input[k])                                         \n
*
*
* @param[out]     pOutput     Output vector ptr.
* @param[in]      pInput      Input vector ptr.
* @param[in]      size        Number of elements in vector, interval [1..65535].
*
* @return         void
*
* @note           ln (vector) = vector \n
*                 v = n, a1, a2, ..., an; \n
*                 ln (v) = n, ln(a1), ln(a2), ..., ln(an); \n
*
*/
void __stdcall C_MODEL_DLL Rsdk_EF_ln_Vof32Vif32(float * pOutput,
                                           float const * pInput,
                                                uint32_t size);

/**
* @brief          Element-wise vector log2 or logarithm base 2.
* @details        Calculate the log2 of the modulus of the input(256 elements).      \n
*                 log2 takes a real number and returns a real number. The sign of the input
*                 is ignored.                                                        \n
*                 output[k] = log2(input[k])                                         \n
*
*
* @param[out]     pOutput     Output vector ptr.
* @param[in]      pInput      Input vector ptr.
*
* @return         void
*
* @note           log2 (vector) = vector \n
*                 v = a1, a2, ..., a256; \n
*                 log2 (v) = log2(a1), log2(a2), ..., log2(a256); \n
*
*/
void __stdcall C_MODEL_DLL Rsdk_EF_log2_Vo256f32Vi256f32(float * pOutput,
                                                   float const * pInput);

/**
* @brief          Element-wise vector log2 or logarithm base 2.
* @details        Calculate the log2 of the modulus of the input.                    \n
*                 log2 takes a real number and returns a real number. The sign of the input
*                 is ignored.                                                        \n
*                 output[k] = log2(input[k])                                         \n
*
*
* @param[out]     pOutput     Output vector ptr.
* @param[in]      pInput      Input vector ptr.
* @param[in]      size        Number of elements in vector, interval [1..65535].
*
* @return         void
*
* @note           log2 (vector) = vector \n
*                 v = n, a1, a2, ..., an; \n
*                 log2 (v) = n, log2(a1), log2(a2), ..., log2(an); \n
*
*/
void __stdcall C_MODEL_DLL Rsdk_EF_log2_Vof32Vif32(float * pOutput,
                                             float const * pInput,
                                                  uint32_t size);

/**
* @brief          Element-wise vector log10 or logarithm base 10.
* @details        Calculate the log10 of the modulus of the input.                   \n
*                 log10 takes a real number and returns a real number. The sign of the input
*                 is ignored.                                                        \n
*                 output[k] = log10(input[k])                                         \n
*
*
* @param[out]     pOutput     Output vector ptr.
* @param[in]      pInput      Input vector ptr.
* @param[in]      size        Number of elements in vector, interval [1..65535].
*
* @return         void
*
* @note           log10 (vector) = vector \n
*                 v = n, a1, a2, ..., an; \n
*                 log10 (v) = n, log10(a1), log10(a2), ..., log10(an); \n
*
*/
void __stdcall C_MODEL_DLL Rsdk_EF_log10_Vof32Vif32(float * pOutput,
                                              float const * pInput,
                                                   uint32_t size);
/** @}*/

/*==================================================================================================
 * Exponentiation, exponential, power
 ==================================================================================================*/

/** @addtogroup c_functions_model_exp
 * @{
 */

/**
* @brief          Element-wise vector exp or exponential.
* @details        Calculate the exp of the input.                                    \n
*                 exp takes a real number and returns its exponential.      \n
*                 output[k] = exp(input[k])                                          \n
*
*
* @param[out]     pOutput     Output vector ptr.
* @param[in]      pInput      Input vector ptr.
* @param[in]      size        Number of elements in vector, interval [1..65535].
*
* @return         void
*
* @note           exp (vector) = vector \n
*                 v = n, a1, a2, ..., an; \n
*                 exp (v) = n, exp(a1), exp(a2), ..., exp(an); \n
*
*/
void __stdcall C_MODEL_DLL Rsdk_EF_exp_Vof32Vif32(float * pOutput,
                                            float const * pInput,
                                                 uint32_t size);
/* TO DO Rsdk_EF_pow2_Vof32cVif32c */
/* TO DO Rsdk_EF_pow2_Vof32Vif32 */
/* TO DO Rsdk_EF_pow3_Vof32cVif32c */
/* TO DO Rsdk_EF_pow3_Vof32Vif32 */
/* TO DO Rsdk_EF_pow4_Vof32cVif32c */
/* TO DO Rsdk_EF_pow4_Vof32Vif32 */
/** @}*/

/*==================================================================================================
 * TRIGONOMETRY
 ==================================================================================================*/

/** @addtogroup c_functions_model_angle_convert
* @{
*/

/**
* @brief          Element-wise convert angle in degrees to radians
* @details        Element-wise convert angle in degrees to radians by multiplying
*                 each element of a real single precision vector with pre-calculated
*                 constant PI / 180.0                                       \n
*                 angleInRadians = (angleInDegrees) * PI / 180.0
*
* @param[out]     pOutput      Output memory area.
* @param[in]      pInput       Input vector .
* @param[in]      size         Number of elements in vector.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_deg2rad_Vof32Vif32(float * pOutput,
                                                float const * pInput,
                                                     uint32_t size);

/**
* @brief          Element-wise convert angle in radians to degrees
* @details        Element-wise convert angle in radians degrees by multiplying
*                 each element of a real single precision vector with pre-calculated
*                 constant 180.0 / PI                                          \n
*                 angleInRadians = (angleInDegrees) * 180.0 / PI
*
* @param[out]     pOutput      Output memory area.
* @param[in]      pInput       Input vector.
* @param[in]      size         Number of elements in vector.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_rad2deg_Vof32Vif32(float * pOutput,
                                                float const * pInput,
                                                     uint32_t size);
/** @}*/

/** @addtogroup c_functions_model_trig
* @{
*/

/**
* @brief          Element-wise vector sine of argument multiplied by PI or sin(x * PI).
* @details        Calculate the sine of all 256 elements after scaling them up by PI. \n
*                 Input is between -1 and +1.                                         \n
*                 Output is between -1 and +1.                                        \n
*                 output[k] = sin(input[k] * pi)                                      \n
*
*
* @param[out]     pOutput     Output vector ptr.
* @param[in]      pInput      Input vector ptr.
*
* @return         void
*
* @note           sine (vector) = vector \n
*                 v = a1, a2, ..., a256; \n
*                 sine (v) = sin(a1*pi), sin(a2*pi), ..., sin(a256*pi); \n
*
*/
void __stdcall C_MODEL_DLL Rsdk_EF_sinpi_Vo256f32Vi256f32(float * pOutput,
                                                    float const * pInput);

/**
* @brief          Element-wise vector sine of argument multiplied by PI or sin(x * PI).
* @details        Calculate the sine of all elements after scaling them up by PI. \n
*                 Input is between -1 and +1.                                     \n
*                 Output is between -1 and +1.                                    \n
*                 output[k] = sin(input[k] * pi)                                  \n
*
*
* @param[out]     pOutput     Output vector ptr.
* @param[in]      pInput      Input vector ptr.
* @param[in]      size        Number of elements in vector, interval [1..65535].
*
* @return         void
*
* @note           sine (vector) = vector \n
*                 v = n, a1, a2, ..., an; \n
*                 sine (v) = n, sin(a1*pi), sin(a2*pi), ..., sin(an*pi); \n
*
*/
void __stdcall C_MODEL_DLL Rsdk_EF_sinpi_Vof32Vif32(float * pOutput,
                                              float const * pInput,
                                                   uint32_t size);

/**
* @brief          Element-wise vector cosine of argument multiplied by PI or cos(x * PI).
* @details        Calculate the cosine of all 256 elements after scaling them up by PI. \n
*                 Input is between -1 and +1.                                           \n
*                 Output is between -1 and +1.                                          \n
*                 output[k] = cos(input[k] * pi)                                        \n
*
*
* @param[out]     pOutput     Output vector ptr.
* @param[in]      pInput      Input vector ptr.
*
* @return         void
*
* @note           cosine (vector) = vector \n
*                 v = a1, a2, ..., a256; \n
*                 cosine (v) = cos(a1*pi), cos(a2*pi), ..., cos(a256*pi); \n
*
*/
void __stdcall C_MODEL_DLL Rsdk_EF_cospi_Vo256f32Vi256f32(float * pOutput,
                                                    float const * pInput);

/**
* @brief          Element-wise vector cosine of argument multiplied by PI or cos(x * PI).
* @details        Calculate the cosine of all elements after scaling them up by PI. \n
*                 Input is between -1 and +1.                                     \n
*                 Output is between -1 and +1.                                    \n
*                 output[k] = cos(input[k] * pi)                                  \n
*
*
* @param[out]     pOutput     Output vector ptr.
* @param[in]      pInput      Input vector ptr.
* @param[in]      size        Number of elements in vector, interval [1..65535].
*
* @return         void
*
* @note           cosine (vector) = vector \n
*                 v = n, a1, a2, ..., an; \n
*                 cosine (v) = n, cos(a1*pi), cos(a2*pi), ..., cos(an*pi); \n
*
*/
void __stdcall C_MODEL_DLL Rsdk_EF_cospi_Vof32Vif32(float * pOutput,
                                              float const * pInput,
                                                   uint32_t size);

/**
* @brief          Element-wise vector tangent of argument multiplied by PI or sin(x * PI).
* @details        Calculate the tangent of all elements after scaling them up by PI. \n
*                 Input is between -0.5 and +0.5.                                     \n
*                 Output is between -INF and +INF.                                    \n
*                 output[k] = tan(input[k] * pi)                                  \n
*
*
* @param[out]     pOutput     Output vector ptr.
* @param[in]      pInput      Input vector ptr.
* @param[in]      size        Number of elements in vector, interval [1..65535].
*
* @return         void
*
* @note           tangent (vector) = vector \n
*                 v = n, a1, a2, ..., an; \n
*                 tangent (v) = n, tan(a1*pi), tan(a2*pi), ..., tan(an*pi); \n
*
*/
void __stdcall C_MODEL_DLL Rsdk_EF_tanpi_Vof32Vif32(float * pOutput,
                                              float const * pInput,
                                                   uint32_t size);

/**
* @brief          Element-wise vector tangent of argument multiplied by PI or sin(x * PI).
*                 Accuracy version - MacLaurin approximation
* @details        Calculate the tangent of all elements after scaling them up by PI. \n
*                 Input is between -0.5 and +0.5.                                     \n
*                 Output is between -INF and +INF.                                    \n
*                 output[k] = tan(input[k] * pi)                                  \n
*
*
* @param[out]     pOutput     Output vector ptr.
* @param[in]      pInput      Input vector ptr.
* @param[in]      size        Number of elements in vector, interval [1..65535].
*
* @return         void
*
* @note           tangent (vector) = vector \n
*                 v = n, a1, a2, ..., an; \n
*                 tangent (v) = n, tan(a1*pi), tan(a2*pi), ..., tan(an*pi); \n
*
*/
void __stdcall C_MODEL_DLL Rsdk_EF_tanpi_Vof32Vif32_k2(float * pOutput,
                                                 float const * pInput,
                                                      uint32_t size);

/**
* @brief          Element-wise vector complex exponential of argument multiplied by PI
*                 or cispi or expj(x * PI).
* @details        Calculate the expj of all elements after scaling them up by PI.           \n
*                 Input is between -1 and +1.                                               \n
*                 Output is between -1 and +1 and is made out of element-wise doublets      \n
*                 of sin and cos applied to the input.
*                 output[k] = expj(input[k] * pi) = cos(input[k]*pi) + j * sin(input[k]*pi) \n
*
*
* @param[out]     pOutput     Output vector ptr.
* @param[in]      pInput      Input vector ptr.
* @param[in]      size        Number of elements in vector, interval [1..65535].
*
* @return         void
*
* @note           expj (vector) = vector \n
*                 v = n, a1, a2, ..., an; \n
*                 expj (v) = n, cos(a1*pi), sin(a1*pi), cos(a2*pi), sin(a2*pi), ...,
*                               cos(an*pi), sin(an*pi); \n
*
*/
void __stdcall C_MODEL_DLL Rsdk_EF_cispi_Vof32Vif32(float * pOutput,
                                              float const * pInput,
                                                   uint32_t size);

/**
* @brief          Element-wise vector cardinal sine of argument x * PI (sin (PI*x)/(PI*x)).
* @details        Calculate the sine of all elements after scaling them up by PI. \n
*                 Input is between -INF and +INF.                                     \n
*                 Output is between -1 and +1.                                    \n
*                 output[k] = sin(input[k] * pi)/(input[k] * pi)                      \n
*
*
* @param[out]     pOutput     Output vector ptr.
* @param[in]      pInput      Input vector ptr.
* @param[in]      size        Number of elements in vector, interval [1..65535].
*
* @return         void
*
* @note           cardinal sine (vector) = vector \n
*                 v = n, a1, a2, ..., an; \n
*                 sinc (v) = n, sin(a1*pi)/(a1*pi), sin(a2*pi)/(a2*pi), ..., sin(an*pi)/(an*pi); \n
*
*/
void __stdcall C_MODEL_DLL Rsdk_EF_sincpi_Vof32Vif32(float * pOutput,
                                               float const * pInput,
                                                    uint32_t size);
/** @} */

/** @addtogroup c_functions_model_trig_inv
 * @{
 */

/**
* @brief          Element-wise vector reverse sine divided by PI, asin/PI or arcsin/PI.
* @details        Calculate the asin of all 256 elements of input then
*                 normalize the output by pi.                                        \n
*                 asin returns an angle between -pi and pi and normalized
*                 with PI to get output limits to -1 to +1                           \n
*                 output[k] = arcsine(input[k]) / pi                                 \n
*
*
* @param[out]     pOutput     Output vector ptr.
* @param[in]      pInput      Input vector ptr.
*
* @return         void
*
* @note           arcsine (vector) = vector \n
*                 v = a1, a2, ..., a256; \n
*                 arcsine (v) = asin(a1)/pi, asin(a2)/pi, ..., asin(a256)/pi; \n
*
*/
void __stdcall C_MODEL_DLL Rsdk_EF_asinpi_Vo256f32Vi256f32(float * pOutput,
                                                     float const * pInput);

/**
* @brief          Element-wise vector reverse sine divided by PI, asin/PI or arcsin/PI.
* @details        Calculate the asin of all elements of input then
*                 normalize the output by pi.                                        \n
*                 asin returns an angle between -pi and pi and normalized
*                 with PI to get output limits to -1 to +1                           \n
*                 output[k] = arcsine(input[k]) / pi                                 \n
*
*
* @param[out]     pOutput     Output vector ptr.
* @param[in]      pInput      Input vector ptr.
* @param[in]      size        Number of elements in vector, interval [1..65535].
*
* @return         void
*
* @note           arcsine (vector) = vector \n
*                 v = n, a1, a2, ..., an; \n
*                 arcsine (v) = n, asin(a1)/pi, asin(a2)/pi, ..., asin(an)/pi; \n
*
*/
void __stdcall C_MODEL_DLL Rsdk_EF_asinpi_Vof32Vif32(float * pOutput,
                                               float const * pInput,
                                                    uint32_t size);

/**
* @brief          Element-wise vector reverse cosine divided by PI, acos/PI or arccos/PI.
* @details        Calculate the acos of all 256 elements of input then
*                 normalize the output by pi.                                        \n
*                 acos returns an angle between -pi and pi and normalized
*                 with PI to get output limits to -1 to +1                           \n
*                 output[k] = arccos(input[k]) / pi                                  \n
*
*
* @param[out]     pOutput     Output vector ptr.
* @param[in]      pInput      Input vector ptr.
*
* @return         void
*
* @note           arccos (vector) = vector \n
*                 v = a1, a2, ..., a256; \n
*                 arccos (v) = acos(a1)/pi, acos(a2)/pi, ..., acos(a256)/pi; \n
*
*/
void __stdcall C_MODEL_DLL Rsdk_EF_acospi_Vo256f32Vi256f32(float * pOutput,
                                                     float const * pInput);

/**
* @brief          Element-wise vector reverse cosine divided by PI, acos/PI or arccos/PI.
* @details        Calculate the acos of all elements of input then
*                 normalize the output by pi.                                        \n
*                 acos returns an angle between -pi and pi and normalized
*                 with PI to get output limits to -1 to +1                           \n
*                 output[k] = arccos(input[k]) / pi                                  \n
*
*
* @param[out]     pOutput     Output vector ptr.
* @param[in]      pInput      Input vector ptr.
* @param[in]      size        Number of elements in vector, interval [1..65535].
*
* @return         void
*
* @note           arccos (vector) = vector \n
*                 v = n, a1, a2, ..., an; \n
*                 arccos (v) = n, acos(a1)/pi, acos(a2)/pi, ..., acos(an)/pi; \n
*
*/
void __stdcall C_MODEL_DLL Rsdk_EF_acospi_Vof32Vif32(float * pOutput,
                                               float const * pInput,
                                                    uint32_t size);

/**
* @brief          Element-wise vector arctangent divided by PI, atan/PI or arctan/PI.
* @details        Calculate the arctangent of 256 elements of input then
*                 normalize the output by pi.                                     \n
*                 Atan returns an angle between -pi and pi and normalized
*                 with PI to get output limits to -1 to +1                        \n
*                 output[k] = arctan(input[k]) / pi                               \n
*
*
* @param[out]     pOutput     Output vector ptr.
* @param[in]      pInput      Input vector ptr.
*
* @return         void
*
* @note           arc-tangent (vector) = vector \n
*                 v = a1, a2, ..., a256; \n
*                 arc-tangent (v) = atan(a1)/pi, atan(a2)/pi, ..., atan(a256)/pi; \n
*
*/
void __stdcall C_MODEL_DLL Rsdk_EF_atanpi_Vo256f32Vi256f32(float * pOutput,
                                                     float const * pInput);

/**
* @brief          Element-wise vector arctangent divided by PI, atan/PI or arctan/PI.
* @details        Calculate the arctangent of all elements of input then
*                 normalize the output by pi.                                     \n
*                 Atan returns an angle between -pi and pi and normalized
*                 with PI to get output limits to -1 to +1                        \n
*                 output[k] = arctan(input[k]) / pi                               \n
*
*
* @param[out]     pOutput     Output vector ptr.
* @param[in]      pInput      Input vector ptr.
* @param[in]      size        Number of elements in vector, interval [1..65535].
*
* @return         void
*
* @note           arc-tangent (vector) = vector \n
*                 v = n, a1, a2, ..., an; \n
*                 arc-tangent (v) = n, atan(a1)/pi, atan(a2)/pi, ..., atan(an)/pi; \n
*
*/
void __stdcall C_MODEL_DLL Rsdk_EF_atanpi_Vof32Vif32(float * pOutput,
                                               float const * pInput,
                                                    uint32_t size);

/**
* @brief          Element-wise vector arctangent2 divided by PI, atan2/PI or arctan2/PI.
* @details        Calculate the arctangent of the element-wise ratio pInputY/pInputX then
*                 normalize the output by pi.                                     \n
*                 Atan2 returns an angle between -pi and pi and normalized
*                 with PI to get output limits to -1 to +1                        \n
*                 output[k] = arctan2(inputY[k], inputX[k])/pi = arctan(inputY[k]/inputX[k])/pi \n
*
*
* @param[out]     pOutput     Output vector ptr.
* @param[in]      pInputY     Input vector ptr.
* @param[in]      pInputX     Input vector ptr.
* @param[in]      size        Number of elements in vector, interval [1..65535].
*
* @return         void
*
 * @note           arc-tangent2 (vector, vector) = vector \n
 *                 Y = n, y1, y2, ..., yn; \n
 *                 X = n, x1, x2, ..., xn; \n
 *                 arc-tangent2 (Y,X) = n, atan2(y1,x1)/pi, atan2(y2,x2)/pi,
 *                 ..., atan2(yn,xn)/pi; \n
 *                 This is equivalent with: \n
 *                 arc-tangent (Y./X) = n, atan(y1/x1)/pi, atan(y2/x2)/pi,
 *                 ..., atan(yn/xn)/pi;
*
*/
void __stdcall C_MODEL_DLL Rsdk_EF_atan2pi_Vof32Vif32Vif32(float * pOutput,
                                                     float const * pInputY,
                                                     float const * pInputX,
                                                          uint32_t size);
/** @}*/

/*==================================================================================================
 * SUM
 ==================================================================================================*/

/** @addtogroup c_functions_model_sums
* @{
*/

/**
* @brief          Sum vector complex elements.
* @details        Sum multiple elements for vector of complex elements.
*
* @param[out]     pOutput     Complex scalar ptr.
* @param[in]      pInput      Input vector ptr.
* @param[in]      size        Number of elements in vector.
*
* @return         void
*
* @note           element sum (vector) = scalar \n
*                 n = elem_cnt \n
*                 v = n, a1, a2..., an; \n
*                 esum(v) = a1 + a2 + ... + an;
*
*/
void __stdcall C_MODEL_DLL Rsdk_LA_sum_Sof32cVif32c(rsdk_complex_float32_t * pOutput,
                                              rsdk_complex_float32_t const * pInput,
                                                                    uint32_t size);

/**
* @brief          Sum vector real elements.
* @details        Sum multiple elements for vector of real elements.
*
* @param[out]     pOutput     Real scalar ptr.
* @param[in]      pInput      Input vector ptr.
* @param[in]      size        Number of elements in vector.
*
* @return         void
*
* @note           element sum (vector) = scalar \n
*                 n = elem_cnt \n
*                 v = n, a1, a2..., an; \n
*                 esum(v) = a1 + a2 + ... + an;
*
*/
void __stdcall C_MODEL_DLL Rsdk_LA_sum_Sof32Vif32(float * pOutput,
                                            float const * pInput,
                                                 uint32_t size);

/**
* @brief          Vector complex elements reciprocal sum.
* @details        Compute reciprocal sum of multiple vector complex elements.
*
* @param[out]     pOutput     Output scalar ptr.
* @param[in]      pInput      Input vector ptr.
* @param[in]      size        Number of elements in vector.
*
* @return         void
*
* @note           element reciprocal sum (vector) = scalar \n
*                 n = size \n
*                 v = n, a1, a2..., an; \n
*                 a1 = x + iy; \n
*                 ersum(v) = 1/a1 + 1/a2 + ... + 1/an; \n
*                 1/a1 = x/(x^2 + y^2) - iy/(x^2 + y^2);
*
*/
void __stdcall C_MODEL_DLL Rsdk_LA_sumRcp_Sof32cVif32c(rsdk_complex_float32_t * pOutput,
                                                 rsdk_complex_float32_t const * pInput,
                                                                       uint32_t size);

/**
* @brief          Vector real elements reciprocal sum.
* @details        Compute reciprocal sum of multiple vector real elements.
*
* @param[out]     pOutput     Output scalar ptr.
* @param[in]      pInput      Input vector ptr.
* @param[in]      size        Number of elements in vector.
*
* @return         void
*
* @note           element reciprocal sum (vector) = scalar \n
*                 n = size \n
*                 v = n, a1, a2..., an; \n
*                 ersum(v) = 1/a1 + 1/a2 + ... + 1/an;
*
*/
void __stdcall C_MODEL_DLL Rsdk_LA_sumRcp_Sof32Vif32(float * pOutput,
                                               float const * pInput,
                                                    uint32_t size);

/**
* @brief          Vector complex elements squared sum.
* @details        Compute squared sum of multiple vector complex elements.
*
* @param[out]     pOutput      Output scalar ptr.
* @param[in]      pInput       Input vector ptr.
* @param[in]      size         Number of elements in vector.
*
* @return         void
*
* @note           element squared sum (vector) = scalar \n
*                 n = size \n
*                 v = n, a1, a2..., an; \n
*                 esqsum(v) = a1^2 + a2^2 + ... + an^2;
*
*
*/
void __stdcall C_MODEL_DLL Rsdk_LA_sum2_Sof32cVif32c(rsdk_complex_float32_t * pOutput,
                                               rsdk_complex_float32_t const * pInput,
                                                                     uint32_t size);

/**
* @brief          Vector real elements squared sum.
* @details        Compute squared sum of multiple vector real elements.
*
* @param[out]     pOutput      Output scalar ptr.
* @param[in]      pInput       Input vector ptr.
* @param[in]      size         Number of elements in vector.
*
* @return         void
*
* @note           element squared sum (vector) = scalar \n
*                 n = size \n
*                 v = n, a1, a2..., an; \n
*                 esqsum(v) = a1^2 + a2^2 + ... + an^2;
*
*
*/
void __stdcall C_MODEL_DLL Rsdk_LA_sum2_Sof32Vif32(float * pOutput,
                                             float const * pInput,
                                                  uint32_t size);

/**
* @brief          Vector complex elements cubic sum.
* @details        Compute cubic sum of multiple vector complex elements.
*
* @param[out]     pOutput      Output scalar ptr.
* @param[in]      pInput       Input vector ptr.
* @param[in]      size         Number of elements in vector.
*
* @return         void
*
* @note           element cubic sum (vector) = scalar \n
*                 n = size \n
*                 v = n, a1, a2..., an; \n
*                 ecsum(v) = a1^3 + a2^3 + ... + an^3;
*
*
*/
void __stdcall C_MODEL_DLL Rsdk_LA_sum3_Sof32cVif32c(rsdk_complex_float32_t * pOutput,
                                               rsdk_complex_float32_t const * pInput,
                                                                     uint32_t size);

/**
* @brief          Vector real elements cubic sum.
* @details        Compute cubic sum of all vector real elements.
*
* @param[out]     pOutput     Real scalar ptr.
* @param[in]      pInput      Input vector ptr.
* @param[in]      size        Number of elements in vector.
*
* @return         void
*
* @note           element cubic sum (vector) = scalar \n
*                 n = size \n
*                 v = n, a1, a2..., an; \n
*                 ecsum(v) = a1^3 + a2^3 + ... + an^3;
*
*
*/
void __stdcall C_MODEL_DLL Rsdk_LA_sum3_Sof32Vif32(float * pOutput,
                                             float const * pInput,
                                                  uint32_t size);
/** @} */

/*==================================================================================================
 * MEAN
 ==================================================================================================*/

/** @addtogroup c_functions_model_means
* @{
*/

/**
* @brief          Arithmetic Mean on vector complex elements.
* @details        Compute Arithmetic Mean of multiple vector complex elements.
*
* @param[out]     pOutput     Output scalar ptr.
* @param[in]      pInput      Input vector ptr.
* @param[in]      size        Number of elements in vector.
*
* @return         void
*
* @note           arithmetic mean (vector) = scalar \n
*                 n = size; \n
*                 v = n, a1, a2..., an; \n
*                 amean(v) = 1\n * (a1 + a2 + ... + an);
*
*/
void __stdcall C_MODEL_DLL Rsdk_LA_avg_Sof32cVif32c(rsdk_complex_float32_t * pOutput,
                                              rsdk_complex_float32_t const * pInput,
                                                                    uint32_t size);
/**
* @brief          Arithmetic Mean on vector complex elements.
* @details        Compute Arithmetic Mean of multiple vector real elements.
*
* @param[out]     pOutput     Output scalar ptr.
* @param[in]      pInput      Input vector ptr.
* @param[in]      size       Number of elements in vector.
*
* @return         void
*
* @note           arithmetic mean (vector) = scalar \n
*                 n = size; \n
*                 v = n, a1, a2..., an; \n
*                 amean(v) = 1/n * (a1 + a2 + ... + an);
*
*/
void __stdcall C_MODEL_DLL Rsdk_LA_avg_Sof32Vif32(float * pOutput,
                                            float const * pInput,
                                                 uint32_t size);

/**
* @brief          Weighted Arithmetic Mean on vector complex elements.
* @details        Compute Weighted Arithmetic Mean of multiple vector complex elements.
*
* @param[out]     pOutput      Output scalar ptr.
* @param[in]      pInput       Input vector ptr.
* @param[in]      pWeights     Weights vector ptr.
* @param[in]      size         Number of elements in vector.
*
* @return         void
*
* @note           weighted arithmetic mean (vector, vector) = scalar \n
*                 n = size \n
*                 v1 = a1, a2..., an; \n
*                 v2 = w1, w2..., wn; \n
*                 wamean (v1, v2) = (a1*w1 + a2*w2 + ... an*wn) / (w1 + w2 + ... + wn);
*
*
*/
void __stdcall C_MODEL_DLL Rsdk_LA_wavg_Sof32cVif32cVif32c(rsdk_complex_float32_t * pOutput,
                                                     rsdk_complex_float32_t const * pInput,
                                                     rsdk_complex_float32_t const * pWeights,
                                                                           uint32_t size);

/**
* @brief          Weighted Arithmetic Mean on vector real elements.
* @details        Compute Weighted Arithmetic Mean of multiple vector real elements.
*
* @param[out]     pOutput      Output scalar ptr.
* @param[in]      pInput       Input vector ptr.
* @param[in]      pWeights     Weights vector ptr.
* @param[in]      size         Number of elements in vector.
*
* @return         void
*
* @note           weighted arithmetic mean (vector, vector) = scalar \n
*                 n = size \n
*                 v1 = a1, a2..., an; \n
*                 v2 = w1, w2..., wn; \n
*                 wamean (v1, v2) = (a1*w1 + a2*w2 + ... an*wn) / (w1 + w2 + ... + wn);
*
*
*/
void __stdcall C_MODEL_DLL Rsdk_LA_wavg_Sof32Vif32Vif32(float * pOutput,
                                                  float const * pInput,
                                                  float const * pWeights,
                                                       uint32_t size);

/**
* @brief          Harmonic Mean on vector complex elements.
* @details        Compute Harmonic Mean of multiple vector complex elements.
*
* @param[out]     pOutput      Output scalar ptr.
* @param[in]      pInput       Input vector ptr.
* @param[in]      size         Number of elements in vector.
*
* @return         void
*
* @note           Harmonic mean (vector) = scalar \n
*                 n = size; \n
*                 v = n, a1, a2..., an; \n
*                 hmean (v) =  n / ( 1/a1 + 1/a2 + ... + 1/an );
*
*
*/
void __stdcall C_MODEL_DLL Rsdk_LA_havg_Sof32cVif32c(rsdk_complex_float32_t * pOutput,
                                               rsdk_complex_float32_t const * pInput,
                                                                     uint32_t size);

/**
* @brief          Harmonic Mean on vector real elements.
* @details        Compute Harmonic Mean of multiple vector real elements.
*
* @param[out]     pOutput      Output scalar ptr.
* @param[in]      pInput       Input vector ptr.
* @param[in]      size        Number of elements in vector.
*
* @return         void
*
* @note           Harmonic mean (vector) = scalar \n
*                 n = size; \n
*                 v = n, a1, a2..., an; \n
*                 hmean (v) =  n / ( 1/a1 + 1/a2 + ... + 1/an );
*
*
*/
void __stdcall C_MODEL_DLL Rsdk_LA_havg_Sof32Vif32(float * pOutput,
                                             float const * pInput,
                                                  uint32_t size);

/**
* @brief          Root Mean Square or Quadratic Mean on vector complex elements.
* @details        Compute Root Mean Square or Quadratic Mean of multiple vector complex elements.
*
* @param[out]     pOutput     Output scalar ptr.
* @param[in]      pInput      Input vector ptr.
* @param[in]      size        Number of elements in vector.
*
* @return         void
*
* @note           root mean square (vector) = scalar \n
*                 n = size; \n
*                 v = n, a1, a2..., an; \n
*                 |a+ib| = sqrt(a^2+b^2) \n
*                 rms (v) = sqrt ( 1/n * (|a1|^2 + |a2|^2 + .... + |an|^2 ) );
*
*
*/
void __stdcall C_MODEL_DLL Rsdk_LA_rms_Sof32Vif32c(float * pOutput,
                            rsdk_complex_float32_t const * pInput,
                                                  uint32_t size);

/**
* @brief          Root Mean Square or Quadratic Mean on vector real elements.
* @details        Compute Root Mean Square or Quadratic Mean of multiple vector real elements.
*
* @param[out]     pOutput     Output scalar ptr.
* @param[in]      pInput      Input vector ptr.
* @param[in]      size        Number of elements in vector.
*
* @return         void
*
* @note           root mean square (vector) = scalar \n
*                 n = size; \n
*                 v = n, a1, a2..., an; \n
*                 rms (v) = sqrt ( 1/n * (|a1|^2 + |a2|^2 + .... + |an|^2 ) );
*
*
*/
void __stdcall C_MODEL_DLL Rsdk_LA_rms_Sof32Vif32(float * pOutput,
                                            float const * pInput,
                                                 uint32_t size);
/** @} */

/*==================================================================================================
 * NORM, DISTANCE
 ==================================================================================================*/

/** @addtogroup c_functions_model_dist
* @{
*/

/**
* @brief          L2 norm of a vector
* @details        norm (v) = 1, sqrt(sum((a1.re^2)+(a1.im^2)+...+ (an.re^2)+(an.im^2)));                    \n
*
*
* @param[out]     pOutput     Output scalar ptr.
* @param[in]      pInput      Input vector ptr.
* @param[in]      size        Number of elements in vector, interval [1..65535].
*
* @return         void
*
* @note           norm (input) = output \n
*                 v = n, a1, a2, ..., an; \n
*                norm (v) = 1, sqrt(sum((a1.re^2)+(a1.im^2)+...+ (an.re^2)+(an.im^2))); \n
*
*/
void __stdcall C_MODEL_DLL Rsdk_LA_normL2_Sof32Vif32c(float * pOutput,
                               rsdk_complex_float32_t const * pInput,
                                                     uint32_t size);

/* TO DO Rsdk_LA_norm2L2_Sof32Vif32c */
/**
* @brief          Squared Mahalanobis distance between two random vectors with 2 variables.
* @details        Compute squared Mahalanobis distance between two vectors
*                 of the same distribution with the inverse covariance matrix S pre-calculated. \n
*                 Input1 vector contains n (size1) observations in pairs, for 2 variables.      \n
*                 Input2 vector contains m (size2) observations in pairs, for 2 variables.      \n
*                 Input3 vector contains pre-calculated inverse covariance matrix S
*                 as a vector s11, s22, 2*s12.                                                  \n
*                 Input vector sizes are is n x 2, m x 2 and 3 float SP elements.               \n
*                 Output vector contains squared distances from first to second vector.         \n
*                 Output vector size is n x m float SP elements.                                \n
*                 Output vector is padded to NUM_AU with zeros n x NUM_AU.
*
*
* @param[out]     pOutput      Output vector.
* @param[in]      pInput1      First input vector pairs ptr.
* @param[in]      pInput2      Second input vector pairs ptr.
* @param[in]      pCov         Inverse Covariance vector ptr, size 3.
* @param[in]      size1        Number of pairs in first vector, interval [1..65535].
* @param[in]      size2        Number of pairs in second vector, interval [1..65535].
*
* @return         void
*
* @note           mahal2 (vector, vector, vector) = vector \n
*                 v1 = (x1, x2), (x3, x4), ..., (x2n-1, x2n); \n
*                 size(v1) = 2n; \n
*                 v2 = (y1, y2), (y3, y4), ..., (y2m-1, y2m); \n
*                 size(v2) = 2m; \n
*                 v3 = c11, c22, 2*c12; \n
*                 size(v3) = 3; \n
*                 v4 = dij  \n
*                 size(v4) = n * m; \n
*                 dij = d((xi, xi+1), (yj, yj+1))
*                     =  (xi-yj)^2 * c11 + (xi+1-yj+1)^2 * c22
*                        + (xi-yj)*(xi+1-yj+1) * 2*c12,    \n
*                 mahal2 (v1,v2,v3) =  d11, d12, ..., d1m,
*                                        d21, d22, ..., d2m,
*                                        ...
*                                        dn1, dn2, ..., dnm, \n
*
*/
void __stdcall C_MODEL_DLL Rsdk_LA_dist2Mahal2_Mof32Mif32Mif32Vi3f32(float * pOutput,
                                                               float const * pInput1,
                                                               float const * pInput2,
                                                               float const * pCov,
                                                                    uint32_t size1,
                                                                    uint32_t size2);
/* TO DO Rsdk_LA_dist2Mahal2_Mof32Mif32Mif32Vi3f32_k2 */
/**
* @brief          Squared Normalized Euclidean distance between two vectors with 2 variables.
* @details        Squared Normalized Euclidean distance between two vectors
*                 of the same distribution with the inverse covariance matrix S pre-calculated
*                 and diagonal.                                                                   \n
*                 Input1 vector contains n (size1) observations in pairs, for 2 variables.        \n
*                 Input2 vector contains m (size2) observations in pairs, for 2 variables.        \n
*                 Input3 vector contains covariance matrix S as a vector s11, s22.                \n
*                 Input vector sizes are is n x 2, m x 2 and 3 float SP elements.                 \n
*                 Output vector contains squared distances from first to second vector.           \n
*                 Output vector size is n x m float SP elements.  \n
*                 Output vector in padded to NUM_AU with zeros n x NUM_AU.
*
*
* @param[out]     pOutput      Output vector.
* @param[in]      pInput1      First input vector pairs ptr.
* @param[in]      pInput2      Second input vector pairs ptr.
* @param[in]      pCov         Inverse Covariance vector ptr, size 2.
* @param[in]      size1        Number of pairs in first vector, interval [1..65535].
* @param[in]      size2        Number of pairs in second vector, interval [1..65535].
*
* @return         void
*
*
*/
void __stdcall C_MODEL_DLL Rsdk_LA_dist2MahalDg2_Mof32Mif32Mif32Vi2f32(float * pOutput,
                                                                 float const * pInput1,
                                                                 float const * pInput2,
                                                                 float const * pCov,
                                                                      uint32_t size1,
                                                                      uint32_t size2);

/**
* @brief          Squared Normalized Euclidean distance between two vectors with 4 variables.
* @details        Squared Normalized Euclidean distance between two vectors
*                 of the same distribution with the inverse covariance matrix S pre-calculated
*                 and diagonal.                                                                   \n
*                 Input1 vector contains n (size1) observations in pairs, for 4 variables.        \n
*                 Input2 vector contains m (size2) observations in pairs, for 4 variables.        \n
*                 Input3 vector contains covariance matrix S as a vector s11, s22, s33, s44.      \n
*                 Input vector sizes are is n x 4, m x 4 and 4 float SP elements.                 \n
*                 Output vector contains squared distances from first to second vector.           \n
*                 Output vector size is n x m float SP elements.  \n
*                 Output vector in padded to NUM_AU with zeros n x NUM_AU.
*
*
* @param[out]     pOutput      Output vector.
* @param[in]      pInput1      First input vector pairs ptr.
* @param[in]      pInput2      Second input vector pairs ptr.
* @param[in]      pCov         Inverse Covariance vector ptr, size 4.
* @param[in]      size1        Number of pairs in first vector, interval [1..65535].
* @param[in]      size2        Number of pairs in second vector, interval [1..65535].
*
* @return         void
*
*/
void __stdcall C_MODEL_DLL Rsdk_LA_dist2MahalDg4_Mof32Mif32Mif32Vi4f32(float * pOutput,
                                                                 float const * pInput1,
                                                                 float const * pInput2,
                                                                 float const * pCov,
                                                                      uint32_t size1,
                                                                      uint32_t size2);
/** @} */

/*==================================================================================================
 * PROD
 ==================================================================================================*/

/** @addtogroup c_functions_model_prod
* @{
*/

/**
* @brief          Vector complex elements product.
* @details        Compute product of all n vector complex elements.
*
* @param[out]     pOutput     Complex scalar ptr.
* @param[in]      pInput      Input vector ptr.
* @param[in]      size        Number of elements in vector.
*
* @return         void
*
* @note           element eprod (vector) = scalar \n
*                 n = elem_cnt \n
*                 v = n, a1, a2..., an; \n
*                 eprod(v) = a1 * a2 * ... * an;
*
*
*/
void __stdcall C_MODEL_DLL Rsdk_LA_prod_Sof32cVif32c(rsdk_complex_float32_t * pOutput,
                                               rsdk_complex_float32_t const * pInput,
                                                                     uint32_t size);

/**
* @brief          Vector real elements product.
* @details        Compute product of multiple vector real elements.
*
* @param[out]     pOutput     Complex scalar ptr.
* @param[in]      pInput      Input vector ptr.
* @param[in]      size        Number of elements in vector.
*
* @return         void
*
* @note           element eprod (vector) = scalar \n
*                 n = elem_cnt \n
*                 v = n, a1, a2..., an; \n
*                 eprod(v) = a1 * a2 * ... * an;
*
*
*/
void __stdcall C_MODEL_DLL Rsdk_LA_prod_Sof32Vif32(float * pOutput,
                                             float const * pInput,
                                                  uint32_t size);
/** @} */

/*==================================================================================================
 * MIN/MAX
 ==================================================================================================*/

/** @addtogroup c_functions_model_minmax
* @{
*/

/**
 * @brief          Find index of Max element on vector complex elements.
 * @details        Find index of Max element of all vector complex elements.
 *
 * @param[out]     pOutput     Unsigned integer scalar ptr.
 * @param[in]      pInput      Input vector ptr.
 * @param[in]      elem_cnt    Number of elements in vector.
 *
 * @return         void
 *
 * @note           Find index of Max element (vector) = scalar \n
 *                 n = elem_cnt; \n
 *                 v = n, a1, a2..., an; \n
 *                 max (v) = index(amax); \n
 *                 \n
 *                 This algorithm returns the index of one of the numbers with the
 *                 the biggest absolute square. \n
 *                 \n
 *                 No phase analysis is performed. To account for the phase
 *                 differences between same absolute square complex numbers, use
 *                 Rsdk_LA_maxAbsPh_Vc
 */
void __stdcall C_MODEL_DLL Rsdk_LA_maxAbs_Sou32Vif32c(uint32_t * pOutput,
                                  rsdk_complex_float32_t const * pInput,
                                                        uint32_t elem_cnt);

/**
* @brief          Find index of Max element on vector real elements.
* @details        Find index of Max element of all vector real elements.
*
* @param[out]     pOutput     Unsigned integer scalar ptr.
* @param[in]      pInput      Input vector ptr.
* @param[in]      elem_cnt    Number of elements in vector.
*
* @return         void
*
* @note           Find index of Max element (vector) = scalar \n
*                 n = elem_cnt; \n
*                 v = n, a1, a2..., an; \n
*                 max (v) = index(amax);
*/
void __stdcall C_MODEL_DLL Rsdk_LA_max_Sou32Vif32(uint32_t * pOutput,
                                               float const * pInput,
                                                    uint32_t elem_cnt);

/**
 * @brief          Find index of min element on vector complex elements.
 * @details        Find index of min element of all vector complex elements.
 *
 * @param[out]     pOutput     Unsigned integer scalar ptr.
 * @param[in]      pInput      Input vector ptr.
 * @param[in]      elem_cnt    Number of elements in vector.
 *
 * @return         void
 *
 * @note           Find index of min element (vector) = scalar \n
 *                 n = elem_cnt; \n
 *                 v = n, a1, a2..., an; \n
 *                 min (v) = index(amin); \n
 *                 \n
 *                 This algorithm returns the index of one of the numbers with the
 *                 the smallest absolute square. \n
 *                 \n
 *                 No phase analysis is performed. To account for the phase
 *                 differences between same absolute square complex numbers, use
 *                 Rsdk_LA_minAbsPh_Vc
 */
void __stdcall C_MODEL_DLL Rsdk_LA_minAbs_Sou32Vif32c(uint32_t * pOutput,
                                  rsdk_complex_float32_t const * pInput,
                                                        uint32_t elem_cnt);

/**
* @brief          Find index of Min element on vector real elements.
* @details        Find index of Min element of all vector real elements.
*
* @param[out]     pOutput     Unsigned integer scalar ptr.
* @param[in]      pInput      Input vector ptr.
* @param[in]      elem_cnt    Number of elements in vector.
*
* @return         void
*
* @note           Find index of Min element (vector) = scalar \n
*                 n = elem_cnt; \n
*                 v = n, a1, a2..., an \n;
*                 min (v) = index(amin);
*/
void __stdcall C_MODEL_DLL Rsdk_LA_min_Sou32Vif32(uint32_t * pOutput,
                                               float const * pInput,
                                                    uint32_t elem_cnt);

/**
 * @brief          Find index of Max element on vector complex elements.
 * @details        Find index of Max element of all vector complex elements,
 *                 by performing both absolute square value and phase analysis.
 *
 * @param[out]     pOutput     Unsigned integer scalar ptr.
 * @param[in]      pInput      Input vector ptr.
 * @param[in]      elem_cnt    Number of elements in vector.
 *
 * @return         void
 *
 * @note           Find index of Max element (vector) = scalar \n
 *                 n = elem_cnt; \n
 *                 v = n, a1, a2..., an; \n
 *                 max (v) = index(amax); \n
 *                 \n
 *                 Restrictions: j != i, j,i >= 1 and j,i <= n, ai and aj from v \n
 *                 Algorithm: \n
 *                 \code{.unparsed}
 *                 if (abs(ai))^2 > (abs(aj))^2, then
 *                         max(v) = i
 *                 else
 *                     if (abs(ai))^2 == (abs(aj))^2, then
 *                         if phase(ai) != phase(aj), then
 *                             // equivalent with matlab's angle() function
 *                             mav(v) = max(phase(ai), phase(aj))
 *                         else
 *                             // phases are equal too. Returns the smallest index (first found) \n
 *                             max(v) = min(i, j)
 *                     else // (abs(ai))^2 < (abs(aj))^2
 *                         max(v) = j
 *                 \endcode
 *                 \n
 *                 Inside the function's body, the maximum shall be referred to as "the extreme".
 */
void __stdcall C_MODEL_DLL Rsdk_LA_maxAbsPh_Vou32Vif32c(uint32_t * pOutput,
                                    rsdk_complex_float32_t const * pInput,
                                                          uint32_t elem_cnt);

/**
 * @brief          Find index of Min element on vector complex elements.
 * @details        Find index of Min element of all vector complex elements,
 *                 by performing both absolute square value and phase analysis.
 *
 * @param[out]     pOutput     Unsigned integer scalar ptr.
 * @param[in]      pInput      Input vector ptr.
 * @param[in]      elem_cnt    Number of elements in vector.
 *
 * @return         void
 *
 * @note           Find index of Min element (vector) = scalar \n
 *                 n = elem_cnt; \n
 *                 v = n, a1, a2..., an; \n
 *                 min (v) = index(amin); \n
 *                 \n
 *                 Restrictions: j != i, j,i >= 1 and j,i <= n, ai and aj from v \n
 *                 Algorithm: \n
 *                 \code{.unparsed}
 *                 if (abs(ai))^2 < (abs(aj))^2, then
 *                         min(v) = i
 *                 else
 *                     if (abs(ai))^2 == (abs(aj))^2, then
 *                         if phase(ai) != phase(aj), then
 *                             // equivalent with matlab's angle() function
 *                             min(v) = min(phase(ai), phase(aj))
 *                         else
 *                             // phases are equal too. Returns the smallest index (first found)
 *                             min(v) = min(i, j)
 *                     else // (abs(ai))^2 > (abs(aj))^2
 *                         min(v) = j
 *                 \endcode
 *                 \n
 *                 Inside the function's body, the minimum shall be referred to as "the extreme".
 */
void __stdcall C_MODEL_DLL Rsdk_LA_minAbsPh_Vou32Vif32c(uint32_t * pOutput,
                                    rsdk_complex_float32_t const * pInput,
                                                          uint32_t elem_cnt);

/** @}*/

/*==================================================================================================
 * SORT
 ==================================================================================================*/
/* TO DO group c_functions_model_sort */
/* TO DO Rsdk_DT_minMax_Vof32Vof32Vif32Vif32 */
/* TO DO Rsdk_DT_mergeOEM_Vo256f32Vi128f32Vi128f32 */
/* TO DO Rsdk_DT_mergeOEM_Vo512f32Vi256f32Vi256f32 */
/* TO DO Rsdk_DT_sortOET_Vo128f32Vi128f32 */
/* TO DO Rsdk_DT_sortdOET_Vo512f32Vi512f32 */
/* TO DO Rsdk_DT_sortOEM_Vo128f32Vi128f32 */
/* TO DO Rsdk_DT_sortOEM_Vo256f32Vi256f32 */
/* TO DO Rsdk_DT_sortEE_Vo512f32Vi512f32 */

/** @addtogroup c_functions_model_sort_au
* @{
*/

/**
* @brief          Odd Even transposition sort real elements.
* @details        Odd-Even Sort / Brick Sort of all 16 vector real elements.
*
* @param[out]     pOutput     Output float32 vector ptr.
* @param[in]      pInput      Input float32 vector ptr.
*
* @return         void
*
* @note           Odd-Even Transpose Sort (vector) = vector \n
*                 v = 16, a1, a2..., a16; \n
*                 OETS (v) =  sorted(v); \n
*                 k = n/2 \n
*                 Step 0 -> re arrange data \n
*                 a[1], 0, a[3], 0, a[5], 0, ... a[2k-1], 0 \n
*                 a[2], 0, a[4], 0, a[6], 0, ... a[2k],   0 \n
*                 Step 1 \n
*                 %MAX(a[1],a[2]), 0, %MAX(a[3],a[4]), 0, %MAX(a[5],a[6]), 0, ... ,
*                 %MAX(a[2k-1],a[2k]), 0 \n
*                 %MIN(a[1],a[2]), 0, %MIN(a[3],a[4]), 0, %MIN(a[5],a[6]), 0, ... ,
*                 %MIN(a[2k-1],a[2k]), 0 \n
*                 \n
*                 %MAX(a1,a2) = (a1+a2)/2 + |a1-a2|/2 \n
*                 %MIN(a1,a2) = (a1+a2)/2 - |a1-a2|/2
*
*
*/
void __stdcall C_MODEL_DLL Rsdk_AU_sortdOET_Vo16f32Vi16f32(float * pOutput,
                                                     float const * pInput);

/**
* @brief          Odd Even transposition sort real elements.
* @details        Odd-Even Sort / Brick Sort of all 64 vector float elements.
*
* @param[out]     pOutput     Output float32 vector ptr.
* @param[in]      pInput      Input float32 vector ptr.
*
* @return         void
*
* @note           Odd-Even Transpose Sort (vector) = vector \n
*                 v = 32, a1, a2..., a32; \n
*                 OETS (v) =  sorted(v); \n
*                 k = n/2 \n
*                 Step 0 -> re arrange data \n
*                 a[1], 0, a[3], 0, a[5], 0, ... a[2k-1], 0 \n
*                 a[2], 0, a[4], 0, a[6], 0, ... a[2k],   0 \n
*                 Step 1 \n
*                 MAX(a[1],a[2]), 0, MAX(a[3],a[4]), 0, MAX(a[5],a[6]), 0, ... ,
*                 MAX(a[2k-1],a[2k]), 0 \n
*                 MIN(a[1],a[2]), 0, MIN(a[3],a[4]), 0, MIN(a[5],a[6]), 0, ... ,
*                 MIN(a[2k-1],a[2k]), 0 \n
*                 \n
*                 MAX(a1,a2) = (a1+a2)/2 + |a1-a2|/2 \n
*                 MIN(a1,a2) = (a1+a2)/2 - |a1-a2|/2
*
*/
void __stdcall C_MODEL_DLL Rsdk_AU_sortdOET_Vo32f32Vi32f32(float * pOutput,
                                                     float const * pInput);
/** @} */

/*==================================================================================================
 * Thresholding
 ==================================================================================================*/

/** @addtogroup c_functions_model_thresh
* @{
*/

 /**
* @brief          Return bitmask that encodes input vector variation against a threshold.
* @details        Bitmask encodes for each of the n input elements, if it's larger or smaller than
*                 the input threshold.
*
* @param[out]     pOutput     Output unsigned int 32bit mask vector.
* @param[in]      pInput1     Input real vector.
* @param[in]      pInput2     Input real scalar.
* @param[in]      size        Length of Input1 vector.
*
* @return         void
*
* @note           thresh_bitmask(vector) = vector \n
*                 thresh_bitmask(v) = [a0 a1 ... an], where \n
*                 a0 = [b31 b30 ... b1 b0] \n
*                 a1 = [b63 b62 ... b33 b32], etc  \n
*                 (a_x are floats, b_y are bits) \n \n
*
*                 b_y = 0 if v_i <= threshold \n
*                 b_y = 1 if v_i > threshold, \n
*                 with y = i % 32 and i = x * 32 + y. \n \n
*
*                 More intuitively, the resulting vector of bits corresponds to the signs of the
*                 reversed difference vector between the input vector (pInput1) and the threshold
*                 constant (pInput2).
*/
void __stdcall C_MODEL_DLL Rsdk_LA_threshBit_Vou32Vif32Sif32(uint32_t * pOutput,
                                                          float const * pInput1,
                                                          float const * pInput2,
                                                               uint32_t size);
/** @}*/

/*==================================================================================================
 * Matrix transpose, conjugate transpose or Hermitian transpose
 ==================================================================================================*/
 /** @addtogroup c_functions_model__transpose
 * @{
 */

/**
* @brief          Transpose a Complex Single Precision matrix
*
* @param[out]     output      Output memory area.
* @param[in]      input       Input matrix.
* @param[in]      numRows     Number of rows of the input matrix.
* @param[in]      numCols     Number of columns of the input matrix.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_T_Mof32cMif32c(rsdk_complex_float32_t * output,
                                            rsdk_complex_float32_t const * input,
                                                                  uint32_t numRows,
                                                                  uint32_t numCols);

/**
* @brief          Transpose a Real Single Precision matrix
*
* @param[out]     output      Output memory area.
* @param[in]      input       Input matrix.
* @param[in]      numRows     Number of rows of the input matrix.
* @param[in]      numCols     Number of columns of the input matrix.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_T_Mof32Mif32(float * output,
                                          float const * input,
                                               uint32_t numRows,
                                               uint32_t numCols);
/* TO DO Rsdk_LA_H_Mof32cMif32c */
/** @}*/

/*==================================================================================================
 * COPY
 ==================================================================================================*/
/* TO DO group: c_functions_model_copy */
/* TO DO Rsdk_DT_copy_Vof32cVif32c */
/* TO DO Rsdk_DT_copy_Vof32Vif32 */
/* TO DO Rsdk_DT_copyOutOffset_Vof32cVif32c */
/* TO DO Rsdk_DT_copyInOffset_Vof32cVif32c */
/* TO DO Rsdk_DT_copyOutOffset_Vof32Vif32 */
/* TO DO Rsdk_DT_copyInOffset_Vof32Vif32 */
/*==================================================================================================
 * CELL GET,SET, Accumulate
 ==================================================================================================*/
/* TO DO group: c_functions_model_cell */
/* TO DO Rsdk_LA_getCell_Sof32Vif32Siu32 */
/* TO DO Rsdk_LA_setCell_Vof32Vif32Siu32Sif32 */
/* TO DO Rsdk_LA_setCell_Viof32Siu32Sif32 */
/* TO DO Rsdk_LA_accCell_Vof32Vif32Siu32Sif32 */
/* TO DO Rsdk_LA_accCell_Viof32Siu32Sif32 */
/* TO DO Rsdk_LA_getCell_Sof32cVif32cSiu32 */
/* TO DO Rsdk_LA_setCell_Vof32cVif32cSiu32Sif32c */
/* TO DO Rsdk_LA_setCell_Viof32cSiu32Sif32c */
/* TO DO Rsdk_LA_accCell_Vof32cVif32cSiu32Sif32c */
/* TO DO Rsdk_LA_accCell_Viof32cSiu32Sif32c */
/* TO DO Rsdk_DT_countCells_Sou32Vif32Sif32 */
/* TO DO Rsdk_DT_isCell_Sou32Vif32Sif32 */
/* TO DO Rsdk_DT_findCell_Sou32Vif32Sif32 */

/* TO DO group: c_functions_model_extract */
/* TO DO Rsdk_DT_extract_Vof32Vif32Viu32 */
/* TO DO Rsdk_DT_extract_Vof32cVif32cViu32 */
/* TO DO Rsdk_DT_extract_Mof32cMif32cViu32 */
/* TO DO Rsdk_DT_getCol_Vof32cMif32cSiu32 */

/*==================================================================================================
 * DMA packed to unpacked(aligned and padded) conversions
 ==================================================================================================*/
/** @addtogroup c_functions_model_lay_conv
* @{
*/

/* TO DO Rsdk_DT_alignPack_Mof32cMif32c */
/* TO DO Rsdk_DT_alignPack_Mof32Mif32 */
/* TO DO Rsdk_DT_alignTPack_Mof32cMif32c */
/* TO DO Rsdk_DT_alignTPack_Mof32Mif32 */
/* TO DO Rsdk_DT_alignHPack_Mof32cMif32c */
/* TO DO Rsdk_DT_unAlign_Mof32cMif32c */
/* TO DO Rsdk_DT_unAlign_Mof32Mif32 */

/**
* @brief          Convert one data stream from position k inside X parallel
*                 streams of NxM matrixes to a NxM matrix - complex single precision
* @details        Data stream at position k is de-serialized and copied in one matrix. \n
*                 The selection is done using the batch_pos index.
*
* @param[out]     pOutput      Output matrix, row major format.
* @param[in]      pInput       Input batch array.
* @param[in]      batch_pos    Position of the extracted matrix.
* @param[in]      nrows        Number of rows of a single matrix from the batch array.
* @param[in]      ncols        Number of columns of a single matrix from the batch array.
* @param[in]      batch_size   Number of matrices saved in the batch array.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_getStream_Mof32cMif32cpX(rsdk_complex_float32_t * pOutput,
                                                            rsdk_complex_float32_t * pInput,
                                                                             uint8_t batch_pos,
                                                                            uint32_t nrows,
                                                                            uint32_t ncols,
                                                                             uint8_t batch_size);

/**
* @brief          Convert NxM matrix to one data stream at position k inside X parallel
*                 streams of NxM matrixes - complex single precision
* @details        Input matrix is serialized and copied in one parallel stream at position k. \n
*                 Fill a single member of the batch and leave the other members intact. \n
*                 The position k, where the input matrix is loaded is selected using the batch_pos index.
*
* @param[out]     pOutput      Output batch array, with the new matrix added.
* @param[in]      pInput       Input matrix, row major format.
* @param[in]      batch_pos    Position in batch array of the loaded matrix.
* @param[in]      nrows        Number of rows of a single matrix from the batch array.
* @param[in]      ncols        Number of columns of a single matrix from the batch array.
* @param[in]      batch_size   Number of matrices saved in the batch array.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_setStream_Mof32cpXMif32c(rsdk_complex_float32_t * pOutput,
                                                            rsdk_complex_float32_t * pInput,
                                                                             uint8_t batch_pos,
                                                                            uint32_t nrows,
                                                                            uint32_t ncols,
                                                                             uint8_t batch_size);

/**
* @brief          Convert one data stream from position k inside X parallel
*                 streams of NxM matrixes to a NxM matrix - real single precision
* @details        Data stream at position k is de-serialized and copied in one matrix. \n
*                 The selection is done using the batch_pos index.
*
* @param[out]     pOutput      Output matrix, row major format.
* @param[in]      pInput       Input matrices stored in batch format.
* @param[in]      matrix_pos   Position of the extracted matrix.
* @param[in]      nrows        Number of rows of a single matrix from the batch array.
* @param[in]      ncols        Number of columns of a single matrix from the batch array.
* @param[in]      batch_count  Number of matrices saved in batch the array.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_getStream_Mof32Mif32pX(float * pOutput,
                                                          float * pInput,
                                                         uint32_t matrix_pos,
                                                         uint32_t nrows,
                                                         uint32_t ncols,
                                                          uint8_t batch_count);

/**
* @brief          Convert NxM matrix to one data stream at position k inside X parallel
*                 streams of NxM matrixes - real single precision
* @details        Input matrix is serialized and copied in one parallel stream at position k. \n
*                 Fill a single member of the batch and leave the other members intact. \n
*                 The position k, where the input matrix is loaded is selected using the batch_pos index.
*
* @param[out]     pOutput      Output batch array, with the new matrix added.
* @param[in]      pInput       Input matrix, row major format.
* @param[in]      matrix_pos   Position in batch array of the loaded matrix.
* @param[in]      nrows        Number of rows of a single matrix from the batch array.
* @param[in]      ncols        Number of columns of a single matrix from the batch array.
* @param[in]      batch_count  Number of matrices saved in the batch array.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_LA_setStream_Mof32pXMif32(float * pOutput,
                                                          float * pInput,
                                                         uint32_t matrix_pos,
                                                         uint32_t nrows,
                                                         uint32_t ncols,
                                                          uint8_t batch_count);

/** @}*/

/*==================================================================================================
 * TYPE conversions, single <> half, real <> complex
 ==================================================================================================*/

/** @addtogroup c_functions_model_conversion
* @{
*/

/**
 * @brief          Convert a real fixed-point input vector to a real floating point (single
 *                 precision) output vector.
 * @details        The input vector's fixed-point elements, represented as 16-bit integers, are
 *                 converted to 32-bit floating point elements. The conversion causes no precision
 *                 loss.
 *
 *
 * @param[out]     pOutput       Output real vector ptr. Floating point single precision.
 * @param[in]      pInput        Input real vector ptr. Fixed-point.
 * @param[in]      size          Number of elements
 *
 * @return         void
 */
void __stdcall C_MODEL_DLL Rsdk_DT_q15toSP_Vof32Viq16(float * pOutput,
                                                    int16_t * pInput,
                                                     uint32_t size);

/**
 * @brief          Convert a complex fixed-point input vector to a complex floating point (single
 *                 precision) output vector.
 * @details        The input vector's fixed-point elements (their real and imaginary parts),
 *                 represented as 16-bit integers, are converted to 32-bit floating point elements.
 *                 The conversion causes no precision loss.
 *
 *
 * @param[out]     pOutput       Output complex vector ptr. Floating point single precision.
 * @param[in]      pInput        Input complex vector ptr. Fixed-point.
 * @param[in]      size          Number of elements
 *
 * @return         void
 */
void __stdcall C_MODEL_DLL Rsdk_DT_q15toSP_Vof32cViq16c(rsdk_complex_float32_t * pOutput,
                                                          rsdk_complex_int16_t * pInput,
                                                                        uint32_t size);
/* TO DO Rsdk_DT_interl_Mof32cMif32Mif32 */
/* TO DO Rsdk_DT_deinterl_Mof32Mof32Mif32c */

/** @}*/

/*==================================================================================================
 * Fourier transform
 ==================================================================================================*/
/*  1D FFT - Fast Fourier transform */

/* Vector index re-order linear to bit-reversed */

/** @addtogroup c_functions_model_fft_br
* @{
*/

/**
* @brief          Re-order Complex Single Precision vector using bit-reversal indexes.
* @details        Used for FFT bit-reverse index re-order of 16 vector elements.
*                 Used with FFT.
*                 Input and output can point to same address.
*
* @param[out]     pOutput      Output memory area.
* @param[in]      pInput       Input Complex Single Precision vector.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_SP_bitRev_Vo16f32cVi16f32c(rsdk_complex_float32_t * pOutput,
                                                     rsdk_complex_float32_t const * pInput);

/**
* @brief          Re-order Complex Single Precision vector using bit-reversal indexes.
* @details        Used for FFT bit-reverse index re-order of 64 vector elements.
*                 Used with FFT.
*                 Input and output can point to same address.
*
* @param[out]     pOutput      Output memory area.
* @param[in]      pInput       Input Complex Single Precision vector.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_SP_bitRev_Vo32f32cVi32f32c(rsdk_complex_float32_t * pOutput,
                                                     rsdk_complex_float32_t const * pInput);

/**
* @brief          Re-order Complex Single Precision vector using bit-reversal indexes.
* @details        Used for FFT bit-reverse index re-order of 64 vector elements.
*                 Used with FFT.
*                 Input and output can point to same address.
*
* @param[out]     pOutput      Output memory area.
* @param[in]      pInput       Input Complex Single Precision vector.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_SP_bitRev_Vo64f32cVi64f32c(rsdk_complex_float32_t * pOutput,
                                                     rsdk_complex_float32_t const * pInput);

/**
* @brief          Re-order Complex Single Precision vector using bit-reversal indexes.
* @details        Used for FFT bit-reverse index re-order of 128 vector elements.
*                 Used with FFT.
*                 Input and output can point to same address.
*
* @param[out]     pOutput      Output memory area.
* @param[in]      pInput       Input Complex Single Precision vector.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_SP_bitRev_Vo128f32cVi128f32c(rsdk_complex_float32_t * pOutput,
                                                       rsdk_complex_float32_t const * pInput);

/**
* @brief          Re-order Complex Single Precision vector using bit-reversal indexes.
* @details        Used for FFT bit-reverse index re-order of 256 vector elements.
*                 Used with FFT.
*                 Input and output can point to same address.
*
* @param[out]     pOutput      Output memory area.
* @param[in]      pInput       Input Complex Single Precision vector.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_SP_bitRev_Vo256f32cVi256f32c(rsdk_complex_float32_t * pOutput,
                                                       rsdk_complex_float32_t const * pInput);

/**
* @brief          Re-order Complex Single Precision vector using bit-reversal indexes.
* @details        Used for FFT bit-reverse index re-order of 512 vector elements.
*                 Used with FFT.
*                 Input and output can point to same address.
*
* @param[out]     pOutput      Output memory area.
* @param[in]      pInput       Input Complex Single Precision vector.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_SP_bitRev_Vo512f32cVi512f32c(rsdk_complex_float32_t * pOutput,
                                                       rsdk_complex_float32_t const * pInput);

/**
* @brief          Re-order Complex Single Precision vector using bit-reversal indexes.
* @details        Used for FFT bit-reverse index re-order of 1024 vector elements.
*                 Used with FFT.
*                 Input and output can point to same address.
*
* @param[out]     pOutput      Output memory area.
* @param[in]      pInput       Input Complex Single Precision vector.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_SP_bitRev_Vo1024f32cVi1024f32c(rsdk_complex_float32_t * pOutput,
                                                         rsdk_complex_float32_t const * pInput);

/**
* @brief          Re-order Complex Single Precision vector using bit-reversal indexes.
* @details        Used for FFT bit-reverse index re-order of 2048 vector elements.
*                 Used with FFT.
*                 Input and output can point to same address.
*
* @param[out]     pOutput      Output memory area.
* @param[in]      pInput       Input Complex Single Precision vector.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_SP_bitRev_Vo2048f32cVi2048f32c(rsdk_complex_float32_t * pOutput,
                                                         rsdk_complex_float32_t const * pInput);
/** @}*/

/** @addtogroup c_functions_model_fft_bfly
 * @{
 */

/**
* @brief          1D FFT DIF Fast Fourier transform vector complex elements, output is BR ordered.
* @details        FFT vector 2 complex elements without bit reverse index change. \n
*                 Decimation in frequency approach, radix 2. \n
*                 Input is linear ordered, output is bit reverse ordered. \n
*                 Input and output can point to same address. \n
*                 For re-order use Rsdk_SP_bitRev_Vo2f32cVi2f32c. \n
*                 For zero padding use Rsdk_SP_zeroTrail_Vof32cVif32c.
*
*
* @param[out]     pOutput     Output vector ptr.
* @param[in]      pInput      Input vector ptr.
*
* @return         void
*
* @note           Fast Fourier transform fft_fd (vector) = vector \n
*                 v = a0, a1; \n
*                 u0  = sum ( v(n)*exp(-j*2*pi* 0*(n-1)/2) ),  n = 1 ... 2 \n
*                 u1  = sum ( v(n)*exp(-j*2*pi* 1*(n-1)/2) ),  n = 1 ... 2 \n
*                 fft_fd(v) = u
*
*
*/
void __stdcall C_MODEL_DLL Rsdk_SP_bflyDif2_Vo2f32cVi2f32c(rsdk_complex_float32_t * pOutput,
                                                     rsdk_complex_float32_t const * pInput);
/* TO DO Rsdk_SP_bflyInvDif2S_Vo2f32cVi2f32c */
/**
* @brief          1D FFT DIF Fast Fourier transform vector complex elements, output is BR ordered.
* @details        FFT vector 8 complex elements without bit reverse index change. \n
*                 Decimation in frequency approach, radix 2. \n
*                 Input is linear ordered, output is bit reverse ordered. \n
*                 Input and output can point to same address. \n
*                 For re-order use Rsdk_SP_bitRev_Vo4f32cVi4f32c. \n
*                 For zero padding use Rsdk_SP_zeroTrail_Vof32cVif32c.
*
*
* @param[out]     pOutput     Output vector ptr.
* @param[in]      pInput      Input vector ptr.
*
* @return         void
*
* @note           Fast Fourier transform fft_fd (vector) = vector \n
*                 v = a00, a01, ..., a11; \n
*                 u00  = sum ( v(n)*exp(-j*2*pi* 0*(n-1)/4) ),  n = 1 ... 4 \n
*                 u10  = sum ( v(n)*exp(-j*2*pi* 1*(n-1)/4) ),  n = 1 ... 4 \n
*
*                 u11  = sum ( v(n)*exp(-j*2*pi* 3*(n-1)/4) ),  n = 1 ... 4 \n
*                 fft_fd(v) = u
*
*
*/
void __stdcall C_MODEL_DLL Rsdk_SP_bflyDif2_Vo4f32cVi4f32c(rsdk_complex_float32_t * pOutput,
                                                     rsdk_complex_float32_t const * pInput);
/* TO DO Rsdk_SP_bflyInvDif2S_Vo4f32cVi4f32c */
/**
* @brief          1D FFT DIF Fast Fourier transform vector complex elements, output is BR ordered.
* @details        FFT vector 8 complex elements without bit reverse index change. \n
*                 Decimation in frequency approach, radix 2. \n
*                 Input is linear ordered, output is bit reverse ordered. \n
*                 Input and output can point to same address. \n
*                 For re-order use Rsdk_SP_bitRev_Vo8f32cVi8f32c. \n
*                 For zero padding use Rsdk_SP_zeroTrail_Vof32cVif32c.
*
*
* @param[out]     pOutput     Output vector ptr.
* @param[in]      pInput      Input vector ptr.
*
* @return         void
*
* @note           Fast Fourier transform fft_fd (vector) = vector \n
*                 v = a000, a001, ..., a111; \n
*                 u000  = sum ( v(n)*exp(-j*2*pi* 0*(n-1)/8) ),  n = 1 ... 8 \n
*                 u100  = sum ( v(n)*exp(-j*2*pi* 1*(n-1)/8) ),  n = 1 ... 8 \n
*
*                 u111  = sum ( v(n)*exp(-j*2*pi* 7*(n-1)/8) ),  n = 1 ... 8 \n
*                 fft_fd(v) = u
*
*
*/
void __stdcall C_MODEL_DLL Rsdk_SP_bflyDif2_Vo8f32cVi8f32c(rsdk_complex_float32_t * pOutput,
                                                     rsdk_complex_float32_t const * pInput);
/* TO DO Rsdk_SP_bflyInvDif2S_Vo8f32cVi8f32c */

/**
* @brief          1D FFT DIF Fast Fourier transform vector complex elements, output is BR ordered.
* @details        FFT vector 16 complex elements without bit reverse index change. \n
*                 Decimation in frequency approach, radix 2. \n
*                 Input is linear ordered, output is bit reverse ordered. \n
*                 Input and output can point to same address. \n
*                 For re-order use Rsdk_SP_bitRev_Vo16f32cVi16f32c. \n
*                 For zero padding use Rsdk_SP_zeroTrail_Vof32cVif32c.
*
*
* @param[out]     pOutput     Output vector ptr.
* @param[in]      pInput      Input vector ptr.
*
* @return         void
*
* @note           Fast Fourier transform fft_fd (vector) = vector \n
*                 v = a0000, a0001, ..., a1111; \n
*                 u0000  = sum ( v(n)*exp(-j*2*pi* 0*(n-1)/16) ),  n = 1 ... 16 \n
*                 u1000  = sum ( v(n)*exp(-j*2*pi* 1*(n-1)/16) ),  n = 1 ... 16 \n \n
*
*                 u1111  = sum ( v(n)*exp(-j*2*pi*15*(n-1)/16) ),  n = 1 ... 16 \n
*                 fft_fd(v) = u
*
*
*/
void __stdcall C_MODEL_DLL Rsdk_SP_bflyDif2_Vo16f32cVi16f32c(rsdk_complex_float32_t * pOutput,
                                                       rsdk_complex_float32_t const * pInput);
/* TO DO Rsdk_SP_bflyInvDif2S_Vo16f32cVi16f32c */

/**
* @brief          1D FFT DIF Fast Fourier transform vector complex elements, output is BR ordered.
* @details        FFT vector 32 complex elements without bit reverse index change. \n
*                 Decimation in frequency approach, radix 2. \n
*                 Input is linear ordered, output is bit reverse ordered. \n
*                 Input and output can point to same address. \n
*                 For re-order use Rsdk_SP_bitRev_Vo32f32cVi32f32c. \n
*                 For zero padding use Rsdk_SP_zeroTrail_Vof32cVif32c.
*
*
* @param[out]     pOutput     Output vector ptr.
* @param[in]      pInput      Input vector ptr.
*
* @return         void
*
* @note           Fast Fourier transform fft_fd (vector) = vector \n
*                 v = a00000, a00001, ..., a11111; \n
*                 u00000  = sum ( v(n)*exp(-j*2*pi* 0*(n-1)/32) ),  n = 1 ... 32 \n
*                 u10000  = sum ( v(n)*exp(-j*2*pi* 1*(n-1)/32) ),  n = 1 ... 32 \n \n
*
*                 u11111  = sum ( v(n)*exp(-j*2*pi*31*(n-1)/32) ),  n = 1 ... 32 \n
*                 fft_fd(v) = u
*
*
*/
void __stdcall C_MODEL_DLL Rsdk_SP_bflyDif2_Vo32f32cVi32f32c(rsdk_complex_float32_t * pOutput,
                                                       rsdk_complex_float32_t const * pInput);
/* TO DO Rsdk_SP_bflyInvDif2S_Vo32f32cVi32f32c */

/**
* @brief          1D FFT DIF Fast Fourier transform vector complex elements, output is BR ordered.
* @details        FFT vector 64 complex elements without bit reverse index change. \n
*                 Decimation in frequency approach, radix 2. \n
*                 Input is linear ordered, output is bit reverse ordered. \n
*                 Input and output can point to same address. \n
*                 For re-order use Rsdk_SP_bitRev_Vo64f32cVi64f32c. \n
*                 For zero padding use Rsdk_SP_zeroTrail_Vof32cVif32c.
*
*
* @param[out]     pOutput     Output vector ptr.
* @param[in]      pInput      Input vector ptr.
*
* @return         void
*
* @note           Fast Fourier transform fft_fd (vector) = vector \n
*                 v = a000000, a000001, ..., a111111; \n
*                 u000000  = sum ( v(n)*exp(-j*2*pi* 0*(n-1)/64) ),  n = 1 ... 64 \n
*                 u100000  = sum ( v(n)*exp(-j*2*pi* 1*(n-1)/64) ),  n = 1 ... 64 \n \n
*
*                 u111111  = sum ( v(n)*exp(-j*2*pi*63*(n-1)/64) ),  n = 1 ... 64 \n
*                 fft_fd(v) = u
*
*
*/
void __stdcall C_MODEL_DLL Rsdk_SP_bflyDif2_Vo64f32cVi64f32c(rsdk_complex_float32_t * pOutput,
                                                       rsdk_complex_float32_t const * pInput);
/* TO DO Rsdk_SP_bflyInvDif2S_Vo64f32cVi64f32c */
/**
* @brief          1D FFT DIF Fast Fourier transform vector complex elements, output is BR ordered.
* @details        FFT vector 128 complex elements without bit reverse index change. \n
*                 Decimation in frequency approach, radix 2. \n
*                 Input is linear ordered, output is bit reverse ordered. \n
*                 For re-order use Rsdk_SP_bitRev_Vo128f32cVi128f32c. \n
*                 For zero padding use Rsdk_SP_zeroTrail_Vof32cVif32c.
*
*
* @param[out]     pOutput     Output vector ptr.
* @param[in]      pInput      Input vector ptr.
*
* @return         void
*
* @note           Fast Fourier transform fft_fd (vector) = vector \n
*                 v = a0000000, a0000001, ..., a1111111; \n
*                 u0000000  = sum ( v(n)*exp(-j*2*pi* 0*(n-1)/128) ),  n = 1 ... 128 \n
*                 u1000000  = sum ( v(n)*exp(-j*2*pi* 1*(n-1)/128) ),  n = 1 ... 128 \n \n
*
*                 u1111111  = sum ( v(n)*exp(-j*2*pi*127*(n-1)/128) ),  n = 1 ... 128 \n
*                 fft_fd(v) = u
*
*
*/
void __stdcall C_MODEL_DLL Rsdk_SP_bflyDif2_Vo128f32cVi128f32c(rsdk_complex_float32_t * pOutput,
                                                         rsdk_complex_float32_t const * pInput);
/* TO DO Rsdk_SP_bflyInvDif2S_Vo128f32cVi128f32c */
/**
* @brief          1D FFT DIF Fast Fourier transform vector complex elements, output is BR ordered.
* @details        FFT vector 256 complex elements without bit reverse index change. \n
*                 Decimation in frequency approach, radix 2. \n
*                 Input is linear ordered, output is bit reverse ordered. \n
*                 For re-order use Rsdk_SP_bitRev_Vo256f32cVi256f32c. \n
*                 For zero padding use Rsdk_SP_zeroTrail_Vof32cVif32c.
*
*
* @param[out]     pOutput     Output vector ptr.
* @param[in]      pInput      Input vector ptr.
*
* @return         void
*
* @note           Fast Fourier transform fft_fd (vector) = vector \n
*                 v = a00000000, a00000001, ..., a11111111; \n
*                 u00000000  = sum ( v(n)*exp(-j*2*pi* 0*(n-1)/256) ),  n = 1 ... 256 \n
*                 u10000000  = sum ( v(n)*exp(-j*2*pi* 1*(n-1)/256) ),  n = 1 ... 256 \n \n
*
*                 u11111111  = sum ( v(n)*exp(-j*2*pi*255*(n-1)/256) ),  n = 1 ... 256 \n
*                 fft_fd(v) = u
*
*
*/
void __stdcall C_MODEL_DLL Rsdk_SP_bflyDif2_Vo256f32cVi256f32c(rsdk_complex_float32_t * pOutput,
                                                         rsdk_complex_float32_t const * pInput);

/**
* @brief          1D FFT DIF Fast Fourier transform vector complex elements, output is BR ordered.
* @details        FFT vector 512 complex elements without bit reverse index change. \n
*                 Decimation in frequency approach, radix 2. \n
*                 Input is linear ordered, output is bit reverse ordered. \n
*                 For re-order use Rsdk_SP_bitRev_Vo512f32cVi512f32c. \n
*                 For zero padding use Rsdk_SP_zeroTrail_Vof32cVif32c.
*
*
* @param[out]     pOutput     Output vector ptr.
* @param[in]      pInput      Input vector ptr.
*
* @return         void
*
* @note           Fast Fourier transform fft_fd (vector) = vector \n
*                 v = a000000000, a000000001, ..., a111111111; \n
*                 u000000000  = sum ( v(n)*exp(-j*2*pi* 0*(n-1)/512) ),  n = 1 ... 512 \n
*                 u100000000  = sum ( v(n)*exp(-j*2*pi* 1*(n-1)/512) ),  n = 1 ... 512 \n \n
*
*                 u111111111  = sum ( v(n)*exp(-j*2*pi*511*(n-1)/512) ),  n = 1 ... 512 \n
*                 fft_fd(v) = u
*
*
*/
void __stdcall C_MODEL_DLL Rsdk_SP_bflyDif2_Vo512f32cVi512f32c(rsdk_complex_float32_t * pOutput,
                                                         rsdk_complex_float32_t const * pInput);

/**
* @brief          1D FFT DIF Fast Fourier transform vector complex elements, output is BR ordered.
* @details        FFT vector 1024 complex elements without bit reverse index change. \n
*                 Decimation in frequency approach, radix 2. \n
*                 Input is linear ordered, output is bit reverse ordered. \n
*                 For re-order use Rsdk_SP_bitRev_Vo1024f32cVi1024f32c. \n
*                 For zero padding use Rsdk_SP_zeroTrail_Vof32cVif32c.
*
*
* @param[out]     pOutput     Output vector ptr.
* @param[in]      pInput      Input vector ptr.
*
* @return         void
*
* @note           Fast Fourier transform fft_fd (vector) = vector \n
*                 v = a0000000000, a0000000001, ..., a1111111111; \n
*                 u0000000000  = sum ( v(n)*exp(-j*2*pi* 0*(n-1)/1024) ),  n = 1 ... 1024 \n
*                 u1000000000  = sum ( v(n)*exp(-j*2*pi* 1*(n-1)/1024) ),  n = 1 ... 1024 \n \n
*
*                 u1111111111  = sum ( v(n)*exp(-j*2*pi*1023*(n-1)/1024) ),  n = 1 ... 1024 \n
*                 fft_fd(v) = u
*
*
*/
void __stdcall C_MODEL_DLL Rsdk_SP_bflyDif2_Vo1024f32cVi1024f32c(rsdk_complex_float32_t * pOutput,
                                                           rsdk_complex_float32_t const * pInput);

/**
* @brief          1D FFT DIF Fast Fourier transform vector complex elements, output is BR ordered.
* @details        FFT vector 2048 complex elements without bit reverse index change. \n
*                 Decimation in frequency approach, radix 2. \n
*                 Input is linear ordered, output is bit reverse ordered. \n
*                 For re-order use Rsdk_SP_bitRev_Vo2048f32cVi204f32c. \n
*                 For zero padding use Rsdk_SP_zeroTrail_Vof32cVif32c.
*
*
* @param[out]     pOutput     Output vector ptr.
* @param[in]      pInput      Input vector ptr.
*
* @return         void
*
* @note           Fast Fourier transform fft_fd (vector) = vector \n
*                 v = a00000000000, a00000000001, ..., a11111111111; \n
*                 u00000000000  = sum ( v(n)*exp(-j*2*pi* 0*(n-1)/2048) ),  n = 1 ... 2048 \n
*                 u10000000000  = sum ( v(n)*exp(-j*2*pi* 1*(n-1)/2048) ),  n = 1 ... 2048 \n \n
*
*                 u11111111111  = sum ( v(n)*exp(-j*2*pi*2047*(n-1)/2048) ),  n = 1 ... 2048 \n
*                 fft_fd(v) = u
*
*
*/
void __stdcall C_MODEL_DLL Rsdk_SP_bflyDif2_Vo2048f32cVi2048f32c(rsdk_complex_float32_t * pOutput,
                                                           rsdk_complex_float32_t const * pInput);
/** @}*/

/** @addtogroup c_functions_model_fft
* @{
*/

/**
* @brief          FFT16 DIF Fast Fourier transform vector complex elements.
* @details        This function performs FFT DIF Fast Fourier transform and then reorders the
*                 results into regular order.
*
* @param[out]     pOutput     Output vector ptr.
* @param[in]      pInput      Input vector ptr.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_SP_fftDif2_Vo16f32cVi16f32c(rsdk_complex_float32_t * pOutput,
                                                      rsdk_complex_float32_t const * pInput);

/**
* @brief          FFT32 DIF Fast Fourier transform vector complex elements.
* @details        This function performs FFT DIF Fast Fourier transform and then reorders the
*                 results into regular order.
*
* @param[out]     pOutput     Output vector ptr.
* @param[in]      pInput      Input vector ptr.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_SP_fftDif2_Vo32f32cVi32f32c(rsdk_complex_float32_t * pOutput,
                                                      rsdk_complex_float32_t const * pInput);

/**
* @brief          FFT64 DIF Fast Fourier transform vector complex elements.
* @details        This function performs FFT DIF Fast Fourier transform and then reorders the
*                 results into regular order.
*
* @param[out]     pOutput     Output vector ptr.
* @param[in]      pInput      Input vector ptr.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_SP_fftDif2_Vo64f32cVi64f32c(rsdk_complex_float32_t * pOutput,
                                                      rsdk_complex_float32_t const * pInput);

/**
* @brief          FFT128 DIF Fast Fourier transform vector complex elements.
* @details        This function performs FFT DIF Fast Fourier transform and then reorders the
*                 results into regular order.
*
* @param[out]     pOutput     Output vector ptr.
* @param[in]      pInput      Input vector ptr.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_SP_fftDif2_Vo128f32cVi128f32c(rsdk_complex_float32_t * pOutput,
                                                        rsdk_complex_float32_t const * pInput);

/**
* @brief          Vector pad trailing zeros to n float32 complex elements.
* @details        Pad trailing zeros for an variable element input vector to n elements.
*                 Input vector element count should be between 1 to n-1 elements.
*                 Input and output can point to same address - inplace.
*
*
* @param[out]     pOutput       Output vector ptr.
* @param[in]      pInput        Input vector ptr.
* @param[in]      out_elem_cnt  Output vector element count.
* @param[in]      in_elem_cnt   Input vector element count.
*
* @return         void
*
* @note           Use before FFT if too few data points.
*                 vpt0 (vector) = scalar \n
*                 v = a1, a2..., an; k=1..n-1 \n
*                 vpt0 (v) =  a1, a2..., ak, 0, 0, 0, ...;
*
*/
void __stdcall C_MODEL_DLL Rsdk_SP_zeroTrail_Vof32cVif32c(rsdk_complex_float32_t * pOutput,
                                                    rsdk_complex_float32_t const * pInput,
                                                                    uint32_t const out_elem_cnt,
                                                                    uint32_t const in_elem_cnt);
/**
* @brief          FFT256 DIF Fast Fourier transform vector complex elements.
* @details        This function performs FFT DIF Fast Fourier transform and then reorders the
*                 results into regular order.
*
* @param[out]     pOutput     Output vector ptr.
* @param[in]      pInput      Input vector ptr.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_SP_fftDif2_Vo256f32cVi256f32c(rsdk_complex_float32_t * pOutput,
                                                        rsdk_complex_float32_t const * pInput);

/**
* @brief          FFT512 DIF Fast Fourier transform vector complex elements.
* @details        This function performs FFT DIF Fast Fourier transform and then reorders the
*                 results into regular order.
*
* @param[out]     pOutput     Output vector ptr.
* @param[in]      pInput      Input vector ptr.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_SP_fftDif2_Vo512f32cVi512f32c(rsdk_complex_float32_t * pOutput,
                                                        rsdk_complex_float32_t const * pInput);

/**
* @brief          FFT1024 DIF Fast Fourier transform vector complex elements.
* @details        This function performs FFT DIF Fast Fourier transform and then reorders the
*                 results into regular order.
*
* @param[out]     pOutput     Output vector ptr.
* @param[in]      pInput      Input vector ptr.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_SP_fftDif2_Vo1024f32cVi1024f32c(rsdk_complex_float32_t * pOutput,
                                                          rsdk_complex_float32_t const * pInput);

/**
* @brief          FFT2048 DIF Fast Fourier transform vector complex elements.
* @details        This function performs FFT DIF Fast Fourier transform and then reorders the
*                 results into regular order.
*
* @param[out]     pOutput     Output vector ptr.
* @param[in]      pInput      Input vector ptr.
*
* @return         void
*/
void __stdcall C_MODEL_DLL Rsdk_SP_fftDif2_Vo2048f32cVi2048f32c(rsdk_complex_float32_t * pOutput,
                                                          rsdk_complex_float32_t const * pInput);

/**
* @brief          2D Fast Fourier transform complex elements, single precision, 16x16 matrix
*
*
* @param[out]     pOutput     Output matrix ptr.
* @param[in]      pInput      Input matrix ptr.
*
* @return         void
*
* @note           This function is part of the C++ template library
*/
void __stdcall C_MODEL_DLL Rsdk_SP_fftDif2Sq_Mo16f32cMi16f32c(rsdk_complex_float32_t * pOutput,
                                                        rsdk_complex_float32_t const * pInput);

/**
* @brief          2D Fast Fourier transform complex elements, single precision, 32x32 matrix
*
*
* @param[out]     pOutput     Output matrix ptr.
* @param[in]      pInput      Input matrix ptr.
*
* @return         void
*
* @note           This function is part of the C++ template library
*/
void __stdcall C_MODEL_DLL Rsdk_SP_fftDif2Sq_Mo32f32cMi32f32c(rsdk_complex_float32_t * pOutput,
                                                        rsdk_complex_float32_t const * pInput);

/**
* @brief          2D Fast Fourier transform complex elements, single precision, 64x64 matrix
*
*
* @param[out]     pOutput     Output matrix ptr.
* @param[in]      pInput      Input matrix ptr.
*
* @return         void
*
* @note           This function is part of the C++ template library
*/
void __stdcall C_MODEL_DLL Rsdk_SP_fftDif2Sq_Mo64f32cMi64f32c(rsdk_complex_float32_t * pOutput,
                                                        rsdk_complex_float32_t const * pInput);

/**
* @brief          2D Fast Fourier transform complex elements, single precision, 128x128 matrix
*
*
* @param[out]     pOutput     Output matrix ptr.
* @param[in]      pInput      Input matrix ptr.
*
* @return         void
*
* @note           This function is part of the C++ template library
*/
void __stdcall C_MODEL_DLL Rsdk_SP_fftDif2Sq_Mo128f32cMi128f32c(rsdk_complex_float32_t * pOutput,
                                                          rsdk_complex_float32_t const * pInput);

/**
* @brief          2D Fast Fourier transform complex elements, single precision, 256x256 matrix
*
*
* @param[out]     pOutput     Output matrix ptr.
* @param[in]      pInput      Input matrix ptr.
*
* @return         void
*
* @note           This function is part of the C++ template library
*/
void __stdcall C_MODEL_DLL Rsdk_SP_fftDif2Sq_Mo256f32cMi256f32c(rsdk_complex_float32_t * pOutput,
                                                          rsdk_complex_float32_t const * pInput);

/**
* @brief          2D Fast Fourier transform complex elements, single precision, 512x512 matrix
*
*
* @param[out]     pOutput     Output matrix ptr.
* @param[in]      pInput      Input matrix ptr.
*
* @return         void
*
* @note           This function is part of the C++ template library
*/
void __stdcall C_MODEL_DLL Rsdk_SP_fftDif2Sq_Mo512f32cMi512f32c(rsdk_complex_float32_t * pOutput,
                                                          rsdk_complex_float32_t const * pInput);

/**
* @brief          2D Fast Fourier transform complex elements, single precision, 1024x1024 matrix
*
*
* @param[out]     pOutput     Output matrix ptr.
* @param[in]      pInput      Input matrix ptr.
*
* @return         void
*
* @note           This function is part of the C++ template library
*/
void __stdcall C_MODEL_DLL Rsdk_SP_fftDif2Sq_Mo1024f32cMi1024f32c(rsdk_complex_float32_t * pOutput,
                                                            rsdk_complex_float32_t const * pInput);

/**
* @brief          2D Fast Fourier transform complex elements, single precision, 2048x2048 matrix
*
*
* @param[out]     pOutput     Output matrix ptr.
* @param[in]      pInput      Input matrix ptr.
*
* @return         void
*
* @note           This function is part of the C++ template library
*/
void __stdcall C_MODEL_DLL Rsdk_SP_fftDif2Sq_Mo2048f32cMi2048f32c(rsdk_complex_float32_t * pOutput,
                                                            rsdk_complex_float32_t const * pInput);
/** @} */

/** @addtogroup c_functions_model_snr
* @{
*/

/**
* @brief          Element-wise signal-to-noise ratio or SNR in dB.
* @details        Compute Signal to noise ratio of signal and noise real vectors. \n
*                 output[k] = 10*log10(input1[k]/input2[k])  \n
*
*
* @param[out]     pOutput     Output vector ptr.
* @param[in]      pInput1     Input vector ptr.
* @param[in]      pInput2     Input vector ptr.
* @param[in]      size        Number of elements in vector, interval [1..65535].
*
*
* @return         void
*
* @note           signal-to-noise ratio (vector, vector) = vector \n
*                 v1 = n, a1, a2, ..., an; \n
*                 v2 = n, b1, b2, ..., bn; \n
*                 SNR (v1,v2) = n, 10*log10(a1/b1),... ,10*log10(an/bn); \n
*                             = n, 10*log2(a1/b1)/log2(10),... ,10*log2(an/bn)/log2(10); \n
*                             = n, 3.0103*log2(a1*rcp(b1)),... ,3.0103*log2(an*rcp(bn)); \n
*/
void __stdcall C_MODEL_DLL Rsdk_SP_SNR_Vof32Vif32Vif32(float * pOutput,
                                                 float const * pInput1,
                                                 float const * pInput2,
                                                    uint32_t   size);

/**
* @brief          Cholesky decomposition for NxN matrix - real positive-definite single precision.
* @details        Applies Cholesky decomposition on positive-definite input matrix
*                 and returns lower triangular matrix with positive real values on the main
*                 diagonal. Both the input and output matrices are assumed to be square. Size must
*                 not be smaller than 2.
*
* @param[out]     pOutput     Output real matrix ptr.
* @param[in]      pInput      Input real matrix ptr.
* @param[in]      size        Size of matrices (>= 2).
*
* @return         void
*
*/
void __stdcall C_MODEL_DLL Rsdk_LA_decLLCholPd_Mof32Mif32(float * pOutput,
                                                    float const * pInput,
                                                         uint32_t size);

/**
* @brief          Cholesky decomposition for NxN matrix - complex hermitian single precision.
* @details        Applies Cholesky decomposition on positive definite hermitian input matrix
*                 and returns lower triangular matrix with positive real values on the main
*                 diagonal. Both the input and output matrices are assumed to be square. Size must
*                 not be smaller than 2.
*
* @param[out]     pOutput     Output complex matrix ptr.
* @param[in]      pInput      Input complex matrix ptr.
* @param[in]      size        Size of matrices (>= 2).
*
* @return         void
*
*/
void __stdcall C_MODEL_DLL Rsdk_LA_decLLCholPd_Mof32cMif32c(rsdk_complex_float32_t * pOutput,
                                                      rsdk_complex_float32_t const * pInput,
                                                                            uint32_t size);

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* RSDK_CMODEL_LIB_FUNCTIONS_H_ */
