#include <stdio.h>
#include <arpa/inet.h>

int main(int argc,char** argv){
	char* addr1 = "3.5.7.9";
	char* addr2 = "1.3.5.7";

	unsigned long conv_addr = inet_addr(addr1);
	if(conv_addr == INADDR_NONE)
		printf("Error!\n");
	else
		printf("Network Ordered Integer Addr : %#lx\n", conv_addr);
	
	conv_addr = inet_addr(addr2);

	if(conv_addr == INADDR_NONE)
		printf("Error!\n");
	else
		printf("Network Ordered Integer Addr : %#lx\n",conv_addr);

	return 0;
	
}
