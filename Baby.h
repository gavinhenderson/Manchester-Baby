#include <iostream>

#ifndef _BABY_H
#define _BABY_H

using namespace std;

class Baby{
	public:
		//Converts a decimal to a string of desired length
		static string decToBin(signed long dec, int length);

		//Converts a string binary no to decimal number
		static signed long binToDec(string bin);

		//takes in a binary string and returns the negated version
		static string negate(string neg);

		//Takes in a filepath and a store to load
		//Returns true if successful and false otherwise
		static bool getStore(string fileName, string* store);

		//Takes in a string and returns the reversed version
		static string reverseString(string rev);

		//Takes in a binary string and returns the opcode
		static int getOpcode(string myInstruction);

		//Takes in a binary string and returns the operand
		static int getOperand(string myInstruction);

		//Takes in a binary string and returns padded 32 bit string
		static string padString(string pad);
};

#endif