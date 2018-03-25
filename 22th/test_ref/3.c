#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void init_rand_arr(int* arr,int size);
void print_arr(int* arr,int* waste,int* space,int size);
void calc_waste_space(int* arr,int* waste,int* space,int size);
void alloc_space(int* arr,int* space,int size);
int sum_arr(int* arr,int size);
int main(void){
	srand(time(NULL));
	int arr[100];
	int waste[100];
	int space[100];
	int dissipation;
	int size = sizeof(arr)/sizeof(int);

	init_rand_arr(arr,size);
	alloc_space(arr,space,size);
	calc_waste_space(arr,waste,space,size);
	print_arr(arr,waste,space,size);

	dissipation = sum_arr(waste,size);
	printf("dissipation : %d\n",dissipation);
}
void init_rand_arr(int* arr,int size){
	int i;
	for(i=0;i<size;i++){
		arr[i] = rand()%131072 + 1;
	}
}

void print_arr(int* arr,int* waste,int* space,int size){
	int i;
	for(i=0;i<size;i++)
		printf("use : %-10dspace : %-10dwaste : %-10d\n",
				arr[i],space[i],waste[i]);
}
void calc_waste_space(int* arr,int* waste,int* space,int size){
	int i;
	for(i=0;i<size;i++)
		waste[i] = space[i] - arr[i];
}
int sum_arr(int* arr,int size){
	int sum = 0;
	int i;
	for(i=0;i<size;i++)
		sum += arr[i];
	return sum;
}
void alloc_space(int* arr,int* space,int size){
	int i = 0;
	int tmp = 4096;
	for(i = 0;i < size; i++){
		while(1){
			if(arr[i] < tmp){
				space[i] = tmp;
				tmp = 4096;
				break;
			}
			if(tmp == 131072){
				printf("memory overflow\n");
				exit(-1);
			}
			tmp = tmp <<1;
		}
	}
}
