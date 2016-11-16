#include <iostream>
#include <algorithm>
#include "Baby.h"

Baby::Baby(){
	controlInstruction = -1;
}

void Baby::incrementCI(){
	BinaryConversion* bin = new BinaryConversion(controlInstuction);
	int CiInt = bin->getBinaryInt();
	delete bin;
	
	CiInt++;
	
	BinaryConversion* bin = new BinaryConversion(CiInt);
	controlInstruction = bin->getBinaryString();
	delete bin;
}

void Baby::fetch(){
	presentInstruction = store[controlInstruction];
}

void Baby::decode(){
	string operandString = presentInstruction.substr(0,5);
	string opcodeString = presentInstruction.substr(13,3);
	reverse(operandString.begin(), operandString.end());
	reverse(opcodeString.begin(), opcodeString.end());
	BinaryConversion* binary1 = new BinaryConversion(operandString);
	BinaryConversion* binary2 = new BinaryConversion(opcodeString);
	operand = binary1->getBinaryInt();
	opcode = binary2->getBinaryInt();
	delete binary1;
	delete binary2;
}

void Baby::execute(){	
	switch(opcode){
		case 0: //JMP
			controlInstruction = store[operand];
			break;
		case 1:
			//JRP
			BinaryConversion* bin = new BinaryConversion(controlInstuction);
			int CiInt = bin->getBinaryInt();
			delete bin;
			CiInt+=operand;
			BinaryConversion* bin = new BinaryConversion(CiInt);
			controlInstruction = bin->getBinaryString();
			delete bin;
			break;
		case 2:
			accumulator = operand*(-1)
			break;
		case 3:
			operand = accumulator
			//LDN - load negative X into the accumulator

			break;
		case 3:
			//STO - store the result as S

			break;
		case 4:
			//SUB - Subtract Y from the value at the accumulator

			break;
		case 5:
			//CMP - skup to the next 
			break;
		case 6:
			break;
		case 7:
			break;
	}
}

int main(){
	Baby* baby = new Baby();
	baby->decode();
	return 0;
}