#include <iostream>
#include <ctime>
using namespace std;

int WAGE_PER_HOUR = 20;
int FULL_DAY_HOURS = 8;
int PART_TIME_HOURS = 4;
int WORKING_DAYS_PER_MONTH = 20;
int MAXIMUM_WORKING_HOURS = 100;
int main()
{
    int employeeHours, totalWage = 0, totalWorkingHours = 0;
    cout << "Welcome to Employee Wage Computation Problem" << endl;
    srand(time(0));

    for(int day = 1; day <= WORKING_DAYS_PER_MONTH && totalWorkingHours <= MAXIMUM_WORKING_HOURS; )
    {
        int status = rand() % 3;
        switch(status)
        {
            case 0 :
                    employeeHours = FULL_DAY_HOURS;
                    break;

            case 1 :
                    employeeHours = PART_TIME_HOURS;
                    break;

            default :
                    employeeHours = 0;
        }
        if((totalWorkingHours + employeeHours) <= MAXIMUM_WORKING_HOURS)
        {
            cout << "Employee Daily Wage is " << WAGE_PER_HOUR * employeeHours << " on Day > " << day << endl;
            totalWage += WAGE_PER_HOUR * employeeHours;
            totalWorkingHours += employeeHours;
            day++;
        }
        if(totalWorkingHours == MAXIMUM_WORKING_HOURS)
            break;
    }
    cout << "Total wage for the month > " << totalWage << endl;
    cout << "Total working hours > " << totalWorkingHours;
    return 0;
}