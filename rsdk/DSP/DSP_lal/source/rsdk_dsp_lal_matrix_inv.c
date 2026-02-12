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
* @file           rsdk_dsp_lal_matrix_inv.c
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

void Rsdk_LA_invHousQRNs_Mof32p8Mif32p8(xb_vecN_2xf32 * pOutput,
                                        xb_vecN_2xf32 * pInput,
                                        xb_vecN_2xf32 * pBuffer1,
                                        xb_vecN_2xf32 * pBuffer2,
                                               uint32_t size)
{
    xb_vecN_2xf32 *Q = pBuffer1;
    xb_vecN_2xf32 *R = pBuffer2;
    /* re-use buffer2 for R inverse */
    xb_vecN_2xf32 *Rinv = pBuffer2;
    /* QR decompositon */
    Rsdk_LA_decQRHous_Mof32p8Mof32p8Mif32p8(R, Q, pOutput, pInput, size, size);
    /* cleaning the pOutput for multiplication */
    Rsdk_EF_fillZeros_Mof32p8(pOutput, size, size);
    /* inverse of R(which is an upper triangular matrix) */
    Rsdk_LA_invUNs_Mof32p8Mif32p8(Rinv, R, size);
    /* multiplication between inverse of R and inverse of Q(which is its transpose) */
    Rsdk_LA_mulSecondT_Mof32p8Mif32p8Mif32p8(pOutput, Rinv, Q, size, size, size);
};


void Rsdk_LA_invHousQRNs_Mof32cp8Mif32cp8(xb_vecN_2xcf32 * pOutput,
                                          xb_vecN_2xcf32 * pInput,
                                          xb_vecN_2xcf32 * pBuffer1,
                                          xb_vecN_2xcf32 * pBuffer2,
                                                  uint32_t size)
{
    xb_vecN_2xcf32 *Q = pBuffer1;
    xb_vecN_2xcf32 *R = pBuffer2;
    /* re-use buffer2 for R inverse */
    xb_vecN_2xcf32 *Rinv = pBuffer2;
    /* QR decompositon */
    Rsdk_LA_decQRHous_Mof32cp8Mof32cp8Mif32cp8(R, Q, pOutput, pInput, size, size);
    /* cleaning the pOutput for multiplication */
    Rsdk_EF_fillZeros_Mof32cp8(pOutput, size, size);
    /* inverse of R(which is an upper triangular matrix) */
    Rsdk_LA_invUNs_Mof32cp8Mif32cp8(Rinv, R, size);
    /* multiplication between inverse of R and inverse of Q (which is the complex conjugate of its transpose) */
    Rsdk_LA_mulSecondH_Mof32cp8Mif32cp8Mif32cp8(pOutput, Rinv, Q, size, size, size);
};


void Rsdk_LA_invGausCPNs_Mof32p8Miof32p8(xb_vecN_2xf32 * restrict pOutput,
                                         xb_vecN_2xf32 * pInput,
                                                uint32_t size)
{
    xb_vecN_2xf32 * restrict pout = pOutput;
    xb_vecN_2xf32 * pin           = pInput;
    xb_vecN_2xf32 pivot, pivot_line, pivot_abs, prev_pivot_abs, pivot_inv, ctmp1, row_val_n, column_val, mat_val_o;
    vboolN_2 detect_max;
    vboolN_2 *detect_line;
    xb_vecN_2xf32* pivot_line_ptr = &pivot_line;
    xtfloat  *pivot_line_parser;
    uint32_t i, j, k, elem;

    /* load identity matrix in pOutput matrix */
    Rsdk_EF_identity_Mof32p8(pout, size);
    pout = pOutput;
    for (i = 0UL; i < (size - 1UL); i++)
    {
        /* find pivot with maximum absolute value */
        pivot      = pin[(i*size) + i];
        pivot_abs  = BBE_ABSN_2XF32(pivot);
        pivot_line = (xb_vecN_2xf32) i;
        for (j = i + 1UL; j < size; j++)
        {
            prev_pivot_abs = pivot_abs;
            pivot_abs      = BBE_MAXN_2XF32(pivot_abs, BBE_ABSN_2XF32(pin[(j * size) + i]));
            detect_max     = (vboolN_2)( prev_pivot_abs == pivot_abs );
            pivot_line     = BBE_MOVN_2XF32T(pivot_line, (xb_vecN_2xf32) j, detect_max);
            pivot          = BBE_MOVN_2XF32T(pivot,pin[(j * size) + i] , detect_max);
        }
        pivot_line_parser = (xtfloat *) pivot_line_ptr;
        /* swap rows if necessary */
        for (j = 0UL; j < ((uint32_t)XCHAL_BBEN_SIMD_WIDTH / 2UL); j++)
        {
            if (((uint32_t)(pivot_line_parser[j])) != i)
            {
                elem        = (1UL << j);
                detect_line = (vboolN_2 *)(&elem);
                for (k = 0UL; k < i; k++)
                {
                    /* inverse matrix row swapping */
                    ctmp1                                             = pout[(i * size) + k];
                    pout[(i * size) + k]                              = BBE_MOVN_2XF32T(pout[(i * size) + k], pout[((uint32_t)pivot_line_parser[j] * size) + k] , BBE_NOTBN_2(*detect_line));
                    pout[((uint32_t)pivot_line_parser[j] * size) + k] = BBE_MOVN_2XF32T(pout[((uint32_t)pivot_line_parser[j] * size) + k], ctmp1 , BBE_NOTBN_2(*detect_line));
                }
                for (k = i; k < size; k++)
                {
                    /* input matrix rows swapping */
                    ctmp1                                             = pin[(i * size) + k];
                    pin[(i * size) + k]                               = BBE_MOVN_2XF32T(pin[(i * size) + k], pin[((uint32_t)pivot_line_parser[j] * size) + k] , BBE_NOTBN_2(*detect_line));
                    pin[((uint32_t)pivot_line_parser[j] * size) + k]  = BBE_MOVN_2XF32T(pin[((uint32_t)pivot_line_parser[j] * size) + k], ctmp1 , BBE_NOTBN_2(*detect_line));
                    /* inverse matrix row swapping */
                    ctmp1                                             = pout[(i * size) + k];
                    pout[(i * size) + k]                              = BBE_MOVN_2XF32T(pout[(i * size) + k], pout[((uint32_t)pivot_line_parser[j] * size) + k] , BBE_NOTBN_2(*detect_line));
                    pout[((uint32_t)pivot_line_parser[j] * size) + k] = BBE_MOVN_2XF32T(pout[((uint32_t)pivot_line_parser[j] * size) + k], ctmp1 , BBE_NOTBN_2(*detect_line));
                }
            }
        }
        /* pivot inverse */
        pivot_inv = BBE_RECIPN_2XF32(pivot);
        /* divide line by chosen pivot */
        for (j = (i + 1UL); j < size; j++)
        {
            ctmp1     = pin[(i * size) + j];
            row_val_n = ctmp1 * pivot_inv;
            /* A - column*curr_line */
            for (k = 0UL; k < size; k++)
            {
                mat_val_o           = pin[(k * size) + j];
                column_val          = pin[(k * size) + i];
                ctmp1               = mat_val_o - (column_val * row_val_n);
                pin[(k * size) + j] = ctmp1;
            }
            /* overwrite current value - saves testing in loop */
            pin[(i * size) + j] = row_val_n;
        }
        for (j = 0UL; j < size; j++)
        {
            ctmp1     = pout[(i * size) + j];
            row_val_n = ctmp1 * pivot_inv;
            /* A - column*curr_line */
            for (k = 0UL; k < size; k++)
            {
                mat_val_o            = pout[(k * size) + j];
                column_val           = pin[(k * size) + i];
                ctmp1                = mat_val_o - (column_val * row_val_n);
                pout[(k * size) + j] = ctmp1;
            }
            /* overwrite current value - saves testing in loop */
            pout[(i * size) + j] = row_val_n;
        }
    }
    /* last row */
    pivot     = pin[(size*size) - 1UL];
    pivot_inv = BBE_RECIPN_2XF32(pivot);
    for (j = 0UL; j < size; j++)
    {
        ctmp1     = pout[((size - 1UL) * size) + j];
        row_val_n = ctmp1 * pivot_inv;
        /* A - column*curr_line */
        for (k = 0UL; k < (size - 1UL); k++)
        {
            mat_val_o            = pout[(k * size) + j];
            column_val           = pin[(k * size) + (size - 1UL)];
            ctmp1                = mat_val_o - (column_val * row_val_n);
            pout[(k * size) + j] = ctmp1;
        }
        pout[((size - 1UL) * size) + j] = row_val_n;
    }

}

void Rsdk_LA_invNsGaus_Mof32p8Miof32p8(xb_vecN_2xf32 * restrict pOutput,
                                       xb_vecN_2xf32 * pInput,
                                              uint32_t size)
{
    xb_vecN_2xf32 * restrict pout = pOutput;
    xb_vecN_2xf32 * pin           = pInput;
    xb_vecN_2xf32 pivot, pivot_inv, ctmp1, row_val_n, column_val, mat_val_o;
    uint32_t i, j, k;

    /* load identity matrix in pOutput matrix */
    Rsdk_EF_identity_Mof32p8(pout, size);
    pout = pOutput;
    for (i = 0UL; i < (size - 1UL); i++)
    {
        pivot      = pin[(i*size) + i];
        pivot_inv  = BBE_RECIPN_2XF32(pivot);
         /* divide line by chosen pivot */
        for (j = (i + 1UL); j < size; j++)
        {
            ctmp1     = pin[(i * size) + j];
            row_val_n = ctmp1 * pivot_inv;
            /* A - column*curr_line */
            for (k = 0UL; k < size; k++)
            {
                mat_val_o           = pin[(k * size) + j];
                column_val          = pin[(k * size) + i];
                ctmp1               = mat_val_o - (column_val * row_val_n);
                pin[(k * size) + j] = ctmp1;
            }
            /* overwrite current value - saves testing in loop */
            pin[(i * size) + j] = row_val_n;
        }
        for (j = 0UL; j < size; j++)
        {
            ctmp1     = pout[(i * size) + j];
            row_val_n = ctmp1 * pivot_inv;
            /* A - column*curr_line */
            for (k = 0UL; k < size; k++)
            {
            mat_val_o            = pout[(k * size) + j];
            column_val           = pin[(k * size) + i];
            ctmp1                = mat_val_o - (column_val * row_val_n);
            pout[(k * size) + j] = ctmp1;
            }
            /* overwrite current value - saves testing in loop */
            pout[(i * size) + j] = row_val_n;
        }
    }

    /* last row */
    pivot     = pin[(size*size) - 1UL];
    pivot_inv = BBE_RECIPN_2XF32(pivot);
    for (j = 0UL; j < size; j++)
    {
        ctmp1     = pout[((size - 1UL) * size) + j];
        row_val_n = ctmp1 * pivot_inv;
        /* A - column*curr_line */
        for (k = 0UL; k < (size - 1UL); k++)
        {
            mat_val_o            = pout[(k * size) + j];
            column_val           = pin[(k * size) + (size - 1UL)];
            ctmp1                = mat_val_o - (column_val * row_val_n);
            pout[(k * size) + j] = ctmp1;
        }
        pout[((size - 1UL) * size) + j] = row_val_n;
    }

}

void Rsdk_LA_invGausCPNs_Mof32cp8Miof32cp8(xb_vecN_2xcf32 * restrict pOutput,
                                           xb_vecN_2xcf32 * pInput,
                                                   uint32_t size)
{
    xb_vecN_2xcf32 * restrict pout = pOutput;
    xb_vecN_2xcf32 * pin           = pInput;
    xb_vecN_2xcf32 pivot, pivot_inv, ctmp1, row_val_n, column_val, mat_val_o;
    xb_vecN_2xf32 pivot_line, pivot_magn, prev_pivot_magn;
    xb_vecN_2xf32 * pivot_line_ptr = &pivot_line;
    vboolN_2 detect_max;
    vboolN_2 *detect_line;
    xtfloat  *pivot_line_parser;
    uint32_t i, j, k, elem;

    /* load identity matrix in pOutput matrix */
    Rsdk_EF_identity_Mof32cp8(pout, size);
    pout = pOutput;
    for (i = 0UL; i < (size - 1UL); i++)
    {
        /* find pivot with maximum magnitude */
        pivot      = pin[(i*size) + i];
        pivot_magn = BBE_MAGN_2XCF32(pivot);
        pivot_line = (xb_vecN_2xf32) i;
        for (j = (i + 1UL); j < size; j++)
        {
            prev_pivot_magn = pivot_magn;
            pivot_magn      = BBE_MAXN_2XF32(pivot_magn, BBE_MAGN_2XCF32(pin[(j * size) + i]));
            detect_max      = (vboolN_2)( prev_pivot_magn == pivot_magn );
            pivot_line      = BBE_MOVN_2XF32T(pivot_line, (xb_vecN_2xf32) j, detect_max);
            pivot           = BBE_MOVN_2XCF32T(pivot,pin[(j * size) + i], detect_max);
        }
        pivot_line_parser = (xtfloat *) pivot_line_ptr;
        /* swap rows if necessary */
        for (j = 0UL; j < ((uint32_t)XCHAL_BBEN_SIMD_WIDTH / 2UL); j++)
        {
            if (((uint32_t)(pivot_line_parser[j])) != i)
            {
                elem = (1UL << j);
                detect_line = (vboolN_2 *)(&elem);

                for (k = 0UL; k < i; k++)
                {
                    /* inverse matrix row swapping */
                    ctmp1                                             = pout[(i * size) + k];
                    pout[(i * size) + k]                              = BBE_MOVN_2XCF32T(pout[(i * size) + k], pout[((uint32_t)pivot_line_parser[j] * size) + k], BBE_NOTBN_2(*detect_line));
                    pout[((uint32_t)pivot_line_parser[j] * size) + k] = BBE_MOVN_2XCF32T(pout[((uint32_t)pivot_line_parser[j] * size) + k], ctmp1, BBE_NOTBN_2(*detect_line));
                }
                for (k = i; k < size; k++)
                {
                    /* input matrix rows swapping */
                    ctmp1                                             = pin[(i * size) + k];
                    pin[(i * size) + k]                               = BBE_MOVN_2XCF32T(pin[(i * size) + k], pin[((uint32_t)pivot_line_parser[j] * size) + k], BBE_NOTBN_2(*detect_line));
                    pin[((uint32_t)pivot_line_parser[j] * size) + k]  = BBE_MOVN_2XCF32T(pin[((uint32_t)pivot_line_parser[j] * size) + k], ctmp1, BBE_NOTBN_2(*detect_line));
                    /* inverse matrix row swapping */
                    ctmp1                                             = pout[(i * size) + k];
                    pout[(i * size) + k]                              = BBE_MOVN_2XCF32T(pout[(i * size) + k], pout[((uint32_t)pivot_line_parser[j] * size) + k], BBE_NOTBN_2(*detect_line));
                    pout[((uint32_t)pivot_line_parser[j] * size) + k] = BBE_MOVN_2XCF32T(pout[((uint32_t)pivot_line_parser[j] * size) + k], ctmp1, BBE_NOTBN_2(*detect_line));
                }
            }
        }
        /* pivot inverse */
        pivot_inv = BBE_RECIPN_2XCF32(pivot);
        /* divide line by chosen pivot */
        for (j = i + 1UL; j < size; j++)
        {
            ctmp1     = pin[(i * size) + j];
            row_val_n = ctmp1 * pivot_inv;
            /* A - column*curr_line */
            for (k = 0UL; k < size; k++)
            {
                mat_val_o           = pin[(k * size) + j];
                column_val          = pin[(k * size) + i];
                ctmp1               = mat_val_o - (column_val * row_val_n);
                pin[(k * size) + j] = ctmp1;
            }
            /* overwrite current value - saves testing in loop */
            pin[(i * size) + j] = row_val_n;
        }
        for (j = 0UL; j < size; j++)
        {
            ctmp1     = pout[(i * size) + j];
            row_val_n = ctmp1 * pivot_inv;
            /* A - column*curr_line */
            for (k = 0UL; k < size; k++)
            {
                mat_val_o            = pout[(k * size) + j];
                column_val           = pin[(k * size) + i];
                ctmp1                = mat_val_o - (column_val * row_val_n);
                pout[(k * size) + j] = ctmp1;
            }
            /* overwrite current value - saves testing in loop */
            pout[(i * size) + j] = row_val_n;
        }
    }
    /* last row */
    pivot     = pin[(size * size) - 1UL];
    pivot_inv = BBE_RECIPN_2XCF32(pivot);
    for (j = 0UL; j < size; j++)
    {
        ctmp1     = pout[((size - 1UL) * size) + j];
        row_val_n = ctmp1 * pivot_inv;
        /* A - column*curr_line */
        for (k = 0UL; k < (size - 1UL); k++)
        {
            mat_val_o            = pout[(k * size) + j];
            column_val           = pin[(k * size) + (size - 1UL)];
            ctmp1                = mat_val_o - (column_val * row_val_n);
            pout[(k * size) + j] = ctmp1;
        }
        pout[((size - 1UL) * size) + j] = row_val_n;
    }
}

void Rsdk_LA_invNsGaus_Mof32cp8Miof32cp8(xb_vecN_2xcf32 * restrict pOutput,
                                         xb_vecN_2xcf32 * pInput,
                                                 uint32_t size)
{
    xb_vecN_2xcf32 * restrict pout = pOutput;
    xb_vecN_2xcf32 * pin           = pInput;
    xb_vecN_2xcf32 pivot, pivot_inv, ctmp1, row_val_n, column_val, mat_val_o;
    uint32_t i, j, k;

    /* load identity matrix in pOutput matrix */
    Rsdk_EF_identity_Mof32cp8(pout, size);
    pout = pOutput;
    for (i = 0UL; i < (size - 1UL); i++)
    {
        pivot     = pin[(i*size) + i];
        /* pivot inverse */
        pivot_inv = BBE_RECIPN_2XCF32(pivot);
        /* divide line by chosen pivot */
        for (j = i + 1UL; j < size; j++)
        {
            ctmp1     = pin[(i * size) + j];
            row_val_n = ctmp1 * pivot_inv;
            /* A - column*curr_line */
            for (k = 0UL; k < size; k++)
            {
                mat_val_o           = pin[(k * size) + j];
                column_val          = pin[(k * size) + i];
                ctmp1               = mat_val_o - (column_val * row_val_n);
                pin[(k * size) + j] = ctmp1;
            }
            /* overwrite current value - saves testing in loop */
            pin[(i * size) + j] = row_val_n;
        }
        for (j = 0UL; j < size; j++)
        {
            ctmp1     = pout[(i * size) + j];
            row_val_n = ctmp1 * pivot_inv;
            /* A - column*curr_line */
            for (k = 0UL; k < size; k++)
            {
                mat_val_o            = pout[(k * size) + j];
                column_val           = pin[(k * size) + i];
                ctmp1                = mat_val_o - (column_val * row_val_n);
                pout[(k * size) + j] = ctmp1;
            }
            /* overwrite current value - saves testing in loop */
            pout[(i * size) + j] = row_val_n;
        }
    }
    /* last row */
    pivot     = pin[(size * size) - 1UL];
    pivot_inv = BBE_RECIPN_2XCF32(pivot);
    for (j = 0UL; j < size; j++)
    {
        ctmp1     = pout[((size - 1UL) * size) + j];
        row_val_n = ctmp1 * pivot_inv;
        /* A - column*curr_line */
        for (k = 0UL; k < (size - 1UL); k++)
        {
            mat_val_o            = pout[(k * size) + j];
            column_val           = pin[(k * size) + (size - 1UL)];
            ctmp1                = mat_val_o - (column_val * row_val_n);
            pout[(k * size) + j] = ctmp1;
        }
        pout[((size - 1UL) * size) + j] = row_val_n;
    }
}

#ifdef __cplusplus
}
#endif

/*******************************************************************************
* EOF
******************************************************************************/
