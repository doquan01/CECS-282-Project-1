#include <iostream>
#include "Faculty.h"

using namespace std;

void Faculty::setLevel(Level l){
	pos = l;
}
void Faculty::setEducation(){
	
}
Education Faculty:: getEducation(){ //change void type so it returns education object
	return edu;
}
string getLevel(){
	switch(pos){
		case AS:
			return "Assistant Professor";
		case AO:
			return "Associate Professor";
		case FU:
			return "Full";
	}
}
void monthlyEarning(){
	
}
void putData(){
	Employee::putData();
	cout<< "\nLevel: "<<getLevel() << endl;
}
Faculty::Faculty(string lastname, string firstname, string id, string birthdate, Level l, string education):Employee(lastName, firstName, id, birthDate){//put appropriate data tpyes
	pos = l;
}
