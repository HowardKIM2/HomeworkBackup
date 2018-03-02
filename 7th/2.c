/*
	function pointer test
*/

#include <stdio.h>

void aaa(void){
	printf("aaa called\n");
}

//return : void(*)(void)
//factor : void(*p)(void)
//name   : bbb
void (*bbb(void(*p)(void)))(void){
	p();
	printf("bbb called\n");
	return aaa;
}


int main(void){
	bbb(aaa)();
	return 0;
}
//result : aaa called\n
//         bbb called\n
//         aaa called\n
