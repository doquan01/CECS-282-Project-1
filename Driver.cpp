//Quan Do, Hunter Lewis
// CECS 282 Project - part 2
#include <iostream>
#include "Employee.h"
#include "Staff.h"
#include "Faculty.h"
#include "Partime.h"
#include "Constants.h"
#include <vector>
#include <typeinfo>

using namespace std;
double totalPart = 0.0;
double totalEmploy = 0.0;
int main(){
static vector<Employee*> work;  
   for (int i = 0; i < work.size(); i++) {
      work.at(i)->putData();
      if(typeid(*work.at(i)) == typeid(Partime)){
         totalPart += work.at(i)->monthlyEarning();
      }
      totalEmploy += work.at(i)->monthlyEarning();
    }
    cout<<"\nTotal monthly salary for all the part-time staff: $"<<totalPart;
    cout<<"\nTotal monthly salary for all employees: $"<<totalEmploy<<endl;
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
         case 'a':            //add an employee to list
            char ch;
            cout << "'f' to add a faculty"
           "\n's' to add a Staff"
           "\n'p' to add a partime"
           "\nEnter selection: ";
          cin >> ch;
            switch(ch)
      {                       //create specified Employee type
         case 'f': work.at(work.size()) = new Faculty;   break;
         case 's': work.at(work.size()) = new Staff; break;
         case 'p': work.at(work.size()) = new Partime;   break;
         default: cout << "\nUnknown Employee type\n"; return;
      }
         int n = work.size();
         work.at(n++)->getData();     //get Employee data from user
            break;
         case 'd':            //display all employees
             
            break;
         case 'w':            //write employees to file
             
            break;
         case 'r':            //read all employees from file
             
            break;
         case 'x': 
         exit(0);   //exit program
         
         default: 
         cout << "\nUnknown command";
         }  //end switch
      }  //end while
   return 0;
}
