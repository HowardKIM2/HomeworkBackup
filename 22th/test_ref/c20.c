#include <stdio.h>

int main(void){
	int x;
	printf("input x: ");
	scanf("%d",&x);
	printf("arranged value (134217728) : %d\n",x&(-134217728));
}
