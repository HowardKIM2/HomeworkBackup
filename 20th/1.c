#include <stdio.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main(void){

	int fd;
	fd = open("a.txt",O_WRONLY|O_CREAT|O_TRUNC,0644);
	close(1);
	dup(fd);
	printf("출력되냐?\n");
	return 0;
}
