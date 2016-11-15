#include <iostream>
#include <string>
#include <cstdlib>
#include "BinaryConversion.h"
using namespace std;

// constructor
BinaryConversion::BinaryConversion()
{
  binaryInt = 0;
  binaryString = "";
}

// destructor
BinaryConversion::~BinaryConversion()
{

}

// method to convert decimal to binary
void BinaryConversion::decimalConversion(long decimal, char *binary)
{
    // variables
      int k = 0;
      int n = 0;
      int remain;
      char temp[80];

      // If user enters a negative number, prompts user to enter a positive number instead
      // and exits the program
      if (decimal < 0)
      {      
        cout << " Please enter a positive number." << endl;
        exit(0);
      }

      do 
      { 
        remain = decimal%2;
        decimal = decimal/2;
        // Converts 0 or 1 to char
        temp[k] = remain + '0';
        k++;
      } while (decimal > 0);

      // null terminator
      temp[k++] = '\0';

      while (k >= 0)
        binary[n++] = temp[--k];
      binary[n-1] = 0;

      binaryString = temp;
}

// converts binary to decimal
unsigned BinaryConversion::binaryConversion(string &bin)
{
    unsigned result=0;
    for (unsigned a=0;a<bin.size();a++){
        if (bin[a]!='0' && bin[a]!='1')
            continue;
        result<<=1;
        result|=bin[a]-'0';
    }

    binaryInt = result;

    return result;
} 


// Returns binaryString
string BinaryConversion::getBinaryString()
{
  return binaryString;
}

// Returns binaryInt
int BinaryConversion::getBinaryInt()
{
  return binaryInt;
}

/*
int main()
{
    BinaryConversion* binCon = new BinaryConversion();
    string bin;
    char binary[80];

    //4294967295
    binCon->decimalConversion(4294967295, binary);
    cout << binCon->getBinaryString() << endl;

    cout << "Please input a binary number (up to "<<(sizeof(unsigned)*8)<<" bits): ";
    getline(cin, bin);
    cout << "The result is: " << binCon->binaryConversion(bin) << endl;

    cout << binCon->getBinaryInt() << endl;

    return 0;
}
*/