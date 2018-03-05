#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
	int data;
	struct tree *l_node;
	struct tree *r_node;
}Tree;

Tree* get_node(void);
void entree(Tree** root,int data);
void printTree(Tree** root);
int main(void){

	Tree *root = NULL;
	Tree *tmp1;
	Tree *tmp2;
	
	entree(&root,50);
	entree(&root,45);
	entree(&root,73);
	entree(&root,32);
	entree(&root,48);
	entree(&root,46);
	entree(&root,16);
	entree(&root,37);
	entree(&root,120);
	entree(&root,47);
	entree(&root,130);
	entree(&root,127);
	entree(&root,124);


}

void entree(Tree** root,int data){
	int num;
	Tree* tmp;
	
	if(*root == NULL){
		tmp = get_node();
		tmp->data = data;
		*root = tmp;		
	}
	else{
		num = (*root)->data;
		data>num ? entree(&((*root)->r_node),data) : entree(&((*root)->l_node),data);
	}

}


Tree* get_node(void){
	Tree *tmp;
	tmp = (Tree*)malloc(sizeof(Tree)*1);
	tmp->l_node = NULL;
	tmp->r_node = NULL;
	
	return tmp;
}


	
