#include <stdio.h>
#include <stdlib.h>
int main(void){
	int num = 1111231232, size = 1, i = 1;
	int* a;
	a = (int*)malloc(sizeof(int)*size);
	printf("%d = ",num);
	while(1){	
		*(a+size-1) = num&(0xfff);
		num>>=12;
		if(!num)
			break;
		size++;
		a = (int*)realloc(a,sizeof(int)*size);
	}
	printf("0x ");
	while(size-i+1){
		printf("%x ",*(a+size-i));
		i++;
	}
	printf("\n");
	return 0;
}
