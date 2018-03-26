#include <signal.h>
#include <stdio.h>

int main(void){
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGKILL, SIG_IGN);
	pause();
	return 0;
}
