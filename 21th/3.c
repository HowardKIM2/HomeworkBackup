#include <stdio.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>
int main(int argc, char** argv){
	int flag = 0;
	int cmd;
	DIR* dp;
	struct dirent* p;
	int i = 1;

	while((cmd = getopt(argc, argv, "abcd")) > 0){
		switch(cmd){
			case 'a':
				flag |= 1;
				break;
			case 'b':
				flag |= 2;
				break;
			case 'c':
				flag |= 4;
				break;
			case 'd':
				flag |=8;
				break;
		
		}
	}
	dp = opendir(".");
	while((p = readdir(dp)) > 0){
		if(!(flag&1)){
			if(p->d_name[0] == '.')
				continue;
		}
		printf("%-16s ",p->d_name);
		if(i%5 == 1)
			printf("\n");
		i++;
	}
	printf("\n");

}
