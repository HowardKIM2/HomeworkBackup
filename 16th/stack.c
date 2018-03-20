#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define element int
typedef struct __stack{
	element data;
	struct __stack *link;
}stack;

stack* get_node(void);
bool Is_no_empty(stack** top);
void push(stack** top, element data);
element pop(stack** top);
void print_stack(stack** top);

int main(void){
	stack* top = NULL;
	push(&top, 10);
	push(&top, 20);
	push(&top, 30);

	print_stack(&top);
	return 0;
}

stack* get_node(void){
	stack* tmp;
	tmp = (stack*)malloc(sizeof(stack)*1);
	tmp->link = NULL;
	return tmp;
}

bool Is_no_empty(stack** top){
	if(*top)
		return true;
	return false;
}

void push(stack** top, element data){
	stack* tmp = *top;	
	*top = get_node();
	(*top)->data = data;
	(*top)->link = tmp;
		
}

element pop(stack** top){
	stack* tmp = *top;
	if(!(*top)){
		printf("Error : Stack is empty\n");
		return 0;
	}
	element res = tmp->data;
	(*top) = (*top)->link;
	free(tmp);
	return res;
}

void print_stack(stack** top){
	stack* tmp = *top;
	while(tmp){
		printf("%d\n",tmp->data);
		tmp = tmp->link;
	}
}




