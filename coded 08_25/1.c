/* WAP to create a 1-D array of n elements and perform the following menu based operations using function.
a. insert a given element at specific position.
b. delete an element from a specific position of the array.
c. linear search to search an element
d. traversal of the array */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool insert_element(int *arr, int *n)
{
    printf("Element to insert: ");
    int element;
    scanf("%d",&element);
    printf("Enter position: ");
    int position;
    scanf("%d", &position);
    if (position >= 0 && position < *n)
    {
        for (int i = *n; i > position; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[position] = element;
        (*n)++;
        return true;
    }
    return false;
}
bool remove_element(int *arr, int *n)
{
    int position;
    printf("Enter position: ");
    scanf("%d", &position);
    if (position >= 0 && position < *n)
    {
        for (int i = position; i < *n; i++)
        {
            arr[i] = arr[i + 1];
        }
        (*n)--;
        return true;
    }
    return false;
}
void linear_search(int arr[], int n)
{
    int element, flag = 0;
    printf("Find the element: ");
    scanf("%d", &element);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == element)
        {
            printf("Found at %d \n", i);
            flag =1;
        }
    }
    if (flag<1) 
    {
        printf("NOT FOUND\n");
    }
    
}
void menu(int *arr, int n)
{
    int option;
    printf("\nEnter option: ");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        // insert(arr, n) ? cout << "Element inserted\n" : fprintf(stderr, "Invalid Position\n");
        insert_element(arr, &n) ? printf("Element inserted\n") : fprintf(stderr, "ERROR\n");
        menu(arr, n);
        break;
    case 2:
        remove_element(arr, &n) ? printf("Element deleted\n") : fprintf(stderr, "ERROR\n");
        menu(arr, n);
        break;
    case 3:
        linear_search(arr, n);
        menu(arr, n);
        break;
    case 4:
        printf("\n");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        menu(arr, n);
        break;
    case 5:
        exit(EXIT_SUCCESS);
        break;
    default:
        fprintf(stderr, "Invalid Option\n");
        menu(arr, n);
        break;
    }
}
int main()
{
    int n, *arr;
    printf("Enter size n : ");
    scanf("%d", &n);
    arr = (int*)malloc(n * sizeof(int));
    printf("Enter Array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("***MENU***\n");
    printf("1. Insert\n2. Delete\n3. Linear Search\n4. Traverse\n5. Exit\n");
    menu(arr, n);
    return 0;
}