#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct __stack{
	int data;
	struct __stack *p_node;
}stack;
void push(stack** top,int data);
stack* get_stack_node(void);
int pop(stack **top);
bool is_not_empty(stack** top);
int main(void){
	stack* top = NULL;
	push(&top,10);
	push(&top,20);
	printf("%d\n",pop(&top));
	printf("%d\n",pop(&top));
	printf("%d\n",pop(&top));

}
void push(stack** top,int data){
	stack* tmp = *top;
	*top = get_stack_node();
	(*top)->data = data;
	(*top)->p_node = tmp;

}
stack* get_stack_node(void){
	stack* tmp;
	tmp = (stack*)malloc(sizeof(stack)*1);
	tmp->p_node = NULL;
	return tmp;
}
int pop(stack **top){
	stack* tmp = *top;
	int data;
	if(!is_not_empty(top)){
		printf("Error : no data in stack\n");
		return 0;
	}
	data = (*top)->data;
	*top = (*top)->p_node;
	free(tmp);
	return data;
}
bool is_not_empty(stack** top){
	if(*top)
		return true;
	return false;
}
