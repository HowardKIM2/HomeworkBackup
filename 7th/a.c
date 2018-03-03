#include <stdio.h>


//float(*)(int,int) (*)(float)(*)(int,int) test (void(*)(void)
float avrg(int x,int y){
	printf("avrg!!(4th)\n");
	return (x+y)/2;
}
// return float(*)(int,int)
// parameter float(*)(int,int)
// name edit_avrg
float (*edit_avrg(float(*p)(int,int)))(int,int){
	printf("edit_avrg!!(3rd)\n");
	return avrg;
}
void test_print(void){
	printf("test_print!!(1st)\n");
}

float (*(*test(void(*p)(void)))(float(*)(int,int)))(int,int){
	p();
	printf("test!!(2nd)\n");
	
	return edit_avrg;
}

int main(void){
	float num;
	num = test(test_print)(avrg)(3,6);
	//float (*(*test(void(*p)(void)))(float(*)(int,int)))(int,int)
	printf("num = %.2f\n",num);
	return 0;
}
