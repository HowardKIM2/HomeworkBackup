#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void term_status(int status){
	if(WIFEXITED(status))
		printf("(exit)status : 0x%x\n",WEXITSTATUS(status));
	else if(WTERMSIG(status))
		printf("(signal)status : 0x%x, %s\n",
				status & 0x7f, WCOREDUMP(status) ? "core dumped" : "");
	while(1);
}

void my_sig(int signo){
	int status;
	wait(&status);
	term_status(status);
}

int main(void){
	pid_t pid;
	int i;
	//행동 지침 지정(인터럽트)
	signal(SIGCHLD, my_sig);
	if((pid = fork()) > 0)
		for(i=0;i<10000;i++){
			usleep(50000);
			printf("%d\n",i+1);
		
		}
	else if(pid == 0)
		sleep(5);
	else{
		perror("fork()");
		exit(-1);
	}
	return 0;
}
