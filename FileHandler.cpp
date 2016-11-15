#include <iostream>
#include <string>
#include <fstream>
#include "FileHandler.h"
using namespace std;

//constructor
FileHandler::FileHandler()
{

}

//Reads in the code from a specific file name and saves it to the
//32 string array called store
void FileHandler::readInCode(string fileName)
{
	fstream myfile;
  int i=0;
  myfile.open(fileName.c_str(), ios::out | ios::in );
	string line;
  if (myfile.is_open())
  {
    while(getline(myfile, line))
    {
      store[i] = line;
      i++;
    }
    myfile.close();
  }

  else
  {
    cout << "Unable to open file" << endl;
  }

}

//returns the code that was read
string* FileHandler::getStore()
{

  return store;
}

//destructor
FileHandler::~FileHandler()
{

}

/*
//tester main for file
int main ()
{
  //declare file to open
  string file;
  file = "BabyTest1-MC.txt";

  //declare instance of class
  FileHandler* fileHandle = new FileHandler();

  //read code into class from filename
  fileHandle->readInCode(file);
  
  //print store from class instance
  for(int i = 0; i < 32; i++)
  {
    cout << fileHandle->getStore() << endl;
  }

  //call destructor on fileHandle instance
  delete fileHandle;

  return 0;
}
*/
