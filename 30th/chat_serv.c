#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <sys/time.h>
#include <stdbool.h>

#define BUF_SIZE	128
#define MAX_CLNT	256

typedef struct sockaddr_in si;
typedef struct sockaddr *  sp;
typedef struct timeval tv;

typedef struct __clnt{
	int clnt_sock;
	si clnt_addr;
}clnt;

int clnt_cnt = 0;
int clnt_socks[MAX_CLNT];
si ban_clnt_addr[MAX_CLNT];
int ban_cnt = 0;
pthread_mutex_t mtx;

double get_runtime(tv start, tv end);
bool chk_too_much(int cnt, double flew_time);
void kick_message(si clnt_addr,char* msg);
bool chk_ban_list(si clnt_addr);
void err_handler(char* msg){
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}

void send_msg(char* msg,int len){
	int i;

	pthread_mutex_lock(&mtx);

	for(i=0;i<clnt_cnt;i++)
		write(clnt_socks[i], msg, len);
	pthread_mutex_unlock(&mtx);
}

void* clnt_handler(void* arg){
	
	clnt st_clnt = *((clnt*)arg);
	int clnt_sock = st_clnt.clnt_sock;
	si clnt_addr = st_clnt.clnt_addr;

	int str_len = 0, i;
	char msg[BUF_SIZE];
	int cnt = 0;
	tv start, end;
	double flew_time = 0;
	int sd_flag = -1;
	gettimeofday(&start, NULL);

	if(chk_ban_list(clnt_addr))
		goto ban;

	while((str_len = read(clnt_sock, msg, sizeof(msg))) != 0){		
#if 1
		if(chk_too_much(cnt,flew_time) && cnt > 5){
			cnt = 0;
			gettimeofday(&start, NULL);
			sd_flag = shutdown(clnt_sock, SHUT_RD);
			ban_clnt_addr[ban_cnt++] = clnt_addr;
			
			printf("add ban list : %s\n",inet_ntoa(clnt_addr.sin_addr));
		}
		else if(flew_time > 10){
			cnt = 0;
			gettimeofday(&start, NULL);
		}
#endif
		send_msg(msg, str_len);
		cnt++;
		gettimeofday(&end, NULL);
		flew_time = get_runtime(start,end);
	}

	if(sd_flag == 0)
		kick_message(clnt_addr, msg);
	
	
	
	pthread_mutex_lock(&mtx);

	for(i=0;i<clnt_cnt;i++){
		if(clnt_sock == clnt_socks[i]){
			while(i++ < clnt_cnt - 1)
				clnt_socks[i] = clnt_socks[i+1];
			break;
		}
	}
	clnt_cnt--;
	pthread_mutex_unlock(&mtx);
ban:
	close(clnt_sock);
	return NULL;
}

int main(int argc, char** argv){
	int serv_sock, clnt_sock;
	si serv_addr, clnt_addr;
	socklen_t addr_size;
	pthread_t t_id;

	if(argc != 2){
		printf("Usage : %s <port>\n",argv[0]);
		exit(1);
	}

	pthread_mutex_init(&mtx, NULL);

	serv_sock = socket(PF_INET, SOCK_STREAM, 0);

	if(serv_sock == -1)
		err_handler("socket() error");
	
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1]));

	if(bind(serv_sock, (sp)&serv_addr, sizeof(serv_addr)) == -1)
		err_handler("bind() error");
	
	if(listen(serv_sock, 5) == -1)
		err_handler("listen() error");

	for(;;){
		addr_size = sizeof(clnt_addr);
		
		clnt_sock = accept(serv_sock, (sp)&clnt_addr, &addr_size);
		if(chk_ban_list(clnt_addr)){
			close(clnt_sock);
			continue;
		}
		
		pthread_mutex_lock(&mtx);
		clnt_socks[clnt_cnt++] = clnt_sock;
		pthread_mutex_unlock(&mtx);
		
		clnt st_clnt;
		st_clnt.clnt_sock = clnt_sock;
		st_clnt.clnt_addr = clnt_addr;
		
		pthread_create(&t_id, NULL, clnt_handler, (void*)&st_clnt);
		pthread_detach(t_id);
		printf("Connected Client IP : %s\n",inet_ntoa(clnt_addr.sin_addr));
	}
	close(serv_sock);
	return 0;
}

double get_runtime(tv start, tv end){
	end.tv_usec = end.tv_usec - start.tv_usec;
	end.tv_sec = end.tv_sec - start.tv_sec;
	end.tv_usec += end.tv_sec * 1000000;
	return end.tv_usec / 1000000.0;
}

bool chk_too_much(int cnt,double flew_time){
	if(cnt > (int)flew_time*5)
		return true;
	return false;
}

void kick_message(si clnt_addr,char* msg){
	char kick_msg[512];
	sprintf(kick_msg,"kick [%s] : %s",inet_ntoa(clnt_addr.sin_addr),msg);
	send_msg(kick_msg, strlen(kick_msg));
}

bool chk_ban_list(si clnt_addr){
	int i;
	for(i=0;i<ban_cnt;i++)
		if(inet_ntoa(clnt_addr.sin_addr) == inet_ntoa(ban_clnt_addr[i].sin_addr))
			return true;
	return false;
}
