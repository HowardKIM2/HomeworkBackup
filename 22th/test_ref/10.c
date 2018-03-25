#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
typedef struct __stack{
	int data;
	struct __stack* link;
}stack;
stack* get_stack_node(void);
void push(stack** top,int data);
void print_stack(stack** top);
void init_rand_arr(int* data, int size);
bool is_not_dup(int* data,int tmp);
void ins_data_to_stack(stack** top,int* data);
int main(void){
	stack* top = NULL;
	int data[21]={0,};
	int size = sizeof(data)/sizeof(int) - 1;
	init_rand_arr(data,size);
	ins_data_to_stack(&top,data);
	print_stack(&top);
	return 0;
}
stack* get_stack_node(void){
	stack* tmp;
	tmp = (stack*)malloc(sizeof(stack)*1);
	tmp->link = NULL;
	return tmp;
}
void push(stack** top,int data){
	stack* tmp = *top;
	(*top) = get_stack_node();
	(*top)->data = data;
	(*top)->link = tmp;
}
void print_stack(stack** top){
	stack* tmp = *top;
	while(tmp){
		printf("data : %d\n",tmp->data);
		tmp = tmp->link;
	}
}
void init_rand_arr(int* data, int size){
	int i, tmp;
	srand(time(NULL));
	for(i=0;i<size;){	
		tmp = rand()%100+1;
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
void ins_data_to_stack(stack** top,int* data){
	int i = 0;
	while(data[i])
		push(top,data[i++]);
	
}
