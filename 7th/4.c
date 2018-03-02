#include <stdio.h>


// int(*)(float,double,int) pof_test_main(float(*)(int,int))
//int (*pof_test_main(float(*t2)(int,int)))(float,doule,int)
//float pof_test2(int i1,int i2)
//int pof_test(float f,double d,int i)

int pof_test2(float f,double d,int i){
	printf("test1 called!\n");
	return (f+d+i)/3.0;
}

float pof_test1(int i1,int i2){
	printf("test2 called!\n");
	return (i1+i2)*0.23573;
}

//return tes1 : int (*)(float,double,int)
//name        : pof_test_main
//parameter   : float (*)(int ,int)
int  (*pof_test_main(float(*t2)(int,int)))(float, double, int){
	float res;
	res = t2(4,3);
	printf("internal ptm res = %f\n",res);
	return pof_test2;
}

int main(void){
	int res;
	res = pof_test_main(pof_test1)(3.7,2.4,7);
	printf("pof_test_main res = %d\n",res);
	return 0;
}
