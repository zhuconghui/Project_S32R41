
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  mainLoopTask.isra.0/45:
    callsite  mainLoopTask.isra.0/45 -> test_init.isra.0/44 : 
  Jump functions of caller  test_init.isra.0/44:
    callsite  test_init.isra.0/44 -> apps_init/13 : 
    callsite  test_init.isra.0/44 -> interface_init/7 : 
  Jump functions of caller  pbuf_free/43:
  Jump functions of caller  udp_sendto/42:
  Jump functions of caller  ipaddr_aton/41:
  Jump functions of caller  pbuf_take/40:
  Jump functions of caller  pbuf_alloc/39:
  Jump functions of caller  memset/38:
  Jump functions of caller  sys_timeout/37:
  Jump functions of caller  udp_bind/35:
  Jump functions of caller  udp_new/34:
  Jump functions of caller  lwiperf_start_tcp_server_default/33:
  Jump functions of caller  mdns_resp_add_netif/32:
  Jump functions of caller  mdns_resp_init/30:
  Jump functions of caller  netif_set_up/29:
  Jump functions of caller  netif_create_ip6_linklocal_address/28:
  Jump functions of caller  netif_set_default/27:
  Jump functions of caller  netif_input/26:
  Jump functions of caller  gmac_ethernetif_init/25:
  Jump functions of caller  netif_add/24:
  Jump functions of caller  end_tcpip_execution/22:
  Jump functions of caller  gmac_ethernetif_shutdown/21:
  Jump functions of caller  OsIf_GetMilliseconds/20:
  Jump functions of caller  sys_check_timeouts/19:
  Jump functions of caller  lwip_init/18:
  Jump functions of caller  sys_init/17:
  Jump functions of caller  start_example/16:
    callsite  start_example/16 -> mainLoopTask.isra.0/45 : 
  Jump functions of caller  apps_init/13:
    callsite  apps_init/13 -> my_udp_init/12 : 
  Jump functions of caller  my_udp_init/12:
  Jump functions of caller  my_udp_send_callback/11:
  Jump functions of caller  lwiperf_report/8:
  Jump functions of caller  interface_init/7:

 Propagating constants:

Not considering start_example for cloning; -fipa-cp-clone disabled.
Not considering my_udp_send_callback for cloning; -fipa-cp-clone disabled.
Not considering lwiperf_report for cloning; -fipa-cp-clone disabled.

overall_size: 188, max_new_size: 11001
 - context independent values, size: 36, time_benefit: 1.000000
 - context independent values, size: 3, time_benefit: 9.000000

IPA lattices after all propagation:

Lattices:
  Node: mainLoopTask.isra.0/45:
  Node: test_init.isra.0/44:
  Node: start_example/16:
  Node: apps_init/13:
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

mainLoopTask.isra.0/45 (mainLoopTask.isra.0) @05eb88c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: network_interfaces/5 (addr)
  Referring: 
  Availability: local
  Function flags: count:11811 (estimated locally) body local executed_once optimize_size
  Called by: start_example/16 (1073741824 (estimated locally),1.00 per call) 
  Calls: end_tcpip_execution/22 (118111601 (estimated locally),10000.14 per call) gmac_ethernetif_shutdown/21 (118111601 (estimated locally),10000.14 per call) OsIf_GetMilliseconds/20 (1073741824 (estimated locally),90910.32 per call) sys_check_timeouts/19 (1073741824 (estimated locally),90910.32 per call) test_init.isra.0/44 (11811 (estimated locally),1.00 per call) lwip_init/18 (11811 (estimated locally),1.00 per call) sys_init/17 (11811 (estimated locally),1.00 per call) 
test_init.isra.0/44 (test_init.isra.0) @05eb8460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local executed_once optimize_size
  Called by: mainLoopTask.isra.0/45 (11811 (estimated locally),1.00 per call) 
  Calls: apps_init/13 (1073741824 (estimated locally),1.00 per call) interface_init/7 (1073741824 (estimated locally),1.00 per call) 
pbuf_free/43 (pbuf_free) @0655b8c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: my_udp_send_callback/11 (574129754 (estimated locally),0.53 per call) 
  Calls: 
udp_sendto/42 (udp_sendto) @0655b7e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: my_udp_send_callback/11 (189462818 (estimated locally),0.18 per call) 
  Calls: 
ipaddr_aton/41 (ipaddr_aton) @0655b700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: my_udp_send_callback/11 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pbuf_take/40 (pbuf_take) @0655b620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: my_udp_send_callback/11 (574129754 (estimated locally),0.53 per call) 
  Calls: 
pbuf_alloc/39 (pbuf_alloc) @0655b540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: my_udp_send_callback/11 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
memset/38 (memset) @0655b460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: my_udp_send_callback/11 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
sys_timeout/37 (sys_timeout) @0655b2a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: my_udp_send_callback/11 (1073741824 (estimated locally),1.00 per call) my_udp_init/12 (574129754 (estimated locally),0.53 per call) 
  Calls: 
ip_addr_any/36 (ip_addr_any) @0654dc18
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: my_udp_init/12 (addr)
  Availability: not_available
  Varpool flags: read-only
udp_bind/35 (udp_bind) @0655b1c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: my_udp_init/12 (574129754 (estimated locally),0.53 per call) 
  Calls: 
udp_new/34 (udp_new) @0655b0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: my_udp_init/12 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
lwiperf_start_tcp_server_default/33 (lwiperf_start_tcp_server_default) @0654b620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: apps_init/13 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
mdns_resp_add_netif/32 (mdns_resp_add_netif) @0654bee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: apps_init/13 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
netif_default/31 (netif_default) @0654d750
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: apps_init/13 (read)
  Availability: not_available
  Varpool flags:
mdns_resp_init/30 (mdns_resp_init) @0654be00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: apps_init/13 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
netif_set_up/29 (netif_set_up) @0654bc40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: interface_init/7 (536870913 (estimated locally),1.00 per call) 
  Calls: 
netif_create_ip6_linklocal_address/28 (netif_create_ip6_linklocal_address) @0654bb60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: interface_init/7 (177167401 (estimated locally),0.33 per call) 
  Calls: 
netif_set_default/27 (netif_set_default) @0654ba80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: interface_init/7 (536870913 (estimated locally),1.00 per call) 
  Calls: 
netif_input/26 (netif_input) @0654b9a0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: interface_init/7 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
gmac_ethernetif_init/25 (gmac_ethernetif_init) @0654b8c0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: interface_init/7 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
netif_add/24 (netif_add) @0654b7e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: interface_init/7 (536870913 (estimated locally),1.00 per call) 
  Calls: 
netif_cfg/23 (netif_cfg) @0654d3a8
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: interface_init/7 (read)interface_init/7 (read)
  Availability: not_available
  Varpool flags:
end_tcpip_execution/22 (end_tcpip_execution) @0654b460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mainLoopTask.isra.0/45 (118111601 (estimated locally),10000.14 per call) 
  Calls: 
gmac_ethernetif_shutdown/21 (gmac_ethernetif_shutdown) @0654b380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mainLoopTask.isra.0/45 (118111601 (estimated locally),10000.14 per call) 
  Calls: 
OsIf_GetMilliseconds/20 (OsIf_GetMilliseconds) @0654b2a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mainLoopTask.isra.0/45 (1073741824 (estimated locally),90910.32 per call) 
  Calls: 
sys_check_timeouts/19 (sys_check_timeouts) @0654b1c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mainLoopTask.isra.0/45 (1073741824 (estimated locally),90910.32 per call) 
  Calls: 
lwip_init/18 (lwip_init) @0654b0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mainLoopTask.isra.0/45 (11811 (estimated locally),1.00 per call) 
  Calls: 
sys_init/17 (sys_init) @0654b000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mainLoopTask.isra.0/45 (11811 (estimated locally),1.00 per call) 
  Calls: 
start_example/16 (start_example) @0646bd20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body executed_once optimize_size
  Called by: 
  Calls: mainLoopTask.isra.0/45 (1073741824 (estimated locally),1.00 per call) 
apps_init/13 (apps_init) @0646b540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: netif_default/31 (read)lwiperf_report/8 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local executed_once optimize_size
  Called by: test_init.isra.0/44 (1073741824 (estimated locally),1.00 per call) 
  Calls: my_udp_init/12 (1073741824 (estimated locally),1.00 per call) lwiperf_start_tcp_server_default/33 (1073741824 (estimated locally),1.00 per call) mdns_resp_add_netif/32 (1073741824 (estimated locally),1.00 per call) mdns_resp_init/30 (1073741824 (estimated locally),1.00 per call) 
my_udp_init/12 (my_udp_init) @0646b2a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: my_udp_pcb/9 (write)ip_addr_any/36 (addr)my_udp_send_callback/11 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local executed_once optimize_size
  Called by: apps_init/13 (1073741824 (estimated locally),1.00 per call) 
  Calls: sys_timeout/37 (574129754 (estimated locally),0.53 per call) udp_bind/35 (574129754 (estimated locally),0.53 per call) udp_new/34 (1073741824 (estimated locally),1.00 per call) 
my_udp_send_callback/11 (my_udp_send_callback) @0646b000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: my_udp_buffer/10 (addr)my_udp_buffer/10 (addr)my_udp_pcb/9 (read)my_udp_send_callback/11 (addr)
  Referring: my_udp_init/12 (addr)my_udp_send_callback/11 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: sys_timeout/37 (1073741824 (estimated locally),1.00 per call) pbuf_free/43 (574129754 (estimated locally),0.53 per call) udp_sendto/42 (189462818 (estimated locally),0.18 per call) ipaddr_aton/41 (574129754 (estimated locally),0.53 per call) pbuf_take/40 (574129754 (estimated locally),0.53 per call) pbuf_alloc/39 (1073741824 (estimated locally),1.00 per call) memset/38 (1073741824 (estimated locally),1.00 per call) 
my_udp_buffer/10 (my_udp_buffer) @06469438
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: my_udp_send_callback/11 (addr)my_udp_send_callback/11 (addr)
  Availability: available
  Varpool flags:
my_udp_pcb/9 (my_udp_pcb) @064693a8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: my_udp_init/12 (write)my_udp_send_callback/11 (read)
  Availability: available
  Varpool flags:
lwiperf_report/8 (lwiperf_report) @06457a80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: apps_init/13 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
interface_init/7 (interface_init) @064577e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: netif_cfg/23 (read)network_interfaces/5 (addr)gmac_ethernetif_init/25 (addr)netif_input/26 (addr)netif_cfg/23 (read)network_interfaces/5 (addr)network_interfaces/5 (addr)
  Referring: 
  Availability: local
  Function flags: count:536870913 (estimated locally) body local executed_once optimize_size
  Called by: test_init.isra.0/44 (1073741824 (estimated locally),1.00 per call) 
  Calls: netif_set_up/29 (536870913 (estimated locally),1.00 per call) netif_create_ip6_linklocal_address/28 (177167401 (estimated locally),0.33 per call) netif_set_default/27 (536870913 (estimated locally),1.00 per call) netif_add/24 (536870913 (estimated locally),1.00 per call) 
g_init_sem/6 (g_init_sem) @06453678
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Varpool flags:
network_interfaces/5 (network_interfaces) @064535e8
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: interface_init/7 (addr)interface_init/7 (addr)interface_init/7 (addr)mainLoopTask.isra.0/45 (addr)
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



;; Function start_example (start_example, funcdef_no=11, decl_uid=9322, cgraph_uid=12, symbol_order=16) (executed once)

Modification phase of node start_example/16
start_example ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG D#2 => 0B
  mainLoopTask.isra.0 ();

}


