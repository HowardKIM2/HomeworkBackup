#include <stdio.h>
#include <stdlib.h>
typedef struct __queue{
	char* data;
	struct __queue* link;
}queue;
queue* get_queue_node(void);
void ins_queue(queue** head,char* data);
void print_queue(queue** head);
int main(void){
	queue* head = NULL;
	ins_queue(&head,"aaa");
	ins_queue(&head,"bbb");
	ins_queue(&head,"ccc");
	ins_queue(&head,"ddd");
	ins_queue(&head,"eee");
	print_queue(&head);
	return 0;
}
queue* get_queue_node(void){
	queue* tmp;
	tmp = (queue*)malloc(sizeof(queue)*1);
	tmp->link = NULL;
	return tmp;
}
void ins_queue(queue** head,char* data){
	queue** tmp = head;
	while(*tmp)
		tmp = &(*tmp)->link;
	*tmp = get_queue_node();
	(*tmp)->data = data;
}
void print_queue(queue** head){
	queue* tmp = *head;
	while(tmp){
		printf("data : %s\n",tmp->data);
		tmp = tmp->link;
	}
}
