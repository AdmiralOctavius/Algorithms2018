/**
Student: Isaac Bennett
Class: CIT 238
Professor: Matt Mundell
Assignment: Assignment 3
-----
Notes: Spent a lot of time on the Quick Select function,
I understand how partitioning works now however!
***/



#include <iostream>
#include <vector>
#include <time.h>
#include "Timer.h"
#include <algorithm>
#include <string>

#include "Student.h"
#include "Sorting.h"
using namespace std;


//Created a slightly adjusted merge function to work with the new MergeSort function
void newMerge(vector<int> &vec, vector<int> &tempNumbers, int leftIndex, int midpoint, int rightIndex)//O(n)
{
	int mergedSize = rightIndex - leftIndex + 1;

	//Resizing our static vector each time this is called
	tempNumbers.resize(mergedSize);


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

//Better merge sort function
void ImpMergeSort(vector<int> &vec, int leftIndex, int rightIndex) {//O(nlogn)

	if (leftIndex < rightIndex) {
		int midpoint = (rightIndex + leftIndex) / 2;
		//Check if the range is less than ten
		if ((rightIndex - leftIndex) < 10) {
			InsertionSort(vec, leftIndex, midpoint);
		}
		//If the range is larger than ten, call mergeSort again
		else {
			ImpMergeSort(vec, leftIndex, midpoint);
		}

		//Same as the first half
		if ((rightIndex - (midpoint)) < 10) {
			InsertionSort(vec, midpoint+1, rightIndex);
		}
		
		else {
			ImpMergeSort(vec, midpoint+1, rightIndex);
		}

		//Create static vector that is only created once
		static vector<int> tempNumbers(rightIndex - leftIndex + 1);
		//Pass in static vector to new merge function
		newMerge(vec, tempNumbers, leftIndex, midpoint, rightIndex);
	}
}


//Note this is not recursive and there is no recursive function.
//I wrote this from start to finish in iterative fashion
//(We discussed this in an email that this was fine!)
int QuickSelect(vector<int> &vec, int leftIndex, int rightIndex, int value) {
	int pivot;
	//Simple bool to keep the while loop forever going, was recieving errors checking against pivot != value
	bool ban = true;
	//Create a variable to be equal to the k formula for this function
	value = vec.size() - value;
	while (ban) {
		//Call partition to continue searching for the element
		pivot = Partition(vec, leftIndex, rightIndex);

		//Check if we found the value we needed
		if (pivot == value) {
			return pivot;
		}

		//Check if smaller
		else if (pivot < value) {
			leftIndex = pivot;
		}
		//Check if larger
		else if (pivot > value) {
			rightIndex = pivot;
		}
	}
}

int main() {

	Timer timer;

	//Setup numbers for Quick Select checking
	vector<int> input(100);
	for (int i = 0; i < 100; i++) {
		input.at(i) = rand() % 100;
	}
	vector<int> inputSave(100);
	inputSave = input;

	vector<int> TenInput(10);
	for (int i = 0; i < 10; i++) {
		TenInput.at(i) = rand() % 100;
	}
	
	//Check Quick Select
	int result;
	//Testing with 3
	result = QuickSelect(input, 0, 99, 3);
	cout << "Third Largest Element Position: " << result << " The Element itself: " << input.at(result) << endl;
	//Sort the vector
	Quicksort(input,0,99);
	DisplayVector(input);

	//Reset vector
	input = inputSave;

	//Testing with 15
	result = QuickSelect(input, 0, 99, 15);
	cout << "15 Largest Element Position: " << result << " The Element itself: " << input.at(result) << endl;
	Quicksort(input, 0, 99);
	DisplayVector(input);

	//Testing with 5 as the median
	result = QuickSelect(TenInput, 0, 9, 5);
	cout << "Median Largest Element Position: " << result << " The Element itself: " << TenInput.at(result) << endl;
	Quicksort(input, 0, 99);
	DisplayVector(input);


	vector<int> inputMerge(100);
	for (int i = 0; i < 100; i++) {
		inputMerge[i] = rand() % 100;
	}
	cout << "InputMerge function runtime at 100: ";
	timer.Start();
	ImpMergeSort(inputMerge, 0, 99);
	timer.Stop();
	timer.Report();
	//DisplayVector(inputMerge);
	cout << endl << endl;

	vector<int> inputOldMerge(100);
	for (int i = 0; i < 100; i++) {
		inputOldMerge[i] = rand() % 100;
	}
	cout << "MergeSort function runtime at 100: ";
	timer.Start();
	MergeSort(inputOldMerge, 0, 99);
	timer.Stop();
	timer.Report();
	//DisplayVector(inputOldMerge);
	cout << endl << endl;

	
	vector<int> inputMergethou(1000);
	for (int i = 0; i < 1000; i++) {
		inputMergethou[i] = rand() % 1000;
	}
	cout << "InputMerge function runtime at 1000: ";
	timer.Start();
	ImpMergeSort(inputMergethou, 0, 999);
	timer.Stop();
	timer.Report();
	//DisplayVector(inputMergethou);
	cout << endl << endl;

	vector<int> inputOldMergethou(1000);
	for (int i = 0; i < 1000; i++) {
		inputOldMergethou[i] = rand() % 1000;
	}
	cout << "MergeSort function runtime at 1000: ";
	timer.Start();
	MergeSort(inputOldMergethou, 0, 999);
	timer.Stop();
	timer.Report();
	//DisplayVector(inputOldMergethou);
	cout << endl << endl;

	vector<int> inputMergetenthou(10000);
	for (int i = 0; i < 10000; i++) {
		inputMergetenthou[i] = rand() % 10000;
	}
	cout << "InputMerge function runtime at 10000: ";
	timer.Start();
	ImpMergeSort(inputMergetenthou, 0, 9999);
	timer.Stop();
	timer.Report();
	//DisplayVector(inputMergetenthou);
	cout << endl << endl;

	vector<int> inputOldMergetenthou(10000);
	for (int i = 0; i < 10000; i++) {
		inputOldMergetenthou[i] = rand() % 10000;
	}
	cout << "MergeSort function runtime at 100: ";
	timer.Start();
	MergeSort(inputOldMergetenthou, 0, 9999);
	timer.Stop();
	timer.Report();
	//DisplayVector(inputOldMergetenthou);
	cout << endl << endl;

	//Student Class section


	Student Ben(111, "Ben", 3.0);
	Student Mark(1340, "Mark", 2.0);
	
	if (Ben < Mark) {
		cout << "Ben goes first" << endl;
	}
	Ben.SetId(2222);
	if (Ben > Mark) {
		cout << "Ben goes Last" << endl;
	}

	vector<Student> studentTable;
	studentTable.push_back(Student(1, "Jim", 2.0));
	studentTable.push_back(Student(2, "Johhny", 2.0));
	studentTable.push_back(Student(5, "Steven", 2.0));
	studentTable.push_back(Student(4, "David", 2.0));
	studentTable.push_back(Student(9));
	studentTable.push_back(Student(8, "Brendly", 2.0));
	studentTable.push_back(Student(6, "Saxton", 2.0));
	studentTable.push_back(Student(7, "Samus", 2.0));
	studentTable.push_back(Student(3, "Marco", 2.0));
	studentTable.push_back(Student(11111, "Denny's", 2.0));


	DisplayVectorStudent(studentTable);

	sort(studentTable.begin(), studentTable.end());

	DisplayVectorStudent(studentTable);
	return 0;
}