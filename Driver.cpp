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
vector<Employee*> work(maxEm);
Staff* allen = new Staff("Allen", "Paita", "123", M, "2/23/59", 50.00);
    Faculty* Johnson = new Faculty("Johnson", "Anne", "243", F, "4/27/62", FU, "Ph.D", "Engineering", 3);
    Staff* Zapata = new Staff("Zapata", "Steven", "456", F, "7/12/64", 35.00);
    Partime* Depirro = new Partime("Depirro", "Martin", "678", F, "9/15/87", 30.00, 15);
    Faculty* Bouris = new Faculty("Bouris", "William", "791", F, "3/14/75", AO, "Ph.D", "English", 1);
    Partime* Guzman = new Partime("Guzman", "Augusto", "455", F, "8/10/77", 35.00, 30);
    Faculty* Andrade = new Faculty("Andrade", "Christopher", "623", F, "5/22/80", AS, "MS", "Physical Education", 0);
    Staff* Rios = new Staff("Rios", "Enrique", "789", M, "6/2/70", 40.00);
    Partime* Aldaco = new Partime("Aldaco", "Marque", "945", M, "11/24/88", 20.00, 35);
    work[0] = allen;
    work[1] = Johnson;
    work[2] = Zapata;
    work[3] = Depirro;
    work[4] = Bouris;
    work[5] = Guzman;
    work[6] = Andrade;
    work[7] = Rios;
    work[8] = Aldaco;
    
int n = 9;
char ch;
double totalPart = 0.0;
double totalEmploy = 0.0;
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
            employeeType etype;       //type of each employee object
            
            ouf.open("D:\\GitHub\\CECS-282-Project-1\\employee.txt", ios::trunc | ios::binary);
            if(!ouf)
               { cout << "\nCan't open file\n";}
            else{
                cout << "\nFound employee file\n";
                }
            for(int j=0; j<n; j++){
            //get its type
            if(typeid(*work.at(j)) == typeid(Faculty)){
                etype = tfaculty;
            }
            else if(typeid(*work.at(j)) == typeid(Staff)){
                etype = tstaff;
            }
            else if(typeid(*work.at(j)) == typeid(Partime)){
                etype = tpartime;
            }
            else{ cerr << "\nBad employee type"; exit(1); }
            ouf.write((char*)&etype, sizeof(etype) );
         switch(etype)           //find its size
             {
             case tpartime:   size=sizeof(Partime); break;
             case tstaff: size=sizeof(Staff); break;
             case tfaculty:   size=sizeof(Faculty); break;
             }                    //write employee object to file
         ouf.write( (char*)(work[j]), size );
         if(!ouf)
             { cout << "\nCan't write to file\n";}
          }
            ouf.close();
         }//write type to file
            break;
         case 'r':{            //read all employees from file
               int size;
            employeeType etype;
            ifstream inf;
            inf.open("D:\\GitHub\\CECS-282-Project-1\\employee.txt",ios::binary);
            if(!inf){
               cout << "\nCan't open file\n";
            }
            int z = 0;
            while(true){
               inf.read((char*)&etype, sizeof(etype));
               if(inf.eof())
                  break;
               if(!inf){
                  cout << "\nCan't read type from file\n";
               }
               switch(etype){
                  case (tfaculty):
                     work[z] = new Faculty;
                     size = sizeof(Faculty);
                     break;
                  case(tstaff):
                     work[z] = new Staff;
                     size = sizeof(Staff);
                     break;
                  case(tpartime):
                     work[z] = new Partime;
                     size = sizeof(Partime);
                     break;
                  default:
                     cout << "\nUnknown type in file\n";
               }
               inf.read((char*)work[z], size);
               if(!inf){
                  cout << "\nCan't read data from file\n";
               }
               z++;
            }
            cout << "Reading " << z << " employees\n";
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
