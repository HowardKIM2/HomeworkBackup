#include <stdio.h>
int sum(int start,int end,int chk);
int main(void){
	int start = 1, end = 100, i = 0;
	int res[4];
	int res2=0;
	for(i=0;i<sizeof(res)/sizeof(int);i++){
		res[i]=sum(start,end,i);
		res2+=res[i];
	}
	printf("res = %d\n",res2);
	
	


	return 0;
}


//chk , 0 : sum all, 1 : sum odd number, 2 : sum even number
//3 : sum multiples of 3
int sum(int start,int end,int chk){
	int sum = 0;
	int i;
	
	for(i = start; i<=end;i++){
		switch(chk){
			case 0:
				sum+=i;
				break;
			case 1:
				if(i%2)
					sum+=i;
				break;
			case 2:
				if(!(i%2))
					sum+=i;
				break;
			case 3:
				if(!(i%3))
					sum+=i;
			default :
				break;
		}	
	}

	return sum;
}
