#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
	char* a = "123";
	int i;
	int num[3];
	for(i=0;i<strlen(a);i++){
		num[i] = atoi(&a[i]);
	}

	for(i=0;i<3;i++){
		printf("%d\n",num[i]);
	}
}
