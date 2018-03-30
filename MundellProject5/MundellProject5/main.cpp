/*****
Name: Isaac Bennett
Class: CIT-238-201
Professor: Matt Mundell
---
Assignment: 5 Trees and stuff
Notes: Big thanks to Philip Taylor, Anthony Brown, and Dylan White, as well as Kris Constantino for explaining the iterative display to me.
I got lost in the weeds attempting to do the iterative display section.
I left my previous two attempts to show my flawed thought process, I learned that sometimes I really do over think things.

On the other hand I believe my balance tree function is very efficient and works well.

Hopefully I did a good job by your standard!
Thanks,
Isaac Bennett.


****/


#include <string>
#include "BinarySearchTree.h"
#include <iostream>
#include "Timer.h"
#include <time.h>

using namespace std;

int main() {

	//Seeding time
	srand(time(NULL));

	//Testing out the functions!
	Timer Time;
	string value;
	BinarySearchTree<string, int> testTree;
	testTree.Add(5, "Maple Syrup");
	testTree.Add(4, "Ice Cream");
	testTree.Add(3, "Banana");
	testTree.Add(7, "Orange");
	testTree.Add(6, "Nuget");
	testTree.Add(4324, "Wales");
	testTree.Add(542, "Testing party");
	testTree.Add(43, "Filler");
	testTree.Add(34, "Car");
	testTree.Add(423, "weqege");
	testTree.Add(2313, "Net");
	testTree.Add(123, "Waddle");

	//Testing this before we add more values
	testTree.DisplayInOrderIterative();

	for (int i = 0; i < 10000; i++) {
		value = to_string(rand() % 10000);
		testTree.Add(rand() % 10000, value);
	}

	//Searching for a different value seems to be dependant on how big the vector is

	//Create random numbers to use as keys

	int key = rand() % 10000;
	int key2 = rand() % 10000;
	int key3 = rand() % 10000;
	string result;

	//After doing a bunch of tests, the balanced tree ends up being more often faster, but the unordered one gets lucky
	cout << endl;
	Time.Start();
	testTree.Search(key, result);
	Time.Stop();
	Time.Report();
	cout << endl << result << " " << endl;

	cout << endl;
	Time.Start();
	testTree.Search(key2, result);
	Time.Stop();
	Time.Report();
	cout << endl << result << " " << endl;

	cout << endl;
	Time.Start();
	testTree.Search(key3, result);
	Time.Stop();
	Time.Report();
	cout << endl << result << " " << endl;

	//Test Balance
	testTree.Balance();

	cout << endl;
	Time.Start();
	testTree.Search(key, result);
	Time.Stop();
	Time.Report();
	cout << endl << result << " " << endl;

	cout << endl;
	Time.Start();
	testTree.Search(key2, result);
	Time.Stop();
	Time.Report();
	cout << endl << result << " " << endl;

	cout << endl;
	Time.Start();
	testTree.Search(key3, result);
	Time.Stop();
	Time.Report();
	cout << endl << result << " " << endl;


	
	return 0;

}