#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <time.h>
#include <signal.h>
#include <setjmp.h>
typedef struct sockaddr_in si;
typedef struct sockaddr * sap;

#define BUF_SIZE		1024
jmp_buf env;

void err_handler(char* msg){
	fputs(msg,stderr);
	fputc('\n',stderr);
	exit(1);
}
void init_game(int* cnt, int* com);
void time_out(int signo);
int main(int argc,char **argv){
	int i, str_len;
	int serv_sock, clnt_sock;
	char p_num[1024];
	int tmp;
	char msg[BUF_SIZE];
	char up[100] = "up";
	char down[100] = "down";
	char fin[100];
	char timeout[100] = "time out , cnt + 1";
	int cnt, com;
	si serv_addr,clnt_addr;
	socklen_t clnt_addr_size;
	int ret;
	if(argc != 2){
		printf("use : %s <port>\n",argv[0]);
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
	
	if(listen(serv_sock, 5) == -1)
		err_handler("listen() error");
	
	clnt_addr_size = sizeof(clnt_addr);
	
	
	for(i=0;i<100;i++){
		clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_addr, &clnt_addr_size);
		if(clnt_sock == -1)
			err_handler("accept() error");
		else
			printf("Connected Client : %d\n",i+1);
		init_game(&cnt,&com);
		printf("com : %d\n",com);
		//game start.
		while((str_len = read(clnt_sock, p_num, BUF_SIZE)) != 0){
			tmp = atoi(p_num);
			if((ret = setjmp(env)) == 0){
				signal(SIGALRM, time_out);
				alarm(3);

				if(tmp == com){
					printf("player : %d\n",tmp);
					sprintf(fin,"%d user: success, cnt %d\n",i,cnt);
					write(clnt_sock, fin, sizeof(fin));
					break;
				}
				else if(tmp < com){
					printf("player : %d\n",tmp);
					cnt++;
					write(clnt_sock, up, sizeof(up));				
				}
				else if(tmp > com){
					printf("player : %d\n",tmp);
					cnt++;
					write(clnt_sock, down, sizeof(down));
				}
				alarm(0);
			}
			else{
				printf("cnt++\n");
				cnt++;
				write(clnt_sock, time_out, sizeof(time_out));		
			}
		}		
		close(clnt_sock);
	}
	close(serv_sock);


	return 0;
}
void init_game(int* cnt, int* com){
	srand(time(NULL));
	*cnt = 1;
	*com = rand()%3333 + 1;
}
void time_out(int signo){

	longjmp(env,1);
}
