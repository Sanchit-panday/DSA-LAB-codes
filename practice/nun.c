#include <stdio.h>
int countX(int L, int R, int X)
{
    int count = -1;
    while (L <= X + (10 * (++count)) && R >= X + (10 * (++count)))
    {
    }
    return count;
}

int main()
{
    int arr[] = {11, 23, 34, 56, 67, 21, 24, 3, 9, 10};
    int n = (sizeof(arr)) / sizeof(arr[0]);
    quicksort(arr, 0, n - 1);
    printf("The sorted array is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}