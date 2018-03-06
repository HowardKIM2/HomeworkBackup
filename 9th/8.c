#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
	int data;
	struct tree *l_node;
	struct tree *r_node;
}Tree;

Tree* get_node(void);
void entree(Tree** root,int data);
Tree* detree(Tree** root,int data);
int findMax(Tree** root);
Tree* findDelete(Tree** root,int data);
void print_Tree(Tree** root);
void changeNode(Tree** root,int data);

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

	
	printf("origin tree : \n");
	print_Tree(&root);
	detree(&root,130);
	printf("deleted tree : \n");
	print_Tree(&root);
	printf("\n");
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


Tree* detree(Tree** root,int data){
	
	Tree *deleted_node;
	int max;

	deleted_node = *root;
	deleted_node = findDelete(&deleted_node,data);		
	
	if(deleted_node->l_node)	
		max = findMax(&(deleted_node->l_node));
	else if(deleted_node->r_node)
		max = findMax(&(deleted_node->r_node));
	else
		max = deleted_node->data;


	printf("\n\ndel : %d\nmax : %d\n\n",deleted_node->data,max);

	deleted_node->data = max;
	
	if(deleted_node->l_node)
		changeNode(&(deleted_node->l_node),max);
	else if(deleted_node->r_node){
		changeNode(&(deleted_node),max);
	}
	else{
		free(deleted_node);
	}
		
}
	
Tree* findDelete(Tree** root,int data){
	
	Tree* deleted_node;
	deleted_node = *root;
	
	if(deleted_node->data < data)
		findDelete(&(deleted_node->r_node),data);
	else if(deleted_node->data > data)
		findDelete(&(deleted_node->l_node),data);
	else
		return deleted_node;
}

int findMax(Tree** root){
	
	Tree *tmp;
	tmp = *root;
	
	if(tmp->r_node)
		findMax(&(tmp->r_node));
	else
		return tmp->data;
}

void print_Tree(Tree** root){
	Tree* tmp = *root;
	if((tmp->l_node)&&(tmp->r_node)){
		printf("%d ",tmp->data);
		print_Tree(&(tmp->l_node));
		print_Tree(&(tmp->r_node));
	}
	else if(tmp->l_node){
		printf("%d ",tmp->data);
		print_Tree(&(tmp->l_node));
	}
	else if(tmp->r_node){
		printf("%d ",tmp->data);
		print_Tree(&(tmp->r_node));
	}
	else
		printf("%d ",tmp->data);
//	printf("%d ",tmp->data);
	
}

void changeNode(Tree** root,int data){
	Tree* tmp = *root;
	if(tmp->data == data){
	
	}


	Tree* tmp;
}
