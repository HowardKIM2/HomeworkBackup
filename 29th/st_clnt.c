#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

typedef struct sockaddr_in si;
typedef struct sockaddr * sap;

#define BUF_SIZE	32

typedef struct __data{
	char name[64];
	int score;
}data;

void err_handler(char* msg);
void read_routine(int sock,char* buf,data* d);
void write_routine(int sock, char* buf,data d);

int main(int argc,char** argv){
	pid_t pid;
	int i,sock;
	si serv_addr;
	char buf[BUF_SIZE] = {0,};
	data d;
	if(argc != 3){
		printf("use : %s <IP> <PORT>\n",argv[0]);
		exit(1);
	}
	sock = socket(PF_INET, SOCK_STREAM, 0);
	
	if(sock == -1)
		err_handler("socket() error");
	
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr.sin_port = htons(atoi(argv[2]));

	if(connect(sock, (sap)&serv_addr, sizeof(serv_addr)) == -1)
		err_handler("connect() errpr");
	else
		puts("Connected .......");
	
	pid = fork();

	if(pid == 0)
		write_routine(sock, buf, d);
	else
		read_routine(sock, buf, &d);
	
	close(sock);
	return 0;
}
void write_routine(int sock, char* buf,data d){
	for(;;){
		scanf("%s%d",d.name,&d.score);
		if(!strcmp(buf, "q\n") || !strcmp(buf, "Q\n")){
			shutdown(sock, SHUT_WR);
			return ;
		}
		sprintf(buf,"%s\t%d\n",d.name,d.score);
		write(sock, buf, strlen(buf));
	}
}
void read_routine(int sock,char* buf, data* d){
	for(;;){
		int str_len = read(sock, buf, BUF_SIZE);
		if(str_len == 0)
			return;
		buf[str_len] = '\0';
		printf("struct from server : %s",buf);
	}
}
void err_handler(char* msg){
	fputs(msg, stderr);
	fputc('\n',stderr);
	exit(1);
}
