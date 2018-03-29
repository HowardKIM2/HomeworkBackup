#include <stdio.h>
#include <signal.h>
#include <unistd.h>
struct sigaction act_new;
struct sigaction act_old;

void sigint_handler(int signo){
	printf("Ctrl + C\n");
	printf("If you push it one more time than exit\n");
	sigaction(SIGINT, &act_old, NULL);
}

int main(void){
	//sa : signal action
	//signal handller set
	act_new.sa_handler = sigint_handler;
	//empty the mask
	sigemptyset(&act_new.sa_mask);
	
	//act_old : save previous handler.
	//& 들어간 애들은, 값이 변경될수도 있음.(다른사람프로그램 보는법)
	//output이 여러개 가능.
	sigaction(SIGINT, &act_new, &act_old);
	while(1){
		printf("sigaction test\n");
		sleep(1);
	}

	return 0;
}
