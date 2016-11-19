#include <iostream>
#include "Machine.h"

Machine::Machine(string fileName){
	runBaby = Baby::getStore(fileName, store);
	for(int i=0; i<32; i++){
		if(store[i]!=""){
			cout << "Line " << i << ": " << store[i] << "\n";
		}
	}
	string accumulator = store[0];
	string controlInstruction = "00000000000000000000000000000000";
	string presentInstruction = "00000000000000000000000000000000";
	int operand = 0;
	int opcode = 0;
	cout << "\n";
}

//Run the fetch-execute cyle;
void Machine::runMachine(){
	while(runBaby){
		incrementControl();
		runBaby = fetch();
		decode();
		runBaby = execute();
	}
}

//Adds one to the control instruction
void Machine::incrementControl(){
	cout << "----------- INCREMENTING ---------------\n";
	signed long CI = Baby::binToDec(controlInstruction);
	CI++;
	controlInstruction = Baby::decToBin(CI,32);
	cout << CI-1 << " >> " << CI << "\n";
	cout << "\n";
}

//Gets the present instrction from the store.
//Returns false if the control instruction is negative
//otherwise return true
bool Machine::fetch(){
	cout << "----------- FETCH -------------\n";
	signed long CI = Baby::binToDec(controlInstruction);
	if(CI<=0){
		return false;
	}
	presentInstruction = store[CI];
	cout << "Present Instruction: " << presentInstruction << "\n";
	cout << "\n";
	return true;
}

//Take out the operand and operator of the current instruction
void Machine::decode(){
	cout << "----------- Decode -------------\n";
	operand = Baby::getOperand(presentInstruction);
	opcode = Baby::getOpcode(presentInstruction);
	cout << "Opcode: " << opcode << "\n";
	cout << "Operand: " << operand << "\n";
	cout << "\n";
}

//Ececute the current command
//return false if the loop is to stop
//return true otherwise
bool Machine::execute(){
	cout << "----------- Execute -------------\n";
	switch(opcode)
	{
		case 0:
		{
			//JMP
			cout << "JMP\n";
			controlInstruction = store[operand];
			cout << "Control Instruction: " << controlInstruction << " = " << Baby::binToDec(controlInstruction) << "\n";
			break;
		}
		case 1:
		{
			//JRP
			cout << "JRP\n";
			signed long CI = Baby::binToDec(controlInstruction);
			string operandString = store[operand];
			signed long operandNo = Baby::binToDec(operandString);
			cout << CI << "\n";
			CI += operandNo;
			cout << operandNo << "\n";
			controlInstruction = Baby::decToBin(CI,32);
			cout << "Control Instruction: " << controlInstruction << " = " << Baby::binToDec(controlInstruction) << "\n";
			break;
		}
		case 2:
		{
			//LDN
			cout << "LDN\n";
			cout << "Store was: " << store[operand] << "\n";
			acc = Baby::negate(store[operand]);
			cout << "Accumulator is: " << acc << "\n";
			break;
		}
		case 3:
		{
			//STO
			cout << "STO\n";
			store[operand] = acc;

			for(int i=0; i<32; i++){
				if(store[i]!=""){
					cout << "Line " << i << ": " << store[i] << "\n";
				}
			}

			break;
		}
		case 4:
		case 5:
		{
			//SUB
			cout << "SUB\n";
			cout << "Accumulator was: " << acc << "\n";
			signed long newAcc = (Baby::binToDec(acc) - Baby::binToDec(store[operand]));
			cout << Baby::binToDec(acc) << " - " << Baby::binToDec(store[operand]) << "\n";
			acc = Baby::decToBin(newAcc,32);
			cout << "Accumulator is: " << acc << "\n";
			break;
		}
		case 6:
		{
			//CMP
			cout << "CMP\n";
			if(Baby::binToDec(acc)<0){
				incrementControl();
			}
			break;
		}
		case 7:
		{
			return false;
			break;
		}
	}
	cout << "\n";
	return true;
}

int main(){
	cout << "Please enter the file name text file you want to read: ";
	string input;
	getline(cin, input);
	Machine* babyMachine = new Machine(input);
	babyMachine->runMachine();
	cout << "///////////////////////////////////////\n";
	cout << "////////////// STOP ///////////////////\n";
	cout << "///////////////////////////////////////\n";
	delete babyMachine;
}