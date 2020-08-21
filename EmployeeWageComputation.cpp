#include <iostream>
#include <ctime>
#include <fstream>
#include <cstring>
#include <vector>
using namespace std;

int FULL_DAY_HOURS = 8;
int PART_TIME_HOURS = 4;

struct CompanyEmpWage
{
    string companyName;
    int wagePerHour = 0, workingDaysPerMonth = 0, maximumWorkingHours = 0, employees = 0, months = 0;

    public :
    void companyDetails(string companyName, int wagePerHour, int workingDaysPerMonth, int maximumWorkingHours, int employees, int months);
    string getCompanyName();
    int getWagePerHour();
    int getWorkingDaysPerMonth();
    int getMaximumWorkingHours();
    int getEmployees();
    int getMonths();
};

void CompanyEmpWage::companyDetails(string companyName, int wagePerHour, int workingDaysPerMonth, int maximumWorkingHours, int employees, int months)
{
    this -> companyName = companyName;
    this -> wagePerHour = wagePerHour;
    this -> workingDaysPerMonth = workingDaysPerMonth;
    this -> maximumWorkingHours = maximumWorkingHours;
    this -> employees = employees;
    this -> months = months;
}

string CompanyEmpWage::getCompanyName()
{
    return companyName;
}

int CompanyEmpWage::getWagePerHour()
{
    return wagePerHour;
}

int CompanyEmpWage::getWorkingDaysPerMonth()
{
    return workingDaysPerMonth;
}

int CompanyEmpWage::getMaximumWorkingHours()
{
    return maximumWorkingHours;
}

int CompanyEmpWage::getEmployees()
{
    return employees;
}

int CompanyEmpWage::getMonths()
{
    return months;
}

struct WageComputation
{
    vector<CompanyEmpWage> companyWage;
    void addCompany(CompanyEmpWage companyEmpWage)
    {
        companyWage.push_back(companyEmpWage);
    }

    void calculate(CompanyEmpWage companyEmpWage)
    {
        int employeeHours, totalWage = 0;
        fstream fileStream;

        fileStream.open("employeeDetails.csv", ios::out | ios::app);
        srand(time(0));

        for(int monthCount = 1; monthCount <= companyEmpWage.getMonths(); monthCount++)
        {
            cout << "Month > " << monthCount << endl;
            for(int employeeCount = 1; employeeCount <= companyEmpWage.getEmployees(); employeeCount++)
            {
                cout << "Employee ID > " << employeeCount << endl;
                int day = 1;
                int totalWorkingHours = 0;

                while(day <= companyEmpWage.getWorkingDaysPerMonth() && totalWorkingHours < companyEmpWage.getMaximumWorkingHours())
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

                    if((totalWorkingHours + employeeHours) <= companyEmpWage.getMaximumWorkingHours())
                    {
                        fileStream << companyEmpWage.getCompanyName() << ",";
                        fileStream << companyEmpWage.getWagePerHour() << ",";
                        fileStream << companyEmpWage.getWorkingDaysPerMonth() << ",";
                        fileStream << companyEmpWage.getMaximumWorkingHours() << ",";
                        fileStream << monthCount << ",";
                        fileStream << employeeCount << ",";
                        fileStream << day << ",";
                        cout << "Employee Daily Wage is " << companyEmpWage.getWagePerHour() * employeeHours << " on Day > " << day << endl;
                        totalWage += companyEmpWage.getWagePerHour() * employeeHours;
                        totalWorkingHours += employeeHours;
                        day++;
                        fileStream << companyEmpWage.getWagePerHour() * employeeHours << ",";
                        fileStream << totalWage << "," << totalWorkingHours << "\n";
                    }
                }
                cout << "Total wage for the month > " << totalWage << endl;
                cout << "Total working hours > " << totalWorkingHours << endl << endl;
                addCompany(companyEmpWage);
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
    struct CompanyEmpWage empWage[2];
    struct WageComputation empWageComputation;
    
    empWage[0].companyDetails("abc", 15, 20, 120, 3, 2);
    empWageComputation.calculate(empWage[0]);
    empWage[1].companyDetails("xyz", 20, 20, 150, 2, 3);
    empWageComputation.calculate(empWage[1]);
    return 0;
}