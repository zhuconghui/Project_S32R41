/**************************************************************************************************
 * Copyright 2022 NXP
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
* @file           rsdk_dsp_lal_sp_smooth.c
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
// Hard limit to output size. LAX memory size will not allow for more than 30 anyway for eigensolvers
#define MAX_SP_SM_OUT_SZ 35

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
void Rsdk_ML_spatialSm_Mof32cp8Mif32cp8(xb_vecN_2xcf32 * pOutput,
                                        xb_vecN_2xcf32 const * pInput,
                                        uint32_t rowsIn, uint32_t colsIn,
                                        uint32_t rowsWin, uint32_t colsWin)
{
  xb_vecN_2xcf32 const * pElement_start[MAX_SP_SM_OUT_SZ];
  xb_vecN_2xcf32 const * pOp_start = pInput;
  xb_vecN_2xcf32 const * pOp1 = pInput;
  xb_vecN_2xcf32 const * pOp1_start = pInput;
  xb_vecN_2xcf32 const * pOp2 = pInput;
  xb_vecN_2xcf32 const * pOp2_start = pInput;
  xb_vecN_2xcf32 * pOutUpp  = pOutput;
  xb_vecN_2xcf32 * pOutLow  = pOutput;
  xb_vecN_2xcf32 * pOutDiag = pOutput;
  xb_vecN_2xcf32 acc;
  int32_t p;
  int32_t q;
  int32_t r;
  int32_t s;

  int32_t outSz = (int32_t)rowsWin * (int32_t)colsWin;
  int32_t iterR = (int32_t)rowsIn - (int32_t)rowsWin + 1;
  int32_t iterC = (int32_t)colsIn - (int32_t)colsWin + 1;

// Initialize rowsWin*colsWin starting positions of iterR*iterC vectors
  s = 0L;
  for (p = 0L; p < (int32_t)colsWin; p++)
  {
      pOp1_start = &pInput[p];
      for (q = 0L; q < (int32_t)rowsWin; q++)
      {
          pElement_start[s] = pOp1_start;
          s++;
          pOp1_start += colsIn;
      }
  }

//  Process the diagonal elements
//pOutDiag <- &pOutput[0]
  for (p = 0L; p < outSz; p++)
  {
    pOp1_start = pElement_start[p];
    acc = BBE_ZERON_2XCF32();

    for (r = 0L; r < iterR; r++)
    {
      pOp1 = pOp1_start;
      pOp1_start = &pOp1_start[colsIn];

      for (s = 0L; s < iterC; s++)
      {
        acc += BBE_CMPLXN_2XF32((xb_vecN_2xf32)0.0F, BBE_MAGN_2XCF32(*pOp1));
        pOp1++;
      }
    }
    *pOutDiag = acc;
    pOutDiag = &pOutDiag[outSz + 1];
  }

//  Process all off-diagonal elements:
//Compute the above diagonal elements
//Conjugate them for the below diagonal elements.
  pOutDiag = &pOutput[1];              //first off-diagonal element
  for (p = 0L; p < outSz; p++)
  {
    pOp_start = pElement_start[p];
    pOutUpp = pOutDiag;              //above diagonal
    pOutLow = &pOutDiag[outSz - 1];  //below diagonal
    pOutDiag = &pOutDiag[outSz + 1];

    for (q = p + 1; q < outSz; q++)
    {
      pOp1_start = pOp_start;
      pOp2_start = pElement_start[q];
      acc = BBE_ZERON_2XCF32();

      for (r = 0L; r < iterR; r++)
      {
        pOp1 = pOp1_start;
        pOp2 = pOp2_start;

        for (s = 0L; s < iterC; s++)
        {
          acc += *pOp1 * BBE_CONJN_2XCF32(*pOp2);
          pOp1++;
          pOp2++;
        }
        //move pointers  to next row
        pOp1_start = &pOp1_start[colsIn];
        pOp2_start = &pOp2_start[colsIn];
      }
      //above diagonal
      *pOutUpp = acc;
      pOutUpp++;
      //below diagonal
      *pOutLow = BBE_CONJN_2XCF32(acc);
      pOutLow = &pOutLow[outSz];
    }
  }
}

#ifdef __cplusplus
}
#endif

/*******************************************************************************
 * EOF
 ******************************************************************************/
