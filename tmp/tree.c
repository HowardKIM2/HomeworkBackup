#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct __tree{
	int data;
	struct __tree* left;
	struct __tree* right;
}tree;
typedef struct __stack{
	tree* data;
	struct __stack *link;
}stack;
tree* get_tree_node(void);
void ins_tree(tree** root,int data);
void del_tree(tree** root,int data);
void findMax(tree** root,int* max);
tree* chg_node(tree* root);
void print_tree(tree** root);
stack* get_stack_node(void);
void push(stack** top,tree* data);
tree* pop(stack** top);
bool is_not_empty(stack** top);
void database(void);
int main(void){
	database();
	return 0;
}
tree* get_tree_node(void){
	tree* tmp;
	tmp = (tree*)malloc(sizeof(tree)*1);
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}
void ins_tree(tree** root,int data){
	tree** tmp = root;
	while(*tmp){
		if(data < (*tmp)->data)
			tmp = &(*tmp)->left;
		else if(data > (*tmp)->data)
			tmp = &(*tmp)->right;
		else{
			//currently, duplicated data is not allowed
		}
	}
	*tmp = get_tree_node();
	(*tmp)->data = data;
}
void del_tree(tree** root,int data){
	tree** tmp = root;
	int max;
	while(tmp){
		if(data < (*tmp)->data)
			tmp = &(*tmp)->left;
		else if(data > (*tmp)->data)
			tmp = &(*tmp)->right;
		else if((*tmp)->left && (*tmp)->right){
			findMax(&(*tmp)->left,&max);
			(*tmp)->data = max;
			return;
		}
		else{
			*tmp = chg_node(*tmp);
			return;
		}
	}
}
void findMax(tree** root,int* max){
	while(*root){
		if(!(*root)->right)
			break;
		*root = (*root)->right;
	}
	*max = (*root)->data;
	*root = chg_node(*root);
}
tree* chg_node(tree* root){
	tree* tmp = root;
	if(!root->right)
		root = root->left;
	else if(!root->left)
		root = root->right;
	free(tmp);
	return root;

}
void print_tree(tree** root){
	tree* tmp = *root;
	stack* top = NULL;
	
	push(&top,tmp);
	while(is_not_empty(&top)){
		tmp = pop(&top);
		if(!tmp)
			break;
		printf("data : %d\n", tmp->data);
		if(tmp->right)
			push(&top,tmp->right);
		else if(tmp->left)
			push(&top,tmp->left);
	}

}
stack* get_stack_node(void){
	stack* tmp;
	tmp = (stack*)malloc(sizeof(stack)*1);
	tmp->link = NULL;
	return tmp;
}
void push(stack** top,tree* data){
	stack* tmp = *top;
	*top = get_stack_node();
	(*top)->data = data;
	(*top)->link = tmp;
}
tree* pop(stack** top){
	stack* tmp = *top;
	tree* data = NULL;
	if(!is_not_empty(top)){
		printf("Error : no data in stack\n");
		return data;
	}
	data = tmp->data;
	(*top) = (*top)->link;
	free(tmp);
	return data;
}
bool is_not_empty(stack** top){
	if(*top)
		return true;
	return false;
}
void database(void){
	tree* root = NULL;
	char ins;
	int data;
	bool q = false;
	while(true){
		printf("input instruction (q:Quit, i:Insert, d:Delete, p:disP) : ");
		scanf("%c%*c",&ins);
		system("clear");
		switch(ins){
			case 'q':
				q = true;
				break;
			case 'i':
				printf("input data (num) : ");
				scanf("%d%*c",&data);
				ins_tree(&root,data);
				printf("%d inserted\n",data);
				break;
			case 'd':
				printf("input deleted data (num) : ");
				scanf("%d%*c",&data);
				del_tree(&root,data);
				printf("%d deleted\n",data);
				break;
			case 'p':
				printf("current tree : \n");
				print_tree(&root);
				break;
			default :
				ins = '\0';
				printf("wrong instructon\n");
				break;
		
		}
		if(q)
			break;
	}
	printf("quit\n");
}
