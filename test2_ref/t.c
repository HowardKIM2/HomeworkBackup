#include <stdio.h>
#include <string.h>

int main(void){
	char* ch1 = "aaaabbbss";
	char ch2 = 'a';
	char* res;
	int b;
	res = strchr(ch1,ch2);
	if(res)
		printf("Res : %s\n",res);
}
