#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

void child_process(void);
int main(void){
	pid_t pid, child_pid;
	int status;
	if((pid = fork()) > 0){
		printf("I'm parent process, waiting child signal\n");
		child_pid = wait(&status);
		if(WIFEXITED(status))
			printf("normal exit : pid(%d), signal(0x%x)\n",child_pid,status&0x7f);
		else
			printf("abnormal exit : pid(%d), signal(0x%x)\n",child_pid,status&0x7f);
	}
	else if(pid == 0)
		child_process();
	else{
		perror("fork()");
		exit(-1);
	}
	return 0;
}
void child_process(void){
	int i;
	sleep(1);
	printf("I'm child, I'll die after 5 sec\n");
	for(i=1;i<=5;i++){
		sleep(1);
		printf("%d sec flew\n",i);
	}
	printf("CHILD DIED\n");
//	abort();
	exit(1);
}
