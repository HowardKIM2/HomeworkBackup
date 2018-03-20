#include <stdio.h>
#include <stdlib.h>

typedef struct __student{
	int index;
	int score;
	char name[20];
}student;
typedef struct __queue{
	student data;
	struct __queue* p_node;
}queue;

queue* get_node(void);
queue* enqueue(queue** top,student data);
void dequeue(queue** top,int index);
void disp_queue(queue** top);
char _getch(void);
int main(void){
	queue* top = NULL;
	char ch;
	student data;
	int index;

	while(1){
		
		printf("명령어 입력(quit('q'),insert('i'),display('p'),dequeue('d')) : ");
		ch = _getch();
		system("clear");
		switch(ch){
			case 'q':
				printf("quit!!\n");
				break;
			case 'i':
				printf("input(name) : ");
				scanf("%s",data.name);
				printf("input(score) : ");
				scanf("%d%*c",&data.score);
				top = enqueue(&top,data);
				printf("name : %s, score : %d inserted\n",data.name,data.score);
				break;
			case 'p':
				printf("current queue :\n");
				disp_queue(&top);
				break;
			case 'd':
				printf("input deleted data's index : ");
				scanf("%d%*c",&index);
				dequeue(&top,index);
				printf("%d index deleted!!\n",index);
				break;
			default:
				printf("wrong instruction!!\n");
				break;
		}
		if(ch == 'q')
			break;
		printf("\n\n");
	}
	return 0;
}
queue* get_node(void){
	queue* tmp;
	tmp = (queue*)malloc(sizeof(queue)*1);
	tmp->p_node = NULL;
	return tmp;
}
queue* enqueue(queue** top,student data){
	queue* prev;
	queue* b_top;
	int i = 0;
	if(!(*top)){
		b_top = get_node();
		b_top->data = data;
	}
	else{
		b_top = *top;
		while(1){
			if(*top){
				prev = (*top);
				(*top) = (*top)->p_node;
			}
			else{
				*top = get_node();
				(*top)->data = data;
				(*top)->data.index = i;
				prev->p_node = *top;
				break;
			}
			i++;
		}
	}
	return b_top;
}
void dequeue(queue** top,int index){
	if(!(*top)){
		printf("there's no queue!!\n");
	}
	(*top)= (*top)->p_node;
}
void disp_queue(queue** top){
	queue* tmp = *top;
	while(tmp){
		printf("%d. name : %s, score : %d\n",tmp->data.index,tmp->data.name,tmp->data.score);
		tmp = tmp->p_node;
	}
}
char _getch(void){
	char buf,ch;
	while((buf = getchar())!=10)
		ch = buf;
	return ch;
}












