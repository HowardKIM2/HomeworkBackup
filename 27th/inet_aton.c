#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

typedef struct sockaddr_in si;

void err_handler(char* msg){
	write(2, msg, strlen(msg));
	exit(1);
}

int main(int argc,char** argv){
	char* addr = "127.124.73.31";
	si addr_inet;
	if(!inet_aton(addr, &addr_inet.sin_addr))
		err_handler("Conversion Error!");
	else
		printf("Network Ordered Integer Addr : %#x\n", addr_inet.sin_addr.s_addr);

	return 0;


}
