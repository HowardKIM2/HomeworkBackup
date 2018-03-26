#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc,char** argv){

	struct stat buf;
	char ch;
	stat(argv[1], &buf);
	if(S_ISDIR(buf.st_mode))
		ch = 'd';
	if(S_ISREG(buf.st_mode))
		ch = '-';
	if(S_ISFIFO(buf.st_mode))
		ch = 'p';
	if(S_ISLNK(buf.st_mode))
		ch = 'l';
	if(S_ISSOCK(buf.st_mode))
		ch = 's';
	if(S_ISCHR(buf.st_mode))
		ch = 'c';
	if(S_ISBLK(buf.st_mode))
		ch = 'b';
	printf("%c\n",ch);

	return 0;


}
