#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void init_rand_arr(int* arr,int size);
void print_arr(int* arr,int* waste,int size);
void calc_waste_space(int* arr,int* waste,int size);
int sum_arr(int* arr,int size);
int main(void){
	srand(time(NULL));
	int arr[100];
	int waste[100];
	int dissipation;
	init_rand_arr(arr,sizeof(arr)/sizeof(int));
	calc_waste_space(arr,waste,sizeof(arr)/sizeof(int));
	print_arr(arr,waste,sizeof(arr)/sizeof(int));

	dissipation = sum_arr(waste,sizeof(waste)/sizeof(int));
	printf("dissipation : %d\n",dissipation);
}
void init_rand_arr(int* arr,int size){
	int i;
	for(i=0;i<size;i++){
		arr[i] = rand()%4096 + 1;
	}
}

void print_arr(int* arr,int* waste,int size){
	int i;
	for(i=0;i<size;i++)
		printf("use : %-10dwaste : %-10d\n",arr[i],waste[i]);
}
void calc_waste_space(int* arr,int* waste,int size){
	int space = 4096;
	int i;
	for(i=0;i<size;i++)
		waste[i] = 4096 - arr[i];
}
int sum_arr(int* arr,int size){
	int sum = 0;
	int i;
	for(i=0;i<size;i++)
		sum += arr[i];
	return sum;
}
