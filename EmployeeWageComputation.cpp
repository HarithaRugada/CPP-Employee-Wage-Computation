#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    cout << "Welcome to Employee Wage Computation Problem" << endl;
    srand(time(0));
    int result = rand() % 2;
    (result == 1) ? cout << "Employee is present" : cout << "Employee is absent";
}