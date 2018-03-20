#include <stdio.h>
#include <stdlib.h>

typedef struct __tree
{
	char* data;
	struct __tree *left;
	struct __tree *right;
} tree;

tree *get_node(void)
{
	tree *tmp;
	tmp = (tree *)malloc(sizeof(tree));
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}

void tree_ins(tree **root, char* data)
{
	if(*root == NULL)
	{
		*root = get_node();
		(*root)->data = data;
		return;
	}
	else if(!(*root)->left)
		tree_ins(&(*root)->left, data);
	else if(!(*root)->right)
		tree_ins(&(*root)->right, data);
	else
		tree_ins(&(*root)->left, data);
}









void print_tree(tree *root)
{
	if(root)
	{
		printf("data = %s, ", root->data);

		if(root->left)
			printf("left = %s, ", root->left->data);
		else
			printf("left = NULL, ");

		if(root->right)
			printf("right = %s\n", root->right->data);
		else
			printf("right = NULL\n");

		print_tree(root->left);
		print_tree(root->right);
	}
}


int main(void)
{
	int i;

	tree *root = NULL;

	tree_ins(&root, "aaa");
	tree_ins(&root, "bbb");
	tree_ins(&root, "ccc");
	tree_ins(&root, "ddd");
	tree_ins(&root, "eee");
	tree_ins(&root, "fff");

	print_tree(root);


	return 0;
}


