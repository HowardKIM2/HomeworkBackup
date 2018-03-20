#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
int main(void){
	int fdin, fdout;
	ssize_t nread;
	char buf[10];

	fdin = open("temp1.txt",O_RDONLY);
	fdout = open("temp2.txt",O_WRONLY | O_CREAT | O_TRUNC, 0644);

	while((nread = read(fdin,buf,10)) > 0){
		printf("Success : %ld\n",nread);
		if(write(fdout, buf ,nread) < nread){
			printf("ERROR\n");
			close(fdin);
			close(fdout);
		}
	
	}
	close(fdin);
	close(fdout);

	return 0;
}
