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
		void setEducation();
		void getEducation(); //change void type so it returns education object
		string getLevel();
		double monthlyEarning();
		void putData();
		Faculty(string lastname, string firstname, string id, string birthdate, string level, string education);//put appropriate data tpyes
	protected:
		string Level;
		Education edu; //need education object
};
#endif