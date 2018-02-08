#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>

#include "Timer.h"

using namespace std;

void DisplayVector(const vector<int> &vec)
{
	for (int i = 0; i < vec.size() && i < 100; i++)
		cout << vec[i] << ", ";
	cout << endl;
}

void VerifySort(const vector<int> &vec)
{
	for(int i = 0; i < vec.size() - 1; i++)
		if (vec[i] > vec[i + 1])
		{
			cout << "Not Sorted" << endl;
			return;
			//break;//would leave the loop, not the function
		}

	cout << "Sorted! Yay!" << endl;
}

void Swap(int &num1, int &num2)//O(1)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

void BubbleSort(vector<int> &vec)//O(n^2)
{
	for (int k = 0; k < vec.size(); ++k)
		for (int i = 0; i < vec.size() - 1; ++i)
			if (vec[i] > vec[i + 1])
				Swap(vec[i], vec[i + 1]);
}

void SelectionSort(vector<int> &vec)//O(n^2)
{ 
	for (int k = 0; k < vec.size(); ++k)
	{
		int maxIndex = 0;
		for (int i = 1; i < vec.size() - k; ++i)
		{
			if (vec[i] > vec[maxIndex])
				maxIndex = i;
		}
		Swap(vec[maxIndex], vec[vec.size() - k - 1]);
	}
}

//Worst Case Complexity: O(n^2)
//Best Case Complexity: Big-Omega(n)
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

//Worst Case: O(n^2), Average: O(nLog(n))
void Quicksort(vector<int> &vec, int leftIndex, int rightIndex)
{
	//Check to see if we have enough numbers to quicksort
	if (leftIndex >= rightIndex)
		return;

	//Partition the vector into two sections, where the 1st is entirely < the 2nd
	int pivotIndex = Partition(vec, leftIndex, rightIndex);

	//Recursively quicksort on both the left section and the 
		//right section determined by the pivot index
	Quicksort(vec, leftIndex, pivotIndex - 1);
	Quicksort(vec, pivotIndex + 1, rightIndex);
}

void Merge(vector<int> &vec, int leftIndex, int midpoint, int rightIndex)//O(n)
{
	int mergedSize = rightIndex - leftIndex + 1;
	vector<int> tempNumbers(mergedSize);

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
//Merge sort is not an in place sort - that means we have to make extra vectors to use it
	//O(n) memory usage
void Mergesort(vector<int> &vec, int leftIndex, int rightIndex)//O(nlogn)
{
	if (leftIndex < rightIndex)
	{
		int midpoint = (rightIndex + leftIndex) / 2;

		Mergesort(vec, leftIndex, midpoint);
		Mergesort(vec, midpoint + 1, rightIndex);
		Merge(vec, leftIndex, midpoint, rightIndex);
	}
}

int main()
{
	srand(time(0));//seed random - new numbers each time we run.
	Timer timer;

	int n = 10000;

	vector<int> numbers;
	for (int i = 0; i < n; i++)
		numbers.push_back(rand() % 1000);

	vector<int> vecToSort = numbers;

	DisplayVector(vecToSort);

	VerifySort(vecToSort);

	cout << "Merge Sort: " << endl;
	vecToSort = numbers;
	//sort(vecToSort.begin(), vecToSort.end());
	timer.Start();
	Mergesort(vecToSort, 0, vecToSort.size() - 1);
	timer.Stop();
	timer.Report();
	VerifySort(vecToSort);

	cout << "Quick Sort: " << endl;
	vecToSort = numbers;
	//sort(vecToSort.begin(), vecToSort.end());
	timer.Start();
	Quicksort(vecToSort, 0, vecToSort.size() - 1);
	timer.Stop();
	timer.Report();
	VerifySort(vecToSort);

	cout << "Bubble Sort: " << endl;
	vecToSort = numbers;
	timer.Start();
	BubbleSort(vecToSort);
	timer.Stop();
	timer.Report();
	VerifySort(vecToSort);

	cout << "Selection Sort: " << endl;
	vecToSort = numbers;//reset vecToSort to random numbers
	timer.Start();
	SelectionSort(vecToSort);
	timer.Stop();
	timer.Report();
	VerifySort(vecToSort);

	cout << "Insertion Sort: " << endl;
	vecToSort = numbers;
	//sort(vecToSort.begin(), vecToSort.end());
	timer.Start();
	InsertionSort(vecToSort, 0, vecToSort.size()-1);
	timer.Stop();
	timer.Report();
	VerifySort(vecToSort);

	cout << "Std::Sort" << endl;
	vecToSort = numbers;
	timer.Start();
	sort(vecToSort.begin(), vecToSort.end());
	timer.Stop();
	timer.Report();
	VerifySort(vecToSort);

	DisplayVector(vecToSort);

	return 0;
}