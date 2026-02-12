/*
 * Copyright 2024 NXP
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
[!
/*  Variable defintions to be used for the code generation  */
var configSet     = this[0];
var Csi2General = configSet.getChildById("Csi2GeneralConfiguration");
var Csi2Configs = configSet.getChildById("Csi2SpecificConfiguration.Csi2DriverMainContainer");
var dcOffset, vca, vcm, vstr;
var PinPackage = scriptApi.getProfile().getMcuInfo().getPackage();
var LocalValue = "";

var LaneNames = [ "CSI2_LANE_0", "CSI2_LANE_1", "CSI2_LANE_2", "CSI2_LANE_3" ];
var hfName = [ "CSI2_ADC_NO", "CSI2_ADC_H_ONLY", "CSI2_ADC_F_ONLY", "CSI2_ADC_HF"];   

/* Return the necessary text for the specified lanes used   */
function getLanePoz(nameStr)
{
    switch(nameStr)
    {
        case "One___lane" : return 0;
        case "Two___lanes": return 1;
        case "Three_lanes": return 2;
        case "Four__lanes": return 3;
    }
}

/* Return the Frame/Packet events to be used                   */
function getFPEvent(inStr)
{
    switch(inStr)
    {
        case "Frame_Start":  return "CSI2_REQ_ETRG_EVT_FRAME_START";
        case "Frame_End":    return "CSI2_REQ_ETRG_EVT_FRAME_END";
        case "Packet_Start": return "CSI2_REQ_ETRG_EVT_CHIRP_START";
        case "Packet_End":   return "CSI2_REQ_ETRG_EVT_CHIRP_END";
    }
}

/* Return the Specific Packets to be used                   */
function getSpecPack(inStr)
{
    switch(inStr)
    {
        case "Embedded_Data":       return "CSI2_REQ_ETRG_EVT_PACK_EMBD";
        case "User_Defined_Data":   return "CSI2_REQ_ETRG_EVT_PACK_USER";
        case "RAW_Data":            return "CSI2_REQ_ETRG_EVT_PACK_RAW";
        case "RGB_Data":            return "CSI2_REQ_ETRG_EVT_PACK_RGB";
    }
}

/* Return the Error Event to be used                   */
function getErrEvt(inStr)
{
    switch(inStr)
    {
        case "Line_Count":                  return "CSI2_REQ_ETRG_EVT_ERR_LINECNT";
        case "Line_Length":                 return "CSI2_REQ_ETRG_EVT_ERR_LINLEN";
        case "CRC_or_ECC2bits":             return "CSI2_REQ_ETRG_EVT_ERR_CRCECC";
        case "No_Synchronization_on_DPHY":  return "CSI2_REQ_ETRG_EVT_ERR_NOSYNC";
    }
}

!]


/*===================================================================
 *  Configuration file for Csi2 module
 */
 
[!
    for each (var node in Csi2Configs.getChildren())
    {
        var uId = node.id.toString();
        uId = uId.slice(uId.lastIndexOf(".") + 1);
<code>
/* ==================================================================
 *  Start of a params set $uId$ for CSI2 unit
 * ================================================================*/
</code>

        for each (var vc in node.getChild("Csi2DriverVCContainer").getChildren())
        {
            vca = vc.getChild("Csi2VcAuxiliaryDataSetup");
            vcm = vc.getChild("Csi2VcMetadataSetup");
            dcOffset = vc.getChild("Csi2VcDcOffsets").getChild("Csi2VcDcOffsetsReal");
            LocalValue = vc.getChild("Csi2VcChannels").getValue();
<code>

/* ==================================================================
 *  Start of Virtual Channel $vc.getChild("Csi2VcNumber").getValue()$ parameters for this CSI2 unit
 * ================================================================*/

extern uint8 $vc.getChild("Csi2VcDataBuffer").getChild("Csi2VcBufMemPointer").getValue()$[];

Csi2_VCParamsType $vc.getChild("Csi2VCParamsName").getValue()$ = 
{
    .streamDataType     = $vc.getChild("Csi2VcStreamType").getValue()$,
    .channelsNum        = $vc.getChild("Csi2VcChannels").getValue()$U,
    .expectedNumSamples = $vc.getChild("Csi2VcNumSamples").getValue()$U,
    .expectedNumLines   = $vc.getChild("Csi2VcNumChirps").getValue()$U,
    .bufferReset        = $vc.getChild("Csi2BufResetType").getValue()$,
    .bufNumLines        = $vc.getChild("Csi2VcDataBuffer").getChild("Csi2VcBufNumLines").getValue()$U,
    .bufLineLen         = $vc.getChild("Csi2VcDataBuffer").getChild("Csi2VcBufLineLen").getValue()$U,
    .bufDataPtr         = (void*)$vc.getChild("Csi2VcDataBuffer").getChild("Csi2VcBufMemPointer").getValue()$,
    .vcEventsReq        = 0u$(vc.getChild("Csi2VcEventsManagement").getChild("Csi2VcEventsSelection").getChild("Csi2VcFrameStartEvt").getValue()) ? " | CSI2_EVT_FRAME_START":""$$(vc.getChild("Csi2VcEventsManagement").getChild("Csi2VcEventsSelection").getChild("Csi2VcFrameEndEvt").getValue()) ? " | CSI2_EVT_FRAME_END":""$$(vc.getChild("Csi2VcEventsManagement").getChild("Csi2VcEventsSelection").getChild("Csi2VcLineDoneEvt").getValue()) ? " | CSI2_EVT_LINE_END":""$$(vc.getChild("Csi2VcEventsManagement").getChild("Csi2VcEventsSelection").getChild("Csi2VcShortPackedEvt").getValue()) ? " | CSI2_EVT_SHORT_PACKET":""$$(vc.getChild("Csi2VcEventsManagement").getChild("Csi2VcEventsSelection").getChild("Csi2VcBitNotToggledEvt").getValue() && Csi2General.getChild("Csi2StatisticDataUsage").getValue()) ? " | CSI2_EVT_BIT_NOT_TOGGLE":""$,
    .outputDataMode     = $vc.getChild("Csi2VcOutputMode").getValue()$ | $(vc.getChild("Csi2VcOutputComplex").getValue()) ? "CSI2_VC_BUF_COMPLEX_DATA":"CSI2_VC_BUF_REAL_DATA"$ | $(vc.getChild("Csi2VcOutputFlip").getValue()) ? "CSI2_VC_BUF_FLIP_SIGN":"CSI2_VC_BUF_NO_FLIP_SIGN"$$(vc.getChild("Csi2VcOutputSwap8").getValue() && (vc.getChild("Csi2VcStreamType").getValue() == 'CSI2_DATA_TYPE_RAW8')) ? " | CSI2_VC_BUF_SWAP_RAW8":""$$(vc.getChild("Csi2VcOutputSwap16").getValue() && (vc.getChild("Csi2VcStreamType").getValue() == 'CSI2_DATA_TYPE_RAW16')) ? " | CSI2_VC_BUF_RAW16_MSB_F":""$$(vc.getChild("Csi2VcOutputWriteAll").getValue()) ? " | CSI2_VC_BUF_WRITE_ALL_DATA":""$</code>
            if((Csi2General.getChild("Csi2AuxiliaryDataUsage").getValue()) && (vca.getChild("Csi2VcAuxiliaryDataUsage").getValue()))            
            {
                vstr = "";
                switch(vca.getChild("Csi2VcAuxiliaryDataStreamType").getValue())
                {
                    default : break;
                    case 'CSI2_DATA_TYPE_AUX_0_DR_1OF2' : vstr = " | 0x40"; break;
                    case 'CSI2_DATA_TYPE_AUX_0_DR_3OF4' : vstr = " | 0x80"; break;
                    case 'CSI2_DATA_TYPE_AUX_1_NO_DROP' : vstr = " | 0xc0"; break;
                }
                <code> | CSI2_VC_BUF_FIFTH_CH_ON$vstr$</code>
            }
<code>,
    .offsetCompReal     = { $dcOffset.getChild("Csi2VcDcOffsetReal0").getValue()$, $(LocalValue > 1) ? dcOffset.getChild("Csi2VcDcOffsetReal1").getValue() : 0$, $(LocalValue > 2) ? dcOffset.getChild("Csi2VcDcOffsetReal2").getValue() : 0$, $(LocalValue > 3) ? dcOffset.getChild("Csi2VcDcOffsetReal3").getValue() : 0$ },
    .offsetCompImg      = { </code>
            if(vc.getChild("Csi2VcOutputComplex").getValue())
            {
                dcOffset = vc.getChild("Csi2VcDcOffsets").getChild("Csi2VcDcOffsetsComplex");
                <code>$dcOffset.getChild("Csi2VcDcOffsetComplex0").getValue()$, $(LocalValue > 1) ? dcOffset.getChild("Csi2VcDcOffsetComplex1").getValue() : 0$, $(LocalValue > 2) ? dcOffset.getChild("Csi2VcDcOffsetComplex2").getValue() : 0$, $(LocalValue > 3) ? dcOffset.getChild("Csi2VcDcOffsetComplex3").getValue() : 0$</code>
            }
            else
            {
                <code>0, 0, 0, 0</code>
            }<code>},
</code>
            dcOffset = vc.getChild("Csi2VcGpioSetup");
            if(Csi2General.getChild("Csi2GPIOUsage").getValue())
            {
                <code>    .gpio1Mask          = (0U</code>
                if(dcOffset.getChild("Csi2Gpio1EnaPackAndFrame").getValue())
                {
                    <code> | $getFPEvent(dcOffset.getChild("Csi2Gpio1PackAndFrameSelection").getValue())$</code>
                }
                if(dcOffset.getChild("Csi2Gpio1EnaPackType").getValue())
                {
                    <code> | $getSpecPack(dcOffset.getChild("Csi2Gpio1PackTypeSelection").getValue())$</code>
                }
                if(dcOffset.getChild("Csi2Gpio1EnaError").getValue())
                {
                    <code> | $getErrEvt(dcOffset.getChild("Csi2Gpio1ErrorSelection").getValue())$</code>
                }
                <code>),
    .gpio2Mask          = 0u,
    .gpio1EnaMask       = (0u$dcOffset.getChild("Csi2Gpio1EnaPackAndFrame").getValue() ? " | CSI2_REQ_ETRG_ENA_ON_PF":""$$dcOffset.getChild("Csi2Gpio1EnaPackType").getValue() ? " | CSI2_REQ_ETRG_ENA_ON_PACKET":""$$dcOffset.getChild("Csi2Gpio1EnaError").getValue() ? " | CSI2_REQ_ETRG_ENA_ON_ERROR":""$),
    .gpio2EnaMask       = 0u,
</code>
            }
            dcOffset = vc.getChild("Csi2VcSdmaSetup");
            if(Csi2General.getChild("Csi2SDMAUsage").getValue())
            {
                <code>    .sdma1Mask          = (0U</code>
                if(dcOffset.getChild("Csi2Sdma1EnaPackAndFrame").getValue())
                {
                    <code> | $getFPEvent(dcOffset.getChild("Csi2Sdma1PackAndFrameSelection").getValue())$</code>
                }
                if(dcOffset.getChild("Csi2Sdma1EnaPackType").getValue())
                {
                    <code> | $getSpecPack(dcOffset.getChild("Csi2Sdma1PackTypeSelection").getValue())$</code>
                }
                if(dcOffset.getChild("Csi2Sdma1EnaError").getValue())
                {
                    <code> | $getErrEvt(dcOffset.getChild("Csi2Sdma1ErrorSelection").getValue())$</code>
                }
                <code>),
    .sdma2Mask          = 0u,
    .sdma1EnaMask       = (0u$dcOffset.getChild("Csi2Sdma1EnaPackAndFrame").getValue() ? " | CSI2_REQ_ETRG_ENA_ON_PF":""$$dcOffset.getChild("Csi2Sdma1EnaPackType").getValue() ? " | CSI2_REQ_ETRG_ENA_ON_PACKET":""$$dcOffset.getChild("Csi2Sdma1EnaError").getValue() ? " | CSI2_REQ_ETRG_ENA_ON_ERROR":""$),
    .sdma2EnaMask       = 0u,
</code>
            }<code>
    .bufNumLinesTrigger = $vc.getChild("Csi2VcEventsManagement").getChild("Csi2VcBufLinesTrigger").getValue()$
};

/* ==================================================================
 *  End of Virtual Channels $vc.getChild("Csi2VcNumber").getValue()$ parameters for this CSI2 unit
 * ================================================================*/
 
</code>
            if((Csi2General.getChild("Csi2AuxiliaryDataUsage").getValue()) && (vca.getChild("Csi2VcAuxiliaryDataUsage").getValue()))
            {
                dcOffset = vc.getChild("Csi2VcDcOffsets").getChild("Csi2VcDcOffsetsReal");
<code>
/* ==================================================================
 *  Start of Auxiliary Data setup for Virtual Channels $vc.getChild("Csi2VcNumber").getValue()$ for this CSI2 unit
 * ================================================================*/
 
extern uint8 $vca.getChild("Csi2VcAuxDataBufMemPointer").getValue()$[];

Csi2_VCParamsType $vc.getChild("Csi2VCParamsName").getValue().replace("_VC_","_AuxVC_")$ = 
{
    .streamDataType     = </code>
    switch(vca.getChild("Csi2VcAuxiliaryDataStreamType").getValue())
    {
        case "CSI2_DATA_TYPE_AUX_0_NO_DROP":
            if(vc.getChild("Csi2VcStreamType").getValue() == "CSI2_DATA_TYPE_RAW12")
            {
                <code>CSI2_DATA_TYPE_R12_A0_NO_DROP</code>
            }
            else if(vc.getChild("Csi2VcStreamType").getValue() == "CSI2_DATA_TYPE_RAW16")
            {
                <code>CSI2_DATA_TYPE_R16_A0_NO_DROP</code>
            }
            else
            {
                <code>ONLY RAW12 and RAW16 supported</code>
            }
            break;
        case "CSI2_DATA_TYPE_AUX_0_DR_1OF2":
            if(vc.getChild("Csi2VcStreamType").getValue() == "CSI2_DATA_TYPE_RAW12")
            {
                <code>CSI2_DATA_TYPE_R12_A0_DR_1OF2</code>
            }
            else if(vc.getChild("Csi2VcStreamType").getValue() == "CSI2_DATA_TYPE_RAW16")
            {
                <code>CSI2_DATA_TYPE_R16_A0_DR_1OF2</code>
            }
            else
            {
                <code>ONLY RAW12 and RAW16 supported</code>
            }
            break;
        case "CSI2_DATA_TYPE_AUX_0_DR_3OF4":
            if(vc.getChild("Csi2VcStreamType").getValue() == "CSI2_DATA_TYPE_RAW12")
            {
                <code>CSI2_DATA_TYPE_R12_A0_DR_3OF4</code>
            }
            else if(vc.getChild("Csi2VcStreamType").getValue() == "CSI2_DATA_TYPE_RAW16")
            {
                <code>CSI2_DATA_TYPE_R16_A0_DR_3OF4</code>
            }
            else
            {
                <code>ONLY RAW12 and RAW16 supported</code>
            }
            break;
        case "CSI2_DATA_TYPE_AUX_1_NO_DROP":
            if(vc.getChild("Csi2VcStreamType").getValue() == "CSI2_DATA_TYPE_RAW12")
            {
                <code>CSI2_DATA_TYPE_R12_A1_NO_DROP</code>
            }
            else if(vc.getChild("Csi2VcStreamType").getValue() == "CSI2_DATA_TYPE_RAW16")
            {
                <code>CSI2_DATA_TYPE_R16_A1_NO_DROP</code>
            }
            else
            {
                <code>ONLY RAW12 and RAW16 supported</code>
            }
            break;
    }
    <code>,
    .channelsNum        = $vc.getChild("Csi2VcChannels").getValue()$U,
    .expectedNumSamples = $vc.getChild("Csi2VcNumSamples").getValue()$U,
    .expectedNumLines   = $vc.getChild("Csi2VcNumChirps").getValue()$U,
    .bufferReset        = $vc.getChild("Csi2BufResetType").getValue()$,
    .bufNumLines        = $vca.getChild("Csi2AuxiliaryDataBufNumLines").getValue()$U,
    .bufLineLen         = $vca.getChild("Csi2VcAuxiliaryDataBufLineLen").getValue()$U,
    .bufDataPtr         = (void*)$vca.getChild("Csi2VcAuxDataBufMemPointer").getValue()$,
    .vcEventsReq        = 0u$(vc.getChild("Csi2VcEventsManagement").getChild("Csi2VcEventsSelection").getChild("Csi2VcFrameStartEvt").getValue()) ? " | CSI2_EVT_FRAME_START":""$$(vc.getChild("Csi2VcEventsManagement").getChild("Csi2VcEventsSelection").getChild("Csi2VcFrameEndEvt").getValue()) ? " | CSI2_EVT_FRAME_END":""$$(vc.getChild("Csi2VcEventsManagement").getChild("Csi2VcEventsSelection").getChild("Csi2VcLineDoneEvt").getValue()) ? " | CSI2_EVT_LINE_END":""$$(vc.getChild("Csi2VcEventsManagement").getChild("Csi2VcEventsSelection").getChild("Csi2VcShortPackedEvt").getValue()) ? " | CSI2_EVT_SHORT_PACKET":""$$(vc.getChild("Csi2VcEventsManagement").getChild("Csi2VcEventsSelection").getChild("Csi2VcBitNotToggledEvt").getValue() && Csi2General.getChild("Csi2StatisticDataUsage").getValue()) ? " | CSI2_EVT_BIT_NOT_TOGGLE":""$,
    .outputDataMode     = $vc.getChild("Csi2VcOutputMode").getValue()$ | $(vc.getChild("Csi2VcOutputComplex").getValue()) ? "CSI2_VC_BUF_COMPLEX_DATA":"CSI2_VC_BUF_REAL_DATA"$ | $(vc.getChild("Csi2VcOutputFlip").getValue()) ? "CSI2_VC_BUF_FLIP_SIGN":"CSI2_VC_BUF_NO_FLIP_SIGN"$$(vc.getChild("Csi2VcOutputSwap8").getValue() && (vc.getChild("Csi2VcStreamType").getValue() == 'CSI2_DATA_TYPE_RAW8')) ? " | CSI2_VC_BUF_SWAP_RAW8":""$$(vc.getChild("Csi2VcOutputSwap16").getValue() && (vc.getChild("Csi2VcStreamType").getValue() == 'CSI2_DATA_TYPE_RAW16')) ? " | CSI2_VC_BUF_RAW16_MSB_F":""$$(vc.getChild("Csi2VcOutputWriteAll").getValue()) ? " | CSI2_VC_BUF_WRITE_ALL_DATA":""$</code>
            if((Csi2General.getChild("Csi2AuxiliaryDataUsage").getValue()) && (vca.getChild("Csi2VcAuxiliaryDataUsage").getValue()))            
            {
                vstr = "";
                switch(vca.getChild("Csi2VcAuxiliaryDataStreamType").getValue())
                {
                    default : break;
                    case 'CSI2_DATA_TYPE_AUX_0_DR_1OF2' : vstr = " | 0x40"; break;
                    case 'CSI2_DATA_TYPE_AUX_0_DR_3OF4' : vstr = " | 0x80"; break;
                    case 'CSI2_DATA_TYPE_AUX_1_NO_DROP' : vstr = " | 0xc0"; break;
                }
                <code> | CSI2_VC_BUF_FIFTH_CH_ON$vstr$</code>
            }
<code>,
    .offsetCompReal     = { $dcOffset.getChild("Csi2VcDcOffsetReal0").getValue()$, $(LocalValue > 1) ? dcOffset.getChild("Csi2VcDcOffsetReal1").getValue() : 0$, $(LocalValue > 2) ? dcOffset.getChild("Csi2VcDcOffsetReal2").getValue() : 0$, $(LocalValue > 3) ? dcOffset.getChild("Csi2VcDcOffsetReal3").getValue() : 0$ },
    .offsetCompImg      = { </code>
            if(vc.getChild("Csi2VcOutputComplex").getValue())
            {
                dcOffset = vc.getChild("Csi2VcDcOffsets").getChild("Csi2VcDcOffsetsComplex");
                <code>$dcOffset.getChild("Csi2VcDcOffsetComplex0").getValue()$, $(LocalValue > 1) ? dcOffset.getChild("Csi2VcDcOffsetComplex1").getValue() : 0$, $(LocalValue > 2) ? dcOffset.getChild("Csi2VcDcOffsetComplex2").getValue() : 0$, $(LocalValue > 3) ? dcOffset.getChild("Csi2VcDcOffsetComplex3").getValue() : 0$</code>
            }
            else
            {
                <code>0, 0, 0, 0</code>
            }<code>},
</code>
            dcOffset = vc.getChild("Csi2VcGpioSetup");
            if(Csi2General.getChild("Csi2GPIOUsage").getValue())
            {
                <code>    .gpio1Mask          = (0U</code>
                if(dcOffset.getChild("Csi2Gpio1EnaPackAndFrame").getValue())
                {
                    <code> | $getFPEvent(dcOffset.getChild("Csi2Gpio1PackAndFrameSelection").getValue())$</code>
                }
                if(dcOffset.getChild("Csi2Gpio1EnaPackType").getValue())
                {
                    <code> | $getSpecPack(dcOffset.getChild("Csi2Gpio1PackTypeSelection").getValue())$</code>
                }
                if(dcOffset.getChild("Csi2Gpio1EnaError").getValue())
                {
                    <code> | $getErrEvt(dcOffset.getChild("Csi2Gpio1ErrorSelection").getValue())$</code>
                }
                <code>),
    .gpio2Mask          = 0u,
    .gpio1EnaMask       = (0u$dcOffset.getChild("Csi2Gpio1EnaPackAndFrame").getValue() ? " | CSI2_REQ_ETRG_ENA_ON_PF":""$$dcOffset.getChild("Csi2Gpio1EnaPackType").getValue() ? " | CSI2_REQ_ETRG_ENA_ON_PACKET":""$$dcOffset.getChild("Csi2Gpio1EnaError").getValue() ? " | CSI2_REQ_ETRG_ENA_ON_ERROR":""$),
    .gpio2EnaMask       = 0u,
</code>
            }
            dcOffset = vc.getChild("Csi2VcSdmaSetup");
            if(Csi2General.getChild("Csi2SDMAUsage").getValue())
            {
                <code>    .sdma1Mask          = (0U</code>
                if(dcOffset.getChild("Csi2Sdma1EnaPackAndFrame").getValue())
                {
                    <code> | $getFPEvent(dcOffset.getChild("Csi2Sdma1PackAndFrameSelection").getValue())$</code>
                }
                if(dcOffset.getChild("Csi2Sdma1EnaPackType").getValue())
                {
                    <code> | $getSpecPack(dcOffset.getChild("Csi2Sdma1PackTypeSelection").getValue())$</code>
                }
                if(dcOffset.getChild("Csi2Sdma1EnaError").getValue())
                {
                    <code> | $getErrEvt(dcOffset.getChild("Csi2Sdma1ErrorSelection").getValue())$</code>
                }
                <code>),
    .sdma2Mask          = 0u,
    .sdma1EnaMask       = (0u$dcOffset.getChild("Csi2Sdma1EnaPackAndFrame").getValue() ? " | CSI2_REQ_ETRG_ENA_ON_PF":""$$dcOffset.getChild("Csi2Sdma1EnaPackType").getValue() ? " | CSI2_REQ_ETRG_ENA_ON_PACKET":""$$dcOffset.getChild("Csi2Sdma1EnaError").getValue() ? " | CSI2_REQ_ETRG_ENA_ON_ERROR":""$),
    .sdma2EnaMask       = 0u,
</code>
            }<code>
    .bufNumLinesTrigger = $vc.getChild("Csi2VcEventsManagement").getChild("Csi2VcBufLinesTrigger").getValue()$
};

/* ==================================================================
 *  End of Auxiliary Data setup for Virtual Channels $vc.getChild("Csi2VcNumber").getValue()$ for this CSI2 unit
 * ================================================================*/

</code>
            }
            if((Csi2General.getChild("Csi2MetaDataUsage").getValue()) && (vcm.getChild("Csi2VcMetadataUsage").getValue()))
            {
<code>

/* ==================================================================
 *  Start of MetaData setup for Virtual Channels $vc.getChild("Csi2VcNumber").getValue()$ for this CSI2 unit
 * ================================================================*/
 
extern uint8 $vcm.getChild("Csi2VcMetadataBufMemPointer").getValue()$[];

Csi2_MetaDataParamsType $vc.getChild("Csi2VCParamsName").getValue().replace("_VC_","_MetaVC_")$ = {
    .streamDataType     = $vcm.getChild("Csi2VcMetadataStreamType").getValue()$,
    .expectedNumBytes   = $vcm.getChild("Csi2VcMetadataInputLineLen").getValue()$U,
    .expectedNumLines   = $vcm.getChild("Csi2VcMetadataInputNumLines").getValue()$U,
    .bufNumLines        = $vcm.getChild("Csi2VcMetadataBufNumLines").getValue()$U,
    .bufLineLen         = $vcm.getChild("Csi2VcMetadataBufLineLen").getValue()$U,
    .bufDataPtr         = (void*)$vcm.getChild("Csi2VcMetadataBufMemPointer").getValue()$,
};

/* ==================================================================
 *  End of MetaData setup for Virtual Channels $vc.getChild("Csi2VcNumber").getValue()$ for this CSI2 unit
 * ================================================================*/
 
</code>
            }
        }
<code>

/* Setup structure for CSI2_UNIT_LEVEL      */
Csi2_SetupParamsType    $node.getChild("Csi2DriverParamsName").getValue()$ = {
    .numLanesRx       = $LaneNames[getLanePoz(node.getChild("Csi2NumLanesRx").getValue())]$,
    .lanesMapRx       = {$LaneNames[node.getChild("Csi2LanesMapping").getChild("Csi2Lane1Mapping").getValue() - 1]$, $LaneNames[node.getChild("Csi2LanesMapping").getChild("Csi2Lane2Mapping").getValue() - 1]$</code>
        if(PinPackage.match("SAF") != "SAF")
        {
            <code>, $LaneNames[node.getChild("Csi2LanesMapping").getChild("Csi2Lane3Mapping").getValue() - 1]$, $LaneNames[node.getChild("Csi2LanesMapping").getChild("Csi2Lane4Mapping").getValue() - 1]$</code>
        }
    <code>},
</code>
        if(PinPackage.match("SAF") == "SAF")
        {
            LocalValue = 0;
            if(Csi2General.getChild("Csi2HeaderDataUsage").getValue())
            {
                LocalValue++;
            }
            if(Csi2General.getChild("Csi2FooterDataUsage").getValue())
            {
                LocalValue += 2;
            }
            LocalValue = hfName[LocalValue];
<code>
    .hfDataManagement = $LocalValue$,
</code>

            if(node.getChild("Csi2RxFrequency").getValue() != 0)
            {
<code>
    .pinsSwapMask     = CSI2_PINS_NO_SWAP$Csi2General.getChild("Csi2PinsSetup").getChild("Csi2PinsSwapClock").getValue()?  " | CSI2_PINS_SWAP_CLOCK":""$$Csi2General.getChild("Csi2PinsSetup").getChild("Csi2PinsSwapLane0").getValue()? " | CSI2_PINS_SWAP_LANE_0":""$$Csi2General.getChild("Csi2PinsSetup").getChild("Csi2PinsSwapLane1").getValue()? " | CSI2_PINS_SWAP_LANE_1":""$,
</code>
            }
        }
<code>

    .initOptions      = $node.getChild("Csi2UnitInitOptions").getValue()$,
</code>
        if(Csi2General.getChild("Csi2StatisticDataUsage").getValue())
        {
            if(Csi2General.getChild("Csi2DcAutoCompensation").getValue())
            {
<code>
    .statManagement   = $node.getChild("Csi2StatisticsImplOptions").getValue()$,
</code>
            }
            else
            {
<code>
    .statManagement   = CSI2_AUTODC_NO_WITH_STATS,
</code>
            }
        }
<code>
    .rxClkFreq        = $node.getChild("Csi2RxFrequency").getValue()$,
    .vcConfigPtr      = { </code>
        LocalValue = [ "NULL_PTR", "NULL_PTR", "NULL_PTR", "NULL_PTR" ];
        for each (var vc in node.getChild("Csi2DriverVCContainer").getChildren())
        {
            LocalValue[vc.getChild("Csi2VcNumber").getValue()] = "&".concat(vc.getChild("Csi2VCParamsName").getValue());
        }
<code> $LocalValue[0]$, $LocalValue[1]$, $LocalValue[2]$, $LocalValue[3]$ },
</code>
        if(Csi2General.getChild("Csi2AuxiliaryDataUsage").getValue())
        {
            LocalValue = [ "NULL_PTR", "NULL_PTR", "NULL_PTR", "NULL_PTR" ];
            for each (var vc in node.getChild("Csi2DriverVCContainer").getChildren())
            {
                if(vc.getChild("Csi2VcAuxiliaryDataSetup").getChild("Csi2VcAuxiliaryDataUsage").getValue())
                {
                    LocalValue[vc.getChild("Csi2VcNumber").getValue()] = "&".concat(vc.getChild("Csi2VCParamsName").getValue().replace("_VC_","_AuxVC_"));
                }
            }
<code>
    .auxConfigPtr     = {  $LocalValue[0]$, $LocalValue[1]$, $LocalValue[2]$, $LocalValue[3]$ },
</code>
        }
        if(Csi2General.getChild("Csi2MetaDataUsage").getValue())
        {
            LocalValue = [ "NULL_PTR", "NULL_PTR", "NULL_PTR", "NULL_PTR" ];
            for each (var vc in node.getChild("Csi2DriverVCContainer").getChildren())
            {
                if(vc.getChild("Csi2VcMetadataSetup").getChild("Csi2VcMetadataUsage").getValue())
                {
                    LocalValue[vc.getChild("Csi2VcNumber").getValue()] = "&".concat(vc.getChild("Csi2VCParamsName").getValue().replace("_VC_","_MetaVC_"));
                }
            }
<code>
    .metaDataPtr      = {  $LocalValue[0]$, $LocalValue[1]$, $LocalValue[2]$, $LocalValue[3]$ },
</code>
        }
<code>
};

/* ===========================================
 *  End of the params set for CSI2 unit $uId$
 * ===========================================*/
</code>
    }
!]
