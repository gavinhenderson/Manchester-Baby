#include <iostream>
#include <string>
#include <cstdlib>
#include "BinaryConversion.h"
using namespace std;

void BinaryConversion::decimalConversion(long decimal, char *binary)
{
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
        temp[k++] = remain + '0';
      } while (decimal > 0);

      while (k >= 0)
        binary[n++] = temp[--k];
      binary[n-1] = 0;
}

// converts binary to decimal
unsigned BinaryConversion::binaryConversion(string &bin)
{
    unsigned res=0;
    for (unsigned a=0;a<bin.size();a++){
        if (bin[a]!='0' && bin[a]!='1')
            continue;
        res<<=1;
        res|=bin[a]-'0';
    }
    return res;
}

string BinaryConversion::getBinaryString()
{
  return binaryString;
}

int BinaryConversion::getBinaryInt()
{
  return binaryInt;
}

