#pragma once
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