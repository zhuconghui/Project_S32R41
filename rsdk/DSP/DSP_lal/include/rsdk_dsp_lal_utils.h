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

#ifndef RSDK_DSP_LAL_UTILS_H_
#define RSDK_DSP_LAL_UTILS_H_

/**
* @file           rsdk_dsp_lal_utils.h
* @brief          DSP Linear Algebra Library utilities
* @details        Functions and defines.
*/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/** @addtogroup dsp_lal_api_const
* @{
*/

/* Function attributes */
/**
* @brief          Optimization options.
                  Used to modify default project code optimization level. \n
                  Can be added after function prototype.
*/
/* Level 0 -O0 Perform no optimization. This is the default when no other optimization
*              level is specified, and when used with -g it results in most accurate debug
*              information.
*/
#define OPTIMIZE_0      __attribute__((optimize("-O0")))

/* Level 1 -O1 Perform some optimization passes and inlining of functions marked with the
* always_inline attribute. */
#define OPTIMIZE_1      __attribute__((optimize("-O1")))

/* Level 2 -O2 Perform extensive global optimization passes, including function inlining. */
#define OPTIMIZE_2      __attribute__((optimize("-O2")))

/* Level 3 -O3 Perform all the optimizations as with -O2, but try more aggressively, which
*              may result in increased compile time or code size. This option also implies
*              -funsafe-math-optimizations.
*/
#define OPTIMIZE_3      __attribute__((optimize("-O3")))

/* Level S -Os Optimize for space. This option is similar to -O2, but the optimizations are
*              guided by the goal of reducing the code size.
*/
#define OPTIMIZE_S      __attribute__((optimize("-Os")))

/* Specify the attribute to force the compiler to inline a specific function */
#define BBE32_ALWAYS_INLINE         __attribute__((always_inline))

/* Use to inform the frontend to never inline a certain function. */
#define BBE32_NO_INLINE             __attribute__((noinline))


/* Float constants, single precision SP */
#define SP_pi                           ((float32_t)(3.14159265358979323846F))    /* PI */
#define SP_pi_over_2                    ((float32_t)(1.57079632679489661923F))    /* PI/2 */
#define EXP_MASK                        (BBE_MOVVA16C(0x7F800000))   /* Infinity IEEE754 == the exponent is 111...1 */
#define MANTISSA_MASK                   (BBE_MOVVA16C(0x007FFFFF))   /* first subnormal IEEE754 == the mask is 000...0 and mantissa is 111...1 */
#define INFINITY_SP                     ((float32_t)(1e+300 * 1e+300))
#define NAN_SP                          (INFINITY_SP * 0.0F)

/*! \def RSDK_MAG2N_2XF32_V1(__out, __inl1, __inl2,  __rtmp,  __itmp)
    \brief A macro that returns \a __out the absolute square, square modulus, square magnitude,
    square norm vector of two input registers of \a __inl1 and \a __inl2.

    \param __out    Output register xb_vecN_2xf32.
    \param __inl1   Input first register xb_vecN_2xf32.
    \param __inl2   Input second register xb_vecN_2xf32.
    \param __rtmp   Scratch register output real part xb_vecN_2xf32 (not initialized).
    \param __rtmp   Scratch register output imaginary part xb_vecN_2xf32 (not initialized).
*/
#define RSDK_MAG2N_2XF32_V1(__out, __inl1, __inl2,  __rtmp,  __itmp)                         \
{                                                                                              \
    BBE_DSELN_2XF32I((__itmp), (__rtmp), (__inl2), (__inl1), BBE_DSELI_DEINTERLEAVE_2);        \
    (__out) = BBE_MULN_2XF32((__rtmp), (__rtmp));                                              \
    BBE_MULAN_2XF32( (__out), (__itmp), (__itmp));                                             \
}
 
/*! \def RSDK_MAG2N_2XF32_V2(__out, __inl1, __inl2,  __rtmp,  __itmp)
    \brief A macro that returns \a __out the absolute square, square modulus, square magnitude,
    square norm vector of two input registers of \a __inl1 and \a __inl2.
 
    \param __out    Output register xb_vecN_2xf32.
    \param __inl1   Input first register xb_vecN_2xf32.
    \param __inl2   Input second register xb_vecN_2xf32.
    \param __rtmp   Scratch register output real part xb_vecN_2xf32 (not initialized).
    \param __rtmp   Scratch register output imaginary part xb_vecN_2xf32 (not initialized).
*/
#define RSDK_MAG2N_2XF32_V2(__out, __inl1, __inl2,  __rtmp,  __itmp)                       \
{                                                                                            \
    (__inl1) = BBE_MULN_2XF32((__inl1), (__inl1));                                           \
    (__inl2) = BBE_MULN_2XF32((__inl2), (__inl2));                                           \
    BBE_DSELN_2XF32I((__itmp), (__rtmp), (__inl2), (__inl1), BBE_DSELI_DEINTERLEAVE_2);      \
    (__out) = BBE_ADDN_2XF32((__rtmp), (__itmp));                                            \
}
/** @}*/

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

#ifdef __cplusplus
}
#endif


#endif /* RSDK_DSP_LAL_UTILS_H_ */
