#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
typedef enum _rot{
	RR,
	RL,
	LR,
	LL
}rot;
typedef struct __avl{
	int data;
	struct __avl* left;
	struct __avl* right;
	int lev;
}avl;
typedef struct __stack{
	void* data;
	struct __stack *link;
}stack;
avl* get_avl_node(void);
void avl_ins(avl** root,int data);
stack* get_stack_node(void);
void push(stack** top,void* data);
bool is_not_empty(stack** top);
void* pop(stack** top);
int update_level(avl** root);
void print_avl(avl** root);
int chk_rot(avl** root);
avl* rotation(avl* root);
int kinds_of_rot(avl** root);
avl* rr_rot(avl* parent,avl* child);
avl* rl_rot(avl* parent,avl* child);
avl* lr_rot(avl* parent,avl* child);
avl* ll_rot(avl* parent,avl* child);
void ins_rand_data(avl** root,int* data);
bool is_dup_data(int* data,int val);
void print_data(int* data);
void del_avl(avl** root,int data);
void findMax(avl** root,int* max,stack** top);
avl* chg_node(avl* root);
void print_stack(stack** top);
int main(void){
	avl* root = NULL;
	int data[13]={0,};
	int i = 0;
 	ins_rand_data(&root,data);
	printf("created data :\n");
	print_data(data);
	printf("after insert data to avl_tree:\n");
	
	print_avl(&root);
	del_avl(&root,data[0]);
	print_avl(&root);
	return 0;
}
avl* get_avl_node(void){
	avl* tmp;
	tmp = (avl*)malloc(sizeof(avl)*1);
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->lev = 1;
	return tmp;
}
void avl_ins(avl** root,int data){
	avl** tmp = root;
	stack* top = NULL;
	int chk;
	while(*tmp){
		if(data < (*tmp)->data){
			push(&top,tmp);
			tmp = &(*tmp)->left;
		}
		else if(data > (*tmp)->data){
			push(&top,tmp);
			tmp = &(*tmp)->right;
		}
	}
	(*tmp) = get_avl_node();
	(*tmp)->data = data;
	while(is_not_empty(&top)){
		avl** p = (avl**)pop(&top);
		(*p)->lev = update_level(p);
		chk = chk_rot(p);
		if(abs(chk) > 1){
			printf("%d rotate!(by insertion)\n",(*p)->data);
			*p = rotation(*p);	
		}
	}
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
	(*top)->link = tmp;
	(*top)->data = data;
}
bool is_not_empty(stack** top){
	if(*top)
		return true;
	return false;
}
void* pop(stack** top){
	void* data = NULL;
	stack* tmp = *top;
	if(!is_not_empty(top)){
		printf("Error : no data in stack\n");
		return data;
	}
	data = (*top)->data;
	(*top) = (*top)->link;
	free(tmp);
	return data;
}
int update_level(avl** root){
	if(!(*root)){
		printf("Error : no data in avl tree\n");
		return 0;
	}
	
	int left = (*root)->left ? (*root)->left->lev : 0 ;
	int right = (*root)->right ? (*root)->right->lev : 0 ;
	if(left > right)
		return left + 1;
	return right + 1;
}
void print_avl(avl** root){
	avl* tmp = *root;
	stack* top = NULL;
	if(!(*root))
		return;
	push(&top,tmp);
	while(is_not_empty(&top)){
		tmp = (avl*)pop(&top);
		printf("data : %d, lev : %d, ",tmp->data,tmp->lev);
		if(tmp->left)
			printf("left : %d, ",tmp->left->data);
		else
			printf("left : NULL, ");
		if(tmp->right)
			printf("right : %d\n",tmp->right->data);
		else 
			printf("right : NULL\n");
		if(tmp->right)
			push(&top,tmp->right);
		if(tmp->left)
			push(&top,tmp->left);
	}
}
int chk_rot(avl** root){
	int left = (*root)->left ? (*root)->left->lev : 0;
	int right = (*root)->right ? (*root)->right->lev : 0;
	return left - right;
}
avl* rotation(avl* root){
	int key = kinds_of_rot(&root);
	avl* tmp = root;
	switch(key){
		case RR:
			printf("RR rotation!\n");
			tmp = rr_rot(root,root->right);
			break;
		case RL:
			printf("RL rotation!\n");
			tmp = rl_rot(root,root->right);
			break;
		case LR:
			tmp = lr_rot(root,root->left);
			printf("LR rotation!\n");
			break;
		case LL:
			tmp = ll_rot(root,root->left);
			printf("LL rotation!\n");
			break;
		default:
			printf("Error : key value is not RR,RL,LR,LL check the code\n");
			break;
	}
	return tmp;
}
int kinds_of_rot(avl** root){
	int left = (*root)->left ? (*root)->left->lev : 0;
	int right = (*root)->right ? (*root)->right->lev : 0;
	if(left > right){
		if(chk_rot(&(*root)->left) > 0)	
			return LL;
		return LR;
	}
	else{
		if(chk_rot(&(*root)->right) < 0)
			return RR;
		return RL;
	}
}
avl* rr_rot(avl* parent,avl* child){
	
	parent->right = child->left;
	child->left = parent;

	parent->lev = update_level(&parent);
	child->lev = update_level(&child);
	return child;
}
avl* rl_rot(avl* parent, avl* child){
	child = ll_rot(child,child->left);
	return rr_rot(parent,child);
}
avl* ll_rot(avl* parent,avl* child){
	parent->left = child->right;
	child->right = parent;
	
	parent->lev = update_level(&parent);
	child->lev = update_level(&child);
	return child;

}
avl* lr_rot(avl* parent,avl* child){
	child = rr_rot(child,child->right);
	return ll_rot(parent,child);
}
void ins_rand_data(avl** root,int* data){
	srand(time(NULL));
	int i = 0, tmp;
	while(i<12){
		tmp = rand()%100+1;
		if(is_dup_data(data,tmp))
			continue;
		data[i] = tmp;
		avl_ins(root,data[i]);
		i++;
	}
}
bool is_dup_data(int* data,int val){
	int i = 0;
	while(data[i]){
		if(val == data[i])
			return true;
		i++;
	}
	return false;
}
void print_data(int* data){
	int i = 0;
	while(data[i]){
		printf("%d(%d), ",data[i],i);
		i++;
	}
	printf("\n");
}
void del_avl(avl** root,int data){
	avl** tmp = root;
	stack* top = NULL;
	int max, chk;
	while(*tmp){
		if(data < (*tmp)->data){
			push(&top,tmp);
			printf("%d pushed!(by deletion)\n",(*tmp)->data);
			tmp = &(*tmp)->left;
		}
		else if(data > (*tmp)->data){
			push(&top,tmp);
			printf("%d pushed!(by deletion)\n",(*tmp)->data);
			tmp = &(*tmp)->right;
		}
		else if(data == (*tmp)->data){
			printf("del : %d\n",(*tmp)->data);
			break;
		}
	}
	print_stack(&top);
	if((*tmp)->left){
		push(&top,tmp);
		printf("%d pushed!\n",(*tmp)->data);
		print_stack(&top);
		findMax(&(*tmp)->left,&max,&top);
		(*tmp)->data = max;
	}
	else
		*tmp = chg_node(*tmp);
	print_stack(&top);
	while(is_not_empty(&top)){
		avl **p = (avl**)pop(&top);
		(*p)->lev = update_level(p);
		chk = chk_rot(p);
		if(abs(chk) > 1){
			printf("%d rotate!!(by deletion)\n",(*p)->data);
			*p = rotation(*p);
		}
	}
}
void findMax(avl** root,int* max,stack** top){
	avl** tmp = root;
	if(!(*tmp)){
		printf("Error:\n");
		return ;
	}
	while((*tmp)->right){
		push(top,tmp);
		printf("%d pushed!!\n",(*tmp)->data);
		tmp = &(*tmp)->right;
	}
	*max = (*tmp)->data;
	*tmp = chg_node(*tmp);
}
avl* chg_node(avl* root){
	avl* tmp = root;
	if(!(root->left))
		root = root->right;
	else if(!(root->right))
		root = root->left;
	free(tmp);
	return root;
}
void print_stack(stack** top){
	stack* tmp  = *top;
	avl** p;
	while(tmp){
		p = (avl**)tmp->data;
		tmp = tmp->link;
	}
}
