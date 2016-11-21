#ifndef _VAR_H
#define _VAR_H

#include <iostream>
#include <string>
#include "Baby.h"
using namespace std;

class Line{
	private:
		string operandString;
		string opcodeString;
		string binary;
		string label;
		int lineNo;
		int operandInt;
		string opcodeBin;
		string operandBin;
	public:
		//constructor that initiates all the variables
		Line();
		
		//Getters and Setters
		string getLabel();
		void setLineNo(int i);
		int getLineNo();
		
		//Figures out what the binary equivalent is
		void setBinary(Line lines[32]);
		
		//string splitter
		void splitString(string line);
		
		//Display the lines info
		void displayTest();
	
		//destructor
		~Line();
};

#endif