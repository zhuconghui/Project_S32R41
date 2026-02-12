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
* @file           rsdk_dsp_lal_matrix_uphess.c
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

void Rsdk_LA_decQUpHessQHousSq_Mof32p8Mof32p8Mif32p8(xb_vecN_2xf32 * pOutputP,
                                                     xb_vecN_2xf32 * pOutputH,
                                                     xb_vecN_2xf32 * pInput,
                                                     xb_vecN_2xf32 * pBuffer,
                                                            uint32_t size)
{
	xb_vecN_2xf32 * poutP = pOutputP;
	xb_vecN_2xf32 * poutH = pOutputH;
	xb_vecN_2xf32 * pin   = pInput;
	xb_vecN_2xf32 * pbuff = pBuffer;
	
	uint32_t      colj;                        // iteration number and column being reflected
	uint32_t      i, j;                        // loop counters
	xb_vecN_2xf32 x0;                     // top element in the vector x being reflected
	xb_vecN_2xf32 modsqx;                 // |x|^2 where x is the on and below sub-diagonal vector
	xb_vecN_2xf32 modx;                   // |x| where x is the on and below sub-diagonal vector
	xb_vecN_2xf32 modxsignx0;             // product of |x| and the sign of x0
	xb_vecN_2xf32 two_over_alphasq;       // 2 / alpha^2 <- 1 / {|x|.(|x| + |x0|)}
	xb_vecN_2xf32 ftmp;                   // scratch
	xb_vecN_2xf32 alpha_w_dot_M;          // scalar product of alpha_w[] with row or column of M
	xb_vecN_2xf32 alpha_w_dot_P;          // scalar product of alpha_w[] with column of P
	xb_vecN_2xf32 zeros = BBE_ZERON_2XF32();
	xb_vecN_2xf32 ones  = (xb_vecN_2xf32)1UL;
	xb_vecN_2xf32 *alpha_w;               // pointer to pBuffer
	vboolN_2      detect_flags;

	// initialise overall orthogonal matrix P[n][n] to the identity matrix
	Rsdk_EF_identity_Mof32p8(poutP, size);
	if (poutH != pin)
	{
		Rsdk_DT_copy_Mof32p8Mif32p8(poutH, pin, size, size);
	}
	alpha_w = pbuff;
	/* loop colj over n-2 iterations for columns 0 to n-3 inclusive applying Householder transformations P[n][n]
	 * where P has inactive identity matrix dimension size (colj+1) by (colj+1) in upper left and
	 * active dimension size (n-1-colj) by (n-1-colj) defined by alpha_w in lower right.
	 * */
	for (colj = 0UL; colj <= (size - 3UL); colj++)
	{
		// calculate |x|^2 where x contains the n-1-colj sub-diagonal and below sub-diagonal elements in H[][colj]
	    modsqx = zeros;
	    for (i = colj + 1UL; i < size; i++)
	    {
	    	modsqx                   += poutH[(i * size) + colj] * poutH[(i * size) + colj];
	    }
	    // store the sub-diagonal element x0 <- x[0] eq H[colj + 1][colj] for convenience
	    x0                            = poutH[((colj + 1UL) * size) + colj];
	    // set modxsignx0 <- |x|.sgn(x[0])
	    modx                          = BBE_SQRTN_2XF32(modsqx);
	    detect_flags                  = (vboolN_2)( x0 >= zeros );
	    modxsignx0                    = modx * BBE_MOVN_2XF32T(ones, -ones, detect_flags);
	    // set two_over_alphasq <- 2 / alpha^2 eq 1 / |x|.(|x| + |x0|) eq |x| / |x|^2.(|x| + |x0|).
	    detect_flags                  = (vboolN_2)( modsqx != zeros );
	    two_over_alphasq              = BBE_MOVN_2XF32T(BBE_DIVN_2XF32(modx, modsqx * (modx + BBE_ABSN_2XF32(x0))), zeros, detect_flags);
	    // set upper element 0 of transformed vector (P.x)[0] <- H[colj + 1][colj] eq -|x|.sgn(x[0])
	    poutH[((colj + 1UL) * size) + colj] = -modxsignx0;
	    /* the vector alpha_w[] defining P has full dimension n by n but active dimension (n-1-colj) by (n-1-colj)
	     * the elements alpha_w[0] to alpha_w[colj] implicitly equaL 0 but are never used.
	     * set the first active element alpha_w[colj + 1] <- x[0] + |x|.sgn(x[0]).
	     * */
	    alpha_w[colj + 1UL]           = x0 + modxsignx0;
	    /* loop i setting the remaining n - colj - 2 elements in alpha_w indexed [colj + 2] to [n - 1] and
	     * zeroing the n-colj-2 below sub-diagonal elements in vector x[] <- H[][colj]
	     * */
	    for (i = colj + 2UL; i < size; i++)
	    {
	    	// set alpha_w[i] <- x[i] eq H[i][colj]
	    	alpha_w[i]                = poutH[(i * size) + colj];
	    	// set x[i] <- H[i][colj] eq 0.0F since the Householder reflection zeroes these elements
	    	poutH[(i * size) + colj] = zeros;
	    }
	    /* pre-multiply: M <- P.M where P[n][n] has active dimension (n-1-colj) by (n-1-colj).
	     * only the lower right block of size (n-1-colj) by (n-1-colj) is changed.
	     * loop j over (n-1-colj) columns indexed from colj+1 to n-1 inclusive
	     * */
	    for (j = colj + 1UL; j < size; j++)
	    {
	    	/* loop i over (n-1-colj) rows indexed from colj+1 to n-1 inclusive computing the
	    	 * scalar product of alpha_w^T with column j of M
	    	 * */
	    	alpha_w_dot_M             = zeros;
	    	for (i = colj + 1UL; i < size; i++)
	    	{
	    		alpha_w_dot_M        += alpha_w[i] * poutH[(i * size) + j];
	    	}
	    	// set ftmp <- 2 / alpha^2 . alpha_w^T.H[][j]
	    	ftmp                      = two_over_alphasq * alpha_w_dot_M;
	    	/* loop i over (n-1-colj) rows indexed from colj+1 to n-1 inclusive
	    	 * H[i][j] <- H[i][j] - alpha_w[i] * (two_over_alphasq * alpha_w_dot_M)
	       * */
	      for (i = colj + 1UL; i < size; i++)
	      {
	    	  poutH[(i * size) + j] -= alpha_w[i] * ftmp;
	      }
	    }
	    /* post-multiply: M <- (P.M).P where P[n][n] has active dimension (n-1-colj) by (n-1-colj).
	     * only columns indexed from colj+1 to n-1 inclusive are changed.
	     * loop i over all rows indexed from 0 to n-1 inclusive
	     * */
	    for (i = 0UL; i < size; i++)
	    {
	      /* loop j over (n-1-colj) columns indexed from colj+1 to n-1 inclusive computing the
	       * scalar product of row i of M with alpha_w.
	       * */
	    	alpha_w_dot_M             = zeros;
	    	for (j = colj + 1UL; j < size; j++)
	    	{
	    		alpha_w_dot_M        += poutH[(i * size) + j] * alpha_w[j];
	    	}
	    	// set ftmp <- 2 / alpha^2 . H[i][].alpha_w
	    	ftmp                      = alpha_w_dot_M * two_over_alphasq;
	    	/* loop j over (n-1-colj) columns indexed from colj+1 to n-1 inclusive
	    	 * H[i][j] <- H[i][j] - alpha_w[i] * (two_over_alphasq * alpha_w_dot_M)
	    	 * */
	    	for (j = colj + 1UL; j < size; j++)
	    	{
	    		poutH[(i * size) + j] -= alpha_w[j] * ftmp;
	    	}
	    }
	    /* post-multiply: accumulate P'[colj] <- P'[colj-1] . P[colj].
	     * only columns indexed from colj+1 to n-1 inclusive are changed.
	     * loop i over all rows in P' indexed from 0 to n-1 inclusive
	     * */
	    for (i = 0UL; i < size; i++)
	    {
	    	/* loop j over (n-1-colj) columns indexed from colj+1 to n-1 inclusive computing the
	    	 * scalar product of row i of P with alpha_w.
	    	 * */
	    	alpha_w_dot_P             = zeros;
	    	for (j = colj + 1UL; j < size; j++)
	    	{
	    		alpha_w_dot_P        += poutP[(i * size) + j] * alpha_w[j];
	    	}
	    	// set ftmp = two_over_alphasq * P[i][].alpha_w
	    	ftmp                      = alpha_w_dot_P * two_over_alphasq;
	    	/* loop j over (n-1-colj) columns indexed from colj+1 to n-1 inclusive
	    	 * P[i][j] <- P[i][j] - alpha_w[i] * (two_over_alphasq * alpha_w_dot_P)
	    	 * */
	    	for (j = colj + 1UL; j < size; j++)
	    	{
	    		poutP[(i * size) + j] -= (alpha_w[j] * ftmp);
	    	}
	    }
	}
}

void Rsdk_LA_decQUpHessQHousSq_Mof32cp8Mof32cp8Mif32cp8(xb_vecN_2xcf32 * pOutputP,
                                                        xb_vecN_2xcf32 * pOutputH,
                                                        xb_vecN_2xcf32 * pInput,
                                                        xb_vecN_2xcf32 * pBuffer,
                                                                uint32_t size)
{
	xb_vecN_2xcf32 * poutP = pOutputP;
	xb_vecN_2xcf32 * poutH = pOutputH;
	xb_vecN_2xcf32 * pin   = pInput;
	xb_vecN_2xcf32 * pbuff = pBuffer;
	
	uint32_t       colj;                      // iteration number and column being reflected
	uint32_t       i, j;                      // loop counters
	xb_vecN_2xcf32 phasorx0;                  // phasor of x0
	xb_vecN_2xcf32 modxphasorx0;              // product of |x| and the phasor (sign) of x0
	xb_vecN_2xcf32 alpha_w_dot_M;             // scalar product of alpha_w[] with row or column of M
	xb_vecN_2xcf32 alpha_w_dot_P;             // scalar product of alpha_w[] with column of P
	xb_vecN_2xcf32 ctmp;
	xb_vecN_2xcf32 *alpha_w;                  // pointer to pBuffer
	xb_vecN_2xf32  ctmp_real, ctmp_imag;
	xb_vecN_2xf32  modsqx;                    // |x|^2 where x is the on and below sub-diagonal vector
	xb_vecN_2xf32  modx;                      // |x| where x is the on and below sub-diagonal vector
	xb_vecN_2xf32  two_over_alphasq;          // 2 / alpha^2 = 1 / {|x|.(|x| + |x0|)}
	xb_vecN_2xf32  modsqx0, modx0;            // |x0|^2 and |x0|
	xb_vecN_2xf32  recipmodx0;                // 1/|x0|
	xb_vecN_2xf32  zeros = BBE_ZERON_2XF32();
	xb_vecN_2xf32  ones = (xb_vecN_2xf32)1UL;
	vboolN_2       detect_flags;

	// initialise overall orthogonal matrix P[n][n] to the identity matrix
	Rsdk_EF_identity_Mof32cp8(poutP, size);
	if (poutH != pin)
	{
		Rsdk_DT_copy_Mof32cp8Mif32cp8(poutH, pin, size, size);
	}
	alpha_w = pbuff;
	/* loop colj over n-2 iterations for columns 0 to n-3 inclusive applying Householder transformations P[n][n]
	 * where P has inactive identity matrix dimension size (colj+1) by (colj+1) in upper left and
	 * active dimension size (n-1-colj) by (n-1-colj) defined by alpha_w in lower right.
	 * */
	for (colj = 0UL; colj <= (size - 3UL); colj++)
	{
		/*  calculate |x|^2 where x contains the n-1-colj sub-diagonal and below sub-diagonal elements in H[][colj].
		 * n-1-colj iterations with minimum iterations <- 2 for last column colj <- n - 3.
		 * */
	    modsqx = zeros;
	    for (i = colj + 1UL; i < size; i++)
	    {
	    	modsqx      += BBE_MAGN_2XCF32(poutH[(i * size) + colj]);
	    }
	    // set modx <- |x| and recipmodx <- 1/|x|
	    modx             = BBE_SQRTN_2XF32(modsqx);
	    // compute |x0|^2, |x0| and 1/|x0| where x0 <- H[colj+1][colj]
	    modsqx0          = BBE_MAGN_2XCF32(poutH[((colj + 1UL) * size) + colj]);
	    modx0            = BBE_SQRTN_2XF32(modsqx0);
	    recipmodx0       = BBE_DIVN_2XF32(ones, BBE_SQRTN_2XF32(modsqx0));
	    /* set two_over_alphasq <- 2 / alpha^2 eq 1 / |x|.(|x| + |x0|)
	     * if |x| <- 0 then |x0| <- 0
	     * */
	    detect_flags     = (vboolN_2)( modx != zeros );
	    two_over_alphasq = BBE_MOVN_2XF32T(BBE_DIVN_2XF32(ones, modx * (modx + modx0)), zeros, detect_flags);

	    /* set phasorx0 <- |x| . (x[0] / |x[0]|) avoiding division by zero
	     * note: phasorx0 <- (1.0F, 0.0F) if x[0] <- (0.0F,0.0F) to match the real QR algorithm
	     * */
	    detect_flags     = (vboolN_2)( modsqx0 != zeros );
	    ctmp_real        = recipmodx0 * BBE_CREALN_2XCF32(poutH[((colj + 1UL) * size) + colj]);
	    ctmp_imag        = recipmodx0 * BBE_CIMAGN_2XCF32(poutH[((colj + 1UL) * size) + colj]);
	    ctmp             = BBE_CMPLXN_2XF32(ctmp_imag, ctmp_real);
	    phasorx0         = BBE_MOVN_2XCF32T(ctmp, BBE_CMPLXN_2XF32(zeros, ones), detect_flags);
	    // set modxphasorx0 <- modx * phasorx0
	    ctmp_real        = modx * BBE_CREALN_2XCF32(phasorx0);
	    ctmp_imag        = modx * BBE_CIMAGN_2XCF32(phasorx0);
	    modxphasorx0     = BBE_CMPLXN_2XF32(ctmp_imag, ctmp_real);
	    /* the vector alpha_w[] defining P has full dimension n by n but active dimension (n-1-colj) by (n-1-colj)
	     * the elements alpha_w[0] to alpha_w[colj] implicitly equal 0 but are never used.
	     * set the upper element alpha_w[0] <- x[0] + |x|.phasor(x[0])
	     * set upper element 0 of transformed vector (P.x)[0] <- H[colj + 1][colj] eq -|x|.phasor(x[0])
	     * */
	    alpha_w[colj + 1UL]                    = poutH[((colj + 1UL) * size) + colj] + modxphasorx0;
	    poutH[((colj + 1UL) * size) + colj] = -modxphasorx0;
	    /* loop i setting the remaining n-colj-2 elements in alpha_w indexed [colj + 2] to [n - 1] and
	     * zeroing the n-colj-2 below sub-diagonal elements in vector x[] <- H[][colj]
	     * this loop has minimum 1 iteration on last pass colj <- n-3.
	     * */
	    for (i = (colj + 2UL); i < size; i++)
	    {
	    	// set alpha_w[i] = x[i] = H[i][colj]
	    	alpha_w[i]                  = poutH[(i * size) + colj];
	    	// set x[i] <- H[i][colj] = 0.0F since the Householder reflection zeroes these elements
	    	poutH[(i * size) + colj] = BBE_ZERON_2XCF32();
	    }
	    /* (1) pre-multiply: M <- P.M where P[n][n] has active dimension (n-1-colj) by (n-1-colj).
	     * only the lower right block of size (n-1-colj) by (n-1-colj) is changed.
	     * loop j over (n-1-colj) columns indexed from colj+1 to n-1 inclusive.
	     * this loop has minimum 2 iterations on last pass when colj <- n-3.
	     * */
	    for (j = (colj + 1UL); j < size; j++)
	    {
	    	/* loop i over (n-1-colj) rows indexed from colj+1 to n-1 inclusive computing the
	    	 * scalar product of alpha_w^H with column j of M
	    	 * */
	    	alpha_w_dot_M      = BBE_ZERON_2XCF32();
	    	for (i = (colj + 1UL); i < size; i++)
	    	{
	    		alpha_w_dot_M += (BBE_CONJN_2XCF32(alpha_w[i]) * poutH[(i * size) + j]);
	    	}
	    	// set ctmp <- 2 / alpha^2 . alpha_w^H.H[][j]
	    	ctmp_real = two_over_alphasq * BBE_CREALN_2XCF32(alpha_w_dot_M);
	    	ctmp_imag = two_over_alphasq * BBE_CIMAGN_2XCF32(alpha_w_dot_M);
	    	ctmp      = BBE_CMPLXN_2XF32(ctmp_imag, ctmp_real);
	    	/* loop i over (n-1-colj) rows indexed from colj+1 to n-1 inclusive computing
	    	 * H[i][j] <- H[i][j] - alpha_w[i] * (two_over_alphasq * alpha_w_dot_M)
	    	 * the minimum number of iterations is 2 when colj <- n-3.
	    	 * */
	    	for (i = colj + 1UL; i < size; i++)
	    	{
	    		poutH[(i * size) + j] -= (alpha_w[i] * ctmp);
	    	}
	    }
	    /* (2) post-multiply: M <- (P.M).P where P[n][n] has active dimension (n-1-colj) by (n-1-colj).
	     * only columns indexed from colj+1 to n-1 inclusive are changed.
	     * loop i over all rows indexed from 0 to n-1 inclusive
	     * */
	    for (i = 0UL; i < size; i++)
	    {
	    	/* loop j over (n-1-colj) columns indexed from colj+1 to n-1 inclusive computing the
	    	 * scalar product of row i of M with alpha_w.
	    	 * the minimum number of iterations is 2 when colj <- n-3.
	    	 * */
	    	alpha_w_dot_M = BBE_ZERON_2XCF32();
	    	for (j = (colj + 1UL); j < size; j++)
	    	{
	    		alpha_w_dot_M += (poutH[(i * size) + j] * alpha_w[j]);
	    	}
	    	// set ctmp <- 2 / alpha^2 . H[i][].alpha_w
	    	ctmp_real = two_over_alphasq * BBE_CREALN_2XCF32(alpha_w_dot_M);
	    	ctmp_imag = two_over_alphasq * BBE_CIMAGN_2XCF32(alpha_w_dot_M);
	    	ctmp      = BBE_CMPLXN_2XF32(ctmp_imag, ctmp_real);
	    	/* loop j over (n-1-colj) columns indexed from colj+1 to n-1 inclusive
	    	 * H[i][j] <- H[i][j] - (two_over_alphasq * alpha_w_dot_M) . alpha_w[i]^H
	    	 * the minimum number of iterations is 2 when colj <- n-3.
	    	 * */
	    	for (j = colj + 1UL; j < size; j++)
	    	{
	    		poutH[(i * size) + j] -= (BBE_CONJN_2XCF32(alpha_w[j]) * ctmp);
	    	}
	    }
	    /* (3) post-multiply: accumulate P'[colj] <- P'[colj-1] . P[colj].
	     * only columns indexed from colj+1 to n-1 inclusive are changed.
	     * loop i over all rows in P' indexed from 0 to n-1 inclusive
	     * */
	    for (i = 0UL; i < size; i++)
	    {
	    	/* loop j over (n-1-colj) columns indexed from colj+1 to n-1 inclusive computing the
	    	 * scalar product of row i of P with alpha_w.
	    	 * the minimum number of iterations is 2 when colj <- n-3
	    	 * */
	    	alpha_w_dot_P = BBE_ZERON_2XCF32();
	    	for (j = (colj + 1UL); j < size; j++)
	    	{
	    		alpha_w_dot_P += (poutP[(i * size) + j] * alpha_w[j]);
	    	}
	    	// set ctmp = two_over_alphasq * P[i][].alpha_w
	    	ctmp_real = two_over_alphasq * BBE_CREALN_2XCF32(alpha_w_dot_P);
	    	ctmp_imag = two_over_alphasq * BBE_CIMAGN_2XCF32(alpha_w_dot_P);
	    	ctmp      = BBE_CMPLXN_2XF32(ctmp_imag, ctmp_real);
	    	/* loop j over (n-1-colj) columns indexed from colj+1 to n-1 inclusive
	    	 * P[i][j] <- P[i][j] - (two_over_alphasq * alpha_w_dot_P).alpha_w[i]^H
	    	 * the minimum number of iterations equals 2 when colj <- n-3.
	    	 * */
	    	for (j = (colj + 1UL); j < size; j++)
	    	{
	    		poutP[(i * size) + j] -= (BBE_CONJN_2XCF32(alpha_w[j]) * ctmp);
	    	}
	    }
	}
}

#ifdef __cplusplus
}
#endif

/*******************************************************************************
* EOF
******************************************************************************/
