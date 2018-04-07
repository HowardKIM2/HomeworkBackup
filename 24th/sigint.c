#include <unistd.h>
#include <stdio.h>
#include <signal.h>
void sig_handler(int signo);
int main(void){
	int i;
	struct sigaction act;

	act.sa_handler = sig_handler;
	sigfillset(&act.sa_mask);
	sigaction(SIGINT,&act,NULL);
	
	for(i=0;;i++){
		printf("%d\n",i);
		sleep(1);
	}
}
void sig_handler(int signo){
	printf("I RECEIVED SIGINT(%d)\n",SIGINT);
	printf("wait 3 sec, during that time, press cntl + z\n");
	int i;

	for(i=1;i<4;i++){
		sleep(1);
		printf("%d sec flew\n",i);
	}
}
