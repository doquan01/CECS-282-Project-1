#include <iostream>
#include "Employee.h"

using namespace std;

Employee::Employee(string l, string f, string id, string b){
	lastName = l;
	firstName = f;
	ID = id;
	birthDate = b;
}
void Employee::putData(){
    cout << "\nEmployee ID: " << getID();
    cout << "\nEmployee Name: " << getFirstName(), getLastName();
    cout << "\nBirthday: " << getBirthDate();
}

void Employee::setLastName(string l){
	lastName = l;
}
void Employee::setFirstName(string f){
	firstName = f;
}
void Employee::setID(string id){
	ID = id; 
}
void Employee::setSex(Sex s, string g){
	cout<<"\nEnter your sex";
	cin>>g;
	if(g == "M" || g == "Male"){
		s = M;
	}
	else if(g == "F" || g == "Female"){
		s = F;
	}
	switch(s){
		case M:
			gender = "M";
			break;
		case F:
			gender = "F";
			break;
	}
}
void Employee::setBirthDate(string b){
	birthDate = b;
}
string Employee::getLastName(){
	return lastName;
}
string Employee::getFirstName(){
	return firstName;
}
string Employee::getID(){
	return ID;
}
string Employee::getSex(){
	return gender;
}
string Employee::getBirthDate(){
	return birthDate;
}




