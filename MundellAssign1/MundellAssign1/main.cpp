#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <time.h>
#include <algorithm>
//Watcher Programs
#include "Timer.h"
using namespace std;

//Temp display
void DisplayArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << ',';
	}
}

int HighestNumber(vector<int> input) {
	int highestNumber = 0;
	for (int i = 0; i < input.size(); i++) {
		if (input.at(i) >= highestNumber) {
			highestNumber = input.at(i);
		}
	}
	return highestNumber;
}

int ThirdHighestNumber(vector<int> input) {
	vector<int> HighestThree(3);
	for (int i = 0; i < input.size(); i++) {
		if (i > HighestThree.at(1)) {
			HighestThree.at(1) = input.at(i);
		}
		else if (i > HighestThree.at(2)) {
			HighestThree.at(1) = input.at(i);
		}
		else if (i > HighestThree.at(3)) {
			HighestThree.at(3) = input.at(i);
		}
		else {
			//nothing
		}
	}

	return HighestThree.at(3);
}
int main() {
	srand(time(0));

	vector<int> RandomNumbers(1000);

	for (int i = 0; i < RandomNumbers.size(); i++) {
		RandomNumbers[i] = rand() % 1000;
	}

	DisplayArray(RandomNumbers.data(), 1000);

	cout << endl << endl << HighestNumber(RandomNumbers);

	sort(RandomNumbers.begin(), RandomNumbers.end());

	DisplayArray(RandomNumbers.data(), 1000);


	return 0;
}
