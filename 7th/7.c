/*
	memcpy is faster than memmove
	but, memcpy doesn't offer memory protection
	So, If the memory is weird when using memcpy, use memmove
*/

#include <stdio.h>
#include <string.h>

int main(void){
	char src[30] = "This is amazing";
	char *dst = src + 3;

	printf("before memcpy = %s\n",src);
	memcpy(dst,src,3);
	printf("after memcpy = %s\n",dst);

	return 0;


}
