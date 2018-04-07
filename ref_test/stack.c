#include <stdio.h>
#include <stdlib.h>
#define element int
typedef struct __stack{
	element data;
	struct __stack* p_node;
}stack;

stack* get_node(void);
void push(stack** top,element data);
int pop(stack** top);
void disp_stack(stack **top);
int main(void){
	stack* top = NULL;
	char ch;
	
	push(&top, 10);
	push(&top, 20);
	push(&top, 30);
	disp_stack(&top);

	pop(&top);
	disp_stack(&top);
	
	return 0;
}

stack* get_node(void){
	stack* tmp;
	tmp = (stack*)malloc(sizeof(stack)*1);
	tmp->p_node = NULL;
	return tmp;
}

void push(stack** top,element data){
	stack* tmp = *top;
	*top = get_node();
	(*top)->data = data;
	(*top)->p_node = tmp;
}
int pop(stack** top){
	element data;
	if(!(*top)){
		printf("there's no stack!!\n");
		return 0;
	}
	data = (*top)->data;
	*top = (*top)->p_node;
	return data;
}
void disp_stack(stack **top){
	stack* tmp = *top;
	while(tmp){
		printf("%d\n",tmp->data);
		tmp = tmp->p_node;
	}
}
