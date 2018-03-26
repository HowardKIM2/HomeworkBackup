#include <stdio.h>
#include <sys/types.h>
int main(void){
	while(1){
		sleep(1);
		system("date");
	}
	printf("after\n");
	return 0;

}
