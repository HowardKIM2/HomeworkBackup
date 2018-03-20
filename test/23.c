#include <stdio.h>
int fib(int num);
int main(void){
	int num = 23, i = 1;
	int val;
	while(i<=num){
		val = fib(i);
		i++;
	}
	printf("%d번째 : %d\n",i-1,val);
	return 0;
}
int fib(int num){
	int num1 = 1,num2 = 4, num3 = 5;
	int res = 0;
	int n = 2;
	if(num == 1)
		return 1;
	else if(num == 2)
		return 4;
	while(n!=num){
		res = num1 + num2;
		num1 = num2;
		num2 = res;
		n++;
	}
	return res;
}	
