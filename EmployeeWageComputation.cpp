#include <iostream>
#include <ctime>
#include <fstream>
#include <cstring>
using namespace std;

int FULL_DAY_HOURS = 8;
int PART_TIME_HOURS = 4;

struct EmpWageBuilder
{
    string companyName;
    int wagePerHour = 0, workingDaysPerMonth = 0, maximumWorkingHours = 0, employees = 0, months = 0;

    EmpWageBuilder(string companyName, int wagePerHour, int workingDaysPerMonth, int maximumWorkingHours, int employees, int months)
    {
        this -> companyName = companyName;
        this -> wagePerHour = wagePerHour;
        this -> workingDaysPerMonth = workingDaysPerMonth;
        this -> maximumWorkingHours = maximumWorkingHours;
        this -> employees = employees;
        this -> months = months;
    }

    void calculate()
    {
        int employeeHours, totalWage = 0;
        fstream fileStream;

        fileStream.open("employeeDetails.csv", ios::out | ios::app);
        srand(time(0));

            for(int monthCount = 1; monthCount <= months; monthCount++)
            {
                cout << "Month > " << monthCount << endl;
                for(int employeeCount = 1; employeeCount <= employees; employeeCount++)
                {
                    cout << "Employee ID > " << employeeCount << endl;
                    int day = 1;
                    int totalWorkingHours = 0;

                    while(day <= workingDaysPerMonth && totalWorkingHours < maximumWorkingHours)
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

                        if((totalWorkingHours + employeeHours) <= maximumWorkingHours)
                        {
                            fileStream << companyName << ",";
                            fileStream << wagePerHour << ",";
                            fileStream << workingDaysPerMonth << ",";
                            fileStream << maximumWorkingHours << ",";
                            fileStream << monthCount << ",";
                            fileStream << employeeCount << ",";
                            fileStream << day << ",";
                            cout << "Employee Daily Wage is " << wagePerHour * employeeHours << " on Day > " << day << endl;
                            totalWage += wagePerHour * employeeHours;
                            totalWorkingHours += employeeHours;
                            day++;
                            fileStream << wagePerHour * employeeHours << ",";
                            fileStream << totalWage << "," << totalWorkingHours << "\n";
                        }
                    }
                    cout << "Total wage for the month > " << totalWage << endl;
                    cout << "Total working hours > " << totalWorkingHours << endl << endl;
                }
            }
    
        fileStream.close();
    }
};

int main()
{
    fstream fileStream;

    fileStream.open("employeeDetails.csv", ios::out | ios::trunc);
    fileStream << "COMPANY NAME, WAGE PER HOUR, WORKING DAYS, MAXIMUM WORKING HOURS, MONTH, EMPLOYEE ID, DAY, WAGE, TOTAL WAGE, TOTAL WORKING HOURS"<< "\n";
    fileStream.close();
    cout << "Welcome to Employee Wage Computation Problem" << endl;

    //string companyName, int wagePerHour, int workingDaysPerMonth, int maximumWorkingHours, int employees, int months
    EmpWageBuilder abc("abc", 15, 20, 120, 3, 2), xyz("xyz", 20, 20, 150, 2, 3);
    abc.calculate();
    xyz.calculate();
    return 0;
}
