#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct tree{
	int data;
	int level;
	struct tree* l_node;
	struct tree* r_node;
}Tree;

Tree* get_node(void);
void print_Tree(Tree** root);
void rotateTree(Tree base);
void entree(Tree** root,int data);
int levelDiff(Tree** root);

int main(void){
	Tree* root = NULL;
	entree(&root,1);
	entree(&root,2);
	entree(&root,3);
	
	
	print_Tree(&root);
	
	return 0;
}
Tree* get_node(){
	Tree* tmp;
	tmp = (Tree*)malloc(sizeof(Tree)*1);
	tmp->l_node = NULL;
	tmp->r_node = NULL;
	tmp->level = 1;

	return tmp;
}

void entree(Tree** root,int data){
	Tree* tmp;
	
	tmp = get_node();
	tmp->data = data;
	
	

	if(!(*root)){
		*root = tmp;
	}	
	else{
		if(data < (*root)->data){
			(*root)->level = (*root)->level + 1;
			entree(&((*root)->l_node),data);
		}
		else if(data > (*root)->data){
			(*root)->level = (*root)->level + 1;
			entree(&((*root)->r_node),data);
		/*	if(levelDiff(root) == 2)
				printf("rotate data : %d\n",(*root)->data);
		*/
			printf("debug\n");
		}
		else{
			//중복시 미구현
		}
	}	
  
}

void print_Tree(Tree** root){
	if(*root){
		printf("data : %d, level : %d\n",(*root)->data,(*root)->level);
		print_Tree(&((*root)->l_node));
		print_Tree(&((*root)->r_node));
	}

}

void rotateTree(Tree base){

}
int levelDiff(Tree** root){
	
	int diff = 0;
	int left = 0, right = 0;
	if((*root)->l_node)
		left = ((*root)->l_node)->level;
	
	if((*root)->r_node)
		left = ((*root)->r_node)->level;
	
	diff = left - right;
	diff = abs(diff);
	return diff;
}
