#include "net.h"
#include "sys_plat.h"
#include "netif_pcap.h"
#include "dbg.h"

#define DBG_TEST DBG_LEVEL_ERROR
net_err_t netdev_init (void) {
    netif_pcap_open();
    return NET_ERR_OK;
}

int main (void) {
    dbg_error(DBG_TEST,"error");
    dbg_waring(DBG_TEST,"waring");
    dbg_assert(1 == 0, "failed");
    net_init();
    net_start();
    netdev_init();

    while(1){
        sys_sleep(10);
    }
	return 0;
}