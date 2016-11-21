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

void Line::displayTest(){
	cout << lineNo << endl;
	cout << label << endl;
	cout << opcodeString << endl;
	cout << operandString << endl;
	cout << endl;
}

string Line::getLabel(){
	return label;
}

void Line::setLineNo(int i){
	lineNo = i;
}

int Line::getLineNo(){
	return lineNo;
}

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

void Line::setBinary(Line lines[32])
{
	if(opcodeString == "JMP")
	{
		opcodeBin = "000";
	}
	if(opcodeString == "JRP")
	{
		opcodeBin = "100";
	}
	if(opcodeString == "LDN")
	{
		opcodeBin = "010";
	}
	if(opcodeString == "STO")
	{
		opcodeBin = "110";
	}
	if(opcodeString == "SUB")
	{
		opcodeBin = "001";
	}
	if(opcodeString == "CMP")
	{
		opcodeBin = "110";
	}
	if(opcodeString == "STP")
	{
		opcodeBin = "111";
	}
	if(opcodeString == "VAR")
	{
		opcodeBin = "000";
	}

	int opInt = -1;

	for(int i=0; i<32; i++)
	{
		if(operandString.compare(lines[i].getLabel())==0)
		{
			operandInt = lines[i].getLineNo();
		}
	}

	if(opInt!=-1){
		operandString = Baby::reverseString(Baby::decToBin(operandInt,13));
	}else{
		operandInt = Baby::strToInt(operandString);
		operandBin = Baby::reverseString(Baby::decToBin(operandInt,13));
	}

	binary = operandBin + opcodeBin + "0000000000000000";
	cout << binary << endl;
	//Baby::writeToFile(binary, "Assembled.txt");
}
