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

int main(){
vector<Employee*> work = { 
        new Staff("Allen", "Paita", "123", M, "2/23/59", 50.00),
        new Faculty("Johnson","Anne","243", F, "4/27/62", FU, "Ph.D", "Engineering", 3),
        new Staff("Zapata", "Steven", "456", F, "7/12/64", 35.00),
        new Partime("Depirro", "Martin", "678", F, "9/15/87", 30.00, 15),
        new Faculty("Bouris","William","791", F, "3/14/75", AO, "Ph.D", "English", 1),
        new Partime("Guzman", "Augusto", "455", F, "8/10/77", 35.00, 30),
        new Faculty("Andrade","Christopher","623", F, "5/22/80", AS, "MS", "Physical Education", 0),
        new Staff("Rios", "Enrique", "789", M, "6/2/70", 40.00),
        new Partime("Aldaco", "Marque", "945", M, "11/24/88", 20.00, 35)};
        
        
        double totalPart = 0.0;
        double totalEmploy = 0.0;
        
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
