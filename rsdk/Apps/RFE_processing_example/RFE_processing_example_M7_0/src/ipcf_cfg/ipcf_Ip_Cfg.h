/*
 *
 * IPC Shared Memory Driver - RTD configuraton
 *
 * Copyright 2020-2023 NXP
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

#include <stdint.h>
#include <stddef.h>
#include "ipc-shm.h"

/*DSP CFG */
#define IPCF_INSTANCE            0U
#define CTRL_CHAN_ID             0U
#define ASYNC_CHAN_ID            1U

/*RFE FW CFG */
#define RFE_ABSTRACT_IPCF_INSTANCE     (1U)
#define RFE_ABSTRACT_IPCF_CMD_CH_ID    (0U)
#define RFE_ABSTRACT_IPCF_RSP_CH_ID    (0U)
#define RFE_ABSTRACT_IPCF_STS_CH_ID    (1U)


/* callbacks for channels  - must be implemented by application*/
/* arguments for callbacks - must be implemented by application*/

void Bbe32EvtIsr(void *argPtr, const uint8 instance, uint8 chan_id, void *bufPtr, uint32 size);
extern void ipcf_chan_rx_cb(void *arg, const uint8 instance, uint8 chan_id, void *mem);
extern void ipc_shm_hardirq_instance(const uint8 instance);

extern const void* rsp_arg_ptr;
extern const void* sts_arg_ptr;
extern const void* rx_cb_arg1;

/* ipc shm configuration for all instances */
extern struct ipc_shm_instances_cfg ipcf_shm_instances_cfg;
extern void ipc_shm_hardirq(void);

#if defined(__cplusplus)
}
#endif

#endif /* IPCF_IP_CFG_H */

