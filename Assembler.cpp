/*
Manchester Baby - AC21009
Team 5
Daniel Kelly: 150024764 
Gavin Henderson: 150010848
Conor King: 150024944
William Doherty: 150019622
*/

#include "Assembler.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iterator>
#include <string>
using namespace std;

//function which opens a file from a string parameter, and reads its contents into the store
void Assembler::readInCode(string fileName)
{
	//set up local variables
	char delimiter(';');
	fstream myfile;
	int i=0;
	string line;
	
	//open a file from user parameter
	myfile.open(fileName.c_str(), ios::out | ios::in );
	
	//loop through file, storing the contents of each line to the store
	if (myfile.is_open()){
  		while(getline(myfile, line)){
  			if(line[0]!=';')
  			{
  				line = line.substr(0, line.find(delimiter)+1);
				store[i] = line;
				i++;
			}
    	}
    	
    //close the file
    myfile.close();
  	}
  	
  	//error handling if file does not exist
  	else{
    cout << "Unable to open file" << endl;
  	}
}

//Displays the information in assembler for debugging and testing purposes
void Assembler::displayTest(){
	for(int i=0; i<32; i++)
	{
		//only try to store data into variable if line is not empty
		if((store[i].size())>0)
		{
			//print line number, label, instruction and operand
			cout << "Line: " << lineStore[i]->getLineNo() << endl;
			lineStore[i]->displayTest();
			cout << endl;
		}
	}
}

//constructor - fills lineStore array with instances of line 
void Assembler::assemble()
{
	for(int i=0; i<32; i++)
	{
		//create a new instance of line and fill it with variables from strings taken from store array
		if(store[i].size()>0)
		{
			lineStore[i] = new Line();
			lineStore[i]->setLineNo(i);
			lineStore[i]->splitString(store[i]);
			//lineStore[i]->displayTest();

		}
	}

	for(int i=0; i<32; i++){
		if(store[i].size()>0)
		{
			saveBinary(lineStore[i]);
		}
	}
	
}

//function which constructs binary strings from a parameter of an instance of line
//then passes the binary string to the writeToFile function
void Assembler::saveBinary(Line* line)
{
	//find binary representation for the instruction
	if(line->getOpcodeString() == "JMP")
	{
		line->setOpcodeBin("000");
	}
	if(line->getOpcodeString() == "JRP")
	{
		line->setOpcodeBin("100");
	}
	if(line->getOpcodeString() == "LDN")
	{
		line->setOpcodeBin("010");
	}
	if(line->getOpcodeString() == "STO")
	{
		line->setOpcodeBin("110");
	}
	if(line->getOpcodeString() == "SUB")
	{
		line->setOpcodeBin("001");
	}
	if(line->getOpcodeString() == "CMP")
	{
		line->setOpcodeBin("110");
	}
	//if it is the STP instruction then it will be the last string wrote to the file
	//function will then prematurely end
	if(line->getOpcodeString() == "STP")
	{
		line->setOpcodeBin("111");
		line->setBinary("00000000000001110000000000000000");
		Baby::writeToFile(line->getBinary());
		cout << line->getBinary() << endl;
		return;

	}
	if(line->getOpcodeString() == "VAR")
	{
		line->setOpcodeBin("000");
	}

	//declare and initialise integer variable which checks line numbers
	int opInt = (-1);

	//compares to see where the operand which declares a variable equals the variable label of another line
	for(int i=0; i<32; i++)
	{
		if(store[i].size()>0){
			if((line->getOperandString()).compare(lineStore[i]->getLabel())==0)
			{
				//if operand equals label, store the line number of the variable 
				opInt = lineStore[i]->getLineNo();
			}
		}
	}

	//pass line number to the decToBin function and reverse the binary string you receive
	if(opInt!=-1){
		line->setOperandBin(Baby::reverseString(Baby::decToBin(opInt,13)));
	}else{
		opInt = Baby::strToInt(line->getOperandString());
		line->setOperandBin(Baby::reverseString(Baby::decToBin(opInt,13)));
	}

	//create the binary string from the converted components
	line->setBinary(line->getOperandBin() + line->getOpcodeBin() + "0000000000000000");
	cout << line->getBinary() << endl;
	//pass the binary string to the writeToFile function
	Baby::writeToFile(line->getBinary());
}

//destructor - loops through line store and deletes instances of line
Assembler::~Assembler()
{
	for(int i=0; i<32; i++)
	{
		delete lineStore[i];
	}
}

int main()
{
	//Create our assembler
	Assembler* assemb = new Assembler();
	
	//call the function which will clean the Assembled.txt file of any contents
	Baby::cleanFile();

 	string input;
 	cout << "Enter a file name of assembly code file: ";
 	getline(cin, input);

	//read in code from file to store
	assemb->readInCode(input);
	
	//Assemble file
	assemb->assemble();
	
	//Display our assembler
	//assemb->displayTest();
	
	//delete instance of assembler
	delete assemb;
	return 0;
}