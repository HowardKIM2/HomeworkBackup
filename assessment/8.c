#include <stdio.h>
double integral(double x1,double x2);
double func(double x);
int main(void){
	double x1 = 1,x2 = 2;
	double res;
	
	res = integral(x1,x2);

	printf("res = %.2lf\n",res);
	
	return 0;
}
double integral(double x1,double x2){
	double res = 0, x, area;
	int i, n = 10000;
	double dx = (x2 - x1)/n;
	x = x1;
	for(i=x1;x<x2;i++){
		area = func(x)*dx;
		res += area;
		x+=dx;
	}
	return res;
}
double func(double x){
	double f_x;
	f_x = 3*x*x+7*x;
	return f_x;
}
