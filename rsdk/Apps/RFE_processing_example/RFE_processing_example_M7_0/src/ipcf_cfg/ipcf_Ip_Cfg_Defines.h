/*
 *
 * IPC Shared Memory Driver - IPCF configuraton defines
 *
 * Copyright 2023-2024 NXP
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
#ifndef IPCF_IP_CFG_DEFINES_H
#define IPCF_IP_CFG_DEFINES_H

#if defined(__cplusplus)
extern "C"{
#endif

/**
 * SOURCE FILE VERSION INFORMATION
 */
#define IPCF_IP_CFG_DEFINES_VENDOR_ID                    43
#define IPCF_IP_CFG_DEFINES_MODULE_ID                    255
#define IPCF_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define IPCF_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION     7
#define IPCF_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define IPCF_IP_CFG_DEFINES_SW_MAJOR_VERSION             1
#define IPCF_IP_CFG_DEFINES_SW_MINOR_VERSION             1
#define IPCF_IP_CFG_DEFINES_SW_PATCH_VERSION             0

#define IPC_SHM_MAX_INSTANCES       2U
#define IPC_SHM_MAX_CHANNELS       2U
#define IPC_SHM_MAX_POOLS       2U
#define IPC_SHM_MAX_BUFS_PER_POOL       1U

#if defined(__cplusplus)
}
#endif

#endif /* IPCF_IP_CFG_DEFINES_H */

