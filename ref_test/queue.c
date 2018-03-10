#include <stdio.h>
#include <stdlib.h>
#define element int

typedef struct __queue{
	element data;
	struct __queue* p_node;
}queue;

queue* get_node(void);
void enqueue(queue** top,element data);
int dequeue(queue** top);
void disp_queue(queue** top);
char _getch(void);
int _getData(void);
int main(void){
	queue* top = NULL;
	char ch;
	element data;
	while(1){
		
		printf("명령어 입력(quit('q'),insert('i'),display('p'),dequeue('d')) : ");
		ch = _getch();
		system("clear");
		switch(ch){
			case 'q':
				printf("quit!!\n");
				break;
			case 'i':
				printf("input(int type data) : ");
				data = _getData();
				enqueue(&top,data);
				printf("data %d inserted\n",data);
				break;
			case 'p':
				printf("current queue :\n");
				disp_queue(&top);
				break;
			case 'd':
				printf("dequeue : %d\n",dequeue(&top));
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
void enqueue(queue** top,element data){
	queue* tmp;
	if(!(*top)){
		tmp = get_node();
		tmp->data = data;
		*top = tmp;
	}
	else
		enqueue(&((*top)->p_node),data);
}
int dequeue(queue** top){
	element data;
	if(!(*top)){
		printf("there's no queue!!\n");
		return 0;
	}
	data = (*top)->data;
	(*top)= (*top)->p_node;
	return data;
}
void disp_queue(queue** top){
	if(*top){
		printf("%d\n",(*top)->data);
		disp_queue(&((*top)->p_node));
	}
	else
		return;
}
char _getch(void){
	char buf,ch;
	while((buf = getchar())!=10)
		ch = buf;
	return ch;
}
int _getData(void){
	int buf,data;
	scanf("%d%*c",&data);
	return data;
}
