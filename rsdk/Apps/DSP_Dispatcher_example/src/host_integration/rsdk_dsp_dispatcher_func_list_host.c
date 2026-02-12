/*
 * Copyright 2020-2021 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

#include "typedefs.h"

#ifdef __cplusplus
extern "C" {
#endif

/** This file defines the list of DSP function IDs to be used by the Executable application running on the Host (master) CPU.
 *  This file is specific to the RSDK DSP Calling Convention and should not be modified by the user.
 *  Only the content of dispatcher_func_list.inc may be modified by the user. See the RSDK User Manual for details.
 */

#define RSDK_DSP_REGISTER_FUNC(funcName) const uint32_t RSDK_DSP_FUNC_ID_##funcName = __COUNTER__;
#include "dispatcher_func_list.inc"

#ifdef __cplusplus
}
#endif

/*******************************************************************************
 * EOF
 ******************************************************************************/
