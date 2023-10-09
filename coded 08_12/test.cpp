// Write a program to print numbers from 1 to n using recursion function
#include <iostream>
using namespace std;
void print(int n)
{
    if (n == 1)
    {
        return;
    }
    n--;
    print(n);
    cout << "n = " << n << "\n";
}
int main()
{
    int n = 5;
    print(n);
    return 0;
}