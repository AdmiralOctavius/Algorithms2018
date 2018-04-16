#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

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

//Predicate 
bool SortItemsByDecreasingValue(const Item &l, const Item &r)
{
	return l.valuePerPound > r.valuePerPound;
}

//O(n)
//Returns the most profitable combination of items from shopInventory
//Assumes shopInventory is sorted by order of value per weight.
vector<Item> PartialKnapsack(vector<Item> &shopInventory, double weightLimit)//Renamed from 'StealStuff'
{
	vector<Item> knapsack;

	double currentWeight = 0;

	while (currentWeight < weightLimit && shopInventory.size())
	{
		knapsack.push_back(shopInventory[0]);
		if (shopInventory[0].weight + currentWeight > weightLimit)//take part 
		{
			double leftOver = weightLimit - currentWeight;
			knapsack.back().weight = leftOver;
			currentWeight = weightLimit;
			shopInventory[0].weight -= leftOver;
		}
		else//take all of it
		{
			currentWeight += shopInventory[0].weight;
			shopInventory.erase(shopInventory.begin());
		}
	}

	return knapsack;
}

void DisplayItems(const vector<Item> &items)
{
	if (items.size() == 0)
		cout << "No items! :(" << endl;
	else
		for (auto val : items)
			cout << val.name << ": " << val.weight << " lbs worth " << val.Total() << " gold" << endl;
}

//Assignment 7: Finish this!
//In this version we CANNNOT take parts of items. Its either all or nothing.
//This algorithm is like the Fibonacci one - it takes forever if you do it 
//the 'easy' recursive way which is O(n*2^n), but with dynamic programming its efficient.
//This is O(n * w) where n is the number of items, w is the weight limit
//Returns the most profitable combination of items from shopInventory 
//Sorting is not required ahead of time for this one
vector<Item> BinaryKnapsack(vector<Item> &shopInventory, double weightLimit)
{
	vector<Item> knapsack;

	//First, just return an empty knapsack if the shopInventory is empty or the weight limit is less than or equal to 0. Sad thief face.

	//Create a table of rows and columns. NumRows = number of items + 1, NumColumns = weightLimit + 1
	//This table will store the maximum value we can get if we take the items in that column. (where we 'memoize' results)
	//You can use a vector of vectors (vector<vector<int>>) or a multidimensional array (int **arr w/ new and delete)
	//It should be a table of 'prices', whether you use int or double is up to you.

	//Loop from i = 0 up to the number of items + 1. i is the current item.
	//Loop from j = 0 up to weight limit + 1. j is the current weight.
	//If i or j is 0, set table[i][j] = 0.
	//otherwise if the previous (i-1) item's weight is less than or equal to j
	//calculate the max value with this item as its total price + the price in table[i-1][j - (int)shopInventory[i-1].weight]
	//calculate the previous max for this column as table[i-1][j]
	//set table[i][j] = the higher of the two values
	//otherwise
	//set table[i][j] = table[i-1][j].

	//At this point we have a table of how much profit we can achieve for every combination of items.
	//The value in the bottom right is the optimal amount we can make.
	//You may optionally want add some code to display that value or the whole table here to help you finish the algorithm.

	//Now we actually take the items that gives us that max value.
	//set i = number of items, j = weightLimit
	//while i is greater than 0 and j is greater or equal to 0
	//if table[i][j] is not equal to table[i-1][j] (then item i-1 must've contributed to our optimal value, so...)
	//take item i-1. Subtract its weight from j. Put the item in the knapsack, and erase it from the shop's inventory
	//decrease i by 1. 

	//Delete any dynamically allocated data you have (if you made any)

	return knapsack;
}

int main()
{
	double weightLimit = 25;
	cout << "Weight Limit: " << weightLimit << endl << endl;

	cout << "The Partial Knapsack Algorithm (which uses Greedy Programming):" << endl;
	vector<Item> alchemistInventory;
	alchemistInventory.push_back({ "Gunpowder", 30, 10 });
	alchemistInventory.push_back({ "Healing Potion", 50, 1 });
	alchemistInventory.push_back({ "Giant Strength Potion", 10, 100 });
	alchemistInventory.push_back({ "Invisibility Potion", 5, 150 });

	cout << "The Alchemist's Inventory:" << endl;
	DisplayItems(alchemistInventory);

	//Using a predicate function:
	sort(alchemistInventory.begin(), alchemistInventory.end(), SortItemsByDecreasingValue);

	cout << endl << "After Sorting." << endl;
	DisplayItems(alchemistInventory);

	cout << endl << "Stealing some items..." << endl;
	vector<Item> result = PartialKnapsack(alchemistInventory, weightLimit);
	DisplayItems(result);

	cout << endl << "Now, the Binary Knapsack Algorithm (which uses Dynamic Programming):" << endl;
	vector<Item> blacksmithInventory;
	blacksmithInventory.push_back({ "Spear", 10, 8 });//80 gold total
	blacksmithInventory.push_back({ "Sword", 20, 10 });//remember 20 is the weight, 10 is the value per pound. Sword = 200 gold total
	blacksmithInventory.push_back({ "Shield", 15, 9 });//135 gold total 

	cout << "The Blacksmith's Inventory:" << endl;
	DisplayItems(blacksmithInventory);

	//Assignment 7:
	//When you are done, the the correct (most profitable) result should be taking the Spear and the Shield worth 215 total.
	//Even though the sword is worth the most per pound, if we take it then we don't have enough
	//room for anything else. If we take the Spear then we can also take the Shield, getting a higher total value.
	cout << endl << "Stealing some items..." << endl;
	result = BinaryKnapsack(blacksmithInventory, weightLimit);
	DisplayItems(result);

	return 0;
}