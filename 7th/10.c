#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
	char src[20] = "made in korea";
	char dst[20] = "made in china";
	if(!strncmp(src,dst,9))
		printf("src == dst\n");
	else
		printf("src != dst\n");
	return 0;
}
