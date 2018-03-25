#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct __tree{
	char* data;
	struct __tree* left;
	struct __tree* right;
}tree;
tree* get_node(void);
void ins_tree(tree** root,char* data);
void print_tree(tree** root);
void del_tree(tree** root,char* data);
tree* findMax(tree** root,char** max);
tree* chgnode(tree* root);

int main(void){
	tree* root = NULL;
	
	ins_tree(&root,"aaa");
	ins_tree(&root,"bbb");
	ins_tree(&root,"ddd");
	ins_tree(&root,"ccc");
	print_tree(&root);
}
tree* get_node(void){
	tree* tmp;
	tmp = (tree*)malloc(sizeof(tree)*1);
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}
void ins_tree(tree** root,char* data){
	if(*root == NULL){
		(*root) = get_node();
		(*root)->data = data;
	}
	else if(strcmp(data,(*root)->data) < 0)
		ins_tree(&(*root)->left,data);
	else if(strcmp(data,(*root)->data) > 0)
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
		printf("data : %s, left : ",(*root)->data);
		if((*root)->left)
			printf("%s, ",(*root)->left->data);
		else
			printf("NULL, ");
		if((*root)->right)
			printf("right : %s\n",(*root)->right->data);
		else
			printf("right : NULL\n");
		print_tree(&(*root)->left);
		print_tree(&(*root)->right);
	}
}
void del_tree(tree** root,char* data){
	char* max;
	tree* del;
	if(*root){
		if(strcmp(data , (*root)->data) < 0){
			del_tree(&(*root)->left,data);
			return ;
		}
		else if(strcmp(data , (*root)->data) > 0){
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
tree* findMax(tree** root,char** max){
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
