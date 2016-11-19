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
	//padded the string if its not 32 bits
	bin = padString(bin);

	//Runs if positive
	if(bin[0]=='0'){
		signed long total = 0;
		for(int i=0; i<32; i++){
			if(bin[i]=='1')
			{
				total += pow(2,(31-i));
			}
		}
		return total;
	//Runs if negative
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
	//Converts given string to number
	signed long negNo = Baby::binToDec(neg);

	//Gets the negitve of the number given
	negNo = negNo*(-1);

	//Converts that back to string and returns it
	neg = Baby::decToBin(negNo,32);
	return neg;
}

//takes in a file name and a pointer to the store that is to be loaded
bool Baby::getStore(string fileName, string* store){
	//Creates a file and opens the given filename
	fstream myFile;
	int i=0;
	myFile.open(fileName.c_str(), ios::out | ios::in);
	string currentLine;

	//Reads each line if it exists and return true
	if(myFile.is_open()){
		while(getline(myFile, currentLine)){
			store[i] = currentLine;
			store[i] = store[i].substr(0,32);
			store[i] = reverseString(store[i]);
			i++;
		}
		myFile.close();
		return true;
	//Lets user know it doesnt exist and then return false
	}else{
		cout << "File not found\n";
		return false;
	}
}

//reverses the string it is given
string Baby::reverseString(string rev){
	string temp;
	//Loops through the given string backwards and saves it to the
	//new string
	for(int i=rev.size(); i>0; i--){
		temp += rev[i-1];
	}
	return temp;
}

//Given an instruction and pulls out the opcode and returns it
int Baby::getOpcode(string myInstruction){
	//Uses substring to get the needed but of code
	string opcodeString = myInstruction.substr(16,3);

	//Pads that string
	opcodeString = Baby::padString(opcodeString);

	//Converts it to a number and returns it
	signed long opcode = Baby::binToDec(opcodeString);
	return opcode;
}

//Given an instruction and pulls out the operand and returns it
int Baby::getOperand(string myInstruction){
	//Uses substring to get the needed bit of code
	string operandString = myInstruction.substr(27,5);

	//Pads the string
	operandString = padString(operandString);

	//Converts it to a number and returns it
	signed long operand = Baby::binToDec(operandString);
	return operand;
}

//Sets a binary string that is less than 32 to its 32 equivalent.
string Baby::padString(string pad){
	string newString = "00000000000000000000000000000000";

	//Adds the given string to the 'newString'
	for(int i=0; i<pad.size(); i++){
		newString[32-pad.size()+i] = pad[i];
	}
	return newString;
}