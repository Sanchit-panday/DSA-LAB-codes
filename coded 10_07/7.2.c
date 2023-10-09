/*
Write a menu driven program to implement circular queue operations such 
as Enqueue, Dequeue, Traverse, IsEmpty, IsFull using array.
*/
#include <stdio.h>
#include <stdlib.h>
static int MAX_SIZE;
typedef struct queue
{
	int *arr;
	int front;
	int rear;
} Queue;
int is_full(Queue *queue)
{
	return (queue->rear + 1) % MAX_SIZE == queue->front;
}

int is_empty(Queue *queue)
{
	return queue->front == -1 && queue->rear == -1;
}
void enqueue(Queue *queue)
{
	if (is_full(queue))
	{
		printf("Cannot enqueue, already full!\n");
		return;
	}
	int element;
	printf("Enter element: ");
	scanf("%d", &element);
	if (queue->front == -1 && queue->rear == -1)
	{
		queue->front = queue->rear = 0;
	}
	else
	{
		queue->rear = (queue->rear + 1) % MAX_SIZE;
	}
	queue->arr[queue->rear] = element;
}
void dequeue(Queue *queue)
{
	if (queue->front == -1 && queue->rear == -1)
	{
		printf("Queue is already empty\n");
		return;
	}
	else if (queue->front == queue->rear)
	{
		queue->front = queue->rear = -1;
	}
	else
	{
		queue->front = (queue->front + 1) % MAX_SIZE;
	}
	printf("Element deleted\n");
}
void Print(Queue *queue)
{
	printf("\n----Queue----\n");
	if (is_empty(queue))
	{
		printf("Nothing to display\n");
		return;
	}
	int count = ((queue->rear + MAX_SIZE - queue->front) % MAX_SIZE) + 1;
	int i;
	for (i = 0; i < count; i++)
	{
		printf("-> %d ", queue->arr[(queue->front + i) % MAX_SIZE]);
	}
	printf("\n");
}
void destroy_queue(Queue *queue)
{
	if (is_empty(queue))
	{
		return;
	}
	free(queue->arr);
	free(queue);
}
int main()
{
	printf("Enter size of queue: ");
	scanf("%d", &MAX_SIZE);
	Queue *queue = (Queue *)malloc(sizeof(Queue));
	queue->arr = (int *)malloc(sizeof(int) * MAX_SIZE);
	queue->front = -1;
	queue->rear = -1;

	printf("***Main Menu***\n");
	printf("1. Enqueue\n");
	printf("2. Dequeue\n");
	printf("3. IsEmpty\n");
	printf("4. IsFull\n");
	printf("5. Traverse\n");
	printf("6. Exit\n");

	int choice;
	while (1)
	{
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		int dequeued_element;
		switch (choice)
		{
		case 1:
			enqueue(queue);
			break;
		case 2:
			dequeue(queue);
			break;
		case 3:
			printf("Queue Empty: ");
			is_empty(queue) ? printf("True\n") : printf("False\n");
			break;
		case 4:
			printf("Queue Full: ");
			is_full(queue) ? printf("True\n") : printf("False\n");
			break;
		case 5:
			Print(queue);
			break;
		case 6:
			destroy_queue(queue);
			exit(0);
		default:
			printf("Invalid choice\n");
			break;
		}
	}
	return 0;
}
