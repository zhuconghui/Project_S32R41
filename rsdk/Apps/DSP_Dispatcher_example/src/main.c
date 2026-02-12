/**************************************************************************************************
 * Copyright 2018-2024 NXP
 **************************************************************************************************
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 **************************************************************************************************/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/

#include <stdio.h>
#include <xtensa/tie/radar24.h>
#include <xtensa/hal.h>

#include "rsdk_dsp_dispatcher.h"
#include "rsdk_dsp_radar_bb_algos.h"

#include "dsp_demo_funcs.h"


#include "rsdk_dsp_lal_vector_add.h"


#include "ipcf_Ip_Cfg.h"

#include "ipcf_Ip_Cfg_Defines.h"







#include "dispatcher_func_list_dsp.h"

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

#define ADDR_DSP_DEBUG6_REG (0xBC)
#define MAX_EVENTS_QUEUE	50u





/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

volatile uint32_t numEvts = 0;
uint32_t eventsQ[MAX_EVENTS_QUEUE];


// MPU DECLARATION; THIS IS ONE TIME ONLY
const struct xthal_MPU_entry __xt_mpu_init_table[] __attribute__((section(".ResetHandler.text"))) = {


















		//.startAddr				.valid	.accessRights	.memType
		XTHAL_MPU_ENTRY(0x0,        1u, 	XTHAL_AR_NONE,  XTHAL_MEM_DEVICE|XTHAL_MEM_NON_SHAREABLE),	    	  							//first segment at addr 0x0 needed for alignment with the background map. not used
		XTHAL_MPU_ENTRY(0x24100000, 1u, 	XTHAL_AR_RWrw,  XTHAL_MEM_NON_CACHEABLE|XTHAL_MEM_NON_SHAREABLE|XTHAL_MEM_BUFFERABLE),     		//DRAM0
		XTHAL_MPU_ENTRY(0x24120000, 1u, 	XTHAL_AR_RWrw,  XTHAL_MEM_NON_CACHEABLE|XTHAL_MEM_NON_SHAREABLE|XTHAL_MEM_BUFFERABLE),     		//DRAM1
	// not production code; IRAM Write protection disabled to allow SW Breakpoints from S32 Debug Probe
#if defined(BBE32_DEBUG)
		XTHAL_MPU_ENTRY(0x24140000, 1u, 	XTHAL_AR_RWXrx, XTHAL_MEM_NON_CACHEABLE|XTHAL_MEM_NON_SHAREABLE), 								//IRAM
#else
		XTHAL_MPU_ENTRY(0x24140000, 1u, 	XTHAL_AR_RXrx,  XTHAL_MEM_NON_CACHEABLE|XTHAL_MEM_NON_SHAREABLE), 								//IRAM
#endif
		XTHAL_MPU_ENTRY(0x24180000, 1u, 	XTHAL_AR_NONE,  XTHAL_MEM_DEVICE|XTHAL_MEM_NON_SHAREABLE),        								//not used
		XTHAL_MPU_ENTRY(0x33c00000, 1u, 	XTHAL_AR_RWrw,  XTHAL_MEM_NON_CACHEABLE|XTHAL_MEM_NON_SHAREABLE|XTHAL_MEM_INTERRUPTIBLE|XTHAL_MEM_BUFFERABLE),  			//SRAM - system shared data




        XTHAL_MPU_ENTRY(0x34000000, 1u,     XTHAL_AR_RWrw,  XTHAL_MEM_NON_CACHEABLE|XTHAL_MEM_NON_SHAREABLE|XTHAL_MEM_INTERRUPTIBLE),          							//SRAM - IPCF
        XTHAL_MPU_ENTRY(0x34001000, 1u,     XTHAL_AR_RWrw,  XTHAL_MEM_NON_CACHEABLE|XTHAL_MEM_NON_SHAREABLE|XTHAL_MEM_INTERRUPTIBLE|XTHAL_MEM_BUFFERABLE),              //SRAM - system shared data

		XTHAL_MPU_ENTRY(0x34400000, 1u, 	XTHAL_AR_NONE,  XTHAL_MEM_DEVICE|XTHAL_MEM_NON_SHAREABLE),       								//not used
		XTHAL_MPU_ENTRY(0x40010000, 1u, 	XTHAL_AR_RWrw,  XTHAL_MEM_NON_CACHEABLE|XTHAL_MEM_SYSTEM_SHAREABLE|XTHAL_MEM_BUFFERABLE),  			//for MSCM register access (same address space on SAF85XX and S32R41)
		XTHAL_MPU_ENTRY(0x40011000, 1u, 	XTHAL_AR_NONE,  XTHAL_MEM_DEVICE|XTHAL_MEM_NON_SHAREABLE),       								//not used

























};

const unsigned int __xt_mpu_init_table_size __attribute__((section(".ResetHandler.text"))) =
    sizeof(__xt_mpu_init_table) / sizeof(struct xthal_MPU_entry);
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

static void SptEvtIsrCb(uint32_t evtId)
{
	if(numEvts >= MAX_EVENTS_QUEUE)
	{
		numEvts = 0;
	}
	eventsQ[numEvts] = evtId;
	numEvts++;

	//for debug: write the event info into one of the DSP_DEBUG<n>_REG registers :
	BBX_SCRLU(0x2000 + evtId, ADDR_DSP_DEBUG6_REG);
}













int main()
{
	rsdkStatus_t dspStatus;
	dspDispInit_t dispInitInfo;

	dispInitInfo.sptEvtIsrCb = SptEvtIsrCb;
	dispInitInfo.sptEvtIntEnBitmap = (RSDK_DSP_SPT_EVT0_INTEN_BIT | RSDK_DSP_SPT_EVT1_INTEN_BIT | RSDK_DSP_SPT_EVT2_INTEN_BIT | RSDK_DSP_SPT_EVT3_INTEN_BIT |
								  RSDK_DSP_SPT_EVT4_INTEN_BIT | RSDK_DSP_SPT_EVT5_INTEN_BIT | RSDK_DSP_SPT_EVT6_INTEN_BIT | RSDK_DSP_SPT_EVT7_INTEN_BIT |
								  RSDK_DSP_SPT_EVT8_INTEN_BIT | RSDK_DSP_SPT_EVT9_INTEN_BIT | RSDK_DSP_SPT_EVT10_INTEN_BIT | RSDK_DSP_SPT_EVT11_INTEN_BIT |
								  RSDK_DSP_SPT_EVT12_INTEN_BIT ); //enable all SPT Events

	dispInitInfo.pFuncTable = gDspDispatcherFuncTable;
	dispInitInfo.funcTableSize = DSP_DISP_FUNC_TABLE_SIZE;

	dispInitInfo.commParams.ipcfInstance = IPCF_INSTANCE;
	dispInitInfo.commParams.ctrlChanId = CTRL_CHAN_ID;
	dispInitInfo.commParams.asyncChanId = ASYNC_CHAN_ID;


	//send a sign of life for debug: write a marker into one of the DSP_DEBUG<n>_REG registers
    BBX_SCRLU(0x1000, ADDR_DSP_DEBUG6_REG);





    // configure params for prefetch aggressiveness
	dispInitInfo.prefAggrParams.prefetchAggressionData = 0xFu;
	dispInitInfo.prefAggrParams.prefetchAggressionInstr = 0xFu;
	dispInitInfo.prefAggrParams.prefetchAggressionSW = 0xFu;


    dspStatus = RsdkDspDispatcherInit(&dispInitInfo);
    if(dspStatus != RSDK_SUCCESS)
    {
        while(1);
    }

    RsdkDspDispatcherRun();

    //the dispatcher runs an infinite loop; it should never get here
    while (1)
        ;

    return 0;
}

/*================================================================================================*/

#ifdef __cplusplus
}
#endif

/*******************************************************************************
 * EOF
 ******************************************************************************/
