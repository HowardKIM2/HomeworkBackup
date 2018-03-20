#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define ERROR -1

int main(void){
	
	int filedes;
	char pathname[] = "temp.txt";
	if((filedes = open(pathname,O_CREAT | O_RDWR | O_EXCL, 0644 )) == ERROR)
	{
		printf("File Open Error!\n");
	}
	printf("filedes : %d\n",filedes);
	close(filedes);

	return 0;

}
