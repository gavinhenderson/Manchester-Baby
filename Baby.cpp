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
	presentInstruction = "10010110100101101001011010010110";




	string buffer;
	stringstream ss(presentInstruction);
	vector<string> part;
	while(ss>>buffer){
		part.push_back(buffer);

	}
	for(vector<char>::const_iterator i = part.begin(); i != part.end(); i++){
		cout << *i << ' ';
	}
/*
	cout << operand;
	cout << "\n";
	cout << function;
	*/
}

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