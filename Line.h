/*
Manchester Baby - AC21009
Team 5
Daniel Kelly: 150024764 
Gavin Henderson: 150010848
Conor King: 150024944
William Doherty: 150019622
*/

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
		string getBinary();
		void setBinary(string newBin);
		void setOperandBin(string newOperandBin);
		string getOperandString();
		int getLineNo();
		string getOpcodeString();
		void setOpcodeString(string newOpcodeString);
		string getLabel();
		string getOpcodeBin();
		string getOperandBin();
		void setLabel(string newLabel);
		void setOpcodeBin(string newOpcodeBin);
		void setLineNo(int newLineNo);
		
		//string splitter
		void splitString(string line);
		
		//Display the lines info
		void displayTest();
	
		//destructor
		~Line();
};

#endif