#include<iostream>
#include "Partime.h"

using namespace std;

void Partime::setHoursPerWeek(int weekHours){
	hoursPerWeek = weekHours;
}
int Partime::getHoursPerWeek(){
	return hoursPerWeek;
}
void Partime::putData(){
	
}
double Partime::monthlyEarning(){
	
}
Partime::Partime(string lastName, string firstName, string id, string birthDate, double r, int weekHours):Staff(string lastName, string firstName, string id, string birthDate, double r){
	hoursPerWeek = weekHours;
}
