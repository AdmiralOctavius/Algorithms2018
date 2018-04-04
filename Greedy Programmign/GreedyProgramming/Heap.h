#pragma once

#include <iostream>
#include <assert.h>
#include <functional>

using namespace std;

/*
Heap 
Can be represented as a Binary Tree
Max-Heap - Every child is smaller than its parent
Min-Heap - every child is larger than its parent
A heap efficiently keeps track of the largest or smallest value in a set

1 6 3 7 5 9 3 2 3 6 4 2 
In a max heap, the root of these would be 9
In a min heap it would be 1

*/

template<class T>
class Heap
{
private:
	int capacity;
	int end;//end will point to the space AFTER the last added element in arr
	T* arr;
	bool maxHeap;
	bool isBuilt;

	void Swap(int index1, int index2)
	{
		swap(arr[index1], arr[index2]);
	}

	void BuildHeap()
	{
		//Create a heap (meeting the heap rules) out of a random array
		for (int i = (end - 1) / 2; i >= 0; --i)
			Heapify(i);
	}

	void Heapify(int parentIndex)//compare 3 nodes, swap them to make a true heap
	{
		int leftChild = LeftChild(parentIndex);
		int rightChild = RightChild(parentIndex);

		if (leftChild >= end || rightChild >= end)
			return;

		if (arr[parentIndex] > arr[leftChild] && arr[parentIndex] > arr[rightChild])
			return;
		else if (arr[leftChild] > arr[rightChild])
		{
			swap(arr[parentIndex], arr[leftChild]);
			Heapify(leftChild);
		}
		else
		{
			swap(arr[parentIndex], arr[rightChild]);
			Heapify(rightChild);
		}
	} 

public:
	Heap(int cap = 50, bool maxHeap = true)
		: capacity(cap),
		maxHeap(maxHeap),
		end(0)
	{
		arr = new T[capacity];
	}

	~Heap()
	{
		delete[] arr;
	}

	void Clear()
	{
		end = 0;
	}

	bool Empty()
	{
		if (end == 0)
			return true;
		return false;

		if (isBuilt == false) {
			BuildHeap();
			isBuilt = true;
		}
		//or
		return !end;
	}

	int Size()
	{
		return end;
	}

	void Add(T data)
	{
		if (end == capacity)
			Resize(capacity * 2);
		arr[end++] = data;

		//Need to move this elsewhere
		//BuildHeap();

		if (isBuilt == true) {
			isBuilt = false;
		}
	} 

	void Display()
	{
		if (isBuilt == false) {
			BuildHeap();
			isBuilt = true;
		}
		for (int i = 0; i < end; ++i)
			cout << arr[i] << ", ";
		cout << endl;
	}

	void Verify()
	{
		if (isBuilt == false) {
			BuildHeap();
			isBuilt = true;
		}
		for (int i = 0; i < (end - 1) / 2; ++i)
			if (arr[LeftChild(i)] > arr[i] || arr[RightChild(i)] > arr[i])
			{
				cout << "Not a valid heap.";
				break;
			}
	}
	 
	void Resize(int newSize)//This is just like a vector's resize (we've done it before so I gave you this one)
	{
		capacity = newSize;

		T* arr2 = new T[capacity];
		for (int i = 0; i < end; ++i)//C++ range-based for loop, basically just a For Each loop like other languages have. Added to C++ in 2011.
			arr2[i] = arr[i];
		delete[] arr;
		arr = arr2;
	}

	T Top()
	{
		if (isBuilt == false) {
			BuildHeap();
			isBuilt = true;
		}
		return arr[0];
	}

	void Pop()
	{ 
		swap(arr[0], arr[--end]);
		Heapify(0);
	}

	T ExtractTop()
	{
		if (isBuilt == false) {
			BuildHeap();
			isBuilt = true;
		}
		T top = Top();
		Pop();
		return top;
	}
	
	int Parent(int index)
	{
		if (isBuilt == false) {
			BuildHeap();
			isBuilt = true;
		}
		return (index - 1) / 2;//ints won't include decimals so it works for right children too
	}

	int LeftChild(int index)//0 is the root, 1 is its left child. 1's left child is 3, 
	{
		if (isBuilt == false) {
			BuildHeap();
			isBuilt = true;
		}
		return index * 2 + 1;
	}

	int RightChild(int index)
	{
		if (isBuilt == false) {
			BuildHeap();
			isBuilt = true;
		}
		return index * 2 + 2;
	}
};