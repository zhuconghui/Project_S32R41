/*
 * Copyright 2020-2024 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

#include <xtensa/tie/xt_bben.h>
#include <xtensa/tie/xt_misc.h>
#include <xtensa/tie/radar24.h>

#include "rsdk_dsp_radar_bb_algos_s32r41.h"



#include "hw_defs.h"

#ifdef __cplusplus
extern "C" {
#endif


#define RSDK_OSCFAR_WIN_SZ (16u)
#define OPRAM_BANK_COLUMNS (512u)


#define BBX_LOAD16_RLU0(base, offset)  						BBX_LOB0NX16_I(base, offset)
#define BBX_LOAD16_RLU1(base, offset)  						BBX_LOB1NX16_I(base, offset)
#define BBX_STORE16_WLU0(vect, base, boolVect, offset)		BBX_SOB0NX16_I(vect, base, boolVect, offset)


xb_vecNx16U rsdkOsCfarInData[OPRAM_BANK_COLUMNS];
xb_vecNx16U rsdkOsCfarThData[OPRAM_BANK_COLUMNS];
xb_vecNx16U rsdkOsCfarThCompVec[OPRAM_BANK_COLUMNS];
xb_vecNx16U rsdkOsCfardetects[OPRAM_BANK_COLUMNS/BBE_SIMD_WIDTH];

void RsdkBbe32OsCfar(uintptr_t argList){

	rsdkBbe32OsCfarParams_t* cfarParams = ((rsdkBbe32OsCfarParams_t**)argList)[0];

	/* check restrictions */
    if ((uintptr_t)cfarParams->dopplerBins % BBE_SIMD_WIDTH != 0)
    {
    	SetDspError(RSDK_DSP_ALGO_WRONG_ALIGN);
    	return;
    }

    if (cfarParams->dopplerBins == 0)
    {
    	SetDspError(RSDK_DSP_ALGO_WRONG_PARAM);
    	return;
    }

	uint16_t chPerFr = cfarParams->dopplerBins;
	uint16_t numRB;

	numRB = (OPRAM_BANK_COLUMNS*BBE_SIMD_WIDTH)/chPerFr;


	uint16_t cRB;

	uint32_t i;
	int32_t junk;
	int8_t op_br0, op_br1, op_bw0; //vars used to do the bank switching for read/write into ORAM
	int breg;

	uint16_t cs;

	int32_t base = 8;

	xb_int16U *rsdkOsCfarThDataInt16 = (xb_int16U *)&rsdkOsCfarThData;
	xb_int16U *thCompare = (xb_int16U *)&rsdkOsCfarThCompVec;
	vboolN *detects = (vboolN *)&rsdkOsCfardetects;
	int tt = 0xffff;
	vboolN tmp16 = *(vboolN *) &tt;

	//read the input samples using RLU0 and the thresholds using RLU1

	op_br0 = 0; op_br1 = 2;  op_bw0 = 1;


	breg  = op_br0 |  op_br1 << 8  |  op_bw0 << 16 ;

	junk = BBX_INITOPBR(breg) ;

	//each loop reads 16 columns from ORAM
	for (i = 0; i < (OPRAM_BANK_COLUMNS)/16; i++)
	{

		rsdkOsCfarInData[i*16 + 0]  = BBX_LOAD16_RLU0(base,  -8);
        rsdkOsCfarInData[i*16 + 1]  = BBX_LOAD16_RLU0(base,  -7);
        rsdkOsCfarInData[i*16 + 2]  = BBX_LOAD16_RLU0(base,  -6);
        rsdkOsCfarInData[i*16 + 3]  = BBX_LOAD16_RLU0(base,  -5);
        rsdkOsCfarInData[i*16 + 4]  = BBX_LOAD16_RLU0(base,  -4);
        rsdkOsCfarInData[i*16 + 5]  = BBX_LOAD16_RLU0(base,  -3);
        rsdkOsCfarInData[i*16 + 6]  = BBX_LOAD16_RLU0(base,  -2);
        rsdkOsCfarInData[i*16 + 7]  = BBX_LOAD16_RLU0(base,  -1);
        rsdkOsCfarInData[i*16 + 8]  = BBX_LOAD16_RLU0(base,   0);
        rsdkOsCfarInData[i*16 + 9]  = BBX_LOAD16_RLU0(base,   1);
        rsdkOsCfarInData[i*16 + 10] = BBX_LOAD16_RLU0(base,   2);
        rsdkOsCfarInData[i*16 + 11] = BBX_LOAD16_RLU0(base,   3);
        rsdkOsCfarInData[i*16 + 12] = BBX_LOAD16_RLU0(base,   4);
        rsdkOsCfarInData[i*16 + 13] = BBX_LOAD16_RLU0(base,   5);
        rsdkOsCfarInData[i*16 + 14] = BBX_LOAD16_RLU0(base,   6);
        rsdkOsCfarInData[i*16 + 15] = BBX_LOAD16_RLU0(base,   7);

        rsdkOsCfarThData[i*16 + 0]  = BBX_LOAD16_RLU1(base,  -8);
        rsdkOsCfarThData[i*16 + 1]  = BBX_LOAD16_RLU1(base,  -7);
        rsdkOsCfarThData[i*16 + 2]  = BBX_LOAD16_RLU1(base,  -6);
        rsdkOsCfarThData[i*16 + 3]  = BBX_LOAD16_RLU1(base,  -5);
        rsdkOsCfarThData[i*16 + 4]  = BBX_LOAD16_RLU1(base,  -4);
        rsdkOsCfarThData[i*16 + 5]  = BBX_LOAD16_RLU1(base,  -3);
        rsdkOsCfarThData[i*16 + 6]  = BBX_LOAD16_RLU1(base,  -2);
        rsdkOsCfarThData[i*16 + 7]  = BBX_LOAD16_RLU1(base,  -1);
        rsdkOsCfarThData[i*16 + 8]  = BBX_LOAD16_RLU1(base,   0);
        rsdkOsCfarThData[i*16 + 9]  = BBX_LOAD16_RLU1(base,   1);
        rsdkOsCfarThData[i*16 + 10] = BBX_LOAD16_RLU1(base,   2);
        rsdkOsCfarThData[i*16 + 11] = BBX_LOAD16_RLU1(base,   3);
        rsdkOsCfarThData[i*16 + 12] = BBX_LOAD16_RLU1(base,   4);
        rsdkOsCfarThData[i*16 + 13] = BBX_LOAD16_RLU1(base,   5);
        rsdkOsCfarThData[i*16 + 14] = BBX_LOAD16_RLU1(base,   6);
        rsdkOsCfarThData[i*16 + 15] = BBX_LOAD16_RLU1(base,   7);

        base = base + 16;

	}

	//loop for each range bin
	for(cRB = 0; cRB < numRB; cRB++)
	{
		//align the thresholds with the input samples
		rsdkOsCfarThCompVec[(cRB*chPerFr)/16] = rsdkOsCfarThData[(cRB*chPerFr)/16+1]; //first column is the next column (rsdkOsCfarThData < RSDK_OSCFAR_WIN_SZ)

		for(cs = 1; cs < (chPerFr - RSDK_OSCFAR_WIN_SZ)/16; cs++)
		{
			rsdkOsCfarThCompVec[((cRB*chPerFr)/16)+cs] = BBE_MINUNX16(rsdkOsCfarThData[((cRB*chPerFr)/16)+cs], rsdkOsCfarThData[((cRB*chPerFr)/16)+cs+1]); //while there are more than RSDK_OSCFAR_WIN_SZ thresholds to compare th=min(th+cs, th+cs+1)
		}

		//access not alligned to 16 for the last 16 elements
		for(cs = chPerFr - RSDK_OSCFAR_WIN_SZ; cs < chPerFr; cs++)
		{
			thCompare[chPerFr*cRB + cs] = rsdkOsCfarThDataInt16[chPerFr*cRB + cs - 1];
		}
	}

	//compare the input samples with the threshold vector and write a 1 if sample>threshold
	for(i = 0;  i < (OPRAM_BANK_COLUMNS); i++)
	{
		detects[i] = BBE_LEUNX16(rsdkOsCfarInData[i], rsdkOsCfarThCompVec[i]);
		detects[i] = BBE_NOTB(detects[i]);
	}

	//write the bitmap in ORAM

	op_br0 = 5; op_br1 = 7 ;  op_bw0 = 0;

	breg  = op_br0 |  op_br1 << 8  |  op_bw0 << 16 ;

	junk = BBX_INITOPBR(breg) ;

    base = 8;

	for (i = 0; i < (OPRAM_BANK_COLUMNS)/256; i++)
	{
		BBX_STORE16_WLU0(rsdkOsCfardetects[(i*16+0)],  base, tmp16, -8);
		BBX_STORE16_WLU0(rsdkOsCfardetects[(i*16+1)],  base, tmp16, -7);
		BBX_STORE16_WLU0(rsdkOsCfardetects[(i*16+2)],  base, tmp16, -6);
		BBX_STORE16_WLU0(rsdkOsCfardetects[(i*16+3)],  base, tmp16, -5);
		BBX_STORE16_WLU0(rsdkOsCfardetects[(i*16+4)],  base, tmp16, -4);
		BBX_STORE16_WLU0(rsdkOsCfardetects[(i*16+5)],  base, tmp16, -3);
		BBX_STORE16_WLU0(rsdkOsCfardetects[(i*16+6)],  base, tmp16, -2);
		BBX_STORE16_WLU0(rsdkOsCfardetects[(i*16+7)],  base, tmp16, -1);
		BBX_STORE16_WLU0(rsdkOsCfardetects[(i*16+8)],  base, tmp16,  0);
		BBX_STORE16_WLU0(rsdkOsCfardetects[(i*16+9)],  base, tmp16,  1);
		BBX_STORE16_WLU0(rsdkOsCfardetects[(i*16+10)], base, tmp16,  2);
		BBX_STORE16_WLU0(rsdkOsCfardetects[(i*16+11)], base, tmp16,  3);
		BBX_STORE16_WLU0(rsdkOsCfardetects[(i*16+12)], base, tmp16,  4);
		BBX_STORE16_WLU0(rsdkOsCfardetects[(i*16+13)], base, tmp16,  5);
		BBX_STORE16_WLU0(rsdkOsCfardetects[(i*16+14)], base, tmp16,  6);
		BBX_STORE16_WLU0(rsdkOsCfardetects[(i*16+15)], base, tmp16,  7);
		base = base + 16;
	}

}

#ifdef __cplusplus
}
#endif

/*******************************************************************************
* EOF
******************************************************************************/
