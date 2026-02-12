/*
 *
 * IPC Shared Memory Driver - IPCF configuraton
 *
 * Copyright 2020-2024 NXP
 * All Rights Reserved.
 *
 * NXP Confidential. This software is owned or controlled by NXP and may only be
 * used strictly in accordance with the applicable license terms. By expressly
 * accepting such terms or by downloading, installing, activating and/or otherwise
 * using the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms. If you do not agree to be
 * bound by the applicable license terms, then you may not retain, install,
 * activate or otherwise use the software.
 *
 */

#ifndef IPCF_IP_CFG_H
#define IPCF_IP_CFG_H

#if defined(__cplusplus)
extern "C"{
#endif

/**
 * SOURCE FILE VERSION INFORMATION
 */
#define IPCF_IP_CFG_VENDOR_ID                    43
#define IPCF_IP_CFG_MODULE_ID                    255
#define IPCF_IP_CFG_AR_RELEASE_MAJOR_VERSION     4
#define IPCF_IP_CFG_AR_RELEASE_MINOR_VERSION     7
#define IPCF_IP_CFG_AR_RELEASE_REVISION_VERSION  0
#define IPCF_IP_CFG_SW_MAJOR_VERSION             1
#define IPCF_IP_CFG_SW_MINOR_VERSION             1
#define IPCF_IP_CFG_SW_PATCH_VERSION             0


/*
* @brief            IPCF configuration for all instances
*
*/

#include <xtensa/xos.h>
#include "ipc-shm.h"

#define IPCF_INSTANCE 0u
#define CTRL_CHAN_ID 0u
#define ASYNC_CHAN_ID 1u

/* callbacks for channels  - must be implemented by application*/
/* arguments for callbacks - must be implemented by application*/

void CpuEvtIsr(void *arg, const uint8_t instance, uint8 chan_id, void *buf, uint32 size);

/* ipc shm configuration for all instances */
extern struct ipc_shm_instances_cfg ipcf_shm_instances_cfg;
extern void ipc_shm_hardirq(void *arg);

#if defined(__cplusplus)
}
#endif

#endif /* IPCF_IP_CFG_H */

