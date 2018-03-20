#include <stdio.h>
//parameter : void
//name : fp_1
//return : void
void fp_1(void){
	printf("fp_1 called!\n");
}


//parameter : void(*)(void)
//name : fp_2
//return : void
void fp_2(void (*p)(void)){

	printf("fp_2 called!\n");
	p();
}


//parameter : int, int
//name : fp_main
//return : void (*)(void(*)(void))
void (*fp_main(int x,int y))(void(*)(void)){
	
	printf("fp_main called!\n");
	return fp_2;
}

int main(void){
	fp_main(1,2)(fp_1);
}

