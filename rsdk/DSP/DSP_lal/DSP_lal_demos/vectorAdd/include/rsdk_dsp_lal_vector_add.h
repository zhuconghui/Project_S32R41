/**************************************************************************************************
 * Copyright 2021-2022 NXP
 **************************************************************************************************
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 **************************************************************************************************/

#ifndef RSDK_DSP_LAL_VECTOR_ADD_H_
#define RSDK_DSP_LAL_VECTOR_ADD_H_

/**
* @file           rsdk_dsp_lal_vector_add.h
* @brief          High level application layer for the BBE Library
* @details        Layer over the BBE32 graphs.
*/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include <stdint.h>

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/** @addtogroup dsp_lal_demos_api_const
* @{
*/

#define BBE_BATCH_WIDTH 			(8U)
#define SIZE_VEC					(6U)

/** @}*/
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/** @addtogroup dsp_lal_demos_api_data
* @{
*/

typedef struct
{
	uint32_t size;       /**< <b>[in]</b> Size of the vector.*/

	/* Below data is represented as uint32_t to allow passing 32-bit addresses from A53 to BBE32.
	The buffers must be aligned at 32 bytes and size must be multiple of 32 bytes*/

	uint32_t pInput1; 			/**< <b>[in]</b> Pointer to input data 1. */
	uint32_t pInput2; 			/**< <b>[in]</b> Pointer to input data 2. */

	uint32_t pOutput; 			/**< <b>[in]</b> Pointer to output data. */

} rsdkBbe32LalVectorAddParams_t;        /**< @brief This structure is used to pass config parameters and in/out buffers for the LAL library */

/** @}*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
/** @addtogroup dsp_lal_demos_api_func_add
* @{
*/
/**
* @brief	Function to call DSP LAL library functions
* All the functions from DSP LAL are grouped inside this function to show their integration with thw DSP Dispatcher.
*
* @param [in] argList - pointer to a data structure of type rsdkBbe32LalVectorAddParams_t containing the DSP LAL parameters and buffers.
*
*/
void RsdkBbe32LalVectorAdd(uintptr_t argList);
/** @} */

#ifdef __cplusplus
}
#endif

#endif /* RSDK_DSP_LAL_VECTOR_ADD_H_ */
