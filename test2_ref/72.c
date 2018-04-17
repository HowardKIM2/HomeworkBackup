#include <stdio.h>
#include <dirent.h>
#include <unistd.h>

int main(int argc,char** argv){
	DIR* dp;
	struct dirent* p;
	int i = 1;
	//select the directory to be listed
	if(argc == 2)
		dp = opendir("argv[1]");
	else
		dp = opendir(".");
	
	while(p = readdir(dp)){
		printf("%-16s",p->d_name);
		if(!(i%5))
			printf("\n");
		i++;
	}
	printf("\n");
}
