#include <stdio.h>
#include <unistd.h>
int main(void){
	FILE *fp = fopen("a.txt","r");
	char buf[1024] = "\0";
	int ret;

	while(ret = fread(buf, 1, sizeof(buf), fp)){
		usleep(1000000);
		fwrite(buf,1,ret,stdout);
	}
	fclose(fp);
	return 0;
}
