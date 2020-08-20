#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

int WAGE_PER_HOUR = 20;
int FULL_DAY_HOURS = 8;
int PART_TIME_HOURS = 4;
int WORKING_DAYS_PER_MONTH = 20;
int MAXIMUM_WORKING_HOURS = 100;

int main()
{
    int employeeHours, totalWage = 0;
    fstream fileStream;

    fileStream.open("employeeDetails.csv", ios::out | ios::trunc);
    fileStream << "Month, Employee ID, Day 1, Day 2, Day 3, Day 4, Day 5, Day 6, Day 7, Day 8, Day 9, Day 10, Day 11, Day 12, Day 13, Day 14, Day 15, Day 16, Day 17, Day 18, Day 19, Day 20, Total Wage, Total Working Hours" << "\n";
    cout << "Welcome to Employee Wage Computation Problem" << endl;
    srand(time(0));

    cout << "Enter the number of employees > ";
    int employees;
    cin >> employees;

    cout << "Enter the number of months > ";
    int months;
    cin >> months;

    for(int monthCount = 1; monthCount <= months; monthCount++)
    {
        cout << "Month > " << monthCount << endl;

        for(int employeeCount = 1; employeeCount <= employees; employeeCount++)
        {
            fileStream << monthCount << ",";
            fileStream << employeeCount << ",";
            cout << "Employee ID > " << employeeCount << endl;
            int day = 1;
            int totalWorkingHours = 0;

            while(day <= WORKING_DAYS_PER_MONTH && totalWorkingHours < MAXIMUM_WORKING_HOURS)
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
                    fileStream << WAGE_PER_HOUR * employeeHours << ",";
                }
            }
            cout << "Total wage for the month > " << totalWage << endl;
            cout << "Total working hours > " << totalWorkingHours << endl << endl;
            fileStream << totalWage << "," << totalWorkingHours << "\n";
        }
    }

    fileStream.close();
    return 0;
}
