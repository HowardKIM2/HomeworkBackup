#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
typedef struct __queue{
	int idx;
	int d_idx;
	int del_arr[0];
	int data[0];
}queue;

void ins_queue(queue** head,int data){
	int idx = (*head)->idx;
	(*head)->data[idx++] = data;
	(*head)->idx = idx;
}

queue* init_queue(void){
	queue* tmp = (queue*)malloc(4096);
	tmp->idx = 0;
	tmp->d_idx = 0;
	return tmp;
}

void print_queue(queue** head){
	queue* tmp = *head;
	int i;
	int j = 0;
	
	for(i=0;i<tmp->idx;i++){
		if((i == tmp->del_arr[j])&&(j < tmp->d_idx)){
			j++;
			continue;
		}
		printf("data[%d] : %d\n",i,(*head)->data[i]);
	}
}

void del_queue(queue** head,int data){
	int del_idx = -1;
	int i;
	queue* tmp = *head;
	//find del_data's idx
	for(i=0;i<tmp->idx;i++){
		if(tmp->data[i] == data){
			del_idx = i;
			break;
		}
	}
#if 1
	//exception : no data
	if(del_idx == -1){
		printf("no data in queue\n");
		return;
	}
	
#endif
	tmp->del_arr[tmp->d_idx] = del_idx;
	tmp->d_idx = tmp->d_idx+1;
}

bool is_not_dup(int* arr,int data){
	int i = 0;
	while(arr[i])
		if(data == arr[i++])
			return false;
	return true;
}

void init_rand_data(int* data,int size){
	int i;
	int tmp;
	for(i=0;i<size;){
		tmp = rand()%20 + 1;
		if(is_not_dup(data,tmp))
			data[i++] = tmp;
	}
		
}

void print_rand_data(int* data){
	int i = 0;
	while(data[i])
		printf("data : %d\n",data[i++]);
}

void ins_data_to_queue(queue** head,int* data){
	int i = 0;
	while(data[i])
		ins_queue(head,data[i++]);
}

int main(void){
	srand(time(NULL));
	int data[17] = {0,};
	int size = sizeof(data)/sizeof(int) - 1;
	
	init_rand_data(data,size);
	print_rand_data(data);
	queue *head = init_queue();
	
	ins_data_to_queue(&head,data);
	printf("\ndata in queue : \n");
	print_queue(&head);
#if 1
	del_queue(&head,data[2]);
	del_queue(&head,data[3]);
	del_queue(&head,data[4]);

	//printf("\ndata in queue : after delete %d, %d, %d\n",
	//		data[2],data[3],data[4]);
	printf("\n");

	print_queue(&head);
	printf("\n%d\n",head->del_arr[0]);
	printf("\n%d\n",head->del_arr[1]);
	printf("\n%d\n",head->del_arr[2]);
#endif
}
