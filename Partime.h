#ifndef Partime_H
#define Partime_H
#include <iostream>

#include "Staff.h"
using namespace std;

class Partime: public Staff{
	public:
		Partime();
		void setHoursPerWeek(int weekHours);
		int getHoursPerWeek();
		void putData();
		double monthlyEarning();
		Partime(string lastName, string firstName, string id, Sex s, string birthDate, double r, int weekHours);
	protected:
		int hoursPerWeek;
};
#endif
