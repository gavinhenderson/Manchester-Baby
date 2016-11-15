#include <iostream>
#include "Baby.h"

Baby::Baby(){
	controlInstruction = 0;
}

void Baby::incrementCI(){
	controlInstruction ++;
}

void Baby::fetch(){
	presentInstruction = store[controlInstruction]
}

void Baby::decode(){
	//Daniel to do
	
	//Take in presentInstruction and split it into the operator and operand
}

void Baby::execute(){
	switch(function){
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