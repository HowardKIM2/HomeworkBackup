#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
typedef enum __rot{
	RR,
	RL,
	LR,
	LL
}rot;
typedef struct __avl{
	int data;
	int lev;
	struct __avl* left;
	struct __avl* right;
}avl;
typedef struct __stack{
	int data;
	struct __stack* link;
}stack;
stack* get_stack_node(void);
void push(stack** top,int data);
int pop(stack** top);
void print_stack(stack** top);
void init_rand_arr(int* data, int size);
bool is_not_dup(int* data,int tmp);
void ins_data_to_stack(stack** top,int* data);
avl* get_avl_node(void);
void ins_avl(avl** root,int data);
void print_avl(avl** root);
int update_lev(avl* root);
bool chk_rot(avl* root);
int kinds_of_rot(avl* root);
void rotation(avl** root,int kinds);
avl* rr_rot(avl* parent,avl* child);
avl* ll_rot(avl* parent,avl* child);
avl* rl_rot(avl* parent,avl* child);
avl* lr_rot(avl* parent,avl* child);
void del_avl(avl** root, int data);
void findMax(avl** root, int* max);
avl* chgnode(avl* root);
int main(void){
	stack* top = NULL;
	avl* root = NULL;
	int data[21]={0,};
	int size = sizeof(data)/sizeof(int) - 1;
	int tmp;
	init_rand_arr(data,size);
	ins_data_to_stack(&top,data);
	printf("current stack data : \n");
	print_stack(&top);

	//odd num to avl tree
	while(top){
		tmp = pop(&top);
		printf("%d pop!\n",tmp);
		if(tmp % 2){
			printf("%d inserted!\n",tmp);
			ins_avl(&root, tmp);
		}
	}
	printf("\nodd data in avl\n");
	print_avl(&root);
	return 0;
}
stack* get_stack_node(void){
	stack* tmp;
	tmp = (stack*)malloc(sizeof(stack)*1);
	tmp->link = NULL;
	return tmp;
}
void push(stack** top,int data){
	stack* tmp = *top;
	(*top) = get_stack_node();
	(*top)->data = data;
	(*top)->link = tmp;
}
int pop(stack** top){
	int data;
	stack* tmp = *top;
	if(*top){
		data = (*top)->data;
		*top = (*top)->link;
		free(tmp);
		return data;
	}
	printf("There is no data in stack\n");
	return 0;
	
}
void print_stack(stack** top){
	stack* tmp = *top;
	while(tmp){
		printf("data : %d\n",tmp->data);
		tmp = tmp->link;
	}
}
void init_rand_arr(int* data, int size){
	int i, tmp;
	srand(time(NULL));
	for(i=0;i<size;){	
		tmp = rand()%100+1;
		if(is_not_dup(data,tmp))
			data[i++] = tmp;
	}

}
bool is_not_dup(int* data,int tmp){
	int i = 0;
	while(data[i]){
		if(data[i++] == tmp)
			return false;
	}
	return true;
}
void ins_data_to_stack(stack** top,int* data){
	int i = 0;
	while(data[i])
		push(top,data[i++]);
	
}
avl* get_avl_node(void){
	avl* tmp;
	tmp = (avl*)malloc(sizeof(avl)*1);
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->lev = 1;
	return tmp;
}
void ins_avl(avl** root,int data){
	avl* tmp = *root;
	if(!tmp){
		*root = get_avl_node();
		(*root)->data = data;
	}
	else{
		if(data < (*root)->data){
			ins_avl(&(*root)->left,data);
		}
		else if(data > (*root)->data){
			ins_avl(&(*root)->right,data);
		}
		else{
			//duplicated data
			if(!(*root)->left)
				ins_avl(&(*root)->left,data);
			else if(!(*root)->right)
				ins_avl(&(*root)->right,data);
			else
				ins_avl(&(*root)->left,data);
		}
		(*root)->lev = update_lev(*root);
		if(chk_rot(*root)){
			printf("rotate : %d\n",(*root)->data);
			rotation(root,kinds_of_rot(*root));
		}
		return;
	}

}	
void print_avl(avl** root){
	if(*root){
		printf("data : %d, lev : %d, left : ",(*root)->data,(*root)->lev);
		if((*root)->left)
			printf("%d, right : ",(*root)->left->data);
		else
			printf("NULL, right : ");
		if((*root)->right)
			printf("%d\n",(*root)->right->data);
		else
			printf("NULL\n");
		print_avl(&(*root)->left);
		print_avl(&(*root)->right);
	}
}
int update_lev(avl* root){
	int left = root->left ? root->left->lev : 0;
	int right = root->right ? root->right->lev : 0;
	
	if(left > right)
		return left + 1;
	return right + 1;
}
bool chk_rot(avl* root){
	int left = root->left ? root->left->lev : 0;
	int right = root->right ? root->right->lev : 0;
	
	if(abs(left - right) > 1)
		return true;
	return false;
}
int kinds_of_rot(avl* root){
	int left = root->left ? root->left->lev : 0;
	int right = root->right ? root->right->lev : 0;
	if(left - right > 1){
		int n_left = root->left->left ? root->left->left->lev : 0;
		int n_right = root->left->right ? root->left->right->lev : 0;
		if(n_left > n_right)
			return LL;
		return LR;
	}
	else if(left - right < -1){
		int n_left = root->right->left ? root->right->left->lev : 0;
		int n_right = root->right->right ? root->right->right->lev : 0;
		if(n_left > n_right)
			return RL;
		return RR;
	}	
	else{
		printf("it dosen't have rotate condition\n");
		return -1;
	}
}
void rotation(avl** root,int kinds){
	switch(kinds){
		case RR:
			printf("%d, RR rotation\n",(*root)->data);
			*root = rr_rot(*root,(*root)->right);
			break;
		case RL:
			printf("%d, RL rotation\n",(*root)->data);
			*root = rl_rot(*root,(*root)->right);
			break;
		case LR:
			printf("%d, LR rotation\n",(*root)->data);
			*root = lr_rot(*root,(*root)->left);
			break;
		case LL:
			printf("%d, LL rotation\n",(*root)->data);
			*root = ll_rot(*root,(*root)->left);
			break;
	}

}
avl* rr_rot(avl* parent,avl* child){
	parent->right = child->left;
	child->left = parent;
	
	parent->lev = update_lev(parent);
	child->lev = update_lev(child);
	return child;
}
avl* ll_rot(avl* parent,avl* child){
	parent->left = child->right;
	child->right = parent;
	
	parent->lev = update_lev(parent);
	child->lev = update_lev(child);
	return child;
}
avl* rl_rot(avl* parent,avl* child){
	child = ll_rot(child,child->left);
	parent = rr_rot(parent,child);

	return parent;
}
avl* lr_rot(avl* parent,avl* child){
	child = rr_rot(child,child->right);
	parent = ll_rot(parent,child);

	return parent;
}
void del_avl(avl** root, int data){
	avl* del = *root;
	int max;
	while(*root){
		if(data < (*root)->data)
			del_avl(&(*root)->left,data);
		else if(data > (*root)->data)
			del_avl(&(*root)->right,data);
		//if data is duplicated, 
		//super upper's one among them be deleted.
		else
			break;
		return ;
	}
	printf("del : %d\n",del->data);
	if((*root)->left){
		findMax(&(*root)->left,&max);
		del->data = max;
	}
	else{
	
		*root = chgnode(*root);
	}
}
void findMax(avl** root, int* max){
	avl** tmp = root;
	while(*tmp){
		if((*tmp)->right)
			tmp = &(*tmp)->right;
		else
			break;
	}
	*max = (*tmp)->data;
	*tmp = chgnode(*tmp);

}
avl* chgnode(avl* root){
	avl* tmp = root;
	if(!root->left)
		root = root->right;
	else
		root = root->left;
	free(tmp);
	return root;
}
