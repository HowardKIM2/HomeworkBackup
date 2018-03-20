#include "my_scanf.h"
int my_scanf(char* buf,int size){
	int nr = read(0,buf,size);
	return nr;
	
}
