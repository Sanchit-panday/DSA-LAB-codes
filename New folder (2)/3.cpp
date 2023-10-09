#include <iostream>
using namespace std;
struct Employee
{
    int Emp_id;
    string name;
    string designation;
    int basic_salary;
    double hra_percentage;
    double da_percentage;
    double gorss_salary;
};

void print(Employee employees[], int i)
{
    cout << "Name: " << employees[i].name << "\n";
    cout << "Designation: " << employees[i].designation << "\n";
    cout << "Basic Salary: " << employees[i].basic_salary << "\n";
    cout << "HRA %: " << employees[i].hra_percentage << "%\n";
    cout << "DA %: " << employees[i].da_percentage << "%\n";
    cout << "Gross Salary: " << employees[i].gorss_salary;
}
int main()
{
    int n;
    cout << "Enter no.of employees: ";
    cin >> n;
    Employee employees[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter employee " << i + 1 << " information :" << endl;
        cout << "Name: ";
        cin >> employees[i].name;
        cout << "Designation: ";
        cin >> employees[i].designation;
        cout << "Basic Salary: ";
        cin >> employees[i].basic_salary;
        cout << "HRA %: ";
        cin >> employees[i].hra_percentage;
        cout << "DA %: ";
        cin >> employees[i].da_percentage;
        employees[i].gorss_salary = employees[i].basic_salary + (employees[i].basic_salary * employees[i].hra_percentage / 100) + (employees[i].basic_salary * employees[i].da_percentage / 100);
        cout << "\n";
    }

    cout << "-----Output-----" << endl;
    for (int i = 0; i < n; i++)
    {
        print(employees, i);
        cout << endl << endl;
    }
    return 0;
}