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

void Assembler::assemble()
{
	for(int i=0; i<32; i++)
	{
		if(store[i].size()>0)
		{
			lineStore[i] = new Line();
			lineStore[i]->setLineNo(i);
			lineStore[i]->splitString(store[i]);
			lineStore[i]->setBinary(*lineStore);
		}
	}
}

int main()
{
	//Create our assembler
	Assembler* assemb = new Assembler();
	
	//read in code from file to store
	assemb->readInCode("Assembler.txt");
	
	//Assemble file
	assemb->assemble();
	
	//Display our assembler
	assemb->displayTest();
	
	//delete instance of assembler
	delete assemb;
	return 0;
}