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
		void virtual getData();
		void virtual putData();
		double monthlyEarning();
		Staff(string lastName, string firstName, string id, Sex s, string birthDate, double r);
	protected:
		double hourlyRate;
		double monthlySalary;
};
#endif
