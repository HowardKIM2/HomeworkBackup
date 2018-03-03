/*
	make stack : 1st try
*/

#include <stdio.h>
#include <malloc.h>


typedef struct stack{

	int data;
	struct stack *p_node;
}Stack;

Stack* get_node();
void push(Stack** top,int data);
int pop(Stack** top);
void disp_stack(Stack** top);
void disp_stack_cnt(Stack** top);


int main(void){

	Stack* top;
	top = get_node();
	
	push(&top,10);
	push(&top,20);
	
	printf("%d\n",pop(&top));
	printf("%d\n",pop(&top));

	push(&top,30);
	push(&top,40);
	
	printf("%d\n",pop(&top));
	printf("%d\n",pop(&top));
	printf("%d\n",pop(&top));
	
	return 0;
}

Stack* get_node(){
	Stack* tmp;
	tmp = (Stack*)malloc(sizeof(Stack*));
	tmp->p_node = NULL;
	tmp->data = 0;
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
	num = tmp->data;
	if(tmp->p_node == NULL){
		printf("there is no stack!!\n");
		return 0;
	}
	(*top) = tmp->p_node;
	

	free(tmp);
	return num;
}

void disp_stack(Stack** top){
	Stack* tmp;
	int i;
	tmp = *top;
	printf("****current Stack*****\n");
	for(i=0;tmp->p_node;i++){
		printf("%d\n",tmp->data);
		tmp = tmp->p_node;
	}
}

void disp_stack_cnt(Stack** top){
	Stack* tmp;
	int i;
	tmp = *top;
	for(i=0;tmp->p_node;i++)
		tmp = tmp->p_node;
	printf("current Stack count : %d\n",i);

}
