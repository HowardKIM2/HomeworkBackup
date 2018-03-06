#include <stdio.h>
#include <malloc.h>
typedef struct stack{
	int data;
	struct stack *p_node;
}Stack;

Stack* get_node();
void push(Stack** top,int data);
int pop(Stack** top);

int main(void){
	Stack *top = NULL;

	push(&top,1);
	push(&top,2);

	printf("data = %d\n",pop(&top));

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
	tmp = *top;
	*top = get_node();
	(*top)->data = data;
	(*top)->p_node = tmp;
}
int pop(Stack** top){
	Stack* tmp;
	int num;
	tmp = *top;
	if(tmp==NULL){
		printf("Stack is EMPTY!\n");
		return 0;
	}
	num = tmp->data;
	*top = tmp->p_node;
	free(tmp);
	return num;
}
