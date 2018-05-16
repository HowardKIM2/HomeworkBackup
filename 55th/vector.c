#include "vector.h"
#include <stdio.h>
#include <math.h>

void print_vector(double* x)
{
	printf("%lf, %lf, %lf\n",x[0],x[1],x[2]);
}
void vector_sum(double* res,double* x, double* y){
	int i;
	for(i=0;i<3;i++)
		res[i] = x[i] + y[i];
}
void vector_sub(double* res,double* x, double* y){
	int i;
	for(i=0;i<3;i++)
		res[i] = x[i] - y[i];
}
void vector_scalar_mul(double* res, double* x, double scalar)
{
	int i;
	for(i=0;i<3;i++)
		res[i] = x[i]*scalar;
}
double vector_inner_product(double* x, double* y)
{
	int i;
	double res = 0;
	for(i=0;i<3;i++)
		res += x[i]*y[i];
	return res;
}
void vector_cross_product(double* res, double* x, double* y)
{
	int i;
	for(i=0;i<3;i++)
		res[i] = x[(i+1)%3]*y[(i+2)%3]-x[(i+2)%3]*y[(i+1)%3];
	
}
double vector_abs_val(double* x)
{
	int i;
	double res = 0;
	for(i=0;i<3;i++)
		res += x[i]*x[i];
	res = sqrt(res);
	return res;
}
void vector_gso_normalization(double* x0, double* x1, double* x2,double* w0, double* w1, double* w2)
{
	int i;

	for(i=0;i<3;i++)
		w0[i] = x0[i];
	
	for(i=0;i<3;i++)
	{
		w1[i] = x1[i] - ((vector_inner_product(x1,w0))/pow(vector_abs_val(w0),2))*w0[i];
	}
	
	for(i=0;i<3;i++)
	{
		w2[i] = x2[i] - ((vector_inner_product(x2,w0))/pow(vector_abs_val(w0),2))*w0[i] 
					- ((vector_inner_product(x2,w1))/pow(vector_abs_val(w1),2))*w1[i];
	}
	
	
}
