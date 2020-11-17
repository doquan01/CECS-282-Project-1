//Quan Do, Hunter Lewis
// CECS 282 Project - part 3
#include <iostream>
#include <fstream>
#include "Employee.h"
#include "Staff.h"
#include "Faculty.h"
#include "Partime.h"
#include "Constants.h"
#include <vector>
#include <typeinfo>
#include <fstream>

using namespace std;
double totalPart = 0.0;
double totalEmploy = 0.0;
int n = 0;
static vector<Employee*> work(100);
enum employeeType {tfaculty, tstaff, tpartime}; 
int main(){
char ch;
   while(true)
      {
      cout << "'a' -- add data for an employee"
              "\n'd' -- display data for all employees"
              "\n'w' -- write all employee data to file"
              "\n'r' -- read all employee data from file"
              "\n'x' -- exit"
              "\nEnter selection: ";
      cin >> ch;
      switch(ch)
         {
         case 'a':{            //add an employee to list
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
            break;
         }
         case 'd':{            //display all employees
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
            break;
         }
         case 'w':{            //write employees to file
         int size;
           cout << "Writing " << n << " employees.\n";
           ofstream ouf;              //open ofstream in binary
           employee_type etype;       //type of each employee object
        
           ouf.open("Employee.DAT", ios::trunc | ios::binary);
           if(!ouf)
              { cout << "\nCan't open file\n"; return; }
           for(int j=0; j<n; j++)     //for every employee object
              {                       //get its type
              etype = employees[j]->get_type();
                                      //write type to file
              ouf.write( (char*)&etype, sizeof(etype) );
              switch(etype)           //find its size
                 {
                 case tmanager:   size=sizeof(manager); break;
                 case tscientist: size=sizeof(scientist); break;
                 case tlaborer:   size=sizeof(laborer); break;
                 }                    //write employee object to file
              ouf.write( (char*)(employees[j]), size );
              if(!ouf)
                 { cout << "\nCan't write to file\n"; return; }
              }
            break;
         }
         case 'r':{            //read all employees from file
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
            break;
         }
         case 'x':{ 
         exit(0);   //exit program
         }
         default:{ 
         cout << "\nUnknown command";
         }
         }  //end switch
      }  //end while
   return 0;
}
