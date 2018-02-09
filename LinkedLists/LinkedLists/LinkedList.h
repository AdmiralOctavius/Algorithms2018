#pragma once

#include <iostream>

using namespace std;

template<class T>
class LinkedList {
public:

	struct Node {
		T data;
		//Pointer to the next node
		Node* next;
		Node(T data, Node* n = nullptr) {
			this->data = data;
			next = n;
		}
	};

	LinkedList() {
		size = 0;
		head = nullptr;
	}

	int GetSize() {
		return size;
	}

	void PushBack(T data) {//O(N)
		if (head == nullptr) {
			head = new Node(data, head);
		}
		else {
			//Node* temp = head;
			//while (temp->next != nullptr) {
				//temp = temp->next;
			//}
			//temp->next = new Node(data);
			tail->next = new Node(data);
			tail = tail->next;
		}
		size++;
	}
	void PushFront(int data) {//O(1)
		if (head == nullptr) {
			head = new Node(data);
			tail = head;
		}
		head = new Node(data, head);
		size++;
	}
	void PopBack() {

	}
	void PopFront() {

	}

private:
	Node* head = nullptr;
	Node* tail = nullptr;
	int size;
};