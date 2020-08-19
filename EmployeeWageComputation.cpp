#include <iostream>
#include <ctime>
using namespace std;

int WAGE_PER_HOUR = 20;
int FULL_DAY_HOURS = 8;
int PART_TIME_HOURS = 4;

int main()
{
    int employeeHours = 0;
    cout << "Welcome to Employee Wage Computation Problem" << endl;
    srand(time(0));
    int status = rand() % 3;

    switch(status)
    {
        case 0 :
                cout << "Employee is present for full-time" << endl;
                employeeHours = FULL_DAY_HOURS;
                break;

        case 1 :
                cout << "Employee is present for part-time" << endl;
                employeeHours = PART_TIME_HOURS;
                break;

        default :
                cout << "Employee is absent" << endl;
    }

    cout << "Employee Daily Wage is > " << WAGE_PER_HOUR * employeeHours;
    return 0;
}