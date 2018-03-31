#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdlib.h>
typedef struct sockaddr_in	si;
typedef struct sockaddr *	sap;

#define BUF_SIZE		1024
#define RLT_SIZE		4
#define OPSZ			4

void err_handler(char *msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}

int main(int argc, char **argv)
{
	int i, sock, result, opnd_cnt, nread;
	char buf[BUF_SIZE] = {0};
	char opmsg[BUF_SIZE] = {0};
	si serv_addr;

	if(argc != 3)
	{
		printf("use: %s <IP> <port>\n", argv[0]);
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
		err_handler("connect() error");
	else
		puts("Connected ......");

	char input[32];
	int send_len;
	
	for(;;)
	{
		system("clear");
		nread = read(sock, buf, BUF_SIZE);
		write(1, buf, nread);
		
		//end messeage : 
		if(!strncmp(buf," 정답!",4)){
			break;
		}
		else if(!strncmp(buf," 종료!",4)){
			goto exit;
		}
		send_len = read(0,input, sizeof(input));
		write(sock, input, send_len);
		
	}
	//send player's name to server.
	send_len = read(0,input, sizeof(input));
	write(sock, input, send_len);
	
	fflush(stdin);
	
	nread = read(0, buf, BUF_SIZE);
	write(sock, buf, nread);
	
	fflush(stdin);
	printf("\n");
	nread = read(sock, buf, BUF_SIZE);
	write(1, buf, nread);
	close(sock);
	
exit:
	return 0;
}
