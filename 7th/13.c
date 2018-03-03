/*
	stack make : 2nd try
*/

#include <stdio.h>
#include <malloc.h>

typedef struct stack{
	int data;
	struct stack *p_node;
}Stack;

void push(Stack** top,int data);
Stack* get_node();
int pop(Stack** top);

int main(void){
	Stack* top;
	top = get_node();

	push(&top,10);
	push(&top,20);
	push(&top,30);

	printf("%d\n",pop(&top));
	printf("%d\n",pop(&top));
	
	push(&top,40);
	push(&top,50);

	printf("%d\n",pop(&top));
	printf("%d\n",pop(&top));
	printf("%d\n",pop(&top));
	printf("%d\n",pop(&top));
	
	return 0;
}

Stack* get_node(){
	Stack* tmp;
	tmp = (Stack*)malloc(sizeof(Stack*));
	tmp->data = 0;
	tmp->p_node = NULL;
	return tmp;
}
void push(Stack** top,int data){
	Stack* tmp;
	tmp = get_node();
	tmp->data = data;
	tmp->p_node = *top;
	*top = tmp;

}
int pop(Stack** top){
	Stack* tmp;
	int num;
	
	if((*top)->p_node == NULL){
		printf("There is no stack\n");
		return 0;
	}

	tmp = *top;
	num = tmp->data;
	*top = tmp->p_node;
	return num;
}
