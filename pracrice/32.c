#include <stdio.h>
#include <stdlib.h>

// Function to rearrange the array as described
void rearrangeArray(int **originalArray, int numRows, int numCols)
{
    int maxNum = 0;
    int frequency = 0;
    for (int i = 0; i < numRows; i++)
    {
        int unique = originalArray[i][0];
        for (int j = 0; j < numCols; j++)
        {
            if (originalArray[i][j] == originalArray[0][0])
            {
                frequency++;
            }
        }
    }
    int *newArray = (int *)malloc(frequency * sizeof(int *));
    // // Find the maximum number in the original array
    // for (int i = 0; i < numRows; i++)
    // {
    //     for (int j = 0; j < numCols; j++)
    //     {
    //         if (originalArray[i * numCols + j] > maxNum)
    //         {
    //             maxNum = originalArray[i * numCols + j];
    //         }
    //     }
    // }
    // // printf("%d", maxNum);
    // // Create a new array to store the rearranged elements
    // int newArray[numRows][numCols];

    // // Initialize a count array to keep track of the occurrences of each number
    // int count[maxNum + 1];

    // for (int i = 0; i <= maxNum; i++)
    // {
    //     count[i] = 0;
    // }

    // // Count the occurrences of each number in the original array
    // for (int i = 0; i < numRows; i++)
    // {
    //     for (int j = 0; j < numCols; j++)
    //     {
    //         int num = originalArray[i * numCols + j];
    //         count[num]++;
    //     }
    // }

    // // Rearrange the array
    // int row = 0;
    // int col = 0;

    // for (int i = 1; i <= maxNum; i++)
    // {
    //     while (count[i] > 0)
    //     {
    //         newArray[row][col] = i;
    //         col++;
    //         count[i]--;

    //         if (col == numCols)
    //         {
    //             col = 0;
    //             row++;
    //         }
    //     }
    // }

    // // Display the rearranged array
    // printf("Rearranged Array:\n");
    // for (int i = 0; i < numRows; i++)
    // {
    //     for (int j = 0; j < numCols; j++)
    //     {
    //         printf("%d ", newArray[i][j]);
    //     }
    //     printf("\n");
    // }
}
int main()
{
    int numRows;
    int numCols;
    printf("Enter the number of rows and columns: ");
    scanf("%d", &numRows);
    scanf("%d", &numCols);
    int **originalArray = (int **)malloc(numRows * sizeof(int *));
    for (int i = 0; i < numRows; i++)
    {
        originalArray[i] = (int *)malloc(numCols * sizeof(int));
    }
    printf("Enter the elements: ");
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            scanf("%d", &originalArray[i][j]);
        }
    }
    printf("Dynamic 2D Array:\n");
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            printf("%3d ", originalArray[i][j]);
        }
        printf("\n");
    }
    rearrangeArray(originalArray, numRows, numCols);

    return 0;
}
