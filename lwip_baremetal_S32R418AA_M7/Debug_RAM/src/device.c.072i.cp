
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  Gmac_Ip_Init/23:
  Jump functions of caller  OsIf_SetTimerFrequency/22:
  Jump functions of caller  Pit_Ip_StartChannel/21:
  Jump functions of caller  Pit_Ip_EnableChannelInterrupt/20:
  Jump functions of caller  Pit_Ip_InitChannel/18:
  Jump functions of caller  Pit_Ip_Init/16:
  Jump functions of caller  OsIf_Init/15:
  Jump functions of caller  GMAC0_CH0_RX_IRQHandler/14:
  Jump functions of caller  GMAC0_CH0_TX_IRQHandler/13:
  Jump functions of caller  IntCtrl_Ip_EnableIrq/12:
  Jump functions of caller  IntCtrl_Ip_SetPriority/11:
  Jump functions of caller  PIT_0_ISR/10:
  Jump functions of caller  IntCtrl_Ip_InstallHandler/9:
  Jump functions of caller  Clock_Ip_Init/7:
  Jump functions of caller  Siul2_Port_Ip_Init/5:
  Jump functions of caller  device_init/4:
    callsite  device_init/4 -> DevAssert/1 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0x1
         Unknown VR
    callsite  device_init/4 -> DevAssert/1 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0x1
         Unknown VR
    callsite  device_init/4 -> DevAssert/1 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0x1
         Unknown VR
    callsite  device_init/4 -> DevAssert/1 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0x1
         Unknown VR
  Jump functions of caller  DevAssert/1:

 Propagating constants:

Not considering device_init for cloning; -fipa-cp-clone disabled.

overall_size: 82, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: device_init/4:
  Node: DevAssert/1:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

Gmac_0_ConfigPB_BOARD_INITPERIPHERALS/24 (Gmac_0_ConfigPB_BOARD_INITPERIPHERALS) @08250a20
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: device_init/4 (addr)
  Availability: not_available
  Varpool flags: read-only
Gmac_Ip_Init/23 (Gmac_Ip_Init) @08253000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: device_init/4 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
OsIf_SetTimerFrequency/22 (OsIf_SetTimerFrequency) @08251ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: device_init/4 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Pit_Ip_StartChannel/21 (Pit_Ip_StartChannel) @08251e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: device_init/4 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Pit_Ip_EnableChannelInterrupt/20 (Pit_Ip_EnableChannelInterrupt) @08251d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: device_init/4 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
PIT_0_ChannelConfig_PB_BOARD_InitPeripherals/19 (PIT_0_ChannelConfig_PB_BOARD_InitPeripherals) @08250870
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: device_init/4 (addr)
  Availability: not_available
  Varpool flags: read-only
Pit_Ip_InitChannel/18 (Pit_Ip_InitChannel) @08251c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: device_init/4 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
PIT_0_InitConfig_PB_BOARD_InitPeripherals/17 (PIT_0_InitConfig_PB_BOARD_InitPeripherals) @082507e0
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: device_init/4 (addr)
  Availability: not_available
  Varpool flags: read-only
Pit_Ip_Init/16 (Pit_Ip_Init) @08251a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: device_init/4 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
OsIf_Init/15 (OsIf_Init) @082519a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: device_init/4 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
GMAC0_CH0_RX_IRQHandler/14 (GMAC0_CH0_RX_IRQHandler) @082518c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: device_init/4 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
GMAC0_CH0_TX_IRQHandler/13 (GMAC0_CH0_TX_IRQHandler) @082517e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: device_init/4 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
IntCtrl_Ip_EnableIrq/12 (IntCtrl_Ip_EnableIrq) @08251700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: device_init/4 (1073741824 (estimated locally),1.00 per call) device_init/4 (1073741824 (estimated locally),1.00 per call) device_init/4 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
IntCtrl_Ip_SetPriority/11 (IntCtrl_Ip_SetPriority) @08251620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: device_init/4 (1073741824 (estimated locally),1.00 per call) device_init/4 (1073741824 (estimated locally),1.00 per call) device_init/4 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
PIT_0_ISR/10 (PIT_0_ISR) @08251540
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: device_init/4 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
IntCtrl_Ip_InstallHandler/9 (IntCtrl_Ip_InstallHandler) @08251460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: device_init/4 (1073741824 (estimated locally),1.00 per call) device_init/4 (1073741824 (estimated locally),1.00 per call) device_init/4 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Clock_Ip_aClockConfig/8 (Clock_Ip_aClockConfig) @082503f0
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: device_init/4 (addr)
  Availability: not_available
  Varpool flags: read-only
Clock_Ip_Init/7 (Clock_Ip_Init) @08251380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: device_init/4 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
g_pin_mux_InitConfigArr_PortContainer_0_BOARD_InitPeripherals/6 (g_pin_mux_InitConfigArr_PortContainer_0_BOARD_InitPeripherals) @08250318
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: device_init/4 (addr)
  Availability: not_available
  Varpool flags: read-only
Siul2_Port_Ip_Init/5 (Siul2_Port_Ip_Init) @082512a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: device_init/4 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
device_init/4 (device_init) @083348c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: g_pin_mux_InitConfigArr_PortContainer_0_BOARD_InitPeripherals/6 (addr)Clock_Ip_aClockConfig/8 (addr)PIT_0_ISR/10 (addr)GMAC0_CH0_TX_IRQHandler/13 (addr)GMAC0_CH0_RX_IRQHandler/14 (addr)PIT_0_InitConfig_PB_BOARD_InitPeripherals/17 (addr)PIT_0_ChannelConfig_PB_BOARD_InitPeripherals/19 (addr)Gmac_0_ConfigPB_BOARD_INITPERIPHERALS/24 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: DevAssert/1 (1073741824 (estimated locally),1.00 per call) Gmac_Ip_Init/23 (1073741824 (estimated locally),1.00 per call) OsIf_SetTimerFrequency/22 (1073741824 (estimated locally),1.00 per call) DevAssert/1 (1073741824 (estimated locally),1.00 per call) Pit_Ip_StartChannel/21 (1073741824 (estimated locally),1.00 per call) Pit_Ip_EnableChannelInterrupt/20 (1073741824 (estimated locally),1.00 per call) Pit_Ip_InitChannel/18 (1073741824 (estimated locally),1.00 per call) Pit_Ip_Init/16 (1073741824 (estimated locally),1.00 per call) OsIf_Init/15 (1073741824 (estimated locally),1.00 per call) IntCtrl_Ip_EnableIrq/12 (1073741824 (estimated locally),1.00 per call) IntCtrl_Ip_SetPriority/11 (1073741824 (estimated locally),1.00 per call) IntCtrl_Ip_InstallHandler/9 (1073741824 (estimated locally),1.00 per call) IntCtrl_Ip_EnableIrq/12 (1073741824 (estimated locally),1.00 per call) IntCtrl_Ip_SetPriority/11 (1073741824 (estimated locally),1.00 per call) IntCtrl_Ip_InstallHandler/9 (1073741824 (estimated locally),1.00 per call) IntCtrl_Ip_EnableIrq/12 (1073741824 (estimated locally),1.00 per call) IntCtrl_Ip_SetPriority/11 (1073741824 (estimated locally),1.00 per call) IntCtrl_Ip_InstallHandler/9 (1073741824 (estimated locally),1.00 per call) DevAssert/1 (1073741824 (estimated locally),1.00 per call) Clock_Ip_Init/7 (1073741824 (estimated locally),1.00 per call) DevAssert/1 (1073741824 (estimated locally),1.00 per call) Siul2_Port_Ip_Init/5 (1073741824 (estimated locally),1.00 per call) 
DevAssert/1 (DevAssert) @08109c40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:214748 (estimated locally) body local optimize_size
  Called by: device_init/4 (1073741824 (estimated locally),1.00 per call) device_init/4 (1073741824 (estimated locally),1.00 per call) device_init/4 (1073741824 (estimated locally),1.00 per call) device_init/4 (1073741824 (estimated locally),1.00 per call) 
  Calls: 

;; Function device_init (device_init, funcdef_no=4, decl_uid=9587, cgraph_uid=5, symbol_order=4)

Modification phase of node device_init/4
device_init ()
{
  StatusType err;
  long unsigned int _1;
  long unsigned int _2;
  _Bool _3;
  _Bool _4;
  _Bool _5;
  <unnamed type> _6;
  _Bool _7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct SRC_Type *)1074627328B].GMAC_0_CTRL_STS;
  _2 = _1 | 4;
  MEM[(struct SRC_Type *)1074627328B].GMAC_0_CTRL_STS ={v} _2;
  # DEBUG BEGIN_STMT
  err_11 = Siul2_Port_Ip_Init (9, &g_pin_mux_InitConfigArr_PortContainer_0_BOARD_InitPeripherals);
  # DEBUG err => err_11
  # DEBUG BEGIN_STMT
  _3 = err_11 == 0;
  DevAssert (_3);
  # DEBUG BEGIN_STMT
  err_14 = Clock_Ip_Init (&Clock_Ip_aClockConfig[0]);
  # DEBUG err => err_14
  # DEBUG BEGIN_STMT
  _4 = err_14 == 0;
  DevAssert (_4);
  # DEBUG BEGIN_STMT
  IntCtrl_Ip_InstallHandler (53, PIT_0_ISR, 0B);
  # DEBUG BEGIN_STMT
  IntCtrl_Ip_SetPriority (53, 9);
  # DEBUG BEGIN_STMT
  IntCtrl_Ip_EnableIrq (53);
  # DEBUG BEGIN_STMT
  IntCtrl_Ip_InstallHandler (58, GMAC0_CH0_TX_IRQHandler, 0B);
  # DEBUG BEGIN_STMT
  IntCtrl_Ip_SetPriority (58, 8);
  # DEBUG BEGIN_STMT
  IntCtrl_Ip_EnableIrq (58);
  # DEBUG BEGIN_STMT
  IntCtrl_Ip_InstallHandler (59, GMAC0_CH0_RX_IRQHandler, 0B);
  # DEBUG BEGIN_STMT
  IntCtrl_Ip_SetPriority (59, 7);
  # DEBUG BEGIN_STMT
  IntCtrl_Ip_EnableIrq (59);
  # DEBUG BEGIN_STMT
  # DEBUG INLINE_ENTRY NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG instance => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  OsIf_Init (0B);
  # DEBUG BEGIN_STMT
  Pit_Ip_Init (0, &PIT_0_InitConfig_PB_BOARD_InitPeripherals);
  # DEBUG BEGIN_STMT
  Pit_Ip_InitChannel (0, &PIT_0_ChannelConfig_PB_BOARD_InitPeripherals[0]);
  # DEBUG BEGIN_STMT
  Pit_Ip_EnableChannelInterrupt (0, 0);
  # DEBUG BEGIN_STMT
  err_30 = Pit_Ip_StartChannel (0, 0, 100000);
  # DEBUG err => err_30
  # DEBUG BEGIN_STMT
  _5 = err_30 == 0;
  DevAssert (_5);
  # DEBUG BEGIN_STMT
  OsIf_SetTimerFrequency (400000000, 0);
  # DEBUG BEGIN_STMT
  _6 = Gmac_Ip_Init (0, &Gmac_0_ConfigPB_BOARD_INITPERIPHERALS);
  err_34 = (StatusType) _6;
  # DEBUG err => err_34
  # DEBUG BEGIN_STMT
  _7 = err_34 == 0;
  DevAssert (_7);
  return;

}


