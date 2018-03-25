#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
typedef struct __tree{
	int data;
	struct __tree* left;
	struct __tree* right;
}tree;
typedef struct __stack{
	void* data;
	struct __stack* link;
}stack;
tree* get_tree_node(void);
void ins_tree(tree** root,int data);
stack* get_stack_node(void);
void push(stack** top,void* data);
void* pop(stack** top);
void print_tree(tree** root);
bool is_not_empty(stack** top);
void init_rand_data(int* data,int size);
void ins_data_to_tree(tree** root,int* data,int size);
void del_tree(tree** root,int data);
tree* chgnode(tree* root);
void findMax(tree** root,int* max);
int main(void){
	srand(time(NULL));
	tree* root = NULL;
	int data[20];
	int size = sizeof(data)/sizeof(int);
	
	init_rand_data(data,size);
	ins_data_to_tree(&root,data,size);

	print_tree(&root);
	printf("\nafter delete %d : \n",data[3]);
	del_tree(&root,data[3]);
	print_tree(&root);
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
	(*tmp) = get_tree_node();
	(*tmp)->data = data;
	
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
	if(!is_not_empty(top)){
		printf("No data in stack\n");
		return NULL;
	}
	void* data = (*top)->data;
	*top = (*top)->link;
	free(tmp);
	return data;
}
void print_tree(tree** root){
	stack* top = NULL;
	tree* tmp = *root;
	
	if(is_not_empty(&top))
		printf("err");
	while(tmp){
		printf("data : %d, ",tmp->data);
		if(tmp->left)
			printf("left : %d ",tmp->left->data);
		else
			printf("left : NULL, ");
		if(tmp->right)
			printf("right : %d\n",tmp->right->data);
		else
			printf("right : NULL\n");
		if(tmp->right)
			push(&top,&tmp->right);
		if(tmp->left)
			tmp = tmp->left;
		else
			break;
	}
	while(is_not_empty(&top)){
		tree** p = (tree**)pop(&top);
		tmp = *p;
		while(tmp){
			printf("data : %d, ",tmp->data);
			if(tmp->left)
				printf("left : %d, ",tmp->left->data);
			else
				printf("left : NULL, ");
			if(tmp->right)
				printf("right : %d\n",tmp->right->data);
			else
				printf("right : NULL\n");
			if(tmp->right)
				push(&top,&tmp->right);
			if(tmp->left)
				tmp = tmp->left;
			else
				break;
		}
	}
}
bool is_not_empty(stack** top){
	if(*top)
		return true;
	return false;
}
void init_rand_data(int* data,int size){
	int i;
	for(i=0;i<size;i++)
		data[i] = rand()%100 + 1;
}
void ins_data_to_tree(tree** root,int* data,int size){
	int i;
	for(i=0;i<size;i++)
		ins_tree(root,data[i]);
}
void del_tree(tree** root,int data){
	tree** tmp = root;
	int max;
	while(*tmp){
		if(data < (*tmp)->data)
			tmp = &(*tmp)->left;
		else if(data > (*tmp)->data)
			tmp = &(*tmp)->right;
		else
			break;
	}
	//currently, tmp has the address that wll be deleted.
	
	if((*tmp)->left){
		findMax(&(*tmp)->left,&max);
		(*tmp)->data = max;
	}
	else
		*tmp = chgnode(*tmp);

}
tree* chgnode(tree* root){
	tree* tmp  = root;
	if(tmp->left)
		root = root->left;
	else if(tmp->right)
		root = root->right;
	else
		root = NULL;
	free(tmp);
	return root;
}
void findMax(tree** root,int* max){
	while(*root){
		if((*root)->right)
			root = &(*root)->right;
		else
			break;
	}
	*max = (*root)->data;
	*root = chgnode(*root);


}
