#include <iostream>
#include "CountingSort.h"
#include "FileManager.h"
#include <vector>


int main(int argc, char** argv)
{
    FileManager f; //instance of FileManager
    CountingSort c; //instance of CountingSort

    std::string file = argv[1]; //taking 1st argument as name of the file
    std::vector<char> cArray = f.GetDataFromFile(file); //reading from file and saving to vector array

    srand(time(0)); //setting "true random"
    
    //creation of three different-sized vector arrays for distributionSort
    std::vector<int> dArraySmall; 
    std::vector<int> dArrayMedium; 
    std::vector<int> dArrayLarge;
    
    //filling vectors with random values
    for (int i = 0; i < 100; i++) {
        dArraySmall.push_back(rand() % 9 + 1);
    }

    for (int i = 0; i < 1000; i++) {
        dArrayMedium.push_back(rand() % 9 + 1);
    }

    for (int i = 0; i < 10000; i++) {
        dArrayLarge.push_back(rand() % 9 + 1);
    }

    
    //sorting all vectors 
    std::vector<int> sortedDArraySmall = c.DistributionCountingSort(dArraySmall, 1, 9);
    std::vector<int> sortedDArrayMedium = c.DistributionCountingSort(dArrayMedium, 1, 9);
    std::vector<int> sortedDArrayLarge = c.DistributionCountingSort(dArrayLarge, 1, 9);


    //printout of sorted vectors
    std::cout << "Small array sorted: \n";
    for (int i = 0; i < sortedDArraySmall.size(); i++) {
        std::cout << sortedDArraySmall[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Medium array sorted: \n";
    for (int i = 0; i < sortedDArrayMedium.size(); i++) {
        std::cout << sortedDArrayMedium[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Large array sorted: \n";
    for (int i = 0; i < sortedDArrayLarge.size(); i++) {
        std::cout << sortedDArrayLarge[i] << " ";
    }
    std::cout << std::endl;


    //sorting of file vector
    std::vector<char> sortedCArray = c.ComparisonCountingSort(cArray);

    //calling SaveDataToFile function to save sorted array
    bool saved = f.SaveDataToFile("Output.txt", sortedCArray);
    if (saved)
        std::cout << "Successfully saved!";

}
