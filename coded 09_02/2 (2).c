#include <stdio.h>
#include <stdlib.h>

/*
4.1 Write a program to create a single linked list of n nodes and perform the following menu
based operations on it using function:
i. Insert a node at specific position
ii. Deletion of an element from specific position
iii. Count nodes
iv. Traverse the linked list
*/

struct Node
{
    int data;
    struct Node *next;
};

void InsertNodeAtPosition(struct Node *head)
{
    int pos, data;
    printf("Enter the position: ");
    scanf("%d", &pos);
    printf("Enter the data: ");
    scanf("%d", &data);
    struct Node *ptr;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    ptr = head;
    for (int i = 1; i < pos; i++)
    {
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("Position Not found.");
        return;
    }
    if (ptr->next == NULL)
    {
        ptr->next = newNode;
        newNode->next = NULL;
        return;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
}
void DeleteNodeFromPosition(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *prev = head;
    if (head == NULL)
        return;
    int pos;
    printf("Enter Position where u want deletion to occur: ");
    scanf("%d", &pos);
    for (int i = 1; i < pos; i++)
    {
        if (ptr == NULL || pos == 0)
        {
            return;
        }
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = ptr->next; // 2 3 4 5
    ptr->next = NULL;
}
void Traverse(struct Node *head)
{
    struct Node *ptr = head;
    printf("The Elements are: \n");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
int CountNode(struct Node *head)
{
    struct Node *ptr = head;
    int count = 0;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        count++;
    }
    return count;
}

int main()
{
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    struct Node *head = NULL;
    struct Node *ptr;
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        if (head == NULL)
        {
            head = newNode;
            ptr = head;
        }
        ptr->next = newNode;
        ptr = newNode;
    }
    struct Node *tail = ptr;
    tail->next = NULL;
    printf("MENU:\n1.Insert the node at a position\n2.Delete a node from specific position\n3.Count\n4.Traversal\n5.Exit\n");
    int counter = 1;
    char ch = '\0';
    while (counter)
    {
        printf("\nEnter choice: ");
        scanf(" %c", &ch);
        switch (ch)
        {
        case ('1'):
        {
            InsertNodeAtPosition(head);
            break;
        }
        case ('2'):
        {
            DeleteNodeFromPosition(head);
            break;
        }
        case ('3'):
        {
            printf("Number of Nodes present: %d", CountNode(head));
            break;
        }
        case ('4'):
        {
            Traverse(head);
            break;
        }
        case ('5'):
        {
            counter--;
            break;
        }
        default:
        {
            printf("Invalid Choice.\n");
            counter--;
            break;
        }
        }
    }
}