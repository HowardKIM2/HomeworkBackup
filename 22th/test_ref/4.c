#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct __tree{
	int data;
	struct __tree* left;
	struct __tree* right;
}tree;
tree* get_node(void);
void ins_tree(tree** root,int data);
void print_tree(tree** root);
void del_tree(tree** root,int data);
tree* findMax(tree** root,int* max);
tree* chgnode(tree* root);
void init_rand_arr(int* data,int size);
void ins_data_to_tree(tree** root,int* data,int size);
int main(void){
	srand(time(NULL));
	tree* root = NULL;
	int data[20];
	
	init_rand_arr(data,sizeof(data)/sizeof(int));
	ins_data_to_tree(&root,data,sizeof(data)/sizeof(int));

	print_tree(&root);
	del_tree(&root,data[5]);
	printf("\nafter delete %d\n",data[5]);
	print_tree(&root);
}
tree* get_node(void){
	tree* tmp;
	tmp = (tree*)malloc(sizeof(tree)*1);
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}
void ins_tree(tree** root,int data){
	if(*root == NULL){
		(*root) = get_node();
		(*root)->data = data;
	}
	else if(data < (*root)->data)
		ins_tree(&(*root)->left,data);
	else if(data > (*root)->data)
		ins_tree(&(*root)->right,data);
	
	//duplicated data.
	else{
		if(!(*root)->left)
			ins_tree(&(*root)->left,data);
		else if(!(*root)->right)
			ins_tree(&(*root)->right,data);
		else	
			ins_tree(&(*root)->left,data);
	}
		
}
void print_tree(tree** root){
	if(*root){
		printf("data : %d, left : ",(*root)->data);
		if((*root)->left)
			printf("%d, ",(*root)->left->data);
		else
			printf("NULL, ");
		if((*root)->right)
			printf("right : %d\n",(*root)->right->data);
		else
			printf("right : NULL\n");
		print_tree(&(*root)->left);
		print_tree(&(*root)->right);
	}
}
void del_tree(tree** root,int data){
	int max;
	tree* del;
	if(*root){
		if(data < (*root)->data){
			del_tree(&(*root)->left,data);
			return ;
		}
		else if(data > (*root)->data){
			del_tree(&(*root)->right,data);
			return ;
		}
	}
	del = *root;
	if((*root)->left){
		del = findMax(&(*root)->left,&max);
		(*root)->data = max;
	}
	else
		*root  = chgnode(*root);
	

}
tree* findMax(tree** root,int* max){
	tree* tmp = *root;
	if((*root)->right){
		findMax(&(*root)->right,max);
		return NULL;
	}
	*max = (*root)->data;
	*root = chgnode(*root);
	return tmp;
}
tree* chgnode(tree* root){
	tree* tmp = root;
	if(root->left)
		root = root->left;
	else
		root = root->right;
	free(tmp);
	return root;
}
void init_rand_arr(int* data,int size){
	int i;
	for(i=0;i<size;i++)
		data[i] = rand()%100 + 1;
}
void ins_data_to_tree(tree** root,int* data,int size){
	int i;
	for(i=0;i<size;i++)
		ins_tree(root,data[i]);
}
