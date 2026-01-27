
IPA constant propagation start:
Determining dynamic type for call: netio_accept.part.0 (pcb_1(D));
  Starting walk at: netio_accept.part.0 (pcb_1(D));
  instance pointer: pcb_1(D)  Outer instance pointer: pcb_1(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: netio_recv.part.0 (pcb_6(D));
  Starting walk at: netio_recv.part.0 (pcb_6(D));
  instance pointer: pcb_6(D)  Outer instance pointer: pcb_6(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pbuf_free (p_4(D));
  Function call may change dynamic type:tcp_recved (pcb_6(D), _1);
  Function call may change dynamic type:pbuf_free (p_4(D));

IPA structures before propagation:

Jump functions:
  Jump functions of caller  netio_recv.part.0/16:
  Jump functions of caller  netio_accept.part.0/15:
  Jump functions of caller  tcp_close/14:
  Jump functions of caller  pbuf_free/13:
  Jump functions of caller  tcp_recved/12:
  Jump functions of caller  tcp_recv/11:
  Jump functions of caller  tcp_sent/10:
  Jump functions of caller  tcp_arg/9:
  Jump functions of caller  tcp_accept/8:
  Jump functions of caller  tcp_listen_with_backlog/7:
  Jump functions of caller  tcp_bind/5:
  Jump functions of caller  tcp_new_ip_type/4:
  Jump functions of caller  netio_init/3:
  Jump functions of caller  netio_accept/2:
    callsite  netio_accept/2 -> netio_accept.part.0/15 : 
       param 0: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  netio_recv/1:
    callsite  netio_recv/1 -> netio_recv.part.0/16 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR

 Propagating constants:

Not considering netio_init for cloning; -fipa-cp-clone disabled.
Not considering netio_accept for cloning; -fipa-cp-clone disabled.
Not considering netio_recv for cloning; -fipa-cp-clone disabled.

overall_size: 71, max_new_size: 11001
 - context independent values, size: 7, time_benefit: 2.000000
 - context independent values, size: 21, time_benefit: 1.000000

IPA lattices after all propagation:

Lattices:
  Node: netio_recv.part.0/16:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: netio_accept.part.0/15:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: netio_init/3:
  Node: netio_accept/2:
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
  Node: netio_recv/1:
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

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

netio_recv.part.0/16 (netio_recv.part.0) @060f5380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: netio_recv/1 (93576600 (estimated locally),0.09 per call) 
  Calls: tcp_arg/9 (1073741824 (estimated locally),1.00 per call) tcp_sent/10 (1073741824 (estimated locally),1.00 per call) tcp_recv/11 (1073741824 (estimated locally),1.00 per call) tcp_close/14 (1073741824 (estimated locally),1.00 per call) 
netio_accept.part.0/15 (netio_accept.part.0) @05f319a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: netio_recv/1 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: netio_accept/2 (574129752 (estimated locally),0.53 per call) 
  Calls: tcp_arg/9 (1073741824 (estimated locally),1.00 per call) tcp_sent/10 (1073741824 (estimated locally),1.00 per call) tcp_recv/11 (1073741824 (estimated locally),1.00 per call) 
tcp_close/14 (tcp_close) @060eb2a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: netio_recv.part.0/16 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pbuf_free/13 (pbuf_free) @060eb1c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: netio_recv/1 (689074890 (estimated locally),0.64 per call) netio_recv/1 (384666935 (estimated locally),0.36 per call) 
  Calls: 
tcp_recved/12 (tcp_recved) @060eb0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: netio_recv/1 (384666935 (estimated locally),0.36 per call) 
  Calls: 
tcp_recv/11 (tcp_recv) @060e8380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: netio_recv.part.0/16 (1073741824 (estimated locally),1.00 per call) netio_accept.part.0/15 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
tcp_sent/10 (tcp_sent) @060e8ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: netio_recv.part.0/16 (1073741824 (estimated locally),1.00 per call) netio_accept.part.0/15 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
tcp_arg/9 (tcp_arg) @060e8e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: netio_recv.part.0/16 (1073741824 (estimated locally),1.00 per call) netio_accept.part.0/15 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
tcp_accept/8 (tcp_accept) @060e8c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: netio_init/3 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
tcp_listen_with_backlog/7 (tcp_listen_with_backlog) @060e8b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: netio_init/3 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
ip_addr_any_type/6 (ip_addr_any_type) @060e1dc8
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: netio_init/3 (addr)
  Availability: not_available
  Varpool flags: read-only
tcp_bind/5 (tcp_bind) @060e8a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: netio_init/3 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
tcp_new_ip_type/4 (tcp_new_ip_type) @060e89a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: netio_init/3 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
netio_init/3 (netio_init) @060e8540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ip_addr_any_type/6 (addr)netio_accept/2 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: tcp_accept/8 (1073741824 (estimated locally),1.00 per call) tcp_listen_with_backlog/7 (1073741824 (estimated locally),1.00 per call) tcp_bind/5 (1073741824 (estimated locally),1.00 per call) tcp_new_ip_type/4 (1073741824 (estimated locally),1.00 per call) 
netio_accept/2 (netio_accept) @060e82a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: netio_init/3 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: netio_accept.part.0/15 (574129752 (estimated locally),0.53 per call) 
netio_recv/1 (netio_recv) @060e8000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: netio_accept.part.0/15 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: netio_recv.part.0/16 (93576600 (estimated locally),0.09 per call) pbuf_free/13 (689074890 (estimated locally),0.64 per call) pbuf_free/13 (384666935 (estimated locally),0.36 per call) tcp_recved/12 (384666935 (estimated locally),0.36 per call) 

;; Function netio_accept (netio_accept, funcdef_no=2, decl_uid=7259, cgraph_uid=3, symbol_order=2)

Modification phase of node netio_accept/2
netio_accept (void * arg, struct tcp_pcb * pcb, err_t err)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_1(D) != 0B)
    goto <bb 3>; [53.47%]
  else
    goto <bb 4>; [46.53%]

  <bb 3> [local count: 574129752]:
  # DEBUG D#1 => arg_3(D)
  # DEBUG D#2 => err_4(D)
  netio_accept.part.0 (pcb_1(D));

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function netio_recv (netio_recv, funcdef_no=1, decl_uid=7254, cgraph_uid=2, symbol_order=1)

Modification phase of node netio_recv/1
netio_recv (void * arg, struct tcp_pcb * pcb, struct pbuf * p, err_t err)
{
  short unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (err_3(D) == 0)
    goto <bb 3>; [67.00%]
  else
    goto <bb 5>; [33.00%]

  <bb 3> [local count: 719407023]:
  if (p_4(D) != 0B)
    goto <bb 4>; [53.47%]
  else
    goto <bb 5>; [46.53%]

  <bb 4> [local count: 384666935]:
  # DEBUG BEGIN_STMT
  _1 = p_4(D)->tot_len;
  tcp_recved (pcb_6(D), _1);
  # DEBUG BEGIN_STMT
  pbuf_free (p_4(D));
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 689074890]:
  # DEBUG BEGIN_STMT
  pbuf_free (p_4(D));

  <bb 6> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (err_3(D) == 0)
    goto <bb 7>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 7> [local count: 536870913]:
  if (p_4(D) == 0B)
    goto <bb 8>; [17.43%]
  else
    goto <bb 9>; [82.57%]

  <bb 8> [local count: 93576600]:
  # DEBUG D#5 => arg_10(D)
  # DEBUG D#6 => p_4(D)
  # DEBUG D#7 => err_3(D)
  netio_recv.part.0 (pcb_6(D));

  <bb 9> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function netio_init (netio_init, funcdef_no=3, decl_uid=5332, cgraph_uid=4, symbol_order=3)

Modification phase of node netio_init/3
netio_init ()
{
  struct tcp_pcb * pcb;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pcb_3 = tcp_new_ip_type (46);
  # DEBUG pcb => pcb_3
  # DEBUG BEGIN_STMT
  tcp_bind (pcb_3, &ip_addr_any_type, 18767);
  # DEBUG BEGIN_STMT
  pcb_6 = tcp_listen_with_backlog (pcb_3, 255);
  # DEBUG pcb => pcb_6
  # DEBUG BEGIN_STMT
  tcp_accept (pcb_6, netio_accept);
  return;

}


