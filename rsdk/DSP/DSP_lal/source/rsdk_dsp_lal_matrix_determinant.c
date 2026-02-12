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
* @file           rsdk_dsp_lal_matrix_determinant.c
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

void Rsdk_LA_detSq_Sof32p8Mif32p8(xb_vecN_2xf32 * pOutput,
                                  xb_vecN_2xf32 * pInput,
                                  xb_vecN_2xf32 * pBuffer1,
                                  xb_vecN_2xf32 * pBuffer2,
                                         uint32_t size)
{
  xb_vecN_2xf32 * pin    = pInput;
  xb_vecN_2xf32 * pout   = pOutput;
  xb_vecN_2xf32 * pbuff1 = pBuffer1;
  xb_vecN_2xf32 * pbuff2 = pBuffer2;
  uint32_t i, j;                         // loop counters
  uint32_t colj;                         // iteration number and column being reflected
  xb_vecN_2xf32 x0;                 // top element in the vector x being reflected
  // x is the on and below sub-diagonal vector = M[][colj] or R[][colj]
  xb_vecN_2xf32 modx;               // |x|
  xb_vecN_2xf32 modsqx;             // |x|^2
  xb_vecN_2xf32 modxsignx0;         // product of |x| and the sign of x0
  xb_vecN_2xf32 two_over_alphasq;   // 2 / alpha^2 eq 1 / {|x|.(|x| + |x0|)}
  xb_vecN_2xf32 alpha_w_dot_M;      // scalar product of alpha_w(pBuffer2[]) with row or column of input matrix
  xb_vecN_2xf32 ftmp;               // scratch
  vboolN_2 flags;                   // predicate flags

  // define matrix pointers for variable matrix dimensions passed at runtime
  // https://stackoverflow.com/questions/10164263/how-to-pass-two-dimensional-array-of-an-unknown-size-to-a-function
  xb_vecN_2xf32 (*pInMatrix)[size][size] = (xb_vecN_2xf32 (*)[size][size]) pin;
  xb_vecN_2xf32 (*pTriMatrix)[size][size] = (xb_vecN_2xf32 (*)[size][size]) pbuff1;

  /* QR decomposition of input matrix M */

  // For colj=0 over size iterations for columns 0 applying Householder transformations P
  // calculate |x|^2 over size iterations where x contains the size on and below-diagonal elements
  // in M[][0].
  modsqx = (xb_vecN_2xf32)0.0F;

  for (i = 0UL; i < size; i++)
  {
    modsqx += ((*pInMatrix)[i][0UL] * (*pInMatrix)[i][0UL]);
  } // end of loop i over size-0 elements in vector x

  // store the diagonal element x0 = x[0] = M[0][0] for convenience
  x0 = (*pInMatrix)[0UL][0UL];

  // modx=|x|
  modx = BBE_SQRTN_2XF32(modsqx);

  // modxsignx0 eq |x|*sgn(x[0])
  modxsignx0 = modx;
  flags = (vboolN_2)( x0 < (xb_vecN_2xf32)0.0F );
  BBE_NEGN_2XF32T(modxsignx0, modx, flags);

  // set on-diagonal upper element 0 of transformed vector R[0][0] eq -|x|.sgn(x[0])
  (*pTriMatrix)[0UL][0UL] = -modxsignx0;

  // set the first active element alpha_w[0]/pBuffer2[0] eq x[0] + |x|.sgn(x[0]).
  pbuff2[0UL] = x0 + modxsignx0;

  // set two_over_alphasq eq 2 / alpha^2 eq 1 / |x|.(|x| + |x0|)
  two_over_alphasq = BBE_RECIPN_2XF32(modsqx + (modx * BBE_ABSN_2XF32(x0)));
  flags = (vboolN_2)( (two_over_alphasq == (xb_vecN_2xf32)INFINITY_SP) | (two_over_alphasq != two_over_alphasq) );
  two_over_alphasq = BBE_MOVN_2XF32T((xb_vecN_2xf32)0.0F, two_over_alphasq, flags);   // true, false, flags

  // loop i for size-1 iterations setting the size-1 elements in alpha_w/pBuffer2 (1) to (size - 1) inclusive
  // and zeroing the size-1 below diagonal elements in vector x[] eq R[][0].
  for (i = 1UL; i < size; i++)
  {
    // set alpha_w[i] eq pBuffer2[i] eq x[i] = M[i][0]
    pbuff2[i] = (*pInMatrix)[i][0UL];

    // set x[i] = R[i][0] = 0.0F since the Householder reflection zeroes these elements
    (*pTriMatrix)[i][0UL] = (xb_vecN_2xf32)0.0F;
  } // end of loop i over elements of vector x

  // pre-multiply: M = P.M where P has active dimension (size).
  // only the lower right block of size (size) by (size-1) is changed.
  // loop j for (size-1) iterations on columns 1 to (size-1) inclusive.
  for (j = 1UL; j < size; j++)
  {
    // loop i for size iterations on rows 0 to size-1 inclusive computing the
    // scalar product of alpha_w^T with column j of M.
    // the minimum number of iterations is 1.
    alpha_w_dot_M = (xb_vecN_2xf32)0.0F;
    for (i = 0UL; i < size; i++)
    {
      alpha_w_dot_M += (pbuff2[i] * (*pInMatrix)[i][j]);
    }
    // set ftmp eq 2 / alpha^2 . pBuffer2^T.M[][j]
    ftmp = two_over_alphasq * alpha_w_dot_M;

    // loop i for size iterations on rows 0 to size-1 inclusive computing
    // R[i][j] eq M[i][j] - alpha_w[i] * (two_over_alphasq * alpha_w_dot_M).
    // the minimum number of iterations is (size-size+1)=1.
    for (i = 0UL; i < size; i++)
    {
      (*pTriMatrix)[i][j] = (*pInMatrix)[i][j] - (pbuff2[i] * ftmp);
    } // end of loop i over active rows
  } // end of loop j over active columns

  // loop colj over size iterations for the remained columns 1 to size-1 inclusive, applying Householder transformations P
  // where P has inactive identity matrix dimension colj by colj in upper left and active dimension
  // (size-colj) by (size-colj) defined by pBuffer2 in lower right.
  for (colj = 1UL; colj < size; colj++)
  {
    // calculate |x|^2 over size-colj iterations where x contains the size-colj on and below-diagonal elements
    // in R[][colj]. minimum iterations = 1 for last column colj = size - 1 if square matrix.
    modsqx = (xb_vecN_2xf32)0.0F;
    for (i = colj; i < size; i++)
    {
        modsqx += ((*pTriMatrix)[i][colj] * (*pTriMatrix)[i][colj]);
    } // end of loop i over size-colj elements in vector x

    // store the diagonal element x0 eq x[0] eq R[colj][colj] for convenience
    x0 = (*pTriMatrix)[colj][colj];

    // modx eq |x|
    modx = BBE_SQRTN_2XF32(modsqx);

    // modxsignx0 eq |x|*sgn(x[0])
    modxsignx0 = modx;
    flags = (vboolN_2)( x0 < (xb_vecN_2xf32)0.0F );
    BBE_NEGN_2XF32T(modxsignx0, modx, flags);

    // set on-diagonal upper element 0 of transformed vector R[colj][colj] eq -|x|.sgn(x[0])
    (*pTriMatrix)[colj][colj] = -modxsignx0;

    // the vector alpha_w[] defining P has full dimension size but active dimension (size-colj)
    // the upper colj elements elements alpha_w[0] to alpha_w[colj-1] are irrelevant.
    // set the first active element alpha_w[colj] eq pBuffer2[colj] eq x[0] + |x|.sgn(x[0]).
    pbuff2[colj] = x0 + modxsignx0;

    // set two_over_alphasq eq 2 / alpha^2 eq 1 / |x|.(|x| + |x0|)
    two_over_alphasq = BBE_RECIPN_2XF32(modsqx + (modx * BBE_ABSN_2XF32(x0)));
    flags = (vboolN_2)( (two_over_alphasq == (xb_vecN_2xf32)INFINITY_SP) | (two_over_alphasq != two_over_alphasq) );
    two_over_alphasq = BBE_MOVN_2XF32T((xb_vecN_2xf32)0.0F, two_over_alphasq, flags);   // true, false, flags

    // loop i for size-1-colj iterations setting the size-1-colj elements in alpha_w (colj + 1) to (size - 1) inclusive
    // and zeroing the size-1-colj below diagonal elements in vector x[] = R[][colj].
    // this loop has zero iterations for square matrices on last pass colj = size-1.
    for (i = colj + 1UL; i < size; i++)
    {
      // set alpha_w[i] eq pBuffer2[i] eq x[i] eq M[i][colj]
      pbuff2[i] = (*pTriMatrix)[i][colj];

      // set x[i] eq R[i][colj] eq 0.0F since the Householder reflection zeroes these elements
      (*pTriMatrix)[i][colj] = (xb_vecN_2xf32)0.0F;
    } // end of loop i over elements of vector x

    // pre-multiply: R = P.R where P has active dimension (size-colj) by (size-colj).
    // only the lower right block of size (size-colj) by (size-1-colj) is changed.
    // loop j for (size-1-colj) iterations on columns colj+1 to size-1 inclusive.
    // this loop has zero iterations on last pass when colj=size-1.
    for (j = colj + 1UL; j < size; j++)
    {
      // loop i for (size-colj) iterations on rows colj to size-1 inclusive computing the
      // scalar product of alpha_w(pBuffer2^T) with column j of M.
      // the minimum number of iterations is (size-size+1)=1.
      alpha_w_dot_M = (xb_vecN_2xf32)0.0F;
      for (i = colj; i < size; i++)
      {
        alpha_w_dot_M += (pbuff2[i] * (*pTriMatrix)[i][j]);
      }
      // set ftmp eq 2 / alpha^2 . pBuffer2^T.M[][j]
      ftmp = two_over_alphasq * alpha_w_dot_M;

      // loop i for (size-colj) iterations on rows colj to size-1 inclusive computing
      // R[i][j] eq R[i][j] - pBuffer2[i] * (two_over_alphasq * alpha_w_dot_M).
      // the minimum number of iterations is (size-size+1)=1.
      for (i = colj; i < size; i++)
      {
        (*pTriMatrix)[i][j] -= (pbuff2[i] * ftmp);
      } // end of loop i over active rows
    } // end of loop j over active columns
  } // end of loop colj defining column iterations for the Householder similarity transformations

  /* Compute the determinant of triangular matrix R returned in Buffer1 */
  ftmp = (*pTriMatrix)[0UL][0UL];
  for (i = 1UL; i < size; i++)
  {
    ftmp *= (*pTriMatrix)[i][i];
  }
  // sign correction
  if ((size & 1UL) != 0UL)
  {
    *pout = -ftmp;
  }
  else
  {
    *pout = ftmp;
  }
  return;
}

void Rsdk_LA_detSq_Sof32cp8Mif32cp8(xb_vecN_2xcf32 * pOutput,
                                    xb_vecN_2xcf32 * pInput,
                                    xb_vecN_2xcf32 * pBuffer1,
                                    xb_vecN_2xcf32 * pBuffer2,
                                            uint32_t size)
{
  xb_vecN_2xcf32 * pin    = pInput;
  xb_vecN_2xcf32 * pout   = pOutput;
  xb_vecN_2xcf32 * pbuff1 = pBuffer1;
  xb_vecN_2xcf32 * pbuff2 = pBuffer2;
  uint32_t colj;                           // iteration number and column being reflected
  uint32_t i, j;                           // loop counters
  xb_vecN_2xcf32 phasorx0;            // phasor of x0
  xb_vecN_2xf32 modsqx0;              // |x0|^2
  xb_vecN_2xf32 recipmodx0;           // 1/|x0|
  xb_vecN_2xcf32 modxphasorx0;        // product of |x| and the phasor of x0
  // x is the on and below sub-diagonal vector = M[][colj] or R[][colj]
  xb_vecN_2xcf32 alpha_w_dot_M;       // scalar product of alpha_w[] with row or column of M
  xb_vecN_2xcf32 complexone;          // 1+0i
  xb_vecN_2xf32 modx;                 // |x| where x is the on and below sub-diagonal vector
  xb_vecN_2xf32 modsqx;               // |x|^2 where x is the on and below sub-diagonal vector
  xb_vecN_2xf32 two_over_alphasq;     // 2 / alpha^2 eq 1 / {|x|.(|x| + |x0|)}
  xb_vecN_2xcf32 ftmp;                // scratch
  vboolN_2 flags;                     // predicate flags

  // define matrix pointers for variable matrix dimensions passed at runtime
  // https://stackoverflow.com/questions/10164263/how-to-pass-two-dimensional-array-of-an-unknown-size-to-a-function
  xb_vecN_2xcf32 (*pInMatrix)[size][size] = (xb_vecN_2xcf32 (*)[size][size]) pin;
  xb_vecN_2xcf32 (*pTriMatrix)[size][size] = (xb_vecN_2xcf32 (*)[size][size]) pbuff1;

  // set complexone eq 1+0i for convenience
  complexone = BBE_CMPLXN_2XF32((xb_vecN_2xf32)0.0F, (xb_vecN_2xf32)1.0F);

  /* QR decomposition of input matrix M */

  // calculate |x|^2 over size iterations where x contains the size on and below-diagonal elements
  // in M[][0]. minimum iterations = 1 for last column (size - 1) of square matrix.
  modsqx = (xb_vecN_2xf32)0.0F;
  for (i = 0UL; i < size; i++)
  {
    modsqx += BBE_MAGN_2XCF32((*pInMatrix)[i][0UL]);
  } // end of loop i over size elements in vector x

  // set modx eq |x|
  modx = BBE_SQRTN_2XF32(modsqx);

  // compute |x0|^2, |x0| and 1/|x0| where x0 eq M[0][0]
  modsqx0 = BBE_MAGN_2XCF32((*pInMatrix)[0UL][0UL]);
  recipmodx0 = BBE_RSQRTN_2XF32(modsqx0);

  // set two_over_alphasq eq 2 / alpha^2 eq 1 / |x|.(|x| + |x0|) noting that if |x|==0 then |x0|==0
  // if (modx not eq 0.0F) then two_over_alphasq eq 1.0F / (modx * (modx + modx0))
  // else two_over_alphasq eq 0.0F
  two_over_alphasq = BBE_RECIPN_2XF32(modsqx + (modx * BBE_SQRTN_2XF32(modsqx0)));
  flags = (vboolN_2)( (two_over_alphasq == (xb_vecN_2xf32)INFINITY_SP) | (two_over_alphasq != two_over_alphasq) );
  two_over_alphasq = BBE_MOVN_2XF32T((xb_vecN_2xf32)0.0F, two_over_alphasq, flags);   // true, false, flags

  // set phasorx0 eq |x| . (x[0] / |x[0]|) avoiding division by zero
  // note: phasorx0 eq (1.0F, 0.0F) if x[0]=(0.0F,0.0F) to match the real QR algorithm
  phasorx0 = BBE_CMPLXN_2XF32(recipmodx0 * BBE_CIMAGN_2XCF32((*pInMatrix)[0UL][0UL]),
                              recipmodx0 * BBE_CREALN_2XCF32((*pInMatrix)[0UL][0UL]));
  flags = (vboolN_2)( (recipmodx0 == (xb_vecN_2xf32)INFINITY_SP) | (recipmodx0 != recipmodx0) );
  phasorx0 = BBE_MOVN_2XCF32T(complexone, phasorx0, flags);   // true, false, flags

  // set modxphasorx0 eq modx * phasorx0
  modxphasorx0 = BBE_CMPLXN_2XF32(modx * BBE_CIMAGN_2XCF32(phasorx0), modx * BBE_CREALN_2XCF32(phasorx0));

  // the vector pBuffer2[] defining P has full dimension size by size but active dimension (size) by (size)
  // set the upper element pBuffer2[0] eq x[0] + |x|.phasor(x[0])
  // and set upper element 0 of transformed vector (P.x)[0] eq R[1][0] eq -|x|.phasor(x[0])
  pbuff2[0UL] = (*pInMatrix)[0UL][0UL] + modxphasorx0;
  (*pTriMatrix)[0UL][0UL] = -modxphasorx0;

  // loop i for size-1 iterations setting the size-1 elements in pBuffer2[i] to M[i][0]
  // and zeroing the size-1 below diagonal elements in vector x[i] eq R[i][0].
  // this loop has zero iterations for square matrices on last pass.
  for (i = 1UL; i < size; i++)
  {
    // set pBuffer2[i] eq x[i] eq M[i][0]
    pbuff2[i] = (*pInMatrix)[i][0UL];

    // set x[i] eq R[i][0] eq 0.0F since the Householder reflection zeroes these elements
    (*pTriMatrix)[i][0UL] = BBE_ZERON_2XCF32();
  } // end of loop i over elements of vector x

  // pre-multiply: R eq P.M where P[size] has active dimension (size).
  // only the lower right block of size (size) by (size-1) is changed.

  // loop j for (size-1) iterations on columns 1 to size-1 inclusive.
  // this loop has zero iterations on last pass.
  for (j = 1UL; j < size; j++)
  {
    // loop i for (size) iterations on rows 0 to size-1 inclusive computing the
    // scalar product of pBuffer2^H with column j of M.
    // the minimum number of iterations is 1.
    alpha_w_dot_M = BBE_ZERON_2XCF32();
    for (i = 0UL; i < size; i++)
    {
        alpha_w_dot_M += (BBE_CONJN_2XCF32(pbuff2[i]) * (*pInMatrix)[i][j]);
    } // end of inner pre-multiply loop i

    // set ftmp eq 2 / alpha^2 . pBuffer2^H.M[][j]
    ftmp = BBE_CMPLXN_2XF32(two_over_alphasq * BBE_CIMAGN_2XCF32(alpha_w_dot_M),
                            two_over_alphasq * BBE_CREALN_2XCF32(alpha_w_dot_M));

    // loop i over (size) rows in column j M[i=0:size-1][j=1:size-1] inclusive computing
    // R[i][j] eq M[i][j] - pBuffer2[i] * (two_over_alphasq * alpha_w_dot_M).
    // the minimum number of iterations is 1.
    for (i = 0UL; i < size; i++)
    {
      (*pTriMatrix)[i][j] = (*pInMatrix)[i][j] - (pbuff2[i] * ftmp);
    } // end of inner pre-multiply loop i
  } // end of outer pre-multiply loop j over active columns

  // loop colj over size iterations for the remained columns 1 to size-1 inclusive applying Householder transformations P
  // where P has inactive identity matrix dimension colj by colj in upper left and active dimension
  // (size-colj) by (size-colj) defined by pBuffer2 in lower right.
  for (colj = 1UL; colj < size; colj++)
  {
    // calculate |x|^2 over size-colj iterations where x contains the size-colj on and below-diagonal elements
    // in M[][colj]. minimum iterations = 1 for last column colj = size - 1 of square matrix.
    modsqx = (xb_vecN_2xf32)0.0F;
    for (i = colj; i < size; i++)
    {
        modsqx += BBE_MAGN_2XCF32((*pTriMatrix)[i][colj]);
    } // end of loop i over size-colj elements in vector x

    // set modx eq |x|
    modx = BBE_SQRTN_2XF32(modsqx);

    // compute |x0|^2, |x0| and 1/|x0| where x0 eq M[colj][colj]
    modsqx0 = BBE_MAGN_2XCF32((*pTriMatrix)[colj][colj]);
    recipmodx0 = BBE_RSQRTN_2XF32(modsqx0);

    // set two_over_alphasq eq 2 / alpha^2 eq 1 / |x|.(|x| + |x0|) noting that if |x|==0 then |x0|==0
    // if (modx not eq 0) then two_over_alphasq eq 1 / (modx * (modx + modx0))
    // else two_over_alphasq eq 0.0F;
    two_over_alphasq = BBE_RECIPN_2XF32(modsqx + (modx * BBE_SQRTN_2XF32(modsqx0)));
    flags = (vboolN_2)( (two_over_alphasq == (xb_vecN_2xf32)INFINITY_SP) | (two_over_alphasq != two_over_alphasq) );
    two_over_alphasq = BBE_MOVN_2XF32T((xb_vecN_2xf32)0.0F, two_over_alphasq, flags);   // true, false, flags

    // set phasorx0 eq |x| . (x[0] / |x[0]|) avoiding division by zero
    // note: phasorx0 eq (1.0F, 0.0F) if x[0] eq (0.0F,0.0F) to match the real QR algorithm
    phasorx0 = BBE_CMPLXN_2XF32(recipmodx0 * BBE_CIMAGN_2XCF32((*pTriMatrix)[colj][colj]),
                                recipmodx0 * BBE_CREALN_2XCF32((*pTriMatrix)[colj][colj]));
    flags = (vboolN_2)( (recipmodx0 == (xb_vecN_2xf32)INFINITY_SP) | (recipmodx0 != recipmodx0) );
    phasorx0 = BBE_MOVN_2XCF32T(complexone, phasorx0, flags);   // true, false, flags

    // set modxphasorx0 eq modx * phasorx0
    modxphasorx0 = BBE_CMPLXN_2XF32(modx * BBE_CIMAGN_2XCF32(phasorx0), modx * BBE_CREALN_2XCF32(phasorx0));

    // the vector pBuffer2[] defining P has full dimension size by size but active dimension (size-colj) by (size-colj)
    // the upper colj elements pBuffer2[0] to pBuffer2[colj-1] are irrelevant
    // set the upper element pBuffer2[colj] eq x[0] + |x|.phasor(x[0])
    // and set upper element 0 of transformed vector (P.x)[0] eq M[colj + 1][colj] eq -|x|.phasor(x[0])
    pbuff2[colj] = (*pTriMatrix)[colj][colj] + modxphasorx0;
    (*pTriMatrix)[colj][colj] = -modxphasorx0;

    // loop i for size-1-colj iterations setting the size-1-colj elements in pBuffer2[i] to M[i][colj]
    // and zeroing the size-1-colj below diagonal elements in vector x[i] eq M[i][colj].
    // this loop has zero iterations for square matrices on last pass.
    for (i = colj + 1UL; i < size; i++)
    {
      // set pBuffer2[i] eq x[i] = R[i][colj]
      pbuff2[i] = (*pTriMatrix)[i][colj];

      // set x[i] eq R[i][colj] eq 0.0F since the Householder reflection zeroes these elements
      (*pTriMatrix)[i][colj] = BBE_ZERON_2XCF32();
    } // end of loop i over elements of vector x

    // pre-multiply: R = P.R where P[size][size] has active dimension (size-colj) by (size-colj).
    // only the lower right block of size (size-colj) by (size-1-colj) is changed.
    // loop j for (size-1-colj) iterations on columns colj+1 to size-1 inclusive.
    // this loop has zero iterations on last pass when colj=size-1.
    for (j = colj + 1UL; j < size; j++)
    {
      // loop i for (size-colj) iterations on rows colj to size-1 inclusive computing the
      // scalar product of pBuffer2^H with column j of M.
      // the minimum number of iterations is (size-size+1)=1.
      alpha_w_dot_M = BBE_ZERON_2XCF32();
      for (i = colj; i < size; i++)
      {
          alpha_w_dot_M += (BBE_CONJN_2XCF32(pbuff2[i]) * (*pTriMatrix)[i][j]);
      } // end of inner pre-multiply loop i

      // set ftmp eq 2 / alpha^2 . pBuffer2^H.M[][j]
      ftmp = BBE_CMPLXN_2XF32(two_over_alphasq * BBE_CIMAGN_2XCF32(alpha_w_dot_M),
                              two_over_alphasq * BBE_CREALN_2XCF32(alpha_w_dot_M));

      // loop i over (size-colj) rows in column j M[i=colj:size-1][j=colj + 1:size-1] inclusive computing
      // R[i][j] eq R[i][j] - pBuffer2[i] * (two_over_alphasq * alpha_w_dot_M).
      // the minimum number of iterations is (size-size+1)=1.
      for (i = colj; i < size; i++)
      {
        (*pTriMatrix)[i][j] -= (pbuff2[i] * ftmp);
      } // end of inner pre-multiply loop i
    } // end of outer pre-multiply loop j over active columns
  } // end of loop colj defining iterations and columns for the Householder similarity transformations

  /* Compute the determinant of triangular matrix returned in Buffer1 */
  ftmp = (*pTriMatrix)[0UL][0UL];
  for (i = 1UL; i < size; i++)
  {
    ftmp *= (*pTriMatrix)[i][i];
  }
  // sign correction
  if ((size & 1UL) != 0UL)
  {
    *pout = -ftmp;
  }
  else
  {
    *pout = ftmp;
  }
  return;
}

#ifdef __cplusplus
}
#endif

/*******************************************************************************
* EOF
******************************************************************************/