#ifndef Employee_H
#define Employee_H

#include <iostream>

using namespace std;

enum Sex {M,F};
class Employee{
	public:
		Employee(string l, string f, int id, Sex, string b);
		void putData();
		void setLastName(string l);
		void setFirstName(string f);
		void setID(int id);
		void setSex(Sex);
		void setBirthDate(string b);
		string getLastName();
		string getFirstName();
		int getID();
		string getSex();
		string getBirthDate();
		virtual void monthlyEarning();
	protected:
		string lastName;
		string firstName;
		string ID;
		string sex;
		string birthDate;
};
#endif
