#include <iostream>
using namespace std;
struct complex
{
    int real;
    int imag;
};
void add(complex a, complex b, complex c)
{
    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;
    printf("\n%d + %di", c.real, c.imag);
}
void multiply(complex &num1, complex &num2, complex &num3)
{
    num3.real = ((num1.real * num2.real) - (num1.imag * num2.imag));
    num3.imag = ((num1.real * num2.imag) + (num1.imag * num2.real));
}
int main()
{
    complex num1, num2, num3;
    cout << "complex number format -> \"a + ii\"\n*Enter a and b only, eg. 2 3\n\n";
    cout << "complex number 1: ";
    cin >> num1.real >> num1.imag;
    cout << "complex number 2: ";
    cin >> num2.real >> num2.imag;
    cout << "\n";
    cout << "MENU" << endl;
    cout << "1. addition\n2. multiplication\nEnter your choice: ";
    int option;
    cin >> option;
    switch (option)
    {
    case 1:
        add(num1, num2, num3);
        break;
    case 2:
        multiply(num1, num2, num3);
        printf("\n%d + %di", num3.real, num3.imag);
        break;
    default:
        cout << "enter a valid option";
        break;
    }
    return 0;
}