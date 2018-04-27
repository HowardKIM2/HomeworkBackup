#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
void init_daemon(void);
int main(void){
	init_daemon();
	//write here what you want to make daemon;
	int i;
	for(i=0;i<50;i++){
		printf("I'm a daemon\n");
		sleep(1);
	}	
	for(;;)
		;
	return 0;
}
void init_daemon(void){
	int i;
	if(fork() > 0)
		exit(0);
	setsid();
	chdir("/");
	umask(0);
	for(i=0;i<64;i++)
		close(i);
	signal(SIGCHLD, SIG_IGN);
}
