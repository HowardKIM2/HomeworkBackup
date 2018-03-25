#include <stdio.h>
#include <string.h>
int cntSmallLetter(char* str);
int main(void){
	char* str = "WTF, Where is my Pointer ? Where is it ?";
	int cnt;
	cnt = cntSmallLetter(str);
	printf("Small Letter : %d(EA)\n",cnt);

}
int cntSmallLetter(char* str){
	int len = strlen(str);
	int i,cnt = 0;
	for(i = 0;i < len;i++){
		if((str[i] > 96)&&(str[i] < 123 ))
			cnt++;
	}
	return cnt;
}
