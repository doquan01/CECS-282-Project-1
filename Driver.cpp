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
}
