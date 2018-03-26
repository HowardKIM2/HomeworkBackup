#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main(void){
	char buf[1024];
	int fd[2];

	fd[0] = open("1.c",O_RDONLY);
	read(fd[0],buf,10);
	write(1,buf,10);

	printf("fd[0] : %d\n",fd[0]);

	fd[1] = open("1.c",O_RDONLY);
	read(fd[1], buf, 10);
	write(1, buf, 10);

	printf("fd[1] : %d\n",fd[1]);
	return 0;
}
