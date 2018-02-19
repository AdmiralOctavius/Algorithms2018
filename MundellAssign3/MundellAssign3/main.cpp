#include <iostream>
#include <vector>
#include <time.h>
#include "Timer.h"
#include <algorithm>
#include <string>

#include "Student.h"
#include "Sorting.h"
using namespace std;


void ImpMergeSort(vector<int> &vec, int leftIndex, int rightIndex) {//O(nlogn)
	if (leftIndex < rightIndex) {
		int midpoint = (rightIndex - leftIndex) / 2;
		if ((midpoint - leftIndex) > 10) {
			ImpMergeSort(vec, leftIndex, midpoint);
		}
		else {
			InsertionSort(vec, leftIndex, midpoint);
		}
		if ((rightIndex - (midpoint + 1)) > 10) {
			ImpMergeSort(vec, midpoint + 1, rightIndex);
		}
		else {
			InsertionSort(vec, midpoint + 1, rightIndex);
		}

		Merge(vec, leftIndex, midpoint, rightIndex);
	}
}



int Partition(vector<int> &vec, int leftIndex, int rightIndex) {//O(n)
															//Pick a pivot value, such as the last value
	//Not sure why we get a random index
	int randIndex = rand() % (rightIndex - leftIndex) + leftIndex;
	//Gets a random pivot index
	swap(vec[randIndex], vec[rightIndex]);

	//This gets the middle of the selection
	//We don't need this anymore
	//int middle = leftIndex + (rightIndex - leftIndex) / 2;
	int pivot = randIndex;
	//Sets pivot to right Index
	//int pivot = vec[rightIndex];
	//int temp;

	//If the result is less than 2 it's an error?
	if ((rightIndex - leftIndex) < 2) {
		return -1;
	}


	//Secondary iterator
	int j = leftIndex;

	//For loop
	for (int i = leftIndex; i < rightIndex; ++i) {
		//Swaps the vectorPos at i with a position in the vector at j
		
		if (vec.at(i) < pivot) {
			Swap(vec.at(i), vec.at(j++));
		}
	}
	//Swap the end result of j with right index? This should give us
	Swap(vec[rightIndex], vec[j]);
	//No need for this
	//change pivot to the middle position
	//pivot = vec[middle];
	//Give the new middle / pivot value
	return j;
}

int ParPartition(vector<int> &vec, int leftIndex, int rightIndex, int pivot) {//O(n)

	swap(vec[pivot], vec[rightIndex]);



	//Secondary iterator
	int j = rightIndex;

	//For loop
	for (int i = leftIndex; i < rightIndex; ++i) {
		//Swaps the vectorPos at i with a position in the vector at j

		if (vec.at(i) < pivot) {
		}
		if (vec.at(i) > pivot) {
			
				Swap(vec.at(i), vec.at(j));
				j--;
				if (vec.at(j) < pivot) {
					Swap(vec.at(j), vec.at(i));
				}
			
		}
	}
	//Swap the end result of j with right index? This should give us
	Swap(vec[rightIndex], vec[j]);
	//No need for this
	//change pivot to the middle position
	//pivot = vec[middle];
	//Give the new middle / pivot value
	return j;
}

int wikiPartition(vector<int> &vec, int leftIndex, int rightIndex, int pivot) {
	int pivotVal = vec[pivot];
	Swap(vec[pivot], vec[rightIndex]);
	int storedIndex = leftIndex;
	for (int i=0; i < vec.size(); i++) {
		if (vec[i] < pivotVal) {
			Swap(vec[storedIndex], vec[i]);
			storedIndex++;
		}
	}
	Swap(vec[rightIndex], vec[storedIndex]);
	return storedIndex;
}
int QuickSelect(vector<int> &vec, int leftIndex, int rightIndex, int value) {
	//Check if there's only one element
	if (vec.size() == 1) {
		return vec[0];
	}
	
	int target = vec.size() - value;
	//Use something similar to quick sort to move 
	//all the smaller values into the left half, 
	//all the bigger vals into the right half.
	//Should get middle of position
	int pivot = ((rightIndex - leftIndex) / 2) + leftIndex;
	//This needs to be the middle
	//Should it be random

	if(pivot == target){
		//This is the end
		return pivot;
	}

	//While loop of calculations
	while(pivot != target){
		if (( rightIndex - leftIndex) <= 0) {
			pivot = rightIndex;
			break;
		}
		pivot = wikiPartition(vec, leftIndex, rightIndex, pivot);
		if (pivot < target) {
			leftIndex = pivot + 1;
		}
		if (pivot > target){
			rightIndex = pivot - 1;
		}
		
		
	}	

	//Return the position of that element
	return pivot;
}


void Quicksort(vector<int> &vec, int leftIndex, int rightIndex) { //O(n^2), Average(O(nlog(n))


	if (leftIndex >= rightIndex) {
		return;
	}

	int pivotIndex = Partition(vec, leftIndex, rightIndex);

	Quicksort(vec, leftIndex, pivotIndex - 1);
	Quicksort(vec, pivotIndex + 1, rightIndex);

	string name;
}

int main() {

	Student Ben(111, "Ben", 3.0);
	Student Mark(1340, "Mark", 2.0);

	if (Ben < Mark) {
		cout << "Ben goes first" << endl;
	}

	vector<int> input(100);
	for (int i = 0; i < 100; i++) {
		input[i] = rand() % 100;
	}
	DisplayVector(input);
	int numGet = 5;
	//int position = QuickSelect(input, 0, 99, numGet);
	//cout << numGet << " number" << input[position] << endl;
	
	sort(input.begin(), input.end());

	DisplayVector(input);


	vector<int> inputMerge(100);
	for (int i = 0; i < 100; i++) {
		inputMerge[i] = rand() % 100;
	}

	ImpMergeSort(inputMerge, 0, 99);
	DisplayVector(inputMerge);
	return 0;
}