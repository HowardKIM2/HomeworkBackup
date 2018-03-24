#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void){
	pid_t pid;
	if((pid = fork()) > 0)
		sleep(50);
	else if(pid == 0)
		;
	else{
		perror("fork()");
		exit(-1);
	}
	return 0;
}
