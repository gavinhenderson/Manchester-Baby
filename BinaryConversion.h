#include <iostream>

#ifndef _BINARY_H
#define _BINARY_H

using namespace std;

class BinaryConversion{
	private:
		string binaryString;
		unsigned binaryInt;
	public:
		//Constructor that will create a binary conversion and convert the int
		//that is passed in and save the result to binaryString
		BinaryConversion(long decimal);
		
		//Constructor that will create a binary conversion and convert the string
		//that is passed in and save the result to int
		BinaryConversion(string bin);
		
		//Returns the binaryString
		string getBinaryString();
		
		//Returns the binaryInt
		unsigned getBinaryInt();
};

#endif
