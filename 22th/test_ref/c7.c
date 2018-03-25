#include <stdio.h>
void multiple(int (*mat1)[3],int (*mat2)[3],int (*res)[3]);
void print_mat(int (*mat)[3]);
int main(void){
	int mat1[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	int mat2[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	int res[3][3];
	multiple(mat1,mat2,res);
	print_mat(mat1);
	printf("\n\n");
	print_mat(mat2);
	printf("\n\n");
	print_mat(res);
	return 0;
}
void multiple(int (*mat1)[3],int (*mat2)[3],int (*res)[3]){
	int i = 0, j = 0, k = 0;
	for(i = 0;i < 3;i++){
		for(j = 0;j < 3;j++){
			res[i][j] = 0;
			for(k = 0;k < 3;k++){
				res[i][j] += mat1[i][k]* mat2[k][j];
			}
		}
	}
}
void print_mat(int (*mat)[3]){
	int i = 0, j = 0;
	for(i = 0;i < 3; i++){
		for(j = 0;j < 3; j++){
			printf("%4d",mat[i][j]);
		}
		printf("\n");
	}
}
