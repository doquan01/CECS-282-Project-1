#ifndef Employee_H
#define Employee_H
#include <vector>
#include <typeinfo>
#include <fstream>
#include <iostream>

using namespace std;
enum Sex {M,F};
enum employeeType {tfaculty, tstaff, tpartime};
const int maxEm = 100;
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
		virtual employeeType get_Type();
      	static void add();      //add an Employee
      	static void display();  //display all Employees
      	static void read();     //read from disk file
      	static void write();    //write to disk file
	protected:
		string lastName;
		string firstName;
		string ID;
		Sex sexes;
		string birthDate;
		static int n;
        static vector<Employee*> work;
};
#endif
