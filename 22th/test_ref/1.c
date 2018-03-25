#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void init_rand_arr(int* arr,int size);
void print_arr(int* arr,int size);
int main(void){
	srand(time(NULL));
	int arr[100];
	
	init_rand_arr(arr,sizeof(arr)/sizeof(int));
	print_arr(arr,sizeof(arr)/sizeof(int));
}
void init_rand_arr(int* arr,int size){
	int i;
	for(i=0;i<size;i++){
		arr[i] = rand()%4096 + 1;
	}
}

void print_arr(int* arr,int size){
	int i;
	for(i=0;i<size;i++)
		printf("%d\n",arr[i]);
}
