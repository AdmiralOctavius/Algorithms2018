// MundellAssign4.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <string>
#include "HashTable.h"
#include "LinkedList.h"
#include "MemLeakDetector.h"
//HashTable call
#include <unordered_map>
#include "OldMode.h"

void HashedModes(unordered_map<string, int>& input) {
	
	unordered_map<int, int> mode;

	unordered_map<string, int>::iterator itr;
	unordered_map<int, int>::iterator iter;
	
	for (itr = input.begin(); itr != input.end(); itr++)
	{
		// itr works as a pointer to pair<string, double>
		// type itr->first stores the key part  and
		// itr->second stores the value part
		//cout << itr->first << "  " << itr->second << endl;
		
		mode[itr->second] = mode[itr->second]++;

	}
	iter = mode.begin();
	int highest = iter->second;
	int count = 1;

	for (iter = mode.begin(); iter != mode.end(); iter++) {
		if (iter->second > highest) {
			highest = iter->second;
		}
	}

	for (iter = mode.begin(); iter != mode.end(); iter++) {
		if (iter->second == highest) {
			cout << "Mode " << count << ": " << iter->first << endl;
		}
	}

}



int main()
{

	LinkedList<int> myList;

	myList.PushBack(5);
	myList.PushBack(7);
	myList.PushBack(11);

	cout << myList.GetSize() << endl;

	myList.PopBack();
	myList.PopFront();
	myList.PushFront(132);
	
	cout << myList.GetSize() << endl;


	unordered_map<string, int> map;

	map["MyKey"] = 45;
	map["MyKey"] = 34;
	map["Lol"] = 101;

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

	map["KingKey"] = 666;
	map["MyFwend"] = 123;
	map["KingKeeey"] = 667;
	map["lolol"] = 101;
	map["lolol"] = 102;
	map["MyFriendy"] = 125;
	map["niceTest"] = 101;
	cout << map.size() << endl;
	unordered_map<string, int>::iterator itr;
	cout << "\nAll Elements : \n";
	for (itr = map.begin(); itr != map.end(); itr++)
	{
		// itr works as a pointer to pair<string, double>
		// type itr->first stores the key part  and
		// itr->second stroes the value part
		cout << itr->first << "  " << itr->second << endl;
	}

	HashedModes(map);

	///map.emplace(45);
	//cout << map.at(map.hash_function("45"));


	HashTable<int, string> myHash;

	myHash.Add("myHash", 12);
	myHash.Add("Feysa", 762);
	myHash.Add("myHdfsdfsh", 6752);
	myHash.Add("myHwrweh", 6542);
	myHash.Add("my243h", 152);
	myHash.Add("mybsh", 1234);
	myHash.Add("myHash", 11);

	if (myHash.doesExist("myHash")) {
		cout << "Found it!" << endl;
	}
	else {
		cout << "Nope!" << endl;
	}

	myHash.deleteElement("Feysa");
	myHash.deleteElement("dsfa");
    return 0;
}

