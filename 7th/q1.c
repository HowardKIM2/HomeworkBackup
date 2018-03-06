#include <stdio.h>
int pof_test1(float num1,double num2,int num3){
	printf("test1 called\n");
	return (int)(num1+num2+num3);
}
float pof_test2(int num1,int num2){
	printf("test2 called\n");
	return (float)(num1+num2)/2;
}
int (*pof_test_main(float(*p)(int,int)))(float,double,int){
	p(4,5);
	return pof_test1;
}

int main(void){
	int num;
	num = pof_test_main(pof_test2)(1,2,3);
	printf("test_main num = %d\n",num); //6
	return 0;
}
