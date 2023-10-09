// Write a program to print numbers from 1 to n using recursion function
#include <iostream>
using namespace std;
void print(int n)
{
    if (n == 0)
    {
        return;
    }
    n--;
    print(n);
    cout << " " << n ;
}
int main()
{
    int n = 5;
    print(n);
    return 0;
}

// #include <iostream>
// using namespace std;

// void print(int n) {
//     if (n == 0) { // Changed the base case to n == 0
//         return;
//     }
//     print(n - 1);
//     cout << n << " "; // Moved the cout before the recursive call
// }

// int main() {
//     int n = 5;
//     print(n);
//     return 0;
// }