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
* @file           rsdk_dsp_lal_matrix_qr.c
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

void Rsdk_LA_decQRHous_Mof32p8Mof32p8Mif32p8(xb_vecN_2xf32 * pOutputR,
		                                     xb_vecN_2xf32 * pOutputQ,
		                                     xb_vecN_2xf32 * pBuffer,
                                             xb_vecN_2xf32 * pInput,
                                                    uint32_t rows,
                                                    uint32_t cols)
{
  xb_vecN_2xf32 * pin    = pInput;
  xb_vecN_2xf32 * pbuff  = pBuffer;
  xb_vecN_2xf32 * poutR  = pOutputR;
  xb_vecN_2xf32 * poutQ  = pOutputQ;
  uint32_t i, j;                         // loop counters
  uint32_t colj;                         // iteration number and column being reflected
  xb_vecN_2xf32 x0;                 // top element in the vector x being reflected
  // x is the on and below sub-diagonal vector eq M[][colj]/R[][colj]
  xb_vecN_2xf32 modx;               // eq |x|
  xb_vecN_2xf32 modsqx;             // eq |x|^2
  xb_vecN_2xf32 modxsignx0;         // product of |x| and the sign of x0
  xb_vecN_2xf32 two_over_alphasq;   // 2 / alpha^2 eq 1 / {|x|.(|x| + |x0|)}
  xb_vecN_2xf32 alpha_w_dot_M;      // scalar product of alpha_w(pBuffer2[]) with row or column of M/R matrix
  xb_vecN_2xf32 alpha_w_dot_P;      // scalar product of alpha_w[] with column of P
  xb_vecN_2xf32 ftmp;               // scratch
  vboolN_2 flags;                   // predicate flags

  // define matrix pointers for variable matrix dimensions passed at runtime
  // https://stackoverflow.com/questions/10164263/how-to-pass-two-dimensional-array-of-an-unknown-size-to-a-function
  xb_vecN_2xf32 (*pInMatrix)[rows][cols] = (xb_vecN_2xf32 (*)[rows][cols]) pin;
  xb_vecN_2xf32 (*pRMatrix)[rows][cols]  = (xb_vecN_2xf32 (*)[rows][rows]) poutR;
  xb_vecN_2xf32 (*pQMatrix)[rows][rows]  = (xb_vecN_2xf32 (*)[rows][rows]) poutQ;

  // Initializing Q[rows][rows] to the identity matrix
  for (i = 0UL; i < rows; i++)
  {
    for (j = 0UL; j < rows; j++)
    {
      (*pQMatrix)[i][j] = (xb_vecN_2xf32)0.0F;
    }
    (*pQMatrix)[i][i] = (xb_vecN_2xf32)1.0F;
  }

  // Iterations for columns 0 applying Householder transformations P
  // calculate |x|^2 over rows iterations where x contains the (rows) on and below-diagonal
  // elements in M[][0].
  modsqx = (xb_vecN_2xf32)0.0F;
  for (i = 0UL; i < rows; i++)
  {
    modsqx += (*pInMatrix)[i][0UL] * (*pInMatrix)[i][0UL];
  } // end of loop i over rows elements in vector x

  // store the diagonal element x0 eq x[0] eq M[0][0] for convenience
  x0 = (*pInMatrix)[0UL][0UL];

  // set modx eq |x|
  modx = BBE_SQRTN_2XF32(modsqx);

  // set modxsignx0 eq |x|.sgn(x[0])
  // modxsignx0 eq modx * ((x0 >= 0.0F) ? 1.0F : -1.0F);
  modxsignx0 = modx;
  flags = (vboolN_2)( x0 < (xb_vecN_2xf32)0.0F );
  BBE_NEGN_2XF32T(modxsignx0, modx, flags);

  // set on-diagonal upper element 0 of transformed vector (P.x)[0] eq M[0][0] eq -|x|.sgn(x[0])
  (*pRMatrix)[0UL][0UL] = -modxsignx0;

  // set the first active element alpha_w[0] eq pBuffer[0] eq x[0] + |x|.sgn(x[0]).
  pbuff[0UL] = x0 + modxsignx0;

  // set two_over_alphasq eq 2 / alpha^2 eq 1 / |x|.(|x| + |x0|)
  two_over_alphasq = BBE_RECIPN_2XF32(modsqx + (modx * BBE_ABSN_2XF32(x0)));
  flags = (vboolN_2)( (two_over_alphasq == (xb_vecN_2xf32)INFINITY_SP) | (two_over_alphasq != two_over_alphasq) );
  two_over_alphasq = BBE_MOVN_2XF32T((xb_vecN_2xf32)0.0F, two_over_alphasq, flags);   // true, false, flags

  // loop i for rows-1 iterations setting the rows-1 elements in alpha_w (1) to (rows - 1) inclusive
  // and zeroing the rows-1 below diagonal elements in vector x[] eq M[][0].
  // this loop has zero iterations for square matrices rows=cols on last pass cols-1=rows-1.
  for (i = 1UL; i < rows; i++)
  {
    // set alpha_w[i] eq pBuffer[i] eq x[i] eq M[i][0]
    pbuff[i] = (*pInMatrix)[i][0UL];

    // set x[i] eq R[i][0] eq 0.0F since the Householder reflection zeroes these elements
    (*pRMatrix)[i][0UL] = (xb_vecN_2xf32)0.0F;
  } // end of loop i over elements of vector x

  // pre-multiply: M = P.M where P has active dimension (rows) by (rows).
  // only the lower right block of size (rows) by (cols-1) is changed.
  // loop j for (cols-1) iterations on columns 1 to cols-1 inclusive.
  for (j = 1UL; j < cols; j++)
  {
    // loop i for (rows) iterations on rows 0 to rows-1 inclusive computing the
    // scalar product of alpha_w^T with column j of M.
    alpha_w_dot_M = (xb_vecN_2xf32)0.0F;
    for (i = 0UL; i < rows; i++)
    {
      alpha_w_dot_M += (pbuff[i] * (*pInMatrix)[i][j]);
    }
    // set ftmp eq 2 / alpha^2 . alpha_w^T.M[][j]
    ftmp = two_over_alphasq * alpha_w_dot_M;

    // loop i for (rows) iterations on rows 0 to rows-1 inclusive computing
    // R[i][j] eq M[i][j] - pBuffer[i] * (two_over_alphasq * alpha_w_dot_M).
    // the minimum number of iterations is (rows-cols+1)=1.
    for (i = 0UL; i < rows; i++)
    {
      (*pRMatrix)[i][j] = (*pInMatrix)[i][j] - (pbuff[i] * ftmp);
    } // end of loop i over active rows
  } // end of loop j over active columns

  // Update the Q matrix
  // post-multiply: P'[0] eq P'[-1].P[0]
  // only columns j indexed from colj to rows-1 inclusive are changed.
  // loop i over all rows in P' indexed from 0 to rows-1 inclusive
  for (i = 0UL; i < rows; i++)
  {
    // loop j over (rows) iterations on columns colj to rows-1 inclusive computing the
    // scalar product of row i of P with alpha_w.
    // the minimum number of iterations is (rows-cols+1)=1.
    alpha_w_dot_P = (xb_vecN_2xf32)0.0F;
    for (j = 0UL; j < rows; j++)
    {
      alpha_w_dot_P += ((*pQMatrix)[i][j] * pbuff[j]);
    }
    // set ftmp eq two_over_alphasq * P[i][].alpha_w
    ftmp = alpha_w_dot_P * two_over_alphasq;

    // loop j over (rows) columns indexed from 0 to rows-1 inclusive
    // Q[i][j] eq Q[i][j] - alpha_w[i] * (two_over_alphasq * alpha_w_dot_P)
    for (j = 0UL; j < rows; j++)
    {
      (*pQMatrix)[i][j] -= (pbuff[j] * ftmp);
    }
  } // end of loop i over over all rows

  // Loop colj over size iterations for the remained columns 1 to size-1 inclusive, applying Householder transformations P
  // where P has inactive identity matrix dimension colj by colj in upper left and active dimension
  // (size-colj) by (size-colj) defined by alpha_w(scratch) in lower right.
  for (colj = 1UL; colj < cols; colj++)
  {
    // calculate |x|^2 over rows-colj iterations where x contains the rows-colj on and below-diagonal elements
    // in R[][colj]. minimum iterations = 1 for last column colj = cols - 1 of square matrix rows = cols.
    modsqx = (xb_vecN_2xf32)0.0F;
    for (i = colj; i < rows; i++)
    {
      modsqx += ((*pRMatrix)[i][colj] * (*pRMatrix)[i][colj]);
    } // end of loop i over rows-colj elements in vector x

    // store the diagonal element x0 eq x[0] eq R[colj][colj] for convenience
    x0 = (*pRMatrix)[colj][colj];

    // set modx=|x|
    modx = BBE_SQRTN_2XF32(modsqx);

    // set modxsignx0 eq |x|.sgn(x[0])
    // modxsignx0 eq modx * ((x0 >= 0.0F) ? 1.0F : -1.0F);
    modxsignx0 = modx;
    flags = (vboolN_2)( x0 < (xb_vecN_2xf32)0.0F );
    BBE_NEGN_2XF32T(modxsignx0, modx, flags);

    // set on-diagonal upper element 0 of transformed vector (P.x)[0] eq R[colj][colj] eq -|x|.sgn(x[0])
    (*pRMatrix)[colj][colj] = -modxsignx0;

    // the vector alpha_w[] defining P has full dimension rows by rows but active dimension (rows-colj) by (rows-colj)
    // the upper colj elements elements alpha_w[0] to alpha_w[colj-1] are irrelevant.
    // set the first active element alpha_w[colj] eq pBuffer[colj] eq x[0] + |x|.sgn(x[0]).
    pbuff[colj] = x0 + modxsignx0;

    // set two_over_alphasq eq 2 / alpha^2 eq 1 / |x|.(|x| + |x0|)
    two_over_alphasq = BBE_RECIPN_2XF32(modsqx + (modx * BBE_ABSN_2XF32(x0)));
    flags = (vboolN_2)( (two_over_alphasq == (xb_vecN_2xf32)INFINITY_SP) | (two_over_alphasq != two_over_alphasq) );
    two_over_alphasq = BBE_MOVN_2XF32T((xb_vecN_2xf32)0.0F, two_over_alphasq, flags);   // true, false, flags

    // loop i for rows-1-colj iterations setting the rows-1-colj elements in alpha_w (colj + 1) to (rows - 1) inclusive
    // and zeroing the rows-1-colj below diagonal elements in vector x[] eq R[][colj].
    // this loop has zero iterations for square matrices rows=cols on last pass colj=cols-1=rows-1.
    for (i = colj + 1UL; i < rows; i++)
    {
      // set alpha_w[i] eq pBuffer[i] eq x[i] eq M[i][colj]
      pbuff[i] = (*pRMatrix)[i][colj];

      // set x[i] eq R[i][colj] eq 0.0F since the Householder reflection zeroes these elements
      (*pRMatrix)[i][colj] = (xb_vecN_2xf32)0.0F;
    } // end of loop i over elements of vector x

    // pre-multiply: R eq P.R where P has active dimension (rows-colj) by (rows-colj).
    // only the lower right block of size (rows-colj) by (cols-1-colj) is changed.
    // loop j for (cols-1-colj) iterations on columns colj+1 to cols-1 inclusive.
    // this loop has zero iterations on last pass when colj=cols-1.
    for (j = colj + 1UL; j < cols; j++)
    {
      // loop i for (rows-colj) iterations on rows colj to rows-1 inclusive computing the
      // scalar product of alpha_w^T with column j of R.
      // the minimum number of iterations is (rows-cols+1)=1.
      alpha_w_dot_M = (xb_vecN_2xf32)0.0F;
      for (i = colj; i < rows; i++)
      {
        alpha_w_dot_M += (pbuff[i] * (*pRMatrix)[i][j]);
      }
      // set ftmp eq 2 / alpha^2 . alpha_w^T.R[][j]
      ftmp = two_over_alphasq * alpha_w_dot_M;

      // loop i for (rows-colj) iterations on rows colj to rows-1 inclusive computing
      // R[i][j] eq R[i][j] - pBuffer[i] * (two_over_alphasq * alpha_w_dot_M).
      // the minimum number of iterations is (rows-cols+1)=1.
      for (i = colj; i < rows; i++)
      {
        (*pRMatrix)[i][j] -= (pbuff[i] * ftmp);
      } // end of loop i over active rows
    } // end of loop j over active columns

    // Update the Q matrix
    // post-multiply: P'[colj] eq P'[colj-1].P[colj]
    // only columns j indexed from colj to rows-1 inclusive are changed.
    // loop i over all rows in P' indexed from 0 to rows-1 inclusive
    for (i = 0UL; i < rows; i++)
    {
      // loop j over (rows-colj) iterations on columns colj to rows-1 inclusive computing the
      // scalar product of row i of P with alpha_w.
      // the minimum number of iterations is (rows-cols+1)=1.
      alpha_w_dot_P = (xb_vecN_2xf32)0.0F;
      for (j = colj; j < rows; j++)
      {
        alpha_w_dot_P += ((*pQMatrix)[i][j] * pbuff[j]);
      }
      // set ftmp eq two_over_alphasq * P[i][].alpha_w
      ftmp = alpha_w_dot_P * two_over_alphasq;

      // loop j over (rows-colj) columns indexed from colj to rows-1 inclusive
      // Q[i][j] eq Q[i][j] - alpha_w[i] * (two_over_alphasq * alpha_w_dot_P)
      // the minimum number of iterations occurs when colj=cols-1 giving (rows-cols+1)=1.
      for (j = colj; j < rows; j++)
      {
        (*pQMatrix)[i][j] -= (pbuff[j] * ftmp);
      }
    } // end of loop i over over all rows
  } // end of loop colj defining column iterations for the Householder similarity transformations

  return;
}


void Rsdk_LA_decQRHous_Mof32cp8Mof32cp8Mif32cp8(xb_vecN_2xcf32 * pOutputR,
		                                        xb_vecN_2xcf32 * pOutputQ,
		                                        xb_vecN_2xcf32 * pBuffer,
                                                xb_vecN_2xcf32 * pInput,
                                                        uint32_t rows,
                                                        uint32_t cols)
{
  xb_vecN_2xcf32 * pin    = pInput;
  xb_vecN_2xcf32 * pbuff  = pBuffer;
  xb_vecN_2xcf32 * poutR  = pOutputR;
  xb_vecN_2xcf32 * poutQ  = pOutputQ;
  uint32_t i, j;                           // loop counters
  uint32_t colj;                           // iteration number and column being reflected
  xb_vecN_2xcf32 phasorx0;            // phasor of x0
  xb_vecN_2xf32 modsqx0;              // eq |x0|^2
  xb_vecN_2xf32 recipmodx0;           // eq 1/|x0|
  // x is the on and below sub-diagonal vector = M[][colj]/R[][colj]
  xb_vecN_2xf32 modx;                 // |x| where x is the on and below sub-diagonal vector
  xb_vecN_2xf32 modsqx;               // |x|^2 where x is the on and below sub-diagonal vector
  xb_vecN_2xf32 two_over_alphasq;     // 2 / alpha^2 eq 1 / {|x|.(|x| + |x0|)}
  xb_vecN_2xcf32 modxphasorx0;        // product of |x| and the phasor of x0
  xb_vecN_2xcf32 alpha_w_dot_M;       // scalar product of alpha_w[] with row or column of M/R
  xb_vecN_2xcf32 alpha_w_dot_P;       // scalar product of alpha_w[] with column of P
  xb_vecN_2xcf32 complexone;          // eq 1+0i
  xb_vecN_2xcf32 ftmp;                // scratch
  vboolN_2 flags;                     // predicate flags

  // define matrix pointers for variable matrix dimensions passed at runtime
  // https://stackoverflow.com/questions/10164263/how-to-pass-two-dimensional-array-of-an-unknown-size-to-a-function
  xb_vecN_2xcf32 (*pInMatrix)[rows][cols] = (xb_vecN_2xcf32 (*)[rows][cols]) pin;
  xb_vecN_2xcf32 (*pRMatrix)[rows][cols]  = (xb_vecN_2xcf32 (*)[rows][rows]) poutR;
  xb_vecN_2xcf32 (*pQMatrix)[rows][rows]  = (xb_vecN_2xcf32 (*)[rows][rows]) poutQ;

  // set complexone eq 1+0i for convenience
  complexone = BBE_CMPLXN_2XF32((xb_vecN_2xf32)0.0F, (xb_vecN_2xf32)1.0F);

  // Initialise unitary matrix Q[rows][rows] to the identity matrix
  for (i = 0UL; i < rows; i++)
  {
    for (j = 0UL; j < rows; j++)
    {
      (*pQMatrix)[i][j] = BBE_ZERON_2XCF32();
    }
    (*pQMatrix)[i][i] = BBE_CMPLXN_2XF32((xb_vecN_2xf32)0.0F, (xb_vecN_2xf32)1.0F);
  }

  // For columns 0 applying Householder transformations P
  // calculate |x|^2 over (rows) iterations where x contains the rows on and below-diagonal
  // elements in M[][0].
  modsqx = (xb_vecN_2xf32)0.0F;
  for (i = 0UL; i < rows; i++)
  {
    modsqx += BBE_MAGN_2XCF32((*pInMatrix)[i][0UL]);
  } // end of loop i over rows elements in vector x

  // set modx eq |x|
  modx = BBE_SQRTN_2XF32(modsqx);

  // compute |x0|^2, |x0| and 1/|x0| where x0 eq M[0][0]
  modsqx0 = BBE_MAGN_2XCF32((*pInMatrix)[0UL][0UL]);
  recipmodx0 = BBE_RSQRTN_2XF32(modsqx0);

  // set two_over_alphasq eq 2 / alpha^2 eq 1 / |x|.(|x| + |x0|) noting that if |x|==0 then |x0|==0
  // if (modx not eq 0.0F) two_over_alphasq eq 1.0F / (modx * (modx + modx0));
  // else two_over_alphasq eq 0.0F;
  two_over_alphasq = BBE_RECIPN_2XF32(modsqx + (modx * BBE_SQRTN_2XF32(modsqx0)));
  flags = (vboolN_2)( (two_over_alphasq == (xb_vecN_2xf32)INFINITY_SP) | (two_over_alphasq != two_over_alphasq) );
  two_over_alphasq = BBE_MOVN_2XF32T((xb_vecN_2xf32)0.0F, two_over_alphasq, flags);   // true, false, flags

  // set phasorx0 eq |x| . (x[0] / |x[0]|) avoiding division by zero
  // note: phasorx0 eq (1.0F, 0.0F) if x[0] eq (0.0F,0.0F) to match the real QR algorithm
  phasorx0 = BBE_CMPLXN_2XF32(recipmodx0 * BBE_CIMAGN_2XCF32((*pInMatrix)[0][0]),
                              recipmodx0 * BBE_CREALN_2XCF32((*pInMatrix)[0][0]));
  flags = (vboolN_2)( (recipmodx0 == (xb_vecN_2xf32)INFINITY_SP) | (recipmodx0 != recipmodx0) );
  phasorx0 = BBE_MOVN_2XCF32T(complexone, phasorx0, flags);   // true, false, flags

  // set modxphasorx0 eq modx * phasorx0
  modxphasorx0 = BBE_CMPLXN_2XF32(modx * BBE_CIMAGN_2XCF32(phasorx0), modx * BBE_CREALN_2XCF32(phasorx0));

  // the vector alpha_w[](pBuffer) defining P has full dimension (rows)
  // set the upper element alpha_w[0] eq x[0] + |x|.phasor(x[0])
  // and set upper element 0 of transformed vector (P.x)[0] eq M[1][0] = -|x|.phasor(x[0])
  pbuff[0UL] = (*pInMatrix)[0UL][0UL] + modxphasorx0;
  (*pRMatrix)[0UL][0UL] = -modxphasorx0;

  // loop i for rows-1 iterations setting the rows-1 elements in alpha_w[i] to R[i][0]
  // and zeroing the rows-1 below diagonal elements in vector x[i] eq R[i][0].
  for (i = 1UL; i < rows; i++)
  {
    // set alpha_w[i] eq x[i] eq M[i][colj]
    pbuff[i] = (*pInMatrix)[i][0UL];

    // set x[i] eq R[i][0] eq 0.0F since the Householder reflection zeroes these elements
    (*pRMatrix)[i][0UL] = BBE_ZERON_2XCF32();
  } // end of loop i over elements of vector x

  // pre-multiply: R eq P.M where P[rows][cols] has active dimension (rows) by (rows).
  // only the lower right block of size (rows) by (cols-1) is changed.
  // loop j for (cols-1) iterations on columns 1 to cols-1 inclusive.
  for (j = 1UL; j < cols; j++)
  {
    // loop i for (rows) iterations on rows 0 to rows-1 inclusive computing the
    // scalar product of alpha_w^H with column j of M.
    // the minimum number of iterations is (rows-cols+1)=1.
    alpha_w_dot_M = BBE_ZERON_2XCF32();
    for (i = 0UL; i < rows; i++)
    {
      alpha_w_dot_M += (BBE_CONJN_2XCF32(pbuff[i]) * (*pInMatrix)[i][j]);
    } // end of inner pre-multiply loop i

    // set ftmp eq 2 / alpha^2 . alpha_w^H.M[][j]
    ftmp = BBE_CMPLXN_2XF32(two_over_alphasq * BBE_CIMAGN_2XCF32(alpha_w_dot_M),
                            two_over_alphasq * BBE_CREALN_2XCF32(alpha_w_dot_M));

    // loop i over (rows) rows in column j M[i=0:rows-1][j=1:cols-1] inclusive computing
    // R[i][j] eq M[i][j] - pBuffer[i] * (two_over_alphasq * alpha_w_dot_M).
    // the minimum number of iterations is (rows-cols+1)=1.
    for (i = 0UL; i < rows; i++)
    {
      (*pRMatrix)[i][j] = (*pInMatrix)[i][j] - (pbuff[i] * ftmp);
    } // end of inner pre-multiply loop i
  } // end of outer pre-multiply loop j over active columns

  // post-multiply on Q[rows][rows]
  // only columns j indexed from 0 to rows-1 inclusive are changed.
  // loop i over all rows in P' indexed from 0 to rows-1 inclusive
  for (i = 0UL; i < rows; i++)
  {
    // loop j over (rows) iterations on columns 0 to rows-1 inclusive
    // computing the scalar product of row i of P with alpha_w(pBuffer).
    alpha_w_dot_P = BBE_ZERON_2XCF32();
    for (j = 0UL; j < rows; j++)
    {
      alpha_w_dot_P += ((*pQMatrix)[i][j] * pbuff[j]);
    } // end of inner post-multiply loop j

    // set ftmp eq two_over_alphasq * Q[i][].alpha_w
    ftmp = BBE_CMPLXN_2XF32(two_over_alphasq * BBE_CIMAGN_2XCF32(alpha_w_dot_P),
                            two_over_alphasq * BBE_CREALN_2XCF32(alpha_w_dot_P));

    // loop j over (rows) columns indexed from 0 to rows-1 inclusive
    // Q[i][j] eq Q[i][j] - (two_over_alphasq * alpha_w_dot_P).alpha_w[i]^H
    for (j = 0UL; j < rows; j++)
    {
        (*pQMatrix)[i][j] -= (ftmp * BBE_CONJN_2XCF32(pbuff[j]));
    } // end of inner-post multiply loop j
  } // end of post-multiply outer loop i over all rows

  // Loop colj over cols iterations for columns 1 to cols-1 inclusive applying Householder transformations P
  // where P has inactive identity matrix dimension colj by colj in upper left and active dimension
  // (rows-colj) by (rows-colj) defined by alpha_w in lower right.
  for (colj = 1UL; colj < cols; colj++)
  {
    // calculate |x|^2 over rows-colj iterations where x contains the rows-colj on and below-diagonal elements
    // in R[][colj]. minimum iterations = 1 for last column colj = cols - 1 of square matrix rows = cols.
    modsqx = (xb_vecN_2xf32)0.0F;
    for (i = colj; i < rows; i++)
    {
      modsqx += BBE_MAGN_2XCF32((*pRMatrix)[i][colj]);
    } // end of loop i over rows-colj elements in vector x

    // set modx eq |x|
    modx = BBE_SQRTN_2XF32(modsqx);

    // compute |x0|^2, |x0| and 1/|x0| where x0 eq R[colj][colj]
    modsqx0 = BBE_MAGN_2XCF32((*pRMatrix)[colj][colj]);
    recipmodx0 = BBE_RSQRTN_2XF32(modsqx0);

    // set two_over_alphasq eq 2 / alpha^2 eq 1 / |x|.(|x| + |x0|) noting that if |x|==0 then |x0|==0
    // if (modx not eq 0.0F) then two_over_alphasq eq 1.0F / (modx * (modx + modx0));
    // else two_over_alphasq eq 0.0F;
    two_over_alphasq = BBE_RECIPN_2XF32(modsqx + (modx * BBE_SQRTN_2XF32(modsqx0)));
    flags = (vboolN_2)( (two_over_alphasq == (xb_vecN_2xf32)INFINITY_SP) | (two_over_alphasq != two_over_alphasq) );
    two_over_alphasq = BBE_MOVN_2XF32T((xb_vecN_2xf32)0.0F, two_over_alphasq, flags);   // true, false, flags

    // set phasorx0 eq |x| . (x[0] / |x[0]|) avoiding division by zero
    // note: phasorx0 eq (1.0F, 0.0F) if x[0] eq (0.0F,0.0F) to match the real QR algorithm
    phasorx0 = BBE_CMPLXN_2XF32(recipmodx0 * BBE_CIMAGN_2XCF32((*pRMatrix)[colj][colj]),
                                recipmodx0 * BBE_CREALN_2XCF32((*pRMatrix)[colj][colj]));
    flags = (vboolN_2)( (recipmodx0 == (xb_vecN_2xf32)INFINITY_SP) | (recipmodx0 != recipmodx0) );
    phasorx0 = BBE_MOVN_2XCF32T(complexone, phasorx0, flags);   // true, false, flags

    // set modxphasorx0 eq modx * phasorx0
    modxphasorx0 = BBE_CMPLXN_2XF32(modx * BBE_CIMAGN_2XCF32(phasorx0), modx * BBE_CREALN_2XCF32(phasorx0));

    // the vector alpha_w[] defining P has full dimension rows but active dimension (rows-colj)
    // the upper colj elements alpha_w[0] to alpha_w[colj-1] are irrelevant
    // set the upper element alpha_w[colj] eq x[0] + |x|.phasor(x[0])
    // and set upper element 0 of transformed vector (P.x)[0] eq R[colj + 1][colj] = -|x|.phasor(x[0])
    pbuff[colj] = (*pRMatrix)[colj][colj] + modxphasorx0;
    (*pRMatrix)[colj][colj] = -modxphasorx0;

    // loop i for rows-1-colj iterations setting the rows-1-colj elements in alpha_w[i] to R[i][colj]
    // and zeroing the rows-1-colj below diagonal elements in vector x[i] = R[i][colj].
    // this loop has zero iterations for square matrices rows=cols on last pass colj=cols-1=rows-1.
    for (i = colj + 1UL; i < rows; i++)
    {
      // set alpha_w[i] eq x[i] eq R[i][colj]
      pbuff[i] = (*pRMatrix)[i][colj];

      // set x[i] eq R[i][colj] eq 0.0F since the Householder reflection zeroes these elements
      (*pRMatrix)[i][colj] = BBE_ZERON_2XCF32();
    } // end of loop i over elements of vector x

    // pre-multiply: R eq P.R where P[rows][cols] has active dimension (rows-colj) by (rows-colj).
    // only the lower right block of size (rows-colj) by (cols-1-colj) is changed.
    // loop j for (cols-1-colj) iterations on columns colj+1 to cols-1 inclusive.
    // this loop has zero iterations on last pass when colj=cols-1.
    for (j = colj + 1UL; j < cols; j++)
    {
      // loop i for (rows-colj) iterations on rows colj to rows-1 inclusive computing the
      // scalar product of alpha_w^H with column j of R.
      // the minimum number of iterations is (rows-cols+1)=1.
      alpha_w_dot_M = BBE_ZERON_2XCF32();
      for (i = colj; i < rows; i++)
      {
        alpha_w_dot_M += (BBE_CONJN_2XCF32(pbuff[i]) * (*pRMatrix)[i][j]);
      } // end of inner pre-multiply loop i

      // set ftmp eq 2 / alpha^2 . alpha_w^H.R[][j]
      ftmp = BBE_CMPLXN_2XF32(two_over_alphasq * BBE_CIMAGN_2XCF32(alpha_w_dot_M),
                              two_over_alphasq * BBE_CREALN_2XCF32(alpha_w_dot_M));

      // loop i over (rows-colj) rows in column j R[i=colj:rows-1][j=colj + 1:cols-1] inclusive computing
      // R[i][j] eq R[i][j] - pBuffer[i] * (two_over_alphasq * alpha_w_dot_M).
      // the minimum number of iterations is (rows-cols+1)=1.
      for (i = colj; i < rows; i++)
      {
        (*pRMatrix)[i][j] -= (pbuff[i] * ftmp);
      } // end of inner pre-multiply loop i
    } // end of outer pre-multiply loop j over active columns

    // post-multiply on Q[rows][rows]: Q'[colj] = Q'[colj-1].Q[colj]
    // only columns j indexed from colj to rows-1 inclusive are changed.
    // loop i over all rows in P' indexed from 0 to rows-1 inclusive
    for (i = 0UL; i < rows; i++)
    {
      // loop j over (rows-colj) iterations on columns colj to rows-1 inclusive
      // computing the scalar product of row i of P with pBuffer.
      // the minimum number of iterations is (rows-cols+1)=1.
      alpha_w_dot_P = BBE_ZERON_2XCF32();
      for (j = colj; j < rows; j++)
      {
        alpha_w_dot_P += ((*pQMatrix)[i][j] * pbuff[j]);
      } // end of inner post-multiply loop j

      // set ftmp eq two_over_alphasq * Q[i][].alpha_w
      ftmp = BBE_CMPLXN_2XF32(two_over_alphasq * BBE_CIMAGN_2XCF32(alpha_w_dot_P),
                              two_over_alphasq * BBE_CREALN_2XCF32(alpha_w_dot_P));

      // loop j over (rows-colj) columns indexed from colj to rows-1 inclusive
      // Q[i][j] eq Q[i][j] - (two_over_alphasq * alpha_w_dot_P).alpha_w[i]^H
      // the minimum number of iterations occurs when colj=cols-1 giving (rows-cols+1)=1.
      for (j = colj; j < rows; j++)
      {
          (*pQMatrix)[i][j] -= (ftmp * BBE_CONJN_2XCF32(pbuff[j]));
      } // end of inner-post multiply loop j
    } // end of post-multiply outer loop i over all rows
  } // end of loop colj defining iterations and columns for the Householder similarity transformations
  return;
}

#ifdef __cplusplus
}
#endif

/*******************************************************************************
* EOF
******************************************************************************/
