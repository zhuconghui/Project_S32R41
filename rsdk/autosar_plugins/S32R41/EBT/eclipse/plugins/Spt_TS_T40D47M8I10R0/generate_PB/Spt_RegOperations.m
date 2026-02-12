[!/* *** multiple inclusion protection *** */!]
[!IF "not(var:defined('SPT_REGOPERATIONS_M'))"!]
[!VAR "SPT_REGOPERATIONS_M"="'true'"!]
[!NOCODE!][!//
/*
 *  Copyright 2021-2024 NXP
 *  NXP Confidential. This software is owned or controlled by NXP and may only
 *  be used strictly in accordance with the applicable license terms. By
 *  expressly accepting such terms or by downloading, installing, activating
 *  and/or otherwise using the software, you are agreeing that you have read,
 *  and that you agree to comply with and are bound by, such license terms. If
 *  you do not agree to be bound by the applicable license terms, then you may
 *  not retain, install, activate or otherwise use the software.
 */
[!ENDNOCODE!][!//

[!MACRO "SptConfigSetupMacro"!][!//
[!CODE!][!//
[!IF "node:value(SptGeneral/POST_BUILD_VARIANT_USED)"!]
#define SPT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spt_MemMap.h"

Spt_DriverInitType [!"node:value(SptSetup/SptSetupStructureName)"!] = {
    .hwPlatSpec = {
#if(SPT_DSP_ENABLE == STD_ON)
        .dspEn = [!"node:value(SptSetup/SptDspEnable)"!],
#endif
    }
};

#define SPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spt_MemMap.h"
[!ENDIF!]
[!ENDCODE!][!//
[!ENDMACRO!][!//

[!MACRO "SptConfigSetupMacroVar"!][!//
[!CODE!][!//
[!IF "node:value(SptGeneral/POST_BUILD_VARIANT_USED)"!]
extern Spt_DriverInitType [!"node:value(SptSetup/SptSetupStructureName)"!];
[!ENDIF!]
[!ENDCODE!][!//
[!ENDMACRO!][!//
/** @} */
[!ENDIF!]
