/***




***/



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
		if (input.at(i) > HighestThree.at(0)) {
			HighestThree.at(2) = HighestThree.at(1);
			HighestThree.at(1) = HighestThree.at(0);
			HighestThree.at(0) = input.at(i);
		
		}
		else if (input.at(i) > HighestThree.at(1) && input.at(i) != HighestThree.at(0)) {
			HighestThree.at(2) = HighestThree.at(1);
			HighestThree.at(1) = input.at(i);
		}
		else if (input.at(i) > HighestThree.at(2) && input.at(i) != HighestThree.at(0) && input.at(i) != HighestThree.at(1)) {
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

	//Ask about >=0 or >= -1
	for (int i = input.size() - 1; i >= 0; i--) {
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
			//cout << "Was most likely equal." << endl;
		}
	}

	return HighestThree.at(2);
}
int main() {

	//-----Establishing the array-----//
	srand(time(0));

	vector<int> RandomNumbers(1000);

	for (int i = 0; i < RandomNumbers.size(); i++) {
		RandomNumbers[i] = rand() % 1000;
	}

	//-------Finished the array------//

	vector<int> RandomTest(10);
	
	RandomTest[0] = 996;
	RandomTest[1] = 995;
	RandomTest[2] = 998;
	RandomTest[3] = 996;
	RandomTest[4] = 997;
	RandomTest[5] = 999;
	RandomTest[6] = 998;
	RandomTest[7] = 997;
	RandomTest[8] = 996;
	RandomTest[9] = 999;

	cout << ThirdHighestNumber(RandomTest);
	sort(RandomTest.begin(), RandomTest.end());

	//Function that displays the top ten results in the sorted Array, helps debug the Third Highests function
	DisplayTopTen(RandomTest);




	//Finds the highest number in the unsorted array
	cout << endl << HighestNumber(RandomNumbers) << endl;

	//Function to find the Third Highest number in the unsorted array, different from "SortedThirdHighestNumber"
	cout << endl << ThirdHighestNumber(RandomNumbers) << endl;

	//Default Sort function
	//Sorting//
	sort(RandomNumbers.begin(), RandomNumbers.end());
	

	//Function that displays the top ten results in the sorted Array, helps debug the Third Highests function
	DisplayTopTen(RandomNumbers);

	cout << endl << endl;

	//Function that finds the Third Highest Number in the sorted array
	cout << endl << SortedThirdHighestNumber(RandomNumbers) << endl;
	return 0;
}



//---End Comments---//
/*
	The function to find the third highest number in the sorted array is vastly more efficient, because we can make assumptions.
	The primary assumption we can make is that since the array is sorted, we can start at the top of the array and work our way down.
	Doing this allows for us to reach our assigned variable much faster than starting at the bottom.

	We can see from the unsorted third highest function that it would take much longer, and more operations, if the array was unsorted.

	If we presume the array is already sorted the function that is designed for the sorted array would be faster.

*/