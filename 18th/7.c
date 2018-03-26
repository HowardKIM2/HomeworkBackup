#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
int main(int arcv, char** argv){
	int fd,ret;
	char buf[1024];
	if(arcv != 2){
		printf("Usage : mycat filename\n");
		exit(-1);
	}
	fd = open(argv[1],O_RDONLY);
	while(ret = read(fd,buf,sizeof(buf)/sizeof(char))){
		write(1,buf,ret);
	}
	close(fd);
	printf("%d\n",atoi("123"));
	return 0;
}
