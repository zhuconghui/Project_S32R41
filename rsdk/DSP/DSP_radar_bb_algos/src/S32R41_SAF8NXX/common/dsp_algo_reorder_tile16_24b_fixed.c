/*
 * Copyright 2024 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */


#include "rsdk_dsp_radar_bb_algos_s32r41.h"
#include "dsp_algo_24b_fixed_functions_s32r41.h"









#include <stdbool.h>
#include <xtensa/tie/xt_FP.h>
#include <xtensa/tie/xt_bben.h>
#include <xtensa/tie/xt_misc.h>
#include <xtensa/tie/radar24.h>

#ifdef __cplusplus
extern "C"{
#endif


void Rsdk_ReordTile16to4Ch(xb_vecNx16 * pOut,
                           xb_vecNx16 * pIn,
							    uint8_t doubleInBufEn,
                               uint16_t size)
{
    uint16_t i = 0U;
    xb_vecNx16 tmpX16;
    xb_vecNx16 *pInTmp;
    xb_vecNx16 *pOutCh1, *pOutCh2, *pOutCh3, *pOutCh4;
    static uint8_t pingPongSwitch = false;	//keep track of odd/even function calls, to update input pointer

    /* check restrictions */
    if ((uintptr_t)pIn % BBE_SIMD_WIDTH != 0) {
    	SetDspError(RSDK_DSP_ALGO_WRONG_ALIGN);
    	return;
    }
    if ((uintptr_t)pOut % BBE_SIMD_WIDTH != 0) {
    	SetDspError(RSDK_DSP_ALGO_WRONG_ALIGN);
    	return;
    }
	if (size % 4 != 0) //size is divided by 16 before being passed to this function, still need to check that it is a multiple of the number of antennas
	{
		SetDspError(RSDK_DSP_ALGO_WRONG_PARAM);
		return;
	}

	if (doubleInBufEn == false)
    {
    	//single buffer.
    	pInTmp = pIn;

    	//also reset the double-buffer ping-pong switch, to allow runtime recovery in case of system error
    	//happening in double-buffer mode after an odd number of chirps
    	pingPongSwitch = false;
    }
    else
    {
    	//using double buffer (ping-pong). Toggle the buffer pointer between calls
    	if (pingPongSwitch == false)
    	{
    		pInTmp = &pIn[0];
    		pingPongSwitch = true;
    	}
    	else
    	{
    		pInTmp = &pIn[size];
    		pingPongSwitch = false;
    	}
    }

    pOutCh1 = &pOut[0];
    pOutCh2 = &pOut[size/4];
    pOutCh3 = &pOut[2*size/4];
    pOutCh4 = &pOut[3*size/4];

    while (i < size)
    {
        BBE_LVNX16_IP(tmpX16, pInTmp, 32U);
        BBE_SVNX16_IP(tmpX16, pOutCh1, 32U);
        BBE_LVNX16_IP(tmpX16, pInTmp, 32U);
        BBE_SVNX16_IP(tmpX16, pOutCh2, 32U);
        BBE_LVNX16_IP(tmpX16, pInTmp, 32U);
        BBE_SVNX16_IP(tmpX16, pOutCh3, 32U);
        BBE_LVNX16_IP(tmpX16, pInTmp, 32U);
        BBE_SVNX16_IP(tmpX16, pOutCh4, 32U);
        i += 4U;
    }
}

#ifdef __cplusplus
}
#endif

/*******************************************************************************
* EOF
******************************************************************************/
