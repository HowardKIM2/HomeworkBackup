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
	fputc('\n',stderr);
	exit(1);
}

int main(int argc,char* argv[]){
	
	st st_recv;
	int sock;
	int str_len;
	char msg[32];
	char* send = "Hi";
	si serv_addr;
	if(argc != 3){
		printf("err\n");
		exit(1);
	}

	sock = socket(PF_INET, SOCK_STREAM, 0);

	if(sock == -1)
		err_handler("socket() error");
	
	memset(&serv_addr, 0 , sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr.sin_port = htons(atoi(argv[2]));

	if(connect(sock, (sap)&serv_addr, sizeof(serv_addr)) == -1)
		err_handler("connect() error");
	
	read(sock, &st_recv, sizeof(&st_recv) );
	printf("name : %s, score : %d\n",st_recv.name,st_recv.score);
		
	close(sock);
	return 0;

}
