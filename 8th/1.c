#include <stdio.h>
#include <stdlib.h>

#define EMPTY 0
typedef struct stack{
	int data;
	struct stack *link;

}Stack;

Stack* get_node();
void push(Stack** top,int data);
int pop(Stack** top);

int main(void){
	Stack* top = EMPTY;

	

	push(&top,10);
	push(&top,20);
	push(&top,30);
	
	printf("%d\n",pop(&top));
	printf("%d\n",pop(&top));
	printf("%d\n",pop(&top));
	printf("%d\n",pop(&top));

}


Stack* get_node(){
	Stack* tmp;
	tmp = (Stack*)malloc(sizeof(Stack)*1);
	tmp->link = EMPTY;

	return tmp;
}

void push(Stack** top,int data){
	Stack* tmp;
	tmp = *top;
	(*top) = get_node();
	(*top)->data = data;
	(*top)->link = tmp;
}

int pop(Stack** top){
	Stack* tmp;
	int num;
	tmp = *top;
	if(*top == EMPTY){
		printf("There is no Stack!!!\n");
		return 0;
	}
	num = tmp->data;
	*top = tmp->link;
	free(tmp);
	return num;
}
