/*
 * Copyright 2016,2019-2022 NXP
 * NXP Confidential. This software is owned or controlled by NXP and may only
 * be used strictly in accordance with the applicable license terms. By
 * expressly accepting such terms or by downloading, installing, activating
 * and/or otherwise using the software, you are agreeing that you have read,
 * and that you agree to comply with and are bound by, such license terms. If
 * you do not agree to be bound by the applicable license terms, then you may
 * not retain, install, activate or otherwise use the software.
 */

/**
@file bc_err.h

@version

@brief Barracuda API HAL(Hardware Abstraction Layer) header file

This is the header file for Barracuda APIs. All exported API can be found in
this file.
*/

#ifndef DPERR_H
#define DPERR_H



#include <stdint.h>
#include <stddef.h>

#if defined(__cplusplus)
extern "C"
{
#endif


typedef uint32_t BC_ERRCODE;

// ***** General no errors *****
#define BC_ERR_NOERROR                 (0u)
//Error code is formated in this way:
//  A 24-bit hex unsigned number: 0xMMEEEu
//      MM: 8-bits for module address, as preallocated as below
//      EEE: 12-bits for actual error code for that specific SW module
//
//      Note: allocation of MM is not continuous.


// ***** General Error Codes (0x50xxxu) *****

/// Input parameters out of range
#define BC_ERR_INPUTOUTOFRANGE          (0x50001u)
/// Access to a not-existing function 
#define BC_ERR_FUNCNOTEXIST             (0x50002u)
/// CRC error injection failure
#define BC_ERR_FAILTOINJECTCRCERR       (0x50003u)
/// Serializer mode other than MIPI/LVDS selected
#define BC_ERR_WRONGINTERFACE           (0x50004u)
/// Access to an OTP disabled IP
#define BC_ERR_IPDISABLED               (0x50005u)

// ***** SYS Error Codes (0x51xxx) *****
#define BC_ERR_SYS_IPHASNOATBCONNECTION         (0x51001u)
#define BC_ERR_SYS_CANNOTFINDCAFCDACCODE        (0x51002u)
/* Gap */
#define BC_ERR_SYS_ADCINVALID                   (0x51005u)
#define BC_ERR_SYS_FILEERROR                    (0x51006u)
#define BC_ERR_SYS_JSONSTRINGNOTEXISTED         (0x51007u)
/* Gap */
/// Failed reading temperature data of TX after multiple retries
#define BC_ERR_SYS_TX_TEMP_READ_TIMEOUT         (0x5100Au)
/// MCLK for serializer(LVDS/MIPI) is not within range. Expected MCLK is 480MHz with a minor drift of +/- 500KHz.  
#define BC_ERR_SYS_MCLK_INTEGRITY_FAILED        (0x5100Bu)
#define BC_ERR_SYS_WRONG_APPCONFIG              (0x5100Cu)
/// Invalid CRC trigger event is given as input
#define BC_ERR_SYS_INVALID_INPUT                (0x5100Du)
/* Gap */
#define BC_ERR_SYS_WRONG_PROFILE_NO_RECOVERY    (0x5100Fu)
#define BC_ERR_SYS_ERRORRECOVERY_FAILED         (0x51010u)
/// This error is related to CAFC sensor integrity check where known errors are injected and checked whether corresponding CAFC errors are triggered. This error is reported when VCOLevelMinErr is FALSE while TRUE is expected.
#define BC_ERR_SYS_CAFCINTEGRITY_CHECK_LEVEL    (0x51011u)
/// This error is related to CAFC sensor integrity check where known errors are injected and checked whether corresponding CAFC errors are triggered. This error is reported when PLLUnlockErr is FALSE while TRUE is expected.
#define BC_ERR_SYS_CAFCINTEGRITY_CHECK_UNLOCK   (0x51012u)
/* Gap */
/// Wrong data interface configuration. LVDS or MIPI interface need to be set in App configuration before initializing data interface
#define BC_ERR_SYS_WRONG_DATAINTERFACE_CONFIG   (0x51014u)
/// ERROR_N Pin should be high at the end of successful startup sequence completion. This error code indicates there are some errors and ERROR_N Pin is low.
#define BC_ERR_SYS_ERROR_N                      (0x51016u)
#define BC_ERR_SYS_INVALID_PROFILE              (0x51017u)
#define BC_ERR_SYS_FAULTINJECTIONRFAIL          (0x51018u)
#define BC_ERR_SYS_WRONG_MID_NO_RECOVERY        (0x51019u)
#define BC_ERR_SYS_SPIACCESS_CHECKFAIL          (0x5101Au)
/// Failed reading temperature data of CAFC after multiple retries
#define BC_ERR_SYS_CAFC_TEMP_READ_TIMEOUT       (0x5101Bu)
/* Gap */

/// CAFC module has to be disabled for slave device. This error occur if the CAFC module is enable for slave device
#define BC_ERR_SYS_SLAVE_WRONG_APPCONFIG        (0x51026u)
/* Gap */
#define BC_ERR_SYS_SUBBANDINC_OUTOFRANGE        (0x5105Cu)
/* Gap */
#define BC_ERR_SYS_PTR_ADDR_NULL                (0x51061u)
#define BC_ERR_SYS_AAFC_AUTO_NOT_SUPPORTED      (0x51062u)
/// RawNumSample is the chirp active or acquisition time. This is affected by the decimation factor. The error means RawNumSample is not a factor of decimation or zero.
#define BC_ERR_SYS_RAW_NUM_SAMPLE_INVALID       (0x51063u)
/// Reset time should be less or equal to chirp active time. 
#define BC_ERR_SYS_INVALID_RESET_TIME           (0x51064u)
/// Calculated total (full ramp) bandwidth = BW TSettle + BW Acquisition + BW TJumpback, is going out of range for corresponding VCO bandwidth.
#define BC_ERR_SYS_TOTAL_BW_OUTOFRANGE          (0x51065u)
/// CAFC integrity check failure due to PLL unlock and/or VCO level min error, API is not able to clear the unlock and/or VCO level min error
#define BC_ERR_SYS_CAFCINTEGRITY_CHECK_FAILED   (0x51066u)
/// Restoring of CHIRP_GLOBAL_CONTROL register failed while CAFC integrity check 
#define BC_ERR_SYS_RESTORE_CHIRP_GLOBAL_FAILED   (0x51067u)
/// ISM register CRC error is reported, even after clearing the error injection
#define BC_ERR_SYS_REGCRC_ISMMODULE_ERROR_SET   (0x51068u)
#define BC_ERR_SYS_REGCRC_TRIGGER_FAILED   (0x51069u)
/// Write check failed while setting defaults for TX_CONTROL_ENABLE register
#define BC_ERR_SYS_TX_CTRL_ENABLE_WRITECHECK_BASE     (0x51070u)
#define BC_ERR_SYS_TX1_CTRL_ENABLE_WRITECHECK         (0x51071u)
#define BC_ERR_SYS_TX2_CTRL_ENABLE_WRITECHECK         (0x51072u)  
#define BC_ERR_SYS_TX1_TX2_CTRL_ENABLE_WRITECHECK     (0x51073u)
#define BC_ERR_SYS_TX3_CTRL_ENABLE_WRITECHECK         (0x51074u)
#define BC_ERR_SYS_TX1_TX3_CTRL_ENABLE_WRITECHECK     (0x51075u)
#define BC_ERR_SYS_TX2_TX3_CTRL_ENABLE_WRITECHECK     (0x51076u)
#define BC_ERR_SYS_TX1_TX2_TX3_CTRL_ENABLE_WRITECHECK (0x51077u)

/// LOI Ball Break error 
#define BC_ERR_SYS_LOI_IN_BALL_BREAK_DETECTED              (0x51078u)
#define BC_ERR_SYS_LOI_OUT_BALL_BREAK_DETECTED             (0x51079u)

// ***** ALG Error Codes (0x52xxx) *****
#define BC_ERR_ALG_DUMMYERROR            (0x52001u) //dummy, change this name when you define the first error

// **** BC_SPI Error Codes (0x53xxx) *****
#define BC_ERR_SPI_WRTRDCRCERROR        (0x53001u)
#define BC_ERR_SPI_WRTCHECKFAIL         (0x53002u)
#define BC_ERR_SPI_READFAIL             (0x53003u)
//0x54xxx is used by PLF layer.

// ***** CC Error Codes (0x00xxx) ***** 
#define BC_ERR_CC_SYSCONFNOTSET             (0x00001u)
#define BC_ERR_CC_PTR_ADDR_NULL             (0x00002u)

// ***** LVDS Error Codes (0x01xxx) *****
/// LVDS test mode setting is incorrect
#define BC_ERR_LVDS_INVALID_INPUT           (0x01001u)
#define BC_ERR_LVDS_PTR_ADDR_NULL           (0x01002u)
#define BC_ERR_LVDS_SAMPPULSE_SHIFT_INVALID (0x01003u)
#define BC_ERR_LVDS_CLK_EDGE_INVALID        (0x01004u)
#define BC_ERR_LVDS_ADCCLK_FROM_INVALID     (0x01005u)
#define BC_ERR_LVDS_FREQ_COUNTER_DEVIATION  (0x01006u)
#define BC_ERR_LVDS_COUNT_PERIOD_INVALID    (0x01007u)
/// Busy wait read of Frequency Counter register failed after max retries
#define BC_ERR_LVDS_FREQCOUNTTIMEOUT        (0x01008u)
/// Restoring of the frequency counter register failed
#define BC_ERR_LVDS_RESTORE_FREQ_COUNTER    (0x01009u)

// ***** MIPI Error Codes (0x02xxx) *****
#define BC_ERR_MIPI_DEVICE_READY_TIMEOUT    (0x02001u)
/// Busy wait read of Frequency Counter register failed after max retries
#define BC_ERR_MIPI_FREQCOUNTTIMEOUT        (0x02002u)  
/// CountPeriod Period in us for doing the frequency measurement is out of range
#define BC_ERR_MIPI_FREQCNT_OUTOFRANGE      (0x02003u) 
#define BC_ERR_MIPI_PTR_ADDR_NULL           (0x02004u)
/// Restoring of the frequency counter register failed
#define BC_ERR_MIPI_RESTORE_FREQ_COUNTER    (0x02005u)

// ***** TE Error Codes (0x04xxx) *****
#define BC_ERR_TE_PRSAFETYDELAY         (0x04001u)
#define BC_ERR_TE_PRCALIBDELAY          (0x04002u) 
#define BC_ERR_TE_RXACTIVEDELAY         (0x04003u) 
/// Invalid HPF Reset Release Delay from reference point
#define BC_ERR_TE_HPFRESETDELAY         (0x04004u) 
#define BC_ERR_TE_DCPOWONDELAY          (0x04005u) 
/// Invalid safety monitor delay from reference point
#define BC_ERR_TE_DCSAFETYDELAY         (0x04006u) 
#define BC_ERR_TE_DDMASETTING           (0x04007u) 
#define BC_ERR_TE_DDMAMODE              (0x04008u)  
#define BC_ERR_TE_JUMPBACK              (0x04009u) 
/// Either TX or RX group delay is greater than DC power on delay
#define BC_ERR_TE_TXRXGRPDELAY          (0x0400Au)  
#define BC_ERR_TE_FINEGRPDELAY          (0x0400Bu)  
/// Invalid Profile or profile combination
#define BC_ERR_TE_PROFILELIST           (0x0400Cu)  
#define BC_ERR_TE_PRCALTIMEOUT          (0x0400Du)  
#define BC_ERR_TE_BIASDELAY             (0x0400Eu)  
#define BC_ERR_TE_INPUTNULL             (0x0400Fu)
/// Invalid profile repeat count 
#define BC_ERR_TE_PRFREPEATCNT          (0x04010u) 
#define BC_ERR_TE_CHIRPSEQINTERVAL      (0x04011u) 
#define BC_ERR_TE_SETTLETIME            (0x04012u) 
#define BC_ERR_TE_OUTPUTSAMPRATE        (0x04013u) 
#define BC_ERR_TE_CHIRPINTERVAL         (0x04014u) 
#define BC_ERR_TE_VIRTUALCHANNEL        (0x04015u) 
#define BC_ERR_TE_DWELLTIME             (0x04016u)
/// Invalid Transmission ON delay from timing reference point
#define BC_ERR_TE_DELAYFROMREFPT        (0x04017u)
/// Polling for the completion of chirp sequence failed after multiple retries
#define BC_ERR_TE_FREQCNTTIMEOUT        (0x04018u)
#define BC_ERR_TE_CHIRPSEQUENCE         (0x04019u)
#define BC_ERR_TE_CHIRPTRGMODE          (0x0401Au)
/* Gap */
#define BC_ERR_TE_PHASEOUTOFRANGE       (0x0401Eu)  
#define BC_ERR_TE_HPFRESETWRONGTRIGGERPOINT (0x0401Fu)

/// Write check failed while setting defaults for TX_CAL_ENABLE register
#define BC_ERR_TE_TX_CAL_ENABLE_WRITECHECK_BASE     (0x04020u)
#define BC_ERR_TE_TX1_CAL_ENABLE_WRITECHECK         (0x04021u)
#define BC_ERR_TE_TX2_CAL_ENABLE_WRITECHECK         (0x04022u)  
#define BC_ERR_TE_TX1_TX2_CAL_ENABLE_WRITECHECK     (0x04023u)
#define BC_ERR_TE_TX3_CAL_ENABLE_WRITECHECK         (0x04024u)
#define BC_ERR_TE_TX1_TX3_CAL_ENABLE_WRITECHECK     (0x04025u)
#define BC_ERR_TE_TX2_TX3_CAL_ENABLE_WRITECHECK     (0x04026u)
#define BC_ERR_TE_TX1_TX2_TX3_CAL_ENABLE_WRITECHECK (0x04027u)
/// Write check failed while setting chirp enable 
#define BC_ERR_TE_CHIRP_ENABLE_WRITECHECK_FAILED    (0x04028u) 

// ***** SC Error Codes (0x05xxx) *****
#define BC_ERR_SC_PROFILE                   (0x05001u) 
#define BC_ERR_SC_OPERATING_FREQ_OUTOFRANGE (0x05002u)
#define BC_ERR_SC_PTR_ADDR_NULL             (0x05003u)
/// Frequency Drift value greater than the chirp bandwidth
#define BC_ERR_SC_INPUT_FREQ_DRIFT_INVALID  (0x05004u)
/// Bandwidth is outside the range what hardware is capable of
#define BC_ERR_SC_USED_BW_OUTOFRANGE        (0x05005u)
/// Ramp time outside the practical range. 
#define BC_ERR_SC_RAMP_TIME_OUTOFRANGE      (0x05006u)
/// Reset time outside the practical range. 
#define BC_ERR_SC_RESET_TIME_OUTOFRANGE     (0x05007u)

// ***** CAFC Error Codes (0x06xxx) *****
#define BC_ERR_CAFC_FREQCNTTIMEOUT       (0x06001u)
#define BC_ERR_CAFC_SBOUTOFRANGE         (0x06002u)
#define BC_ERR_CAFC_INPUTOUTOFRANGE      (0x06003u)
/// Wrong VCO selected
#define BC_ERR_CAFC_BWOUTOFRANGE         (0x06004u)
/// Compensated slice number is 0, which is is invalid
#define BC_ERR_CAFC_CONFIGLOOPFILTERFAIL (0x06005u)
#define BC_ERR_CAFC_LOOPBWOUTOFRANGE     (0x06006u)
#define BC_ERR_CAFC_PTR_ADDR_NULL        (0x06007u) 
#define BC_ERR_CAFC_WRONGPROFILEID       (0x06008u) 
/// Busy status for aafc, kvco and dvdt
#define BC_ERR_CAFC_AAFCKVCODVDT_TIMEOUT (0x06009u)
#define BC_ERR_CAFC_VCOCALIB_AAFCFAIL    (0x0600Au)
#define BC_ERR_CAFC_VCOCALIB_KVCODVDTFAIL (0x0600Bu)
#define BC_ERR_CAFC_NOSTOREINPROFILESELECTED (0x0600Cu)
#define BC_ERR_CAFC_DVDT_COUNT_WRONG      (0x0600Du)
#define BC_ERR_CAFC_KVCO_COUNT_STATUS_ERR       (0x0600Eu)
#define BC_ERR_CAFC_WRONG_KVCO                  (0x06010u)
#define BC_ERR_CAFC_WRONG_ACQUISITION_DURATION  (0x06011u)

// ***** ADC Error Codes (0x07xxx) *****
/// ADC calibration failure
#define BC_ERR_ADC_CALIBRATIONFAILED        (0x07001u) 
/// ADC calibration timeout failure
#define BC_ERR_ADC_CALIBRATIONTIMEOUT       (0x07002u) 
/// ADC calibration Check not done
#define BC_ERR_ADC_CALIBRATIONCHECKNOTDONE  (0x07003u) 

// ***** GBIAS Error Codes (0x09xxx) *****
#define BC_ERR_GBIAS_DUMMY     (0x09001u) 

// ***** LOI Error Codes (0x0Axxx) *****
/* Gap */
/// LO LUT Gain code out of range
#define BC_ERR_LOI_LUTGAINCODE_OUTOFRANGE       (0x0A003u) 
/* Gap */
/// LO Gain cal busy
#define BC_ERR_LOI_CAL_BUSY                     (0x0A005u) 
/// LO Gain cal error
#define BC_ERR_LOI_CAL_ERROR                    (0x0A006u) 
#define BC_ERR_LOI_PTR_ADDR_NULL                (0x0A007u) 

// ***** MCLK Error Codes (0x0Cxxx) *****
/* Gap */
#define BC_ERR_MCLK_PLL_CALIBRATION_FAILED          (0x0C003u)
#define BC_ERR_MCLK_PLL_CALIBRATION_NOTFINISHED     (0x0C004u)

#define BC_ERR_MCLK_MSPC_CALIBRATION_ERROR          (0x0C006u)
#define BC_ERR_MCLK_MSPCTIMEOUT                     (0x0C007u)
/* Gap */
#define BC_ERR_MCLK_PTR_ADDR_NULL                   (0x0C00Au)

// ***** RX Error Codes (0x0Dxxx) *****
#define BC_ERR_RX_INPUTOUTOFRANGE       	(0x0D001u) 
#define BC_ERR_RX_CAL_BUSY              	(0x0D002u)
#define BC_ERR_RX1_CAL_BUSY             	(0x0D003u)
#define BC_ERR_RX2_CAL_BUSY             	(0x0D004u)
#define BC_ERR_RX3_CAL_BUSY             	(0x0D005u)
#define BC_ERR_RX4_CAL_BUSY             	(0x0D006u)
#define BC_ERR_RX_CAL_ERROR             	(0x0D007u)
#define BC_ERR_RX1_CAL_ERROR            	(0x0D008u)
#define BC_ERR_RX2_CAL_ERROR            	(0x0D009u)
#define BC_ERR_RX1_RX2_CAL_ERROR        	(0x0D00Au)
#define BC_ERR_RX3_CAL_ERROR            	(0x0D00Bu)
#define BC_ERR_RX1_RX3_CAL_ERROR        	(0x0D00Cu)
#define BC_ERR_RX2_RX3_CAL_ERROR        	(0x0D00Du)
#define BC_ERR_RX1_RX2_RX3_CAL_ERROR    	(0x0D00Eu)
#define BC_ERR_RX4_CAL_ERROR            	(0x0D00Fu)
#define BC_ERR_RX1_RX4_CAL_ERROR            (0x0D010u)
#define BC_ERR_RX2_RX4_CAL_ERROR            (0x0D011u)
#define BC_ERR_RX1_RX2_RX4_CAL_ERROR        (0x0D012u)
#define BC_ERR_RX3_RX4_CAL_ERROR            (0x0D013u)
#define BC_ERR_RX1_RX3_RX4_CAL_ERROR        (0x0D014u)
#define BC_ERR_RX2_RX3_RX4_CAL_ERROR        (0x0D015u)
#define BC_ERR_RX1_RX2_RX3_RX4_CAL_ERROR    (0x0D016u)
#define BC_ERR_RX_PTR_ADDR_NULL             (0x0D017u)
#define BC_ERR_RX_WRNG_CAL_TARGET_OFFSET    (0x0D018u)
/// Write check failed while enabling Functional Safety Mon Level for RX  
#define BC_ERR_RX_FUSA_ENABLE_WRITECHECK_BASE           (0x0D020u)
#define BC_ERR_RX1_FUSA_ENABLE_WRITECHECK               (0x0D021u)
#define BC_ERR_RX2_FUSA_ENABLE_WRITECHECK               (0x0D022u)  
#define BC_ERR_RX1_RX2_FUSA_ENABLE_WRITECHECK           (0x0D023u)
#define BC_ERR_RX3_FUSA_ENABLE_WRITECHECK               (0x0D024u)
#define BC_ERR_RX1_RX3_FUSA_ENABLE_WRITECHECK           (0x0D025u)
#define BC_ERR_RX2_RX3_FUSA_ENABLE_WRITECHECK           (0x0D026u)
#define BC_ERR_RX1_RX2_RX3_FUSA_ENABLE_WRITECHECK       (0x0D027u)   
#define BC_ERR_RX4_FUSA_ENABLE_WRITECHECK               (0x0D028u)   
#define BC_ERR_RX1_RX4_FUSA_ENABLE_WRITECHECK           (0x0D029u)   
#define BC_ERR_RX2_RX4_FUSA_ENABLE_WRITECHECK           (0x0D02Au)   
#define BC_ERR_RX1_RX2_RX4_FUSA_ENABLE_WRITECHECK       (0x0D02Bu)   
#define BC_ERR_RX3_RX4_FUSA_ENABLE_WRITECHECK           (0x0D02Cu)   
#define BC_ERR_RX1_RX3_RX4_FUSA_ENABLE_WRITECHECK       (0x0D02Du)   
#define BC_ERR_RX2_RX3_RX4_FUSA_ENABLE_WRITECHECK       (0x0D02Eu)   
#define BC_ERR_RX1_RX2_RX3_RX4_FUSA_ENABLE_WRITECHECK   (0x0D02Fu)  
/// Write check failed for Rx BBD Enable
#define BC_ERR_RX_BBD_ENABLE_WRITECHECK_BASE            (0x0D030u)
#define BC_ERR_RX1_BBD_ENABLE_WRITECHECK               (0x0D031u)
#define BC_ERR_RX2_BBD_ENABLE_WRITECHECK               (0x0D032u)  
#define BC_ERR_RX1_RX2_BBD_ENABLE_WRITECHECK           (0x0D033u)
#define BC_ERR_RX3_BBD_ENABLE_WRITECHECK               (0x0D034u)
#define BC_ERR_RX1_RX3_BBD_ENABLE_WRITECHECK           (0x0D035u)
#define BC_ERR_RX2_RX3_BBD_ENABLE_WRITECHECK           (0x0D036u)
#define BC_ERR_RX1_RX2_RX3_BBD_ENABLE_WRITECHECK       (0x0D037u)   
#define BC_ERR_RX4_BBD_ENABLE_WRITECHECK               (0x0D038u)   
#define BC_ERR_RX1_RX4_BBD_ENABLE_WRITECHECK           (0x0D039u)   
#define BC_ERR_RX2_RX4_BBD_ENABLE_WRITECHECK           (0x0D03Au)   
#define BC_ERR_RX1_RX2_RX4_BBD_ENABLE_WRITECHECK       (0x0D03Bu)   
#define BC_ERR_RX3_RX4_BBD_ENABLE_WRITECHECK           (0x0D03Cu)   
#define BC_ERR_RX1_RX3_RX4_BBD_ENABLE_WRITECHECK       (0x0D03Du)   
#define BC_ERR_RX2_RX3_RX4_BBD_ENABLE_WRITECHECK       (0x0D03Eu)   
#define BC_ERR_RX1_RX2_RX3_RX4_BBD_ENABLE_WRITECHECK   (0x0D03Fu) 

// ***** TX Error Codes (0x11xxx) *****
#define BC_ERR_TX_INPUTOUTOFRANGE       (0x11001u) 
#define BC_ERR_TX_PRCADCTIMEOUT         (0x11002u)
#define BC_ERR_TX_SENSORFITFAIL         (0x11003u)
#define BC_ERR_TX_CAL_BUSY              (0x11004u)
#define BC_ERR_TX1_CAL_BUSY             (0x11005u)
#define BC_ERR_TX2_CAL_BUSY             (0x11006u)
#define BC_ERR_TX3_CAL_BUSY             (0x11007u)
#define BC_ERR_TX_CAL_ERROR             (0x11008u)
#define BC_ERR_TX1_CAL_ERROR            (0x11009u)
#define BC_ERR_TX2_CAL_ERROR            (0x1100Au)
#define BC_ERR_TX1_TX2_CAL_ERROR        (0x1100Bu)
#define BC_ERR_TX3_CAL_ERROR            (0x1100Cu)
#define BC_ERR_TX1_TX3_CAL_ERROR        (0x1100Du)
#define BC_ERR_TX2_TX3_CAL_ERROR        (0x1100Eu)
#define BC_ERR_TX1_TX2_TX3_CAL_ERROR    (0x1100Fu)
#define BC_ERR_TX_SAFETY_BUSY              (0x11010u)
#define BC_ERR_TX1_SAFETY_BUSY             (0x11011u)
#define BC_ERR_TX2_SAFETY_BUSY             (0x11012u)
#define BC_ERR_TX3_SAFETY_BUSY             (0x11013u)
#define BC_ERR_TX_SAFETY_ERROR             (0x11014u)
#define BC_ERR_TX1_SAFETY_ERROR            (0x11015u)
#define BC_ERR_TX2_SAFETY_ERROR            (0x11016u)
#define BC_ERR_TX1_TX2_SAFETY_ERROR        (0x11017u)
#define BC_ERR_TX3_SAFETY_ERROR            (0x11018u)
#define BC_ERR_TX1_TX3_SAFETY_ERROR        (0x11019u)
#define BC_ERR_TX2_TX3_SAFETY_ERROR        (0x1101Au)
#define BC_ERR_TX1_TX2_TX3_SAFETY_ERROR    (0x1101Bu)
#define BC_ERR_TX_PTR_ADDR_NULL         (0x1101Cu)
#define BC_ERR_TX_NOSTOREINPROFILESELECTED (0x1101Du)
#define BC_ERR_TX_POUT_VGA_REDUCETX_NOTSUPPORTED (0x1101Eu)
#define BC_ERR_TX_RF_MIN_CODE_OUTOFRANGE    (0x1101Fu)
/// Write check failed for while enabling Functional Safety Mon Level enabling for TX  
#define BC_ERR_TX_FUSA_ENABLE_WRITECHECK_BASE     (0x11020u)
#define BC_ERR_TX1_FUSA_ENABLE_WRITECHECK         (0x11021u)
#define BC_ERR_TX2_FUSA_ENABLE_WRITECHECK         (0x11022u)  
#define BC_ERR_TX1_TX2_FUSA_ENABLE_WRITECHECK     (0x11023u)
#define BC_ERR_TX3_FUSA_ENABLE_WRITECHECK         (0x11024u)
#define BC_ERR_TX1_TX3_FUSA_ENABLE_WRITECHECK     (0x11025u)
#define BC_ERR_TX2_TX3_FUSA_ENABLE_WRITECHECK     (0x11026u)
#define BC_ERR_TX1_TX2_TX3_FUSA_ENABLE_WRITECHECK (0x11027u)
/// If the TX calibration is not complete, setting bias current will not succeed
#define BC_ERR_TX_CALIB_BIAS_CURR_WRITE_FAILED    (0x11028u)
/// TX calibration failed with timeout
#define BC_ERR_TX_CALIB_TIMEOUT                   (0x11029u)
/// Write check failed while enabling BBD for TX
#define BC_ERR_TX_BBD_ENABLE_WRITECHECK_BASE     (0x11030u)
#define BC_ERR_TX1_BBD_ENABLE_WRITECHECK         (0x11031u)
#define BC_ERR_TX2_BBD_ENABLE_WRITECHECK         (0x11032u)  
#define BC_ERR_TX1_TX2_BBD_ENABLE_WRITECHECK     (0x11033u)
#define BC_ERR_TX3_BBD_ENABLE_WRITECHECK         (0x11034u)
#define BC_ERR_TX1_TX3_BBD_ENABLE_WRITECHECK     (0x11035u)
#define BC_ERR_TX2_TX3_BBD_ENABLE_WRITECHECK     (0x11036u)
#define BC_ERR_TX1_TX2_TX3_BBD_ENABLE_WRITECHECK (0x11037u)

// ***** SSB Error Codes (0x14xxx) *****
/// Connected signal node to a wrong ATB
#define BC_ERR_SSB_SIGNALNOTEXISTONSELECTEDATB  (0x14001u) 
/// Input out of range
#define BC_ERR_SSB_INPUTOUTOFRANGE              (0x14002u) 

// ***** GLDO Error Codes (0x15xxx) *****
#define BC_ERR_GLDO_SNSERROR                      (0x15001u)
#define BC_ERR_GLDO_SNS_FORCEERROR                (0x15002u)
#define BC_ERR_GLDO_SNS_RESETERROR                (0x15003u)

// ***** ATB Error Codes (0x16xxx) *****
/// BISTADC data collection timeout 
#define BC_ERR_ATB_BISTADCTIMEOUT           (0x16001u)   
/// selected a wrong ATB
#define BC_ERR_ATB_WRONGATBNODESELECTED     (0x16002u) 

// ***** OTP Error Codes (0x17xxx) *****
/// Fail to read OTP table
#define BC_ERR_OTP_FAILTOREAD               (0x17001u) 
/// CRC check failure
#define BC_ERR_OTP_CRCCHECKFAILURE          (0x17002u) 
/// IP is disabled
#define BC_ERR_OTP_IPISDISABLED             (0x17003u)
/// OTP is not loaded. 
#define BC_ERR_OTP_OTPISNOTLOADED           (0x17004u) 
/* Gap */
// None of the OTP memory is enabled
#define BC_ERR_OTP_ALLMEMDISABLED           (0x17006u) 

// ***** ISM Error Codes (0x18xxx) *****
#define BC_ERR_ISM_INVALID_INPUT                            (0x018001u)
#define BC_ERR_ISM_PTR_ADDR_NULL                            (0x018002u)
#define BC_ERR_ISM_STARTUP_SEQ_CONFIG_FAILED                (0x018003u)
#define BC_ERR_ISM_INPUTMODE_TOGGLE_TEST_FAILED             (0x018004u)
#define BC_ERR_ISM_OUTPUTMODE_TOGGLE_TEST_FAILED            (0x018005u)
#define BC_ERR_ISM_FIT_ERROR_N_HIGH                         (0x018006u)
#define BC_ERR_ISM_FIT_RESET_STATE_CHANGE_FAILED            (0x018007u)
#define BC_ERR_ISM_FIT_RESET_ERROR_FAILED                   (0x018008u)
#define BC_ERR_ISM_FIT_FORCE_STATE_CHANGE_FAILED            (0x018009u)
#define BC_ERR_ISM_FIT_FORCE_ERROR_FAILED                   (0x01800Au)
#define BC_ERR_ISM_FIT_FAILED                               (0x01800Bu)
#define BC_ERR_ISM_FIT_STATUS_FAILED                        (0x01800Cu)
#define BC_ERR_ISM_FIT_TX_STATUS_FAILED                     (0x01800Du)
#define BC_ERR_ISM_FIT_RX_STATUS_FAILED                     (0x01800Eu)
#define BC_ERR_ISM_FIT_ADC_STATUS_FAILED                    (0x01800Fu)
#define BC_ERR_ISM_FIT_CHIRP_STATUS_FAILED                  (0x018010u)
#define BC_ERR_ISM_FIT_MCLK_LO_ISM_OTP_CC_STATUS_FAILED     (0x018011u)
#define BC_ERR_ISM_FIT_SSB_SER_GB_GLDO_ATB_STATUS_FAILED    (0x018012u)
#define BC_ERR_ISM_CAL_BUSY                                 (0x018013u)
#define BC_ERR_ISM_CAL_ERROR                                (0x018014u)
#define BC_ERR_ISM_CAL_SUCCESS                              (0x018015u)
#define BC_ERR_ISM_DISABLE_LB_TOGGLE_TEST_FAILED            (0x018016u)


#if defined(__cplusplus)
}
#endif
#endif
