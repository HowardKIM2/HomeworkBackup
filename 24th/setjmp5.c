#include <stdio.h>
#include <signal.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void my_sig(int signo){
	printf("You must insert coin\n");
//	exit(0);
}
int main(void){
	char buf[1024];
	int ret;
	while(1){
	signal(SIGALRM,my_sig);
	alarm(1);
	read(0,buf,sizeof(buf));
	}
	return 0;
}
