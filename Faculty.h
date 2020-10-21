#ifndef Faculty_H
#define Faculty_H
#include <iostream>
#include "Employee.h"

using namespace std;

enum Level = {AS, AO, FU};
class Faculty: public Employee
{
	public:
		void setLevel();
		void setEducation(string d, string m, int r);
		Education getEducation();
		string getLevel();
		double monthlyEarning();
		void putData();
		Faculty(string lastname, string firstname, string id, string birthdate, Level l, string d, string m, int r);//put appropriate data tpyes
	protected:
		Level pos;
		Education edu;
};
#endif
