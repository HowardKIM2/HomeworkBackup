#include <stdio.h>
double dac(int sig);
int main(void){
	int sig;
	double v;
	sig = 2077; // ADC value : 2077
	v = dac(sig);

	printf("adc : %d, voltage : %.3lf\n",sig,v);
}
double dac(int sig){
	int minV = -5, maxV = 5, bit = 12;
	int maxSig = 2047; //-2^11 ~ 2^11-1
	int minSig = -2048;
	double v;

	v = (double)maxV/maxSig*sig;
	return v;

}
