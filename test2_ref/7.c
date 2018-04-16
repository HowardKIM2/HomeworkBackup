#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>
struct dirent* sel_rand_file(DIR* dp,struct dirent* p);
int main(void){
	struct dirent* p;
	DIR* dp;
	struct stat buf;
	char rwx[4] = "RWX";
	int i;
	dp = opendir(".");
	
	//select a random file in the current directory(".")
	p = sel_rand_file(dp,p);
	stat(p->d_name,&buf);

	printf("selected : %s\n",p->d_name);
	//permission print
	printf("Permission : ");
	for(i=0;i<3;i++)
		if((buf.st_mode >> (8-i))&1)
			printf("%c",rwx[i]);
	printf("\n");

}
struct dirent* sel_rand_file(DIR* dp,struct dirent* p){
	int file_num = 0;
	int rand_file;
	struct stat buf;
	srand(time(NULL));
	
	//check how many files in the directory, but directory
	while(p = readdir(dp)){
		stat(p->d_name,&buf);
		if(!S_ISDIR(buf.st_mode))
			file_num++;
	}


	rewinddir(dp);
	printf("total files : %d\n",file_num);
	rand_file = rand() % file_num + 1;
	file_num = 0;

	//among the files, select 1 file randomly
	while(p = readdir(dp)){
		stat(p->d_name,&buf);
		if(!S_ISDIR(buf.st_mode))
			file_num++;
		if(file_num == rand_file)
			break;
	}
	return p;
}
