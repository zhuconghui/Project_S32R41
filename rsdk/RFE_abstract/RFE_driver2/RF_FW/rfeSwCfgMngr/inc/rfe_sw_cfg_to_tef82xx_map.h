/**************************************************************************************************
* Copyright 2022 - 2023 NXP
**************************************************************************************************
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
**************************************************************************************************/

/******************************************************************************
 *   Project              : S32R41_RFE_FW
 *   Platform             : S32R41
 *****************************************************************************/

#ifndef RFE_SW_CFG_TO_TEF82XX_MAP_H_
#define RFE_SW_CFG_TO_TEF82XX_MAP_H_

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "bc_types.h"
#include "rfe_sw_cfg_tef82xx.h"
#include "rfe_error.h"
#include "bc_err.h"

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

/**
 * \brief This function convert uint8_t rfeRxGain number in RX_Gain_Control_e
 *
 *
 * \pre
 *
 * \param [in]      rxGain - rfeRxGain number.
 *
 * \return RX_Gain_Control_e - RX gain control
 *
 * \post NIL
 *
 * \ingroup NIL
 */
RX_Gain_Control_e       rfeRxGainMapper(uint8_t rxGain);

/**
 * \brief This function convert rfeRxLpfCutOff_t in SYS_RXLPF_CornerFreq_e
 *
 *
 * \pre
 *
 * \param [in]      rxLPF - List of supported RX LPF Cutoff frequencies.
 *
 * \return SYS_RXLPF_CornerFreq_e - Rx LPF frequency coarse setting
 *
 * \post NIL
 *
 * \ingroup NIL
 */
SYS_RXLPF_CornerFreq_e  rfeRxLPFMapper(rfeRxLpfCutOff_t rxLPF);

/**
 * \brief This function convert rfeRxHpfCutOff_t in SYS_RXHPF_CornerFreq_e
 *
 *
 * \pre
 *
 * \param [in]      rxHPF - List of supported RX HPF Cutoff frequencies.
 *
 * \return SYS_RXHPF_CornerFreq_e - Rx HPF frequency setting
 *
 * \post NIL
 *
 * \ingroup NIL
 */
SYS_RXHPF_CornerFreq_e  rfeRxHPFMapper(rfeRxHpfCutOff_t rxHPF);

/**
 * \brief This function convert uint8_t rfeCafcPllLPF number in CAFC_LoopFilterLUTSel_e
 *
 *
 * \pre
 *
 * \param [in]      LPFLUTSel - rfeCafcPllLPF number.
 *
 * \return CAFC_LoopFilterLUTSel_e - CAFC PLL loop filter LUT type options
 *
 * \post NIL
 *
 * \ingroup NIL
 */
CAFC_LoopFilterLUTSel_e rfeCafcPllLPFLUTSelMApper(uint8_t LPFLUTSel);

/**
 * \brief This function convert uint8_t rfeProfMode number in SYS_ProfID_e
 *
 *
 * \pre
 *
 * \param [in]      profModeSel - rfeProfMode number.
 *
 * \return SYS_ProfID_e - Profile IDs
 *
 * \post NIL
 *
 * \ingroup NIL
 */
SYS_ProfID_e            rfeProfModeSelMapper(uint8_t profModeSel);

/**
 * \brief This function convert uint8_t rfeUseExtTrig number in TE_ChirpTrigMode_e
 *
 *
 * \pre
 *
 * \param [in]      cafcPllLPFSel - rfeUseExtTrig number.
 *
 * \return TE_ChirpTrigMode_e - Chirp trigger mode
 *
 * \post NIL
 *
 * \ingroup NIL
 */
TE_ChirpTrigMode_e      rfeUseExtTrigMapper(uint8_t useExtTrig);

/**
 * \brief This function convert uint8_t rfeVCOSel number in CAFC_VCOBWSel_e
 *
 *
 * \pre
 *
 * \param [in]      cafcPllLPFSel - rfeVCOSel number.
 *
 * \return CAFC_VCOBWSel_e - Chirp PLL VCO Bandwidth options
 *
 * \post NIL
 *
 * \ingroup NIL
 */
CAFC_VCOBWSel_e         rfeVCOSelMapper(uint8_t cafcPllLPFSel);

/**
 * \brief This function convert uint8_t rfeCafcPll in CAFC_PLLLPFSel_e
 *
 *
 * \pre
 *
 * \param [in]      cafcPllLPFSel - rfeCafcPll number.
 *
 * \return CAFC_PLLLPFSel_e - PLL LPF BW configuration selection for a profile
 *
 * \post NIL
 *
 * \ingroup NIL
 */
CAFC_PLLLPFSel_e        rfeCafcPllLPFSelMapper(uint8_t cafcPllLPFSel);

/**
 * \brief This function convert uint8_t in CAFC_LoopFilterLUTSel_e
 *
 *
 * \pre
 *
 * \param [in]      cafcPllLPFSel - cafcLoopFilterLUTSel number.
 *
 * \return CAFC_LoopFilterLUTSel_e - CAFC PLL loop filter LUT type options
 *
 * \post NIL
 *
 * \ingroup NIL
 */
CAFC_LoopFilterLUTSel_e rfeCafcLoopFilterLUTSelMapper(uint8_t cafcLoopFilterLUTSel);

/**
 * \brief This function convert uint8_t virtual channel in SYS_VCN_e
 *
 *
 * \pre
 *
 * \param [in]      virtualChannelNo - virtual channel number.
 *
 * \return SYS_VCN_e - Virtual channel numbers enum
 *
 * \post NIL
 *
 * \ingroup NIL
 */
SYS_VCN_e               rfeVirtualChannelMapper(uint8_t virtualChannelNo);

/**
 * \brief This function convert rfeDDMAModeSel_t in TE_DDMAMod_e
 *
 *
 * \pre
 *
 * \param [in]      ddmaMode - List of supported Phase Rotator DDMA modes.
 *
 * \return TE_DDMAMod_e - DDMA mode selection
 *
 * \post NIL
 *
 * \ingroup NIL
 */
TE_DDMAMod_e            rfeDdmaModeMapper(rfeDDMAModeSel_t ddmaMode);

/**
 * \brief This function convert uint8_t in TE_DDMAMod_e
 *
 *
 * \pre
 *
 * \param [in]      ddmaMode - List of supported Phase Rotator DDMA modes.
 *
 * \return TE_DDMAMod_e - DDMA mode selection
 *
 * \post NIL
 *
 * \ingroup NIL
 */
TE_DDMAMod_e            rfeDdmaModeFromUint8Mapper(uint8_t ddmaMode);

/**
 * \brief This function convert rfePRPCGenMode_t in TE_PRPCGenMode_e
 *
 *
 * \pre
 *
 * \param [in]      finalPCGenMode - List of supported Phase Rotator Phase Code generation modes.
 *
 * \return TE_PRPCGenMode_e - Phase Code generation modes
 *
 * \post NIL
 *
 * \ingroup NIL
 */
TE_PRPCGenMode_e        rfeFinalPCGenModeMapper(rfePRPCGenMode_t finalPCGenMode);

/**
 * \brief This function convert TEF82XX error in RFE error
 *
 *
 * \pre
 *
 * \param [in]      errCode - TEF82XX error.
 *
 * \return rfe_error_t - rfe error with information about which front end report the error
 * 						to see the error need to mask low nibble of byte 2
 * 						to see which front end report the error need to mask all bytes less low nibble of byte 2
 *
 * \post NIL
 *
 * \ingroup NIL
 */
rfe_error_t 			Tef82xxErrToRfeErrorMapper(BC_ERRCODE errCode);

/**
 * \brief This function convert CAFC_VCOBWSel_e in CAFC_PLLLPFSel_e
 *
 *
 * \pre
 *
 * \param [in]      CAFC_VCOBWSel_e - CAFC PLL loop filter LUT type options.
 *
 * \return CAFC_PLLLPFSel_e - PLL LPF BW configuration selection for a profile
 *
 * \post NIL
 *
 * \ingroup NIL
 */
CAFC_PLLLPFSel_e 		rfeCafcPllLPFSelFromVCOMapper(CAFC_VCOBWSel_e vcoSel);

/**
 * \brief This function convert CAFC_VCOBWSel_e in CAFC_LoopFilterLUTSel_e
 *
 *
 * \pre
 *
 * \param [in]      vcoSel - Chirp PLL VCO Bandwidth options.
 *
 * \return CAFC_LoopFilterLUTSel_e - CAFC PLL loop filter LUT type options
 *
 * \post NIL
 *
 * \ingroup NIL
 */
CAFC_LoopFilterLUTSel_e rfeCafcPllLPFLUTSelFromVCOMapper(CAFC_VCOBWSel_e vcoSel);

/**
 * \brief This function convert uint8_t in rfe_chirpSequenceIndex_t
 *
 *
 * \pre
 *
 * \param [in]      chirpSequence - chirp sequence number.
 *
 * \return rfe_chirpSequenceIndex_t - chirp sequence enumerated
 *
 * \post NIL
 *
 * \ingroup NIL
 */
rfe_chirpSequenceIndex_t rfeChirpSequenceMapper(uint8_t chirpSequence);

/**
 * \brief This function convert uint8_t in rfe_chirpSequenceIndex_t
 *
 *
 * \pre
 *
 * \param [in]      chirpProfile - chirp profile number.
 *
 * \return rfe_chirpProfileIndex_t - chirp profile enumerated
 *
 * \post NIL
 *
 * \ingroup NIL
 */
rfe_chirpProfileIndex_t rfeChirpProfileMapper(uint8_t chirpProfile);

/**
 * \brief This function convert uint8_t in rfe_txIndex_t
 *
 *
 * \pre
 *
 * \param [in]      tx - tx number.
 *
 * \return rfe_txIndex_t - tx enumerated
 *
 * \post NIL
 *
 * \ingroup NIL
 */
rfe_txIndex_t rfeTxIndexMapper(uint8_t tx);

/**
 * \brief This function convert uint8_t in rfeRxLpfCutOff_t
 *
 *
 * \pre
 *
 * \param [in]      rxLpfCutOffFrequency - Lpf Cut Off Frequency .
 *
 * \return rfeRxLpfCutOff_t - Rx Lpf Cut Off enumerated
 *
 * \post NIL
 *
 * \ingroup NIL
 */
rfeRxLpfCutOff_t rfeRxLpfCutOffMapper(uint8_t rxLpfCutOffFrequency);

/**
 * \brief This function convert uint8_t in rfeRxHpfCutOff_t
 *
 *
 * \pre
 *
 * \param [in]      rxHpfCutOffFrequency - Hpf Cut Off Frequency .
 *
 * \return rfeRxHpfCutOff_t - Rx Hpf Cut Off enumerated
 *
 * \post NIL
 *
 * \ingroup NIL
 */
rfeRxHpfCutOff_t rfeRxHpfCutOffMapper(uint8_t rxHpfCutOffFrequency);

/**
 * \brief This function convert uint8 in BOOL
 *
 *
 * \pre
 *
 * \param [in]      val - value will be converted .
 *
 * \return BOOL - result of conversion
 *
 * \post NIL
 *
 * \ingroup NIL
 */
BOOL ConvertUint8ToBool(uint8_t val);

/**
 * \brief This function convert uint8 to rfeSwBist_InjectToneMode_t
 *
 *
 * \pre
 *
 * \param [in]      val - value will be converted .
 *
 * \return rfeSwBist_InjectToneMode_t - Inject Tone Mode enumerated
 *
 * \post NIL
 *
 * \ingroup NIL
 */
rfeSwBist_InjectToneMode_t InjectToneModeMapper(uint8_t val);

/**
 * \brief This function convert uint8 to rfe_effectiveSamplingFrequency_t
 *
 *
 * \pre
 *
 * \param [in]      val - value will be converted .
 *
 * \return rfe_effectiveSamplingFrequency_t - Effective Sampling Frequency enumerated
 *
 * \post NIL
 *
 * \ingroup NIL
 */
rfe_effectiveSamplingFrequency_t EffectiveSamplingFrequencyMapper(uint8_t val);

/**
 * \brief This function convert uint8 to rfe_rxGain_t
 *
 *
 * \pre
 *
 * \param [in]      val - value will be converted .
 *
 * \return rfe_rxGain_t - Rx Gain enumerated
 *
 * \post NIL
 *
 * \ingroup NIL
 */
rfe_rxGain_t RxGainMapper(uint8_t val);

/**
 * \brief This function convert uint8 to rfe_virtualChannel_t
 *
 *
 * \pre
 *
 * \param [in]      val - value will be converted .
 *
 * \return rfe_virtualChannel_t - Virtual Channel enumerated
 *
 * \post NIL
 *
 * \ingroup NIL
 */
rfe_virtualChannel_t VirtualChannelMapper(uint8_t val);

/**
 * \brief This function convert uint8 to SYS_IPNum_e
 *
 *
 * \pre
 *
 * \param [in]      val - value will be converted .
 *
 * \return SYS_IPNum_e - SYS_IPNum enumerated
 *
 * \post NIL
 *
 * \ingroup NIL
 */
SYS_IPNum_e SYS_IPNumMapper(uint8_t val);

/**
 * \brief This function convert rfe_rxGain_t to RX_Gain_Control_e
 *
 *
 * \pre
 *
 * \param [in]      val - value will be converted .
 *
 * \return RX_Gain_Control_e - RX_Gain_Control enumerated
 *
 * \post NIL
 *
 * \ingroup NIL
 */
RX_Gain_Control_e RxGainControlMapper(rfe_rxGain_t val);

/**
 * \brief This function convert uint8 to rfeChirpPllVcoBandwidth_t
 *
 *
 * \pre
 *
 * \param [in]      val - value will be converted .
 *
 * \return rfeChirpPllVcoBandwidth_t - ChirpPllVcoBandwidth enumerated
 *
 * \post NIL
 *
 * \ingroup NIL
 */
rfeChirpPllVcoBandwidth_t ChirpPllVcoBandwidthMapper(uint8_t val);
#endif /* RFE_SW_CFG_TO_TEF82XX_MAP_H_ */
