#include <stdio.h>
#include <stdlib.h>

typedef struct _adv_queue{
	int data[0];
}queue;

int main(void){
	queue* head = (queue*)malloc(4096);
	head->data[0] = 10;
	head->data[1] = 20;
	printf("%d\n",head->data[0]);
	printf("%d\n",head->data[1]);
	return 0;
}
