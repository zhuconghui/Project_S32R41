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


static struct ipc_shm_pool_cfg ipcf_shm_cfg_buf_pools0_0[1] = {
	{
		.num_bufs = 1,
		.buf_size = 512,
	},

};

static struct ipc_shm_pool_cfg ipcf_shm_cfg_buf_pools0_1[1] = {
	{
		.num_bufs = 1,
		.buf_size = 32,
	},
};

static struct ipc_shm_channel_cfg ipcf_shm_cfg_channels0[2] = {
	{
		.type = IPC_SHM_MANAGED,
		.ch = {
			.managed = {
				.num_pools = 1,
				.pools = ipcf_shm_cfg_buf_pools0_0,
				.rx_cb = Bbe32EvtIsr,
				.cb_arg = NULL,
			},
		},
	},
	{
		.type = IPC_SHM_MANAGED,
		.ch = {
			.managed = {
				.num_pools = 1,
				.pools = ipcf_shm_cfg_buf_pools0_1,
				.rx_cb = Bbe32EvtIsr,
				.cb_arg = NULL,
			},
		},
	},
};


/* ipc shm configuration */
struct ipc_shm_cfg ipcf_shm_cfg_instances[1] = {
	{
		.local_shm_addr  = 0x34000000,
		.remote_shm_addr = 0x34000400,
		.inter_core_tx_irq = 3,
		.inter_core_rx_irq = 2,
		.local_core = {
			.type = IPC_CORE_M7,
			.index = IPC_CORE_INDEX_0,
			.trusted = IPC_CORE_INDEX_0 | IPC_CORE_INDEX_1
						| IPC_CORE_INDEX_2 | IPC_CORE_INDEX_3
		},
		.remote_core = {
			.type = IPC_CORE_BBE32,
			.index = IPC_CORE_INDEX_0,
		},
		.shm_size  = 1024,
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
