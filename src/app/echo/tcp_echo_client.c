//
// Created by 33441 on 2025/10/5.
//
#include "tcp_echo_client.h"
#include<WinSock2.h>
#include "sys_plat.h"

int tcp_echo_client_start(const char * ip, int port){
    plat_printf("tcp echo client, ip: %d, port: %d\n", ip, port);

    SOCKET s = socket(AF_INET,SOCK_STREAM,0);
    if(s < 0) {
        plat_printf("tcp echo client: open socket error");
        return -1;
    }

    struct sockaddr_in server_addr;
    plat_memset(&server_addr,0,sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip);
    server_addr.sin_port = htons(port);
    if(connect(s,(const struct sockaddr *)&server_addr,sizeof(server_addr) < 0)){
        plat_printf("connect error");
        return -1;
    }

    char buf[128];
    plat_printf(">>");
    while(fgets(buf,sizeof(buf),stdin) != NULL){
        if(send(s,buf,plat_strlen(buf),0) <= 0){
            plat_printf("write error");
            return -1;
        }

        plat_memset(buf,0,sizeof(buf));
        int len = recv(s,buf,sizeof(buf) - 1, 0);
        if(len <= 0){
            plat_printf("read error");
            return -1;
        }

        plat_printf("%s", buf);
        plat_printf(">>");

        closesocket(s);
    }

}
