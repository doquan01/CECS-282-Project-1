#include <iostream>
#include "Constants.h"
#include "Staff.h"
using namespace std;
 
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
	Employee::putData();
    cout << "\nFull Time Monthly Salary: " << monthlyEarning();
} 
Staff::Staff(){
	hourlyRate = 0;
}
Staff::Staff(string lastName, string firstName, string id, Sex s, string birthDate, double r):Employee(lastName, firstName, id, s, birthDate){
	hourlyRate = r;
}   
