#include <stdio.h>
#include <time.h>
#include <stdlib.h>
typedef struct __employee{
		char* name;
		int salary;
}employee;
void init_salary(employee* p);
double avr_salary(employee *p);
void print_best(employee *p);
int main(void){
	employee p[5]={{"Mark",},{"Jason",},{"Rena",},{"Jay",},{"Sheldon",}}; 
	int i;
	double avr;
	srand(time(NULL));
	
	init_salary(p);
	for(i=0;i<5;i++)
		printf("%s, %d\n",p[i].name,p[i].salary);
	avr = avr_salary(p);
	printf("average : %.2lf\n",avr);
	print_best(p);
	return 0;
}
void init_salary(employee* p){
	int i;
	for(i=0;i<5;i++)
		p[i].salary = rand()%5000000;
}
double avr_salary(employee *p){
	double res = 0;
	int i;
	for(i = 0;i<5;i++)
		res += p[i].salary;
	res /= 5;
	return res;
}
void print_best(employee *p){
	int tmp = 0,i, index;
	for(i=0;i<5;i++){
		if(tmp < p[i].salary){
			tmp = p[i].salary;
			index = i;
		}
	}
	printf("The best salaryman : %s, %d\n",p[index].name,p[index].salary);
}	
