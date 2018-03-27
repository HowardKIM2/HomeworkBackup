#include <signal.h>
#include <stdio.h>
#include <unistd.h>
void my_sig(int signo){
	printf("my_sig called\n");
}
void my_sig2(int signo){
	printf("my_sig2 called\n");
}
int main(void){
	void (*old_p)(int);
	void (*old_p2)(int);
	//signal returns previous function pointer.
	//old_p receive NULL.
	old_p = signal(SIGINT, my_sig);
	pause();
	//old_p2 receives my_sig
	old_p2 = signal(SIGINT, my_sig2);
	pause();
	old_p2 = signal(SIGINT, old_p2);
	pause();
	for(;;)
		pause();
	return 0;

}
