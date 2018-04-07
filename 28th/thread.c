#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* test_thread1(void* data);
void* test_thread2(void* data);
int global;

pthread_mutex_t mtx;

int main(void){
	pthread_t p_thread[2];
	int data = 2;
	int status;
	global = 2;
	
	pthread_mutex_init(&mtx, NULL);
	
	pthread_create(&p_thread[0], NULL, test_thread1, (void*)&data);

	pthread_join(p_thread[0],(void*)&status);
	
	pthread_create(&p_thread[1], NULL, test_thread2, (void*)&data);
	pthread_join(p_thread[1],(void*)&status);

	return 0;
}
void* test_thread1(void* data){
	int i;
	for(;;){
		pthread_mutex_lock(&mtx);
		for(i=0;i<5;i++){
			usleep(1000);
			printf("1 : %d\n", i + 1);
		}
		sleep(1);
		pthread_mutex_unlock(&mtx);
	}
	return NULL;
}
void* test_thread2(void* data){
	int i;
	for(;;){
		pthread_mutex_lock(&mtx);
		for(i=0;i<5;i++){
			usleep(1000);
			printf("2 : %d\n", i + 1);
		}
		sleep(1);
		pthread_mutex_unlock(&mtx);
	}
	return NULL;
}
