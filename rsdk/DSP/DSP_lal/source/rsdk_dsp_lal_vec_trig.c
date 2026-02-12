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


/**
* @file          rsdk_dsp_lal_vec_trig.c
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

void Rsdk_LA_rad2deg_Vof32p8Vif32p8(xb_vecN_2xf32 * pOutput,
                                    xb_vecN_2xf32 * pInput,
									       uint32_t size)
{
	xb_vecN_2xf32 * pin  = pInput;
	xb_vecN_2xf32 * pout = pOutput;
    const xb_vecN_2xf32 div_180_pi = (xb_vecN_2xf32)(180.F/(float32_t)SP_pi);
	uint32_t i;
	
	for (i = 0; i < size; i++)
    {
        pout[i] = pin[i] * div_180_pi;
    }
}

void Rsdk_LA_deg2rad_Vof32p8Vif32p8(xb_vecN_2xf32 * pOutput,
                                    xb_vecN_2xf32 * pInput,
                                           uint32_t size)
{
	xb_vecN_2xf32 * pin  = pInput;
	xb_vecN_2xf32 * pout = pOutput;
    const xb_vecN_2xf32 div_pi_180 = (xb_vecN_2xf32)((float32_t)SP_pi/180.F);
    uint32_t i;

    for (i = 0; i < size; i++)
    {
        pout[i] = pin[i] * div_pi_180;
    }
}

void Rsdk_EF_asin_Vof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                            xb_vecN_2xf32 * pInput,
                                                   uint32_t size)
{
	xb_vecN_2xf32 * pin  = pInput;
	xb_vecN_2xf32 * pout = pOutput;
    xb_vecN_2xf32 r, x;
    const xb_vecN_2xf32 piover2 = 1.5707963F;
    const xb_vecN_2xf32 a0 = 1.5707963050F;
    const xb_vecN_2xf32 a1 = -0.2145988016F;
    const xb_vecN_2xf32 a2 = 0.0889789874F;
    const xb_vecN_2xf32 a3 = -0.0501743046F;
    const xb_vecN_2xf32 a4 = 0.0308918810F;
    const xb_vecN_2xf32 a5 = -0.0170881256F;
    const xb_vecN_2xf32 a6 = 0.0066700901F;
    const xb_vecN_2xf32 a7 = -0.0012624911F;
    vboolN_2 flags;
    uint32_t iElem;

    for (iElem = 0UL; iElem < size; iElem++)
    {
        x = *pin;
        flags = (vboolN_2)(x < (xb_vecN_2xf32)0.0F);
        x = BBE_ABSN_2XF32(x);
        r = a0 + (x * (a1 + (x * (a2 + (x * (a3 + (x * (a4 + (x * (a5 + (x * (a6 + (x * a7)))))))))))));
        r = (xb_vecN_2xf32)piover2 - (BBE_SQRTN_2XF32((xb_vecN_2xf32)1.0F - x) * r);
        BBE_NEGN_2XF32T(r, r, flags);

        // return NAN for invalid argument
        flags = (vboolN_2)(x > (xb_vecN_2xf32)1.0F) | (x < (xb_vecN_2xf32)-1.0F);
        BBE_ABSN_2XF32T(r, (xb_vecN_2xf32)NAN_SP, flags);

        *pout = r;

        pin++;
        pout++;
    }
}

void Rsdk_EF_acos_Vof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                            xb_vecN_2xf32 * pInput,
                                                   uint32_t size)
{
	xb_vecN_2xf32 * pin  = pInput;
	xb_vecN_2xf32 * pout = pOutput;
    const xb_vecN_2xf32 piover2 = 1.5707963F;
    xb_vecN_2xf32 r, x;
    uint32_t iElem;

    for (iElem = 0UL; iElem < size; iElem++)
    {
        x = *pin;
        Rsdk_EF_asin_Vof32p8Vif32p8(&r, &x, 1UL);
        r = piover2 - r;
        *pout = r;

        pin++;
        pout++;
    }
}

void Rsdk_EF_sin_Vof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                           xb_vecN_2xf32 * pInput,
                                                  uint32_t size)
{
	xb_vecN_2xf32 * pin  = pInput;
	xb_vecN_2xf32 * pout = pOutput;
    xb_vecN_2xf32 r, x;
    xb_vecN_2xf32 x2;
    vboolN_2 xltmpiover2;
    vboolN_2 xgtpiover2;
    const xb_vecN_2xf32 pi = 3.1415927F;
    const xb_vecN_2xf32 piover2 = 1.5707963F;
    const xb_vecN_2xf32 a1 = 9.999999947E-01F;
    const xb_vecN_2xf32 a3 = -1.666665670E-01F;
    const xb_vecN_2xf32 a5 = 8.333025174E-03F;
    const xb_vecN_2xf32 a7 = -1.980741431E-04F;
    const xb_vecN_2xf32 a9 = 2.601886907E-06F;
    uint32_t iElem;

    for (iElem = 0UL; iElem < size; iElem++)
    {
        x = *pin;
        // set flags
        xltmpiover2 = (vboolN_2)(x < -piover2);
        xgtpiover2 = (vboolN_2)(x > piover2);

        // map x to range -pi/2 <= x <= pi/2
        BBE_ADDN_2XF32T(x, x, (xb_vecN_2xf32)pi, xltmpiover2);
        BBE_SUBN_2XF32T(x, x, (xb_vecN_2xf32)pi, xgtpiover2);

        // compute sin(x) for x in range -pi/2 <= x <= pi/2
        x2 = x * x;
        r = x * (a1 + (x2 * (a3 + (x2 * (a5 + (x2 * (a7 + (x2 * a9))))))));

        // correct result for x < -pi/2 and x > pi/2
        BBE_NEGN_2XF32T(r, r, xltmpiover2);
        BBE_NEGN_2XF32T(r, r, xgtpiover2);

        *pout = r;

        pin++;
        pout++;
    }
}


void Rsdk_EF_cos_Vof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                           xb_vecN_2xf32 * pInput,
                                                  uint32_t size)
{
	xb_vecN_2xf32 * pin  = pInput;
	xb_vecN_2xf32 * pout = pOutput;
    xb_vecN_2xf32 r, x;
    xb_vecN_2xf32 x2;
    vboolN_2 xltmpiover2;
    vboolN_2 xgtpiover2;
    const xb_vecN_2xf32 pi = 3.1415927F;
    const xb_vecN_2xf32 piover2 = 1.5707963F;
    const xb_vecN_2xf32 a1 = 9.999999947E-01F;
    const xb_vecN_2xf32 a3 = -1.666665670E-01F;
    const xb_vecN_2xf32 a5 = 8.333025174E-03F;
    const xb_vecN_2xf32 a7 = -1.980741431E-04F;
    const xb_vecN_2xf32 a9 = 2.601886907E-06F;
    uint32_t iElem;

    for (iElem = 0UL; iElem < size; iElem++)
    {
        x = (*pin)  + piover2;
        // set flags
        xltmpiover2 = (vboolN_2)(x < -piover2);
        xgtpiover2 = (vboolN_2)(x > piover2);

        // map x to range -pi/2 <= x <= pi/2
        BBE_ADDN_2XF32T(x, x, (xb_vecN_2xf32)pi, xltmpiover2);
        BBE_SUBN_2XF32T(x, x, (xb_vecN_2xf32)pi, xgtpiover2);

        // compute sin(x) for x in range -pi/2 <= x <= pi/2
        x2 = x * x;
        r = x * (a1 + (x2 * (a3 + (x2 * (a5 + (x2 * (a7 + (x2 * a9))))))));

        // correct result for x < -pi/2 and x > pi/2
        BBE_NEGN_2XF32T(r, r, xltmpiover2);
        BBE_NEGN_2XF32T(r, r, xgtpiover2);

        *pout = r;

        pin++;
        pout++;
    }
}


void Rsdk_EF_atan_Vof32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                            xb_vecN_2xf32 * pInput,
                                                   uint32_t size)
{
	xb_vecN_2xf32 * pin  = pInput;
	xb_vecN_2xf32 * pout = pOutput;
    xb_vecN_2xf32 r, x;                             // computed r
    xb_vecN_2xf32 x2;                               // x*x
    vboolN_2 isnegative;                            // x is negative
    vboolN_2 exceeds1;                              // x is greater than 1.0
    vboolN_2 mapped;                                // x in range tan(15 deg) to tan(45 deg)=1.0
    vboolN_2 pminfinity;                            // x=INFINITY or -INFINITY
    const xb_vecN_2xf32 tan15deg = 0.26794919F;     // tan(15 deg) = 2 - sqrt(3)
    const xb_vecN_2xf32 tan30deg = 0.57735027F;     // tan(30 deg) = 1/sqrt(3)
    const xb_vecN_2xf32 a3 = -0.33333333F;          // Maclaurin coefficient of x^3 = -1/3
    const xb_vecN_2xf32 a5 = 0.2F;                  // Maclaurin coefficient of x^5 = 1/5
    const xb_vecN_2xf32 a7 = -0.14285714F;          // Maclaurin coefficient of x^7 = -1/7
    const xb_vecN_2xf32 piover6 = 0.52359878F;      // pi/6
    const xb_vecN_2xf32 piover2 = 1.5707963F;       // pi/2
    uint32_t iElem;

    for (iElem = 0UL; iElem < size; iElem++)
    {
        x = *pin;
        // set flags for negative argument to allow use of tan(-x)=-tan(x) and for x infinite
        isnegative = (vboolN_2)( x < (xb_vecN_2xf32)0.0F );
        x = BBE_ABSN_2XF32(x);
        pminfinity = (vboolN_2)( x == (xb_vecN_2xf32)INFINITY_SP );

        // test for argument above 1 to allow use of atan(x)=pi/2-atan(1/x)
        exceeds1 = (vboolN_2)( x > (xb_vecN_2xf32)1.0F );
        BBE_RECIPN_2XF32T(x, x, exceeds1);

        // at this point, 0<=x<=1 with 0<=angle<=45 deg
        // map case of tan(15 deg)<=x<=1 onto range -tan(15 deg) to tan(15 deg)
        // using tan(angle-30deg) = (tan(angle)-tan(30deg)) / (1 + tan(angle)tan(30deg))
        // x eq tan(15 deg) maps to tan(-15 deg) = -tan(15 deg)
        // x eq 1.0F maps to (sqrt(3) - 1) / (sqrt(3) + 1) = 2 - sqrt(3) = tan(15 deg)
        mapped = (vboolN_2)( x > (xb_vecN_2xf32)tan15deg);
        BBE_DIVN_2XF32T(x, x -(xb_vecN_2xf32)tan30deg, (xb_vecN_2xf32)1.0F + (tan30deg * x), mapped);

        // Maclaurin approximation to inverse tan function for x in range -tan(15 deg) to tan(15 deg) = 0.268
        x2 = x * x;
        //r eq x * ((xb_vecN_2xf32)1.0F + x2 * (a3 + x2 * (a5 + x2 * (a7 + x2 * (a9 + x2 * (a11 + x2 * a13))))));
        //r eq x * ((xb_vecN_2xf32)1.0F + x2 * (a3 + x2 * (a5 + x2 * (a7 + x2 * (a9 + x2 * a11)))));
        //r eq x * ((xb_vecN_2xf32)1.0F + x2 * (a3 + x2 * (a5 + x2 * (a7 + x2 * a9))));
        r = x * ((xb_vecN_2xf32)1.0F + (x2 * (a3 + (x2 * (a5 + (x2 * a7))))));

        // undo the distortions applied earlier to obtain -pi/2 <= r <= pi/2
        // and check for |x|=INFINITY giving erroneous NAN needing correction to -pi/2 and pi/2
        BBE_ADDN_2XF32T(r, r, (xb_vecN_2xf32)piover6, mapped);
        BBE_SUBN_2XF32T(r, (xb_vecN_2xf32)piover2, r, exceeds1);
        BBE_ABSN_2XF32T(r, (xb_vecN_2xf32)piover2, pminfinity);
        BBE_NEGN_2XF32T(r, r, isnegative);

        *pout = r;

        pin++;
        pout++;
    }
}


void Rsdk_EF_atan2_Vof32p8Vif32p8Vif32p8(xb_vecN_2xf32 * __restrict pOutput,
                                                    xb_vecN_2xf32 * pInputY,
                                                    xb_vecN_2xf32 * pInputX,
                                                           uint32_t size)
{
	xb_vecN_2xf32 * pinX = pInputX;
	xb_vecN_2xf32 * pinY = pInputY;
	xb_vecN_2xf32 * pout = pOutput;
    xb_vecN_2xf32 r, x, y, z;
    vboolN_2 xeqzero;                       // x=0.0F flags
    vboolN_2 yeqzero;                       // y=0.0F flags
    vboolN_2 xltzero;                       // x<0.0F flags
    vboolN_2 yltzero;                       // y<0.0F flags
    vboolN_2 ygezero;                       // y>0.0F flags
    const xb_vecN_2xf32 pi = 3.1415927F;    // pi
    uint32_t iElem;

    for (iElem = 0UL; iElem < size; iElem++)
    {
        y = *pinY;
        x = *pinX;
        // set flags for special cases
        xeqzero = (vboolN_2)( x == (xb_vecN_2xf32)0.0F );
        yeqzero = (vboolN_2)( y == (xb_vecN_2xf32)0.0F );
        xltzero = (vboolN_2)( x < (xb_vecN_2xf32)0.0F );
        yltzero = (vboolN_2)( y < (xb_vecN_2xf32)0.0F );
        ygezero = (vboolN_2)( y >= (xb_vecN_2xf32)0.0F );

        // call the atan approximation
        z = BBE_DIVN_2XF32(y, x);
        Rsdk_EF_atan_Vof32p8Vif32p8(&r, &z, 1UL);

        // if (x eq 0.0F) && (y eq 0.0F) return 0.0F
        BBE_ABSN_2XF32T(r, (xb_vecN_2xf32)0.0F, BBE_ANDBN_2(xeqzero, yeqzero));

        // quadrant 2 correction (90 deg to 180 deg)
        // if ((x less than 0.0F) && (y greater than or equal to 0.0F)) return pi + atan_deg(y / x);
        BBE_ADDN_2XF32T(r, r, (xb_vecN_2xf32)pi, BBE_ANDBN_2(xltzero, ygezero));

        // quadrant 3 correction (-180 deg to -90 deg)
        // if ((x less than 0.0F) && (y less than 0.0F)) return atan_deg(y / x) - pi;
        BBE_SUBN_2XF32T(r, r, (xb_vecN_2xf32)pi, BBE_ANDBN_2(xltzero, yltzero));

        *pout = r;

        pinX++;
        pinY++;
        pout++;
    }
}

#ifdef __cplusplus
}
#endif

/*******************************************************************************
* EOF
******************************************************************************/


