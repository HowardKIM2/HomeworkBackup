#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>

int main(void){
	DIR* dp;
	int i = 0;
	struct dirent *p;
	//directory open , '.' means current directory
	dp = opendir(".");
	while(p = readdir(dp)){  //p = directoy list
		if(p->d_name[0] == '.')
			continue;
		printf("%-16s ",p->d_name);
		if((i + 1)%5 == 0)  // 5 unit print ('\n')
			printf("\n");
		i++;
	}
	printf("\n");
	closedir(dp);

	return 0;
}
