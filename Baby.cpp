#include <iostream>
#include <fstream>
#include <cmath>
#include "Baby.h"

using namespace std;

//Takes in a decimal number and the desiered length of string then
//returns the binary number as a string
string Baby::decToBin(signed long dec, int length){
	//The string that will be returned to the user
	string myBinary = "";

	//Catches the exception of the desired number being 0
	if(dec==0){
		myBinary = "00000000000000000000000000000000";
	//Runs if the number is positive
	}else if(dec>0){
		int mask = 1;
		for(int i=0; i<length; i++){
			if((mask&dec)>=1){
				myBinary = "1"+myBinary;
			}else{
				myBinary = "0"+myBinary; 
			}
			mask <<= 1;
		}
		return myBinary;
	//Runs if the number is negative
	}else if(dec<0){
		dec = dec*(-1);
		dec--;
		int mask = 1;
		for(int i=0; i<31; i++){
			if((mask&dec)>=1){
				myBinary = "1"+myBinary;
			}else{
				myBinary = "0"+myBinary; 
			}
			mask <<= 1;
		}

		myBinary = padString(myBinary);

		int i=0;
		while(myBinary[i]=='0'){
			myBinary[i]='1';
			i++;
		}

		for(int j=i; j<32; j++){
			if(myBinary[j]=='0'){
				myBinary[j] = '1';
			}
			else{
				myBinary[j] = '0';
			}
		}

		return myBinary;
	}
}

//Takes in a binary number of any length then returns the
//result as a signed long
signed long Baby::binToDec(string bin){
	bin = padString(bin);

	if(bin[0]=='0'){
		signed long total = 0;
		for(int i=0; i<32; i++){
			if(bin[i]=='1')
			{
				total += pow(2,(31-i));
			}
		}
		return total;
	}else{
		//Rewrite string without leading bit
		string newString = bin.substr(1,31);

		//Invert new string
		string inverted = "0000000000000000000000000000000";
		for(int i=0; i<newString.size(); i++){
			if(newString[i]=='0'){
				inverted[i] = '1';
			}else
			{
				inverted[i] = '0';
			}
		}

		//Convert inverted normally
		signed long total = 0;
		for(int i=0; i<31; i++){
			if(inverted[i]=='1')
			{
				total += pow(2,(30-i));
			}
		}

		total++;
		total = total*(-1);
		return total;
	}
}

//Takes in a binary string and returns the negative of the string
string Baby::negate(string neg){
	signed long negNo = Baby::binToDec(neg);
	negNo = negNo*(-1);
	neg = Baby::decToBin(negNo,32);
	return neg;
}

//takes in a file name and a pointer to the store that is to be loaded
bool Baby::getStore(string fileName, string* store){
	fstream myFile;
	int i=0;
	myFile.open(fileName.c_str(), ios::out | ios::in);
	string currentLine;
	if(myFile.is_open()){
		while(getline(myFile, currentLine)){
			store[i] = currentLine;
			store[i] = store[i].substr(0,32);
			store[i] = reverseString(store[i]);
			i++;
		}
		myFile.close();
		return true;
	}else{
		cout << "File not found\n";
		return false;
	}
}

//reverses the string it is given
string Baby::reverseString(string rev){
	string temp;
	for(int i=rev.size(); i>0; i--){
		temp += rev[i-1];
	}
	return temp;
}

//Given an instruction and pulls out the opcode and returns it
int Baby::getOpcode(string myInstruction){
	string opcodeString = myInstruction.substr(16,3);
	opcodeString = Baby::padString(opcodeString);
	signed long opcode = Baby::binToDec(opcodeString);
	return opcode;
}

//Given an instruction and pulls out the operand and returns it
int Baby::getOperand(string myInstruction){
	string operandString = myInstruction.substr(27,5);
	operandString = padString(operandString);
	signed long operand = Baby::binToDec(operandString);
	return operand;
}

//Sets a binary string that is less than 32 to its 32 equivalent.
string Baby::padString(string pad){
	string newString = "00000000000000000000000000000000";
	for(int i=0; i<pad.size(); i++){
		newString[32-pad.size()+i] = pad[i];
	}
	return newString;
}