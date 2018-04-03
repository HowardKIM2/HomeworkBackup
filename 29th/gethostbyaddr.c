#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

typedef struct sockaddr_in si;

void err_handler(char* msg){
	fputs(msg, stderr);
	fputc('\n',stderr);
	exit(1);
}

int main(int argc,char** argv){
	int i;
	si addr;
	struct hostent* host;

	if(argc != 2){
		printf("use : %s <port>",argv[0]);
		exit(1);
	}

	memset(&addr, 0, sizeof(addr));
	/*
		screenshot
	
	*/

}
