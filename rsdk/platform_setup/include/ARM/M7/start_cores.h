/*
 * Copyright 2019-2022 NXP
 * SPDX-License-Identifier: BSD-3-Clause
 */

#if defined(START_CM7_1)
extern void Start_Cores(void);
#else
#define Start_Cores()
#endif
