#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
typedef struct __queue{
	int data;
	struct __queue* link;
}queue;

void disp_student_manager(int* score,char* name,int size);
void confirm_info(char *name,int score);
int main(void){	
	int score;
	//Slab 할당자가 32byte를 관리하기 때문에 성능이 빠름.
	char name[32] = {0};
	queue* head = NULL; 
	
	disp_student_manager(&score,name,sizeof(name));
	confirm_info(name,score);

	return 0;
}
void disp_student_manager(int* score,char* name,int size){
	char* str1 = "이름을 입력하시오: ";
	char* str2 = "성적을 입력하시오: ";
	char tmp[32] = {0};

	write(1,str1,strlen(str1));
	read(0, name, size);
	write(1,str2,strlen(str2));
	read(0, tmp, sizeof(tmp));
	
	//string to integer
	*score = atoi(tmp);

}
void confirm_info(char *name,int score){
	printf("name = %s, score : %d\n",name,score);
}
