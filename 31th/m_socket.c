#include "m_socket.h"


void err_handler(char* msg){
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}

int get_sock_fd(void){
	int sock;
	sock = socket(PF_INET, SOCK_STREAM, 0);
	if(sock == -1)
		err_handler("socket() error");
	return sock;
}

void set_serv_addr(si* serv_addr,char* port,char* ip_addr){
	memset(serv_addr, 0, sizeof(*serv_addr));
	serv_addr->sin_family = AF_INET;
	if(ip_addr)
		serv_addr->sin_addr.s_addr = inet_addr(ip_addr);
	else
		serv_addr->sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr->sin_port = htons(atoi(port));
}

void bind_serv(int serv_sock, si serv_addr){
	if(bind(serv_sock, (sap)&serv_addr, sizeof(serv_addr)) == -1)
		err_handler("bind() error");
}

void listen_serv(int serv_sock, int listen_num){
	if(listen(serv_sock, listen_num) == -1)
		err_handler("listen() error");
}

int serv_accept(int serv_sock, si clnt_addr, int* clnt_addr_size){
	int clnt_sock;
	clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_addr, clnt_addr_size);
	if(clnt_sock == -1)
		err_handler("accept() error");
	return clnt_sock;
}

void connect_clnt(int sock, si serv_addr, int serv_addr_size){
	if(connect(sock, (sap)&serv_addr, sizeof(serv_addr)) == -1)
		err_handler("connect() error");
}
