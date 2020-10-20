#ifndef Partime_H
#define Partime_H
#include <iostream>

#include "Staff.h"
using namespace std;

class Partime: public Staff{
	public:
		void setHoursPerWeek(int weekHours);
		int getHoursPerWeek();
		void putData();
		double monthlyEarning();
		Partime(string lastName, string firstName, string id, string birthDate, double r, int weekHours);
	protected:
		int hoursPerWeek;
};
#endif
