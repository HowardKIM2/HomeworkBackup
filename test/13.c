#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
int main(void){
	srand(time(NULL));
	int space[100];		   //물건을 담을 수 있는 공간
	int input[100] = {0,}; // 담긴 물건
	int waste[100]={0,};   //낭비된 공간
	int i = 0;
	while(i<100){
		space[i] = rand()%4096 + 1;
		printf("%d\n",*(space+i));
		i++;
	}
	for(i=0;i<100;i++){
		waste[i] = space[i] - input[i];//낭비된 공간 : 수용량 - 사용량
	}
	return 0;
}
