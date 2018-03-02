/*
	function pointer3
*/
#include <stdio.h>

//return : int(*)[2]
//name   : aaa
//parameter : void
int (*aaa(void))[2]{
	static int a[2][2] = {10,20,30,40};
	printf("aaa called\n");
	return a;
}

//return : {int(*)[2]}(*)(void)
//name   : bbb
//factor : void
int (*(*bbb(void))(void))[2]{
	printf("bbb called\n");
	return aaa;
}

//return : {int(*)[2](void)}(*)(void)
//name   : ccc
//parameter : void
int (*(* ccc(void))(void))[2]{
	printf("ccc called\n");
	return aaa;
}
int (*(* ddd(void))(void))[2]{
	printf("ddd called\n");
	return aaa;
}
int (*(* eee(void))(void))[2]{
	printf("eee called\n");
	return aaa;
}

int main(void){
	//int[2](*) ret
	int (*ret)[2];

	//int (*(*(*(p[][2])(void))(void))[2]
	//int(*)[2](*)(void) (*(*(p[][2])(void))
	//{int(*)[2](*)(void)}(*)(void) p[][2]
	int (*(*(*p[][2])(void))(void))[2] = {{bbb,bbb},{bbb,bbb}};
	
	
	//int (*(*(*(*p1)[2])(void))(void))[2]
	//int(*)[2](void) (*(*(*p1)[2])(void))
	//{int[2](*)(void)}(*)(void) *(*p1)[2]
	//[{int[2](*)(void)}(*)(void)][2] *p1
	
	//int (*)[2] (*)(void) (*)(void) (*)[2]
	int (*(*(*(*p1)[2])(void))(void))[2] = p;
	
	//
	ret = ((*(*(*(*p1)[3])))()());

	printf("%d\n",*ret[0]);   //==p[0][0]
	
	return 0;
}
