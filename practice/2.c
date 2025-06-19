// DeQueue
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *prev, *next;
};
struct Deque
{
    struct Node *front, *rear;
    int size;
};
int is_empty(struct Deque dq)
{
    return dq == NULL;
}
int is_full(struct Deque dq)
{
    return dq.rear->next == NULL && dq.front->prev == NULL;
}
void print(struct Deque dq)
{
    struct Node *temp = dq.front;
    while(!temp) {
        printf("%d", temp->data);
        temp = temp->next;
    }
}
void insert_f(struct Deque *dq, int element)
{
    if (is_empty(dq))
    {
        printf("Empty\n");

    }
    else
    {
        // single element at 0 pos
        if (dq->front->prev == NULL)
        {
            for (int i = (sizeof(dq->arr) / sizeof(int)) - 1; i >= 0; i++)
            {
                dq->arr[i] = dq->arr[i - 1];
            }
            dq->rear++;
            dq->front = element;
        }
        else
        {
            dq->front--;
            dq->arr[dq->front] = element;
        }
    }
}
void insert_r(int dq_type)
{
}
int main()
{
    struct Deque dq;
    dq.front = dq.rear = NULL;
    int size;
    size = 10;
    // I restricted [insertion from front not allowed]
    // O restricted [deletion from rear not allowed]

    insert_f(dq, 10);
    print(dq);
    return 0;
}