/*
 * Copyright 2023-2024 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */


#include "dsp_algo_24b_fixed_functions_s32r41.h"






#include <xtensa/tie/xt_FP.h>
#include <xtensa/tie/xt_bben.h>
#include <xtensa/tie/xt_misc.h>
#include <xtensa/tie/radar24.h>

#ifdef __cplusplus
extern "C"{
#endif

#define HISTSTEP(x, hist_val, v_in, vt_val) { bbx_vecNx24 v_currVal = BBX_REPNX24(v_in, (x)); BBE_MULANX16T(hist_val, 1, 1, BBX_LTENX24((vt_val), (v_currVal)));}
#define HISTSTEP2(x, hist_val, v_currVal, vt_val) { BBE_MULANX16T(hist_val, 1, 1, BBX_LTENX24((vt_val), (v_currVal)));}
#define HISTSTEP3(x, hist_val, v_currVal, vt_val) { BBE_MULANX16T(hist_val, 1, 1, BBX_LTNX24((vt_val), (v_currVal)));}

static const int16_t shuffleVector[16] = {0,1,2,3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 ,15, 15};

void Rsdk_Hist(bbx_vecNx24 * pOut,
		       bbx_vecNx24 * pIn,
		       bbx_vecNx24 * pEdges,
				    uint16_t size,
				    uint16_t sizeEdges)
{
	xb_vecNx40 hist40 = 0;
	xb_vecNx40 hist40_cpy = 0;
	bbx_vecNx24 hist = 0;
	bbx_vecNx24 hist_cpy = 0;
	bbx_vecNx24 v_t;
	bbx_vecNx24 v_tle;
	bbx_vecNx24 v_in;
	bbx_vecNx24 v_currVal;
	xb_vecNx16 *pShuffleVector = (xb_vecNx16 *)(uintptr_t)&shuffleVector;
	vsaN selectShuffle = xb_vecNx16_rtor_vsaN(*pShuffleVector);
	int32_t id_edge = 0;
	int32_t idx;

	v_t = (bbx_vecNx24)(((int32_t *)pEdges)[sizeEdges * 16 - 1]);
	v_tle = ((bbx_vecNx24*)pEdges)[sizeEdges - 1];
	// compute how many values are greater than and greater than or equal with the last batch of edges
	for (id_edge = 0; id_edge < (int32_t)size; id_edge++)
	{
		v_in = pIn[id_edge];
		v_currVal = BBX_REPNX24(v_in, 0);
		HISTSTEP3(0, hist40_cpy, v_currVal, v_t);
		HISTSTEP2(0, hist40, v_currVal, v_tle);
		v_currVal = BBX_REPNX24(v_in, 1);
		HISTSTEP3(1, hist40_cpy, v_currVal, v_t);
		HISTSTEP2(1, hist40, v_currVal, v_tle);
		v_currVal = BBX_REPNX24(v_in, 2);
		HISTSTEP3(2, hist40_cpy, v_currVal, v_t);
		HISTSTEP2(2, hist40, v_currVal, v_tle);
		v_currVal = BBX_REPNX24(v_in, 3);
		HISTSTEP3(3, hist40_cpy, v_currVal, v_t);
		HISTSTEP2(3, hist40, v_currVal, v_tle);
		v_currVal = BBX_REPNX24(v_in, 4);
		HISTSTEP3(4, hist40_cpy, v_currVal, v_t);
		HISTSTEP2(4, hist40, v_currVal, v_tle);
		v_currVal = BBX_REPNX24(v_in, 5);
		HISTSTEP3(5, hist40_cpy, v_currVal, v_t);
		HISTSTEP2(5, hist40, v_currVal, v_tle);
		v_currVal = BBX_REPNX24(v_in, 6);
		HISTSTEP3(6, hist40_cpy, v_currVal, v_t);
		HISTSTEP2(6, hist40, v_currVal, v_tle);
		v_currVal = BBX_REPNX24(v_in, 7);
		HISTSTEP3(7, hist40_cpy, v_currVal, v_t);
		HISTSTEP2(7, hist40, v_currVal, v_tle);
		v_currVal = BBX_REPNX24(v_in, 8);
		HISTSTEP3(8, hist40_cpy, v_currVal, v_t);
		HISTSTEP2(8, hist40, v_currVal, v_tle);
		v_currVal = BBX_REPNX24(v_in, 9);
		HISTSTEP3(9, hist40_cpy, v_currVal, v_t);
		HISTSTEP2(9, hist40, v_currVal, v_tle);
		v_currVal = BBX_REPNX24(v_in, 10);
		HISTSTEP3(10, hist40_cpy, v_currVal, v_t);
		HISTSTEP2(10, hist40, v_currVal, v_tle);
		v_currVal = BBX_REPNX24(v_in, 11);
		HISTSTEP3(11, hist40_cpy, v_currVal, v_t);
		HISTSTEP2(11, hist40, v_currVal, v_tle);
		v_currVal = BBX_REPNX24(v_in, 12);
		HISTSTEP3(12, hist40_cpy, v_currVal, v_t);
		HISTSTEP2(12, hist40, v_currVal, v_tle);
		v_currVal = BBX_REPNX24(v_in, 13);
		HISTSTEP3(13, hist40_cpy, v_currVal, v_t);
		HISTSTEP2(13, hist40, v_currVal, v_tle);
		v_currVal = BBX_REPNX24(v_in, 14);
		HISTSTEP3(14, hist40_cpy, v_currVal, v_t);
		HISTSTEP2(14, hist40, v_currVal, v_tle);
		v_currVal = BBX_REPNX24(v_in, 15);
		HISTSTEP3(15, hist40_cpy, v_currVal, v_t);
		HISTSTEP2(15, hist40, v_currVal, v_tle);

	}
	hist = BBE_PACKLNX40(hist40);
	hist_cpy = BBE_PACKLNX40(hist40_cpy);
	// shift right with a position and add update second last value with the greater than value of the last edge value
	hist_cpy = BBX_SHFNX24(BBE_SELNX16I(hist_cpy, hist , BBE_SELI_ROTATE_RIGHT_1), selectShuffle);
    pOut[sizeEdges - 1] = BBE_SUBNX16(hist,  hist_cpy);
	hist_cpy = hist;
	id_edge = (int32_t)sizeEdges - 2;
	// compute how many values are greater than or equal with the rest of the edges
	while (id_edge >= 0)
	{
		hist = 0;
		hist40 = 0;
		v_t = ((bbx_vecNx24*)pEdges)[id_edge];

		for (idx = 0; idx < (int32_t)size; idx++)
		{
			v_in = pIn[idx];

			HISTSTEP(0, hist40, v_in, v_t);
			HISTSTEP(1, hist40, v_in, v_t);
			HISTSTEP(2, hist40, v_in, v_t);
			HISTSTEP(3, hist40, v_in, v_t);
			HISTSTEP(4, hist40, v_in, v_t);
			HISTSTEP(5, hist40, v_in, v_t);
			HISTSTEP(6, hist40, v_in, v_t);
			HISTSTEP(7, hist40, v_in, v_t);
			HISTSTEP(8, hist40, v_in, v_t);
			HISTSTEP(9, hist40, v_in, v_t);
			HISTSTEP(10, hist40, v_in, v_t);
			HISTSTEP(11, hist40, v_in, v_t);
			HISTSTEP(12, hist40, v_in, v_t);
			HISTSTEP(13, hist40, v_in, v_t);
			HISTSTEP(14, hist40, v_in, v_t);
			HISTSTEP(15, hist40, v_in, v_t);

		}
		hist = BBE_PACKLNX40(hist40);
		// shift right with a position
		hist_cpy = BBE_SELNX16I(hist_cpy, hist , BBE_SELI_ROTATE_RIGHT_1);
		pOut[id_edge] = BBE_SUBNX16(hist,  hist_cpy);
		hist_cpy = hist;
		id_edge--;
	}
}

#ifdef __cplusplus
}
#endif

/*******************************************************************************
* EOF
******************************************************************************/
