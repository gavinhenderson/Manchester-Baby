/*
Manchester Baby - AC21009
Team 5
Daniel Kelly: 150024764 
Gavin Henderson: 150010848
Conor King: 150024944
William Doherty: 150019622
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
#include "Baby.h"
#include "Line.h"

#ifndef _ASSEMBLER_H
#define _ASSEMBLER_H

using namespace std;

class Assembler
{
	private:
		string file;
		string store[32];
		Line* lineStore[32];

	public:
		//Reads in the code from a specific file name and saves it to the
		//32 string array called store
		void readInCode(string fileName);

		//Displays the information in assembler for debugging and testing purposes
		void displayTest();

		//Loops through the line store and triggers them to figure out there binary
		//versions of themselves
		void assemble();

		//function which constructs binary strings from a parameter of an instance of line
		//then passes the binary string to the writeToFile function
		void saveBinary(Line* line);

		//destructor
		~Assembler();
};

#endif