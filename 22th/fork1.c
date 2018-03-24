#include <unistd.h>
#include <stdio.h>

int main(void){
	printf("before ");
	fork();
	printf("after ");
	return 0;

}
