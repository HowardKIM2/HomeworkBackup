#include <stdio.h>
int fib(int num);
int main(void){
	int num = 27, i = 1;
	int val, odd_sum = 0,even_sum = 0;
	while(i<=num){
		val = fib(i);
		if(val % 2)
			odd_sum += val;
		else
			even_sum += val;
		i++;
	}
	printf("odd_sum : %d\n",odd_sum);
	printf("even_sum : %d\n",even_sum);
	printf("odd_sum - even_sum = %d\n",odd_sum-even_sum);
	return 0;
}
int fib(int num){
	int num1 = 1,num2 = 1;
	int res = 0;
	int n = 2;
	if(num == 1 || num == 2)
		return 1;
	while(n!=num){
		res = num1 + num2;
		num1 = num2;
		num2 = res;
		n++;
	}
	return res;
}	
