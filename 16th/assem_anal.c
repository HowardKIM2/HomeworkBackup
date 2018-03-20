#include <stdio.h>

int main(void){
	int i;
	int a = 0;

	for(i = 0;i < 10;i++){
		if(i%2)
			a++;
	}
	printf("%d\n",a);
	return 0;
}
