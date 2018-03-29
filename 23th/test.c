#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc,char** argv){
	pid_t pid;
	int status;
	if((pid = fork()) > 0){
		wait(&status);
	}
	else if(pid == 0){
		execlp("./newpgm","aa","bb","cc",NULL);
	}
	else{
		perror("fork()");
		exit(-1);
	}
	return 0;

}
