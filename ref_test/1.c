#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
	struct __avl *right;
	struct __avl *left;
}avl;
typedef struct __stack{
	void* data;
	struct __stack* link;
}stack;

avl* get_avl_node(void);
void avl_ins(avl** root,element data);
void print_avl(avl** root);
int update_level(avl* root);
stack* get_stack_node(void);
bool Is_not_empty(stack** top);
void push(stack** top,void* data);
void* pop(stack** top);
int rot_chk(avl* root);
int kinds_of_rot(avl* root);
avl* rotation(avl* root,int kinds);
avl* rot_rr(avl* root);
avl* rot_rl(avl* root);
avl* rot_lr(avl* root);
avl* rot_ll(avl* root);

int main(void){
	avl* root = NULL;
	avl_ins(&root,50);
	printf("address : %x\n",root);
	avl_ins(&root,60);
	printf("address : %x\n",root);
	avl_ins(&root,70);
	printf("address : %x\n",root);
	print_avl(&root);
	printf("\ndebug : %d\n",root->data);
	return 0;
}

avl* get_avl_node(void){
	avl* tmp;
	tmp = (avl*)malloc(sizeof(avl)*1);
	tmp->right = NULL;
	tmp->left = NULL;
	tmp->lev = 1;
	return tmp;
}

void avl_ins(avl** root,element data){
	avl** tmp = root;
	avl** t;
	stack* top = NULL;
	int chk;
	while(*tmp){
		printf("%d push!!\n",(*tmp)->data);
		push(&top,tmp);
		if(data < (*tmp)->data)
			tmp = &(*tmp)->left;
		else if(data > (*tmp)->data)
			tmp = &(*tmp)->right;
	}
	*tmp = get_avl_node();
	(*tmp)->data = data;
	while(Is_not_empty(&top)){
		t = (avl**)pop(&top);
		(*t)->lev = update_level(*t);
		
		chk = rot_chk(*t);
		if(abs(chk) > 1){
			(*t) = rotation((*t),kinds_of_rot(*t));
			printf("rotate!!\n");
		printf("address : %x(in while)\n",*root);
		}
	}
}

void print_avl(avl** root){
	if(*root){
		printf("data : %d, level : %d, ",(*root)->data,(*root)->lev);

		if((*root)->left)
			printf("left : %d, ",(*root)->left->data);
		else
			printf("left : NULL, ");
		if((*root)->right)
			printf("right : %d\n",(*root)->right->data);
		else
			printf("right : NULL\n");
		
		print_avl(&(*root)->left);
		print_avl(&(*root)->right);
	}
}

int update_level(avl* root){
	int right = root->right ? root->right->lev : 0;
	int left = root->left ? root->left->lev : 0;
	if(right > left)
		return right + 1;
	return left + 1;
}


stack* get_stack_node(void){
	stack* tmp;
	tmp = (stack*)malloc(sizeof(stack)*1);
	tmp->link = NULL;
}

bool Is_not_empty(stack** top){
	if(*top)
		return true;
	return false;
}

void push(stack** top,void* data){
	if(data == NULL)
		return;
	stack *tmp = *top;
	*top = get_stack_node();
	(*top)->data = data;
	(*top)->link = tmp;

}

void* pop(stack** top){
	stack* tmp = *top;
	void* data = NULL;
	if(!Is_not_empty(&tmp)){
		printf("Stack is empty!!\n");
		return NULL;
	}
	data = tmp->data;
	(*top) = (*top)->link;
	free(tmp);
	return data;
	
}

int rot_chk(avl* root){
	int right = root->right ? root->right->lev : 0;
	int left = root->left ? root->left->lev : 0;
	return left - right;
}

int kinds_of_rot(avl* root){
	if(rot_chk(root) > 1){
		if(rot_chk(root->left) > 0)
			return LL;
		return LR;
	}
	if(rot_chk(root) < -1){
		if(rot_chk(root->right) < 0)
			return RR;
		return RL;
	}
}

avl* rotation(avl* root,int kinds){
	avl* tmp;
	switch(kinds){
		case RR:
			printf("RR rotate!\n");
			tmp = rot_rr(root);
			break;
		case LL:
			printf("LL rotate!\n");
			tmp = rot_ll(root);
			break;
		case LR:
			printf("LR rotate!\n");
			break;
		case RL:
			printf("RL rotate!\n");
			tmp = rot_rl(root);
	}
	
	return tmp;
}

avl* rot_rr(avl* root){
	avl* tmp = root;
	root = root->right;
	tmp->right = root->left;
	root->left = tmp;

	root->left->lev = update_level(root->left);
	root->right->lev = update_level(root->right);
	root->lev = update_level(root);
	return root;
}

avl* rot_rl(avl* root){
	avl* tmp = root->right;
	root->right = root->right->left;
	root->right->right = tmp;
	tmp->left = NULL;

	root->left->right->lev = update_level(root->right->right);
	root->right->lev = update_level(root->right);
	root->lev = update_level(root);

	return rot_rr(root);
}

avl* rot_lr(avl* root){

}

avl* rot_ll(avl* root){

	avl* tmp = root;
	root = root->left;
	tmp->left = root->right;
	root->right = tmp;
	
	root->left->lev = update_level(root->left);
	root->right->lev = update_level(root->right);
	root->lev = update_level(root);
	return root;
}
