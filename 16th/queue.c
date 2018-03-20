#include <stdio.h>
#include <stdlib.h>
#define element int
typedef struct __queue{
	element data;
	struct __queue *link;
}queue;

queue* get_node(void);
void ins_queue(queue** head,element data);
element de_queue(queue** head);
void print_queue(queue** head);
int main(void){
	queue* head = NULL;
	ins_queue(&head,10);
	ins_queue(&head,20);
	ins_queue(&head,30);
	ins_queue(&head,40);
	ins_queue(&head,50);
	print_queue(&head);
}

queue* get_node(void){
	queue* tmp;
	tmp = (queue*)malloc(sizeof(queue)*1);
	tmp->link = NULL;
	return tmp;
}
void ins_queue(queue** head,element data){
	queue** tmp = head;
	while(*tmp)
		tmp = &(*tmp)->link;
	
	*tmp = get_node();
	(*tmp)->data = data;
}
element de_queue(queue** head){
	queue* tmp = *head;
	int data;
	if(!(*head)){
		printf("Error : There's no data in queue\n");
		return 0;
	}
	data = (*head)->data;
	*head = (*head)->link;
	free(tmp);
	return data;

}
void print_queue(queue** head){
	queue* tmp = *head;	while(tmp){
		printf("%d\n",tmp->data);
		tmp = tmp->link;
	}
}
