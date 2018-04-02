#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
#define MAX_CLNT 256
typedef struct sockaddr_in si;
typedef struct sockaddr * sap;
int thread_pid[MAX_CLNT];
int clnt_socks[MAX_CLNT];
int clnt_cnt = 0;
pthread_mutex_t mtx;

void err_handler(char* msg);
void* clnt_handler(void* data);
int main(int argc,char** argv){
	int serv_sock, clnt_sock;
	si serv_addr, clnt_addr;
	socklen_t addr_size;
	pthread_t t_id;
	int idx = 0;
	if(argc != 2){
		printf("use: %s <port>\n",argv[0]);
		exit(1);
	}

	serv_sock = socket(PF_INET, SOCK_STREAM, 0);
	if(serv_sock == -1)
		err_handler("socket() error");

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1]));

	if(bind(serv_sock, (sap)&serv_addr, sizeof(serv_addr)) == -1)
		err_handler("bind() error");
	
	if(listen(serv_sock,2) == -1)
		err_handler("listen() error");

	for(;;){
		addr_size = sizeof(clnt_addr);
		clnt_sock = accept(serv_sock, (sap)&clnt_addr, &addr_size);
		
		pthread_mutex_lock(&mtx);	
		clnt_socks[clnt_cnt++] = clnt_sock;
		pthread_mutex_unlock(&mtx);	
		
		pthread_create(&t_id, NULL, clnt_handler, (void*)&clnt_sock); 
		pthread_detach(t_id);
		thread_pid[idx] = getpid();
		printf("%d번째 클라이언트\n",clnt_cnt);
	}
	return 0;
}
void err_handler(char* msg){
	fputs(msg,stderr);
	fputc('\n',stderr);
	exit(1);
}
void* clnt_handler(void* data){
	int clnt_sock = *(int*)data;
	printf("sock fd : %d\n",clnt_sock);
	
	return NULL;
}
