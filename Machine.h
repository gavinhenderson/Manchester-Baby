/*
Manchester Baby - AC21009
Team 5
Daniel Kelly: 150024764 
Gavin Henderson: 150010848
Conor King: 150024944
William Doherty: 150019622
*/

#include <iostream>
#include "Baby.h"

#ifndef _MACHINE_H
#define _MACHINE_H

using namespace std;

class Machine{
	private: 
		//Whether or not the baby should run
		bool runBaby;

		//Machines memory store
		string store[32];

		//The machines accumulator
		string acc;

		//The control instruction
		string controlInstruction;

		//The present instruction
		string presentInstruction;

		//The current operand and opcode
		int operand;
		int opcode;
	public:
		//Constructor that loads the store as it is created
		Machine(string fileName);

		//Run the fetch-execute cyle;
		void runMachine();

		//Adds one to the control instruction
		void incrementControl();

		//Gets the present instrction from the store.
		//Returns false if the control instruction is negative
		//otherwise return true
		bool fetch();

		//Take out the operand and operator of the current instruction
		void decode();

		//Ececute the current command
		//return false if the loop is to stop
		//return true otherwise
		bool execute();
};

#endif