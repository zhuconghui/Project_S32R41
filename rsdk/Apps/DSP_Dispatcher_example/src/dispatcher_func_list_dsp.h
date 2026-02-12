/*
 * Copyright 2018-2021 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

#ifndef DSP_DISPATCHER_FUNC_LIST_DSP_H
#define DSP_DISPATCHER_FUNC_LIST_DSP_H

#define RSDK_DSP_REGISTER_FUNC(funcName) (&funcName),

rsdkDspFuncPtr_t gDspDispatcherFuncTable[] = {
#include "dispatcher_func_list.inc"
};

#define DSP_DISP_FUNC_TABLE_SIZE (sizeof(gDspDispatcherFuncTable) / sizeof(rsdkDspFuncPtr_t))

#endif /* DSP_DISPATCHER_FUNC_LIST_DSP_H */
