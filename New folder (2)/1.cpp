#include <iostream>
using namespace std;
void compare(int &a, int &b)
{
    if (a == b)
    {
        cout << "Both numbers are same";
        return;
    }
    (a > b) ? cout << a << " is greater than " << b : cout << a << " is smaller than " << b;
    return;
}
int main()
{
    int a, b;
    printf("Enter two numbers: ");
    cin >> a;
    cin >> b;
    compare(a, b);
    return 0;
}