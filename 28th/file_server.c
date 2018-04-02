#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

typedef struct sockaddr_in si;
typedef struct sockaddr * sap;

#define BUF_SIZE 	32

void err_handler(char* msg){
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}

int main(int argc,char** argv){
	int serv_sock, clnt_sock, fd;
	char buf[BUF_SIZE] = {0};
	int read_cnt;

	si serv_addr, clnt_addr;
	socklen_t clnt_addr_size;

	if(argc != 2){
		printf("use : %s <port>\n",argv[0]);
		exit(1);
	}

	fd = open("file_server.c",O_RDONLY);
	serv_sock = socket(PF_INET, SOCK_STREAM, 0);

	if(serv_sock == -1)
		err_handler("socket() error");

	memset(&serv_addr, 0 , sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1]));

	if(bind(serv_sock, (sap)&serv_addr, sizeof(serv_addr)) == -1)
		err_handler("bind() error");
	if(listen(serv_sock, 5)== -1)
		err_handler("listen() error");

	clnt_addr_size = sizeof(clnt_addr);

	clnt_sock = accept(serv_sock, (sap)&clnt_addr, &clnt_addr_size);

	for(;;){
		read_cnt = read(fd, buf, BUF_SIZE);
		if(read_cnt < BUF_SIZE){
			write(clnt_sock, buf, read_cnt);
			break;
		}
		write(clnt_sock, buf, BUF_SIZE);
	}

	shutdown(clnt_sock, SHUT_WR);
	read(clnt_sock, buf, BUF_SIZE);
	printf("msg from client : %s\n",buf);

	close(fd);
	close(clnt_sock);
	close(serv_sock);

	return 0;
}
