/*

Name: Isaac Bennett
Class: Cit-238-201
Professor: Matt Mundell
----
Assignment: Assignment 6 – Heaps, Greedy Algorithms and Pattern Matching
Notes: Help recieved: Dylan White, Kristofer Constantino

This was rough, and I did Rabin Karp first.
Greedy was fun to work on, since adding different coins was cool



*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include "RabinKarp.h"
#include "Heap.h"
#include "GreedyCoinAlg.h"
#include "Timer.h"
#include <streambuf>
#include <fstream>
using namespace std;


string ReadFile(string filename)
{
	string result = "";
	ifstream fin;
	fin.open(filename);

	//Figure out how much space we need to store the file contents
	fin.seekg(0, ios::end);//Move to end of the file
	result.reserve(fin.tellg());
	fin.seekg(0, ios::beg);//Move to beginning of the file

						   //Read the file. Multiple ways to do this; this method is fast for simply grabbing everything (no parsing)
	result.assign(istreambuf_iterator<char>(fin), istreambuf_iterator<char>());

	fin.close();//Make sure to do this - otherwise it'll say 'file is open in another program' until you restart your computer (usually)
	return result;
}


vector<int> ComputePrefixArray(const string &pattern)
{
	vector<int> prefixArray(pattern.size());
	int q = 0;

	prefixArray[0] = 0;

	for (int i = 1; i < pattern.size(); ++i)
	{
		while (q > 0 && pattern[q] != pattern[i])
			q = prefixArray[q - 1];

		if (pattern[q] == pattern[i])
			++q;

		prefixArray[i] = q;
	}

	return prefixArray;
}

vector<int> PatternMatchKnuthMorrisPratt(const string &source, const string &pattern)
{
	vector<int> results;

	//This should output each index where pattern was found in source
	if (source.size() < pattern.size())
		return results;//Pattern can't be in a source that is smaller than the pattern itself

					   //Preprocessing
					   //Extra processing done ahead of time to make the main processing faster (or functional)
	vector<int> prefixArray = ComputePrefixArray(pattern);

	int q = 0;
	for (int i = 0; i < source.size() - (pattern.size() - 1); ++i)
	{
		while (q > 0 && toupper(pattern[q]) != toupper(source[i]))
			q = prefixArray[q - 1];

		if (toupper(pattern[q]) == toupper(source[i]))
			++q;

		if (q == pattern.size())
		{
			results.emplace_back(i - (q - 1));
			q = prefixArray[q - 1];
		}
	}

	return results;
}

//Brute-Force/Naive
vector<int> PatternMatchSimple(const string &source, const string &pattern)//O(n^2)
{
	vector<int> results;

	//This should output each index where pattern was found in source
	if (source.size() < pattern.size())
		return results;//Pattern can't be in a source that is smaller than the pattern itself

	for (int i = 0; i < source.size() - (pattern.size() - 1); ++i)
	{
		for (int j = 0; j < pattern.size(); ++j)
		{
			if (toupper(source[i + j]) != toupper(pattern[j]))
				break;

			if (j == pattern.size() - 1)//if we got through the whole pattern without breaking.
				results.push_back(i);//cout << "Match found at index " << i << endl;
		}
	}
	return results;
}


int main()
{

	srand(time_t(NULL));
	Timer timer;

	//Testing Values for RabinKarp
	/*vector<int> input;
	input.push_back(1);
	input.push_back(4);
	input.push_back(2);
	input.push_back(3);
	for (int i = 0; i < 100; i++) {
		input.push_back(rand() % 100);
	}
	input.push_back(1);
	input.push_back(2);
	input.push_back(5);
	input.push_back(3);
	for (int i = 0; i < 100; i++) {
		input.push_back(rand() % 100);
	}
	input.push_back(1);
	input.push_back(1);
	input.push_back(1);
	input.push_back(1);
	input.push_back(1);
	*/


	/*vector<int> pattern;
	pattern.push_back(1);
	pattern.push_back(2);
	pattern.push_back(5);
	pattern.push_back(3);
	*/
	string input = ReadFile("input.txt");
	string pattern = "1253";
	vector<int> results;

	//Calling up RabinKarp with basic values
	cout << "Testing RabinKarp: ";
	timer.Start();
	results = RabinKarp(input, pattern);
	timer.Stop();
	timer.Report();

	cout << endl << endl;
	for (int i = 0; i < results.size(); i++) {
		cout << results[i] << ",";
	}

	cout << "Testing KMP: ";
	vector<int> results2;
	timer.Start();
	results2 = PatternMatchKnuthMorrisPratt(input, pattern);
	timer.Stop();
	timer.Report();
	
	cout << endl << endl;

	cout << "Testing Brute forces: ";
	vector<int> results3;
	timer.Start();
	results3 = PatternMatchSimple(input, pattern);
	timer.Stop();
	timer.Report();

	cout << endl << endl;


	//Creating basic heap
	Heap<int> myHeap;
	for (int i = 0; i < 20; i++) {
		myHeap.Add(rand() % 100);
	}
	
	//Testing new build heap function
	myHeap.Display();
	cout << endl << endl;
	myHeap.Verify();
	myHeap.Empty();


	//Setting up new coins
	vector<Coin> ValidCoins;
	
	ValidCoins.push_back({ "Dime" , 10 });
	ValidCoins.push_back({ "Penny", 1 });
	ValidCoins.push_back({ "Quarter", 25 });
	ValidCoins.push_back({ "Nickle", 5 });
	//Uncomment this if you want to test other currencies
	/*ValidCoins.push_back({ "50c Euro", 62 });
	ValidCoins.push_back({ "Qian", 20 });
	ValidCoins.push_back({ "Rupee", 1 });*/

	//Sort the coins we add in
	sort(ValidCoins.begin(), ValidCoins.end(), [](Coin& l, Coin& r) { return l.value > r.value; });

	//Output the coins added
	for (auto val : ValidCoins)
		cout << val.name << ",";

	cout << endl << endl;

	vector<Coin> ChangeWallet = ChangeCalc(ValidCoins, 50);
	cout << "Testing against 50cents" << endl;
	//Output out values
	for (auto val : ChangeWallet)
		cout << val.name << " count: " << val.count << " | ";
	cout << endl;

	//Get the change needed for the amount
	ChangeWallet = ChangeCalc(ValidCoins, 80);
	cout << "Testing against 80cents" << endl;
	//Output out values
	for (auto val : ChangeWallet)
		cout << val.name << " count: " << val.count << " | ";
	cout << endl;

	ChangeWallet = ChangeCalc(ValidCoins, 99);
	cout << "Testing against 99cents" << endl;
	//Output out values
	for (auto val : ChangeWallet)
		cout << val.name << " count: " << val.count << " | ";
	cout << endl;

	ChangeWallet = ChangeCalc(ValidCoins, 149);
	cout << "Testing against 1 dollar 49cents" << endl;
	//Output out values
	for (auto val : ChangeWallet)
		cout << val.name << " count: " << val.count << " | ";
	cout << endl;

	
	return 0;
}