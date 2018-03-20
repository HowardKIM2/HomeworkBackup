#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define element int
typedef struct __stack{
	element data;
	struct __stack* p_node;
}stack;

stack* get_node(void);
void push(stack** top,element data);
int pop(stack** top);
void disp_stack(stack **top);
void input_stack(stack** top);
bool chk_dup(int* a,int i,int num);
int main(void){
	stack* top = NULL;
	input_stack(&top);
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
void input_stack(stack** top){
	
	srand(time(NULL));
	int a[20];
	int i = 0;
	while(i<20){
		a[i]=rand()%100+1;
		if(chk_dup(a,i,a[i]))
			continue;
		push(top,a[i]);
		i++;
	}
}
bool chk_dup(int* a,int i,int num){
	int j;
	bool chk = false;
	for(j=0;j<i;j++){
		if(a[j] == num){
			chk = true;
			break;
		}
	}
	return chk;
}

















