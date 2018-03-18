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
void print_stack(stack** top);
void database(void);
int main(void){
	database();
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
void print_stack(stack** top){
	stack* tmp = *top;
	bool start = true;
	while(tmp){
		if(start){
			printf("data : %d  <-top data\n",tmp->data);
			start = false;
		}
		else
			printf("data : %d\n",tmp->data);
		tmp = tmp->p_node;
	}
}
void database(void){
	stack* top = NULL;
	char ins;
	bool q = false;
	int data;
	while(true){
		printf("Input instruction (q:Quit, i:Insert, d:Delete, p:disP) : ");
		scanf("%c%*c",&ins);
		system("clear");
		switch(ins){
			case 'q':
				q = true;
				break;
			case 'i':
				printf("input data(num) : ");
				scanf("%d%*c",&data);
				push(&top,data);
				printf("%d inserted!\n",data);
				break;
			case 'd':
				data = pop(&top);
				printf("%d deleted!\n",data);
				break;
			case 'p':
				printf("current stack : \n");
				print_stack(&top);
				break;
			default :
				break;
		}
		if(q)
			break;
	}
	printf("quit!\n");
}
