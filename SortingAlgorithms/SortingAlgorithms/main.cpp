#include <iostream>
#include <vector>
#include <time.h>
#include "Timer.h"
#include <algorithm>
using namespace std;

void DisplayVector(const vector<int> &vec) {

	for (int i = 0; i < vec.size() && i < 100; i++) {
		cout << vec[i] << ", ";
	}
	cout << endl;

}

void VerifySort(const vector<int> &vec) {

	for (int i = 0; i < vec.size()-1; i++)
	{
		if (vec[i] > vec[i + 1]) {
			cout << "Not Sorted" << endl;
			return;
		}
	}
	cout << "Sorted! Yay!" << endl;
	return;
}

void Swap(int &num1, int &num2) {
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

//For all these functions pass by reference	
void BubbleSort(vector<int> &input) {

	for (int k = 0; k < input.size(); ++k) {
		for (int i = 0; i < input.size() - 1; i++) {
			if (input[i] > input[i + 1]) {
				Swap(input[i], input[i + 1]);
			}
		}
	}
}


void SelectionSort(vector<int> &vec) {
	for (int k = 0; k < vec.size(); ++k) {
		int maxIndex = 0;
		for (int i = 1; i < vec.size() - k; ++i) {
			if (vec[i] > vec[maxIndex]) {
				maxIndex = i;
			}
		}
		Swap(vec[maxIndex], vec[vec.size() -k - 1]);
	}
}


int Partition(vector<int> &vec, int leftIndex, int rightIndex) {//O(n)
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
}




void Quicksort(vector<int> &vec, int leftIndex, int rightIndex) { //O(n^2), Average(O(nlog(n))


	if (leftIndex >= rightIndex) {
		return;
	}

	int pivotIndex = Partition(vec, leftIndex, rightIndex);

	Quicksort(vec, leftIndex, pivotIndex - 1);
	Quicksort(vec, pivotIndex + 1, rightIndex);

}

int main() {
	/**srand(time(0));
	Timer timer;
	vector<int> numbers;
	int n = 1000;

	for (int i = 0; i < n; i++) {
		numbers.push_back(rand() % 1000);
	}
	//Added for fast copy
	vector<int> vecToSort = numbers;

	DisplayVector(numbers);

	VerifySort(numbers);

	//sort(numbers.begin(), numbers.end());
	timer.Start();
	BubbleSort(vecToSort);
	timer.Stop();
	timer.Report();

	VerifySort(vecToSort);
	vecToSort = numbers;

	timer.Start();
	//Interesting
	SelectionSort(vecToSort);
	timer.Stop();
	timer.Report();

	DisplayVector(vecToSort);
	VerifySort(vecToSort);
	**/

	vector<int> partitioning;
	partitioning.push_back(1);
	partitioning.push_back(5);
	partitioning.push_back(2);
	partitioning.push_back(7);
	partitioning.push_back(2);
	partitioning.push_back(8);
	cout << Partition(partitioning, 0, 5) << endl;
	cout << Partition(partitioning, 0, 1) << endl;
	cout << Partition(partitioning, 0, 0) << endl;
	cout << Partition(partitioning, 3, 5) << endl;

	return 0;
}