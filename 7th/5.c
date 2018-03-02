#include <stdio.h>
int subpof1(int i1,int i2){
	printf("subpof1!\n");
	return i1+i2;
}
int (*pof1(int i1))(int,int){
	printf("pof1!\n");
	return subpof1;
}
float pof2(int i1,double d1){
	printf("pof2!\n");
	return i1+d1/3.0;
}
int (*(*pof_test_main(float(*p2)(int,double)))(int))(int,int){
	float res;
	res = p2(3,7.7);
	printf("pof_test_main res = %.2f\n",res);
	return pof1;
}

int main(void){
	int res;
	//int (*(*)(int))(int,int)
	//res = subpof1(3,4);
	//res = pof1(1)(3,4);
	res = pof_test_main(pof2)(1)(3,4);
	printf("main res = %d\n",res);
	
	return 0;
}
