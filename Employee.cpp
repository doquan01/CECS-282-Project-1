#include <iostream>
#include "Employee.h"

using namespace std;

Employee::Employee(string l, string f, string id, Sex, string b ){
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
string Employee::getBirthDate(){

}

void Employee::setLastName(string l){

}

void Employee::setBirthDate(string b){


}

void Employee::setFirstName(string f){


}

void Employee::setID(string id){

}

string Employee::getSex(){

}

string Employee::getFirstName(){


}

string Employee::getLastName(){


}

string getID(){

    
}
