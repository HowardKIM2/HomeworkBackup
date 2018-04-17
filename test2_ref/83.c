#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(void){
	printf("create \"test\" directory\n");
	mkdir("./test",0644);
	return 0;
}
