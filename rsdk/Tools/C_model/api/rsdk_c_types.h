/*
 * Copyright 2016-2018,2021-2022 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

#ifndef RSDK_C_TYPES_H_
#define RSDK_C_TYPES_H_

#ifdef __cplusplus
extern "C"{
#endif

/**
* @file           rsdk_c_types.h
*/


/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/

/** @addtogroup c_model_api_types
* @{
*/

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

/**
* @brief          C complex single precision type.
*/

#include <stdint.h>

typedef struct rsdk_complex_float32 {
    float   real; /**< @brief real part*/
    float   imag;  /**< @brief imaginary part*/
} rsdk_complex_float32_t;

typedef struct rsdk_complex_int16 {
    int16_t   real; /**< @brief real part*/
    int16_t   imag;  /**< @brief imaginary part*/
}  rsdk_complex_int16_t;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

/** @}*/

#ifdef __cplusplus
}
#endif

#endif /*RSDK_C_TYPES_H_*/
