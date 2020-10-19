#ifdef STAFF_H
#define STAFF_H

#include "Employee.h"
#include <iostream>

using namespace std;

class Staff: public Employee
{
	public:
		void setHourlyRate(double r);
		double getHourlyRate();
		void putData();
		double monthlyEarning();
		Staff(string lastName, string firstName, string id, string birthDate, double r);
	protected:
		double hourlyRate;
};
#endif
