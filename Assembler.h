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

		//Make sure we delete vars in linestore
		//Assembler();
};

#endif