#include "net.h"
#include "sys_plat.h"
#include "netif_pcap.h"
#include "dbg.h"
#include "nlist.h"

#define DBG_TEST DBG_LEVEL_ERROR

net_err_t netdev_init (void) {
    netif_pcap_open();
    return NET_ERR_OK;
}

typedef struct _tnode_t {
    int id;
    nlist_node_t node;
}tnode_t;

void nlist_test(){
    tnode_t node[8];
    nlist_t list;

    nlist_init(&list);

    for(int i = 0; i < 8; i++){
        node[i].id = i;
        nlist_insert_first(&list,&node[i].node);
    }
    plat_printf("insert first over\n");

    nlist_node_t * p;
    nlist_for_each(p,list){
        tnode_t * tnode = nlist_entry(p,tnode_t,node);
        plat_printf("id:%d\n", tnode->id);
    }

    plat_printf("remove first\n");

    for (int i = 0; i < 8; i++) {
        p = nlist_remove_first(&list);
        plat_printf("id:%d\n", nlist_entry(p, tnode_t, node)->id);
    }


    for (int i = 0; i < 8; i++) {
        nlist_insert_last(&list, &node[i].node);
    }
    plat_printf("insert last\n");

    nlist_for_each(p,list){
        tnode_t * tnode = nlist_entry(p,tnode_t,node);
        plat_printf("id:%d\n", tnode->id);
    }

    plat_printf("remove last\n");
    for (int i = 0; i < 8; i++) {
        nlist_remove_last(&list);
    }
}

void basic_test(){
    nlist_test();
}

int main (void) {

    net_init();
    net_start();

    basic_test();

    //初始化网络接口
    netdev_init();

    while(1){
        sys_sleep(10);
    }
	return 0;
}