#include <stdio.h>
#include <dirent.h>
#include <fcntl.h>

int main(void){
	DIR* dp;
	struct dirent* p;
	int i = 1;
	dp = opendir(".");
	while(p = readdir(dp)){
		if(p->d_name[0] == '.')
			continue;
		
		printf("%-16s ",p->d_name);
		if(i%5 == 0)
			printf("\n");
		i++;
	}
	printf("\n");

	return 0;
}
