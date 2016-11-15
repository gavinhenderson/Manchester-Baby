#include <iostream>
#include "BinaryConversion.h"

#ifndef _BABY_H
#define _BABY_H

using namespace std;

class Baby{
	private:
		string store[32];
		int Accumulator;
		int controlInstruction;
		string presentInstruction;
		int operand;
		int opcode;
		int result;
	public:
		//Constructor
		Baby();
		
		//Increment the CI by 1
		void incrementCI();
	
		//Run the function on the operand
		void execute();
		
		//Will get the next instruction in the store and
		//set it to the present instruction
		void fetch();
				
		//Will take the presentIntstruction and put the operand and function
		//stored in them and save them to the class. This will use string
		//manipulation and the binary conversion class
		void decode();
		
		//Displays the current happenings of the baby
		void displayStatus();
};

#endif
