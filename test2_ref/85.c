#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <stdlib.h>
void test(char* name);
bool chk_incld_abc(char* name);
int main(void){
	DIR* dp;
	struct dirent* p;
	struct stat buf;
	dp = opendir(".");
	while(p = readdir(dp)){
		stat(p->d_name,&buf);
		if(S_ISDIR(buf.st_mode)&&(p->d_name[0] != '.'))
			test(p->d_name);
	}
}
void test(char* name){
	srand(time(NULL));
	printf("DIR : %s\n",name);
	DIR* dp;
	char* file;
	int nl, i, fd;
	dp = opendir(name);
	chdir(name);
	nl = rand()%5 + 5;
	file = (char*)malloc(sizeof(char)*nl);
	
	for(i=0;i<nl;i++)
		file[i] = 97 + rand()%26;


	if((fd = creat(file,0644)) < 0)
		printf("create fail\n");
	else
		printf("%s created\n",file);

	sleep(1);
	closedir(dp);
	chdir("..");
}
bool chk_incld_abc(char* name){
	char* chk = NULL;
	if(strchr(name,'a'))
		return true;
	if(strchr(name,'b'))
		return true;
	if(strchr(name,'c'))
		return true;
	return false;
}
