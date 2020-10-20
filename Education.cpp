#include <iostream>
#include "Education.h"

using namespace std;

void Education::setDegree(string d){
	Degree = d;
}
void Education::setMajor(string m){
	Major = m;
}
void Education::setResearch(int r){
	Research = r;
}
string Education::getDegree(){
	return Degree;
}
string Education::getMajor(){
	return Major;
}
int Education::getResearch(){
	return Research;
} 
