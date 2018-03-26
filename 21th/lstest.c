#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#define A (1<<0)
#define B (1<<1)
#define C (1<<2)
#define D (1<<3)
#define E (1<<4)
#define F (1<<5)
#define G (1<<6)

void check_flag(int flag){
	int i, tmp = flag;
	
	for(i = 0;i < 7; i++){
		switch(tmp & (1<<i)){
			case A:
				printf("A\n");
				break;	
			case B:
				printf("B\n");
				break;
 			case C:
				printf("C\n");
				break;
			case D:
				printf("D\n");
				break;
			case E:
				printf("E\n");
				break;
			case F:
				printf("F\n");
				break;
			case G:
				printf("G\n");
				break;
			}
	}
}


int main(int argc, char** argv){
	char cmd;
	int flag = 0;
	while((cmd = getopt(argc, argv, "abcdefg")) > 0){
		switch(cmd){
			case 'a':
				flag |= 1 << 0;
				break;
			case 'b':
				flag |= 1 << 1;
				break;
			case 'c':
				flag |= 1 << 2;
				break;
			case 'd':
				flag |= 1 << 3;
				break;
			case 'e':
				flag |= 1 << 4;
				break;
			case 'f':
				flag |= 1 << 5;
				break;
			case 'g':
				flag |= 1 << 6;
				break;
		}
	}
	check_flag(flag);
	return 0;
}
