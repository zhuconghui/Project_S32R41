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
* @file           rsdk_dsp_lal_matrix_eigensolver.c
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
void Rsdk_LA_eigSy_Mof32p8Mof32p8Mif32p8(xb_vecN_2xf32 * pOutputD,
                                         xb_vecN_2xf32 * pOutputV,
                                         xb_vecN_2xf32 * pInput,
                                                uint32_t size,
                                                uint32_t passes)
{
	xb_vecN_2xf32 * pIn = pInput;
	xb_vecN_2xf32 * pX = pOutputV;
	xb_vecN_2xf32 * pA = pOutputD;
	
	xb_vecN_2xf32 * pApp;
	xb_vecN_2xf32 * pAqq;
	xb_vecN_2xf32 * pApq;
	xb_vecN_2xf32 * pAqp;
	xb_vecN_2xf32 * pArpr;
	xb_vecN_2xf32 * pArqr;
	xb_vecN_2xf32 * pXrp;
	xb_vecN_2xf32 * pXrq;
	xb_vecN_2xf32   one_f = (xb_vecN_2xf32)1UL;
	xb_vecN_2xf32   zero_f = BBE_ZERON_2XF32();
	xb_vecN_2xf32   cot2phi;
	xb_vecN_2xf32   tanphi;
	xb_vecN_2xf32   sinphi;
	xb_vecN_2xf32   cosphi;
	xb_vecN_2xf32   Apq;
	xb_vecN_2xf32   App;
	xb_vecN_2xf32   Aqq;
	xb_vecN_2xf32   Arpr;
	xb_vecN_2xf32   Arqr;
	xb_vecN_2xf32   Xrp;
	xb_vecN_2xf32   Xrq;
	xb_vecN_2xf32   temp1;
	xb_vecN_2xf32   temp2;
	vboolN_2        detects;
    uint32_t        pass;
    uint32_t        p;
    uint32_t        q;
    uint32_t        r;

    // initialise the matrix of eigenvectors X to the identity matrix
    Rsdk_EF_identity_Mof32p8(pX, size);
    // copy the input into matrix D if necessary
	if (pA != pIn)
	{
		Rsdk_DT_copy_Mof32p8Mif32p8(pA, pIn, size, size);
	}
    pX = pOutputV;
    pA = pOutputD;

    // perform requested number of passes over above diagonal elements
    for (pass = 0UL; pass < passes; pass++)
    {
         pApp = pA;
        // loop p over all rows with above diagonal elements: constant n-1 iterations
        for (p = 0UL; p < (size - 1UL); p++)
        {
            pAqq = &pApp[size + 1UL];
            pApq = &pApp[1UL];
            // loop q over above diagonal elements: n-p-1 iterations with minimum 1 (p=n-2) to maximum n-1 (p=0)
            for (q = p + 1UL; q < size; q++)
            {
                Apq     = *pApq;
                App     = *pApp;
                Aqq     = *pAqq;
                cot2phi = BBE_DIVN_2XF32((Aqq - App), (xb_vecN_2xf32)2UL * Apq);
                // if (cot2phi is greater or eqaul than 0) then tanphi eq 1 / (cot2phi + sqrtf(1 + cot2phi * cot2phi))
                temp1   = BBE_DIVN_2XF32(one_f, cot2phi + BBE_SQRTN_2XF32(one_f + (cot2phi * cot2phi)));
                // else tanphi eq 1 / (cot2phi - sqrtf(1 + cot2phi * cot2phi))
                temp2   = BBE_DIVN_2XF32(one_f, cot2phi - BBE_SQRTN_2XF32(one_f + (cot2phi * cot2phi)));
                detects = BBE_OGEN_2XF32(cot2phi, zero_f);
                tanphi  = BBE_MOVN_2XF32T(temp1, temp2, detects);
                // if (Apq is equal 0): tanphi <- 0
                detects = (vboolN_2)( Apq == zero_f );
                tanphi  = BBE_MOVN_2XF32T(zero_f, tanphi, detects);
                cosphi  = BBE_DIVN_2XF32(one_f, BBE_SQRTN_2XF32(one_f + (tanphi * tanphi)));
                sinphi  = tanphi * cosphi;
                *pApp   = App - (tanphi * Apq);
                *pAqq   = Aqq + (tanphi * Apq);
                *pApq   = zero_f;
                pArpr   = &pA[p];
                pArqr   = &pA[q];
                // (1) apply rotation to columns p and q (rows 0 to p-1)
                // p iterations range 0 to n-2
                for (r = 0UL; r < p; r++)
                {
                    Arpr   = *pArpr;
                    Arqr   = *pArqr;
                    // A[r][p] eq cos(phi) * A[r][p] - sin(phi) * A[r][q]
                    *pArpr = (cosphi * Arpr) - (sinphi * Arqr);
                    // A[r][q] eq sin(phi) * A[r][p] + cos(phi) * A[r][q]
                    *pArqr = (sinphi * Arpr) + (cosphi * Arqr);
                    pArpr += size;
                    pArqr += size;
                }
                pArpr = &pApp[1UL];
                pArqr = &pApq[size];
                // (2) apply rotation to rows p and q (columns q+1 to n-1)
                // n-q-1 iterations range 0 to n-2
                for (r = p + 1UL; r < q; r++)
                {
                    Arpr   = *pArpr;
                    Arqr   = *pArqr;
                    // A[p][r] eq cos(phi) * A[p][r] - sin(phi) * A[q][r]
                    *pArpr = (cosphi * Arpr) - (sinphi * Arqr);
                    // A[q][r] eq sin(phi) * A[p][r] + cos(phi) * A[q][r]
                    *pArqr = (sinphi * Arpr) + (cosphi * Arqr);
                    pArpr += 1UL;
                    pArqr += size;
                }
                pArpr = &pApq[1UL];
                pArqr = &pAqq[1UL];
                // (3) apply rotation to remaining elements in row p and column q
                // q-p-1 iterations range 0 to n-2
                for (r = q + 1UL; r < size; r++)
                {
                    Arpr   = *pArpr;
                    Arqr   = *pArqr;
                    // A[r][p] eq cos(phi) * A[p][r] - sin(phi) * A[r][q]
                    *pArpr = (cosphi * Arpr) - (sinphi * Arqr);
                    // A[r][q] eq sin(phi) * A[p][r] + cos(phi) * A[r][q]
                    *pArqr = (sinphi * Arpr) + (cosphi * Arqr);
                    pArpr += 1UL;
                    pArqr += 1UL;
                }

                // set pXrp <- &X[r=0][p] and pXrq=&X[r=0][q]
                pXrp = pX + p;
                pXrq = pX + q;
                // apply the jacobi rotation to eigenvector matrix X columns p and q
                // constant n iterations
                for (r = 0UL; r < size; r++)
				{
                    Xrp   = *pXrp;
                    Xrq   = *pXrq;
                    // X[r][p] eq cos(phi) * X[r][p] - sin(phi) * X[r][q]
                    *pXrp = (cosphi * Xrp) - (sinphi * Xrq);
                    // X[r][q] eq sin(phi) * X[r][p] + cos(phi) * X[r][q]
                    *pXrq = (sinphi * Xrp) + (cosphi * Xrq);
                    pXrp += size;
                    pXrq += size;
                }
                // update pAqq for next iteration of q
                pAqq = &pAqq[size + 1UL];
                pApq = &pApq[1UL];
            } // end of loop over columns q
            pApp = &pApp[size + 1UL];
        } // end of loop over rows p
    } // end of loop over passes i

    // copy above diagonal elements to below diagonal
    // loop p over rows 0 to n-2 inclusive with above diagonal elements
    // constant n-1 iterations.
    // set pApp = &A[p=0][p=0] = A
    pApp = pA;
    for (p = 0UL; p <= (size - 2UL); p++)
    {
        // set pApq eq &A[p][q=p+1] eq pApp + 1
        pApq = pApp + 1UL;
        // set pAqp eq &A[q=p+1][p] eq pApp + n
        pAqp = pApp + size;
        // loop q over n-1-p above diagonal columns
        // minimum iterations=1 when p=n-2
        for (q = p + 1UL; q < size; q++)
        {
            // A[q + p * n] eq A[p + q * n]
            *pAqp = *pApq;
            pApq++;
            pAqp += size;
        }   // end of loop q over columns

        pApp += size + 1UL;
    }   // end of loop p over rows
}

void Rsdk_LA_eigHm_Mof32cp8Mof32cp8Mif32cp8(xb_vecN_2xcf32 * pOutputD,
                                            xb_vecN_2xcf32 * pOutputV,
                                            xb_vecN_2xcf32 * pInput,
                                                    uint32_t size,
                                                    uint32_t passes)
{
    xb_vecN_2xcf32 * pIn = pInput;
    xb_vecN_2xcf32 * pX = pOutputV;
    xb_vecN_2xcf32 * pA = pOutputD;
	
    xb_vecN_2xcf32 * pApp;
    xb_vecN_2xcf32 * pAqq;
    xb_vecN_2xcf32 * pApq;
    xb_vecN_2xcf32 * pAqp;
    xb_vecN_2xcf32 * pArpr;
    xb_vecN_2xcf32 * pArqr;
    xb_vecN_2xcf32 * pXrp;
    xb_vecN_2xcf32 * pXrq;
    xb_vecN_2xcf32   Apq;
    xb_vecN_2xcf32   Arpr;
    xb_vecN_2xcf32   Arqr;
    xb_vecN_2xcf32   Xrp;
    xb_vecN_2xcf32   Xrq;
    xb_vecN_2xcf32   s;
    xb_vecN_2xcf32   tempc1;
    xb_vecN_2xcf32   tempc2;
    xb_vecN_2xf32    two_f  = (xb_vecN_2xf32)2.0F;
    xb_vecN_2xf32    one_f  = (xb_vecN_2xf32)1.0F;
    xb_vecN_2xf32    half_f = (xb_vecN_2xf32)0.5F;
    xb_vecN_2xf32    zero_f = BBE_ZERON_2XF32();
    xb_vecN_2xf32    Aqq;
    xb_vecN_2xf32    App;
    xb_vecN_2xf32    modsqHpq;
    xb_vecN_2xf32    Appqq;
    xb_vecN_2xf32    delta;
    xb_vecN_2xf32    beta_m;
    xb_vecN_2xf32    betasq;
    xb_vecN_2xf32    sum_sq;
    xb_vecN_2xf32    invsqrtsq;
    xb_vecN_2xf32    invsq;
    xb_vecN_2xf32    c;
    xb_vecN_2xf32    s_real;
    xb_vecN_2xf32    s_imag;
    xb_vecN_2xf32    csq;
    xb_vecN_2xf32    alpha;
    xb_vecN_2xf32    modssq;
	xb_vecN_2xf32    temp1;
	xb_vecN_2xf32    temp2;
	vboolN_2         detects;
    uint32_t         pass;
    uint32_t         p;
    uint32_t         q;
    uint32_t         r;

    // initialise the matrix of eigenvectors X to the identity matrix
    Rsdk_EF_identity_Mof32cp8(pX, size);
    // copy the input into matrix D if necessary
	if (pA != pIn)
	{
		Rsdk_DT_copy_Mof32cp8Mif32cp8(pA, pIn, size, size);
	}
    pX = pOutputV;
    pA = pOutputD;
    // perform requested number of passes over above diagonal elements
    for (pass = 0UL; pass < passes; pass++)
    {
         pApp = pA;
        // loop p over all rows with above diagonal elements: constant n-1 iterations
        for (p = 0UL; p < (size - 1UL); p++)
        {
            pAqq = &pApp[size + 1UL];
            pApq = &pApp[1UL];
            // loop q over above diagonal elements: n-p-1 iterations with minimum 1 (p=n-2) to maximum n-1 (p=0)
            for (q = p + 1UL; q < size; q++)
            {
                Apq       = *pApq;
                App       = BBE_CREALN_2XCF32(*pApp);
                Aqq       = BBE_CREALN_2XCF32(*pAqq);
                modsqHpq  = (BBE_CREALN_2XCF32(Apq) * BBE_CREALN_2XCF32(Apq)) + (BBE_CIMAGN_2XCF32(Apq) * BBE_CIMAGN_2XCF32(Apq));
                Appqq     = half_f * (App - Aqq);
                delta     = (Appqq * Appqq) + modsqHpq;
                // if (appqq is greater or equal than 0) then beta_m eq Appqq + sqrtf(delta)
                temp1     = Appqq + BBE_SQRTN_2XF32(delta);
                // else beta_m eq Appqq - sqrtf(delta)
                temp2     = Appqq - BBE_SQRTN_2XF32(delta);
                detects   = BBE_OGEN_2XF32(Appqq, zero_f);
                beta_m    = BBE_MOVN_2XF32T(temp1, temp2, detects);
                betasq    = beta_m * beta_m;
                sum_sq    = modsqHpq + betasq;
                invsqrtsq = BBE_DIVN_2XF32(one_f, BBE_SQRTN_2XF32(sum_sq));
                invsq     = BBE_DIVN_2XF32(one_f, sum_sq);
                c         = BBE_ABSN_2XF32(beta_m) * invsqrtsq;
                csq       = betasq * invsq;
                // if (beta_m >= 0) then s eq conj(Apq) * invsqrtsq
                tempc1    = BBE_CMPLXN_2XF32((-BBE_CIMAGN_2XCF32(Apq) * invsqrtsq), (BBE_CREALN_2XCF32(Apq) * invsqrtsq));
                // else s eq - conj(Apq) * invsqrtsq
                tempc2    = BBE_CMPLXN_2XF32((BBE_CIMAGN_2XCF32(Apq) * invsqrtsq), (-BBE_CREALN_2XCF32(Apq) * invsqrtsq));
                detects   = BBE_OGEN_2XF32(beta_m, zero_f);
                s         = BBE_MOVN_2XCF32T(tempc1, tempc2, detects);
                // if (modsqHpq eq zero_f) then {c eq 1; csq eq 1, s eq 0 + 0i}
                detects   = (vboolN_2)( modsqHpq == zero_f );
                c         = BBE_MOVN_2XF32T(one_f, c, detects);
                csq       = BBE_MOVN_2XF32T(one_f, csq, detects);
                s         = BBE_MOVN_2XCF32T(BBE_ZERON_2XCF32(), s, detects);
                s_real	  = BBE_CREALN_2XCF32(s);
                s_imag    = BBE_CIMAGN_2XCF32(s);
                alpha     = (- modsqHpq * beta_m) * invsq;
                modssq    = one_f - csq;
                *pApp     = BBE_CMPLXN_2XF32(BBE_CIMAGN_2XCF32(*pApp), (- alpha * two_f) + (csq * App) + (modssq * Aqq));
                *pAqq     = BBE_CMPLXN_2XF32(BBE_CIMAGN_2XCF32(*pAqq), (alpha * two_f) + (modssq * App) + (csq * Aqq));
                *pApq     = BBE_ZERON_2XCF32();
                pArpr     = &pA[p];
                pArqr     = &pA[q];
                // (1) apply rotation to columns p and q (rows 0 to p-1)
                // p iterations range 0 to n-2
                for (r = 0UL; r < p; r++)
                {
                    Arpr   = *pArpr;
                    Arqr   = *pArqr;
                    // A(r,p) eq c * Arp + s * Arq
                    temp1  = (c * BBE_CIMAGN_2XCF32(Arpr)) + (s_real * BBE_CIMAGN_2XCF32(Arqr)) + (s_imag * BBE_CREALN_2XCF32(Arqr));
                    temp2  = (c * BBE_CREALN_2XCF32(Arpr)) + (s_real * BBE_CREALN_2XCF32(Arqr)) - (s_imag * BBE_CIMAGN_2XCF32(Arqr));
                    *pArpr = BBE_CMPLXN_2XF32(temp1, temp2);
                    // A(r,q) eq c * Arq - conj(s) * Arp
                    temp1  = (c * BBE_CIMAGN_2XCF32(Arqr)) - (s_real * BBE_CIMAGN_2XCF32(Arpr)) + (s_imag * BBE_CREALN_2XCF32(Arpr));
                    temp2  = (c * BBE_CREALN_2XCF32(Arqr)) - (s_real * BBE_CREALN_2XCF32(Arpr)) - (s_imag * BBE_CIMAGN_2XCF32(Arpr));
                    *pArqr = BBE_CMPLXN_2XF32(temp1, temp2);
                    pArpr += size;
                    pArqr += size;
                }
                pArpr = &pApp[1UL];
                pArqr = &pApq[size];
                // (2) apply rotation to rows p and q (columns q+1 to n-1)
                // n-q-1 iterations range 0 to n-2
                for (r = p + 1UL; r < q; r++)
                {
                    Arpr   = *pArpr;
                    Arqr   = *pArqr;
                    // A(p,r) eq c * Apr + conj(s) * conj(Arq)
                    temp1  = (c * BBE_CIMAGN_2XCF32(Arpr)) - (s_real * BBE_CIMAGN_2XCF32(Arqr)) - (s_imag * BBE_CREALN_2XCF32(Arqr));
                    temp2  = (c * BBE_CREALN_2XCF32(Arpr)) + (s_real * BBE_CREALN_2XCF32(Arqr)) - (s_imag * BBE_CIMAGN_2XCF32(Arqr));
                    *pArpr = BBE_CMPLXN_2XF32(temp1, temp2);
                    // A(r,q) eq c * Arq - conj(s) * conj(Apr)
                    temp1  = (c * BBE_CIMAGN_2XCF32(Arqr)) + (s_real * BBE_CIMAGN_2XCF32(Arpr)) + (s_imag * BBE_CREALN_2XCF32(Arpr));
                    temp2  = (c * BBE_CREALN_2XCF32(Arqr)) - (s_real * BBE_CREALN_2XCF32(Arpr)) + (s_imag * BBE_CIMAGN_2XCF32(Arpr));
                    *pArqr = BBE_CMPLXN_2XF32(temp1, temp2);
                    pArpr += 1UL;
                    pArqr += size;
                }
                pArpr = &pApq[1UL];
                pArqr = &pAqq[1UL];
                // (3) apply rotation to remaining elements in row p and column q
                // q-p-1 iterations range 0 to n-2
                for (r = q + 1UL; r < size; r++)
                {
                    Arpr   = *pArpr;
                    Arqr   = *pArqr;
                    // A(p,r) eq c * Apr + conj(s) * Aqr
                    temp1  = (c * BBE_CIMAGN_2XCF32(Arpr)) + (s_real * BBE_CIMAGN_2XCF32(Arqr)) - (s_imag * BBE_CREALN_2XCF32(Arqr));
                    temp2  = (c * BBE_CREALN_2XCF32(Arpr)) + (s_real * BBE_CREALN_2XCF32(Arqr)) + (s_imag * BBE_CIMAGN_2XCF32(Arqr));
                    *pArpr = BBE_CMPLXN_2XF32(temp1, temp2);
                    // A(q,r) eq c * Aqr - s * Apr
                    temp1  = (c * BBE_CIMAGN_2XCF32(Arqr)) - (s_real * BBE_CIMAGN_2XCF32(Arpr)) - (s_imag * BBE_CREALN_2XCF32(Arpr));
                    temp2  = (c * BBE_CREALN_2XCF32(Arqr)) - (s_real * BBE_CREALN_2XCF32(Arpr)) + (s_imag * BBE_CIMAGN_2XCF32(Arpr));
                    *pArqr = BBE_CMPLXN_2XF32(temp1, temp2);
                    pArpr += 1UL;
                    pArqr += 1UL;
                }
                // set pXrp eq &X[r=0][p] and pXrq eq &X[r=0][q]
                pXrp = pX + p;
                pXrq = pX + q;
                // apply the jacobi rotation to eigenvector matrix X columns p and q
                // constant n iterations
                for (r = 0UL; r < size; r++)
                {
                    Xrp   = *pXrp;
                    Xrq   = *pXrq;
                    // X(r,p) eq c * Xrp + s * Xrq
                    temp1 = (c * BBE_CIMAGN_2XCF32(Xrp)) + (s_real * BBE_CIMAGN_2XCF32(Xrq)) + (s_imag * BBE_CREALN_2XCF32(Xrq));
                    temp2 = (c * BBE_CREALN_2XCF32(Xrp)) + (s_real * BBE_CREALN_2XCF32(Xrq)) - (s_imag * BBE_CIMAGN_2XCF32(Xrq));
                    *pXrp = BBE_CMPLXN_2XF32(temp1, temp2);
                    // X(r,q) eq c * Xrq - conj(s) * Xrp
                    temp1 = (c * BBE_CIMAGN_2XCF32(Xrq)) - (s_real * BBE_CIMAGN_2XCF32(Xrp)) + (s_imag * BBE_CREALN_2XCF32(Xrp));
                    temp2 = (c * BBE_CREALN_2XCF32(Xrq)) - (s_real * BBE_CREALN_2XCF32(Xrp)) - (s_imag * BBE_CIMAGN_2XCF32(Xrp));
                    *pXrq = BBE_CMPLXN_2XF32(temp1, temp2);
                    pXrp += size;
                    pXrq += size;
                }
                // update pAqq for next iteration of q
                pAqq = &pAqq[size + 1UL];
                pApq = &pApq[1UL];
            } // end of loop over columns q
            pApp = &pApp[size + 1UL];
        } // end of loop over rows p
    } // end of loop over passes i
    // copy above diagonal elements to below diagonal
    // loop p over rows 0 to n-2 inclusive with above diagonal elements
    // constant n-1 iterations.
    // set pApp eq &A[p=0][p=0] eq A
    pApp = pA;
    for (p = 0UL; p <= (size - 2UL); p++)
    {
        // set pApq eq &A[p][q=p+1] eq pApp + 1
        pApq = pApp + 1UL;
        // set pAqp eq &A[q=p+1][p] eq pApp + n
        pAqp = pApp + size;
        // loop q over n-1-p above diagonal columns
        // minimum iterations eq 1 when p<-n-2
        for (q = p + 1UL; q < size; q++)
        {
            // A[q + p * n] eq A[p + q * n];
            *pAqp = *pApq;
            pApq++;
            pAqp += size;
        }   // end of loop q over columns

        pApp += size + 1UL;
    }   // end of loop p over rows
}

static void Rsdk_LA_eigUpHessHelper_Vof32cp8Mof32cp8Mif32cp8(xb_vecN_2xcf32 * __restrict pOutputD,
                                                             xb_vecN_2xcf32 * __restrict pOutputV,
                                                                        xb_vecN_2xcf32 * pInput,
                                                                              uint32_t * iterations,
                                                                                uint32_t size,
                                                                                  xtbool vecCompute)
{
	xb_vecN_2xcf32 (*pM)[size][size] = (xb_vecN_2xcf32 (*)[size][size]) pInput;
	xb_vecN_2xcf32 (*pX)[size][size] = (xb_vecN_2xcf32 (*)[size][size]) pOutputV;
	xb_vecN_2xcf32 * pA = pOutputD;
	
	xb_vecN_2xcf32 rhoA, rhoB;					    // shifts
	xb_vecN_2xcf32 ctmpA, ctmpB, ctmpC;			    // scratch
	xb_vecN_2xcf32 phasor;						    // complex phasor
	xb_vecN_2xcf32 cplxOnes;
	xb_vecN_2xcf32 tmp;						        // scratch
	xb_vecN_2xf32  ftmp, ftmp2;                     // scratch
	xb_vecN_2xf32  mod, modsq, rmod, rmodsq;        // mod, mod^2, 1/mod, 1/mod^2
	vboolN_2       flagsA, flagsB;                  // decisional flags
	int32_t        i, j, k;
	int32_t        itk;                             // iterations performed for current eigenvalue k
	uint8_t        flagsAll;

	cplxOnes                         = BBE_CMPLXN_2XF32((xb_vecN_2xf32)0.0F, (xb_vecN_2xf32)1.0F);
	// define matrix pointers for variable matrix dimensions passed at runtime

	
	rhoA = BBE_ZERON_2XCF32();
	
	if (pOutputV != NULL)
	{
		Rsdk_EF_identity_Mof32cp8(pOutputV, size);
	}
	/* transform subdiagonal elements to be real (create real sub-diagonal elements)
	 * loop i down elements of the leading diagonal with sub-diagonal element to the left
	 * */
	for (i = 1L; i < (int32_t)size; i++)
	{
		// set phasor eq M[i][i-1]/|M[i][i-1]|
		mod              = BBE_SQRTN_2XF32(BBE_MAGN_2XCF32((*pM)[i][i - 1L]));
		rmod             = BBE_RECIPN_2XF32(mod);
		flagsA           = (vboolN_2)( mod != BBE_ZERON_2XF32() );
		phasor           = BBE_CMPLXN_2XF32((BBE_CIMAGN_2XCF32((*pM)[i][i - 1L]) * rmod), (BBE_CREALN_2XCF32((*pM)[i][i - 1L]) * rmod));
		phasor           = BBE_MOVN_2XCF32T(phasor, cplxOnes, flagsA);
		// apply forward and inverse phasor unitary transformation to M[i][i-1]
		(*pM)[i][i - 1L] = BBE_CMPLXN_2XF32(BBE_ZERON_2XF32(), mod);
		/* apply the forward unitary similarity transformation on and above diagonal elements in row i
		 * loop j over on and above diagonal elements
		 * */
		for (j = i; j < (int32_t)size; j++)
		{
			(*pM)[i][j] *= BBE_CONJN_2XCF32(phasor);
		}
		/* apply the inverse unitary similarity transformation to on and above sub-diagonal elements in column i
		 * loop j down column i
		 * */
		k = i + 1L;
		if (k == (int32_t)size)
		{
			k = (int32_t)size - 1L;
		}
		for (j = 0L; j <= k; j++)
		{
			(*pM)[j][i] *= phasor;
		}
		// apply the inverse unitary similarity transformation to the eigenvectors matrix X
		if (vecCompute)
		{
			for (j = 0L; j < (int32_t)size; j++)
			{
				(*pX)[j][i] *= phasor;
			}
		}
	}
	// initialise the shift rhoB to zero
	rhoB = BBE_ZERON_2XCF32();
	// loop over all n eigenvalues k indexed in reverse order from k = n - 1 to 0 inclusive
	for (k = (int32_t)size - 1L; k >= 0; k--)
	{
		// reset the iterations count itk for this eigenvalue k
		itk = 0L;
		// loop indefinitely solving for eigenvalue k
		while (true)
		{
			// break if k eq 0
			if (k == 0L)
			{
				break;
			}
			// break and move to next eigenvalue k-1 if M[k][k-1] is zero within numerical accuracy
			ftmp     = BBE_ABSN_2XF32(BBE_CREALN_2XCF32((*pM)[k - 1L][k - 1L])) + BBE_ABSN_2XF32(BBE_CIMAGN_2XCF32((*pM)[k - 1L][k - 1L])) +
				       BBE_ABSN_2XF32(BBE_CREALN_2XCF32((*pM)[k][k])) + BBE_ABSN_2XF32(BBE_CIMAGN_2XCF32((*pM)[k][k]));
			flagsA   = (vboolN_2)( ftmp != (ftmp + BBE_ABSN_2XF32(BBE_CREALN_2XCF32((*pM)[k][k - 1L]))) );
			/* break only when all are done */
			flagsAll = *(uint8_t *) &flagsA;
			if (!flagsAll)
			{
				break;
			}
			// proceed with standard shift rhoA for all iterations except itk=10 and itk=20
			if ((itk != 10L) && (itk != 20L))
			{
				rhoA   = BBE_MOVN_2XCF32T((*pM)[k][k], rhoA, flagsA);
				ctmpA  = BBE_CMPLXN_2XF32((BBE_CIMAGN_2XCF32((*pM)[k - 1L][k]) * BBE_CREALN_2XCF32((*pM)[k][k - 1L])),
						                  (BBE_CREALN_2XCF32((*pM)[k - 1L][k]) * BBE_CREALN_2XCF32((*pM)[k][k - 1L])));
				ctmpB  = BBE_CMPLXN_2XF32(((xb_vecN_2xf32)0.5F * BBE_CIMAGN_2XCF32((*pM)[k - 1L][k - 1L] - rhoA)),
						                  ((xb_vecN_2xf32)0.5F * BBE_CREALN_2XCF32((*pM)[k - 1L][k - 1L] - rhoA)));
				tmp    = (ctmpB * ctmpB) + ctmpA;
				Rsdk_EF_sqrt_Vof32cp8Vif32cp8(&ctmpC, &tmp, 1UL);
				flagsB = (vboolN_2)( ((BBE_CREALN_2XCF32(ctmpB) * BBE_CREALN_2XCF32(ctmpC)) +
					                  (BBE_CIMAGN_2XCF32(ctmpB) * BBE_CIMAGN_2XCF32(ctmpC))) < BBE_ZERON_2XF32() );
				BBE_NEGN_2XCF32T(ctmpC, ctmpC, flagsB);
				ctmpB += ctmpC;
				modsq  = BBE_MAGN_2XCF32(ctmpB);
				flagsB = (vboolN_2)( modsq != BBE_ZERON_2XF32() );
				rmodsq = BBE_MOVN_2XF32T(BBE_RECIPN_2XF32(modsq), BBE_ZERON_2XF32(), flagsB);
				ctmpA  = BBE_CMPLXN_2XF32((BBE_CIMAGN_2XCF32(ctmpA) * rmodsq), (BBE_CREALN_2XCF32(ctmpA) * rmodsq));
				ctmpC  = ctmpA * BBE_CONJN_2XCF32(ctmpB);
				rhoA   = BBE_MOVN_2XCF32T(rhoA - ctmpC, rhoA, flagsA);
			}
			else
			{
				// form exceptional shift rhoA on iterations itk<-10 and itk<-20 to jolt the convergence
				if (k == 1) {
					rhoA = BBE_MOVN_2XCF32T(BBE_CMPLXN_2XF32(BBE_ZERON_2XF32(), BBE_ABSN_2XF32(BBE_CREALN_2XCF32((*pM)[k][k - 1L]))), rhoA, flagsA);
				} else {
					rhoA = BBE_MOVN_2XCF32T(BBE_CMPLXN_2XF32(BBE_ZERON_2XF32(),
					   BBE_ABSN_2XF32(BBE_CREALN_2XCF32((*pM)[k][k - 1L])) + BBE_ABSN_2XF32(BBE_CREALN_2XCF32((*pM)[k - 1L][k - 2L]))), rhoA, flagsA);
				}
			}
			// remove shift rhoA from the diagonal
			for (i = 0L; i <= k; i++)
			{
				(*pM)[i][i] = BBE_MOVN_2XCF32T((*pM)[i][i] - rhoA, (*pM)[i][i], flagsA);
			}
			// update overall shift rhoB <- rhoB + rhoA
			rhoB = BBE_MOVN_2XCF32T(rhoB + rhoA, rhoB, flagsA);
			// reduce to triangle (rows)
			for (i = 1L; i <= k; i++)
			{
				ftmp                  = BBE_CREALN_2XCF32((*pM)[i - 1L][i - 1L]);
				ftmp2                 = ftmp * ftmp;
				ftmp                  = BBE_CIMAGN_2XCF32((*pM)[i - 1L][i - 1L]);
				ftmp2                += ftmp * ftmp;
				ftmp                  = BBE_CREALN_2XCF32((*pM)[i][i - 1L]);
				ftmp2                += ftmp * ftmp;
				mod                   = BBE_SQRTN_2XF32(ftmp2);
				rmod                  = BBE_RECIPN_2XF32(mod);
				// correct for division by zero and BBE_RECIPN_2XF32 deviations
				flagsB                = (vboolN_2)( (rmod != rmod) & (mod == mod) );
				rmod                  = BBE_MOVN_2XF32T((xb_vecN_2xf32)1.0F, rmod, flagsB);
				pA[i - 1L]            = BBE_MOVN_2XCF32T(BBE_CMPLXN_2XF32((BBE_CIMAGN_2XCF32((*pM)[i - 1L][i - 1L]) * rmod),
					                                                      (BBE_CREALN_2XCF32((*pM)[i - 1L][i - 1L]) * rmod)), pA[i - 1L], flagsA);
				(*pM)[i][i - 1L]      = BBE_MOVN_2XCF32T(BBE_CMPLXN_2XF32((BBE_CREALN_2XCF32((*pM)[i][i - 1L]) * rmod),
					                    (xb_vecN_2xf32)0.0F), (*pM)[i][i - 1L], flagsA);
				(*pM)[i - 1L][i - 1L] = BBE_MOVN_2XCF32T(BBE_CMPLXN_2XF32((xb_vecN_2xf32)0.0F, mod),
					                    (*pM)[i - 1L][i - 1L], flagsA);
				for (j = i; j < (int32_t)size; j++)
				{
					ctmpA             = (*pM)[i - 1L][j];
					ctmpB             = (*pM)[i][j];
					ctmpC             = BBE_CONJN_2XCF32(pA[i - 1L]) * ctmpA;
					(*pM)[i - 1L][j]  = BBE_MOVN_2XCF32T(BBE_CMPLXN_2XF32(BBE_CIMAGN_2XCF32(ctmpC) + (BBE_CIMAGN_2XCF32((*pM)[i][i - 1L]) * BBE_CIMAGN_2XCF32(ctmpB)),
						          	                                      BBE_CREALN_2XCF32(ctmpC) + (BBE_CIMAGN_2XCF32((*pM)[i][i - 1L]) * BBE_CREALN_2XCF32(ctmpB))), (*pM)[i - 1L][j], flagsA);
					ctmpC             = pA[i - 1L] * ctmpB;
					(*pM)[i][j]       = BBE_MOVN_2XCF32T(BBE_CMPLXN_2XF32(BBE_CIMAGN_2XCF32(ctmpC) - (BBE_CIMAGN_2XCF32((*pM)[i][i - 1L]) * BBE_CIMAGN_2XCF32(ctmpA)),
					                                                      BBE_CREALN_2XCF32(ctmpC) - (BBE_CIMAGN_2XCF32((*pM)[i][i - 1L]) * BBE_CREALN_2XCF32(ctmpA))), (*pM)[i][j], flagsA);
				}
			}
			// set phasor eq M[k][k]/|M[k][k]|
			mod         = BBE_SQRTN_2XF32(BBE_MAGN_2XCF32((*pM)[k][k]));
			rmod        = BBE_RECIPN_2XF32(mod);
			phasor      = BBE_CMPLXN_2XF32((BBE_CIMAGN_2XCF32((*pM)[k][k]) * rmod), (BBE_CREALN_2XCF32((*pM)[k][k]) * rmod));
			// correct for division by zero and BBE_RECIPN_2XF32 deviations
			flagsB      = (vboolN_2)( (rmod != rmod) & (mod == mod) );
			phasor      = BBE_MOVN_2XCF32T(cplxOnes, phasor, flagsB);
			// apply phasor rotation to M[k][k]
			(*pM)[k][k] = BBE_MOVN_2XCF32T(BBE_CMPLXN_2XF32((xb_vecN_2xf32)0.0F, mod), (*pM)[k][k], flagsA);
			// apply phasor down column k of M[][]
			for (j = k + 1L; j < (int32_t)size; j++)
			{
				(*pM)[k][j] = BBE_MOVN_2XCF32T((*pM)[k][j] * BBE_CONJN_2XCF32(phasor), (*pM)[k][j], flagsA);
			}
			// inverse operation (columns)
			for (j = 1L; j <= k; j++)
			{
				for (i = 0L; i <= j; i++)
				{
					ctmpA = BBE_CMPLXN_2XF32((xb_vecN_2xf32)0.0F, BBE_CREALN_2XCF32((*pM)[i][j - 1L]));
					ctmpB = (*pM)[i][j];
					if (i != j)
					{
						ctmpA = BBE_CMPLXN_2XF32(BBE_CIMAGN_2XCF32((*pM)[i][j - 1L]), BBE_CREALN_2XCF32(ctmpA));
						(*pM)[i][j - 1L] = BBE_MOVN_2XCF32T(BBE_CMPLXN_2XF32((BBE_CREALN_2XCF32(pA[j - 1L]) * BBE_CIMAGN_2XCF32(ctmpA)) + (BBE_CIMAGN_2XCF32(pA[j - 1L]) * BBE_CREALN_2XCF32(ctmpA)) + (BBE_CIMAGN_2XCF32((*pM)[j][j - 1L]) * BBE_CIMAGN_2XCF32(ctmpB)),
								      	                                      BBE_CREALN_2XCF32((*pM)[i][j - 1L])), (*pM)[i][j - 1L], flagsA);
					}
					(*pM)[i][j - 1L] =  BBE_MOVN_2XCF32T(BBE_CMPLXN_2XF32(BBE_CIMAGN_2XCF32((*pM)[i][j - 1L]),
								  	                                     (BBE_CREALN_2XCF32(pA[j - 1L]) * BBE_CREALN_2XCF32(ctmpA)) - (BBE_CIMAGN_2XCF32(pA[j - 1L]) * BBE_CIMAGN_2XCF32(ctmpA)) + (BBE_CIMAGN_2XCF32((*pM)[j][j - 1L]) * BBE_CREALN_2XCF32(ctmpB))), 
																		  (*pM)[i][j - 1L], flagsA);
					ctmpC            =  BBE_CONJN_2XCF32(pA[j - 1L]) * ctmpB;
					(*pM)[i][j]      =  BBE_MOVN_2XCF32T(BBE_CMPLXN_2XF32(BBE_CIMAGN_2XCF32(ctmpC) - (BBE_CIMAGN_2XCF32((*pM)[j][j - 1L]) * BBE_CIMAGN_2XCF32(ctmpA)),
								  	        	                          BBE_CREALN_2XCF32(ctmpC) - (BBE_CIMAGN_2XCF32((*pM)[j][j - 1L]) * BBE_CREALN_2XCF32(ctmpA))), (*pM)[i][j], flagsA);
				}
				// update eigenvectors matrix X[n][n]
				if (vecCompute)
				{
					for (i = 0L; i < (int32_t)size; i++)
					{
						ftmp             = BBE_CIMAGN_2XCF32((*pM)[j][j - 1L]);
						ctmpA            = BBE_CMPLXN_2XF32((ftmp * BBE_CIMAGN_2XCF32((*pX)[i][j])), (ftmp * BBE_CREALN_2XCF32((*pX)[i][j])));
						ctmpB            = BBE_CMPLXN_2XF32((ftmp * BBE_CIMAGN_2XCF32((*pX)[i][j - 1L])), (ftmp * BBE_CREALN_2XCF32((*pX)[i][j - 1L])));
						(*pX)[i][j - 1L] = BBE_MOVN_2XCF32T((pA[j - 1L] * (*pX)[i][j - 1L]) + ctmpA, (*pX)[i][j - 1L], flagsA);
						(*pX)[i][j]      = BBE_MOVN_2XCF32T((BBE_CONJN_2XCF32(pA[j - 1L]) * (*pX)[i][j]) - ctmpB, (*pX)[i][j], flagsA);
					}
				}
			}
			// apply phasor down column k of M[n][n]
			for (i = 0L; i <= k; i++)
			{
				(*pM)[i][k] = BBE_MOVN_2XCF32T(((*pM)[i][k] * phasor), (*pM)[i][k], flagsA);
			}
			// apply phasor down column k of X[n][n]
			if (vecCompute)
			{
				for (i = 0L; i < (int32_t)size; i++)
				{
					(*pX)[i][k] = BBE_MOVN_2XCF32T(((*pX)[i][k] * phasor), (*pX)[i][k], flagsA);
				}
			}
			// increment itk = the number of iterations performed for current eigenvalue k
			itk++;
			// decrement iterations and return if the maximum number of iterations have been performed
			(*iterations)--;
			if (*iterations == 0UL)
			{
				return;
			}
		}
		// add shift to M[k][k] to obtain eigenvalue eig_val[k]
		(*pM)[k][k] += rhoB;
		pA[k]  = (*pM)[k][k];
		// all eigenvalues have been found: back substitute to find vectors of upper triangular form
	}
	if (vecCompute)
	{
		// set mod to largest element in on and above diagonal elements of M[][]
		mod = BBE_ZERON_2XF32();
		for (i = 0L; i < (int32_t)size; i++)
		{
			for (j = i; j < (int32_t)size; j++)
			{
				ftmp   = BBE_ABSN_2XF32(BBE_CREALN_2XCF32(((*pM)[i][j]))) + BBE_ABSN_2XF32(BBE_CIMAGN_2XCF32(((*pM)[i][j])));
				flagsB = (vboolN_2)( ftmp > mod );
				mod    = BBE_MOVN_2XF32T(ftmp, mod, flagsB);
			}
		}
		for (k = (int32_t)size - 1L; k >= 1L; k--)
		{
			(*pM)[k][k] = cplxOnes;
			for (i = k - 1L; i >= 0L; i--)
			{
				ctmpA = BBE_ZERON_2XCF32();
				for (j = i + 1L; j <= k; j++)
				{
					ctmpA += ((*pM)[i][j] * (*pM)[j][k]);
				}
				ctmpB = pA[k] - pA[i];
				/* handle the case where ctmpB eq 0.0F to permit later ctmpA / ctmpB
				 * by setting ctmpB to be a small number relative to mod.
				 * set flags to be true for batch elements with ctmpB eq 0.0F;
				 * */
				flagsB = (vboolN_2)( ctmpB == BBE_ZERON_2XCF32() );
				ctmpB  = BBE_MOVN_2XCF32T(BBE_CMPLXN_2XF32((xb_vecN_2xf32)0.0F, mod), ctmpB, flagsB);
				while (true)
				{
					ctmpB    = BBE_MOVN_2XCF32T(BBE_CMPLXN_2XF32((xb_vecN_2xf32)0.0F, ((xb_vecN_2xf32)0.01F * BBE_CREALN_2XCF32(ctmpB))), ctmpB, flagsB);
					flagsB  &= (vboolN_2)( (mod + BBE_CREALN_2XCF32(ctmpB)) > mod );
					flagsAll = *(uint8_t *) &flagsB;
					if (!flagsAll) 
					{
						break;
					}
				};
				// set flagsB to true for non-zero matrices M[n][n]
				flagsB      = (vboolN_2)( mod != (xb_vecN_2xf32)0.0F );
				(*pM)[i][k] = BBE_ZERON_2XCF32();
				BBE_DIVN_2XCF32T((*pM)[i][k], ctmpA, ctmpB, flagsB);
			}
		}
		// multiply by transformation matrix to give vectors of original full matrix
		for (j = (int32_t)size - 1L; j >= 0L; j--)
		{
			for (i = 0L; i < (int32_t)size; i++)
			{
				ctmpA       = BBE_ZERON_2XCF32();
				for (k = 0L; k <= j; k++)
				{
					 ctmpA += ((*pX)[i][k] * (*pM)[k][j]);
				}
				(*pX)[i][j] = BBE_MOVN_2XCF32T(ctmpA, (*pX)[i][j], flagsB);
			}
		}
		// normalise the eigenvectors
		for (j = 0L; j < (int32_t)size; j++)
		{
			modsq           = (xb_vecN_2xf32)0.0F;
			for (i = 0L; i < (int32_t)size; i++)
			{
				modsq      += BBE_MAGN_2XCF32((*pX)[i][j]);
			}
			rmod            = BBE_RSQRTN_2XF32(modsq);
			for (i = 0; i < (int32_t)size; i++)
			{
				(*pX)[i][j] = BBE_CMPLXN_2XF32((BBE_CIMAGN_2XCF32((*pX)[i][j]) * rmod), (BBE_CREALN_2XCF32((*pX)[i][j]) * rmod));
			}
		}
	}
}

void  Rsdk_LA_eigValUpHess_Vof32cp8Mif32cp8(xb_vecN_2xcf32 * __restrict pOutputD,
                                                       xb_vecN_2xcf32 * pInput,
                                                             uint32_t * iterations,
                                                               uint32_t size)
{
	 Rsdk_LA_eigUpHessHelper_Vof32cp8Mof32cp8Mif32cp8(pOutputD, NULL, pInput, iterations, size, (xtbool)0);
}

void Rsdk_LA_eigUpHess_Vof32cp8Mof32cp8Mif32cp8(xb_vecN_2xcf32 * __restrict pOutputD,
                                                xb_vecN_2xcf32 * __restrict pOutputV,
                                                           xb_vecN_2xcf32 * pInput,
                                                                 uint32_t * iterations,
                                                                   uint32_t size)
{
	 Rsdk_LA_eigUpHessHelper_Vof32cp8Mof32cp8Mif32cp8(pOutputD, pOutputV, pInput, iterations, size, (xtbool)1);
}


// Rsdk_LA_hypoth_Vo1f32p8Vi1f32p8Vi1f32p8 : computes sqrt(a*a + b*b) without
// destructive underflow or overflow.
static void Rsdk_LA_hypoth_Vo1f32p8Vi1f32p8Vi1f32p8(
                                             xb_vecN_2xf32 * __restrict pOutput,
                                                        xb_vecN_2xf32 * pInput1,
                                                        xb_vecN_2xf32 * pInput2)
{
	xb_vecN_2xf32 smaller, larger;
	xb_vecN_2xf32 a, b, r;
	vboolN_2 flags;

	a = BBE_ABSN_2XF32(*pInput1);
	b = BBE_ABSN_2XF32(*pInput2);

	flags = (vboolN_2)(a > b);
	smaller = BBE_MOVN_2XF32T(b, a, flags);	// true, false, flags
	larger = BBE_MOVN_2XF32T(a, b, flags);	// true, false, flags

	r = BBE_DIVN_2XF32(smaller, larger);
	r = larger * BBE_SQRTN_2XF32((xb_vecN_2xf32)1.0F + (r * r));

	flags = (vboolN_2)(larger == (xb_vecN_2xf32)0.0F);
	*pOutput = BBE_MOVN_2XF32T((xb_vecN_2xf32)0.0F, r, flags);	// true, false, flags

}

static void Rsdk_LA_eigTriDgSyHelper_Mof32p8Mof32p8Mif32p8(
		                                    xb_vecN_2xf32 * __restrict pOutputD,
		                                    xb_vecN_2xf32 * __restrict pOutputV,
		                                                 xb_vecN_2xf32 * pInput,
											                int32_t  iterations,
		                                                           int32_t size,
											                 xtbool eigVectInit)
{
	xb_vecN_2xf32 (*pX)[size][size] = (xb_vecN_2xf32 (*)[size][size]) pOutputV;
	xb_vecN_2xf32 (*pA)[size][size] = (xb_vecN_2xf32 (*)[size][size]) pInput;

	xb_vecN_2xf32 e[size]; // scratch
	xb_vecN_2xf32 (*pD)[size] = (xb_vecN_2xf32 (*)[size]) pOutputD;
	xb_vecN_2xf32 (*pE)[size] = (xb_vecN_2xf32 (*)[size]) e;

	xb_vecN_2xf32 b, f, g, p, r;	// scratch
	xb_vecN_2xf32 dpd;				// sum of diagonal elements pD[m] and pD[m+1]
	xb_vecN_2xf32 s, c;				// sine and cosine of planar rotation
	xb_vecN_2xf32 bbe_ones = (xb_vecN_2xf32)1;
	vboolN_2 flags0, flagsrnz;		// predication flags
	int32_t i, j, k, lx, m;			// loop counters
	uint8_t ucharA;			// cast of predication flags

	f =  (xb_vecN_2xf32)0.0F;
	b =  (xb_vecN_2xf32)0.0F;

	// copy diagonal and off-diagonal elements of A[size][size] to pD[size] and e[size]
	(*pD)[0] = (*pA)[0][0];
	(*pE)[0] = (xb_vecN_2xf32)0.0F;
	for (i = 1L; i < size; i++)
	{
		(*pD)[i] = (*pA)[i][i];
		(*pE)[i] = (*pA)[i-1L][i];
	}

	// initialise the eigenvectors matrix X[size][size] to identity I[size][size] if requested
	if (eigVectInit)
	{
		for (i = 0L; i < size; i++)
		{
			for (j = 0L; j < size; j++)
			{
				(*pX)[i][j] = (xb_vecN_2xf32)0.0F;
			}
			(*pX)[i][i] = (xb_vecN_2xf32)1.0F;
		}
	}
	// shuffle the elements of e[1...size-1] down into e[0 .. size - 2] with e[size - 1] set to zero
	for (i = 1L; i < size; i++)
	{
		(*pE)[i - 1L] = (*pE)[i];
	}
	(*pE)[size - 1L] = (xb_vecN_2xf32)0.0F;

	// loop lx over all eigenvalues pD[lx]
	for (lx = 0L; lx < size; lx++)
	{
		// start of do-while (m != lx) performing QL iteration up to maximum iterations iterations
		do
		{
			// set m to the first off-diagonal element e[m] (where 1 <= m <= size - 2) with
			// numerically zero value for all batch instances when flags0 = 00000000b = FALSE.
			// default is m = size - 2 when loop exits normally when at least one instance has not converged.
			for (m = lx; m < (size - 1L); m++)
			{
				dpd = BBE_ABSN_2XF32((*pD)[m]) + BBE_ABSN_2XF32((*pD)[m + 1L]);
				flags0 = (vboolN_2)(dpd != (dpd + BBE_ABSN_2XF32((*pE)[m])));
				ucharA = *(uint8_t *) &flags0;
				if (!ucharA)
				{
					break;
				}
			}

			// if m == lx then e[lx] is zero for all instances so skip any further processing
			if (m != lx)
			{
				// return if the maximum number of iterations has been exceeded
				if (iterations == 0)
				{
					return;
				}
				(iterations)--;

				// calculate shift checking for e[lx]=0.0F for one or more instances
				g = BBE_DIVN_2XF32((*pD)[lx + 1L] - (*pD)[lx], (xb_vecN_2xf32)2.0F * (*pD)[lx]);
				Rsdk_LA_hypoth_Vo1f32p8Vi1f32p8Vi1f32p8(&r, &bbe_ones, &g);

				flags0 = (vboolN_2)(g < (xb_vecN_2xf32)0.0F);
				BBE_NEGN_2XF32T(r, r, flags0);

				g = (*pD)[m] - (*pD)[lx] + BBE_DIVN_2XF32((*pE)[lx], g + r);

				// set r and g to zero since e[lx] may be zero for one or more instances
				flags0 = (vboolN_2)((BBE_ABSN_2XF32(g) == (xb_vecN_2xf32)INFINITY_SP) | (g != g));
				g = BBE_MOVN_2XF32T((xb_vecN_2xf32)0.0F, g, flags0);	// true, false, flags

				flags0 = (vboolN_2)((BBE_ABSN_2XF32(r) == (xb_vecN_2xf32)INFINITY_SP) | (r != r));
				r = BBE_MOVN_2XF32T((xb_vecN_2xf32)0.0F, r, flags0);	// true, false, flags

				s = (xb_vecN_2xf32)1.0F;
				c = (xb_vecN_2xf32)1.0F;
				p = (xb_vecN_2xf32)0.0F;

				// loop i applying planar rotations
				// note: the scalar code breaks from this i loop when r == 0.0F so use flagsrnz to track r != 0.0F

				// set flagsrnz = 11111111b since no break has occurred from any instance
				flagsrnz = (vboolN_2)((xb_vecN_2xf32)0.0F == (xb_vecN_2xf32)0.0F);

				for (i = (m - 1L); i >= lx; i--)
				{
					// start of break predication block
					{
						f = BBE_MOVN_2XF32T(s * (*pE)[i], f, flagsrnz);	// true, false, flagsrnz
						b = BBE_MOVN_2XF32T(c * (*pE)[i], b, flagsrnz);	// true, false, flagsrnz
						Rsdk_LA_hypoth_Vo1f32p8Vi1f32p8Vi1f32p8(&r, &f, &g);
						(*pE)[i + 1L] = BBE_MOVN_2XF32T(r, (*pE)[i + 1L], flagsrnz);	// true, false, flagsrnz

						// update flagsrnz taking bits low if r == 0.0F
						flagsrnz &= (vboolN_2)(r != (xb_vecN_2xf32)0.0F);

						// if (r eq 0.0F) {pD[i + 1] -= p; e[m] eq 0.0F; break;}
						// in addition to predication, exit loop if all instances have r == 0.0F
						BBE_SUBN_2XF32T((*pD)[i + 1L], (*pD)[i + 1L], p, ~flagsrnz);	// default, pD[i + 1] - p if flagsrnz true
						(*pE)[m] = BBE_MOVN_2XF32T((xb_vecN_2xf32)0.0F, (*pE)[m], ~flagsrnz);	// true, false, flagsrnz
						ucharA = *(uint8_t *) &flagsrnz;
						if (ucharA == 0U)
						{
							break;
						}

						BBE_DIVN_2XF32T(s, f, r, flagsrnz);	// s = f / r if flagsrnz true otherwise s
						BBE_DIVN_2XF32T(c, g, r, flagsrnz);	// c = g / r if flagsrnz true otherwise c
						g = BBE_MOVN_2XF32T((*pD)[i + 1L] - p, g, flagsrnz);	// true, false, flagsrnz
						r = BBE_MOVN_2XF32T((((*pD)[i] - g) * s) + (((xb_vecN_2xf32)2.0F * c) * b), r, flagsrnz);
						p = BBE_MOVN_2XF32T(s * r, p, flagsrnz);
						(*pD)[i + 1L] = BBE_MOVN_2XF32T(g + p, (*pD)[i + 1L], flagsrnz);
						g = BBE_MOVN_2XF32T((c * r) - b, g, flagsrnz);

						// update the eigenvectors matrix X[size][size] if requested
						// loop k over all rows of eigenvector columns i, i+1 applying planar rotation
						for (k = 0L; k < size; k++)
						{
							f = (*pX)[k][i + 1L];
							(*pX)[k][i + 1L] = BBE_MOVN_2XF32T((s * (*pX)[k][i]) + (c * f), (*pX)[k][i + 1L], flagsrnz);	// true, false, flagsrnz
							(*pX)[k][i] = BBE_MOVN_2XF32T((c * (*pX)[k][i]) - (s * f), (*pX)[k][i], flagsrnz);	// true, false, flagsrnz
						}

					} // end of break predication block

				}	// end of i loop applying planar rotations

				// update diagonal elements pD[] and off-diagonal elements e[]
				// if (!((r eq 0.0F) && (i g.e than lx)))
				{
					flags0 = (vboolN_2)((r == (xb_vecN_2xf32)0.0F) & ((xb_vecN_2xf32)i >= (xb_vecN_2xf32)lx));
					(*pD)[lx] = BBE_MOVN_2XF32T((*pD)[lx] - p, (*pD)[lx], ~flags0);	// true, false, flags
					(*pE)[lx] = BBE_MOVN_2XF32T(g, (*pE)[lx], ~flags0);	// true, false, flags
					(*pE)[m] = BBE_MOVN_2XF32T((xb_vecN_2xf32)0.0F, (*pE)[m], ~flags0);	// true, false, flags
				}

			}	// end of test if (m != lx)

		} while (m != lx);	// end of infinite do-while loop calculating eigenvalue pD[lx]

	}	// end of loop lx over all eigenvalues pD[lx] from lx=0 to lx=size-1

	return;
}

void  Rsdk_LA_eigValTriDgSy_Mof32p8Mof32p8Mif32p8(
                                            xb_vecN_2xf32 * __restrict pOutputD,
                                                         xb_vecN_2xf32 * pInput,
                                                             int32_t iterations,
                                                                   int32_t size)
{
	xb_vecN_2xf32 (*pA)[size][size] = (xb_vecN_2xf32 (*)[size][size]) pInput;
	xb_vecN_2xf32 e[size]; // scratch
	xb_vecN_2xf32 (*pD)[size] = (xb_vecN_2xf32 (*)[size]) pOutputD;
	xb_vecN_2xf32 (*pE)[size] = (xb_vecN_2xf32 (*)[size]) e;

	xb_vecN_2xf32 b, f, g, p, r;	// scratch
	xb_vecN_2xf32 dpd;				// sum of diagonal elements pD[m] and pD[m+1]
	xb_vecN_2xf32 s, c;				// sine and cosine of planar rotation
	xb_vecN_2xf32 bbe_ones = (xb_vecN_2xf32)1;
	vboolN_2 flags0, flagsrnz;		// predication flags
	int32_t i, lx, m;				// loop counters
	uint8_t ucharA;			// cast of predication flags

	f =  (xb_vecN_2xf32)0.0F;
	b =  (xb_vecN_2xf32)0.0F;

	// copy diagonal and off-diagonal elements of pA[size][size] to pD[size] and e[size]
	(*pD)[0] = (*pA)[0][0];
	(*pE)[0] = (xb_vecN_2xf32)0.0F;
	for (i = 1L; i < size; i++)
	{
		(*pD)[i] = (*pA)[i][i];
		(*pE)[i] = (*pA)[i-1L][i];
	}

	// shuffle the elements of e[1...size-1] down into e[0 .. size - 2] with e[size - 1] set to zero
	for (i = 1L; i < size; i++)
	{
		(*pE)[i - 1L] = (*pE)[i];
	}
	(*pE)[size - 1L] = (xb_vecN_2xf32)0.0F;

	// loop lx over all eigenvalues pD[lx]
	for (lx = 0L; lx < size; lx++)
	{
		// start of do-while (m != lx) performing QL iteration up to maximum iterations iterations
		do
		{
			// set m to the first off-diagonal element e[m] (where 1 <= m <= size - 2) with
			// numerically zero value for all batch instances when flags0 = 00000000b = FALSE.
			// default is m = size - 2 when loop exits normally when at least one instance has not converged.
			for (m = lx; m < (size - 1L); m++)
			{
				dpd = BBE_ABSN_2XF32((*pD)[m]) + BBE_ABSN_2XF32((*pD)[m + 1L]);
				flags0 = (vboolN_2)(dpd != (dpd + BBE_ABSN_2XF32((*pE)[m])));
				ucharA = *(uint8_t *) &flags0;
				if (!ucharA)
				{
					break;
				}
			}

			// if m == lx then e[lx] is zero for all instances so skip any further processing
			if (m != lx)
			{
				// return if the maximum number of iterations has been exceeded
				if (iterations == 0L)
				{
					return;
				}
				(iterations)--;

				// calculate shift checking for e[lx]=0.0F for one or more instances
				g = BBE_DIVN_2XF32((*pD)[lx + 1L] - (*pD)[lx], (xb_vecN_2xf32)2.0F * (*pD)[lx]);
				Rsdk_LA_hypoth_Vo1f32p8Vi1f32p8Vi1f32p8(&r, &bbe_ones, &g);

				flags0 = (vboolN_2)(g < (xb_vecN_2xf32)0.0F);
				BBE_NEGN_2XF32T(r, r, flags0);

				g = (*pD)[m] - (*pD)[lx] + BBE_DIVN_2XF32((*pE)[lx], g + r);

				// set r and g to zero since e[lx] may be zero for one or more instances
				flags0 = (vboolN_2)((BBE_ABSN_2XF32(g) == (xb_vecN_2xf32)INFINITY_SP) | (g != g));
				g = BBE_MOVN_2XF32T((xb_vecN_2xf32)0.0F, g, flags0);	// true, false, flags

				flags0 = (vboolN_2)((BBE_ABSN_2XF32(r) == (xb_vecN_2xf32)INFINITY_SP) | (r != r));
				r = BBE_MOVN_2XF32T((xb_vecN_2xf32)0.0F, r, flags0);	// true, false, flags

				s = (xb_vecN_2xf32)1.0F;
				c = (xb_vecN_2xf32)1.0F;
				p = (xb_vecN_2xf32)0.0F;

				// loop i applying planar rotations
				// note: the scalar code breaks from this i loop when r == 0.0F so use flagsrnz to track r != 0.0F

				// set flagsrnz = 11111111b since no break has occurred from any instance
				flagsrnz = (vboolN_2)((xb_vecN_2xf32)0.0F == (xb_vecN_2xf32)0.0F);

				for (i = (m - 1L); i >= lx; i--)
				{
					// start of break predication block
					{
						f = BBE_MOVN_2XF32T(s * (*pE)[i], f, flagsrnz);	// true, false, flagsrnz
						b = BBE_MOVN_2XF32T(c * (*pE)[i], b, flagsrnz);	// true, false, flagsrnz
						Rsdk_LA_hypoth_Vo1f32p8Vi1f32p8Vi1f32p8(&r, &f, &g);
						(*pE)[i + 1L] = BBE_MOVN_2XF32T(r, (*pE)[i + 1L], flagsrnz);	// true, false, flagsrnz

						// update flagsrnz taking bits low if r == 0.0F
						flagsrnz &= (vboolN_2)(r != (xb_vecN_2xf32)0.0F);

						// if (r eq 0.0F) {pD[i + 1] -= p; e[m] eq 0.0F; break;}
						// in addition to predication, exit loop if all instances have r == 0.0F
						BBE_SUBN_2XF32T((*pD)[i + 1L], (*pD)[i + 1L], p, ~flagsrnz);	// default, pD[i + 1] - p if flagsrnz true
						(*pE)[m] = BBE_MOVN_2XF32T((xb_vecN_2xf32)0.0F, (*pE)[m], ~flagsrnz);	// true, false, flagsrnz
						ucharA = *(uint8_t *) &flagsrnz;
						if (ucharA == 0U)
						{
							break;
						}

						BBE_DIVN_2XF32T(s, f, r, flagsrnz);	// s = f / r if flagsrnz true otherwise s
						BBE_DIVN_2XF32T(c, g, r, flagsrnz);	// c = g / r if flagsrnz true otherwise c
						g = BBE_MOVN_2XF32T((*pD)[i + 1L] - p, g, flagsrnz);	// true, false, flagsrnz
						r = BBE_MOVN_2XF32T((((*pD)[i] - g) * s) + (((xb_vecN_2xf32)2.0F * c) * b), r, flagsrnz);
						p = BBE_MOVN_2XF32T(s * r, p, flagsrnz);
						(*pD)[i + 1L] = BBE_MOVN_2XF32T(g + p, (*pD)[i + 1L], flagsrnz);
						g = BBE_MOVN_2XF32T((c * r) - b, g, flagsrnz);

					} // end of break predication block

				}	// end of i loop applying planar rotations

				// update diagonal elements pD[] and off-diagonal elements e[]
				// if (not((r eq 0.0F) and (i g.e.than lx)))
				{
					flags0 = (vboolN_2)((r == (xb_vecN_2xf32)0.0F) & ((xb_vecN_2xf32)i >= (xb_vecN_2xf32)lx));
					(*pD)[lx] = BBE_MOVN_2XF32T((*pD)[lx] - p, (*pD)[lx], ~flags0);	// true, false, flags
					(*pE)[lx] = BBE_MOVN_2XF32T(g, (*pE)[lx], ~flags0);	// true, false, flags
					(*pE)[m] = BBE_MOVN_2XF32T((xb_vecN_2xf32)0.0F, (*pE)[m], ~flags0);	// true, false, flags
				}

			}	// end of test if (m != lx)

		} while (m != lx);	// end of infinite do-while loop calculating eigenvalue pD[lx]

	}	// end of loop lx over all eigenvalues pD[lx] from lx=0 to lx=size-1

	return;
}

void Rsdk_LA_eigTriDgSy_Mof32p8Mof32p8Mif32p8(
		                                    xb_vecN_2xf32 * __restrict pOutputD,
		                                    xb_vecN_2xf32 * __restrict pOutputV,
		                                               xb_vecN_2xf32 * pInput,
                                                             int32_t iterations,
                                                             int32_t size)
{
    // do the identity matrix initialization of eigenvector  matrix
    Rsdk_LA_eigTriDgSyHelper_Mof32p8Mof32p8Mif32p8(pOutputD,
                                                   pOutputV,
                                                   pInput,
                                                   iterations,
                                                   size,
                                                   (xtbool)1);
}

void Rsdk_LA_eigTriDgQHousSy_Mof32p8Mof32p8Mif32p8(
                                            xb_vecN_2xf32 * __restrict pOutputD,
                                            xb_vecN_2xf32 * __restrict pOutputV,
                                                         xb_vecN_2xf32 * pInput,
                                                             int32_t iterations,
                                                               int32_t size)
{
    // do not do the identity matrix initialization of the eigenvector  matrix
    Rsdk_LA_eigTriDgSyHelper_Mof32p8Mof32p8Mif32p8(pOutputD,
                                                   pOutputV,
                                                   pInput,
                                                   iterations,
                                                   size,
                                                   (xtbool)0);
}


#ifdef __cplusplus
}
#endif

/*******************************************************************************
* EOF
******************************************************************************/
