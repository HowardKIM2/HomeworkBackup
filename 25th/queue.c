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
	if(idx != 4096){
		(*head)->data[idx] = data;
		(*head)->idx = (*head)->idx + 1;
	}

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
	for(i=0;i<tmp->idx;i++){
		printf("data : %d\n",tmp->data[i]);
	}
}

void del_queue(queue** head,int data){
	int del_idx = -1;
	int i;
	int* del_p;
	queue* tmp = *head;
	//find del_data's idx
	for(i=0;tmp->idx;i++){
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

#if 0
	//defficient methode.
	for(i=del_idx;i<tmp->idx-1;i++)
		tmp->data[i] = tmp->data[i+1];
	(*head)->idx = (*head)->idx - 1;
#endif

#if 0
	//very defficient methode.
	memmove(&tmp->data[del_idx], &tmp->data[del_idx+1], tmp->idx - del_idx);
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

	del_queue(&head,data[2]);
	del_queue(&head,data[3]);
	del_queue(&head,data[4]);

	printf("\ndata in queue : after delete %d, %d, %d\n",
			data[2],data[3],data[4]);

	print_queue(&head);
	printf("\n%d\n",head->del_arr[0]);
	printf("\n%d\n",head->del_arr[1]);
	printf("\n%d\n",head->del_arr[2]);
}
