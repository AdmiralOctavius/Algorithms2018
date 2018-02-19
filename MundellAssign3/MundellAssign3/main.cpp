#include <iostream>
#include <vector>
#include <time.h>
#include "Timer.h"
#include <algorithm>
#include <string>
using namespace std;

void DisplayVector(const vector<int> &vec) {

	for (int i = 0; i < vec.size() && i < 100; i++) {
		cout << vec[i] << ", ";
	}
	cout << endl;

}

void Swap(int &num1, int &num2) {
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

/*
int Partition(vector<int> &vec, int leftIndex, int rightIndex) {//O(n)
																//Pick a pivot value, such as the last value
	int randIndex = rand() % (rightIndex - leftIndex) + leftIndex;
	swap(vec[randIndex], vec[rightIndex]);

	int middle = leftIndex + (rightIndex - leftIndex) / 2;
	int pivot = vec[rightIndex];
	//int temp;
	if ((rightIndex - leftIndex) < 2) {
		return -1;
	}


	int j = leftIndex;
	for (int i = 0; i < rightIndex; i++) {
		if (vec.at(i) < pivot) {
			Swap(vec.at(i), vec.at(j++));
		}
	}
	Swap(vec[rightIndex], vec[j]);
	pivot = vec[middle];
	return pivot;
}*/



int Partition(vector<int> &vec, int leftIndex, int rightIndex)//O(n)
{
	//Pick a pivot value, such as the last value in the section
	int randIndex = rand() % (rightIndex - leftIndex) + leftIndex;
	swap(vec[randIndex], vec[rightIndex]);
	int pivot = vec[rightIndex];

	//Then for every value smaller than the pivot, swap it into the left half of the section
	int j = leftIndex;
	for (int i = leftIndex; i < rightIndex; ++i)
	{
		if (vec[i] < pivot)
			Swap(vec[i], vec[j++]);
	}

	//Then swap the pivot value into the middle of the section
	Swap(vec[rightIndex], vec[j]);

	//Finally, return the index of the pivot value
	return j;
}


//O(N)
void Merge(vector<int> &vec, int leftIndex, int midpoint, int rightIndex) {
	int mergedSize = rightIndex;
	vector<int> tempNumbers(mergedSize);
	int leftPos = leftIndex;
	int rightPos = midpoint + 1;
	int mergePos = 0;

	while (leftPos <= midpoint && rightPos <= rightIndex) {

		if (vec[leftPos] < vec[rightPos]) {
			tempNumbers[mergePos++] = vec[leftPos++];
		}
		else {
			tempNumbers[mergePos++] = vec[rightPos++];
		}
	}
	//Only one of these while loops could ever run after the first while loop
	while (leftPos <= midpoint) {
		tempNumbers[mergePos++] = vec[leftPos++];
	}
	while (rightPos <= tempNumbers[mergePos++]) {
		tempNumbers[mergePos++] = vec[rightPos++];
	}

	for (int i = 0; i < mergedSize; i++) {

	}
}

//In place sort - only moves numbers in the original array
//O(1) memory usage
//Merge sort is not an in place sort, we make extra vectors to use it
//O(N) memory usage
/*void MergeSort(vector<int> &vec, int leftIndex, int rightIndex) {//O(nlogn)
	if (leftIndex < rightIndex) {
		int midpoint = (rightIndex - leftIndex) / 2;

		MergeSort(vec, leftIndex, midpoint);
		MergeSort(vec, midpoint + 1), rightIndex;
		Merge(vec, leftIndex, midpoint);
	}
}*/



void Quicksort(vector<int> &vec, int leftIndex, int rightIndex) { //O(n^2), Average(O(nlog(n))


	if (leftIndex >= rightIndex) {
		return;
	}

	int pivotIndex = Partition(vec, leftIndex, rightIndex);

	Quicksort(vec, leftIndex, pivotIndex - 1);
	Quicksort(vec, pivotIndex + 1, rightIndex);

	string name;
}

int QuickSelect(vector<int> &vec, int leftIndex, int rightIndex, int value) {
	int pivot;//= (rightIndex - leftIndex) / 2;
	bool ban = true;
	value = vec.size() - value;
	while (ban) {
		pivot = Partition(vec, leftIndex, rightIndex);
		if (pivot == value) {
			return pivot;
		}
		else if (pivot < value) {
			leftIndex = pivot - 1;
		}
		else if (pivot > value) {
			rightIndex = pivot + 1;
		}
	}
}

int main() {

	vector<int> input(100);
	for (int i = 0; i < 100; i++) {
		input.at(i) = rand() % 100;
	}

	vector<int> TenInput(10);
	for (int i = 0; i < 10; i++) {
		TenInput.at(i) = rand() % 100;
	}


	int result;
	result = QuickSelect(input, 0, 99, 3);
	cout << "Third Largest Element Position: " << result << " The Element itself: " << input.at(result) << endl;
	DisplayVector(input);

	result = QuickSelect(input, 0, 99, 15);
	cout << "15 Largest Element Position: " << result << " The Element itself: " << input.at(result) << endl;
	DisplayVector(input);

	result = QuickSelect(TenInput, 0, 9, 4);
	cout << "Median Largest Element Position: " << result << " The Element itself: " << TenInput.at(result) << endl;
	DisplayVector(TenInput);

	return 0;
}