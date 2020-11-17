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
         if(s == "M"){
             sexes = M;
         }
         else if(s == "F"){
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
int Employee::n;
vector<*Employee> Employee::work(maxEm);
employeeType Employee::get_type(){
    if(typeid(*this) == typeid(Faculty)){
        return tfaculty;
    }
    else if(typeid(*this) == typeid(Staff)){
        return tstaff;
    }
    else if(typeid(*this) == typeid(Partime)){
        return tpartime;
    }
    else
      { cerr << "\nBad employee type"; exit(1); }
   return tfaculty;
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
         work[n++]->getData();     //get Employee data from user
}
void Employee::display(){
    double totalPart = 0.0;
    double totalEmploy = 0.0;
    if(n == 0){
             cout<<"There are no employees at the moment"<<endl;
         }
         else{
             for (int i = 0; i < n; i++) {
                  work.at(i)->putData();
                  if(typeid(*work.at(i)) == typeid(Partime)){
                     totalPart += work.at(i)->monthlyEarning();
                  }
                  totalEmploy += work.at(i)->monthlyEarning();
                }
                cout<<"\nTotal monthly salary for all the part-time staff: $"<<totalPart;
                cout<<"\nTotal monthly salary for all employees: $"<<totalEmploy<<endl;
         }
}
void Employee::write(){
    int size;
       cout << "Writing " << n << " employees.\n";
       ofstream ouf;              //open ofstream in binary
       employeeType etype;       //type of each employee object
    
       ouf.open("Employee.DAT", ios::trunc | ios::binary);
       if(!ouf)
          { cout << "\nCan't open file\n"; return; }
       for(int j=0; j<n; j++)     //for every employee object
          {                       //get its type
          etype = work[j]->get_type();
                                  //write type to file
          ouf.write( (char*)&etype, sizeof(etype) );
          switch(etype)           //find its size
             {
             case tpartime:   size=sizeof(Partime); break;
             case tstaff: size=sizeof(Staff); break;
             case tfaculty:   size=sizeof(Faculty); break;
             }                    //write employee object to file
          ouf.write( (char*)(work[j]), size );
          if(!ouf)
             { cout << "\nCan't write to file\n"; return; }
          }
}
void Employee::read(){
    int size;
            employeeType etype;
            ifstream inf;
            inf.open("Employee.DAT",ios::binary);
            if(!inf){
               cout << "\nCan't open file\n";
               return;
            }
            n = 0;
            while(true){
               inf.read((char*)&etype, sizeof(etype));
               if(inf.eof())
                  break;
               if(!inf){
                  cout << "\nCan't read type from file\n";
               }
               switch(etype){
                  case (tfaculty):
                     work[n] = new Faculty;
                     size = sizeof(Faculty);
                     break;
                  case(tstaff):
                     work[n] = new Staff;
                     size = sizeof(Staff);
                     break;
                  case(tpartime):
                     work[n] = new Partime;
                     size = sizeof(Partime);
                     break;
                  default:
                     cout << "\nUnknown type in file\n";
               }
               inf.read((char*)work[n], size);
               if(!inf){
                  cout << "\nCan't read data from file\n";
               }
               n++;
            }
            cout << "Reading " << n << " employees\n";
}




