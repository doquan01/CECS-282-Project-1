#ifndef Employee_H
#define Employee_H
#include <vector>
#include "Constants.h"
#include <typeinfo>
#include <fstream>
#include <iostream>


using namespace std;
enum Sex {M,F};
enum employeeType {tfaculty, tstaff, tpartime};
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
		static void copyVector(vector<Employee*> &v);
		virtual employeeType get_type();
		static void add();      
	    static void display();  
	    static void read();    
	    static void write();
	protected:
		char lastName[LEN];
		char firstName[LEN];
		char ID[LEN];
		Sex sexes;
		char birthDate[LEN];
		static int n;
		static vector<Employee*> work;
};
#endif
