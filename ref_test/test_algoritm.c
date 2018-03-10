#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void algoritm(void);
int main(void){
	double start_time, end_time, result;
	
	start_time=clock();
	
	algoritm();
	algoritm();
	algoritm();

	end_time=clock();

	result = ((double)(end_time - start_time)/CLOCKS_PER_SEC);
	printf("%.2lf\n",result);
	return 0;

}
void algoritm(void){
	int i;
	for(i=0;i<100000000;i++);
}
