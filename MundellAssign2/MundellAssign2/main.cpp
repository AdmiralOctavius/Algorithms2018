#include <algorithm>
#include <vector>
#include <math.h>
#include <iostream>
#include <time.h>
using namespace std;

//Unsorted Max
int vecMax(vector<int> &input) {
	int max = 0;
	for (int i = 0; i < input.size(); i++) {
		if (input.at(i) > max) {
			max = input.at(i);
		}
	}
	return max;
}

int vecSortedMax(vector<int> &input) {
	int max = 0;
	//Make it check for the direction of sort
	max = input.at(input.size() - 1);
	return max;
}


int vectorModeSingle(vector<int> &input) {
	int result = 0;
	vector<int> modes;
	bool exists = false;
	int j = 0;
	int mode = 0;
	int modePos = 0;
	//For loop of all elements in input, Big O of N
	for (int i = 0; i < input.size(); i++) {
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
	for (int x = 1; x < modes.size(); x = x +2) {
		if (modes.at(x) > mode) {
			mode = modes.at(x);
			result = modes.at(x - 1);
		}
	}
	return result;
}

int main() {

	srand(time(0));

	vector<int> randNums(100);
	for (int i = 0; i < randNums.size(); i++) {
		randNums[i] = rand() % 50;
	}

	cout << "Max number: " << vecMax(randNums) << endl;
	cout << "Min Number not working" << endl;
	cout << "Mode is: " << vectorModeSingle(randNums) << endl;

	return 0;



}