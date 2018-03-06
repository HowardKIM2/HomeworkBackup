#include <stdio.h>
#include <string.h>
int StrCmp(char* str1,char* str2);
int main(void){
	char* str1 = "TI Cortex-R5F Safety MCU is very good to Real-Time System.";
	char* str2 = "Safety MCU";
	int index;
	index = StrCmp(str1,str2);

	printf("index = %d\n",index);


}
int StrCmp(char* str1,char* str2){
	int index, length, chk;
	length = strlen(str1) - strlen(str2);
	for(index = 0;index < length ;index++){	
		chk = strncmp(str1+index,str2,strlen(str2));
		if(!chk)
			break;
	}
	return index;
}
