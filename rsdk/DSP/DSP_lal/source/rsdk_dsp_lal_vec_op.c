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


/**
* @file           rsdk_dsp_lal_vec_op.c
*/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "rsdk_dsp_lal.h"
#include "rsdk_dsp_lal_utils.h"

#ifdef __cplusplus
extern "C"{
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

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

void Rsdk_EF_mod_Vof32p8Vif32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
		                                          xb_vecN_2xf32 * pInput1,
		                                          xb_vecN_2xf32 * pInput2,
		                                                 uint32_t size)
{
	xb_vecN_2xf32 * pin1 = pInput1;
	xb_vecN_2xf32 * pin2 = pInput2;
	xb_vecN_2xf32 * pout = pOutput;
	
    xb_vecN_2xf32 x, y, z1;
    vboolN_2 flagsA;
    xb_vecN_2xf32 zero = (xb_vecN_2xf32)0.0F;
    xb_vecN_2xf32 z2 = (xb_vecN_2xf32)0.0F;
    uint32_t iElem;

    for (iElem = 0UL; iElem < size; iElem++)
    {
        x = *pin1;
        y = *pin2;
        flagsA = (vboolN_2)(y != zero);
        BBE_DIVN_2XF32T(z2, x, y, flagsA); // predication for zero values
        z1 = BBE_FIFLOORN_2XF32(z2)*y;
        *pout = x - z1;

        pin1++;
        pin2++;
        pout++;
    }
}

void Rsdk_EF_sqrt_Vof32cp8Vif32cp8(xb_vecN_2xcf32 * __restrict pOutput,
		                                      xb_vecN_2xcf32 * pInput,
		                                              uint32_t size)
{
	xb_vecN_2xcf32 * pin  = pInput;
	xb_vecN_2xcf32 * pout = pOutput;
	
	xb_vecN_2xcf32 w, x;
	xb_vecN_2xf32 wRe, wIm;			// eq Re{w}, Im{w}
	xb_vecN_2xf32 r;				// eq |pInput|
	xb_vecN_2xf32 modzdplusr;		// eq |pInput'+r|
	xb_vecN_2xf32 k;				// scratch
	xb_vecN_2xf32 zdRepr;			// pInput'.Re+r
	xb_vecN_2xf32 zero;				// scratch
	vboolN_2 flagsA, flagsB;		// predication flags
	uint32_t iElem;

	for (iElem = 0UL; iElem < size; iElem++)
	{
		x = *pin;
	    zero = (xb_vecN_2xf32)0.0F;
		k = zero;
		r = BBE_SQRTN_2XF32((BBE_CREALN_2XCF32(x) * BBE_CREALN_2XCF32(x)) + (BBE_CIMAGN_2XCF32(x) * BBE_CIMAGN_2XCF32(x)));
		zdRepr = BBE_ABSN_2XF32(BBE_CREALN_2XCF32(x)) + r;
		modzdplusr = BBE_SQRTN_2XF32((zdRepr * zdRepr) + (BBE_CIMAGN_2XCF32(x) * BBE_CIMAGN_2XCF32(x)));
		flagsA = (vboolN_2)(modzdplusr != zero);
		BBE_DIVN_2XF32T(k, BBE_SQRTN_2XF32(r), modzdplusr, flagsA);
		flagsB = (vboolN_2)(BBE_CREALN_2XCF32(x) < zero);
		wRe = k * zdRepr;
		wIm = k * BBE_CIMAGN_2XCF32(x);
		BBE_MULN_2XF32T(wRe, k, BBE_ABSN_2XF32(BBE_CIMAGN_2XCF32(x)), flagsB);
		BBE_MULN_2XF32T(wIm, k, zdRepr, flagsB);

		w = BBE_CMPLXN_2XF32(wIm, wRe);
		flagsA = (vboolN_2)(BBE_CIMAGN_2XCF32(x) < zero);
		BBE_CONJN_2XCF32T(w, w, BBE_ANDBN_2(flagsA, flagsB));
		*pout = w;

        pin++;
        pout++;
	}
}

void Rsdk_EF_sqrtAbs_Vof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
		                                       xb_vecN_2xf32 * pInput,
		                                              uint32_t size)
{
	xb_vecN_2xf32 * pin  = pInput;
	xb_vecN_2xf32 * pout = pOutput;
	
    xb_vecN_2xf32 x, r;
    uint32_t iElem;

    for (iElem = 0UL; iElem < size; iElem++)
    {
        x = *pin;
        r = BBE_ABSN_2XF32(x);
        *pout = BBE_SQRTN_2XF32(r);

        pin++;
        pout++;
    }
}

void Rsdk_EF_sqrt_Vof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
		                                    xb_vecN_2xf32 * pInput,
		                                           uint32_t size)
{
	xb_vecN_2xf32 * pin  = pInput;
	xb_vecN_2xf32 * pout = pOutput;
	
    xb_vecN_2xf32 r;
    uint32_t iElem;

    for (iElem = 0UL; iElem < size; iElem++)
    {
        r = *pin;
        *pout = BBE_SQRTN_2XF32(r);

        pin++;
        pout++;
    }
}

void Rsdk_LA_hypot_Vof32p8Vif32p8Vif32p8(xb_vecN_2xf32 * restrict pOutput,
                                                  xb_vecN_2xf32 * pInput1,
                                                  xb_vecN_2xf32 * pInput2,
                                                         uint32_t size)
{
    xb_vecN_2xf32 * pin1 = pInput1;
    xb_vecN_2xf32 * pin2 = pInput2;
    xb_vecN_2xf32 * pout = pOutput;

    xb_vecN_2xf32 a, b, r1, r;
    vboolN_2 flagsA, flagsB, flagsAB;
    uint32_t iElem;

    for (iElem = 0UL; iElem < size; iElem++)
    {
        a = BBE_ABSN_2XF32(*pin1); pin1++;
        b = BBE_ABSN_2XF32(*pin2); pin2++;

        //hypot(nan, inf) = inf
        flagsA = (vboolN_2)(a != a);
        flagsB = (vboolN_2)(b == (xb_vecN_2xf32)INFINITY_SP);
        flagsAB = (vboolN_2)(flagsA & flagsB);

        //hypot(nan, -inf) = inf
        flagsB = (vboolN_2)(b == (xb_vecN_2xf32)(-1.0F*INFINITY_SP));
        flagsAB |= (vboolN_2)(flagsA & flagsB);

        //hypot(inf, nan) = inf
        flagsA = (vboolN_2)(a == (xb_vecN_2xf32)INFINITY_SP);
        flagsB = (vboolN_2)(b != b);
        flagsAB |= (vboolN_2)(flagsA & flagsB);

        //hypot(-inf, nan) = inf
        flagsA = (vboolN_2)(a == (xb_vecN_2xf32)(-1.0F*INFINITY_SP));
        flagsAB |= (vboolN_2)(flagsA & flagsB);

        r1 = BBE_MULN_2XF32(a, a);
        BBE_MULAN_2XF32(r1, b, b);

        r = BBE_SQRTN_2XF32(r1);

        *pout = BBE_MOVN_2XF32T((xb_vecN_2xf32)INFINITY_SP, r, flagsAB);	// true, false, flags
        pout++;
    }
}

void Rsdk_LA_rcp_Vof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
		                                   xb_vecN_2xf32 * pInput,
		                                          uint32_t size)
{
	xb_vecN_2xf32 * pin  = pInput;
	xb_vecN_2xf32 * pout = pOutput;
	
	xb_vecN_2xf32 x, z;
	xb_vecN_2xf32 zeros = (xb_vecN_2xf32)0.0F;
	vboolN_2 iszero;
	uint32_t iElem;

	/*
	* @note
	* TO DO: \n
	* to be discussed the Xtensa`s issue with reciprocal function,\n
	* i.e., BBE_RECIPN_2XF32(0) = NAN which is not IEEE-754 compliant \n
	* BBE_RECIPN_2XF32(0) = INFINITY according to IEEE-754
	*/
	for (iElem = 0UL; iElem < size; iElem++)
	{
		x = *pin;
		iszero  = (vboolN_2)(x == zeros);

		z = BBE_MOVN_2XF32T(BBE_RECIPN_2XF32(x), (xb_vecN_2xf32)INFINITY_SP, BBE_NOTBN_2(iszero));
		*pout = z;

        pin++;
        pout++;
	}
}

void Rsdk_LA_rcp_Vof32cp8Vif32cp8(xb_vecN_2xcf32 * __restrict pOutput,
		                                     xb_vecN_2xcf32 * pInput,
		                                             uint32_t size)
{
	xb_vecN_2xcf32 * pin  = pInput;
	xb_vecN_2xcf32 * pout = pOutput;
	
	xb_vecN_2xcf32 x, z;
	xb_vecN_2xcf32 zeros = (xb_vecN_2xcf32)0.0F;
	vboolN_2 iszero;
	uint32_t iElem;

	/*
	* @note
	* TO DO: \n
	* to be discussed the Xtensa`s issue with reciprocal function,\n
	* i.e., BBE_RECIPN_2XCF32(0) = NAN which is not IEEE-754 compliant \n
	* BBE_RECIPN_2XCF32(0) = INFINITY according to IEEE-754
	*/
	for (iElem = 0UL; iElem < size; iElem++)
	{
		x = *pin;
		iszero  = (vboolN_2)(x == zeros);

		z = BBE_MOVN_2XCF32T(BBE_RECIPN_2XCF32(x), (xb_vecN_2xcf32)INFINITY_SP, BBE_NOTBN_2(iszero));
		*pout = z;

        pin++;
        pout++;
	}
}

void Rsdk_EF_exp_Vof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                           xb_vecN_2xf32 * pInput,
                                                  uint32_t size)
{
	xb_vecN_2xf32 * pin  = pInput;
	xb_vecN_2xf32 * pout = pOutput;
	
	const xb_vecN_2xf32 rec_ln2      = (xb_vecN_2xf32)(BBE_MOVF32_FROM32(0x3fb8aa3bL));	    // eq 1.0F / ln(2) <- 1.4426950F
	const xb_vecN_2xf32 a0           = (xb_vecN_2xf32)(BBE_MOVF32_FROM32(0x3fb504f4L));		// Taylor coefficient of y^0 <- 1.4142136F
	const xb_vecN_2xf32 a1           = (xb_vecN_2xf32)(BBE_MOVF32_FROM32(0x3f7af233L));		// Taylor coefficient of y^1 <- 9.8025814E-1F
	const xb_vecN_2xf32 a2           = (xb_vecN_2xf32)(BBE_MOVF32_FROM32(0x3eadf14cL));		// Taylor coefficient of y^2 <- 3.3973158E-1F
	const xb_vecN_2xf32 a3           = (xb_vecN_2xf32)(BBE_MOVF32_FROM32(0x3da0c1cfL));		// Taylor coefficient of y^3 <- 7.8494663E-2F
	const xb_vecN_2xf32 a4           = (xb_vecN_2xf32)(BBE_MOVF32_FROM32(0x3c5edb4cL));		// Taylor coefficient of y^4 <- 1.3602089E-2F
	const xb_vecN_2xf32 a5           = (xb_vecN_2xf32)(BBE_MOVF32_FROM32(0x3af727e9L));		// Taylor coefficient of y^5 <- 1.8856499E-3F
	const xb_vecN_2xf32 a6           = (xb_vecN_2xf32)(BBE_MOVF32_FROM32(0x39646baaL));		// Taylor coefficient of y^6 <- 2.1783882E-4F
	const xb_vecN_2xf32 a7           = (xb_vecN_2xf32)(BBE_MOVF32_FROM32(0x37b4f28fL));		// Taylor coefficient of y^7 <- 2.1570623E-5F
	const xb_vecN_2x32v and_coeff    = xb_int32v_rtor_xb_vecN_2x32v(0x007FFFFF);
	xb_vecN_2xf32 x;
	xb_vecN_2xf32 r;							// approximation to exponential
	xb_vecN_2xf32 floor_x;						// floor of x
	xb_vecN_2xf32 exponent;						// exponent of r
	xb_vecN_2x32v iexponent;					// integer exponent of r
	xb_vecN_2x32v *intPtr_r;				    // integer pointer to r
	vboolN_2 flags;								// predication flags
	uint32_t iElem;

	for (iElem = 0UL; iElem < size; iElem++)
	{
	// set x eq (x / ln(2)) and set x eq (fractional part of x - 0.5F) for Taylor approximation about x eq 0.5F
	x           = *pin;
	x          *= rec_ln2;
	floor_x     = BBE_FIFLOORN_2XF32(x);
	exponent    = floor_x + (xb_vecN_2xf32)127.0F;
	x          -= (floor_x + (xb_vecN_2xf32)0.5F);
	intPtr_r    = (xb_vecN_2x32v *)&r;

	// compute 2^x using Taylor approximation about x = 0.5F for range -0.5F < x < 0.5F
	r = a0 + (x * (a1 + (x * (a2 + (x * (a3 + (x * (a4 + (x * (a5 + (x * (a6 + (x * a7)))))))))))));

	// correct the case where the Taylor approximation results in r eq 2.0F for x eq 0x3EFFFFFF = 0.499999970198F
	flags       = (vboolN_2)( r >= (xb_vecN_2xf32)2.0F );
	BBE_ADDN_2XF32T(exponent, exponent, (xb_vecN_2xf32)1.0F, flags);
	r           = BBE_MOVN_2XF32T((xb_vecN_2xf32)1.0F, r, flags);

	// map exponents above 254 to INF (with exponent=255, mantissa=0)
	flags       = (vboolN_2)( exponent > (xb_vecN_2xf32)254.0F );
	exponent    = BBE_MOVN_2XF32T((xb_vecN_2xf32)255.0F, exponent, flags);
	r           = BBE_MOVN_2XF32T((xb_vecN_2xf32)0.0F, r, flags);

	// map 0.0F and de-normalised numbers to 0.0F (with exponent=0, mantissa=0)
	flags      = (vboolN_2)( exponent <= (xb_vecN_2xf32)0.0F );
	exponent   = BBE_MOVN_2XF32T((xb_vecN_2xf32)0.0F, exponent, flags);
	r          = BBE_MOVN_2XF32T((xb_vecN_2xf32)0.0F, r, flags);

	// add the new exponent to r
	*intPtr_r  = BBE_ANDN_2X32(*intPtr_r, and_coeff);
	iexponent  = BBE_TRUNCN_2XF32(exponent, 23L);
	*intPtr_r  = BBE_ORN_2X32(*intPtr_r, iexponent);
	*pout   = r;
	pin++;
	pout++;
	}
};

#ifdef __cplusplus
}
#endif

/*******************************************************************************
* EOF
******************************************************************************/

