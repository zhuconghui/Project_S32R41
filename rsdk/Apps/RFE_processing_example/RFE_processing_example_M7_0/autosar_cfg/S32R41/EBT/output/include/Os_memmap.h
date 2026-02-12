/******************************************************************************
*
*       NXP(TM) and the NXP logo are trademarks of NXP.
*       All other product or service names are the property of their respective owners.
*       (C) Freescale Semiconductor, Inc. 2013-2016
*       Copyright 2024 NXP
*
*       THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
*       BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF NXP.
*
*       Description: Memory map file
*
*       Note: The implementation that was used is: AUTOSAR_S32R41
*       System Generator for AUTOSAR OS/S32R41 - Version: 4.7 Build 4.7.160
*
********************************************************************************/
/*  --- HOOKS CODE ---  */

#if defined(OSHOOK_START_SEC_CODE)

#undef OSHOOK_START_SEC_CODE
#undef MEMMAP_ERROR

#if defined(OSGHSARM)

#pragma ghs section text=".oshook"

#elif defined(OSGCCARM)

#pragma GCC section text ".oshook"

#elif defined(OSDIABARM)

#pragma clang section text=".oshook"

#elif defined(OSIARARM)

/* TBD */

#elif defined(OSDS5ARM)

#pragma arm section code=".oshook"

#else

#error Unknown compiler
#endif /* OSGHSARM */

#elif defined(OSHOOK_STOP_SEC_CODE)

#undef OSHOOK_STOP_SEC_CODE
#undef MEMMAP_ERROR

#if defined(OSGHSARM)

#pragma ghs section text=default

#elif defined(OSGCCARM)

#pragma GCC section text "default"

#elif defined(OSDIABARM)

#pragma clang section text=""

#elif defined(OSIARARM)

/* TBD */

#elif defined(OSDS5ARM)

#pragma arm section code

#else

#error Unknown compiler
#endif /* OSGHSARM */

/*  --- APP CODE ---  */

#elif defined(APP_START_SEC_CODE)

#undef APP_START_SEC_CODE
#undef MEMMAP_ERROR

#if defined(OSGHSARM)

#pragma ghs section text=".appcode"

#elif defined(OSGCCARM)

#pragma GCC section text ".appcode"

#elif defined(OSDIABARM)

#pragma clang section text=".appcode"

#elif defined(OSIARARM)

/* TBD */

#elif defined(OSDS5ARM)

#pragma arm section code=".appcode"

#else

#error Unknown compiler
#endif /* OSGHSARM */

#elif defined(APP_STOP_SEC_CODE)

#undef APP_STOP_SEC_CODE
#undef MEMMAP_ERROR

#if defined(OSGHSARM)

#pragma ghs section text=default

#elif defined(OSGCCARM)

#pragma GCC section text "default"

#elif defined(OSDIABARM)

#pragma clang section text=""

#elif defined(OSIARARM)

/* TBD */

#elif defined(OSDS5ARM)

#pragma arm section code

#else

#error Unknown compiler
#endif /* OSGHSARM */

/*  --- OSVECTORS CODE ---  */

#elif defined(OSVECTORS_START_SEC_CODE)

#undef OSVECTORS_START_SEC_CODE
#undef MEMMAP_ERROR

#if defined(OSGHSARM)

OSASM("    .section  \".vects\", \"vax\"    ");
OSASM("    .vle ");

#elif defined(OSGCCARM)

#pragma GCC section text ".vects"

#elif defined(OSDIABARM)

#pragma clang section text=".vects"

#elif defined(OSIARARM)

/* TBD */

#elif defined(OSDS5ARM)

#pragma arm section code=".vects"

#else

#error Unknown compiler
#endif /* OSGHSARM */

#elif defined(OSVECTORS_STOP_SEC_CODE)

#undef OSVECTORS_STOP_SEC_CODE
#undef MEMMAP_ERROR

#if defined(OSGHSARM)

OSASM("    .section  \".vletext\", \"vax\"    ");
OSASM("    .vle ");

#elif defined(OSGCCARM)

#pragma GCC section text "default"

#elif defined(OSDIABARM)

#pragma clang section text=""

#elif defined(OSIARARM)

/* TBD */

#elif defined(OSDS5ARM)

#pragma arm section code=".vletext"

#else

#error Unknown compiler
#endif /* OSGHSARM */

/*  --- OSVECTORS CODE second core ---  */

#elif defined(OSVECTORS2_START_SEC_CODE)

#undef OSVECTORS2_START_SEC_CODE
#undef MEMMAP_ERROR

#if defined(OSGHSARM)

OSASM("    .section  \".vects2\", \"vax\"    ");
OSASM("    .vle ");

#elif defined(OSGCCARM)

#pragma GCC section text ".vects2"

#elif defined(OSDIABARM)

#pragma clang section text=".vects2"

#elif defined(OSIARARM)

/* TBD */

#elif defined(OSDS5ARM)

#pragma arm section code=".vects2"

#else

#error Unknown compiler
#endif /* OSGHSARM */

#elif defined(OSVECTORS2_STOP_SEC_CODE)

#undef OSVECTORS2_STOP_SEC_CODE
#undef MEMMAP_ERROR

#if defined(OSGHSARM)

OSASM("    .section  \".vletext\", \"vax\"    ");
OSASM("    .vle ");

#elif defined(OSGCCARM)

#pragma GCC section text "default"

#elif defined(OSDIABARM)

#pragma clang section text=""

#elif defined(OSIARARM)

/* TBD */

#elif defined(OSDS5ARM)

#pragma arm section code=".vletext"

#else

#error Unknown compiler
#endif /* OSGHSARM */

/*  --- STARTUP CODE second core ---  */

#elif defined(OSSTARTUP2_START_SEC_CODE)

#undef OSSTARTUP2_START_SEC_CODE
#undef MEMMAP_ERROR

#if defined(OSGHSARM)

OSASM("    .section  \".startup2\", \"vax\"    ");
OSASM("    .vle ");

#elif defined(OSGCCARM)

#pragma GCC section text ".startup2"

#elif defined(OSDIABARM)

#pragma clang section text=".startup2"

#elif defined(OSIARARM)

/* TBD */

#elif defined(OSDS5ARM)

#pragma arm section code=".startup2"

#else

#error Unknown compiler
#endif /* OSGHSARM */

#elif defined(OSSTARTUP2_STOP_SEC_CODE)

#undef OSSTARTUP2_STOP_SEC_CODE
#undef MEMMAP_ERROR

#if defined(OSGHSARM)

OSASM("    .section  \".vletext\", \"vax\"    ");
OSASM("    .vle ");

#elif defined(OSGCCARM)

#pragma GCC section text "default"

#elif defined(OSDIABARM)

#pragma clang section text=""

#elif defined(OSIARARM)

/* TBD */

#elif defined(OSDS5ARM)

#pragma arm section code=".vletext"

#else

#error Unknown compiler
#endif /* OSGHSARM */

#endif /* OSHOOK_START_SEC_CODE */

