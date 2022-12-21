/*
Naive method:
Method 1 (Use Sorting)  

Sort both strings
Compare the sorted strings
*/
// C++ program to check whether two strings are anagrams
// of each other
#include <bits/stdc++.h>
using namespace std;

/* function to check whether two strings are anagram of
each other */
bool are_Anagram(string str1, string str2)
{
	// Get lengths of both strings
	int n1 = str1.length();
	int n2 = str2.length();

	// If length of both strings is not same, then they
	// cannot be anagram
	if (n1 != n2)
		return false;

	// Sort both the strings
	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());

	// Compare sorted strings
	return str1==str2;
}
//Time Complexity: O(nLogn)
//You can implement your own sorting algo and suppose that strings are s1=abc and s2=cba then in this case sorting
//can be done in O(n) time only using something like dutch national flag algorithm for this case.

/*
Method 2 (Count characters) 
This method assumes that the set of possible characters in both strings is small. In the following implementation, 
it is assumed that the characters are stored using 8 bit and there can be 256 possible characters. 

Create count arrays of size 256 for both strings. Initialize all values in count arrays as 0.
Iterate through every character of both strings and increment the count of character in the corresponding count arrays.
Compare count arrays. If both count arrays are same, then return true.

The above implementation can be further to use only one count array instead of two. 
We can increment the value in count array for characters in str1 and decrement for characters in str2. 
Finally, if all count values are 0, then the two strings are anagram of each other. 
*/

#define NO_OF_CHARS 256
 
/* function to check whether two strings are anagram of
each other */
bool areAnagram(string str1, string str2)
{
    // Create a count arraya and initialize all values as 0
    int count[NO_OF_CHARS] = { 0 };
    int i;
    
    if(str1.length()!=str2.length())
		return false; 
    // For each character in input string str1, increment count and for each character in input string str2
    // decrement count in the count array. If strings are anagram then count array should become 0.
    for (int i = 0; i < str1.length(); i++) {
        count[str1[i]]++;
        count[str2[i]]--;
    }
 
    // Compare count arrays
    for (i = 0; i < NO_OF_CHARS; i++)
        if (count[i] != 0)
            return false;
 
    return true;
}
//Time Complexity: O(n)
//Space complexity: O(NO_OF_CHARS) which is actually O(1) and does noot depend on input string in any way.
//We may even use hashing here and that might give better space complexity results. We would be string key(character)
//value(frequency) pairs in an unordered map.

// Driver code
int main()
{
	string str1 = "test";
	string str2 = "ttes";

	// Function Call
	if (areAnagram(str1, str2))
		cout << "The two strings are anagram of each other";
	else
		cout << "The two strings are not anagram of each "
				"other";

	return 0;
}

