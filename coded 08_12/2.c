#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) { // Optimize the loop condition
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int sum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i])) {
            sum += arr[i];
        }
    }
    return sum;
}

int main() {
    int n;
    printf("Enter size of the array: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int ans = sum(arr, n);
    printf("\nAnswer: %d", ans);

    free(arr);
    return 0;
}
