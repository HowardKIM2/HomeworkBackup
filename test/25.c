#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
int* sadari(int people,int getnum);
bool chk_dup(int* a, int i, int num);
int main(void){
	int people, getnum, i; //people 참여인원수, getnum 사다리 당첨자수
	int* get;
	printf("사람수 : ");
	scanf("%d",&people);
	printf("사다리 당첨자 수  : ");
	scanf("%d",&getnum);
	get = sadari(people,getnum);
	//당첨자 출력
	printf("%d명 당첨!\n",getnum);
	for(i=0;i<getnum;i++)
		printf("%d번 사람\n",get[i]);
	
	return 0;
}
int* sadari(int people,int getnum){
	int* get;				//당첨자 저장 변수
	int i = 0;
	get = (int*)malloc(sizeof(int)*getnum);
	srand(time(NULL));
	while(i<getnum){
		get[i] = rand()%people + 1;
		if(chk_dup(get,i,get[i]))
			continue;
		i++;
	}
	return get;
	
}
bool chk_dup(int* a,int i, int num){
	int j;
	bool chk = false;
	for(j = 0; j < i; j++){
		if(a[j] == num){
			chk = true;
			break;
		}
	}
	return chk;
}
