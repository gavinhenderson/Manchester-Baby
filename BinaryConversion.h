#include <iostream>

#ifndef _BINARY_H
#define _BINARY_H

using namespace std;

class BinaryConversion{
	private:
		string binaryString;
		int binaryInt;
	public:
		void BinaryConversion(int myInt);
		void BinaryConversion(string myString);
		string getBinaryString();
		int getBinaryInt();
}

#endif