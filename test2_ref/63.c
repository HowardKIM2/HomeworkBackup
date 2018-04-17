#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
void chk_file(struct stat buf);
int main(int argc, char** argv){
	struct stat buf;
	if(argc != 2){
		printf("use : %s <file_name>\n",argv[0]);
		exit(1);
	}

	stat(argv[1], &buf);	
	chk_file(buf);

	return 0;
}
void chk_file(struct stat buf){
	if(S_ISDIR(buf.st_mode))
		printf("directory\n");
	if(S_ISREG(buf.st_mode))
		printf("regular\n");
	if(S_ISFIFO(buf.st_mode))
		printf("pipe\n");
	if(S_ISSOCK(buf.st_mode))
		printf("socket\n");
	if(S_ISCHR(buf.st_mode))
		printf("character device\n");
	if(S_ISBLK(buf.st_mode))
		printf("block device\n");
}
