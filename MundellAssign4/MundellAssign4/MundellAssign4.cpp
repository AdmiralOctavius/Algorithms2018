// MundellAssign4.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <string>
#include "HashTable.h"
#include "LinkedList.h"
#include "MemLeakDetector.h"
//HashTable call
#include <unordered_map>

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

	map.emplace(45);
	cout << map.find(45);
    return 0;
}

