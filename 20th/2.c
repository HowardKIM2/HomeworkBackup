#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void){

	int fd;
	char buff[1024];
	fd = open("a.txt",O_RDONLY);
	close(0);
	dup(fd);
	gets(buff);
	
	printf("출력될까?\n");
	printf("buf : %s\n",buff);
	return 0;
}
