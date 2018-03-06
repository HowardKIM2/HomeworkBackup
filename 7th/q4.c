#include <stdio.h>
#include <malloc.h>

typedef struct stack{
	int data;
	struct stack *p_node;
}Stack;

Stack* get_node();
void push(Stack** memory,int data);
int pop(Stack** memory);

int main(void){
	Stack* memory;
	memory = get_node();

	push(&memory,10);
	push(&memory,20);
	push(&memory,30);

	printf("%d\n",pop(&memory));
	printf("%d\n",pop(&memory));
	printf("%d\n",pop(&memory));
	printf("%d\n",pop(&memory));
	printf("%d\n",pop(&memory));

	return 0;
}

Stack* get_node(){
	Stack* new_node;
	new_node = (Stack*)malloc(sizeof(Stack*));
	new_node->data = 0;
	new_node->p_node = NULL;
	return new_node;
}

void push(Stack** memory,int data){
	Stack* tmp;
	
	tmp = *memory;
	*memory = get_node();
	(*memory)->data = data;
	(*memory)->p_node = tmp;
}

int pop(Stack** memory){
	int num;
	Stack* tmp;
	tmp = *memory;
	if(tmp->p_node == NULL){
		printf("Stack is EMPTY!!\n");
		return 0;
	}
	num = tmp->data;
	*memory = tmp->p_node;
	return num;
}

