
/*
 * Copyright 2021-2024 NXP
 * NXP Confidential and Proprietary.
 * This software is owned or controlled by NXP and may only be used strictly
 * in accordance with the applicable license terms. By expressly accepting
 * such terms or by downloading, installing, activating and/or otherwise using
 * the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms. If you do not agree to be
 * bound by the applicable license terms, then you may not retain, install,
 * activate or otherwise use the software.
 */

#ifndef RFE_DSP_MATH_H_
#define RFE_DSP_MATH_H_

#include <stddef.h>

#include "rfeDspSystem.h"
#include "rfe_error.h"
#include "rfe_types.h"

/*****************************************************************************************
 * Special integer, float numbers and math constant
 ****************************************************************************************/
#define RFE_DSP_FLOAT_TO_INT_CONVERSION_THRESHOLD ( ( float32_t ) 0.5f)

/* Maximum and minimum of int32_t, int16_t and int8_t value */
#define MAX_INT64_VALUE            ( (int64_t)(0x7FFFFFFFFFFFFFFFLL) )
#define MIN_INT64_VALUE            ( (int64_t)(~0x7FFFFFFFFFFFFFFFLL) )
#define MAX_INT32_VALUE            ( (int32_t)(0x7FFFFFFFL) )
#define MIN_INT32_VALUE            ( (int32_t)(~0x7FFFFFFFL) )
#define MAX_INT16_VALUE            ( (int16_t)32767 )
#define MIN_INT16_VALUE            ( (int16_t)-32768 )
#define MAX_INT8_VALUE             ( (int8_t)127 )
#define MIN_INT8_VALUE             ( (int8_t)-128 )

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

/* Math constant log10(2) */
#ifndef LOG10_2
 #define LOG10_2                           ( 0.3010300099849700927734375F )
#endif
/* Math constant PI, PI/2 and PI/4 */
#ifndef M_PI
 #define M_PI                              ( 3.14159265358979323846F )
#endif

#ifndef M_PI_2
 #define M_PI_2                            ( M_PI / 2.0F )
#endif

#ifndef M_PI_4
 #define M_PI_4                            ( M_PI / 4.0F )
#endif


/*****************************************************************************************
 * Complex data types and MACRO functions used in rfeDspMath functions
 *
 *****************************************************************************************/
/**
 * \brief cint16_t complex int16 type
 */
typedef struct
{
    int16_t re; /*## attribute int16 real element */
    int16_t im; /*## attribute int16 imaginary element */
} cint16_t;

/**
 * \brief cint32_t complex int32 type
 */
typedef struct
{
    int32_t re; /*## attribute int32 real element */
    int32_t im; /*## attribute int32 imaginary element */
} cint32_t;

/**
 * \brief cfloat32_t complex single precision float type
 */
typedef struct
{
    float32_t re; /*## attribute float real element */
    float32_t im; /*## attribute float imaginary element */
} cfloat32_t;

/**
 * \brief int16x2_t two int16_t values together for M7 load as one 32bit value 
 */
typedef int32_t  int16x2_t;

typedef struct {
    int16_t val_l16;
    int16_t val_h16;
} int16x2Val_t; 

/**
 * \brief uint16x2_t two uint16_t values together for M7 load as one 32bit value 
 */
typedef uint32_t  uint16x2_t;

/**
 * rfeDsp_floatIeeeU32BitsUnion_t
 * Union used for get IEEE754-2008 format bits of a float value 
 */
typedef union {
    float32_t   val_float;      /*## attribute val_float */
    uint32_t    val_u32;        /*## attribute val_u32 */
}rfeDsp_floatIeeeU32BitsUnion_t;

/*****************************************************************************************
 * MACRO functions
 *
 *****************************************************************************************/
/**
 * \brief   RFE_DSP_VCVT_F2I
 * \details Convert a float value to an int32_t value, which is equal to (int32_t) casting.
 * \param [in]    sf      float value 
 * \return        result  converted int32_t value 
 */
__attribute__( ( always_inline ) ) static inline int32_t RFE_DSP_VCVT_F2I( float32_t sf )
{
  int32_t result;
  float32_t sReg;
  __ASM volatile ( "VCVTR.S32.F32 %0, %1" : "=t" (sReg) : "t" (sf) );
  __ASM volatile ( "VMOV %0, %1"  : "=r" (result) : "t" (sReg) );
  return result;
}

/*****************************************************************************************
 * Very basic functions
 *****************************************************************************************/

/**
 * \brief   rfeDspMath_unpackLowI16x2
 * \details Extract low 16-bit int16_t value from a int16x2_t value.
 * \param [in]    A      input value
 * \return        low 16-bit of the input value
 */
static inline int16_t rfeDspMath_unpackLowI16x2 ( int16x2_t valI16x2 )
{
    /* coverity[cert_int31_c_violation] we should do the logical & operation only on unsigned values, so below casting is required */
    uint32_t low16Bits = ( ( uint32_t )valI16x2 ) & 0x0000FFFFUL;
    /* coverity[cert_int31_c_violation]low16Bits having only lower 16 bit value of valI16x2, will not overflow */
    return ( int16_t )low16Bits;
}

/**
 * \brief   rfeDspMath_unpackHighI16x2
 * \details Extract high 16-bit int16_t value from a int16x2_t value.
 * \param [in]    A      input value 
 * \return        high 16-bit of the input value 
 */
static inline int16_t rfeDspMath_unpackHighI16x2 ( int16x2_t valI16x2 )
{
    /* coverity[cert_int31_c_violation]valI16x2 is designed to contain two signed integer 16-Bit values and need to extract the value stored in the higher part. Right shift of signed integers could become incompatible, so required unsigned value.*/
    uint32_t high16Bits = ( ( uint32_t )valI16x2 ) >> 16U;
    return ( int16_t )high16Bits;
}

/*****************************************************************************************
 * DSP & FPU functions: single-precision float and fixed-point Q31 / Q15 conversion
 *
 *****************************************************************************************/
/**
 * \brief   rfeDspMath_floatToQ15: inline function to covert float to Q15
 * \details Convert float value to Q15.nFranctionBits values and output saturation flag.
 * \attention  NaNs are converted to 0. +-infinite are converted to MAX_INT16_VALUE or MIN_INT16_VALUE with saturation set.
 * \param [in]      f32                          single-precision floating-point value.
 * \param [in]      nFractionBits                Number of fractional bits, must be in [0,15].
 * \param [out]     pSaturated                   Output saturation flag.
 * \return          The converted Q15 value.
 * \result  Cycles: ?  
 */
static inline int16_t rfeDspMath_floatToQ15(
 float32_t f32,
 uint8_t nFractionBits, 
 bool* const pSaturated
)
{
    int16_t v16 = ( int16_t )nFractionBits;
    float32_t f32b = f32;
    if ( v16 > 15 ) 
    {
        uint32_t u32 = 1UL << 30U;
        float32_t onePower30F = ( float32_t )u32;
        while ( v16 > 30 ) 
        { 
            f32b *= onePower30F;
            v16 -= 30;
        }
        u32 = 1UL << ( uint8_t )v16;
        f32b *= ( float32_t )u32;
    }
    else
    {
        uint32_t u32 = 1UL << ( uint8_t )v16;
        f32b *= ( float32_t )u32;
    }

    int32_t v32 = RFE_DSP_VCVT_F2I( f32b );
    if ( MIN_INT16_VALUE > v32 )
    {
        v16 = MIN_INT16_VALUE;
        *pSaturated = true;
    }
    else if ( MAX_INT16_VALUE >= v32 )
    {
        v16 = ( int16_t )v32;
        *pSaturated = false;
    }
    else
    {
        v16 = MAX_INT16_VALUE;
        *pSaturated = true;
    }
    /* coverity[overflow_sink] This return value is well within FLOAT32_MIN and FLOAT32_MAX boundaries so this violation can be safely ignored. */
    return v16;
}

/**************************************************************************************************
 * DSP & FPU functions: log2, log10 and complex absolute decibal functions.  
 *                Note: integration test of fixed-point log2 and log10 functions are not done yet.
 **************************************************************************************************/
/**
 * \brief   rfeDspMath_log2fValidX: log2 of valid input xLargerThan1eMinus37 with single-precision floating-point 
 *          input and result.
 *
 * \details Calculate log2(x) using Remez algoritm with hand tuned constants for 32 bit float. Accuracy 
 *          was 19.5 bits and is now 20.5 bits for values larger than 1e-37.
 *
 * \attention   The caller must guarantee valid input >= 1e-37.
 * 
 * \param [in]      xLargerThan1eMinus37       input value >= 1e-37F.
 *
 * \return  log2(x) in float format.
 *
 * \post    NIL
 *
 * \ingroup NIL
 *
 * \result  +/- ? cycles
 *
 * \authors  nlv10844 & nlv13279   
 */
__attribute__( ( always_inline ) ) static inline float32_t rfeDspMath_log2fValidX ( const float32_t xLargerThan1eMinus37 )
{
    rfeDsp_floatIeeeU32BitsUnion_t unionFloat;
    unionFloat.val_float = xLargerThan1eMinus37;
    register uint32_t ieee754U32 = unionFloat.val_u32;
    uint32_t manU32 = ( ieee754U32 & 0x007FFFFFUL ) | 0x3F000000UL; 
    unionFloat.val_u32 = manU32;
    register float32_t manF = unionFloat.val_float;
 
	register float32_t resF = ( float32_t )( ieee754U32 ) * 1.1920928955078125E-7F;
    resF -= 124.2254486083984375F + ( 1.49802935123443603515625F * manF );
	resF -= ( 1.72588002681732177734375F / (0.3520887792110443115234375F + manF) );

    /* coverity[overflow_sink] This return value is well within FLOAT32_MIN and FLOAT32_MAX boundaries so this violation can be safely ignored. */
    return resF;
}

/**
 * \brief   rfeDspMath_log2F: log2 with single-precision floating-point result.
 *
 * \details Calculate log2(x) using Remez algoritm with hand tuned constants for 32 bit float. Accuracy 
 *          was 19.5 bits and is now 20.5 bits for values larger than 1e-37.
 *
 * \attention   It returns -NaN for input x<0, and returns -INF if input < RFE_DSP_FLOAT_POSITIVE_MIN (~1.4e-45).
 * 
 * \param [in]      x       recommend input value >= 1e-37F.
 *
 * \return  log2(x) in float format.
 *
 * \post    NIL
 *
 * \ingroup NIL
 *
 * \result  +/- 312/11=28 cycles
 *
 * \authors  nlv10844 & nlv13279   
 */

/* coverity[misra_c_2012_rule_5_9_violation]
 * Static inline functions are listed as exceptions to this rule as per MISRA C 2012 guidelines.
 */
__attribute__( ( always_inline ) ) static inline float32_t rfeDspMath_log2F ( const float32_t x )
{
    register float32_t resF;
    rfeDsp_floatIeeeU32BitsUnion_t unionFloat;
    unionFloat.val_u32 = RFE_DSP_FLOAT_POSITIVE_MIN;
    float32_t positiveMinF = unionFloat.val_float;
    
    if ( x >= positiveMinF )
    {
        resF = rfeDspMath_log2fValidX( x );
    }
    else
    {
        if ( x < 0.0F )
        {
            unionFloat.val_u32 = RFE_DSP_FLOAT_A_NEG_NAN;
            resF = unionFloat.val_float;
        }
        else
        {
            unionFloat.val_u32 = RFE_DSP_FLOAT_NEG_INFINIT; 
            resF = unionFloat.val_float;
        }
    }
    
    return resF;
}

/**
 * \brief   rfeDspMath_absCF32dB: Calculate complex absolute of cfloat32_t array, output results in float format.
 *
 * \details Calculate complex absolute value of each cfloat32_t value in input array and output float results.
 *
 * \param [in]   pCF32      Pointer to cfloat32_t input array.
 * \param [in]   nElements  Number of elements in the input and output array.
 * \param [out]  pAbsF32dB  Pointer to output array.
 *
 * \return  NIL
 *
 * \post    NIL
 *
 * \ingroup NIL
 *
 * \result  +/- 3617/64 = 57 cycles per value
 *
 * \authors  nlv13279  
 */
void rfeDspMath_absCF32dB(
 const cfloat32_t* pCF32,
 uint32_t nElements,
 float32_t* pAbsF32dB,
 rfe_error_t* rfe___error___pointer
);

/*****************************************************************************************
 * DSP & FPU functions: atan2 and angle functions
 *
 *****************************************************************************************/
/**
 * \brief   rfeDspMath_atan2F: get angle of a single-precision floating-point vector position at (x, y)
 *
 * \details Calculate radian angle of a point (x, y) in a 2D x-y plane, in range of [-pi, pi], using 
 *          IEEE754-2008 single-precision floating-point format definition.
 *          This function checks demormal floating values such as NaN and infinite. For special
 *          input, it returns the following table like in Matlab:
 *                     y           x           angle
 *                    NaN         any           NaN
 *                    any         NaN           NaN
 *                    INF         INF           pi/4
 *                    INF        -INF          3pi/4
 *                   -INF         INF          -pi/4
 *                   -INF        -INF         -3pi/4
 *                    INF        normal         pi/2
 *                   -INF        normal        -pi/2
 *                  +/-0.0F      >=-0.0F        0.0F    =>Note: same as MatLab, see attention
 *                    0.0F       <-0.0F          pi
 *                   -0.0F       <-0.0F         -pi
 *                   >0.0F      +/-0.0F         pi/2
 *                   <0.0F      +/-0.0F        -pi/2
 *                  >=0.0F       -INF            pi
 *                  <=-0.0F      -INF           -pi
 *                   normal       INF           0.0F
 *
 * \attention
 * 1. The return for case ( y=+/-0.0F, x=-0.0F ) is the same as MatLab, but different to C <math> .
 * 2. We select 5 iterations as default in this matan2 function. For people wants faster with less iterations, 
 *    or more accurate with more iterations, you can change the MATAN2_ITERATION definition. 
 * 
 * The performance over iterations is listed below:
 *    Iter.   Accu. Bits   Corr factor   Corrected Accu. Bits     Cycles with -Ofast
 *                                        Worst    Average     arm_clang  orig.   arm_gcc 
 *      2         2         0.833279       6.0       6.0                  (101)
 *      3         3         0.960733       9.2       9.2                  (129)
 *      4         4         0.990317      12.3      12.2           134    (152)     124
 *      5         5         0.997588      15.3      15.3           157    (163)     146
 *      6         6         0.999400      18.2      18.4           179    (188)     169
 *      7         7         0.999851      20.5      21.3           200    (203)     188
 *      8         8         0.999970      21.8      23.6           226    (222)     210
 *      9         9         0.999990      22.1      25.6           246    (239)     236
 *
 * \param [in]      x       position projection on the x axis.
 * \param [in]      y       position projection on the y axis.
 *
 * \return  floating-point radian angle in [-pi, pi].
 *
 * \post    NIL
 *
 * \ingroup NIL
 *
 * \result  accuracy:  < +/- 0.05 degree
 *          cycles:  1332/24 = 55.5 cycles per value
 * \authors  nlv10844 & nlv13279   
 */
// Define your wanted accuracy here by iteration that must be in [2, 9]. More than 9 will not give more accuracy.  
#define MATAN2_ITERATIONS  5

extern const float32_t rfeDspMath_matan2SIN[10];
extern const float32_t rfeDspMath_matan2COS[10];
 
__attribute__( ( always_inline ) ) static inline float32_t rfeDspMath_atan2F( const float32_t y, const float32_t x )
{
    static const float32_t rfeDspMath_matan2CorrFactors[8] = {
     0.833279F, 0.960733F,  0.990317F, 0.997588F, 0.999400F, 0.999851F, 0.999970F, 0.999990F
    };
    register float32_t a = 0.0F;
    rfeDsp_floatIeeeU32BitsUnion_t unionFloat;
    unionFloat.val_float = x;
    register uint32_t xU32 = unionFloat.val_u32;  // in IEEE754-2008 format
    unionFloat.val_float = y;
    register uint32_t yU32 = unionFloat.val_u32;  // in IEEE754-2008 format
    register uint32_t absXU32 = xU32 & RFE_DSP_FLOAT_VALUE_MASK;
    register uint32_t absYU32 = yU32 & RFE_DSP_FLOAT_VALUE_MASK;
    
    /**
     *  Handle special cases:
     *   return NaN, if x or y is NaN;
     */
    if ( ( ( RFE_DSP_FLOAT_DENORMAL_MASK & xU32 ) == RFE_DSP_FLOAT_DENORMAL_MASK ) ||
         ( ( RFE_DSP_FLOAT_DENORMAL_MASK & yU32 ) == RFE_DSP_FLOAT_DENORMAL_MASK ) )
    {
        // If y is denormal value
        if ( ( RFE_DSP_FLOAT_DENORMAL_MASK & yU32 ) == RFE_DSP_FLOAT_DENORMAL_MASK )
        {
            //y is NaN 
            if ( ( yU32 & RFE_DSP_FLOAT_MANTISSA_MASK ) != 0UL )
            {
                a = y;  // return a NaN	if any of x or y is NaN
            }
            else // y is infinite
            {
                // x is denormal
                if ( ( RFE_DSP_FLOAT_DENORMAL_MASK & xU32 ) == RFE_DSP_FLOAT_DENORMAL_MASK ) 
                {
                    if ( ( xU32 & RFE_DSP_FLOAT_MANTISSA_MASK ) != 0UL )  // x is NaN
                    {
                        a = x;  // return a NaN	if any of x or y is NaN
                    }
                    else // both x and y are infinite, return +/-pi/4 or +/-3pi/4 
                    {
                        if ( ( xU32 & RFE_DSP_FLOAT_SIGN_MASK ) == 0UL )  // in 1st or 4th quarter, return +/-pi/4 
                        {
                            a = ( ( yU32 & RFE_DSP_FLOAT_SIGN_MASK ) > 0UL ) ? ( -M_PI_4 ) : ( M_PI_4 );
                        }
                        else // in 2nd or 3rd quarter, return +/-3pi/4 
                        {
                            a = ( ( yU32 & RFE_DSP_FLOAT_SIGN_MASK ) > 0UL ) ? ( -M_PI_4 * 3.0F ) : ( M_PI_4 * 3.0F );  
                        }
                    }
                }
                else // x is normal, return +/- pi/2  
                {
                    a = ( ( yU32 & RFE_DSP_FLOAT_SIGN_MASK ) > 0UL ) ? ( -M_PI_2 ) : ( M_PI_2 );  
                }
            }
        }
        else  // y is normal, then x must be denormal
        {
            if( ( xU32 & RFE_DSP_FLOAT_MANTISSA_MASK ) != 0UL )  // x is NaN
            {
                a = x;  // return a NaN	if any of x or y is NaN
            }
            else // x must be infinite  
            {
                if ( ( xU32 & RFE_DSP_FLOAT_SIGN_MASK ) > 0UL )   // x = -inf, return +/-Pi
                {
                    a = ( ( yU32 & RFE_DSP_FLOAT_SIGN_MASK ) > 0UL ) ? ( -M_PI ) : ( M_PI );  
                }
                else // x=inf, y is normal, return 0.0F  
                {
                    a = 0.0F;  
                }
            }
        }
    }
    /**
     *  Handle normal values, including zeros
     */
    else
    {
        register float32_t x1 = x;
        register float32_t y1 = y;
        register float32_t downS = 2.0F;
        if((absXU32 <= 0x00000800UL) && (absYU32 <= 0x00000800UL)) // upscale small values
        {
            absXU32 <<= 11U;
            absYU32 <<= 11U;
            uint32_t sU = 1UL << 11U;  // Add sU to comply MISRA rule 10.8 
            float32_t sF = (float32_t)sU;
            x1 *= sF;
            y1 *= sF;
        }
        else // downscale big values to deal with big values like 1e+38
        {
            absXU32 >>= 1U;
            absYU32 >>= 1U;
            x1 /= downS;
            y1 /= downS;
        }

        /**
         *  Handle normal values: both are non-zero
         */
        if((absXU32 > 0UL) && (absYU32 > 0UL))  // both non-zero
        {
            // scale down to create headroom for rotatin of extreme large number (> e+38)
            register float32_t da = M_PI_2;

            if(y1 > 0.0F)
            {
                a += da;
                da /= downS;
                if ( x1 < 0.0F )
                {
                    register float32_t y2 = (y1 + x1) * ( -0.7071067812F ) ;
                    x1 = ( y1 - x1 ) * 0.7071067812F;
                    y1 = y2;
                    a += da;
                }
                else
                {
                    register float32_t y2 = (y1 - x1) * 0.7071067812F;
                    x1 = ( x1 + y1 ) * 0.7071067812F;
                    y1 = y2;
                    a -= da;
                }
            }
            else
            {
                a -= da;
                da /= downS;
                if ( x1 > 0.0F )
                {
                    register float32_t y2 = (y1 + x1) * 0.7071067812F;
                    x1 = ( x1 - y1 ) * 0.7071067812F;
                    y1 = y2;
                    a += da;
                }
                else
                {
                    register float32_t y2 = (x1 - y1) * 0.7071067812F;
                    x1 = (x1 + y1) * ( -0.7071067812F );
                    y1 = y2;
                    a -= da;
                }
            }
            da /= downS;
            
            for(register int8_t i = 2; i < MATAN2_ITERATIONS; i++)
            {
                register float32_t x2 = x1 * rfeDspMath_matan2SIN[i];
                register float32_t y2 = y1 * rfeDspMath_matan2SIN[i];
                
                if( y1 > 0.0F )
                {
                    x1 = (x1 * rfeDspMath_matan2COS[i]) + y2;
                    y1 = (y1 * rfeDspMath_matan2COS[i]) - x2;
                    // update angle
                    a += da;
                }
                else
                {
                    x1 = (x1 * rfeDspMath_matan2COS[i]) - y2;
                    y1 = (y1 * rfeDspMath_matan2COS[i]) + x2;
                    // update angle
                    a -= da;
                }
                
                da /= downS;
            }
            
            // use remainder as for final correction for more accuracy
            if(x1 > 0.0F)
            {
                a += (rfeDspMath_matan2CorrFactors[MATAN2_ITERATIONS - 2] * y1) / x1;
            }
        }
        /**
         *  Handle normal values: at least one of x and y is zero
         */
        else  // at least one of x and y is zero
        {
            if ( absYU32 == 0UL )  // y is zero
            {
                if ( x < -0.0F )
                {
                    a = ((yU32 & RFE_DSP_FLOAT_SIGN_MASK) > 0UL) ? ( -M_PI ) : ( M_PI );  // if y ==-0.0, return -pi;
                }
                else
                {
                    a = 0.0F;
                }
            }
            else  // y is non-zero, then x must be zero;
            {
                a = ((yU32 & RFE_DSP_FLOAT_SIGN_MASK ) > 0UL) ? ( -M_PI_2 ) : ( M_PI_2 );
            }
        }
    }

    /* coverity[overflow_sink] This return value is well within FLOAT32_MIN and FLOAT32_MAX boundaries so this violation can be safely ignored. */
    return a;
}

#endif /*RFE_DSP_MATH_H_*/
