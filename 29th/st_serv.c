#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <sys/socket.h>

typedef struct sockaddr_in si;
typedef struct sockaddr* sap;

#define BUF_SIZE	32

typedef struct __data{
	char name[64];
	int score;
}data;

void err_handler(char* msg);
void read_childproc(int sig);
void send_data(data d,int clnt_sock);
void input_data(data* d);
void read_data(data* d,int clnt_sock);
int main(int argc,char** argv){

	int serv_sock, clnt_sock;
	si serv_addr, clnt_addr;
	pid_t pid;
	struct sigaction act;
	socklen_t addr_size;
	int str_len, state;
	char buf[BUF_SIZE] = {0,};
	data d;
	if(argc != 2){
		printf("use : %s <port>\n",argv[0]);
		exit(1);
	}
	
	act.sa_handler = read_childproc;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	state = sigaction(SIGCHLD, &act, 0);

	serv_sock = socket(PF_INET, SOCK_STREAM, 0);

	if(serv_sock == -1)
		err_handler("socket() error");

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1]));

	if(bind(serv_sock, (sap)&serv_addr, sizeof(serv_addr)) == -1)
		err_handler("bind() error");
	
	if(listen(serv_sock, 5) == -1)
		err_handler("listen() error");

	for(;;){
		addr_size = sizeof(clnt_addr);
		clnt_sock = accept(serv_sock, (sap)&clnt_addr, &addr_size);
		if(clnt_sock == -1)
			continue;
		else
			puts("New Client Connected ....");
		pid = fork();
		if(pid == -1){
			close(clnt_sock);
			continue;
		}
		if(pid == 0){
			close(serv_sock);
#if 0
			while((str_len = read(clnt_sock, buf, BUF_SIZE)) != 0)
				write(clnt_sock, buf, str_len);
#endif

#if 1
			while(1){
				input_data(&d);
				send_data(d,clnt_sock);
			}
#endif
			close(clnt_sock);
			puts("Client Disconnected ...");
			return 0;
		}
		else{

			while(1)
				read_data(&d, clnt_sock);
			close(clnt_sock);
		}
	}
	close(serv_sock);

	return 0;
}
void read_childproc(int sig){
	pid_t pid;
	int status;
	pid = waitpid(-1, &status, WNOHANG);
	printf("Removed proc id : %d\n",pid);
}
void err_handler(char* msg){
	fputs(msg, stderr);
	fputc('\n',stderr);
	exit(1);
}
void send_data(data d,int clnt_sock){
	char smsg[1024];
	sprintf(smsg,"%s\t%d\n",d.name,d.score);
	write(clnt_sock, &d, strlen(smsg));
}
void input_data(data* d){
	scanf("%s%d",d->name,&d->score);
}
void read_data(data* d,int clnt_sock){
	int read_len;
	char smsg[1024];
	int i,start = 0,end = 0;
	
	read_len = read(clnt_sock, smsg, sizeof(smsg));
	smsg[read_len] = '\0';

	printf("struct from clnt : %s",smsg);
}
