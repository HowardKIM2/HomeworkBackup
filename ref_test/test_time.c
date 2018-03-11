#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void algoritm(void);
int main(void){
	time_t ts=time(NULL);
	time_t te;
	double res;
	int i;
	for(i=0;i<20;i++)
		algoritm();
	
	te = time(NULL);
	res = difftime(te,ts);
	printf("res = %.lfsec (20 times try)\n",res);
	return 0;

}
void algoritm(void){
	system("./a.out");
}
