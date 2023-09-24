/*5.2 Write a program to create a circular double linked list and perform the following menu based operations on it:
i. insert an element at specific position
ii. delete an element from specific position
iii. Traverse the list*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

void insert(int data, int pos)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (head == NULL)
    {
        head = new_node;
        new_node->next = new_node;
        new_node->prev = new_node;
        return;
    }

    if (pos == 1)
    {
        new_node->next = head;
        new_node->prev = head->prev;
        head->prev = new_node;
        new_node->prev->next = new_node;
        head = new_node;
        return;
    }

    struct node *temp = head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }

    new_node->next = temp->next;
    new_node->prev = temp;
    temp->next->prev = new_node;
    temp->next = new_node;
}

void del(int pos)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (pos == 1)
    {
        if (head->next == head)
        {
            free(head);
            head = NULL;
        }
        else
        {
            struct node *to_delete = head;
            head = head->next;
            head->prev = to_delete->prev;
            to_delete->prev->next = head;
            free(to_delete);
        }
        return;
    }

    struct node *temp = head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }

    struct node *to_delete = temp->next;
    temp->next = to_delete->next;
    to_delete->next->prev = temp;
    free(to_delete);
}

void traverse()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main()
{
    int choice, data, pos;
    printf("1. Insert\n2. Delete\n3. Traverse\n4. Exit\n");
    while (1)
    {

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            printf("Enter position to insert: ");
            scanf("%d", &pos);
            insert(data, pos);
            break;
        case 2:
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            del(pos);
            break;
        case 3:
            traverse();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}
