/**************************************************************************************************
 * Copyright 2017-2022 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 **************************************************************************************************/
#include "cache.h"
#ifdef D_CACHE_ENABLE
#include "rsdk_osenv.h" //TODO: Add an explanation why we must include this file or move it where is directly used
#include "core_cm7.h"
#endif

void FlushDcacheRange(const char* addr, int size)
{
#ifdef D_CACHE_ENABLE
    SCB_CleanDCache_by_Addr((volatile void *)addr, size);
#endif
	return;
}

void InvalidateDcacheRange(const char* addr, int size)
{
#ifdef D_CACHE_ENABLE
    SCB_InvalidateDCache_by_Addr((volatile void *)addr, size);
#endif
	return;
}
