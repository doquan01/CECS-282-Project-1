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
            Employee::add();
            break;
         }
         case 'd':{            //display all employees
            Employee::display();
            break;
         }
         case 'w':{            //write employees to file
            Employee::write();
            break;
         }
         case 'r':{            //read all employees from file
            Employee::read();
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
