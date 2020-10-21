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
Partime::Partime(string lastName, string firstName, string id, Sex s, string birthDate, double r, int weekHours):Staff(lastName, firstName, id, s, birthDate, r){
	hoursPerWeek = weekHours;
}
Partime::Partime(){
	hoursPerWeek = 0;

}
