/*
Manchester Baby - AC21009
Team 5
Daniel Kelly: 150024764 
Gavin Henderson: 150010848
Conor King: 150024944
William Doherty: 150019622
*/

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
		
		//converts string to integer
		static int strToInt(string in);

		//creates a text file from file parameter and then writes to it using line parameter
		static void writeToFile(string line);

		//function which cleans a file which the program will then write to
		static void cleanFile();
};

#endif