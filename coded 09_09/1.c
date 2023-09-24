/*
WAP Perform following operations using function on the single linked list:
i. search an element in the list
ii. sort the list in ascending order
iii. reverse the list
*/
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void printList(struct Node *n)
{
    while (n != NULL)
    {
        printf("%d -> ", n->data);
        n = n->next;
    }
    printf("\n");
}
void search(struct Node *head, int item)
{
    if (head == NULL)
    {
        printf("Linked list is empty\n");
        return ;
    }
    struct Node *ptr = head;
    int i = 1;
    do
    {
        if (item == ptr->data)
        {
            printf("Position %d", i);
            return;
        }
        ptr = ptr->next;
        i++;
    } while (ptr != NULL);
    printf("data not found");
    return ;
}
// sorting starts from here
struct Node *swap(struct Node *ptr1, struct Node *ptr2)
{
    struct Node *tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}
int bubbleSort(struct Node **head, int count)
{
    struct Node **h;
    int i, j, swapped;

    for (i = 0; i <= count; i++)
    {

        h = head;
        swapped = 0;

        for (j = 0; j < count - i - 1; j++)
        {

            struct Node *p1 = *h;
            struct Node *p2 = p1->next;

            if (p1->data > p2->data)
            {

                /* update the link after swapping */
                *h = swap(p1, p2);
                swapped = 1;
            }

            h = &(*h)->next;
        }

        /* break if the loop ended without any swap */
        if (swapped == 0)
            break;
    }
}
// sorting ends here
static void reverse(struct Node** head_ref)
{
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next = NULL;
    while (current != NULL) {
        // Store next
        next = current->next;
 
        // Reverse current node's pointer
        current->next = prev;
 
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
void menu(struct Node *head, int n)
{
    printf("MENU\n");
    printf("1.Search an element in the list.\n");
    printf("2.Sort the list in ascendin order.\n");
    printf("3. Reverse the list.\n");
    printf("\nEnter the choice-> ");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Enter element to be searched :");
        int item;
        scanf("%d", &item);
        search(head, item);
        break;
    case 2:
        printf("Sorted list is: ");
        bubbleSort(&head, n);
        printList(head);
        break;
    case 3:
        printf("Reversed list is: ");
        reverse(&head);
        printList(head);
        break;
    }
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
    menu(head, n);
}