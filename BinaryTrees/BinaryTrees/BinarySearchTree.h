#pragma once

#include <iostream>
#include <vector>

template<typename T, typename K>//typename same as using class
class BinarySearchTree
{
public:
	struct Node {
		Node* leftChild = nullptr;
		Node* rightChild = nullptr;
		T value;
		Node(T val = T(), Node* left = nullptr, Node* right = nullptr)
			: value(val), leftChild(left), rightChild(right)
		{
		
		}
	};

	BinarySearchTree() {
		root = nullptr;
		size = 0;
	}

	void Add(K insertKey, T val) {//O(log(n))

	}

	T search(K searchKey) {//O(log(n))

	}

	void Remove(K searchKey) {//O(log(n))

	}


	~BinarySearchTree() {

	}
private:

	Node* root = nullptr;
	int size = 0;

};