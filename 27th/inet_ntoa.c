#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>

typedef struct sockaddr_in si;

int main(int argc,char** argv){
	si addr1, addr2;
	char* str;
	char str_arr[32] = {0};

	addr1.sin_addr.s_addr = htonl(0x10203040);
	addr2.sin_addr.s_addr = htonl(0x12345678);

	str = inet_ntoa(addr1.sin_addr);
	strcpy(str_arr, str);
	printf("Not 1: %s\n",str);

	str = inet_ntoa(addr2.sin_addr);

	printf("Not 2: %s\n",str);
	printf("Not 3: %s\n",str_arr);

	return 0;
}
