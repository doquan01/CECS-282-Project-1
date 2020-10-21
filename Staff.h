#ifndef STAFF_H
#define STAFF_H

#include "Employee.h"
#include <iostream>

using namespace std;

class Staff: public Employee
{
	public:
		Staff();
		void setHourlyRate(double r);
		double getHourlyRate();
		virtual void putData();
		double monthlyEarning();
		Staff(string lastName, string firstName, string id, Sex s, string birthDate, double r);
	protected:
		double hourlyRate;
};
#endif