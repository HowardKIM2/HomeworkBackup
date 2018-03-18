#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct __queue{
	int data;
	struct __queue *link;
}queue;
queue* get_queue_node(void);
void ins_queue(queue** head,int data);
int de_queue(queue** head);
bool is_not_empty(queue** head);
int main(void){
	queue* head = NULL;
	ins_queue(&head,10);
	ins_queue(&head,20);
	ins_queue(&head,30);
	
	printf("%d\n",de_queue(&head));
	printf("%d\n",de_queue(&head));
	printf("%d\n",de_queue(&head));
	printf("%d\n",de_queue(&head));

	return 0;
}
queue* get_queue_node(void){
	queue* tmp;
	tmp = (queue*)malloc(sizeof(queue)*1);
	tmp->link = NULL;
	return tmp;
}
void ins_queue(queue** head,int data){
	queue** tmp = head;
	while(*tmp)
		tmp = &(*tmp)->link;
	*tmp = get_queue_node();
	(*tmp)->data = data;
}
int de_queue(queue** head){
	queue* tmp = *head;
	int data;
	if(!is_not_empty(&tmp)){
		printf("Error : no data in queue\n");
		return 0;
	}
	data = tmp->data;
	(*head) = (*head)->link;
	free(tmp);
	return data;
}
bool is_not_empty(queue** head){
	if(*head)
		return true;
	return false;
}
