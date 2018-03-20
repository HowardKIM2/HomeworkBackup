#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	srand(time(NULL));
	int a[100];
	int i = 0;
	while(i<100){
		a[i] = rand()%4096 + 1;
		printf("%d\n",*(a+i));
		i++;
	}
	return 0;
}
