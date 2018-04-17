#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <setjmp.h>

jmp_buf env;
unsigned int clap = 0;
unsigned int count = 1;

void time_handler(int signo);
bool chk_right(int count, int input);
void int_handler(int signo);
int chk_369_num(int count);
void waits(void);
int main(void){
	//max user's input 999
	char input[4] = {'\0',}; 
	int usr, clap, ret;
	while(1){	
redo:
		signal(SIGINT, int_handler);
		signal(SIGALRM,time_handler);
		alarm(3);
		//user input num
		system("clear");
		printf("num -> %d \n",count);
		clap = chk_369_num(count);
		if(clap)
			goto wait;
		read(0, input, sizeof(input));
		usr = atoi(input);
#if 0
	if(clap != 0){
			printf("You should've claped %d times\n",clap);
			exit(1);
		}
#endif
		
		chk_right(count,usr);
		count++;
	}
wait:
	while(1){
		pause();
		count++;
		goto redo;
	}

}
void time_handler(int signo){
	printf("3 sec flew, exit! :(\n");
	exit(1);
}
bool chk_right(int count, int input){
	if(count - input){
		printf("%d != %d , exit! :(",count,input);
		exit(1);
	}
	if(chk_369_num(count)){
		printf("should've claped!!");
		exit(1);
	}
	return true;
}
void int_handler(int signo){
	clap++;
	int chk = chk_369_num(count);
	if(chk < clap){
		printf("chk : %d, clap : %d\n",chk,clap);
		printf("wrong clap!\n");
		exit(1);
	}
	if(chk == clap)
		clap = 0;
	else
		waits();
}
void waits(void){
	printf("clap more\n");

	signal(SIGINT, int_handler);
	pause();
}
int chk_369_num(int count){
	int chk = 0;
	int buf;
	buf = count / 100;
	if(((count/100) % 3 == 0)&& (count / 100 != 0))
		chk++;
	if((((count%100) / 10) % 3 == 0)&&((count % 100) / 10 != 0))
		chk++;
	if(((count % 10) % 3 == 0)&&(count % 10 != 0))
		chk++;
	return chk;
}
