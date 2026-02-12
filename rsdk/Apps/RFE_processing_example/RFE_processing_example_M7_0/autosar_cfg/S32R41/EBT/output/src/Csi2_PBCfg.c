/*
 * Copyright 2022-2024 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */


#include "Csi2_Types.h"
#include "rsdk_version.h"
#include "Rfe20_PCCfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CSI2_CBK_VENDOR_ID                          43
#define CSI2_CBK_AR_RELEASE_MAJOR_VERSION           RSDK_AR_MAJOR
#define CSI2_CBK_AR_RELEASE_MINOR_VERSION           RSDK_AR_MINOR
#define CSI2_CBK_AR_RELEASE_REVISION_VERSION        RSDK_AR_REV
#define CSI2_CBK_SW_MAJOR_VERSION                   RSDK_SW_MAJOR
#define CSI2_CBK_SW_MINOR_VERSION                   RSDK_SW_MINOR
#define CSI2_CBK_SW_PATCH_VERSION                   RSDK_SW_PATCH


/*===================================================================
 *  Configuration file for Csi2 module
 */


/* ==================================================================
 *  Start of a params set for CSI2 unit
 * ================================================================*/

/* ==================================================================
 *  Start of Virtual Channel parameters for this CSI2 unit
 * ================================================================*/
extern uint8 gAdcDataBuff0[];

Csi2_VCParamsType SetupParam_0_Params_VC_0 = {
    .streamDataType     = CSI2_DATA_TYPE_RAW12,
    .channelsNum        = 4u,
    .expectedNumSamples = 512u,
    .expectedNumLines   = 128u,
    .bufferReset        = CSI2_BUF_RESET_FS,
    .bufNumLines        = 2u,
    .bufLineLen         = 4176u,
    .bufDataPtr         = (void*)gAdcDataBuff0,
    .vcEventsReq        = 0u | CSI2_EVT_FRAME_START | CSI2_EVT_FRAME_END,
    .outputDataMode     = CSI2_VC_BUF_OUT_TILE8 | CSI2_VC_BUF_REAL_DATA | CSI2_VC_BUF_NO_FLIP_SIGN,
    .offsetCompReal     = {0,0,0,0},
    .offsetCompImg      = {0,0,0,0},
    .bufNumLinesTrigger = 1
};


Csi2_VCParamsType SetupParam_0_Params_VC_3 = {
    .streamDataType     = CSI2_DATA_TYPE_RAW12,
    .channelsNum        = 4u,
    .expectedNumSamples = 128u,
    .expectedNumLines   = 1u,
    .bufNumLines        = 1u,
    .bufLineLen         = 1024u,
    .bufDataPtr         = (void*)RFE_RFBIST_BUFFERS_ADDRESS,
    .vcEventsReq        = 0u,
    .outputDataMode     = CSI2_VC_BUF_OUT_TILE8 | CSI2_VC_BUF_REAL_DATA | CSI2_VC_BUF_NO_FLIP_SIGN,
    .offsetCompReal     = {0,0,0,0},
    .offsetCompImg      = {0,0,0,0},
    .bufNumLinesTrigger = 1
};

/* ==================================================================
 *  End of Virtual Channels parameters for this CSI2 unit
 * ================================================================*/


 
/* Setup structure for CSI2_UNIT_LEVEL      */
Csi2_SetupParamsType    Csi2SetupParamsList_0 = {
    .numLanesRx = CSI2_LANE_3,
    .lanesMapRx = {CSI2_LANE_0, CSI2_LANE_1, CSI2_LANE_2, CSI2_LANE_3},
    .initOptions = CSI2_DPHY_INIT_W_STOP_STATE,
    .statManagement = CSI2_AUTODC_NO,
    .rxClkFreq = 240,
    .vcConfigPtr = { &SetupParam_0_Params_VC_0, NULL_PTR, NULL_PTR, &SetupParam_0_Params_VC_3},
};

/* ===========================================
 *  End of the params set for CSI2 unit
 * ===========================================*/


/* ==================================================================
 *  Start of a params set for CSI2 unit
 * ================================================================*/

/* ==================================================================
 *  Start of Virtual Channel parameters for this CSI2 unit
 * ================================================================*/
extern uint8 gAdcDataBuff1[];

Csi2_VCParamsType SetupParam_1_Params_VC_0 = {
    .streamDataType     = CSI2_DATA_TYPE_RAW12,
    .channelsNum        = 4u,
    .expectedNumSamples = 512u,
    .expectedNumLines   = 128u,
    .bufferReset        = CSI2_BUF_RESET_FS,
    .bufNumLines        = 2u,
    .bufLineLen         = 4176u,
    .bufDataPtr         = (void*)gAdcDataBuff1,
    .vcEventsReq        = 0u | CSI2_EVT_FRAME_START | CSI2_EVT_FRAME_END,
    .outputDataMode     = CSI2_VC_BUF_OUT_TILE8 | CSI2_VC_BUF_REAL_DATA | CSI2_VC_BUF_NO_FLIP_SIGN,
    .offsetCompReal     = {0,0,0,0},
    .offsetCompImg      = {0,0,0,0},
    .bufNumLinesTrigger = 1
};


Csi2_VCParamsType SetupParam_1_Params_VC_3 = {
    .streamDataType     = CSI2_DATA_TYPE_RAW12,
    .channelsNum        = 4u,
    .expectedNumSamples = 128u,
    .expectedNumLines   = 1u,
    .bufNumLines        = 1u,
    .bufLineLen         = 1024u,
    .bufDataPtr         = (void*)RFE_RFBIST_BUFFERS_ADDRESS + (((uint32_t)1 % (uint32_t)RFE_NUM_USED_FRONT_ENDS) * 1024UL),
    .vcEventsReq        = 0u,
    .outputDataMode     = CSI2_VC_BUF_OUT_TILE8 | CSI2_VC_BUF_REAL_DATA | CSI2_VC_BUF_NO_FLIP_SIGN,
    .offsetCompReal     = {0,0,0,0},
    .offsetCompImg      = {0,0,0,0},
    .bufNumLinesTrigger = 1
};

/* ==================================================================
 *  End of Virtual Channels parameters for this CSI2 unit
 * ================================================================*/


 
/* Setup structure for CSI2_UNIT_LEVEL      */
Csi2_SetupParamsType    Csi2SetupParamsList_1 = {
    .numLanesRx = CSI2_LANE_3,
    .lanesMapRx = {CSI2_LANE_0, CSI2_LANE_1, CSI2_LANE_2, CSI2_LANE_3},
    .initOptions = CSI2_DPHY_INIT_W_STOP_STATE,
    .statManagement = CSI2_AUTODC_NO,
    .rxClkFreq = 240,
    .vcConfigPtr = { &SetupParam_1_Params_VC_0, NULL_PTR, NULL_PTR, &SetupParam_1_Params_VC_3},
};

/* ===========================================
 *  End of the params set for CSI2 unit
 * ===========================================*/

