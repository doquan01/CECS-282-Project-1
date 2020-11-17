#ifndef Employee_H
#define Employee_H

#include <iostream>

using namespace std;
enum Sex {M,F};
class Employee{
	public:
		Employee();
		Employee(string l, string f, string id, Sex s, string b);
		void virtual putData();
		void virtual getData();
		void setLastName(string l);
		void setFirstName(string f);
		void setID(string id);
		void setSex(Sex s);
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
		Sex sexes;
		string birthDate;
};
#endif
