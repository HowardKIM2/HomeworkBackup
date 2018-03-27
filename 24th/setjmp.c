#include <fcntl.h>
#include <stdlib.h>
#include <setjmp.h>
#include <stdio.h>
#define LABEL1 1
#define LABEL2 2
jmp_buf env;

void test(void){
	//1 is return value.
	longjmp(env, LABEL1);
}
void label(void){
	longjmp(env, LABEL2);
}

int main(void){
	int ret;
	//setjmp env-> create lable
	if((ret = setjmp(env)) == 0){
		printf("thus\n");
		test();
	}
	else if(ret == LABEL1){
		printf("1st Label \n");
		label();
	}
	else if(ret == LABEL2)
		printf("2nd Label \n");
	
	return 0;
}
