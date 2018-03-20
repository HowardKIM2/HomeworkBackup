#include <stdio.h>
#define inc_each(x,y) {x++;y++;}
int main(void){
	int x = 10, y = 5;
	if(x > y)
		do{
			inc_each(x,y);
		}while(0);	
	else
	 	x = y;

	printf("x = %d, y = %d\n",x,y);
	return 0;
}
