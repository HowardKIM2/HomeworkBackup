#include <stdio.h>
#include <stdlib.h>
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
	struct __avl *right;
	struct __avl *left;
}avl;

avl* get_node(void);
void avl_ins(avl** root,int data);
void print_avl(avl** root);
int update_level(avl** root,int data);
int rot_chk(avl** root,int data);
int kinds_of_rot(avl** root,int data);
void rotate(avl** root,int data,int kinds);

int main(void){
	avl* root = NULL;
	avl_ins(&root,40);
	avl_ins(&root,50);
	avl_ins(&root,45);
	print_avl(&root);
	return 0;
}

avl* get_node(){
	avl* tmp;

	tmp = (avl*)malloc(sizeof(avl)*1);
	tmp->right = NULL;
	tmp->left = NULL;
	tmp->lev = 1;
	
	return tmp;
}

void avl_ins(avl** root,int data){
	avl* tmp = get_node();
	if(!(*root)){
		*root = tmp;
		(*root)->data = data;
		return;
	}
	if(data < (*root)->data)
		avl_ins(&((*root)->left),data);
	else if(data > (*root)->data)
		avl_ins(&((*root)->right),data);
	else{
		//미구현(중복데이터 저장)
	}
	(*root)->lev = update_level(root,data);
	
	if(abs(rot_chk(root,data))>1)
		printf("kinds : %d!\n",kinds_of_rot(root,data));
	/*
	if(abs(rot_chk(root,data))>1){
		rotate(root,data,kinds_of_rot(root,data));
	}*/
}

void print_avl(avl** root){
	int right,left;

	if(*root){

		if((*root)->right)
			right = ((*root)->right)->lev;
		else
			right = 0;
		if((*root)->left)
			left = ((*root)->left)->lev;
		else
			left = 0;

		printf("data : %d, lev : %d, right : %d, left : %d\n",
						(*root)->data,(*root)->lev,right,left);
		print_avl(&((*root)->left));
		print_avl(&((*root)->right));
	}
}

int update_level(avl** root,int data){
	int right = (*root)->right ? ((*root)->right)->lev : 0;
	int left = (*root)->left ? ((*root)->left)->lev : 0;
	if(right > left)
		return right + 1;
	return left + 1;
}

int rot_chk(avl** root,int data){
	int right = (*root)->right ? ((*root)->right)->lev : 0;
	int left = (*root)->left ? ((*root)->left)->lev : 0;
	return right - left;
}

int kinds_of_rot(avl**root,int data){
	int right, left;
	int chk = rot_chk(root,data);
	if(chk > 1){
	    right = ((*root)->right)->right ? (((*root)->right)->right)->lev : 0;
	    left = ((*root)->right)->left ? (((*root)->right)->left)->lev : 0;
		if(right > left){
			printf("RR\n");
			return RR;
		}
		else{
			printf("RL\n");
			return RL;
		}
	}
	else if(chk < -1){
		if(right < left){
			printf("LL\n");
			return LL;
		}
		else{
			printf("LR\n");
			return LR;
		}
	}
																		
}

void rotate(avl** root,int data,int kinds){
	avl *tmp;
	printf("rotate !! : %d\n",kinds);
	switch(kinds){
		case RR:
			tmp = *root;
			*root = (*root)->right;
			tmp->right = (*root)->left;
			(*root)->left = tmp;

			((*root)->right)->lev = update_level(&((*root)->right),data);
			((*root)->left)->lev = update_level(&((*root)->left),data);
			(*root)->lev = update_level(root,data);
			break;
		case RL:
			tmp = (*root)->right;
			(*root)->right = ((*root)->right)->left;
			((*root)->right)->right = tmp;
			tmp->left = (*root)->right->right;
			
			(((*root)->right)->right)->lev = update_level(&(((*root)->right)->right),data);
			((*root)->right)->lev = update_level(&((*root)->right),data);
			(*root)->lev = update_level(root,data);
			break;
		case LR:
			tmp = (*root)->left;
			(*root)->left = ((*root)->left)->right;
			((*root)->left)->left = tmp;
			tmp->right = (*root)->right;

			(((*root)->left)->left)->lev = update_level(&(((*root)->left)->left),data);
			((*root)->left)->lev = update_level(&((*root)->left),data);
			(*root)->lev = update_level(root,data);	
			break;
		case LL:
			tmp = *root;
			*root = (*root)->left;
			tmp->left = (*root)->right;
			(*root)->right = tmp;

			((*root)->right)->lev = update_level(&((*root)->right),data);
			((*root)->left)->lev = update_level(&((*root)->left),data);
			(*root)->lev = update_level(root,data);
			break;

		default:
			printf("err!\n");
			break;
	}


	if(abs(rot_chk(root,data))>1)
		rotate(root,data,kinds_of_rot(root,data));
}
