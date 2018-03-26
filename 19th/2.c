#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
typedef struct{
	char fname[20];
	int fsize;
}F_info;

#define min(x,y) (((x) < (y)) ? (x) : (y))

int main(int argc, char* argv[]){
	int src, dst, len, ret;
	F_info info;
	char buf[1024];
	src = open(argv[1], O_RDONLY);

	while(read(src,&info,sizeof(info))){
		dst = open(info.fname, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		printf("info.name : %s, info.fsize : %d\n",info.fname, info.fsize);
		while(info.fsize > 0){
			len = min(sizeof(buf),info.fsize);
			ret = read(src, buf, len);
			write(dst, buf, ret);
			info.fsize -= ret;
		}
		close(dst);
	}
	close(src);
	return 0;

}
