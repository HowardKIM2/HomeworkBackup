#include <stdio.h>
void func(int (*arr)[3]);
void sapply(int (*arr)[3],void(*p)(int (*array)[3]));
void print_mat(int (*mat)[3]);
int main(void){
	int arr[2][3] = {{2,4,6},{2,4,6}};
	printf("before : \n");
	print_mat(arr);
	sapply(arr,func);
	printf("after : \n");
	print_mat(arr);
}
void print_mat(int (*mat)[3]){
	int i = 0, j = 0;
	for(i = 0;i < 2;i++){
		for(j=0;j<3;j++){
			printf("%4d",mat[i][j]);
		}
		printf("\n");
	}

}
void func(int (*arr)[3]){
	int j;
	for(j=0;j<3;j++){
		arr[1][j] = arr[1][j] * arr[1][j];
	}
}


void sapply(int (*arr)[3],void(*p)(int (*array)[3])){
	p(arr);
}
