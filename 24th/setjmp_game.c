#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <setjmp.h>
#include <string.h>
jmp_buf env;

int init_game_num(void);
void time_over(int signo);
int main(void){
	int num;
	num = init_game_num();
	int cnt = 1;
	char buf[100];
	int input;
	int gamechk = 0;
	int ret;
	char* s_str = "input your number :";
	if((ret = setjmp(env)) == 0){
		while(cnt <= 5){
			signal(SIGALRM,time_over);
			alarm(1);
			write(1,s_str,strlen(s_str));
			read(0,buf,sizeof(buf));
			input = atoi(buf);
			if(input == num){
				gamechk = 1;
				break;
			}
			else if(input > num)
				printf("lower\n");
			else
				printf("upper\n");
			cnt++;
		}
		if(gamechk == 0)
			printf("Lose, num : %d\n",num);
		else
			printf("Win!, count : %d, num : %d\n",cnt,num);
	
	}
	else if(ret > 0)
		printf("\ntime over, num : %d\n",num);

	return 0;
}
int init_game_num(void){
	srand(time(NULL));
	int num;
	num = rand()%25 + 1;
	return num;
}
void time_over(int signo){
	int flag = -1;
	if(flag < 0)
		longjmp(env,1);
}
