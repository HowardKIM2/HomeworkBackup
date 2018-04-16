#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "my_scanf.h"
int main(int argc, char** argv){
	int nr;
	char buf[1024] = {0};

	nr = my_scanf(buf, sizeof(buf));
	printf("nr = %d\n",nr);
	write(1,buf,nr);
	
	return 0;
}
