//
// Created by 33441 on 2025/10/7.
//

#include "exmsg.h"
#include "sys_plat.h"

net_err_t exmsg_init (void){
    return NET_ERR_OK;
}

static void work_thread (void * arg) {
    plat_printf("exmsg is running...\n ");
    while(1){
        sys_sleep(1);
    }
}

net_err_t exmsg_start(void){
    //创建核心线程
    sys_thread_t thread = sys_thread_create(work_thread, NULL);
    if (thread == SYS_THREAD_INVALID) {
        return NET_ERR_SYS;
    }
    return NET_ERR_OK;
}
