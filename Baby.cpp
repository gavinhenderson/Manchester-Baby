#include <iostream>
#include <algorithm>
#include "Baby.h"

Baby::Baby(){
	controlInstruction = 0;
}

void Baby::incrementCI(){
	controlInstruction ++;
}

void Baby::fetch(){
	presentInstruction = store[controlInstruction];
}

void Baby::decode(){
	presentInstruction = "11100000000000100000000000000000";
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
		case 0:
			controlInstruction = operand;
			break;
		case 1:
			controlInstruction += operand;
			break;
		case 2:
			
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
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