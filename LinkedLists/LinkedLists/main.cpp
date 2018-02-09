#include <iostream>

#include "LinkedList.h"

int main(){

	//Calling the node struct within linked list
	LinkedList<int>::Node n(1);
	LinkedList<int> intList;
	cout << intList.GetSize() << endl;
	intList.PushBack(1);
	intList.PushBack(2);
	intList.PushFront(3);
	return 0;
}