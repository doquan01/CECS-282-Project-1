#ifndef Faculty_H
#define Faculty_H
#include <iostream>
#include "Employee.h"
#include "Education.h"

using namespace std;

enum Level {AS, AO, FU};
class Faculty: public Employee
{
	public:
		void setLevel(Level l);
		void setEducation(string d, string m, int r);
		Education getEducation();
		string getLevel();
		double monthlyEarning();
		void getData();
		void putData();
		Faculty();
		Faculty(string lastName, string firstName, string id, Sex s, string birthDate, Level l, string d, string m, int r);
	private:
		Level pos;
		Education edu;
};
#endif
