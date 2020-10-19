#ifdef STAFF_H
#define STAFF_H

#include "Employee.h"
#include <iostream>

using namespace std;

class Staff: public Employee
{
	public:
		Staff(double r = 160);
		void setHourlyRate(double r);
		double getHourlyRate();
		void putData();
		double monthlyEarning();
	protected:
		double hourlyRate;
};
#endif
