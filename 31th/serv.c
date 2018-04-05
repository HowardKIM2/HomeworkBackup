#include "m_socket.h"
#define LISTEN_NUM 5
int main(int argc, char** argv){
	int serv_sock;
	int clnt_sock;

	si serv_addr;
	si clnt_addr;
	socklen_t clnt_addr_size;

	if(argc != 2){
		printf("use : %s <port>\n",argv[0]);
	}

	serv_sock = get_sock_fd();
	
	set_serv_addr(&serv_addr,argv[1], NULL);
	
	bind_serv(serv_sock, serv_addr);

	listen_serv(serv_sock, LISTEN_NUM);

	clnt_sock = serv_accept(serv_sock, clnt_addr, &clnt_addr_size);

#if 1
	write(clnt_sock, "Test\n", 5);

#endif
	close(clnt_sock);
	close(serv_sock);
	return 0;
}
