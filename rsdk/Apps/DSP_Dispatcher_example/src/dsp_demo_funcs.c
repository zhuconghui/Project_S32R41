/*
 * Copyright 2018-2021,2024 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

#include "dsp_demo_funcs.h"
#include <stdint.h>
#include <xtensa/tie/xt_bben.h>
#include <xtensa/tie/xt_misc.h>
#include <xtensa/tie/radar24.h>
#include <xtensa/tie/xt_core.h>




#ifdef __cplusplus
extern "C"{
#endif

// used for debug purposes to check that P1 Task executes the correct number of times RsdkBbe32Func1
uint32_t numberFunc1Debug = 0;

void RsdkBbe32Func1(uintptr_t argList)
{

	int32_t wRegDataRe, wRegDataIm;

	int32_t arg;



	arg = ((int32_t*)argList)[0]; //interpret argList as a simple 32-bit scalar

	arg = arg + 0x10001; //do some particular processing on the input data

	//Write back the scalar result to SPT Work Reg 0 Real and Imag parts.
	wRegDataRe = arg & 0x00ffffff;
	BBX_SCRLU(wRegDataRe, 0x198);
	XT_DSYNC();			//needed because back-to-back writes to CRLU interface result in data loss otherwise
	wRegDataIm = (arg >> 24U) & 0x000000ff;
	BBX_SCRLU(wRegDataIm, 0x19C);



	numberFunc1Debug++;
}

void RsdkBbe32Func2(uintptr_t argList)
{
    uint32_t arg1, arg2, res;

    int32_t wRegDataRe, wRegDataIm;

    //interpret argList as an array of 2 32-bit arguments
    arg1 = ((uint32_t*)argList)[0];
	arg2 = ((uint32_t*)argList)[1];

	res = arg1 + arg2;


	//Write back the scalar result to SPT Work Reg 0 Real and Imag parts.
	wRegDataRe = (int32_t)(res & 0x00ffffffu);
	BBX_SCRLU(wRegDataRe, 0x198);
	XT_DSYNC();			//needed because back-to-back writes to CRLU interface result in data loss otherwise
	wRegDataIm = (int32_t)((res >> 24) & 0x000000ffu);
	BBX_SCRLU(wRegDataIm, 0x19C);



}

#ifdef __cplusplus
}
#endif

/*******************************************************************************
* EOF
******************************************************************************/
