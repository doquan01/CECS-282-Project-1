#include <iostream>
#include "Employee.h"

using namespace std;

<<<<<<< HEAD
Employee(string l, string f, int id, Sex, string b){
=======
Employee::Employee(string l, string f, int id, Sex, string b ){
>>>>>>> 8a05cad25780643061a6519e9193e8f9a42db5e4
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

void Employee::setID(int id){

}

string Employee::getSex(){

}

string Employee::getFirstName(){


}

string Employee::getLastName(){


}

int getID(){

    
}
