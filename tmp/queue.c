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
void print_queue(queue** head);
void database(void);
int main(void){
	database();
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
void print_queue(queue** head){
	queue* tmp = *head;
	bool start = true;
	while(tmp){
		if(start){
			printf("data : %d  <- head data\n",tmp->data);
			start = false;
		}
		else
			printf("data : %d\n",tmp->data);
		tmp = tmp->link;
	}

}
void database(void){
	queue* head = NULL;
	char ins;
	int data;
	bool q = false;

	while(true){
		printf("input instruction (q:Quit, i:Insert, d:Delete, p:disP) :");
		scanf("%c%*c",&ins);
		system("clear");
		switch(ins){
			case 'q':
				q = true;
				break;
			case 'i':
				printf("input data(num) : ");
				scanf("%d%*c",&data);
				ins_queue(&head,data);
				printf("%d inserted\n",data);
				break;
			case 'd':
				data = de_queue(&head);
				printf("%d deleted\n",data);
				break;
			case 'p':
				printf("current queue : \n");
				print_queue(&head);
			default :
				break;
		}
		if(q)
			break;
	}
	printf("quit!\n");

}
