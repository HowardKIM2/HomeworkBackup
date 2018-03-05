#include <stdio.h>
#include <stdlib.h>

typedef struct __queue{
	int data;
	struct __queue *link;
}Queue;


Queue* enqueue(Queue **head, int data);
Queue* get_node(void);
Queue* deque(Queue **head, int data);
void printfqueue(Queue **head);

int main(void){
	Queue* head = NULL;
	enqueue(&head,10);
	enqueue(&head,20);
	enqueue(&head,30);
	enqueue(&head,40);

	deque(&head,10);
	
	printfqueue(&head);

	return 0;
}

Queue* enqueue(Queue **head, int data){

	if(*head == NULL){
		*head = get_node();
		(*head)->data = data;
		return 0;
	}
	enqueue(&((*head)->link),data);
}

Queue* get_node(){
	Queue* tmp;
	tmp = (Queue*)malloc(sizeof(Queue)*1);
	tmp->link = NULL;

	return tmp;
}

Queue* deque(Queue **head, int data){
	
	Queue* tmp;
	tmp = *head;

	if((*head)->data == data){
		*head = tmp->link;
		free(tmp);
		return 0;
	}
	deque(&((*head)->link),data);

}

void printfqueue(Queue **head){
	if(*head !=NULL){
		printf("%d\n",(*head)->data);
		printfqueue(&((*head)->link));
	}
		
}
