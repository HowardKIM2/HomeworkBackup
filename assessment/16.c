#include <stdio.h>
double dac(int minV,int maxV,int bit,int digit);
int main(void){
	int minV = -5, maxV = 5;
	int digit = 12677, bit = 16 ;
	double v;

	v = dac(minV,maxV,bit,digit);
	printf("v = %.4lf\n",v);


	return 0;
}
double dac(int minV,int maxV,int bit,int digit){
	double v=1;
	int maxDigit = (1<<(bit-1)) - 1;
	int minDigit = -1*(1<<(bit-1)) ;
	int baseDigit = (digit>=0)?maxDigit:minDigit;
	int baseV = (digit>=0)?maxV:minV;
	
	v = baseV *((double)digit / baseDigit);
	return v;
}
