#pragma once

#include <vector>
#include <string>
#include <assert.h>

using namespace std;

/*
Hash value = Fixed Length string/number generated deterministically from a variable length input
	Deterministic = For a given input, you always get the same output
					No randomization. If input = 5, output = 7, then every 5 will output 7

Web/Security Example
password1234 (plaintext)
Hash(password1234) =  980234jsfkjg093jkjfd0894
Hash(password123)  =  HB794LJZSD0823LJ098234JJ

Hash Table Example
Hash(742) = 2
Hash(369) = 9
Hash(204) = 4
Hash(839) = 9//Hash Collision - 2 different inputs hash to the same output
					
*/

//Hash Tables are good for searching and inserting in constant time O(1)
template<class T, class K>
class HashTable
{
	struct ValuePair
	{
		T data;
		K key;
		ValuePair(T inputData, K inKey)//Constructor
			: data(inputData), key(inKey)//Member Initialization List
		{
			//data = inputData;
			//key = inKey;
		}
	};

public:
	HashTable(int initialSize = 100)
	{
		table.resize(initialSize);
	}

	int Hash(K key) const//Calculate an array index from whatever 'key' is
	{//Rule is hash values have to be within 0 - (arraySize - 1)

		return key % table.size();
	}

	void Add(K key, T data)
	{
		//ValuePair storedData;
		//storedData.key = key;
		//storedData.data = data;
		//table[Hash(key)].push_back(storedData);

		//table[Hash(key)].push_back(ValuePair(data, key));

		table[Hash(key)].push_back({ data, key });//initializer list
	}


	//Need to create search function similar to search that checks to see if the element is in the array.
	T Search(K key) const
	{
		int hash = Hash(key);
		//Collisions should be rare, so it still behaves like a O(1) function
		for (int i = 0; i < table[hash].size(); ++i)//O(bucketSize)
		{
			if (table[hash][i].key == key)
				return table[hash][i].data;
		}

		//Value wasn't in the table
		//Exception //try, catch, throw
		//assert(false, "A key wasn't found in the table");
		throw string("A key wasn't found in the table");

		//bucket 0:
		//bucket 1:
		//bucket 3:
		//...
		//bucket 9: Jurassic Party, Civil War 
	}
	T operator[](K key) const
	{ 
		return Search(key);
	}
	//Pointer vs. Reference
	//A reference can't be null, and can't be reassigned

private:
	vector<vector<ValuePair>> table;
};

//Template Specialization Class
//Defines what to do if your template argument is a specific data type
//Hash Tables are good for searching and inserting in constant time O(1)
template<class T>
class HashTable<T, string>
{
	struct ValuePair
	{
		T data;
		string key;
		ValuePair(T inputData, string inKey)//Constructor
			: data(inputData), key(inKey)//Member Initialization List
		{
			//data = inputData;
			//key = inKey;
		}
	};

public:
	HashTable(int initialSize = 100)
	{
		table.resize(initialSize);
	}

	int Hash(string key) const//Calculate an array index from whatever 'key' is
	{//Rule is hash values have to be within 0 - (arraySize - 1)

		unsigned long long total = 5381;
		for (int i = 0; i < key.size(); ++i)
		{
			total = total * 33 + key[i];
		}

		//cout << "Hash Value for " << key << ": " << total % table.size() << endl;

		return total % table.size();
	}

	void Add(string key, T data)
	{
		//ValuePair storedData;
		//storedData.key = key;
		//storedData.data = data;
		//table[Hash(key)].push_back(storedData);

		//table[Hash(key)].push_back(ValuePair(data, key));

		table[Hash(key)].push_back({ data, key });//initializer list
	}

	T Search(string key) const
	{
		int hash = Hash(key);
		//Collisions should be rare, so it still behaves like a O(1) function
		for (int i = 0; i < table[hash].size(); ++i)//O(bucketSize)
		{
			if (table[hash][i].key == key)
				return table[hash][i].data;
		}

		//Value wasn't in the table
		//Exception //try, catch, throw
		//assert(false, "A key wasn't found in the table");
		throw string("A key wasn't found in the table");

		//bucket 0:
		//bucket 1:
		//bucket 3:
		//...
		//bucket 9: Jurassic Party, Civil War 
	}
	T operator[](string key) const
	{
		return Search(key);
	}
	//Pointer vs. Reference
	//A reference can't be null, and can't be reassigned


	//Need to create a function to find if a value is in the array
	bool doesExist(string key)const {

		//First find the hashed position of the key
		int hash = Hash(key);
		//This will most likely go to beyond O(N) if the item does not exist
		for (int i = 0; i < table[hash].size(); ++i)//O(bucketSize)
		{
			if (table[hash][i].key == key)
				return true;
		}

		return false;
	}
private:
	vector<vector<ValuePair>> table;
};