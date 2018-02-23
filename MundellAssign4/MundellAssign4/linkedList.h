#pragma once

#include <iostream>

using namespace std;

//Doubly Linked List (If you haven't noticed, putting a comment here makes it appear as a tooltip when you hover over the name of the class/function!!!)
template<class T>
class LinkedList
{
public:
	struct Node//struct is identical to class, but public by default (in C++ - it has other differences in other languages)
	{
		T data;
		Node *next, *prev;
		Node(T data, Node* n = nullptr, Node* p = nullptr)
		{
			this->data = data;
			next = n;
			prev = p;
		}
	};

	LinkedList()//Constructor (Default Constructor - no parameters)
	{
		size = 0;
		head = tail = nullptr;
	}

	~LinkedList()//Destructor (added after class since we ran out of time). Needed to delete allocated memory when list is destroyed.
	{
		cout << "In linked list destructor." << endl;

		Node* temp = head;
		while (temp != nullptr)
		{
			temp = temp->next;
			delete head;
			head = temp;
		}
	}

	int GetSize()
	{
		return size;
	}

	void PushBack(T data)//O(1) now that we have a 'tail' pointer
	{
		if (head == nullptr)
		{
			head = new Node(data);
			tail = head;
		}
		else
		{
			tail->next = new Node(data);
			//Assignment 4: Need a line of code here to maintain the Doubly Linked List property (Hint: Draw it!)
			tail = tail->next;
		}

		++size;
	}

	void PushFront(T data)//O(1)
	{
		if (head == nullptr)//List is empty. Could also do if(!head)
		{
			head = new Node(data);
			tail = head;
		}
		else
		{
			head = new Node(data, head);
			//Assignment 4: Need a line of code here to maintain the Doubly Linked List property (Hint: Draw it!)
		}

		++size;
	}

	void PopBack()
	{
		if (tail == nullptr)//empty list
			return;

		if (head == tail)//list has one element
		{
			delete head;
			head = tail = nullptr;
			--size;

			return;
		}

		//Singly Linked List Method (O(n))
		//Node* temp = head;
		//while (temp->next != tail)
		//	temp = temp->next;
		//
		//temp->next = nullptr;
		//delete tail;
		//tail = temp;

		//Assignment 4: Doubly Linked List Method (O(1)) (Hint: Draw it!)		
		//???

		--size;
	}

	void Remove(Node* n)
	{
		n->prev->next = n->next;
		n->next->prev = n->prev;
		delete n;

		--size;
	}

	void PopFront()
	{
		if (head == nullptr)
			return;

		Node* temp = head;
		head = head->next;
		//Assignment 4: Need a line of code here to maintain the Doubly Linked List property (Hint: Draw it!)
		delete temp;

		--size;
	}

private:
	Node* head = nullptr;
	Node* tail = nullptr;
	unsigned int size = 0;
};