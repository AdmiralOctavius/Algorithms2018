/***
Student: Isaac Bennett
Class: CIT263 Alg
Prof: Matt Mundell
-----
Assignment 1: Vector search and sort
Notes: Was a fairly fun review project, good start.
Will work more on pure efficiency next time.
***/


//Includes
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <time.h>
#include <algorithm>
//Watcher Programs
#include "Timer.h"
using namespace std;

//Temp display function
//Complexity: O(N)
void DisplayArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << ',';
	}
}

//Disply top ten function, good for debugging
//Complexity: O(10)
void DisplayTopTen(vector<int> input) {
	for (int i = input.size() - 10; i < input.size(); i++) {
		cout << input.at(i) << ',' ;
	}
}

//Gets the highest number in an unsorted array, starting at the bottom
//O(N)
int HighestNumber(vector<int> input) {
	int highestNumber = 0;
	for (int i = 0; i < input.size(); i++) {
		if (input.at(i) >= highestNumber) {
			highestNumber = input.at(i);
		}
	}
	return highestNumber;
}

//Simple function that gets the highest number at the end of a sorted vector
//Complexity: O(4)
int HighestVectorNumber(vector<int> input) {

	int highestNum = 0;
	int size = input.size();
	highestNum = input.at(size);

	return highestNum;
}

//Gets the third highest in an unsorted array/vector
//Complexity:O(N)
int ThirdHighestNumber(vector<int> input) {
	//Establish vector for the highest three numbers
	vector<int> HighestThree(3);	
	HighestThree.at(0) = 0;
	HighestThree.at(1) = 0;
	HighestThree.at(2) = 0;

	//Main for loop over all the numbers in vector
	for (int i = 0; i < input.size(); i++) {
		//If the new number is greater than all the other numbers we shift all the numbers down by 1 in the vector, dumping the lowest value
		if (input.at(i) > HighestThree.at(0)) {
			HighestThree.at(2) = HighestThree.at(1);
			HighestThree.at(1) = HighestThree.at(0);
			HighestThree.at(0) = input.at(i);
		
		}
		//We do the same here, but we also check to ensure that it is not the same number as the highest number, we want to ignore similar highest numbers
		else if (input.at(i) > HighestThree.at(1) && input.at(i) != HighestThree.at(0)) {
			HighestThree.at(2) = HighestThree.at(1);
			HighestThree.at(1) = input.at(i);
		}
		//Same here, but we also ignore the second highest number as well
		else if (input.at(i) > HighestThree.at(2) && input.at(i) != HighestThree.at(0) && input.at(i) != HighestThree.at(1)) {
			HighestThree.at(2) = input.at(i);
		}
		else {
			//nothing
			//cout << "Not Higher than anything." << endl;
		}
	}

	//Return the third highest number in our smaller vector
	return HighestThree.at(2);
}

//Much simpler function for finding our number in a sorted vector
//Complexity: O(N)
int SortedThirdHighestNumber(vector<int> input) {
	//Again small vector of three elements
	vector<int> HighestThree(3);
	HighestThree.at(0) = 0;
	HighestThree.at(1) = 0;
	HighestThree.at(2) = 0;

	//Ask about >=0 or >= -1
	//Simple for loop counting down from the top of the array, allowing for optimization
	for (int i = input.size() - 1; i >= 0; i--) {
		//If we find a number similar to the highest number, or if it is higher, simply store it
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
	//Simply return the third highest
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


	//Finds the highest number in the unsorted array
	cout << endl << HighestNumber(RandomNumbers) << endl;

	//Function to find the Third Highest number in the unsorted array, different from "SortedThirdHighestNumber"
	cout << endl << ThirdHighestNumber(RandomNumbers) << endl;

	//Default Sort function
	//Sorting//
	sort(RandomNumbers.begin(), RandomNumbers.end());
	//Sorting//	

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