// WAP to represent a given sparse matrix in 3-tuple format using 2-D array.
#include <stdio.h>
#include <stdlib.h>
void sparse_format(int **arr, int row, int cols)
{
    printf("sparse matrix in 3-tuple format\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] != 0)
            {
                printf("%d %d %d", i, j, arr[i][j]);
            }
        }
        printf("\n");
    }
}
int main()
{
    int row, cols;
    printf("Enter size of the sparse matrix: ");
    scanf("%d", &row);
    scanf("%d", &cols);

    int **arr = (int **)malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++)
    {
        arr[i] = (int *)malloc(cols * sizeof(int));
    }

    printf("Enter elements of the matrix: ");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    sparse_format(arr, row, cols);
    for (int i = 0; i < cols; i++)
    {
        free(arr[i]);
    }
    free(arr);
    return 0;
}