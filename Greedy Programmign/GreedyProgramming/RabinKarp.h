#pragma once

#include <vector>
#include <string>
#include <iostream>

using namespace std;
/*




Rabin-Karp Pattern Matching Pseudocode:
Assume
sSize = size of the source data.
pSize = size of the pattern


1. Calculate the numeric sum of all the elements in the pattern (Remember ‘A’ = 65 in ASCII). Let’s call this ‘pSum.’
2. Calculate the sum of the first pSize elements in the source. This will be ‘sSum.’
3. Loop through all the elements in the source, from 0 up to sSize – (pSize-1).
	a. If sSum equals pSum, this might* be a match…
		i. Check each character from here to pSize for an exact match, the same way the brute-force method does. 
		If it is a match, output or store the index in a result vector to return later.
	b. Otherwise, there can’t be a match here
		i. subtract from sSum the value of source[i]
		ii. add to sSum the value of source[i + pSize].
4. Return the results (if you were storing them in a vector)

*A note on this algorithm:
‘True’ Rabin-Karp does a little more – it uses a Hash function 
(similar to our good old friend the Hash Table) to reduce the number of ‘false positives’ 
(aka hash collisions) on step 3a. However, not only is that more complicated,
I have found it to almost always be slower than this method because of the extra work it does to calculate hash values.
That ‘textbook’ version may be better in some worst-case scenarios, but this is usually faster on average.






*/

vector<int> RabinKarp(string input, string pattern) {
	int sSize = input.size();
	int pSize = pattern.size();
	int sSum = 0;
	int pSum = 0;
	//1
	for (int i = 0; i < pSize; i++) {
		pSum += pattern[i];
	}
	//2
	for (int i = 0; i < pSize; i++) {
		sSum += input[i];
	}

	//3
	vector<int> currentMatch;
	vector<int> matches;
	bool noMatch = false;
	for (int i = 0; i < sSize - (pSize - 1); i++) {
		if (sSum ==	pSum) {
			//Start loop
			noMatch = false;
			for (int j = 0; j < pSize; j++) {
				if (input[i + j] != pattern[j]) {
					noMatch = true;
					break;
				}
			}
			if (!noMatch) {
				matches.push_back(i);
			}
		}
		else {
			//Reset
			sSum -= input[i];
			//This gets the next element in the vector that would be the end of the pattern
			sSum += input[i + pSize];
		}
		



		/*
		if (input[i] == pattern[i]) {
			for (int j = 0; j < pSize; i++) {
				currentMatch.push_back(input[i + j]);
			}
			if (currentMatch == pattern) {
				matches.push_back(i);
			}
		}
		*/
		
	}

	return matches;
}