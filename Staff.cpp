#include <iostream>
#include "Constants.h"
#include "Staff.h"
using namespace std;
 
double staffHours = STAFF_MONTHLY_HOURS_WORKED;

void Staff::setHourlyRate(double r){
    hourlyRate = r;
}
double Staff::getHourlyRate(){
    return hourlyRate;
}
double Staff::monthlyEarning(){
    monthlySalary = staffHours  * hourlyRate;
    return monthlySalary;
}
void Staff::getData(){
    Employee::getData();
    cout<<"Enter hourly rate: "; cin>>hourlyRate;
}
void Staff::putData(){
	Employee::putData();
    cout << "\nFull Time \nMonthly Salary: " << monthlyEarning()<<endl;
} 
Staff::Staff(){
	hourlyRate = 0;
	monthlySalary = 0;
}
Staff::Staff(string lastName, string firstName, string id, Sex s, string birthDate, double r):Employee(lastName, firstName, id, s, birthDate){
	hourlyRate = r;
	monthlySalary = monthlyEarning();
}   
