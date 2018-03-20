#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv){
	int fdin, fdout;
	ssize_t nread;
	char buf[1024];
	int i;
	if(argc != 3){
		printf("인자 3개 입력!!\n");
		exit(-1);
	}
	for(i = 0; i < argc; i++)
		printf("인자 : %s\n",argv[i]);
	
	fdin = open(argv[1],O_RDONLY);
	fdout = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC | O_EXCL, 0644);

	while((nread = read(fdin,buf,1024)) > 0){
		printf("Success : %ld\n",nread);
		if(write(fdout, buf ,nread) < nread){
			printf("ERROR : \"%s\" already exists\n",argv[2]);
			close(fdin);
			close(fdout);
			exit(-1);
		}
	}
	close(fdin);
	close(fdout);

	return 0;
}
