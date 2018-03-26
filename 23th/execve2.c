#include <unistd.h>
#include <stdio.h>
int main(void){
	//fork와는 다르게, 실행 시 프로세스를 바꿔버림.
	execlp("ps","ps","-e","-f",NULL);
	
	printf("after\n");
	return 0;
}
