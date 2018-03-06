#include <stdio.h>
int oddSum(int start,int end);
int main(void){
	int start = 0, end = 100;
	int sum;

	sum = oddSum(start,end);
	
	printf("sum = %d\n",sum);
	return 0;
}
int oddSum(int start,int end){
	int i, sum = 0;

	for(i=start;i<=end;i++){
		if(i%2)
			sum+=i;
	}
	return sum;
}	
