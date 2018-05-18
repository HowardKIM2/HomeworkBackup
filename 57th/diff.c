#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#define delta_x	0.001
#define start	-5.000
#define end		5.000

#define y(x)	y[(long)((x-start)/delta_x)]
#define init_val(a,b)	y(a)=b

double e;

void set_exp_val(void);
double f_x(double x);
double y_prime_equation(double x,double y);
void diff_equation(double (*p)(double x,double y), double* y);
void set_accuracy(double* y,double (*p)(double),double* accuracy);
void write_txt_data(int fd, double* y, double (*p)(double x));
int main(void)
{
	double x = 0;
	double y[10000];
	double accuracy[10000];
	int i;

	/*e = 2.713xxxxxxxxxx*/
	set_exp_val();

	/*y(0) = 3*/
	init_val(0,3);
	
	/*set y[0] ~ y[9999]*/
	diff_equation(y_prime_equation, y);

	/*set accuracy between y and f_x*/
	set_accuracy(y,f_x,accuracy);

	
	for(i=0;i<10000;i++)
		printf("y(%lf) = %.12lf, %.12lf, 오차율 : %.3lf%%\n",delta_x*i-5, y[i],f_x(delta_x*i - 5),accuracy[i]*100);

	int fd;
	fd = open("data.txt",O_CREAT|O_TRUNC| O_RDWR,0644);
	
	write_txt_data(fd,y,f_x);
}
//e = (1+dx)^(1/dx) = (1 + 0.00000000001)^100000000000 which is about 2.713xxxxxxxx
void set_exp_val(void)
{
	e = pow(1+0.000000000001,1/0.000000000001);
}
//the origin result of differential equation, 3e^(-x^2)
double f_x(double x)
{
	return 3*pow(e,-pow(x,2));
}
//physics modeling, y'=-2xy. return value must be y'
double y_prime_equation(double x,double y)
{
	return -2*x*y;
}
void diff_equation(double (*p)(double x,double y), double* y)
{
	int i;
	double x = 0;
	/*x = -5 ~ 0*/
	for(i = 4999 ;i>=0;i--){
		x = delta_x*i - 5;
		y[i]= -p(x+delta_x,y[i+1])*delta_x+y[i+1];
	}
	/*x = 0 ~ 5*/
	for(i=5001;i<10000;i++){
		x = delta_x*i - 5;
		y[i] = p(x-delta_x,y[i-1])*delta_x+y[i-1];
	}
}
void set_accuracy(double* y,double(*p)(double),double* accuracy)
{
	int i;
	for(i=0;i<10000;i++)
	{
		accuracy[i] = (y[i] - p(delta_x*i - 5))/p(delta_x*i - 5);
		/*accuracy value must be a positive number*/
		if(accuracy[i] < 0)
			accuracy[i] *= (-1);
	}
}
void write_txt_data(int fd, double* y, double (*p)(double x))
{
	int i;
	double x, tmp;
	char buf[64];
	for(i=0;i<10000;i++)
	{
		x = delta_x*i - 5;
		tmp = p(x);
		sprintf(buf,"%d\t%.12lf\t%.12lf\n",i,y[i],tmp);
		buf[strlen(buf)] = '\0';
		write(fd,buf,strlen(buf));
		
	}
}
