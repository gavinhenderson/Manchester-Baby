#include <iostream>

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
		int function;
	public:	
		//Run the function on the operand
		void execute();
		
		//Will get the next instruction in the store and
		//set it to the present instruction
		void fetch();
				
		//Will take the presentIntstruction and put the operand and function
		//stored in them and save them to the class. This will use string
		//manipulation and the binary conversion class
		void decode();
}

#endif
