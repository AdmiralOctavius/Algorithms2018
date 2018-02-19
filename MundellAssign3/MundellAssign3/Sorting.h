#pragma once
#include <vector>
#include <iostream>
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

//Call this when a range in MergeSort is smaller than 10
void InsertionSort(vector<int> &vec, int leftIndex, int rightIndex)//O(n^2)
{
	for (int i = leftIndex + 1; i <= rightIndex; ++i)
	{
		int j = i;
		while (j > leftIndex && vec[j] < vec[j - 1])
		{
			Swap(vec[j], vec[j - 1]);
			j--;
		}
	}
}

//O(N)
/* My incomplete merge code from class void Merge(vector<int> &vec, int leftIndex, int midpoint, int rightIndex) {
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
}*/

void Merge(vector<int> &vec, int leftIndex, int midpoint, int rightIndex)//O(n)
{
	int mergedSize = rightIndex - leftIndex + 1;
	static vector<int> tempNumbers(mergedSize);
	//tempNumbers.resize(mergedSize);

	int leftPos = leftIndex;
	int rightPos = midpoint + 1;
	int mergePos = 0;

	//Compares first number in both sections, taking the smallest each time
	//Until one section is empty
	//This while loop is the bulk of merge sort
	while (leftPos <= midpoint && rightPos <= rightIndex)
	{
		if (vec[leftPos] < vec[rightPos])
			tempNumbers[mergePos++] = vec[leftPos++];
		else
			tempNumbers[mergePos++] = vec[rightPos++];
	}

	//Takes any numbers left in the left half of the section
	while (leftPos <= midpoint)
		tempNumbers[mergePos++] = vec[leftPos++];

	//Takes any numbers left over in the right half of the section
	while (rightPos <= rightIndex)
		tempNumbers[mergePos++] = vec[rightPos++];

	//Copies the sorted numbers back into the original array
	for (int i = 0; i < mergedSize; ++i)
		vec[leftIndex + i] = tempNumbers[i];
}

//In place sort - only moves numbers in the original array
//O(1) memory usage
//Merge sort is not an in place sort, we make extra vectors to use it
//O(N) memory usage
void MergeSort(vector<int> &vec, int leftIndex, int rightIndex) {//O(nlogn)
	if (leftIndex < rightIndex) {
		int midpoint = (rightIndex - leftIndex) / 2;

		MergeSort(vec, leftIndex, midpoint);
		MergeSort(vec, midpoint + 1, rightIndex);
		Merge(vec, leftIndex, midpoint, rightIndex);
	}
}
