#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
void gogogo(int voidv){
	printf("SIGINT Accur\n");
	exit(0);
}

int main(void){
	signal(SIGINT,gogogo);

	for(;;){
		printf("kill Test\n");
		sleep(2);
	}

	return 0;
}
