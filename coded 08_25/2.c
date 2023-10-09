/*Write a program to perform the following operations on a given square matrix using functions:
i. Find the no. of nonzero elements
ii. Display the elements of just above and below the main diagonal*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void zeros(int **arr, int n)
{
    int count = 0;
    for (int i = 0; i < n * n; i++)
    {
        if (arr[i] == 0)
        {
            count++;
        }
    }
    printf("\ncount: %d", count);
}
void upper_triagular(int **arr, int n)
{
    printf("\nUpper elements: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (i < j)
            {
                printf("%d ", arr[i][j]);
            }
        }
    }
}
void lower_triagular(int **arr, int n)
{
    printf("\n\nlower elements:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > j)
            {
                printf("%d ", arr[i][j]);
            }
        }
    }
}

void menu(int **arr, int n)
{
    int option;
    printf("\nEnter option: ");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        zeros(arr, n);
        break;
    case 2:
        upper_triagular(arr, n);
        lower_triagular(arr, n);
        break;
    case 3:
        printf("Exit Menu");
        exit(EXIT_SUCCESS);
    default:
        printf("Invalid Option");
        break;
    }
}

int main()
{
    int n;
    printf("Enter size of the square matrix: ");
    scanf("%d", &n);

    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter elements of the matrix: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("***MENU***\n");
    printf("i. Find the no. of nonzero elements\nii. Display the elements of just above and below the main diagonal\niii. Exit \n");
    menu(arr, n);
    for (int i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);
    return 0;
}