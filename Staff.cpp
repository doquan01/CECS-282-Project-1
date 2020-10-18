#include <iostream>
#include "Constants.h"
#include "Staff.h"
using namespace std;

class Staff extends Employee{  
    float hourlyRate = STAFF_MONTHLY_HOURS_WORKED;
    double monthlySalary = FACULTY_MONTHY_SALARY;

    double setHourlyRate(double r){
        hourlyRate = r;
    }
    void getHourlyRate(){
        return hourlyRate
    }
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