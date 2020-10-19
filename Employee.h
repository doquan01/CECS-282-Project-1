#ifndef Employee_H
#define Employee_H

#include <iostream>

using namespace std;

class Employee{
	public:
		Employee();
	protected:
		string lastName;
		string firstName;
		string ID;
		
		string birthDate;
};
#endif
