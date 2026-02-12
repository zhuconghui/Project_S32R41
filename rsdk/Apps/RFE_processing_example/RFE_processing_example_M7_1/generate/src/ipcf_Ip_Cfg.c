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
#if defined(__cplusplus)
extern "C"{
#endif

#include "ipc-types.h"
#include "ipcf_Ip_Cfg.h"
#include "rfe20_PCCfg.h"
/**
 * SOURCE FILE VERSION INFORMATION
 */
#define IPCF_IP_CFG_VENDOR_ID_C                    43
#define IPCF_IP_CFG_MODULE_ID_C                    255
#define IPCF_IP_CFG_AR_RELEASE_MAJOR_VERSION_C     4
#define IPCF_IP_CFG_AR_RELEASE_MINOR_VERSION_C     7
#define IPCF_IP_CFG_AR_RELEASE_REVISION_VERSION_C  0
#define IPCF_IP_CFG_SW_MAJOR_VERSION_C             1
#define IPCF_IP_CFG_SW_MINOR_VERSION_C             1
#define IPCF_IP_CFG_SW_PATCH_VERSION_C             0

/**
 * FILE VERSION CHECKS
 */
#if (IPCF_IP_CFG_VENDOR_ID_C != IPC_TYPES_VENDOR_ID)
    #error "ipcf_Ip_Cfg.c and ipc-types.h have different vendor ids"
#endif
#if ((IPCF_IP_CFG_AR_RELEASE_MAJOR_VERSION_C != IPC_TYPES_AR_RELEASE_MAJOR_VERSION) || \
    (IPCF_IP_CFG_AR_RELEASE_MINOR_VERSION_C != IPC_TYPES_AR_RELEASE_MINOR_VERSION) || \
    (IPCF_IP_CFG_AR_RELEASE_REVISION_VERSION_C != IPC_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of ipcf_Ip_Cfg.c and ipc-types.h are different"
#endif
#if ((IPCF_IP_CFG_SW_MAJOR_VERSION_C != IPC_TYPES_SW_MAJOR_VERSION) || \
    (IPCF_IP_CFG_SW_MINOR_VERSION_C != IPC_TYPES_SW_MINOR_VERSION) || \
    (IPCF_IP_CFG_SW_PATCH_VERSION_C != IPC_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of ipcf_Ip_Cfg.c and ipc-types.h are different"
#endif

#if (IPCF_IP_CFG_VENDOR_ID_C != IPCF_IP_CFG_VENDOR_ID)
    #error "ipcf_Ip_Cfg.c and ipcf_Ip_Cfg.h have different vendor ids"
#endif
#if ((IPCF_IP_CFG_AR_RELEASE_MAJOR_VERSION_C != IPCF_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (IPCF_IP_CFG_AR_RELEASE_MINOR_VERSION_C != IPCF_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
    (IPCF_IP_CFG_AR_RELEASE_REVISION_VERSION_C != IPCF_IP_CFG_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of ipcf_Ip_Cfg.c and ipcf_Ip_Cfg.h are different"
#endif
#if ((IPCF_IP_CFG_SW_MAJOR_VERSION_C != IPCF_IP_CFG_SW_MAJOR_VERSION) || \
    (IPCF_IP_CFG_SW_MINOR_VERSION_C != IPCF_IP_CFG_SW_MINOR_VERSION) || \
    (IPCF_IP_CFG_SW_PATCH_VERSION_C != IPCF_IP_CFG_SW_PATCH_VERSION))
#error "Software Version Numbers of ipcf_Ip_Cfg.c and ipcf_Ip_Cfg.h are different"
#endif


static struct ipc_shm_channel_cfg ipcf_shm_cfg_channels0[2] = {
    {
        .type = IPC_SHM_UNMANAGED,
        .ch = {
            .unmanaged = {
                .size = 256,
                .rx_cb = ipcf_chan_rx_cb,
                .cb_arg = &cmd_arg_ptr,
            },
        },
    },
    {
        .type = IPC_SHM_UNMANAGED,
        .ch = {
            .unmanaged = {
                .size = 64,
                .rx_cb = ipcf_chan_rx_cb,
                .cb_arg = NULL,
            },
        },
    },
};



/* ipc shm configuration */
struct ipc_shm_cfg ipcf_shm_cfg_instances[1] = {
    {
        .local_shm_addr  = RFE_CMD_CLIENT_BASE_ADDRESS+0x400,
        .remote_shm_addr = RFE_CMD_CLIENT_BASE_ADDRESS,
        .shm_size  = 0x400,
        .inter_core_tx_irq = MSCM_INT0_IRQn,
        .inter_core_rx_irq = IPC_IRQ_NONE,
        .local_core = {
            .type = IPC_CORE_M7,
            .index = IPC_CORE_INDEX_1,
        },
        .remote_core = {
            .type = IPC_CORE_M7,
            .index = IPC_CORE_INDEX_0,
        },
        .num_channels = 2,
        .channels = ipcf_shm_cfg_channels0,
    },
};

struct ipc_shm_instances_cfg ipcf_shm_instances_cfg = {
    .num_instances = 1u,
    .shm_cfg = ipcf_shm_cfg_instances,
};


#if defined(__cplusplus)
}
#endif

