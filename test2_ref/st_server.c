#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
typedef struct sockaddr_in si;
typedef struct sockaddr * sap;
typedef struct __st{
	char name[30];
	int score;
}st;
void err_handler(char* msg){
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}

int main(int argc,char** argv){
	int serv_sock;
	int clnt_sock;
	int ret;
	st st_send = {"KKK",100};
	si serv_addr;
	si clnt_addr;
	socklen_t clnt_addr_size;
	char* send = "Hello";
	char recv[32] = {0,};
	if(argc != 2){
		printf("use : %s <port>\n",argv[0]);
		exit(1);
	}
	//sock file descriptor
	serv_sock = socket(PF_INET, SOCK_STREAM, 0);
	if(serv_sock == -1)
		err_handler("socket() error");
	
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1]));
	//bind : server ip address setting
	if(bind(serv_sock, (sap)&serv_addr, sizeof(serv_addr)) == -1)
		err_handler("bind() error");
	//listen : max people , wait client.
	
	if(listen(serv_sock, 5) == -1)
		err_handler("listen() error");

	clnt_addr_size = sizeof(clnt_addr);
	//client permit.
	clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_addr, &clnt_addr_size);
	if(clnt_sock == -1)
		err_handler("accept() error");
	write(clnt_sock, &st_send, sizeof(&st_send));
	
	close(clnt_sock);
	close(serv_sock);

}
