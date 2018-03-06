#include <stdio.h>
int adc(int minV,int maxV,int bit,double v);
int main(void){
	int maxV = 12, minV = -12;
	int bit = 24;
	double v = 9.7;
	int digit;

	digit = adc(minV,maxV,bit,v);
	
	printf("res = %d\n",digit);

	return 0;
}
int adc(int minV,int maxV,int bit,double v){
	int maxDigit = (1<<(bit-1)) -1;
	int minDigit = -1*(1<<(bit-1));
	int baseV =v>0 ? maxV : minV;
	int baseDigit = v>=0 ? maxDigit:minDigit;
	int digit;

	digit = (v / baseV)*baseDigit;

	return digit;
}

