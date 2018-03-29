#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
void *task1(void *X){
	while(1){
		sleep(1);
		printf("Thread A complete\n");
	}
}

void *task2(void* x){
	while(1){
		printf("Thread B complete\n");
		sleep(1);
	}
}

int main(void){
	pthread_t ThreadA,ThreadB;

	pthread_create(&ThreadA, NULL, task1 ,NULL);
	pthread_create(&ThreadB, NULL, task2 ,NULL);

	pthread_join(ThreadA,NULL);
	pthread_join(ThreadB,NULL);
}
