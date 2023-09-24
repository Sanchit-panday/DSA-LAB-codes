#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row, col, no_of_ele;
    printf("Enter sparse matrix in 3-tuple format: ");

    // Storing sparse matrix in 3-tuple form

    scanf("%d", &row);
    scanf("%d", &col);
    scanf("%d", &no_of_ele);

    int **arr = (int **)malloc(no_of_ele * sizeof(int *));
    for (int i = 0; i < no_of_ele; i++)
    {
        arr[i] = (int *)malloc(3 * sizeof(int));
    }

    // Taking input
    for (int i = 0; i < no_of_ele; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    // Generate the matrix
    int **matrix = (int **)calloc(row, sizeof(int *));
    for (int i = 0; i < row; i++)
    {
        matrix[i] = (int *)calloc(col, sizeof(int));
    }

    for (int i = 0; i < no_of_ele; i++)
    {
        int row_idx = arr[i][0];
        int col_idx = arr[i][1];
        int value = arr[i][2];
        matrix[row_idx][col_idx] = value;
    }

    // [For Testing] Display the generated matrix
    // printf("main matrix:\n");
    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < col; j++)
    //     {
    //         printf("%d ", matrix[i][j]);
    //     }
    //     printf("\n");
    // }

    // Allocate memory for the transposed matrix
    int **transpose = (int **)malloc(col * sizeof(int *));
    for (int i = 0; i < col; i++)
    {
        transpose[i] = (int *)malloc(row * sizeof(int));
    }

    // Transpose the generated matrix
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }

    // [For Testing] Display the transposed matrix
    // printf("Transposed matrix:\n");
    // for (int i = 0; i < col; i++)
    // {
    //     for (int j = 0; j < row; j++)
    //     {
    //         printf("%d ", transpose[i][j]);
    //     }
    //     printf("\n");
    // }

    printf("\nranspose of sparse matrix::\n");
    printf("%d %d %d\n", col, row, no_of_ele);
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (transpose[i][j] != 0)
            {
                printf("%d %d %d", i, j, transpose[i][j]);
                printf("\n");
            }
        }
    }

    // deallocating all memory
    for (int i = 0; i < no_of_ele; i++)
    {
        free(arr[i]);
    }
    free(arr);

    for (int i = 0; i < row; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    for (int i = 0; i < col; i++)
    {
        free(transpose[i]);
    }
    free(transpose);
    return 0;
}
