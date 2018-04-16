#include <signal.h>
#include <stdio.h>
void sig_handler(int signo);
int main(void){
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, sig_handler);
	while(1);

}
void sig_handler(int signo){
	printf("QUIT!!\n");
	exit(-1);
}
