#include <stdio.h>
int pof1(int num1,int num2){
	printf("pof1 called\n");
	return num1+num2;
}
int (*subpof1(int num1))(int,int){
	printf("subpof1 called\n");
	return pof1;
}
float pof2(int num1,double num2){
	printf("pof2 called\n");
	return (float)(num1*num2);
}
int (*(*pof_test_main(float(*p2)(int,double)))(int))(int,int){
	p2(3,5);
	printf("pof_test_main called\n");
	return subpof1;
}
int main(void){
	int num;
	num = pof_test_main(pof2)(3)(3,5);
	printf("main num = %d\n",num);
	//pof2 called\n
	//pof_test_main called\n
	//subpof1 called\n
	//pof1 called\n
	//main num = 8\n

	return 0;
}
