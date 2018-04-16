#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#define BUF_SIZE 1024
void err_handler(char* msg);
int chk_lines(char* file);
void print_five_lines(int nr, char* file);
int main(int argc, char** argv){
	if(argc != 2){
		printf("use : <%s> <filename>\n",argv[0]);
		exit(-1);
	}
	int fd, nr = 0;
	char buf[BUF_SIZE];

	nr = chk_lines(argv[1]);

	print_five_lines(nr, argv[1]);
}
void err_handler(char* msg){
	fputs(msg,stderr);
	fputc('\n',stderr);
	exit(-1);
}
int chk_lines(char* file){
	int nr = 0, fd;
	char buf[32];
	if((fd = open(file,O_RDONLY,0644))< 0)
		err_handler("open error");
	while(read(fd,buf,1) > 0)
		if(buf[0] == '\n')
			nr++;
	close(fd);
	return nr;	
}	
void print_five_lines(int nr, char* file){
	int i, fd, ret, cur_nr = 0;
	char buf[32];
	if((fd = open(file,O_RDONLY,0644))< 0)
		err_handler("open error");
	printf("upper 5 lines\n");
	while((ret = read(fd,buf,1)) > 0){
		if(cur_nr < 5)
			write(1, buf, ret);
		else if(nr - cur_nr == 5)
			break;

		if(buf[0] == '\n')
			cur_nr++;
	}

	printf("lower 5 lines\n");
	while((ret = read(fd,buf,1)) > 0)
		write(1, buf, ret);
	
}
