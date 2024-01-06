#include <stdio.h>
#include <stdlib.h>
void SelectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int iMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[iMin])
            {
                iMin = j;
            }
        }
        if (iMin != i)
        {
            int *temp = (int *)malloc(sizeof(int));
            *temp = arr[i];
            arr[i] = arr[iMin];
            arr[iMin] = *temp;
        }
    }
}

int main()
{
    int arr[20] = {5, 3, 1, 7, 2, 9, 4, 8, 6, 10, 12, 13, 15, 11, 14, 16, 17, 18, 19, 20};
    SelectionSort(arr, 20);
    for (int i = 0; i < 20; i++)
    {
        printf("%d - \n", arr[i]);
    }

    return 0;
}