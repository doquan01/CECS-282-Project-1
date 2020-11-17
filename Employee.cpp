#include <iostream>
#include "Employee.h"

using namespace std;
Employee::Employee(){
	lastName = "";
	firstName = "";
	ID = "";
	birthDate = "";
}
Employee::Employee(string l, string f, string id, Sex s, string b){
	lastName = l;
	firstName = f;
	ID = id;
	sexes = s;
	birthDate = b;
}
void Employee::getData(){
    cin.ignore(10, '\n');
    string s;
         cout << "   Enter last name: "; cin >> lastName;
         cout << "   Enter first name: "; cin >> firstName;
         cout << "   Enter ID number: ";      cin >> ID;
         cout << "   Enter sex type: ";      cin >> s;
         if(s == "M" || s == "m"){
             sexes = M;
         }
         else if(s == "F" || s == "f"){
             sexes = F;
         }
         cout << "   Enter birth date ";      cin >> birthDate;
}
void Employee::putData(){
    cout << "\nEmployee ID: " << getID();
    cout << "\nEmployee Name: " << getFirstName()<< " "<< getLastName();
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
void Employee::setSex(Sex s){
	sexes = s;
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
	switch(sexes){
		case F:
			return "F";
		case M:
			return "M";
	}
}
string Employee::getBirthDate(){
	return birthDate;
}





