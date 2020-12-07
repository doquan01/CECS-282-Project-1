#include <iostream>
#include "Employee.h"
#include "Faculty.h"
#include "Staff.h"
#include "Partime.h"
#include <typeinfo>

using namespace std;
const int maxEm = 100;
int Employee::n;
vector<Employee*> Employee::work(maxEm);

Employee::Employee(){ //fix this
	lastName = "";
	firstName = "";
	ID = "";
	birthDate = "";
}
Employee::Employee(string l, string f, string id, Sex s, string b){ //Fix this
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
employeeType Employee::get_type()
{
    if (typeid(*this) == typeid(Faculty))
        return tfaculty;
    else if (typeid(*this) == typeid(Staff))
        return tstaff;
    else if (typeid(*this) == typeid(Partime))
        return tpartime;
    else
    {
        cerr << "\nBad employee type"; exit(1);
    }
}
   
void Employee::add(){
	char aOp;
        cout << "'f' to add a faculty"
       "\n's' to add a Staff"
       "\n'p' to add a partime"
       "\nEnter selection: ";
        cin >> aOp;
        switch(aOp)
          {                       //create specified Employee type
             case 'f': work[n] = new Faculty;   break;
             case 's': work[n] = new Staff; break;
             case 'p': work[n] = new Partime;   break;
             default: cout << "\nUnknown Employee type\n";
          }
    work[n++]->getData();
}
void Employee::display(){
  for(int j=0; j<n; j++)
  {
  cout  << (j+1);           //display number
  employeeType etype;
  etype = work[j]->get_type();
  switch( etype )   //display type
     {
     case tfaculty:{
     	cout << ". Type: Faculty";
		break;
	 }
     case tstaff:{
     	cout << ". Type: Staff";
		break;
	 }
     case tpartime:{
     	cout << ". Type: Parttime"; 
		break;
	 }
     default: cout << ". Unknown type";
     }
  work[j]->putData();    //display employee data
  cout << endl;
  }
}
void Employee::read(){
	   {
   int size;                  //size of employee object
   employeeType etype;       //type of employee
   ifstream inf;              //open ifstream in binary
   inf.open("EMPLOY.DAT", ios::binary);
   if(!inf)
      { cout << "\nCan't open file\n"; return; }
   n = 0;                     //no employees in memory yet
   while(true)
      {                       //read type of next employee
      inf.read( (char*)&etype, sizeof(etype) );
      if( inf.eof() )         //quit loop on eof
         break;
      if(!inf)                //error reading type
         { cout << "\nCan't read type from file\n"; return; }
      switch(etype)
         {                    //make new employee
         case tfaculty:       //of correct type
            work[n] = new Faculty;
            size=sizeof(Faculty);
            break;
         case tstaff:
            work[n] = new Staff;
            size=sizeof(Staff);
            break;
         case tpartime:
            work[n] = new Partime;
            size=sizeof(Partime);
            break;
         default: cout << "\nUnknown type in file\n"; return;
         }                    //read data from file into it
      inf.read( (char*)work[n], size  );
      if(!inf)                //error but not eof
         { cout << "\nCan't read data from file\n"; return; }
      n++;                    //count employee
      }  //end while
   cout << "Reading " << n << " employees\n";
   }
}
void Employee::write()
   {
   int size = 0;
   cout << "Writing " << n << " employees.\n";
   ofstream ouf;              //open ofstream in binary
   employeeType etype;       //type of each employee object

   ouf.open("EMPLOY.DAT", ios::trunc | ios::binary);
   if(!ouf)
      { cout << "\nCan't open file\n"; return; }
   for(int j=0; j<n; j++)     //for every employee object
      {                       //get its type
      etype = work[j]->get_type();
                              //write type to file
      ouf.write( (char*)&etype, sizeof(etype) );
      switch(etype)           //find its size
         {
         case tfaculty:   size=sizeof(Faculty); break;
         case tstaff: size=sizeof(Staff); break;
         case tpartime:   size=sizeof(Partime); break;
         }                    //write employee object to file
      ouf.write( (char*)(work[j]), size );
      if(!ouf)
         { cout << "\nCan't write to file\n"; return; }
      }
   }
void Employee::copyVector(vector<Employee*> const &v){
	for(int i = 0; i < v.size(); i++){
		work[i] = v[i];
		++n;
	}
}
