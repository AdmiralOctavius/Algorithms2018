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

void DisplayTopTen(vector<int> input) {
	for (int i = input.size() - 10; i < input.size(); i++) {
		cout << input.at(i) << ',' ;
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

int HighestVectorNumber(vector<int> input) {

	int highestNum = 0;
	int size = input.size();
	highestNum = input.at(size);

	return highestNum;
}

int ThirdHighestNumber(vector<int> input) {
	vector<int> HighestThree(3);	
	HighestThree.at(0) = 0;
	HighestThree.at(1) = 0;
	HighestThree.at(2) = 0;
	for (int i = 0; i < input.size(); i++) {
		if (input.at(i) >= HighestThree.at(0)) {
			HighestThree.at(2) = HighestThree.at(1);
			HighestThree.at(1) = HighestThree.at(0);
			HighestThree.at(0) = input.at(i);
		
		}
		else if (input.at(i) >= HighestThree.at(1)) {
			HighestThree.at(2) = HighestThree.at(1);
			HighestThree.at(1) = input.at(i);
		}
		else if (input.at(i) >= HighestThree.at(2)) {
			HighestThree.at(2) = input.at(i);
		}
		else {
			//nothing
			//cout << "Not Higher than anything." << endl;
		}
	}

	return HighestThree.at(2);
}

int SortedThirdHighestNumber(vector<int> input) {
	vector<int> HighestThree(3);
	HighestThree.at(0) = 0;
	HighestThree.at(1) = 0;
	HighestThree.at(2) = 0;

	for (int i = input.size() - 1; i > 0; i--) {
		if (input.at(i) >= HighestThree.at(0)) {
			HighestThree.at(0) = input.at(i);
		}
		else if (input.at(i) >= HighestThree.at(1)) {
			HighestThree.at(1) = input.at(i);
		}
		else if (input.at(i) >= HighestThree.at(2)) {
			HighestThree.at(2) = input.at(i);
			break;
		}
		else {
			//nothing
			cout << "Was most likely equal." << endl;
		}
	}

	return HighestThree.at(2);
}
int main() {
	srand(time(0));

	vector<int> RandomNumbers(1000);

	for (int i = 0; i < RandomNumbers.size(); i++) {
		RandomNumbers[i] = rand() % 1000;
	}

	//DisplayArray(RandomNumbers.data(), 1000);

	cout << endl << HighestNumber(RandomNumbers) << endl;

	cout << endl << ThirdHighestNumber(RandomNumbers) << endl;

	sort(RandomNumbers.begin(), RandomNumbers.end());

	//DisplayArray(RandomNumbers.data(), 1000);

	cout << endl << HighestNumber(RandomNumbers) << endl;

	DisplayTopTen(RandomNumbers);
	cout << endl << endl;
	//cout << endl << ThirdHighestNumber(RandomNumbers) << endl;
	cout << endl << SortedThirdHighestNumber(RandomNumbers) << endl;
	return 0;
}
