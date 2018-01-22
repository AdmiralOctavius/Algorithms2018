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

	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] > vec[i + 1]) {
			cout << "Not Sorted" << endl;
			return;
		}
	}
	cout << "Sorted! Yay!" << endl;
	return;
}


int main() {
	srand(time(0));
	Timer timer;
	vector<int> numbers;
	int n = 1000;

	for (int i = 0; i < n; i++) {
		numbers.push_back(rand() % 1000);
	}

	DisplayVector(numbers);

	VerifySort(numbers);

	sort(numbers.begin(), numbers.end());

	VerifySort(numbers);
	return 0;
}