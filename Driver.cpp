#include <iostream>
#include "Employee.h"
#include "Staff.h"
#include "Faculty.h"
#include "Partime.h"
#include "Constants.h"
#include <vector>

using namespace std;

int main(){
Staff *s1 = new Staff("Allen", "Paita", "123", M, "2/23/59", 50.00);
s1->putData();

Staff *s2 = new Staff("Zapata", "Steven", "456", F, "7/12/64", 35.00);
s2->putData();

Staff *s3 = new Staff("Rios", "Enrique", "789", M, "6/2/70", 40.00);
s3->putData();

// // Faculty(string lastname, string firstname, string id, Sex s, string birthdate, Level l, string d, string m, int r);
// Faculty *f1 = new Faculty("Johnson","Anne","243", F, "4/27/62", FU, "Ph.D", "Engineering", 3);
// f1->putData();

// Partime(string lastName, string firstName, string id, Sex s, string birthDate, double r, int weekHours);
Partime *p1 = new Partime("Guzman", "Augusto", "455", F, "8/10/77", 35.00, 30);
p1->putData();

Partime *p2 = new Partime("Depirro", "Martin", "678", F, "9/15/87", 30.00, 15);
p1->putData();

Partime *p3 = new Partime("Aldaco", "Marque", "945", M, "11/24/88", 20.00, 35);
p1->putData();
}
