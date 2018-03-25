#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
typedef struct __queue{
	int data;
	struct __queue* link;
}queue;
queue* get_queue_node(void);
void ins_queue(queue** head,int data);
void print_queue(queue** head);
void init_rand_arr(int* data,int size);
bool is_not_dup(int* data,int tmp);
void ins_data_to_queue(queue** head,int* data);
int main(void){
	queue* head = NULL;
	int data[17]={0,};
	int size = sizeof(data)/sizeof(int)-1;
	init_rand_arr(data,size);
	ins_data_to_queue(&head,data);
	print_queue(&head);
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
void print_queue(queue** head){
	queue* tmp = *head;
	while(tmp){
		printf("data : %d\n",tmp->data);
		tmp = tmp->link;
	}
}
void init_rand_arr(int* data,int size){
	srand(time(NULL));
	int i, tmp;
	for(i=0;i<size;){
		tmp = rand()%16 + 1;
		if(is_not_dup(data,tmp))
			data[i++] = tmp;
	}
}
bool is_not_dup(int* data,int tmp){
	int i = 0;
	while(data[i]){
		if(data[i++] == tmp)
			return false;
	}
	return true;
}
void ins_data_to_queue(queue** head,int* data){
	int i = 0;
	while(data[i])
		ins_queue(head,data[i++]);
	
}
