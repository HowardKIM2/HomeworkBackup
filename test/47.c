#include <stdio.h>
#include <stdlib.h>

typedef struct __queue
{
	char* data;
	struct __queue *link;
} queue;

queue *get_node(void)
{
	queue *tmp;
	tmp = (queue *)malloc(sizeof(queue));
	tmp->link = NULL;
	return tmp;
}

void enqueue(queue **head, char* data)
{
	if(*head == NULL)
	{
		*head = get_node();
		(*head)->data = data;
		return;
	}

	enqueue(&(*head)->link, data);
}

void print_queue(queue *head)
{
	queue *tmp = head;

	while(head)
	{
		printf("head->data = %s\n", head->data);
		head = head->link;
	}
}
int main(void)
{
	queue *head = NULL;

	enqueue(&head, "aaa");
	enqueue(&head, "bbb");

	print_queue(head);

	return 0;
}






























