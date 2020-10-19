#include <iostream>
#include "Constants.h"
#include "Staff.h"
#include <string.h>
using namespace std;

class Staff{  
    double hourlyRate = STAFF_MONTHLY_HOURS_WORKED;
    double monthlySalary = FACULTY_MONTHY_SALARY;

    void Staff::setHourlyRate(double r){
        hourlyRate = r;
    }
    double Staff::getHourlyRate(){
        return hourlyRate;
    }
    double Staff::monthlyEarning(){
        monthlySalary = monthlySalary  * hourlyRate;
        return monthlySalary;
    }
    void Staff::putData(){
        cout << "\nEmployee ID: " << idNumber;
        cout << "\nEmployee Name: " << firstName, lastName;
        cout << "\nBirthday: " << birthDate;
        cout << "\nFull Time Monthly Salary: " << monthlyEarning();
    } 

    Staff::Staff(double r):Employee(int idNumber, string firstName, string lastName, string birthDate);   
}
