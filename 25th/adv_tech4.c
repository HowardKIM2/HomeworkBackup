#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int score;
	char name[20];
}ST;

typedef struct{
	int count;
	char name[20];
	int score[0];
}FLEX;

int main(void){
	FLEX* p = (FLEX*)malloc(4096);
	int i;
	//34807 -> segmentation fault.
	for(i=0;i<34806;i++)
		p->score[i] = i;
	for(i=0;i<34806;i++)
		printf("data : %d\n",p->score[i]);

	printf("size : %d\n",sizeof(FLEX));
	return 0;

}
