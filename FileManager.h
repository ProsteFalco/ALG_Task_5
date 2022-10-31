#pragma once
#include <iostream>
#include <vector>
#include <fstream>

class FileManager
{
public:
	std::vector<char> GetDataFromFile(std::string filename);
	template <typename T>
	bool SaveDataToFile(std::string filename, std::vector<T> data);
};

template<typename T>
inline bool FileManager::SaveDataToFile(std::string filename, std::vector<T> data)
{
	std::ofstream Myfile; //opening/creating file for writing

	Myfile.open(filename); //open file
	for (int i = 0; i < data.size(); i++) {
		Myfile << data[i];// writing data to file from vector
	}
	Myfile.close();//closing file

	return true;//returing true when file saved and closed
}
