/**************************************************************************************************
 * Copyright 2022-2023 NXP
 **************************************************************************************************
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 **************************************************************************************************/


/**
* @file           rsdk_dsp_lal_vec_thrshld.c
*/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "rsdk_dsp_lal.h"
#include "rsdk_dsp_lal_utils.h"
#include <xtensa/tie/xt_bbe32.h>
#include "limits.h"

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/* Binary sequence mask value */
#define BIN_SEQ_MASK  (0x0001U)

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

static const int16_t loop_mask[] = { 0, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 7, 0 };

static const uint16_t vec_mask[] = {
        USHRT_MAX, 0U, USHRT_MAX, 0U,
        USHRT_MAX, 0U, USHRT_MAX, 0U,
        USHRT_MAX, 0U, USHRT_MAX, 0U,
        USHRT_MAX, 0U, USHRT_MAX, 0U
};

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
void Rsdk_LA_threshAbs_Vof32p8Vif32cp8Vif32p8(xb_vecN_2xf32 * __restrict  pOutput,
                                                   xb_vecN_2xcf32 const * pInput1,
                                                   xb_vecN_2xf32 const *  pInput2,
                                                                 uint32_t size)
{
    xb_vecN_2xcf32 const * pin1 = pInput1;
    xb_vecN_2xf32 const * pin2  = pInput2;
    xb_vecN_2xf32 * pout        = pOutput;

    xb_vecN_2xf32 scratch1, scratch2, pin11, pin12, tempMagn;

    uint32_t iElem;
    vboolN_2 detects;

    xb_vecNx16 const * loopCount = (xb_vecNx16 const *) loop_mask;
    xb_vecNx16 const * vectorMask = (xb_vecNx16 const *) vec_mask;

    for (iElem = 0UL; iElem < size; iElem++)
    {
        /* Perform the threshold of the complex input vector, pInput1, against the square of the threshold input vector, pInput2 */
        BBE_LVN_2XF32_IP(pin11, pin1, 2*XCHAL_BBEN_SIMD_WIDTH);
        BBE_LVN_2XF32_IP(pin12, pin1, 2*XCHAL_BBEN_SIMD_WIDTH);
        RSDK_MAG2N_2XF32_V1(tempMagn, pin11, pin12, scratch1, scratch2);

        detects = BBE_OGEN_2XF32(tempMagn, (xb_vecN_2xf32)((*pin2) * (*pin2)));

        /* Copy the binary sequence (detects) to all elements of a 16 x 16-bit integer vector */
        xb_vecNx16 det_vec = BBE_MOVVA16((uint16_t)(*(uint8_t*)&detects));

        /* The below code converts the 16 x 16-bit detection vector (det_vec) to 8 x 32-bit real vector (SP-FP).
         * Suppose the following example input: detects = (0, 0, 0, 1, 0, 0, 0, 0)
         * => det_vec = BBE_MOVVA16(detects) => det_vec = (16 elements x 0x0010)
         *  Steps:
         *  1. BBE_SRANX16(det_vec, loopCount) - right shift det_vec vector elements with the values from loopCount vector
         *     result = (16, 0, 16, 0, 16, 0, 16, 1, 16, 2, 16, 4, 16, 8, 16, 16)
         *  2. BBE_ANDNX16(result, BBE_MOVVA16(BIN_SEQ_MASK)) - mask the previous result with the mask 0x0001.
         *     result = (0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0)
         *  3. BBE_ANDNX16(t2, vectorMask) - keep only the even vector elements, zero all the odd vector elements.
         *     We did so to be able to group 2 x 16-bit integer vector element to get 1 x 32-bit integer vector element in the next step.
         *  4. BBE_MOVN_2X32U_FROMNX16(result) - 16x16-bit integer vector to 8x32-bit integer vector conversion
         *     result = (0, 0, 0, 1, 0, 0, 0, 0)
         *  5. BBE_FLOATN_2X32(result) - 8x32-bit integer vector to 8x32-bit single precision floating point
         *     result = (0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0)
         * */

        /* Compute and write the output vector */
        *pout = BBE_FLOATN_2X32(BBE_MOVN_2X32U_FROMNX16(BBE_ANDNX16(BBE_ANDNX16(BBE_SRANX16(det_vec, *loopCount), BBE_MOVVA16(BIN_SEQ_MASK)), *vectorMask)), 0);

        /* Increment the pointers */
        pout++;
    }
}

void Rsdk_LA_threshAbs_Vof32p8Vif32cp8Sif32(xb_vecN_2xf32 * __restrict  pOutput,
                                                 xb_vecN_2xcf32 const * pInput1,
                                                      float32_t const * pInput2,
                                                               uint32_t size)
{
	xb_vecN_2xcf32 const * pin1 = pInput1;
	float32_t const * pin2      = pInput2;
	xb_vecN_2xf32 * pout        = pOutput;
	
    uint32_t iElem;
    vboolN_2 detects;

    xb_vecNx16 const * loopCount = (xb_vecNx16 const *)loop_mask;
    xb_vecNx16 const * vectorMask = (xb_vecNx16 const *)vec_mask;

    for (iElem = 0UL; iElem < size; iElem++)
    {
        /* Perform the threshold of the complex input vector, pInput1, against the square of the scalar threshold input, pInput2 */
        detects = BBE_OGEN_2XF32(BBE_MAGN_2XCF32(*pin1), (xb_vecN_2xf32)((*pin2) * (*pin2)));

        /* Copy the binary sequence (detects) to all elements of a 16 x 16-bit integer vector */
        xb_vecNx16 det_vec = BBE_MOVVA16((uint16_t)(*(uint8_t*)&detects));

        /* Compute and write the output vector */
        *pout = BBE_FLOATN_2X32(BBE_MOVN_2X32U_FROMNX16(BBE_ANDNX16(BBE_ANDNX16(BBE_SRANX16(det_vec, *loopCount), BBE_MOVVA16(BIN_SEQ_MASK)), *vectorMask)), 0);

        /* Increment the pointers */
        pin1++;
        pout++;
    }
}

void Rsdk_LA_thresh_Vof32p8Vif32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                               xb_vecN_2xf32 const * pInput1,
                                               xb_vecN_2xf32 const * pInput2,
                                                            uint32_t size)
{
	xb_vecN_2xf32 const * pin1 = pInput1;
	xb_vecN_2xf32 const * pin2 = pInput2;
	xb_vecN_2xf32 * pout       = pOutput;
	
    uint32_t iElem;
    vboolN_2 detects;

    xb_vecNx16 const * loopCount = (xb_vecNx16 const *)loop_mask;
    xb_vecNx16 const * vectorMask = (xb_vecNx16 const *)vec_mask;

    for (iElem = 0UL; iElem < size; iElem++)
    {
        /* Perform the threshold of the real input vector, pInput1, against the threshold input vector, pInput2 */
        detects = BBE_OGEN_2XF32((*pin1), (*pin2));

        /* Copy the binary sequence (detects) to all elements of a 16 x 16-bit integer vector */
        xb_vecNx16 det_vec = BBE_MOVVA16((uint16_t)(*(uint8_t*)&detects));

        /* Compute and write the output vector */
        *pout = BBE_FLOATN_2X32(BBE_MOVN_2X32U_FROMNX16(BBE_ANDNX16(BBE_ANDNX16(BBE_SRANX16(det_vec, *loopCount), BBE_MOVVA16(BIN_SEQ_MASK)), *vectorMask)), 0);

        /* Increment the pointers */
        pin1++;
        pout++;
    }
}

void Rsdk_LA_thresh_Vof32p8Vif32p8Sif32(xb_vecN_2xf32 * __restrict pOutput,
                                             xb_vecN_2xf32 const * pInput1,
                                                 float32_t const * pInput2,
                                                          uint32_t size)
{
	xb_vecN_2xf32 const * pin1 = pInput1;
	float32_t const *     pin2 = pInput2;
	xb_vecN_2xf32 * pout       = pOutput;
	
    uint32_t iElem;
    vboolN_2 detects;

    xb_vecNx16 const * loopCount = (xb_vecNx16 const *)loop_mask;
    xb_vecNx16 const * vectorMask = (xb_vecNx16 const *)vec_mask;

    for (iElem = 0UL; iElem < size; iElem++)
    {
        /* Perform the threshold of the real input vector, pInput1, against the scalar threshold, pInput2 */
        detects = BBE_OGEN_2XF32((*pin1), (xb_vecN_2xf32)(*pin2));

        /* Copy the binary sequence (detects) to all elements of a 16 x 16-bit integer vector */
        xb_vecNx16 det_vec = BBE_MOVVA16((uint16_t)(*(uint8_t*)&detects));

        /* Compute and write the output vector */
        *pout = BBE_FLOATN_2X32(BBE_MOVN_2X32U_FROMNX16(BBE_ANDNX16(BBE_ANDNX16(BBE_SRANX16(det_vec, *loopCount), BBE_MOVVA16(BIN_SEQ_MASK)), *vectorMask)), 0);

        /* Increment the pointers */
        pin1++;
        pout++;
    }
}

#ifdef __cplusplus
}
#endif

/*******************************************************************************
 * EOF
 ******************************************************************************/
