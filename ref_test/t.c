#include <stdio.h>
#include <stdlib.h>
typedef struct __tree{
	int data;
	struct __tree *right;
	struct __tree *left;
}tree;
tree* get_node(void){
	tree* tmp;
	tmp = (tree*)malloc(sizeof(tree)*1);
	tmp->right = NULL;
	tmp->left = NULL;
}
void print(tree** root);
int main(void){
	tree* root;
	tree* tmp1;
	tree* tmp2;
	tree* tmp3;
	root = get_node();
	tmp1 = get_node();
	tmp2 = get_node();
	tmp3 = get_node();
	root->data = 10;
	tmp1->data = 20;
	tmp2->data = 30;
	tmp3->data = 40;
	root->right=tmp1;
	root->right->right=tmp2;
	root->right->right->right=tmp3;
	root->right->right->right = NULL;
	tmp3;
	free(tmp3);
	print(&root);
	return 0;
}

void print(tree** root){
	if(*root){
		printf("%d\n",(*root)->data);
		print(&((*root)->left));
		print(&((*root)->right));
	}
}
