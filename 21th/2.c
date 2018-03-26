#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc,char* argv[]){
	int cmd;
	cmd = getopt(argc, argv, "abcd");
	while((cmd = getopt(argc, argv, "abcd")) > 0){
		switch(cmd){
			case 'a':
				printf("a option added\n");
				break;
			case 'b':
				printf("b option added\n");
				break;
			case 'c':
				printf("c option added\n");
				break;
			case 'd':
				printf("d option added\n");
				break;
			default :
				printf("wrong option added\n");
				break;
		}
	}
	return 0;
}
