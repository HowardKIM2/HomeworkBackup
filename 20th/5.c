#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void){
	int fd, ret;
	char buf[1024];
	fd = open("myfifo",O_RDWR);
	fcntl(0, F_SETFL, O_NONBLOCK);
	fcntl(fd, F_SETFL, O_NONBLOCK);

	int i = 0;
	for(i = 0;;i++){
	/*
		if((ret = read(0,buf,sizeof(buf))) > 0){
			buf[ret - 1] = 0;
			printf("Keyboard Input : [%s]\n",buf);
		}
	*/
		if((ret = read(fd,buf,sizeof(buf))) > 0){
			buf[ret - 1] = 0;
			printf("Pipe Input : [%s]\n",buf);
		}
		if(0 == i % 500000)
			printf("non-blocking!\n");
	}
	close(fd);

	return 0;
}
