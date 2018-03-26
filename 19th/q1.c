#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
bool chk_dup(int* num,int val){
	int i;
	for(i=0;num[i];i++){
		if(num[i] == val)
			return false;
	}
	return true;
}
typedef struct __queue{
	int data;
	struct __queue* link;
}queue;
queue* get_node(void){
	queue* tmp;
	tmp = (queue*)malloc(sizeof(queue)*1);
	tmp->link = NULL;
	return tmp;
}
void enqueue(queue** head,int data){
	queue** tmp = head;
	while(*tmp)
		tmp = &(*tmp)->link;
	*tmp = get_node();
	(*tmp)->data = data;
	printf("enqueue : %d\n",(*tmp)->data);
}
void print_queue(queue** haed){
	queue* tmp = *haed;
	while(tmp){
		printf("data : %d\n",tmp->data);
		tmp = tmp->link;
	}


}
int dequeue(queue** head){
	queue* tmp = *head;
	int data;
	if(!tmp){
		printf("NO DATA in queue!!\n");
		return 0;
	}
	data = tmp->data;
	(*head) = (*head)->link;
	free(tmp);
	return data;
}
int even_sum(queue** head){
	queue* tmp = *head;
	int num, sum = 0;
	while(tmp){
		num = dequeue(&tmp);
		if(!(num%2))
			sum += num;
	}
	return sum;
}

int main(int argc, char* argv[]){
	srand(time(NULL));
	int num[10] = {0,};
	int i, tmp, ret, sum, size;
	int fd;
	char buf[1024];
	queue* head = NULL;
	size = sizeof(num)/sizeof(int) - 1;
	for(i = 0;i<sizeof(num)/sizeof(int) -1 ; ){
		tmp = rand()%9+1;
		if(chk_dup(num,tmp)){
			num[i++] = tmp;
			enqueue(&head,tmp);
		}
		ret = i;
	}
	i=0;

	fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	print_queue(&head);
	sum = even_sum(&head);
	sprintf(buf, "%d %d %d %d %d %d %d %d %d\neven sum : %d",num[0],num[1],num[2],num[3],num[4],num[5],num[6],num[7],num[8],sum);
	
	i = 0;
	while(buf[i++])
		ret = i;
	
	write(fd,buf,ret);
	write(fd,buf,ret);

}
