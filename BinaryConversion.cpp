#include <iostream>
#include "BinaryConversion.h"

using namespace std;

//Constructor that takes in a long and coverts it to string
BinaryConversion::BinaryConversion(long decimal)
{
    //Initialise variables
    char binary[80];
	int k = 0;
	int n = 0;
    int remain;
    char temp[80];

    do{
		remain = decimal%2;
        decimal = decimal/2;
        // Converts 0 or 1 to char
        temp[k] = remain + '0';
        k++;
	}while (decimal > 0);

    // null terminator
    temp[k++] = '\0';

    while (k >= 0){
    	binary[n++] = temp[--k];
    }
    binary[n-1] = 0;
	binaryString = temp;
	
	//Reverse binaryString
	reverse(binaryString.begin(), binaryString.end());

}

//Constructor that takes in a binary number and converts it to an integer
BinaryConversion::BinaryConversion(string bin)
{
    unsigned result=0;
    for (unsigned a=0;a<bin.size();a++){
        if (bin[a]!='0' && bin[a]!='1')
            continue;
        result<<=1;
        result|=bin[a]-'0';
    }

    binaryInt = result;
} 

// Returns binaryString
string BinaryConversion::getBinaryString()
{
	return binaryString;
}

// Returns binaryInt
unsigned BinaryConversion::getBinaryInt()
{
	return binaryInt;
}

//TESTER

int main()
{
    BinaryConversion* binCon = new BinaryConversion("11111111111111111111111111111111");
    cout << binCon->getBinaryInt() << endl;
    
    BinaryConversion* binCon2 = new BinaryConversion(4294967295);
    cout << binCon2->getBinaryString() << endl;
    
    delete binCon;
    delete binCon2;
    
    return 0;
}
