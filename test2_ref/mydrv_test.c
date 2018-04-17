#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_BUFFER 26
char buf_in[MAX_BUFFER];
char buf_out[MAX_BUFFER];

int main(void){
	int fd, i, c = 65;
	int chk;
	if((fd = open("/dev/mydevicefile",O_RDWR)) < 0){
		perror("open error");
		exit(-1);
	}
	for(i=0;i<MAX_BUFFER;i++){
		buf_out[i] = c++;
		buf_in[i] = 65;
	}
	for(i=0;i<MAX_BUFFER;i++){
		fprintf(stderr,"%c",buf_out[i]);
	}
	fprintf(stderr, "\n");

	chk = write(fd, buf_out, MAX_BUFFER);
	printf("write : %d(959?)\n",chk);
	read(fd, buf_in, MAX_BUFFER);
	printf("read : %d(959?)\n",chk);

	for(i=0;i<MAX_BUFFER;i++){
		fprintf(stderr,"%c",buf_in[i]);
	}
	
	fprintf(stderr,"\n");
	close(fd);
	return 0;
}
