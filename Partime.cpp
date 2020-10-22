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
	cout << "\nMonthly hours worked: " << hoursPerWeek * 4;
	cout << "\nMonthly salary: " << monthlyEarning() << endl;
	
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
