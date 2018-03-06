#include <stdio.h>

void func(int (*p)[3]){
	int j;
	for(int j=0;j<3;j++)
		p[1][j] = p[0][j] + p[1][j];
}

void sapply(int (*arr)[3],void (*p)(int(*)[3])){
	p(arr);
}

int main(void){
	int arr[2][3]={{1,2,3},{1,2,3}};
	int i, j;
	sapply(arr,func);

	for(i=0;i<2;i++){
		for(j=0;j<3;j++)
			printf("%d ",arr[i][j]);
		printf("\n");
	}
	return 0;
}
