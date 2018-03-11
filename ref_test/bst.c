#include <stdio.h>
#include <stdlib.h>
#define element int
typedef struct __tree{
	element data;
	struct __tree *right;
	struct __tree *left;
}tree;
typedef struct __stack{
	element data;
	struct __stack *p_node;
}stack;

tree* get_node(void);
tree* tree_ins(tree** root,element data);
void disp_tree(tree** root);
void del_tree(tree** root,element data);
int main(void){
	tree* root = NULL;
	char ch;
	element data;
	while(1){
		printf("Instruction quit(q), insert(i), delete(d), display(p) : ");
		scanf("%c%*c",&ch);
		system("clear");
		switch(ch){
			case 'q':
				printf("quit!\n");
				break;
			case 'p':
				printf("current tree :\n");
				disp_tree(&root);
				break;
			case 'i':
				printf("data : ");
				scanf("%d%*c",&data);
				root = tree_ins(&root,data);
				break;
			case 'd':
				printf("del data : ");
				scanf("%d%*c",&data);
				del_tree(&root,data);
				break;
			default:
				printf("wrong instruction!\n");
				break;
		}
		if(ch == 'q')
			break;
	}
}

tree* get_node(void){
	tree* tmp;
	tmp = (tree*)malloc(sizeof(tree)*1);
	tmp->right = NULL;
	tmp->left = NULL;
	return tmp;
}
tree* tree_ins(tree** root,element data){
	tree* b_root = *root;
	tree* prev = *root;
	if(!(*root)){
		*root = get_node();
		(*root)->data = data;
		return *root;
	}
	while(1){
		if(!(*root)){
			(*root) = get_node();
			(*root)->data = data;
			if(prev){
				if(prev->data > (*root)->data)
					prev->left = *root;
				else
					prev->right = *root;
			}
			break;
		}
		else if(data < (*root)->data){
			prev = *root;
			(*root) = (*root)->left;
		}
		else if(data > (*root)->data){
			prev = *root;
			(*root) = (*root)->right;
		}
		else{
			printf("duplicated data!!\n");
			break;
		}
	}
	return b_root;
}
void disp_tree(tree** root){
	if(*root){
		printf("data : %d, ",(*root)->data);
		if((*root)->left)
			printf("left : %d, ",(*root)->left->data);
		else
			printf("left : NULL, ");
		if((*root)->right)
			printf("right : %d\n",(*root)->right->data);
		else
			printf("right : NULL\n");
		disp_tree(&((*root)->left));
		disp_tree(&((*root)->right));
	}
}
void del_tree(tree** root,element data){
	tree* tmp = *root;
	tree* parent = NULL;
	tree* del;
	if(!tmp){
		printf("there is no %d in tree\n",data);
		return;
	}
	
	while(1){
		if(data > tmp->data){
			parent = tmp;
			if(!tmp->right){
				printf("there is no %d in tree\n",data);
				return;
			}
			tmp = tmp->right;
		}
		else if(data < tmp->data){
			parent = tmp;
			if(!tmp->left){
				printf("there is no %d in tree\n",data);
				return;
			}
			tmp = tmp->left;
		}
		else
			break;
	}
	del = tmp;
	
	if((!parent)&&(!tmp->left)){
		(*root) = (*root)->right;
		free(tmp);
		return;
	}
	else if(tmp->left){
		parent = tmp;
		tmp = tmp->left;
		while(1){
			if(tmp->right){
				parent = tmp;
				tmp = tmp->right;
			}
			else
				break;
		}
	}
	del->data = tmp->data;
	
	if(tmp->left)
		parent->data < tmp->data ? (parent->right = tmp->left) : (parent->left = tmp->left) ;
	else{
		parent->data < tmp->data ? (parent->right = NULL) : (parent->left = NULL) ;
	}

	free(tmp);
}
