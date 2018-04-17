#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
void create_file(void);
int main(void){
	int fd, ret;
	char buf[1024];
	fd = open("myfifo",O_RDWR);
//	fcntl(0, F_SETFL, O_NONBLOCK);
//	fcntl(fd, F_SETFL, O_NONBLOCK);

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
		if(!strcmp(buf,"c type.c"))
			create_file();
	}
	close(fd);

	return 0;
}
void create_file(void){
	int fd;
	if((fd = open("type.c",O_CREAT|O_TRUNC,0644)) > 0)
		printf("type.c created!\n");
	else
		printf("create error\n");
	close(fd);
}
