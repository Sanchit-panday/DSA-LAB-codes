#include <stdio.h>
#include <stdlib.h>

// Function to rearrange the 2D array
void rearrangeArray(int originalArray[][5], int numRows, int numCols)
{
    // Find the maximum frequency of any number
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
    int maxFrequency = 0;

    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            if (originalArray[i][j] > maxFrequency)
            {
                maxFrequency = originalArray[i][j];
            }
        }
    }
    // Create a new 1D array with the appropriate size
    int newArray[numRows * numCols];

    // Initialize the new array with zeros
    for (int i = 0; i < numRows * numCols; i++)
    {
        newArray[i] = 0;
    }

    // Populate the new array with the numbers
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            int num = originalArray[i][j];
            newArray[num - 1]++; // Increment the count for the corresponding number
        }
    }

    // Display the modified array
    printf("Modified Array:\n");
    for (int i = 0; i < numRows * numCols; i++) {
        while (newArray[i] > 0) {
            printf("%d ,", i + 1);
            newArray[i]--;
        }
    }
    // for (int i = 0; i < numRows * numCols; i++)
    // {
    //     for (int j = 0; j <frequency; j++)
    //     {
    //         while (newArray[i] > 0)
    //         {
    //             printf("%d ", i + 1);
    //             newArray[i]--;
    //         }
    //     }
    //     printf("\n");
    // }

    printf("\n");
}

int main()
{
    int numRows = 3; // Number of rows
    int numCols = 4; // Number of columns

    int originalArray[3][5] = {
        {2, 3, 1, 5},
        {3, 1, 2, 2},
        {1, 3, 5, 5}};

    rearrangeArray(originalArray, numRows, numCols);

    return 0;
}
