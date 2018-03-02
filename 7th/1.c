/*
	Function pointer test

*/


#include <stdio.h>
void aaa(void){
	printf("aaa called\n");
}
int number(void){
	printf("number called\n");
	return 7;
}

// factor : void
// return : void * void
// name   : bbb
// void (*bbb(void))(void)
void (*bbb(void))(void){
	printf("bbb called\n");
	return aaa;
}

// factor : void(*)(void)
// return : void
// name   : ccc
void ccc(void(*p)(void)){
	printf("ccc : I can call aaa!\n");
	p();
}

// factor : void
// return : int(*) void
// name   :  ddd
int (*ddd(void))(void){
	printf("ddd : I can call number\n");
	return number;
}
int main(void){
	int num;

	bbb()();
	ccc(aaa);
	num = ddd()();
	printf("num = %d\n",num);
	return 0;
}
