#include <stdio.h>
#include <stdlib.h>
#define element int
typedef struct __tree{
	element data;
	struct __tree* left;
	struct __tree* right;
}tree;
tree* get_tree_node(void);
void ins_tree(tree** root,element data);
void del_tree(tree** root,element data);
tree* findMax(tree** root);
void chg_node(tree** root);
int main(void){
	tree* root = NULL;
	ins_tree(&root, 10);
	ins_tree(&root, 5);
	ins_tree(&root, 15);
	printf("%d\n",root->data);
	printf("%d\n",root->left->data);
	printf("%d\n",root->right->data);

	del_tree(&root, 5);
	return 0;
}
tree* get_tree_node(void){
	tree* tmp;
	tmp = (tree*)malloc(sizeof(tree)*1);
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}
void ins_tree(tree** root,element data){
	tree** tmp = root;
	while(*tmp){
		if(data < (*tmp)->data)
			tmp = &(*tmp)->left;
		else if(data > (*tmp)->data)
			tmp = &(*tmp)->right;
	}
	*tmp = get_tree_node();
	(*tmp)->data = data;
}
void del_tree(tree** root,element data){
	tree** tmp = root;
	tree* del;
	tree* max;
	while(1){
		if(data < (*tmp)->data)
			tmp = &(*tmp)->left;
		else if(data > (*tmp)->data)
			tmp = &(*tmp)->right;
		else{
			del = *tmp;
			break;
		}
	}
	if(del->left)
		max = findMax(&del->left);
	else
		max = del;
	del->data = max->data;
	chg_node(&max);


}
tree* findMax(tree** root){
	tree* tmp = *root;
	while(tmp){
		if(tmp->right)
			tmp = tmp->right;
		else
			break;
	}
	return tmp;
}
void chg_node(tree** root){
	tree* tmp = *root;
	if((*root)->left)
		(*root) = (*root)->left;
}
