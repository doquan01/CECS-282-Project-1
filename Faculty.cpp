#include <iostream>
#include "Faculty.h"
#include "Constants.h"

using namespace std;

void Faculty::setLevel(Level l){
	pos = l;
}
void Faculty::setEducation(string d, string m, int r){
	edu = Education(d,m,r);
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
void Faculty::getData(){
    string l;
    string d;
    string m;
    int r;
    Employee::getData();
    cout<<"Enter position level: "; cin>>l;
    if(l == "AS" || l == "as"){
        pos = AS;
    }
    else if(l == "AO" || l == "ao"){
        pos = AO;
    }
    else if(l == "FU" || l == "fu"){
        pos = FU;
    }
    cout<<"Enter degree: "; cin>>d;
    cout<<"Enter major: "; cin>>m;
    cout<<"Enter number of research: "; cin>>r;
    edu = Education(d,m,r);
}
void Faculty::putData(){
	Employee::putData();
	cout<< "\n"<<getLevel() <<" Professor"<< endl;
	cout<< "Monthly Salary: " << monthlyEarning()<<endl;
}
Faculty::Faculty():Employee(){
	edu = Education();
}
Faculty::Faculty(string lastName, string firstName, string id, Sex s, string birthDate, Level l, string d, string m, int r):Employee(lastName, firstName, id, s, birthDate){
	setEducation(d,m,r);
	pos = l;
}
