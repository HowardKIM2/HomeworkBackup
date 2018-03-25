#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
typedef enum __rot{
	RR,
	RL,
	LR,
	LL
}rot;
typedef struct __avl{
	char* data;
	int lev;
	struct __avl* left;
	struct __avl* right;
}avl;
avl* get_avl_node(void);
void ins_avl(avl** root,char* data);
void print_avl(avl** root);
int update_lev(avl* root);
bool chk_rot(avl* root);
int kinds_of_rot(avl* root);
void rotation(avl** root,int kinds);
avl* rr_rot(avl* parent,avl* child);
avl* ll_rot(avl* parent,avl* child);
avl* rl_rot(avl* parent,avl* child);
avl* lr_rot(avl* parent,avl* child);
void del_avl(avl** root, char* data);
void findMax(avl** root, char** max);
avl* chgnode(avl* root);
int main(void){
	avl* root = NULL;
	ins_avl(&root,"aaa");
	ins_avl(&root,"bbb");
	ins_avl(&root,"ccc");
	ins_avl(&root,"ddd");
	ins_avl(&root,"eee");
	print_avl(&root);
	del_avl(&root,"aaa");
	print_avl(&root);
}
avl* get_avl_node(void){
	avl* tmp;
	tmp = (avl*)malloc(sizeof(avl)*1);
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->lev = 1;
	return tmp;
}
void ins_avl(avl** root,char* data){
	avl* tmp = *root;
	if(!tmp){
		*root = get_avl_node();
		(*root)->data = data;
	}
	else{
		if(strcmp(data,(*root)->data) < 0){
			ins_avl(&(*root)->left,data);
		}
		else if(strcmp(data,(*root)->data) > 0){
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
			printf("rotate : %s\n",(*root)->data);
			rotation(root,kinds_of_rot(*root));
		}
		return;
	}

}	
void print_avl(avl** root){
	if(*root){
		printf("data : %s, lev : %d, left : ",(*root)->data,(*root)->lev);
		if((*root)->left)
			printf("%s, right : ",(*root)->left->data);
		else
			printf("NULL, right : ");
		if((*root)->right)
			printf("%s\n",(*root)->right->data);
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
			printf("%s, RR rotation\n",(*root)->data);
			*root = rr_rot(*root,(*root)->right);
			break;
		case RL:
			printf("%s, RL rotation\n",(*root)->data);
			*root = rl_rot(*root,(*root)->right);
			break;
		case LR:
			printf("%s, LR rotation\n",(*root)->data);
			*root = lr_rot(*root,(*root)->left);
			break;
		case LL:
			printf("%s, LL rotation\n",(*root)->data);
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
void del_avl(avl** root, char* data){
	avl* del = *root;
	char* max;
	while(*root){
		if(strcmp(data,(*root)->data) < 0)
			del_avl(&(*root)->left,data);
		else if(strcmp(data ,(*root)->data) > 0)
			del_avl(&(*root)->right,data);
		//if data is duplicated, 
		//super upper's one among them be deleted.
		else
			break;
		return ;
	}
	printf("del : %s\n",del->data);
	if((*root)->left){
		findMax(&(*root)->left,&max);
		del->data = max;
	}
	else{
		*root = chgnode(*root);
	}
}
void findMax(avl** root, char** max){
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
