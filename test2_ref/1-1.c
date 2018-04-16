#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define pi 3.14159
#define phase 0
#define bit 10
#define maxV 5
#define minV -5
double func_sin(double T, double t);
double* sampling(double (*func)(double T,double t),double T, double ts);
double* adc(double* smp_val, int smp_num, int res_bit);
int main(void){
	double T = 0.5, f, w;
	double val;
	double* smp_val;
	f = 1/T;
	w = 2*pi*f;
	val = func_sin(T,0.125);
	
	printf("T : %.2lf(sec)\nf : %.2lf(Hz)\nw : %.2lf(rad/sec)\n",T,f,w);
	smp_val = sampling(func_sin, T, 0.005);
	
	int i;
	for(i=0;i<=T/0.005;i++)
		printf("sampling val : %lf\n",smp_val[i]);

	smp_val = adc(smp_val,(int)(T/0.005),bit);
	
	printf("\nDigitalization : \n");
	for(i=0;i<=T/0.005;i++)
		printf("digit val : %lf\n",smp_val[i]);
}

double func_sin(double T, double t){
	double ret;
	//sin(wt) , 2*pi/T == w
	ret = sinf(2*pi*t/T);
	return ret;
}

double* sampling(double (*func)(double T,double t), double T, double ts){
	double* smp_val;
	int i;
	smp_val = (double*)malloc(sizeof(double) * (int)T/ts);
	
	printf("sampling frequency : %.0lf\nsampling num : %.0lf\n",1/ts,T/ts);
	//sampling to smp_val[], T/ts : sampling number
	for(i = 0;i <= T/ts;i++)
		smp_val[i] = func(T,i*ts);
	
	return smp_val;
}
double* adc(double* smp_val, int smp_num, int res_bit){
	double dv;
	double del;
	int i, resolution = pow(2,bit);
	dv = (double)maxV/resolution;
	printf("dv : %lf\n",dv);
	printf("smpnum : %d\n",smp_num);
	for(i=0;i<=smp_num;i++){
		del = smp_val[i];
		if(smp_val[i] > 0){
			while(1){
				if(del < dv)
					break;
				del -= dv;
			}
			smp_val[i] -= del;
		}
		else{
			while(1){
				if(del > -dv)
					break;
				del += dv;
			}
			smp_val[i] += del;
		}
	}
	return smp_val;
}
