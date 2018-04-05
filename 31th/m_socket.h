#ifndef __M_SOCKET__H__
#define __M_SOCKET__H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
typedef struct sockaddr_in si;
typedef struct sockaddr * sap;

void err_handler(char* msg);

int get_sock_fd(void);
void set_serv_addr(si* serv_addr,char* port,char* ip_addr);
void bind_serv(int serv_sock, si serv_addr);
void listen_serv(int serv_sock, int listen_num);
int serv_accept(int serv_sock, si clnt_addr, int* clnt_addr_size);
void connect_clnt(int sock, si serv_addr, int serv_addr_size);

#endif
