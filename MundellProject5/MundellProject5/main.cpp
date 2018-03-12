#include <string>
#include "BinarySearchTree.h"
#include <iostream>


int main() {

	/****************************************************************************************************************
	Learning about Trees!
	*/

	BinarySearchTree<string, int> testTree;
	testTree.Add(5, "Maple Syrup");
	testTree.Add(4, "Ice Cream");
	testTree.Add(3, "Banana");
	testTree.Add(7, "Orange");
	testTree.Add(6, "Nuget");
	testTree.Add(8, "Waffle");

	testTree.DisplayInOrderIterative();


	return 0;

}