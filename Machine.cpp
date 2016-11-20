#include <iostream>
#include "Machine.h"

//Constructor for the machine that takes in the file name to load to the store
Machine::Machine(string fileName){
	//Loads the store with the given filename
	runBaby = Baby::getStore(fileName, store);
	
	//Prints the store line by line
	for(int i=0; i<32; i++){
		if(store[i]!=""){
			cout << "Line " << i << ": " << store[i] << "\n";
		}
	}
	
	//Initialises the variables
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
	
	//Saves control instruction to be printed later
	string startingCI = controlInstruction;
	
	//Convertst the control instruction to a signed long then
	//increment it
	signed long CI = Baby::binToDec(controlInstruction);
	CI++;
	
	//Convert it back to a string and save it as the control instruction
	controlInstruction = Baby::decToBin(CI,32);
	
	//Display it in a meaningful way
	cout << CI-1 << " >> " << CI << "\n";
	cout << startingCI << " >> " << controlInstruction << "\n"
	cout << "\n";
}

//Gets the present instrction from the store.
//Returns false if the control instruction is negative
//otherwise return true
bool Machine::fetch(){
	cout << "----------- FETCH -------------\n";
	
	//Convert the control instruction into a signed long
	signed long CI = Baby::binToDec(controlInstruction);
	
	//If its 0 or less returns false which triggers the program to stop
	if(CI<=0){
		return false;
	}
	
	//Gets the present instruction from the store and saves it in a meaningful way
	presentInstruction = store[CI];
	cout << "Present Instruction: " << presentInstruction << "\n";
	cout << "\n";
	return true;
}

//Take out the operand and operator of the current instruction
void Machine::decode(){
	cout << "----------- Decode -------------\n";
	
	//Get the opcode and operand from the present instruction and
	//save them
	operand = Baby::getOperand(presentInstruction);
	opcode = Baby::getOpcode(presentInstruction);
	
	//Display it in a meaningful way
	cout << "Opcode: " << opcode << "\n";
	cout << "Operand: " << operand << "\n";
	cout << "\n";
}

//Ececute the current command
//return false if the loop is to stop
//return true otherwise
bool Machine::execute(){
	cout << "----------- Execute -------------\n";
	
	//Switch statement to find the right command to run
	switch(opcode)
	{
		case 0:
		{
			//JMP
			cout << "JMP\n";
			
			//Set the control instruction equal to what ever is in the
			//store[operand] line
			controlInstruction = store[operand];
			
			//Display that in a meaningful way
			cout << "Control Instruction: " << controlInstruction << " = " << Baby::binToDec(controlInstruction) << "\n";
			break;
		}
		case 1:
		{
			//JRP
			cout << "JRP\n";
			
			//Convert the control instruction and the number stored in store[operand]
			//to signed longs then add store[operand] to the control instruction
			signed long CI = Baby::binToDec(controlInstruction);
			string operandString = store[operand];
			signed long operandNo = Baby::binToDec(operandString);
			cout << CI << "\n";
			CI += operandNo;
			cout << operandNo << "\n";
			
			//Convert the control instruction back to binary and save it to the control instruction
			controlInstruction = Baby::decToBin(CI,32);
			
			//Display the process to the user
			cout << "Control Instruction: " << controlInstruction << " = " << Baby::binToDec(controlInstruction) << "\n";
			break;
		}
		case 2:
		{
			//LDN
			cout << "LDN\n";
			cout << "Store was: " << store[operand] << "\n";
			
			//negate the the store[operand] then save it to the accumulator
			acc = Baby::negate(store[operand]);
			
			//Display the process
			cout << "Accumulator is: " << acc << "\n";
			break;
		}
		case 3:
		{
			//STO
			cout << "STO\n";
			
			//Store the accumulator to the store
			store[operand] = acc;

			//Print the store again
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
			
			//Create the new accumulator by subtracting whats at the store from it
			signed long newAcc = (Baby::binToDec(acc) - Baby::binToDec(store[operand]));
			
			//Display the subtraction
			cout << Baby::binToDec(acc) << " - " << Baby::binToDec(store[operand]) << "\n";
			
			//Save the accumulator
			acc = Baby::decToBin(newAcc,32);
			
			//Display the new accumulator
			cout << "Accumulator is: " << acc << "\n";
			break;
		}
		case 6:
		{
			//CMP
			cout << "CMP\n";
			
			//If the accumulator is less that 0 increment the control instruction
			if(Baby::binToDec(acc)<0){
				incrementControl();
			}
			break;
		}
		case 7:
		{
			//Returns false to stop the execution loop
			return false;
			break;
		}
	}
	cout << "\n";
	
	//Return true to let the loop know that it should continues
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