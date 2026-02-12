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

// Obtain printf function
#if defined(DEBUG_VERSION) // As used in M7_0
  #include <stdio.h>
  #include <string.h>
  #include "debug_tools.h"
#elif defined(RFE_DEBUG)  // As used in M7_1
  #include <string.h>
  #include <stdio.h>
  #include "rfeHwLink.h"
#else
  #error "No debug printing supported"
#endif

#include "rfe_types.h"
#include "rfe_error.h"

#include "rfe_blob_access.h"
#include "rfe_blob_debug.h"


/*****************************************************************************
* local defines
*****************************************************************************/
#define FORMAT_STRING10  "%10s"
#define FORMAT_NUMERIC10 "%10d"
#define FORMAT_NAME30  " %30s"
#define FORMAT_VERSION "%d.%d.%d"
#define FORMAT_SEP " : "
#define NAME_WIDTH  30
#define FIELD_WIDTH 10
#define NR_FIELDS_MAX 8

#ifndef NULL_PTR
#define NULL_PTR ((void *)0)
#endif

#if defined(DEBUG_VERSION)
// Map RfeDbgPrintMsg to DbgPrintMsg
#define  RfeDbgPrintMsg DbgPrintMsg
#elif defined(RFE_DEBUG)
// use RfeDbgPrintMsg
#else
// use dummy func
static void RfeDbgPrintMsg(const char *fmt, ...)
{
	return;
}
#endif



/*****************************************************************************
* local types
*****************************************************************************/
typedef struct{
	rfeCfg_section_t section;
	rfeCfg_param_t param;
	const char *name;
} rfe_section_param_list_t;

typedef struct {
	rfe_fuSaFault_t fuSaFault;
	const char *string;
} rfe_fusafault_list_t;

typedef struct {
	uint32_t index;
	const char *string ;
} string_list_t;

/*****************************************************************************
* local functions (prototypes)
*****************************************************************************/
void RfeDbg_BlobSummary(const uint8_t *pConfig, bool bTranslate);
void RfeDbg_MetadataList(const uint8_t *pConfig, bool bTranslate);
void RfeDbg_RadarCyclesList(const uint8_t *pConfig, bool bTranslate);
void RfeDbg_ChirpProfilesList(const uint8_t *pConfig, bool bTranslate);
void RfeDbg_SeqProfilesList(const uint8_t *pConfig, bool bTranslate);
static void RfeDbg_Transprintf(char *pString, rfeCfg_param_t param, uint32_t value);

/*****************************************************************************
* exported variables
*****************************************************************************/

/*****************************************************************************
* local variables
*****************************************************************************/



static const char nullstring[1] = "";

/* constants */
static const char gsRadarCycleColumnNames[][NAME_WIDTH+1] = {
		"chirpSequence[]", "chirpSeqStartTimeOffset[]", "recalProfileDependent[]"
};

static const rfe_section_param_list_t gsMetadataList[] = {
		{rfeCfg_section_metadata_e, rfeCfg_param_metadata_chirpSequenceConfigCount_e, "chirpSequenceConfigCount"},
		{rfeCfg_section_metadata_e, rfeCfg_param_metadata_chirpProfileCount_e,        "chirpProfileCount"       },
};

static const rfe_section_param_list_t gsGeneralList[] = {
		{ rfeCfg_section_general_e, rfeCfg_param_general_powerMode_e,                     "powerMode"                      },
		{ rfeCfg_section_general_e, rfeCfg_param_general_radarCycleStartSignalGpio_e,     "radarCycleStartSignalGpio"      },
		{ rfeCfg_section_general_e, rfeCfg_param_general_chirpSequenceActiveSignalGpio_e, "chirpSequenceActiveSignalGpio"  },
		{ rfeCfg_section_general_e, rfeCfg_param_general_clkIoConfig_e,                   "clkIoConfig"                    },
		{ rfeCfg_section_general_e, rfeCfg_param_general_pdcDecimationFilter_e,           "pdcDecimationFilter"            },
		{ rfeCfg_section_general_e, rfeCfg_param_general_dataOutConfig_e,                 "dataOutConfig"                  },
		{ rfeCfg_section_general_e, rfeCfg_param_general_metadataPacketSwContent_e,       "metadataPacketSwContent"        },
		{ rfeCfg_section_general_e, rfeCfg_param_general_metadataPacketVirtualChannel_e,  "metadataPacketVirtualChannel"   },
		{ rfeCfg_section_general_e, rfeCfg_param_general_jumpbackTimeTicks_e,             "jumpbackTimeTicks"              }
};

static const string_list_t gsChirpProfileParams[] = {
        { rfeCfg_param_chirpProfile_effectiveSamplingFrequency_e,   "effectiveSamplingFrequency"   },
        { rfeCfg_param_chirpProfile_chirpIntervalTimeTicks_e,       "chirpIntervalTimeTicks"       },
        { rfeCfg_param_chirpProfile_dwellTimeTicks_e,               "dwellTimeTicks"               },
        { rfeCfg_param_chirpProfile_settleTimeTicks_e,              "settleTimeTicks"              },
        { rfeCfg_param_chirpProfile_acquisitionTimeTicks_e,         "acquisitionTimeTicks"         },
        { rfeCfg_param_chirpProfile_resetTimeTicks_e,               "resetTimeTicks"               },
        { rfeCfg_param_chirpProfile_centerFrequency_e,              "centerFrequency"              },
        { rfeCfg_param_chirpProfile_effectiveChirpBandwidth_e,      "effectiveChirpBandwidth"      },
        { rfeCfg_param_chirpProfile_chirpPllVcoSelect_e,            "chirpPllVcoSelect"            },
        { rfeCfg_param_chirpProfile_chirpSlopeDirection_e,          "chirpSlopeDirection"          },
        { rfeCfg_param_chirpProfile_chirpPllLoopFilterBandwidth_e,  "chirpPllLoopFilterBandwidth"  },
        { rfeCfg_param_chirpProfile_txTransmissionEnable_e,         "txTransmissionEnable"         },
        { rfeCfg_param_chirpProfile_txPower_e,                      "txPower"                      },
        { rfeCfg_param_chirpProfile_txPhaseRotation_1_e,            "txPhaseRotation_1"            },
        { rfeCfg_param_chirpProfile_txPhaseRotation_2_e,            "txPhaseRotation_2"            },
        { rfeCfg_param_chirpProfile_txPhaseRotation_3_e,            "txPhaseRotation_3"            },
        { rfeCfg_param_chirpProfile_txTransmissionReferenceTime_e,  "txTransmissionReferenceTime"  },
        { rfeCfg_param_chirpProfile_txTransmissionTimeOffset_e,     "txTransmissionTimeOffset"     },
        { rfeCfg_param_chirpProfile_chirpFrequencyDriftSteps_e,     "chirpFrequencyDriftSteps"     },
        { rfeCfg_param_chirpProfile_rxGain_e,                       "rxGain"                       },
        { rfeCfg_param_chirpProfile_rxHpfCutOffFrequency_e,         "rxHpfCutOffFrequency"         },
        { rfeCfg_param_chirpProfile_rxLpfCutOffFrequency_e,         "rxLpfCutOffFrequency"         },
        { rfeCfg_param_chirpProfile_virtualChannel_e,               "virtualChannel"               }
};

static const string_list_t gsChirpSequenceParams[] = {
		{ rfeCfg_param_chirpSequence_chirpCount_e,                "chirpCount"                 },
		{ rfeCfg_param_chirpSequence_chirpProfileSequence_0_e,    "chirpProfileSequence_0"     },
		{ rfeCfg_param_chirpSequence_chirpProfileSequence_1_e,    "chirpProfileSequence_1"     },
		{ rfeCfg_param_chirpSequence_chirpProfileSequence_2_e,    "chirpProfileSequence_2"     },
		{ rfeCfg_param_chirpSequence_chirpProfileSequence_3_e,    "chirpProfileSequence_3"     },
		{ rfeCfg_param_chirpSequence_chirpProfileSequence_4_e,    "chirpProfileSequence_4"     },
		{ rfeCfg_param_chirpSequence_chirpProfileSequence_5_e,    "chirpProfileSequence_5"     },
		{ rfeCfg_param_chirpSequence_chirpProfileSequence_6_e,    "chirpProfileSequence_6"     },
		{ rfeCfg_param_chirpSequence_chirpProfileSequence_7_e,    "chirpProfileSequence_7"     },
		{ rfeCfg_param_chirpSequence_chirpProfileSequenceLength_e,"chirpProfileSequenceLength" },
		{ rfeCfg_param_chirpSequence_dynamicUpdatesEnabled_e,     "dynamicUpdatesEnabled"      },
		{ rfeCfg_param_chirpSequence_dynamicTableIndex_e,         "dynamicTableIndex"          }
};

static const string_list_t gsRadarCycleParams[] = {
		{ rfeCfg_param_radarCycle_chirpSequenceCount_e,            "chirpSequenceCount"            },
		{ rfeCfg_param_radarCycle_recalibrateProfileIndependent_e, "recalibrateProfileIndependent" },
		{ rfeCfg_param_radarCycle_bistInterval_e,                  "bistInterval"                  },
		{ rfeCfg_param_radarCycle_radarCycleDuration_e,            "radarCycleDuration"            },
};

static const string_list_t gsChirpProfileSections[] = {
		{ rfeCfg_section_chirpProfile_0_e, "chirpProfile_0" },
		{ rfeCfg_section_chirpProfile_1_e, "chirpProfile_1" },
		{ rfeCfg_section_chirpProfile_2_e, "chirpProfile_2" },
		{ rfeCfg_section_chirpProfile_3_e, "chirpProfile_3" },
		{ rfeCfg_section_chirpProfile_4_e, "chirpProfile_4" },
		{ rfeCfg_section_chirpProfile_5_e, "chirpProfile_5" },
		{ rfeCfg_section_chirpProfile_6_e, "chirpProfile_6" },
		{ rfeCfg_section_chirpProfile_7_e, "chirpProfile_7" },
};

static const string_list_t gsChirpSequenceSections[] = {
		{ rfeCfg_section_chirpSequenceConfig_0_e, "chirpSequence_0"},
		{ rfeCfg_section_chirpSequenceConfig_1_e, "chirpSequence_1"},
		{ rfeCfg_section_chirpSequenceConfig_2_e, "chirpSequence_2"},
		{ rfeCfg_section_chirpSequenceConfig_3_e, "chirpSequence_3"},
		{ rfeCfg_section_chirpSequenceConfig_4_e, "chirpSequence_4"},
		{ rfeCfg_section_chirpSequenceConfig_5_e, "chirpSequence_5"},
		{ rfeCfg_section_chirpSequenceConfig_6_e, "chirpSequence_6"},
		{ rfeCfg_section_chirpSequenceConfig_7_e, "chirpSequence_7"},
};



/*--------------------------------------------------------------------------------*/
void RfeDbg_BlobSummary(const uint8_t *pConfig, bool bTranslate)
{
	RfeDbg_MetadataList(pConfig, bTranslate);
	RfeDbg_RadarCyclesList(pConfig, bTranslate);
	RfeDbg_SeqProfilesList(pConfig, bTranslate);
	RfeDbg_ChirpProfilesList(pConfig, bTranslate);
}


/* Function implementations */
static void RfeDbg_Transprintf(char *pString, rfeCfg_param_t param, uint32_t value)
{
	char dummy[FIELD_WIDTH+1]="";

	switch (param)
	{
		case rfeCfg_param_chirpProfile_effectiveSamplingFrequency_e:
		{
			snprintf (dummy, sizeof(dummy), "%d:%dM",(int)value,(int)( 40 / (1<<value)));
		}
		break;

		case rfeCfg_param_chirpProfile_chirpIntervalTimeTicks_e:
		case rfeCfg_param_chirpProfile_dwellTimeTicks_e:
		case rfeCfg_param_chirpProfile_settleTimeTicks_e:
		case rfeCfg_param_chirpProfile_acquisitionTimeTicks_e:
		case rfeCfg_param_chirpProfile_resetTimeTicks_e:
		case rfeCfg_param_chirpProfile_txTransmissionReferenceTime_e:
		case rfeCfg_param_chirpProfile_txTransmissionTimeOffset_e: /* 1 tick = 25ns */
		{
			snprintf (dummy, sizeof(dummy), "%0d.%03du", (int)(value*25)/1000, (int)(value*25)%1000);
		}
		break;


		case  rfeCfg_param_chirpProfile_chirpPllLoopFilterBandwidth_e:
		{
			snprintf (dummy, sizeof(dummy), "%dk", (int)(200+value*50));   /* 200, 250, ... 800kHz */
		}
		break;

		case rfeCfg_param_chirpProfile_txPower_e:
		{
			snprintf (dummy, sizeof(dummy), "%4d.%01d", (int)(value/10), (int)(value%10)); /* 0.1 dBm steps */
		}
		break;

		case  rfeCfg_param_chirpProfile_rxGain_e:
		{
			if ((rfe_rxGain_t)value <= rfe_rxGain_46dB_e) {
				snprintf (dummy, sizeof(dummy), "%d:%ddB", (int)value, (int)(25+3*value));
			}
		}
		break;

		case rfeCfg_param_chirpProfile_chirpPllVcoSelect_e: /* 1G/2G/4G enum */
		{
			switch((rfe_chirpPllVco_t)value)
			{
				case rfe_chirpPllVco_1GHz_e: snprintf(dummy, sizeof(dummy), "%d:1G", (int)value); break;
				case rfe_chirpPllVco_2GHz_e: snprintf(dummy, sizeof(dummy), "%d:2G", (int)value); break;
				case rfe_chirpPllVco_4GHz_e: snprintf(dummy, sizeof(dummy), "%d:4G", (int)value); break;
				default: break;
			}
		}
		break;

		case rfeCfg_param_chirpProfile_chirpSlopeDirection_e:
		{
			switch((rfe_chirpSlopeDirection_t)value)
			{
				case rfe_chirpSlopeDirection_falling_e: snprintf(dummy, sizeof(dummy), "%d:fall", (int)value); break;
				case rfe_chirpSlopeDirection_rising_e:  snprintf(dummy, sizeof(dummy), "%d:rise", (int)value); break;
				default: break;
			}
		}
		break;

		case  rfeCfg_param_chirpProfile_rxHpfCutOffFrequency_e:
		{
			switch ((rfe_rxHpfCutOffFrequency_t)(value))
			{
				case rfe_rxHpfCutOffFrequency_200kHz_e:  snprintf (dummy, sizeof(dummy), "%d:200k", (int)value); break;
				case rfe_rxHpfCutOffFrequency_300kHz_e:  snprintf (dummy, sizeof(dummy), "%d:300k", (int)value); break;
				case rfe_rxHpfCutOffFrequency_400kHz_e:  snprintf (dummy, sizeof(dummy), "%d:400k", (int)value); break;
				case rfe_rxHpfCutOffFrequency_800kHz_e:  snprintf (dummy, sizeof(dummy), "%d:800k", (int)value); break;
				case rfe_rxHpfCutOffFrequency_1600kHz_e: snprintf (dummy, sizeof(dummy), "%d:1.6M", (int)value); break;
				case rfe_rxHpfCutOffFrequency_3200kHz_e: snprintf (dummy, sizeof(dummy), "%d:3.2M", (int)value); break;
				case rfe_rxHpfCutOffFrequency_6400kHz_e: snprintf (dummy, sizeof(dummy), "%d:6.4M", (int)value); break;
				default: break;
			};
		}
		break;

		case  rfeCfg_param_chirpProfile_rxLpfCutOffFrequency_e:
		{
			switch ((rfe_rxLpfCutOffFrequency_t)(value))
			{
				case rfe_rxLpfCutOffFrequency_10MHz_e: snprintf (dummy, sizeof(dummy), "%d:10M", (int)value); break;
				case rfe_rxLpfCutOffFrequency_15MHz_e: snprintf (dummy, sizeof(dummy), "%d:15M", (int)value); break;
				case rfe_rxLpfCutOffFrequency_20MHz_e: snprintf (dummy, sizeof(dummy), "%d:20M", (int)value); break;
				case rfe_rxLpfCutOffFrequency_25MHz_e: snprintf (dummy, sizeof(dummy), "%d:25M", (int)value); break;
				case rfe_rxLpfCutOffFrequency_30MHz_e: snprintf (dummy, sizeof(dummy), "%d:30M", (int)value); break;
				case rfe_rxLpfCutOffFrequency_40MHz_e: snprintf (dummy, sizeof(dummy), "%d:40M", (int)value); break;
				default: break;
			};
		}
		break;
		case  rfeCfg_param_chirpProfile_centerFrequency_e:
		case  rfeCfg_param_chirpProfile_effectiveChirpBandwidth_e:
		default:
		{
			snprintf (dummy, sizeof(dummy), "%d", (int)value);
		}
		break;
	}
	/* */
	snprintf(pString, FIELD_WIDTH+1, FORMAT_STRING10, dummy);
}



void RfeDbg_MetadataList(const uint8_t *pConfig, bool bTranslate)
{
	uint32_t value;
	rfe_error_t rfeError = rfe_error_none_e, *rfe___error___pointer = &rfeError;
	rfeCfg_section_t section;
	uint8_t *pCfg=(uint8_t *)pConfig;
	uint8_t idx;

	struct {
		uint32_t major, minor, patch;
	} version = { 0, 0, 0 };


	/* Print metadata info */
	RfeDbgPrintMsg("\nrfeConfig.metadata:\n");

	section = rfeCfg_section_metadata_e;
	
	value = rfeCfg_read(pCfg, section, rfeCfg_param_metadata_majorVersion_e, rfe___error___pointer);
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		version.major = (uint8_t)value;
	}

	value = rfeCfg_read(pCfg, section, rfeCfg_param_metadata_minorVersion_e, rfe___error___pointer);
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		version.minor = (uint8_t)value;
	}

	value = rfeCfg_read(pCfg, section, rfeCfg_param_metadata_patchVersion_e, rfe___error___pointer);
	if (*rfe___error___pointer == rfe_error_none_e)
	{
		version.patch = (uint8_t)value;
	}

	if (bTranslate==true)
	{
		RfeDbgPrintMsg(FORMAT_NAME30 FORMAT_SEP FORMAT_VERSION "\n", "version(maj,min,patch)", version.major, version.minor, version.patch);
	}
	else
	{
		RfeDbgPrintMsg(FORMAT_NAME30 FORMAT_SEP "%d\n", "version.major", version.major);
		RfeDbgPrintMsg(FORMAT_NAME30 FORMAT_SEP "%d\n", "version.minor", version.minor);
		RfeDbgPrintMsg(FORMAT_NAME30 FORMAT_SEP "%d\n", "version.patch", version.patch);
	}

	// iterate list
	for (idx = 0; idx < sizeof(gsMetadataList)/sizeof(gsMetadataList[0]); idx++)
	{
		value = rfeCfg_read(pCfg, gsMetadataList[idx].section, gsMetadataList[idx].param, rfe___error___pointer);
		if (*rfe___error___pointer == rfe_error_none_e)
		{
			RfeDbgPrintMsg(FORMAT_NAME30 FORMAT_SEP "%d\n", gsMetadataList[idx].name, value);
		}
	}
	RfeDbgPrintMsg("\n");

	/* Print general section */
	section = rfeCfg_section_general_e;
	RfeDbgPrintMsg("\nrfeConfig.general:\n");

    // iterate list
	for (idx = 0; idx < sizeof(gsGeneralList)/sizeof(gsGeneralList[0]); idx++)
	{
		value = rfeCfg_read(pCfg, gsGeneralList[idx].section, gsGeneralList[idx].param, rfe___error___pointer);
		if (*rfe___error___pointer == rfe_error_none_e)
		{
			RfeDbgPrintMsg(FORMAT_NAME30 FORMAT_SEP "%d\n", gsGeneralList[idx].name,  value);
		}
	}
}

void RfeDbg_ChirpProfilesList(const uint8_t *pConfig, bool bTranslate)
{
	rfe_error_t rfeError = rfe_error_none_e, *rfe___error___pointer = &rfeError;
	char profileLine[NAME_WIDTH+FIELD_WIDTH*NR_FIELDS_MAX+1] = "";
	uint8_t *pCfg = (uint8_t*)pConfig;
	uint8_t idxProfile, idxParam;
	uint32_t value;

	/* Print table for 8 ChirpProfiles */
	RfeDbgPrintMsg("\nrfeConfig.chirpProfiles 0-7:\n{\n");
	for (idxParam = 0; idxParam < sizeof(gsChirpProfileParams)/sizeof(gsChirpProfileParams[0]); idxParam++)
	{
		memset (profileLine, 0, sizeof(profileLine));
		for(idxProfile = 0; idxProfile < sizeof(gsChirpProfileSections)/sizeof(gsChirpProfileSections[0]); idxProfile++)
		{
			value = rfeCfg_read(pCfg, (rfeCfg_section_t)gsChirpProfileSections[idxProfile].index,
					(rfeCfg_param_t)gsChirpProfileParams[idxParam].index, rfe___error___pointer);

			if (*rfe___error___pointer == rfe_error_none_e)
			{
				if (bTranslate==true)
				{
					RfeDbg_Transprintf(&profileLine[idxProfile*FIELD_WIDTH], (rfeCfg_param_t)gsChirpProfileParams[idxParam].index, (uint32_t)value);
				}
				else
				{
					snprintf(&profileLine[idxProfile*FIELD_WIDTH], FIELD_WIDTH+1, FORMAT_NUMERIC10, (int)value);
				}
			}
		}

		RfeDbgPrintMsg(FORMAT_NAME30 FORMAT_SEP "%s\n", gsChirpProfileParams[idxParam].string, profileLine);
	}
}

void RfeDbg_SeqProfilesList(const uint8_t *pConfig, bool bTranslate)
{

	rfe_error_t rfeError = rfe_error_none_e, *rfe___error___pointer = &rfeError;
	char profileLine[NAME_WIDTH+FIELD_WIDTH*NR_FIELDS_MAX+1] = "";
	uint8_t *pCfg = (uint8_t *)pConfig;
	uint8_t idxProfile, idxParam;
	uint32_t value;
	rfeCfg_param_t param;
	rfeCfg_section_t section;

	/* Print table for 8 ChirpProfileSequences */
	RfeDbgPrintMsg("\nrfeConfig.chirpSequence 0-7:\n");
	for (idxParam = 0; idxParam < sizeof(gsChirpSequenceParams)/sizeof(gsChirpSequenceParams[0]); idxParam++)
	{
		param = (rfeCfg_param_t)gsChirpSequenceParams[idxParam].index;
		memset (profileLine, 0, sizeof (profileLine));

		for(idxProfile = 0; idxProfile < 8; idxProfile++)
		{
			section = (rfeCfg_section_t)gsChirpSequenceSections[idxProfile].index;

			value = rfeCfg_read(pCfg, section, param, rfe___error___pointer);
			if (*rfe___error___pointer == rfe_error_none_e)
			{
				if (bTranslate==true)
				{
					RfeDbg_Transprintf(&profileLine[idxProfile*FIELD_WIDTH], param, (uint32_t)value);
				}
				else
				{
					snprintf(&profileLine[idxProfile*FIELD_WIDTH], FIELD_WIDTH+1, FORMAT_NUMERIC10, (int)value);
				}
			}
		}

		RfeDbgPrintMsg(FORMAT_NAME30 FORMAT_SEP "%s\n", gsChirpSequenceParams[idxParam].string, profileLine);
	}
}

void RfeDbg_RadarCyclesList(const uint8_t *pConfig, bool bTranslate)
{

	rfe_error_t rfeError = rfe_error_none_e, *rfe___error___pointer = &rfeError;
	char profileLine[NAME_WIDTH+FIELD_WIDTH*NR_FIELDS_MAX+1] = "";
	uint8_t *pCfg =  (uint8_t*)pConfig;
	uint8_t idxProfile, idxParam;
	uint32_t value;
	rfeCfg_param_t param;
	rfeCfg_section_t section;

	/* Print table for RadarCycle */
	section = rfeCfg_section_radarCycle_e;
	RfeDbgPrintMsg("\nrfeConfig.RadarCycle[0-7]:\n");

	for (idxParam = 0; idxParam < sizeof(gsRadarCycleParams)/sizeof(gsRadarCycleParams[0]); idxParam++)
	{
		value = rfeCfg_read(pCfg, section, gsRadarCycleParams[idxParam].index, rfe___error___pointer);
		if (*rfe___error___pointer == rfe_error_none_e)
		{
			RfeDbgPrintMsg(FORMAT_NAME30 FORMAT_SEP "%d\n", gsRadarCycleParams[idxParam].string,  value);
		}
	}

	for (idxParam=0; idxParam<sizeof(gsRadarCycleColumnNames)/sizeof(gsRadarCycleColumnNames[0]); idxParam++)
	{
		memset (profileLine, 0, sizeof(profileLine));
		//snprintf(profileLine, sizeof(profileLine),  );
		for (idxProfile=0; idxProfile<8; idxProfile++)
		{
			if (idxParam == 0u)
			{
				param = rfeCfg_util_params_radarCycle_chirpSequence[idxProfile];
			}
			else if (idxParam == 1u)
			{
				param = rfeCfg_util_params_radarCycle_chirpSequenceStartTimeOffset[idxProfile];
			}
			else if (idxParam == 2u)
			{
				switch (idxProfile)
				{
				case 1:  param=rfeCfg_param_radarCycle_recalibrateProfileDependent_1_e; break;
				case 2:  param=rfeCfg_param_radarCycle_recalibrateProfileDependent_2_e; break;
				case 3:  param=rfeCfg_param_radarCycle_recalibrateProfileDependent_3_e; break;
				case 4:  param=rfeCfg_param_radarCycle_recalibrateProfileDependent_4_e; break;
				case 5:  param=rfeCfg_param_radarCycle_recalibrateProfileDependent_5_e; break;
				case 6:  param=rfeCfg_param_radarCycle_recalibrateProfileDependent_6_e; break;
				case 7:  param=rfeCfg_param_radarCycle_recalibrateProfileDependent_7_e; break;
				default: param=rfeCfg_param_radarCycle_recalibrateProfileDependent_0_e; break;
				};
			}
			else
			{
				param=0; /* should fault actually */
			}

			value = rfeCfg_read((uint8_t*)pConfig, section, param, rfe___error___pointer);
			if (*rfe___error___pointer == rfe_error_none_e)
			{
				if (bTranslate==true)
				{
					RfeDbg_Transprintf(&profileLine[idxProfile*FIELD_WIDTH], param, (uint32_t)value);
				}
				else
				{
					snprintf(&profileLine[idxProfile*FIELD_WIDTH], FIELD_WIDTH+1, FORMAT_NUMERIC10, (int)value);
				}
			}
		}

		RfeDbgPrintMsg(FORMAT_NAME30 FORMAT_SEP "%s\n", gsRadarCycleColumnNames[idxParam] , profileLine);
	}

}

