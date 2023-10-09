/*
Write a menu driven program to create a linear queue using array
and perform Enqueue, Dequeue, Traverse, IsEmpty, IsFull operations.
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Queue
{
    int *queue;
    int front;
    int rear;
    int max_size;
} Queue;

Queue *create_queue(int size)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->queue = (int *)malloc(sizeof(int) * size);
    queue->front = -1;
    queue->rear = -1;
    queue->max_size = size;
    return queue;
}

int is_empty(Queue *queue)
{
    return queue->front == -1;
}

int is_full(Queue *queue)
{
    return queue->rear == queue->max_size - 1;
}

void enqueue(Queue *queue)
{
    if (is_full(queue))
    {
        printf("Cannot enqueue, already full!\n");
    }
    else
    {
        if (queue->rear == -1)
        {
            queue->front++;
            queue->rear++;
        }
        else
        {
            queue->rear++;
        }
        int element;
        printf("Enter element: ");
        scanf("%d", &element);
        queue->queue[queue->rear] = element;
    }
}

int dequeue(Queue *queue)
{
    if (is_empty(queue))
    {
        printf("Queue is already empty\n");
        return -1;
    }
    else
    {
        int element = queue->queue[queue->front];
        if (queue->front == queue->rear)
        {
            queue->front = -1;
            queue->rear = -1;
        }
        else
        {
            queue->front++;
        }

        return element;
    }
}

void traverse(Queue *queue)
{
    if (is_empty(queue))
    {
        printf("Nothing to display\n");
        return;
    }
    printf("\n----Queue----\n");
    for (int i = queue->front; i <= queue->rear; i++)
    {
        printf("-> %d ", queue->queue[i]);
    }

    printf("\n");
}

void destroy_queue(Queue *queue)
{
    free(queue->queue);
    free(queue);
}

int main()
{
    int size;
    printf("Enter the size of Queue: \n");
    scanf("%d", &size);
    if (size <= 0)
    {
        printf("Invalid size\n");
        exit(0);
    }

    Queue *queue = create_queue(size);

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
            dequeued_element = dequeue(queue);
            if (dequeued_element != -1)
            {
                printf("Dequeued element: %d\n", dequeued_element);
            }
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
            traverse(queue);
            break;
        case 6:
            destroy_queue(queue);
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
    }

    destroy_queue(queue);
    return 0;
}