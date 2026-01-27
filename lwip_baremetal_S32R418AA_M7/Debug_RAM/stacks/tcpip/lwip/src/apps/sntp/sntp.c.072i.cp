
IPA constant propagation start:
Determining dynamic type for call: sntp_send_request (&sntp_server_address);
  Starting walk at: sntp_send_request (&sntp_server_address);
  instance pointer: &sntp_server_address  Outer instance pointer: sntp_server_address offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: sntp_initialize_request (sntpmsg_12);
  Starting walk at: sntp_initialize_request (sntpmsg_12);
  instance pointer: sntpmsg_12  Outer instance pointer: sntpmsg_12 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:p_9 = pbuf_alloc (74, 48, 640);
Determining dynamic type for call: sntp_retry (0B);
  Starting walk at: sntp_retry (0B);
  instance pointer: 0B  Outer instance pointer: 0B offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pbuf_free (p_12(D));
  Function call may change dynamic type:_2 = pbuf_get_at (p_12(D), 0);
  Function call may change dynamic type:pbuf_copy_partial (p_12(D), &timestamps, 8, 40);
  Function call may change dynamic type:stratum_16 = pbuf_get_at (p_12(D), 1);
Determining dynamic type for call: sntp_process (&timestamps);
  Starting walk at: sntp_process (&timestamps);
  instance pointer: &timestamps  Outer instance pointer: timestamps offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pbuf_free (p_12(D));
  Function call may change dynamic type:_2 = pbuf_get_at (p_12(D), 0);
  Function call may change dynamic type:pbuf_copy_partial (p_12(D), &timestamps, 8, 40);
  Function call may change dynamic type:stratum_16 = pbuf_get_at (p_12(D), 1);

IPA structures before propagation:

Jump functions:
  Jump functions of caller  sntp_request.part.0/35:
  Jump functions of caller  udp_remove/33:
  Jump functions of caller  lwip_htonl/32:
  Jump functions of caller  pbuf_copy_partial/31:
  Jump functions of caller  pbuf_get_at/30:
  Jump functions of caller  memset/29:
  Jump functions of caller  pbuf_free/28:
  Jump functions of caller  udp_sendto/27:
  Jump functions of caller  pbuf_alloc/26:
  Jump functions of caller  sys_untimeout/25:
  Jump functions of caller  udp_bind/23:
  Jump functions of caller  sys_timeout/22:
  Jump functions of caller  rand/21:
  Jump functions of caller  udp_recv/20:
  Jump functions of caller  udp_new_ip_type/19:
  Jump functions of caller  sntp_getserver/18:
  Jump functions of caller  sntp_setserver/17:
  Jump functions of caller  sntp_getreachability/16:
  Jump functions of caller  sntp_getoperatingmode/15:
  Jump functions of caller  sntp_setoperatingmode/14:
  Jump functions of caller  sntp_enabled/13:
  Jump functions of caller  sntp_stop/12:
  Jump functions of caller  sntp_init/11:
  Jump functions of caller  sntp_request/10:
    callsite  sntp_request/10 -> sntp_send_request/9 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  sntp_request/10 -> sntp_request.part.0/35 : 
  Jump functions of caller  sntp_send_request/9:
    callsite  sntp_send_request/9 -> sntp_initialize_request/6 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  sntp_recv/8:
    callsite  sntp_recv/8 -> sntp_retry/7 : 
       param 0: CONST: 0B
         value: 0x0, mask: 0xfffffff8
         Unknown VR
    callsite  sntp_recv/8 -> sntp_process/5 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  sntp_retry/7:
  Jump functions of caller  sntp_initialize_request/6:
  Jump functions of caller  sntp_process/5:

 Propagating constants:

Not considering sntp_getserver for cloning; -fipa-cp-clone disabled.
Not considering sntp_setserver for cloning; -fipa-cp-clone disabled.
Not considering sntp_getreachability for cloning; -fipa-cp-clone disabled.
Not considering sntp_getoperatingmode for cloning; -fipa-cp-clone disabled.
Not considering sntp_setoperatingmode for cloning; -fipa-cp-clone disabled.
Not considering sntp_enabled for cloning; -fipa-cp-clone disabled.
Not considering sntp_stop for cloning; -fipa-cp-clone disabled.
Not considering sntp_init for cloning; -fipa-cp-clone disabled.
Not considering sntp_request for cloning; -fipa-cp-clone disabled.
Not considering sntp_recv for cloning; -fipa-cp-clone disabled.
Not considering sntp_retry for cloning; -fipa-cp-clone disabled.

overall_size: 294, max_new_size: 11001
 - context independent values, size: 33, time_benefit: 1.000000
 - context independent values, size: 61, time_benefit: 4.000000
 - context independent values, size: 18, time_benefit: 1.000000

IPA lattices after all propagation:

Lattices:
  Node: sntp_request.part.0/35:
  Node: sntp_getserver/18:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: sntp_setserver/17:
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
  Node: sntp_getreachability/16:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: sntp_getoperatingmode/15:
  Node: sntp_setoperatingmode/14:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: sntp_enabled/13:
  Node: sntp_stop/12:
  Node: sntp_init/11:
  Node: sntp_request/10:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: sntp_send_request/9:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         const struct ip_addr_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: sntp_recv/8:
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
  Node: sntp_retry/7:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: sntp_initialize_request/6:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: sntp_process/5:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         const struct sntp_timestamps * ~[0B, 0B]
        AGGS VARIABLE

IPA decision stage:

Propagated bits info for function sntp_send_request/9:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function sntp_process/5:
 param 0: value = 0x0, mask = 0xfffffffc

IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

sntp_request.part.0/35 (sntp_request.part.0) @05f578c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: sntp_retry/7 (addr)sntp_retry/7 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: sntp_request/10 (536870912 (estimated locally),0.50 per call) 
  Calls: sys_untimeout/25 (1073741824 (estimated locally),1.00 per call) sys_timeout/22 (1073741824 (estimated locally),1.00 per call) 
ip_addr_any/34 (ip_addr_any) @061747e0
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: sntp_getserver/18 (addr)
  Availability: not_available
  Varpool flags: read-only
udp_remove/33 (udp_remove) @0613d8c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: sntp_stop/12 (354334802 (estimated locally),0.33 per call) 
  Calls: 
lwip_htonl/32 (lwip_htonl) @0613d700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: sntp_process/5 (1073741824 (estimated locally),1.00 per call) sntp_process/5 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pbuf_copy_partial/31 (pbuf_copy_partial) @0613d460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: sntp_recv/8 (19073089 (estimated locally),0.02 per call) 
  Calls: 
pbuf_get_at/30 (pbuf_get_at) @0613d380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: sntp_recv/8 (57797241 (estimated locally),0.05 per call) sntp_recv/8 (217325345 (estimated locally),0.20 per call) 
  Calls: 
memset/29 (memset) @0613d0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: sntp_initialize_request/6 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pbuf_free/28 (pbuf_free) @06134ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: sntp_recv/8 (1073741824 (estimated locally),1.00 per call) sntp_send_request/9 (86372 (estimated locally),0.37 per call) 
  Calls: 
udp_sendto/27 (udp_sendto) @06134e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: sntp_send_request/9 (86372 (estimated locally),0.37 per call) 
  Calls: 
pbuf_alloc/26 (pbuf_alloc) @06134d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: sntp_send_request/9 (123389 (estimated locally),0.53 per call) 
  Calls: 
sys_untimeout/25 (sys_untimeout) @061349a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: sntp_stop/12 (354334802 (estimated locally),0.33 per call) sntp_stop/12 (354334802 (estimated locally),0.33 per call) sntp_recv/8 (116930484 (estimated locally),0.11 per call) sntp_recv/8 (116930484 (estimated locally),0.11 per call) sntp_request.part.0/35 (1073741824 (estimated locally),1.00 per call) sntp_send_request/9 (37017 (estimated locally),0.16 per call) sntp_send_request/9 (86372 (estimated locally),0.37 per call) sntp_retry/7 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
ip_addr_any_type/24 (ip_addr_any_type) @0612ed38
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: sntp_init/11 (addr)
  Availability: not_available
  Varpool flags: read-only
udp_bind/23 (udp_bind) @061347e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: sntp_init/11 (16733 (estimated locally),0.01 per call) 
  Calls: 
sys_timeout/22 (sys_timeout) @06134700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: sntp_init/11 (40718 (estimated locally),0.03 per call) sntp_recv/8 (116930484 (estimated locally),0.11 per call) sntp_request.part.0/35 (1073741824 (estimated locally),1.00 per call) sntp_send_request/9 (37017 (estimated locally),0.16 per call) sntp_send_request/9 (86372 (estimated locally),0.37 per call) sntp_retry/7 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
rand/21 (rand) @06134620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: sntp_init/11 (40718 (estimated locally),0.03 per call) 
  Calls: 
udp_recv/20 (udp_recv) @06134460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: sntp_init/11 (123389 (estimated locally),0.09 per call) 
  Calls: 
udp_new_ip_type/19 (udp_new_ip_type) @06134380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: sntp_init/11 (230763 (estimated locally),0.17 per call) 
  Calls: 
sntp_getserver/18 (sntp_getserver) @0612ce00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: sntp_servers/3 (addr)ip_addr_any/34 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
sntp_setserver/17 (sntp_setserver) @0612c8c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: sntp_servers/3 (write)sntp_servers/3 (write)sntp_servers/3 (write)sntp_servers/3 (write)sntp_servers/3 (write)sntp_servers/3 (write)sntp_servers/3 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: 
sntp_getreachability/16 (sntp_getreachability) @0612c0e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: sntp_servers/3 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
sntp_getoperatingmode/15 (sntp_getoperatingmode) @0612cd20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: sntp_opmode/1 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
sntp_setoperatingmode/14 (sntp_setoperatingmode) @0612ca80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: sntp_pcb/2 (read)sntp_opmode/1 (write)
  Referring: 
  Availability: available
  Function flags: count:181990 (estimated locally) body optimize_size
  Called by: 
  Calls: 
sntp_enabled/13 (sntp_enabled) @0612c7e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: sntp_pcb/2 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
sntp_stop/12 (sntp_stop) @0612c540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: sntp_pcb/2 (read)sntp_servers/3 (write)sntp_request/10 (addr)sntp_retry/7 (addr)sntp_pcb/2 (read)sntp_pcb/2 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: udp_remove/33 (354334802 (estimated locally),0.33 per call) sys_untimeout/25 (354334802 (estimated locally),0.33 per call) sys_untimeout/25 (354334802 (estimated locally),0.33 per call) 
sntp_init/11 (sntp_init) @0612c2a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: sntp_pcb/2 (read)sntp_pcb/2 (write)sntp_recv/8 (addr)sntp_opmode/1 (read)sntp_retry_timeout/4 (write)sntp_request/10 (addr)sntp_pcb/2 (read)ip_addr_any_type/24 (addr)
  Referring: 
  Availability: available
  Function flags: count:1323941 (estimated locally) body optimize_size
  Called by: 
  Calls: udp_bind/23 (16733 (estimated locally),0.01 per call) sys_timeout/22 (40718 (estimated locally),0.03 per call) rand/21 (40718 (estimated locally),0.03 per call) udp_recv/20 (123389 (estimated locally),0.09 per call) udp_new_ip_type/19 (230763 (estimated locally),0.17 per call) 
sntp_request/10 (sntp_request) @0612c000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: sntp_servers/3 (read)
  Referring: sntp_send_request/9 (addr)sntp_retry/7 (addr)sntp_recv/8 (addr)sntp_send_request/9 (addr)sntp_init/11 (addr)sntp_retry/7 (addr)sntp_recv/8 (addr)sntp_stop/12 (addr)
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: sntp_send_request/9 (536870913 (estimated locally),0.50 per call) sntp_request.part.0/35 (536870912 (estimated locally),0.50 per call) 
sntp_send_request/9 (sntp_send_request) @06117c40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: sntp_pcb/2 (read)sntp_servers/3 (read)sntp_servers/3 (write)sntp_retry/7 (addr)sntp_retry/7 (addr)sntp_request/10 (addr)sntp_request/10 (addr)
  Referring: 
  Availability: local
  Function flags: count:230763 (estimated locally) body local optimize_size
  Called by: sntp_request/10 (536870913 (estimated locally),0.50 per call) 
  Calls: sys_timeout/22 (37017 (estimated locally),0.16 per call) sys_untimeout/25 (37017 (estimated locally),0.16 per call) sys_timeout/22 (86372 (estimated locally),0.37 per call) sys_untimeout/25 (86372 (estimated locally),0.37 per call) pbuf_free/28 (86372 (estimated locally),0.37 per call) udp_sendto/27 (86372 (estimated locally),0.37 per call) sntp_initialize_request/6 (86372 (estimated locally),0.37 per call) pbuf_alloc/26 (123389 (estimated locally),0.53 per call) 
sntp_recv/8 (sntp_recv) @061179a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: sntp_opmode/1 (read)sntp_servers/3 (read)sntp_servers/3 (write)sntp_opmode/1 (read)sntp_retry/7 (addr)sntp_request/10 (addr)sntp_retry_timeout/4 (write)sntp_request/10 (addr)sntp_opmode/1 (read)
  Referring: sntp_init/11 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: sntp_retry/7 (80717468 (estimated locally),0.08 per call) sys_timeout/22 (116930484 (estimated locally),0.11 per call) sys_untimeout/25 (116930484 (estimated locally),0.11 per call) sys_untimeout/25 (116930484 (estimated locally),0.11 per call) sntp_process/5 (354334802 (estimated locally),0.33 per call) pbuf_free/28 (1073741824 (estimated locally),1.00 per call) pbuf_copy_partial/31 (19073089 (estimated locally),0.02 per call) pbuf_get_at/30 (57797241 (estimated locally),0.05 per call) pbuf_get_at/30 (217325345 (estimated locally),0.20 per call) 
sntp_retry/7 (sntp_retry) @06117700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: sntp_request/10 (addr)sntp_retry_timeout/4 (read)sntp_request/10 (addr)sntp_retry_timeout/4 (read)sntp_retry_timeout/4 (write)sntp_retry_timeout/4 (write)
  Referring: sntp_send_request/9 (addr)sntp_recv/8 (addr)sntp_send_request/9 (addr)sntp_request.part.0/35 (addr)sntp_request.part.0/35 (addr)sntp_stop/12 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: sntp_recv/8 (80717468 (estimated locally),0.08 per call) 
  Calls: sys_timeout/22 (1073741824 (estimated locally),1.00 per call) sys_untimeout/25 (1073741824 (estimated locally),1.00 per call) 
sntp_initialize_request/6 (sntp_initialize_request) @06117460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: sntp_send_request/9 (86372 (estimated locally),0.37 per call) 
  Calls: memset/29 (1073741824 (estimated locally),1.00 per call) 
sntp_process/5 (sntp_process) @061171c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: sntp_recv/8 (354334802 (estimated locally),0.33 per call) 
  Calls: lwip_htonl/32 (1073741824 (estimated locally),1.00 per call) lwip_htonl/32 (1073741824 (estimated locally),1.00 per call) 
sntp_retry_timeout/4 (sntp_retry_timeout) @06114480
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: sntp_retry/7 (write)sntp_recv/8 (write)sntp_retry/7 (read)sntp_retry/7 (read)sntp_retry/7 (write)sntp_init/11 (write)
  Availability: available
  Varpool flags:
sntp_servers/3 (sntp_servers) @06114288
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: sntp_setserver/17 (write)sntp_stop/12 (write)sntp_getreachability/16 (read)sntp_recv/8 (read)sntp_send_request/9 (write)sntp_request/10 (read)sntp_recv/8 (write)sntp_send_request/9 (read)sntp_setserver/17 (write)sntp_setserver/17 (write)sntp_setserver/17 (write)sntp_setserver/17 (write)sntp_setserver/17 (write)sntp_setserver/17 (write)sntp_getserver/18 (addr)
  Availability: available
  Varpool flags:
sntp_pcb/2 (sntp_pcb) @06114168
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: sntp_init/11 (read)sntp_enabled/13 (read)sntp_stop/12 (write)sntp_init/11 (read)sntp_init/11 (write)sntp_send_request/9 (read)sntp_stop/12 (read)sntp_stop/12 (read)sntp_setoperatingmode/14 (read)
  Availability: available
  Varpool flags:
sntp_opmode/1 (sntp_opmode) @061140d8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: sntp_recv/8 (read)sntp_setoperatingmode/14 (write)sntp_recv/8 (read)sntp_init/11 (read)sntp_recv/8 (read)sntp_getoperatingmode/15 (read)
  Availability: available
  Varpool flags:

;; Function sntp_retry (sntp_retry, funcdef_no=3, decl_uid=7249, cgraph_uid=4, symbol_order=7)

Modification phase of node sntp_retry/7
sntp_retry (void * arg)
{
  u32_t new_retry_timeout;
  long unsigned int sntp_retry_timeout.12_1;
  long unsigned int sntp_retry_timeout.13_2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  sys_untimeout (sntp_request, 0B);
  # DEBUG BEGIN_STMT
  sntp_retry_timeout.12_1 = sntp_retry_timeout;
  sys_timeout (sntp_retry_timeout.12_1, sntp_request, 0B);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  sntp_retry_timeout.13_2 = sntp_retry_timeout;
  new_retry_timeout_7 = sntp_retry_timeout.13_2 << 1;
  # DEBUG new_retry_timeout => new_retry_timeout_7
  # DEBUG BEGIN_STMT
  if (new_retry_timeout_7 <= 150000)
    goto <bb 3>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 3> [local count: 536870913]:
  if (sntp_retry_timeout.13_2 < new_retry_timeout_7)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 268435456]:
  # DEBUG BEGIN_STMT
  sntp_retry_timeout = new_retry_timeout_7;
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 805306369]:
  # DEBUG BEGIN_STMT
  sntp_retry_timeout = 150000;

  <bb 6> [local count: 1073741824]:
  return;

}



;; Function sntp_recv (sntp_recv, funcdef_no=4, decl_uid=7257, cgraph_uid=5, symbol_order=8)

Modification phase of node sntp_recv/8
sntp_recv (void * arg, struct udp_pcb * pcb, struct pbuf * p, const struct ip_addr_t * addr, u16_t port)
{
  err_t err;
  u8_t stratum;
  u8_t mode;
  struct sntp_timestamps timestamps;
  short unsigned int _1;
  unsigned char _2;
  unsigned char sntp_opmode.16_3;
  unsigned char _4;
  unsigned char _5;
  unsigned char sntp_opmode.18_6;
  unsigned char sntp_opmode.19_7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG err => -16
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = p_12(D)->tot_len;
  if (_1 == 48)
    goto <bb 3>; [20.24%]
  else
    goto <bb 9>; [79.76%]

  <bb 3> [local count: 217325345]:
  # DEBUG BEGIN_STMT
  _2 = pbuf_get_at (p_12(D), 0);
  mode_14 = _2 & 7;
  # DEBUG mode => mode_14
  # DEBUG BEGIN_STMT
  sntp_opmode.16_3 = sntp_opmode;
  if (sntp_opmode.16_3 == 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 108662673]:
  if (mode_14 == 4)
    goto <bb 7>; [34.00%]
  else
    goto <bb 5>; [66.00%]

  <bb 5> [local count: 180380036]:
  if (sntp_opmode.16_3 == 1)
    goto <bb 6>; [34.00%]
  else
    goto <bb 9>; [66.00%]

  <bb 6> [local count: 61329212]:
  if (mode_14 == 5)
    goto <bb 7>; [34.00%]
  else
    goto <bb 9>; [66.00%]

  <bb 7> [local count: 57797241]:
  # DEBUG BEGIN_STMT
  stratum_16 = pbuf_get_at (p_12(D), 1);
  # DEBUG stratum => stratum_16
  # DEBUG BEGIN_STMT
  if (stratum_16 == 0)
    goto <bb 9>; [67.00%]
  else
    goto <bb 8>; [33.00%]

  <bb 8> [local count: 19073089]:
  # DEBUG BEGIN_STMT
  pbuf_copy_partial (p_12(D), &timestamps, 8, 40);
  # DEBUG BEGIN_STMT
  # DEBUG err => 0

  <bb 9> [local count: 1073741824]:
  # err_8 = PHI <-16(2), -3(6), 0(8), 1(7), -3(5)>
  # DEBUG err => err_8
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pbuf_free (p_12(D));
  # DEBUG BEGIN_STMT
  if (err_8 == 0)
    goto <bb 10>; [33.00%]
  else
    goto <bb 12>; [67.00%]

  <bb 10> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  sntp_process (&timestamps);
  # DEBUG BEGIN_STMT
  _4 = sntp_servers[0].reachability;
  _5 = _4 | 1;
  sntp_servers[0].reachability = _5;
  # DEBUG BEGIN_STMT
  sntp_opmode.18_6 = sntp_opmode;
  if (sntp_opmode.18_6 == 0)
    goto <bb 11>; [33.00%]
  else
    goto <bb 15>; [67.00%]

  <bb 11> [local count: 116930484]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  sys_untimeout (sntp_retry, 0B);
  # DEBUG BEGIN_STMT
  sys_untimeout (sntp_request, 0B);
  # DEBUG BEGIN_STMT
  sntp_retry_timeout = 15000;
  # DEBUG BEGIN_STMT
  # DEBUG sntp_update_delay => 3600000
  # DEBUG BEGIN_STMT
  sys_timeout (3600000, sntp_request, 0B);
  goto <bb 15>; [100.00%]

  <bb 12> [local count: 719407022]:
  # DEBUG BEGIN_STMT
  if (err_8 == 1)
    goto <bb 13>; [34.00%]
  else
    goto <bb 15>; [66.00%]

  <bb 13> [local count: 244598387]:
  # DEBUG BEGIN_STMT
  sntp_opmode.19_7 = sntp_opmode;
  if (sntp_opmode.19_7 == 0)
    goto <bb 14>; [33.00%]
  else
    goto <bb 15>; [67.00%]

  <bb 14> [local count: 80717468]:
  # DEBUG BEGIN_STMT
  sntp_retry (0B);

  <bb 15> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  timestamps ={v} {CLOBBER};
  return;

}



;; Function sntp_request (sntp_request, funcdef_no=6, decl_uid=7232, cgraph_uid=7, symbol_order=10)

Modification phase of node sntp_request/10
sntp_request (void * arg)
{
  struct ip_addr_t sntp_server_address;
  unsigned char _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  _Bool iftmp.10_7;
  int iftmp.11_8;
  _Bool iftmp.10_11;
  _Bool iftmp.10_13;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  sntp_server_address = sntp_servers[0].addr;
  # DEBUG BEGIN_STMT
  _1 = sntp_server_address.type;
  if (_1 == 6)
    goto <bb 3>; [34.00%]
  else
    goto <bb 9>; [66.00%]

  <bb 3> [local count: 365072220]:
  _2 = sntp_server_address.u_addr.ip6.addr[0];
  if (_2 == 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 4> [local count: 182536110]:
  _3 = sntp_server_address.u_addr.ip6.addr[1];
  if (_3 == 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 5> [local count: 91268055]:
  _4 = sntp_server_address.u_addr.ip6.addr[2];
  if (_4 == 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 6> [local count: 45634027]:
  _5 = sntp_server_address.u_addr.ip6.addr[3];
  if (_5 == 0)
    goto <bb 8>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 7> [local count: 342255206]:

  <bb 8> [local count: 365072220]:
  # iftmp.11_8 = PHI <1(6), 0(7)>
  iftmp.10_13 = (_Bool) iftmp.11_8;
  goto <bb 10>; [100.00%]

  <bb 9> [local count: 708669604]:
  _6 = sntp_server_address.u_addr.ip4.addr;
  iftmp.10_11 = _6 == 0;

  <bb 10> [local count: 1073741824]:
  # iftmp.10_7 = PHI <iftmp.10_13(8), iftmp.10_11(9)>
  if (iftmp.10_7 != 0)
    goto <bb 11>; [50.00%]
  else
    goto <bb 12>; [50.00%]

  <bb 11> [local count: 536870912]:
  # DEBUG D#1 => arg_14(D)
  sntp_request.part.0 ();
  goto <bb 13>; [100.00%]

  <bb 12> [local count: 536870913]:
  # DEBUG err => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  sntp_send_request (&sntp_server_address);

  <bb 13> [local count: 1073741824]:
  sntp_server_address ={v} {CLOBBER};
  return;

}



;; Function sntp_init (sntp_init, funcdef_no=7, decl_uid=6316, cgraph_uid=8, symbol_order=11)

Modification phase of node sntp_init/11
sntp_init ()
{
  struct udp_pcb * sntp_pcb.0_1;
  struct udp_pcb * _2;
  unsigned char sntp_opmode.4_3;
  int _4;
  long unsigned int _5;
  long unsigned int _6;
  struct udp_pcb * sntp_pcb.6_7;
  unsigned char _8;
  unsigned char _9;

  <bb 2> [local count: 1323941]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  sntp_pcb.0_1 = sntp_pcb;
  if (sntp_pcb.0_1 == 0B)
    goto <bb 3>; [17.43%]
  else
    goto <bb 9>; [82.57%]

  <bb 3> [local count: 230763]:
  # DEBUG BEGIN_STMT
  _2 = udp_new_ip_type (46);
  sntp_pcb = _2;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (_2 == 0B)
    goto <bb 10>; [46.53%]
  else
    goto <bb 5>; [53.47%]

  <bb 10> [local count: 107374]:

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 11> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 123389]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  udp_recv (_2, sntp_recv, 0B);
  # DEBUG BEGIN_STMT
  sntp_opmode.4_3 = sntp_opmode;
  if (sntp_opmode.4_3 == 0)
    goto <bb 6>; [33.00%]
  else
    goto <bb 7>; [67.00%]

  <bb 6> [local count: 40718]:
  # DEBUG BEGIN_STMT
  sntp_retry_timeout = 15000;
  # DEBUG BEGIN_STMT
  _4 = rand ();
  _5 = (long unsigned int) _4;
  _6 = _5 % 5000;
  sys_timeout (_6, sntp_request, 0B);
  goto <bb 9>; [100.00%]

  <bb 7> [local count: 82671]:
  # DEBUG BEGIN_STMT
  if (sntp_opmode.4_3 == 1)
    goto <bb 8>; [20.24%]
  else
    goto <bb 9>; [79.76%]

  <bb 8> [local count: 16733]:
  # DEBUG BEGIN_STMT
  sntp_pcb.6_7 = sntp_pcb;
  _8 = sntp_pcb.6_7->so_options;
  _9 = _8 | 32;
  sntp_pcb.6_7->so_options = _9;
  # DEBUG BEGIN_STMT
  udp_bind (sntp_pcb.6_7, &ip_addr_any_type, 123);

  <bb 9> [local count: 1216567]:
  return;

}



;; Function sntp_stop (sntp_stop, funcdef_no=8, decl_uid=6318, cgraph_uid=9, symbol_order=12)

Modification phase of node sntp_stop/12
sntp_stop ()
{
  u8_t i;
  struct udp_pcb * sntp_pcb.21_1;
  struct udp_pcb * sntp_pcb.23_2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  sntp_pcb.21_1 = sntp_pcb;
  if (sntp_pcb.21_1 != 0B)
    goto <bb 7>; [33.00%]
  else
    goto <bb 6>; [67.00%]

  <bb 7> [local count: 354334802]:
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  sntp_servers[0].reachability = 0;
  # DEBUG BEGIN_STMT
  # DEBUG i => 1

  <bb 4> [local count: 708669605]:
  # i_3 = PHI <1(3), 0(7)>
  # DEBUG i => i_3
  # DEBUG BEGIN_STMT
  if (i_3 == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 5> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  sys_untimeout (sntp_request, 0B);
  # DEBUG BEGIN_STMT
  sys_untimeout (sntp_retry, 0B);
  # DEBUG BEGIN_STMT
  sntp_pcb.23_2 = sntp_pcb;
  udp_remove (sntp_pcb.23_2);
  # DEBUG BEGIN_STMT
  sntp_pcb = 0B;

  <bb 6> [local count: 1073741824]:
  return;

}



;; Function sntp_enabled (sntp_enabled, funcdef_no=9, decl_uid=6320, cgraph_uid=10, symbol_order=13)

Modification phase of node sntp_enabled/13
sntp_enabled ()
{
  struct udp_pcb * sntp_pcb.24_1;
  _Bool _2;
  u8_t _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  sntp_pcb.24_1 = sntp_pcb;
  _2 = sntp_pcb.24_1 != 0B;
  _4 = (u8_t) _2;
  return _4;

}



;; Function sntp_setoperatingmode (sntp_setoperatingmode, funcdef_no=10, decl_uid=6312, cgraph_uid=11, symbol_order=14)

Modification phase of node sntp_setoperatingmode/14
sntp_setoperatingmode (u8_t operating_mode)
{
  struct udp_pcb * sntp_pcb.25_1;

  <bb 2> [local count: 181990]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (operating_mode_4(D) > 1)
    goto <bb 7>; [59.00%]
  else
    goto <bb 4>; [41.00%]

  <bb 7> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 9> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 74616]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  sntp_pcb.25_1 = sntp_pcb;
  if (sntp_pcb.25_1 != 0B)
    goto <bb 8>; [70.00%]
  else
    goto <bb 6>; [30.00%]

  <bb 8> [local count: 52231]:

  <bb 5> [local count: 522311701]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 10> [local count: 522311701]:
  goto <bb 5>; [100.00%]

  <bb 6> [local count: 22385]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  sntp_opmode = operating_mode_4(D);
  return;

}



;; Function sntp_getoperatingmode (sntp_getoperatingmode, funcdef_no=11, decl_uid=6314, cgraph_uid=12, symbol_order=15)

Modification phase of node sntp_getoperatingmode/15
sntp_getoperatingmode ()
{
  u8_t _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _2 = sntp_opmode;
  return _2;

}



;; Function sntp_getreachability (sntp_getreachability, funcdef_no=12, decl_uid=6327, cgraph_uid=13, symbol_order=16)

Modification phase of node sntp_getreachability/16
sntp_getreachability (u8_t idx)
{
  u8_t _1;
  u8_t _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (idx_2(D) == 0)
    goto <bb 3>; [34.00%]
  else
    goto <bb 4>; [66.00%]

  <bb 3> [local count: 365072220]:
  # DEBUG BEGIN_STMT
  _4 = sntp_servers[0].reachability;

  <bb 4> [local count: 1073741824]:
  # _1 = PHI <_4(3), 0(2)>
  return _1;

}



;; Function sntp_setserver (sntp_setserver, funcdef_no=13, decl_uid=6323, cgraph_uid=14, symbol_order=17)

Modification phase of node sntp_setserver/17
sntp_setserver (u8_t idx, const struct ip_addr_t * server)
{
  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (idx_2(D) == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 3> [local count: 536870911]:
  # DEBUG BEGIN_STMT
  if (server_4(D) != 0B)
    goto <bb 4>; [70.00%]
  else
    goto <bb 5>; [30.00%]

  <bb 4> [local count: 375809638]:
  # DEBUG BEGIN_STMT
  sntp_servers[0].addr = *server_4(D);
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 161061273]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  sntp_servers[0].addr.u_addr.ip6.addr[0] = 0;
  # DEBUG BEGIN_STMT
  sntp_servers[0].addr.u_addr.ip6.addr[1] = 0;
  # DEBUG BEGIN_STMT
  sntp_servers[0].addr.u_addr.ip6.addr[2] = 0;
  # DEBUG BEGIN_STMT
  sntp_servers[0].addr.u_addr.ip6.addr[3] = 0;
  # DEBUG BEGIN_STMT
  sntp_servers[0].addr.u_addr.ip6.zone = 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  sntp_servers[0].addr.type = 0;

  <bb 6> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return;

}



;; Function sntp_getserver (sntp_getserver, funcdef_no=14, decl_uid=6325, cgraph_uid=15, symbol_order=18)

Modification phase of node sntp_getserver/18
sntp_getserver (u8_t idx)
{
  const struct ip_addr_t * _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (idx_2(D) == 0)
    goto <bb 3>; [34.00%]
  else
    goto <bb 4>; [66.00%]

  <bb 3> [local count: 365072220]:
  # DEBUG BEGIN_STMT

  <bb 4> [local count: 1073741824]:
  # _1 = PHI <&MEM[(void *)&sntp_servers](3), &ip_addr_any(2)>
  return _1;

}


