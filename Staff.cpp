#include <iostream>
#include "Constants.h"
using namespace std;

class Staff extends Employee{
    public:
        float hourlyRate;
        double monthlySalary;    
    float hourlyRate = STAFF_MONTHLY_HOURS_WORKED;
    double monthlySalary = FACULTY_MONTHY_SALARY;
    double monthlyEarning(){
        monthlySalary = monthlySalary  * hourlyRate;
        return monthlySalary
    }

    void putData(){
        cout << "\nEmployee ID: " << idNumber;
        cout << "\nEmployee Name: " << firstName, lastName;
        cout << "\nBirthday: " << birthDate;
        cout << "\nFull Time Monthly Salary: " << monthlyEarning();
    } 
    
}