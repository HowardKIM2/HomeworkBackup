#include "m_socket.h"

int main(int argc, char** argv){
	int sock;
	si serv_addr;
	int str_len;
	char msg[64];

	if(argc != 3){
		printf("use : %s <IP> <PORT>\n",argv[0]);
		exit(1);
	}
	sock = get_sock_fd();

	set_serv_addr(&serv_addr, argv[2], argv[1]);
	connect_clnt(sock,serv_addr,sizeof(serv_addr));
	
	str_len = read(sock, msg, sizeof(msg) - 1);
	
	printf("msg from serv : %s\n",msg);

	close(sock);
	return 0;
}
