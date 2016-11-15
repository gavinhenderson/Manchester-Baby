#include <iostream>

#ifndef _BINARY_H
#define _BINARY_H

using namespace std;

class BinaryConversion{
	private:
		string binaryString;
		int binaryInt;
	public:
		//Constructor that will create a binary conversion and convert the int
		//that is passed in and save the result to binaryString
		void BinaryConversion(int myInt);
		
		//Constructor that will create a binary conversion and convert the string
		//that is passed in and save the result to int
		void BinaryConversion(string myString);
		
		//Returns the binaryString
		string getBinaryString();
		
		//Returns the binaryInt
		int getBinaryInt();
}

#endif