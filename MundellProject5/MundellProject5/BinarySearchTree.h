#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <assert.h>
#include <stack>
using namespace std;

//Tree - contains nodes that point to any number of child nodes, without any cycles or loops (then it would be a Graph)
	//Binary Tree - each node can have up to 2 children max
		//Binary Search Tree - Binary Tree in which all left children are smaller than their, parent, and parents are smaller than their right children
			//in other words: left child <= parent <= right child
//Each subtree (or branch) is itself a tree - that means we can use recursion!

template<typename T, typename K>//typename same as using class here
class BinarySearchTree//Only works for T's that support <, >, ==
{
public:
	struct Node
	{
		//Binary Search Tree Property = Left Child's Value <= Parent's Value <= Right Child's Value
		Node* left = nullptr;
		Node* right = nullptr;
		T value;
		K key;

		Node(K k, T val = T(), Node* l = nullptr, Node* r = nullptr)
			: key(k), value(val), left(l), right(r)
		{

		}
	};

	BinarySearchTree()
	{
		root = nullptr;
		size = 0;
	}

	~BinarySearchTree()//we need this because we used new in the add function
	{		
		//DestroyHelper(root);//commented out temporarily while I explain some stuff...
	}

	void Add(K insertKey, T val)//O(log(n))
	{
		size++;
		if (!root)//if tree is empty
			root = new Node(insertKey, val);
		else
			AddHelper(root, insertKey, val);
	}

	bool Search(K searchKey, T &result)//O(log(n))
	{
		return SearchHelperIterative(root, searchKey, result);
	}

	void Delete(K searchKey)//O(log(n))
	{
		DeleteHelper(root, searchKey);
	}

	void DisplayInOrder()
	{
		DisplayInOrderHelper(root);
	}

	void DisplayInOrderIterative() {
		DisplayInOrderHelperIterative(root);
	}

	void DisplayPreOrder()
	{
		DisplayPreOrderHelper(root);
	}

	void DisplayPostOrder()
	{
		DisplayPostOrderHelper(root);
	}

	void IterativeAdd(K insertKey, T val)
	{
		if (root == nullptr)
		{
			root = new Node(insertKey, val);
			++size;
		}
		else
		{
			Node* temp = root;
			while (temp != nullptr)
			{
				if (temp->key > insertKey)
				{
					if (temp->left == nullptr)
					{
						temp->left = new Node(insertKey, val);
						++size;
						break;
					}
					else
						temp = temp->left;
				}
				else
				{
					if (temp->right == nullptr)
					{
						temp->right = new Node(insertKey, val);
						++size;
						break;
					}
					else
						temp = temp->right;
				}
			}
		}
	}

	void IterativeAdd(vector<Node*>& nodeVals)
	{
		int i = 0;
		if (root == nullptr)
		{
			root = nodeVals[i];
			++size;
			i++;
		}
		else
		{
			Node* temp = root;
			while (temp != nullptr)
			{
				if (temp->key > nodeVals[i]->insertKey)
				{
					if (temp->left == nullptr)
					{
						temp->left = nodeVals[i];
						++size;
						i++;
						break;
					}
					else
						temp = temp->left;
				}
				else
				{
					if (temp->right == nullptr)
					{
						temp->right = nodeVals[i];
						++size;
						i++;
						break;
					}
					else
						temp = temp->right;
				}
			}
		}
	}
	bool IterativeSearch(K searchKey, T& result) const
	{
		Node* temp = root;
		while (temp != nullptr)
		{
			if (temp->key == searchKey)
			{
				result = temp->value;
				return true;
			}
			else if (temp->key < searchKey)
				temp = temp->right;
			else
				temp = temp->left;
		}
		return false;
	}

	void Balance() {
		//Store nodes
		vector<Node*> nodeVals;

		//Get nodes
		FeedInOrderHelper(root, nodeVals);

		//Display real fast
		for (int i = 0; i < nodeVals.size(); i++) {

			cout << nodeVals.at(i)->value << ", ";
		}


		//delete root
		root == nullptr;
		//Set size to 0
		size = 0;

		//assign all node pointers to null
		for (int i = 0; i < nodeVals.size(); i++) {
			nodeVals[i]->left = nullptr;
			nodeVals[i]->right = nullptr;
			//cout << "Left: " << nodeVals[i]->left << " , Right: " << nodeVals[i]->right << " |";
		}

		//shuffle vector
		//readd items
		for (int i = 0; i < nodeVals.size(); i++) {

		}
	}

private:
	Node* root = nullptr;
	int size = 0;

	void DestroyHelper(Node* node)
	{
		if (node)
		{
			DestroyHelper(node->left);
			DestroyHelper(node->right);
			delete node;
		}
	}

	void AddHelper(Node*& node, K insertKey, T val)//O(log(n))
	{
		if (node == nullptr)
			node = new Node(insertKey, val);
		else if (insertKey < node->key)//go to the left
			AddHelper(node->left, insertKey, val);
		else//go to the right
			AddHelper(node->right, insertKey, val);
	}

	void DeleteHelper(Node*& node, K searchKey)
	{
		if (node)
		{
			if (searchKey == node->key)
			{
				//we found the node, delete it
				//Cases: 0 children, 1 child, 2 children, 
				//and is this node the root? (which actually won't matter in the recursive version of this function since we use a Node*& parameter)

				if (!node->left && !node->right)//has no children
				{
					delete node;
					node = nullptr;
				}
				else if (node->left && node->right)//has 2 children
				{
					//Bump up left side, reattach right 
				}
				else if (node->left)//has a left child
				{
					delete node;
					node = node->left;//Will this work?
				}
				else if (node->right)//has a right child
				{
					delete node;
					node = node->right;
				}
			}
			else if (searchKey > node->key)
				DeleteHelper(node->right, searchKey);
			else
				DeleteHelper(node->left, searchKey);
		}
	}
	
	bool SearchHelperIterative(Node* node, K searchKey, T &result)//O(log(n))
	{
		while (node && node->key != searchKey)
			if (searchKey < node->key)
				node = node->left;
			else
				node = node->right;

		if (node == nullptr)
			return false;

		result = node->value;
		return true;
	}
	
	void DisplayInOrderHelper(Node* node)
	{
		if (node)//Base Case
		{
			//General Case
			DisplayInOrderHelper(node->left);//display left subtree
			cout << node->key << ": " << node->value << ", ";//display parent
			DisplayInOrderHelper(node->right);//display right subtree
		}
	}


	void DisplayInOrderHelperIterative(Node* node)
	{
		/*if (node)//Base Case
		{
			//General Case
			DisplayInOrderHelper(node->left);//display left subtree
			cout << node->key << ": " << node->value << ", ";//display parent
			DisplayInOrderHelper(node->right);//display right subtree
		}*/
		bool notDone = false;
		int sizes = size;
		stack <Node*> output;
		stack <Node*> hitStack;
		//output.push(node);
		hitStack.push(nullptr);

		Node* currentNode = node;
		while (notDone == false) {
			if (hitStack.size() > sizes) {
				break;
			}
			else if (currentNode == root && currentNode->left == hitStack.top()) {
				cout << currentNode->key << ": " << currentNode->value << ", ";
				hitStack.push(currentNode);
				currentNode = currentNode->right;
				//output.pop();
			}
			else if (currentNode->left != nullptr && currentNode->left != hitStack.top()) {
				//Cannot call hitstack When empty
				
					output.push(currentNode);
					currentNode = currentNode->left;
				
			}
			else if (currentNode->right != nullptr && currentNode->right != hitStack.top()) {
					cout << currentNode->key << ": " << currentNode->value << ", ";
					hitStack.push(currentNode);
					output.push(currentNode);
					currentNode = currentNode->right;
				
			}
			//Gets stuck in a loop here
			else if (currentNode != output.top() && currentNode->left == nullptr && currentNode->right == nullptr && currentNode != hitStack.top()) {
				
					cout << currentNode->key << ": " << currentNode->value << ", ";
					//Reassign current node here
					hitStack.push(currentNode);
					currentNode = output.top();
					output.pop();
				
			}
			//Create instance where both paths are in hit stack
			else if (currentNode->left == hitStack.top() && currentNode->right == nullptr || currentNode->right == hitStack.top() && currentNode->left==nullptr) {

				cout << currentNode->key << ": " << currentNode->value << ", ";
				hitStack.push(currentNode);
				currentNode = output.top();
				output.pop();
				//cout << currentNode->key << ": " << currentNode->value << ", ";
				//hitStack.push(currentNode);
				//output.pop();
			}
		
			else if (currentNode->left != nullptr && currentNode->right == hitStack.top()) {
				cout << currentNode->key << ": " << currentNode->value << ", ";
				hitStack.push(currentNode);
				currentNode = output.top();
				output.pop();
				//cout << currentNode->key << ": " << currentNode->value << ", ";
				//hitStack.push(currentNode);
				//output.pop();
			}
			else if (currentNode->right != nullptr && currentNode->left == hitStack.top()) {
				cout << currentNode->key << ": " << currentNode->value << ", ";
				hitStack.push(currentNode);
				currentNode = output.top();
				output.pop();
				//cout << currentNode->key << ": " << currentNode->value << ", ";
				//hitStack.push(currentNode);
				//output.pop();
			}
			else {
				//Should be done
				break;
			}
		}

	}



	void DisplayPreOrderHelper(Node* node)//Print parent first, then left child, then right child. Root appears first
	{
		if (node)//Base Case
		{
			//General Case
			cout << node->key << ": " << node->value << ", ";//print parent
			DisplayPreOrderHelper(node->left);//display left subtree
			DisplayPreOrderHelper(node->right);//display right subtree
		}
	}
	
	void DisplayPostOrderHelper(Node* node)//Print children first, then parent. Root will be displayed last
	{
		if (node)//Base Case
		{
			//General Case
			DisplayPostOrderHelper(node->left);//display left subtree
			DisplayPostOrderHelper(node->right);//display right subtree
			cout << node->key << ": " << node->value << ", ";//print parent
		}
	}

	void FeedInOrderHelper(Node* node, vector<Node*>& nodeVals)
	{
		if (node)//Base Case
		{
			//General Case
			FeedInOrderHelper(node->left, nodeVals);//display left subtree
			nodeVals.push_back(node);
			FeedInOrderHelper(node->right, nodeVals);//display right subtree
		}
	}
	
};