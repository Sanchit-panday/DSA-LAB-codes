#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1016

char STACK_rachit[MAX_SIZE];
int TOP_rachit = -1;
int LENGTH = 6;

void push(char data)
{
    if (TOP_rachit < LENGTH - 1)
    {
        TOP_rachit++;
        STACK_rachit[TOP_rachit] = data;
    }
    else
    {
        printf("Stack Overflow\n");
    }
}

char pop()
{
    if (TOP_rachit >= 0)
    {
        char item = STACK_rachit[TOP_rachit];
        TOP_rachit--;
        return item;
    }
    else
    {
        printf("Stack Underflow\n");
        return '\0';
    }
}

void display()
{
    if (TOP_rachit >= 0)
    {
        printf("Stack content:\n");
        for (int i = TOP_rachit; i >= 0; i--)
        {
            printf("%c\n", STACK_rachit[i]);
        }
    }
    else
    {
        printf("Stack is empty\n");
    }
}
char *byte_to_binary(char x)
{
    static char b[9];
    b[0] = '\0';
    for (int z = 128; z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }
    return b;
}

void convert_to_binary()
{
    if (TOP_rachit >= 0)
    {
        printf("Binary stack:\n");
        for (int i = TOP_rachit; i >= 0; i--)
        {
            printf("%s\n", byte_to_binary(STACK_rachit[i]));
        }
    }
    else
    {
        printf("Stack is empty\n");
    }
}

int main()
{
    char choice, data;

    printf("\nMenu:\n");
    printf("a. PUSH\n");
    printf("b. Pop\n");
    printf("c. Display\n");
    printf("d. Convert binary stack\n");
    printf("e. Quit\n");

    while (1)
    {

        scanf(" %c", &choice);

        switch (choice)
        {
        case 'a':
            printf("Enter data to push: ");
            scanf(" %c", &data);
            push(data);
            break;
        case 'b':
            data = pop();
            if (data != '\0')
            {
                printf("Popped item: %c\n", data);
            }
            break;
        case 'c':
            display();
            break;
        case 'd':
            convert_to_binary();
            break;
        case 'e':
            exit(0);
        default:

            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}