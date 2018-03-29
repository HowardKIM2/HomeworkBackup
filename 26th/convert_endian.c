#include <stdio.h>
#include <arpa/inet.h>
int main(void){
	unsigned short host_port = 0x5678;
	unsigned short net_port;
	unsigned long host_addr = 0x87654321;
	unsigned long net_addr;

	net_port = htons(host_port);
	net_addr = htonl(host_addr);

	printf("Host Ordered Port : %#x\n", host_port);
	printf("Network Ordered Port : %#x\n",net_port);
	printf("Host Ordered Address : %#lx\n",host_addr);
	printf("Network Ordered Address : %#lx\n", net_addr);

	return 0;
}
