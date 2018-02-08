#include <iostream>
#include <random>
#include <time.h>
#include <string>

#include "Player.h"
#include "PlayerVector.h"

using namespace std;

int main()
{
	cout << "MaxHP for a player is: " << Player::GetMaxHP() << endl;
	Player mainCharacter;
	cout << mainCharacter.GetName() << endl;

	mainCharacter.SetName("Barbatos");
	cout << mainCharacter.GetName() << endl;
	cout << mainCharacter.GetHP() << endl;

	Player player2("Joe Bob", 50);
	mainCharacter.Attack(player2);
	mainCharacter.Attack(player2);
	mainCharacter.Attack(player2);
	mainCharacter.Attack(player2);
	mainCharacter.Attack(player2);
	mainCharacter.Attack(player2);
	cout << player2.GetHP() << endl;

	int num = 5;
	int* intPtr = &num;
	cout << intPtr << endl;//Outputs address
	cout << *intPtr << endl;//Dereferences pointer, outputs 5

	Player* playerPtr = &mainCharacter;
	cout << "Address of mainCharacter: " 
		<< playerPtr << endl;

	cout << "Character's name: "
		<< (*playerPtr).GetName() << endl;

	cout << "Character's name: "
		<< playerPtr->GetName() << endl;

	playerPtr = &player2;

	cout << "Player2's name: "
		<< playerPtr->GetName() << endl;

	//This pointer points at nothing
	//And we can check for that!
	Player* ptr2 = nullptr;
	cout << ptr2 << endl;
	if (ptr2 == nullptr)
		cout << "ptr2 is ready to point at something!" << endl;

	//For this, we'd have to overload the << operator
	//for our user defined type 'Player'
	//cout << mainCharacter << endl;

	int numPlayers = 4;
	//Player players[numPlayers];//Can't do this
	Player* players = new Player[numPlayers];
	players[0].SetName("Sally");
	players[1].SetName("Fred");
	players[2].SetName("Bob");
	players[3].SetName("Jen");


	PlayerVector players2;
	players2.PushBack(players[0]);
	players2.PushBack(players[1]);
	players2.PushBack(players[2]);
	players2.PushBack(players[3]);
	
	delete[] players;//Deallocate our dynamic array

	return 0;
}