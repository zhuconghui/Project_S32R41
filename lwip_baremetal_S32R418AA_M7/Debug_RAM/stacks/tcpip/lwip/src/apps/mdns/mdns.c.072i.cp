
IPA constant propagation start:
Determining dynamic type for call: mdns_announce (netif_1(D), &ip6_addr_any);
  Starting walk at: mdns_announce (netif_1(D), &ip6_addr_any);
  instance pointer: netif_1(D)  Outer instance pointer: netif_1(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: mdns_announce (netif_1(D), &ip6_addr_any);
  Starting walk at: mdns_announce (netif_1(D), &ip6_addr_any);
  instance pointer: &ip6_addr_any  Outer instance pointer: ip6_addr_any offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: mdns_announce (netif_1(D), &ip_addr_any);
  Starting walk at: mdns_announce (netif_1(D), &ip_addr_any);
  instance pointer: netif_1(D)  Outer instance pointer: netif_1(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_announce (netif_1(D), &ip6_addr_any);
Determining dynamic type for call: mdns_announce (netif_1(D), &ip_addr_any);
  Starting walk at: mdns_announce (netif_1(D), &ip_addr_any);
  instance pointer: &ip_addr_any  Outer instance pointer: ip_addr_any offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: target_end_4 = mdns_readname (pbuf_3(D), _2, &target);
  Starting walk at: target_end_4 = mdns_readname (pbuf_3(D), _2, &target);
  instance pointer: pbuf_3(D)  Outer instance pointer: pbuf_3(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: target_end_4 = mdns_readname (pbuf_3(D), _2, &target);
  Starting walk at: target_end_4 = mdns_readname (pbuf_3(D), _2, &target);
  instance pointer: &target  Outer instance pointer: target offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: res_1 = mdns_build_dnssd_domain (&mydomain);
  Starting walk at: res_1 = mdns_build_dnssd_domain (&mydomain);
  instance pointer: &mydomain  Outer instance pointer: mydomain offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _4 = mdns_domain_eq (_3, &mydomain);
  Starting walk at: _4 = mdns_domain_eq (_3, &mydomain);
  instance pointer: _3  Outer instance pointer: rr_2(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_1 = mdns_build_dnssd_domain (&mydomain);
Determining dynamic type for call: _4 = mdns_domain_eq (_3, &mydomain);
  Starting walk at: _4 = mdns_domain_eq (_3, &mydomain);
  instance pointer: &mydomain  Outer instance pointer: mydomain offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_1 = mdns_build_dnssd_domain (&mydomain);
Determining dynamic type for call: res_7 = mdns_build_service_domain (&mydomain, service_6(D), 0);
  Starting walk at: res_7 = mdns_build_service_domain (&mydomain, service_6(D), 0);
  instance pointer: &mydomain  Outer instance pointer: mydomain offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_1 = mdns_build_dnssd_domain (&mydomain);
  Function call may change dynamic type:_4 = mdns_domain_eq (_3, &mydomain);
Determining dynamic type for call: res_7 = mdns_build_service_domain (&mydomain, service_6(D), 0);
  Starting walk at: res_7 = mdns_build_service_domain (&mydomain, service_6(D), 0);
  instance pointer: service_6(D)  Outer instance pointer: service_6(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_1 = mdns_build_dnssd_domain (&mydomain);
  Function call may change dynamic type:_4 = mdns_domain_eq (_3, &mydomain);
Determining dynamic type for call: _9 = mdns_domain_eq (_8, &mydomain);
  Starting walk at: _9 = mdns_domain_eq (_8, &mydomain);
  instance pointer: _8  Outer instance pointer: rr_2(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_7 = mdns_build_service_domain (&mydomain, service_6(D), 0);
  Function call may change dynamic type:res_1 = mdns_build_dnssd_domain (&mydomain);
  Function call may change dynamic type:_4 = mdns_domain_eq (_3, &mydomain);
Determining dynamic type for call: _9 = mdns_domain_eq (_8, &mydomain);
  Starting walk at: _9 = mdns_domain_eq (_8, &mydomain);
  instance pointer: &mydomain  Outer instance pointer: mydomain offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_7 = mdns_build_service_domain (&mydomain, service_6(D), 0);
  Function call may change dynamic type:res_1 = mdns_build_dnssd_domain (&mydomain);
  Function call may change dynamic type:_4 = mdns_domain_eq (_3, &mydomain);
Determining dynamic type for call: res_13 = mdns_build_service_domain (&mydomain, service_6(D), 1);
  Starting walk at: res_13 = mdns_build_service_domain (&mydomain, service_6(D), 1);
  instance pointer: &mydomain  Outer instance pointer: mydomain offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_7 = mdns_build_service_domain (&mydomain, service_6(D), 0);
  Function call may change dynamic type:res_1 = mdns_build_dnssd_domain (&mydomain);
  Function call may change dynamic type:_4 = mdns_domain_eq (_3, &mydomain);
  Function call may change dynamic type:_9 = mdns_domain_eq (_8, &mydomain);
Determining dynamic type for call: res_13 = mdns_build_service_domain (&mydomain, service_6(D), 1);
  Starting walk at: res_13 = mdns_build_service_domain (&mydomain, service_6(D), 1);
  instance pointer: service_6(D)  Outer instance pointer: service_6(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_7 = mdns_build_service_domain (&mydomain, service_6(D), 0);
  Function call may change dynamic type:res_1 = mdns_build_dnssd_domain (&mydomain);
  Function call may change dynamic type:_4 = mdns_domain_eq (_3, &mydomain);
  Function call may change dynamic type:_9 = mdns_domain_eq (_8, &mydomain);
Determining dynamic type for call: _15 = mdns_domain_eq (_14, &mydomain);
  Starting walk at: _15 = mdns_domain_eq (_14, &mydomain);
  instance pointer: _14  Outer instance pointer: rr_2(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_13 = mdns_build_service_domain (&mydomain, service_6(D), 1);
  Function call may change dynamic type:res_7 = mdns_build_service_domain (&mydomain, service_6(D), 0);
  Function call may change dynamic type:res_1 = mdns_build_dnssd_domain (&mydomain);
  Function call may change dynamic type:_4 = mdns_domain_eq (_3, &mydomain);
  Function call may change dynamic type:_9 = mdns_domain_eq (_8, &mydomain);
Determining dynamic type for call: _15 = mdns_domain_eq (_14, &mydomain);
  Starting walk at: _15 = mdns_domain_eq (_14, &mydomain);
  instance pointer: &mydomain  Outer instance pointer: mydomain offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_13 = mdns_build_service_domain (&mydomain, service_6(D), 1);
  Function call may change dynamic type:res_7 = mdns_build_service_domain (&mydomain, service_6(D), 0);
  Function call may change dynamic type:res_1 = mdns_build_dnssd_domain (&mydomain);
  Function call may change dynamic type:_4 = mdns_domain_eq (_3, &mydomain);
  Function call may change dynamic type:_9 = mdns_domain_eq (_8, &mydomain);
Determining dynamic type for call: res_21 = mdns_build_reverse_v4_domain (&mydomain, _20);
  Starting walk at: res_21 = mdns_build_reverse_v4_domain (&mydomain, _20);
  instance pointer: &mydomain  Outer instance pointer: mydomain offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_8 = mdns_build_reverse_v6_domain (&mydomain, _7);
  Function call may change dynamic type:_10 = mdns_domain_eq (_9, &mydomain);
Determining dynamic type for call: res_21 = mdns_build_reverse_v4_domain (&mydomain, _20);
  Starting walk at: res_21 = mdns_build_reverse_v4_domain (&mydomain, _20);
  instance pointer: _20  Outer instance pointer: netif_3(D) offset: 32 (bits) vtbl reference: 
  Function call may change dynamic type:res_8 = mdns_build_reverse_v6_domain (&mydomain, _7);
  Function call may change dynamic type:_10 = mdns_domain_eq (_9, &mydomain);
Determining dynamic type for call: _23 = mdns_domain_eq (_22, &mydomain);
  Starting walk at: _23 = mdns_domain_eq (_22, &mydomain);
  instance pointer: _22  Outer instance pointer: rr_1(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_21 = mdns_build_reverse_v4_domain (&mydomain, _20);
  Function call may change dynamic type:res_8 = mdns_build_reverse_v6_domain (&mydomain, _7);
  Function call may change dynamic type:_10 = mdns_domain_eq (_9, &mydomain);
Determining dynamic type for call: _23 = mdns_domain_eq (_22, &mydomain);
  Starting walk at: _23 = mdns_domain_eq (_22, &mydomain);
  instance pointer: &mydomain  Outer instance pointer: mydomain offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_21 = mdns_build_reverse_v4_domain (&mydomain, _20);
  Function call may change dynamic type:res_8 = mdns_build_reverse_v6_domain (&mydomain, _7);
  Function call may change dynamic type:_10 = mdns_domain_eq (_9, &mydomain);
Determining dynamic type for call: res_8 = mdns_build_reverse_v6_domain (&mydomain, _7);
  Starting walk at: res_8 = mdns_build_reverse_v6_domain (&mydomain, _7);
  instance pointer: &mydomain  Outer instance pointer: mydomain offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_8 = mdns_build_reverse_v6_domain (&mydomain, _7);
  Function call may change dynamic type:_10 = mdns_domain_eq (_9, &mydomain);
Determining dynamic type for call: res_8 = mdns_build_reverse_v6_domain (&mydomain, _7);
  Starting walk at: res_8 = mdns_build_reverse_v6_domain (&mydomain, _7);
  instance pointer: _7  Outer instance pointer: &netif_3(D)->ip6_addr[i_4].u_addr.ip6 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_8 = mdns_build_reverse_v6_domain (&mydomain, _7);
  Function call may change dynamic type:_10 = mdns_domain_eq (_9, &mydomain);
Determining dynamic type for call: _10 = mdns_domain_eq (_9, &mydomain);
  Starting walk at: _10 = mdns_domain_eq (_9, &mydomain);
  instance pointer: _9  Outer instance pointer: rr_1(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_8 = mdns_build_reverse_v6_domain (&mydomain, _7);
  Function call may change dynamic type:res_8 = mdns_build_reverse_v6_domain (&mydomain, _7);
  Function call may change dynamic type:_10 = mdns_domain_eq (_9, &mydomain);
Determining dynamic type for call: _10 = mdns_domain_eq (_9, &mydomain);
  Starting walk at: _10 = mdns_domain_eq (_9, &mydomain);
  instance pointer: &mydomain  Outer instance pointer: mydomain offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_8 = mdns_build_reverse_v6_domain (&mydomain, _7);
  Function call may change dynamic type:res_8 = mdns_build_reverse_v6_domain (&mydomain, _7);
  Function call may change dynamic type:_10 = mdns_domain_eq (_9, &mydomain);
Determining dynamic type for call: res_29 = mdns_build_host_domain (&mydomain, _28);
  Starting walk at: res_29 = mdns_build_host_domain (&mydomain, _28);
  instance pointer: &mydomain  Outer instance pointer: mydomain offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_8 = mdns_build_reverse_v6_domain (&mydomain, _7);
  Function call may change dynamic type:_10 = mdns_domain_eq (_9, &mydomain);
  Function call may change dynamic type:res_21 = mdns_build_reverse_v4_domain (&mydomain, _20);
  Function call may change dynamic type:_23 = mdns_domain_eq (_22, &mydomain);
Determining dynamic type for call: res_29 = mdns_build_host_domain (&mydomain, _28);
  Starting walk at: res_29 = mdns_build_host_domain (&mydomain, _28);
  instance pointer: _28  Outer instance pointer: _28 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_8 = mdns_build_reverse_v6_domain (&mydomain, _7);
  Function call may change dynamic type:_10 = mdns_domain_eq (_9, &mydomain);
  Function call may change dynamic type:res_21 = mdns_build_reverse_v4_domain (&mydomain, _20);
  Function call may change dynamic type:_23 = mdns_domain_eq (_22, &mydomain);
Determining dynamic type for call: _31 = mdns_domain_eq (_30, &mydomain);
  Starting walk at: _31 = mdns_domain_eq (_30, &mydomain);
  instance pointer: _30  Outer instance pointer: rr_1(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_29 = mdns_build_host_domain (&mydomain, _28);
  Function call may change dynamic type:res_8 = mdns_build_reverse_v6_domain (&mydomain, _7);
  Function call may change dynamic type:_10 = mdns_domain_eq (_9, &mydomain);
  Function call may change dynamic type:res_21 = mdns_build_reverse_v4_domain (&mydomain, _20);
  Function call may change dynamic type:_23 = mdns_domain_eq (_22, &mydomain);
Determining dynamic type for call: _31 = mdns_domain_eq (_30, &mydomain);
  Starting walk at: _31 = mdns_domain_eq (_30, &mydomain);
  instance pointer: &mydomain  Outer instance pointer: mydomain offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_29 = mdns_build_host_domain (&mydomain, _28);
  Function call may change dynamic type:res_8 = mdns_build_reverse_v6_domain (&mydomain, _7);
  Function call may change dynamic type:_10 = mdns_domain_eq (_9, &mydomain);
  Function call may change dynamic type:res_21 = mdns_build_reverse_v4_domain (&mydomain, _20);
  Function call may change dynamic type:_23 = mdns_domain_eq (_22, &mydomain);
Determining dynamic type for call: res_5 = mdns_domain_add_label (domain_4(D), _1, _3);
  Starting walk at: res_5 = mdns_domain_add_label (domain_4(D), _1, _3);
  instance pointer: domain_4(D)  Outer instance pointer: domain_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: res_5 = mdns_domain_add_label (domain_4(D), _1, _3);
  Starting walk at: res_5 = mdns_domain_add_label (domain_4(D), _1, _3);
  instance pointer: _1  Outer instance pointer: _1 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _6 = mdns_add_dotlocal (domain_4(D));
  Starting walk at: _6 = mdns_add_dotlocal (domain_4(D));
  instance pointer: domain_4(D)  Outer instance pointer: domain_4(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_5 = mdns_domain_add_label (domain_4(D), _1, _3);
Determining dynamic type for call: res_2 = mdns_domain_add_label (domain_1(D), "ip6", 3);
  Starting walk at: res_2 = mdns_domain_add_label (domain_1(D), "ip6", 3);
  instance pointer: domain_1(D)  Outer instance pointer: domain_1(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: res_2 = mdns_domain_add_label (domain_1(D), "ip6", 3);
  Starting walk at: res_2 = mdns_domain_add_label (domain_1(D), "ip6", 3);
  instance pointer: "ip6"  Outer instance pointer: "ip6" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: res_3 = mdns_domain_add_label (domain_1(D), "arpa", 4);
  Starting walk at: res_3 = mdns_domain_add_label (domain_1(D), "arpa", 4);
  instance pointer: domain_1(D)  Outer instance pointer: domain_1(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_2 = mdns_domain_add_label (domain_1(D), "ip6", 3);
Determining dynamic type for call: res_3 = mdns_domain_add_label (domain_1(D), "arpa", 4);
  Starting walk at: res_3 = mdns_domain_add_label (domain_1(D), "arpa", 4);
  instance pointer: "arpa"  Outer instance pointer: "arpa" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: res_4 = mdns_domain_add_label (domain_1(D), 0B, 0);
  Starting walk at: res_4 = mdns_domain_add_label (domain_1(D), 0B, 0);
  instance pointer: domain_1(D)  Outer instance pointer: domain_1(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_3 = mdns_domain_add_label (domain_1(D), "arpa", 4);
  Function call may change dynamic type:res_2 = mdns_domain_add_label (domain_1(D), "ip6", 3);
Determining dynamic type for call: res_4 = mdns_domain_add_label (domain_1(D), 0B, 0);
  Starting walk at: res_4 = mdns_domain_add_label (domain_1(D), 0B, 0);
  instance pointer: 0B  Outer instance pointer: 0B offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_3 = mdns_domain_add_label (domain_1(D), "arpa", 4);
  Function call may change dynamic type:res_2 = mdns_domain_add_label (domain_1(D), "ip6", 3);
Determining dynamic type for call: res_2 = mdns_domain_add_label (domain_1(D), "arpa", 4);
  Starting walk at: res_2 = mdns_domain_add_label (domain_1(D), "arpa", 4);
  instance pointer: domain_1(D)  Outer instance pointer: domain_1(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: res_2 = mdns_domain_add_label (domain_1(D), "arpa", 4);
  Starting walk at: res_2 = mdns_domain_add_label (domain_1(D), "arpa", 4);
  instance pointer: "arpa"  Outer instance pointer: "arpa" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: res_3 = mdns_domain_add_label (domain_1(D), 0B, 0);
  Starting walk at: res_3 = mdns_domain_add_label (domain_1(D), 0B, 0);
  instance pointer: domain_1(D)  Outer instance pointer: domain_1(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_2 = mdns_domain_add_label (domain_1(D), "arpa", 4);
Determining dynamic type for call: res_3 = mdns_domain_add_label (domain_1(D), 0B, 0);
  Starting walk at: res_3 = mdns_domain_add_label (domain_1(D), 0B, 0);
  instance pointer: 0B  Outer instance pointer: 0B offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_2 = mdns_domain_add_label (domain_1(D), "arpa", 4);
Determining dynamic type for call: res_8 = mdns_domain_add_label (domain_7(D), _4, _6);
  Starting walk at: res_8 = mdns_domain_add_label (domain_7(D), _4, _6);
  instance pointer: domain_7(D)  Outer instance pointer: domain_7(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: res_8 = mdns_domain_add_label (domain_7(D), _4, _6);
  Starting walk at: res_8 = mdns_domain_add_label (domain_7(D), _4, _6);
  instance pointer: _4  Outer instance pointer: _4 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _9 = mdns_add_dotlocal (domain_7(D));
  Starting walk at: _9 = mdns_add_dotlocal (domain_7(D));
  instance pointer: domain_7(D)  Outer instance pointer: domain_7(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_8 = mdns_domain_add_label (domain_7(D), _4, _6);
Determining dynamic type for call: _2 = mdns_domain_add_label (domain_1(D), 0B, 0);
  Starting walk at: _2 = mdns_domain_add_label (domain_1(D), 0B, 0);
  instance pointer: domain_1(D)  Outer instance pointer: domain_1(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _2 = mdns_domain_add_label (domain_1(D), 0B, 0);
  Starting walk at: _2 = mdns_domain_add_label (domain_1(D), 0B, 0);
  instance pointer: 0B  Outer instance pointer: 0B offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: mdns_resp_announce.part.0 (netif_5(D));
  Starting walk at: mdns_resp_announce.part.0 (netif_5(D));
  instance pointer: netif_5(D)  Outer instance pointer: netif_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _8 = mdns_domain_add_label (_1, txt_5(D), txt_len_6(D));
  Starting walk at: _8 = mdns_domain_add_label (_1, txt_5(D), txt_len_6(D));
  instance pointer: _1  Outer instance pointer: service_3(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _8 = mdns_domain_add_label (_1, txt_5(D), txt_len_6(D));
  Starting walk at: _8 = mdns_domain_add_label (_1, txt_5(D), txt_len_6(D));
  instance pointer: txt_5(D)  Outer instance pointer: txt_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: mdns_resp_restart (netif_12(D));
  Starting walk at: mdns_resp_restart (netif_12(D));
  instance pointer: netif_12(D)  Outer instance pointer: netif_12(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:memcpy (_4, name_10(D), _5);
Determining dynamic type for call: mdns_resp_restart (netif_18(D));
  Starting walk at: mdns_resp_restart (netif_18(D));
  instance pointer: netif_18(D)  Outer instance pointer: netif_18(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:memcpy (_10, service_22(D), iftmp.43_5);
  Function call may change dynamic type:memcpy (_8, name_21(D), iftmp.42_7);
  Function call may change dynamic type:srv_25 = mem_calloc (1, 404);
Determining dynamic type for call: mdns_resp_restart (netif_10(D));
  Starting walk at: mdns_resp_restart (netif_10(D));
  instance pointer: netif_10(D)  Outer instance pointer: netif_10(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:memcpy (_3, hostname_8(D), _4);
Determining dynamic type for call: mdns_resp_restart (netif_16(D));
  Starting walk at: mdns_resp_restart (netif_16(D));
  instance pointer: netif_16(D)  Outer instance pointer: netif_16(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_31 = mld6_joingroup_netif (netif_16(D), &v6group.u_addr.ip6);
  Function call may change dynamic type:res_29 = igmp_joingroup_netif (netif_16(D), &v4group.u_addr.ip4);
  Function call may change dynamic type:memcpy (_7, hostname_18(D), iftmp.4_22);
  Function call may change dynamic type:mdns_20 = mem_calloc (1, 76);
Determining dynamic type for call: _8 = mdns_send_probe (arg_13(D), &ip_addr_any);
  Starting walk at: _8 = mdns_send_probe (arg_13(D), &ip_addr_any);
  instance pointer: arg_13(D)  Outer instance pointer: arg_13(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _8 = mdns_send_probe (arg_13(D), &ip_addr_any);
  Starting walk at: _8 = mdns_send_probe (arg_13(D), &ip_addr_any);
  instance pointer: &ip_addr_any  Outer instance pointer: ip_addr_any offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _9 = mdns_send_probe (arg_13(D), &ip6_addr_any);
  Starting walk at: _9 = mdns_send_probe (arg_13(D), &ip6_addr_any);
  instance pointer: arg_13(D)  Outer instance pointer: arg_13(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_8 = mdns_send_probe (arg_13(D), &ip_addr_any);
Determining dynamic type for call: _9 = mdns_send_probe (arg_13(D), &ip6_addr_any);
  Starting walk at: _9 = mdns_send_probe (arg_13(D), &ip6_addr_any);
  instance pointer: &ip6_addr_any  Outer instance pointer: ip6_addr_any offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: mdns_probe.part.0 (arg_13(D));
  Starting walk at: mdns_probe.part.0 (arg_13(D));
  instance pointer: arg_13(D)  Outer instance pointer: arg_13(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_8 = mdns_send_probe (arg_13(D), &ip_addr_any);
  Function call may change dynamic type:_9 = mdns_send_probe (arg_13(D), &ip6_addr_any);
Determining dynamic type for call: mdns_resp_announce (arg_13(D));
  Starting walk at: mdns_resp_announce (arg_13(D));
  instance pointer: arg_13(D)  Outer instance pointer: arg_13(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: mdns_name_result_cb.9_4 (arg_13(D), 1);
  Starting walk at: mdns_name_result_cb.9_4 (arg_13(D), 1);
  instance pointer: arg_13(D)  Outer instance pointer: arg_13(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_resp_announce (arg_13(D));
Determining dynamic type for call: mdns_build_host_domain (&domain, mdns_31);
  Starting walk at: mdns_build_host_domain (&domain, mdns_31);
  instance pointer: &domain  Outer instance pointer: domain offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: mdns_build_host_domain (&domain, mdns_31);
  Starting walk at: mdns_build_host_domain (&domain, mdns_31);
  instance pointer: mdns_31  Outer instance pointer: mdns_31 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:memset (&MEM[(void *)&pkt + 4B], 0, 68);
Determining dynamic type for call: res_36 = mdns_add_question (&pkt, &domain, 255, 1, 1);
  Starting walk at: res_36 = mdns_add_question (&pkt, &domain, 255, 1, 1);
  instance pointer: &pkt  Outer instance pointer: pkt offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_build_host_domain (&domain, mdns_31);
Determining dynamic type for call: res_36 = mdns_add_question (&pkt, &domain, 255, 1, 1);
  Starting walk at: res_36 = mdns_add_question (&pkt, &domain, 255, 1, 1);
  instance pointer: &domain  Outer instance pointer: domain offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_build_host_domain (&domain, mdns_31);
Determining dynamic type for call: res_44 = mdns_send_outpacket (&pkt, 0);
  Starting walk at: res_44 = mdns_send_outpacket (&pkt, 0);
  instance pointer: &pkt  Outer instance pointer: pkt offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_53 = mdns_add_question (&pkt, &domain, 255, 1, 1);
  Function call may change dynamic type:mdns_build_service_domain (&domain, service_50, 1);
  Function call may change dynamic type:res_36 = mdns_add_question (&pkt, &domain, 255, 1, 1);
  Function call may change dynamic type:mdns_build_host_domain (&domain, mdns_31);
Determining dynamic type for call: mdns_build_service_domain (&domain, service_50, 1);
  Starting walk at: mdns_build_service_domain (&domain, service_50, 1);
  instance pointer: &domain  Outer instance pointer: domain offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_36 = mdns_add_question (&pkt, &domain, 255, 1, 1);
  Function call may change dynamic type:mdns_build_host_domain (&domain, mdns_31);
  Function call may change dynamic type:res_53 = mdns_add_question (&pkt, &domain, 255, 1, 1);
  Function call may change dynamic type:mdns_build_service_domain (&domain, service_50, 1);
Determining dynamic type for call: mdns_build_service_domain (&domain, service_50, 1);
  Starting walk at: mdns_build_service_domain (&domain, service_50, 1);
  instance pointer: service_50  Outer instance pointer: service_50 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_36 = mdns_add_question (&pkt, &domain, 255, 1, 1);
  Function call may change dynamic type:mdns_build_host_domain (&domain, mdns_31);
  Function call may change dynamic type:memset (&MEM[(void *)&pkt + 4B], 0, 68);
  Function call may change dynamic type:res_53 = mdns_add_question (&pkt, &domain, 255, 1, 1);
  Function call may change dynamic type:mdns_build_service_domain (&domain, service_50, 1);
Determining dynamic type for call: res_53 = mdns_add_question (&pkt, &domain, 255, 1, 1);
  Starting walk at: res_53 = mdns_add_question (&pkt, &domain, 255, 1, 1);
  instance pointer: &pkt  Outer instance pointer: pkt offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_build_service_domain (&domain, service_50, 1);
  Function call may change dynamic type:res_36 = mdns_add_question (&pkt, &domain, 255, 1, 1);
  Function call may change dynamic type:mdns_build_host_domain (&domain, mdns_31);
  Function call may change dynamic type:res_53 = mdns_add_question (&pkt, &domain, 255, 1, 1);
  Function call may change dynamic type:mdns_build_service_domain (&domain, service_50, 1);
Determining dynamic type for call: res_53 = mdns_add_question (&pkt, &domain, 255, 1, 1);
  Starting walk at: res_53 = mdns_add_question (&pkt, &domain, 255, 1, 1);
  instance pointer: &domain  Outer instance pointer: domain offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_build_service_domain (&domain, service_50, 1);
  Function call may change dynamic type:res_36 = mdns_add_question (&pkt, &domain, 255, 1, 1);
  Function call may change dynamic type:mdns_build_host_domain (&domain, mdns_31);
  Function call may change dynamic type:res_53 = mdns_add_question (&pkt, &domain, 255, 1, 1);
  Function call may change dynamic type:mdns_build_service_domain (&domain, service_50, 1);
Determining dynamic type for call: mdns_handle_question (&packet);
  Starting walk at: mdns_handle_question (&packet);
  instance pointer: &packet  Outer instance pointer: packet offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_17 = lwip_htons (_16);
  Function call may change dynamic type:_14 = lwip_htons (_13);
  Function call may change dynamic type:_12 = lwip_htons (_11);
  Function call may change dynamic type:_10 = lwip_htons (_9);
  Function call may change dynamic type:_8 = lwip_htons (_7);
  Function call may change dynamic type:memcpy (&packet.source_addr, addr_37(D), 24);
  Function call may change dynamic type:_4 = pbuf_copy_partial (p_34(D), &hdr, 12, 0);
Determining dynamic type for call: mdns_handle_response (&packet);
  Starting walk at: mdns_handle_response (&packet);
  instance pointer: &packet  Outer instance pointer: packet offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_17 = lwip_htons (_16);
  Function call may change dynamic type:_14 = lwip_htons (_13);
  Function call may change dynamic type:_12 = lwip_htons (_11);
  Function call may change dynamic type:_10 = lwip_htons (_9);
  Function call may change dynamic type:_8 = lwip_htons (_7);
  Function call may change dynamic type:memcpy (&packet.source_addr, addr_37(D), 24);
  Function call may change dynamic type:_4 = pbuf_copy_partial (p_34(D), &hdr, 12, 0);
Determining dynamic type for call: res_31 = mdns_read_answer (pkt_28(D), &ans);
  Starting walk at: res_31 = mdns_read_answer (pkt_28(D), &ans);
  instance pointer: pkt_28(D)  Outer instance pointer: pkt_28(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_31 = mdns_read_answer (pkt_28(D), &ans);
  Function call may change dynamic type:res_46 = mdns_read_question (pkt_28(D), &q);
  Function call may change dynamic type:res_33 = mdns_build_host_domain (&domain, mdns_29);
  Function call may change dynamic type:_7 = mdns_domain_eq (&ans.info.domain, &domain);
  Function call may change dynamic type:_9 = mdns_domain_eq (&ans.info.domain, &domain);
  Function call may change dynamic type:res_40 = mdns_build_service_domain (&domain, service_38, 1);
  Function call may change dynamic type:sys_untimeout (mdns_probe, _10);
  Function call may change dynamic type:mdns_name_result_cb.62_11 (_13, 0);
Determining dynamic type for call: res_31 = mdns_read_answer (pkt_28(D), &ans);
  Starting walk at: res_31 = mdns_read_answer (pkt_28(D), &ans);
  instance pointer: &ans  Outer instance pointer: ans offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_31 = mdns_read_answer (pkt_28(D), &ans);
  Function call may change dynamic type:res_46 = mdns_read_question (pkt_28(D), &q);
  Function call may change dynamic type:res_33 = mdns_build_host_domain (&domain, mdns_29);
  Function call may change dynamic type:_7 = mdns_domain_eq (&ans.info.domain, &domain);
  Function call may change dynamic type:_9 = mdns_domain_eq (&ans.info.domain, &domain);
  Function call may change dynamic type:res_40 = mdns_build_service_domain (&domain, service_38, 1);
  Function call may change dynamic type:sys_untimeout (mdns_probe, _10);
  Function call may change dynamic type:mdns_name_result_cb.62_11 (_13, 0);
Determining dynamic type for call: mdns_domain_debug_print (&ans.info.domain);
  Starting walk at: mdns_domain_debug_print (&ans.info.domain);
  instance pointer: &ans.info.domain  Outer instance pointer: ans offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_31 = mdns_read_answer (pkt_28(D), &ans);
  Function call may change dynamic type:res_31 = mdns_read_answer (pkt_28(D), &ans);
  Function call may change dynamic type:res_46 = mdns_read_question (pkt_28(D), &q);
  Function call may change dynamic type:res_33 = mdns_build_host_domain (&domain, mdns_29);
  Function call may change dynamic type:_7 = mdns_domain_eq (&ans.info.domain, &domain);
  Function call may change dynamic type:_9 = mdns_domain_eq (&ans.info.domain, &domain);
  Function call may change dynamic type:res_40 = mdns_build_service_domain (&domain, service_38, 1);
  Function call may change dynamic type:sys_untimeout (mdns_probe, _10);
  Function call may change dynamic type:mdns_name_result_cb.62_11 (_13, 0);
Determining dynamic type for call: res_33 = mdns_build_host_domain (&domain, mdns_29);
  Starting walk at: res_33 = mdns_build_host_domain (&domain, mdns_29);
  instance pointer: &domain  Outer instance pointer: domain offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_31 = mdns_read_answer (pkt_28(D), &ans);
  Function call may change dynamic type:res_31 = mdns_read_answer (pkt_28(D), &ans);
  Function call may change dynamic type:res_46 = mdns_read_question (pkt_28(D), &q);
  Function call may change dynamic type:res_33 = mdns_build_host_domain (&domain, mdns_29);
  Function call may change dynamic type:_7 = mdns_domain_eq (&ans.info.domain, &domain);
  Function call may change dynamic type:_9 = mdns_domain_eq (&ans.info.domain, &domain);
  Function call may change dynamic type:res_40 = mdns_build_service_domain (&domain, service_38, 1);
  Function call may change dynamic type:sys_untimeout (mdns_probe, _10);
  Function call may change dynamic type:mdns_name_result_cb.62_11 (_13, 0);
Determining dynamic type for call: res_33 = mdns_build_host_domain (&domain, mdns_29);
  Starting walk at: res_33 = mdns_build_host_domain (&domain, mdns_29);
  instance pointer: mdns_29  Outer instance pointer: mdns_29 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_31 = mdns_read_answer (pkt_28(D), &ans);
  Function call may change dynamic type:res_31 = mdns_read_answer (pkt_28(D), &ans);
  Function call may change dynamic type:res_46 = mdns_read_question (pkt_28(D), &q);
  Function call may change dynamic type:res_33 = mdns_build_host_domain (&domain, mdns_29);
  Function call may change dynamic type:_7 = mdns_domain_eq (&ans.info.domain, &domain);
  Function call may change dynamic type:_9 = mdns_domain_eq (&ans.info.domain, &domain);
  Function call may change dynamic type:res_40 = mdns_build_service_domain (&domain, service_38, 1);
  Function call may change dynamic type:sys_untimeout (mdns_probe, _10);
  Function call may change dynamic type:mdns_name_result_cb.62_11 (_13, 0);
Determining dynamic type for call: _7 = mdns_domain_eq (&ans.info.domain, &domain);
  Starting walk at: _7 = mdns_domain_eq (&ans.info.domain, &domain);
  instance pointer: &ans.info.domain  Outer instance pointer: ans offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_33 = mdns_build_host_domain (&domain, mdns_29);
  Function call may change dynamic type:res_31 = mdns_read_answer (pkt_28(D), &ans);
  Function call may change dynamic type:res_31 = mdns_read_answer (pkt_28(D), &ans);
  Function call may change dynamic type:res_46 = mdns_read_question (pkt_28(D), &q);
  Function call may change dynamic type:res_33 = mdns_build_host_domain (&domain, mdns_29);
  Function call may change dynamic type:_7 = mdns_domain_eq (&ans.info.domain, &domain);
  Function call may change dynamic type:_9 = mdns_domain_eq (&ans.info.domain, &domain);
  Function call may change dynamic type:res_40 = mdns_build_service_domain (&domain, service_38, 1);
  Function call may change dynamic type:sys_untimeout (mdns_probe, _10);
  Function call may change dynamic type:mdns_name_result_cb.62_11 (_13, 0);
Determining dynamic type for call: _7 = mdns_domain_eq (&ans.info.domain, &domain);
  Starting walk at: _7 = mdns_domain_eq (&ans.info.domain, &domain);
  instance pointer: &domain  Outer instance pointer: domain offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_33 = mdns_build_host_domain (&domain, mdns_29);
  Function call may change dynamic type:res_31 = mdns_read_answer (pkt_28(D), &ans);
  Function call may change dynamic type:res_31 = mdns_read_answer (pkt_28(D), &ans);
  Function call may change dynamic type:res_46 = mdns_read_question (pkt_28(D), &q);
  Function call may change dynamic type:res_33 = mdns_build_host_domain (&domain, mdns_29);
  Function call may change dynamic type:_7 = mdns_domain_eq (&ans.info.domain, &domain);
  Function call may change dynamic type:_9 = mdns_domain_eq (&ans.info.domain, &domain);
  Function call may change dynamic type:res_40 = mdns_build_service_domain (&domain, service_38, 1);
  Function call may change dynamic type:sys_untimeout (mdns_probe, _10);
  Function call may change dynamic type:mdns_name_result_cb.62_11 (_13, 0);
Determining dynamic type for call: mdns_name_result_cb.62_11 (_13, 0);
  Starting walk at: mdns_name_result_cb.62_11 (_13, 0);
  instance pointer: _13  Outer instance pointer: _13 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:sys_untimeout (mdns_probe, _10);
  Function call may change dynamic type:res_33 = mdns_build_host_domain (&domain, mdns_29);
  Function call may change dynamic type:res_31 = mdns_read_answer (pkt_28(D), &ans);
  Function call may change dynamic type:_9 = mdns_domain_eq (&ans.info.domain, &domain);
  Function call may change dynamic type:res_40 = mdns_build_service_domain (&domain, service_38, 1);
  Function call may change dynamic type:sys_untimeout (mdns_probe, _10);
  Function call may change dynamic type:mdns_name_result_cb.62_11 (_13, 0);
  Function call may change dynamic type:res_46 = mdns_read_question (pkt_28(D), &q);
  Function call may change dynamic type:_7 = mdns_domain_eq (&ans.info.domain, &domain);
Determining dynamic type for call: res_40 = mdns_build_service_domain (&domain, service_38, 1);
  Starting walk at: res_40 = mdns_build_service_domain (&domain, service_38, 1);
  instance pointer: &domain  Outer instance pointer: domain offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_33 = mdns_build_host_domain (&domain, mdns_29);
  Function call may change dynamic type:res_31 = mdns_read_answer (pkt_28(D), &ans);
  Function call may change dynamic type:_9 = mdns_domain_eq (&ans.info.domain, &domain);
  Function call may change dynamic type:res_40 = mdns_build_service_domain (&domain, service_38, 1);
  Function call may change dynamic type:sys_untimeout (mdns_probe, _10);
  Function call may change dynamic type:mdns_name_result_cb.62_11 (_13, 0);
  Function call may change dynamic type:res_46 = mdns_read_question (pkt_28(D), &q);
  Function call may change dynamic type:_7 = mdns_domain_eq (&ans.info.domain, &domain);
Determining dynamic type for call: res_40 = mdns_build_service_domain (&domain, service_38, 1);
  Starting walk at: res_40 = mdns_build_service_domain (&domain, service_38, 1);
  instance pointer: service_38  Outer instance pointer: service_38 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_33 = mdns_build_host_domain (&domain, mdns_29);
  Function call may change dynamic type:res_31 = mdns_read_answer (pkt_28(D), &ans);
  Function call may change dynamic type:_9 = mdns_domain_eq (&ans.info.domain, &domain);
  Function call may change dynamic type:res_40 = mdns_build_service_domain (&domain, service_38, 1);
  Function call may change dynamic type:sys_untimeout (mdns_probe, _10);
  Function call may change dynamic type:mdns_name_result_cb.62_11 (_13, 0);
  Function call may change dynamic type:res_46 = mdns_read_question (pkt_28(D), &q);
  Function call may change dynamic type:_7 = mdns_domain_eq (&ans.info.domain, &domain);
Determining dynamic type for call: _9 = mdns_domain_eq (&ans.info.domain, &domain);
  Starting walk at: _9 = mdns_domain_eq (&ans.info.domain, &domain);
  instance pointer: &ans.info.domain  Outer instance pointer: ans offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_40 = mdns_build_service_domain (&domain, service_38, 1);
  Function call may change dynamic type:res_33 = mdns_build_host_domain (&domain, mdns_29);
  Function call may change dynamic type:res_31 = mdns_read_answer (pkt_28(D), &ans);
  Function call may change dynamic type:_9 = mdns_domain_eq (&ans.info.domain, &domain);
  Function call may change dynamic type:res_40 = mdns_build_service_domain (&domain, service_38, 1);
  Function call may change dynamic type:sys_untimeout (mdns_probe, _10);
  Function call may change dynamic type:mdns_name_result_cb.62_11 (_13, 0);
  Function call may change dynamic type:res_46 = mdns_read_question (pkt_28(D), &q);
  Function call may change dynamic type:_7 = mdns_domain_eq (&ans.info.domain, &domain);
Determining dynamic type for call: _9 = mdns_domain_eq (&ans.info.domain, &domain);
  Starting walk at: _9 = mdns_domain_eq (&ans.info.domain, &domain);
  instance pointer: &domain  Outer instance pointer: domain offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_40 = mdns_build_service_domain (&domain, service_38, 1);
  Function call may change dynamic type:res_33 = mdns_build_host_domain (&domain, mdns_29);
  Function call may change dynamic type:res_31 = mdns_read_answer (pkt_28(D), &ans);
  Function call may change dynamic type:_9 = mdns_domain_eq (&ans.info.domain, &domain);
  Function call may change dynamic type:res_40 = mdns_build_service_domain (&domain, service_38, 1);
  Function call may change dynamic type:sys_untimeout (mdns_probe, _10);
  Function call may change dynamic type:mdns_name_result_cb.62_11 (_13, 0);
  Function call may change dynamic type:res_46 = mdns_read_question (pkt_28(D), &q);
  Function call may change dynamic type:_7 = mdns_domain_eq (&ans.info.domain, &domain);
Determining dynamic type for call: res_46 = mdns_read_question (pkt_28(D), &q);
  Starting walk at: res_46 = mdns_read_question (pkt_28(D), &q);
  instance pointer: pkt_28(D)  Outer instance pointer: pkt_28(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_46 = mdns_read_question (pkt_28(D), &q);
Determining dynamic type for call: res_46 = mdns_read_question (pkt_28(D), &q);
  Starting walk at: res_46 = mdns_read_question (pkt_28(D), &q);
  instance pointer: &q  Outer instance pointer: q offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_46 = mdns_read_question (pkt_28(D), &q);
Determining dynamic type for call: mdns_init_outpacket (&reply, pkt_136(D));
  Starting walk at: mdns_init_outpacket (&reply, pkt_136(D));
  instance pointer: &reply  Outer instance pointer: reply offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: mdns_init_outpacket (&reply, pkt_136(D));
  Starting walk at: mdns_init_outpacket (&reply, pkt_136(D));
  instance pointer: pkt_136(D)  Outer instance pointer: pkt_136(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: mdns_send_outpacket (&reply, 132);
  Starting walk at: mdns_send_outpacket (&reply, 132);
  instance pointer: &reply  Outer instance pointer: reply offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_28 = check_host (_27, &ans.info, &rev_v6);
  Function call may change dynamic type:res_141 = mdns_read_answer (pkt_136(D), &ans);
  Function call may change dynamic type:mdns_init_outpacket (&reply, pkt_136(D));
  Function call may change dynamic type:_219 = check_service (service_217, &q.info);
  Function call may change dynamic type:_209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  Function call may change dynamic type:res_206 = mdns_read_question (pkt_136(D), &q);
  Function call may change dynamic type:res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
  Function call may change dynamic type:res_152 = mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_150 = mdns_readname (_33, _34, &known_ans);
  Function call may change dynamic type:_35 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:_56 = pbuf_memcmp (_51, _52, _54, 4);
  Function call may change dynamic type:_66 = pbuf_memcmp (_61, _62, _64, 16);
  Function call may change dynamic type:_71 = check_service (service_161, &ans.info);
  Function call may change dynamic type:_107 = pbuf_memcmp (_104, _105, _106, _103);
  Function call may change dynamic type:mdns_prepare_txtdata (service_161);
  Function call may change dynamic type:len_169 = pbuf_copy_partial (_87, &field16, 2, read_pos_167);
  Function call may change dynamic type:_89 = lwip_htons (field16.72_88);
  Function call may change dynamic type:len_173 = pbuf_copy_partial (_90, &field16, 2, read_pos_171);
  Function call may change dynamic type:_92 = lwip_htons (field16.73_91);
  Function call may change dynamic type:len_177 = pbuf_copy_partial (_93, &field16, 2, read_pos_175);
  Function call may change dynamic type:_95 = lwip_htons (field16.74_94);
  Function call may change dynamic type:mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_181 = mdns_readname (_97, read_pos_179, &known_ans);
  Function call may change dynamic type:_98 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:len_189 = mdns_readname (_76, _77, &known_ans);
  Function call may change dynamic type:res_191 = mdns_build_service_domain (&my_ans, service_161, 0);
  Function call may change dynamic type:_79 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:res_195 = mdns_build_service_domain (&my_ans, service_161, 1);
  Function call may change dynamic type:_83 = mdns_domain_eq (&known_ans, &my_ans);
Determining dynamic type for call: res_141 = mdns_read_answer (pkt_136(D), &ans);
  Starting walk at: res_141 = mdns_read_answer (pkt_136(D), &ans);
  instance pointer: pkt_136(D)  Outer instance pointer: pkt_136(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_28 = check_host (_27, &ans.info, &rev_v6);
  Function call may change dynamic type:res_141 = mdns_read_answer (pkt_136(D), &ans);
  Function call may change dynamic type:mdns_init_outpacket (&reply, pkt_136(D));
  Function call may change dynamic type:_219 = check_service (service_217, &q.info);
  Function call may change dynamic type:_209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  Function call may change dynamic type:res_206 = mdns_read_question (pkt_136(D), &q);
  Function call may change dynamic type:res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
  Function call may change dynamic type:res_152 = mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_150 = mdns_readname (_33, _34, &known_ans);
  Function call may change dynamic type:_35 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:_56 = pbuf_memcmp (_51, _52, _54, 4);
  Function call may change dynamic type:_66 = pbuf_memcmp (_61, _62, _64, 16);
  Function call may change dynamic type:_71 = check_service (service_161, &ans.info);
  Function call may change dynamic type:_107 = pbuf_memcmp (_104, _105, _106, _103);
  Function call may change dynamic type:mdns_prepare_txtdata (service_161);
  Function call may change dynamic type:len_169 = pbuf_copy_partial (_87, &field16, 2, read_pos_167);
  Function call may change dynamic type:_89 = lwip_htons (field16.72_88);
  Function call may change dynamic type:len_173 = pbuf_copy_partial (_90, &field16, 2, read_pos_171);
  Function call may change dynamic type:_92 = lwip_htons (field16.73_91);
  Function call may change dynamic type:len_177 = pbuf_copy_partial (_93, &field16, 2, read_pos_175);
  Function call may change dynamic type:_95 = lwip_htons (field16.74_94);
  Function call may change dynamic type:mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_181 = mdns_readname (_97, read_pos_179, &known_ans);
  Function call may change dynamic type:_98 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:len_189 = mdns_readname (_76, _77, &known_ans);
  Function call may change dynamic type:res_191 = mdns_build_service_domain (&my_ans, service_161, 0);
  Function call may change dynamic type:_79 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:res_195 = mdns_build_service_domain (&my_ans, service_161, 1);
  Function call may change dynamic type:_83 = mdns_domain_eq (&known_ans, &my_ans);
Determining dynamic type for call: res_141 = mdns_read_answer (pkt_136(D), &ans);
  Starting walk at: res_141 = mdns_read_answer (pkt_136(D), &ans);
  instance pointer: &ans  Outer instance pointer: ans offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_28 = check_host (_27, &ans.info, &rev_v6);
  Function call may change dynamic type:res_141 = mdns_read_answer (pkt_136(D), &ans);
  Function call may change dynamic type:mdns_init_outpacket (&reply, pkt_136(D));
  Function call may change dynamic type:_219 = check_service (service_217, &q.info);
  Function call may change dynamic type:_209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  Function call may change dynamic type:res_206 = mdns_read_question (pkt_136(D), &q);
  Function call may change dynamic type:res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
  Function call may change dynamic type:res_152 = mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_150 = mdns_readname (_33, _34, &known_ans);
  Function call may change dynamic type:_35 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:_56 = pbuf_memcmp (_51, _52, _54, 4);
  Function call may change dynamic type:_66 = pbuf_memcmp (_61, _62, _64, 16);
  Function call may change dynamic type:_71 = check_service (service_161, &ans.info);
  Function call may change dynamic type:_107 = pbuf_memcmp (_104, _105, _106, _103);
  Function call may change dynamic type:mdns_prepare_txtdata (service_161);
  Function call may change dynamic type:len_169 = pbuf_copy_partial (_87, &field16, 2, read_pos_167);
  Function call may change dynamic type:_89 = lwip_htons (field16.72_88);
  Function call may change dynamic type:len_173 = pbuf_copy_partial (_90, &field16, 2, read_pos_171);
  Function call may change dynamic type:_92 = lwip_htons (field16.73_91);
  Function call may change dynamic type:len_177 = pbuf_copy_partial (_93, &field16, 2, read_pos_175);
  Function call may change dynamic type:_95 = lwip_htons (field16.74_94);
  Function call may change dynamic type:mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_181 = mdns_readname (_97, read_pos_179, &known_ans);
  Function call may change dynamic type:_98 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:len_189 = mdns_readname (_76, _77, &known_ans);
  Function call may change dynamic type:res_191 = mdns_build_service_domain (&my_ans, service_161, 0);
  Function call may change dynamic type:_79 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:res_195 = mdns_build_service_domain (&my_ans, service_161, 1);
  Function call may change dynamic type:_83 = mdns_domain_eq (&known_ans, &my_ans);
Determining dynamic type for call: mdns_domain_debug_print (&ans.info.domain);
  Starting walk at: mdns_domain_debug_print (&ans.info.domain);
  instance pointer: &ans.info.domain  Outer instance pointer: ans offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_141 = mdns_read_answer (pkt_136(D), &ans);
  Function call may change dynamic type:_28 = check_host (_27, &ans.info, &rev_v6);
  Function call may change dynamic type:res_141 = mdns_read_answer (pkt_136(D), &ans);
  Function call may change dynamic type:mdns_init_outpacket (&reply, pkt_136(D));
  Function call may change dynamic type:_219 = check_service (service_217, &q.info);
  Function call may change dynamic type:_209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  Function call may change dynamic type:res_206 = mdns_read_question (pkt_136(D), &q);
  Function call may change dynamic type:res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
  Function call may change dynamic type:res_152 = mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_150 = mdns_readname (_33, _34, &known_ans);
  Function call may change dynamic type:_35 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:_56 = pbuf_memcmp (_51, _52, _54, 4);
  Function call may change dynamic type:_66 = pbuf_memcmp (_61, _62, _64, 16);
  Function call may change dynamic type:_71 = check_service (service_161, &ans.info);
  Function call may change dynamic type:_107 = pbuf_memcmp (_104, _105, _106, _103);
  Function call may change dynamic type:mdns_prepare_txtdata (service_161);
  Function call may change dynamic type:len_169 = pbuf_copy_partial (_87, &field16, 2, read_pos_167);
  Function call may change dynamic type:_89 = lwip_htons (field16.72_88);
  Function call may change dynamic type:len_173 = pbuf_copy_partial (_90, &field16, 2, read_pos_171);
  Function call may change dynamic type:_92 = lwip_htons (field16.73_91);
  Function call may change dynamic type:len_177 = pbuf_copy_partial (_93, &field16, 2, read_pos_175);
  Function call may change dynamic type:_95 = lwip_htons (field16.74_94);
  Function call may change dynamic type:mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_181 = mdns_readname (_97, read_pos_179, &known_ans);
  Function call may change dynamic type:_98 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:len_189 = mdns_readname (_76, _77, &known_ans);
  Function call may change dynamic type:res_191 = mdns_build_service_domain (&my_ans, service_161, 0);
  Function call may change dynamic type:_79 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:res_195 = mdns_build_service_domain (&my_ans, service_161, 1);
  Function call may change dynamic type:_83 = mdns_domain_eq (&known_ans, &my_ans);
Determining dynamic type for call: _28 = check_host (_27, &ans.info, &rev_v6);
  Starting walk at: _28 = check_host (_27, &ans.info, &rev_v6);
  instance pointer: _27  Outer instance pointer: _27 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_141 = mdns_read_answer (pkt_136(D), &ans);
  Function call may change dynamic type:_28 = check_host (_27, &ans.info, &rev_v6);
  Function call may change dynamic type:res_141 = mdns_read_answer (pkt_136(D), &ans);
  Function call may change dynamic type:mdns_init_outpacket (&reply, pkt_136(D));
  Function call may change dynamic type:_219 = check_service (service_217, &q.info);
  Function call may change dynamic type:_209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  Function call may change dynamic type:res_206 = mdns_read_question (pkt_136(D), &q);
  Function call may change dynamic type:res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
  Function call may change dynamic type:res_152 = mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_150 = mdns_readname (_33, _34, &known_ans);
  Function call may change dynamic type:_35 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:_56 = pbuf_memcmp (_51, _52, _54, 4);
  Function call may change dynamic type:_66 = pbuf_memcmp (_61, _62, _64, 16);
  Function call may change dynamic type:_71 = check_service (service_161, &ans.info);
  Function call may change dynamic type:_107 = pbuf_memcmp (_104, _105, _106, _103);
  Function call may change dynamic type:mdns_prepare_txtdata (service_161);
  Function call may change dynamic type:len_169 = pbuf_copy_partial (_87, &field16, 2, read_pos_167);
  Function call may change dynamic type:_89 = lwip_htons (field16.72_88);
  Function call may change dynamic type:len_173 = pbuf_copy_partial (_90, &field16, 2, read_pos_171);
  Function call may change dynamic type:_92 = lwip_htons (field16.73_91);
  Function call may change dynamic type:len_177 = pbuf_copy_partial (_93, &field16, 2, read_pos_175);
  Function call may change dynamic type:_95 = lwip_htons (field16.74_94);
  Function call may change dynamic type:mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_181 = mdns_readname (_97, read_pos_179, &known_ans);
  Function call may change dynamic type:_98 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:len_189 = mdns_readname (_76, _77, &known_ans);
  Function call may change dynamic type:res_191 = mdns_build_service_domain (&my_ans, service_161, 0);
  Function call may change dynamic type:_79 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:res_195 = mdns_build_service_domain (&my_ans, service_161, 1);
  Function call may change dynamic type:_83 = mdns_domain_eq (&known_ans, &my_ans);
Determining dynamic type for call: _28 = check_host (_27, &ans.info, &rev_v6);
  Starting walk at: _28 = check_host (_27, &ans.info, &rev_v6);
  instance pointer: &ans.info  Outer instance pointer: ans offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_141 = mdns_read_answer (pkt_136(D), &ans);
  Function call may change dynamic type:_28 = check_host (_27, &ans.info, &rev_v6);
  Function call may change dynamic type:res_141 = mdns_read_answer (pkt_136(D), &ans);
  Function call may change dynamic type:mdns_init_outpacket (&reply, pkt_136(D));
  Function call may change dynamic type:_219 = check_service (service_217, &q.info);
  Function call may change dynamic type:_209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  Function call may change dynamic type:res_206 = mdns_read_question (pkt_136(D), &q);
  Function call may change dynamic type:res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
  Function call may change dynamic type:res_152 = mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_150 = mdns_readname (_33, _34, &known_ans);
  Function call may change dynamic type:_35 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:_56 = pbuf_memcmp (_51, _52, _54, 4);
  Function call may change dynamic type:_66 = pbuf_memcmp (_61, _62, _64, 16);
  Function call may change dynamic type:_71 = check_service (service_161, &ans.info);
  Function call may change dynamic type:_107 = pbuf_memcmp (_104, _105, _106, _103);
  Function call may change dynamic type:mdns_prepare_txtdata (service_161);
  Function call may change dynamic type:len_169 = pbuf_copy_partial (_87, &field16, 2, read_pos_167);
  Function call may change dynamic type:_89 = lwip_htons (field16.72_88);
  Function call may change dynamic type:len_173 = pbuf_copy_partial (_90, &field16, 2, read_pos_171);
  Function call may change dynamic type:_92 = lwip_htons (field16.73_91);
  Function call may change dynamic type:len_177 = pbuf_copy_partial (_93, &field16, 2, read_pos_175);
  Function call may change dynamic type:_95 = lwip_htons (field16.74_94);
  Function call may change dynamic type:mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_181 = mdns_readname (_97, read_pos_179, &known_ans);
  Function call may change dynamic type:_98 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:len_189 = mdns_readname (_76, _77, &known_ans);
  Function call may change dynamic type:res_191 = mdns_build_service_domain (&my_ans, service_161, 0);
  Function call may change dynamic type:_79 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:res_195 = mdns_build_service_domain (&my_ans, service_161, 1);
  Function call may change dynamic type:_83 = mdns_domain_eq (&known_ans, &my_ans);
Determining dynamic type for call: _28 = check_host (_27, &ans.info, &rev_v6);
  Starting walk at: _28 = check_host (_27, &ans.info, &rev_v6);
  instance pointer: &rev_v6  Outer instance pointer: rev_v6 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_141 = mdns_read_answer (pkt_136(D), &ans);
  Function call may change dynamic type:_28 = check_host (_27, &ans.info, &rev_v6);
  Function call may change dynamic type:res_141 = mdns_read_answer (pkt_136(D), &ans);
  Function call may change dynamic type:mdns_init_outpacket (&reply, pkt_136(D));
  Function call may change dynamic type:_219 = check_service (service_217, &q.info);
  Function call may change dynamic type:_209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  Function call may change dynamic type:res_206 = mdns_read_question (pkt_136(D), &q);
  Function call may change dynamic type:res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
  Function call may change dynamic type:res_152 = mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_150 = mdns_readname (_33, _34, &known_ans);
  Function call may change dynamic type:_35 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:_56 = pbuf_memcmp (_51, _52, _54, 4);
  Function call may change dynamic type:_66 = pbuf_memcmp (_61, _62, _64, 16);
  Function call may change dynamic type:_71 = check_service (service_161, &ans.info);
  Function call may change dynamic type:_107 = pbuf_memcmp (_104, _105, _106, _103);
  Function call may change dynamic type:mdns_prepare_txtdata (service_161);
  Function call may change dynamic type:len_169 = pbuf_copy_partial (_87, &field16, 2, read_pos_167);
  Function call may change dynamic type:_89 = lwip_htons (field16.72_88);
  Function call may change dynamic type:len_173 = pbuf_copy_partial (_90, &field16, 2, read_pos_171);
  Function call may change dynamic type:_92 = lwip_htons (field16.73_91);
  Function call may change dynamic type:len_177 = pbuf_copy_partial (_93, &field16, 2, read_pos_175);
  Function call may change dynamic type:_95 = lwip_htons (field16.74_94);
  Function call may change dynamic type:mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_181 = mdns_readname (_97, read_pos_179, &known_ans);
  Function call may change dynamic type:_98 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:len_189 = mdns_readname (_76, _77, &known_ans);
  Function call may change dynamic type:res_191 = mdns_build_service_domain (&my_ans, service_161, 0);
  Function call may change dynamic type:_79 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:res_195 = mdns_build_service_domain (&my_ans, service_161, 1);
  Function call may change dynamic type:_83 = mdns_domain_eq (&known_ans, &my_ans);
Determining dynamic type for call: len_150 = mdns_readname (_33, _34, &known_ans);
  Starting walk at: len_150 = mdns_readname (_33, _34, &known_ans);
  instance pointer: _33  Outer instance pointer: _33 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_28 = check_host (_27, &ans.info, &rev_v6);
  Function call may change dynamic type:res_141 = mdns_read_answer (pkt_136(D), &ans);
  Function call may change dynamic type:_28 = check_host (_27, &ans.info, &rev_v6);
  Function call may change dynamic type:res_141 = mdns_read_answer (pkt_136(D), &ans);
  Function call may change dynamic type:mdns_init_outpacket (&reply, pkt_136(D));
  Function call may change dynamic type:_219 = check_service (service_217, &q.info);
  Function call may change dynamic type:_209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  Function call may change dynamic type:res_206 = mdns_read_question (pkt_136(D), &q);
  Function call may change dynamic type:res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
  Function call may change dynamic type:res_152 = mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_150 = mdns_readname (_33, _34, &known_ans);
  Function call may change dynamic type:_35 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:_56 = pbuf_memcmp (_51, _52, _54, 4);
  Function call may change dynamic type:_66 = pbuf_memcmp (_61, _62, _64, 16);
  Function call may change dynamic type:_71 = check_service (service_161, &ans.info);
  Function call may change dynamic type:_107 = pbuf_memcmp (_104, _105, _106, _103);
  Function call may change dynamic type:mdns_prepare_txtdata (service_161);
  Function call may change dynamic type:len_169 = pbuf_copy_partial (_87, &field16, 2, read_pos_167);
  Function call may change dynamic type:_89 = lwip_htons (field16.72_88);
  Function call may change dynamic type:len_173 = pbuf_copy_partial (_90, &field16, 2, read_pos_171);
  Function call may change dynamic type:_92 = lwip_htons (field16.73_91);
  Function call may change dynamic type:len_177 = pbuf_copy_partial (_93, &field16, 2, read_pos_175);
  Function call may change dynamic type:_95 = lwip_htons (field16.74_94);
  Function call may change dynamic type:mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_181 = mdns_readname (_97, read_pos_179, &known_ans);
  Function call may change dynamic type:_98 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:len_189 = mdns_readname (_76, _77, &known_ans);
  Function call may change dynamic type:res_191 = mdns_build_service_domain (&my_ans, service_161, 0);
  Function call may change dynamic type:_79 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:res_195 = mdns_build_service_domain (&my_ans, service_161, 1);
  Function call may change dynamic type:_83 = mdns_domain_eq (&known_ans, &my_ans);
Determining dynamic type for call: len_150 = mdns_readname (_33, _34, &known_ans);
  Starting walk at: len_150 = mdns_readname (_33, _34, &known_ans);
  instance pointer: &known_ans  Outer instance pointer: known_ans offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_28 = check_host (_27, &ans.info, &rev_v6);
  Function call may change dynamic type:res_141 = mdns_read_answer (pkt_136(D), &ans);
  Function call may change dynamic type:_28 = check_host (_27, &ans.info, &rev_v6);
  Function call may change dynamic type:res_141 = mdns_read_answer (pkt_136(D), &ans);
  Function call may change dynamic type:mdns_init_outpacket (&reply, pkt_136(D));
  Function call may change dynamic type:_219 = check_service (service_217, &q.info);
  Function call may change dynamic type:_209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  Function call may change dynamic type:res_206 = mdns_read_question (pkt_136(D), &q);
  Function call may change dynamic type:res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
  Function call may change dynamic type:res_152 = mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_150 = mdns_readname (_33, _34, &known_ans);
  Function call may change dynamic type:_35 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:_56 = pbuf_memcmp (_51, _52, _54, 4);
  Function call may change dynamic type:_66 = pbuf_memcmp (_61, _62, _64, 16);
  Function call may change dynamic type:_71 = check_service (service_161, &ans.info);
  Function call may change dynamic type:_107 = pbuf_memcmp (_104, _105, _106, _103);
  Function call may change dynamic type:mdns_prepare_txtdata (service_161);
  Function call may change dynamic type:len_169 = pbuf_copy_partial (_87, &field16, 2, read_pos_167);
  Function call may change dynamic type:_89 = lwip_htons (field16.72_88);
  Function call may change dynamic type:len_173 = pbuf_copy_partial (_90, &field16, 2, read_pos_171);
  Function call may change dynamic type:_92 = lwip_htons (field16.73_91);
  Function call may change dynamic type:len_177 = pbuf_copy_partial (_93, &field16, 2, read_pos_175);
  Function call may change dynamic type:_95 = lwip_htons (field16.74_94);
  Function call may change dynamic type:mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_181 = mdns_readname (_97, read_pos_179, &known_ans);
  Function call may change dynamic type:_98 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:len_189 = mdns_readname (_76, _77, &known_ans);
  Function call may change dynamic type:res_191 = mdns_build_service_domain (&my_ans, service_161, 0);
  Function call may change dynamic type:_79 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:res_195 = mdns_build_service_domain (&my_ans, service_161, 1);
  Function call may change dynamic type:_83 = mdns_domain_eq (&known_ans, &my_ans);
Determining dynamic type for call: res_152 = mdns_build_host_domain (&my_ans, mdns_137);
  Starting walk at: res_152 = mdns_build_host_domain (&my_ans, mdns_137);
  instance pointer: &my_ans  Outer instance pointer: my_ans offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:len_150 = mdns_readname (_33, _34, &known_ans);
  Function call may change dynamic type:_28 = check_host (_27, &ans.info, &rev_v6);
  Function call may change dynamic type:res_141 = mdns_read_answer (pkt_136(D), &ans);
  Function call may change dynamic type:_28 = check_host (_27, &ans.info, &rev_v6);
  Function call may change dynamic type:res_141 = mdns_read_answer (pkt_136(D), &ans);
  Function call may change dynamic type:mdns_init_outpacket (&reply, pkt_136(D));
  Function call may change dynamic type:_219 = check_service (service_217, &q.info);
  Function call may change dynamic type:_209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  Function call may change dynamic type:res_206 = mdns_read_question (pkt_136(D), &q);
  Function call may change dynamic type:res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
  Function call may change dynamic type:res_152 = mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_150 = mdns_readname (_33, _34, &known_ans);
  Function call may change dynamic type:_35 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:_56 = pbuf_memcmp (_51, _52, _54, 4);
  Function call may change dynamic type:_66 = pbuf_memcmp (_61, _62, _64, 16);
  Function call may change dynamic type:_71 = check_service (service_161, &ans.info);
  Function call may change dynamic type:_107 = pbuf_memcmp (_104, _105, _106, _103);
  Function call may change dynamic type:mdns_prepare_txtdata (service_161);
  Function call may change dynamic type:len_169 = pbuf_copy_partial (_87, &field16, 2, read_pos_167);
  Function call may change dynamic type:_89 = lwip_htons (field16.72_88);
  Function call may change dynamic type:len_173 = pbuf_copy_partial (_90, &field16, 2, read_pos_171);
  Function call may change dynamic type:_92 = lwip_htons (field16.73_91);
  Function call may change dynamic type:len_177 = pbuf_copy_partial (_93, &field16, 2, read_pos_175);
  Function call may change dynamic type:_95 = lwip_htons (field16.74_94);
  Function call may change dynamic type:mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_181 = mdns_readname (_97, read_pos_179, &known_ans);
  Function call may change dynamic type:_98 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:len_189 = mdns_readname (_76, _77, &known_ans);
  Function call may change dynamic type:res_191 = mdns_build_service_domain (&my_ans, service_161, 0);
  Function call may change dynamic type:_79 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:res_195 = mdns_build_service_domain (&my_ans, service_161, 1);
  Function call may change dynamic type:_83 = mdns_domain_eq (&known_ans, &my_ans);
Determining dynamic type for call: res_152 = mdns_build_host_domain (&my_ans, mdns_137);
  Starting walk at: res_152 = mdns_build_host_domain (&my_ans, mdns_137);
  instance pointer: mdns_137  Outer instance pointer: mdns_137 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:len_150 = mdns_readname (_33, _34, &known_ans);
  Function call may change dynamic type:_28 = check_host (_27, &ans.info, &rev_v6);
  Function call may change dynamic type:res_141 = mdns_read_answer (pkt_136(D), &ans);
  Function call may change dynamic type:_28 = check_host (_27, &ans.info, &rev_v6);
  Function call may change dynamic type:res_141 = mdns_read_answer (pkt_136(D), &ans);
  Function call may change dynamic type:mdns_init_outpacket (&reply, pkt_136(D));
  Function call may change dynamic type:_219 = check_service (service_217, &q.info);
  Function call may change dynamic type:_209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  Function call may change dynamic type:res_206 = mdns_read_question (pkt_136(D), &q);
  Function call may change dynamic type:res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
  Function call may change dynamic type:res_152 = mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_150 = mdns_readname (_33, _34, &known_ans);
  Function call may change dynamic type:_35 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:_56 = pbuf_memcmp (_51, _52, _54, 4);
  Function call may change dynamic type:_66 = pbuf_memcmp (_61, _62, _64, 16);
  Function call may change dynamic type:_71 = check_service (service_161, &ans.info);
  Function call may change dynamic type:_107 = pbuf_memcmp (_104, _105, _106, _103);
  Function call may change dynamic type:mdns_prepare_txtdata (service_161);
  Function call may change dynamic type:len_169 = pbuf_copy_partial (_87, &field16, 2, read_pos_167);
  Function call may change dynamic type:_89 = lwip_htons (field16.72_88);
  Function call may change dynamic type:len_173 = pbuf_copy_partial (_90, &field16, 2, read_pos_171);
  Function call may change dynamic type:_92 = lwip_htons (field16.73_91);
  Function call may change dynamic type:len_177 = pbuf_copy_partial (_93, &field16, 2, read_pos_175);
  Function call may change dynamic type:_95 = lwip_htons (field16.74_94);
  Function call may change dynamic type:mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_181 = mdns_readname (_97, read_pos_179, &known_ans);
  Function call may change dynamic type:_98 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:len_189 = mdns_readname (_76, _77, &known_ans);
  Function call may change dynamic type:res_191 = mdns_build_service_domain (&my_ans, service_161, 0);
  Function call may change dynamic type:_79 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:res_195 = mdns_build_service_domain (&my_ans, service_161, 1);
  Function call may change dynamic type:_83 = mdns_domain_eq (&known_ans, &my_ans);
Determining dynamic type for call: _35 = mdns_domain_eq (&known_ans, &my_ans);
  Starting walk at: _35 = mdns_domain_eq (&known_ans, &my_ans);
  instance pointer: &known_ans  Outer instance pointer: known_ans offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_152 = mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_150 = mdns_readname (_33, _34, &known_ans);
  Function call may change dynamic type:_28 = check_host (_27, &ans.info, &rev_v6);
  Function call may change dynamic type:res_141 = mdns_read_answer (pkt_136(D), &ans);
  Function call may change dynamic type:_28 = check_host (_27, &ans.info, &rev_v6);
  Function call may change dynamic type:res_141 = mdns_read_answer (pkt_136(D), &ans);
  Function call may change dynamic type:mdns_init_outpacket (&reply, pkt_136(D));
  Function call may change dynamic type:_219 = check_service (service_217, &q.info);
  Function call may change dynamic type:_209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  Function call may change dynamic type:res_206 = mdns_read_question (pkt_136(D), &q);
  Function call may change dynamic type:res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
  Function call may change dynamic type:res_152 = mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_150 = mdns_readname (_33, _34, &known_ans);
  Function call may change dynamic type:_35 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:_56 = pbuf_memcmp (_51, _52, _54, 4);
  Function call may change dynamic type:_66 = pbuf_memcmp (_61, _62, _64, 16);
  Function call may change dynamic type:_71 = check_service (service_161, &ans.info);
  Function call may change dynamic type:_107 = pbuf_memcmp (_104, _105, _106, _103);
  Function call may change dynamic type:mdns_prepare_txtdata (service_161);
  Function call may change dynamic type:len_169 = pbuf_copy_partial (_87, &field16, 2, read_pos_167);
  Function call may change dynamic type:_89 = lwip_htons (field16.72_88);
  Function call may change dynamic type:len_173 = pbuf_copy_partial (_90, &field16, 2, read_pos_171);
  Function call may change dynamic type:_92 = lwip_htons (field16.73_91);
  Function call may change dynamic type:len_177 = pbuf_copy_partial (_93, &field16, 2, read_pos_175);
  Function call may change dynamic type:_95 = lwip_htons (field16.74_94);
  Function call may change dynamic type:mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_181 = mdns_readname (_97, read_pos_179, &known_ans);
  Function call may change dynamic type:_98 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:len_189 = mdns_readname (_76, _77, &known_ans);
  Function call may change dynamic type:res_191 = mdns_build_service_domain (&my_ans, service_161, 0);
  Function call may change dynamic type:_79 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:res_195 = mdns_build_service_domain (&my_ans, service_161, 1);
  Function call may change dynamic type:_83 = mdns_domain_eq (&known_ans, &my_ans);
Determining dynamic type for call: _35 = mdns_domain_eq (&known_ans, &my_ans);
  Starting walk at: _35 = mdns_domain_eq (&known_ans, &my_ans);
  instance pointer: &my_ans  Outer instance pointer: my_ans offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_152 = mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_150 = mdns_readname (_33, _34, &known_ans);
  Function call may change dynamic type:_28 = check_host (_27, &ans.info, &rev_v6);
  Function call may change dynamic type:res_141 = mdns_read_answer (pkt_136(D), &ans);
  Function call may change dynamic type:_28 = check_host (_27, &ans.info, &rev_v6);
  Function call may change dynamic type:res_141 = mdns_read_answer (pkt_136(D), &ans);
  Function call may change dynamic type:mdns_init_outpacket (&reply, pkt_136(D));
  Function call may change dynamic type:_219 = check_service (service_217, &q.info);
  Function call may change dynamic type:_209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  Function call may change dynamic type:res_206 = mdns_read_question (pkt_136(D), &q);
  Function call may change dynamic type:res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
  Function call may change dynamic type:res_152 = mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_150 = mdns_readname (_33, _34, &known_ans);
  Function call may change dynamic type:_35 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:_56 = pbuf_memcmp (_51, _52, _54, 4);
  Function call may change dynamic type:_66 = pbuf_memcmp (_61, _62, _64, 16);
  Function call may change dynamic type:_71 = check_service (service_161, &ans.info);
  Function call may change dynamic type:_107 = pbuf_memcmp (_104, _105, _106, _103);
  Function call may change dynamic type:mdns_prepare_txtdata (service_161);
  Function call may change dynamic type:len_169 = pbuf_copy_partial (_87, &field16, 2, read_pos_167);
  Function call may change dynamic type:_89 = lwip_htons (field16.72_88);
  Function call may change dynamic type:len_173 = pbuf_copy_partial (_90, &field16, 2, read_pos_171);
  Function call may change dynamic type:_92 = lwip_htons (field16.73_91);
  Function call may change dynamic type:len_177 = pbuf_copy_partial (_93, &field16, 2, read_pos_175);
  Function call may change dynamic type:_95 = lwip_htons (field16.74_94);
  Function call may change dynamic type:mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_181 = mdns_readname (_97, read_pos_179, &known_ans);
  Function call may change dynamic type:_98 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:len_189 = mdns_readname (_76, _77, &known_ans);
  Function call may change dynamic type:res_191 = mdns_build_service_domain (&my_ans, service_161, 0);
  Function call may change dynamic type:_79 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:res_195 = mdns_build_service_domain (&my_ans, service_161, 1);
  Function call may change dynamic type:_83 = mdns_domain_eq (&known_ans, &my_ans);
Determining dynamic type for call: _71 = check_service (service_161, &ans.info);
  Starting walk at: _71 = check_service (service_161, &ans.info);
  instance pointer: service_161  Outer instance pointer: service_161 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_28 = check_host (_27, &ans.info, &rev_v6);
  Function call may change dynamic type:res_141 = mdns_read_answer (pkt_136(D), &ans);
  Function call may change dynamic type:_71 = check_service (service_161, &ans.info);
  Function call may change dynamic type:_107 = pbuf_memcmp (_104, _105, _106, _103);
  Function call may change dynamic type:mdns_prepare_txtdata (service_161);
  Function call may change dynamic type:len_169 = pbuf_copy_partial (_87, &field16, 2, read_pos_167);
  Function call may change dynamic type:_89 = lwip_htons (field16.72_88);
  Function call may change dynamic type:len_173 = pbuf_copy_partial (_90, &field16, 2, read_pos_171);
  Function call may change dynamic type:_92 = lwip_htons (field16.73_91);
  Function call may change dynamic type:len_177 = pbuf_copy_partial (_93, &field16, 2, read_pos_175);
  Function call may change dynamic type:_95 = lwip_htons (field16.74_94);
  Function call may change dynamic type:mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_181 = mdns_readname (_97, read_pos_179, &known_ans);
  Function call may change dynamic type:_98 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:len_189 = mdns_readname (_76, _77, &known_ans);
  Function call may change dynamic type:res_191 = mdns_build_service_domain (&my_ans, service_161, 0);
  Function call may change dynamic type:_79 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:res_195 = mdns_build_service_domain (&my_ans, service_161, 1);
  Function call may change dynamic type:_83 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:mdns_init_outpacket (&reply, pkt_136(D));
  Function call may change dynamic type:_219 = check_service (service_217, &q.info);
  Function call may change dynamic type:_209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  Function call may change dynamic type:res_206 = mdns_read_question (pkt_136(D), &q);
  Function call may change dynamic type:res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
  Function call may change dynamic type:res_152 = mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_150 = mdns_readname (_33, _34, &known_ans);
  Function call may change dynamic type:_35 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:_56 = pbuf_memcmp (_51, _52, _54, 4);
  Function call may change dynamic type:_66 = pbuf_memcmp (_61, _62, _64, 16);
Determining dynamic type for call: _71 = check_service (service_161, &ans.info);
  Starting walk at: _71 = check_service (service_161, &ans.info);
  instance pointer: &ans.info  Outer instance pointer: ans offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_28 = check_host (_27, &ans.info, &rev_v6);
  Function call may change dynamic type:res_141 = mdns_read_answer (pkt_136(D), &ans);
  Function call may change dynamic type:_71 = check_service (service_161, &ans.info);
  Function call may change dynamic type:_107 = pbuf_memcmp (_104, _105, _106, _103);
  Function call may change dynamic type:mdns_prepare_txtdata (service_161);
  Function call may change dynamic type:len_169 = pbuf_copy_partial (_87, &field16, 2, read_pos_167);
  Function call may change dynamic type:_89 = lwip_htons (field16.72_88);
  Function call may change dynamic type:len_173 = pbuf_copy_partial (_90, &field16, 2, read_pos_171);
  Function call may change dynamic type:_92 = lwip_htons (field16.73_91);
  Function call may change dynamic type:len_177 = pbuf_copy_partial (_93, &field16, 2, read_pos_175);
  Function call may change dynamic type:_95 = lwip_htons (field16.74_94);
  Function call may change dynamic type:mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_181 = mdns_readname (_97, read_pos_179, &known_ans);
  Function call may change dynamic type:_98 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:len_189 = mdns_readname (_76, _77, &known_ans);
  Function call may change dynamic type:res_191 = mdns_build_service_domain (&my_ans, service_161, 0);
  Function call may change dynamic type:_79 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:res_195 = mdns_build_service_domain (&my_ans, service_161, 1);
  Function call may change dynamic type:_83 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:mdns_init_outpacket (&reply, pkt_136(D));
  Function call may change dynamic type:_219 = check_service (service_217, &q.info);
  Function call may change dynamic type:_209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  Function call may change dynamic type:res_206 = mdns_read_question (pkt_136(D), &q);
  Function call may change dynamic type:res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
  Function call may change dynamic type:res_152 = mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_150 = mdns_readname (_33, _34, &known_ans);
  Function call may change dynamic type:_35 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:_56 = pbuf_memcmp (_51, _52, _54, 4);
  Function call may change dynamic type:_66 = pbuf_memcmp (_61, _62, _64, 16);
Determining dynamic type for call: mdns_prepare_txtdata (service_161);
  Starting walk at: mdns_prepare_txtdata (service_161);
  instance pointer: service_161  Outer instance pointer: service_161 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_71 = check_service (service_161, &ans.info);
  Function call may change dynamic type:_28 = check_host (_27, &ans.info, &rev_v6);
  Function call may change dynamic type:res_141 = mdns_read_answer (pkt_136(D), &ans);
  Function call may change dynamic type:_71 = check_service (service_161, &ans.info);
  Function call may change dynamic type:_107 = pbuf_memcmp (_104, _105, _106, _103);
  Function call may change dynamic type:mdns_prepare_txtdata (service_161);
  Function call may change dynamic type:len_169 = pbuf_copy_partial (_87, &field16, 2, read_pos_167);
  Function call may change dynamic type:_89 = lwip_htons (field16.72_88);
  Function call may change dynamic type:len_173 = pbuf_copy_partial (_90, &field16, 2, read_pos_171);
  Function call may change dynamic type:_92 = lwip_htons (field16.73_91);
  Function call may change dynamic type:len_177 = pbuf_copy_partial (_93, &field16, 2, read_pos_175);
  Function call may change dynamic type:_95 = lwip_htons (field16.74_94);
  Function call may change dynamic type:mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_181 = mdns_readname (_97, read_pos_179, &known_ans);
  Function call may change dynamic type:_98 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:len_189 = mdns_readname (_76, _77, &known_ans);
  Function call may change dynamic type:res_191 = mdns_build_service_domain (&my_ans, service_161, 0);
  Function call may change dynamic type:_79 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:res_195 = mdns_build_service_domain (&my_ans, service_161, 1);
  Function call may change dynamic type:_83 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:mdns_init_outpacket (&reply, pkt_136(D));
  Function call may change dynamic type:_219 = check_service (service_217, &q.info);
  Function call may change dynamic type:_209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  Function call may change dynamic type:res_206 = mdns_read_question (pkt_136(D), &q);
  Function call may change dynamic type:res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
  Function call may change dynamic type:res_152 = mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_150 = mdns_readname (_33, _34, &known_ans);
  Function call may change dynamic type:_35 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:_56 = pbuf_memcmp (_51, _52, _54, 4);
  Function call may change dynamic type:_66 = pbuf_memcmp (_61, _62, _64, 16);
Determining dynamic type for call: len_181 = mdns_readname (_97, read_pos_179, &known_ans);
  Starting walk at: len_181 = mdns_readname (_97, read_pos_179, &known_ans);
  instance pointer: _97  Outer instance pointer: _97 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_95 = lwip_htons (field16.74_94);
  Function call may change dynamic type:len_177 = pbuf_copy_partial (_93, &field16, 2, read_pos_175);
  Function call may change dynamic type:_92 = lwip_htons (field16.73_91);
  Function call may change dynamic type:len_173 = pbuf_copy_partial (_90, &field16, 2, read_pos_171);
  Function call may change dynamic type:_89 = lwip_htons (field16.72_88);
  Function call may change dynamic type:len_169 = pbuf_copy_partial (_87, &field16, 2, read_pos_167);
  Function call may change dynamic type:_71 = check_service (service_161, &ans.info);
  Function call may change dynamic type:_28 = check_host (_27, &ans.info, &rev_v6);
  Function call may change dynamic type:res_141 = mdns_read_answer (pkt_136(D), &ans);
  Function call may change dynamic type:_71 = check_service (service_161, &ans.info);
  Function call may change dynamic type:_107 = pbuf_memcmp (_104, _105, _106, _103);
  Function call may change dynamic type:mdns_prepare_txtdata (service_161);
  Function call may change dynamic type:len_169 = pbuf_copy_partial (_87, &field16, 2, read_pos_167);
  Function call may change dynamic type:_89 = lwip_htons (field16.72_88);
  Function call may change dynamic type:len_173 = pbuf_copy_partial (_90, &field16, 2, read_pos_171);
  Function call may change dynamic type:_92 = lwip_htons (field16.73_91);
  Function call may change dynamic type:len_177 = pbuf_copy_partial (_93, &field16, 2, read_pos_175);
  Function call may change dynamic type:_95 = lwip_htons (field16.74_94);
  Function call may change dynamic type:mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_181 = mdns_readname (_97, read_pos_179, &known_ans);
  Function call may change dynamic type:_98 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:len_189 = mdns_readname (_76, _77, &known_ans);
  Function call may change dynamic type:res_191 = mdns_build_service_domain (&my_ans, service_161, 0);
  Function call may change dynamic type:_79 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:res_195 = mdns_build_service_domain (&my_ans, service_161, 1);
  Function call may change dynamic type:_83 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:mdns_init_outpacket (&reply, pkt_136(D));
  Function call may change dynamic type:_219 = check_service (service_217, &q.info);
  Function call may change dynamic type:_209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  Function call may change dynamic type:res_206 = mdns_read_question (pkt_136(D), &q);
  Function call may change dynamic type:res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
  Function call may change dynamic type:res_152 = mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_150 = mdns_readname (_33, _34, &known_ans);
  Function call may change dynamic type:_35 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:_56 = pbuf_memcmp (_51, _52, _54, 4);
  Function call may change dynamic type:_66 = pbuf_memcmp (_61, _62, _64, 16);
Determining dynamic type for call: len_181 = mdns_readname (_97, read_pos_179, &known_ans);
  Starting walk at: len_181 = mdns_readname (_97, read_pos_179, &known_ans);
  instance pointer: &known_ans  Outer instance pointer: known_ans offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_95 = lwip_htons (field16.74_94);
  Function call may change dynamic type:len_177 = pbuf_copy_partial (_93, &field16, 2, read_pos_175);
  Function call may change dynamic type:_92 = lwip_htons (field16.73_91);
  Function call may change dynamic type:len_173 = pbuf_copy_partial (_90, &field16, 2, read_pos_171);
  Function call may change dynamic type:_89 = lwip_htons (field16.72_88);
  Function call may change dynamic type:len_169 = pbuf_copy_partial (_87, &field16, 2, read_pos_167);
  Function call may change dynamic type:_71 = check_service (service_161, &ans.info);
  Function call may change dynamic type:_28 = check_host (_27, &ans.info, &rev_v6);
  Function call may change dynamic type:res_141 = mdns_read_answer (pkt_136(D), &ans);
  Function call may change dynamic type:_71 = check_service (service_161, &ans.info);
  Function call may change dynamic type:_107 = pbuf_memcmp (_104, _105, _106, _103);
  Function call may change dynamic type:mdns_prepare_txtdata (service_161);
  Function call may change dynamic type:len_169 = pbuf_copy_partial (_87, &field16, 2, read_pos_167);
  Function call may change dynamic type:_89 = lwip_htons (field16.72_88);
  Function call may change dynamic type:len_173 = pbuf_copy_partial (_90, &field16, 2, read_pos_171);
  Function call may change dynamic type:_92 = lwip_htons (field16.73_91);
  Function call may change dynamic type:len_177 = pbuf_copy_partial (_93, &field16, 2, read_pos_175);
  Function call may change dynamic type:_95 = lwip_htons (field16.74_94);
  Function call may change dynamic type:mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_181 = mdns_readname (_97, read_pos_179, &known_ans);
  Function call may change dynamic type:_98 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:len_189 = mdns_readname (_76, _77, &known_ans);
  Function call may change dynamic type:res_191 = mdns_build_service_domain (&my_ans, service_161, 0);
  Function call may change dynamic type:_79 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:res_195 = mdns_build_service_domain (&my_ans, service_161, 1);
  Function call may change dynamic type:_83 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:mdns_init_outpacket (&reply, pkt_136(D));
  Function call may change dynamic type:_219 = check_service (service_217, &q.info);
  Function call may change dynamic type:_209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  Function call may change dynamic type:res_206 = mdns_read_question (pkt_136(D), &q);
  Function call may change dynamic type:res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
  Function call may change dynamic type:res_152 = mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_150 = mdns_readname (_33, _34, &known_ans);
  Function call may change dynamic type:_35 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:_56 = pbuf_memcmp (_51, _52, _54, 4);
  Function call may change dynamic type:_66 = pbuf_memcmp (_61, _62, _64, 16);
Determining dynamic type for call: mdns_build_host_domain (&my_ans, mdns_137);
  Starting walk at: mdns_build_host_domain (&my_ans, mdns_137);
  instance pointer: &my_ans  Outer instance pointer: my_ans offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:len_181 = mdns_readname (_97, read_pos_179, &known_ans);
  Function call may change dynamic type:_95 = lwip_htons (field16.74_94);
  Function call may change dynamic type:len_177 = pbuf_copy_partial (_93, &field16, 2, read_pos_175);
  Function call may change dynamic type:_92 = lwip_htons (field16.73_91);
  Function call may change dynamic type:len_173 = pbuf_copy_partial (_90, &field16, 2, read_pos_171);
  Function call may change dynamic type:_89 = lwip_htons (field16.72_88);
  Function call may change dynamic type:len_169 = pbuf_copy_partial (_87, &field16, 2, read_pos_167);
  Function call may change dynamic type:_71 = check_service (service_161, &ans.info);
  Function call may change dynamic type:_28 = check_host (_27, &ans.info, &rev_v6);
  Function call may change dynamic type:res_141 = mdns_read_answer (pkt_136(D), &ans);
  Function call may change dynamic type:_71 = check_service (service_161, &ans.info);
  Function call may change dynamic type:_107 = pbuf_memcmp (_104, _105, _106, _103);
  Function call may change dynamic type:mdns_prepare_txtdata (service_161);
  Function call may change dynamic type:len_169 = pbuf_copy_partial (_87, &field16, 2, read_pos_167);
  Function call may change dynamic type:_89 = lwip_htons (field16.72_88);
  Function call may change dynamic type:len_173 = pbuf_copy_partial (_90, &field16, 2, read_pos_171);
  Function call may change dynamic type:_92 = lwip_htons (field16.73_91);
  Function call may change dynamic type:len_177 = pbuf_copy_partial (_93, &field16, 2, read_pos_175);
  Function call may change dynamic type:_95 = lwip_htons (field16.74_94);
  Function call may change dynamic type:mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_181 = mdns_readname (_97, read_pos_179, &known_ans);
  Function call may change dynamic type:_98 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:len_189 = mdns_readname (_76, _77, &known_ans);
  Function call may change dynamic type:res_191 = mdns_build_service_domain (&my_ans, service_161, 0);
  Function call may change dynamic type:_79 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:res_195 = mdns_build_service_domain (&my_ans, service_161, 1);
  Function call may change dynamic type:_83 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:mdns_init_outpacket (&reply, pkt_136(D));
  Function call may change dynamic type:_219 = check_service (service_217, &q.info);
  Function call may change dynamic type:_209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  Function call may change dynamic type:res_206 = mdns_read_question (pkt_136(D), &q);
  Function call may change dynamic type:res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
  Function call may change dynamic type:res_152 = mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_150 = mdns_readname (_33, _34, &known_ans);
  Function call may change dynamic type:_35 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:_56 = pbuf_memcmp (_51, _52, _54, 4);
  Function call may change dynamic type:_66 = pbuf_memcmp (_61, _62, _64, 16);
Determining dynamic type for call: mdns_build_host_domain (&my_ans, mdns_137);
  Starting walk at: mdns_build_host_domain (&my_ans, mdns_137);
  instance pointer: mdns_137  Outer instance pointer: mdns_137 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:len_181 = mdns_readname (_97, read_pos_179, &known_ans);
  Function call may change dynamic type:_95 = lwip_htons (field16.74_94);
  Function call may change dynamic type:len_177 = pbuf_copy_partial (_93, &field16, 2, read_pos_175);
  Function call may change dynamic type:_92 = lwip_htons (field16.73_91);
  Function call may change dynamic type:len_173 = pbuf_copy_partial (_90, &field16, 2, read_pos_171);
  Function call may change dynamic type:_89 = lwip_htons (field16.72_88);
  Function call may change dynamic type:len_169 = pbuf_copy_partial (_87, &field16, 2, read_pos_167);
  Function call may change dynamic type:_71 = check_service (service_161, &ans.info);
  Function call may change dynamic type:_28 = check_host (_27, &ans.info, &rev_v6);
  Function call may change dynamic type:res_141 = mdns_read_answer (pkt_136(D), &ans);
  Function call may change dynamic type:_71 = check_service (service_161, &ans.info);
  Function call may change dynamic type:_107 = pbuf_memcmp (_104, _105, _106, _103);
  Function call may change dynamic type:mdns_prepare_txtdata (service_161);
  Function call may change dynamic type:len_169 = pbuf_copy_partial (_87, &field16, 2, read_pos_167);
  Function call may change dynamic type:_89 = lwip_htons (field16.72_88);
  Function call may change dynamic type:len_173 = pbuf_copy_partial (_90, &field16, 2, read_pos_171);
  Function call may change dynamic type:_92 = lwip_htons (field16.73_91);
  Function call may change dynamic type:len_177 = pbuf_copy_partial (_93, &field16, 2, read_pos_175);
  Function call may change dynamic type:_95 = lwip_htons (field16.74_94);
  Function call may change dynamic type:mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_181 = mdns_readname (_97, read_pos_179, &known_ans);
  Function call may change dynamic type:_98 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:len_189 = mdns_readname (_76, _77, &known_ans);
  Function call may change dynamic type:res_191 = mdns_build_service_domain (&my_ans, service_161, 0);
  Function call may change dynamic type:_79 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:res_195 = mdns_build_service_domain (&my_ans, service_161, 1);
  Function call may change dynamic type:_83 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:mdns_init_outpacket (&reply, pkt_136(D));
  Function call may change dynamic type:_219 = check_service (service_217, &q.info);
  Function call may change dynamic type:_209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  Function call may change dynamic type:res_206 = mdns_read_question (pkt_136(D), &q);
  Function call may change dynamic type:res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
  Function call may change dynamic type:res_152 = mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_150 = mdns_readname (_33, _34, &known_ans);
  Function call may change dynamic type:_35 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:_56 = pbuf_memcmp (_51, _52, _54, 4);
  Function call may change dynamic type:_66 = pbuf_memcmp (_61, _62, _64, 16);
Determining dynamic type for call: _98 = mdns_domain_eq (&known_ans, &my_ans);
  Starting walk at: _98 = mdns_domain_eq (&known_ans, &my_ans);
  instance pointer: &known_ans  Outer instance pointer: known_ans offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_181 = mdns_readname (_97, read_pos_179, &known_ans);
  Function call may change dynamic type:_95 = lwip_htons (field16.74_94);
  Function call may change dynamic type:len_177 = pbuf_copy_partial (_93, &field16, 2, read_pos_175);
  Function call may change dynamic type:_92 = lwip_htons (field16.73_91);
  Function call may change dynamic type:len_173 = pbuf_copy_partial (_90, &field16, 2, read_pos_171);
  Function call may change dynamic type:_89 = lwip_htons (field16.72_88);
  Function call may change dynamic type:len_169 = pbuf_copy_partial (_87, &field16, 2, read_pos_167);
  Function call may change dynamic type:_71 = check_service (service_161, &ans.info);
  Function call may change dynamic type:_28 = check_host (_27, &ans.info, &rev_v6);
  Function call may change dynamic type:res_141 = mdns_read_answer (pkt_136(D), &ans);
  Function call may change dynamic type:_71 = check_service (service_161, &ans.info);
  Function call may change dynamic type:_107 = pbuf_memcmp (_104, _105, _106, _103);
  Function call may change dynamic type:mdns_prepare_txtdata (service_161);
  Function call may change dynamic type:len_169 = pbuf_copy_partial (_87, &field16, 2, read_pos_167);
  Function call may change dynamic type:_89 = lwip_htons (field16.72_88);
  Function call may change dynamic type:len_173 = pbuf_copy_partial (_90, &field16, 2, read_pos_171);
  Function call may change dynamic type:_92 = lwip_htons (field16.73_91);
  Function call may change dynamic type:len_177 = pbuf_copy_partial (_93, &field16, 2, read_pos_175);
  Function call may change dynamic type:_95 = lwip_htons (field16.74_94);
  Function call may change dynamic type:mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_181 = mdns_readname (_97, read_pos_179, &known_ans);
  Function call may change dynamic type:_98 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:len_189 = mdns_readname (_76, _77, &known_ans);
  Function call may change dynamic type:res_191 = mdns_build_service_domain (&my_ans, service_161, 0);
  Function call may change dynamic type:_79 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:res_195 = mdns_build_service_domain (&my_ans, service_161, 1);
  Function call may change dynamic type:_83 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:mdns_init_outpacket (&reply, pkt_136(D));
  Function call may change dynamic type:_219 = check_service (service_217, &q.info);
  Function call may change dynamic type:_209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  Function call may change dynamic type:res_206 = mdns_read_question (pkt_136(D), &q);
  Function call may change dynamic type:res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
  Function call may change dynamic type:res_152 = mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_150 = mdns_readname (_33, _34, &known_ans);
  Function call may change dynamic type:_35 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:_56 = pbuf_memcmp (_51, _52, _54, 4);
  Function call may change dynamic type:_66 = pbuf_memcmp (_61, _62, _64, 16);
Determining dynamic type for call: _98 = mdns_domain_eq (&known_ans, &my_ans);
  Starting walk at: _98 = mdns_domain_eq (&known_ans, &my_ans);
  instance pointer: &my_ans  Outer instance pointer: my_ans offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_181 = mdns_readname (_97, read_pos_179, &known_ans);
  Function call may change dynamic type:_95 = lwip_htons (field16.74_94);
  Function call may change dynamic type:len_177 = pbuf_copy_partial (_93, &field16, 2, read_pos_175);
  Function call may change dynamic type:_92 = lwip_htons (field16.73_91);
  Function call may change dynamic type:len_173 = pbuf_copy_partial (_90, &field16, 2, read_pos_171);
  Function call may change dynamic type:_89 = lwip_htons (field16.72_88);
  Function call may change dynamic type:len_169 = pbuf_copy_partial (_87, &field16, 2, read_pos_167);
  Function call may change dynamic type:_71 = check_service (service_161, &ans.info);
  Function call may change dynamic type:_28 = check_host (_27, &ans.info, &rev_v6);
  Function call may change dynamic type:res_141 = mdns_read_answer (pkt_136(D), &ans);
  Function call may change dynamic type:_71 = check_service (service_161, &ans.info);
  Function call may change dynamic type:_107 = pbuf_memcmp (_104, _105, _106, _103);
  Function call may change dynamic type:mdns_prepare_txtdata (service_161);
  Function call may change dynamic type:len_169 = pbuf_copy_partial (_87, &field16, 2, read_pos_167);
  Function call may change dynamic type:_89 = lwip_htons (field16.72_88);
  Function call may change dynamic type:len_173 = pbuf_copy_partial (_90, &field16, 2, read_pos_171);
  Function call may change dynamic type:_92 = lwip_htons (field16.73_91);
  Function call may change dynamic type:len_177 = pbuf_copy_partial (_93, &field16, 2, read_pos_175);
  Function call may change dynamic type:_95 = lwip_htons (field16.74_94);
  Function call may change dynamic type:mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_181 = mdns_readname (_97, read_pos_179, &known_ans);
  Function call may change dynamic type:_98 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:len_189 = mdns_readname (_76, _77, &known_ans);
  Function call may change dynamic type:res_191 = mdns_build_service_domain (&my_ans, service_161, 0);
  Function call may change dynamic type:_79 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:res_195 = mdns_build_service_domain (&my_ans, service_161, 1);
  Function call may change dynamic type:_83 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:mdns_init_outpacket (&reply, pkt_136(D));
  Function call may change dynamic type:_219 = check_service (service_217, &q.info);
  Function call may change dynamic type:_209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  Function call may change dynamic type:res_206 = mdns_read_question (pkt_136(D), &q);
  Function call may change dynamic type:res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
  Function call may change dynamic type:res_152 = mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_150 = mdns_readname (_33, _34, &known_ans);
  Function call may change dynamic type:_35 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:_56 = pbuf_memcmp (_51, _52, _54, 4);
  Function call may change dynamic type:_66 = pbuf_memcmp (_61, _62, _64, 16);
Determining dynamic type for call: len_189 = mdns_readname (_76, _77, &known_ans);
  Starting walk at: len_189 = mdns_readname (_76, _77, &known_ans);
  instance pointer: _76  Outer instance pointer: _76 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_71 = check_service (service_161, &ans.info);
  Function call may change dynamic type:_28 = check_host (_27, &ans.info, &rev_v6);
  Function call may change dynamic type:res_141 = mdns_read_answer (pkt_136(D), &ans);
  Function call may change dynamic type:_71 = check_service (service_161, &ans.info);
  Function call may change dynamic type:_107 = pbuf_memcmp (_104, _105, _106, _103);
  Function call may change dynamic type:mdns_prepare_txtdata (service_161);
  Function call may change dynamic type:len_169 = pbuf_copy_partial (_87, &field16, 2, read_pos_167);
  Function call may change dynamic type:_89 = lwip_htons (field16.72_88);
  Function call may change dynamic type:len_173 = pbuf_copy_partial (_90, &field16, 2, read_pos_171);
  Function call may change dynamic type:_92 = lwip_htons (field16.73_91);
  Function call may change dynamic type:len_177 = pbuf_copy_partial (_93, &field16, 2, read_pos_175);
  Function call may change dynamic type:_95 = lwip_htons (field16.74_94);
  Function call may change dynamic type:mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_181 = mdns_readname (_97, read_pos_179, &known_ans);
  Function call may change dynamic type:_98 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:len_189 = mdns_readname (_76, _77, &known_ans);
  Function call may change dynamic type:res_191 = mdns_build_service_domain (&my_ans, service_161, 0);
  Function call may change dynamic type:_79 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:res_195 = mdns_build_service_domain (&my_ans, service_161, 1);
  Function call may change dynamic type:_83 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:mdns_init_outpacket (&reply, pkt_136(D));
  Function call may change dynamic type:_219 = check_service (service_217, &q.info);
  Function call may change dynamic type:_209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  Function call may change dynamic type:res_206 = mdns_read_question (pkt_136(D), &q);
  Function call may change dynamic type:res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
  Function call may change dynamic type:res_152 = mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_150 = mdns_readname (_33, _34, &known_ans);
  Function call may change dynamic type:_35 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:_56 = pbuf_memcmp (_51, _52, _54, 4);
  Function call may change dynamic type:_66 = pbuf_memcmp (_61, _62, _64, 16);
Determining dynamic type for call: len_189 = mdns_readname (_76, _77, &known_ans);
  Starting walk at: len_189 = mdns_readname (_76, _77, &known_ans);
  instance pointer: &known_ans  Outer instance pointer: known_ans offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_71 = check_service (service_161, &ans.info);
  Function call may change dynamic type:_28 = check_host (_27, &ans.info, &rev_v6);
  Function call may change dynamic type:res_141 = mdns_read_answer (pkt_136(D), &ans);
  Function call may change dynamic type:_71 = check_service (service_161, &ans.info);
  Function call may change dynamic type:_107 = pbuf_memcmp (_104, _105, _106, _103);
  Function call may change dynamic type:mdns_prepare_txtdata (service_161);
  Function call may change dynamic type:len_169 = pbuf_copy_partial (_87, &field16, 2, read_pos_167);
  Function call may change dynamic type:_89 = lwip_htons (field16.72_88);
  Function call may change dynamic type:len_173 = pbuf_copy_partial (_90, &field16, 2, read_pos_171);
  Function call may change dynamic type:_92 = lwip_htons (field16.73_91);
  Function call may change dynamic type:len_177 = pbuf_copy_partial (_93, &field16, 2, read_pos_175);
  Function call may change dynamic type:_95 = lwip_htons (field16.74_94);
  Function call may change dynamic type:mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_181 = mdns_readname (_97, read_pos_179, &known_ans);
  Function call may change dynamic type:_98 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:len_189 = mdns_readname (_76, _77, &known_ans);
  Function call may change dynamic type:res_191 = mdns_build_service_domain (&my_ans, service_161, 0);
  Function call may change dynamic type:_79 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:res_195 = mdns_build_service_domain (&my_ans, service_161, 1);
  Function call may change dynamic type:_83 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:mdns_init_outpacket (&reply, pkt_136(D));
  Function call may change dynamic type:_219 = check_service (service_217, &q.info);
  Function call may change dynamic type:_209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  Function call may change dynamic type:res_206 = mdns_read_question (pkt_136(D), &q);
  Function call may change dynamic type:res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
  Function call may change dynamic type:res_152 = mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_150 = mdns_readname (_33, _34, &known_ans);
  Function call may change dynamic type:_35 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:_56 = pbuf_memcmp (_51, _52, _54, 4);
  Function call may change dynamic type:_66 = pbuf_memcmp (_61, _62, _64, 16);
Determining dynamic type for call: res_191 = mdns_build_service_domain (&my_ans, service_161, 0);
  Starting walk at: res_191 = mdns_build_service_domain (&my_ans, service_161, 0);
  instance pointer: &my_ans  Outer instance pointer: my_ans offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:len_189 = mdns_readname (_76, _77, &known_ans);
  Function call may change dynamic type:_71 = check_service (service_161, &ans.info);
  Function call may change dynamic type:_28 = check_host (_27, &ans.info, &rev_v6);
  Function call may change dynamic type:res_141 = mdns_read_answer (pkt_136(D), &ans);
  Function call may change dynamic type:_71 = check_service (service_161, &ans.info);
  Function call may change dynamic type:_107 = pbuf_memcmp (_104, _105, _106, _103);
  Function call may change dynamic type:mdns_prepare_txtdata (service_161);
  Function call may change dynamic type:len_169 = pbuf_copy_partial (_87, &field16, 2, read_pos_167);
  Function call may change dynamic type:_89 = lwip_htons (field16.72_88);
  Function call may change dynamic type:len_173 = pbuf_copy_partial (_90, &field16, 2, read_pos_171);
  Function call may change dynamic type:_92 = lwip_htons (field16.73_91);
  Function call may change dynamic type:len_177 = pbuf_copy_partial (_93, &field16, 2, read_pos_175);
  Function call may change dynamic type:_95 = lwip_htons (field16.74_94);
  Function call may change dynamic type:mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_181 = mdns_readname (_97, read_pos_179, &known_ans);
  Function call may change dynamic type:_98 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:len_189 = mdns_readname (_76, _77, &known_ans);
  Function call may change dynamic type:res_191 = mdns_build_service_domain (&my_ans, service_161, 0);
  Function call may change dynamic type:_79 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:res_195 = mdns_build_service_domain (&my_ans, service_161, 1);
  Function call may change dynamic type:_83 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:mdns_init_outpacket (&reply, pkt_136(D));
  Function call may change dynamic type:_219 = check_service (service_217, &q.info);
  Function call may change dynamic type:_209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  Function call may change dynamic type:res_206 = mdns_read_question (pkt_136(D), &q);
  Function call may change dynamic type:res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
  Function call may change dynamic type:res_152 = mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_150 = mdns_readname (_33, _34, &known_ans);
  Function call may change dynamic type:_35 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:_56 = pbuf_memcmp (_51, _52, _54, 4);
  Function call may change dynamic type:_66 = pbuf_memcmp (_61, _62, _64, 16);
Determining dynamic type for call: res_191 = mdns_build_service_domain (&my_ans, service_161, 0);
  Starting walk at: res_191 = mdns_build_service_domain (&my_ans, service_161, 0);
  instance pointer: service_161  Outer instance pointer: service_161 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:len_189 = mdns_readname (_76, _77, &known_ans);
  Function call may change dynamic type:_71 = check_service (service_161, &ans.info);
  Function call may change dynamic type:_28 = check_host (_27, &ans.info, &rev_v6);
  Function call may change dynamic type:res_141 = mdns_read_answer (pkt_136(D), &ans);
  Function call may change dynamic type:_71 = check_service (service_161, &ans.info);
  Function call may change dynamic type:_107 = pbuf_memcmp (_104, _105, _106, _103);
  Function call may change dynamic type:mdns_prepare_txtdata (service_161);
  Function call may change dynamic type:len_169 = pbuf_copy_partial (_87, &field16, 2, read_pos_167);
  Function call may change dynamic type:_89 = lwip_htons (field16.72_88);
  Function call may change dynamic type:len_173 = pbuf_copy_partial (_90, &field16, 2, read_pos_171);
  Function call may change dynamic type:_92 = lwip_htons (field16.73_91);
  Function call may change dynamic type:len_177 = pbuf_copy_partial (_93, &field16, 2, read_pos_175);
  Function call may change dynamic type:_95 = lwip_htons (field16.74_94);
  Function call may change dynamic type:mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_181 = mdns_readname (_97, read_pos_179, &known_ans);
  Function call may change dynamic type:_98 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:len_189 = mdns_readname (_76, _77, &known_ans);
  Function call may change dynamic type:res_191 = mdns_build_service_domain (&my_ans, service_161, 0);
  Function call may change dynamic type:_79 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:res_195 = mdns_build_service_domain (&my_ans, service_161, 1);
  Function call may change dynamic type:_83 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:mdns_init_outpacket (&reply, pkt_136(D));
  Function call may change dynamic type:_219 = check_service (service_217, &q.info);
  Function call may change dynamic type:_209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  Function call may change dynamic type:res_206 = mdns_read_question (pkt_136(D), &q);
  Function call may change dynamic type:res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
  Function call may change dynamic type:res_152 = mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_150 = mdns_readname (_33, _34, &known_ans);
  Function call may change dynamic type:_35 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:_56 = pbuf_memcmp (_51, _52, _54, 4);
  Function call may change dynamic type:_66 = pbuf_memcmp (_61, _62, _64, 16);
Determining dynamic type for call: _79 = mdns_domain_eq (&known_ans, &my_ans);
  Starting walk at: _79 = mdns_domain_eq (&known_ans, &my_ans);
  instance pointer: &known_ans  Outer instance pointer: known_ans offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_191 = mdns_build_service_domain (&my_ans, service_161, 0);
  Function call may change dynamic type:len_189 = mdns_readname (_76, _77, &known_ans);
  Function call may change dynamic type:_71 = check_service (service_161, &ans.info);
  Function call may change dynamic type:_28 = check_host (_27, &ans.info, &rev_v6);
  Function call may change dynamic type:res_141 = mdns_read_answer (pkt_136(D), &ans);
  Function call may change dynamic type:_71 = check_service (service_161, &ans.info);
  Function call may change dynamic type:_107 = pbuf_memcmp (_104, _105, _106, _103);
  Function call may change dynamic type:mdns_prepare_txtdata (service_161);
  Function call may change dynamic type:len_169 = pbuf_copy_partial (_87, &field16, 2, read_pos_167);
  Function call may change dynamic type:_89 = lwip_htons (field16.72_88);
  Function call may change dynamic type:len_173 = pbuf_copy_partial (_90, &field16, 2, read_pos_171);
  Function call may change dynamic type:_92 = lwip_htons (field16.73_91);
  Function call may change dynamic type:len_177 = pbuf_copy_partial (_93, &field16, 2, read_pos_175);
  Function call may change dynamic type:_95 = lwip_htons (field16.74_94);
  Function call may change dynamic type:mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_181 = mdns_readname (_97, read_pos_179, &known_ans);
  Function call may change dynamic type:_98 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:len_189 = mdns_readname (_76, _77, &known_ans);
  Function call may change dynamic type:res_191 = mdns_build_service_domain (&my_ans, service_161, 0);
  Function call may change dynamic type:_79 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:res_195 = mdns_build_service_domain (&my_ans, service_161, 1);
  Function call may change dynamic type:_83 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:mdns_init_outpacket (&reply, pkt_136(D));
  Function call may change dynamic type:_219 = check_service (service_217, &q.info);
  Function call may change dynamic type:_209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  Function call may change dynamic type:res_206 = mdns_read_question (pkt_136(D), &q);
  Function call may change dynamic type:res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
  Function call may change dynamic type:res_152 = mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_150 = mdns_readname (_33, _34, &known_ans);
  Function call may change dynamic type:_35 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:_56 = pbuf_memcmp (_51, _52, _54, 4);
  Function call may change dynamic type:_66 = pbuf_memcmp (_61, _62, _64, 16);
Determining dynamic type for call: _79 = mdns_domain_eq (&known_ans, &my_ans);
  Starting walk at: _79 = mdns_domain_eq (&known_ans, &my_ans);
  instance pointer: &my_ans  Outer instance pointer: my_ans offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_191 = mdns_build_service_domain (&my_ans, service_161, 0);
  Function call may change dynamic type:len_189 = mdns_readname (_76, _77, &known_ans);
  Function call may change dynamic type:_71 = check_service (service_161, &ans.info);
  Function call may change dynamic type:_28 = check_host (_27, &ans.info, &rev_v6);
  Function call may change dynamic type:res_141 = mdns_read_answer (pkt_136(D), &ans);
  Function call may change dynamic type:_71 = check_service (service_161, &ans.info);
  Function call may change dynamic type:_107 = pbuf_memcmp (_104, _105, _106, _103);
  Function call may change dynamic type:mdns_prepare_txtdata (service_161);
  Function call may change dynamic type:len_169 = pbuf_copy_partial (_87, &field16, 2, read_pos_167);
  Function call may change dynamic type:_89 = lwip_htons (field16.72_88);
  Function call may change dynamic type:len_173 = pbuf_copy_partial (_90, &field16, 2, read_pos_171);
  Function call may change dynamic type:_92 = lwip_htons (field16.73_91);
  Function call may change dynamic type:len_177 = pbuf_copy_partial (_93, &field16, 2, read_pos_175);
  Function call may change dynamic type:_95 = lwip_htons (field16.74_94);
  Function call may change dynamic type:mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_181 = mdns_readname (_97, read_pos_179, &known_ans);
  Function call may change dynamic type:_98 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:len_189 = mdns_readname (_76, _77, &known_ans);
  Function call may change dynamic type:res_191 = mdns_build_service_domain (&my_ans, service_161, 0);
  Function call may change dynamic type:_79 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:res_195 = mdns_build_service_domain (&my_ans, service_161, 1);
  Function call may change dynamic type:_83 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:mdns_init_outpacket (&reply, pkt_136(D));
  Function call may change dynamic type:_219 = check_service (service_217, &q.info);
  Function call may change dynamic type:_209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  Function call may change dynamic type:res_206 = mdns_read_question (pkt_136(D), &q);
  Function call may change dynamic type:res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
  Function call may change dynamic type:res_152 = mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_150 = mdns_readname (_33, _34, &known_ans);
  Function call may change dynamic type:_35 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:_56 = pbuf_memcmp (_51, _52, _54, 4);
  Function call may change dynamic type:_66 = pbuf_memcmp (_61, _62, _64, 16);
Determining dynamic type for call: res_195 = mdns_build_service_domain (&my_ans, service_161, 1);
  Starting walk at: res_195 = mdns_build_service_domain (&my_ans, service_161, 1);
  instance pointer: &my_ans  Outer instance pointer: my_ans offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:len_189 = mdns_readname (_76, _77, &known_ans);
  Function call may change dynamic type:_71 = check_service (service_161, &ans.info);
  Function call may change dynamic type:_28 = check_host (_27, &ans.info, &rev_v6);
  Function call may change dynamic type:res_141 = mdns_read_answer (pkt_136(D), &ans);
  Function call may change dynamic type:mdns_init_outpacket (&reply, pkt_136(D));
  Function call may change dynamic type:_219 = check_service (service_217, &q.info);
  Function call may change dynamic type:_209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  Function call may change dynamic type:res_206 = mdns_read_question (pkt_136(D), &q);
  Function call may change dynamic type:res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
  Function call may change dynamic type:res_152 = mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_150 = mdns_readname (_33, _34, &known_ans);
  Function call may change dynamic type:_35 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:_56 = pbuf_memcmp (_51, _52, _54, 4);
  Function call may change dynamic type:_66 = pbuf_memcmp (_61, _62, _64, 16);
  Function call may change dynamic type:_107 = pbuf_memcmp (_104, _105, _106, _103);
  Function call may change dynamic type:mdns_prepare_txtdata (service_161);
  Function call may change dynamic type:len_169 = pbuf_copy_partial (_87, &field16, 2, read_pos_167);
  Function call may change dynamic type:_89 = lwip_htons (field16.72_88);
  Function call may change dynamic type:len_173 = pbuf_copy_partial (_90, &field16, 2, read_pos_171);
  Function call may change dynamic type:_92 = lwip_htons (field16.73_91);
  Function call may change dynamic type:len_177 = pbuf_copy_partial (_93, &field16, 2, read_pos_175);
  Function call may change dynamic type:_95 = lwip_htons (field16.74_94);
  Function call may change dynamic type:mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_181 = mdns_readname (_97, read_pos_179, &known_ans);
  Function call may change dynamic type:_98 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:res_191 = mdns_build_service_domain (&my_ans, service_161, 0);
  Function call may change dynamic type:_79 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:res_195 = mdns_build_service_domain (&my_ans, service_161, 1);
  Function call may change dynamic type:_83 = mdns_domain_eq (&known_ans, &my_ans);
Determining dynamic type for call: res_195 = mdns_build_service_domain (&my_ans, service_161, 1);
  Starting walk at: res_195 = mdns_build_service_domain (&my_ans, service_161, 1);
  instance pointer: service_161  Outer instance pointer: service_161 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:len_189 = mdns_readname (_76, _77, &known_ans);
  Function call may change dynamic type:_71 = check_service (service_161, &ans.info);
  Function call may change dynamic type:_28 = check_host (_27, &ans.info, &rev_v6);
  Function call may change dynamic type:res_141 = mdns_read_answer (pkt_136(D), &ans);
  Function call may change dynamic type:mdns_init_outpacket (&reply, pkt_136(D));
  Function call may change dynamic type:_219 = check_service (service_217, &q.info);
  Function call may change dynamic type:_209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  Function call may change dynamic type:res_206 = mdns_read_question (pkt_136(D), &q);
  Function call may change dynamic type:res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
  Function call may change dynamic type:res_152 = mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_150 = mdns_readname (_33, _34, &known_ans);
  Function call may change dynamic type:_35 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:_56 = pbuf_memcmp (_51, _52, _54, 4);
  Function call may change dynamic type:_66 = pbuf_memcmp (_61, _62, _64, 16);
  Function call may change dynamic type:_107 = pbuf_memcmp (_104, _105, _106, _103);
  Function call may change dynamic type:mdns_prepare_txtdata (service_161);
  Function call may change dynamic type:len_169 = pbuf_copy_partial (_87, &field16, 2, read_pos_167);
  Function call may change dynamic type:_89 = lwip_htons (field16.72_88);
  Function call may change dynamic type:len_173 = pbuf_copy_partial (_90, &field16, 2, read_pos_171);
  Function call may change dynamic type:_92 = lwip_htons (field16.73_91);
  Function call may change dynamic type:len_177 = pbuf_copy_partial (_93, &field16, 2, read_pos_175);
  Function call may change dynamic type:_95 = lwip_htons (field16.74_94);
  Function call may change dynamic type:mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_181 = mdns_readname (_97, read_pos_179, &known_ans);
  Function call may change dynamic type:_98 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:res_191 = mdns_build_service_domain (&my_ans, service_161, 0);
  Function call may change dynamic type:_79 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:res_195 = mdns_build_service_domain (&my_ans, service_161, 1);
  Function call may change dynamic type:_83 = mdns_domain_eq (&known_ans, &my_ans);
Determining dynamic type for call: _83 = mdns_domain_eq (&known_ans, &my_ans);
  Starting walk at: _83 = mdns_domain_eq (&known_ans, &my_ans);
  instance pointer: &known_ans  Outer instance pointer: known_ans offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_195 = mdns_build_service_domain (&my_ans, service_161, 1);
  Function call may change dynamic type:len_189 = mdns_readname (_76, _77, &known_ans);
  Function call may change dynamic type:_71 = check_service (service_161, &ans.info);
  Function call may change dynamic type:_28 = check_host (_27, &ans.info, &rev_v6);
  Function call may change dynamic type:res_141 = mdns_read_answer (pkt_136(D), &ans);
  Function call may change dynamic type:mdns_init_outpacket (&reply, pkt_136(D));
  Function call may change dynamic type:_219 = check_service (service_217, &q.info);
  Function call may change dynamic type:_209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  Function call may change dynamic type:res_206 = mdns_read_question (pkt_136(D), &q);
  Function call may change dynamic type:res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
  Function call may change dynamic type:res_152 = mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_150 = mdns_readname (_33, _34, &known_ans);
  Function call may change dynamic type:_35 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:_56 = pbuf_memcmp (_51, _52, _54, 4);
  Function call may change dynamic type:_66 = pbuf_memcmp (_61, _62, _64, 16);
  Function call may change dynamic type:_107 = pbuf_memcmp (_104, _105, _106, _103);
  Function call may change dynamic type:mdns_prepare_txtdata (service_161);
  Function call may change dynamic type:len_169 = pbuf_copy_partial (_87, &field16, 2, read_pos_167);
  Function call may change dynamic type:_89 = lwip_htons (field16.72_88);
  Function call may change dynamic type:len_173 = pbuf_copy_partial (_90, &field16, 2, read_pos_171);
  Function call may change dynamic type:_92 = lwip_htons (field16.73_91);
  Function call may change dynamic type:len_177 = pbuf_copy_partial (_93, &field16, 2, read_pos_175);
  Function call may change dynamic type:_95 = lwip_htons (field16.74_94);
  Function call may change dynamic type:mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_181 = mdns_readname (_97, read_pos_179, &known_ans);
  Function call may change dynamic type:_98 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:res_191 = mdns_build_service_domain (&my_ans, service_161, 0);
  Function call may change dynamic type:_79 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:res_195 = mdns_build_service_domain (&my_ans, service_161, 1);
  Function call may change dynamic type:_83 = mdns_domain_eq (&known_ans, &my_ans);
Determining dynamic type for call: _83 = mdns_domain_eq (&known_ans, &my_ans);
  Starting walk at: _83 = mdns_domain_eq (&known_ans, &my_ans);
  instance pointer: &my_ans  Outer instance pointer: my_ans offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_195 = mdns_build_service_domain (&my_ans, service_161, 1);
  Function call may change dynamic type:len_189 = mdns_readname (_76, _77, &known_ans);
  Function call may change dynamic type:_71 = check_service (service_161, &ans.info);
  Function call may change dynamic type:_28 = check_host (_27, &ans.info, &rev_v6);
  Function call may change dynamic type:res_141 = mdns_read_answer (pkt_136(D), &ans);
  Function call may change dynamic type:mdns_init_outpacket (&reply, pkt_136(D));
  Function call may change dynamic type:_219 = check_service (service_217, &q.info);
  Function call may change dynamic type:_209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  Function call may change dynamic type:res_206 = mdns_read_question (pkt_136(D), &q);
  Function call may change dynamic type:res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
  Function call may change dynamic type:res_152 = mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_150 = mdns_readname (_33, _34, &known_ans);
  Function call may change dynamic type:_35 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:_56 = pbuf_memcmp (_51, _52, _54, 4);
  Function call may change dynamic type:_66 = pbuf_memcmp (_61, _62, _64, 16);
  Function call may change dynamic type:_107 = pbuf_memcmp (_104, _105, _106, _103);
  Function call may change dynamic type:mdns_prepare_txtdata (service_161);
  Function call may change dynamic type:len_169 = pbuf_copy_partial (_87, &field16, 2, read_pos_167);
  Function call may change dynamic type:_89 = lwip_htons (field16.72_88);
  Function call may change dynamic type:len_173 = pbuf_copy_partial (_90, &field16, 2, read_pos_171);
  Function call may change dynamic type:_92 = lwip_htons (field16.73_91);
  Function call may change dynamic type:len_177 = pbuf_copy_partial (_93, &field16, 2, read_pos_175);
  Function call may change dynamic type:_95 = lwip_htons (field16.74_94);
  Function call may change dynamic type:mdns_build_host_domain (&my_ans, mdns_137);
  Function call may change dynamic type:len_181 = mdns_readname (_97, read_pos_179, &known_ans);
  Function call may change dynamic type:_98 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:res_191 = mdns_build_service_domain (&my_ans, service_161, 0);
  Function call may change dynamic type:_79 = mdns_domain_eq (&known_ans, &my_ans);
  Function call may change dynamic type:res_195 = mdns_build_service_domain (&my_ans, service_161, 1);
  Function call may change dynamic type:_83 = mdns_domain_eq (&known_ans, &my_ans);
Determining dynamic type for call: res_206 = mdns_read_question (pkt_136(D), &q);
  Starting walk at: res_206 = mdns_read_question (pkt_136(D), &q);
  instance pointer: pkt_136(D)  Outer instance pointer: pkt_136(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_init_outpacket (&reply, pkt_136(D));
  Function call may change dynamic type:_219 = check_service (service_217, &q.info);
  Function call may change dynamic type:_209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  Function call may change dynamic type:res_206 = mdns_read_question (pkt_136(D), &q);
  Function call may change dynamic type:res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
Determining dynamic type for call: res_206 = mdns_read_question (pkt_136(D), &q);
  Starting walk at: res_206 = mdns_read_question (pkt_136(D), &q);
  instance pointer: &q  Outer instance pointer: q offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_init_outpacket (&reply, pkt_136(D));
  Function call may change dynamic type:_219 = check_service (service_217, &q.info);
  Function call may change dynamic type:_209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  Function call may change dynamic type:res_206 = mdns_read_question (pkt_136(D), &q);
  Function call may change dynamic type:res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
Determining dynamic type for call: mdns_domain_debug_print (&q.info.domain);
  Starting walk at: mdns_domain_debug_print (&q.info.domain);
  instance pointer: &q.info.domain  Outer instance pointer: q offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_206 = mdns_read_question (pkt_136(D), &q);
  Function call may change dynamic type:mdns_init_outpacket (&reply, pkt_136(D));
  Function call may change dynamic type:_219 = check_service (service_217, &q.info);
  Function call may change dynamic type:_209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  Function call may change dynamic type:res_206 = mdns_read_question (pkt_136(D), &q);
  Function call may change dynamic type:res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
Determining dynamic type for call: _209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  Starting walk at: _209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  instance pointer: _6  Outer instance pointer: _6 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_206 = mdns_read_question (pkt_136(D), &q);
  Function call may change dynamic type:mdns_init_outpacket (&reply, pkt_136(D));
  Function call may change dynamic type:_219 = check_service (service_217, &q.info);
  Function call may change dynamic type:_209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  Function call may change dynamic type:res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
Determining dynamic type for call: _209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  Starting walk at: _209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  instance pointer: &q.info  Outer instance pointer: q offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_206 = mdns_read_question (pkt_136(D), &q);
  Function call may change dynamic type:mdns_init_outpacket (&reply, pkt_136(D));
  Function call may change dynamic type:_219 = check_service (service_217, &q.info);
  Function call may change dynamic type:_209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  Function call may change dynamic type:res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
Determining dynamic type for call: _209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  Starting walk at: _209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  instance pointer: &reply.host_reverse_v6_replies  Outer instance pointer: reply offset: 560 (bits) vtbl reference: 
  Function call may change dynamic type:res_206 = mdns_read_question (pkt_136(D), &q);
  Function call may change dynamic type:mdns_init_outpacket (&reply, pkt_136(D));
  Function call may change dynamic type:_219 = check_service (service_217, &q.info);
  Function call may change dynamic type:_209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  Function call may change dynamic type:res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
Determining dynamic type for call: res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
  Starting walk at: res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
  instance pointer: &reply  Outer instance pointer: reply offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  Function call may change dynamic type:res_206 = mdns_read_question (pkt_136(D), &q);
  Function call may change dynamic type:mdns_init_outpacket (&reply, pkt_136(D));
  Function call may change dynamic type:res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
  Function call may change dynamic type:_219 = check_service (service_217, &q.info);
Determining dynamic type for call: res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
  Starting walk at: res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
  instance pointer: &q.info.domain  Outer instance pointer: q offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  Function call may change dynamic type:res_206 = mdns_read_question (pkt_136(D), &q);
  Function call may change dynamic type:mdns_init_outpacket (&reply, pkt_136(D));
  Function call may change dynamic type:res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
  Function call may change dynamic type:_219 = check_service (service_217, &q.info);
Determining dynamic type for call: _219 = check_service (service_217, &q.info);
  Starting walk at: _219 = check_service (service_217, &q.info);
  instance pointer: service_217  Outer instance pointer: service_217 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  Function call may change dynamic type:res_206 = mdns_read_question (pkt_136(D), &q);
  Function call may change dynamic type:mdns_init_outpacket (&reply, pkt_136(D));
  Function call may change dynamic type:res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
  Function call may change dynamic type:_219 = check_service (service_217, &q.info);
Determining dynamic type for call: _219 = check_service (service_217, &q.info);
  Starting walk at: _219 = check_service (service_217, &q.info);
  instance pointer: &q.info  Outer instance pointer: q offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  Function call may change dynamic type:res_206 = mdns_read_question (pkt_136(D), &q);
  Function call may change dynamic type:mdns_init_outpacket (&reply, pkt_136(D));
  Function call may change dynamic type:res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
  Function call may change dynamic type:_219 = check_service (service_217, &q.info);
Determining dynamic type for call: mdns_send_outpacket (&announce, 132);
  Starting walk at: mdns_send_outpacket (&announce, 132);
  instance pointer: &announce  Outer instance pointer: announce offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: res_178 = mdns_add_a_answer (outpkt_174(D), _6, _1);
  Starting walk at: res_178 = mdns_add_a_answer (outpkt_174(D), _6, _1);
  instance pointer: outpkt_174(D)  Outer instance pointer: outpkt_174(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: res_178 = mdns_add_a_answer (outpkt_174(D), _6, _1);
  Starting walk at: res_178 = mdns_add_a_answer (outpkt_174(D), _6, _1);
  instance pointer: _1  Outer instance pointer: _1 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: res_181 = mdns_add_hostv4_ptr_answer (outpkt_174(D), _11, _12);
  Starting walk at: res_181 = mdns_add_hostv4_ptr_answer (outpkt_174(D), _11, _12);
  instance pointer: outpkt_174(D)  Outer instance pointer: outpkt_174(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_178 = mdns_add_a_answer (outpkt_174(D), _6, _1);
Determining dynamic type for call: res_181 = mdns_add_hostv4_ptr_answer (outpkt_174(D), _11, _12);
  Starting walk at: res_181 = mdns_add_hostv4_ptr_answer (outpkt_174(D), _11, _12);
  instance pointer: _12  Outer instance pointer: _12 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_178 = mdns_add_a_answer (outpkt_174(D), _6, _1);
Determining dynamic type for call: res_185 = mdns_add_aaaa_answer (outpkt_174(D), _18, _15, addrindex_143);
  Starting walk at: res_185 = mdns_add_aaaa_answer (outpkt_174(D), _18, _15, addrindex_143);
  instance pointer: outpkt_174(D)  Outer instance pointer: outpkt_174(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_178 = mdns_add_a_answer (outpkt_174(D), _6, _1);
  Function call may change dynamic type:res_181 = mdns_add_hostv4_ptr_answer (outpkt_174(D), _11, _12);
  Function call may change dynamic type:res_185 = mdns_add_aaaa_answer (outpkt_174(D), _18, _15, addrindex_143);
Determining dynamic type for call: res_185 = mdns_add_aaaa_answer (outpkt_174(D), _18, _15, addrindex_143);
  Starting walk at: res_185 = mdns_add_aaaa_answer (outpkt_174(D), _18, _15, addrindex_143);
  instance pointer: _15  Outer instance pointer: _15 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_178 = mdns_add_a_answer (outpkt_174(D), _6, _1);
  Function call may change dynamic type:res_181 = mdns_add_hostv4_ptr_answer (outpkt_174(D), _11, _12);
  Function call may change dynamic type:res_185 = mdns_add_aaaa_answer (outpkt_174(D), _18, _15, addrindex_143);
Determining dynamic type for call: res_191 = mdns_add_hostv6_ptr_answer (outpkt_174(D), _23, _24, addrindex_145);
  Starting walk at: res_191 = mdns_add_hostv6_ptr_answer (outpkt_174(D), _23, _24, addrindex_145);
  instance pointer: outpkt_174(D)  Outer instance pointer: outpkt_174(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_178 = mdns_add_a_answer (outpkt_174(D), _6, _1);
  Function call may change dynamic type:res_181 = mdns_add_hostv4_ptr_answer (outpkt_174(D), _11, _12);
  Function call may change dynamic type:res_185 = mdns_add_aaaa_answer (outpkt_174(D), _18, _15, addrindex_143);
  Function call may change dynamic type:res_191 = mdns_add_hostv6_ptr_answer (outpkt_174(D), _23, _24, addrindex_145);
Determining dynamic type for call: res_191 = mdns_add_hostv6_ptr_answer (outpkt_174(D), _23, _24, addrindex_145);
  Starting walk at: res_191 = mdns_add_hostv6_ptr_answer (outpkt_174(D), _23, _24, addrindex_145);
  instance pointer: _24  Outer instance pointer: _24 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_178 = mdns_add_a_answer (outpkt_174(D), _6, _1);
  Function call may change dynamic type:res_181 = mdns_add_hostv4_ptr_answer (outpkt_174(D), _11, _12);
  Function call may change dynamic type:res_185 = mdns_add_aaaa_answer (outpkt_174(D), _18, _15, addrindex_143);
  Function call may change dynamic type:res_191 = mdns_add_hostv6_ptr_answer (outpkt_174(D), _23, _24, addrindex_145);
Determining dynamic type for call: res_223 = mdns_add_srv_answer (outpkt_174(D), _48, mdns_175, service_221);
  Starting walk at: res_223 = mdns_add_srv_answer (outpkt_174(D), _48, mdns_175, service_221);
  instance pointer: outpkt_174(D)  Outer instance pointer: outpkt_174(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_178 = mdns_add_a_answer (outpkt_174(D), _6, _1);
  Function call may change dynamic type:res_181 = mdns_add_hostv4_ptr_answer (outpkt_174(D), _11, _12);
  Function call may change dynamic type:res_185 = mdns_add_aaaa_answer (outpkt_174(D), _18, _15, addrindex_143);
  Function call may change dynamic type:res_191 = mdns_add_hostv6_ptr_answer (outpkt_174(D), _23, _24, addrindex_145);
  Function call may change dynamic type:res_248 = mdns_add_txt_answer (outpkt_174(D), _37, service_237);
  Function call may change dynamic type:res_239 = mdns_add_servicetype_ptr_answer (outpkt_174(D), service_237);
  Function call may change dynamic type:res_242 = mdns_add_servicename_ptr_answer (outpkt_174(D), service_237);
  Function call may change dynamic type:res_245 = mdns_add_srv_answer (outpkt_174(D), _32, mdns_175, service_237);
  Function call may change dynamic type:res_223 = mdns_add_srv_answer (outpkt_174(D), _48, mdns_175, service_221);
  Function call may change dynamic type:res_226 = mdns_add_txt_answer (outpkt_174(D), _55, service_221);
  Function call may change dynamic type:res_230 = mdns_add_aaaa_answer (outpkt_174(D), _65, _62, addrindex_146);
  Function call may change dynamic type:res_234 = mdns_add_a_answer (outpkt_174(D), _75, _71);
Determining dynamic type for call: res_223 = mdns_add_srv_answer (outpkt_174(D), _48, mdns_175, service_221);
  Starting walk at: res_223 = mdns_add_srv_answer (outpkt_174(D), _48, mdns_175, service_221);
  instance pointer: mdns_175  Outer instance pointer: mdns_175 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_178 = mdns_add_a_answer (outpkt_174(D), _6, _1);
  Function call may change dynamic type:res_181 = mdns_add_hostv4_ptr_answer (outpkt_174(D), _11, _12);
  Function call may change dynamic type:res_185 = mdns_add_aaaa_answer (outpkt_174(D), _18, _15, addrindex_143);
  Function call may change dynamic type:res_191 = mdns_add_hostv6_ptr_answer (outpkt_174(D), _23, _24, addrindex_145);
  Function call may change dynamic type:res_248 = mdns_add_txt_answer (outpkt_174(D), _37, service_237);
  Function call may change dynamic type:res_239 = mdns_add_servicetype_ptr_answer (outpkt_174(D), service_237);
  Function call may change dynamic type:res_242 = mdns_add_servicename_ptr_answer (outpkt_174(D), service_237);
  Function call may change dynamic type:res_245 = mdns_add_srv_answer (outpkt_174(D), _32, mdns_175, service_237);
  Function call may change dynamic type:res_223 = mdns_add_srv_answer (outpkt_174(D), _48, mdns_175, service_221);
  Function call may change dynamic type:res_226 = mdns_add_txt_answer (outpkt_174(D), _55, service_221);
  Function call may change dynamic type:res_230 = mdns_add_aaaa_answer (outpkt_174(D), _65, _62, addrindex_146);
  Function call may change dynamic type:res_234 = mdns_add_a_answer (outpkt_174(D), _75, _71);
Determining dynamic type for call: res_223 = mdns_add_srv_answer (outpkt_174(D), _48, mdns_175, service_221);
  Starting walk at: res_223 = mdns_add_srv_answer (outpkt_174(D), _48, mdns_175, service_221);
  instance pointer: service_221  Outer instance pointer: service_221 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_178 = mdns_add_a_answer (outpkt_174(D), _6, _1);
  Function call may change dynamic type:res_181 = mdns_add_hostv4_ptr_answer (outpkt_174(D), _11, _12);
  Function call may change dynamic type:res_185 = mdns_add_aaaa_answer (outpkt_174(D), _18, _15, addrindex_143);
  Function call may change dynamic type:res_191 = mdns_add_hostv6_ptr_answer (outpkt_174(D), _23, _24, addrindex_145);
  Function call may change dynamic type:res_248 = mdns_add_txt_answer (outpkt_174(D), _37, service_237);
  Function call may change dynamic type:res_239 = mdns_add_servicetype_ptr_answer (outpkt_174(D), service_237);
  Function call may change dynamic type:res_242 = mdns_add_servicename_ptr_answer (outpkt_174(D), service_237);
  Function call may change dynamic type:res_245 = mdns_add_srv_answer (outpkt_174(D), _32, mdns_175, service_237);
  Function call may change dynamic type:res_223 = mdns_add_srv_answer (outpkt_174(D), _48, mdns_175, service_221);
  Function call may change dynamic type:res_226 = mdns_add_txt_answer (outpkt_174(D), _55, service_221);
  Function call may change dynamic type:res_230 = mdns_add_aaaa_answer (outpkt_174(D), _65, _62, addrindex_146);
  Function call may change dynamic type:res_234 = mdns_add_a_answer (outpkt_174(D), _75, _71);
Determining dynamic type for call: res_226 = mdns_add_txt_answer (outpkt_174(D), _55, service_221);
  Starting walk at: res_226 = mdns_add_txt_answer (outpkt_174(D), _55, service_221);
  instance pointer: outpkt_174(D)  Outer instance pointer: outpkt_174(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_178 = mdns_add_a_answer (outpkt_174(D), _6, _1);
  Function call may change dynamic type:res_181 = mdns_add_hostv4_ptr_answer (outpkt_174(D), _11, _12);
  Function call may change dynamic type:res_185 = mdns_add_aaaa_answer (outpkt_174(D), _18, _15, addrindex_143);
  Function call may change dynamic type:res_191 = mdns_add_hostv6_ptr_answer (outpkt_174(D), _23, _24, addrindex_145);
  Function call may change dynamic type:res_248 = mdns_add_txt_answer (outpkt_174(D), _37, service_237);
  Function call may change dynamic type:res_239 = mdns_add_servicetype_ptr_answer (outpkt_174(D), service_237);
  Function call may change dynamic type:res_242 = mdns_add_servicename_ptr_answer (outpkt_174(D), service_237);
  Function call may change dynamic type:res_245 = mdns_add_srv_answer (outpkt_174(D), _32, mdns_175, service_237);
  Function call may change dynamic type:res_223 = mdns_add_srv_answer (outpkt_174(D), _48, mdns_175, service_221);
  Function call may change dynamic type:res_226 = mdns_add_txt_answer (outpkt_174(D), _55, service_221);
  Function call may change dynamic type:res_230 = mdns_add_aaaa_answer (outpkt_174(D), _65, _62, addrindex_146);
  Function call may change dynamic type:res_234 = mdns_add_a_answer (outpkt_174(D), _75, _71);
Determining dynamic type for call: res_226 = mdns_add_txt_answer (outpkt_174(D), _55, service_221);
  Starting walk at: res_226 = mdns_add_txt_answer (outpkt_174(D), _55, service_221);
  instance pointer: service_221  Outer instance pointer: service_221 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_178 = mdns_add_a_answer (outpkt_174(D), _6, _1);
  Function call may change dynamic type:res_181 = mdns_add_hostv4_ptr_answer (outpkt_174(D), _11, _12);
  Function call may change dynamic type:res_185 = mdns_add_aaaa_answer (outpkt_174(D), _18, _15, addrindex_143);
  Function call may change dynamic type:res_191 = mdns_add_hostv6_ptr_answer (outpkt_174(D), _23, _24, addrindex_145);
  Function call may change dynamic type:res_248 = mdns_add_txt_answer (outpkt_174(D), _37, service_237);
  Function call may change dynamic type:res_239 = mdns_add_servicetype_ptr_answer (outpkt_174(D), service_237);
  Function call may change dynamic type:res_242 = mdns_add_servicename_ptr_answer (outpkt_174(D), service_237);
  Function call may change dynamic type:res_245 = mdns_add_srv_answer (outpkt_174(D), _32, mdns_175, service_237);
  Function call may change dynamic type:res_223 = mdns_add_srv_answer (outpkt_174(D), _48, mdns_175, service_221);
  Function call may change dynamic type:res_226 = mdns_add_txt_answer (outpkt_174(D), _55, service_221);
  Function call may change dynamic type:res_230 = mdns_add_aaaa_answer (outpkt_174(D), _65, _62, addrindex_146);
  Function call may change dynamic type:res_234 = mdns_add_a_answer (outpkt_174(D), _75, _71);
Determining dynamic type for call: res_230 = mdns_add_aaaa_answer (outpkt_174(D), _65, _62, addrindex_146);
  Starting walk at: res_230 = mdns_add_aaaa_answer (outpkt_174(D), _65, _62, addrindex_146);
  instance pointer: outpkt_174(D)  Outer instance pointer: outpkt_174(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_178 = mdns_add_a_answer (outpkt_174(D), _6, _1);
  Function call may change dynamic type:res_181 = mdns_add_hostv4_ptr_answer (outpkt_174(D), _11, _12);
  Function call may change dynamic type:res_185 = mdns_add_aaaa_answer (outpkt_174(D), _18, _15, addrindex_143);
  Function call may change dynamic type:res_191 = mdns_add_hostv6_ptr_answer (outpkt_174(D), _23, _24, addrindex_145);
  Function call may change dynamic type:res_248 = mdns_add_txt_answer (outpkt_174(D), _37, service_237);
  Function call may change dynamic type:res_239 = mdns_add_servicetype_ptr_answer (outpkt_174(D), service_237);
  Function call may change dynamic type:res_242 = mdns_add_servicename_ptr_answer (outpkt_174(D), service_237);
  Function call may change dynamic type:res_245 = mdns_add_srv_answer (outpkt_174(D), _32, mdns_175, service_237);
  Function call may change dynamic type:res_234 = mdns_add_a_answer (outpkt_174(D), _75, _71);
  Function call may change dynamic type:res_223 = mdns_add_srv_answer (outpkt_174(D), _48, mdns_175, service_221);
  Function call may change dynamic type:res_226 = mdns_add_txt_answer (outpkt_174(D), _55, service_221);
  Function call may change dynamic type:res_230 = mdns_add_aaaa_answer (outpkt_174(D), _65, _62, addrindex_146);
Determining dynamic type for call: res_230 = mdns_add_aaaa_answer (outpkt_174(D), _65, _62, addrindex_146);
  Starting walk at: res_230 = mdns_add_aaaa_answer (outpkt_174(D), _65, _62, addrindex_146);
  instance pointer: _62  Outer instance pointer: _62 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_178 = mdns_add_a_answer (outpkt_174(D), _6, _1);
  Function call may change dynamic type:res_181 = mdns_add_hostv4_ptr_answer (outpkt_174(D), _11, _12);
  Function call may change dynamic type:res_185 = mdns_add_aaaa_answer (outpkt_174(D), _18, _15, addrindex_143);
  Function call may change dynamic type:res_191 = mdns_add_hostv6_ptr_answer (outpkt_174(D), _23, _24, addrindex_145);
  Function call may change dynamic type:res_248 = mdns_add_txt_answer (outpkt_174(D), _37, service_237);
  Function call may change dynamic type:res_239 = mdns_add_servicetype_ptr_answer (outpkt_174(D), service_237);
  Function call may change dynamic type:res_242 = mdns_add_servicename_ptr_answer (outpkt_174(D), service_237);
  Function call may change dynamic type:res_245 = mdns_add_srv_answer (outpkt_174(D), _32, mdns_175, service_237);
  Function call may change dynamic type:res_234 = mdns_add_a_answer (outpkt_174(D), _75, _71);
  Function call may change dynamic type:res_223 = mdns_add_srv_answer (outpkt_174(D), _48, mdns_175, service_221);
  Function call may change dynamic type:res_226 = mdns_add_txt_answer (outpkt_174(D), _55, service_221);
  Function call may change dynamic type:res_230 = mdns_add_aaaa_answer (outpkt_174(D), _65, _62, addrindex_146);
Determining dynamic type for call: res_234 = mdns_add_a_answer (outpkt_174(D), _75, _71);
  Starting walk at: res_234 = mdns_add_a_answer (outpkt_174(D), _75, _71);
  instance pointer: outpkt_174(D)  Outer instance pointer: outpkt_174(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_178 = mdns_add_a_answer (outpkt_174(D), _6, _1);
  Function call may change dynamic type:res_181 = mdns_add_hostv4_ptr_answer (outpkt_174(D), _11, _12);
  Function call may change dynamic type:res_185 = mdns_add_aaaa_answer (outpkt_174(D), _18, _15, addrindex_143);
  Function call may change dynamic type:res_191 = mdns_add_hostv6_ptr_answer (outpkt_174(D), _23, _24, addrindex_145);
  Function call may change dynamic type:res_248 = mdns_add_txt_answer (outpkt_174(D), _37, service_237);
  Function call may change dynamic type:res_239 = mdns_add_servicetype_ptr_answer (outpkt_174(D), service_237);
  Function call may change dynamic type:res_242 = mdns_add_servicename_ptr_answer (outpkt_174(D), service_237);
  Function call may change dynamic type:res_245 = mdns_add_srv_answer (outpkt_174(D), _32, mdns_175, service_237);
  Function call may change dynamic type:res_230 = mdns_add_aaaa_answer (outpkt_174(D), _65, _62, addrindex_146);
  Function call may change dynamic type:res_234 = mdns_add_a_answer (outpkt_174(D), _75, _71);
  Function call may change dynamic type:res_223 = mdns_add_srv_answer (outpkt_174(D), _48, mdns_175, service_221);
  Function call may change dynamic type:res_226 = mdns_add_txt_answer (outpkt_174(D), _55, service_221);
Determining dynamic type for call: res_234 = mdns_add_a_answer (outpkt_174(D), _75, _71);
  Starting walk at: res_234 = mdns_add_a_answer (outpkt_174(D), _75, _71);
  instance pointer: _71  Outer instance pointer: _71 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_178 = mdns_add_a_answer (outpkt_174(D), _6, _1);
  Function call may change dynamic type:res_181 = mdns_add_hostv4_ptr_answer (outpkt_174(D), _11, _12);
  Function call may change dynamic type:res_185 = mdns_add_aaaa_answer (outpkt_174(D), _18, _15, addrindex_143);
  Function call may change dynamic type:res_191 = mdns_add_hostv6_ptr_answer (outpkt_174(D), _23, _24, addrindex_145);
  Function call may change dynamic type:res_248 = mdns_add_txt_answer (outpkt_174(D), _37, service_237);
  Function call may change dynamic type:res_239 = mdns_add_servicetype_ptr_answer (outpkt_174(D), service_237);
  Function call may change dynamic type:res_242 = mdns_add_servicename_ptr_answer (outpkt_174(D), service_237);
  Function call may change dynamic type:res_245 = mdns_add_srv_answer (outpkt_174(D), _32, mdns_175, service_237);
  Function call may change dynamic type:res_230 = mdns_add_aaaa_answer (outpkt_174(D), _65, _62, addrindex_146);
  Function call may change dynamic type:res_234 = mdns_add_a_answer (outpkt_174(D), _75, _71);
  Function call may change dynamic type:res_223 = mdns_add_srv_answer (outpkt_174(D), _48, mdns_175, service_221);
  Function call may change dynamic type:res_226 = mdns_add_txt_answer (outpkt_174(D), _55, service_221);
Determining dynamic type for call: res_239 = mdns_add_servicetype_ptr_answer (outpkt_174(D), service_237);
  Starting walk at: res_239 = mdns_add_servicetype_ptr_answer (outpkt_174(D), service_237);
  instance pointer: outpkt_174(D)  Outer instance pointer: outpkt_174(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_178 = mdns_add_a_answer (outpkt_174(D), _6, _1);
  Function call may change dynamic type:res_181 = mdns_add_hostv4_ptr_answer (outpkt_174(D), _11, _12);
  Function call may change dynamic type:res_185 = mdns_add_aaaa_answer (outpkt_174(D), _18, _15, addrindex_143);
  Function call may change dynamic type:res_191 = mdns_add_hostv6_ptr_answer (outpkt_174(D), _23, _24, addrindex_145);
  Function call may change dynamic type:res_248 = mdns_add_txt_answer (outpkt_174(D), _37, service_237);
  Function call may change dynamic type:res_239 = mdns_add_servicetype_ptr_answer (outpkt_174(D), service_237);
  Function call may change dynamic type:res_242 = mdns_add_servicename_ptr_answer (outpkt_174(D), service_237);
  Function call may change dynamic type:res_245 = mdns_add_srv_answer (outpkt_174(D), _32, mdns_175, service_237);
Determining dynamic type for call: res_239 = mdns_add_servicetype_ptr_answer (outpkt_174(D), service_237);
  Starting walk at: res_239 = mdns_add_servicetype_ptr_answer (outpkt_174(D), service_237);
  instance pointer: service_237  Outer instance pointer: service_237 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_178 = mdns_add_a_answer (outpkt_174(D), _6, _1);
  Function call may change dynamic type:res_181 = mdns_add_hostv4_ptr_answer (outpkt_174(D), _11, _12);
  Function call may change dynamic type:res_185 = mdns_add_aaaa_answer (outpkt_174(D), _18, _15, addrindex_143);
  Function call may change dynamic type:res_191 = mdns_add_hostv6_ptr_answer (outpkt_174(D), _23, _24, addrindex_145);
  Function call may change dynamic type:res_248 = mdns_add_txt_answer (outpkt_174(D), _37, service_237);
  Function call may change dynamic type:res_239 = mdns_add_servicetype_ptr_answer (outpkt_174(D), service_237);
  Function call may change dynamic type:res_242 = mdns_add_servicename_ptr_answer (outpkt_174(D), service_237);
  Function call may change dynamic type:res_245 = mdns_add_srv_answer (outpkt_174(D), _32, mdns_175, service_237);
Determining dynamic type for call: res_242 = mdns_add_servicename_ptr_answer (outpkt_174(D), service_237);
  Starting walk at: res_242 = mdns_add_servicename_ptr_answer (outpkt_174(D), service_237);
  instance pointer: outpkt_174(D)  Outer instance pointer: outpkt_174(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_178 = mdns_add_a_answer (outpkt_174(D), _6, _1);
  Function call may change dynamic type:res_181 = mdns_add_hostv4_ptr_answer (outpkt_174(D), _11, _12);
  Function call may change dynamic type:res_185 = mdns_add_aaaa_answer (outpkt_174(D), _18, _15, addrindex_143);
  Function call may change dynamic type:res_191 = mdns_add_hostv6_ptr_answer (outpkt_174(D), _23, _24, addrindex_145);
  Function call may change dynamic type:res_248 = mdns_add_txt_answer (outpkt_174(D), _37, service_237);
  Function call may change dynamic type:res_239 = mdns_add_servicetype_ptr_answer (outpkt_174(D), service_237);
  Function call may change dynamic type:res_242 = mdns_add_servicename_ptr_answer (outpkt_174(D), service_237);
  Function call may change dynamic type:res_245 = mdns_add_srv_answer (outpkt_174(D), _32, mdns_175, service_237);
Determining dynamic type for call: res_242 = mdns_add_servicename_ptr_answer (outpkt_174(D), service_237);
  Starting walk at: res_242 = mdns_add_servicename_ptr_answer (outpkt_174(D), service_237);
  instance pointer: service_237  Outer instance pointer: service_237 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_178 = mdns_add_a_answer (outpkt_174(D), _6, _1);
  Function call may change dynamic type:res_181 = mdns_add_hostv4_ptr_answer (outpkt_174(D), _11, _12);
  Function call may change dynamic type:res_185 = mdns_add_aaaa_answer (outpkt_174(D), _18, _15, addrindex_143);
  Function call may change dynamic type:res_191 = mdns_add_hostv6_ptr_answer (outpkt_174(D), _23, _24, addrindex_145);
  Function call may change dynamic type:res_248 = mdns_add_txt_answer (outpkt_174(D), _37, service_237);
  Function call may change dynamic type:res_239 = mdns_add_servicetype_ptr_answer (outpkt_174(D), service_237);
  Function call may change dynamic type:res_242 = mdns_add_servicename_ptr_answer (outpkt_174(D), service_237);
  Function call may change dynamic type:res_245 = mdns_add_srv_answer (outpkt_174(D), _32, mdns_175, service_237);
Determining dynamic type for call: res_245 = mdns_add_srv_answer (outpkt_174(D), _32, mdns_175, service_237);
  Starting walk at: res_245 = mdns_add_srv_answer (outpkt_174(D), _32, mdns_175, service_237);
  instance pointer: outpkt_174(D)  Outer instance pointer: outpkt_174(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_178 = mdns_add_a_answer (outpkt_174(D), _6, _1);
  Function call may change dynamic type:res_181 = mdns_add_hostv4_ptr_answer (outpkt_174(D), _11, _12);
  Function call may change dynamic type:res_185 = mdns_add_aaaa_answer (outpkt_174(D), _18, _15, addrindex_143);
  Function call may change dynamic type:res_191 = mdns_add_hostv6_ptr_answer (outpkt_174(D), _23, _24, addrindex_145);
  Function call may change dynamic type:res_248 = mdns_add_txt_answer (outpkt_174(D), _37, service_237);
  Function call may change dynamic type:res_242 = mdns_add_servicename_ptr_answer (outpkt_174(D), service_237);
  Function call may change dynamic type:res_245 = mdns_add_srv_answer (outpkt_174(D), _32, mdns_175, service_237);
  Function call may change dynamic type:res_239 = mdns_add_servicetype_ptr_answer (outpkt_174(D), service_237);
Determining dynamic type for call: res_245 = mdns_add_srv_answer (outpkt_174(D), _32, mdns_175, service_237);
  Starting walk at: res_245 = mdns_add_srv_answer (outpkt_174(D), _32, mdns_175, service_237);
  instance pointer: mdns_175  Outer instance pointer: mdns_175 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_178 = mdns_add_a_answer (outpkt_174(D), _6, _1);
  Function call may change dynamic type:res_181 = mdns_add_hostv4_ptr_answer (outpkt_174(D), _11, _12);
  Function call may change dynamic type:res_185 = mdns_add_aaaa_answer (outpkt_174(D), _18, _15, addrindex_143);
  Function call may change dynamic type:res_191 = mdns_add_hostv6_ptr_answer (outpkt_174(D), _23, _24, addrindex_145);
  Function call may change dynamic type:res_248 = mdns_add_txt_answer (outpkt_174(D), _37, service_237);
  Function call may change dynamic type:res_242 = mdns_add_servicename_ptr_answer (outpkt_174(D), service_237);
  Function call may change dynamic type:res_245 = mdns_add_srv_answer (outpkt_174(D), _32, mdns_175, service_237);
  Function call may change dynamic type:res_239 = mdns_add_servicetype_ptr_answer (outpkt_174(D), service_237);
Determining dynamic type for call: res_245 = mdns_add_srv_answer (outpkt_174(D), _32, mdns_175, service_237);
  Starting walk at: res_245 = mdns_add_srv_answer (outpkt_174(D), _32, mdns_175, service_237);
  instance pointer: service_237  Outer instance pointer: service_237 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_178 = mdns_add_a_answer (outpkt_174(D), _6, _1);
  Function call may change dynamic type:res_181 = mdns_add_hostv4_ptr_answer (outpkt_174(D), _11, _12);
  Function call may change dynamic type:res_185 = mdns_add_aaaa_answer (outpkt_174(D), _18, _15, addrindex_143);
  Function call may change dynamic type:res_191 = mdns_add_hostv6_ptr_answer (outpkt_174(D), _23, _24, addrindex_145);
  Function call may change dynamic type:res_248 = mdns_add_txt_answer (outpkt_174(D), _37, service_237);
  Function call may change dynamic type:res_242 = mdns_add_servicename_ptr_answer (outpkt_174(D), service_237);
  Function call may change dynamic type:res_245 = mdns_add_srv_answer (outpkt_174(D), _32, mdns_175, service_237);
  Function call may change dynamic type:res_239 = mdns_add_servicetype_ptr_answer (outpkt_174(D), service_237);
Determining dynamic type for call: res_248 = mdns_add_txt_answer (outpkt_174(D), _37, service_237);
  Starting walk at: res_248 = mdns_add_txt_answer (outpkt_174(D), _37, service_237);
  instance pointer: outpkt_174(D)  Outer instance pointer: outpkt_174(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_178 = mdns_add_a_answer (outpkt_174(D), _6, _1);
  Function call may change dynamic type:res_181 = mdns_add_hostv4_ptr_answer (outpkt_174(D), _11, _12);
  Function call may change dynamic type:res_185 = mdns_add_aaaa_answer (outpkt_174(D), _18, _15, addrindex_143);
  Function call may change dynamic type:res_191 = mdns_add_hostv6_ptr_answer (outpkt_174(D), _23, _24, addrindex_145);
  Function call may change dynamic type:res_248 = mdns_add_txt_answer (outpkt_174(D), _37, service_237);
  Function call may change dynamic type:res_245 = mdns_add_srv_answer (outpkt_174(D), _32, mdns_175, service_237);
  Function call may change dynamic type:res_239 = mdns_add_servicetype_ptr_answer (outpkt_174(D), service_237);
  Function call may change dynamic type:res_242 = mdns_add_servicename_ptr_answer (outpkt_174(D), service_237);
Determining dynamic type for call: res_248 = mdns_add_txt_answer (outpkt_174(D), _37, service_237);
  Starting walk at: res_248 = mdns_add_txt_answer (outpkt_174(D), _37, service_237);
  instance pointer: service_237  Outer instance pointer: service_237 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_178 = mdns_add_a_answer (outpkt_174(D), _6, _1);
  Function call may change dynamic type:res_181 = mdns_add_hostv4_ptr_answer (outpkt_174(D), _11, _12);
  Function call may change dynamic type:res_185 = mdns_add_aaaa_answer (outpkt_174(D), _18, _15, addrindex_143);
  Function call may change dynamic type:res_191 = mdns_add_hostv6_ptr_answer (outpkt_174(D), _23, _24, addrindex_145);
  Function call may change dynamic type:res_248 = mdns_add_txt_answer (outpkt_174(D), _37, service_237);
  Function call may change dynamic type:res_245 = mdns_add_srv_answer (outpkt_174(D), _32, mdns_175, service_237);
  Function call may change dynamic type:res_239 = mdns_add_servicetype_ptr_answer (outpkt_174(D), service_237);
  Function call may change dynamic type:res_242 = mdns_add_servicename_ptr_answer (outpkt_174(D), service_237);
Determining dynamic type for call: mdns_build_service_domain (&service_instance, service_6(D), 1);
  Starting walk at: mdns_build_service_domain (&service_instance, service_6(D), 1);
  instance pointer: &service_instance  Outer instance pointer: service_instance offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: mdns_build_service_domain (&service_instance, service_6(D), 1);
  Starting walk at: mdns_build_service_domain (&service_instance, service_6(D), 1);
  instance pointer: service_6(D)  Outer instance pointer: service_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: mdns_prepare_txtdata (service_6(D));
  Starting walk at: mdns_prepare_txtdata (service_6(D));
  instance pointer: service_6(D)  Outer instance pointer: service_6(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_build_service_domain (&service_instance, service_6(D), 1);
Determining dynamic type for call: _12 = mdns_add_answer (reply_9(D), &service_instance, 16, 1, cache_flush_10(D), _1, _2, _4, 0B);
  Starting walk at: _12 = mdns_add_answer (reply_9(D), &service_instance, 16, 1, cache_flush_10(D), _1, _2, _4, 0B);
  instance pointer: reply_9(D)  Outer instance pointer: reply_9(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_prepare_txtdata (service_6(D));
  Function call may change dynamic type:mdns_build_service_domain (&service_instance, service_6(D), 1);
Determining dynamic type for call: _12 = mdns_add_answer (reply_9(D), &service_instance, 16, 1, cache_flush_10(D), _1, _2, _4, 0B);
  Starting walk at: _12 = mdns_add_answer (reply_9(D), &service_instance, 16, 1, cache_flush_10(D), _1, _2, _4, 0B);
  instance pointer: &service_instance  Outer instance pointer: service_instance offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_prepare_txtdata (service_6(D));
  Function call may change dynamic type:mdns_build_service_domain (&service_instance, service_6(D), 1);
Determining dynamic type for call: _12 = mdns_add_answer (reply_9(D), &service_instance, 16, 1, cache_flush_10(D), _1, _2, _4, 0B);
  Starting walk at: _12 = mdns_add_answer (reply_9(D), &service_instance, 16, 1, cache_flush_10(D), _1, _2, _4, 0B);
  instance pointer: _2  Outer instance pointer: service_6(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_prepare_txtdata (service_6(D));
  Function call may change dynamic type:mdns_build_service_domain (&service_instance, service_6(D), 1);
Determining dynamic type for call: _12 = mdns_add_answer (reply_9(D), &service_instance, 16, 1, cache_flush_10(D), _1, _2, _4, 0B);
  Starting walk at: _12 = mdns_add_answer (reply_9(D), &service_instance, 16, 1, cache_flush_10(D), _1, _2, _4, 0B);
  instance pointer: 0B  Outer instance pointer: 0B offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_prepare_txtdata (service_6(D));
  Function call may change dynamic type:mdns_build_service_domain (&service_instance, service_6(D), 1);
Determining dynamic type for call: mdns_build_service_domain (&service_instance, service_9(D), 1);
  Starting walk at: mdns_build_service_domain (&service_instance, service_9(D), 1);
  instance pointer: &service_instance  Outer instance pointer: service_instance offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: mdns_build_service_domain (&service_instance, service_9(D), 1);
  Starting walk at: mdns_build_service_domain (&service_instance, service_9(D), 1);
  instance pointer: service_9(D)  Outer instance pointer: service_9(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: mdns_build_host_domain (&srvhost, mdns_11(D));
  Starting walk at: mdns_build_host_domain (&srvhost, mdns_11(D));
  instance pointer: &srvhost  Outer instance pointer: srvhost offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_build_service_domain (&service_instance, service_9(D), 1);
Determining dynamic type for call: mdns_build_host_domain (&srvhost, mdns_11(D));
  Starting walk at: mdns_build_host_domain (&srvhost, mdns_11(D));
  instance pointer: mdns_11(D)  Outer instance pointer: mdns_11(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_build_service_domain (&service_instance, service_9(D), 1);
Determining dynamic type for call: _23 = mdns_add_answer (reply_13(D), &service_instance, 33, 1, cache_flush_21(D), _6, &srvdata, 6, &srvhost);
  Starting walk at: _23 = mdns_add_answer (reply_13(D), &service_instance, 33, 1, cache_flush_21(D), _6, &srvdata, 6, &srvhost);
  instance pointer: reply_13(D)  Outer instance pointer: reply_13(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_5 = lwip_htons (_4);
  Function call may change dynamic type:_3 = lwip_htons (0);
  Function call may change dynamic type:_2 = lwip_htons (0);
  Function call may change dynamic type:mdns_build_host_domain (&srvhost, mdns_11(D));
  Function call may change dynamic type:mdns_build_service_domain (&service_instance, service_9(D), 1);
Determining dynamic type for call: _23 = mdns_add_answer (reply_13(D), &service_instance, 33, 1, cache_flush_21(D), _6, &srvdata, 6, &srvhost);
  Starting walk at: _23 = mdns_add_answer (reply_13(D), &service_instance, 33, 1, cache_flush_21(D), _6, &srvdata, 6, &srvhost);
  instance pointer: &service_instance  Outer instance pointer: service_instance offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_5 = lwip_htons (_4);
  Function call may change dynamic type:_3 = lwip_htons (0);
  Function call may change dynamic type:_2 = lwip_htons (0);
  Function call may change dynamic type:mdns_build_host_domain (&srvhost, mdns_11(D));
  Function call may change dynamic type:mdns_build_service_domain (&service_instance, service_9(D), 1);
Determining dynamic type for call: _23 = mdns_add_answer (reply_13(D), &service_instance, 33, 1, cache_flush_21(D), _6, &srvdata, 6, &srvhost);
  Starting walk at: _23 = mdns_add_answer (reply_13(D), &service_instance, 33, 1, cache_flush_21(D), _6, &srvdata, 6, &srvhost);
  instance pointer: &srvdata  Outer instance pointer: srvdata offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_5 = lwip_htons (_4);
  Function call may change dynamic type:_3 = lwip_htons (0);
  Function call may change dynamic type:_2 = lwip_htons (0);
  Function call may change dynamic type:mdns_build_host_domain (&srvhost, mdns_11(D));
  Function call may change dynamic type:mdns_build_service_domain (&service_instance, service_9(D), 1);
Determining dynamic type for call: _23 = mdns_add_answer (reply_13(D), &service_instance, 33, 1, cache_flush_21(D), _6, &srvdata, 6, &srvhost);
  Starting walk at: _23 = mdns_add_answer (reply_13(D), &service_instance, 33, 1, cache_flush_21(D), _6, &srvdata, 6, &srvhost);
  instance pointer: &srvhost  Outer instance pointer: srvhost offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_5 = lwip_htons (_4);
  Function call may change dynamic type:_3 = lwip_htons (0);
  Function call may change dynamic type:_2 = lwip_htons (0);
  Function call may change dynamic type:mdns_build_host_domain (&srvhost, mdns_11(D));
  Function call may change dynamic type:mdns_build_service_domain (&service_instance, service_9(D), 1);
Determining dynamic type for call: mdns_build_service_domain (&service_type, service_3(D), 0);
  Starting walk at: mdns_build_service_domain (&service_type, service_3(D), 0);
  instance pointer: &service_type  Outer instance pointer: service_type offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: mdns_build_service_domain (&service_type, service_3(D), 0);
  Starting walk at: mdns_build_service_domain (&service_type, service_3(D), 0);
  instance pointer: service_3(D)  Outer instance pointer: service_3(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: mdns_build_service_domain (&service_instance, service_3(D), 1);
  Starting walk at: mdns_build_service_domain (&service_instance, service_3(D), 1);
  instance pointer: &service_instance  Outer instance pointer: service_instance offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_build_service_domain (&service_type, service_3(D), 0);
Determining dynamic type for call: mdns_build_service_domain (&service_instance, service_3(D), 1);
  Starting walk at: mdns_build_service_domain (&service_instance, service_3(D), 1);
  instance pointer: service_3(D)  Outer instance pointer: service_3(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_build_service_domain (&service_type, service_3(D), 0);
Determining dynamic type for call: _8 = mdns_add_answer (reply_6(D), &service_type, 12, 1, 0, _1, 0B, 0, &service_instance);
  Starting walk at: _8 = mdns_add_answer (reply_6(D), &service_type, 12, 1, 0, _1, 0B, 0, &service_instance);
  instance pointer: reply_6(D)  Outer instance pointer: reply_6(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_build_service_domain (&service_instance, service_3(D), 1);
  Function call may change dynamic type:mdns_build_service_domain (&service_type, service_3(D), 0);
Determining dynamic type for call: _8 = mdns_add_answer (reply_6(D), &service_type, 12, 1, 0, _1, 0B, 0, &service_instance);
  Starting walk at: _8 = mdns_add_answer (reply_6(D), &service_type, 12, 1, 0, _1, 0B, 0, &service_instance);
  instance pointer: &service_type  Outer instance pointer: service_type offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_build_service_domain (&service_instance, service_3(D), 1);
  Function call may change dynamic type:mdns_build_service_domain (&service_type, service_3(D), 0);
Determining dynamic type for call: _8 = mdns_add_answer (reply_6(D), &service_type, 12, 1, 0, _1, 0B, 0, &service_instance);
  Starting walk at: _8 = mdns_add_answer (reply_6(D), &service_type, 12, 1, 0, _1, 0B, 0, &service_instance);
  instance pointer: 0B  Outer instance pointer: 0B offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_build_service_domain (&service_instance, service_3(D), 1);
  Function call may change dynamic type:mdns_build_service_domain (&service_type, service_3(D), 0);
Determining dynamic type for call: _8 = mdns_add_answer (reply_6(D), &service_type, 12, 1, 0, _1, 0B, 0, &service_instance);
  Starting walk at: _8 = mdns_add_answer (reply_6(D), &service_type, 12, 1, 0, _1, 0B, 0, &service_instance);
  instance pointer: &service_instance  Outer instance pointer: service_instance offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_build_service_domain (&service_instance, service_3(D), 1);
  Function call may change dynamic type:mdns_build_service_domain (&service_type, service_3(D), 0);
Determining dynamic type for call: mdns_build_service_domain (&service_type, service_3(D), 0);
  Starting walk at: mdns_build_service_domain (&service_type, service_3(D), 0);
  instance pointer: &service_type  Outer instance pointer: service_type offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: mdns_build_service_domain (&service_type, service_3(D), 0);
  Starting walk at: mdns_build_service_domain (&service_type, service_3(D), 0);
  instance pointer: service_3(D)  Outer instance pointer: service_3(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: mdns_build_dnssd_domain (&service_dnssd);
  Starting walk at: mdns_build_dnssd_domain (&service_dnssd);
  instance pointer: &service_dnssd  Outer instance pointer: service_dnssd offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_build_service_domain (&service_type, service_3(D), 0);
Determining dynamic type for call: _8 = mdns_add_answer (reply_6(D), &service_dnssd, 12, 1, 0, _1, 0B, 0, &service_type);
  Starting walk at: _8 = mdns_add_answer (reply_6(D), &service_dnssd, 12, 1, 0, _1, 0B, 0, &service_type);
  instance pointer: reply_6(D)  Outer instance pointer: reply_6(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_build_dnssd_domain (&service_dnssd);
  Function call may change dynamic type:mdns_build_service_domain (&service_type, service_3(D), 0);
Determining dynamic type for call: _8 = mdns_add_answer (reply_6(D), &service_dnssd, 12, 1, 0, _1, 0B, 0, &service_type);
  Starting walk at: _8 = mdns_add_answer (reply_6(D), &service_dnssd, 12, 1, 0, _1, 0B, 0, &service_type);
  instance pointer: &service_dnssd  Outer instance pointer: service_dnssd offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_build_dnssd_domain (&service_dnssd);
  Function call may change dynamic type:mdns_build_service_domain (&service_type, service_3(D), 0);
Determining dynamic type for call: _8 = mdns_add_answer (reply_6(D), &service_dnssd, 12, 1, 0, _1, 0B, 0, &service_type);
  Starting walk at: _8 = mdns_add_answer (reply_6(D), &service_dnssd, 12, 1, 0, _1, 0B, 0, &service_type);
  instance pointer: 0B  Outer instance pointer: 0B offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_build_dnssd_domain (&service_dnssd);
  Function call may change dynamic type:mdns_build_service_domain (&service_type, service_3(D), 0);
Determining dynamic type for call: _8 = mdns_add_answer (reply_6(D), &service_dnssd, 12, 1, 0, _1, 0B, 0, &service_type);
  Starting walk at: _8 = mdns_add_answer (reply_6(D), &service_dnssd, 12, 1, 0, _1, 0B, 0, &service_type);
  instance pointer: &service_type  Outer instance pointer: service_type offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_build_dnssd_domain (&service_dnssd);
  Function call may change dynamic type:mdns_build_service_domain (&service_type, service_3(D), 0);
Determining dynamic type for call: mdns_build_host_domain (&host, _3);
  Starting walk at: mdns_build_host_domain (&host, _3);
  instance pointer: &host  Outer instance pointer: host offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: mdns_build_host_domain (&host, _3);
  Starting walk at: mdns_build_host_domain (&host, _3);
  instance pointer: _3  Outer instance pointer: _3 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: mdns_build_reverse_v6_domain (&revhost, _4);
  Starting walk at: mdns_build_reverse_v6_domain (&revhost, _4);
  instance pointer: &revhost  Outer instance pointer: revhost offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_build_host_domain (&host, _3);
Determining dynamic type for call: mdns_build_reverse_v6_domain (&revhost, _4);
  Starting walk at: mdns_build_reverse_v6_domain (&revhost, _4);
  instance pointer: _4  Outer instance pointer: &netif_10(D)->ip6_addr[addrindex_12(D)].u_addr.ip6 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_build_host_domain (&host, _3);
Determining dynamic type for call: _17 = mdns_add_answer (reply_14(D), &revhost, 12, 1, cache_flush_15(D), _8, 0B, 0, &host);
  Starting walk at: _17 = mdns_add_answer (reply_14(D), &revhost, 12, 1, cache_flush_15(D), _8, 0B, 0, &host);
  instance pointer: reply_14(D)  Outer instance pointer: reply_14(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_build_reverse_v6_domain (&revhost, _4);
  Function call may change dynamic type:mdns_build_host_domain (&host, _3);
Determining dynamic type for call: _17 = mdns_add_answer (reply_14(D), &revhost, 12, 1, cache_flush_15(D), _8, 0B, 0, &host);
  Starting walk at: _17 = mdns_add_answer (reply_14(D), &revhost, 12, 1, cache_flush_15(D), _8, 0B, 0, &host);
  instance pointer: &revhost  Outer instance pointer: revhost offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_build_reverse_v6_domain (&revhost, _4);
  Function call may change dynamic type:mdns_build_host_domain (&host, _3);
Determining dynamic type for call: _17 = mdns_add_answer (reply_14(D), &revhost, 12, 1, cache_flush_15(D), _8, 0B, 0, &host);
  Starting walk at: _17 = mdns_add_answer (reply_14(D), &revhost, 12, 1, cache_flush_15(D), _8, 0B, 0, &host);
  instance pointer: 0B  Outer instance pointer: 0B offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_build_reverse_v6_domain (&revhost, _4);
  Function call may change dynamic type:mdns_build_host_domain (&host, _3);
Determining dynamic type for call: _17 = mdns_add_answer (reply_14(D), &revhost, 12, 1, cache_flush_15(D), _8, 0B, 0, &host);
  Starting walk at: _17 = mdns_add_answer (reply_14(D), &revhost, 12, 1, cache_flush_15(D), _8, 0B, 0, &host);
  instance pointer: &host  Outer instance pointer: host offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_build_reverse_v6_domain (&revhost, _4);
  Function call may change dynamic type:mdns_build_host_domain (&host, _3);
Determining dynamic type for call: mdns_build_host_domain (&host, _3);
  Starting walk at: mdns_build_host_domain (&host, _3);
  instance pointer: &host  Outer instance pointer: host offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: mdns_build_host_domain (&host, _3);
  Starting walk at: mdns_build_host_domain (&host, _3);
  instance pointer: _3  Outer instance pointer: _3 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _16 = mdns_add_answer (reply_13(D), &host, 28, 1, cache_flush_14(D), _7, _8, 16, 0B);
  Starting walk at: _16 = mdns_add_answer (reply_13(D), &host, 28, 1, cache_flush_14(D), _7, _8, 16, 0B);
  instance pointer: reply_13(D)  Outer instance pointer: reply_13(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_build_host_domain (&host, _3);
Determining dynamic type for call: _16 = mdns_add_answer (reply_13(D), &host, 28, 1, cache_flush_14(D), _7, _8, 16, 0B);
  Starting walk at: _16 = mdns_add_answer (reply_13(D), &host, 28, 1, cache_flush_14(D), _7, _8, 16, 0B);
  instance pointer: &host  Outer instance pointer: host offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_build_host_domain (&host, _3);
Determining dynamic type for call: _16 = mdns_add_answer (reply_13(D), &host, 28, 1, cache_flush_14(D), _7, _8, 16, 0B);
  Starting walk at: _16 = mdns_add_answer (reply_13(D), &host, 28, 1, cache_flush_14(D), _7, _8, 16, 0B);
  instance pointer: _8  Outer instance pointer: &netif_10(D)->ip6_addr[addrindex_12(D)].u_addr.ip6 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_build_host_domain (&host, _3);
Determining dynamic type for call: _16 = mdns_add_answer (reply_13(D), &host, 28, 1, cache_flush_14(D), _7, _8, 16, 0B);
  Starting walk at: _16 = mdns_add_answer (reply_13(D), &host, 28, 1, cache_flush_14(D), _7, _8, 16, 0B);
  instance pointer: 0B  Outer instance pointer: 0B offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_build_host_domain (&host, _3);
Determining dynamic type for call: mdns_build_host_domain (&host, _3);
  Starting walk at: mdns_build_host_domain (&host, _3);
  instance pointer: &host  Outer instance pointer: host offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: mdns_build_host_domain (&host, _3);
  Starting walk at: mdns_build_host_domain (&host, _3);
  instance pointer: _3  Outer instance pointer: _3 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: mdns_build_reverse_v4_domain (&revhost, _4);
  Starting walk at: mdns_build_reverse_v4_domain (&revhost, _4);
  instance pointer: &revhost  Outer instance pointer: revhost offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_build_host_domain (&host, _3);
Determining dynamic type for call: mdns_build_reverse_v4_domain (&revhost, _4);
  Starting walk at: mdns_build_reverse_v4_domain (&revhost, _4);
  instance pointer: _4  Outer instance pointer: netif_10(D) offset: 32 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_build_host_domain (&host, _3);
Determining dynamic type for call: _16 = mdns_add_answer (reply_13(D), &revhost, 12, 1, cache_flush_14(D), _8, 0B, 0, &host);
  Starting walk at: _16 = mdns_add_answer (reply_13(D), &revhost, 12, 1, cache_flush_14(D), _8, 0B, 0, &host);
  instance pointer: reply_13(D)  Outer instance pointer: reply_13(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_build_reverse_v4_domain (&revhost, _4);
  Function call may change dynamic type:mdns_build_host_domain (&host, _3);
Determining dynamic type for call: _16 = mdns_add_answer (reply_13(D), &revhost, 12, 1, cache_flush_14(D), _8, 0B, 0, &host);
  Starting walk at: _16 = mdns_add_answer (reply_13(D), &revhost, 12, 1, cache_flush_14(D), _8, 0B, 0, &host);
  instance pointer: &revhost  Outer instance pointer: revhost offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_build_reverse_v4_domain (&revhost, _4);
  Function call may change dynamic type:mdns_build_host_domain (&host, _3);
Determining dynamic type for call: _16 = mdns_add_answer (reply_13(D), &revhost, 12, 1, cache_flush_14(D), _8, 0B, 0, &host);
  Starting walk at: _16 = mdns_add_answer (reply_13(D), &revhost, 12, 1, cache_flush_14(D), _8, 0B, 0, &host);
  instance pointer: 0B  Outer instance pointer: 0B offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_build_reverse_v4_domain (&revhost, _4);
  Function call may change dynamic type:mdns_build_host_domain (&host, _3);
Determining dynamic type for call: _16 = mdns_add_answer (reply_13(D), &revhost, 12, 1, cache_flush_14(D), _8, 0B, 0, &host);
  Starting walk at: _16 = mdns_add_answer (reply_13(D), &revhost, 12, 1, cache_flush_14(D), _8, 0B, 0, &host);
  instance pointer: &host  Outer instance pointer: host offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_build_reverse_v4_domain (&revhost, _4);
  Function call may change dynamic type:mdns_build_host_domain (&host, _3);
Determining dynamic type for call: mdns_build_host_domain (&host, _3);
  Starting walk at: mdns_build_host_domain (&host, _3);
  instance pointer: &host  Outer instance pointer: host offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: mdns_build_host_domain (&host, _3);
  Starting walk at: mdns_build_host_domain (&host, _3);
  instance pointer: _3  Outer instance pointer: _3 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _15 = mdns_add_answer (reply_12(D), &host, 1, 1, cache_flush_13(D), _7, _8, 4, 0B);
  Starting walk at: _15 = mdns_add_answer (reply_12(D), &host, 1, 1, cache_flush_13(D), _7, _8, 4, 0B);
  instance pointer: reply_12(D)  Outer instance pointer: reply_12(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_build_host_domain (&host, _3);
Determining dynamic type for call: _15 = mdns_add_answer (reply_12(D), &host, 1, 1, cache_flush_13(D), _7, _8, 4, 0B);
  Starting walk at: _15 = mdns_add_answer (reply_12(D), &host, 1, 1, cache_flush_13(D), _7, _8, 4, 0B);
  instance pointer: &host  Outer instance pointer: host offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_build_host_domain (&host, _3);
Determining dynamic type for call: _15 = mdns_add_answer (reply_12(D), &host, 1, 1, cache_flush_13(D), _7, _8, 4, 0B);
  Starting walk at: _15 = mdns_add_answer (reply_12(D), &host, 1, 1, cache_flush_13(D), _7, _8, 4, 0B);
  instance pointer: _8  Outer instance pointer: netif_10(D) offset: 32 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_build_host_domain (&host, _3);
Determining dynamic type for call: _15 = mdns_add_answer (reply_12(D), &host, 1, 1, cache_flush_13(D), _7, _8, 4, 0B);
  Starting walk at: _15 = mdns_add_answer (reply_12(D), &host, 1, 1, cache_flush_13(D), _7, _8, 4, 0B);
  instance pointer: 0B  Outer instance pointer: 0B offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:mdns_build_host_domain (&host, _3);
Determining dynamic type for call: res_35 = mdns_read_rr_info (pkt_30(D), _7);
  Starting walk at: res_35 = mdns_read_rr_info (pkt_30(D), _7);
  instance pointer: pkt_30(D)  Outer instance pointer: pkt_30(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:memset (answer_32(D), 0, 276);
Determining dynamic type for call: res_35 = mdns_read_rr_info (pkt_30(D), _7);
  Starting walk at: res_35 = mdns_read_rr_info (pkt_30(D), _7);
  instance pointer: _7  Outer instance pointer: answer_32(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:memset (answer_32(D), 0, 276);
Determining dynamic type for call: res_17 = mdns_read_rr_info (pkt_11(D), _7);
  Starting walk at: res_17 = mdns_read_rr_info (pkt_11(D), _7);
  instance pointer: pkt_11(D)  Outer instance pointer: pkt_11(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:memset (question_14(D), 0, 266);
Determining dynamic type for call: res_17 = mdns_read_rr_info (pkt_11(D), _7);
  Starting walk at: res_17 = mdns_read_rr_info (pkt_11(D), _7);
  instance pointer: _7  Outer instance pointer: question_14(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:memset (question_14(D), 0, 266);
Determining dynamic type for call: _5 = mdns_read_question.part.0 (question_14(D));
  Starting walk at: _5 = mdns_read_question.part.0 (question_14(D));
  instance pointer: question_14(D)  Outer instance pointer: question_14(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_17 = mdns_read_rr_info (pkt_11(D), _7);
  Function call may change dynamic type:memset (question_14(D), 0, 266);
Determining dynamic type for call: _4 = mdns_readname (_1, _2, _3);
  Starting walk at: _4 = mdns_readname (_1, _2, _3);
  instance pointer: _1  Outer instance pointer: _1 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _4 = mdns_readname (_1, _2, _3);
  Starting walk at: _4 = mdns_readname (_1, _2, _3);
  instance pointer: _3  Outer instance pointer: info_20(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: mdns_add_question (reply_35(D), domain_39(D), type_46(D), klass_47(D), cache_flush_48(D));
  Starting walk at: mdns_add_question (reply_35(D), domain_39(D), type_46(D), klass_47(D), cache_flush_48(D));
  instance pointer: reply_35(D)  Outer instance pointer: reply_35(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = pbuf_alloc (74, 500, 640);
Determining dynamic type for call: mdns_add_question (reply_35(D), domain_39(D), type_46(D), klass_47(D), cache_flush_48(D));
  Starting walk at: mdns_add_question (reply_35(D), domain_39(D), type_46(D), klass_47(D), cache_flush_48(D));
  instance pointer: domain_39(D)  Outer instance pointer: domain_39(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = pbuf_alloc (74, 500, 640);
Determining dynamic type for call: res_60 = mdns_write_domain (reply_35(D), answer_domain_44(D));
  Starting walk at: res_60 = mdns_write_domain (reply_35(D), answer_domain_44(D));
  instance pointer: reply_35(D)  Outer instance pointer: reply_35(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_54 = pbuf_take_at (_14, &field32, 4, _15);
  Function call may change dynamic type:_13 = lwip_htonl (ttl_50(D));
  Function call may change dynamic type:mdns_add_question (reply_35(D), domain_39(D), type_46(D), klass_47(D), cache_flush_48(D));
  Function call may change dynamic type:_2 = pbuf_alloc (74, 500, 640);
  Function call may change dynamic type:res_57 = pbuf_take_at (_19, buf_41(D), _20, _18);
Determining dynamic type for call: res_60 = mdns_write_domain (reply_35(D), answer_domain_44(D));
  Starting walk at: res_60 = mdns_write_domain (reply_35(D), answer_domain_44(D));
  instance pointer: answer_domain_44(D)  Outer instance pointer: answer_domain_44(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_54 = pbuf_take_at (_14, &field32, 4, _15);
  Function call may change dynamic type:_13 = lwip_htonl (ttl_50(D));
  Function call may change dynamic type:mdns_add_question (reply_35(D), domain_39(D), type_46(D), klass_47(D), cache_flush_48(D));
  Function call may change dynamic type:_2 = pbuf_alloc (74, 500, 640);
  Function call may change dynamic type:res_57 = pbuf_take_at (_19, buf_41(D), _20, _18);
Determining dynamic type for call: res_23 = mdns_write_domain (outpkt_15(D), domain_20(D));
  Starting walk at: res_23 = mdns_write_domain (outpkt_15(D), domain_20(D));
  instance pointer: outpkt_15(D)  Outer instance pointer: outpkt_15(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = pbuf_alloc (74, 500, 640);
Determining dynamic type for call: res_23 = mdns_write_domain (outpkt_15(D), domain_20(D));
  Starting walk at: res_23 = mdns_write_domain (outpkt_15(D), domain_20(D));
  instance pointer: domain_20(D)  Outer instance pointer: domain_20(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_2 = pbuf_alloc (74, 500, 640);
Determining dynamic type for call: _3 = mdns_add_question.part.0 (outpkt_15(D), type_24(D), klass_26(D), unicast_25(D));
  Starting walk at: _3 = mdns_add_question.part.0 (outpkt_15(D), type_24(D), klass_26(D), unicast_25(D));
  instance pointer: outpkt_15(D)  Outer instance pointer: outpkt_15(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_23 = mdns_write_domain (outpkt_15(D), domain_20(D));
  Function call may change dynamic type:_2 = pbuf_alloc (74, 500, 640);
Determining dynamic type for call: len_39 = mdns_compress_domain (_4, &offset, domain_34(D));
  Starting walk at: len_39 = mdns_compress_domain (_4, &offset, domain_34(D));
  instance pointer: _4  Outer instance pointer: _4 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:len_39 = mdns_compress_domain (_4, &offset, domain_34(D));
Determining dynamic type for call: len_39 = mdns_compress_domain (_4, &offset, domain_34(D));
  Starting walk at: len_39 = mdns_compress_domain (_4, &offset, domain_34(D));
  instance pointer: &offset  Outer instance pointer: offset offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:len_39 = mdns_compress_domain (_4, &offset, domain_34(D));
Determining dynamic type for call: len_39 = mdns_compress_domain (_4, &offset, domain_34(D));
  Starting walk at: len_39 = mdns_compress_domain (_4, &offset, domain_34(D));
  instance pointer: domain_34(D)  Outer instance pointer: domain_34(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:len_39 = mdns_compress_domain (_4, &offset, domain_34(D));
Determining dynamic type for call: _1 = mdns_compress_domain.part.0 (pbuf_5(D), offset_7(D), domain_8(D));
  Starting walk at: _1 = mdns_compress_domain.part.0 (pbuf_5(D), offset_7(D), domain_8(D));
  instance pointer: pbuf_5(D)  Outer instance pointer: pbuf_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = mdns_compress_domain.part.0 (pbuf_5(D), offset_7(D), domain_8(D));
  Starting walk at: _1 = mdns_compress_domain.part.0 (pbuf_5(D), offset_7(D), domain_8(D));
  instance pointer: offset_7(D)  Outer instance pointer: offset_7(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = mdns_compress_domain.part.0 (pbuf_5(D), offset_7(D), domain_8(D));
  Starting walk at: _1 = mdns_compress_domain.part.0 (pbuf_5(D), offset_7(D), domain_8(D));
  instance pointer: domain_8(D)  Outer instance pointer: domain_8(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _5 = check_service.part.0 (service_8(D), rr_7(D));
  Starting walk at: _5 = check_service.part.0 (service_8(D), rr_7(D));
  instance pointer: service_8(D)  Outer instance pointer: service_8(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _5 = check_service.part.0 (service_8(D), rr_7(D));
  Starting walk at: _5 = check_service.part.0 (service_8(D), rr_7(D));
  instance pointer: rr_7(D)  Outer instance pointer: rr_7(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _4 = check_host.part.0 (netif_8(D), rr_7(D), reverse_v6_reply_9(D));
  Starting walk at: _4 = check_host.part.0 (netif_8(D), rr_7(D), reverse_v6_reply_9(D));
  instance pointer: netif_8(D)  Outer instance pointer: netif_8(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _4 = check_host.part.0 (netif_8(D), rr_7(D), reverse_v6_reply_9(D));
  Starting walk at: _4 = check_host.part.0 (netif_8(D), rr_7(D), reverse_v6_reply_9(D));
  instance pointer: rr_7(D)  Outer instance pointer: rr_7(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _4 = check_host.part.0 (netif_8(D), rr_7(D), reverse_v6_reply_9(D));
  Starting walk at: _4 = check_host.part.0 (netif_8(D), rr_7(D), reverse_v6_reply_9(D));
  instance pointer: reverse_v6_reply_9(D)  Outer instance pointer: reverse_v6_reply_9(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: res_18 = mdns_domain_add_label (domain_13(D), _1, _4);
  Starting walk at: res_18 = mdns_domain_add_label (domain_13(D), _1, _4);
  instance pointer: domain_13(D)  Outer instance pointer: domain_13(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:memset (domain_13(D), 0, 260);
Determining dynamic type for call: res_18 = mdns_domain_add_label (domain_13(D), _1, _4);
  Starting walk at: res_18 = mdns_domain_add_label (domain_13(D), _1, _4);
  instance pointer: _1  Outer instance pointer: service_16(D) offset: 2080 (bits) vtbl reference: 
  Function call may change dynamic type:memset (domain_13(D), 0, 260);
Determining dynamic type for call: res_20 = mdns_domain_add_label (domain_13(D), _5, _8);
  Starting walk at: res_20 = mdns_domain_add_label (domain_13(D), _5, _8);
  instance pointer: domain_13(D)  Outer instance pointer: domain_13(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:memset (domain_13(D), 0, 260);
  Function call may change dynamic type:res_18 = mdns_domain_add_label (domain_13(D), _1, _4);
Determining dynamic type for call: res_20 = mdns_domain_add_label (domain_13(D), _5, _8);
  Starting walk at: res_20 = mdns_domain_add_label (domain_13(D), _5, _8);
  instance pointer: _5  Outer instance pointer: service_16(D) offset: 2592 (bits) vtbl reference: 
  Function call may change dynamic type:memset (domain_13(D), 0, 260);
  Function call may change dynamic type:res_18 = mdns_domain_add_label (domain_13(D), _1, _4);
Determining dynamic type for call: _2 = mdns_build_service_domain.part.0 (domain_13(D), service_16(D));
  Starting walk at: _2 = mdns_build_service_domain.part.0 (domain_13(D), service_16(D));
  instance pointer: domain_13(D)  Outer instance pointer: domain_13(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_20 = mdns_domain_add_label (domain_13(D), _5, _8);
  Function call may change dynamic type:memset (domain_13(D), 0, 260);
  Function call may change dynamic type:res_18 = mdns_domain_add_label (domain_13(D), _1, _4);
Determining dynamic type for call: _2 = mdns_build_service_domain.part.0 (domain_13(D), service_16(D));
  Starting walk at: _2 = mdns_build_service_domain.part.0 (domain_13(D), service_16(D));
  instance pointer: service_16(D)  Outer instance pointer: service_16(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_20 = mdns_domain_add_label (domain_13(D), _5, _8);
  Function call may change dynamic type:memset (domain_13(D), 0, 260);
  Function call may change dynamic type:res_18 = mdns_domain_add_label (domain_13(D), _1, _4);
Determining dynamic type for call: res_7 = mdns_domain_add_label (domain_4(D), "_services", 9);
  Starting walk at: res_7 = mdns_domain_add_label (domain_4(D), "_services", 9);
  instance pointer: domain_4(D)  Outer instance pointer: domain_4(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:memset (domain_4(D), 0, 260);
Determining dynamic type for call: res_7 = mdns_domain_add_label (domain_4(D), "_services", 9);
  Starting walk at: res_7 = mdns_domain_add_label (domain_4(D), "_services", 9);
  instance pointer: "_services"  Outer instance pointer: "_services" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: res_9 = mdns_domain_add_label (domain_4(D), "_dns-sd", 7);
  Starting walk at: res_9 = mdns_domain_add_label (domain_4(D), "_dns-sd", 7);
  instance pointer: domain_4(D)  Outer instance pointer: domain_4(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_7 = mdns_domain_add_label (domain_4(D), "_services", 9);
  Function call may change dynamic type:memset (domain_4(D), 0, 260);
Determining dynamic type for call: res_9 = mdns_domain_add_label (domain_4(D), "_dns-sd", 7);
  Starting walk at: res_9 = mdns_domain_add_label (domain_4(D), "_dns-sd", 7);
  instance pointer: "_dns-sd"  Outer instance pointer: "_dns-sd" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = mdns_build_dnssd_domain.part.0 (domain_4(D));
  Starting walk at: _1 = mdns_build_dnssd_domain.part.0 (domain_4(D));
  instance pointer: domain_4(D)  Outer instance pointer: domain_4(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_9 = mdns_domain_add_label (domain_4(D), "_dns-sd", 7);
  Function call may change dynamic type:res_7 = mdns_domain_add_label (domain_4(D), "_services", 9);
  Function call may change dynamic type:memset (domain_4(D), 0, 260);
Determining dynamic type for call: res_11 = mdns_domain_add_label (domain_7(D), _1, _3);
  Starting walk at: res_11 = mdns_domain_add_label (domain_7(D), _1, _3);
  instance pointer: domain_7(D)  Outer instance pointer: domain_7(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:memset (domain_7(D), 0, 260);
Determining dynamic type for call: res_11 = mdns_domain_add_label (domain_7(D), _1, _3);
  Starting walk at: res_11 = mdns_domain_add_label (domain_7(D), _1, _3);
  instance pointer: _1  Outer instance pointer: mdns_9(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:memset (domain_7(D), 0, 260);
Determining dynamic type for call: _13 = mdns_add_dotlocal (domain_7(D));
  Starting walk at: _13 = mdns_add_dotlocal (domain_7(D));
  instance pointer: domain_7(D)  Outer instance pointer: domain_7(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_11 = mdns_domain_add_label (domain_7(D), _1, _3);
  Function call may change dynamic type:memset (domain_7(D), 0, 260);
Determining dynamic type for call: res_5 = mdns_domain_add_label (domain_3(D), "local", 5);
  Starting walk at: res_5 = mdns_domain_add_label (domain_3(D), "local", 5);
  instance pointer: domain_3(D)  Outer instance pointer: domain_3(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: res_5 = mdns_domain_add_label (domain_3(D), "local", 5);
  Starting walk at: res_5 = mdns_domain_add_label (domain_3(D), "local", 5);
  instance pointer: "local"  Outer instance pointer: "local" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _6 = mdns_add_dotlocal.part.0 (domain_3(D));
  Starting walk at: _6 = mdns_add_dotlocal.part.0 (domain_3(D));
  instance pointer: domain_3(D)  Outer instance pointer: domain_3(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_5 = mdns_domain_add_label (domain_3(D), "local", 5);
Determining dynamic type for call: _3 = mdns_build_reverse_v6_domain.part.0 (domain_16(D));
  Starting walk at: _3 = mdns_build_reverse_v6_domain.part.0 (domain_16(D));
  instance pointer: domain_16(D)  Outer instance pointer: domain_16(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:memset (domain_16(D), 0, 260);
  Function call may change dynamic type:res_27 = mdns_domain_add_label (domain_16(D), &buf, 1);
Determining dynamic type for call: res_27 = mdns_domain_add_label (domain_16(D), &buf, 1);
  Starting walk at: res_27 = mdns_domain_add_label (domain_16(D), &buf, 1);
  instance pointer: domain_16(D)  Outer instance pointer: domain_16(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:memset (domain_16(D), 0, 260);
  Function call may change dynamic type:res_27 = mdns_domain_add_label (domain_16(D), &buf, 1);
Determining dynamic type for call: res_27 = mdns_domain_add_label (domain_16(D), &buf, 1);
  Starting walk at: res_27 = mdns_domain_add_label (domain_16(D), &buf, 1);
  instance pointer: &buf  Outer instance pointer: buf offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_27 = mdns_domain_add_label (domain_16(D), &buf, 1);
Determining dynamic type for call: res_16 = mdns_domain_add_label (domain_9(D), "in-addr", 7);
  Starting walk at: res_16 = mdns_domain_add_label (domain_9(D), "in-addr", 7);
  instance pointer: domain_9(D)  Outer instance pointer: domain_9(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:memset (domain_9(D), 0, 260);
  Function call may change dynamic type:res_22 = mdns_domain_add_label (domain_9(D), &buf, _5);
  Function call may change dynamic type:lwip_itoa (&buf, 4, _3);
Determining dynamic type for call: res_16 = mdns_domain_add_label (domain_9(D), "in-addr", 7);
  Starting walk at: res_16 = mdns_domain_add_label (domain_9(D), "in-addr", 7);
  instance pointer: "in-addr"  Outer instance pointer: "in-addr" offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _14 = mdns_build_reverse_v4_domain.part.0 (domain_9(D));
  Starting walk at: _14 = mdns_build_reverse_v4_domain.part.0 (domain_9(D));
  instance pointer: domain_9(D)  Outer instance pointer: domain_9(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:res_16 = mdns_domain_add_label (domain_9(D), "in-addr", 7);
  Function call may change dynamic type:memset (domain_9(D), 0, 260);
  Function call may change dynamic type:res_22 = mdns_domain_add_label (domain_9(D), &buf, _5);
  Function call may change dynamic type:lwip_itoa (&buf, 4, _3);
Determining dynamic type for call: res_22 = mdns_domain_add_label (domain_9(D), &buf, _5);
  Starting walk at: res_22 = mdns_domain_add_label (domain_9(D), &buf, _5);
  instance pointer: domain_9(D)  Outer instance pointer: domain_9(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:lwip_itoa (&buf, 4, _3);
  Function call may change dynamic type:memset (domain_9(D), 0, 260);
  Function call may change dynamic type:res_22 = mdns_domain_add_label (domain_9(D), &buf, _5);
  Function call may change dynamic type:lwip_itoa (&buf, 4, _3);
Determining dynamic type for call: res_22 = mdns_domain_add_label (domain_9(D), &buf, _5);
  Starting walk at: res_22 = mdns_domain_add_label (domain_9(D), &buf, _5);
  instance pointer: &buf  Outer instance pointer: buf offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:lwip_itoa (&buf, 4, _3);
  Function call may change dynamic type:res_22 = mdns_domain_add_label (domain_9(D), &buf, _5);
  Function call may change dynamic type:lwip_itoa (&buf, 4, _3);
Determining dynamic type for call: _2 (service_5(D), _3);
  Starting walk at: _2 (service_5(D), _3);
  instance pointer: service_5(D)  Outer instance pointer: service_5(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:memset (_1, 0, 260);
Determining dynamic type for call: _2 (service_5(D), _3);
  Starting walk at: _2 (service_5(D), _3);
  instance pointer: _3  Outer instance pointer: _3 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:memset (_1, 0, 260);
Determining dynamic type for call: _3 = mdns_domain_eq.part.0 (a_8(D), b_9(D));
  Starting walk at: _3 = mdns_domain_eq.part.0 (a_8(D), b_9(D));
  instance pointer: a_8(D)  Outer instance pointer: a_8(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _3 = mdns_domain_eq.part.0 (a_8(D), b_9(D));
  Starting walk at: _3 = mdns_domain_eq.part.0 (a_8(D), b_9(D));
  instance pointer: b_9(D)  Outer instance pointer: b_9(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _7 = mdns_readname_loop (p_4(D), offset_5(D), domain_2(D), 0);
  Starting walk at: _7 = mdns_readname_loop (p_4(D), offset_5(D), domain_2(D), 0);
  instance pointer: p_4(D)  Outer instance pointer: p_4(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:memset (domain_2(D), 0, 260);
Determining dynamic type for call: _7 = mdns_readname_loop (p_4(D), offset_5(D), domain_2(D), 0);
  Starting walk at: _7 = mdns_readname_loop (p_4(D), offset_5(D), domain_2(D), 0);
  instance pointer: domain_2(D)  Outer instance pointer: domain_2(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:memset (domain_2(D), 0, 260);
Determining dynamic type for call: res_32 = mdns_domain_add_label_pbuf (domain_30(D), p_25(D), offset_28, c_27);
  Starting walk at: res_32 = mdns_domain_add_label_pbuf (domain_30(D), p_25(D), offset_28, c_27);
  instance pointer: domain_30(D)  Outer instance pointer: domain_30(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:c_27 = pbuf_get_at (p_25(D), offset_18);
  Function call may change dynamic type:res_32 = mdns_domain_add_label_pbuf (domain_30(D), p_25(D), offset_28, c_27);
  Function call may change dynamic type:c_27 = pbuf_get_at (p_25(D), offset_18);
Determining dynamic type for call: res_32 = mdns_domain_add_label_pbuf (domain_30(D), p_25(D), offset_28, c_27);
  Starting walk at: res_32 = mdns_domain_add_label_pbuf (domain_30(D), p_25(D), offset_28, c_27);
  instance pointer: p_25(D)  Outer instance pointer: p_25(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:c_27 = pbuf_get_at (p_25(D), offset_18);
  Function call may change dynamic type:res_32 = mdns_domain_add_label_pbuf (domain_30(D), p_25(D), offset_28, c_27);
  Function call may change dynamic type:c_27 = pbuf_get_at (p_25(D), offset_18);
Determining dynamic type for call: res_38 = mdns_readname_loop (p_25(D), jumpaddr_35, domain_30(D), _12);
  Starting walk at: res_38 = mdns_readname_loop (p_25(D), jumpaddr_35, domain_30(D), _12);
  instance pointer: p_25(D)  Outer instance pointer: p_25(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_8 = pbuf_get_at (p_25(D), offset_4);
  Function call may change dynamic type:c_27 = pbuf_get_at (p_25(D), offset_18);
  Function call may change dynamic type:res_32 = mdns_domain_add_label_pbuf (domain_30(D), p_25(D), offset_28, c_27);
  Function call may change dynamic type:c_27 = pbuf_get_at (p_25(D), offset_18);
Determining dynamic type for call: res_38 = mdns_readname_loop (p_25(D), jumpaddr_35, domain_30(D), _12);
  Starting walk at: res_38 = mdns_readname_loop (p_25(D), jumpaddr_35, domain_30(D), _12);
  instance pointer: domain_30(D)  Outer instance pointer: domain_30(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_8 = pbuf_get_at (p_25(D), offset_4);
  Function call may change dynamic type:c_27 = pbuf_get_at (p_25(D), offset_18);
  Function call may change dynamic type:res_32 = mdns_domain_add_label_pbuf (domain_30(D), p_25(D), offset_28, c_27);
  Function call may change dynamic type:c_27 = pbuf_get_at (p_25(D), offset_18);
Determining dynamic type for call: err_16 = mdns_domain_add_label_base (domain_13(D), len_14(D));
  Starting walk at: err_16 = mdns_domain_add_label_base (domain_13(D), len_14(D));
  instance pointer: domain_13(D)  Outer instance pointer: domain_13(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: err_7 = mdns_domain_add_label_base (domain_4(D), len_5(D));
  Starting walk at: err_7 = mdns_domain_add_label_base (domain_4(D), len_5(D));
  instance pointer: domain_4(D)  Outer instance pointer: domain_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _2 = mdns_domain_add_label.part.0 (domain_4(D), label_8(D), len_5(D));
  Starting walk at: _2 = mdns_domain_add_label.part.0 (domain_4(D), label_8(D), len_5(D));
  instance pointer: domain_4(D)  Outer instance pointer: domain_4(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_7 = mdns_domain_add_label_base (domain_4(D), len_5(D));
Determining dynamic type for call: _2 = mdns_domain_add_label.part.0 (domain_4(D), label_8(D), len_5(D));
  Starting walk at: _2 = mdns_domain_add_label.part.0 (domain_4(D), label_8(D), len_5(D));
  instance pointer: label_8(D)  Outer instance pointer: label_8(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_7 = mdns_domain_add_label_base (domain_4(D), len_5(D));

IPA structures before propagation:

Jump functions:
  Jump functions of caller  mdns_probe.part.0/104:
  Jump functions of caller  mdns_resp_announce.part.0/103:
    callsite  mdns_resp_announce.part.0/103 -> mdns_announce/40 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: &ip6_addr_any
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  mdns_resp_announce.part.0/103 -> mdns_announce/40 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: &ip_addr_any
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  mdns_add_question.part.0/102:
  Jump functions of caller  mdns_compress_domain.part.0/101:
    callsite  mdns_compress_domain.part.0/101 -> mdns_readname/11 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  check_service.part.0/100:
    callsite  check_service.part.0/100 -> mdns_build_dnssd_domain/19 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  check_service.part.0/100 -> mdns_domain_eq/13 : 
       param 0: ANCESTOR: 1, offset 0
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  check_service.part.0/100 -> mdns_build_service_domain/20 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  check_service.part.0/100 -> mdns_domain_eq/13 : 
       param 0: ANCESTOR: 1, offset 0
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  check_service.part.0/100 -> mdns_build_service_domain/20 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
    callsite  check_service.part.0/100 -> mdns_domain_eq/13 : 
       param 0: ANCESTOR: 1, offset 0
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  check_host.part.0/99:
    callsite  check_host.part.0/99 -> mdns_build_reverse_v6_domain/16 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  check_host.part.0/99 -> mdns_domain_eq/13 : 
       param 0: ANCESTOR: 1, offset 0
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  check_host.part.0/99 -> mdns_build_reverse_v4_domain/15 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: ANCESTOR: 0, offset 32
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  check_host.part.0/99 -> mdns_domain_eq/13 : 
       param 0: ANCESTOR: 1, offset 0
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  check_host.part.0/99 -> mdns_build_host_domain/18 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  check_host.part.0/99 -> mdns_domain_eq/13 : 
       param 0: ANCESTOR: 1, offset 0
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  mdns_domain_eq.part.0/98:
  Jump functions of caller  mdns_read_question.part.0/97:
  Jump functions of caller  mdns_build_dnssd_domain.part.0/96:
    callsite  mdns_build_dnssd_domain.part.0/96 -> mdns_domain_add_label/8 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  mdns_build_dnssd_domain.part.0/96 -> mdns_add_dotlocal/17 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  mdns_build_reverse_v6_domain.part.0/95:
    callsite  mdns_build_reverse_v6_domain.part.0/95 -> mdns_domain_add_label/8 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: "ip6"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 2: CONST: 3
         value: 0x3, mask: 0x0
         Unknown VR
    callsite  mdns_build_reverse_v6_domain.part.0/95 -> mdns_domain_add_label/8 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: "arpa"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 2: CONST: 4
         value: 0x4, mask: 0x0
         Unknown VR
    callsite  mdns_build_reverse_v6_domain.part.0/95 -> mdns_domain_add_label/8 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0B
         value: 0x0, mask: 0xfffffff8
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  mdns_build_reverse_v4_domain.part.0/94:
    callsite  mdns_build_reverse_v4_domain.part.0/94 -> mdns_domain_add_label/8 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: "arpa"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 2: CONST: 4
         value: 0x4, mask: 0x0
         Unknown VR
    callsite  mdns_build_reverse_v4_domain.part.0/94 -> mdns_domain_add_label/8 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0B
         value: 0x0, mask: 0xfffffff8
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  mdns_build_service_domain.part.0/93:
    callsite  mdns_build_service_domain.part.0/93 -> mdns_domain_add_label/8 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  mdns_build_service_domain.part.0/93 -> mdns_add_dotlocal/17 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  mdns_add_dotlocal.part.0/92:
    callsite  mdns_add_dotlocal.part.0/92 -> mdns_domain_add_label/8 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0B
         value: 0x0, mask: 0xfffffff8
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  mdns_domain_add_label.part.0/91:
  Jump functions of caller  pbuf_memcmp/90:
  Jump functions of caller  netif_alloc_client_data_id/89:
  Jump functions of caller  udp_recv/88:
  Jump functions of caller  udp_bind/86:
  Jump functions of caller  udp_new_ip_type/85:
  Jump functions of caller  rand/84:
  Jump functions of caller  lwip_htonl/83:
  Jump functions of caller  lwip_itoa/82:
  Jump functions of caller  udp_sendto_if/81:
  Jump functions of caller  pbuf_realloc/80:
  Jump functions of caller  pbuf_take/79:
  Jump functions of caller  pbuf_take_at/78:
  Jump functions of caller  lwip_htons/77:
  Jump functions of caller  pbuf_alloc/76:
  Jump functions of caller  pbuf_free/75:
  Jump functions of caller  sys_timeout/74:
  Jump functions of caller  mld6_leavegroup_netif/71:
  Jump functions of caller  igmp_leavegroup_netif/70:
  Jump functions of caller  sys_untimeout/69:
  Jump functions of caller  mem_free/68:
  Jump functions of caller  mld6_joingroup_netif/67:
  Jump functions of caller  igmp_joingroup_netif/66:
  Jump functions of caller  mem_calloc/65:
  Jump functions of caller  strlen/64:
  Jump functions of caller  memcmp/63:
  Jump functions of caller  lwip_strnicmp/62:
  Jump functions of caller  pbuf_copy_partial/61:
  Jump functions of caller  pbuf_get_at/60:
  Jump functions of caller  memset/59:
  Jump functions of caller  memcpy/58:
  Jump functions of caller  mdns_resp_init/57:
  Jump functions of caller  mdns_resp_restart/56:
  Jump functions of caller  mdns_resp_register_name_result_cb/55:
  Jump functions of caller  mdns_resp_announce/54:
    callsite  mdns_resp_announce/54 -> mdns_resp_announce.part.0/103 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  mdns_resp_add_service_txtitem/53:
    callsite  mdns_resp_add_service_txtitem/53 -> mdns_domain_add_label/8 : 
       param 0: ANCESTOR: 0, offset 0, agg_preserved
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  mdns_resp_rename_service/52:
    callsite  mdns_resp_rename_service/52 -> mdns_resp_restart/56 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  mdns_resp_del_service/51:
  Jump functions of caller  mdns_resp_add_service/50:
    callsite  mdns_resp_add_service/50 -> mdns_resp_restart/56 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  mdns_resp_rename_netif/49:
    callsite  mdns_resp_rename_netif/49 -> mdns_resp_restart/56 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  mdns_resp_remove_netif/48:
  Jump functions of caller  mdns_resp_add_netif/47:
    callsite  mdns_resp_add_netif/47 -> mdns_resp_restart/56 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  mdns_probe/46:
    callsite  mdns_probe/46 -> mdns_probe.part.0/104 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  mdns_probe/46 -> mdns_send_probe/45 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: &ip6_addr_any
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  mdns_probe/46 -> mdns_send_probe/45 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: &ip_addr_any
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  mdns_probe/46 -> mdns_resp_announce/54 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    indirect simple callsite, calling param -1, offset 0, for stmt mdns_name_result_cb.9_4 (arg_13(D), 1);
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
  Jump functions of caller  mdns_send_probe/45:
    callsite  mdns_send_probe/45 -> mdns_send_outpacket/39 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  mdns_send_probe/45 -> mdns_add_question/25 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: CONST: 255
         value: 0xff, mask: 0x0
         Unknown VR
       param 3: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 4: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
    callsite  mdns_send_probe/45 -> mdns_build_service_domain/20 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
    callsite  mdns_send_probe/45 -> mdns_add_question/25 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: CONST: 255
         value: 0xff, mask: 0x0
         Unknown VR
       param 3: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 4: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
    callsite  mdns_send_probe/45 -> mdns_build_host_domain/18 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  mdns_recv/44:
    callsite  mdns_recv/44 -> mdns_handle_question/41 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  mdns_recv/44 -> mdns_handle_response/42 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  mdns_handle_response/42:
    callsite  mdns_handle_response/42 -> mdns_domain_eq/13 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  mdns_handle_response/42 -> mdns_build_service_domain/20 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
    callsite  mdns_handle_response/42 -> mdns_domain_eq/13 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  mdns_handle_response/42 -> mdns_build_host_domain/18 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  mdns_handle_response/42 -> mdns_domain_debug_print/12 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  mdns_handle_response/42 -> mdns_read_answer/29 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  mdns_handle_response/42 -> mdns_read_question/28 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    indirect simple callsite, calling param -1, offset 0, for stmt mdns_name_result_cb.62_11 (_13, 0);
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  mdns_handle_question/41:
    callsite  mdns_handle_question/41 -> mdns_send_outpacket/39 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: CONST: 132
         value: 0x84, mask: 0x0
         Unknown VR
    callsite  mdns_handle_question/41 -> mdns_prepare_txtdata/14 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  mdns_handle_question/41 -> mdns_domain_eq/13 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  mdns_handle_question/41 -> mdns_build_host_domain/18 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  mdns_handle_question/41 -> mdns_readname/11 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  mdns_handle_question/41 -> mdns_domain_eq/13 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  mdns_handle_question/41 -> mdns_build_service_domain/20 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
    callsite  mdns_handle_question/41 -> mdns_domain_eq/13 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  mdns_handle_question/41 -> mdns_build_service_domain/20 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  mdns_handle_question/41 -> mdns_readname/11 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  mdns_handle_question/41 -> check_service/22 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  mdns_handle_question/41 -> mdns_domain_eq/13 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  mdns_handle_question/41 -> mdns_build_host_domain/18 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  mdns_handle_question/41 -> mdns_readname/11 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  mdns_handle_question/41 -> check_host/21 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: UNKNOWN
         Aggregate passed by reference:
           offset: 0, cst: 0
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  mdns_handle_question/41 -> mdns_domain_debug_print/12 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  mdns_handle_question/41 -> mdns_read_answer/29 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  mdns_handle_question/41 -> mdns_add_question/25 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 4: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  mdns_handle_question/41 -> check_service/22 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  mdns_handle_question/41 -> check_host/21 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: UNKNOWN
         value: 0x2, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  mdns_handle_question/41 -> mdns_domain_debug_print/12 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  mdns_handle_question/41 -> mdns_read_question/28 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  mdns_handle_question/41 -> mdns_init_outpacket/38 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  mdns_announce/40:
    callsite  mdns_announce/40 -> mdns_send_outpacket/39 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: CONST: 132
         value: 0x84, mask: 0x0
         Unknown VR
  Jump functions of caller  mdns_send_outpacket/39:
    callsite  mdns_send_outpacket/39 -> mdns_add_a_answer/30 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         VR  [0, 255]
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  mdns_send_outpacket/39 -> mdns_add_aaaa_answer/32 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         VR  [0, 255]
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0x3
         VR  [0, 3]
    callsite  mdns_send_outpacket/39 -> mdns_add_txt_answer/37 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         VR  [0, 255]
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  mdns_send_outpacket/39 -> mdns_add_srv_answer/36 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         VR  [0, 255]
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  mdns_send_outpacket/39 -> mdns_add_txt_answer/37 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         VR  [0, 255]
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  mdns_send_outpacket/39 -> mdns_add_srv_answer/36 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         VR  [0, 255]
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  mdns_send_outpacket/39 -> mdns_add_servicename_ptr_answer/35 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  mdns_send_outpacket/39 -> mdns_add_servicetype_ptr_answer/34 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  mdns_send_outpacket/39 -> mdns_add_hostv6_ptr_answer/33 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         VR  [0, 255]
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0x7fffffff
         VR  [0, 2147483647]
    callsite  mdns_send_outpacket/39 -> mdns_add_aaaa_answer/32 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         VR  [0, 255]
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0x3
         VR  [0, 3]
    callsite  mdns_send_outpacket/39 -> mdns_add_hostv4_ptr_answer/31 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         VR  [0, 255]
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  mdns_send_outpacket/39 -> mdns_add_a_answer/30 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         VR  [0, 255]
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  mdns_init_outpacket/38:
  Jump functions of caller  mdns_add_txt_answer/37:
    callsite  mdns_add_txt_answer/37 -> mdns_add_answer/26 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: CONST: 16
         value: 0x10, mask: 0x0
         Unknown VR
       param 3: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 4: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 5: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 6: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 7: UNKNOWN
         value: 0x0, mask: 0xffff
         VR  [0, 65535]
       param 8: CONST: 0B
         value: 0x0, mask: 0xfffffff8
         Unknown VR
    callsite  mdns_add_txt_answer/37 -> mdns_prepare_txtdata/14 : 
       param 0: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  mdns_add_txt_answer/37 -> mdns_build_service_domain/20 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
  Jump functions of caller  mdns_add_srv_answer/36:
    callsite  mdns_add_srv_answer/36 -> mdns_add_answer/26 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: CONST: 33
         value: 0x21, mask: 0x0
         Unknown VR
       param 3: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 4: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 5: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 6: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 7: CONST: 6
         value: 0x6, mask: 0x0
         Unknown VR
       param 8: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  mdns_add_srv_answer/36 -> mdns_build_host_domain/18 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  mdns_add_srv_answer/36 -> mdns_build_service_domain/20 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: PASS THROUGH: 3, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
  Jump functions of caller  mdns_add_servicename_ptr_answer/35:
    callsite  mdns_add_servicename_ptr_answer/35 -> mdns_add_answer/26 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: CONST: 12
         value: 0xc, mask: 0x0
         Unknown VR
       param 3: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 4: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 5: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 6: CONST: 0B
         value: 0x0, mask: 0xfffffff8
         Unknown VR
       param 7: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 8: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  mdns_add_servicename_ptr_answer/35 -> mdns_build_service_domain/20 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
    callsite  mdns_add_servicename_ptr_answer/35 -> mdns_build_service_domain/20 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  mdns_add_servicetype_ptr_answer/34:
    callsite  mdns_add_servicetype_ptr_answer/34 -> mdns_add_answer/26 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: CONST: 12
         value: 0xc, mask: 0x0
         Unknown VR
       param 3: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 4: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 5: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 6: CONST: 0B
         value: 0x0, mask: 0xfffffff8
         Unknown VR
       param 7: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 8: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  mdns_add_servicetype_ptr_answer/34 -> mdns_build_dnssd_domain/19 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  mdns_add_servicetype_ptr_answer/34 -> mdns_build_service_domain/20 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  mdns_add_hostv6_ptr_answer/33:
    callsite  mdns_add_hostv6_ptr_answer/33 -> mdns_add_answer/26 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: CONST: 12
         value: 0xc, mask: 0x0
         Unknown VR
       param 3: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 4: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 5: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 6: CONST: 0B
         value: 0x0, mask: 0xfffffff8
         Unknown VR
       param 7: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 8: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  mdns_add_hostv6_ptr_answer/33 -> mdns_build_reverse_v6_domain/16 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  mdns_add_hostv6_ptr_answer/33 -> mdns_build_host_domain/18 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  mdns_add_aaaa_answer/32:
    callsite  mdns_add_aaaa_answer/32 -> mdns_add_answer/26 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: CONST: 28
         value: 0x1c, mask: 0x0
         Unknown VR
       param 3: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 4: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 5: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 6: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 7: CONST: 16
         value: 0x10, mask: 0x0
         Unknown VR
       param 8: CONST: 0B
         value: 0x0, mask: 0xfffffff8
         Unknown VR
    callsite  mdns_add_aaaa_answer/32 -> mdns_build_host_domain/18 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  mdns_add_hostv4_ptr_answer/31:
    callsite  mdns_add_hostv4_ptr_answer/31 -> mdns_add_answer/26 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: CONST: 12
         value: 0xc, mask: 0x0
         Unknown VR
       param 3: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 4: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 5: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 6: CONST: 0B
         value: 0x0, mask: 0xfffffff8
         Unknown VR
       param 7: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 8: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  mdns_add_hostv4_ptr_answer/31 -> mdns_build_reverse_v4_domain/15 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: ANCESTOR: 2, offset 32
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
    callsite  mdns_add_hostv4_ptr_answer/31 -> mdns_build_host_domain/18 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  mdns_add_a_answer/30:
    callsite  mdns_add_a_answer/30 -> mdns_add_answer/26 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 3: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 4: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 5: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 6: ANCESTOR: 2, offset 32
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 7: CONST: 4
         value: 0x4, mask: 0x0
         Unknown VR
       param 8: CONST: 0B
         value: 0x0, mask: 0xfffffff8
         Unknown VR
    callsite  mdns_add_a_answer/30 -> mdns_build_host_domain/18 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  mdns_read_answer/29:
    callsite  mdns_read_answer/29 -> mdns_read_rr_info/27 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: ANCESTOR: 1, offset 0
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
  Jump functions of caller  mdns_read_question/28:
    callsite  mdns_read_question/28 -> mdns_read_question.part.0/97 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  mdns_read_question/28 -> mdns_read_rr_info/27 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: ANCESTOR: 1, offset 0
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
  Jump functions of caller  mdns_read_rr_info/27:
    callsite  mdns_read_rr_info/27 -> mdns_readname/11 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: ANCESTOR: 1, offset 0, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  mdns_add_answer/26:
    callsite  mdns_add_answer/26 -> mdns_write_domain/24 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 8, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  mdns_add_answer/26 -> mdns_add_question/25 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 4: PASS THROUGH: 4, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
  Jump functions of caller  mdns_add_question/25:
    callsite  mdns_add_question/25 -> mdns_add_question.part.0/102 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 3: PASS THROUGH: 4, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
    callsite  mdns_add_question/25 -> mdns_write_domain/24 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  mdns_write_domain/24:
    callsite  mdns_write_domain/24 -> mdns_compress_domain/23 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffe
         VR  ~[0, 0]
       param 2: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  mdns_compress_domain/23:
    callsite  mdns_compress_domain/23 -> mdns_compress_domain.part.0/101 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  check_service/22:
    callsite  check_service/22 -> check_service.part.0/100 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  check_host/21:
    callsite  check_host/21 -> check_host.part.0/99 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  mdns_build_service_domain/20:
    callsite  mdns_build_service_domain/20 -> mdns_build_service_domain.part.0/93 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  mdns_build_service_domain/20 -> mdns_domain_add_label/8 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 2: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  mdns_build_service_domain/20 -> mdns_domain_add_label/8 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 2: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  mdns_build_dnssd_domain/19:
    callsite  mdns_build_dnssd_domain/19 -> mdns_build_dnssd_domain.part.0/96 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  mdns_build_dnssd_domain/19 -> mdns_domain_add_label/8 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: "_dns-sd"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 2: CONST: 7
         value: 0x7, mask: 0x0
         Unknown VR
    callsite  mdns_build_dnssd_domain/19 -> mdns_domain_add_label/8 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: "_services"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 2: CONST: 9
         value: 0x9, mask: 0x0
         Unknown VR
  Jump functions of caller  mdns_build_host_domain/18:
    callsite  mdns_build_host_domain/18 -> mdns_add_dotlocal/17 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  mdns_build_host_domain/18 -> mdns_domain_add_label/8 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 2: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  mdns_add_dotlocal/17:
    callsite  mdns_add_dotlocal/17 -> mdns_add_dotlocal.part.0/92 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  mdns_add_dotlocal/17 -> mdns_domain_add_label/8 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: "local"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 2: CONST: 5
         value: 0x5, mask: 0x0
         Unknown VR
  Jump functions of caller  mdns_build_reverse_v6_domain/16:
    callsite  mdns_build_reverse_v6_domain/16 -> mdns_build_reverse_v6_domain.part.0/95 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  mdns_build_reverse_v6_domain/16 -> mdns_domain_add_label/8 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
  Jump functions of caller  mdns_build_reverse_v4_domain/15:
    callsite  mdns_build_reverse_v4_domain/15 -> mdns_build_reverse_v4_domain.part.0/94 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  mdns_build_reverse_v4_domain/15 -> mdns_domain_add_label/8 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: "in-addr"
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 2: CONST: 7
         value: 0x7, mask: 0x0
         Unknown VR
    callsite  mdns_build_reverse_v4_domain/15 -> mdns_domain_add_label/8 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: UNKNOWN
         value: 0x0, mask: 0x3
         VR  [0, 3]
  Jump functions of caller  mdns_prepare_txtdata/14:
    indirect aggregate callsite, calling param 0, offset 3104, by reference, for stmt _2 (service_5(D), _3);
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  mdns_domain_eq/13:
    callsite  mdns_domain_eq/13 -> mdns_domain_eq.part.0/98 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  mdns_domain_debug_print/12:
  Jump functions of caller  mdns_readname/11:
    callsite  mdns_readname/11 -> mdns_readname_loop/10 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  mdns_readname_loop/10:
    callsite  mdns_readname_loop/10 -> mdns_domain_add_label_pbuf/9 : 
       param 0: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  mdns_readname_loop/10 -> mdns_readname_loop/10 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0x3fff
         VR  [0, 16383]
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 3, op plus_expr 1
         value: 0x0, mask: 0x7
         VR  [1, 6]
  Jump functions of caller  mdns_domain_add_label_pbuf/9:
    callsite  mdns_domain_add_label_pbuf/9 -> mdns_domain_add_label_base/7 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  mdns_domain_add_label/8:
    callsite  mdns_domain_add_label/8 -> mdns_domain_add_label.part.0/91 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  mdns_domain_add_label/8 -> mdns_domain_add_label_base/7 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  mdns_domain_add_label_base/7:

 Propagating constants:

Not considering mdns_resp_init for cloning; -fipa-cp-clone disabled.
Not considering mdns_resp_restart for cloning; -fipa-cp-clone disabled.
Not considering mdns_resp_register_name_result_cb for cloning; -fipa-cp-clone disabled.
Not considering mdns_resp_announce for cloning; -fipa-cp-clone disabled.
Not considering mdns_resp_add_service_txtitem for cloning; -fipa-cp-clone disabled.
Not considering mdns_resp_rename_service for cloning; -fipa-cp-clone disabled.
Not considering mdns_resp_del_service for cloning; -fipa-cp-clone disabled.
Not considering mdns_resp_add_service for cloning; -fipa-cp-clone disabled.
Not considering mdns_resp_rename_netif for cloning; -fipa-cp-clone disabled.
Not considering mdns_resp_remove_netif for cloning; -fipa-cp-clone disabled.
Not considering mdns_resp_add_netif for cloning; -fipa-cp-clone disabled.
Not considering mdns_probe for cloning; -fipa-cp-clone disabled.
Not considering mdns_recv for cloning; -fipa-cp-clone disabled.
Not considering mdns_compress_domain for cloning; -fipa-cp-clone disabled.
Not considering mdns_domain_eq for cloning; -fipa-cp-clone disabled.
Not considering mdns_readname for cloning; -fipa-cp-clone disabled.
Not considering mdns_domain_add_label for cloning; -fipa-cp-clone disabled.

overall_size: 2601, max_new_size: 11001
 - context independent values, size: 96, time_benefit: 2.000000
 - context independent values, size: 81, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.

IPA lattices after all propagation:

Lattices:
  Node: mdns_probe.part.0/104:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: mdns_resp_announce.part.0/103:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: mdns_add_question.part.0/102:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct mdns_outpacket * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
               255 [loc_time: 1, loc_size: 40, prop_time: 0, prop_size: 0]
               1 [loc_time: 1, loc_size: 40, prop_time: 0, prop_size: 0]
               28 [loc_time: 1, loc_size: 40, prop_time: 0, prop_size: 0]
               12 [loc_time: 1, loc_size: 40, prop_time: 0, prop_size: 0]
               33 [loc_time: 1, loc_size: 40, prop_time: 0, prop_size: 0]
               16 [loc_time: 1, loc_size: 40, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [2]: VARIABLE
               1 [loc_time: 1, loc_size: 39, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [3]: VARIABLE
               1 [loc_time: 2, loc_size: 38, prop_time: 0, prop_size: 0]
               0 [loc_time: 2, loc_size: 37, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x1, mask = 0xff
         u16_t [0, 255]
        AGGS VARIABLE
  Node: mdns_compress_domain.part.0/101:
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
  Node: check_service.part.0/100:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct mdns_rr_info * ~[0B, 0B]
        AGGS VARIABLE
  Node: check_host.part.0/99:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct mdns_rr_info * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         u8_t * ~[0B, 0B]
        AGGS VARIABLE
        ref offset 0: 0 [loc_time: 0, loc_size: 78, prop_time: 0, prop_size: 0]
  Node: mdns_domain_eq.part.0/98:
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
  Node: mdns_read_question.part.0/97:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct mdns_question * ~[0B, 0B]
        AGGS VARIABLE
  Node: mdns_build_dnssd_domain.part.0/96:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct mdns_domain * ~[0B, 0B]
        AGGS VARIABLE
  Node: mdns_build_reverse_v6_domain.part.0/95:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct mdns_domain * ~[0B, 0B]
        AGGS VARIABLE
  Node: mdns_build_reverse_v4_domain.part.0/94:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct mdns_domain * ~[0B, 0B]
        AGGS VARIABLE
  Node: mdns_build_service_domain.part.0/93:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct mdns_domain * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: mdns_add_dotlocal.part.0/92:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct mdns_domain * ~[0B, 0B]
        AGGS VARIABLE
  Node: mdns_domain_add_label.part.0/91:
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
  Node: mdns_resp_init/57:
  Node: mdns_resp_restart/56:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: mdns_resp_register_name_result_cb/55:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: mdns_resp_announce/54:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: mdns_resp_add_service_txtitem/53:
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
  Node: mdns_resp_rename_service/52:
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
  Node: mdns_resp_del_service/51:
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
  Node: mdns_resp_add_service/50:
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
  Node: mdns_resp_rename_netif/49:
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
  Node: mdns_resp_remove_netif/48:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: mdns_resp_add_netif/47:
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
  Node: mdns_probe/46:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: mdns_send_probe/45:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: &ip_addr_any [loc_time: 1, loc_size: 81, prop_time: 0, prop_size: 0]
               &ip6_addr_any [loc_time: 1, loc_size: 81, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         const struct ip_addr_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: mdns_recv/44:
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
  Node: mdns_handle_response/42:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct mdns_packet * ~[0B, 0B]
        AGGS VARIABLE
  Node: mdns_handle_question/41:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct mdns_packet * ~[0B, 0B]
        AGGS VARIABLE
  Node: mdns_announce/40:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: &ip_addr_any [loc_time: 1, loc_size: 43, prop_time: 0, prop_size: 0]
               &ip6_addr_any [loc_time: 1, loc_size: 43, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         const struct ip_addr_t * ~[0B, 0B]
        AGGS VARIABLE
  Node: mdns_send_outpacket/39:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct mdns_outpacket * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: 132 [loc_time: 1, loc_size: 301, prop_time: 0, prop_size: 0]
               0 [loc_time: 1, loc_size: 301, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x84
         u8_t [0, 132]
        AGGS VARIABLE
  Node: mdns_init_outpacket/38:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct mdns_outpacket * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct mdns_packet * ~[0B, 0B]
        AGGS VARIABLE
  Node: mdns_add_txt_answer/37:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct mdns_outpacket * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xff
         u16_t [0, 255]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: mdns_add_srv_answer/36:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct mdns_outpacket * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xff
         u16_t [0, 255]
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
  Node: mdns_add_servicename_ptr_answer/35:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct mdns_outpacket * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: mdns_add_servicetype_ptr_answer/34:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct mdns_outpacket * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: mdns_add_hostv6_ptr_answer/33:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct mdns_outpacket * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xff
         u16_t [0, 255]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x7fffffff
         int [0, +INF]
        AGGS VARIABLE
  Node: mdns_add_aaaa_answer/32:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct mdns_outpacket * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xff
         u16_t [0, 255]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x3
         int [0, 3]
        AGGS VARIABLE
  Node: mdns_add_hostv4_ptr_answer/31:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct mdns_outpacket * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xff
         u16_t [0, 255]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: mdns_add_a_answer/30:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct mdns_outpacket * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xff
         u16_t [0, 255]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: mdns_read_answer/29:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct mdns_packet * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct mdns_answer * ~[0B, 0B]
        AGGS VARIABLE
  Node: mdns_read_question/28:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct mdns_packet * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct mdns_question * ~[0B, 0B]
        AGGS VARIABLE
  Node: mdns_read_rr_info/27:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct mdns_packet * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct mdns_rr_info * ~[0B, 0B]
        AGGS VARIABLE
  Node: mdns_add_answer/26:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct mdns_outpacket * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct mdns_domain * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: 1 [loc_time: 2, loc_size: 89, prop_time: 0, prop_size: 0]
               28 [loc_time: 2, loc_size: 89, prop_time: 0, prop_size: 0]
               12 [loc_time: 2, loc_size: 89, prop_time: 0, prop_size: 0]
               33 [loc_time: 2, loc_size: 89, prop_time: 0, prop_size: 0]
               16 [loc_time: 2, loc_size: 89, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x10, mask = 0x3d
         u16_t [1, 33]
        AGGS VARIABLE
    param [3]: 1 [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x1, mask = 0x0
         u16_t [1, 1]
        AGGS VARIABLE
    param [4]: VARIABLE
               0 [loc_time: 2, loc_size: 89, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xff
         u16_t [0, 255]
        AGGS VARIABLE
    param [5]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [6]: VARIABLE
               0B [loc_time: 5, loc_size: 72, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [7]: VARIABLE
               4 [loc_time: 2, loc_size: 89, prop_time: 0, prop_size: 0]
               16 [loc_time: 2, loc_size: 89, prop_time: 0, prop_size: 0]
               0 [loc_time: 2, loc_size: 89, prop_time: 0, prop_size: 0]
               6 [loc_time: 2, loc_size: 89, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xffff
         size_t [0, 65535]
        AGGS VARIABLE
    param [8]: VARIABLE
               0B [loc_time: 5, loc_size: 77, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         VARYING
        AGGS VARIABLE
  Node: mdns_add_question/25:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct mdns_outpacket * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct mdns_domain * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: VARIABLE
               16 [loc_time: 1, loc_size: 35, prop_time: 0, prop_size: 0]
               33 [loc_time: 1, loc_size: 35, prop_time: 0, prop_size: 0]
               12 [loc_time: 1, loc_size: 35, prop_time: 0, prop_size: 0]
               28 [loc_time: 1, loc_size: 35, prop_time: 0, prop_size: 0]
               1 [loc_time: 1, loc_size: 35, prop_time: 0, prop_size: 0]
               255 [loc_time: 1, loc_size: 35, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [3]: VARIABLE
               1 [loc_time: 1, loc_size: 35, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [4]: VARIABLE
               0 [loc_time: 1, loc_size: 35, prop_time: 0, prop_size: 0]
               1 [loc_time: 1, loc_size: 35, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x1, mask = 0xff
         u16_t [0, 255]
        AGGS VARIABLE
  Node: mdns_write_domain/24:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct mdns_outpacket * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
               0B [loc_time: 1, loc_size: 66, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         VARYING
        AGGS VARIABLE
  Node: mdns_compress_domain/23:
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
  Node: check_service/22:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct mdns_rr_info * ~[0B, 0B]
        AGGS VARIABLE
  Node: check_host/21:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct mdns_rr_info * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         u8_t * ~[0B, 0B]
        AGGS VARIABLE
        ref offset 0: 0 [loc_time: 0, loc_size: 13, prop_time: 0, prop_size: 0]
  Node: mdns_build_service_domain/20:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct mdns_domain * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [2]: 0 [loc_time: 3, loc_size: 21, prop_time: 0, prop_size: 0]
               1 [loc_time: 3, loc_size: 31, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x1, mask = 0x1
         int [0, 1]
        AGGS VARIABLE
  Node: mdns_build_dnssd_domain/19:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct mdns_domain * ~[0B, 0B]
        AGGS VARIABLE
  Node: mdns_build_host_domain/18:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct mdns_domain * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: mdns_add_dotlocal/17:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct mdns_domain * ~[0B, 0B]
        AGGS VARIABLE
  Node: mdns_build_reverse_v6_domain/16:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct mdns_domain * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: mdns_build_reverse_v4_domain/15:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct mdns_domain * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: mdns_prepare_txtdata/14:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: mdns_domain_eq/13:
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
  Node: mdns_domain_debug_print/12:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct mdns_domain * ~[0B, 0B]
        AGGS VARIABLE
  Node: mdns_readname/11:
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
  Node: mdns_readname_loop/10:
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
    param [3]: VARIABLE
               0 [loc_time: 18, loc_size: 52, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         unsigned int [0, 6]
        AGGS VARIABLE
  Node: mdns_domain_add_label_pbuf/9:
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
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: mdns_domain_add_label/8:
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
  Node: mdns_domain_add_label_base/7:
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

IPA decision stage:

 - Creating a specialized node of mdns_add_answer/26 for all known contexts.
    replacing param #3 klass with const 1
Propagated bits info for function mdns_add_answer.constprop/105:
 param 0: value = 0x0, mask = 0xfffffffc
 param 1: value = 0x0, mask = 0xfffffffc
 param 2: value = 0x10, mask = 0x3d
 param 3: value = 0x1, mask = 0x0
 param 4: value = 0x0, mask = 0xff
 param 7: value = 0x0, mask = 0xffff
 param 8: value = 0x0, mask = 0xfffffffc
Propagated bits info for function mdns_add_question.part.0/102:
 param 0: value = 0x0, mask = 0xfffffffc
 param 3: value = 0x1, mask = 0xff
Propagated bits info for function check_service.part.0/100:
 param 1: value = 0x0, mask = 0xfffffffc
Propagated bits info for function check_host.part.0/99:
 param 1: value = 0x0, mask = 0xfffffffc
Propagated bits info for function mdns_read_question.part.0/97:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function mdns_build_dnssd_domain.part.0/96:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function mdns_build_reverse_v6_domain.part.0/95:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function mdns_build_reverse_v4_domain.part.0/94:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function mdns_build_service_domain.part.0/93:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function mdns_add_dotlocal.part.0/92:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function mdns_send_probe/45:
 param 1: value = 0x0, mask = 0xfffffffc
Propagated bits info for function mdns_handle_response/42:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function mdns_handle_question/41:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function mdns_announce/40:
 param 1: value = 0x0, mask = 0xfffffffc
Propagated bits info for function mdns_send_outpacket/39:
 param 0: value = 0x0, mask = 0xfffffffc
 param 1: value = 0x0, mask = 0x84
Propagated bits info for function mdns_init_outpacket/38:
 param 0: value = 0x0, mask = 0xfffffffc
 param 1: value = 0x0, mask = 0xfffffffc
Propagated bits info for function mdns_add_txt_answer/37:
 param 0: value = 0x0, mask = 0xfffffffc
 param 1: value = 0x0, mask = 0xff
Propagated bits info for function mdns_add_srv_answer/36:
 param 0: value = 0x0, mask = 0xfffffffc
 param 1: value = 0x0, mask = 0xff
Propagated bits info for function mdns_add_servicename_ptr_answer/35:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function mdns_add_servicetype_ptr_answer/34:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function mdns_add_hostv6_ptr_answer/33:
 param 0: value = 0x0, mask = 0xfffffffc
 param 1: value = 0x0, mask = 0xff
 param 3: value = 0x0, mask = 0x7fffffff
Propagated bits info for function mdns_add_aaaa_answer/32:
 param 0: value = 0x0, mask = 0xfffffffc
 param 1: value = 0x0, mask = 0xff
 param 3: value = 0x0, mask = 0x3
Propagated bits info for function mdns_add_hostv4_ptr_answer/31:
 param 0: value = 0x0, mask = 0xfffffffc
 param 1: value = 0x0, mask = 0xff
Propagated bits info for function mdns_add_a_answer/30:
 param 0: value = 0x0, mask = 0xfffffffc
 param 1: value = 0x0, mask = 0xff
Propagated bits info for function mdns_read_answer/29:
 param 0: value = 0x0, mask = 0xfffffffc
 param 1: value = 0x0, mask = 0xfffffffc
Propagated bits info for function mdns_read_question/28:
 param 0: value = 0x0, mask = 0xfffffffc
 param 1: value = 0x0, mask = 0xfffffffc
Propagated bits info for function mdns_read_rr_info/27:
 param 0: value = 0x0, mask = 0xfffffffc
 param 1: value = 0x0, mask = 0xfffffffc
Propagated bits info for function mdns_add_answer/26:
 param 0: value = 0x0, mask = 0xfffffffc
 param 1: value = 0x0, mask = 0xfffffffc
 param 2: value = 0x10, mask = 0x3d
 param 3: value = 0x1, mask = 0x0
 param 4: value = 0x0, mask = 0xff
 param 7: value = 0x0, mask = 0xffff
 param 8: value = 0x0, mask = 0xfffffffc
Propagated bits info for function mdns_add_question/25:
 param 0: value = 0x0, mask = 0xfffffffc
 param 1: value = 0x0, mask = 0xfffffffc
 param 4: value = 0x1, mask = 0xff
Propagated bits info for function mdns_write_domain/24:
 param 0: value = 0x0, mask = 0xfffffffc
 param 1: value = 0x0, mask = 0xfffffffc
Propagated bits info for function check_service/22:
 param 1: value = 0x0, mask = 0xfffffffc
Propagated bits info for function check_host/21:
 param 1: value = 0x0, mask = 0xfffffffc
Propagated bits info for function mdns_build_service_domain/20:
 param 0: value = 0x0, mask = 0xfffffffc
 param 2: value = 0x1, mask = 0x1
Propagated bits info for function mdns_build_dnssd_domain/19:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function mdns_build_host_domain/18:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function mdns_add_dotlocal/17:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function mdns_build_reverse_v6_domain/16:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function mdns_build_reverse_v4_domain/15:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function mdns_domain_debug_print/12:
 param 0: value = 0x0, mask = 0xfffffffc

IPA constant propagation end

Reclaiming functions: mdns_add_answer/26
Reclaiming variables:
Clearing address taken flags:
Symbol table:

mdns_add_answer.constprop.0/105 (mdns_add_answer.constprop) @064cf1c0
  Type: function definition analyzed
  Visibility:
  References: 
  Referring: 
  Clone of mdns_add_answer/26
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: mdns_add_hostv4_ptr_answer/31 (1073741824 (estimated locally),1.00 per call) mdns_add_hostv6_ptr_answer/33 (1073741824 (estimated locally),1.00 per call) mdns_add_servicetype_ptr_answer/34 (1073741824 (estimated locally),1.00 per call) mdns_add_servicename_ptr_answer/35 (1073741824 (estimated locally),1.00 per call) mdns_add_srv_answer/36 (1073741824 (estimated locally),1.00 per call) mdns_add_txt_answer/37 (1073741824 (estimated locally),1.00 per call) mdns_add_aaaa_answer/32 (1073741824 (estimated locally),1.00 per call) mdns_add_a_answer/30 (1073741824 (estimated locally),1.00 per call) 
  Calls: pbuf_alloc/76 (187153200 (estimated locally),0.17 per call) mdns_add_question/25 (1050476032 (estimated locally),0.98 per call) lwip_htonl/83 (1050476032 (estimated locally),0.98 per call) pbuf_take_at/78 (1050476032 (estimated locally),0.98 per call) pbuf_take_at/78 (370715093 (estimated locally),0.35 per call) mdns_write_domain/24 (397089735 (estimated locally),0.37 per call) lwip_htons/77 (432260540 (estimated locally),0.40 per call) pbuf_take_at/78 (432260540 (estimated locally),0.40 per call) 
mdns_probe.part.0/104 (mdns_probe.part.0) @0646f460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: mdns_probe/46 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: mdns_probe/46 (719407025 (estimated locally),0.67 per call) 
  Calls: sys_timeout/74 (1073741824 (estimated locally),1.00 per call) 
mdns_resp_announce.part.0/103 (mdns_resp_announce.part.0) @0646f380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: ip6_addr_any/73 (addr)ip_addr_any/72 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: mdns_resp_announce/54 (145808965 (estimated locally),0.14 per call) 
  Calls: mdns_announce/40 (1073741824 (estimated locally),1.00 per call) mdns_announce/40 (354334802 (estimated locally),0.33 per call) 
mdns_add_question.part.0/102 (mdns_add_question.part.0) @06455b60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741823 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: mdns_add_question/25 (513472682 (estimated locally),0.48 per call) 
  Calls: lwip_htons/77 (1073741823 (estimated locally),1.00 per call) pbuf_take_at/78 (1073741823 (estimated locally),1.00 per call) lwip_htons/77 (708669604 (estimated locally),0.66 per call) pbuf_take_at/78 (708669604 (estimated locally),0.66 per call) 
mdns_compress_domain.part.0/101 (mdns_compress_domain.part.0) @064550e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:73241592 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: mdns_compress_domain/23 (73241592 (estimated locally),0.69 per call) 
  Calls: mdns_readname/11 (73241592 (estimated locally),1.00 per call) memcmp/63 (249145566 (estimated locally),3.40 per call) 
check_service.part.0/100 (check_service.part.0) @06440000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: check_service/22 (645533583 (estimated locally),0.60 per call) 
  Calls: mdns_build_dnssd_domain/19 (1073741824 (estimated locally),1.00 per call) mdns_domain_eq/13 (354334802 (estimated locally),0.33 per call) mdns_build_service_domain/20 (1073741824 (estimated locally),1.00 per call) mdns_domain_eq/13 (354334802 (estimated locally),0.33 per call) mdns_build_service_domain/20 (1073741824 (estimated locally),1.00 per call) mdns_domain_eq/13 (354334802 (estimated locally),0.33 per call) 
check_host.part.0/99 (check_host.part.0) @064408c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: mdns_netif_client_id/3 (read)
  Referring: 
  Availability: local
  Function flags: count:475612076 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: check_host/21 (475612080 (estimated locally),0.67 per call) 
  Calls: mdns_build_reverse_v6_domain/16 (265751101 (estimated locally),0.56 per call) mdns_domain_eq/13 (87697863 (estimated locally),0.18 per call) mdns_build_reverse_v4_domain/15 (88583701 (estimated locally),0.19 per call) mdns_domain_eq/13 (29232621 (estimated locally),0.06 per call) mdns_build_host_domain/18 (475612077 (estimated locally),1.00 per call) mdns_domain_eq/13 (156951985 (estimated locally),0.33 per call) 
mdns_domain_eq.part.0/98 (mdns_domain_eq.part.0) @06302a80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:113027770 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: mdns_domain_eq/13 (113027770 (estimated locally),0.50 per call) 
  Calls: lwip_strnicmp/62 (982325207 (estimated locally),8.69 per call) 
mdns_read_question.part.0/97 (mdns_read_question.part.0) @0641aee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: mdns_read_question/28 (510142215 (estimated locally),0.48 per call) 
  Calls: 
mdns_build_dnssd_domain.part.0/96 (mdns_build_dnssd_domain.part.0) @0641a9a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: dnssd_protos/6 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: mdns_build_dnssd_domain/19 (256544236 (estimated locally),0.24 per call) 
  Calls: strlen/64 (1073741824 (estimated locally),1.00 per call) mdns_domain_add_label/8 (1073741824 (estimated locally),1.00 per call) mdns_add_dotlocal/17 (524845004 (estimated locally),0.49 per call) 
mdns_build_reverse_v6_domain.part.0/95 (mdns_build_reverse_v6_domain.part.0) @0641a540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: mdns_build_reverse_v6_domain/16 (24817613 (estimated locally),0.38 per call) 
  Calls: mdns_domain_add_label/8 (1073741824 (estimated locally),1.00 per call) mdns_domain_add_label/8 (524845004 (estimated locally),0.49 per call) mdns_domain_add_label/8 (256544238 (estimated locally),0.24 per call) 
mdns_build_reverse_v4_domain.part.0/94 (mdns_build_reverse_v4_domain.part.0) @0641a000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: mdns_build_reverse_v4_domain/15 (104969000 (estimated locally),0.40 per call) 
  Calls: mdns_domain_add_label/8 (1073741824 (estimated locally),1.00 per call) mdns_domain_add_label/8 (524845004 (estimated locally),0.49 per call) 
mdns_build_service_domain.part.0/93 (mdns_build_service_domain.part.0) @06302c40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: dnssd_protos/6 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: mdns_build_service_domain/20 (435621351 (estimated locally),0.41 per call) 
  Calls: strlen/64 (1073741824 (estimated locally),1.00 per call) mdns_domain_add_label/8 (1073741824 (estimated locally),1.00 per call) mdns_add_dotlocal/17 (524845004 (estimated locally),0.49 per call) 
mdns_add_dotlocal.part.0/92 (mdns_add_dotlocal.part.0) @06302700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: mdns_add_dotlocal/17 (524845000 (estimated locally),0.49 per call) 
  Calls: mdns_domain_add_label/8 (1073741824 (estimated locally),1.00 per call) 
mdns_domain_add_label.part.0/91 (mdns_domain_add_label.part.0) @05efc8c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: mdns_domain_add_label/8 (233860968 (estimated locally),0.22 per call) 
  Calls: memcpy/58 (1073741824 (estimated locally),1.00 per call) 
pbuf_memcmp/90 (pbuf_memcmp) @06288380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mdns_handle_question/41 (368047 (estimated locally),0.00 per call) mdns_handle_question/41 (594506 (estimated locally),0.00 per call) mdns_handle_question/41 (1189012 (estimated locally),0.01 per call) 
  Calls: 
netif_alloc_client_data_id/89 (netif_alloc_client_data_id) @062882a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mdns_resp_init/57 (40718 (estimated locally),0.18 per call) 
  Calls: 
udp_recv/88 (udp_recv) @062881c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mdns_resp_init/57 (40718 (estimated locally),0.18 per call) 
  Calls: 
ip_addr_any_type/87 (ip_addr_any_type) @06282990
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: mdns_resp_init/57 (addr)
  Availability: not_available
  Varpool flags: read-only
udp_bind/86 (udp_bind) @06288000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mdns_resp_init/57 (123389 (estimated locally),0.53 per call) 
  Calls: 
udp_new_ip_type/85 (udp_new_ip_type) @0626dee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mdns_resp_init/57 (230763 (estimated locally),1.00 per call) 
  Calls: 
rand/84 (rand) @0626dd20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mdns_resp_restart/56 (720400030 (estimated locally),0.67 per call) 
  Calls: 
lwip_htonl/83 (lwip_htonl) @0621ca80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mdns_add_answer.constprop/105 (1050476032 (estimated locally),0.98 per call) mdns_read_answer/29 (162864370 (estimated locally),0.15 per call) 
  Calls: 
lwip_itoa/82 (lwip_itoa) @0621c7e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mdns_build_reverse_v4_domain/15 (858993460 (estimated locally),3.23 per call) 
  Calls: 
udp_sendto_if/81 (udp_sendto_if) @0621c540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mdns_send_outpacket/39 (3552104 (estimated locally),0.05 per call) mdns_send_outpacket/39 (3552104 (estimated locally),0.05 per call) 
  Calls: 
pbuf_realloc/80 (pbuf_realloc) @0621c460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mdns_send_outpacket/39 (7104207 (estimated locally),0.10 per call) 
  Calls: 
pbuf_take/79 (pbuf_take) @0621c380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mdns_send_outpacket/39 (7104207 (estimated locally),0.10 per call) 
  Calls: 
pbuf_take_at/78 (pbuf_take_at) @06208e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mdns_add_answer.constprop/105 (1050476032 (estimated locally),0.98 per call) mdns_add_answer.constprop/105 (370715093 (estimated locally),0.35 per call) mdns_add_answer.constprop/105 (432260540 (estimated locally),0.40 per call) mdns_add_question.part.0/102 (1073741823 (estimated locally),1.00 per call) mdns_add_question.part.0/102 (708669604 (estimated locally),0.66 per call) mdns_write_domain/24 (57190360 (estimated locally),0.29 per call) mdns_write_domain/24 (64418067 (estimated locally),0.33 per call) 
  Calls: 
lwip_htons/77 (lwip_htons) @06208d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mdns_add_answer.constprop/105 (432260540 (estimated locally),0.40 per call) mdns_recv/44 (239187613 (estimated locally),0.22 per call) mdns_recv/44 (239187613 (estimated locally),0.22 per call) mdns_recv/44 (239187613 (estimated locally),0.22 per call) mdns_recv/44 (239187613 (estimated locally),0.22 per call) mdns_recv/44 (239187613 (estimated locally),0.22 per call) mdns_handle_question/41 (2451 (estimated locally),0.00 per call) mdns_handle_question/41 (36690 (estimated locally),0.00 per call) mdns_handle_question/41 (549323 (estimated locally),0.00 per call) mdns_send_outpacket/39 (7104207 (estimated locally),0.10 per call) mdns_send_outpacket/39 (7104207 (estimated locally),0.10 per call) mdns_send_outpacket/39 (7104207 (estimated locally),0.10 per call) mdns_send_outpacket/39 (7104207 (estimated locally),0.10 per call) mdns_send_outpacket/39 (7104207 (estimated locally),0.10 per call) mdns_add_srv_answer/36 (1073741824 (estimated locally),1.00 per call) mdns_add_srv_answer/36 (1073741824 (estimated locally),1.00 per call) mdns_add_srv_answer/36 (1073741824 (estimated locally),1.00 per call) mdns_add_question.part.0/102 (1073741823 (estimated locally),1.00 per call) mdns_add_question.part.0/102 (708669604 (estimated locally),0.66 per call) mdns_write_domain/24 (57190360 (estimated locally),0.29 per call) mdns_read_answer/29 (32963748 (estimated locally),0.03 per call) mdns_read_rr_info/27 (979182121 (estimated locally),0.91 per call) mdns_read_rr_info/27 (1019768924 (estimated locally),0.95 per call) 
  Calls: 
pbuf_alloc/76 (pbuf_alloc) @06208c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mdns_add_answer.constprop/105 (187153200 (estimated locally),0.17 per call) mdns_add_question/25 (187153200 (estimated locally),0.17 per call) 
  Calls: 
pbuf_free/75 (pbuf_free) @062087e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mdns_recv/44 (1073741824 (estimated locally),1.00 per call) mdns_handle_question/41 (13053622 (estimated locally),0.10 per call) mdns_send_probe/45 (79493049 (estimated locally),0.53 per call) mdns_send_outpacket/39 (37246918 (estimated locally),0.53 per call) 
  Calls: 
sys_timeout/74 (sys_timeout) @06208380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mdns_resp_restart/56 (720400030 (estimated locally),0.67 per call) mdns_probe.part.0/104 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
ip6_addr_any/73 (ip6_addr_any) @06207900
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: mdns_resp_announce.part.0/103 (addr)mdns_probe/46 (addr)
  Availability: not_available
  Varpool flags: read-only
ip_addr_any/72 (ip_addr_any) @06207870
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: mdns_resp_announce.part.0/103 (addr)mdns_probe/46 (addr)
  Availability: not_available
  Varpool flags: read-only
mld6_leavegroup_netif/71 (mld6_leavegroup_netif) @062081c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mdns_resp_remove_netif/48 (249412 (estimated locally),0.70 per call) 
  Calls: 
igmp_leavegroup_netif/70 (igmp_leavegroup_netif) @062080e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mdns_resp_remove_netif/48 (249412 (estimated locally),0.70 per call) 
  Calls: 
sys_untimeout/69 (sys_untimeout) @06208000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mdns_resp_restart/56 (145808966 (estimated locally),0.14 per call) mdns_resp_remove_netif/48 (50481 (estimated locally),0.14 per call) mdns_handle_response/42 (8523920 (estimated locally),0.07 per call) 
  Calls: 
mem_free/68 (mem_free) @05b32e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mdns_resp_add_netif/47 (17094 (estimated locally),0.13 per call) mdns_resp_del_service/51 (244572 (estimated locally),0.68 per call) mdns_resp_remove_netif/48 (249412 (estimated locally),0.70 per call) mdns_resp_remove_netif/48 (2871185 (estimated locally),8.02 per call) 
  Calls: 
mld6_joingroup_netif/67 (mld6_joingroup_netif) @05b32d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mdns_resp_add_netif/47 (10978 (estimated locally),0.08 per call) 
  Calls: 
igmp_joingroup_netif/66 (igmp_joingroup_netif) @05b32c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mdns_resp_add_netif/47 (22460 (estimated locally),0.17 per call) 
  Calls: 
mem_calloc/65 (mem_calloc) @05b32b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mdns_resp_add_service/50 (237989 (estimated locally),0.66 per call) mdns_resp_add_netif/47 (22666 (estimated locally),0.17 per call) 
  Calls: 
strlen/64 (strlen) @05b32a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mdns_resp_rename_service/52 (357913 (estimated locally),1.00 per call) mdns_resp_add_service/50 (235823 (estimated locally),0.66 per call) mdns_resp_add_service/50 (235823 (estimated locally),0.66 per call) mdns_resp_add_service/50 (246818 (estimated locally),0.69 per call) mdns_resp_add_service/50 (249412 (estimated locally),0.70 per call) mdns_resp_rename_netif/49 (1073741824 (estimated locally),1.00 per call) mdns_resp_add_netif/47 (22460 (estimated locally),0.17 per call) mdns_resp_add_netif/47 (131407 (estimated locally),1.00 per call) mdns_build_dnssd_domain.part.0/96 (1073741824 (estimated locally),1.00 per call) mdns_build_reverse_v4_domain/15 (858993460 (estimated locally),3.23 per call) mdns_build_service_domain/20 (891205715 (estimated locally),0.83 per call) mdns_build_service_domain/20 (536870913 (estimated locally),0.50 per call) mdns_build_service_domain.part.0/93 (1073741824 (estimated locally),1.00 per call) mdns_build_host_domain/18 (1063970774 (estimated locally),0.99 per call) 
  Calls: 
memcmp/63 (memcmp) @05b328c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mdns_compress_domain.part.0/101 (249145566 (estimated locally),3.40 per call) 
  Calls: 
lwip_strnicmp/62 (lwip_strnicmp) @05b32700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mdns_domain_eq.part.0/98 (982325207 (estimated locally),8.69 per call) 
  Calls: 
pbuf_copy_partial/61 (pbuf_copy_partial) @05b32540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mdns_recv/44 (741418729 (estimated locally),0.69 per call) mdns_handle_question/41 (12108 (estimated locally),0.00 per call) mdns_handle_question/41 (181277 (estimated locally),0.00 per call) mdns_handle_question/41 (2714048 (estimated locally),0.02 per call) mdns_read_answer/29 (162864370 (estimated locally),0.15 per call) mdns_read_answer/29 (493528393 (estimated locally),0.46 per call) mdns_read_rr_info/27 (1019768924 (estimated locally),0.95 per call) mdns_read_rr_info/27 (1062038039 (estimated locally),0.99 per call) mdns_domain_add_label_pbuf/9 (233860969 (estimated locally),0.22 per call) 
  Calls: 
pbuf_get_at/60 (pbuf_get_at) @05b32380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mdns_readname_loop/10 (13462704 (estimated locally),0.11 per call) mdns_readname_loop/10 (1052266988 (estimated locally),8.58 per call) 
  Calls: 
memset/59 (memset) @05b320e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mdns_recv/44 (239187613 (estimated locally),0.22 per call) mdns_announce/40 (59055800 (estimated locally),1.00 per call) mdns_send_probe/45 (148668505 (estimated locally),1.00 per call) mdns_send_outpacket/39 (7104207 (estimated locally),0.10 per call) mdns_read_answer/29 (1009673471 (estimated locally),0.94 per call) mdns_read_question/28 (1020284429 (estimated locally),0.95 per call) mdns_readname/11 (1073741824 (estimated locally),1.00 per call) mdns_build_dnssd_domain/19 (1073741824 (estimated locally),1.00 per call) mdns_build_reverse_v6_domain/16 (64190116 (estimated locally),0.99 per call) mdns_build_reverse_v4_domain/15 (261993004 (estimated locally),0.99 per call) mdns_build_service_domain/20 (1073741824 (estimated locally),1.00 per call) mdns_build_host_domain/18 (1073741824 (estimated locally),1.00 per call) mdns_init_outpacket/38 (1073741824 (estimated locally),1.00 per call) mdns_prepare_txtdata/14 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
memcpy/58 (memcpy) @061f5700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: mdns_resp_rename_service/52 (242028 (estimated locally),0.68 per call) mdns_resp_add_service/50 (235823 (estimated locally),0.66 per call) mdns_resp_add_service/50 (235823 (estimated locally),0.66 per call) mdns_resp_rename_netif/49 (1048167403 (estimated locally),0.98 per call) mdns_resp_add_netif/47 (22460 (estimated locally),0.17 per call) mdns_recv/44 (239187613 (estimated locally),0.22 per call) mdns_announce/40 (59055800 (estimated locally),1.00 per call) mdns_send_probe/45 (59055800 (estimated locally),0.40 per call) mdns_domain_add_label.part.0/91 (1073741824 (estimated locally),1.00 per call) mdns_init_outpacket/38 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
mdns_resp_init/57 (mdns_resp_init) @061f5d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: mdns_pcb/4 (write)ip_addr_any_type/87 (addr)mdns_pcb/4 (read)mdns_recv/44 (addr)mdns_netif_client_id/3 (write)
  Referring: 
  Availability: available
  Function flags: count:230763 (estimated locally) body optimize_size
  Called by: 
  Calls: netif_alloc_client_data_id/89 (40718 (estimated locally),0.18 per call) udp_recv/88 (40718 (estimated locally),0.18 per call) udp_bind/86 (123389 (estimated locally),0.53 per call) udp_new_ip_type/85 (230763 (estimated locally),1.00 per call) 
mdns_resp_restart/56 (mdns_resp_restart) @061f58c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: mdns_netif_client_id/3 (read)mdns_probe/46 (addr)mdns_probe/46 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: mdns_resp_rename_service/52 (242028 (estimated locally),0.68 per call) mdns_resp_add_service/50 (235823 (estimated locally),0.66 per call) mdns_resp_rename_netif/49 (1048167403 (estimated locally),0.98 per call) mdns_resp_add_netif/47 (5366 (estimated locally),0.04 per call) 
  Calls: sys_timeout/74 (720400030 (estimated locally),0.67 per call) rand/84 (720400030 (estimated locally),0.67 per call) sys_untimeout/69 (145808966 (estimated locally),0.14 per call) 
mdns_resp_register_name_result_cb/55 (mdns_resp_register_name_result_cb) @061f5620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: mdns_name_result_cb/5 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
mdns_resp_announce/54 (mdns_resp_announce) @061f5380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: mdns_netif_client_id/3 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: mdns_probe/46 (354334802 (estimated locally),0.33 per call) 
  Calls: mdns_resp_announce.part.0/103 (145808965 (estimated locally),0.14 per call) 
mdns_resp_add_service_txtitem/53 (mdns_resp_add_service_txtitem) @061e6d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:230763 (estimated locally) body optimize_size
  Called by: 
  Calls: mdns_domain_add_label/8 (123389 (estimated locally),0.53 per call) 
mdns_resp_rename_service/52 (mdns_resp_rename_service) @061e62a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: mdns_netif_client_id/3 (read)
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: mdns_resp_restart/56 (242028 (estimated locally),0.68 per call) memcpy/58 (242028 (estimated locally),0.68 per call) strlen/64 (357913 (estimated locally),1.00 per call) 
mdns_resp_del_service/51 (mdns_resp_del_service) @061e6c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: mdns_netif_client_id/3 (read)
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: mem_free/68 (244572 (estimated locally),0.68 per call) 
mdns_resp_add_service/50 (mdns_resp_add_service) @061e68c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: mdns_netif_client_id/3 (read)
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: mdns_resp_restart/56 (235823 (estimated locally),0.66 per call) memcpy/58 (235823 (estimated locally),0.66 per call) strlen/64 (235823 (estimated locally),0.66 per call) memcpy/58 (235823 (estimated locally),0.66 per call) strlen/64 (235823 (estimated locally),0.66 per call) mem_calloc/65 (237989 (estimated locally),0.66 per call) strlen/64 (246818 (estimated locally),0.69 per call) strlen/64 (249412 (estimated locally),0.70 per call) 
mdns_resp_rename_netif/49 (mdns_resp_rename_netif) @061e6460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: mdns_netif_client_id/3 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: mdns_resp_restart/56 (1048167403 (estimated locally),0.98 per call) memcpy/58 (1048167403 (estimated locally),0.98 per call) strlen/64 (1073741824 (estimated locally),1.00 per call) 
mdns_resp_remove_netif/48 (mdns_resp_remove_netif) @061e61c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: mdns_netif_client_id/3 (read)mdns_probe/46 (addr)v4group/1 (addr)v6group/2 (addr)mdns_netif_client_id/3 (read)
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: mem_free/68 (249412 (estimated locally),0.70 per call) mld6_leavegroup_netif/71 (249412 (estimated locally),0.70 per call) igmp_leavegroup_netif/70 (249412 (estimated locally),0.70 per call) mem_free/68 (2871185 (estimated locally),8.02 per call) sys_untimeout/69 (50481 (estimated locally),0.14 per call) 
mdns_resp_add_netif/47 (mdns_resp_add_netif) @061d68c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: mdns_netif_client_id/3 (read)mdns_netif_client_id/3 (read)v4group/1 (addr)v6group/2 (addr)mdns_netif_client_id/3 (read)
  Referring: 
  Availability: available
  Function flags: count:132001 (estimated locally) body optimize_size
  Called by: 
  Calls: mem_free/68 (17094 (estimated locally),0.13 per call) mdns_resp_restart/56 (5366 (estimated locally),0.04 per call) mld6_joingroup_netif/67 (10978 (estimated locally),0.08 per call) igmp_joingroup_netif/66 (22460 (estimated locally),0.17 per call) memcpy/58 (22460 (estimated locally),0.17 per call) strlen/64 (22460 (estimated locally),0.17 per call) mem_calloc/65 (22666 (estimated locally),0.17 per call) strlen/64 (131407 (estimated locally),1.00 per call) 
mdns_probe/46 (mdns_probe) @061d6c40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: mdns_netif_client_id/3 (read)mdns_name_result_cb/5 (read)ip_addr_any/72 (addr)ip6_addr_any/73 (addr)
  Referring: mdns_probe.part.0/104 (addr)mdns_handle_response/42 (addr)mdns_resp_remove_netif/48 (addr)mdns_resp_restart/56 (addr)mdns_resp_restart/56 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: mdns_probe.part.0/104 (719407025 (estimated locally),0.67 per call) mdns_send_probe/45 (78343425 (estimated locally),0.07 per call) mdns_send_probe/45 (237404317 (estimated locally),0.22 per call) mdns_resp_announce/54 (354334802 (estimated locally),0.33 per call) 
   Indirect call(248034361 (estimated locally),0.23 per call) 
mdns_send_probe/45 (mdns_send_probe) @061d67e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: mdns_netif_client_id/3 (read)
  Referring: 
  Availability: local
  Function flags: count:148668505 (estimated locally) body local optimize_size
  Called by: mdns_probe/46 (78343425 (estimated locally),0.07 per call) mdns_probe/46 (237404317 (estimated locally),0.22 per call) 
  Calls: pbuf_free/75 (79493049 (estimated locally),0.53 per call) mdns_send_outpacket/39 (59055800 (estimated locally),0.40 per call) memcpy/58 (59055800 (estimated locally),0.40 per call) mdns_add_question/25 (710280211 (estimated locally),4.78 per call) mdns_build_service_domain/20 (710280211 (estimated locally),4.78 per call) mdns_add_question/25 (148668505 (estimated locally),1.00 per call) mdns_build_host_domain/18 (148668505 (estimated locally),1.00 per call) memset/59 (148668505 (estimated locally),1.00 per call) 
mdns_recv/44 (mdns_recv) @061d61c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: ip_data/43 (read)mdns_netif_client_id/3 (read)ip_data/43 (read)ip_data/43 (read)ip_data/43 (read)ip_data/43 (read)ip_data/43 (read)ip_data/43 (read)
  Referring: mdns_resp_init/57 (addr)
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: pbuf_free/75 (1073741824 (estimated locally),1.00 per call) mdns_handle_question/41 (141120692 (estimated locally),0.13 per call) mdns_handle_response/42 (98066921 (estimated locally),0.09 per call) lwip_htons/77 (239187613 (estimated locally),0.22 per call) lwip_htons/77 (239187613 (estimated locally),0.22 per call) lwip_htons/77 (239187613 (estimated locally),0.22 per call) lwip_htons/77 (239187613 (estimated locally),0.22 per call) lwip_htons/77 (239187613 (estimated locally),0.22 per call) memcpy/58 (239187613 (estimated locally),0.22 per call) memset/59 (239187613 (estimated locally),0.22 per call) pbuf_copy_partial/61 (741418729 (estimated locally),0.69 per call) 
ip_data/43 (ip_data) @06161990
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: mdns_recv/44 (read)mdns_recv/44 (read)mdns_recv/44 (read)mdns_recv/44 (read)mdns_recv/44 (read)mdns_recv/44 (read)mdns_recv/44 (read)
  Availability: not_available
  Varpool flags:
mdns_handle_response/42 (mdns_handle_response) @061782a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: mdns_netif_client_id/3 (read)mdns_probe/46 (addr)mdns_name_result_cb/5 (read)
  Referring: 
  Availability: local
  Function flags: count:114863532 (estimated locally) body local optimize_size
  Called by: mdns_recv/44 (98066921 (estimated locally),0.09 per call) 
  Calls: sys_untimeout/69 (8523920 (estimated locally),0.07 per call) mdns_domain_eq/13 (48276385 (estimated locally),0.42 per call) mdns_build_service_domain/20 (146292075 (estimated locally),1.27 per call) mdns_domain_eq/13 (8523920 (estimated locally),0.07 per call) mdns_build_host_domain/18 (25830061 (estimated locally),0.22 per call) mdns_domain_debug_print/12 (492996550 (estimated locally),4.29 per call) mdns_read_answer/29 (521689471 (estimated locally),4.54 per call) mdns_read_question/28 (1014686025 (estimated locally),8.83 per call) 
   Indirect call(5966744 (estimated locally),0.05 per call) 
mdns_handle_question/41 (mdns_handle_question) @0615fee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: mdns_netif_client_id/3 (read)
  Referring: 
  Availability: local
  Function flags: count:135784700 (estimated locally) body local optimize_size
  Called by: mdns_recv/44 (141120692 (estimated locally),0.13 per call) 
  Calls: pbuf_free/75 (13053622 (estimated locally),0.10 per call) mdns_send_outpacket/39 (10884740 (estimated locally),0.08 per call) pbuf_memcmp/90 (368047 (estimated locally),0.00 per call) mdns_prepare_txtdata/14 (1818412 (estimated locally),0.01 per call) mdns_domain_eq/13 (242 (estimated locally),0.00 per call) mdns_build_host_domain/18 (496 (estimated locally),0.00 per call) mdns_readname/11 (496 (estimated locally),0.00 per call) lwip_htons/77 (2451 (estimated locally),0.00 per call) pbuf_copy_partial/61 (12108 (estimated locally),0.00 per call) lwip_htons/77 (36690 (estimated locally),0.00 per call) pbuf_copy_partial/61 (181277 (estimated locally),0.00 per call) lwip_htons/77 (549323 (estimated locally),0.00 per call) pbuf_copy_partial/61 (2714048 (estimated locally),0.02 per call) mdns_domain_eq/13 (150003 (estimated locally),0.00 per call) mdns_build_service_domain/20 (454555 (estimated locally),0.00 per call) mdns_domain_eq/13 (150003 (estimated locally),0.00 per call) mdns_build_service_domain/20 (454555 (estimated locally),0.00 per call) mdns_readname/11 (2087031 (estimated locally),0.02 per call) check_service/22 (41245680 (estimated locally),0.30 per call) pbuf_memcmp/90 (594506 (estimated locally),0.00 per call) pbuf_memcmp/90 (1189012 (estimated locally),0.01 per call) mdns_domain_eq/13 (649365 (estimated locally),0.00 per call) mdns_build_host_domain/18 (2981473 (estimated locally),0.02 per call) mdns_readname/11 (2981473 (estimated locally),0.02 per call) check_host/21 (58922399 (estimated locally),0.43 per call) mdns_domain_debug_print/12 (176733548 (estimated locally),1.30 per call) mdns_read_answer/29 (187019628 (estimated locally),1.38 per call) mdns_add_question/25 (88583700 (estimated locally),0.65 per call) check_service/22 (375809638 (estimated locally),2.77 per call) check_host/21 (536870913 (estimated locally),3.95 per call) mdns_domain_debug_print/12 (536870913 (estimated locally),3.95 per call) mdns_read_question/28 (557266881 (estimated locally),4.10 per call) mdns_init_outpacket/38 (44808951 (estimated locally),0.33 per call) 
mdns_announce/40 (mdns_announce) @0615f8c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: mdns_netif_client_id/3 (read)
  Referring: 
  Availability: local
  Function flags: count:59055800 (estimated locally) body local optimize_size
  Called by: mdns_resp_announce.part.0/103 (1073741824 (estimated locally),1.00 per call) mdns_resp_announce.part.0/103 (354334802 (estimated locally),0.33 per call) 
  Calls: mdns_send_outpacket/39 (59055800 (estimated locally),1.00 per call) memcpy/58 (59055800 (estimated locally),1.00 per call) memset/59 (59055800 (estimated locally),1.00 per call) 
mdns_send_outpacket/39 (mdns_send_outpacket) @0615f2a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: mdns_netif_client_id/3 (read)v6group/2 (addr)v4group/1 (addr)mdns_pcb/4 (read)mdns_pcb/4 (read)
  Referring: 
  Availability: local
  Function flags: count:69659470 (estimated locally) body local optimize_size
  Called by: mdns_handle_question/41 (10884740 (estimated locally),0.08 per call) mdns_announce/40 (59055800 (estimated locally),1.00 per call) mdns_send_probe/45 (59055800 (estimated locally),0.40 per call) 
  Calls: pbuf_free/75 (37246918 (estimated locally),0.53 per call) udp_sendto_if/81 (3552104 (estimated locally),0.05 per call) udp_sendto_if/81 (3552104 (estimated locally),0.05 per call) pbuf_realloc/80 (7104207 (estimated locally),0.10 per call) pbuf_take/79 (7104207 (estimated locally),0.10 per call) lwip_htons/77 (7104207 (estimated locally),0.10 per call) lwip_htons/77 (7104207 (estimated locally),0.10 per call) lwip_htons/77 (7104207 (estimated locally),0.10 per call) lwip_htons/77 (7104207 (estimated locally),0.10 per call) lwip_htons/77 (7104207 (estimated locally),0.10 per call) memset/59 (7104207 (estimated locally),0.10 per call) mdns_add_a_answer/30 (59024618 (estimated locally),0.85 per call) mdns_add_aaaa_answer/32 (91964433 (estimated locally),1.32 per call) mdns_add_txt_answer/37 (100412592 (estimated locally),1.44 per call) mdns_add_srv_answer/36 (80468860 (estimated locally),1.16 per call) mdns_add_txt_answer/37 (216325518 (estimated locally),3.11 per call) mdns_add_srv_answer/36 (281997976 (estimated locally),4.05 per call) mdns_add_servicename_ptr_answer/35 (284060253 (estimated locally),4.08 per call) mdns_add_servicetype_ptr_answer/34 (286137612 (estimated locally),4.11 per call) mdns_add_hostv6_ptr_answer/33 (115589638 (estimated locally),1.66 per call) mdns_add_aaaa_answer/32 (25774464 (estimated locally),0.37 per call) mdns_add_hostv4_ptr_answer/31 (20408413 (estimated locally),0.29 per call) mdns_add_a_answer/30 (22987625 (estimated locally),0.33 per call) 
mdns_init_outpacket/38 (mdns_init_outpacket) @06153c40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: mdns_handle_question/41 (44808951 (estimated locally),0.33 per call) 
  Calls: memcpy/58 (1073741824 (estimated locally),1.00 per call) memset/59 (1073741824 (estimated locally),1.00 per call) 
mdns_add_txt_answer/37 (mdns_add_txt_answer) @061538c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: mdns_send_outpacket/39 (100412592 (estimated locally),1.44 per call) mdns_send_outpacket/39 (216325518 (estimated locally),3.11 per call) 
  Calls: mdns_add_answer.constprop/105 (1073741824 (estimated locally),1.00 per call) mdns_prepare_txtdata/14 (1073741824 (estimated locally),1.00 per call) mdns_build_service_domain/20 (1073741824 (estimated locally),1.00 per call) 
mdns_add_srv_answer/36 (mdns_add_srv_answer) @06153620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: mdns_send_outpacket/39 (80468860 (estimated locally),1.16 per call) mdns_send_outpacket/39 (281997976 (estimated locally),4.05 per call) 
  Calls: mdns_add_answer.constprop/105 (1073741824 (estimated locally),1.00 per call) lwip_htons/77 (1073741824 (estimated locally),1.00 per call) lwip_htons/77 (1073741824 (estimated locally),1.00 per call) lwip_htons/77 (1073741824 (estimated locally),1.00 per call) mdns_build_host_domain/18 (1073741824 (estimated locally),1.00 per call) mdns_build_service_domain/20 (1073741824 (estimated locally),1.00 per call) 
mdns_add_servicename_ptr_answer/35 (mdns_add_servicename_ptr_answer) @06153380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: mdns_send_outpacket/39 (284060253 (estimated locally),4.08 per call) 
  Calls: mdns_add_answer.constprop/105 (1073741824 (estimated locally),1.00 per call) mdns_build_service_domain/20 (1073741824 (estimated locally),1.00 per call) mdns_build_service_domain/20 (1073741824 (estimated locally),1.00 per call) 
mdns_add_servicetype_ptr_answer/34 (mdns_add_servicetype_ptr_answer) @061530e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: mdns_send_outpacket/39 (286137612 (estimated locally),4.11 per call) 
  Calls: mdns_add_answer.constprop/105 (1073741824 (estimated locally),1.00 per call) mdns_build_dnssd_domain/19 (1073741824 (estimated locally),1.00 per call) mdns_build_service_domain/20 (1073741824 (estimated locally),1.00 per call) 
mdns_add_hostv6_ptr_answer/33 (mdns_add_hostv6_ptr_answer) @0614de00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: mdns_netif_client_id/3 (read)mdns_netif_client_id/3 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: mdns_send_outpacket/39 (115589638 (estimated locally),1.66 per call) 
  Calls: mdns_add_answer.constprop/105 (1073741824 (estimated locally),1.00 per call) mdns_build_reverse_v6_domain/16 (1073741824 (estimated locally),1.00 per call) mdns_build_host_domain/18 (1073741824 (estimated locally),1.00 per call) 
mdns_add_aaaa_answer/32 (mdns_add_aaaa_answer) @0614d9a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: mdns_netif_client_id/3 (read)mdns_netif_client_id/3 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: mdns_send_outpacket/39 (91964433 (estimated locally),1.32 per call) mdns_send_outpacket/39 (25774464 (estimated locally),0.37 per call) 
  Calls: mdns_add_answer.constprop/105 (1073741824 (estimated locally),1.00 per call) mdns_build_host_domain/18 (1073741824 (estimated locally),1.00 per call) 
mdns_add_hostv4_ptr_answer/31 (mdns_add_hostv4_ptr_answer) @0614d540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: mdns_netif_client_id/3 (read)mdns_netif_client_id/3 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: mdns_send_outpacket/39 (20408413 (estimated locally),0.29 per call) 
  Calls: mdns_add_answer.constprop/105 (1073741824 (estimated locally),1.00 per call) mdns_build_reverse_v4_domain/15 (1073741824 (estimated locally),1.00 per call) mdns_build_host_domain/18 (1073741824 (estimated locally),1.00 per call) 
mdns_add_a_answer/30 (mdns_add_a_answer) @0614d0e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: mdns_netif_client_id/3 (read)mdns_netif_client_id/3 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: mdns_send_outpacket/39 (59024618 (estimated locally),0.85 per call) mdns_send_outpacket/39 (22987625 (estimated locally),0.33 per call) 
  Calls: mdns_add_answer.constprop/105 (1073741824 (estimated locally),1.00 per call) mdns_build_host_domain/18 (1073741824 (estimated locally),1.00 per call) 
mdns_read_answer/29 (mdns_read_answer) @0613ac40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: mdns_handle_question/41 (187019628 (estimated locally),1.38 per call) mdns_handle_response/42 (521689471 (estimated locally),4.54 per call) 
  Calls: lwip_htons/77 (32963748 (estimated locally),0.03 per call) pbuf_copy_partial/61 (162864370 (estimated locally),0.15 per call) lwip_htonl/83 (162864370 (estimated locally),0.15 per call) pbuf_copy_partial/61 (493528393 (estimated locally),0.46 per call) mdns_read_rr_info/27 (1009673471 (estimated locally),0.94 per call) memset/59 (1009673471 (estimated locally),0.94 per call) 
mdns_read_question/28 (mdns_read_question) @0613a9a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: mdns_handle_question/41 (557266881 (estimated locally),4.10 per call) mdns_handle_response/42 (1014686025 (estimated locally),8.83 per call) 
  Calls: mdns_read_question.part.0/97 (510142215 (estimated locally),0.48 per call) mdns_read_rr_info/27 (1020284429 (estimated locally),0.95 per call) memset/59 (1020284429 (estimated locally),0.95 per call) 
mdns_read_rr_info/27 (mdns_read_rr_info) @0613a700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: mdns_read_answer/29 (1009673471 (estimated locally),0.94 per call) mdns_read_question/28 (1020284429 (estimated locally),0.95 per call) 
  Calls: lwip_htons/77 (979182121 (estimated locally),0.91 per call) pbuf_copy_partial/61 (1019768924 (estimated locally),0.95 per call) lwip_htons/77 (1019768924 (estimated locally),0.95 per call) pbuf_copy_partial/61 (1062038039 (estimated locally),0.99 per call) mdns_readname/11 (1073741824 (estimated locally),1.00 per call) 
mdns_add_answer/26 (mdns_add_answer) @0613a460
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
mdns_add_question/25 (mdns_add_question) @0613a1c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: mdns_add_answer.constprop/105 (1050476032 (estimated locally),0.98 per call) mdns_handle_question/41 (88583700 (estimated locally),0.65 per call) mdns_send_probe/45 (710280211 (estimated locally),4.78 per call) mdns_send_probe/45 (148668505 (estimated locally),1.00 per call) 
  Calls: mdns_add_question.part.0/102 (513472682 (estimated locally),0.48 per call) mdns_write_domain/24 (1050476034 (estimated locally),0.98 per call) pbuf_alloc/76 (187153200 (estimated locally),0.17 per call) 
mdns_write_domain/24 (mdns_write_domain) @0612cb60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:195206264 (estimated locally) body local optimize_size
  Called by: mdns_add_answer.constprop/105 (397089735 (estimated locally),0.37 per call) mdns_add_question/25 (1050476034 (estimated locally),0.98 per call) 
  Calls: pbuf_take_at/78 (57190360 (estimated locally),0.29 per call) lwip_htons/77 (57190360 (estimated locally),0.29 per call) pbuf_take_at/78 (64418067 (estimated locally),0.33 per call) mdns_compress_domain/23 (322125769 (estimated locally),1.65 per call) 
mdns_compress_domain/23 (mdns_compress_domain) @0612cd20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:106070372 (estimated locally) body optimize_size
  Called by: mdns_write_domain/24 (322125769 (estimated locally),1.65 per call) 
  Calls: mdns_compress_domain.part.0/101 (73241592 (estimated locally),0.69 per call) 
check_service/22 (check_service) @0612ca80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741823 (estimated locally) body local optimize_size
  Called by: mdns_handle_question/41 (41245680 (estimated locally),0.30 per call) mdns_handle_question/41 (375809638 (estimated locally),2.77 per call) 
  Calls: check_service.part.0/100 (645533583 (estimated locally),0.60 per call) 
check_host/21 (check_host) @0612c7e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:709868772 (estimated locally) body local optimize_size
  Called by: mdns_handle_question/41 (58922399 (estimated locally),0.43 per call) mdns_handle_question/41 (536870913 (estimated locally),3.95 per call) 
  Calls: check_host.part.0/99 (475612080 (estimated locally),0.67 per call) 
mdns_build_service_domain/20 (mdns_build_service_domain) @06123d20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: mdns_handle_question/41 (454555 (estimated locally),0.00 per call) mdns_handle_question/41 (454555 (estimated locally),0.00 per call) mdns_send_probe/45 (710280211 (estimated locally),4.78 per call) mdns_add_txt_answer/37 (1073741824 (estimated locally),1.00 per call) mdns_add_srv_answer/36 (1073741824 (estimated locally),1.00 per call) mdns_add_servicename_ptr_answer/35 (1073741824 (estimated locally),1.00 per call) mdns_add_servicename_ptr_answer/35 (1073741824 (estimated locally),1.00 per call) mdns_add_servicetype_ptr_answer/34 (1073741824 (estimated locally),1.00 per call) check_service.part.0/100 (1073741824 (estimated locally),1.00 per call) check_service.part.0/100 (1073741824 (estimated locally),1.00 per call) mdns_handle_response/42 (146292075 (estimated locally),1.27 per call) 
  Calls: mdns_build_service_domain.part.0/93 (435621351 (estimated locally),0.41 per call) mdns_domain_add_label/8 (891205715 (estimated locally),0.83 per call) strlen/64 (891205715 (estimated locally),0.83 per call) mdns_domain_add_label/8 (536870913 (estimated locally),0.50 per call) strlen/64 (536870913 (estimated locally),0.50 per call) memset/59 (1073741824 (estimated locally),1.00 per call) 
mdns_build_dnssd_domain/19 (mdns_build_dnssd_domain) @061237e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: mdns_add_servicetype_ptr_answer/34 (1073741824 (estimated locally),1.00 per call) check_service.part.0/100 (1073741824 (estimated locally),1.00 per call) 
  Calls: mdns_build_dnssd_domain.part.0/96 (256544236 (estimated locally),0.24 per call) mdns_domain_add_label/8 (524845004 (estimated locally),0.49 per call) mdns_domain_add_label/8 (1073741824 (estimated locally),1.00 per call) memset/59 (1073741824 (estimated locally),1.00 per call) 
mdns_build_host_domain/18 (mdns_build_host_domain) @061232a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: mdns_handle_question/41 (496 (estimated locally),0.00 per call) mdns_handle_question/41 (2981473 (estimated locally),0.02 per call) mdns_send_probe/45 (148668505 (estimated locally),1.00 per call) mdns_add_a_answer/30 (1073741824 (estimated locally),1.00 per call) mdns_add_aaaa_answer/32 (1073741824 (estimated locally),1.00 per call) mdns_add_srv_answer/36 (1073741824 (estimated locally),1.00 per call) mdns_add_hostv6_ptr_answer/33 (1073741824 (estimated locally),1.00 per call) mdns_add_hostv4_ptr_answer/31 (1073741824 (estimated locally),1.00 per call) check_host.part.0/99 (475612077 (estimated locally),1.00 per call) mdns_handle_response/42 (25830061 (estimated locally),0.22 per call) 
  Calls: mdns_add_dotlocal/17 (520068914 (estimated locally),0.48 per call) mdns_domain_add_label/8 (1063970774 (estimated locally),0.99 per call) strlen/64 (1063970774 (estimated locally),0.99 per call) memset/59 (1073741824 (estimated locally),1.00 per call) 
mdns_add_dotlocal/17 (mdns_add_dotlocal) @0611aee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: mdns_build_dnssd_domain.part.0/96 (524845004 (estimated locally),0.49 per call) mdns_build_service_domain.part.0/93 (524845004 (estimated locally),0.49 per call) mdns_build_host_domain/18 (520068914 (estimated locally),0.48 per call) 
  Calls: mdns_add_dotlocal.part.0/92 (524845000 (estimated locally),0.49 per call) mdns_domain_add_label/8 (1073741824 (estimated locally),1.00 per call) 
mdns_build_reverse_v6_domain/16 (mdns_build_reverse_v6_domain) @0611ab60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:65072437 (estimated locally) body local optimize_size
  Called by: mdns_add_hostv6_ptr_answer/33 (1073741824 (estimated locally),1.00 per call) check_host.part.0/99 (265751101 (estimated locally),0.56 per call) 
  Calls: mdns_build_reverse_v6_domain.part.0/95 (24817613 (estimated locally),0.38 per call) mdns_domain_add_label/8 (715863675 (estimated locally),11.00 per call) memset/59 (64190116 (estimated locally),0.99 per call) 
mdns_build_reverse_v4_domain/15 (mdns_build_reverse_v4_domain) @0611a540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:265594209 (estimated locally) body local optimize_size
  Called by: mdns_add_hostv4_ptr_answer/31 (1073741824 (estimated locally),1.00 per call) check_host.part.0/99 (88583701 (estimated locally),0.19 per call) 
  Calls: mdns_build_reverse_v4_domain.part.0/94 (104969000 (estimated locally),0.40 per call) mdns_domain_add_label/8 (214748365 (estimated locally),0.81 per call) mdns_domain_add_label/8 (858993460 (estimated locally),3.23 per call) strlen/64 (858993460 (estimated locally),3.23 per call) lwip_itoa/82 (858993460 (estimated locally),3.23 per call) memset/59 (261993004 (estimated locally),0.99 per call) 
mdns_prepare_txtdata/14 (mdns_prepare_txtdata) @0610fc40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: mdns_handle_question/41 (1818412 (estimated locally),0.01 per call) mdns_add_txt_answer/37 (1073741824 (estimated locally),1.00 per call) 
  Calls: memset/59 (1073741824 (estimated locally),1.00 per call) 
   Indirect call(751619278 (estimated locally),0.70 per call)  of param:0 loaded from aggregate passed by reference at offset 3104 (vptr maybe changed)
mdns_domain_eq/13 (mdns_domain_eq) @0610fe00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:226055540 (estimated locally) body optimize_size
  Called by: mdns_handle_question/41 (242 (estimated locally),0.00 per call) mdns_handle_question/41 (150003 (estimated locally),0.00 per call) mdns_handle_question/41 (150003 (estimated locally),0.00 per call) mdns_handle_question/41 (649365 (estimated locally),0.00 per call) check_service.part.0/100 (354334802 (estimated locally),0.33 per call) check_service.part.0/100 (354334802 (estimated locally),0.33 per call) check_service.part.0/100 (354334802 (estimated locally),0.33 per call) check_host.part.0/99 (87697863 (estimated locally),0.18 per call) check_host.part.0/99 (29232621 (estimated locally),0.06 per call) check_host.part.0/99 (156951985 (estimated locally),0.33 per call) mdns_handle_response/42 (48276385 (estimated locally),0.42 per call) mdns_handle_response/42 (8523920 (estimated locally),0.07 per call) 
  Calls: mdns_domain_eq.part.0/98 (113027770 (estimated locally),0.50 per call) 
mdns_domain_debug_print/12 (mdns_domain_debug_print) @0610fb60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:118111600 (estimated locally) body local optimize_size
  Called by: mdns_handle_question/41 (176733548 (estimated locally),1.30 per call) mdns_handle_question/41 (536870913 (estimated locally),3.95 per call) mdns_handle_response/42 (492996550 (estimated locally),4.29 per call) 
  Calls: 
mdns_readname/11 (mdns_readname) @0610f8c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: mdns_handle_question/41 (496 (estimated locally),0.00 per call) mdns_handle_question/41 (2087031 (estimated locally),0.02 per call) mdns_handle_question/41 (2981473 (estimated locally),0.02 per call) mdns_compress_domain.part.0/101 (73241592 (estimated locally),1.00 per call) mdns_read_rr_info/27 (1073741824 (estimated locally),1.00 per call) 
  Calls: mdns_readname_loop/10 (1073741824 (estimated locally),1.00 per call) memset/59 (1073741824 (estimated locally),1.00 per call) 
mdns_readname_loop/10 (mdns_readname_loop) @0610f620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:122575812 (estimated locally) body local optimize_size
  Called by: mdns_readname/11 (1073741824 (estimated locally),1.00 per call) mdns_readname_loop/10 (6741545 (estimated locally),0.05 per call) 
  Calls: mdns_domain_add_label_pbuf/9 (990385272 (estimated locally),8.08 per call) mdns_readname_loop/10 (6741545 (estimated locally),0.05 per call) pbuf_get_at/60 (13462704 (estimated locally),0.11 per call) pbuf_get_at/60 (1052266988 (estimated locally),8.58 per call) 
mdns_domain_add_label_pbuf/9 (mdns_domain_add_label_pbuf) @0610f380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741823 (estimated locally) body local optimize_size
  Called by: mdns_readname_loop/10 (990385272 (estimated locally),8.08 per call) 
  Calls: pbuf_copy_partial/61 (233860969 (estimated locally),0.22 per call) mdns_domain_add_label_base/7 (1073741823 (estimated locally),1.00 per call) 
mdns_domain_add_label/8 (mdns_domain_add_label) @0610f0e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: mdns_resp_add_service_txtitem/53 (123389 (estimated locally),0.53 per call) mdns_build_dnssd_domain/19 (524845004 (estimated locally),0.49 per call) mdns_build_dnssd_domain/19 (1073741824 (estimated locally),1.00 per call) mdns_build_dnssd_domain.part.0/96 (1073741824 (estimated locally),1.00 per call) mdns_build_reverse_v6_domain/16 (715863675 (estimated locally),11.00 per call) mdns_build_reverse_v6_domain.part.0/95 (1073741824 (estimated locally),1.00 per call) mdns_build_reverse_v6_domain.part.0/95 (524845004 (estimated locally),0.49 per call) mdns_build_reverse_v6_domain.part.0/95 (256544238 (estimated locally),0.24 per call) mdns_build_reverse_v4_domain/15 (214748365 (estimated locally),0.81 per call) mdns_build_reverse_v4_domain/15 (858993460 (estimated locally),3.23 per call) mdns_build_reverse_v4_domain.part.0/94 (1073741824 (estimated locally),1.00 per call) mdns_build_reverse_v4_domain.part.0/94 (524845004 (estimated locally),0.49 per call) mdns_build_service_domain/20 (891205715 (estimated locally),0.83 per call) mdns_build_service_domain/20 (536870913 (estimated locally),0.50 per call) mdns_build_service_domain.part.0/93 (1073741824 (estimated locally),1.00 per call) mdns_build_host_domain/18 (1063970774 (estimated locally),0.99 per call) mdns_add_dotlocal/17 (1073741824 (estimated locally),1.00 per call) mdns_add_dotlocal.part.0/92 (1073741824 (estimated locally),1.00 per call) 
  Calls: mdns_domain_add_label.part.0/91 (233860968 (estimated locally),0.22 per call) mdns_domain_add_label_base/7 (1073741823 (estimated locally),1.00 per call) 
mdns_domain_add_label_base/7 (mdns_domain_add_label_base) @06109e00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: mdns_domain_add_label/8 (1073741823 (estimated locally),1.00 per call) mdns_domain_add_label_pbuf/9 (1073741823 (estimated locally),1.00 per call) 
  Calls: 
dnssd_protos/6 (dnssd_protos) @061011f8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: mdns_build_service_domain.part.0/93 (read)mdns_build_dnssd_domain.part.0/96 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
mdns_name_result_cb/5 (mdns_name_result_cb) @060b4af8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: mdns_handle_response/42 (read)mdns_probe/46 (read)mdns_resp_register_name_result_cb/55 (write)
  Availability: available
  Varpool flags:
mdns_pcb/4 (mdns_pcb) @060b4a20
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: mdns_send_outpacket/39 (read)mdns_send_outpacket/39 (read)mdns_resp_init/57 (write)mdns_resp_init/57 (read)
  Availability: available
  Varpool flags:
mdns_netif_client_id/3 (mdns_netif_client_id) @060b4990
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: mdns_resp_rename_service/52 (read)mdns_add_a_answer/30 (read)mdns_probe/46 (read)mdns_add_aaaa_answer/32 (read)mdns_handle_question/41 (read)mdns_resp_del_service/51 (read)mdns_add_a_answer/30 (read)mdns_add_aaaa_answer/32 (read)mdns_send_probe/45 (read)mdns_handle_response/42 (read)mdns_resp_remove_netif/48 (read)check_host.part.0/99 (read)mdns_add_hostv4_ptr_answer/31 (read)mdns_add_hostv4_ptr_answer/31 (read)mdns_add_hostv6_ptr_answer/33 (read)mdns_add_hostv6_ptr_answer/33 (read)mdns_resp_restart/56 (read)mdns_resp_add_netif/47 (read)mdns_recv/44 (read)mdns_resp_rename_netif/49 (read)mdns_resp_remove_netif/48 (read)mdns_send_outpacket/39 (read)mdns_resp_announce/54 (read)mdns_resp_add_service/50 (read)mdns_announce/40 (read)mdns_resp_add_netif/47 (read)mdns_resp_add_netif/47 (read)mdns_resp_init/57 (write)
  Availability: available
  Varpool flags:
v6group/2 (v6group) @060b47e0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: mdns_send_outpacket/39 (addr)mdns_resp_remove_netif/48 (addr)mdns_resp_add_netif/47 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
v4group/1 (v4group) @05ebf2d0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: mdns_send_outpacket/39 (addr)mdns_resp_remove_netif/48 (addr)mdns_resp_add_netif/47 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known

;; Function mdns_domain_add_label_base (mdns_domain_add_label_base, funcdef_no=1, decl_uid=7382, cgraph_uid=2, symbol_order=7)

Modification phase of node mdns_domain_add_label_base/7
mdns_domain_add_label_base (struct mdns_domain * domain, u8_t len)
{
  int _1;
  int _2;
  short unsigned int _3;
  int _4;
  int _5;
  short unsigned int _6;
  short unsigned int _7;
  int _8;
  short unsigned int _9;
  err_t _10;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (len_12(D) > 63)
    goto <bb 8>; [1.04%]
  else
    goto <bb 3>; [98.96%]

  <bb 3> [local count: 1062574910]:
  # DEBUG BEGIN_STMT
  if (len_12(D) != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 531287455]:
  _1 = (int) len_12(D);
  _2 = _1 + 1;
  _3 = domain_14(D)->length;
  _4 = (int) _3;
  _5 = _2 + _4;
  if (_5 > 255)
    goto <bb 8>; [1.04%]
  else
    goto <bb 5>; [98.96%]

  <bb 5> [local count: 1057049521]:
  # DEBUG BEGIN_STMT
  if (len_12(D) == 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 6> [local count: 528524760]:
  _6 = domain_14(D)->length;
  if (_6 > 255)
    goto <bb 8>; [1.04%]
  else
    goto <bb 7>; [98.96%]

  <bb 7> [local count: 1051552863]:
  # DEBUG BEGIN_STMT
  _7 = domain_14(D)->length;
  _8 = (int) _7;
  domain_14(D)->name[_8] = len_12(D);
  # DEBUG BEGIN_STMT
  _9 = _7 + 1;
  domain_14(D)->length = _9;
  # DEBUG BEGIN_STMT

  <bb 8> [local count: 1073741824]:
  # _10 = PHI <-6(2), -6(4), -6(6), 0(7)>
  return _10;

}



;; Function mdns_domain_debug_print (mdns_domain_debug_print, funcdef_no=6, decl_uid=7415, cgraph_uid=7, symbol_order=12)

Modification phase of node mdns_domain_debug_print/12
Adjusting mask for param 0 to 0xfffffffc
Adjusting align: 4, misalign: 0
Setting nonnull for 0
mdns_domain_debug_print (struct mdns_domain * domain)
{
  u8_t * src;
  sizetype _1;
  unsigned char _2;
  sizetype _7;

  <bb 2> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  src_5 = &domain_4(D)->name;
  # DEBUG src => src_5
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  # DEBUG label_len => _2
  # DEBUG BEGIN_STMT
  # DEBUG src => src_3 + 1
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  # DEBUG i => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (sizetype) _2;
  _7 = _1 + 1;
  src_8 = src_3 + _7;
  # DEBUG src => src_8

  <bb 4> [local count: 1073741824]:
  # src_3 = PHI <src_5(2), src_8(3)>
  # DEBUG src => src_3
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = *src_3;
  if (_2 != 0)
    goto <bb 3>; [89.00%]
  else
    goto <bb 5>; [11.00%]

  <bb 5> [local count: 118111601]:
  return;

}



;; Function mdns_prepare_txtdata (mdns_prepare_txtdata, funcdef_no=8, decl_uid=7438, cgraph_uid=9, symbol_order=14)

Modification phase of node mdns_prepare_txtdata/14
mdns_prepare_txtdata (struct mdns_service * service)
{
  struct mdns_domain * _1;
  void (*<T707>) (struct mdns_service *, void *) _2;
  void * _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = &service_5(D)->txtdata;
  memset (_1, 0, 260);
  # DEBUG BEGIN_STMT
  _2 = service_5(D)->txt_fn;
  if (_2 != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 4>; [30.00%]

  <bb 3> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  _3 = service_5(D)->txt_userdata;
  _2 (service_5(D), _3);

  <bb 4> [local count: 1073741824]:
  return;

}



;; Function mdns_readname_loop (mdns_readname_loop, funcdef_no=4, decl_uid=7401, cgraph_uid=5, symbol_order=10)

Modification phase of node mdns_readname_loop/10
Setting value range of param 3 [0, 6]
mdns_readname_loop (struct pbuf * p, u16_t offset, struct mdns_domain * domain, unsigned int depth)
{
  err_t res;
  u16_t res;
  u16_t jumpaddr;
  u8_t c;
  int _1;
  int _2;
  short unsigned int _3;
  int _5;
  signed short _6;
  signed short _7;
  unsigned char _8;
  signed short _9;
  signed short _10;
  short unsigned int _11;
  unsigned int _12;
  short unsigned int _14;
  int _15;
  int _16;
  short unsigned int _17;
  u16_t _19;
  unsigned char _29;

  <bb 2> [local count: 122575812]:

  <bb 3> [local count: 1073741824]:
  # offset_18 = PHI <offset_22(D)(2), offset_33(15)>
  # DEBUG offset => offset_18
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (depth_24(D) > 5)
    goto <bb 14>; [2.00%]
  else
    goto <bb 4>; [98.00%]

  <bb 4> [local count: 1052266988]:
  # DEBUG BEGIN_STMT
  c_27 = pbuf_get_at (p_25(D), offset_18);
  # DEBUG c => c_27
  # DEBUG BEGIN_STMT
  offset_28 = offset_18 + 1;
  # DEBUG offset => offset_28
  # DEBUG BEGIN_STMT
  _2 = (int) c_27;
  _29 = c_27 & 192;
  if (_29 == 192)
    goto <bb 5>; [2.00%]
  else
    goto <bb 10>; [98.00%]

  <bb 5> [local count: 21045340]:
  # _1 = PHI <_2(4)>
  # offset_13 = PHI <offset_18(4)>
  # offset_4 = PHI <offset_28(4)>
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = p_25(D)->tot_len;
  if (_3 <= offset_4)
    goto <bb 14>; [36.03%]
  else
    goto <bb 6>; [63.97%]

  <bb 6> [local count: 13462704]:
  # DEBUG BEGIN_STMT
  _5 = _1 << 8;
  _6 = (signed short) _5;
  _7 = _6 & 16128;
  _8 = pbuf_get_at (p_25(D), offset_4);
  _9 = (signed short) _8;
  _10 = _7 | _9;
  jumpaddr_35 = (u16_t) _10;
  # DEBUG jumpaddr => jumpaddr_35
  # DEBUG BEGIN_STMT
  offset_36 = offset_13 + 2;
  # DEBUG offset => offset_36
  # DEBUG BEGIN_STMT
  if (jumpaddr_35 > 11)
    goto <bb 7>; [78.28%]
  else
    goto <bb 14>; [21.72%]

  <bb 7> [local count: 10538605]:
  _11 = p_25(D)->tot_len;
  if (_11 > jumpaddr_35)
    goto <bb 8>; [63.97%]
  else
    goto <bb 14>; [36.03%]

  <bb 8> [local count: 6741545]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _12 = depth_24(D) + 1;
  res_38 = mdns_readname_loop (p_25(D), jumpaddr_35, domain_30(D), _12);
  # DEBUG res => res_38
  # DEBUG BEGIN_STMT
  if (res_38 == 65535)
    goto <bb 9>; [12.50%]
  else
    goto <bb 14>; [87.50%]

  <bb 9> [local count: 842693]:
  # DEBUG BEGIN_STMT
  goto <bb 14>; [100.00%]

  <bb 10> [local count: 1031221649]:
  # DEBUG BEGIN_STMT
  if (c_27 <= 63)
    goto <bb 11>; [98.00%]
  else
    goto <bb 14>; [2.00%]

  <bb 11> [local count: 1010597217]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _14 = domain_30(D)->length;
  _15 = (int) _14;
  _16 = _2 + _15;
  if (_16 > 255)
    goto <bb 14>; [2.00%]
  else
    goto <bb 12>; [98.00%]

  <bb 12> [local count: 990385272]:
  # DEBUG BEGIN_STMT
  res_32 = mdns_domain_add_label_pbuf (domain_30(D), p_25(D), offset_28, c_27);
  # DEBUG res => res_32
  # DEBUG BEGIN_STMT
  if (res_32 != 0)
    goto <bb 14>; [2.00%]
  else
    goto <bb 13>; [98.00%]

  <bb 13> [local count: 970577566]:
  # DEBUG BEGIN_STMT
  _17 = (short unsigned int) c_27;
  offset_33 = _17 + offset_28;
  # DEBUG offset => offset_33
  # DEBUG BEGIN_STMT
  if (c_27 != 0)
    goto <bb 15>; [98.00%]
  else
    goto <bb 14>; [2.00%]

  <bb 15> [local count: 951166011]:
  goto <bb 3>; [100.00%]

  <bb 14> [local count: 122575810]:
  # _19 = PHI <65535(3), 65535(5), 65535(9), 65535(7), 65535(11), 65535(12), 65535(10), offset_33(13), offset_36(8), 65535(6)>
  # DEBUG offset => NULL
  return _19;

}



;; Function mdns_domain_add_label (mdns_domain_add_label, funcdef_no=2, decl_uid=6863, cgraph_uid=3, symbol_order=8)

Modification phase of node mdns_domain_add_label/8
mdns_domain_add_label (struct mdns_domain * domain, const char * label, u8_t len)
{
  err_t err;
  err_t _1;
  signed char _2;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  err_7 = mdns_domain_add_label_base (domain_4(D), len_5(D));
  # DEBUG err => err_7
  # DEBUG BEGIN_STMT
  if (err_7 != 0)
    goto <bb 5>; [34.00%]
  else
    goto <bb 3>; [66.00%]

  <bb 3> [local count: 708669604]:
  # DEBUG BEGIN_STMT
  if (len_5(D) != 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 4> [local count: 233860968]:
  _2 = mdns_domain_add_label.part.0 (domain_4(D), label_8(D), len_5(D));

  <bb 5> [local count: 1073741824]:
  # _1 = PHI <err_7(2), _2(4), 0(3)>
  return _1;

}



;; Function mdns_add_dotlocal (mdns_add_dotlocal, funcdef_no=11, decl_uid=7469, cgraph_uid=12, symbol_order=17)

Modification phase of node mdns_add_dotlocal/17
Adjusting mask for param 0 to 0xfffffffc
Adjusting align: 4, misalign: 0
Setting nonnull for 0
mdns_add_dotlocal (struct mdns_domain * domain)
{
  err_t res;
  err_t _1;
  signed char _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  res_5 = mdns_domain_add_label (domain_3(D), "local", 5);
  # DEBUG res => res_5
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (res_5 != 0)
    goto <bb 4>; [51.12%]
  else
    goto <bb 3>; [48.88%]

  <bb 3> [local count: 524845000]:
  _6 = mdns_add_dotlocal.part.0 (domain_3(D));

  <bb 4> [local count: 1073741824]:
  # _1 = PHI <res_5(2), _6(3)>
  return _1;

}



;; Function mdns_build_host_domain (mdns_build_host_domain, funcdef_no=12, decl_uid=7474, cgraph_uid=13, symbol_order=18)

Modification phase of node mdns_build_host_domain/18
Adjusting mask for param 0 to 0xfffffffc
Adjusting align: 4, misalign: 0
Setting nonnull for 0
mdns_build_host_domain (struct mdns_domain * domain, struct mdns_host * mdns)
{
  err_t res;
  char[64] * _1;
  unsigned int _2;
  unsigned char _3;
  err_t _4;
  err_t _13;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  memset (domain_7(D), 0, 260);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (mdns_9(D) == 0B)
    goto <bb 5>; [0.91%]
  else
    goto <bb 3>; [99.09%]

  <bb 3> [local count: 1063970774]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = &mdns_9(D)->name;
  _2 = strlen (_1);
  _3 = (unsigned char) _2;
  res_11 = mdns_domain_add_label (domain_7(D), _1, _3);
  # DEBUG res => res_11
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (res_11 != 0)
    goto <bb 5>; [51.12%]
  else
    goto <bb 4>; [48.88%]

  <bb 4> [local count: 520068914]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _13 = mdns_add_dotlocal (domain_7(D));

  <bb 5> [local count: 1073741824]:
  # _4 = PHI <-6(2), res_11(3), _13(4)>
  return _4;

}



;; Function mdns_build_service_domain (mdns_build_service_domain, funcdef_no=14, decl_uid=7484, cgraph_uid=15, symbol_order=20)

Modification phase of node mdns_build_service_domain/20
Adjusting mask for param 0 to 0xfffffffc
Adjusting align: 4, misalign: 0
Adjusting mask for param 2 to 0x1
Setting nonnull for 0
Setting value range of param 2 [0, 1]
mdns_build_service_domain (struct mdns_domain * domain, struct mdns_service * service, int include_name)
{
  err_t res;
  char[64] * _1;
  signed char _2;
  unsigned int _3;
  unsigned char _4;
  char[64] * _5;
  unsigned int _7;
  unsigned char _8;
  err_t _10;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  memset (domain_13(D), 0, 260);
  # DEBUG BEGIN_STMT
  if (include_name_15(D) != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _1 = &service_16(D)->name;
  _3 = strlen (_1);
  _4 = (unsigned char) _3;
  res_18 = mdns_domain_add_label (domain_13(D), _1, _4);
  # DEBUG res => res_18
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (res_18 != 0)
    goto <bb 6>; [34.00%]
  else
    goto <bb 4>; [66.00%]

  <bb 4> [local count: 891205715]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _5 = &service_16(D)->service;
  _7 = strlen (_5);
  _8 = (unsigned char) _7;
  res_20 = mdns_domain_add_label (domain_13(D), _5, _8);
  # DEBUG res => res_20
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (res_20 != 0)
    goto <bb 6>; [51.12%]
  else
    goto <bb 5>; [48.88%]

  <bb 5> [local count: 435621351]:
  # DEBUG D#1 => include_name_15(D)
  _2 = mdns_build_service_domain.part.0 (domain_13(D), service_16(D));

  <bb 6> [local count: 1073741824]:
  # _10 = PHI <res_18(3), res_20(4), _2(5)>
  return _10;

}



;; Function mdns_build_reverse_v4_domain (mdns_build_reverse_v4_domain, funcdef_no=9, decl_uid=7442, cgraph_uid=10, symbol_order=15)

Modification phase of node mdns_build_reverse_v4_domain/15
Adjusting mask for param 0 to 0xfffffffc
Adjusting align: 4, misalign: 0
Setting nonnull for 0
mdns_build_reverse_v4_domain (struct mdns_domain * domain, const struct ip4_addr_t * addr)
{
  u8_t val;
  char buf[4];
  err_t res;
  int i;
  sizetype i.30_1;
  const u8_t * _2;
  int _3;
  unsigned int _4;
  unsigned char _5;
  err_t _7;
  signed char _14;

  <bb 2> [local count: 265594209]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (domain_9(D) == 0B)
    goto <bb 11>; [0.45%]
  else
    goto <bb 3>; [99.55%]

  <bb 3> [local count: 264399035]:
  if (addr_10(D) == 0B)
    goto <bb 11>; [0.91%]
  else
    goto <bb 4>; [99.09%]

  <bb 4> [local count: 261993004]:
  # DEBUG BEGIN_STMT
  memset (domain_9(D), 0, 260);
  # DEBUG BEGIN_STMT
  # DEBUG ptr => addr_10(D)
  # DEBUG BEGIN_STMT
  # DEBUG i => 3
  goto <bb 8>; [100.00%]

  <bb 5> [local count: 858993460]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  i.30_1 = (sizetype) i_6;
  _2 = addr_10(D) + i.30_1;
  val_19 = *_2;
  # DEBUG val => val_19
  # DEBUG BEGIN_STMT
  _3 = (int) val_19;
  lwip_itoa (&buf, 4, _3);
  # DEBUG BEGIN_STMT
  _4 = strlen (&buf);
  _5 = (unsigned char) _4;
  res_22 = mdns_domain_add_label (domain_9(D), &buf, _5);
  # DEBUG res => res_22
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (res_22 != 0)
    goto <bb 6>; [5.50%]
  else
    goto <bb 7>; [94.50%]

  <bb 6> [local count: 47244640]:
  # res_13 = PHI <res_22(5)>
  # DEBUG BEGIN_STMT
  buf ={v} {CLOBBER};
  goto <bb 11>; [100.00%]

  <bb 7> [local count: 811748819]:
  # DEBUG BEGIN_STMT
  buf ={v} {CLOBBER};
  # DEBUG BEGIN_STMT
  i_24 = i_6 + -1;
  # DEBUG i => i_24

  <bb 8> [local count: 1073741824]:
  # i_6 = PHI <3(4), i_24(7)>
  # DEBUG i => i_6
  # DEBUG BEGIN_STMT
  if (i_6 != -1)
    goto <bb 5>; [80.00%]
  else
    goto <bb 9>; [20.00%]

  <bb 9> [local count: 214748365]:
  # DEBUG BEGIN_STMT
  res_16 = mdns_domain_add_label (domain_9(D), "in-addr", 7);
  # DEBUG res => res_16
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (res_16 != 0)
    goto <bb 11>; [51.12%]
  else
    goto <bb 10>; [48.88%]

  <bb 10> [local count: 104969000]:
  # DEBUG D#3 => addr_10(D)
  _14 = mdns_build_reverse_v4_domain.part.0 (domain_9(D));

  <bb 11> [local count: 265594210]:
  # _7 = PHI <-16(3), res_13(6), res_16(9), _14(10), -16(2)>
  return _7;

}



;; Function mdns_build_reverse_v6_domain (mdns_build_reverse_v6_domain, funcdef_no=10, decl_uid=7454, cgraph_uid=11, symbol_order=16)

Modification phase of node mdns_build_reverse_v6_domain/16
Adjusting mask for param 0 to 0xfffffffc
Adjusting align: 4, misalign: 0
Setting nonnull for 0
mdns_build_reverse_v6_domain (struct mdns_domain * domain, const struct ip6_addr_t * addr)
{
  int j;
  u8_t byte;
  char buf;
  err_t res;
  int i;
  sizetype i.33_1;
  const u8_t * _2;
  signed char _3;
  char _6;
  char _8;
  err_t _12;
  unsigned char _20;

  <bb 2> [local count: 65072437]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (domain_16(D) == 0B)
    goto <bb 16>; [0.45%]
  else
    goto <bb 3>; [99.55%]

  <bb 3> [local count: 64779611]:
  if (addr_17(D) == 0B)
    goto <bb 16>; [0.91%]
  else
    goto <bb 4>; [99.09%]

  <bb 4> [local count: 64190116]:
  # DEBUG BEGIN_STMT
  memset (domain_16(D), 0, 260);
  # DEBUG BEGIN_STMT
  # DEBUG ptr => addr_17(D)
  # DEBUG BEGIN_STMT
  # DEBUG i => 15
  goto <bb 14>; [100.00%]

  <bb 5> [local count: 397250652]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  i.33_1 = (sizetype) i_9;
  _2 = addr_17(D) + i.33_1;
  byte_21 = *_2;
  # DEBUG byte => byte_21
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG j => 0
  goto <bb 12>; [100.00%]

  <bb 6> [local count: 715863675]:
  # DEBUG BEGIN_STMT
  _20 = byte_10 & 15;
  if (_20 <= 9)
    goto <bb 7>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 7> [local count: 357931837]:
  # DEBUG BEGIN_STMT
  _6 = _20 + 48;
  buf = _6;
  goto <bb 9>; [100.00%]

  <bb 8> [local count: 357931837]:
  # DEBUG BEGIN_STMT
  _8 = _20 + 87;
  buf = _8;

  <bb 9> [local count: 715863675]:
  # DEBUG BEGIN_STMT
  res_27 = mdns_domain_add_label (domain_16(D), &buf, 1);
  # DEBUG res => res_27
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (res_27 != 0)
    goto <bb 10>; [5.50%]
  else
    goto <bb 11>; [94.50%]

  <bb 10> [local count: 39372502]:
  # res_7 = PHI <res_27(9)>
  # DEBUG BEGIN_STMT
  buf ={v} {CLOBBER};
  goto <bb 16>; [100.00%]

  <bb 11> [local count: 676491173]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  byte_28 = byte_10 >> 4;
  # DEBUG byte => byte_28
  # DEBUG BEGIN_STMT
  j_29 = j_11 + 1;
  # DEBUG j => j_29

  <bb 12> [local count: 1073741824]:
  # byte_10 = PHI <byte_21(5), byte_28(11)>
  # j_11 = PHI <0(5), j_29(11)>
  # DEBUG j => j_11
  # DEBUG byte => byte_10
  # DEBUG BEGIN_STMT
  if (j_11 != 2)
    goto <bb 6>; [66.67%]
  else
    goto <bb 13>; [33.33%]

  <bb 13> [local count: 357878150]:
  buf ={v} {CLOBBER};
  # DEBUG BEGIN_STMT
  i_23 = i_9 + -1;
  # DEBUG i => i_23

  <bb 14> [local count: 422068266]:
  # i_9 = PHI <15(4), i_23(13)>
  # DEBUG i => i_9
  # DEBUG BEGIN_STMT
  if (i_9 != -1)
    goto <bb 5>; [94.12%]
  else
    goto <bb 15>; [5.88%]

  <bb 15> [local count: 24817613]:
  # DEBUG D#5 => addr_17(D)
  _3 = mdns_build_reverse_v6_domain.part.0 (domain_16(D));

  <bb 16> [local count: 65072437]:
  # _12 = PHI <-16(3), res_7(10), _3(15), -16(2)>
  return _12;

}



;; Function mdns_build_dnssd_domain (mdns_build_dnssd_domain, funcdef_no=13, decl_uid=7478, cgraph_uid=14, symbol_order=19)

Modification phase of node mdns_build_dnssd_domain/19
Adjusting mask for param 0 to 0xfffffffc
Adjusting align: 4, misalign: 0
Setting nonnull for 0
mdns_build_dnssd_domain (struct mdns_domain * domain)
{
  err_t res;
  signed char _1;
  err_t _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  memset (domain_4(D), 0, 260);
  # DEBUG BEGIN_STMT
  res_7 = mdns_domain_add_label (domain_4(D), "_services", 9);
  # DEBUG res => res_7
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (res_7 != 0)
    goto <bb 5>; [51.12%]
  else
    goto <bb 3>; [48.88%]

  <bb 3> [local count: 524845004]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  res_9 = mdns_domain_add_label (domain_4(D), "_dns-sd", 7);
  # DEBUG res => res_9
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (res_9 != 0)
    goto <bb 5>; [51.12%]
  else
    goto <bb 4>; [48.88%]

  <bb 4> [local count: 256544236]:
  _1 = mdns_build_dnssd_domain.part.0 (domain_4(D));

  <bb 5> [local count: 1073741823]:
  # _2 = PHI <res_7(2), res_9(3), _1(4)>
  return _2;

}



;; Function mdns_readname (mdns_readname, funcdef_no=5, decl_uid=6867, cgraph_uid=6, symbol_order=11)

Modification phase of node mdns_readname/11
mdns_readname (struct pbuf * p, u16_t offset, struct mdns_domain * domain)
{
  u16_t _7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  memset (domain_2(D), 0, 260);
  # DEBUG BEGIN_STMT
  _7 = mdns_readname_loop (p_4(D), offset_5(D), domain_2(D), 0);
  return _7;

}



;; Function mdns_read_rr_info (mdns_read_rr_info, funcdef_no=21, decl_uid=7568, cgraph_uid=22, symbol_order=27)

Modification phase of node mdns_read_rr_info/27
Adjusting mask for param 0 to 0xfffffffc
Adjusting align: 4, misalign: 0
Adjusting mask for param 1 to 0xfffffffc
Adjusting align: 4, misalign: 0
Setting nonnull for 0
Setting nonnull for 1
mdns_read_rr_info (struct mdns_packet * pkt, struct mdns_rr_info * info)
{
  u16_t copied;
  u16_t field16;
  struct pbuf * _1;
  short unsigned int _2;
  struct mdns_domain * _3;
  short unsigned int _4;
  struct pbuf * _5;
  short unsigned int _6;
  short unsigned int _7;
  short unsigned int field16.64_8;
  short unsigned int _9;
  struct pbuf * _10;
  short unsigned int _11;
  short unsigned int _12;
  short unsigned int _13;
  short unsigned int field16.65_14;
  short unsigned int _15;
  err_t _16;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pkt_19(D)->pbuf;
  _2 = pkt_19(D)->parse_offset;
  _3 = &info_20(D)->domain;
  _4 = mdns_readname (_1, _2, _3);
  pkt_19(D)->parse_offset = _4;
  # DEBUG BEGIN_STMT
  if (_4 == 65535)
    goto <bb 6>; [1.09%]
  else
    goto <bb 3>; [98.91%]

  <bb 3> [local count: 1062038039]:
  # DEBUG BEGIN_STMT
  _5 = pkt_19(D)->pbuf;
  copied_24 = pbuf_copy_partial (_5, &field16, 2, _4);
  # DEBUG copied => copied_24
  # DEBUG BEGIN_STMT
  if (copied_24 != 2)
    goto <bb 6>; [3.98%]
  else
    goto <bb 4>; [96.02%]

  <bb 4> [local count: 1019768924]:
  # DEBUG BEGIN_STMT
  _6 = pkt_19(D)->parse_offset;
  _7 = _6 + 2;
  pkt_19(D)->parse_offset = _7;
  # DEBUG BEGIN_STMT
  field16.64_8 = field16;
  _9 = lwip_htons (field16.64_8);
  info_20(D)->type = _9;
  # DEBUG BEGIN_STMT
  _10 = pkt_19(D)->pbuf;
  _11 = pkt_19(D)->parse_offset;
  copied_29 = pbuf_copy_partial (_10, &field16, 2, _11);
  # DEBUG copied => copied_29
  # DEBUG BEGIN_STMT
  if (copied_29 != 2)
    goto <bb 6>; [3.98%]
  else
    goto <bb 5>; [96.02%]

  <bb 5> [local count: 979182121]:
  # DEBUG BEGIN_STMT
  _12 = pkt_19(D)->parse_offset;
  _13 = _12 + 2;
  pkt_19(D)->parse_offset = _13;
  # DEBUG BEGIN_STMT
  field16.65_14 = field16;
  _15 = lwip_htons (field16.65_14);
  info_20(D)->klass = _15;
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
  # _16 = PHI <-6(2), -6(3), -6(4), 0(5)>
  field16 ={v} {CLOBBER};
  return _16;

}



;; Function mdns_read_question (mdns_read_question, funcdef_no=22, decl_uid=7574, cgraph_uid=23, symbol_order=28)

Modification phase of node mdns_read_question/28
Adjusting mask for param 0 to 0xfffffffc
Adjusting align: 4, misalign: 0
Adjusting mask for param 1 to 0xfffffffc
Adjusting align: 4, misalign: 0
Setting nonnull for 0
Setting nonnull for 1
mdns_read_question (struct mdns_packet * pkt, struct mdns_question * question)
{
  err_t res;
  struct pbuf * _1;
  short unsigned int _2;
  short unsigned int _3;
  short unsigned int _4;
  signed char _5;
  short unsigned int _6;
  struct mdns_rr_info * _7;
  err_t _9;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = pkt_11(D)->pbuf;
  _2 = _1->tot_len;
  _3 = pkt_11(D)->parse_offset;
  if (_2 < _3)
    goto <bb 6>; [1.04%]
  else
    goto <bb 3>; [98.96%]

  <bb 3> [local count: 1062574910]:
  # DEBUG BEGIN_STMT
  _4 = pkt_11(D)->questions_left;
  if (_4 != 0)
    goto <bb 4>; [96.02%]
  else
    goto <bb 6>; [3.98%]

  <bb 4> [local count: 1020284429]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _6 = _4 + 65535;
  pkt_11(D)->questions_left = _6;
  # DEBUG BEGIN_STMT
  memset (question_14(D), 0, 266);
  # DEBUG BEGIN_STMT
  _7 = &question_14(D)->info;
  res_17 = mdns_read_rr_info (pkt_11(D), _7);
  # DEBUG res => res_17
  # DEBUG BEGIN_STMT
  if (res_17 != 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 5> [local count: 510142215]:
  # DEBUG D#7 => pkt_11(D)
  _5 = mdns_read_question.part.0 (question_14(D));

  <bb 6> [local count: 1073741824]:
  # _9 = PHI <-6(2), res_17(4), _5(5), -6(3)>
  return _9;

}



;; Function mdns_read_answer (mdns_read_answer, funcdef_no=23, decl_uid=7579, cgraph_uid=24, symbol_order=29)

Modification phase of node mdns_read_answer/29
Adjusting mask for param 0 to 0xfffffffc
Adjusting align: 4, misalign: 0
Adjusting mask for param 1 to 0xfffffffc
Adjusting align: 4, misalign: 0
Setting nonnull for 0
Setting nonnull for 1
mdns_read_answer (struct mdns_packet * pkt, struct mdns_answer * answer)
{
  err_t res;
  u32_t ttl;
  u16_t field16;
  u16_t copied;
  short unsigned int _1;
  struct pbuf * _2;
  short unsigned int _3;
  short unsigned int _4;
  short unsigned int _5;
  short unsigned int _6;
  struct mdns_rr_info * _7;
  short unsigned int _8;
  short unsigned int _9;
  short unsigned int _10;
  struct pbuf * _11;
  short unsigned int _12;
  short unsigned int _13;
  short unsigned int _14;
  long unsigned int ttl.66_15;
  long unsigned int _16;
  struct pbuf * _17;
  short unsigned int _18;
  short unsigned int _19;
  short unsigned int _20;
  short unsigned int field16.67_21;
  short unsigned int _22;
  short unsigned int _23;
  short unsigned int _24;
  err_t _25;
  err_t _26;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = pkt_30(D)->questions_left;
  if (_1 != 0)
    goto <bb 10>; [1.04%]
  else
    goto <bb 3>; [98.96%]

  <bb 3> [local count: 1062574910]:
  # DEBUG BEGIN_STMT
  _2 = pkt_30(D)->pbuf;
  _3 = _2->tot_len;
  _4 = pkt_30(D)->parse_offset;
  if (_3 < _4)
    goto <bb 10>; [1.04%]
  else
    goto <bb 4>; [98.96%]

  <bb 4> [local count: 1051524131]:
  # DEBUG BEGIN_STMT
  _5 = pkt_30(D)->answers_left;
  if (_5 != 0)
    goto <bb 5>; [96.02%]
  else
    goto <bb 10>; [3.98%]

  <bb 5> [local count: 1009673471]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _6 = _5 + 65535;
  pkt_30(D)->answers_left = _6;
  # DEBUG BEGIN_STMT
  memset (answer_32(D), 0, 276);
  # DEBUG BEGIN_STMT
  _7 = &answer_32(D)->info;
  res_35 = mdns_read_rr_info (pkt_30(D), _7);
  # DEBUG res => res_35
  # DEBUG BEGIN_STMT
  if (res_35 != 0)
    goto <bb 9>; [51.12%]
  else
    goto <bb 6>; [48.88%]

  <bb 6> [local count: 493528393]:
  # DEBUG BEGIN_STMT
  _8 = answer_32(D)->info.klass;
  _9 = _8 & 32768;
  answer_32(D)->cache_flush = _9;
  # DEBUG BEGIN_STMT
  _10 = _8 & 32767;
  answer_32(D)->info.klass = _10;
  # DEBUG BEGIN_STMT
  _11 = pkt_30(D)->pbuf;
  _12 = pkt_30(D)->parse_offset;
  copied_39 = pbuf_copy_partial (_11, &ttl, 4, _12);
  # DEBUG copied => copied_39
  # DEBUG BEGIN_STMT
  if (copied_39 != 4)
    goto <bb 9>; [67.00%]
  else
    goto <bb 7>; [33.00%]

  <bb 7> [local count: 162864370]:
  # DEBUG BEGIN_STMT
  _13 = pkt_30(D)->parse_offset;
  _14 = _13 + 4;
  pkt_30(D)->parse_offset = _14;
  # DEBUG BEGIN_STMT
  ttl.66_15 = ttl;
  _16 = lwip_htonl (ttl.66_15);
  answer_32(D)->ttl = _16;
  # DEBUG BEGIN_STMT
  _17 = pkt_30(D)->pbuf;
  _18 = pkt_30(D)->parse_offset;
  copied_44 = pbuf_copy_partial (_17, &field16, 2, _18);
  # DEBUG copied => copied_44
  # DEBUG BEGIN_STMT
  if (copied_44 != 2)
    goto <bb 9>; [79.76%]
  else
    goto <bb 8>; [20.24%]

  <bb 8> [local count: 32963748]:
  # DEBUG BEGIN_STMT
  _19 = pkt_30(D)->parse_offset;
  _20 = _19 + 2;
  pkt_30(D)->parse_offset = _20;
  # DEBUG BEGIN_STMT
  field16.67_21 = field16;
  _22 = lwip_htons (field16.67_21);
  answer_32(D)->rd_length = _22;
  # DEBUG BEGIN_STMT
  _23 = pkt_30(D)->parse_offset;
  answer_32(D)->rd_offset = _23;
  # DEBUG BEGIN_STMT
  _24 = _22 + _23;
  pkt_30(D)->parse_offset = _24;
  # DEBUG BEGIN_STMT

  <bb 9> [local count: 1009673471]:
  # _25 = PHI <res_35(5), -6(6), -6(7), 0(8)>
  field16 ={v} {CLOBBER};
  ttl ={v} {CLOBBER};

  <bb 10> [local count: 1073741824]:
  # _26 = PHI <-6(2), -6(3), _25(9), -6(4)>
  return _26;

}



;; Function mdns_compress_domain.part.0 (mdns_compress_domain.part.0, funcdef_no=61, decl_uid=8761, cgraph_uid=92, symbol_order=101)

Modification phase of node mdns_compress_domain.part.0/101
mdns_compress_domain.part.0 (struct pbuf * pbuf, u16_t * offset, struct mdns_domain * domain)
{
  struct mdns_domain target;
  u16_t target_end;
  u8_t target_len;
  u8_t writelen;
  u8_t * ptr;
  u8_t domainlen;
  u8_t labellen;
  u8_t targetpos;
  short unsigned int _2;
  short unsigned int _6;
  unsigned char _7;
  short unsigned int _8;
  unsigned char _9;
  short unsigned int _12;
  unsigned char _13;
  short unsigned int _16;
  short unsigned int _17;
  unsigned char _18;
  unsigned char _19;
  int _21;
  int _22;
  int _23;
  int _24;
  u8_t * _25;
  u8_t * _26;
  unsigned int _27;
  int _28;
  short unsigned int _30;
  short unsigned int _31;
  unsigned char _34;
  int _36;
  int _37;
  sizetype _38;
  short unsigned int _40;
  short unsigned int _41;
  short unsigned int _42;

  <bb 13> [local count: 73241592]:

  <bb 2> [local count: 73241592]:
  # DEBUG BEGIN_STMT
  _2 = *offset_1(D);
  target_end_4 = mdns_readname (pbuf_3(D), _2, &target);
  # DEBUG target_end => target_end_4
  # DEBUG BEGIN_STMT
  if (target_end_4 == 65535)
    goto <bb 3>; [20.97%]
  else
    goto <bb 4>; [79.03%]

  <bb 3> [local count: 15358762]:
  # DEBUG BEGIN_STMT
  _6 = domain_5(D)->length;
  // predicted unlikely by early return (on trees) predictor.
  goto <bb 12>; [100.00%]

  <bb 4> [local count: 57882830]:
  # DEBUG BEGIN_STMT
  _7 = (unsigned char) target_end_4;
  _8 = *offset_1(D);
  _9 = (unsigned char) _8;
  target_len_10 = _7 - _9;
  # DEBUG target_len => target_len_10
  # DEBUG BEGIN_STMT
  ptr_11 = &domain_5(D)->name;
  # DEBUG ptr => ptr_11
  # DEBUG BEGIN_STMT
  goto <bb 11>; [100.00%]

  <bb 5> [local count: 1034442873]:
  # DEBUG BEGIN_STMT
  _13 = (unsigned char) _12;
  domainlen_15 = _13 - writelen_14;
  # DEBUG domainlen => domainlen_15
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _16 = (short unsigned int) domainlen_15;
  _17 = target.length;
  if (_16 <= _17)
    goto <bb 6>; [50.00%]
  else
    goto <bb 10>; [50.00%]

  <bb 6> [local count: 517221436]:
  if (domainlen_15 > 2)
    goto <bb 7>; [50.00%]
  else
    goto <bb 10>; [50.00%]

  <bb 7> [local count: 258610718]:
  # DEBUG BEGIN_STMT
  _18 = (unsigned char) _17;
  _19 = writelen_14 - _13;
  targetpos_20 = _18 + _19;
  # DEBUG targetpos => targetpos_20
  # DEBUG BEGIN_STMT
  _21 = (int) targetpos_20;
  _22 = _21 + 2;
  _23 = (int) target_len_10;
  if (_22 >= _23)
    goto <bb 12>; [3.66%]
  else
    goto <bb 8>; [96.34%]

  <bb 8> [local count: 249145566]:
  # DEBUG BEGIN_STMT
  _24 = (int) writelen_14;
  _25 = &domain_5(D)->name[_24];
  _26 = &target.name[_21];
  _27 = (unsigned int) domainlen_15;
  _28 = memcmp (_25, _26, _27);
  if (_28 == 0)
    goto <bb 9>; [3.66%]
  else
    goto <bb 10>; [96.34%]

  <bb 9> [local count: 9118728]:
  # _42 = PHI <_40(8)>
  # targetpos_29 = PHI <targetpos_20(8)>
  # DEBUG BEGIN_STMT
  _30 = (short unsigned int) targetpos_29;
  _31 = _8 + _30;
  *offset_1(D) = _31;
  # DEBUG BEGIN_STMT
  // predicted unlikely by early return (on trees) predictor.
  goto <bb 12>; [100.00%]

  <bb 10> [local count: 1015858994]:
  # DEBUG BEGIN_STMT
  labellen_33 = *ptr_32;
  # DEBUG labellen => labellen_33
  # DEBUG BEGIN_STMT
  _34 = writelen_14 + labellen_33;
  writelen_35 = _34 + 1;
  # DEBUG writelen => writelen_35
  # DEBUG BEGIN_STMT
  _36 = (int) labellen_33;
  _37 = _36 + 1;
  _38 = (sizetype) _37;
  ptr_39 = ptr_32 + _38;
  # DEBUG ptr => ptr_39

  <bb 11> [local count: 1073741824]:
  # writelen_14 = PHI <0(4), writelen_35(10)>
  # ptr_32 = PHI <ptr_11(4), ptr_39(10)>
  # DEBUG ptr => ptr_32
  # DEBUG writelen => writelen_14
  # DEBUG BEGIN_STMT
  _40 = (short unsigned int) writelen_14;
  _12 = domain_5(D)->length;
  if (_12 > _40)
    goto <bb 5>; [96.34%]
  else
    goto <bb 12>; [3.66%]

  <bb 12> [local count: 73241593]:
  # _41 = PHI <_6(3), _12(7), _42(9), _12(11)>
  target ={v} {CLOBBER};
  return _41;

}



;; Function mdns_domain_eq (mdns_domain_eq, funcdef_no=7, decl_uid=6870, cgraph_uid=8, symbol_order=13)

Modification phase of node mdns_domain_eq/13
mdns_domain_eq (struct mdns_domain * a, struct mdns_domain * b)
{
  short unsigned int _1;
  short unsigned int _2;
  int _3;
  int _6;

  <bb 2> [local count: 226055540]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = a_8(D)->length;
  _2 = b_9(D)->length;
  if (_1 != _2)
    goto <bb 4>; [50.00%]
  else
    goto <bb 3>; [50.00%]

  <bb 3> [local count: 113027770]:
  _3 = mdns_domain_eq.part.0 (a_8(D), b_9(D));

  <bb 4> [local count: 226055540]:
  # _6 = PHI <0(2), _3(3)>
  return _6;

}



;; Function mdns_handle_response (mdns_handle_response, funcdef_no=36, decl_uid=7732, cgraph_uid=37, symbol_order=42)

Modification phase of node mdns_handle_response/42
Adjusting mask for param 0 to 0xfffffffc
Adjusting align: 4, misalign: 0
Setting nonnull for 0
mdns_handle_response (struct mdns_packet * pkt)
{
  struct mdns_service * service;
  u8_t conflict;
  u8_t i;
  struct mdns_domain domain;
  err_t res;
  struct mdns_answer ans;
  err_t res;
  struct mdns_question q;
  struct mdns_host * mdns;
  struct netif * _1;
  unsigned char mdns_netif_client_id.60_2;
  int _3;
  short unsigned int _4;
  unsigned char _5;
  unsigned char _6;
  int _7;
  int _9;
  struct netif * _10;
  void (*<T709>) (struct netif *, u8_t) mdns_name_result_cb.62_11;
  struct netif * _13;
  short unsigned int _14;

  <bb 2> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  _1 = pkt_28(D)->netif;
  mdns_netif_client_id.60_2 = mdns_netif_client_id;
  _3 = (int) mdns_netif_client_id.60_2;
  mdns_29 = _1->client_data[_3];
  # DEBUG mdns => mdns_29
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 3> [local count: 1014686025]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  res_46 = mdns_read_question (pkt_28(D), &q);
  # DEBUG res => res_46
  # DEBUG BEGIN_STMT
  if (res_46 != 0)
    goto <bb 4>; [5.50%]
  else
    goto <bb 5>; [94.50%]

  <bb 4> [local count: 55807731]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  q ={v} {CLOBBER};
  goto <bb 28>; [100.00%]

  <bb 5> [local count: 958878293]:
  q ={v} {CLOBBER};

  <bb 6> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _4 = pkt_28(D)->questions_left;
  if (_4 != 0)
    goto <bb 3>; [94.50%]
  else
    goto <bb 29>; [5.50%]

  <bb 29> [local count: 59055800]:
  goto <bb 27>; [100.00%]

  <bb 7> [local count: 521689471]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  res_31 = mdns_read_answer (pkt_28(D), &ans);
  # DEBUG res => res_31
  # DEBUG BEGIN_STMT
  if (res_31 != 0)
    goto <bb 8>; [5.50%]
  else
    goto <bb 9>; [94.50%]

  <bb 8> [local count: 28692921]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  ans ={v} {CLOBBER};
  goto <bb 28>; [100.00%]

  <bb 9> [local count: 492996550]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mdns_domain_debug_print (&ans.info.domain);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _5 = mdns_29->probing_state;
  if (_5 == 1)
    goto <bb 10>; [34.00%]
  else
    goto <bb 26>; [66.00%]

  <bb 10> [local count: 167618827]:
  _6 = mdns_29->probes_sent;
  if (_6 != 0)
    goto <bb 11>; [15.41%]
  else
    goto <bb 26>; [84.59%]

  <bb 11> [local count: 25830061]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG conflict => 0
  # DEBUG BEGIN_STMT
  res_33 = mdns_build_host_domain (&domain, mdns_29);
  # DEBUG res => res_33
  # DEBUG BEGIN_STMT
  if (res_33 == 0)
    goto <bb 12>; [33.00%]
  else
    goto <bb 14>; [67.00%]

  <bb 12> [local count: 8523920]:
  _7 = mdns_domain_eq (&ans.info.domain, &domain);
  if (_7 != 0)
    goto <bb 13>; [50.00%]
  else
    goto <bb 14>; [50.00%]

  <bb 13> [local count: 4261960]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG conflict => 1

  <bb 14> [local count: 25830061]:
  # i_17 = PHI <0(11), 0(12), 0(13)>
  # conflict_8 = PHI <0(11), 0(12), 1(13)>
  goto <bb 21>; [100.00%]

  <bb 15> [local count: 208988678]:
  # DEBUG BEGIN_STMT
  service_38 = mdns_29->services[0];
  # DEBUG service => service_38
  # DEBUG BEGIN_STMT
  if (service_38 == 0B)
    goto <bb 16>; [30.00%]
  else
    goto <bb 17>; [70.00%]

  <bb 16> [local count: 62696603]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by continue predictor.
  goto <bb 20>; [100.00%]

  <bb 17> [local count: 146292075]:
  # DEBUG BEGIN_STMT
  res_40 = mdns_build_service_domain (&domain, service_38, 1);
  # DEBUG res => res_40
  # DEBUG BEGIN_STMT
  if (res_40 == 0)
    goto <bb 18>; [33.00%]
  else
    goto <bb 20>; [67.00%]

  <bb 18> [local count: 48276385]:
  _9 = mdns_domain_eq (&ans.info.domain, &domain);
  if (_9 != 0)
    goto <bb 19>; [50.00%]
  else
    goto <bb 20>; [50.00%]

  <bb 19> [local count: 24138192]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG conflict => 1

  <bb 20> [local count: 208988678]:
  # i_20 = PHI <1(18), 1(17), 1(16), 1(19)>
  # conflict_16 = PHI <conflict_18(18), conflict_18(17), conflict_18(16), 1(19)>

  <bb 21> [local count: 234818740]:
  # i_15 = PHI <i_17(14), i_20(20)>
  # conflict_18 = PHI <conflict_8(14), conflict_16(20)>
  # DEBUG conflict => conflict_18
  # DEBUG i => i_15
  # DEBUG BEGIN_STMT
  if (i_15 == 0)
    goto <bb 15>; [89.00%]
  else
    goto <bb 22>; [11.00%]

  <bb 22> [local count: 25830061]:
  # conflict_12 = PHI <conflict_18(21)>
  # DEBUG BEGIN_STMT
  if (conflict_12 != 0)
    goto <bb 23>; [33.00%]
  else
    goto <bb 25>; [67.00%]

  <bb 23> [local count: 8523920]:
  # DEBUG BEGIN_STMT
  _10 = pkt_28(D)->netif;
  sys_untimeout (mdns_probe, _10);
  # DEBUG BEGIN_STMT
  mdns_name_result_cb.62_11 = mdns_name_result_cb;
  if (mdns_name_result_cb.62_11 != 0B)
    goto <bb 24>; [70.00%]
  else
    goto <bb 25>; [30.00%]

  <bb 24> [local count: 5966744]:
  # DEBUG BEGIN_STMT
  _13 = pkt_28(D)->netif;
  mdns_name_result_cb.62_11 (_13, 0);

  <bb 25> [local count: 25830061]:
  domain ={v} {CLOBBER};

  <bb 26> [local count: 492996550]:
  ans ={v} {CLOBBER};

  <bb 27> [local count: 552052351]:
  # DEBUG BEGIN_STMT
  _14 = pkt_28(D)->answers_left;
  if (_14 != 0)
    goto <bb 7>; [94.50%]
  else
    goto <bb 28>; [5.50%]

  <bb 28> [local count: 114863532]:
  return;

}



;; Function check_host.part.0 (check_host.part.0, funcdef_no=59, decl_uid=8741, cgraph_uid=90, symbol_order=99)

Modification phase of node check_host.part.0/99
Adjusting mask for param 1 to 0xfffffffc
Adjusting align: 4, misalign: 0
Setting nonnull for 1
Setting nonnull for 2
check_host.part.0 (struct netif * netif, struct mdns_rr_info * rr, u8_t * reverse_v6_reply)
{
  err_t res;
  int replies;
  struct mdns_domain mydomain;
  int i;
  short unsigned int _2;
  unsigned char _5;
  unsigned char _6;
  struct ip6_addr_t * _7;
  struct mdns_domain * _9;
  int _10;
  unsigned char _12;
  signed char _13;
  int _14;
  signed char _15;
  signed char _16;
  unsigned char _17;
  long unsigned int _19;
  struct ip4_addr_t * _20;
  struct mdns_domain * _22;
  int _23;
  unsigned char mdns_netif_client_id.75_26;
  int _27;
  void * _28;
  struct mdns_domain * _30;
  int _31;
  long unsigned int _32;
  short unsigned int _33;
  short unsigned int _36;
  int _39;

  <bb 26> [local count: 475612076]:

  <bb 2> [local count: 475612076]:
  # DEBUG BEGIN_STMT
  _2 = rr_1(D)->type;
  if (_2 == 12)
    goto <bb 3>; [34.00%]
  else
    goto <bb 4>; [66.00%]

  <bb 3> [local count: 268435456]:
  # replies_40 = PHI <0(2), 0(4)>
  # i_41 = PHI <0(2), 0(4)>
  goto <bb 11>; [100.00%]

  <bb 4> [local count: 313903970]:
  if (_2 == 255)
    goto <bb 3>; [34.00%]
  else
    goto <bb 16>; [66.00%]

  <bb 5> [local count: 805306368]:
  # DEBUG BEGIN_STMT
  _5 = netif_3(D)->ip6_addr_state[i_4];
  _6 = _5 & 16;
  if (_6 != 0)
    goto <bb 6>; [33.00%]
  else
    goto <bb 10>; [67.00%]

  <bb 6> [local count: 265751101]:
  # DEBUG BEGIN_STMT
  _7 = &netif_3(D)->ip6_addr[i_4].u_addr.ip6;
  res_8 = mdns_build_reverse_v6_domain (&mydomain, _7);
  # DEBUG res => res_8
  # DEBUG BEGIN_STMT
  if (res_8 == 0)
    goto <bb 7>; [33.00%]
  else
    goto <bb 10>; [67.00%]

  <bb 7> [local count: 87697863]:
  _9 = &rr_1(D)->domain;
  _10 = mdns_domain_eq (_9, &mydomain);
  if (_10 != 0)
    goto <bb 8>; [50.00%]
  else
    goto <bb 10>; [50.00%]

  <bb 8> [local count: 43848932]:
  # DEBUG BEGIN_STMT
  # DEBUG replies => 8
  # DEBUG BEGIN_STMT
  if (reverse_v6_reply_11(D) != 0B)
    goto <bb 9>; [70.00%]
  else
    goto <bb 10>; [30.00%]

  <bb 9> [local count: 30694252]:
  # DEBUG BEGIN_STMT
  _12 = *reverse_v6_reply_11(D);
  _13 = (signed char) _12;
  _14 = 1 << i_4;
  _15 = (signed char) _14;
  _16 = _13 | _15;
  _17 = (unsigned char) _16;
  *reverse_v6_reply_11(D) = _17;

  <bb 10> [local count: 805306368]:
  # replies_42 = PHI <replies_43(5), replies_43(6), replies_43(7), 8(8), 8(9)>
  # DEBUG replies => replies_42
  # DEBUG BEGIN_STMT
  i_18 = i_4 + 1;
  # DEBUG i => i_18

  <bb 11> [local count: 1073741824]:
  # replies_43 = PHI <replies_40(3), replies_42(10)>
  # i_4 = PHI <i_41(3), i_18(10)>
  # DEBUG i => i_4
  # DEBUG replies => replies_43
  # DEBUG BEGIN_STMT
  if (i_4 != 3)
    goto <bb 5>; [75.00%]
  else
    goto <bb 12>; [25.00%]

  <bb 12> [local count: 268435456]:
  # replies_24 = PHI <replies_43(11)>
  # DEBUG BEGIN_STMT
  _19 = MEM[(const struct ip4_addr_t *)netif_3(D) + 4B].addr;
  if (_19 != 0)
    goto <bb 13>; [33.00%]
  else
    goto <bb 16>; [67.00%]

  <bb 13> [local count: 88583701]:
  # DEBUG BEGIN_STMT
  _20 = &netif_3(D)->ip_addr.u_addr.ip4;
  res_21 = mdns_build_reverse_v4_domain (&mydomain, _20);
  # DEBUG res => res_21
  # DEBUG BEGIN_STMT
  if (res_21 == 0)
    goto <bb 14>; [33.00%]
  else
    goto <bb 16>; [67.00%]

  <bb 14> [local count: 29232621]:
  _22 = &rr_1(D)->domain;
  _23 = mdns_domain_eq (_22, &mydomain);
  if (_23 != 0)
    goto <bb 15>; [50.00%]
  else
    goto <bb 16>; [50.00%]

  <bb 15> [local count: 14616311]:
  # DEBUG BEGIN_STMT
  replies_25 = replies_24 | 2;
  # DEBUG replies => replies_25

  <bb 16> [local count: 475612077]:
  # replies_34 = PHI <0(4), replies_24(12), replies_24(13), replies_24(14), replies_25(15)>
  # DEBUG replies => replies_34
  # DEBUG BEGIN_STMT
  mdns_netif_client_id.75_26 = mdns_netif_client_id;
  _27 = (int) mdns_netif_client_id.75_26;
  _28 = netif_3(D)->client_data[_27];
  res_29 = mdns_build_host_domain (&mydomain, _28);
  # DEBUG res => res_29
  # DEBUG BEGIN_STMT
  if (res_29 == 0)
    goto <bb 17>; [33.00%]
  else
    goto <bb 25>; [67.00%]

  <bb 17> [local count: 156951985]:
  _30 = &rr_1(D)->domain;
  _31 = mdns_domain_eq (_30, &mydomain);
  if (_31 != 0)
    goto <bb 18>; [50.00%]
  else
    goto <bb 25>; [50.00%]

  <bb 18> [local count: 78475993]:
  # DEBUG BEGIN_STMT
  _32 = MEM[(const struct ip4_addr_t *)netif_3(D) + 4B].addr;
  if (_32 != 0)
    goto <bb 19>; [50.00%]
  else
    goto <bb 22>; [50.00%]

  <bb 19> [local count: 39237996]:
  _33 = rr_1(D)->type;
  if (_33 == 1)
    goto <bb 21>; [34.00%]
  else
    goto <bb 20>; [66.00%]

  <bb 20> [local count: 25897078]:
  if (_33 == 255)
    goto <bb 21>; [34.00%]
  else
    goto <bb 22>; [66.00%]

  <bb 21> [local count: 22145925]:
  # DEBUG BEGIN_STMT
  replies_35 = replies_34 | 1;
  # DEBUG replies => replies_35

  <bb 22> [local count: 78475993]:
  # replies_37 = PHI <replies_34(18), replies_34(20), replies_35(21)>
  # DEBUG replies => replies_37
  # DEBUG BEGIN_STMT
  _36 = rr_1(D)->type;
  if (_36 == 28)
    goto <bb 24>; [34.00%]
  else
    goto <bb 23>; [66.00%]

  <bb 23> [local count: 51794155]:
  if (_36 == 255)
    goto <bb 24>; [34.00%]
  else
    goto <bb 25>; [66.00%]

  <bb 24> [local count: 44291850]:
  # DEBUG BEGIN_STMT
  replies_38 = replies_37 | 4;
  # DEBUG replies => replies_38

  <bb 25> [local count: 475612077]:
  # _39 = PHI <replies_34(16), replies_34(17), replies_37(23), replies_38(24)>
  # DEBUG replies => NULL
  mydomain ={v} {CLOBBER};
  return _39;

}



;; Function check_service.part.0 (check_service.part.0, funcdef_no=60, decl_uid=8752, cgraph_uid=91, symbol_order=100)

Modification phase of node check_service.part.0/100
Adjusting mask for param 1 to 0xfffffffc
Adjusting align: 4, misalign: 0
Setting nonnull for 1
check_service.part.0 (struct mdns_service * service, struct mdns_rr_info * rr)
{
  err_t res;
  int replies;
  struct mdns_domain mydomain;
  struct mdns_domain * _3;
  int _4;
  short unsigned int _5;
  struct mdns_domain * _8;
  int _9;
  short unsigned int _10;
  struct mdns_domain * _14;
  int _15;
  short unsigned int _16;
  int _21;

  <bb 21> [local count: 1073741824]:

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  res_1 = mdns_build_dnssd_domain (&mydomain);
  # DEBUG res => res_1
  # DEBUG BEGIN_STMT
  if (res_1 == 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 7>; [67.00%]

  <bb 3> [local count: 354334802]:
  _3 = &rr_2(D)->domain;
  _4 = mdns_domain_eq (_3, &mydomain);
  if (_4 != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 4> [local count: 177167401]:
  _5 = rr_2(D)->type;
  if (_5 == 12)
    goto <bb 6>; [34.00%]
  else
    goto <bb 5>; [66.00%]

  <bb 5> [local count: 116930485]:
  if (_5 == 255)
    goto <bb 6>; [34.00%]
  else
    goto <bb 7>; [66.00%]

  <bb 6> [local count: 99993281]:
  # DEBUG BEGIN_STMT
  # DEBUG replies => 16

  <bb 7> [local count: 1073741824]:
  # replies_11 = PHI <0(2), 0(3), 0(5), 16(6)>
  # DEBUG replies => replies_11
  # DEBUG BEGIN_STMT
  res_7 = mdns_build_service_domain (&mydomain, service_6(D), 0);
  # DEBUG res => res_7
  # DEBUG BEGIN_STMT
  if (res_7 == 0)
    goto <bb 8>; [33.00%]
  else
    goto <bb 12>; [67.00%]

  <bb 8> [local count: 354334802]:
  _8 = &rr_2(D)->domain;
  _9 = mdns_domain_eq (_8, &mydomain);
  if (_9 != 0)
    goto <bb 9>; [50.00%]
  else
    goto <bb 12>; [50.00%]

  <bb 9> [local count: 177167401]:
  _10 = rr_2(D)->type;
  if (_10 == 12)
    goto <bb 11>; [34.00%]
  else
    goto <bb 10>; [66.00%]

  <bb 10> [local count: 116930485]:
  if (_10 == 255)
    goto <bb 11>; [34.00%]
  else
    goto <bb 12>; [66.00%]

  <bb 11> [local count: 99993281]:
  # DEBUG BEGIN_STMT
  replies_12 = replies_11 | 32;
  # DEBUG replies => replies_12

  <bb 12> [local count: 1073741824]:
  # replies_17 = PHI <replies_11(7), replies_11(8), replies_11(10), replies_12(11)>
  # DEBUG replies => replies_17
  # DEBUG BEGIN_STMT
  res_13 = mdns_build_service_domain (&mydomain, service_6(D), 1);
  # DEBUG res => res_13
  # DEBUG BEGIN_STMT
  if (res_13 == 0)
    goto <bb 13>; [33.00%]
  else
    goto <bb 20>; [67.00%]

  <bb 13> [local count: 354334802]:
  _14 = &rr_2(D)->domain;
  _15 = mdns_domain_eq (_14, &mydomain);
  if (_15 != 0)
    goto <bb 14>; [50.00%]
  else
    goto <bb 20>; [50.00%]

  <bb 14> [local count: 177167401]:
  # DEBUG BEGIN_STMT
  _16 = rr_2(D)->type;
  if (_16 == 33)
    goto <bb 16>; [34.00%]
  else
    goto <bb 15>; [66.00%]

  <bb 15> [local count: 116930485]:
  if (_16 == 255)
    goto <bb 16>; [34.00%]
  else
    goto <bb 17>; [66.00%]

  <bb 16> [local count: 99993281]:
  # DEBUG BEGIN_STMT
  replies_18 = replies_17 | 64;
  # DEBUG replies => replies_18

  <bb 17> [local count: 177167401]:
  # replies_19 = PHI <replies_17(15), replies_18(16)>
  # DEBUG replies => replies_19
  # DEBUG BEGIN_STMT
  if (_16 == 16)
    goto <bb 19>; [34.00%]
  else
    goto <bb 18>; [66.00%]

  <bb 18> [local count: 116930485]:
  if (_16 == 255)
    goto <bb 19>; [34.00%]
  else
    goto <bb 20>; [66.00%]

  <bb 19> [local count: 99993281]:
  # DEBUG BEGIN_STMT
  replies_20 = replies_19 | 128;
  # DEBUG replies => replies_20

  <bb 20> [local count: 1073741824]:
  # _21 = PHI <replies_17(12), replies_17(13), replies_19(18), replies_20(19)>
  # DEBUG replies => NULL
  mydomain ={v} {CLOBBER};
  return _21;

}



;; Function mdns_compress_domain (mdns_compress_domain, funcdef_no=17, decl_uid=6874, cgraph_uid=18, symbol_order=23)

Modification phase of node mdns_compress_domain/23
mdns_compress_domain (struct pbuf * pbuf, u16_t * offset, struct mdns_domain * domain)
{
  short unsigned int _1;
  u16_t _4;
  u16_t _9;

  <bb 2> [local count: 106070372]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG writelen => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pbuf_5(D) == 0B)
    goto <bb 3>; [30.95%]
  else
    goto <bb 4>; [69.05%]

  <bb 3> [local count: 32828780]:
  # DEBUG BEGIN_STMT
  _9 = domain_8(D)->length;
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 73241592]:
  _1 = mdns_compress_domain.part.0 (pbuf_5(D), offset_7(D), domain_8(D));

  <bb 5> [local count: 106070373]:
  # _4 = PHI <_9(3), _1(4)>
  return _4;

}



;; Function mdns_write_domain (mdns_write_domain, funcdef_no=18, decl_uid=7524, cgraph_uid=19, symbol_order=24)

Modification phase of node mdns_write_domain/24
Adjusting mask for param 0 to 0xfffffffc
Adjusting align: 4, misalign: 0
Adjusting mask for param 1 to 0xfffffffc
Adjusting align: 4, misalign: 0
Setting nonnull for 0
mdns_write_domain (struct mdns_outpacket * outpkt, struct mdns_domain * domain)
{
  u16_t len;
  u16_t offset;
  u16_t jump;
  u16_t jump_offset;
  u16_t writelen;
  err_t res;
  int i;
  unsigned char _1;
  short unsigned int _2;
  struct pbuf * _4;
  struct pbuf * _5;
  u8_t[256] * _6;
  short unsigned int _7;
  short unsigned int _8;
  short unsigned int _9;
  short unsigned int _10;
  short unsigned int _11;
  short unsigned int _12;
  short unsigned int _13;
  struct pbuf * _14;
  short unsigned int _15;
  short unsigned int _16;
  short unsigned int _17;
  err_t _26;

  <bb 2> [local count: 195206264]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  writelen_35 = domain_34(D)->length;
  # DEBUG writelen => writelen_35
  # DEBUG BEGIN_STMT
  # DEBUG jump_offset => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = domain_34(D)->skip_compression;
  if (_1 == 0)
    goto <bb 20>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 20> [local count: 97603132]:
  goto <bb 7>; [100.00%]

  <bb 3> [local count: 976138694]:
  # DEBUG BEGIN_STMT
  _2 = outpkt_36(D)->domain_offsets[i_18];
  offset = _2;
  # DEBUG BEGIN_STMT
  if (_2 != 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 6>; [67.00%]

  <bb 4> [local count: 322125769]:
  # DEBUG BEGIN_STMT
  _4 = outpkt_36(D)->pbuf;
  len_39 = mdns_compress_domain (_4, &offset, domain_34(D));
  # DEBUG len => len_39
  # DEBUG BEGIN_STMT
  if (writelen_21 > len_39)
    goto <bb 5>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 5> [local count: 161062884]:
  # DEBUG BEGIN_STMT
  # DEBUG writelen => len_39
  # DEBUG BEGIN_STMT
  jump_offset_40 = offset;
  # DEBUG jump_offset => jump_offset_40

  <bb 6> [local count: 976138694]:
  # writelen_20 = PHI <writelen_21(3), writelen_21(4), len_39(5)>
  # jump_offset_23 = PHI <jump_offset_24(3), jump_offset_24(4), jump_offset_40(5)>
  # DEBUG jump_offset => jump_offset_23
  # DEBUG writelen => writelen_20
  offset ={v} {CLOBBER};
  # DEBUG BEGIN_STMT
  i_42 = i_18 + 1;
  # DEBUG i => i_42

  <bb 7> [local count: 1073741824]:
  # i_18 = PHI <i_42(6), 0(20)>
  # writelen_21 = PHI <writelen_20(6), writelen_35(20)>
  # jump_offset_24 = PHI <jump_offset_23(6), 0(20)>
  # DEBUG jump_offset => jump_offset_24
  # DEBUG writelen => writelen_21
  # DEBUG i => i_18
  # DEBUG BEGIN_STMT
  if (i_18 != 10)
    goto <bb 3>; [90.91%]
  else
    goto <bb 8>; [9.09%]

  <bb 8> [local count: 195206264]:
  # writelen_22 = PHI <writelen_35(2), writelen_21(7)>
  # jump_offset_25 = PHI <0(2), jump_offset_24(7)>
  # DEBUG jump_offset => jump_offset_25
  # DEBUG writelen => writelen_22
  # DEBUG BEGIN_STMT
  if (writelen_22 != 0)
    goto <bb 9>; [33.00%]
  else
    goto <bb 15>; [67.00%]

  <bb 9> [local count: 64418067]:
  # DEBUG BEGIN_STMT
  _5 = outpkt_36(D)->pbuf;
  _6 = &domain_34(D)->name;
  _7 = outpkt_36(D)->write_offset;
  res_44 = pbuf_take_at (_5, _6, writelen_22, _7);
  # DEBUG res => res_44
  # DEBUG BEGIN_STMT
  if (res_44 != 0)
    goto <bb 18>; [34.00%]
  else
    goto <bb 19>; [66.00%]

  <bb 19> [local count: 42515924]:
  goto <bb 13>; [100.00%]

  <bb 10> [local count: 274315752]:
  # DEBUG BEGIN_STMT
  _8 = outpkt_36(D)->domain_offsets[i_19];
  if (_8 == 0)
    goto <bb 11>; [5.50%]
  else
    goto <bb 12>; [94.50%]

  <bb 11> [local count: 15087366]:
  # i_3 = PHI <i_19(10)>
  # DEBUG BEGIN_STMT
  _9 = outpkt_36(D)->write_offset;
  outpkt_36(D)->domain_offsets[i_3] = _9;
  # DEBUG BEGIN_STMT
  goto <bb 14>; [100.00%]

  <bb 12> [local count: 259228386]:
  # DEBUG BEGIN_STMT
  i_45 = i_19 + 1;
  # DEBUG i => i_45

  <bb 13> [local count: 301744310]:
  # i_19 = PHI <i_45(12), 0(19)>
  # DEBUG i => i_19
  # DEBUG BEGIN_STMT
  if (i_19 != 10)
    goto <bb 10>; [90.91%]
  else
    goto <bb 14>; [9.09%]

  <bb 14> [local count: 42515924]:
  # DEBUG BEGIN_STMT
  _10 = outpkt_36(D)->write_offset;
  _11 = _10 + writelen_22;
  outpkt_36(D)->write_offset = _11;

  <bb 15> [local count: 173304121]:
  # DEBUG BEGIN_STMT
  if (jump_offset_25 != 0)
    goto <bb 16>; [33.00%]
  else
    goto <bb 18>; [67.00%]

  <bb 16> [local count: 57190360]:
  # DEBUG BEGIN_STMT
  _12 = jump_offset_25 | 49152;
  _13 = lwip_htons (_12);
  jump = _13;
  # DEBUG BEGIN_STMT
  _14 = outpkt_36(D)->pbuf;
  _15 = outpkt_36(D)->write_offset;
  res_51 = pbuf_take_at (_14, &jump, 2, _15);
  # DEBUG res => res_51
  # DEBUG BEGIN_STMT
  if (res_51 != 0)
    goto <bb 18>; [34.00%]
  else
    goto <bb 17>; [66.00%]

  <bb 17> [local count: 37745638]:
  # DEBUG BEGIN_STMT
  _16 = outpkt_36(D)->write_offset;
  _17 = _16 + 2;
  outpkt_36(D)->write_offset = _17;

  <bb 18> [local count: 195206264]:
  # _26 = PHI <res_44(9), res_51(16), 0(17), 0(15)>
  jump ={v} {CLOBBER};
  return _26;

}



;; Function mdns_add_question (mdns_add_question, funcdef_no=19, decl_uid=7544, cgraph_uid=20, symbol_order=25)

Modification phase of node mdns_add_question/25
Adjusting mask for param 0 to 0xfffffffc
Adjusting align: 4, misalign: 0
Adjusting mask for param 1 to 0xfffffffc
Adjusting align: 4, misalign: 0
Adjusting mask for param 4 to 0xff
Setting nonnull for 0
Setting nonnull for 1
Setting value range of param 4 [0, 255]
mdns_add_question (struct mdns_outpacket * outpkt, struct mdns_domain * domain, u16_t type, u16_t klass, u16_t unicast)
{
  err_t res;
  u16_t question_len;
  struct pbuf * _1;
  struct pbuf * _2;
  signed char _3;
  short unsigned int _4;
  short unsigned int _5;
  int _6;
  int _7;
  int _8;
  struct pbuf * _9;
  short unsigned int _10;
  int _11;
  err_t _12;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = outpkt_15(D)->pbuf;
  if (_1 == 0B)
    goto <bb 3>; [17.43%]
  else
    goto <bb 5>; [82.57%]

  <bb 3> [local count: 187153200]:
  # DEBUG BEGIN_STMT
  _2 = pbuf_alloc (74, 500, 640);
  outpkt_15(D)->pbuf = _2;
  # DEBUG BEGIN_STMT
  if (_2 == 0B)
    goto <bb 8>; [0.45%]
  else
    goto <bb 4>; [99.55%]

  <bb 4> [local count: 186311011]:
  # DEBUG BEGIN_STMT
  outpkt_15(D)->write_offset = 12;

  <bb 5> [local count: 1072899636]:
  # DEBUG BEGIN_STMT
  _4 = domain_20(D)->length;
  question_len_21 = _4 + 4;
  # DEBUG question_len => question_len_21
  # DEBUG BEGIN_STMT
  _5 = outpkt_15(D)->write_offset;
  _6 = (int) _5;
  _7 = (int) question_len_21;
  _8 = _6 + _7;
  _9 = outpkt_15(D)->pbuf;
  _10 = _9->tot_len;
  _11 = (int) _10;
  if (_8 > _11)
    goto <bb 8>; [2.09%]
  else
    goto <bb 6>; [97.91%]

  <bb 6> [local count: 1050476034]:
  # DEBUG BEGIN_STMT
  res_23 = mdns_write_domain (outpkt_15(D), domain_20(D));
  # DEBUG res => res_23
  # DEBUG BEGIN_STMT
  if (res_23 != 0)
    goto <bb 8>; [51.12%]
  else
    goto <bb 7>; [48.88%]

  <bb 7> [local count: 513472682]:
  # DEBUG D#9 => domain_20(D)
  _3 = mdns_add_question.part.0 (outpkt_15(D), type_24(D), klass_26(D), unicast_25(D));

  <bb 8> [local count: 1073741824]:
  # _12 = PHI <-1(3), -1(5), res_23(6), _3(7)>
  return _12;

}



;; Function mdns_add_answer.constprop (mdns_add_answer.constprop.0, funcdef_no=65, decl_uid=8825, cgraph_uid=96, symbol_order=105)

Modification phase of node mdns_add_answer.constprop/105
Adjusting mask for param 0 to 0xfffffffc
Adjusting align: 4, misalign: 0
Adjusting mask for param 1 to 0xfffffffc
Adjusting align: 4, misalign: 0
Adjusting mask for param 2 to 0x3d
Adjusting mask for param 4 to 0xff
Adjusting mask for param 7 to 0xffff
Adjusting mask for param 8 to 0xfffffffc
Adjusting align: 4, misalign: 0
Setting nonnull for 0
Setting nonnull for 1
Setting value range of param 2 [1, 33]
Setting value range of param 4 [0, 255]
Setting value range of param 7 [0, 65535]
mdns_add_answer.constprop (struct mdns_outpacket * reply, struct mdns_domain * domain, u16_t type, u16_t cache_flush, u32_t ttl, const u8_t * buf, size_t buf_length, struct mdns_domain * answer_domain)
{
  u16_t answer_len;
  u16_t field16;
  u32_t field32;
  err_t res;
  u16_t klass;
  struct pbuf * _2;
  struct pbuf * _3;
  short unsigned int _5;
  short unsigned int _9;
  short unsigned int _12;
  short unsigned int _15;
  int _16;
  int _18;
  int _19;
  struct pbuf * _20;
  short unsigned int _21;
  int _22;
  long unsigned int _26;
  struct pbuf * _27;
  short unsigned int _28;
  short unsigned int _30;
  short unsigned int _31;
  short unsigned int _32;
  struct pbuf * _33;
  short unsigned int _34;
  short unsigned int _36;
  short unsigned int _37;
  short unsigned int _39;
  short unsigned int _40;
  short unsigned int _41;
  struct pbuf * _42;
  signed char _44;

  <bb 18> [local count: 1073741824]:
  # DEBUG klass => 1

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = reply_1(D)->pbuf;
  if (_2 == 0B)
    goto <bb 3>; [17.43%]
  else
    goto <bb 5>; [82.57%]

  <bb 3> [local count: 187153200]:
  # DEBUG BEGIN_STMT
  _3 = pbuf_alloc (74, 500, 640);
  reply_1(D)->pbuf = _3;
  # DEBUG BEGIN_STMT
  if (_3 == 0B)
    goto <bb 17>; [0.45%]
  else
    goto <bb 4>; [99.55%]

  <bb 4> [local count: 186311011]:
  # DEBUG BEGIN_STMT
  reply_1(D)->write_offset = 12;

  <bb 5> [local count: 1072899636]:
  # DEBUG BEGIN_STMT
  _5 = domain_4(D)->length;
  answer_len_6 = _5 + 10;
  # DEBUG answer_len => answer_len_6
  # DEBUG BEGIN_STMT
  if (buf_7(D) != 0B)
    goto <bb 6>; [70.00%]
  else
    goto <bb 7>; [30.00%]

  <bb 6> [local count: 751029745]:
  # DEBUG BEGIN_STMT
  _9 = (short unsigned int) buf_length_8(D);
  answer_len_10 = answer_len_6 + _9;
  # DEBUG answer_len => answer_len_10

  <bb 7> [local count: 1072899635]:
  # answer_len_13 = PHI <answer_len_6(5), answer_len_10(6)>
  # DEBUG answer_len => answer_len_13
  # DEBUG BEGIN_STMT
  if (answer_domain_11(D) != 0B)
    goto <bb 8>; [70.00%]
  else
    goto <bb 9>; [30.00%]

  <bb 8> [local count: 751029744]:
  # DEBUG BEGIN_STMT
  _12 = answer_domain_11(D)->length;
  answer_len_14 = _12 + answer_len_13;
  # DEBUG answer_len => answer_len_14

  <bb 9> [local count: 1072899635]:
  # answer_len_17 = PHI <answer_len_13(7), answer_len_14(8)>
  # DEBUG answer_len => answer_len_17
  # DEBUG BEGIN_STMT
  _15 = reply_1(D)->write_offset;
  _16 = (int) _15;
  _18 = (int) answer_len_17;
  _19 = _16 + _18;
  _20 = reply_1(D)->pbuf;
  _21 = _20->tot_len;
  _22 = (int) _21;
  if (_19 > _22)
    goto <bb 17>; [2.09%]
  else
    goto <bb 10>; [97.91%]

  <bb 10> [local count: 1050476032]:
  # DEBUG BEGIN_STMT
  mdns_add_question (reply_1(D), domain_4(D), type_23(D), 1, cache_flush_24(D));
  # DEBUG BEGIN_STMT
  _26 = lwip_htonl (ttl_25(D));
  field32 = _26;
  # DEBUG BEGIN_STMT
  _27 = reply_1(D)->pbuf;
  _28 = reply_1(D)->write_offset;
  res_29 = pbuf_take_at (_27, &field32, 4, _28);
  # DEBUG res => res_29
  # DEBUG BEGIN_STMT
  if (res_29 != 0)
    goto <bb 17>; [34.00%]
  else
    goto <bb 11>; [66.00%]

  <bb 11> [local count: 693314182]:
  # DEBUG BEGIN_STMT
  _30 = reply_1(D)->write_offset;
  _31 = _30 + 4;
  # DEBUG BEGIN_STMT
  # DEBUG rdlen_offset => _31
  # DEBUG BEGIN_STMT
  _32 = _31 + 2;
  reply_1(D)->write_offset = _32;
  # DEBUG BEGIN_STMT
  # DEBUG answer_offset => _32
  # DEBUG BEGIN_STMT
  if (buf_7(D) != 0B)
    goto <bb 12>; [53.47%]
  else
    goto <bb 14>; [46.53%]

  <bb 12> [local count: 370715093]:
  # DEBUG BEGIN_STMT
  _33 = reply_1(D)->pbuf;
  _34 = (short unsigned int) buf_length_8(D);
  res_35 = pbuf_take_at (_33, buf_7(D), _34, _32);
  # DEBUG res => res_35
  # DEBUG BEGIN_STMT
  if (res_35 != 0)
    goto <bb 17>; [34.00%]
  else
    goto <bb 13>; [66.00%]

  <bb 13> [local count: 244671961]:
  # DEBUG BEGIN_STMT
  _36 = reply_1(D)->write_offset;
  _37 = _34 + _36;
  reply_1(D)->write_offset = _37;

  <bb 14> [local count: 567271051]:
  # DEBUG BEGIN_STMT
  if (answer_domain_11(D) != 0B)
    goto <bb 15>; [70.00%]
  else
    goto <bb 16>; [30.00%]

  <bb 15> [local count: 397089735]:
  # DEBUG BEGIN_STMT
  res_38 = mdns_write_domain (reply_1(D), answer_domain_11(D));
  # DEBUG res => res_38
  # DEBUG BEGIN_STMT
  if (res_38 != 0)
    goto <bb 17>; [34.00%]
  else
    goto <bb 16>; [66.00%]

  <bb 16> [local count: 432260540]:
  # DEBUG BEGIN_STMT
  _39 = reply_1(D)->write_offset;
  _40 = _39 - _32;
  _41 = lwip_htons (_40);
  field16 = _41;
  # DEBUG BEGIN_STMT
  _42 = reply_1(D)->pbuf;
  res_43 = pbuf_take_at (_42, &field16, 2, _31);
  # DEBUG res => res_43
  # DEBUG BEGIN_STMT

  <bb 17> [local count: 1073741824]:
  # _44 = PHI <-1(3), -1(9), res_29(10), res_35(12), res_38(15), res_43(16)>
  field16 ={v} {CLOBBER};
  field32 ={v} {CLOBBER};
  return _44;

}



;; Function mdns_add_a_answer (mdns_add_a_answer, funcdef_no=24, decl_uid=7588, cgraph_uid=25, symbol_order=30)

Modification phase of node mdns_add_a_answer/30
Adjusting mask for param 0 to 0xfffffffc
Adjusting align: 4, misalign: 0
Adjusting mask for param 1 to 0xff
Setting nonnull for 0
Setting value range of param 1 [0, 255]
mdns_add_a_answer (struct mdns_outpacket * reply, u16_t cache_flush, struct netif * netif)
{
  struct mdns_domain host;
  unsigned char mdns_netif_client_id.36_1;
  int _2;
  void * _3;
  unsigned char mdns_netif_client_id.37_4;
  int _5;
  void * _6;
  long unsigned int _7;
  struct ip4_addr_t * _8;
  err_t _15;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mdns_netif_client_id.36_1 = mdns_netif_client_id;
  _2 = (int) mdns_netif_client_id.36_1;
  _3 = netif_10(D)->client_data[_2];
  mdns_build_host_domain (&host, _3);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mdns_netif_client_id.37_4 = mdns_netif_client_id;
  _5 = (int) mdns_netif_client_id.37_4;
  _6 = netif_10(D)->client_data[_5];
  _7 = MEM[(struct mdns_host *)_6].dns_ttl;
  _8 = &netif_10(D)->ip_addr.u_addr.ip4;
  _15 = mdns_add_answer (reply_12(D), &host, 1, 1, cache_flush_13(D), _7, _8, 4, 0B);
  host ={v} {CLOBBER};
  return _15;

}



;; Function mdns_add_aaaa_answer (mdns_add_aaaa_answer, funcdef_no=26, decl_uid=7602, cgraph_uid=27, symbol_order=32)

Modification phase of node mdns_add_aaaa_answer/32
Adjusting mask for param 0 to 0xfffffffc
Adjusting align: 4, misalign: 0
Adjusting mask for param 1 to 0xff
Adjusting mask for param 3 to 0x3
Setting nonnull for 0
Setting value range of param 1 [0, 255]
Setting value range of param 3 [0, 3]
mdns_add_aaaa_answer (struct mdns_outpacket * reply, u16_t cache_flush, struct netif * netif, int addrindex)
{
  struct mdns_domain host;
  unsigned char mdns_netif_client_id.34_1;
  int _2;
  void * _3;
  unsigned char mdns_netif_client_id.35_4;
  int _5;
  void * _6;
  long unsigned int _7;
  struct ip6_addr_t * _8;
  err_t _16;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mdns_netif_client_id.34_1 = mdns_netif_client_id;
  _2 = (int) mdns_netif_client_id.34_1;
  _3 = netif_10(D)->client_data[_2];
  mdns_build_host_domain (&host, _3);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mdns_netif_client_id.35_4 = mdns_netif_client_id;
  _5 = (int) mdns_netif_client_id.35_4;
  _6 = netif_10(D)->client_data[_5];
  _7 = MEM[(struct mdns_host *)_6].dns_ttl;
  _8 = &netif_10(D)->ip6_addr[addrindex_12(D)].u_addr.ip6;
  _16 = mdns_add_answer (reply_13(D), &host, 28, 1, cache_flush_14(D), _7, _8, 16, 0B);
  host ={v} {CLOBBER};
  return _16;

}



;; Function mdns_add_txt_answer (mdns_add_txt_answer, funcdef_no=31, decl_uid=7637, cgraph_uid=32, symbol_order=37)

Modification phase of node mdns_add_txt_answer/37
Adjusting mask for param 0 to 0xfffffffc
Adjusting align: 4, misalign: 0
Adjusting mask for param 1 to 0xff
Setting nonnull for 0
Setting value range of param 1 [0, 255]
mdns_add_txt_answer (struct mdns_outpacket * reply, u16_t cache_flush, struct mdns_service * service)
{
  struct mdns_domain service_instance;
  long unsigned int _1;
  u8_t[256] * _2;
  short unsigned int _3;
  unsigned int _4;
  err_t _12;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mdns_build_service_domain (&service_instance, service_6(D), 1);
  # DEBUG BEGIN_STMT
  mdns_prepare_txtdata (service_6(D));
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = service_6(D)->dns_ttl;
  _2 = &service_6(D)->txtdata.name;
  _3 = service_6(D)->txtdata.length;
  _4 = (unsigned int) _3;
  _12 = mdns_add_answer (reply_9(D), &service_instance, 16, 1, cache_flush_10(D), _1, _2, _4, 0B);
  service_instance ={v} {CLOBBER};
  return _12;

}



;; Function mdns_add_srv_answer (mdns_add_srv_answer, funcdef_no=30, decl_uid=7629, cgraph_uid=31, symbol_order=36)

Modification phase of node mdns_add_srv_answer/36
Adjusting mask for param 0 to 0xfffffffc
Adjusting align: 4, misalign: 0
Adjusting mask for param 1 to 0xff
Setting nonnull for 0
Setting value range of param 1 [0, 255]
mdns_add_srv_answer (struct mdns_outpacket * reply, u16_t cache_flush, struct mdns_host * mdns, struct mdns_service * service)
{
  u16_t srvdata[3];
  struct mdns_domain srvhost;
  struct mdns_domain service_instance;
  unsigned char _1;
  short unsigned int _2;
  short unsigned int _3;
  short unsigned int _4;
  short unsigned int _5;
  long unsigned int _6;
  err_t _23;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mdns_build_service_domain (&service_instance, service_9(D), 1);
  # DEBUG BEGIN_STMT
  mdns_build_host_domain (&srvhost, mdns_11(D));
  # DEBUG BEGIN_STMT
  _1 = reply_13(D)->legacy_query;
  if (_1 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  srvhost.skip_compression = 1;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _2 = lwip_htons (0);
  srvdata[0] = _2;
  # DEBUG BEGIN_STMT
  _3 = lwip_htons (0);
  srvdata[1] = _3;
  # DEBUG BEGIN_STMT
  _4 = service_9(D)->port;
  _5 = lwip_htons (_4);
  srvdata[2] = _5;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _6 = service_9(D)->dns_ttl;
  _23 = mdns_add_answer (reply_13(D), &service_instance, 33, 1, cache_flush_21(D), _6, &srvdata, 6, &srvhost);
  service_instance ={v} {CLOBBER};
  srvhost ={v} {CLOBBER};
  srvdata ={v} {CLOBBER};
  return _23;

}



;; Function mdns_add_servicename_ptr_answer (mdns_add_servicename_ptr_answer, funcdef_no=29, decl_uid=7621, cgraph_uid=30, symbol_order=35)

Modification phase of node mdns_add_servicename_ptr_answer/35
Adjusting mask for param 0 to 0xfffffffc
Adjusting align: 4, misalign: 0
Setting nonnull for 0
mdns_add_servicename_ptr_answer (struct mdns_outpacket * reply, struct mdns_service * service)
{
  struct mdns_domain service_instance;
  struct mdns_domain service_type;
  long unsigned int _1;
  err_t _8;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mdns_build_service_domain (&service_type, service_3(D), 0);
  # DEBUG BEGIN_STMT
  mdns_build_service_domain (&service_instance, service_3(D), 1);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = service_3(D)->dns_ttl;
  _8 = mdns_add_answer (reply_6(D), &service_type, 12, 1, 0, _1, 0B, 0, &service_instance);
  service_type ={v} {CLOBBER};
  service_instance ={v} {CLOBBER};
  return _8;

}



;; Function mdns_add_servicetype_ptr_answer (mdns_add_servicetype_ptr_answer, funcdef_no=28, decl_uid=7615, cgraph_uid=29, symbol_order=34)

Modification phase of node mdns_add_servicetype_ptr_answer/34
Adjusting mask for param 0 to 0xfffffffc
Adjusting align: 4, misalign: 0
Setting nonnull for 0
mdns_add_servicetype_ptr_answer (struct mdns_outpacket * reply, struct mdns_service * service)
{
  struct mdns_domain service_dnssd;
  struct mdns_domain service_type;
  long unsigned int _1;
  err_t _8;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mdns_build_service_domain (&service_type, service_3(D), 0);
  # DEBUG BEGIN_STMT
  mdns_build_dnssd_domain (&service_dnssd);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = service_3(D)->dns_ttl;
  _8 = mdns_add_answer (reply_6(D), &service_dnssd, 12, 1, 0, _1, 0B, 0, &service_type);
  service_type ={v} {CLOBBER};
  service_dnssd ={v} {CLOBBER};
  return _8;

}



;; Function mdns_add_hostv6_ptr_answer (mdns_add_hostv6_ptr_answer, funcdef_no=27, decl_uid=7609, cgraph_uid=28, symbol_order=33)

Modification phase of node mdns_add_hostv6_ptr_answer/33
Adjusting mask for param 0 to 0xfffffffc
Adjusting align: 4, misalign: 0
Adjusting mask for param 1 to 0xff
Adjusting mask for param 3 to 0x7fffffff
Setting nonnull for 0
Setting value range of param 1 [0, 255]
Setting value range of param 3 [0, 2147483647]
mdns_add_hostv6_ptr_answer (struct mdns_outpacket * reply, u16_t cache_flush, struct netif * netif, int addrindex)
{
  struct mdns_domain revhost;
  struct mdns_domain host;
  unsigned char mdns_netif_client_id.31_1;
  int _2;
  void * _3;
  struct ip6_addr_t * _4;
  unsigned char mdns_netif_client_id.32_5;
  int _6;
  void * _7;
  long unsigned int _8;
  err_t _17;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mdns_netif_client_id.31_1 = mdns_netif_client_id;
  _2 = (int) mdns_netif_client_id.31_1;
  _3 = netif_10(D)->client_data[_2];
  mdns_build_host_domain (&host, _3);
  # DEBUG BEGIN_STMT
  _4 = &netif_10(D)->ip6_addr[addrindex_12(D)].u_addr.ip6;
  mdns_build_reverse_v6_domain (&revhost, _4);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mdns_netif_client_id.32_5 = mdns_netif_client_id;
  _6 = (int) mdns_netif_client_id.32_5;
  _7 = netif_10(D)->client_data[_6];
  _8 = MEM[(struct mdns_host *)_7].dns_ttl;
  _17 = mdns_add_answer (reply_14(D), &revhost, 12, 1, cache_flush_15(D), _8, 0B, 0, &host);
  host ={v} {CLOBBER};
  revhost ={v} {CLOBBER};
  return _17;

}



;; Function mdns_add_hostv4_ptr_answer (mdns_add_hostv4_ptr_answer, funcdef_no=25, decl_uid=7594, cgraph_uid=26, symbol_order=31)

Modification phase of node mdns_add_hostv4_ptr_answer/31
Adjusting mask for param 0 to 0xfffffffc
Adjusting align: 4, misalign: 0
Adjusting mask for param 1 to 0xff
Setting nonnull for 0
Setting value range of param 1 [0, 255]
mdns_add_hostv4_ptr_answer (struct mdns_outpacket * reply, u16_t cache_flush, struct netif * netif)
{
  struct mdns_domain revhost;
  struct mdns_domain host;
  unsigned char mdns_netif_client_id.28_1;
  int _2;
  void * _3;
  struct ip4_addr_t * _4;
  unsigned char mdns_netif_client_id.29_5;
  int _6;
  void * _7;
  long unsigned int _8;
  err_t _16;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mdns_netif_client_id.28_1 = mdns_netif_client_id;
  _2 = (int) mdns_netif_client_id.28_1;
  _3 = netif_10(D)->client_data[_2];
  mdns_build_host_domain (&host, _3);
  # DEBUG BEGIN_STMT
  _4 = &netif_10(D)->ip_addr.u_addr.ip4;
  mdns_build_reverse_v4_domain (&revhost, _4);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mdns_netif_client_id.29_5 = mdns_netif_client_id;
  _6 = (int) mdns_netif_client_id.29_5;
  _7 = netif_10(D)->client_data[_6];
  _8 = MEM[(struct mdns_host *)_7].dns_ttl;
  _16 = mdns_add_answer (reply_13(D), &revhost, 12, 1, cache_flush_14(D), _8, 0B, 0, &host);
  host ={v} {CLOBBER};
  revhost ={v} {CLOBBER};
  return _16;

}



;; Function mdns_send_outpacket (mdns_send_outpacket, funcdef_no=33, decl_uid=7377, cgraph_uid=34, symbol_order=39)

Modification phase of node mdns_send_outpacket/39
Adjusting mask for param 0 to 0xfffffffc
Adjusting align: 4, misalign: 0
Adjusting mask for param 1 to 0x84
Setting nonnull for 0
Setting value range of param 1 [0, -124]
mdns_send_outpacket (struct mdns_outpacket * outpkt, u8_t flags)
{
  struct dns_hdr hdr;
  const struct ip_addr_t * mcast_destaddr;
  int addrindex;
  int addrindex;
  u8_t rev_addrs;
  int addrindex;
  u16_t answers;
  struct mdns_host * mdns;
  int i;
  err_t res;
  struct mdns_service * service;
  struct netif * _1;
  unsigned char mdns_netif_client_id.16_2;
  int _3;
  unsigned char _4;
  unsigned char _5;
  short unsigned int _6;
  unsigned char _8;
  unsigned char _9;
  unsigned char _10;
  short unsigned int _11;
  struct netif * _12;
  unsigned char _14;
  struct netif * _15;
  unsigned char _16;
  unsigned char _17;
  short unsigned int _18;
  unsigned char _21;
  unsigned char _22;
  short unsigned int _23;
  struct netif * _24;
  unsigned char _26;
  unsigned char _28;
  unsigned char _30;
  unsigned char _31;
  short unsigned int _32;
  unsigned char _34;
  signed char _35;
  unsigned char _36;
  short unsigned int _37;
  signed char flags.25_39;
  short unsigned int _40;
  short unsigned int _41;
  short unsigned int _42;
  short unsigned int _43;
  unsigned char _44;
  unsigned char _47;
  short unsigned int _48;
  short unsigned int _49;
  unsigned char _50;
  short unsigned int _51;
  unsigned char _52;
  signed char _53;
  unsigned char _54;
  short unsigned int _55;
  short unsigned int _56;
  unsigned char _57;
  short unsigned int _58;
  unsigned char _59;
  unsigned char _60;
  unsigned char _61;
  struct netif * _62;
  unsigned char _63;
  unsigned char _64;
  short unsigned int _65;
  short unsigned int _67;
  unsigned char _68;
  short unsigned int _69;
  unsigned char _70;
  struct netif * _71;
  long unsigned int _73;
  unsigned char _74;
  short unsigned int _75;
  short unsigned int _77;
  unsigned char _78;
  short unsigned int _79;
  struct pbuf * _80;
  short unsigned int _81;
  short unsigned int _82;
  short unsigned int _83;
  short unsigned int _84;
  short unsigned int _85;
  short unsigned int _86;
  short unsigned int _87;
  short unsigned int _88;
  short unsigned int _89;
  short unsigned int _90;
  struct pbuf * _91;
  struct pbuf * _92;
  short unsigned int _93;
  unsigned char _94;
  unsigned char _95;
  struct udp_pcb * mdns_pcb.26_96;
  struct pbuf * _97;
  struct ip_addr_t * _98;
  short unsigned int _99;
  struct netif * _100;
  struct udp_pcb * mdns_pcb.27_101;
  struct pbuf * _102;
  struct netif * _103;
  struct pbuf * _104;
  unsigned char _172;
  unsigned char _176;
  unsigned char _179;
  unsigned char _183;
  unsigned char _189;
  unsigned char _195;
  unsigned char _199;
  unsigned char _214;
  unsigned char _215;
  unsigned char _228;
  unsigned char _253;

  <bb 2> [local count: 69659470]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG res => -16
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = outpkt_174(D)->netif;
  mdns_netif_client_id.16_2 = mdns_netif_client_id;
  _3 = (int) mdns_netif_client_id.16_2;
  mdns_175 = _1->client_data[_3];
  # DEBUG mdns => mdns_175
  # DEBUG BEGIN_STMT
  # DEBUG answers => 0
  # DEBUG BEGIN_STMT
  _4 = outpkt_174(D)->host_replies;
  _172 = _4 & 1;
  if (_172 != 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 3> [local count: 22987625]:
  # DEBUG BEGIN_STMT
  _5 = outpkt_174(D)->cache_flush;
  _6 = (short unsigned int) _5;
  res_178 = mdns_add_a_answer (outpkt_174(D), _6, _1);
  # DEBUG res => res_178
  # DEBUG BEGIN_STMT
  if (res_178 != 0)
    goto <bb 4>; [34.00%]
  else
    goto <bb 5>; [66.00%]

  <bb 4> [local count: 7815793]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 83>; [100.00%]

  <bb 5> [local count: 61843677]:
  # res_106 = PHI <-16(2), res_178(3)>
  # answers_130 = PHI <0(2), 1(3)>
  # DEBUG answers => answers_130
  # DEBUG res => res_106
  # DEBUG BEGIN_STMT
  _9 = outpkt_174(D)->host_replies;
  _176 = _9 & 2;
  if (_176 != 0)
    goto <bb 6>; [33.00%]
  else
    goto <bb 9>; [67.00%]

  <bb 6> [local count: 20408413]:
  # DEBUG BEGIN_STMT
  _10 = outpkt_174(D)->cache_flush;
  _11 = (short unsigned int) _10;
  _12 = outpkt_174(D)->netif;
  res_181 = mdns_add_hostv4_ptr_answer (outpkt_174(D), _11, _12);
  # DEBUG res => res_181
  # DEBUG BEGIN_STMT
  if (res_181 != 0)
    goto <bb 7>; [34.00%]
  else
    goto <bb 8>; [66.00%]

  <bb 7> [local count: 6938861]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 83>; [100.00%]

  <bb 8> [local count: 13469553]:
  # DEBUG BEGIN_STMT
  answers_182 = answers_130 + 1;
  # DEBUG answers => answers_182

  <bb 9> [local count: 54904817]:
  # res_107 = PHI <res_106(5), 0(8)>
  # answers_131 = PHI <answers_130(5), answers_182(8)>
  # DEBUG answers => answers_131
  # DEBUG res => res_107
  # DEBUG BEGIN_STMT
  _14 = outpkt_174(D)->host_replies;
  _8 = _14 & 4;
  if (_8 != 0)
    goto <bb 87>; [50.00%]
  else
    goto <bb 16>; [50.00%]

  <bb 87> [local count: 27452408]:
  goto <bb 15>; [100.00%]

  <bb 10> [local count: 78104438]:
  # DEBUG BEGIN_STMT
  _15 = outpkt_174(D)->netif;
  _16 = _15->ip6_addr_state[addrindex_143];
  _253 = _16 & 16;
  if (_253 != 0)
    goto <bb 11>; [33.00%]
  else
    goto <bb 14>; [67.00%]

  <bb 11> [local count: 25774464]:
  # DEBUG BEGIN_STMT
  _17 = outpkt_174(D)->cache_flush;
  _18 = (short unsigned int) _17;
  res_185 = mdns_add_aaaa_answer (outpkt_174(D), _18, _15, addrindex_143);
  # DEBUG res => res_185
  # DEBUG BEGIN_STMT
  if (res_185 != 0)
    goto <bb 12>; [5.50%]
  else
    goto <bb 13>; [94.50%]

  <bb 12> [local count: 1417596]:
  # res_20 = PHI <res_185(11)>
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 83>; [100.00%]

  <bb 13> [local count: 24356869]:
  # DEBUG BEGIN_STMT
  answers_186 = answers_133 + 1;
  # DEBUG answers => answers_186

  <bb 14> [local count: 76686842]:
  # res_108 = PHI <res_109(10), 0(13)>
  # answers_132 = PHI <answers_133(10), answers_186(13)>
  # DEBUG answers => answers_132
  # DEBUG res => res_108
  # DEBUG BEGIN_STMT
  addrindex_187 = addrindex_143 + 1;
  # DEBUG addrindex => addrindex_187

  <bb 15> [local count: 104139250]:
  # res_109 = PHI <res_108(14), res_107(87)>
  # answers_133 = PHI <answers_132(14), answers_131(87)>
  # addrindex_143 = PHI <addrindex_187(14), 0(87)>
  # DEBUG addrindex => addrindex_143
  # DEBUG answers => answers_133
  # DEBUG res => res_109
  # DEBUG BEGIN_STMT
  if (addrindex_143 != 3)
    goto <bb 10>; [75.00%]
  else
    goto <bb 16>; [25.00%]

  <bb 16> [local count: 53487221]:
  # res_110 = PHI <res_107(9), res_109(15)>
  # answers_134 = PHI <answers_131(9), answers_133(15)>
  # DEBUG answers => answers_134
  # DEBUG res => res_110
  # DEBUG BEGIN_STMT
  _21 = outpkt_174(D)->host_replies;
  _179 = _21 & 8;
  if (_179 != 0)
    goto <bb 18>; [50.00%]
  else
    goto <bb 17>; [50.00%]

  <bb 17> [local count: 47129790]:
  # res_250 = PHI <res_110(16), res_112(24)>
  # i_105 = PHI <0(16), 0(24)>
  # answers_72 = PHI <answers_134(16), answers_136(24)>
  goto <bb 44>; [100.00%]

  <bb 18> [local count: 26743610]:
  # DEBUG BEGIN_STMT
  rev_addrs_188 = outpkt_174(D)->host_reverse_v6_replies;
  # DEBUG rev_addrs => rev_addrs_188
  # DEBUG BEGIN_STMT
  # DEBUG addrindex => 0
  # DEBUG BEGIN_STMT
  goto <bb 24>; [100.00%]

  <bb 19> [local count: 350271631]:
  # DEBUG BEGIN_STMT
  _78 = rev_addrs_144 & 1;
  if (_78 != 0)
    goto <bb 20>; [33.00%]
  else
    goto <bb 23>; [67.00%]

  <bb 20> [local count: 115589638]:
  # DEBUG BEGIN_STMT
  _22 = outpkt_174(D)->cache_flush;
  _23 = (short unsigned int) _22;
  _24 = outpkt_174(D)->netif;
  res_191 = mdns_add_hostv6_ptr_answer (outpkt_174(D), _23, _24, addrindex_145);
  # DEBUG res => res_191
  # DEBUG BEGIN_STMT
  if (res_191 != 0)
    goto <bb 21>; [5.50%]
  else
    goto <bb 22>; [94.50%]

  <bb 21> [local count: 6357430]:
  # res_25 = PHI <res_191(20)>
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 83>; [100.00%]

  <bb 22> [local count: 109232208]:
  # DEBUG BEGIN_STMT
  answers_192 = answers_136 + 1;
  # DEBUG answers => answers_192

  <bb 23> [local count: 343914200]:
  # res_111 = PHI <res_112(19), 0(22)>
  # answers_135 = PHI <answers_136(19), answers_192(22)>
  # DEBUG answers => answers_135
  # DEBUG res => res_111
  # DEBUG BEGIN_STMT
  addrindex_193 = addrindex_145 + 1;
  # DEBUG addrindex => addrindex_193
  # DEBUG BEGIN_STMT
  rev_addrs_194 = rev_addrs_144 >> 1;
  # DEBUG rev_addrs => rev_addrs_194

  <bb 24> [local count: 370657810]:
  # res_112 = PHI <res_110(18), res_111(23)>
  # answers_136 = PHI <answers_134(18), answers_135(23)>
  # rev_addrs_144 = PHI <rev_addrs_188(18), rev_addrs_194(23)>
  # addrindex_145 = PHI <0(18), addrindex_193(23)>
  # DEBUG addrindex => addrindex_145
  # DEBUG rev_addrs => rev_addrs_144
  # DEBUG answers => answers_136
  # DEBUG res => res_112
  # DEBUG BEGIN_STMT
  if (rev_addrs_144 != 0)
    goto <bb 19>; [94.50%]
  else
    goto <bb 17>; [5.50%]

  <bb 25> [local count: 1050119503]:
  # DEBUG BEGIN_STMT
  service_237 = mdns_175->services[0];
  # DEBUG service => service_237
  # DEBUG BEGIN_STMT
  if (service_237 == 0B)
    goto <bb 26>; [17.43%]
  else
    goto <bb 27>; [82.57%]

  <bb 26> [local count: 183035829]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by continue predictor.
  goto <bb 43>; [100.00%]

  <bb 27> [local count: 867083674]:
  # DEBUG BEGIN_STMT
  _26 = outpkt_174(D)->serv_replies[0];
  _57 = _26 & 16;
  if (_57 != 0)
    goto <bb 28>; [33.00%]
  else
    goto <bb 31>; [67.00%]

  <bb 28> [local count: 286137612]:
  # DEBUG BEGIN_STMT
  res_239 = mdns_add_servicetype_ptr_answer (outpkt_174(D), service_237);
  # DEBUG res => res_239
  # DEBUG BEGIN_STMT
  if (res_239 != 0)
    goto <bb 29>; [2.20%]
  else
    goto <bb 30>; [97.80%]

  <bb 29> [local count: 6295027]:
  # res_27 = PHI <res_239(28)>
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 83>; [100.00%]

  <bb 30> [local count: 279842584]:
  # DEBUG BEGIN_STMT
  answers_240 = answers_142 + 1;
  # DEBUG answers => answers_240

  <bb 31> [local count: 860788647]:
  # res_114 = PHI <res_118(27), 0(30)>
  # answers_138 = PHI <answers_142(27), answers_240(30)>
  # DEBUG answers => answers_138
  # DEBUG res => res_114
  # DEBUG BEGIN_STMT
  _28 = outpkt_174(D)->serv_replies[0];
  _228 = _28 & 32;
  if (_228 != 0)
    goto <bb 32>; [33.00%]
  else
    goto <bb 35>; [67.00%]

  <bb 32> [local count: 284060253]:
  # DEBUG BEGIN_STMT
  res_242 = mdns_add_servicename_ptr_answer (outpkt_174(D), service_237);
  # DEBUG res => res_242
  # DEBUG BEGIN_STMT
  if (res_242 != 0)
    goto <bb 33>; [2.20%]
  else
    goto <bb 34>; [97.80%]

  <bb 33> [local count: 6249326]:
  # res_29 = PHI <res_242(32)>
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 83>; [100.00%]

  <bb 34> [local count: 277810928]:
  # DEBUG BEGIN_STMT
  answers_243 = answers_138 + 1;
  # DEBUG answers => answers_243

  <bb 35> [local count: 854539322]:
  # res_115 = PHI <res_114(31), 0(34)>
  # answers_139 = PHI <answers_138(31), answers_243(34)>
  # DEBUG answers => answers_139
  # DEBUG res => res_115
  # DEBUG BEGIN_STMT
  _30 = outpkt_174(D)->serv_replies[0];
  _68 = _30 & 64;
  if (_68 != 0)
    goto <bb 36>; [33.00%]
  else
    goto <bb 39>; [67.00%]

  <bb 36> [local count: 281997976]:
  # DEBUG BEGIN_STMT
  _31 = outpkt_174(D)->cache_flush;
  _32 = (short unsigned int) _31;
  res_245 = mdns_add_srv_answer (outpkt_174(D), _32, mdns_175, service_237);
  # DEBUG res => res_245
  # DEBUG BEGIN_STMT
  if (res_245 != 0)
    goto <bb 37>; [2.20%]
  else
    goto <bb 38>; [97.80%]

  <bb 37> [local count: 6203955]:
  # res_33 = PHI <res_245(36)>
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 83>; [100.00%]

  <bb 38> [local count: 275794021]:
  # DEBUG BEGIN_STMT
  answers_246 = answers_139 + 1;
  # DEBUG answers => answers_246

  <bb 39> [local count: 848335366]:
  # res_116 = PHI <res_115(35), 0(38)>
  # answers_140 = PHI <answers_139(35), answers_246(38)>
  # DEBUG answers => answers_140
  # DEBUG res => res_116
  # DEBUG BEGIN_STMT
  _34 = outpkt_174(D)->serv_replies[0];
  _35 = (signed char) _34;
  if (_35 < 0)
    goto <bb 40>; [25.50%]
  else
    goto <bb 43>; [74.50%]

  <bb 40> [local count: 216325518]:
  # DEBUG BEGIN_STMT
  _36 = outpkt_174(D)->cache_flush;
  _37 = (short unsigned int) _36;
  res_248 = mdns_add_txt_answer (outpkt_174(D), _37, service_237);
  # DEBUG res => res_248
  # DEBUG BEGIN_STMT
  if (res_248 != 0)
    goto <bb 41>; [2.20%]
  else
    goto <bb 42>; [97.80%]

  <bb 41> [local count: 4759161]:
  # res_38 = PHI <res_248(40)>
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 83>; [100.00%]

  <bb 42> [local count: 211566357]:
  # DEBUG BEGIN_STMT
  answers_249 = answers_140 + 1;
  # DEBUG answers => answers_249

  <bb 43> [local count: 1026612034]:
  # res_159 = PHI <0(42), res_116(39), res_118(26)>
  # i_141 = PHI <1(42), 1(39), 1(26)>
  # answers_117 = PHI <answers_249(42), answers_140(39), answers_142(26)>

  <bb 44> [local count: 1073741824]:
  # res_118 = PHI <res_250(17), res_159(43)>
  # i_128 = PHI <i_105(17), i_141(43)>
  # answers_142 = PHI <answers_72(17), answers_117(43)>
  # DEBUG answers => answers_142
  # DEBUG i => i_128
  # DEBUG res => res_118
  # DEBUG BEGIN_STMT
  if (i_128 == 0)
    goto <bb 25>; [97.80%]
  else
    goto <bb 45>; [2.20%]

  <bb 45> [local count: 23622320]:
  # res_7 = PHI <res_118(44)>
  # answers_19 = PHI <answers_142(44)>
  # DEBUG BEGIN_STMT
  flags.25_39 = (signed char) flags_196(D);
  if (flags.25_39 < 0)
    goto <bb 46>; [41.00%]
  else
    goto <bb 48>; [59.00%]

  <bb 46> [local count: 9685151]:
  # DEBUG BEGIN_STMT
  _40 = outpkt_174(D)->answers;
  _41 = answers_19 + _40;
  outpkt_174(D)->answers = _41;

  <bb 47> [local count: 23622320]:
  # res_167 = PHI <res_7(46), res_7(48)>
  # i_124 = PHI <0(46), 0(48)>
  goto <bb 75>; [100.00%]

  <bb 48> [local count: 13937169]:
  # DEBUG BEGIN_STMT
  _42 = outpkt_174(D)->authoritative;
  _43 = answers_19 + _42;
  outpkt_174(D)->authoritative = _43;
  goto <bb 47>; [100.00%]

  <bb 49> [local count: 590638324]:
  # DEBUG BEGIN_STMT
  service_221 = mdns_175->services[0];
  # DEBUG service => service_221
  # DEBUG BEGIN_STMT
  if (service_221 == 0B)
    goto <bb 50>; [17.43%]
  else
    goto <bb 51>; [82.57%]

  <bb 50> [local count: 102948260]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by continue predictor.
  goto <bb 74>; [100.00%]

  <bb 51> [local count: 487690063]:
  # DEBUG BEGIN_STMT
  _44 = outpkt_174(D)->serv_replies[0];
  _183 = _44 & 32;
  if (_183 != 0)
    goto <bb 52>; [50.00%]
  else
    goto <bb 60>; [50.00%]

  <bb 52> [local count: 243845032]:
  # DEBUG BEGIN_STMT
  _189 = _44 & 64;
  if (_189 == 0)
    goto <bb 53>; [33.00%]
  else
    goto <bb 56>; [67.00%]

  <bb 53> [local count: 80468860]:
  # DEBUG BEGIN_STMT
  _47 = outpkt_174(D)->cache_flush;
  _48 = (short unsigned int) _47;
  res_223 = mdns_add_srv_answer (outpkt_174(D), _48, mdns_175, service_221);
  # DEBUG res => res_223
  # DEBUG BEGIN_STMT
  if (res_223 != 0)
    goto <bb 54>; [2.20%]
  else
    goto <bb 55>; [97.80%]

  <bb 54> [local count: 1770315]:
  # res_45 = PHI <res_223(53)>
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 83>; [100.00%]

  <bb 55> [local count: 78698545]:
  # DEBUG BEGIN_STMT
  _49 = outpkt_174(D)->additional;
  _51 = _49 + 1;
  outpkt_174(D)->additional = _51;

  <bb 56> [local count: 242074717]:
  # res_119 = PHI <res_125(52), 0(55)>
  # DEBUG res => res_119
  # DEBUG BEGIN_STMT
  _52 = outpkt_174(D)->serv_replies[0];
  _53 = (signed char) _52;
  if (_53 >= 0)
    goto <bb 57>; [41.48%]
  else
    goto <bb 60>; [58.52%]

  <bb 57> [local count: 100412592]:
  # DEBUG BEGIN_STMT
  _54 = outpkt_174(D)->cache_flush;
  _55 = (short unsigned int) _54;
  res_226 = mdns_add_txt_answer (outpkt_174(D), _55, service_221);
  # DEBUG res => res_226
  # DEBUG BEGIN_STMT
  if (res_226 != 0)
    goto <bb 58>; [2.20%]
  else
    goto <bb 59>; [97.80%]

  <bb 58> [local count: 2209077]:
  # res_46 = PHI <res_226(57)>
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 83>; [100.00%]

  <bb 59> [local count: 98203515]:
  # DEBUG BEGIN_STMT
  _56 = outpkt_174(D)->additional;
  _58 = _56 + 1;
  outpkt_174(D)->additional = _58;

  <bb 60> [local count: 483710671]:
  # res_120 = PHI <res_125(51), res_119(56), 0(59)>
  # DEBUG res => res_120
  # DEBUG BEGIN_STMT
  _59 = outpkt_174(D)->serv_replies[0];
  _195 = _59 & 96;
  if (_195 != 0)
    goto <bb 62>; [50.00%]
  else
    goto <bb 61>; [50.00%]

  <bb 61> [local count: 241855335]:
  _60 = outpkt_174(D)->host_replies;
  _199 = _60 & 5;
  if (_199 != 0)
    goto <bb 62>; [50.00%]
  else
    goto <bb 74>; [50.00%]

  <bb 62> [local count: 362783003]:
  # DEBUG BEGIN_STMT
  _61 = outpkt_174(D)->host_replies;
  _214 = _61 & 4;
  if (_214 == 0)
    goto <bb 86>; [27.00%]
  else
    goto <bb 69>; [73.00%]

  <bb 86> [local count: 97951411]:
  goto <bb 68>; [100.00%]

  <bb 63> [local count: 278680099]:
  # DEBUG BEGIN_STMT
  _62 = outpkt_174(D)->netif;
  _63 = _62->ip6_addr_state[addrindex_146];
  _50 = _63 & 16;
  if (_50 != 0)
    goto <bb 64>; [33.00%]
  else
    goto <bb 67>; [67.00%]

  <bb 64> [local count: 91964433]:
  # DEBUG BEGIN_STMT
  _64 = outpkt_174(D)->cache_flush;
  _65 = (short unsigned int) _64;
  res_230 = mdns_add_aaaa_answer (outpkt_174(D), _65, _62, addrindex_146);
  # DEBUG res => res_230
  # DEBUG BEGIN_STMT
  if (res_230 != 0)
    goto <bb 65>; [5.50%]
  else
    goto <bb 66>; [94.50%]

  <bb 65> [local count: 5058044]:
  # res_66 = PHI <res_230(64)>
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 83>; [100.00%]

  <bb 66> [local count: 86906389]:
  # DEBUG BEGIN_STMT
  _67 = outpkt_174(D)->additional;
  _69 = _67 + 1;
  outpkt_174(D)->additional = _69;

  <bb 67> [local count: 273622055]:
  # res_121 = PHI <res_122(63), 0(66)>
  # DEBUG res => res_121
  # DEBUG BEGIN_STMT
  addrindex_232 = addrindex_146 + 1;
  # DEBUG addrindex => addrindex_232

  <bb 68> [local count: 371573466]:
  # res_122 = PHI <res_121(67), res_120(86)>
  # addrindex_146 = PHI <addrindex_232(67), 0(86)>
  # DEBUG addrindex => addrindex_146
  # DEBUG res => res_122
  # DEBUG BEGIN_STMT
  if (addrindex_146 != 3)
    goto <bb 63>; [75.00%]
  else
    goto <bb 69>; [25.00%]

  <bb 69> [local count: 357724959]:
  # res_123 = PHI <res_120(62), res_122(68)>
  # DEBUG res => res_123
  # DEBUG BEGIN_STMT
  _70 = outpkt_174(D)->host_replies;
  _215 = _70 & 1;
  if (_215 == 0)
    goto <bb 70>; [50.00%]
  else
    goto <bb 74>; [50.00%]

  <bb 70> [local count: 178862480]:
  _71 = outpkt_174(D)->netif;
  _73 = MEM[(const struct ip4_addr_t *)_71 + 4B].addr;
  if (_73 != 0)
    goto <bb 71>; [33.00%]
  else
    goto <bb 74>; [67.00%]

  <bb 71> [local count: 59024618]:
  # DEBUG BEGIN_STMT
  _74 = outpkt_174(D)->cache_flush;
  _75 = (short unsigned int) _74;
  res_234 = mdns_add_a_answer (outpkt_174(D), _75, _71);
  # DEBUG res => res_234
  # DEBUG BEGIN_STMT
  if (res_234 != 0)
    goto <bb 72>; [2.20%]
  else
    goto <bb 73>; [97.80%]

  <bb 72> [local count: 1298542]:
  # res_76 = PHI <res_234(71)>
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 83>; [100.00%]

  <bb 73> [local count: 57726077]:
  # DEBUG BEGIN_STMT
  _77 = outpkt_174(D)->additional;
  _79 = _77 + 1;
  outpkt_174(D)->additional = _79;

  <bb 74> [local count: 580302347]:
  # res_155 = PHI <res_123(69), res_120(61), res_125(50), 0(73), res_123(70)>
  # i_137 = PHI <1(69), 1(61), 1(50), 1(73), 1(70)>

  <bb 75> [local count: 603924666]:
  # res_125 = PHI <res_167(47), res_155(74)>
  # i_129 = PHI <i_124(47), i_137(74)>
  # DEBUG i => i_129
  # DEBUG res => res_125
  # DEBUG BEGIN_STMT
  if (i_129 == 0)
    goto <bb 49>; [97.80%]
  else
    goto <bb 76>; [2.20%]

  <bb 76> [local count: 13286343]:
  # res_13 = PHI <res_125(75)>
  # DEBUG BEGIN_STMT
  _80 = outpkt_174(D)->pbuf;
  if (_80 != 0B)
    goto <bb 77>; [53.47%]
  else
    goto <bb 83>; [46.53%]

  <bb 77> [local count: 7104207]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  memset (&hdr, 0, 12);
  # DEBUG BEGIN_STMT
  hdr.flags1 = flags_196(D);
  # DEBUG BEGIN_STMT
  _81 = outpkt_174(D)->questions;
  _82 = lwip_htons (_81);
  hdr.numquestions = _82;
  # DEBUG BEGIN_STMT
  _83 = outpkt_174(D)->answers;
  _84 = lwip_htons (_83);
  hdr.numanswers = _84;
  # DEBUG BEGIN_STMT
  _85 = outpkt_174(D)->authoritative;
  _86 = lwip_htons (_85);
  hdr.numauthrr = _86;
  # DEBUG BEGIN_STMT
  _87 = outpkt_174(D)->additional;
  _88 = lwip_htons (_87);
  hdr.numextrarr = _88;
  # DEBUG BEGIN_STMT
  _89 = outpkt_174(D)->tx_id;
  _90 = lwip_htons (_89);
  hdr.id = _90;
  # DEBUG BEGIN_STMT
  _91 = outpkt_174(D)->pbuf;
  pbuf_take (_91, &hdr, 12);
  # DEBUG BEGIN_STMT
  _92 = outpkt_174(D)->pbuf;
  _93 = outpkt_174(D)->write_offset;
  pbuf_realloc (_92, _93);
  # DEBUG BEGIN_STMT
  _94 = outpkt_174(D)->dest_addr.type;
  if (_94 == 6)
    goto <bb 79>; [34.00%]
  else
    goto <bb 78>; [66.00%]

  <bb 78> [local count: 4688777]:
  # DEBUG BEGIN_STMT
  # DEBUG mcast_destaddr => &v4group

  <bb 79> [local count: 7104207]:
  # mcast_destaddr_147 = PHI <&v6group(77), &v4group(78)>
  # DEBUG mcast_destaddr => mcast_destaddr_147
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _95 = outpkt_174(D)->unicast_reply;
  if (_95 != 0)
    goto <bb 80>; [50.00%]
  else
    goto <bb 81>; [50.00%]

  <bb 80> [local count: 3552104]:
  # DEBUG BEGIN_STMT
  mdns_pcb.26_96 = mdns_pcb;
  _97 = outpkt_174(D)->pbuf;
  _98 = &outpkt_174(D)->dest_addr;
  _99 = outpkt_174(D)->dest_port;
  _100 = outpkt_174(D)->netif;
  res_219 = udp_sendto_if (mdns_pcb.26_96, _97, _98, _99, _100);
  # DEBUG res => res_219
  goto <bb 82>; [100.00%]

  <bb 81> [local count: 3552104]:
  # DEBUG BEGIN_STMT
  mdns_pcb.27_101 = mdns_pcb;
  _102 = outpkt_174(D)->pbuf;
  _103 = outpkt_174(D)->netif;
  res_217 = udp_sendto_if (mdns_pcb.27_101, _102, mcast_destaddr_147, 5353, _103);
  # DEBUG res => res_217

  <bb 82> [local count: 7104207]:
  # res_126 = PHI <res_219(80), res_217(81)>
  # DEBUG res => res_126
  hdr ={v} {CLOBBER};

  <bb 83> [local count: 69659469]:
  # res_127 = PHI <res_178(4), res_181(7), res_20(12), res_25(21), res_27(29), res_29(33), res_33(37), res_38(41), res_45(54), res_46(58), res_66(65), res_76(72), res_13(76), res_126(82)>
cleanup:
  # DEBUG res => res_127
  # DEBUG BEGIN_STMT
  _104 = outpkt_174(D)->pbuf;
  if (_104 != 0B)
    goto <bb 84>; [53.47%]
  else
    goto <bb 85>; [46.53%]

  <bb 84> [local count: 37246918]:
  # DEBUG BEGIN_STMT
  pbuf_free (_104);
  # DEBUG BEGIN_STMT
  outpkt_174(D)->pbuf = 0B;

  <bb 85> [local count: 69659469]:
  # DEBUG BEGIN_STMT
  return res_127;

}



;; Function mdns_send_probe (mdns_send_probe, funcdef_no=38, decl_uid=7767, cgraph_uid=39, symbol_order=45)

Modification phase of node mdns_send_probe/45
Adjusting mask for param 1 to 0xfffffffc
Adjusting align: 4, misalign: 0
Setting nonnull for 1
mdns_send_probe (struct netif * netif, const struct ip_addr_t * destination)
{
  struct mdns_service * serv;
  struct mdns_service * service;
  err_t res;
  u8_t i;
  struct mdns_domain domain;
  struct mdns_outpacket pkt;
  struct mdns_host * mdns;
  unsigned char mdns_netif_client_id.11_1;
  int _2;
  short unsigned int _3;
  unsigned char _4;
  short unsigned int _5;
  short unsigned int _6;
  short unsigned int _7;
  long unsigned int _8;
  int _9;
  unsigned char _10;
  unsigned char _11;
  unsigned char _12;
  struct pbuf * _15;

  <bb 2> [local count: 148668505]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mdns_netif_client_id.11_1 = mdns_netif_client_id;
  _2 = (int) mdns_netif_client_id.11_1;
  mdns_31 = netif_30(D)->client_data[_2];
  # DEBUG mdns => mdns_31
  # DEBUG BEGIN_STMT
  memset (&MEM[(void *)&pkt + 4B], 0, 68);
  # DEBUG BEGIN_STMT
  pkt.netif = netif_30(D);
  # DEBUG BEGIN_STMT
  mdns_build_host_domain (&domain, mdns_31);
  # DEBUG BEGIN_STMT
  res_36 = mdns_add_question (&pkt, &domain, 255, 1, 1);
  # DEBUG res => res_36
  # DEBUG BEGIN_STMT
  if (res_36 != 0)
    goto <bb 3>; [34.00%]
  else
    goto <bb 4>; [66.00%]

  <bb 3> [local count: 50547292]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 24>; [100.00%]

  <bb 4> [local count: 98121213]:
  # DEBUG BEGIN_STMT
  _3 = pkt.questions;
  _5 = _3 + 1;
  pkt.questions = _5;
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  goto <bb 11>; [100.00%]

  <bb 5> [local count: 1014686015]:
  # DEBUG BEGIN_STMT
  service_50 = mdns_31->services[0];
  # DEBUG service => service_50
  # DEBUG BEGIN_STMT
  if (service_50 == 0B)
    goto <bb 6>; [30.00%]
  else
    goto <bb 7>; [70.00%]

  <bb 6> [local count: 304405805]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by continue predictor.
  goto <bb 10>; [100.00%]

  <bb 7> [local count: 710280211]:
  # DEBUG BEGIN_STMT
  mdns_build_service_domain (&domain, service_50, 1);
  # DEBUG BEGIN_STMT
  res_53 = mdns_add_question (&pkt, &domain, 255, 1, 1);
  # DEBUG res => res_53
  # DEBUG BEGIN_STMT
  if (res_53 != 0)
    goto <bb 8>; [5.50%]
  else
    goto <bb 9>; [94.50%]

  <bb 8> [local count: 39065412]:
  # res_14 = PHI <res_53(7)>
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 24>; [100.00%]

  <bb 9> [local count: 671214799]:
  # DEBUG BEGIN_STMT
  _6 = pkt.questions;
  _7 = _6 + 1;
  pkt.questions = _7;

  <bb 10> [local count: 975620603]:
  # i_22 = PHI <1(6), 1(9)>

  <bb 11> [local count: 1073741814]:
  # i_16 = PHI <i_22(10), 0(4)>
  # DEBUG i => i_16
  # DEBUG BEGIN_STMT
  if (i_16 == 0)
    goto <bb 5>; [94.50%]
  else
    goto <bb 12>; [5.50%]

  <bb 12> [local count: 59055800]:
  # DEBUG BEGIN_STMT
  _8 = MEM[(const struct ip4_addr_t *)netif_30(D) + 4B].addr;
  if (_8 != 0)
    goto <bb 13>; [50.00%]
  else
    goto <bb 14>; [50.00%]

  <bb 13> [local count: 29527900]:
  # DEBUG BEGIN_STMT
  pkt.host_replies = 1;

  <bb 14> [local count: 59055800]:
  # i_13 = PHI <0(13), 0(12)>
  goto <bb 18>; [100.00%]

  <bb 15> [local count: 177167399]:
  # DEBUG BEGIN_STMT
  _9 = (int) i_17;
  _10 = netif_30(D)->ip6_addr_state[_9];
  _4 = _10 & 16;
  if (_4 != 0)
    goto <bb 16>; [50.00%]
  else
    goto <bb 17>; [50.00%]

  <bb 16> [local count: 88583700]:
  # DEBUG BEGIN_STMT
  _11 = pkt.host_replies;
  _12 = _11 | 4;
  pkt.host_replies = _12;

  <bb 17> [local count: 177167399]:
  # DEBUG BEGIN_STMT
  i_49 = i_17 + 1;
  # DEBUG i => i_49

  <bb 18> [local count: 236223199]:
  # i_17 = PHI <i_13(14), i_49(17)>
  # DEBUG i => i_17
  # DEBUG BEGIN_STMT
  if (i_17 != 3)
    goto <bb 15>; [75.00%]
  else
    goto <bb 27>; [25.00%]

  <bb 27> [local count: 59055800]:
  goto <bb 21>; [100.00%]

  <bb 19> [local count: 1014686024]:
  # DEBUG BEGIN_STMT
  serv_45 = mdns_31->services[0];
  # DEBUG serv => serv_45
  # DEBUG BEGIN_STMT
  if (serv_45 != 0B)
    goto <bb 20>; [67.00%]
  else
    goto <bb 28>; [33.00%]

  <bb 28> [local count: 334846388]:
  goto <bb 22>; [100.00%]

  <bb 20> [local count: 679839636]:
  # DEBUG BEGIN_STMT
  pkt.serv_replies[0] = 192;

  <bb 21> [local count: 738895437]:
  # i_56 = PHI <1(20), 0(27)>

  <bb 22> [local count: 1073741824]:
  # i_18 = PHI <i_56(21), 1(28)>
  # DEBUG i => i_18
  # DEBUG BEGIN_STMT
  if (i_18 == 0)
    goto <bb 19>; [94.50%]
  else
    goto <bb 23>; [5.50%]

  <bb 23> [local count: 59055800]:
  # DEBUG BEGIN_STMT
  pkt.tx_id = 0;
  # DEBUG BEGIN_STMT
  pkt.dest_port = 5353;
  # DEBUG BEGIN_STMT
  memcpy (&pkt.dest_addr, destination_41(D), 24);
  # DEBUG BEGIN_STMT
  res_44 = mdns_send_outpacket (&pkt, 0);
  # DEBUG res => res_44

  <bb 24> [local count: 148668503]:
  # res_19 = PHI <res_36(3), res_14(8), res_44(23)>
cleanup:
  # DEBUG res => res_19
  # DEBUG BEGIN_STMT
  _15 = pkt.pbuf;
  if (_15 != 0B)
    goto <bb 25>; [53.47%]
  else
    goto <bb 26>; [46.53%]

  <bb 25> [local count: 79493049]:
  # DEBUG BEGIN_STMT
  pbuf_free (_15);
  # DEBUG BEGIN_STMT

  <bb 26> [local count: 148668503]:
  # DEBUG BEGIN_STMT
  pkt ={v} {CLOBBER};
  domain ={v} {CLOBBER};
  return res_19;

}



;; Function mdns_announce (mdns_announce, funcdef_no=34, decl_uid=7679, cgraph_uid=35, symbol_order=40)

Modification phase of node mdns_announce/40
Adjusting mask for param 1 to 0xfffffffc
Adjusting align: 4, misalign: 0
Setting nonnull for 1
mdns_announce (struct netif * netif, const struct ip_addr_t * destination)
{
  struct mdns_service * serv;
  struct mdns_host * mdns;
  int i;
  struct mdns_outpacket announce;
  unsigned char mdns_netif_client_id.47_1;
  int _2;
  long unsigned int _4;
  unsigned char _5;
  unsigned char _6;
  unsigned char _7;
  unsigned char _8;
  signed char _9;
  int _10;
  signed char _11;
  signed char _12;
  unsigned char _13;
  unsigned char _28;

  <bb 2> [local count: 59055800]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mdns_netif_client_id.47_1 = mdns_netif_client_id;
  _2 = (int) mdns_netif_client_id.47_1;
  mdns_23 = netif_22(D)->client_data[_2];
  # DEBUG mdns => mdns_23
  # DEBUG BEGIN_STMT
  memset (&MEM[(void *)&announce + 4B], 0, 68);
  # DEBUG BEGIN_STMT
  announce.netif = netif_22(D);
  # DEBUG BEGIN_STMT
  announce.cache_flush = 1;
  # DEBUG BEGIN_STMT
  _4 = MEM[(const struct ip4_addr_t *)netif_22(D) + 4B].addr;
  if (_4 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 29527900]:
  # DEBUG BEGIN_STMT
  announce.host_replies = 3;

  <bb 4> [local count: 59055800]:
  # i_36 = PHI <0(3), 0(2)>
  goto <bb 8>; [100.00%]

  <bb 5> [local count: 177167400]:
  # DEBUG BEGIN_STMT
  _5 = netif_22(D)->ip6_addr_state[i_14];
  _28 = _5 & 16;
  if (_28 != 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 6> [local count: 88583700]:
  # DEBUG BEGIN_STMT
  _6 = announce.host_replies;
  _7 = _6 | 12;
  announce.host_replies = _7;
  # DEBUG BEGIN_STMT
  _8 = announce.host_reverse_v6_replies;
  _9 = (signed char) _8;
  _10 = 1 << i_14;
  _11 = (signed char) _10;
  _12 = _9 | _11;
  _13 = (unsigned char) _12;
  announce.host_reverse_v6_replies = _13;

  <bb 7> [local count: 177167400]:
  # DEBUG BEGIN_STMT
  i_39 = i_14 + 1;
  # DEBUG i => i_39

  <bb 8> [local count: 236223199]:
  # i_14 = PHI <i_36(4), i_39(7)>
  # DEBUG i => i_14
  # DEBUG BEGIN_STMT
  if (i_14 != 3)
    goto <bb 5>; [75.00%]
  else
    goto <bb 14>; [25.00%]

  <bb 14> [local count: 59055800]:
  goto <bb 11>; [100.00%]

  <bb 9> [local count: 1014686025]:
  # DEBUG BEGIN_STMT
  serv_34 = mdns_23->services[0];
  # DEBUG serv => serv_34
  # DEBUG BEGIN_STMT
  if (serv_34 != 0B)
    goto <bb 10>; [67.00%]
  else
    goto <bb 15>; [33.00%]

  <bb 15> [local count: 334846388]:
  goto <bb 12>; [100.00%]

  <bb 10> [local count: 679839637]:
  # DEBUG BEGIN_STMT
  announce.serv_replies[0] = 240;

  <bb 11> [local count: 738895437]:
  # i_16 = PHI <1(10), 0(14)>

  <bb 12> [local count: 1073741824]:
  # i_15 = PHI <i_16(11), 1(15)>
  # DEBUG i => i_15
  # DEBUG BEGIN_STMT
  if (i_15 == 0)
    goto <bb 9>; [94.50%]
  else
    goto <bb 13>; [5.50%]

  <bb 13> [local count: 59055800]:
  # DEBUG BEGIN_STMT
  announce.dest_port = 5353;
  # DEBUG BEGIN_STMT
  memcpy (&announce.dest_addr, destination_30(D), 24);
  # DEBUG BEGIN_STMT
  mdns_send_outpacket (&announce, 132);
  announce ={v} {CLOBBER};
  return;

}



;; Function mdns_handle_question (mdns_handle_question, funcdef_no=35, decl_uid=7692, cgraph_uid=36, symbol_order=41)

Modification phase of node mdns_handle_question/41
Adjusting mask for param 0 to 0xfffffffc
Adjusting align: 4, misalign: 0
Setting nonnull for 0
mdns_handle_question (struct mdns_packet * pkt)
{
  struct mdns_domain my_ans;
  struct mdns_domain known_ans;
  u16_t read_pos;
  u16_t len;
  u16_t field16;
  u16_t len;
  struct mdns_domain my_ans;
  struct mdns_domain known_ans;
  u16_t len;
  struct mdns_domain my_ans;
  struct mdns_domain known_ans;
  int match;
  u8_t rev_v6;
  struct mdns_answer ans;
  struct mdns_question q;
  struct mdns_host * mdns;
  err_t res;
  int i;
  int replies;
  struct mdns_outpacket reply;
  struct mdns_service * service;
  struct netif * _1;
  unsigned char mdns_netif_client_id.69_2;
  int _3;
  unsigned char _4;
  short unsigned int _5;
  struct netif * _6;
  unsigned char _7;
  signed char _8;
  signed char _9;
  signed char _10;
  unsigned char _11;
  int _12;
  unsigned char _13;
  signed char _14;
  signed char _15;
  signed char _16;
  unsigned char _17;
  int _18;
  unsigned char _19;
  short unsigned int _20;
  short unsigned int _21;
  short unsigned int _22;
  short unsigned int _23;
  short unsigned int _24;
  unsigned char _25;
  int _26;
  struct netif * _27;
  int _28;
  long unsigned int _29;
  long unsigned int _30;
  long unsigned int _31;
  short unsigned int _32;
  struct pbuf * _33;
  short unsigned int _34;
  int _35;
  int _36;
  unsigned char _37;
  unsigned char _38;
  int _39;
  unsigned char _40;
  signed char _41;
  unsigned char rev_v6.70_42;
  signed char rev_v6.71_43;
  signed char _44;
  signed char _45;
  unsigned char _46;
  unsigned char _47;
  unsigned char _48;
  int _49;
  short unsigned int _50;
  struct pbuf * _51;
  short unsigned int _52;
  struct netif * _53;
  struct ip4_addr_t * _54;
  short unsigned int _56;
  unsigned char _57;
  unsigned char _58;
  int _59;
  short unsigned int _60;
  struct pbuf * _61;
  short unsigned int _62;
  struct netif * _63;
  struct ip6_addr_t * _64;
  short unsigned int _66;
  unsigned char _67;
  unsigned char _68;
  unsigned char _69;
  int _70;
  int _71;
  long unsigned int _72;
  long unsigned int _73;
  long unsigned int _74;
  short unsigned int _75;
  struct pbuf * _76;
  short unsigned int _77;
  int _78;
  int _79;
  unsigned char _80;
  unsigned char _81;
  int _82;
  int _83;
  unsigned char _84;
  unsigned char _85;
  int _86;
  struct pbuf * _87;
  short unsigned int field16.72_88;
  short unsigned int _89;
  struct pbuf * _90;
  short unsigned int field16.73_91;
  short unsigned int _92;
  struct pbuf * _93;
  short unsigned int field16.74_94;
  short unsigned int _95;
  short unsigned int _96;
  struct pbuf * _97;
  int _98;
  unsigned char _99;
  unsigned char _100;
  int _101;
  short unsigned int _102;
  short unsigned int _103;
  struct pbuf * _104;
  short unsigned int _105;
  u8_t[256] * _106;
  short unsigned int _107;
  unsigned char _108;
  unsigned char _109;
  short unsigned int _110;
  struct pbuf * _111;
  int _209;
  int _219;

  <bb 2> [local count: 135784700]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG replies => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = pkt_136(D)->netif;
  mdns_netif_client_id.69_2 = mdns_netif_client_id;
  _3 = (int) mdns_netif_client_id.69_2;
  mdns_137 = _1->client_data[_3];
  # DEBUG mdns => mdns_137
  # DEBUG BEGIN_STMT
  _4 = mdns_137->probing_state;
  if (_4 != 2)
    goto <bb 85>; [67.00%]
  else
    goto <bb 3>; [33.00%]

  <bb 3> [local count: 44808951]:
  # DEBUG BEGIN_STMT
  mdns_init_outpacket (&reply, pkt_136(D));
  # DEBUG BEGIN_STMT
  goto <bb 19>; [100.00%]

  <bb 4> [local count: 557266881]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  res_206 = mdns_read_question (pkt_136(D), &q);
  # DEBUG res => res_206
  # DEBUG BEGIN_STMT
  if (res_206 != 0)
    goto <bb 5>; [3.66%]
  else
    goto <bb 6>; [96.34%]

  <bb 5> [local count: 20395968]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  q ={v} {CLOBBER};
  goto <bb 85>; [100.00%]

  <bb 6> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mdns_domain_debug_print (&q.info.domain);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _5 = q.unicast;
  if (_5 != 0)
    goto <bb 7>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 7> [local count: 268435456]:
  # DEBUG BEGIN_STMT
  reply.unicast_reply = 1;

  <bb 8> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _6 = pkt_136(D)->netif;
  _209 = check_host (_6, &q.info, &reply.host_reverse_v6_replies);
  _7 = reply.host_replies;
  _8 = (signed char) _7;
  _9 = (signed char) _209;
  _10 = _8 | _9;
  _11 = (unsigned char) _10;
  reply.host_replies = _11;
  # DEBUG BEGIN_STMT
  _12 = (int) _11;
  replies_211 = _12 | replies_114;
  # DEBUG replies => replies_211
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  goto <bb 13>; [100.00%]

  <bb 9> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  service_217 = mdns_137->services[0];
  # DEBUG service => service_217
  # DEBUG BEGIN_STMT
  if (service_217 == 0B)
    goto <bb 10>; [30.00%]
  else
    goto <bb 11>; [70.00%]

  <bb 10> [local count: 161061274]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by continue predictor.
  goto <bb 12>; [100.00%]

  <bb 11> [local count: 375809638]:
  # DEBUG BEGIN_STMT
  _219 = check_service (service_217, &q.info);
  _13 = reply.serv_replies[0];
  _14 = (signed char) _13;
  _15 = (signed char) _219;
  _16 = _14 | _15;
  _17 = (unsigned char) _16;
  reply.serv_replies[0] = _17;
  # DEBUG BEGIN_STMT
  _18 = (int) _17;
  replies_221 = _18 | replies_113;
  # DEBUG replies => replies_221

  <bb 12> [local count: 536870912]:
  # replies_124 = PHI <replies_113(10), replies_221(11)>
  # i_128 = PHI <1(10), 1(11)>

  <bb 13> [local count: 1073741824]:
  # replies_113 = PHI <replies_124(12), replies_211(8)>
  # i_115 = PHI <i_128(12), 0(8)>
  # DEBUG i => i_115
  # DEBUG replies => replies_113
  # DEBUG BEGIN_STMT
  if (i_115 == 0)
    goto <bb 9>; [50.00%]
  else
    goto <bb 14>; [50.00%]

  <bb 14> [local count: 536870913]:
  # replies_55 = PHI <replies_113(13)>
  # DEBUG BEGIN_STMT
  if (replies_55 != 0)
    goto <bb 15>; [50.00%]
  else
    goto <bb 18>; [50.00%]

  <bb 15> [local count: 268435456]:
  _19 = reply.legacy_query;
  if (_19 != 0)
    goto <bb 16>; [33.00%]
  else
    goto <bb 18>; [67.00%]

  <bb 16> [local count: 88583700]:
  # DEBUG BEGIN_STMT
  _20 = q.info.type;
  _21 = q.info.klass;
  res_213 = mdns_add_question (&reply, &q.info.domain, _20, _21, 0);
  # DEBUG res => res_213
  # DEBUG BEGIN_STMT
  reply.questions = 1;
  # DEBUG BEGIN_STMT
  if (res_213 != 0)
    goto <bb 17>; [3.66%]
  else
    goto <bb 18>; [96.34%]

  <bb 17> [local count: 3242163]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  q ={v} {CLOBBER};
  goto <bb 82>; [100.00%]

  <bb 18> [local count: 533628749]:
  q ={v} {CLOBBER};

  <bb 19> [local count: 578437701]:
  # replies_114 = PHI <0(3), replies_55(18)>
  # DEBUG replies => replies_114
  # DEBUG BEGIN_STMT
  _22 = pkt_136(D)->questions_left;
  if (_22 != 0)
    goto <bb 4>; [96.34%]
  else
    goto <bb 87>; [3.66%]

  <bb 87> [local count: 21170821]:
  goto <bb 80>; [100.00%]

  <bb 20> [local count: 187019628]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  res_141 = mdns_read_answer (pkt_136(D), &ans);
  # DEBUG res => res_141
  # DEBUG BEGIN_STMT
  if (res_141 != 0)
    goto <bb 21>; [5.50%]
  else
    goto <bb 22>; [94.50%]

  <bb 21> [local count: 10286080]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  ans ={v} {CLOBBER};
  rev_v6 ={v} {CLOBBER};
  goto <bb 82>; [100.00%]

  <bb 22> [local count: 176733548]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mdns_domain_debug_print (&ans.info.domain);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _23 = ans.info.type;
  if (_23 == 255)
    goto <bb 24>; [20.24%]
  else
    goto <bb 23>; [79.76%]

  <bb 23> [local count: 140962678]:
  _24 = ans.info.klass;
  if (_24 == 255)
    goto <bb 24>; [58.20%]
  else
    goto <bb 25>; [41.80%]

  <bb 24> [local count: 117811149]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by continue predictor.
  ans ={v} {CLOBBER};
  rev_v6 ={v} {CLOBBER};
  goto <bb 79>; [100.00%]

  <bb 25> [local count: 58922399]:
  # DEBUG BEGIN_STMT
  rev_v6 = 0;
  # DEBUG BEGIN_STMT
  _25 = reply.host_replies;
  _26 = (int) _25;
  _27 = pkt_136(D)->netif;
  _28 = check_host (_27, &ans.info, &rev_v6);
  match_144 = _26 & _28;
  # DEBUG match => match_144
  # DEBUG BEGIN_STMT
  if (match_144 != 0)
    goto <bb 26>; [50.00%]
  else
    goto <bb 41>; [50.00%]

  <bb 26> [local count: 29461200]:
  _29 = ans.ttl;
  _30 = mdns_137->dns_ttl;
  _31 = _30 >> 1;
  if (_29 > _31)
    goto <bb 27>; [50.00%]
  else
    goto <bb 41>; [50.00%]

  <bb 27> [local count: 14730600]:
  # DEBUG BEGIN_STMT
  _32 = ans.info.type;
  if (_32 == 12)
    goto <bb 28>; [20.24%]
  else
    goto <bb 37>; [79.76%]

  <bb 28> [local count: 2981473]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _33 = pkt_136(D)->pbuf;
  _34 = ans.rd_offset;
  len_150 = mdns_readname (_33, _34, &known_ans);
  # DEBUG len => len_150
  # DEBUG BEGIN_STMT
  res_152 = mdns_build_host_domain (&my_ans, mdns_137);
  # DEBUG res => res_152
  # DEBUG BEGIN_STMT
  if (len_150 != 65535)
    goto <bb 29>; [66.00%]
  else
    goto <bb 36>; [34.00%]

  <bb 29> [local count: 1967772]:
  if (res_152 == 0)
    goto <bb 30>; [33.00%]
  else
    goto <bb 36>; [67.00%]

  <bb 30> [local count: 649365]:
  _35 = mdns_domain_eq (&known_ans, &my_ans);
  if (_35 != 0)
    goto <bb 31>; [50.00%]
  else
    goto <bb 36>; [50.00%]

  <bb 31> [local count: 324682]:
  # DEBUG BEGIN_STMT
  _36 = match_144 & 2;
  if (_36 != 0)
    goto <bb 32>; [50.00%]
  else
    goto <bb 33>; [50.00%]

  <bb 32> [local count: 162341]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _37 = reply.host_replies;
  _38 = _37 & 253;
  reply.host_replies = _38;

  <bb 33> [local count: 324682]:
  # DEBUG BEGIN_STMT
  _39 = match_144 & 8;
  if (_39 != 0)
    goto <bb 34>; [50.00%]
  else
    goto <bb 36>; [50.00%]

  <bb 34> [local count: 162341]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _40 = reply.host_reverse_v6_replies;
  _41 = (signed char) _40;
  rev_v6.70_42 = rev_v6;
  rev_v6.71_43 = (signed char) rev_v6.70_42;
  _44 = ~rev_v6.71_43;
  _45 = _41 & _44;
  _46 = (unsigned char) _45;
  reply.host_reverse_v6_replies = _46;
  # DEBUG BEGIN_STMT
  if (_46 == 0)
    goto <bb 35>; [50.00%]
  else
    goto <bb 36>; [50.00%]

  <bb 35> [local count: 81171]:
  # DEBUG BEGIN_STMT
  _47 = reply.host_replies;
  _48 = _47 & 247;
  reply.host_replies = _48;

  <bb 36> [local count: 2981473]:
  known_ans ={v} {CLOBBER};
  my_ans ={v} {CLOBBER};
  goto <bb 41>; [100.00%]

  <bb 37> [local count: 11749126]:
  # DEBUG BEGIN_STMT
  _49 = match_144 & 1;
  if (_49 != 0)
    goto <bb 38>; [50.00%]
  else
    goto <bb 42>; [50.00%]

  <bb 38> [local count: 5874563]:
  # DEBUG BEGIN_STMT
  _50 = ans.rd_length;
  if (_50 == 4)
    goto <bb 39>; [20.24%]
  else
    goto <bb 41>; [79.76%]

  <bb 39> [local count: 1189012]:
  _51 = pkt_136(D)->pbuf;
  _52 = ans.rd_offset;
  _53 = pkt_136(D)->netif;
  _54 = &_53->ip_addr.u_addr.ip4;
  _56 = pbuf_memcmp (_51, _52, _54, 4);
  if (_56 == 0)
    goto <bb 40>; [50.00%]
  else
    goto <bb 41>; [50.00%]

  <bb 40> [local count: 594506]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _57 = reply.host_replies;
  _58 = _57 & 254;
  reply.host_replies = _58;

  <bb 41> [local count: 58922399]:
  # i_200 = PHI <0(25), 0(26), 0(36), 0(39), 0(42), 0(43), 0(44), 0(45), 0(38), 0(40)>
  goto <bb 77>; [100.00%]

  <bb 42> [local count: 5874563]:
  # DEBUG BEGIN_STMT
  _59 = match_144 & 4;
  if (_59 != 0)
    goto <bb 43>; [50.00%]
  else
    goto <bb 41>; [50.00%]

  <bb 43> [local count: 2937282]:
  # DEBUG BEGIN_STMT
  _60 = ans.rd_length;
  if (_60 == 16)
    goto <bb 44>; [20.24%]
  else
    goto <bb 41>; [79.76%]

  <bb 44> [local count: 594506]:
  _61 = pkt_136(D)->pbuf;
  _62 = ans.rd_offset;
  _63 = pkt_136(D)->netif;
  _64 = &_63->ip6_addr[0].u_addr.ip6;
  _66 = pbuf_memcmp (_61, _62, _64, 16);
  if (_66 == 0)
    goto <bb 45>; [50.00%]
  else
    goto <bb 41>; [50.00%]

  <bb 45> [local count: 297253]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _67 = reply.host_replies;
  _68 = _67 & 251;
  reply.host_replies = _68;
  goto <bb 41>; [100.00%]

  <bb 46> [local count: 58922399]:
  # DEBUG BEGIN_STMT
  service_161 = mdns_137->services[0];
  # DEBUG service => service_161
  # DEBUG BEGIN_STMT
  if (service_161 == 0B)
    goto <bb 47>; [30.00%]
  else
    goto <bb 48>; [70.00%]

  <bb 47> [local count: 17676720]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by continue predictor.
  goto <bb 76>; [100.00%]

  <bb 48> [local count: 41245680]:
  # DEBUG BEGIN_STMT
  _69 = reply.serv_replies[0];
  _70 = (int) _69;
  _71 = check_service (service_161, &ans.info);
  match_163 = _70 & _71;
  # DEBUG match => match_163
  # DEBUG BEGIN_STMT
  if (match_163 != 0)
    goto <bb 49>; [50.00%]
  else
    goto <bb 76>; [50.00%]

  <bb 49> [local count: 20622840]:
  _72 = ans.ttl;
  _73 = service_161->dns_ttl;
  _74 = _73 >> 1;
  if (_72 > _74)
    goto <bb 50>; [50.00%]
  else
    goto <bb 76>; [50.00%]

  <bb 50> [local count: 10311420]:
  # DEBUG BEGIN_STMT
  _75 = ans.info.type;
  if (_75 == 12)
    goto <bb 51>; [20.24%]
  else
    goto <bb 61>; [79.76%]

  <bb 51> [local count: 2087031]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _76 = pkt_136(D)->pbuf;
  _77 = ans.rd_offset;
  len_189 = mdns_readname (_76, _77, &known_ans);
  # DEBUG len => len_189
  # DEBUG BEGIN_STMT
  if (len_189 != 65535)
    goto <bb 52>; [66.00%]
  else
    goto <bb 60>; [34.00%]

  <bb 52> [local count: 1377441]:
  # DEBUG BEGIN_STMT
  _78 = match_163 & 16;
  if (_78 != 0)
    goto <bb 53>; [33.00%]
  else
    goto <bb 56>; [67.00%]

  <bb 53> [local count: 454555]:
  # DEBUG BEGIN_STMT
  res_191 = mdns_build_service_domain (&my_ans, service_161, 0);
  # DEBUG res => res_191
  # DEBUG BEGIN_STMT
  if (res_191 == 0)
    goto <bb 54>; [33.00%]
  else
    goto <bb 56>; [67.00%]

  <bb 54> [local count: 150003]:
  _79 = mdns_domain_eq (&known_ans, &my_ans);
  if (_79 != 0)
    goto <bb 55>; [50.00%]
  else
    goto <bb 56>; [50.00%]

  <bb 55> [local count: 75002]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _80 = reply.serv_replies[0];
  _81 = _80 & 239;
  reply.serv_replies[0] = _81;

  <bb 56> [local count: 1377441]:
  # DEBUG BEGIN_STMT
  _82 = match_163 & 32;
  if (_82 != 0)
    goto <bb 57>; [33.00%]
  else
    goto <bb 60>; [67.00%]

  <bb 57> [local count: 454555]:
  # DEBUG BEGIN_STMT
  res_195 = mdns_build_service_domain (&my_ans, service_161, 1);
  # DEBUG res => res_195
  # DEBUG BEGIN_STMT
  if (res_195 == 0)
    goto <bb 58>; [33.00%]
  else
    goto <bb 60>; [67.00%]

  <bb 58> [local count: 150003]:
  _83 = mdns_domain_eq (&known_ans, &my_ans);
  if (_83 != 0)
    goto <bb 59>; [50.00%]
  else
    goto <bb 60>; [50.00%]

  <bb 59> [local count: 75002]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _84 = reply.serv_replies[0];
  _85 = _84 & 223;
  reply.serv_replies[0] = _85;

  <bb 60> [local count: 2087031]:
  known_ans ={v} {CLOBBER};
  my_ans ={v} {CLOBBER};
  goto <bb 76>; [100.00%]

  <bb 61> [local count: 8224389]:
  # DEBUG BEGIN_STMT
  _86 = match_163 & 64;
  if (_86 != 0)
    goto <bb 62>; [33.00%]
  else
    goto <bb 72>; [67.00%]

  <bb 62> [local count: 2714048]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  read_pos_167 = ans.rd_offset;
  # DEBUG read_pos => read_pos_167
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _87 = pkt_136(D)->pbuf;
  len_169 = pbuf_copy_partial (_87, &field16, 2, read_pos_167);
  # DEBUG len => len_169
  # DEBUG BEGIN_STMT
  if (len_169 != 2)
    goto <bb 71>; [79.76%]
  else
    goto <bb 63>; [20.24%]

  <bb 63> [local count: 549323]:
  field16.72_88 = field16;
  _89 = lwip_htons (field16.72_88);
  if (_89 != 0)
    goto <bb 71>; [67.00%]
  else
    goto <bb 64>; [33.00%]

  <bb 64> [local count: 181277]:
  # DEBUG BEGIN_STMT
  read_pos_171 = read_pos_167 + 2;
  # DEBUG read_pos => read_pos_171
  # DEBUG BEGIN_STMT
  _90 = pkt_136(D)->pbuf;
  len_173 = pbuf_copy_partial (_90, &field16, 2, read_pos_171);
  # DEBUG len => len_173
  # DEBUG BEGIN_STMT
  if (len_173 != 2)
    goto <bb 71>; [79.76%]
  else
    goto <bb 65>; [20.24%]

  <bb 65> [local count: 36690]:
  field16.73_91 = field16;
  _92 = lwip_htons (field16.73_91);
  if (_92 != 0)
    goto <bb 71>; [67.00%]
  else
    goto <bb 66>; [33.00%]

  <bb 66> [local count: 12108]:
  # DEBUG BEGIN_STMT
  read_pos_175 = read_pos_171 + 2;
  # DEBUG read_pos => read_pos_175
  # DEBUG BEGIN_STMT
  _93 = pkt_136(D)->pbuf;
  len_177 = pbuf_copy_partial (_93, &field16, 2, read_pos_175);
  # DEBUG len => len_177
  # DEBUG BEGIN_STMT
  if (len_177 != 2)
    goto <bb 71>; [79.76%]
  else
    goto <bb 67>; [20.24%]

  <bb 67> [local count: 2451]:
  field16.74_94 = field16;
  _95 = lwip_htons (field16.74_94);
  _96 = service_161->port;
  if (_95 != _96)
    goto <bb 71>; [79.76%]
  else
    goto <bb 68>; [20.24%]

  <bb 68> [local count: 496]:
  # DEBUG BEGIN_STMT
  read_pos_179 = read_pos_175 + 2;
  # DEBUG read_pos => read_pos_179
  # DEBUG BEGIN_STMT
  _97 = pkt_136(D)->pbuf;
  len_181 = mdns_readname (_97, read_pos_179, &known_ans);
  # DEBUG len => len_181
  # DEBUG BEGIN_STMT
  mdns_build_host_domain (&my_ans, mdns_137);
  # DEBUG BEGIN_STMT
  if (len_181 == 65535)
    goto <bb 71>; [51.12%]
  else
    goto <bb 69>; [48.88%]

  <bb 69> [local count: 242]:
  _98 = mdns_domain_eq (&known_ans, &my_ans);
  if (_98 == 0)
    goto <bb 71>; [50.00%]
  else
    goto <bb 70>; [50.00%]

  <bb 70> [local count: 121]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _99 = reply.serv_replies[0];
  _100 = _99 & 191;
  reply.serv_replies[0] = _100;

  <bb 71> [local count: 2714048]:
  # DEBUG BEGIN_STMT
  field16 ={v} {CLOBBER};
  known_ans ={v} {CLOBBER};
  my_ans ={v} {CLOBBER};
  goto <bb 76>; [100.00%]

  <bb 72> [local count: 5510340]:
  # DEBUG BEGIN_STMT
  _101 = match_163 & 128;
  if (_101 != 0)
    goto <bb 73>; [33.00%]
  else
    goto <bb 76>; [67.00%]

  <bb 73> [local count: 1818412]:
  # DEBUG BEGIN_STMT
  mdns_prepare_txtdata (service_161);
  # DEBUG BEGIN_STMT
  _102 = service_161->txtdata.length;
  _103 = ans.rd_length;
  if (_102 == _103)
    goto <bb 74>; [20.24%]
  else
    goto <bb 76>; [79.76%]

  <bb 74> [local count: 368047]:
  _104 = pkt_136(D)->pbuf;
  _105 = ans.rd_offset;
  _106 = &service_161->txtdata.name;
  _107 = pbuf_memcmp (_104, _105, _106, _103);
  if (_107 == 0)
    goto <bb 75>; [50.00%]
  else
    goto <bb 76>; [50.00%]

  <bb 75> [local count: 184023]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _108 = reply.serv_replies[0];
  _109 = _108 & 127;
  reply.serv_replies[0] = _109;

  <bb 76> [local count: 58922399]:
  # i_118 = PHI <1(49), 1(48), 1(47), 1(75), 1(74), 1(73), 1(72), 1(71), 1(60)>

  <bb 77> [local count: 117844799]:
  # i_116 = PHI <i_200(41), i_118(76)>
  # DEBUG i => i_116
  # DEBUG BEGIN_STMT
  if (i_116 == 0)
    goto <bb 46>; [50.00%]
  else
    goto <bb 78>; [50.00%]

  <bb 78> [local count: 58922399]:
  ans ={v} {CLOBBER};
  rev_v6 ={v} {CLOBBER};

  <bb 79> [local count: 176733548]:

  <bb 80> [local count: 197904368]:
  # DEBUG BEGIN_STMT
  _110 = pkt_136(D)->answers_left;
  if (_110 != 0)
    goto <bb 20>; [94.50%]
  else
    goto <bb 81>; [5.50%]

  <bb 81> [local count: 10884740]:
  # DEBUG BEGIN_STMT
  mdns_send_outpacket (&reply, 132);

  <bb 82> [local count: 24412983]:
cleanup:
  # DEBUG BEGIN_STMT
  _111 = reply.pbuf;
  if (_111 != 0B)
    goto <bb 83>; [53.47%]
  else
    goto <bb 84>; [46.53%]

  <bb 83> [local count: 13053622]:
  # DEBUG BEGIN_STMT
  pbuf_free (_111);
  # DEBUG BEGIN_STMT

  <bb 84> [local count: 24412983]:
  reply ={v} {CLOBBER};
  goto <bb 86>; [100.00%]

  <bb 85> [local count: 111371717]:
  reply ={v} {CLOBBER};

  <bb 86> [local count: 135784700]:
  return;

}



;; Function mdns_recv (mdns_recv, funcdef_no=37, decl_uid=7758, cgraph_uid=38, symbol_order=44)

Modification phase of node mdns_recv/44
mdns_recv (void * arg, struct udp_pcb * pcb, struct pbuf * p, const struct ip_addr_t * addr, u16_t port)
{
  struct netif * recv_netif;
  struct mdns_packet packet;
  struct dns_hdr hdr;
  unsigned char mdns_netif_client_id.53_1;
  int _2;
  void * _3;
  short unsigned int _4;
  unsigned char _5;
  unsigned char _6;
  short unsigned int _7;
  short unsigned int _8;
  short unsigned int _9;
  short unsigned int _10;
  short unsigned int _11;
  short unsigned int _12;
  short unsigned int _13;
  short unsigned int _14;
  short unsigned int _15;
  short unsigned int _16;
  short unsigned int _17;
  short unsigned int _18;
  unsigned char _19;
  long unsigned int _20;
  long unsigned int _21;
  long unsigned int _22;
  long unsigned int _23;
  long unsigned int _24;
  unsigned char _25;
  signed char _26;
  int iftmp.56_27;
  unsigned char _33;
  _Bool iftmp.55_54;
  _Bool iftmp.58_56;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  recv_netif_32 = ip_data.current_input_netif;
  # DEBUG recv_netif => recv_netif_32
  # DEBUG BEGIN_STMT
  # DEBUG offset => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mdns_netif_client_id.53_1 = mdns_netif_client_id;
  _2 = (int) mdns_netif_client_id.53_1;
  _3 = recv_netif_32->client_data[_2];
  if (_3 == 0B)
    goto <bb 3>; [30.95%]
  else
    goto <bb 4>; [69.05%]

  <bb 3> [local count: 332323094]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 23>; [100.00%]

  <bb 4> [local count: 741418729]:
  # DEBUG BEGIN_STMT
  _4 = pbuf_copy_partial (p_34(D), &hdr, 12, 0);
  if (_4 <= 11)
    goto <bb 5>; [34.00%]
  else
    goto <bb 6>; [66.00%]

  <bb 5> [local count: 252082367]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 23>; [100.00%]

  <bb 6> [local count: 489336360]:
  # DEBUG BEGIN_STMT
  # DEBUG offset => 12
  # DEBUG BEGIN_STMT
  _5 = hdr.flags1;
  _6 = _5 >> 3;
  _33 = _6 & 15;
  if (_33 != 0)
    goto <bb 7>; [51.12%]
  else
    goto <bb 8>; [48.88%]

  <bb 7> [local count: 250148747]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 23>; [100.00%]

  <bb 8> [local count: 239187613]:
  # DEBUG BEGIN_STMT
  memset (&MEM[(void *)&packet + 24B], 0, 24);
  # DEBUG BEGIN_STMT
  memcpy (&packet.source_addr, addr_37(D), 24);
  # DEBUG BEGIN_STMT
  packet.source_port = port_39(D);
  # DEBUG BEGIN_STMT
  packet.netif = recv_netif_32;
  # DEBUG BEGIN_STMT
  packet.pbuf = p_34(D);
  # DEBUG BEGIN_STMT
  packet.parse_offset = 12;
  # DEBUG BEGIN_STMT
  _7 = hdr.id;
  _8 = lwip_htons (_7);
  packet.tx_id = _8;
  # DEBUG BEGIN_STMT
  _9 = hdr.numquestions;
  _10 = lwip_htons (_9);
  packet.questions_left = _10;
  packet.questions = _10;
  # DEBUG BEGIN_STMT
  _11 = hdr.numanswers;
  _12 = lwip_htons (_11);
  _13 = hdr.numauthrr;
  _14 = lwip_htons (_13);
  _15 = _12 + _14;
  _16 = hdr.numextrarr;
  _17 = lwip_htons (_16);
  _18 = _15 + _17;
  packet.answers_left = _18;
  packet.answers = _18;
  # DEBUG BEGIN_STMT
  _19 = ip_data.current_iphdr_dest.type;
  if (_19 == 6)
    goto <bb 9>; [34.00%]
  else
    goto <bb 16>; [66.00%]

  <bb 9> [local count: 81323788]:
  # DEBUG BEGIN_STMT
  _20 = ip_data.current_iphdr_dest.u_addr.ip6.addr[0];
  if (_20 != 767)
    goto <bb 14>; [66.00%]
  else
    goto <bb 10>; [34.00%]

  <bb 10> [local count: 27650088]:
  _21 = ip_data.current_iphdr_dest.u_addr.ip6.addr[1];
  if (_21 != 0)
    goto <bb 14>; [50.00%]
  else
    goto <bb 11>; [50.00%]

  <bb 11> [local count: 13825044]:
  _22 = ip_data.current_iphdr_dest.u_addr.ip6.addr[2];
  if (_22 != 0)
    goto <bb 14>; [50.00%]
  else
    goto <bb 12>; [50.00%]

  <bb 12> [local count: 6912522]:
  _23 = ip_data.current_iphdr_dest.u_addr.ip6.addr[3];
  if (_23 != 4211081216)
    goto <bb 14>; [66.00%]
  else
    goto <bb 13>; [34.00%]

  <bb 13> [local count: 2350257]:

  <bb 14> [local count: 81323788]:
  # iftmp.56_27 = PHI <1(10), 0(13), 1(9), 1(12), 1(11)>
  iftmp.55_54 = (_Bool) iftmp.56_27;
  if (iftmp.55_54 != 0)
    goto <bb 15>; [50.00%]
  else
    goto <bb 16>; [50.00%]

  <bb 15> [local count: 40661894]:
  # DEBUG BEGIN_STMT
  packet.recv_unicast = 1;

  <bb 16> [local count: 239187613]:
  # DEBUG BEGIN_STMT
  if (_19 != 6)
    goto <bb 17>; [66.00%]
  else
    goto <bb 20>; [34.00%]

  <bb 17> [local count: 157863825]:
  # DEBUG BEGIN_STMT
  if (_19 == 0)
    goto <bb 18>; [50.00%]
  else
    goto <bb 19>; [50.00%]

  <bb 18> [local count: 78931912]:
  _24 = ip_data.current_iphdr_dest.u_addr.ip4.addr;
  iftmp.58_56 = _24 != 4211081440;
  if (iftmp.58_56 != 0)
    goto <bb 19>; [50.00%]
  else
    goto <bb 20>; [50.00%]

  <bb 19> [local count: 118397868]:
  # DEBUG BEGIN_STMT
  packet.recv_unicast = 1;

  <bb 20> [local count: 239187613]:
  # DEBUG BEGIN_STMT
  _25 = hdr.flags1;
  _26 = (signed char) _25;
  if (_26 < 0)
    goto <bb 21>; [41.00%]
  else
    goto <bb 22>; [59.00%]

  <bb 21> [local count: 98066921]:
  # DEBUG BEGIN_STMT
  mdns_handle_response (&packet);
  goto <bb 23>; [100.00%]

  <bb 22> [local count: 141120692]:
  # DEBUG BEGIN_STMT
  mdns_handle_question (&packet);

  <bb 23> [local count: 1073741824]:
dealloc:
  # DEBUG BEGIN_STMT
  pbuf_free (p_34(D));
  hdr ={v} {CLOBBER};
  packet ={v} {CLOBBER};
  return;

}



;; Function mdns_resp_remove_netif (mdns_resp_remove_netif, funcdef_no=41, decl_uid=6828, cgraph_uid=42, symbol_order=48)

Modification phase of node mdns_resp_remove_netif/48
mdns_resp_remove_netif (struct netif * netif)
{
  struct mdns_service * service;
  struct mdns_host * mdns;
  int i;
  unsigned char mdns_netif_client_id.6_1;
  int _2;
  unsigned char _3;
  unsigned char mdns_netif_client_id.7_4;
  int _5;
  err_t _7;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (netif_13(D) == 0B)
    goto <bb 14>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 14> [local count: 107374]:

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
  mdns_netif_client_id.6_1 = mdns_netif_client_id;
  _2 = (int) mdns_netif_client_id.6_1;
  mdns_15 = netif_13(D)->client_data[_2];
  # DEBUG mdns => mdns_15
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (mdns_15 == 0B)
    goto <bb 13>; [0.45%]
  else
    goto <bb 5>; [99.55%]

  <bb 5> [local count: 249412]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = mdns_15->probing_state;
  if (_3 == 1)
    goto <bb 6>; [20.24%]
  else
    goto <bb 7>; [79.76%]

  <bb 6> [local count: 50481]:
  # DEBUG BEGIN_STMT
  sys_untimeout (mdns_probe, netif_13(D));

  <bb 7> [local count: 249412]:
  # i_24 = PHI <0(6), 0(5)>
  goto <bb 10>; [100.00%]

  <bb 8> [local count: 4285350]:
  # DEBUG BEGIN_STMT
  service_22 = mdns_15->services[0];
  # DEBUG service => service_22
  # DEBUG BEGIN_STMT
  if (service_22 != 0B)
    goto <bb 9>; [67.00%]
  else
    goto <bb 16>; [33.00%]

  <bb 16> [local count: 1414165]:
  goto <bb 11>; [100.00%]

  <bb 9> [local count: 2871185]:
  # DEBUG BEGIN_STMT
  mem_free (service_22);

  <bb 10> [local count: 3120596]:
  # i_9 = PHI <i_24(7), 1(9)>

  <bb 11> [local count: 4534762]:
  # i_6 = PHI <i_9(10), 1(16)>
  # DEBUG i => i_6
  # DEBUG BEGIN_STMT
  if (i_6 == 0)
    goto <bb 8>; [94.50%]
  else
    goto <bb 12>; [5.50%]

  <bb 12> [local count: 249412]:
  # DEBUG BEGIN_STMT
  igmp_leavegroup_netif (netif_13(D), &v4group.u_addr.ip4);
  # DEBUG BEGIN_STMT
  mld6_leavegroup_netif (netif_13(D), &v6group.u_addr.ip6);
  # DEBUG BEGIN_STMT
  mem_free (mdns_15);
  # DEBUG BEGIN_STMT
  mdns_netif_client_id.7_4 = mdns_netif_client_id;
  _5 = (int) mdns_netif_client_id.7_4;
  netif_13(D)->client_data[_5] = 0B;
  # DEBUG BEGIN_STMT

  <bb 13> [local count: 250539]:
  # _7 = PHI <-6(4), 0(12)>
  return _7;

}



;; Function mdns_resp_del_service (mdns_resp_del_service, funcdef_no=44, decl_uid=6843, cgraph_uid=45, symbol_order=51)

Modification phase of node mdns_resp_del_service/51
mdns_resp_del_service (struct netif * netif, s8_t slot)
{
  struct mdns_host * mdns;
  unsigned char mdns_netif_client_id.44_1;
  int _2;
  struct mdns_service * _3;
  err_t _4;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (netif_7(D) == 0B)
    goto <bb 9>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 9> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 10> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mdns_netif_client_id.44_1 = mdns_netif_client_id;
  _2 = (int) mdns_netif_client_id.44_1;
  mdns_9 = netif_7(D)->client_data[_2];
  # DEBUG mdns => mdns_9
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (mdns_9 == 0B)
    goto <bb 8>; [0.45%]
  else
    goto <bb 5>; [99.55%]

  <bb 5> [local count: 249412]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (slot_10(D) != 0)
    goto <bb 8>; [1.04%]
  else
    goto <bb 6>; [98.96%]

  <bb 6> [local count: 246818]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = mdns_9->services[0];
  if (_3 == 0B)
    goto <bb 8>; [0.91%]
  else
    goto <bb 7>; [99.09%]

  <bb 7> [local count: 244572]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG srv => _3
  # DEBUG BEGIN_STMT
  mdns_9->services[0] = 0B;
  # DEBUG BEGIN_STMT
  mem_free (_3);
  # DEBUG BEGIN_STMT

  <bb 8> [local count: 250539]:
  # _4 = PHI <-6(4), -6(5), -6(6), 0(7)>
  return _4;

}



;; Function mdns_resp_add_service_txtitem (mdns_resp_add_service_txtitem, funcdef_no=46, decl_uid=6851, cgraph_uid=47, symbol_order=53)

Modification phase of node mdns_resp_add_service_txtitem/53
mdns_resp_add_service_txtitem (struct mdns_service * service, const char * txt, u8_t txt_len)
{
  struct mdns_domain * _1;
  err_t _8;

  <bb 2> [local count: 230763]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (service_3(D) == 0B)
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
  _1 = &service_3(D)->txtdata;
  _8 = mdns_domain_add_label (_1, txt_5(D), txt_len_6(D));
  return _8;

}



;; Function mdns_resp_announce (mdns_resp_announce, funcdef_no=47, decl_uid=6855, cgraph_uid=48, symbol_order=54)

Modification phase of node mdns_resp_announce/54
mdns_resp_announce (struct netif * netif)
{
  struct mdns_host * mdns;
  unsigned char mdns_netif_client_id.46_1;
  int _2;
  unsigned char _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (netif_5(D) == 0B)
    goto <bb 6>; [18.09%]
  else
    goto <bb 3>; [81.91%]

  <bb 3> [local count: 879501929]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mdns_netif_client_id.46_1 = mdns_netif_client_id;
  _2 = (int) mdns_netif_client_id.46_1;
  mdns_7 = netif_5(D)->client_data[_2];
  # DEBUG mdns => mdns_7
  # DEBUG BEGIN_STMT
  if (mdns_7 == 0B)
    goto <bb 6>; [18.09%]
  else
    goto <bb 4>; [81.91%]

  <bb 4> [local count: 720400030]:
  # DEBUG BEGIN_STMT
  _3 = mdns_7->probing_state;
  if (_3 == 2)
    goto <bb 5>; [20.24%]
  else
    goto <bb 6>; [79.76%]

  <bb 5> [local count: 145808965]:
  mdns_resp_announce.part.0 (netif_5(D));

  <bb 6> [local count: 1073741824]:
  return;

}



;; Function mdns_probe (mdns_probe, funcdef_no=39, decl_uid=7379, cgraph_uid=40, symbol_order=46)

Modification phase of node mdns_probe/46
mdns_probe (void * arg)
{
  struct mdns_host * mdns;
  unsigned char mdns_netif_client_id.8_1;
  int _2;
  unsigned char _3;
  void (*<T709>) (struct netif *, u8_t) mdns_name_result_cb.9_4;
  long unsigned int _7;
  signed char _8;
  signed char _9;
  unsigned char _10;
  unsigned char _11;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG netif => arg_13(D)
  # DEBUG BEGIN_STMT
  mdns_netif_client_id.8_1 = mdns_netif_client_id;
  _2 = (int) mdns_netif_client_id.8_1;
  mdns_15 = MEM[(struct netif *)arg_13(D)].client_data[_2];
  # DEBUG mdns => mdns_15
  # DEBUG BEGIN_STMT
  _3 = mdns_15->probes_sent;
  if (_3 > 2)
    goto <bb 3>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  mdns_15->probing_state = 2;
  # DEBUG BEGIN_STMT
  mdns_resp_announce (arg_13(D));
  # DEBUG BEGIN_STMT
  mdns_name_result_cb.9_4 = mdns_name_result_cb;
  if (mdns_name_result_cb.9_4 != 0B)
    goto <bb 4>; [70.00%]
  else
    goto <bb 10>; [30.00%]

  <bb 4> [local count: 248034361]:
  # DEBUG BEGIN_STMT
  mdns_name_result_cb.9_4 (arg_13(D), 1);
  goto <bb 10>; [100.00%]

  <bb 5> [local count: 719407023]:
  # DEBUG BEGIN_STMT
  _7 = MEM[(const struct ip4_addr_t *)arg_13(D) + 4B].addr;
  if (_7 != 0)
    goto <bb 6>; [33.00%]
  else
    goto <bb 9>; [67.00%]

  <bb 6> [local count: 237404317]:
  _8 = mdns_send_probe (arg_13(D), &ip_addr_any);
  if (_8 == 0)
    goto <bb 7>; [33.00%]
  else
    goto <bb 9>; [67.00%]

  <bb 7> [local count: 78343425]:
  # DEBUG BEGIN_STMT
  _9 = mdns_send_probe (arg_13(D), &ip6_addr_any);
  if (_9 == 0)
    goto <bb 8>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 8> [local count: 39171712]:
  # DEBUG BEGIN_STMT
  _10 = mdns_15->probes_sent;
  _11 = _10 + 1;
  mdns_15->probes_sent = _11;

  <bb 9> [local count: 719407025]:
  mdns_probe.part.0 (arg_13(D));

  <bb 10> [local count: 1073741824]:
  return;

}



;; Function mdns_resp_register_name_result_cb (mdns_resp_register_name_result_cb, funcdef_no=48, decl_uid=6822, cgraph_uid=49, symbol_order=55)

Modification phase of node mdns_resp_register_name_result_cb/55
mdns_resp_register_name_result_cb (void (*mdns_name_result_cb_t) (struct netif *, u8_t) cb)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  mdns_name_result_cb = cb_2(D);
  return;

}



;; Function mdns_resp_restart (mdns_resp_restart, funcdef_no=49, decl_uid=6853, cgraph_uid=50, symbol_order=56)

Modification phase of node mdns_resp_restart/56
mdns_resp_restart (struct netif * netif)
{
  struct mdns_host * mdns;
  unsigned char mdns_netif_client_id.48_1;
  int _2;
  unsigned char _3;
  int _4;
  long unsigned int _5;
  long unsigned int _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (netif_9(D) == 0B)
    goto <bb 7>; [18.09%]
  else
    goto <bb 3>; [81.91%]

  <bb 3> [local count: 879501929]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mdns_netif_client_id.48_1 = mdns_netif_client_id;
  _2 = (int) mdns_netif_client_id.48_1;
  mdns_11 = netif_9(D)->client_data[_2];
  # DEBUG mdns => mdns_11
  # DEBUG BEGIN_STMT
  if (mdns_11 == 0B)
    goto <bb 7>; [18.09%]
  else
    goto <bb 4>; [81.91%]

  <bb 4> [local count: 720400030]:
  # DEBUG BEGIN_STMT
  _3 = mdns_11->probing_state;
  if (_3 == 1)
    goto <bb 5>; [20.24%]
  else
    goto <bb 6>; [79.76%]

  <bb 5> [local count: 145808966]:
  # DEBUG BEGIN_STMT
  sys_untimeout (mdns_probe, netif_9(D));

  <bb 6> [local count: 720400030]:
  # DEBUG BEGIN_STMT
  mdns_11->probes_sent = 0;
  # DEBUG BEGIN_STMT
  mdns_11->probing_state = 1;
  # DEBUG BEGIN_STMT
  _4 = rand ();
  _5 = (long unsigned int) _4;
  _6 = _5 % 250;
  sys_timeout (_6, mdns_probe, netif_9(D));

  <bb 7> [local count: 1073741824]:
  return;

}



;; Function mdns_resp_add_netif (mdns_resp_add_netif, funcdef_no=40, decl_uid=6826, cgraph_uid=41, symbol_order=47)

Modification phase of node mdns_resp_add_netif/47
mdns_resp_add_netif (struct netif * netif, const char * hostname, u32_t dns_ttl)
{
  struct mdns_host * mdns;
  err_t res;
  unsigned int _1;
  unsigned char mdns_netif_client_id.2_2;
  int _3;
  void * _4;
  unsigned char mdns_netif_client_id.3_5;
  int _6;
  char[64] * _7;
  unsigned int _8;
  unsigned char mdns_netif_client_id.5_9;
  int _10;
  err_t _12;
  unsigned int iftmp.4_22;

  <bb 2> [local count: 132001]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (netif_16(D) == 0B)
    goto <bb 13>; [0.45%]
  else
    goto <bb 3>; [99.55%]

  <bb 3> [local count: 131407]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = strlen (hostname_18(D));
  if (_1 > 63)
    goto <bb 13>; [1.04%]
  else
    goto <bb 4>; [98.96%]

  <bb 4> [local count: 130040]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mdns_netif_client_id.2_2 = mdns_netif_client_id;
  _3 = (int) mdns_netif_client_id.2_2;
  _4 = netif_16(D)->client_data[_3];
  if (_4 != 0B)
    goto <bb 14>; [82.57%]
  else
    goto <bb 6>; [17.43%]

  <bb 14> [local count: 107374]:

  <bb 5> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 15> [local count: 1073741824]:
  goto <bb 5>; [100.00%]

  <bb 6> [local count: 22666]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mdns_20 = mem_calloc (1, 76);
  # DEBUG mdns => mdns_20
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (mdns_20 == 0B)
    goto <bb 13>; [0.91%]
  else
    goto <bb 7>; [99.09%]

  <bb 7> [local count: 22460]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mdns_netif_client_id.3_5 = mdns_netif_client_id;
  _6 = (int) mdns_netif_client_id.3_5;
  netif_16(D)->client_data[_6] = mdns_20;
  # DEBUG BEGIN_STMT
  _7 = &mdns_20->name;
  _8 = strlen (hostname_18(D));
  iftmp.4_22 = MIN_EXPR <_8, 63>;
  memcpy (_7, hostname_18(D), iftmp.4_22);
  # DEBUG BEGIN_STMT
  mdns_20->dns_ttl = dns_ttl_24(D);
  # DEBUG BEGIN_STMT
  mdns_20->probes_sent = 0;
  # DEBUG BEGIN_STMT
  mdns_20->probing_state = 0;
  # DEBUG BEGIN_STMT
  res_29 = igmp_joingroup_netif (netif_16(D), &v4group.u_addr.ip4);
  # DEBUG res => res_29
  # DEBUG BEGIN_STMT
  if (res_29 != 0)
    goto <bb 8>; [51.12%]
  else
    goto <bb 9>; [48.88%]

  <bb 8> [local count: 11481]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 12>; [100.00%]

  <bb 9> [local count: 10978]:
  # DEBUG BEGIN_STMT
  res_31 = mld6_joingroup_netif (netif_16(D), &v6group.u_addr.ip6);
  # DEBUG res => res_31
  # DEBUG BEGIN_STMT
  if (res_31 != 0)
    goto <bb 10>; [51.12%]
  else
    goto <bb 11>; [48.88%]

  <bb 10> [local count: 5612]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 12>; [100.00%]

  <bb 11> [local count: 5366]:
  # DEBUG BEGIN_STMT
  mdns_resp_restart (netif_16(D));
  # DEBUG BEGIN_STMT
  goto <bb 13>; [100.00%]

  <bb 12> [local count: 17094]:
  # res_11 = PHI <res_29(8), res_31(10)>
cleanup:
  # DEBUG res => res_11
  # DEBUG BEGIN_STMT
  mem_free (mdns_20);
  # DEBUG BEGIN_STMT
  mdns_netif_client_id.5_9 = mdns_netif_client_id;
  _10 = (int) mdns_netif_client_id.5_9;
  netif_16(D)->client_data[_10] = 0B;
  # DEBUG BEGIN_STMT

  <bb 13> [local count: 24627]:
  # _12 = PHI <-6(2), -6(3), -1(6), 0(11), res_11(12)>
  return _12;

}



;; Function mdns_resp_rename_netif (mdns_resp_rename_netif, funcdef_no=42, decl_uid=6831, cgraph_uid=43, symbol_order=49)

Modification phase of node mdns_resp_rename_netif/49
mdns_resp_rename_netif (struct netif * netif, const char * hostname)
{
  size_t len;
  struct mdns_host * mdns;
  unsigned char mdns_netif_client_id.38_1;
  int _2;
  char[64] * _3;
  unsigned int _4;
  err_t _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  len_9 = strlen (hostname_8(D));
  # DEBUG len => len_9
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (netif_10(D) == 0B)
    goto <bb 6>; [0.45%]
  else
    goto <bb 3>; [99.55%]

  <bb 3> [local count: 1068909987]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (len_9 > 63)
    goto <bb 6>; [1.04%]
  else
    goto <bb 4>; [98.96%]

  <bb 4> [local count: 1057793323]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mdns_netif_client_id.38_1 = mdns_netif_client_id;
  _2 = (int) mdns_netif_client_id.38_1;
  mdns_11 = netif_10(D)->client_data[_2];
  # DEBUG mdns => mdns_11
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (mdns_11 == 0B)
    goto <bb 6>; [0.91%]
  else
    goto <bb 5>; [99.09%]

  <bb 5> [local count: 1048167403]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = &mdns_11->name;
  _4 = len_9;
  memcpy (_3, hostname_8(D), _4);
  # DEBUG BEGIN_STMT
  mdns_11->name[len_9] = 0;
  # DEBUG BEGIN_STMT
  mdns_resp_restart (netif_10(D));
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
  # _5 = PHI <-6(2), -6(3), -6(4), 0(5)>
  return _5;

}



;; Function mdns_resp_add_service (mdns_resp_add_service, funcdef_no=43, decl_uid=6840, cgraph_uid=44, symbol_order=50)

Modification phase of node mdns_resp_add_service/50
mdns_resp_add_service (struct netif * netif, const char * name, const char * service, mdns_sd_proto proto, u16_t port, u32_t dns_ttl, void (*service_get_txt_fn_t) (struct mdns_service *, void *) txt_fn, void * txt_data)
{
  struct mdns_host * mdns;
  struct mdns_service * srv;
  s8_t slot;
  s8_t i;
  unsigned char mdns_netif_client_id.39_1;
  int _2;
  unsigned int _3;
  unsigned int _4;
  unsigned int iftmp.43_5;
  struct mdns_service * _6;
  unsigned int iftmp.42_7;
  char[64] * _8;
  unsigned int _9;
  char[64] * _10;
  unsigned int _11;
  short unsigned int _12;
  s8_t _15;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG slot => -1
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (netif_18(D) == 0B)
    goto <bb 14>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 14> [local count: 107374]:

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
  mdns_netif_client_id.39_1 = mdns_netif_client_id;
  _2 = (int) mdns_netif_client_id.39_1;
  mdns_20 = netif_18(D)->client_data[_2];
  # DEBUG mdns => mdns_20
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (mdns_20 == 0B)
    goto <bb 13>; [0.45%]
  else
    goto <bb 5>; [99.55%]

  <bb 5> [local count: 249412]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = strlen (name_21(D));
  if (_3 > 63)
    goto <bb 13>; [1.04%]
  else
    goto <bb 6>; [98.96%]

  <bb 6> [local count: 246818]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _4 = strlen (service_22(D));
  if (_4 > 63)
    goto <bb 13>; [1.04%]
  else
    goto <bb 7>; [98.96%]

  <bb 7> [local count: 244251]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (proto_23(D) > 1)
    goto <bb 13>; [1.49%]
  else
    goto <bb 15>; [98.51%]

  <bb 15> [local count: 240612]:
  goto <bb 9>; [100.00%]

  <bb 8> [local count: 228068]:
  # DEBUG BEGIN_STMT
  _6 = mdns_20->services[0];
  if (_6 == 0B)
    goto <bb 10>; [5.50%]
  else
    goto <bb 17>; [94.50%]

  <bb 17> [local count: 215524]:

  <bb 9> [local count: 456136]:
  # i_13 = PHI <0(15), 1(17)>
  # DEBUG i => i_13
  # DEBUG BEGIN_STMT
  if (i_13 == 0)
    goto <bb 8>; [50.00%]
  else
    goto <bb 10>; [50.00%]

  <bb 10> [local count: 240612]:
  # slot_14 = PHI <0(8), -1(9)>
  # DEBUG slot => slot_14
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (slot_14 == -1)
    goto <bb 13>; [1.09%]
  else
    goto <bb 11>; [98.91%]

  <bb 11> [local count: 237989]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  srv_25 = mem_calloc (1, 404);
  # DEBUG srv => srv_25
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (srv_25 == 0B)
    goto <bb 13>; [0.91%]
  else
    goto <bb 12>; [99.09%]

  <bb 12> [local count: 235823]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _8 = &srv_25->name;
  _9 = strlen (name_21(D));
  iftmp.42_7 = MIN_EXPR <_9, 63>;
  memcpy (_8, name_21(D), iftmp.42_7);
  # DEBUG BEGIN_STMT
  _10 = &srv_25->service;
  _11 = strlen (service_22(D));
  iftmp.43_5 = MIN_EXPR <_11, 63>;
  memcpy (_10, service_22(D), iftmp.43_5);
  # DEBUG BEGIN_STMT
  srv_25->txt_fn = txt_fn_28(D);
  # DEBUG BEGIN_STMT
  srv_25->txt_userdata = txt_data_30(D);
  # DEBUG BEGIN_STMT
  _12 = (short unsigned int) proto_23(D);
  srv_25->proto = _12;
  # DEBUG BEGIN_STMT
  srv_25->port = port_33(D);
  # DEBUG BEGIN_STMT
  srv_25->dns_ttl = dns_ttl_35(D);
  # DEBUG BEGIN_STMT
  mdns_20->services[0] = srv_25;
  # DEBUG BEGIN_STMT
  mdns_resp_restart (netif_18(D));
  # DEBUG BEGIN_STMT

  <bb 13> [local count: 250539]:
  # _15 = PHI <-6(4), -6(5), -6(6), -6(7), -1(10), -1(11), 0(12)>
  return _15;

}



;; Function mdns_resp_rename_service (mdns_resp_rename_service, funcdef_no=45, decl_uid=6847, cgraph_uid=46, symbol_order=52)

Modification phase of node mdns_resp_rename_service/52
mdns_resp_rename_service (struct netif * netif, s8_t slot, const char * name)
{
  size_t len;
  struct mdns_host * mdns;
  unsigned char mdns_netif_client_id.45_1;
  int _2;
  struct mdns_service * _3;
  char[64] * _4;
  unsigned int _5;
  err_t _6;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  len_11 = strlen (name_10(D));
  # DEBUG len => len_11
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (netif_12(D) == 0B)
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

  <bb 11> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mdns_netif_client_id.45_1 = mdns_netif_client_id;
  _2 = (int) mdns_netif_client_id.45_1;
  mdns_13 = netif_12(D)->client_data[_2];
  # DEBUG mdns => mdns_13
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (mdns_13 == 0B)
    goto <bb 9>; [0.45%]
  else
    goto <bb 5>; [99.55%]

  <bb 5> [local count: 249412]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (len_11 > 63)
    goto <bb 9>; [1.04%]
  else
    goto <bb 6>; [98.96%]

  <bb 6> [local count: 246818]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (slot_14(D) != 0)
    goto <bb 9>; [1.04%]
  else
    goto <bb 7>; [98.96%]

  <bb 7> [local count: 244251]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = mdns_13->services[0];
  if (_3 == 0B)
    goto <bb 9>; [0.91%]
  else
    goto <bb 8>; [99.09%]

  <bb 8> [local count: 242028]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG srv => _3
  # DEBUG BEGIN_STMT
  _4 = &_3->name;
  _5 = len_11;
  memcpy (_4, name_10(D), _5);
  # DEBUG BEGIN_STMT
  _3->name[len_11] = 0;
  # DEBUG BEGIN_STMT
  mdns_resp_restart (netif_12(D));
  # DEBUG BEGIN_STMT

  <bb 9> [local count: 250539]:
  # _6 = PHI <-6(4), -6(5), -6(6), -6(7), 0(8)>
  return _6;

}



;; Function mdns_resp_init (mdns_resp_init, funcdef_no=50, decl_uid=6820, cgraph_uid=51, symbol_order=57)

Modification phase of node mdns_resp_init/57
mdns_resp_init ()
{
  err_t res;
  struct udp_pcb * _1;
  struct udp_pcb * mdns_pcb.52_2;
  unsigned char _3;

  <bb 2> [local count: 230763]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = udp_new_ip_type (46);
  mdns_pcb = _1;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (_1 == 0B)
    goto <bb 7>; [46.53%]
  else
    goto <bb 4>; [53.47%]

  <bb 7> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 9> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 123389]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1->mcast_ttl = 255;
  # DEBUG BEGIN_STMT
  res_11 = udp_bind (_1, &ip_addr_any_type, 5353);
  # DEBUG res => res_11
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (res_11 != 0)
    goto <bb 8>; [67.00%]
  else
    goto <bb 6>; [33.00%]

  <bb 8> [local count: 82671]:

  <bb 5> [local count: 826707361]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 10> [local count: 826707360]:
  goto <bb 5>; [100.00%]

  <bb 6> [local count: 40718]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mdns_pcb.52_2 = mdns_pcb;
  udp_recv (mdns_pcb.52_2, mdns_recv, 0B);
  # DEBUG BEGIN_STMT
  _3 = netif_alloc_client_data_id ();
  mdns_netif_client_id = _3;
  return;

}


