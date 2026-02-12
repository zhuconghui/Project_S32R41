/**************************************************************************************************
* Copyright 2021-2023 NXP
**************************************************************************************************
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
**************************************************************************************************/

/*
 * rfeDspMath_pcmath.h
 *     proxy compatible copy ==> Look in rfedspmath.h for clarification and doxygen
 *     prevents loads of manual corrections 
 *
 *  Created on:  
 *                  
 *      Author: 
 *
 */

#ifndef RFE_DSP_MATH_PCMATH_H_
#define RFE_DSP_MATH_PCMATH_H_

#include <stddef.h>
#include <math.h>

#include "rfeDspSystem.h"
#include "rfe_error.h"

/*****************************************************************************************
 * Special integer, float numbers and math constant  ( DO NOT ASK ME :-( )
 ****************************************************************************************/
#define RFE_DSP_FLOAT_TO_INT_CONVERSION_THRESHOLD ( ( float32_t ) 0.5f)

/* Maximum and minimum of int32_t, int16_t and int8_t value */
#define MAX_INT64_VALUE            ( (int64_t)(0x7FFFFFFFFFFFFFFFUL) )
#define MIN_INT64_VALUE            ( (int64_t)(0x8000000000000000UL) )
#define MAX_INT32_VALUE            ( (int32_t)(0x7FFFFFFFUL) )
#define MIN_INT32_VALUE            ( (int32_t)(0x80000000UL) )
#define MAX_INT16_VALUE            ( (int16_t)0x7FFFU )
#define MIN_INT16_VALUE            ( (int16_t)0x8000U )
#define MAX_INT8_VALUE             ( (int8_t)0x7FU )
#define MIN_INT8_VALUE             ( (int8_t)0x80U )

/* Special numbers used in floating point value conversion */
#define RFE_DSP_FLOAT_LEAD_BIT_VALUE       (   0x800000UL )
#define RFE_DSP_FLOAT_MANTISSA_MASK        (   0x7FFFFFUL )
#define RFE_DSP_FLOAT_POSITIVE_MAX         ( 0x7F7FFFFFUL )
#define RFE_DSP_FLOAT_POSITIVE_MIN         ( 0x00000001UL )
#define RFE_DSP_FLOAT_A_NEG_NAN            ( 0xFFFFFFFFUL )
#define RFE_DSP_FLOAT_A_POS_NAN            ( 0x7FFFFFFFUL )
#define RFE_DSP_FLOAT_POS_INFINIT          ( 0x7F800000UL )
#define RFE_DSP_FLOAT_NEG_INFINIT          ( 0xFF800000UL )
#define RFE_DSP_FLOAT_SIGN_MASK            ( 0x80000000UL )
#define RFE_DSP_FLOAT_VALUE_MASK           ( 0x7FFFFFFFUL )
#define RFE_DSP_FLOAT_DENORMAL_MASK        ( 0x7F800000UL )

/* Some float numbers */
#define RFE_DSP_FLOAT_1EN8                 ( 0x322BCC77UL )
#define RFE_DSP_FLOAT_1EN7                 ( 0x33D6BF95UL )
#define RFE_DSP_FLOAT_1EN6                 ( 0x358637BDUL )
#define RFE_DSP_FLOAT_1EN5                 ( 0x3727C5ACUL )
#define RFE_DSP_FLOAT_1EN4                 ( 0x38D1B717UL )
#define RFE_DSP_FLOAT_1EN3                 ( 0x3A83126FUL )
#define RFE_DSP_FLOAT_1EN2                 ( 0x3C23D70AUL )
#define RFE_DSP_FLOAT_1EN1                 ( 0x3DCCCCCDUL )

#endif /*RFE_DSP_MATH_H_*/

