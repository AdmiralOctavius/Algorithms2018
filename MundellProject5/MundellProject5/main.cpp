#include <string>
#include "BinarySearchTree.h"
#include <iostream>
#include "Timer.h"

int main() {

	/****************************************************************************************************************
	Learning about Trees!
	*/
	Timer Time;

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
	testTree.DisplayInOrderIterative();

	string result;
	cout << endl;
	Time.Start();
	testTree.Search(4324, result);
	Time.Stop();
	Time.Report();
	cout << endl << result << " " << endl;

	testTree.Balance();

	cout << endl;
	Time.Start();
	testTree.Search(4324, result);
	Time.Stop();
	Time.Report();
	cout << endl << result << " " << endl;
	cout << endl << endl;

	//testTree.DisplayInOrderIterative();
	testTree.DisplayInOrder();
	cout << "hi" << endl;
	return 0;

}