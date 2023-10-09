/*
Write a program to create a double linked list and perform the following menu based operations on it:
i. insert an element at specific position
ii. delete an element from specific position
iii. Traverse the list
*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
  struct node *prev;
};

struct node *ui(int n)
{
  int i;
  struct node *head = NULL;
  struct node *temp = NULL;
  struct node *p = NULL;
  for (i = 0; i < n; i++)
  {
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter info of node %d:", i + 1);
    scanf("%d", &temp->data);
    temp->next = NULL;
    temp->prev = NULL;
    if (head == NULL)
    {
      head = temp;
    }
    else
    {
      p = head;
      while (p->next != NULL)
      {
        p = p->next;
      }
      p->next = temp;
      temp->prev = p;
    }
  }
  return head;
}

struct node *insert(struct node *head)
{
  int data, n;
  printf("Enter the position:");
  scanf("%d", &n);
  printf("Enter the Element to insert :");
  scanf("%d", &data);
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data;
  if (n == 1)
  {
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL)
    {
      head->prev = newNode;
    }
    return newNode;
  }

  struct node *current = head;
  int position = 1;

  while (current != NULL && position < n - 1)
  {
    current = current->next;
    position++;
  }

  if (current == NULL)
  {
    printf("Invalid position.\n");
    free(newNode);
    return head;
  }

  newNode->prev = current;
  newNode->next = current->next;

  if (current->next != NULL)
  {
    current->next->prev = newNode;
  }

  current->next = newNode;

  return head;
}

struct node *del(struct node *head)
{
  int position;
  printf("Enter the position:");
  scanf("%d", &position);
  if (position <= 0)
  {
    printf("Invalid position.\n");
    return head;
  }

  struct node *current = head;
  int currentPosition = 1;

  while (current != NULL && currentPosition < position)
  {
    current = current->next;
    currentPosition++;
  }

  if (current == NULL)
  {
    printf("Invalid position.\n");
    return head;
  }

  if (current == head)
  {
    head = current->next;
    if (head != NULL)
    {
      head->prev = NULL;
    }
    free(current);
    return head;
  }

  if (current->prev != NULL)
  {
    current->prev->next = current->next;
  }
  if (current->next != NULL)
  {
    current->next->prev = current->prev;
  }

  free(current);

  return head;
}

void travers(struct node *head)
{
  struct node *ptr = head;
  if (head == NULL)
  {
    printf("list is empty\n");
    return;
  }

  while (ptr != NULL)
  {
    printf("%4d", ptr->data);
    ptr = ptr->next;
  }
}

int main()
{
  int n, x = 0, op;
  printf("Enter the size of link list:");
  scanf("%d", &n);
  struct node *head = NULL;
  head = ui(n);
  printf("MENU:\n1. Insert the node at a position\n2. Delete a node from specific position\n3. Traversal\n4. Exit\n");
  while (x != 1)
  {
    printf("\nEnter the option:");

    scanf("%d", &op);

    if (op == 1)
    {
      head = insert(head);
    }
    else if (op == 2)
    {
      head = del(head);
    }
    else if (op == 3)
    {
      travers(head);
    }
    else if (op == 4)
    {
      x = 1;
    }
  }
  return 0;
}