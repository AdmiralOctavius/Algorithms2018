#pragma once

//Need the highest

class Item
{
public:
	Item(string n, double w, double vPP)
		: name(n), weight(w), valuePerPound(vPP)
	{

	}

	string name;
	double weight;
	double valuePerPound;
	double Total()
	{
		return valuePerPound * weight;
	}

	bool operator<(const Item& rhs) const
	{
		return valuePerPound < rhs.valuePerPound;
	}

	bool operator>(const Item& rhs) const
	{
		return valuePerPound > rhs.valuePerPound;
	}
};

class Coin {

public: 
	Coin(string n, double v ) : name(n), value(v){

	}

	string name;
	double value;
	double count;

	bool operator<(const Coin& rhs) const {
		return value < rhs.value;
	}
	bool operator>(const Coin& rhs) const {
		return value > rhs.value;
	}
};

//Predicate 
bool SortItemsByDecreasingValue(const Item &l, const Item &r)
{
	return l.valuePerPound > r.valuePerPound;
}

class SortItemsFunctor {

public:
	bool desc = true;
	bool operator()(const Item &l, const Item &r) {
		if (desc)
			return l.valuePerPound > r.valuePerPound;
		else
			return r.valuePerPound > l.valuePerPound;
	}
};

/*
Greedy Algorithms
At each step, pick the locally optimal solution,
hoping for a globally optimal outcome
Locally Optimal would be like taking a
chess piece as soon as you can, without considering several moves ahead.
In that example, the greedy approach would NOT guarantee
the globally optimal outcome (winning the game)
But for some problems the greedy approach does guarantee the right answer

Partial Knapsack Problem
We are a thief going into a store to steal stuff. We have a weight limit,
so we can only carry so much.
What do we take to maximize our ill-gained profits?
In this 'Partial' problem we can take parts of an item.

We can carry 20lbs.

Gunpowder:				10 gold/lb,		30lbs
Healing Potion:			1 gold/lb,		50lbs
Giant Strength Potion:	100 gold/lb		10lbs
Invisibility Potion:	150 gold/lb		5lbs

Binary Knapsack Problem
We can only take whole things
We can carry 50lb.

1 Sword:				100 gold,	20lb
2 Magic Short-Sword:	500 gold,	10lb
3 Shield x 10:		30 gold,	5lb
4 Kite Shield:		200 gold,	40lb
5 Magic Tower Shield: 1000 gold,	60lb

Item 2 + 4 = 700 gold in 50lbs
Item 2 + 3 (8 of them) = 740 gold in 50lbs

*/



//Get change calculator
vector<Coin> ChangeCalc(vector<Coin> &shopChange, double maxNeeded) {

	//Setup Values
	SortItemsFunctor sorter;
	vector<Coin> changeWallet;
	double currentVal = 0;

	//Add the blank coins to the array
	for (int i = 0; i < shopChange.size(); i++) {
		changeWallet.push_back(shopChange.at(i));
		changeWallet.at(i).count = 0;
		
	}

	//Simple while loop function that adjusts to the coins available
	while (currentVal < maxNeeded) {
		for (int i = 0; i < shopChange.size(); i++) {
			while (shopChange.at(i).value + currentVal <= maxNeeded) {
				currentVal += shopChange.at(i).value;
				changeWallet[i].count++;
			}
		}
	}

	//Return vector of coins
	return changeWallet;
}