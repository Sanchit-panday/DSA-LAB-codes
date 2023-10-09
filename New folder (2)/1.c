#include <stdio.h>
void compare_num(int *a, int *b)
{
    if (*a == *b)
    {
        printf("Both numbers are same");
        return;
    }
    (*a > *b) ? printf("%d is greater than %d", *a, *b) : 
    printf("%d is smaller than %d", *a, *b);
    return;
}
int main()
{
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    compare_num(&a, &b);
    return 0;
}