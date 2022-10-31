#include <iostream>
#include <vector>

class CountingSort
{
public:
	template <typename T>
	std::vector<T> ComparisonCountingSort(std::vector<T> inputArray);
	std::vector<int> DistributionCountingSort(std::vector<int> inputArray, int l , int u);
};

//template method for ComparisonCountingSort based on pseudocode
template<class T>
inline std::vector<T> CountingSort::ComparisonCountingSort(std::vector<T> inputArray)
{
	std::vector<T> outputArray;
	std::vector<T> countArray;

	for (int i = 0; i < inputArray.size(); i++) {
		countArray.push_back(0);
	}
	for (int i = 0; i < inputArray.size(); i++) {
		outputArray.push_back(0);
	}

	for (int i = 0; i < (inputArray.size() - 1); i++) {
		for (int j = i + 1; j < inputArray.size(); j++) {
			if (inputArray[i] < inputArray[j])
				countArray[j] = countArray[j] + 1;
			else
				countArray[i] = countArray[i] + 1;
		}
	}

	for (int i = 0; i < inputArray.size(); i++) {
		outputArray[countArray[i]] = inputArray[i];
	}

	return outputArray;
}
