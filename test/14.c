#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void){
	srand(time(NULL));
	int space[100];		   //물건을 담을 수 있는 공간
	int input[100] = {0,}; // 담긴 물건
	int waste[100]={0,};   //낭비된 공간
	int i = 0;
	while(i<100){
		space[i] = rand()%131072 + 1;
		if(space[i] >= 4096)             //최솟값 : 4096
			space[i] = space[i]&(-4096); //난수 : 0~131072 ->4096배수
		else
			space[i] = 4096;
		i++;
	}
	for(i=0;i<100;i++){
		waste[i] = space[i] - input[i];//낭비된 공간 : 수용량 - 사용량
	}
	return 0;
}
