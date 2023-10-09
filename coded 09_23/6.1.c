/*
Write a menu driven program to create a stack using array and perform the following operation using function
a. Push
b. Pop
c. check stack is empty or not
d. check stack is full or not
e. display stack elements
*/
#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int *arr;
    int size;
    int top;
};

void push(struct Stack *s)
{

    if (s->top == s->size - 1)
    {
        printf("Stack overflow!\n");
        return;
    }
    int item;
    printf("Enter element to be pushed into the stack: ");
    scanf("%d", &item);
    s->top++;
    s->arr[s->top] = item;
}

int pop(struct Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack underflow!\n");
        return -1;
    }
    int item = s->arr[s->top];
    s->top--;

    return item;
}

int is_empty(struct Stack *s)
{
    return s->top == -1;
}

int is_full(struct Stack *s)
{
    return s->top == s->size - 1;
}

void display_stack(struct Stack *s)
{
    if (is_empty(s))
    {
        printf("Stack is empty!\n");
        return;
    }

    printf("Stack: ");
    for (int i = s->top; i >= 0; i--)
    {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}
void menu(struct Stack s)
{
    int choice, item;
    printf("\nEnter option: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        push(&s);
        menu(s);
        break;

    case 2:
        item = pop(&s);
        if (item != -1)
        {
            printf("%d deleted from Stack\n", item);
        }
        menu(s);
        break;

    case 3:
        if (is_empty(&s))
        {
            printf("Stack empty: True\n");
        }
        else
        {
            printf("Stack empty: False\n");
        }
        menu(s);
        break;

    case 4:
        if (is_full(&s))
        {
            printf("Stack is full!\n");
        }
        else
        {
            printf("Stack is not full!\n");
        }
        menu(s);
        break;

    case 5:
        display_stack(&s);
        menu(s);
        break;

    case 6:
        exit(0);
        break;

    default:
        printf("Invalid choice!\n");
    }
}
int main()
{
    struct Stack s;
    printf("Enter size of stack: ");
    scanf("%d", &s.size);
    s.arr = (int *)malloc(s.size * sizeof(int));
    s.top = -1;

    printf("1. Push\n2. Pop\n3. Check if empty\n4. Check if full\n5. Display stack\n6. EXIT\n");
    menu(s);

    return 0;
}
