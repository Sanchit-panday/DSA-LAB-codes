/*
Write a menu driven program to create a stack using linked list and perform the following operation using function
a. Push
b. Pop
c. IsEmpty
d. display the stack elements
*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Stack
{
    struct Node *head;
};

void push(struct Stack *s, int item)
{
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->data = item;
    new_node->next = s->head;
    s->head = new_node;
}

int pop(struct Stack *s)
{
    if (s->head == NULL)
    {
        printf("Stack is empty!\n");
        return -1;
    }

    int item = s->head->data;
    struct Node *temp = s->head;
    s->head = s->head->next;
    free(temp);
    return item;
}

int is_empty(struct Stack *s)
{
    return s->head == NULL;
}

void display_stack(struct Stack *s)
{
    if (is_empty(s))
    {
        printf("Stack is empty!\n");
        return;
    }

    struct Node *temp = s->head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    struct Stack s;
    s.head = NULL;

    int choice;
    int item;

    do
    {
        printf("1. Push\n2. Pop\n3. Check if stack is empty\n4. Display stack elements\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the item to push: ");
            scanf("%d", &item);
            push(&s, item);
            break;

        case 2:
            item = pop(&s);
            if (item != -1)
            {
                printf("The popped item is: %d\n", item);
            }
            break;

        case 3:
            if (is_empty(&s))
            {
                printf("Stack is empty!\n");
            }
            else
            {
                printf("Stack is not empty!\n");
            }
            break;

        case 4:
            display_stack(&s);
            break;

        case 5:
            exit(0);
            break;

        default:
            printf("Invalid choice!\nExit Program");
        }
    } while (choice != 5);

    return 0;
}
