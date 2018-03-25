#include <stdio.h>
int f_x(int x);
double integral(int x1,int x2);
int main(void){
	double res;
	res = integral(1,3);
	printf("%.5lf\n",res);
	return 0;
}
int f_x(int x){
	int y;
	y = 4*x*x + 5*x + 1; //4x^2+5x+1

	return y;
}
double integral(int x1,int x2){
	int n = 100000, i;
	double dx = (double)(x2 - x1)/n;
	double res = 0, x = x1; 
	for(i = x1; x <= x2; i++){
		res+= f_x(x)*dx;
		x = x + dx;
	}
	return res;
}
