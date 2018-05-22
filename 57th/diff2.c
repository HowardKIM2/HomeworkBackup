#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct __stack
{
	char eq[64];
	struct __stack* node;
}stack;
typedef struct __expr
{
	char eq[64];
	struct __expr* left;
	struct __expr* right;
}expr;
expr* get_expr_node(void);
void ins_expr_node(expr** root);
int find_equal_idx(char* buf);
void init_expr_node(expr** root, expr** ln, expr** rn);
void set_ln_node(expr** ln, char* buf, int eq_idx);
void set_rn_node(expr** rn, char* buf, int eq_idx);
stack* get_stack_node(void);
void push(stack** top, char* buf);
void pop(stack** top,char* buf);
bool is_not_empty(stack** top);
void ins_tree(expr** root, char* buf);
void print_tree(expr** root);
int main(void)
{
	/*root must have '='*/
	expr* root = NULL;
	/*ln means left node, should be relative with y or y', without x*/
	expr* ln = NULL;
	/*rn means right node, should be relative with x and constant number, without y*/
	expr* rn = NULL;
	/*buf has the equation, f.e. y'=-2xy*/
	char buf[64] = "y'=-2xy";
	/*eq_idx means equal index, This indicates where '=' is.*/
	int eq_idx;

	/*set eq_idx*/
	eq_idx = find_equal_idx(buf);

	/*set initial tree. root get value '='*/
	init_expr_node(&root,&ln,&rn);
	set_ln_node(&ln, buf, eq_idx);
	set_rn_node(&rn, buf, eq_idx);
	printf("root : %s\n",root->eq);
	printf("left : %s\n",root->left->eq);
	printf("right : %s\n",root->right->eq);
	
	ins_expr_node(&ln);
	print_tree(&root);
	printf("test : %s\n",root->left->left->eq);
}
expr* get_expr_node(void)
{
	expr* tmp;
	tmp = (expr*)malloc(sizeof(expr)*1);
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}
void ins_expr_node(expr** root)
{
	char buf[32];
	char tmp_buf[32];
	char tmp;
	int i = 0;
	stack* top = NULL;
	while((*root)->eq[i])
	{
		tmp = (*root)->eq[i];
		/*tmp is number(0~9) or 'x' or 'y'*/
		if( tmp=='x' || tmp == 'y' || ((48 <=tmp) &&(tmp <= 57)) ) 
			push(&top, &tmp);
		else
		{ 
			sprintf(tmp_buf,"%c",tmp);
			strcat(buf, tmp_buf);
			ins_tree(root,tmp_buf);
		}
		i++;
	}
	while(is_not_empty(&top))
	{
		pop(&top, buf);
		ins_tree(root,buf);
	}
}
/*find where '=' is*/
int find_equal_idx(char* buf)
{
	int i;
	for(i=0;buf[i];i++)
		if(buf[i] == '=')
			break;
	return i;
}
void init_expr_node(expr** root, expr** ln, expr** rn)
{
	*root = get_expr_node();
	*ln   = get_expr_node();
	*rn	  = get_expr_node();

	(*root)->left  = *ln;
	(*root)->right = *rn;
	
	strcat((*root)->eq,"=");
}
void set_ln_node(expr** ln, char* buf, int eq_idx)
{
	strncpy((*ln)->eq, buf, eq_idx);
}
void set_rn_node(expr** rn, char* buf, int eq_idx)
{
	strncpy((*rn)->eq, buf + eq_idx + 1, strlen(buf) - eq_idx - 1);
}
stack* get_stack_node(void)
{
	stack* tmp;
	tmp = (stack*)malloc(sizeof(stack)*1);
	tmp->node = NULL;
	return tmp;
}
void push(stack** top, char* buf)
{
	stack* tmp = *top;
	*top = get_stack_node();
	strcat((*top)->eq, buf);
	(*top)->node = tmp;
}
void pop(stack** top,char* buf)
{
	if(!(*top)->eq)
	{
		strcat(buf,"");
		return;
	}
	stack* tmp = *top;
	strcpy(buf, (*top)->eq);
	*top = (*top)->node;
	free(tmp);
}
bool is_not_empty(stack** top)
{
	if(*top)
		return true;
	return false;
}
void ins_tree(expr** root, char* buf)
{
	expr* tmp = *root;
	while(tmp)
	{
		if(!tmp->left)
			tmp = tmp->left;
		else if(!tmp->right)
			tmp = tmp->right;
		else
			tmp = tmp->left;
	}
	tmp = get_expr_node();
	strcpy(tmp->eq, buf);
}
void print_tree(expr** root)
{
	expr* tmp = *root;
	if(tmp)
	{
		printf("value : %s\n",tmp->eq);
		print_tree(&tmp->left);
		print_tree(&tmp->right);
	}
	return;
}
