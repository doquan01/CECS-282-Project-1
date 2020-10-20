#ifndef Employee_H
#define Employee_H

#include <iostream>

using namespace std;

enum Sex {M,F};
class Employee{
	public:
		Employee(string l, string f, string id, string b);
		void putData();
		void setLastName(string l);
		void setFirstName(string f);
		void setID(string id);
		void setSex(Sex s, string g);
		void setBirthDate(string b);
		string getLastName();
		string getFirstName();
		string getID();
		string getSex();
		string getBirthDate();
		virtual double monthlyEarning() = 0;
	protected:
		string lastName;
		string firstName;
		string ID;
		string gender;
		string birthDate;
};
#endif
