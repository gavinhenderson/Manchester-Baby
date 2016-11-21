/*
Manchester Baby - AC21009
Team 5
Daniel Kelly: 150024764 
Gavin Henderson: 150010848
Conor King: 150024944
William Doherty: 150019622
*/

#include <iostream>
#include <string>
#include <sstream>
#include "Line.h"
using namespace std;

//constructor
Line::Line()
{
	operandString = "";
	opcodeString = "";
	binary = "";
	label = "";
	lineNo = 0;
	operandInt = 0;
	opcodeBin = "";
	operandBin = "";
}

//test function that displays the components of the string
void Line::displayTest(){
	cout << lineNo << endl;
	cout << label << endl;
	cout << opcodeString << endl;
	cout << operandString << endl;
	cout << endl;
}

//getters and setters
string Line::getBinary(){
	return binary;
}

void Line::setBinary(string newBin){
	binary = newBin;
}

void Line::setOperandBin(string newOperandBin){
	operandBin = newOperandBin;
}

string Line::getOperandString(){
	return operandString;
}

int Line::getLineNo(){
	return lineNo;
}

string Line::getOpcodeString(){
	return opcodeString;
}

void Line::setOpcodeString(string newOpcodeString){
	opcodeString = newOpcodeString;
}

string Line::getLabel(){
	return label;
}

void Line::setLabel(string newLabel){
	label = newLabel;
}

void Line::setOpcodeBin(string newOpcodeBin){
	opcodeBin = newOpcodeBin;
}

void Line::setLineNo(int newLineNo){
	lineNo = newLineNo;
}

string Line::getOpcodeBin(){
	return opcodeBin;
}

string Line::getOperandBin(){
	return operandBin;
}

//function which splits a string from a parameter into its compenents
void Line::splitString(string line)
{
	//State what we are using as the delimiter of the string
	char delimiter(':');
	string smallLine = "";

	if(line[0] !=';')
	{
		line = line.substr(0, line.find(';'));
		//get the label from the string and remove it from the read in line
		if(line[0]!=' ')
		{
			label = line.substr(0, line.find(delimiter));
			line = line.substr(label.size()+1, line.size());
		}

		//remove all spaces from the line and store it in the smallLine var
		for (int i = 0; i < line.size(); i++)
		{
			if(line[i]!=' ')
			{
				smallLine += line[i];
			}
		}

		//read the instruction from smallLine and store in instruct var
		for(int i=0; i<3; i++)
		{
			opcodeString += smallLine[i];
		}

		//remove instruction from smallLine
		smallLine = smallLine.substr(3,line.size());

		//remove the semicolon from the end of the small line
		//this is the operand of the line
		smallLine = smallLine.substr(0, smallLine.size());
		operandString = smallLine.substr(0, line.find(';'));
	}
}
	
//destructor
Line::~Line()
{

}