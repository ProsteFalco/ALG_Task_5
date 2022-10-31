#include "FileManager.h"
#include <iostream>
#include <fstream>

std::vector<char> FileManager::GetDataFromFile(std::string filename)
{
	std::ifstream MyFile; // creating file object
	
	MyFile.open(filename); //opening file object to reading


	//if file doesn't exist returns empty vector with error message
	if (!MyFile) { 
		std::cout << "Invalid file name!";
		return std::vector<char>();
	}

	std::vector<char> input;
	char inputChar;

	while (!MyFile.eof()) { //reading until file doesn't end (EOF = end of file)
		MyFile >> inputChar; //input one character to inputChar variable
		input.push_back(inputChar); //assign value to new index of vector
	}

	MyFile.close(); //closing file
	return input; //returning vector
}
