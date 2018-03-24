#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){
	pid_t pid;
	int status;
	if((pid = fork()) > 0){
		wait(&status);
		printf("status : 0x%x\n", status&0x7f);
	}
	else if(pid == 0)
		abort();
	else{
		perror("fork()");
		exit(-1);
	}
	return 0;

}
