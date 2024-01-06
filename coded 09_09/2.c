/*
Insert and delete at any given position in a circular linked list.
After any operation traverse the list to show the elements.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void display(struct Node *head)
{
    // empty list
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    int i = 1;
    struct Node *temp = head;
    do
    {
        printf("| Node %d | Data %d |\n", i++, temp->data);
        temp = temp->next;
    } while (temp != head);
}
struct Node *insertAtAnyPosition(struct Node *head)
{
    int data, position;
    printf("Enter data : ");
    scanf("%d", &data);
    printf("Enter position: ");
    scanf("%d", &position);
    struct Node *newNode = createNode(data);

    if (head == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }
    struct Node *current = head;
    for (int i = 1; i < position - 1; i++)
    {
        if (current->next == head)
        {
            printf("Invalid pos\n");
            return head;
        }
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;

    return head;
}
int countNodes(struct Node *head)
{
    struct Node *temp = head;
    int result = 0;
    if (head != NULL)
    {
        do
        {
            temp = temp->next;
            result++;
        } while (temp != head);
    }

    return result;
}

struct Node *delPos (struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty. Deletion is not possible.\n");
        return head;
    }

    int position;
    printf("Enter index: ");
    scanf("%d", &position);

    if (position == 0)
    {
        printf("cannot delete head node\n");
        return head->next;
    }

    struct Node *prev = head;
    for (int i = 0; i < position - 1; i++)
    {
        if (prev == NULL)
        {
            return head;
        }
        prev = prev->next;
    }

    if (position > countNodes(head)-1 || position < 0)
    {
        printf("Invalid position\n");
        return head->next;
    }
    
    struct Node *current = prev->next;
    prev->next = current->next;

    free(current);
    return head;
}

void menu(struct Node *head)
{
    printf("\nEnter the choice-> ");
    int choice;
    scanf("%d", &choice);
    int data, position;
    switch (choice)
    {
    case 1:
        head = insertAtAnyPosition(head);
        display(head);
        menu(head);
        break;
    case 2:
        head = delPos(head);
        display(head);
        menu(head);
        break;
    case 3:
        exit(0);
    default:
        printf("Invalid choice\n");
    }
}
int main()
{
    struct Node *head = NULL;
    int choice, data, position;
    printf("\nMENU(Circular Linked List)\n");
    printf("1. Insert at any given position.\n");
    printf("2. Delete at any given position.\n");
    printf("3. Exit\n");
    menu(head);

    return 0;
}