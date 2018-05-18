#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define delta_x	0.0001
#define start	-5.000
#define end		5.000

double f_x(double x);
double e;
int main(void)
{
	double x = 0;
	double y[100000] = {0,};
	double accuracy[100000];
	int i;

	e = pow(1+0.000000000001,1/0.000000000001);

	y[50000] = 3;
	for(i=49999;i>=0;i--){
		x = delta_x*i - 5;
		y[i] = 2*x*delta_x*y[i+1]+y[i+1];
	}
	for(i=50001;i<100000;i++){
		x = delta_x*i - 5;
		y[i] = -2*delta_x*y[i-1]*x+y[i-1];
	}
	for(i=0;i<100000;i++)
	{
		accuracy[i] = (y[i] - f_x(delta_x*i - 5))/f_x(delta_x*i - 5);
		if(accuracy[i] < 0)
			accuracy[i] *= (-1);
	}
	for(i=0;i<100000;i++)
		printf("y(%lf) = %.12lf, %.12lf, 오차율 : %.15lf%%\n",delta_x*i-5, y[i],f_x(delta_x*i - 5),accuracy[i]*100);
}
double f_x(double x)
{
	return 3*pow(e,-pow(x,2));
}
