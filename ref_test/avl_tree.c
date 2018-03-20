#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define element int
typedef enum _rot{
	RR,
	RL,
	LR,
	LL
}rot;

typedef struct __avl{
	element data;
	int lev;
	struct __avl *left;
	struct __avl *right;
}avl;

typedef struct __stack{
	avl* data;
	struct __stack* p_node;
}stack;


avl* get_node(void);
stack* get_stack_node(void);
void push(stack** top, avl* data);
void* pop(stack** top);
void ins_avl(avl** root,element data);
void print_avl(avl** root);
int update_level(avl** root);
int chk_rot(avl** root);
avl* rr_rot(avl** root);
avl* test(avl* parent,avl* child){
	avl* tmp = parent;
	parent = child;
	child->right = tmp;
	return child;
}

int main(void){
	avl* root = NULL;
	ins_avl(&root,50);
	ins_avl(&root,60);
	ins_avl(&root,70);
	ins_avl(&root,80);
	print_avl(&root);
	return 0;
}

avl* get_node(void){
	avl* tmp;
	tmp = (avl*)malloc(sizeof(avl)*1);
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->lev = 1;
	return tmp;
}

stack* get_stack_node(void){
	stack* tmp;
	tmp = (stack*)malloc(sizeof(stack)*1);
	tmp->data = NULL;
	tmp->p_node = NULL;

	return tmp;
}
void push(stack** top, avl* data){
	stack* tmp = get_stack_node();
	tmp->data = data;
	if(*top){
		tmp->p_node = *top;
		*top = tmp;
	}
	else
		*top = tmp;
}
void* pop(stack** top){
	stack* tmp = *top;
	avl* data;
	if(*top){
		data = tmp->data;
		*top = tmp->p_node;
		free(tmp);
		return data;
	}
	printf("There's no stack!\n");
	return NULL;
	
}
void ins_avl(avl** root,element data){
	avl** tmp = root;
	avl* tmp2;
	stack* top = NULL;
	int chk;
	while(*tmp){
		if(data < (*tmp)->data){
			push(&top,*tmp);
			tmp = &(*tmp)->left;
		}
		else if(data > (*tmp)->data){
			push(&top,*tmp);
			tmp = &(*tmp)->right;	
		}
	}
	(*tmp) = get_node();
	(*tmp)->data = data;
	printf("%d's stack :\n",data);
	while(top){

		
		avl **t = (avl **)pop(&top);
		if(*t)
			printf("%d\n",(*t)->data);
		//(*t)->lev = update_level(t);
		/*
		printf("%d\n",(*t)->data);
		
		chk = chk_rot(t);
		if(abs(chk) > 1){
			printf("%d(%d)Rotate!!\n",(*t)->data,(*t)->lev);
		//	rr_rot(tmp);
		}*/
	
	} 
}

void print_avl(avl** root){
	if(*root){
		printf("data : %d, lev = %d, ",(*root)->data,(*root)->lev);
		if((*root)->left)
			printf("left = %d, ",(*root)->left->data);
		else
			printf("left = NULL, ");

		if((*root)->right)
			printf("right = %d\n",(*root)->right->data);
		else
			printf("right = NULL\n");

		print_avl(&(*root)->left);
		print_avl(&(*root)->right);
	}
}

int update_level(avl** root){
	int left = (*root)->left ? (*root)->left->lev : 0 ;
	int right = (*root)->right ? (*root)->right->lev : 0 ;
	
	if(left > right)
		return left + 1;
	return right + 1;
}

int chk_rot(avl** root){
	int left = (*root)->left ? (*root)->left->lev : 0 ;
	int right = (*root)->right ? (*root)->right->lev : 0 ;
	return left - right;
}

avl* rr_rot(avl** root){

	if(70 == (*root)->data)
		root = &(*root)->right;

	//free(tmp2);

/*
	(*root)->lev = update_level(root);
	*root = (*root)->right;
	tmp->right = (*root)->left;
	(*root)->left = tmp;
	(*root)->left->lev = update_level(&((*root)->left));
	(*root)->right->lev = update_level(&((*root)->right));
	(*root)->lev = update_level(root);
*/
	return *root;
}
