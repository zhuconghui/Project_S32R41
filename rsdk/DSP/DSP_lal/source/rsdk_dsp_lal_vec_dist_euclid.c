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
* @file           rsdk_dsp_lal_vec_dist_euclid.c
*/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "rsdk_dsp_lal.h"

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

/* Squared Normalized Euclidean distance 1:1  */
void Rsdk_LA_dist2MahalDg2_Sof32p8Vif32p8Vif32p8Vi2f32(xb_vecN_2xf32 * pOutput,
                                                 xb_vecN_2xf32 const * pInput1,
                                                 xb_vecN_2xf32 const * pInput2,
                                                     float32_t const * pInput3)
{
    xb_vecN_2xf32       * pout = (xb_vecN_2xf32 *)       pOutput;
    xb_vecN_2xf32 const * obs  = (xb_vecN_2xf32 const *) pInput1;
    xb_vecN_2xf32 const * ref  = (xb_vecN_2xf32 const *) pInput2;

    xb_vecN_2xf32 s00, s11;
    xb_vecN_2xf32 d_obs_ref_x, d_obs_ref_y, dist;

    xb_vecN_2xf32 ref_x = 0.0F;
	xb_vecN_2xf32 ref_y = 0.0F;
    xb_vecN_2xf32 obs_x = 0.0F;
    xb_vecN_2xf32 obs_y = 0.0F;

    // fill invers cov diag
    s00 = (xb_vecN_2xf32) ( pInput3[0] );
    s11 = (xb_vecN_2xf32) ( pInput3[1] );

    // load obs_x, obs_y with real vector
    BBE_LVN_2XF32_IP(obs_x, obs, 2*XCHAL_BBEN_SIMD_WIDTH);
    BBE_LVN_2XF32_IP(obs_y, obs, 2*XCHAL_BBEN_SIMD_WIDTH);

    // load ref_x, ref_y with real vector
    BBE_LVN_2XF32_IP(ref_x, ref, 2*XCHAL_BBEN_SIMD_WIDTH);
    BBE_LVN_2XF32_IP(ref_y, ref, 2*XCHAL_BBEN_SIMD_WIDTH);

    // compute obs - ref
    d_obs_ref_x = BBE_SUBN_2XF32(obs_x, ref_x);
    d_obs_ref_y = BBE_SUBN_2XF32(obs_y, ref_y);

    // compute Euclidean (obs - ref)^2
    d_obs_ref_x = BBE_MULN_2XF32(d_obs_ref_x, d_obs_ref_x);
    d_obs_ref_y = BBE_MULN_2XF32(d_obs_ref_y, d_obs_ref_y);

    // Normalized (obs - ref)^2 * sxx
    d_obs_ref_x = BBE_MULN_2XF32(d_obs_ref_x, s00);
    d_obs_ref_y = BBE_MULN_2XF32(d_obs_ref_y, s11);

    // compute Sum( (obs - ref)^2 * sxx )
    dist = BBE_ADDN_2XF32(d_obs_ref_x, d_obs_ref_y);

    // store squared distance
    BBE_SVN_2XF32_IP(dist, pout, 2*XCHAL_BBEN_SIMD_WIDTH);
}


/* Squared Normalized Euclidean distance 1 obs to each 8 ref */
void Rsdk_LA_dist2MahalDg2_Sof32p8Vi2f32Vif32p8Vi2f32(xb_vecN_2xf32 * pOutput,
                                                    float32_t const * pInput1,
                                                xb_vecN_2xf32 const * pInput2,
                                                    float32_t const * pInput3)
{
    xb_vecN_2xf32       * pout = (xb_vecN_2xf32 *)       pOutput;
    xb_vecN_2xf32 const * ref  = (xb_vecN_2xf32 const *) pInput2;

    xb_vecN_2xf32 s00, s11, obs_x, obs_y;
    xb_vecN_2xf32 d_obs_ref_x, d_obs_ref_y, dist;

	xb_vecN_2xf32 ref_x = 0.0F;
	xb_vecN_2xf32 ref_y = 0.0F;
	
    // fill invers cov diag
    s00 = (xb_vecN_2xf32) ( pInput3[0] );
    s11 = (xb_vecN_2xf32) ( pInput3[1] );

    // fill obs_x, obs_y with real scalar
    obs_x = (xb_vecN_2xf32) ( pInput1[0] );
    obs_y = (xb_vecN_2xf32) ( pInput1[1] );

    // load ref_x, ref_y with real vector
    BBE_LVN_2XF32_IP(ref_x, ref, 2*XCHAL_BBEN_SIMD_WIDTH);
    BBE_LVN_2XF32_IP(ref_y, ref, 2*XCHAL_BBEN_SIMD_WIDTH);

    // compute obs - ref
    d_obs_ref_x = BBE_SUBN_2XF32(obs_x, ref_x);
    d_obs_ref_y = BBE_SUBN_2XF32(obs_y, ref_y);

    // compute Euclidean (obs - ref)^2
    d_obs_ref_x = BBE_MULN_2XF32(d_obs_ref_x, d_obs_ref_x);
    d_obs_ref_y = BBE_MULN_2XF32(d_obs_ref_y, d_obs_ref_y);

    // compute Normalized (obs - ref)^2 * sxx
    d_obs_ref_x = BBE_MULN_2XF32(d_obs_ref_x, s00);
    d_obs_ref_y = BBE_MULN_2XF32(d_obs_ref_y, s11);

    // compute Sum( (obs - ref)^2 * sxx )
    dist = BBE_ADDN_2XF32(d_obs_ref_x, d_obs_ref_y);

    // store squared distance
    BBE_SVN_2XF32_IP(dist, pout, 2*XCHAL_BBEN_SIMD_WIDTH);
}

#ifdef __cplusplus
}
#endif

/*******************************************************************************
* EOF
******************************************************************************/
