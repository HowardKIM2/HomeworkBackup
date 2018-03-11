#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define element int

typedef struct __avl{
	element data;
	int lev;
	struct __avl *left;
	struct __avl *right;
}avl;

typedef struct __stack{
	avl* root;
	struct __stack *p_node;
}stack;

avl* get_node(void);
avl* avl_ins(avl** root,element data);
void print_tree(avl** root);
int update_level(avl** root);
void push(stack** top,avl* root);
stack* get_stack_node(void);
avl* pop(stack** top);
int chk_rotate(avl** root);

int main(void){
	avl* root = NULL;

	root = avl_ins(&root,50);
	root = avl_ins(&root,45);
	root = avl_ins(&root,48);

	print_tree(&root);

	return 0;
}

avl* get_node(void){
	avl* tmp;
	tmp = (avl*)malloc(sizeof(avl)*1);
	tmp->right = NULL;
	tmp->left = NULL;
	tmp->lev = 1;

	return tmp;
}

avl* avl_ins(avl** root,element data){
	avl* b_root = *root;
	avl* prev;
	avl* tmp = NULL;
	stack* top = NULL;
	if(!(*root)){
		*root = get_node();
		(*root)->data = data;
		return *root;
	}
	else{
		while(1){
			if(!(*root)){
				*root = get_node();
				(*root)->data = data;
				if(prev->data > data)
					prev->left = *root;
				else
					prev->right = *root;
				break;
			}
			else if(data < (*root)->data){
				prev = *root;
				push(&top,(*root));
				(*root) = (*root)->left;
			}
			else if(data > (*root)->data){
				prev = *root;
				push(&top,(*root));
				(*root) = (*root)->right;
			}
		
		}
	}
	while(1){
		tmp = pop(&top);
		if(!tmp)
			break;

		tmp->lev = update_level(&tmp);
		if(abs(chk_rotate(&tmp)) > 1){
			printf("%d rotate!!\n",tmp->data);

			//rotate and rotated data level update:
		}
	}
	return b_root;
}

void print_tree(avl** root){
	if(*root){
		
		printf("data : %d, level : %d, ",(*root)->data,(*root)->lev);
		printf("left : ");
		if((*root)->left)
			printf("%d, ",(*root)->left->data);
		else
			printf("NULL, ");
		if((*root)->right)
			printf("right : %d\n",(*root)->right->data);
		else
			printf("right : NULL\n");
		print_tree(&((*root)->left));
		print_tree(&((*root)->right));
	}
	
}

int update_level(avl** root){
	int left = (*root)->left ? (*root)->left->lev  : 0;
	int right = (*root)->right ? (*root)->right->lev  : 0;

	if(right > left)
		return right + 1;
	return left + 1;
}

void push(stack** top,avl* root){
	stack* tmp = *top;
	if(!(*top)){
		(*top) = get_stack_node();
		(*top)->root = root;
	}
	else{
		(*top) = get_stack_node();
		(*top)->root = root;
		(*top)->p_node = tmp;
	}
}

stack* get_stack_node(void){
	stack* tmp;
	tmp = (stack*)malloc(sizeof(stack)*1);
	tmp->p_node = NULL;
	return tmp;
}
avl* pop(stack** top){
	if(*top){
		avl* data = (*top)->root;
		(*top) = (*top)->p_node;
		return data;
	}
	return NULL;
}
int chk_rotate(avl** root){
	int right = (*root)->right ? (*root)->right->lev : 0;
	int left = (*root)->left ? (*root)->left->lev : 0;
	
	return right - left;
}
