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
		void setEducation(Education e);
		Education getEducation();
		string getLevel();
		double monthlyEarning();
		void putData();
		Faculty();
		Faculty(string lastname, string firstname, string id, Sex s, string birthdate, Level l, Education e);
	private:
		Level pos;
		Education edu;
};
#endif
