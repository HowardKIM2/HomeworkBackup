#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
int main(void){
	int fd, ret;
	char buff[1024];
	mkfifo("myfifo");
	fd = open("myfifo",O_RDWR);
	for(;;){
		ret = read(0, buff, sizeof(buff));
		buff[ret - 1] = 0;
		printf("Keyboard input : [%s]\n",buff);
		read(fd,buff,sizeof(buff));
		buff[ret - 1] = 0;
		printf("Pipe Input : [%s]\n",buff);
	}
	return 0;
}
