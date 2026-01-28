
IPA constant propagation start:
Determining dynamic type for call: tcp_abandon (inactive_10, 0);
  Starting walk at: tcp_abandon (inactive_10, 0);
  instance pointer: inactive_10  Outer instance pointer: inactive_11 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: tcp_abort (pcb_1);
  Starting walk at: tcp_abort (pcb_1);
  instance pointer: pcb_1  Outer instance pointer: pcb_1 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_abort (pcb_1);
Determining dynamic type for call: err_6 = _4 (_5, pcb_1(D), 0B, 0);
  Starting walk at: err_6 = _4 (_5, pcb_1(D), 0B, 0);
  instance pointer: _5  Outer instance pointer: _5 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: err_6 = _4 (_5, pcb_1(D), 0B, 0);
  Starting walk at: err_6 = _4 (_5, pcb_1(D), 0B, 0);
  instance pointer: pcb_1(D)  Outer instance pointer: pcb_1(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: err_6 = _4 (_5, pcb_1(D), 0B, 0);
  Starting walk at: err_6 = _4 (_5, pcb_1(D), 0B, 0);
  instance pointer: 0B  Outer instance pointer: 0B offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _3 = tcp_close (pcb_2(D));
  Starting walk at: _3 = tcp_close (pcb_2(D));
  instance pointer: pcb_2(D)  Outer instance pointer: pcb_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: tcp_pcb_purge (pcb_3(D));
  Starting walk at: tcp_pcb_purge (pcb_3(D));
  instance pointer: pcb_3(D)  Outer instance pointer: pcb_3(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: tcp_backlog_accepted (pcb_1(D));
  Starting walk at: tcp_backlog_accepted (pcb_1(D));
  instance pointer: pcb_1(D)  Outer instance pointer: pcb_1(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: tcp_segs_free (_4);
  Starting walk at: tcp_segs_free (_4);
  instance pointer: _4  Outer instance pointer: _4 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_segs_free (_3);
  Function call may change dynamic type:tcp_backlog_accepted (pcb_1(D));
  Function call may change dynamic type:pbuf_free (_2);
Determining dynamic type for call: tcp_segs_free (_3);
  Starting walk at: tcp_segs_free (_3);
  instance pointer: _3  Outer instance pointer: _3 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_backlog_accepted (pcb_1(D));
  Function call may change dynamic type:pbuf_free (_2);
Determining dynamic type for call: tcp_netif_ip_addr_changed_pcblist (old_addr_49(D), tcp_active_pcbs.91_7);
  Starting walk at: tcp_netif_ip_addr_changed_pcblist (old_addr_49(D), tcp_active_pcbs.91_7);
  instance pointer: old_addr_49(D)  Outer instance pointer: old_addr_49(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: tcp_netif_ip_addr_changed_pcblist (old_addr_49(D), tcp_active_pcbs.91_7);
  Starting walk at: tcp_netif_ip_addr_changed_pcblist (old_addr_49(D), tcp_active_pcbs.91_7);
  instance pointer: tcp_active_pcbs.91_7  Outer instance pointer: tcp_active_pcbs.91_7 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: tcp_netif_ip_addr_changed_pcblist (old_addr_49(D), tcp_bound_pcbs.92_8);
  Starting walk at: tcp_netif_ip_addr_changed_pcblist (old_addr_49(D), tcp_bound_pcbs.92_8);
  instance pointer: old_addr_49(D)  Outer instance pointer: old_addr_49(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_netif_ip_addr_changed_pcblist (old_addr_49(D), tcp_active_pcbs.91_7);
Determining dynamic type for call: tcp_netif_ip_addr_changed_pcblist (old_addr_49(D), tcp_bound_pcbs.92_8);
  Starting walk at: tcp_netif_ip_addr_changed_pcblist (old_addr_49(D), tcp_bound_pcbs.92_8);
  instance pointer: tcp_bound_pcbs.92_8  Outer instance pointer: tcp_bound_pcbs.92_8 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_netif_ip_addr_changed_pcblist (old_addr_49(D), tcp_active_pcbs.91_7);
Determining dynamic type for call: tcp_netif_ip_addr_changed_pcblist.part.0 (old_addr_6(D), pcb_list_5(D));
  Starting walk at: tcp_netif_ip_addr_changed_pcblist.part.0 (old_addr_6(D), pcb_list_5(D));
  instance pointer: old_addr_6(D)  Outer instance pointer: old_addr_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: tcp_netif_ip_addr_changed_pcblist.part.0 (old_addr_6(D), pcb_list_5(D));
  Starting walk at: tcp_netif_ip_addr_changed_pcblist.part.0 (old_addr_6(D), pcb_list_5(D));
  instance pointer: pcb_list_5(D)  Outer instance pointer: pcb_list_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: tcp_pcb_remove.part.0 (pcblist_6(D), pcb_4(D));
  Starting walk at: tcp_pcb_remove.part.0 (pcblist_6(D), pcb_4(D));
  instance pointer: pcblist_6(D)  Outer instance pointer: pcblist_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: tcp_pcb_remove.part.0 (pcblist_6(D), pcb_4(D));
  Starting walk at: tcp_pcb_remove.part.0 (pcblist_6(D), pcb_4(D));
  instance pointer: pcb_4(D)  Outer instance pointer: pcb_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: tcp_pcb_purge.part.0 (pcb_4(D));
  Starting walk at: tcp_pcb_purge.part.0 (pcb_4(D));
  instance pointer: pcb_4(D)  Outer instance pointer: pcb_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: tcp_close_shutdown_fin (pcb_4);
  Starting walk at: tcp_close_shutdown_fin (pcb_4);
  instance pointer: pcb_4  Outer instance pointer: pcb_4 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_close_shutdown_fin (pcb_4);
Determining dynamic type for call: tcp_abort (inactive_4);
  Starting walk at: tcp_abort (inactive_4);
  instance pointer: inactive_4  Outer instance pointer: inactive_6 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: tcp_abort (inactive_17);
  Starting walk at: tcp_abort (inactive_17);
  instance pointer: inactive_17  Outer instance pointer: inactive_9 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _10 = tcp_recv_null.part.0 (pcb_4(D), err_6(D));
  Starting walk at: _10 = tcp_recv_null.part.0 (pcb_4(D), err_6(D));
  instance pointer: pcb_4(D)  Outer instance pointer: pcb_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: tcp_recved (pcb_4(D), _1);
  Starting walk at: tcp_recved (pcb_4(D), _1);
  instance pointer: pcb_4(D)  Outer instance pointer: pcb_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: tcp_seg_free (seg_1);
  Starting walk at: tcp_seg_free (seg_1);
  instance pointer: seg_1  Outer instance pointer: seg_1 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_seg_free (seg_1);
Determining dynamic type for call: err_15 = tcp_recv_null (0B, pcb_10(D), _1, 0);
  Starting walk at: err_15 = tcp_recv_null (0B, pcb_10(D), _1, 0);
  instance pointer: 0B  Outer instance pointer: 0B offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: err_15 = tcp_recv_null (0B, pcb_10(D), _1, 0);
  Starting walk at: err_15 = tcp_recv_null (0B, pcb_10(D), _1, 0);
  instance pointer: pcb_10(D)  Outer instance pointer: pcb_10(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: err_15 = tcp_recv_null (0B, pcb_10(D), _1, 0);
  Starting walk at: err_15 = tcp_recv_null (0B, pcb_10(D), _1, 0);
  instance pointer: _1  Outer instance pointer: _1 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: err_17 = _2 (_3, pcb_10(D), _1, 0);
  Starting walk at: err_17 = _2 (_3, pcb_10(D), _1, 0);
  instance pointer: _3  Outer instance pointer: _3 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: err_17 = _2 (_3, pcb_10(D), _1, 0);
  Starting walk at: err_17 = _2 (_3, pcb_10(D), _1, 0);
  instance pointer: pcb_10(D)  Outer instance pointer: pcb_10(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: err_17 = _2 (_3, pcb_10(D), _1, 0);
  Starting walk at: err_17 = _2 (_3, pcb_10(D), _1, 0);
  instance pointer: _1  Outer instance pointer: _1 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _4 = tcp_process_refused_data.part.0 (pcb_10(D));
  Starting walk at: _4 = tcp_process_refused_data.part.0 (pcb_10(D));
  instance pointer: pcb_10(D)  Outer instance pointer: pcb_10(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_17 = _2 (_3, pcb_10(D), _1, 0);
  Function call may change dynamic type:err_15 = tcp_recv_null (0B, pcb_10(D), _1, 0);
Determining dynamic type for call: tcp_close_shutdown_fin (pcb_14);
  Starting walk at: tcp_close_shutdown_fin (pcb_14);
  instance pointer: pcb_14  Outer instance pointer: pcb_14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_process_refused_data (pcb_14);
  Function call may change dynamic type:tcp_output (pcb_14);
  Function call may change dynamic type:tcp_close_shutdown_fin (pcb_14);
Determining dynamic type for call: tcp_process_refused_data (pcb_14);
  Starting walk at: tcp_process_refused_data (pcb_14);
  instance pointer: pcb_14  Outer instance pointer: pcb_14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_process_refused_data (pcb_14);
  Function call may change dynamic type:tcp_close_shutdown_fin (pcb_14);
  Function call may change dynamic type:tcp_output (pcb_14);
Determining dynamic type for call: tcp_pcb_purge (pcb_106);
  Starting walk at: tcp_pcb_purge (pcb_106);
  instance pointer: pcb_106  Outer instance pointer: pcb_106 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_free (pcb_106);
  Function call may change dynamic type:tcp_pcb_purge (pcb_106);
  Function call may change dynamic type:tcp_free (pcb_105);
  Function call may change dynamic type:tcp_pcb_purge (pcb_105);
  Function call may change dynamic type:_34 = tcp_rexmit_rto_prepare (pcb_105);
  Function call may change dynamic type:tcp_rexmit_rto_commit (pcb_105);
  Function call may change dynamic type:_23 = tcp_split_unsent_seg (pcb_105, _21);
  Function call may change dynamic type:_22 = tcp_zero_window_probe (pcb_105);
  Function call may change dynamic type:_24 = tcp_output (pcb_105);
  Function call may change dynamic type:err_186 = tcp_keepalive (pcb_105);
  Function call may change dynamic type:tcp_rst (pcb_105, _84, _85, _86, _87, _88, _89);
  Function call may change dynamic type:err_fn_198 (err_arg_205, -13);
  Function call may change dynamic type:tcp_output (pcb_105);
  Function call may change dynamic type:err_196 = _94 (_95, pcb_105);
Determining dynamic type for call: tcp_free (pcb_106);
  Starting walk at: tcp_free (pcb_106);
  instance pointer: pcb_106  Outer instance pointer: pcb_106 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_pcb_purge (pcb_106);
  Function call may change dynamic type:tcp_free (pcb_106);
  Function call may change dynamic type:tcp_free (pcb_105);
  Function call may change dynamic type:tcp_pcb_purge (pcb_105);
  Function call may change dynamic type:_34 = tcp_rexmit_rto_prepare (pcb_105);
  Function call may change dynamic type:tcp_rexmit_rto_commit (pcb_105);
  Function call may change dynamic type:_23 = tcp_split_unsent_seg (pcb_105, _21);
  Function call may change dynamic type:_22 = tcp_zero_window_probe (pcb_105);
  Function call may change dynamic type:_24 = tcp_output (pcb_105);
  Function call may change dynamic type:err_186 = tcp_keepalive (pcb_105);
  Function call may change dynamic type:tcp_rst (pcb_105, _84, _85, _86, _87, _88, _89);
  Function call may change dynamic type:err_fn_198 (err_arg_205, -13);
  Function call may change dynamic type:tcp_output (pcb_105);
  Function call may change dynamic type:err_196 = _94 (_95, pcb_105);
Determining dynamic type for call: err_196 = _94 (_95, pcb_105);
  Starting walk at: err_196 = _94 (_95, pcb_105);
  instance pointer: _95  Outer instance pointer: _95 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_free (pcb_105);
  Function call may change dynamic type:tcp_pcb_purge (pcb_105);
  Function call may change dynamic type:err_186 = tcp_keepalive (pcb_105);
  Function call may change dynamic type:tcp_rst (pcb_105, _84, _85, _86, _87, _88, _89);
  Function call may change dynamic type:err_fn_198 (err_arg_205, -13);
  Function call may change dynamic type:tcp_output (pcb_105);
  Function call may change dynamic type:err_196 = _94 (_95, pcb_105);
  Function call may change dynamic type:_34 = tcp_rexmit_rto_prepare (pcb_105);
  Function call may change dynamic type:tcp_rexmit_rto_commit (pcb_105);
  Function call may change dynamic type:_23 = tcp_split_unsent_seg (pcb_105, _21);
  Function call may change dynamic type:_22 = tcp_zero_window_probe (pcb_105);
  Function call may change dynamic type:_24 = tcp_output (pcb_105);
Determining dynamic type for call: err_196 = _94 (_95, pcb_105);
  Starting walk at: err_196 = _94 (_95, pcb_105);
  instance pointer: pcb_105  Outer instance pointer: pcb_105 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_free (pcb_105);
  Function call may change dynamic type:tcp_pcb_purge (pcb_105);
  Function call may change dynamic type:err_186 = tcp_keepalive (pcb_105);
  Function call may change dynamic type:tcp_rst (pcb_105, _84, _85, _86, _87, _88, _89);
  Function call may change dynamic type:err_fn_198 (err_arg_205, -13);
  Function call may change dynamic type:tcp_output (pcb_105);
  Function call may change dynamic type:err_196 = _94 (_95, pcb_105);
  Function call may change dynamic type:_34 = tcp_rexmit_rto_prepare (pcb_105);
  Function call may change dynamic type:tcp_rexmit_rto_commit (pcb_105);
  Function call may change dynamic type:_23 = tcp_split_unsent_seg (pcb_105, _21);
  Function call may change dynamic type:_22 = tcp_zero_window_probe (pcb_105);
  Function call may change dynamic type:_24 = tcp_output (pcb_105);
Determining dynamic type for call: tcp_pcb_purge (pcb_105);
  Starting walk at: tcp_pcb_purge (pcb_105);
  instance pointer: pcb_105  Outer instance pointer: pcb_105 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_free (pcb_105);
  Function call may change dynamic type:tcp_pcb_purge (pcb_105);
  Function call may change dynamic type:err_186 = tcp_keepalive (pcb_105);
  Function call may change dynamic type:tcp_rst (pcb_105, _84, _85, _86, _87, _88, _89);
  Function call may change dynamic type:err_fn_198 (err_arg_205, -13);
  Function call may change dynamic type:tcp_output (pcb_105);
  Function call may change dynamic type:err_196 = _94 (_95, pcb_105);
  Function call may change dynamic type:_34 = tcp_rexmit_rto_prepare (pcb_105);
  Function call may change dynamic type:tcp_rexmit_rto_commit (pcb_105);
  Function call may change dynamic type:_23 = tcp_split_unsent_seg (pcb_105, _21);
  Function call may change dynamic type:_22 = tcp_zero_window_probe (pcb_105);
  Function call may change dynamic type:_24 = tcp_output (pcb_105);
Determining dynamic type for call: tcp_free (pcb_105);
  Starting walk at: tcp_free (pcb_105);
  instance pointer: pcb_105  Outer instance pointer: pcb_105 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_pcb_purge (pcb_105);
  Function call may change dynamic type:tcp_free (pcb_105);
  Function call may change dynamic type:tcp_rst (pcb_105, _84, _85, _86, _87, _88, _89);
  Function call may change dynamic type:err_fn_198 (err_arg_205, -13);
  Function call may change dynamic type:tcp_output (pcb_105);
  Function call may change dynamic type:err_196 = _94 (_95, pcb_105);
  Function call may change dynamic type:_34 = tcp_rexmit_rto_prepare (pcb_105);
  Function call may change dynamic type:tcp_rexmit_rto_commit (pcb_105);
  Function call may change dynamic type:_23 = tcp_split_unsent_seg (pcb_105, _21);
  Function call may change dynamic type:_22 = tcp_zero_window_probe (pcb_105);
  Function call may change dynamic type:_24 = tcp_output (pcb_105);
  Function call may change dynamic type:err_186 = tcp_keepalive (pcb_105);
Determining dynamic type for call: err_fn_198 (err_arg_205, -13);
  Starting walk at: err_fn_198 (err_arg_205, -13);
  instance pointer: err_arg_205  Outer instance pointer: err_arg_205 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_free (pcb_105);
  Function call may change dynamic type:tcp_pcb_purge (pcb_105);
  Function call may change dynamic type:tcp_free (pcb_105);
  Function call may change dynamic type:tcp_rst (pcb_105, _84, _85, _86, _87, _88, _89);
  Function call may change dynamic type:err_fn_198 (err_arg_205, -13);
  Function call may change dynamic type:tcp_output (pcb_105);
  Function call may change dynamic type:err_196 = _94 (_95, pcb_105);
  Function call may change dynamic type:_34 = tcp_rexmit_rto_prepare (pcb_105);
  Function call may change dynamic type:tcp_rexmit_rto_commit (pcb_105);
  Function call may change dynamic type:_23 = tcp_split_unsent_seg (pcb_105, _21);
  Function call may change dynamic type:_22 = tcp_zero_window_probe (pcb_105);
  Function call may change dynamic type:_24 = tcp_output (pcb_105);
  Function call may change dynamic type:err_186 = tcp_keepalive (pcb_105);
Determining dynamic type for call: iss_107 = tcp_next_iss (pcb_57(D));
  Starting walk at: iss_107 = tcp_next_iss (pcb_57(D));
  instance pointer: pcb_57(D)  Outer instance pointer: pcb_57(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:netif_84 = netif_get_by_index (_5);
  Function call may change dynamic type:iftmp.40_82 = ip4_route (_9);
  Function call may change dynamic type:iftmp.40_80 = ip6_route (_7, _8);
  Function call may change dynamic type:iftmp.46_88 = ip6_select_source_address (netif_40, _17);
  Function call may change dynamic type:_30 = tcp_new_port ();
Determining dynamic type for call: _32 = tcp_eff_send_mss_netif (536, netif_40, _2);
  Starting walk at: _32 = tcp_eff_send_mss_netif (536, netif_40, _2);
  instance pointer: netif_40  Outer instance pointer: netif_40 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:iss_107 = tcp_next_iss (pcb_57(D));
  Function call may change dynamic type:netif_84 = netif_get_by_index (_5);
  Function call may change dynamic type:iftmp.40_82 = ip4_route (_9);
  Function call may change dynamic type:iftmp.40_80 = ip6_route (_7, _8);
  Function call may change dynamic type:iftmp.46_88 = ip6_select_source_address (netif_40, _17);
  Function call may change dynamic type:_30 = tcp_new_port ();
Determining dynamic type for call: _32 = tcp_eff_send_mss_netif (536, netif_40, _2);
  Starting walk at: _32 = tcp_eff_send_mss_netif (536, netif_40, _2);
  instance pointer: _2  Outer instance pointer: pcb_57(D) offset: 192 (bits) vtbl reference: 
  Function call may change dynamic type:iss_107 = tcp_next_iss (pcb_57(D));
  Function call may change dynamic type:netif_84 = netif_get_by_index (_5);
  Function call may change dynamic type:iftmp.40_82 = ip4_route (_9);
  Function call may change dynamic type:iftmp.40_80 = ip6_route (_7, _8);
  Function call may change dynamic type:iftmp.46_88 = ip6_select_source_address (netif_40, _17);
  Function call may change dynamic type:_30 = tcp_new_port ();
Determining dynamic type for call: wnd_inflation_13 = tcp_update_rcv_ann_wnd (pcb_6(D));
  Starting walk at: wnd_inflation_13 = tcp_update_rcv_ann_wnd (pcb_6(D));
  instance pointer: pcb_6(D)  Outer instance pointer: pcb_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: tcp_recved.part.0 (pcb_6(D));
  Starting walk at: tcp_recved.part.0 (pcb_6(D));
  instance pointer: pcb_6(D)  Outer instance pointer: pcb_6(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:wnd_inflation_13 = tcp_update_rcv_ann_wnd (pcb_6(D));
Determining dynamic type for call: tcp_free (pcb_33(D));
  Starting walk at: tcp_free (pcb_33(D));
  instance pointer: pcb_33(D)  Outer instance pointer: pcb_33(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:lpcb_36 = memp_malloc (3);
Determining dynamic type for call: _5 = tcp_listen_with_backlog_and_err (pcb_2(D), backlog_3(D), 0B);
  Starting walk at: _5 = tcp_listen_with_backlog_and_err (pcb_2(D), backlog_3(D), 0B);
  instance pointer: pcb_2(D)  Outer instance pointer: pcb_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _5 = tcp_listen_with_backlog_and_err (pcb_2(D), backlog_3(D), 0B);
  Starting walk at: _5 = tcp_listen_with_backlog_and_err (pcb_2(D), backlog_3(D), 0B);
  instance pointer: 0B  Outer instance pointer: 0B offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: tcp_abort (pcb_2(D));
  Starting walk at: tcp_abort (pcb_2(D));
  instance pointer: pcb_2(D)  Outer instance pointer: pcb_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: tcp_abandon (pcb_2(D), 1);
  Starting walk at: tcp_abandon (pcb_2(D), 1);
  instance pointer: pcb_2(D)  Outer instance pointer: pcb_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: tcp_pcb_remove (&tcp_active_pcbs, pcb_23(D));
  Starting walk at: tcp_pcb_remove (&tcp_active_pcbs, pcb_23(D));
  instance pointer: &tcp_active_pcbs  Outer instance pointer: tcp_active_pcbs offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: tcp_pcb_remove (&tcp_active_pcbs, pcb_23(D));
  Starting walk at: tcp_pcb_remove (&tcp_active_pcbs, pcb_23(D));
  instance pointer: pcb_23(D)  Outer instance pointer: pcb_23(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: tcp_segs_free (_8);
  Starting walk at: tcp_segs_free (_8);
  instance pointer: _8  Outer instance pointer: _8 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_pcb_remove (&tcp_active_pcbs, pcb_23(D));
Determining dynamic type for call: tcp_segs_free (_9);
  Starting walk at: tcp_segs_free (_9);
  instance pointer: _9  Outer instance pointer: _9 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_pcb_remove (&tcp_active_pcbs, pcb_23(D));
  Function call may change dynamic type:tcp_segs_free (_8);
Determining dynamic type for call: tcp_backlog_accepted (pcb_23(D));
  Starting walk at: tcp_backlog_accepted (pcb_23(D));
  instance pointer: pcb_23(D)  Outer instance pointer: pcb_23(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_pcb_remove (&tcp_active_pcbs, pcb_23(D));
  Function call may change dynamic type:tcp_segs_free (_8);
  Function call may change dynamic type:tcp_segs_free (_9);
Determining dynamic type for call: tcp_free (pcb_23(D));
  Starting walk at: tcp_free (pcb_23(D));
  instance pointer: pcb_23(D)  Outer instance pointer: pcb_23(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_backlog_accepted (pcb_23(D));
  Function call may change dynamic type:tcp_pcb_remove (&tcp_active_pcbs, pcb_23(D));
  Function call may change dynamic type:tcp_segs_free (_8);
  Function call may change dynamic type:tcp_segs_free (_9);
  Function call may change dynamic type:tcp_rst (pcb_23(D), seqno_25, ackno_26, _10, _11, local_port_14, _12);
Determining dynamic type for call: errf_27 (errf_arg_28, -13);
  Starting walk at: errf_27 (errf_arg_28, -13);
  instance pointer: errf_arg_28  Outer instance pointer: errf_arg_28 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_free (pcb_23(D));
  Function call may change dynamic type:tcp_backlog_accepted (pcb_23(D));
  Function call may change dynamic type:tcp_pcb_remove (&tcp_active_pcbs, pcb_23(D));
  Function call may change dynamic type:tcp_segs_free (_8);
  Function call may change dynamic type:tcp_segs_free (_9);
  Function call may change dynamic type:tcp_rst (pcb_23(D), seqno_25, ackno_26, _10, _11, local_port_14, _12);
Determining dynamic type for call: tcp_pcb_remove (&tcp_tw_pcbs, pcb_23(D));
  Starting walk at: tcp_pcb_remove (&tcp_tw_pcbs, pcb_23(D));
  instance pointer: &tcp_tw_pcbs  Outer instance pointer: tcp_tw_pcbs offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: tcp_pcb_remove (&tcp_tw_pcbs, pcb_23(D));
  Starting walk at: tcp_pcb_remove (&tcp_tw_pcbs, pcb_23(D));
  instance pointer: pcb_23(D)  Outer instance pointer: pcb_23(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: tcp_free (pcb_23(D));
  Starting walk at: tcp_free (pcb_23(D));
  instance pointer: pcb_23(D)  Outer instance pointer: pcb_23(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_pcb_remove (&tcp_tw_pcbs, pcb_23(D));
Determining dynamic type for call: _18 = tcp_close_shutdown (pcb_10(D), 1);
  Starting walk at: _18 = tcp_close_shutdown (pcb_10(D), 1);
  instance pointer: pcb_10(D)  Outer instance pointer: pcb_10(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _20 = tcp_close_shutdown (pcb_10(D), _6);
  Starting walk at: _20 = tcp_close_shutdown (pcb_10(D), _6);
  instance pointer: pcb_10(D)  Outer instance pointer: pcb_10(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pbuf_free (_4);
Determining dynamic type for call: _11 = tcp_close_shutdown (pcb_7(D), 1);
  Starting walk at: _11 = tcp_close_shutdown (pcb_7(D), 1);
  instance pointer: pcb_7(D)  Outer instance pointer: pcb_7(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: tcp_backlog_accepted (pcb_15(D));
  Starting walk at: tcp_backlog_accepted (pcb_15(D));
  instance pointer: pcb_15(D)  Outer instance pointer: pcb_15(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_26 = tcp_send_fin (pcb_15(D));
Determining dynamic type for call: tcp_pcb_purge (pcb_35(D));
  Starting walk at: tcp_pcb_purge (pcb_35(D));
  instance pointer: pcb_35(D)  Outer instance pointer: pcb_35(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_rst (pcb_35(D), _6, _7, _8, _9, _10, _11);
Determining dynamic type for call: tcp_free (pcb_35(D));
  Starting walk at: tcp_free (pcb_35(D));
  instance pointer: pcb_35(D)  Outer instance pointer: pcb_35(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_pcb_purge (pcb_35(D));
  Function call may change dynamic type:tcp_rst (pcb_35(D), _6, _7, _8, _9, _10, _11);
Determining dynamic type for call: tcp_pcb_remove (&tcp_active_pcbs, pcb_35(D));
  Starting walk at: tcp_pcb_remove (&tcp_active_pcbs, pcb_35(D));
  instance pointer: &tcp_active_pcbs  Outer instance pointer: tcp_active_pcbs offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: tcp_pcb_remove (&tcp_active_pcbs, pcb_35(D));
  Starting walk at: tcp_pcb_remove (&tcp_active_pcbs, pcb_35(D));
  instance pointer: pcb_35(D)  Outer instance pointer: pcb_35(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: tcp_free (pcb_35(D));
  Starting walk at: tcp_free (pcb_35(D));
  instance pointer: pcb_35(D)  Outer instance pointer: pcb_35(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_pcb_remove (&tcp_active_pcbs, pcb_35(D));
Determining dynamic type for call: tcp_listen_closed (pcb_35(D));
  Starting walk at: tcp_listen_closed (pcb_35(D));
  instance pointer: pcb_35(D)  Outer instance pointer: pcb_35(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: tcp_pcb_remove (&tcp_listen_pcbs.pcbs, pcb_35(D));
  Starting walk at: tcp_pcb_remove (&tcp_listen_pcbs.pcbs, pcb_35(D));
  instance pointer: &tcp_listen_pcbs.pcbs  Outer instance pointer: tcp_listen_pcbs offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_listen_closed (pcb_35(D));
Determining dynamic type for call: tcp_pcb_remove (&tcp_listen_pcbs.pcbs, pcb_35(D));
  Starting walk at: tcp_pcb_remove (&tcp_listen_pcbs.pcbs, pcb_35(D));
  instance pointer: pcb_35(D)  Outer instance pointer: pcb_35(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_listen_closed (pcb_35(D));
Determining dynamic type for call: tcp_free_listen (pcb_35(D));
  Starting walk at: tcp_free_listen (pcb_35(D));
  instance pointer: pcb_35(D)  Outer instance pointer: pcb_35(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_pcb_remove (&tcp_listen_pcbs.pcbs, pcb_35(D));
  Function call may change dynamic type:tcp_listen_closed (pcb_35(D));
Determining dynamic type for call: tcp_free (pcb_35(D));
  Starting walk at: tcp_free (pcb_35(D));
  instance pointer: pcb_35(D)  Outer instance pointer: pcb_35(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _61 = tcp_close_shutdown_fin (pcb_35(D));
  Starting walk at: _61 = tcp_close_shutdown_fin (pcb_35(D));
  instance pointer: pcb_35(D)  Outer instance pointer: pcb_35(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: tcp_remove_listener (_3, pcb_8(D));
  Starting walk at: tcp_remove_listener (_3, pcb_8(D));
  instance pointer: _3  Outer instance pointer: _3 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_remove_listener (_3, pcb_8(D));
Determining dynamic type for call: tcp_remove_listener (_3, pcb_8(D));
  Starting walk at: tcp_remove_listener (_3, pcb_8(D));
  instance pointer: pcb_8(D)  Outer instance pointer: pcb_8(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_remove_listener (_3, pcb_8(D));
Determining dynamic type for call: tcp_free.part.0 (pcb_4(D));
  Starting walk at: tcp_free.part.0 (pcb_4(D));
  instance pointer: pcb_4(D)  Outer instance pointer: pcb_4(D) offset: 0 (bits) vtbl reference: 

IPA structures before propagation:

Jump functions:
  Jump functions of caller  tcp_kill_state.part.0/98:
    callsite  tcp_kill_state.part.0/98 -> tcp_abandon/26 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  tcp_netif_ip_addr_changed_pcblist.part.0/97:
    callsite  tcp_netif_ip_addr_changed_pcblist.part.0/97 -> tcp_abort/27 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_process_refused_data.part.0/96:
    indirect aggregate callsite, calling param 0, offset 1344, by reference, for stmt err_6 = _4 (_5, pcb_1(D), 0B, 0);
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: 0B
         value: 0x0, mask: 0xfffffff8
         Unknown VR
       param 3: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  tcp_recv_null.part.0/95:
    callsite  tcp_recv_null.part.0/95 -> tcp_close/24 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_pcb_remove.part.0/94:
    callsite  tcp_pcb_remove.part.0/94 -> tcp_pcb_purge/58 : 
       param 0: PASS THROUGH: 1, op nop_expr
         Aggregate passed by reference:
           offset: 416, cst: 0B
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_pcb_purge.part.0/93:
    callsite  tcp_pcb_purge.part.0/93 -> tcp_backlog_accepted/21 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  tcp_pcb_purge.part.0/93 -> tcp_segs_free/41 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  tcp_pcb_purge.part.0/93 -> tcp_segs_free/41 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_recved.part.0/92:
  Jump functions of caller  tcp_free.part.0/91:
  Jump functions of caller  nd6_get_destination_mtu/90:
  Jump functions of caller  memset/88:
  Jump functions of caller  tcp_keepalive/87:
  Jump functions of caller  tcp_rexmit_rto_commit/86:
  Jump functions of caller  tcp_rexmit_rto_prepare/85:
  Jump functions of caller  tcp_split_unsent_seg/84:
  Jump functions of caller  tcp_zero_window_probe/83:
  Jump functions of caller  tcp_enqueue_flags/82:
  Jump functions of caller  ip6_select_source_address/81:
  Jump functions of caller  ip4_route/80:
  Jump functions of caller  netif_get_by_index/79:
  Jump functions of caller  memp_malloc/78:
  Jump functions of caller  tcp_timer_needed/77:
  Jump functions of caller  ip6_route/76:
  Jump functions of caller  pbuf_free/74:
  Jump functions of caller  tcp_output/73:
  Jump functions of caller  tcp_send_fin/72:
  Jump functions of caller  tcp_trigger_input_pcb_close/70:
  Jump functions of caller  tcp_rst/68:
  Jump functions of caller  memp_free/67:
  Jump functions of caller  rand/66:
  Jump functions of caller  tcp_tcp_get_tcp_addrinfo/65:
  Jump functions of caller  tcp_debug_state_str/64:
  Jump functions of caller  tcp_netif_ip_addr_changed/63:
    callsite  tcp_netif_ip_addr_changed/63 -> tcp_netif_ip_addr_changed_pcblist/62 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  tcp_netif_ip_addr_changed/63 -> tcp_netif_ip_addr_changed_pcblist/62 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_netif_ip_addr_changed_pcblist/62:
    callsite  tcp_netif_ip_addr_changed_pcblist/62 -> tcp_netif_ip_addr_changed_pcblist.part.0/97 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_eff_send_mss_netif/61:
  Jump functions of caller  tcp_next_iss/60:
  Jump functions of caller  tcp_pcb_remove/59:
    callsite  tcp_pcb_remove/59 -> tcp_pcb_remove.part.0/94 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_pcb_purge/58:
    callsite  tcp_pcb_purge/58 -> tcp_pcb_purge.part.0/93 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_poll/57:
  Jump functions of caller  tcp_accept/56:
  Jump functions of caller  tcp_err/55:
  Jump functions of caller  tcp_sent/54:
  Jump functions of caller  tcp_recv/53:
  Jump functions of caller  tcp_arg/52:
  Jump functions of caller  tcp_new_ip_type/51:
    callsite  tcp_new_ip_type/51 -> tcp_alloc/49 : 
       param 0: CONST: 64
         value: 0x40, mask: 0x0
         Unknown VR
  Jump functions of caller  tcp_new/50:
    callsite  tcp_new/50 -> tcp_alloc/49 : 
       param 0: CONST: 64
         value: 0x40, mask: 0x0
         Unknown VR
  Jump functions of caller  tcp_alloc/49:
    callsite  tcp_alloc/49 -> tcp_kill_prio/45 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  tcp_alloc/49 -> tcp_kill_state/46 : 
       param 0: CONST: 8
         value: 0x8, mask: 0x0
         Unknown VR
    callsite  tcp_alloc/49 -> tcp_kill_state/46 : 
       param 0: CONST: 9
         value: 0x9, mask: 0x0
         Unknown VR
    callsite  tcp_alloc/49 -> tcp_kill_timewait/47 : 
    callsite  tcp_alloc/49 -> tcp_handle_closepend/48 : 
  Jump functions of caller  tcp_handle_closepend/48:
    callsite  tcp_handle_closepend/48 -> tcp_close_shutdown_fin/23 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_kill_timewait/47:
    callsite  tcp_kill_timewait/47 -> tcp_abort/27 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_kill_state/46:
    callsite  tcp_kill_state/46 -> tcp_kill_state.part.0/98 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  tcp_kill_prio/45:
    callsite  tcp_kill_prio/45 -> tcp_abort/27 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_recv_null/44:
    callsite  tcp_recv_null/44 -> tcp_recv_null.part.0/95 : 
       param 0: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
         Unknown VR
    callsite  tcp_recv_null/44 -> tcp_recved/34 : 
       param 0: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
  Jump functions of caller  tcp_setprio/43:
  Jump functions of caller  tcp_seg_free/42:
  Jump functions of caller  tcp_segs_free/41:
    callsite  tcp_segs_free/41 -> tcp_seg_free/42 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_process_refused_data/40:
    callsite  tcp_process_refused_data/40 -> tcp_process_refused_data.part.0/96 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  tcp_process_refused_data/40 -> tcp_recv_null/44 : 
       param 0: CONST: 0B
         value: 0x0, mask: 0xfffffff8
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    indirect aggregate callsite, calling param 0, offset 1344, by reference, for stmt err_17 = _2 (_3, pcb_10(D), _1, 0);
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  tcp_txnow/39:
  Jump functions of caller  tcp_fasttmr/38:
    callsite  tcp_fasttmr/38 -> tcp_process_refused_data/40 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  tcp_fasttmr/38 -> tcp_close_shutdown_fin/23 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_slowtmr/37:
    callsite  tcp_slowtmr/37 -> tcp_free/15 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  tcp_slowtmr/37 -> tcp_pcb_purge/58 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  tcp_slowtmr/37 -> tcp_free/15 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  tcp_slowtmr/37 -> tcp_pcb_purge/58 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    indirect simple callsite, calling param -1, offset 0, for stmt err_196 = _94 (_95, pcb_105);
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    indirect simple callsite, calling param -1, offset 0, for stmt err_fn_198 (err_arg_205, -13);
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: -13
         value: 0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff3, mask: 0x0
         Unknown VR
  Jump functions of caller  tcp_connect/36:
    callsite  tcp_connect/36 -> tcp_eff_send_mss_netif/61 : 
       param 0: CONST: 536
         value: 0x218, mask: 0x0
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: ANCESTOR: 0, offset 192
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  tcp_connect/36 -> tcp_next_iss/60 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  tcp_connect/36 -> tcp_new_port/35 : 
  Jump functions of caller  tcp_new_port/35:
  Jump functions of caller  tcp_recved/34:
    callsite  tcp_recved/34 -> tcp_recved.part.0/92 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  tcp_recved/34 -> tcp_update_rcv_ann_wnd/33 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_update_rcv_ann_wnd/33:
  Jump functions of caller  tcp_listen_with_backlog_and_err/32:
    callsite  tcp_listen_with_backlog_and_err/32 -> tcp_free/15 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_listen_with_backlog/31:
    callsite  tcp_listen_with_backlog/31 -> tcp_listen_with_backlog_and_err/32 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: CONST: 0B
         value: 0x0, mask: 0xfffffff8
         Unknown VR
  Jump functions of caller  tcp_accept_null/30:
    callsite  tcp_accept_null/30 -> tcp_abort/27 : 
       param 0: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_bind_netif/29:
  Jump functions of caller  tcp_bind/28:
    callsite  tcp_bind/28 -> tcp_new_port/35 : 
  Jump functions of caller  tcp_abort/27:
    callsite  tcp_abort/27 -> tcp_abandon/26 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
  Jump functions of caller  tcp_abandon/26:
    callsite  tcp_abandon/26 -> tcp_free/15 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  tcp_abandon/26 -> tcp_backlog_accepted/21 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  tcp_abandon/26 -> tcp_segs_free/41 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  tcp_abandon/26 -> tcp_segs_free/41 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  tcp_abandon/26 -> tcp_pcb_remove/59 : 
       param 0: CONST: &tcp_active_pcbs
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  tcp_abandon/26 -> tcp_free/15 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  tcp_abandon/26 -> tcp_pcb_remove/59 : 
       param 0: CONST: &tcp_tw_pcbs
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
    indirect aggregate callsite, calling param 0, offset 1440, by reference, for stmt errf_27 (errf_arg_28, -13);
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: -13
         value: 0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff3, mask: 0x0
         Unknown VR
  Jump functions of caller  tcp_shutdown/25:
    callsite  tcp_shutdown/25 -> tcp_close_shutdown/22 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  tcp_shutdown/25 -> tcp_close_shutdown/22 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
  Jump functions of caller  tcp_close/24:
    callsite  tcp_close/24 -> tcp_close_shutdown/22 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
  Jump functions of caller  tcp_close_shutdown_fin/23:
    callsite  tcp_close_shutdown_fin/23 -> tcp_backlog_accepted/21 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_close_shutdown/22:
    callsite  tcp_close_shutdown/22 -> tcp_close_shutdown_fin/23 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  tcp_close_shutdown/22 -> tcp_free/15 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  tcp_close_shutdown/22 -> tcp_pcb_remove/59 : 
       param 0: CONST: &tcp_active_pcbs
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  tcp_close_shutdown/22 -> tcp_free_listen/16 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  tcp_close_shutdown/22 -> tcp_pcb_remove/59 : 
       param 0: CONST: &tcp_listen_pcbs.pcbs
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  tcp_close_shutdown/22 -> tcp_listen_closed/19 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  tcp_close_shutdown/22 -> tcp_free/15 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  tcp_close_shutdown/22 -> tcp_free/15 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  tcp_close_shutdown/22 -> tcp_pcb_purge/58 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_backlog_accepted/21:
  Jump functions of caller  tcp_backlog_delayed/20:
  Jump functions of caller  tcp_listen_closed/19:
    callsite  tcp_listen_closed/19 -> tcp_remove_listener/18 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_remove_listener/18:
  Jump functions of caller  tcp_tmr/17:
    callsite  tcp_tmr/17 -> tcp_slowtmr/37 : 
    callsite  tcp_tmr/17 -> tcp_fasttmr/38 : 
  Jump functions of caller  tcp_free_listen/16:
  Jump functions of caller  tcp_free/15:
    callsite  tcp_free/15 -> tcp_free.part.0/91 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_init/14:

 Propagating constants:

Not considering tcp_tcp_get_tcp_addrinfo for cloning; -fipa-cp-clone disabled.
Not considering tcp_debug_state_str for cloning; -fipa-cp-clone disabled.
Not considering tcp_netif_ip_addr_changed for cloning; -fipa-cp-clone disabled.
Not considering tcp_eff_send_mss_netif for cloning; -fipa-cp-clone disabled.
Not considering tcp_next_iss for cloning; -fipa-cp-clone disabled.
Not considering tcp_pcb_remove for cloning; -fipa-cp-clone disabled.
Not considering tcp_pcb_purge for cloning; -fipa-cp-clone disabled.
Not considering tcp_poll for cloning; -fipa-cp-clone disabled.
Not considering tcp_accept for cloning; -fipa-cp-clone disabled.
Not considering tcp_err for cloning; -fipa-cp-clone disabled.
Not considering tcp_sent for cloning; -fipa-cp-clone disabled.
Not considering tcp_recv for cloning; -fipa-cp-clone disabled.
Not considering tcp_arg for cloning; -fipa-cp-clone disabled.
Not considering tcp_new_ip_type for cloning; -fipa-cp-clone disabled.
Not considering tcp_new for cloning; -fipa-cp-clone disabled.
Not considering tcp_alloc for cloning; -fipa-cp-clone disabled.
Not considering tcp_recv_null for cloning; -fipa-cp-clone disabled.
Not considering tcp_setprio for cloning; -fipa-cp-clone disabled.
Not considering tcp_seg_free for cloning; -fipa-cp-clone disabled.
Not considering tcp_segs_free for cloning; -fipa-cp-clone disabled.
Not considering tcp_process_refused_data for cloning; -fipa-cp-clone disabled.
Not considering tcp_txnow for cloning; -fipa-cp-clone disabled.
Not considering tcp_fasttmr for cloning; -fipa-cp-clone disabled.
Not considering tcp_slowtmr for cloning; -fipa-cp-clone disabled.
Not considering tcp_connect for cloning; -fipa-cp-clone disabled.
Not considering tcp_recved for cloning; -fipa-cp-clone disabled.
Not considering tcp_update_rcv_ann_wnd for cloning; -fipa-cp-clone disabled.
Not considering tcp_listen_with_backlog_and_err for cloning; -fipa-cp-clone disabled.
Not considering tcp_listen_with_backlog for cloning; -fipa-cp-clone disabled.
Not considering tcp_accept_null for cloning; -fipa-cp-clone disabled.
Not considering tcp_bind_netif for cloning; -fipa-cp-clone disabled.
Not considering tcp_bind for cloning; -fipa-cp-clone disabled.
Not considering tcp_abort for cloning; -fipa-cp-clone disabled.
Not considering tcp_abandon for cloning; -fipa-cp-clone disabled.
Not considering tcp_shutdown for cloning; -fipa-cp-clone disabled.
Not considering tcp_close for cloning; -fipa-cp-clone disabled.
Not considering tcp_backlog_accepted for cloning; -fipa-cp-clone disabled.
Not considering tcp_backlog_delayed for cloning; -fipa-cp-clone disabled.
Not considering tcp_tmr for cloning; -fipa-cp-clone disabled.
Not considering tcp_free for cloning; -fipa-cp-clone disabled.
Not considering tcp_init for cloning; -fipa-cp-clone disabled.

overall_size: 2056, max_new_size: 11001
 - context independent values, size: 9, time_benefit: 2.000000
 - context independent values, size: 16, time_benefit: 1.000000

IPA lattices after all propagation:

Lattices:
  Node: tcp_kill_state.part.0/98:
    param [0]: 8 [loc_time: 1, loc_size: 20, prop_time: 0, prop_size: 0]
               9 [loc_time: 1, loc_size: 20, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x8, mask = 0x1
         tcp_state [8, 9]
        AGGS VARIABLE
  Node: tcp_netif_ip_addr_changed_pcblist.part.0/97:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: tcp_process_refused_data.part.0/96:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: tcp_recv_null.part.0/95:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: tcp_pcb_remove.part.0/94:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: tcp_pcb_purge.part.0/93:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: tcp_recved.part.0/92:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: tcp_free.part.0/91:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: tcp_tcp_get_tcp_addrinfo/65:
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
  Node: tcp_debug_state_str/64:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: tcp_netif_ip_addr_changed/63:
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
  Node: tcp_netif_ip_addr_changed_pcblist/62:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: tcp_eff_send_mss_netif/61:
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
  Node: tcp_next_iss/60:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: tcp_pcb_remove/59:
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
  Node: tcp_pcb_purge/58:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: tcp_poll/57:
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
  Node: tcp_accept/56:
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
  Node: tcp_err/55:
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
  Node: tcp_sent/54:
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
  Node: tcp_recv/53:
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
  Node: tcp_arg/52:
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
  Node: tcp_new_ip_type/51:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: tcp_new/50:
  Node: tcp_alloc/49:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: tcp_handle_closepend/48:
  Node: tcp_kill_timewait/47:
  Node: tcp_kill_state/46:
    param [0]: 9 [loc_time: 4, loc_size: 7, prop_time: 0, prop_size: 0]
               8 [loc_time: 4, loc_size: 7, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x8, mask = 0x1
         tcp_state [8, 9]
        AGGS VARIABLE
  Node: tcp_kill_prio/45:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: tcp_recv_null/44:
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
  Node: tcp_setprio/43:
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
  Node: tcp_seg_free/42:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: tcp_segs_free/41:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: tcp_process_refused_data/40:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: tcp_txnow/39:
  Node: tcp_fasttmr/38:
  Node: tcp_slowtmr/37:
  Node: tcp_connect/36:
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
  Node: tcp_new_port/35:
  Node: tcp_recved/34:
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
  Node: tcp_update_rcv_ann_wnd/33:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: tcp_listen_with_backlog_and_err/32:
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
  Node: tcp_listen_with_backlog/31:
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
  Node: tcp_accept_null/30:
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
  Node: tcp_bind_netif/29:
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
  Node: tcp_bind/28:
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
  Node: tcp_abort/27:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: tcp_abandon/26:
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
  Node: tcp_shutdown/25:
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
  Node: tcp_close/24:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: tcp_close_shutdown_fin/23:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: tcp_close_shutdown/22:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
               1 [loc_time: 2, loc_size: 104, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: tcp_backlog_accepted/21:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: tcp_backlog_delayed/20:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: tcp_listen_closed/19:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: tcp_remove_listener/18:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: tcp_tmr/17:
  Node: tcp_free_listen/16:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: tcp_free/15:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: tcp_init/14:

IPA decision stage:

Propagated bits info for function tcp_kill_state.part.0/98:
 param 0: value = 0x8, mask = 0x1
Propagated bits info for function tcp_kill_state/46:
 param 0: value = 0x8, mask = 0x1

IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

tcp_kill_state.part.0/98 (tcp_kill_state.part.0) @0659a8c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: tcp_active_pcbs/8 (read)tcp_ticks/3 (read)
  Referring: 
  Availability: local
  Function flags: count:118111600 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: tcp_kill_state/46 (74616 (estimated locally),0.41 per call) 
  Calls: tcp_abandon/26 (63154273 (estimated locally),0.53 per call) 
tcp_netif_ip_addr_changed_pcblist.part.0/97 (tcp_netif_ip_addr_changed_pcblist.part.0) @0659ae00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:118111600 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: tcp_netif_ip_addr_changed_pcblist/62 (250539 (estimated locally),0.70 per call) 
  Calls: tcp_abort/27 (107221711 (estimated locally),0.91 per call) 
tcp_process_refused_data.part.0/96 (tcp_process_refused_data.part.0) @0659a2a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: tcp_process_refused_data/40 (267227497 (estimated locally),0.25 per call) 
  Calls: 
   Indirect call(751619278 (estimated locally),0.70 per call)  of param:0 loaded from aggregate passed by reference at offset 1344 (vptr maybe changed)
tcp_recv_null.part.0/95 (tcp_recv_null.part.0) @06574540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: tcp_recv_null/44 (497363818 (estimated locally),0.46 per call) 
  Calls: tcp_close/24 (217325345 (estimated locally),0.20 per call) 
tcp_pcb_remove.part.0/94 (tcp_pcb_remove.part.0) @06574d20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:232411 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: tcp_pcb_remove/59 (175377 (estimated locally),0.49 per call) 
  Calls: tcp_pcb_purge/58 (232411 (estimated locally),1.00 per call) tcp_output/73 (33409 (estimated locally),0.14 per call) 
tcp_pcb_purge.part.0/93 (tcp_pcb_purge.part.0) @06574380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: tcp_pcb_purge/58 (141867178 (estimated locally),0.13 per call) 
  Calls: tcp_backlog_accepted/21 (1073741824 (estimated locally),1.00 per call) pbuf_free/74 (574129754 (estimated locally),0.53 per call) tcp_segs_free/41 (1073741824 (estimated locally),1.00 per call) tcp_segs_free/41 (1073741824 (estimated locally),1.00 per call) 
tcp_recved.part.0/92 (tcp_recved.part.0) @0643e380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: tcp_recved/34 (68783 (estimated locally),0.18 per call) 
  Calls: tcp_output/73 (1073741824 (estimated locally),1.00 per call) 
tcp_free.part.0/91 (tcp_free.part.0) @05fa18c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: tcp_free/15 (102669 (estimated locally),0.49 per call) 
  Calls: memp_free/67 (1073741824 (estimated locally),1.00 per call) 
nd6_get_destination_mtu/90 (nd6_get_destination_mtu) @063af8c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_eff_send_mss_netif/61 (50709 (estimated locally),0.14 per call) 
  Calls: 
iss.7855/89 (iss) @063be2d0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: tcp_next_iss/60 (read)tcp_next_iss/60 (write)
  Availability: available
  Varpool flags: initialized
memset/88 (memset) @063947e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_alloc/49 (574129754 (estimated locally),0.53 per call) 
  Calls: 
tcp_keepalive/87 (tcp_keepalive) @063577e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_slowtmr/37 (186443 (estimated locally),0.39 per call) 
  Calls: 
tcp_rexmit_rto_commit/86 (tcp_rexmit_rto_commit) @06357ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_slowtmr/37 (131862 (estimated locally),0.28 per call) 
  Calls: 
tcp_rexmit_rto_prepare/85 (tcp_rexmit_rto_prepare) @06357e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_slowtmr/37 (217954 (estimated locally),0.46 per call) 
  Calls: 
tcp_split_unsent_seg/84 (tcp_split_unsent_seg) @06357700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_slowtmr/37 (65017 (estimated locally),0.14 per call) 
  Calls: 
tcp_zero_window_probe/83 (tcp_zero_window_probe) @063578c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_slowtmr/37 (65017 (estimated locally),0.14 per call) 
  Calls: 
tcp_enqueue_flags/82 (tcp_enqueue_flags) @06357c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_connect/36 (656363041 (estimated locally),0.97 per call) 
  Calls: 
ip6_select_source_address/81 (ip6_select_source_address) @06357b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_connect/36 (66921724 (estimated locally),0.10 per call) 
  Calls: 
ip4_route/80 (ip4_route) @06357a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_connect/36 (293740668 (estimated locally),0.43 per call) 
  Calls: 
netif_get_by_index/79 (netif_get_by_index) @063579a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_connect/36 (219209454 (estimated locally),0.32 per call) 
  Calls: 
memp_malloc/78 (memp_malloc) @063572a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_alloc/49 (991036 (estimated locally),0.00 per call) tcp_alloc/49 (5685806 (estimated locally),0.01 per call) tcp_alloc/49 (32620803 (estimated locally),0.03 per call) tcp_alloc/49 (187153200 (estimated locally),0.17 per call) tcp_alloc/49 (1073741824 (estimated locally),1.00 per call) tcp_listen_with_backlog_and_err/32 (146758 (estimated locally),0.64 per call) 
  Calls: 
tcp_timer_needed/77 (tcp_timer_needed) @06317e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_connect/36 (328181520 (estimated locally),0.48 per call) tcp_listen_with_backlog_and_err/32 (27247 (estimated locally),0.12 per call) tcp_bind/28 (14801258 (estimated locally),0.64 per call) 
  Calls: 
ip6_route/76 (ip6_route) @06317d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_connect/36 (151320950 (estimated locally),0.22 per call) tcp_bind/28 (549431 (estimated locally),0.02 per call) 
  Calls: 
ip_addr_any/75 (ip_addr_any) @0633cf30
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: tcp_bind/28 (addr)
  Availability: not_available
  Varpool flags: read-only
pbuf_free/74 (pbuf_free) @06317540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_shutdown/25 (226701775 (estimated locally),0.21 per call) tcp_recv_null/44 (571546170 (estimated locally),0.53 per call) tcp_pcb_purge.part.0/93 (574129754 (estimated locally),0.53 per call) tcp_seg_free/42 (401890828 (estimated locally),0.37 per call) 
  Calls: 
tcp_output/73 (tcp_output) @06317380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_connect/36 (328181520 (estimated locally),0.48 per call) tcp_fasttmr/38 (220998616 (estimated locally),3.74 per call) tcp_pcb_remove.part.0/94 (33409 (estimated locally),0.14 per call) tcp_slowtmr/37 (433800 (estimated locally),0.91 per call) tcp_slowtmr/37 (21456 (estimated locally),0.04 per call) tcp_txnow/39 (315357973 (estimated locally),2.67 per call) tcp_recved.part.0/92 (1073741824 (estimated locally),1.00 per call) tcp_close_shutdown_fin/23 (62008 (estimated locally),0.17 per call) 
  Calls: 
tcp_send_fin/72 (tcp_send_fin) @063171c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_close_shutdown_fin/23 (62635 (estimated locally),0.18 per call) tcp_close_shutdown_fin/23 (62635 (estimated locally),0.18 per call) tcp_close_shutdown_fin/23 (62635 (estimated locally),0.18 per call) 
  Calls: 
lwip_stats/71 (lwip_stats) @06315090
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: tcp_alloc/49 (read)tcp_alloc/49 (read)tcp_close_shutdown/22 (read)tcp_close_shutdown/22 (write)tcp_close_shutdown_fin/23 (read)tcp_close_shutdown_fin/23 (write)tcp_close_shutdown_fin/23 (read)tcp_close_shutdown_fin/23 (write)tcp_close_shutdown_fin/23 (read)tcp_close_shutdown_fin/23 (write)tcp_alloc/49 (read)tcp_alloc/49 (read)tcp_connect/36 (read)tcp_connect/36 (write)
  Availability: not_available
  Varpool flags:
tcp_trigger_input_pcb_close/70 (tcp_trigger_input_pcb_close) @062f6e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_close_shutdown/22 (3855 (estimated locally),0.01 per call) 
  Calls: 
tcp_input_pcb/69 (tcp_input_pcb) @062fbdc8
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: tcp_close_shutdown/22 (read)
  Availability: not_available
  Varpool flags:
tcp_rst/68 (tcp_rst) @062f6c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_abandon/26 (54861 (estimated locally),0.14 per call) tcp_close_shutdown/22 (12850 (estimated locally),0.04 per call) tcp_slowtmr/37 (427326 (estimated locally),0.89 per call) 
  Calls: 
memp_free/67 (memp_free) @062f6540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_seg_free/42 (751619278 (estimated locally),0.70 per call) tcp_free.part.0/91 (1073741824 (estimated locally),1.00 per call) tcp_free_listen/16 (102669 (estimated locally),0.49 per call) 
  Calls: 
rand/66 (rand) @062f6380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: tcp_init/14 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
tcp_tcp_get_tcp_addrinfo/65 (tcp_tcp_get_tcp_addrinfo) @062e8ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
tcp_debug_state_str/64 (tcp_debug_state_str) @062e8e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: tcp_state_str/1 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
tcp_netif_ip_addr_changed/63 (tcp_netif_ip_addr_changed) @062e8b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: tcp_active_pcbs/8 (read)tcp_bound_pcbs/6 (read)tcp_listen_pcbs/7 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: tcp_netif_ip_addr_changed_pcblist/62 (248034361 (estimated locally),0.23 per call) tcp_netif_ip_addr_changed_pcblist/62 (248034361 (estimated locally),0.23 per call) 
tcp_netif_ip_addr_changed_pcblist/62 (tcp_netif_ip_addr_changed_pcblist) @062d6ee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:357913 (estimated locally) body local optimize_size
  Called by: tcp_netif_ip_addr_changed/63 (248034361 (estimated locally),0.23 per call) tcp_netif_ip_addr_changed/63 (248034361 (estimated locally),0.23 per call) 
  Calls: tcp_netif_ip_addr_changed_pcblist.part.0/97 (250539 (estimated locally),0.70 per call) 
tcp_eff_send_mss_netif/61 (tcp_eff_send_mss_netif) @062d68c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: tcp_connect/36 (656363041 (estimated locally),0.97 per call) 
  Calls: nd6_get_destination_mtu/90 (50709 (estimated locally),0.14 per call) 
tcp_next_iss/60 (tcp_next_iss) @062d6380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: iss.7855/89 (read)tcp_ticks/3 (read)iss.7855/89 (write)
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: tcp_connect/36 (656363041 (estimated locally),0.97 per call) 
  Calls: 
tcp_pcb_remove/59 (tcp_pcb_remove) @062d60e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: tcp_abandon/26 (54861 (estimated locally),0.14 per call) tcp_abandon/26 (42187 (estimated locally),0.11 per call) tcp_close_shutdown/22 (46762 (estimated locally),0.13 per call) tcp_close_shutdown/22 (46762 (estimated locally),0.13 per call) 
  Calls: tcp_pcb_remove.part.0/94 (175377 (estimated locally),0.49 per call) 
tcp_pcb_purge/58 (tcp_pcb_purge) @062cba80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: tcp_close_shutdown/22 (12850 (estimated locally),0.04 per call) tcp_pcb_remove.part.0/94 (232411 (estimated locally),1.00 per call) tcp_slowtmr/37 (544281 (estimated locally),1.14 per call) tcp_slowtmr/37 (1321353 (estimated locally),2.77 per call) 
  Calls: tcp_pcb_purge.part.0/93 (141867178 (estimated locally),0.13 per call) 
tcp_poll/57 (tcp_poll) @062cb540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:385552 (estimated locally) body optimize_size
  Called by: 
  Calls: 
tcp_accept/56 (tcp_accept) @062cbee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
tcp_err/55 (tcp_err) @062cbc40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:451151 (estimated locally) body optimize_size
  Called by: 
  Calls: 
tcp_sent/54 (tcp_sent) @062cb9a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:451151 (estimated locally) body optimize_size
  Called by: 
  Calls: 
tcp_recv/53 (tcp_recv) @062cb700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:451151 (estimated locally) body optimize_size
  Called by: 
  Calls: 
tcp_arg/52 (tcp_arg) @062cb460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
tcp_new_ip_type/51 (tcp_new_ip_type) @062cb1c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: tcp_alloc/49 (1073741824 (estimated locally),1.00 per call) 
tcp_new/50 (tcp_new) @062c0b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: tcp_alloc/49 (1073741824 (estimated locally),1.00 per call) 
tcp_alloc/49 (tcp_alloc) @062c0d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: lwip_stats/71 (read)lwip_stats/71 (read)lwip_stats/71 (read)lwip_stats/71 (read)tcp_ticks/3 (read)tcp_timer_ctr/13 (read)tcp_recv_null/44 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: tcp_new_ip_type/51 (1073741824 (estimated locally),1.00 per call) tcp_new/50 (1073741824 (estimated locally),1.00 per call) 
  Calls: memset/88 (574129754 (estimated locally),0.53 per call) memp_malloc/78 (991036 (estimated locally),0.00 per call) tcp_kill_prio/45 (991036 (estimated locally),0.00 per call) memp_malloc/78 (5685806 (estimated locally),0.01 per call) tcp_kill_state/46 (5685806 (estimated locally),0.01 per call) memp_malloc/78 (32620803 (estimated locally),0.03 per call) tcp_kill_state/46 (32620803 (estimated locally),0.03 per call) memp_malloc/78 (187153200 (estimated locally),0.17 per call) tcp_kill_timewait/47 (187153200 (estimated locally),0.17 per call) tcp_handle_closepend/48 (187153200 (estimated locally),0.17 per call) memp_malloc/78 (1073741824 (estimated locally),1.00 per call) 
tcp_handle_closepend/48 (tcp_handle_closepend) @062c0a80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: tcp_active_pcbs/8 (read)
  Referring: 
  Availability: local
  Function flags: count:118111602 (estimated locally) body local optimize_size
  Called by: tcp_alloc/49 (187153200 (estimated locally),0.17 per call) 
  Calls: tcp_close_shutdown_fin/23 (315357973 (estimated locally),2.67 per call) 
tcp_kill_timewait/47 (tcp_kill_timewait) @062c07e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: tcp_tw_pcbs/9 (read)tcp_ticks/3 (read)
  Referring: 
  Availability: local
  Function flags: count:118111600 (estimated locally) body local optimize_size
  Called by: tcp_alloc/49 (187153200 (estimated locally),0.17 per call) 
  Calls: tcp_abort/27 (63154273 (estimated locally),0.53 per call) 
tcp_kill_state/46 (tcp_kill_state) @062c0540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:181990 (estimated locally) body local optimize_size
  Called by: tcp_alloc/49 (5685806 (estimated locally),0.01 per call) tcp_alloc/49 (32620803 (estimated locally),0.03 per call) 
  Calls: tcp_kill_state.part.0/98 (74616 (estimated locally),0.41 per call) 
tcp_kill_prio/45 (tcp_kill_prio) @062c02a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: tcp_active_pcbs/8 (read)tcp_ticks/3 (read)tcp_ticks/3 (read)
  Referring: 
  Availability: local
  Function flags: count:147750313 (estimated locally) body local optimize_size
  Called by: tcp_alloc/49 (991036 (estimated locally),0.00 per call) 
  Calls: tcp_abort/27 (63154273 (estimated locally),0.43 per call) 
tcp_recv_null/44 (tcp_recv_null) @062c0000
  Type: function definition analyzed
  Visibility: externally_visible public
  Address is taken.
  References: 
  Referring: tcp_alloc/49 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: tcp_process_refused_data/40 (186311010 (estimated locally),0.17 per call) 
  Calls: tcp_recv_null.part.0/95 (497363818 (estimated locally),0.46 per call) pbuf_free/74 (571546170 (estimated locally),0.53 per call) tcp_recved/34 (571546170 (estimated locally),0.53 per call) 
tcp_setprio/43 (tcp_setprio) @0628fc40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
tcp_seg_free/42 (tcp_seg_free) @0628f700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: tcp_segs_free/41 (955630223 (estimated locally),8.09 per call) 
  Calls: memp_free/67 (751619278 (estimated locally),0.70 per call) pbuf_free/74 (401890828 (estimated locally),0.37 per call) 
tcp_segs_free/41 (tcp_segs_free) @0628fe00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:118111600 (estimated locally) body optimize_size
  Called by: tcp_abandon/26 (88891 (estimated locally),0.23 per call) tcp_abandon/26 (88891 (estimated locally),0.23 per call) tcp_pcb_purge.part.0/93 (1073741824 (estimated locally),1.00 per call) tcp_pcb_purge.part.0/93 (1073741824 (estimated locally),1.00 per call) 
  Calls: tcp_seg_free/42 (955630223 (estimated locally),8.09 per call) 
tcp_process_refused_data/40 (tcp_process_refused_data) @0628fb60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: tcp_fasttmr/38 (358084727 (estimated locally),6.06 per call) 
  Calls: tcp_process_refused_data.part.0/96 (267227497 (estimated locally),0.25 per call) tcp_recv_null/44 (186311010 (estimated locally),0.17 per call) 
   Indirect call(882598975 (estimated locally),0.82 per call)  of param:0 loaded from aggregate passed by reference at offset 1344 (vptr maybe changed)
tcp_txnow/39 (tcp_txnow) @0628f8c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: tcp_active_pcbs/8 (read)
  Referring: 
  Availability: available
  Function flags: count:118111602 (estimated locally) body optimize_size
  Called by: 
  Calls: tcp_output/73 (315357973 (estimated locally),2.67 per call) 
tcp_fasttmr/38 (tcp_fasttmr) @0628f620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: tcp_timer_ctr/13 (read)tcp_timer_ctr/13 (write)tcp_active_pcbs/8 (read)tcp_timer_ctr/13 (read)tcp_active_pcbs_changed/11 (write)tcp_active_pcbs_changed/11 (read)
  Referring: 
  Availability: available
  Function flags: count:59055800 (estimated locally) body optimize_size
  Called by: tcp_tmr/17 (1073741824 (estimated locally),1.00 per call) 
  Calls: tcp_process_refused_data/40 (358084727 (estimated locally),6.06 per call) tcp_close_shutdown_fin/23 (220998616 (estimated locally),3.74 per call) tcp_output/73 (220998616 (estimated locally),3.74 per call) 
tcp_slowtmr/37 (tcp_slowtmr) @0628f380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: tcp_ticks/3 (read)tcp_ticks/3 (write)tcp_timer_ctr/13 (read)tcp_timer_ctr/13 (write)tcp_active_pcbs/8 (read)tcp_timer_ctr/13 (read)tcp_persist_backoff/5 (read)tcp_backoff/4 (read)tcp_ticks/3 (read)tcp_ticks/3 (read)tcp_ticks/3 (read)tcp_ticks/3 (read)tcp_active_pcbs/8 (read)tcp_active_pcbs/8 (read)tcp_active_pcbs/8 (write)tcp_active_pcbs_changed/11 (write)tcp_active_pcbs_changed/11 (read)tcp_active_pcbs_changed/11 (write)tcp_active_pcbs_changed/11 (read)tcp_tw_pcbs/9 (read)tcp_ticks/3 (read)tcp_tw_pcbs/9 (read)tcp_tw_pcbs/9 (read)tcp_tw_pcbs/9 (write)
  Referring: 
  Availability: available
  Function flags: count:477869 (estimated locally) body optimize_size
  Called by: tcp_tmr/17 (354334802 (estimated locally),0.33 per call) 
  Calls: tcp_free/15 (529314 (estimated locally),1.11 per call) tcp_pcb_purge/58 (544281 (estimated locally),1.14 per call) tcp_output/73 (433800 (estimated locally),0.91 per call) tcp_free/15 (1294926 (estimated locally),2.71 per call) tcp_rst/68 (427326 (estimated locally),0.89 per call) tcp_pcb_purge/58 (1321353 (estimated locally),2.77 per call) tcp_keepalive/87 (186443 (estimated locally),0.39 per call) tcp_rexmit_rto_commit/86 (131862 (estimated locally),0.28 per call) tcp_rexmit_rto_prepare/85 (217954 (estimated locally),0.46 per call) tcp_output/73 (21456 (estimated locally),0.04 per call) tcp_split_unsent_seg/84 (65017 (estimated locally),0.14 per call) tcp_zero_window_probe/83 (65017 (estimated locally),0.14 per call) 
   Indirect call(938962 (estimated locally),1.96 per call) 
   Indirect call(906448 (estimated locally),1.90 per call) 
tcp_connect/36 (tcp_connect) @062509a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: tcp_bound_pcbs/6 (read)tcp_bound_pcbs/6 (write)tcp_active_pcbs/8 (read)tcp_active_pcbs/8 (write)tcp_active_pcbs_changed/11 (write)lwip_stats/71 (read)lwip_stats/71 (write)
  Referring: 
  Availability: available
  Function flags: count:677334388 (estimated locally) body optimize_size
  Called by: 
  Calls: tcp_output/73 (328181520 (estimated locally),0.48 per call) tcp_timer_needed/77 (328181520 (estimated locally),0.48 per call) tcp_enqueue_flags/82 (656363041 (estimated locally),0.97 per call) tcp_eff_send_mss_netif/61 (656363041 (estimated locally),0.97 per call) tcp_next_iss/60 (656363041 (estimated locally),0.97 per call) tcp_new_port/35 (329896985 (estimated locally),0.49 per call) ip6_select_source_address/81 (66921724 (estimated locally),0.10 per call) ip4_route/80 (293740668 (estimated locally),0.43 per call) ip6_route/76 (151320950 (estimated locally),0.22 per call) netif_get_by_index/79 (219209454 (estimated locally),0.32 per call) 
tcp_new_port/35 (tcp_new_port) @06239620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: tcp_port/2 (read)tcp_port/2 (write)tcp_port/2 (write)tcp_pcb_lists/10 (read)tcp_port/2 (read)tcp_port/2 (read)
  Referring: 
  Availability: local
  Function flags: count:29273961 (estimated locally) body local optimize_size
  Called by: tcp_connect/36 (329896985 (estimated locally),0.49 per call) tcp_bind/28 (7527826 (estimated locally),0.33 per call) 
  Calls: 
tcp_recved/34 (tcp_recved) @06239380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:385552 (estimated locally) body optimize_size
  Called by: tcp_recv_null/44 (571546170 (estimated locally),0.53 per call) 
  Calls: tcp_recved.part.0/92 (68783 (estimated locally),0.18 per call) tcp_update_rcv_ann_wnd/33 (208432 (estimated locally),0.54 per call) 
tcp_update_rcv_ann_wnd/33 (tcp_update_rcv_ann_wnd) @062390e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: tcp_recved/34 (208432 (estimated locally),0.54 per call) 
  Calls: 
tcp_listen_with_backlog_and_err/32 (tcp_listen_with_backlog_and_err) @06208380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: tcp_bound_pcbs/6 (read)tcp_bound_pcbs/6 (write)tcp_accept_null/30 (addr)tcp_listen_pcbs/7 (read)tcp_listen_pcbs/7 (write)
  Referring: 
  Availability: available
  Function flags: count:228328 (estimated locally) body optimize_size
  Called by: tcp_listen_with_backlog/31 (1073741824 (estimated locally),1.00 per call) 
  Calls: tcp_timer_needed/77 (27247 (estimated locally),0.12 per call) tcp_free/15 (134621 (estimated locally),0.59 per call) memp_malloc/78 (146758 (estimated locally),0.64 per call) 
tcp_listen_with_backlog/31 (tcp_listen_with_backlog) @06208540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: tcp_listen_with_backlog_and_err/32 (1073741824 (estimated locally),1.00 per call) 
tcp_accept_null/30 (tcp_accept_null) @062082a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: tcp_listen_with_backlog_and_err/32 (addr)
  Availability: available
  Function flags: count:230763 (estimated locally) body optimize_size
  Called by: 
  Calls: tcp_abort/27 (123389 (estimated locally),0.53 per call) 
tcp_bind_netif/29 (tcp_bind_netif) @06208000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
tcp_bind/28 (tcp_bind) @061e2e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ip_addr_any/75 (addr)tcp_pcb_lists/10 (read)tcp_bound_pcbs/6 (read)tcp_bound_pcbs/6 (write)
  Referring: 
  Availability: available
  Function flags: count:23155528 (estimated locally) body optimize_size
  Called by: 
  Calls: tcp_timer_needed/77 (14801258 (estimated locally),0.64 per call) tcp_new_port/35 (7527826 (estimated locally),0.33 per call) ip6_route/76 (549431 (estimated locally),0.02 per call) 
tcp_abort/27 (tcp_abort) @061ad380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: tcp_netif_ip_addr_changed_pcblist.part.0/97 (107221711 (estimated locally),0.91 per call) tcp_kill_prio/45 (63154273 (estimated locally),0.43 per call) tcp_kill_timewait/47 (63154273 (estimated locally),0.53 per call) tcp_accept_null/30 (123389 (estimated locally),0.53 per call) 
  Calls: tcp_abandon/26 (1073741824 (estimated locally),1.00 per call) 
tcp_abandon/26 (tcp_abandon) @061ad0e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: tcp_tw_pcbs/9 (addr)tcp_bound_pcbs/6 (read)tcp_bound_pcbs/6 (write)tcp_active_pcbs/8 (addr)tcp_active_pcbs_changed/11 (write)
  Referring: 
  Availability: available
  Function flags: count:385552 (estimated locally) body optimize_size
  Called by: tcp_kill_state.part.0/98 (63154273 (estimated locally),0.53 per call) tcp_abort/27 (1073741824 (estimated locally),1.00 per call) 
  Calls: tcp_free/15 (166245 (estimated locally),0.43 per call) tcp_rst/68 (54861 (estimated locally),0.14 per call) tcp_backlog_accepted/21 (166245 (estimated locally),0.43 per call) tcp_segs_free/41 (88891 (estimated locally),0.23 per call) tcp_segs_free/41 (88891 (estimated locally),0.23 per call) tcp_pcb_remove/59 (54861 (estimated locally),0.14 per call) tcp_free/15 (42187 (estimated locally),0.11 per call) tcp_pcb_remove/59 (42187 (estimated locally),0.11 per call) 
   Indirect call(116372 (estimated locally),0.30 per call)  of param:0 loaded from aggregate passed by reference at offset 1440 (vptr maybe changed)
tcp_shutdown/25 (tcp_shutdown) @06193b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: tcp_close_shutdown/22 (458758748 (estimated locally),0.43 per call) pbuf_free/74 (226701775 (estimated locally),0.21 per call) tcp_close_shutdown/22 (107589552 (estimated locally),0.10 per call) 
tcp_close/24 (tcp_close) @061931c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: tcp_recv_null.part.0/95 (217325345 (estimated locally),0.20 per call) 
  Calls: tcp_close_shutdown/22 (1068909987 (estimated locally),1.00 per call) 
tcp_close_shutdown_fin/23 (tcp_close_shutdown_fin) @06193d20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: lwip_stats/71 (read)lwip_stats/71 (write)lwip_stats/71 (read)lwip_stats/71 (write)lwip_stats/71 (read)lwip_stats/71 (write)
  Referring: 
  Availability: local
  Function flags: count:357913 (estimated locally) body local optimize_size
  Called by: tcp_fasttmr/38 (220998616 (estimated locally),3.74 per call) tcp_close_shutdown/22 (46762 (estimated locally),0.13 per call) tcp_handle_closepend/48 (315357973 (estimated locally),2.67 per call) 
  Calls: tcp_output/73 (62008 (estimated locally),0.17 per call) tcp_send_fin/72 (62635 (estimated locally),0.18 per call) tcp_send_fin/72 (62635 (estimated locally),0.18 per call) tcp_backlog_accepted/21 (20669 (estimated locally),0.06 per call) tcp_send_fin/72 (62635 (estimated locally),0.18 per call) 
tcp_close_shutdown/22 (tcp_close_shutdown) @06193a80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: tcp_active_pcbs/8 (read)tcp_active_pcbs/8 (write)tcp_active_pcbs_changed/11 (write)tcp_input_pcb/69 (read)tcp_bound_pcbs/6 (read)tcp_bound_pcbs/6 (write)tcp_listen_pcbs/7 (addr)tcp_active_pcbs/8 (addr)tcp_active_pcbs_changed/11 (write)lwip_stats/71 (read)lwip_stats/71 (write)
  Referring: 
  Availability: local
  Function flags: count:357913 (estimated locally) body local optimize_size
  Called by: tcp_shutdown/25 (458758748 (estimated locally),0.43 per call) tcp_shutdown/25 (107589552 (estimated locally),0.10 per call) tcp_close/24 (1068909987 (estimated locally),1.00 per call) 
  Calls: tcp_close_shutdown_fin/23 (46762 (estimated locally),0.13 per call) tcp_free/15 (46762 (estimated locally),0.13 per call) tcp_pcb_remove/59 (46762 (estimated locally),0.13 per call) tcp_free_listen/16 (46762 (estimated locally),0.13 per call) tcp_pcb_remove/59 (46762 (estimated locally),0.13 per call) tcp_listen_closed/19 (46762 (estimated locally),0.13 per call) tcp_free/15 (46762 (estimated locally),0.13 per call) tcp_free/15 (8995 (estimated locally),0.03 per call) tcp_trigger_input_pcb_close/70 (3855 (estimated locally),0.01 per call) tcp_pcb_purge/58 (12850 (estimated locally),0.04 per call) tcp_rst/68 (12850 (estimated locally),0.04 per call) 
tcp_backlog_accepted/21 (tcp_backlog_accepted) @06193620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: tcp_abandon/26 (166245 (estimated locally),0.43 per call) tcp_pcb_purge.part.0/93 (1073741824 (estimated locally),1.00 per call) tcp_close_shutdown_fin/23 (20669 (estimated locally),0.06 per call) 
  Calls: 
tcp_backlog_delayed/20 (tcp_backlog_delayed) @06193380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: 
tcp_listen_closed/19 (tcp_listen_closed) @061930e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: tcp_pcb_lists/10 (read)
  Referring: 
  Availability: local
  Function flags: count:232411 (estimated locally) body local optimize_size
  Called by: tcp_close_shutdown/22 (46762 (estimated locally),0.13 per call) 
  Calls: tcp_remove_listener/18 (165942 (estimated locally),0.71 per call) 
tcp_remove_listener/18 (tcp_remove_listener) @0618a380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:357913 (estimated locally) body local optimize_size
  Called by: tcp_listen_closed/19 (165942 (estimated locally),0.71 per call) 
  Calls: 
tcp_tmr/17 (tcp_tmr) @0618ad20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: tcp_timer/12 (read)tcp_timer/12 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: tcp_slowtmr/37 (354334802 (estimated locally),0.33 per call) tcp_fasttmr/38 (1073741824 (estimated locally),1.00 per call) 
tcp_free_listen/16 (tcp_free_listen) @0618aa80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:210043 (estimated locally) body local optimize_size
  Called by: tcp_close_shutdown/22 (46762 (estimated locally),0.13 per call) 
  Calls: memp_free/67 (102669 (estimated locally),0.49 per call) 
tcp_free/15 (tcp_free) @0618a7e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:210043 (estimated locally) body optimize_size
  Called by: tcp_abandon/26 (166245 (estimated locally),0.43 per call) tcp_abandon/26 (42187 (estimated locally),0.11 per call) tcp_close_shutdown/22 (46762 (estimated locally),0.13 per call) tcp_close_shutdown/22 (46762 (estimated locally),0.13 per call) tcp_close_shutdown/22 (8995 (estimated locally),0.03 per call) tcp_slowtmr/37 (529314 (estimated locally),1.11 per call) tcp_slowtmr/37 (1294926 (estimated locally),2.71 per call) tcp_listen_with_backlog_and_err/32 (134621 (estimated locally),0.59 per call) 
  Calls: tcp_free.part.0/91 (102669 (estimated locally),0.49 per call) 
tcp_init/14 (tcp_init) @0618a540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: tcp_port/2 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: rand/66 (1073741824 (estimated locally),1.00 per call) 
tcp_timer_ctr/13 (tcp_timer_ctr) @06173f78
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: tcp_slowtmr/37 (read)tcp_slowtmr/37 (write)tcp_fasttmr/38 (read)tcp_slowtmr/37 (read)tcp_fasttmr/38 (read)tcp_fasttmr/38 (write)tcp_alloc/49 (read)
  Availability: available
  Varpool flags:
tcp_timer/12 (tcp_timer) @06173ee8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: tcp_tmr/17 (read)tcp_tmr/17 (write)
  Availability: available
  Varpool flags:
tcp_active_pcbs_changed/11 (tcp_active_pcbs_changed) @06173e58
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: tcp_close_shutdown/22 (write)tcp_abandon/26 (write)tcp_close_shutdown/22 (write)tcp_fasttmr/38 (read)tcp_slowtmr/37 (write)tcp_slowtmr/37 (read)tcp_slowtmr/37 (write)tcp_slowtmr/37 (read)tcp_fasttmr/38 (write)tcp_connect/36 (write)
  Availability: available
  Varpool flags:
tcp_pcb_lists/10 (tcp_pcb_lists) @06173e10
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: tcp_listen_pcbs/7 (addr)tcp_bound_pcbs/6 (addr)tcp_active_pcbs/8 (addr)tcp_tw_pcbs/9 (addr)
  Referring: tcp_new_port/35 (read)tcp_listen_closed/19 (read)tcp_bind/28 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
tcp_tw_pcbs/9 (tcp_tw_pcbs) @06173dc8
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: tcp_pcb_lists/10 (addr)tcp_abandon/26 (addr)tcp_slowtmr/37 (write)tcp_slowtmr/37 (read)tcp_slowtmr/37 (read)tcp_slowtmr/37 (read)tcp_kill_timewait/47 (read)
  Availability: available
  Varpool flags:
tcp_active_pcbs/8 (tcp_active_pcbs) @06173d80
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: tcp_pcb_lists/10 (addr)tcp_connect/36 (write)tcp_slowtmr/37 (read)tcp_slowtmr/37 (read)tcp_close_shutdown/22 (write)tcp_txnow/39 (read)tcp_close_shutdown/22 (addr)tcp_slowtmr/37 (read)tcp_kill_prio/45 (read)tcp_kill_state.part.0/98 (read)tcp_abandon/26 (addr)tcp_fasttmr/38 (read)tcp_handle_closepend/48 (read)tcp_slowtmr/37 (write)tcp_close_shutdown/22 (read)tcp_connect/36 (read)tcp_netif_ip_addr_changed/63 (read)
  Availability: available
  Varpool flags:
tcp_listen_pcbs/7 (tcp_listen_pcbs) @06173d38
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: tcp_pcb_lists/10 (addr)tcp_close_shutdown/22 (addr)tcp_listen_with_backlog_and_err/32 (write)tcp_listen_with_backlog_and_err/32 (read)tcp_netif_ip_addr_changed/63 (read)
  Availability: available
  Varpool flags:
tcp_bound_pcbs/6 (tcp_bound_pcbs) @06173cf0
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: tcp_pcb_lists/10 (addr)tcp_abandon/26 (write)tcp_abandon/26 (read)tcp_bind/28 (read)tcp_bind/28 (write)tcp_connect/36 (write)tcp_close_shutdown/22 (read)tcp_listen_with_backlog_and_err/32 (read)tcp_listen_with_backlog_and_err/32 (write)tcp_close_shutdown/22 (write)tcp_connect/36 (read)tcp_netif_ip_addr_changed/63 (read)
  Availability: available
  Varpool flags:
tcp_persist_backoff/5 (tcp_persist_backoff) @06173ca8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: tcp_slowtmr/37 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
tcp_backoff/4 (tcp_backoff) @06173bd0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: tcp_slowtmr/37 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
tcp_ticks/3 (tcp_ticks) @06173af8
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: tcp_kill_prio/45 (read)tcp_kill_prio/45 (read)tcp_alloc/49 (read)tcp_slowtmr/37 (read)tcp_kill_timewait/47 (read)tcp_slowtmr/37 (read)tcp_slowtmr/37 (read)tcp_kill_state.part.0/98 (read)tcp_slowtmr/37 (read)tcp_slowtmr/37 (write)tcp_slowtmr/37 (read)tcp_slowtmr/37 (read)tcp_next_iss/60 (read)
  Availability: available
  Varpool flags:
tcp_port/2 (tcp_port) @06173ab0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: tcp_new_port/35 (read)tcp_new_port/35 (read)tcp_new_port/35 (write)tcp_new_port/35 (write)tcp_new_port/35 (read)tcp_init/14 (write)
  Availability: available
  Varpool flags: initialized
tcp_state_str/1 (tcp_state_str) @06173a20
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: tcp_debug_state_str/64 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known

;; Function tcp_new_port (tcp_new_port, funcdef_no=22, decl_uid=7491, cgraph_uid=23, symbol_order=35)

Modification phase of node tcp_new_port/35
tcp_new_port ()
{
  struct tcp_pcb * pcb;
  u16_t n;
  u8_t i;
  short unsigned int tcp_port.25_1;
  short unsigned int _2;
  int _3;
  struct tcp_pcb * * _4;
  short unsigned int _5;
  short unsigned int tcp_port.28_6;
  u16_t _10;
  u16_t _16;

  <bb 2> [local count: 29273961]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG n => 0

  <bb 3> [local count: 84523615]:
  # n_8 = PHI <0(2), n_20(9)>
again:
  # DEBUG n => n_8
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tcp_port.25_1 = tcp_port;
  _2 = tcp_port.25_1 + 1;
  tcp_port = _2;
  # DEBUG BEGIN_STMT
  if (_2 == 65535)
    goto <bb 4>; [34.00%]
  else
    goto <bb 5>; [66.00%]

  <bb 4> [local count: 28738029]:
  # DEBUG BEGIN_STMT
  tcp_port = 49152;

  <bb 5> [local count: 84523615]:
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  goto <bb 13>; [100.00%]

  <bb 6> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  _3 = (int) i_7;
  _4 = tcp_pcb_lists[_3];
  pcb_17 = *_4;
  # DEBUG pcb => pcb_17
  goto <bb 11>; [100.00%]

  <bb 7> [local count: 1014686024]:
  # DEBUG BEGIN_STMT
  _5 = pcb_9->local_port;
  tcp_port.28_6 = tcp_port;
  if (_5 == tcp_port.28_6)
    goto <bb 8>; [5.50%]
  else
    goto <bb 10>; [94.50%]

  <bb 8> [local count: 55807731]:
  # DEBUG BEGIN_STMT
  n_20 = n_8 + 1;
  # DEBUG n => n_20
  # DEBUG BEGIN_STMT
  if (n_20 == 16384)
    goto <bb 15>; [1.00%]
  else
    goto <bb 9>; [99.00%]

  <bb 9> [local count: 55249654]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 3>; [100.00%]

  <bb 10> [local count: 958878293]:
  # DEBUG BEGIN_STMT
  pcb_19 = pcb_9->next;
  # DEBUG pcb => pcb_19

  <bb 11> [local count: 1073741824]:
  # pcb_9 = PHI <pcb_17(6), pcb_19(10)>
  # DEBUG pcb => pcb_9
  # DEBUG BEGIN_STMT
  if (pcb_9 != 0B)
    goto <bb 7>; [94.50%]
  else
    goto <bb 12>; [5.50%]

  <bb 12> [local count: 59055800]:
  # DEBUG BEGIN_STMT
  i_18 = i_7 + 1;
  # DEBUG i => i_18

  <bb 13> [local count: 143579415]:
  # i_7 = PHI <0(5), i_18(12)>
  # DEBUG i => i_7
  # DEBUG BEGIN_STMT
  if (i_7 != 4)
    goto <bb 6>; [80.00%]
  else
    goto <bb 14>; [20.00%]

  <bb 14> [local count: 28715883]:
  # DEBUG BEGIN_STMT
  _16 = tcp_port;

  <bb 15> [local count: 29273960]:
  # _10 = PHI <0(8), _16(14)>
  return _10;

}



;; Function tcp_init (tcp_init, funcdef_no=1, decl_uid=7258, cgraph_uid=2, symbol_order=14)

Modification phase of node tcp_init/14
tcp_init ()
{
  int _1;
  short unsigned int _2;
  short unsigned int _3;
  short unsigned int _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = rand ();
  _2 = (short unsigned int) _1;
  _3 = _2 & 16383;
  _4 = _3 + 49152;
  tcp_port = _4;
  return;

}



;; Function tcp_free (tcp_free, funcdef_no=2, decl_uid=7273, cgraph_uid=3, symbol_order=15)

Modification phase of node tcp_free/15
tcp_free (struct tcp_pcb * pcb)
{
  tcp_state _1;

  <bb 2> [local count: 210043]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pcb_4(D)->state;
  if (_1 == 1)
    goto <bb 5>; [51.12%]
  else
    goto <bb 4>; [48.88%]

  <bb 5> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 102669]:
  tcp_free.part.0 (pcb_4(D));
  return;

}



;; Function tcp_backlog_delayed (tcp_backlog_delayed, funcdef_no=7, decl_uid=7200, cgraph_uid=8, symbol_order=20)

Modification phase of node tcp_backlog_delayed/20
tcp_backlog_delayed (struct tcp_pcb * pcb)
{
  short unsigned int _1;
  struct tcp_pcb_listen * _2;
  unsigned char _3;
  short unsigned int _4;
  unsigned char _5;
  short unsigned int _6;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_10(D) == 0B)
    goto <bb 10>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 10> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 12> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pcb_10(D)->flags;
  _4 = _1 & 512;
  if (_4 == 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 5> [local count: 125270]:
  # DEBUG BEGIN_STMT
  _2 = pcb_10(D)->listener;
  if (_2 != 0B)
    goto <bb 6>; [70.00%]
  else
    goto <bb 9>; [30.00%]

  <bb 6> [local count: 87689]:
  # DEBUG BEGIN_STMT
  _3 = _2->accepts_pending;
  _5 = _3 + 1;
  _2->accepts_pending = _5;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (_5 == 0)
    goto <bb 11>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 11> [local count: 43844]:

  <bb 7> [local count: 438444579]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 13> [local count: 438444579]:
  goto <bb 7>; [100.00%]

  <bb 8> [local count: 43844]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _6 = _1 | 512;
  pcb_10(D)->flags = _6;

  <bb 9> [local count: 206695]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function tcp_backlog_accepted (tcp_backlog_accepted, funcdef_no=8, decl_uid=7202, cgraph_uid=9, symbol_order=21)

Modification phase of node tcp_backlog_accepted/21
tcp_backlog_accepted (struct tcp_pcb * pcb)
{
  short unsigned int _1;
  struct tcp_pcb_listen * _2;
  unsigned char _3;
  short unsigned int _4;
  unsigned char _5;
  short unsigned int _6;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_10(D) == 0B)
    goto <bb 10>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 10> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 12> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pcb_10(D)->flags;
  _4 = _1 & 512;
  if (_4 != 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 5> [local count: 125270]:
  # DEBUG BEGIN_STMT
  _2 = pcb_10(D)->listener;
  if (_2 != 0B)
    goto <bb 6>; [70.00%]
  else
    goto <bb 9>; [30.00%]

  <bb 6> [local count: 87689]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = _2->accepts_pending;
  if (_3 == 0)
    goto <bb 11>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 11> [local count: 43844]:

  <bb 7> [local count: 438444579]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 13> [local count: 438444579]:
  goto <bb 7>; [100.00%]

  <bb 8> [local count: 43844]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _5 = _3 + 255;
  _2->accepts_pending = _5;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _6 = _1 & 65023;
  pcb_10(D)->flags = _6;

  <bb 9> [local count: 206695]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function tcp_close_shutdown_fin (tcp_close_shutdown_fin, funcdef_no=10, decl_uid=7493, cgraph_uid=11, symbol_order=23)

Modification phase of node tcp_close_shutdown_fin/23
tcp_close_shutdown_fin (struct tcp_pcb * pcb)
{
  err_t err;
  tcp_state _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  short unsigned int _8;
  short unsigned int _9;
  err_t _11;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_15(D) == 0B)
    goto <bb 16>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 16> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 17> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pcb_15(D)->state;
  switch (_1) <default: <L20> [25.00%], case 3: <L3> [25.00%], case 4: <L6> [25.00%], case 7: <L9> [25.00%]>

  <bb 5> [local count: 62635]:
<L3>:
  # DEBUG BEGIN_STMT
  err_26 = tcp_send_fin (pcb_15(D));
  # DEBUG err => err_26
  # DEBUG BEGIN_STMT
  if (err_26 == 0)
    goto <bb 6>; [33.00%]
  else
    goto <bb 11>; [67.00%]

  <bb 6> [local count: 20669]:
  # DEBUG BEGIN_STMT
  tcp_backlog_accepted (pcb_15(D));
  # DEBUG BEGIN_STMT
  _2 = lwip_stats.mib2.tcpattemptfails;
  _3 = _2 + 1;
  lwip_stats.mib2.tcpattemptfails = _3;
  # DEBUG BEGIN_STMT
  pcb_15(D)->state = 5;
  goto <bb 11>; [100.00%]

  <bb 7> [local count: 62635]:
<L6>:
  # DEBUG BEGIN_STMT
  err_22 = tcp_send_fin (pcb_15(D));
  # DEBUG err => err_22
  # DEBUG BEGIN_STMT
  if (err_22 == 0)
    goto <bb 8>; [50.00%]
  else
    goto <bb 11>; [50.00%]

  <bb 8> [local count: 31317]:
  # DEBUG BEGIN_STMT
  _4 = lwip_stats.mib2.tcpestabresets;
  _5 = _4 + 1;
  lwip_stats.mib2.tcpestabresets = _5;
  # DEBUG BEGIN_STMT
  pcb_15(D)->state = 5;
  goto <bb 11>; [100.00%]

  <bb 9> [local count: 62635]:
<L9>:
  # DEBUG BEGIN_STMT
  err_18 = tcp_send_fin (pcb_15(D));
  # DEBUG err => err_18
  # DEBUG BEGIN_STMT
  if (err_18 == 0)
    goto <bb 10>; [50.00%]
  else
    goto <bb 11>; [50.00%]

  <bb 10> [local count: 31317]:
  # DEBUG BEGIN_STMT
  _6 = lwip_stats.mib2.tcpestabresets;
  _7 = _6 + 1;
  lwip_stats.mib2.tcpestabresets = _7;
  # DEBUG BEGIN_STMT
  pcb_15(D)->state = 9;

  <bb 11> [local count: 187905]:
  # err_10 = PHI <0(6), 0(8), 0(10), err_26(5), err_22(7), err_18(9)>
  # DEBUG err => err_10
  # DEBUG BEGIN_STMT
  if (err_10 == 0)
    goto <bb 12>; [33.00%]
  else
    goto <bb 13>; [67.00%]

  <bb 12> [local count: 62008]:
  # DEBUG BEGIN_STMT
  tcp_output (pcb_15(D));
  goto <bb 15>; [100.00%]

  <bb 13> [local count: 125896]:
  # DEBUG BEGIN_STMT
  if (err_10 == -1)
    goto <bb 14>; [20.97%]
  else
    goto <bb 15>; [79.03%]

  <bb 14> [local count: 26400]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _8 = pcb_15(D)->flags;
  _9 = _8 | 8;
  pcb_15(D)->flags = _9;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 15> [local count: 250539]:
  # _11 = PHI <0(4), 0(14), err_10(13), err_10(12)>
<L20>:
  return _11;

}



;; Function tcp_bind (tcp_bind, funcdef_no=15, decl_uid=7209, cgraph_uid=16, symbol_order=28)

Modification phase of node tcp_bind/28
tcp_bind (struct tcp_pcb * pcb, const struct ip_addr_t * ipaddr, u16_t port)
{
  struct netif * selected_netif;
  struct ip_addr_t zoned_ipaddr;
  struct tcp_pcb * cpcb;
  int i;
  tcp_state _1;
  unsigned char _2;
  unsigned char _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  unsigned char _12;
  struct tcp_pcb * * _13;
  short unsigned int _14;
  unsigned char _15;
  _Bool _16;
  unsigned char _17;
  _Bool _18;
  long unsigned int _19;
  long unsigned int _20;
  long unsigned int _21;
  long unsigned int _22;
  _Bool _23;
  long unsigned int _24;
  _Bool _25;
  unsigned char _26;
  long unsigned int _27;
  long unsigned int _28;
  long unsigned int _29;
  long unsigned int _30;
  _Bool _31;
  long unsigned int _32;
  _Bool _33;
  unsigned char _34;
  long unsigned int _35;
  long unsigned int _36;
  long unsigned int _37;
  long unsigned int _38;
  long unsigned int _39;
  long unsigned int _40;
  long unsigned int _41;
  long unsigned int _42;
  unsigned char _43;
  unsigned char _44;
  _Bool _45;
  long unsigned int _46;
  long unsigned int _47;
  unsigned char _48;
  long unsigned int _49;
  long unsigned int _50;
  long unsigned int _51;
  long unsigned int _52;
  _Bool _53;
  long unsigned int _54;
  _Bool _55;
  unsigned char _56;
  unsigned char _57;
  unsigned char _58;
  unsigned char _59;
  const struct ip4_addr_t * _60;
  struct tcp_pcb * tcp_bound_pcbs.24_61;
  err_t _67;
  u8_t iftmp.9_68;
  int iftmp.10_69;
  int iftmp.11_70;
  int iftmp.12_71;
  int iftmp.13_72;
  int iftmp.14_73;
  int iftmp.15_74;
  int iftmp.16_75;
  int iftmp.17_76;
  const long unsigned int iftmp.23_77;
  u8_t iftmp.9_93;
  const long unsigned int iftmp.18_102;
  const long unsigned int iftmp.19_104;
  const long unsigned int iftmp.20_106;
  const long unsigned int iftmp.21_108;
  u8_t iftmp.22_110;
  const long unsigned int iftmp.23_112;

  <bb 2> [local count: 23155528]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG max_pcb_list => 4
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (ipaddr_82(D) == 0B)
    goto <bb 3>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 3> [local count: 6946659]:
  # DEBUG BEGIN_STMT
  # DEBUG ipaddr => &ip_addr_any

  <bb 4> [local count: 23155528]:
  # ipaddr_62 = PHI <ipaddr_82(D)(2), &ip_addr_any(3)>
  # DEBUG ipaddr => ipaddr_62
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_83(D) == 0B)
    goto <bb 78>; [0.45%]
  else
    goto <bb 5>; [99.55%]

  <bb 5> [local count: 23051329]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pcb_83(D)->state;
  if (_1 != 0)
    goto <bb 78>; [1.04%]
  else
    goto <bb 6>; [98.96%]

  <bb 6> [local count: 22811595]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (ipaddr_62 != 0B)
    goto <bb 7>; [70.00%]
  else
    goto <bb 16>; [30.00%]

  <bb 7> [local count: 15968116]:
  _2 = ipaddr_62->type;
  if (_2 == 6)
    goto <bb 8>; [34.00%]
  else
    goto <bb 16>; [66.00%]

  <bb 8> [local count: 5429160]:
  _3 = ipaddr_62->u_addr.ip6.zone;
  if (_3 == 0)
    goto <bb 9>; [50.00%]
  else
    goto <bb 16>; [50.00%]

  <bb 9> [local count: 2714580]:
  _4 = ipaddr_62->u_addr.ip6.addr[0];
  _5 = _4 & 49407;
  if (_5 == 33022)
    goto <bb 10>; [20.24%]
  else
    goto <bb 16>; [79.76%]

  <bb 10> [local count: 549431]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  zoned_ipaddr.type = 6;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  zoned_ipaddr.u_addr.ip6.addr[0] = _4;
  # DEBUG BEGIN_STMT
  _6 = ipaddr_62->u_addr.ip6.addr[1];
  zoned_ipaddr.u_addr.ip6.addr[1] = _6;
  # DEBUG BEGIN_STMT
  _7 = ipaddr_62->u_addr.ip6.addr[2];
  zoned_ipaddr.u_addr.ip6.addr[2] = _7;
  # DEBUG BEGIN_STMT
  _8 = ipaddr_62->u_addr.ip6.addr[3];
  zoned_ipaddr.u_addr.ip6.addr[3] = _8;
  # DEBUG BEGIN_STMT
  zoned_ipaddr.u_addr.ip6.zone = 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  selected_netif_92 = ip6_route (&zoned_ipaddr.u_addr.ip6, &zoned_ipaddr.u_addr.ip6);
  # DEBUG selected_netif => selected_netif_92
  # DEBUG BEGIN_STMT
  if (selected_netif_92 != 0B)
    goto <bb 11>; [70.00%]
  else
    goto <bb 16>; [30.00%]

  <bb 11> [local count: 384602]:
  # DEBUG BEGIN_STMT
  _9 = zoned_ipaddr.u_addr.ip6.addr[0];
  _10 = _9 & 49407;
  if (_10 == 33022)
    goto <bb 14>; [34.00%]
  else
    goto <bb 12>; [66.00%]

  <bb 12> [local count: 253837]:
  _11 = _9 & 36863;
  if (_11 == 511)
    goto <bb 14>; [34.00%]
  else
    goto <bb 13>; [66.00%]

  <bb 13> [local count: 167532]:
  if (_11 == 767)
    goto <bb 14>; [34.00%]
  else
    goto <bb 15>; [66.00%]

  <bb 14> [local count: 274030]:
  _12 = selected_netif_92->num;
  iftmp.9_93 = _12 + 1;

  <bb 15> [local count: 384602]:
  # iftmp.9_68 = PHI <iftmp.9_93(14), 0(13)>
  zoned_ipaddr.u_addr.ip6.zone = iftmp.9_68;

  <bb 16> [local count: 22811595]:
  # ipaddr_63 = PHI <ipaddr_62(6), ipaddr_62(7), ipaddr_62(8), ipaddr_62(9), &zoned_ipaddr(15), &zoned_ipaddr(10)>
  # DEBUG ipaddr => ipaddr_63
  # DEBUG BEGIN_STMT
  if (port_95(D) == 0)
    goto <bb 17>; [33.00%]
  else
    goto <bb 79>; [67.00%]

  <bb 79> [local count: 15283769]:
  goto <bb 58>; [100.00%]

  <bb 17> [local count: 7527826]:
  # DEBUG BEGIN_STMT
  port_100 = tcp_new_port ();
  # DEBUG port => port_100
  # DEBUG BEGIN_STMT
  if (port_100 == 0)
    goto <bb 78>; [1.04%]
  else
    goto <bb 59>; [98.96%]

  <bb 18> [local count: 29406884]:
  # DEBUG BEGIN_STMT
  _13 = tcp_pcb_lists[i_65];
  cpcb_96 = *_13;
  # DEBUG cpcb => cpcb_96
  goto <bb 56>; [100.00%]

  <bb 19> [local count: 1052266987]:
  # DEBUG BEGIN_STMT
  _14 = cpcb_66->local_port;
  if (_14 == port_95(D))
    goto <bb 20>; [34.00%]
  else
    goto <bb 55>; [66.00%]

  <bb 20> [local count: 357770776]:
  # DEBUG BEGIN_STMT
  if (ipaddr_63 != 0B)
    goto <bb 21>; [70.00%]
  else
    goto <bb 22>; [30.00%]

  <bb 21> [local count: 250439543]:
  _15 = ipaddr_63->type;
  if (_15 == 6)
    goto <bb 23>; [34.00%]
  else
    goto <bb 22>; [66.00%]

  <bb 22> [local count: 272621331]:

  <bb 23> [local count: 357770775]:
  # iftmp.10_69 = PHI <1(21), 0(22)>
  _16 = (_Bool) iftmp.10_69;
  _17 = cpcb_66->local_ip.type;
  _18 = _17 == 6;
  if (_16 != _18)
    goto <bb 55>; [66.00%]
  else
    goto <bb 24>; [34.00%]

  <bb 24> [local count: 121642064]:
  if (_17 == 6)
    goto <bb 25>; [34.00%]
  else
    goto <bb 31>; [66.00%]

  <bb 25> [local count: 41358302]:
  _19 = cpcb_66->local_ip.u_addr.ip6.addr[0];
  if (_19 == 0)
    goto <bb 26>; [50.00%]
  else
    goto <bb 29>; [50.00%]

  <bb 26> [local count: 20679151]:
  _20 = cpcb_66->local_ip.u_addr.ip6.addr[1];
  if (_20 == 0)
    goto <bb 27>; [50.00%]
  else
    goto <bb 29>; [50.00%]

  <bb 27> [local count: 10339575]:
  _21 = cpcb_66->local_ip.u_addr.ip6.addr[2];
  if (_21 == 0)
    goto <bb 28>; [50.00%]
  else
    goto <bb 29>; [50.00%]

  <bb 28> [local count: 5169788]:
  _22 = cpcb_66->local_ip.u_addr.ip6.addr[3];
  if (_22 == 0)
    goto <bb 30>; [50.00%]
  else
    goto <bb 29>; [50.00%]

  <bb 29> [local count: 38773408]:

  <bb 30> [local count: 41358302]:
  # iftmp.11_70 = PHI <1(28), 0(29)>
  _23 = (_Bool) iftmp.11_70;
  if (_23 != 0)
    goto <bb 78>; [2.00%]
  else
    goto <bb 34>; [98.00%]

  <bb 31> [local count: 80283762]:
  _24 = cpcb_66->local_ip.u_addr.ip4.addr;
  if (_24 == 0)
    goto <bb 33>; [50.00%]
  else
    goto <bb 32>; [50.00%]

  <bb 32> [local count: 40141881]:

  <bb 33> [local count: 80283762]:
  # iftmp.12_71 = PHI <1(31), 0(32)>
  _25 = (_Bool) iftmp.12_71;
  if (_25 != 0)
    goto <bb 78>; [2.00%]
  else
    goto <bb 34>; [98.00%]

  <bb 34> [local count: 119209222]:
  if (ipaddr_63 != 0B)
    goto <bb 35>; [98.00%]
  else
    goto <bb 78>; [2.00%]

  <bb 35> [local count: 116825038]:
  _26 = ipaddr_63->type;
  if (_26 == 6)
    goto <bb 36>; [34.00%]
  else
    goto <bb 42>; [66.00%]

  <bb 36> [local count: 39720513]:
  _27 = ipaddr_63->u_addr.ip6.addr[0];
  if (_27 == 0)
    goto <bb 37>; [50.00%]
  else
    goto <bb 40>; [50.00%]

  <bb 37> [local count: 19860256]:
  _28 = ipaddr_63->u_addr.ip6.addr[1];
  if (_28 == 0)
    goto <bb 38>; [50.00%]
  else
    goto <bb 40>; [50.00%]

  <bb 38> [local count: 9930128]:
  _29 = ipaddr_63->u_addr.ip6.addr[2];
  if (_29 == 0)
    goto <bb 39>; [50.00%]
  else
    goto <bb 40>; [50.00%]

  <bb 39> [local count: 4965064]:
  _30 = ipaddr_63->u_addr.ip6.addr[3];
  if (_30 == 0)
    goto <bb 41>; [50.00%]
  else
    goto <bb 40>; [50.00%]

  <bb 40> [local count: 37237981]:

  <bb 41> [local count: 39720513]:
  # iftmp.13_72 = PHI <1(39), 0(40)>
  _31 = (_Bool) iftmp.13_72;
  if (_31 != 0)
    goto <bb 78>; [2.00%]
  else
    goto <bb 45>; [98.00%]

  <bb 42> [local count: 77104525]:
  _32 = ipaddr_63->u_addr.ip4.addr;
  if (_32 == 0)
    goto <bb 44>; [50.00%]
  else
    goto <bb 43>; [50.00%]

  <bb 43> [local count: 38552263]:

  <bb 44> [local count: 77104525]:
  # iftmp.14_73 = PHI <1(42), 0(43)>
  _33 = (_Bool) iftmp.14_73;
  if (_33 != 0)
    goto <bb 78>; [2.00%]
  else
    goto <bb 45>; [98.00%]

  <bb 45> [local count: 114488537]:
  _34 = ipaddr_63->type;
  if (_17 == _34)
    goto <bb 46>; [34.00%]
  else
    goto <bb 55>; [66.00%]

  <bb 46> [local count: 38926103]:
  if (_17 == 6)
    goto <bb 47>; [34.00%]
  else
    goto <bb 54>; [66.00%]

  <bb 47> [local count: 13234875]:
  _35 = cpcb_66->local_ip.u_addr.ip6.addr[0];
  _36 = ipaddr_63->u_addr.ip6.addr[0];
  if (_35 == _36)
    goto <bb 48>; [34.00%]
  else
    goto <bb 52>; [66.00%]

  <bb 48> [local count: 4499857]:
  _37 = cpcb_66->local_ip.u_addr.ip6.addr[1];
  _38 = ipaddr_63->u_addr.ip6.addr[1];
  if (_37 == _38)
    goto <bb 49>; [34.00%]
  else
    goto <bb 52>; [66.00%]

  <bb 49> [local count: 1529952]:
  _39 = cpcb_66->local_ip.u_addr.ip6.addr[2];
  _40 = ipaddr_63->u_addr.ip6.addr[2];
  if (_39 == _40)
    goto <bb 50>; [34.00%]
  else
    goto <bb 52>; [66.00%]

  <bb 50> [local count: 520184]:
  _41 = cpcb_66->local_ip.u_addr.ip6.addr[3];
  _42 = ipaddr_63->u_addr.ip6.addr[3];
  if (_41 == _42)
    goto <bb 51>; [34.00%]
  else
    goto <bb 52>; [66.00%]

  <bb 51> [local count: 176862]:
  _43 = cpcb_66->local_ip.u_addr.ip6.zone;
  _44 = ipaddr_63->u_addr.ip6.zone;
  if (_43 == _44)
    goto <bb 53>; [34.00%]
  else
    goto <bb 52>; [66.00%]

  <bb 52> [local count: 13174742]:

  <bb 53> [local count: 13234875]:
  # iftmp.15_74 = PHI <1(51), 0(52)>
  _45 = (_Bool) iftmp.15_74;
  if (_45 != 0)
    goto <bb 78>; [2.00%]
  else
    goto <bb 55>; [98.00%]

  <bb 54> [local count: 25691228]:
  _46 = cpcb_66->local_ip.u_addr.ip4.addr;
  _47 = ipaddr_63->u_addr.ip4.addr;
  if (_46 == _47)
    goto <bb 78>; [2.00%]
  else
    goto <bb 55>; [98.00%]

  <bb 55> [local count: 1044334940]:
  # DEBUG BEGIN_STMT
  cpcb_98 = cpcb_66->next;
  # DEBUG cpcb => cpcb_98

  <bb 56> [local count: 1073741824]:
  # cpcb_66 = PHI <cpcb_96(18), cpcb_98(55)>
  # DEBUG cpcb => cpcb_66
  # DEBUG BEGIN_STMT
  if (cpcb_66 != 0B)
    goto <bb 19>; [98.00%]
  else
    goto <bb 57>; [2.00%]

  <bb 57> [local count: 21474836]:
  # DEBUG BEGIN_STMT
  i_97 = i_65 + 1;
  # DEBUG i => i_97

  <bb 58> [local count: 36758605]:
  # i_65 = PHI <i_97(57), 0(79)>
  # DEBUG i => i_65
  # DEBUG BEGIN_STMT
  if (i_65 != 4)
    goto <bb 18>; [80.00%]
  else
    goto <bb 59>; [20.00%]

  <bb 59> [local count: 14801258]:
  # port_64 = PHI <port_100(17), port_95(D)(58)>
  # DEBUG port => port_64
  # DEBUG BEGIN_STMT
  if (ipaddr_63 != 0B)
    goto <bb 60>; [70.00%]
  else
    goto <bb 70>; [30.00%]

  <bb 60> [local count: 10360881]:
  _48 = ipaddr_63->type;
  if (_48 == 6)
    goto <bb 61>; [34.00%]
  else
    goto <bb 67>; [66.00%]

  <bb 61> [local count: 3522699]:
  _49 = ipaddr_63->u_addr.ip6.addr[0];
  if (_49 != 0)
    goto <bb 66>; [50.00%]
  else
    goto <bb 62>; [50.00%]

  <bb 62> [local count: 1761350]:
  _50 = ipaddr_63->u_addr.ip6.addr[1];
  if (_50 != 0)
    goto <bb 66>; [50.00%]
  else
    goto <bb 63>; [50.00%]

  <bb 63> [local count: 880675]:
  _51 = ipaddr_63->u_addr.ip6.addr[2];
  if (_51 != 0)
    goto <bb 66>; [50.00%]
  else
    goto <bb 64>; [50.00%]

  <bb 64> [local count: 440337]:
  _52 = ipaddr_63->u_addr.ip6.addr[3];
  if (_52 != 0)
    goto <bb 66>; [50.00%]
  else
    goto <bb 65>; [50.00%]

  <bb 65> [local count: 220169]:

  <bb 66> [local count: 3522699]:
  # iftmp.16_75 = PHI <1(62), 0(65), 1(61), 1(64), 1(63)>
  _53 = (_Bool) iftmp.16_75;
  if (_53 != 0)
    goto <bb 71>; [50.00%]
  else
    goto <bb 70>; [50.00%]

  <bb 67> [local count: 6838181]:
  _54 = ipaddr_63->u_addr.ip4.addr;
  if (_54 != 0)
    goto <bb 69>; [50.00%]
  else
    goto <bb 68>; [50.00%]

  <bb 68> [local count: 3419091]:

  <bb 69> [local count: 6838181]:
  # iftmp.17_76 = PHI <1(67), 0(68)>
  _55 = (_Bool) iftmp.17_76;
  if (_55 != 0)
    goto <bb 71>; [50.00%]
  else
    goto <bb 70>; [50.00%]

  <bb 70> [local count: 9620818]:
  _56 = ipaddr_63->type;
  _57 = pcb_83(D)->local_ip.type;
  if (_56 != _57)
    goto <bb 71>; [66.00%]
  else
    goto <bb 77>; [34.00%]

  <bb 71> [local count: 11530180]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _58 = ipaddr_63->type;
  pcb_83(D)->local_ip.type = _58;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (ipaddr_63 != 0B)
    goto <bb 72>; [70.00%]
  else
    goto <bb 74>; [30.00%]

  <bb 72> [local count: 8071126]:
  _59 = ipaddr_63->type;
  if (_59 == 6)
    goto <bb 73>; [34.00%]
  else
    goto <bb 74>; [66.00%]

  <bb 73> [local count: 2744183]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  iftmp.18_102 = ipaddr_63->u_addr.ip6.addr[0];
  pcb_83(D)->local_ip.u_addr.ip6.addr[0] = iftmp.18_102;
  # DEBUG BEGIN_STMT
  iftmp.19_104 = ipaddr_63->u_addr.ip6.addr[1];
  pcb_83(D)->local_ip.u_addr.ip6.addr[1] = iftmp.19_104;
  # DEBUG BEGIN_STMT
  iftmp.20_106 = ipaddr_63->u_addr.ip6.addr[2];
  pcb_83(D)->local_ip.u_addr.ip6.addr[2] = iftmp.20_106;
  # DEBUG BEGIN_STMT
  iftmp.21_108 = ipaddr_63->u_addr.ip6.addr[3];
  pcb_83(D)->local_ip.u_addr.ip6.addr[3] = iftmp.21_108;
  # DEBUG BEGIN_STMT
  iftmp.22_110 = ipaddr_63->u_addr.ip6.zone;
  pcb_83(D)->local_ip.u_addr.ip6.zone = iftmp.22_110;
  # DEBUG BEGIN_STMT
  goto <bb 77>; [100.00%]

  <bb 74> [local count: 8785997]:
  # DEBUG BEGIN_STMT
  _60 = &ipaddr_63->u_addr.ip4;
  if (_60 != 0B)
    goto <bb 75>; [70.00%]
  else
    goto <bb 76>; [30.00%]

  <bb 75> [local count: 6150198]:
  iftmp.23_112 = ipaddr_63->u_addr.ip4.addr;

  <bb 76> [local count: 8785997]:
  # iftmp.23_77 = PHI <iftmp.23_112(75), 0(74)>
  pcb_83(D)->local_ip.u_addr.ip4.addr = iftmp.23_77;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pcb_83(D)->local_ip.u_addr.ip6.addr[3] = 0;
  pcb_83(D)->local_ip.u_addr.ip6.addr[2] = 0;
  pcb_83(D)->local_ip.u_addr.ip6.addr[1] = 0;
  # DEBUG BEGIN_STMT
  pcb_83(D)->local_ip.u_addr.ip6.zone = 0;

  <bb 77> [local count: 14801258]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pcb_83(D)->local_port = port_64;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tcp_bound_pcbs.24_61 = tcp_bound_pcbs;
  pcb_83(D)->next = tcp_bound_pcbs.24_61;
  # DEBUG BEGIN_STMT
  tcp_bound_pcbs = pcb_83(D);
  # DEBUG BEGIN_STMT
  tcp_timer_needed ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 78> [local count: 23155530]:
  # _67 = PHI <-16(4), -6(5), -2(17), -8(33), 0(77), -8(30), -8(53), -8(34), -8(44), -8(41), -8(54)>
  zoned_ipaddr ={v} {CLOBBER};
  return _67;

}



;; Function tcp_bind_netif (tcp_bind_netif, funcdef_no=16, decl_uid=7212, cgraph_uid=17, symbol_order=29)

Modification phase of node tcp_bind_netif/29
tcp_bind_netif (struct tcp_pcb * pcb, const struct netif * netif)
{
  unsigned char _1;
  unsigned char _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (netif_4(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 4>; [30.00%]

  <bb 3> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  _1 = netif_4(D)->num;
  _2 = _1 + 1;
  pcb_6(D)->netif_idx = _2;
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 322122547]:
  # DEBUG BEGIN_STMT
  pcb_6(D)->netif_idx = 0;

  <bb 5> [local count: 1073741824]:
  return;

}



;; Function tcp_listen_with_backlog_and_err (tcp_listen_with_backlog_and_err, funcdef_no=19, decl_uid=7221, cgraph_uid=20, symbol_order=32)

Modification phase of node tcp_listen_with_backlog_and_err/32
tcp_listen_with_backlog_and_err (struct tcp_pcb * pcb, u8_t backlog, err_t * err)
{
  struct tcp_pcb * tcp_tmp_pcb;
  err_t res;
  struct tcp_pcb_listen * lpcb;
  tcp_state _1;
  void * _3;
  short unsigned int _4;
  unsigned char _5;
  unsigned char _6;
  unsigned char _7;
  unsigned char _8;
  unsigned char _9;
  unsigned char _10;
  unsigned char iftmp.33_11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  unsigned char _16;
  long unsigned int _17;
  struct tcp_pcb * tcp_bound_pcbs.31_18;
  struct tcp_pcb * _19;
  struct tcp_pcb * _20;
  struct tcp_pcb * _21;
  tcp_state _22;
  struct tcp_pcb * _23;

  <bb 2> [local count: 228328]:
  # DEBUG BEGIN_STMT
  # DEBUG lpcb => 0B
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_33(D) == 0B)
    goto <bb 3>; [8.27%]
  else
    goto <bb 4>; [91.73%]

  <bb 3> [local count: 18883]:
  # DEBUG BEGIN_STMT
  # DEBUG res => -16
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 21>; [100.00%]

  <bb 4> [local count: 209445]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pcb_33(D)->state;
  if (_1 != 0)
    goto <bb 5>; [29.93%]
  else
    goto <bb 6>; [70.07%]

  <bb 5> [local count: 62687]:
  # DEBUG BEGIN_STMT
  # DEBUG res => -15
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 21>; [100.00%]

  <bb 6> [local count: 146758]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  lpcb_36 = memp_malloc (3);
  # DEBUG lpcb => lpcb_36
  # DEBUG BEGIN_STMT
  if (lpcb_36 == 0B)
    goto <bb 7>; [8.27%]
  else
    goto <bb 8>; [91.73%]

  <bb 7> [local count: 12137]:
  # DEBUG BEGIN_STMT
  # DEBUG res => -1
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 21>; [100.00%]

  <bb 8> [local count: 134621]:
  # DEBUG BEGIN_STMT
  _3 = pcb_33(D)->callback_arg;
  lpcb_36->callback_arg = _3;
  # DEBUG BEGIN_STMT
  _4 = pcb_33(D)->local_port;
  lpcb_36->local_port = _4;
  # DEBUG BEGIN_STMT
  lpcb_36->state = 1;
  # DEBUG BEGIN_STMT
  _5 = pcb_33(D)->prio;
  lpcb_36->prio = _5;
  # DEBUG BEGIN_STMT
  _6 = pcb_33(D)->so_options;
  lpcb_36->so_options = _6;
  # DEBUG BEGIN_STMT
  _7 = pcb_33(D)->netif_idx;
  lpcb_36->netif_idx = _7;
  # DEBUG BEGIN_STMT
  _8 = pcb_33(D)->ttl;
  lpcb_36->ttl = _8;
  # DEBUG BEGIN_STMT
  _9 = pcb_33(D)->tos;
  lpcb_36->tos = _9;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _10 = pcb_33(D)->local_ip.type;
  lpcb_36->remote_ip.type = _10;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  lpcb_36->local_ip.type = _10;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (_10 == 6)
    goto <bb 9>; [34.00%]
  else
    goto <bb 10>; [66.00%]

  <bb 9> [local count: 45771]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _12 = pcb_33(D)->local_ip.u_addr.ip6.addr[0];
  lpcb_36->local_ip.u_addr.ip6.addr[0] = _12;
  # DEBUG BEGIN_STMT
  _13 = pcb_33(D)->local_ip.u_addr.ip6.addr[1];
  lpcb_36->local_ip.u_addr.ip6.addr[1] = _13;
  # DEBUG BEGIN_STMT
  _14 = pcb_33(D)->local_ip.u_addr.ip6.addr[2];
  lpcb_36->local_ip.u_addr.ip6.addr[2] = _14;
  # DEBUG BEGIN_STMT
  _15 = pcb_33(D)->local_ip.u_addr.ip6.addr[3];
  lpcb_36->local_ip.u_addr.ip6.addr[3] = _15;
  # DEBUG BEGIN_STMT
  _16 = pcb_33(D)->local_ip.u_addr.ip6.zone;
  lpcb_36->local_ip.u_addr.ip6.zone = _16;
  # DEBUG BEGIN_STMT
  goto <bb 11>; [100.00%]

  <bb 10> [local count: 88850]:
  # DEBUG BEGIN_STMT
  _17 = pcb_33(D)->local_ip.u_addr.ip4.addr;
  lpcb_36->local_ip.u_addr.ip4.addr = _17;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  lpcb_36->local_ip.u_addr.ip6.addr[3] = 0;
  lpcb_36->local_ip.u_addr.ip6.addr[2] = 0;
  lpcb_36->local_ip.u_addr.ip6.addr[1] = 0;
  # DEBUG BEGIN_STMT
  lpcb_36->local_ip.u_addr.ip6.zone = 0;

  <bb 11> [local count: 134621]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (_4 != 0)
    goto <bb 12>; [50.00%]
  else
    goto <bb 18>; [50.00%]

  <bb 12> [local count: 67311]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tcp_bound_pcbs.31_18 = tcp_bound_pcbs;
  if (tcp_bound_pcbs.31_18 == pcb_33(D))
    goto <bb 13>; [30.00%]
  else
    goto <bb 25>; [70.00%]

  <bb 13> [local count: 20193]:
  # DEBUG BEGIN_STMT
  _19 = tcp_bound_pcbs.31_18->next;
  tcp_bound_pcbs = _19;
  goto <bb 17>; [100.00%]

  <bb 14> [local count: 416228]:
  # DEBUG BEGIN_STMT
  _20 = tcp_tmp_pcb_26->next;
  if (_20 == pcb_33(D))
    goto <bb 15>; [5.50%]
  else
    goto <bb 27>; [94.50%]

  <bb 27> [local count: 393336]:
  goto <bb 16>; [100.00%]

  <bb 15> [local count: 22893]:
  # tcp_tmp_pcb_2 = PHI <tcp_tmp_pcb_26(14)>
  # DEBUG BEGIN_STMT
  _21 = pcb_33(D)->next;
  tcp_tmp_pcb_2->next = _21;
  # DEBUG BEGIN_STMT
  goto <bb 17>; [100.00%]

  <bb 25> [local count: 47117]:

  <bb 16> [local count: 440453]:
  # tcp_tmp_pcb_26 = PHI <tcp_bound_pcbs.31_18(25), _20(27)>
  # DEBUG tcp_tmp_pcb => tcp_tmp_pcb_26
  # DEBUG BEGIN_STMT
  if (tcp_tmp_pcb_26 != 0B)
    goto <bb 14>; [94.50%]
  else
    goto <bb 17>; [5.50%]

  <bb 17> [local count: 67311]:
  # DEBUG BEGIN_STMT
  pcb_33(D)->next = 0B;

  <bb 18> [local count: 134621]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tcp_free (pcb_33(D));
  # DEBUG BEGIN_STMT
  lpcb_36->accept = tcp_accept_null;
  # DEBUG BEGIN_STMT
  lpcb_36->accepts_pending = 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _22 = lpcb_36->state;
  if (_22 != 1)
    goto <bb 24>; [79.76%]
  else
    goto <bb 20>; [20.24%]

  <bb 24> [local count: 107374]:

  <bb 19> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 26> [local count: 1073741824]:
  goto <bb 19>; [100.00%]

  <bb 20> [local count: 27247]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  iftmp.33_11 = MAX_EXPR <1, backlog_63(D)>;
  lpcb_36->backlog = iftmp.33_11;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _23 = tcp_listen_pcbs.pcbs;
  MEM[(struct tcp_pcb *)lpcb_36].next = _23;
  # DEBUG BEGIN_STMT
  tcp_listen_pcbs.pcbs = lpcb_36;
  # DEBUG BEGIN_STMT
  tcp_timer_needed ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG res => 0

  <bb 21> [local count: 120954]:
  # lpcb_24 = PHI <0B(3), 0B(5), lpcb_36(20), 0B(7)>
  # res_25 = PHI <-16(3), -15(5), 0(20), -1(7)>
done:
  # DEBUG res => res_25
  # DEBUG lpcb => lpcb_24
  # DEBUG BEGIN_STMT
  if (err_69(D) != 0B)
    goto <bb 22>; [70.00%]
  else
    goto <bb 23>; [30.00%]

  <bb 22> [local count: 84668]:
  # DEBUG BEGIN_STMT
  *err_69(D) = res_25;

  <bb 23> [local count: 120954]:
  # DEBUG BEGIN_STMT
  return lpcb_24;

}



;; Function tcp_listen_with_backlog (tcp_listen_with_backlog, funcdef_no=18, decl_uid=7224, cgraph_uid=19, symbol_order=31)

Modification phase of node tcp_listen_with_backlog/31
tcp_listen_with_backlog (struct tcp_pcb * pcb, u8_t backlog)
{
  struct tcp_pcb * _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _5 = tcp_listen_with_backlog_and_err (pcb_2(D), backlog_3(D), 0B);
  return _5;

}



;; Function tcp_update_rcv_ann_wnd (tcp_update_rcv_ann_wnd, funcdef_no=20, decl_uid=7290, cgraph_uid=21, symbol_order=33)

Modification phase of node tcp_update_rcv_ann_wnd/33
tcp_update_rcv_ann_wnd (struct tcp_pcb * pcb)
{
  u32_t new_rcv_ann_wnd;
  u32_t new_right_edge;
  long unsigned int _1;
  short unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  short unsigned int _5;
  short unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long int _10;
  long unsigned int _11;
  long int _12;
  short unsigned int _13;
  u32_t _14;
  u32_t _27;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_19(D) == 0B)
    goto <bb 13>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 13> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 15> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pcb_19(D)->rcv_nxt;
  _2 = pcb_19(D)->rcv_wnd;
  _3 = (long unsigned int) _2;
  new_right_edge_21 = _1 + _3;
  # DEBUG new_right_edge => new_right_edge_21
  # DEBUG BEGIN_STMT
  _4 = pcb_19(D)->rcv_ann_right_edge;
  _5 = pcb_19(D)->mss;
  _6 = MIN_EXPR <_5, 3650>;
  _7 = (long unsigned int) _6;
  _8 = _4 + _7;
  _9 = new_right_edge_21 - _8;
  _10 = (long int) _9;
  if (_10 >= 0)
    goto <bb 5>; [42.57%]
  else
    goto <bb 6>; [57.43%]

  <bb 5> [local count: 106655]:
  # DEBUG BEGIN_STMT
  pcb_19(D)->rcv_ann_wnd = _2;
  # DEBUG BEGIN_STMT
  _27 = new_right_edge_21 - _4;
  goto <bb 12>; [100.00%]

  <bb 6> [local count: 143885]:
  # DEBUG BEGIN_STMT
  _11 = _1 - _4;
  _12 = (long int) _11;
  if (_12 > 0)
    goto <bb 7>; [42.57%]
  else
    goto <bb 8>; [57.43%]

  <bb 7> [local count: 61252]:
  # DEBUG BEGIN_STMT
  pcb_19(D)->rcv_ann_wnd = 0;
  goto <bb 11>; [100.00%]

  <bb 8> [local count: 82633]:
  # DEBUG BEGIN_STMT
  new_rcv_ann_wnd_22 = _4 - _1;
  # DEBUG new_rcv_ann_wnd => new_rcv_ann_wnd_22
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (new_rcv_ann_wnd_22 > 65535)
    goto <bb 14>; [66.00%]
  else
    goto <bb 10>; [34.00%]

  <bb 14> [local count: 54538]:

  <bb 9> [local count: 545378766]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 16> [local count: 545378766]:
  goto <bb 9>; [100.00%]

  <bb 10> [local count: 28095]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _13 = (short unsigned int) new_rcv_ann_wnd_22;
  pcb_19(D)->rcv_ann_wnd = _13;

  <bb 11> [local count: 89347]:
  # DEBUG BEGIN_STMT

  <bb 12> [local count: 196002]:
  # _14 = PHI <_27(5), 0(11)>
  return _14;

}



;; Function tcp_recved (tcp_recved, funcdef_no=21, decl_uid=7205, cgraph_uid=22, symbol_order=34)

Modification phase of node tcp_recved/34
tcp_recved (struct tcp_pcb * pcb, u16_t len)
{
  tcpwnd_size_t rcv_wnd;
  u32_t wnd_inflation;
  tcp_state _1;
  short unsigned int _2;

  <bb 2> [local count: 385552]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_6(D) == 0B)
    goto <bb 11>; [18.09%]
  else
    goto <bb 3>; [81.91%]

  <bb 3> [local count: 315806]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pcb_6(D)->state;
  if (_1 == 1)
    goto <bb 12>; [34.00%]
  else
    goto <bb 5>; [66.00%]

  <bb 12> [local count: 107374]:

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 13> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 208432]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = pcb_6(D)->rcv_wnd;
  rcv_wnd_9 = _2 + len_8(D);
  # DEBUG rcv_wnd => rcv_wnd_9
  # DEBUG BEGIN_STMT
  if (rcv_wnd_9 > 7300)
    goto <bb 7>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 6> [local count: 104216]:
  if (_2 > rcv_wnd_9)
    goto <bb 7>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 7> [local count: 156324]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pcb_6(D)->rcv_wnd = 7300;
  goto <bb 9>; [100.00%]

  <bb 8> [local count: 52108]:
  # DEBUG BEGIN_STMT
  pcb_6(D)->rcv_wnd = rcv_wnd_9;

  <bb 9> [local count: 208432]:
  # DEBUG BEGIN_STMT
  wnd_inflation_13 = tcp_update_rcv_ann_wnd (pcb_6(D));
  # DEBUG wnd_inflation => wnd_inflation_13
  # DEBUG BEGIN_STMT
  if (wnd_inflation_13 > 1824)
    goto <bb 10>; [33.00%]
  else
    goto <bb 11>; [67.00%]

  <bb 10> [local count: 68783]:
  # DEBUG D#1 => len_8(D)
  tcp_recved.part.0 (pcb_6(D));

  <bb 11> [local count: 278178]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function tcp_txnow (tcp_txnow, funcdef_no=26, decl_uid=7266, cgraph_uid=27, symbol_order=39)

Modification phase of node tcp_txnow/39
tcp_txnow ()
{
  struct tcp_pcb * pcb;
  short unsigned int _1;
  short unsigned int _9;

  <bb 2> [local count: 118111602]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pcb_6 = tcp_active_pcbs;
  # DEBUG pcb => pcb_6
  goto <bb 6>; [100.00%]

  <bb 3> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  _1 = pcb_2->flags;
  _9 = _1 & 128;
  if (_9 != 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 4> [local count: 315357973]:
  # DEBUG BEGIN_STMT
  tcp_output (pcb_2);

  <bb 5> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  pcb_8 = pcb_2->next;
  # DEBUG pcb => pcb_8

  <bb 6> [local count: 1073741824]:
  # pcb_2 = PHI <pcb_6(2), pcb_8(5)>
  # DEBUG pcb => pcb_2
  # DEBUG BEGIN_STMT
  if (pcb_2 != 0B)
    goto <bb 3>; [89.00%]
  else
    goto <bb 7>; [11.00%]

  <bb 7> [local count: 118111601]:
  return;

}



;; Function tcp_seg_free (tcp_seg_free, funcdef_no=29, decl_uid=7319, cgraph_uid=30, symbol_order=42)

Modification phase of node tcp_seg_free/42
tcp_seg_free (struct tcp_seg * seg)
{
  struct pbuf * _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (seg_4(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 6>; [30.00%]

  <bb 3> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  _1 = seg_4(D)->p;
  if (_1 != 0B)
    goto <bb 4>; [53.47%]
  else
    goto <bb 5>; [46.53%]

  <bb 4> [local count: 401890828]:
  # DEBUG BEGIN_STMT
  pbuf_free (_1);

  <bb 5> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  memp_free (4, seg_4(D));

  <bb 6> [local count: 1073741824]:
  return;

}



;; Function tcp_segs_free (tcp_segs_free, funcdef_no=28, decl_uid=7317, cgraph_uid=29, symbol_order=41)

Modification phase of node tcp_segs_free/41
tcp_segs_free (struct tcp_seg * seg)
{
  struct tcp_seg * next;

  <bb 2> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  next_5 = seg_1->next;
  # DEBUG next => next_5
  # DEBUG BEGIN_STMT
  tcp_seg_free (seg_1);
  # DEBUG BEGIN_STMT
  # DEBUG seg => next_5

  <bb 4> [local count: 1073741824]:
  # seg_1 = PHI <seg_3(D)(2), next_5(3)>
  # DEBUG seg => seg_1
  # DEBUG BEGIN_STMT
  if (seg_1 != 0B)
    goto <bb 3>; [89.00%]
  else
    goto <bb 5>; [11.00%]

  <bb 5> [local count: 118111601]:
  return;

}



;; Function tcp_setprio (tcp_setprio, funcdef_no=30, decl_uid=7240, cgraph_uid=31, symbol_order=43)

Modification phase of node tcp_setprio/43
tcp_setprio (struct tcp_pcb * pcb, u8_t prio)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_2(D) == 0B)
    goto <bb 4>; [18.09%]
  else
    goto <bb 3>; [81.91%]

  <bb 3> [local count: 879501929]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pcb_2(D)->prio = prio_4(D);

  <bb 4> [local count: 1073741824]:
  return;

}



;; Function tcp_arg (tcp_arg, funcdef_no=39, decl_uid=7182, cgraph_uid=40, symbol_order=52)

Modification phase of node tcp_arg/52
tcp_arg (struct tcp_pcb * pcb, void * arg)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_2(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 4>; [30.00%]

  <bb 3> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  pcb_2(D)->callback_arg = arg_4(D);

  <bb 4> [local count: 1073741824]:
  return;

}



;; Function tcp_recv (tcp_recv, funcdef_no=40, decl_uid=7185, cgraph_uid=41, symbol_order=53)

Modification phase of node tcp_recv/53
tcp_recv (struct tcp_pcb * pcb, err_t (*tcp_recv_fn) (void *, struct tcp_pcb *, struct pbuf *, err_t) recv)
{
  tcp_state _1;

  <bb 2> [local count: 451151]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_4(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 6>; [30.00%]

  <bb 3> [local count: 315806]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pcb_4(D)->state;
  if (_1 == 1)
    goto <bb 7>; [34.00%]
  else
    goto <bb 5>; [66.00%]

  <bb 7> [local count: 107374]:

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 8> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 208432]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pcb_4(D)->recv = recv_6(D);

  <bb 6> [local count: 343777]:
  return;

}



;; Function tcp_sent (tcp_sent, funcdef_no=41, decl_uid=7188, cgraph_uid=42, symbol_order=54)

Modification phase of node tcp_sent/54
tcp_sent (struct tcp_pcb * pcb, err_t (*tcp_sent_fn) (void *, struct tcp_pcb *, u16_t) sent)
{
  tcp_state _1;

  <bb 2> [local count: 451151]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_4(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 6>; [30.00%]

  <bb 3> [local count: 315806]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pcb_4(D)->state;
  if (_1 == 1)
    goto <bb 7>; [34.00%]
  else
    goto <bb 5>; [66.00%]

  <bb 7> [local count: 107374]:

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 8> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 208432]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pcb_4(D)->sent = sent_6(D);

  <bb 6> [local count: 343777]:
  return;

}



;; Function tcp_err (tcp_err, funcdef_no=42, decl_uid=7191, cgraph_uid=43, symbol_order=55)

Modification phase of node tcp_err/55
tcp_err (struct tcp_pcb * pcb, void (*tcp_err_fn) (void *, err_t) err)
{
  tcp_state _1;

  <bb 2> [local count: 451151]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_4(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 6>; [30.00%]

  <bb 3> [local count: 315806]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pcb_4(D)->state;
  if (_1 == 1)
    goto <bb 7>; [34.00%]
  else
    goto <bb 5>; [66.00%]

  <bb 7> [local count: 107374]:

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 8> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 208432]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pcb_4(D)->errf = err_6(D);

  <bb 6> [local count: 343777]:
  return;

}



;; Function tcp_accept (tcp_accept, funcdef_no=43, decl_uid=7194, cgraph_uid=44, symbol_order=56)

Modification phase of node tcp_accept/56
tcp_accept (struct tcp_pcb * pcb, err_t (*tcp_accept_fn) (void *, struct tcp_pcb *, err_t) accept)
{
  tcp_state _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_3(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 5>; [30.00%]

  <bb 3> [local count: 751619278]:
  _1 = pcb_3(D)->state;
  if (_1 == 1)
    goto <bb 4>; [34.00%]
  else
    goto <bb 5>; [66.00%]

  <bb 4> [local count: 255550554]:
  # DEBUG BEGIN_STMT
  # DEBUG lpcb => pcb_3(D)
  # DEBUG BEGIN_STMT
  MEM[(struct tcp_pcb_listen *)pcb_3(D)].accept = accept_5(D);

  <bb 5> [local count: 1073741824]:
  return;

}



;; Function tcp_poll (tcp_poll, funcdef_no=44, decl_uid=7198, cgraph_uid=45, symbol_order=57)

Modification phase of node tcp_poll/57
tcp_poll (struct tcp_pcb * pcb, err_t (*tcp_poll_fn) (void *, struct tcp_pcb *) poll, u8_t interval)
{
  tcp_state _1;

  <bb 2> [local count: 385552]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_4(D) == 0B)
    goto <bb 6>; [18.09%]
  else
    goto <bb 3>; [81.91%]

  <bb 3> [local count: 315806]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pcb_4(D)->state;
  if (_1 == 1)
    goto <bb 7>; [34.00%]
  else
    goto <bb 5>; [66.00%]

  <bb 7> [local count: 107374]:

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 8> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 208432]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pcb_4(D)->poll = poll_6(D);
  # DEBUG BEGIN_STMT
  pcb_4(D)->pollinterval = interval_8(D);

  <bb 6> [local count: 278178]:
  return;

}



;; Function tcp_pcb_purge (tcp_pcb_purge, funcdef_no=45, decl_uid=7312, cgraph_uid=46, symbol_order=58)

Modification phase of node tcp_pcb_purge/58
tcp_pcb_purge (struct tcp_pcb * pcb)
{
  tcp_state _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_4(D) == 0B)
    goto <bb 7>; [18.09%]
  else
    goto <bb 3>; [81.91%]

  <bb 3> [local count: 879501929]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pcb_4(D)->state;
  if (_1 != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 4> [local count: 439750964]:
  if (_1 != 10)
    goto <bb 5>; [66.00%]
  else
    goto <bb 7>; [34.00%]

  <bb 5> [local count: 290235636]:
  if (_1 != 1)
    goto <bb 6>; [48.88%]
  else
    goto <bb 7>; [51.12%]

  <bb 6> [local count: 141867178]:
  tcp_pcb_purge.part.0 (pcb_4(D));

  <bb 7> [local count: 1073741824]:
  return;

}



;; Function tcp_slowtmr (tcp_slowtmr, funcdef_no=24, decl_uid=7262, cgraph_uid=25, symbol_order=37)

Modification phase of node tcp_slowtmr/37
tcp_slowtmr ()
{
  void * err_arg;
  void (*tcp_err_fn) (void *, err_t) err_fn;
  int calc_rto;
  u8_t backoff_idx;
  u8_t backoff_cnt;
  err_t err;
  u8_t pcb_reset;
  u8_t pcb_remove;
  tcpwnd_size_t eff_wnd;
  struct tcp_pcb * prev;
  struct tcp_pcb * pcb;
  long unsigned int tcp_ticks.52_1;
  long unsigned int _2;
  unsigned char tcp_timer_ctr.53_3;
  unsigned char _4;
  tcp_state _5;
  unsigned char _6;
  unsigned char tcp_timer_ctr.54_7;
  unsigned char _9;
  unsigned char _10;
  unsigned char _11;
  struct tcp_seg * _12;
  struct tcp_seg * _13;
  unsigned char _14;
  int _15;
  int _16;
  unsigned char _17;
  unsigned char _19;
  unsigned char _20;
  short unsigned int _21;
  signed char _22;
  signed char _23;
  signed char _24;
  unsigned char _25;
  unsigned char _27;
  short int _28;
  unsigned short _29;
  unsigned short _30;
  short int _31;
  short int _32;
  short int _33;
  signed char _34;
  struct tcp_seg * _35;
  struct tcp_seg * _36;
  tcp_state _37;
  unsigned char _38;
  short int _39;
  short int _40;
  int _41;
  short int _42;
  int _43;
  int _44;
  int _45;
  unsigned char _46;
  int _47;
  short unsigned int _48;
  short unsigned int _49;
  short unsigned int _50;
  short unsigned int _51;
  short unsigned int _52;
  tcp_state _53;
  short unsigned int _54;
  long unsigned int tcp_ticks.57_55;
  long unsigned int _56;
  long unsigned int _57;
  unsigned char _58;
  int _59;
  long unsigned int tcp_ticks.58_60;
  long unsigned int _61;
  long unsigned int _62;
  long unsigned int _63;
  long unsigned int _64;
  long unsigned int _65;
  unsigned char _66;
  long unsigned int _67;
  long unsigned int _68;
  long unsigned int _69;
  long unsigned int _70;
  unsigned char _71;
  unsigned char _72;
  tcp_state _73;
  long unsigned int tcp_ticks.60_74;
  long unsigned int _75;
  long unsigned int _76;
  long unsigned int tcp_ticks.61_77;
  long unsigned int _78;
  long unsigned int _79;
  struct tcp_pcb * tcp_active_pcbs.62_80;
  struct tcp_pcb * _81;
  struct tcp_pcb * tcp_active_pcbs.63_82;
  struct tcp_pcb * _83;
  long unsigned int _84;
  long unsigned int _85;
  struct ip_addr_t * _86;
  struct ip_addr_t * _87;
  short unsigned int _88;
  short unsigned int _89;
  unsigned char tcp_active_pcbs_changed.64_90;
  unsigned char _91;
  unsigned char _92;
  unsigned char _93;
  err_t (*<T74e>) (void *, struct tcp_pcb *) _94;
  void * _95;
  unsigned char tcp_active_pcbs_changed.65_96;
  tcp_state _97;
  long unsigned int tcp_ticks.66_98;
  long unsigned int _99;
  long unsigned int _100;
  struct tcp_pcb * tcp_tw_pcbs.67_101;
  struct tcp_pcb * _102;
  struct tcp_pcb * tcp_tw_pcbs.68_103;
  struct tcp_pcb * _104;
  short int iftmp.56_116;
  short unsigned int _141;
  unsigned char _145;

  <bb 2> [local count: 477869]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG err => 0
  # DEBUG BEGIN_STMT
  tcp_ticks.52_1 = tcp_ticks;
  _2 = tcp_ticks.52_1 + 1;
  tcp_ticks = _2;
  # DEBUG BEGIN_STMT
  tcp_timer_ctr.53_3 = tcp_timer_ctr;
  _4 = tcp_timer_ctr.53_3 + 1;
  tcp_timer_ctr = _4;
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 52726]:

  <bb 4> [local count: 530595]:
  # DEBUG BEGIN_STMT
  # DEBUG prev => 0B
  # DEBUG BEGIN_STMT
  pcb_146 = tcp_active_pcbs;
  # DEBUG pcb => pcb_146
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 84>; [100.00%]

  <bb 5> [local count: 5368700]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _5 = pcb_105->state;
  if (_5 == 0)
    goto <bb 101>; [2.00%]
  else
    goto <bb 7>; [98.00%]

  <bb 101> [local count: 107374]:

  <bb 6> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 111> [local count: 1073741824]:
  goto <bb 6>; [100.00%]

  <bb 7> [local count: 5261326]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (_5 == 1)
    goto <bb 102>; [2.00%]
  else
    goto <bb 9>; [98.00%]

  <bb 102> [local count: 105227]:

  <bb 8> [local count: 1052266989]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 112> [local count: 1052266989]:
  goto <bb 8>; [100.00%]

  <bb 9> [local count: 5156099]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (_5 == 10)
    goto <bb 103>; [2.00%]
  else
    goto <bb 11>; [98.00%]

  <bb 103> [local count: 103122]:

  <bb 10> [local count: 1031221651]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 113> [local count: 1031221651]:
  goto <bb 10>; [100.00%]

  <bb 11> [local count: 5052978]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _6 = pcb_105->last_timer;
  tcp_timer_ctr.54_7 = tcp_timer_ctr;
  if (_6 == tcp_timer_ctr.54_7)
    goto <bb 12>; [20.24%]
  else
    goto <bb 13>; [79.76%]

  <bb 12> [local count: 1022723]:
  # DEBUG BEGIN_STMT
  # DEBUG prev => pcb_105
  # DEBUG BEGIN_STMT
  pcb_210 = pcb_105->next;
  # DEBUG pcb => pcb_210
  # DEBUG BEGIN_STMT
  // predicted unlikely by continue predictor.
  goto <bb 83>; [100.00%]

  <bb 13> [local count: 4030255]:
  # DEBUG BEGIN_STMT
  pcb_105->last_timer = tcp_timer_ctr.54_7;
  # DEBUG BEGIN_STMT
  # DEBUG pcb_remove => 0
  # DEBUG BEGIN_STMT
  # DEBUG pcb_reset => 0
  # DEBUG BEGIN_STMT
  if (_5 == 2)
    goto <bb 14>; [34.00%]
  else
    goto <bb 15>; [66.00%]

  <bb 14> [local count: 1370287]:
  _9 = pcb_105->nrtx;
  if (_9 > 1)
    goto <bb 44>; [59.00%]
  else
    goto <bb 15>; [41.00%]

  <bb 15> [local count: 3221786]:
  # DEBUG BEGIN_STMT
  _10 = pcb_105->nrtx;
  if (_10 > 1)
    goto <bb 44>; [59.00%]
  else
    goto <bb 16>; [41.00%]

  <bb 16> [local count: 1320932]:
  # DEBUG BEGIN_STMT
  _11 = pcb_105->persist_backoff;
  if (_11 != 0)
    goto <bb 17>; [50.00%]
  else
    goto <bb 31>; [50.00%]

  <bb 17> [local count: 660466]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _12 = pcb_105->unacked;
  if (_12 != 0B)
    goto <bb 106>; [2.00%]
  else
    goto <bb 19>; [98.00%]

  <bb 106> [local count: 13209]:

  <bb 18> [local count: 132093439]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 116> [local count: 132093439]:
  goto <bb 18>; [100.00%]

  <bb 19> [local count: 647257]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _13 = pcb_105->unsent;
  if (_13 == 0B)
    goto <bb 107>; [2.00%]
  else
    goto <bb 21>; [98.00%]

  <bb 107> [local count: 12945]:

  <bb 20> [local count: 129451570]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 117> [local count: 129451570]:
  goto <bb 20>; [100.00%]

  <bb 21> [local count: 634312]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _14 = pcb_105->persist_probe;
  if (_14 > 1)
    goto <bb 44>; [59.00%]
  else
    goto <bb 22>; [41.00%]

  <bb 22> [local count: 260068]:
  # DEBUG BEGIN_STMT
  _15 = (int) _11;
  _16 = _15 + -1;
  backoff_cnt_173 = tcp_persist_backoff[_16];
  # DEBUG backoff_cnt => backoff_cnt_173
  # DEBUG BEGIN_STMT
  _17 = pcb_105->persist_cnt;
  if (_17 < backoff_cnt_173)
    goto <bb 23>; [50.00%]
  else
    goto <bb 24>; [50.00%]

  <bb 23> [local count: 130034]:
  # DEBUG BEGIN_STMT
  _19 = _17 + 1;
  pcb_105->persist_cnt = _19;

  <bb 24> [local count: 260068]:
  # DEBUG BEGIN_STMT
  _20 = pcb_105->persist_cnt;
  if (_20 >= backoff_cnt_173)
    goto <bb 25>; [50.00%]
  else
    goto <bb 44>; [50.00%]

  <bb 25> [local count: 130034]:
  # DEBUG BEGIN_STMT
  # DEBUG next_slot => 1
  # DEBUG BEGIN_STMT
  _21 = pcb_105->snd_wnd;
  if (_21 == 0)
    goto <bb 26>; [50.00%]
  else
    goto <bb 27>; [50.00%]

  <bb 26> [local count: 65017]:
  # DEBUG BEGIN_STMT
  _22 = tcp_zero_window_probe (pcb_105);
  if (_22 != 0)
    goto <bb 44>; [50.00%]
  else
    goto <bb 29>; [50.00%]

  <bb 27> [local count: 65017]:
  # DEBUG BEGIN_STMT
  _23 = tcp_split_unsent_seg (pcb_105, _21);
  if (_23 == 0)
    goto <bb 28>; [33.00%]
  else
    goto <bb 29>; [67.00%]

  <bb 28> [local count: 21456]:
  # DEBUG BEGIN_STMT
  _24 = tcp_output (pcb_105);
  if (_24 == 0)
    goto <bb 44>; [50.00%]
  else
    goto <bb 29>; [50.00%]

  <bb 29> [local count: 86798]:
  # DEBUG next_slot => NULL
  # DEBUG BEGIN_STMT
  pcb_105->persist_cnt = 0;
  # DEBUG BEGIN_STMT
  _25 = pcb_105->persist_backoff;
  if (_25 <= 6)
    goto <bb 30>; [50.00%]
  else
    goto <bb 44>; [50.00%]

  <bb 30> [local count: 43399]:
  # DEBUG BEGIN_STMT
  _27 = _25 + 1;
  pcb_105->persist_backoff = _27;
  goto <bb 44>; [100.00%]

  <bb 31> [local count: 660466]:
  # DEBUG BEGIN_STMT
  _28 = pcb_105->rtime;
  _29 = (unsigned short) _28;
  if (_29 <= 32766)
    goto <bb 32>; [50.00%]
  else
    goto <bb 33>; [50.00%]

  <bb 32> [local count: 330233]:
  # DEBUG BEGIN_STMT
  _30 = _29 + 1;
  _31 = (short int) _30;
  pcb_105->rtime = _31;

  <bb 33> [local count: 660466]:
  # DEBUG BEGIN_STMT
  _32 = pcb_105->rtime;
  _33 = pcb_105->rto;
  if (_32 >= _33)
    goto <bb 34>; [33.00%]
  else
    goto <bb 44>; [67.00%]

  <bb 34> [local count: 217954]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _34 = tcp_rexmit_rto_prepare (pcb_105);
  if (_34 == 0)
    goto <bb 37>; [50.00%]
  else
    goto <bb 35>; [50.00%]

  <bb 35> [local count: 108977]:
  _35 = pcb_105->unacked;
  if (_35 == 0B)
    goto <bb 36>; [30.00%]
  else
    goto <bb 44>; [70.00%]

  <bb 36> [local count: 32693]:
  _36 = pcb_105->unsent;
  if (_36 != 0B)
    goto <bb 37>; [70.00%]
  else
    goto <bb 44>; [30.00%]

  <bb 37> [local count: 131862]:
  # DEBUG BEGIN_STMT
  _37 = pcb_105->state;
  if (_37 != 2)
    goto <bb 38>; [66.00%]
  else
    goto <bb 41>; [34.00%]

  <bb 38> [local count: 87029]:
  # DEBUG BEGIN_STMT
  _38 = pcb_105->nrtx;
  backoff_idx_163 = MIN_EXPR <_38, 12>;
  # DEBUG backoff_idx => backoff_idx_163
  # DEBUG BEGIN_STMT
  _39 = pcb_105->sa;
  _40 = _39 >> 3;
  _41 = (int) _40;
  _42 = pcb_105->sv;
  _43 = (int) _42;
  _44 = _41 + _43;
  _45 = (int) backoff_idx_163;
  _46 = tcp_backoff[_45];
  _47 = (int) _46;
  calc_rto_164 = _44 << _47;
  # DEBUG calc_rto => calc_rto_164
  # DEBUG BEGIN_STMT
  if (calc_rto_164 <= 32766)
    goto <bb 39>; [50.00%]
  else
    goto <bb 40>; [50.00%]

  <bb 39> [local count: 43514]:

  <bb 40> [local count: 87029]:
  # _59 = PHI <calc_rto_164(39), 32767(38)>
  iftmp.56_116 = (short int) _59;
  pcb_105->rto = iftmp.56_116;

  <bb 41> [local count: 131862]:
  # DEBUG BEGIN_STMT
  pcb_105->rtime = 0;
  # DEBUG BEGIN_STMT
  _48 = pcb_105->snd_wnd;
  _49 = pcb_105->cwnd;
  eff_wnd_167 = MIN_EXPR <_48, _49>;
  # DEBUG eff_wnd => eff_wnd_167
  # DEBUG BEGIN_STMT
  _50 = eff_wnd_167 >> 1;
  pcb_105->ssthresh = _50;
  # DEBUG BEGIN_STMT
  _51 = pcb_105->mss;
  _52 = _51 << 1;
  if (_50 < _52)
    goto <bb 42>; [50.00%]
  else
    goto <bb 43>; [50.00%]

  <bb 42> [local count: 65931]:
  # DEBUG BEGIN_STMT
  pcb_105->ssthresh = _52;

  <bb 43> [local count: 131862]:
  # DEBUG BEGIN_STMT
  pcb_105->cwnd = _51;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pcb_105->bytes_acked = 0;
  # DEBUG BEGIN_STMT
  tcp_rexmit_rto_commit (pcb_105);

  <bb 44> [local count: 4004100]:
  # pcb_remove_109 = PHI <1(14), 1(15), 0(24), 0(33), 0(35), 0(36), 0(43), 1(21), 0(30), 0(29), 0(28), 0(26)>
  # DEBUG next_slot => NULL
  # DEBUG pcb_remove => pcb_remove_109
  # DEBUG BEGIN_STMT
  _53 = pcb_105->state;
  if (_53 == 6)
    goto <bb 45>; [34.00%]
  else
    goto <bb 48>; [66.00%]

  <bb 45> [local count: 1361394]:
  # DEBUG BEGIN_STMT
  _54 = pcb_105->flags;
  _141 = _54 & 16;
  if (_141 != 0)
    goto <bb 46>; [50.00%]
  else
    goto <bb 48>; [50.00%]

  <bb 46> [local count: 680697]:
  # DEBUG BEGIN_STMT
  tcp_ticks.57_55 = tcp_ticks;
  _56 = pcb_105->tmr;
  _57 = tcp_ticks.57_55 - _56;
  if (_57 > 40)
    goto <bb 47>; [50.00%]
  else
    goto <bb 48>; [50.00%]

  <bb 47> [local count: 340349]:
  # DEBUG BEGIN_STMT
  pcb_remove_184 = pcb_remove_109 + 1;
  # DEBUG pcb_remove => pcb_remove_184

  <bb 48> [local count: 4004100]:
  # pcb_remove_110 = PHI <pcb_remove_109(44), pcb_remove_109(45), pcb_remove_109(46), pcb_remove_184(47)>
  # DEBUG pcb_remove => pcb_remove_110
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _58 = pcb_105->so_options;
  _145 = _58 & 8;
  if (_145 != 0)
    goto <bb 49>; [50.00%]
  else
    goto <bb 56>; [50.00%]

  <bb 49> [local count: 2002050]:
  if (_53 == 4)
    goto <bb 51>; [34.00%]
  else
    goto <bb 50>; [66.00%]

  <bb 50> [local count: 1321353]:
  if (_53 == 7)
    goto <bb 51>; [34.00%]
  else
    goto <bb 56>; [66.00%]

  <bb 51> [local count: 1129957]:
  # DEBUG BEGIN_STMT
  tcp_ticks.58_60 = tcp_ticks;
  _61 = pcb_105->tmr;
  _62 = tcp_ticks.58_60 - _61;
  _63 = pcb_105->keep_idle;
  _64 = _63 + 675000;
  _65 = _64 / 500;
  if (_62 > _65)
    goto <bb 52>; [50.00%]
  else
    goto <bb 53>; [50.00%]

  <bb 52> [local count: 564979]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pcb_remove_188 = pcb_remove_110 + 1;
  # DEBUG pcb_remove => pcb_remove_188
  # DEBUG BEGIN_STMT
  # DEBUG pcb_reset => 1
  goto <bb 56>; [100.00%]

  <bb 53> [local count: 564979]:
  # DEBUG BEGIN_STMT
  _66 = pcb_105->keep_cnt_sent;
  _67 = (long unsigned int) _66;
  _68 = _67 * 75000;
  _69 = _63 + _68;
  _70 = _69 / 500;
  if (_62 > _70)
    goto <bb 54>; [33.00%]
  else
    goto <bb 56>; [67.00%]

  <bb 54> [local count: 186443]:
  # DEBUG BEGIN_STMT
  err_186 = tcp_keepalive (pcb_105);
  # DEBUG err => err_186
  # DEBUG BEGIN_STMT
  if (err_186 == 0)
    goto <bb 55>; [50.00%]
  else
    goto <bb 56>; [50.00%]

  <bb 55> [local count: 93221]:
  # DEBUG BEGIN_STMT
  _71 = pcb_105->keep_cnt_sent;
  _72 = _71 + 1;
  pcb_105->keep_cnt_sent = _72;

  <bb 56> [local count: 4004100]:
  # pcb_remove_111 = PHI <pcb_remove_110(48), pcb_remove_110(50), pcb_remove_188(52), pcb_remove_110(53), pcb_remove_110(54), pcb_remove_110(55)>
  # pcb_reset_114 = PHI <0(48), 0(50), 1(52), 0(53), 0(54), 0(55)>
  # DEBUG pcb_reset => pcb_reset_114
  # DEBUG pcb_remove => pcb_remove_111
  # DEBUG BEGIN_STMT
  _73 = pcb_105->state;
  if (_73 == 3)
    goto <bb 57>; [34.00%]
  else
    goto <bb 59>; [66.00%]

  <bb 57> [local count: 1361394]:
  # DEBUG BEGIN_STMT
  tcp_ticks.60_74 = tcp_ticks;
  _75 = pcb_105->tmr;
  _76 = tcp_ticks.60_74 - _75;
  if (_76 > 40)
    goto <bb 58>; [50.00%]
  else
    goto <bb 59>; [50.00%]

  <bb 58> [local count: 680697]:
  # DEBUG BEGIN_STMT
  pcb_remove_189 = pcb_remove_111 + 1;
  # DEBUG pcb_remove => pcb_remove_189

  <bb 59> [local count: 4004100]:
  # pcb_remove_112 = PHI <pcb_remove_111(56), pcb_remove_111(57), pcb_remove_189(58)>
  # DEBUG pcb_remove => pcb_remove_112
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (_73 == 9)
    goto <bb 60>; [34.00%]
  else
    goto <bb 62>; [66.00%]

  <bb 60> [local count: 1361394]:
  # DEBUG BEGIN_STMT
  tcp_ticks.61_77 = tcp_ticks;
  _78 = pcb_105->tmr;
  _79 = tcp_ticks.61_77 - _78;
  if (_79 > 240)
    goto <bb 61>; [50.00%]
  else
    goto <bb 62>; [50.00%]

  <bb 61> [local count: 680697]:
  # DEBUG BEGIN_STMT
  pcb_remove_190 = pcb_remove_112 + 1;
  # DEBUG pcb_remove => pcb_remove_190

  <bb 62> [local count: 4004100]:
  # pcb_remove_113 = PHI <pcb_remove_112(59), pcb_remove_112(60), pcb_remove_190(61)>
  # DEBUG pcb_remove => pcb_remove_113
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_remove_113 != 0)
    goto <bb 63>; [33.00%]
  else
    goto <bb 76>; [67.00%]

  <bb 63> [local count: 1321353]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  err_fn_198 = pcb_105->errf;
  # DEBUG err_fn => err_fn_198
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tcp_pcb_purge (pcb_105);
  # DEBUG BEGIN_STMT
  if (prev_107 != 0B)
    goto <bb 64>; [70.00%]
  else
    goto <bb 67>; [30.00%]

  <bb 64> [local count: 924947]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tcp_active_pcbs.62_80 = tcp_active_pcbs;
  if (tcp_active_pcbs.62_80 == pcb_105)
    goto <bb 104>; [2.00%]
  else
    goto <bb 66>; [98.00%]

  <bb 104> [local count: 18499]:

  <bb 65> [local count: 184989753]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 114> [local count: 184989753]:
  goto <bb 65>; [100.00%]

  <bb 66> [local count: 906448]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _81 = pcb_105->next;
  prev_107->next = _81;
  goto <bb 70>; [100.00%]

  <bb 67> [local count: 396406]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tcp_active_pcbs.63_82 = tcp_active_pcbs;
  if (tcp_active_pcbs.63_82 != pcb_105)
    goto <bb 105>; [2.00%]
  else
    goto <bb 69>; [98.00%]

  <bb 105> [local count: 7928]:

  <bb 68> [local count: 79281323]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 115> [local count: 79281323]:
  goto <bb 68>; [100.00%]

  <bb 69> [local count: 388478]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _83 = pcb_105->next;
  tcp_active_pcbs = _83;

  <bb 70> [local count: 1294926]:
  # DEBUG BEGIN_STMT
  if (pcb_reset_114 != 0)
    goto <bb 71>; [33.00%]
  else
    goto <bb 72>; [67.00%]

  <bb 71> [local count: 427326]:
  # DEBUG BEGIN_STMT
  _84 = pcb_105->snd_nxt;
  _85 = pcb_105->rcv_nxt;
  _86 = &pcb_105->local_ip;
  _87 = &pcb_105->remote_ip;
  _88 = pcb_105->local_port;
  _89 = pcb_105->remote_port;
  tcp_rst (pcb_105, _84, _85, _86, _87, _88, _89);

  <bb 72> [local count: 1294926]:
  # DEBUG BEGIN_STMT
  err_arg_205 = pcb_105->callback_arg;
  # DEBUG err_arg => err_arg_205
  # DEBUG BEGIN_STMT
  # DEBUG D#3 => pcb_105->state
  # DEBUG last_state => D#3
  # DEBUG BEGIN_STMT
  # DEBUG pcb2 => pcb_105
  # DEBUG BEGIN_STMT
  pcb_206 = pcb_105->next;
  # DEBUG pcb => pcb_206
  # DEBUG BEGIN_STMT
  tcp_free (pcb_105);
  # DEBUG BEGIN_STMT
  tcp_active_pcbs_changed = 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (err_fn_198 != 0B)
    goto <bb 73>; [70.00%]
  else
    goto <bb 74>; [30.00%]

  <bb 73> [local count: 906448]:
  # DEBUG BEGIN_STMT
  err_fn_198 (err_arg_205, -13);

  <bb 74> [local count: 1294926]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tcp_active_pcbs_changed.64_90 = tcp_active_pcbs_changed;
  if (tcp_active_pcbs_changed.64_90 != 0)
    goto <bb 75>; [2.00%]
  else
    goto <bb 83>; [98.00%]

  <bb 75> [local count: 25899]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 3>; [100.00%]

  <bb 76> [local count: 2682747]:
  # DEBUG BEGIN_STMT
  # DEBUG prev => pcb_105
  # DEBUG BEGIN_STMT
  pcb_191 = pcb_105->next;
  # DEBUG pcb => pcb_191
  # DEBUG BEGIN_STMT
  _91 = pcb_105->polltmr;
  _92 = _91 + 1;
  pcb_105->polltmr = _92;
  # DEBUG BEGIN_STMT
  _93 = pcb_105->pollinterval;
  if (_92 >= _93)
    goto <bb 77>; [50.00%]
  else
    goto <bb 83>; [50.00%]

  <bb 77> [local count: 1341374]:
  # DEBUG BEGIN_STMT
  pcb_105->polltmr = 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tcp_active_pcbs_changed = 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _94 = pcb_105->poll;
  if (_94 != 0B)
    goto <bb 78>; [70.00%]
  else
    goto <bb 79>; [30.00%]

  <bb 78> [local count: 938962]:
  # DEBUG BEGIN_STMT
  _95 = pcb_105->callback_arg;
  err_196 = _94 (_95, pcb_105);
  # DEBUG err => err_196

  <bb 79> [local count: 1341374]:
  # err_115 = PHI <err_196(78), 0(77)>
  # DEBUG err => err_115
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tcp_active_pcbs_changed.65_96 = tcp_active_pcbs_changed;
  if (tcp_active_pcbs_changed.65_96 != 0)
    goto <bb 80>; [2.00%]
  else
    goto <bb 81>; [98.00%]

  <bb 80> [local count: 26827]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 3>; [100.00%]

  <bb 81> [local count: 1314546]:
  # DEBUG BEGIN_STMT
  if (err_115 == 0)
    goto <bb 82>; [33.00%]
  else
    goto <bb 83>; [67.00%]

  <bb 82> [local count: 433800]:
  # DEBUG BEGIN_STMT
  tcp_output (pcb_105);

  <bb 83> [local count: 4947670]:
  # pcb_177 = PHI <pcb_210(12), pcb_206(74), pcb_191(82), pcb_191(81), pcb_191(76)>
  # prev_26 = PHI <pcb_105(12), prev_107(74), pcb_105(82), pcb_105(81), pcb_105(76)>

  <bb 84> [local count: 5478265]:
  # pcb_105 = PHI <pcb_177(83), pcb_146(4)>
  # prev_107 = PHI <prev_26(83), 0B(4)>
  # DEBUG prev => prev_107
  # DEBUG pcb => pcb_105
  # DEBUG BEGIN_STMT
  if (pcb_105 != 0B)
    goto <bb 5>; [98.00%]
  else
    goto <bb 85>; [2.00%]

  <bb 85> [local count: 109565]:
  # DEBUG BEGIN_STMT
  # DEBUG prev => 0B
  # DEBUG BEGIN_STMT
  pcb_147 = tcp_tw_pcbs;
  # DEBUG pcb => pcb_147
  # DEBUG BEGIN_STMT
  goto <bb 99>; [100.00%]

  <bb 86> [local count: 1695977]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _97 = pcb_106->state;
  if (_97 != 10)
    goto <bb 108>; [2.75%]
  else
    goto <bb 88>; [97.25%]

  <bb 108> [local count: 46639]:

  <bb 87> [local count: 466394387]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 118> [local count: 466394387]:
  goto <bb 87>; [100.00%]

  <bb 88> [local count: 1649337]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG pcb_remove => 0
  # DEBUG BEGIN_STMT
  tcp_ticks.66_98 = tcp_ticks;
  _99 = pcb_106->tmr;
  _100 = tcp_ticks.66_98 - _99;
  if (_100 > 240)
    goto <bb 89>; [33.00%]
  else
    goto <bb 90>; [67.00%]

  <bb 89> [local count: 544281]:
  # DEBUG BEGIN_STMT
  # DEBUG pcb_remove => 1
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tcp_pcb_purge (pcb_106);
  # DEBUG BEGIN_STMT
  if (prev_108 != 0B)
    goto <bb 91>; [70.00%]
  else
    goto <bb 94>; [30.00%]

  <bb 90> [local count: 1105056]:
  # DEBUG pcb_remove => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG prev => pcb_106
  # DEBUG BEGIN_STMT
  pcb_149 = pcb_106->next;
  # DEBUG pcb => pcb_149
  goto <bb 98>; [100.00%]

  <bb 91> [local count: 380997]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tcp_tw_pcbs.67_101 = tcp_tw_pcbs;
  if (tcp_tw_pcbs.67_101 == pcb_106)
    goto <bb 109>; [2.75%]
  else
    goto <bb 93>; [97.25%]

  <bb 109> [local count: 10477]:

  <bb 92> [local count: 104774333]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 119> [local count: 104774333]:
  goto <bb 92>; [100.00%]

  <bb 93> [local count: 370520]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _102 = pcb_106->next;
  prev_108->next = _102;
  goto <bb 97>; [100.00%]

  <bb 94> [local count: 163284]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tcp_tw_pcbs.68_103 = tcp_tw_pcbs;
  if (tcp_tw_pcbs.68_103 != pcb_106)
    goto <bb 110>; [2.75%]
  else
    goto <bb 96>; [97.25%]

  <bb 110> [local count: 4490]:

  <bb 95> [local count: 44903286]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 120> [local count: 44903286]:
  goto <bb 95>; [100.00%]

  <bb 96> [local count: 158794]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _104 = pcb_106->next;
  tcp_tw_pcbs = _104;

  <bb 97> [local count: 529314]:
  # DEBUG BEGIN_STMT
  # DEBUG pcb2 => pcb_106
  # DEBUG BEGIN_STMT
  pcb_156 = pcb_106->next;
  # DEBUG pcb => pcb_156
  # DEBUG BEGIN_STMT
  tcp_free (pcb_106);

  <bb 98> [local count: 1634370]:
  # pcb_155 = PHI <pcb_156(97), pcb_149(90)>
  # prev_160 = PHI <prev_108(97), pcb_106(90)>

  <bb 99> [local count: 1743935]:
  # pcb_106 = PHI <pcb_155(98), pcb_147(85)>
  # prev_108 = PHI <prev_160(98), 0B(85)>
  # DEBUG prev => prev_108
  # DEBUG pcb => pcb_106
  # DEBUG BEGIN_STMT
  if (pcb_106 != 0B)
    goto <bb 86>; [97.25%]
  else
    goto <bb 100>; [2.75%]

  <bb 100> [local count: 47958]:
  return;

}



;; Function tcp_pcb_remove (tcp_pcb_remove, funcdef_no=46, decl_uid=7315, cgraph_uid=47, symbol_order=59)

Modification phase of node tcp_pcb_remove/59
tcp_pcb_remove (struct tcp_pcb * * pcblist, struct tcp_pcb * pcb)
{
  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_4(D) == 0B)
    goto <bb 7>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 7> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 9> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcblist_6(D) == 0B)
    goto <bb 8>; [30.00%]
  else
    goto <bb 6>; [70.00%]

  <bb 8> [local count: 75162]:

  <bb 5> [local count: 751619279]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 10> [local count: 751619279]:
  goto <bb 5>; [100.00%]

  <bb 6> [local count: 175377]:
  tcp_pcb_remove.part.0 (pcblist_6(D), pcb_4(D));
  return;

}



;; Function tcp_close_shutdown (tcp_close_shutdown, funcdef_no=9, decl_uid=7538, cgraph_uid=10, symbol_order=22)

Modification phase of node tcp_close_shutdown/22
tcp_close_shutdown (struct tcp_pcb * pcb, u8_t rst_on_unacked_data)
{
  struct tcp_pcb * tcp_tmp_pcb;
  struct tcp_pcb * tcp_tmp_pcb;
  tcp_state _1;
  struct pbuf * _3;
  short unsigned int _4;
  short unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  struct ip_addr_t * _8;
  struct ip_addr_t * _9;
  short unsigned int _10;
  short unsigned int _11;
  struct tcp_pcb * tcp_active_pcbs.2_12;
  struct tcp_pcb * _13;
  struct tcp_pcb * _14;
  struct tcp_pcb * _15;
  struct tcp_pcb * tcp_input_pcb.4_16;
  tcp_state _17;
  short unsigned int _18;
  struct tcp_pcb * tcp_bound_pcbs.5_19;
  struct tcp_pcb * _20;
  struct tcp_pcb * _21;
  struct tcp_pcb * _22;
  long unsigned int _23;
  long unsigned int _24;
  err_t _27;
  short unsigned int _47;
  err_t _61;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_35(D) == 0B)
    goto <bb 33>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 33> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 37> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (rst_on_unacked_data_37(D) != 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 20>; [50.00%]

  <bb 5> [local count: 125270]:
  _1 = pcb_35(D)->state;
  if (_1 == 4)
    goto <bb 7>; [34.00%]
  else
    goto <bb 6>; [66.00%]

  <bb 6> [local count: 82678]:
  if (_1 == 7)
    goto <bb 7>; [34.00%]
  else
    goto <bb 20>; [66.00%]

  <bb 7> [local count: 70702]:
  # DEBUG BEGIN_STMT
  _3 = pcb_35(D)->refused_data;
  if (_3 != 0B)
    goto <bb 9>; [70.00%]
  else
    goto <bb 8>; [30.00%]

  <bb 8> [local count: 21211]:
  _4 = pcb_35(D)->rcv_wnd;
  if (_4 != 7300)
    goto <bb 9>; [66.00%]
  else
    goto <bb 20>; [34.00%]

  <bb 9> [local count: 63491]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _5 = pcb_35(D)->flags;
  _47 = _5 & 16;
  if (_47 == 0)
    goto <bb 34>; [79.76%]
  else
    goto <bb 11>; [20.24%]

  <bb 34> [local count: 50640]:

  <bb 10> [local count: 506401690]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 38> [local count: 506401690]:
  goto <bb 10>; [100.00%]

  <bb 11> [local count: 12850]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _6 = pcb_35(D)->snd_nxt;
  _7 = pcb_35(D)->rcv_nxt;
  _8 = &pcb_35(D)->local_ip;
  _9 = &pcb_35(D)->remote_ip;
  _10 = pcb_35(D)->local_port;
  _11 = pcb_35(D)->remote_port;
  tcp_rst (pcb_35(D), _6, _7, _8, _9, _10, _11);
  # DEBUG BEGIN_STMT
  tcp_pcb_purge (pcb_35(D));
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tcp_active_pcbs.2_12 = tcp_active_pcbs;
  if (tcp_active_pcbs.2_12 == pcb_35(D))
    goto <bb 12>; [30.00%]
  else
    goto <bb 35>; [70.00%]

  <bb 12> [local count: 3855]:
  # DEBUG BEGIN_STMT
  _13 = tcp_active_pcbs.2_12->next;
  tcp_active_pcbs = _13;
  goto <bb 16>; [100.00%]

  <bb 13> [local count: 79463]:
  # DEBUG BEGIN_STMT
  _14 = tcp_tmp_pcb_25->next;
  if (_14 == pcb_35(D))
    goto <bb 14>; [5.50%]
  else
    goto <bb 39>; [94.50%]

  <bb 39> [local count: 75093]:
  goto <bb 15>; [100.00%]

  <bb 14> [local count: 4370]:
  # tcp_tmp_pcb_2 = PHI <tcp_tmp_pcb_25(13)>
  # DEBUG BEGIN_STMT
  _15 = pcb_35(D)->next;
  tcp_tmp_pcb_2->next = _15;
  # DEBUG BEGIN_STMT
  goto <bb 16>; [100.00%]

  <bb 35> [local count: 8995]:

  <bb 15> [local count: 84088]:
  # tcp_tmp_pcb_25 = PHI <tcp_active_pcbs.2_12(35), _14(39)>
  # DEBUG tcp_tmp_pcb => tcp_tmp_pcb_25
  # DEBUG BEGIN_STMT
  if (tcp_tmp_pcb_25 != 0B)
    goto <bb 13>; [94.50%]
  else
    goto <bb 16>; [5.50%]

  <bb 16> [local count: 12850]:
  # DEBUG BEGIN_STMT
  pcb_35(D)->next = 0B;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tcp_active_pcbs_changed = 1;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tcp_input_pcb.4_16 = tcp_input_pcb;
  if (tcp_input_pcb.4_16 == pcb_35(D))
    goto <bb 17>; [30.00%]
  else
    goto <bb 18>; [70.00%]

  <bb 17> [local count: 3855]:
  # DEBUG BEGIN_STMT
  tcp_trigger_input_pcb_close ();
  goto <bb 19>; [100.00%]

  <bb 18> [local count: 8995]:
  # DEBUG BEGIN_STMT
  tcp_free (pcb_35(D));

  <bb 19> [local count: 12850]:
  # DEBUG BEGIN_STMT
  goto <bb 32>; [100.00%]

  <bb 20> [local count: 187049]:
  # DEBUG BEGIN_STMT
  _17 = pcb_35(D)->state;
  switch (_17) <default: <L38> [25.00%], case 0: <L25> [25.00%], case 1: <L36> [25.00%], case 2: <L37> [25.00%]>

  <bb 21> [local count: 46762]:
<L25>:
  # DEBUG BEGIN_STMT
  _18 = pcb_35(D)->local_port;
  if (_18 != 0)
    goto <bb 22>; [50.00%]
  else
    goto <bb 28>; [50.00%]

  <bb 22> [local count: 23381]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tcp_bound_pcbs.5_19 = tcp_bound_pcbs;
  if (tcp_bound_pcbs.5_19 == pcb_35(D))
    goto <bb 23>; [30.00%]
  else
    goto <bb 36>; [70.00%]

  <bb 23> [local count: 7014]:
  # DEBUG BEGIN_STMT
  _20 = tcp_bound_pcbs.5_19->next;
  tcp_bound_pcbs = _20;
  goto <bb 27>; [100.00%]

  <bb 24> [local count: 144581]:
  # DEBUG BEGIN_STMT
  _21 = tcp_tmp_pcb_26->next;
  if (_21 == pcb_35(D))
    goto <bb 25>; [5.50%]
  else
    goto <bb 40>; [94.50%]

  <bb 40> [local count: 136629]:
  goto <bb 26>; [100.00%]

  <bb 25> [local count: 7952]:
  # tcp_tmp_pcb_40 = PHI <tcp_tmp_pcb_26(24)>
  # DEBUG BEGIN_STMT
  _22 = pcb_35(D)->next;
  tcp_tmp_pcb_40->next = _22;
  # DEBUG BEGIN_STMT
  goto <bb 27>; [100.00%]

  <bb 36> [local count: 16367]:

  <bb 26> [local count: 152996]:
  # tcp_tmp_pcb_26 = PHI <tcp_bound_pcbs.5_19(36), _21(40)>
  # DEBUG tcp_tmp_pcb => tcp_tmp_pcb_26
  # DEBUG BEGIN_STMT
  if (tcp_tmp_pcb_26 != 0B)
    goto <bb 24>; [94.50%]
  else
    goto <bb 27>; [5.50%]

  <bb 27> [local count: 23381]:
  # DEBUG BEGIN_STMT
  pcb_35(D)->next = 0B;

  <bb 28> [local count: 46762]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tcp_free (pcb_35(D));
  # DEBUG BEGIN_STMT
  goto <bb 32>; [100.00%]

  <bb 29> [local count: 46762]:
<L36>:
  # DEBUG BEGIN_STMT
  tcp_listen_closed (pcb_35(D));
  # DEBUG BEGIN_STMT
  tcp_pcb_remove (&tcp_listen_pcbs.pcbs, pcb_35(D));
  # DEBUG BEGIN_STMT
  tcp_free_listen (pcb_35(D));
  # DEBUG BEGIN_STMT
  goto <bb 32>; [100.00%]

  <bb 30> [local count: 46762]:
<L37>:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tcp_pcb_remove (&tcp_active_pcbs, pcb_35(D));
  # DEBUG BEGIN_STMT
  tcp_active_pcbs_changed = 1;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tcp_free (pcb_35(D));
  # DEBUG BEGIN_STMT
  _23 = lwip_stats.mib2.tcpattemptfails;
  _24 = _23 + 1;
  lwip_stats.mib2.tcpattemptfails = _24;
  # DEBUG BEGIN_STMT
  goto <bb 32>; [100.00%]

  <bb 31> [local count: 46762]:
<L38>:
  # DEBUG BEGIN_STMT
  _61 = tcp_close_shutdown_fin (pcb_35(D));

  <bb 32> [local count: 199899]:
  # _27 = PHI <0(19), _61(31), 0(29), 0(28), 0(30)>
  return _27;

}



;; Function tcp_close (tcp_close, funcdef_no=11, decl_uid=7228, cgraph_uid=12, symbol_order=24)

Modification phase of node tcp_close/24
tcp_close (struct tcp_pcb * pcb)
{
  tcp_state _1;
  short unsigned int _2;
  short unsigned int _3;
  err_t _4;
  err_t _11;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_7(D) == 0B)
    goto <bb 6>; [0.45%]
  else
    goto <bb 3>; [99.55%]

  <bb 3> [local count: 1068909987]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pcb_7(D)->state;
  if (_1 != 1)
    goto <bb 4>; [66.00%]
  else
    goto <bb 5>; [34.00%]

  <bb 4> [local count: 705480592]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = pcb_7(D)->flags;
  _3 = _2 | 16;
  pcb_7(D)->flags = _3;

  <bb 5> [local count: 1068909987]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _11 = tcp_close_shutdown (pcb_7(D), 1);

  <bb 6> [local count: 1073741824]:
  # _4 = PHI <-16(2), _11(5)>
  return _4;

}



;; Function tcp_recv_null (tcp_recv_null, funcdef_no=31, decl_uid=7357, cgraph_uid=32, symbol_order=44)

Modification phase of node tcp_recv_null/44
tcp_recv_null (void * arg, struct tcp_pcb * pcb, struct pbuf * p, err_t err)
{
  short unsigned int _1;
  err_t _2;
  signed char _10;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_4(D) == 0B)
    goto <bb 6>; [0.45%]
  else
    goto <bb 3>; [99.55%]

  <bb 3> [local count: 1068909987]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (p_5(D) != 0B)
    goto <bb 4>; [53.47%]
  else
    goto <bb 5>; [46.53%]

  <bb 4> [local count: 571546170]:
  # DEBUG BEGIN_STMT
  _1 = p_5(D)->tot_len;
  tcp_recved (pcb_4(D), _1);
  # DEBUG BEGIN_STMT
  pbuf_free (p_5(D));
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 497363818]:
  # DEBUG D#4 => arg_3(D)
  # DEBUG D#5 => p_5(D)
  _10 = tcp_recv_null.part.0 (pcb_4(D), err_6(D));

  <bb 6> [local count: 1073741824]:
  # _2 = PHI <-16(2), _10(5), 0(4)>
  return _2;

}



;; Function tcp_process_refused_data (tcp_process_refused_data, funcdef_no=27, decl_uid=7292, cgraph_uid=28, symbol_order=40)

Modification phase of node tcp_process_refused_data/40
tcp_process_refused_data (struct tcp_pcb * pcb)
{
  u8_t refused_flags;
  err_t err;
  struct pbuf * _1;
  err_t (*<T744>) (void *, struct tcp_pcb *, struct pbuf *, err_t) _2;
  void * _3;
  signed char _4;
  err_t _8;
  unsigned char _19;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_10(D) == 0B)
    goto <bb 11>; [0.45%]
  else
    goto <bb 3>; [99.55%]

  <bb 3> [local count: 1068909985]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pcb_10(D)->refused_data;
  refused_flags_12 = _1->flags;
  # DEBUG refused_flags => refused_flags_12
  # DEBUG BEGIN_STMT
  # DEBUG refused_data => _1
  # DEBUG BEGIN_STMT
  pcb_10(D)->refused_data = 0B;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = pcb_10(D)->recv;
  if (_2 != 0B)
    goto <bb 4>; [82.57%]
  else
    goto <bb 5>; [17.43%]

  <bb 4> [local count: 882598975]:
  # DEBUG BEGIN_STMT
  _3 = pcb_10(D)->callback_arg;
  err_17 = _2 (_3, pcb_10(D), _1, 0);
  # DEBUG err => err_17
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 186311010]:
  # DEBUG BEGIN_STMT
  err_15 = tcp_recv_null (0B, pcb_10(D), _1, 0);
  # DEBUG err => err_15

  <bb 6> [local count: 1068909986]:
  # err_7 = PHI <err_17(4), err_15(5)>
  # DEBUG err => err_7
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (err_7 == 0)
    goto <bb 7>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 7> [local count: 534454993]:
  # DEBUG BEGIN_STMT
  _19 = refused_flags_12 & 32;
  if (_19 != 0)
    goto <bb 8>; [50.00%]
  else
    goto <bb 11>; [50.00%]

  <bb 8> [local count: 267227497]:
  _4 = tcp_process_refused_data.part.0 (pcb_10(D));
  goto <bb 11>; [100.00%]

  <bb 9> [local count: 534454993]:
  # DEBUG BEGIN_STMT
  if (err_7 == -13)
    goto <bb 11>; [34.00%]
  else
    goto <bb 10>; [66.00%]

  <bb 10> [local count: 352740296]:
  # DEBUG BEGIN_STMT
  pcb_10(D)->refused_data = _1;
  # DEBUG BEGIN_STMT

  <bb 11> [local count: 1073741824]:
  # _8 = PHI <-16(2), _4(8), -13(9), -5(10), 0(7)>
  # DEBUG err => NULL
  return _8;

}



;; Function tcp_fasttmr (tcp_fasttmr, funcdef_no=25, decl_uid=7264, cgraph_uid=26, symbol_order=38)

Modification phase of node tcp_fasttmr/38
tcp_fasttmr ()
{
  struct tcp_pcb * next;
  struct tcp_pcb * pcb;
  unsigned char tcp_timer_ctr.69_1;
  unsigned char _2;
  unsigned char _3;
  unsigned char tcp_timer_ctr.70_4;
  short unsigned int _5;
  short unsigned int _7;
  short unsigned int _8;
  short unsigned int _9;
  short unsigned int _10;
  short unsigned int _11;
  struct pbuf * _12;
  unsigned char tcp_active_pcbs_changed.72_13;
  short unsigned int _33;
  short unsigned int _34;

  <bb 2> [local count: 59055800]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tcp_timer_ctr.69_1 = tcp_timer_ctr;
  _2 = tcp_timer_ctr.69_1 + 1;
  tcp_timer_ctr = _2;

  <bb 3> [local count: 78750460]:
tcp_fasttmr_start:
  # DEBUG BEGIN_STMT
  pcb_22 = tcp_active_pcbs;
  # DEBUG pcb => pcb_22
  # DEBUG BEGIN_STMT
  goto <bb 14>; [100.00%]

  <bb 4> [local count: 1014686023]:
  # DEBUG BEGIN_STMT
  _3 = pcb_14->last_timer;
  tcp_timer_ctr.70_4 = tcp_timer_ctr;
  if (_3 != tcp_timer_ctr.70_4)
    goto <bb 5>; [66.00%]
  else
    goto <bb 12>; [34.00%]

  <bb 5> [local count: 669692776]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pcb_14->last_timer = tcp_timer_ctr.70_4;
  # DEBUG BEGIN_STMT
  _5 = pcb_14->flags;
  _33 = _5 & 1;
  if (_33 != 0)
    goto <bb 6>; [33.00%]
  else
    goto <bb 7>; [67.00%]

  <bb 6> [local count: 220998616]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _7 = _5 | 2;
  pcb_14->flags = _7;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tcp_output (pcb_14);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _8 = pcb_14->flags;
  _9 = _8 & 65532;
  pcb_14->flags = _9;

  <bb 7> [local count: 669692776]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _10 = pcb_14->flags;
  _34 = _10 & 8;
  if (_34 != 0)
    goto <bb 8>; [33.00%]
  else
    goto <bb 9>; [67.00%]

  <bb 8> [local count: 220998616]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _11 = _10 & 65527;
  pcb_14->flags = _11;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tcp_close_shutdown_fin (pcb_14);

  <bb 9> [local count: 669692776]:
  # DEBUG BEGIN_STMT
  next_30 = pcb_14->next;
  # DEBUG next => next_30
  # DEBUG BEGIN_STMT
  _12 = pcb_14->refused_data;
  if (_12 != 0B)
    goto <bb 10>; [53.47%]
  else
    goto <bb 13>; [46.53%]

  <bb 10> [local count: 358084727]:
  # DEBUG BEGIN_STMT
  tcp_active_pcbs_changed = 0;
  # DEBUG BEGIN_STMT
  tcp_process_refused_data (pcb_14);
  # DEBUG BEGIN_STMT
  tcp_active_pcbs_changed.72_13 = tcp_active_pcbs_changed;
  if (tcp_active_pcbs_changed.72_13 != 0)
    goto <bb 11>; [5.50%]
  else
    goto <bb 13>; [94.50%]

  <bb 11> [local count: 19694660]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 3>; [100.00%]

  <bb 12> [local count: 344993248]:
  # DEBUG BEGIN_STMT
  pcb_23 = pcb_14->next;
  # DEBUG pcb => pcb_23

  <bb 13> [local count: 994991364]:
  # pcb_18 = PHI <next_30(10), next_30(9), pcb_23(12)>

  <bb 14> [local count: 1073741824]:
  # pcb_14 = PHI <pcb_18(13), pcb_22(3)>
  # DEBUG pcb => pcb_14
  # DEBUG BEGIN_STMT
  if (pcb_14 != 0B)
    goto <bb 4>; [94.50%]
  else
    goto <bb 15>; [5.50%]

  <bb 15> [local count: 59055800]:
  return;

}



;; Function tcp_tmr (tcp_tmr, funcdef_no=4, decl_uid=7260, cgraph_uid=5, symbol_order=17)

Modification phase of node tcp_tmr/17
tcp_tmr ()
{
  unsigned char tcp_timer.0_1;
  unsigned char _2;
  unsigned char _8;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  tcp_fasttmr ();
  # DEBUG BEGIN_STMT
  tcp_timer.0_1 = tcp_timer;
  _2 = tcp_timer.0_1 + 1;
  tcp_timer = _2;
  _8 = _2 & 1;
  if (_8 != 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  tcp_slowtmr ();

  <bb 4> [local count: 1073741824]:
  return;

}



;; Function tcp_shutdown (tcp_shutdown, funcdef_no=12, decl_uid=7232, cgraph_uid=13, symbol_order=25)

Modification phase of node tcp_shutdown/25
tcp_shutdown (struct tcp_pcb * pcb, int shut_rx, int shut_tx)
{
  tcp_state _1;
  short unsigned int _2;
  short unsigned int _3;
  struct pbuf * _4;
  tcp_state _5;
  unsigned char _6;
  err_t _7;
  err_t _18;
  err_t _20;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_10(D) == 0B)
    goto <bb 12>; [0.45%]
  else
    goto <bb 3>; [99.55%]

  <bb 3> [local count: 1068909985]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pcb_10(D)->state;
  if (_1 == 1)
    goto <bb 12>; [0.54%]
  else
    goto <bb 4>; [99.46%]

  <bb 4> [local count: 1063137870]:
  # DEBUG BEGIN_STMT
  if (shut_rx_12(D) != 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 5> [local count: 531568935]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = pcb_10(D)->flags;
  _3 = _2 | 16;
  pcb_10(D)->flags = _3;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (shut_tx_14(D) != 0)
    goto <bb 6>; [20.24%]
  else
    goto <bb 7>; [79.76%]

  <bb 6> [local count: 107589552]:
  # DEBUG BEGIN_STMT
  _18 = tcp_close_shutdown (pcb_10(D), 1);
  goto <bb 12>; [100.00%]

  <bb 7> [local count: 423979382]:
  # DEBUG BEGIN_STMT
  _4 = pcb_10(D)->refused_data;
  if (_4 != 0B)
    goto <bb 8>; [53.47%]
  else
    goto <bb 9>; [46.53%]

  <bb 8> [local count: 226701775]:
  # DEBUG BEGIN_STMT
  pbuf_free (_4);
  # DEBUG BEGIN_STMT
  pcb_10(D)->refused_data = 0B;

  <bb 9> [local count: 955548318]:
  # DEBUG BEGIN_STMT
  if (shut_tx_14(D) != 0)
    goto <bb 10>; [50.00%]
  else
    goto <bb 12>; [50.00%]

  <bb 10> [local count: 477774159]:
  # DEBUG BEGIN_STMT
  _5 = pcb_10(D)->state;
  switch (_5) <default: <L17> [3.98%], case 3 ... 4: <L11> [96.02%], case 7: <L11> [96.02%]>

  <bb 11> [local count: 458758748]:
<L11>:
  # DEBUG BEGIN_STMT
  _6 = (unsigned char) shut_rx_12(D);
  _20 = tcp_close_shutdown (pcb_10(D), _6);

  <bb 12> [local count: 1073741824]:
  # _7 = PHI <-16(2), -11(3), _18(6), _20(11), -11(10), 0(9)>
<L17>:
  return _7;

}



;; Function tcp_abandon (tcp_abandon, funcdef_no=13, decl_uid=7276, cgraph_uid=14, symbol_order=26)

Modification phase of node tcp_abandon/26
tcp_abandon (struct tcp_pcb * pcb, int reset)
{
  struct tcp_pcb * tcp_tmp_pcb;
  u16_t local_port;
  int send_rst;
  void * errf_arg;
  void (*tcp_err_fn) (void *, err_t) errf;
  u32_t ackno;
  u32_t seqno;
  tcp_state _1;
  short unsigned int _3;
  struct tcp_pcb * tcp_bound_pcbs.7_4;
  struct tcp_pcb * _5;
  struct tcp_pcb * _6;
  struct tcp_pcb * _7;
  struct tcp_seg * _8;
  struct tcp_seg * _9;
  struct ip_addr_t * _10;
  struct ip_addr_t * _11;
  short unsigned int _12;

  <bb 2> [local count: 385552]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_23(D) == 0B)
    goto <bb 24>; [18.09%]
  else
    goto <bb 3>; [81.91%]

  <bb 3> [local count: 315806]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pcb_23(D)->state;
  if (_1 == 1)
    goto <bb 25>; [34.00%]
  else
    goto <bb 5>; [66.00%]

  <bb 25> [local count: 107374]:

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 27> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 208432]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (_1 == 10)
    goto <bb 6>; [20.24%]
  else
    goto <bb 7>; [79.76%]

  <bb 6> [local count: 42187]:
  # DEBUG BEGIN_STMT
  tcp_pcb_remove (&tcp_tw_pcbs, pcb_23(D));
  # DEBUG BEGIN_STMT
  tcp_free (pcb_23(D));
  goto <bb 24>; [100.00%]

  <bb 7> [local count: 166245]:
  # DEBUG BEGIN_STMT
  # DEBUG send_rst => 0
  # DEBUG BEGIN_STMT
  # DEBUG local_port => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  seqno_25 = pcb_23(D)->snd_nxt;
  # DEBUG seqno => seqno_25
  # DEBUG BEGIN_STMT
  ackno_26 = pcb_23(D)->rcv_nxt;
  # DEBUG ackno => ackno_26
  # DEBUG BEGIN_STMT
  errf_27 = pcb_23(D)->errf;
  # DEBUG errf => errf_27
  # DEBUG BEGIN_STMT
  errf_arg_28 = pcb_23(D)->callback_arg;
  # DEBUG errf_arg => errf_arg_28
  # DEBUG BEGIN_STMT
  if (_1 == 0)
    goto <bb 8>; [67.00%]
  else
    goto <bb 15>; [33.00%]

  <bb 8> [local count: 111384]:
  # DEBUG BEGIN_STMT
  _3 = pcb_23(D)->local_port;
  if (_3 != 0)
    goto <bb 9>; [50.00%]
  else
    goto <bb 16>; [50.00%]

  <bb 9> [local count: 55692]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tcp_bound_pcbs.7_4 = tcp_bound_pcbs;
  if (tcp_bound_pcbs.7_4 == pcb_23(D))
    goto <bb 10>; [30.00%]
  else
    goto <bb 26>; [70.00%]

  <bb 10> [local count: 16708]:
  # DEBUG BEGIN_STMT
  _5 = tcp_bound_pcbs.7_4->next;
  tcp_bound_pcbs = _5;
  goto <bb 14>; [100.00%]

  <bb 11> [local count: 344383]:
  # DEBUG BEGIN_STMT
  _6 = tcp_tmp_pcb_15->next;
  if (_6 == pcb_23(D))
    goto <bb 12>; [5.50%]
  else
    goto <bb 28>; [94.50%]

  <bb 28> [local count: 325442]:
  goto <bb 13>; [100.00%]

  <bb 12> [local count: 18941]:
  # tcp_tmp_pcb_2 = PHI <tcp_tmp_pcb_15(11)>
  # DEBUG BEGIN_STMT
  _7 = pcb_23(D)->next;
  tcp_tmp_pcb_2->next = _7;
  # DEBUG BEGIN_STMT
  goto <bb 14>; [100.00%]

  <bb 26> [local count: 38984]:

  <bb 13> [local count: 364426]:
  # tcp_tmp_pcb_15 = PHI <tcp_bound_pcbs.7_4(26), _6(28)>
  # DEBUG tcp_tmp_pcb => tcp_tmp_pcb_15
  # DEBUG BEGIN_STMT
  if (tcp_tmp_pcb_15 != 0B)
    goto <bb 11>; [94.50%]
  else
    goto <bb 14>; [5.50%]

  <bb 14> [local count: 55692]:
  # DEBUG BEGIN_STMT
  pcb_23(D)->next = 0B;
  goto <bb 16>; [100.00%]

  <bb 15> [local count: 54861]:
  # DEBUG BEGIN_STMT
  # DEBUG send_rst => reset_29(D)
  # DEBUG BEGIN_STMT
  local_port_30 = pcb_23(D)->local_port;
  # DEBUG local_port => local_port_30
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tcp_pcb_remove (&tcp_active_pcbs, pcb_23(D));
  # DEBUG BEGIN_STMT
  tcp_active_pcbs_changed = 1;

  <bb 16> [local count: 166245]:
  # send_rst_13 = PHI <0(14), reset_29(D)(15), 0(8)>
  # local_port_14 = PHI <0(14), local_port_30(15), 0(8)>
  # DEBUG local_port => local_port_14
  # DEBUG send_rst => send_rst_13
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _8 = pcb_23(D)->unacked;
  if (_8 != 0B)
    goto <bb 17>; [53.47%]
  else
    goto <bb 18>; [46.53%]

  <bb 17> [local count: 88891]:
  # DEBUG BEGIN_STMT
  tcp_segs_free (_8);

  <bb 18> [local count: 166245]:
  # DEBUG BEGIN_STMT
  _9 = pcb_23(D)->unsent;
  if (_9 != 0B)
    goto <bb 19>; [53.47%]
  else
    goto <bb 20>; [46.53%]

  <bb 19> [local count: 88891]:
  # DEBUG BEGIN_STMT
  tcp_segs_free (_9);

  <bb 20> [local count: 166245]:
  # DEBUG BEGIN_STMT
  tcp_backlog_accepted (pcb_23(D));
  # DEBUG BEGIN_STMT
  if (send_rst_13 != 0)
    goto <bb 21>; [33.00%]
  else
    goto <bb 22>; [67.00%]

  <bb 21> [local count: 54861]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _10 = &pcb_23(D)->local_ip;
  _11 = &pcb_23(D)->remote_ip;
  _12 = pcb_23(D)->remote_port;
  tcp_rst (pcb_23(D), seqno_25, ackno_26, _10, _11, local_port_14, _12);

  <bb 22> [local count: 166245]:
  # DEBUG BEGIN_STMT
  # DEBUG D#8 => pcb_23(D)->state
  # DEBUG last_state => D#8
  # DEBUG BEGIN_STMT
  tcp_free (pcb_23(D));
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (errf_27 != 0B)
    goto <bb 23>; [70.00%]
  else
    goto <bb 24>; [30.00%]

  <bb 23> [local count: 116372]:
  # DEBUG BEGIN_STMT
  errf_27 (errf_arg_28, -13);

  <bb 24> [local count: 278178]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function tcp_abort (tcp_abort, funcdef_no=14, decl_uid=7226, cgraph_uid=15, symbol_order=27)

Modification phase of node tcp_abort/27
tcp_abort (struct tcp_pcb * pcb)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  tcp_abandon (pcb_2(D), 1);
  return;

}



;; Function tcp_accept_null (tcp_accept_null, funcdef_no=17, decl_uid=7619, cgraph_uid=18, symbol_order=30)

Modification phase of node tcp_accept_null/30
tcp_accept_null (void * arg, struct tcp_pcb * pcb, err_t err)
{
  <bb 2> [local count: 230763]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_2(D) == 0B)
    goto <bb 5>; [46.53%]
  else
    goto <bb 4>; [53.47%]

  <bb 5> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 123389]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tcp_abort (pcb_2(D));
  # DEBUG BEGIN_STMT
  return -13;

}



;; Function tcp_netif_ip_addr_changed_pcblist (tcp_netif_ip_addr_changed_pcblist, funcdef_no=49, decl_uid=7868, cgraph_uid=50, symbol_order=62)

Modification phase of node tcp_netif_ip_addr_changed_pcblist/62
tcp_netif_ip_addr_changed_pcblist (const struct ip_addr_t * old_addr, struct tcp_pcb * pcb_list)
{
  struct tcp_pcb * pcb;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG pcb => pcb_list_5(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (old_addr_6(D) == 0B)
    goto <bb 5>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 5> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # pcb_1 = PHI <pcb_list_5(D)(2)>
  tcp_netif_ip_addr_changed_pcblist.part.0 (old_addr_6(D), pcb_list_5(D));
  return;

}



;; Function tcp_kill_state (tcp_kill_state, funcdef_no=33, decl_uid=7769, cgraph_uid=34, symbol_order=46)

Modification phase of node tcp_kill_state/46
Adjusting mask for param 0 to 0x1
Setting value range of param 0 [8, 9]
tcp_kill_state (tcp_state state)
{
  unsigned char _1;

  <bb 2> [local count: 181990]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = state_4(D) + 248;
  if (_1 > 1)
    goto <bb 5>; [59.00%]
  else
    goto <bb 4>; [41.00%]

  <bb 5> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 74616]:
  tcp_kill_state.part.0 (state_4(D));
  return;

}



;; Function tcp_alloc (tcp_alloc, funcdef_no=36, decl_uid=7271, cgraph_uid=37, symbol_order=49)

Modification phase of node tcp_alloc/49
tcp_alloc (u8_t prio)
{
  struct tcp_pcb * pcb;
  struct stats_mem * _1;
  short unsigned int _2;
  short unsigned int _3;
  struct stats_mem * _4;
  short unsigned int _5;
  short unsigned int _6;
  struct stats_mem * _7;
  short unsigned int _8;
  short unsigned int _9;
  struct stats_mem * _10;
  short unsigned int _11;
  short unsigned int _12;
  long unsigned int tcp_ticks.73_13;
  unsigned char tcp_timer_ctr.74_14;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pcb_26 = memp_malloc (2);
  # DEBUG pcb => pcb_26
  # DEBUG BEGIN_STMT
  if (pcb_26 == 0B)
    goto <bb 3>; [17.43%]
  else
    goto <bb 14>; [82.57%]

  <bb 3> [local count: 187153200]:
  # DEBUG BEGIN_STMT
  tcp_handle_closepend ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tcp_kill_timewait ();
  # DEBUG BEGIN_STMT
  pcb_30 = memp_malloc (2);
  # DEBUG pcb => pcb_30
  # DEBUG BEGIN_STMT
  if (pcb_30 == 0B)
    goto <bb 4>; [17.43%]
  else
    goto <bb 12>; [82.57%]

  <bb 4> [local count: 32620803]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tcp_kill_state (9);
  # DEBUG BEGIN_STMT
  pcb_33 = memp_malloc (2);
  # DEBUG pcb => pcb_33
  # DEBUG BEGIN_STMT
  if (pcb_33 == 0B)
    goto <bb 5>; [17.43%]
  else
    goto <bb 10>; [82.57%]

  <bb 5> [local count: 5685806]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tcp_kill_state (8);
  # DEBUG BEGIN_STMT
  pcb_36 = memp_malloc (2);
  # DEBUG pcb => pcb_36
  # DEBUG BEGIN_STMT
  if (pcb_36 == 0B)
    goto <bb 6>; [17.43%]
  else
    goto <bb 8>; [82.57%]

  <bb 6> [local count: 991036]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tcp_kill_prio (prio_37(D));
  # DEBUG BEGIN_STMT
  pcb_40 = memp_malloc (2);
  # DEBUG pcb => pcb_40
  # DEBUG BEGIN_STMT
  if (pcb_40 != 0B)
    goto <bb 7>; [70.00%]
  else
    goto <bb 8>; [30.00%]

  <bb 7> [local count: 693725]:
  # DEBUG BEGIN_STMT
  _1 = lwip_stats.memp[2];
  _2 = _1->err;
  _3 = _2 + 65535;
  _1->err = _3;

  <bb 8> [local count: 5685806]:
  # pcb_15 = PHI <pcb_36(5), pcb_40(6), pcb_40(7)>
  # DEBUG pcb => pcb_15
  # DEBUG BEGIN_STMT
  if (pcb_15 != 0B)
    goto <bb 9>; [70.00%]
  else
    goto <bb 10>; [30.00%]

  <bb 9> [local count: 3980064]:
  # DEBUG BEGIN_STMT
  _4 = lwip_stats.memp[2];
  _5 = _4->err;
  _6 = _5 + 65535;
  _4->err = _6;

  <bb 10> [local count: 32620803]:
  # pcb_16 = PHI <pcb_33(4), pcb_15(8), pcb_15(9)>
  # DEBUG pcb => pcb_16
  # DEBUG BEGIN_STMT
  if (pcb_16 != 0B)
    goto <bb 11>; [70.00%]
  else
    goto <bb 12>; [30.00%]

  <bb 11> [local count: 22834562]:
  # DEBUG BEGIN_STMT
  _7 = lwip_stats.memp[2];
  _8 = _7->err;
  _9 = _8 + 65535;
  _7->err = _9;

  <bb 12> [local count: 187153200]:
  # pcb_17 = PHI <pcb_30(3), pcb_16(10), pcb_16(11)>
  # DEBUG pcb => pcb_17
  # DEBUG BEGIN_STMT
  if (pcb_17 != 0B)
    goto <bb 13>; [70.00%]
  else
    goto <bb 14>; [30.00%]

  <bb 13> [local count: 131007240]:
  # DEBUG BEGIN_STMT
  _10 = lwip_stats.memp[2];
  _11 = _10->err;
  _12 = _11 + 65535;
  _10->err = _12;

  <bb 14> [local count: 1073741824]:
  # pcb_18 = PHI <pcb_26(2), pcb_17(12), pcb_17(13)>
  # DEBUG pcb => pcb_18
  # DEBUG BEGIN_STMT
  if (pcb_18 != 0B)
    goto <bb 15>; [53.47%]
  else
    goto <bb 16>; [46.53%]

  <bb 15> [local count: 574129754]:
  # DEBUG BEGIN_STMT
  memset (pcb_18, 0, 192);
  # DEBUG BEGIN_STMT
  pcb_18->prio = prio_37(D);
  # DEBUG BEGIN_STMT
  pcb_18->snd_buf = 7300;
  # DEBUG BEGIN_STMT
  pcb_18->rcv_ann_wnd = 7300;
  pcb_18->rcv_wnd = 7300;
  # DEBUG BEGIN_STMT
  pcb_18->ttl = 255;
  # DEBUG BEGIN_STMT
  pcb_18->mss = 536;
  # DEBUG BEGIN_STMT
  pcb_18->rto = 6;
  # DEBUG BEGIN_STMT
  pcb_18->sv = 6;
  # DEBUG BEGIN_STMT
  pcb_18->rtime = -1;
  # DEBUG BEGIN_STMT
  pcb_18->cwnd = 1;
  # DEBUG BEGIN_STMT
  tcp_ticks.73_13 = tcp_ticks;
  pcb_18->tmr = tcp_ticks.73_13;
  # DEBUG BEGIN_STMT
  tcp_timer_ctr.74_14 = tcp_timer_ctr;
  pcb_18->last_timer = tcp_timer_ctr.74_14;
  # DEBUG BEGIN_STMT
  pcb_18->ssthresh = 7300;
  # DEBUG BEGIN_STMT
  pcb_18->recv = tcp_recv_null;
  # DEBUG BEGIN_STMT
  pcb_18->keep_idle = 7200000;

  <bb 16> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return pcb_18;

}



;; Function tcp_new (tcp_new, funcdef_no=37, decl_uid=7177, cgraph_uid=38, symbol_order=50)

Modification phase of node tcp_new/50
tcp_new ()
{
  struct tcp_pcb * _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _3 = tcp_alloc (64);
  return _3;

}



;; Function tcp_new_ip_type (tcp_new_ip_type, funcdef_no=38, decl_uid=7179, cgraph_uid=39, symbol_order=51)

Modification phase of node tcp_new_ip_type/51
tcp_new_ip_type (u8_t type)
{
  struct tcp_pcb * pcb;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pcb_4 = tcp_alloc (64);
  # DEBUG pcb => pcb_4
  # DEBUG BEGIN_STMT
  if (pcb_4 != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 4>; [30.00%]

  <bb 3> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pcb_4->local_ip.type = type_5(D);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pcb_4->remote_ip.type = type_5(D);

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return pcb_4;

}



;; Function tcp_next_iss (tcp_next_iss, funcdef_no=47, decl_uid=7339, cgraph_uid=48, symbol_order=60)

Modification phase of node tcp_next_iss/60
tcp_next_iss (struct tcp_pcb * pcb)
{
  static u32_t iss = 6510;
  long unsigned int iss.84_1;
  long unsigned int tcp_ticks.85_2;
  long unsigned int _3;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_5(D) == 0B)
    goto <bb 5>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 5> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  iss.84_1 = iss;
  tcp_ticks.85_2 = tcp_ticks;
  _3 = iss.84_1 + tcp_ticks.85_2;
  iss = _3;
  # DEBUG BEGIN_STMT
  return _3;

}



;; Function tcp_eff_send_mss_netif (tcp_eff_send_mss_netif, funcdef_no=48, decl_uid=7352, cgraph_uid=49, symbol_order=61)

Modification phase of node tcp_eff_send_mss_netif/61
tcp_eff_send_mss_netif (u16_t sendmss, struct netif * outif, const struct ip_addr_t * dest)
{
  u16_t offset;
  u16_t mtu;
  unsigned char _1;
  const struct ip6_addr_t * _2;
  unsigned char _3;
  u16_t _6;
  u16_t iftmp.86_7;
  u16_t iftmp.86_18;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (dest_11(D) == 0B)
    goto <bb 15>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 15> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 16> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = dest_11(D)->type;
  if (_1 == 6)
    goto <bb 5>; [20.24%]
  else
    goto <bb 6>; [79.76%]

  <bb 5> [local count: 50709]:
  # DEBUG BEGIN_STMT
  _2 = &dest_11(D)->u_addr.ip6;
  mtu_15 = nd6_get_destination_mtu (_2, outif_13(D));
  # DEBUG mtu => mtu_15
  goto <bb 8>; [100.00%]

  <bb 6> [local count: 199830]:
  # DEBUG BEGIN_STMT
  if (outif_13(D) == 0B)
    goto <bb 14>; [18.09%]
  else
    goto <bb 7>; [81.91%]

  <bb 7> [local count: 163681]:
  # DEBUG BEGIN_STMT
  mtu_16 = outif_13(D)->mtu;
  # DEBUG mtu => mtu_16

  <bb 8> [local count: 214390]:
  # mtu_4 = PHI <mtu_15(5), mtu_16(7)>
  # DEBUG mtu => mtu_4
  # DEBUG BEGIN_STMT
  if (mtu_4 != 0)
    goto <bb 9>; [50.00%]
  else
    goto <bb 14>; [50.00%]

  <bb 9> [local count: 107195]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = dest_11(D)->type;
  if (_3 == 6)
    goto <bb 11>; [34.00%]
  else
    goto <bb 10>; [66.00%]

  <bb 10> [local count: 70749]:
  # DEBUG BEGIN_STMT
  # DEBUG offset => 40

  <bb 11> [local count: 107195]:
  # offset_5 = PHI <60(9), 40(10)>
  # DEBUG offset => offset_5
  # DEBUG BEGIN_STMT
  if (mtu_4 > offset_5)
    goto <bb 12>; [50.00%]
  else
    goto <bb 13>; [50.00%]

  <bb 12> [local count: 53598]:
  iftmp.86_18 = mtu_4 - offset_5;

  <bb 13> [local count: 107195]:
  # iftmp.86_7 = PHI <iftmp.86_18(12), 0(11)>
  # DEBUG mss_s => iftmp.86_7
  # DEBUG BEGIN_STMT
  sendmss_19 = MIN_EXPR <iftmp.86_7, sendmss_17(D)>;
  # DEBUG sendmss => sendmss_19

  <bb 14> [local count: 250539]:
  # _6 = PHI <sendmss_17(D)(6), sendmss_19(13), sendmss_17(D)(8)>
  # DEBUG sendmss => NULL
  return _6;

}



;; Function tcp_connect (tcp_connect, funcdef_no=23, decl_uid=7217, cgraph_uid=24, symbol_order=36)

Modification phase of node tcp_connect/36
tcp_connect (struct tcp_pcb * pcb, const struct ip_addr_t * ipaddr, u16_t port, err_t (*tcp_connected_fn) (void *, struct tcp_pcb *, err_t) connected)
{
  struct tcp_pcb * tcp_tmp_pcb;
  u16_t old_local_port;
  u32_t iss;
  err_t ret;
  struct netif * netif;
  tcp_state _1;
  struct ip_addr_t * _2;
  unsigned char _3;
  unsigned char _4;
  unsigned char _5;
  unsigned char _6;
  struct ip6_addr_t * _7;
  struct ip6_addr_t * _8;
  struct ip4_addr_t * _9;
  unsigned char _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  unsigned char _16;
  const struct ip6_addr_t * _17;
  unsigned char _18;
  long unsigned int _19;
  long unsigned int _20;
  long unsigned int _21;
  long unsigned int _22;
  unsigned char _23;
  long unsigned int _24;
  unsigned char _25;
  unsigned char _26;
  long unsigned int _27;
  long unsigned int _28;
  unsigned char _29;
  short unsigned int _30;
  long unsigned int _31;
  short unsigned int _32;
  struct tcp_pcb * tcp_bound_pcbs.49_33;
  struct tcp_pcb * _34;
  struct tcp_pcb * _35;
  struct tcp_pcb * _36;
  struct tcp_pcb * tcp_active_pcbs.51_37;
  long unsigned int _38;
  long unsigned int _39;
  err_t _42;
  _Bool iftmp.42_43;
  int iftmp.43_44;
  int iftmp.44_45;
  const struct ip_addr_t * iftmp.45_46;
  const long unsigned int iftmp.34_61;
  const long unsigned int iftmp.35_63;
  const long unsigned int iftmp.36_65;
  const long unsigned int iftmp.37_67;
  u8_t iftmp.38_69;
  const long unsigned int iftmp.39_71;
  struct netif * iftmp.40_80;
  struct netif * iftmp.40_82;
  _Bool iftmp.42_85;
  _Bool iftmp.42_86;
  const struct ip_addr_t * iftmp.46_88;
  const struct ip_addr_t * iftmp.47_89;
  u8_t iftmp.48_101;

  <bb 2> [local count: 677334388]:
  # DEBUG BEGIN_STMT
  # DEBUG netif => 0B
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_57(D) == 0B)
    goto <bb 47>; [0.45%]
  else
    goto <bb 3>; [99.55%]

  <bb 3> [local count: 674286383]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (ipaddr_58(D) == 0B)
    goto <bb 47>; [0.45%]
  else
    goto <bb 4>; [99.55%]

  <bb 4> [local count: 671252095]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pcb_57(D)->state;
  if (_1 != 0)
    goto <bb 47>; [1.04%]
  else
    goto <bb 5>; [98.96%]

  <bb 5> [local count: 664271073]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = &pcb_57(D)->remote_ip;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = ipaddr_58(D)->type;
  pcb_57(D)->remote_ip.type = _3;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _4 = ipaddr_58(D)->type;
  if (_4 == 6)
    goto <bb 6>; [34.00%]
  else
    goto <bb 7>; [66.00%]

  <bb 6> [local count: 225852164]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  iftmp.34_61 = ipaddr_58(D)->u_addr.ip6.addr[0];
  pcb_57(D)->remote_ip.u_addr.ip6.addr[0] = iftmp.34_61;
  # DEBUG BEGIN_STMT
  iftmp.35_63 = ipaddr_58(D)->u_addr.ip6.addr[1];
  pcb_57(D)->remote_ip.u_addr.ip6.addr[1] = iftmp.35_63;
  # DEBUG BEGIN_STMT
  iftmp.36_65 = ipaddr_58(D)->u_addr.ip6.addr[2];
  pcb_57(D)->remote_ip.u_addr.ip6.addr[2] = iftmp.36_65;
  # DEBUG BEGIN_STMT
  iftmp.37_67 = ipaddr_58(D)->u_addr.ip6.addr[3];
  pcb_57(D)->remote_ip.u_addr.ip6.addr[3] = iftmp.37_67;
  # DEBUG BEGIN_STMT
  iftmp.38_69 = ipaddr_58(D)->u_addr.ip6.zone;
  pcb_57(D)->remote_ip.u_addr.ip6.zone = iftmp.38_69;
  # DEBUG BEGIN_STMT
  goto <bb 8>; [100.00%]

  <bb 7> [local count: 438418907]:
  # DEBUG BEGIN_STMT
  iftmp.39_71 = ipaddr_58(D)->u_addr.ip4.addr;
  pcb_57(D)->remote_ip.u_addr.ip4.addr = iftmp.39_71;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pcb_57(D)->remote_ip.u_addr.ip6.addr[3] = 0;
  pcb_57(D)->remote_ip.u_addr.ip6.addr[2] = 0;
  pcb_57(D)->remote_ip.u_addr.ip6.addr[1] = 0;
  # DEBUG BEGIN_STMT
  pcb_57(D)->remote_ip.u_addr.ip6.zone = 0;

  <bb 8> [local count: 664271073]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pcb_57(D)->remote_port = port_77(D);
  # DEBUG BEGIN_STMT
  _5 = pcb_57(D)->netif_idx;
  if (_5 != 0)
    goto <bb 9>; [33.00%]
  else
    goto <bb 10>; [67.00%]

  <bb 9> [local count: 219209454]:
  # DEBUG BEGIN_STMT
  netif_84 = netif_get_by_index (_5);
  # DEBUG netif => netif_84
  goto <bb 13>; [100.00%]

  <bb 10> [local count: 445061618]:
  # DEBUG BEGIN_STMT
  _6 = pcb_57(D)->remote_ip.type;
  if (_6 == 6)
    goto <bb 11>; [34.00%]
  else
    goto <bb 12>; [66.00%]

  <bb 11> [local count: 151320950]:
  _7 = &pcb_57(D)->local_ip.u_addr.ip6;
  _8 = &pcb_57(D)->remote_ip.u_addr.ip6;
  iftmp.40_80 = ip6_route (_7, _8);
  goto <bb 13>; [100.00%]

  <bb 12> [local count: 293740668]:
  _9 = &pcb_57(D)->remote_ip.u_addr.ip4;
  iftmp.40_82 = ip4_route (_9);

  <bb 13> [local count: 664271073]:
  # netif_40 = PHI <netif_84(9), iftmp.40_82(12), iftmp.40_80(11)>
  # DEBUG netif => netif_40
  # DEBUG BEGIN_STMT
  if (netif_40 == 0B)
    goto <bb 47>; [0.45%]
  else
    goto <bb 14>; [99.55%]

  <bb 14> [local count: 661281853]:
  # DEBUG BEGIN_STMT
  _10 = pcb_57(D)->local_ip.type;
  if (_10 == 6)
    goto <bb 15>; [34.00%]
  else
    goto <bb 21>; [66.00%]

  <bb 15> [local count: 224835830]:
  _11 = pcb_57(D)->local_ip.u_addr.ip6.addr[0];
  if (_11 == 0)
    goto <bb 16>; [50.00%]
  else
    goto <bb 19>; [50.00%]

  <bb 16> [local count: 112417915]:
  _12 = pcb_57(D)->local_ip.u_addr.ip6.addr[1];
  if (_12 == 0)
    goto <bb 17>; [50.00%]
  else
    goto <bb 19>; [50.00%]

  <bb 17> [local count: 56208957]:
  _13 = pcb_57(D)->local_ip.u_addr.ip6.addr[2];
  if (_13 == 0)
    goto <bb 18>; [50.00%]
  else
    goto <bb 19>; [50.00%]

  <bb 18> [local count: 28104479]:
  _14 = pcb_57(D)->local_ip.u_addr.ip6.addr[3];
  if (_14 == 0)
    goto <bb 20>; [50.00%]
  else
    goto <bb 19>; [50.00%]

  <bb 19> [local count: 210783590]:

  <bb 20> [local count: 224835830]:
  # iftmp.43_44 = PHI <1(18), 0(19)>
  iftmp.42_85 = (_Bool) iftmp.43_44;
  goto <bb 24>; [100.00%]

  <bb 21> [local count: 436446023]:
  _15 = pcb_57(D)->local_ip.u_addr.ip4.addr;
  if (_15 == 0)
    goto <bb 23>; [50.00%]
  else
    goto <bb 22>; [50.00%]

  <bb 22> [local count: 218223011]:

  <bb 23> [local count: 436446023]:
  # iftmp.44_45 = PHI <1(21), 0(22)>
  iftmp.42_86 = (_Bool) iftmp.44_45;

  <bb 24> [local count: 661281853]:
  # iftmp.42_43 = PHI <iftmp.42_85(20), iftmp.42_86(23)>
  if (iftmp.42_43 != 0)
    goto <bb 25>; [50.00%]
  else
    goto <bb 32>; [50.00%]

  <bb 25> [local count: 330640926]:
  # DEBUG BEGIN_STMT
  _16 = ipaddr_58(D)->type;
  if (_16 == 6)
    goto <bb 26>; [20.24%]
  else
    goto <bb 27>; [79.76%]

  <bb 26> [local count: 66921724]:
  _17 = &ipaddr_58(D)->u_addr.ip6;
  iftmp.46_88 = ip6_select_source_address (netif_40, _17);
  goto <bb 28>; [100.00%]

  <bb 27> [local count: 263719203]:
  iftmp.47_89 = &netif_40->ip_addr;

  <bb 28> [local count: 330640926]:
  # iftmp.45_46 = PHI <iftmp.46_88(26), iftmp.47_89(27)>
  # DEBUG local_ip => iftmp.45_46
  # DEBUG BEGIN_STMT
  if (iftmp.45_46 == 0B)
    goto <bb 47>; [0.45%]
  else
    goto <bb 29>; [99.55%]

  <bb 29> [local count: 329153042]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _18 = iftmp.45_46->type;
  pcb_57(D)->local_ip.type = _18;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (_18 == 6)
    goto <bb 30>; [34.00%]
  else
    goto <bb 31>; [66.00%]

  <bb 30> [local count: 111912034]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _19 = iftmp.45_46->u_addr.ip6.addr[0];
  pcb_57(D)->local_ip.u_addr.ip6.addr[0] = _19;
  # DEBUG BEGIN_STMT
  _20 = iftmp.45_46->u_addr.ip6.addr[1];
  pcb_57(D)->local_ip.u_addr.ip6.addr[1] = _20;
  # DEBUG BEGIN_STMT
  _21 = iftmp.45_46->u_addr.ip6.addr[2];
  pcb_57(D)->local_ip.u_addr.ip6.addr[2] = _21;
  # DEBUG BEGIN_STMT
  _22 = iftmp.45_46->u_addr.ip6.addr[3];
  pcb_57(D)->local_ip.u_addr.ip6.addr[3] = _22;
  # DEBUG BEGIN_STMT
  _23 = iftmp.45_46->u_addr.ip6.zone;
  pcb_57(D)->local_ip.u_addr.ip6.zone = _23;
  # DEBUG BEGIN_STMT
  goto <bb 32>; [100.00%]

  <bb 31> [local count: 217241008]:
  # DEBUG BEGIN_STMT
  _24 = iftmp.45_46->u_addr.ip4.addr;
  pcb_57(D)->local_ip.u_addr.ip4.addr = _24;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pcb_57(D)->local_ip.u_addr.ip6.addr[3] = 0;
  pcb_57(D)->local_ip.u_addr.ip6.addr[2] = 0;
  pcb_57(D)->local_ip.u_addr.ip6.addr[1] = 0;
  # DEBUG BEGIN_STMT
  pcb_57(D)->local_ip.u_addr.ip6.zone = 0;

  <bb 32> [local count: 659793970]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _25 = pcb_57(D)->remote_ip.type;
  if (_25 == 6)
    goto <bb 33>; [34.00%]
  else
    goto <bb 36>; [66.00%]

  <bb 33> [local count: 224329950]:
  _26 = pcb_57(D)->remote_ip.u_addr.ip6.zone;
  if (_26 == 0)
    goto <bb 34>; [50.00%]
  else
    goto <bb 36>; [50.00%]

  <bb 34> [local count: 112164975]:
  _27 = pcb_57(D)->remote_ip.u_addr.ip6.addr[0];
  _28 = _27 & 49407;
  if (_28 == 33022)
    goto <bb 35>; [34.00%]
  else
    goto <bb 36>; [66.00%]

  <bb 35> [local count: 38136091]:
  # DEBUG BEGIN_STMT
  _29 = netif_40->num;
  iftmp.48_101 = _29 + 1;
  pcb_57(D)->remote_ip.u_addr.ip6.zone = iftmp.48_101;

  <bb 36> [local count: 659793970]:
  # DEBUG BEGIN_STMT
  old_local_port_103 = pcb_57(D)->local_port;
  # DEBUG old_local_port => old_local_port_103
  # DEBUG BEGIN_STMT
  if (old_local_port_103 == 0)
    goto <bb 37>; [50.00%]
  else
    goto <bb 38>; [50.00%]

  <bb 37> [local count: 329896985]:
  # DEBUG BEGIN_STMT
  _30 = tcp_new_port ();
  pcb_57(D)->local_port = _30;
  # DEBUG BEGIN_STMT
  if (_30 == 0)
    goto <bb 47>; [1.04%]
  else
    goto <bb 38>; [98.96%]

  <bb 38> [local count: 656363041]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  iss_107 = tcp_next_iss (pcb_57(D));
  # DEBUG iss => iss_107
  # DEBUG BEGIN_STMT
  pcb_57(D)->rcv_nxt = 0;
  # DEBUG BEGIN_STMT
  pcb_57(D)->snd_nxt = iss_107;
  # DEBUG BEGIN_STMT
  _31 = iss_107 + 4294967295;
  pcb_57(D)->lastack = _31;
  # DEBUG BEGIN_STMT
  pcb_57(D)->snd_wl2 = _31;
  # DEBUG BEGIN_STMT
  pcb_57(D)->snd_lbb = _31;
  # DEBUG BEGIN_STMT
  pcb_57(D)->rcv_ann_wnd = 7300;
  pcb_57(D)->rcv_wnd = 7300;
  # DEBUG BEGIN_STMT
  pcb_57(D)->rcv_ann_right_edge = 0;
  # DEBUG BEGIN_STMT
  pcb_57(D)->snd_wnd = 7300;
  # DEBUG BEGIN_STMT
  pcb_57(D)->mss = 536;
  # DEBUG BEGIN_STMT
  _32 = tcp_eff_send_mss_netif (536, netif_40, _2);
  pcb_57(D)->mss = _32;
  # DEBUG BEGIN_STMT
  pcb_57(D)->cwnd = 1;
  # DEBUG BEGIN_STMT
  pcb_57(D)->connected = connected_121(D);
  # DEBUG BEGIN_STMT
  ret_124 = tcp_enqueue_flags (pcb_57(D), 2);
  # DEBUG ret => ret_124
  # DEBUG BEGIN_STMT
  if (ret_124 == 0)
    goto <bb 39>; [50.00%]
  else
    goto <bb 47>; [50.00%]

  <bb 39> [local count: 328181520]:
  # DEBUG BEGIN_STMT
  pcb_57(D)->state = 2;
  # DEBUG BEGIN_STMT
  if (old_local_port_103 != 0)
    goto <bb 40>; [50.00%]
  else
    goto <bb 46>; [50.00%]

  <bb 40> [local count: 164090760]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tcp_bound_pcbs.49_33 = tcp_bound_pcbs;
  if (tcp_bound_pcbs.49_33 == pcb_57(D))
    goto <bb 41>; [30.00%]
  else
    goto <bb 48>; [70.00%]

  <bb 41> [local count: 49227228]:
  # DEBUG BEGIN_STMT
  _34 = tcp_bound_pcbs.49_33->next;
  tcp_bound_pcbs = _34;
  goto <bb 45>; [100.00%]

  <bb 42> [local count: 1014686026]:
  # DEBUG BEGIN_STMT
  _35 = tcp_tmp_pcb_41->next;
  if (_35 == pcb_57(D))
    goto <bb 43>; [5.50%]
  else
    goto <bb 49>; [94.50%]

  <bb 49> [local count: 958878295]:
  goto <bb 44>; [100.00%]

  <bb 43> [local count: 55807731]:
  # tcp_tmp_pcb_47 = PHI <tcp_tmp_pcb_41(42)>
  # DEBUG BEGIN_STMT
  _36 = pcb_57(D)->next;
  tcp_tmp_pcb_47->next = _36;
  # DEBUG BEGIN_STMT
  goto <bb 45>; [100.00%]

  <bb 48> [local count: 114863532]:

  <bb 44> [local count: 1073741824]:
  # tcp_tmp_pcb_41 = PHI <tcp_bound_pcbs.49_33(48), _35(49)>
  # DEBUG tcp_tmp_pcb => tcp_tmp_pcb_41
  # DEBUG BEGIN_STMT
  if (tcp_tmp_pcb_41 != 0B)
    goto <bb 42>; [94.50%]
  else
    goto <bb 45>; [5.50%]

  <bb 45> [local count: 164090760]:
  # DEBUG BEGIN_STMT

  <bb 46> [local count: 328181520]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tcp_active_pcbs.51_37 = tcp_active_pcbs;
  pcb_57(D)->next = tcp_active_pcbs.51_37;
  # DEBUG BEGIN_STMT
  tcp_active_pcbs = pcb_57(D);
  # DEBUG BEGIN_STMT
  tcp_timer_needed ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tcp_active_pcbs_changed = 1;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _38 = lwip_stats.mib2.tcpactiveopens;
  _39 = _38 + 1;
  lwip_stats.mib2.tcpactiveopens = _39;
  # DEBUG BEGIN_STMT
  tcp_output (pcb_57(D));

  <bb 47> [local count: 677334389]:
  # _42 = PHI <-16(2), -16(3), -10(4), -4(13), -4(28), -2(37), ret_124(46), ret_124(38)>
  return _42;

}



;; Function tcp_netif_ip_addr_changed (tcp_netif_ip_addr_changed, funcdef_no=50, decl_uid=7362, cgraph_uid=51, symbol_order=63)

Modification phase of node tcp_netif_ip_addr_changed/63
tcp_netif_ip_addr_changed (const struct ip_addr_t * old_addr, const struct ip_addr_t * new_addr)
{
  struct tcp_pcb_listen * lpcb;
  unsigned char _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  struct tcp_pcb * tcp_active_pcbs.91_7;
  struct tcp_pcb * tcp_bound_pcbs.92_8;
  unsigned char _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  unsigned char _15;
  unsigned char _16;
  long unsigned int _17;
  long unsigned int _18;
  long unsigned int _19;
  long unsigned int _20;
  long unsigned int _21;
  long unsigned int _22;
  long unsigned int _23;
  long unsigned int _24;
  unsigned char _25;
  unsigned char _26;
  long unsigned int _27;
  long unsigned int _28;
  unsigned char _29;
  unsigned char _30;
  long unsigned int _31;
  long unsigned int _32;
  long unsigned int _33;
  long unsigned int _34;
  unsigned char _35;
  long unsigned int _36;
  _Bool iftmp.88_38;
  int iftmp.89_39;
  int iftmp.90_40;
  _Bool iftmp.94_41;
  int iftmp.95_42;
  int iftmp.96_43;
  _Bool iftmp.98_44;
  int iftmp.99_45;
  _Bool iftmp.88_51;
  _Bool iftmp.88_52;
  _Bool iftmp.94_56;
  _Bool iftmp.94_57;
  _Bool iftmp.98_59;
  _Bool iftmp.98_60;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (old_addr_49(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 43>; [30.00%]

  <bb 3> [local count: 751619278]:
  _1 = old_addr_49(D)->type;
  if (_1 == 6)
    goto <bb 4>; [34.00%]
  else
    goto <bb 10>; [66.00%]

  <bb 4> [local count: 255550554]:
  _2 = old_addr_49(D)->u_addr.ip6.addr[0];
  if (_2 != 0)
    goto <bb 9>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 5> [local count: 127775277]:
  _3 = old_addr_49(D)->u_addr.ip6.addr[1];
  if (_3 != 0)
    goto <bb 9>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 6> [local count: 63887639]:
  _4 = old_addr_49(D)->u_addr.ip6.addr[2];
  if (_4 != 0)
    goto <bb 9>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 7> [local count: 31943819]:
  _5 = old_addr_49(D)->u_addr.ip6.addr[3];
  if (_5 != 0)
    goto <bb 9>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 8> [local count: 15971910]:

  <bb 9> [local count: 255550554]:
  # iftmp.89_39 = PHI <1(5), 0(8), 1(4), 1(7), 1(6)>
  iftmp.88_51 = (_Bool) iftmp.89_39;
  goto <bb 13>; [100.00%]

  <bb 10> [local count: 496068723]:
  _6 = old_addr_49(D)->u_addr.ip4.addr;
  if (_6 != 0)
    goto <bb 12>; [50.00%]
  else
    goto <bb 11>; [50.00%]

  <bb 11> [local count: 248034361]:

  <bb 12> [local count: 496068723]:
  # iftmp.90_40 = PHI <1(10), 0(11)>
  iftmp.88_52 = (_Bool) iftmp.90_40;

  <bb 13> [local count: 751619278]:
  # iftmp.88_38 = PHI <iftmp.88_51(9), iftmp.88_52(12)>
  if (iftmp.88_38 != 0)
    goto <bb 14>; [33.00%]
  else
    goto <bb 43>; [67.00%]

  <bb 14> [local count: 248034361]:
  # DEBUG BEGIN_STMT
  tcp_active_pcbs.91_7 = tcp_active_pcbs;
  tcp_netif_ip_addr_changed_pcblist (old_addr_49(D), tcp_active_pcbs.91_7);
  # DEBUG BEGIN_STMT
  tcp_bound_pcbs.92_8 = tcp_bound_pcbs;
  tcp_netif_ip_addr_changed_pcblist (old_addr_49(D), tcp_bound_pcbs.92_8);
  # DEBUG BEGIN_STMT
  if (new_addr_55(D) != 0B)
    goto <bb 15>; [70.00%]
  else
    goto <bb 43>; [30.00%]

  <bb 15> [local count: 173624053]:
  _9 = new_addr_55(D)->type;
  if (_9 == 6)
    goto <bb 16>; [34.00%]
  else
    goto <bb 22>; [66.00%]

  <bb 16> [local count: 59032178]:
  _10 = new_addr_55(D)->u_addr.ip6.addr[0];
  if (_10 != 0)
    goto <bb 21>; [50.00%]
  else
    goto <bb 17>; [50.00%]

  <bb 17> [local count: 29516089]:
  _11 = new_addr_55(D)->u_addr.ip6.addr[1];
  if (_11 != 0)
    goto <bb 21>; [50.00%]
  else
    goto <bb 18>; [50.00%]

  <bb 18> [local count: 14758044]:
  _12 = new_addr_55(D)->u_addr.ip6.addr[2];
  if (_12 != 0)
    goto <bb 21>; [50.00%]
  else
    goto <bb 19>; [50.00%]

  <bb 19> [local count: 7379022]:
  _13 = new_addr_55(D)->u_addr.ip6.addr[3];
  if (_13 != 0)
    goto <bb 21>; [50.00%]
  else
    goto <bb 20>; [50.00%]

  <bb 20> [local count: 3689511]:

  <bb 21> [local count: 59032178]:
  # iftmp.95_42 = PHI <1(17), 0(20), 1(16), 1(19), 1(18)>
  iftmp.94_56 = (_Bool) iftmp.95_42;
  goto <bb 25>; [100.00%]

  <bb 22> [local count: 114591875]:
  _14 = new_addr_55(D)->u_addr.ip4.addr;
  if (_14 != 0)
    goto <bb 24>; [50.00%]
  else
    goto <bb 23>; [50.00%]

  <bb 23> [local count: 57295938]:

  <bb 24> [local count: 114591875]:
  # iftmp.96_43 = PHI <1(22), 0(23)>
  iftmp.94_57 = (_Bool) iftmp.96_43;

  <bb 25> [local count: 173624053]:
  # iftmp.94_41 = PHI <iftmp.94_56(21), iftmp.94_57(24)>
  if (iftmp.94_41 != 0)
    goto <bb 26>; [50.00%]
  else
    goto <bb 43>; [50.00%]

  <bb 26> [local count: 86812027]:
  # DEBUG BEGIN_STMT
  lpcb_58 = tcp_listen_pcbs.listen_pcbs;
  # DEBUG lpcb => lpcb_58
  goto <bb 42>; [100.00%]

  <bb 27> [local count: 702388219]:
  # DEBUG BEGIN_STMT
  _15 = lpcb_37->local_ip.type;
  _16 = old_addr_49(D)->type;
  if (_15 == _16)
    goto <bb 28>; [34.00%]
  else
    goto <bb 41>; [66.00%]

  <bb 28> [local count: 238811994]:
  if (_15 == 6)
    goto <bb 29>; [34.00%]
  else
    goto <bb 36>; [66.00%]

  <bb 29> [local count: 81196078]:
  _17 = lpcb_37->local_ip.u_addr.ip6.addr[0];
  _18 = old_addr_49(D)->u_addr.ip6.addr[0];
  if (_17 == _18)
    goto <bb 30>; [34.00%]
  else
    goto <bb 34>; [66.00%]

  <bb 30> [local count: 27606667]:
  _19 = lpcb_37->local_ip.u_addr.ip6.addr[1];
  _20 = old_addr_49(D)->u_addr.ip6.addr[1];
  if (_19 == _20)
    goto <bb 31>; [34.00%]
  else
    goto <bb 34>; [66.00%]

  <bb 31> [local count: 9386267]:
  _21 = lpcb_37->local_ip.u_addr.ip6.addr[2];
  _22 = old_addr_49(D)->u_addr.ip6.addr[2];
  if (_21 == _22)
    goto <bb 32>; [34.00%]
  else
    goto <bb 34>; [66.00%]

  <bb 32> [local count: 3191331]:
  _23 = lpcb_37->local_ip.u_addr.ip6.addr[3];
  _24 = old_addr_49(D)->u_addr.ip6.addr[3];
  if (_23 == _24)
    goto <bb 33>; [34.00%]
  else
    goto <bb 34>; [66.00%]

  <bb 33> [local count: 1085052]:
  _25 = lpcb_37->local_ip.u_addr.ip6.zone;
  _26 = old_addr_49(D)->u_addr.ip6.zone;
  if (_25 == _26)
    goto <bb 35>; [34.00%]
  else
    goto <bb 34>; [66.00%]

  <bb 34> [local count: 80827160]:

  <bb 35> [local count: 81196078]:
  # iftmp.99_45 = PHI <1(33), 0(34)>
  iftmp.98_60 = (_Bool) iftmp.99_45;
  goto <bb 37>; [100.00%]

  <bb 36> [local count: 157615916]:
  _27 = lpcb_37->local_ip.u_addr.ip4.addr;
  _28 = old_addr_49(D)->u_addr.ip4.addr;
  iftmp.98_59 = _27 == _28;

  <bb 37> [local count: 238811994]:
  # iftmp.98_44 = PHI <iftmp.98_60(35), iftmp.98_59(36)>
  if (iftmp.98_44 != 0)
    goto <bb 38>; [50.00%]
  else
    goto <bb 41>; [50.00%]

  <bb 38> [local count: 119405997]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _29 = new_addr_55(D)->type;
  lpcb_37->local_ip.type = _29;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _30 = new_addr_55(D)->type;
  if (_30 == 6)
    goto <bb 39>; [34.00%]
  else
    goto <bb 40>; [66.00%]

  <bb 39> [local count: 40598039]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _31 = new_addr_55(D)->u_addr.ip6.addr[0];
  lpcb_37->local_ip.u_addr.ip6.addr[0] = _31;
  # DEBUG BEGIN_STMT
  _32 = new_addr_55(D)->u_addr.ip6.addr[1];
  lpcb_37->local_ip.u_addr.ip6.addr[1] = _32;
  # DEBUG BEGIN_STMT
  _33 = new_addr_55(D)->u_addr.ip6.addr[2];
  lpcb_37->local_ip.u_addr.ip6.addr[2] = _33;
  # DEBUG BEGIN_STMT
  _34 = new_addr_55(D)->u_addr.ip6.addr[3];
  lpcb_37->local_ip.u_addr.ip6.addr[3] = _34;
  # DEBUG BEGIN_STMT
  _35 = new_addr_55(D)->u_addr.ip6.zone;
  lpcb_37->local_ip.u_addr.ip6.zone = _35;
  # DEBUG BEGIN_STMT
  goto <bb 41>; [100.00%]

  <bb 40> [local count: 78807958]:
  # DEBUG BEGIN_STMT
  _36 = new_addr_55(D)->u_addr.ip4.addr;
  lpcb_37->local_ip.u_addr.ip4.addr = _36;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  lpcb_37->local_ip.u_addr.ip6.addr[3] = 0;
  lpcb_37->local_ip.u_addr.ip6.addr[2] = 0;
  lpcb_37->local_ip.u_addr.ip6.addr[1] = 0;
  # DEBUG BEGIN_STMT
  lpcb_37->local_ip.u_addr.ip6.zone = 0;

  <bb 41> [local count: 702388219]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  lpcb_72 = lpcb_37->next;
  # DEBUG lpcb => lpcb_72

  <bb 42> [local count: 789200246]:
  # lpcb_37 = PHI <lpcb_58(26), lpcb_72(41)>
  # DEBUG lpcb => lpcb_37
  # DEBUG BEGIN_STMT
  if (lpcb_37 != 0B)
    goto <bb 27>; [89.00%]
  else
    goto <bb 43>; [11.00%]

  <bb 43> [local count: 1073741824]:
  return;

}



;; Function tcp_debug_state_str (tcp_debug_state_str, funcdef_no=51, decl_uid=6425, cgraph_uid=52, symbol_order=64)

Modification phase of node tcp_debug_state_str/64
tcp_debug_state_str (tcp_state s)
{
  int _1;
  const char * _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = (int) s_2(D);
  _4 = tcp_state_str[_1];
  return _4;

}



;; Function tcp_tcp_get_tcp_addrinfo (tcp_tcp_get_tcp_addrinfo, funcdef_no=52, decl_uid=7247, cgraph_uid=53, symbol_order=65)

Modification phase of node tcp_tcp_get_tcp_addrinfo/65
tcp_tcp_get_tcp_addrinfo (struct tcp_pcb * pcb, int local, struct ip_addr_t * addr, u16_t * port)
{
  short unsigned int _1;
  short unsigned int _2;
  err_t _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (pcb_8(D) != 0B)
    goto <bb 3>; [98.33%]
  else
    goto <bb 13>; [1.67%]

  <bb 3> [local count: 1055810336]:
  # DEBUG BEGIN_STMT
  if (local_10(D) != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 4> [local count: 527905168]:
  # DEBUG BEGIN_STMT
  if (addr_11(D) != 0B)
    goto <bb 5>; [70.00%]
  else
    goto <bb 6>; [30.00%]

  <bb 5> [local count: 369533618]:
  # DEBUG BEGIN_STMT
  *addr_11(D) = pcb_8(D)->local_ip;

  <bb 6> [local count: 527905168]:
  # DEBUG BEGIN_STMT
  if (port_13(D) != 0B)
    goto <bb 7>; [70.00%]
  else
    goto <bb 12>; [30.00%]

  <bb 7> [local count: 369533618]:
  # DEBUG BEGIN_STMT
  _1 = pcb_8(D)->local_port;
  *port_13(D) = _1;
  goto <bb 12>; [100.00%]

  <bb 8> [local count: 527905168]:
  # DEBUG BEGIN_STMT
  if (addr_11(D) != 0B)
    goto <bb 9>; [70.00%]
  else
    goto <bb 10>; [30.00%]

  <bb 9> [local count: 369533618]:
  # DEBUG BEGIN_STMT
  *addr_11(D) = pcb_8(D)->remote_ip;

  <bb 10> [local count: 527905168]:
  # DEBUG BEGIN_STMT
  if (port_13(D) != 0B)
    goto <bb 11>; [70.00%]
  else
    goto <bb 12>; [30.00%]

  <bb 11> [local count: 369533618]:
  # DEBUG BEGIN_STMT
  _2 = pcb_8(D)->remote_port;
  *port_13(D) = _2;

  <bb 12> [local count: 1055810337]:
  # DEBUG BEGIN_STMT

  <bb 13> [local count: 1073741824]:
  # _3 = PHI <0(12), -6(2)>
  return _3;

}


