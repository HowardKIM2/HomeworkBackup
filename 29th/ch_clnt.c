#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <time.h>
#define BUF_SIZE	128
#define NAME_SIZE	32

typedef struct sockaddr_in si;
typedef struct sockaddr * sp;

char name[NAME_SIZE] = "[DEFAULT]";
char msg[BUF_SIZE];

void err_handler(char* msg){
	fputs(msg, stderr);
	fputc('\n',stderr);
	exit(1);
}
char* create_rand_msg(void){
	srand(time(NULL));
	int str_len = rand()%20 + 10;
	int i;
	char* msg = (char*)malloc(sizeof(char)*str_len);
	for(i=0;i<str_len - 1;i++)
		msg[i] = 65 + rand()%26;
	msg[str_len - 1] = '\n';
	msg[str_len] = '\0';
	return msg;
}

void* send_msg(void* arg){
	int sock = *((int*)arg);
	char name_msg[NAME_SIZE + BUF_SIZE];
	char* msg;
	int time_rand;
	srand(time(NULL));
	for(;;){
		//period : 1~6 sec
		time_rand = rand()%6 + 1;
		//random msg
		msg = create_rand_msg();

		if(!strcmp(msg, "q\n") || !strcmp(msg, "Q\n")){
			close(sock);
			exit(0);
		}
		write(sock, msg, strlen(msg));
		sleep(time_rand);
	}
	return NULL;
}

void* recv_msg(void* arg){
	int sock = *((int*)arg);
	char name_msg[NAME_SIZE + BUF_SIZE];
	int str_len;

	for(;;){
		str_len = read(sock, name_msg, NAME_SIZE + BUF_SIZE - 1);
		if(str_len == -1)
			return (void*)-1;

		name_msg[str_len] = 0;
		fputs(name_msg, stdout);
	}
	return NULL;
}

int main(int argc,char** argv){
	int sock;
	si serv_addr;
	pthread_t snd_thread, rcv_thread;
	void* thread_ret;
	if(argc != 4){
		printf("Usage: %s <IP> <port><name>\n",argv[0]);
		exit(1);
	}
	sprintf(name, "[%s]", argv[3]);
	sock = socket(PF_INET, SOCK_STREAM, 0);

	if(sock == -1)
		err_handler("socket() error");
	
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr.sin_port = htons(atoi(argv[2]));

	if(connect(sock, (sp)&serv_addr, sizeof(serv_addr)) == -1)
		err_handler("connect() error");
	
	pthread_create(&snd_thread, NULL, send_msg, (void*)&sock);
	pthread_create(&rcv_thread, NULL, recv_msg, (void*)&sock);

	pthread_join(snd_thread, &thread_ret);
	pthread_join(rcv_thread, &thread_ret);

	close(sock);
	return 0;
}
