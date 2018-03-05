#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
	int data;
	struct tree *l_node;
	struct tree *r_node;
}Tree;

Tree* get_node(void);
void entree(Tree** root,int data);
Tree* findTree1(Tree** root,int data);
Tree* findTree2(Tree** root,int data);
Tree* findUpperNode(Tree** root,int data);
void detreeL(Tree** root,int data);

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





	printf("root : %d\n",root->data);
	printf("l : %d\n",(root->l_node)->data);
	printf("lr :%d\n",((root->l_node)->r_node)->data);
	printf("lrl : %d\n",(((root->l_node)->r_node)->l_node)->data);
	
	detreeL(&root,50);

	printf("root : %d\n",root->data);
	printf("lr : %d\n",(((root->l_node)->r_node))->data);
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

Tree* findTree1(Tree** root,int data){
	Tree *tmp = *root;
	
	if(data > tmp->data)
		findTree1(&(tmp->r_node),data);
	else if(data < (*root)->data)
		findTree1(&(tmp->l_node),data);
	else
		return tmp;
	
}

Tree* findTree2(Tree** root,int data){
	Tree *tmp = *root;
	if(tmp->r_node == NULL)
		return tmp;
	if((tmp->r_node)->data > data){
		if(tmp->l_node != NULL)
			findTree2(&(tmp->l_node),data);
		else
			return tmp;
	}
	else{
		if(tmp->r_node !=NULL)
			findTree2(&(tmp->r_node),data);
		else
			return tmp;
	}

}
	
Tree* findUpperNode(Tree** root,int data){
	Tree* tmp = *root;
	if(tmp->data > data){
		if((tmp->l_node)->data != data){
			findUpperNode(&(tmp->l_node),data);
		}
	}
	else{
		if((tmp->r_node)->data != data)
			findUpperNode(&(tmp->r_node),data);
		else
			return tmp;
	}
}
void detreeL(Tree** root,int data){
	Tree* tmp1;
	Tree* tmp2;
	Tree* tmp2_upper;

	tmp1 = findTree1(root,data);
	tmp2 = findTree2(&tmp1,data);
	tmp2_upper = findUpperNode(root,tmp2->data);
	
	tmp1->data = tmp2->data;
	tmp2_upper->r_node = tmp2->l_node;	
}
