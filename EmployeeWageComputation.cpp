#include <iostream>
#include <ctime>
using namespace std;
int WAGE_PER_HOUR = 20;
int FULL_DAY_HOUR = 8;

int main()
{
    cout << "Welcome to Employee Wage Computation Problem" << endl;
    srand(time(0));
    int result = rand() % 2;
    (result == 1) ? cout << "Employee is present" << endl : cout << "Employee is absent" << endl;
    if(result == 1)
        cout << "Employee Daily Wage is > " << WAGE_PER_HOUR * FULL_DAY_HOUR;
    return 0;
}