#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
bool chk_dup(int* a, int i, int num); 
typedef struct __queue{
	int data;
	struct __queue *link;
}queue;
queue* get_node(void);
void ins_queue(queue** head,int data);
void print_queue(queue** head);
int de_queue(queue** head);
int main(void){
	srand(time(NULL));
	int a[16];
	int i;
	queue* head = NULL;
	while(i<16){
		a[i] = rand()%16;
		if(chk_dup(a,i,a[i]))
			continue;
		ins_queue(&head,a[i]);
		i++;
	}
	print_queue(&head);
	return 0;
}
bool chk_dup(int* a, int i, int num){
	int j;
	bool chk = false;
	for(j=0;j<i;j++){
		if(a[j]	== num){
			chk = true;
			break;
		}
	}
	return chk;
}
queue* get_node(void){
	queue* tmp;
	tmp = (queue*)malloc(sizeof(queue)*1);
	tmp->link = NULL;
	return tmp;
}
void ins_queue(queue** head,int data){
	queue** tmp = head;
	while(*tmp)
		tmp = &(*tmp)->link;
	*tmp = get_node();
	(*tmp)->data = data;
}
void print_queue(queue** head){
	queue* tmp = *head;
	while(tmp){
		printf("%d\n",tmp->data);
		tmp = tmp->link;
	}
}
int de_queue(queue** head){
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










