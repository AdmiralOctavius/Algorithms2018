/***
Isaac Bennett
Cit-238
Assignment 2
Prof. Matt Mundell
-----
Assistance recieved: Dylan White, Anthony Brown, Kris Constantino
***/



#include <algorithm>
#include <vector>
#include <math.h>
#include <iostream>
#include <time.h>

#include "Timer.h"
using namespace std;

//Unsorted Min
int vecMin(vector<int> &input) {//O(
	int min = 0;
	for (int i = 0; i < input.size(); i++) {
		if (input.at(i) < min) {
			min = input.at(i);
		}
	}
	return min;
}

//Sorted Min
int vecSortedMin(vector<int> &input) {//O(3)
	int min = 0;
	min = input.at(0);
	return min;
}

//Unsorted Max
int vecMax(vector<int> &input) {//O(N)
	int max = 0;
	for (int i = 0; i < input.size(); i++) {
		if (input.at(i) > max) {
			max = input.at(i);
		}
	}
	return max;
}

//Sorted Max
int vecSortedMax(vector<int> &input) {//O(3)
	int max = 0;
	max = input.at(input.size() - 1);
	return max;
}

//Mean function
//Note, due to the nature of how we come about doing the mean, 
//I cannot envision how we would improve a function to find the mean with a sorted vector
int vecMean(vector<int> &input) {//O(N)
	int mean = 0;
	for (int i = 0; i < input.size(); i++) {
		mean = input.at(i) + mean;
	}
	mean = mean / input.size();
	return mean;
}

//Function to find the mode of a single element
//Total worst case complexity is O(N^2)
int vectorModeSingle(vector<int> &input) {
	//Stores the highest number
	int result = 0;
	//Stores a list of all numbers with multiple (non zero) instances
	vector<int> modes;
	//Check that lets us ignore a duplicate value in the input vector
	bool exists = false;
	//Incrementer counter for the amount a specific number appears in the input vector
	int j = 0;
	//Comparator value
	int mode = 0;
	//Value to keep track of position in end for loop
	int modePos = 0;


	//For loop of all elements in input, Big O(N^2)
	for (int i = 0; i < input.size(); i++) {
		//This checks to ensure that we ignore duplicate values
		exists = false;
		for (int k = 0; k < modes.size(); k = k +2) {
			if(k == 0){/*nothing*/}
			else if (input.at(i) == modes.at(k)) {
				exists = true;
			}
		}
		if (exists == false) {
			//Should access the new vector's push_back func, gives it the next number
			modes.push_back(input.at(i));
			j = 0;
			
			for (int z = 0; z < input.size(); z++) {
				if (z == i) {/*Skip this instance, this should never run*/ }
				
				if (modes.at(modePos) == input.at(z)) {
					j++;
				}
			}
			modes.push_back(j);
			modePos = modePos + 2;
		}
		
	}

	//Need to get multiple modes for extra credit
	for (int x = 1; x < modes.size(); x = x +2) {
		if (modes.at(x) > mode) {
			mode = modes.at(x);
			result = modes.at(x - 1);
		}
	}
	return result;
}

vector<int> vectorModeMultiple(vector<int> &input) {
	int result = 0;
	int resultVal = 0;
	vector<int> modes;
	vector<int> maxModes;
	bool exists = false;
	int j = 0;
	int mode = 0;
	int modePos = 0;
	//For loop of all elements in input, Big O of N
	for (int i = 0; i < input.size(); i++) {
		exists = false;
		for (int k = 0; k < modes.size(); k = k + 2) {
			if (input.at(i) == modes.at(k)) {
				exists = true;
			}
		}
		if (exists == false) {
			//Should access the new vector's push_back func, gives it the next number
			modes.push_back(input.at(i));
			j = 0;

			for (int z = 0; z < input.size(); z++) {
				if (z == i) {/*Skip this instance*/ }
				//Got an error when testing with 100 elements
				if (modes.at(modePos) == input.at(z)) {
					j++;
				}
			}
			modes.push_back(j);
			modePos = modePos + 2;
		}

	}

	//Need to get multiple modes for extra credit
	for (int x = 1; x < modes.size(); x = x + 2) {
		if (modes.at(x) > mode) {
			mode = modes.at(x);
			result = modes.at(x - 1);
			resultVal = modes.at(x);
		}
	}
	maxModes.push_back(result);
	for (int y = 1; y < modes.size(); y = y +2) {
		if (modes.at(y) == resultVal && modes.at(y-1) != result) {
			maxModes.push_back(modes.at(y - 1));
		}
	}	
	return maxModes;
}
//Basic swap 
void Swap(int &num1, int &num2)    //O(1)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}


//Bubble sort function with changes
void BetterBubbleSort(vector<int> &vec)//O(n^2)
{
	int sortedSize = vec.size();
	bool firstRun = true;
	//With how random input works, the odds of the last element being the largest number is slim.
	//With this presumption we can take the initial end of the vector and watch for a change
	int start = vec.at(sortedSize - 1);
	for (int k = 0; k < vec.size(); k++)
	{

		for (int i = 0; i < sortedSize - 1; i++)
		{
			if (vec[i] > vec[i + 1])
			{
				Swap(vec[i], vec[i + 1]);
			}

		}
		if (start == vec.at(sortedSize - 1) && firstRun) {
			//We didn't change anything, we're already sorted
			cout << "Already sorted, have a nice day!" << endl;
			break;
		}
		firstRun = false;
		sortedSize--;
	}
}

//Bubble sort function with no changes
void BubbleSort(vector<int> &vec)//O(n^2)
{
	for (int k = 0; k < vec.size(); k++)
	{

		for (int i = 0; i < vec.size() - 1; i++)
		{
			if (vec[i] > vec[i + 1])
			{
				Swap(vec[i], vec[i + 1]);
			}

		}

	}
}

void DisplayVec(vector<int> vec)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << " ";
	}
	cout << endl << endl;
}

int main() {

	Timer timer;
	srand(time(0));

	vector<int> randNums1000(1000);
	for (int i = 0; i < randNums1000.size(); i++) {
		randNums1000[i] = rand() % 50;
	}
	vector<int> randNums10(10);
	for (int i = 0; i < randNums10.size(); i++) {
		randNums10[i] = rand() % 50;
	}
	vector<int> randNums100(100);
	for (int i = 0; i < randNums100.size(); i++) {
		randNums100[i] = rand() % 50;
	}
	vector<int> randNums2 = randNums1000;

	//Test vector to prove multiple modes function works
	vector<int> multipleModes;
	multipleModes.push_back(12);
	multipleModes.push_back(12);
	multipleModes.push_back(12);
	multipleModes.push_back(12);
	multipleModes.push_back(12);
	multipleModes.push_back(11);
	multipleModes.push_back(11);
	multipleModes.push_back(11);
	multipleModes.push_back(11);
	multipleModes.push_back(11);

	cout << "Max number: " << vecMax(randNums1000) << endl;
	cout << "Min number: " << vecMin(randNums1000) << endl;
	cout << "Mean is: " << vecMean(randNums1000) << endl;
	cout << "Mode is: " << vectorModeSingle(randNums1000) << endl;

	//Testing multiple mode function
	vector<int> MultipleModesResult = vectorModeMultiple(randNums1000);
	DisplayVec(MultipleModesResult);
	vector<int> MultipleModesConfirmTest = vectorModeMultiple(multipleModes);
	DisplayVec(MultipleModesConfirmTest);


	//Preforming bubble sort tests
	cout << "Bubble sort executing." << endl;
	timer.Start();
	BubbleSort(randNums1000);
	timer.Stop();
	timer.Report();

	//Quick test of sorted min max
	cout << "Max is: " << vecSortedMax(randNums1000) << endl;
	cout << "Min is: " << vecSortedMin(randNums1000) << endl;

	cout << "Testing better bubble sort with 1000 elements: " << endl;
	timer.Start();
	BetterBubbleSort(randNums2);
	timer.Stop();
	timer.Report();

	cout << "Testing better bubble sort with 100 elements: " << endl;
	timer.Start();
	BetterBubbleSort(randNums100);
	timer.Stop();
	timer.Report();

	cout << "Testing better bubble sort with 10 elements: " << endl;
	timer.Start();
	BetterBubbleSort(randNums10);
	timer.Stop();
	timer.Report();


	return 0;
}