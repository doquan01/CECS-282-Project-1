#include <iostream>
#include "Faculty.h"
#include "Constants.h"

using namespace std;

void Faculty::setLevel(Level l){
	pos = l;
}
void Faculty::setEducation(string d, string m, int r){
	edu.setDegree(d);
	edu.setMajor(m);
	edu.setResearch(r);
}
Education Faculty:: getEducation(){
	return edu;
}
string Faculty::getLevel(){
	switch(pos){
		case AS:
			return "Assistant Professor";
		case AO:
			return "Associate Professor";
		case FU:
			return "Full";
	}
}
double Faculty::monthlyEarning(){
	switch(pos){
		case AS:
			return FACULTY_MONTHY_SALARY;
		case AO:
			return (FACULTY_MONTHY_SALARY * 1.2);
		case FU:
			return (FACULTY_MONTHY_SALARY * 1.4);
	}
}
void Faculty::putData(){
	Employee::putData();
	cout<< "\nLevel: "<<getLevel() << endl;
	cout<< "Monthly Salary: " << monthlyEarning()<<endl;
}
Faculty::Faculty(string lastname, string firstname, string id, string birthdate, Level l, string d, string m, int r):Employee(lastName, firstName, id, birthDate){
	edu.setDegree(d);
	edu.setMajor(m);
	edu.setResearch(r);
	pos = l;
}
