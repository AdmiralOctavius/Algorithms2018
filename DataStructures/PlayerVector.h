#pragma once

#include <iostream>
using namespace std;

#include "Player.h"

class PlayerVector
{
public:
	PlayerVector()//default constructor
	{
		size = 0;
		capacity = 3;
		playerArray = new Player[capacity];
		cout << "In PlayerVector Constructor" << endl;
	}

	void PushBack(Player p)//If not growing, O(1), otherwise O(n)
	{
		cout << "Pushing player" << endl;
		if (size >= capacity)
			Grow();
		playerArray[size++] = p;
	}

	void PushFront(Player p)//O(n) (no matter what)
	{

	}

	void Grow()//O(n)
	{
		cout << "Growing..." << endl;
		capacity *= 2;
		Player* temparray = new Player[capacity];//make bigger array
		for (int i = 0; i < size; ++i)
			temparray[i] = playerArray[i];//Copying old values into new array
		delete[] playerArray;//If we don't delete our memory we get a Memory Leak
		playerArray = temparray;
	}

	~PlayerVector()//Destructor
	{
		cout << "In PlayerVector Destructor" << endl;
		if(playerArray)
			delete[] playerArray;
	}
private:
	int size, capacity;
	Player* playerArray = nullptr;
};