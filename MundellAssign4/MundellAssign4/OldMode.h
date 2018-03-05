#pragma once
#include <vector>

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
		for (int k = 0; k < modes.size(); k = k + 2) {
			if (k == 0) {/*nothing*/ }
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
	for (int x = 1; x < modes.size(); x = x + 2) {
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
	for (int y = 1; y < modes.size(); y = y + 2) {
		if (modes.at(y) == resultVal && modes.at(y - 1) != result) {
			maxModes.push_back(modes.at(y - 1));
		}
	}
	return maxModes;
}
