#include "CountingSort.h"
#include <iostream>
#include <vector>

//DistributionCountingSort based on pseudocode
std::vector<int> CountingSort::DistributionCountingSort(std::vector<int> inputArray, int l, int u)
{
	std::vector<int> outputArray;

	if (l > u)
		return outputArray;

	std::vector<int> distributionArray;

	for (int i = 0; i <= (u - l); i++) {
		distributionArray.push_back(0);
	}

	for (int i = 0; i < inputArray.size(); i++) {
		outputArray.push_back(0);
	}

	for (int i = 0; i < inputArray.size(); i++) {
		distributionArray[inputArray[i] - l] = distributionArray[inputArray[i] - l] + 1;

	}

	for (int i = 1; i <= (u - l); i++) {
		distributionArray[i] = distributionArray[i - 1] + distributionArray[i];
	}


	for (int i = inputArray.size() - 1; i > -1; i--) {
		int j = inputArray[i] - l;
		outputArray[distributionArray[j] - 1] = inputArray[i];
		distributionArray[j] = distributionArray[j] - 1;
	}


	return outputArray;
}
