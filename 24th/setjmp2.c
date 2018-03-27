#include <fcntl.h>
#include <stdlib.h>
#include <setjmp.h>
#include <stdio.h>

jmp_buf env;

void test(void){
	int flag = -1;
	if(flag < 0)
		longjmp(env,1);
	printf("call test\n");
}

int main(void){
	int ret;
	if((ret = setjmp(env)) == 0)
		test();
	else if(ret > 0)
		printf("error\n");
	return 0;

}
