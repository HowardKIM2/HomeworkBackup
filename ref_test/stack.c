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
	element data;
	while(1){
		printf("Instruction quit(q), insert(i), pop(d), disp(d) :");
		scanf("%c%*c",&ch);
		system("clear");
		switch(ch){
			case 'q':
				printf("quit!\n");
				break;
			case 'i':
				printf("data : ");
				scanf("%d%*c",&data);
				push(&top,data);
				printf("data %d inserted!\n",data);
				break;
			case 'd':
				printf("data %d deleted!\n",pop(&top));
				break;
			case 'p':
				printf("current stack :\n");
				disp_stack(&top);
				break;
		}
		
		if(ch=='q')
			break;
	}


	return 0;
}

stack* get_node(void){
	stack* tmp;
	tmp = (stack*)malloc(sizeof(stack)*1);
	tmp->p_node = NULL;
	return tmp;
}

void push(stack** top,element data){
	stack* tmp;
	if(!(*top)){
		*top = get_node();
		(*top)->data = data;
	}
	else{
		tmp = *top;
		(*top) = get_node();
		(*top)->data = data;
		(*top)->p_node = tmp;
	}
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
