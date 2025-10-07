#include <stdio.h>
#include "net.h"
#include "sys_plat.h"


int main (void) {
    net_init();
    net_start();
    while(1){
        sys_sleep(10);
    }
	return 0;
}