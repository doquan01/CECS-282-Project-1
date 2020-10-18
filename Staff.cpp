#include <iostream>
#include "Constants.h"
using namespace std;

class Staff extends Employee{
    public:
        float hourlyRate;
        double monthlySalary;
    void putData(){
        cout << "\nEmployee ID: " << idNumber;
        cout << "\nEmployee Name: " << firstName, lastName;
        cout << "\nBirthday: " << birthDate;
        cout << "\nFull Time Monthly Salary: " << monthlySalary;
        }
    }   
}