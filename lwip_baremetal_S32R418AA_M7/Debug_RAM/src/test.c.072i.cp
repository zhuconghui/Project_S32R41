
IPA constant propagation start:
Determining dynamic type for call: udp_perf_recv.part.0 (p_1(D));
  Starting walk at: udp_perf_recv.part.0 (p_1(D));
  instance pointer: p_1(D)  Outer instance pointer: p_1(D) offset: 0 (bits) vtbl reference: 

IPA structures before propagation:

Jump functions:
  Jump functions of caller  mainLoopTask.isra.0/52:
    callsite  mainLoopTask.isra.0/52 -> test_init.isra.0/51 : 
  Jump functions of caller  test_init.isra.0/51:
    callsite  test_init.isra.0/51 -> apps_init/18 : 
    callsite  test_init.isra.0/51 -> interface_init/7 : 
  Jump functions of caller  udp_perf_recv.part.0/50:
  Jump functions of caller  udp_recv/49:
  Jump functions of caller  pbuf_free/48:
  Jump functions of caller  udp_sendto/47:
  Jump functions of caller  ipaddr_aton/46:
  Jump functions of caller  pbuf_take/45:
  Jump functions of caller  pbuf_alloc/44:
  Jump functions of caller  memset/43:
  Jump functions of caller  sys_timeout/42:
  Jump functions of caller  udp_bind/40:
  Jump functions of caller  udp_new/39:
  Jump functions of caller  lwiperf_start_tcp_server_default/38:
  Jump functions of caller  mdns_resp_add_netif/37:
  Jump functions of caller  mdns_resp_init/35:
  Jump functions of caller  netif_set_up/34:
  Jump functions of caller  netif_create_ip6_linklocal_address/33:
  Jump functions of caller  netif_set_default/32:
  Jump functions of caller  netif_input/31:
  Jump functions of caller  gmac_ethernetif_init/30:
  Jump functions of caller  netif_add/29:
  Jump functions of caller  end_tcpip_execution/27:
  Jump functions of caller  gmac_ethernetif_shutdown/26:
  Jump functions of caller  OsIf_GetMilliseconds/25:
  Jump functions of caller  sys_check_timeouts/24:
  Jump functions of caller  lwip_init/23:
  Jump functions of caller  sys_init/22:
  Jump functions of caller  start_example/21:
    callsite  start_example/21 -> mainLoopTask.isra.0/52 : 
  Jump functions of caller  apps_init/18:
    callsite  apps_init/18 -> udp_perf_init/17 : 
    callsite  apps_init/18 -> my_udp_init/12 : 
  Jump functions of caller  udp_perf_init/17:
  Jump functions of caller  udp_perf_report/16:
  Jump functions of caller  udp_perf_recv/15:
    callsite  udp_perf_recv/15 -> udp_perf_recv.part.0/50 : 
       param 0: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  my_udp_init/12:
  Jump functions of caller  my_udp_send_callback/11:
  Jump functions of caller  lwiperf_report/8:
  Jump functions of caller  interface_init/7:

 Propagating constants:

Not considering start_example for cloning; -fipa-cp-clone disabled.
Not considering udp_perf_report for cloning; -fipa-cp-clone disabled.
Not considering udp_perf_recv for cloning; -fipa-cp-clone disabled.
Not considering my_udp_send_callback for cloning; -fipa-cp-clone disabled.
Not considering lwiperf_report for cloning; -fipa-cp-clone disabled.

overall_size: 238, max_new_size: 11001
 - context independent values, size: 9, time_benefit: 1.000000
 - context independent values, size: 7, time_benefit: 4.000000
 - context independent values, size: 36, time_benefit: 1.000000
 - context independent values, size: 3, time_benefit: 9.000000

IPA lattices after all propagation:

Lattices:
  Node: mainLoopTask.isra.0/52:
  Node: test_init.isra.0/51:
  Node: udp_perf_recv.part.0/50:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: start_example/21:
  Node: apps_init/18:
  Node: udp_perf_init/17:
  Node: udp_perf_report/16:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: udp_perf_recv/15:
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
  Node: my_udp_init/12:
  Node: my_udp_send_callback/11:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: lwiperf_report/8:
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
  Node: interface_init/7:

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

mainLoopTask.isra.0/52 (mainLoopTask.isra.0) @06ba5b60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: network_interfaces/5 (addr)
  Referring: 
  Availability: local
  Function flags: count:11811 (estimated locally) body local executed_once optimize_size
  Called by: start_example/21 (1073741824 (estimated locally),1.00 per call) 
  Calls: end_tcpip_execution/27 (118111601 (estimated locally),10000.14 per call) gmac_ethernetif_shutdown/26 (118111601 (estimated locally),10000.14 per call) OsIf_GetMilliseconds/25 (1073741824 (estimated locally),90910.32 per call) sys_check_timeouts/24 (1073741824 (estimated locally),90910.32 per call) test_init.isra.0/51 (11811 (estimated locally),1.00 per call) lwip_init/23 (11811 (estimated locally),1.00 per call) sys_init/22 (11811 (estimated locally),1.00 per call) 
test_init.isra.0/51 (test_init.isra.0) @06ba58c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local executed_once optimize_size
  Called by: mainLoopTask.isra.0/52 (11811 (estimated locally),1.00 per call) 
  Calls: apps_init/18 (1073741824 (estimated locally),1.00 per call) interface_init/7 (1073741824 (estimated locally),1.00 per call) 
udp_perf_recv.part.0/50 (udp_perf_recv.part.0) @06ba5460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: udp_perf_rx_bytes/14 (read)udp_perf_rx_bytes/14 (write)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: udp_perf_recv/15 (574129752 (estimated locally),0.53 per call) 
  Calls: pbuf_free/48 (1073741824 (estimated locally),1.00 per call) 
udp_recv/49 (udp_recv) @07252540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: udp_perf_init/17 (189462818 (estimated locally),0.18 per call) 
  Calls: 
pbuf_free/48 (pbuf_free) @07252380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: udp_perf_recv.part.0/50 (1073741824 (estimated locally),1.00 per call) my_udp_send_callback/11 (574129754 (estimated locally),0.53 per call) 
  Calls: 
udp_sendto/47 (udp_sendto) @072522a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: my_udp_send_callback/11 (189462818 (estimated locally),0.18 per call) 
  Calls: 
ipaddr_aton/46 (ipaddr_aton) @072521c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: my_udp_send_callback/11 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pbuf_take/45 (pbuf_take) @072520e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: my_udp_send_callback/11 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pbuf_alloc/44 (pbuf_alloc) @07252000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: my_udp_send_callback/11 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
memset/43 (memset) @072211c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: my_udp_send_callback/11 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
sys_timeout/42 (sys_timeout) @07221ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: udp_perf_init/17 (189462818 (estimated locally),0.18 per call) my_udp_send_callback/11 (1073741824 (estimated locally),1.00 per call) udp_perf_report/16 (1073741824 (estimated locally),1.00 per call) my_udp_init/12 (574129754 (estimated locally),0.53 per call) 
  Calls: 
ip_addr_any/41 (ip_addr_any) @07250000
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: my_udp_init/12 (addr)udp_perf_init/17 (addr)
  Availability: not_available
  Varpool flags: read-only
udp_bind/40 (udp_bind) @07221e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: udp_perf_init/17 (574129754 (estimated locally),0.53 per call) my_udp_init/12 (574129754 (estimated locally),0.53 per call) 
  Calls: 
udp_new/39 (udp_new) @07221d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: udp_perf_init/17 (1073741824 (estimated locally),1.00 per call) my_udp_init/12 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
lwiperf_start_tcp_server_default/38 (lwiperf_start_tcp_server_default) @07221a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: apps_init/18 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
mdns_resp_add_netif/37 (mdns_resp_add_netif) @072219a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: apps_init/18 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
netif_default/36 (netif_default) @07220ab0
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: apps_init/18 (read)
  Availability: not_available
  Varpool flags:
mdns_resp_init/35 (mdns_resp_init) @072218c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: apps_init/18 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
netif_set_up/34 (netif_set_up) @07221700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: interface_init/7 (536870913 (estimated locally),1.00 per call) 
  Calls: 
netif_create_ip6_linklocal_address/33 (netif_create_ip6_linklocal_address) @07221620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: interface_init/7 (177167401 (estimated locally),0.33 per call) 
  Calls: 
netif_set_default/32 (netif_set_default) @07221540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: interface_init/7 (536870913 (estimated locally),1.00 per call) 
  Calls: 
netif_input/31 (netif_input) @07221460
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: interface_init/7 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
gmac_ethernetif_init/30 (gmac_ethernetif_init) @07221380
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: interface_init/7 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
netif_add/29 (netif_add) @072212a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: interface_init/7 (536870913 (estimated locally),1.00 per call) 
  Calls: 
netif_cfg/28 (netif_cfg) @072206c0
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: interface_init/7 (read)interface_init/7 (read)
  Availability: not_available
  Varpool flags:
end_tcpip_execution/27 (end_tcpip_execution) @07171620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mainLoopTask.isra.0/52 (118111601 (estimated locally),10000.14 per call) 
  Calls: 
gmac_ethernetif_shutdown/26 (gmac_ethernetif_shutdown) @07171380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mainLoopTask.isra.0/52 (118111601 (estimated locally),10000.14 per call) 
  Calls: 
OsIf_GetMilliseconds/25 (OsIf_GetMilliseconds) @071710e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mainLoopTask.isra.0/52 (1073741824 (estimated locally),90910.32 per call) 
  Calls: 
sys_check_timeouts/24 (sys_check_timeouts) @07171ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mainLoopTask.isra.0/52 (1073741824 (estimated locally),90910.32 per call) 
  Calls: 
lwip_init/23 (lwip_init) @07171e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mainLoopTask.isra.0/52 (11811 (estimated locally),1.00 per call) 
  Calls: 
sys_init/22 (sys_init) @07171d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mainLoopTask.isra.0/52 (11811 (estimated locally),1.00 per call) 
  Calls: 
start_example/21 (start_example) @071717e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body executed_once optimize_size
  Called by: 
  Calls: mainLoopTask.isra.0/52 (1073741824 (estimated locally),1.00 per call) 
apps_init/18 (apps_init) @07171000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: netif_default/36 (read)lwiperf_report/8 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local executed_once optimize_size
  Called by: test_init.isra.0/51 (1073741824 (estimated locally),1.00 per call) 
  Calls: udp_perf_init/17 (1073741824 (estimated locally),1.00 per call) my_udp_init/12 (1073741824 (estimated locally),1.00 per call) lwiperf_start_tcp_server_default/38 (1073741824 (estimated locally),1.00 per call) mdns_resp_add_netif/37 (1073741824 (estimated locally),1.00 per call) mdns_resp_init/35 (1073741824 (estimated locally),1.00 per call) 
udp_perf_init/17 (udp_perf_init) @0716bd20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: udp_perf_pcb/13 (write)ip_addr_any/41 (addr)udp_perf_pcb/13 (read)udp_perf_recv/15 (addr)udp_perf_report/16 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local executed_once optimize_size
  Called by: apps_init/18 (1073741824 (estimated locally),1.00 per call) 
  Calls: sys_timeout/42 (189462818 (estimated locally),0.18 per call) udp_recv/49 (189462818 (estimated locally),0.18 per call) udp_bind/40 (574129754 (estimated locally),0.53 per call) udp_new/39 (1073741824 (estimated locally),1.00 per call) 
udp_perf_report/16 (udp_perf_report) @0716ba80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: udp_perf_rx_bytes/14 (read)udp_perf_rx_bytes/14 (write)udp_perf_report/16 (addr)
  Referring: udp_perf_report/16 (addr)udp_perf_init/17 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: sys_timeout/42 (1073741824 (estimated locally),1.00 per call) 
udp_perf_recv/15 (udp_perf_recv) @0716b7e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: udp_perf_init/17 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: udp_perf_recv.part.0/50 (574129752 (estimated locally),0.53 per call) 
udp_perf_rx_bytes/14 (udp_perf_rx_bytes) @07169678
  Type: variable definition analyzed
  Visibility: force_output prevailing_def_ironly
  References: 
  Referring: udp_perf_report/16 (read)udp_perf_report/16 (write)udp_perf_recv.part.0/50 (read)udp_perf_recv.part.0/50 (write)
  Availability: available
  Varpool flags: initialized
udp_perf_pcb/13 (udp_perf_pcb) @071695e8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: udp_perf_init/17 (write)udp_perf_init/17 (read)
  Availability: available
  Varpool flags:
my_udp_init/12 (my_udp_init) @0716b2a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: my_udp_pcb/9 (write)ip_addr_any/41 (addr)my_udp_send_callback/11 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local executed_once optimize_size
  Called by: apps_init/18 (1073741824 (estimated locally),1.00 per call) 
  Calls: sys_timeout/42 (574129754 (estimated locally),0.53 per call) udp_bind/40 (574129754 (estimated locally),0.53 per call) udp_new/39 (1073741824 (estimated locally),1.00 per call) 
my_udp_send_callback/11 (my_udp_send_callback) @0716b000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: my_udp_buffer/10 (addr)my_udp_buffer/10 (addr)my_udp_pcb/9 (read)my_udp_send_callback/11 (addr)
  Referring: my_udp_init/12 (addr)my_udp_send_callback/11 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: sys_timeout/42 (1073741824 (estimated locally),1.00 per call) pbuf_free/48 (574129754 (estimated locally),0.53 per call) udp_sendto/47 (189462818 (estimated locally),0.18 per call) ipaddr_aton/46 (574129754 (estimated locally),0.53 per call) pbuf_take/45 (574129754 (estimated locally),0.53 per call) pbuf_alloc/44 (1073741824 (estimated locally),1.00 per call) memset/43 (1073741824 (estimated locally),1.00 per call) 
my_udp_buffer/10 (my_udp_buffer) @07169438
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: my_udp_send_callback/11 (addr)my_udp_send_callback/11 (addr)
  Availability: available
  Varpool flags:
my_udp_pcb/9 (my_udp_pcb) @071693a8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: my_udp_init/12 (write)my_udp_send_callback/11 (read)
  Availability: available
  Varpool flags:
lwiperf_report/8 (lwiperf_report) @07157a80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: apps_init/18 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
interface_init/7 (interface_init) @071577e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: netif_cfg/28 (read)network_interfaces/5 (addr)gmac_ethernetif_init/30 (addr)netif_input/31 (addr)netif_cfg/28 (read)network_interfaces/5 (addr)network_interfaces/5 (addr)
  Referring: 
  Availability: local
  Function flags: count:536870913 (estimated locally) body local executed_once optimize_size
  Called by: test_init.isra.0/51 (1073741824 (estimated locally),1.00 per call) 
  Calls: netif_set_up/34 (536870913 (estimated locally),1.00 per call) netif_create_ip6_linklocal_address/33 (177167401 (estimated locally),0.33 per call) netif_set_default/32 (536870913 (estimated locally),1.00 per call) netif_add/29 (536870913 (estimated locally),1.00 per call) 
g_init_sem/6 (g_init_sem) @07153678
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Varpool flags:
network_interfaces/5 (network_interfaces) @071535e8
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: interface_init/7 (addr)interface_init/7 (addr)interface_init/7 (addr)mainLoopTask.isra.0/52 (addr)
  Availability: available
  Varpool flags:

;; Function lwiperf_report (lwiperf_report, funcdef_no=5, decl_uid=9342, cgraph_uid=6, symbol_order=8)

Modification phase of node lwiperf_report/8
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



;; Function udp_perf_report (udp_perf_report, funcdef_no=9, decl_uid=9364, cgraph_uid=10, symbol_order=16)

Modification phase of node udp_perf_report/16
udp_perf_report (void * arg)
{
  long unsigned int udp_perf_rx_bytes.8_1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  udp_perf_rx_bytes.8_1 ={v} udp_perf_rx_bytes;
  # DEBUG D#1 => udp_perf_rx_bytes.8_1 * 8
  # DEBUG kbit_s => D#1 / 1000
  # DEBUG BEGIN_STMT
  udp_perf_rx_bytes ={v} 0;
  # DEBUG BEGIN_STMT
  sys_timeout (1000, udp_perf_report, 0B);
  return;

}



;; Function my_udp_send_callback (my_udp_send_callback, funcdef_no=6, decl_uid=9347, cgraph_uid=7, symbol_order=11)

Modification phase of node my_udp_send_callback/11
my_udp_send_callback (void * arg)
{
  struct ip_addr_t dest_addr;
  struct pbuf * p;
  int _1;
  struct udp_pcb * my_udp_pcb.4_2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  memset (&my_udp_buffer, 65, 1024);
  # DEBUG BEGIN_STMT
  p_8 = pbuf_alloc (74, 1024, 640);
  # DEBUG p => p_8
  # DEBUG BEGIN_STMT
  if (p_8 != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 6>; [46.53%]

  <bb 3> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  pbuf_take (p_8, &my_udp_buffer, 1024);
  # DEBUG BEGIN_STMT
  _1 = ipaddr_aton ("192.168.0.8", &dest_addr);
  if (_1 != 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 4> [local count: 189462818]:
  # DEBUG BEGIN_STMT
  my_udp_pcb.4_2 = my_udp_pcb;
  udp_sendto (my_udp_pcb.4_2, p_8, &dest_addr, 5000);

  <bb 5> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  pbuf_free (p_8);

  <bb 6> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  sys_timeout (1000, my_udp_send_callback, 0B);
  dest_addr ={v} {CLOBBER};
  return;

}



;; Function udp_perf_recv (udp_perf_recv, funcdef_no=8, decl_uid=9361, cgraph_uid=9, symbol_order=15)

Modification phase of node udp_perf_recv/15
udp_perf_recv (void * arg, struct udp_pcb * pcb, struct pbuf * p, const struct ip_addr_t * addr, u16_t port)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (p_1(D) != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 4>; [46.53%]

  <bb 3> [local count: 574129752]:
  # DEBUG D#2 => arg_3(D)
  # DEBUG D#3 => pcb_4(D)
  # DEBUG D#4 => addr_5(D)
  # DEBUG D#5 => port_6(D)
  udp_perf_recv.part.0 (p_1(D));

  <bb 4> [local count: 1073741824]:
  return;

}



;; Function start_example (start_example, funcdef_no=14, decl_uid=9322, cgraph_uid=15, symbol_order=21) (executed once)

Modification phase of node start_example/21
start_example ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG D#11 => 0B
  mainLoopTask.isra.0 ();

}


