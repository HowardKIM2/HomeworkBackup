#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <string.h>
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
	printf("DIR : %s\n",name);
	DIR* dp;
	struct dirent* p;
	struct stat buf;
	dp = opendir(name);
	while(p = readdir(dp)){
		stat(p->d_name, &buf);
		if(!chk_incld_abc(p->d_name))
			continue;
		if(S_ISDIR(buf.st_mode))
			printf(" - Directory : %s\n",p->d_name);
		else
			printf(" - File : %s\n",p->d_name);
	}
	closedir(dp);
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
