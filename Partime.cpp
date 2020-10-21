#include<iostream>
#include "Partime.h"
#include "Constants.h"
using namespace std;

void Partime::setHoursPerWeek(int weekHours){
	hoursPerWeek = weekHours;
}
int Partime::getHoursPerWeek(){
	return hoursPerWeek;
}
void Partime::putData(){
	Employee::putData();
	cout << "Monthly salary: " << monthlyEarning();
	cout << "Monthly hours worked: " << STAFF_MONTHLY_HOURS_WORKED;
}
double Partime::monthlyEarning(){
	return hourlyRate * hoursPerWeek * 4;
}
Partime::Partime(string lastName, string firstName, string id, Sex s, string birthDate, double r, int weekHours):Staff(lastName, firstName, id, s, birthDate, r){
	hoursPerWeek = weekHours;
}
Partime::Partime(){
	hoursPerWeek = 0;

}
