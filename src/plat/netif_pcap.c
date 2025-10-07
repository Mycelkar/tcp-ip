//
// Created by 33441 on 2025/10/7.
//
#include "netif_pcap.h"
#include "sys_plat.h"

void recv_thread(void * arg) {
    plat_printf("recv thread is running...\n");

    while(1){
        sys_sleep(1);
    }
}

void xmit_thread(void * arg) {
    plat_printf("xmit thread is running...\n");

    while(1){
        sys_sleep(1);
    }
}

net_err_t netif_pcap_open (void) {
    sys_thread_create(recv_thread,NULL);
    sys_thread_create(xmit_thread,NULL);
    return NET_ERR_OK;
}