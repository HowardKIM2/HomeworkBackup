#include <fcntl.h>
#include <stdlib.h>
#include <setjmp.h>
#include <stdio.h>

jmp_buf env;

void should_be_ignore(void);
int main(void){
	int ret;
	if((ret = setjmp(env)) == 0)
		should_be_ignore();
	else if(ret > 0)
		printf("execute this!\n");
	return 0;
}
void should_be_ignore(void){
	longjmp(env,1);
	printf("This sentence should be ignored(jumped)\n");
	
}
