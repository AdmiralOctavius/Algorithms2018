/**
Student: Isaac Bennett
Class: Cit 238-201
Professor: Matt Mundell
---
Assignment: Assignment 4-Lists and hash tables (and unordered map, the better hash table)

Help recieved:
Philip Taylor helped me understand how the unordered map actually functions.
Dylan White and Kristofer Constantino helped me double check my HashTable, and assured me I was overthinking the problem.



**/




#include <iostream>
#include <string>
#include "MemLeakDetector.h"
#include "Timer.h"
#include <time.h>
#include <algorithm>

//HashTable call
#include <unordered_map>
#include "HashTable.h"
#include "LinkedList.h"

//Unorded map mode function
void MapModes(unordered_map<string, int>& input) {
	
	//Stores instances of numbers
	unordered_map<int, int> mode;

	//Iterators to parse through the maps
	unordered_map<string, int>::iterator itr;
	unordered_map<int, int>::iterator iter;
	
	//Initial for loop to parse through unordered map
	for (itr = input.begin(); itr != input.end(); itr++)
	{
		// itr works as a pointer to pair<string, double>
		// type itr->first stores the key part  and
		// itr->second stores the value part
		//cout << itr->first << "  " << itr->second << endl;

		//Assigns the mode map an instance of a number the for loop is on, and increment that number
		mode[itr->second] = mode[itr->second]++;

	}
	//Set the second iterator to the beginning of the mode map
	iter = mode.begin();
	//Set the highest value to the first count
	int highest = iter->second;
	int count = 1;

	//Set the highest instance variable to the highest instance
	for (iter = mode.begin(); iter != mode.end(); iter++) {
		if (iter->second > highest) {
			highest = iter->second;
		}
	}

	//Check for similar highest instances
	for (iter = mode.begin(); iter != mode.end(); iter++) {
		if (iter->second == highest) {
			//Print out the modes
			cout << "Mode " << count << ": " << iter->first << endl;
			count++;
		}
	}

}

//Old Vector Mode function
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


int main()
{
	Timer timer;
	srand(time(0));

	//Linked list testing
	LinkedList<int> myList;

	myList.PushBack(5);
	myList.PushBack(7);
	myList.PushBack(11);

	cout << myList.GetSize() << endl;

	myList.PopBack();
	myList.PopFront();
	myList.PushFront(132);
	
	cout << myList.GetSize() << endl;
	//End Linked list testing


	//Unordered map testing
	unordered_map<string, int> map;

	//Inserting values into the map
	map["MyKey"] = 45;
	map["MyKey"] = 34;
	map["Lol"] = 101;
	map["KingKey"] = 666;
	map["myMyMYmy"] = 202;

	map["KinggKey"] = 666;
	map["KingggKey"] = 666;
	map["MyFwend"] = 123;
	map["KingKeeey"] = 667;
	map["lolol"] = 101;

	map["lolol"] = 102;
	map["MyFriendy"] = 125;
	map["niceTest"] = 101;
	map["mymymy"] = 102;
	map["funfunfun"] = 102;

	//Testing key finding
	string key = "Pi";
	string key2 = "Lol";

	if (map.find(key) == map.end())
		cout << key << " not found";
	else
		cout << "Found " << key << endl;

	if (map.find(key2) == map.end())
		cout << key2 << " not found";
	else
		cout << "Found " << key2	 << endl;

	cout << map.size() << endl;

	//Testing running through the map
	unordered_map<string, int>::iterator itr;
	cout << "\nAll Elements : \n";
	for (itr = map.begin(); itr != map.end(); itr++)
	{
		// itr works as a pointer to pair<string, double>
		// type itr->first stores the key part  and
		// itr->second stroes the value part
		cout << itr->first << "  " << itr->second << endl;
	}

	//Mode Finder for unordered map of 15 values
	timer.Start();
	MapModes(map);
	timer.Stop();
	timer.Report();


	cout << endl << endl << endl;


	//Create vector of 15 values
	vector<int> randomNums;
	for (int i = 0; i < 15; i++) {
		randomNums.push_back(rand() % 100);
	}
	//Test vector mode against map mode
	//Note: my old vector mode function returned a vector, which will most likely slow it down
	timer.Start();
	vector<int> modes = vectorModeMultiple(randomNums);
	for (int i = 0; i < modes.size(); i++) {
		cout << "Mode " << i << ": " << modes[i] << ", ";
	}
	timer.Stop();
	timer.Report();

	//Hashtable testing
	HashTable<int, string> myHash;

	myHash.Add("myHash", 12);
	myHash.Add("Feysa", 762);
	myHash.Add("Feysa", 761);
	myHash.Add("myHdfsdfsh", 6752);
	myHash.Add("myHwrweh", 6542);
	myHash.Add("my243h", 152);
	myHash.Add("mybsh", 1234);
	myHash.Add("myHash", 11);

	//Testing the doesExist function
	if (myHash.doesExist("myHash")) {
		cout << "Found it!" << endl;
	}
	else {
		cout << "Nope!" << endl;
	}

	//Testing Delete element
	myHash.deleteElement("Feysa");
	myHash.deleteElement("Feysa");
	myHash.deleteElement("dsfa");
	myHash.deleteElement("mybsh");

	myHash.Add("Feysa", 765);
	myHash.Add("Feysa", 74321);
	myHash.Add("Feysa", 7325);
	myHash.deleteElement("Feysa");



    return 0;
}

