# CECS-282-Project-1

Payroll System Using Inheritance and Polymorphism

Define the following constants in a header file.

FACULTY_MONTHLY_SALARY = 5000.00
STAFF_MONTHLY_HOURS_WORKED = 160
Implement an abstract class Employee with the following requirements:

Attributes
last name (String)
first name (String)
ID number (String)
Sex - M or F (use enum statement)
Birth date (Date)
Default argument constructor and argument constructors.
Public methods
putData that displays the following information:
ID Employee number :_________
Employee name: __________
Birth date: _______
get and set methods
pure virtual method monthlyEarning that returns the monthly earning.   
3. Implement a class called Staff extending from the class Employee with the following requirements:

Attribute
Hourly rate
Default argument and argument contructors
Public methods
get and set
The method monthlyEarning returns monthly salary (hourly rate times 160)
putData that displays the following information:
ID Employee number :_________
Employee name: __________
Birth date: _______
Full Time
Monthly Salary: _________
Implement a class Education with the following requirements:

Attributes
Degree (MS or PhD )
Major (Engineering, Chemistry, English, etc ... )
Research (number of researches)
Default argument and argument constructors.
Public methods
get and set
Implement a class Faculty extending from the class Employee with the following requirements:

Attributes
Level (use enum statement)
"AS": assistant professor
"AO": associate professor
"FU": professor
Education object
Default argument and argument constructor
Public methods
get and set
The method monthlyEarning returns monthly salary based on the faculty's level.
AS - faculty monthly salary
AO - 1.2 times faculty monthly salary
FU - 1.4 times faculty monthly salary
putData that displays the following information:
ID Employee number :_________
Employee name: __________
Birth date: _______
XXXXX Professor where  XXXXX can be Assistant, Associate or Full
Monthly Salary: _________
Implement a class called Partime extending from the class Staff with the following requirements:

Attributes
Hours worked per week
Default argument and argument constructors
Public methods
set and get
The method monthlyEarning returns monthly salary which hourly rate multiplied hours worked per week multiplied four.
putData that displays the following information:
ID Employee number :_________
Employee name: __________
Birth date: _______
Hours works per month: ______
Monthly Salary: _________
Implement a test driver program that creates a vector of class Employee to store the objects Staff, Faculty and Partime.

Using polymorphism, display the following outputs:

a. Employee information using the method putData. 

All employees 10 points Due date: 10/22 (only this part)
Staff
Faculty
Part-time
b. Total monthly salary for all the part-time staff .
c. Total monthly salary for all employees.

Test Data (Input data)

Staff

Last name:  Allen
First name: Paita
ID: 123
Sex: M
Birth date: 2/23/59
Hourly rate: $50.00
Last name: Zapata
First Name: Steven
ID: 456
Sex: F
Birth date: 7/12/64
Hourly rate: $35.00
Last name:Rios
First name:Enrique
ID: 789
Sex: M
Birth date: 6/2/70
Hourly rate: $40.00
Faculty

Last name: Johnson
First name: Anne
ID: 243
Sex: F
Birth date: 4/27/62
Level: Full
Degree: Ph.D
Major: Engineering
Reseach: 3
Last name: Bouris
First name: William
ID: 791
Sex: F
Birth date: 3/14/75
Level: Associate
Degree: Ph.D
Major: English
Reseach: 1
Last name: Andrade
First name: Christopher
ID: 623
Sex: F
Birth date: 5/22/80
Level: Assistant
Degree: MS
Major: Physical Education
Research: 0
Part-time

Last name: Guzman
First name: Augusto
ID: 455
Sex: F
Birth date: 8/10/77
Hourly rate: $35.00
Hours worked per week: 30
Last name: Depirro
First name: Martin
ID: 678
Sex: F
Birth date: 9/15/87
Hourly rate: $30.00
Hours worked per week:15
Last name: Aldaco
First name: Marque
ID: 945
Sex: M
Birth date: 11/24/88
Hourly rate: $20.00
Hours worked per week: 35
