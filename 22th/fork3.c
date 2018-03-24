#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char** argv){
	pid_t pid;
	pid = fork();

	if(pid > 0){
		printf("parent pid = %d, cpid = %d\n",getpid(),pid);
	}
	else if(pid == 0){
		printf("child : pid = %d, cpid = %d\n",getpid(),pid);
	}
	else{
		perror("fork()");
		exit(-1);
	}
	return 0;
}
