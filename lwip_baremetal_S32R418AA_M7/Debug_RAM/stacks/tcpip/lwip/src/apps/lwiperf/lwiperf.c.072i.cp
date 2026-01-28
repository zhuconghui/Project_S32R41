
IPA constant propagation start:
Determining dynamic type for call: _3 = lwiperf_tcp_client_send_more (arg_1(D));
  Starting walk at: _3 = lwiperf_tcp_client_send_more (arg_1(D));
  instance pointer: arg_1(D)  Outer instance pointer: arg_1(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = sys_now ();
Determining dynamic type for call: lwiperf_tcp_close (arg_3(D), 3);
  Starting walk at: lwiperf_tcp_close (arg_3(D), 3);
  instance pointer: arg_3(D)  Outer instance pointer: arg_3(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_17 = pbuf_memcmp (p_1(D), 0, _16, 24);
Determining dynamic type for call: err2_13 = lwiperf_tx_start_passive (arg_3(D));
  Starting walk at: err2_13 = lwiperf_tx_start_passive (arg_3(D));
  instance pointer: arg_3(D)  Outer instance pointer: arg_3(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_9 = pbuf_copy_partial (p_1(D), _8, 24, 0);
Determining dynamic type for call: lwiperf_tcp_close (arg_3(D), 4);
  Starting walk at: lwiperf_tcp_close (arg_3(D), 4);
  instance pointer: arg_3(D)  Outer instance pointer: arg_3(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err2_13 = lwiperf_tx_start_passive (arg_3(D));
  Function call may change dynamic type:_9 = pbuf_copy_partial (p_1(D), _8, 24, 0);
Determining dynamic type for call: lwiperf_tcp_close (arg_3(D), 2);
  Starting walk at: lwiperf_tcp_close (arg_3(D), 2);
  instance pointer: arg_3(D)  Outer instance pointer: arg_3(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_9 = pbuf_copy_partial (p_1(D), _8, 24, 0);
Determining dynamic type for call: lwiperf_tcp_close (arg_3(D), 3);
  Starting walk at: lwiperf_tcp_close (arg_3(D), 3);
  instance pointer: arg_3(D)  Outer instance pointer: arg_3(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: lwiperf_list_add (_21);
  Starting walk at: lwiperf_list_add (_21);
  instance pointer: _21  Outer instance pointer: client_conn_2 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_20 = tcp_connect (newpcb_5, &remote_addr, remote_port_19(D), lwiperf_tcp_client_connected);
  Function call may change dynamic type:tcp_err (newpcb_5, lwiperf_tcp_err);
  Function call may change dynamic type:tcp_poll (newpcb_5, lwiperf_tcp_poll, 2);
  Function call may change dynamic type:tcp_sent (newpcb_5, lwiperf_tcp_client_sent);
  Function call may change dynamic type:tcp_arg (newpcb_5, client_conn_2);
  Function call may change dynamic type:_7 = sys_now ();
  Function call may change dynamic type:memset (client_conn_2, 0, 92);
  Function call may change dynamic type:newpcb_5 = tcp_new_ip_type (_4);
  Function call may change dynamic type:client_conn_2 = mem_malloc (92);
Determining dynamic type for call: lwiperf_tcp_close (client_conn_2, 2);
  Starting walk at: lwiperf_tcp_close (client_conn_2, 2);
  instance pointer: client_conn_2  Outer instance pointer: client_conn_2 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_20 = tcp_connect (newpcb_5, &remote_addr, remote_port_19(D), lwiperf_tcp_client_connected);
  Function call may change dynamic type:tcp_err (newpcb_5, lwiperf_tcp_err);
  Function call may change dynamic type:tcp_poll (newpcb_5, lwiperf_tcp_poll, 2);
  Function call may change dynamic type:tcp_sent (newpcb_5, lwiperf_tcp_client_sent);
  Function call may change dynamic type:tcp_arg (newpcb_5, client_conn_2);
  Function call may change dynamic type:_7 = sys_now ();
  Function call may change dynamic type:memset (client_conn_2, 0, 92);
  Function call may change dynamic type:newpcb_5 = tcp_new_ip_type (_4);
  Function call may change dynamic type:client_conn_2 = mem_malloc (92);
Determining dynamic type for call: lwiperf_tcp_client_send_more (arg_1(D));
  Starting walk at: lwiperf_tcp_client_send_more (arg_1(D));
  instance pointer: arg_1(D)  Outer instance pointer: arg_1(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _2 = lwiperf_tcp_client_send_more (arg_1(D));
  Starting walk at: _2 = lwiperf_tcp_client_send_more (arg_1(D));
  instance pointer: arg_1(D)  Outer instance pointer: arg_1(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: lwiperf_tcp_close (conn_1(D), 1);
  Starting walk at: lwiperf_tcp_close (conn_1(D), 1);
  instance pointer: conn_1(D)  Outer instance pointer: conn_1(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:amount_bytes_10 = lwip_htonl (_2);
  Function call may change dynamic type:err_28 = tcp_write (_24, txptr_25, txlen_26, apiflags_27);
  Function call may change dynamic type:_8 = lwip_htonl (_7);
  Function call may change dynamic type:now_4 = sys_now ();
  Function call may change dynamic type:amount_bytes_10 = lwip_htonl (_2);
Determining dynamic type for call: lwiperf_tcp_close (conn_1(D), 1);
  Starting walk at: lwiperf_tcp_close (conn_1(D), 1);
  instance pointer: conn_1(D)  Outer instance pointer: conn_1(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_8 = lwip_htonl (_7);
  Function call may change dynamic type:now_4 = sys_now ();
  Function call may change dynamic type:err_28 = tcp_write (_24, txptr_25, txlen_26, apiflags_27);
  Function call may change dynamic type:_8 = lwip_htonl (_7);
  Function call may change dynamic type:now_4 = sys_now ();
  Function call may change dynamic type:amount_bytes_10 = lwip_htonl (_2);
Determining dynamic type for call: _33 = lwiperf_list_find (_31);
  Starting walk at: _33 = lwiperf_list_find (_31);
  instance pointer: _31  Outer instance pointer: _31 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_err (_29, lwiperf_tcp_err);
  Function call may change dynamic type:tcp_poll (newpcb_4(D), lwiperf_tcp_poll, 2);
  Function call may change dynamic type:tcp_recv (newpcb_4(D), lwiperf_tcp_recv);
  Function call may change dynamic type:tcp_arg (newpcb_4(D), conn_24);
  Function call may change dynamic type:_26 = sys_now ();
  Function call may change dynamic type:memset (conn_24, 0, 92);
  Function call may change dynamic type:conn_24 = mem_malloc (92);
Determining dynamic type for call: lwiperf_tcp_close (arg_1(D), 2);
  Starting walk at: lwiperf_tcp_close (arg_1(D), 2);
  instance pointer: arg_1(D)  Outer instance pointer: arg_1(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_err (_29, lwiperf_tcp_err);
  Function call may change dynamic type:tcp_poll (newpcb_4(D), lwiperf_tcp_poll, 2);
  Function call may change dynamic type:tcp_recv (newpcb_4(D), lwiperf_tcp_recv);
  Function call may change dynamic type:tcp_arg (newpcb_4(D), conn_24);
  Function call may change dynamic type:_26 = sys_now ();
  Function call may change dynamic type:memset (conn_24, 0, 92);
  Function call may change dynamic type:conn_24 = mem_malloc (92);
Determining dynamic type for call: lwiperf_list_add (_34);
  Starting walk at: lwiperf_list_add (_34);
  instance pointer: _34  Outer instance pointer: conn_24 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_err (_29, lwiperf_tcp_err);
  Function call may change dynamic type:tcp_poll (newpcb_4(D), lwiperf_tcp_poll, 2);
  Function call may change dynamic type:tcp_recv (newpcb_4(D), lwiperf_tcp_recv);
  Function call may change dynamic type:tcp_arg (newpcb_4(D), conn_24);
  Function call may change dynamic type:_26 = sys_now ();
  Function call may change dynamic type:memset (conn_24, 0, 92);
  Function call may change dynamic type:conn_24 = mem_malloc (92);
  Function call may change dynamic type:lwiperf_tcp_close (arg_1(D), 2);
Determining dynamic type for call: lwiperf_list_add (_11);
  Starting walk at: lwiperf_list_add (_11);
  instance pointer: _11  Outer instance pointer: s_1 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_accept (_10, lwiperf_tcp_accept);
  Function call may change dynamic type:tcp_arg (_9, s_1);
  Function call may change dynamic type:_9 = tcp_listen_with_backlog (pcb_5, 1);
  Function call may change dynamic type:err_8 = tcp_bind (pcb_5, local_addr_6(D), local_port_7(D));
  Function call may change dynamic type:pcb_5 = tcp_new_ip_type (46);
  Function call may change dynamic type:memset (s_1, 0, 92);
  Function call may change dynamic type:s_1 = mem_malloc (92);
Determining dynamic type for call: ret_38 = lwiperf_tx_start_impl (remote_addr_33(D), remote_port_34(D), &settings, report_fn_35(D), report_arg_36(D), 0B, &state);
  Starting walk at: ret_38 = lwiperf_tx_start_impl (remote_addr_33(D), remote_port_34(D), &settings, report_fn_35(D), report_arg_36(D), 0B, &state);
  instance pointer: remote_addr_33(D)  Outer instance pointer: remote_addr_33(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_5 = lwip_htonl (4294966296);
  Function call may change dynamic type:_4 = lwip_htonl (5001);
  Function call may change dynamic type:_3 = lwip_htonl (1);
  Function call may change dynamic type:_1 = lwip_htonl (2147483649);
  Function call may change dynamic type:_2 = lwip_htonl (2147483648);
Determining dynamic type for call: ret_38 = lwiperf_tx_start_impl (remote_addr_33(D), remote_port_34(D), &settings, report_fn_35(D), report_arg_36(D), 0B, &state);
  Starting walk at: ret_38 = lwiperf_tx_start_impl (remote_addr_33(D), remote_port_34(D), &settings, report_fn_35(D), report_arg_36(D), 0B, &state);
  instance pointer: &settings  Outer instance pointer: settings offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_5 = lwip_htonl (4294966296);
  Function call may change dynamic type:_4 = lwip_htonl (5001);
  Function call may change dynamic type:_3 = lwip_htonl (1);
  Function call may change dynamic type:memset (&settings, 0, 24);
  Function call may change dynamic type:_1 = lwip_htonl (2147483649);
  Function call may change dynamic type:_2 = lwip_htonl (2147483648);
Determining dynamic type for call: ret_38 = lwiperf_tx_start_impl (remote_addr_33(D), remote_port_34(D), &settings, report_fn_35(D), report_arg_36(D), 0B, &state);
  Starting walk at: ret_38 = lwiperf_tx_start_impl (remote_addr_33(D), remote_port_34(D), &settings, report_fn_35(D), report_arg_36(D), 0B, &state);
  instance pointer: report_fn_35(D)  Outer instance pointer: report_fn_35(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_5 = lwip_htonl (4294966296);
  Function call may change dynamic type:_4 = lwip_htonl (5001);
  Function call may change dynamic type:_3 = lwip_htonl (1);
  Function call may change dynamic type:_1 = lwip_htonl (2147483649);
  Function call may change dynamic type:_2 = lwip_htonl (2147483648);
Determining dynamic type for call: ret_38 = lwiperf_tx_start_impl (remote_addr_33(D), remote_port_34(D), &settings, report_fn_35(D), report_arg_36(D), 0B, &state);
  Starting walk at: ret_38 = lwiperf_tx_start_impl (remote_addr_33(D), remote_port_34(D), &settings, report_fn_35(D), report_arg_36(D), 0B, &state);
  instance pointer: report_arg_36(D)  Outer instance pointer: report_arg_36(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_5 = lwip_htonl (4294966296);
  Function call may change dynamic type:_4 = lwip_htonl (5001);
  Function call may change dynamic type:_3 = lwip_htonl (1);
  Function call may change dynamic type:_1 = lwip_htonl (2147483649);
  Function call may change dynamic type:_2 = lwip_htonl (2147483648);
Determining dynamic type for call: ret_38 = lwiperf_tx_start_impl (remote_addr_33(D), remote_port_34(D), &settings, report_fn_35(D), report_arg_36(D), 0B, &state);
  Starting walk at: ret_38 = lwiperf_tx_start_impl (remote_addr_33(D), remote_port_34(D), &settings, report_fn_35(D), report_arg_36(D), 0B, &state);
  instance pointer: 0B  Outer instance pointer: 0B offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_5 = lwip_htonl (4294966296);
  Function call may change dynamic type:_4 = lwip_htonl (5001);
  Function call may change dynamic type:_3 = lwip_htonl (1);
  Function call may change dynamic type:memset (&settings, 0, 24);
  Function call may change dynamic type:_1 = lwip_htonl (2147483649);
  Function call may change dynamic type:_2 = lwip_htonl (2147483648);
Determining dynamic type for call: ret_38 = lwiperf_tx_start_impl (remote_addr_33(D), remote_port_34(D), &settings, report_fn_35(D), report_arg_36(D), 0B, &state);
  Starting walk at: ret_38 = lwiperf_tx_start_impl (remote_addr_33(D), remote_port_34(D), &settings, report_fn_35(D), report_arg_36(D), 0B, &state);
  instance pointer: &state  Outer instance pointer: state offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_5 = lwip_htonl (4294966296);
  Function call may change dynamic type:_4 = lwip_htonl (5001);
  Function call may change dynamic type:_3 = lwip_htonl (1);
  Function call may change dynamic type:_1 = lwip_htonl (2147483649);
  Function call may change dynamic type:_2 = lwip_htonl (2147483648);
Determining dynamic type for call: ret_41 = lwiperf_start_tcp_server_impl (_8, 5001, report_fn_35(D), report_arg_36(D), state.6_6, &server);
  Starting walk at: ret_41 = lwiperf_start_tcp_server_impl (_8, 5001, report_fn_35(D), report_arg_36(D), state.6_6, &server);
  instance pointer: _8  Outer instance pointer: _7 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_38 = lwiperf_tx_start_impl (remote_addr_33(D), remote_port_34(D), &settings, report_fn_35(D), report_arg_36(D), 0B, &state);
  Function call may change dynamic type:_5 = lwip_htonl (4294966296);
  Function call may change dynamic type:_4 = lwip_htonl (5001);
  Function call may change dynamic type:_3 = lwip_htonl (1);
  Function call may change dynamic type:memset (&settings, 0, 24);
  Function call may change dynamic type:_1 = lwip_htonl (2147483649);
  Function call may change dynamic type:_2 = lwip_htonl (2147483648);
Determining dynamic type for call: ret_41 = lwiperf_start_tcp_server_impl (_8, 5001, report_fn_35(D), report_arg_36(D), state.6_6, &server);
  Starting walk at: ret_41 = lwiperf_start_tcp_server_impl (_8, 5001, report_fn_35(D), report_arg_36(D), state.6_6, &server);
  instance pointer: report_fn_35(D)  Outer instance pointer: report_fn_35(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_38 = lwiperf_tx_start_impl (remote_addr_33(D), remote_port_34(D), &settings, report_fn_35(D), report_arg_36(D), 0B, &state);
  Function call may change dynamic type:_5 = lwip_htonl (4294966296);
  Function call may change dynamic type:_4 = lwip_htonl (5001);
  Function call may change dynamic type:_3 = lwip_htonl (1);
  Function call may change dynamic type:_1 = lwip_htonl (2147483649);
  Function call may change dynamic type:_2 = lwip_htonl (2147483648);
Determining dynamic type for call: ret_41 = lwiperf_start_tcp_server_impl (_8, 5001, report_fn_35(D), report_arg_36(D), state.6_6, &server);
  Starting walk at: ret_41 = lwiperf_start_tcp_server_impl (_8, 5001, report_fn_35(D), report_arg_36(D), state.6_6, &server);
  instance pointer: report_arg_36(D)  Outer instance pointer: report_arg_36(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_38 = lwiperf_tx_start_impl (remote_addr_33(D), remote_port_34(D), &settings, report_fn_35(D), report_arg_36(D), 0B, &state);
  Function call may change dynamic type:_5 = lwip_htonl (4294966296);
  Function call may change dynamic type:_4 = lwip_htonl (5001);
  Function call may change dynamic type:_3 = lwip_htonl (1);
  Function call may change dynamic type:_1 = lwip_htonl (2147483649);
  Function call may change dynamic type:_2 = lwip_htonl (2147483648);
Determining dynamic type for call: ret_41 = lwiperf_start_tcp_server_impl (_8, 5001, report_fn_35(D), report_arg_36(D), state.6_6, &server);
  Starting walk at: ret_41 = lwiperf_start_tcp_server_impl (_8, 5001, report_fn_35(D), report_arg_36(D), state.6_6, &server);
  instance pointer: state.6_6  Outer instance pointer: state.6_6 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_38 = lwiperf_tx_start_impl (remote_addr_33(D), remote_port_34(D), &settings, report_fn_35(D), report_arg_36(D), 0B, &state);
  Function call may change dynamic type:_5 = lwip_htonl (4294966296);
  Function call may change dynamic type:_4 = lwip_htonl (5001);
  Function call may change dynamic type:_3 = lwip_htonl (1);
  Function call may change dynamic type:memset (&settings, 0, 24);
  Function call may change dynamic type:_1 = lwip_htonl (2147483649);
  Function call may change dynamic type:_2 = lwip_htonl (2147483648);
Determining dynamic type for call: ret_41 = lwiperf_start_tcp_server_impl (_8, 5001, report_fn_35(D), report_arg_36(D), state.6_6, &server);
  Starting walk at: ret_41 = lwiperf_start_tcp_server_impl (_8, 5001, report_fn_35(D), report_arg_36(D), state.6_6, &server);
  instance pointer: &server  Outer instance pointer: server offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_38 = lwiperf_tx_start_impl (remote_addr_33(D), remote_port_34(D), &settings, report_fn_35(D), report_arg_36(D), 0B, &state);
  Function call may change dynamic type:_5 = lwip_htonl (4294966296);
  Function call may change dynamic type:_4 = lwip_htonl (5001);
  Function call may change dynamic type:_3 = lwip_htonl (1);
  Function call may change dynamic type:_1 = lwip_htonl (2147483649);
  Function call may change dynamic type:_2 = lwip_htonl (2147483648);
Determining dynamic type for call: lwiperf_abort (state.9_9);
  Starting walk at: lwiperf_abort (state.9_9);
  instance pointer: state.9_9  Outer instance pointer: state.9_9 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:ret_41 = lwiperf_start_tcp_server_impl (_8, 5001, report_fn_35(D), report_arg_36(D), state.6_6, &server);
  Function call may change dynamic type:ret_38 = lwiperf_tx_start_impl (remote_addr_33(D), remote_port_34(D), &settings, report_fn_35(D), report_arg_36(D), 0B, &state);
  Function call may change dynamic type:_5 = lwip_htonl (4294966296);
  Function call may change dynamic type:_4 = lwip_htonl (5001);
  Function call may change dynamic type:_3 = lwip_htonl (1);
  Function call may change dynamic type:memset (&settings, 0, 24);
  Function call may change dynamic type:_1 = lwip_htonl (2147483649);
  Function call may change dynamic type:_2 = lwip_htonl (2147483648);
Determining dynamic type for call: _6 = lwiperf_start_tcp_client (remote_addr_2(D), 5001, 0, report_fn_3(D), report_arg_4(D));
  Starting walk at: _6 = lwiperf_start_tcp_client (remote_addr_2(D), 5001, 0, report_fn_3(D), report_arg_4(D));
  instance pointer: remote_addr_2(D)  Outer instance pointer: remote_addr_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _6 = lwiperf_start_tcp_client (remote_addr_2(D), 5001, 0, report_fn_3(D), report_arg_4(D));
  Starting walk at: _6 = lwiperf_start_tcp_client (remote_addr_2(D), 5001, 0, report_fn_3(D), report_arg_4(D));
  instance pointer: report_fn_3(D)  Outer instance pointer: report_fn_3(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _6 = lwiperf_start_tcp_client (remote_addr_2(D), 5001, 0, report_fn_3(D), report_arg_4(D));
  Starting walk at: _6 = lwiperf_start_tcp_client (remote_addr_2(D), 5001, 0, report_fn_3(D), report_arg_4(D));
  instance pointer: report_arg_4(D)  Outer instance pointer: report_arg_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _5 = lwiperf_start_tcp_server_impl.part.0 (local_addr_8(D), local_port_12(D), report_fn_10(D), report_arg_11(D), related_master_state_9(D), state_6(D));
  Starting walk at: _5 = lwiperf_start_tcp_server_impl.part.0 (local_addr_8(D), local_port_12(D), report_fn_10(D), report_arg_11(D), related_master_state_9(D), state_6(D));
  instance pointer: local_addr_8(D)  Outer instance pointer: local_addr_8(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _5 = lwiperf_start_tcp_server_impl.part.0 (local_addr_8(D), local_port_12(D), report_fn_10(D), report_arg_11(D), related_master_state_9(D), state_6(D));
  Starting walk at: _5 = lwiperf_start_tcp_server_impl.part.0 (local_addr_8(D), local_port_12(D), report_fn_10(D), report_arg_11(D), related_master_state_9(D), state_6(D));
  instance pointer: report_fn_10(D)  Outer instance pointer: report_fn_10(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _5 = lwiperf_start_tcp_server_impl.part.0 (local_addr_8(D), local_port_12(D), report_fn_10(D), report_arg_11(D), related_master_state_9(D), state_6(D));
  Starting walk at: _5 = lwiperf_start_tcp_server_impl.part.0 (local_addr_8(D), local_port_12(D), report_fn_10(D), report_arg_11(D), related_master_state_9(D), state_6(D));
  instance pointer: report_arg_11(D)  Outer instance pointer: report_arg_11(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _5 = lwiperf_start_tcp_server_impl.part.0 (local_addr_8(D), local_port_12(D), report_fn_10(D), report_arg_11(D), related_master_state_9(D), state_6(D));
  Starting walk at: _5 = lwiperf_start_tcp_server_impl.part.0 (local_addr_8(D), local_port_12(D), report_fn_10(D), report_arg_11(D), related_master_state_9(D), state_6(D));
  instance pointer: related_master_state_9(D)  Outer instance pointer: related_master_state_9(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _5 = lwiperf_start_tcp_server_impl.part.0 (local_addr_8(D), local_port_12(D), report_fn_10(D), report_arg_11(D), related_master_state_9(D), state_6(D));
  Starting walk at: _5 = lwiperf_start_tcp_server_impl.part.0 (local_addr_8(D), local_port_12(D), report_fn_10(D), report_arg_11(D), related_master_state_9(D), state_6(D));
  instance pointer: state_6(D)  Outer instance pointer: state_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: err_9 = lwiperf_start_tcp_server_impl (local_addr_4(D), local_port_5(D), report_fn_6(D), report_arg_7(D), 0B, &state);
  Starting walk at: err_9 = lwiperf_start_tcp_server_impl (local_addr_4(D), local_port_5(D), report_fn_6(D), report_arg_7(D), 0B, &state);
  instance pointer: local_addr_4(D)  Outer instance pointer: local_addr_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: err_9 = lwiperf_start_tcp_server_impl (local_addr_4(D), local_port_5(D), report_fn_6(D), report_arg_7(D), 0B, &state);
  Starting walk at: err_9 = lwiperf_start_tcp_server_impl (local_addr_4(D), local_port_5(D), report_fn_6(D), report_arg_7(D), 0B, &state);
  instance pointer: report_fn_6(D)  Outer instance pointer: report_fn_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: err_9 = lwiperf_start_tcp_server_impl (local_addr_4(D), local_port_5(D), report_fn_6(D), report_arg_7(D), 0B, &state);
  Starting walk at: err_9 = lwiperf_start_tcp_server_impl (local_addr_4(D), local_port_5(D), report_fn_6(D), report_arg_7(D), 0B, &state);
  instance pointer: report_arg_7(D)  Outer instance pointer: report_arg_7(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: err_9 = lwiperf_start_tcp_server_impl (local_addr_4(D), local_port_5(D), report_fn_6(D), report_arg_7(D), 0B, &state);
  Starting walk at: err_9 = lwiperf_start_tcp_server_impl (local_addr_4(D), local_port_5(D), report_fn_6(D), report_arg_7(D), 0B, &state);
  instance pointer: 0B  Outer instance pointer: 0B offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: err_9 = lwiperf_start_tcp_server_impl (local_addr_4(D), local_port_5(D), report_fn_6(D), report_arg_7(D), 0B, &state);
  Starting walk at: err_9 = lwiperf_start_tcp_server_impl (local_addr_4(D), local_port_5(D), report_fn_6(D), report_arg_7(D), 0B, &state);
  instance pointer: &state  Outer instance pointer: state offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _5 = lwiperf_start_tcp_server (&ip_addr_any, 5001, report_fn_2(D), report_arg_3(D));
  Starting walk at: _5 = lwiperf_start_tcp_server (&ip_addr_any, 5001, report_fn_2(D), report_arg_3(D));
  instance pointer: &ip_addr_any  Outer instance pointer: ip_addr_any offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _5 = lwiperf_start_tcp_server (&ip_addr_any, 5001, report_fn_2(D), report_arg_3(D));
  Starting walk at: _5 = lwiperf_start_tcp_server (&ip_addr_any, 5001, report_fn_2(D), report_arg_3(D));
  instance pointer: report_fn_2(D)  Outer instance pointer: report_fn_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _5 = lwiperf_start_tcp_server (&ip_addr_any, 5001, report_fn_2(D), report_arg_3(D));
  Starting walk at: _5 = lwiperf_start_tcp_server (&ip_addr_any, 5001, report_fn_2(D), report_arg_3(D));
  instance pointer: report_arg_3(D)  Outer instance pointer: report_arg_3(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _9 = lwiperf_tcp_accept.part.0 (arg_12(D), newpcb_11(D));
  Starting walk at: _9 = lwiperf_tcp_accept.part.0 (arg_12(D), newpcb_11(D));
  instance pointer: arg_12(D)  Outer instance pointer: arg_12(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _9 = lwiperf_tcp_accept.part.0 (arg_12(D), newpcb_11(D));
  Starting walk at: _9 = lwiperf_tcp_accept.part.0 (arg_12(D), newpcb_11(D));
  instance pointer: newpcb_11(D)  Outer instance pointer: newpcb_11(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: lwiperf_tcp_poll.part.0 (arg_7(D));
  Starting walk at: lwiperf_tcp_poll.part.0 (arg_7(D));
  instance pointer: arg_7(D)  Outer instance pointer: arg_7(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: lwiperf_tcp_close (arg_7(D), 2);
  Starting walk at: lwiperf_tcp_close (arg_7(D), 2);
  instance pointer: arg_7(D)  Outer instance pointer: arg_7(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: lwiperf_tcp_close (arg_1(D), 5);
  Starting walk at: lwiperf_tcp_close (arg_1(D), 5);
  instance pointer: arg_1(D)  Outer instance pointer: arg_1(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: lwiperf_tcp_recv.part.0 (arg_9(D), tpcb_11(D), p_13(D));
  Starting walk at: lwiperf_tcp_recv.part.0 (arg_9(D), tpcb_11(D), p_13(D));
  instance pointer: arg_9(D)  Outer instance pointer: arg_9(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: lwiperf_tcp_recv.part.0 (arg_9(D), tpcb_11(D), p_13(D));
  Starting walk at: lwiperf_tcp_recv.part.0 (arg_9(D), tpcb_11(D), p_13(D));
  instance pointer: tpcb_11(D)  Outer instance pointer: tpcb_11(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: lwiperf_tcp_recv.part.0 (arg_9(D), tpcb_11(D), p_13(D));
  Starting walk at: lwiperf_tcp_recv.part.0 (arg_9(D), tpcb_11(D), p_13(D));
  instance pointer: p_13(D)  Outer instance pointer: p_13(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: lwiperf_tx_start_passive (arg_9(D));
  Starting walk at: lwiperf_tx_start_passive (arg_9(D));
  instance pointer: arg_9(D)  Outer instance pointer: arg_9(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: lwiperf_tcp_close (arg_9(D), 0);
  Starting walk at: lwiperf_tcp_close (arg_9(D), 0);
  instance pointer: arg_9(D)  Outer instance pointer: arg_9(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:lwiperf_tx_start_passive (arg_9(D));
Determining dynamic type for call: lwiperf_tcp_close (arg_9(D), 5);
  Starting walk at: lwiperf_tcp_close (arg_9(D), 5);
  instance pointer: arg_9(D)  Outer instance pointer: arg_9(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_18 = lwiperf_tx_start_impl (_4, remote_port_16, _5, _6, _7, _8, &new_conn);
  Starting walk at: ret_18 = lwiperf_tx_start_impl (_4, remote_port_16, _5, _6, _7, _8, &new_conn);
  instance pointer: _4  Outer instance pointer: _3 offset: 192 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = lwip_htonl (_1);
Determining dynamic type for call: ret_18 = lwiperf_tx_start_impl (_4, remote_port_16, _5, _6, _7, _8, &new_conn);
  Starting walk at: ret_18 = lwiperf_tx_start_impl (_4, remote_port_16, _5, _6, _7, _8, &new_conn);
  instance pointer: _5  Outer instance pointer: conn_14(D) offset: 320 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = lwip_htonl (_1);
Determining dynamic type for call: ret_18 = lwiperf_tx_start_impl (_4, remote_port_16, _5, _6, _7, _8, &new_conn);
  Starting walk at: ret_18 = lwiperf_tx_start_impl (_4, remote_port_16, _5, _6, _7, _8, &new_conn);
  instance pointer: _6  Outer instance pointer: _6 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = lwip_htonl (_1);
Determining dynamic type for call: ret_18 = lwiperf_tx_start_impl (_4, remote_port_16, _5, _6, _7, _8, &new_conn);
  Starting walk at: ret_18 = lwiperf_tx_start_impl (_4, remote_port_16, _5, _6, _7, _8, &new_conn);
  instance pointer: _7  Outer instance pointer: _7 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = lwip_htonl (_1);
Determining dynamic type for call: ret_18 = lwiperf_tx_start_impl (_4, remote_port_16, _5, _6, _7, _8, &new_conn);
  Starting walk at: ret_18 = lwiperf_tx_start_impl (_4, remote_port_16, _5, _6, _7, _8, &new_conn);
  instance pointer: _8  Outer instance pointer: _8 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = lwip_htonl (_1);
Determining dynamic type for call: ret_18 = lwiperf_tx_start_impl (_4, remote_port_16, _5, _6, _7, _8, &new_conn);
  Starting walk at: ret_18 = lwiperf_tx_start_impl (_4, remote_port_16, _5, _6, _7, _8, &new_conn);
  instance pointer: &new_conn  Outer instance pointer: new_conn offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = lwip_htonl (_1);
Determining dynamic type for call: _1 = lwiperf_tx_start_impl.part.0 (remote_ip_6(D), remote_port_13(D), settings_8(D), report_fn_11(D), report_arg_12(D), related_master_state_10(D), new_conn_9(D));
  Starting walk at: _1 = lwiperf_tx_start_impl.part.0 (remote_ip_6(D), remote_port_13(D), settings_8(D), report_fn_11(D), report_arg_12(D), related_master_state_10(D), new_conn_9(D));
  instance pointer: remote_ip_6(D)  Outer instance pointer: remote_ip_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = lwiperf_tx_start_impl.part.0 (remote_ip_6(D), remote_port_13(D), settings_8(D), report_fn_11(D), report_arg_12(D), related_master_state_10(D), new_conn_9(D));
  Starting walk at: _1 = lwiperf_tx_start_impl.part.0 (remote_ip_6(D), remote_port_13(D), settings_8(D), report_fn_11(D), report_arg_12(D), related_master_state_10(D), new_conn_9(D));
  instance pointer: settings_8(D)  Outer instance pointer: settings_8(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = lwiperf_tx_start_impl.part.0 (remote_ip_6(D), remote_port_13(D), settings_8(D), report_fn_11(D), report_arg_12(D), related_master_state_10(D), new_conn_9(D));
  Starting walk at: _1 = lwiperf_tx_start_impl.part.0 (remote_ip_6(D), remote_port_13(D), settings_8(D), report_fn_11(D), report_arg_12(D), related_master_state_10(D), new_conn_9(D));
  instance pointer: report_fn_11(D)  Outer instance pointer: report_fn_11(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = lwiperf_tx_start_impl.part.0 (remote_ip_6(D), remote_port_13(D), settings_8(D), report_fn_11(D), report_arg_12(D), related_master_state_10(D), new_conn_9(D));
  Starting walk at: _1 = lwiperf_tx_start_impl.part.0 (remote_ip_6(D), remote_port_13(D), settings_8(D), report_fn_11(D), report_arg_12(D), related_master_state_10(D), new_conn_9(D));
  instance pointer: report_arg_12(D)  Outer instance pointer: report_arg_12(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = lwiperf_tx_start_impl.part.0 (remote_ip_6(D), remote_port_13(D), settings_8(D), report_fn_11(D), report_arg_12(D), related_master_state_10(D), new_conn_9(D));
  Starting walk at: _1 = lwiperf_tx_start_impl.part.0 (remote_ip_6(D), remote_port_13(D), settings_8(D), report_fn_11(D), report_arg_12(D), related_master_state_10(D), new_conn_9(D));
  instance pointer: related_master_state_10(D)  Outer instance pointer: related_master_state_10(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = lwiperf_tx_start_impl.part.0 (remote_ip_6(D), remote_port_13(D), settings_8(D), report_fn_11(D), report_arg_12(D), related_master_state_10(D), new_conn_9(D));
  Starting walk at: _1 = lwiperf_tx_start_impl.part.0 (remote_ip_6(D), remote_port_13(D), settings_8(D), report_fn_11(D), report_arg_12(D), related_master_state_10(D), new_conn_9(D));
  instance pointer: new_conn_9(D)  Outer instance pointer: new_conn_9(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _5 = lwiperf_tcp_client_connected.part.0 (arg_4(D));
  Starting walk at: _5 = lwiperf_tcp_client_connected.part.0 (arg_4(D));
  instance pointer: arg_4(D)  Outer instance pointer: arg_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: lwiperf_tcp_close (arg_4(D), 5);
  Starting walk at: lwiperf_tcp_close (arg_4(D), 5);
  instance pointer: arg_4(D)  Outer instance pointer: arg_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _8 = lwiperf_tcp_client_sent.part.0 (arg_3(D));
  Starting walk at: _8 = lwiperf_tcp_client_sent.part.0 (arg_3(D));
  instance pointer: arg_3(D)  Outer instance pointer: arg_3(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: lwiperf_tcp_client_send_more.part.0 (conn_6(D));
  Starting walk at: lwiperf_tcp_client_send_more.part.0 (conn_6(D));
  instance pointer: conn_6(D)  Outer instance pointer: conn_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: lwiperf_list_remove (_1);
  Starting walk at: lwiperf_list_remove (_1);
  instance pointer: _1  Outer instance pointer: conn_12(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: lwip_tcp_conn_report (conn_12(D), report_type_15(D));
  Starting walk at: lwip_tcp_conn_report (conn_12(D), report_type_15(D));
  instance pointer: conn_12(D)  Outer instance pointer: conn_12(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:lwiperf_list_remove (_1);
Determining dynamic type for call: _5 (_6, report_type_21(D), _8, _9, _10, _11, _12, duration_ms_19, bandwidth_kbitpsec_13);
  Starting walk at: _5 (_6, report_type_21(D), _8, _9, _10, _11, _12, duration_ms_19, bandwidth_kbitpsec_13);
  instance pointer: _6  Outer instance pointer: _6 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:now_18 = sys_now ();
Determining dynamic type for call: _5 (_6, report_type_21(D), _8, _9, _10, _11, _12, duration_ms_19, bandwidth_kbitpsec_13);
  Starting walk at: _5 (_6, report_type_21(D), _8, _9, _10, _11, _12, duration_ms_19, bandwidth_kbitpsec_13);
  instance pointer: _8  Outer instance pointer: _7 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:now_18 = sys_now ();
Determining dynamic type for call: _5 (_6, report_type_21(D), _8, _9, _10, _11, _12, duration_ms_19, bandwidth_kbitpsec_13);
  Starting walk at: _5 (_6, report_type_21(D), _8, _9, _10, _11, _12, duration_ms_19, bandwidth_kbitpsec_13);
  instance pointer: _10  Outer instance pointer: _7 offset: 192 (bits) vtbl reference: 
  Function call may change dynamic type:now_18 = sys_now ();

IPA structures before propagation:

Jump functions:
  Jump functions of caller  lwiperf_tcp_client_connected.part.0/56:
    callsite  lwiperf_tcp_client_connected.part.0/56 -> lwiperf_tcp_client_send_more/8 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  lwiperf_tcp_recv.part.0/55:
    callsite  lwiperf_tcp_recv.part.0/55 -> lwiperf_tcp_close/7 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 3
         value: 0x3, mask: 0x0
         Unknown VR
    callsite  lwiperf_tcp_recv.part.0/55 -> lwiperf_tcp_close/7 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 2
         value: 0x2, mask: 0x0
         Unknown VR
    callsite  lwiperf_tcp_recv.part.0/55 -> lwiperf_tx_start_passive/12 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  lwiperf_tcp_recv.part.0/55 -> lwiperf_tcp_close/7 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 4
         value: 0x4, mask: 0x0
         Unknown VR
    callsite  lwiperf_tcp_recv.part.0/55 -> lwiperf_tcp_close/7 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 3
         value: 0x3, mask: 0x0
         Unknown VR
  Jump functions of caller  lwiperf_tx_start_impl.part.0/54:
    callsite  lwiperf_tx_start_impl.part.0/54 -> lwiperf_tcp_close/7 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 2
         value: 0x2, mask: 0x0
         Unknown VR
    callsite  lwiperf_tx_start_impl.part.0/54 -> lwiperf_list_add/3 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  lwiperf_tcp_poll.part.0/53:
    callsite  lwiperf_tcp_poll.part.0/53 -> lwiperf_tcp_client_send_more/8 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  lwiperf_tcp_client_sent.part.0/52:
    callsite  lwiperf_tcp_client_sent.part.0/52 -> lwiperf_tcp_client_send_more/8 : 
       param 0: PASS THROUGH: 0, op nop_expr
         Aggregate passed by reference:
           offset: 256, cst: 0
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  lwiperf_tcp_client_send_more.part.0/51:
    callsite  lwiperf_tcp_client_send_more.part.0/51 -> lwiperf_tcp_close/7 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
    callsite  lwiperf_tcp_client_send_more.part.0/51 -> lwiperf_tcp_close/7 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
  Jump functions of caller  lwiperf_tcp_accept.part.0/50:
    callsite  lwiperf_tcp_accept.part.0/50 -> lwiperf_list_find/5 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  lwiperf_tcp_accept.part.0/50 -> lwiperf_tcp_close/7 : 
       param 0: PASS THROUGH: 0, op nop_expr
         Aggregate passed by reference:
           offset: 192, cst: 0B
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 2
         value: 0x2, mask: 0x0
         Unknown VR
    callsite  lwiperf_tcp_accept.part.0/50 -> lwiperf_list_add/3 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  lwiperf_start_tcp_server_impl.part.0/49:
    callsite  lwiperf_start_tcp_server_impl.part.0/49 -> lwiperf_list_add/3 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  tcp_abort/48:
  Jump functions of caller  tcp_connect/47:
  Jump functions of caller  tcp_sent/46:
  Jump functions of caller  memcpy/45:
  Jump functions of caller  pbuf_remove_header/44:
  Jump functions of caller  tcp_recved/43:
  Jump functions of caller  pbuf_memcmp/42:
  Jump functions of caller  pbuf_copy_partial/41:
  Jump functions of caller  pbuf_free/40:
  Jump functions of caller  tcp_output/39:
  Jump functions of caller  tcp_write/38:
  Jump functions of caller  lwip_htonl/37:
  Jump functions of caller  tcp_err/36:
  Jump functions of caller  tcp_poll/35:
  Jump functions of caller  tcp_recv/34:
  Jump functions of caller  sys_now/33:
  Jump functions of caller  tcp_accept/32:
  Jump functions of caller  tcp_arg/31:
  Jump functions of caller  mem_free/30:
  Jump functions of caller  tcp_close/29:
  Jump functions of caller  tcp_listen_with_backlog/28:
  Jump functions of caller  tcp_bind/27:
  Jump functions of caller  tcp_new_ip_type/26:
  Jump functions of caller  memset/25:
  Jump functions of caller  mem_malloc/24:
  Jump functions of caller  lwiperf_abort/22:
  Jump functions of caller  lwiperf_start_tcp_client/21:
    callsite  lwiperf_start_tcp_client/21 -> lwiperf_abort/22 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  lwiperf_start_tcp_client/21 -> lwiperf_start_tcp_server_impl/19 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 5001
         value: 0x1389, mask: 0x0
         Unknown VR
       param 2: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 4, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 5: UNKNOWN
         Aggregate passed by reference:
           offset: 0, cst: 0B
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  lwiperf_start_tcp_client/21 -> lwiperf_tx_start_impl/11 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 3: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: PASS THROUGH: 4, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 5: CONST: 0B
         value: 0x0, mask: 0xfffffff8
         Unknown VR
       param 6: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  lwiperf_start_tcp_client_default/20:
    callsite  lwiperf_start_tcp_client_default/20 -> lwiperf_start_tcp_client/21 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 5001
         value: 0x1389, mask: 0x0
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 3: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  lwiperf_start_tcp_server_impl/19:
    callsite  lwiperf_start_tcp_server_impl/19 -> lwiperf_start_tcp_server_impl.part.0/49 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: PASS THROUGH: 4, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 5: PASS THROUGH: 5, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  lwiperf_start_tcp_server/18:
    callsite  lwiperf_start_tcp_server/18 -> lwiperf_start_tcp_server_impl/19 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: CONST: 0B
         value: 0x0, mask: 0xfffffff8
         Unknown VR
       param 5: UNKNOWN
         Aggregate passed by reference:
           offset: 0, cst: 0B
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  lwiperf_start_tcp_server_default/17:
    callsite  lwiperf_start_tcp_server_default/17 -> lwiperf_start_tcp_server/18 : 
       param 0: CONST: &ip_addr_any
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: CONST: 5001
         value: 0x1389, mask: 0x0
         Unknown VR
       param 2: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  lwiperf_tcp_accept/16:
    callsite  lwiperf_tcp_accept/16 -> lwiperf_tcp_accept.part.0/50 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  lwiperf_tcp_poll/15:
    callsite  lwiperf_tcp_poll/15 -> lwiperf_tcp_poll.part.0/53 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  lwiperf_tcp_poll/15 -> lwiperf_tcp_close/7 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 2
         value: 0x2, mask: 0x0
         Unknown VR
  Jump functions of caller  lwiperf_tcp_err/14:
    callsite  lwiperf_tcp_err/14 -> lwiperf_tcp_close/7 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 5
         value: 0x5, mask: 0x0
         Unknown VR
  Jump functions of caller  lwiperf_tcp_recv/13:
    callsite  lwiperf_tcp_recv/13 -> lwiperf_tcp_recv.part.0/55 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  lwiperf_tcp_recv/13 -> lwiperf_tcp_close/7 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  lwiperf_tcp_recv/13 -> lwiperf_tx_start_passive/12 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  lwiperf_tcp_recv/13 -> lwiperf_tcp_close/7 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 5
         value: 0x5, mask: 0x0
         Unknown VR
  Jump functions of caller  lwiperf_tx_start_passive/12:
    callsite  lwiperf_tx_start_passive/12 -> lwiperf_tx_start_impl/11 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: ANCESTOR: 0, offset 320
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 5: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 6: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  lwiperf_tx_start_impl/11:
    callsite  lwiperf_tx_start_impl/11 -> lwiperf_tx_start_impl.part.0/54 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: PASS THROUGH: 4, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 5: PASS THROUGH: 5, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 6: PASS THROUGH: 6, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  lwiperf_tcp_client_connected/10:
    callsite  lwiperf_tcp_client_connected/10 -> lwiperf_tcp_client_connected.part.0/56 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  lwiperf_tcp_client_connected/10 -> lwiperf_tcp_close/7 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 5
         value: 0x5, mask: 0x0
         Unknown VR
  Jump functions of caller  lwiperf_tcp_client_sent/9:
    callsite  lwiperf_tcp_client_sent/9 -> lwiperf_tcp_client_sent.part.0/52 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  lwiperf_tcp_client_send_more/8:
    callsite  lwiperf_tcp_client_send_more/8 -> lwiperf_tcp_client_send_more.part.0/51 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  lwiperf_tcp_close/7:
    callsite  lwiperf_tcp_close/7 -> lwip_tcp_conn_report/6 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  lwiperf_tcp_close/7 -> lwiperf_list_remove/4 : 
       param 0: ANCESTOR: 0, offset 0, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  lwip_tcp_conn_report/6:
    indirect aggregate callsite, calling param 0, offset 192, by reference, for stmt _5 (_6, report_type_21(D), _8, _9, _10, _11, _12, duration_ms_19, bandwidth_kbitpsec_13);
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 4: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 5: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 6: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 7: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 8: UNKNOWN
         value: 0x0, mask: 0xfffffff8
         Unknown VR
  Jump functions of caller  lwiperf_list_find/5:
  Jump functions of caller  lwiperf_list_remove/4:
  Jump functions of caller  lwiperf_list_add/3:

 Propagating constants:

Not considering lwiperf_abort for cloning; -fipa-cp-clone disabled.
Not considering lwiperf_start_tcp_client for cloning; -fipa-cp-clone disabled.
Not considering lwiperf_start_tcp_client_default for cloning; -fipa-cp-clone disabled.
Not considering lwiperf_start_tcp_server for cloning; -fipa-cp-clone disabled.
Not considering lwiperf_start_tcp_server_default for cloning; -fipa-cp-clone disabled.
Not considering lwiperf_tcp_accept for cloning; -fipa-cp-clone disabled.
Not considering lwiperf_tcp_poll for cloning; -fipa-cp-clone disabled.
Not considering lwiperf_tcp_err for cloning; -fipa-cp-clone disabled.
Not considering lwiperf_tcp_recv for cloning; -fipa-cp-clone disabled.
Not considering lwiperf_tcp_client_connected for cloning; -fipa-cp-clone disabled.
Not considering lwiperf_tcp_client_sent for cloning; -fipa-cp-clone disabled.

overall_size: 891, max_new_size: 11001
 - context independent values, size: 17, time_benefit: 0.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 50, time_benefit: 0.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 6, time_benefit: 1.000000
 - context independent values, size: 11, time_benefit: 1.000000

IPA lattices after all propagation:

Lattices:
  Node: lwiperf_tcp_client_connected.part.0/56:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: lwiperf_tcp_recv.part.0/55:
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
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: lwiperf_tx_start_impl.part.0/54:
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
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct lwiperf_settings_t * ~[0B, 0B]
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [4]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [5]: VARIABLE
               0B [loc_time: 1, loc_size: 83, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [6]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct lwiperf_state_tcp_t * * ~[0B, 0B]
        AGGS VARIABLE
  Node: lwiperf_tcp_poll.part.0/53:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: lwiperf_tcp_client_sent.part.0/52:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: lwiperf_tcp_client_send_more.part.0/51:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: lwiperf_tcp_accept.part.0/50:
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
  Node: lwiperf_start_tcp_server_impl.part.0/49:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
               5001 [loc_time: 1, loc_size: 50, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [4]: VARIABLE
               0B [loc_time: 1, loc_size: 50, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [5]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct lwiperf_state_tcp_t * * ~[0B, 0B]
        ref offset 0: 0B [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
  Node: lwiperf_abort/22:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: lwiperf_start_tcp_client/21:
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
  Node: lwiperf_start_tcp_client_default/20:
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
  Node: lwiperf_start_tcp_server_impl/19:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
               5001 [loc_time: 1, loc_size: 17, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [4]: VARIABLE
               0B [loc_time: 1, loc_size: 17, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [5]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct lwiperf_state_tcp_t * * ~[0B, 0B]
        ref offset 0: 0B [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
  Node: lwiperf_start_tcp_server/18:
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
  Node: lwiperf_start_tcp_server_default/17:
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
  Node: lwiperf_tcp_accept/16:
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
  Node: lwiperf_tcp_poll/15:
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
  Node: lwiperf_tcp_err/14:
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
  Node: lwiperf_tcp_recv/13:
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
  Node: lwiperf_tx_start_passive/12:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: lwiperf_tx_start_impl/11:
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
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct lwiperf_settings_t * ~[0B, 0B]
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [4]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [5]: VARIABLE
               0B [loc_time: 1, loc_size: 24, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [6]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct lwiperf_state_tcp_t * * ~[0B, 0B]
        AGGS VARIABLE
  Node: lwiperf_tcp_client_connected/10:
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
  Node: lwiperf_tcp_client_sent/9:
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
  Node: lwiperf_tcp_client_send_more/8:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: lwiperf_tcp_close/7:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: 1 [loc_time: 1, loc_size: 50, prop_time: 0, prop_size: 0]
               4 [loc_time: 1, loc_size: 50, prop_time: 0, prop_size: 0]
               3 [loc_time: 1, loc_size: 50, prop_time: 0, prop_size: 0]
               0 [loc_time: 1, loc_size: 50, prop_time: 0, prop_size: 0]
               5 [loc_time: 1, loc_size: 50, prop_time: 0, prop_size: 0]
               2 [loc_time: 1, loc_size: 50, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x2, mask = 0x7
         lwiperf_report_type [0, 5]
        AGGS VARIABLE
  Node: lwip_tcp_conn_report/6:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: 2 [loc_time: 1, loc_size: 35, prop_time: 0, prop_size: 0]
               5 [loc_time: 1, loc_size: 35, prop_time: 0, prop_size: 0]
               0 [loc_time: 1, loc_size: 35, prop_time: 0, prop_size: 0]
               3 [loc_time: 1, loc_size: 35, prop_time: 0, prop_size: 0]
               4 [loc_time: 1, loc_size: 35, prop_time: 0, prop_size: 0]
               1 [loc_time: 1, loc_size: 35, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x2, mask = 0x7
         lwiperf_report_type [0, 5]
        AGGS VARIABLE
  Node: lwiperf_list_find/5:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: lwiperf_list_remove/4:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: lwiperf_list_add/3:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE

IPA decision stage:

 - Creating a specialized node of lwiperf_start_tcp_server_impl/19 for all known contexts.
 - Creating a specialized node of lwiperf_start_tcp_server_impl.part.0/49 for all known contexts.
Propagated bits info for function lwiperf_start_tcp_server_impl.part.0.constprop/58:
 param 5: value = 0x0, mask = 0xfffffffc
Propagated bits info for function lwiperf_start_tcp_server_impl.constprop/57:
 param 5: value = 0x0, mask = 0xfffffffc
Propagated bits info for function lwiperf_tx_start_impl.part.0/54:
 param 6: value = 0x0, mask = 0xfffffffc
Propagated bits info for function lwiperf_start_tcp_server_impl.part.0/49:
 param 5: value = 0x0, mask = 0xfffffffc
Propagated bits info for function lwiperf_start_tcp_server_impl/19:
 param 5: value = 0x0, mask = 0xfffffffc
Propagated bits info for function lwiperf_tx_start_impl/11:
 param 6: value = 0x0, mask = 0xfffffffc
Propagated bits info for function lwiperf_tcp_close/7:
 param 1: value = 0x2, mask = 0x7
Propagated bits info for function lwip_tcp_conn_report/6:
 param 1: value = 0x2, mask = 0x7

IPA constant propagation end

Reclaiming functions: lwiperf_start_tcp_server_impl.part.0/49 lwiperf_start_tcp_server_impl/19
Reclaiming variables:
Clearing address taken flags:
Symbol table:

lwiperf_start_tcp_server_impl.part.0.constprop.0/58 (lwiperf_start_tcp_server_impl.part.0.constprop) @061e0ee0
  Type: function definition analyzed
  Visibility: artificial
  References: lwiperf_tcp_accept/16 (addr)
  Referring: 
  Clone of lwiperf_start_tcp_server_impl.part.0/49
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 local split_part optimize_size
  Called by: lwiperf_start_tcp_server_impl.constprop/57 (248259 (estimated locally),0.69 per call) 
  Calls: lwiperf_list_add/3 (513017274 (estimated locally),0.48 per call) tcp_accept/32 (513017274 (estimated locally),0.48 per call) tcp_arg/31 (513017274 (estimated locally),0.48 per call) mem_free/30 (2319013 (estimated locally),0.00 per call) tcp_close/29 (2319013 (estimated locally),0.00 per call) tcp_listen_with_backlog/28 (515336287 (estimated locally),0.48 per call) tcp_bind/27 (1054288640 (estimated locally),0.98 per call) tcp_new_ip_type/26 (1063970774 (estimated locally),0.99 per call) memset/25 (1063970774 (estimated locally),0.99 per call) mem_malloc/24 (1073741824 (estimated locally),1.00 per call) 
lwiperf_start_tcp_server_impl.constprop.0/57 (lwiperf_start_tcp_server_impl.constprop) @0632db60
  Type: function definition analyzed
  Visibility:
  References: 
  Referring: 
  Clone of lwiperf_start_tcp_server_impl/19
  Availability: local
  Function flags: count:357913 (estimated locally) local optimize_size
  Called by: lwiperf_start_tcp_server/18 (1073741824 (estimated locally),1.00 per call) lwiperf_start_tcp_client/21 (122464 (estimated locally),0.18 per call) 
  Calls: lwiperf_start_tcp_server_impl.part.0.constprop/58 (248259 (estimated locally),0.69 per call) 
lwiperf_tcp_client_connected.part.0/56 (lwiperf_tcp_client_connected.part.0) @062fca80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: lwiperf_tcp_client_connected/10 (30371 (estimated locally),0.20 per call) 
  Calls: sys_now/33 (1073741824 (estimated locally),1.00 per call) lwiperf_tcp_client_send_more/8 (1073741824 (estimated locally),1.00 per call) 
lwiperf_tcp_recv.part.0/55 (lwiperf_tcp_recv.part.0) @062fcee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:323907 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: lwiperf_tcp_recv/13 (30064 (estimated locally),0.20 per call) 
  Calls: lwiperf_tcp_close/7 (49169 (estimated locally),0.15 per call) pbuf_free/40 (49169 (estimated locally),0.15 per call) pbuf_copy_partial/41 (63941 (estimated locally),0.20 per call) lwiperf_tcp_close/7 (21101 (estimated locally),0.07 per call) pbuf_free/40 (21101 (estimated locally),0.07 per call) lwiperf_tx_start_passive/12 (7069 (estimated locally),0.02 per call) lwiperf_tcp_close/7 (1431 (estimated locally),0.00 per call) pbuf_free/40 (1431 (estimated locally),0.00 per call) pbuf_memcmp/42 (42841 (estimated locally),0.13 per call) lwiperf_tcp_close/7 (8671 (estimated locally),0.03 per call) pbuf_free/40 (8671 (estimated locally),0.03 per call) sys_now/33 (55270 (estimated locally),0.17 per call) tcp_recved/43 (55270 (estimated locally),0.17 per call) pbuf_free/40 (55270 (estimated locally),0.17 per call) pbuf_remove_header/44 (107289 (estimated locally),0.33 per call) tcp_recved/43 (27247 (estimated locally),0.08 per call) pbuf_free/40 (27247 (estimated locally),0.08 per call) 
lwiperf_tx_start_impl.part.0/54 (lwiperf_tx_start_impl.part.0) @062fc700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: lwiperf_tcp_client_sent/9 (addr)lwiperf_tcp_poll/15 (addr)lwiperf_tcp_err/14 (addr)lwiperf_tcp_client_connected/10 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: lwiperf_tx_start_impl/11 (93775 (estimated locally),0.26 per call) 
  Calls: mem_malloc/24 (1073741824 (estimated locally),1.00 per call) tcp_new_ip_type/26 (1063970774 (estimated locally),0.99 per call) mem_free/30 (4787868 (estimated locally),0.00 per call) memset/25 (1059182906 (estimated locally),0.99 per call) sys_now/33 (1059182906 (estimated locally),0.99 per call) memcpy/45 (1059182906 (estimated locally),0.99 per call) tcp_arg/31 (1059182906 (estimated locally),0.99 per call) tcp_sent/46 (1059182906 (estimated locally),0.99 per call) tcp_poll/35 (1059182906 (estimated locally),0.99 per call) tcp_err/36 (1059182906 (estimated locally),0.99 per call) tcp_connect/47 (1059182906 (estimated locally),0.99 per call) lwiperf_tcp_close/7 (360122188 (estimated locally),0.34 per call) lwiperf_list_add/3 (699060718 (estimated locally),0.65 per call) 
lwiperf_tcp_poll.part.0/53 (lwiperf_tcp_poll.part.0) @062fc0e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: lwiperf_tcp_poll/15 (36703 (estimated locally),0.24 per call) 
  Calls: lwiperf_tcp_client_send_more/8 (354334802 (estimated locally),0.33 per call) 
lwiperf_tcp_client_sent.part.0/52 (lwiperf_tcp_client_sent.part.0) @061e0e00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: lwiperf_tcp_client_sent/9 (22666 (estimated locally),0.17 per call) 
  Calls: lwiperf_tcp_client_send_more/8 (1073741824 (estimated locally),1.00 per call) 
lwiperf_tcp_client_send_more.part.0/51 (lwiperf_tcp_client_send_more.part.0) @061e0460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: lwiperf_txbuf_const/2 (addr)
  Referring: 
  Availability: local
  Function flags: count:9478698 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: lwiperf_tcp_client_send_more/8 (22776 (estimated locally),0.17 per call) 
  Calls: sys_now/33 (59055800 (estimated locally),6.23 per call) lwip_htonl/37 (59055800 (estimated locally),6.23 per call) lwiperf_tcp_close/7 (1624035 (estimated locally),0.17 per call) lwip_htonl/37 (59055800 (estimated locally),6.23 per call) lwiperf_tcp_close/7 (1624035 (estimated locally),0.17 per call) tcp_write/38 (1073741823 (estimated locally),113.28 per call) tcp_output/39 (6230629 (estimated locally),0.66 per call) 
lwiperf_tcp_accept.part.0/50 (lwiperf_tcp_accept.part.0) @061e07e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: lwiperf_tcp_recv/13 (addr)lwiperf_tcp_poll/15 (addr)lwiperf_tcp_err/14 (addr)
  Referring: 
  Availability: local
  Function flags: count:306783 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: lwiperf_tcp_accept/16 (22549 (estimated locally),0.10 per call) 
  Calls: mem_malloc/24 (150150 (estimated locally),0.49 per call) memset/25 (148783 (estimated locally),0.48 per call) sys_now/33 (148783 (estimated locally),0.48 per call) tcp_arg/31 (148783 (estimated locally),0.48 per call) tcp_recv/34 (148783 (estimated locally),0.48 per call) tcp_poll/35 (148783 (estimated locally),0.48 per call) tcp_err/36 (148783 (estimated locally),0.48 per call) lwiperf_list_find/5 (37196 (estimated locally),0.12 per call) lwiperf_tcp_close/7 (48355 (estimated locally),0.16 per call) lwiperf_list_add/3 (148783 (estimated locally),0.48 per call) 
lwiperf_start_tcp_server_impl.part.0/49 (lwiperf_start_tcp_server_impl.part.0) @05f218c0
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) first_run:1 body split_part optimize_size
  Called by: 
  Calls: 
tcp_abort/48 (tcp_abort) @061bf000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: lwiperf_tcp_close/7 (165356 (estimated locally),0.23 per call) 
  Calls: 
tcp_connect/47 (tcp_connect) @061a5b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: lwiperf_tx_start_impl.part.0/54 (1059182906 (estimated locally),0.99 per call) 
  Calls: 
tcp_sent/46 (tcp_sent) @061a5a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: lwiperf_tx_start_impl.part.0/54 (1059182906 (estimated locally),0.99 per call) lwiperf_tcp_close/7 (501079 (estimated locally),0.70 per call) 
  Calls: 
memcpy/45 (memcpy) @061a59a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: lwiperf_tx_start_impl.part.0/54 (1059182906 (estimated locally),0.99 per call) 
  Calls: 
pbuf_remove_header/44 (pbuf_remove_header) @061a5700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: lwiperf_tcp_recv.part.0/55 (107289 (estimated locally),0.33 per call) 
  Calls: 
tcp_recved/43 (tcp_recved) @061a5620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: lwiperf_tcp_recv.part.0/55 (55270 (estimated locally),0.17 per call) lwiperf_tcp_recv.part.0/55 (27247 (estimated locally),0.08 per call) 
  Calls: 
pbuf_memcmp/42 (pbuf_memcmp) @061a5540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: lwiperf_tcp_recv.part.0/55 (42841 (estimated locally),0.13 per call) 
  Calls: 
pbuf_copy_partial/41 (pbuf_copy_partial) @061a5460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: lwiperf_tcp_recv.part.0/55 (63941 (estimated locally),0.20 per call) 
  Calls: 
pbuf_free/40 (pbuf_free) @061a5380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: lwiperf_tcp_recv.part.0/55 (49169 (estimated locally),0.15 per call) lwiperf_tcp_recv.part.0/55 (21101 (estimated locally),0.07 per call) lwiperf_tcp_recv.part.0/55 (1431 (estimated locally),0.00 per call) lwiperf_tcp_recv.part.0/55 (8671 (estimated locally),0.03 per call) lwiperf_tcp_recv.part.0/55 (55270 (estimated locally),0.17 per call) lwiperf_tcp_recv.part.0/55 (27247 (estimated locally),0.08 per call) 
  Calls: 
tcp_output/39 (tcp_output) @061a5000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: lwiperf_tcp_client_send_more.part.0/51 (6230629 (estimated locally),0.66 per call) 
  Calls: 
tcp_write/38 (tcp_write) @06173ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: lwiperf_tcp_client_send_more.part.0/51 (1073741823 (estimated locally),113.28 per call) 
  Calls: 
lwip_htonl/37 (lwip_htonl) @06173e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: lwiperf_start_tcp_client/21 (504103 (estimated locally),0.75 per call) lwiperf_start_tcp_client/21 (504103 (estimated locally),0.75 per call) lwiperf_start_tcp_client/21 (504103 (estimated locally),0.75 per call) lwiperf_start_tcp_client/21 (168034 (estimated locally),0.25 per call) lwiperf_start_tcp_client/21 (168034 (estimated locally),0.25 per call) lwiperf_tx_start_passive/12 (715827 (estimated locally),1.00 per call) lwiperf_tcp_client_send_more.part.0/51 (59055800 (estimated locally),6.23 per call) lwiperf_tcp_client_send_more.part.0/51 (59055800 (estimated locally),6.23 per call) 
  Calls: 
tcp_err/36 (tcp_err) @061738c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: lwiperf_tx_start_impl.part.0/54 (1059182906 (estimated locally),0.99 per call) lwiperf_tcp_accept.part.0/50 (148783 (estimated locally),0.48 per call) lwiperf_tcp_close/7 (501079 (estimated locally),0.70 per call) 
  Calls: 
tcp_poll/35 (tcp_poll) @061737e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: lwiperf_tx_start_impl.part.0/54 (1059182906 (estimated locally),0.99 per call) lwiperf_tcp_accept.part.0/50 (148783 (estimated locally),0.48 per call) lwiperf_tcp_close/7 (501079 (estimated locally),0.70 per call) 
  Calls: 
tcp_recv/34 (tcp_recv) @06173700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: lwiperf_tcp_accept.part.0/50 (148783 (estimated locally),0.48 per call) lwiperf_tcp_close/7 (501079 (estimated locally),0.70 per call) 
  Calls: 
sys_now/33 (sys_now) @06173620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: lwiperf_tcp_client_connected.part.0/56 (1073741824 (estimated locally),1.00 per call) lwiperf_tcp_recv.part.0/55 (55270 (estimated locally),0.17 per call) lwiperf_tx_start_impl.part.0/54 (1059182906 (estimated locally),0.99 per call) lwiperf_tcp_client_send_more.part.0/51 (59055800 (estimated locally),6.23 per call) lwiperf_tcp_accept.part.0/50 (148783 (estimated locally),0.48 per call) lwip_tcp_conn_report/6 (401890827 (estimated locally),0.37 per call) 
  Calls: 
tcp_accept/32 (tcp_accept) @061732a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: lwiperf_start_tcp_server_impl.part.0.constprop/58 (513017274 (estimated locally),0.48 per call) 
  Calls: 
tcp_arg/31 (tcp_arg) @061731c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: lwiperf_start_tcp_server_impl.part.0.constprop/58 (513017274 (estimated locally),0.48 per call) lwiperf_tx_start_impl.part.0/54 (1059182906 (estimated locally),0.99 per call) lwiperf_tcp_accept.part.0/50 (148783 (estimated locally),0.48 per call) lwiperf_tcp_close/7 (501079 (estimated locally),0.70 per call) 
  Calls: 
mem_free/30 (mem_free) @061730e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: lwiperf_start_tcp_server_impl.part.0.constprop/58 (2319013 (estimated locally),0.00 per call) lwiperf_abort/22 (487371413 (estimated locally),4.13 per call) lwiperf_tx_start_impl.part.0/54 (4787868 (estimated locally),0.00 per call) lwiperf_tcp_close/7 (608453 (estimated locally),0.85 per call) 
  Calls: 
tcp_close/29 (tcp_close) @06173000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: lwiperf_start_tcp_server_impl.part.0.constprop/58 (2319013 (estimated locally),0.00 per call) lwiperf_tcp_close/7 (214748 (estimated locally),0.30 per call) lwiperf_tcp_close/7 (501079 (estimated locally),0.70 per call) 
  Calls: 
tcp_listen_with_backlog/28 (tcp_listen_with_backlog) @06163620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: lwiperf_start_tcp_server_impl.part.0.constprop/58 (515336287 (estimated locally),0.48 per call) 
  Calls: 
tcp_bind/27 (tcp_bind) @06163380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: lwiperf_start_tcp_server_impl.part.0.constprop/58 (1054288640 (estimated locally),0.98 per call) 
  Calls: 
tcp_new_ip_type/26 (tcp_new_ip_type) @061630e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: lwiperf_start_tcp_server_impl.part.0.constprop/58 (1063970774 (estimated locally),0.99 per call) lwiperf_tx_start_impl.part.0/54 (1063970774 (estimated locally),0.99 per call) 
  Calls: 
memset/25 (memset) @06163ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: lwiperf_start_tcp_server_impl.part.0.constprop/58 (1063970774 (estimated locally),0.99 per call) lwiperf_start_tcp_client/21 (672138 (estimated locally),1.00 per call) lwiperf_tx_start_impl.part.0/54 (1059182906 (estimated locally),0.99 per call) lwiperf_tcp_accept.part.0/50 (148783 (estimated locally),0.48 per call) 
  Calls: 
mem_malloc/24 (mem_malloc) @06163e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: lwiperf_start_tcp_server_impl.part.0.constprop/58 (1073741824 (estimated locally),1.00 per call) lwiperf_tx_start_impl.part.0/54 (1073741824 (estimated locally),1.00 per call) lwiperf_tcp_accept.part.0/50 (150150 (estimated locally),0.49 per call) 
  Calls: 
ip_addr_any/23 (ip_addr_any) @061684c8
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: lwiperf_start_tcp_server_default/17 (addr)
  Availability: not_available
  Varpool flags: read-only
lwiperf_abort/22 (lwiperf_abort) @061637e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: lwiperf_all_connections/1 (read)
  Referring: 
  Availability: available
  Function flags: count:118111600 (estimated locally) body optimize_size
  Called by: lwiperf_start_tcp_client/21 (20513 (estimated locally),0.03 per call) 
  Calls: mem_free/30 (487371413 (estimated locally),4.13 per call) 
lwiperf_start_tcp_client/21 (lwiperf_start_tcp_client) @06163540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:672138 (estimated locally) body optimize_size
  Called by: lwiperf_start_tcp_client_default/20 (1073741824 (estimated locally),1.00 per call) 
  Calls: lwiperf_abort/22 (20513 (estimated locally),0.03 per call) lwiperf_start_tcp_server_impl.constprop/57 (122464 (estimated locally),0.18 per call) lwiperf_tx_start_impl/11 (504103 (estimated locally),0.75 per call) lwip_htonl/37 (504103 (estimated locally),0.75 per call) lwip_htonl/37 (504103 (estimated locally),0.75 per call) lwip_htonl/37 (504103 (estimated locally),0.75 per call) lwip_htonl/37 (168034 (estimated locally),0.25 per call) lwip_htonl/37 (168034 (estimated locally),0.25 per call) memset/25 (672138 (estimated locally),1.00 per call) 
lwiperf_start_tcp_client_default/20 (lwiperf_start_tcp_client_default) @061632a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: lwiperf_start_tcp_client/21 (1073741824 (estimated locally),1.00 per call) 
lwiperf_start_tcp_server_impl/19 (lwiperf_start_tcp_server_impl) @06163000
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: 
lwiperf_start_tcp_server/18 (lwiperf_start_tcp_server) @061542a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: lwiperf_start_tcp_server_default/17 (1073741824 (estimated locally),1.00 per call) 
  Calls: lwiperf_start_tcp_server_impl.constprop/57 (1073741824 (estimated locally),1.00 per call) 
lwiperf_start_tcp_server_default/17 (lwiperf_start_tcp_server_default) @06154ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ip_addr_any/23 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: lwiperf_start_tcp_server/18 (1073741824 (estimated locally),1.00 per call) 
lwiperf_tcp_accept/16 (lwiperf_tcp_accept) @06154c40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: lwiperf_start_tcp_server_impl.part.0.constprop.0/58 (addr)
  Availability: available
  Function flags: count:218971 (estimated locally) body optimize_size
  Called by: 
  Calls: lwiperf_tcp_accept.part.0/50 (22549 (estimated locally),0.10 per call) 
lwiperf_tcp_poll/15 (lwiperf_tcp_poll) @06154460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: lwiperf_tcp_accept.part.0/50 (addr)lwiperf_tx_start_impl.part.0/54 (addr)
  Availability: available
  Function flags: count:153391 (estimated locally) body optimize_size
  Called by: 
  Calls: lwiperf_tcp_poll.part.0/53 (36703 (estimated locally),0.24 per call) lwiperf_tcp_close/7 (9314 (estimated locally),0.06 per call) 
lwiperf_tcp_err/14 (lwiperf_tcp_err) @061541c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: lwiperf_tcp_accept.part.0/50 (addr)lwiperf_tx_start_impl.part.0/54 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: lwiperf_tcp_close/7 (1073741824 (estimated locally),1.00 per call) 
lwiperf_tcp_recv/13 (lwiperf_tcp_recv) @06129ee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: lwiperf_tcp_accept.part.0/50 (addr)
  Availability: available
  Function flags: count:153391 (estimated locally) body optimize_size
  Called by: 
  Calls: lwiperf_tcp_recv.part.0/55 (30064 (estimated locally),0.20 per call) lwiperf_tcp_close/7 (6640 (estimated locally),0.04 per call) lwiperf_tx_start_passive/12 (1096 (estimated locally),0.01 per call) lwiperf_tcp_close/7 (9314 (estimated locally),0.06 per call) 
lwiperf_tx_start_passive/12 (lwiperf_tx_start_passive) @06129b60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:715827 (estimated locally) body local optimize_size
  Called by: lwiperf_tcp_recv/13 (1096 (estimated locally),0.01 per call) lwiperf_tcp_recv.part.0/55 (7069 (estimated locally),0.02 per call) 
  Calls: lwiperf_tx_start_impl/11 (715827 (estimated locally),1.00 per call) lwip_htonl/37 (715827 (estimated locally),1.00 per call) 
lwiperf_tx_start_impl/11 (lwiperf_tx_start_impl) @061298c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:357913 (estimated locally) body local optimize_size
  Called by: lwiperf_start_tcp_client/21 (504103 (estimated locally),0.75 per call) lwiperf_tx_start_passive/12 (715827 (estimated locally),1.00 per call) 
  Calls: lwiperf_tx_start_impl.part.0/54 (93775 (estimated locally),0.26 per call) 
lwiperf_tcp_client_connected/10 (lwiperf_tcp_client_connected) @061291c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: lwiperf_tx_start_impl.part.0/54 (addr)
  Availability: available
  Function flags: count:153391 (estimated locally) body optimize_size
  Called by: 
  Calls: lwiperf_tcp_client_connected.part.0/56 (30371 (estimated locally),0.20 per call) lwiperf_tcp_close/7 (15646 (estimated locally),0.10 per call) 
lwiperf_tcp_client_sent/9 (lwiperf_tcp_client_sent) @06118ee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: lwiperf_tx_start_impl.part.0/54 (addr)
  Availability: available
  Function flags: count:130040 (estimated locally) body optimize_size
  Called by: 
  Calls: lwiperf_tcp_client_sent.part.0/52 (22666 (estimated locally),0.17 per call) 
lwiperf_tcp_client_send_more/8 (lwiperf_tcp_client_send_more) @06118c40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:130150 (estimated locally) body local optimize_size
  Called by: lwiperf_tcp_client_connected.part.0/56 (1073741824 (estimated locally),1.00 per call) lwiperf_tcp_poll.part.0/53 (354334802 (estimated locally),0.33 per call) lwiperf_tcp_client_sent.part.0/52 (1073741824 (estimated locally),1.00 per call) 
  Calls: lwiperf_tcp_client_send_more.part.0/51 (22776 (estimated locally),0.17 per call) 
lwiperf_tcp_close/7 (lwiperf_tcp_close) @061188c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:715827 (estimated locally) body local optimize_size
  Called by: lwiperf_tcp_client_connected/10 (15646 (estimated locally),0.10 per call) lwiperf_tcp_recv/13 (6640 (estimated locally),0.04 per call) lwiperf_tcp_recv/13 (9314 (estimated locally),0.06 per call) lwiperf_tcp_recv.part.0/55 (49169 (estimated locally),0.15 per call) lwiperf_tcp_recv.part.0/55 (21101 (estimated locally),0.07 per call) lwiperf_tcp_recv.part.0/55 (1431 (estimated locally),0.00 per call) lwiperf_tcp_recv.part.0/55 (8671 (estimated locally),0.03 per call) lwiperf_tx_start_impl.part.0/54 (360122188 (estimated locally),0.34 per call) lwiperf_tcp_poll/15 (9314 (estimated locally),0.06 per call) lwiperf_tcp_client_send_more.part.0/51 (1624035 (estimated locally),0.17 per call) lwiperf_tcp_client_send_more.part.0/51 (1624035 (estimated locally),0.17 per call) lwiperf_tcp_err/14 (1073741824 (estimated locally),1.00 per call) lwiperf_tcp_accept.part.0/50 (48355 (estimated locally),0.16 per call) 
  Calls: mem_free/30 (608453 (estimated locally),0.85 per call) tcp_close/29 (214748 (estimated locally),0.30 per call) tcp_abort/48 (165356 (estimated locally),0.23 per call) tcp_close/29 (501079 (estimated locally),0.70 per call) tcp_err/36 (501079 (estimated locally),0.70 per call) tcp_recv/34 (501079 (estimated locally),0.70 per call) tcp_sent/46 (501079 (estimated locally),0.70 per call) tcp_poll/35 (501079 (estimated locally),0.70 per call) tcp_arg/31 (501079 (estimated locally),0.70 per call) lwip_tcp_conn_report/6 (715827 (estimated locally),1.00 per call) lwiperf_list_remove/4 (715827 (estimated locally),1.00 per call) 
lwip_tcp_conn_report/6 (lwip_tcp_conn_report) @06118540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741823 (estimated locally) body local optimize_size
  Called by: lwiperf_tcp_close/7 (715827 (estimated locally),1.00 per call) 
  Calls: sys_now/33 (401890827 (estimated locally),0.37 per call) 
   Indirect call(401890827 (estimated locally),0.37 per call)  of param:0 loaded from aggregate passed by reference at offset 192 (vptr maybe changed)
lwiperf_list_find/5 (lwiperf_list_find) @061182a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: lwiperf_all_connections/1 (read)
  Referring: 
  Availability: local
  Function flags: count:114863532 (estimated locally) body local optimize_size
  Called by: lwiperf_tcp_accept.part.0/50 (37196 (estimated locally),0.12 per call) 
  Calls: 
lwiperf_list_remove/4 (lwiperf_list_remove) @06118000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: lwiperf_all_connections/1 (read)lwiperf_all_connections/1 (write)
  Referring: 
  Availability: local
  Function flags: count:454857 (estimated locally) body local optimize_size
  Called by: lwiperf_tcp_close/7 (715827 (estimated locally),1.00 per call) 
  Calls: 
lwiperf_list_add/3 (lwiperf_list_add) @060eed20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: lwiperf_all_connections/1 (read)lwiperf_all_connections/1 (write)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: lwiperf_start_tcp_server_impl.part.0.constprop/58 (513017274 (estimated locally),0.48 per call) lwiperf_tx_start_impl.part.0/54 (699060718 (estimated locally),0.65 per call) lwiperf_tcp_accept.part.0/50 (148783 (estimated locally),0.48 per call) 
  Calls: 
lwiperf_txbuf_const/2 (lwiperf_txbuf_const) @060ea828
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: lwiperf_tcp_client_send_more.part.0/51 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
lwiperf_all_connections/1 (lwiperf_all_connections) @060ea750
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: lwiperf_list_add/3 (write)lwiperf_list_add/3 (read)lwiperf_list_find/5 (read)lwiperf_list_remove/4 (write)lwiperf_list_remove/4 (read)lwiperf_abort/22 (read)
  Availability: available
  Varpool flags:

;; Function lwiperf_tcp_close (lwiperf_tcp_close, funcdef_no=5, decl_uid=7461, cgraph_uid=6, symbol_order=7)

Modification phase of node lwiperf_tcp_close/7
Adjusting mask for param 1 to 0x7
Setting value range of param 1 [0, 5]
lwiperf_tcp_close (struct lwiperf_state_tcp_t * conn, lwiperf_report_type report_type)
{
  err_t err;
  struct lwiperf_state_base_t * _1;
  struct tcp_pcb * _2;
  struct tcp_pcb * _3;
  struct tcp_pcb * _4;
  struct tcp_pcb * _5;
  struct tcp_pcb * _6;
  struct tcp_pcb * _7;
  struct tcp_pcb * _8;
  struct tcp_pcb * _9;

  <bb 2> [local count: 715827]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = &conn_12(D)->base;
  lwiperf_list_remove (_1);
  # DEBUG BEGIN_STMT
  lwip_tcp_conn_report (conn_12(D), report_type_15(D));
  # DEBUG BEGIN_STMT
  _2 = conn_12(D)->conn_pcb;
  if (_2 != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 5>; [30.00%]

  <bb 3> [local count: 501079]:
  # DEBUG BEGIN_STMT
  tcp_arg (_2, 0B);
  # DEBUG BEGIN_STMT
  _3 = conn_12(D)->conn_pcb;
  tcp_poll (_3, 0B, 0);
  # DEBUG BEGIN_STMT
  _4 = conn_12(D)->conn_pcb;
  tcp_sent (_4, 0B);
  # DEBUG BEGIN_STMT
  _5 = conn_12(D)->conn_pcb;
  tcp_recv (_5, 0B);
  # DEBUG BEGIN_STMT
  _6 = conn_12(D)->conn_pcb;
  tcp_err (_6, 0B);
  # DEBUG BEGIN_STMT
  _7 = conn_12(D)->conn_pcb;
  err_26 = tcp_close (_7);
  # DEBUG err => err_26
  # DEBUG BEGIN_STMT
  if (err_26 != 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 7>; [67.00%]

  <bb 4> [local count: 165356]:
  # DEBUG BEGIN_STMT
  _8 = conn_12(D)->conn_pcb;
  tcp_abort (_8);
  goto <bb 7>; [100.00%]

  <bb 5> [local count: 214748]:
  # DEBUG BEGIN_STMT
  _9 = conn_12(D)->server_pcb;
  err_18 = tcp_close (_9);
  # DEBUG err => err_18
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (err_18 != 0)
    goto <bb 8>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 8> [local count: 107374]:

  <bb 6> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 9> [local count: 1073741824]:
  goto <bb 6>; [100.00%]

  <bb 7> [local count: 608453]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mem_free (conn_12(D));
  return;

}



;; Function lwiperf_tcp_err (lwiperf_tcp_err, funcdef_no=12, decl_uid=7422, cgraph_uid=13, symbol_order=14)

Modification phase of node lwiperf_tcp_err/14
lwiperf_tcp_err (void * arg, err_t err)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG conn => arg_1(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  lwiperf_tcp_close (arg_1(D), 5);
  return;

}



;; Function lwiperf_tcp_accept (lwiperf_tcp_accept, funcdef_no=14, decl_uid=7553, cgraph_uid=15, symbol_order=16)

Modification phase of node lwiperf_tcp_accept/16
lwiperf_tcp_accept (void * arg, struct tcp_pcb * newpcb, err_t err)
{
  unsigned char _1;
  struct tcp_pcb * _2;
  struct tcp_pcb * _3;
  err_t _5;
  signed char _9;

  <bb 2> [local count: 218971]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (err_10(D) != 0)
    goto <bb 12>; [1.04%]
  else
    goto <bb 3>; [98.96%]

  <bb 3> [local count: 216694]:
  if (newpcb_11(D) == 0B)
    goto <bb 12>; [0.45%]
  else
    goto <bb 4>; [99.55%]

  <bb 4> [local count: 215719]:
  if (arg_12(D) == 0B)
    goto <bb 12>; [0.45%]
  else
    goto <bb 5>; [99.55%]

  <bb 5> [local count: 214748]:
  # DEBUG BEGIN_STMT
  # DEBUG s => arg_12(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = MEM[(struct lwiperf_state_tcp_t *)arg_12(D)].base.server;
  if (_1 == 0)
    goto <bb 13>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 13> [local count: 107374]:

  <bb 6> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 16> [local count: 1073741824]:
  goto <bb 6>; [100.00%]

  <bb 7> [local count: 107374]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = MEM[(struct lwiperf_state_tcp_t *)arg_12(D)].server_pcb;
  if (_2 == 0B)
    goto <bb 14>; [30.00%]
  else
    goto <bb 9>; [70.00%]

  <bb 14> [local count: 32212]:

  <bb 8> [local count: 322122547]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 17> [local count: 322122547]:
  goto <bb 8>; [100.00%]

  <bb 9> [local count: 75162]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = MEM[(struct lwiperf_state_tcp_t *)arg_12(D)].conn_pcb;
  if (_3 != 0B)
    goto <bb 15>; [70.00%]
  else
    goto <bb 11>; [30.00%]

  <bb 15> [local count: 52613]:

  <bb 10> [local count: 526133494]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 18> [local count: 526133494]:
  goto <bb 10>; [100.00%]

  <bb 11> [local count: 22549]:
  # DEBUG D#1 => err_10(D)
  _9 = lwiperf_tcp_accept.part.0 (arg_12(D), newpcb_11(D));

  <bb 12> [local count: 15497]:
  # _5 = PHI <-6(3), _9(11), -6(2), -6(4)>
  return _5;

}



;; Function lwiperf_tcp_client_send_more (lwiperf_tcp_client_send_more, funcdef_no=6, decl_uid=7466, cgraph_uid=7, symbol_order=8)

Modification phase of node lwiperf_tcp_client_send_more/8
lwiperf_tcp_client_send_more (struct lwiperf_state_tcp_t * conn)
{
  unsigned char _1;
  unsigned char _2;

  <bb 2> [local count: 130150]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (conn_6(D) == 0B)
    goto <bb 5>; [30.00%]
  else
    goto <bb 3>; [70.00%]

  <bb 3> [local count: 91105]:
  _1 = conn_6(D)->base.tcp;
  if (_1 == 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 4> [local count: 45553]:
  _2 = conn_6(D)->base.server;
  if (_2 != 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 5> [local count: 107374]:

  <bb 6> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 8> [local count: 1073741824]:
  goto <bb 6>; [100.00%]

  <bb 7> [local count: 22776]:
  lwiperf_tcp_client_send_more.part.0 (conn_6(D));
  return 0;

}



;; Function lwiperf_tcp_client_sent (lwiperf_tcp_client_sent, funcdef_no=7, decl_uid=7487, cgraph_uid=8, symbol_order=9)

Modification phase of node lwiperf_tcp_client_sent/9
lwiperf_tcp_client_sent (void * arg, struct tcp_pcb * tpcb, u16_t len)
{
  err_t D.7916;
  struct tcp_pcb * _1;

  <bb 2> [local count: 130040]:
  # DEBUG BEGIN_STMT
  # DEBUG conn => arg_3(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = MEM[(struct lwiperf_state_tcp_t *)arg_3(D)].conn_pcb;
  if (_1 != tpcb_6(D))
    goto <bb 5>; [82.57%]
  else
    goto <bb 4>; [17.43%]

  <bb 5> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 22666]:
  # DEBUG D#5 => tpcb_6(D)
  # DEBUG D#6 => len_4(D)
  _8 = lwiperf_tcp_client_sent.part.0 (arg_3(D));
  return _8;

}



;; Function lwiperf_tcp_poll (lwiperf_tcp_poll, funcdef_no=13, decl_uid=7419, cgraph_uid=14, symbol_order=15)

Modification phase of node lwiperf_tcp_poll/15
lwiperf_tcp_poll (void * arg, struct tcp_pcb * tpcb)
{
  struct tcp_pcb * _1;
  unsigned char _2;
  unsigned char _3;

  <bb 2> [local count: 153391]:
  # DEBUG BEGIN_STMT
  # DEBUG conn => arg_7(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = MEM[(struct lwiperf_state_tcp_t *)arg_7(D)].conn_pcb;
  if (_1 != tpcb_9(D))
    goto <bb 8>; [70.00%]
  else
    goto <bb 4>; [30.00%]

  <bb 8> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 9> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 46017]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = MEM[(struct lwiperf_state_tcp_t *)arg_7(D)].poll_count;
  _3 = _2 + 1;
  MEM[(struct lwiperf_state_tcp_t *)arg_7(D)].poll_count = _3;
  if (_3 > 9)
    goto <bb 5>; [20.24%]
  else
    goto <bb 6>; [79.76%]

  <bb 5> [local count: 9314]:
  # DEBUG BEGIN_STMT
  lwiperf_tcp_close (arg_7(D), 2);
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 6> [local count: 36703]:
  # DEBUG D#9 => tpcb_9(D)
  lwiperf_tcp_poll.part.0 (arg_7(D));

  <bb 7> [local count: 46017]:
  return 0;

}



;; Function lwiperf_tcp_client_connected (lwiperf_tcp_client_connected, funcdef_no=8, decl_uid=7494, cgraph_uid=9, symbol_order=10)

Modification phase of node lwiperf_tcp_client_connected/10
lwiperf_tcp_client_connected (void * arg, struct tcp_pcb * tpcb, err_t err)
{
  struct tcp_pcb * _1;
  err_t _2;
  signed char _5;

  <bb 2> [local count: 153391]:
  # DEBUG BEGIN_STMT
  # DEBUG conn => arg_4(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = MEM[(struct lwiperf_state_tcp_t *)arg_4(D)].conn_pcb;
  if (_1 != tpcb_7(D))
    goto <bb 8>; [70.00%]
  else
    goto <bb 4>; [30.00%]

  <bb 8> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 9> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 46017]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (err_8(D) != 0)
    goto <bb 5>; [34.00%]
  else
    goto <bb 6>; [66.00%]

  <bb 5> [local count: 15646]:
  # DEBUG BEGIN_STMT
  lwiperf_tcp_close (arg_4(D), 5);
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 6> [local count: 30371]:
  # DEBUG D#13 => tpcb_7(D)
  # DEBUG D#14 => err_8(D)
  _5 = lwiperf_tcp_client_connected.part.0 (arg_4(D));

  <bb 7> [local count: 46017]:
  # _2 = PHI <0(5), _5(6)>
  return _2;

}



;; Function lwiperf_start_tcp_server_impl.part.0.constprop (lwiperf_start_tcp_server_impl.part.0.constprop.0, funcdef_no=29, decl_uid=7970, cgraph_uid=56, symbol_order=58)

Modification phase of node lwiperf_start_tcp_server_impl.part.0.constprop/58
Adjusting mask for param 5 to 0xfffffffc
Adjusting align: 4, misalign: 0
Setting nonnull for 5
     Aggregate replacements: 5[0]=0B
lwiperf_start_tcp_server_impl.part.0.constprop (const struct ip_addr_t * local_addr, u16_t local_port, void (*lwiperf_report_fn) (void *, lwiperf_report_type, const struct ip_addr_t *, u16_t, const struct ip_addr_t *, u16_t, u32_t, u32_t, u32_t) report_fn, void * report_arg, struct lwiperf_state_base_t * related_master_state, struct lwiperf_state_tcp_t * * state)
{
  struct lwiperf_state_tcp_t * s;
  struct tcp_pcb * pcb;
  err_t err;
  struct tcp_pcb * _9;
  struct tcp_pcb * _10;
  struct lwiperf_state_base_t * _11;
  signed char _13;

  <bb 13> [local count: 1073741824]:

  <bb 2> [local count: 1073741824]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  s_1 = mem_malloc (92);
  # DEBUG s => s_1
  # DEBUG BEGIN_STMT
  if (s_1 == 0B)
    goto <bb 4>; [0.91%]
  else
    goto <bb 5>; [99.09%]

  <bb 4> [local count: 9771051]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by early return (on trees) predictor.
  goto <bb 12>; [100.00%]

  <bb 5> [local count: 1063970774]:
  # DEBUG BEGIN_STMT
  memset (s_1, 0, 92);
  # DEBUG BEGIN_STMT
  s_1->base.tcp = 1;
  # DEBUG BEGIN_STMT
  s_1->base.server = 1;
  # DEBUG BEGIN_STMT
  s_1->base.related_master_state = related_master_state_2(D);
  # DEBUG BEGIN_STMT
  s_1->report_fn = report_fn_3(D);
  # DEBUG BEGIN_STMT
  s_1->report_arg = report_arg_4(D);
  # DEBUG BEGIN_STMT
  pcb_5 = tcp_new_ip_type (46);
  # DEBUG pcb => pcb_5
  # DEBUG BEGIN_STMT
  if (pcb_5 == 0B)
    goto <bb 6>; [0.91%]
  else
    goto <bb 7>; [99.09%]

  <bb 6> [local count: 9682134]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by early return (on trees) predictor.
  goto <bb 12>; [100.00%]

  <bb 7> [local count: 1054288640]:
  # DEBUG BEGIN_STMT
  err_8 = tcp_bind (pcb_5, local_addr_6(D), local_port_7(D));
  # DEBUG err => err_8
  # DEBUG BEGIN_STMT
  if (err_8 != 0)
    goto <bb 8>; [51.12%]
  else
    goto <bb 9>; [48.88%]

  <bb 8> [local count: 538952353]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by early return (on trees) predictor.
  goto <bb 12>; [100.00%]

  <bb 9> [local count: 515336287]:
  # DEBUG BEGIN_STMT
  _9 = tcp_listen_with_backlog (pcb_5, 1);
  s_1->server_pcb = _9;
  # DEBUG BEGIN_STMT
  if (_9 == 0B)
    goto <bb 10>; [0.45%]
  else
    goto <bb 11>; [99.55%]

  <bb 10> [local count: 2319013]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tcp_close (pcb_5);
  # DEBUG BEGIN_STMT
  mem_free (s_1);
  # DEBUG BEGIN_STMT
  // predicted unlikely by early return (on trees) predictor.
  goto <bb 12>; [100.00%]

  <bb 11> [local count: 513017274]:
  # DEBUG BEGIN_STMT
  # DEBUG pcb => 0B
  # DEBUG BEGIN_STMT
  tcp_arg (_9, s_1);
  # DEBUG BEGIN_STMT
  _10 = s_1->server_pcb;
  tcp_accept (_10, lwiperf_tcp_accept);
  # DEBUG BEGIN_STMT
  _11 = &s_1->base;
  lwiperf_list_add (_11);
  # DEBUG BEGIN_STMT
  *state_12(D) = s_1;
  # DEBUG BEGIN_STMT

  <bb 12> [local count: 1073741824]:
  # _13 = PHI <-1(4), -1(6), err_8(8), -1(10), 0(11)>
  return _13;

}



;; Function lwiperf_tx_start_impl.part.0 (lwiperf_tx_start_impl.part.0, funcdef_no=26, decl_uid=7925, cgraph_uid=52, symbol_order=54)

Modification phase of node lwiperf_tx_start_impl.part.0/54
Adjusting mask for param 6 to 0xfffffffc
Adjusting align: 4, misalign: 0
Setting nonnull for 2
Setting nonnull for 6
lwiperf_tx_start_impl.part.0 (const struct ip_addr_t * remote_ip, u16_t remote_port, struct lwiperf_settings_t * settings, void (*lwiperf_report_fn) (void *, lwiperf_report_type, const struct ip_addr_t *, u16_t, const struct ip_addr_t *, u16_t, u32_t, u32_t, u32_t) report_fn, void * report_arg, struct lwiperf_state_base_t * related_master_state, struct lwiperf_state_tcp_t * * new_conn)
{
  err_t err;
  struct lwiperf_state_tcp_t * client_conn;
  struct tcp_pcb * newpcb;
  struct ip_addr_t remote_addr;
  unsigned char _4;
  long unsigned int _7;
  struct lwiperf_settings_t * _10;
  unsigned char _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  unsigned char _17;
  long unsigned int _18;
  struct lwiperf_state_base_t * _21;
  signed char _22;

  <bb 13> [local count: 1073741824]:

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  *new_conn_1(D) = 0B;
  # DEBUG BEGIN_STMT
  client_conn_2 = mem_malloc (92);
  # DEBUG client_conn => client_conn_2
  # DEBUG BEGIN_STMT
  if (client_conn_2 == 0B)
    goto <bb 3>; [0.91%]
  else
    goto <bb 4>; [99.09%]

  <bb 3> [local count: 9771051]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by early return (on trees) predictor.
  goto <bb 12>; [100.00%]

  <bb 4> [local count: 1063970774]:
  # DEBUG BEGIN_STMT
  _4 = remote_ip_3(D)->type;
  newpcb_5 = tcp_new_ip_type (_4);
  # DEBUG newpcb => newpcb_5
  # DEBUG BEGIN_STMT
  if (newpcb_5 == 0B)
    goto <bb 5>; [0.45%]
  else
    goto <bb 6>; [99.55%]

  <bb 5> [local count: 4787868]:
  # DEBUG BEGIN_STMT
  mem_free (client_conn_2);
  # DEBUG BEGIN_STMT
  // predicted unlikely by early return (on trees) predictor.
  goto <bb 12>; [100.00%]

  <bb 6> [local count: 1059182906]:
  # DEBUG BEGIN_STMT
  memset (client_conn_2, 0, 92);
  # DEBUG BEGIN_STMT
  client_conn_2->base.tcp = 1;
  # DEBUG BEGIN_STMT
  client_conn_2->base.related_master_state = related_master_state_6(D);
  # DEBUG BEGIN_STMT
  client_conn_2->conn_pcb = newpcb_5;
  # DEBUG BEGIN_STMT
  _7 = sys_now ();
  client_conn_2->time_started = _7;
  # DEBUG BEGIN_STMT
  client_conn_2->report_fn = report_fn_8(D);
  # DEBUG BEGIN_STMT
  client_conn_2->report_arg = report_arg_9(D);
  # DEBUG BEGIN_STMT
  client_conn_2->next_num = 4;
  # DEBUG BEGIN_STMT
  client_conn_2->bytes_transferred = 0;
  # DEBUG BEGIN_STMT
  _10 = &client_conn_2->settings;
  memcpy (_10, settings_11(D), 24);
  # DEBUG BEGIN_STMT
  client_conn_2->have_settings_buf = 1;
  # DEBUG BEGIN_STMT
  tcp_arg (newpcb_5, client_conn_2);
  # DEBUG BEGIN_STMT
  tcp_sent (newpcb_5, lwiperf_tcp_client_sent);
  # DEBUG BEGIN_STMT
  tcp_poll (newpcb_5, lwiperf_tcp_poll, 2);
  # DEBUG BEGIN_STMT
  tcp_err (newpcb_5, lwiperf_tcp_err);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _12 = remote_ip_3(D)->type;
  remote_addr.type = _12;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (_12 == 6)
    goto <bb 7>; [34.00%]
  else
    goto <bb 8>; [66.00%]

  <bb 7> [local count: 360122188]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _13 = remote_ip_3(D)->u_addr.ip6.addr[0];
  remote_addr.u_addr.ip6.addr[0] = _13;
  # DEBUG BEGIN_STMT
  _14 = remote_ip_3(D)->u_addr.ip6.addr[1];
  remote_addr.u_addr.ip6.addr[1] = _14;
  # DEBUG BEGIN_STMT
  _15 = remote_ip_3(D)->u_addr.ip6.addr[2];
  remote_addr.u_addr.ip6.addr[2] = _15;
  # DEBUG BEGIN_STMT
  _16 = remote_ip_3(D)->u_addr.ip6.addr[3];
  remote_addr.u_addr.ip6.addr[3] = _16;
  # DEBUG BEGIN_STMT
  _17 = remote_ip_3(D)->u_addr.ip6.zone;
  remote_addr.u_addr.ip6.zone = _17;
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 8> [local count: 699060718]:
  # DEBUG BEGIN_STMT
  _18 = remote_ip_3(D)->u_addr.ip4.addr;
  remote_addr.u_addr.ip4.addr = _18;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  remote_addr.u_addr.ip6.addr[3] = 0;
  remote_addr.u_addr.ip6.addr[2] = 0;
  remote_addr.u_addr.ip6.addr[1] = 0;
  # DEBUG BEGIN_STMT
  remote_addr.u_addr.ip6.zone = 0;

  <bb 9> [local count: 1059182906]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  err_20 = tcp_connect (newpcb_5, &remote_addr, remote_port_19(D), lwiperf_tcp_client_connected);
  # DEBUG err => err_20
  # DEBUG BEGIN_STMT
  if (err_20 != 0)
    goto <bb 10>; [34.00%]
  else
    goto <bb 11>; [66.00%]

  <bb 10> [local count: 360122188]:
  # DEBUG BEGIN_STMT
  lwiperf_tcp_close (client_conn_2, 2);
  # DEBUG BEGIN_STMT
  // predicted unlikely by early return (on trees) predictor.
  goto <bb 12>; [100.00%]

  <bb 11> [local count: 699060718]:
  # DEBUG BEGIN_STMT
  _21 = &client_conn_2->base;
  lwiperf_list_add (_21);
  # DEBUG BEGIN_STMT
  *new_conn_1(D) = client_conn_2;
  # DEBUG BEGIN_STMT

  <bb 12> [local count: 1073741824]:
  # _22 = PHI <-1(3), -1(5), err_20(10), 0(11)>
  remote_addr ={v} {CLOBBER};
  return _22;

}



;; Function lwiperf_tx_start_passive (lwiperf_tx_start_passive, funcdef_no=10, decl_uid=7515, cgraph_uid=11, symbol_order=12)

Modification phase of node lwiperf_tx_start_passive/12
lwiperf_tx_start_passive (struct lwiperf_state_tcp_t * conn)
{
  u16_t remote_port;
  struct lwiperf_state_tcp_t * new_conn;
  err_t ret;
  long unsigned int _1;
  long unsigned int _2;
  struct tcp_pcb * _3;
  struct ip_addr_t * _4;
  struct lwiperf_settings_t * _5;
  void (*<T639>) (void *, lwiperf_report_type, const struct ip_addr_t *, u16_t, const struct ip_addr_t *, u16_t, u32_t, u32_t, u32_t) _6;
  void * _7;
  struct lwiperf_state_base_t * _8;
  struct lwiperf_state_tcp_t * new_conn.3_9;

  <bb 2> [local count: 715827]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  new_conn = 0B;
  # DEBUG BEGIN_STMT
  _1 = conn_14(D)->settings.remote_port;
  _2 = lwip_htonl (_1);
  remote_port_16 = (u16_t) _2;
  # DEBUG remote_port => remote_port_16
  # DEBUG BEGIN_STMT
  _3 = conn_14(D)->conn_pcb;
  _4 = &_3->remote_ip;
  _5 = &conn_14(D)->settings;
  _6 = conn_14(D)->report_fn;
  _7 = conn_14(D)->report_arg;
  _8 = conn_14(D)->base.related_master_state;
  ret_18 = lwiperf_tx_start_impl (_4, remote_port_16, _5, _6, _7, _8, &new_conn);
  # DEBUG ret => ret_18
  # DEBUG BEGIN_STMT
  if (ret_18 == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 3> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  new_conn.3_9 = new_conn;
  if (new_conn.3_9 == 0B)
    goto <bb 7>; [30.00%]
  else
    goto <bb 5>; [70.00%]

  <bb 7> [local count: 107374]:

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 8> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  new_conn.3_9->settings.flags = 0;

  <bb 6> [local count: 608453]:
  # DEBUG BEGIN_STMT
  new_conn ={v} {CLOBBER};
  return ret_18;

}



;; Function lwiperf_tcp_recv (lwiperf_tcp_recv, funcdef_no=11, decl_uid=7525, cgraph_uid=12, symbol_order=13)

Modification phase of node lwiperf_tcp_recv/13
lwiperf_tcp_recv (void * arg, struct tcp_pcb * tpcb, struct pbuf * p, err_t err)
{
  struct tcp_pcb * _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;

  <bb 2> [local count: 153391]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG conn => arg_9(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = MEM[(struct lwiperf_state_tcp_t *)arg_9(D)].conn_pcb;
  if (_1 != tpcb_11(D))
    goto <bb 13>; [70.00%]
  else
    goto <bb 4>; [30.00%]

  <bb 13> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 14> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 46017]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (err_12(D) != 0)
    goto <bb 5>; [20.24%]
  else
    goto <bb 6>; [79.76%]

  <bb 5> [local count: 9314]:
  # DEBUG BEGIN_STMT
  lwiperf_tcp_close (arg_9(D), 5);
  # DEBUG BEGIN_STMT
  goto <bb 12>; [100.00%]

  <bb 6> [local count: 36704]:
  # DEBUG BEGIN_STMT
  if (p_13(D) == 0B)
    goto <bb 7>; [18.09%]
  else
    goto <bb 11>; [81.91%]

  <bb 7> [local count: 6640]:
  # DEBUG BEGIN_STMT
  _2 = MEM[(struct lwiperf_state_tcp_t *)arg_9(D)].settings.flags;
  _3 = _2 & 128;
  if (_3 != 0)
    goto <bb 8>; [50.00%]
  else
    goto <bb 10>; [50.00%]

  <bb 8> [local count: 3320]:
  # DEBUG BEGIN_STMT
  _4 = _2 & 16777216;
  if (_4 == 0)
    goto <bb 9>; [33.00%]
  else
    goto <bb 10>; [67.00%]

  <bb 9> [local count: 1096]:
  # DEBUG BEGIN_STMT
  lwiperf_tx_start_passive (arg_9(D));

  <bb 10> [local count: 6640]:
  # DEBUG BEGIN_STMT
  lwiperf_tcp_close (arg_9(D), 0);
  # DEBUG BEGIN_STMT
  goto <bb 12>; [100.00%]

  <bb 11> [local count: 30064]:
  # DEBUG D#11 => err_12(D)
  lwiperf_tcp_recv.part.0 (arg_9(D), tpcb_11(D), p_13(D));

  <bb 12> [local count: 31072]:
  return 0;

}



;; Function lwiperf_start_tcp_server (lwiperf_start_tcp_server, funcdef_no=16, decl_uid=6319, cgraph_uid=17, symbol_order=18)

Modification phase of node lwiperf_start_tcp_server/18
lwiperf_start_tcp_server (const struct ip_addr_t * local_addr, u16_t local_port, void (*lwiperf_report_fn) (void *, lwiperf_report_type, const struct ip_addr_t *, u16_t, const struct ip_addr_t *, u16_t, u32_t, u32_t, u32_t) report_fn, void * report_arg)
{
  struct lwiperf_state_tcp_t * state;
  err_t err;
  void * _1;
  void * _10;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  state = 0B;
  # DEBUG BEGIN_STMT
  err_9 = lwiperf_start_tcp_server_impl (local_addr_4(D), local_port_5(D), report_fn_6(D), report_arg_7(D), 0B, &state);
  # DEBUG err => err_9
  # DEBUG BEGIN_STMT
  if (err_9 == 0)
    goto <bb 3>; [55.78%]
  else
    goto <bb 4>; [44.22%]

  <bb 3> [local count: 598933190]:
  # DEBUG BEGIN_STMT
  _10 = state;

  <bb 4> [local count: 1073741824]:
  # _1 = PHI <_10(3), 0B(2)>
  state ={v} {CLOBBER};
  return _1;

}



;; Function lwiperf_start_tcp_server_default (lwiperf_start_tcp_server_default, funcdef_no=15, decl_uid=6322, cgraph_uid=16, symbol_order=17)

Modification phase of node lwiperf_start_tcp_server_default/17
lwiperf_start_tcp_server_default (void (*lwiperf_report_fn) (void *, lwiperf_report_type, const struct ip_addr_t *, u16_t, const struct ip_addr_t *, u16_t, u32_t, u32_t, u32_t) report_fn, void * report_arg)
{
  void * _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _5 = lwiperf_start_tcp_server (&ip_addr_any, 5001, report_fn_2(D), report_arg_3(D));
  return _5;

}



;; Function lwiperf_abort (lwiperf_abort, funcdef_no=20, decl_uid=6334, cgraph_uid=21, symbol_order=22)

Modification phase of node lwiperf_abort/22
lwiperf_abort (void * lwiperf_session)
{
  struct lwiperf_state_base_t * last;
  struct lwiperf_state_base_t * i;
  struct lwiperf_state_base_t * _1;

  <bb 2> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  # DEBUG last => 0B
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  i_8 = lwiperf_all_connections;
  # DEBUG i => i_8
  goto <bb 12>; [100.00%]

  <bb 3> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  if (i_2 == lwiperf_session_9(D))
    goto <bb 5>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 4> [local count: 668941156]:
  _1 = i_2->related_master_state;
  if (_1 == lwiperf_session_9(D))
    goto <bb 5>; [30.00%]
  else
    goto <bb 8>; [70.00%]

  <bb 5> [local count: 487371413]:
  # DEBUG BEGIN_STMT
  # DEBUG dealloc => i_2
  # DEBUG BEGIN_STMT
  i_13 = i_2->next;
  # DEBUG i => i_13
  # DEBUG BEGIN_STMT
  if (last_3 != 0B)
    goto <bb 6>; [70.00%]
  else
    goto <bb 7>; [30.00%]

  <bb 6> [local count: 341159989]:
  # DEBUG BEGIN_STMT
  last_3->next = i_13;

  <bb 7> [local count: 487371413]:
  # DEBUG BEGIN_STMT
  mem_free (i_2);
  goto <bb 10>; [100.00%]

  <bb 8> [local count: 468258809]:
  # DEBUG BEGIN_STMT
  # DEBUG last => i_2
  # DEBUG BEGIN_STMT
  i_11 = i_2->next;
  # DEBUG i => i_11

  <bb 10> [local count: 955630223]:
  # i_6 = PHI <i_13(7), i_11(8)>
  # last_12 = PHI <last_3(7), i_2(8)>

  <bb 12> [local count: 1073741824]:
  # i_2 = PHI <i_6(10), i_8(2)>
  # last_3 = PHI <last_12(10), 0B(2)>
  # DEBUG last => last_3
  # DEBUG i => i_2
  # DEBUG BEGIN_STMT
  if (i_2 != 0B)
    goto <bb 3>; [89.00%]
  else
    goto <bb 11>; [11.00%]

  <bb 11> [local count: 118111601]:
  return;

}



;; Function lwiperf_start_tcp_client (lwiperf_start_tcp_client, funcdef_no=19, decl_uid=6328, cgraph_uid=20, symbol_order=21)

Modification phase of node lwiperf_start_tcp_client/21
lwiperf_start_tcp_client (const struct ip_addr_t * remote_addr, u16_t remote_port, lwiperf_client_type type, void (*lwiperf_report_fn) (void *, lwiperf_report_type, const struct ip_addr_t *, u16_t, const struct ip_addr_t *, u16_t, u32_t, u32_t, u32_t) report_fn, void * report_arg)
{
  struct lwiperf_state_tcp_t * server;
  struct lwiperf_state_tcp_t * state;
  struct lwiperf_settings_t settings;
  err_t ret;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  struct lwiperf_state_tcp_t * state.6_6;
  struct tcp_pcb * _7;
  struct ip_addr_t * _8;
  struct lwiperf_state_tcp_t * state.9_9;
  struct lwiperf_state_tcp_t * server.10_10;
  struct lwiperf_state_tcp_t * state.11_11;
  struct tcp_pcb * _12;
  void * _13;
  void * _48;

  <bb 2> [local count: 672138]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  state = 0B;
  # DEBUG BEGIN_STMT
  memset (&settings, 0, 24);
  # DEBUG BEGIN_STMT
  switch (type_22(D)) <default: <L20> [25.00%], case 0: <L21> [25.00%], case 1: <L1> [25.00%], case 2: <L2> [25.00%]>

  <bb 3> [local count: 168034]:
<L1>:
  # DEBUG BEGIN_STMT
  _1 = lwip_htonl (2147483649);
  settings.flags = _1;
  # DEBUG BEGIN_STMT
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 168034]:
<L2>:
  # DEBUG BEGIN_STMT
  _2 = lwip_htonl (2147483648);
  settings.flags = _2;
  # DEBUG BEGIN_STMT

  <bb 5> [local count: 504103]:
<L21>:
  # DEBUG BEGIN_STMT
  _3 = lwip_htonl (1);
  settings.num_threads = _3;
  # DEBUG BEGIN_STMT
  _4 = lwip_htonl (5001);
  settings.remote_port = _4;
  # DEBUG BEGIN_STMT
  _5 = lwip_htonl (4294966296);
  settings.amount = _5;
  # DEBUG BEGIN_STMT
  ret_38 = lwiperf_tx_start_impl (remote_addr_33(D), remote_port_34(D), &settings, report_fn_35(D), report_arg_36(D), 0B, &state);
  # DEBUG ret => ret_38
  # DEBUG BEGIN_STMT
  if (ret_38 == 0)
    goto <bb 6>; [71.00%]
  else
    goto <bb 15>; [29.00%]

  <bb 6> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  state.6_6 = state;
  if (state.6_6 == 0B)
    goto <bb 16>; [30.00%]
  else
    goto <bb 8>; [70.00%]

  <bb 16> [local count: 107374]:

  <bb 7> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 17> [local count: 1073741824]:
  goto <bb 7>; [100.00%]

  <bb 8> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (type_22(D) != 0)
    goto <bb 9>; [48.88%]
  else
    goto <bb 14>; [51.12%]

  <bb 9> [local count: 122464]:
  # DEBUG BEGIN_STMT
  server = 0B;
  # DEBUG BEGIN_STMT
  _7 = state.6_6->conn_pcb;
  _8 = &_7->local_ip;
  ret_41 = lwiperf_start_tcp_server_impl (_8, 5001, report_fn_35(D), report_arg_36(D), state.6_6, &server);
  # DEBUG ret => ret_41
  # DEBUG BEGIN_STMT
  if (ret_41 != 0)
    goto <bb 10>; [16.75%]
  else
    goto <bb 11>; [83.25%]

  <bb 10> [local count: 20513]:
  # DEBUG BEGIN_STMT
  state.9_9 = state;
  lwiperf_abort (state.9_9);
  # DEBUG BEGIN_STMT
  server ={v} {CLOBBER};
  goto <bb 15>; [100.00%]

  <bb 11> [local count: 101951]:
  # DEBUG BEGIN_STMT
  server.10_10 = server;
  server.10_10->specific_remote = 1;
  # DEBUG BEGIN_STMT
  state.11_11 = state;
  _12 = state.11_11->conn_pcb;
  server.10_10->remote_addr = _12->remote_ip;
  # DEBUG BEGIN_STMT
  if (type_22(D) == 2)
    goto <bb 12>; [34.00%]
  else
    goto <bb 13>; [66.00%]

  <bb 12> [local count: 34663]:
  # DEBUG BEGIN_STMT
  server.10_10->client_tradeoff_mode = 1;

  <bb 13> [local count: 101951]:
  server ={v} {CLOBBER};

  <bb 14> [local count: 230027]:
  # DEBUG BEGIN_STMT
  _48 = state;

  <bb 15> [local count: 564764]:
  # _13 = PHI <0B(2), 0B(10), _48(14), 0B(5)>
<L20>:
  settings ={v} {CLOBBER};
  state ={v} {CLOBBER};
  return _13;

}



;; Function lwiperf_start_tcp_client_default (lwiperf_start_tcp_client_default, funcdef_no=18, decl_uid=6332, cgraph_uid=19, symbol_order=20)

Modification phase of node lwiperf_start_tcp_client_default/20
lwiperf_start_tcp_client_default (const struct ip_addr_t * remote_addr, void (*lwiperf_report_fn) (void *, lwiperf_report_type, const struct ip_addr_t *, u16_t, const struct ip_addr_t *, u16_t, u32_t, u32_t, u32_t) report_fn, void * report_arg)
{
  void * _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _6 = lwiperf_start_tcp_client (remote_addr_2(D), 5001, 0, report_fn_3(D), report_arg_4(D));
  return _6;

}


