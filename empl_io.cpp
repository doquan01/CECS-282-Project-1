// empl_io.cpp
// performs file I/O on Employee objects
// handles different sized objects
#include <fstream>            //for file-stream functions
#include <iostream>
#include <typeinfo>           //for typeid()
#include<vector>
using namespace std;
#include <process.h>          //for exit()
#include "Employee.h"

const int LEN = 32;           //maximum length of last names
const int MAXEM = 100;        //maximum number of Employees

enum Employee_type {tFaculty, tStaff, tPartime};
////////////////////////////////////////////////////////////////
class Employee                //Employee class
   {
   private:
      char name[LEN];         //Employee name
      unsigned long number;   //Employee number
      static int n;           //current number of Employees
      static vector<Employee*> Employees;  //array of ptrs to emps
   public:
      virtual void getdata()
         {
         cin.ignore(10, '\n');
         cout << "   Enter last name: "; cin >> name;
         cout << "   Enter number: ";      cin >> number;
         }
      virtual void putdata()
         {
         cout << "\n   Name: " << name;
         cout << "\n   Number: " << number;
         }
      virtual Employee_type get_type();  //get type
      static void add();      //add an Employee
      static void display();  //display all Employees
      static void read();     //read from disk file
      static void write();    //write to disk file
   };
//--------------------------------------------------------------
//static variables
int Employee::n;              //current number of Employees
vector<Employee*> Employee::Employees(MAXEM);  //array of ptrs to emps
////////////////////////////////////////////////////////////////
//Faculty class
class Faculty : public Employee
   {
   private:
      char title[LEN];        //"vice-president" etc.
      double dues;            //golf club dues
   public:
      void getdata()
         {
         Employee::getdata();
         cout << "   Enter title: ";          cin >> title;
         cout << "   Enter golf club dues: "; cin >> dues;
         }
      void putdata()
         {
         Employee::putdata();
         cout << "\n   Title: " << title;
         cout << "\n   Golf club dues: " << dues;
         }
   };
////////////////////////////////////////////////////////////////
//Staff class
class Staff : public Employee
   {
   private:
      int pubs;               //number of publications
   public:
      void getdata()
         {
         Employee::getdata();
         cout << "   Enter number of pubs: "; cin >> pubs;
         }
      void putdata()
         {
         Employee::putdata();
         cout << "\n   Number of publications: " << pubs;
         }
   };
////////////////////////////////////////////////////////////////   
//Partime class
class Partime : public Employee
   {
   };
////////////////////////////////////////////////////////////////
//add Employee to list in memory
void Employee::add()
   {
   char ch;
   cout << "'f' to add a faculty"
           "\n's' to add a Staff"
           "\n'p' to add a partime"
           "\nEnter selection: ";
   cin >> ch;
   switch(ch)
      {                       //create specified Employee type
      case 'f': Employees[n] = new Faculty;   break;
      case 's': Employees[n] = new Staff; break;
      case 'p': Employees[n] = new Partime;   break;
      default: cout << "\nUnknown Employee type\n"; return;
      }
   Employees[n++]->getdata();     //get Employee data from user
   }
//--------------------------------------------------------------
//display all Employees
void Employee::display()
   {
   for(int j=0; j<n; j++)
      {
      cout  << (j+1);           //display number
      switch( Employees[j]->get_type() )   //display type
         {
         case tFaculty:    cout << ". Type: Faculty";   break;
         case tStaff:  cout << ". Type: Staff"; break;
         case tPartime:    cout << ". Type: Partime";   break;
         default: cout << ". Unknown type";
         }
      Employees[j]->putdata();    //display Employee data
      cout << endl;
      }
   }
//--------------------------------------------------------------
//return the type of this object
Employee_type Employee::get_type()
   {
   if( typeid(*this) == typeid(Faculty) )
      return tFaculty;
   else if( typeid(*this)==typeid(Staff) )
      return tStaff;
   else if( typeid(*this)==typeid(Partime) )
      return tPartime;
   else
      { cerr << "\nBad Employee type"; exit(1); }
   return tFaculty;
   }
//--------------------------------------------------------------
//write all current memory objects to file
void Employee::write()
   {
   int size;
   cout << "Writing " << n << " Employees.\n";
   ofstream ouf;              //open ofstream in binary
   Employee_type etype;       //type of each Employee object

   ouf.open("EMPLOY.DAT", ios::trunc | ios::binary);
   if(!ouf)
      { cout << "\nCan't open file\n"; return; }
   for(int j=0; j<n; j++)     //for every Employee object
      {                       //get its type
      etype = Employees[j]->get_type();
                              //write type to file
      ouf.write( (char*)&etype, sizeof(etype) );
      switch(etype)           //find its size
         {
         case tFaculty:   size=sizeof(Faculty); break;
         case tStaff: size=sizeof(Staff); break;
         case tPartime:   size=sizeof(Partime); break;
         }                    //write Employee object to file
      ouf.write( (char*)(Employees[j]), size );
      if(!ouf)
         { cout << "\nCan't write to file\n"; return; }
      }
   }
//--------------------------------------------------------------
//read data for all Employees from file into memory
void Employee::read()
   {
   int size;                  //size of Employee object
   Employee_type etype;       //type of Employee
   ifstream inf;              //open ifstream in binary
   inf.open("EMPLOY.DAT", ios::binary);
   if(!inf)
      { cout << "\nCan't open file\n"; return; }
   n = 0;                     //no Employees in memory yet
   while(true)
      {                       //read type of next Employee
      inf.read( (char*)&etype, sizeof(etype) );
      if( inf.eof() )         //quit loop on eof
         break;
      if(!inf)                //error reading type
         { cout << "\nCan't read type from file\n"; return; }
      switch(etype)
         {                    //make new Employee
         case tFaculty:       //of correct type
            Employees[n] = new Faculty;
            size=sizeof(Faculty);
            break;
         case tStaff:
            Employees[n] = new Staff;
            size=sizeof(Staff);
            break;
         case tPartime:
            Employees[n] = new Partime;
            size=sizeof(Partime);
            break;
         default: cout << "\nUnknown type in file\n"; return;
         }                    //read data from file into it
      inf.read( (char*)Employees[n], size  );
      if(!inf)                //error but not eof
         { cout << "\nCan't read data from file\n"; return; }
      n++;                    //count Employee
      }  //end while
   cout << "Reading " << n << " Employees\n";
   }
////////////////////////////////////////////////////////////////
int main()
   {
   char ch;
   while(true)
      {
      cout << "'a' -- add data for an Employee"
              "\n'd' -- display data for all Employees"
              "\n'w' -- write all Employee data to file"
              "\n'r' -- read all Employee data from file"
              "\n'x' -- exit"
              "\nEnter selection: ";
      cin >> ch;
      switch(ch)
         {
         case 'a':            //add an Employee to list
            Employee::add(); break;
         case 'd':            //display all Employees
            Employee::display(); break;
         case 'w':            //write Employees to file
            Employee::write(); break;
         case 'r':            //read all Employees from file
            Employee::read(); break;
         case 'x': exit(0);   //exit program
         default: cout << "\nUnknown command";
         }  //end switch
      }  //end while
   return 0;
   }  //end main()