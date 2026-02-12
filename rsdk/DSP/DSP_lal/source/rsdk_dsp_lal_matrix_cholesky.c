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
* @file           rsdk_dsp_lal_matrix_cholesky.c
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

void Rsdk_LA_decLLCholPd_Mof32p8Mif32p8(xb_vecN_2xf32 * pOutput,
		                                xb_vecN_2xf32 * pInput,
		                                       uint32_t size)
{
  uint32_t i, j, k;                // loop counters
  xb_vecN_2xf32 sum;               // scratch sum
  xb_vecN_2xf32 inv_xii;           // 1.0F / L[i][i]

  // Define matrix pointers for variable matrix dimensions passed at runtime
  xb_vecN_2xf32 (*pA)[size][size] = (xb_vecN_2xf32 (*)[size][size]) pInput;
  xb_vecN_2xf32 (*pL)[size][size] = (xb_vecN_2xf32 (*)[size][size]) pOutput;

  // Loop i for size iterations over all rows
  for (i = 0UL; i < size; i++)
  {
    // Loop j for size-i iterations over on and above diagonal elements so j >= i
    // minimum number of iterations is 1 when i=size-1
    for (j = i; j < size; j++)
    {
      // Accumulate sum = A[i][j] - Sigma(k=0 to i-1) {L[i][k] * L[j][k]}
      // = A[i][j] - Sigma(k=0 to i-1) {L[i][k] * L[j][k]} since j >= i > k
      // and L[i][k] and L[j][k] are therefore strictly below diagonal elements
      // i iterations with minimum number of iterations 0 when i=0.
      sum = (*pA)[i][j];
      for (k = 0UL; k < i; k++)
      {
        sum -= (*pL)[i][k] * (*pL)[j][k];
      }

      // Store on and below-diagonal element L[j][i] (since j >= i)
      if (i == j)
      {
        // set L[i][i] = sqrt(A[i][i] - Sigma(k=0 to i-1) L[i][k]^2) = sqrt(sum)
        (*pL)[i][i] = BBE_SQRTN_2XF32(BBE_ABSN_2XF32(sum));
        inv_xii = BBE_RSQRTN_2XF32(BBE_ABSN_2XF32(sum));
      }
      else
      {
        // Set L[j][i] = (A[i][j] - Sigma(k=0 to i-1) L[i][k].L[j][k]) / L[i][i] = sum / L[i][i]
        // and zero the above diagonal element L[i][j].
        // Note that 1.0F/L[i][i] has been computed and stored in inv_xii on first j iteration where j=i
        (*pL)[j][i] = sum * inv_xii;
        (*pL)[i][j] = (xb_vecN_2xf32)0.0F;
      }
    } // end of loop j over on and above diagonal elements
  } // end of loop i over rows
  return;
}


void Rsdk_LA_decLLCholPd_Mof32cp8Mif32cp8(xb_vecN_2xcf32 * pOutput,
		                                  xb_vecN_2xcf32 * pInput,
		                                          uint32_t size)
{
  uint32_t i, j, k;           // loop counters
  xb_vecN_2xcf32 sum;         // complex sum
  xb_vecN_2xf32 inv_xii;      // 1.0F / H[i][i]
  xb_vecN_2xf32 sumRe;        // real sum

  // Define matrix pointers for variable matrix dimensions passed at runtime
  xb_vecN_2xcf32 (*pH)[size][size] = (xb_vecN_2xcf32 (*)[size][size]) pInput;
  xb_vecN_2xcf32 (*pL)[size][size] = (xb_vecN_2xcf32 (*)[size][size]) pOutput;

  // Loop i for size iterations over all rows
  for (i = 0UL; i < size; i++)
  {
    // Loop j for size-i iterations over on and above diagonal elements so j >= i
    // minimum number of iterations is 1 when i=size-1
    for (j = i; j < size; j++)
    {
      // Accumulate sum = H[i][j] - Sigma(k=0 to i-1) {L[i][k] * conjg(L[j][k])}
      // since j >= i > k so L[i][k] and L[j][k] are strictly below diagonal elements
      // minimum number of iterations in k loop is 0 when i=0.
      // handle diagonal and off-diagonal cases separately
      if (i == j)
      {
        sumRe = BBE_CREALN_2XCF32((*pH)[i][i]);
        for (k = 0UL; k < i; k++)
        {
          sumRe -= BBE_MAGN_2XCF32((*pL)[i][k]);
        } // end of k loop

        // Set L[i][i] = sqrt(H[i][i] - Sigma(k=0 to i-1) {L[i][k] * conjg(L[j][k])} = sqrt(sum.Re)
        (*pL)[i][i] = BBE_CMPLXN_2XF32((xb_vecN_2xf32)0.0F, BBE_SQRTN_2XF32(BBE_ABSN_2XF32(sumRe)));
        inv_xii = BBE_RSQRTN_2XF32(BBE_ABSN_2XF32(sumRe));
      } // end of on-diagonal case i==j
      else
      {
        sum = (*pH)[i][j];
        for (k = 0UL; k < i; k++)
        {
          sum -= ((*pL)[i][k] * BBE_CONJN_2XCF32((*pL)[j][k]));
        }

        // Set L[j][i] = (H[i][j] - Sigma(k=0 to i-1) L[i][k].L[j][k]) / L[i][i] = sum / L[i][i]
        // note that 1.0F/L[i][i] has been computed and stored in inv_xii on first j iteration (j=i)
        (*pL)[j][i] = BBE_CMPLXN_2XF32(-BBE_CIMAGN_2XCF32(sum) * inv_xii, BBE_CREALN_2XCF32(sum) * inv_xii);

        // zero the above diagonal element L[i][j]
        (*pL)[i][j] = BBE_ZERON_2XCF32();
      } // end of off diagonal case i!=j
    } // end of loop j over on and above diagonal elements
  } // end of loop i over rows

    return;
}

#ifdef __cplusplus
}
#endif

/*******************************************************************************
* EOF
******************************************************************************/
