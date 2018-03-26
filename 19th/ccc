#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
typedef struct {
	char fname[20];
	int fsize;
}F_info;

int file_size(int fd){
	int fsize, old;
	old = lseek(fd, 0, SEEK_CUR);
	fsize = lseek(fd, 0, SEEK_END);
	lseek(fd, old, SEEK_SET);
	return fsize;
}

int main(int argc, char *argv[]){
	int src, dst, ret;
	char buf[1024];
	F_info info;
	int i;
	dst = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	printf("argc : %d\n",argc);
	for(i=0;i<argc-2;i++){
		src = open(argv[i+1],O_RDONLY);
		strcpy(info.fname, argv[i+1]);
		info.fsize = file_size(src);
		write(dst, &info, sizeof(info));
		printf(" i = %d\n",i);
		while(ret = read(src, buf, sizeof(buf))){
			write(dst, buf, ret);
		}
		printf("%s %d\n",info.fname,info.fsize);
		close(src);
	}
	close(dst);
	return 0;
}
