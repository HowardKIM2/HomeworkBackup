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
int main(void){
	queue* top = NULL;
	char ch;
	element data;
	enqueue(&top,10);
	enqueue(&top,20);
	enqueue(&top,30);
	disp_queue(&top);

	dequeue(&top);
	disp_queue(&top);
	return 0;
}
queue* get_node(void){
	queue* tmp;
	tmp = (queue*)malloc(sizeof(queue)*1);
	tmp->p_node = NULL;
	return tmp;
}
void enqueue(queue** top,element data){
	queue** tmp = top;
	while(*tmp)
		tmp = &(*tmp)->p_node;
	*tmp = get_node();
	(*tmp)->data = data;
}
int dequeue(queue** top){
	element data;
	queue* tmp = *top;
	if(!(*top)){
		printf("there's no queue!!\n");
		return 0;
	}
	data = tmp->data;
	(*top)= (*top)->p_node;
	free(tmp);
	return data;
}
void disp_queue(queue** top){
	queue* tmp = *top;
	while(tmp){
		printf("data : %d\n",tmp->data);
		tmp = tmp->p_node;
	}
}
