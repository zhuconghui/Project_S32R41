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
[!VAR "Csi2CfgPath"!]/AUTOSAR/TOP-LEVEL-PACKAGES/Csi2/ELEMENTS/Csi2[!ENDVAR!][!MACRO "GetLineId", "numLine"!][!IF "$numLine = 1"!]CSI2_LANE_0[!ELSEIF "$numLine = 2"!]CSI2_LANE_1[!ELSEIF "$numLine = 3"!]CSI2_LANE_2[!ELSEIF "$numLine = 4"!]CSI2_LANE_3[!ENDIF!][!ENDMACRO!][!MACRO "GetFPEvt", "inValue"!][!IF "$inValue = 'Frame_Start'"!]CSI2_REQ_ETRG_EVT_FRAME_START[!ELSEIF "$inValue = 'Frame_End'"!]CSI2_REQ_ETRG_EVT_FRAME_END[!ELSEIF "$inValue = 'Packet_Start'"!]CSI2_REQ_ETRG_EVT_CHIRP_START[!ELSEIF "$inValue = 'Packet_End'"!]CSI2_REQ_ETRG_EVT_CHIRP_END[!ENDIF!][!ENDMACRO!][!MACRO "GetSpecPack", "inValue"!][!IF "$inValue = 'Embedded_Data'"!]CSI2_REQ_ETRG_EVT_PACK_EMBD[!ELSEIF "$inValue = 'User_Defined_Data'"!]CSI2_REQ_ETRG_EVT_PACK_USER[!ELSEIF "$inValue = 'RAW_Data'"!]CSI2_REQ_ETRG_EVT_PACK_RAW[!ELSEIF "$inValue = 'RGB_Data'"!]CSI2_REQ_ETRG_EVT_PACK_RGB[!ENDIF!][!ENDMACRO!][!MACRO "GetErrEvt", "inValue"!][!IF "$inValue = 'Line_Count'"!]CSI2_REQ_ETRG_EVT_ERR_LINECNT[!ELSEIF "$inValue = 'Line_Length'"!]CSI2_REQ_ETRG_EVT_ERR_LINLEN[!ELSEIF "$inValue = 'CRC_or_ECC2bits'"!]CSI2_REQ_ETRG_EVT_ERR_CRCECC[!ELSEIF "$inValue = 'No_Synchronization_on_DPHY'"!]CSI2_REQ_ETRG_EVT_ERR_NOSYNC[!ENDIF!][!ENDMACRO!][!MACRO "GetOutputAuxMask", "type"!][!IF "$type = 'CSI2_DATA_TYPE_AUX_0_NO_DROP'"!][!ELSEIF "$type = 'CSI2_DATA_TYPE_AUX_0_DR_1OF2'"!] | 0x40[!ELSEIF "$type = 'CSI2_DATA_TYPE_AUX_0_DR_3OF4'"!] | 0x80[!ELSE!] | 0xc0[!ENDIF!][!ENDMACRO!]

#include "Csi2_Types.h"
#include "rsdk_version.h"
[!IF "(text:concat(text:grep(node:value(/AUTOSAR/TOP-LEVEL-PACKAGES/Resource/ELEMENTS/Resource/ResourceGeneral/ResourceSubderivative), 'saf8[A-Za-z_0-9]*'), 'x') = 'x') and ((/AUTOSAR/TOP-LEVEL-PACKAGES/Csi2/ELEMENTS/Csi2/Csi2General/Csi2Rfe20Usage) = 'true')"!]#include "Rfe20_PCCfg.h"[!ENDIF!]

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
[!LOOP "/AUTOSAR/TOP-LEVEL-PACKAGES/Csi2/ELEMENTS/Csi2/Csi2SetupParamsList/*"!]
[!VAR "setupIndex" = "replace(node:name(.), 'Csi2SetupParamsList_', '')"!]
/* ==================================================================
 *  Start of a params set for CSI2 unit
 * ================================================================*/

/* ==================================================================
 *  Start of Virtual Channel parameters for this CSI2 unit
 * ================================================================*/[!LOOP "./Csi2VcParamsList/*"!]
extern uint8 [!"node:value(./Csi2VcDataBuffer/Csi2VcBufMemPointer)"!][];

Csi2_VCParamsType [!"concat('SetupParam_', $setupIndex, '_Params_VC_', node:value(./Csi2VcUsed))"!] = {
    .streamDataType     = [!"node:value(./Csi2VcStreamType)"!],
    .channelsNum        = [!"concat(node:value(./Csi2VcChannels), 'u')"!],
    .expectedNumSamples = [!"concat(node:value(./Csi2VcNumSamples), 'u')"!],
    .expectedNumLines   = [!"concat(node:value(./Csi2VcNumChirps), 'u')"!],
    .bufferReset        = [!"node:value(./Csi2BufResetType)"!],
    .bufNumLines        = [!"concat(node:value(./Csi2VcDataBuffer/Csi2VcBufNumLines), 'u')"!],
    .bufLineLen         = [!"concat(node:value(./Csi2VcDataBuffer/Csi2VcBufLineLen), 'u')"!],
    .bufDataPtr         = (void*)[!"node:value(./Csi2VcDataBuffer/Csi2VcBufMemPointer)"!],
    .vcEventsReq        = 0u[!IF "node:value(./Csi2VcEventsManagement/Csi2VcEventsSelection/Csi2VcFrameStartEvt)"!] | CSI2_EVT_FRAME_START[!ENDIF!][!IF "node:value(./Csi2VcEventsManagement/Csi2VcEventsSelection/Csi2VcFrameEndEvt)"!] | CSI2_EVT_FRAME_END[!ENDIF!][!IF "node:value(./Csi2VcEventsManagement/Csi2VcEventsSelection/Csi2VcLineDoneEvt)"!] | CSI2_EVT_LINE_END[!ENDIF!][!IF "node:value(./Csi2VcEventsManagement/Csi2VcEventsSelection/Csi2VcShortPackedEvt)"!] | CSI2_EVT_SHORT_PACKET[!ENDIF!][!IF "node:value(./Csi2VcEventsManagement/Csi2VcEventsSelection/Csi2VcStartNotZeroEvt)"!] | CSI2_EVT_NEXT_START_NOT_0[!ENDIF!][!IF "(node:value(./Csi2VcEventsManagement/Csi2VcEventsSelection/Csi2VcBitNotToggledEvt) = 'true') and (node:value(../../../../Csi2General/Csi2StatisticDataUsage) = 'true')"!] | CSI2_EVT_BIT_NOT_TOGGLE[!ENDIF!],
    .outputDataMode     = [!"node:value(./Csi2VcOutputMode/Csi2BufDataOutput)"!] | [!IF "node:value(./Csi2VcOutputMode/Csi2VcOutputComplex)"!]CSI2_VC_BUF_COMPLEX_DATA[!ELSE!]CSI2_VC_BUF_REAL_DATA[!ENDIF!] | [!IF "node:value(./Csi2VcOutputMode/Csi2VcOutputFlip)"!]CSI2_VC_BUF_FLIP_SIGN[!ELSE!]CSI2_VC_BUF_NO_FLIP_SIGN[!ENDIF!][!IF "(node:value(./Csi2VcStreamType) = 'CSI2_DATA_TYPE_RAW8') and node:value(./Csi2VcOutputMode/Csi2VcOutputSwap8)"!] | CSI2_VC_BUF_SWAP_RAW8[!ENDIF!][!IF "(node:value(./Csi2VcStreamType) = 'CSI2_DATA_TYPE_RAW16') and node:value(./Csi2VcOutputMode/Csi2VcOutputSwap16)"!] | CSI2_VC_BUF_RAW16_MSB_F[!ENDIF!][!IF "node:value(./Csi2VcOutputMode/Csi2VcOutputWriteAll)"!] | CSI2_VC_BUF_WRITE_ALL_DATA[!ENDIF!][!IF "node:value(./Csi2VcAuxiliaryDataSetup/Csi2VcAuxiliaryDataUsage)"!] | CSI2_VC_BUF_FIFTH_CH_ON[!CALL "GetOutputAuxMask", "type" = "node:value(./Csi2VcAuxiliaryDataSetup/Csi2VcAuxiliaryDataStreamType)"!][!ENDIF!],
    .offsetCompReal     = {[!FOR "chnlId" = "0" TO "3"!][!IF "$chnlId != 0"!],[!ENDIF!][!"node:value(concat('./Csi2VcDcOffsets/Csi2VcDcOffsetsReal/Csi2VcDcOffsetReal', $chnlId))"!][!ENDFOR!]},
    .offsetCompImg      = {[!FOR "chnlId" = "0" TO "3"!][!IF "$chnlId != 0"!],[!ENDIF!][!"node:value(concat('./Csi2VcDcOffsets/Csi2VcDcOffsetsComplex/Csi2VcDcOffsetComplex', $chnlId))"!][!ENDFOR!]},[!IF "node:value(../../../../Csi2General/Csi2GPIOUsage)"!]
    .gpio1Mask          = (0u[!IF "node:value(./Csi2VcGpioSetup/Csi2Gpio1Setup/Csi2Gpio1EnaPackAndFrame)"!] |  [!CALL "GetFPEvt", "inValue" = "node:value(./Csi2VcGpioSetup/Csi2Gpio1Setup/Csi2Gpio1PackAndFrameSelection)"!][!ENDIF!][!IF "node:value(./Csi2VcGpioSetup/Csi2Gpio1Setup/Csi2Gpio1EnaPackType)"!] | [!CALL "GetSpecPack", "inValue" = "node:value(./Csi2VcGpioSetup/Csi2Gpio1Setup/Csi2Gpio1PackTypeSelection)"!][!ENDIF!][!IF "node:value(./Csi2VcGpioSetup/Csi2Gpio1Setup/Csi2Gpio1EnaError)"!] | [!CALL "GetErrEvt", "inValue" = "node:value(./Csi2VcGpioSetup/Csi2Gpio1Setup/Csi2Gpio1ErrorSelection)"!][!ENDIF!]),
    .gpio2Mask          = 0u,
    .gpio1EnaMask       = (0u[!IF "node:value(./Csi2VcGpioSetup/Csi2Gpio1Setup/Csi2Gpio1EnaPackAndFrame)"!] | CSI2_REQ_ETRG_ENA_ON_PF[!ENDIF!][!IF "node:value(./Csi2VcGpioSetup/Csi2Gpio1Setup/Csi2Gpio1EnaPackType)"!] | CSI2_REQ_ETRG_ENA_ON_PACKET[!ENDIF!][!IF "node:value(./Csi2VcGpioSetup/Csi2Gpio1Setup/Csi2Gpio1EnaError)"!] | CSI2_REQ_ETRG_ENA_ON_ERROR[!ENDIF!]),
    .gpio2EnaMask       = 0u,[!ENDIF!][!IF "node:value(../../../../Csi2General/Csi2SDMAUsage)"!]
    .sdma1Mask          = (0u[!IF "node:value(./Csi2VcSdmaSetup/Csi2Sdma1Setup/Csi2Sdma1EnaPackAndFrame)"!] |  [!CALL "GetFPEvt", "inValue" = "node:value(./Csi2VcSdmaSetup/Csi2Sdma1Setup/Csi2Sdma1PackAndFrameSelection)"!][!ENDIF!][!IF "node:value(./Csi2VcSdmaSetup/Csi2Sdma1Setup/Csi2Sdma1EnaPackType)"!] | [!CALL "GetSpecPack", "inValue" = "node:value(./Csi2VcSdmaSetup/Csi2Sdma1Setup/Csi2Sdma1PackTypeSelection)"!][!ENDIF!][!IF "node:value(./Csi2VcSdmaSetup/Csi2Sdma1Setup/Csi2Sdma1EnaError)"!] | [!CALL "GetErrEvt", "inValue" = "node:value(./Csi2VcSdmaSetup/Csi2Sdma1Setup/Csi2Sdma1ErrorSelection)"!][!ENDIF!]),
    .sdma2Mask          = 0u,
    .sdma1EnaMask       = (0u[!IF "node:value(./Csi2VcSdmaSetup/Csi2Sdma1Setup/Csi2Sdma1EnaPackAndFrame)"!] | CSI2_REQ_ETRG_ENA_ON_PF[!ENDIF!][!IF "node:value(./Csi2VcSdmaSetup/Csi2Sdma1Setup/Csi2Sdma1EnaPackType)"!] | CSI2_REQ_ETRG_ENA_ON_PACKET[!ENDIF!][!IF "node:value(./Csi2VcSdmaSetup/Csi2Sdma1Setup/Csi2Sdma1EnaError)"!] | CSI2_REQ_ETRG_ENA_ON_ERROR[!ENDIF!]),
    .sdma2EnaMask       = 0u,[!ENDIF!]
    .bufNumLinesTrigger = [!"node:value(./Csi2VcEventsManagement/Csi2VcBufLinesTrigger)"!]
};
[!ENDLOOP!]
[!IF "(text:concat(text:grep(node:value(/AUTOSAR/TOP-LEVEL-PACKAGES/Resource/ELEMENTS/Resource/ResourceGeneral/ResourceSubderivative), 'saf8[A-Za-z_0-9]*'), 'x') = 'x') and ((/AUTOSAR/TOP-LEVEL-PACKAGES/Csi2/ELEMENTS/Csi2/Csi2General/Csi2Rfe20Usage) = 'true')"!]
Csi2_VCParamsType [!"concat('SetupParam_', $setupIndex, '_Params_VC_3')"!] = {
    .streamDataType     = CSI2_DATA_TYPE_RAW12,
    .channelsNum        = 4u,
    .expectedNumSamples = 128u,
    .expectedNumLines   = 1u,
    .bufNumLines        = 1u,
    .bufLineLen         = 1024u,
    .bufDataPtr         = (void*)RFE_RFBIST_BUFFERS_ADDRESS[!IF "$setupIndex != 0"!] + (((uint32_t)[!"$setupIndex"!] % (uint32_t)RFE_NUM_USED_FRONT_ENDS) * 1024UL)[!ENDIF!],
    .vcEventsReq        = 0u,
    .outputDataMode     = CSI2_VC_BUF_OUT_TILE8 | CSI2_VC_BUF_REAL_DATA | CSI2_VC_BUF_NO_FLIP_SIGN,
    .offsetCompReal     = {0,0,0,0},
    .offsetCompImg      = {0,0,0,0},
    .bufNumLinesTrigger = 1
};
[!ENDIF!]
/* ==================================================================
 *  End of Virtual Channels parameters for this CSI2 unit
 * ================================================================*/[!IF "node:value(../../Csi2General/Csi2AuxiliaryDataUsage)"!]
 
/* ==================================================================
 *  Start of Auxiliary Data setup for Virtual Channels for this CSI2 unit
 * ================================================================*/[!LOOP "./Csi2VcParamsList/*"!][!IF "node:value(./Csi2VcAuxiliaryDataSetup/Csi2VcAuxiliaryDataUsage)"!]
extern uint8 [!"node:value(./Csi2VcAuxiliaryDataSetup/Csi2VcAuxDataBufMemPointer)"!][];

Csi2_VCParamsType [!"concat('SetupParam_', $setupIndex, '_Params_AuxVC_', node:value(./Csi2VcUsed))"!] = {
    .streamDataType     = [!IF "node:value(./Csi2VcAuxiliaryDataSetup/Csi2VcAuxiliaryDataStreamType)='CSI2_DATA_TYPE_AUX_0_NO_DROP'"!][!IF "node:value(./Csi2VcStreamType)='CSI2_DATA_TYPE_RAW12'"!]CSI2_DATA_TYPE_R12_A0_NO_DROP[!ELSE!]CSI2_DATA_TYPE_R16_A0_NO_DROP[!ENDIF!][!ELSEIF "node:value(./Csi2VcAuxiliaryDataSetup/Csi2VcAuxiliaryDataStreamType)='CSI2_DATA_TYPE_AUX_0_DR_1OF2'"!][!IF "node:value(./Csi2VcStreamType)='CSI2_DATA_TYPE_RAW12'"!]CSI2_DATA_TYPE_R12_A0_DR_1OF2[!ELSE!]CSI2_DATA_TYPE_R16_A0_DR_1OF2[!ENDIF!][!ELSEIF "node:value(./Csi2VcAuxiliaryDataSetup/Csi2VcAuxiliaryDataStreamType)='CSI2_DATA_TYPE_AUX_0_DR_3OF4'"!][!IF "node:value(./Csi2VcStreamType)='CSI2_DATA_TYPE_RAW12'"!]CSI2_DATA_TYPE_R12_A0_DR_3OF4[!ELSE!]CSI2_DATA_TYPE_R16_A0_DR_3OF4[!ENDIF!][!ELSE!][!IF "node:value(./Csi2VcStreamType)='CSI2_DATA_TYPE_RAW12'"!]CSI2_DATA_TYPE_R12_A1_NO_DROP[!ELSE!]CSI2_DATA_TYPE_R16_A1_NO_DROP[!ENDIF!][!ENDIF!],
    .channelsNum        = [!"concat(node:value(./Csi2VcChannels), 'u')"!],
    .expectedNumSamples = [!"concat(node:value(./Csi2VcNumSamples), 'u')"!],
    .expectedNumLines   = [!"concat(node:value(./Csi2VcNumChirps), 'u')"!],[!IF "text:concat(text:grep(node:value('/AUTOSAR/TOP-LEVEL-PACKAGES/Resource/ELEMENTS/Resource/ResourceGeneral/ResourceSubderivative'), 'saf8[A-Za-z_0-9]*'), 'x') != 'x'"!]
    .bufferReset        = [!"node:value(./Csi2BufResetType)"!],[!ENDIF!]
    .bufNumLines        = [!"concat(node:value(./Csi2VcAuxiliaryDataSetup/Csi2AuxiliaryDataBufNumLines), 'u')"!],
    .bufLineLen         = [!"concat(node:value(./Csi2VcAuxiliaryDataSetup/Csi2VcAuxiliaryDataBufLineLen), 'u')"!],
    .bufDataPtr         = (void*)[!"node:value(./Csi2VcAuxiliaryDataSetup/Csi2VcAuxDataBufMemPointer)"!],
    .vcEventsReq        = 0u[!IF "node:value(./Csi2VcEventsManagement/Csi2VcEventsSelection/Csi2VcFrameStartEvt)"!] | CSI2_EVT_FRAME_START[!ENDIF!][!IF "node:value(./Csi2VcEventsManagement/Csi2VcEventsSelection/Csi2VcFrameEndEvt)"!] | CSI2_EVT_FRAME_END[!ENDIF!][!IF "node:value(./Csi2VcEventsManagement/Csi2VcEventsSelection/Csi2VcLineDoneEvt)"!] | CSI2_EVT_LINE_END[!ENDIF!][!IF "node:value(./Csi2VcEventsManagement/Csi2VcEventsSelection/Csi2VcShortPackedEvt)"!] | CSI2_EVT_SHORT_PACKET[!ENDIF!][!IF "node:value(./Csi2VcEventsManagement/Csi2VcEventsSelection/Csi2VcStartNotZeroEvt)"!] | CSI2_EVT_NEXT_START_NOT_0[!ENDIF!][!IF "(node:value(./Csi2VcEventsManagement/Csi2VcEventsSelection/Csi2VcBitNotToggledEvt) = 'true') and (node:value(../../../../Csi2General/Csi2StatisticDataUsage) = 'true')"!] | CSI2_EVT_BIT_NOT_TOGGLE[!ENDIF!],
    .outputDataMode     = CSI2_VC_BUF_FIFTH_CH_ON[!CALL "GetOutputAuxMask", "type" = "node:value(./Csi2VcAuxiliaryDataSetup/Csi2VcAuxiliaryDataStreamType)"!] | [!"node:value(./Csi2VcOutputMode/Csi2BufDataOutput)"!] | [!IF "node:value(./Csi2VcOutputMode/Csi2VcOutputComplex)"!]CSI2_VC_BUF_COMPLEX_DATA[!ELSE!]CSI2_VC_BUF_REAL_DATA[!ENDIF!] | [!IF "node:value(./Csi2VcOutputMode/Csi2VcOutputFlip)"!]CSI2_VC_BUF_FLIP_SIGN[!ELSE!]CSI2_VC_BUF_NO_FLIP_SIGN[!ENDIF!][!IF "(node:value(./Csi2VcStreamType) = 'CSI2_DATA_TYPE_RAW8') and node:value(./Csi2VcOutputMode/Csi2VcOutputSwap8)"!] | CSI2_VC_BUF_SWAP_RAW8[!ENDIF!][!IF "(node:value(./Csi2VcStreamType) = 'CSI2_DATA_TYPE_RAW16') and node:value(./Csi2VcOutputMode/Csi2VcOutputSwap16)"!] | CSI2_VC_BUF_RAW16_MSB_F[!ENDIF!][!IF "node:value(./Csi2VcOutputMode/Csi2VcOutputWriteAll)"!] | CSI2_VC_BUF_WRITE_ALL_DATA[!ENDIF!],
    .offsetCompReal     = {[!FOR "chnlId" = "0" TO "3"!][!IF "$chnlId != 0"!],[!ENDIF!][!"node:value(concat('./Csi2VcDcOffsets/Csi2VcDcOffsetsReal/Csi2VcDcOffsetReal', $chnlId))"!][!ENDFOR!]},
    .offsetCompImg      = {[!FOR "chnlId" = "0" TO "3"!][!IF "$chnlId != 0"!],[!ENDIF!][!"node:value(concat('./Csi2VcDcOffsets/Csi2VcDcOffsetsComplex/Csi2VcDcOffsetComplex', $chnlId))"!][!ENDFOR!]},[!IF "node:value(../../../../Csi2General/Csi2GPIOUsage)"!]
    .gpio1Mask          = (0u[!IF "node:value(./Csi2VcGpioSetup/Csi2Gpio1Setup/Csi2Gpio1EnaPackAndFrame)"!] |  [!CALL "GetFPEvt", "inValue" = "node:value(./Csi2VcGpioSetup/Csi2Gpio1Setup/Csi2Gpio1PackAndFrameSelection)"!][!ENDIF!][!IF "node:value(./Csi2VcGpioSetup/Csi2Gpio1Setup/Csi2Gpio1EnaPackType)"!] | [!CALL "GetSpecPack", "inValue" = "node:value(./Csi2VcGpioSetup/Csi2Gpio1Setup/Csi2Gpio1PackTypeSelection)"!][!ENDIF!][!IF "node:value(./Csi2VcGpioSetup/Csi2Gpio1Setup/Csi2Gpio1EnaError)"!] | [!CALL "GetErrEvt", "inValue" = "node:value(./Csi2VcGpioSetup/Csi2Gpio1Setup/Csi2Gpio1ErrorSelection)"!][!ENDIF!]),
    .gpio2Mask          = 0u,
    .gpio1EnaMask       = (0u[!IF "node:value(./Csi2VcGpioSetup/Csi2Gpio1Setup/Csi2Gpio1EnaPackAndFrame)"!] | CSI2_REQ_ETRG_ENA_ON_PF[!ENDIF!][!IF "node:value(./Csi2VcGpioSetup/Csi2Gpio1Setup/Csi2Gpio1EnaPackType)"!] | CSI2_REQ_ETRG_ENA_ON_PACKET[!ENDIF!][!IF "node:value(./Csi2VcGpioSetup/Csi2Gpio1Setup/Csi2Gpio1EnaError)"!] | CSI2_REQ_ETRG_ENA_ON_ERROR[!ENDIF!]),
    .gpio2EnaMask       = 0u,[!ENDIF!][!IF "node:value(../../../../Csi2General/Csi2SDMAUsage)"!]
    .sdma1Mask          = (0u[!IF "node:value(./Csi2VcSdmaSetup/Csi2Sdma1Setup/Csi2Sdma1EnaPackAndFrame)"!] |  [!CALL "GetFPEvt", "inValue" = "node:value(./Csi2VcSdmaSetup/Csi2Sdma1Setup/Csi2Sdma1PackAndFrameSelection)"!][!ENDIF!][!IF "node:value(./Csi2VcSdmaSetup/Csi2Sdma1Setup/Csi2Sdma1EnaPackType)"!] | [!CALL "GetSpecPack", "inValue" = "node:value(./Csi2VcSdmaSetup/Csi2Sdma1Setup/Csi2Sdma1PackTypeSelection)"!][!ENDIF!][!IF "node:value(./Csi2VcSdmaSetup/Csi2Sdma1Setup/Csi2Sdma1EnaError)"!] | [!CALL "GetErrEvt", "inValue" = "node:value(./Csi2VcSdmaSetup/Csi2Sdma1Setup/Csi2Sdma1ErrorSelection)"!][!ENDIF!]),
    .sdma2Mask          = 0u,
    .sdma1EnaMask       = (0u[!IF "node:value(./Csi2VcSdmaSetup/Csi2Sdma1Setup/Csi2Sdma1EnaPackAndFrame)"!] | CSI2_REQ_ETRG_ENA_ON_PF[!ENDIF!][!IF "node:value(./Csi2VcSdmaSetup/Csi2Sdma1Setup/Csi2Sdma1EnaPackType)"!] | CSI2_REQ_ETRG_ENA_ON_PACKET[!ENDIF!][!IF "node:value(./Csi2VcSdmaSetup/Csi2Sdma1Setup/Csi2Sdma1EnaError)"!] | CSI2_REQ_ETRG_ENA_ON_ERROR[!ENDIF!]),
    .sdma2EnaMask       = 0u,[!ENDIF!]
    .bufNumLinesTrigger = [!"node:value(./Csi2VcEventsManagement/Csi2VcBufLinesTrigger)"!]
};[!ENDIF!]
[!ENDLOOP!]
/* ==================================================================
 *  End of Auxiliary Data setup for Virtual Channels for this CSI2 unit
 * ================================================================*/
[!ENDIF!]

[!IF "node:value(../../Csi2General/Csi2MetaDataUsage)"!]
 
/* ==================================================================
 *  Start of MetaData setup for Virtual Channels for this CSI2 unit
 * ================================================================*/
    [!LOOP "./Csi2VcParamsList/*"!]
        [!IF "node:value(./Csi2VcMetadataSetup/Csi2VcMetadataUsage)"!]
extern uint8 [!"node:value(./Csi2VcMetadataSetup/Csi2VcMetadataBufMemPointer)"!][];

Csi2_MetaDataParamsType [!"concat('SetupParam_', $setupIndex, '_Params_MetaVC_', node:value(./Csi2VcUsed))"!] = {
    .streamDataType     = [!"node:value(./Csi2VcMetadataSetup/Csi2VcMetadataStreamType)"!],
    .expectedNumBytes   = [!"concat(node:value(./Csi2VcMetadataSetup/Csi2VcMetadataInputLineLen), 'u')"!],
    .expectedNumLines   = [!"concat(node:value(./Csi2VcMetadataSetup/Csi2VcMetadataInputNumLines), 'u')"!],
    .bufNumLines        = [!"concat(node:value(./Csi2VcMetadataSetup/Csi2VcMetadataBufNumLines), 'u')"!],
    .bufLineLen         = [!"concat(node:value(./Csi2VcMetadataSetup/Csi2VcMetadataBufLineLen), 'u')"!],
    .bufDataPtr         = (void*)[!"node:value(./Csi2VcMetadataSetup/Csi2VcMetadataBufMemPointer)"!],
};      [!ENDIF!]
    [!ENDLOOP!]
/* ==================================================================
 *  End of MetaData setup for Virtual Channels for this CSI2 unit
 * ================================================================*/
[!ENDIF!]
 
/* Setup structure for CSI2_UNIT_LEVEL      */
Csi2_SetupParamsType    [!"node:name(.)"!] = {[!VAR "numNodes" = "node:value(./Csi2NumLanesRx)"!]
    .numLanesRx = [!IF "$numNodes = 'One___lane'"!]CSI2_LANE_0[!ELSEIF "$numNodes = 'Two___lanes'"!]CSI2_LANE_1[!ELSEIF "$numNodes = 'Three_lanes'"!]CSI2_LANE_2[!ELSE!]CSI2_LANE_3[!ENDIF!],
    .lanesMapRx = {[!IF "$numNodes = 'One___lane'"!]CSI2_LANE_0[!ELSE!][!CALL "GetLineId", "numLine" = "node:value(./Csi2LanesMapping/Csi2Lane1Mapping)"!], [!CALL "GetLineId", "numLine" = "node:value(./Csi2LanesMapping/Csi2Lane2Mapping)"!][!IF "$numNodes != 'Two___lanes'"!], [!CALL "GetLineId", "numLine" = "node:value(./Csi2LanesMapping/Csi2Lane3Mapping)"!][!IF "$numNodes != 'Three_lanes'"!], [!CALL "GetLineId", "numLine" = "node:value(./Csi2LanesMapping/Csi2Lane4Mapping)"!][!ENDIF!][!ENDIF!][!ENDIF!]},
    .initOptions = [!"node:value(./Csi2UnitInitOptions)"!],[!IF "node:value(../../Csi2General/Csi2StatisticDataUsage)"!][!IF "node:value(../../Csi2General/Csi2DcAutoCompensation)"!]
    .statManagement = [!"node:value(./Csi2StatisticsImplOptions)"!],[!ELSE!]
    .statManagement = CSI2_AUTODC_NO_WITH_STATS,[!ENDIF!][!ENDIF!][!IF "(text:concat(text:grep(node:value('/AUTOSAR/TOP-LEVEL-PACKAGES/Resource/ELEMENTS/Resource/ResourceGeneral/ResourceSubderivative'), 'saf8[A-Za-z_0-9]*'), 'x') != 'x') "!][!IF "node:value(../../Csi2General/Csi2PhyUsageSaf85)"!]
    .pinsSwapMask = CSI2_PINS_NO_SWAP[!IF "node:value(../../Csi2PinsSetup/Csi2PinsSwapClock)"!] | CSI2_PINS_SWAP_CLOCK[!ENDIF!][!IF "node:value(../../Csi2PinsSetup/Csi2PinsSwapLane0)"!] | CSI2_PINS_SWAP_LANE_0[!ENDIF!][!IF "node:value(../../Csi2PinsSetup/Csi2PinsSwapLane1)"!] | CSI2_PINS_SWAP_LANE_1[!ENDIF!],[!ENDIF!][!ENDIF!]
    .rxClkFreq = [!"node:value(./Csi2RxFrequency)"!],
    .vcConfigPtr = { [!FOR "vc" = "0" TO "3"!][!VAR "isThis" = "0"!][!IF "$vc != 0"!], [!ENDIF!][!IF "($vc = 3) and (text:concat(text:grep(node:value(/AUTOSAR/TOP-LEVEL-PACKAGES/Resource/ELEMENTS/Resource/ResourceGeneral/ResourceSubderivative), 'saf8[A-Za-z_0-9]*'), 'x') = 'x') and ((/AUTOSAR/TOP-LEVEL-PACKAGES/Csi2/ELEMENTS/Csi2/Csi2General/Csi2Rfe20Usage) = 'true')"!]&[!"concat('SetupParam_', $setupIndex, '_Params_VC_3')"!][!ELSE!][!FOR "set" = "0" TO "3"!][!IF "node:exists(concat('./Csi2VcParamsList/Csi2VcParamsList_', $set))"!][!IF "node:value(concat('./Csi2VcParamsList/Csi2VcParamsList_', $set, '/Csi2VcUsed')) = $vc"!][!VAR "isThis" = "1"!][!BREAK!][!ENDIF!][!ENDIF!][!ENDFOR!][!IF "$isThis = 0"!]NULL_PTR[!ELSE!]&[!"concat('SetupParam_', $setupIndex, '_Params_VC_', $vc)"!][!ENDIF!][!ENDIF!][!ENDFOR!]},[!IF "node:value(../../Csi2General/Csi2AuxiliaryDataUsage)"!]
    .auxConfigPtr = {[!FOR "vc" = "0" TO "3"!][!VAR "isThis" = "0"!][!IF "$vc != 0"!], [!ENDIF!][!FOR "set" = "0" TO "3"!][!IF "node:exists(concat('./Csi2VcParamsList/Csi2VcParamsList_', $set))"!][!IF "(node:value(concat('./Csi2VcParamsList/Csi2VcParamsList_', $set, '/Csi2VcUsed')) = $vc) and (node:value(concat('./Csi2VcParamsList/Csi2VcParamsList_', $set, '/Csi2VcAuxiliaryDataSetup/Csi2VcAuxiliaryDataUsage')) = 'true')"!][!VAR "isThis" = "1"!][!BREAK!][!ENDIF!][!ENDIF!][!ENDFOR!][!IF "$isThis = 0"!]NULL_PTR[!ELSE!]&[!"concat('SetupParam_', $setupIndex, '_Params_AuxVC_', $vc)"!][!ENDIF!][!ENDFOR!]},[!ENDIF!][!IF "node:value(../../Csi2General/Csi2MetaDataUsage)"!]
    .metaDataPtr = {[!FOR "vc" = "0" TO "3"!][!VAR "isThis" = "0"!][!IF "$vc != 0"!], [!ENDIF!][!FOR "set" = "0" TO "3"!][!IF "node:exists(concat('./Csi2VcParamsList/Csi2VcParamsList_', $set))"!][!IF "(node:value(concat('./Csi2VcParamsList/Csi2VcParamsList_', $set, '/Csi2VcUsed')) = $vc) and (node:value(concat('./Csi2VcParamsList/Csi2VcParamsList_', $set, '/Csi2VcMetadataSetup/Csi2VcMetadataUsage')) = 'true')"!][!VAR "isThis" = "1"!][!BREAK!][!ENDIF!][!ENDIF!][!ENDFOR!][!IF "$isThis = 0"!]NULL_PTR[!ELSE!]&[!"concat('SetupParam_', $setupIndex, '_Params_MetaVC_', $vc)"!][!ENDIF!][!ENDFOR!]},[!ENDIF!][!IF "text:concat(text:grep(node:value('/AUTOSAR/TOP-LEVEL-PACKAGES/Resource/ELEMENTS/Resource/ResourceGeneral/ResourceSubderivative'), 'saf85[A-Za-z_0-9]*'), 'x') != 'x'"!]
    .hfDataManagement = [!IF "node:value(../../Csi2General/Csi2HeaderDataUsage)"!][!IF "node:value(../../Csi2General/Csi2FooterDataUsage)"!]CSI2_ADC_HF[!ELSE!]CSI2_ADC_H_ONLY[!ENDIF!][!ELSE!][!IF "node:value(../../Csi2General/Csi2FooterDataUsage)"!]CSI2_ADC_F_ONLY[!ELSE!]CSI2_ADC_NO[!ENDIF!][!ENDIF!][!ENDIF!]
};

/* ===========================================
 *  End of the params set for CSI2 unit
 * ===========================================*/
[!ENDLOOP!]
