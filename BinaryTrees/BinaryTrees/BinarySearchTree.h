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
		if (!root) {//If tree is empty
			root = new Node(insertKey, val);
		}
		else {
			AddHelper(root, insertKey, val);

		}
	}



	T search(K searchKey) {//O(log(n))

	}

	void Delete(K searchKey) {//O(log(n))
		DeleteHelper(searchKey);
	}

	void DisplayInOrder() {
		DisplayInOrderHelper(root);
	}

	void DisplayPreOrder(){
		DisplayPreOrderHelper(root);
	}

	void DisplayPostOrder() {
		DisplayPreOrderHelper(root);
	}
	//Display
	~BinarySearchTree() {

	}
private:

	Node* root = nullptr;
	int size = 0;

	void AddHelper(Node* node, K insertKey, T val) {
		if (node == nullptr) {
			node = new Node(insertKey, val);
		}
		else if (insertKey < temp->key) {//goto the left
			AddHelper(node->left, insertKey, val);
		}
		else {//goto the right
			AddHelper(node->right, insertKey, val);
		}
	}

	void DisplayInOrderHelper(Node* node) {//In order
		if (node) {//Base case
			DisplayInOrderHelper(node->left);//Display left subtree
			cout << node->value << ", ";
			DisplayInOrderHelper(node->right);//Display right subtree
		}
		
	}
	void DisplayPreOrderHelper(Node* node) {//Parent first
		if (node) {//Base case
			cout << node->value << ", ";
			DisplayPreOrderHelper(node->left);//Display left subtree
			DisplayPreOrderHelper(node->right);//Display right subtree
		}

	}

	void DisplayPostOrderHelper(Node* node) {//children first then parent
		if (node) {//Base case
			DisplayPostOrderHelper(node->left);//Display left subtree
			DisplayPostOrderHelper(node->right);//Display right subtree
			cout << node->value << ", ";
		}

	}

	T SearchHelper(Node* node, K searchKey) {
		if (node->key == searchKey) {
			return node->value;
		}
		else if (searchKey > node->key) {
			return SearchHelper(node->right, searchKey);
		}
		else {
			return SearchHelper(node->left, searchKey);
		}
	}

	void DeleteHelper(Node* node, K searchKey) {
		if (node) {
			if (searchKey == node->key) {

			}
			else if (searchKey > node->key) {
				DeleteHelper(node->right, searchKey);
			}
			else{
				DeleteHelper(node - left, searchKey);
			}
		}
	}
};