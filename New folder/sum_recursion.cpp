// Write a program to print the sum of digits of the number entered by the user using recursion function
#include <iostream>
using namespace std;
void sum(int n, int &ans)
{
    if (n == 0)
    {
        return;
    }
    int digit = n % 10;
    n = n / 10;

    sum(n, ans);
    ans = ans + digit;
}
int main()
{
    int ans = 0, n;
    cout << "Enter the n : ";
    cin >> n;
    sum(n, ans);
    cout << "sum = " << ans;
    return 0;
}