#ifndef Employee_H
#define Employee_H

#include <iostream>

using namespace std;

class Employee{
	public:
		Employee();
		void putData();
		void setLastName(sting l);
		void setFirstName(string f);
		void setID(int id);
		void setSex();
		void setBirthDate(string b);
		string getLastName();
		string getFirstName();
		int getID();
		enum getSex();
		string getBirthDate();
		virtual void monthlyEarning();
	protected:
		string lastName;
		string firstName;
		string ID;
		enum Sex {M,F};
		string birthDate;
};
#endif
