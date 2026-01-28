
IPA constant propagation start:
Determining dynamic type for call: res_5 = mqtt_parse_incoming (arg_4(D), p_1(D));
  Starting walk at: res_5 = mqtt_parse_incoming (arg_4(D), p_1(D));
  instance pointer: arg_4(D)  Outer instance pointer: arg_4(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_recved (pcb_3(D), _2);
Determining dynamic type for call: res_5 = mqtt_parse_incoming (arg_4(D), p_1(D));
  Starting walk at: res_5 = mqtt_parse_incoming (arg_4(D), p_1(D));
  instance pointer: p_1(D)  Outer instance pointer: p_1(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_recved (pcb_3(D), _2);
Determining dynamic type for call: mqtt_close (arg_4(D), res_5);
  Starting walk at: mqtt_close (arg_4(D), res_5);
  instance pointer: arg_4(D)  Outer instance pointer: arg_4(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pbuf_free (p_1(D));
  Function call may change dynamic type:res_5 = mqtt_parse_incoming (arg_4(D), p_1(D));
  Function call may change dynamic type:tcp_recved (pcb_3(D), _2);
Determining dynamic type for call: mqtt_output_send (_3, _4);
  Starting walk at: mqtt_output_send (_3, _4);
  instance pointer: _3  Outer instance pointer: arg_1(D) offset: 1888 (bits) vtbl reference: 
  Function call may change dynamic type:sys_timeout (5000, mqtt_cyclic_timer, arg_1(D));
  Function call may change dynamic type:tcp_poll (tpcb_2(D), mqtt_tcp_poll_cb, 2);
  Function call may change dynamic type:tcp_sent (tpcb_2(D), mqtt_tcp_sent_cb);
  Function call may change dynamic type:tcp_recv (tpcb_2(D), mqtt_tcp_recv_cb);
Determining dynamic type for call: mqtt_output_send (_3, _4);
  Starting walk at: mqtt_output_send (_3, _4);
  instance pointer: _4  Outer instance pointer: _4 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:sys_timeout (5000, mqtt_cyclic_timer, arg_1(D));
  Function call may change dynamic type:tcp_poll (tpcb_2(D), mqtt_tcp_poll_cb, 2);
  Function call may change dynamic type:tcp_sent (tpcb_2(D), mqtt_tcp_sent_cb);
  Function call may change dynamic type:tcp_recv (tpcb_2(D), mqtt_tcp_recv_cb);
Determining dynamic type for call: mqtt_close (arg_1(D), 256);
  Starting walk at: mqtt_close (arg_1(D), 256);
  instance pointer: arg_1(D)  Outer instance pointer: arg_1(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: r_1 = mqtt_take_request (_5, 0);
  Starting walk at: r_1 = mqtt_take_request (_5, 0);
  instance pointer: _5  Outer instance pointer: arg_4(D) offset: 192 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_delete_request (r_1);
  Function call may change dynamic type:r_1 = mqtt_take_request (_5, 0);
  Function call may change dynamic type:_2 (_3, 0);
Determining dynamic type for call: mqtt_output_send (_6, _7);
  Starting walk at: mqtt_output_send (_6, _7);
  instance pointer: _6  Outer instance pointer: arg_4(D) offset: 1888 (bits) vtbl reference: 
  Function call may change dynamic type:r_1 = mqtt_take_request (_5, 0);
  Function call may change dynamic type:mqtt_delete_request (r_1);
  Function call may change dynamic type:r_1 = mqtt_take_request (_5, 0);
  Function call may change dynamic type:_2 (_3, 0);
Determining dynamic type for call: mqtt_output_send (_6, _7);
  Starting walk at: mqtt_output_send (_6, _7);
  instance pointer: _7  Outer instance pointer: _7 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:r_1 = mqtt_take_request (_5, 0);
  Function call may change dynamic type:mqtt_delete_request (r_1);
  Function call may change dynamic type:r_1 = mqtt_take_request (_5, 0);
  Function call may change dynamic type:_2 (_3, 0);
Determining dynamic type for call: _2 (_3, 0);
  Starting walk at: _2 (_3, 0);
  instance pointer: _3  Outer instance pointer: _3 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:r_1 = mqtt_take_request (_5, 0);
  Function call may change dynamic type:mqtt_delete_request (r_1);
  Function call may change dynamic type:r_1 = mqtt_take_request (_5, 0);
  Function call may change dynamic type:_2 (_3, 0);
Determining dynamic type for call: mqtt_delete_request (r_1);
  Starting walk at: mqtt_delete_request (r_1);
  instance pointer: r_1  Outer instance pointer: r_1 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:r_1 = mqtt_take_request (_5, 0);
  Function call may change dynamic type:mqtt_delete_request (r_1);
  Function call may change dynamic type:_2 (_3, 0);
Determining dynamic type for call: mqtt_ringbuf_advance_get_idx.isra.0.part.0 (ISRA.31_6(D), len_1(D));
  Starting walk at: mqtt_ringbuf_advance_get_idx.isra.0.part.0 (ISRA.31_6(D), len_1(D));
  instance pointer: ISRA.31_6(D)  Outer instance pointer: ISRA.31_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: mqtt_close (client_4(D), 0);
  Starting walk at: mqtt_close (client_4(D), 0);
  instance pointer: client_4(D)  Outer instance pointer: client_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: mqtt_init_requests (_4, 4);
  Starting walk at: mqtt_init_requests (_4, 4);
  instance pointer: _4  Outer instance pointer: client_77(D) offset: 224 (bits) vtbl reference: 
  Function call may change dynamic type:memset (client_77(D), 0, 496);
Determining dynamic type for call: _34 = mqtt_output_check_space (_33, remaining_length_110);
  Starting walk at: _34 = mqtt_output_check_space (_33, remaining_length_110);
  instance pointer: _33  Outer instance pointer: client_77(D) offset: 1888 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_init_requests (_4, 4);
  Function call may change dynamic type:memset (client_77(D), 0, 496);
Determining dynamic type for call: mqtt_output_append_fixed_header (_33, 1, 0, 0, 0, remaining_length_110);
  Starting walk at: mqtt_output_append_fixed_header (_33, 1, 0, 0, 0, remaining_length_110);
  instance pointer: _33  Outer instance pointer: client_77(D) offset: 1888 (bits) vtbl reference: 
  Function call may change dynamic type:tcp_err (_39, mqtt_tcp_err_cb);
  Function call may change dynamic type:err_119 = tcp_connect (_38, ip_addr_79(D), port_117(D), mqtt_tcp_connect_cb);
  Function call may change dynamic type:err_116 = tcp_bind (_37, &ip_addr_any, 0);
  Function call may change dynamic type:tcp_arg (_36, client_77(D));
  Function call may change dynamic type:_36 = tcp_new_ip_type (_35);
  Function call may change dynamic type:_34 = mqtt_output_check_space (_33, remaining_length_110);
  Function call may change dynamic type:mqtt_init_requests (_4, 4);
  Function call may change dynamic type:memset (client_77(D), 0, 496);
Determining dynamic type for call: mqtt_output_append_string (_33, "MQTT", 4);
  Starting walk at: mqtt_output_append_string (_33, "MQTT", 4);
  instance pointer: _33  Outer instance pointer: client_77(D) offset: 1888 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_output_append_fixed_header (_33, 1, 0, 0, 0, remaining_length_110);
  Function call may change dynamic type:tcp_err (_39, mqtt_tcp_err_cb);
  Function call may change dynamic type:err_119 = tcp_connect (_38, ip_addr_79(D), port_117(D), mqtt_tcp_connect_cb);
  Function call may change dynamic type:err_116 = tcp_bind (_37, &ip_addr_any, 0);
  Function call may change dynamic type:tcp_arg (_36, client_77(D));
  Function call may change dynamic type:_36 = tcp_new_ip_type (_35);
  Function call may change dynamic type:_34 = mqtt_output_check_space (_33, remaining_length_110);
  Function call may change dynamic type:mqtt_init_requests (_4, 4);
  Function call may change dynamic type:memset (client_77(D), 0, 496);
Determining dynamic type for call: mqtt_output_append_string (_33, "MQTT", 4);
  Starting walk at: mqtt_output_append_string (_33, "MQTT", 4);
  instance pointer: "MQTT"  Outer instance pointer: "MQTT" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: mqtt_ringbuf_put (_33, 4);
  Starting walk at: mqtt_ringbuf_put (_33, 4);
  instance pointer: _33  Outer instance pointer: client_77(D) offset: 1888 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_output_append_string (_33, "MQTT", 4);
  Function call may change dynamic type:mqtt_output_append_fixed_header (_33, 1, 0, 0, 0, remaining_length_110);
  Function call may change dynamic type:tcp_err (_39, mqtt_tcp_err_cb);
  Function call may change dynamic type:err_119 = tcp_connect (_38, ip_addr_79(D), port_117(D), mqtt_tcp_connect_cb);
  Function call may change dynamic type:err_116 = tcp_bind (_37, &ip_addr_any, 0);
  Function call may change dynamic type:tcp_arg (_36, client_77(D));
  Function call may change dynamic type:_36 = tcp_new_ip_type (_35);
  Function call may change dynamic type:_34 = mqtt_output_check_space (_33, remaining_length_110);
  Function call may change dynamic type:mqtt_init_requests (_4, 4);
  Function call may change dynamic type:memset (client_77(D), 0, 496);
Determining dynamic type for call: mqtt_ringbuf_put (_33, flags_106);
  Starting walk at: mqtt_ringbuf_put (_33, flags_106);
  instance pointer: _33  Outer instance pointer: client_77(D) offset: 1888 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_ringbuf_put (_33, 4);
  Function call may change dynamic type:mqtt_output_append_string (_33, "MQTT", 4);
  Function call may change dynamic type:mqtt_output_append_fixed_header (_33, 1, 0, 0, 0, remaining_length_110);
  Function call may change dynamic type:tcp_err (_39, mqtt_tcp_err_cb);
  Function call may change dynamic type:err_119 = tcp_connect (_38, ip_addr_79(D), port_117(D), mqtt_tcp_connect_cb);
  Function call may change dynamic type:err_116 = tcp_bind (_37, &ip_addr_any, 0);
  Function call may change dynamic type:tcp_arg (_36, client_77(D));
  Function call may change dynamic type:_36 = tcp_new_ip_type (_35);
  Function call may change dynamic type:_34 = mqtt_output_check_space (_33, remaining_length_110);
  Function call may change dynamic type:mqtt_init_requests (_4, 4);
  Function call may change dynamic type:memset (client_77(D), 0, 496);
Determining dynamic type for call: mqtt_output_append_u16 (_33, _40);
  Starting walk at: mqtt_output_append_u16 (_33, _40);
  instance pointer: _33  Outer instance pointer: client_77(D) offset: 1888 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_ringbuf_put (_33, flags_106);
  Function call may change dynamic type:mqtt_ringbuf_put (_33, 4);
  Function call may change dynamic type:mqtt_output_append_string (_33, "MQTT", 4);
  Function call may change dynamic type:mqtt_output_append_fixed_header (_33, 1, 0, 0, 0, remaining_length_110);
  Function call may change dynamic type:tcp_err (_39, mqtt_tcp_err_cb);
  Function call may change dynamic type:err_119 = tcp_connect (_38, ip_addr_79(D), port_117(D), mqtt_tcp_connect_cb);
  Function call may change dynamic type:err_116 = tcp_bind (_37, &ip_addr_any, 0);
  Function call may change dynamic type:tcp_arg (_36, client_77(D));
  Function call may change dynamic type:_36 = tcp_new_ip_type (_35);
  Function call may change dynamic type:_34 = mqtt_output_check_space (_33, remaining_length_110);
  Function call may change dynamic type:mqtt_init_requests (_4, 4);
  Function call may change dynamic type:memset (client_77(D), 0, 496);
Determining dynamic type for call: mqtt_output_append_string (_33, _41, client_id_length_108);
  Starting walk at: mqtt_output_append_string (_33, _41, client_id_length_108);
  instance pointer: _33  Outer instance pointer: client_77(D) offset: 1888 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_output_append_u16 (_33, _40);
  Function call may change dynamic type:mqtt_ringbuf_put (_33, flags_106);
  Function call may change dynamic type:mqtt_ringbuf_put (_33, 4);
  Function call may change dynamic type:mqtt_output_append_string (_33, "MQTT", 4);
  Function call may change dynamic type:mqtt_output_append_fixed_header (_33, 1, 0, 0, 0, remaining_length_110);
  Function call may change dynamic type:tcp_err (_39, mqtt_tcp_err_cb);
  Function call may change dynamic type:err_119 = tcp_connect (_38, ip_addr_79(D), port_117(D), mqtt_tcp_connect_cb);
  Function call may change dynamic type:err_116 = tcp_bind (_37, &ip_addr_any, 0);
  Function call may change dynamic type:tcp_arg (_36, client_77(D));
  Function call may change dynamic type:_36 = tcp_new_ip_type (_35);
  Function call may change dynamic type:_34 = mqtt_output_check_space (_33, remaining_length_110);
  Function call may change dynamic type:mqtt_init_requests (_4, 4);
  Function call may change dynamic type:memset (client_77(D), 0, 496);
Determining dynamic type for call: mqtt_output_append_string (_33, _41, client_id_length_108);
  Starting walk at: mqtt_output_append_string (_33, _41, client_id_length_108);
  instance pointer: _41  Outer instance pointer: _41 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_output_append_u16 (_33, _40);
  Function call may change dynamic type:mqtt_ringbuf_put (_33, flags_106);
  Function call may change dynamic type:mqtt_ringbuf_put (_33, 4);
  Function call may change dynamic type:mqtt_output_append_string (_33, "MQTT", 4);
  Function call may change dynamic type:mqtt_output_append_fixed_header (_33, 1, 0, 0, 0, remaining_length_110);
  Function call may change dynamic type:tcp_err (_39, mqtt_tcp_err_cb);
  Function call may change dynamic type:err_119 = tcp_connect (_38, ip_addr_79(D), port_117(D), mqtt_tcp_connect_cb);
  Function call may change dynamic type:err_116 = tcp_bind (_37, &ip_addr_any, 0);
  Function call may change dynamic type:tcp_arg (_36, client_77(D));
  Function call may change dynamic type:_36 = tcp_new_ip_type (_35);
  Function call may change dynamic type:_34 = mqtt_output_check_space (_33, remaining_length_110);
  Function call may change dynamic type:mqtt_init_requests (_4, 4);
  Function call may change dynamic type:memset (client_77(D), 0, 496);
Determining dynamic type for call: mqtt_output_append_string (_33, _42, _43);
  Starting walk at: mqtt_output_append_string (_33, _42, _43);
  instance pointer: _33  Outer instance pointer: client_77(D) offset: 1888 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_output_append_string (_33, _41, client_id_length_108);
  Function call may change dynamic type:mqtt_output_append_u16 (_33, _40);
  Function call may change dynamic type:mqtt_ringbuf_put (_33, flags_106);
  Function call may change dynamic type:mqtt_ringbuf_put (_33, 4);
  Function call may change dynamic type:mqtt_output_append_string (_33, "MQTT", 4);
  Function call may change dynamic type:mqtt_output_append_fixed_header (_33, 1, 0, 0, 0, remaining_length_110);
  Function call may change dynamic type:tcp_err (_39, mqtt_tcp_err_cb);
  Function call may change dynamic type:err_119 = tcp_connect (_38, ip_addr_79(D), port_117(D), mqtt_tcp_connect_cb);
  Function call may change dynamic type:err_116 = tcp_bind (_37, &ip_addr_any, 0);
  Function call may change dynamic type:tcp_arg (_36, client_77(D));
  Function call may change dynamic type:_36 = tcp_new_ip_type (_35);
  Function call may change dynamic type:_34 = mqtt_output_check_space (_33, remaining_length_110);
  Function call may change dynamic type:mqtt_init_requests (_4, 4);
  Function call may change dynamic type:memset (client_77(D), 0, 496);
Determining dynamic type for call: mqtt_output_append_string (_33, _42, _43);
  Starting walk at: mqtt_output_append_string (_33, _42, _43);
  instance pointer: _42  Outer instance pointer: _42 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_output_append_string (_33, _41, client_id_length_108);
  Function call may change dynamic type:mqtt_output_append_u16 (_33, _40);
  Function call may change dynamic type:mqtt_ringbuf_put (_33, flags_106);
  Function call may change dynamic type:mqtt_ringbuf_put (_33, 4);
  Function call may change dynamic type:mqtt_output_append_string (_33, "MQTT", 4);
  Function call may change dynamic type:mqtt_output_append_fixed_header (_33, 1, 0, 0, 0, remaining_length_110);
  Function call may change dynamic type:tcp_err (_39, mqtt_tcp_err_cb);
  Function call may change dynamic type:err_119 = tcp_connect (_38, ip_addr_79(D), port_117(D), mqtt_tcp_connect_cb);
  Function call may change dynamic type:err_116 = tcp_bind (_37, &ip_addr_any, 0);
  Function call may change dynamic type:tcp_arg (_36, client_77(D));
  Function call may change dynamic type:_36 = tcp_new_ip_type (_35);
  Function call may change dynamic type:_34 = mqtt_output_check_space (_33, remaining_length_110);
  Function call may change dynamic type:mqtt_init_requests (_4, 4);
  Function call may change dynamic type:memset (client_77(D), 0, 496);
Determining dynamic type for call: mqtt_output_append_string (_33, _44, _45);
  Starting walk at: mqtt_output_append_string (_33, _44, _45);
  instance pointer: _33  Outer instance pointer: client_77(D) offset: 1888 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_output_append_string (_33, _42, _43);
  Function call may change dynamic type:mqtt_output_append_string (_33, _41, client_id_length_108);
  Function call may change dynamic type:mqtt_output_append_u16 (_33, _40);
  Function call may change dynamic type:mqtt_ringbuf_put (_33, flags_106);
  Function call may change dynamic type:mqtt_ringbuf_put (_33, 4);
  Function call may change dynamic type:mqtt_output_append_string (_33, "MQTT", 4);
  Function call may change dynamic type:mqtt_output_append_fixed_header (_33, 1, 0, 0, 0, remaining_length_110);
  Function call may change dynamic type:tcp_err (_39, mqtt_tcp_err_cb);
  Function call may change dynamic type:err_119 = tcp_connect (_38, ip_addr_79(D), port_117(D), mqtt_tcp_connect_cb);
  Function call may change dynamic type:err_116 = tcp_bind (_37, &ip_addr_any, 0);
  Function call may change dynamic type:tcp_arg (_36, client_77(D));
  Function call may change dynamic type:_36 = tcp_new_ip_type (_35);
  Function call may change dynamic type:_34 = mqtt_output_check_space (_33, remaining_length_110);
  Function call may change dynamic type:mqtt_init_requests (_4, 4);
  Function call may change dynamic type:memset (client_77(D), 0, 496);
Determining dynamic type for call: mqtt_output_append_string (_33, _44, _45);
  Starting walk at: mqtt_output_append_string (_33, _44, _45);
  instance pointer: _44  Outer instance pointer: _44 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_output_append_string (_33, _42, _43);
  Function call may change dynamic type:mqtt_output_append_string (_33, _41, client_id_length_108);
  Function call may change dynamic type:mqtt_output_append_u16 (_33, _40);
  Function call may change dynamic type:mqtt_ringbuf_put (_33, flags_106);
  Function call may change dynamic type:mqtt_ringbuf_put (_33, 4);
  Function call may change dynamic type:mqtt_output_append_string (_33, "MQTT", 4);
  Function call may change dynamic type:mqtt_output_append_fixed_header (_33, 1, 0, 0, 0, remaining_length_110);
  Function call may change dynamic type:tcp_err (_39, mqtt_tcp_err_cb);
  Function call may change dynamic type:err_119 = tcp_connect (_38, ip_addr_79(D), port_117(D), mqtt_tcp_connect_cb);
  Function call may change dynamic type:err_116 = tcp_bind (_37, &ip_addr_any, 0);
  Function call may change dynamic type:tcp_arg (_36, client_77(D));
  Function call may change dynamic type:_36 = tcp_new_ip_type (_35);
  Function call may change dynamic type:_34 = mqtt_output_check_space (_33, remaining_length_110);
  Function call may change dynamic type:mqtt_init_requests (_4, 4);
  Function call may change dynamic type:memset (client_77(D), 0, 496);
Determining dynamic type for call: mqtt_output_append_string (_33, _47, client_user_len_60);
  Starting walk at: mqtt_output_append_string (_33, _47, client_user_len_60);
  instance pointer: _33  Outer instance pointer: client_77(D) offset: 1888 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_output_append_string (_33, _41, client_id_length_108);
  Function call may change dynamic type:mqtt_output_append_u16 (_33, _40);
  Function call may change dynamic type:mqtt_ringbuf_put (_33, flags_106);
  Function call may change dynamic type:mqtt_ringbuf_put (_33, 4);
  Function call may change dynamic type:mqtt_output_append_string (_33, "MQTT", 4);
  Function call may change dynamic type:mqtt_output_append_fixed_header (_33, 1, 0, 0, 0, remaining_length_110);
  Function call may change dynamic type:tcp_err (_39, mqtt_tcp_err_cb);
  Function call may change dynamic type:err_119 = tcp_connect (_38, ip_addr_79(D), port_117(D), mqtt_tcp_connect_cb);
  Function call may change dynamic type:err_116 = tcp_bind (_37, &ip_addr_any, 0);
  Function call may change dynamic type:tcp_arg (_36, client_77(D));
  Function call may change dynamic type:_36 = tcp_new_ip_type (_35);
  Function call may change dynamic type:_34 = mqtt_output_check_space (_33, remaining_length_110);
  Function call may change dynamic type:mqtt_init_requests (_4, 4);
  Function call may change dynamic type:memset (client_77(D), 0, 496);
  Function call may change dynamic type:mqtt_output_append_string (_33, _44, _45);
  Function call may change dynamic type:mqtt_output_append_string (_33, _42, _43);
Determining dynamic type for call: mqtt_output_append_string (_33, _47, client_user_len_60);
  Starting walk at: mqtt_output_append_string (_33, _47, client_user_len_60);
  instance pointer: _47  Outer instance pointer: _47 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_output_append_string (_33, _41, client_id_length_108);
  Function call may change dynamic type:mqtt_output_append_u16 (_33, _40);
  Function call may change dynamic type:mqtt_ringbuf_put (_33, flags_106);
  Function call may change dynamic type:mqtt_ringbuf_put (_33, 4);
  Function call may change dynamic type:mqtt_output_append_string (_33, "MQTT", 4);
  Function call may change dynamic type:mqtt_output_append_fixed_header (_33, 1, 0, 0, 0, remaining_length_110);
  Function call may change dynamic type:tcp_err (_39, mqtt_tcp_err_cb);
  Function call may change dynamic type:err_119 = tcp_connect (_38, ip_addr_79(D), port_117(D), mqtt_tcp_connect_cb);
  Function call may change dynamic type:err_116 = tcp_bind (_37, &ip_addr_any, 0);
  Function call may change dynamic type:tcp_arg (_36, client_77(D));
  Function call may change dynamic type:_36 = tcp_new_ip_type (_35);
  Function call may change dynamic type:_34 = mqtt_output_check_space (_33, remaining_length_110);
  Function call may change dynamic type:mqtt_init_requests (_4, 4);
  Function call may change dynamic type:memset (client_77(D), 0, 496);
  Function call may change dynamic type:mqtt_output_append_string (_33, _44, _45);
  Function call may change dynamic type:mqtt_output_append_string (_33, _42, _43);
Determining dynamic type for call: mqtt_output_append_string (_33, _48, client_pass_len_61);
  Starting walk at: mqtt_output_append_string (_33, _48, client_pass_len_61);
  instance pointer: _33  Outer instance pointer: client_77(D) offset: 1888 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_output_append_string (_33, _41, client_id_length_108);
  Function call may change dynamic type:mqtt_output_append_u16 (_33, _40);
  Function call may change dynamic type:mqtt_ringbuf_put (_33, flags_106);
  Function call may change dynamic type:mqtt_ringbuf_put (_33, 4);
  Function call may change dynamic type:mqtt_output_append_string (_33, "MQTT", 4);
  Function call may change dynamic type:mqtt_output_append_fixed_header (_33, 1, 0, 0, 0, remaining_length_110);
  Function call may change dynamic type:tcp_err (_39, mqtt_tcp_err_cb);
  Function call may change dynamic type:err_119 = tcp_connect (_38, ip_addr_79(D), port_117(D), mqtt_tcp_connect_cb);
  Function call may change dynamic type:err_116 = tcp_bind (_37, &ip_addr_any, 0);
  Function call may change dynamic type:tcp_arg (_36, client_77(D));
  Function call may change dynamic type:_36 = tcp_new_ip_type (_35);
  Function call may change dynamic type:_34 = mqtt_output_check_space (_33, remaining_length_110);
  Function call may change dynamic type:mqtt_init_requests (_4, 4);
  Function call may change dynamic type:memset (client_77(D), 0, 496);
  Function call may change dynamic type:mqtt_output_append_string (_33, _44, _45);
  Function call may change dynamic type:mqtt_output_append_string (_33, _42, _43);
  Function call may change dynamic type:mqtt_output_append_string (_33, _47, client_user_len_60);
Determining dynamic type for call: mqtt_output_append_string (_33, _48, client_pass_len_61);
  Starting walk at: mqtt_output_append_string (_33, _48, client_pass_len_61);
  instance pointer: _48  Outer instance pointer: _48 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_output_append_string (_33, _41, client_id_length_108);
  Function call may change dynamic type:mqtt_output_append_u16 (_33, _40);
  Function call may change dynamic type:mqtt_ringbuf_put (_33, flags_106);
  Function call may change dynamic type:mqtt_ringbuf_put (_33, 4);
  Function call may change dynamic type:mqtt_output_append_string (_33, "MQTT", 4);
  Function call may change dynamic type:mqtt_output_append_fixed_header (_33, 1, 0, 0, 0, remaining_length_110);
  Function call may change dynamic type:tcp_err (_39, mqtt_tcp_err_cb);
  Function call may change dynamic type:err_119 = tcp_connect (_38, ip_addr_79(D), port_117(D), mqtt_tcp_connect_cb);
  Function call may change dynamic type:err_116 = tcp_bind (_37, &ip_addr_any, 0);
  Function call may change dynamic type:tcp_arg (_36, client_77(D));
  Function call may change dynamic type:_36 = tcp_new_ip_type (_35);
  Function call may change dynamic type:_34 = mqtt_output_check_space (_33, remaining_length_110);
  Function call may change dynamic type:mqtt_init_requests (_4, 4);
  Function call may change dynamic type:memset (client_77(D), 0, 496);
  Function call may change dynamic type:mqtt_output_append_string (_33, _44, _45);
  Function call may change dynamic type:mqtt_output_append_string (_33, _42, _43);
  Function call may change dynamic type:mqtt_output_append_string (_33, _47, client_user_len_60);
Determining dynamic type for call: pkt_id_30 = msg_generate_packet_id.isra.0 (_46);
  Starting walk at: pkt_id_30 = msg_generate_packet_id.isra.0 (_46);
  instance pointer: _46  Outer instance pointer: client_20(D) offset: 48 (bits) vtbl reference: 
Determining dynamic type for call: r_34 = mqtt_create_request (_7, 4, pkt_id_30, cb_31(D), arg_32(D));
  Starting walk at: r_34 = mqtt_create_request (_7, 4, pkt_id_30, cb_31(D), arg_32(D));
  instance pointer: _7  Outer instance pointer: client_20(D) offset: 224 (bits) vtbl reference: 
  Function call may change dynamic type:pkt_id_30 = msg_generate_packet_id.isra.0 (_46);
Determining dynamic type for call: r_34 = mqtt_create_request (_7, 4, pkt_id_30, cb_31(D), arg_32(D));
  Starting walk at: r_34 = mqtt_create_request (_7, 4, pkt_id_30, cb_31(D), arg_32(D));
  instance pointer: cb_31(D)  Outer instance pointer: cb_31(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pkt_id_30 = msg_generate_packet_id.isra.0 (_46);
Determining dynamic type for call: r_34 = mqtt_create_request (_7, 4, pkt_id_30, cb_31(D), arg_32(D));
  Starting walk at: r_34 = mqtt_create_request (_7, 4, pkt_id_30, cb_31(D), arg_32(D));
  instance pointer: arg_32(D)  Outer instance pointer: arg_32(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pkt_id_30 = msg_generate_packet_id.isra.0 (_46);
Determining dynamic type for call: _9 = mqtt_output_check_space (_8, remaining_length_27);
  Starting walk at: _9 = mqtt_output_check_space (_8, remaining_length_27);
  instance pointer: _8  Outer instance pointer: client_20(D) offset: 1888 (bits) vtbl reference: 
  Function call may change dynamic type:r_34 = mqtt_create_request (_7, 4, pkt_id_30, cb_31(D), arg_32(D));
  Function call may change dynamic type:pkt_id_30 = msg_generate_packet_id.isra.0 (_46);
Determining dynamic type for call: mqtt_output_append_fixed_header (_8, iftmp.13_14, 0, 1, 0, remaining_length_27);
  Starting walk at: mqtt_output_append_fixed_header (_8, iftmp.13_14, 0, 1, 0, remaining_length_27);
  instance pointer: _8  Outer instance pointer: client_20(D) offset: 1888 (bits) vtbl reference: 
  Function call may change dynamic type:_9 = mqtt_output_check_space (_8, remaining_length_27);
  Function call may change dynamic type:r_34 = mqtt_create_request (_7, 4, pkt_id_30, cb_31(D), arg_32(D));
  Function call may change dynamic type:pkt_id_30 = msg_generate_packet_id.isra.0 (_46);
Determining dynamic type for call: mqtt_output_append_u16 (_8, pkt_id_30);
  Starting walk at: mqtt_output_append_u16 (_8, pkt_id_30);
  instance pointer: _8  Outer instance pointer: client_20(D) offset: 1888 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_output_append_fixed_header (_8, iftmp.13_14, 0, 1, 0, remaining_length_27);
  Function call may change dynamic type:_9 = mqtt_output_check_space (_8, remaining_length_27);
  Function call may change dynamic type:r_34 = mqtt_create_request (_7, 4, pkt_id_30, cb_31(D), arg_32(D));
  Function call may change dynamic type:pkt_id_30 = msg_generate_packet_id.isra.0 (_46);
Determining dynamic type for call: mqtt_output_append_string (_8, topic_22(D), topic_len_24);
  Starting walk at: mqtt_output_append_string (_8, topic_22(D), topic_len_24);
  instance pointer: _8  Outer instance pointer: client_20(D) offset: 1888 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_output_append_u16 (_8, pkt_id_30);
  Function call may change dynamic type:mqtt_output_append_fixed_header (_8, iftmp.13_14, 0, 1, 0, remaining_length_27);
  Function call may change dynamic type:_9 = mqtt_output_check_space (_8, remaining_length_27);
  Function call may change dynamic type:r_34 = mqtt_create_request (_7, 4, pkt_id_30, cb_31(D), arg_32(D));
  Function call may change dynamic type:pkt_id_30 = msg_generate_packet_id.isra.0 (_46);
Determining dynamic type for call: mqtt_output_append_string (_8, topic_22(D), topic_len_24);
  Starting walk at: mqtt_output_append_string (_8, topic_22(D), topic_len_24);
  instance pointer: topic_22(D)  Outer instance pointer: topic_22(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_output_append_u16 (_8, pkt_id_30);
  Function call may change dynamic type:mqtt_output_append_fixed_header (_8, iftmp.13_14, 0, 1, 0, remaining_length_27);
  Function call may change dynamic type:_9 = mqtt_output_check_space (_8, remaining_length_27);
  Function call may change dynamic type:r_34 = mqtt_create_request (_7, 4, pkt_id_30, cb_31(D), arg_32(D));
  Function call may change dynamic type:pkt_id_30 = msg_generate_packet_id.isra.0 (_46);
Determining dynamic type for call: mqtt_ringbuf_put (_8, _10);
  Starting walk at: mqtt_ringbuf_put (_8, _10);
  instance pointer: _8  Outer instance pointer: client_20(D) offset: 1888 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_output_append_string (_8, topic_22(D), topic_len_24);
  Function call may change dynamic type:mqtt_output_append_u16 (_8, pkt_id_30);
  Function call may change dynamic type:mqtt_output_append_fixed_header (_8, iftmp.13_14, 0, 1, 0, remaining_length_27);
  Function call may change dynamic type:_9 = mqtt_output_check_space (_8, remaining_length_27);
  Function call may change dynamic type:r_34 = mqtt_create_request (_7, 4, pkt_id_30, cb_31(D), arg_32(D));
  Function call may change dynamic type:pkt_id_30 = msg_generate_packet_id.isra.0 (_46);
Determining dynamic type for call: mqtt_append_request (_11, r_34);
  Starting walk at: mqtt_append_request (_11, r_34);
  instance pointer: _11  Outer instance pointer: client_20(D) offset: 192 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_output_append_string (_8, topic_22(D), topic_len_24);
  Function call may change dynamic type:mqtt_output_append_u16 (_8, pkt_id_30);
  Function call may change dynamic type:mqtt_output_append_fixed_header (_8, iftmp.13_14, 0, 1, 0, remaining_length_27);
  Function call may change dynamic type:_9 = mqtt_output_check_space (_8, remaining_length_27);
  Function call may change dynamic type:r_34 = mqtt_create_request (_7, 4, pkt_id_30, cb_31(D), arg_32(D));
  Function call may change dynamic type:pkt_id_30 = msg_generate_packet_id.isra.0 (_46);
  Function call may change dynamic type:mqtt_ringbuf_put (_8, _10);
Determining dynamic type for call: mqtt_append_request (_11, r_34);
  Starting walk at: mqtt_append_request (_11, r_34);
  instance pointer: r_34  Outer instance pointer: r_34 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_output_append_string (_8, topic_22(D), topic_len_24);
  Function call may change dynamic type:mqtt_output_append_u16 (_8, pkt_id_30);
  Function call may change dynamic type:mqtt_output_append_fixed_header (_8, iftmp.13_14, 0, 1, 0, remaining_length_27);
  Function call may change dynamic type:_9 = mqtt_output_check_space (_8, remaining_length_27);
  Function call may change dynamic type:r_34 = mqtt_create_request (_7, 4, pkt_id_30, cb_31(D), arg_32(D));
  Function call may change dynamic type:pkt_id_30 = msg_generate_packet_id.isra.0 (_46);
  Function call may change dynamic type:mqtt_ringbuf_put (_8, _10);
Determining dynamic type for call: mqtt_output_send (_8, _12);
  Starting walk at: mqtt_output_send (_8, _12);
  instance pointer: _8  Outer instance pointer: client_20(D) offset: 1888 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_append_request (_11, r_34);
  Function call may change dynamic type:mqtt_output_append_string (_8, topic_22(D), topic_len_24);
  Function call may change dynamic type:mqtt_output_append_u16 (_8, pkt_id_30);
  Function call may change dynamic type:mqtt_output_append_fixed_header (_8, iftmp.13_14, 0, 1, 0, remaining_length_27);
  Function call may change dynamic type:_9 = mqtt_output_check_space (_8, remaining_length_27);
  Function call may change dynamic type:r_34 = mqtt_create_request (_7, 4, pkt_id_30, cb_31(D), arg_32(D));
  Function call may change dynamic type:pkt_id_30 = msg_generate_packet_id.isra.0 (_46);
  Function call may change dynamic type:mqtt_ringbuf_put (_8, _10);
Determining dynamic type for call: mqtt_output_send (_8, _12);
  Starting walk at: mqtt_output_send (_8, _12);
  instance pointer: _12  Outer instance pointer: _12 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_append_request (_11, r_34);
  Function call may change dynamic type:mqtt_output_append_string (_8, topic_22(D), topic_len_24);
  Function call may change dynamic type:mqtt_output_append_u16 (_8, pkt_id_30);
  Function call may change dynamic type:mqtt_output_append_fixed_header (_8, iftmp.13_14, 0, 1, 0, remaining_length_27);
  Function call may change dynamic type:_9 = mqtt_output_check_space (_8, remaining_length_27);
  Function call may change dynamic type:r_34 = mqtt_create_request (_7, 4, pkt_id_30, cb_31(D), arg_32(D));
  Function call may change dynamic type:pkt_id_30 = msg_generate_packet_id.isra.0 (_46);
  Function call may change dynamic type:mqtt_ringbuf_put (_8, _10);
Determining dynamic type for call: mqtt_delete_request (r_34);
  Starting walk at: mqtt_delete_request (r_34);
  instance pointer: r_34  Outer instance pointer: r_34 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_9 = mqtt_output_check_space (_8, remaining_length_27);
  Function call may change dynamic type:r_34 = mqtt_create_request (_7, 4, pkt_id_30, cb_31(D), arg_32(D));
  Function call may change dynamic type:pkt_id_30 = msg_generate_packet_id.isra.0 (_46);
Determining dynamic type for call: pkt_id_31 = msg_generate_packet_id.isra.0 (_49);
  Starting walk at: pkt_id_31 = msg_generate_packet_id.isra.0 (_49);
  instance pointer: _49  Outer instance pointer: client_20(D) offset: 48 (bits) vtbl reference: 
Determining dynamic type for call: r_36 = mqtt_create_request (_6, 4, pkt_id_11, cb_33(D), arg_34(D));
  Starting walk at: r_36 = mqtt_create_request (_6, 4, pkt_id_11, cb_33(D), arg_34(D));
  instance pointer: _6  Outer instance pointer: client_20(D) offset: 224 (bits) vtbl reference: 
  Function call may change dynamic type:pkt_id_31 = msg_generate_packet_id.isra.0 (_49);
Determining dynamic type for call: r_36 = mqtt_create_request (_6, 4, pkt_id_11, cb_33(D), arg_34(D));
  Starting walk at: r_36 = mqtt_create_request (_6, 4, pkt_id_11, cb_33(D), arg_34(D));
  instance pointer: cb_33(D)  Outer instance pointer: cb_33(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pkt_id_31 = msg_generate_packet_id.isra.0 (_49);
Determining dynamic type for call: r_36 = mqtt_create_request (_6, 4, pkt_id_11, cb_33(D), arg_34(D));
  Starting walk at: r_36 = mqtt_create_request (_6, 4, pkt_id_11, cb_33(D), arg_34(D));
  instance pointer: arg_34(D)  Outer instance pointer: arg_34(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pkt_id_31 = msg_generate_packet_id.isra.0 (_49);
Determining dynamic type for call: _8 = mqtt_output_check_space (_7, remaining_length_32);
  Starting walk at: _8 = mqtt_output_check_space (_7, remaining_length_32);
  instance pointer: _7  Outer instance pointer: client_20(D) offset: 1888 (bits) vtbl reference: 
  Function call may change dynamic type:r_36 = mqtt_create_request (_6, 4, pkt_id_11, cb_33(D), arg_34(D));
  Function call may change dynamic type:pkt_id_31 = msg_generate_packet_id.isra.0 (_49);
Determining dynamic type for call: mqtt_output_append_fixed_header (_7, 3, 0, qos_27(D), retain_38(D), remaining_length_32);
  Starting walk at: mqtt_output_append_fixed_header (_7, 3, 0, qos_27(D), retain_38(D), remaining_length_32);
  instance pointer: _7  Outer instance pointer: client_20(D) offset: 1888 (bits) vtbl reference: 
  Function call may change dynamic type:_8 = mqtt_output_check_space (_7, remaining_length_32);
  Function call may change dynamic type:r_36 = mqtt_create_request (_6, 4, pkt_id_11, cb_33(D), arg_34(D));
  Function call may change dynamic type:pkt_id_31 = msg_generate_packet_id.isra.0 (_49);
Determining dynamic type for call: mqtt_output_append_string (_7, topic_22(D), topic_len_24);
  Starting walk at: mqtt_output_append_string (_7, topic_22(D), topic_len_24);
  instance pointer: _7  Outer instance pointer: client_20(D) offset: 1888 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_output_append_fixed_header (_7, 3, 0, qos_27(D), retain_38(D), remaining_length_32);
  Function call may change dynamic type:_8 = mqtt_output_check_space (_7, remaining_length_32);
  Function call may change dynamic type:r_36 = mqtt_create_request (_6, 4, pkt_id_11, cb_33(D), arg_34(D));
  Function call may change dynamic type:pkt_id_31 = msg_generate_packet_id.isra.0 (_49);
Determining dynamic type for call: mqtt_output_append_string (_7, topic_22(D), topic_len_24);
  Starting walk at: mqtt_output_append_string (_7, topic_22(D), topic_len_24);
  instance pointer: topic_22(D)  Outer instance pointer: topic_22(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_output_append_fixed_header (_7, 3, 0, qos_27(D), retain_38(D), remaining_length_32);
  Function call may change dynamic type:_8 = mqtt_output_check_space (_7, remaining_length_32);
  Function call may change dynamic type:r_36 = mqtt_create_request (_6, 4, pkt_id_11, cb_33(D), arg_34(D));
  Function call may change dynamic type:pkt_id_31 = msg_generate_packet_id.isra.0 (_49);
Determining dynamic type for call: mqtt_output_append_u16 (_7, pkt_id_11);
  Starting walk at: mqtt_output_append_u16 (_7, pkt_id_11);
  instance pointer: _7  Outer instance pointer: client_20(D) offset: 1888 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_output_append_string (_7, topic_22(D), topic_len_24);
  Function call may change dynamic type:mqtt_output_append_fixed_header (_7, 3, 0, qos_27(D), retain_38(D), remaining_length_32);
  Function call may change dynamic type:_8 = mqtt_output_check_space (_7, remaining_length_32);
  Function call may change dynamic type:r_36 = mqtt_create_request (_6, 4, pkt_id_11, cb_33(D), arg_34(D));
  Function call may change dynamic type:pkt_id_31 = msg_generate_packet_id.isra.0 (_49);
Determining dynamic type for call: mqtt_output_append_buf (_7, payload_42(D), payload_length_25(D));
  Starting walk at: mqtt_output_append_buf (_7, payload_42(D), payload_length_25(D));
  instance pointer: _7  Outer instance pointer: client_20(D) offset: 1888 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_output_append_string (_7, topic_22(D), topic_len_24);
  Function call may change dynamic type:mqtt_output_append_fixed_header (_7, 3, 0, qos_27(D), retain_38(D), remaining_length_32);
  Function call may change dynamic type:_8 = mqtt_output_check_space (_7, remaining_length_32);
  Function call may change dynamic type:r_36 = mqtt_create_request (_6, 4, pkt_id_11, cb_33(D), arg_34(D));
  Function call may change dynamic type:pkt_id_31 = msg_generate_packet_id.isra.0 (_49);
  Function call may change dynamic type:mqtt_output_append_u16 (_7, pkt_id_11);
Determining dynamic type for call: mqtt_output_append_buf (_7, payload_42(D), payload_length_25(D));
  Starting walk at: mqtt_output_append_buf (_7, payload_42(D), payload_length_25(D));
  instance pointer: payload_42(D)  Outer instance pointer: payload_42(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_output_append_string (_7, topic_22(D), topic_len_24);
  Function call may change dynamic type:mqtt_output_append_fixed_header (_7, 3, 0, qos_27(D), retain_38(D), remaining_length_32);
  Function call may change dynamic type:_8 = mqtt_output_check_space (_7, remaining_length_32);
  Function call may change dynamic type:r_36 = mqtt_create_request (_6, 4, pkt_id_11, cb_33(D), arg_34(D));
  Function call may change dynamic type:pkt_id_31 = msg_generate_packet_id.isra.0 (_49);
  Function call may change dynamic type:mqtt_output_append_u16 (_7, pkt_id_11);
Determining dynamic type for call: mqtt_append_request (_9, r_36);
  Starting walk at: mqtt_append_request (_9, r_36);
  instance pointer: _9  Outer instance pointer: client_20(D) offset: 192 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_output_append_string (_7, topic_22(D), topic_len_24);
  Function call may change dynamic type:mqtt_output_append_fixed_header (_7, 3, 0, qos_27(D), retain_38(D), remaining_length_32);
  Function call may change dynamic type:_8 = mqtt_output_check_space (_7, remaining_length_32);
  Function call may change dynamic type:r_36 = mqtt_create_request (_6, 4, pkt_id_11, cb_33(D), arg_34(D));
  Function call may change dynamic type:pkt_id_31 = msg_generate_packet_id.isra.0 (_49);
  Function call may change dynamic type:mqtt_output_append_u16 (_7, pkt_id_11);
  Function call may change dynamic type:mqtt_output_append_buf (_7, payload_42(D), payload_length_25(D));
Determining dynamic type for call: mqtt_append_request (_9, r_36);
  Starting walk at: mqtt_append_request (_9, r_36);
  instance pointer: r_36  Outer instance pointer: r_36 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_output_append_string (_7, topic_22(D), topic_len_24);
  Function call may change dynamic type:mqtt_output_append_fixed_header (_7, 3, 0, qos_27(D), retain_38(D), remaining_length_32);
  Function call may change dynamic type:_8 = mqtt_output_check_space (_7, remaining_length_32);
  Function call may change dynamic type:r_36 = mqtt_create_request (_6, 4, pkt_id_11, cb_33(D), arg_34(D));
  Function call may change dynamic type:pkt_id_31 = msg_generate_packet_id.isra.0 (_49);
  Function call may change dynamic type:mqtt_output_append_u16 (_7, pkt_id_11);
  Function call may change dynamic type:mqtt_output_append_buf (_7, payload_42(D), payload_length_25(D));
Determining dynamic type for call: mqtt_output_send (_7, _10);
  Starting walk at: mqtt_output_send (_7, _10);
  instance pointer: _7  Outer instance pointer: client_20(D) offset: 1888 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_append_request (_9, r_36);
  Function call may change dynamic type:mqtt_output_append_string (_7, topic_22(D), topic_len_24);
  Function call may change dynamic type:mqtt_output_append_fixed_header (_7, 3, 0, qos_27(D), retain_38(D), remaining_length_32);
  Function call may change dynamic type:_8 = mqtt_output_check_space (_7, remaining_length_32);
  Function call may change dynamic type:r_36 = mqtt_create_request (_6, 4, pkt_id_11, cb_33(D), arg_34(D));
  Function call may change dynamic type:pkt_id_31 = msg_generate_packet_id.isra.0 (_49);
  Function call may change dynamic type:mqtt_output_append_u16 (_7, pkt_id_11);
  Function call may change dynamic type:mqtt_output_append_buf (_7, payload_42(D), payload_length_25(D));
Determining dynamic type for call: mqtt_output_send (_7, _10);
  Starting walk at: mqtt_output_send (_7, _10);
  instance pointer: _10  Outer instance pointer: _10 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_append_request (_9, r_36);
  Function call may change dynamic type:mqtt_output_append_string (_7, topic_22(D), topic_len_24);
  Function call may change dynamic type:mqtt_output_append_fixed_header (_7, 3, 0, qos_27(D), retain_38(D), remaining_length_32);
  Function call may change dynamic type:_8 = mqtt_output_check_space (_7, remaining_length_32);
  Function call may change dynamic type:r_36 = mqtt_create_request (_6, 4, pkt_id_11, cb_33(D), arg_34(D));
  Function call may change dynamic type:pkt_id_31 = msg_generate_packet_id.isra.0 (_49);
  Function call may change dynamic type:mqtt_output_append_u16 (_7, pkt_id_11);
  Function call may change dynamic type:mqtt_output_append_buf (_7, payload_42(D), payload_length_25(D));
Determining dynamic type for call: mqtt_delete_request (r_36);
  Starting walk at: mqtt_delete_request (r_36);
  instance pointer: r_36  Outer instance pointer: r_36 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_8 = mqtt_output_check_space (_7, remaining_length_32);
  Function call may change dynamic type:r_36 = mqtt_create_request (_6, 4, pkt_id_11, cb_33(D), arg_34(D));
  Function call may change dynamic type:pkt_id_31 = msg_generate_packet_id.isra.0 (_49);
Determining dynamic type for call: _3 = mqtt_tcp_connect_cb.part.0 (arg_2(D), tpcb_6(D));
  Starting walk at: _3 = mqtt_tcp_connect_cb.part.0 (arg_2(D), tpcb_6(D));
  instance pointer: arg_2(D)  Outer instance pointer: arg_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _3 = mqtt_tcp_connect_cb.part.0 (arg_2(D), tpcb_6(D));
  Starting walk at: _3 = mqtt_tcp_connect_cb.part.0 (arg_2(D), tpcb_6(D));
  instance pointer: tpcb_6(D)  Outer instance pointer: tpcb_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: mqtt_output_send (_2, tpcb_6(D));
  Starting walk at: mqtt_output_send (_2, tpcb_6(D));
  instance pointer: _2  Outer instance pointer: arg_4(D) offset: 1888 (bits) vtbl reference: 
Determining dynamic type for call: mqtt_output_send (_2, tpcb_6(D));
  Starting walk at: mqtt_output_send (_2, tpcb_6(D));
  instance pointer: tpcb_6(D)  Outer instance pointer: tpcb_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: mqtt_tcp_err_cb.part.0 (arg_2(D));
  Starting walk at: mqtt_tcp_err_cb.part.0 (arg_2(D));
  instance pointer: arg_2(D)  Outer instance pointer: arg_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: mqtt_tcp_sent_cb.part.0 (arg_3(D));
  Starting walk at: mqtt_tcp_sent_cb.part.0 (arg_3(D));
  instance pointer: arg_3(D)  Outer instance pointer: arg_3(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _5 = mqtt_tcp_recv_cb.part.0 (arg_6(D), pcb_9(D), p_10(D));
  Starting walk at: _5 = mqtt_tcp_recv_cb.part.0 (arg_6(D), pcb_9(D), p_10(D));
  instance pointer: arg_6(D)  Outer instance pointer: arg_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _5 = mqtt_tcp_recv_cb.part.0 (arg_6(D), pcb_9(D), p_10(D));
  Starting walk at: _5 = mqtt_tcp_recv_cb.part.0 (arg_6(D), pcb_9(D), p_10(D));
  instance pointer: pcb_9(D)  Outer instance pointer: pcb_9(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _5 = mqtt_tcp_recv_cb.part.0 (arg_6(D), pcb_9(D), p_10(D));
  Starting walk at: _5 = mqtt_tcp_recv_cb.part.0 (arg_6(D), pcb_9(D), p_10(D));
  instance pointer: p_10(D)  Outer instance pointer: p_10(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: mqtt_close (arg_6(D), 256);
  Starting walk at: mqtt_close (arg_6(D), 256);
  instance pointer: arg_6(D)  Outer instance pointer: arg_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: res_55 = mqtt_message_received (client_49(D), fixed_hdr_len_34, cpy_len_8, msg_rem_len_53);
  Starting walk at: res_55 = mqtt_message_received (client_49(D), fixed_hdr_len_34, cpy_len_8, msg_rem_len_53);
  instance pointer: client_49(D)  Outer instance pointer: client_49(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pbuf_copy_partial (p_44(D), _25, cpy_len_8, in_offset_32);
  Function call may change dynamic type:b_59 = pbuf_get_at (p_44(D), in_offset_32);
  Function call may change dynamic type:pbuf_copy_partial (p_44(D), _25, cpy_len_8, in_offset_32);
  Function call may change dynamic type:mqtt_message_received (client_49(D), fixed_hdr_len_63, 0, 0);
  Function call may change dynamic type:res_55 = mqtt_message_received (client_49(D), fixed_hdr_len_34, cpy_len_8, msg_rem_len_53);
Determining dynamic type for call: mqtt_message_received (client_49(D), fixed_hdr_len_63, 0, 0);
  Starting walk at: mqtt_message_received (client_49(D), fixed_hdr_len_63, 0, 0);
  instance pointer: client_49(D)  Outer instance pointer: client_49(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:b_59 = pbuf_get_at (p_44(D), in_offset_32);
  Function call may change dynamic type:pbuf_copy_partial (p_44(D), _25, cpy_len_8, in_offset_32);
  Function call may change dynamic type:mqtt_message_received (client_49(D), fixed_hdr_len_63, 0, 0);
  Function call may change dynamic type:res_55 = mqtt_message_received (client_49(D), fixed_hdr_len_34, cpy_len_8, msg_rem_len_53);
Determining dynamic type for call: r_90 = mqtt_take_request (_62, pkt_id_88);
  Starting walk at: r_90 = mqtt_take_request (_62, pkt_id_88);
  instance pointer: _62  Outer instance pointer: client_80(D) offset: 192 (bits) vtbl reference: 
Determining dynamic type for call: _64 (_65, 0);
  Starting walk at: _64 (_65, 0);
  instance pointer: _65  Outer instance pointer: _65 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:r_90 = mqtt_take_request (_62, pkt_id_88);
Determining dynamic type for call: mqtt_incomming_suback (r_90, _63);
  Starting walk at: mqtt_incomming_suback (r_90, _63);
  instance pointer: r_90  Outer instance pointer: r_90 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:r_90 = mqtt_take_request (_62, pkt_id_88);
Determining dynamic type for call: mqtt_delete_request (r_90);
  Starting walk at: mqtt_delete_request (r_90);
  instance pointer: r_90  Outer instance pointer: r_90 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_incomming_suback (r_90, _63);
  Function call may change dynamic type:r_90 = mqtt_take_request (_62, pkt_id_88);
  Function call may change dynamic type:_64 (_65, 0);
Determining dynamic type for call: pub_ack_rec_rel_response (client_80(D), 7, pkt_id_88, 0);
  Starting walk at: pub_ack_rec_rel_response (client_80(D), 7, pkt_id_88, 0);
  instance pointer: client_80(D)  Outer instance pointer: client_80(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pub_ack_rec_rel_response (client_80(D), 6, pkt_id_88, 1);
  Starting walk at: pub_ack_rec_rel_response (client_80(D), 6, pkt_id_88, 1);
  instance pointer: client_80(D)  Outer instance pointer: client_80(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _42 (_43, topic_99, _45);
  Starting walk at: _42 (_43, topic_99, _45);
  instance pointer: _43  Outer instance pointer: _43 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _42 (_43, topic_99, _45);
  Starting walk at: _42 (_43, topic_99, _45);
  instance pointer: topic_99  Outer instance pointer: topic_99 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _51 (_52, _54, payload_length_67, _56);
  Starting walk at: _51 (_52, _54, payload_length_67, _56);
  instance pointer: _52  Outer instance pointer: _52 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_42 (_43, topic_99, _45);
Determining dynamic type for call: _51 (_52, _54, payload_length_67, _56);
  Starting walk at: _51 (_52, _54, payload_length_67, _56);
  instance pointer: _54  Outer instance pointer: _54 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_42 (_43, topic_99, _45);
Determining dynamic type for call: pub_ack_rec_rel_response (client_80(D), iftmp.23_72, _57, 0);
  Starting walk at: pub_ack_rec_rel_response (client_80(D), iftmp.23_72, _57, 0);
  instance pointer: client_80(D)  Outer instance pointer: client_80(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_42 (_43, topic_99, _45);
  Function call may change dynamic type:_51 (_52, _54, payload_length_67, _56);
Determining dynamic type for call: _10 (client_80(D), _11, 0);
  Starting walk at: _10 (client_80(D), _11, 0);
  instance pointer: client_80(D)  Outer instance pointer: client_80(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _10 (client_80(D), _11, 0);
  Starting walk at: _10 (client_80(D), _11, 0);
  instance pointer: _11  Outer instance pointer: _11 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 (_2, iftmp.24_3);
  Starting walk at: _1 (_2, iftmp.24_3);
  instance pointer: _2  Outer instance pointer: _2 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _2 = mqtt_output_check_space (_1, 2);
  Starting walk at: _2 = mqtt_output_check_space (_1, 2);
  instance pointer: _1  Outer instance pointer: client_6(D) offset: 1888 (bits) vtbl reference: 
Determining dynamic type for call: mqtt_output_append_fixed_header (_1, msg_9(D), 0, qos_10(D), 0, 2);
  Starting walk at: mqtt_output_append_fixed_header (_1, msg_9(D), 0, qos_10(D), 0, 2);
  instance pointer: _1  Outer instance pointer: client_6(D) offset: 1888 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = mqtt_output_check_space (_1, 2);
Determining dynamic type for call: mqtt_output_append_u16 (_1, pkt_id_12(D));
  Starting walk at: mqtt_output_append_u16 (_1, pkt_id_12(D));
  instance pointer: _1  Outer instance pointer: client_6(D) offset: 1888 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_output_append_fixed_header (_1, msg_9(D), 0, qos_10(D), 0, 2);
  Function call may change dynamic type:_2 = mqtt_output_check_space (_1, 2);
Determining dynamic type for call: mqtt_output_send (_1, _3);
  Starting walk at: mqtt_output_send (_1, _3);
  instance pointer: _1  Outer instance pointer: client_6(D) offset: 1888 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_output_append_u16 (_1, pkt_id_12(D));
  Function call may change dynamic type:mqtt_output_append_fixed_header (_1, msg_9(D), 0, qos_10(D), 0, 2);
  Function call may change dynamic type:_2 = mqtt_output_check_space (_1, 2);
Determining dynamic type for call: mqtt_output_send (_1, _3);
  Starting walk at: mqtt_output_send (_1, _3);
  instance pointer: _3  Outer instance pointer: _3 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_output_append_u16 (_1, pkt_id_12(D));
  Function call may change dynamic type:mqtt_output_append_fixed_header (_1, msg_9(D), 0, qos_10(D), 0, 2);
  Function call may change dynamic type:_2 = mqtt_output_check_space (_1, 2);
Determining dynamic type for call: mqtt_request_time_elapsed (_6, 5);
  Starting walk at: mqtt_request_time_elapsed (_6, 5);
  instance pointer: _6  Outer instance pointer: arg_29(D) offset: 192 (bits) vtbl reference: 
Determining dynamic type for call: mqtt_close (arg_29(D), 257);
  Starting walk at: mqtt_close (arg_29(D), 257);
  instance pointer: arg_29(D)  Outer instance pointer: arg_29(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_request_time_elapsed (_6, 5);
Determining dynamic type for call: _22 = mqtt_output_check_space (_21, 0);
  Starting walk at: _22 = mqtt_output_check_space (_21, 0);
  instance pointer: _21  Outer instance pointer: arg_29(D) offset: 1888 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_request_time_elapsed (_6, 5);
  Function call may change dynamic type:mqtt_close (arg_29(D), 257);
Determining dynamic type for call: mqtt_output_append_fixed_header (_21, 12, 0, 0, 0, 0);
  Starting walk at: mqtt_output_append_fixed_header (_21, 12, 0, 0, 0, 0);
  instance pointer: _21  Outer instance pointer: arg_29(D) offset: 1888 (bits) vtbl reference: 
  Function call may change dynamic type:_22 = mqtt_output_check_space (_21, 0);
  Function call may change dynamic type:mqtt_request_time_elapsed (_6, 5);
  Function call may change dynamic type:mqtt_close (arg_29(D), 257);
Determining dynamic type for call: mqtt_close (arg_29(D), 257);
  Starting walk at: mqtt_close (arg_29(D), 257);
  instance pointer: arg_29(D)  Outer instance pointer: arg_29(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: mqtt_clear_requests (_6);
  Starting walk at: mqtt_clear_requests (_6);
  instance pointer: _6  Outer instance pointer: client_14(D) offset: 192 (bits) vtbl reference: 
  Function call may change dynamic type:res_20 = tcp_close (_4);
  Function call may change dynamic type:tcp_sent (_3, 0B);
  Function call may change dynamic type:tcp_err (_2, 0B);
  Function call may change dynamic type:tcp_recv (_1, 0B);
  Function call may change dynamic type:tcp_abort (_5);
Determining dynamic type for call: _8 (client_14(D), _9, reason_26(D));
  Starting walk at: _8 (client_14(D), _9, reason_26(D));
  instance pointer: client_14(D)  Outer instance pointer: client_14(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:sys_untimeout (mqtt_cyclic_timer, client_14(D));
  Function call may change dynamic type:mqtt_clear_requests (_6);
  Function call may change dynamic type:res_20 = tcp_close (_4);
  Function call may change dynamic type:tcp_sent (_3, 0B);
  Function call may change dynamic type:tcp_err (_2, 0B);
  Function call may change dynamic type:tcp_recv (_1, 0B);
  Function call may change dynamic type:tcp_abort (_5);
Determining dynamic type for call: _8 (client_14(D), _9, reason_26(D));
  Starting walk at: _8 (client_14(D), _9, reason_26(D));
  instance pointer: _9  Outer instance pointer: _9 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:sys_untimeout (mqtt_cyclic_timer, client_14(D));
  Function call may change dynamic type:mqtt_clear_requests (_6);
  Function call may change dynamic type:res_20 = tcp_close (_4);
  Function call may change dynamic type:tcp_sent (_3, 0B);
  Function call may change dynamic type:tcp_err (_2, 0B);
  Function call may change dynamic type:tcp_recv (_1, 0B);
  Function call may change dynamic type:tcp_abort (_5);
Determining dynamic type for call: _3 = mqtt_ringbuf_len (rb_12(D));
  Starting walk at: _3 = mqtt_ringbuf_len (rb_12(D));
  instance pointer: rb_12(D)  Outer instance pointer: rb_12(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: mqtt_ringbuf_put (rb_30(D), _17);
  Starting walk at: mqtt_ringbuf_put (rb_30(D), _17);
  instance pointer: rb_30(D)  Outer instance pointer: rb_30(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: mqtt_ringbuf_put (rb_30(D), _21);
  Starting walk at: mqtt_ringbuf_put (rb_30(D), _21);
  instance pointer: rb_30(D)  Outer instance pointer: rb_30(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_ringbuf_put (rb_30(D), _17);
  Function call may change dynamic type:mqtt_ringbuf_put (rb_30(D), _21);
Determining dynamic type for call: mqtt_ringbuf_put (rb_11(D), _2);
  Starting walk at: mqtt_ringbuf_put (rb_11(D), _2);
  instance pointer: rb_11(D)  Outer instance pointer: rb_11(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: mqtt_ringbuf_put (rb_11(D), _3);
  Starting walk at: mqtt_ringbuf_put (rb_11(D), _3);
  instance pointer: rb_11(D)  Outer instance pointer: rb_11(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_ringbuf_put (rb_11(D), _2);
Determining dynamic type for call: mqtt_ringbuf_put (rb_11(D), _6);
  Starting walk at: mqtt_ringbuf_put (rb_11(D), _6);
  instance pointer: rb_11(D)  Outer instance pointer: rb_11(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_ringbuf_put (rb_11(D), _3);
  Function call may change dynamic type:mqtt_ringbuf_put (rb_11(D), _2);
  Function call may change dynamic type:mqtt_ringbuf_put (rb_11(D), _6);
Determining dynamic type for call: mqtt_ringbuf_put (rb_9(D), _3);
  Starting walk at: mqtt_ringbuf_put (rb_9(D), _3);
  instance pointer: rb_9(D)  Outer instance pointer: rb_9(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_ringbuf_put (rb_9(D), _3);
Determining dynamic type for call: mqtt_ringbuf_put (rb_6(D), _2);
  Starting walk at: mqtt_ringbuf_put (rb_6(D), _2);
  instance pointer: rb_6(D)  Outer instance pointer: rb_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: mqtt_ringbuf_put (rb_6(D), _3);
  Starting walk at: mqtt_ringbuf_put (rb_6(D), _3);
  instance pointer: rb_6(D)  Outer instance pointer: rb_6(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_ringbuf_put (rb_6(D), _2);
Determining dynamic type for call: mqtt_delete_request (iter_1);
  Starting walk at: mqtt_delete_request (iter_1);
  instance pointer: iter_1  Outer instance pointer: iter_1 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_delete_request (iter_1);
Determining dynamic type for call: _6 (_7, -3);
  Starting walk at: _6 (_7, -3);
  instance pointer: _7  Outer instance pointer: _7 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_delete_request (r_12);
  Function call may change dynamic type:_6 (_7, -3);
Determining dynamic type for call: mqtt_delete_request (r_12);
  Starting walk at: mqtt_delete_request (r_12);
  instance pointer: r_12  Outer instance pointer: r_12 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_delete_request (r_12);
  Function call may change dynamic type:_6 (_7, -3);
Determining dynamic type for call: r_1 = mqtt_create_request.part.0 (r_objs_5(D), r_objs_len_7(D), pkt_id_10(D), cb_8(D), arg_9(D));
  Starting walk at: r_1 = mqtt_create_request.part.0 (r_objs_5(D), r_objs_len_7(D), pkt_id_10(D), cb_8(D), arg_9(D));
  instance pointer: r_objs_5(D)  Outer instance pointer: r_objs_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: r_1 = mqtt_create_request.part.0 (r_objs_5(D), r_objs_len_7(D), pkt_id_10(D), cb_8(D), arg_9(D));
  Starting walk at: r_1 = mqtt_create_request.part.0 (r_objs_5(D), r_objs_len_7(D), pkt_id_10(D), cb_8(D), arg_9(D));
  instance pointer: cb_8(D)  Outer instance pointer: cb_8(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: r_1 = mqtt_create_request.part.0 (r_objs_5(D), r_objs_len_7(D), pkt_id_10(D), cb_8(D), arg_9(D));
  Starting walk at: r_1 = mqtt_create_request.part.0 (r_objs_5(D), r_objs_len_7(D), pkt_id_10(D), cb_8(D), arg_9(D));
  instance pointer: arg_9(D)  Outer instance pointer: arg_9(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = mqtt_ringbuf_len (rb_25(D));
  Starting walk at: _1 = mqtt_ringbuf_len (rb_25(D));
  instance pointer: rb_25(D)  Outer instance pointer: rb_25(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: mqtt_ringbuf_advance_get_idx.isra.0 (_40, send_len_16);
  Starting walk at: mqtt_ringbuf_advance_get_idx.isra.0 (_40, send_len_16);
  instance pointer: _40  Outer instance pointer: rb_25(D) offset: 16 (bits) vtbl reference: 
  Function call may change dynamic type:err_32 = tcp_write (tpcb_27(D), _34, send_len_16, iftmp.9_19);
Determining dynamic type for call: _9 = mqtt_ringbuf_len (rb_25(D));
  Starting walk at: _9 = mqtt_ringbuf_len (rb_25(D));
  instance pointer: rb_25(D)  Outer instance pointer: rb_25(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mqtt_ringbuf_advance_get_idx.isra.0 (_40, send_len_16);
  Function call may change dynamic type:err_32 = tcp_write (tpcb_27(D), _34, send_len_16, iftmp.9_19);
Determining dynamic type for call: mqtt_ringbuf_advance_get_idx.isra.0 (_41, send_len_17);
  Starting walk at: mqtt_ringbuf_advance_get_idx.isra.0 (_41, send_len_17);
  instance pointer: _41  Outer instance pointer: rb_25(D) offset: 16 (bits) vtbl reference: 
  Function call may change dynamic type:err_32 = tcp_write (tpcb_27(D), _34, send_len_16, iftmp.9_19);
  Function call may change dynamic type:err_37 = tcp_write (tpcb_27(D), _30, iftmp.10_20, 1);
  Function call may change dynamic type:mqtt_ringbuf_advance_get_idx.isra.0 (_40, send_len_16);

IPA structures before propagation:

Jump functions:
  Jump functions of caller  mqtt_tcp_recv_cb.part.0/72:
    callsite  mqtt_tcp_recv_cb.part.0/72 -> mqtt_parse_incoming/25 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  mqtt_tcp_recv_cb.part.0/72 -> mqtt_close/20 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
  Jump functions of caller  mqtt_tcp_connect_cb.part.0/71:
    callsite  mqtt_tcp_connect_cb.part.0/71 -> mqtt_output_send/6 : 
       param 0: ANCESTOR: 0, offset 1888
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  mqtt_tcp_err_cb.part.0/70:
    callsite  mqtt_tcp_err_cb.part.0/70 -> mqtt_close/20 : 
       param 0: PASS THROUGH: 0, op nop_expr
         Aggregate passed by reference:
           offset: 96, cst: 0B
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 256
         value: 0x100, mask: 0x0
         Unknown VR
  Jump functions of caller  mqtt_tcp_sent_cb.part.0/69:
    callsite  mqtt_tcp_sent_cb.part.0/69 -> mqtt_delete_request/9 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  mqtt_tcp_sent_cb.part.0/69 -> mqtt_take_request/10 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  mqtt_tcp_sent_cb.part.0/69 -> mqtt_output_send/6 : 
       param 0: ANCESTOR: 0, offset 1888
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    indirect simple callsite, calling param -1, offset 0, for stmt _2 (_3, 0);
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  mqtt_create_request.part.0/65:
  Jump functions of caller  mqtt_ringbuf_advance_get_idx.isra.0.part.0/64:
  Jump functions of caller  mqtt_ringbuf_advance_get_idx.isra.0/63:
    callsite  mqtt_ringbuf_advance_get_idx.isra.0/63 -> mqtt_ringbuf_advance_get_idx.isra.0.part.0/64 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
  Jump functions of caller  msg_generate_packet_id.isra.0/62:
  Jump functions of caller  pbuf_copy_partial/61:
  Jump functions of caller  pbuf_get_at/60:
  Jump functions of caller  tcp_recved/59:
  Jump functions of caller  pbuf_free/58:
  Jump functions of caller  tcp_poll/57:
  Jump functions of caller  sys_timeout/56:
  Jump functions of caller  sys_untimeout/55:
  Jump functions of caller  tcp_close/54:
  Jump functions of caller  tcp_sent/53:
  Jump functions of caller  tcp_recv/52:
  Jump functions of caller  tcp_abort/51:
  Jump functions of caller  tcp_err/50:
  Jump functions of caller  tcp_connect/49:
  Jump functions of caller  tcp_bind/47:
  Jump functions of caller  tcp_arg/46:
  Jump functions of caller  tcp_new_ip_type/45:
  Jump functions of caller  memset/44:
  Jump functions of caller  mem_free/43:
  Jump functions of caller  mem_calloc/42:
  Jump functions of caller  tcp_output/41:
  Jump functions of caller  tcp_write/40:
  Jump functions of caller  strlen/39:
  Jump functions of caller  mqtt_client_is_connected/38:
  Jump functions of caller  mqtt_disconnect/37:
    callsite  mqtt_disconnect/37 -> mqtt_close/20 : 
       param 0: PASS THROUGH: 0, op nop_expr
         Aggregate passed by reference:
           offset: 80, cst: 0
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  mqtt_client_connect/36:
    callsite  mqtt_client_connect/36 -> mqtt_output_append_string/17 : 
       param 0: ANCESTOR: 0, offset 1888
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
    callsite  mqtt_client_connect/36 -> mqtt_output_append_string/17 : 
       param 0: ANCESTOR: 0, offset 1888
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
    callsite  mqtt_client_connect/36 -> mqtt_output_append_string/17 : 
       param 0: ANCESTOR: 0, offset 1888
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xff
         VR  [0, 255]
    callsite  mqtt_client_connect/36 -> mqtt_output_append_string/17 : 
       param 0: ANCESTOR: 0, offset 1888
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xff
         VR  [0, 255]
    callsite  mqtt_client_connect/36 -> mqtt_output_append_string/17 : 
       param 0: ANCESTOR: 0, offset 1888
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
    callsite  mqtt_client_connect/36 -> mqtt_output_append_u16/15 : 
       param 0: ANCESTOR: 0, offset 1888
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
    callsite  mqtt_client_connect/36 -> mqtt_ringbuf_put/2 : 
       param 0: ANCESTOR: 0, offset 1888
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xfe
         VR  [2, -1]
    callsite  mqtt_client_connect/36 -> mqtt_ringbuf_put/2 : 
       param 0: ANCESTOR: 0, offset 1888
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: CONST: 4
         value: 0x4, mask: 0x0
         Unknown VR
    callsite  mqtt_client_connect/36 -> mqtt_output_append_string/17 : 
       param 0: ANCESTOR: 0, offset 1888
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: CONST: "MQTT"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 2: CONST: 4
         value: 0x4, mask: 0x0
         Unknown VR
    callsite  mqtt_client_connect/36 -> mqtt_output_append_fixed_header/18 : 
       param 0: ANCESTOR: 0, offset 1888
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 3: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 4: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 5: UNKNOWN
         value: 0x0, mask: 0xffff
         VR  [12, -1]
    callsite  mqtt_client_connect/36 -> mqtt_output_check_space/19 : 
       param 0: ANCESTOR: 0, offset 1888
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffff
         VR  [12, -1]
    callsite  mqtt_client_connect/36 -> mqtt_init_requests/13 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: CONST: 4
         value: 0x4, mask: 0x0
         Unknown VR
  Jump functions of caller  mqtt_client_free/35:
  Jump functions of caller  mqtt_client_new/34:
  Jump functions of caller  mqtt_set_inpub_callback/33:
  Jump functions of caller  mqtt_sub_unsub/32:
    callsite  mqtt_sub_unsub/32 -> mqtt_output_send/6 : 
       param 0: ANCESTOR: 0, offset 1888
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  mqtt_sub_unsub/32 -> mqtt_append_request/8 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  mqtt_sub_unsub/32 -> mqtt_ringbuf_put/2 : 
       param 0: ANCESTOR: 0, offset 1888
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0x3
         VR  [0, 2]
    callsite  mqtt_sub_unsub/32 -> mqtt_output_append_string/17 : 
       param 0: ANCESTOR: 0, offset 1888
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffff
         VR  [0, -3]
    callsite  mqtt_sub_unsub/32 -> mqtt_output_append_u16/15 : 
       param 0: ANCESTOR: 0, offset 1888
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
    callsite  mqtt_sub_unsub/32 -> mqtt_output_append_fixed_header/18 : 
       param 0: ANCESTOR: 0, offset 1888
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xa
         VR  [8, 10]
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 3: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 4: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 5: UNKNOWN
         value: 0x0, mask: 0xffff
         VR  [4, -1]
    callsite  mqtt_sub_unsub/32 -> mqtt_delete_request/9 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  mqtt_sub_unsub/32 -> mqtt_output_check_space/19 : 
       param 0: ANCESTOR: 0, offset 1888
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffff
         VR  [4, -1]
    callsite  mqtt_sub_unsub/32 -> mqtt_create_request/7 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: CONST: 4
         value: 0x4, mask: 0x0
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: PASS THROUGH: 4, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  mqtt_sub_unsub/32 -> msg_generate_packet_id.isra.0/62 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
  Jump functions of caller  mqtt_publish/31:
    callsite  mqtt_publish/31 -> mqtt_output_send/6 : 
       param 0: ANCESTOR: 0, offset 1888
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  mqtt_publish/31 -> mqtt_append_request/8 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  mqtt_publish/31 -> mqtt_output_append_buf/16 : 
       param 0: ANCESTOR: 0, offset 1888
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
    callsite  mqtt_publish/31 -> mqtt_output_append_u16/15 : 
       param 0: ANCESTOR: 0, offset 1888
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
    callsite  mqtt_publish/31 -> mqtt_output_append_string/17 : 
       param 0: ANCESTOR: 0, offset 1888
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffff
         VR  [0, -3]
    callsite  mqtt_publish/31 -> mqtt_output_append_fixed_header/18 : 
       param 0: ANCESTOR: 0, offset 1888
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: CONST: 3
         value: 0x3, mask: 0x0
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 3: PASS THROUGH: 4, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 4: PASS THROUGH: 5, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 5: UNKNOWN
         value: 0x0, mask: 0xffff
         VR  [2, -1]
    callsite  mqtt_publish/31 -> mqtt_delete_request/9 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  mqtt_publish/31 -> mqtt_output_check_space/19 : 
       param 0: ANCESTOR: 0, offset 1888
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffff
         VR  [2, -1]
    callsite  mqtt_publish/31 -> mqtt_create_request/7 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: CONST: 4
         value: 0x4, mask: 0x0
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 3: PASS THROUGH: 6, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: PASS THROUGH: 7, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  mqtt_publish/31 -> msg_generate_packet_id.isra.0/62 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
  Jump functions of caller  mqtt_tcp_connect_cb/30:
    callsite  mqtt_tcp_connect_cb/30 -> mqtt_tcp_connect_cb.part.0/71 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  mqtt_tcp_poll_cb/29:
    callsite  mqtt_tcp_poll_cb/29 -> mqtt_output_send/6 : 
       param 0: ANCESTOR: 0, offset 1888, agg_preserved
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  mqtt_tcp_err_cb/28:
    callsite  mqtt_tcp_err_cb/28 -> mqtt_tcp_err_cb.part.0/70 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  mqtt_tcp_sent_cb/27:
    callsite  mqtt_tcp_sent_cb/27 -> mqtt_tcp_sent_cb.part.0/69 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  mqtt_tcp_recv_cb/26:
    callsite  mqtt_tcp_recv_cb/26 -> mqtt_tcp_recv_cb.part.0/72 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  mqtt_tcp_recv_cb/26 -> mqtt_close/20 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 256
         value: 0x100, mask: 0x0
         Unknown VR
  Jump functions of caller  mqtt_parse_incoming/25:
    callsite  mqtt_parse_incoming/25 -> mqtt_message_received/24 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  mqtt_parse_incoming/25 -> mqtt_message_received/24 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 3: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  mqtt_message_received/24:
    callsite  mqtt_message_received/24 -> mqtt_delete_request/9 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  mqtt_message_received/24 -> mqtt_incomming_suback/23 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  mqtt_message_received/24 -> mqtt_take_request/10 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
    callsite  mqtt_message_received/24 -> pub_ack_rec_rel_response/22 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 7
         value: 0x7, mask: 0x0
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 3: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  mqtt_message_received/24 -> pub_ack_rec_rel_response/22 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 6
         value: 0x6, mask: 0x0
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 3: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
    callsite  mqtt_message_received/24 -> pub_ack_rec_rel_response/22 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0x5
         VR  [4, 5]
       param 2: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 3: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    indirect simple callsite, calling param -1, offset 0, for stmt _64 (_65, 0);
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    indirect aggregate callsite, calling param 0, offset 768, by reference, for stmt _51 (_52, _54, payload_length_67, _56);
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 2: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0x1
         VR  [0, 1]
    indirect aggregate callsite, calling param 0, offset 800, by reference, for stmt _42 (_43, topic_99, _45);
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    indirect aggregate callsite, calling param 0, offset 160, by reference, for stmt _10 (client_80(D), _11, 0);
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  mqtt_incomming_suback/23:
    indirect aggregate callsite, calling param 0, offset 32, by reference, for stmt _1 (_2, iftmp.24_3);
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff3
         VR  [-13, 0]
  Jump functions of caller  pub_ack_rec_rel_response/22:
    callsite  pub_ack_rec_rel_response/22 -> mqtt_output_send/6 : 
       param 0: ANCESTOR: 0, offset 1888
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pub_ack_rec_rel_response/22 -> mqtt_output_append_u16/15 : 
       param 0: ANCESTOR: 0, offset 1888
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
    callsite  pub_ack_rec_rel_response/22 -> mqtt_output_append_fixed_header/18 : 
       param 0: ANCESTOR: 0, offset 1888
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 4: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 5: CONST: 2
         value: 0x2, mask: 0x0
         Unknown VR
    callsite  pub_ack_rec_rel_response/22 -> mqtt_output_check_space/19 : 
       param 0: ANCESTOR: 0, offset 1888, agg_preserved
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: CONST: 2
         value: 0x2, mask: 0x0
         Unknown VR
  Jump functions of caller  mqtt_cyclic_timer/21:
    callsite  mqtt_cyclic_timer/21 -> mqtt_output_append_fixed_header/18 : 
       param 0: ANCESTOR: 0, offset 1888
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: CONST: 12
         value: 0xc, mask: 0x0
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 3: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 4: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 5: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  mqtt_cyclic_timer/21 -> mqtt_output_check_space/19 : 
       param 0: ANCESTOR: 0, offset 1888
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  mqtt_cyclic_timer/21 -> mqtt_close/20 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 257
         value: 0x101, mask: 0x0
         Unknown VR
    callsite  mqtt_cyclic_timer/21 -> mqtt_request_time_elapsed/11 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: CONST: 5
         value: 0x5, mask: 0x0
         Unknown VR
    callsite  mqtt_cyclic_timer/21 -> mqtt_close/20 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 257
         value: 0x101, mask: 0x0
         Unknown VR
  Jump functions of caller  mqtt_close/20:
    callsite  mqtt_close/20 -> mqtt_clear_requests/12 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    indirect aggregate callsite, calling param 0, offset 160, by reference, for stmt _8 (client_14(D), _9, reason_26(D));
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
  Jump functions of caller  mqtt_output_check_space/19:
    callsite  mqtt_output_check_space/19 -> mqtt_ringbuf_len/5 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  mqtt_output_append_fixed_header/18:
    callsite  mqtt_output_append_fixed_header/18 -> mqtt_ringbuf_put/2 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  mqtt_output_append_fixed_header/18 -> mqtt_ringbuf_put/2 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  mqtt_output_append_string/17:
    callsite  mqtt_output_append_string/17 -> mqtt_ringbuf_put/2 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  mqtt_output_append_string/17 -> mqtt_ringbuf_put/2 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  mqtt_output_append_string/17 -> mqtt_ringbuf_put/2 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  mqtt_output_append_buf/16:
    callsite  mqtt_output_append_buf/16 -> mqtt_ringbuf_put/2 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  mqtt_output_append_u16/15:
    callsite  mqtt_output_append_u16/15 -> mqtt_ringbuf_put/2 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  mqtt_output_append_u16/15 -> mqtt_ringbuf_put/2 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  mqtt_init_requests/13:
  Jump functions of caller  mqtt_clear_requests/12:
    callsite  mqtt_clear_requests/12 -> mqtt_delete_request/9 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  mqtt_request_time_elapsed/11:
    callsite  mqtt_request_time_elapsed/11 -> mqtt_delete_request/9 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    indirect simple callsite, calling param -1, offset 0, for stmt _6 (_7, -3);
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: -3
         value: 0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffd, mask: 0x0
         Unknown VR
  Jump functions of caller  mqtt_take_request/10:
  Jump functions of caller  mqtt_delete_request/9:
  Jump functions of caller  mqtt_append_request/8:
  Jump functions of caller  mqtt_create_request/7:
    callsite  mqtt_create_request/7 -> mqtt_create_request.part.0/65 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: PASS THROUGH: 4, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  mqtt_output_send/6:
    callsite  mqtt_output_send/6 -> mqtt_ringbuf_advance_get_idx.isra.0/63 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
    callsite  mqtt_output_send/6 -> mqtt_ringbuf_len/5 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  mqtt_output_send/6 -> mqtt_ringbuf_advance_get_idx.isra.0/63 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffff
         VR  [1, -1]
    callsite  mqtt_output_send/6 -> mqtt_ringbuf_len/5 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  mqtt_ringbuf_len/5:
  Jump functions of caller  mqtt_ringbuf_put/2:

 Propagating constants:

Not considering mqtt_client_is_connected for cloning; -fipa-cp-clone disabled.
Not considering mqtt_disconnect for cloning; -fipa-cp-clone disabled.
Not considering mqtt_client_connect for cloning; -fipa-cp-clone disabled.
Not considering mqtt_client_free for cloning; -fipa-cp-clone disabled.
Not considering mqtt_client_new for cloning; -fipa-cp-clone disabled.
Not considering mqtt_set_inpub_callback for cloning; -fipa-cp-clone disabled.
Not considering mqtt_sub_unsub for cloning; -fipa-cp-clone disabled.
Not considering mqtt_publish for cloning; -fipa-cp-clone disabled.
Not considering mqtt_tcp_connect_cb for cloning; -fipa-cp-clone disabled.
Not considering mqtt_tcp_poll_cb for cloning; -fipa-cp-clone disabled.
Not considering mqtt_tcp_err_cb for cloning; -fipa-cp-clone disabled.
Not considering mqtt_tcp_sent_cb for cloning; -fipa-cp-clone disabled.
Not considering mqtt_tcp_recv_cb for cloning; -fipa-cp-clone disabled.
Not considering mqtt_cyclic_timer for cloning; -fipa-cp-clone disabled.

overall_size: 1285, max_new_size: 11001
 - context independent values, size: 9, time_benefit: 1.000000
 - context independent values, size: 10, time_benefit: 2.000000
 - context independent values, size: 18, time_benefit: 3.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 12, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 31, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 12, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.
 - context independent values, size: 14, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.

IPA lattices after all propagation:

Lattices:
  Node: mqtt_tcp_recv_cb.part.0/72:
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
  Node: mqtt_tcp_connect_cb.part.0/71:
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
  Node: mqtt_tcp_err_cb.part.0/70:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: mqtt_tcp_sent_cb.part.0/69:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: mqtt_create_request.part.0/65:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct mqtt_request_t * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: 4 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x4, mask = 0x0
         size_t [4, 4]
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
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: mqtt_ringbuf_advance_get_idx.isra.0.part.0/64:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         u16_t * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: mqtt_ringbuf_advance_get_idx.isra.0/63:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         u16_t * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: msg_generate_packet_id.isra.0/62:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         u16_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: mqtt_client_is_connected/38:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: mqtt_disconnect/37:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: mqtt_client_connect/36:
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
  Node: mqtt_client_free/35:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: mqtt_client_new/34:
  Node: mqtt_set_inpub_callback/33:
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
  Node: mqtt_sub_unsub/32:
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
  Node: mqtt_publish/31:
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
  Node: mqtt_tcp_connect_cb/30:
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
  Node: mqtt_tcp_poll_cb/29:
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
  Node: mqtt_tcp_err_cb/28:
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
  Node: mqtt_tcp_sent_cb/27:
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
  Node: mqtt_tcp_recv_cb/26:
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
  Node: mqtt_parse_incoming/25:
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
  Node: mqtt_message_received/24:
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
               0 [loc_time: 1, loc_size: 162, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [3]: VARIABLE
               0 [loc_time: 1, loc_size: 180, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: mqtt_incomming_suback/23:
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
  Node: pub_ack_rec_rel_response/22:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
               6 [loc_time: 1, loc_size: 23, prop_time: 0, prop_size: 0]
               7 [loc_time: 1, loc_size: 23, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x7, mask = 0x7
         u8_t [4, 7]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [3]: 1 [loc_time: 1, loc_size: 23, prop_time: 0, prop_size: 0]
               0 [loc_time: 1, loc_size: 23, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x1
         u8_t [0, 1]
        AGGS VARIABLE
  Node: mqtt_cyclic_timer/21:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: mqtt_close/20:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
               257 [loc_time: 1, loc_size: 50, prop_time: 0, prop_size: 0]
               256 [loc_time: 1, loc_size: 50, prop_time: 0, prop_size: 0]
               0 [loc_time: 1, loc_size: 50, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: mqtt_output_check_space/19:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct mqtt_ringbuf_t * ~[0B, 0B]
        AGGS BOTTOM
    param [1]: VARIABLE
               0 [loc_time: 2, loc_size: 16, prop_time: 0, prop_size: 0]
               2 [loc_time: 2, loc_size: 16, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         u16_t ~[1, 1]
        AGGS VARIABLE
  Node: mqtt_output_append_fixed_header/18:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct mqtt_ringbuf_t * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
               12 [loc_time: 6, loc_size: 21, prop_time: 0, prop_size: 0]
               7 [loc_time: 6, loc_size: 21, prop_time: 0, prop_size: 0]
               6 [loc_time: 6, loc_size: 21, prop_time: 0, prop_size: 0]
               3 [loc_time: 6, loc_size: 21, prop_time: 0, prop_size: 0]
               1 [loc_time: 6, loc_size: 21, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x1, mask = 0xf
         u8_t [1, 12]
        AGGS VARIABLE
    param [2]: 0 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x0
         u8_t [0, 0]
        AGGS VARIABLE
    param [3]: VARIABLE
               1 [loc_time: 6, loc_size: 21, prop_time: 0, prop_size: 0]
               0 [loc_time: 6, loc_size: 21, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [4]: VARIABLE
               0 [loc_time: 5, loc_size: 22, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [5]: VARIABLE
               0 [loc_time: 4, loc_size: 23, prop_time: 0, prop_size: 0]
               2 [loc_time: 4, loc_size: 23, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         u16_t ~[1, 1]
        AGGS VARIABLE
  Node: mqtt_output_append_string/17:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct mqtt_ringbuf_t * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
               "MQTT" [loc_time: 1, loc_size: 18, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [2]: VARIABLE
               4 [loc_time: 66, loc_size: 17, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: mqtt_output_append_buf/16:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct mqtt_ringbuf_t * ~[0B, 0B]
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
  Node: mqtt_output_append_u16/15:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct mqtt_ringbuf_t * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: mqtt_init_requests/13:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct mqtt_request_t * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: 4 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x4, mask = 0x0
         size_t [4, 4]
        AGGS VARIABLE
  Node: mqtt_clear_requests/12:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct mqtt_request_t * * ~[0B, 0B]
        AGGS VARIABLE
  Node: mqtt_request_time_elapsed/11:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct mqtt_request_t * * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: 5 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x5, mask = 0x0
         u8_t [5, 5]
        AGGS VARIABLE
  Node: mqtt_take_request/10:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
               0 [loc_time: 1, loc_size: 30, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: mqtt_delete_request/9:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: mqtt_append_request/8:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct mqtt_request_t * * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: mqtt_create_request/7:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct mqtt_request_t * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: 4 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x4, mask = 0x0
         size_t [4, 4]
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
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: mqtt_output_send/6:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: mqtt_ringbuf_len/5:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: mqtt_ringbuf_put/2:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct mqtt_ringbuf_t * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
               4 [loc_time: 1, loc_size: 10, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE

IPA decision stage:

 - Creating a specialized node of mqtt_output_append_fixed_header/18 for all known contexts.
    replacing param #2 fdup with const 0
 - Creating a specialized node of mqtt_init_requests/13 for all known contexts.
    replacing param #1 r_objs_len with const 4
 - Creating a specialized node of mqtt_request_time_elapsed/11 for all known contexts.
    replacing param #1 t with const 5
 - Creating a specialized node of mqtt_create_request/7 for all known contexts.
    replacing param #1 r_objs_len with const 4
 - Creating a specialized node of mqtt_create_request.part.0/65 for all known contexts.
    replacing param #1 r_objs_len with const 4
Propagated bits info for function mqtt_create_request.part.0.constprop/79:
 param 1: value = 0x4, mask = 0x0
Propagated bits info for function mqtt_create_request.constprop/78:
 param 1: value = 0x4, mask = 0x0
Propagated bits info for function mqtt_request_time_elapsed.constprop/77:
 param 1: value = 0x5, mask = 0x0
Propagated bits info for function mqtt_init_requests.constprop/76:
 param 1: value = 0x4, mask = 0x0
Propagated bits info for function mqtt_output_append_fixed_header.constprop/75:
 param 1: value = 0x1, mask = 0xf
 param 2: value = 0x0, mask = 0x0
Propagated bits info for function mqtt_create_request.part.0/65:
 param 1: value = 0x4, mask = 0x0
Propagated bits info for function pub_ack_rec_rel_response/22:
 param 1: value = 0x7, mask = 0x7
 param 3: value = 0x0, mask = 0x1
Propagated bits info for function mqtt_output_append_fixed_header/18:
 param 1: value = 0x1, mask = 0xf
 param 2: value = 0x0, mask = 0x0
Propagated bits info for function mqtt_init_requests/13:
 param 1: value = 0x4, mask = 0x0
Propagated bits info for function mqtt_request_time_elapsed/11:
 param 1: value = 0x5, mask = 0x0
Propagated bits info for function mqtt_create_request/7:
 param 1: value = 0x4, mask = 0x0

IPA constant propagation end

Reclaiming functions: mqtt_create_request.part.0/65 mqtt_output_append_fixed_header/18 mqtt_init_requests/13 mqtt_request_time_elapsed/11 mqtt_create_request/7
Reclaiming variables:
Clearing address taken flags:
Symbol table:

mqtt_create_request.part.0.constprop.0/79 (mqtt_create_request.part.0.constprop) @065162a0
  Type: function definition analyzed
  Visibility: artificial
  References: 
  Referring: 
  Clone of mqtt_create_request.part.0/65
  Availability: local
  Function flags: count:114863532 (estimated locally) first_run:1 local split_part optimize_size
  Called by: mqtt_create_request.constprop/78 (250539 (estimated locally),0.70 per call) 
  Calls: 
mqtt_create_request.constprop.0/78 (mqtt_create_request.constprop) @064be2a0
  Type: function definition analyzed
  Visibility:
  References: 
  Referring: 
  Clone of mqtt_create_request/7
  Availability: local
  Function flags: count:357913 (estimated locally) local optimize_size
  Called by: mqtt_publish/31 (168159 (estimated locally),0.47 per call) mqtt_sub_unsub/32 (84080 (estimated locally),0.23 per call) 
  Calls: mqtt_create_request.part.0.constprop/79 (250539 (estimated locally),0.70 per call) 
mqtt_request_time_elapsed.constprop.0/77 (mqtt_request_time_elapsed.constprop) @0626d620
  Type: function definition analyzed
  Visibility:
  References: 
  Referring: 
  Clone of mqtt_request_time_elapsed/11
  Availability: local
  Function flags: count:357913 (estimated locally) local optimize_size
  Called by: mqtt_cyclic_timer/21 (33468 (estimated locally),0.09 per call) 
  Calls: mqtt_delete_request/9 (2116828 (estimated locally),5.91 per call) 
   Indirect call(1481780 (estimated locally),4.14 per call) 
mqtt_init_requests.constprop.0/76 (mqtt_init_requests.constprop) @062548c0
  Type: function definition analyzed
  Visibility:
  References: 
  Referring: 
  Clone of mqtt_init_requests/13
  Availability: local
  Function flags: count:357913 (estimated locally) local optimize_size
  Called by: mqtt_client_connect/36 (84139 (estimated locally),0.24 per call) 
  Calls: 
mqtt_output_append_fixed_header.constprop.0/75 (mqtt_output_append_fixed_header.constprop) @062540e0
  Type: function definition analyzed
  Visibility:
  References: 
  Referring: 
  Clone of mqtt_output_append_fixed_header/18
  Availability: local
  Function flags: count:118111600 (estimated locally) local optimize_size
  Called by: pub_ack_rec_rel_response/22 (1031006900 (estimated locally),0.96 per call) mqtt_cyclic_timer/21 (1822 (estimated locally),0.01 per call) mqtt_publish/31 (164896 (estimated locally),0.46 per call) mqtt_sub_unsub/32 (82881 (estimated locally),0.23 per call) mqtt_client_connect/36 (17816 (estimated locally),0.05 per call) 
  Calls: mqtt_ringbuf_put/2 (118111600 (estimated locally),1.00 per call) mqtt_ringbuf_put/2 (1073741824 (estimated locally),9.09 per call) 
mqtt_tcp_recv_cb.part.0/72 (mqtt_tcp_recv_cb.part.0) @064beb60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: mqtt_tcp_recv_cb/26 (25078 (estimated locally),0.11 per call) 
  Calls: tcp_recved/59 (1073741824 (estimated locally),1.00 per call) mqtt_parse_incoming/25 (1073741824 (estimated locally),1.00 per call) pbuf_free/58 (1073741824 (estimated locally),1.00 per call) mqtt_close/20 (354334802 (estimated locally),0.33 per call) 
mqtt_tcp_connect_cb.part.0/71 (mqtt_tcp_connect_cb.part.0) @0649ca80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: mqtt_tcp_recv_cb/26 (addr)mqtt_tcp_sent_cb/27 (addr)mqtt_tcp_poll_cb/29 (addr)mqtt_cyclic_timer/21 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: mqtt_tcp_connect_cb/30 (524845000 (estimated locally),0.49 per call) 
  Calls: tcp_recv/52 (1073741824 (estimated locally),1.00 per call) tcp_sent/53 (1073741824 (estimated locally),1.00 per call) tcp_poll/57 (1073741824 (estimated locally),1.00 per call) sys_timeout/56 (1073741824 (estimated locally),1.00 per call) mqtt_output_send/6 (1073741824 (estimated locally),1.00 per call) 
mqtt_tcp_err_cb.part.0/70 (mqtt_tcp_err_cb.part.0) @06254620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: mqtt_tcp_err_cb/28 (123389 (estimated locally),0.53 per call) 
  Calls: mqtt_close/20 (1073741824 (estimated locally),1.00 per call) 
mqtt_tcp_sent_cb.part.0/69 (mqtt_tcp_sent_cb.part.0) @0649c9a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:118111600 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: mqtt_tcp_sent_cb/27 (118111600 (estimated locally),0.34 per call) 
  Calls: mqtt_delete_request/9 (955630223 (estimated locally),8.09 per call) mqtt_take_request/10 (1073741824 (estimated locally),9.09 per call) mqtt_output_send/6 (118111601 (estimated locally),1.00 per call) 
   Indirect call(668941156 (estimated locally),5.66 per call) 
mqtt_create_request.part.0/65 (mqtt_create_request.part.0) @063e9e00
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:114863532 (estimated locally) first_run:1 body split_part optimize_size
  Called by: 
  Calls: 
mqtt_ringbuf_advance_get_idx.isra.0.part.0/64 (mqtt_ringbuf_advance_get_idx.isra.0.part.0) @063e9540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: mqtt_ringbuf_advance_get_idx.isra.0/63 (107374 (estimated locally),0.50 per call) 
  Calls: 
mqtt_ringbuf_advance_get_idx.isra.0/63 (mqtt_ringbuf_advance_get_idx.isra.0) @063e9000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:214748 (estimated locally) body local optimize_size
  Called by: mqtt_output_send/6 (154348240 (estimated locally),0.14 per call) mqtt_output_send/6 (77174120 (estimated locally),0.07 per call) 
  Calls: mqtt_ringbuf_advance_get_idx.isra.0.part.0/64 (107374 (estimated locally),0.50 per call) 
msg_generate_packet_id.isra.0/62 (msg_generate_packet_id.isra.0) @0607a8c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: mqtt_sub_unsub/32 (84080 (estimated locally),0.23 per call) mqtt_publish/31 (56677 (estimated locally),0.16 per call) 
  Calls: 
pbuf_copy_partial/61 (pbuf_copy_partial) @0633fe00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mqtt_parse_incoming/25 (353212205 (estimated locally),5.05 per call) 
  Calls: 
pbuf_get_at/60 (pbuf_get_at) @0633fd20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mqtt_parse_incoming/25 (218286360 (estimated locally),3.12 per call) 
  Calls: 
tcp_recved/59 (tcp_recved) @0633f9a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mqtt_tcp_recv_cb.part.0/72 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pbuf_free/58 (pbuf_free) @0633f8c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mqtt_tcp_recv_cb/26 (12919 (estimated locally),0.06 per call) mqtt_tcp_recv_cb.part.0/72 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
tcp_poll/57 (tcp_poll) @0633f460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mqtt_tcp_connect_cb.part.0/71 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
sys_timeout/56 (sys_timeout) @0633f0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mqtt_tcp_connect_cb.part.0/71 (1073741824 (estimated locally),1.00 per call) mqtt_cyclic_timer/21 (82174 (estimated locally),0.23 per call) 
  Calls: 
sys_untimeout/55 (sys_untimeout) @06326460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mqtt_close/20 (250539 (estimated locally),0.70 per call) 
  Calls: 
tcp_close/54 (tcp_close) @06326380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mqtt_close/20 (133963 (estimated locally),0.37 per call) 
  Calls: 
tcp_sent/53 (tcp_sent) @06326ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mqtt_tcp_connect_cb.part.0/71 (1073741824 (estimated locally),1.00 per call) mqtt_close/20 (133963 (estimated locally),0.37 per call) 
  Calls: 
tcp_recv/52 (tcp_recv) @06326e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mqtt_tcp_connect_cb.part.0/71 (1073741824 (estimated locally),1.00 per call) mqtt_close/20 (133963 (estimated locally),0.37 per call) 
  Calls: 
tcp_abort/51 (tcp_abort) @06326b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mqtt_client_connect/36 (56750 (estimated locally),0.16 per call) mqtt_close/20 (44208 (estimated locally),0.12 per call) 
  Calls: 
tcp_err/50 (tcp_err) @06326a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mqtt_client_connect/36 (17816 (estimated locally),0.05 per call) mqtt_close/20 (133963 (estimated locally),0.37 per call) 
  Calls: 
tcp_connect/49 (tcp_connect) @063269a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mqtt_client_connect/36 (36448 (estimated locally),0.10 per call) 
  Calls: 
ip_addr_any/48 (ip_addr_any) @06337360
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: mqtt_client_connect/36 (addr)
  Availability: not_available
  Varpool flags: read-only
tcp_bind/47 (tcp_bind) @063268c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mqtt_client_connect/36 (74566 (estimated locally),0.21 per call) 
  Calls: 
tcp_arg/46 (tcp_arg) @063267e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mqtt_client_connect/36 (74566 (estimated locally),0.21 per call) 
  Calls: 
tcp_new_ip_type/45 (tcp_new_ip_type) @06326700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mqtt_client_connect/36 (75251 (estimated locally),0.21 per call) 
  Calls: 
memset/44 (memset) @06326620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mqtt_client_connect/36 (84139 (estimated locally),0.24 per call) 
  Calls: 
mem_free/43 (mem_free) @063262a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mqtt_client_free/35 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
mem_calloc/42 (mem_calloc) @063260e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mqtt_client_new/34 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
tcp_output/41 (tcp_output) @062eba80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mqtt_output_send/6 (154348240 (estimated locally),0.14 per call) 
  Calls: 
tcp_write/40 (tcp_write) @062eb9a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mqtt_output_send/6 (77174120 (estimated locally),0.07 per call) mqtt_output_send/6 (467721938 (estimated locally),0.44 per call) 
  Calls: 
strlen/39 (strlen) @062bcd20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mqtt_client_connect/36 (79323 (estimated locally),0.22 per call) mqtt_client_connect/36 (56752 (estimated locally),0.16 per call) mqtt_client_connect/36 (58006 (estimated locally),0.16 per call) mqtt_client_connect/36 (40375 (estimated locally),0.11 per call) mqtt_client_connect/36 (41228 (estimated locally),0.12 per call) mqtt_sub_unsub/32 (175378 (estimated locally),0.49 per call) mqtt_publish/31 (173554 (estimated locally),0.48 per call) 
  Calls: 
mqtt_client_is_connected/38 (mqtt_client_is_connected) @062bc700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: 
mqtt_disconnect/37 (mqtt_disconnect) @062bc380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: mqtt_close/20 (82678 (estimated locally),0.23 per call) 
mqtt_client_connect/36 (mqtt_client_connect) @062bc000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ip_addr_any/48 (addr)mqtt_tcp_connect_cb/30 (addr)mqtt_tcp_err_cb/28 (addr)
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: tcp_abort/51 (56750 (estimated locally),0.16 per call) mqtt_output_append_string/17 (5879 (estimated locally),0.02 per call) mqtt_output_append_string/17 (4543 (estimated locally),0.01 per call) mqtt_output_append_string/17 (5879 (estimated locally),0.02 per call) mqtt_output_append_string/17 (5879 (estimated locally),0.02 per call) mqtt_output_append_string/17 (17816 (estimated locally),0.05 per call) mqtt_output_append_u16/15 (17816 (estimated locally),0.05 per call) mqtt_ringbuf_put/2 (17816 (estimated locally),0.05 per call) mqtt_ringbuf_put/2 (17816 (estimated locally),0.05 per call) mqtt_output_append_string/17 (17816 (estimated locally),0.05 per call) mqtt_output_append_fixed_header.constprop/75 (17816 (estimated locally),0.05 per call) tcp_err/50 (17816 (estimated locally),0.05 per call) tcp_connect/49 (36448 (estimated locally),0.10 per call) tcp_bind/47 (74566 (estimated locally),0.21 per call) tcp_arg/46 (74566 (estimated locally),0.21 per call) tcp_new_ip_type/45 (75251 (estimated locally),0.21 per call) mqtt_output_check_space/19 (76857 (estimated locally),0.21 per call) strlen/39 (79323 (estimated locally),0.22 per call) strlen/39 (56752 (estimated locally),0.16 per call) strlen/39 (58006 (estimated locally),0.16 per call) strlen/39 (40375 (estimated locally),0.11 per call) strlen/39 (41228 (estimated locally),0.12 per call) mqtt_init_requests.constprop/76 (84139 (estimated locally),0.24 per call) memset/44 (84139 (estimated locally),0.24 per call) 
mqtt_client_free/35 (mqtt_client_free) @062b0460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: mem_free/43 (1073741824 (estimated locally),1.00 per call) 
mqtt_client_new/34 (mqtt_client_new) @062b01c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: mem_calloc/42 (1073741824 (estimated locally),1.00 per call) 
mqtt_set_inpub_callback/33 (mqtt_set_inpub_callback) @062a57e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: 
mqtt_sub_unsub/32 (mqtt_sub_unsub) @062a5ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: mqtt_output_send/6 (82881 (estimated locally),0.23 per call) mqtt_append_request/8 (82881 (estimated locally),0.23 per call) mqtt_ringbuf_put/2 (27351 (estimated locally),0.08 per call) mqtt_output_append_string/17 (82881 (estimated locally),0.23 per call) mqtt_output_append_u16/15 (82881 (estimated locally),0.23 per call) mqtt_output_append_fixed_header.constprop/75 (82881 (estimated locally),0.23 per call) mqtt_delete_request/9 (433 (estimated locally),0.00 per call) mqtt_output_check_space/19 (83314 (estimated locally),0.23 per call) mqtt_create_request.constprop/78 (84080 (estimated locally),0.23 per call) msg_generate_packet_id.isra.0/62 (84080 (estimated locally),0.23 per call) strlen/39 (175378 (estimated locally),0.49 per call) 
mqtt_publish/31 (mqtt_publish) @062a5700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: mqtt_output_send/6 (164896 (estimated locally),0.46 per call) mqtt_append_request/8 (164896 (estimated locally),0.46 per call) mqtt_output_append_buf/16 (38091 (estimated locally),0.11 per call) mqtt_output_append_u16/15 (54416 (estimated locally),0.15 per call) mqtt_output_append_string/17 (164896 (estimated locally),0.46 per call) mqtt_output_append_fixed_header.constprop/75 (164896 (estimated locally),0.46 per call) mqtt_delete_request/9 (1733 (estimated locally),0.00 per call) mqtt_output_check_space/19 (166629 (estimated locally),0.47 per call) mqtt_create_request.constprop/78 (168159 (estimated locally),0.47 per call) msg_generate_packet_id.isra.0/62 (56677 (estimated locally),0.16 per call) strlen/39 (173554 (estimated locally),0.48 per call) 
mqtt_tcp_connect_cb/30 (mqtt_tcp_connect_cb) @062a50e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: mqtt_client_connect/36 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: mqtt_tcp_connect_cb.part.0/71 (524845000 (estimated locally),0.49 per call) 
mqtt_tcp_poll_cb/29 (mqtt_tcp_poll_cb) @06297e00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: mqtt_tcp_connect_cb.part.0/71 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: mqtt_output_send/6 (217325345 (estimated locally),0.20 per call) 
mqtt_tcp_err_cb/28 (mqtt_tcp_err_cb) @06297b60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: mqtt_client_connect/36 (addr)
  Availability: available
  Function flags: count:230763 (estimated locally) body optimize_size
  Called by: 
  Calls: mqtt_tcp_err_cb.part.0/70 (123389 (estimated locally),0.53 per call) 
mqtt_tcp_sent_cb/27 (mqtt_tcp_sent_cb) @062978c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: mqtt_tcp_connect_cb.part.0/71 (addr)
  Availability: available
  Function flags: count:347387059 (estimated locally) body optimize_size
  Called by: 
  Calls: mqtt_tcp_sent_cb.part.0/69 (118111600 (estimated locally),0.34 per call) 
mqtt_tcp_recv_cb/26 (mqtt_tcp_recv_cb) @06297620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: mqtt_tcp_connect_cb.part.0/71 (addr)
  Availability: available
  Function flags: count:219131 (estimated locally) body optimize_size
  Called by: 
  Calls: mqtt_tcp_recv_cb.part.0/72 (25078 (estimated locally),0.11 per call) pbuf_free/58 (12919 (estimated locally),0.06 per call) mqtt_close/20 (8021 (estimated locally),0.04 per call) 
mqtt_parse_incoming/25 (mqtt_parse_incoming) @06297380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:69891998 (estimated locally) body local optimize_size
  Called by: mqtt_tcp_recv_cb.part.0/72 (1073741824 (estimated locally),1.00 per call) 
  Calls: mqtt_message_received/24 (197021768 (estimated locally),2.82 per call) pbuf_copy_partial/61 (353212205 (estimated locally),5.05 per call) mqtt_message_received/24 (75985482 (estimated locally),1.09 per call) pbuf_get_at/60 (218286360 (estimated locally),3.12 per call) 
mqtt_message_received/24 (mqtt_message_received) @062970e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:214748 (estimated locally) body local optimize_size
  Called by: mqtt_parse_incoming/25 (197021768 (estimated locally),2.82 per call) mqtt_parse_incoming/25 (75985482 (estimated locally),1.09 per call) 
  Calls: mqtt_delete_request/9 (6493 (estimated locally),0.03 per call) mqtt_incomming_suback/23 (1609 (estimated locally),0.01 per call) mqtt_take_request/10 (10570 (estimated locally),0.05 per call) pub_ack_rec_rel_response/22 (3054 (estimated locally),0.01 per call) pub_ack_rec_rel_response/22 (3829 (estimated locally),0.02 per call) pub_ack_rec_rel_response/22 (1219 (estimated locally),0.01 per call) 
   Indirect call(3418 (estimated locally),0.02 per call) 
   Indirect call(3414 (estimated locally),0.02 per call)  of param:0 loaded from aggregate passed by reference at offset 768 (vptr maybe changed)
   Indirect call(1458 (estimated locally),0.01 per call)  of param:0 loaded from aggregate passed by reference at offset 800 (vptr maybe changed)
   Indirect call(2851 (estimated locally),0.01 per call)  of param:0 loaded from aggregate passed by reference at offset 160 (vptr maybe changed)
mqtt_incomming_suback/23 (mqtt_incomming_suback) @06271e00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: mqtt_message_received/24 (1609 (estimated locally),0.01 per call) 
  Calls: 
   Indirect call(751619278 (estimated locally),0.70 per call)  of param:0 loaded from aggregate passed by reference at offset 32 (vptr maybe changed)
pub_ack_rec_rel_response/22 (pub_ack_rec_rel_response) @06271b60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: mqtt_message_received/24 (3054 (estimated locally),0.01 per call) mqtt_message_received/24 (3829 (estimated locally),0.02 per call) mqtt_message_received/24 (1219 (estimated locally),0.01 per call) 
  Calls: mqtt_output_send/6 (1031006900 (estimated locally),0.96 per call) mqtt_output_append_u16/15 (1031006900 (estimated locally),0.96 per call) mqtt_output_append_fixed_header.constprop/75 (1031006900 (estimated locally),0.96 per call) mqtt_output_check_space/19 (1073741824 (estimated locally),1.00 per call) 
mqtt_cyclic_timer/21 (mqtt_cyclic_timer) @062718c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: mqtt_cyclic_timer/21 (addr)
  Referring: mqtt_close/20 (addr)mqtt_cyclic_timer/21 (addr)mqtt_tcp_connect_cb.part.0/71 (addr)
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: sys_timeout/56 (82174 (estimated locally),0.23 per call) mqtt_output_append_fixed_header.constprop/75 (1822 (estimated locally),0.01 per call) mqtt_output_check_space/19 (5522 (estimated locally),0.02 per call) mqtt_close/20 (5522 (estimated locally),0.02 per call) mqtt_request_time_elapsed.constprop/77 (33468 (estimated locally),0.09 per call) mqtt_close/20 (28111 (estimated locally),0.08 per call) 
mqtt_close/20 (mqtt_close) @06271620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: mqtt_cyclic_timer/21 (addr)
  Referring: 
  Availability: local
  Function flags: count:357913 (estimated locally) body local optimize_size
  Called by: mqtt_disconnect/37 (82678 (estimated locally),0.23 per call) mqtt_tcp_recv_cb/26 (8021 (estimated locally),0.04 per call) mqtt_tcp_recv_cb.part.0/72 (354334802 (estimated locally),0.33 per call) mqtt_cyclic_timer/21 (5522 (estimated locally),0.02 per call) mqtt_cyclic_timer/21 (28111 (estimated locally),0.08 per call) mqtt_tcp_err_cb.part.0/70 (1073741824 (estimated locally),1.00 per call) 
  Calls: sys_untimeout/55 (250539 (estimated locally),0.70 per call) mqtt_clear_requests/12 (250539 (estimated locally),0.70 per call) tcp_abort/51 (44208 (estimated locally),0.12 per call) tcp_close/54 (133963 (estimated locally),0.37 per call) tcp_sent/53 (133963 (estimated locally),0.37 per call) tcp_err/50 (133963 (estimated locally),0.37 per call) tcp_recv/52 (133963 (estimated locally),0.37 per call) 
   Indirect call(87689 (estimated locally),0.25 per call)  of param:0 loaded from aggregate passed by reference at offset 160 (vptr maybe changed)
mqtt_output_check_space/19 (mqtt_output_check_space) @06271380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:357913 (estimated locally) body local optimize_size
  Called by: mqtt_client_connect/36 (76857 (estimated locally),0.21 per call) mqtt_sub_unsub/32 (83314 (estimated locally),0.23 per call) mqtt_publish/31 (166629 (estimated locally),0.47 per call) mqtt_cyclic_timer/21 (5522 (estimated locally),0.02 per call) pub_ack_rec_rel_response/22 (1073741824 (estimated locally),1.00 per call) 
  Calls: mqtt_ringbuf_len/5 (250539 (estimated locally),0.70 per call) 
mqtt_output_append_fixed_header/18 (mqtt_output_append_fixed_header) @062710e0
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:118111600 (estimated locally) body optimize_size
  Called by: 
  Calls: 
mqtt_output_append_string/17 (mqtt_output_append_string) @0626de00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:118111600 (estimated locally) body local optimize_size
  Called by: mqtt_client_connect/36 (5879 (estimated locally),0.02 per call) mqtt_client_connect/36 (4543 (estimated locally),0.01 per call) mqtt_client_connect/36 (5879 (estimated locally),0.02 per call) mqtt_client_connect/36 (5879 (estimated locally),0.02 per call) mqtt_client_connect/36 (17816 (estimated locally),0.05 per call) mqtt_client_connect/36 (17816 (estimated locally),0.05 per call) mqtt_sub_unsub/32 (82881 (estimated locally),0.23 per call) mqtt_publish/31 (164896 (estimated locally),0.46 per call) 
  Calls: mqtt_ringbuf_put/2 (955630223 (estimated locally),8.09 per call) mqtt_ringbuf_put/2 (118111600 (estimated locally),1.00 per call) mqtt_ringbuf_put/2 (118111600 (estimated locally),1.00 per call) 
mqtt_output_append_buf/16 (mqtt_output_append_buf) @0626db60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:118111600 (estimated locally) body local optimize_size
  Called by: mqtt_publish/31 (38091 (estimated locally),0.11 per call) 
  Calls: mqtt_ringbuf_put/2 (955630223 (estimated locally),8.09 per call) 
mqtt_output_append_u16/15 (mqtt_output_append_u16) @0626d8c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: mqtt_client_connect/36 (17816 (estimated locally),0.05 per call) mqtt_sub_unsub/32 (82881 (estimated locally),0.23 per call) mqtt_publish/31 (54416 (estimated locally),0.15 per call) pub_ack_rec_rel_response/22 (1031006900 (estimated locally),0.96 per call) 
  Calls: mqtt_ringbuf_put/2 (1073741824 (estimated locally),1.00 per call) mqtt_ringbuf_put/2 (1073741824 (estimated locally),1.00 per call) 
mqtt_init_requests/13 (mqtt_init_requests) @0626d380
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: 
mqtt_clear_requests/12 (mqtt_clear_requests) @0626d0e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:357913 (estimated locally) body local optimize_size
  Called by: mqtt_close/20 (250539 (estimated locally),0.70 per call) 
  Calls: mqtt_delete_request/9 (2027091 (estimated locally),5.66 per call) 
mqtt_request_time_elapsed/11 (mqtt_request_time_elapsed) @0625ce00
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: 
mqtt_take_request/10 (mqtt_take_request) @0625cb60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:357913 (estimated locally) body local optimize_size
  Called by: mqtt_message_received/24 (10570 (estimated locally),0.05 per call) mqtt_tcp_sent_cb.part.0/69 (1073741824 (estimated locally),9.09 per call) 
  Calls: 
mqtt_delete_request/9 (mqtt_delete_request) @0625c8c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: mqtt_request_time_elapsed.constprop/77 (2116828 (estimated locally),5.91 per call) mqtt_sub_unsub/32 (433 (estimated locally),0.00 per call) mqtt_publish/31 (1733 (estimated locally),0.00 per call) mqtt_message_received/24 (6493 (estimated locally),0.03 per call) mqtt_tcp_sent_cb.part.0/69 (955630223 (estimated locally),8.09 per call) mqtt_clear_requests/12 (2027091 (estimated locally),5.66 per call) 
  Calls: 
mqtt_append_request/8 (mqtt_append_request) @0625c620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:306783 (estimated locally) body local optimize_size
  Called by: mqtt_sub_unsub/32 (82881 (estimated locally),0.23 per call) mqtt_publish/31 (164896 (estimated locally),0.46 per call) 
  Calls: 
mqtt_create_request/7 (mqtt_create_request) @0625c380
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: 
mqtt_output_send/6 (mqtt_output_send) @0625c0e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741823 (estimated locally) body local optimize_size
  Called by: mqtt_sub_unsub/32 (82881 (estimated locally),0.23 per call) mqtt_publish/31 (164896 (estimated locally),0.46 per call) mqtt_tcp_connect_cb.part.0/71 (1073741824 (estimated locally),1.00 per call) pub_ack_rec_rel_response/22 (1031006900 (estimated locally),0.96 per call) mqtt_tcp_sent_cb.part.0/69 (118111601 (estimated locally),1.00 per call) mqtt_tcp_poll_cb/29 (217325345 (estimated locally),0.20 per call) 
  Calls: tcp_output/41 (154348240 (estimated locally),0.14 per call) mqtt_ringbuf_advance_get_idx.isra.0/63 (154348240 (estimated locally),0.14 per call) tcp_write/40 (77174120 (estimated locally),0.07 per call) mqtt_ringbuf_len/5 (77174120 (estimated locally),0.07 per call) mqtt_ringbuf_advance_get_idx.isra.0/63 (77174120 (estimated locally),0.07 per call) tcp_write/40 (467721938 (estimated locally),0.44 per call) mqtt_ringbuf_len/5 (1073741823 (estimated locally),1.00 per call) 
mqtt_ringbuf_len/5 (mqtt_ringbuf_len) @06254b60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: mqtt_output_send/6 (77174120 (estimated locally),0.07 per call) mqtt_output_send/6 (1073741823 (estimated locally),1.00 per call) mqtt_output_check_space/19 (250539 (estimated locally),0.70 per call) 
  Calls: 
mqtt_ringbuf_put/2 (mqtt_ringbuf_put) @06254380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: mqtt_output_append_fixed_header.constprop/75 (118111600 (estimated locally),1.00 per call) mqtt_output_append_fixed_header.constprop/75 (1073741824 (estimated locally),9.09 per call) mqtt_client_connect/36 (17816 (estimated locally),0.05 per call) mqtt_client_connect/36 (17816 (estimated locally),0.05 per call) mqtt_sub_unsub/32 (27351 (estimated locally),0.08 per call) mqtt_output_append_string/17 (955630223 (estimated locally),8.09 per call) mqtt_output_append_string/17 (118111600 (estimated locally),1.00 per call) mqtt_output_append_string/17 (118111600 (estimated locally),1.00 per call) mqtt_output_append_buf/16 (955630223 (estimated locally),8.09 per call) mqtt_output_append_u16/15 (1073741824 (estimated locally),1.00 per call) mqtt_output_append_u16/15 (1073741824 (estimated locally),1.00 per call) 
  Calls: 

;; Function mqtt_ringbuf_put (mqtt_ringbuf_put, funcdef_no=2, decl_uid=7516, cgraph_uid=3, symbol_order=2)

Modification phase of node mqtt_ringbuf_put/2
Setting nonnull for 0
mqtt_ringbuf_put (struct mqtt_ringbuf_t * rb, u8_t item)
{
  short unsigned int _1;
  int _2;
  short unsigned int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = rb_6(D)->put;
  _2 = (int) _1;
  rb_6(D)->buf[_2] = item_7(D);
  # DEBUG BEGIN_STMT
  _3 = _1 + 1;
  rb_6(D)->put = _3;
  # DEBUG BEGIN_STMT
  if (_3 > 255)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  rb_6(D)->put = 0;

  <bb 4> [local count: 1073741824]:
  return;

}



;; Function mqtt_append_request (mqtt_append_request, funcdef_no=8, decl_uid=7554, cgraph_uid=9, symbol_order=8)

Modification phase of node mqtt_append_request/8
Setting nonnull for 0
mqtt_append_request (struct mqtt_request_t * * tail, struct mqtt_request_t * r)
{
  struct mqtt_request_t * iter;
  s16_t time_before;
  struct mqtt_request_t * head;
  short unsigned int _1;
  unsigned short time_before.6_2;
  unsigned short _3;
  short unsigned int time_before.7_4;
  short unsigned int _5;

  <bb 2> [local count: 306783]:
  # DEBUG BEGIN_STMT
  # DEBUG head => 0B
  # DEBUG BEGIN_STMT
  # DEBUG time_before => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (tail_13(D) == 0B)
    goto <bb 13>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 13> [local count: 92035]:

  <bb 3> [local count: 920350130]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 15> [local count: 920350130]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 214748]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  iter_15 = *tail_13(D);
  # DEBUG iter => iter_15
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 1737507]:
  # DEBUG BEGIN_STMT
  _1 = iter_8->timeout_diff;
  time_before.6_2 = (unsigned short) time_before_7;
  _3 = _1 + time_before.6_2;
  time_before_21 = (s16_t) _3;
  # DEBUG time_before => time_before_21
  # DEBUG BEGIN_STMT
  # DEBUG head => iter_8
  # DEBUG BEGIN_STMT
  iter_23 = iter_8->next;
  # DEBUG iter => iter_23

  <bb 6> [local count: 1952255]:
  # head_6 = PHI <0B(4), iter_8(5)>
  # time_before_7 = PHI <0(4), time_before_21(5)>
  # iter_8 = PHI <iter_15(4), iter_23(5)>
  # DEBUG iter => iter_8
  # DEBUG time_before => time_before_7
  # DEBUG head => head_6
  # DEBUG BEGIN_STMT
  if (iter_8 != 0B)
    goto <bb 5>; [89.00%]
  else
    goto <bb 7>; [11.00%]

  <bb 7> [local count: 214748]:
  # head_22 = PHI <head_6(6)>
  # time_before_12 = PHI <time_before_7(6)>
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (time_before_12 > 30)
    goto <bb 14>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 14> [local count: 107374]:

  <bb 8> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 16> [local count: 1073741824]:
  goto <bb 8>; [100.00%]

  <bb 9> [local count: 107374]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  time_before.7_4 = (short unsigned int) time_before_12;
  _5 = 30 - time_before.7_4;
  r_16(D)->timeout_diff = _5;
  # DEBUG BEGIN_STMT
  if (head_22 == 0B)
    goto <bb 10>; [30.00%]
  else
    goto <bb 11>; [70.00%]

  <bb 10> [local count: 32212]:
  # DEBUG BEGIN_STMT
  *tail_13(D) = r_16(D);
  goto <bb 12>; [100.00%]

  <bb 11> [local count: 75162]:
  # DEBUG BEGIN_STMT
  head_22->next = r_16(D);

  <bb 12> [local count: 107374]:
  return;

}



;; Function mqtt_take_request (mqtt_take_request, funcdef_no=10, decl_uid=7569, cgraph_uid=11, symbol_order=10)

Modification phase of node mqtt_take_request/10
mqtt_take_request (struct mqtt_request_t * * tail, u16_t pkt_id)
{
  struct mqtt_request_t * prev;
  struct mqtt_request_t * iter;
  short unsigned int _1;
  struct mqtt_request_t * _2;
  struct mqtt_request_t * _3;
  struct mqtt_request_t * _4;
  short unsigned int _6;
  short unsigned int _7;
  short unsigned int _8;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG iter => 0B
  # DEBUG prev => 0B
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (tail_15(D) == 0B)
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
  iter_17 = *tail_15(D);
  # DEBUG iter => iter_17
  goto <bb 7>; [100.00%]

  <bb 5> [local count: 2213224]:
  # DEBUG BEGIN_STMT
  _1 = iter_9->pkt_id;
  if (_1 == pkt_id_18(D))
    goto <bb 8>; [5.50%]
  else
    goto <bb 6>; [94.50%]

  <bb 6> [local count: 2091497]:
  # DEBUG BEGIN_STMT
  # DEBUG prev => iter_9
  # DEBUG BEGIN_STMT
  iter_20 = iter_9->next;
  # DEBUG iter => iter_20

  <bb 7> [local count: 2342036]:
  # iter_9 = PHI <iter_17(4), iter_20(6)>
  # prev_10 = PHI <0B(4), iter_9(6)>
  # DEBUG prev => prev_10
  # DEBUG iter => iter_9
  # DEBUG BEGIN_STMT
  if (iter_9 != 0B)
    goto <bb 5>; [94.50%]
  else
    goto <bb 8>; [5.50%]

  <bb 8> [local count: 250539]:
  # iter_19 = PHI <iter_9(5), iter_9(7)>
  # prev_5 = PHI <prev_10(5), prev_10(7)>
  # DEBUG BEGIN_STMT
  if (iter_19 != 0B)
    goto <bb 9>; [70.00%]
  else
    goto <bb 15>; [30.00%]

  <bb 9> [local count: 175378]:
  # DEBUG BEGIN_STMT
  if (prev_5 == 0B)
    goto <bb 10>; [30.00%]
  else
    goto <bb 11>; [70.00%]

  <bb 10> [local count: 52613]:
  # DEBUG BEGIN_STMT
  _2 = iter_19->next;
  *tail_15(D) = _2;
  goto <bb 12>; [100.00%]

  <bb 11> [local count: 122764]:
  # DEBUG BEGIN_STMT
  _3 = iter_19->next;
  prev_5->next = _3;

  <bb 12> [local count: 175378]:
  # DEBUG BEGIN_STMT
  _4 = iter_19->next;
  if (_4 != 0B)
    goto <bb 13>; [70.00%]
  else
    goto <bb 14>; [30.00%]

  <bb 13> [local count: 122764]:
  # DEBUG BEGIN_STMT
  _6 = _4->timeout_diff;
  _7 = iter_19->timeout_diff;
  _8 = _6 + _7;
  _4->timeout_diff = _8;

  <bb 14> [local count: 175378]:
  # DEBUG BEGIN_STMT
  iter_19->next = 0B;

  <bb 15> [local count: 250539]:
  # DEBUG BEGIN_STMT
  return iter_19;

}



;; Function mqtt_output_append_u16 (mqtt_output_append_u16, funcdef_no=15, decl_uid=7610, cgraph_uid=16, symbol_order=15)

Modification phase of node mqtt_output_append_u16/15
Setting nonnull for 0
mqtt_output_append_u16 (struct mqtt_ringbuf_t * rb, u16_t value)
{
  short unsigned int _1;
  unsigned char _2;
  unsigned char _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = value_4(D) >> 8;
  _2 = (unsigned char) _1;
  mqtt_ringbuf_put (rb_6(D), _2);
  # DEBUG BEGIN_STMT
  _3 = (unsigned char) value_4(D);
  mqtt_ringbuf_put (rb_6(D), _3);
  return;

}



;; Function mqtt_output_append_string (mqtt_output_append_string, funcdef_no=17, decl_uid=7624, cgraph_uid=18, symbol_order=17)

Modification phase of node mqtt_output_append_string/17
Setting nonnull for 0
mqtt_output_append_string (struct mqtt_ringbuf_t * rb, const char * str, u16_t length)
{
  u16_t n;
  short unsigned int _1;
  unsigned char _2;
  unsigned char _3;
  sizetype _4;
  const char * _5;
  char _6;

  <bb 2> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = length_9(D) >> 8;
  _2 = (unsigned char) _1;
  mqtt_ringbuf_put (rb_11(D), _2);
  # DEBUG BEGIN_STMT
  _3 = (unsigned char) length_9(D);
  mqtt_ringbuf_put (rb_11(D), _3);
  # DEBUG BEGIN_STMT
  # DEBUG n => 0
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  _4 = (sizetype) n_7;
  _5 = str_14(D) + _4;
  _6 = *_5;
  mqtt_ringbuf_put (rb_11(D), _6);
  # DEBUG BEGIN_STMT
  n_16 = n_7 + 1;
  # DEBUG n => n_16

  <bb 4> [local count: 1073741824]:
  # n_7 = PHI <0(2), n_16(3)>
  # DEBUG n => n_7
  # DEBUG BEGIN_STMT
  if (n_7 < length_9(D))
    goto <bb 3>; [89.00%]
  else
    goto <bb 5>; [11.00%]

  <bb 5> [local count: 118111601]:
  return;

}



;; Function mqtt_ringbuf_advance_get_idx.isra.0 (mqtt_ringbuf_advance_get_idx.isra.0, funcdef_no=40, decl_uid=8283, cgraph_uid=63, symbol_order=63)

Modification phase of node mqtt_ringbuf_advance_get_idx.isra.0/63
Setting nonnull for 0
mqtt_ringbuf_advance_get_idx.isra.0 (u16_t * ISRA.31, u16_t len)
{
  <bb 2> [local count: 214748]:
  # DEBUG rb s=> rb
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (len_1(D) > 255)
    goto <bb 5>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 5> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 107374]:
  mqtt_ringbuf_advance_get_idx.isra.0.part.0 (ISRA.31_6(D), len_1(D));
  return;

}



;; Function mqtt_output_append_fixed_header.constprop (mqtt_output_append_fixed_header.constprop.0, funcdef_no=51, decl_uid=8384, cgraph_uid=75, symbol_order=75)

Modification phase of node mqtt_output_append_fixed_header.constprop/75
Adjusting mask for param 1 to 0xf
Setting nonnull for 0
Setting value range of param 1 [1, 12]
Setting value range of param 5 ~[1, 1]
mqtt_output_append_fixed_header.constprop (struct mqtt_ringbuf_t * rb, u8_t msg_type, u8_t fqos, u8_t fretain, u16_t r_length)
{
  u8_t fdup;
  int _2;
  int _3;
  signed char _4;
  int _5;
  int _6;
  signed char _7;
  signed char _8;
  signed char _9;
  int _11;
  int _12;
  signed char _13;
  signed char _14;
  signed char _15;
  signed char fretain.2_17;
  signed char _18;
  signed char _19;
  unsigned char _20;
  signed char _23;
  signed char _24;
  signed char iftmp.3_25;
  signed char _26;
  unsigned char _27;

  <bb 8> [local count: 118111600]:
  # DEBUG fdup => 0

  <bb 2> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  _2 = (int) msg_type_1(D);
  _3 = _2 << 4;
  _4 = (signed char) _3;
  _5 = 0;
  _6 = _5 << 3;
  _7 = (signed char) _6;
  _8 = _7 & 8;
  _9 = _4 | _8;
  _11 = (int) fqos_10(D);
  _12 = _11 << 1;
  _13 = (signed char) _12;
  _14 = _13 & 6;
  _15 = _9 | _14;
  fretain.2_17 = (signed char) fretain_16(D);
  _18 = fretain.2_17 & 1;
  _19 = _15 | _18;
  _20 = (unsigned char) _19;
  # DEBUG rb => rb_21(D)
  # DEBUG value => _20
  # DEBUG INLINE_ENTRY mqtt_output_append_u8
  # DEBUG BEGIN_STMT
  mqtt_ringbuf_put (rb_21(D), _20);

  <bb 3> [local count: 1073741824]:
  # r_length_22 = PHI <r_length_29(D)(2), r_length_28(6)>
  # DEBUG rb => NULL
  # DEBUG value => NULL
  # DEBUG r_length => r_length_22
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _23 = (signed char) r_length_22;
  _24 = _23 & 127;
  if (r_length_22 > 127)
    goto <bb 5>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 4> [local count: 536870913]:

  <bb 5> [local count: 1073741824]:
  # iftmp.3_25 = PHI <-128(3), 0(4)>
  _26 = _24 | iftmp.3_25;
  _27 = (unsigned char) _26;
  # DEBUG rb => rb_21(D)
  # DEBUG value => _27
  # DEBUG INLINE_ENTRY mqtt_output_append_u8
  # DEBUG BEGIN_STMT
  mqtt_ringbuf_put (rb_21(D), _27);
  # DEBUG rb => NULL
  # DEBUG value => NULL
  # DEBUG BEGIN_STMT
  r_length_28 = r_length_22 >> 7;
  # DEBUG r_length => r_length_28
  # DEBUG BEGIN_STMT
  if (r_length_28 != 0)
    goto <bb 6>; [89.00%]
  else
    goto <bb 7>; [11.00%]

  <bb 6> [local count: 955630223]:
  goto <bb 3>; [100.00%]

  <bb 7> [local count: 118111601]:
  return;

}



;; Function mqtt_close (mqtt_close, funcdef_no=20, decl_uid=7650, cgraph_uid=21, symbol_order=20)

Modification phase of node mqtt_close/20
mqtt_close (struct mqtt_client_t * client, mqtt_connection_status_t reason)
{
  err_t res;
  struct tcp_pcb * _1;
  struct tcp_pcb * _2;
  struct tcp_pcb * _3;
  struct tcp_pcb * _4;
  struct tcp_pcb * _5;
  struct mqtt_request_t * * _6;
  unsigned char _7;
  void (*<T643>) (struct mqtt_client_t *, void *, mqtt_connection_status_t) _8;
  void * _9;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (client_14(D) == 0B)
    goto <bb 12>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 12> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 13> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = client_14(D)->conn;
  if (_1 != 0B)
    goto <bb 5>; [53.47%]
  else
    goto <bb 8>; [46.53%]

  <bb 5> [local count: 133963]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tcp_recv (_1, 0B);
  # DEBUG BEGIN_STMT
  _2 = client_14(D)->conn;
  tcp_err (_2, 0B);
  # DEBUG BEGIN_STMT
  _3 = client_14(D)->conn;
  tcp_sent (_3, 0B);
  # DEBUG BEGIN_STMT
  _4 = client_14(D)->conn;
  res_20 = tcp_close (_4);
  # DEBUG res => res_20
  # DEBUG BEGIN_STMT
  if (res_20 != 0)
    goto <bb 6>; [33.00%]
  else
    goto <bb 7>; [67.00%]

  <bb 6> [local count: 44208]:
  # DEBUG BEGIN_STMT
  _5 = client_14(D)->conn;
  tcp_abort (_5);

  <bb 7> [local count: 133963]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  client_14(D)->conn = 0B;

  <bb 8> [local count: 250539]:
  # DEBUG BEGIN_STMT
  _6 = &client_14(D)->pend_req_queue;
  mqtt_clear_requests (_6);
  # DEBUG BEGIN_STMT
  sys_untimeout (mqtt_cyclic_timer, client_14(D));
  # DEBUG BEGIN_STMT
  _7 = client_14(D)->conn_state;
  if (_7 != 0)
    goto <bb 9>; [50.00%]
  else
    goto <bb 11>; [50.00%]

  <bb 9> [local count: 125270]:
  # DEBUG BEGIN_STMT
  client_14(D)->conn_state = 0;
  # DEBUG BEGIN_STMT
  _8 = client_14(D)->connect_cb;
  if (_8 != 0B)
    goto <bb 10>; [70.00%]
  else
    goto <bb 11>; [30.00%]

  <bb 10> [local count: 87689]:
  # DEBUG BEGIN_STMT
  _9 = client_14(D)->connect_arg;
  _8 (client_14(D), _9, reason_26(D));

  <bb 11> [local count: 250539]:
  return;

}



;; Function mqtt_tcp_err_cb (mqtt_tcp_err_cb, funcdef_no=28, decl_uid=7730, cgraph_uid=29, symbol_order=28)

Modification phase of node mqtt_tcp_err_cb/28
mqtt_tcp_err_cb (void * arg, err_t err)
{
  <bb 2> [local count: 230763]:
  # DEBUG BEGIN_STMT
  # DEBUG client => arg_2(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (arg_2(D) == 0B)
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
  # DEBUG D#7 => err_3(D)
  mqtt_tcp_err_cb.part.0 (arg_2(D));
  return;

}



;; Function mqtt_output_check_space (mqtt_output_check_space, funcdef_no=19, decl_uid=7642, cgraph_uid=20, symbol_order=19)

Modification phase of node mqtt_output_check_space/19
Setting nonnull for 0
Setting value range of param 1 ~[1, 1]
mqtt_output_check_space (struct mqtt_ringbuf_t * rb, u16_t r_length)
{
  u16_t total_len;
  int _2;
  short unsigned int _3;
  int _4;
  int _5;
  _Bool _6;
  u8_t _16;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  total_len_11 = r_length_10(D) + 1;
  # DEBUG total_len => total_len_11
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (rb_12(D) == 0B)
    goto <bb 6>; [30.00%]
  else
    goto <bb 7>; [70.00%]

  <bb 6> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 8> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 7> [local count: 250539]:

  <bb 4> [local count: 2277630]:
  # r_length_7 = PHI <r_length_10(D)(7), r_length_15(9)>
  # total_len_8 = PHI <total_len_11(7), total_len_14(9)>
  # DEBUG total_len => total_len_8
  # DEBUG r_length => r_length_7
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  total_len_14 = total_len_8 + 1;
  # DEBUG total_len => total_len_14
  # DEBUG BEGIN_STMT
  r_length_15 = r_length_7 >> 7;
  # DEBUG r_length => r_length_15
  # DEBUG BEGIN_STMT
  if (r_length_15 != 0)
    goto <bb 9>; [89.00%]
  else
    goto <bb 5>; [11.00%]

  <bb 9> [local count: 2027091]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 250539]:
  # total_len_1 = PHI <total_len_14(4)>
  # DEBUG BEGIN_STMT
  _2 = (int) total_len_1;
  _3 = mqtt_ringbuf_len (rb_12(D));
  _4 = (int) _3;
  _5 = 256 - _4;
  _6 = _2 <= _5;
  _16 = (u8_t) _6;
  return _16;

}



;; Function mqtt_cyclic_timer (mqtt_cyclic_timer, funcdef_no=21, decl_uid=7510, cgraph_uid=22, symbol_order=21)

Modification phase of node mqtt_cyclic_timer/21
mqtt_cyclic_timer (void * arg)
{
  u8_t restart_timer;
  unsigned char _1;
  short unsigned int _2;
  short unsigned int _3;
  int _4;
  int _5;
  struct mqtt_request_t * * _6;
  short unsigned int _7;
  short unsigned int _8;
  short unsigned int _9;
  int _10;
  int _11;
  int _12;
  short unsigned int _13;
  int _14;
  int _15;
  short unsigned int _16;
  int _17;
  int _18;
  short unsigned int _19;
  int _20;
  struct mqtt_ringbuf_t * _21;
  unsigned char _22;
  short unsigned int _23;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG restart_timer => 1
  # DEBUG BEGIN_STMT
  # DEBUG client => arg_29(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (arg_29(D) == 0B)
    goto <bb 21>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 21> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 22> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = MEM[(struct mqtt_client_t *)arg_29(D)].conn_state;
  if (_1 == 2)
    goto <bb 5>; [34.00%]
  else
    goto <bb 8>; [66.00%]

  <bb 5> [local count: 85183]:
  # DEBUG BEGIN_STMT
  _2 = MEM[(struct mqtt_client_t *)arg_29(D)].cyclic_tick;
  _3 = _2 + 1;
  MEM[(struct mqtt_client_t *)arg_29(D)].cyclic_tick = _3;
  # DEBUG BEGIN_STMT
  _4 = (int) _3;
  _5 = _4 * 5;
  if (_5 > 99)
    goto <bb 7>; [33.00%]
  else
    goto <bb 19>; [67.00%]

  <bb 7> [local count: 28111]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mqtt_close (arg_29(D), 257);
  # DEBUG BEGIN_STMT
  # DEBUG restart_timer => 0
  # DEBUG BEGIN_STMT
  goto <bb 20>; [100.00%]

  <bb 8> [local count: 165356]:
  # DEBUG BEGIN_STMT
  if (_1 == 3)
    goto <bb 10>; [20.24%]
  else
    goto <bb 20>; [79.76%]

  <bb 10> [local count: 33468]:
  # DEBUG BEGIN_STMT
  _6 = &MEM[(struct mqtt_client_t *)arg_29(D)].pend_req_queue;
  mqtt_request_time_elapsed (_6, 5);
  # DEBUG BEGIN_STMT
  _7 = MEM[(struct mqtt_client_t *)arg_29(D)].keep_alive;
  if (_7 != 0)
    goto <bb 12>; [50.00%]
  else
    goto <bb 19>; [50.00%]

  <bb 12> [local count: 16734]:
  # DEBUG BEGIN_STMT
  _8 = MEM[(struct mqtt_client_t *)arg_29(D)].server_watchdog;
  _9 = _8 + 1;
  MEM[(struct mqtt_client_t *)arg_29(D)].server_watchdog = _9;
  # DEBUG BEGIN_STMT
  _10 = (int) _9;
  _11 = _10 * 5;
  _12 = (int) _7;
  _13 = _7 >> 1;
  _14 = (int) _13;
  _15 = _12 + _14;
  if (_11 > _15)
    goto <bb 13>; [33.00%]
  else
    goto <bb 14>; [67.00%]

  <bb 13> [local count: 5522]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mqtt_close (arg_29(D), 257);
  # DEBUG BEGIN_STMT
  # DEBUG restart_timer => 0

  <bb 14> [local count: 16734]:
  # restart_timer_24 = PHI <1(12), 0(13)>
  # DEBUG restart_timer => restart_timer_24
  # DEBUG BEGIN_STMT
  _16 = MEM[(struct mqtt_client_t *)arg_29(D)].cyclic_tick;
  _17 = (int) _16;
  _18 = _17 * 5;
  _19 = MEM[(struct mqtt_client_t *)arg_29(D)].keep_alive;
  _20 = (int) _19;
  if (_18 >= _20)
    goto <bb 15>; [33.00%]
  else
    goto <bb 17>; [67.00%]

  <bb 15> [local count: 5522]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _21 = &MEM[(struct mqtt_client_t *)arg_29(D)].output;
  _22 = mqtt_output_check_space (_21, 0);
  if (_22 != 0)
    goto <bb 16>; [33.00%]
  else
    goto <bb 18>; [67.00%]

  <bb 16> [local count: 1822]:
  # DEBUG BEGIN_STMT
  mqtt_output_append_fixed_header (_21, 12, 0, 0, 0, 0);
  # DEBUG BEGIN_STMT
  MEM[(struct mqtt_client_t *)arg_29(D)].cyclic_tick = 0;
  goto <bb 18>; [100.00%]

  <bb 17> [local count: 11212]:
  # DEBUG BEGIN_STMT
  _23 = _16 + 1;
  MEM[(struct mqtt_client_t *)arg_29(D)].cyclic_tick = _23;

  <bb 18> [local count: 16734]:
  # DEBUG restart_timer => restart_timer_24
  # DEBUG BEGIN_STMT
  if (restart_timer_24 != 0)
    goto <bb 19>; [50.00%]
  else
    goto <bb 20>; [50.00%]

  <bb 19> [local count: 82174]:
  # DEBUG restart_timer => NULL
  # DEBUG BEGIN_STMT
  sys_timeout (5000, mqtt_cyclic_timer, arg_29(D));

  <bb 20> [local count: 250539]:
  # DEBUG restart_timer => NULL
  return;

}



;; Function mqtt_output_send (mqtt_output_send, funcdef_no=6, decl_uid=7532, cgraph_uid=7, symbol_order=6)

Modification phase of node mqtt_output_send/6
mqtt_output_send (struct mqtt_ringbuf_t * rb, struct tcp_pcb * tpcb)
{
  u16_t send_len;
  u8_t wrap;
  err_t err;
  short unsigned int _1;
  int _2;
  short unsigned int _3;
  int _4;
  int _5;
  _Bool _6;
  short unsigned int _7;
  int _8;
  short unsigned int _9;
  int _10;
  short unsigned int _11;
  int _12;
  int _13;
  u16_t iftmp.8_18;
  u8_t iftmp.9_19;
  u16_t iftmp.10_20;
  int iftmp.11_21;
  u16_t iftmp.8_26;
  u8_t * _30;
  u8_t * _34;
  u16_t iftmp.12_35;
  u16_t * _40;
  u16_t * _41;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG wrap => 0
  # DEBUG BEGIN_STMT
  _1 = mqtt_ringbuf_len (rb_25(D));
  _2 = (int) _1;
  _3 = rb_25(D)->get;
  _4 = (int) _3;
  _5 = 256 - _4;
  if (_2 < _5)
    goto <bb 4>; [50.00%]
  else
    goto <bb 3>; [50.00%]

  <bb 3> [local count: 536870911]:
  iftmp.8_26 = 256 - _3;

  <bb 4> [local count: 1073741823]:
  # iftmp.8_18 = PHI <_1(2), iftmp.8_26(3)>
  # DEBUG ringbuf_lin_len => iftmp.8_18
  # DEBUG BEGIN_STMT
  send_len_28 = tpcb_27(D)->snd_buf;
  # DEBUG send_len => send_len_28
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (send_len_28 == 0)
    goto <bb 18>; [34.00%]
  else
    goto <bb 5>; [66.00%]

  <bb 5> [local count: 708669604]:
  if (iftmp.8_18 == 0)
    goto <bb 18>; [34.00%]
  else
    goto <bb 6>; [66.00%]

  <bb 6> [local count: 467721938]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (iftmp.8_18 < send_len_28)
    goto <bb 7>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 7> [local count: 233860969]:
  # DEBUG BEGIN_STMT
  # DEBUG send_len => iftmp.8_18
  # DEBUG BEGIN_STMT
  _6 = _1 > iftmp.8_18;
  wrap_29 = (u8_t) _6;
  # DEBUG wrap => wrap_29

  <bb 8> [local count: 467721938]:
  # wrap_15 = PHI <0(6), wrap_29(7)>
  # send_len_16 = PHI <send_len_28(6), iftmp.8_18(7)>
  # DEBUG send_len => send_len_16
  # DEBUG wrap => wrap_15
  # DEBUG BEGIN_STMT
  # DEBUG rb => rb_25(D)
  # DEBUG INLINE_ENTRY mqtt_ringbuf_get_ptr
  # DEBUG BEGIN_STMT
  _34 = &rb_25(D)->buf[_4];
  # DEBUG rb => NULL
  if (wrap_15 != 0)
    goto <bb 10>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 9> [local count: 233860969]:

  <bb 10> [local count: 467721938]:
  # iftmp.9_19 = PHI <3(8), 1(9)>
  err_32 = tcp_write (tpcb_27(D), _34, send_len_16, iftmp.9_19);
  # DEBUG err => err_32
  # DEBUG BEGIN_STMT
  if (err_32 == 0)
    goto <bb 11>; [50.00%]
  else
    goto <bb 16>; [50.00%]

  <bb 11> [local count: 233860969]:
  if (wrap_15 != 0)
    goto <bb 12>; [33.00%]
  else
    goto <bb 16>; [67.00%]

  <bb 12> [local count: 77174120]:
  # DEBUG BEGIN_STMT
  _40 = &MEM[(short unsigned int *)rb_25(D) + 2B];
  # DEBUG D#2 => rb_25(D)
  mqtt_ringbuf_advance_get_idx.isra.0 (_40, send_len_16);
  # DEBUG BEGIN_STMT
  _7 = tpcb_27(D)->snd_buf;
  _8 = (int) _7;
  _9 = mqtt_ringbuf_len (rb_25(D));
  _10 = (int) _9;
  _11 = rb_25(D)->get;
  _12 = (int) _11;
  _13 = 256 - _12;
  iftmp.11_21 = MIN_EXPR <_13, _10>;
  if (_8 < iftmp.11_21)
    goto <bb 15>; [50.00%]
  else
    goto <bb 13>; [50.00%]

  <bb 13> [local count: 38587060]:
  if (_10 < _13)
    goto <bb 15>; [50.00%]
  else
    goto <bb 14>; [50.00%]

  <bb 14> [local count: 19293530]:
  iftmp.12_35 = 256 - _11;

  <bb 15> [local count: 77174120]:
  # iftmp.10_20 = PHI <_7(12), iftmp.12_35(14), _9(13)>
  # DEBUG send_len => iftmp.10_20
  # DEBUG BEGIN_STMT
  # DEBUG rb => rb_25(D)
  # DEBUG INLINE_ENTRY mqtt_ringbuf_get_ptr
  # DEBUG BEGIN_STMT
  _30 = &rb_25(D)->buf[_12];
  # DEBUG rb => NULL
  err_37 = tcp_write (tpcb_27(D), _30, iftmp.10_20, 1);
  # DEBUG err => err_37

  <bb 16> [local count: 467721938]:
  # err_14 = PHI <err_32(10), 0(11), err_37(15)>
  # send_len_17 = PHI <send_len_16(10), send_len_16(11), iftmp.10_20(15)>
  # DEBUG send_len => send_len_17
  # DEBUG err => err_14
  # DEBUG BEGIN_STMT
  if (err_14 == 0)
    goto <bb 17>; [33.00%]
  else
    goto <bb 18>; [67.00%]

  <bb 17> [local count: 154348240]:
  # DEBUG BEGIN_STMT
  _41 = &MEM[(short unsigned int *)rb_25(D) + 2B];
  # DEBUG D#2 => rb_25(D)
  mqtt_ringbuf_advance_get_idx.isra.0 (_41, send_len_17);
  # DEBUG BEGIN_STMT
  tcp_output (tpcb_27(D));

  <bb 18> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function mqtt_tcp_poll_cb (mqtt_tcp_poll_cb, funcdef_no=29, decl_uid=7736, cgraph_uid=30, symbol_order=29)

Modification phase of node mqtt_tcp_poll_cb/29
mqtt_tcp_poll_cb (void * arg, struct tcp_pcb * tpcb)
{
  unsigned char _1;
  struct mqtt_ringbuf_t * _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG client => arg_4(D)
  # DEBUG BEGIN_STMT
  _1 = MEM[(struct mqtt_client_t *)arg_4(D)].conn_state;
  if (_1 == 3)
    goto <bb 3>; [20.24%]
  else
    goto <bb 4>; [79.76%]

  <bb 3> [local count: 217325345]:
  # DEBUG BEGIN_STMT
  _2 = &MEM[(struct mqtt_client_t *)arg_4(D)].output;
  mqtt_output_send (_2, tpcb_6(D));

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function mqtt_tcp_sent_cb (mqtt_tcp_sent_cb, funcdef_no=27, decl_uid=7721, cgraph_uid=28, symbol_order=27)

Modification phase of node mqtt_tcp_sent_cb/27
mqtt_tcp_sent_cb (void * arg, struct tcp_pcb * tpcb, u16_t len)
{
  unsigned char _1;

  <bb 2> [local count: 347387059]:
  # DEBUG BEGIN_STMT
  # DEBUG client => arg_3(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = MEM[(struct mqtt_client_t *)arg_3(D)].conn_state;
  if (_1 == 3)
    goto <bb 3>; [34.00%]
  else
    goto <bb 4>; [66.00%]

  <bb 3> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  MEM[(struct mqtt_client_t *)arg_3(D)].cyclic_tick = 0;
  # DEBUG BEGIN_STMT
  MEM[(struct mqtt_client_t *)arg_3(D)].server_watchdog = 0;
  # DEBUG BEGIN_STMT
  # DEBUG D#3 => tpcb_2(D)
  # DEBUG D#4 => len_4(D)
  mqtt_tcp_sent_cb.part.0 (arg_3(D));

  <bb 4> [local count: 347387060]:
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function pub_ack_rec_rel_response (pub_ack_rec_rel_response, funcdef_no=22, decl_uid=7664, cgraph_uid=23, symbol_order=22)

Modification phase of node pub_ack_rec_rel_response/22
Adjusting mask for param 1 to 0x7
Adjusting mask for param 3 to 0x1
Setting value range of param 1 [4, 7]
Setting value range of param 3 [0, 1]
pub_ack_rec_rel_response (struct mqtt_client_t * client, u8_t msg, u16_t pkt_id, u8_t qos)
{
  err_t err;
  struct mqtt_ringbuf_t * _1;
  unsigned char _2;
  struct tcp_pcb * _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG err => 0
  # DEBUG BEGIN_STMT
  _1 = &client_6(D)->output;
  _2 = mqtt_output_check_space (_1, 2);
  if (_2 != 0)
    goto <bb 3>; [96.02%]
  else
    goto <bb 4>; [3.98%]

  <bb 3> [local count: 1031006900]:
  # DEBUG BEGIN_STMT
  mqtt_output_append_fixed_header (_1, msg_9(D), 0, qos_10(D), 0, 2);
  # DEBUG BEGIN_STMT
  mqtt_output_append_u16 (_1, pkt_id_12(D));
  # DEBUG BEGIN_STMT
  _3 = client_6(D)->conn;
  mqtt_output_send (_1, _3);

  <bb 4> [local count: 1073741824]:
  # err_4 = PHI <0(3), -1(2)>
  # DEBUG err => err_4
  # DEBUG BEGIN_STMT
  return err_4;

}



;; Function mqtt_tcp_connect_cb (mqtt_tcp_connect_cb, funcdef_no=30, decl_uid=7742, cgraph_uid=31, symbol_order=30)

Modification phase of node mqtt_tcp_connect_cb/30
mqtt_tcp_connect_cb (void * arg, struct tcp_pcb * tpcb, err_t err)
{
  err_t _1;
  signed char _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG client => arg_2(D)
  # DEBUG BEGIN_STMT
  if (err_4(D) != 0)
    goto <bb 4>; [51.12%]
  else
    goto <bb 3>; [48.88%]

  <bb 3> [local count: 524845000]:
  # DEBUG D#9 => err_4(D)
  _3 = mqtt_tcp_connect_cb.part.0 (arg_2(D), tpcb_6(D));

  <bb 4> [local count: 1073741824]:
  # _1 = PHI <err_4(D)(2), _3(3)>
  return _1;

}



;; Function mqtt_message_received (mqtt_message_received, funcdef_no=24, decl_uid=7675, cgraph_uid=25, symbol_order=24)

Modification phase of node mqtt_message_received/24
mqtt_message_received (struct mqtt_client_t * client, u8_t fixed_hdr_len, u16_t length, u32_t remaining_length)
{
  struct mqtt_request_t * r;
  u16_t topic_len;
  u8_t bkp;
  u16_t after_topic;
  u8_t * topic;
  u8_t qos;
  u16_t payload_length;
  u16_t payload_offset;
  u16_t pkt_id;
  u8_t pkt_type;
  size_t var_hdr_payload_bufsize;
  u8_t * var_hdr_payload;
  mqtt_connection_status_t res;
  u8_t[128] * _1;
  sizetype _2;
  unsigned char _3;
  long unsigned int _4;
  int _5;
  int _6;
  int _7;
  unsigned char _8;
  unsigned char _9;
  void (*<T643>) (struct mqtt_client_t *, void *, mqtt_connection_status_t) _10;
  void * _11;
  int _12;
  int _13;
  unsigned char _14;
  int _15;
  int _16;
  unsigned char _17;
  short unsigned int _18;
  unsigned char _19;
  short unsigned int _20;
  int _21;
  int _22;
  int _23;
  unsigned int _24;
  unsigned int _25;
  unsigned int _26;
  unsigned int _27;
  unsigned int _28;
  unsigned int _29;
  unsigned int _30;
  unsigned int _31;
  u8_t * _32;
  unsigned char _33;
  short unsigned int _34;
  short unsigned int _35;
  sizetype _36;
  u8_t * _37;
  unsigned char _38;
  short unsigned int _39;
  short unsigned int _40;
  u8_t * _41;
  void (*<T650>) (void *, const char *, u32_t) _42;
  void * _43;
  long unsigned int _44;
  long unsigned int _45;
  unsigned int _46;
  int _47;
  int _48;
  int _49;
  unsigned int _50;
  void (*<T64b>) (void *, const u8_t *, u16_t, u8_t) _51;
  void * _52;
  sizetype _53;
  u8_t * _54;
  _Bool _55;
  unsigned char _56;
  short unsigned int _57;
  unsigned char _58;
  short unsigned int _59;
  unsigned char _60;
  short unsigned int _61;
  struct mqtt_request_t * * _62;
  unsigned char _63;
  void (*<T655>) (void *, err_t) _64;
  void * _65;
  mqtt_connection_status_t _69;
  u16_t iftmp.21_70;
  unsigned int iftmp.22_71;
  u8_t iftmp.23_72;

  <bb 2> [local count: 214748]:
  # DEBUG BEGIN_STMT
  # DEBUG res => 0
  # DEBUG BEGIN_STMT
  _1 = &client_80(D)->rx_buffer;
  _2 = (sizetype) fixed_hdr_len_81(D);
  var_hdr_payload_82 = _1 + _2;
  # DEBUG var_hdr_payload => var_hdr_payload_82
  # DEBUG BEGIN_STMT
  var_hdr_payload_bufsize_83 = 128 - _2;
  # DEBUG var_hdr_payload_bufsize => var_hdr_payload_bufsize_83
  # DEBUG BEGIN_STMT
  _3 = client_80(D)->rx_buffer[0];
  pkt_type_85 = _3 >> 4;
  # DEBUG pkt_type => pkt_type_85
  # DEBUG BEGIN_STMT
  # DEBUG pkt_id => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _4 = client_80(D)->msg_idx;
  if (_2 > _4)
    goto <bb 65>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 65> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 66> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 107374]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _5 = (int) fixed_hdr_len_81(D);
  _6 = (int) length_86(D);
  _7 = _5 + _6;
  if (_7 > 128)
    goto <bb 64>; [21.72%]
  else
    goto <bb 5>; [78.28%]

  <bb 5> [local count: 84052]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pkt_type_85 == 2)
    goto <bb 6>; [34.00%]
  else
    goto <bb 12>; [66.00%]

  <bb 6> [local count: 28578]:
  # DEBUG BEGIN_STMT
  _8 = client_80(D)->conn_state;
  if (_8 == 2)
    goto <bb 7>; [34.00%]
  else
    goto <bb 64>; [66.00%]

  <bb 7> [local count: 9716]:
  # DEBUG BEGIN_STMT
  if (length_86(D) <= 1)
    goto <bb 8>; [16.16%]
  else
    goto <bb 9>; [83.84%]

  <bb 8> [local count: 1570]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 64>; [100.00%]

  <bb 9> [local count: 8146]:
  # DEBUG BEGIN_STMT
  _9 = MEM[(u8_t *)var_hdr_payload_82 + 1B];
  res_112 = (mqtt_connection_status_t) _9;
  # DEBUG res => res_112
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (res_112 == 0)
    goto <bb 10>; [50.00%]
  else
    goto <bb 64>; [50.00%]

  <bb 10> [local count: 4073]:
  # DEBUG BEGIN_STMT
  client_80(D)->cyclic_tick = 0;
  # DEBUG BEGIN_STMT
  client_80(D)->conn_state = 3;
  # DEBUG BEGIN_STMT
  _10 = client_80(D)->connect_cb;
  if (_10 != 0B)
    goto <bb 11>; [70.00%]
  else
    goto <bb 64>; [30.00%]

  <bb 11> [local count: 2851]:
  # DEBUG BEGIN_STMT
  _11 = client_80(D)->connect_arg;
  _10 (client_80(D), _11, 0);
  goto <bb 64>; [100.00%]

  <bb 12> [local count: 55475]:
  # DEBUG BEGIN_STMT
  if (pkt_type_85 == 13)
    goto <bb 64>; [34.00%]
  else
    goto <bb 13>; [66.00%]

  <bb 13> [local count: 36613]:
  # DEBUG BEGIN_STMT
  if (pkt_type_85 == 3)
    goto <bb 14>; [34.00%]
  else
    goto <bb 45>; [66.00%]

  <bb 14> [local count: 12448]:
  # DEBUG BEGIN_STMT
  # DEBUG payload_offset => 0
  # DEBUG BEGIN_STMT
  # DEBUG payload_length => length_86(D)
  # DEBUG BEGIN_STMT
  _12 = (int) _3;
  _13 = _12 >> 1;
  _14 = (unsigned char) _13;
  qos_96 = _14 & 3;
  # DEBUG qos => qos_96
  # DEBUG BEGIN_STMT
  if (_4 <= 128)
    goto <bb 15>; [50.00%]
  else
    goto <bb 34>; [50.00%]

  <bb 15> [local count: 6224]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (qos_96 != 0)
    goto <bb 17>; [50.00%]
  else
    goto <bb 16>; [50.00%]

  <bb 16> [local count: 3112]:

  <bb 17> [local count: 6224]:
  # iftmp.21_70 = PHI <2(15), 0(16)>
  # DEBUG qos_len => iftmp.21_70
  # DEBUG BEGIN_STMT
  _15 = (int) iftmp.21_70;
  _16 = _15 + 1;
  if (_6 <= _16)
    goto <bb 18>; [21.72%]
  else
    goto <bb 19>; [78.28%]

  <bb 18> [local count: 1352]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 64>; [100.00%]

  <bb 19> [local count: 4872]:
  # DEBUG BEGIN_STMT
  _17 = *var_hdr_payload_82;
  topic_len_97 = (u16_t) _17;
  # DEBUG topic_len => topic_len_97
  # DEBUG BEGIN_STMT
  _18 = topic_len_97 << 8;
  _19 = MEM[(u8_t *)var_hdr_payload_82 + 1B];
  _20 = (short unsigned int) _19;
  topic_len_98 = _18 + _20;
  # DEBUG topic_len => topic_len_98
  # DEBUG BEGIN_STMT
  _21 = (int) topic_len_98;
  _22 = _15 + 2;
  _23 = _6 - _22;
  if (_21 > _23)
    goto <bb 21>; [21.72%]
  else
    goto <bb 20>; [78.28%]

  <bb 20> [local count: 3814]:
  _24 = (unsigned int) topic_len_98;
  _25 = (unsigned int) iftmp.21_70;
  _26 = var_hdr_payload_bufsize_83 - _25;
  _27 = _26 + 4294967294;
  if (_24 > _27)
    goto <bb 21>; [21.72%]
  else
    goto <bb 22>; [78.28%]

  <bb 21> [local count: 1887]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 64>; [100.00%]

  <bb 22> [local count: 2986]:
  # DEBUG BEGIN_STMT
  topic_99 = var_hdr_payload_82 + 2;
  # DEBUG topic => topic_99
  # DEBUG BEGIN_STMT
  after_topic_100 = topic_len_98 + 2;
  # DEBUG after_topic => after_topic_100
  # DEBUG BEGIN_STMT
  _28 = (unsigned int) after_topic_100;
  if (qos_96 != 0)
    goto <bb 24>; [50.00%]
  else
    goto <bb 23>; [50.00%]

  <bb 23> [local count: 1493]:

  <bb 24> [local count: 2986]:
  # iftmp.22_71 = PHI <2(22), 1(23)>
  _29 = _28 + iftmp.22_71;
  if (_29 > var_hdr_payload_bufsize_83)
    goto <bb 25>; [21.72%]
  else
    goto <bb 26>; [78.28%]

  <bb 25> [local count: 648]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 64>; [100.00%]

  <bb 26> [local count: 2337]:
  # DEBUG BEGIN_STMT
  if (qos_96 != 0)
    goto <bb 27>; [50.00%]
  else
    goto <bb 30>; [50.00%]

  <bb 27> [local count: 1169]:
  # DEBUG BEGIN_STMT
  _30 = (unsigned int) length_86(D);
  _31 = _28 + 2;
  if (_30 < _31)
    goto <bb 28>; [21.72%]
  else
    goto <bb 29>; [78.28%]

  <bb 28> [local count: 254]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 64>; [100.00%]

  <bb 29> [local count: 915]:
  # DEBUG BEGIN_STMT
  _32 = var_hdr_payload_82 + _28;
  _33 = *_32;
  _34 = (short unsigned int) _33;
  _35 = _34 << 8;
  _36 = _28 + 1;
  _37 = var_hdr_payload_82 + _36;
  _38 = *_37;
  _39 = (short unsigned int) _38;
  _40 = _35 + _39;
  client_80(D)->inpub_pkt_id = _40;
  # DEBUG BEGIN_STMT
  after_topic_103 = topic_len_98 + 4;
  # DEBUG after_topic => after_topic_103
  goto <bb 31>; [100.00%]

  <bb 30> [local count: 1169]:
  # DEBUG BEGIN_STMT
  client_80(D)->inpub_pkt_id = 0;

  <bb 31> [local count: 2083]:
  # after_topic_68 = PHI <after_topic_103(29), after_topic_100(30)>
  # DEBUG after_topic => after_topic_68
  # DEBUG BEGIN_STMT
  _41 = topic_99 + _24;
  bkp_104 = *_41;
  # DEBUG bkp => bkp_104
  # DEBUG BEGIN_STMT
  *_41 = 0;
  # DEBUG BEGIN_STMT
  payload_length_106 = length_86(D) - after_topic_68;
  # DEBUG payload_length => payload_length_106
  # DEBUG BEGIN_STMT
  # DEBUG payload_offset => after_topic_68
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _42 = client_80(D)->pub_cb;
  if (_42 != 0B)
    goto <bb 32>; [70.00%]
  else
    goto <bb 33>; [30.00%]

  <bb 32> [local count: 1458]:
  # DEBUG BEGIN_STMT
  _43 = client_80(D)->inpub_arg;
  _44 = (long unsigned int) payload_length_106;
  _45 = _44 + remaining_length_107(D);
  _42 (_43, topic_99, _45);

  <bb 33> [local count: 2083]:
  # DEBUG BEGIN_STMT
  *_41 = bkp_104;

  <bb 34> [local count: 8308]:
  # payload_offset_66 = PHI <0(14), after_topic_68(33)>
  # payload_length_67 = PHI <length_86(D)(14), payload_length_106(33)>
  # DEBUG payload_length => payload_length_67
  # DEBUG payload_offset => payload_offset_66
  # DEBUG BEGIN_STMT
  if (payload_length_67 != 0)
    goto <bb 36>; [50.00%]
  else
    goto <bb 35>; [50.00%]

  <bb 35> [local count: 4154]:
  if (remaining_length_107(D) == 0)
    goto <bb 36>; [50.00%]
  else
    goto <bb 64>; [50.00%]

  <bb 36> [local count: 6231]:
  # DEBUG BEGIN_STMT
  _46 = (unsigned int) length_86(D);
  _47 = (int) payload_offset_66;
  _48 = (int) payload_length_67;
  _49 = _47 + _48;
  _50 = (unsigned int) _49;
  if (_46 < _50)
    goto <bb 37>; [21.72%]
  else
    goto <bb 38>; [78.28%]

  <bb 37> [local count: 1353]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 64>; [100.00%]

  <bb 38> [local count: 4877]:
  # DEBUG BEGIN_STMT
  _51 = client_80(D)->data_cb;
  if (_51 != 0B)
    goto <bb 39>; [70.00%]
  else
    goto <bb 40>; [30.00%]

  <bb 39> [local count: 3414]:
  # DEBUG BEGIN_STMT
  _52 = client_80(D)->inpub_arg;
  _53 = (sizetype) payload_offset_66;
  _54 = var_hdr_payload_82 + _53;
  _55 = remaining_length_107(D) == 0;
  _56 = (unsigned char) _55;
  _51 (_52, _54, payload_length_67, _56);

  <bb 40> [local count: 4877]:
  # DEBUG BEGIN_STMT
  if (remaining_length_107(D) == 0)
    goto <bb 41>; [50.00%]
  else
    goto <bb 64>; [50.00%]

  <bb 41> [local count: 2439]:
  if (qos_96 != 0)
    goto <bb 42>; [50.00%]
  else
    goto <bb 64>; [50.00%]

  <bb 42> [local count: 1219]:
  # DEBUG BEGIN_STMT
  if (qos_96 == 1)
    goto <bb 44>; [34.00%]
  else
    goto <bb 43>; [66.00%]

  <bb 43> [local count: 805]:

  <bb 44> [local count: 1219]:
  # iftmp.23_72 = PHI <4(42), 5(43)>
  # DEBUG resp_msg => iftmp.23_72
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _57 = client_80(D)->inpub_pkt_id;
  pub_ack_rec_rel_response (client_80(D), iftmp.23_72, _57, 0);
  goto <bb 64>; [100.00%]

  <bb 45> [local count: 24165]:
  # DEBUG BEGIN_STMT
  _58 = *var_hdr_payload_82;
  _59 = (short unsigned int) _58;
  pkt_id_87 = _59 << 8;
  # DEBUG pkt_id => pkt_id_87
  # DEBUG BEGIN_STMT
  _60 = MEM[(u8_t *)var_hdr_payload_82 + 1B];
  _61 = (short unsigned int) _60;
  pkt_id_88 = _61 | pkt_id_87;
  # DEBUG pkt_id => pkt_id_88
  # DEBUG BEGIN_STMT
  if (pkt_id_88 == 0)
    goto <bb 46>; [21.72%]
  else
    goto <bb 47>; [78.28%]

  <bb 46> [local count: 5249]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 64>; [100.00%]

  <bb 47> [local count: 18916]:
  # DEBUG BEGIN_STMT
  if (pkt_type_85 == 5)
    goto <bb 48>; [20.24%]
  else
    goto <bb 49>; [79.76%]

  <bb 48> [local count: 3829]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pub_ack_rec_rel_response (client_80(D), 6, pkt_id_88, 1);
  goto <bb 64>; [100.00%]

  <bb 49> [local count: 15088]:
  # DEBUG BEGIN_STMT
  if (pkt_type_85 == 6)
    goto <bb 50>; [20.24%]
  else
    goto <bb 51>; [79.76%]

  <bb 50> [local count: 3054]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pub_ack_rec_rel_response (client_80(D), 7, pkt_id_88, 0);
  goto <bb 64>; [100.00%]

  <bb 51> [local count: 12034]:
  # DEBUG BEGIN_STMT
  if (pkt_type_85 == 9)
    goto <bb 55>; [20.24%]
  else
    goto <bb 52>; [79.76%]

  <bb 52> [local count: 9598]:
  if (pkt_type_85 == 11)
    goto <bb 55>; [34.00%]
  else
    goto <bb 53>; [66.00%]

  <bb 53> [local count: 6335]:
  if (pkt_type_85 == 7)
    goto <bb 55>; [34.00%]
  else
    goto <bb 54>; [66.00%]

  <bb 54> [local count: 4181]:
  if (pkt_type_85 == 4)
    goto <bb 55>; [65.00%]
  else
    goto <bb 63>; [35.00%]

  <bb 55> [local count: 10570]:
  # DEBUG BEGIN_STMT
  _62 = &client_80(D)->pend_req_queue;
  r_90 = mqtt_take_request (_62, pkt_id_88);
  # DEBUG r => r_90
  # DEBUG BEGIN_STMT
  if (r_90 != 0B)
    goto <bb 56>; [70.00%]
  else
    goto <bb 64>; [30.00%]

  <bb 56> [local count: 7399]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pkt_type_85 == 9)
    goto <bb 57>; [34.00%]
  else
    goto <bb 60>; [66.00%]

  <bb 57> [local count: 2516]:
  # DEBUG BEGIN_STMT
  if (length_86(D) <= 2)
    goto <bb 58>; [36.03%]
  else
    goto <bb 59>; [63.97%]

  <bb 58> [local count: 906]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 64>; [100.00%]

  <bb 59> [local count: 1609]:
  # DEBUG BEGIN_STMT
  _63 = MEM[(u8_t *)var_hdr_payload_82 + 2B];
  mqtt_incomming_suback (r_90, _63);
  goto <bb 62>; [100.00%]

  <bb 60> [local count: 4884]:
  # DEBUG BEGIN_STMT
  _64 = r_90->cb;
  if (_64 != 0B)
    goto <bb 61>; [70.00%]
  else
    goto <bb 62>; [30.00%]

  <bb 61> [local count: 3418]:
  # DEBUG BEGIN_STMT
  _65 = r_90->arg;
  _64 (_65, 0);

  <bb 62> [local count: 6493]:
  # DEBUG BEGIN_STMT
  mqtt_delete_request (r_90);
  goto <bb 64>; [100.00%]

  <bb 63> [local count: 1463]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.

  <bb 64> [local count: 107374]:
  # _69 = PHI <256(4), 0(12), 256(18), 256(8), 256(63), 256(58), 256(46), 256(37), 256(28), 256(25), 256(21), 0(10), 0(55), 0(41), 0(44), 0(35), res_112(9), 0(11), 0(6), 0(62), 0(50), 0(48), 0(40)>
  # DEBUG res => NULL
  return _69;

}



;; Function mqtt_tcp_recv_cb (mqtt_tcp_recv_cb, funcdef_no=26, decl_uid=7712, cgraph_uid=27, symbol_order=26)

Modification phase of node mqtt_tcp_recv_cb/26
mqtt_tcp_recv_cb (void * arg, struct tcp_pcb * pcb, struct pbuf * p, err_t err)
{
  struct tcp_pcb * _1;
  err_t _2;
  signed char _5;

  <bb 2> [local count: 219131]:
  # DEBUG BEGIN_STMT
  # DEBUG client => arg_6(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (arg_6(D) == 0B)
    goto <bb 12>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 12> [local count: 65739]:

  <bb 3> [local count: 657392954]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 14> [local count: 657392954]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 153391]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = MEM[(struct mqtt_client_t *)arg_6(D)].conn;
  if (_1 != pcb_9(D))
    goto <bb 13>; [70.00%]
  else
    goto <bb 6>; [30.00%]

  <bb 13> [local count: 107374]:

  <bb 5> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 15> [local count: 1073741824]:
  goto <bb 5>; [100.00%]

  <bb 6> [local count: 46017]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (p_10(D) == 0B)
    goto <bb 7>; [17.43%]
  else
    goto <bb 8>; [82.57%]

  <bb 7> [local count: 8021]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mqtt_close (arg_6(D), 256);
  goto <bb 11>; [100.00%]

  <bb 8> [local count: 37997]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (err_11(D) != 0)
    goto <bb 9>; [34.00%]
  else
    goto <bb 10>; [66.00%]

  <bb 9> [local count: 12919]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pbuf_free (p_10(D));
  # DEBUG BEGIN_STMT
  goto <bb 11>; [100.00%]

  <bb 10> [local count: 25078]:
  # DEBUG D#11 => err_11(D)
  _5 = mqtt_tcp_recv_cb.part.0 (arg_6(D), pcb_9(D), p_10(D));

  <bb 11> [local count: 46017]:
  # _2 = PHI <err_11(D)(9), _5(10), 0(7)>
  return _2;

}



;; Function mqtt_publish (mqtt_publish, funcdef_no=31, decl_uid=6405, cgraph_uid=32, symbol_order=31)

Modification phase of node mqtt_publish/31
mqtt_publish (struct mqtt_client_t * client, const char * topic, const void * payload, u16_t payload_length, u8_t qos, u8_t retain, void (*mqtt_request_cb_t) (void *, err_t) cb, void * arg)
{
  u16_t remaining_length;
  u16_t topic_len;
  size_t total_len;
  size_t topic_strlen;
  u16_t pkt_id;
  struct mqtt_request_t * r;
  unsigned char _1;
  int _2;
  int _3;
  int _4;
  int _5;
  struct mqtt_request_t[4] * _6;
  struct mqtt_ringbuf_t * _7;
  unsigned char _8;
  struct mqtt_request_t * * _9;
  struct tcp_pcb * _10;
  err_t _13;
  unsigned int _28;
  u16_t * _49;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (client_20(D) == 0B)
    goto <bb 21>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 21> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 23> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (topic_22(D) == 0B)
    goto <bb 22>; [30.00%]
  else
    goto <bb 6>; [70.00%]

  <bb 22> [local count: 75162]:

  <bb 5> [local count: 751619279]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 24> [local count: 751619279]:
  goto <bb 5>; [100.00%]

  <bb 6> [local count: 175378]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = client_20(D)->conn_state;
  if (_1 == 0)
    goto <bb 20>; [1.04%]
  else
    goto <bb 7>; [98.96%]

  <bb 7> [local count: 173554]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  topic_strlen_23 = strlen (topic_22(D));
  # DEBUG topic_strlen => topic_strlen_23
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (topic_strlen_23 > 65533)
    goto <bb 20>; [1.04%]
  else
    goto <bb 8>; [98.96%]

  <bb 8> [local count: 171749]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  topic_len_24 = (u16_t) topic_strlen_23;
  # DEBUG topic_len => topic_len_24
  # DEBUG BEGIN_STMT
  _28 = topic_strlen_23;
  _2 = (int) _28;
  _3 = _2 + 2;
  _4 = (int) payload_length_25(D);
  _5 = _3 + _4;
  total_len_26 = (size_t) _5;
  # DEBUG total_len => total_len_26
  # DEBUG BEGIN_STMT
  if (qos_27(D) != 0)
    goto <bb 9>; [33.00%]
  else
    goto <bb 10>; [67.00%]

  <bb 9> [local count: 56677]:
  # DEBUG BEGIN_STMT
  total_len_29 = total_len_26 + 2;
  # DEBUG total_len => total_len_29
  # DEBUG BEGIN_STMT
  _49 = &MEM[(short unsigned int *)client_20(D) + 6B];
  # DEBUG D#1 => client_20(D)
  pkt_id_31 = msg_generate_packet_id.isra.0 (_49);
  # DEBUG pkt_id => pkt_id_31

  <bb 10> [local count: 171749]:
  # pkt_id_11 = PHI <pkt_id_31(9), 0(8)>
  # total_len_12 = PHI <total_len_29(9), total_len_26(8)>
  # DEBUG total_len => total_len_12
  # DEBUG pkt_id => pkt_id_11
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (total_len_12 > 65535)
    goto <bb 20>; [2.09%]
  else
    goto <bb 11>; [97.91%]

  <bb 11> [local count: 168159]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  remaining_length_32 = (u16_t) total_len_12;
  # DEBUG remaining_length => remaining_length_32
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _6 = &client_20(D)->req_list;
  r_36 = mqtt_create_request (_6, 4, pkt_id_11, cb_33(D), arg_34(D));
  # DEBUG r => r_36
  # DEBUG BEGIN_STMT
  if (r_36 == 0B)
    goto <bb 20>; [0.91%]
  else
    goto <bb 12>; [99.09%]

  <bb 12> [local count: 166629]:
  # DEBUG BEGIN_STMT
  _7 = &client_20(D)->output;
  _8 = mqtt_output_check_space (_7, remaining_length_32);
  if (_8 == 0)
    goto <bb 13>; [1.04%]
  else
    goto <bb 14>; [98.96%]

  <bb 13> [local count: 1733]:
  # DEBUG BEGIN_STMT
  mqtt_delete_request (r_36);
  # DEBUG BEGIN_STMT
  goto <bb 20>; [100.00%]

  <bb 14> [local count: 164896]:
  # DEBUG BEGIN_STMT
  mqtt_output_append_fixed_header (_7, 3, 0, qos_27(D), retain_38(D), remaining_length_32);
  # DEBUG BEGIN_STMT
  mqtt_output_append_string (_7, topic_22(D), topic_len_24);
  # DEBUG BEGIN_STMT
  if (qos_27(D) != 0)
    goto <bb 15>; [33.00%]
  else
    goto <bb 16>; [67.00%]

  <bb 15> [local count: 54416]:
  # DEBUG BEGIN_STMT
  mqtt_output_append_u16 (_7, pkt_id_11);

  <bb 16> [local count: 164896]:
  # DEBUG BEGIN_STMT
  if (payload_42(D) != 0B)
    goto <bb 17>; [70.00%]
  else
    goto <bb 19>; [30.00%]

  <bb 17> [local count: 115427]:
  if (payload_length_25(D) != 0)
    goto <bb 18>; [33.00%]
  else
    goto <bb 19>; [67.00%]

  <bb 18> [local count: 38091]:
  # DEBUG BEGIN_STMT
  mqtt_output_append_buf (_7, payload_42(D), payload_length_25(D));

  <bb 19> [local count: 164896]:
  # DEBUG BEGIN_STMT
  _9 = &client_20(D)->pend_req_queue;
  mqtt_append_request (_9, r_36);
  # DEBUG BEGIN_STMT
  _10 = client_20(D)->conn;
  mqtt_output_send (_7, _10);
  # DEBUG BEGIN_STMT

  <bb 20> [local count: 175378]:
  # _13 = PHI <-11(6), -16(7), -16(10), -1(11), -1(13), 0(19)>
  return _13;

}



;; Function mqtt_sub_unsub (mqtt_sub_unsub, funcdef_no=32, decl_uid=6396, cgraph_uid=33, symbol_order=32)

Modification phase of node mqtt_sub_unsub/32
mqtt_sub_unsub (struct mqtt_client_t * client, const char * topic, u8_t qos, void (*mqtt_request_cb_t) (void *, err_t) cb, void * arg, u8_t sub)
{
  struct mqtt_request_t * r;
  u16_t pkt_id;
  u16_t remaining_length;
  u16_t topic_len;
  size_t total_len;
  size_t topic_strlen;
  int _1;
  int _2;
  _Bool _3;
  int _4;
  int _5;
  unsigned char _6;
  struct mqtt_request_t[4] * _7;
  struct mqtt_ringbuf_t * _8;
  unsigned char _9;
  unsigned char _10;
  struct mqtt_request_t * * _11;
  struct tcp_pcb * _12;
  err_t _13;
  u8_t iftmp.13_14;
  unsigned int _36;
  u16_t * _46;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (client_20(D) == 0B)
    goto <bb 20>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 20> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 23> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (topic_22(D) == 0B)
    goto <bb 21>; [30.00%]
  else
    goto <bb 6>; [70.00%]

  <bb 21> [local count: 75162]:

  <bb 5> [local count: 751619279]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 24> [local count: 751619279]:
  goto <bb 5>; [100.00%]

  <bb 6> [local count: 175378]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  topic_strlen_23 = strlen (topic_22(D));
  # DEBUG topic_strlen => topic_strlen_23
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (topic_strlen_23 > 65533)
    goto <bb 19>; [1.04%]
  else
    goto <bb 7>; [98.96%]

  <bb 7> [local count: 173554]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  topic_len_24 = (u16_t) topic_strlen_23;
  # DEBUG topic_len => topic_len_24
  # DEBUG BEGIN_STMT
  _36 = topic_strlen_23;
  _1 = (int) _36;
  _2 = _1 + 4;
  _3 = sub_25(D) != 0;
  _4 = (int) _3;
  _5 = _2 + _4;
  total_len_26 = (size_t) _5;
  # DEBUG total_len => total_len_26
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (total_len_26 > 65535)
    goto <bb 19>; [1.04%]
  else
    goto <bb 8>; [98.96%]

  <bb 8> [local count: 171749]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  remaining_length_27 = (u16_t) _5;
  # DEBUG remaining_length => remaining_length_27
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (qos_28(D) > 2)
    goto <bb 22>; [50.00%]
  else
    goto <bb 10>; [50.00%]

  <bb 22> [local count: 85875]:

  <bb 9> [local count: 858744708]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 25> [local count: 858744708]:
  goto <bb 9>; [100.00%]

  <bb 10> [local count: 85874]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _6 = client_20(D)->conn_state;
  if (_6 == 0)
    goto <bb 19>; [2.09%]
  else
    goto <bb 11>; [97.91%]

  <bb 11> [local count: 84080]:
  # DEBUG BEGIN_STMT
  _46 = &MEM[(short unsigned int *)client_20(D) + 6B];
  # DEBUG D#1 => client_20(D)
  pkt_id_30 = msg_generate_packet_id.isra.0 (_46);
  # DEBUG pkt_id => pkt_id_30
  # DEBUG BEGIN_STMT
  _7 = &client_20(D)->req_list;
  r_34 = mqtt_create_request (_7, 4, pkt_id_30, cb_31(D), arg_32(D));
  # DEBUG r => r_34
  # DEBUG BEGIN_STMT
  if (r_34 == 0B)
    goto <bb 19>; [0.91%]
  else
    goto <bb 12>; [99.09%]

  <bb 12> [local count: 83314]:
  # DEBUG BEGIN_STMT
  _8 = &client_20(D)->output;
  _9 = mqtt_output_check_space (_8, remaining_length_27);
  if (_9 == 0)
    goto <bb 13>; [0.52%]
  else
    goto <bb 14>; [99.48%]

  <bb 13> [local count: 433]:
  # DEBUG BEGIN_STMT
  mqtt_delete_request (r_34);
  # DEBUG BEGIN_STMT
  goto <bb 19>; [100.00%]

  <bb 14> [local count: 82881]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (sub_25(D) != 0)
    goto <bb 16>; [50.00%]
  else
    goto <bb 15>; [50.00%]

  <bb 15> [local count: 41441]:

  <bb 16> [local count: 82881]:
  # iftmp.13_14 = PHI <8(14), 10(15)>
  mqtt_output_append_fixed_header (_8, iftmp.13_14, 0, 1, 0, remaining_length_27);
  # DEBUG BEGIN_STMT
  mqtt_output_append_u16 (_8, pkt_id_30);
  # DEBUG BEGIN_STMT
  mqtt_output_append_string (_8, topic_22(D), topic_len_24);
  # DEBUG BEGIN_STMT
  if (sub_25(D) != 0)
    goto <bb 17>; [33.00%]
  else
    goto <bb 18>; [67.00%]

  <bb 17> [local count: 27351]:
  # DEBUG BEGIN_STMT
  _10 = qos_28(D);
  # DEBUG rb => _8
  # DEBUG value => _10
  # DEBUG INLINE_ENTRY mqtt_output_append_u8
  # DEBUG BEGIN_STMT
  mqtt_ringbuf_put (_8, _10);

  <bb 18> [local count: 82881]:
  # DEBUG rb => NULL
  # DEBUG value => NULL
  # DEBUG BEGIN_STMT
  _11 = &client_20(D)->pend_req_queue;
  mqtt_append_request (_11, r_34);
  # DEBUG BEGIN_STMT
  _12 = client_20(D)->conn;
  mqtt_output_send (_8, _12);
  # DEBUG BEGIN_STMT

  <bb 19> [local count: 89503]:
  # _13 = PHI <-16(6), -16(7), -11(10), -1(11), -1(13), 0(18)>
  return _13;

}



;; Function mqtt_set_inpub_callback (mqtt_set_inpub_callback, funcdef_no=33, decl_uid=6389, cgraph_uid=34, symbol_order=33)

Modification phase of node mqtt_set_inpub_callback/33
mqtt_set_inpub_callback (struct mqtt_client_t * client, void (*mqtt_incoming_publish_cb_t) (void *, const char *, u32_t) pub_cb, void (*mqtt_incoming_data_cb_t) (void *, const u8_t *, u16_t, u8_t) data_cb, void * arg)
{
  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (client_2(D) == 0B)
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
  client_2(D)->data_cb = data_cb_4(D);
  # DEBUG BEGIN_STMT
  client_2(D)->pub_cb = pub_cb_6(D);
  # DEBUG BEGIN_STMT
  client_2(D)->inpub_arg = arg_8(D);
  return;

}



;; Function mqtt_client_new (mqtt_client_new, funcdef_no=34, decl_uid=6380, cgraph_uid=35, symbol_order=34)

Modification phase of node mqtt_client_new/34
mqtt_client_new ()
{
  struct mqtt_client_t * _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = mem_calloc (1, 496);
  return _3;

}



;; Function mqtt_client_free (mqtt_client_free, funcdef_no=35, decl_uid=6382, cgraph_uid=36, symbol_order=35)

Modification phase of node mqtt_client_free/35
mqtt_client_free (struct mqtt_client_t * client)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  mem_free (client_2(D));
  return;

}



;; Function mqtt_client_connect (mqtt_client_connect, funcdef_no=36, decl_uid=6376, cgraph_uid=37, symbol_order=36)

Modification phase of node mqtt_client_connect/36
mqtt_client_connect (struct mqtt_client_t * client, const struct ip_addr_t * ip_addr, u16_t port, void (*mqtt_connection_cb_t) (struct mqtt_client_t *, void *, mqtt_connection_status_t) cb, void * arg, const struct mqtt_connect_client_info_t * client_info)
{
  u16_t client_pass_len;
  u16_t client_user_len;
  u8_t will_msg_len;
  u8_t will_topic_len;
  u8_t flags;
  u16_t remaining_length;
  u16_t client_id_length;
  size_t len;
  err_t err;
  const char * _1;
  unsigned char _2;
  short unsigned int _3;
  struct mqtt_request_t[4] * _4;
  const char * _5;
  const char * _6;
  unsigned char _7;
  int _8;
  int _9;
  signed char _10;
  signed char _11;
  signed char _12;
  unsigned char _13;
  int _14;
  int _15;
  int _16;
  int _17;
  const char * _18;
  int _19;
  int _20;
  int _21;
  int _22;
  const char * _23;
  int _24;
  int _25;
  int _26;
  int _27;
  const char * _28;
  int _29;
  int _30;
  int _31;
  int _32;
  struct mqtt_ringbuf_t * _33;
  unsigned char _34;
  unsigned char _35;
  struct tcp_pcb * _36;
  struct tcp_pcb * _37;
  struct tcp_pcb * _38;
  struct tcp_pcb * _39;
  short unsigned int _40;
  const char * _41;
  const char * _42;
  short unsigned int _43;
  const char * _44;
  short unsigned int _45;
  signed char flags.15_46;
  const char * _47;
  const char * _48;
  struct tcp_pcb * _49;
  err_t _62;
  unsigned int _71;
  unsigned int _72;
  unsigned int _73;
  unsigned int _74;
  unsigned char _75;
  unsigned char _76;
  unsigned int _95;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG remaining_length => 10
  # DEBUG BEGIN_STMT
  # DEBUG flags => 0
  # DEBUG will_topic_len => 0
  # DEBUG will_msg_len => 0
  # DEBUG BEGIN_STMT
  # DEBUG client_user_len => 0
  # DEBUG client_pass_len => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (client_77(D) == 0B)
    goto <bb 45>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 45> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 49> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (ip_addr_79(D) == 0B)
    goto <bb 46>; [30.00%]
  else
    goto <bb 6>; [70.00%]

  <bb 46> [local count: 75162]:

  <bb 5> [local count: 751619279]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 50> [local count: 751619279]:
  goto <bb 5>; [100.00%]

  <bb 6> [local count: 175378]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (client_info_80(D) == 0B)
    goto <bb 47>; [30.00%]
  else
    goto <bb 8>; [70.00%]

  <bb 47> [local count: 52613]:

  <bb 7> [local count: 526133495]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 51> [local count: 526133495]:
  goto <bb 7>; [100.00%]

  <bb 8> [local count: 122764]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = client_info_80(D)->client_id;
  if (_1 == 0B)
    goto <bb 48>; [30.00%]
  else
    goto <bb 10>; [70.00%]

  <bb 48> [local count: 36829]:

  <bb 9> [local count: 368293446]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 52> [local count: 368293446]:
  goto <bb 9>; [100.00%]

  <bb 10> [local count: 85935]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = client_77(D)->conn_state;
  if (_2 != 0)
    goto <bb 44>; [2.09%]
  else
    goto <bb 11>; [97.91%]

  <bb 11> [local count: 84139]:
  # DEBUG BEGIN_STMT
  memset (client_77(D), 0, 496);
  # DEBUG BEGIN_STMT
  client_77(D)->connect_arg = arg_82(D);
  # DEBUG BEGIN_STMT
  client_77(D)->connect_cb = cb_84(D);
  # DEBUG BEGIN_STMT
  _3 = client_info_80(D)->keep_alive;
  client_77(D)->keep_alive = _3;
  # DEBUG BEGIN_STMT
  _4 = &client_77(D)->req_list;
  mqtt_init_requests (_4, 4);
  # DEBUG BEGIN_STMT
  _5 = client_info_80(D)->will_topic;
  if (_5 != 0B)
    goto <bb 12>; [70.00%]
  else
    goto <bb 19>; [30.00%]

  <bb 12> [local count: 58897]:
  _6 = client_info_80(D)->will_msg;
  if (_6 != 0B)
    goto <bb 13>; [70.00%]
  else
    goto <bb 19>; [30.00%]

  <bb 13> [local count: 41228]:
  # DEBUG BEGIN_STMT
  # DEBUG flags => 4
  # DEBUG BEGIN_STMT
  _7 = client_info_80(D)->will_qos;
  _8 = (int) _7;
  _9 = _8 << 3;
  _10 = (signed char) _9;
  _11 = _10 & 24;
  _12 = _11 | 4;
  flags_88 = (u8_t) _12;
  # DEBUG flags => flags_88
  # DEBUG BEGIN_STMT
  _13 = client_info_80(D)->will_retain;
  if (_13 != 0)
    goto <bb 14>; [50.00%]
  else
    goto <bb 15>; [50.00%]

  <bb 14> [local count: 20614]:
  # DEBUG BEGIN_STMT
  flags_89 = flags_88 | 32;
  # DEBUG flags => flags_89

  <bb 15> [local count: 41228]:
  # flags_54 = PHI <flags_88(13), flags_89(14)>
  # DEBUG flags => flags_54
  # DEBUG BEGIN_STMT
  len_90 = strlen (_5);
  # DEBUG len => len_90
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (len_90 > 255)
    goto <bb 44>; [1.04%]
  else
    goto <bb 16>; [98.96%]

  <bb 16> [local count: 40799]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (len_90 == 0)
    goto <bb 44>; [1.04%]
  else
    goto <bb 17>; [98.96%]

  <bb 17> [local count: 40375]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  will_topic_len_91 = (u8_t) len_90;
  # DEBUG will_topic_len => will_topic_len_91
  # DEBUG BEGIN_STMT
  len_92 = strlen (_6);
  # DEBUG len => len_92
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (len_92 > 255)
    goto <bb 44>; [1.04%]
  else
    goto <bb 18>; [98.96%]

  <bb 18> [local count: 39955]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  will_msg_len_93 = (u8_t) len_92;
  # DEBUG will_msg_len => will_msg_len_93
  # DEBUG BEGIN_STMT
  _95 = len_90;
  _14 = (int) _95;
  _15 = _14 + 14;
  _71 = len_92;
  _16 = (int) _71;
  _17 = _15 + _16;
  # DEBUG len => (size_t) _17
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  remaining_length_94 = (u16_t) _17;
  # DEBUG remaining_length => remaining_length_94

  <bb 19> [local count: 82866]:
  # remaining_length_51 = PHI <10(11), 10(12), remaining_length_94(18)>
  # flags_55 = PHI <0(11), 0(12), flags_54(18)>
  # will_topic_len_58 = PHI <0(11), 0(12), will_topic_len_91(18)>
  # will_msg_len_59 = PHI <0(11), 0(12), will_msg_len_93(18)>
  # DEBUG will_msg_len => will_msg_len_59
  # DEBUG will_topic_len => will_topic_len_58
  # DEBUG flags => flags_55
  # DEBUG remaining_length => remaining_length_51
  # DEBUG BEGIN_STMT
  _18 = client_info_80(D)->client_user;
  if (_18 != 0B)
    goto <bb 20>; [70.00%]
  else
    goto <bb 24>; [30.00%]

  <bb 20> [local count: 58006]:
  # DEBUG BEGIN_STMT
  flags_96 = flags_55 | 128;
  # DEBUG flags => flags_96
  # DEBUG BEGIN_STMT
  len_97 = strlen (_18);
  # DEBUG len => len_97
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (len_97 > 65535)
    goto <bb 44>; [1.04%]
  else
    goto <bb 21>; [98.96%]

  <bb 21> [local count: 57403]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (len_97 == 0)
    goto <bb 44>; [1.04%]
  else
    goto <bb 22>; [98.96%]

  <bb 22> [local count: 56806]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  client_user_len_98 = (u16_t) len_97;
  # DEBUG client_user_len => client_user_len_98
  # DEBUG BEGIN_STMT
  _19 = (int) remaining_length_51;
  _20 = _19 + 2;
  _72 = len_97;
  _21 = (int) _72;
  _22 = _20 + _21;
  len_99 = (size_t) _22;
  # DEBUG len => len_99
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (len_99 > 65535)
    goto <bb 44>; [1.04%]
  else
    goto <bb 23>; [98.96%]

  <bb 23> [local count: 56215]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  remaining_length_100 = (u16_t) _22;
  # DEBUG remaining_length => remaining_length_100

  <bb 24> [local count: 81075]:
  # remaining_length_52 = PHI <remaining_length_51(19), remaining_length_100(23)>
  # flags_56 = PHI <flags_55(19), flags_96(23)>
  # client_user_len_60 = PHI <0(19), client_user_len_98(23)>
  # DEBUG client_user_len => client_user_len_60
  # DEBUG flags => flags_56
  # DEBUG remaining_length => remaining_length_52
  # DEBUG BEGIN_STMT
  _23 = client_info_80(D)->client_pass;
  if (_23 != 0B)
    goto <bb 25>; [70.00%]
  else
    goto <bb 29>; [30.00%]

  <bb 25> [local count: 56752]:
  # DEBUG BEGIN_STMT
  flags_101 = flags_56 | 64;
  # DEBUG flags => flags_101
  # DEBUG BEGIN_STMT
  len_102 = strlen (_23);
  # DEBUG len => len_102
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (len_102 > 65535)
    goto <bb 44>; [1.04%]
  else
    goto <bb 26>; [98.96%]

  <bb 26> [local count: 56162]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (len_102 == 0)
    goto <bb 44>; [1.04%]
  else
    goto <bb 27>; [98.96%]

  <bb 27> [local count: 55578]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  client_pass_len_103 = (u16_t) len_102;
  # DEBUG client_pass_len => client_pass_len_103
  # DEBUG BEGIN_STMT
  _24 = (int) remaining_length_52;
  _25 = _24 + 2;
  _73 = len_102;
  _26 = (int) _73;
  _27 = _25 + _26;
  len_104 = (size_t) _27;
  # DEBUG len => len_104
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (len_104 > 65535)
    goto <bb 44>; [1.04%]
  else
    goto <bb 28>; [98.96%]

  <bb 28> [local count: 55000]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  remaining_length_105 = (u16_t) _27;
  # DEBUG remaining_length => remaining_length_105

  <bb 29> [local count: 79323]:
  # remaining_length_53 = PHI <remaining_length_52(24), remaining_length_105(28)>
  # flags_57 = PHI <flags_56(24), flags_101(28)>
  # client_pass_len_61 = PHI <0(24), client_pass_len_103(28)>
  # DEBUG client_pass_len => client_pass_len_61
  # DEBUG flags => flags_57
  # DEBUG remaining_length => remaining_length_53
  # DEBUG BEGIN_STMT
  flags_106 = flags_57 | 2;
  # DEBUG flags => flags_106
  # DEBUG BEGIN_STMT
  _28 = client_info_80(D)->client_id;
  len_107 = strlen (_28);
  # DEBUG len => len_107
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (len_107 > 65535)
    goto <bb 44>; [1.04%]
  else
    goto <bb 30>; [98.96%]

  <bb 30> [local count: 78498]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  client_id_length_108 = (u16_t) len_107;
  # DEBUG client_id_length => client_id_length_108
  # DEBUG BEGIN_STMT
  _29 = (int) remaining_length_53;
  _30 = _29 + 2;
  _74 = len_107;
  _31 = (int) _74;
  _32 = _30 + _31;
  len_109 = (size_t) _32;
  # DEBUG len => len_109
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (len_109 > 65535)
    goto <bb 44>; [2.09%]
  else
    goto <bb 31>; [97.91%]

  <bb 31> [local count: 76857]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  remaining_length_110 = (u16_t) _32;
  # DEBUG remaining_length => remaining_length_110
  # DEBUG BEGIN_STMT
  _33 = &client_77(D)->output;
  _34 = mqtt_output_check_space (_33, remaining_length_110);
  if (_34 == 0)
    goto <bb 44>; [2.09%]
  else
    goto <bb 32>; [97.91%]

  <bb 32> [local count: 75251]:
  # DEBUG BEGIN_STMT
  _35 = ip_addr_79(D)->type;
  _36 = tcp_new_ip_type (_35);
  client_77(D)->conn = _36;
  # DEBUG BEGIN_STMT
  if (_36 == 0B)
    goto <bb 44>; [0.91%]
  else
    goto <bb 33>; [99.09%]

  <bb 33> [local count: 74566]:
  # DEBUG BEGIN_STMT
  tcp_arg (_36, client_77(D));
  # DEBUG BEGIN_STMT
  _37 = client_77(D)->conn;
  err_116 = tcp_bind (_37, &ip_addr_any, 0);
  # DEBUG err => err_116
  # DEBUG BEGIN_STMT
  if (err_116 != 0)
    goto <bb 34>; [51.12%]
  else
    goto <bb 35>; [48.88%]

  <bb 34> [local count: 38118]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 43>; [100.00%]

  <bb 35> [local count: 36448]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _38 = client_77(D)->conn;
  err_119 = tcp_connect (_38, ip_addr_79(D), port_117(D), mqtt_tcp_connect_cb);
  # DEBUG err => err_119
  # DEBUG BEGIN_STMT
  if (err_119 != 0)
    goto <bb 36>; [51.12%]
  else
    goto <bb 37>; [48.88%]

  <bb 36> [local count: 18632]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 43>; [100.00%]

  <bb 37> [local count: 17816]:
  # DEBUG BEGIN_STMT
  _39 = client_77(D)->conn;
  tcp_err (_39, mqtt_tcp_err_cb);
  # DEBUG BEGIN_STMT
  client_77(D)->conn_state = 1;
  # DEBUG BEGIN_STMT
  mqtt_output_append_fixed_header (_33, 1, 0, 0, 0, remaining_length_110);
  # DEBUG BEGIN_STMT
  mqtt_output_append_string (_33, "MQTT", 4);
  # DEBUG BEGIN_STMT
  # DEBUG rb => _33
  # DEBUG value => 4
  # DEBUG INLINE_ENTRY mqtt_output_append_u8
  # DEBUG BEGIN_STMT
  mqtt_ringbuf_put (_33, 4);
  # DEBUG rb => NULL
  # DEBUG value => NULL
  # DEBUG BEGIN_STMT
  # DEBUG rb => _33
  # DEBUG value => flags_106
  # DEBUG INLINE_ENTRY mqtt_output_append_u8
  # DEBUG BEGIN_STMT
  mqtt_ringbuf_put (_33, flags_106);
  # DEBUG rb => NULL
  # DEBUG value => NULL
  # DEBUG BEGIN_STMT
  _40 = client_info_80(D)->keep_alive;
  mqtt_output_append_u16 (_33, _40);
  # DEBUG BEGIN_STMT
  _41 = client_info_80(D)->client_id;
  mqtt_output_append_string (_33, _41, client_id_length_108);
  # DEBUG BEGIN_STMT
  _75 = flags_57 & 4;
  if (_75 != 0)
    goto <bb 38>; [33.00%]
  else
    goto <bb 39>; [67.00%]

  <bb 38> [local count: 5879]:
  # DEBUG BEGIN_STMT
  _42 = client_info_80(D)->will_topic;
  _43 = (short unsigned int) will_topic_len_58;
  mqtt_output_append_string (_33, _42, _43);
  # DEBUG BEGIN_STMT
  _44 = client_info_80(D)->will_msg;
  _45 = (short unsigned int) will_msg_len_59;
  mqtt_output_append_string (_33, _44, _45);

  <bb 39> [local count: 17816]:
  # DEBUG BEGIN_STMT
  flags.15_46 = (signed char) flags_106;
  if (flags.15_46 < 0)
    goto <bb 40>; [25.50%]
  else
    goto <bb 41>; [74.50%]

  <bb 40> [local count: 4543]:
  # DEBUG BEGIN_STMT
  _47 = client_info_80(D)->client_user;
  mqtt_output_append_string (_33, _47, client_user_len_60);

  <bb 41> [local count: 17816]:
  # DEBUG BEGIN_STMT
  _76 = flags_57 & 64;
  if (_76 != 0)
    goto <bb 42>; [33.00%]
  else
    goto <bb 44>; [67.00%]

  <bb 42> [local count: 5879]:
  # DEBUG BEGIN_STMT
  _48 = client_info_80(D)->client_pass;
  mqtt_output_append_string (_33, _48, client_pass_len_61);
  goto <bb 44>; [100.00%]

  <bb 43> [local count: 56750]:
  # err_50 = PHI <err_116(34), err_119(36)>
tcp_fail:
  # DEBUG err => err_50
  # DEBUG BEGIN_STMT
  _49 = client_77(D)->conn;
  tcp_abort (_49);
  # DEBUG BEGIN_STMT
  client_77(D)->conn = 0B;
  # DEBUG BEGIN_STMT

  <bb 44> [local count: 85935]:
  # _62 = PHI <-10(10), -6(15), -6(16), -6(17), err_50(43), -6(20), -6(21), -6(22), -6(25), -6(26), -6(27), -6(29), -6(30), -1(31), -1(32), 0(42), 0(41)>
  return _62;

}



;; Function mqtt_disconnect (mqtt_disconnect, funcdef_no=37, decl_uid=6378, cgraph_uid=38, symbol_order=37)

Modification phase of node mqtt_disconnect/37
mqtt_disconnect (struct mqtt_client_t * client)
{
  unsigned char _1;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (client_4(D) == 0B)
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

  <bb 8> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = client_4(D)->conn_state;
  if (_1 != 0)
    goto <bb 5>; [33.00%]
  else
    goto <bb 6>; [67.00%]

  <bb 5> [local count: 82678]:
  # DEBUG BEGIN_STMT
  client_4(D)->conn_state = 0;
  # DEBUG BEGIN_STMT
  mqtt_close (client_4(D), 0);

  <bb 6> [local count: 250539]:
  return;

}



;; Function mqtt_client_is_connected (mqtt_client_is_connected, funcdef_no=38, decl_uid=6384, cgraph_uid=39, symbol_order=38)

Modification phase of node mqtt_client_is_connected/38
mqtt_client_is_connected (struct mqtt_client_t * client)
{
  unsigned char _1;
  _Bool _2;
  u8_t _6;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (client_4(D) == 0B)
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
  _1 = client_4(D)->conn_state;
  _2 = _1 == 3;
  _6 = (u8_t) _2;
  return _6;

}


