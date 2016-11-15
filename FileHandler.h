#include <iostream>

#ifndef _FILEHANDLER_H
#define _FILEHANDLER_H

using namespace std;

class FileHandler
{
	private:
		string store[32];
	public:
		//Reads in the code from a specific file name and saves it to the
		//32 string array called store
		void readInCode(string fileName);
		
		//returns the code that was read
		string* getStore();
};

#endif
