#include <stdio.h>

float pof1(int num1, int num2){
	printf("pof1 called\n");
	return (float)(num1+num2);
}

float (*subpof1(float(*p1)(int,int)))(int, int){
	printf("subpof1 called\n");
	return pof1;
}

void pof2(void){
	printf("pof2 called\n");
}

float (*(*test(void (*p)(void)))(float(*)(int,int)))(int,int){
	p();
	printf("test called\n");
	return subpof1;
}

int main(void){
	float num;
	num = test(pof2)(pof1)(3,4);

	printf("main num = %.2f\n",num);

	//pof2 called\n
	//test called\n
	//subpof1 called\n
	//pof1 called\n
	//main num = 7.00\n
	return 0;
}
