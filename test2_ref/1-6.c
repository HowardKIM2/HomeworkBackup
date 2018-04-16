#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef struct __stack{
	int data[0];
	int top;
}stack;
stack* init_stack(void);
void push(stack** top,int data);
int pop(stack** top);
void print_stack(stack** top);
int main(void){
	stack* top = NULL;
	top = init_stack();
	
	push(&top, 10);
	push(&top, 20);
	push(&top, 30);
	push(&top, 40);

	print_stack(&top);

	printf("%d pop!!\n",pop(&top));
	
	print_stack(&top);
}
stack* init_stack(void){
	stack* tmp = (stack*)malloc(4096);
	tmp->top = 1;
	return tmp;
}
void push(stack** top,int data){
	int ntop = (*top)->top;
	(*top)->data[ntop] = data;
	(*top)->top = ++ntop;
}	
void print_stack(stack** top){
	int i;
	for(i = (*top)->top-1 ;i>=1 ;i--)
		printf("data : %d\n",(*top)->data[i]);
}
int pop(stack** top){
	int data;
	data = (*top)->data[(*top)->top - 1];
	(*top)->top = (*top)->top - 1;
	return data;
}
