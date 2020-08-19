#include <iostream>
#include <ctime>
using namespace std;

int WAGE_PER_HOUR = 20;
int FULL_DAY_HOURS = 8;
int PART_TIME_HOURS = 4;
int WORKING_DAYS_PER_MONTH = 20;

int main()
{
    int employeeHours, totalWage = 0;
    cout << "Welcome to Employee Wage Computation Problem" << endl;
    srand(time(0));

    for(int day = 1; day <= WORKING_DAYS_PER_MONTH; day++)
    {
        int status = rand() % 3;
        switch(status)
        {
            case 0 :
                    cout << "Employee is present for full-time on Day > " << day << endl;
                    employeeHours = FULL_DAY_HOURS;
                    break;

            case 1 :
                    cout << "Employee is present for part-time on Day > " << day << endl;
                    employeeHours = PART_TIME_HOURS;
                    break;

            default :
                    cout << "Employee is absent on Day > " << day << endl;
                    employeeHours = 0;
        }
        cout << "Employee Daily Wage is " << WAGE_PER_HOUR * employeeHours << " on Day > " << day << endl;
        totalWage += WAGE_PER_HOUR * employeeHours;
    }
    cout << "Total wage for the month > " << totalWage;
    return 0;
}