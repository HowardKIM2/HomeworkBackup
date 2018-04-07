#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define element int
typedef struct __tree{
	element data;
	struct __tree* left;
	struct __tree* right;
}tree;
typedef struct __stack{
	void* data;
	struct __stack* link;
}stack;

//functions for tree 
tree* get_tree_node(void);
void ins_tree(tree** root, element data);
void del_tree(tree** root, element data);
void find_max(tree** root,int* max);
void chg_node(tree** root);
void print_tree(tree** root);
//functions for stack, whick used for "print_tree" without recursive f
stack* get_stack_node(void);
void push(stack** top,void* data);
void* pop(stack** top);
bool is_not_empty(stack** top);

int main(void){
	tree* root = NULL;
	ins_tree(&root, 30);
	ins_tree(&root, 20);
	ins_tree(&root, 25);
	ins_tree(&root, 40);
	ins_tree(&root, 5);
	ins_tree(&root, 5);
	
	print_tree(&root);
	printf("\nafter del 25\n");
	del_tree(&root,25);
	print_tree(&root);
}
tree* get_tree_node(void){
	tree* tmp;
	tmp = (tree*)malloc(sizeof(tree)*1);
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}
void ins_tree(tree** root, element data){
	tree** tmp = root;
	while(*tmp){
		if(data < (*tmp)->data)
			tmp = &(*tmp)->left;
		else if(data > (*tmp)->data)
			tmp = &(*tmp)->right;
		//duplicated data
		else{
			if(!(*tmp)->left)
				tmp = &(*tmp)->left;
			else if(!(*tmp)->right)
				tmp = &(*tmp)->right;
			else
				tmp = &(*tmp)->left;
		}
	}
	*tmp = get_tree_node();
	(*tmp)->data = data;
}
void del_tree(tree** root, element data){
	int max;
	while(*root){
		if(data < (*root)->data){
			if((*root)->left)
				root = &(*root)->left;
			else{
				printf("There's no %d in tree\n",data);
				return;
			}
		}
		else if(data > (*root)->data){
			if((*root)->right)
				root = &(*root)->right;
			else{
				printf("There's no %d in tree\n",data);
				return;
			}
		}
		else
			break;
	}
	if((*root)->left){
		find_max(&(*root)->left,&max);
		(*root)->data = max;
	}
	else
		chg_node(root);
	
		
}

void find_max(tree** root, int* max){
	while((*root)->right)
		root = &(*root)->right;
	*max = (*root)->data;
	chg_node(root);

}

void chg_node(tree** root){
	tree* tmp = *root;
	if((*root)->left)
		*root = (*root)->left;
	else
		*root = (*root)->right;
	free(tmp);
}
stack* get_stack_node(void){
	stack* tmp;
	tmp = (stack*)malloc(sizeof(stack)*1);
	tmp->link = NULL;
	return tmp;
}
void push(stack** top,void* data){
	stack* tmp = *top;
	*top = get_stack_node();
	(*top)->data = data;
	(*top)->link = tmp;
}
void* pop(stack** top){
	stack* tmp = *top;
	void* data = tmp->data;
	*top = (*top)->link;
	free(tmp);

	return data;
}

void print_tree(tree** root){
	stack* top = NULL;
	tree* tmp = *root;
	while(tmp){
		printf("data : %d\n",tmp->data);
		
		if(tmp->right)
			push(&top, (void*)tmp->right);

		
		if(tmp->left)
			tmp = tmp->left;
		else if(is_not_empty(&top))
			tmp = (tree*)pop(&top);
		else
			tmp = tmp->left;
	}
}	

bool is_not_empty(stack** top){
	if(*top)
		return true;
	return false;
}
