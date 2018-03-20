#include <stdio.h>
void add_int_mat(int (*mat1)[3],int (*mat2)[3],int (*res)[3]);
void add_float_mat(int (*mat_f1)[3],int (*mat_f2)[3],int (*res_f)[3]);
void print_mat(int (*mat)[3]);
int main(void){
	//int type 3 by 3 matrix
	int mat1[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	int mat2[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	int res[3][3];
	//float type 3 by 3 matrix
	float mat_f1[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	float mat_f2[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	float res_f[3][3];
	add_int_mat(mat1,mat2,res);
	
	
	return 0;
}
void add_int_mat(int (*mat1)[3],int (*mat2)[3],int (*res)[3]){
	int i = 0, j = 0, k = 0;
	for(i = 0;i < 3;i++){
		for(j = 0;j < 3;j++){
			res[i][j] = 0;
			for(k = 0;k < 3;k++){
				res[i][j] += mat1[i][k] + mat2[k][j];
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
