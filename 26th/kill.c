#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
int main(int argc,char* argv[]){
	if(argc < 2)
		printf("Usage : ./exe pid\n");
	else
		kill(atoi(argv[1]),SIGINT);

	return 0;

}
