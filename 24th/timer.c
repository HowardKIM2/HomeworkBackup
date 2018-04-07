#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void time_handler(int signo);
int main(void){
	
	signal(SIGALRM, time_handler);
	alarm(3);
	
	while(1);
	return 0;
}
void time_handler(int signo){
	printf("3 sec flew\n");
	alarm(3);
}
