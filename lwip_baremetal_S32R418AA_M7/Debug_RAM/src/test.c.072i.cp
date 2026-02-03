
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  mainLoopTask.isra.0/55:
    callsite  mainLoopTask.isra.0/55 -> process_udp_send/15 : 
    callsite  mainLoopTask.isra.0/55 -> test_init.isra.0/53 : 
  Jump functions of caller  process_udp_send.part.0/54:
  Jump functions of caller  test_init.isra.0/53:
    callsite  test_init.isra.0/53 -> apps_init/17 : 
    callsite  test_init.isra.0/53 -> interface_init/8 : 
  Jump functions of caller  Stm_Ip_StartCounting/52:
  Jump functions of caller  Stm_Ip_EnableChannel/51:
  Jump functions of caller  Stm_Ip_InitChannel/49:
  Jump functions of caller  Stm_Ip_Init/48:
  Jump functions of caller  IntCtrl_Ip_Init/46:
  Jump functions of caller  ipaddr_aton/45:
  Jump functions of caller  memset/44:
  Jump functions of caller  udp_bind/42:
  Jump functions of caller  udp_new/41:
  Jump functions of caller  lwiperf_start_tcp_server_default/40:
  Jump functions of caller  mdns_resp_add_netif/39:
  Jump functions of caller  mdns_resp_init/37:
  Jump functions of caller  netif_set_up/36:
  Jump functions of caller  netif_create_ip6_linklocal_address/35:
  Jump functions of caller  netif_set_default/34:
  Jump functions of caller  netif_input/33:
  Jump functions of caller  gmac_ethernetif_init/32:
  Jump functions of caller  netif_add/31:
  Jump functions of caller  end_tcpip_execution/29:
  Jump functions of caller  gmac_ethernetif_shutdown/28:
  Jump functions of caller  OsIf_GetMilliseconds/27:
  Jump functions of caller  sys_check_timeouts/26:
  Jump functions of caller  lwip_init/25:
  Jump functions of caller  sys_init/24:
  Jump functions of caller  pbuf_free/23:
  Jump functions of caller  udp_sendto/22:
  Jump functions of caller  pbuf_alloc/21:
  Jump functions of caller  start_example/20:
    callsite  start_example/20 -> mainLoopTask.isra.0/55 : 
  Jump functions of caller  apps_init/17:
    callsite  apps_init/17 -> my_udp_init/16 : 
  Jump functions of caller  my_udp_init/16:
  Jump functions of caller  process_udp_send/15:
    callsite  process_udp_send/15 -> process_udp_send.part.0/54 : 
  Jump functions of caller  StmNotification/14:
  Jump functions of caller  lwiperf_report/9:
  Jump functions of caller  interface_init/8:

 Propagating constants:

Not considering start_example for cloning; -fipa-cp-clone disabled.
Not considering process_udp_send for cloning; -fipa-cp-clone disabled.
Not considering StmNotification for cloning; -fipa-cp-clone disabled.
Not considering lwiperf_report for cloning; -fipa-cp-clone disabled.

overall_size: 204, max_new_size: 11001
 - context independent values, size: 3, time_benefit: 9.000000

IPA lattices after all propagation:

Lattices:
  Node: mainLoopTask.isra.0/55:
  Node: process_udp_send.part.0/54:
  Node: test_init.isra.0/53:
  Node: start_example/20:
  Node: apps_init/17:
  Node: my_udp_init/16:
  Node: process_udp_send/15:
  Node: StmNotification/14:
  Node: lwiperf_report/9:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [3]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [4]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [5]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [6]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [7]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [8]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: interface_init/8:

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

mainLoopTask.isra.0/55 (mainLoopTask.isra.0) @06b66b60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: network_interfaces/6 (addr)
  Referring: 
  Availability: local
  Function flags: count:11811 (estimated locally) body local executed_once optimize_size
  Called by: start_example/20 (1073741824 (estimated locally),1.00 per call) 
  Calls: end_tcpip_execution/29 (118111601 (estimated locally),10000.14 per call) gmac_ethernetif_shutdown/28 (118111601 (estimated locally),10000.14 per call) OsIf_GetMilliseconds/27 (1073741824 (estimated locally),90910.32 per call) process_udp_send/15 (1073741824 (estimated locally),90910.32 per call) sys_check_timeouts/26 (1073741824 (estimated locally),90910.32 per call) test_init.isra.0/53 (11811 (estimated locally),1.00 per call) lwip_init/25 (11811 (estimated locally),1.00 per call) sys_init/24 (11811 (estimated locally),1.00 per call) 
process_udp_send.part.0/54 (process_udp_send.part.0) @06b668c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: udp_send_flag/12 (write)my_udp_buffer/11 (addr)my_udp_pcb/10 (read)g_dest_addr/13 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: process_udp_send/15 (354334800 (estimated locally),0.33 per call) 
  Calls: pbuf_alloc/21 (1073741824 (estimated locally),1.00 per call) udp_sendto/22 (574129754 (estimated locally),0.53 per call) pbuf_free/23 (574129754 (estimated locally),0.53 per call) 
test_init.isra.0/53 (test_init.isra.0) @06b66460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local executed_once optimize_size
  Called by: mainLoopTask.isra.0/55 (11811 (estimated locally),1.00 per call) 
  Calls: apps_init/17 (1073741824 (estimated locally),1.00 per call) interface_init/8 (1073741824 (estimated locally),1.00 per call) 
Stm_Ip_StartCounting/52 (Stm_Ip_StartCounting) @084a6700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: my_udp_init/16 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Stm_Ip_EnableChannel/51 (Stm_Ip_EnableChannel) @084a6620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: my_udp_init/16 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
STM_0_ChannelConfig_PB_BOARD_InitPeripherals/50 (STM_0_ChannelConfig_PB_BOARD_InitPeripherals) @084a7168
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: my_udp_init/16 (addr)
  Availability: not_available
  Varpool flags: read-only
Stm_Ip_InitChannel/49 (Stm_Ip_InitChannel) @084a6540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: my_udp_init/16 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Stm_Ip_Init/48 (Stm_Ip_Init) @084a6460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: my_udp_init/16 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
IntCtrlConfig_0/47 (IntCtrlConfig_0) @084a7090
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: my_udp_init/16 (addr)
  Availability: not_available
  Varpool flags: read-only
IntCtrl_Ip_Init/46 (IntCtrl_Ip_Init) @084a6380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: my_udp_init/16 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
ipaddr_aton/45 (ipaddr_aton) @084a61c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: my_udp_init/16 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
memset/44 (memset) @084a60e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: my_udp_init/16 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
ip_addr_any/43 (ip_addr_any) @08483f30
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: my_udp_init/16 (addr)
  Availability: not_available
  Varpool flags: read-only
udp_bind/42 (udp_bind) @084a6000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: my_udp_init/16 (574129754 (estimated locally),0.53 per call) 
  Calls: 
udp_new/41 (udp_new) @08482540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: my_udp_init/16 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
lwiperf_start_tcp_server_default/40 (lwiperf_start_tcp_server_default) @08482e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: apps_init/17 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
mdns_resp_add_netif/39 (mdns_resp_add_netif) @08482d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: apps_init/17 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
netif_default/38 (netif_default) @08483a68
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: apps_init/17 (read)
  Availability: not_available
  Varpool flags:
mdns_resp_init/37 (mdns_resp_init) @08482c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: apps_init/17 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
netif_set_up/36 (netif_set_up) @08482a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: interface_init/8 (536870913 (estimated locally),1.00 per call) 
  Calls: 
netif_create_ip6_linklocal_address/35 (netif_create_ip6_linklocal_address) @084829a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: interface_init/8 (177167401 (estimated locally),0.33 per call) 
  Calls: 
netif_set_default/34 (netif_set_default) @084828c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: interface_init/8 (536870913 (estimated locally),1.00 per call) 
  Calls: 
netif_input/33 (netif_input) @084827e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: interface_init/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
gmac_ethernetif_init/32 (gmac_ethernetif_init) @08482700
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: interface_init/8 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
netif_add/31 (netif_add) @08482620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: interface_init/8 (536870913 (estimated locally),1.00 per call) 
  Calls: 
netif_cfg/30 (netif_cfg) @084836c0
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: interface_init/8 (read)interface_init/8 (read)
  Availability: not_available
  Varpool flags:
end_tcpip_execution/29 (end_tcpip_execution) @084822a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mainLoopTask.isra.0/55 (118111601 (estimated locally),10000.14 per call) 
  Calls: 
gmac_ethernetif_shutdown/28 (gmac_ethernetif_shutdown) @084821c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mainLoopTask.isra.0/55 (118111601 (estimated locally),10000.14 per call) 
  Calls: 
OsIf_GetMilliseconds/27 (OsIf_GetMilliseconds) @084820e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mainLoopTask.isra.0/55 (1073741824 (estimated locally),90910.32 per call) 
  Calls: 
sys_check_timeouts/26 (sys_check_timeouts) @08482000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mainLoopTask.isra.0/55 (1073741824 (estimated locally),90910.32 per call) 
  Calls: 
lwip_init/25 (lwip_init) @0847d620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mainLoopTask.isra.0/55 (11811 (estimated locally),1.00 per call) 
  Calls: 
sys_init/24 (sys_init) @0847d380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mainLoopTask.isra.0/55 (11811 (estimated locally),1.00 per call) 
  Calls: 
pbuf_free/23 (pbuf_free) @0847dee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: process_udp_send.part.0/54 (574129754 (estimated locally),0.53 per call) 
  Calls: 
udp_sendto/22 (udp_sendto) @0847de00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: process_udp_send.part.0/54 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pbuf_alloc/21 (pbuf_alloc) @0847dd20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: process_udp_send.part.0/54 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
start_example/20 (start_example) @0847d7e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body executed_once optimize_size
  Called by: 
  Calls: mainLoopTask.isra.0/55 (1073741824 (estimated locally),1.00 per call) 
apps_init/17 (apps_init) @08343ee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: netif_default/38 (read)lwiperf_report/9 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local executed_once optimize_size
  Called by: test_init.isra.0/53 (1073741824 (estimated locally),1.00 per call) 
  Calls: my_udp_init/16 (1073741824 (estimated locally),1.00 per call) lwiperf_start_tcp_server_default/40 (1073741824 (estimated locally),1.00 per call) mdns_resp_add_netif/39 (1073741824 (estimated locally),1.00 per call) mdns_resp_init/37 (1073741824 (estimated locally),1.00 per call) 
my_udp_init/16 (my_udp_init) @08343c40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: my_udp_pcb/10 (write)ip_addr_any/43 (addr)my_udp_buffer/11 (addr)g_dest_addr/13 (addr)IntCtrlConfig_0/47 (addr)STM_0_ChannelConfig_PB_BOARD_InitPeripherals/50 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local executed_once optimize_size
  Called by: apps_init/17 (1073741824 (estimated locally),1.00 per call) 
  Calls: Stm_Ip_StartCounting/52 (1073741824 (estimated locally),1.00 per call) Stm_Ip_EnableChannel/51 (1073741824 (estimated locally),1.00 per call) Stm_Ip_InitChannel/49 (1073741824 (estimated locally),1.00 per call) Stm_Ip_Init/48 (1073741824 (estimated locally),1.00 per call) IntCtrl_Ip_Init/46 (1073741824 (estimated locally),1.00 per call) ipaddr_aton/45 (1073741824 (estimated locally),1.00 per call) memset/44 (1073741824 (estimated locally),1.00 per call) udp_bind/42 (574129754 (estimated locally),0.53 per call) udp_new/41 (1073741824 (estimated locally),1.00 per call) 
process_udp_send/15 (process_udp_send) @083439a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: udp_send_flag/12 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: mainLoopTask.isra.0/55 (1073741824 (estimated locally),90910.32 per call) 
  Calls: process_udp_send.part.0/54 (354334800 (estimated locally),0.33 per call) 
StmNotification/14 (StmNotification) @08343700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: udp_send_flag/12 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
g_dest_addr/13 (g_dest_addr) @08344288
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: my_udp_init/16 (addr)process_udp_send.part.0/54 (addr)
  Availability: available
  Varpool flags:
udp_send_flag/12 (udp_send_flag) @083441f8
  Type: variable definition analyzed
  Visibility: force_output externally_visible public
  References: 
  Referring: StmNotification/14 (write)process_udp_send.part.0/54 (write)process_udp_send/15 (read)
  Availability: available
  Varpool flags: initialized
my_udp_buffer/11 (my_udp_buffer) @08344168
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: my_udp_init/16 (addr)process_udp_send.part.0/54 (addr)
  Availability: available
  Varpool flags:
my_udp_pcb/10 (my_udp_pcb) @083440d8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: my_udp_init/16 (write)process_udp_send.part.0/54 (read)
  Availability: available
  Varpool flags:
lwiperf_report/9 (lwiperf_report) @083430e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: apps_init/17 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
interface_init/8 (interface_init) @0832dee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: netif_cfg/30 (read)network_interfaces/6 (addr)gmac_ethernetif_init/32 (addr)netif_input/33 (addr)netif_cfg/30 (read)network_interfaces/6 (addr)network_interfaces/6 (addr)
  Referring: 
  Availability: local
  Function flags: count:536870913 (estimated locally) body local executed_once optimize_size
  Called by: test_init.isra.0/53 (1073741824 (estimated locally),1.00 per call) 
  Calls: netif_set_up/36 (536870913 (estimated locally),1.00 per call) netif_create_ip6_linklocal_address/35 (177167401 (estimated locally),0.33 per call) netif_set_default/34 (536870913 (estimated locally),1.00 per call) netif_add/31 (536870913 (estimated locally),1.00 per call) 
g_init_sem/7 (g_init_sem) @0832e240
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Varpool flags:
network_interfaces/6 (network_interfaces) @0832e1b0
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: interface_init/8 (addr)interface_init/8 (addr)interface_init/8 (addr)mainLoopTask.isra.0/55 (addr)
  Availability: available
  Varpool flags:

;; Function lwiperf_report (lwiperf_report, funcdef_no=6, decl_uid=12952, cgraph_uid=7, symbol_order=9)

Modification phase of node lwiperf_report/9
lwiperf_report (void * arg, lwiperf_report_type report_type, const struct ip_addr_t * local_addr, u16_t local_port, const struct ip_addr_t * remote_addr, u16_t remote_port, u32_t bytes_transferred, u32_t ms_duration, u32_t bandwidth_kbitpsec)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return;

}



;; Function StmNotification (StmNotification, funcdef_no=7, decl_uid=12959, cgraph_uid=8, symbol_order=14)

Modification phase of node StmNotification/14
StmNotification ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  udp_send_flag ={v} 1;
  return;

}



;; Function process_udp_send (process_udp_send, funcdef_no=8, decl_uid=12962, cgraph_uid=9, symbol_order=15)

Modification phase of node process_udp_send/15
process_udp_send ()
{
  unsigned char udp_send_flag.0_1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  udp_send_flag.0_1 ={v} udp_send_flag;
  if (udp_send_flag.0_1 != 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334800]:
  process_udp_send.part.0 ();

  <bb 4> [local count: 1073741824]:
  return;

}



;; Function start_example (start_example, funcdef_no=13, decl_uid=12932, cgraph_uid=14, symbol_order=20) (executed once)

Modification phase of node start_example/20
start_example ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG D#2 => 0B
  mainLoopTask.isra.0 ();

}


