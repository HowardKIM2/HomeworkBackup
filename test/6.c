#include <stdio.h>
#include <string.h>
int compStr(char* str,char* search);
int main(void){
	char* str = "TI Cortex-R5F Safety MCU is very good to Real-Time System.";
	char* search = "Safety MCU";
	int index;
	index = compStr(str,search);
	if(index == -1)
		printf("일치하는 문장 없음\n");
	else
		printf("%d번째부터 시작\n",index+1);
}
int compStr(char* str,char* search){
	int index = -1, len, chk;
	for(index = 0;index < len; index++){
		chk = strncmp(str+index,search,strlen(search));
		if(!chk)
			break;
	}
	return index;

}
