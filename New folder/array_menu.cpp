/* WAP to create a 1-D array of n elements and perform the following menu based operations using function.
a. insert a given element at specific position.
b. delete an element from a specific position of the array.
c. linear search to search an element
d. traversal of the array */
#include <iostream>
using namespace std;
bool insert(int *arr, int &n)
{
    cout << "Element to insert: ";
    int element;
    cin >> element;
    cout << "Enter position: ";
    int position;
    cin >> position;
    if (position >= 0 && position < n)
    {
        for (int i = n; i > position; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[position] = element;
        n++;
        return true;
    }
    return false;
}
bool remove(int *arr, int &n)
{
    int position;
    cout << "Enter position: ";
    cin >> position;
    if (position >= 0 && position < n)
    {
        for (int i = position; i < n; i++)
        {
            arr[i] = arr[i + 1];
        }
        n--;
        return true;
    }
    return false;
}
void linear_search(int arr[], int n)
{
    int element, flag = 0;
    cout << "Find the element: ";
    cin >> element;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == element)
        {
            cout << "Found at " << i << endl;
            flag =1;
        }
    }
    if (flag<1) 
    {
        cout << "NOT FOUND\n";
    }
    
}
void menu(int *arr, int n)
{
    int option;
    cout << "\nEnter option: ";
    cin >> option;
    switch (option)
    {
    case 1:
        // insert(arr, n) ? cout << "Element inserted\n" : fprintf(stderr, "Invalid Position\n");
        insert(arr, n) ? void(cout << "Element inserted\n") : void(fprintf(stderr, "ERROR\n"));
        menu(arr, n);
        break;
    case 2:
        remove(arr, n) ? void(cout << "Element deleted\n") : void(fprintf(stderr, "ERROR\n"));
        menu(arr, n);
        break;
    case 3:
        linear_search(arr, n);
        menu(arr, n);
        break;
    case 4:
        cout << "\n";
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        menu(arr, n);
        break;
    case 5:
        exit(EXIT_SUCCESS);
        break;
    default:
        fprintf(stderr, "Invalid Option\n");
        menu(arr, n);
        break;
    }
}
int main()
{
    int n;
    cout << "Enter size n : ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter Array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "***MENU***\n";
    cout << "1. Insert\n2. Delete\n3. Linear Search\n4. Traverse\n5. Exit\n";
    menu(arr, n);
    return 0;
}