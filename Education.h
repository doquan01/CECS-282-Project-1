#ifndef Education_H
#define Education_H

#include <iostream>

using namespace std;

class Education{
	public:
		void setDegree(string d);
		void setMajor(string m);
		void setResearch(int r);
		
		string getDegree();
		string getMajor();
		int getResearch(); 
		
		Education();
		Education(string d, string m, int r);
	protected:
		string Degree;
		string Major;
		int Research;
};
#endif
